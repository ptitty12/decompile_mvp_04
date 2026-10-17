// Cross-build exactness of the semantics library (E2; decisions FP1/FP2 in
// docs/engine/E0B_LOG.md). Every result is hashed and the hash must equal a
// constant. The native build (MSVC, clang) and the WebAssembly build (Emscripten,
// run under Node) both run this test, so they must compute every result bit for
// bit the same: NaN payloads, signed zeros, denormals, every rounding mode, NI,
// fused multiply-add, paired singles, quantization, and the integer, CR and XER
// effects of every opcode.
//
// - "sem": every non-branch opcode (execute_plain) with random spare fields, on
//   random CPU states whose FPRs are drawn from edge-case-heavy distributions,
//   over aliased RAM (every guest page maps one 64 KiB buffer, so any effective
//   address is valid and page-crossing accesses take the slow path);
// - "fp": the fp:: functions directly, in all four rounding modes, with and
//   without NI.
//
// If a semantics change is intended, the constants change with it: run the
// native build, take the printed digests, and confirm the WebAssembly build
// prints the same ones before updating them.
#include <doctest/doctest.h>

#include <memory>
#include <vector>

#include "common/sha1.h"
#include "ppc/fp.h"
#include "ppc/interp.h"
#include "ppc/isa.h"
#include "digest_gen.h"

using namespace mvp;
using namespace mvp::ppc;
using namespace mvp::ppc::digest;

namespace {

// The digest is the exact Gekko model's (Q4, F1: the engine's default is the fast model).
const bool g_exact = (fp::g_model = fp::Model::Exact, true);

constexpr const char* kFpDigest = "408b94ae7108349bd90bac160b82fc0f19c8f78e";

}  // namespace

TEST_CASE("semantics digest: every non-branch opcode on random states") {
  std::vector<u8> ram(Memory::kPageSize);
  auto mem = std::make_unique<Memory>();
  for (u8*& p : mem->page) p = ram.data();  // every page aliases one buffer
  DigestHooks hooks;
  Cpu c;
  c.mem = mem.get();
  c.hooks = &hooks;
  Rng r(0x5EED0E2D16E57ull);
  for (u8& b : ram) b = static_cast<u8>(r.next() >> 56);
  Hasher h;
  std::size_t executed = 0, ops_run = 0;
  for (Op op : plain_ops()) {
    const OpInfo& info = op_info(op);
    bool any = false;
    for (int n = 0; n < 1024; ++n) {
      random_state(r, c);
      u32 w = info.pattern | (r.u() & ~info.mask);
      if (decode(w) != op) continue;
      if (!execute_plain(c, op, Insn{w})) break;  // a branch or system instruction
      any = true;
      ++executed;
      h.put32(w);
      h.state(c);
    }
    if (any) ++ops_run;
  }
  h.sha.update(ram.data(), ram.size());
  std::string digest = Sha1::hex(h.sha.finish());
  MESSAGE("sem digest ", digest, " (", executed, " executions of ", ops_run, " opcodes)");
  CHECK(ops_run >= 200);
  CHECK(digest == kSemDigest);
}

TEST_CASE("fp digest: the integer softfloat in all rounding modes, with and without NI") {
  Rng r(0xF10A7D16E57ull);
  Hasher h;
  for (int n = 0; n < 60000; ++n) {
    u64 a = fp_value(r), b = fp_value(r), c = fp_value(r);
    u32 fpscr = static_cast<u32>(n & 3) | ((n & 4) ? fpscr::NI : 0u);
    for (fp::Prec p : {fp::Prec::Single, fp::Prec::Double}) {
      h.put64(fp::add(a, b, p, fpscr));
      h.put64(fp::sub(a, b, p, fpscr));
      h.put64(fp::mul(a, c, p, fpscr));
      h.put64(fp::div(a, b, p, fpscr));
      for (int m = 0; m < 4; ++m) h.put64(fp::madd(a, c, b, m & 1, m & 2, p, fpscr));
    }
    h.put64(fp::force25(c));
    h.put64(fp::round_to_single(a, fpscr));
    h.put64(fp::to_int32(a, false, fpscr));
    h.put64(fp::to_int32(a, true, fpscr));
    h.put64(fp::reciprocal_estimate(b, fpscr));
    h.put64(fp::rsqrt_estimate(b, fpscr));
    h.put32(fp::double_to_single(a));
    h.put32(fp::double_to_single_ftz(a));
    h.put64(fp::single_to_double(static_cast<u32>(b)));
    h.put64(fp::select(a, b, c));
    u32 type = r.u() & 7, scale = r.u() & 0x3F;
    h.put32(fp::quantize(a, type, scale));
    h.put64(fp::dequantize(r.u(), type, scale));
    h.flush();
  }
  std::string digest = Sha1::hex(h.sha.finish());
  MESSAGE("fp digest ", digest);
  CHECK(digest == kFpDigest);
}
