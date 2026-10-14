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
u32 PPCMfmsr(void);
void PPCMtmsr(u32 msr);
u32 PPCMfhid0(void);
void fn_8041A5BC(u32 hid0);       /* PPCMthid0 */
u32 PPCMfl2cr(void);
void PPCMtl2cr(u32 l2cr);
void PPCMtdec(u32 dec);
void PPCSync(void);
void PPCHalt(void);
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
__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler);
__OSExceptionHandler __OSGetExceptionHandler(__OSException exception);

/* OSArena */
void* OSGetArenaHi(void);
void* OSGetArenaLo(void);
void fn_80432CC4(void* hi);       /* OSSetArenaHi */
void OSSetArenaLo(void* lo);
void* fn_80432CD4(u32 size, u32 align); /* OSAllocFromArenaLo */

/* OSCache */
void DCInvalidateRange(void* addr, u32 len);
void DCFlushRange(void* addr, u32 len);
void DCFlushRangeNoSync(void* addr, u32 len);

/* OSContext */
void OSLoadContext(OSContext* context);
void OSClearContext(OSContext* context);
void OSSetCurrentContext(OSContext* context);


/* OSThread */
s32 OSDisableScheduler(void);
s32 OSEnableScheduler(void);
void __OSReschedule(void);

/* OSTime */
OSTime fn_804386AC(OSTime time);  /* __OSTimeToSystemTime */
u32 fn_80438640(void);            /* OSGetTick */

/* DVD */
BOOL fn_80425724(void* alarm);    /* __DVDTestAlarm */

#ifdef __cplusplus
}
#endif

#endif
