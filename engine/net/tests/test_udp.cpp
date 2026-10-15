// Data-free test of the native UDP transport (net/udp.h): two lockstep sessions
// over 127.0.0.1, one of them through an impairing wrapper (loss, latency,
// jitter on the real clock), produce identical input streams.
#include <doctest/doctest.h>

#include <vector>

#include "net/identity.h"
#include "net/session.h"
#include "net/udp.h"

using namespace mvp;
using namespace mvp::net;

TEST_CASE("UDP loopback: two sessions in lockstep") {
  std::string err;
  auto ua = UdpTransport::open("127.0.0.1", 0, &err);
  REQUIRE_MESSAGE(ua, err);
  auto ub = UdpTransport::open("127.0.0.1", 0, &err);
  REQUIRE_MESSAGE(ub, err);
  CHECK(ua->local_port() != 0);
  REQUIRE(ua->set_peer("127.0.0.1", ub->local_port(), &err));
  REQUIRE(ub->set_peer("127.0.0.1", ua->local_port(), &err));
  ImpairedTransport ia(*ua, {3, 4, 0.2, 5});

  auto cfg = [](int player) {
    SessionConfig c;
    c.player = player;
    c.delay = 2;
    c.hash_interval = 0;
    c.nonce = static_cast<u64>(player);
    c.timeout_ms = 5000;
    c.id.build = "udp-test";
    c.id.packset = empty_packset_hash();
    return c;
  };
  auto pad_of = [](int player) {
    return [player](u64 f) {
      PadState p;
      p.connected = true;
      p.buttons = static_cast<u16>(((f / 5) * 37 + static_cast<u64>(player) * 11) & rt::pad::kAll);
      return p;
    };
  };
  Session a(ia, cfg(1), pad_of(1)), b(*ub, cfg(2), pad_of(2));
  std::vector<rt::FrameInput> ta, tb;
  const u64 frames = 400;
  const u64 start = host_ms();
  while ((ta.size() < frames || tb.size() < frames) && host_ms() - start < 20000) {
    const u64 now = host_ms();
    a.update(now);
    b.update(now);
    if (ta.size() < frames && a.ready(ta.size(), now)) ta.push_back(a.take(ta.size()));
    if (tb.size() < frames && b.ready(tb.size(), now)) tb.push_back(b.take(tb.size()));
    if (a.ended() || b.ended()) break;
    ia.wait(1);
  }
  CHECK(a.state() == State::Running);
  CHECK(b.state() == State::Running);
  REQUIRE(ta.size() == frames);
  REQUIRE(tb.size() == frames);
  for (std::size_t f = 0; f < frames; ++f) CHECK(ta[f] == tb[f]);
  CHECK(ia.dropped > 0);
  CHECK(ta[frames - 1].pad[0].buttons == ((((frames - 1 - 2) / 5) * 37 + 11) & rt::pad::kAll));
}
