// mvp-xlat: the translator's development CLI.
//
//   mvp-xlat cfg [--errors] [--tables]   recover functions and CFGs, print a summary
//   mvp-xlat emit-cpp <dir> [--shards N]  translate the whole DOL to C++ in <dir> (under build/)
//
// Reads the disc from MVP_DISC (or the build's default) and config/GV4E69/symbols.txt.
// Output describes the retail binary's structure only; it stays in the terminal
// or under build/.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "runtime/hle.h"
#include "translator/emit_cpp.h"
#include "translator/program.h"

using namespace mvp;
using namespace mvp::xlat;

int main(int argc, char** argv) {
  if (argc < 2) {
    std::fprintf(stderr, "usage: mvp-xlat cfg [--errors] [--tables] | emit-cpp <dir> [--shards N]\n");
    return 2;
  }
  std::string cmd = argv[1];
  bool show_errors = false, show_tables = false;
  for (int k = 2; k < argc; ++k) {
    if (!std::strcmp(argv[k], "--errors")) show_errors = true;
    if (!std::strcmp(argv[k], "--tables")) show_tables = true;
  }
  std::string err;
  auto in = load_inputs(default_disc_path(), default_symbols_path(), &err);
  if (!in) {
    std::fprintf(stderr, "mvp-xlat: %s\n", err.c_str());
    return 1;
  }
  if (cmd == "cfg") {
    ProgramCfg p = build_cfg(in->disc.dol, in->symbols);
    std::printf("functions %zu, words %zu (reachable %zu), blocks %zu\n", p.functions.size(), p.words,
                p.reachable_words, p.blocks);
    std::printf("calls %zu, tail calls %zu, indirect calls %zu, jump tables %zu, indirect jumps %zu, "
                "absolute calls %zu\n",
                p.calls, p.tail_calls, p.indirect_calls, p.jump_tables, p.indirect_jumps, p.absolute_calls);
    std::printf("resume points %zu, back edges %zu, secondary entries %zu, runs into the next function %zu, "
                "expected traps %zu, errors %zu\n",
                p.resume_points, p.back_edges, p.secondary_entries, p.falls_into_next, p.expected_traps,
                p.errors);
    if (show_tables)
      for (const auto& f : p.functions)
        for (const auto& t : f.tables)
          std::printf("  %s: bctr 0x%08X table 0x%08X, %zu entries\n", f.sym->name.c_str(), t.site, t.table,
                      t.targets.size());
    if (show_errors)
      for (const auto& e : p.error_list) std::printf("  %s\n", e.c_str());
    return p.errors ? 1 : 0;
  }
  if (cmd == "emit-cpp") {
    if (argc < 3) return 2;
    EmitOptions opt;
    for (std::size_t k = 0; k < rt::hle_table().size(); ++k) opt.hle[rt::hle_table()[k].name] = static_cast<int>(k);
    for (int k = 3; k + 1 < argc; ++k)
      if (!std::strcmp(argv[k], "--shards")) opt.shards = std::atoi(argv[k + 1]);
    ProgramCfg p = build_cfg(in->disc.dol, in->symbols);
    if (p.errors) {
      std::fprintf(stderr, "mvp-xlat: the CFG has %zu errors; not emitting\n", p.errors);
      return 1;
    }
    EmitStats st;
    if (!emit_cpp(p, argv[2], opt, &st, &err)) {
      std::fprintf(stderr, "mvp-xlat: %s\n", err.c_str());
      return 1;
    }
    std::printf("emitted %zu functions (%zu entry points), %zu instructions, %zu bytes of C++ in %d shards\n",
                st.functions, st.entries, st.instructions, st.bytes, opt.shards);
    return 0;
  }
  std::fprintf(stderr, "mvp-xlat: unknown command %s\n", cmd.c_str());
  return 2;
}
