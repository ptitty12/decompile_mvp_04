// A single-producer, single-consumer ring of stereo 16-bit frames (E3b): the
// mixer writes on the emulation thread at the pace of the guest's virtual
// clock, the host's audio device reads on its own thread. Nothing flows back:
// a full ring drops what the producer writes (counted), an empty one gives
// the consumer fewer frames. Lock-free; positions only grow.
#pragma once

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <vector>

namespace mvp::audio {

class Ring {
 public:
  // Capacity in frames, rounded up to a power of two.
  explicit Ring(std::uint32_t capacity_frames) {
    std::uint32_t c = 1;
    while (c < capacity_frames) c <<= 1;
    cap_ = c;
    buf_.assign(2 * static_cast<std::size_t>(c), 0);
  }

  std::uint32_t capacity() const { return cap_; }

  // Producer: appends up to `frames` frames; returns how many fit.
  std::uint32_t write(const std::int16_t* lr, std::uint32_t frames) {
    const std::uint64_t w = w_.load(std::memory_order_relaxed), r = r_.load(std::memory_order_acquire);
    const std::uint32_t space = cap_ - static_cast<std::uint32_t>(w - r);
    const std::uint32_t n = std::min(frames, space);
    copy_in(w, lr, n);
    w_.store(w + n, std::memory_order_release);
    if (n < frames) dropped_.fetch_add(frames - n, std::memory_order_relaxed);
    written_.fetch_add(n, std::memory_order_relaxed);
    return n;
  }

  // Consumer: takes up to `frames` frames; returns how many there were.
  std::uint32_t read(std::int16_t* lr, std::uint32_t frames) {
    const std::uint64_t r = r_.load(std::memory_order_relaxed), w = w_.load(std::memory_order_acquire);
    const std::uint32_t n = std::min(frames, static_cast<std::uint32_t>(w - r));
    copy_out(r, lr, n);
    r_.store(r + n, std::memory_order_release);
    return n;
  }

  // Consumer: discards up to `frames` frames.
  std::uint32_t skip(std::uint32_t frames) {
    const std::uint64_t r = r_.load(std::memory_order_relaxed), w = w_.load(std::memory_order_acquire);
    const std::uint32_t n = std::min(frames, static_cast<std::uint32_t>(w - r));
    r_.store(r + n, std::memory_order_release);
    return n;
  }

  // Frames waiting (exact on the consumer side, a lower bound on the producer side).
  std::uint32_t available() const {
    return static_cast<std::uint32_t>(w_.load(std::memory_order_acquire) - r_.load(std::memory_order_acquire));
  }
  std::uint64_t dropped() const { return dropped_.load(std::memory_order_relaxed); }
  std::uint64_t written() const { return written_.load(std::memory_order_relaxed); }

 private:
  void copy_in(std::uint64_t pos, const std::int16_t* lr, std::uint32_t n) {
    const std::uint32_t at = static_cast<std::uint32_t>(pos & (cap_ - 1));
    const std::uint32_t first = std::min(n, cap_ - at);
    std::memcpy(&buf_[2 * static_cast<std::size_t>(at)], lr, 4 * static_cast<std::size_t>(first));
    std::memcpy(&buf_[0], lr + 2 * static_cast<std::size_t>(first), 4 * static_cast<std::size_t>(n - first));
  }
  void copy_out(std::uint64_t pos, std::int16_t* lr, std::uint32_t n) const {
    const std::uint32_t at = static_cast<std::uint32_t>(pos & (cap_ - 1));
    const std::uint32_t first = std::min(n, cap_ - at);
    std::memcpy(lr, &buf_[2 * static_cast<std::size_t>(at)], 4 * static_cast<std::size_t>(first));
    std::memcpy(lr + 2 * static_cast<std::size_t>(first), &buf_[0], 4 * static_cast<std::size_t>(n - first));
  }

  std::uint32_t cap_ = 0;
  std::vector<std::int16_t> buf_;
  std::atomic<std::uint64_t> w_{0}, r_{0};
  std::atomic<std::uint64_t> dropped_{0}, written_{0};
};

}  // namespace mvp::audio
