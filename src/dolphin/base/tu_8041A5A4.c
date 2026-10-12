/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk), .text 0x8041A5A4-0x8041A6C4.
 * Hand-written original code (exception and debugger stubs, SPR moves): excluded from
 * matching under the no-inline-code rule; stays linked from the split. Placeholder unit.
 * Only fn_8041A694 (a plain call pair around an or) is written in C.
 */
#include <dolphin.h>
#include <dolphin/base/PPCArch.h>

/* fn_8041A5B4 is the HID0 read (PPCMfhid0), fn_8041A5BC the HID0 write (PPCMthid0): hand-written original code. */
u32 fn_8041A5B4(void);
void fn_8041A5BC(u32 newHID0);

void fn_8041A694(void);

void fn_8041A694(void) {
    fn_8041A5BC(fn_8041A5B4() | HID0_SPD);
}
