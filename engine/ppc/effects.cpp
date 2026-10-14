#include "ppc/effects.h"

namespace mvp::ppc {

namespace {

RegSet G(u32 r) { return bit(static_cast<int>(r)); }
RegSet ra0(Insn i) { return i.rA() ? G(i.rA()) : 0; }  // rA|0 addressing
// `count` consecutive GPRs from `first`, wrapping after r31 (lswi, stswi).
RegSet run(u32 first, u32 count) {
  RegSet s = 0;
  for (u32 k = 0; k < count && k < 32; ++k) s |= G((first + k) & 31);
  return s;
}
// rD..r31 (lmw, stmw).
RegSet to_r31(u32 first) { return run(first, 32 - first); }

}  // namespace

Effects effects(Op op, Insn i) {
  Effects e;
  RegSet& R = e.reads;
  RegSet& W = e.writes;
  auto rc = [&] {
    if (i.rc()) {
      R |= bit(reg::CR) | bit(reg::SO);
      W |= bit(reg::CR);
    }
  };
  auto oe = [&] {
    if (i.oe()) {
      R |= bit(reg::SO);  // SO |= OV
      W |= bit(reg::SO);
    }
  };
  const RegSet cr = bit(reg::CR), ca = bit(reg::CA), so = bit(reg::SO);
  switch (op) {
    // ---- integer arithmetic ----
    case Op::add: case Op::subf: case Op::mullw: case Op::divw: case Op::divwu:
      R |= G(i.rA()) | G(i.rB());
      W |= G(i.rD());
      oe();
      rc();
      break;
    case Op::addc: case Op::subfc:
      R |= G(i.rA()) | G(i.rB());
      W |= G(i.rD()) | ca;
      oe();
      rc();
      break;
    case Op::adde: case Op::subfe:
      R |= G(i.rA()) | G(i.rB()) | ca;
      W |= G(i.rD()) | ca;
      oe();
      rc();
      break;
    case Op::addme: case Op::addze: case Op::subfme: case Op::subfze:
      R |= G(i.rA()) | ca;
      W |= G(i.rD()) | ca;
      oe();
      rc();
      break;
    case Op::neg:
      R |= G(i.rA());
      W |= G(i.rD());
      oe();
      rc();
      break;
    case Op::mulhw: case Op::mulhwu:
      R |= G(i.rA()) | G(i.rB());
      W |= G(i.rD());
      rc();
      break;
    case Op::addi: case Op::addis:
      R |= ra0(i);
      W |= G(i.rD());
      break;
    case Op::addic: case Op::subfic:
      R |= G(i.rA());
      W |= G(i.rD()) | ca;
      break;
    case Op::addic_rc:
      R |= G(i.rA()) | cr | so;
      W |= G(i.rD()) | ca | cr;
      break;
    case Op::mulli:
      R |= G(i.rA());
      W |= G(i.rD());
      break;

    // ---- compare ----
    case Op::cmp: case Op::cmpl:
      R |= G(i.rA()) | G(i.rB()) | cr | so;
      W |= cr;
      break;
    case Op::cmpi: case Op::cmpli:
      R |= G(i.rA()) | cr | so;
      W |= cr;
      break;

    // ---- logical, rotate, shift ----
    case Op::and_: case Op::andc: case Op::eqv: case Op::nand: case Op::nor: case Op::or_: case Op::orc:
    case Op::xor_: case Op::slw: case Op::srw: case Op::rlwnm:
      R |= G(i.rS()) | G(i.rB());
      W |= G(i.rA());
      rc();
      break;
    case Op::extsb: case Op::extsh: case Op::cntlzw: case Op::rlwinm:
      R |= G(i.rS());
      W |= G(i.rA());
      rc();
      break;
    case Op::rlwimi:
      R |= G(i.rS()) | G(i.rA());
      W |= G(i.rA());
      rc();
      break;
    case Op::ori: case Op::oris: case Op::xori: case Op::xoris:
      R |= G(i.rS());
      W |= G(i.rA());
      break;
    case Op::andi_rc: case Op::andis_rc:
      R |= G(i.rS()) | cr | so;
      W |= G(i.rA()) | cr;
      break;
    case Op::sraw:
      R |= G(i.rS()) | G(i.rB());
      W |= G(i.rA()) | ca;
      rc();
      break;
    case Op::srawi:
      R |= G(i.rS());
      W |= G(i.rA()) | ca;
      rc();
      break;

    // ---- branches: condition, target, link ----
    case Op::b:
      if (i.lk()) W |= bit(reg::LR);
      break;
    case Op::bc: case Op::bclr: case Op::bcctr:
      if (!(i.bo() & 4)) {
        R |= bit(reg::CTR);
        W |= bit(reg::CTR);
      }
      if (!(i.bo() & 16)) R |= cr;
      if (op == Op::bclr) R |= bit(reg::LR);
      if (op == Op::bcctr) R |= bit(reg::CTR);
      if (i.lk()) W |= bit(reg::LR);
      break;
    case Op::sc: case Op::rfi:
      break;
    case Op::tw:
      R |= G(i.rA()) | G(i.rB());
      break;
    case Op::twi:
      R |= G(i.rA());
      break;

    // ---- condition register ----
    case Op::crand: case Op::crandc: case Op::creqv: case Op::crnand: case Op::crnor: case Op::cror:
    case Op::crorc: case Op::crxor: case Op::mcrf: case Op::fcmpo: case Op::fcmpu: case Op::mcrfs:
    case Op::ps_cmpo0: case Op::ps_cmpo1: case Op::ps_cmpu0: case Op::ps_cmpu1:
      R |= cr;
      W |= cr;
      break;
    case Op::mcrxr:
      R |= cr | so | ca;
      W |= cr | so | ca;
      break;
    case Op::mfcr:
      R |= cr;
      W |= G(i.rD());
      break;
    case Op::mtcrf:
      R |= G(i.rS()) | cr;
      W |= cr;
      break;

    // ---- special registers ----
    case Op::mfmsr: case Op::mftb: case Op::mfsr:
      W |= G(i.rD());
      break;
    case Op::mtmsr: case Op::mtsr:
      R |= G(i.rS());
      break;
    case Op::mfsrin:
      R |= G(i.rB());
      W |= G(i.rD());
      break;
    case Op::mtsrin:
      R |= G(i.rS()) | G(i.rB());
      break;
    case Op::mfspr:
      W |= G(i.rD());
      if (i.spr() == spr::XER) R |= so | ca;
      if (i.spr() == spr::LR) R |= bit(reg::LR);
      if (i.spr() == spr::CTR) R |= bit(reg::CTR);
      break;
    case Op::mtspr:
      R |= G(i.rS());
      if (i.spr() == spr::XER) W |= so | ca;
      if (i.spr() == spr::LR) W |= bit(reg::LR);
      if (i.spr() == spr::CTR) W |= bit(reg::CTR);
      break;

    // ---- cache and synchronization ----
    case Op::dcbf: case Op::dcbi: case Op::dcbst: case Op::dcbt: case Op::dcbtst: case Op::eieio: case Op::isync:
    case Op::sync: case Op::tlbie: case Op::tlbsync:
      break;
    case Op::dcbz: case Op::dcbz_l: case Op::icbi:
      R |= ra0(i) | G(i.rB());
      break;
    case Op::eciwx: case Op::ecowx:
      R |= ra0(i) | G(i.rB()) | G(i.rD());
      W |= G(i.rD());
      break;

    // ---- integer loads ----
    case Op::lbz: case Op::lha: case Op::lhz: case Op::lwz:
      R |= ra0(i);
      W |= G(i.rD());
      break;
    case Op::lbzu: case Op::lhau: case Op::lhzu: case Op::lwzu:
      R |= G(i.rA());
      W |= G(i.rD()) | G(i.rA());
      break;
    case Op::lbzx: case Op::lhax: case Op::lhzx: case Op::lwzx: case Op::lhbrx: case Op::lwbrx: case Op::lwarx:
      R |= ra0(i) | G(i.rB());
      W |= G(i.rD());
      break;
    case Op::lbzux: case Op::lhaux: case Op::lhzux: case Op::lwzux:
      R |= G(i.rA()) | G(i.rB());
      W |= G(i.rD()) | G(i.rA());
      break;
    case Op::lmw:
      R |= ra0(i);
      W |= to_r31(i.rD());
      break;
    case Op::lswi:
      R |= ra0(i);
      W |= run(i.rD(), ((i.nb() ? i.nb() : 32) + 3) / 4);
      break;
    case Op::lswx:  // the byte count is in XER (not cached): any GPR may be written, or keep its value
      R |= kAllGprs;
      W |= kAllGprs;
      break;

    // ---- integer stores ----
    case Op::stb: case Op::sth: case Op::stw:
      R |= ra0(i) | G(i.rS());
      break;
    case Op::stbu: case Op::sthu: case Op::stwu:
      R |= G(i.rA()) | G(i.rS());
      W |= G(i.rA());
      break;
    case Op::stbx: case Op::sthx: case Op::stwx: case Op::sthbrx: case Op::stwbrx:
      R |= ra0(i) | G(i.rB()) | G(i.rS());
      break;
    case Op::stbux: case Op::sthux: case Op::stwux:
      R |= G(i.rA()) | G(i.rB()) | G(i.rS());
      W |= G(i.rA());
      break;
    case Op::stwcx_rc:
      R |= ra0(i) | G(i.rB()) | G(i.rS()) | cr | so;
      W |= cr;
      break;
    case Op::stmw:
      R |= ra0(i) | to_r31(i.rS());
      break;
    case Op::stswi:
      R |= ra0(i) | run(i.rS(), ((i.nb() ? i.nb() : 32) + 3) / 4);
      break;
    case Op::stswx:
      R |= ra0(i) | kAllGprs;
      break;

    // ---- floating-point loads and stores (FPRs are never cached) ----
    case Op::lfs: case Op::lfd: case Op::stfs: case Op::stfd: case Op::psq_l: case Op::psq_st:
      R |= ra0(i);
      break;
    case Op::lfsu: case Op::lfdu: case Op::stfsu: case Op::stfdu: case Op::psq_lu: case Op::psq_stu:
      R |= G(i.rA());
      W |= G(i.rA());
      break;
    case Op::lfsx: case Op::lfdx: case Op::stfsx: case Op::stfdx: case Op::stfiwx: case Op::psq_lx: case Op::psq_stx:
      R |= ra0(i) | G(i.rB());
      break;
    case Op::lfsux: case Op::lfdux: case Op::stfsux: case Op::stfdux: case Op::psq_lux: case Op::psq_stux:
      R |= G(i.rA()) | G(i.rB());
      W |= G(i.rA());
      break;

    // ---- floating-point arithmetic, FPSCR, paired singles: FPRs and FPSCR only ----
    default:
      break;
  }
  return e;
}

}  // namespace mvp::ppc
