// Browser audio, the engine side (E2c): the AX mixer (audio/mixer.h) observes
// the DSP's frames exactly as natively; its output collects here between two
// run batches, and the Worker posts each batch to the page's AudioWorklet
// (engine/web/src/audio-worklet.ts), which resamples it to the device through
// its own drift resampler. Nothing flows back: guest state is the same with and
// without the mixer (E3b-MIX1), and the worklet's timing never reaches the
// Worker's loop.
#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "audio/mixer.h"

namespace mvp::web {

class PendingAudio final : public audio::FrameSink {
 public:
  // At most this many frames wait (2 s at 32 kHz); older ones are dropped
  // (nobody is taking them: no worklet yet, or a stalled page).
  static constexpr std::uint32_t kMaxFrames = 64000;

  void audio_frames(const audio::s16* lr, audio::u32 frames, audio::u32 rate) override {
    rate_ = rate;
    pending_.insert(pending_.end(), lr, lr + 2 * static_cast<std::size_t>(frames));
    total_ += frames;
    for (audio::u32 i = 0; i < 2 * frames; ++i)
      if (lr[i]) {
        ++nonsilent_;
        break;
      }
    for (audio::u32 i = 0; i < 2 * frames; ++i) {
      const std::int32_t a = lr[i] < 0 ? -static_cast<std::int32_t>(lr[i]) : lr[i];
      if (a > peak_) peak_ = a;
    }
    const std::size_t cap = 2 * static_cast<std::size_t>(kMaxFrames);
    if (pending_.size() > cap) {
      dropped_ += (pending_.size() - cap) / 2;
      pending_.erase(pending_.begin(), pending_.end() - static_cast<std::ptrdiff_t>(cap));
    }
  }

  // Moves what waits into the taken buffer (valid until the next take) and
  // returns its frame count.
  std::uint32_t take() {
    taken_.swap(pending_);
    pending_.clear();
    return static_cast<std::uint32_t>(taken_.size() / 2);
  }
  const std::int16_t* taken() const { return taken_.data(); }
  void clear() { pending_.clear(); }

  std::uint32_t rate() const { return rate_; }
  std::uint64_t total() const { return total_; }
  std::uint64_t nonsilent_batches() const { return nonsilent_; }
  std::uint64_t dropped() const { return dropped_; }
  std::int32_t peak() const { return peak_; }

 private:
  std::vector<std::int16_t> pending_, taken_;
  std::uint32_t rate_ = audio::kDspRate;
  std::uint64_t total_ = 0, nonsilent_ = 0, dropped_ = 0;
  std::int32_t peak_ = 0;
};

}  // namespace mvp::web
