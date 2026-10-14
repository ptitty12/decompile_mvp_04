/*
 * Dolphin SDK OS (OSCache, OSContext, OSError, OSExec, OSFont, OSInterrupt; MWCC GC/1.2.5n),
 * .text 0x804330D0-0x8043580C (code-only unit; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * Original-code functions in this range are not reproduced: fn_804330D0, fn_804330E4, fn_804333F8, fn_8043351C,
 * fn_80433644, fn_8043364C (mfmsr/mtmsr), fn_804336B4, fn_80433734, fn_8043380C, fn_80433838, fn_80433B9C,
 * fn_8043449C, fn_804344C4, OSDisableInterrupts, fn_80434F9C, OSRestoreInterrupts, fn_804357A4.
 *
 * The range is five source files (OSCache, OSContext, OSError, OSExec/OSFont, OSInterrupt); the "==== name ===="
 * markers below show the boundaries. String data is pooled per source file (offsets from the file's first string),
 * so functions that use several strings only match when each file is compiled as its own unit. The "flags:" tags
 * give the compiler flags a function needs: untagged functions match with the configured flags; the OSCache,
 * OSContext and OSInterrupt files compile with -opt nopeephole after their first original-code function.
 * Compile flags per source file (found by compiling each "====" section below as its own unit; every function tagged
 * "matches only with -opt nopeephole" is an exact match with that flag, and the untagged ones match with the configured
 * flags): OSCache, OSContext, OSExec (after Run, 0x8043449C) and OSInterrupt need -opt nopeephole; OSError, OSExec up to
 * Run (PackArgs) and OSFont use the configured flags. Section address ranges: OSCache 0x804330D0, OSContext 0x804333F8,
 * OSError 0x80433C68, OSExec 0x80434314, OSFont 0x80434C74, OSInterrupt 0x80434F88, OSLink (__OSModuleInit) 0x804357F4.
 * Not matched yet: fn_8043402C (callee-saved string base / table base swapped).
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/hw_regs.h>
#include <dolphin/tail10.h>

extern void fn_80421C20(char* msg, ...);              /* DBPrintf */
extern void fn_804330D0(void);                         /* ICEnable */
extern void fn_80432F94(void);                         /* DCEnable */
extern void fn_804338F4(OSContext* context);
extern s16 lbl_806EF818;               /* __OSLastInterrupt */
extern u32 lbl_806EF814;               /* __OSLastInterruptSrr0 */
extern s64 lbl_806EF820;               /* __OSLastInterruptTime */
extern OSTime fn_80438628(void);       /* OSGetTime */
extern u32 fn_8043380C(void);                          /* OSGetStackPointer (original code) */
extern void fn_80433B9C(void);                         /* floating point unavailable handler (original code) */
extern OSErrorHandler fn_80433E14(OSError error, OSErrorHandler handler);

extern OSContext* __OSCurrentContextCached AT_ADDRESS(0x800000D4);
extern OSContext* __OSFPUContextCached AT_ADDRESS(0x800000D8);

/* ==== OSCache ==== */

void fn_8043310C(void);
void fn_804331A4(u16 error, OSContext* context, ...);
void fn_80433304(void);

static void L2Disable(void)
{
    __sync();
    fn_8041A5CC(fn_8041A5C4() & 0x7FFFFFFF);
    __sync();
}

/* flags: matches only with -opt nopeephole */
/* L2GlobalInvalidate */
void fn_8043310C(void)
{
    L2Disable();
    fn_8041A5CC(fn_8041A5C4() | 0x200000);
    while (fn_8041A5C4() & 1) {
    }
    fn_8041A5CC(fn_8041A5C4() & ~0x200000);
    while (fn_8041A5C4() & 1) {
        fn_80421C20(">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n");
    }
}

/* flags: matches only with -opt nopeephole */
/* DMAErrorHandler */
void fn_804331A4(u16 error, OSContext* context, ...)
{
    u32 hid2 = PPCMfhid2();

    OSReport("Machine check received\n");
    OSReport("HID2 = 0x%x   SRR1 = 0x%x\n", hid2, context->srr1);
    if (!(hid2 & 0x00F00000) || !(context->srr1 & 0x00200000)) {
        OSReport("Machine check was not DMA/locked cache related\n");
        fn_804338F4(context);
        fn_8041A5E4();
    }

    OSReport("DMAErrorHandler(): An error occurred while processing DMA.\n");
    OSReport("The following errors have been detected and cleared :\n");

    if (hid2 & 0x00800000) {
        OSReport("\t- Requested a locked cache tag that was already in the cache\n");
    }
    if (hid2 & 0x00400000) {
        OSReport("\t- DMA attempted to access normal cache\n");
    }
    if (hid2 & 0x00200000) {
        OSReport("\t- DMA missed in data cache\n");
    }
    if (hid2 & 0x00100000) {
        OSReport("\t- DMA queue overflowed\n");
    }

    PPCMthid2(hid2);
}

static void L2Enable(void)
{
    fn_8041A5CC((fn_8041A5C4() | 0x80000000) & ~0x200000);
}

static void L2Init(void)
{
    u32 oldMSR;

    oldMSR = fn_8041A5A4();
    __sync();
    fn_8041A5AC(0x30);
    __sync();
    L2Disable();
    fn_8043310C();
    fn_8041A5AC(oldMSR);
}

/* flags: matches only with -opt nopeephole */
/* __OSCacheInit */
void fn_80433304(void)
{
    if (!(fn_8041A5B4() & 0x8000)) {
        fn_804330D0();
        fn_80421C20("L1 i-caches initialized\n");
    }
    if (!(fn_8041A5B4() & 0x4000)) {
        fn_80432F94();
        fn_80421C20("L1 d-caches initialized\n");
    }
    if (!(fn_8041A5C4() & 0x80000000)) {
        L2Init();
        L2Enable();
        fn_80421C20("L2 cache initialized\n");
    }
    fn_80433E14(1, fn_804331A4);
    fn_80421C20("Locked cache machine check handler installed\n");
}

/* ==== OSContext ==== */


void fn_804338F4(OSContext* context);
void fn_80433C20(void);
OSContext* fn_804336A8(void);

/* OSGetCurrentContext */
OSContext* fn_804336A8(void)
{
    return __OSCurrentContextCached;
}

/* flags: matches only with -opt nopeephole */
/* OSClearContext */
void fn_80433814(OSContext* context)
{
    context->mode = 0;
    context->state = 0;
    if (context == __OSFPUContextCached) {
        __OSFPUContextCached = NULL;
    }
}

/* flags: matches only with -opt nopeephole */
/* OSDumpContext */
void fn_804338F4(OSContext* context)
{
    u32 i;
    u32* p;

    OSReport("------------------------- Context 0x%08x -------------------------\n", context);
    for (i = 0; i < 16; i++) {
        OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i, context->gpr[i], context->gpr[i], i + 16,
                 context->gpr[i + 16], context->gpr[i + 16]);
    }
    OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", context->lr, context->cr);
    OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", context->srr0, context->srr1);
    OSReport("\nGQRs----------\n");
    for (i = 0; i < 4; i++) {
        OSReport("gqr%d = 0x%08x \t gqr%d = 0x%08x\n", i, context->gqr[i], i + 4, context->gqr[i + 4]);
    }

    if (context->state & OS_CONTEXT_STATE_FPSAVED) {
        OSContext* currentContext;
        OSContext fpuContext;
        BOOL enabled;

        enabled = OSDisableInterrupts();
        currentContext = fn_804336A8();
        fn_80433814(&fpuContext);
        fn_8043364C(&fpuContext);

        OSReport("\n\nFPRs----------\n");
        for (i = 0; i < 32; i += 2) {
            OSReport("fr%d \t= %d \t fr%d \t= %d\n", i, (u32)context->fpr[i], i + 1, (u32)context->fpr[i + 1]);
        }

        OSReport("\n\nPSFs----------\n");
        for (i = 0; i < 32; i += 2) {
            OSReport("ps%d \t= 0x%x \t ps%d \t= 0x%x\n", i, (u32)context->psf[i], i + 1, (u32)context->psf[i + 1]);
        }

        fn_80433814(&fpuContext);
        fn_8043364C(currentContext);
        OSRestoreInterrupts(enabled);
    }

    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (i = 0, p = (u32*)context->gpr[1]; p && (u32)p != 0xFFFFFFFF && i++ < 16; p = (u32*)*p) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
    }
}

/* flags: matches only with -opt nopeephole */
/* __OSContextInit */
void fn_80433C20(void)
{
    fn_80432014(7, (__OSExceptionHandler)fn_80433B9C);
    __OSFPUContextCached = NULL;
    fn_80421C20("FPU-unavailable handler installed\n");
}

/* ==== OSError ==== */

void OSReport(const char* msg, ...);
void fn_80433CE8(const char* file, int line, const char* msg, ...);

/* OSReport */
void OSReport(const char* msg, ...)
{
    va_list marker;

    va_start(marker, msg);
    vprintf(msg, marker);
    va_end(marker);
}

/* OSPanic */
void fn_80433CE8(const char* file, int line, const char* msg, ...)
{
    va_list marker;
    u32 i;
    u32* p;

    OSDisableInterrupts();
    va_start(marker, msg);
    vprintf(msg, marker);
    va_end(marker);
    OSReport(" in \"%s\" on line %d.\n", file, line);
    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (i = 0, p = (u32*)fn_8043380C(); p && (u32)p != 0xFFFFFFFF && i++ < 16; p = (u32*)*p) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
    }
    fn_8041A5E4();
}

extern u32 lbl_806EF2D8;               /* __OSFpscrEnableBits */
extern void* lbl_806DF090[17];         /* __OSErrorTable */

extern void fn_80433644(OSContext* context);           /* OSSaveFPUContext wrapper (original code) */

OSErrorHandler fn_80433E14(OSError error, OSErrorHandler handler);
void fn_8043402C(u8 exception, OSContext* context, u32 dsisr, u32 dar);

/* OSSetErrorHandler */
OSErrorHandler fn_80433E14(OSError error, OSErrorHandler handler)
{
    OSErrorHandler oldHandler;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    oldHandler = (OSErrorHandler)lbl_806DF090[error];
    lbl_806DF090[error] = (void*)handler;

    if (error == 16) {
        u32 msr;
        u32 fpscr;
        OSThread* thread;

        msr = fn_8041A5A4();
        fn_8041A5AC(msr | 0x2000);
        fpscr = fn_8041A628();
        if (handler) {
            for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
                thread->context.srr1 |= 0x900;
                if (!(thread->context.state & 1)) {
                    int i;

                    thread->context.state |= 1;
                    for (i = 0; i < 32; i++) {
                        *(u64*)&thread->context.fpr[i] = 0xFFFFFFFFFFFFFFFFull;
                        *(u64*)&thread->context.psf[i] = 0xFFFFFFFFFFFFFFFFull;
                    }
                    thread->context.fpscr = 4;
                }
                thread->context.fpscr |= (lbl_806EF2D8 & 0xF8);
                thread->context.fpscr &= 0x6005F8FF;
            }
            msr |= 0x900;
            fpscr |= (lbl_806EF2D8 & 0xF8);
        } else {
            for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
                thread->context.srr1 &= ~0x900;
                thread->context.fpscr &= ~0xF8;
                thread->context.fpscr &= 0x6005F8FF;
            }
            fpscr &= ~0xF8;
            msr &= ~0x900;
        }
        fpscr &= 0x6005F8FF;
        fn_8041A648(fpscr);
        fn_8041A5AC(msr);
    }

    OSRestoreInterrupts(enabled);
    return oldHandler;
}

typedef OSErrorHandler ErrHandler;


/* flags: not matched (near-miss) */
/* near-miss: only the callee-saved registers differ (string base r31 / error table r30 in retail, swapped here); the
 * `dar` argument of the program-exception report is part of the original call */
/* __OSUnhandledException */
void fn_8043402C(u8 exception, OSContext* context, u32 dsisr, u32 dar)
{
    void** table = lbl_806DF090;
    OSTime tb = fn_80438628();

    if (!(context->srr1 & 2)) {
        OSReport("Non-recoverable Exception %d", exception);
    } else {
        if (exception == 6 && (context->srr1 & 0x100000) && table[16]) {
            u32 fpscr;
            u32 msr;

            exception = 16;
            msr = fn_8041A5A4();
            fn_8041A5AC(msr | 0x2000);
            if (__OSFPUContextCached) {
                fn_80433644(__OSFPUContextCached);
            }
            fpscr = fn_8041A628();
            fn_8041A648(fpscr & 0x6005F8FF);
            fn_8041A5AC(msr);

            if (__OSFPUContextCached == context) {
                fn_80437484();
                ((ErrHandler)table[16])(16, context, dsisr, dar);
                context->srr1 &= ~0x2000;
                __OSFPUContextCached = NULL;
                context->fpscr &= 0x6005F8FF;
                fn_804374C4();
                fn_804379E0();
            } else {
                context->srr1 &= ~0x2000;
                __OSFPUContextCached = NULL;
            }
            fn_80433734(context);
        }

        if (table[exception]) {
            fn_80437484();
            ((ErrHandler)table[exception])(exception, context, dsisr, dar);
            fn_804374C4();
            fn_804379E0();
            fn_80433734(context);
        }

        if (exception == 8) {
            fn_80433734(context);
        }
        OSReport("Unhandled Exception %d", exception);
    }

    OSReport("\n");
    fn_804338F4(context);
    OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    OSReport("TB = 0x%016llx\n", tb);

    switch (exception) {
    case 2:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access invalid address 0x%x (read from DAR)\n",
                 context->srr0, dar);
        break;
    case 3:
        OSReport("\nAttempted to fetch instruction from invalid address 0x%x (read from SRR0)\n", context->srr0);
        break;
    case 5:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access unaligned address 0x%x (read from DAR)\n",
                 context->srr0, dar);
        break;
    case 6:
        OSReport("\nProgram exception : Possible illegal instruction/operation at or around 0x%x (read from SRR0)\n",
                 context->srr0, dar);
        break;
    case 15:
        OSReport("\n");
        OSReport("AI DMA Address =   0x%04x%04x\n", __DSPRegs[24], __DSPRegs[25]);
        OSReport("ARAM DMA Address = 0x%04x%04x\n", __DSPRegs[16], __DSPRegs[17]);
        OSReport("DI DMA Address =   0x%08x\n", __DIRegs[5]);
        break;
    }

    OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n", lbl_806EF818, lbl_806EF814, lbl_806EF820);
    fn_8041A5E4();
}

/* ==== OSExec ==== */

extern int fn_80424C14(DVDCommandBlock* block, void* addr, s32 length, s32 offset, void* callback, s32 prio);  /* DVDReadAbsAsyncPrio */
extern s32 fn_80425064(DVDCommandBlock* block);        /* DVDGetCommandBlockStatus */
extern BOOL fn_80425510(void);                         /* DVDCheckDisk */
extern void fn_804361BC(int);                          /* __OSDoHotReset */
extern s32 lbl_806EF7F8;                               /* Prepared */
extern s32 lbl_806EF7FC;                               /* cached dol/FST offset */

BOOL fn_80434314(void* ptr, int argc, char* argv[]);
void fn_804344D8(void* addr, s32 length, s32 offset);
void fn_80434544(void);
void fn_80434550(OSExecParams* params);
s32 fn_80434590(void);
void fn_80434654(u32 doloffset, u32 restartCode, void* regionStart, void* regionEnd, BOOL argsUseDefault, s32 argc, char** argv);
void fn_80434AD8(u32 doloffset, u32 restartCode, const char** argv);

/* PackArgs */
BOOL fn_80434314(void* addr, int argc, char* argv[])
{
    int numArgs;
    char* bootInfo2;
    char* ptr;
    char** list;
    u32 i;

    bootInfo2 = (char*)addr;
    memset(bootInfo2, 0, 0x2000);

    if (argc == 0) {
        *(u32*)(bootInfo2 + 8) = 0;
    } else {
        numArgs = argc;
        ptr = bootInfo2 + 0x2000;
        while (--argc >= 0) {
            ptr -= strlen(argv[argc]) + 1;
            strcpy(ptr, argv[argc]);
            argv[argc] = (char*)(ptr - bootInfo2);
        }

        ptr = bootInfo2 + ((ptr - bootInfo2) & ~0x3);
        ptr -= ((numArgs + 1) * 4);
        list = (char**)ptr;

        for (i = 0; i < numArgs + 1; i++) {
            list[i] = argv[i];
        }

        ptr -= 4;
        *(u32*)ptr = numArgs;

        *(u32*)(bootInfo2 + 8) = (ptr - bootInfo2);
    }

    return 1;
}

/* flags: matches only with -opt nopeephole */
/* Read (DVDReadAbsAsyncPrio + wait) */
void fn_804344D8(void* addr, s32 length, s32 offset)
{
    DVDCommandBlock block;

    fn_80424C14(&block, addr, length, offset, NULL, 0);
    while (fn_80425064(&block)) {
        if (!fn_80425510()) {
            fn_804361BC(0);
        }
    }
}

/* Callback */
void fn_80434544(void)
{
    lbl_806EF7F8 = 1;
}

/* flags: matches only with -opt nopeephole */
/* __OSGetExecParams */
void fn_80434550(OSExecParams* params)
{
    if (OS_BASE_CACHED <= *(u32*)0x800030F0) {
        memcpy(params, *(void**)0x800030F0, sizeof(OSExecParams));
    } else {
        params->valid = FALSE;
    }
}

extern BOOL fn_80434F9C(void);                         /* OSEnableInterrupts */
extern u32 fn_80435350(u32 global);                    /* __OSMaskInterrupts */
extern u32 __OSUnmaskInterrupts(u32 global);
extern void fn_80422FD8(void);                         /* DVDInit */
extern BOOL fn_8042515C(BOOL autoInvalidation);        /* DVDSetAutoInvalidation */
extern void fn_8042516C(void);                         /* DVDResume */
extern void fn_80425608(DVDCBCallback callback);       /* __DVDPrepareResetAsync */
extern DVDDiskID* fn_80425508(void);                   /* DVDGetCurrentDiskID */
extern int fn_80424E94(DVDCommandBlock* block, DVDCBCallback callback);  /* DVDCancelStreamAsync */
extern void fn_8043449C(void* entry);                  /* Run (original code) */
extern void fn_804330C0(void);                         /* ICFlashInvalidate */
extern void fn_80435FA4(void** start, void** end);     /* OSGetSaveRegion */

extern BOOL lbl_806EF7AC;                              /* __OSIsGcam */
extern volatile u32 lbl_812FDFF0 AT_ADDRESS(0x812FDFF0);
extern volatile u32 lbl_812FDFEC AT_ADDRESS(0x812FDFEC);
extern volatile u8 lbl_800030E2 AT_ADDRESS(0x800030E2);

/* flags: matches only with -opt nopeephole */
/* GetApploaderPosition */
s32 fn_80434590(void)
{
    u32* tgcHeader;
    s32 apploaderOffsetInTGC;

    if (lbl_806EF7FC != 0) {
        return lbl_806EF7FC;
    }

    if (__OSAppLoaderOffset != 0) {
        tgcHeader = fn_80432CD4(0x40, 0x20);
        fn_804344D8(tgcHeader, 0x40, __OSAppLoaderOffset);
        apploaderOffsetInTGC = tgcHeader[14];
        lbl_806EF7FC = __OSAppLoaderOffset + apploaderOffsetInTGC;
    } else {
        lbl_806EF7FC = 0x2440;
    }
    return lbl_806EF7FC;
}

typedef struct {
    char date[16];
    u32 entry;
    u32 size;
    u32 rebootSize;
    u32 reserved2;
} AppLoaderStruct;

/* StartDol */
static void StartDol(const OSExecParams* params, void* entry)
{
    OSExecParams* paramsWork = (OSExecParams*)fn_80432CD4(sizeof(OSExecParams), 1);

    memcpy(paramsWork, params, sizeof(OSExecParams));
    __OSExecParams = paramsWork;
    __PIRegs[9] = 7;

    OSDisableInterrupts();
    fn_8043449C(entry);
}

/* IsStreamEnabled */
static int IsStreamEnabled(void)
{
    if (fn_80425508()->streaming) {
        return TRUE;
    }

    return FALSE;
}

/* StopStreaming */
static void StopStreaming(void)
{
    DVDCommandBlock block;

    if (!lbl_806EF7AC && IsStreamEnabled()) {
        AISetStreamVolLeft(0);
        AISetStreamVolRight(0);
        fn_80424E94(&block, NULL);

        while (fn_80425064(&block)) {
            if (!fn_80425510()) {
                fn_804361BC(0);
            }
        }

        AISetStreamPlayState(0);
    }
}

/* LoadApploader */
static AppLoaderStruct* LoadApploader(void)
{
    AppLoaderStruct* header;

    header = (AppLoaderStruct*)fn_80432CD4(sizeof(AppLoaderStruct), 0x20);
    fn_804344D8(header, sizeof(AppLoaderStruct), fn_80434590());

    fn_804344D8((void*)0x81200000, OSRoundUp32B(header->size), fn_80434590() + 0x20);
    ICInvalidateRange((void*)0x81200000, OSRoundUp32B(header->size));
    return header;
}

/* LoadDol */
static void* LoadDol(const OSExecParams* params, AppLoaderCallback getInterface)
{
    appInitCallback appInit;
    appGetNextCallback appGetNext;
    appGetEntryCallback appGetEntry;
    void* addr;
    u32 length;
    u32 offset;
    OSExecParams* paramsWork;

    getInterface(&appInit, &appGetNext, &appGetEntry);
    paramsWork = (OSExecParams*)fn_80432CD4(sizeof(OSExecParams), 1);
    memcpy(paramsWork, params, sizeof(OSExecParams));
    __OSExecParams = paramsWork;
    appInit((void (*)(char*))OSReport);
    fn_80432CCC(paramsWork);

    while (appGetNext(&addr, &length, &offset) != 0) {
        fn_804344D8(addr, length, offset);
    }

    return appGetEntry();
}

/* IsNewApploader */
static BOOL IsNewApploader(AppLoaderStruct* header)
{
    return strncmp(header->date, "2004/02/01", 10) > 0 ? TRUE : FALSE;
}

/* flags: matches only with -opt nopeephole */
/* __OSBootDolSimple */
void fn_80434654(u32 doloffset, u32 restartCode, void* regionStart, void* regionEnd, BOOL argsUseDefault, s32 argc, char** argv)
{
    OSExecParams* params;
    void* dolEntry;
    AppLoaderStruct* header;

    OSDisableInterrupts();
    params = (OSExecParams*)fn_80432CD4(sizeof(OSExecParams), 1);
    params->valid = TRUE;
    params->restartCode = restartCode;
    params->regionStart = regionStart;
    params->regionEnd = regionEnd;
    params->argsUseDefault = argsUseDefault;

    if (!argsUseDefault) {
        params->argsAddr = fn_80432CD4(0x2000, 1);
        fn_80434314(params->argsAddr, argc, argv);
    }

    fn_80422FD8();
    fn_8042515C(TRUE);
    fn_8042516C();

    lbl_806EF7F8 = FALSE;

    fn_80425608((DVDCBCallback)fn_80434544);
    fn_80435350(0xFFFFFFE0);
    __OSUnmaskInterrupts(0x400);
    fn_80434F9C();

    while (lbl_806EF7F8 != TRUE) {
        if (!fn_80425510()) {
            fn_804361BC(0);
        }
    }

    StopStreaming();

    header = LoadApploader();
    if (IsNewApploader(header)) {
        if (doloffset == 0xFFFFFFFF) {
            doloffset = (fn_80434590() + 0x20) + header->size;
        }

        params->bootDol = doloffset;
        dolEntry = LoadDol(params, (AppLoaderCallback)header->entry);
        StartDol(params, dolEntry);
    } else {
        lbl_812FDFF0 = (u32)regionStart;
        lbl_812FDFEC = (u32)regionEnd;
        lbl_800030E2 = 1;

        fn_804344D8((void*)0x81300000, OSRoundUp32B(header->rebootSize), (fn_80434590() + 0x20) + header->size);
        ICInvalidateRange((void*)0x81300000, OSRoundUp32B(header->rebootSize));
        OSDisableInterrupts();
        fn_804330C0();
        fn_8043449C((void*)0x81300000);
    }
}

/* flags: matches only with -opt nopeephole */
/* __OSBootDol */
void fn_80434AD8(u32 doloffset, u32 restartCode, const char** argv)
{
    char doloffInString[20];
    s32 argvlen;
    char** argvToPass;
    s32 i;
    void* saveStart;
    void* saveEnd;

    fn_80435FA4(&saveStart, &saveEnd);
    sprintf(doloffInString, "%d", doloffset);
    argvlen = 0;

    if (argv != 0) {
        while (argv[argvlen] != 0) {
            argvlen++;
        }
    }

    argvlen++;
    argvToPass = (char**)fn_80432CD4((argvlen + 1) * 4, 1);
    *argvToPass = doloffInString;

    for (i = 1; i < argvlen; i++) {
        argvToPass[i] = (char*)argv[i - 1];
    }

    fn_80434654(-1, restartCode, saveStart, saveEnd, FALSE, argvlen, argvToPass);
}

/* ==== OSFont ==== */

extern u16 lbl_80636598[];              /* single-byte code table (0x20..0xDF) */
extern u16 lbl_80636718[];              /* SJIS level 1 table */
extern u16 lbl_806EF2F0;                /* FontEncode */
extern void* lbl_806EF80C;              /* ParseString function pointer */
extern void* lbl_806EF800;              /* font data (ANSI) */
extern void* lbl_806EF804;              /* font data (SJIS) */

u32 fn_80434C74(u16 encode, u16 code);
u16 fn_80434DE8(void);
char* fn_80434E4C(u16 encode, const char* string, void** pfont, int* pfontCode);

static BOOL IsSjisTrailByte(u8 c)
{
    return (0x40 <= c && c <= 0xFC) && (c != 0x7F);
}

static BOOL IsSjisLeadByte(u8 c)
{
    return (0x81 <= c && c <= 0x9F) || (0xE0 <= c && c <= 0xFC);
}

/* GetFontCode */

u32 fn_80434C74(u16 encode, u16 code)
{
    if (encode == 1) {
        if (code >= 0x20 && code <= 0xDF) {
            return lbl_80636598[code - 0x20];
        }
        if (code > 0x889E && code <= 0x9872) {
            int row = code >> 8;
            int col = code & 0xFF;
            int idx = (row - 0x88) * 0xBC;

            if (!IsSjisTrailByte(col)) {
                return 0;
            }
            col -= 0x40;
            if (col >= 0x40) {
                col--;
            }
            return idx + col + 0x2BE;
        }
        if (code >= 0x8140 && code < 0x879E) {
            int row = code >> 8;
            int col = code & 0xFF;
            int idx = (row - 0x81) * 0xBC;

            if (!IsSjisTrailByte(col)) {
                return 0;
            }
            col -= 0x40;
            if (col >= 0x40) {
                col--;
            }
            return lbl_80636718[idx + col];
        }
    } else {
        if (code > 0x20 && code <= 0xFF) {
            return code - 0x20;
        }
    }
    return 0;
}

/* OSGetFontEncode (VI_PAL..VI_EURGB60 are empty cases that fall into default) */
u16 fn_80434DE8(void)
{
    if (lbl_806EF2F0 != 0xFFFF) {
        return lbl_806EF2F0;
    }
    switch (*(volatile int*)0x800000CC) {
    case 0:
        lbl_806EF2F0 = (__VIRegs[55] & 2) ? 1 : 0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    default:
        lbl_806EF2F0 = 0;
        break;
    }
    lbl_806EF80C = (void*)fn_80434E4C;
    return lbl_806EF2F0;
}

/* ParseStringS */
char* fn_80434E4C(u16 encode, const char* string, void** pfont, int* pfontCode)
{
    void* font;
    u16 code = 0;

    switch (encode) {
    case 0:
        font = lbl_806EF800;
        code = *string;
        if (code != 0) {
            string++;
        }
        break;
    case 1:
        font = lbl_806EF804;
        code = *string;
        if (code == 0) {
            break;
        }
        string++;

        if (IsSjisLeadByte(code) && IsSjisTrailByte(*string)) {
            code = (code << 8 | *string++);
        }
        break;
    }

    *pfont = font;
    *pfontCode = fn_80434C74(encode, code);

    return (char*)string;
}

/* ==== OSInterrupt ==== */

typedef void (*InterruptHandler)(s16 interrupt, OSContext* context);

extern InterruptHandler* lbl_806EF810;      /* InterruptHandlerTable */
extern u32 lbl_806370A8[];                  /* InterruptPrioTable */

extern void fn_804357A4(void);

InterruptHandler fn_80434FF0(s16 interrupt);
void fn_80435004(void);
u32 fn_80435078(u32 mask, u32 current);
u32 fn_80435350(u32 global);
void fn_80435460(u16 exception, OSContext* context);
void fn_804357F4(void);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler)
{
    __OSInterruptHandler old;

    old = lbl_806EF810[interrupt];
    lbl_806EF810[interrupt] = handler;
    return old;
}

/* __OSGetInterruptHandler */
InterruptHandler fn_80434FF0(s16 interrupt)
{
    return lbl_806EF810[interrupt];
}

/* flags: matches only with -opt nopeephole */
/* __OSInterruptInit */
void fn_80435004(void)
{
    lbl_806EF810 = (InterruptHandler*)0x80003040;
    memset(lbl_806EF810, 0, 32 * sizeof(InterruptHandler));
    *(u32*)0x800000C4 = 0;
    *(u32*)0x800000C8 = 0;
    __PIRegs[1] = 0xF0;
    fn_80435350(0xFFFFFFE0);
    fn_80432014(4, (__OSExceptionHandler)fn_804357A4);
}

/* flags: matches only with -opt nopeephole */
/* SetInterruptMask */
u32 fn_80435078(u32 mask, u32 current)
{
    u32 reg;

    switch (__cntlzw(mask)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        reg = 0;
        if (!(current & OS_INTERRUPTMASK_MEM_0)) {
            reg |= 0x1;
        }
        if (!(current & OS_INTERRUPTMASK_MEM_1)) {
            reg |= 0x2;
        }
        if (!(current & OS_INTERRUPTMASK_MEM_2)) {
            reg |= 0x4;
        }
        if (!(current & OS_INTERRUPTMASK_MEM_3)) {
            reg |= 0x8;
        }
        if (!(current & OS_INTERRUPTMASK_MEM_ADDRESS)) {
            reg |= 0x10;
        }
        __MEMRegs[14] = (u16)reg;
        mask &= ~OS_INTERRUPTMASK_MEM;
        break;
    case 5:
    case 6:
    case 7:
        reg = __DSPRegs[5];
        reg &= ~0x1F8;
        if (!(current & OS_INTERRUPTMASK_DSP_AI)) {
            reg |= 0x10;
        }
        if (!(current & OS_INTERRUPTMASK_DSP_ARAM)) {
            reg |= 0x40;
        }
        if (!(current & OS_INTERRUPTMASK_DSP_DSP)) {
            reg |= 0x100;
        }
        __DSPRegs[5] = (u16)reg;
        mask &= ~OS_INTERRUPTMASK_DSP;
        break;
    case 8:
        reg = __AIRegs[0];
        reg &= ~0x2C;
        if (!(current & OS_INTERRUPTMASK_AI_AI)) {
            reg |= 0x4;
        }
        __AIRegs[0] = reg;
        mask &= ~OS_INTERRUPTMASK_AI;
        break;
    case 9:
    case 10:
    case 11:
        reg = __EXIRegs[0];
        reg &= ~0x2C0F;
        if (!(current & OS_INTERRUPTMASK_EXI_0_EXI)) {
            reg |= 0x1;
        }
        if (!(current & OS_INTERRUPTMASK_EXI_0_TC)) {
            reg |= 0x4;
        }
        if (!(current & OS_INTERRUPTMASK_EXI_0_EXT)) {
            reg |= 0x400;
        }
        __EXIRegs[0] = reg;
        mask &= ~OS_INTERRUPTMASK_EXI_0;
        break;
    case 12:
    case 13:
    case 14:
        reg = __EXIRegs[5];
        reg &= ~0xC0F;
        if (!(current & OS_INTERRUPTMASK_EXI_1_EXI)) {
            reg |= 0x1;
        }
        if (!(current & OS_INTERRUPTMASK_EXI_1_TC)) {
            reg |= 0x4;
        }
        if (!(current & OS_INTERRUPTMASK_EXI_1_EXT)) {
            reg |= 0x400;
        }
        __EXIRegs[5] = reg;
        mask &= ~OS_INTERRUPTMASK_EXI_1;
        break;
    case 15:
    case 16:
        reg = __EXIRegs[10];
        reg &= ~0xF;
        if (!(current & OS_INTERRUPTMASK_EXI_2_EXI)) {
            reg |= 0x1;
        }
        if (!(current & OS_INTERRUPTMASK_EXI_2_TC)) {
            reg |= 0x4;
        }
        __EXIRegs[10] = reg;
        mask &= ~OS_INTERRUPTMASK_EXI_2;
        break;
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        reg = 0xF0;
        if (!(current & OS_INTERRUPTMASK_PI_CP)) {
            reg |= 0x800;
        }
        if (!(current & OS_INTERRUPTMASK_PI_SI)) {
            reg |= 0x8;
        }
        if (!(current & OS_INTERRUPTMASK_PI_DI)) {
            reg |= 0x4;
        }
        if (!(current & OS_INTERRUPTMASK_PI_RSW)) {
            reg |= 0x2;
        }
        if (!(current & OS_INTERRUPTMASK_PI_ERROR)) {
            reg |= 0x1;
        }
        if (!(current & OS_INTERRUPTMASK_PI_VI)) {
            reg |= 0x100;
        }
        if (!(current & OS_INTERRUPTMASK_PI_DEBUG)) {
            reg |= 0x1000;
        }
        if (!(current & OS_INTERRUPTMASK_PI_PE_TOKEN)) {
            reg |= 0x200;
        }
        if (!(current & OS_INTERRUPTMASK_PI_PE_FINISH)) {
            reg |= 0x400;
        }
        if (!(current & OS_INTERRUPTMASK_PI_HSP)) {
            reg |= 0x2000;
        }
        __PIRegs[1] = reg;
        mask &= ~OS_INTERRUPTMASK_PI;
        break;
    }
    return mask;
}

/* with -opt nopeephole (OSInterrupt compiled as its own unit) the exact body is
 *   mask = ~(prev | local) & global; global |= prev; *(u32*)0x800000C4 = global;
 *   while (mask) { mask = SetInterruptMask(mask, global | local); }
 * (and the mirror image for the unmask: mask = (prev | local) & global; global = prev & ~global; ...),
 * with plain (non-volatile) reads of 0x800000C4/0x800000C8; with the configured flags that form scores lower
 * (86.32% against 90.29% for the volatile form below), so the volatile form is kept. */
/* flags: not matched (near-miss; this form is the better one with the configured flags) */
/* __OSMaskInterrupts */
u32 fn_80435350(u32 global)
{
    BOOL enabled;
    u32 prev;
    u32 local;
    u32 mask;

    enabled = OSDisableInterrupts();
    prev = *(volatile u32*)0x800000C4;
    local = *(volatile u32*)0x800000C8;
    mask = global & ~(prev | local);
    global |= prev;
    *(volatile u32*)0x800000C4 = global;
    global |= local;
    while (mask) {
        mask = fn_80435078(mask, global);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}

/* flags: not matched (near-miss; see the note above __OSMaskInterrupts) */
/* __OSUnmaskInterrupts */
u32 __OSUnmaskInterrupts(u32 global)
{
    BOOL enabled;
    u32 prev;
    u32 local;
    u32 mask;

    enabled = OSDisableInterrupts();
    prev = *(volatile u32*)0x800000C4;
    local = *(volatile u32*)0x800000C8;
    mask = global & (prev | local);
    global = prev & ~global;
    *(volatile u32*)0x800000C4 = global;
    global |= local;
    while (mask) {
        mask = fn_80435078(mask, global);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}

/* flags: matches only with -opt nopeephole */
/* __OSDispatchInterrupt */
void fn_80435460(u16 exception, OSContext* context)
{
    s16 interrupt;
    u32 intsr;
    u32 cause;
    u32 unmasked;
    u32* prio;
    InterruptHandler handler;
    u32 reg;

    intsr = __PIRegs[0];
    intsr &= ~0x10000;
    if (intsr == 0 || (intsr & __PIRegs[1]) == 0) {
        fn_80433734(context);
    }

    cause = 0;
    if (intsr & 0x80) {
        reg = __MEMRegs[15];
        if (reg & 0x1) {
            cause |= OS_INTERRUPTMASK_MEM_0;
        }
        if (reg & 0x2) {
            cause |= OS_INTERRUPTMASK_MEM_1;
        }
        if (reg & 0x4) {
            cause |= OS_INTERRUPTMASK_MEM_2;
        }
        if (reg & 0x8) {
            cause |= OS_INTERRUPTMASK_MEM_3;
        }
        if (reg & 0x10) {
            cause |= OS_INTERRUPTMASK_MEM_ADDRESS;
        }
    }
    if (intsr & 0x40) {
        reg = __DSPRegs[5];
        if (reg & 0x8) {
            cause |= OS_INTERRUPTMASK_DSP_AI;
        }
        if (reg & 0x20) {
            cause |= OS_INTERRUPTMASK_DSP_ARAM;
        }
        if (reg & 0x80) {
            cause |= OS_INTERRUPTMASK_DSP_DSP;
        }
    }
    if (intsr & 0x20) {
        reg = __AIRegs[0];
        if (reg & 0x8) {
            cause |= OS_INTERRUPTMASK_AI_AI;
        }
    }
    if (intsr & 0x10) {
        reg = __EXIRegs[0];
        if (reg & 0x2) {
            cause |= OS_INTERRUPTMASK_EXI_0_EXI;
        }
        if (reg & 0x8) {
            cause |= OS_INTERRUPTMASK_EXI_0_TC;
        }
        if (reg & 0x800) {
            cause |= OS_INTERRUPTMASK_EXI_0_EXT;
        }
        reg = __EXIRegs[5];
        if (reg & 0x2) {
            cause |= OS_INTERRUPTMASK_EXI_1_EXI;
        }
        if (reg & 0x8) {
            cause |= OS_INTERRUPTMASK_EXI_1_TC;
        }
        if (reg & 0x800) {
            cause |= OS_INTERRUPTMASK_EXI_1_EXT;
        }
        reg = __EXIRegs[10];
        if (reg & 0x2) {
            cause |= OS_INTERRUPTMASK_EXI_2_EXI;
        }
        if (reg & 0x8) {
            cause |= OS_INTERRUPTMASK_EXI_2_TC;
        }
    }
    if (intsr & 0x2000) {
        cause |= OS_INTERRUPTMASK_PI_HSP;
    }
    if (intsr & 0x1000) {
        cause |= OS_INTERRUPTMASK_PI_DEBUG;
    }
    if (intsr & 0x400) {
        cause |= OS_INTERRUPTMASK_PI_PE_FINISH;
    }
    if (intsr & 0x200) {
        cause |= OS_INTERRUPTMASK_PI_PE_TOKEN;
    }
    if (intsr & 0x100) {
        cause |= OS_INTERRUPTMASK_PI_VI;
    }
    if (intsr & 0x8) {
        cause |= OS_INTERRUPTMASK_PI_SI;
    }
    if (intsr & 0x4) {
        cause |= OS_INTERRUPTMASK_PI_DI;
    }
    if (intsr & 0x2) {
        cause |= OS_INTERRUPTMASK_PI_RSW;
    }
    if (intsr & 0x800) {
        cause |= OS_INTERRUPTMASK_PI_CP;
    }
    if (intsr & 0x1) {
        cause |= OS_INTERRUPTMASK_PI_ERROR;
    }

    unmasked = cause & ~(*(volatile u32*)0x800000C4 | *(volatile u32*)0x800000C8);
    if (unmasked) {
        for (prio = lbl_806370A8;; prio++) {
            if (unmasked & *prio) {
                interrupt = (s16)__cntlzw(unmasked & *prio);
                break;
            }
        }

        handler = fn_80434FF0(interrupt);
        if (handler) {
            if (interrupt > 4) {
                lbl_806EF818 = interrupt;
                lbl_806EF820 = fn_80438628();
                lbl_806EF814 = context->srr0;
            }
            fn_80437484();
            handler(interrupt, context);
            fn_804374C4();
            fn_804379E0();
            fn_80433734(context);
        }
    }
    fn_80433734(context);
}

extern void fn_804357A4(void);                         /* ExternalInterruptHandler wrapper (original code) */
extern OSModuleQueue __OSModuleInfoList AT_ADDRESS(0x800030C8);
extern void* __OSStringTable AT_ADDRESS(0x800030D0);

/* __OSModuleInit (OSLink.c: own unit, configured flags) */
void fn_804357F4(void)
{
    __OSModuleInfoList.head = __OSModuleInfoList.tail = 0;
    __OSStringTable = 0;
}
