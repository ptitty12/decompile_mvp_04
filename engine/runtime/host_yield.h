// Host yields (E2): rt::run() returns between VI fields, so that a browser can
// go back to its event loop (show the frame, read input) and call run() again
// for the next field.
//
// The guest cannot tell. A yield is an unwind like a thread switch's
// (runtime/native.h): native frames return, the next run() continues at c.pc
// and re-enters functions at their resume labels. It is taken at the end of a
// safe point, after the safe point's events and interrupts, and never inside
// an interrupt handler (it waits for the next safe point outside one). When
// the guest continues at that very safe point, the re-entered code calls the
// safe point again (resume labels sit before it): that first call, at the same
// PC with the same instruction count, returns at once, because the call the
// yield interrupted already did all of its work. So the guest runs exactly the
// same instructions with or without yields; `mvp-play --yield` and the browser
// shell check it against runs without them (docs/engine/WEB.md).
#pragma once

#include <cstdint>

#include "runtime/sys_hooks.h"

namespace mvp::rt {

class YieldingHooks : public SystemHooks {
 public:
  using SystemHooks::SystemHooks;

  // Asks run() to return after the current safe point (or the next one outside
  // interrupt handlers). Call it from inside the run, e.g. from a GfxObserver's
  // vi_field.
  void request_yield() { want_ = true; }
  bool yield_pending() const { return want_; }

  void safepoint(ppc::Cpu& c) override;

  std::uint64_t yields = 0, repeats_skipped = 0;

 private:
  bool want_ = false;
  bool armed_ = false;  // the next safe point may be the one a yield interrupted
  std::uint32_t pc_ = 0;
  std::uint64_t ticks_ = 0;
};

}  // namespace mvp::rt
