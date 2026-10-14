// mvp-boot: runs the retail DOL natively (translated C++), for development.
//
//   mvp-boot lockstep   E0b item 6: run the translated code from __start and the
//                       reference interpreter side by side (runtime/lockstep.h)
//                       up to the first MMIO access.
//   mvp-boot run [--until main|none] [--mmio N]
//                       E0b item 7+: boot with the IPL environment (runtime/boot.h)
//                       and the hardware model (runtime/hw.h); print the calls
//                       __start makes and the MMIO summary.
//
// Needs the disc (MVP_DISC) and a build with the translated code. Prints register
// values and addresses only; nothing it prints or writes is committed.
#include <cstdio>
#include <cstdlib>
#include <string>

#include "runtime/boot.h"
#include "runtime/hw.h"
#include "runtime/lockstep.h"
#include "runtime/sys_hooks.h"
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

struct RunTrace {
  const xlat::ProgramCfg* cfg = nullptr;
  u32 start_fn = 0, stop_at = 0;
  std::uint64_t events = 0;
  std::string name(u32 a) const {
    const xlat::Symbol* s = cfg->index.containing(a);
    return s ? s->name : std::string("?");
  }
};
RunTrace* g_trace = nullptr;

void trace_hook(ppc::Cpu& c, u32 addr) {
  RunTrace& t = *g_trace;
  ++t.events;
  const xlat::Symbol* caller = t.cfg->index.containing(c.lr - 4);
  if (caller && caller->address == t.start_fn)
    std::printf("  event %llu: __start (lr 0x%08X) calls %s (0x%08X)\n", static_cast<unsigned long long>(t.events),
                c.lr, t.name(addr).c_str(), addr);
  if (addr == t.stop_at) throw StopRun{"reached " + t.name(addr)};
}

int run_boot(const xlat::Inputs& in, int argc, char** argv) {
  std::string until = "main";
  std::size_t mmio_lines = 40;
  for (int k = 2; k + 1 < argc; ++k) {
    if (std::string(argv[k]) == "--until") until = argv[k + 1];
    if (std::string(argv[k]) == "--mmio") mmio_lines = static_cast<std::size_t>(std::atoi(argv[k + 1]));
  }
  xlat::ProgramCfg cfg = xlat::build_cfg(in.disc.dol, in.symbols);
  Machine m;
  m.load_dol(in.disc.dol);
  BootLayout L = setup_boot_environment(m, in.disc);
  std::printf("boot: FST at 0x%08X (%u bytes), BI2 at 0x%08X, arena hi 0x%08X\n", L.fst, L.fst_size, L.bi2,
              L.arena_hi);
  Hardware hw(&m.cpu(), m.mem1(), Machine::kMem1Size);
  SystemHooks hooks(&m);
  m.memory().io = &hw;
  m.cpu().hooks = &hooks;
  mvp_register_game();
  RunTrace t;
  t.cfg = &cfg;
  t.start_fn = in.disc.dol.entry();
  const xlat::Symbol* mainsym = in.symbols.find("main");
  t.stop_at = until == "main" ? (mainsym ? mainsym->address : 0x8014D63Cu) : 0;
  g_trace = &t;
  rt::g_entry_hook = &trace_hook;
  std::string why;
  int rc = 1;
  try {
    rt::run(m.cpu());
  } catch (const StopRun& s) {
    why = s.why;
    rc = s.why.rfind("reached", 0) == 0 ? 0 : 1;
  } catch (const ppc::GuestFault& f) {
    why = std::string("guest fault: ") + f.what() + " in " + t.name(f.pc());
  }
  rt::g_entry_hook = nullptr;
  std::printf("stopped: %s (pc 0x%08X in %s) after %llu function entries, %llu unwinds\n", why.c_str(),
              m.cpu().pc, t.name(m.cpu().pc).c_str(), static_cast<unsigned long long>(t.events),
              static_cast<unsigned long long>(rt::g_unwinds));
  std::printf("MMIO: %zu accesses logged, %zu bytes to the write-gather pipe, %llu sc, %llu icbi blocks\n",
              hw.log().size(), hw.fifo().size(), static_cast<unsigned long long>(hooks.syscalls),
              static_cast<unsigned long long>(hooks.icbi_blocks));
  std::size_t shown = 0;
  for (const auto& a : hw.log()) {
    if (shown++ >= mmio_lines) break;
    std::printf("  %s %-3s 0x%08X %d bytes %s 0x%08X  (pc 0x%08X %s)\n", a.write ? "W" : "R",
                Hardware::block_name(a.addr), a.addr, a.size, a.write ? "<-" : "->", a.value, a.pc,
                t.name(a.pc).c_str());
  }
  return rc;
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
  if (cmd == "run") return run_boot(*in, argc, argv);
  std::fprintf(stderr, "usage: mvp-boot lockstep | run [--until main|none] [--mmio N]\n");
  return 2;
}
