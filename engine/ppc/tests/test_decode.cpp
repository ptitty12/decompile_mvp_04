// Data-free decoder and disassembler vectors. Encodings are built from fields here
// (no game bytes); expected text follows decomp-toolkit's listing conventions.
#include <doctest/doctest.h>

#include <string>

#include "ppc/disasm.h"

using namespace mvp::ppc;

namespace {

u32 D(u32 op, u32 rt, u32 ra, s32 imm) { return op << 26 | rt << 21 | ra << 16 | (static_cast<u32>(imm) & 0xFFFF); }
u32 X(u32 op, u32 rt, u32 ra, u32 rb, u32 xo, u32 rc = 0) {
  return op << 26 | rt << 21 | ra << 16 | rb << 11 | xo << 1 | rc;
}
u32 XO(u32 rt, u32 ra, u32 rb, u32 oe, u32 xo, u32 rc = 0) {
  return 31u << 26 | rt << 21 | ra << 16 | rb << 11 | oe << 10 | xo << 1 | rc;
}
u32 A(u32 op, u32 ft, u32 fa, u32 fb, u32 fc, u32 xo, u32 rc = 0) {
  return op << 26 | ft << 21 | fa << 16 | fb << 11 | fc << 6 | xo << 1 | rc;
}
u32 M(u32 op, u32 rs, u32 ra, u32 sh, u32 mb, u32 me, u32 rc = 0) {
  return op << 26 | rs << 21 | ra << 16 | sh << 11 | mb << 6 | me << 1 | rc;
}
u32 B(u32 bo, u32 bi, s32 bd, u32 aa = 0, u32 lk = 0) {
  return 16u << 26 | bo << 21 | bi << 16 | (static_cast<u32>(bd) & 0xFFFC) | aa << 1 | lk;
}
u32 I(s32 li, u32 aa = 0, u32 lk = 0) { return 18u << 26 | (static_cast<u32>(li) & 0x03FFFFFC) | aa << 1 | lk; }
u32 SPR(u32 xo, u32 r, u32 spr) { return 31u << 26 | r << 21 | (spr & 31) << 16 | (spr >> 5) << 11 | xo << 1; }

struct Vec {
  u32 word;
  const char* text;
  u32 addr = 0x80003100;
};

}  // namespace

TEST_CASE("every opcode's pattern decodes to itself, and spare field bits keep it") {
  for (int k = 1; k < static_cast<int>(Op::count); ++k) {
    Op op = static_cast<Op>(k);
    const OpInfo& o = op_info(op);
    CHECK_MESSAGE(decode(o.pattern) == op, o.name);
    // Fill every bit outside the mask: still the same op.
    CHECK_MESSAGE(decode(o.pattern | ~o.mask) == op, o.name);
    // Flip each masked bit outside the primary opcode: never this op.
    for (int bit = 0; bit < 26; ++bit) {
      u32 m = 1u << bit;
      if (o.mask & m) CHECK_MESSAGE(decode(o.pattern ^ m) != op, o.name);
    }
  }
}

TEST_CASE("reserved bits make a word invalid") {
  CHECK(decode(0) == Op::invalid);
  CHECK(decode(0x04000000) == Op::invalid);               // primary opcode 1 does not exist
  CHECK(decode(A(59, 0, 0, 1, 12, 25)) == Op::invalid);   // fmuls with frB != 0
  CHECK(decode(X(31, 0, 1, 2, 23) | 1) == Op::invalid);   // lwzx with Rc
  CHECK(decode(X(19, 20, 0, 1, 16)) == Op::invalid);      // bclr with bits 16-20 set
  CHECK(decode(D(11, 1, 3, 0)) == Op::invalid);           // cmpwi with L=1 (64-bit form)
  CHECK(decode(X(31, 1, 0, 3, 1014)) == Op::invalid);     // dcbz with rD != 0
  CHECK(decode(0x44000000) == Op::invalid);               // sc without its fixed bit
  CHECK(disasm(0, 0x80003100) == ".4byte 0x00000000 /* invalid */");
}

TEST_CASE("disassembly vectors") {
  const Vec v[] = {
      // addi / addis family
      {D(14, 3, 0, -1), "li r3, -0x1"},
      {D(14, 3, 1, 8), "addi r3, r1, 0x8"},
      {D(14, 11, 9, -12), "subi r11, r9, 0xc"},
      {D(14, 3, 4, -0x8000), "addi r3, r4, -0x8000"},
      {D(15, 1, 0, 0x8070), "lis r1, 0x8070"},
      {D(15, 4, 4, -0xdd3), "subis r4, r4, 0xdd3"},
      {D(15, 9, 31, 0xe), "addis r9, r31, 0xe"},
      {D(15, 9, 3, -0x8000), "addis r9, r3, 0x8000"},
      {D(12, 3, 3, -1), "subic r3, r3, 0x1"},
      {D(13, 4, 0, -1), "subic. r4, r0, 0x1"},
      {D(13, 11, 11, 1), "addic. r11, r11, 0x1"},
      {D(7, 0, 3, 0xf8), "mulli r0, r3, 0xf8"},
      {D(8, 9, 3, 0), "subfic r9, r3, 0x0"},
      // logical immediates
      {D(24, 0, 0, 0), "nop"},
      {D(24, 1, 1, 0x1020), "ori r1, r1, 0x1020"},
      {D(28, 3, 4, 0x8000), "andi. r4, r3, 0x8000"},
      {D(29, 0, 7, 0x2000), "andis. r7, r0, 0x2000"},
      {D(27, 0, 0, 0x8000), "xoris r0, r0, 0x8000"},
      // compares
      {D(11, 0, 6, 0), "cmpwi r6, 0x0"},
      {D(11, 7 << 2, 6, -3), "cmpwi cr7, r6, -0x3"},
      {D(10, 0, 3, 2), "cmplwi r3, 0x2"},
      {X(31, 0, 4, 0, 0), "cmpw r4, r0"},
      {X(31, 1 << 2, 26, 28, 32), "cmplw cr1, r26, r28"},
      // XO arithmetic
      {XO(6, 5, 6, 0, 266), "add r6, r5, r6"},
      {XO(6, 5, 6, 1, 266, 1), "addo. r6, r5, r6"},
      {XO(5, 3, 5, 0, 40), "subf r5, r3, r5"},
      {XO(30, 30, 0, 0, 104), "neg r30, r30"},
      {XO(3, 3, 0, 0, 104, 1), "neg. r3, r3"},
      {XO(9, 9, 0, 0, 202), "addze r9, r9"},
      {XO(0, 9, 3, 0, 138), "adde r0, r9, r3"},
      {XO(0, 9, 0, 0, 75), "mulhw r0, r9, r0"},
      {XO(0, 9, 10, 0, 459), "divwu r0, r9, r10"},
      // X logical
      {X(31, 3, 30, 3, 444), "mr r30, r3"},
      {X(31, 3, 30, 3, 444, 1), "mr. r30, r3"},
      {X(31, 0, 0, 11, 444), "or r0, r0, r11"},
      {X(31, 0, 0, 0, 124), "nor r0, r0, r0"},
      {X(31, 3, 0, 0, 26), "cntlzw r0, r3"},
      {X(31, 0, 30, 0, 954), "extsb r30, r0"},
      {X(31, 9, 9, 31, 824), "srawi r9, r9, 31"},
      {X(31, 0, 0, 28, 824, 1), "srawi. r0, r0, 28"},
      // rotates
      {M(21, 11, 9, 3, 0, 28), "slwi r9, r11, 3"},
      {M(21, 11, 11, 4, 0, 27, 1), "slwi. r11, r11, 4"},
      {M(21, 0, 9, 1, 31, 31), "srwi r9, r0, 31"},
      {M(21, 10, 9, 0, 24, 31), "clrlwi r9, r10, 24"},
      {M(21, 4, 7, 0, 0, 26), "clrrwi r7, r4, 5"},
      {M(21, 3, 3, 30, 31, 31), "extrwi r3, r3, 1, 29"},
      {M(21, 9, 3, 17, 0, 2), "extlwi r3, r9, 3, 17"},
      {M(21, 3, 3, 24, 7, 7), "clrlslwi r3, r3, 31, 24"},
      {M(21, 9, 9, 0, 16, 27), "rlwinm r9, r9, 0, 16, 27"},
      {M(21, 4, 3, 4, 0, 31), "rotlwi r3, r4, 4"},
      {M(21, 4, 3, 28, 0, 31), "rotrwi r3, r4, 4"},
      {M(20, 9, 0, 14, 10, 17), "rlwimi r0, r9, 14, 10, 17"},
      {M(23, 0, 0, 10, 0, 31), "rotlw r0, r0, r10"},
      {M(23, 11, 11, 0, 24, 31), "rlwnm r11, r11, r0, 24, 31"},
      // branches (address 0x80003100)
      {I(0x200, 0, 1), "bl 0x80003300"},
      {I(-0x100), "b 0x80003000"},
      {I(0x60, 1, 1), "bla 0x60"},
      {B(12, 2, 0x18), "beq 0x80003118"},
      {B(4, 2, -0x10), "bne 0x800030f0"},
      {B(12, 6, 8), "beq cr1, 0x80003108"},
      {B(12, 0, 8), "blt 0x80003108"},
      {B(4, 1, 8), "ble 0x80003108"},
      {B(4, 0, 8), "bge 0x80003108"},
      {B(12, 1, 8), "bgt 0x80003108"},
      {B(12, 3, 8), "bso 0x80003108"},
      {B(4, 31, 8), "bns cr7, 0x80003108"},
      {B(16, 0, -8), "bdnz 0x800030f8"},
      {B(18, 0, 8), "bdz 0x80003108"},
      {B(8, 2, 8), "bdnzt eq, 0x80003108"},
      {B(13, 2, 8), "beq+ 0x80003108"},
      {B(13, 2, -8), "beq- 0x800030f8"},
      {B(12, 2, 8, 0, 1), "beql 0x80003108"},
      {B(20, 0, 8), "bc 20, lt, 0x80003108"},
      {X(19, 20, 0, 0, 16), "blr"},
      {X(19, 20, 0, 0, 16, 1), "blrl"},
      {X(19, 12, 2, 0, 16), "beqlr"},
      {X(19, 4, 2, 0, 16), "bnelr"},
      {X(19, 12, 6, 0, 16), "beqlr cr1"},
      {X(19, 4, 3, 0, 16), "bnslr"},
      {X(19, 20, 0, 0, 528), "bctr"},
      {X(19, 20, 0, 0, 528, 1), "bctrl"},
      {0x44000002, "sc"},
      {X(19, 0, 0, 0, 50), "rfi"},
      {X(19, 0, 0, 0, 150), "isync"},
      {X(31, 0, 0, 0, 598), "sync"},
      // condition register
      {X(19, 6, 6, 6, 193), "crclr cr1eq"},
      {X(19, 6, 6, 6, 289), "crset cr1eq"},
      {X(19, 3, 2, 1, 449), "cror un, eq, gt"},
      {X(19, 3, 2, 2, 449), "crmove un, eq"},
      {X(19, 31, 30, 30, 33), "crnot cr7un, cr7eq"},
      {X(19, 3, 24, 28, 289), "creqv un, cr6lt, cr7lt"},
      {X(19, 7 << 2, 0, 0, 0), "mcrf cr7, cr0"},
      {X(31, 3, 0, 0, 19), "mfcr r3"},
      {31u << 26 | 12u << 21 | 8u << 12 | 144u << 1, "mtcrf 8, r12"},
      // special registers
      {SPR(339, 0, 8), "mflr r0"},
      {SPR(467, 0, 8), "mtlr r0"},
      {SPR(467, 3, 9), "mtctr r3"},
      {SPR(339, 25, 9), "mfctr r25"},
      {SPR(339, 5, 1), "mfxer r5"},
      {SPR(467, 4, 26), "mtsrr0 r4"},
      {SPR(467, 3, 22), "mtdec r3"},
      {SPR(339, 3, 920), "mfspr r3, HID2"},
      {SPR(467, 3, 912), "mtspr GQR0, r3"},
      {SPR(339, 3, 1008), "mfspr r3, HID0"},
      {SPR(339, 9, 285), "mfspr r9, 285"},
      {SPR(339, 5, 272), "mfsprg r5, 0"},
      {SPR(467, 31, 273), "mtsprg 1, r31"},
      {SPR(467, 7, 528), "mtibatu 0, r7"},
      {SPR(339, 5, 541), "mfdbatl r5, 2"},
      {SPR(371, 9, 268), "mftb r9, 268"},
      {X(31, 5, 0, 0, 83), "mfmsr r5"},
      {X(31, 4, 0, 0, 146), "mtmsr r4"},
      {X(31, 5, 0, 0, 595), "mfsr r5, 0"},
      {X(31, 3, 7, 0, 210), "mtsr 7, r3"},
      // cache and TLB
      {X(31, 0, 0, 3, 982), "icbi r0, r3"},
      {X(31, 0, 0, 3, 470), "dcbi r0, r3"},
      {X(31, 0, 0, 3, 1014), "dcbz r0, r3"},
      {X(31, 0, 0, 3, 306), "tlbie r3"},
      // loads and stores
      {D(32, 6, 6, 0), "lwz r6, 0x0(r6)"},
      {D(37, 1, 1, -8), "stwu r1, -0x8(r1)"},
      {D(47, 29, 1, 0x54), "stmw r29, 0x54(r1)"},
      {D(42, 3, 9, 0x90), "lha r3, 0x90(r9)"},
      {D(48, 0, 11, 0x3048), "lfs f0, 0x3048(r11)"},
      {D(50, 0, 3, 0), "lfd f0, 0x0(r3)"},
      {D(51, 0, 9, -8), "lfdu f0, -0x8(r9)"},
      {X(31, 0, 31, 0, 23), "lwzx r0, r31, r0"},
      {X(31, 3, 6, 31, 534), "lwbrx r3, r6, r31"},
      {X(31, 5, 6, 31, 662), "stwbrx r5, r6, r31"},
      {X(31, 0, 3, 4, 663), "stfsx f0, r3, r4"},
      {X(31, 1, 2, 3, 150, 1), "stwcx. r1, r2, r3"},
      // floating point
      {A(59, 0, 0, 0, 12, 25), "fmuls f0, f0, f12"},
      {A(59, 1, 1, 0, 1, 29), "fmadds f1, f1, f1, f0"},
      {A(59, 12, 12, 0, 0, 20), "fsubs f12, f12, f0"},
      {A(63, 30, 0, 12, 13, 29), "fmadd f30, f0, f13, f12"},
      {A(59, 0, 0, 12, 0, 18), "fdivs f0, f0, f12"},
      {X(63, 0, 0, 0, 12), "frsp f0, f0"},
      {X(63, 0, 13, 0, 0), "fcmpu cr0, f13, f0"},
      {X(63, 0, 1, 0, 32), "fcmpo cr0, f1, f0"},
      {X(63, 13, 0, 0, 15), "fctiwz f13, f0"},
      {X(63, 1, 0, 0, 72), "fmr f1, f0"},
      {X(63, 12, 0, 0, 40), "fneg f12, f0"},
      {X(63, 1, 0, 2, 26), "frsqrte f1, f2"},
      {63u << 26 | 255u << 17 | 711u << 1, "mtfsf 255, f0"},
      {X(63, 29, 0, 0, 38), "mtfsb1 cr7gt"},
      {X(63, 0, 0, 0, 583), "mffs f0"},
      // paired singles
      {56u << 26 | 0u << 21 | 3u << 16, "psq_l f0, 0x0(r3), 0, qr0"},
      {56u << 26 | 4u << 21 | 9u << 16 | 1u << 15, "psq_l f4, 0x0(r9), 1, qr0"},
      {56u << 26 | 0u << 21 | 3u << 16 | 5u << 12 | 0xFF8u, "psq_l f0, -0x8(r3), 0, qr5"},
      {60u << 26 | 1u << 21 | 4u << 16 | 2u << 12 | 2u, "psq_st f1, 0x2(r4), 0, qr2"},
      {4u << 26 | 0u << 21 | 3u << 16 | 4u << 11 | 1u << 10 | 2u << 7 | 6u << 1, "psq_lx f0, r3, r4, 1, qr2"},
      {X(4, 4, 4, 4, 528), "ps_merge00 f4, f4, f4"},
      {X(4, 20, 8, 9, 624), "ps_merge11 f20, f8, f9"},
      {A(4, 0, 0, 10, 8, 14), "ps_madds0 f0, f0, f8, f10"},
      {A(4, 6, 5, 5, 6, 10), "ps_sum0 f6, f5, f6, f5"},
      {A(4, 8, 16, 0, 20, 25), "ps_mul f8, f16, f20"},
      {X(4, 1, 0, 0, 72), "ps_mr f1, f0"},
      {X(4, 19, 0, 11, 40), "ps_neg f19, f11"},
      {X(4, 1 << 2, 1, 2, 32), "ps_cmpo0 cr1, f1, f2"},
  };
  for (const auto& t : v) {
    std::string got = disasm(t.word, t.addr);
    CHECK_MESSAGE(got == t.text, "word ", t.word);
  }
}

TEST_CASE("field accessors") {
  Insn i{B(12, 2, -0x10)};
  CHECK(i.bd() == -0x10);
  Insn j{I(-0x100)};
  CHECK(j.li() == -0x100);
  Insn k{SPR(339, 3, 920)};
  CHECK(k.spr() == 920);
  Insn p{56u << 26 | 0xFF8u};
  CHECK(p.ps_d() == -8);
  CHECK(rot_mask(0, 31) == 0xFFFFFFFFu);
  CHECK(rot_mask(16, 27) == 0x0000FFF0u);
  CHECK(rot_mask(30, 1) == 0xC0000003u);
  CHECK(rot_mask(5, 5) == 0x04000000u);
}
