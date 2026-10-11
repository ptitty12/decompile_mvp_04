/*
 * Front-end overlay code, .frontend_codeoverlay 0x804CE408-0x804D08D0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_80330BC8(void* x);
extern "C" int fn_804CEBAC(FeScrM* x, int* out);
extern "C" void fn_804CE7F0(FeScrM* x, int v);
extern const char lbl_8067F728[];
extern const FePair lbl_805F84B8;
extern const FePair lbl_805F84C0;
extern "C" void fn_804CEC64(FeScrM* x);
extern "C" void fn_804CEEF0(FeScrM* x);
extern "C" int fn_804CF884(FeScrM* x, int a);
extern "C" void fn_804CF908(FeScrM* x, int a);
extern "C" FeSlot44* fn_804CF92C(FeScrM* x, int a);
extern "C" int fn_804D0308(void);
extern "C" int fn_804D0310(void);
extern "C" int fn_804D0510(FeScrM* x, int a);
extern "C" FeScrM* fn_804CEF34(FeScrM* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CF304(FeScrM* x);
extern "C" void fn_804CF368(FeScrM* x);
extern "C" void fn_804CF7B4(FeScrM* x);
extern "C" void fn_804CF81C(FeScrM* x);
extern "C" int fn_804CF8AC(FeScrM* x);
extern "C" int fn_804D0860(FeScrM* x, int a);

extern "C" FE_OVERLAY void fn_804CEC64(FeScrM* x)
{
    int sp8;
    fn_80330BC8(x);
    if (fn_804CEBAC(x, &sp8) != 0) {
        fn_804CE7F0(x, sp8);
    }
}

extern "C" FE_OVERLAY void fn_804CEEF0(FeScrM* x)
{
    if (x->m998 != 0) {
        fn_80377488(x->m998);
        x->m998 = 0;
        x->m99C = 0;
    }
}

extern "C" FE_OVERLAY FeScrM* fn_804CEF34(FeScrM* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EB2F4((UiScrRaw*)self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067F728);
    fn_804D1FD4(&self->m144);
    fn_804D1FD4(&self->m188);
    self->m1CC = 0;
    self->m1D0 = 0;
    self->m1D4 = 0;
    return self;
}

/* near-miss: retail recomputes `addi r4,r1,8` before each call; we keep &p in a callee-saved
 * register (open: locals at a nonzero frame offset, see PATTERNS). */
extern "C" FE_OVERLAY void fn_804CF304(FeScrM* x)
{
    fn_800EB41C((UiS*)x);
    FePair p = lbl_805F84B8;
    fn_804D21B8(&x->m188, &p);
    p = lbl_805F84B8;
    fn_804D21B8(&x->m144, &p);
}

/* near-miss: same as fn_804CF304. */
extern "C" FE_OVERLAY void fn_804CF368(FeScrM* x)
{
    fn_800ED254(x);
    FePair p = lbl_805F84C0;
    fn_804D21B8(&x->m188, &p);
    p = lbl_805F84C0;
    fn_804D21B8(&x->m144, &p);
}

extern "C" FE_OVERLAY void fn_804CF7B4(FeScrM* x)
{
    fn_804D2310(&x->m188)->fn_vslot71();
    fn_804D2310(&x->m144)->fn_vslot71();
}

extern "C" FE_OVERLAY void fn_804CF81C(FeScrM* x)
{
    fn_804D2310(&x->m188)->fn_vslot72();
    fn_804D2310(&x->m144)->fn_vslot72();
}

extern "C" FE_OVERLAY int fn_804CF884(FeScrM* x, int a)
{
    if (a == x->m188.m38 || a == x->m144.m38) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804CF8AC(FeScrM* x)
{
    if (x->m1D4 != 0) {
        FeLink10* p = lbl_806192E0->m4->m10;
        int u = p->m6C;
        int w = p->m70;
        if ((u == -1 && x->m188.m38 != -1) || (w == -1 && x->m144.m38 != -1)) {
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804CF908(FeScrM* x, int a)
{
    fn_804D2310(fn_804CF92C(x, a));
}

extern "C" FE_OVERLAY FeSlot44* fn_804CF92C(FeScrM* x, int a)
{
    FeSlot44* p = &x->m188;
    if (p->m38 == a) {
        return p;
    }
    return &x->m144;
}

extern "C" FE_OVERLAY int fn_804D0308(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804D0310(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804D0510(FeScrM* x, int a)
{
    if (a == 1) {
        FeW* p = x->m1CC;
        if (p != 0) {
            return p->b0;
        }
    } else if (a == 0) {
        FeW* p = x->m1D0;
        if (p != 0) {
            return p->b0;
        }
    }
    return 0;
}

/* near-miss: retail shares the vcall tail between the slot 86/87 arms (the arm only picks
 * lha/lwz, then `b` to the common `add; mtlr; blrl; cmpwi`), like a call through a selected
 * function pointer; every if/else, ternary and member-pointer spelling tried (8) keeps two
 * full call sequences. */
extern "C" FE_OVERLAY int fn_804D0860(FeScrM* x, int a)
{
    FeW* w = x->m138;
    if (w != 0) {
        int r;
        if (a == 1) {
            r = w->fn_vslot86();
        } else {
            r = w->fn_vslot87();
        }
        if (r == 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}
