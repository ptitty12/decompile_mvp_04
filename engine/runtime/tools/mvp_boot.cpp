// mvp-boot: runs the retail DOL natively (translated C++), for development.
//
//   mvp-boot lockstep   E0b item 6: run the translated code from __start and the
//                       reference interpreter side by side (runtime/lockstep.h)
//                       up to the first MMIO access.
//   mvp-boot run [--until main|none] [--mmio N] [--log FILE]
//                       E0b items 7 and 8: boot with the IPL environment
//                       (runtime/boot.h) and the hardware model (runtime/hw.h).
//                       Prints the calls __start makes; logs every call from game
//                       or EA code into the SDK and runtime libraries (K1's set)
//                       by name to FILE (default sdk_calls.log, in the current
//                       directory) and stops at a call into an SDK function that
//                       has no name yet, printing its address (input for K1).
//
// Needs the disc (MVP_DISC) and a build with the translated code. Prints register
// values, names and addresses only; the log stays under build/ (only its hash may
// be committed).
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include "common/bytes.h"
#include "common/file.h"
#include "common/sha1.h"
#include "ppc/isa.h"
#include "runtime/boot.h"
#include "runtime/hle.h"
#include "runtime/hw.h"
#include "runtime/lockstep.h"
#include "runtime/sdk_names.h"
#include "runtime/sys_hooks.h"
#include "translator/program.h"
#include "translator/units.h"

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
  const xlat::UnitMap* units = nullptr;
  u32 start_fn = 0, stop_at = 0;
  std::uint64_t events = 0, max_events = 20000000;
  std::string log;  // one line per SDK boundary call
  std::uint64_t sdk_calls = 0;
  std::map<std::string, std::uint64_t> per_function;
  std::vector<std::string> first_order;

  std::string name(u32 a) const {
    const xlat::Symbol* s = cfg->index.containing(a);
    if (!s) return "?";
    if (s->name.rfind("fn_", 0) == 0)
      if (const char* alias = sdk_alias(s->address)) return alias;
    return s->name;
  }
  bool named(u32 a) const {
    const xlat::Symbol* s = cfg->index.at(a);
    return s && (s->name.rfind("fn_", 0) != 0 || sdk_alias(a));
  }
};
RunTrace* g_trace = nullptr;

void trace_hook(ppc::Cpu& c, u32 addr) {
  RunTrace& t = *g_trace;
  ++t.events;
  u32 call_site = c.lr - 4;
  const xlat::Symbol* caller = t.cfg->index.containing(call_site);
  if (caller && caller->address == t.start_fn)
    std::printf("  event %llu: __start (lr 0x%08X) calls %s (0x%08X)\n", static_cast<unsigned long long>(t.events),
                c.lr, t.name(addr).c_str(), addr);
  // An SDK boundary call: game or EA code (or crt0) calling into the runtime libraries.
  // LR names the call site only when the word there is a call to this entry (a
  // direct bl to it, or an indirect call); otherwise this entry was reached by a
  // tail call further down the chain (PCinit's `b` into its body, for example).
  bool direct = false;
  if (const u8* p = c.mem->host(call_site)) {
    ppc::Insn w{be32(p)};
    ppc::Op op = ppc::decode(w.w);
    if (op == ppc::Op::b && w.lk()) direct = (w.aa() ? static_cast<u32>(w.li()) : call_site + static_cast<u32>(w.li())) == addr;
    else if ((op == ppc::Op::bclr || op == ppc::Op::bcctr) && w.lk()) direct = true;
  }
  if (direct && t.units->is_runtime(addr) && !t.units->is_runtime(call_site)) {
    if (!t.named(addr)) {
      char b[160];
      std::snprintf(b, sizeof b, "call into unnamed SDK function 0x%08X (%s, unit %s) from 0x%08X (%s)", addr,
                    t.name(addr).c_str(), t.units->unit_at(addr).c_str(), call_site, t.name(call_site).c_str());
      throw StopRun{b};
    }
    std::string callee = t.name(addr);
    ++t.sdk_calls;
    if (t.per_function[callee]++ == 0) t.first_order.push_back(callee);
    t.log += callee + " <- " + t.name(call_site) + "\n";
  }
  if (addr == t.stop_at) throw StopRun{"reached " + t.name(addr)};
  if (t.events >= t.max_events) throw StopRun{"function-entry budget used up (--max-entries)"};
}

int run_boot(const xlat::Inputs& in, int argc, char** argv) {
  std::string until = "main", log_path = "sdk_calls.log";
  std::size_t mmio_lines = 40;
  std::uint64_t max_entries = 20000000, max_ticks = 2000000000ull;
  for (int k = 2; k + 1 < argc; ++k) {
    std::string a = argv[k];
    if (a == "--until") until = argv[k + 1];
    if (a == "--mmio") mmio_lines = static_cast<std::size_t>(std::atoi(argv[k + 1]));
    if (a == "--log") log_path = argv[k + 1];
    if (a == "--max-entries") max_entries = std::strtoull(argv[k + 1], nullptr, 10);
    if (a == "--max-ticks") max_ticks = std::strtoull(argv[k + 1], nullptr, 10);
  }
  auto splits = read_text(xlat::default_splits_path());
  if (!splits) {
    std::fprintf(stderr, "mvp-boot: cannot read %s\n", xlat::default_splits_path().c_str());
    return 1;
  }
  xlat::UnitMap units = xlat::UnitMap::parse(*splits);
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
  hooks.tick_limit = max_ticks;
  m.cpu().next_event = max_ticks;
  mvp_register_game();
  RunTrace t;
  t.cfg = &cfg;
  t.units = &units;
  t.start_fn = in.disc.dol.entry();
  t.max_events = max_entries;
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
  std::printf("SDK calls: %llu boundary calls to %zu functions, all named; OSReport lines %llu\n",
              static_cast<unsigned long long>(t.sdk_calls), t.per_function.size(),
              static_cast<unsigned long long>(g_report_count));
  for (const auto& n : t.first_order) std::printf("  %-28s %llu\n", n.c_str(), static_cast<unsigned long long>(t.per_function[n]));
  if (!write_file(log_path, t.log.data(), t.log.size())) std::fprintf(stderr, "mvp-boot: cannot write %s\n", log_path.c_str());
  std::printf("SDK call log: %s, %zu bytes, sha1 %s\n", log_path.c_str(), t.log.size(),
              Sha1::of(t.log.data(), t.log.size()).c_str());
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
  std::setvbuf(stdout, nullptr, _IOLBF, 1 << 16);
  std::string cmd = argc > 1 ? argv[1] : "";
  std::string err;
  auto in = xlat::load_inputs(xlat::default_disc_path(), xlat::default_symbols_path(), &err);
  if (!in) {
    std::fprintf(stderr, "mvp-boot: %s\n", err.c_str());
    return 77;
  }
  if (cmd == "lockstep") return lockstep(*in);
  if (cmd == "run") return run_boot(*in, argc, argv);
  std::fprintf(stderr, "usage: mvp-boot lockstep | run [--until main|none] [--mmio N] [--log FILE]\n");
  return 2;
}
