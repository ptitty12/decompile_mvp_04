// Data-free check of runs that stop at the frame poll (E5c: an input source
// that waits for a frame's input stops the run there, YieldingHooks::stop_before,
// runtime/hle.h). The synthetic program (translator/tests/synth.h) calls the
// hooked poll four times in a row, with no safe point between the calls where
// the runtime would stop on its own. A source that makes every poll wait once
// must stop the run at each of them, before the poll consumes anything, and the
// guest must run exactly as without the stops. Used by the C++ emitter's and the
// wasm emitter's tests, after they registered their translated code.
#pragma once

#include <cstdio>
#include <iterator>
#include <set>
#include <string>
#include <vector>

#include "../../ppc/tests/encode.h"
#include "../../translator/tests/synth.h"
#include "common/bytes.h"
#include "runtime/hle.h"
#include "runtime/host_yield.h"
#include "runtime/input.h"
#include "runtime/lockstep.h"
#include "runtime/native.h"

namespace mvp::rt::poll_stop {

// Frame f's input has bit f set on port 1; with `wait`, each frame's input is
// "not here yet" the first time its poll asks.
struct Source : InputSource {
  YieldingHooks* hooks = nullptr;
  bool wait = false;
  std::set<std::uint64_t> asked;
  int stops = 0;
  bool before_poll(ppc::Cpu& c, std::uint64_t frame) override {
    if (!wait || !asked.insert(frame).second) return true;
    if (!hooks->stop_before(c)) return true;
    ++stops;
    return false;
  }
  FrameInput input_for(std::uint64_t frame) override {
    FrameInput in = neutral_input(1);
    in.pad[0].buttons = static_cast<std::uint16_t>(1u << frame) & pad::kAll;
    return in;
  }
};

struct Outcome {
  std::vector<std::string> polls;  // per poll: frame, instruction count, PC, input
  int runs = 0;                    // rt::run() calls that returned (stops)
  int stops = 0;
  std::uint64_t ticks = 0, frames = 0, unwinds = 0;
  std::string regs;                // every register at the end
  std::vector<std::uint32_t> results;
};

inline std::vector<std::string>* g_polls = nullptr;

inline void log_poll(ppc::Cpu& c, std::uint64_t frame) {
  char b[96];
  std::snprintf(b, sizeof b, "frame %llu ticks %llu pc %08x buttons %04x", static_cast<unsigned long long>(frame),
                static_cast<unsigned long long>(c.ticks), c.pc, g_input->current().pad[0].buttons);
  g_polls->push_back(b);
}

inline std::string regs(const ppc::Cpu& c) {
  std::string s;
  char b[32];
  for (int k = 0; k < 32; ++k) {
    std::snprintf(b, sizeof b, "r%d=%08x ", k, c.gpr[k]);
    s += b;
  }
  std::snprintf(b, sizeof b, "lr=%08x ctr=%08x cr=%08x", c.lr, c.ctr, c.cr);
  return s + b;
}

// Runs the synthetic program natively from its entry to its MMIO store, calling
// rt::run() again whenever it returns.
inline Outcome run(const vfs::Dol& dol, std::uint32_t results, bool wait) {
  Machine m;
  StopIo io;
  io.cpu = &m.cpu();
  m.memory().io = &io;
  YieldingHooks hooks(&m);
  m.cpu().hooks = &hooks;
  m.load_dol(dol);
  {
    // The floating-point unavailable handler (the program starts with MSR 0):
    // sets FP in SRR1 and returns (as in test_emit_lockstep).
    using namespace mvp::ppc::enc;
    const std::uint32_t handler[] = {SPR(467, 3, 272), SPR(339, 3, 27), D(24, 3, 3, 0x2000),
                                     SPR(467, 3, 27),  SPR(339, 3, 272), X(19, 0, 0, 0, 50)};
    for (std::size_t k = 0; k < std::size(handler); ++k) put_be32(m.mem1() + 0x800 + 4 * k, handler[k]);
    m.set_real_mode(true);
  }
  hooks.reschedule(m.cpu());
  Source src;
  src.hooks = &hooks;
  src.wait = wait;
  InputQueue q(neutral_input(1));
  q.set_source(&src);
  Outcome o;
  g_polls = &o.polls;
  g_input = &q;
  g_frame_hook = &log_poll;
  const std::uint64_t unwinds = g_unwinds, polls = g_frame_polls;
  for (;;) {
    try {
      rt::run(m.cpu());
    } catch (const StopAtMmio&) {
      break;
    }
    if (++o.runs > 100) break;  // never: four stops
  }
  g_input = nullptr;
  g_frame_hook = nullptr;
  g_polls = nullptr;
  o.stops = src.stops;
  o.ticks = m.cpu().ticks;
  o.frames = g_frame_polls - polls;
  o.unwinds = g_unwinds - unwinds;
  o.regs = regs(m.cpu());
  for (std::size_t k = 0; k < xlat::synth::expected_results().size(); ++k)
    o.results.push_back(be32(m.mem1() + (results & 0x01FFFFFF) + 4 * k));
  return o;
}

}  // namespace mvp::rt::poll_stop
