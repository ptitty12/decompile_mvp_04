// Data-free tests for controller input (DETERMINISM R14, E0c): the per-frame input
// queue, the PadState wire form, input scripts, and the PADRead replacement and
// frame poll hook (runtime/hle.h) on a bare machine.
#include <doctest/doctest.h>

#include <cstring>

#include "common/bytes.h"
#include "runtime/hle.h"
#include "runtime/input.h"
#include "runtime/machine.h"

using namespace mvp;
using namespace mvp::rt;

namespace {

FrameInput with_buttons(u16 p1) {
  FrameInput f = neutral_input(1);
  f.pad[0].buttons = p1;
  return f;
}

int hle_by_address(u32 a) {
  const auto& t = hle_table();
  for (std::size_t k = 0; k < t.size(); ++k)
    if (t[k].address == a) return static_cast<int>(k);
  return -1;
}

}  // namespace

TEST_CASE("the queue consumes exactly one frame's input per frame poll") {
  FrameInput boot = neutral_input(1);
  InputQueue q(boot);
  CHECK(q.current() == boot);  // before the first poll: the boot input
  CHECK(q.frames() == 0);
  CHECK_FALSE(q.ready());
  q.push(with_buttons(pad::kA));
  q.push(with_buttons(pad::kB));
  q.push(with_buttons(pad::kStart));
  CHECK(q.pending() == 3);
  CHECK(q.ready());
  CHECK(q.begin_frame() == 0);
  CHECK(q.current().pad[0].buttons == pad::kA);
  CHECK(q.current().pad[0].buttons == pad::kA);  // reading does not consume
  CHECK(q.begin_frame() == 1);
  CHECK(q.current().pad[0].buttons == pad::kB);
  q.push(with_buttons(pad::kX));  // pushed after polls began: still in frame order
  CHECK(q.begin_frame() == 2);
  CHECK(q.current().pad[0].buttons == pad::kStart);
  CHECK(q.begin_frame() == 3);
  CHECK(q.current().pad[0].buttons == pad::kX);
  CHECK(q.pending() == 0);
  // Nothing queued and no source: the previous frame's input holds.
  CHECK(q.begin_frame() == 4);
  CHECK(q.current().pad[0].buttons == pad::kX);
  CHECK(q.frames() == 5);
}

TEST_CASE("the queue asks its source for frames nobody pushed") {
  struct Counting : InputSource {
    std::vector<u64> asked;
    FrameInput input_for(u64 frame) override {
      asked.push_back(frame);
      return with_buttons(frame % 2 ? pad::kA : 0);
    }
  } src;
  InputQueue q;
  q.set_source(&src);
  CHECK(q.ready());
  q.begin_frame();                 // frame 0 from the source
  q.push(with_buttons(pad::kY));   // frame 1 pushed
  q.begin_frame();
  CHECK(q.current().pad[0].buttons == pad::kY);
  q.begin_frame();                 // frame 2 from the source
  q.begin_frame();                 // frame 3 from the source
  CHECK(q.current().pad[0].buttons == pad::kA);
  CHECK(src.asked == std::vector<u64>{0, 2, 3});
}

TEST_CASE("the wire form round-trips and rejects malformed frames") {
  FrameInput f = neutral_input(0x5);  // ports 1 and 3
  f.pad[0].buttons = pad::kA | pad::kStart | pad::kLeft;
  f.pad[0].stick_x = -128;
  f.pad[0].stick_y = 127;
  f.pad[0].substick_x = 5;
  f.pad[0].substick_y = -6;
  f.pad[0].trigger_l = 255;
  f.pad[2].trigger_r = 17;
  f.pad[2].analog_a = 200;
  f.pad[2].analog_b = 1;
  std::vector<u8> w = encode_frame(f);
  REQUIRE(w.size() == kFrameWireSize);
  CHECK(w[0] == 1);           // version
  CHECK(w[1] == 1);           // port 1 connected
  CHECK(w[2] == 0x11);        // buttons, big-endian (START | A)
  CHECK(w[3] == 0x01);        // LEFT
  CHECK(w[4] == 0x80);        // stick x = -128
  CHECK(w[12] == 0);          // port 2 missing
  auto back = decode_frame(w.data(), w.size());
  REQUIRE(back);
  CHECK(*back == f);
  std::vector<u8> bad = w;
  bad[0] = 2;  // unknown version
  CHECK_FALSE(decode_frame(bad.data(), bad.size()));
  CHECK_FALSE(decode_frame(w.data(), w.size() - 1));
  bad = w;
  bad[1] = 3;  // reserved flag bit
  CHECK_FALSE(decode_frame(bad.data(), bad.size()));
  bad = w;
  bad[2] |= 0x80;  // not a button bit (0x8000)
  CHECK_FALSE(decode_frame(bad.data(), bad.size()));
  bad = w;
  bad[13] = 1;  // a missing pad with a button held
  CHECK_FALSE(decode_frame(bad.data(), bad.size()));
}

TEST_CASE("input scripts: events by frame, state holds until changed") {
  std::string err;
  auto s = InputScript::parse(
      "# a comment line\n"
      "mvp-input 1\n"
      "10 1 press START      # hold START from frame 10\n"
      "12 1 release start\n"
      "20 1 tap 3 A B\n"
      "30 1 stick -128 127\n"
      "30 1 cstick 1 -1\n"
      "31 1 trigger 255 0\n"
      "31 1 analog 9 8\n"
      "40 2 connect\n"
      "40 2 press X\n"
      "50 2 disconnect\n",
      &err);
  REQUIRE_MESSAGE(s, err);
  CHECK(s->events() == 11);  // tap is a press and a release
  CHECK(s->last_frame() == 50);
  FrameInput f0 = s->input_for(0);
  CHECK(f0 == neutral_input(1));
  CHECK(s->input_for(9).pad[0].buttons == 0);
  CHECK(s->input_for(10).pad[0].buttons == pad::kStart);
  CHECK(s->input_for(11).pad[0].buttons == pad::kStart);
  CHECK(s->input_for(12).pad[0].buttons == 0);
  CHECK(s->input_for(20).pad[0].buttons == (pad::kA | pad::kB));
  CHECK(s->input_for(22).pad[0].buttons == (pad::kA | pad::kB));
  CHECK(s->input_for(23).pad[0].buttons == 0);
  FrameInput f31 = s->input_for(31);
  CHECK(f31.pad[0].stick_x == -128);
  CHECK(f31.pad[0].stick_y == 127);
  CHECK(f31.pad[0].substick_x == 1);
  CHECK(f31.pad[0].substick_y == -1);
  CHECK(f31.pad[0].trigger_l == 255);
  CHECK(f31.pad[0].analog_a == 9);
  CHECK(f31.pad[0].analog_b == 8);
  CHECK_FALSE(f31.pad[1].connected);
  CHECK(s->input_for(45).pad[1].connected);
  CHECK(s->input_for(45).pad[1].buttons == pad::kX);
  CHECK(s->input_for(50).pad[1] == PadState{});
  // Going back recomputes from the start.
  CHECK(s->input_for(11).pad[0].buttons == pad::kStart);
  CHECK(s->input_for(11).pad[1] == PadState{});
}

TEST_CASE("input scripts: errors name the line") {
  std::string err;
  CHECK_FALSE(InputScript::parse("", &err));
  CHECK(err.find("header") != std::string::npos);
  CHECK_FALSE(InputScript::parse("mvp-input 2\n", &err));
  CHECK(err.find("version") != std::string::npos);
  CHECK_FALSE(InputScript::parse("mvp-input 1\n5 1 press JUMP\n", &err));
  CHECK(err.rfind("line 2:", 0) == 0);
  CHECK_FALSE(InputScript::parse("mvp-input 1\n5 5 press A\n", &err));
  CHECK_FALSE(InputScript::parse("mvp-input 1\n-1 1 press A\n", &err));
  CHECK_FALSE(InputScript::parse("mvp-input 1\n5 1 stick 200 0\n", &err));
  CHECK_FALSE(InputScript::parse("mvp-input 1\n5 1 trigger -1 0\n", &err));
  CHECK_FALSE(InputScript::parse("mvp-input 1\n5 1 tap 0 A\n", &err));
  CHECK_FALSE(InputScript::parse("mvp-input 1\n5 1 hold A\n", &err));
}

TEST_CASE("PADRead returns the current frame's input; the frame poll hook consumes frames") {
  Machine m;
  ppc::Cpu& c = m.cpu();
  int pad_read = hle_index("PADRead");
  int poll = hle_by_address(0x8014865Cu);
  REQUIRE(pad_read >= 0);
  REQUIRE(poll >= 0);
  CHECK(hle_table()[static_cast<std::size_t>(poll)].kind == HleKind::Before);

  FrameInput boot = neutral_input(0x3);  // ports 1 and 2
  InputQueue q(boot);
  FrameInput f = neutral_input(0x1);
  f.pad[0].buttons = pad::kStart | pad::kA;
  f.pad[0].stick_x = -3;
  f.pad[0].trigger_r = 0x80;
  q.push(f);
  g_input = &q;
  static std::vector<u64> seen;
  seen.clear();
  g_frame_hook = [](ppc::Cpu&, std::uint64_t frame) { seen.push_back(frame); };

  constexpr u32 kStatus = 0x80001000u;
  std::memset(m.mem1() + 0x1000, 0xEE, 48);
  auto read_pads = [&] {
    c.gpr[3] = kStatus;
    c.lr = 0x80003104u;
    hle_call(c, pad_read, nullptr);
    CHECK(c.pc == 0x80003104u);
  };
  std::uint64_t reads = g_pad_reads, polls = g_frame_polls;
  read_pads();  // before the first poll: the boot input
  const u8* s = m.mem1() + 0x1000;
  CHECK(c.gpr[3] == 0xC0000000u);  // channels 0 and 1
  CHECK(be16(s) == 0);
  CHECK(s[10] == 0);                 // port 1: PAD_ERR_NONE
  CHECK(s[12 + 10] == 0);            // port 2: PAD_ERR_NONE
  CHECK(s[24 + 10] == 0xFF);         // port 3: PAD_ERR_NO_CONTROLLER
  CHECK(s[36 + 10] == 0xFF);
  CHECK(s[11] == 0xEE);              // padding untouched

  hle_before(c, poll);  // frame 0 begins
  CHECK(q.frames() == 1);
  CHECK(seen == std::vector<u64>{0});
  read_pads();
  CHECK(c.gpr[3] == 0x80000000u);
  CHECK(be16(s) == (pad::kStart | pad::kA));
  CHECK(static_cast<s8>(s[2]) == -3);
  CHECK(s[7] == 0x80);
  CHECK(s[10] == 0);
  CHECK(s[12 + 10] == 0xFF);         // port 2 unplugged in frame 0
  CHECK(be16(s + 12) == 0);
  read_pads();                       // a second read in the same frame: the same input
  CHECK(be16(s) == (pad::kStart | pad::kA));
  CHECK(g_pad_reads == reads + 3);
  CHECK(g_frame_polls == polls + 1);

  g_input = nullptr;  // no input layer: no controllers
  read_pads();
  CHECK(c.gpr[3] == 0);
  CHECK(s[10] == 0xFF);
  g_frame_hook = nullptr;
}

TEST_CASE("a source may stop the run at the frame poll; the poll then consumes nothing (E5c)") {
  Machine m;
  ppc::Cpu& c = m.cpu();
  int poll = hle_by_address(0x8014865Cu);
  REQUIRE(poll >= 0);
  struct Waiting : InputSource {
    int asked = 0;
    bool here = false;  // whether the frame's input is known (else: "stopped the run")
    bool before_poll(ppc::Cpu&, u64) override {
      ++asked;
      return here;
    }
    FrameInput input_for(u64) override { return with_buttons(pad::kA); }
  } src;
  InputQueue q(neutral_input(1));
  q.set_source(&src);
  g_input = &q;
  static int hooked;
  hooked = 0;
  g_frame_hook = [](ppc::Cpu&, std::uint64_t) { ++hooked; };
  const std::uint64_t polls = g_frame_polls;

  hle_before(c, poll);  // the source stops the run: nothing happens
  CHECK(src.asked == 1);
  CHECK(q.frames() == 0);
  CHECK(g_frame_polls == polls);
  CHECK(hooked == 0);
  CHECK(q.current() == neutral_input(1));

  src.here = true;
  hle_before(c, poll);  // the same poll again, now with its input
  CHECK(src.asked == 2);
  CHECK(q.frames() == 1);
  CHECK(g_frame_polls == polls + 1);
  CHECK(hooked == 1);
  CHECK(q.current().pad[0].buttons == pad::kA);

  src.here = false;
  q.push(with_buttons(pad::kB));  // a queued input never waits
  hle_before(c, poll);
  CHECK(src.asked == 2);
  CHECK(q.frames() == 2);
  CHECK(q.current().pad[0].buttons == pad::kB);
  g_input = nullptr;
  g_frame_hook = nullptr;
}
