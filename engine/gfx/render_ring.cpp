#include "gfx/render_ring.h"

#include <chrono>
#include <cstring>
#include <thread>

#ifdef __EMSCRIPTEN_PTHREADS__
#include <emscripten/threading.h>
#endif

namespace mvp::gfx {

namespace {

using Clock = std::chrono::steady_clock;

double ms_since(Clock::time_point t0) {
  return std::chrono::duration<double, std::milli>(Clock::now() - t0).count();
}

constexpr std::uint32_t pad4(std::uint32_t n) { return (n + 3u) & ~3u; }

}  // namespace

void ring_wait(std::atomic<std::uint32_t>& word, std::uint32_t seen, double max_ms) {
#ifdef __EMSCRIPTEN_PTHREADS__
  emscripten_futex_wait(reinterpret_cast<volatile void*>(&word), seen, max_ms < 0 ? INFINITY : max_ms);
#else
  // Tests and native tools: yield until it changes or the time is up.
  const auto t0 = Clock::now();
  while (word.load(std::memory_order_acquire) == seen) {
    if (max_ms >= 0 && ms_since(t0) >= max_ms) return;
    std::this_thread::yield();
  }
#endif
}

void ring_wake(std::atomic<std::uint32_t>& word) {
#ifdef __EMSCRIPTEN_PTHREADS__
  emscripten_futex_wake(reinterpret_cast<volatile void*>(&word), 0x7FFFFFFF);
#else
  (void)word;
#endif
}

RenderRing::RenderRing(std::uint32_t capacity) {
  std::uint32_t c = 4096;
  while (c < capacity) c <<= 1;
  cap_ = c;
  mask_ = c - 1;
  storage_.assign(c, 0);
  buf_ = storage_.data();
}

std::uint8_t* RenderRing::reserve(std::uint32_t type, std::uint32_t len) {
  const std::uint32_t size = 4 + pad4(len);
  std::uint32_t at = wpos_ & mask_;
  const std::uint32_t to_end = cap_ - at;
  const std::uint32_t need = size <= to_end ? size : size + to_end;  // a wrap skips the rest of the buffer
  if (room() < need) {
    rd_cached_ = rd_.load(std::memory_order_acquire);
    if (room() < need) {
      ++full_waits_;
      publish();  // the consumer must see what is there to make room
      for (;;) {
        rd_cached_ = rd_.load(std::memory_order_acquire);
        if (room() >= need) break;
        prod_target_.store(wpos_ + need - cap_, std::memory_order_seq_cst);  // rd_ there: room() >= need
        prod_wait_.store(1, std::memory_order_seq_cst);
        const std::uint32_t seen = rd_.load(std::memory_order_seq_cst);
        rd_cached_ = seen;
        if (room() >= need) {
          prod_wait_.store(0, std::memory_order_relaxed);
          break;
        }
        ring_wait(rd_, seen, 5.0);
        prod_wait_.store(0, std::memory_order_relaxed);
      }
    }
  }
  if (size > to_end) {  // wrap: a marker, then the record at offset 0
    const std::uint32_t marker = kWrap << 24;
    std::memcpy(buf_ + at, &marker, 4);
    wpos_ += to_end;
    at = 0;
  }
  const std::uint32_t hdr = type << 24 | len;
  std::memcpy(buf_ + at, &hdr, 4);
  open_ = size;
  return buf_ + at + 4;
}

void RenderRing::commit() {
  wpos_ += open_;
  bytes_ += open_;
  ++records_;
  open_ = 0;
}

void RenderRing::publish() {
  if (pub_local_ == wpos_) return;
  pub_local_ = wpos_;
  pub_hist_[++publishes_ & (kPubHistory - 1)] = wpos_;
  pub_.store(wpos_, std::memory_order_seq_cst);
  if (cons_wait_.load(std::memory_order_seq_cst)) {
    cons_wait_.store(0, std::memory_order_relaxed);
    ring_wake(pub_);
  }
}

double RenderRing::wait_read(std::uint32_t pos, double spin_us) {
  publish();
  if (finished(pos)) return 0;
  const auto t0 = Clock::now();
  const double spin_ms = spin_us / 1000.0;
  for (unsigned n = 1; !finished(pos); ++n) {
    if (n % 64 || ms_since(t0) < spin_ms) continue;  // the consumer is usually in the middle of a record
    prod_target_.store(pos, std::memory_order_seq_cst);  // woken when the consumer gets there, not at every record
    prod_wait_.store(1, std::memory_order_seq_cst);
    const std::uint32_t seen = rd_.load(std::memory_order_seq_cst);
    if (static_cast<std::int32_t>(seen - pos) >= 0) break;
    ring_wait(rd_, seen, 5.0);
  }
  prod_wait_.store(0, std::memory_order_relaxed);
  rd_cached_ = rd_.load(std::memory_order_acquire);
  return ms_since(t0);
}

bool RenderRing::next(Record* r) {
  for (;;) {
    if (cpos_ == pub_cached_) {
      pub_cached_ = pub_.load(std::memory_order_acquire);
      if (cpos_ == pub_cached_) return false;
    }
    const std::uint32_t at = cpos_ & mask_;
    std::uint32_t hdr;
    std::memcpy(&hdr, buf_ + at, 4);
    const std::uint32_t type = hdr >> 24;
    if (type == kWrap) {  // the record continues at offset 0
      cpos_ += cap_ - at;
      rd_.store(cpos_, std::memory_order_release);
      continue;
    }
    r->type = type;
    r->len = hdr & kMaxLen;
    r->data = buf_ + at + 4;
    cnext_ = cpos_ + 4 + pad4(r->len);
    return true;
  }
}

void RenderRing::done() {
  cpos_ = cnext_;
  rd_.store(cpos_, std::memory_order_seq_cst);
  if (prod_wait_.load(std::memory_order_seq_cst) &&
      static_cast<std::int32_t>(cpos_ - prod_target_.load(std::memory_order_seq_cst)) >= 0)
    ring_wake(rd_);
}

bool RenderRing::wait_data(double max_ms) {
  if (has_data()) return true;
  cons_wait_.store(1, std::memory_order_seq_cst);
  const std::uint32_t seen = pub_.load(std::memory_order_seq_cst);
  if (seen == cpos_) ring_wait(pub_, seen, max_ms);
  cons_wait_.store(0, std::memory_order_relaxed);
  return has_data();
}

}  // namespace mvp::gfx
