/*
 * Dolphin SDK MTX/VEC (MWCC GC/1.2.5n, cflags_dolphin_sdk with -char signed),
 * .text 0x804310E0-0x80431828 (code-only unit, 11 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/mtx.h>

#include "__gx.h"

void fn_804310E0(u32* topIn, u32* topOut, u32* botIn, u32* botOut, u32* clrIn, u32* copyClks);
void fn_80431374(Mtx44 m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
void fn_80431494(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f);
void fn_80431564(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);

/* near-miss: matches only with the extra flag -schedule off (default flags emit the hi/lo loads in the other order). Likely GXReadPixMetric. */
static inline u32 ReadPE(u32 lo, u32 hi) {
    u32 ctrH, ctrL, ctrH2;
    ctrH = GX_GET_PE_REG(hi);
    do {
        ctrH2 = ctrH;
        ctrL = GX_GET_PE_REG(lo);
        ctrH = GX_GET_PE_REG(hi);
    } while (ctrH != ctrH2);
    return (ctrH << 16) | ctrL;
}

void fn_804310E0(u32* topIn, u32* topOut, u32* botIn, u32* botOut, u32* clrIn, u32* copyClks) {
    *topIn = ReadPE(12, 13) * 4;
    *topOut = ReadPE(14, 15) * 4;
    *botIn = ReadPE(16, 17) * 4;
    *botOut = ReadPE(18, 19) * 4;
    *clrIn = ReadPE(20, 21) * 4;
    *copyClks = ReadPE(22, 23);
}

/* near-miss: matches only with the extra flag -opt nopeephole (C_MTXLightPerspective in mtx.c; fn_80431494/fn_80431564 are mtx44.c and match at default flags) */
void fn_80431374(Mtx44 m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT) {
    f32 angle;
    f32 cot;

    angle = fovY * 0.5f;
    angle = MTXDegToRad(angle);
    cot = 1.0f / tanf(angle);

    m[0][0] = (cot / aspect) * scaleS;
    m[0][1] = 0.0f;
    m[0][2] = -transS;
    m[0][3] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = cot * scaleT;
    m[1][2] = -transT;
    m[1][3] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = -1.0f;
    m[2][3] = 0.0f;
}

void fn_80431494(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f) {
    f32 angle;
    f32 cot;
    f32 tmp;

    angle = fovY * 0.5f;
    angle = MTXDegToRad(angle);
    cot = 1.0f / tanf(angle);

    m[0][0] = cot / aspect;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = cot;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;

    tmp = 1.0f / (f - n);
    m[2][2] = -n * tmp;
    m[2][3] = tmp * -(f * n);

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = -1.0f;
    m[3][3] = 0.0f;
}

void fn_80431564(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f) {
    f32 tmp;

    tmp = 1.0f / (r - l);
    m[0][0] = 2.0f * tmp;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = -(r + l) * tmp;

    tmp = 1.0f / (t - b);
    m[1][0] = 0.0f;
    m[1][1] = 2.0f * tmp;
    m[1][2] = 0.0f;
    m[1][3] = -(t + b) * tmp;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;

    tmp = 1.0f / (f - n);
    m[2][2] = -1.0f * tmp;
    m[2][3] = -f * tmp;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}
