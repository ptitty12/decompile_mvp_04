// The runtime's answers to the CPU hooks (ppc::Hooks): time base and
// decrementer, MSR changes, icbi, sc.
//
// The time base here is a placeholder that item 9 replaces with the virtual
// clock: it advances by a fixed amount on every read, so it is deterministic but
// not yet tied to executed instructions.
#pragma once

#include <cstdint>

#include "ppc/cpu.h"
#include "runtime/machine.h"

namespace mvp::rt {

class SystemHooks : public ppc::Hooks {
 public:
  explicit SystemHooks(Machine* m) : m_(m) {}

  std::uint64_t time_base(ppc::Cpu&) override { return tb_ += 1000; }
  void set_time_base(ppc::Cpu&, std::uint64_t v) override { tb_ = v; }
  u32 decrementer(ppc::Cpu&) override { return dec_; }
  void set_decrementer(ppc::Cpu&, u32 v) override { dec_ = v; }
  // Translation off (IR or DR clear) maps physical MEM1 at 0 (real mode).
  void msr_changed(ppc::Cpu& c, u32 old) override;
  // Translated code is only valid for the DOL's bytes: invalidating a changed
  // code block is a hard error (the vector area below 0x80003000 is not DOL code).
  void icbi(ppc::Cpu& c, u32 ea) override;
  // The OS's system call only flushes write buffers (HID0[ABE] toggle, rfi):
  // nothing to do here.
  void system_call(ppc::Cpu&) override { ++syscalls; }

  std::uint64_t syscalls = 0, icbi_blocks = 0, real_mode_switches = 0;

 private:
  Machine* m_;
  std::uint64_t tb_ = 0;
  u32 dec_ = 0;
};

}  // namespace mvp::rt
