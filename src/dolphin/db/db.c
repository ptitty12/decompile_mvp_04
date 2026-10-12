/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80421B84-0x80421C70 (code-only unit, 5 functions; original file name from the reference split).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/db.h>
#include <dolphin/os.h>

extern DBInterface* lbl_806EF608;
extern BOOL lbl_806EF60C;
extern char lbl_80633660[];

void fn_804338F4(OSContext* context); /* OSDumpContext */
void fn_8041A5E4(void);               /* PPCHalt */

void fn_80421B84(void);
void fn_80421BAC(void);
void fn_80421BF4(void);
BOOL fn_80421C04(__OSException exception);
void fn_80421C20(char* format, ...);

void fn_80421B84(void) {
    lbl_806EF608 = (DBInterface*)OSPhysicalToCached(OS_DBINTERFACE_ADDR);
    lbl_806EF608->ExceptionDestination = (void (*)(void))OSCachedToPhysical(fn_80421BF4);
    lbl_806EF60C = TRUE;
}

void fn_80421BAC(void) {
    u32* contextAddr = (u32*)0x00C0;
    OSContext* context = (OSContext*)(*contextAddr + 0x80000000);

    OSReport(lbl_80633660);
    fn_804338F4(context);
    fn_8041A5E4();
}

BOOL fn_80421C04(__OSException exception) {
    u32 mask = 1 << exception;
    return (BOOL)(lbl_806EF608->exceptionMask & mask);
}

void fn_80421C20(char* format, ...) {
}
