// mvp-boot: runs the retail DOL natively (translated C++), for development.
//
//   mvp-boot lockstep   E0b item 6: run the translated code from __start and the
//                       reference interpreter side by side (runtime/lockstep.h)
//                       up to the first MMIO access.
//
// Needs the disc (MVP_DISC) and a build with the translated code. Prints register
// values and addresses only; nothing it prints or writes is committed.
#include <cstdio>
#include <string>

#include "runtime/lockstep.h"
#include "translator/program.h"

void mvp_register_game();

using namespace mvp;
using namespace mvp::rt;

namespace {

int lockstep(const xlat::Inputs& in) {
  xlat::ProgramCfg cfg = xlat::build_cfg(in.disc.dol, in.symbols);
  Machine ref, nat;
  FixedHooks ref_hooks, nat_hooks;
  StopIo ref_io, nat_io;
  ref_io.cpu = &ref.cpu();
  nat_io.cpu = &nat.cpu();
  ref.memory().io = &ref_io;
  nat.memory().io = &nat_io;
  ref.cpu().hooks = &ref_hooks;
  nat.cpu().hooks = &nat_hooks;
  ref.load_dol(in.disc.dol);
  nat.load_dol(in.disc.dol);
  mvp_register_game();
  LockstepResult r = run_lockstep(ref, nat, cfg, 16);
  auto name = [&](u32 a) {
    const xlat::Symbol* s = cfg.index.containing(a);
    return s ? s->name : std::string("?");
  };
  std::printf("%llu function-entry events compared, %llu reference instructions, %llu full MEM1 comparisons\n",
              static_cast<unsigned long long>(r.events), static_cast<unsigned long long>(r.ref_steps),
              static_cast<unsigned long long>(r.mem_checks));
  if (!r.pass) {
    std::printf("%s\n  recent entries:", r.message.c_str());
    for (u32 a : r.recent) std::printf(" %08X(%s)", a, name(a).c_str());
    std::printf("\nFAIL\n");
    return 1;
  }
  std::printf("first MMIO access: %s of %d bytes at 0x%08X, from 0x%08X (%s)\n", r.stop.write ? "write" : "read",
              r.stop.size, r.stop.addr, r.stop.pc, name(r.stop.pc).c_str());
  std::printf("PASS: zero divergences from __start to the first MMIO access\n");
  return 0;
}

}  // namespace

int main(int argc, char** argv) {
  std::string cmd = argc > 1 ? argv[1] : "";
  std::string err;
  auto in = xlat::load_inputs(xlat::default_disc_path(), xlat::default_symbols_path(), &err);
  if (!in) {
    std::fprintf(stderr, "mvp-boot: %s\n", err.c_str());
    return 77;
  }
  if (cmd == "lockstep") return lockstep(*in);
  std::fprintf(stderr, "usage: mvp-boot lockstep\n");
  return 2;
}
