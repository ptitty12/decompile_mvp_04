// ppc::effects() against the semantics: for every opcode, on random states and
// random spare fields,
// - cacheable registers outside `writes` never change;
// - randomizing every cacheable register outside `reads` changes no result:
//   the registers in `writes`, every register that is never cached (FPRs,
//   FPSCR, MSR, SPRs, XER[OV] and the byte count, the reservation), and memory.
// Branches are checked through sem::branch_cond plus their target and link.
#include <doctest/doctest.h>

#include <cstring>
#include <memory>
#include <string>
#include <vector>

#include "ppc/effects.h"
#include "ppc/interp.h"
#include "ppc/sem.h"

using namespace mvp;
using namespace mvp::ppc;

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
  u32 u() { return static_cast<u32>(next() >> 32); }
};

struct FixedHooks : Hooks {
  u64 tb = 5000;
  u32 dec = 77;
  u64 time_base(Cpu&) override { return tb += 3; }
  void set_time_base(Cpu&, u64 v) override { tb = v; }
  u32 decrementer(Cpu&) override { return dec; }
  void set_decrementer(Cpu&, u32 v) override { dec = v; }
  void msr_changed(Cpu&, u32) override {}
  void icbi(Cpu&, u32) override {}
  void system_call(Cpu&) override {}
};

u32 get(const Cpu& c, int r) {
  if (r < 32) return c.gpr[r];
  switch (r) {
    case reg::CR: return c.cr;
    case reg::LR: return c.lr;
    case reg::CTR: return c.ctr;
    case reg::CA: return c.xer_ca;
    default: return c.xer_so;
  }
}
void set(Cpu& c, int r, u32 v) {
  if (r < 32) {
    c.gpr[r] = v;
    return;
  }
  switch (r) {
    case reg::CR: c.cr = v; return;
    case reg::LR: c.lr = v; return;
    case reg::CTR: c.ctr = v; return;
    case reg::CA: c.xer_ca = v & 1; return;
    default: c.xer_so = v & 1; return;
  }
}
const char* name(int r) {
  static char b[8];
  if (r < 32) {
    std::snprintf(b, sizeof b, "r%d", r);
    return b;
  }
  const char* n[] = {"cr", "lr", "ctr", "ca", "so"};
  return n[r - 32];
}

// Everything except the cacheable registers.
std::string uncached_diff(const Cpu& a, const Cpu& b) {
  std::string d;
  if (std::memcmp(a.fpr, b.fpr, sizeof a.fpr)) d += " fpr";
  if (a.fpscr != b.fpscr) d += " fpscr";
  if (a.msr != b.msr) d += " msr";
  if (a.xer_ov != b.xer_ov || a.xer_low != b.xer_low) d += " xer";
  if (a.reserve != b.reserve || a.reserve_addr != b.reserve_addr) d += " reserve";
  if (std::memcmp(a.sr, b.sr, sizeof a.sr)) d += " sr";
  if (std::memcmp(a.spr, b.spr, sizeof a.spr)) d += " spr";
  return d;
}

struct Rig {
  std::vector<u8> ram, init;
  std::unique_ptr<Memory> mem = std::make_unique<Memory>();
  FixedHooks hooks;
  Rig() : ram(Memory::kPageSize), init(Memory::kPageSize) {
    for (u8*& p : mem->page) p = ram.data();  // any effective address is valid
  }
  // Runs `op` from state `s` with the initial memory; returns the final state.
  // For branches the "result" is the condition, kept in spr[0], and the target in spr[1].
  Cpu run(const Cpu& s, Op op, Insn i, bool* plain) {
    std::memcpy(ram.data(), init.data(), ram.size());
    hooks = FixedHooks{};
    Cpu c = s;
    c.mem = mem.get();
    c.hooks = &hooks;
    *plain = true;
    if (op == Op::b || op == Op::bc || op == Op::bclr || op == Op::bcctr) {
      bool t = op == Op::b ? true : sem::branch_cond(c, i);
      u32 target = op == Op::bclr ? c.lr : op == Op::bcctr ? c.ctr : 0;
      if (i.lk()) c.lr = c.pc + 4;
      c.spr[0] = t;
      c.spr[1] = target;
      return c;
    }
    *plain = execute_plain(c, op, i);
    return c;
  }
};

}  // namespace

TEST_CASE("register effects cover every opcode's semantics") {
  Rig rig;
  Rng r(0xEFFEC75ull);
  std::size_t checked = 0, ops_checked = 0;
  for (u32 k = 1; k < static_cast<u32>(Op::count); ++k) {
    Op op = static_cast<Op>(k);
    const OpInfo& info = op_info(op);
    bool any = false;
    for (int n = 0; n < 96; ++n) {
      u32 w = info.pattern | (r.u() & ~info.mask);
      if (decode(w) != op) continue;
      Insn i{w};
      Effects e = effects(op, i);
      Cpu s;
      for (u32& v : s.gpr) v = (r.next() & 3) ? r.u() : (r.u() & 0xFF);
      for (Fpr& f : s.fpr) {
        f.ps0 = r.next();
        f.ps1 = r.next();
      }
      s.cr = r.u();
      s.lr = r.u();
      s.ctr = (r.next() & 3) ? r.u() : 1;
      s.set_xer(r.u());
      s.fpscr = r.u();
      s.msr = r.u();
      for (u32& v : s.spr) v = r.u();
      s.reserve = r.u() & 1;
      s.reserve_addr = r.u();
      s.pc = 0x80001000u;
      for (u8& b : rig.init) b = static_cast<u8>(r.next() >> 56);

      bool plain = true;
      Cpu a = rig.run(s, op, i, &plain);
      if (!plain) break;  // sc, rfi, traps: no execute_plain semantics to check
      std::vector<u8> mem_a = rig.ram;
      any = true;
      ++checked;
      for (int g = 0; g < reg::kCount; ++g)
        if (!(e.writes & bit(g)))
          CHECK_MESSAGE(get(a, g) == get(s, g), std::string(op_name(op)), " writes ", std::string(name(g)), " (word ", w, ")");

      // Randomize everything the instruction does not read.
      Cpu s2 = s;
      for (int g = 0; g < reg::kCount; ++g)
        if (!(e.reads & bit(g))) set(s2, g, get(s, g) ^ r.u() ^ 0x5A5A5A5Au);
      Cpu b = rig.run(s2, op, i, &plain);
      for (int g = 0; g < reg::kCount; ++g)
        if (e.writes & bit(g))
          CHECK_MESSAGE(get(a, g) == get(b, g), std::string(op_name(op)), " reads more than declared (", std::string(name(g)), " differs, word ",
                        w, ")");
      std::string d = uncached_diff(a, b);
      CHECK_MESSAGE(d.empty(), std::string(op_name(op)), " reads more than declared:", d, " (word ", w, ")");
      CHECK_MESSAGE(mem_a == rig.ram, std::string(op_name(op)), " reads more than declared: memory differs (word ", w, ")");
    }
    if (any) ++ops_checked;
  }
  MESSAGE(checked, " executions, ", ops_checked, " opcodes");
  CHECK(ops_checked >= 214);
}
