#include "runtime/sys_hooks.h"

#include <cstdio>

#include "runtime/hw.h"

namespace mvp::rt {

void SystemHooks::msr_changed(ppc::Cpu& c, u32 old) {
  constexpr u32 kXlat = ppc::msr::IR | ppc::msr::DR;
  bool was_real = (old & kXlat) != kXlat, is_real = (c.msr & kXlat) != kXlat;
  if (was_real != is_real) {
    m_->set_real_mode(is_real);
    ++real_mode_switches;
  }
}

void SystemHooks::safepoint(ppc::Cpu& c) {
  if (c.ticks >= tick_limit) throw StopRun{"instruction budget used up (--max-ticks)"};
  c.next_event = tick_limit;
}

void SystemHooks::icbi(ppc::Cpu& c, u32 ea) {
  ++icbi_blocks;
  if (!m_->code_intact(ea)) {
    char b[96];
    std::snprintf(b, sizeof b, "code block 0x%08X no longer matches the DOL (icbi)", ea & ~31u);
    throw ppc::GuestFault(c.pc, b);
  }
}

}  // namespace mvp::rt
