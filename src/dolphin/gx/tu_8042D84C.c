/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8042D84C-0x8042DD30 (code-only unit, 8 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin/gx.h>
#include <dolphin/os.h>

#include "__gx.h"

/* GXLight.c. The functions keep their placeholder names (symbols.txt): likely GXInitLightSpot,
 * GXInitLightPos, GXInitLightColor, [GXLoadLightObjImm: paired-single code, skipped],
 * GXSetChanAmbColor, GXSetChanMatColor, GXSetNumChans, GXSetChanCtrl. */

typedef struct LightObjInt {
    u32 reserved[3];
    u32 color;
    f32 a[3];
    f32 k[3];
    f32 lpos[3];
    f32 ldir[3];
} LightObjInt;

f32 fn_80411554(f32 x); /* cosf */

void fn_8042D84C(GXLightObj* lt_obj, f32 cutoff, GXSpotFn spot_func);
void fn_8042D9DC(GXLightObj* lt_obj, f32 x, f32 y, f32 z);
void fn_8042D9EC(GXLightObj* lt_obj, GXColor* color);
void fn_8042DA74(GXChannelID chan, GXColor amb_color);
void fn_8042DB5C(GXChannelID chan, GXColor mat_color);
void fn_8042DC44(u8 nChans);
void fn_8042DC80(GXChannelID chan, GXBool enable, GXColorSrc amb_src, GXColorSrc mat_src, u32 light_mask, GXDiffuseFn diff_fn, GXAttnFn attn_fn);

void fn_8042D84C(GXLightObj* lt_obj, f32 cutoff, GXSpotFn spot_func) {
    f32 a0, a1, a2;
    f32 d;
    f32 cr;
    LightObjInt* obj;

    obj = (LightObjInt*)lt_obj;
    if (cutoff <= 0.0f || cutoff > 90.0f) {
        spot_func = GX_SP_OFF;
    }
    cr = fn_80411554((3.1415927f * cutoff) / 180.0f);
    switch (spot_func) {
    case GX_SP_FLAT:
        a0 = -1000.0f * cr;
        a1 = 1000.0f;
        a2 = 0.0f;
        break;
    case GX_SP_COS:
        d = 1.0f / (1.0f - cr);
        a0 = -cr * d;
        a1 = d;
        a2 = 0.0f;
        break;
    case GX_SP_COS2:
        d = 1.0f / (1.0f - cr);
        a0 = 0.0f;
        a1 = -cr * d;
        a2 = d;
        break;
    case GX_SP_SHARP:
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = d * (cr * (cr - 2.0f));
        a1 = 2.0f * d;
        a2 = -d;
        break;
    case GX_SP_RING1:
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = (-4.0f * d) * cr;
        a1 = (4.0f * (1.0f + cr)) * d;
        a2 = -4.0f * d;
        break;
    case GX_SP_RING2:
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = 1.0f - d * (2.0f * cr * cr);
        a1 = (4.0f * cr) * d;
        a2 = -2.0f * d;
        break;
    case GX_SP_OFF:
    default:
        a0 = 1.0f;
        a1 = 0.0f;
        a2 = 0.0f;
        break;
    }
    obj->a[0] = a0;
    obj->a[1] = a1;
    obj->a[2] = a2;
}

void fn_8042D9DC(GXLightObj* lt_obj, f32 x, f32 y, f32 z) {
    LightObjInt* obj = (LightObjInt*)lt_obj;

    obj->lpos[0] = x;
    obj->lpos[1] = y;
    obj->lpos[2] = z;
}

void fn_8042D9EC(GXLightObj* lt_obj, GXColor* color) {
    LightObjInt* obj = (LightObjInt*)lt_obj;

    obj->color = *(u32*)color;
}

void fn_8042DA74(GXChannelID chan, GXColor amb_color) {
    u32 reg, colIdx;

    switch (chan) {
    case GX_COLOR0:
        reg = __GXData->ambColor[0];
        reg = __rlwimi(reg, *(u32*)&amb_color, 0, 0, 23);
        colIdx = 0;
        break;
    case GX_COLOR1:
        reg = __GXData->ambColor[1];
        reg = __rlwimi(reg, *(u32*)&amb_color, 0, 0, 23);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = __GXData->ambColor[0];
        SET_REG_FIELD(0, reg, 8, 0, amb_color.a);
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = __GXData->ambColor[1];
        SET_REG_FIELD(0, reg, 8, 0, amb_color.a);
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32*)&amb_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32*)&amb_color;
        colIdx = 1;
        break;
    default:
        return;
    }
    GX_WRITE_XF_REG(colIdx + 10, reg);
    __GXData->bpSentNot = 1;
    __GXData->ambColor[colIdx] = reg;
}

void fn_8042DB5C(GXChannelID chan, GXColor mat_color) {
    u32 reg, colIdx;

    switch (chan) {
    case GX_COLOR0:
        reg = __GXData->matColor[0];
        reg = __rlwimi(reg, *(u32*)&mat_color, 0, 0, 23);
        colIdx = 0;
        break;
    case GX_COLOR1:
        reg = __GXData->matColor[1];
        reg = __rlwimi(reg, *(u32*)&mat_color, 0, 0, 23);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = __GXData->matColor[0];
        SET_REG_FIELD(0, reg, 8, 0, mat_color.a);
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = __GXData->matColor[1];
        SET_REG_FIELD(0, reg, 8, 0, mat_color.a);
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32*)&mat_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32*)&mat_color;
        colIdx = 1;
        break;
    default:
        return;
    }
    GX_WRITE_XF_REG(colIdx + 12, reg);
    __GXData->bpSentNot = 1;
    __GXData->matColor[colIdx] = reg;
}

void fn_8042DC44(u8 nChans) {
    SET_REG_FIELD(0, __GXData->genMode, 3, 4, nChans);
    GX_WRITE_XF_REG(9, nChans);
    __GXData->dirtyState |= 4;
}

void fn_8042DC80(GXChannelID chan, GXBool enable, GXColorSrc amb_src, GXColorSrc mat_src, u32 light_mask, GXDiffuseFn diff_fn, GXAttnFn attn_fn) {
    u32 reg, idx;

    idx = chan & 3;
    reg = 0;
    SET_REG_FIELD(0, reg, 1, 1, enable);
    SET_REG_FIELD(0, reg, 1, 0, mat_src);
    SET_REG_FIELD(0, reg, 1, 6, amb_src);
    SET_REG_FIELD(0, reg, 2, 7, (attn_fn == GX_AF_SPEC) ? GX_DF_NONE : diff_fn);
    SET_REG_FIELD(0, reg, 1, 9, (attn_fn != GX_AF_NONE));
    SET_REG_FIELD(0, reg, 1, 10, (attn_fn != GX_AF_SPEC));
    SET_REG_FIELD(0, reg, 4, 2, light_mask & 0xF);
    SET_REG_FIELD(0, reg, 4, 11, (light_mask >> 4) & 0xF);
    GX_WRITE_XF_REG(idx + 14, reg);
    if (chan == GX_COLOR0A0) {
        GX_WRITE_XF_REG(16, reg);
    } else if (chan == GX_COLOR1A1) {
        GX_WRITE_XF_REG(17, reg);
    }
    __GXData->bpSentNot = 1;
}
