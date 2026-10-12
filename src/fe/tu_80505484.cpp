/*
 * Front-end overlay code, .frontend_codeoverlay 0x80505484-0x80508C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" void fn_80505760(FeScrD* x);
extern "C" void fn_80505E40(FeScrD* x);
extern "C" int fn_8050787C(FeScrN* x, int a);
extern "C" int fn_80507A6C(FeScrN* x);
extern "C" int fn_80507C38(FeScrA* x);
extern "C" int fn_80507C80(FeScrA* x);

extern "C" FE_OVERLAY void fn_80505760(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80505E40(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_8050787C(FeScrN* x, int a)
{
    x->m14C->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_80507A6C(FeScrN* x)
{
    x->m14C->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C38(FeScrA* x)
{
    if (x->m138->fn_vslot86() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C80(FeScrA* x)
{
    if (x->m138->fn_vslot87() != 0) {
        return 1;
    }
    return 0;
}
