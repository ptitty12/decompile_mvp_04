// Build-time tool: translates the synthetic test program (tests/synth.h) to C++,
// for test_emit_lockstep. Data-free: the program is built from instruction fields.
#include <cstdio>

#include "synth.h"
#include "runtime/hle.h"
#include "translator/emit_cpp.h"

using namespace mvp;
using namespace mvp::xlat;

int main(int argc, char** argv) {
  if (argc < 2) {
    std::fprintf(stderr, "usage: mvp-synth-emit <dir>\n");
    return 2;
  }
  synth::Program prog = synth::make();
  std::vector<std::string> errs;
  SymbolTable syms = SymbolTable::parse(prog.symbols, &errs);
  auto dol = vfs::Dol::parse(prog.dol);
  if (!errs.empty() || !dol) {
    std::fprintf(stderr, "mvp-synth-emit: bad synthetic program\n");
    return 1;
  }
  ProgramCfg cfg = build_cfg(*dol, syms);
  for (const auto& e : cfg.error_list) std::fprintf(stderr, "mvp-synth-emit: %s\n", e.c_str());
  if (cfg.errors) return 1;
  EmitOptions opt;
  const auto& table = rt::hle_table();
  for (std::size_t k = 0; k < table.size(); ++k)
    opt.hle.push_back({table[k].name, table[k].address, static_cast<int>(k), table[k].kind == rt::HleKind::Before});
  opt.shards = 2;
  std::string err;
  if (!emit_cpp(cfg, argv[1], opt, nullptr, &err)) {
    std::fprintf(stderr, "mvp-synth-emit: %s\n", err.c_str());
    return 1;
  }
  return 0;
}
