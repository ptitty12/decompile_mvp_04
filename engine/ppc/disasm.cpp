#include "ppc/disasm.h"

#include <cstdio>

namespace mvp::ppc {

namespace {

std::string hex_s(s32 v) {
  char b[16];
  if (v < 0)
    std::snprintf(b, sizeof b, "-0x%x", static_cast<unsigned>(-static_cast<long long>(v)));
  else
    std::snprintf(b, sizeof b, "0x%x", static_cast<unsigned>(v));
  return b;
}
std::string hex_u(u32 v) {
  char b[16];
  std::snprintf(b, sizeof b, "0x%x", v);
  return b;
}
std::string dec(u32 v) { return std::to_string(v); }
std::string r(u32 n) { return "r" + std::to_string(n); }
std::string f(u32 n) { return "f" + std::to_string(n); }
std::string cr(u32 n) { return "cr" + std::to_string(n); }
std::string qr(u32 n) { return "qr" + std::to_string(n); }
std::string mem(s32 d, u32 ra) { return hex_s(d) + "(" + r(ra) + ")"; }

std::string join(std::initializer_list<std::string> args) {
  std::string s;
  for (const auto& a : args) {
    if (!s.empty()) s += ", ";
    s += a;
  }
  return s;
}

std::string line(const std::string& mnemonic, const std::string& args) {
  return args.empty() ? mnemonic : mnemonic + " " + args;
}

// Suffixes in ISA order: o (OE), . (Rc).
std::string oe_rc(const char* base, const Insn& i, bool has_oe) {
  std::string m = base;
  if (has_oe && i.oe()) m += "o";
  if (i.rc()) m += ".";
  return m;
}
std::string rc(const char* base, const Insn& i) {
  std::string m = base;
  if (i.rc()) m += ".";
  return m;
}

const char* kCond[4] = {"lt", "gt", "eq", "un"};

std::string branch_target(const Insn& i, u32 addr, s32 disp) {
  u32 t = i.aa() ? static_cast<u32>(disp) : addr + static_cast<u32>(disp);
  return hex_u(t);
}

// bc / bclr / bcctr simplified mnemonics. `kind` is "" (bc), "lr" or "ctr".
std::string cond_branch(const Insn& i, u32 addr, const char* kind) {
  u32 bo = i.bo(), bi = i.bi();
  bool is_bc = kind[0] == 0;
  std::string target = is_bc ? branch_target(i, addr, i.bd()) : "";
  std::string base;
  std::string args;
  u32 bo4 = bo & 0x1E;
  auto with_target = [&](std::string a) {
    if (!is_bc) return a;
    return a.empty() ? target : a + ", " + target;
  };
  static const char* kTrue[4] = {"lt", "gt", "eq", "so"};
  static const char* kFalse[4] = {"ge", "le", "ne", "ns"};
  if (bo == 20 && bi == 0 && !is_bc) {
    base = kind[0] == 'l' ? "blr" : "bctr";
  } else if (bo4 == 12 || bo4 == 4) {
    base = std::string("b") + (bo4 == 12 ? kTrue[bi & 3] : kFalse[bi & 3]) + kind;
    args = with_target(bi < 4 ? "" : cr(bi >> 2));
  } else if (bo4 == 16 && bi == 0) {
    base = std::string("bdnz") + kind;
    args = with_target("");
  } else if (bo4 == 18 && bi == 0) {
    base = std::string("bdz") + kind;
    args = with_target("");
  } else if (bo4 == 0 || bo4 == 2 || bo4 == 8 || bo4 == 10) {
    const char* ctr = bo4 == 0 ? "bdnzf" : bo4 == 2 ? "bdzf" : bo4 == 8 ? "bdnzt" : "bdzt";
    base = std::string(ctr) + kind;
    args = with_target(cr_bit_name(bi));
  } else {
    base = std::string("bc") + kind;
    args = with_target(join({dec(bo), cr_bit_name(bi)}));
  }
  if (i.lk()) base += "l";
  if (is_bc && i.aa()) base += "a";
  // Branch prediction hint: the y bit (BO's low bit). For bc the sign of the
  // displacement says which way the static prediction was reversed.
  if (bo & 1) base += (is_bc && i.bd() < 0) ? "-" : "+";
  return line(base, args);
}

std::string rlwinm_text(const Insn& i) {
  u32 sh = i.sh(), mb = i.mb(), me = i.me();
  const char* dot = i.rc() ? "." : "";
  std::string ra = r(i.rA()), rs = r(i.rS());
  auto m = [&](const char* name) { return std::string(name) + dot; };
  if (sh == 0 && mb == 0) return line(m("clrrwi"), join({ra, rs, dec(31 - me)}));
  if (sh == 0 && me == 31) return line(m("clrlwi"), join({ra, rs, dec(mb)}));
  if (mb == 0 && me == 31 && sh <= 16) return line(m("rotlwi"), join({ra, rs, dec(sh)}));
  if (mb == 0 && me == 31 && sh > 16) return line(m("rotrwi"), join({ra, rs, dec(32 - sh)}));
  if (mb == 0 && me == 31 - sh) return line(m("slwi"), join({ra, rs, dec(sh)}));
  if (me == 31 && sh == 32 - mb) return line(m("srwi"), join({ra, rs, dec(mb)}));
  if (sh < 32 && me == 31 - sh) return line(m("clrlslwi"), join({ra, rs, dec(mb + sh), dec(sh)}));
  if (mb == 0) return line(m("extlwi"), join({ra, rs, dec(me + 1), dec(sh)}));
  if (me == 31 && sh >= 32 - mb) return line(m("extrwi"), join({ra, rs, dec(32 - mb), dec(sh - (32 - mb))}));
  return line(m("rlwinm"), join({ra, rs, dec(sh), dec(mb), dec(me)}));
}

std::string spr_text(u32 n) {
  const char* name = spr_name(n);
  return name ? std::string(name) : dec(n);
}

std::string mfspr_text(const Insn& i) {
  u32 n = i.spr();
  std::string rd = r(i.rD());
  switch (n) {
    case spr::XER: return line("mfxer", rd);
    case spr::LR: return line("mflr", rd);
    case spr::CTR: return line("mfctr", rd);
    case spr::DSISR: return line("mfdsisr", rd);
    case spr::DAR: return line("mfdar", rd);
    case spr::DEC: return line("mfdec", rd);
    case spr::SDR1: return line("mfsdr1", rd);
    case spr::SRR0: return line("mfsrr0", rd);
    case spr::SRR1: return line("mfsrr1", rd);
    case spr::EAR: return line("mfear", rd);
    default: break;
  }
  if ((n & 0x3FC) == spr::SPRG0) return line("mfsprg", join({rd, dec(n & 3)}));
  if ((n & 0x3F9) == 528) return line("mfibatu", join({rd, dec((n >> 1) & 3)}));
  if ((n & 0x3F9) == 529) return line("mfibatl", join({rd, dec((n >> 1) & 3)}));
  if ((n & 0x3F9) == 536) return line("mfdbatu", join({rd, dec((n >> 1) & 3)}));
  if ((n & 0x3F9) == 537) return line("mfdbatl", join({rd, dec((n >> 1) & 3)}));
  return line("mfspr", join({rd, spr_text(n)}));
}

std::string mtspr_text(const Insn& i) {
  u32 n = i.spr();
  std::string rs = r(i.rS());
  switch (n) {
    case spr::XER: return line("mtxer", rs);
    case spr::LR: return line("mtlr", rs);
    case spr::CTR: return line("mtctr", rs);
    case spr::DSISR: return line("mtdsisr", rs);
    case spr::DAR: return line("mtdar", rs);
    case spr::DEC: return line("mtdec", rs);
    case spr::SDR1: return line("mtsdr1", rs);
    case spr::SRR0: return line("mtsrr0", rs);
    case spr::SRR1: return line("mtsrr1", rs);
    case spr::EAR: return line("mtear", rs);
    case spr::TBL_W: return line("mttbl", rs);
    case spr::TBU_W: return line("mttbu", rs);
    default: break;
  }
  if ((n & 0x3FC) == spr::SPRG0) return line("mtsprg", join({dec(n & 3), rs}));
  if ((n & 0x3F9) == 528) return line("mtibatu", join({dec((n >> 1) & 3), rs}));
  if ((n & 0x3F9) == 529) return line("mtibatl", join({dec((n >> 1) & 3), rs}));
  if ((n & 0x3F9) == 536) return line("mtdbatu", join({dec((n >> 1) & 3), rs}));
  if ((n & 0x3F9) == 537) return line("mtdbatl", join({dec((n >> 1) & 3), rs}));
  return line("mtspr", join({spr_text(n), rs}));
}

}  // namespace

std::string cr_bit_name(u32 bit) {
  u32 field = bit >> 2;
  return field == 0 ? std::string(kCond[bit & 3]) : cr(field) + kCond[bit & 3];
}

const char* spr_name(u32 n) {
  switch (n) {
    case spr::XER: return "XER";
    case spr::LR: return "LR";
    case spr::CTR: return "CTR";
    case spr::DSISR: return "DSISR";
    case spr::DAR: return "DAR";
    case spr::DEC: return "DEC";
    case spr::SDR1: return "SDR1";
    case spr::SRR0: return "SRR0";
    case spr::SRR1: return "SRR1";
    case spr::EAR: return "EAR";
    case spr::PVR: return "PVR";
    case spr::HID0: return "HID0";
    case spr::HID1: return "HID1";
    case spr::HID2: return "HID2";
    case spr::IABR: return "IABR";
    case spr::DABR: return "DABR";
    case spr::L2CR: return "L2CR";
    case spr::ICTC: return "ICTC";
    case spr::THRM1: return "THRM1";
    case spr::THRM2: return "THRM2";
    case spr::THRM3: return "THRM3";
    case spr::WPAR: return "WPAR";
    case spr::DMA_U: return "DMA_U";
    case spr::DMA_L: return "DMA_L";
    case spr::MMCR0: return "MMCR0";
    case spr::MMCR1: return "MMCR1";
    case spr::PMC1: return "PMC1";
    case spr::PMC2: return "PMC2";
    case spr::PMC3: return "PMC3";
    case spr::PMC4: return "PMC4";
    case spr::SIA: return "SIA";
    case spr::SDA: return "SDA";
    case spr::UMMCR0: return "UMMCR0";
    case spr::UMMCR1: return "UMMCR1";
    case spr::UPMC1: return "UPMC1";
    case spr::UPMC2: return "UPMC2";
    case spr::UPMC3: return "UPMC3";
    case spr::UPMC4: return "UPMC4";
    case spr::USIA: return "USIA";
    case spr::USDA: return "USDA";
    default: break;
  }
  if (n >= spr::GQR0 && n < spr::GQR0 + 8) {
    static const char* g[8] = {"GQR0", "GQR1", "GQR2", "GQR3", "GQR4", "GQR5", "GQR6", "GQR7"};
    return g[n - spr::GQR0];
  }
  return nullptr;
}

std::string disasm(u32 w, u32 addr) {
  Insn i{w};
  Op op = decode(w);
  const char* name = op_name(op);
  std::string rd = r(i.rD()), ra = r(i.rA()), rb = r(i.rB()), rs = r(i.rS());
  std::string fd = f(i.rD()), fa = f(i.rA()), fb = f(i.rB()), fc = f(i.rC());
  switch (op) {
    case Op::invalid: {
      char b[48];
      std::snprintf(b, sizeof b, ".4byte 0x%08X /* invalid */", w);
      return b;
    }
    // D-form arithmetic with simplified forms.
    case Op::addi:
      if (i.rA() == 0) return line("li", join({rd, hex_s(i.simm())}));
      if (i.simm() < 0 && i.simm() != -0x8000) return line("subi", join({rd, ra, hex_s(-i.simm())}));
      return line(name, join({rd, ra, hex_s(i.simm())}));
    case Op::addis:
      if (i.rA() == 0) return line("lis", join({rd, hex_u(i.uimm())}));
      if (i.simm() < 0 && i.simm() != -0x8000) return line("subis", join({rd, ra, hex_s(-i.simm())}));
      return line(name, join({rd, ra, hex_u(i.uimm())}));  // dtk shows addis operands unsigned
    case Op::addic:
    case Op::addic_rc: {
      bool neg = i.simm() < 0 && i.simm() != -0x8000;
      const char* n = op == Op::addic ? (neg ? "subic" : "addic") : (neg ? "subic." : "addic.");
      return line(n, join({rd, ra, hex_s(neg ? -i.simm() : i.simm())}));
    }
    case Op::mulli:
    case Op::subfic:
      return line(name, join({rd, ra, hex_s(i.simm())}));
    // XO-form arithmetic.
    case Op::add: case Op::addc: case Op::adde: case Op::divw: case Op::divwu: case Op::mullw:
    case Op::subf: case Op::subfc: case Op::subfe:
      return line(oe_rc(name, i, true), join({rd, ra, rb}));
    case Op::mulhw: case Op::mulhwu:
      return line(rc(name, i), join({rd, ra, rb}));
    case Op::addme: case Op::addze: case Op::neg: case Op::subfme: case Op::subfze:
      return line(oe_rc(name, i, true), join({rd, ra}));
    // Compare.
    case Op::cmp: case Op::cmpl: case Op::cmpi: case Op::cmpli: {
      const char* n = op == Op::cmp ? "cmpw" : op == Op::cmpl ? "cmplw" : op == Op::cmpi ? "cmpwi" : "cmplwi";
      std::string last = op == Op::cmp || op == Op::cmpl ? rb : op == Op::cmpi ? hex_s(i.simm()) : hex_u(i.uimm());
      if (i.crfD() == 0) return line(n, join({ra, last}));
      return line(n, join({cr(i.crfD()), ra, last}));
    }
    // Logical.
    case Op::or_:
      if (i.rB() == i.rS()) return line(i.rc() ? "mr." : "mr", join({ra, rs}));
      return line(rc(name, i), join({ra, rs, rb}));
    case Op::and_: case Op::andc: case Op::eqv: case Op::nand: case Op::nor: case Op::orc: case Op::xor_:
    case Op::slw: case Op::sraw: case Op::srw:
      return line(rc(name, i), join({ra, rs, rb}));
    case Op::cntlzw: case Op::extsb: case Op::extsh:
      return line(rc(name, i), join({ra, rs}));
    case Op::ori:
      if (i.rA() == 0 && i.rS() == 0 && i.uimm() == 0) return "nop";
      return line(name, join({ra, rs, hex_u(i.uimm())}));
    case Op::oris: case Op::xori: case Op::xoris: case Op::andi_rc: case Op::andis_rc:
      return line(name, join({ra, rs, hex_u(i.uimm())}));
    case Op::srawi:
      return line(rc(name, i), join({ra, rs, dec(i.sh())}));
    // Rotate.
    case Op::rlwinm:
      return rlwinm_text(i);
    case Op::rlwnm:
      if (i.mb() == 0 && i.me() == 31) return line(rc("rotlw", i), join({ra, rs, rb}));
      return line(rc(name, i), join({ra, rs, rb, dec(i.mb()), dec(i.me())}));
    case Op::rlwimi:
      return line(rc(name, i), join({ra, rs, dec(i.sh()), dec(i.mb()), dec(i.me())}));
    // Branches.
    case Op::b: {
      std::string m = "b";
      if (i.lk()) m += "l";
      if (i.aa()) m += "a";
      return line(m, branch_target(i, addr, i.li()));
    }
    case Op::bc: return cond_branch(i, addr, "");
    case Op::bclr: return cond_branch(i, addr, "lr");
    case Op::bcctr: return cond_branch(i, addr, "ctr");
    case Op::sc: case Op::rfi: case Op::isync: case Op::sync: case Op::eieio: case Op::tlbsync:
      return name;
    case Op::tw:
      return line(name, join({dec(i.to()), ra, rb}));
    case Op::twi:
      return line(name, join({dec(i.to()), ra, hex_s(i.simm())}));
    // Condition register.
    case Op::crxor:
      if (i.crbA() == i.crbD() && i.crbB() == i.crbD()) return line("crclr", cr_bit_name(i.crbD()));
      return line(name, join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA()), cr_bit_name(i.crbB())}));
    case Op::creqv:
      if (i.crbA() == i.crbD() && i.crbB() == i.crbD()) return line("crset", cr_bit_name(i.crbD()));
      return line(name, join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA()), cr_bit_name(i.crbB())}));
    case Op::cror:
      if (i.crbB() == i.crbA()) return line("crmove", join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA())}));
      return line(name, join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA()), cr_bit_name(i.crbB())}));
    case Op::crnor:
      if (i.crbB() == i.crbA()) return line("crnot", join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA())}));
      return line(name, join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA()), cr_bit_name(i.crbB())}));
    case Op::crand: case Op::crandc: case Op::crnand: case Op::crorc:
      return line(name, join({cr_bit_name(i.crbD()), cr_bit_name(i.crbA()), cr_bit_name(i.crbB())}));
    case Op::mcrf: case Op::mcrfs:
      return line(name, join({cr(i.crfD()), cr(i.crfS())}));
    case Op::mcrxr:
      return line(name, cr(i.crfD()));
    case Op::mfcr: case Op::mfmsr:
      return line(name, rd);
    case Op::mtmsr:
      return line(name, rs);
    case Op::mtcrf:
      return line(name, join({dec(i.crm()), rs}));
    // Special registers.
    case Op::mfspr: return mfspr_text(i);
    case Op::mtspr: return mtspr_text(i);
    case Op::mftb: return line(name, join({rd, dec(i.tbr())}));
    case Op::mfsr: return line(name, join({rd, dec(i.sr())}));
    case Op::mtsr: return line(name, join({dec(i.sr()), rs}));
    case Op::mfsrin: return line(name, join({rd, rb}));
    case Op::mtsrin: return line(name, join({rs, rb}));
    // Cache and TLB.
    case Op::dcbf: case Op::dcbi: case Op::dcbst: case Op::dcbt: case Op::dcbtst: case Op::dcbz:
    case Op::dcbz_l: case Op::icbi:
      return line(name, join({ra, rb}));
    case Op::tlbie:
      return line(name, rb);
    // Integer loads and stores.
    case Op::lbz: case Op::lbzu: case Op::lha: case Op::lhau: case Op::lhz: case Op::lhzu: case Op::lmw:
    case Op::lwz: case Op::lwzu:
      return line(name, join({rd, mem(i.simm(), i.rA())}));
    case Op::stb: case Op::stbu: case Op::sth: case Op::sthu: case Op::stmw: case Op::stw: case Op::stwu:
      return line(name, join({rs, mem(i.simm(), i.rA())}));
    case Op::lbzux: case Op::lbzx: case Op::lhaux: case Op::lhax: case Op::lhbrx: case Op::lhzux: case Op::lhzx:
    case Op::lswx: case Op::lwarx: case Op::lwbrx: case Op::lwzux: case Op::lwzx: case Op::eciwx:
      return line(name, join({rd, ra, rb}));
    case Op::stbux: case Op::stbx: case Op::sthbrx: case Op::sthux: case Op::sthx: case Op::stswx: case Op::stwbrx:
    case Op::stwcx_rc: case Op::stwux: case Op::stwx: case Op::ecowx:
      return line(name, join({rs, ra, rb}));
    case Op::lswi: return line(name, join({rd, ra, dec(i.nb())}));
    case Op::stswi: return line(name, join({rs, ra, dec(i.nb())}));
    // Floating-point loads and stores.
    case Op::lfd: case Op::lfdu: case Op::lfs: case Op::lfsu:
    case Op::stfd: case Op::stfdu: case Op::stfs: case Op::stfsu:
      return line(name, join({fd, mem(i.simm(), i.rA())}));
    case Op::lfdux: case Op::lfdx: case Op::lfsux: case Op::lfsx:
    case Op::stfdux: case Op::stfdx: case Op::stfiwx: case Op::stfsux: case Op::stfsx:
      return line(name, join({fd, ra, rb}));
    // Floating-point arithmetic.
    case Op::fadd: case Op::fadds: case Op::fdiv: case Op::fdivs: case Op::fsub: case Op::fsubs:
    case Op::ps_add: case Op::ps_div: case Op::ps_sub:
    case Op::ps_merge00: case Op::ps_merge01: case Op::ps_merge10: case Op::ps_merge11:
      return line(rc(name, i), join({fd, fa, fb}));
    case Op::fmul: case Op::fmuls: case Op::ps_mul: case Op::ps_muls0: case Op::ps_muls1:
      return line(rc(name, i), join({fd, fa, fc}));
    case Op::fmadd: case Op::fmadds: case Op::fmsub: case Op::fmsubs: case Op::fnmadd: case Op::fnmadds:
    case Op::fnmsub: case Op::fnmsubs: case Op::fsel:
    case Op::ps_madd: case Op::ps_madds0: case Op::ps_madds1: case Op::ps_msub: case Op::ps_nmadd:
    case Op::ps_nmsub: case Op::ps_sel: case Op::ps_sum0: case Op::ps_sum1:
      return line(rc(name, i), join({fd, fa, fc, fb}));
    case Op::fabs: case Op::fctiw: case Op::fctiwz: case Op::fmr: case Op::fnabs: case Op::fneg: case Op::fres:
    case Op::frsp: case Op::frsqrte:
    case Op::ps_abs: case Op::ps_mr: case Op::ps_nabs: case Op::ps_neg: case Op::ps_res: case Op::ps_rsqrte:
      return line(rc(name, i), join({fd, fb}));
    case Op::fcmpo: case Op::fcmpu: case Op::ps_cmpo0: case Op::ps_cmpo1: case Op::ps_cmpu0: case Op::ps_cmpu1:
      return line(name, join({cr(i.crfD()), fa, fb}));
    // FPSCR.
    case Op::mffs: return line(rc(name, i), fd);
    case Op::mtfsb0: case Op::mtfsb1: return line(rc(name, i), cr_bit_name(i.crbD()));
    case Op::mtfsf: return line(rc(name, i), join({dec(i.fm()), fb}));
    case Op::mtfsfi: return line(rc(name, i), join({cr(i.crfD()), dec(i.mtfsfi_imm())}));
    // Paired-single loads and stores.
    case Op::psq_l: case Op::psq_lu: case Op::psq_st: case Op::psq_stu:
      return line(name, join({fd, mem(i.ps_d(), i.rA()), dec(i.ps_w()), qr(i.ps_i())}));
    case Op::psq_lx: case Op::psq_lux: case Op::psq_stx: case Op::psq_stux:
      return line(name, join({fd, ra, rb, dec(i.psx_w()), qr(i.psx_i())}));
    case Op::count: break;
  }
  return name;
}

}  // namespace mvp::ppc
