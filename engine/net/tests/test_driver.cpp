// Data-free tests for net/driver.h: the lockstep gate in the run loop, the
// early yield after a frame poll whose successor is missing, the "gate missed"
// stop, and the state-hash desync stop, on a bare machine (no game code). The
// two peers share one Machine: the hashed memory is the same unless a test
// changes it between the two peers' polls.
#include <doctest/doctest.h>

#include <vector>

#include "net/driver.h"
#include "net/identity.h"
#include "net/session.h"
#include "runtime/hle.h"
#include "runtime/hw.h"

using namespace mvp;
using namespace mvp::net;

namespace {

std::uint64_t g_now = 0;
std::uint64_t clock_ms() { return g_now; }

SessionConfig cfg(int player) {
  SessionConfig c;
  c.player = player;
  c.delay = 2;
  c.hash_interval = 4;
  c.nonce = static_cast<u64>(player);
  c.timeout_ms = 2000;
  c.id.build = "driver-test";
  c.id.packset = empty_packset_hash();
  return c;
}

struct Side {
  Session s;
  NetplayDriver d;
  std::uint64_t polls = 0;
  std::vector<rt::FrameInput> inputs;
  Side(Transport& t, int player, rt::Machine& m, rt::YieldingHooks& h)
      : s(t, cfg(player), [player](u64 f) {
          PadState p;
          p.connected = true;
          p.buttons = static_cast<u16>((f * 3 + static_cast<u64>(player)) & rt::pad::kAll);
          return p;
        }),
        d(s, t, m, &h, &clock_ms) {}
  // One host-loop step: the gate, then a "field" that polls once.
  bool step() {
    rt::g_frame_polls = polls;
    if (!d.may_run(g_now)) return false;
    inputs.push_back(d.input_for(polls));
    d.after_poll(polls);
    ++polls;
    return true;
  }
};

}  // namespace

TEST_CASE("the gate runs a frame only with both inputs; early yields; same streams") {
  rt::Machine m;
  rt::YieldingHooks ha(&m), hb(&m);
  SimLink link({30, 10, 0.1, 0.0, 5});
  Side a(link.end(0), 1, m, ha), b(link.end(1), 2, m, hb);
  g_now = 0;
  while (g_now < 60000 && (a.polls < 300 || b.polls < 300)) {
    if (a.polls < 300) a.step();
    if (b.polls < 300 && g_now % 2 == 0) b.step();  // b is slower
    link.advance(1);
    ++g_now;
  }
  REQUIRE(a.inputs.size() == 300);
  REQUIRE(b.inputs.size() == 300);
  for (std::size_t f = 0; f < 300; ++f) CHECK(a.inputs[f] == b.inputs[f]);
  CHECK(a.d.gate_misses == 0);
  CHECK(a.d.stalls > 0);
  CHECK(a.d.early_yields > 0);
  CHECK(ha.yield_pending());  // after_poll asked the run to return at its next safe point
  CHECK(a.d.windows().size() == 75);
  CHECK(a.s.stats().hashes_compared >= 70);
  CHECK(a.s.state() == State::Running);
  rt::g_frame_polls = 0;
}

TEST_CASE("a poll without its input stops the run (gate missed)") {
  rt::Machine m;
  rt::YieldingHooks ha(&m), hb(&m);
  SimLink link({30, 0, 0.0, 0.0, 6});
  Side a(link.end(0), 1, m, ha), b(link.end(1), 2, m, hb);
  g_now = 0;
  while (!a.s.running() || !b.s.running()) {
    a.s.update(g_now);
    b.s.update(g_now);
    link.advance(1);
    ++g_now;
  }
  // Frames 0 and 1 are below the delay; frame 2 needs b's input, which b has not produced.
  CHECK_NOTHROW(a.d.input_for(0));
  CHECK_NOTHROW(a.d.input_for(1));
  CHECK_THROWS_AS(a.d.input_for(2), rt::StopRun);
  CHECK(a.d.gate_misses == 1);
  rt::g_frame_polls = 0;
}

TEST_CASE("different memory at a window stops both sides with a desync") {
  rt::Machine m;
  rt::YieldingHooks ha(&m), hb(&m);
  SimLink link({10, 0, 0.0, 0.0, 7});
  Side a(link.end(0), 1, m, ha), b(link.end(1), 2, m, hb);
  g_now = 0;
  bool stopped_a = false, stopped_b = false;
  while (g_now < 20000 && !(stopped_a && stopped_b)) {
    try {
      if (!stopped_a) a.step();
    } catch (const rt::StopRun&) {
      stopped_a = true;
    }
    // b sees one byte of MEM1 differ while it hashes frame 40 (slice 0 of the
    // window 40..43).
    const bool poke = b.polls == 40;
    if (poke) m.mem1()[0x123456] ^= 0x5A;
    try {
      if (!stopped_b) b.step();
    } catch (const rt::StopRun&) {
      stopped_b = true;
    }
    if (poke) m.mem1()[0x123456] ^= 0x5A;
    a.s.update(g_now);
    b.s.update(g_now);
    link.advance(1);
    ++g_now;
  }
  CHECK(a.s.state() == State::Desynced);
  CHECK(b.s.state() == State::Desynced);
  REQUIRE(a.s.mismatch());
  CHECK(a.s.mismatch()->frame == 43);
  CHECK(a.d.diagnostic().find("last window slice") != std::string::npos);
  CHECK(a.polls < 43 + 4);
  rt::g_frame_polls = 0;
}
