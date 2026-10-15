// The consumer side of the audio ring (E3b): a small adaptive resampler that
// soaks up the drift between the guest's virtual clock (which fills the ring at
// the AI rate of virtual time) and the host's audio clock (which empties it).
//
// It reads the ring at a ratio near 1 (linear interpolation between frames) and
// steers the ratio so the ring's smoothed fill stays near a target: fuller than
// the target, it reads slightly faster (at most +0.5 %); emptier, slower. When
// the ring runs dry it fades to silence and waits until the ring holds the
// target again (an underrun, counted); when it holds far more than the target
// (the emulation ran ahead, or the device stalled) it skips down to the target
// (counted). All of this is host-side: none of it reaches the guest.
#pragma once

#include <cstdint>
#include <vector>

#include "audio/ring.h"

namespace mvp::audio {

class DriftResampler {
 public:
  struct Stats {
    std::uint64_t out_frames = 0;       // frames produced
    std::uint64_t silent_frames = 0;    // ... of which silence (not primed, or after an underrun)
    std::uint64_t underruns = 0;        // times the ring ran dry
    std::uint64_t skipped_frames = 0;   // frames skipped to catch up
    double min_ratio = 1, max_ratio = 1;
  };

  // `target` frames of buffering (the latency the device sees, on top of its own).
  DriftResampler(Ring& ring, std::uint32_t target);

  // Produces exactly `frames` interleaved stereo frames.
  void pull(std::int16_t* out, std::uint32_t frames);

  double ratio() const { return ratio_; }
  double fill() const { return fill_; }
  const Stats& stats() const { return st_; }
  std::uint32_t target() const { return target_; }

 private:
  bool next(std::int16_t f[2]);  // the next ring frame, through a local chunk
  // Frames not yet played: the ring, the local chunk, and the two being
  // interpolated between.
  std::uint32_t held() const { return ring_.available() + (chunk_n_ - chunk_at_) + (primed_ ? 2u : 0u); }

  Ring& ring_;
  std::uint32_t target_;
  std::vector<std::int16_t> chunk_;
  std::uint32_t chunk_n_ = 0, chunk_at_ = 0;
  bool primed_ = false;
  double fill_ = 0, ratio_ = 1, pos_ = 0;
  std::int16_t a_[2] = {}, b_[2] = {};
  std::int16_t fade_[2] = {};
  std::uint32_t fade_left_ = 0;
  Stats st_;
};

}  // namespace mvp::audio
