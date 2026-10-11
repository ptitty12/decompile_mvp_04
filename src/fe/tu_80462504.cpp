/*
 * Front-end overlay code, .frontend_codeoverlay 0x80462504-0x80464090 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY int fn_80462504(FeScrD* x, int a)
{
    int r;
    if (x->m134 != 1) {
        r = 0;
    } else {
        x->fn_vslot67(1, a);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8046255C(FeScrD* x, int a)
{
    int r;
    if (x->m134 != 1) {
        r = 0;
    } else {
        x->fn_vslot67(7, a);
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_804626B4(FeScrE* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_80462A7C(FeScrE* x, FeW* w)
{
    if (w == x->m140) {
        x->m2C8 = 0;
        x->m150 = fn_800B548C(((FeSub*)((char*)x->m144 + 0x98))->s5());
        fn_804637FC(x);
    }
}

FE_OVERLAY void fn_80462C3C(FeScrE* x)
{
    if (x->m13C->fn_vslot59() > 0) {
        if (x->m13C->fn_vslot61() != 1) {
            ((FeWV*)x->m13C)->s69(1);
        }
    }
    fn_80463E40(x);
}

FE_OVERLAY int fn_80462CD4(FeScrE* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_80462D30(FeScrE* x)
{
    if (fn_80463CE4(x) == 0) {
        fn_80463044(x);
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80462D74(FeScrE* x)
{
    if (x->m13C != x->m134) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    fn_80463D60(x, x->m134);
    return 0;
}

FE_OVERLAY int fn_80462DC8(void) { return 0; }

FE_OVERLAY int fn_80462DD0(FeScrE* x)
{
    if (x->m13C != x->m138) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    fn_80463D60(x, x->m138);
    return 0;
}

FE_OVERLAY int fn_80462E24(void) { return 0; }

FE_OVERLAY int fn_80462E2C(FeScrE* x)
{
    x->m13C->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_80462E68(FeScrE* x)
{
    x->m13C->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_80462EA4(FeScrE* x)
{
    x->m13C->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_80462EE0(FeScrE* x)
{
    x->m13C->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_80462F1C(FeScrE* x)
{
    if (x->m154 != 0) {
        x->m140->fn_vslot40(1);
    }
    return 1;
}

FE_OVERLAY int fn_80462F68(FeScrE* x, int a)
{
    if (x->m154 != 0) {
        x->m140->fn_vslot41(a);
    }
    return 1;
}

FE_OVERLAY int fn_80462FB0(FeScrE* x)
{
    if (x->m154 != 0) {
        x->m140->fn_vslot38(1);
    }
    return 1;
}

FE_OVERLAY int fn_80462FFC(FeScrE* x)
{
    if (x->m154 != 0) {
        x->m140->fn_vslot39();
    }
    return 1;
}

FE_OVERLAY int fn_804637F4(void) { return 0; }

FE_OVERLAY int fn_80463AC8(FeScrE* x, FeW* w, int b, int c)
{
    if (w == x->m138 || w == x->m134) {
        fn_80463D60(x, w);
        w->fn_vslot67(c, 1);
        int m = x->m2C8;
        if (m == 0 || (m == 1 && x->m13C == x->m138) || (m == 2 && x->m13C == x->m134)) {
            fn_80463044(x);
        }
    }
    return 0;
}

FE_OVERLAY int fn_80463B84(FeScrE* x, FeW* w, int b, int c)
{
    if (w == x->m138 || w == x->m134) {
        fn_80463D60(x, w);
        w->fn_vslot67(c, 1);
        ((FeWV*)x)->s44(fn_800C8070(x));
    }
    return 0;
}

FE_OVERLAY void fn_80463C28(int unused, FeScrE* x)
{
    x->m13C->fn_vslot14(1);
}

FE_OVERLAY int fn_80463C64(FeScrE* x)
{
    int r;
    if (x->m13C == x->m134) {
        r = x->m14C->fn_vslot86() != 0;
    } else if (x->m13C == x->m138) {
        r = x->m14C->fn_vslot87() != 0;
    } else {
        r = 0;
    }
    return r;
}

FE_OVERLAY int fn_80463CE4(FeScrE* x)
{
    int r = 0;
    if (x->m14C->fn_vslot86() != 0 || x->m14C->fn_vslot87() != 0) {
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_80463D60(FeScrE* x, FeW* w)
{
    x->m13C->fn_vslot14(0);
    if (w == x->m134) {
        x->m13C = w;
        x->m14C->fn_vslot84(0, 0);
    } else if (w == x->m138) {
        x->m13C = w;
        x->m14C->fn_vslot84(1, 0);
    }
    x->m13C->fn_vslot14(1);
    fn_80463E40(x);
}

FE_OVERLAY void fn_80463FE0(FeScrE* x, int a)
{
    fn_800ED310(x, a);
    x->m13C->fn_vslot14(a);
}


FE_OVERLAY FeScrF* fn_80464030(FeScrF* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067AB18);
    self->m130 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 1;
    self->m144 = 0;
    return self;
}
}
