/*
 * Dolphin SDK OS (OSMemory, OSMutex, OSReset, OSRtc, OSThread start; MWCC GC/1.2.5n),
 * .text 0x80435A10-0x80437444 (code-only unit; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * Original-code functions in this range are not reproduced: fn_80435AB8, fn_80435B38, fn_80435BB8,
 * fn_804360E4 (mftb), fn_80437254, fn_80437274 (references fn_80437254+0x1C).
 *
 * The "==== name ====" markers are the source-file boundaries (string pools are per file). The "flags:" tags give
 * the compiler flags a function needs; untagged functions match with the configured flags.
 * Not matched yet: LockSram/LockSramEx and the functions that inline them, UnlockSram, __OSInitSram
 * (the original keeps the static SramControl base in a callee-saved register, which an extern cannot reproduce),
 * fn_80436530 (OSGetResetButtonState) and fn_804372DC (__OSThreadInit) were not attempted.
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/hw_regs.h>
#include <dolphin/tail10.h>


extern void fn_80435BB8(u32 addr);                     /* RealMode (original code) */
extern void fn_80435AB8(void);                         /* Config24MB (original code) */
extern void fn_80435B38(void);                         /* Config48MB (original code) */
extern void fn_8043402C(u8 exception, OSContext* context, u32 dsisr, u32 dar);
extern u32 fn_80435350(u32 global);
extern OSResetFunctionInfo lbl_80637128;
extern void* lbl_806DF090[17];                         /* __OSErrorTable */

/* ==== OSMemory ==== */

BOOL fn_80435A10(BOOL final);
void fn_80435A4C(s16 interrupt, OSContext* context);
void fn_80435BD0(void);

/* OnReset (OSMemory) */
BOOL fn_80435A10(BOOL final)
{
    if (final) {
        __MEMRegs[8] = 0xFF;
        fn_80435350(OS_INTERRUPTMASK_MEM_RESET);
    }
    return TRUE;
}

/* MEMIntrruptHandler */
void fn_80435A4C(s16 interrupt, OSContext* context)
{
    u32 addr;
    u32 cause;

    cause = __MEMRegs[0x0F];
    addr = (((u32)__MEMRegs[0x12] & 0x3FF) << 16) | __MEMRegs[0x11];
    __MEMRegs[0x10] = 0;

    if (lbl_806DF090[15]) {
        ((OSErrorHandler)lbl_806DF090[15])(15, context, cause, addr);
    } else {
        fn_8043402C(15, context, cause, addr);
    }
}

/* flags: matches only with -opt nopeephole */
/* __OSInitMemoryProtection */
void fn_80435BD0(void)
{
    u32 padding[12];
    u32 simulatedSize;
    BOOL enabled;

    simulatedSize = *(u32*)0x800000F0;
    enabled = OSDisableInterrupts();
    __MEMRegs[0x10] = 0;
    __MEMRegs[8] = 0xFF;
    fn_80435350(OS_INTERRUPTMASK_MEM_RESET);
    __OSSetInterruptHandler(0, (void*)fn_80435A4C);
    __OSSetInterruptHandler(1, (void*)fn_80435A4C);
    __OSSetInterruptHandler(2, (void*)fn_80435A4C);
    __OSSetInterruptHandler(3, (void*)fn_80435A4C);
    __OSSetInterruptHandler(4, (void*)fn_80435A4C);
    OSRegisterResetFunction(&lbl_80637128);

    if (*(u32*)0x800000F0 < *(u32*)0x80000028 && *(u32*)0x800000F0 == 0x01800000) {
        fn_80432FA8((void*)0x81800000, 0x01800000);
        __MEMRegs[0x14] = 2;
    }
    if (simulatedSize <= 0x01800000) {
        fn_80435BB8((u32)fn_80435AB8);
    } else if (simulatedSize <= 0x03000000) {
        fn_80435BB8((u32)fn_80435B38);
    }
    __OSUnmaskInterrupts(OS_INTERRUPTMASK_MEM_ADDRESS);
    OSRestoreInterrupts(enabled);
}

/* ==== OSMutex ==== */

extern OSThread* fn_80437444(void);        /* OSGetCurrentThread */
extern void fn_80437768(OSThread* thread, s32 priority);   /* __OSPromoteThread */
extern void fn_804382CC(OSThreadQueue* queue);             /* OSSleepThread */
extern void fn_804383B8(OSThreadQueue* queue);             /* OSWakeupThread */
extern s32 fn_8043756C(OSThread* thread);                  /* __OSGetEffectivePriority */
extern void fn_80437434(OSThreadQueue* queue);             /* OSInitThreadQueue */

void fn_80435CE8(OSMutex* mutex);
void fn_80435D20(OSMutex* mutex);
void fn_80435DFC(OSMutex* mutex);
void fn_80435EC4(OSThread* thread);

/* OSInitMutex */
void fn_80435CE8(OSMutex* mutex)
{
    fn_80437434(&mutex->queue);
    mutex->thread = NULL;
    mutex->count = 0;
}

/* OSLockMutex */
void fn_80435D20(OSMutex* mutex)
{
    BOOL enabled = OSDisableInterrupts();
    OSThread* currentThread = fn_80437444();
    OSThread* ownerThread;

    while (TRUE) {
        ownerThread = mutex->thread;
        if (ownerThread == 0) {
            mutex->thread = currentThread;
            mutex->count++;
            {
                OSMutex* tail = currentThread->queueMutex.tail;

                if (tail == NULL) {
                    currentThread->queueMutex.head = mutex;
                } else {
                    tail->link.next = mutex;
                }
                mutex->link.prev = tail;
                mutex->link.next = NULL;
                currentThread->queueMutex.tail = mutex;
            }
            break;
        } else if (ownerThread == currentThread) {
            mutex->count++;
            break;
        } else {
            currentThread->mutex = mutex;
            fn_80437768(mutex->thread, currentThread->priority);
            fn_804382CC(&mutex->queue);
            currentThread->mutex = NULL;
        }
    }
    OSRestoreInterrupts(enabled);
}

/* OSUnlockMutex */
void fn_80435DFC(OSMutex* mutex)
{
    BOOL enabled = OSDisableInterrupts();
    OSThread* currentThread = fn_80437444();

    if (mutex->thread == currentThread && --mutex->count == 0) {
        OSMutex* next = mutex->link.next;
        OSMutex* prev = mutex->link.prev;

        if (next == NULL) {
            currentThread->queueMutex.tail = prev;
        } else {
            next->link.prev = prev;
        }
        if (prev == NULL) {
            currentThread->queueMutex.head = next;
        } else {
            prev->link.next = next;
        }
        mutex->thread = NULL;
        if (currentThread->priority < currentThread->base) {
            currentThread->priority = fn_8043756C(currentThread);
        }
        fn_804383B8(&mutex->queue);
    }
    OSRestoreInterrupts(enabled);
}

/* __OSUnlockAllMutex */
void fn_80435EC4(OSThread* thread)
{
    OSMutex* mutex;

    while (thread->queueMutex.head) {
        OSMutex* next;

        mutex = thread->queueMutex.head;
        next = mutex->link.next;
        if (next == NULL) {
            thread->queueMutex.tail = NULL;
        } else {
            next->link.prev = NULL;
        }
        thread->queueMutex.head = next;
        mutex->count = 0;
        mutex->thread = NULL;
        fn_804383B8(&mutex->queue);
    }
}

/* ==== OSReset ==== */

extern OSResetFunctionQueue ResetFunctionQueue_806EF830;
extern u32 lbl_806EF838;                               /* bootDol / restart parameter */
extern OSSram* fn_80436A9C(void);                      /* __OSLockSram */
extern void fn_804360E4(u32 code);                     /* Reset (original code) */
extern BOOL fn_80436E90(BOOL commit);                  /* __OSUnlockSram */
extern BOOL fn_80436ED8(void);                         /* __OSSyncSram */
extern void fn_80432EBC(void);                         /* __OSStopAudioSystem */
extern void fn_804330E4(void);                         /* LCDisable */
extern void fn_804330C0(void);                         /* ICFlashInvalidate */
extern BOOL __PADDisableRecalibration(BOOL disable);
extern void fn_80437D18(OSThread* thread);             /* OSCancelThread */
extern void fn_80435F34(u32 resetCode, u32 bootDol);   /* __OSReboot */

void OSRegisterResetFunction(OSResetFunctionInfo* func);
BOOL fn_8043603C(BOOL final);
void fn_80436154(void);
void fn_804361BC(u32 resetCode);
void fn_80436204(int reset, u32 resetCode, BOOL forceMenu);
u32 fn_80436404(void);

/* OSRegisterResetFunction */
void OSRegisterResetFunction(OSResetFunctionInfo* func)
{
    OSResetFunctionInfo* tmp;
    OSResetFunctionInfo* iter;

    for (iter = ResetFunctionQueue_806EF830.head; iter && iter->priority <= func->priority; iter = iter->next)
        ;
    if (iter == NULL) {
        tmp = ResetFunctionQueue_806EF830.tail;
        if (tmp == NULL) {
            ResetFunctionQueue_806EF830.head = func;
        } else {
            tmp->next = func;
        }
        func->prev = tmp;
        func->next = NULL;
        ResetFunctionQueue_806EF830.tail = func;
        return;
    }
    func->next = iter;
    tmp = iter->prev;
    iter->prev = func;
    func->prev = tmp;
    if (tmp == NULL) {
        ResetFunctionQueue_806EF830.head = func;
        return;
    }
    tmp->next = func;
}

/* __OSCallResetFunctions */
BOOL fn_8043603C(BOOL final)
{
    OSResetFunctionInfo* info;
    s32 err = 0;
    u32 priority = 0;

    for (info = ResetFunctionQueue_806EF830.head; info; info = info->next) {
        if (err != 0 && priority != info->priority) {
            break;
        }
        err |= !info->func(final);
        priority = info->priority;
    }
    err |= !fn_80436ED8();

    if (err) {
        return FALSE;
    }
    return TRUE;
}

/* flags: matches only with -opt nopeephole */
/* KillThreads */
void fn_80436154(void)
{
    OSThread* thread;
    OSThread* next;

    for (thread = __OSActiveThreadQueue.head; thread; thread = next) {
        next = thread->linkActive.next;
        switch (thread->state) {
        case 1:
        case 4:
            fn_80437D18(thread);
            break;
        }
    }
}

/* flags: matches only with -opt nopeephole */
/* __OSDoHotReset */
void fn_804361BC(u32 resetCode)
{
    OSDisableInterrupts();
    __VIRegs[1] = 0;
    fn_804330C0();
    fn_804360E4(resetCode << 3);
}

/* flags: matches only with -opt nopeephole -inline noauto */
/* OSResetSystem */
void fn_80436204(int reset, u32 resetCode, BOOL forceMenu)
{
    BOOL rc;
    BOOL disableRecalibration;
    u32 unk[2];

    fn_80437484();
    if (reset == 1 && forceMenu) {
        OSSram* sram = fn_80436A9C();

        sram->flags |= 0x40;
        fn_80436E90(TRUE);
        resetCode = 0;
    }
    if (reset == 2 || (reset == 0 && (lbl_806EF838 != 0 || resetCode == 0xC0010000))) {
        fn_80432EBC();
        disableRecalibration = __PADDisableRecalibration(TRUE);
        while (!fn_8043603C(FALSE)) {
        }
        while (!fn_80436ED8()) {
        }
        OSDisableInterrupts();
        fn_8043603C(TRUE);
        fn_804330E4();
        __PADDisableRecalibration(disableRecalibration);
        fn_80436154();
    } else {
        fn_80432EBC();
        while (!fn_8043603C(FALSE)) {
        }
        while (!fn_80436ED8()) {
        }
        OSDisableInterrupts();
        fn_8043603C(TRUE);
        fn_804330E4();
        fn_80436154();
    }

    if (reset == 1) {
        OSDisableInterrupts();
        __VIRegs[1] = 0;
        fn_804330C0();
        fn_804360E4(resetCode << 3);
    } else if (reset == 0) {
        if (forceMenu == 1) {
            OSReport("OSResetSystem(): You can't specify TRUE to forceMenu if you restart. Ignored\n");
        }
        fn_804374C4();
        fn_80435F34(resetCode, lbl_806EF838);
    }
    memset((void*)0x80000040, 0, 0x8C);
    memset((void*)0x800000D4, 0, 0x14);
    memset((void*)0x800000F4, 0, 4);
    memset((void*)0x80003000, 0, 0xC0);
    memset((void*)0x800030C8, 0, 0xC);
    memset((void*)0x800030E2, 0, 1);
}

/* flags: matches only with -opt nopeephole */
/* OSGetResetCode */
u32 fn_80436404(void)
{
    extern OSExecParams lbl_806DF070;

    if (lbl_806DF070.valid != 0) {
        return lbl_806DF070.restartCode | 0x80000000;
    }
    return (__PIRegs[9] & ~7) >> 3;
}

extern OSTime lbl_806EF858;           /* HoldUp-time */
extern s32 lbl_806EF844;              /* Down */
extern s32 lbl_806EF848;              /* LastState */
extern void (*lbl_806EF840)(void);    /* ResetCallback */
extern BOOL fn_80436530(void);

void fn_8043643C(s16 interrupt, OSContext* context);
BOOL fn_804367C8(void);

/* __OSResetSWInterruptHandler */
void fn_8043643C(s16 interrupt, OSContext* context)
{
    void (*callback)(void);

    lbl_806EF858 = __OSGetSystemTime();
    while (__OSGetSystemTime() - lbl_806EF858 < OSMicrosecondsToTicks(100) && !(__PIRegs[0] & 0x00010000))
        ;
    if (!(__PIRegs[0] & 0x00010000)) {
        lbl_806EF848 = lbl_806EF844 = TRUE;
        fn_80435350(OS_INTERRUPTMASK_PI_RSW);
        if (lbl_806EF840) {
            callback = lbl_806EF840;
            lbl_806EF840 = NULL;
            callback();
        }
    }
    __PIRegs[0] = 2;
}

/* OSGetResetSwitchState */
BOOL fn_804367C8(void)
{
    return fn_80436530();
}

/* ==== OSRtc ==== */

typedef void (*RtcExiCallback)(s32 chan, OSContext* context);

extern SramControl lbl_806DF3C0;                                            /* Scb */
extern int fn_804280EC(s32 chan, u32 dev, RtcExiCallback cb);               /* EXILock */
extern int fn_8042792C(s32 chan, u32 dev, u32 freq);                        /* EXISelect */
extern int fn_804281E0(s32 chan);                                           /* EXIUnlock */
extern int fn_80426DC4(s32 chan, void* buf, s32 len, u32 type, void* cb);   /* EXIImm */
extern int fn_804271AC(s32 chan);                                           /* EXISync */
extern int fn_80427020(s32 chan, void* buf, s32 len, u32 type);             /* EXIImmEx */
extern int fn_804270C0(s32 chan, void* buf, s32 len, u32 type, void* cb);   /* EXIDma */
extern int fn_80427A58(s32 chan);                                           /* EXIDeselect */

BOOL fn_80436848(void* buffer, u32 offset, u32 size);
void fn_804367E8(s32 chan, OSContext* context);
void fn_80436960(void);
OSSram* fn_80436A9C(void);
OSSramEx* fn_80436AF8(void);
BOOL fn_80436B54(BOOL commit, u32 offset);
BOOL fn_80436E90(BOOL commit);
BOOL fn_80436EB4(BOOL commit);
BOOL fn_80436ED8(void);
u32 fn_80436EE8(void);
void fn_80436F58(u32 mode);
u16 fn_80436FFC(s32 chan);
void fn_80437080(s32 chan, u16 id);
u16 fn_8043712C(void);
void fn_8043719C(u16 gbs);

/* UnlockedHandler */
void fn_804367E8(s32 chan, OSContext* context)
{
    lbl_806DF3C0.sync = fn_80436848(lbl_806DF3C0.sram + lbl_806DF3C0.offset, lbl_806DF3C0.offset, 64 - lbl_806DF3C0.offset);
    if (lbl_806DF3C0.sync) {
        lbl_806DF3C0.offset = 64;
    }
}

/* WriteSram */
BOOL fn_80436848(void* buffer, u32 offset, u32 size)
{
    BOOL err;
    u32 cmd;

    if (!fn_804280EC(0, 1, fn_804367E8)) {
        return FALSE;
    }
    if (!fn_8042792C(0, 1, 3)) {
        fn_804281E0(0);
        return FALSE;
    }
    offset <<= 6;
    cmd = (offset + 0x100) | 0xA0000000;
    err = !fn_80426DC4(0, &cmd, 4, 1, 0);
    err |= !fn_804271AC(0);
    err |= !fn_80427020(0, buffer, size, 1);
    err |= !fn_80427A58(0);
    fn_804281E0(0);
    return !err;
}

/* flags: not matched (near-miss) */
/* __OSInitSram */
void fn_80436960(void)
{
    SramControl* scb = &lbl_806DF3C0;
    BOOL err;
    u32 cmd;
    BOOL ok;

    scb->enabled = scb->locked = FALSE;
    fn_80432FA8(&lbl_806DF3C0, 64);
    ok = FALSE;
    if (fn_804280EC(0, 1, 0)) {
        if (!fn_8042792C(0, 1, 3)) {
            fn_804281E0(0);
        } else {
            cmd = 0x20000100;
            err = !fn_80426DC4(0, &cmd, 4, 1, 0);
            err |= !fn_804271AC(0);
            err |= !fn_804270C0(0, &lbl_806DF3C0, 64, 0, 0);
            err |= !fn_804271AC(0);
            err |= !fn_80427A58(0);
            fn_804281E0(0);
            ok = !err;
        }
    }
    scb->sync = ok;
    scb->offset = 64;
    fn_8043719C(fn_8043712C());
}

/* flags: not matched (near-miss) */
/* __OSLockSram */
OSSram* fn_80436A9C(void)
{
    SramControl* scb = &lbl_806DF3C0;
    BOOL enabled = OSDisableInterrupts();

    if (scb->locked) {
        OSRestoreInterrupts(enabled);
        return NULL;
    }
    scb->enabled = enabled;
    scb->locked = TRUE;
    return (OSSram*)scb;
}

/* flags: not matched (near-miss) */
/* __OSLockSramEx */
OSSramEx* fn_80436AF8(void)
{
    SramControl* scb = &lbl_806DF3C0;
    BOOL enabled = OSDisableInterrupts();

    if (scb->locked) {
        OSRestoreInterrupts(enabled);
        return NULL;
    }
    scb->enabled = enabled;
    scb->locked = TRUE;
    return (OSSramEx*)(scb->sram + sizeof(OSSram));
}

/* flags: not matched (near-miss) */
/* UnlockSram */
BOOL fn_80436B54(BOOL commit, u32 offset)
{
    SramControl* scb = &lbl_806DF3C0;
    u16* p;

    if (commit) {
        if (offset == 0) {
            OSSram* sram = (OSSram*)scb->sram;

            if (2 < (sram->flags & 3)) {
                sram->flags &= ~3;
            }
            sram->checkSum = sram->checkSumInv = 0;
            for (p = (u16*)&sram->counterBias; p < (u16*)(scb->sram + sizeof(OSSram)); p++) {
                sram->checkSum += *p;
                sram->checkSumInv += ~*p;
            }
        }
        if (offset < scb->offset) {
            scb->offset = offset;
        }
        if (scb->offset <= 0x14) {
            OSSramEx* sramex = (OSSramEx*)(scb->sram + sizeof(OSSram));

            if ((sramex->gbs & 0x7C00) == 0x5000 || (sramex->gbs & 0xC0) == 0xC0) {
                sramex->gbs = 0;
            }
        }
        scb->sync = fn_80436848(scb->sram + scb->offset, scb->offset, 64 - scb->offset);
        if (scb->sync) {
            scb->offset = 64;
        }
    }
    scb->locked = FALSE;
    OSRestoreInterrupts(scb->enabled);
    return scb->sync;
}

/* __OSUnlockSram */
BOOL fn_80436E90(BOOL commit)
{
    return fn_80436B54(commit, 0);
}

/* __OSUnlockSramEx */
BOOL fn_80436EB4(BOOL commit)
{
    return fn_80436B54(commit, sizeof(OSSram));
}

/* __OSSyncSram */
BOOL fn_80436ED8(void)
{
    return lbl_806DF3C0.sync;
}

/* flags: not matched (near-miss) */
/* OSGetSoundMode */
u32 fn_80436EE8(void)
{
    OSSram* sram = fn_80436A9C();
    u32 mode = (sram->flags & 0x80) ? OS_SOUND_MODE_STEREO : OS_SOUND_MODE_MONO;

    fn_80436B54(FALSE, 0);
    return mode;
}

/* flags: not matched (near-miss) */
/* OSSetSoundMode */
void fn_80436F58(u32 mode)
{
    OSSram* sram;

    mode <<= 7;
    mode &= 0x80;
    sram = fn_80436A9C();
    if (mode == (sram->flags & 0x80)) {
        fn_80436B54(FALSE, 0);
        return;
    }
    sram->flags &= ~0x80;
    sram->flags |= mode;
    fn_80436B54(TRUE, 0);
}

/* flags: not matched (near-miss) */
/* OSGetWirelessID */
u16 fn_80436FFC(s32 chan)
{
    OSSramEx* sram = fn_80436AF8();
    u16 id = sram->wirelessPadID[chan];

    fn_80436B54(FALSE, sizeof(OSSram));
    return id;
}

/* flags: not matched (near-miss) */
/* OSSetWirelessID */
void fn_80437080(s32 chan, u16 id)
{
    OSSramEx* sram = fn_80436AF8();

    if (sram->wirelessPadID[chan] != id) {
        sram->wirelessPadID[chan] = id;
        fn_80436B54(TRUE, sizeof(OSSram));
    } else {
        fn_80436B54(FALSE, sizeof(OSSram));
    }
}

/* flags: not matched (near-miss) */
/* OSGetGbsMode */
u16 fn_8043712C(void)
{
    OSSramEx* sram = fn_80436AF8();
    u16 gbs = sram->gbs;

    fn_80436B54(FALSE, sizeof(OSSram));
    return gbs;
}

/* flags: not matched (near-miss) */
/* OSSetGbsMode */
void fn_8043719C(u16 gbs)
{
    OSSramEx* sram;

    if ((gbs & 0x7C00) == 0x5000 || (gbs & 0xC0) == 0xC0) {
        gbs = 0;
    }
    sram = fn_80436AF8();
    if (gbs == sram->gbs) {
        fn_80436B54(FALSE, sizeof(OSSram));
        return;
    }
    sram->gbs = gbs;
    fn_80436B54(TRUE, sizeof(OSSram));
}
