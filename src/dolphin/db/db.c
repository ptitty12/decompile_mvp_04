/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80421B84-0x80421C70 (code-only unit, 5 functions; original file name from the reference split).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/db.h>
#include <dolphin/os.h>

extern DBInterface* __DBInterface;
extern BOOL DBVerbose;
extern char lbl_80633660[];

void OSDumpContext(OSContext* context);
void PPCHalt(void);

void DBInit(void);
void fn_80421BAC(void);
void __DBExceptionDestination(void);
BOOL fn_80421C04(__OSException exception);
void DBPrintf(char* format, ...);

void DBInit(void) {
    __DBInterface = (DBInterface*)OSPhysicalToCached(OS_DBINTERFACE_ADDR);
    __DBInterface->ExceptionDestination = (void (*)(void))OSCachedToPhysical(__DBExceptionDestination);
    DBVerbose = TRUE;
}

void fn_80421BAC(void) {
    u32* contextAddr = (u32*)0x00C0;
    OSContext* context = (OSContext*)(*contextAddr + 0x80000000);

    OSReport(lbl_80633660);
    OSDumpContext(context);
    PPCHalt();
}

BOOL fn_80421C04(__OSException exception) {
    u32 mask = 1 << exception;
    return (BOOL)(__DBInterface->exceptionMask & mask);
}

void DBPrintf(char* format, ...) {
}
