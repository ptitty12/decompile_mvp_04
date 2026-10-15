// Data-free tests for the AX voice model (runtime/ax.h, DETERMINISM R8, E0c):
// synthetic parameter blocks and sample memory, no game data.
#include <doctest/doctest.h>

#include <vector>

#include "common/bytes.h"
#include "runtime/ax.h"

using namespace mvp;
using namespace mvp::rt::ax;

namespace {

struct Pb {
  u8 b[kPbSize] = {};
  void h(u32 off, u16 v) { put_be16(b + off, v); }
  void w(u32 off, u32 v) { put_be32(b + off, v); }
  u16 h(u32 off) const { return be16(b + off); }
  u32 w(u32 off) const { return be32(b + off); }
};

// A running voice without sample-rate conversion.
Pb voice(u16 format, u32 cur, u32 end, bool loop = false, u32 loop_at = 0) {
  Pb p;
  p.h(pb::kState, kStateRun);
  p.h(pb::kSrcSelect, kSrcNone);
  p.h(pb::kFormat, format);
  p.h(pb::kLoopFlag, loop ? 1 : 0);
  p.w(pb::kCurHi, cur);
  p.w(pb::kEndHi, end);
  p.w(pb::kLoopHi, loop_at);
  return p;
}

// Two ADPCM frames at byte 0x100: headers 0x12 (coefficients 1, scale 4) and
// 0x05 (coefficients 0, scale 32); sample nibbles 1, 2, ..., 7, -8, -7, ... cycling.
std::vector<u8> adpcm_aram() {
  std::vector<u8> a(0x400, 0);
  int n = 1;
  for (u32 f = 0; f < 2; ++f) {
    a[0x100 + 8 * f] = f ? 0x05 : 0x12;
    for (u32 k = 1; k < 8; ++k) {
      u8 hi = static_cast<u8>(n++ & 0xF), lo = static_cast<u8>(n++ & 0xF);
      a[0x100 + 8 * f + k] = static_cast<u8>(hi << 4 | lo);
    }
  }
  return a;
}

int nib(int v) { return (v & 0xF) >= 8 ? (v & 0xF) - 16 : (v & 0xF); }

}  // namespace

TEST_CASE("ADPCM: nibble addresses skip frame headers, each header loads pred_scale, the end stops the voice") {
  std::vector<u8> aram = adpcm_aram();
  SampleMemory m{aram.data(), static_cast<u32>(aram.size())};
  // Frame 0 starts at nibble 0x200; its first sample is nibble 0x202. The last
  // sample of frame 1 is nibble 0x21F.
  Pb p = voice(kFormatAdpcm, 0x202, 0x21F);
  p.h(pb::kPredScale, 0x12);
  // Coefficient pair 1 = (1.0, 0) in 5.11: each sample adds the previous one;
  // pair 0 = (0, 0): plain nibble x scale.
  p.h(pb::kCoefs + 4, 0x0800);
  Voice v = Voice::load(p.b);
  std::vector<s16> got;
  AdvanceResult r = advance(v, m, kSamplesPerFrame, [&](s16 s) { got.push_back(s); });
  CHECK(r.samples == 28);  // 2 frames x 14 samples, then the voice stopped
  CHECK(r.ended);
  CHECK_FALSE(r.looped);
  CHECK(v.state == kStateStop);
  CHECK(v.cur == 0x21F);
  CHECK(v.pred_scale == 0x05);
  // Expected: frame 0 (scale 4, predictor yn1), then frame 1 (scale 32, no predictor).
  std::vector<s16> want;
  int yn1 = 0, n = 1;
  for (int k = 0; k < 14; ++k) want.push_back(static_cast<s16>(yn1 = nib(n++) * 4 + yn1));
  for (int k = 0; k < 14; ++k) want.push_back(static_cast<s16>(nib(n++) * 32));
  CHECK(got == want);
  CHECK(v.yn1 == want[27]);
  CHECK(v.yn2 == want[26]);
  CHECK(v.last[3] == want[27]);
  CHECK(v.last[0] == want[24]);
  // A stopped voice reads nothing more.
  CHECK(advance(v, m, kSamplesPerFrame).samples == 0);
  s16 s = 0;
  CHECK(next_sample(v, m, &s) == Read::kNone);
}

TEST_CASE("ADPCM loops: back to the loop start with the loop context; a stream keeps its history") {
  std::vector<u8> aram = adpcm_aram();
  SampleMemory m{aram.data(), static_cast<u32>(aram.size())};
  for (u16 type : {kTypeNormal, kTypeStream}) {
    Pb p = voice(kFormatAdpcm, 0x202, 0x20F, true, 0x204);
    p.h(pb::kType, type);
    p.h(pb::kPredScale, 0x12);
    p.h(pb::kCoefs + 4, 0x0800);
    p.h(pb::kLoopPredScale, 0x12);
    p.h(pb::kLoopYn1, 100);
    p.h(pb::kLoopYn2, 50);
    Voice v = Voice::load(p.b);
    s16 s = 0;
    for (int k = 0; k < 13; ++k) CHECK(next_sample(v, m, &s) == Read::kSample);
    CHECK(v.cur == 0x20F);
    s16 before = v.yn1;
    CHECK(next_sample(v, m, &s) == Read::kLooped);  // the sample at the end, then the wrap
    CHECK(v.cur == 0x204);
    CHECK(v.state == kStateRun);
    if (type == kTypeNormal) {
      CHECK(v.yn1 == 100);
      CHECK(v.yn2 == 50);
    } else {
      CHECK(v.yn1 == s);
      CHECK(v.yn2 == before);
    }
    // A whole frame of a looping voice never stops: 160 samples over a 12-sample loop.
    AdvanceResult r = advance(v, m, kSamplesPerFrame);
    CHECK(r.samples == 160);
    CHECK(r.looped);
    CHECK_FALSE(r.ended);
    CHECK(v.cur >= 0x204);
    CHECK(v.cur <= 0x20F);
  }
}

TEST_CASE("PCM16 counts 16-bit samples, PCM8 bytes") {
  std::vector<u8> aram(0x100, 0);
  for (u32 k = 0; k < 0x80; ++k) put_be16(&aram[2 * k], static_cast<u16>(0x1000 + k));
  SampleMemory m{aram.data(), static_cast<u32>(aram.size())};
  Pb p = voice(kFormatPcm16, 0x10, 0x13);
  Voice v = Voice::load(p.b);
  std::vector<s16> got;
  AdvanceResult r = advance(v, m, kSamplesPerFrame, [&](s16 s) { got.push_back(s); });
  CHECK(r.samples == 4);
  CHECK(r.ended);
  CHECK(got == std::vector<s16>{0x1010, 0x1011, 0x1012, 0x1013});

  aram[0xC0] = 0x7F;  // PCM8: one signed byte per sample, scaled by 256
  aram[0xC1] = 0x80;
  aram[0xC2] = 0x01;
  Pb q = voice(kFormatPcm8, 0xC0, 0xC2);
  Voice w = Voice::load(q.b);
  got.clear();
  advance(w, m, kSamplesPerFrame, [&](s16 s) { got.push_back(s); });
  CHECK(got == std::vector<s16>{0x7F00, -32768, 0x0100});
  CHECK(w.cur == 0xC2);
}

TEST_CASE("the converter consumes ratio x 160 input samples and carries the fraction") {
  Voice v;
  v.src_select = 0;  // polyphase
  v.ratio = 0x00018000;  // 1.5
  CHECK(input_samples(v, kSamplesPerFrame) == 240);
  CHECK(v.frac == 0);
  v.ratio = 0x00008000;  // 0.5
  CHECK(input_samples(v, kSamplesPerFrame) == 80);
  v.ratio = 0x00010001;  // just above 1: the fraction grows by 160 per frame
  u32 total = 0;
  for (int f = 0; f < 410; ++f) total += input_samples(v, kSamplesPerFrame);
  CHECK(total == 410 * 160 + 1);  // 410 x 160 = 65,600: one extra sample
  CHECK(v.frac == 410 * 160 - 65536);
  v.src_select = kSrcNone;  // no conversion: 1:1, the fraction untouched
  CHECK(input_samples(v, kSamplesPerFrame) == 160);
  CHECK(v.frac == 410 * 160 - 65536);
}

TEST_CASE("an audio frame walks the PB list from the command list and writes the PBs back") {
  std::vector<u8> mem(0x10000, 0), aram(0x1000, 0);
  SampleMemory m{aram.data(), static_cast<u32>(aram.size())};
  // Command list at 0x1000: studio, output buffer, PB list (virtual address), process.
  const u16 cl[] = {0x0000, 0x8000, 0x3000, 0x0007, 0x8000, 0x4000, 0x0002, 0x8000, 0x2000, 0x0003};
  for (u32 k = 0; k < 10; ++k) put_be16(&mem[0x1000 + 2 * k], cl[k]);
  Pb a = voice(kFormatPcm16, 0x100, 0x100 + 99);  // 100 samples, then the end
  a.w(pb::kNextHi, 0x80002100u);
  Pb b = voice(kFormatPcm16, 0x400, 0x500);
  b.h(pb::kState, kStateStop);
  Pb c = voice(kFormatPcm16, 0x200, 0x2FF, true, 0x200);  // loops
  c.w(pb::kNextHi, 0);
  b.w(pb::kNextHi, 0x80002200u);
  std::copy(a.b, a.b + kPbSize, &mem[0x2000]);
  std::copy(b.b, b.b + kPbSize, &mem[0x2100]);
  std::copy(c.b, c.b + kPbSize, &mem[0x2200]);
  std::vector<u8> before_b(&mem[0x2100], &mem[0x2100] + kPbSize);

  FrameStats st = process_frame(mem.data(), static_cast<u32>(mem.size()), m, 0x00001000u);
  INFO(st.error);
  REQUIRE(st.error.empty());
  CHECK(st.voices == 3);
  CHECK(st.running == 2);
  CHECK(st.ended == 1);
  CHECK(st.looped == 0);
  CHECK(st.samples == 100 + 160);
  CHECK(be16(&mem[0x2000 + pb::kState]) == kStateStop);
  CHECK(be32(&mem[0x2000 + pb::kCurHi]) == 0x100 + 99);
  CHECK(std::vector<u8>(&mem[0x2100], &mem[0x2100] + kPbSize) == before_b);  // stopped: untouched
  CHECK(be32(&mem[0x2200 + pb::kCurHi]) == 0x200 + 160);
  st = process_frame(mem.data(), static_cast<u32>(mem.size()), m, 0x00001000u);
  CHECK(st.running == 1);
  CHECK(st.looped == 1);  // 320 > 256 samples: wrapped once
  CHECK(be32(&mem[0x2200 + pb::kCurHi]) == 0x200 + 320 - 256);

  put_be16(&mem[0x1006], 0x0009);  // an unknown command before the PB list
  st = process_frame(mem.data(), static_cast<u32>(mem.size()), m, 0x00001000u);
  CHECK(st.error.find("0x0009") != std::string::npos);
}

TEST_CASE("PB updates apply at the start of their millisecond") {
  std::vector<u8> mem(0x10000, 0), aram(0x1000, 0);
  SampleMemory m{aram.data(), static_cast<u32>(aram.size())};
  const u16 cl[] = {0x0002, 0x0000, 0x2000};
  for (u32 k = 0; k < 3; ++k) put_be16(&mem[0x1000 + 2 * k], cl[k]);
  Pb a = voice(kFormatPcm16, 0, 0x7FF);
  a.h(pb::kUpdNum + 4, 1);  // one update in millisecond 2
  a.w(pb::kUpdDataHi, 0x80003000u);
  std::copy(a.b, a.b + kPbSize, &mem[0x2000]);
  put_be16(&mem[0x3000], static_cast<u16>(pb::kState / 2));  // state := stop
  put_be16(&mem[0x3002], kStateStop);
  FrameStats st = process_frame(mem.data(), static_cast<u32>(mem.size()), m, 0x1000);
  REQUIRE(st.error.empty());
  CHECK(st.updates == 1);
  CHECK(st.samples == 2 * kSamplesPerMs);  // milliseconds 0 and 1 ran
  CHECK(be16(&mem[0x2000 + pb::kState]) == kStateStop);
  CHECK(be32(&mem[0x2000 + pb::kCurHi]) == 2 * kSamplesPerMs);
}

TEST_CASE("AX2: milliseconds run while the voice runs, the envelope is written back, an observer sees each one") {
  std::vector<u8> mem(0x10000, 0), aram(0x1000, 0);
  for (u32 k = 0; k < 0x400; ++k) put_be16(&aram[2 * k], static_cast<u16>(k));
  SampleMemory m{aram.data(), static_cast<u32>(aram.size())};
  const u16 cl[] = {0x0002, 0x0000, 0x2000, 0x0003};
  for (u32 k = 0; k < 4; ++k) put_be16(&mem[0x1000 + 2 * k], cl[k]);
  // 0x80 samples at a ratio of 1 + 1/256: the end comes in millisecond 3.
  Pb a = voice(kFormatPcm16, 0, 0x7F);
  a.h(pb::kSrcSelect, 0);
  a.w(pb::kRatioHi, 0x10100);
  a.h(pb::kVeVolume, 0x4000);
  a.h(pb::kVeDelta, 2);
  std::copy(a.b, a.b + kPbSize, &mem[0x2000]);

  struct Obs : FrameObserver {
    int begins = 0, ends = 0;
    std::vector<VoiceMs> ms;
    std::vector<u16> ve;
    std::vector<s16> in;
    void frame_begin(const u8*, u32, u32 cmdlist) override { begins += cmdlist == 0x1000; }
    void voice_ms(const VoiceMs& v) override {
      ms.push_back(v);
      ve.push_back(be16(v.pb + pb::kVeVolume));
      in.insert(in.end(), v.in, v.in + v.n_in);
    }
    void frame_end() override { ++ends; }
  } obs;
  FrameStats st = process_frame(mem.data(), static_cast<u32>(mem.size()), m, 0x1000, &obs);
  REQUIRE(st.error.empty());
  CHECK(obs.begins == 1);
  CHECK(obs.ends == 1);
  REQUIRE(obs.ms.size() == 4);  // milliseconds 0..3; the voice stopped in 3
  for (u32 k = 0; k < 4; ++k) {
    CHECK(obs.ms[k].ms == k);
    CHECK(obs.ms[k].pb_addr == 0x2000);
    CHECK(obs.ve[k] == 0x4000 + 64 * k);  // the PB as it was at the start of that millisecond
    CHECK(obs.ms[k].ended == (k == 3));
  }
  CHECK(obs.ms[0].n_in == 32);  // floor(32 x (1 + 1/256)) = 32, fraction 0x2000
  CHECK(obs.in.size() == 0x80);
  for (u32 k = 0; k < obs.in.size(); ++k) CHECK(obs.in[k] == static_cast<s16>(k));
  CHECK(be16(&mem[0x2000 + pb::kState]) == kStateStop);
  CHECK(be16(&mem[0x2000 + pb::kVeVolume]) == 0x4000 + 4 * 32 * 2);  // four milliseconds of +2
  CHECK(be16(&mem[0x2000 + pb::kFrac]) == ((4 * 32 * 0x100) & 0xFFFF));  // no fraction after the end
  // The same frame without an observer writes the same guest state.
  std::vector<u8> mem2(0x10000, 0);
  for (u32 k = 0; k < 4; ++k) put_be16(&mem2[0x1000 + 2 * k], cl[k]);
  std::copy(a.b, a.b + kPbSize, &mem2[0x2000]);
  process_frame(mem2.data(), static_cast<u32>(mem2.size()), m, 0x1000);
  CHECK(mem2 == mem);
}
