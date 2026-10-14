// A GameCube machine for running the retail DOL: MEM1, the CPU, and the DOL
// loaded where the apploader would put it.
#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "ppc/cpu.h"
#include "vfs/dol.h"

namespace mvp::rt {

using u8 = std::uint8_t;
using u32 = std::uint32_t;

class Machine {
 public:
  static constexpr u32 kMem1Size = 0x01800000;  // 24 MiB
  static constexpr u32 kGuard = 64;             // bytes past the end, for unaligned accesses

  Machine();
  Machine(const Machine&) = delete;
  Machine& operator=(const Machine&) = delete;

  // Copies the DOL's sections into MEM1, zeroes .bss, sets the PC to the entry.
  void load_dol(const vfs::Dol& dol);

  ppc::Cpu& cpu() { return cpu_; }
  ppc::Memory& memory() { return *mem_; }
  u8* mem1() { return mem1_.data(); }
  const u8* mem1() const { return mem1_.data(); }

 private:
  std::vector<u8> mem1_;
  std::unique_ptr<ppc::Memory> mem_;
  ppc::Cpu cpu_;
};

}  // namespace mvp::rt
