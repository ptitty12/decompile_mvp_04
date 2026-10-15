// Differential fuzzing (E0b item 4 exit): random programs of integer, branch,
// condition-register, XER and load/store instructions run on our reference
// interpreter and on pureikyubu's interpreter (CC0, an independent
// implementation). After every instruction the GPRs, CR, XER, LR, CTR and PC
// must agree; at the end of each program, the data memory too.
//
// Floating point is excluded on purpose: pureikyubu's FP is not hardware-exact
// (E0_SURVEY §2), so tests/test_fp.cpp checks ours against IEEE references.
#include <doctest/doctest.h>

#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <memory>
#include <vector>

#include "common/bytes.h"
#include "pk_oracle.h"
#include "ppc/disasm.h"
#include "ppc/interp.h"

using namespace mvp::ppc;
using mvp::ppc::test::PkOracle;
using mvp::ppc::test::PkState;

namespace {

struct Rng {
  u64 s;
  explicit Rng(u64 seed) : s(seed) {}
  u64 next() {
    s ^= s >> 12;
    s ^= s << 25;
    s ^= s >> 27;
    return s * 0x2545F4914F6CDD1Dull;
  }
  u32 below(u32 n) { return static_cast<u32>(next() % n); }
};

constexpr u32 kRamSize = 0x01800000;  // 24 MiB at 0x80000000
constexpr u32 kCode = 0x80010000;
constexpr u32 kData = 0x80100000;
constexpr u32 kDataSize = 0x30000;
constexpr int kProgramLen = 48;

// Ours: RAM is mapped at 0x80000000 and (for data) at 0x00000000, like the two
// block translations on the pureikyubu side. Reads beyond RAM but inside either
// 256 MiB block return 0 and writes are dropped, like pureikyubu's flat memory
// stub; anything else is an exception.
bool in_blocks(u32 addr) { return addr < 0x10000000u || (addr >= 0x80000000u && addr < 0x90000000u); }
struct FlatIo : Io {
  u32 read(u32 addr, int) override {
    if (in_blocks(addr)) return 0;
    throw GuestFault(0, "outside the blocks");
  }
  void write(u32 addr, u32, int) override {
    if (in_blocks(addr)) return;
    throw GuestFault(0, "outside the blocks");
  }
};

struct NullHooks : Hooks {
  u64 time_base(Cpu&) override { return 0; }
  void set_time_base(Cpu&, u64) override {}
  u32 decrementer(Cpu&) override { return 0; }
  void set_decrementer(Cpu&, u32) override {}
  void msr_changed(Cpu&, u32) override {}
  void icbi(Cpu&, u32) override {}
  void system_call(Cpu&) override {}
};

const Op kOps[] = {
    Op::add, Op::addc, Op::adde, Op::addi, Op::addic, Op::addic_rc, Op::addis, Op::addme, Op::addze, Op::divw,
    Op::divwu, Op::mulhw, Op::mulhwu, Op::mulli, Op::mullw, Op::neg, Op::subf, Op::subfc, Op::subfe, Op::subfic,
    Op::subfme, Op::subfze, Op::cmp, Op::cmpi, Op::cmpl, Op::cmpli, Op::and_, Op::andc, Op::andi_rc, Op::andis_rc,
    Op::cntlzw, Op::eqv, Op::extsb, Op::extsh, Op::nand, Op::nor, Op::or_, Op::orc, Op::ori, Op::oris, Op::xor_,
    Op::xori, Op::xoris, Op::rlwimi, Op::rlwinm, Op::rlwnm, Op::slw, Op::sraw, Op::srawi, Op::srw, Op::b, Op::bc,
    Op::bcctr, Op::bclr, Op::crand, Op::crandc, Op::creqv, Op::crnand, Op::crnor, Op::cror, Op::crxor,
    Op::mcrf, Op::mcrxr, Op::mfcr, Op::mtcrf, Op::mfspr, Op::mtspr, Op::lbz, Op::lbzu, Op::lbzux, Op::lbzx, Op::lha,
    Op::lhau, Op::lhaux, Op::lhax, Op::lhbrx, Op::lhz, Op::lhzu, Op::lhzux, Op::lhzx, Op::lmw, Op::lwarx, Op::lwbrx,
    Op::lwz, Op::lwzu, Op::lwzux, Op::lwzx, Op::stb, Op::stbu, Op::stbux, Op::stbx, Op::sth, Op::sthbrx, Op::sthu,
    Op::sthux, Op::sthx, Op::stmw, Op::stw, Op::stwbrx, Op::stwcx_rc, Op::stwu, Op::stwux, Op::stwx, Op::dcbf,
    Op::dcbst, Op::dcbt, Op::dcbtst, Op::sync, Op::isync, Op::eieio,
};

bool is_update_load(Op op) {
  switch (op) {
    case Op::lbzu: case Op::lbzux: case Op::lhau: case Op::lhaux: case Op::lhzu: case Op::lhzux: case Op::lwzu:
    case Op::lwzux:
      return true;
    default:
      return false;
  }
}
bool is_update_store(Op op) {
  switch (op) {
    case Op::stbu: case Op::stbux: case Op::sthu: case Op::sthux: case Op::stwu: case Op::stwux:
      return true;
    default:
      return false;
  }
}

// One random, well-formed instruction at `pc`.
u32 gen(Rng& r, u32 pc) {
  for (;;) {
    Op op = kOps[r.below(sizeof kOps / sizeof kOps[0])];
    const OpInfo& o = op_info(op);
    u32 w = o.pattern | (static_cast<u32>(r.next()) & ~o.mask);
    Insn i{w};
    // Branch targets stay inside the program; no absolute forms.
    s32 span = static_cast<s32>(kCode + 4 * kProgramLen - pc);
    s32 back = static_cast<s32>(pc - kCode);
    s32 disp = (static_cast<s32>(r.below(static_cast<u32>((span + back) / 4))) * 4) - back;
    if (op == Op::b) w = (w & ~0x03FFFFFEu) | (static_cast<u32>(disp) & 0x03FFFFFC);
    if (op == Op::bc) w = (w & ~0xFFFEu) | (static_cast<u32>(disp) & 0xFFFC);
    if (op == Op::bcctr) w |= 4u << 21;  // BO[2]: the decrementing form is invalid
    // Linking conditional branches: only the always-taken form (see the header).
    if ((op == Op::bc || op == Op::bclr || op == Op::bcctr) && (w & 1)) w = (w & ~(31u << 21)) | (20u << 21);
    if (op == Op::divw || op == Op::divwu || op == Op::mullw) w &= ~(1u << 10);  // no OE (see the header)
    if (op == Op::mfspr || op == Op::mtspr) {
      static const u32 kSpr[3] = {1, 8, 9};  // XER, LR, CTR
      u32 n = kSpr[r.below(3)];
      w = (w & ~(0x3FFu << 11)) | ((n & 31) << 16) | ((n >> 5) << 11);
    }
    i = Insn{w};
    // Invalid forms: update with rA = 0 or rA = rD; lmw over its base register.
    if ((is_update_load(op) && (i.rA() == 0 || i.rA() == i.rD())) || (is_update_store(op) && i.rA() == 0)) continue;
    if (op == Op::lmw && (i.rA() >= i.rD() || i.rA() == 0)) continue;
    if (decode(w) != op) continue;
    return w;
  }
}

// True when `word`, about to run on `c`, falls in one of the uncompared cases above.
bool undefined_or_known_pk_bug(u32 word, const Cpu& c) {
  Insn i{word};
  Op op = decode(word);
  if (op == Op::divw) {
    s32 a = static_cast<s32>(c.gpr[i.rA()]), b = static_cast<s32>(c.gpr[i.rB()]);
    return b == 0 || (a == static_cast<s32>(0x80000000u) && b == -1);
  }
  if (op == Op::divwu) return c.gpr[i.rB()] == 0;
  // stwcx. while holding a reservation for another address: the architecture
  // leaves it undefined whether the store happens (ours: no, like Dolphin; it:
  // yes). Without a reservation ours skips the access, where pureikyubu still
  // translates the address and can fault.
  if (op == Op::stwcx_rc) {
    u32 ea = (i.rA() ? c.gpr[i.rA()] : 0) + c.gpr[i.rB()];
    if (c.reserve && c.reserve_addr != ea) return true;
    if (!c.reserve && !in_blocks(ea)) return true;
  }
  if (op == Op::sraw) {
    u32 n = c.gpr[i.rB()];
    if ((n & 0x3F) == 0 && n != 0) return true;
    if ((n & 0x20) && c.gpr[i.rS()] == 0x80000000u) return true;
  }
  return false;
}

std::string diff(const PkState& a, const Cpu& c) {
  std::string out;
  char b[96];
  for (int k = 0; k < 32; ++k)
    if (a.gpr[k] != c.gpr[k]) {
      std::snprintf(b, sizeof b, " r%d pk=%08X ours=%08X", k, a.gpr[k], c.gpr[k]);
      out += b;
    }
  auto one = [&](const char* n, u32 x, u32 y) {
    if (x != y) {
      std::snprintf(b, sizeof b, " %s pk=%08X ours=%08X", n, x, y);
      out += b;
    }
  };
  one("cr", a.cr, c.cr);
  one("xer", a.xer, c.xer());
  one("lr", a.lr, c.lr);
  one("ctr", a.ctr, c.ctr);
  one("pc", a.pc, c.pc);
  return out;
}

}  // namespace

TEST_CASE("random integer/branch/CR/XER programs: reference interpreter vs pureikyubu") {
  std::vector<u8> ram_pk(kRamSize, 0), ram_ours(kRamSize + 16, 0);
  PkOracle pk(ram_pk.data(), kRamSize);
  auto mem = std::make_unique<Memory>();
  mem->map(0x80000000, ram_ours.data(), kRamSize);
  mem->map(0x00000000, ram_ours.data(), kRamSize);
  FlatIo io;
  mem->io = &io;
  NullHooks hooks;

  Rng r(0xE0B4);
  const int programs = 30000;
  long long steps = 0, compared = 0;
  int both_faulted = 0, mismatched_faults = 0, failures = 0, uncompared = 0;
  std::vector<int> op_count(static_cast<int>(Op::count), 0);
  std::map<std::string, int> fault_by_op;

  for (int p = 0; p < programs && failures < 5; ++p) {
    // Program and data, identical in both memories.
    for (int k = 0; k < kProgramLen; ++k) {
      u32 pc = kCode + 4 * static_cast<u32>(k);
      u32 w = gen(r, pc);
      mvp::put_be32(&ram_ours[pc - 0x80000000], w);
      mvp::put_be32(&ram_pk[pc - 0x80000000], w);
    }
    for (u32 a = 0; a < kDataSize; a += 8) {
      u64 v = r.next();
      mvp::put_be64(&ram_ours[kData - 0x80000000 + a], v);
      mvp::put_be64(&ram_pk[kData - 0x80000000 + a], v);
    }
    Cpu c;
    c.mem = mem.get();
    c.hooks = &hooks;
    c.msr = msr::FP;  // as pureikyubu's (MSR_FP): stray FP stores run, not trap
    PkState s{};
    for (int k = 0; k < 32; ++k) s.gpr[k] = c.gpr[k] = kData + 0x8000 + r.below(0x10000);
    s.cr = c.cr = static_cast<u32>(r.next());
    s.xer = static_cast<u32>(r.next()) & 0xE000007F;
    c.set_xer(s.xer);
    s.pc = c.pc = kCode;
    s.lr = c.lr = kCode + 4;
    s.ctr = c.ctr = kCode + 4;
    pk.load(s);

    for (int n = 0; n < 64; ++n) {
      u32 pc = c.pc;
      u32 word = mvp::be32(&ram_ours[pc - 0x80000000]);
      if (undefined_or_known_pk_bug(word, c)) {
        ++uncompared;
        break;
      }
      Cpu before = c;
      bool ours_ok = true;
      try {
        step(c);
      } catch (const GuestFault&) {
        ours_ok = false;
      }
      bool pk_ok = pk.step();
      ++steps;
      // A branch out of RAM: pureikyubu faults on the fetch in the same step.
      if (ours_ok && !pk_ok && (c.pc < 0x80000000u || c.pc >= 0x80000000u + kRamSize)) ours_ok = false;
      if (!ours_ok || !pk_ok) {
        if (ours_ok != pk_ok) {
          ++mismatched_faults;
          ++fault_by_op[disasm(word, pc).substr(0, disasm(word, pc).find(' '))];
          if (mismatched_faults <= 20)
            MESSAGE("fault mismatch at ", disasm(word, pc), ": ours ", ours_ok ? "ok" : "fault", ", pk ",
                    pk_ok ? "ok" : "exception");
        } else {
          ++both_faulted;
        }
        break;
      }
      PkState got;
      pk.save(&got);
      ++compared;
      ++op_count[static_cast<int>(decode(word))];
      std::string d = diff(got, c);
      if (!d.empty()) {
        char head[256];
        Insn ii{word};
        std::snprintf(head, sizeof head, "program %d step %d at %08X: %08X %s (before: rD/rS=%08X rA=%08X rB=%08X xer=%08X) ->",
                      p, n, pc, word, disasm(word, pc).c_str(), before.gpr[ii.rD()], before.gpr[ii.rA()],
                      before.gpr[ii.rB()], before.xer());
        FAIL_CHECK(head, d);
        ++failures;
        break;
      }
      if (c.pc < kCode || c.pc >= kCode + 4 * kProgramLen) break;
    }
    if (std::memcmp(&ram_ours[kData - 0x80000000], &ram_pk[kData - 0x80000000], kDataSize) != 0) {
      FAIL_CHECK("program ", p, ": data memory differs");
      ++failures;
    }
  }
  for (const auto& [m, n] : fault_by_op) std::printf("  fault mismatches at %-10s %d\n", m.c_str(), n);
  int distinct = 0;
  for (int k = 1; k < static_cast<int>(Op::count); ++k) distinct += op_count[k] ? 1 : 0;
  std::printf("pureikyubu fuzz: %d programs, %lld instructions compared (%lld executed), %d distinct opcodes, "
              "%d programs ended by a fault in both, %d ended at an undefined or known-pureikyubu-bug case, "
              "%d fault mismatches\n",
              programs, compared, steps, distinct, both_faulted, uncompared, mismatched_faults);
  CHECK(failures == 0);
  CHECK(mismatched_faults == 0);
  CHECK(distinct >= 100);
}
