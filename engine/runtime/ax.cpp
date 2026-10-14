#include "runtime/ax.h"

#include <algorithm>
#include <cstdio>

namespace mvp::rt::ax {

namespace {

u16 rd16(const u8* p) { return static_cast<u16>(p[0] << 8 | p[1]); }
void wr16(u8* p, u16 v) {
  p[0] = static_cast<u8>(v >> 8);
  p[1] = static_cast<u8>(v);
}
u32 rd32(const u8* p) { return u32(rd16(p)) << 16 | rd16(p + 2); }
void wr32(u8* p, u32 v) {
  wr16(p, static_cast<u16>(v >> 16));
  wr16(p + 2, static_cast<u16>(v));
}

s16 clamp16(std::int64_t v) { return static_cast<s16>(std::clamp<std::int64_t>(v, -32768, 32767)); }

}  // namespace

Voice Voice::load(const u8* p) {
  Voice v;
  v.state = rd16(p + pb::kState);
  v.type = rd16(p + pb::kType);
  v.src_select = rd16(p + pb::kSrcSelect);
  v.format = rd16(p + pb::kFormat);
  v.loop_flag = rd16(p + pb::kLoopFlag);
  v.loop = rd32(p + pb::kLoopHi);
  v.end = rd32(p + pb::kEndHi);
  v.cur = rd32(p + pb::kCurHi);
  for (int k = 0; k < 16; ++k) v.coef[k] = static_cast<s16>(rd16(p + pb::kCoefs + 2 * k));
  v.gain = rd16(p + pb::kGain);
  v.pred_scale = rd16(p + pb::kPredScale);
  v.yn1 = static_cast<s16>(rd16(p + pb::kYn1));
  v.yn2 = static_cast<s16>(rd16(p + pb::kYn2));
  v.ratio = rd32(p + pb::kRatioHi);
  v.frac = rd16(p + pb::kFrac);
  for (int k = 0; k < 4; ++k) v.last[k] = static_cast<s16>(rd16(p + pb::kLast + 2 * k));
  v.loop_pred_scale = rd16(p + pb::kLoopPredScale);
  v.loop_yn1 = static_cast<s16>(rd16(p + pb::kLoopYn1));
  v.loop_yn2 = static_cast<s16>(rd16(p + pb::kLoopYn2));
  return v;
}

void Voice::store(u8* p) const {
  wr16(p + pb::kState, state);
  wr32(p + pb::kCurHi, cur);
  wr16(p + pb::kPredScale, pred_scale);
  wr16(p + pb::kYn1, static_cast<u16>(yn1));
  wr16(p + pb::kYn2, static_cast<u16>(yn2));
  wr16(p + pb::kFrac, frac);
  for (int k = 0; k < 4; ++k) wr16(p + pb::kLast + 2 * k, static_cast<u16>(last[k]));
}

Read next_sample(Voice& v, const SampleMemory& m, s16* out) {
  if (v.state != kStateRun) return Read::kNone;
  s16 s = 0;
  switch (v.format) {
    case kFormatAdpcm: {
      if ((v.cur & 15u) < 2) {  // on a frame header: load it, go to the frame's first sample
        v.pred_scale = m.byte((v.cur & ~15u) >> 1);
        v.cur = (v.cur & ~15u) + 2;
      }
      u8 b = m.byte(v.cur >> 1);
      int n = (v.cur & 1) ? (b & 0xF) : (b >> 4);
      if (n >= 8) n -= 16;
      std::int64_t scale = std::int64_t(1) << (v.pred_scale & 0xF);
      int k = (v.pred_scale >> 4) & 7;
      std::int64_t acc = n * scale * 2048 + std::int64_t(v.coef[2 * k]) * v.yn1 +
                         std::int64_t(v.coef[2 * k + 1]) * v.yn2 + 1024;
      s = clamp16(acc >> 11);
      v.yn2 = v.yn1;
      v.yn1 = s;
      break;
    }
    case kFormatPcm16:
      s = static_cast<s16>(m.byte(v.cur * 2) << 8 | m.byte(v.cur * 2 + 1));
      break;
    case kFormatPcm8:
      s = static_cast<s16>(static_cast<std::int8_t>(m.byte(v.cur)) * 256);
      break;
    default:  // unknown format: silence, but the address still moves
      break;
  }
  *out = s;
  if (v.cur == v.end) {
    if (!v.loop_flag) {
      v.state = kStateStop;
      return Read::kEnded;
    }
    v.cur = v.loop;
    if (v.format == kFormatAdpcm) {
      v.pred_scale = v.loop_pred_scale;
      if (v.type != kTypeStream) {
        v.yn1 = v.loop_yn1;
        v.yn2 = v.loop_yn2;
      }
    }
    return Read::kLooped;
  }
  ++v.cur;
  if (v.format == kFormatAdpcm && (v.cur & 15u) == 0) {  // the next frame: its header, then its samples
    v.pred_scale = m.byte(v.cur >> 1);
    v.cur += 2;
  }
  return Read::kSample;
}

u32 input_samples(Voice& v, u32 out_samples) {
  if (v.src_select == kSrcNone) return out_samples;
  u64 t = u64(v.frac) + u64(v.ratio) * out_samples;
  v.frac = static_cast<u16>(t & 0xFFFF);
  return static_cast<u32>(t >> 16);
}

AdvanceResult advance(Voice& v, const SampleMemory& m, u32 out_samples, const SampleSink& sink) {
  AdvanceResult r;
  if (v.state != kStateRun) return r;
  u32 n = input_samples(v, out_samples);
  for (u32 k = 0; k < n; ++k) {
    s16 s = 0;
    Read got = next_sample(v, m, &s);
    if (got == Read::kNone) break;
    ++r.samples;
    v.last[0] = v.last[1];
    v.last[1] = v.last[2];
    v.last[2] = v.last[3];
    v.last[3] = s;
    if (sink) sink(s);
    if (got == Read::kLooped) r.looped = true;
    if (got == Read::kEnded) {
      r.ended = true;
      break;
    }
  }
  return r;
}

FrameStats process_frame(u8* mem1, u32 mem1_size, const SampleMemory& aram, u32 cmdlist) {
  FrameStats st;
  char b[128];
  auto at = [&](u32 addr, u32 len) -> u8* {
    u32 a = addr & 0x01FFFFFFu;
    return a + len <= mem1_size ? mem1 + a : nullptr;
  };
  // The command list up to its PB command (0x02 hi lo). The AX library writes
  // 0x00 (studio), then 0x07 or 0x11 (output buffer), then 0x02 (__AXNextFrame,
  // fn_804181DC); each takes a 32-bit address.
  u32 head = 0, p = cmdlist;
  for (int n = 0;; ++n) {
    const u8* c = at(p, 6);
    if (!c || n == 8) {
      std::snprintf(b, sizeof b, "AX command list at 0x%08X: no PB command (0x02)", cmdlist);
      st.error = b;
      return st;
    }
    u16 cmd = rd16(c);
    if (cmd == 0x02) {
      head = rd32(c + 2);
      break;
    }
    if (cmd != 0x00 && cmd != 0x07 && cmd != 0x11) {
      std::snprintf(b, sizeof b, "AX command 0x%04X before the PB list is not modeled (list at 0x%08X)", cmd, cmdlist);
      st.error = b;
      return st;
    }
    p += 6;
  }
  for (u32 addr = head; addr; ++st.voices) {
    u8* pbp = at(addr, kPbSize);
    if (!pbp || st.voices == kMaxVoices) {
      std::snprintf(b, sizeof b, "AX PB list: bad or too long at 0x%08X", addr);
      st.error = b;
      return st;
    }
    addr = rd32(pbp + pb::kNextHi);
    if (rd16(pbp + pb::kState) != kStateRun) continue;
    ++st.running;
    u16 upd[5];
    u32 nupd = 0;
    for (int k = 0; k < 5; ++k) nupd += upd[k] = rd16(pbp + pb::kUpdNum + 2 * k);
    u32 data = rd32(pbp + pb::kUpdDataHi);
    AdvanceResult r;
    // Per millisecond: that millisecond's updates, then its 32 samples. Without
    // updates, one pass over the frame (the same result).
    for (int ms = 0; ms < (nupd ? 5 : 1); ++ms) {
      for (u32 k = 0; nupd && k < upd[ms]; ++k, data += 4) {
        const u8* u = at(data, 4);
        if (!u) break;
        u32 off = 2u * rd16(u);
        if (off + 2 <= kPbSize) wr16(pbp + off, rd16(u + 2));
        ++st.updates;
      }
      Voice v = Voice::load(pbp);
      AdvanceResult part = advance(v, aram, nupd ? kSamplesPerMs : kSamplesPerFrame);
      v.store(pbp);
      r.samples += part.samples;
      r.looped |= part.looped;
      r.ended |= part.ended;
    }
    st.samples += r.samples;
    st.looped += r.looped ? 1 : 0;
    st.ended += r.ended ? 1 : 0;
  }
  return st;
}

}  // namespace mvp::rt::ax
