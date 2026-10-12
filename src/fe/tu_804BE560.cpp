/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BE560-0x804BFB3C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern const char lbl_80670968[];
extern const char lbl_806706C0[];

extern "C" FE_OVERLAY void fn_804BEE04(int a, FeW* w)
{
    if (a == 1) {
        ((FeWV*)w)->s89();
    }
}

extern "C" FE_OVERLAY int fn_804BF0E8(FeScrN* x)
{
    x->m134->fn_vslot52();
    x->fn_vslot87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF148(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF184(FeScrN* x)
{
    x->m134->fn_vslot50();
    x->fn_vslot87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF1E4(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_804BF2EC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80670968);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804BF33C(FeScrN* self)
{
    self->SetVptr(lbl_80670968);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_804BF4AC(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804BF4CC(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF508(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF544(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF580(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF5BC(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_804BF6E8(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}

extern "C" FE_OVERLAY FeScrN* fn_804BF75C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806706C0);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804BF7AC(FeScrN* self)
{
    self->SetVptr(lbl_806706C0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_804BF88C(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804BF8AC(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF8E8(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF924(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF960(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF99C(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_804BFAC8(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}
