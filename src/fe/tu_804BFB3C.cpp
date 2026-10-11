/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BFB3C-0x804C19EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_804C1100(void* x);
extern "C" void fn_804C13F8(FeScrD* x);

extern "C" FE_OVERLAY void fn_804BFD98(FeObjP* x)
{
    x->m24->fn_vslot8(0);
    fn_80444890(x);
}

extern "C" FE_OVERLAY void* fn_804C0620(char* p, int i, int j)
{
    return p + (i * 0x118 + 0x168) + j * 0x28;
}

extern "C" FE_OVERLAY void fn_804C0BD8(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804C10D4(int a, void* x)
{
    if (a == 1) {
        fn_804C1100(x);
    }
}

extern "C" FE_OVERLAY void fn_804C1484(FeScrD* x)
{
    fn_804C13F8(x);
}

extern "C" FE_OVERLAY int fn_804C1640(FeScrN* x)
{
    x->m14C->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1778(FeScrN* x)
{
    x->m14C->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C19AC(FeScrN* x)
{
    x->m144->fn_vslot40(1);
    return 1;
}
