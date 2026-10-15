// The AX mixer (E3b): what the AX DSP microcode does with the voices after it
// has read their samples, computed on the host, without writing guest state.
//
// The runtime's DSP model (runtime/ax.h, AX2) advances the voices when the CPU
// posts its command list and hands every running voice's millisecond to an
// ax::FrameObserver: the PB as it was at the start of that millisecond and the
// input samples the voice consumed. AxMixer is that observer. Per audio frame
// (5 ms, 160 output samples at the DSP's 32 kHz):
//
// - the command list is parsed (fn_804181DC builds it): 0x00 studio (bus
//   initial values and per-sample deltas, the SDK's depop), 0x07 / 0x11 (last
//   frame's main surround folded into L and R: added to both in stereo mode,
//   L -= S and R += S in surround mode), 0x02/0x03 the voices, 0x04 / 0x05 aux
//   A / B (send buffer address, return buffer address), 0x13 / 0x10 Dolby Pro
//   Logic II (below), 0x12 compressor (not modeled; EA turns it off), 0x0E
//   output, 0x0F end. Commands before 0x03 run at frame_begin, the others at
//   frame_end in list order;
// - each voice millisecond: sample-rate conversion (srcSelect 0: 4-tap
//   polyphase with 128 phases, coefSelect 0/1/2 = cutoffs 8, 12.8 and 16 kHz
//   at 32 kHz; 1: linear; 2: none), the volume envelope (sample x volume >> 15,
//   volume += delta per sample), the one-pole low-pass filter when lpf.on,
//   then each bus that mixerCtrl enables gets clamp16(sample x volume >> 15),
//   the volume moving by its delta per sample when the bus's ramp bit is set;
// - aux returns: the buffer the CPU's aux callback filled (EA's SND copies its
//   main-CPU software mix there: SNDDRV_audiocallback) is read from guest memory
//   (3 x 160 big-endian s32: L, R, S) and added to the main buses;
// - Dolby Pro Logic II mode (AXSetMode(2); MVP 2005 uses it when EA SND is set
//   up for 4 channels, its default): 0x13 sends aux A L/R/S and aux B S and
//   returns four channels from the callback (main L, main R, aux B L, aux B R:
//   EA's four-channel software mix); 0x10 adds aux B L/R (the rear channels)
//   one frame late to main L/R. That is a plain 4-to-2 fold, as in Dolphin's
//   description of these commands; the console's matrix encoding (phase-shifted
//   rears) is not modeled;
// - output: main L and R clamped to 16 bits; main S is kept for the next
//   frame's 0x07 / 0x11.
//
// What is not written to guest memory (the DSP would): the aux send buffers
// (so the CPU's aux callback sees silence, as without a mixer: EA's main-CPU
// effects get no input), the output and surround buffers, and the PB fields
// only the DSP reads back (ramped mix volumes, dpop, LPF history). The mixer
// keeps those in host state per PB ("shadow"): a PB's mix block is taken from
// guest memory when the CPU changed it since the last frame, else the ramped
// values carry on. A voice that disappears mid-sound is faded out over the next
// frame (host-side depop) instead of the SDK's studio depop, whose input (dpop)
// is never written. The polyphase coefficients are our own windowed-sinc
// design, not the DSP ROM's.
//
// Nothing here feeds back into the guest: audio output timing, the sink and the
// host's audio device cannot change what the game computes.
#pragma once

#include <array>
#include <cstdint>
#include <functional>
#include <map>
#include <string>
#include <vector>

#include "runtime/ax.h"

namespace mvp::audio {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using s16 = std::int16_t;
using u32 = std::uint32_t;
using s32 = std::int32_t;
using u64 = std::uint64_t;
using s64 = std::int64_t;

inline constexpr u32 kFrameSamples = rt::ax::kSamplesPerFrame;  // 160
inline constexpr u32 kMsSamples = rt::ax::kSamplesPerMs;         // 32
inline constexpr u32 kDspRate = 32000;

// Receives the mix: interleaved stereo frames (L, R) at `rate` Hz.
class FrameSink {
 public:
  virtual ~FrameSink() = default;
  virtual void audio_frames(const s16* lr, u32 frames, u32 rate) = 0;
};

// Several sinks.
class TeeSink : public FrameSink {
 public:
  void add(FrameSink* s) {
    if (s) outs_.push_back(s);
  }
  void audio_frames(const s16* lr, u32 frames, u32 rate) override {
    for (FrameSink* s : outs_) s->audio_frames(lr, frames, rate);
  }

 private:
  std::vector<FrameSink*> outs_;
};

// ---- the DSP's per-voice stages (exposed for the tests) ----

// 16.16 sample-rate conversion of one millisecond: `in` holds the input samples
// the voice consumed (fewer than the converter wants once the voice ended: the
// rest read as 0). `hist` (the PB's last_samples, oldest first) and `frac` are
// the state at the start; both are updated.
struct SrcState {
  u16 src_select = 0, coef_select = 0;
  u32 ratio = 0x10000;
  u32 frac = 0;
  s16 hist[4] = {};
};
void convert(SrcState& s, const s16* in, u32 n_in, s16* out, u32 n_out);

// The polyphase table: [coef_select 0..2][phase 0..127][tap 0..3], Q15, each
// phase summing to 32768. Taps apply to hist[0..3]; the interpolation point is
// hist[1] + phase / 128 (a two-sample delay). Our own design: a Lanczos-2
// windowed sinc with cutoffs 0.5, 0.8 and 1.0 of the input Nyquist frequency.
using PolyphaseTable = std::array<std::array<std::array<s32, 4>, 128>, 3>;
const PolyphaseTable& polyphase_table();

// Mixer control bits (PB mixerCtrl, the 2004 microcode's layout: EA's
// SNDDRV_DSPMixerUpdate sets them this way).
namespace mixctrl {
inline constexpr u16 kL = 0x0001, kR = 0x0002, kS = 0x0004, kRamp = 0x0008;
inline constexpr u16 kAL = 0x0010, kAR = 0x0020, kARamp = 0x0040, kAS = 0x0080, kASRamp = 0x0100;
inline constexpr u16 kBL = 0x0200, kBR = 0x0400, kBRamp = 0x0800, kBS = 0x1000, kBSRamp = 0x2000;
}  // namespace mixctrl

// The nine mixing buses, in the studio block's order.
enum Bus : u32 { kMainL, kMainR, kMainS, kAuxAL, kAuxAR, kAuxAS, kAuxBL, kAuxBR, kAuxBS, kBuses };

struct MixerStats {
  u64 frames = 0;            // audio frames mixed (160 output samples each)
  u64 voice_ms = 0;          // voice milliseconds mixed
  u64 src_ms[4] = {};        // by srcSelect: polyphase, linear, none, other
  u64 ramp_ms = 0, lpf_ms = 0, itd_ms = 0, env_ms = 0;  // milliseconds with a mix ramp, the LPF, ITD, an envelope delta
  u64 mix_reloads = 0;       // a PB's mix block taken from guest memory (new or changed by the CPU)
  u64 depops = 0;            // voices faded out by the host-side depop
  u64 aux_frames[2] = {};    // frames with an aux A / B command
  u64 aux_return_frames[2] = {};  // ... whose return buffer held non-zero samples
  u64 aux_send_frames[2] = {};    // ... whose voices sent non-zero samples (not delivered to the guest)
  u64 surround_mode_frames = 0, stereo_mode_frames = 0, compressor_frames = 0, dpl2_frames = 0;
  u64 unknown_commands = 0;
  u32 last_unknown_command = 0;
  u64 clipped = 0;           // output samples clamped to 16 bits
  u64 nonsilent_frames = 0;  // frames with a non-zero output sample
  s32 peak = 0;              // largest |output sample|
  double sum_squares = 0;    // of the output samples (L and R), for the RMS
  u16 max_ve = 0;            // largest envelope volume seen (as unsigned)
  u32 max_voices = 0;        // voices in one frame
};

class AxMixer : public rt::ax::FrameObserver {
 public:
  explicit AxMixer(FrameSink* sink = nullptr) : sink_(sink) {}
  void set_sink(FrameSink* s) { sink_ = s; }
  // The rate the AI plays the output at (default 32 kHz); queried per frame.
  void set_rate(std::function<u32()> f) { rate_ = std::move(f); }

  void frame_begin(const u8* mem1, u32 mem1_size, u32 cmdlist) override;
  void voice_ms(const rt::ax::VoiceMs& v) override;
  void frame_end() override;

  const MixerStats& stats() const { return st_; }
  // The last frame's output (interleaved L, R).
  const s16* last_output() const { return out_; }

 private:
  struct Shadow {
    bool valid = false;
    u8 guest_mix[2 + 0x24] = {};  // mixerCtrl and AXPBMIX as last seen in guest memory
    u16 vol[9] = {};              // the DSP-side mix volumes (ramped)
    u8 guest_lpf[8] = {};
    s16 lpf_yn1 = 0;
    s32 dpop[9] = {};             // the last sample each bus got
    u64 frame = 0;                // last frame it ran in
  };
  const u8* at(u32 addr, u32 len) const;

  FrameSink* sink_ = nullptr;
  std::function<u32()> rate_;
  const u8* mem_ = nullptr;
  u32 mem_size_ = 0;
  struct Command {
    u16 cmd = 0;
    u32 arg[6] = {};  // the 32-bit arguments
  };
  u64 frame_no_ = 0;
  std::vector<Command> after_;  // the commands after 0x03, run at frame_end
  u32 voices_ = 0;
  s32 bus_[kBuses][kFrameSamples] = {};
  s32 prev_s_[kFrameSamples] = {};                         // main S, for 0x07 / 0x11
  s32 prev_bl_[kFrameSamples] = {}, prev_br_[kFrameSamples] = {};  // aux B L/R, for 0x10
  s32 depop_[kBuses] = {};  // host-side depop still to fade out, per bus
  s16 out_[2 * kFrameSamples] = {};
  std::map<u32, Shadow> shadow_;
  MixerStats st_;
};

}  // namespace mvp::audio
