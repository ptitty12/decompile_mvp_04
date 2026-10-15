// Data-free tests for the output side (E3b): the ring, the drift resampler,
// WAV files and the level meter.
#include <doctest/doctest.h>

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

#include "audio/drift.h"
#include "audio/ring.h"
#include "audio/wav.h"

using namespace mvp;
using namespace mvp::audio;

namespace {

constexpr double kPi = 3.14159265358979323846;

// A producer that writes a counting ramp (L = n, R = -n, wrapping in 16 bits).
struct Ramp {
  std::int16_t n = 0;
  void write(Ring& r, std::uint32_t frames) {
    std::vector<std::int16_t> b(2 * frames);
    for (std::uint32_t i = 0; i < frames; ++i, ++n) {
      b[2 * i] = n;
      b[2 * i + 1] = static_cast<std::int16_t>(-n);
    }
    r.write(b.data(), frames);
  }
};

}  // namespace

TEST_CASE("ring: wraps, drops what does not fit, skips") {
  Ring r(100);  // rounded up to 128
  CHECK(r.capacity() == 128);
  std::vector<std::int16_t> in(2 * 200), out(2 * 200);
  for (std::size_t k = 0; k < in.size(); ++k) in[k] = static_cast<std::int16_t>(k);
  CHECK(r.write(in.data(), 100) == 100);
  CHECK(r.read(out.data(), 60) == 60);
  CHECK(out[119] == 119);
  CHECK(r.write(in.data() + 200, 100) == 88);  // 40 waiting + 88 = 128
  CHECK(r.dropped() == 12);
  CHECK(r.available() == 128);
  CHECK(r.skip(20) == 20);
  CHECK(r.read(out.data(), 200) == 108);
  CHECK(out[0] == 160);                     // frame 80 of the first write
  CHECK(out[2 * 20] == 200);                // then the second write, across the wrap
  CHECK(out[2 * 107 + 1] == 200 + 2 * 87 + 1);
  CHECK(r.read(out.data(), 1) == 0);
  CHECK(r.written() == 188);
}

TEST_CASE("drift: at the target fill, the output is the input, frame for frame") {
  Ring ring(1 << 14);
  Ramp p;
  p.write(ring, 1000);  // the target
  DriftResampler d(ring, 1000);
  std::vector<std::int16_t> out(2 * 480);
  std::int16_t expect = 0;
  for (int k = 0; k < 50; ++k) {
    d.pull(out.data(), 480);
    p.write(ring, 480);  // the producer keeps pace exactly
    for (int i = 0; i < 480; ++i, ++expect) {
      CHECK(out[2 * static_cast<std::size_t>(i)] == expect);
      CHECK(out[2 * static_cast<std::size_t>(i) + 1] == -expect);
    }
  }
  CHECK(d.ratio() == 1.0);
  CHECK(d.stats().underruns == 0);
  CHECK(d.stats().silent_frames == 0);
}

TEST_CASE("drift: a producer 0.3 % fast is absorbed by a ratio of about 1.003, without drops or underruns") {
  Ring ring(1 << 16);
  Ramp p;
  p.write(ring, 3200);
  DriftResampler d(ring, 3200);
  std::vector<std::int16_t> out(2 * 512);
  double owed = 0;
  for (int k = 0; k < 4000; ++k) {  // ~64 s at 32 kHz
    d.pull(out.data(), 512);
    owed += 512 * 1.003;
    const auto n = static_cast<std::uint32_t>(owed);
    p.write(ring, n);
    owed -= n;
  }
  CHECK(d.ratio() == doctest::Approx(1.003).epsilon(0.0005));
  CHECK(d.stats().underruns == 0);
  CHECK(d.stats().skipped_frames == 0);
  CHECK(ring.dropped() == 0);
  CHECK(ring.available() < 2 * 3200);
  CHECK(d.stats().max_ratio <= 1.005);
}

TEST_CASE("drift: a slow producer underruns into silence and restarts at the target; far ahead it skips") {
  Ring ring(1 << 16);
  Ramp p;
  p.write(ring, 1000);
  DriftResampler d(ring, 1000);
  std::vector<std::int16_t> out(2 * 400);
  for (int k = 0; k < 20; ++k) {
    d.pull(out.data(), 400);
    p.write(ring, 200);  // half speed
  }
  CHECK(d.stats().underruns >= 1);
  CHECK(d.stats().silent_frames > 0);
  CHECK(d.stats().min_ratio >= 0.995);
  // The last frame of an underrun is silence after a short fade.
  const auto silent_before = d.stats().silent_frames;
  // A burst far beyond 4 x the target: skipped down to the target.
  p.write(ring, 20000);
  d.pull(out.data(), 400);
  CHECK(d.stats().skipped_frames > 10000);
  CHECK(ring.available() < 1000);
  CHECK(d.stats().silent_frames >= silent_before);
}

TEST_CASE("WAV: written frames read back, the header carries the rate") {
  const std::string path = "test_audio_out.wav";
  std::vector<std::int16_t> lr;
  for (int i = 0; i < 1000; ++i) {
    lr.push_back(static_cast<std::int16_t>(i * 31));
    lr.push_back(static_cast<std::int16_t>(-i * 17));
  }
  {
    WavWriter w;
    REQUIRE(w.open(path));
    w.audio_frames(lr.data(), 600, 32000);
    w.audio_frames(lr.data() + 1200, 400, 32000);
    CHECK(w.frames() == 1000);
    CHECK(w.close());
  }
  std::vector<std::int16_t> back;
  std::uint32_t rate = 0;
  REQUIRE(read_wav(path, &back, &rate));
  CHECK(rate == 32000);
  CHECK(back == lr);
  std::remove(path.c_str());
}

TEST_CASE("levels: a full-scale sine is -3 dBFS RMS, silence has no level, windows count") {
  LevelMeter m(3200);
  std::vector<std::int16_t> lr;
  for (int i = 0; i < 32000; ++i) {
    const auto s = static_cast<std::int16_t>(std::lround(32767 * std::sin(2 * kPi * 1000 * i / 32000.0)));
    lr.push_back(s);
    lr.push_back(s);
  }
  m.audio_frames(lr.data(), 32000, 32000);
  std::vector<std::int16_t> zero(2 * 32000, 0);
  m.audio_frames(zero.data(), 32000, 32000);
  REQUIRE(m.windows().size() == 20);
  CHECK(m.windows()[0].rms_dbfs == doctest::Approx(-3.01).epsilon(0.01));
  CHECK(m.windows()[0].peak == 32767);
  CHECK(std::isinf(m.windows()[19].rms_dbfs));
  CHECK(m.windows_above(-60) == 10);
  CHECK(m.rms_dbfs() == doctest::Approx(-6.02).epsilon(0.01));
  CHECK(m.summary().find("10 of 20 windows") != std::string::npos);
}
