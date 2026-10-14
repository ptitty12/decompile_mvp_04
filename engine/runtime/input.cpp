#include "runtime/input.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <sstream>

namespace mvp::rt {

namespace pad {

u16 button_bit(const std::string& name) {
  static const struct {
    const char* n;
    u16 bit;
  } kNames[] = {{"LEFT", kLeft}, {"RIGHT", kRight}, {"DOWN", kDown}, {"UP", kUp}, {"Z", kZ},
                {"R", kR},       {"L", kL},         {"A", kA},       {"B", kB},   {"X", kX},
                {"Y", kY},       {"START", kStart}};
  std::string up;
  for (char ch : name) up.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(ch))));
  for (const auto& e : kNames)
    if (up == e.n) return e.bit;
  return 0;
}

}  // namespace pad

FrameInput neutral_input(u32 port_mask) {
  FrameInput f;
  for (int k = 0; k < kPorts; ++k) f.pad[k].connected = (port_mask >> k) & 1;
  return f;
}

std::vector<u8> encode_frame(const FrameInput& in) {
  std::vector<u8> out;
  out.reserve(kFrameWireSize);
  out.push_back(PadState::kVersion);
  for (const PadState& p : in.pad) {
    out.push_back(p.connected ? 1 : 0);
    out.push_back(static_cast<u8>(p.buttons >> 8));
    out.push_back(static_cast<u8>(p.buttons));
    for (s8 v : {p.stick_x, p.stick_y, p.substick_x, p.substick_y}) out.push_back(static_cast<u8>(v));
    for (u8 v : {p.trigger_l, p.trigger_r, p.analog_a, p.analog_b}) out.push_back(v);
  }
  return out;
}

std::optional<FrameInput> decode_frame(const u8* d, std::size_t size) {
  if (size != kFrameWireSize || d[0] != PadState::kVersion) return std::nullopt;
  FrameInput f;
  const u8* q = d + 1;
  for (PadState& p : f.pad) {
    if (q[0] & ~1u) return std::nullopt;  // reserved flag bits
    p.connected = q[0] & 1;
    p.buttons = static_cast<u16>(q[1] << 8 | q[2]);
    if (p.buttons & ~pad::kAll) return std::nullopt;
    p.stick_x = static_cast<s8>(q[3]);
    p.stick_y = static_cast<s8>(q[4]);
    p.substick_x = static_cast<s8>(q[5]);
    p.substick_y = static_cast<s8>(q[6]);
    p.trigger_l = q[7];
    p.trigger_r = q[8];
    p.analog_a = q[9];
    p.analog_b = q[10];
    if (!p.connected && !(p == PadState{})) return std::nullopt;  // a missing pad has no controls
    q += 11;
  }
  return f;
}

u64 InputQueue::begin_frame() {
  if (!pending_.empty()) {
    current_ = pending_.front();
    pending_.pop_front();
  } else if (source_) {
    current_ = source_->input_for(frames_);
  }  // else: the previous frame's input holds
  return frames_++;
}

// ---- scripts ----

namespace {

enum Op { kPress, kRelease, kStick, kCStick, kTrigger, kAnalog, kConnect, kDisconnect };

bool parse_int(const std::string& s, long lo, long hi, int* out) {
  if (s.empty()) return false;
  char* end = nullptr;
  long v = std::strtol(s.c_str(), &end, 10);
  if (*end || v < lo || v > hi) return false;
  *out = static_cast<int>(v);
  return true;
}

}  // namespace

std::optional<InputScript> InputScript::parse(const std::string& text, std::string* error,
                                              const FrameInput& initial) {
  InputScript s;
  s.initial_ = initial;
  s.state_ = initial;
  std::istringstream in(text);
  std::string raw;
  std::size_t line_no = 0;
  bool header = false;
  auto fail = [&](const std::string& why) {
    if (error) *error = "line " + std::to_string(line_no) + ": " + why;
    return std::nullopt;
  };
  while (std::getline(in, raw)) {
    ++line_no;
    if (auto hash = raw.find('#'); hash != std::string::npos) raw.resize(hash);
    std::istringstream ls(raw);
    std::vector<std::string> w;
    for (std::string t; ls >> t;) w.push_back(t);
    if (w.empty()) continue;
    if (!header) {
      if (w.size() != 2 || w[0] != "mvp-input") return fail("expected the header 'mvp-input 1'");
      if (w[1] != "1") return fail("unsupported script version " + w[1]);
      header = true;
      continue;
    }
    if (w.size() < 3) return fail("expected '<frame> <port> <command> ...'");
    char* end = nullptr;
    unsigned long long frame = std::strtoull(w[0].c_str(), &end, 10);
    if (*end || w[0][0] == '-') return fail("bad frame '" + w[0] + "'");
    int port = 0;
    if (!parse_int(w[1], 1, kPorts, &port)) return fail("bad port '" + w[1] + "' (1-4)");
    const std::string& cmd = w[2];
    Event e{frame, port - 1, 0, 0, 0, 0, line_no};
    auto buttons = [&](std::size_t from, u16* bits) -> bool {
      if (from >= w.size()) return false;
      for (std::size_t k = from; k < w.size(); ++k) {
        u16 b = pad::button_bit(w[k]);
        if (!b) return false;
        *bits |= b;
      }
      return true;
    };
    auto two = [&](long lo, long hi) { return w.size() == 5 && parse_int(w[3], lo, hi, &e.a) && parse_int(w[4], lo, hi, &e.b); };
    if (cmd == "press" || cmd == "release") {
      e.op = cmd == "press" ? kPress : kRelease;
      if (!buttons(3, &e.bits)) return fail("expected button names after " + cmd);
    } else if (cmd == "tap") {
      int n = 0;
      if (w.size() < 5 || !parse_int(w[3], 1, 1000000, &n)) return fail("expected 'tap N BUTTON...'");
      e.op = kPress;
      if (!buttons(4, &e.bits)) return fail("expected button names after tap N");
      Event r = e;
      r.op = kRelease;
      r.frame = frame + static_cast<u64>(n);
      s.events_.push_back(e);
      s.events_.push_back(r);
      continue;
    } else if (cmd == "stick" || cmd == "cstick") {
      e.op = cmd == "stick" ? kStick : kCStick;
      if (!two(-128, 127)) return fail("expected '" + cmd + " X Y' (-128..127)");
    } else if (cmd == "trigger" || cmd == "analog") {
      e.op = cmd == "trigger" ? kTrigger : kAnalog;
      if (!two(0, 255)) return fail("expected '" + cmd + " A B' (0..255)");
    } else if (cmd == "connect" || cmd == "disconnect") {
      e.op = cmd == "connect" ? kConnect : kDisconnect;
      if (w.size() != 3) return fail(cmd + " takes no arguments");
    } else {
      return fail("unknown command '" + cmd + "'");
    }
    s.events_.push_back(e);
  }
  if (!header) {
    line_no = 0;
    return fail("empty script (no 'mvp-input 1' header)");
  }
  std::stable_sort(s.events_.begin(), s.events_.end(),
                   [](const Event& a, const Event& b) { return a.frame < b.frame; });
  return s;
}

FrameInput InputScript::input_for(u64 frame) {
  if (at_frame_ && frame < *at_frame_) {  // going back: start over
    state_ = initial_;
    next_ = 0;
    at_frame_.reset();
  }
  for (; next_ < events_.size() && events_[next_].frame <= frame; ++next_) {
    const Event& e = events_[next_];
    PadState& p = state_.pad[e.port];
    switch (e.op) {
      case kPress: p.buttons |= e.bits; break;
      case kRelease: p.buttons &= static_cast<u16>(~e.bits); break;
      case kStick: p.stick_x = static_cast<s8>(e.a); p.stick_y = static_cast<s8>(e.b); break;
      case kCStick: p.substick_x = static_cast<s8>(e.a); p.substick_y = static_cast<s8>(e.b); break;
      case kTrigger: p.trigger_l = static_cast<u8>(e.a); p.trigger_r = static_cast<u8>(e.b); break;
      case kAnalog: p.analog_a = static_cast<u8>(e.a); p.analog_b = static_cast<u8>(e.b); break;
      case kConnect: p = PadState{}; p.connected = true; break;
      case kDisconnect: p = PadState{}; break;
    }
    if (!p.connected) p = PadState{};  // a missing pad has no controls
  }
  at_frame_ = frame;
  return state_;
}

}  // namespace mvp::rt
