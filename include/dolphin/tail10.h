/*
 * Prototypes for Dolphin SDK functions that symbols.txt still names fn_<addr>, so the
 * tail OS units (src/dolphin/os/tu_*.c) can call them by the name the split uses.
 * The likely Nintendo name is in the comment. Additive only.
 */
#ifndef _DOLPHIN_TAIL10_H_
#define _DOLPHIN_TAIL10_H_

#include <dolphin/types.h>
#include <dolphin/os.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PPCArch (base/tu_8041A5A4.c) */
u32 fn_8041A5A4(void);            /* PPCMfmsr */
void fn_8041A5AC(u32 msr);        /* PPCMtmsr */
u32 fn_8041A5B4(void);            /* PPCMfhid0 */
void fn_8041A5BC(u32 hid0);       /* PPCMthid0 */
u32 fn_8041A5C4(void);            /* PPCMfl2cr */
void fn_8041A5CC(u32 l2cr);       /* PPCMtl2cr */
void fn_8041A5D4(u32 dec);        /* PPCMtdec */
void fn_8041A5DC(void);           /* PPCSync */
void fn_8041A5E4(void);           /* PPCHalt */
void fn_8041A5F8(u32 v);          /* PPCMtmmcr0 */
void fn_8041A600(u32 v);          /* PPCMtmmcr1 */
void fn_8041A608(u32 v);          /* PPCMtpmc1 */
void fn_8041A610(u32 v);          /* PPCMtpmc2 */
void fn_8041A618(u32 v);          /* PPCMtpmc3 */
void fn_8041A620(u32 v);          /* PPCMtpmc4 */
u32 fn_8041A628(void);            /* PPCMffpscr */
void fn_8041A648(u32 v);          /* PPCMtfpscr */
void fn_8041A694(void);           /* PPCDisableSpeculation */
void fn_8041A6BC(void);           /* PPCSetFpIEEEMode */

/* OSException */
void* fn_80432014(u8 exception, void* handler);  /* __OSSetExceptionHandler */
void* fn_80432030(u8 exception);                 /* __OSGetExceptionHandler */

/* OSArena */
void* fn_80432CB4(void);          /* OSGetArenaHi */
void* fn_80432CBC(void);          /* OSGetArenaLo */
void fn_80432CC4(void* hi);       /* OSSetArenaHi */
void fn_80432CCC(void* lo);       /* OSSetArenaLo */
void* fn_80432CD4(u32 size, u32 align); /* OSAllocFromArenaLo */

/* OSCache */
void fn_80432FA8(void* addr, u32 len);  /* DCInvalidateRange */
void fn_80432FD4(void* addr, u32 len);  /* DCFlushRange */
void fn_80433034(void* addr, u32 len);  /* DCFlushRangeNoSync */

/* OSContext */
void fn_80433734(OSContext* context);   /* OSLoadContext */
void fn_80433814(OSContext* context);   /* OSClearContext */
void fn_8043364C(OSContext* context);   /* OSSetCurrentContext */


/* OSThread */
s32 fn_80437484(void);            /* OSDisableScheduler */
s32 fn_804374C4(void);            /* OSEnableScheduler */
void fn_804379E0(void);           /* __OSReschedule */

/* OSTime */
OSTime fn_804386AC(OSTime time);  /* __OSTimeToSystemTime */
u32 fn_80438640(void);            /* OSGetTick */

/* DVD */
BOOL fn_80425724(void* alarm);    /* __DVDTestAlarm */

#ifdef __cplusplus
}
#endif

#endif
