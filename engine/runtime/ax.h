// The DSP side of AX (DETERMINISM R8, E0c): what the AX microcode does to the
// voice parameter blocks (PBs) in main memory each audio frame, without mixing.
//
// The CPU side (the SDK's AX library, retail code) keeps an AXVPB per voice and a
// copy of every PB in the array __AXPB (lbl_806CB720, 64 x 0xF4 bytes, linked by
// their `next` fields). Each audio frame it sends a command list whose command
// 0x02 names the first PB; the DSP walks the list and, for every running voice,
// reads the frame's input samples from ARAM and writes the PB back. The next
// frame's __AXSyncPBs (fn_80419CB4 -> fn_80419568) reads back `state`,
// `ve.currentVolume` and `addr.currentAddress` into the AXVPB. EA's SND driver
// then frees voices whose state went to stop and refills streaming buffers by
// the play position (snd/tu_803AC88C, around 0x803AFB60 and 0x803AFC84).
//
// Model (E0c-AX1), one frame = 160 output samples (5 ms at 32 kHz):
// - the sample-rate converter consumes floor((frac + ratio x 160) / 65536) input
//   samples (16.16 ratio, the fraction carried in src.currentAddressFrac); with
//   srcSelect 2 (no conversion) exactly 160;
// - input samples are read at addr.currentAddress in the format's units: ADPCM
//   in nibbles (8-byte frames: a header byte, then 14 sample nibbles; crossing a
//   frame loads pred_scale from the header), PCM16 in 16-bit samples, PCM8 in
//   bytes;
// - after the sample at addr.endAddress the voice loops to addr.loopAddress
//   (ADPCM: pred_scale from adpcmLoop, and for non-stream voices the history
//   yn1/yn2 too) or, without loopFlag, stops (state 0) and reads no more;
// - ADPCM is decoded (yn1/yn2 kept in the PB); the last four input samples go
//   to src.last_samples, for the polyphase filter of a later mixer;
// - PB updates (update.updNum[5], data at dataHi:dataLo, pairs of halfword
//   offset and value) apply at the start of each millisecond (32 samples);
// - E3b (AX2): a voice is processed millisecond by millisecond (5 x 32 output
//   samples), each only while it is running at the start of that millisecond,
//   and the volume envelope moves: ve.currentVolume += ve.currentDelta for
//   every output sample (16-bit wrap), written back as the DSP does (the CPU
//   reads it back in fn_80419568).
// The mix itself (SRC filter, envelope and mix volumes, buses, aux returns,
// output) is computed by an observer (engine/audio), which only reads: the
// PB fields that only the DSP reads back (ramped mix volumes, dpop, LPF
// history) and the output and aux buffers are not written to guest memory, so
// guest state is the same with and without a mixer.
// Nothing here reads host state; the frame runs when the CPU posts its command
// list, a point fixed by guest instructions (DSP1).
#pragma once

#include <cstdint>
#include <functional>
#include <string>

namespace mvp::rt::ax {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using s16 = std::int16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

inline constexpr u32 kPbSize = 0xF4;
inline constexpr u32 kMaxVoices = 64;
inline constexpr u32 kSamplesPerFrame = 160;  // 5 ms at 32 kHz
inline constexpr u32 kSamplesPerMs = 32;

// PB field offsets in bytes (SDK 2004 AXPB, include/dolphin/ax.h; confirmed by
// __AXVPBInit fn_80419F7C and the read-back in fn_80419568).
namespace pb {
inline constexpr u32 kNextHi = 0x00, kNextLo = 0x02, kSrcSelect = 0x08, kState = 0x0E, kType = 0x10;
inline constexpr u32 kCoefSelect = 0x0A, kMixerCtrl = 0x0C;
inline constexpr u32 kMix = 0x12;  // AXPBMIX: 9 (volume, delta) pairs, see kMix* below
inline constexpr u32 kItdOn = 0x36;
inline constexpr u32 kUpdNum = 0x44, kUpdDataHi = 0x4E, kUpdDataLo = 0x50;
inline constexpr u32 kDpop = 0x52;
inline constexpr u32 kVeVolume = 0x64, kVeDelta = 0x66;
inline constexpr u32 kLoopFlag = 0x6E, kFormat = 0x70, kLoopHi = 0x72, kLoopLo = 0x74, kEndHi = 0x76, kEndLo = 0x78,
                     kCurHi = 0x7A, kCurLo = 0x7C;
inline constexpr u32 kCoefs = 0x7E, kGain = 0x9E, kPredScale = 0xA0, kYn1 = 0xA2, kYn2 = 0xA4;
inline constexpr u32 kRatioHi = 0xA6, kRatioLo = 0xA8, kFrac = 0xAA, kLast = 0xAC;
inline constexpr u32 kLoopPredScale = 0xB4, kLoopYn1 = 0xB6, kLoopYn2 = 0xB8;
inline constexpr u32 kLpfOn = 0xBA, kLpfYn1 = 0xBC, kLpfA0 = 0xBE, kLpfB0 = 0xC0;
// AXPBMIX entries (volume at kMix + 4 * entry, its delta 2 bytes later), in
// SDK order: main L, R; aux A L, R; aux B L, R, S; main S; aux A S.
inline constexpr u32 kMixL = 0, kMixR = 1, kMixAL = 2, kMixAR = 3, kMixBL = 4, kMixBR = 5, kMixBS = 6, kMixS = 7,
                     kMixAS = 8;
}  // namespace pb

inline constexpr u16 kStateStop = 0, kStateRun = 1;
inline constexpr u16 kTypeNormal = 0, kTypeStream = 1;
inline constexpr u16 kSrcNone = 2;
inline constexpr u16 kFormatAdpcm = 0x0000, kFormatPcm16 = 0x000A, kFormatPcm8 = 0x0019;

// Sample memory (ARAM). Reads outside it return 0.
struct SampleMemory {
  const u8* data = nullptr;
  u32 size = 0;
  u8 byte(u32 a) const { return a < size ? data[a] : 0; }
};

// The DSP-side state of one voice, unpacked from its PB (big-endian).
struct Voice {
  u16 state = 0, type = 0, src_select = 0, format = 0, loop_flag = 0;
  u32 loop = 0, end = 0, cur = 0;  // in the format's units (ADPCM: nibbles)
  s16 coef[16] = {};
  u16 gain = 0, pred_scale = 0;
  s16 yn1 = 0, yn2 = 0;
  u32 ratio = 0;  // 16.16
  u16 frac = 0;
  s16 last[4] = {};
  u16 loop_pred_scale = 0;
  s16 loop_yn1 = 0, loop_yn2 = 0;

  static Voice load(const u8* pb);
  // Writes back what the DSP changes: state, current address, ADPCM state,
  // the converter's fraction and history.
  void store(u8* pb) const;
};

// Called with every input sample a voice consumes (for a mixer; may be empty).
using SampleSink = std::function<void(s16)>;

// What next_sample did.
enum class Read { kNone, kSample, kLooped, kEnded };

// Reads the input sample at v.cur and moves on (ADPCM: decodes it; a frame
// boundary loads the next header), then handles the end: kLooped when the voice
// went back to its loop start after this sample, kEnded when it stopped. Reads
// nothing (kNone) once the voice is stopped.
Read next_sample(Voice& v, const SampleMemory& m, s16* out);

// Input samples the converter consumes for `out_samples` output samples (and
// the fraction it carries on).
u32 input_samples(Voice& v, u32 out_samples);

struct AdvanceResult {
  u32 samples = 0;  // input samples consumed
  bool looped = false, ended = false;
};

// Advances a running voice by `out_samples` output samples.
AdvanceResult advance(Voice& v, const SampleMemory& m, u32 out_samples, const SampleSink& sink = {});

struct FrameStats {
  u32 voices = 0;   // PBs in the list
  u32 running = 0;  // advanced this frame
  u32 ended = 0;    // stopped at their end this frame
  u32 looped = 0;   // wrapped to their loop start this frame
  u32 updates = 0;  // PB updates applied
  u64 samples = 0;  // input samples consumed
  std::string error;  // a command list the model does not understand
};

// One millisecond of one voice, as the DSP processed it (for a mixer).
struct VoiceMs {
  u32 pb_addr = 0;          // the PB's address, as in the list
  u32 ms = 0;               // 0..4 within the frame
  const u8* pb = nullptr;   // the PB at the start of this millisecond, after its updates (kPbSize bytes)
  const s16* in = nullptr;  // the input samples it consumed in this millisecond, in order
  u32 n_in = 0;
  bool ended = false;  // it stopped at its end in this millisecond
};

// Sees every audio frame as the DSP processes it. Everything it gets is
// read-only: an observer must not change guest state (the mixer, engine/audio).
class FrameObserver {
 public:
  virtual ~FrameObserver() = default;
  // The CPU posted its command list at `cmdlist`; guest memory as it is now.
  virtual void frame_begin(const u8* mem1, u32 mem1_size, u32 cmdlist) = 0;
  // A running voice's millisecond: voices in list order, milliseconds in order.
  virtual void voice_ms(const VoiceMs& v) = 0;
  // All voices are done (PBs written back).
  virtual void frame_end() = 0;
};

// One audio frame: finds the PB list through the command list at `cmdlist` (a
// MEM1 address; the top bits are ignored, as by the DSP's DMA) and advances
// every running voice, writing the PBs back. An observer, if any, sees the frame.
FrameStats process_frame(u8* mem1, u32 mem1_size, const SampleMemory& aram, u32 cmdlist,
                         FrameObserver* observer = nullptr);

}  // namespace mvp::rt::ax
