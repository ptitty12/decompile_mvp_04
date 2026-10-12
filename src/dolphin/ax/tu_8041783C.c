/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8041783C-0x8041A5A4 (code-only unit: AXAlloc.c, AXAux.c, AXCL.c, AXOut.c, AXProf.c, AXSPB.c and
 * AXVPB.c in link order; 58 functions).
 * Every data object is extern by its lbl_ name.
 * Reference: Nintendo Dolphin SDK 2004 AX library as published in doldecomp/dolsdk2004 (structure and field names);
 * callees that symbols.txt still names fn_<addr> are declared here under that name with the SDK name in a comment.
 */
#include <dolphin.h>
#include <dolphin/ax.h>
#include <dolphin/ai.h>
#include <dolphin/dsp.h>

#include "__ax.h"

/* __AXStackHead and __AXStackTail are adjacent statics of AXAlloc.c (lbl_806C38C0 = lbl_806C3840 + 0x80); the
 * pop/push helpers are addressed off the head base, so they spell the tail as head[AX_PRIORITY_STACKS + i] */
extern AXVPB* lbl_806C3840[AX_PRIORITY_STACKS];
extern AXVPB* lbl_806C38C0[AX_PRIORITY_STACKS];
#define STACK_TAIL(i) lbl_806C3840[AX_PRIORITY_STACKS + (i)]
extern AXVPB* lbl_806EF528;                     /* __AXCallbackStack */

extern void fn_80419F38(AXVPB* p); /* __AXSetPBDefault */

/* __AXGetStackHead */
AXVPB* fn_8041783C(u32 priority)
{
    return lbl_806C3840[priority];
}

static void fn_80417A30(AXVPB* p);
static AXVPB* fn_80417A60(void);
static void fn_80417A7C(AXVPB* p);

/* __AXServiceCallbackStack */
void fn_80417854(void)
{
    AXVPB* p;

    p = fn_80417A60();
    while (p != NULL) {
        if (p->priority != 0) {
            if (p->callback != NULL) {
                p->callback(p);
            }
            fn_80417A7C(p);
            fn_80417A30(p);
        }
        p = fn_80417A60();
    }
}

/* __AXInitVoiceStacks */
void fn_804178C8(void)
{
    u32 i;

    lbl_806EF528 = NULL;
    for (i = 0; i < AX_PRIORITY_STACKS; i++) {
        lbl_806C38C0[i] = NULL;
        lbl_806C3840[i] = NULL;
    }
}

/* __AXAllocInit */
void fn_8041797C(void)
{
    u32 i;

    lbl_806EF528 = NULL;
    for (i = 0; i < AX_PRIORITY_STACKS; i++) {
        lbl_806C38C0[i] = NULL;
        lbl_806C3840[i] = NULL;
    }
}

/* __AXPushFreeStack */
static void fn_80417A30(AXVPB* p)
{
    p->next = lbl_806C3840[0];
    lbl_806C3840[0] = p;
    p->priority = 0;
}

/* __AXPushCallbackStack */
void fn_80417A50(AXVPB* p)
{
    p->next1 = lbl_806EF528;
    lbl_806EF528 = p;
}

/* __AXPopCallbackStack */
static AXVPB* fn_80417A60(void)
{
    AXVPB* p;

    p = lbl_806EF528;
    if (p != NULL) {
        lbl_806EF528 = p->next1;
    }
    return p;
}

/* __AXRemoveFromStack */
static void fn_80417A7C(AXVPB* p)
{
    u32 i;
    AXVPB** head;
    AXVPB** tail;

    i = p->priority;
    head = &lbl_806C3840[i];
    tail = &lbl_806C38C0[i];
    if (*head == *tail) {
        *tail = NULL;
        *head = NULL;
    } else if (p == *head) {
        *head = p->next;
        ((AXVPB*)*head)->prev = NULL;
    } else if (p == *tail) {
        *tail = p->prev;
        ((AXVPB*)*tail)->next = NULL;
    } else {
        AXVPB* prev = p->prev;
        AXVPB* next = p->next;
        prev->next = next;
        next->prev = prev;
    }
}

/* AXFreeVoice */
void fn_80417B10(AXVPB* p)
{
    BOOL old;

    old = OSDisableInterrupts();
    fn_80417A7C(p);
    if (p->pb.state == 1) {
        p->depop = 1;
    }
    fn_80419F38(p);
    fn_80417A30(p);
    OSRestoreInterrupts(old);
}

/* __AXPopFreeStack */
static AXVPB* __AXPopFreeStack(void)
{
    AXVPB* p;

    p = lbl_806C3840[0];
    if (lbl_806C3840[0] != NULL) {
        lbl_806C3840[0] = lbl_806C3840[0]->next;
    }
    return p;
}

/* __AXPopStackFromBottom */
static AXVPB* __AXPopStackFromBottom(u32 priority)
{
    AXVPB* p;

    if (lbl_806C3840[priority] == NULL) {
        return NULL;
    }
    if (lbl_806C3840[priority] == STACK_TAIL(priority)) {
        STACK_TAIL(priority) = NULL;
        p = lbl_806C3840[priority];
        lbl_806C3840[priority] = NULL;
        return p;
    }
    if (STACK_TAIL(priority) == NULL) {
        return NULL;
    }
    p = STACK_TAIL(priority);
    STACK_TAIL(priority) = p->prev;
    ((AXVPB*)STACK_TAIL(priority))->next = NULL;
    return p;
}

/* __AXPushStackHead */
static void __AXPushStackHead(AXVPB* p, u32 priority)
{
    p->next = lbl_806C3840[priority];
    p->prev = NULL;
    if (p->next != NULL) {
        lbl_806C3840[priority]->prev = p;
        lbl_806C3840[priority] = p;
    } else {
        STACK_TAIL(priority) = p;
        lbl_806C3840[priority] = p;
    }
}

/* AXAcquireVoice
 * near-miss: 96 vs 93 instructions; retail keeps the head and tail walk pointers as two separate loop induction
 * pointers, ours folds the tail into a displacement off one. */
AXVPB* fn_80417B90(u32 priority, void (*callback)(void*), u32 userContext)
{
    BOOL old;
    AXVPB* p;
    u32 i;

    old = OSDisableInterrupts();
    p = __AXPopFreeStack();
    if (p == NULL) {
        for (i = 1; i < priority; i++) {
            p = __AXPopStackFromBottom(i);
            if (p != NULL) {
                if (p->pb.state == 1) {
                    p->depop = 1;
                }
                if (p->callback != NULL) {
                    p->callback(p);
                }
                break;
            }
        }
    }
    if (p != NULL) {
        __AXPushStackHead(p, priority);
        p->priority = priority;
        p->callback = callback;
        p->userContext = userContext;
        fn_80419F38(p);
    }
    OSRestoreInterrupts(old);
    return p;
}

/* AXAux.c: AuxA and AuxB buffers (3 frames of 3 x 160 samples each) */
extern u32 lbl_806C3940[3][480];
extern u32 lbl_806C4FC0[3][480];
extern void (*lbl_806EF530)(void*, void*); /* __AXCallbackAuxA */
extern void (*lbl_806EF534)(void*, void*); /* __AXCallbackAuxB */
extern void* lbl_806EF538;                 /* __AXContextAuxA */
extern void* lbl_806EF53C;                 /* __AXContextAuxB */
extern u32* lbl_806EF540;
extern u32* lbl_806EF544;
extern u32* lbl_806EF548;
extern u32* lbl_806EF54C;
extern u32 lbl_806EF550;
extern u32 lbl_806EF554;
extern u32 lbl_806EF558;
extern u32 lbl_806EF55C;
extern u32 lbl_806EF560;
extern u32 lbl_806EF578; /* __AXOutputBufferMode? (AX step mode) */

extern void fn_80432FA8(void* addr, u32 nBytes); /* DCInvalidateRange */
extern void fn_80433034(void* addr, u32 nBytes); /* DCFlushRangeNoSync / DCStoreRangeNoSync */

/* __AXAuxInit */
void fn_80417D04(void)
{
    int i;
    u32* a;
    u32* b;

    lbl_806EF530 = NULL;
    lbl_806EF534 = NULL;
    lbl_806EF538 = NULL;
    lbl_806EF53C = NULL;
    lbl_806EF550 = 0;
    lbl_806EF554 = 1;
    lbl_806EF558 = 0;
    lbl_806EF55C = 1;
    lbl_806EF560 = 2;
    a = (u32*)lbl_806C3940;
    b = (u32*)lbl_806C4FC0;
    for (i = 0; i < 480; i++) {
        *a++ = 0;
        *b++ = 0;
    }
}

/* __AXAuxQuit */
void fn_80417DE8(void)
{
    lbl_806EF530 = NULL;
    lbl_806EF534 = NULL;
}

void fn_80417DF8(u32* p)
{
    if (lbl_806EF530 != NULL) {
        *p = (u32)lbl_806C3940[lbl_806EF550];
    } else {
        *p = 0;
    }
}

void fn_80417E2C(u32* p)
{
    *p = (u32)((u8*)lbl_806C4FC0[lbl_806EF550] + 0x500);
}

void fn_80417E4C(u32* p)
{
    *p = (u32)lbl_806C3940[lbl_806EF554];
}

void fn_80417E68(u32* p)
{
    *p = (u32)((u8*)lbl_806C3940[lbl_806EF554] + 0x280);
}

void fn_80417E88(u32* p)
{
    *p = (u32)((u8*)lbl_806C3940[lbl_806EF554] + 0x500);
}

void fn_80417EA8(u32* p)
{
    *p = (u32)((u8*)lbl_806C4FC0[lbl_806EF554] + 0x500);
}

void fn_80417EC8(u32* p)
{
    if (lbl_806EF534 != NULL) {
        *p = (u32)lbl_806C4FC0[lbl_806EF550];
    } else {
        *p = 0;
    }
}

void fn_80417EFC(u32* p)
{
    *p = (u32)lbl_806C4FC0[lbl_806EF554];
}

void fn_80417F18(u32* p)
{
    *p = (u32)lbl_806C4FC0[lbl_806EF558];
}

void fn_80417F34(u32* p)
{
    *p = (u32)lbl_806C4FC0[lbl_806EF55C];
}

/* AuxA and AuxB buffers back to back, as one object */
struct AxAuxBufs {
    u32 a[3][3][160];
    u32 b[3][3][160];
};

/* __AXProcessAux
 * near-miss: same length; retail forms the AuxB base as (AuxA + idx*0x780) + 0x1680 in a register and takes +0x280/+0x500
 * from that, ours folds the constants into the offsets. */
void fn_80417F50(void)
{
    AX_AUX_DATA_DPL2 auxDataDpl2;
    AX_AUX_DATA auxDataA;
    AX_AUX_DATA auxDataB;
    struct AxAuxBufs* bufs = (struct AxAuxBufs*)lbl_806C3940;

    lbl_806EF540 = bufs->a[lbl_806EF550][0];
    lbl_806EF544 = bufs->a[lbl_806EF554][0];
    lbl_806EF548 = bufs->b[lbl_806EF550][0];
    lbl_806EF54C = bufs->b[lbl_806EF554][0];

    if (lbl_806EF530 != NULL) {
        if (lbl_806EF578 == 2) {
            auxDataDpl2.l = (s32*)bufs->a[lbl_806EF560][0];
            auxDataDpl2.r = (s32*)bufs->a[lbl_806EF560][1];
            auxDataDpl2.ls = (s32*)bufs->a[lbl_806EF560][2];
            auxDataDpl2.rs = (s32*)bufs->b[lbl_806EF560][-1 + 3];
            fn_80432FA8(auxDataDpl2.l, 0x780);
            fn_80432FA8(auxDataDpl2.rs, 0x280);
            lbl_806EF530(&auxDataDpl2, lbl_806EF538);
            fn_80433034(auxDataDpl2.l, 0x780);
            fn_80433034(auxDataDpl2.rs, 0x280);
        } else {
            auxDataA.l = (s32*)bufs->a[lbl_806EF560][0];
            auxDataA.r = (s32*)bufs->a[lbl_806EF560][1];
            auxDataA.s = (s32*)bufs->a[lbl_806EF560][2];
            fn_80432FA8(auxDataA.l, 0x780);
            lbl_806EF530(&auxDataA, lbl_806EF538);
            fn_80433034(auxDataA.l, 0x780);
        }
    }

    if (lbl_806EF534 != NULL && lbl_806EF578 != 2) {
        auxDataB.l = (s32*)bufs->b[lbl_806EF560][0];
        auxDataB.r = (s32*)bufs->b[lbl_806EF560][1];
        auxDataB.s = (s32*)bufs->b[lbl_806EF560][2];
        fn_80432FA8(auxDataB.l, 0x780);
        lbl_806EF534(&auxDataB, lbl_806EF53C);
        fn_80433034(auxDataB.l, 0x780);
    }

    lbl_806EF550++;
    lbl_806EF554++;
    lbl_806EF560++;
    lbl_806EF558++;
    lbl_806EF55C++;
    lbl_806EF550 %= 3;
    lbl_806EF554 %= 3;
    lbl_806EF558 &= 1;
    lbl_806EF55C &= 1;
    lbl_806EF560 %= 3;
}

/* AXRegisterAuxACallback */
void fn_8041818C(void (*callback)(void*, void*), void* context)
{
    lbl_806EF530 = callback;
    lbl_806EF538 = context;
}

/* AXCL.c, AXOut.c: command list state */
extern u32 lbl_806EF570; /* __AXClCycles */
extern s32 lbl_806EF568;
extern u16* lbl_806EF56C;
extern u16 lbl_806C6640[2][0x180];
extern u32 lbl_806EF574;

/* __AXGetCommandListCycles */
u32 fn_80418198(void)
{
    return lbl_806EF570;
}

/* __AXGetCommandListAddress */
u32 fn_804181A0(void)
{
    u32 ret;

    ret = (u32)lbl_806C6640[lbl_806EF568];
    lbl_806EF568++;
    lbl_806EF568 &= 1;
    lbl_806EF56C = lbl_806C6640[lbl_806EF568];
    return ret;
}

/* __AXClInit */
void fn_8041888C(void)
{
    lbl_806EF578 = 0;
    lbl_806EF568 = 0;
    lbl_806EF56C = lbl_806C6640[0];
    lbl_806EF574 = 1;
}

/* __AXClQuit */
void fn_804188B0(void)
{
}

/* AXSetMode */
void fn_804188B4(u32 mode)
{
    if (lbl_806EF578 != mode) {
        lbl_806EF578 = mode;
    }
}

void fn_804188C8(u32 v)
{
    lbl_806EF574 = v;
}

/* AXOut.c */
struct AxOutBss {
    u32 outBuffer[3][160];   /* __AXOutBuffer */
    u32 sBuffer[160];        /* __AXOutSBuffer */
    u8 stack[0x4000];        /* DSP slave stack and padding */
    DSPTaskInfo task;        /* __AXDspSlave task */
    AXPROFILE profile;       /* __AXLocalProfile */
};
extern struct AxOutBss lbl_806C6C40;
extern DSPTaskInfo lbl_806CB640;
extern u32 lbl_806EF580; /* __AXOutFrame */
extern u32 lbl_806EF584; /* __AXAiDmaFrame? */
extern u32 lbl_806EF588; /* __AXDspState */
extern volatile OSTime lbl_806EF590; /* __AXDspTime */
extern void (*lbl_806EF598)(void); /* __AXUserFrameCallback */
extern s32 lbl_806EF59C;
extern s32 lbl_806EF5A0;
extern u32 lbl_806EF5A4;
extern OSThreadQueue lbl_806EF5A8;
extern u32 lbl_806EF5B0; /* __AXOutputBufferMode */
extern u16 lbl_80631560[]; /* axDspSlave */
extern u16 lbl_806EF168;   /* axDspSlaveLength */

extern OSTime fn_80438628(void);               /* OSGetTime */
extern void fn_80437434(OSThreadQueue* queue); /* OSInitThreadQueue */
extern void fn_804382CC(OSThreadQueue* queue); /* OSSleepThread */
extern void fn_804383B8(OSThreadQueue* queue); /* OSWakeupThread */
extern void fn_80432FD4(void* addr, u32 nBytes); /* DCFlushRange */
extern void fn_80419CB4(u32 lessDspCycles);    /* __AXSyncPBs */
extern void fn_804190A4(void);
extern u32 fn_80419560(void);                  /* __AXGetNumVoices */
extern AXPROFILE* fn_8041A55C(void);           /* __AXGetCurrentProfile */
extern void fn_804181DC(void* sbuffer, void* buffer); /* __AXNextFrame */
extern void fn_80418A88(void);
extern void fn_80418BD4(void);

/* __AXOutNewFrame
 * not matched in this merged unit: retail calls the AXAlloc/AXCL functions out of line (separate translation units), ours
 * inlines them (154 vs 110 instructions). Matches once AXAlloc.c / AXAux.c / AXCL.c / AXOut.c are split. */
void fn_804188D0(u32 lessDspCycles)
{
    u32 cl;
    AXPROFILE* profile;

    lbl_806C6C40.profile.axFrameStart = fn_80438628();
    fn_80419CB4(lessDspCycles);
    fn_804190A4();
    cl = fn_804181A0();
    DSPSendMailToDSP(0xBABE0180);
    while (DSPCheckMailToDSP() != 0)
        ;
    DSPSendMailToDSP(cl);
    while (DSPCheckMailToDSP() != 0)
        ;
    fn_80417854();
    lbl_806C6C40.profile.auxProcessingStart = fn_80438628();
    fn_80417F50();
    lbl_806C6C40.profile.auxProcessingEnd = fn_80438628();
    lbl_806C6C40.profile.userCallbackStart = fn_80438628();
    if (lbl_806EF598 != NULL) {
        lbl_806EF598();
    }
    lbl_806C6C40.profile.userCallbackEnd = fn_80438628();
    fn_804181DC(lbl_806C6C40.sBuffer, lbl_806C6C40.outBuffer[lbl_806EF580]);
    lbl_806EF580++;
    if (lbl_806EF5B0 == 1) {
        lbl_806EF580 %= 3;
    } else {
        lbl_806EF580 &= 1;
        AIInitDMA((u32)lbl_806C6C40.outBuffer[lbl_806EF580], 0x280);
    }
    lbl_806C6C40.profile.axFrameEnd = fn_80438628();
    lbl_806C6C40.profile.axNumVoices = fn_80419560();
    profile = fn_8041A55C();
    if (profile != NULL) {
        *profile = lbl_806C6C40.profile;
    }
}

/* __AXOutAiCallback */
void fn_80418A88(void)
{
    if (lbl_806EF588 == 0) {
        lbl_806EF590 = fn_80438628();
    }
    if (lbl_806EF588 == 1) {
        lbl_806EF588 = 0;
        fn_804188D0(0);
    } else {
        lbl_806EF588 = 2;
        DSPAssertTask(&lbl_806CB640);
    }
    if (lbl_806EF5B0 == 1) {
        AIInitDMA((u32)lbl_806C6C40.outBuffer[lbl_806EF584], 0x280);
        lbl_806EF584++;
        lbl_806EF584 %= 3;
    }
}

/* DSP task init callback */
void fn_80418B44(void)
{
    lbl_806EF59C = 1;
}

/* DSP task resume callback */
void fn_80418B50(void)
{
    if (lbl_806EF588 == 2) {
        lbl_806EF588 = 0;
        fn_804188D0((u32)(fn_80438628() - lbl_806EF590) >> 2);
        return;
    }
    lbl_806EF588 = 1;
}

/* DSP task done callback */
void fn_80418BA8(void)
{
    lbl_806EF5A0 = 1;
    fn_804383B8(&lbl_806EF5A8);
}

/* __AXOutInitDSP */
void fn_80418BD4(void)
{
    struct AxOutBss* o = &lbl_806C6C40;

    o->task.iram_mmem_addr = lbl_80631560;
    o->task.iram_length = lbl_806EF168;
    o->task.iram_addr = 0;
    o->task.dram_mmem_addr = (u16*)o->stack;
    o->task.dram_length = 0x2000;
    o->task.dram_addr = 0;
    o->task.dsp_init_vector = 0x10;
    o->task.dsp_resume_vector = 0x30;
    o->task.init_cb = (DSPCallback)fn_80418B44;
    o->task.res_cb = (DSPCallback)fn_80418B50;
    o->task.done_cb = (DSPCallback)fn_80418BA8;
    o->task.req_cb = NULL;
    o->task.priority = 0;
    lbl_806EF59C = 0;
    lbl_806EF5A0 = 0;
    fn_80437434(&lbl_806EF5A8);
    if (DSPCheckInit() == 0) {
        DSPInit();
    }
    DSPAddTask(&o->task);
    while (lbl_806EF59C == 0)
        ;
}

/* __AXOutInit
 * near-miss: retail unrolls both zeroing loops 80 words per iteration (ctr 6 and 2); the index and pointer spellings tried
 * give other unroll factors. */
void fn_80418CA0(u32 outputBufferMode)
{
    u32* p;
    int i;

    lbl_806EF580 = 0;
    lbl_806EF584 = 0;
    lbl_806EF5B0 = outputBufferMode;
    lbl_806EF5A4 = 0;
    p = (u32*)lbl_806C6C40.outBuffer;
    for (i = 0; i < 0x1E0; i++) {
        *p++ = 0;
    }
    fn_80432FD4(lbl_806C6C40.outBuffer, 0x780);
    p = lbl_806C6C40.sBuffer;
    for (i = 0; i < 0xA0; i++) {
        *p++ = 0;
    }
    fn_80432FD4(lbl_806C6C40.sBuffer, 0x280);
    fn_80418BD4();
    AIRegisterDMACallback((AIDCallback)fn_80418A88);
    if (lbl_806EF5B0 == 1) {
        fn_804181DC(lbl_806C6C40.sBuffer, lbl_806C6C40.outBuffer[2]);
    } else {
        fn_804181DC(lbl_806C6C40.sBuffer, lbl_806C6C40.outBuffer[1]);
    }
    lbl_806EF588 = 1;
    lbl_806EF598 = NULL;
    if (lbl_806EF5B0 == 1) {
        AIInitDMA((u32)lbl_806C6C40.outBuffer[lbl_806EF584], 0x280);
        lbl_806EF584++;
        lbl_806EF584 &= 1;
    } else {
        AIInitDMA((u32)lbl_806C6C40.outBuffer[lbl_806EF580], 0x280);
    }
    AIStartDMA();
}

/* __AXOutQuit */
void fn_80419040(void)
{
    BOOL old;

    old = OSDisableInterrupts();
    lbl_806EF598 = NULL;
    DSPCancelTask(&lbl_806CB640);
    fn_804382CC(&lbl_806EF5A8);
    AIStopDMA();
    OSRestoreInterrupts(old);
}
