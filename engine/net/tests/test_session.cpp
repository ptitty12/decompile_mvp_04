// Data-free tests for the lockstep session (net/session.h) over the simulated
// network (net/transport.h SimLink): latency, jitter (reordering), loss,
// duplication, cuts. Two sessions must produce identical per-frame inputs (the
// exact stream the delay rule defines), never run a frame before the other peer
// produced its input for it, detect a desync on both sides, refuse incompatible
// peers, and time out.
#include <doctest/doctest.h>

#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

#include "net/identity.h"
#include "net/session.h"
#include "net/state_hash.h"

using namespace mvp;
using namespace mvp::net;

namespace {

// Player p's controller at sample frame f: changes every few frames, all fields used.
PadState scripted_pad(int player, u64 f) {
  u64 x = (f / static_cast<u64>(3 + player)) * 0x9E3779B97F4A7C15ull + static_cast<u64>(player) * 0xBF58476D1CE4E5B9ull;
  x ^= x >> 31;
  x *= 0x94D049BB133111EBull;
  x ^= x >> 29;
  PadState p;
  p.connected = true;
  p.buttons = static_cast<u16>(x) & rt::pad::kAll;
  p.stick_x = static_cast<rt::s8>(x >> 16);
  p.stick_y = static_cast<rt::s8>(x >> 24);
  p.substick_x = static_cast<rt::s8>(x >> 32);
  p.substick_y = static_cast<rt::s8>(x >> 40);
  p.trigger_l = static_cast<u8>(x >> 48);
  p.trigger_r = static_cast<u8>(x >> 56);
  p.analog_a = static_cast<u8>(x >> 4);
  p.analog_b = static_cast<u8>(x >> 12);
  return p;
}

// The input every peer must see at frame f with delay d.
rt::FrameInput expected(u64 f, u32 d) {
  rt::FrameInput in = rt::neutral_input(0x3);
  if (f >= d) {
    in.pad[0] = scripted_pad(1, f - d);
    in.pad[1] = scripted_pad(2, f - d);
  }
  return in;
}

Identity test_identity() {
  Identity id;
  id.build = "test";
  id.packset = empty_packset_hash();
  id.settings = "ports=0x3";
  return id;
}

SessionConfig config(int player, u32 delay) {
  SessionConfig c;
  c.player = player;
  c.delay = delay;
  c.hash_interval = 30;
  c.nonce = 1000 + static_cast<u64>(player);
  c.seed = 77 + static_cast<u64>(player);
  c.timeout_ms = 3000;
  c.id = test_identity();
  return c;
}

// A simulated game: runs frames at its own pace when the session lets it.
struct Peer {
  int player;
  Session s;
  u64 frame = 0;
  u64 next_due = 0;
  u32 frame_ms;
  u32 slow_every = 0, slow_ms = 0;  // every n-th frame takes slow_ms (loading)
  std::vector<rt::FrameInput> taken;
  StateHasher hasher;
  u64 run_hash = 0;
  u64 corrupt_at = ~0ull;  // submit a wrong hash for the window closing here
  u64 stalled_ms = 0;

  Peer(Transport& t, SessionConfig c, u32 ms)
      : player(c.player), s(t, c, [p = c.player](u64 f) { return scripted_pad(p, f); }), frame_ms(ms),
        hasher(c.hash_interval) {}
};

struct Sim {
  SimLink link;
  Peer a, b;
  u32 delay;
  u64 max_lead = 0;
  bool order_ok = true;

  Sim(SimLink::Params p, u32 da, u32 db, u32 ms_a = 16, u32 ms_b = 16)
      : link(p), a(link.end(0), config(1, da), ms_a), b(link.end(1), config(2, db), ms_b), delay(std::max(da, db)) {}

  void step_peer(Peer& me, Peer& other) {
    const u64 now = link.now();
    me.s.update(now);
    if (me.s.ended()) return;
    if (now < me.next_due) return;
    if (!me.s.ready(me.frame, now)) {
      if (me.s.running()) ++me.stalled_ms;
      return;
    }
    // The other peer must already have produced its input for this frame.
    if (other.s.local_horizon() <= me.frame && me.frame >= me.s.delay()) order_ok = false;
    rt::FrameInput in = me.s.take(me.frame, now);
    me.taken.push_back(in);
    std::vector<u8> w = rt::encode_frame(in);
    me.run_hash = xxh64(w.data(), w.size(), me.run_hash);
    // The "state": the running hash of all inputs so far, hashed like guest memory.
    u8 state[8];
    for (int k = 0; k < 8; ++k) state[k] = static_cast<u8>(me.run_hash >> (8 * k));
    if (auto h = me.hasher.at_frame(me.frame, state, sizeof state, me.frame * 1000)) {
      u64 v = *h;
      if (me.frame == me.corrupt_at) v ^= 1;
      me.s.submit_hash(static_cast<u32>(me.frame), v, now);
    }
    ++me.frame;
    me.next_due = now + me.frame_ms + (me.slow_every && me.frame % me.slow_every == 0 ? me.slow_ms : 0);
  }

  // Runs until both reached `frames` frames or `limit_ms` passed.
  void run(u64 frames, u64 limit_ms) {
    while (link.now() < limit_ms && (a.frame < frames || b.frame < frames)) {
      if (a.frame < frames) step_peer(a, b);
      if (b.frame < frames) step_peer(b, a);
      // Keep sessions pumped even when their game is done (acks, resends).
      if (a.frame >= frames) a.s.update(link.now());
      if (b.frame >= frames) b.s.update(link.now());
      max_lead = std::max<u64>(max_lead, a.frame > b.frame ? a.frame - b.frame : b.frame - a.frame);
      if (a.s.ended() && b.s.ended()) break;
      link.advance(1);
    }
  }

  void check_streams(u64 frames) {
    REQUIRE(a.taken.size() >= frames);
    REQUIRE(b.taken.size() >= frames);
    for (u64 f = 0; f < frames; ++f) {
      if (!(a.taken[f] == expected(f, delay)) || !(b.taken[f] == expected(f, delay))) {
        FAIL("input stream differs at frame " << f);
      }
    }
    CHECK(order_ok);
    CHECK(max_lead <= delay + 1);
  }
};

}  // namespace

TEST_CASE("handshake: negotiation of delay and seed") {
  Sim sim({20, 0, 0.0, 0.0, 1}, 2, 4);
  sim.run(10, 2000);
  CHECK(sim.a.s.state() == State::Running);
  CHECK(sim.b.s.state() == State::Running);
  CHECK(sim.a.s.delay() == 4);
  CHECK(sim.b.s.delay() == 4);
  CHECK(sim.a.s.seed() == 78);  // player 1's
  CHECK(sim.b.s.seed() == 78);
  CHECK(sim.a.s.local_port() == 0);
  CHECK(sim.b.s.local_port() == 1);
  sim.check_streams(10);
}

TEST_CASE("clean link: identical streams, the delay rule, no stalls once running") {
  Sim sim({15, 0, 0.0, 0.0, 2}, 3, 3);
  sim.run(2000, 120000);
  sim.check_streams(2000);
  CHECK(sim.a.s.stats().hashes_compared >= 60);
  CHECK(sim.b.s.stats().hashes_compared >= 60);
  CHECK(sim.a.s.state() == State::Running);
  // A one-way latency of 15 ms is less than 3 frames: after the start, nobody waits.
  CHECK(sim.a.stalled_ms < 100);
  CHECK(sim.b.stalled_ms < 100);
  CHECK(sim.a.s.stats().rtt_avg() >= 30.0);
  CHECK(sim.a.s.stats().rtt_avg() <= 50.0);
  // Without stalls the input latency is the delay: 3 frames of 16 ms, on both sides.
  for (const Peer* p : {&sim.a, &sim.b}) {
    CHECK(p->s.stats().latency_avg() >= 47.0);
    CHECK(p->s.stats().latency_avg() <= 50.0);
  }
}

TEST_CASE("lossy, jittery, duplicating link: identical streams") {
  for (u32 d : {0u, 1u, 2u, 3u, 4u}) {
    CAPTURE(d);
    Sim sim({30, 60, 0.25, 0.05, 1234 + d}, d, d);
    sim.run(1500, 600000);
    sim.check_streams(1500);
    CHECK(sim.link.dropped > 100);
    CHECK(sim.link.reordered > 10);
    CHECK(sim.link.duplicated > 10);
    CHECK(sim.a.s.stats().inputs_redundant > 0);
    CHECK(sim.a.s.state() == State::Running);
    CHECK(sim.b.s.state() == State::Running);
    CHECK_FALSE(sim.a.s.mismatch());
  }
}

TEST_CASE("very lossy link (60%): still identical") {
  Sim sim({40, 20, 0.6, 0.0, 99}, 4, 4);
  sim.run(600, 600000);
  sim.check_streams(600);
}

TEST_CASE("different speeds and loading hitches: the faster peer waits") {
  Sim sim({25, 10, 0.05, 0.0, 5}, 2, 2, 16, 21);
  sim.b.slow_every = 97;
  sim.b.slow_ms = 400;
  sim.run(1200, 600000);
  sim.check_streams(1200);
  CHECK(sim.a.stalled_ms > sim.b.stalled_ms);
  // The waiting peer samples its pad when the wait ends: its input latency is
  // the delay at the slower peer's pace (2 x 21 ms), not the delay plus its waits.
  MESSAGE("latency: fast peer " << sim.a.s.stats().latency_avg() << " ms, slow peer " << sim.b.s.stats().latency_avg() << " ms");
  CHECK(sim.a.s.stats().latency_avg() < 2 * 21 + 12);
}

TEST_CASE("desync: a wrong state hash stops both peers at that window") {
  Sim sim({20, 5, 0.1, 0.0, 7}, 3, 3);
  sim.b.corrupt_at = 30 * 10 - 1;  // window 10 closes at frame 299
  sim.run(2000, 120000);
  CHECK(sim.a.s.state() == State::Desynced);
  CHECK(sim.b.s.state() == State::Desynced);
  REQUIRE(sim.a.s.mismatch());
  CHECK(sim.a.s.mismatch()->frame == 299);
  REQUIRE(sim.b.s.mismatch());
  CHECK(sim.b.s.mismatch()->frame == 299);
  CHECK(sim.a.s.mismatch()->local != sim.a.s.mismatch()->remote);
  // Both stop close to the bad window (a few frames for the hash to travel).
  CHECK(sim.a.frame < 299 + 40);
  CHECK(sim.b.frame < 299 + 40);
  CHECK(sim.a.s.diagnostic().find("mismatch at frame 299") != std::string::npos);
  // The windows before it compared equal.
  CHECK(sim.a.s.stats().hashes_compared >= 9);
}

TEST_CASE("incompatible peers are refused with the reason") {
  SimLink link({10, 0, 0.0, 0.0, 3});
  SessionConfig ca = config(1, 2), cb = config(2, 2);
  cb.id.disc[3] = 9;
  Session a(link.end(0), ca, nullptr), b(link.end(1), cb, nullptr);
  for (int t = 0; t < 1000 && !(a.ended() && b.ended()); ++t) {
    a.update(link.now());
    b.update(link.now());
    link.advance(1);
  }
  CHECK(a.state() == State::Rejected);
  CHECK(b.state() == State::Rejected);
  CHECK(a.reason().find("disc") != std::string::npos);
  CHECK_FALSE(a.ready(0, link.now()));

  SimLink link2({10, 0, 0.0, 0.0, 3});
  Session c(link2.end(0), config(1, 2), nullptr), d(link2.end(1), config(1, 2), nullptr);
  for (int t = 0; t < 1000 && !(c.ended() && d.ended()); ++t) {
    c.update(link2.now());
    d.update(link2.now());
    link2.advance(1);
  }
  CHECK(c.state() == State::Rejected);
  CHECK(c.reason().find("player 1") != std::string::npos);
}

TEST_CASE("handshake survives heavy loss") {
  Sim sim({50, 30, 0.7, 0.0, 11}, 2, 2);
  sim.run(100, 60000);
  sim.check_streams(100);
}

TEST_CASE("a cut link times out on both sides; nobody runs past the other") {
  Sim sim({20, 0, 0.0, 0.0, 13}, 3, 3);
  sim.run(300, 60000);
  sim.check_streams(300);
  sim.link.set_cut(true);
  sim.run(100000, sim.link.now() + 10000);
  CHECK(sim.a.s.state() == State::Disconnected);
  CHECK(sim.b.s.state() == State::Disconnected);
  CHECK(sim.a.s.reason().find("stopped answering") != std::string::npos);
  CHECK(sim.order_ok);
  CHECK(sim.max_lead <= 4);
  // Neither ran more than delay+1 frames beyond the cut.
  CHECK(sim.a.frame <= 300 + 4 + 1);
}

TEST_CASE("quit: the other side learns it") {
  Sim sim({20, 0, 0.0, 0.0, 17}, 2, 2);
  sim.run(200, 60000);
  sim.a.s.quit(sim.link.now());
  CHECK(sim.a.s.state() == State::Ended);
  for (int t = 0; t < 200; ++t) {
    sim.b.s.update(sim.link.now());
    sim.link.advance(1);
  }
  CHECK(sim.b.s.state() == State::Disconnected);
  CHECK(sim.b.s.reason().find("left") != std::string::npos);
}

TEST_CASE("bandwidth: a few KB/s per direction") {
  Sim sim({30, 10, 0.02, 0.0, 21}, 3, 3);
  sim.run(3600, 600000);  // one minute of frames
  sim.check_streams(3600);
  const double seconds = static_cast<double>(sim.link.now()) / 1000.0;
  const double a_bps = static_cast<double>(sim.a.s.stats().bytes_sent) / seconds;
  MESSAGE("player 1 sends " << a_bps << " payload bytes/s, " << sim.a.s.stats().packets_sent / seconds << " packets/s");
  CHECK(a_bps < 8000);
}

TEST_CASE("Q5: when the peer's inputs arrived, and the round trip's jitter") {
  // A steady link: the round trips barely change, so the jitter stays small.
  Sim steady({15, 0, 0.0, 0.0, 21}, 3, 3);
  steady.run(600, 60000);
  const SessionStats& st = steady.a.s.stats();
  CHECK(st.rtt_recent >= 30.0);
  CHECK(st.rtt_recent <= 50.0);
  CHECK(st.rtt_jitter < 10.0);
  // A jittery link: up to 40 ms more one way, at random.
  Sim jittery({15, 40, 0.0, 0.0, 22}, 3, 3);
  jittery.run(600, 120000);
  CHECK(jittery.a.s.stats().rtt_jitter > st.rtt_jitter + 5.0);
  // The arrival times of the inputs still held: in frame order, none in the future, none for the
  // neutral frames before the delay or for inputs not here yet.
  Session& s = steady.b.s;
  CHECK_FALSE(s.remote_arrival_ms(0));
  CHECK_FALSE(s.remote_arrival_ms(s.remote_horizon()));
  u64 last = 0;
  int known = 0;
  for (u64 f = s.next_frame(); f < s.remote_horizon(); ++f) {
    auto t = s.remote_arrival_ms(f);
    REQUIRE(t);
    CHECK(*t >= last);
    CHECK(*t <= steady.link.now());
    last = *t;
    ++known;
  }
  CHECK(known >= 0);
  // Early in a session the first inputs after the delay have their times.
  Sim fresh({10, 0, 0.0, 0.0, 23}, 2, 2);
  fresh.b.frame_ms = 1000;  // b barely runs, so a holds its inputs
  fresh.run(2, 400);  // a takes frames 0 and 1 (neutral) and holds b's input of frame 2
  CHECK(fresh.a.s.remote_arrival_ms(2));
  CHECK_FALSE(fresh.a.s.remote_arrival_ms(1));
}
