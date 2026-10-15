#include "audio/drift.h"

#include <algorithm>
#include <cmath>

namespace mvp::audio {

namespace {
constexpr std::uint32_t kChunk = 256;      // frames taken from the ring at a time
constexpr std::uint32_t kFade = 64;        // frames to fade out over after an underrun
constexpr double kSmoothing = 0.05;        // per pull: the fill estimate's time constant is ~20 pulls
constexpr double kGain = 0.01;             // ratio change per unit of relative fill error
constexpr double kMaxAdjust = 0.005;       // +-0.5 %: inaudible as pitch
constexpr std::uint32_t kSkipFactor = 4;   // more than 4 x the target: skip down to it
}  // namespace

DriftResampler::DriftResampler(Ring& ring, std::uint32_t target)
    : ring_(ring), target_(std::max<std::uint32_t>(target, 64)), chunk_(2 * kChunk) {}

bool DriftResampler::next(std::int16_t f[2]) {
  if (chunk_at_ == chunk_n_) {
    chunk_n_ = ring_.read(chunk_.data(), kChunk);
    chunk_at_ = 0;
    if (!chunk_n_) return false;
  }
  f[0] = chunk_[2 * static_cast<std::size_t>(chunk_at_)];
  f[1] = chunk_[2 * static_cast<std::size_t>(chunk_at_) + 1];
  ++chunk_at_;
  return true;
}

void DriftResampler::pull(std::int16_t* out, std::uint32_t frames) {
  std::uint32_t have = held();
  if (have > kSkipFactor * target_) {  // far ahead of the device: catch up
    std::uint32_t drop = have - target_;
    const std::uint32_t local = std::min(drop, chunk_n_ - chunk_at_);
    chunk_at_ += local;
    drop -= local;
    st_.skipped_frames += local + ring_.skip(drop);
    fill_ = target_;
    have = held();
  }
  if (!primed_ && have >= target_) {  // enough buffered: start (or restart)
    primed_ = true;
    pos_ = 0;
    fill_ = have;
    next(a_);
    next(b_);
  }
  if (primed_) {
    fill_ += kSmoothing * (static_cast<double>(held()) - fill_);
    const double err = (fill_ - target_) / target_;
    ratio_ = 1 + std::clamp(kGain * err, -kMaxAdjust, kMaxAdjust);
    st_.min_ratio = std::min(st_.min_ratio, ratio_);
    st_.max_ratio = std::max(st_.max_ratio, ratio_);
  }
  for (std::uint32_t i = 0; i < frames; ++i) {
    std::int16_t* o = out + 2 * static_cast<std::size_t>(i);
    if (!primed_) {
      for (int c = 0; c < 2; ++c)
        o[c] = fade_left_ ? static_cast<std::int16_t>(fade_[c] * static_cast<int>(fade_left_) / static_cast<int>(kFade)) : 0;
      if (fade_left_) --fade_left_;
      ++st_.silent_frames;
      continue;
    }
    for (int c = 0; c < 2; ++c)
      o[c] = static_cast<std::int16_t>(std::lround(a_[c] + (b_[c] - a_[c]) * pos_));
    pos_ += ratio_;
    while (pos_ >= 1) {
      pos_ -= 1;
      a_[0] = b_[0];
      a_[1] = b_[1];
      if (!next(b_)) {  // the ring ran dry: fade out, wait for it to fill again
        primed_ = false;
        ++st_.underruns;
        fade_[0] = a_[0];
        fade_[1] = a_[1];
        fade_left_ = kFade;
        break;
      }
    }
  }
  st_.out_frames += frames;
}

}  // namespace mvp::audio
