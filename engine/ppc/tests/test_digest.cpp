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

using namespace mvp;
using namespace mvp::ppc;

namespace {

constexpr const char* kSemDigest = "e4104538efe8ca13bf01d9f68d34ca0a1b3a5c35";
constexpr const char* kFpDigest = "408b94ae7108349bd90bac160b82fc0f19c8f78e";

// Deterministic generator (xorshift64*): the same sequence on every build.
struct Rng {
  u64 s;
  explicit Rng(u64 seed) : s(seed) {}
  u64 next() {
    s ^= s >> 12;
    s ^= s << 25;
    s ^= s >> 27;
    return s * 0x2545F4914F6CDD1Dull;
  }
  u32 u() { return static_cast<u32>(next() >> 32); }
};

constexpr u64 kSpecials[] = {
    0x0000000000000000ull, 0x8000000000000000ull,  // +-0
    0x7FF0000000000000ull, 0xFFF0000000000000ull,  // +-inf
    0x7FF8000000000000ull, 0xFFF8000000000000ull,  // default QNaNs
    0x7FF0000000000001ull, 0x7FF4000000000000ull,  // SNaNs
    0x7FFFFFFFFFFFFFFFull, 0xFFF8000012345678ull,  // QNaNs with payloads
    0x0000000000000001ull, 0x800FFFFFFFFFFFFFull,  // double denormals
    0x0010000000000000ull, 0x7FEFFFFFFFFFFFFFull,  // smallest / largest normal double
    0x3810000000000000ull, 0x380FFFFFFFFFFFFFull,  // 2^-126 and just below (single normal limit)
    0x36A0000000000000ull, 0x369FFFFFFFFFFFFFull,  // 2^-149 and just below (single denormal limit)
    0x47EFFFFFE0000000ull, 0x47EFFFFFF0000000ull,  // FLT_MAX and its rounding boundary
    0x3FF0000000000000ull, 0xBFF0000000000000ull,  // +-1
    0x3FF0000010000000ull, 0x3FF0000008000000ull,  // single ties (round to even), force25 ties
    0x41DFFFFFFFC00000ull, 0xC1E0000000000000ull,  // 2^31-1, -2^31 (fctiw limits)
    0x41E0000000000000ull, 0x3FE0000000000000ull,  // 2^31, 0.5
};

// An FPR half from an edge-case-heavy distribution.
u64 fp_value(Rng& r) {
  u64 k = r.next();
  u64 sign = (k >> 63) << 63;
  switch (k % 10) {
    case 0: return kSpecials[(k >> 8) % (sizeof kSpecials / sizeof kSpecials[0])];
    case 1: return r.next();                              // anything, NaN payloads included
    case 2: return fp::single_to_double(r.u());           // single-representable
    case 3: return sign | (r.next() & fp::kFracMask);     // double denormal
    case 4: {                                             // around the single denormal range
      u64 e = 1023 - 155 + (r.next() % 36);
      return sign | (e << 52) | (r.next() & fp::kFracMask);
    }
    case 5: {                                             // around the single overflow range
      u64 e = 1023 + 120 + (r.next() % 12);
      return sign | (e << 52) | (r.next() & fp::kFracMask);
    }
    default: {                                            // moderate, sometimes few significant bits
      u64 e = 1023 - 40 + (r.next() % 81);
      u64 frac = r.next() & fp::kFracMask;
      if ((k >> 20) % 3 == 0) frac &= ~((1ull << ((k >> 24) % 52)) - 1);
      return sign | (e << 52) | frac;
    }
  }
}

u32 gpr_value(Rng& r) {
  u64 k = r.next();
  switch (k % 8) {
    case 0: return 0;
    case 1: return 0x80000000u;
    case 2: return 0x7FFFFFFFu;
    case 3: return 0xFFFFFFFFu;
    case 4: return static_cast<u32>((k >> 8) & 0x3F);  // small (shift counts, indices)
    default: return r.u();
  }
}

// Deterministic hooks: the time base advances by a fixed step per read.
struct DigestHooks : Hooks {
  u64 tb = 0x0123456789ull;
  u32 dec = 0;
  u64 time_base(Cpu&) override { return tb += 977; }
  void set_time_base(Cpu&, u64 v) override { tb = v; }
  u32 decrementer(Cpu&) override { return dec; }
  void set_decrementer(Cpu&, u32 v) override { dec = v; }
  void msr_changed(Cpu&, u32) override {}
  void icbi(Cpu&, u32) override {}
  void system_call(Cpu&) override {}
};

// Little-endian serialization of the architectural state, then hashed.
struct Hasher {
  Sha1 sha;
  std::vector<u8> buf;
  void put32(u32 v) {
    for (int k = 0; k < 4; ++k) buf.push_back(static_cast<u8>(v >> (8 * k)));
  }
  void put64(u64 v) {
    put32(static_cast<u32>(v));
    put32(static_cast<u32>(v >> 32));
  }
  void flush() {
    sha.update(buf.data(), buf.size());
    buf.clear();
  }
  void state(const Cpu& c) {
    for (u32 v : c.gpr) put32(v);
    for (const Fpr& f : c.fpr) {
      put64(f.ps0);
      put64(f.ps1);
    }
    put32(c.cr);
    put32(c.lr);
    put32(c.ctr);
    put32(c.xer());
    put32(c.fpscr);
    put32(c.msr);
    put32(c.reserve);
    put32(c.reserve_addr);
    for (u32 v : c.sr) put32(v);
    for (u32 k = 0; k < 8; ++k) put32(c.spr[spr::GQR0 + k]);
    put32(c.spr[spr::SRR0]);
    put32(c.spr[spr::SRR1]);
    flush();
  }
};

std::vector<Op> plain_ops() {
  std::vector<Op> ops;
  for (u32 k = 1; k < static_cast<u32>(Op::count); ++k) ops.push_back(static_cast<Op>(k));
  return ops;
}

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
      for (u32& v : c.gpr) v = gpr_value(r);
      for (Fpr& f : c.fpr) {
        f.ps0 = fp_value(r);
        f.ps1 = (r.next() & 3) ? fp_value(r) : fp::single_to_double(r.u());
      }
      c.cr = r.u();
      c.lr = r.u();
      c.ctr = r.u();
      c.set_xer(r.u());
      // Rounding mode and NI in every combination; other FPSCR bits random.
      c.fpscr = r.u();
      c.msr = r.u();
      for (u32 k = 0; k < 8; ++k) c.spr[spr::GQR0 + k] = r.u() & 0x3F073F07u;
      c.reserve = r.u() & 1;
      c.reserve_addr = r.u();
      c.pc = 0x80001000u;
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
