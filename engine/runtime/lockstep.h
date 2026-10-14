// Lockstep checking (E0b item 6): translated code against the reference
// interpreter. Two machines start from the same state; the native one runs
// translated code; at every translated function entry the reference machine
// interprets up to the same entry, and every register must be equal (MEM1 too,
// every `mem_every` entries and at the end). Development tool; not shipped.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "runtime/machine.h"
#include "runtime/native.h"
#include "translator/cfg.h"

namespace mvp::rt {

// Thrown by StopIo at the first MMIO access.
struct StopAtMmio {
  u32 addr;
  int size;
  bool write;
  u32 value;
  u32 pc;
};

struct StopIo : ppc::Io {
  ppc::Cpu* cpu = nullptr;
  u32 read(u32 addr, int size) override { throw StopAtMmio{addr, size, false, 0, cpu->pc}; }
  void write(u32 addr, u32 value, int size) override { throw StopAtMmio{addr, size, true, value, cpu->pc}; }
};

// Deterministic placeholder clock until the virtual clock (item 9): every read of
// the time base advances it by a fixed step, so both machines see the same values.
struct FixedHooks : ppc::Hooks {
  std::uint64_t tb = 0;
  u32 dec = 0;
  std::uint64_t time_base(ppc::Cpu&) override { return tb += 1000; }
  void set_time_base(ppc::Cpu&, std::uint64_t v) override { tb = v; }
  u32 decrementer(ppc::Cpu&) override { return dec; }
  void set_decrementer(ppc::Cpu&, u32 v) override { dec = v; }
  void msr_changed(ppc::Cpu&, u32) override {}
  void icbi(ppc::Cpu&, u32) override {}
  void system_call(ppc::Cpu& c) override;
};

struct LockstepResult {
  bool pass = false;
  std::string message;  // divergence or fault description
  std::uint64_t events = 0, ref_steps = 0, mem_checks = 0;
  StopAtMmio stop{};    // where the native run stopped
  std::vector<u32> recent;  // last function entries before a divergence
};

// Runs `nat` (translated code via rt::run) and `ref` (interpreter) from their
// current, identical states until both reach their first MMIO access.
LockstepResult run_lockstep(Machine& ref, Machine& nat, const xlat::ProgramCfg& cfg, u32 mem_every = 16);

// Register differences between two CPUs, as " name ref=.. nat=.." pairs.
std::string cpu_diff(const ppc::Cpu& a, const ppc::Cpu& b);

}  // namespace mvp::rt
