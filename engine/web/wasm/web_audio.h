// Browser audio, the engine side (E2c, Q2): the AX mixer (audio/mixer.h)
// observes the DSP's frames exactly as natively, and its output goes to the
// page's AudioWorklet (engine/web/src/audio-worklet.ts), which resamples it to
// the device through its own drift resampler. Two ways:
//
// - A ring in shared memory (Q2, the threaded engine, whose memory is a
//   SharedArrayBuffer): the frames go into an AudioRing in the engine's heap as
//   the mixer makes them, inside the run, and the worklet reads them from there
//   at its own pace. No batch boundary and no message stands between the
//   emulation and the speaker.
// - Otherwise the frames collect here between two run batches and the Worker
//   hands each batch over (its own SharedArrayBuffer ring on a cross-origin
//   isolated page, else a transferred buffer through a MessagePort: worker.ts).
//
// Nothing flows back: guest state is the same with and without the mixer
// (E3b-MIX1), and the worklet's timing never reaches the Worker's loop.
#pragma once

#include <atomic>
#include <cstdint>
#include <cstring>
#include <memory>
#include <vector>

#include "audio/mixer.h"

namespace mvp::web {

// A single-producer, single-consumer ring of interleaved 16-bit stereo frames
// in shared memory; the worklet reads it with Atomics (audio-worklet.ts, the
// same layout; the Worker's own ring for the single-threaded engine too).
// Indices count frames and wrap at 2^32; the capacity is a power of two.
struct AudioRing {
  static constexpr std::uint32_t kMagic = 0x4D565041;  // "MVPA"
  std::atomic<std::uint32_t> magic{kMagic};
  std::atomic<std::uint32_t> capacity{0};  // frames
  std::atomic<std::uint32_t> rate{0};      // Hz of the frames written last
  std::atomic<std::uint32_t> write{0};     // producer: frames written
  std::atomic<std::uint32_t> read{0};      // consumer: frames read
  std::atomic<std::uint32_t> dropped{0};   // producer: frames that found the ring full
  std::atomic<std::uint32_t> data{0};      // byte address of the frames
  std::uint32_t reserved[9] = {};
};
static_assert(sizeof(AudioRing) == 64, "the worklet reads the header as 16 int32s");

class PendingAudio final : public audio::FrameSink {
 public:
  // At most this many frames wait (2 s at 32 kHz); older ones are dropped
  // (nobody is taking them: no worklet yet, or a stalled page).
  static constexpr std::uint32_t kMaxFrames = 64000;

  void audio_frames(const audio::s16* lr, audio::u32 frames, audio::u32 rate) override {
    rate_ = rate;
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
    if (ring_) {
      to_ring(lr, frames, rate);
      return;
    }
    pending_.insert(pending_.end(), lr, lr + 2 * static_cast<std::size_t>(frames));
    const std::size_t cap = 2 * static_cast<std::size_t>(kMaxFrames);
    if (pending_.size() > cap) {
      dropped_ += (pending_.size() - cap) / 2;
      pending_.erase(pending_.begin(), pending_.end() - static_cast<std::ptrdiff_t>(cap));
    }
  }

  // Q2: from now on the frames go into a ring of `capacity` frames (a power of
  // two) in this module's memory instead; returns its header for the worklet.
  AudioRing* make_ring(std::uint32_t capacity) {
    if (!ring_) {
      frames_.assign(2 * static_cast<std::size_t>(capacity), 0);
      ring_ = std::make_unique<AudioRing>();
      ring_->capacity.store(capacity);
      ring_->rate.store(rate_);
      ring_->data.store(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(frames_.data())));
      pending_.clear();
    }
    return ring_.get();
  }
  bool ring() const { return ring_ != nullptr; }

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
  std::uint64_t dropped() const { return dropped_ + (ring_ ? ring_->dropped.load() : 0); }
  std::int32_t peak() const { return peak_; }

 private:
  void to_ring(const audio::s16* lr, audio::u32 frames, audio::u32 rate) {
    AudioRing& r = *ring_;
    const std::uint32_t cap = r.capacity.load(std::memory_order_relaxed);
    const std::uint32_t w = r.write.load(std::memory_order_relaxed);
    const std::uint32_t used = w - r.read.load(std::memory_order_acquire);
    const std::uint32_t n = frames < cap - used ? frames : cap - used;
    const std::uint32_t at = w & (cap - 1), first = n < cap - at ? n : cap - at;
    std::memcpy(&frames_[2 * static_cast<std::size_t>(at)], lr, 4 * static_cast<std::size_t>(first));
    if (n > first) std::memcpy(frames_.data(), lr + 2 * first, 4 * static_cast<std::size_t>(n - first));
    r.rate.store(rate, std::memory_order_relaxed);
    r.write.store(w + n, std::memory_order_release);
    if (n < frames) r.dropped.fetch_add(frames - n, std::memory_order_relaxed);
  }

  std::vector<std::int16_t> pending_, taken_;
  std::vector<std::int16_t> frames_;   // the ring's frames (Q2)
  std::unique_ptr<AudioRing> ring_;
  std::uint32_t rate_ = audio::kDspRate;
  std::uint64_t total_ = 0, nonsilent_ = 0, dropped_ = 0;
  std::int32_t peak_ = 0;
};

}  // namespace mvp::web
