// Shared by test_digest (the semantics digest) and the WebAssembly emitter's
// digest test (runtime/tests/test_wasm_digest.cpp, E2d), which replays the same
// sequence through translated code: generators, hooks, the state hasher.
#pragma once

#include <vector>

#include "common/sha1.h"
#include "ppc/cpu.h"
#include "ppc/fp.h"
#include "ppc/isa.h"

namespace mvp::ppc::digest {

// The semantics digest (test_digest "sem"); native and WebAssembly builds, and
// the WebAssembly emitter's translated code, must all produce it.
inline constexpr const char* kSemDigest = "e4104538efe8ca13bf01d9f68d34ca0a1b3a5c35";

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
inline u64 fp_value(Rng& r) {
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

inline u32 gpr_value(Rng& r) {
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

inline std::vector<Op> plain_ops() {
  std::vector<Op> ops;
  for (u32 k = 1; k < static_cast<u32>(Op::count); ++k) ops.push_back(static_cast<Op>(k));
  return ops;
}


// A random CPU state as the semantics digest draws it (the order of draws is
// part of the digest).
inline void random_state(Rng& r, Cpu& c) {
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
}

}  // namespace mvp::ppc::digest
