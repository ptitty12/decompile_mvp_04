// SDL3 playback (audio/sdl_out.h, E3b) on SDL's "dummy" audio driver: no
// device, no game data. The device thread must pull the ring's frames through
// the drift resampler; nothing else may stop the producer.
#include <doctest/doctest.h>

#include <SDL3/SDL.h>

#include <cmath>
#include <string>
#include <vector>

#include "audio/sdl_out.h"

using namespace mvp::audio;

TEST_CASE("SDL playback pulls the mixer's frames through the ring") {
  SDL_SetHint(SDL_HINT_AUDIO_DRIVER, "dummy");
  std::string err;
  auto out = SdlAudioOut::open(32000, 50, &err);
  REQUIRE_MESSAGE(out, err);
  CHECK(out->driver() == "dummy");
  // Half a second of a tone, delivered in 5 ms frames like the mixer does,
  // paced by throttle() as mvp-play does.
  std::vector<std::int16_t> f(2 * 160);
  int n = 0;
  for (int frame = 0; frame < 100; ++frame) {
    for (int i = 0; i < 160; ++i, ++n) {
      const auto s = static_cast<std::int16_t>(std::lround(8000 * std::sin(n * 0.1)));
      f[2 * static_cast<std::size_t>(i)] = s;
      f[2 * static_cast<std::size_t>(i) + 1] = s;
    }
    out->audio_frames(f.data(), 160, 32000);
    out->throttle(2.0, 50);
  }
  SDL_Delay(300);
  out->close();
  const SdlAudioOut::Stats s = out->stats();
  CHECK(s.written == 16000);
  CHECK(s.ring_full == 0);
  CHECK(s.drift.out_frames > 0);
  CHECK(s.drift.out_frames > s.drift.silent_frames);  // it played, not only silence
  MESSAGE("dummy device: " << s.drift.out_frames << " frames pulled, " << s.drift.silent_frames << " silent, "
                           << s.drift.underruns << " underruns, ratio " << s.drift.min_ratio << ".."
                           << s.drift.max_ratio << ", throttle waits " << s.throttle_waits << " ms");
}
