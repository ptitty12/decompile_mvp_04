// Local-only check (E0b item 5 exit): recover every function's CFG from the
// retail DOL and symbols.txt. Passes when no branch target is unresolved, every
// cross-function branch lands on a function start, and every unconditional
// bctr goes through a recovered jump table. Exits 77 without the disc.
#include <cstdio>
#include <filesystem>

#include "translator/program.h"

using namespace mvp;
using namespace mvp::xlat;

int main() {
  std::string disc = default_disc_path();
  std::error_code ec;
  if (disc.empty() || !std::filesystem::exists(disc, ec)) {
    std::printf("SKIP: MVP_DISC not set\n");
    return 77;
  }
  std::string err;
  auto in = load_inputs(disc, default_symbols_path(), &err);
  if (!in) {
    std::printf("FAIL: %s\n", err.c_str());
    return 1;
  }
  ProgramCfg p = build_cfg(in->disc.dol, in->symbols);
  std::size_t bctr = 0, bctr_tables = 0, unreachable = p.words - p.reachable_words;
  for (const auto& f : p.functions)
    for (std::size_t k = 0; k < f.insns.size(); ++k) {
      const auto& x = f.insns[k];
      if (!f.reachable[k] || x.op != ppc::Op::bcctr || x.conditional || (x.word & 1)) continue;
      ++bctr;
      if (x.flow == Flow::JumpTable) ++bctr_tables;
    }
  std::printf("functions %zu (symbols.txt lists %zu), words %zu, reachable %zu, unreachable %zu, blocks %zu\n",
              p.functions.size(), in->symbols.functions().size(), p.words, p.reachable_words, unreachable, p.blocks);
  std::printf("calls %zu, tail calls %zu, indirect calls %zu, absolute calls %zu\n", p.calls, p.tail_calls,
              p.indirect_calls, p.absolute_calls);
  std::printf("bctr %zu, through recovered jump tables %zu; other indirect jumps %zu\n", bctr, bctr_tables,
              p.indirect_jumps);
  std::printf("resume points %zu, back edges (safe points) %zu, pure spins (idle skip) %zu\n",
              p.resume_points, p.back_edges, p.idle_spins);
  std::printf("gap functions (branch-target code labels outside every function) %zu, secondary entry points %zu, "
              "functions running into the next one %zu, expected traps %zu\n",
              p.gap_functions, p.secondary_entries, p.falls_into_next, p.expected_traps);
  for (const auto& g : p.gap_symbols) std::printf("  gap function %s at 0x%08X, %u bytes\n", g.name.c_str(), g.address, g.size);
  for (const auto& f : p.functions) {
    for (std::size_t k = 1; k < f.entries.size(); ++k)
      std::printf("  secondary entry 0x%08X in %s\n", f.entries[k], f.sym->name.c_str());
    if (f.falls_into) std::printf("  %s runs into 0x%08X\n", f.sym->name.c_str(), f.falls_into);
    for (std::uint32_t a : f.expected_traps) std::printf("  expected trap at 0x%08X in %s\n", a, f.sym->name.c_str());
  }
  for (std::size_t k = 0; k < p.error_list.size() && k < 30; ++k) std::printf("  %s\n", p.error_list[k].c_str());
  bool pass = p.errors == 0 && bctr == bctr_tables && p.functions.size() == in->symbols.functions().size() + p.gap_functions;
  std::printf("%s: %zu errors\n", pass ? "PASS" : "FAIL", p.errors);
  return pass ? 0 : 1;
}
