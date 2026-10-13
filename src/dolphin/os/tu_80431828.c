/*
 * Dolphin SDK OS (OS.c, MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80431828-0x804321A0 (code-only unit, 12 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * This file needs -opt nopeephole (OS.c compiles with it, like dolphin/os/OS.c).
 *
 * Original-code functions are not reproduced: fn_80431FEC, fn_80432010, fn_80432044 (OSExceptionVector),
 * fn_804320E0, fn_80432138 (__OSPSInit, GQR clears). fn_80431D6C (OSExceptionInit) refers to labels inside
 * them: the labels inside fn_80432044 have no symbols.txt entry, so they are lbl_ placeholders (see below).
 * fn_80432014 / fn_80432030 / fn_8043218C are the tiny accessors below.
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/hw_regs.h>
#include <dolphin/tail10.h>

typedef struct OsBss {
    /* 0x00 */ u8 driveInfo[0x20];
    /* 0x20 */ DVDCommandBlock block;
    /* 0x50 */ OSExecParams params;
} OsBss;

extern OsBss lbl_806DF020;                  /* DriveInfo, DriveBlock, copy of the exec params */
extern OSBootInfo* lbl_806EF7A0;            /* BootInfo */
extern u32* lbl_806EF7A4;                   /* BI2DebugFlag */
extern u32 lbl_806EF7A8;                    /* BI2DebugFlagHolder */
extern u32 lbl_806EF89C;                    /* __PADSpec */
extern u32 lbl_806EF654;
extern BOOL lbl_806EF7C0;                  /* AreWeInitialized */
extern BOOL lbl_806EF7C8;
extern BOOL lbl_806EF7AC;
extern OSTime lbl_806EF7D0;                 /* __OSStartTime */
extern void** lbl_806EF7C4;                 /* exception handler table */
extern const char* lbl_806EF2B8;            /* __OSVersion */
/* The string __OSVersion points to is the first object of OS.c .data; the later string offsets (relative to the
 * pool base register) only come out right when it precedes them. The pointer itself is extern above. */
static char __OSVersionString[] = "<< Dolphin SDK - OS\trelease build: May 21 2004 09:28:09 (0x2301) >>";
extern u8 lbl_80701020[] AT_ADDRESS(0x80701020);

extern void fn_80403FF8(void);              /* EnableMetroTRKInterrupts */
extern void fn_80422FD8(void);              /* DVDInit */
extern int fn_80424F50(DVDCommandBlock* block, void* info, void* cb);   /* DVDInquiryAsync */
extern void fn_80427F18(void);              /* EXIInit */
extern void fn_80431D6C(void);              /* OSExceptionInit */
extern void fn_80433C20(void);              /* __OSContextInit */
extern void fn_80433304(void);              /* __OSCacheInit */
extern void fn_80434550(OSExecParams* params);   /* __OSGetExecParams */
extern void fn_80434F9C(void);              /* OSEnableInterrupts */
extern void fn_80435004(void);              /* __OSInterruptInit */
extern void fn_804357F4(void);              /* __OSModuleInit */
extern void fn_8043643C(void);              /* __OSResetSWInterruptHandler */
extern void fn_80435BD0(void);              /* __OSInitMemoryProtection */
extern void fn_80436960(void);              /* __OSInitSram */
extern void fn_80437274(void);              /* __OSInitSystemCall */
extern void fn_804372DC(void);              /* __OSThreadInit */
extern void fn_804321CC(void);              /* OSInitAlarm */
extern void fn_80432D00(void);              /* __OSInitAudioSystem */
extern u32 fn_80436404(void);               /* OSGetResetCode */

u32 fn_80431828(void);
void fn_80431850(s32 result, DVDCommandBlock* block);
void fn_8043188C(void);
void* fn_80432014(u8 exception, void* handler);
void* fn_80432030(u8 exception);
u32 fn_8043218C(void);

/* flags: matches only with -opt nopeephole */
/* OSGetConsoleType */
u32 fn_80431828(void)
{
    if (lbl_806EF7A0 == NULL || lbl_806EF7A0->consoleType == 0) {
        return 0x10000002;
    }
    return lbl_806EF7A0->consoleType;
}

/* flags: matches only with -opt nopeephole */
/* InquiryCallback */
void fn_80431850(s32 result, DVDCommandBlock* block)
{
    switch (block->state) {
    case 0:
        __OSDeviceCode = (u16)(0x8000 | *(u16*)(lbl_806DF020.driveInfo + 2));
        break;
    default:
        __OSDeviceCode = 1;
        break;
    }
}

/* flags: not matched (near-miss) */
/* OSInit */
/* near-miss 96.5%: bss base and string-pool base callee-saved registers are swapped (r31/r30), 3 instructions short; the
 * ClearArena `reset` flag is `(x & 0x80000000) ? 1 : 0` (retail cmplwi/beq/li/li, not neg/addic/subfe); the `&bss->params.regionStart/
 * regionEnd` addresses are separate addi's in retail (pointer locals tried, no change) */
void fn_8043188C(void)
{
    OsBss* bss = &lbl_806DF020;
    u32* debugInfo;

    if (lbl_806EF7C0 == 0) {
        lbl_806EF7C0 = 1;

        lbl_806EF7D0 = __OSGetSystemTime();
        OSDisableInterrupts();
        fn_80434550(&bss->params);

        fn_8041A5F8(0);
        fn_8041A600(0);
        fn_8041A608(0);
        fn_8041A610(0);
        fn_8041A618(0);
        fn_8041A620(0);
        fn_8041A694();
        fn_8041A6BC();

        lbl_806EF7A4 = NULL;
        lbl_806EF7A0 = (OSBootInfo*)0x80000000;
        lbl_806EF654 = 0;

        debugInfo = *(u32**)0x800000F4;
        if (debugInfo != NULL) {
            lbl_806EF7A4 = debugInfo + 3;
            lbl_806EF89C = debugInfo[9];
            *(u8*)0x800030E8 = (u8)*lbl_806EF7A4;
            *(u8*)0x800030E9 = (u8)lbl_806EF89C;
        } else if (lbl_806EF7A0->arenaHi) {
            lbl_806EF7A8 = *(u8*)0x800030E8;
            lbl_806EF7A4 = &lbl_806EF7A8;
            lbl_806EF89C = *(u8*)0x800030E9;
        }

        lbl_806EF654 = 1;
        fn_80432CCC(lbl_806EF7A0->arenaLo == NULL ? (void*)0x80701040 : lbl_806EF7A0->arenaLo);
        if (lbl_806EF7A0->arenaLo == NULL && lbl_806EF7A4 != NULL && *lbl_806EF7A4 < 2) {
            fn_80432CCC((char*)(((u32)lbl_80701020 + 0x1F) & ~0x1F));
        }
        fn_80432CC4(lbl_806EF7A0->arenaHi == NULL ? (void*)0x81780000 : lbl_806EF7A0->arenaHi);

        fn_80431D6C();
        fn_80437274();
        fn_804321CC();
        fn_804357F4();
        fn_80435004();
        __OSSetInterruptHandler(0x16, (void*)fn_8043643C);
        fn_80433C20();
        fn_80433304();
        fn_80427F18();
        SIInit();
        fn_80436960();
        fn_804372DC();
        fn_80432D00();
        PPCMthid2(PPCMfhid2() & ~0x40000000);
        if (lbl_806EF7C8 == 0) {
            fn_80435BD0();
        }

        OSReport("\nDolphin OS\n");
        OSReport("Kernel built : %s %s\n", "May 21 2004", "09:28:09");
        OSReport("Console Type : ");
        {
        u32 consoleType = fn_80431828();
        switch (consoleType & 0xF0000000) {
        case 0:
            OSReport("Retail %d\n", consoleType);
            break;
        case 0x10000000:
        case 0x20000000:
            switch (consoleType & 0x0FFFFFFF) {
            case 0x10000000:
                OSReport("Mac Emulator\n");
                break;
            case 0x10000001:
                OSReport("PC Emulator\n");
                break;
            case 0x10000002:
                OSReport("EPPC Arthur\n");
                break;
            case 0x10000003:
                OSReport("EPPC Minnow\n");
                break;
            default:
                OSReport("Development HW%d (%08x)\n", (consoleType & 0x0FFFFFFF) - 3, consoleType);
                break;
            }
            break;
        default:
            OSReport("%08x\n");
            break;
        }
        }
        OSReport("Memory %d MB\n", lbl_806EF7A0->memorySize >> 20);
        OSReport("Arena : 0x%x - 0x%x\n", fn_80432CBC(), fn_80432CB4());
        OSRegisterVersion(lbl_806EF2B8);
        if (lbl_806EF7A4 != NULL && *lbl_806EF7A4 >= 2) {
            fn_80403FF8();
        }

        /* ClearArena */
        {
            BOOL reset = (fn_80436404() & 0x80000000) ? 1 : 0;
            u32* saveStart = (u32*)&bss->params.regionStart;

            if (!reset) {
                memset(fn_80432CBC(), 0, (u32)fn_80432CB4() - (u32)fn_80432CBC());
            } else if (*saveStart == 0) {
                memset(fn_80432CBC(), 0, (u32)fn_80432CB4() - (u32)fn_80432CBC());
            } else if ((u32)fn_80432CBC() < *saveStart) {
                if ((u32)fn_80432CB4() <= *saveStart) {
                    memset(fn_80432CBC(), 0, (u32)fn_80432CB4() - (u32)fn_80432CBC());
                } else {
                    u32 saveEnd;

                    memset(fn_80432CBC(), 0, *saveStart - (u32)fn_80432CBC());
                    saveEnd = (u32)bss->params.regionEnd;
                    if ((u32)fn_80432CB4() > saveEnd) {
                        memset((void*)saveEnd, 0, (u32)fn_80432CB4() - saveEnd);
                    }
                }
            }
        }

        fn_80434F9C();
        if (lbl_806EF7C8 == 0) {
            fn_80422FD8();
            if (lbl_806EF7AC != 0) {
                __OSDeviceCode = 0x9000;
            } else {
                fn_80432FA8(bss, 0x20);
                fn_80424F50(&bss->block, bss, (void*)fn_80431850);
            }
        }
    }
}

extern u8 fn_80431FEC[];   /* __OSDBINTSTART (original code, OSDBIntegrator) */
extern u8 fn_80432010[];   /* __OSDBINTEND, __OSDBJUMPSTART (original code, OSDBJump) */
extern u8 fn_80432044[];   /* __OSEVStart: OSExceptionVector (original code) */
/* Labels inside OSExceptionVector (original code). symbols.txt has no entry for them, so they are
 * placeholders here: lbl_8043209C = fn_80432044+0x58 (__DBVECTOR), lbl_804320AC = fn_80432044+0x68
 * (__OSEVSetNumber), lbl_804320DC = fn_80432044+0x98 (__OSEVEnd). */
extern u8 lbl_8043209C[];
extern u8 lbl_804320AC[];
extern u8 lbl_804320DC[];
extern void fn_804320E0(void);   /* OSDefaultExceptionHandler (original code) */
void fn_80421C20(char* str, ...);               /* DBPrintf */
BOOL fn_80421C04(__OSException exception);      /* __DBIsExceptionMarked */

static u32 __OSExceptionLocations[] = {
    0x00000100, 0x00000200, 0x00000300, 0x00000400, 0x00000500, 0x00000600, 0x00000700, 0x00000800,
    0x00000900, 0x00000C00, 0x00000D00, 0x00000F00, 0x00001300, 0x00001400, 0x00001700,
};

/* flags: matches only with -opt nopeephole */
/* OSExceptionInit */
void fn_80431D6C(void)
{
    __OSException exception;
    void* destAddr;
    u32* opCodeAddr;
    u32 oldOpCode;
    u8* handlerStart;
    u32 handlerSize;

    opCodeAddr = (u32*)lbl_804320AC;
    oldOpCode = *opCodeAddr;
    handlerStart = (u8*)fn_80432044;
    handlerSize = (u32)lbl_804320DC - (u32)fn_80432044;

    destAddr = (void*)OSPhysicalToCached(0x60);
    if (*(u32*)destAddr == 0) {
        fn_80421C20("Installing OSDBIntegrator\n");
        memcpy(destAddr, (void*)fn_80431FEC, (u32)fn_80432010 - (u32)fn_80431FEC);
        fn_80433034(destAddr, (u32)fn_80432010 - (u32)fn_80431FEC);
        __sync();
        ICInvalidateRange(destAddr, (u32)fn_80432010 - (u32)fn_80431FEC);
    }

    for (exception = 0; exception < 15; exception++) {
        if (lbl_806EF7A4 && (*lbl_806EF7A4 >= 2) && fn_80421C04(exception)) {
            fn_80421C20(">>> OSINIT: exception %d commandeered by TRK\n", exception);
            continue;
        }

        *opCodeAddr = oldOpCode | exception;

        if (fn_80421C04(exception)) {
            fn_80421C20(">>> OSINIT: exception %d vectored to debugger\n", exception);
            memcpy((void*)lbl_8043209C, (void*)fn_80432010, (u32)fn_80432014 - (u32)fn_80432010);
        } else {
            u32* ops = (u32*)lbl_8043209C;
            int cb;

            for (cb = 0; cb < (u32)fn_80432014 - (u32)fn_80432010; cb += sizeof(u32)) {
                *ops++ = 0x60000000;
            }
        }

        destAddr = (void*)OSPhysicalToCached(__OSExceptionLocations[(u32)exception]);
        memcpy(destAddr, handlerStart, handlerSize);
        fn_80433034(destAddr, handlerSize);
        __sync();
        ICInvalidateRange(destAddr, handlerSize);
    }
    lbl_806EF7C4 = (void**)OSPhysicalToCached(0x3000);

    for (exception = 0; exception < 15; exception++) {
        fn_80432014(exception, (void*)fn_804320E0);
    }

    *opCodeAddr = oldOpCode;

    fn_80421C20("Exceptions initialized...\n");
}

/* flags: matches only with -opt nopeephole */
/* __OSSetExceptionHandler */
void* fn_80432014(u8 exception, void* handler)
{
    void* old = lbl_806EF7C4[exception];

    lbl_806EF7C4[exception] = handler;
    return old;
}

/* flags: matches only with -opt nopeephole */
/* __OSGetExceptionHandler */
void* fn_80432030(u8 exception)
{
    return lbl_806EF7C4[exception];
}

/* flags: matches only with -opt nopeephole */
/* __OSGetDIConfig */
u32 fn_8043218C(void)
{
    return __DIRegs[9] & 0xFF;
}
