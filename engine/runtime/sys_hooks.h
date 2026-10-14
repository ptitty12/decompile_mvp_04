// The runtime's answers to the CPU hooks (ppc::Hooks): the virtual clock (time
// base and decrementer), interrupt delivery at safe points, the idle skip, MSR
// changes, icbi and sc (E0b items 7 and 9).
//
// Virtual clock (DETERMINISM R1): the time base is derived only from the number
// of guest instructions run (c.ticks) at a fixed charge of `cpi` CPU cycles per
// instruction; the CPU runs at 486 MHz and the time base at 1/12 of that. Host
// time never enters. Interrupts (decrementer, and PI causes from the hardware
// model) are delivered only at safe points (function entries and loop back
// edges) while MSR[EE] is set (R4), by running the OS's own exception vector code.
#pragma once

#include <cstdint>

#include "ppc/cpu.h"
#include "runtime/machine.h"

namespace mvp::rt {

class Hardware;

struct ClockConfig {
  std::uint32_t cpi = 2;  // CPU cycles charged per guest instruction (part of the netplay handshake)
};

class SystemHooks : public ppc::Hooks {
 public:
  explicit SystemHooks(Machine* m, Hardware* hw = nullptr, ClockConfig clk = {}) : m_(m), hw_(hw), clk_(clk) {}

  // Time base for the instruction count `ticks`.
  std::uint64_t tb_at(std::uint64_t ticks) const { return tb_offset_ + ticks * clk_.cpi / 12; }
  // First instruction count at which the time base reaches `tb`.
  std::uint64_t ticks_for(std::uint64_t tb) const;

  std::uint64_t time_base(ppc::Cpu& c) override { return tb_at(c.ticks); }
  void set_time_base(ppc::Cpu& c, std::uint64_t v) override;
  u32 decrementer(ppc::Cpu& c) override;
  void set_decrementer(ppc::Cpu& c, u32 v) override;
  // Translation off (IR or DR clear) maps physical MEM1 at 0 (real mode); EE set
  // may make a pending interrupt deliverable at the next safe point.
  void msr_changed(ppc::Cpu& c, u32 old) override;
  // Translated code is only valid for the DOL's bytes: invalidating a changed
  // code block is a hard error (the vector area below 0x80003000 is not DOL code).
  void icbi(ppc::Cpu& c, u32 ea) override;
  // The OS's system call only flushes write buffers (HID0[ABE] toggle, rfi):
  // nothing to do here.
  void system_call(ppc::Cpu&) override { ++syscalls; }
  // Runs due events, delivers a pending interrupt, applies the idle skip, and
  // stops the run (StopRun) once `tick_limit` instructions have run.
  void safepoint(ppc::Cpu& c) override;

  // Recomputes c.next_event from the scheduled events.
  void reschedule(ppc::Cpu& c);

  std::uint64_t tick_limit = ~0ull;
  std::uint64_t syscalls = 0, icbi_blocks = 0, real_mode_switches = 0;
  std::uint64_t external_interrupts = 0, decrementer_interrupts = 0, idle_skips = 0, idle_ticks_skipped = 0;

 private:
  void deliver(ppc::Cpu& c, u32 vector);

  Machine* m_;
  Hardware* hw_;
  ClockConfig clk_;
  std::uint64_t tb_offset_ = 0;
  // Decrementer: value `dec_value_` written at time base `dec_base_`.
  u32 dec_value_ = 0;
  std::uint64_t dec_base_ = 0;
  std::uint64_t dec_fire_tb_ = ~0ull;  // when it next turns negative
  bool dec_pending_ = false;
};

}  // namespace mvp::rt
