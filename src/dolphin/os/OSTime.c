/*
 * Dolphin SDK OSTime.c (MWCC GC/1.2.5n, cflags_dolphin_sdk + -opt nopeephole), .text 0x80438628-0x80438778.
 * Split off dolphin/os/tu_80437444.c (OSThread.c) on 2026-10-13: the OSTime.c functions match only with
 * MWCC's peephole pass off, see docs/DECISIONS.md.
 * Not reproduced: fn_80438628/fn_80438640 (OSGetTime/OSGetTick, mftb: original code, kept as split assembly).
 * fn_80438724 (a walk over a zeroed 4-entry function table at lbl_80649298) has no source shape yet.
 */
#include <dolphin.h>
#include <dolphin/os.h>

extern OSTime fn_80438628(void);                       /* OSGetTime (original code) */

/* Bodies from the public dolsdk2004 OSTime.c (as reused by the RE4 decomp, docs/DECISIONS.md); 0x800030D8 is the
   OS globals' time-adjust word in low memory (OSPhysicalToCached(0x30D8)), not a DOL symbol. */
OSTime __OSGetSystemTime(void)
{
    BOOL enabled;
    OSTime* timeAdjustAddr;
    OSTime result;

    timeAdjustAddr = (OSTime*)0x800030D8;
    enabled = OSDisableInterrupts();
    result = fn_80438628() + *timeAdjustAddr;
    OSRestoreInterrupts(enabled);
    return result;
}

OSTime fn_804386AC(OSTime time)                        /* __OSTimeToSystemTime */
{
    BOOL enabled;
    OSTime* timeAdjustAddr = (OSTime*)0x800030D8;
    OSTime result;

    enabled = OSDisableInterrupts();
    result = *timeAdjustAddr + time;
    OSRestoreInterrupts(enabled);
    return result;
}

BOOL fn_80438724(void);

BOOL fn_80438704(void)
{
    return fn_80438724();
}
