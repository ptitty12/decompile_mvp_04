// A minimal guest machine for instruction tests: 1 MiB of RAM at 0x80000000 (and
// its uncached mirror at 0xC0000000), recording hooks, and a step helper.
#pragma once

#include <memory>
#include <set>
#include <vector>

#include "common/bytes.h"
#include "ppc/interp.h"

namespace mvp::ppc::test {

struct RecordingHooks : Hooks {
  u64 tb = 0;
  u32 dec = 0;
  int syscalls = 0;
  u32 last_old_msr = 0xFFFFFFFF;
  std::vector<u32> icbis;
  u64 time_base(Cpu&) override { return tb; }
  void set_time_base(Cpu&, u64 v) override { tb = v; }
  u32 decrementer(Cpu&) override { return dec; }
  void set_decrementer(Cpu&, u32 v) override { dec = v; }
  void msr_changed(Cpu&, u32 old) override { last_old_msr = old; }
  void icbi(Cpu&, u32 ea) override { icbis.push_back(ea); }
  void system_call(Cpu&) override { ++syscalls; }
};

// Ops executed by any Machine in this test binary (for the coverage check).
inline std::set<Op>& covered() {
  static std::set<Op> s;
  return s;
}

struct Machine {
  static constexpr u32 kBase = 0x80000000;
  static constexpr u32 kSize = 0x100000;
  static constexpr u32 kPc = 0x80001000;
  std::vector<u8> ram;
  std::unique_ptr<Memory> mem;
  RecordingHooks hooks;
  Cpu c;

  Machine() : ram(kSize + 16, 0), mem(std::make_unique<Memory>()) {
    mem->map(kBase, ram.data(), kSize);
    mem->map(0xC0000000, ram.data(), kSize);
    c.mem = mem.get();
    c.hooks = &hooks;
    c.pc = kPc;
  }
  // Executes `word` at kPc (or at `at`); returns the op.
  Op run(u32 word, u32 at = kPc) {
    put_be32(&ram[at - kBase], word);
    c.pc = at;
    Op op = step(c);
    covered().insert(op);
    return op;
  }
  u32 r32(u32 a) const { return be32(&ram[a - kBase]); }
  u32 r16(u32 a) const { return be16(&ram[a - kBase]); }
  u32 r8(u32 a) const { return ram[a - kBase]; }
  u64 r64(u32 a) const { return be64(&ram[a - kBase]); }
  void w32(u32 a, u32 v) { put_be32(&ram[a - kBase], v); }
  void w16(u32 a, u32 v) { put_be16(&ram[a - kBase], static_cast<u16>(v)); }
  void w8(u32 a, u32 v) { ram[a - kBase] = static_cast<u8>(v); }
  void w64(u32 a, u64 v) { put_be64(&ram[a - kBase], v); }
};

}  // namespace mvp::ppc::test
