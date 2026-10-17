// Q4 (owner decision F1: native implementations of the hottest game functions):
// game functions the engine runs as host code (HleKind::Native, runtime/hle.h).
//
// Each is equal to the translated original in everything the guest can see: the
// same registers, memory and hardware accesses, in the same order, at the same
// guest times (c.pc and c.ticks at every access as the original's instruction
// would have them, and c.ticks counting the original's instructions at the end),
// so the guest state is the same whether it or the original runs. Each runs
// only when the state it is written for holds (MSR[FP] set, the fast
// floating-point model of ppc/fp.h, float quantization in the GQRs it uses,
// operands in plain memory) and calls the original otherwise. The interpreter
// always runs the original, so the lockstep checker compares the two.
#pragma once

#include "runtime/native.h"

namespace mvp::rt {

// fn_803EB000 (a leaf, 112 or 66 instructions): blends up to three 4x4 matrices
// (64 bytes each, r5 + the low byte of each of the three words at r3 times 64)
// with the weights at r3 (three singles; one matrix when the second weight is
// zero), combines the blend's four rows with each of the first three columns of
// the 4x4 matrix at r6 into a 3x4 matrix, and sends that down the write-gather
// pipe (the address at 0(r14)) as an XF matrix load: the word at 4(r14), the
// byte r10 * 12, then twelve singles. Leaves r11 = r10 * 9 for its caller.
void hle_fn_803EB000(Cpu& c, GuestFn original);

}  // namespace mvp::rt
