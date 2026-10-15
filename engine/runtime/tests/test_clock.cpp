// Data-free tests of the virtual clock and interrupt delivery (E0b item 9): a
// guest loop with a decrementer handler at 0x900 (real mode, as the OS installs
// it) runs in the interpreter; the handler counts and re-arms the decrementer.
#include <doctest/doctest.h>

#include <vector>

#include "../../ppc/tests/encode.h"
#include "common/bytes.h"
#include "runtime/hw.h"
#include "runtime/native.h"
#include "runtime/sys_hooks.h"

using namespace mvp;
using namespace mvp::rt;
using namespace mvp::ppc::enc;

namespace {

void put(Machine& m, u32 addr, const std::vector<u32>& words) {
  for (std::size_t k = 0; k < words.size(); ++k) put_be32(m.mem1() + (addr & 0x01FFFFFF) + 4 * k, words[k]);
}

}  // namespace

TEST_CASE("time base and decrementer follow the instruction count") {
  Machine m;
  SystemHooks h(&m, nullptr, ClockConfig{2000});
  ppc::Cpu& c = m.cpu();
  c.hooks = &h;
  c.ticks = 600;
  CHECK(h.time_base(c) == 100);  // 600 instructions * 2 cycles / 12
  h.set_time_base(c, 5000);
  CHECK(h.time_base(c) == 5000);
  c.ticks += 60;
  CHECK(h.time_base(c) == 5010);
  CHECK(h.ticks_for(5010) == c.ticks);
  h.set_decrementer(c, 100);
  c.ticks += 600;  // 100 time-base ticks later
  CHECK(h.decrementer(c) == 0);
  // The decrementer fires when it turns negative: one tick later.
  CHECK(c.next_event == h.ticks_for(5010 + 101));
}

TEST_CASE("fractional charges per instruction (CLK2) and a change of charge mid-run") {
  Machine m;
  SystemHooks h(&m, nullptr, ClockConfig{1250});  // 1.25 cycles: 48 instructions per 5 time-base ticks
  ppc::Cpu& c = m.cpu();
  c.hooks = &h;
  c.ticks = 48;
  CHECK(h.time_base(c) == 5);
  c.ticks = 47;
  CHECK(h.time_base(c) == 4);  // rounds down
  CHECK(h.ticks_for(5) == 48);  // the first count that reaches it
  CHECK(h.ticks_for(4) == 39);  // 39 * 1.25 / 12 = 4.06; 38 gives 3.96
  // The charge changes at 4,800 instructions (500 ticks); the time base goes on from there.
  c.ticks = 4800;
  h.set_clock(c, ClockConfig{1000});
  CHECK(h.clock().cpi_milli == 1000);
  CHECK(h.time_base(c) == 500);
  c.ticks += 120;  // 120 more at one cycle each
  CHECK(h.time_base(c) == 510);
  CHECK(h.ticks_for(510) == c.ticks);
}

namespace {

// Decrementer handler at physical 0x900 (it runs in real mode, as the OS's
// vector does): counts in physical 0x1000, re-arms the decrementer, rfi. It
// uses only r10, which the test loops leave alone.
void put_dec_handler(Machine& m, s32 rearm) {
  put(m, 0x80000900, {
                         D(32, 10, 0, 0x1000),  // lwz r10, 0x1000(0)
                         D(14, 10, 10, 1),      // addi r10, r10, 1
                         D(36, 10, 0, 0x1000),  // stw r10, 0x1000(0)
                         D(14, 10, 0, rearm),   // li r10, rearm
                         SPR(467, 10, 22),      // mtdec r10
                         X(19, 0, 0, 0, 50),    // rfi
                     });
}

void start_thread(ppc::Cpu& c, SystemHooks& h, u32 pc) {
  c.pc = pc;
  c.msr = ppc::msr::EE | ppc::msr::IR | ppc::msr::DR | ppc::msr::FP | ppc::msr::RI;
  c.gpr[1] = 0x80400000;
  h.set_decrementer(c, 1200);
}

}  // namespace

TEST_CASE("decrementer interrupts are delivered at safe points while EE is set") {
  Machine m;
  SystemHooks h(&m);
  ppc::Cpu& c = m.cpu();
  c.hooks = &h;
  put_dec_handler(m, 1200);
  // Busy loop: r3 counts iterations; the back edge is a safe point.
  put(m, 0x80003100, {
                         D(14, 3, 3, 1),  // addi r3, r3, 1
                         I(-4),           // b . - 4
                     });
  u32 safe[] = {0x80003104};
  g_safe.set(safe, 1);
  g_idle.set(safe, 0);
  start_thread(c, h, 0x80003100);
  h.tick_limit = 200000;
  h.reschedule(c);
  try {
    run(c);
  } catch (const StopRun&) {
  }
  u32 count = be32(m.mem1() + 0x1000);
  // 200,000 instructions = 33,333 time-base ticks; the decrementer fires every
  // 1,201 ticks plus the handler's own run time: 27 interrupts.
  CHECK(count == h.decrementer_interrupts);
  CHECK(count >= 26);
  CHECK(count <= 28);
  CHECK(h.idle_skips == 0);
  CHECK((c.pc == 0x80003100 || c.pc == 0x80003104));
  CHECK((c.msr & ppc::msr::EE) != 0);  // restored by rfi
  CHECK(h.real_mode_switches == 2 * count);
  CHECK(c.gpr[10] == 1200);
  g_safe.set(safe, 0);
}

TEST_CASE("the idle skip jumps virtual time to the next interrupt") {
  Machine m;
  SystemHooks h(&m);
  ppc::Cpu& c = m.cpu();
  c.hooks = &h;
  put_dec_handler(m, 1200);
  // Wait until the handler has run three times, then return to LR:
  //   lis r9, 0x8000 / L: lwz r4, 0x1000(r9) / cmpwi r4, 3 / blt L / blr
  put(m, 0x80003200, {
                         D(15, 9, 0, 0x8000),   // lis r9, 0x8000
                         D(32, 4, 9, 0x1000),   // lwz r4, 0x1000(r9)
                         D(11, 0, 4, 3),        // cmpwi r4, 3
                         B(12, 0, -8),          // blt . - 8
                         X(19, 20, 0, 0, 16),   // blr
                     });
  u32 idle[] = {0x8000320C};
  g_safe.set(idle, 1);
  g_idle.set(idle, 1);
  start_thread(c, h, 0x80003200);
  h.reschedule(c);
  std::uint64_t interpreted = g_interpreted;
  c.lr = 0x80003300;
  call_indirect(c, 0x80003200);
  CHECK(c.pc == 0x80003300);
  CHECK(be32(m.mem1() + 0x1000) == 3);
  CHECK(h.decrementer_interrupts == 3);
  // The pass that leaves the loop (r4 == 3 already) skips nothing.
  CHECK(h.idle_skips == 3);
  // Three waits of 1,201 time-base ticks (7,206 instructions each) passed with
  // only a few dozen instructions actually run.
  CHECK(c.ticks >= 3 * 7206);
  CHECK(g_interpreted - interpreted < 100);
  CHECK(h.idle_ticks_skipped + (g_interpreted - interpreted) == c.ticks);
  g_safe.set(idle, 0);
  g_idle.set(idle, 0);
}

TEST_CASE("VI display interrupts raise the PI cause at their lines") {
  std::vector<u8> mem(0x01800000 + 64, 0);
  ppc::Cpu cpu;
  Hardware hw(&cpu, mem.data(), 0x01800000);
  constexpr std::uint64_t kLine = 1351350 / 525;  // 2,574 time-base ticks
  // DI0 at line 263 and DI1 at line 2, both enabled (VIInit programs such pairs).
  hw.write(0xCC002030, (0x1000u | 263u) << 16, 4);
  hw.write(0xCC002034, (0x1000u | 2u) << 16, 4);
  hw.write(0xCC003004, 0x100, 4);  // unmask VI
  CHECK_FALSE(hw.interrupt_pending());
  CHECK(hw.next_event_tb() == kLine);
  hw.advance(kLine);  // line 2 starts: DI1
  CHECK(hw.interrupt_pending());
  CHECK((hw.read(0xCC002034, 4) & 0x80000000u) != 0);
  CHECK((hw.read(0xCC002030, 4) & 0x80000000u) == 0);
  hw.write(0xCC002034, (0x1000u | 2u) << 16, 4);  // acknowledge (status bit clear)
  CHECK_FALSE(hw.interrupt_pending());
  hw.advance(262 * kLine - 1);  // just before line 263
  CHECK_FALSE(hw.interrupt_pending());
  hw.advance(262 * kLine);
  CHECK(hw.interrupt_pending());
  CHECK((hw.read(0xCC003000, 4) & 0x100) != 0);
  CHECK(hw.vi_fields() == 2);
  // Nothing more this frame: the next event is the next frame's start.
  CHECK(hw.next_event_tb() == 1351350);
  hw.write(0xCC003004, 0, 4);  // masked: still caused, no longer pending
  CHECK((hw.read(0xCC003000, 4) & 0x100) != 0);
  CHECK_FALSE(hw.interrupt_pending());
}
