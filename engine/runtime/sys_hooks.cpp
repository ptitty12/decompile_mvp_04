#include "runtime/sys_hooks.h"

#include <algorithm>
#include <cstdio>

#include "ppc/isa.h"
#include "ppc/mem_access.h"
#include "ppc/sem.h"
#include "runtime/hw.h"
#include "runtime/native.h"

namespace mvp::rt {

namespace {
constexpr u32 kEE = ppc::msr::EE, kIP = 1u << 6, kME = 1u << 12, kILE = 1u << 16, kLE = 1u;

// Whether the spin loop's back-edge branch at c.pc is about to be taken. Only
// then does the guest wait; on the pass that leaves the loop no time may be
// skipped. (Idle spins never decrement CTR: the translator excludes those.)
bool spin_continues(ppc::Cpu& c) {
  ppc::Insn i{ppc::read32(c, c.pc)};
  if (i.opcd() == 18) return true;  // b
  if (i.opcd() != 16 || !(i.bo() & 4)) return false;
  return (i.bo() & 16) || ppc::sem::cr_bit(c, i.bi()) == ((i.bo() >> 3) & 1);
}
}  // namespace

std::uint64_t SystemHooks::ticks_for(std::uint64_t tb) const {
  if (tb <= tb_offset_) return 0;
  std::uint64_t d = tb - tb_offset_;  // ticks * cpi / 12 >= d
  return (d * 12 + clk_.cpi - 1) / clk_.cpi;
}

void SystemHooks::set_time_base(ppc::Cpu& c, std::uint64_t v) {
  tb_offset_ = v - c.ticks * clk_.cpi / 12;  // modular: the base may go "negative"
  reschedule(c);
}

u32 SystemHooks::decrementer(ppc::Cpu& c) {
  return dec_value_ - static_cast<u32>(tb_at(c.ticks) - dec_base_);
}

void SystemHooks::set_decrementer(ppc::Cpu& c, u32 v) {
  dec_base_ = tb_at(c.ticks);
  dec_value_ = v;
  if (static_cast<std::int32_t>(v) < 0) {
    // Writing a negative value signals the exception at once.
    dec_pending_ = true;
    dec_fire_tb_ = ~0ull;
  } else {
    dec_pending_ = false;
    dec_fire_tb_ = dec_base_ + v + 1;  // when bit 0 turns from 0 to 1
  }
  reschedule(c);
}

void SystemHooks::msr_changed(ppc::Cpu& c, u32 old) {
  constexpr u32 kXlat = ppc::msr::IR | ppc::msr::DR;
  bool was_real = (old & kXlat) != kXlat, is_real = (c.msr & kXlat) != kXlat;
  if (was_real != is_real) {
    m_->set_real_mode(is_real);
    ++real_mode_switches;
  }
  if ((c.msr & kEE) && !(old & kEE)) reschedule(c);  // a pending interrupt may now be taken
}

void SystemHooks::icbi(ppc::Cpu& c, u32 ea) {
  ++icbi_blocks;
  if (!m_->code_intact(ea)) {
    char b[96];
    std::snprintf(b, sizeof b, "code block 0x%08X no longer matches the DOL (icbi)", ea & ~31u);
    throw ppc::GuestFault(c.pc, b);
  }
}

void SystemHooks::reschedule(ppc::Cpu& c) {
  std::uint64_t next_tb = dec_fire_tb_;
  if (hw_) next_tb = std::min(next_tb, hw_->next_event_tb());
  std::uint64_t next = next_tb == ~0ull ? ~0ull : ticks_for(next_tb);
  bool pending = dec_pending_ || (hw_ && hw_->interrupt_pending());
  if ((c.msr & kEE) && pending) next = c.ticks;  // deliverable at the next safe point
  c.next_event = std::min(next, tick_limit);
}

void SystemHooks::deliver(ppc::Cpu& c, u32 vector) {
  u32 resume = c.pc, sp = c.gpr[1];
  u32 old = c.msr;
  c.spr[ppc::spr::SRR0] = resume;
  c.spr[ppc::spr::SRR1] = old & 0x0000FFFFu;
  c.msr = (old & (kME | kIP | kILE)) | ((old & kILE) ? kLE : 0);
  msr_changed(c, old);
  c.pc = ((old & kIP) ? 0xFFF00000u : 0u) | vector;
  reschedule(c);
  int depth = g_exception_depth++;
  u32 lr = g_exception_lr;
  g_exception_lr = c.lr;
  try {
    run_handler(c, resume, sp);  // back at `resume`, or another thread with rt::g_unwinding set
  } catch (...) {
    g_exception_depth = depth;
    g_exception_lr = lr;
    throw;
  }
  g_exception_depth = depth;
  g_exception_lr = lr;
}

void SystemHooks::safepoint(ppc::Cpu& c) {
  if (c.ticks >= tick_limit) throw StopRun{"instruction budget used up (--max-ticks)"};
  auto update = [&] {
    std::uint64_t tb = tb_at(c.ticks);
    if (hw_) hw_->advance(tb);
    if (tb >= dec_fire_tb_) {
      dec_pending_ = true;
      dec_fire_tb_ = ~0ull;
    }
  };
  update();
  bool ee = (c.msr & kEE) != 0;
  bool external = hw_ && hw_->interrupt_pending();
  if (g_idle.has(c.pc) && ee && !external && !dec_pending_ && spin_continues(c)) {
    // Idle skip: the guest spins waiting for an interrupt; nothing else can
    // happen until the next event, so virtual time jumps there.
    reschedule(c);
    if (c.next_event > c.ticks && c.next_event != ~0ull) {
      ++idle_skips;
      idle_ticks_skipped += c.next_event - c.ticks;
      c.ticks = c.next_event;
      if (c.ticks >= tick_limit) throw StopRun{"instruction budget used up (--max-ticks)"};
      update();
      external = hw_ && hw_->interrupt_pending();
    }
  }
  if (ee && external) {
    ++external_interrupts;
    deliver(c, 0x500);
  } else if (ee && dec_pending_) {
    ++decrementer_interrupts;
    dec_pending_ = false;
    deliver(c, 0x900);
  }
  reschedule(c);
}

}  // namespace mvp::rt
