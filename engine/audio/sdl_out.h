// Audio playback through SDL3 (E3b, native development builds): the mixer's
// frames go into a ring (audio/ring.h); SDL's audio thread pulls them through
// the drift resampler (audio/drift.h) at the AI rate, and SDL converts to the
// device's rate. The browser build (E2) replaces this with an AudioWorklet
// around the same ring and resampler.
//
// Determinism: the guest only ever writes into the ring. Host audio timing
// reaches nothing but the resampler and, through throttle(), how fast the host
// runs the emulation (never what the guest computes).
#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "audio/drift.h"
#include "audio/mixer.h"
#include "audio/ring.h"

struct SDL_AudioStream;

namespace mvp::audio {

class SdlAudioOut : public FrameSink {
 public:
  struct Stats {
    std::uint64_t written = 0;    // frames the mixer delivered into the ring
    std::uint64_t ring_full = 0;  // frames dropped because the ring was full
    std::uint64_t throttle_waits = 0;  // milliseconds throttle() waited
    std::uint64_t played_nonsilent = 0;  // frames handed to the device with a non-zero sample
    std::int32_t played_peak = 0;        // largest |sample| handed to the device
    DriftResampler::Stats drift;
  };

  // Opens the default playback device for 16-bit stereo at `rate` with
  // `latency_ms` of buffering in the ring. Needs no window.
  static std::unique_ptr<SdlAudioOut> open(std::uint32_t rate, std::uint32_t latency_ms, std::string* err);
  ~SdlAudioOut() override;

  // Producer (the emulation thread): the mixer's output.
  void audio_frames(const s16* lr, u32 frames, u32 rate) override;
  // Host pacing: waits (at most max_ms) while the ring holds more than
  // `factor` x the target, so a host running faster than real time (a fast
  // display, no window) does not overrun the device.
  void throttle(double factor = 2.0, std::uint32_t max_ms = 50);
  // Stops playback; stats() is final afterwards.
  void close();

  std::string driver() const { return driver_; }
  std::string device() const { return device_; }
  std::uint32_t device_rate() const { return device_rate_; }
  Stats stats() const;

 private:
  SdlAudioOut(std::uint32_t rate, std::uint32_t target);
  static void pull(void* self, SDL_AudioStream* stream, int additional, int total);

  SDL_AudioStream* stream_ = nullptr;
  Ring ring_;
  DriftResampler drift_;
  std::vector<std::int16_t> tmp_;
  std::uint32_t rate_ = 0, device_rate_ = 0;
  std::uint64_t throttle_waits_ = 0, played_nonsilent_ = 0;
  std::int32_t played_peak_ = 0;
  std::string driver_, device_;
};

}  // namespace mvp::audio
