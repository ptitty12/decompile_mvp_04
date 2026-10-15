// Data-free tests for the AX mixer (audio/mixer.h, E3b): synthetic voices
// (sines, ramps, ADPCM encoded here) through the DSP model (runtime/ax.h) and
// the mixer, no game data.
#include <doctest/doctest.h>

#include <algorithm>
#include <cmath>
#include <vector>

#include "audio/mixer.h"
#include "common/bytes.h"
#include "runtime/ax.h"

using namespace mvp;
using namespace mvp::audio;
namespace ax = mvp::rt::ax;
namespace pb = mvp::rt::ax::pb;

namespace {

constexpr double kPi = 3.14159265358979323846;

// Guest memory layout of these tests.
constexpr u32 kCmdList = 0x1000, kStudio = 0x1100, kPbBase = 0x2000, kAuxSend = 0x4000, kAuxReturn = 0x5000,
              kSurround = 0x6000, kOutput = 0x6400;

struct Pb {
  u8 b[ax::kPbSize] = {};
  void h(u32 off, u16 v) { put_be16(b + off, v); }
  void w(u32 off, u32 v) { put_be32(b + off, v); }
  void mix(u32 entry, u16 vol, u16 delta = 0) {
    h(pb::kMix + 4 * entry, vol);
    h(pb::kMix + 4 * entry + 2, delta);
  }
};

// A running PCM16 voice over ARAM samples [start, end], at 1:1 rate, on main L
// and R at unity, envelope 0.5 (so the output is the sample >> 1).
Pb pcm_voice(u32 start, u32 end) {
  Pb p;
  p.h(pb::kState, ax::kStateRun);
  p.h(pb::kSrcSelect, ax::kSrcNone);
  p.h(pb::kFormat, ax::kFormatPcm16);
  p.w(pb::kCurHi, start);
  p.w(pb::kEndHi, end);
  p.h(pb::kVeVolume, 0x4000);
  p.h(pb::kMixerCtrl, mixctrl::kL | mixctrl::kR);
  p.mix(pb::kMixL, 0x8000);
  p.mix(pb::kMixR, 0x8000);
  p.w(pb::kRatioHi, 0x10000);
  return p;
}

struct Capture : FrameSink {
  std::vector<s16> lr;
  u32 rate = 0, calls = 0;
  void audio_frames(const s16* f, u32 frames, u32 r) override {
    lr.insert(lr.end(), f, f + 2 * frames);
    rate = r;
    ++calls;
  }
  s16 l(std::size_t i) const { return lr[2 * i]; }
  s16 r(std::size_t i) const { return lr[2 * i + 1]; }
  std::size_t frames() const { return lr.size() / 2; }
};

struct Guest {
  std::vector<u8> mem = std::vector<u8>(0x10000, 0);
  std::vector<u8> aram = std::vector<u8>(0x40000, 0);
  u32 voices = 0;
  u16 fold = 0x07;
  bool aux_a = true;
  bool dpl2 = false;  // AXSetMode(2): 0x13 and 0x10 instead of 0x07 and 0x04

  void pcm(u32 sample, s16 v) { put_be16(&aram[2 * sample], static_cast<u16>(v)); }
  // Appends a PB to the list; returns its address.
  u32 add(const Pb& p) {
    const u32 a = kPbBase + 0x100 * voices;
    std::copy(p.b, p.b + ax::kPbSize, &mem[a]);
    if (voices) put_be32(&mem[a - 0x100 + pb::kNextHi], 0x80000000u | a);
    ++voices;
    return a;
  }
  u8* pbp(u32 i) { return &mem[kPbBase + 0x100 * i]; }
  void cmdlist() {
    std::vector<u16> w = {0x0000, 0x8000, static_cast<u16>(kStudio)};
    if (fold) w.insert(w.end(), {fold, 0x8000, static_cast<u16>(kSurround)});
    w.insert(w.end(), {0x0002, 0x8000, static_cast<u16>(voices ? kPbBase : 0), 0x0003});
    if (!voices) w[w.size() - 3] = 0, w[w.size() - 2] = 0;
    if (dpl2) {
      // Sends: aux A L/R/S, aux B S; returns: L, R, rear L, rear R (as fn_804181DC lays them out).
      w.insert(w.end(), {0x0013, 0x8000, static_cast<u16>(kAuxSend), 0x8000, static_cast<u16>(kAuxSend + 0x780),
                         0x8000, static_cast<u16>(kAuxReturn), 0x8000, static_cast<u16>(kAuxReturn + 0x280),
                         0x8000, static_cast<u16>(kAuxReturn + 0x500), 0x8000, static_cast<u16>(kAuxReturn + 0x780)});
      w.insert(w.end(), {0x0010, 0x8000, static_cast<u16>(kAuxSend + 0x800), 0x8000, static_cast<u16>(kAuxSend + 0xA80)});
    } else if (aux_a) {
      w.insert(w.end(), {0x0004, 0x8000, static_cast<u16>(kAuxSend), 0x8000, static_cast<u16>(kAuxReturn)});
    }
    w.insert(w.end(), {0x000E, 0x8000, static_cast<u16>(kSurround), 0x8000, static_cast<u16>(kOutput), 0x000F});
    for (std::size_t k = 0; k < w.size(); ++k) put_be16(&mem[kCmdList + 2 * k], w[k]);
  }
  ax::FrameStats frame(ax::FrameObserver* obs) {
    cmdlist();
    return ax::process_frame(mem.data(), static_cast<u32>(mem.size()),
                             {aram.data(), static_cast<u32>(aram.size())}, kCmdList, obs);
  }
};

// The frequency of the strongest DFT bin between 20 Hz and Nyquist (1 Hz steps
// near `guess`), and the RMS, of one channel.
double tone_frequency(const std::vector<double>& x, double rate, double guess) {
  double best = 0, best_f = 0;
  for (double f = guess * 0.8; f <= guess * 1.2; f += 1) {
    double re = 0, im = 0;
    for (std::size_t n = 0; n < x.size(); ++n) {
      re += x[n] * std::cos(2 * kPi * f * n / rate);
      im += x[n] * std::sin(2 * kPi * f * n / rate);
    }
    const double p = re * re + im * im;
    if (p > best) best = p, best_f = f;
  }
  return best_f;
}
double rms(const std::vector<double>& x) {
  double s = 0;
  for (double v : x) s += v * v;
  return std::sqrt(s / static_cast<double>(x.size()));
}

// GameCube ADPCM: encodes `x` into 8-byte frames at ARAM byte `at` with
// coefficient pair 0 = (c0, c1) (5.11), choosing each frame's scale. Returns
// the samples a decoder must reconstruct (computed here, independently of the
// DSP model's decoder).
std::vector<s16> adpcm_encode(std::vector<u8>& aram, u32 at, const std::vector<s16>& x, s16 c0, s16 c1) {
  std::vector<s16> recon;
  s32 yn1 = 0, yn2 = 0;
  for (std::size_t f = 0; f * 14 < x.size(); ++f) {
    for (int shift = 0; shift <= 12; ++shift) {
      s32 a = yn1, b = yn2;
      u8 nib[14] = {};
      s16 got14[14] = {};
      bool fits = true;
      for (int k = 0; k < 14 && fits; ++k) {
        const std::size_t i = f * 14 + static_cast<std::size_t>(k);
        const s32 want = i < x.size() ? x[i] : 0;
        const s32 pred = (c0 * a + c1 * b + 1024) >> 11;
        const s32 scale = 1 << shift;
        s32 n = static_cast<s32>(std::lround(static_cast<double>(want - pred) / scale));
        if (n < -8 || n > 7) {
          if (shift < 12) fits = false;
          n = std::clamp(n, -8, 7);
        }
        const s32 got = std::clamp(n * scale + pred, -32768, 32767);
        nib[k] = static_cast<u8>(n & 0xF);
        got14[k] = static_cast<s16>(got);
        b = a;
        a = got;
      }
      if (!fits) continue;
      aram[at + 8 * f] = static_cast<u8>(shift);  // coefficient pair 0
      for (int k = 0; k < 7; ++k) aram[at + 8 * f + 1 + k] = static_cast<u8>(nib[2 * k] << 4 | nib[2 * k + 1]);
      yn1 = a;
      yn2 = b;
      recon.insert(recon.end(), got14, got14 + 14);
      break;
    }
  }
  return recon;
}

}  // namespace

TEST_CASE("polyphase table: unity gain at DC, symmetric phases, a pass-through phase 0 at the widest cutoff") {
  const PolyphaseTable& t = polyphase_table();
  for (int set = 0; set < 3; ++set) {
    for (int p = 0; p < 128; ++p) {
      const auto& c = t[set][p];
      CHECK(c[0] + c[1] + c[2] + c[3] == 32768);
      if (p > 0) {  // phase p mirrors phase 128 - p
        const auto& m = t[set][128 - p];
        for (int k = 0; k < 4 && p != 64; ++k) CHECK(std::abs(c[k] - m[3 - k]) <= 1);
      }
    }
    CHECK(t[set][0][3] == 0);  // at phase 0 the farthest tap is outside the window
  }
  CHECK(t[2][0][1] == 32768);  // cutoff 1.0, phase 0: exactly hist[1]
  CHECK(t[2][0][0] == 0);
  CHECK(t[0][0][1] < 32768);  // the 8 kHz set low-passes even at phase 0
  CHECK(t[0][0][0] > 0);
}

TEST_CASE("conversion: none passes through, linear interpolates, polyphase is a two-sample delay at ratio 1") {
  std::vector<s16> in(64);
  for (int k = 0; k < 64; ++k) in[static_cast<std::size_t>(k)] = static_cast<s16>(100 * k - 1000);
  s16 out[32];

  SrcState none;
  none.src_select = ax::kSrcNone;
  convert(none, in.data(), 32, out, 32);
  for (int i = 0; i < 32; ++i) CHECK(out[i] == in[static_cast<std::size_t>(i)]);
  CHECK(none.hist[3] == in[31]);

  SrcState poly;  // ratio 1.0, fraction 0: hist[1] of each step, i.e. in[i - 2]
  poly.src_select = 0;
  poly.coef_select = 2;
  poly.hist[2] = 7;
  poly.hist[3] = 9;
  convert(poly, in.data(), 32, out, 32);
  CHECK(out[0] == 7);
  CHECK(out[1] == 9);
  for (int i = 2; i < 32; ++i) CHECK(out[i] == in[static_cast<std::size_t>(i - 2)]);
  CHECK(poly.frac == 0);

  SrcState lin;  // ratio 0.5: every other output is a midpoint
  lin.src_select = 1;
  lin.ratio = 0x8000;
  auto val = [](int k) { return 100 * k - 1000; };  // in[k], also for k = -1
  lin.hist[2] = static_cast<s16>(val(-1));
  lin.hist[3] = in[0];
  // The DSP model takes floor((0 + 0.5 x 32)) = 16 input samples for this millisecond.
  convert(lin, in.data() + 1, 16, out, 32);
  for (int i = 0; i < 32; ++i) {
    const int j = (i + 1) / 2;  // the newest sample pulled so far: in[j]
    if ((i + 1) % 2 == 0) CHECK(out[i] == val(j - 1));  // fraction 0: the previous sample
    else CHECK(out[i] == (val(j - 1) + val(j)) / 2);    // fraction 0.5: the midpoint
  }
  CHECK(lin.frac == 0);

  // The number of input samples pulled is the DSP model's count, fraction carried.
  for (u32 ratio : {0x8000u, 0x10000u, 0x12345u, 0x2C000u, 0x3FFFFu}) {
    SrcState s;
    s.src_select = 0;
    s.ratio = ratio;
    s.frac = 0x1234;
    ax::Voice v;
    v.ratio = ratio;
    v.frac = 0x1234;
    const u32 need = ax::input_samples(v, 32);
    std::vector<s16> src(need + 8, 0);
    src[need - 1] = 1000;  // the last sample the converter must pull
    convert(s, src.data(), need, out, 32);
    CHECK(s.frac == v.frac);
    CHECK(s.hist[3] == 1000);
  }
}

TEST_CASE("conversion keeps a tone's pitch and level, down and up") {
  struct Case {
    u16 src_select, coef;
    u32 ratio;  // input rate / 32 kHz
    double tone;
  };
  for (Case c : {Case{0, 0, 0x8000, 1000}, Case{0, 1, 0x8000, 2000}, Case{0, 2, 0x10000, 3000},
                 Case{0, 2, 0x18000, 1500}, Case{1, 0, 0x8000, 500}, Case{0, 1, 0x20000, 1000}}) {
    const double in_rate = 32000.0 * c.ratio / 65536.0;
    std::vector<s16> in(static_cast<std::size_t>(in_rate * 0.25) + 64);
    for (std::size_t n = 0; n < in.size(); ++n) in[n] = static_cast<s16>(std::lround(12000 * std::sin(2 * kPi * c.tone * n / in_rate)));
    SrcState s;
    s.src_select = c.src_select;
    s.coef_select = c.coef;
    s.ratio = c.ratio;
    std::vector<double> y;
    std::size_t at = 0;
    for (int ms = 0; ms < 240; ++ms) {
      ax::Voice v;
      v.ratio = c.ratio;
      v.frac = static_cast<u16>(s.frac);
      const u32 need = ax::input_samples(v, 32);
      s16 out[32];
      convert(s, in.data() + at, need, out, 32);
      at += need;
      if (ms >= 8) for (s16 o : out) y.push_back(o);  // skip the start-up
    }
    INFO("srcSelect " << c.src_select << " coef " << c.coef << " ratio " << c.ratio);
    CHECK(tone_frequency(y, 32000, c.tone) == doctest::Approx(c.tone).epsilon(0.002));
    const double level = 20 * std::log10(rms(y) / (12000 / std::sqrt(2.0)));
    CHECK(level > -1.5);  // well inside every set's passband
    CHECK(level < 0.2);
  }
}

TEST_CASE("volume and pan: each enabled bus gets sample x volume >> 15, mixed over voices") {
  Guest g;
  for (u32 k = 0; k < 1024; ++k) g.pcm(k, static_cast<s16>(2 * k - 600));
  for (u32 k = 0; k < 1024; ++k) g.pcm(2048 + k, 1000);
  Pb a = pcm_voice(0, 1023);  // centre, full volume (after the 0.5 envelope)
  Pb b = pcm_voice(2048, 2048 + 1023);
  b.h(pb::kMixerCtrl, mixctrl::kL);  // left only, quarter volume; R's volume is ignored without its bit
  b.mix(pb::kMixL, 0x2000);
  Pb c = pcm_voice(2048, 2048 + 1023);
  c.h(pb::kMixerCtrl, mixctrl::kR | mixctrl::kAL);  // right at 0.75 and aux A (not output)
  c.mix(pb::kMixR, 0x6000);
  c.mix(pb::kMixAL, 0x7FFF);
  g.add(a);
  g.add(b);
  g.add(c);
  Capture cap;
  AxMixer m(&cap);
  REQUIRE(g.frame(&m).error.empty());
  REQUIRE(cap.frames() == kFrameSamples);
  CHECK(cap.rate == kDspRate);
  for (u32 i = 0; i < kFrameSamples; ++i) {
    const s32 s = (2 * static_cast<s32>(i) - 600) >> 1;
    CHECK(cap.l(i) == s + (500 * 0x2000 >> 15));
    CHECK(cap.r(i) == s + (500 * 0x6000 >> 15));
  }
  CHECK(m.stats().voice_ms == 15);
  CHECK(m.stats().max_voices == 3);
  CHECK(m.stats().aux_send_frames[0] == 1);
  CHECK(m.stats().nonsilent_frames == 1);
  m.set_rate([] { return 48000u; });
  g.frame(&m);
  CHECK(cap.rate == 48000);
}

TEST_CASE("the envelope ramps per sample; the DSP model writes the volume back") {
  Guest g;
  for (u32 k = 0; k < 4096; ++k) g.pcm(k, 20000);
  Pb a = pcm_voice(0, 4095);
  a.h(pb::kVeVolume, 0x7000);
  a.h(pb::kVeDelta, static_cast<u16>(-0x40));
  g.add(a);
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  s32 vol = 0x7000;
  for (u32 i = 0; i < kFrameSamples; ++i, vol -= 0x40) CHECK(cap.l(i) == (20000 * vol) >> 15);
  CHECK(be16(g.pbp(0) + pb::kVeVolume) == 0x7000 - 160 * 0x40);
  g.frame(&m);  // the next frame starts where this one ended
  CHECK(cap.l(kFrameSamples) == (20000 * (0x7000 - 160 * 0x40)) >> 15);
  CHECK(be16(g.pbp(0) + pb::kVeVolume) == 0x7000 - 320 * 0x40);
  CHECK(m.stats().env_ms == 10);
}

TEST_CASE("mix ramps run per sample and carry over frames until the CPU changes the mix block") {
  Guest g;
  for (u32 k = 0; k < 8192; ++k) g.pcm(k, 16384);  // x 0.5 envelope = 8192
  Pb a = pcm_voice(0, 8191);
  a.h(pb::kMixerCtrl, mixctrl::kL | mixctrl::kR | mixctrl::kRamp);
  a.mix(pb::kMixL, 0x0000, 0x0040);  // L ramps up from 0 by 0x40 per sample
  a.mix(pb::kMixR, 0x4000, 0);       // R constant (ramp bit set, delta 0)
  g.add(a);
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  g.frame(&m);
  for (u32 i = 0; i < 2 * kFrameSamples; ++i) {
    CHECK(cap.l(i) == (8192 * static_cast<s32>(0x40 * i)) >> 15);
    CHECK(cap.r(i) == 4096);
  }
  // Guest memory still holds the CPU's values: ramped volumes stay on the host.
  CHECK(be16(g.pbp(0) + pb::kMix) == 0);
  // The CPU writes a new mix block: it applies from the next frame.
  put_be16(g.pbp(0) + pb::kMix, 0x2000);
  put_be16(g.pbp(0) + pb::kMix + 2, 0);
  g.frame(&m);
  CHECK(cap.l(2 * kFrameSamples) == 8192 * 0x2000 >> 15);
  CHECK(cap.l(3 * kFrameSamples - 1) == 8192 * 0x2000 >> 15);
  CHECK(m.stats().mix_reloads == 2);
  CHECK(m.stats().ramp_ms == 10);
}

TEST_CASE("loop and stop: a looping voice keeps playing, an ended one is silent, a stopped one fades out") {
  Guest g;
  for (u32 k = 0; k < 100; ++k) g.pcm(k, static_cast<s16>(k * 10 + 10));
  Pb loop = pcm_voice(0, 99);
  loop.h(pb::kLoopFlag, 1);
  loop.w(pb::kLoopHi, 50);
  Pb once = pcm_voice(0, 99);
  once.h(pb::kMixerCtrl, mixctrl::kR);
  loop.h(pb::kMixerCtrl, mixctrl::kL);
  g.add(loop);
  g.add(once);
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  // L: 0..99 then 50..99 then 50..59; R: 0..99 then silence.
  for (u32 i = 0; i < kFrameSamples; ++i) {
    const u32 k = i < 100 ? i : 50 + (i - 100) % 50;
    CHECK(cap.l(i) == static_cast<s16>((k * 10 + 10) >> 1));
    CHECK(cap.r(i) == (i < 100 ? static_cast<s16>((i * 10 + 10) >> 1) : 0));
  }
  CHECK(be16(g.pbp(1) + pb::kState) == ax::kStateStop);
  CHECK(be16(g.pbp(0) + pb::kState) == ax::kStateRun);

  // The CPU stops the looping voice while it plays: no click, a fade from its
  // last output (host-side depop, at most 20 per sample).
  const s16 last = cap.l(kFrameSamples - 1);
  REQUIRE(last > 100);
  put_be16(g.pbp(0) + pb::kState, ax::kStateStop);
  g.frame(&m);
  CHECK(cap.l(kFrameSamples) == last);
  CHECK(cap.l(kFrameSamples + 1) == last - std::min(20, last / 160));
  CHECK(cap.l(kFrameSamples + 1) < last);
  CHECK(m.stats().depops == 1);
}

TEST_CASE("ADPCM: a tone encoded in the test plays back through the DSP model and the mixer") {
  Guest g;
  const double f = 440, w = 2 * kPi * f / 32000;
  std::vector<s16> x(32000 / 10);
  for (std::size_t n = 0; n < x.size(); ++n) x[n] = static_cast<s16>(std::lround(9000 * std::sin(w * n)));
  // A second-order predictor that fits the tone: x[n] = 2 cos(w) x[n-1] - x[n-2].
  const s16 c0 = static_cast<s16>(std::lround(2 * std::cos(w) * 2048)), c1 = -2048;
  const std::vector<s16> recon = adpcm_encode(g.aram, 0x1000, x, c0, c1);
  const u32 frames = static_cast<u32>((x.size() + 13) / 14);
  Pb a;
  a.h(pb::kState, ax::kStateRun);
  a.h(pb::kSrcSelect, ax::kSrcNone);
  a.h(pb::kFormat, ax::kFormatAdpcm);
  a.w(pb::kCurHi, 2 * 0x1000 + 2);                       // nibble address of the first sample
  a.w(pb::kEndHi, 2 * (0x1000 + 8 * (frames - 1)) + 15);  // the last sample of the last frame
  a.h(pb::kCoefs + 0, static_cast<u16>(c0));
  a.h(pb::kCoefs + 2, static_cast<u16>(c1));
  a.h(pb::kPredScale, g.aram[0x1000]);
  a.h(pb::kVeVolume, 0x7FFF);
  a.h(pb::kMixerCtrl, mixctrl::kL | mixctrl::kR);
  a.mix(pb::kMixL, 0x8000);
  a.mix(pb::kMixR, 0x4000);
  g.add(a);
  Capture cap;
  AxMixer m(&cap);
  for (int k = 0; k < 20; ++k) g.frame(&m);
  REQUIRE(cap.frames() == 20 * kFrameSamples);
  // Exactly the encoder's reconstruction, through the envelope (0x7FFF) and the
  // mix volumes (1.0 left, 0.5 right).
  double err2 = 0;
  for (std::size_t i = 0; i < cap.frames(); ++i) {
    const s32 e = (recon[i] * 0x7FFF) >> 15;
    CHECK(cap.l(i) == e);
    CHECK(cap.r(i) == (e * 0x4000 >> 15));
    err2 += double(cap.l(i) - x[i]) * double(cap.l(i) - x[i]);
  }
  CHECK(std::sqrt(err2 / static_cast<double>(cap.frames())) < 8);  // close to the tone itself
  std::vector<double> l;
  for (std::size_t i = 0; i < cap.frames(); ++i) l.push_back(cap.l(i));
  CHECK(tone_frequency(l, 32000, f) == doctest::Approx(f).epsilon(0.002));
}

TEST_CASE("aux: the voices' sends never reach the guest; the CPU's return buffer is added to the output") {
  Guest g;
  for (u32 k = 0; k < 1024; ++k) g.pcm(k, 4000);
  Pb a = pcm_voice(0, 1023);
  a.h(pb::kMixerCtrl, mixctrl::kAL | mixctrl::kAR | mixctrl::kAS);  // aux A only
  a.mix(pb::kMixAL, 0x8000);
  a.mix(pb::kMixAR, 0x8000);
  a.mix(pb::kMixAS, 0x8000);
  g.add(a);
  // The CPU's aux callback left samples in the return buffer (L, R, S).
  for (u32 i = 0; i < kFrameSamples; ++i) {
    put_be32(&g.mem[kAuxReturn + 4 * i], static_cast<u32>(static_cast<s32>(i) * 3));
    put_be32(&g.mem[kAuxReturn + 4 * (kFrameSamples + i)], static_cast<u32>(-static_cast<s32>(i)));
    put_be32(&g.mem[kAuxReturn + 4 * (2 * kFrameSamples + i)], 7);
  }
  const std::vector<u8> send_before(&g.mem[kAuxSend], &g.mem[kAuxSend] + 0x780);
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  for (u32 i = 0; i < kFrameSamples; ++i) {
    CHECK(cap.l(i) == static_cast<s16>(3 * i));
    CHECK(cap.r(i) == -static_cast<s16>(i));
  }
  CHECK(std::vector<u8>(&g.mem[kAuxSend], &g.mem[kAuxSend] + 0x780) == send_before);
  CHECK(m.stats().aux_frames[0] == 1);
  CHECK(m.stats().aux_send_frames[0] == 1);
  CHECK(m.stats().aux_return_frames[0] == 1);
  // Return surround: folded into L and R the next frame (stereo mode), with the
  // return buffer emptied.
  std::fill(&g.mem[kAuxReturn], &g.mem[kAuxReturn] + 0x780, u8{0});
  g.frame(&m);
  CHECK(cap.l(kFrameSamples) == 7);
  CHECK(cap.r(kFrameSamples) == 7);
}

TEST_CASE("surround: last frame's S is added to L and R in stereo mode, -S / +S in surround mode") {
  for (u16 fold : {u16{0x07}, u16{0x11}}) {
    Guest g;
    g.fold = fold;
    g.aux_a = false;
    for (u32 k = 0; k < 1024; ++k) g.pcm(k, 1200);
    Pb a = pcm_voice(0, 1023);
    a.h(pb::kMixerCtrl, mixctrl::kS);
    a.mix(pb::kMixS, 0x8000);
    g.add(a);
    Capture cap;
    AxMixer m(&cap);
    g.frame(&m);
    CHECK(cap.l(0) == 0);  // nothing yet: S goes out a frame later
    g.frame(&m);
    CHECK(cap.r(kFrameSamples) == 600);
    CHECK(cap.l(kFrameSamples) == (fold == 0x11 ? -600 : 600));
    CHECK((fold == 0x11 ? m.stats().surround_mode_frames : m.stats().stereo_mode_frames) == 2);
  }
}

TEST_CASE("studio: each bus starts at its value and moves by its delta per sample") {
  Guest g;
  g.aux_a = false;
  put_be32(&g.mem[kStudio + 0], 500);  // main L: 500, -2 per sample
  put_be16(&g.mem[kStudio + 4], static_cast<u16>(-2));
  put_be32(&g.mem[kStudio + 6], static_cast<u32>(-100));  // main R: constant -100
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  for (u32 i = 0; i < kFrameSamples; ++i) {
    CHECK(cap.l(i) == 500 - 2 * static_cast<s32>(i));
    CHECK(cap.r(i) == -100);
  }
}

TEST_CASE("the low-pass filter: y = (a0 x + b0 y1) >> 15, its history kept on the host") {
  Guest g;
  for (u32 k = 0; k < 1024; ++k) g.pcm(k, 20000);
  Pb a = pcm_voice(0, 1023);
  a.h(pb::kLpfOn, 1);
  a.h(pb::kLpfA0, 0x2000);
  a.h(pb::kLpfB0, 0x6000);
  g.add(a);
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  g.frame(&m);
  s32 y = 0;
  for (u32 i = 0; i < 2 * kFrameSamples; ++i) {
    y = (0x2000 * 10000 + 0x6000 * y) >> 15;
    CHECK(cap.l(i) == y);
  }
  CHECK(be16(g.pbp(0) + pb::kLpfYn1) == 0);  // not written to the guest
  CHECK(m.stats().lpf_ms == 10);
}

TEST_CASE("guest state is the same with and without the mixer") {
  // Voices of every kind, ramps, an envelope, sends, a voice that ends and one
  // that the "CPU" stops: the PBs, the buffers and ARAM must not depend on the
  // observer.
  Guest base;
  for (u32 k = 0; k < 0x8000; ++k) base.pcm(k, static_cast<s16>(std::lround(15000 * std::sin(k * 0.05))));
  for (u32 v = 0; v < 6; ++v) {
    Pb p = pcm_voice(v * 0x1000, v * 0x1000 + 0x0FFF - v * 0x300);
    p.h(pb::kSrcSelect, static_cast<u16>(v % 3));
    p.h(pb::kCoefSelect, static_cast<u16>(v % 3));
    p.w(pb::kRatioHi, 0x8000 + v * 0x5000);
    p.h(pb::kLoopFlag, v & 1);
    p.w(pb::kLoopHi, v * 0x1000);
    p.h(pb::kVeDelta, static_cast<u16>(v == 2 ? -3 : 0));
    p.h(pb::kMixerCtrl, static_cast<u16>(0x3FFF >> v));
    for (u32 e = 0; e < 9; ++e) p.mix(e, static_cast<u16>(0x1000 * e + 0x800), static_cast<u16>(e * 3));
    p.h(pb::kLpfOn, v == 4);
    p.h(pb::kLpfA0, 0x4000);
    p.h(pb::kLpfB0, 0x3FFF);
    base.add(p);
  }
  Guest with = base, without = base;
  Capture cap;
  AxMixer m(&cap);
  for (int f = 0; f < 40; ++f) {
    if (f == 20) {
      put_be16(with.pbp(1) + pb::kState, ax::kStateStop);
      put_be16(without.pbp(1) + pb::kState, ax::kStateStop);
    }
    with.frame(&m);
    without.frame(nullptr);
  }
  CHECK(with.mem == without.mem);
  CHECK(with.aram == without.aram);
  CHECK(cap.frames() == 40 * kFrameSamples);
  CHECK(m.stats().nonsilent_frames == 40);
  CHECK(m.stats().src_ms[0] > 0);
  CHECK(m.stats().src_ms[1] > 0);
  CHECK(m.stats().src_ms[2] > 0);
}

TEST_CASE("Dolby Pro Logic II mode: four returned channels, the rear ones (aux B L/R) one frame late into L and R") {
  Guest g;
  g.fold = 0;
  g.dpl2 = true;
  for (u32 k = 0; k < 1024; ++k) g.pcm(k, 2000);
  Pb a = pcm_voice(0, 1023);  // front left 1000, rear right 250 (aux B R at 0.25)
  a.h(pb::kMixerCtrl, mixctrl::kL | mixctrl::kBR);
  a.mix(pb::kMixBR, 0x2000);
  g.add(a);
  // The callback's four channels: L, R, rear L, rear R.
  for (u32 i = 0; i < kFrameSamples; ++i) {
    put_be32(&g.mem[kAuxReturn + 4 * i], 10);
    put_be32(&g.mem[kAuxReturn + 0x280 + 4 * i], 20);
    put_be32(&g.mem[kAuxReturn + 0x500 + 4 * i], 30);
    put_be32(&g.mem[kAuxReturn + 0x780 + 4 * i], 40);
  }
  const std::vector<u8> before(g.mem.begin() + kAuxSend, g.mem.begin() + kAuxSend + 0x1000);
  Capture cap;
  AxMixer m(&cap);
  g.frame(&m);
  CHECK(cap.l(0) == 1000 + 10);  // the rears are not out yet
  CHECK(cap.r(0) == 20);
  g.frame(&m);
  CHECK(cap.l(kFrameSamples) == 1000 + 10 + 30);
  CHECK(cap.r(kFrameSamples) == 20 + 250 + 40);
  CHECK(std::vector<u8>(g.mem.begin() + kAuxSend, g.mem.begin() + kAuxSend + 0x1000) == before);  // nothing uploaded
  CHECK(m.stats().dpl2_frames == 2);
  CHECK(m.stats().aux_return_frames[0] == 2);
  CHECK(m.stats().unknown_commands == 0);
}
