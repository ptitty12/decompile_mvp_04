// Instruction encoders for tests: words are built from fields, never taken from game code.
#pragma once

#include "ppc/isa.h"

namespace mvp::ppc::enc {

inline u32 D(u32 op, u32 rt, u32 ra, s32 imm) { return op << 26 | rt << 21 | ra << 16 | (static_cast<u32>(imm) & 0xFFFF); }
inline u32 X(u32 op, u32 rt, u32 ra, u32 rb, u32 xo, u32 rc = 0) {
  return op << 26 | rt << 21 | ra << 16 | rb << 11 | xo << 1 | rc;
}
inline u32 XO(u32 rt, u32 ra, u32 rb, u32 oe, u32 xo, u32 rc = 0) {
  return 31u << 26 | rt << 21 | ra << 16 | rb << 11 | oe << 10 | xo << 1 | rc;
}
inline u32 A(u32 op, u32 ft, u32 fa, u32 fb, u32 fc, u32 xo, u32 rc = 0) {
  return op << 26 | ft << 21 | fa << 16 | fb << 11 | fc << 6 | xo << 1 | rc;
}
inline u32 M(u32 op, u32 rs, u32 ra, u32 sh, u32 mb, u32 me, u32 rc = 0) {
  return op << 26 | rs << 21 | ra << 16 | sh << 11 | mb << 6 | me << 1 | rc;
}
inline u32 B(u32 bo, u32 bi, s32 bd, u32 aa = 0, u32 lk = 0) {
  return 16u << 26 | bo << 21 | bi << 16 | (static_cast<u32>(bd) & 0xFFFC) | aa << 1 | lk;
}
inline u32 I(s32 li, u32 aa = 0, u32 lk = 0) { return 18u << 26 | (static_cast<u32>(li) & 0x03FFFFFC) | aa << 1 | lk; }
inline u32 SPR(u32 xo, u32 r, u32 spr) { return 31u << 26 | r << 21 | (spr & 31) << 16 | (spr >> 5) << 11 | xo << 1; }
// psq_l / psq_st family: d is a 12-bit displacement.
inline u32 PSQ(u32 op, u32 fr, u32 ra, s32 d, u32 w, u32 i) {
  return op << 26 | fr << 21 | ra << 16 | w << 15 | i << 12 | (static_cast<u32>(d) & 0xFFF);
}
inline u32 PSQX(u32 fr, u32 ra, u32 rb, u32 w, u32 i, u32 xo6) {
  return 4u << 26 | fr << 21 | ra << 16 | rb << 11 | w << 10 | i << 7 | xo6 << 1;
}

}  // namespace mvp::ppc::enc
