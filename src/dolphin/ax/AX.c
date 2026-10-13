/* Imported from emoose/re4 @ feb6805b (src/lib/AX.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, ax library; names are Nintendo's. */
#include <dolphin.h>
#include <dolphin/ax.h>

#include "__ax.h"

/* Existing retail AX providers, retaining their SDK call contracts. */
extern void fn_804178C8(void);
extern void fn_80419F7C(void);
extern void fn_8041949C(void);
extern void fn_80417D04(void);
extern void fn_8041888C(void);
extern void fn_80418CA0 (u32 outputBufferMode);
extern void fn_8041797C(void);
extern void fn_8041A180(void);
extern void fn_804194C8(void);
extern void fn_80417DE8(void);
extern void fn_804188B0(void);
extern void fn_80419040(void);

#ifdef DEBUG
char lbl_8062F9F8[] = "<< Dolphin SDK - AX\tdebug build: Apr  5 2004 03:56:21 (0x2301) >>";
#else
char lbl_8062F9F8[] = "<< Dolphin SDK - AX\trelease build: Apr  5 2004 04:15:05 (0x2301) >>";
#endif

const char* __AXVersion = lbl_8062F9F8;

void AXInit(void) {
    AXInitEx(0);
}

void AXInitEx(u32 outputBufferMode) {
#ifdef DEBUG
    OSReport("Initializing AX\n");
#endif
    OSRegisterVersion(__AXVersion);

    fn_804178C8();
    fn_80419F7C();
    fn_8041949C();
    fn_80417D04();
    fn_8041888C();
    fn_80418CA0(outputBufferMode);
}

void AXQuit(void) {
#ifdef DEBUG
    OSReport("Shutting down AX\n");
#endif
    fn_8041797C();
    fn_8041A180();
    fn_804194C8();
    fn_80417DE8();
    fn_804188B0();
    fn_80419040();
}
