#include "runtime/host_yield.h"

#include "runtime/native.h"

namespace mvp::rt {

void YieldingHooks::safepoint(ppc::Cpu& c) {
  if (armed_) {
    armed_ = false;
    if (c.pc == pc_ && c.ticks == ticks_) {
      ++repeats_skipped;  // the safe point the yield interrupted: it already ran
      return;
    }
  }
  const std::uint32_t at = c.pc;
  SystemHooks::safepoint(c);
  if (!want_ || g_exception_depth > 0) return;
  want_ = false;
  ++yields;
  // Continuing right here repeats this safe point; after a thread switch (an
  // unwind already under way) or a jump elsewhere, the dispatcher starts afresh
  // at c.pc exactly as it would without the yield, so nothing is skipped then.
  if (!g_unwinding && c.pc == at) {
    armed_ = true;
    pc_ = at;
    ticks_ = c.ticks;
  }
  yield_run();
}

bool YieldingHooks::stop_before(ppc::Cpu& c) {
  if (g_exception_depth > 0 || g_unwinding) return false;
  want_ = false;
  ++yields;
  ++stops;
  // The re-entered function's entry safe point, at this PC and instruction
  // count, is the one the stopped call already passed.
  armed_ = true;
  pc_ = c.pc;
  ticks_ = c.ticks;
  yield_run();
  return true;
}

}  // namespace mvp::rt
