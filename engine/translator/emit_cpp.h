// C++ emitter (D1): translates every recovered function to C++ that calls the
// semantics library with constant instruction words (ppc/sem.h), so translated
// code and the reference interpreter share one definition of every instruction.
// Control flow follows the CFG: local branches are gotos, calls are C++ calls
// with the return-address check of runtime/native.h, jump tables are switches.
// Every call's return address and every loop back edge is a resume label: an
// unwind may continue there in a live frame, and the dispatcher may re-enter the
// function's body there (runtime/native.h, E0c). Every FPU instruction first
// checks MSR[FP] and takes the floating-point unavailable exception when it is
// clear (rt::fp_unavailable, E3a).
//
// The output is derived from the player's disc: it is written under build/ only.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "translator/cfg.h"

namespace mvp::xlat {

struct HleSpec {
  std::string name;     // symbols.txt name, matched when `address` is 0
  std::uint32_t address = 0;
  int index = -1;       // in rt::hle_table()
  bool before = false;  // a hook before the body, not a replacement
};

struct EmitOptions {
  int shards = 64;          // game_00.cpp ... game_NN.cpp
  bool pc_per_insn = true;  // store the guest PC before every instruction (precise faults)
  // Replacements and hooks (runtime/hle.h), one per rt::hle_table() entry. A
  // replaced function gets a stub calling rt::hle_call, plus its translated
  // original as f_XXXXXXXX_orig; a hooked one calls rt::hle_before after its entry.
  std::vector<HleSpec> hle;
};

struct EmitStats {
  std::size_t functions = 0, entries = 0, instructions = 0, bytes = 0, hle_stubs = 0, resume_labels = 0;
  std::size_t fpu_checks = 0;   // FPU instructions checked for MSR[FP] (floating-point unavailable)
  std::vector<int> hle_matched;  // HleSpec::index of every spec that found its function
};

// Writes <dir>/game_decls.h, <dir>/game_NN.cpp and <dir>/game_table.cpp. The
// table file defines `void mvp_register_game()`, which fills rt::g_native, the
// safe points, the idle spins, rt::g_resume_labels and the replaced functions.
bool emit_cpp(const ProgramCfg& p, const std::string& dir, const EmitOptions& opt, EmitStats* stats,
              std::string* error);

}  // namespace mvp::xlat
