// Data-free end-to-end test of the C++ emitter and the native runtime: the
// synthetic program (translator/tests/synth.h) is translated at build time; here
// the translated code runs against the reference interpreter in lockstep, and
// the results it stores must be the expected ones. Then it runs again with an
// input source that stops the run at every frame poll (poll_stop.h, E5c).
#include <doctest/doctest.h>

#include "../../ppc/tests/encode.h"
#include "../../translator/tests/synth.h"
#include "common/bytes.h"
#include "poll_stop.h"
#include "runtime/hle.h"
#include "runtime/lockstep.h"

void mvp_register_game();

namespace {
std::string g_reported;
void capture(const std::string& s) { g_reported += s; }
}  // namespace

using namespace mvp;
using namespace mvp::rt;

TEST_CASE("translated synthetic program matches the interpreter in lockstep") {
  xlat::synth::Program prog = xlat::synth::make();
  auto syms = xlat::SymbolTable::parse(prog.symbols);
  auto dol = vfs::Dol::parse(prog.dol);
  REQUIRE(dol);
  xlat::ProgramCfg cfg = xlat::build_cfg(*dol, syms);
  REQUIRE(cfg.errors == 0);
  CHECK(cfg.secondary_entries == 1);
  CHECK(cfg.falls_into_next == 1);
  CHECK(cfg.jump_tables == 1);

  Machine ref, nat;
  FixedHooks hr, hn;
  StopIo ir, in;
  ir.cpu = &ref.cpu();
  in.cpu = &nat.cpu();
  ref.memory().io = &ir;
  nat.memory().io = &in;
  ref.cpu().hooks = &hr;
  nat.cpu().hooks = &hn;
  ref.load_dol(*dol);
  nat.load_dol(*dol);
  // The program starts with MSR[FP] clear (MSR 0), so its first FPU instruction
  // (in fpwork) raises floating-point unavailable. The handler at 0x800 sets FP in
  // SRR1 and returns: the reference interpreter runs it in line, the native side
  // runs it to its rfi from the translated frame (rt::fp_unavailable) and goes on.
  {
    using namespace mvp::ppc::enc;
    const u32 handler[] = {
        SPR(467, 3, 272),       // mtsprg0 r3
        SPR(339, 3, 27),        // mfsrr1 r3
        D(24, 3, 3, 0x2000),    // ori r3, r3, MSR[FP]
        SPR(467, 3, 27),        // mtsrr1 r3
        SPR(339, 3, 272),       // mfsprg0 r3
        X(19, 0, 0, 0, 50),     // rfi
    };
    for (Machine* m : {&ref, &nat}) {
      for (std::size_t k = 0; k < std::size(handler); ++k) put_be32(m->mem1() + 0x800 + 4 * k, handler[k]);
      m->set_real_mode(true);  // the vector runs at its physical address
    }
  }
  hn.run_handlers = true;
  mvp_register_game();
  REQUIRE_FALSE(g_native.empty());

  std::uint64_t unwinds = g_unwinds, inframe = g_inframe_resumes, entries = g_resume_entries,
                interpreted = g_interpreted;
  g_report = &capture;
  LockstepResult r = run_lockstep(ref, nat, cfg, 1);
  INFO(r.message);
  REQUIRE(r.pass);
  CHECK(r.stop.write);
  CHECK(r.stop.addr == 0xCC000000u);
  CHECK(r.events > 20);
  // Unwinds to the top: b_fn's rfi into a_fn's finished frame, and jumper's
  // early return (main lands between resume labels).
  CHECK(g_unwinds == unwinds + 2);
  // yield_self reloads its own context (the same stack frame), and rec(1) loads
  // rec(2)'s: both end in a live frame, without reaching the dispatcher.
  CHECK(g_inframe_resumes == inframe + 2);
  // The dispatcher re-enters a_fn after b_fn's unwind, then main where a_fn
  // returns, and main again where leaf returns after jumper's.
  CHECK(g_resume_entries == entries + 3);
  // Only main's two instructions after jumper's return (a store, the bl) and the
  // six of the floating-point unavailable handler ran in the interpreter.
  CHECK(g_interpreted == interpreted + 2 + 6);
  CHECK(hr.exceptions == 1);
  CHECK(hn.exceptions == 1);
  CHECK_FALSE(g_unwinding);

  // OSReport ran through the HLE (runtime/hle.h), formatted from guest varargs.
  CHECK(g_reported.find("x=42") == 0);
  auto want = xlat::synth::expected_results();
  for (std::size_t k = 0; k < want.size(); ++k) {
    u32 got = be32(nat.mem1() + (prog.results & 0x01FFFFFF) + 4 * k);
    CHECK_MESSAGE(got == want[k], "result ", k);
  }
}

// E5c: the frame poll can stop the run before it consumes anything (netplay
// waits there), even when nothing else would stop the run between two polls,
// and the guest then runs exactly as without the stops.
TEST_CASE("a frame poll that must wait for its input stops the run there, invisibly") {
  xlat::synth::Program prog = xlat::synth::make();
  auto dol = vfs::Dol::parse(prog.dol);
  REQUIRE(dol);
  mvp_register_game();
  poll_stop::Outcome plain = poll_stop::run(*dol, prog.results, false);
  poll_stop::Outcome stopped = poll_stop::run(*dol, prog.results, true);
  CHECK(plain.runs == 0);
  CHECK(plain.frames == 4);
  CHECK(plain.results == xlat::synth::expected_results());
  CHECK(stopped.stops == 4);
  CHECK(stopped.runs == 4);  // rt::run() returned once at each poll
  CHECK(stopped.unwinds == plain.unwinds + 4);
  CHECK(stopped.frames == 4);
  CHECK(stopped.polls == plain.polls);  // each poll once, at the same instruction count, with its own input
  CHECK(stopped.ticks == plain.ticks);
  CHECK(stopped.regs == plain.regs);
  CHECK(stopped.results == plain.results);
  CHECK_FALSE(g_unwinding);
}
