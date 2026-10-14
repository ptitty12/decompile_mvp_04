/*
 * Dolphin SDK OSTime.c (MWCC GC/1.2.5n, cflags_dolphin_sdk + -opt nopeephole), .text 0x80438628-0x80438778.
 * Split off dolphin/os/tu_80437444.c (OSThread.c) on 2026-10-13: the OSTime.c functions match only with
 * MWCC's peephole pass off, see docs/DECISIONS.md.
 * Not reproduced: OSGetTime/OSGetTick (OSGetTime/fn_80438640, mftb: original code, kept as split assembly).
 * fn_80438724 is EA's __init_cpp (reference-build name): it calls each entry of the 4-word constructor table at lbl_80649298
 * (declared void so MWCC takes r3 for the table address, as retail does; fn_80438704 is its void wrapper).
 */
#include <dolphin.h>
#include <dolphin/os.h>

extern OSTime OSGetTime(void);                       /* OSGetTime (original code) */

/* Bodies from the public dolsdk2004 OSTime.c (as reused by the RE4 decomp, docs/DECISIONS.md); 0x800030D8 is the
   OS globals' time-adjust word in low memory (OSPhysicalToCached(0x30D8)), not a DOL symbol. */
OSTime __OSGetSystemTime(void)
{
    BOOL enabled;
    OSTime* timeAdjustAddr;
    OSTime result;

    timeAdjustAddr = (OSTime*)0x800030D8;
    enabled = OSDisableInterrupts();
    result = OSGetTime() + *timeAdjustAddr;
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

void fn_80438724(void);

void fn_80438704(void)
{
    fn_80438724();
}

extern void (*lbl_80649298[])(void);

/* EA __init_cpp (reference-build name): calls each static constructor in the .ctors-style table. */
void fn_80438724(void)
{
    void (**ctor)(void);
    for (ctor = lbl_80649298; *ctor != 0; ctor++) {
        (*ctor)();
    }
}
