// Data-free end-to-end test of the C++ emitter and the native runtime: the
// synthetic program (translator/tests/synth.h) is translated at build time; here
// the translated code runs against the reference interpreter in lockstep, and
// the results it stores must be the expected ones.
#include <doctest/doctest.h>

#include "../../translator/tests/synth.h"
#include "common/bytes.h"
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
  // Only main's two instructions after jumper's return (a store, the bl) ran in
  // the interpreter.
  CHECK(g_interpreted == interpreted + 2);
  CHECK_FALSE(g_unwinding);

  // OSReport ran through the HLE (runtime/hle.h), formatted from guest varargs.
  CHECK(g_reported.find("x=42") == 0);
  auto want = xlat::synth::expected_results();
  for (std::size_t k = 0; k < want.size(); ++k) {
    u32 got = be32(nat.mem1() + (prog.results & 0x01FFFFFF) + 4 * k);
    CHECK_MESSAGE(got == want[k], "result ", k);
  }
}
