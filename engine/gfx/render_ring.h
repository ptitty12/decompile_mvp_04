// The render thread's command ring (P2): a single-producer, single-consumer
// queue of records in memory both threads see. The emulation thread (the
// producer) appends what the renderer must see, in order: the GX commands the
// graphics processor executes (copied, so the CPU FIFO and display lists may be
// rewritten at once), VI fields, presents. The render thread (the consumer)
// runs the GX processor and the WebGPU renderer on them.
//
// Records are a 32-bit header (type << 24 | payload length) and the payload,
// padded to 4 bytes, contiguous in the buffer (a record that would cross the
// end starts again at offset 0 after a wrap marker). Positions are byte counts
// modulo 2^32; the capacity is a power of two far below that.
//
// Visibility is batched: commit() completes a record, publish() makes every
// committed record visible to the consumer (and wakes it if it sleeps).
// wait_read(pos) is the fence: it returns once the consumer has *finished*
// every record before pos (done() was called for each), so whatever memory
// those records made the renderer read has been read.
//
// Waiting uses futex-style waits on the position words: Atomics.wait in the
// browser (Emscripten pthreads), a short sleep loop elsewhere (tests).
#pragma once

#include <atomic>
#include <cstdint>
#include <vector>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4324)  // padded to the cache line on purpose
#endif

namespace mvp::gfx {

// Waits while `word` still holds `seen`, at most `max_ms` (< 0: no limit).
// May return early (spuriously); callers re-check their condition.
void ring_wait(std::atomic<std::uint32_t>& word, std::uint32_t seen, double max_ms);
// Wakes every thread waiting on `word`.
void ring_wake(std::atomic<std::uint32_t>& word);

class RenderRing {
 public:
  static constexpr std::uint32_t kWrap = 0xFF;      // record type reserved for the wrap marker
  static constexpr std::uint32_t kMaxLen = 0xFFFFFF;  // 24-bit payload length

  // `capacity`: a power of two, at least 4 KiB.
  explicit RenderRing(std::uint32_t capacity);
  RenderRing(const RenderRing&) = delete;
  RenderRing& operator=(const RenderRing&) = delete;

  std::uint32_t capacity() const { return cap_; }
  // The largest payload reserve() accepts (half the ring).
  std::uint32_t max_payload() const { return cap_ / 2 - 8; }

  // ---- producer ----
  // Space for a record of `len` payload bytes (len <= max_payload()), waiting
  // for the consumer to free room if needed. Fill it, then commit().
  std::uint8_t* reserve(std::uint32_t type, std::uint32_t len);
  void commit();
  // Makes the committed records visible and wakes a sleeping consumer.
  void publish();
  // Publishes when at least `bytes` committed bytes are not visible yet.
  void publish_if(std::uint32_t bytes) {
    if (wpos_ - pub_local_ >= bytes) publish();
  }
  // The position after the last committed record.
  std::uint32_t end() const { return wpos_; }
  // Publishes, then waits until the consumer has finished every record before
  // `pos`. Spins for `spin_us` microseconds first. Returns the time waited (ms).
  double wait_read(std::uint32_t pos, double spin_us = 50);
  // True if the consumer has finished every record before `pos`.
  bool finished(std::uint32_t pos) const {
    return static_cast<std::int32_t>(rd_.load(std::memory_order_acquire) - pos) >= 0;
  }

  // ---- consumer ----
  struct Record {
    std::uint32_t type = 0, len = 0;
    const std::uint8_t* data = nullptr;
  };
  // The next visible record, else false. Call done() when finished with it.
  bool next(Record* r);
  void done();
  // True if a published record is waiting (without taking it).
  bool has_data() const { return pub_.load(std::memory_order_acquire) != cpos_; }
  // Waits for published data, at most `max_ms` (< 0: no limit). True if there is some.
  bool wait_data(double max_ms);

  // ---- statistics (the producer's) ----
  std::uint64_t records() const { return records_; }
  std::uint64_t bytes() const { return bytes_; }
  std::uint64_t full_waits() const { return full_waits_; }

 private:
  std::uint32_t room() const { return cap_ - (wpos_ - rd_cached_); }

  std::vector<std::uint8_t> storage_;
  std::uint8_t* buf_ = nullptr;
  std::uint32_t cap_ = 0, mask_ = 0;

  // Shared words, each on its own cache line.
  alignas(64) std::atomic<std::uint32_t> pub_{0};        // published write position
  alignas(64) std::atomic<std::uint32_t> rd_{0};         // finished position (the consumer's)
  alignas(64) std::atomic<std::uint32_t> cons_wait_{0};  // the consumer sleeps on pub_
  alignas(64) std::atomic<std::uint32_t> prod_wait_{0};  // the producer sleeps on rd_

  // Producer-local.
  alignas(64) std::uint32_t wpos_ = 0, pub_local_ = 0, rd_cached_ = 0, open_ = 0;
  std::uint64_t records_ = 0, bytes_ = 0, full_waits_ = 0;
  // Consumer-local.
  alignas(64) std::uint32_t cpos_ = 0, cnext_ = 0, pub_cached_ = 0;
};

}  // namespace mvp::gfx

#ifdef _MSC_VER
#pragma warning(pop)
#endif
