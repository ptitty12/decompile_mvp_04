// C++ emitter (D1): translates every recovered function to C++ that calls the
// semantics library with constant instruction words (ppc/sem.h), so translated
// code and the reference interpreter share one definition of every instruction.
// Control flow follows the CFG: local branches are gotos, calls are C++ calls
// with the return-address check of runtime/native.h, jump tables are switches.
//
// The output is derived from the player's disc: it is written under build/ only.
#pragma once

#include <string>

#include "translator/cfg.h"

namespace mvp::xlat {

struct EmitOptions {
  int shards = 64;          // game_00.cpp ... game_NN.cpp
  bool pc_per_insn = true;  // store the guest PC before every instruction (precise faults)
};

struct EmitStats {
  std::size_t functions = 0, entries = 0, instructions = 0, bytes = 0;
};

// Writes <dir>/game_decls.h, <dir>/game_NN.cpp and <dir>/game_table.cpp. The
// table file defines `void mvp_register_game()`, which fills rt::g_native.
bool emit_cpp(const ProgramCfg& p, const std::string& dir, const EmitOptions& opt, EmitStats* stats,
              std::string* error);

}  // namespace mvp::xlat
