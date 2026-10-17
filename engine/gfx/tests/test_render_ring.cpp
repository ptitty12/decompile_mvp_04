// The render thread's command ring (P2): order, contents, wrap-around, the
// full-ring wait and the fence, with a real producer and consumer thread.
#include <doctest/doctest.h>

#include <atomic>
#include <cstring>
#include <random>
#include <thread>
#include <vector>

#include "gfx/render_ring.h"

using mvp::gfx::RenderRing;

namespace {

// Payload of record `seq`: its sequence number, then bytes derived from it.
void fill(std::uint8_t* p, std::uint32_t len, std::uint32_t seq) {
  for (std::uint32_t k = 0; k < len; ++k) p[k] = static_cast<std::uint8_t>(seq * 31u + k * 7u);
  if (len >= 4) std::memcpy(p, &seq, 4);
}

bool check(const std::uint8_t* p, std::uint32_t len, std::uint32_t seq) {
  std::uint32_t got = seq;
  if (len >= 4) std::memcpy(&got, p, 4);
  if (got != seq) return false;
  for (std::uint32_t k = 4; k < len; ++k)
    if (p[k] != static_cast<std::uint8_t>(seq * 31u + k * 7u)) return false;
  return true;
}

std::uint32_t len_of(std::uint32_t seq, std::uint32_t max) {
  std::uint32_t x = seq * 2654435761u;
  x ^= x >> 13;
  std::uint32_t n = x % 97 == 0 ? x % max : x % 300;  // mostly small, sometimes large
  return n < 4 ? 4 : n;
}

}  // namespace

TEST_CASE("records come out in order, intact, across the wrap") {
  RenderRing ring(4096);
  CHECK(ring.capacity() == 4096);
  std::uint32_t seq = 0, got = 0;
  for (int round = 0; round < 50; ++round) {
    // Fill most of the ring, then drain it: the positions wrap several times.
    for (int k = 0; k < 9; ++k, ++seq) {
      const std::uint32_t n = 100 + (seq % 300);
      fill(ring.reserve(1 + seq % 5, n), n, seq);
      ring.commit();
    }
    RenderRing::Record r;
    CHECK_FALSE(ring.next(&r));  // nothing published yet
    ring.publish();
    while (ring.next(&r)) {
      CHECK(r.type == 1 + got % 5);
      CHECK(r.len == 100 + (got % 300));
      CHECK(check(r.data, r.len, got));
      ring.done();
      ++got;
    }
    CHECK(got == seq);
    CHECK(ring.finished(ring.end()));
  }
}

TEST_CASE("a producer and a consumer thread, with fences") {
  RenderRing ring(64 << 10);
  const std::uint32_t total = 200000;
  std::atomic<std::uint32_t> consumed{0};
  std::atomic<bool> bad{false};
  std::thread consumer([&] {
    std::uint32_t seq = 0;
    while (seq < total) {
      RenderRing::Record r;
      if (!ring.next(&r)) {
        ring.wait_data(5.0);
        continue;
      }
      if (r.type != 1 + seq % 7 || r.len != len_of(seq, ring.max_payload()) || !check(r.data, r.len, seq))
        bad = true;
      consumed.store(seq + 1, std::memory_order_release);  // "finished" before done()
      ring.done();
      ++seq;
    }
  });
  std::uint32_t fences = 0, late = 0;
  for (std::uint32_t seq = 0; seq < total; ++seq) {
    const std::uint32_t n = len_of(seq, ring.max_payload());
    fill(ring.reserve(1 + seq % 7, n), n, seq);
    ring.commit();
    ring.publish_if(1024);
    if (seq % 1000 == 999) {  // a fence: every record so far is finished when it returns
      ring.wait_read(ring.end());
      ++fences;
      if (consumed.load(std::memory_order_acquire) != seq + 1) ++late;
    }
  }
  ring.wait_read(ring.end());
  consumer.join();
  CHECK_FALSE(bad.load());
  CHECK(consumed.load() == total);
  CHECK(fences == total / 1000);
  CHECK(late == 0);
  CHECK(ring.records() == total);
  MESSAGE("full-ring waits: " << ring.full_waits());
}

TEST_CASE("Q4: the publishes are counted, and what each made visible is kept") {
  RenderRing ring(4096);
  CHECK(ring.publishes() == 0);
  ring.publish();  // nothing new: not a publish
  CHECK(ring.publishes() == 0);
  fill(ring.reserve(1, 10), 10, 1);
  ring.commit();
  const std::uint32_t first = ring.end();
  ring.publish();
  CHECK(ring.publishes() == 1);
  CHECK(ring.published_at(1) == first);
  fill(ring.reserve(1, 20), 20, 2);
  ring.commit();
  ring.publish_if(1);
  CHECK(ring.publishes() == 2);
  CHECK(ring.published_at(2) == ring.end());
  CHECK(ring.published_at(1) == first);
}
