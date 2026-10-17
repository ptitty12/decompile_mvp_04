// Exactness of the WebAssembly emitter's inline code (E2d; Emscripten only),
// against the semantics library (decisions FP1/FP2, docs/engine/E0B_LOG.md).
//
// - "digest": test_digest's semantics digest replayed through translated code.
//   Every word that digest executes becomes a function `word; blr`; the same
//   random states (ppc/tests/digest_gen.h) run through the translated module
//   and, alongside, through the interpreter. Every execution's whole state and
//   RAM must equal the interpreter's, and the hash must be the constant that the
//   native and WebAssembly builds of test_digest print (kSemDigest).
// - "fp": the instructions the emitter computes inline with a fast path and a
//   runtime fallback (floating-point arithmetic, paired singles, quantized loads
//   and stores, lmw/stmw, SPR moves) on millions of states built to hit the
//   fast path's edges: round to nearest with NI (the game's FPSCR) most of the
//   time, singles, integers, sums and fused products that land exactly on, or
//   within one double ulp of, a midpoint between two singles, the 2^-126 flush
//   boundary, overflow, NaNs, infinities, subnormals, every GQR type and scale,
//   page-crossing accesses. Translated code against the interpreter, state and
//   RAM after every execution.
#include <doctest/doctest.h>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

#include "../../ppc/tests/digest_gen.h"
#include "common/bytes.h"
#include "ppc/fp.h"
#include "ppc/interp.h"
#include "runtime/native.h"
#include "runtime/wasm_host.h"
#include "translator/cfg.h"
#include "translator/wasm_emit.h"
#include "vfs/dol.h"

using namespace mvp;
using namespace mvp::ppc;
using namespace mvp::ppc::digest;

namespace {

constexpr u32 kText = 0x80003100;
constexpr u32 kBlr = 0x4E800020;

// Instructions execute_plain() does not run (branches and system instructions).
bool is_plain(Op op) {
  switch (op) {
    case Op::b: case Op::bc: case Op::bcctr: case Op::bclr: case Op::sc: case Op::rfi: case Op::tw: case Op::twi:
    case Op::eciwx: case Op::ecowx: case Op::invalid:
      return false;
    default:
      return true;
  }
}

// Translates `word; blr` for every word into one module, loads it, and returns
// each function (rt::g_native).
std::vector<rt::GuestFn> translate(const std::vector<u32>& words, std::size_t* module_bytes, bool fp_exact = true) {
  std::vector<u32> text;
  text.reserve(2 * words.size());
  std::string syms;
  syms.reserve(64 * words.size());
  char line[96];
  for (std::size_t k = 0; k < words.size(); ++k) {
    text.push_back(words[k]);
    text.push_back(kBlr);
    u32 a = kText + 8 * static_cast<u32>(k);
    std::snprintf(line, sizeof line, "f_%08X = .text:0x%08X; // type:function size:0x8\n", a, a);
    syms += line;
  }
  std::vector<u8> dol(0x100 + 4 * text.size(), 0);
  put_be32(&dol[0], 0x100);
  put_be32(&dol[0x48], kText);
  put_be32(&dol[0x90], static_cast<u32>(4 * text.size()));
  put_be32(&dol[0xE0], kText);
  for (std::size_t k = 0; k < text.size(); ++k) put_be32(&dol[0x100 + 4 * k], text[k]);
  auto parsed = vfs::Dol::parse(dol);
  REQUIRE(parsed);
  static std::vector<std::unique_ptr<vfs::Dol>> keep;  // the CFG points into its DOL and symbols
  static std::vector<std::unique_ptr<xlat::SymbolTable>> keep_syms;
  keep.push_back(std::make_unique<vfs::Dol>(std::move(*parsed)));
  keep_syms.push_back(std::make_unique<xlat::SymbolTable>(xlat::SymbolTable::parse(syms)));
  xlat::ProgramCfg cfg = xlat::build_cfg(*keep.back(), *keep_syms.back());
  REQUIRE(cfg.errors == 0);
  xlat::WasmEmitOptions opt;
  opt.fpu_checks = false;  // execute_plain(), the reference, has no MSR[FP] check
  opt.fp_exact = fp_exact;  // Q4: the emitter's model must be the interpreter's (fp::g_model)
  xlat::WasmModule mod;
  std::string err;
  REQUIRE_MESSAGE(xlat::emit_wasm(cfg, opt, &mod, &err), err);
  if (module_bytes) *module_bytes = mod.bytes.size();
  rt::WasmLoadStats ls;
  REQUIRE_MESSAGE(rt::load_wasm_module(mod, &ls, &err), err);
  std::vector<rt::GuestFn> fns(words.size());
  for (std::size_t k = 0; k < words.size(); ++k) {
    fns[k] = rt::g_native.find(kText + 8 * static_cast<u32>(k));
    REQUIRE(fns[k]);
  }
  return fns;
}

// Runs one translated `word; blr` on c (which must not expect an unwind).
void run_translated(rt::GuestFn fn, Cpu& c, u32 word_addr) {
  c.next_event = ~0ull;
  c.lr = c.lr;  // blr returns to LR; nothing reads c.pc afterwards
  (void)word_addr;
  fn(c);
  REQUIRE_FALSE(rt::g_unwinding);
}

// The first architectural difference between two states, or "".
std::string diff(const Cpu& a, const Cpu& b) {
  char m[160];
  for (int k = 0; k < 32; ++k)
    if (a.gpr[k] != b.gpr[k]) {
      std::snprintf(m, sizeof m, "r%d %08X vs %08X", k, a.gpr[k], b.gpr[k]);
      return m;
    }
  for (int k = 0; k < 32; ++k)
    if (a.fpr[k].ps0 != b.fpr[k].ps0 || a.fpr[k].ps1 != b.fpr[k].ps1) {
      std::snprintf(m, sizeof m, "f%d %016llX:%016llX vs %016llX:%016llX", k,
                    static_cast<unsigned long long>(a.fpr[k].ps0), static_cast<unsigned long long>(a.fpr[k].ps1),
                    static_cast<unsigned long long>(b.fpr[k].ps0), static_cast<unsigned long long>(b.fpr[k].ps1));
      return m;
    }
  auto u = [&](const char* n, u32 x, u32 y) -> std::string {
    if (x == y) return "";
    std::snprintf(m, sizeof m, "%s %08X vs %08X", n, x, y);
    return m;
  };
  for (auto s : {u("cr", a.cr, b.cr), u("lr", a.lr, b.lr), u("ctr", a.ctr, b.ctr), u("xer", a.xer(), b.xer()),
                 u("fpscr", a.fpscr, b.fpscr), u("msr", a.msr, b.msr), u("reserve", a.reserve, b.reserve),
                 u("reserve_addr", a.reserve_addr, b.reserve_addr)})
    if (!s.empty()) return s;
  for (int k = 0; k < 16; ++k)
    if (a.sr[k] != b.sr[k]) return u("sr", a.sr[k], b.sr[k]);
  for (int k = 0; k < 1024; ++k)
    if (a.spr[k] != b.spr[k]) {
      std::snprintf(m, sizeof m, "spr%d %08X vs %08X", k, a.spr[k], b.spr[k]);
      return m;
    }
  return "";
}

// Two machines over aliased RAM (every guest page maps one 64 KiB buffer, as in
// test_digest): `ref` runs the interpreter, `wasm` the translated code.
struct Pair {
  std::vector<u8> ram_ref, ram_wasm;
  std::unique_ptr<Memory> mem_ref, mem_wasm;
  DigestHooks hooks_ref, hooks_wasm;
  Cpu ref, wasm;
  Pair() : ram_ref(Memory::kPageSize), ram_wasm(Memory::kPageSize), mem_ref(new Memory), mem_wasm(new Memory) {
    for (u8*& p : mem_ref->page) p = ram_ref.data();
    for (u8*& p : mem_wasm->page) p = ram_wasm.data();
    ref.mem = mem_ref.get();
    wasm.mem = mem_wasm.get();
    ref.hooks = &hooks_ref;
    wasm.hooks = &hooks_wasm;
  }
  // Copies ref's architectural state to wasm (the memory and hooks stay their own).
  void sync() {
    Memory* m = wasm.mem;
    Hooks* h = wasm.hooks;
    wasm = ref;
    wasm.mem = m;
    wasm.hooks = h;
  }
};

std::string op_word(u32 w) {
  char b[64];
  std::snprintf(b, sizeof b, "%s (0x%08X)", op_name(decode(w)), w);
  return b;
}

}  // namespace

TEST_CASE("semantics digest through the WebAssembly emitter's translated code") {
  ppc::fp::g_model = ppc::fp::Model::Exact;  // the digest is the exact model's
  // Plan: replay test_digest's sequence to collect the words it executes.
  std::vector<u32> words;
  {
    Pair p;
    Rng r(0x5EED0E2D16E57ull);
    for (u8& b : p.ram_ref) b = static_cast<u8>(r.next() >> 56);
    for (Op op : plain_ops()) {
      const OpInfo& info = op_info(op);
      for (int n = 0; n < 1024; ++n) {
        random_state(r, p.ref);
        u32 w = info.pattern | (r.u() & ~info.mask);
        if (decode(w) != op) continue;
        if (!is_plain(op)) break;
        words.push_back(w);
      }
    }
  }
  std::size_t bytes = 0;
  std::vector<rt::GuestFn> fns = translate(words, &bytes);
  MESSAGE(words.size(), " words translated into a ", bytes, "-byte module");

  Pair p;
  Rng r(0x5EED0E2D16E57ull);
  for (u8& b : p.ram_ref) b = static_cast<u8>(r.next() >> 56);
  p.ram_wasm = p.ram_ref;
  Hasher h;
  std::size_t k = 0, differences = 0;
  std::string first;
  for (Op op : plain_ops()) {
    const OpInfo& info = op_info(op);
    for (int n = 0; n < 1024; ++n) {
      random_state(r, p.ref);
      u32 w = info.pattern | (r.u() & ~info.mask);
      if (decode(w) != op) continue;
      if (!is_plain(op)) break;
      REQUIRE(k < words.size());
      REQUIRE(words[k] == w);
      p.sync();
      execute_plain(p.ref, op, Insn{w});
      run_translated(fns[k], p.wasm, kText + 8 * static_cast<u32>(k));
      ++k;
      std::string d = diff(p.ref, p.wasm);
      if (d.empty() && p.ram_ref != p.ram_wasm) d = "RAM";
      if (!d.empty()) {
        if (!differences) first = op_word(w) + ": " + d;
        ++differences;
        p.ram_wasm = p.ram_ref;
      }
      h.put32(w);
      h.state(p.wasm);
    }
  }
  h.sha.update(p.ram_wasm.data(), p.ram_wasm.size());
  std::string digest = Sha1::hex(h.sha.finish());
  MESSAGE("translated-code digest ", digest, " (", k, " executions)");
  CHECK_MESSAGE(differences == 0, differences, " executions differ; first: ", first);
  CHECK(k == words.size());
  CHECK(digest == kSemDigest);
}

namespace {

// FPR values for the inline fast paths' edges.
u64 fz_value(Rng& r) {
  u64 k = r.next();
  u64 sign = (k >> 63) << 63;
  switch (k % 14) {
    case 0: case 1: return fp_value(r);
    case 2: case 3: case 4: {  // a normal single
      u64 e = 1023 - 30 + (r.next() % 61);
      return sign | (e << 52) | (r.next() & 0x000FFFFFE0000000ull);
    }
    case 5: {  // small integers (pixels, coefficients)
      long v = static_cast<long>(r.next() % 600) - 300;
      double d = static_cast<double>(v);
      u64 b;
      std::memcpy(&b, &d, 8);
      return b;
    }
    case 6: {  // singles around 2^-126 (normal and denormal)
      u64 e = 1023 - 126 - 24 + (r.next() % 28);
      return sign | (e << 52) | (r.next() & 0x000FFFFFE0000000ull);
    }
    case 7: {  // singles near FLT_MAX
      u64 e = 1023 + 124 + (r.next() % 4);
      return sign | (e << 52) | (r.next() & 0x000FFFFFE0000000ull);
    }
    case 8: return 0x4330000000000000ull | (r.next() & 0xFFFFFFFFull);  // 2^52 + n (int to float)
    case 9: return 0x4330000080000000ull;
    case 10: {  // doubles with few significant bits
      u64 e = 1023 - 20 + (r.next() % 41);
      u64 frac = r.next() & fp::kFracMask;
      frac &= ~((1ull << (r.next() % 53)) - 1);
      return sign | (e << 52) | frac;
    }
    default: {  // any moderate double
      u64 e = 1023 - 60 + (r.next() % 121);
      return sign | (e << 52) | (r.next() & fp::kFracMask);
    }
  }
}

double as_d(u64 b) {
  double d;
  std::memcpy(&d, &b, 8);
  return d;
}
u64 as_b(double d) {
  u64 b;
  std::memcpy(&b, &d, 8);
  return b;
}

// A midpoint between two adjacent normal singles, as a double.
u64 midpoint(Rng& r, u64 sign) {
  u64 e = 1023 - 40 + (r.next() % 81);
  if (r.next() % 8 == 0) e = 1023 - 126 + (r.next() % 3);  // near the flush boundary
  if (r.next() % 8 == 0) e = 1023 + 127;                   // FLT_MAX's binade (the overflow midpoint too)
  return sign | (e << 52) | (r.next() & 0x000FFFFFE0000000ull) | 0x10000000ull;
}

// Rewrites the operands of the instruction in `c` so that its exact result is a
// single midpoint, or within less than half a double ulp of one (which rounding
// to double moves onto the midpoint), or exactly 2^-126.
void construct(Rng& r, Cpu& c, Op op, Insn i) {
  const u32 ra = i.rA(), rb = i.rB(), rc = i.rC();
  auto tiny = [&](u64 m) -> u64 {  // nonzero, below half a double ulp of m (or exactly half)
    u64 e = (m >> 52) & 0x7FF;
    u64 below = 54 + r.next() % 20;
    if (r.next() % 6 == 0) below = 54;  // exactly half an ulp: a double-rounding tie
    u64 s = (r.next() & 1) << 63;
    return e > below ? s | ((e - below) << 52) | ((r.next() % 3 == 0) ? (r.next() & fp::kFracMask) : 0) : s;
  };
  for (int half = 0; half < 2; ++half) {
    auto F = [&](u32 reg) -> u64& { return half ? c.fpr[reg].ps1 : c.fpr[reg].ps0; };
    u64 sign = (r.next() & 1) << 63;
    u64 m = midpoint(r, sign);
    if (r.next() % 10 == 0) m = sign | 0x3810000000000000ull;  // 2^-126
    switch (op) {
      case Op::fadds: case Op::fsubs: case Op::ps_add: case Op::ps_sub: case Op::ps_sum0: case Op::ps_sum1: {
        const bool sub = op == Op::fsubs || op == Op::ps_sub;
        u32 b_reg = rb;
        bool b_ps1 = half != 0;
        if (op == Op::ps_sum0 || op == Op::ps_sum1) {  // A.ps0 + B.ps1
          if (half) break;
          b_ps1 = true;
        }
        u64& A = F(ra);
        u64& B = b_ps1 ? c.fpr[b_reg].ps1 : c.fpr[b_reg].ps0;
        switch (r.next() % 3) {
          case 0: {  // exactly m: x + (m - x)
            double x = as_d(m) * (1.0 + static_cast<double>(r.next() % 1024) / 4096.0);
            x = static_cast<double>(static_cast<float>(x));
            A = as_b(x);
            B = as_b(sub ? x - as_d(m) : as_d(m) - x);
            break;
          }
          default: {  // m plus a tiny term
            A = m;
            B = tiny(m);
            break;
          }
        }
        break;
      }
      case Op::fmuls: case Op::ps_mul: case Op::ps_muls0: case Op::ps_muls1: {
        u64& A = F(ra);
        u64& C = (op == Op::ps_muls0) ? c.fpr[rc].ps0 : (op == Op::ps_muls1) ? c.fpr[rc].ps1 : F(rc);
        int k = static_cast<int>(r.next() % 9) - 4;
        A = as_b(as_d(m) / std::ldexp(1.0, k));
        C = as_b(std::ldexp(1.0, k));
        if (r.next() % 3 == 0) A = (A & ~0x1FFFFFFFull) | (r.next() & 0x1FFFFFFFull);  // not exact
        break;
      }
      case Op::fmadds: case Op::fmsubs: case Op::fnmadds: case Op::fnmsubs: case Op::ps_madd: case Op::ps_msub:
      case Op::ps_nmadd: case Op::ps_nmsub: case Op::ps_madds0: case Op::ps_madds1: {
        const bool sub = op == Op::fmsubs || op == Op::fnmsubs || op == Op::ps_msub || op == Op::ps_nmsub;
        u64& A = F(ra);
        u64& B = F(rb);
        u64& C = (op == Op::ps_madds0) ? c.fpr[rc].ps0 : (op == Op::ps_madds1) ? c.fpr[rc].ps1 : F(rc);
        int k = static_cast<int>(r.next() % 9) - 4;
        if (r.next() % 3 == 0) {  // a product that underflows double, b a signed zero, tiny or m
          A = ((r.next() & 1) << 63) | ((1023 - 100 - r.next() % 60) << 52) | (r.next() & 0x000FFFFFE0000000ull);
          C = ((r.next() & 1) << 63) | (r.next() & 0x000FFFFFFFFFFFFFull) >> (r.next() % 40);
          u64 kind = r.next() % 3;
          B = kind == 0 ? (r.next() & 1) << 63 : kind == 1 ? tiny(m) : m;
        } else if (r.next() % 2) {  // p = m exactly, b tiny
          A = as_b(as_d(m) / std::ldexp(1.0, k));
          C = as_b(std::ldexp(1.0, k));
          B = tiny(m);
        } else {  // p + b = m exactly, p a product of singles
          double x = static_cast<double>(static_cast<float>(as_d(m) * 0.75));
          A = as_b(x / std::ldexp(1.0, k));
          C = as_b(std::ldexp(1.0, k));
          double rest = as_d(m) - x;
          B = as_b(sub ? -rest : rest);
        }
        break;
      }
      case Op::fdivs: case Op::ps_div: {
        u64& A = F(ra);
        u64& B = F(rb);
        int k = static_cast<int>(r.next() % 9) - 4;
        A = m;
        B = as_b(std::ldexp(1.0, k));
        A = as_b(as_d(A) * as_d(B));
        break;
      }
      default:
        break;
    }
    if (op == Op::fadds || op == Op::fsubs || op == Op::fmuls || op == Op::fdivs || op == Op::fmadds ||
        op == Op::fmsubs || op == Op::fnmadds || op == Op::fnmsubs)
      break;  // scalar: ps0 only
  }
}

}  // namespace

// Q4, F1: both models, each against the interpreter with the same model: the
// exact one (E2d's proofs), and the fast one, where the translated code must be
// the semantics library bit for bit (the same on every host).
static void fp_edges(bool exact) {
  ppc::fp::g_model = exact ? ppc::fp::Model::Exact : ppc::fp::Model::Fast;
  const Op ops[] = {
      Op::fadd,    Op::fsub,    Op::fmul,    Op::fdiv,     Op::fadds,    Op::fsubs,    Op::fmuls,   Op::fdivs,
      Op::fmadd,   Op::fmsub,   Op::fnmadd,  Op::fnmsub,   Op::fmadds,   Op::fmsubs,   Op::fnmadds, Op::fnmsubs,
      Op::frsp,    Op::fctiw,   Op::fctiwz,  Op::fcmpu,    Op::fcmpo,    Op::fsel,     Op::fres,    Op::frsqrte,
      Op::ps_add,  Op::ps_sub,  Op::ps_mul,  Op::ps_div,   Op::ps_muls0, Op::ps_muls1, Op::ps_madd, Op::ps_msub,
      Op::ps_nmadd, Op::ps_nmsub, Op::ps_madds0, Op::ps_madds1, Op::ps_sum0, Op::ps_sum1, Op::ps_sel, Op::ps_cmpu0,
      Op::ps_cmpu1, Op::ps_cmpo0, Op::ps_cmpo1, Op::ps_res, Op::ps_rsqrte, Op::psq_l, Op::psq_lu, Op::psq_lx,
      Op::psq_lux, Op::psq_st, Op::psq_stu, Op::psq_stx, Op::psq_stux, Op::lmw,    Op::stmw,    Op::sraw,
      Op::mfspr,   Op::mtspr,   Op::mfmsr};
  // MVP_FUZZ_STATES and MVP_FUZZ_SEED (development) scale the run up and vary it.
  const char* env_states = std::getenv("MVP_FUZZ_STATES");
  const char* env_seed = std::getenv("MVP_FUZZ_SEED");
  const int kWords = 24, kStates = env_states ? std::atoi(env_states) : 2500;
  Rng r(env_seed ? std::strtoull(env_seed, nullptr, 0) : 0xE2D0F1A57ull);
  std::vector<u32> words;
  for (Op op : ops) {
    const OpInfo& info = op_info(op);
    for (int n = 0; n < kWords;) {
      u32 w = info.pattern | (r.u() & ~info.mask);
      if (op == Op::mfspr || op == Op::mtspr) {  // XER, SRR0/1, GQRs, HID2, plain SPRs (not DEC or the time base)
        const u32 sprs[] = {1, 26, 27, 912, 913, 915, 919, 920, 1008, 272};
        u32 n_spr = sprs[r.next() % 10];
        w = (w & ~(0x3FFu << 11)) | ((n_spr & 31) << 16) | ((n_spr >> 5) << 11);
      }
      if (decode(w) != op) continue;
      words.push_back(w);
      ++n;
    }
  }
  std::size_t bytes = 0;
  std::vector<rt::GuestFn> fns = translate(words, &bytes, exact);
  MESSAGE(words.size(), " words translated into a ", bytes, "-byte module");

  Pair p;
  for (u8& b : p.ram_ref) b = static_cast<u8>(r.next() >> 56);
  p.ram_wasm = p.ram_ref;
  std::size_t executions = 0, differences = 0, constructed = 0;
  std::string first;
  for (std::size_t k = 0; k < words.size(); ++k) {
    const u32 w = words[k];
    const Op op = decode(w);
    const Insn i{w};
    const bool stores = op == Op::psq_st || op == Op::psq_stu || op == Op::psq_stx || op == Op::psq_stux ||
                        op == Op::stmw;
    for (int n = 0; n < kStates; ++n) {
      Cpu& c = p.ref;
      for (u32& v : c.gpr) v = (r.next() % 4) ? static_cast<u32>(r.next()) : static_cast<u32>(0xFFF0 + r.next() % 32);
      for (Fpr& f : c.fpr) {
        f.ps0 = fz_value(r);
        f.ps1 = fz_value(r);
      }
      c.cr = r.u();
      c.lr = r.u();
      c.ctr = r.u();
      c.set_xer(r.u());
      c.fpscr = (r.next() % 4) ? ((r.u() & ~7u) | fpscr::NI) : r.u();
      c.msr = r.u();
      for (u32 q = 0; q < 8; ++q) c.spr[spr::GQR0 + q] = r.u() & 0x3F073F07u;
      if (r.next() % 3 == 0) {
        construct(r, c, op, i);
        ++constructed;
      }
      p.sync();
      const Cpu before = p.ref;
      execute_plain(p.ref, op, i);
      run_translated(fns[k], p.wasm, kText + 8 * static_cast<u32>(k));
      ++executions;
      std::string d = diff(p.ref, p.wasm);
      if (d.empty() && stores && p.ram_ref != p.ram_wasm) d = "RAM";
      if (!d.empty()) {
        if (differences < 8) {
          char in[200];
          std::snprintf(in, sizeof in, " | fpscr %08X A %016llX:%016llX B %016llX:%016llX C %016llX:%016llX",
                        before.fpscr, (unsigned long long)before.fpr[i.rA()].ps0,
                        (unsigned long long)before.fpr[i.rA()].ps1, (unsigned long long)before.fpr[i.rB()].ps0,
                        (unsigned long long)before.fpr[i.rB()].ps1, (unsigned long long)before.fpr[i.rC()].ps0,
                        (unsigned long long)before.fpr[i.rC()].ps1);
          MESSAGE(op_word(w), ": ", d, in);
          if (first.empty()) first = op_word(w) + ": " + d;
        }
        ++differences;
        p.ram_wasm = p.ram_ref;
      }
    }
  }
  MESSAGE(executions, " executions (", constructed, " with constructed operands), ", differences, " differences");
  CHECK_MESSAGE(differences == 0, "first: ", first);
  ppc::fp::g_model = ppc::fp::Model::Fast;
}

TEST_CASE("floating point, paired singles, psq and lmw/stmw: translated code vs interpreter on edge cases") {
  fp_edges(true);
}

TEST_CASE("Q4: the same in the fast floating-point model (F1)") { fp_edges(false); }
