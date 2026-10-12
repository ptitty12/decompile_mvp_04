/*
 * Dolphin SDK EXI (MWCC GC/1.2.5n, cflags_dolphin_sdk with -O3,p as EXIBios.c needs;
 * EXIUart.c at the end of this range may want -O4,p),
 * .text 0x80425E54-0x80428F14 (code-only unit, 51 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
/* FLAGS EVIDENCE (worker tail-09): 0x80425E54..0x80426CD0 is dvdlow.c (DVDLow*, DI registers at 0xCC006000,
 * not EXI). It compiles byte-identical (19 of 21 functions) with MWCC GC/1.2.5n -O4,p (cflags_dolphin_sdk /
 * cflags_dolphin_dvd), but this unit is configured with cflags_dolphin_exi (-O3,p), under which only
 * fn_80426C98 matches. The unit needs a split at 0x80426CD0 (EXIBios.c starts at fn_80426C54's successor
 * 0x80426CD0) with the DVD flags for the first part. The statics below are volatile only where that
 * reproduces the original load/store order (empirical; the SDK declares them volatile).
 * Parked: fn_80426174 (ProcessNextCommand) and fn_804263F8 (DVDLowRead), same instruction count, register
 * assignment differs because Prev/Curr are separate statics in the original. */
#include <dolphin.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>

#include <dolphin/hw_regs.h>

/* dvdlow.c part of this unit (0x80425E54..0x80426CD0). The statics sit in one .bss lump (lbl_806DE288) and
 * .sbss variables, all extern here. Placeholder names kept; likely SDK names:
 * fn_80425E54 __DVDInitWA, fn_80425E94 __DVDInterruptHandler, fn_80426174 ProcessNextCommand,
 * fn_804261F8 AlarmHandler, fn_80426268 Read, fn_80426378 SeekTwiceBeforeRead, fn_804263F8 DVDLowRead,
 * fn_80426690 DVDLowSeek, fn_80426724 DVDLowWaitCoverClose, fn_80426750 DVDLowReadDiskID,
 * fn_804267F4 DVDLowStopMotor, fn_80426880 DVDLowRequestError, fn_8042690C DVDLowInquiry,
 * fn_804269A8 DVDLowAudioStream, fn_80426A40 DVDLowRequestAudioStatus, fn_80426ACC DVDLowAudioBufferConfig,
 * fn_80426B68 DVDLowReset, fn_80426C24 DVDLowBreak, fn_80426C38 DVDLowClearCallback,
 * fn_80426C54 __DVDLowSetWAType, fn_80426C98 __DVDLowTestAlarm.
 * Other placeholder callees: fn_80432224 OSCreateAlarm, fn_80432484 OSSetAlarm, fn_80432568 OSCancelAlarm,
 * fn_80433814 OSClearContext, fn_8043364C OSSetCurrentContext, fn_80435350 __OSMaskInterrupts,
 * fn_80425508 (DVD drive-status flag accessor), fn_804321CC OSInitAlarm. */

typedef struct DvdLowCommand {
    s32 command;
    void* addr;
    u32 length;
    u32 offset;
    DVDLowCallback callback;
} DvdLowCommand;

typedef struct DvdLowBuffer {
    u32 addr;
    u32 length;
    u32 offset;
} DvdLowBuffer;

typedef struct DvdLowBss {
    DvdLowCommand commandList[3];
    u32 pad3C;
    OSAlarm alarmForWA;
    OSAlarm alarmForTimeout;
    OSAlarm alarmForBreak;
    DvdLowBuffer prev;
    DvdLowBuffer curr;
} DvdLowBss;

extern DvdLowBss lbl_806DE288;
extern OSAlarm lbl_806DE2F0;
extern OSAlarm lbl_806DE318;
extern s32 lbl_806EF210;               /* ResetOccurred-style flag in .sdata */
extern volatile s32 lbl_806EF6D8;               /* StopAtNextInt */
extern u32 lbl_806EF6DC;               /* last transfer length */
extern DVDLowCallback lbl_806EF6E0;    /* Callback */
extern DVDLowCallback lbl_806EF6E4;    /* ResetCoverCallback */
extern volatile OSTime lbl_806EF6E8;            /* LastResetEnd */
extern volatile u32 lbl_806EF6F0;               /* ResetOccurred */
extern volatile s32 lbl_806EF6F4;               /* WaitingCoverClose */
extern volatile s32 lbl_806EF6F8;               /* Breaking */
extern u32 lbl_806EF6FC;               /* WorkAroundType */
extern u32 lbl_806EF700;               /* WorkAroundSeekLocation */
extern volatile OSTime lbl_806EF708;            /* LastReadFinished */
extern OSTime lbl_806EF710;            /* LastReadIssued */
extern volatile s32 lbl_806EF718;               /* LastCommandWasRead */
extern volatile s32 lbl_806EF71C;               /* NextCommandNumber */

void fn_80432224(OSAlarm* alarm);
void fn_80432484(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
void fn_80432568(OSAlarm* alarm);
void fn_80433814(OSContext* context);
void fn_8043364C(OSContext* context);
void fn_80435350(u32 mask);
void fn_804321CC(void);
u8* fn_80425508(void);
void fn_80426C54(u32 type, u32 location);

void fn_80425E54(void);
void fn_80425E94(__OSInterrupt interrupt, OSContext* context);
void fn_80426174(OSAlarm* alarm, OSContext* context);
void fn_804261F8(OSAlarm* alarm, OSContext* context);
void fn_80426268(void* addr, u32 length, u32 offset, DVDLowCallback callback);
void fn_80426378(void* addr, u32 length, u32 offset, DVDLowCallback callback);
BOOL fn_804263F8(void* addr, u32 length, u32 offset, DVDLowCallback callback);
BOOL fn_80426690(u32 offset, DVDLowCallback callback);
BOOL fn_80426724(DVDLowCallback callback);
BOOL fn_80426750(DVDDiskID* diskID, DVDLowCallback callback);
BOOL fn_804267F4(DVDLowCallback callback);
BOOL fn_80426880(DVDLowCallback callback);
BOOL fn_8042690C(DVDDriveInfo* info, DVDLowCallback callback);
BOOL fn_804269A8(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback);
BOOL fn_80426A40(u32 subcmd, DVDLowCallback callback);
BOOL fn_80426ACC(BOOL eventMode, u32 bufferNum, DVDLowCallback callback);
void fn_80426B68(void);
BOOL fn_80426C24(void);
DVDLowCallback fn_80426C38(void);
BOOL fn_80426C98(const OSAlarm* alarm);

void fn_80425E54(void) {
    lbl_806EF71C = 0;
    lbl_806DE288.commandList[0].command = -1;
    fn_80426C54(0, 0);
    fn_804321CC();
}

void fn_80425E94(__OSInterrupt interrupt, OSContext* context) {
    DvdLowBss* bss = &lbl_806DE288;
    OSContext exceptionContext;
    u32 cause;
    u32 reg;
    u32 mask;
    u32 intr;

    cause = 0;
    if (lbl_806EF718) {
        lbl_806EF708 = __OSGetSystemTime();
        lbl_806EF210 = 0;
        bss->prev.addr = bss->curr.addr;
        bss->prev.length = bss->curr.length;
        bss->prev.offset = bss->curr.offset;
        if (lbl_806EF6D8 == 1) {
            cause |= 8;
        }
    }
    lbl_806EF718 = 0;
    lbl_806EF6D8 = 0;
    reg = __DIRegs[0];
    mask = reg & 0x2A;
    intr = reg & 0x54 & (mask << 1);
    if (intr & 0x40) {
        cause |= 8;
    }
    if (intr & 0x10) {
        cause |= 1;
    }
    if (intr & 0x04) {
        cause |= 2;
    }
    if (cause != 0) {
        lbl_806EF6F0 = 0;
        fn_80432568(&bss->alarmForTimeout);
    }
    __DIRegs[0] = intr | mask;
    if (lbl_806EF6F0 != 0 && (__OSGetSystemTime() - lbl_806EF6E8) < OSMillisecondsToTicks(200)) {
        reg = __DIRegs[1];
        mask = reg & 2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            if (lbl_806EF6E4) {
                lbl_806EF6E4(4);
            }
            lbl_806EF6E4 = NULL;
        }
        __DIRegs[1] = __DIRegs[1];
    } else if (lbl_806EF6F4) {
        reg = __DIRegs[1];
        mask = reg & 2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            cause |= 4;
        }
        __DIRegs[1] = intr | mask;
        lbl_806EF6F4 = 0;
    } else {
        __DIRegs[1] = 0;
    }
    if ((cause & 8) && !lbl_806EF6F8) {
        cause &= ~8;
    }
    if (cause & 1) {
        s32 n = lbl_806EF71C;
        BOOL handled;

        if (bss->commandList[n].command == 1) {
            lbl_806EF71C++;
            fn_80426268(bss->commandList[n].addr, bss->commandList[n].length, bss->commandList[n].offset, bss->commandList[n].callback);
            handled = TRUE;
        } else if (bss->commandList[n].command == 2) {
            lbl_806EF71C++;
            fn_80426690(bss->commandList[n].offset, bss->commandList[n].callback);
            handled = TRUE;
        } else {
            handled = FALSE;
        }
        if (handled) {
            return;
        }
    } else {
        bss->commandList[0].command = -1;
        lbl_806EF71C = 0;
    }
    fn_80433814(&exceptionContext);
    fn_8043364C(&exceptionContext);
    if (cause != 0) {
        DVDLowCallback cb = lbl_806EF6E0;

        lbl_806EF6E0 = NULL;
        if (cb) {
            cb(cause);
        }
        lbl_806EF6F8 = 0;
    }
    fn_80433814(&exceptionContext);
    fn_8043364C(context);
}

/* near-miss: ProcessNextCommand; the original loads the command once and keeps the base in r4 */
void fn_80426174(OSAlarm* alarm, OSContext* context) {
    s32 n = lbl_806EF71C;

    if (lbl_806DE288.commandList[n].command == 1) {
        lbl_806EF71C++;
        fn_80426268(lbl_806DE288.commandList[n].addr, lbl_806DE288.commandList[n].length, lbl_806DE288.commandList[n].offset, lbl_806DE288.commandList[n].callback);
    } else if (lbl_806DE288.commandList[n].command == 2) {
        lbl_806EF71C++;
        fn_80426690(lbl_806DE288.commandList[n].offset, lbl_806DE288.commandList[n].callback);
    }
}

void fn_804261F8(OSAlarm* alarm, OSContext* context) {
    OSContext exceptionContext;
    DVDLowCallback cb;

    fn_80435350(0x400);
    fn_80433814(&exceptionContext);
    fn_8043364C(&exceptionContext);
    cb = lbl_806EF6E0;
    lbl_806EF6E0 = NULL;
    if (cb) {
        cb(0x10);
    }
    fn_80433814(&exceptionContext);
    fn_8043364C(context);
}

void fn_80426268(void* addr, u32 length, u32 offset, DVDLowCallback callback) {
    DvdLowBss* bss = &lbl_806DE288;

    lbl_806EF6D8 = 0;
    lbl_806EF6E0 = callback;
    lbl_806EF718 = 1;
    lbl_806EF710 = __OSGetSystemTime();
    __DIRegs[2] = 0xA8000000;
    __DIRegs[3] = offset >> 2;
    __DIRegs[4] = length;
    __DIRegs[5] = (u32)addr;
    __DIRegs[6] = length;
    lbl_806EF6DC = length;
    __DIRegs[7] = 3;
    if (length > 0xA00000) {
        u32 ticks = OSSecondsToTicks(20);
        fn_80432224(&bss->alarmForTimeout);
        fn_80432484(&bss->alarmForTimeout, ticks, fn_804261F8);
    } else {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&bss->alarmForTimeout);
        fn_80432484(&bss->alarmForTimeout, ticks, fn_804261F8);
    }
}

void fn_80426378(void* addr, u32 length, u32 offset, DVDLowCallback callback) {
    DvdLowBss* bss = &lbl_806DE288;
    u32 newOffset;

    newOffset = offset & ~0x7FFF;
    if (newOffset == 0) {
        newOffset = 0;
    } else {
        newOffset += lbl_806EF700;
    }
    bss->commandList[0].command = 2;
    bss->commandList[0].offset = newOffset;
    bss->commandList[0].callback = callback;
    bss->commandList[1].command = 1;
    bss->commandList[1].addr = addr;
    bss->commandList[1].length = length;
    bss->commandList[1].offset = offset;
    bss->commandList[1].callback = callback;
    bss->commandList[2].command = -1;
    lbl_806EF71C = 0;
    fn_80426690(newOffset, callback);
}

/* near-miss: DVDLowRead, 166 = 166 instructions; register assignment of the Prev/Curr field addresses differs */
BOOL fn_804263F8(void* addr, u32 length, u32 offset, DVDLowCallback callback) {
    DvdLowBss* bss = &lbl_806DE288;
    u32* curOffset = &bss->curr.offset;
    u32* prevLength;
    u32* prevOffset;
    u32 prevEnd;
    u32 start;
    u32 gap;
    BOOL streaming;
    BOOL close;

    __DIRegs[6] = length;
    bss->curr.addr = (u32)addr;
    bss->curr.length = length;
    bss->curr.offset = offset;
    if (lbl_806EF6FC == 0) {
        bss->commandList[0].command = -1;
        lbl_806EF71C = 0;
        fn_80426268(addr, length, offset, callback);
    } else if (lbl_806EF6FC == 1) {
        if (lbl_806EF210) {
            fn_80426378(addr, length, offset, callback);
        } else {
            prevLength = &bss->prev.length;
            prevOffset = &bss->prev.offset;
            start = *curOffset >> 15;
            prevEnd = (*prevLength - 1 + *prevOffset) >> 15;
            streaming = fn_80425508()[8] ? TRUE : FALSE;
            gap = streaming ? 5 : 15;
            close = (start > prevEnd - 2) || (start < prevEnd + gap + 3);
            if (!close) {
                bss->commandList[0].command = -1;
                lbl_806EF71C = 0;
                fn_80426268(addr, length, offset, callback);
            } else {
                prevEnd = (*prevLength - 1 + *prevOffset) >> 15;
                start = *curOffset >> 15;
                if (prevEnd == start || prevEnd + 1 == start) {
                    OSTime now = __OSGetSystemTime();
                    OSTime elapsed = now - lbl_806EF708;
                    OSTime limit = OSMillisecondsToTicks(5);

                    if (elapsed > limit) {
                        bss->commandList[0].command = -1;
                        lbl_806EF71C = 0;
                        fn_80426268(addr, length, offset, callback);
                    } else {
                        bss->commandList[0].command = 1;
                        bss->commandList[0].addr = addr;
                        bss->commandList[0].length = length;
                        bss->commandList[0].offset = offset;
                        bss->commandList[0].callback = callback;
                        bss->commandList[1].command = -1;
                        lbl_806EF71C = 0;
                        fn_80432224(&bss->alarmForWA);
                        fn_80432484(&bss->alarmForWA, limit - elapsed + OSMicrosecondsToTicks(500), fn_80426174);
                    }
                } else {
                    fn_80426378(addr, length, offset, callback);
                }
            }
        }
    }
    return TRUE;
}

BOOL fn_80426690(u32 offset, DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = 0xAB000000;
    __DIRegs[3] = offset >> 2;
    __DIRegs[7] = 1;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_80426724(DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6F4 = 1;
    lbl_806EF6D8 = 0;
    __DIRegs[1] = 2;
    return TRUE;
}

BOOL fn_80426750(DVDDiskID* diskID, DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = 0xA8000040;
    __DIRegs[3] = 0;
    __DIRegs[4] = 0x20;
    __DIRegs[5] = (u32)diskID;
    __DIRegs[6] = 0x20;
    __DIRegs[7] = 3;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_804267F4(DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = 0xE3000000;
    __DIRegs[7] = 1;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_80426880(DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = 0xE0000000;
    __DIRegs[7] = 1;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_8042690C(DVDDriveInfo* info, DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = 0x12000000;
    __DIRegs[4] = 0x20;
    __DIRegs[5] = (u32)info;
    __DIRegs[6] = 0x20;
    __DIRegs[7] = 3;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_804269A8(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = subcmd | 0xE1000000;
    __DIRegs[3] = offset >> 2;
    __DIRegs[4] = length;
    __DIRegs[7] = 1;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_80426A40(u32 subcmd, DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = subcmd | 0xE2000000;
    __DIRegs[7] = 1;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

BOOL fn_80426ACC(BOOL eventMode, u32 bufferNum, DVDLowCallback callback) {
    lbl_806EF6E0 = callback;
    lbl_806EF6D8 = 0;
    __DIRegs[2] = 0xE4000000 | (eventMode ? 0x10000 : 0) | bufferNum;
    __DIRegs[7] = 1;
    {
        u32 ticks = OSSecondsToTicks(10);
        fn_80432224(&lbl_806DE2F0);
        fn_80432484(&lbl_806DE2F0, ticks, fn_804261F8);
    }
    return TRUE;
}

void fn_80426B68(void) {
    u32 reg;
    OSTime resetStart;

    __DIRegs[1] = 2;
    reg = __PIRegs[9];
    __PIRegs[9] = (reg & ~4) | 1;
    resetStart = __OSGetSystemTime();
    while (__OSGetSystemTime() - resetStart < OSMicrosecondsToTicks(12)) {
    }
    __PIRegs[9] = reg | 5;
    lbl_806EF6F0 = 1;
    lbl_806EF6E8 = __OSGetSystemTime();
}

BOOL fn_80426C24(void) {
    lbl_806EF6D8 = 1;
    lbl_806EF6F8 = 1;
    return TRUE;
}

DVDLowCallback fn_80426C38(void) {
    DVDLowCallback old;

    __DIRegs[1] = 0;
    old = lbl_806EF6E0;
    lbl_806EF6F4 = 0;
    lbl_806EF6E0 = NULL;
    return old;
}

void fn_80426C54(u32 type, u32 location) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    lbl_806EF6FC = type;
    lbl_806EF700 = location;
    OSRestoreInterrupts(enabled);
}

BOOL fn_80426C98(const OSAlarm* alarm) {
    if (alarm == &lbl_806DE318) {
        return TRUE;
    }
    if (alarm == &lbl_806DE2F0) {
        return TRUE;
    }
    return FALSE;
}
