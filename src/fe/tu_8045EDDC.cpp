/*
 * Front-end overlay code, .frontend_codeoverlay 0x8045EDDC-0x80462504 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY int fn_8045EDDC(FeScrD* x)
{
    if (x->m14C != x->m144) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    fn_804613EC(x, x->m144);
    return 0;
}

FE_OVERLAY int fn_8045EE30(void) { return 0; }

FE_OVERLAY int fn_8045EE38(FeScrD* x)
{
    if (x->m14C != x->m148) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    fn_804613EC(x, x->m148);
    return 0;
}

FE_OVERLAY int fn_8045EE8C(void) { return 0; }

FE_OVERLAY int fn_8045EE94(FeScrD* x)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot40(1);
    } else {
        w->fn_vslot40(1);
    }
    return 0;
}

FE_OVERLAY int fn_8045EF14(FeScrD* x, int a)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot41(a);
    } else {
        w->fn_vslot41(a);
    }
    return 0;
}

FE_OVERLAY int fn_8045EF8C(FeScrD* x)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot38(1);
    } else {
        w->fn_vslot38(1);
    }
    return 0;
}

FE_OVERLAY int fn_8045F00C(FeScrD* x)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot39();
    } else {
        w->fn_vslot39();
    }
    return 0;
}

FE_OVERLAY int fn_8045F084(FeScrD* x)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot40(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F0D8(FeScrD* x, int a)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot41(a);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F128(FeScrD* x)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot38(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F17C(FeScrD* x)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot39();
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_8045F374(FeScrD* x)
{
    fn_80460750(x);
}

FE_OVERLAY void fn_8045F734(FeScrD* x, FeScrD* y)
{
    if (x != 0) {
        fn_8045FBF8(y);
    }
}

FE_OVERLAY void fn_8045FAB8(int a, FeScrD* x)
{
    if (a == 1) {
        int idx = x->m144->fn_vslot60();
        fn_80461228(x, fn_80461218(x, idx));
    }
}

FE_OVERLAY void fn_8045FCAC(void) {}

FE_OVERLAY void fn_8045FCB0(FeScrD* x, int a)
{
    fn_800ED310(x, a);
    x->m14C->fn_vslot14(a);
}

FE_OVERLAY void fn_80460714(FeScrD* x)
{
    x->m160->fn_vslot8(0);
}

FE_OVERLAY int fn_80461218(FeScrD* x, int i)
{
    return x->m3468[i];
}

FE_OVERLAY int fn_804615C4(FeScrD* x)
{
    return (unsigned)(x->m134 - 2) <= 2;
}

}
