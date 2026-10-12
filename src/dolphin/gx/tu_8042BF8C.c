/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8042BF8C-0x8042C830 (code-only unit, 20 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin/gx.h>
#include <dolphin/os.h>

#include "__gx.h"

/* GXMisc.c / GXCpu2Efb.c pieces. Callees that symbols.txt names only by address:
 * fn_8041A5DC PPCSync, fn_80438628 OSGetTime, fn_804382CC OSSleepThread, fn_804383B8 OSWakeupThread,
 * fn_80437434 OSInitThreadQueue, fn_80433814 OSClearContext, fn_8043364C OSSetCurrentContext,
 * fn_8042A898 __GXIsGPFifoReady, fn_8042A790 __GXCleanGPFifo. */
void fn_8041A5DC(void);
OSTime fn_80438628(void);
void fn_804382CC(OSThreadQueue* queue);
void fn_804383B8(OSThreadQueue* queue);
void fn_80437434(OSThreadQueue* queue);
void fn_80433814(OSContext* context);
void fn_8043364C(OSContext* context);
u32 fn_8042A898(void);
void fn_8042A790(void);

extern GXDrawSyncCallback lbl_806EF780;
extern GXDrawDoneCallback lbl_806EF784;
extern u8 lbl_806EF788;
extern OSThreadQueue lbl_806EF78C;

void fn_8042C020(void);
void fn_8042C07C(void);
void fn_8042C1E8(void);
void fn_8042C3B0(u16 token);
void fn_8042C464(void);
void fn_8042C4E4(void);
void fn_8042C508(GXCompare func, u8 threshold);
void fn_8042C51C(GXAlphaReadMode mode);
void fn_8042C53C(GXBool dither);
void fn_8042C554(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op);
void fn_8042C5B8(GXBool update_enable);
void fn_8042C5D0(GXBool enable, u8 alpha);
void fn_8042C5F4(GXBool update_enable);
void fn_8042C60C(GXBool compare_enable, GXCompare func, GXBool update_enable);
GXDrawSyncCallback fn_8042C62C(GXDrawSyncCallback cb);
void fn_8042C670(__OSInterrupt interrupt, OSContext* context);
GXDrawDoneCallback fn_8042C6F8(GXDrawDoneCallback cb);
void fn_8042C73C(__OSInterrupt interrupt, OSContext* context);

void GXSetMisc(GXMiscToken token, u32 val) {
    switch (token) {
    case GX_MT_NULL:
        break;
    case GX_MT_XF_FLUSH:
        __GXData->vNum = val;
        __GXData->vNumNot = !__GXData->vNum;
        __GXData->bpSentNot = 1;
        if (__GXData->vNum) {
            __GXData->dirtyState |= 8;
        }
        break;
    case GX_MT_DL_SAVE_CONTEXT:
        __GXData->dlSaveContext = (val != 0);
        break;
    case GX_MT_ABORT_WAIT_COPYOUT:
        __GXData->abtWaitPECopy = (val != 0);
        break;
    }
}

/* GXFlush */
void fn_8042C020(void) {
    if (__GXData->dirtyState) {
        __GXSetDirtyState();
    }
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    fn_8041A5DC();
}

static inline void AbortWait(u32 clocks) {
    OSTime time0, time1;

    time0 = fn_80438628();
    do {
        time1 = fn_80438628();
    } while (time1 - time0 <= clocks / 2);
}

static inline u32 ReadMEM(u32 hiIdx, u32 loIdx) {
    u32 hi, hi2, lo;

    hi = GX_GET_MEM_REG(hiIdx);
    do {
        hi2 = hi;
        lo = GX_GET_MEM_REG(loIdx);
        hi = GX_GET_MEM_REG(hiIdx);
    } while (hi != hi2);
    return (hi << 16) | lo;
}

/* near-miss: loop copy placement (target copies the old count at the loop end, we copy at the top) */
/* __GXAbort */
void fn_8042C07C(void) {
    u32 cnt0, cnt1;
    volatile u32* piReg;

    if (__GXData->abtWaitPECopy && fn_8042A898()) {
        cnt1 = ReadMEM(39, 40);
        do {
            cnt0 = cnt1;
            AbortWait(16);
            cnt1 = ReadMEM(39, 40);
        } while (cnt1 != cnt0);
    }
    piReg = (volatile u32*)0xCC003000;
    piReg[6] = 1;
    AbortWait(100);
    piReg[6] = 0;
    AbortWait(10);
}

/* near-miss: same loop copy placement as fn_8042C07C (its body is inlined here) */
/* GXAbortFrame */
void fn_8042C1E8(void) {
    u32 cnt0, cnt1;
    volatile u32* piReg;

    if (__GXData->abtWaitPECopy && fn_8042A898()) {
        cnt1 = ReadMEM(39, 40);
        do {
            cnt0 = cnt1;
            AbortWait(16);
            cnt1 = ReadMEM(39, 40);
        } while (cnt1 != cnt0);
    }
    piReg = (volatile u32*)0xCC003000;
    piReg[6] = 1;
    AbortWait(100);
    piReg[6] = 0;
    AbortWait(10);
    if (fn_8042A898()) {
        fn_8042A790();
        __GXInitRevisionBits();
        __GXData->dirtyState = 0;
        fn_8042C020();
    }
}

/* GXSetDrawSync */
void fn_8042C3B0(u16 token) {
    u32 reg;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    reg = 0x48000000 | token;
    GX_WRITE_RAS_REG(reg);
    SET_REG_FIELD(0, reg, 16, 0, token);
    SET_REG_FIELD(0, reg, 8, 24, 0x47);
    GX_WRITE_RAS_REG(reg);
    fn_8042C020();
    OSRestoreInterrupts(enabled);
    __GXData->bpSentNot = 0;
}

static inline void GXSetDrawDoneInt(void) {
    u32 reg;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    reg = 0x45000002;
    GX_WRITE_RAS_REG(reg);
    fn_8042C020();
    lbl_806EF788 = 0;
    OSRestoreInterrupts(enabled);
}

static inline void GXWaitDrawDoneInt(void) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    while (!lbl_806EF788) {
        fn_804382CC(&lbl_806EF78C);
    }
    OSRestoreInterrupts(enabled);
}

/* GXDrawDone */
void fn_8042C464(void) {
    GXSetDrawDoneInt();
    GXWaitDrawDoneInt();
}

/* GXPixModeSync */
void fn_8042C4E4(void) {
    GX_WRITE_RAS_REG(__GXData->peCtrl);
    __GXData->bpSentNot = 0;
}

/* GXPokeAlphaMode */
void fn_8042C508(GXCompare func, u8 threshold) {
    GX_SET_PE_REG(3, (func << 8) | threshold);
}

/* GXPokeAlphaRead */
void fn_8042C51C(GXAlphaReadMode mode) {
    u32 reg = 0;

    SET_REG_FIELD(0, reg, 2, 0, mode);
    SET_REG_FIELD(0, reg, 1, 2, 1);
    GX_SET_PE_REG(4, reg);
}

/* GXPokeDither */
void fn_8042C53C(GXBool dither) {
    u32 reg = GX_GET_PE_REG(1);

    SET_REG_FIELD(0, reg, 1, 4, dither);
    GX_SET_PE_REG(1, reg);
}

/* GXPokeBlendMode */
void fn_8042C554(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op) {
    u32 reg = GX_GET_PE_REG(1);

    SET_REG_FIELD(0, reg, 1, 0, (type == GX_BM_BLEND) || (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0, reg, 1, 11, (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0, reg, 1, 1, (type == GX_BM_LOGIC));
    SET_REG_FIELD(0, reg, 4, 12, op);
    SET_REG_FIELD(0, reg, 3, 8, src_factor);
    SET_REG_FIELD(0, reg, 3, 5, dst_factor);
    SET_REG_FIELD(0, reg, 8, 24, 0x41);
    GX_SET_PE_REG(1, reg);
}

/* GXPokeColorUpdate */
void fn_8042C5B8(GXBool update_enable) {
    u32 reg = GX_GET_PE_REG(1);

    SET_REG_FIELD(0, reg, 1, 3, update_enable);
    GX_SET_PE_REG(1, reg);
}

/* GXPokeDstAlpha */
void fn_8042C5D0(GXBool enable, u8 alpha) {
    u32 reg = 0;

    SET_REG_FIELD(0, reg, 8, 0, alpha);
    SET_REG_FIELD(0, reg, 1, 8, enable);
    GX_SET_PE_REG(2, reg);
}

/* GXPokeAlphaUpdate */
void fn_8042C5F4(GXBool update_enable) {
    u32 reg = GX_GET_PE_REG(1);

    SET_REG_FIELD(0, reg, 1, 2, update_enable);
    GX_SET_PE_REG(1, reg);
}

/* GXPokeZMode */
void fn_8042C60C(GXBool compare_enable, GXCompare func, GXBool update_enable) {
    u32 reg = 0;

    SET_REG_FIELD(0, reg, 1, 0, compare_enable);
    SET_REG_FIELD(0, reg, 3, 1, func);
    SET_REG_FIELD(0, reg, 1, 4, update_enable);
    GX_SET_PE_REG(0, reg);
}

/* GXSetDrawSyncCallback */
GXDrawSyncCallback fn_8042C62C(GXDrawSyncCallback cb) {
    GXDrawSyncCallback old;
    BOOL enabled;

    old = lbl_806EF780;
    enabled = OSDisableInterrupts();
    lbl_806EF780 = cb;
    OSRestoreInterrupts(enabled);
    return old;
}

/* GXTokenInterruptHandler */
void fn_8042C670(__OSInterrupt interrupt, OSContext* context) {
    u16 token;
    u32 reg;
    OSContext exceptContext;

    token = GX_GET_PE_REG(7);
    if (lbl_806EF780) {
        fn_80433814(&exceptContext);
        fn_8043364C(&exceptContext);
        lbl_806EF780(token);
        fn_80433814(&exceptContext);
        fn_8043364C(context);
    }
    reg = GX_GET_PE_REG(5);
    SET_REG_FIELD(0, reg, 1, 2, 1);
    GX_SET_PE_REG(5, reg);
}

/* GXSetDrawDoneCallback */
GXDrawDoneCallback fn_8042C6F8(GXDrawDoneCallback cb) {
    GXDrawDoneCallback old;
    BOOL enabled;

    old = lbl_806EF784;
    enabled = OSDisableInterrupts();
    lbl_806EF784 = cb;
    OSRestoreInterrupts(enabled);
    return old;
}

/* GXFinishInterruptHandler */
void fn_8042C73C(__OSInterrupt interrupt, OSContext* context) {
    u32 reg;
    OSContext exceptContext;

    reg = GX_GET_PE_REG(5);
    SET_REG_FIELD(0, reg, 1, 3, 1);
    GX_SET_PE_REG(5, reg);
    lbl_806EF788 = 1;
    if (lbl_806EF784) {
        fn_80433814(&exceptContext);
        fn_8043364C(&exceptContext);
        lbl_806EF784();
        fn_80433814(&exceptContext);
        fn_8043364C(context);
    }
    fn_804383B8(&lbl_806EF78C);
}

void __GXPEInit(void) {
    u32 reg;

    __OSSetInterruptHandler(18, fn_8042C670);
    __OSSetInterruptHandler(19, fn_8042C73C);
    fn_80437434(&lbl_806EF78C);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);
    reg = GX_GET_PE_REG(5);
    SET_REG_FIELD(0, reg, 1, 2, 1);
    SET_REG_FIELD(0, reg, 1, 3, 1);
    SET_REG_FIELD(0, reg, 1, 0, 1);
    SET_REG_FIELD(0, reg, 1, 1, 1);
    GX_SET_PE_REG(5, reg);
}
