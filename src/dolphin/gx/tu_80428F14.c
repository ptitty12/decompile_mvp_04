/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80428F14-0x8042AB48 (code-only unit, 24 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
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

/* near-miss: loop body and the three register writes are right, but the original has empty
 * jump-to-next blocks (b .+4) before the loop that split the scheduling; not reproduced */
void __GXInitRevisionBits(void) {
    u32 i;
    u32 reg;

    for (i = 0; i < 8; i++) {
        SET_REG_FIELD(0, __GXData->vatA[i], 1, 30, 1);
        SET_REG_FIELD(0, __GXData->vatB[i], 1, 31, 1);
        GX_WRITE_U8(8);
        GX_WRITE_U8(i | 0x80);
        GX_WRITE_U32(__GXData->vatB[i]);
    }
    reg = 0;
    SET_REG_FIELD(0, reg, 1, 0, 1);
    SET_REG_FIELD(0, reg, 1, 1, 1);
    SET_REG_FIELD(0, reg, 1, 2, 1);
    SET_REG_FIELD(0, reg, 1, 3, 1);
    SET_REG_FIELD(0, reg, 1, 4, 1);
    SET_REG_FIELD(0, reg, 1, 5, 1);
    GX_WRITE_XF_REG(0, reg);
    reg = 0;
    SET_REG_FIELD(0, reg, 1, 0, 1);
    GX_WRITE_XF_REG(0x12, reg);
    reg = 0;
    SET_REG_FIELD(0, reg, 1, 0, 1);
    SET_REG_FIELD(0, reg, 1, 1, 1);
    SET_REG_FIELD(0, reg, 1, 2, 1);
    SET_REG_FIELD(0, reg, 1, 3, 1);
    SET_REG_FIELD(0, reg, 8, 24, 0x58);
    GX_WRITE_RAS_REG(reg);
}

static inline void GXUnderflowHandler(void) {
    fn_80437ED4(lbl_806EF768);
    lbl_806EF770 = 0;
    fn_8042A760(1, 1);
    fn_8042A730(1, 0);
}

static inline void GXOverflowHandler(void) {
    lbl_806EF778++;
    fn_8042A730(0, 1);
    fn_8042A760(1, 0);
    lbl_806EF770 = 1;
    fn_8043815C(lbl_806EF768);
}

static inline void GXBreakPointHandler(OSContext* context) {
    OSContext exceptContext;

    __GXData->cpEnable = (u32)__rlwimi(__GXData->cpEnable, 0, 5, 26, 26);
    GX_SET_CP_REG(1, __GXData->cpEnable);
    if (lbl_806EF774) {
        fn_80433814(&exceptContext);
        fn_8043364C(&exceptContext);
        lbl_806EF774();
        fn_80433814(&exceptContext);
        fn_8043364C(context);
    }
}

void fn_80429FF0(__OSInterrupt interrupt, OSContext* context) {
    __GXData->cpStatus = GX_GET_CP_REG(0);
    if (GET_REG_FIELD(__GXData->cpEnable, 1, 3) && GET_REG_FIELD(__GXData->cpStatus, 1, 1)) {
        GXUnderflowHandler();
    }
    if (GET_REG_FIELD(__GXData->cpEnable, 1, 2) && GET_REG_FIELD(__GXData->cpStatus, 1, 0)) {
        GXOverflowHandler();
    }
    if (GET_REG_FIELD(__GXData->cpEnable, 1, 5) && GET_REG_FIELD(__GXData->cpStatus, 1, 4)) {
        GXBreakPointHandler(context);
    }
}

void GXInitFifoBase(GXFifoObj* fifo, void* base, u32 size) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;

    realFifo->base = base;
    realFifo->top = (u8*)base + size - 4;
    realFifo->size = size;
    realFifo->count = 0;
    fn_8042A200(fifo, size - 0x4000, (size >> 1) & ~31);
    fn_8042A190(fifo, base, base);
}

void fn_8042A190(GXFifoObj* fifo, void* rd, void* wr) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    realFifo->rdPtr = rd;
    realFifo->wrPtr = wr;
    realFifo->count = (u8*)wr - (u8*)rd;
    if (realFifo->count < 0) {
        realFifo->count += realFifo->size;
    }
    OSRestoreInterrupts(enabled);
}

void fn_8042A200(GXFifoObj* fifo, u32 hi, u32 lo) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;

    realFifo->hiWatermark = hi;
    realFifo->loWatermark = lo;
}

void GXSetCPUFifo(GXFifoObj* fifo) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    lbl_806EF760 = realFifo;
    if (realFifo == lbl_806EF764) {
        u32 reg = 0;
        GX_SET_PI_REG(3, (u32)realFifo->base & 0x3FFFFFFF);
        GX_SET_PI_REG(4, (u32)realFifo->top & 0x3FFFFFFF);
        reg = (u32)__rlwimi(reg, (u32)realFifo->wrPtr, 0, 6, 26);
        reg = (u32)__rlwimi(reg, 0, 26, 5, 5);
        GX_SET_PI_REG(5, reg);
        lbl_806EF76C = 1;
        fn_8042A760(1, 1);
        fn_8042A730(1, 0);
        fn_8042A6FC(1);
    } else {
        if (lbl_806EF76C) {
            fn_8042A6FC(0);
            lbl_806EF76C = 0;
        }
        fn_8042A730(0, 0);
        {
        u32 reg = 0;
        GX_SET_PI_REG(3, (u32)realFifo->base & 0x3FFFFFFF);
        GX_SET_PI_REG(4, (u32)realFifo->top & 0x3FFFFFFF);
        reg = (u32)__rlwimi(reg, (u32)realFifo->wrPtr, 0, 6, 26);
        reg = (u32)__rlwimi(reg, 0, 26, 5, 5);
        GX_SET_PI_REG(5, reg);
        }
    }
    fn_8041A5DC();
    OSRestoreInterrupts(enabled);
}

void GXSetGPFifo(GXFifoObj* fifo) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    fn_8042A6D8();
    fn_8042A730(0, 0);
    lbl_806EF764 = realFifo;
    GX_SET_CP_REG(16, (u32)realFifo->base);
    GX_SET_CP_REG(18, (u32)realFifo->top);
    GX_SET_CP_REG(24, realFifo->count);
    GX_SET_CP_REG(26, (u32)realFifo->wrPtr);
    GX_SET_CP_REG(28, (u32)realFifo->rdPtr);
    GX_SET_CP_REG(20, realFifo->hiWatermark);
    GX_SET_CP_REG(22, realFifo->loWatermark);
    GX_SET_CP_REG(17, ((u32)realFifo->base >> 16) & 0x3FFF);
    GX_SET_CP_REG(19, ((u32)realFifo->top >> 16) & 0x3FFF);
    GX_SET_CP_REG(25, realFifo->count >> 16);
    GX_SET_CP_REG(27, ((u32)realFifo->wrPtr >> 16) & 0x3FFF);
    GX_SET_CP_REG(29, ((u32)realFifo->rdPtr >> 16) & 0x3FFF);
    GX_SET_CP_REG(21, realFifo->hiWatermark >> 16);
    GX_SET_CP_REG(23, realFifo->loWatermark >> 16);
    fn_8041A5DC();
    if (lbl_806EF760 == lbl_806EF764) {
        lbl_806EF76C = 1;
        fn_8042A730(1, 0);
        fn_8042A6FC(1);
    } else {
        lbl_806EF76C = 0;
        fn_8042A730(0, 0);
        fn_8042A6FC(0);
    }
    fn_8042A760(1, 1);
    fn_8042A6B4();
    OSRestoreInterrupts(enabled);
}

void fn_8042A4AC(GXFifoObj* fifo, void** readPtr, void** writePtr) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;

    if (realFifo == lbl_806EF760) {
        realFifo->wrPtr = (void*)(((u32)GX_GET_PI_REG(5) & 0xFBFFFFFF) + 0x80000000);
    }
    if (realFifo == lbl_806EF764) {
        u32 ptr = (GX_GET_CP_REG(29) << 16) | GX_GET_CP_REG(28);
        realFifo->rdPtr = (void*)(ptr + 0x80000000);
        realFifo->count = (GX_GET_CP_REG(25) << 16) | GX_GET_CP_REG(24);
    } else {
        realFifo->count = (u8*)realFifo->wrPtr - (u8*)realFifo->rdPtr;
        if (realFifo->count < 0) {
            realFifo->count += realFifo->size;
        }
    }
    *readPtr = realFifo->rdPtr;
    *writePtr = realFifo->wrPtr;
}

GXBreakPtCallback fn_8042A544(GXBreakPtCallback cb) {
    GXBreakPtCallback oldCB;
    BOOL enabled;

    oldCB = lbl_806EF774;
    enabled = OSDisableInterrupts();
    lbl_806EF774 = cb;
    OSRestoreInterrupts(enabled);
    return oldCB;
}

void fn_8042A588(void* break_pt) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    fn_8042A6D8();
    GX_SET_CP_REG(30, (u32)break_pt);
    GX_SET_CP_REG(31, ((u32)break_pt >> 16) & 0x3FFF);
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 1, 1);
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 5, 1);
    GX_SET_CP_REG(1, __GXData->cpEnable);
    lbl_806EF77C = (u32)break_pt;
    fn_8042A6B4();
    OSRestoreInterrupts(enabled);
}

void fn_8042A614(void) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 1, 0);
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 5, 0);
    GX_SET_CP_REG(1, __GXData->cpEnable);
    lbl_806EF77C = 0;
    OSRestoreInterrupts(enabled);
}

void __GXFifoInit(void) {
    __OSSetInterruptHandler(17, fn_80429FF0);
    __OSUnmaskInterrupts(0x4000);
    lbl_806EF768 = fn_80437444();
    lbl_806EF770 = 0;
    lbl_806EF760 = NULL;
    lbl_806EF764 = NULL;
}

void fn_8042A6B4(void) {
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 0, 1);
    GX_SET_CP_REG(1, __GXData->cpEnable);
}

void fn_8042A6D8(void) {
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 0, 0);
    GX_SET_CP_REG(1, __GXData->cpEnable);
}

void fn_8042A6FC(u8 enable) {
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 4, enable ? 1 : 0);
    GX_SET_CP_REG(1, __GXData->cpEnable);
}

void fn_8042A730(u8 hi, u8 lo) {
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 2, hi);
    SET_REG_FIELD(0, __GXData->cpEnable, 1, 3, lo);
    GX_SET_CP_REG(1, __GXData->cpEnable);
}

void fn_8042A760(u8 hi, u8 lo) {
    SET_REG_FIELD(0, __GXData->cpClr, 1, 0, hi);
    SET_REG_FIELD(0, __GXData->cpClr, 1, 1, lo);
    GX_SET_CP_REG(2, __GXData->cpClr);
}

void fn_8042A790(void) {
    GXFifoObj tempFifo;
    GXFifoObj* gpFifo;
    GXFifoObj* cpuFifo;
    void* tempBase;
    volatile u32 pad[3]; /* placeholder for 12 unidentified bytes of stack before tempFifo */

    gpFifo = fn_8042A898();
    if (gpFifo == NULL) {
        return;
    }
    cpuFifo = fn_8042A890();
    tempBase = ((__GXFifoObj*)gpFifo)->base;
    tempFifo = *gpFifo;
    fn_8042A190(&tempFifo, tempBase, tempBase);
    GXSetGPFifo(&tempFifo);
    if (cpuFifo == gpFifo) {
        GXSetCPUFifo(&tempFifo);
    }
    fn_8042A190(gpFifo, tempBase, tempBase);
    GXSetGPFifo(gpFifo);
    if (cpuFifo == gpFifo) {
        GXSetCPUFifo(cpuFifo);
    }
}

GXFifoObj* fn_8042A890(void) {
    return (GXFifoObj*)lbl_806EF760;
}

GXFifoObj* fn_8042A898(void) {
    return (GXFifoObj*)lbl_806EF764;
}

/* near-miss: only the scheduling of the final rlwimi/li differs */
volatile void* fn_8042A8A0(void* ptr) {
    u32 reg = 0;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    fn_8042C020();
    while (fn_8041A680() & 1) {
    }
    PPCMtwpar(OSUncachedToPhysical((void*)0xCC008000));
    if (lbl_806EF76C) {
        fn_8042A6FC(0);
        fn_8042A730(0, 0);
    }
    reg = (u32)__rlwimi(reg, (u32)ptr, 0, 6, 26);
    lbl_806EF760->wrPtr = (void*)(((u32)GX_GET_PI_REG(5) & 0xFBFFFFFF) + 0x80000000);
    reg = (u32)__rlwimi(reg, 0, 26, 5, 5);
    GX_SET_PI_REG(3, 0);
    GX_SET_PI_REG(4, 0x04000000);
    GX_SET_PI_REG(5, reg);
    fn_8041A5DC();
    OSRestoreInterrupts(enabled);
    return &GXWGFifo;
}

void fn_8042A9A8(void) {
    u32 reg = 0;
    BOOL enabled;
    u32 i;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 31; i++) {
        GX_WRITE_U8(0);
    }
    fn_8041A5DC();
    while (fn_8041A680() & 1) {
    }
    PPCMtwpar(OSUncachedToPhysical((void*)0xCC008000));
    GX_SET_PI_REG(3, (u32)lbl_806EF760->base & 0x3FFFFFFF);
    GX_SET_PI_REG(4, (u32)lbl_806EF760->top & 0x3FFFFFFF);
    reg = (u32)__rlwimi(reg, (u32)lbl_806EF760->wrPtr, 0, 6, 26);
    reg = (u32)__rlwimi(reg, 0, 26, 5, 5);
    GX_SET_PI_REG(5, reg);
    if (lbl_806EF76C) {
        fn_8042A760(1, 1);
        fn_8042A730(1, 0);
        fn_8042A6FC(1);
    }
    fn_8041A5DC();
    OSRestoreInterrupts(enabled);
}
