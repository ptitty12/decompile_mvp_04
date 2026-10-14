// Register effects of every instruction, for emitters that keep guest registers
// in host locals (the WebAssembly emitter, E2).
//
// The cacheable registers are the 32 GPRs, CR, LR, CTR, XER[CA] and XER[SO]. For
// each instruction, `reads` is every cacheable register whose value can change
// any result (registers, memory, or state that is never cached), and `writes`
// every cacheable register it can change. Both are supersets: being too wide
// costs a spill or a reload, being too narrow is a bug. tests/test_effects.cpp
// checks every opcode against the semantics (sem.h): registers outside `writes`
// never change, and perturbing registers outside `reads` never changes a result.
#pragma once

#include <cstdint>

#include "ppc/isa.h"

namespace mvp::ppc {

namespace reg {
inline constexpr int CR = 32, LR = 33, CTR = 34, CA = 35, SO = 36, kCount = 37;
}  // namespace reg

using RegSet = std::uint64_t;
inline constexpr RegSet bit(int r) { return RegSet{1} << r; }
inline constexpr RegSet kAllGprs = 0xFFFFFFFFull;
inline constexpr RegSet kAllRegs = (RegSet{1} << reg::kCount) - 1;

struct Effects {
  RegSet reads = 0, writes = 0;
};

// Effects of a non-branch instruction as execute_plain() runs it (sem.h), or of
// a branch's condition and link (b, bc, bclr, bcctr: the CR bit, the CTR
// count-down, LR or CTR as the target, LK). sc, rfi, tw and twi report what they
// read; their control transfer is the caller's business.
Effects effects(Op op, Insn i);

}  // namespace mvp::ppc
