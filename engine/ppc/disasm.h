// Gekko disassembler. The text follows the conventions of decomp-toolkit's
// listings (simplified mnemonics, lowercase hex immediates, cr bit names), so a
// whole-DOL disassembly can be checked against dtk word for word. Branch targets
// print as absolute addresses ("0x800031A4") instead of labels.
#pragma once

#include <string>

#include "ppc/isa.h"

namespace mvp::ppc {

std::string disasm(u32 word, u32 address);

// Names used in operands.
std::string cr_bit_name(u32 bit);  // 0 -> "lt", 6 -> "cr1eq"
const char* spr_name(u32 spr);     // null when the SPR has no name

}  // namespace mvp::ppc
