/*
 * Front-end overlay code, .frontend_codeoverlay 0x8051E878-0x80520BE0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern "C" void fn_8052007C(FeScrD* x);
extern "C" void fn_8052005C(FeScrD* x);
extern "C" void fn_8051F6A4(void* x);
extern "C" void fn_8051F748(void* x);

extern "C" FE_OVERLAY void fn_8051F6A4(void* x)
{
    FeSubOf(x)->s5();
}

extern "C" FE_OVERLAY void fn_8051F748(void* x)
{
    FeSubOf(x)->s11();
}

extern "C" FE_OVERLAY void fn_8051FF84(void) {}

extern "C" FE_OVERLAY void fn_8052005C(FeScrD* x)
{
    fn_8052007C(x);
}
