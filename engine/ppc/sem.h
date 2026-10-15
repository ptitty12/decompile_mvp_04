// Gekko instruction semantics: one function per opcode, `void op(Cpu&, Insn)`.
//
// This is the single definition of what each instruction does. The reference
// interpreter calls these functions with decoded words; the C++ emitter emits
// calls with constant words, which the compiler folds. Branches only compute
// their condition and target here (the caller owns control flow).
//
// Integer behaviour follows the PowerPC 750CL / Gekko manuals; where the
// architecture says "undefined" (divide overflow), the values are the ones the
// hardware produces (as measured by the Dolphin project's hardware tests, read
// as reference, not copied). Floating point is in fp.h.
#pragma once

#include "ppc/cpu.h"
#include "ppc/fp.h"
#include "ppc/isa.h"
#include "ppc/mem_access.h"

namespace mvp::ppc::sem {

// ---- condition register and XER helpers ----

inline u32 cr_bit(const Cpu& c, u32 bit) { return (c.cr >> (31 - bit)) & 1; }
inline void set_cr_bit(Cpu& c, u32 bit, u32 v) {
  u32 m = 1u << (31 - bit);
  c.cr = v ? (c.cr | m) : (c.cr & ~m);
}
inline void set_cr_field(Cpu& c, u32 field, u32 bits4) {
  u32 sh = 28 - 4 * field;
  c.cr = (c.cr & ~(0xFu << sh)) | ((bits4 & 0xF) << sh);
}
inline u32 cr_field(const Cpu& c, u32 field) { return (c.cr >> (28 - 4 * field)) & 0xF; }
// LT GT EQ SO for a signed comparison with zero.
inline void set_cr0(Cpu& c, u32 r) {
  s32 v = static_cast<s32>(r);
  set_cr_field(c, 0, (v < 0 ? 8u : v > 0 ? 4u : 2u) | c.xer_so);
}
inline void set_ov(Cpu& c, bool ov) {
  c.xer_ov = ov ? 1 : 0;
  c.xer_so |= c.xer_ov;
}
inline u32 rotl(u32 v, u32 n) { return n ? (v << n) | (v >> (32 - n)) : v; }

// Effective addresses: rA|0 + d, rA|0 + rB.
inline u32 ea_d(const Cpu& c, Insn i) { return (i.rA() ? c.gpr[i.rA()] : 0) + static_cast<u32>(i.simm()); }
inline u32 ea_x(const Cpu& c, Insn i) { return (i.rA() ? c.gpr[i.rA()] : 0) + c.gpr[i.rB()]; }
inline u32 ea_du(const Cpu& c, Insn i) { return c.gpr[i.rA()] + static_cast<u32>(i.simm()); }
inline u32 ea_xu(const Cpu& c, Insn i) { return c.gpr[i.rA()] + c.gpr[i.rB()]; }

// ---- integer arithmetic ----

// rD = a + b + carry_in, with optional CA, OV (OE) and CR0 (Rc) updates.
inline void add_with(Cpu& c, Insn i, u32 a, u32 b, u32 carry_in, bool set_ca) {
  u64 wide = static_cast<u64>(a) + b + carry_in;
  u32 r = static_cast<u32>(wide);
  if (set_ca) c.xer_ca = static_cast<u32>(wide >> 32);
  if (i.oe()) set_ov(c, ((a ^ r) & (b ^ r)) >> 31);
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}

inline void add(Cpu& c, Insn i) { add_with(c, i, c.gpr[i.rA()], c.gpr[i.rB()], 0, false); }
inline void addc(Cpu& c, Insn i) { add_with(c, i, c.gpr[i.rA()], c.gpr[i.rB()], 0, true); }
inline void adde(Cpu& c, Insn i) { add_with(c, i, c.gpr[i.rA()], c.gpr[i.rB()], c.xer_ca, true); }
inline void addze(Cpu& c, Insn i) { add_with(c, i, c.gpr[i.rA()], 0, c.xer_ca, true); }
inline void addme(Cpu& c, Insn i) { add_with(c, i, c.gpr[i.rA()], 0xFFFFFFFFu, c.xer_ca, true); }
inline void subf(Cpu& c, Insn i) { add_with(c, i, ~c.gpr[i.rA()], c.gpr[i.rB()], 1, false); }
inline void subfc(Cpu& c, Insn i) { add_with(c, i, ~c.gpr[i.rA()], c.gpr[i.rB()], 1, true); }
inline void subfe(Cpu& c, Insn i) { add_with(c, i, ~c.gpr[i.rA()], c.gpr[i.rB()], c.xer_ca, true); }
inline void subfze(Cpu& c, Insn i) { add_with(c, i, ~c.gpr[i.rA()], 0, c.xer_ca, true); }
inline void subfme(Cpu& c, Insn i) { add_with(c, i, ~c.gpr[i.rA()], 0xFFFFFFFFu, c.xer_ca, true); }
inline void neg(Cpu& c, Insn i) {
  u32 a = c.gpr[i.rA()];
  u32 r = 0u - a;
  if (i.oe()) set_ov(c, a == 0x80000000u);
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}

inline void addi(Cpu& c, Insn i) { c.gpr[i.rD()] = (i.rA() ? c.gpr[i.rA()] : 0) + static_cast<u32>(i.simm()); }
inline void addis(Cpu& c, Insn i) { c.gpr[i.rD()] = (i.rA() ? c.gpr[i.rA()] : 0) + (i.uimm() << 16); }
inline void addic(Cpu& c, Insn i) {
  u32 a = c.gpr[i.rA()];
  u64 wide = static_cast<u64>(a) + static_cast<u32>(i.simm());
  c.xer_ca = static_cast<u32>(wide >> 32);
  c.gpr[i.rD()] = static_cast<u32>(wide);
}
inline void addic_rc(Cpu& c, Insn i) {
  addic(c, i);
  set_cr0(c, c.gpr[i.rD()]);
}
inline void subfic(Cpu& c, Insn i) {
  u64 wide = static_cast<u64>(static_cast<u32>(~c.gpr[i.rA()])) + static_cast<u32>(i.simm()) + 1;
  c.xer_ca = static_cast<u32>(wide >> 32);
  c.gpr[i.rD()] = static_cast<u32>(wide);
}
inline void mulli(Cpu& c, Insn i) {
  c.gpr[i.rD()] = static_cast<u32>(static_cast<s32>(c.gpr[i.rA()]) * static_cast<s64>(i.simm()));
}
inline void mullw(Cpu& c, Insn i) {
  s64 p = static_cast<s64>(static_cast<s32>(c.gpr[i.rA()])) * static_cast<s32>(c.gpr[i.rB()]);
  u32 r = static_cast<u32>(p);
  if (i.oe()) set_ov(c, p != static_cast<s32>(r));
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}
inline void mulhw(Cpu& c, Insn i) {
  s64 p = static_cast<s64>(static_cast<s32>(c.gpr[i.rA()])) * static_cast<s32>(c.gpr[i.rB()]);
  u32 r = static_cast<u32>(static_cast<u64>(p) >> 32);
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}
inline void mulhwu(Cpu& c, Insn i) {
  u64 p = static_cast<u64>(c.gpr[i.rA()]) * c.gpr[i.rB()];
  u32 r = static_cast<u32>(p >> 32);
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}
// Divide overflow (b == 0, or 0x80000000 / -1): the hardware returns 0xFFFFFFFF
// for a negative dividend and 0 otherwise.
inline void divw(Cpu& c, Insn i) {
  s32 a = static_cast<s32>(c.gpr[i.rA()]), b = static_cast<s32>(c.gpr[i.rB()]);
  bool ov = b == 0 || (a == static_cast<s32>(0x80000000u) && b == -1);
  u32 r = ov ? (a < 0 ? 0xFFFFFFFFu : 0u) : static_cast<u32>(a / b);
  if (i.oe()) set_ov(c, ov);
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}
inline void divwu(Cpu& c, Insn i) {
  u32 a = c.gpr[i.rA()], b = c.gpr[i.rB()];
  bool ov = b == 0;
  u32 r = ov ? 0u : a / b;
  if (i.oe()) set_ov(c, ov);
  c.gpr[i.rD()] = r;
  if (i.rc()) set_cr0(c, r);
}

// ---- compare ----

inline u32 cmp_bits(Cpu& c, bool lt, bool gt) { return (lt ? 8u : gt ? 4u : 2u) | c.xer_so; }
inline void cmp(Cpu& c, Insn i) {
  s32 a = static_cast<s32>(c.gpr[i.rA()]), b = static_cast<s32>(c.gpr[i.rB()]);
  set_cr_field(c, i.crfD(), cmp_bits(c, a < b, a > b));
}
inline void cmpl(Cpu& c, Insn i) {
  u32 a = c.gpr[i.rA()], b = c.gpr[i.rB()];
  set_cr_field(c, i.crfD(), cmp_bits(c, a < b, a > b));
}
inline void cmpi(Cpu& c, Insn i) {
  s32 a = static_cast<s32>(c.gpr[i.rA()]), b = i.simm();
  set_cr_field(c, i.crfD(), cmp_bits(c, a < b, a > b));
}
inline void cmpli(Cpu& c, Insn i) {
  u32 a = c.gpr[i.rA()], b = i.uimm();
  set_cr_field(c, i.crfD(), cmp_bits(c, a < b, a > b));
}

// ---- logical ----

inline void logic_result(Cpu& c, Insn i, u32 r) {
  c.gpr[i.rA()] = r;
  if (i.rc()) set_cr0(c, r);
}
inline void and_(Cpu& c, Insn i) { logic_result(c, i, c.gpr[i.rS()] & c.gpr[i.rB()]); }
inline void andc(Cpu& c, Insn i) { logic_result(c, i, c.gpr[i.rS()] & ~c.gpr[i.rB()]); }
inline void or_(Cpu& c, Insn i) { logic_result(c, i, c.gpr[i.rS()] | c.gpr[i.rB()]); }
inline void orc(Cpu& c, Insn i) { logic_result(c, i, c.gpr[i.rS()] | ~c.gpr[i.rB()]); }
inline void xor_(Cpu& c, Insn i) { logic_result(c, i, c.gpr[i.rS()] ^ c.gpr[i.rB()]); }
inline void nand(Cpu& c, Insn i) { logic_result(c, i, ~(c.gpr[i.rS()] & c.gpr[i.rB()])); }
inline void nor(Cpu& c, Insn i) { logic_result(c, i, ~(c.gpr[i.rS()] | c.gpr[i.rB()])); }
inline void eqv(Cpu& c, Insn i) { logic_result(c, i, ~(c.gpr[i.rS()] ^ c.gpr[i.rB()])); }
inline void extsb(Cpu& c, Insn i) {
  logic_result(c, i, static_cast<u32>(static_cast<s32>(static_cast<std::int8_t>(c.gpr[i.rS()]))));
}
inline void extsh(Cpu& c, Insn i) {
  logic_result(c, i, static_cast<u32>(static_cast<s32>(static_cast<std::int16_t>(c.gpr[i.rS()]))));
}
inline void cntlzw(Cpu& c, Insn i) {
  u32 v = c.gpr[i.rS()], n = 0;
  while (n < 32 && !(v & 0x80000000u)) {
    v <<= 1;
    ++n;
  }
  logic_result(c, i, n);
}
inline void ori(Cpu& c, Insn i) { c.gpr[i.rA()] = c.gpr[i.rS()] | i.uimm(); }
inline void oris(Cpu& c, Insn i) { c.gpr[i.rA()] = c.gpr[i.rS()] | (i.uimm() << 16); }
inline void xori(Cpu& c, Insn i) { c.gpr[i.rA()] = c.gpr[i.rS()] ^ i.uimm(); }
inline void xoris(Cpu& c, Insn i) { c.gpr[i.rA()] = c.gpr[i.rS()] ^ (i.uimm() << 16); }
inline void andi_rc(Cpu& c, Insn i) {
  u32 r = c.gpr[i.rS()] & i.uimm();
  c.gpr[i.rA()] = r;
  set_cr0(c, r);
}
inline void andis_rc(Cpu& c, Insn i) {
  u32 r = c.gpr[i.rS()] & (i.uimm() << 16);
  c.gpr[i.rA()] = r;
  set_cr0(c, r);
}

// ---- rotate and shift ----

inline void rlwinm(Cpu& c, Insn i) { logic_result(c, i, rotl(c.gpr[i.rS()], i.sh()) & rot_mask(i.mb(), i.me())); }
inline void rlwnm(Cpu& c, Insn i) {
  logic_result(c, i, rotl(c.gpr[i.rS()], c.gpr[i.rB()] & 31) & rot_mask(i.mb(), i.me()));
}
inline void rlwimi(Cpu& c, Insn i) {
  u32 m = rot_mask(i.mb(), i.me());
  logic_result(c, i, (rotl(c.gpr[i.rS()], i.sh()) & m) | (c.gpr[i.rA()] & ~m));
}
inline void slw(Cpu& c, Insn i) {
  u32 n = c.gpr[i.rB()] & 0x3F;
  logic_result(c, i, n > 31 ? 0 : c.gpr[i.rS()] << n);
}
inline void srw(Cpu& c, Insn i) {
  u32 n = c.gpr[i.rB()] & 0x3F;
  logic_result(c, i, n > 31 ? 0 : c.gpr[i.rS()] >> n);
}
inline void sra_by(Cpu& c, Insn i, u32 n) {
  s32 v = static_cast<s32>(c.gpr[i.rS()]);
  u32 r;
  if (n > 31) {
    r = v < 0 ? 0xFFFFFFFFu : 0u;
    c.xer_ca = v < 0 ? 1 : 0;
  } else {
    r = static_cast<u32>(v >> n);
    c.xer_ca = (v < 0 && n && (static_cast<u32>(v) & ((1u << n) - 1))) ? 1 : 0;
  }
  logic_result(c, i, r);
}
inline void sraw(Cpu& c, Insn i) { sra_by(c, i, c.gpr[i.rB()] & 0x3F); }
inline void srawi(Cpu& c, Insn i) { sra_by(c, i, i.sh()); }

// ---- condition register logic ----

inline void crop(Cpu& c, Insn i, u32 r) { set_cr_bit(c, i.crbD(), r & 1); }
inline void crand(Cpu& c, Insn i) { crop(c, i, cr_bit(c, i.crbA()) & cr_bit(c, i.crbB())); }
inline void crandc(Cpu& c, Insn i) { crop(c, i, cr_bit(c, i.crbA()) & ~cr_bit(c, i.crbB())); }
inline void creqv(Cpu& c, Insn i) { crop(c, i, ~(cr_bit(c, i.crbA()) ^ cr_bit(c, i.crbB()))); }
inline void crnand(Cpu& c, Insn i) { crop(c, i, ~(cr_bit(c, i.crbA()) & cr_bit(c, i.crbB()))); }
inline void crnor(Cpu& c, Insn i) { crop(c, i, ~(cr_bit(c, i.crbA()) | cr_bit(c, i.crbB()))); }
inline void cror(Cpu& c, Insn i) { crop(c, i, cr_bit(c, i.crbA()) | cr_bit(c, i.crbB())); }
inline void crorc(Cpu& c, Insn i) { crop(c, i, cr_bit(c, i.crbA()) | ~cr_bit(c, i.crbB())); }
inline void crxor(Cpu& c, Insn i) { crop(c, i, cr_bit(c, i.crbA()) ^ cr_bit(c, i.crbB())); }
inline void mcrf(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), cr_field(c, i.crfS())); }
inline void mcrxr(Cpu& c, Insn i) {
  set_cr_field(c, i.crfD(), c.xer() >> 28);
  c.xer_so = c.xer_ov = c.xer_ca = 0;  // XER[0-3] = 0, the reserved bit 3 included
  c.xer_low &= ~0x10000000u;
}
inline void mfcr(Cpu& c, Insn i) { c.gpr[i.rD()] = c.cr; }
inline void mtcrf(Cpu& c, Insn i) {
  u32 m = 0;
  for (u32 f = 0; f < 8; ++f)
    if (i.crm() & (0x80u >> f)) m |= 0xF0000000u >> (4 * f);
  c.cr = (c.cr & ~m) | (c.gpr[i.rS()] & m);
}

// ---- special registers ----

inline void mfmsr(Cpu& c, Insn i) { c.gpr[i.rD()] = c.msr; }
inline void mtmsr(Cpu& c, Insn i) {
  u32 old = c.msr;
  c.msr = c.gpr[i.rS()];
  c.hooks->msr_changed(c, old);
}
inline u32 read_spr(Cpu& c, u32 n) {
  switch (n) {
    case spr::XER: return c.xer();
    case spr::LR: return c.lr;
    case spr::CTR: return c.ctr;
    case spr::DEC: return c.hooks->decrementer(c);
    case spr::TBL_R: case spr::TBL_W: return static_cast<u32>(c.hooks->time_base(c));
    case spr::TBU_R: case spr::TBU_W: return static_cast<u32>(c.hooks->time_base(c) >> 32);
    default: return c.spr[n & 1023];
  }
}
inline void write_spr(Cpu& c, u32 n, u32 v) {
  switch (n) {
    case spr::XER: c.set_xer(v); return;
    case spr::LR: c.lr = v; return;
    case spr::CTR: c.ctr = v; return;
    case spr::DEC: c.hooks->set_decrementer(c, v); return;
    case spr::TBL_W: {
      u64 tb = c.hooks->time_base(c);
      c.hooks->set_time_base(c, (tb & 0xFFFFFFFF00000000ull) | v);
      return;
    }
    case spr::TBU_W: {
      u64 tb = c.hooks->time_base(c);
      c.hooks->set_time_base(c, (tb & 0xFFFFFFFFull) | (static_cast<u64>(v) << 32));
      return;
    }
    default: c.spr[n & 1023] = v; return;
  }
}
inline void mfspr(Cpu& c, Insn i) { c.gpr[i.rD()] = read_spr(c, i.spr()); }
inline void mtspr(Cpu& c, Insn i) { write_spr(c, i.spr(), c.gpr[i.rS()]); }
inline void mftb(Cpu& c, Insn i) {
  u64 tb = c.hooks->time_base(c);
  c.gpr[i.rD()] = i.tbr() == spr::TBU_R ? static_cast<u32>(tb >> 32) : static_cast<u32>(tb);
}
inline void mfsr(Cpu& c, Insn i) { c.gpr[i.rD()] = c.sr[i.sr()]; }
inline void mtsr(Cpu& c, Insn i) { c.sr[i.sr()] = c.gpr[i.rS()]; }
inline void mfsrin(Cpu& c, Insn i) { c.gpr[i.rD()] = c.sr[c.gpr[i.rB()] >> 28]; }
inline void mtsrin(Cpu& c, Insn i) { c.sr[c.gpr[i.rB()] >> 28] = c.gpr[i.rS()]; }

// ---- cache, sync, TLB: no architectural effect here, except the icbi hook and dcbz ----

inline void nop_op(Cpu&, Insn) {}
inline void icbi(Cpu& c, Insn i) { c.hooks->icbi(c, ea_x(c, i)); }
inline void dcbz(Cpu& c, Insn i) {
  u32 ea = ea_x(c, i) & ~31u;
  for (u32 k = 0; k < 32; k += 4) write32(c, ea + k, 0);
}

// ---- integer loads and stores ----

inline void lbz(Cpu& c, Insn i) { c.gpr[i.rD()] = read8(c, ea_d(c, i)); }
inline void lbzx(Cpu& c, Insn i) { c.gpr[i.rD()] = read8(c, ea_x(c, i)); }
inline void lbzu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  c.gpr[i.rD()] = read8(c, ea);
  c.gpr[i.rA()] = ea;
}
inline void lbzux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  c.gpr[i.rD()] = read8(c, ea);
  c.gpr[i.rA()] = ea;
}
inline u32 sext16(u32 v) { return static_cast<u32>(static_cast<s32>(static_cast<std::int16_t>(v))); }
inline void lhz(Cpu& c, Insn i) { c.gpr[i.rD()] = read16(c, ea_d(c, i)); }
inline void lhzx(Cpu& c, Insn i) { c.gpr[i.rD()] = read16(c, ea_x(c, i)); }
inline void lhzu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  c.gpr[i.rD()] = read16(c, ea);
  c.gpr[i.rA()] = ea;
}
inline void lhzux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  c.gpr[i.rD()] = read16(c, ea);
  c.gpr[i.rA()] = ea;
}
inline void lha(Cpu& c, Insn i) { c.gpr[i.rD()] = sext16(read16(c, ea_d(c, i))); }
inline void lhax(Cpu& c, Insn i) { c.gpr[i.rD()] = sext16(read16(c, ea_x(c, i))); }
inline void lhau(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  c.gpr[i.rD()] = sext16(read16(c, ea));
  c.gpr[i.rA()] = ea;
}
inline void lhaux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  c.gpr[i.rD()] = sext16(read16(c, ea));
  c.gpr[i.rA()] = ea;
}
inline void lhbrx(Cpu& c, Insn i) {
  u32 v = read16(c, ea_x(c, i));
  c.gpr[i.rD()] = ((v & 0xFF) << 8) | (v >> 8);
}
inline void lwz(Cpu& c, Insn i) { c.gpr[i.rD()] = read32(c, ea_d(c, i)); }
inline void lwzx(Cpu& c, Insn i) { c.gpr[i.rD()] = read32(c, ea_x(c, i)); }
inline void lwzu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  c.gpr[i.rD()] = read32(c, ea);
  c.gpr[i.rA()] = ea;
}
inline void lwzux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  c.gpr[i.rD()] = read32(c, ea);
  c.gpr[i.rA()] = ea;
}
inline u32 bswap32(u32 v) { return (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24); }
inline void lwbrx(Cpu& c, Insn i) { c.gpr[i.rD()] = bswap32(read32(c, ea_x(c, i))); }
inline void lwarx(Cpu& c, Insn i) {
  u32 ea = ea_x(c, i);
  c.gpr[i.rD()] = read32(c, ea);
  c.reserve = 1;
  c.reserve_addr = ea;
}
inline void lmw(Cpu& c, Insn i) {
  u32 ea = ea_d(c, i);
  for (u32 r = i.rD(); r < 32; ++r, ea += 4) c.gpr[r] = read32(c, ea);
}
inline void lswi(Cpu& c, Insn i) {
  u32 ea = i.rA() ? c.gpr[i.rA()] : 0;
  u32 n = i.nb() ? i.nb() : 32;
  u32 r = i.rD() - 1;
  for (u32 k = 0; k < n; ++k, ++ea) {
    if (k % 4 == 0) {
      r = (r + 1) & 31;
      c.gpr[r] = 0;
    }
    c.gpr[r] |= read8(c, ea) << (24 - 8 * (k % 4));
  }
}
inline void lswx(Cpu& c, Insn i) {
  u32 ea = ea_x(c, i);
  u32 n = c.xer_low & 0x7F;
  u32 r = i.rD() - 1;
  for (u32 k = 0; k < n; ++k, ++ea) {
    if (k % 4 == 0) {
      r = (r + 1) & 31;
      c.gpr[r] = 0;
    }
    c.gpr[r] |= read8(c, ea) << (24 - 8 * (k % 4));
  }
}

inline void stb(Cpu& c, Insn i) { write8(c, ea_d(c, i), c.gpr[i.rS()]); }
inline void stbx(Cpu& c, Insn i) { write8(c, ea_x(c, i), c.gpr[i.rS()]); }
inline void stbu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  write8(c, ea, c.gpr[i.rS()]);
  c.gpr[i.rA()] = ea;
}
inline void stbux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  write8(c, ea, c.gpr[i.rS()]);
  c.gpr[i.rA()] = ea;
}
inline void sth(Cpu& c, Insn i) { write16(c, ea_d(c, i), c.gpr[i.rS()]); }
inline void sthx(Cpu& c, Insn i) { write16(c, ea_x(c, i), c.gpr[i.rS()]); }
inline void sthu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  write16(c, ea, c.gpr[i.rS()]);
  c.gpr[i.rA()] = ea;
}
inline void sthux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  write16(c, ea, c.gpr[i.rS()]);
  c.gpr[i.rA()] = ea;
}
inline void sthbrx(Cpu& c, Insn i) {
  u32 v = c.gpr[i.rS()];
  write16(c, ea_x(c, i), ((v & 0xFF) << 8) | ((v >> 8) & 0xFF));
}
inline void stw(Cpu& c, Insn i) { write32(c, ea_d(c, i), c.gpr[i.rS()]); }
inline void stwx(Cpu& c, Insn i) { write32(c, ea_x(c, i), c.gpr[i.rS()]); }
inline void stwu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  write32(c, ea, c.gpr[i.rS()]);
  c.gpr[i.rA()] = ea;
}
inline void stwux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  write32(c, ea, c.gpr[i.rS()]);
  c.gpr[i.rA()] = ea;
}
inline void stwbrx(Cpu& c, Insn i) { write32(c, ea_x(c, i), bswap32(c.gpr[i.rS()])); }
inline void stwcx_rc(Cpu& c, Insn i) {
  u32 ea = ea_x(c, i);
  bool ok = c.reserve && c.reserve_addr == ea;
  if (ok) write32(c, ea, c.gpr[i.rS()]);
  c.reserve = 0;
  set_cr_field(c, 0, (ok ? 2u : 0u) | c.xer_so);
}
inline void stmw(Cpu& c, Insn i) {
  u32 ea = ea_d(c, i);
  for (u32 r = i.rS(); r < 32; ++r, ea += 4) write32(c, ea, c.gpr[r]);
}
inline void stswi(Cpu& c, Insn i) {
  u32 ea = i.rA() ? c.gpr[i.rA()] : 0;
  u32 n = i.nb() ? i.nb() : 32;
  u32 r = i.rS() - 1;
  for (u32 k = 0; k < n; ++k, ++ea) {
    if (k % 4 == 0) r = (r + 1) & 31;
    write8(c, ea, c.gpr[r] >> (24 - 8 * (k % 4)));
  }
}
inline void stswx(Cpu& c, Insn i) {
  u32 ea = ea_x(c, i);
  u32 n = c.xer_low & 0x7F;
  u32 r = i.rS() - 1;
  for (u32 k = 0; k < n; ++k, ++ea) {
    if (k % 4 == 0) r = (r + 1) & 31;
    write8(c, ea, c.gpr[r] >> (24 - 8 * (k % 4)));
  }
}

// ---- floating-point loads and stores ----
// A single-precision load fills both paired-single halves; a double load sets ps0.

inline void fill(Cpu& c, u32 r, u64 v) { c.fpr[r].ps0 = c.fpr[r].ps1 = v; }
inline void lfs(Cpu& c, Insn i) { fill(c, i.rD(), fp::single_to_double(read32(c, ea_d(c, i)))); }
inline void lfsx(Cpu& c, Insn i) { fill(c, i.rD(), fp::single_to_double(read32(c, ea_x(c, i)))); }
inline void lfsu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  fill(c, i.rD(), fp::single_to_double(read32(c, ea)));
  c.gpr[i.rA()] = ea;
}
inline void lfsux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  fill(c, i.rD(), fp::single_to_double(read32(c, ea)));
  c.gpr[i.rA()] = ea;
}
inline void lfd(Cpu& c, Insn i) { c.fpr[i.rD()].ps0 = read64(c, ea_d(c, i)); }
inline void lfdx(Cpu& c, Insn i) { c.fpr[i.rD()].ps0 = read64(c, ea_x(c, i)); }
inline void lfdu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  c.fpr[i.rD()].ps0 = read64(c, ea);
  c.gpr[i.rA()] = ea;
}
inline void lfdux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  c.fpr[i.rD()].ps0 = read64(c, ea);
  c.gpr[i.rA()] = ea;
}
inline void stfs(Cpu& c, Insn i) { write32(c, ea_d(c, i), fp::double_to_single(c.fpr[i.rS()].ps0)); }
inline void stfsx(Cpu& c, Insn i) { write32(c, ea_x(c, i), fp::double_to_single(c.fpr[i.rS()].ps0)); }
inline void stfsu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  write32(c, ea, fp::double_to_single(c.fpr[i.rS()].ps0));
  c.gpr[i.rA()] = ea;
}
inline void stfsux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  write32(c, ea, fp::double_to_single(c.fpr[i.rS()].ps0));
  c.gpr[i.rA()] = ea;
}
inline void stfd(Cpu& c, Insn i) { write64(c, ea_d(c, i), c.fpr[i.rS()].ps0); }
inline void stfdx(Cpu& c, Insn i) { write64(c, ea_x(c, i), c.fpr[i.rS()].ps0); }
inline void stfdu(Cpu& c, Insn i) {
  u32 ea = ea_du(c, i);
  write64(c, ea, c.fpr[i.rS()].ps0);
  c.gpr[i.rA()] = ea;
}
inline void stfdux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  write64(c, ea, c.fpr[i.rS()].ps0);
  c.gpr[i.rA()] = ea;
}
inline void stfiwx(Cpu& c, Insn i) { write32(c, ea_x(c, i), static_cast<u32>(c.fpr[i.rS()].ps0)); }

// ---- floating-point arithmetic ----
// Single-precision results fill both halves; double results set ps0 only.

using fp::Prec;
inline u64 A(const Cpu& c, Insn i) { return c.fpr[i.rA()].ps0; }
inline u64 B(const Cpu& c, Insn i) { return c.fpr[i.rB()].ps0; }
inline u64 C(const Cpu& c, Insn i) { return c.fpr[i.rC()].ps0; }
inline void fresult(Cpu& c, Insn i, u64 v) { c.fpr[i.rD()].ps0 = v; }
inline void sresult(Cpu& c, Insn i, u64 v) { fill(c, i.rD(), v); }

inline void fadd(Cpu& c, Insn i) { fresult(c, i, fp::add(A(c, i), B(c, i), Prec::Double, c.fpscr)); }
inline void fadds(Cpu& c, Insn i) { sresult(c, i, fp::add(A(c, i), B(c, i), Prec::Single, c.fpscr)); }
inline void fsub(Cpu& c, Insn i) { fresult(c, i, fp::sub(A(c, i), B(c, i), Prec::Double, c.fpscr)); }
inline void fsubs(Cpu& c, Insn i) { sresult(c, i, fp::sub(A(c, i), B(c, i), Prec::Single, c.fpscr)); }
inline void fmul(Cpu& c, Insn i) { fresult(c, i, fp::mul(A(c, i), C(c, i), Prec::Double, c.fpscr)); }
inline void fmuls(Cpu& c, Insn i) {
  sresult(c, i, fp::mul(A(c, i), fp::force25(C(c, i)), Prec::Single, c.fpscr));
}
inline void fdiv(Cpu& c, Insn i) { fresult(c, i, fp::div(A(c, i), B(c, i), Prec::Double, c.fpscr)); }
inline void fdivs(Cpu& c, Insn i) { sresult(c, i, fp::div(A(c, i), B(c, i), Prec::Single, c.fpscr)); }
inline void fmadd(Cpu& c, Insn i) {
  fresult(c, i, fp::madd(A(c, i), C(c, i), B(c, i), false, false, Prec::Double, c.fpscr));
}
inline void fmsub(Cpu& c, Insn i) {
  fresult(c, i, fp::madd(A(c, i), C(c, i), B(c, i), true, false, Prec::Double, c.fpscr));
}
inline void fnmadd(Cpu& c, Insn i) {
  fresult(c, i, fp::madd(A(c, i), C(c, i), B(c, i), false, true, Prec::Double, c.fpscr));
}
inline void fnmsub(Cpu& c, Insn i) {
  fresult(c, i, fp::madd(A(c, i), C(c, i), B(c, i), true, true, Prec::Double, c.fpscr));
}
inline void fmadds(Cpu& c, Insn i) {
  sresult(c, i, fp::madd(A(c, i), fp::force25(C(c, i)), B(c, i), false, false, Prec::Single, c.fpscr));
}
inline void fmsubs(Cpu& c, Insn i) {
  sresult(c, i, fp::madd(A(c, i), fp::force25(C(c, i)), B(c, i), true, false, Prec::Single, c.fpscr));
}
inline void fnmadds(Cpu& c, Insn i) {
  sresult(c, i, fp::madd(A(c, i), fp::force25(C(c, i)), B(c, i), false, true, Prec::Single, c.fpscr));
}
inline void fnmsubs(Cpu& c, Insn i) {
  sresult(c, i, fp::madd(A(c, i), fp::force25(C(c, i)), B(c, i), true, true, Prec::Single, c.fpscr));
}
inline void frsp(Cpu& c, Insn i) { sresult(c, i, fp::round_to_single(B(c, i), c.fpscr)); }
inline void fres(Cpu& c, Insn i) { sresult(c, i, fp::reciprocal_estimate(B(c, i), c.fpscr)); }
inline void frsqrte(Cpu& c, Insn i) { fresult(c, i, fp::rsqrt_estimate(B(c, i), c.fpscr)); }
inline void fctiw(Cpu& c, Insn i) { fresult(c, i, fp::to_int32(B(c, i), false, c.fpscr)); }
inline void fctiwz(Cpu& c, Insn i) { fresult(c, i, fp::to_int32(B(c, i), true, c.fpscr)); }
inline void fsel(Cpu& c, Insn i) { fresult(c, i, fp::select(A(c, i), C(c, i), B(c, i))); }
inline void fmr(Cpu& c, Insn i) { fresult(c, i, B(c, i)); }
inline void fneg(Cpu& c, Insn i) { fresult(c, i, B(c, i) ^ fp::kSign); }
inline void fabs(Cpu& c, Insn i) { fresult(c, i, B(c, i) & ~fp::kSign); }
inline void fnabs(Cpu& c, Insn i) { fresult(c, i, B(c, i) | fp::kSign); }

// Unordered/ordered compare into a CR field (LT GT EQ UN). FPSCR[FPCC] is not modeled.
inline u32 fcmp_bits(u64 a, u64 b) {
  if (fp::is_nan(a) || fp::is_nan(b)) return 1;
  bool az = fp::is_zero(a), bz = fp::is_zero(b);
  if (az && bz) return 2;
  bool as = (a & fp::kSign) != 0, bs = (b & fp::kSign) != 0;
  // Compare as sign-magnitude integers.
  auto key = [](u64 x, bool s, bool z) -> s64 {
    if (z) return 0;
    s64 m = static_cast<s64>(x & ~fp::kSign);
    return s ? -m : m;
  };
  s64 ka = key(a, as, az), kb = key(b, bs, bz);
  return ka < kb ? 8u : ka > kb ? 4u : 2u;
}
inline void fcmpu(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), fcmp_bits(A(c, i), B(c, i))); }
inline void fcmpo(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), fcmp_bits(A(c, i), B(c, i))); }

// ---- FPSCR ----

inline void mffs(Cpu& c, Insn i) { fresult(c, i, 0xFFF8000000000000ull | c.fpscr); }
inline void mtfsf(Cpu& c, Insn i) {
  u32 m = 0;
  for (u32 f = 0; f < 8; ++f)
    if (i.fm() & (0x80u >> f)) m |= 0xF0000000u >> (4 * f);
  c.fpscr = (c.fpscr & ~m) | (static_cast<u32>(B(c, i)) & m);
}
inline void mtfsfi(Cpu& c, Insn i) {
  u32 sh = 28 - 4 * i.crfD();
  c.fpscr = (c.fpscr & ~(0xFu << sh)) | (i.mtfsfi_imm() << sh);
}
inline void mtfsb0(Cpu& c, Insn i) { c.fpscr &= ~(0x80000000u >> i.crbD()); }
inline void mtfsb1(Cpu& c, Insn i) { c.fpscr |= 0x80000000u >> i.crbD(); }
inline void mcrfs(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), (c.fpscr >> (28 - 4 * i.crfS())) & 0xF); }

// ---- paired singles ----

inline const Fpr& PA(const Cpu& c, Insn i) { return c.fpr[i.rA()]; }
inline const Fpr& PB(const Cpu& c, Insn i) { return c.fpr[i.rB()]; }
inline const Fpr& PC(const Cpu& c, Insn i) { return c.fpr[i.rC()]; }
inline void pset(Cpu& c, Insn i, u64 ps0, u64 ps1) {
  c.fpr[i.rD()].ps0 = ps0;
  c.fpr[i.rD()].ps1 = ps1;
}
inline void ps_add(Cpu& c, Insn i) {
  pset(c, i, fp::add(PA(c, i).ps0, PB(c, i).ps0, Prec::Single, c.fpscr),
       fp::add(PA(c, i).ps1, PB(c, i).ps1, Prec::Single, c.fpscr));
}
inline void ps_sub(Cpu& c, Insn i) {
  pset(c, i, fp::sub(PA(c, i).ps0, PB(c, i).ps0, Prec::Single, c.fpscr),
       fp::sub(PA(c, i).ps1, PB(c, i).ps1, Prec::Single, c.fpscr));
}
inline void ps_div(Cpu& c, Insn i) {
  pset(c, i, fp::div(PA(c, i).ps0, PB(c, i).ps0, Prec::Single, c.fpscr),
       fp::div(PA(c, i).ps1, PB(c, i).ps1, Prec::Single, c.fpscr));
}
inline void ps_mul(Cpu& c, Insn i) {
  pset(c, i, fp::mul(PA(c, i).ps0, fp::force25(PC(c, i).ps0), Prec::Single, c.fpscr),
       fp::mul(PA(c, i).ps1, fp::force25(PC(c, i).ps1), Prec::Single, c.fpscr));
}
inline void ps_muls0(Cpu& c, Insn i) {
  u64 m = fp::force25(PC(c, i).ps0);
  pset(c, i, fp::mul(PA(c, i).ps0, m, Prec::Single, c.fpscr), fp::mul(PA(c, i).ps1, m, Prec::Single, c.fpscr));
}
inline void ps_muls1(Cpu& c, Insn i) {
  u64 m = fp::force25(PC(c, i).ps1);
  pset(c, i, fp::mul(PA(c, i).ps0, m, Prec::Single, c.fpscr), fp::mul(PA(c, i).ps1, m, Prec::Single, c.fpscr));
}
inline void ps_madd_impl(Cpu& c, Insn i, u64 c0, u64 c1, bool neg_b, bool neg_r) {
  const Fpr a = PA(c, i), b = PB(c, i);
  pset(c, i, fp::madd(a.ps0, fp::force25(c0), b.ps0, neg_b, neg_r, Prec::Single, c.fpscr),
       fp::madd(a.ps1, fp::force25(c1), b.ps1, neg_b, neg_r, Prec::Single, c.fpscr));
}
inline void ps_madd(Cpu& c, Insn i) { ps_madd_impl(c, i, PC(c, i).ps0, PC(c, i).ps1, false, false); }
inline void ps_msub(Cpu& c, Insn i) { ps_madd_impl(c, i, PC(c, i).ps0, PC(c, i).ps1, true, false); }
inline void ps_nmadd(Cpu& c, Insn i) { ps_madd_impl(c, i, PC(c, i).ps0, PC(c, i).ps1, false, true); }
inline void ps_nmsub(Cpu& c, Insn i) { ps_madd_impl(c, i, PC(c, i).ps0, PC(c, i).ps1, true, true); }
inline void ps_madds0(Cpu& c, Insn i) { ps_madd_impl(c, i, PC(c, i).ps0, PC(c, i).ps0, false, false); }
inline void ps_madds1(Cpu& c, Insn i) { ps_madd_impl(c, i, PC(c, i).ps1, PC(c, i).ps1, false, false); }
inline void ps_sum0(Cpu& c, Insn i) {
  u64 s = fp::add(PA(c, i).ps0, PB(c, i).ps1, Prec::Single, c.fpscr);
  pset(c, i, s, PC(c, i).ps1);
}
inline void ps_sum1(Cpu& c, Insn i) {
  u64 s = fp::add(PA(c, i).ps0, PB(c, i).ps1, Prec::Single, c.fpscr);
  pset(c, i, PC(c, i).ps0, s);
}
inline void ps_merge00(Cpu& c, Insn i) { pset(c, i, PA(c, i).ps0, PB(c, i).ps0); }
inline void ps_merge01(Cpu& c, Insn i) { pset(c, i, PA(c, i).ps0, PB(c, i).ps1); }
inline void ps_merge10(Cpu& c, Insn i) { pset(c, i, PA(c, i).ps1, PB(c, i).ps0); }
inline void ps_merge11(Cpu& c, Insn i) { pset(c, i, PA(c, i).ps1, PB(c, i).ps1); }
inline void ps_mr(Cpu& c, Insn i) { pset(c, i, PB(c, i).ps0, PB(c, i).ps1); }
inline void ps_neg(Cpu& c, Insn i) { pset(c, i, PB(c, i).ps0 ^ fp::kSign, PB(c, i).ps1 ^ fp::kSign); }
inline void ps_abs(Cpu& c, Insn i) { pset(c, i, PB(c, i).ps0 & ~fp::kSign, PB(c, i).ps1 & ~fp::kSign); }
inline void ps_nabs(Cpu& c, Insn i) { pset(c, i, PB(c, i).ps0 | fp::kSign, PB(c, i).ps1 | fp::kSign); }
inline void ps_sel(Cpu& c, Insn i) {
  pset(c, i, fp::select(PA(c, i).ps0, PC(c, i).ps0, PB(c, i).ps0),
       fp::select(PA(c, i).ps1, PC(c, i).ps1, PB(c, i).ps1));
}
inline void ps_res(Cpu& c, Insn i) {
  pset(c, i, fp::reciprocal_estimate(PB(c, i).ps0, c.fpscr), fp::reciprocal_estimate(PB(c, i).ps1, c.fpscr));
}
inline void ps_rsqrte(Cpu& c, Insn i) {
  pset(c, i, fp::round_to_single(fp::rsqrt_estimate(PB(c, i).ps0, c.fpscr), c.fpscr),
       fp::round_to_single(fp::rsqrt_estimate(PB(c, i).ps1, c.fpscr), c.fpscr));
}
inline void ps_cmpu0(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), fcmp_bits(PA(c, i).ps0, PB(c, i).ps0)); }
inline void ps_cmpo0(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), fcmp_bits(PA(c, i).ps0, PB(c, i).ps0)); }
inline void ps_cmpu1(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), fcmp_bits(PA(c, i).ps1, PB(c, i).ps1)); }
inline void ps_cmpo1(Cpu& c, Insn i) { set_cr_field(c, i.crfD(), fcmp_bits(PA(c, i).ps1, PB(c, i).ps1)); }

// Quantized loads and stores through GQR[i].
inline void psq_load(Cpu& c, u32 rd, u32 ea, u32 w, u32 gqr_index) {
  u32 g = c.spr[spr::GQR0 + gqr_index];
  u32 type = (g >> 16) & 7, scale = (g >> 24) & 0x3F;
  u32 size = fp::quant_size(type);
  auto rd_raw = [&](u32 a) { return size == 1 ? read8(c, a) : size == 2 ? read16(c, a) : read32(c, a); };
  u64 ps0 = fp::dequantize(rd_raw(ea), type, scale);
  u64 ps1 = w ? 0x3FF0000000000000ull : fp::dequantize(rd_raw(ea + size), type, scale);
  c.fpr[rd].ps0 = ps0;
  c.fpr[rd].ps1 = ps1;
}
inline void psq_store(Cpu& c, u32 rs, u32 ea, u32 w, u32 gqr_index) {
  u32 g = c.spr[spr::GQR0 + gqr_index];
  u32 type = g & 7, scale = (g >> 8) & 0x3F;
  u32 size = fp::quant_size(type);
  auto wr = [&](u32 a, u32 v) {
    if (size == 1) write8(c, a, v);
    else if (size == 2) write16(c, a, v);
    else write32(c, a, v);
  };
  wr(ea, fp::quantize(c.fpr[rs].ps0, type, scale));
  if (!w) wr(ea + size, fp::quantize(c.fpr[rs].ps1, type, scale));
}
inline u32 ea_ps(const Cpu& c, Insn i) { return (i.rA() ? c.gpr[i.rA()] : 0) + static_cast<u32>(i.ps_d()); }
inline void psq_l(Cpu& c, Insn i) { psq_load(c, i.rD(), ea_ps(c, i), i.ps_w(), i.ps_i()); }
inline void psq_lu(Cpu& c, Insn i) {
  u32 ea = c.gpr[i.rA()] + static_cast<u32>(i.ps_d());
  psq_load(c, i.rD(), ea, i.ps_w(), i.ps_i());
  c.gpr[i.rA()] = ea;
}
inline void psq_lx(Cpu& c, Insn i) { psq_load(c, i.rD(), ea_x(c, i), i.psx_w(), i.psx_i()); }
inline void psq_lux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  psq_load(c, i.rD(), ea, i.psx_w(), i.psx_i());
  c.gpr[i.rA()] = ea;
}
inline void psq_st(Cpu& c, Insn i) { psq_store(c, i.rS(), ea_ps(c, i), i.ps_w(), i.ps_i()); }
inline void psq_stu(Cpu& c, Insn i) {
  u32 ea = c.gpr[i.rA()] + static_cast<u32>(i.ps_d());
  psq_store(c, i.rS(), ea, i.ps_w(), i.ps_i());
  c.gpr[i.rA()] = ea;
}
inline void psq_stx(Cpu& c, Insn i) { psq_store(c, i.rS(), ea_x(c, i), i.psx_w(), i.psx_i()); }
inline void psq_stux(Cpu& c, Insn i) {
  u32 ea = ea_xu(c, i);
  psq_store(c, i.rS(), ea, i.psx_w(), i.psx_i());
  c.gpr[i.rA()] = ea;
}

// ---- system ----

// rfi: restore MSR from SRR1 and continue at SRR0 (the caller transfers control).
inline void rfi(Cpu& c) {
  constexpr u32 kMask = 0x87C0FFFFu;  // MSR bits restored from SRR1
  u32 old = c.msr;
  c.msr = ((c.msr & ~kMask) | (c.spr[spr::SRR1] & kMask)) & ~(1u << 18);
  c.pc = c.spr[spr::SRR0] & ~3u;
  c.hooks->msr_changed(c, old);
}

// Exception entry, as the hardware takes an interrupt: SRR0 = c.pc (the
// interrupted or faulting instruction), SRR1 = the MSR's low half, the new MSR
// keeps only ME, IP and ILE (LE from ILE: external and decrementer interrupts,
// floating-point unavailable), and c.pc = the vector (at 0xFFF00000 with MSR[IP]).
// Translation goes off with IR/DR (the caller's hooks see the MSR change).
inline void enter_exception(Cpu& c, u32 vector) {
  constexpr u32 kME = 1u << 12, kIP = 1u << 6, kILE = 1u << 16, kLE = 1u;
  const u32 old = c.msr;
  c.spr[spr::SRR0] = c.pc;
  c.spr[spr::SRR1] = old & 0x0000FFFFu;
  c.msr = (old & (kME | kIP | kILE)) | ((old & kILE) ? kLE : 0);
  c.hooks->msr_changed(c, old);
  c.pc = ((old & kIP) ? 0xFFF00000u : 0u) | vector;
}

inline bool trap_cond(u32 to, s32 a, s32 b) {
  return ((to & 16) && a < b) || ((to & 8) && a > b) || ((to & 4) && a == b) ||
         ((to & 2) && static_cast<u32>(a) < static_cast<u32>(b)) ||
         ((to & 1) && static_cast<u32>(a) > static_cast<u32>(b));
}
inline bool tw_taken(const Cpu& c, Insn i) {
  return trap_cond(i.to(), static_cast<s32>(c.gpr[i.rA()]), static_cast<s32>(c.gpr[i.rB()]));
}
inline bool twi_taken(const Cpu& c, Insn i) { return trap_cond(i.to(), static_cast<s32>(c.gpr[i.rA()]), i.simm()); }

// ---- branches: condition and target only ----

// bc/bclr/bcctr condition. Decrements CTR when BO[2] is clear (never for bcctr,
// where that form is invalid).
inline bool branch_cond(Cpu& c, Insn i) {
  u32 bo = i.bo();
  bool ctr_ok = true;
  if (!(bo & 4)) {
    --c.ctr;
    ctr_ok = ((c.ctr != 0) != ((bo & 2) != 0));
  }
  bool cond_ok = (bo & 16) || (cr_bit(c, i.bi()) == ((bo >> 3) & 1));
  return ctr_ok && cond_ok;
}

}  // namespace mvp::ppc::sem
