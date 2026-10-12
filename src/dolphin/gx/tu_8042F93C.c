/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8042F93C-0x804310E0 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin/gx.h>
#include <dolphin/os.h>

#include <math.h>

#include "__gx.h"

/* GXPixel.c / GXTransform.c / GXPerf.c part. Placeholder names kept (symbols.txt); likely SDK names:
 * fn_8042F93C GXSetFog, fn_8042FB50 GXInitFogAdjTable, fn_8042FD00 GXSetFogRangeAdj,
 * fn_8042FE24 GXSetBlendMode, fn_8042FE78 GXSetColorUpdate, fn_8042FEA4 GXSetAlphaUpdate,
 * fn_8042FED0 GXSetZMode, fn_8042FF04 GXSetZCompLoc, fn_8042FF38 GXSetPixelFmt,
 * fn_8043000C GXSetDither, fn_80430038 GXSetDstAlpha, fn_80430074 GXSetFieldMask,
 * fn_804300AC GXSetFieldMode, fn_80430124 GXCallDisplayList, fn_80430194 GXSetProjection (psq),
 * fn_80430238 GXSetProjectionv (psq), fn_804302C4 GXLoadPosMtxImm (psq), fn_80430314
 * GXLoadNrmMtxImm (psq), fn_80430364 GXSetCurrentMtx, fn_80430398 GXLoadTexMtxImm (psq),
 * fn_8043044C __GXSetProjection helper (viewport), fn_804304DC GXSetViewportJitter,
 * fn_80430534 GXSetViewport, fn_8043057C GXSetScissor, fn_804305F4 GXSetScissorBoxOffset,
 * fn_80430634 GXSetClipMode, fn_8043065C __GXSetMatrixIndex, fn_804306E0 GXSetGPMetric,
 * fn_80430F28 GXReadGPMetric, fn_804310D0 GXClearGPMetric.
 * fn_80406C74 is the double->u32 conversion helper (__cvt_fp2unsigned). */
u32 fn_80406C74(double x);

void fn_8042F93C(GXFogType type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);
void fn_8042FB50(GXFogAdjTable* table, u16 width, const f32 projmtx[4][4]);
void fn_8042FD00(GXBool enable, u16 center, GXFogAdjTable* table);
void fn_8042FE24(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op);
void fn_8042FE78(GXBool update_enable);
void fn_8042FEA4(GXBool update_enable);
void fn_8042FED0(GXBool compare_enable, GXCompare func, GXBool update_enable);
void fn_8042FF04(GXBool before_tex);
void fn_8042FF38(GXPixelFmt pix_fmt, GXZFmt16 z_fmt);
void fn_8043000C(GXBool dither);
void fn_80430038(GXBool enable, u8 alpha);
void fn_80430074(GXBool update_odd, GXBool update_even);
void fn_804300AC(GXBool field_mode, GXBool half_aspect_ratio);
void fn_80430124(void* list, u32 nbytes);
void fn_80430364(u32 id);
void fn_8043044C(void);
void fn_804304DC(u32 field, f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz);
void fn_80430534(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz);
void fn_8043057C(u32 left, u32 top, u32 wd, u32 ht);
void fn_804305F4(u32 x_off, u32 y_off);
void fn_80430634(GXClipMode mode);
void fn_8043065C(s32 mtx);
void fn_804310D0(void);

/* near-miss: same instructions, only the scheduling of the three early loads/inserts and the temp registers differ */
void fn_8042F93C(GXFogType type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color) {
    u32 fogColorReg = 0, fogParamReg0 = 0, fogParamReg1 = 0, fogParamReg2 = 0, fogParamReg3 = 0;
    u32 fsel;
    u32 proj;
    f32 A, B, B_mant, C, a, c;
    u32 B_expn, b_m, b_s, a_hex, c_hex;

    fsel = type & 7;
    proj = (type >> 3) & 1;
    if (proj) {
        if (farz == nearz || endz == startz) {
            a = 0.0f;
            c = 0.0f;
        } else {
            A = 1.0f / (endz - startz);
            a = A * (farz - nearz);
            c = A * (startz - nearz);
        }
    } else {
        if (farz == nearz || endz == startz) {
            A = 0.0f;
            B = 0.5f;
            C = 0.0f;
        } else {
            A = (farz * nearz) / ((farz - nearz) * (endz - startz));
            B = farz / (farz - nearz);
            C = startz / (endz - startz);
        }
        B_mant = B;
        B_expn = 0;
        while (B_mant > 1.0) {
            B_mant *= 0.5f;
            B_expn++;
        }
        while (B_mant > 0.0f && B_mant < 0.5) {
            B_mant *= 2.0f;
            B_expn--;
        }
        a = A / (1 << (B_expn + 1));
        b_m = (u32)(8388638.0f * B_mant);
        b_s = B_expn + 1;
        c = C;
        SET_REG_FIELD(0, fogParamReg1, 24, 0, b_m);
        SET_REG_FIELD(0, fogParamReg1, 8, 24, 0xEF);
        SET_REG_FIELD(0, fogParamReg2, 5, 0, b_s);
        SET_REG_FIELD(0, fogParamReg2, 8, 24, 0xF0);
    }
    a_hex = *(u32*)&a;
    c_hex = *(u32*)&c;
    SET_REG_FIELD(0, fogParamReg0, 11, 0, (a_hex >> 12) & 0x7FF);
    SET_REG_FIELD(0, fogParamReg0, 8, 11, (a_hex >> 23) & 0xFF);
    SET_REG_FIELD(0, fogParamReg0, 1, 19, (a_hex >> 31));
    SET_REG_FIELD(0, fogParamReg0, 8, 24, 0xEE);
    SET_REG_FIELD(0, fogParamReg3, 11, 0, (c_hex >> 12) & 0x7FF);
    SET_REG_FIELD(0, fogParamReg3, 8, 11, (c_hex >> 23) & 0xFF);
    SET_REG_FIELD(0, fogParamReg3, 1, 19, (c_hex >> 31));
    SET_REG_FIELD(0, fogParamReg3, 1, 20, proj);
    SET_REG_FIELD(0, fogParamReg3, 3, 21, fsel);
    SET_REG_FIELD(0, fogParamReg3, 8, 24, 0xF1);
    SET_REG_FIELD(0, fogColorReg, 24, 0, *(u32*)&color >> 8);
    SET_REG_FIELD(0, fogColorReg, 8, 24, 0xF2);
    GX_WRITE_RAS_REG(fogParamReg0);
    GX_WRITE_RAS_REG(fogParamReg1);
    GX_WRITE_RAS_REG(fogParamReg2);
    GX_WRITE_RAS_REG(fogParamReg3);
    GX_WRITE_RAS_REG(fogColorReg);
    __GXData->bpSentNot = 0;
}

/* near-miss: loop-invariant 2.0f / width is hoisted into f25 in the original but the iw/sc registers come out swapped here */
void fn_8042FB50(GXFogAdjTable* table, u16 width, const f32 projmtx[4][4]) {
    f32 xi, iw, rangeScale, sqrtTerm, ratio;
    u32 i;
    f32 sc;
    u32 r;

    if (projmtx[3][3] == 0.0) {
        ratio = projmtx[2][3] / (projmtx[2][2] - 1.0f);
        iw = ratio / projmtx[0][0];
        rangeScale = ratio;
    } else {
        iw = 1.0f / projmtx[0][0];
        rangeScale = 1.7320499f * iw;
    }
    sc = 2.0f / width;
    for (i = 0; i < 10; i++) {
        xi = (i + 1) << 5;
        xi = xi * sc * iw;
        sqrtTerm = 1.0f + (xi * xi) / (rangeScale * rangeScale);
        sqrtTerm = sqrtf(sqrtTerm);
        r = (u32)(256.0f * sqrtTerm);
        table->r[i] = r & 0xFFF;
    }
}

void fn_8042FD00(GXBool enable, u16 center, GXFogAdjTable* table) {
    u32 fogRangeReg;
    u32 fogRangeRegK;
    u32 i;

    if (enable) {
        for (i = 0; i < 10; i += 2) {
            fogRangeRegK = 0;
            SET_REG_FIELD(0, fogRangeRegK, 12, 0, table->r[i]);
            SET_REG_FIELD(0, fogRangeRegK, 12, 12, table->r[i + 1]);
            SET_REG_FIELD(0, fogRangeRegK, 8, 24, 0xE9 + i / 2);
            GX_WRITE_RAS_REG(fogRangeRegK);
        }
    }
    fogRangeReg = 0;
    SET_REG_FIELD(0, fogRangeReg, 10, 0, center + 342);
    SET_REG_FIELD(0, fogRangeReg, 1, 10, enable);
    SET_REG_FIELD(0, fogRangeReg, 8, 24, 0xE8);
    GX_WRITE_RAS_REG(fogRangeReg);
    __GXData->bpSentNot = 0;
}

void fn_8042FE24(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op) {
    u32 reg = __GXData->cmode0;

    SET_REG_FIELD(0, reg, 1, 11, (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0, reg, 1, 0, type);
    SET_REG_FIELD(0, reg, 1, 1, (type == GX_BM_LOGIC));
    SET_REG_FIELD(0, reg, 4, 12, op);
    SET_REG_FIELD(0, reg, 3, 8, src_factor);
    SET_REG_FIELD(0, reg, 3, 5, dst_factor);
    GX_WRITE_RAS_REG(reg);
    __GXData->cmode0 = reg;
    __GXData->bpSentNot = 0;
}

void fn_8042FE78(GXBool update_enable) {
    u32 reg = __GXData->cmode0;

    SET_REG_FIELD(0, reg, 1, 3, update_enable);
    GX_WRITE_RAS_REG(reg);
    __GXData->cmode0 = reg;
    __GXData->bpSentNot = 0;
}

void fn_8042FEA4(GXBool update_enable) {
    u32 reg = __GXData->cmode0;

    SET_REG_FIELD(0, reg, 1, 4, update_enable);
    GX_WRITE_RAS_REG(reg);
    __GXData->cmode0 = reg;
    __GXData->bpSentNot = 0;
}

void fn_8042FED0(GXBool compare_enable, GXCompare func, GXBool update_enable) {
    u32 reg = __GXData->zmode;

    SET_REG_FIELD(0, reg, 1, 0, compare_enable);
    SET_REG_FIELD(0, reg, 3, 1, func);
    SET_REG_FIELD(0, reg, 1, 4, update_enable);
    GX_WRITE_RAS_REG(reg);
    __GXData->zmode = reg;
    __GXData->bpSentNot = 0;
}

void fn_8042FF04(GXBool before_tex) {
    SET_REG_FIELD(0, __GXData->peCtrl, 1, 6, before_tex);
    GX_WRITE_RAS_REG(__GXData->peCtrl);
    __GXData->bpSentNot = 0;
}

extern u32 lbl_806354E0[8]; /* pixel format -> hardware format table */

/* near-miss: the 1/0 value for the genMode bit lands in r5 here, r0 in the original */
void fn_8042FF38(GXPixelFmt pix_fmt, GXZFmt16 z_fmt) {
    u32 oldPeCtrl;

    oldPeCtrl = __GXData->peCtrl;
    SET_REG_FIELD(0, __GXData->peCtrl, 3, 0, lbl_806354E0[pix_fmt]);
    SET_REG_FIELD(0, __GXData->peCtrl, 3, 3, z_fmt);
    if (oldPeCtrl != __GXData->peCtrl) {
        GX_WRITE_RAS_REG(__GXData->peCtrl);
        SET_REG_FIELD(0, __GXData->genMode, 1, 9, (pix_fmt == GX_PF_RGB565_Z16) ? 1 : 0);
        __GXData->dirtyState |= 4;
    }
    if (lbl_806354E0[pix_fmt] == 4) {
        SET_REG_FIELD(0, __GXData->cmode1, 2, 9, (pix_fmt - GX_PF_Y8) & 3);
        SET_REG_FIELD(0, __GXData->cmode1, 8, 24, 0x42);
        GX_WRITE_RAS_REG(__GXData->cmode1);
    }
    __GXData->bpSentNot = 0;
}

void fn_8043000C(GXBool dither) {
    u32 reg = __GXData->cmode0;

    SET_REG_FIELD(0, reg, 1, 2, dither);
    GX_WRITE_RAS_REG(reg);
    __GXData->cmode0 = reg;
    __GXData->bpSentNot = 0;
}

void fn_80430038(GXBool enable, u8 alpha) {
    u32 reg = __GXData->cmode1;

    SET_REG_FIELD(0, reg, 8, 0, alpha);
    SET_REG_FIELD(0, reg, 1, 8, enable);
    GX_WRITE_RAS_REG(reg);
    __GXData->cmode1 = reg;
    __GXData->bpSentNot = 0;
}

void fn_80430074(GXBool update_odd, GXBool update_even) {
    u32 reg = 0;

    SET_REG_FIELD(0, reg, 1, 0, update_even);
    SET_REG_FIELD(0, reg, 1, 1, update_odd);
    SET_REG_FIELD(0, reg, 8, 24, 0x44);
    GX_WRITE_RAS_REG(reg);
    __GXData->bpSentNot = 0;
}

void fn_804300AC(GXBool field_mode, GXBool half_aspect_ratio) {
    SET_REG_FIELD(0, __GXData->lpSize, 1, 22, half_aspect_ratio);
    GX_WRITE_RAS_REG(__GXData->lpSize);
    __GXFlushTextureState();
    GX_WRITE_RAS_REG(0x68000000 | field_mode);
    __GXFlushTextureState();
}

void fn_80430124(void* list, u32 nbytes) {
    if (__GXData->dirtyState != 0) {
        __GXSetDirtyState();
    }
    if (*(u32*)&__GXData->vNumNot == 0) {
        __GXSendFlushPrim();
    }
    GX_WRITE_U8(0x40);
    GX_WRITE_U32(list);
    GX_WRITE_U32(nbytes);
}

void fn_80430364(u32 id) {
    SET_REG_FIELD(0, __GXData->matIdxA, 6, 0, id);
    fn_8043065C(0);
}

void fn_8043044C(void) {
    f32 sx, sy, sz, ox, oy, oz, zmin, zmax;

    sx = __GXData->vpWd / 2;
    sy = -__GXData->vpHt / 2;
    ox = 342.0f + (__GXData->vpLeft + __GXData->vpWd / 2);
    oy = 342.0f + (__GXData->vpTop + __GXData->vpHt / 2);
    zmax = __GXData->vpFarz * __GXData->zScale;
    zmin = __GXData->vpNearz * __GXData->zScale;
    sz = zmax - zmin;
    oz = zmax + __GXData->zOffset;
    GX_WRITE_U8(0x10);
    GX_WRITE_U32(0x5101A);
    GX_WRITE_F32(sx);
    GX_WRITE_F32(sy);
    GX_WRITE_F32(sz);
    GX_WRITE_F32(ox);
    GX_WRITE_F32(oy);
    GX_WRITE_F32(oz);
}

void fn_804304DC(u32 field, f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz) {
    if (field == 0) {
        top -= 0.5f;
    }
    __GXData->vpLeft = left;
    __GXData->vpTop = top;
    __GXData->vpWd = wd;
    __GXData->vpHt = ht;
    __GXData->vpNearz = nearz;
    __GXData->vpFarz = farz;
    fn_8043044C();
    __GXData->bpSentNot = 1;
}

void fn_80430534(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz) {
    __GXData->vpLeft = left;
    __GXData->vpTop = top;
    __GXData->vpWd = wd;
    __GXData->vpHt = ht;
    __GXData->vpNearz = nearz;
    __GXData->vpFarz = farz;
    fn_8043044C();
    __GXData->bpSentNot = 1;
}

void fn_8043057C(u32 left, u32 top, u32 wd, u32 ht) {
    u32 tp, lf, bm, rt;

    tp = top + 0x156;
    lf = left + 0x156;
    bm = tp + ht - 1;
    rt = lf + wd - 1;
    SET_REG_FIELD(0, __GXData->suScis0, 11, 0, tp);
    SET_REG_FIELD(0, __GXData->suScis0, 11, 12, lf);
    SET_REG_FIELD(0, __GXData->suScis1, 11, 0, bm);
    SET_REG_FIELD(0, __GXData->suScis1, 11, 12, rt);
    GX_WRITE_RAS_REG(__GXData->suScis0);
    GX_WRITE_RAS_REG(__GXData->suScis1);
    __GXData->bpSentNot = 0;
}

void fn_804305F4(u32 x_off, u32 y_off) {
    u32 reg = 0;
    u32 hx = (x_off + 0x156) >> 1;
    u32 hy = (y_off + 0x156) >> 1;

    SET_REG_FIELD(0, reg, 10, 0, hx);
    SET_REG_FIELD(0, reg, 10, 10, hy);
    SET_REG_FIELD(0, reg, 8, 24, 0x59);
    GX_WRITE_RAS_REG(reg);
    __GXData->bpSentNot = 0;
}

void fn_80430634(GXClipMode mode) {
    GX_WRITE_XF_REG(5, mode);
    __GXData->bpSentNot = 1;
}

void fn_8043065C(s32 mtx) {
    if (mtx < 5) {
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x30);
        GX_WRITE_U32(__GXData->matIdxA);
        GX_WRITE_XF_REG(24, __GXData->matIdxA);
    } else {
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x40);
        GX_WRITE_U32(__GXData->matIdxB);
        GX_WRITE_XF_REG(25, __GXData->matIdxB);
    }
    __GXData->bpSentNot = 1;
}

void fn_804306E0(GXPerf0 perf0, GXPerf1 perf1);
void fn_80430F28(u32* cnt0, u32* cnt1);

/* GXSetGPMetric */
void fn_804306E0(GXPerf0 perf0, GXPerf1 perf1) {
    switch (__GXData->perf0) {
    case GX_PERF0_VERTICES:
    case GX_PERF0_CLIP_VTX:
    case GX_PERF0_CLIP_CLKS:
    case GX_PERF0_XF_WAIT_IN:
    case GX_PERF0_XF_WAIT_OUT:
    case GX_PERF0_XF_XFRM_CLKS:
    case GX_PERF0_XF_LIT_CLKS:
    case GX_PERF0_XF_BOT_CLKS:
    case GX_PERF0_XF_REGLD_CLKS:
    case GX_PERF0_XF_REGRD_CLKS:
    case GX_PERF0_CLIP_RATIO:
    case GX_PERF0_CLOCKS:
        GX_WRITE_XF_REG(6, 0);
        break;
    case GX_PERF0_TRIANGLES:
    case GX_PERF0_TRIANGLES_CULLED:
    case GX_PERF0_TRIANGLES_PASSED:
    case GX_PERF0_TRIANGLES_SCISSORED:
    case GX_PERF0_TRIANGLES_0TEX:
    case GX_PERF0_TRIANGLES_1TEX:
    case GX_PERF0_TRIANGLES_2TEX:
    case GX_PERF0_TRIANGLES_3TEX:
    case GX_PERF0_TRIANGLES_4TEX:
    case GX_PERF0_TRIANGLES_5TEX:
    case GX_PERF0_TRIANGLES_6TEX:
    case GX_PERF0_TRIANGLES_7TEX:
    case GX_PERF0_TRIANGLES_8TEX:
    case GX_PERF0_TRIANGLES_0CLR:
    case GX_PERF0_TRIANGLES_1CLR:
    case GX_PERF0_TRIANGLES_2CLR:
        GX_WRITE_RAS_REG(0x23000000);
        break;
    case GX_PERF0_QUAD_0CVG:
    case GX_PERF0_QUAD_NON0CVG:
    case GX_PERF0_QUAD_1CVG:
    case GX_PERF0_QUAD_2CVG:
    case GX_PERF0_QUAD_3CVG:
    case GX_PERF0_QUAD_4CVG:
    case GX_PERF0_AVG_QUAD_CNT:
        GX_WRITE_RAS_REG(0x24000000);
        break;
    case GX_PERF0_NONE:
    default:
        break;
    }
    switch (__GXData->perf1) {
    case GX_PERF1_TEXELS:
    case GX_PERF1_TX_IDLE:
    case GX_PERF1_TX_REGS:
    case GX_PERF1_TX_MEMSTALL:
    case GX_PERF1_TC_CHECK1_2:
    case GX_PERF1_TC_CHECK3_4:
    case GX_PERF1_TC_CHECK5_6:
    case GX_PERF1_TC_CHECK7_8:
    case GX_PERF1_TC_MISS:
    case GX_PERF1_CLOCKS:
        GX_WRITE_RAS_REG(0x67000000);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
    case GX_PERF1_VC_MISSQ_FULL:
    case GX_PERF1_VC_MEMREQ_FULL:
    case GX_PERF1_VC_STATUS7:
    case GX_PERF1_VC_MISSREP_FULL:
    case GX_PERF1_VC_STREAMBUF_LOW:
    case GX_PERF1_VC_ALL_STALLS:
    case GX_PERF1_VERTICES:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 0);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_FIFO_REQ:
    case GX_PERF1_CALL_REQ:
    case GX_PERF1_VC_MISS_REQ:
    case GX_PERF1_CP_ALL_REQ:
        GX_SET_CP_REG(3, 0);
        break;
    case GX_PERF1_NONE:
    default:
        break;
    }
    __GXData->perf0 = perf0;
    switch (__GXData->perf0) {
    case GX_PERF0_VERTICES:
        GX_WRITE_XF_REG(6, 0x273);
        break;
    case GX_PERF0_CLIP_VTX:
        GX_WRITE_XF_REG(6, 0x14A);
        break;
    case GX_PERF0_CLIP_CLKS:
        GX_WRITE_XF_REG(6, 0x16B);
        break;
    case GX_PERF0_XF_WAIT_IN:
        GX_WRITE_XF_REG(6, 0x84);
        break;
    case GX_PERF0_XF_WAIT_OUT:
        GX_WRITE_XF_REG(6, 0xC6);
        break;
    case GX_PERF0_XF_XFRM_CLKS:
        GX_WRITE_XF_REG(6, 0x210);
        break;
    case GX_PERF0_XF_LIT_CLKS:
        GX_WRITE_XF_REG(6, 0x252);
        break;
    case GX_PERF0_XF_BOT_CLKS:
        GX_WRITE_XF_REG(6, 0x231);
        break;
    case GX_PERF0_XF_REGLD_CLKS:
        GX_WRITE_XF_REG(6, 0x1AD);
        break;
    case GX_PERF0_XF_REGRD_CLKS:
        GX_WRITE_XF_REG(6, 0x1CE);
        break;
    case GX_PERF0_CLOCKS:
        GX_WRITE_XF_REG(6, 0x21);
        break;
    case GX_PERF0_CLIP_RATIO:
        GX_WRITE_XF_REG(6, 0x153);
        break;
    case GX_PERF0_TRIANGLES:
        GX_WRITE_RAS_REG(0x2300AE7F);
        break;
    case GX_PERF0_TRIANGLES_CULLED:
        GX_WRITE_RAS_REG(0x23008E7F);
        break;
    case GX_PERF0_TRIANGLES_PASSED:
        GX_WRITE_RAS_REG(0x23009E7F);
        break;
    case GX_PERF0_TRIANGLES_SCISSORED:
        GX_WRITE_RAS_REG(0x23001E7F);
        break;
    case GX_PERF0_TRIANGLES_0TEX:
        GX_WRITE_RAS_REG(0x2300AC3F);
        break;
    case GX_PERF0_TRIANGLES_1TEX:
        GX_WRITE_RAS_REG(0x2300AC7F);
        break;
    case GX_PERF0_TRIANGLES_2TEX:
        GX_WRITE_RAS_REG(0x2300ACBF);
        break;
    case GX_PERF0_TRIANGLES_3TEX:
        GX_WRITE_RAS_REG(0x2300ACFF);
        break;
    case GX_PERF0_TRIANGLES_4TEX:
        GX_WRITE_RAS_REG(0x2300AD3F);
        break;
    case GX_PERF0_TRIANGLES_5TEX:
        GX_WRITE_RAS_REG(0x2300AD7F);
        break;
    case GX_PERF0_TRIANGLES_6TEX:
        GX_WRITE_RAS_REG(0x2300ADBF);
        break;
    case GX_PERF0_TRIANGLES_7TEX:
        GX_WRITE_RAS_REG(0x2300ADFF);
        break;
    case GX_PERF0_TRIANGLES_8TEX:
        GX_WRITE_RAS_REG(0x2300AE3F);
        break;
    case GX_PERF0_TRIANGLES_0CLR:
        GX_WRITE_RAS_REG(0x2300A27F);
        break;
    case GX_PERF0_TRIANGLES_1CLR:
        GX_WRITE_RAS_REG(0x2300A67F);
        break;
    case GX_PERF0_TRIANGLES_2CLR:
        GX_WRITE_RAS_REG(0x2300AA7F);
        break;
    case GX_PERF0_QUAD_0CVG:
        GX_WRITE_RAS_REG(0x2402C0C6);
        break;
    case GX_PERF0_QUAD_NON0CVG:
        GX_WRITE_RAS_REG(0x2402C16B);
        break;
    case GX_PERF0_QUAD_1CVG:
        GX_WRITE_RAS_REG(0x2402C0E7);
        break;
    case GX_PERF0_QUAD_2CVG:
        GX_WRITE_RAS_REG(0x2402C108);
        break;
    case GX_PERF0_QUAD_3CVG:
        GX_WRITE_RAS_REG(0x2402C129);
        break;
    case GX_PERF0_QUAD_4CVG:
        GX_WRITE_RAS_REG(0x2402C14A);
        break;
    case GX_PERF0_AVG_QUAD_CNT:
        GX_WRITE_RAS_REG(0x2402C1AD);
        break;
    case GX_PERF0_NONE:
    default:
        break;
    }
    __GXData->perf1 = perf1;
    switch (__GXData->perf1) {
    case GX_PERF1_TEXELS:
        GX_WRITE_RAS_REG(0x67000042);
        break;
    case GX_PERF1_TX_IDLE:
        GX_WRITE_RAS_REG(0x67000084);
        break;
    case GX_PERF1_TX_REGS:
        GX_WRITE_RAS_REG(0x67000063);
        break;
    case GX_PERF1_TX_MEMSTALL:
        GX_WRITE_RAS_REG(0x67000129);
        break;
    case GX_PERF1_TC_MISS:
        GX_WRITE_RAS_REG(0x67000252);
        break;
    case GX_PERF1_CLOCKS:
        GX_WRITE_RAS_REG(0x67000021);
        break;
    case GX_PERF1_TC_CHECK1_2:
        GX_WRITE_RAS_REG(0x6700014B);
        break;
    case GX_PERF1_TC_CHECK3_4:
        GX_WRITE_RAS_REG(0x6700018D);
        break;
    case GX_PERF1_TC_CHECK5_6:
        GX_WRITE_RAS_REG(0x670001CF);
        break;
    case GX_PERF1_TC_CHECK7_8:
        GX_WRITE_RAS_REG(0x67000211);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 2);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VC_MISSQ_FULL:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 3);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VC_MEMREQ_FULL:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 4);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VC_STATUS7:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 5);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VC_MISSREP_FULL:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 6);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VC_STREAMBUF_LOW:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 7);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VC_ALL_STALLS:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 9);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_VERTICES:
        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 8);
        GX_WRITE_U8(8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);
        break;
    case GX_PERF1_FIFO_REQ:
        GX_SET_CP_REG(3, 2);
        break;
    case GX_PERF1_CALL_REQ:
        GX_SET_CP_REG(3, 3);
        break;
    case GX_PERF1_VC_MISS_REQ:
        GX_SET_CP_REG(3, 4);
        break;
    case GX_PERF1_CP_ALL_REQ:
        GX_SET_CP_REG(3, 5);
        break;
    case GX_PERF1_NONE:
    default:
        break;
    }
    __GXData->bpSentNot = 0;
}

static inline u32 ReadCP(u32 lo, u32 hi) {
    u32 ctrH, ctrL, ctrH2;

    ctrH = GX_GET_CP_REG(hi);
    do {
        ctrH2 = ctrH;
        ctrL = GX_GET_CP_REG(lo);
        ctrH = GX_GET_CP_REG(hi);
    } while (ctrH != ctrH2);
    return (ctrH << 16) | ctrL;
}

/* near-miss: byte-identical with the extra flag -schedule off (the four counter-read loops load lo before hi,
 * unscheduled); at default flags the scheduler reorders them */
/* GXReadGPMetric */
void fn_80430F28(u32* cnt0, u32* cnt1) {
    u32 ctr0, ctr1, ctr2, ctr3;

    ctr0 = ReadCP(32, 33);
    ctr1 = ReadCP(34, 35);
    ctr2 = ReadCP(36, 37);
    ctr3 = ReadCP(38, 39);
    switch (__GXData->perf0) {
    case GX_PERF0_CLIP_RATIO:
        *cnt0 = (ctr1 * 1000) / ctr0;
        break;
    case GX_PERF0_VERTICES:
    case GX_PERF0_CLIP_VTX:
    case GX_PERF0_CLIP_CLKS:
    case GX_PERF0_XF_WAIT_IN:
    case GX_PERF0_XF_WAIT_OUT:
    case GX_PERF0_XF_XFRM_CLKS:
    case GX_PERF0_XF_LIT_CLKS:
    case GX_PERF0_XF_BOT_CLKS:
    case GX_PERF0_XF_REGLD_CLKS:
    case GX_PERF0_XF_REGRD_CLKS:
    case GX_PERF0_TRIANGLES:
    case GX_PERF0_TRIANGLES_CULLED:
    case GX_PERF0_TRIANGLES_PASSED:
    case GX_PERF0_TRIANGLES_SCISSORED:
    case GX_PERF0_TRIANGLES_0TEX:
    case GX_PERF0_TRIANGLES_1TEX:
    case GX_PERF0_TRIANGLES_2TEX:
    case GX_PERF0_TRIANGLES_3TEX:
    case GX_PERF0_TRIANGLES_4TEX:
    case GX_PERF0_TRIANGLES_5TEX:
    case GX_PERF0_TRIANGLES_6TEX:
    case GX_PERF0_TRIANGLES_7TEX:
    case GX_PERF0_TRIANGLES_8TEX:
    case GX_PERF0_TRIANGLES_0CLR:
    case GX_PERF0_TRIANGLES_1CLR:
    case GX_PERF0_TRIANGLES_2CLR:
    case GX_PERF0_QUAD_0CVG:
    case GX_PERF0_QUAD_NON0CVG:
    case GX_PERF0_QUAD_1CVG:
    case GX_PERF0_QUAD_2CVG:
    case GX_PERF0_QUAD_3CVG:
    case GX_PERF0_QUAD_4CVG:
    case GX_PERF0_AVG_QUAD_CNT:
    case GX_PERF0_CLOCKS:
        *cnt0 = ctr0;
        break;
    case GX_PERF0_NONE:
        *cnt0 = 0;
        break;
    default:
        *cnt0 = 0;
        break;
    }
    switch (__GXData->perf1) {
    case GX_PERF1_TEXELS:
        *cnt1 = ctr3 * 4;
        break;
    case GX_PERF1_TC_CHECK1_2:
        *cnt1 = ctr2 + ctr3 * 2;
        break;
    case GX_PERF1_TC_CHECK3_4:
        *cnt1 = ctr2 * 3 + ctr3 * 4;
        break;
    case GX_PERF1_TC_CHECK5_6:
        *cnt1 = ctr2 * 5 + ctr3 * 6;
        break;
    case GX_PERF1_TC_CHECK7_8:
        *cnt1 = ctr2 * 7 + ctr3 * 8;
        break;
    case GX_PERF1_TX_IDLE:
    case GX_PERF1_TX_REGS:
    case GX_PERF1_TX_MEMSTALL:
    case GX_PERF1_TC_MISS:
    case GX_PERF1_VC_ELEMQ_FULL:
    case GX_PERF1_VC_MISSQ_FULL:
    case GX_PERF1_VC_MEMREQ_FULL:
    case GX_PERF1_VC_STATUS7:
    case GX_PERF1_VC_MISSREP_FULL:
    case GX_PERF1_VC_STREAMBUF_LOW:
    case GX_PERF1_VC_ALL_STALLS:
    case GX_PERF1_VERTICES:
    case GX_PERF1_CLOCKS:
        *cnt1 = ctr3;
        break;
    case GX_PERF1_FIFO_REQ:
    case GX_PERF1_CALL_REQ:
    case GX_PERF1_VC_MISS_REQ:
    case GX_PERF1_CP_ALL_REQ:
        *cnt1 = ctr2;
        break;
    case GX_PERF1_NONE:
        *cnt1 = 0;
        break;
    default:
        *cnt1 = 0;
        break;
    }
}

/* GXClearGPMetric */
void fn_804310D0(void) {
    GX_SET_CP_REG(2, 4);
}
