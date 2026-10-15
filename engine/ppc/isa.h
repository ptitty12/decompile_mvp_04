// Gekko (PowerPC 750CL) instruction set: opcodes, encodings and field accessors.
//
// One decoder serves the disassembler, the reference interpreter, the CFG builder
// and every emitter (E0_SURVEY §5, D1). Each opcode has an encoding pattern and a
// mask covering its opcode fields and its reserved bits; a word whose reserved
// bits are not zero decodes as Op::invalid, so the translator never guesses.
#pragma once

#include <cstdint>

namespace mvp::ppc {

using u32 = std::uint32_t;
using s32 = std::int32_t;

// X(name, pattern, mask). Names with a trailing underscore avoid C++ keywords;
// `_rc` marks the record forms that exist only with Rc=1 (andi., stwcx.).
#define MVP_PPC_OPS(X)                         \
  /* integer arithmetic */                     \
  X(add, 0x7C000214, 0xFC0003FE)               \
  X(addc, 0x7C000014, 0xFC0003FE)              \
  X(adde, 0x7C000114, 0xFC0003FE)              \
  X(addi, 0x38000000, 0xFC000000)              \
  X(addic, 0x30000000, 0xFC000000)             \
  X(addic_rc, 0x34000000, 0xFC000000)          \
  X(addis, 0x3C000000, 0xFC000000)             \
  X(addme, 0x7C0001D4, 0xFC00FBFE)             \
  X(addze, 0x7C000194, 0xFC00FBFE)             \
  X(divw, 0x7C0003D6, 0xFC0003FE)              \
  X(divwu, 0x7C000396, 0xFC0003FE)             \
  X(mulhw, 0x7C000096, 0xFC0007FE)             \
  X(mulhwu, 0x7C000016, 0xFC0007FE)            \
  X(mulli, 0x1C000000, 0xFC000000)             \
  X(mullw, 0x7C0001D6, 0xFC0003FE)             \
  X(neg, 0x7C0000D0, 0xFC00FBFE)               \
  X(subf, 0x7C000050, 0xFC0003FE)              \
  X(subfc, 0x7C000010, 0xFC0003FE)             \
  X(subfe, 0x7C000110, 0xFC0003FE)             \
  X(subfic, 0x20000000, 0xFC000000)            \
  X(subfme, 0x7C0001D0, 0xFC00FBFE)            \
  X(subfze, 0x7C000190, 0xFC00FBFE)            \
  /* compare */                                \
  X(cmp, 0x7C000000, 0xFC6007FF)               \
  X(cmpi, 0x2C000000, 0xFC600000)              \
  X(cmpl, 0x7C000040, 0xFC6007FF)              \
  X(cmpli, 0x28000000, 0xFC600000)             \
  /* logical */                                \
  X(and_, 0x7C000038, 0xFC0007FE)              \
  X(andc, 0x7C000078, 0xFC0007FE)              \
  X(andi_rc, 0x70000000, 0xFC000000)           \
  X(andis_rc, 0x74000000, 0xFC000000)          \
  X(cntlzw, 0x7C000034, 0xFC00FFFE)            \
  X(eqv, 0x7C000238, 0xFC0007FE)               \
  X(extsb, 0x7C000774, 0xFC00FFFE)             \
  X(extsh, 0x7C000734, 0xFC00FFFE)             \
  X(nand, 0x7C0003B8, 0xFC0007FE)              \
  X(nor, 0x7C0000F8, 0xFC0007FE)               \
  X(or_, 0x7C000378, 0xFC0007FE)               \
  X(orc, 0x7C000338, 0xFC0007FE)               \
  X(ori, 0x60000000, 0xFC000000)               \
  X(oris, 0x64000000, 0xFC000000)              \
  X(xor_, 0x7C000278, 0xFC0007FE)              \
  X(xori, 0x68000000, 0xFC000000)              \
  X(xoris, 0x6C000000, 0xFC000000)             \
  /* rotate and shift */                       \
  X(rlwimi, 0x50000000, 0xFC000000)            \
  X(rlwinm, 0x54000000, 0xFC000000)            \
  X(rlwnm, 0x5C000000, 0xFC000000)             \
  X(slw, 0x7C000030, 0xFC0007FE)               \
  X(sraw, 0x7C000630, 0xFC0007FE)              \
  X(srawi, 0x7C000670, 0xFC0007FE)             \
  X(srw, 0x7C000430, 0xFC0007FE)               \
  /* branch and system */                      \
  X(b, 0x48000000, 0xFC000000)                 \
  X(bc, 0x40000000, 0xFC000000)                \
  X(bcctr, 0x4C000420, 0xFC00FFFE)             \
  X(bclr, 0x4C000020, 0xFC00FFFE)              \
  X(sc, 0x44000002, 0xFFFFFFFF)                \
  X(rfi, 0x4C000064, 0xFFFFFFFF)               \
  X(tw, 0x7C000008, 0xFC0007FF)                \
  X(twi, 0x0C000000, 0xFC000000)               \
  /* condition register */                     \
  X(crand, 0x4C000202, 0xFC0007FF)             \
  X(crandc, 0x4C000102, 0xFC0007FF)            \
  X(creqv, 0x4C000242, 0xFC0007FF)             \
  X(crnand, 0x4C0001C2, 0xFC0007FF)            \
  X(crnor, 0x4C000042, 0xFC0007FF)             \
  X(cror, 0x4C000382, 0xFC0007FF)              \
  X(crorc, 0x4C000342, 0xFC0007FF)             \
  X(crxor, 0x4C000182, 0xFC0007FF)             \
  X(mcrf, 0x4C000000, 0xFC63FFFF)              \
  X(mcrxr, 0x7C000400, 0xFC7FFFFF)             \
  X(mfcr, 0x7C000026, 0xFC1FFFFF)              \
  X(mtcrf, 0x7C000120, 0xFC100FFF)             \
  /* special registers */                      \
  X(mfmsr, 0x7C0000A6, 0xFC1FFFFF)             \
  X(mtmsr, 0x7C000124, 0xFC1FFFFF)             \
  X(mfspr, 0x7C0002A6, 0xFC0007FF)             \
  X(mtspr, 0x7C0003A6, 0xFC0007FF)             \
  X(mftb, 0x7C0002E6, 0xFC0007FF)              \
  X(mfsr, 0x7C0004A6, 0xFC10FFFF)              \
  X(mfsrin, 0x7C000526, 0xFC1F07FF)            \
  X(mtsr, 0x7C0001A4, 0xFC10FFFF)              \
  X(mtsrin, 0x7C0001E4, 0xFC1F07FF)            \
  /* cache, sync, TLB */                       \
  X(dcbf, 0x7C0000AC, 0xFFE007FF)              \
  X(dcbi, 0x7C0003AC, 0xFFE007FF)              \
  X(dcbst, 0x7C00006C, 0xFFE007FF)             \
  X(dcbt, 0x7C00022C, 0xFFE007FF)              \
  X(dcbtst, 0x7C0001EC, 0xFFE007FF)            \
  X(dcbz, 0x7C0007EC, 0xFFE007FF)              \
  X(dcbz_l, 0x100007EC, 0xFFE007FF)            \
  X(icbi, 0x7C0007AC, 0xFFE007FF)              \
  X(eieio, 0x7C0006AC, 0xFFFFFFFF)             \
  X(isync, 0x4C00012C, 0xFFFFFFFF)             \
  X(sync, 0x7C0004AC, 0xFFFFFFFF)              \
  X(tlbie, 0x7C000264, 0xFFFF07FF)             \
  X(tlbsync, 0x7C00046C, 0xFFFFFFFF)           \
  X(eciwx, 0x7C00026C, 0xFC0007FF)             \
  X(ecowx, 0x7C00036C, 0xFC0007FF)             \
  /* integer loads and stores */               \
  X(lbz, 0x88000000, 0xFC000000)               \
  X(lbzu, 0x8C000000, 0xFC000000)              \
  X(lbzux, 0x7C0000EE, 0xFC0007FF)             \
  X(lbzx, 0x7C0000AE, 0xFC0007FF)              \
  X(lha, 0xA8000000, 0xFC000000)               \
  X(lhau, 0xAC000000, 0xFC000000)              \
  X(lhaux, 0x7C0002EE, 0xFC0007FF)             \
  X(lhax, 0x7C0002AE, 0xFC0007FF)              \
  X(lhbrx, 0x7C00062C, 0xFC0007FF)             \
  X(lhz, 0xA0000000, 0xFC000000)               \
  X(lhzu, 0xA4000000, 0xFC000000)              \
  X(lhzux, 0x7C00026E, 0xFC0007FF)             \
  X(lhzx, 0x7C00022E, 0xFC0007FF)              \
  X(lmw, 0xB8000000, 0xFC000000)               \
  X(lswi, 0x7C0004AA, 0xFC0007FF)              \
  X(lswx, 0x7C00042A, 0xFC0007FF)              \
  X(lwarx, 0x7C000028, 0xFC0007FF)             \
  X(lwbrx, 0x7C00042C, 0xFC0007FF)             \
  X(lwz, 0x80000000, 0xFC000000)               \
  X(lwzu, 0x84000000, 0xFC000000)              \
  X(lwzux, 0x7C00006E, 0xFC0007FF)             \
  X(lwzx, 0x7C00002E, 0xFC0007FF)              \
  X(stb, 0x98000000, 0xFC000000)               \
  X(stbu, 0x9C000000, 0xFC000000)              \
  X(stbux, 0x7C0001EE, 0xFC0007FF)             \
  X(stbx, 0x7C0001AE, 0xFC0007FF)              \
  X(sth, 0xB0000000, 0xFC000000)               \
  X(sthbrx, 0x7C00072C, 0xFC0007FF)            \
  X(sthu, 0xB4000000, 0xFC000000)              \
  X(sthux, 0x7C00036E, 0xFC0007FF)             \
  X(sthx, 0x7C00032E, 0xFC0007FF)              \
  X(stmw, 0xBC000000, 0xFC000000)              \
  X(stswi, 0x7C0005AA, 0xFC0007FF)             \
  X(stswx, 0x7C00052A, 0xFC0007FF)             \
  X(stw, 0x90000000, 0xFC000000)               \
  X(stwbrx, 0x7C00052C, 0xFC0007FF)            \
  X(stwcx_rc, 0x7C00012D, 0xFC0007FF)          \
  X(stwu, 0x94000000, 0xFC000000)              \
  X(stwux, 0x7C00016E, 0xFC0007FF)             \
  X(stwx, 0x7C00012E, 0xFC0007FF)              \
  /* floating-point loads and stores */        \
  X(lfd, 0xC8000000, 0xFC000000)               \
  X(lfdu, 0xCC000000, 0xFC000000)              \
  X(lfdux, 0x7C0004EE, 0xFC0007FF)             \
  X(lfdx, 0x7C0004AE, 0xFC0007FF)              \
  X(lfs, 0xC0000000, 0xFC000000)               \
  X(lfsu, 0xC4000000, 0xFC000000)              \
  X(lfsux, 0x7C00046E, 0xFC0007FF)             \
  X(lfsx, 0x7C00042E, 0xFC0007FF)              \
  X(stfd, 0xD8000000, 0xFC000000)              \
  X(stfdu, 0xDC000000, 0xFC000000)             \
  X(stfdux, 0x7C0005EE, 0xFC0007FF)            \
  X(stfdx, 0x7C0005AE, 0xFC0007FF)             \
  X(stfiwx, 0x7C0007AE, 0xFC0007FF)            \
  X(stfs, 0xD0000000, 0xFC000000)              \
  X(stfsu, 0xD4000000, 0xFC000000)             \
  X(stfsux, 0x7C00056E, 0xFC0007FF)            \
  X(stfsx, 0x7C00052E, 0xFC0007FF)             \
  /* floating-point arithmetic */              \
  X(fabs, 0xFC000210, 0xFC1F07FE)              \
  X(fadd, 0xFC00002A, 0xFC0007FE)              \
  X(fadds, 0xEC00002A, 0xFC0007FE)             \
  X(fcmpo, 0xFC000040, 0xFC6007FF)             \
  X(fcmpu, 0xFC000000, 0xFC6007FF)             \
  X(fctiw, 0xFC00001C, 0xFC1F07FE)             \
  X(fctiwz, 0xFC00001E, 0xFC1F07FE)            \
  X(fdiv, 0xFC000024, 0xFC0007FE)              \
  X(fdivs, 0xEC000024, 0xFC0007FE)             \
  X(fmadd, 0xFC00003A, 0xFC00003E)             \
  X(fmadds, 0xEC00003A, 0xFC00003E)            \
  X(fmr, 0xFC000090, 0xFC1F07FE)               \
  X(fmsub, 0xFC000038, 0xFC00003E)             \
  X(fmsubs, 0xEC000038, 0xFC00003E)            \
  X(fmul, 0xFC000032, 0xFC00F83E)              \
  X(fmuls, 0xEC000032, 0xFC00F83E)             \
  X(fnabs, 0xFC000110, 0xFC1F07FE)             \
  X(fneg, 0xFC000050, 0xFC1F07FE)              \
  X(fnmadd, 0xFC00003E, 0xFC00003E)            \
  X(fnmadds, 0xEC00003E, 0xFC00003E)           \
  X(fnmsub, 0xFC00003C, 0xFC00003E)            \
  X(fnmsubs, 0xEC00003C, 0xFC00003E)           \
  X(fres, 0xEC000030, 0xFC1F07FE)              \
  X(frsp, 0xFC000018, 0xFC1F07FE)              \
  X(frsqrte, 0xFC000034, 0xFC1F07FE)           \
  X(fsel, 0xFC00002E, 0xFC00003E)              \
  X(fsub, 0xFC000028, 0xFC0007FE)              \
  X(fsubs, 0xEC000028, 0xFC0007FE)             \
  /* FPSCR */                                  \
  X(mcrfs, 0xFC000080, 0xFC63FFFF)             \
  X(mffs, 0xFC00048E, 0xFC1FFFFE)              \
  X(mtfsb0, 0xFC00008C, 0xFC1FFFFE)            \
  X(mtfsb1, 0xFC00004C, 0xFC1FFFFE)            \
  X(mtfsf, 0xFC00058E, 0xFE0107FE)             \
  X(mtfsfi, 0xFC00010C, 0xFC7F0FFE)            \
  /* paired singles */                         \
  X(psq_l, 0xE0000000, 0xFC000000)             \
  X(psq_lu, 0xE4000000, 0xFC000000)            \
  X(psq_lux, 0x1000004C, 0xFC00007F)           \
  X(psq_lx, 0x1000000C, 0xFC00007F)            \
  X(psq_st, 0xF0000000, 0xFC000000)            \
  X(psq_stu, 0xF4000000, 0xFC000000)           \
  X(psq_stux, 0x1000004E, 0xFC00007F)          \
  X(psq_stx, 0x1000000E, 0xFC00007F)           \
  X(ps_abs, 0x10000210, 0xFC1F07FE)            \
  X(ps_add, 0x1000002A, 0xFC0007FE)            \
  X(ps_cmpo0, 0x10000040, 0xFC6007FF)          \
  X(ps_cmpo1, 0x100000C0, 0xFC6007FF)          \
  X(ps_cmpu0, 0x10000000, 0xFC6007FF)          \
  X(ps_cmpu1, 0x10000080, 0xFC6007FF)          \
  X(ps_div, 0x10000024, 0xFC0007FE)            \
  X(ps_madd, 0x1000003A, 0xFC00003E)           \
  X(ps_madds0, 0x1000001C, 0xFC00003E)         \
  X(ps_madds1, 0x1000001E, 0xFC00003E)         \
  X(ps_merge00, 0x10000420, 0xFC0007FE)        \
  X(ps_merge01, 0x10000460, 0xFC0007FE)        \
  X(ps_merge10, 0x100004A0, 0xFC0007FE)        \
  X(ps_merge11, 0x100004E0, 0xFC0007FE)        \
  X(ps_mr, 0x10000090, 0xFC1F07FE)             \
  X(ps_msub, 0x10000038, 0xFC00003E)           \
  X(ps_mul, 0x10000032, 0xFC00F83E)            \
  X(ps_muls0, 0x10000018, 0xFC00F83E)          \
  X(ps_muls1, 0x1000001A, 0xFC00F83E)          \
  X(ps_nabs, 0x10000110, 0xFC1F07FE)           \
  X(ps_neg, 0x10000050, 0xFC1F07FE)            \
  X(ps_nmadd, 0x1000003E, 0xFC00003E)          \
  X(ps_nmsub, 0x1000003C, 0xFC00003E)          \
  X(ps_res, 0x10000030, 0xFC1F07FE)            \
  X(ps_rsqrte, 0x10000034, 0xFC1F07FE)         \
  X(ps_sel, 0x1000002E, 0xFC00003E)            \
  X(ps_sub, 0x10000028, 0xFC0007FE)            \
  X(ps_sum0, 0x10000014, 0xFC00003E)           \
  X(ps_sum1, 0x10000016, 0xFC00003E)

enum class Op : std::uint16_t {
  invalid,
#define MVP_X(name, pattern, mask) name,
  MVP_PPC_OPS(MVP_X)
#undef MVP_X
      count
};

// Instructions that need the FPU: floating-point loads and stores, arithmetic,
// moves, compares, FPSCR moves and every paired-single instruction (lfd through
// ps_sum1 in the table above). With MSR[FP] clear they do not run: they raise the
// floating-point unavailable exception (vector 0x800), which the OS uses to switch
// FPU contexts lazily (OSSetCurrentContext clears MSR[FP] for a thread that does
// not own the FPU).
inline bool uses_fpu(Op op) { return op >= Op::lfd && op <= Op::ps_sum1; }

struct OpInfo {
  const char* name;  // base mnemonic as the ISA spells it ("andi.", "stwcx.")
  u32 pattern;
  u32 mask;
};

const OpInfo& op_info(Op op);
inline const char* op_name(Op op) { return op_info(op).name; }

// Decodes one instruction word. Words with nonzero reserved bits, and opcodes the
// Gekko does not implement, give Op::invalid.
Op decode(u32 word);

// Field accessors, named as in the PowerPC manuals (bit 0 = most significant).
struct Insn {
  u32 w = 0;

  u32 opcd() const { return w >> 26; }
  u32 rD() const { return (w >> 21) & 31; }
  u32 rS() const { return (w >> 21) & 31; }
  u32 rA() const { return (w >> 16) & 31; }
  u32 rB() const { return (w >> 11) & 31; }
  u32 rC() const { return (w >> 6) & 31; }  // frC
  s32 simm() const { return static_cast<std::int16_t>(w & 0xFFFF); }
  u32 uimm() const { return w & 0xFFFF; }
  bool rc() const { return (w & 1) != 0; }
  bool oe() const { return ((w >> 10) & 1) != 0; }
  bool lk() const { return (w & 1) != 0; }
  bool aa() const { return ((w >> 1) & 1) != 0; }
  u32 bo() const { return (w >> 21) & 31; }
  u32 bi() const { return (w >> 16) & 31; }
  s32 bd() const { return static_cast<std::int16_t>(w & 0xFFFC); }
  s32 li() const {
    u32 v = w & 0x03FFFFFC;
    return static_cast<s32>((v & 0x02000000) ? (v | 0xFC000000) : v);
  }
  u32 sh() const { return (w >> 11) & 31; }
  u32 mb() const { return (w >> 6) & 31; }
  u32 me() const { return (w >> 1) & 31; }
  u32 crfD() const { return (w >> 23) & 7; }
  u32 crfS() const { return (w >> 18) & 7; }
  u32 crbD() const { return (w >> 21) & 31; }
  u32 crbA() const { return (w >> 16) & 31; }
  u32 crbB() const { return (w >> 11) & 31; }
  u32 crm() const { return (w >> 12) & 0xFF; }
  u32 fm() const { return (w >> 17) & 0xFF; }
  u32 spr() const { return ((w >> 16) & 31) | (((w >> 11) & 31) << 5); }
  u32 tbr() const { return spr(); }
  u32 sr() const { return (w >> 16) & 15; }
  u32 nb() const { return (w >> 11) & 31; }
  u32 to() const { return (w >> 21) & 31; }
  u32 mtfsfi_imm() const { return (w >> 12) & 15; }
  // psq_l / psq_st / psq_lu / psq_stu: 12-bit displacement, W and I fields.
  s32 ps_d() const { return static_cast<s32>(static_cast<std::int32_t>((w & 0xFFF) << 20) >> 20); }
  u32 ps_w() const { return (w >> 15) & 1; }
  u32 ps_i() const { return (w >> 12) & 7; }
  // psq_lx / psq_stx / psq_lux / psq_stux.
  u32 psx_w() const { return (w >> 10) & 1; }
  u32 psx_i() const { return (w >> 7) & 7; }
};

// Rotate mask MASK(mb, me): ones from bit mb through bit me, wrapping when mb > me.
inline u32 rot_mask(u32 mb, u32 me) {
  u32 a = 0xFFFFFFFFu >> mb;
  u32 b = 0xFFFFFFFFu << (31 - me);
  return mb <= me ? (a & b) : (a | b);
}

// Special-purpose register numbers the runtime and disassembler name.
namespace spr {
inline constexpr u32 XER = 1, LR = 8, CTR = 9, DSISR = 18, DAR = 19, DEC = 22, SDR1 = 25, SRR0 = 26, SRR1 = 27,
                     SPRG0 = 272, EAR = 282, TBL_R = 268, TBU_R = 269, TBL_W = 284, TBU_W = 285, PVR = 287,
                     IBAT0U = 528, DBAT0U = 536, GQR0 = 912, HID2 = 920, WPAR = 921, DMA_U = 922, DMA_L = 923,
                     UMMCR0 = 936, UPMC1 = 937, UPMC2 = 938, USIA = 939, UMMCR1 = 940, UPMC3 = 941, UPMC4 = 942,
                     USDA = 943, MMCR0 = 952, PMC1 = 953, PMC2 = 954, SIA = 955, MMCR1 = 956, PMC3 = 957,
                     PMC4 = 958, SDA = 959, HID0 = 1008, HID1 = 1009, IABR = 1010, DABR = 1013, L2CR = 1017,
                     ICTC = 1019, THRM1 = 1020, THRM2 = 1021, THRM3 = 1022;
}  // namespace spr

}  // namespace mvp::ppc
