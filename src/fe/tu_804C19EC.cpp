/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C19EC-0x804C3ECC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern const char lbl_8066FB70[];

extern "C" FE_OVERLAY int fn_804C19EC(FeScrN* x, int a)
{
    x->m144->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1A28(FeScrN* x)
{
    x->m144->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1A68(FeScrN* x)
{
    x->m144->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C3920(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C395C(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C3998(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C39D4(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_804C3A10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066FB70);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804C3A60(FeScrN* self)
{
    self->SetVptr(lbl_8066FB70);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_804C3B4C(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C3B88(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C3BC4(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C3C00(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C3C3C(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_804C3D68(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}
