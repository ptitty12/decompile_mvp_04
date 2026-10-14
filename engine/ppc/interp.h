// Reference interpreter: executes guest instructions one at a time with the
// semantics library (sem.h). It is the oracle for every other execution path
// (translated C++, later WebAssembly) and the path that resumes suspended guest
// frames (D4).
#pragma once

#include "ppc/cpu.h"
#include "ppc/isa.h"

namespace mvp::ppc {

// Executes the instruction at c.pc and advances c.pc (to the branch target when a
// branch is taken). Returns the opcode it executed. Throws GuestFault on an
// invalid instruction, a guest trap or an unmapped access.
Op step(Cpu& c);

// Executes one already-fetched instruction word at c.pc (same contract as step).
Op execute(Cpu& c, u32 word);

// Executes a non-branch instruction's effect without touching c.pc. Returns false
// (doing nothing) for branches, sc, rfi and traps, which the caller must handle.
bool execute_plain(Cpu& c, Op op, Insn i);

}  // namespace mvp::ppc
