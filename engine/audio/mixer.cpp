#include "audio/mixer.h"

#include <algorithm>
#include <cmath>
#include <cstring>

#include "common/bytes.h"

namespace mvp::audio {

namespace pb = rt::ax::pb;

namespace {

s16 clamp16(s64 v) { return static_cast<s16>(std::clamp<s64>(v, -32768, 32767)); }

double sinc(double x) {
  if (x == 0) return 1;
  const double px = 3.14159265358979323846 * x;
  return std::sin(px) / px;
}

// Mix entries (AXPBMIX order): the bus each feeds, its enable and ramp bits.
struct MixEntry {
  Bus bus;
  u16 enable, ramp;
};
constexpr MixEntry kEntries[9] = {
    {kMainL, mixctrl::kL, mixctrl::kRamp},     {kMainR, mixctrl::kR, mixctrl::kRamp},
    {kAuxAL, mixctrl::kAL, mixctrl::kARamp},   {kAuxAR, mixctrl::kAR, mixctrl::kARamp},
    {kAuxBL, mixctrl::kBL, mixctrl::kBRamp},   {kAuxBR, mixctrl::kBR, mixctrl::kBRamp},
    {kAuxBS, mixctrl::kBS, mixctrl::kBSRamp},  {kMainS, mixctrl::kS, mixctrl::kRamp},
    {kAuxAS, mixctrl::kAS, mixctrl::kASRamp},
};

// Arguments (16-bit words) of each command of the 2004 microcode's lists, as
// __AXNextFrame (fn_804181DC) writes them; -1 = not used by this SDK.
int command_words(u16 cmd) {
  switch (cmd) {
    case 0x00: return 2;   // studio (bus initial values)
    case 0x02: return 2;   // PB list
    case 0x03: return 0;   // process the voices
    case 0x04: return 4;   // aux A: send buffer, return buffer
    case 0x05: return 4;   // aux B
    case 0x07: return 2;   // stereo: fold last frame's surround into L and R
    case 0x0E: return 4;   // output: surround buffer, L/R buffer
    case 0x10: return 4;   // Dolby Pro Logic II: aux B L/R
    case 0x11: return 2;   // surround: fold last frame's surround as -S / +S
    case 0x12: return 4;   // compressor: threshold, release frames, table
    case 0x13: return 12;  // Dolby Pro Logic II: aux sends and returns
    default: return -1;
  }
}

}  // namespace

const PolyphaseTable& polyphase_table() {
  static const PolyphaseTable table = [] {
    PolyphaseTable t{};
    const double cutoff[3] = {0.5, 0.8, 1.0};  // of the input Nyquist frequency: 8, 12.8, 16 kHz at 32 kHz
    for (int set = 0; set < 3; ++set) {
      const double fc = cutoff[set];
      for (int phase = 0; phase < 128; ++phase) {
        const double f = phase / 128.0;
        double w[4], sum = 0;
        for (int k = 0; k < 4; ++k) {
          const double x = k - 1.0 - f;  // tap k's distance from the point hist[1] + f
          w[k] = std::fabs(x) < 2 ? fc * sinc(fc * x) * sinc(x / 2) : 0;
          sum += w[k];
        }
        s32 q[4], qsum = 0;
        int big = 0;
        for (int k = 0; k < 4; ++k) {
          q[k] = static_cast<s32>(std::lround(w[k] / sum * 32768.0));
          qsum += q[k];
          if (std::abs(q[k]) > std::abs(q[big])) big = k;
        }
        q[big] += 32768 - qsum;  // unity gain at DC, exactly
        for (int k = 0; k < 4; ++k) t[static_cast<std::size_t>(set)][static_cast<std::size_t>(phase)][static_cast<std::size_t>(k)] = q[k];
      }
    }
    return t;
  }();
  return table;
}

void convert(SrcState& s, const s16* in, u32 n_in, s16* out, u32 n_out) {
  u32 next = 0;
  auto pull = [&] {
    const s16 x = next < n_in ? in[next] : 0;  // after the end of the sample: silence
    ++next;
    s.hist[0] = s.hist[1];
    s.hist[1] = s.hist[2];
    s.hist[2] = s.hist[3];
    s.hist[3] = x;
  };
  if (s.src_select == rt::ax::kSrcNone) {  // one input sample per output sample
    for (u32 i = 0; i < n_out; ++i) {
      pull();
      out[i] = s.hist[3];
    }
    return;
  }
  const auto& tab = polyphase_table()[std::min<u32>(s.coef_select, 2)];
  u64 pos = s.frac & 0xFFFFu;
  for (u32 i = 0; i < n_out; ++i) {
    pos += s.ratio;
    while (pos >= 0x10000) {
      pull();
      pos -= 0x10000;
    }
    const u32 f = static_cast<u32>(pos);
    if (s.src_select == 0) {  // 4-tap polyphase
      const auto& c = tab[f >> 9];
      const s64 acc = s64(c[0]) * s.hist[0] + s64(c[1]) * s.hist[1] + s64(c[2]) * s.hist[2] + s64(c[3]) * s.hist[3];
      out[i] = clamp16((acc + 16384) >> 15);
    } else {  // linear (srcSelect 1, and anything else that converts)
      out[i] = clamp16(s.hist[2] + ((s64(s.hist[3]) - s.hist[2]) * f >> 16));
    }
  }
  s.frac = static_cast<u32>(pos);
}

const u8* AxMixer::at(u32 addr, u32 len) const {
  const u32 a = addr & 0x01FFFFFFu;
  return mem_ && a <= mem_size_ && len <= mem_size_ - a ? mem_ + a : nullptr;
}

void AxMixer::frame_begin(const u8* mem1, u32 mem1_size, u32 cmdlist) {
  mem_ = mem1;
  mem_size_ = mem1_size;
  ++frame_no_;
  voices_ = 0;
  after_.clear();
  for (auto& b : bus_) std::fill(std::begin(b), std::end(b), 0);
  // The command list (fn_804181DC writes it). What comes before 0x03 (process
  // the voices) runs now; what comes after runs in frame_end, in list order.
  bool voices_done = false;
  u32 p = cmdlist;
  for (int n = 0; n < 64; ++n) {
    const u8* c = at(p, 2);
    if (!c) break;
    Command cmd;
    cmd.cmd = be16(c);
    if (cmd.cmd == 0x0F) break;
    const int words = command_words(cmd.cmd);
    if (words < 0) {
      ++st_.unknown_commands;
      st_.last_unknown_command = cmd.cmd;
      break;
    }
    for (u32 k = 0; k < static_cast<u32>(words) / 2 && k < 6; ++k) {
      const u8* a = at(p + 2 + 4 * k, 4);
      cmd.arg[k] = a ? be32(a) : 0u;
    }
    p += 2 + 2 * static_cast<u32>(words);
    if (cmd.cmd == 0x03) {
      voices_done = true;
      continue;
    }
    if (voices_done) {
      after_.push_back(cmd);
      continue;
    }
    switch (cmd.cmd) {
      case 0x00: {
        // The buses start from the studio block: per bus a 32-bit value and a
        // per-sample delta (the SDK's depop, fn_804190A4).
        const u8* sp = at(cmd.arg[0], 6 * kBuses);
        for (u32 b = 0; sp && b < kBuses; ++b) {
          s32 v = static_cast<s32>(be32(sp + 6 * b));
          const s32 d = static_cast<s16>(be16(sp + 6 * b + 4));
          for (u32 i = 0; i < kFrameSamples; ++i, v += d) bus_[b][i] = v;
        }
        break;
      }
      case 0x07:  // stereo: last frame's surround added to L and R
      case 0x11:  // surround: L -= S, R += S
        for (u32 i = 0; i < kFrameSamples; ++i) {
          bus_[kMainL][i] += cmd.cmd == 0x11 ? -prev_s_[i] : prev_s_[i];
          bus_[kMainR][i] += prev_s_[i];
        }
        ++(cmd.cmd == 0x11 ? st_.surround_mode_frames : st_.stereo_mode_frames);
        break;
      default: break;
    }
  }
}

void AxMixer::voice_ms(const rt::ax::VoiceMs& v) {
  const u8* p = v.pb;
  if (v.ms >= 5) return;
  Shadow& sh = shadow_[v.pb_addr];
  if (sh.frame != frame_no_) ++voices_;
  sh.frame = frame_no_;
  ++st_.voice_ms;

  // The mix block: from guest memory when it is new or the CPU changed it.
  u8 mix[sizeof sh.guest_mix];
  std::memcpy(mix, p + pb::kMixerCtrl, 2);
  std::memcpy(mix + 2, p + pb::kMix, 0x24);
  if (!sh.valid || std::memcmp(mix, sh.guest_mix, sizeof mix) != 0) {
    std::memcpy(sh.guest_mix, mix, sizeof mix);
    for (u32 e = 0; e < 9; ++e) sh.vol[e] = be16(p + pb::kMix + 4 * e);
    ++st_.mix_reloads;
  }

  // Sample-rate conversion.
  SrcState src;
  src.src_select = be16(p + pb::kSrcSelect);
  src.coef_select = be16(p + pb::kCoefSelect);
  src.ratio = be32(p + pb::kRatioHi);
  src.frac = be16(p + pb::kFrac);
  for (u32 k = 0; k < 4; ++k) src.hist[k] = static_cast<s16>(be16(p + pb::kLast + 2 * k));
  ++st_.src_ms[std::min<u32>(src.src_select, 3)];
  s16 smp[kMsSamples];
  convert(src, v.in, v.n_in, smp, kMsSamples);

  // The volume envelope.
  s16 vol = static_cast<s16>(be16(p + pb::kVeVolume));
  const s16 delta = static_cast<s16>(be16(p + pb::kVeDelta));
  st_.max_ve = std::max<u16>(st_.max_ve, static_cast<u16>(vol));
  if (delta) ++st_.env_ms;
  for (u32 i = 0; i < kMsSamples; ++i) {
    smp[i] = clamp16((s32(smp[i]) * vol) >> 15);
    vol = static_cast<s16>(static_cast<u16>(vol + delta));
  }

  // The low-pass filter.
  if (be16(p + pb::kLpfOn)) {
    ++st_.lpf_ms;
    if (!sh.valid || std::memcmp(p + pb::kLpfOn, sh.guest_lpf, sizeof sh.guest_lpf) != 0) {
      std::memcpy(sh.guest_lpf, p + pb::kLpfOn, sizeof sh.guest_lpf);
      sh.lpf_yn1 = static_cast<s16>(be16(p + pb::kLpfYn1));
    }
    const s64 a0 = be16(p + pb::kLpfA0), b0 = be16(p + pb::kLpfB0);
    s16 y = sh.lpf_yn1;
    for (u32 i = 0; i < kMsSamples; ++i) smp[i] = y = clamp16((a0 * smp[i] + b0 * y) >> 15);
    sh.lpf_yn1 = y;
  }
  if (be16(p + pb::kItdOn)) ++st_.itd_ms;  // initial time delay: not modeled
  sh.valid = true;

  // The buses.
  const u16 ctrl = be16(p + pb::kMixerCtrl);
  bool ramp = false;
  for (u32 e = 0; e < 9; ++e) {
    const MixEntry& me = kEntries[e];
    if (!(ctrl & me.enable)) {
      sh.dpop[e] = 0;
      continue;
    }
    u16 mv = sh.vol[e];
    const s16 md = (ctrl & me.ramp) ? static_cast<s16>(be16(p + pb::kMix + 4 * e + 2)) : 0;
    ramp |= md != 0;
    s32* bus = bus_[me.bus] + kMsSamples * v.ms;
    s32 last = 0;
    for (u32 i = 0; i < kMsSamples; ++i) {
      last = clamp16((s32(smp[i]) * mv) >> 15);
      bus[i] += last;
      mv = static_cast<u16>(mv + md);
    }
    sh.vol[e] = mv;
    sh.dpop[e] = last;
  }
  if (ramp) ++st_.ramp_ms;
}

void AxMixer::frame_end() {
  // Voices that ran last frame and not in this one were stopped by the CPU (or
  // ended): fade their last output out from this frame on (host-side depop,
  // the ramp the SDK computes: at most 20 per sample, the rest carried over).
  for (auto it = shadow_.begin(); it != shadow_.end();) {
    if (it->second.frame == frame_no_) {
      ++it;
      continue;
    }
    bool any = false;
    for (u32 e = 0; e < 9; ++e) {
      depop_[kEntries[e].bus] += it->second.dpop[e];
      any |= it->second.dpop[e] != 0;
    }
    if (any) ++st_.depops;
    it = shadow_.erase(it);
  }
  for (u32 b = 0; b < kBuses; ++b) {
    const s32 step = std::clamp(depop_[b] / static_cast<s32>(kFrameSamples), -20, 20);
    if (!step) {  // under one per sample: dropped, as the SDK does
      depop_[b] = 0;
      continue;
    }
    s32 h = depop_[b];
    for (u32 i = 0; i < kFrameSamples; ++i, h -= step) bus_[b][i] += h;
    depop_[b] -= step * static_cast<s32>(kFrameSamples);
  }

  // The commands after the voices, in list order. Uploads (aux sends to the
  // CPU's callback) are not written to guest memory; downloads (what the
  // callback left there) are read from it.
  auto sent = [&](std::initializer_list<Bus> buses) {
    for (Bus b : buses)
      for (u32 i = 0; i < kFrameSamples; ++i)
        if (bus_[b][i]) return true;
    return false;
  };
  // Adds 160 big-endian s32 at `addr` to `bus`; true if any was non-zero.
  auto download = [&](u32 addr, Bus bus) {
    const u8* r = at(addr, kFrameSamples * 4);
    bool any = false;
    for (u32 i = 0; r && i < kFrameSamples; ++i) {
      const s32 x = static_cast<s32>(be32(r + 4 * i));
      any |= x != 0;
      bus_[bus][i] += x;
    }
    return any;
  };
  for (const Command& c : after_) {
    switch (c.cmd) {
      case 0x04:  // aux A / B: send (upload) to arg 0, return (download) from arg 1 into main L, R, S
      case 0x05: {
        const u32 k = c.cmd - 0x04u;
        ++st_.aux_frames[k];
        if (k == 0 ? sent({kAuxAL, kAuxAR, kAuxAS}) : sent({kAuxBL, kAuxBR, kAuxBS})) ++st_.aux_send_frames[k];
        bool any = false;
        for (u32 ch = 0; ch < 3; ++ch) any |= download(c.arg[1] + 4 * kFrameSamples * ch, static_cast<Bus>(kMainL + ch));
        if (any) ++st_.aux_return_frames[k];
        break;
      }
      case 0x13: {  // Dolby Pro Logic II: send aux A L/R/S and aux B S; the four
                    // returned channels go to main L, main R, aux B L, aux B R
        ++st_.dpl2_frames;
        ++st_.aux_frames[0];
        if (sent({kAuxAL, kAuxAR, kAuxAS, kAuxBS})) ++st_.aux_send_frames[0];
        bool any = download(c.arg[2], kMainL);
        any |= download(c.arg[3], kMainR);
        any |= download(c.arg[4], kAuxBL);
        any |= download(c.arg[5], kAuxBR);
        if (any) ++st_.aux_return_frames[0];
        break;
      }
      case 0x10:  // Dolby Pro Logic II: aux B L/R (the rear channels) one frame late into main L/R
        for (u32 i = 0; i < kFrameSamples; ++i) {
          std::swap(prev_bl_[i], bus_[kAuxBL][i]);
          std::swap(prev_br_[i], bus_[kAuxBR][i]);
          bus_[kMainL][i] += bus_[kAuxBL][i];
          bus_[kMainR][i] += bus_[kAuxBR][i];
        }
        break;
      case 0x12: ++st_.compressor_frames; break;  // not modeled (EA turns it off)
      default: break;                              // 0x0E output: below
    }
  }

  // The output: main L and R, 16-bit; main S is folded in next frame.
  bool nonsilent = false;
  for (u32 i = 0; i < kFrameSamples; ++i) {
    for (u32 c = 0; c < 2; ++c) {
      const s32 x = bus_[kMainL + c][i];
      const s16 o = clamp16(x);
      if (o != x) ++st_.clipped;
      out_[2 * i + c] = o;
      nonsilent |= o != 0;
      st_.peak = std::max<s32>(st_.peak, o < 0 ? -s32(o) : s32(o));
      st_.sum_squares += double(o) * double(o);
    }
    prev_s_[i] = bus_[kMainS][i];
  }
  if (nonsilent) ++st_.nonsilent_frames;

  st_.max_voices = std::max(st_.max_voices, voices_);
  ++st_.frames;
  if (sink_) sink_->audio_frames(out_, kFrameSamples, rate_ ? rate_() : kDspRate);
}

}  // namespace mvp::audio
