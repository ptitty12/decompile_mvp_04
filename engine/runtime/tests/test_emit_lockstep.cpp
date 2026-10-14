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

  std::uint64_t unwinds = g_unwinds;
  g_report = &capture;
  LockstepResult r = run_lockstep(ref, nat, cfg, 1);
  INFO(r.message);
  REQUIRE(r.pass);
  CHECK(r.stop.write);
  CHECK(r.stop.addr == 0xCC000000u);
  CHECK(r.events > 20);
  CHECK(g_unwinds == unwinds + 1);  // jumper's early return unwound main once

  // OSReport ran through the HLE (runtime/hle.h), formatted from guest varargs.
  CHECK(g_reported.find("x=42") == 0);
  auto want = xlat::synth::expected_results();
  for (std::size_t k = 0; k < want.size(); ++k) {
    u32 got = be32(nat.mem1() + (prog.results & 0x01FFFFFF) + 4 * k);
    CHECK_MESSAGE(got == want[k], "result ", k);
  }
}
