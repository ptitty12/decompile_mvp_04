// A narrow interface to pureikyubu's Gekko interpreter (CC0, vendored in
// engine/third_party/pureikyubu), used as an independent oracle for integer,
// branch, CR and XER semantics. Its headers stay inside pk_oracle.cpp.
#pragma once

#include <cstdint>

namespace mvp::ppc::test {

struct PkState {
  std::uint32_t gpr[32];
  std::uint32_t cr, xer, lr, ctr, pc;
};

class PkOracle {
 public:
  // `ram` is the physical memory (big-endian bytes) mapped at 0x80000000 (code
  // and data) and at 0x00000000 (data) through block address translations, with
  // caches off.
  PkOracle(std::uint8_t* ram, std::uint32_t size);
  ~PkOracle();
  void load(const PkState& s);
  void save(PkState* s) const;
  // Executes one instruction. Returns false if the core took an exception or halted.
  bool step();
};

}  // namespace mvp::ppc::test
