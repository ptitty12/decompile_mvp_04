/*
 * Dolphin SDK OSTime.c (MWCC GC/1.2.5n, cflags_dolphin_sdk + -opt nopeephole), .text 0x80438628-0x80438778.
 * Split off dolphin/os/tu_80437444.c (OSThread.c) on 2026-10-13: the OSTime.c functions match only with
 * peephole off (register copies come out as `addi rX,rY,0` in retail), see docs/DECISIONS.md.
 * Not reproduced: fn_80438628/fn_80438640 (OSGetTime/OSGetTick, mftb: original code, kept as split assembly).
 * fn_80438724 (a walk over a zeroed 4-entry function table at lbl_80649298) has no source shape yet.
 */
#include <dolphin.h>
#include <dolphin/os.h>

BOOL fn_80438724(void);

BOOL fn_80438704(void)
{
    return fn_80438724();
}
