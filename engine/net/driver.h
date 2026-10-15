// Netplay in the run loop (E5): the lockstep session becomes the input queue's
// source, and the host loop runs the guest only while the next frame's inputs
// are known. The engine's deterministic run loop is unchanged; only where the
// per-frame input comes from changes (E0c-IN1).
//
// The host loop (browser Worker, native tools) calls rt::run() repeatedly; it
// returns at every VI field (runtime/host_yield.h) and, with netplay, early
// when the next frame's input is missing. Before each call:
//
//     if (driver.may_run(now)) rt::run(cpu);   // else: wait for datagrams
//
// - may_run() pumps the session and generates the local input of frame
//   `polls + delay`; it is true when the next frame poll's input is known.
// - At a frame poll the input queue first asks before_poll(frame). When that
//   frame's input is not known, the driver stops the run right there, before
//   the poll consumes anything (YieldingHooks::stop_before): rt::run() returns,
//   the host loop waits in may_run(), and the next rt::run() makes the same poll
//   again (E5c). So the run waits at every poll whose input is missing, wherever
//   the poll is and however soon it follows the previous one.
// - Then the queue asks input_for(frame): the session's input, known by then. A
//   poll that cannot stop (inside an interrupt handler, or without yield hooks)
//   and finds no input stops the run ("gate missed") rather than guess; it has
//   not happened. In blocking mode (native tools only) input_for() waits
//   instead, pumping the transport.
// - after_poll() asks the run to yield at its next stopping safe point when the
//   following frame's input is not known yet (it often is not), so the host
//   loop pumps the network meanwhile. It also feeds the state hasher
//   (net/state_hash.h) and submits the window hashes to the session (desync
//   detection).
//
// Yields, stops and waits are invisible to the guest: they only decide when the
// guest runs, never what it computes.
//
// E5c: until then the gate relied on after_poll()'s yield alone, and a yield
// waits for a safe point where an event is due. When a frame takes less time
// than the gap between two events (the match's loading runs frames without
// rendering, some 130,000 instructions apart, with no VI, audio or DVD event in
// between), the next poll came first and found no input.
#pragma once

#include <cstdint>
#include <string>

#include "net/session.h"
#include "net/state_hash.h"
#include "runtime/host_yield.h"
#include "runtime/input.h"
#include "runtime/machine.h"

namespace mvp::net {

class NetplayDriver : public rt::InputSource {
 public:
  using Clock = std::uint64_t (*)();  // host milliseconds (timers only)

  // `yield_hooks` may be null when the host loop never yields early (blocking
  // mode). `clock` is used inside input_for() and after_poll().
  NetplayDriver(Session& s, Transport& t, rt::Machine& m, rt::YieldingHooks* yield_hooks, Clock clock,
                bool blocking = false);

  // Pumps the session; true when the guest may run up to the next frame poll.
  bool may_run(std::uint64_t now_ms);
  // The input queue's source (runtime/input.h): at the poll of frame `frame`,
  // stops the run there when that frame's input is not known (returns false).
  bool before_poll(ppc::Cpu& c, std::uint64_t frame) override;
  // The input queue's source (runtime/input.h): frame `frame`'s input.
  rt::FrameInput input_for(std::uint64_t frame) override;
  // Call from the frame hook (rt::g_frame_hook) at every poll, after its input
  // was consumed.
  void after_poll(std::uint64_t frame);

  Session& session() { return s_; }
  const StateHasher& hasher() const { return hasher_; }
  // Window hashes this side computed, in order (frame, hash).
  const std::vector<HashRecord>& windows() const { return windows_; }

  // Statistics.
  std::uint64_t stall_ms = 0, stalls = 0, gate_misses = 0, early_yields = 0, longest_stall_ms = 0;
  std::uint64_t poll_stops = 0;  // runs stopped at a poll whose input was missing (before_poll)
  // Optional: corrupt the hash of the window closing at this frame (tests of
  // the desync path only).
  std::uint64_t corrupt_window_at = ~0ull;

  // The local diagnostic: the session's report plus the slice hashes of the last
  // window (comparing two players' files shows which MEM1 range differs).
  std::string diagnostic() const;

 private:
  void end_stall(std::uint64_t now_ms);

  Session& s_;
  Transport& t_;
  rt::Machine& m_;
  rt::YieldingHooks* yh_;
  Clock clock_;
  bool blocking_;
  StateHasher hasher_;
  std::vector<HashRecord> windows_;
  bool stalled_ = false;
  std::uint64_t stall_start_ = 0;
};

}  // namespace mvp::net
