/*
 * Front-end overlay code, .frontend_codeoverlay 0x804CE408-0x804D08D0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_804D0318(FeScrM* x, int a);
extern "C" void fn_804D2118(FeSlot44* p, int a);
extern "C" void fn_804D292C(FeSlot44* p, int a);
extern "C" void fn_804CF52C(FeScrM* x);
extern const char* lbl_80621AF0;
extern "C" void fn_804D2708(FeSlot44* p);
extern "C" char* strcat(char* dst, const char* src);
extern "C" void fn_8033E958(const char* fmt, ...);

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

struct FeGame;

extern "C" void fn_804CE9D0(FeGame* g);

extern FeGame* lbl_80621AB0;

extern "C" FE_OVERLAY void fn_804CEAEC(FeScrM* x)
{
    char buf[16];
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    int id = ((int*)x->m998)[x->m9A0];
    s->fn_8007A700(0, id, x->m9B0);
    s->fn_8007A700(1, id, buf);
    strcat(x->m9B0, " ");
    strcat(x->m9B0, buf);
    fn_8033E958("Now examining: %s\n", x->m9B0);
}

extern "C" FE_OVERLAY void fn_804CEB84(void)
{
    fn_804CE9D0(lbl_80621AB0);
}

/* near-miss: 96.9%. Loop-entry order differs: retail emits li r7 before addi r8 (the row pointer),
 * and addi r8,r8,96 before addi r6,r6,1; variants with the row pointer as a biv or an indexed giv give 91-97%. */
extern "C" FE_OVERLAY int fn_804CEBAC(FeScrM* x, int* out)
{
    int a = x->m9A0;
    if (a != x->m9A4 || x->m9A8 != x->m9AC) {
        x->m9A4 = a;
        x->m9AC = x->m9A8;
        fn_804CEAEC(x);
        *out = 7;
        return 1;
    }
    int i = 0;
    FeRow60* r = x->m3E8;
    while (i < 7) {
        if (r->m4C != x->m97C[i]) {
            *out = i;
            return 1;
        }
        i++;
        r++;
    }
    return 0;
}

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

/* fn_804D21B8 takes an 8-byte pointer-to-member by value (its definition in tu_804D08D0):
   SysV passes it as a pointer to a caller temp at 8(r1), rebuilt for each call. The header
   prototype takes FePair*, so call through the by-value type. */
typedef void (*FeSetPairFn)(FeSlot44*, FePair);
#define FeSetPair(s, v) ((FeSetPairFn)fn_804D21B8)((s), (v))

extern "C" FE_OVERLAY void fn_804CF304(FeScrM* x)
{
    fn_800EB41C((UiS*)x);
    FeSetPair(&x->m188, lbl_805F84B8);
    FeSetPair(&x->m144, lbl_805F84B8);
}

extern "C" FE_OVERLAY void fn_804CF368(FeScrM* x)
{
    fn_800ED254(x);
    FeSetPair(&x->m188, lbl_805F84C0);
    FeSetPair(&x->m144, lbl_805F84C0);
}

extern "C" FE_OVERLAY int fn_804CF3CC(FeScrM* x, int a)
{
    FeVQ* p = (FeVQ*)x;
    if (p->s88()) {
        if (x->m1D4 != 0 && x->m144.m38 == -1) {
            fn_804CF52C(x);
            return 0;
        }
        return p->s84(a)->s50(a);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804CF47C(FeScrM* x, int a)
{
    FeVQ* p = (FeVQ*)x;
    if (p->s88()) {
        if (x->m1D4 != 0 && x->m188.m38 == -1) {
            fn_804CF52C(x);
            return 0;
        }
        return p->s84(a)->s52(a);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804CF52C(FeScrM* x)
{
    if (x->m1D4 != 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
        if (fn_804CF8AC(x) == 0) {
            fn_804D0318(x, 1);
            fn_804D0318(x, 0);
        }
        FeSlot44* a = &x->m188;
        FeSlot44* b = &x->m144;
        int t = b->m38;
        fn_804D292C(b, a->m38);
        fn_804D292C(a, t);
        if (b->m38 == -1) {
            fn_804D2118(a, 1);
            fn_804D2118(b, 0);
        } else {
            fn_804D2118(a, 0);
            fn_804D2118(b, 1);
        }
    }
}

extern "C" FE_OVERLAY void fn_804CF5F8(FeScrM* x)
{
    fn_804D2708(&x->m188);
    fn_804D2708(&x->m144);
    x->fn_vslot85();
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_80621AF0, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
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

extern "C" FE_OVERLAY void fn_804D01A0(FeScrM* x, void* a, int b)
{
    ((FeWV*)fn_804D2310(&x->m188))->s68(a, b);
    ((FeWV*)fn_804D2310(&x->m144))->s68(a, b);
}

extern "C" FE_OVERLAY void fn_804D0220(FeScrM* x, int a)
{
    ((FeWV*)fn_804D2310(&x->m188))->s69(a);
    ((FeWV*)fn_804D2310(&x->m144))->s69(a);
}

extern "C" FE_OVERLAY void fn_804D0294(FeScrM* x, int a)
{
    ((FeWV*)fn_804D2310(&x->m188))->s73(a);
    ((FeWV*)fn_804D2310(&x->m144))->s73(a);
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
