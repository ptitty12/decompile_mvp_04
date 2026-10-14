// pureikyubu's interpreter behind PkOracle. Only this file sees its headers.
#include "pk_oracle.h"

#include <csetjmp>

#include "pch.h"

extern jmp_buf g_fuzzJmp;
extern bool g_fuzzActive;

// The core and its stubs expect this global (pureikyubu's bench.cpp defines it).
Gekko::GekkoCore* Core = nullptr;

namespace mvp::ppc::test {

PkOracle::PkOracle(std::uint8_t* ram, std::uint32_t size) {
  Flipper::ProcessorInterface::ram = ram;
  Flipper::ProcessorInterface::ramSize = size;
  if (!Core) Core = new Gekko::GekkoCore();
}

PkOracle::~PkOracle() {}

void PkOracle::load(const PkState& s) {
  Core->Reset();
  Core->cache->Enable(false);
  Core->icache->Enable(false);
  for (int i = 0; i < 16; i++) Core->regs.sr[i] = 0x80000000;
  // 256 MiB block at 0x80000000 -> physical 0, read/write.
  Core->regs.spr[(int)Gekko::SPR::DBAT0U] = 0x80001fff;
  Core->regs.spr[(int)Gekko::SPR::DBAT0L] = 0x00000002;
  Core->regs.spr[(int)Gekko::SPR::IBAT0U] = 0x80001fff;
  Core->regs.spr[(int)Gekko::SPR::IBAT0L] = 0x00000002;
  // Data also at 0x00000000 -> physical 0 (sums and differences of pointers land there).
  Core->regs.spr[(int)Gekko::SPR::DBAT1U] = 0x00001fff;
  Core->regs.spr[(int)Gekko::SPR::DBAT1L] = 0x00000002;
  Core->regs.msr = MSR_IR | MSR_DR | MSR_FP;
  for (int i = 0; i < 32; i++) Core->regs.gpr[i] = s.gpr[i];
  Core->regs.cr = s.cr;
  Core->regs.spr[(int)Gekko::SPR::XER] = s.xer;
  Core->regs.spr[(int)Gekko::SPR::LR] = s.lr;
  Core->regs.spr[(int)Gekko::SPR::CTR] = s.ctr;
  Core->regs.pc = s.pc;
}

void PkOracle::save(PkState* s) const {
  for (int i = 0; i < 32; i++) s->gpr[i] = Core->regs.gpr[i];
  s->cr = Core->regs.cr;
  s->xer = Core->regs.spr[(int)Gekko::SPR::XER];
  s->lr = Core->regs.spr[(int)Gekko::SPR::LR];
  s->ctr = Core->regs.spr[(int)Gekko::SPR::CTR];
  s->pc = Core->regs.pc;
}

bool PkOracle::step() {
  if (setjmp(g_fuzzJmp)) {
    g_fuzzActive = false;
    return false;
  }
  g_fuzzActive = true;
  Core->Step();
  g_fuzzActive = false;
  // An exception switches to real mode (MSR[IR] cleared) and a low vector.
  return (Core->regs.msr & MSR_IR) && Core->regs.pc >= 0x80000000u;
}

}  // namespace mvp::ppc::test
