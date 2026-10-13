/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80428F14-0x80429FF0: the GXInit.c tail (__GXInitRevisionBits, GXInit, __GXInitGX), built with -opt nopeephole.
 * GXFifo.c (0x80429FF0-0x8042AB48) is its own unit, dolphin/gx/GXFifo.c (split 2026-10-13).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 *
 * __GXInitRevisionBits (0x80428F14), GXInit (0x804290B8) and __GXInitGX (0x804296B8, not written here) are the tail
 * of GXInit.c, which is compiled with -opt nopeephole (like dolphin/gx/tu_80428C64.c); the GXFifo.c part from
 * fn_80429FF0 on needs peephole ON. The bodies below are the dolsdk2004 GXInit.c ones (adonis-singh/re4
 * src/lib/GXInit.c) and are score_variants MATCH (105/105, 384/384) with -opt nopeephole, so this unit needs a
 * split at 0x80429FF0 (head with nopeephole). GXInit also needs FifoObj as a TU-local static (below): with an
 * extern the address of FifoObj is not hoisted to the function start (143 diff slots instead of 0).
 * __GXInitGX (590 insns) needs the same flags plus the GXInit.c statics defined in the TU (DefaultTexData,
 * GXDefaultVATList, GXDefaultProjData at lbl_806344A0+0x60/+0x80/+0x150, and 0x60 bytes of string pool before
 * them): with those as TU statics the dolsdk2004 body has 3 diff slots (the data offsets), with externs 544.
 */
#include <dolphin/gx.h>
#include <dolphin/os.h>
#include <dolphin/base/PPCArch.h>

#include "__gx.h"

/* GXFifo.c part of this unit. Placeholder names (symbols.txt) with the likely SDK names:
 * fn_80429FF0 GXCPInterruptHandler, fn_8042A190 GXInitFifoPtrs, fn_8042A200 GXInitFifoLimits,
 * fn_8042A4AC GXGetFifoPtrs, fn_8042A544 GXSetBreakPtCallback, fn_8042A588 GXEnableBreakPt,
 * fn_8042A614 GXDisableBreakPt, fn_8042A6B4 __GXFifoReadEnable, fn_8042A6D8 __GXFifoReadDisable,
 * fn_8042A6FC __GXFifoLink, fn_8042A730 __GXWriteFifoIntEnable, fn_8042A760 __GXWriteFifoIntReset,
 * fn_8042A790 __GXCleanGPFifo, fn_8042A890 GXGetCPUFifo, fn_8042A898 GXGetGPFifo,
 * fn_8042A8A0 GXRedirectWriteGatherPipe, fn_8042A9A8 GXRestoreWriteGatherPipe.
 * Other placeholder callees: fn_80437ED4 OSResumeThread, fn_8043815C OSSuspendThread,
 * fn_80437444 OSGetCurrentThread, fn_80433814 OSClearContext, fn_8043364C OSSetCurrentContext,
 * fn_8041A5DC PPCSync, fn_8041A680 PPCMfwpar, fn_8042C020 GXFlush. */
s32 fn_80437ED4(OSThread* thread);
s32 fn_8043815C(OSThread* thread);
OSThread* fn_80437444(void);
void fn_80433814(OSContext* context);
void fn_8043364C(OSContext* context);
void fn_8041A5DC(void);
u32 fn_8041A680(void);
void fn_8042C020(void);

extern __GXFifoObj* lbl_806EF760; /* CPUFifo */
extern __GXFifoObj* lbl_806EF764; /* GPFifo */
extern OSThread* lbl_806EF768;    /* __GXCurrentThread */
extern u8 lbl_806EF76C;           /* CPGPLinked */
extern BOOL lbl_806EF770;         /* GXOverflowSuspendInProgress */
extern GXBreakPtCallback lbl_806EF774;
extern u32 lbl_806EF778;          /* __GXOverflowCount */
extern u32 lbl_806EF77C;          /* BreakPoint address */

void fn_80429FF0(__OSInterrupt interrupt, OSContext* context);
void fn_8042A190(GXFifoObj* fifo, void* rd, void* wr);
void fn_8042A200(GXFifoObj* fifo, u32 hi, u32 lo);
void fn_8042A4AC(GXFifoObj* fifo, void** readPtr, void** writePtr);
GXBreakPtCallback fn_8042A544(GXBreakPtCallback cb);
void fn_8042A588(void* break_pt);
void fn_8042A614(void);
void fn_8042A6B4(void);
void fn_8042A6D8(void);
void fn_8042A6FC(u8 enable);
void fn_8042A730(u8 hi, u8 lo);
void fn_8042A760(u8 hi, u8 lo);
void fn_8042A790(void);
GXFifoObj* fn_8042A890(void);
GXFifoObj* fn_8042A898(void);
volatile void* fn_8042A8A0(void* ptr);
void fn_8042A9A8(void);

void __GXInitRevisionBits(void);

/* flags: matches only with -opt nopeephole (GXInit.c range) */
#define SOME_SET_REG_MACRO(reg, size, shift, val)                                                   	do {                                                                                            		(reg) = (u32)__rlwimi((u32)(reg), (val), (shift), (32 - (shift) - (size)), (31 - (shift))); 	} while (0);

void __GXInitRevisionBits(void) {
    u32 i;

    for (i = 0; i < 8; i++) {
        s32 regAddr;
        SOME_SET_REG_MACRO(__GXData->vatA[i], 1, 30, 1);
        SOME_SET_REG_MACRO(__GXData->vatB[i], 1, 31, 1);

        GX_WRITE_U8(0x8);
        GX_WRITE_U8(i | 0x80);
        GX_WRITE_U32(__GXData->vatB[i]);
        regAddr = i - 12;
    }

    {
        u32 reg1 = 0;
        u32 reg2 = 0;

        SOME_SET_REG_MACRO(reg1, 1, 0, 1);
        SOME_SET_REG_MACRO(reg1, 1, 1, 1);
        SOME_SET_REG_MACRO(reg1, 1, 2, 1);
        SOME_SET_REG_MACRO(reg1, 1, 3, 1);
        SOME_SET_REG_MACRO(reg1, 1, 4, 1);
        SOME_SET_REG_MACRO(reg1, 1, 5, 1);
        GX_WRITE_XF_REG(0, reg1);

        SOME_SET_REG_MACRO(reg2, 1, 0, 1);
        GX_WRITE_XF_REG(0x12, reg2);
    }

    {
        u32 reg = 0;
        SOME_SET_REG_MACRO(reg, 1, 0, 1);
        SOME_SET_REG_MACRO(reg, 1, 1, 1);
        SOME_SET_REG_MACRO(reg, 1, 2, 1);
        SOME_SET_REG_MACRO(reg, 1, 3, 1);
        SOME_SET_REG_MACRO(reg, 8, 24, 0x58);
        GX_WRITE_RAS_REG(reg);
    }
}

void __GXPEInit(void);
void __GXSetTmemConfig(u32 config);
GXTexRegion* fn_80428C64(const GXTexObj* t_obj, GXTexMapID id);
GXTlutRegion* fn_80428D60(u32 idx);

extern const char* __GXVersion;
extern OSResetFunctionInfo GXResetFuncInfo;
extern u32 GXTexRegionAddrTable[];
extern u32 lbl_806EF75C;
/* lbl_806344A0 (0x16C bytes) holds DefaultTexData at +0x60, GXDefaultVATList at +0x80 and GXDefaultProjData
 * at +0x150: they are used by __GXInitGX, which is not written here */
static GXFifoObj FifoObj; /* GXInit.c static, .bss 0x806DE418 (symbols.txt: FifoObj) */

/* flags: matches only with -opt nopeephole (GXInit.c range) */
GXFifoObj* GXInit(void* base, u32 size) {
    u32 i;
    u32 reg;
    u32 freqBase;

    OSRegisterVersion(__GXVersion);

    __GXData->inDispList = FALSE;
    __GXData->dlSaveContext = TRUE;
    __GXData->abtWaitPECopy = 1;
    __GXData->tcsManEnab = FALSE;
    __GXData->tevTcEnab = FALSE;

    GXSetMisc(GX_MT_XF_FLUSH, 0);

    __piReg = OSPhysicalToUncached(0xC003000);
    __cpReg = OSPhysicalToUncached(0xC000000);
    __peReg = OSPhysicalToUncached(0xC001000);
    __memReg = OSPhysicalToUncached(0xC004000);
    __GXFifoInit();
    GXInitFifoBase(&FifoObj, base, size);
    GXSetCPUFifo(&FifoObj);
    GXSetGPFifo(&FifoObj);

    if (!lbl_806EF75C) {
        OSRegisterResetFunction(&GXResetFuncInfo);
        lbl_806EF75C = 1;
    }

    __GXPEInit();
    {
        u32 hid2 = PPCMfhid2();

        PPCMtwpar(OSUncachedToPhysical((void*)GXFIFO_ADDR));
        hid2 |= 0x40000000;
        PPCMthid2(hid2);
    }

    __GXData->genMode = 0;
    SET_REG_FIELD(0, __GXData->genMode, 8, 24, 0);
    __GXData->bpMask = 255;
    SET_REG_FIELD(0, __GXData->bpMask, 8, 24, 0x0F);
    __GXData->lpSize = 0;
    SET_REG_FIELD(0, __GXData->lpSize, 8, 24, 0x22);

    for (i = 0; i < 16; ++i) {
        __GXData->tevc[i] = 0;
        __GXData->teva[i] = 0;
        __GXData->tref[i / 2] = 0;
        __GXData->texmapId[i] = GX_TEXMAP_NULL;
        SET_REG_FIELD(1130, __GXData->tevc[i], 8, 24, 0xC0 + i * 2);
        SET_REG_FIELD(1131, __GXData->teva[i], 8, 24, 0xC1 + i * 2);
        SET_REG_FIELD(1133, __GXData->tevKsel[i / 2], 8, 24, 0xF6 + i / 2);
        SET_REG_FIELD(1135, __GXData->tref[i / 2], 8, 24, 0x28 + i / 2);
    }

    __GXData->iref = 0;
    SET_REG_FIELD(0, __GXData->iref, 8, 24, 0x27);

    for (i = 0; i < 8; ++i) {
        __GXData->suTs0[i] = 0;
        __GXData->suTs1[i] = 0;
        SET_REG_FIELD(1144, __GXData->suTs0[i], 8, 24, 0x30 + i * 2);
        SET_REG_FIELD(1145, __GXData->suTs1[i], 8, 24, 0x31 + i * 2);
    }

    SET_REG_FIELD(0, __GXData->suScis0, 8, 24, 0x20);
    SET_REG_FIELD(0, __GXData->suScis1, 8, 24, 0x21);
    SET_REG_FIELD(0, __GXData->cmode0, 8, 24, 0x41);
    SET_REG_FIELD(0, __GXData->cmode1, 8, 24, 0x42);
    SET_REG_FIELD(0, __GXData->zmode, 8, 24, 0x40);
    SET_REG_FIELD(0, __GXData->peCtrl, 8, 24, 0x43);
    SET_REG_FIELD(0, __GXData->cpTex, 2, 7, 0);

    __GXData->zScale = 1.6777216E7f;
    __GXData->zOffset = 0.0f;
    __GXData->dirtyState = 0;
    __GXData->dirtyVAT = FALSE;

    freqBase = __OSBusClock / 500;
    __GXFlushTextureState();
    reg = (freqBase >> 11) | 0x400 | 0x69000000;
    GX_WRITE_RAS_REG(reg);

    __GXFlushTextureState();
    reg = (freqBase / 0x1080) | 0x200 | 0x46000000;
    GX_WRITE_RAS_REG(reg);

    __GXInitRevisionBits();

    for (i = 0; i < 8; i++) {
        GXInitTexCacheRegion(&__GXData->TexRegions0[i], GX_FALSE, GXTexRegionAddrTable[i],
                             GX_TEXCACHE_32K, GXTexRegionAddrTable[i + 8], GX_TEXCACHE_32K);
        GXInitTexCacheRegion(&__GXData->TexRegions1[i], GX_FALSE, GXTexRegionAddrTable[i + 16],
                             GX_TEXCACHE_32K, GXTexRegionAddrTable[i + 24], GX_TEXCACHE_32K);
        GXInitTexCacheRegion(&__GXData->TexRegions2[i], GX_TRUE, GXTexRegionAddrTable[i + 32],
                             GX_TEXCACHE_32K, GXTexRegionAddrTable[i + 40], GX_TEXCACHE_32K);
    }

    for (i = 0; i < 16; i++) {
        GXInitTlutRegion(&__GXData->TlutRegions[i], 0xC0000 + 0x2000 * i, GX_TLUT_256);
    }

    for (i = 0; i < 4; i++) {
        GXInitTlutRegion(&__GXData->TlutRegions[i + 16], 0xE0000 + 0x8000 * i, GX_TLUT_1K);
    }

    {
        u32 reg = 0;
        GX_SET_CP_REG(3, reg);

        SET_REG_FIELD(0, __GXData->perfSel, 4, 4, 0);
        GX_WRITE_U8(0x8);
        GX_WRITE_U8(0x20);
        GX_WRITE_U32(__GXData->perfSel);

        reg = 0;
        GX_WRITE_XF_REG(6, reg);

        reg = 0x23000000;
        GX_WRITE_RAS_REG(reg);

        reg = 0x24000000;
        GX_WRITE_RAS_REG(reg);

        reg = 0x67000000;
        GX_WRITE_RAS_REG(reg);
    }

    __GXSetIndirectMask(0);
    __GXSetTmemConfig(2);
    __GXInitGX();

    return &FifoObj;
}
