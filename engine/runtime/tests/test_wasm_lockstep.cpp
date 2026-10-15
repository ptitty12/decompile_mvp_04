// Data-free end-to-end test of the WebAssembly emitter (E2; Emscripten build
// only): the synthetic program (translator/tests/synth.h) is translated to a
// wasm module in-process, as the player's browser will translate the game,
// compiled and instantiated into the runtime, and run in lockstep with the
// reference interpreter. The checks are those of test_emit_lockstep (the C++
// emitter): same results, same unwinds, in-frame resumes, resume entries and
// interpreted instructions. Both helper modes run: inline code, and every
// non-branch instruction through the runtime. A second program checks the
// inline floating-point moves and conversions on edge-case values.
#include <doctest/doctest.h>

#include <cstdio>
#include <iterator>

#include "../../ppc/tests/encode.h"
#include "../../translator/tests/synth.h"
#include "common/bytes.h"
#include "runtime/hle.h"
#include "runtime/lockstep.h"
#include "runtime/wasm_host.h"
#include "translator/wasm_emit.h"

namespace {
std::string g_reported;
void capture(const std::string& s) { g_reported += s; }
}  // namespace

using namespace mvp;
using namespace mvp::rt;

// The programs start with MSR[FP] clear (MSR 0), so their first FPU instruction
// raises floating-point unavailable (E3a). The handler at 0x800 sets FP in SRR1
// and returns: the reference interpreter runs it in line, the translated side
// runs it to its rfi from the translated frame (rt.fp_unavailable) and goes on,
// as in test_emit_lockstep.
static void install_fp_handler(Machine& m) {
  using namespace mvp::ppc::enc;
  const u32 handler[] = {
      SPR(467, 3, 272),     // mtsprg0 r3
      SPR(339, 3, 27),      // mfsrr1 r3
      D(24, 3, 3, 0x2000),  // ori r3, r3, MSR[FP]
      SPR(467, 3, 27),      // mtsrr1 r3
      SPR(339, 3, 272),     // mfsprg0 r3
      X(19, 0, 0, 0, 50),   // rfi
  };
  for (std::size_t k = 0; k < std::size(handler); ++k) put_be32(m.mem1() + 0x800 + 4 * k, handler[k]);
  m.set_real_mode(true);  // the vector runs at its physical address
}

static void run_case(bool inline_ops) {
  xlat::synth::Program prog = xlat::synth::make();
  auto syms = xlat::SymbolTable::parse(prog.symbols);
  auto dol = vfs::Dol::parse(prog.dol);
  REQUIRE(dol);
  xlat::ProgramCfg cfg = xlat::build_cfg(*dol, syms);
  REQUIRE(cfg.errors == 0);

  xlat::WasmEmitOptions opt;
  const auto& table = hle_table();
  for (std::size_t k = 0; k < table.size(); ++k)
    opt.hle.push_back({table[k].name, table[k].address, static_cast<int>(k), table[k].kind == HleKind::Before});
  opt.precise_io = true;  // exact registers at the MMIO stop
  opt.inline_ops = inline_ops;
  xlat::WasmModule mod;
  std::string err;
  REQUIRE_MESSAGE(xlat::emit_wasm(cfg, opt, &mod, &err), err);
  MESSAGE(mod.bytes.size(), " bytes, ", mod.stats.instructions, " instructions (", mod.stats.inline_insns, " inline, ",
          mod.stats.helper_insns, " through the runtime, ", mod.stats.branch_insns, " control)");

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
  install_fp_handler(ref);
  install_fp_handler(nat);
  hn.run_handlers = true;
  WasmLoadStats ls;
  REQUIRE_MESSAGE(load_wasm_module(mod, &ls, &err), err);
  REQUIRE_FALSE(g_native.empty());

  std::uint64_t unwinds = g_unwinds, inframe = g_inframe_resumes, entries = g_resume_entries,
                interpreted = g_interpreted;
  g_reported.clear();
  g_report = &capture;
  LockstepResult r = run_lockstep(ref, nat, cfg, 1);
  INFO(r.message);
  REQUIRE(r.pass);
  CHECK(r.stop.write);
  CHECK(r.stop.addr == 0xCC000000u);
  CHECK(r.events > 20);
  CHECK(g_unwinds == unwinds + 2);
  CHECK(g_inframe_resumes == inframe + 2);
  CHECK(g_resume_entries == entries + 3);
  // main's two instructions after jumper's return, and the six of the handler.
  CHECK(g_interpreted == interpreted + 2 + 6);
  CHECK(hr.exceptions == 1);
  CHECK(hn.exceptions == 1);
  CHECK_FALSE(g_unwinding);
  CHECK(g_reported.find("x=42") == 0);
  auto want = xlat::synth::expected_results();
  for (std::size_t k = 0; k < want.size(); ++k) {
    u32 got = be32(nat.mem1() + (prog.results & 0x01FFFFFF) + 4 * k);
    CHECK_MESSAGE(got == want[k], "result ", k);
  }
}

TEST_CASE("wasm-emitted synthetic program matches the interpreter in lockstep (inline code)") { run_case(true); }

TEST_CASE("wasm-emitted synthetic program matches the interpreter in lockstep (runtime helpers only)") {
  run_case(false);
}

// The emitter's inline floating-point moves and conversions (lfs's single to
// double, stfs's double to single with its denormalizing and NaN cases, lfd,
// stfd, stfiwx, fneg, fnabs, ps_merge10) on edge-case values, against the
// interpreter: one loop over records of inputs, every result stored, and the
// whole of MEM1 and every register compared where both stop (an MMIO store).
namespace {

struct Rng {
  std::uint64_t s;
  std::uint64_t next() {
    s ^= s >> 12;
    s ^= s << 25;
    s ^= s >> 27;
    return s * 0x2545F4914F6CDD1Dull;
  }
};

struct FpProgram {
  std::vector<std::uint8_t> dol;
  std::string symbols;
};

FpProgram make_fp_program() {
  using namespace mvp::ppc::enc;
  constexpr u32 kText = 0x80003100, kIn = 0x80200000, kRecords = 96;
  const u32 singles[] = {0x00000000, 0x80000000, 0x3F800000, 0xBF800000, 0x00000001, 0x80000001, 0x007FFFFF,
                         0x00400000, 0x00800000, 0x7F7FFFFF, 0xFF7FFFFF, 0x7F800000, 0xFF800000, 0x7FC00000,
                         0xFFC00000, 0x7F800001, 0x7FBFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x34000000};
  const std::uint64_t doubles[] = {
      0x0000000000000000ull, 0x8000000000000000ull, 0x3FF0000000000000ull, 0x7FF0000000000000ull,
      0xFFF0000000000000ull, 0x7FF8000000000000ull, 0x7FF0000000000001ull, 0xFFF4000012345678ull,
      0x0000000000000001ull, 0x800FFFFFFFFFFFFFull, 0x3690000000000000ull, 0x36A0000000000000ull,
      0x36A8000000000000ull, 0x36B0000000000001ull, 0x3700000000000000ull, 0x37F0000000000000ull,
      0x3800000000000000ull, 0x380FFFFFFFFFFFFFull, 0x3810000000000000ull, 0x47EFFFFFE0000000ull,
      0x47EFFFFFFFFFFFFFull, 0x47F0000000000000ull, 0xB80FFFFFFFFFFFFFull, 0xC7EFFFFFF0000000ull};
  Rng r{0x5EEDF10A7ull};
  std::vector<u32> data;
  for (u32 k = 0; k < kRecords; ++k) {
    u32 s = k < std::size(singles) ? singles[k] : static_cast<u32>(r.next() >> 32);
    std::uint64_t d = k < std::size(doubles) ? doubles[k] : r.next();
    if (k >= std::size(doubles) && (k & 1)) {
      // Exponents around the single denormal and normal limits.
      std::uint64_t e = 860 + (r.next() % 50);
      d = (d & 0x800FFFFFFFFFFFFFull) | (e << 52);
    }
    data.push_back(s);
    data.push_back(0);
    data.push_back(static_cast<u32>(d >> 32));
    data.push_back(static_cast<u32>(d));
  }
  std::vector<u32> w = {
      D(15, 3, 0, 0x8020),   // lis r3, 0x8020 (inputs)
      D(15, 4, 0, 0x8030),   // lis r4, 0x8030 (results, plain RAM)
      D(14, 5, 0, kRecords), // li r5, records
      SPR(467, 5, 9),        // mtctr r5
      D(14, 6, 0, 12),       // li r6, 12
  };
  const u32 loop = kText + 4 * static_cast<u32>(w.size());
  for (u32 x : {D(48, 1, 3, 0),          // lfs f1, 0(r3)
                D(54, 1, 4, 0),          // stfd f1, 0(r4)
                D(50, 2, 3, 8),          // lfd f2, 8(r3)
                D(52, 2, 4, 8),          // stfs f2, 8(r4)
                X(31, 2, 4, 6, 983),     // stfiwx f2, r4, r6 (12)
                X(63, 3, 0, 2, 40),      // fneg f3, f2
                D(54, 3, 4, 16),         // stfd f3, 16(r4)
                X(63, 4, 0, 1, 136),     // fnabs f4, f1
                D(54, 4, 4, 24),         // stfd f4, 24(r4)
                X(4, 5, 1, 2, 592),      // ps_merge10 f5, f1, f2
                PSQ(60, 5, 4, 32, 0, 0), // psq_st f5, 32(r4), 0, qr0
                D(14, 3, 3, 16),         // addi r3, r3, 16
                D(14, 4, 4, 48)})        // addi r4, r4, 48
    w.push_back(x);
  w.push_back(B(16, 0, static_cast<s32>(loop - (kText + 4 * static_cast<u32>(w.size())))));  // bdnz loop
  w.push_back(D(15, 9, 0, static_cast<s32>(static_cast<std::int16_t>(0xCC00))));  // lis r9, 0xCC00
  w.push_back(D(36, 0, 9, 0));            // stw r0, 0(r9): MMIO, the stop
  w.push_back(X(19, 20, 0, 0, 16));       // blr
  const std::size_t text_bytes = 4 * w.size(), data_bytes = 4 * data.size();
  std::vector<std::uint8_t> d(0x100 + text_bytes + data_bytes, 0);
  auto set = [&](int slot, u32 off, u32 addr, u32 size) {
    put_be32(&d[4 * static_cast<std::size_t>(slot)], off);
    put_be32(&d[0x48 + 4 * static_cast<std::size_t>(slot)], addr);
    put_be32(&d[0x90 + 4 * static_cast<std::size_t>(slot)], size);
  };
  set(0, 0x100, kText, static_cast<u32>(text_bytes));
  set(7, static_cast<u32>(0x100 + text_bytes), kIn, static_cast<u32>(data_bytes));
  put_be32(&d[0xE0], kText);
  for (std::size_t k = 0; k < w.size(); ++k) put_be32(&d[0x100 + 4 * k], w[k]);
  for (std::size_t k = 0; k < data.size(); ++k) put_be32(&d[0x100 + text_bytes + 4 * k], data[k]);
  char line[128];
  std::snprintf(line, sizeof line, "main = .text:0x%08X; // type:function size:0x%zX\n", kText, text_bytes);
  return FpProgram{std::move(d), line};
}

}  // namespace

TEST_CASE("wasm-emitted floating-point moves and conversions match the interpreter on edge cases") {
  FpProgram prog = make_fp_program();
  auto syms = xlat::SymbolTable::parse(prog.symbols);
  auto dol = vfs::Dol::parse(prog.dol);
  REQUIRE(dol);
  xlat::ProgramCfg cfg = xlat::build_cfg(*dol, syms);
  REQUIRE(cfg.errors == 0);
  xlat::WasmEmitOptions opt;
  opt.precise_io = true;
  xlat::WasmModule mod;
  std::string err;
  REQUIRE_MESSAGE(xlat::emit_wasm(cfg, opt, &mod, &err), err);
  CHECK(mod.stats.helper_insns == 0);  // psq_st too is inline since E2d

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
  install_fp_handler(ref);
  install_fp_handler(nat);
  hn.run_handlers = true;
  WasmLoadStats ls;
  REQUIRE_MESSAGE(load_wasm_module(mod, &ls, &err), err);
  LockstepResult r = run_lockstep(ref, nat, cfg, 1);
  INFO(r.message);
  REQUIRE(r.pass);
  CHECK(r.stop.addr == 0xCC000000u);
  CHECK(hr.exceptions == 1);  // the first lfs; MSR[FP] stays set after
  CHECK(hn.exceptions == 1);
  // Spot checks against the conversion rules (fp.h): lfs of the smallest
  // single denormal, stfs of a NaN keeps the top fraction bits.
  CHECK(be64(nat.mem1() + 0x300000 + 48 * 4) == 0x36A0000000000000ull);
  CHECK(be32(nat.mem1() + 0x300000 + 48 * 7 + 8) == 0xFFA00000u);
}
