/*
 * Front-end overlay code, .frontend_codeoverlay 0x80520BE0-0x805283C4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern const char lbl_80667638[];
extern const char lbl_80667650[];
extern const char lbl_80669498[];
extern const char lbl_806694B0[];
extern const char lbl_80669780[];
extern const char lbl_80669CF8[];
extern const char lbl_80669FA0[];
extern const char lbl_8067A190[];
extern "C" void fn_80523A90(void* x, int a);
extern "C" void fn_80524B54(void* x);
extern "C" void fn_804D34A0(void* x);
extern "C" void fn_8040B61C(void* p);
extern "C" void fn_80524408(void* x, int a);
extern "C" void fn_800EC208__FP3UiS(void* x);
extern "C" void fn_8007FE04__FP13Unk8007F198_D(void* p);
extern "C" void fn_80087B10__Fv();
extern "C" void fn_800C5E28();
extern "C" void fn_800C618C();
extern "C" void fn_80134E38(void* p, int c);
extern const char lbl_8062265C[];
extern const char lbl_806226D4[];
extern "C" FeSingle* fn_805210A0(void);
extern "C" void fn_805210EC(void);
extern "C" int fn_80522890(FeSingle* x, unsigned i);
extern "C" void fn_805228DC(FeSingle* x);
extern "C" void fn_80522A74(FeScrD* x);
extern "C" int fn_8052388C(void* x, int a);
extern "C" int fn_805238EC(void* x, int a);
extern "C" int fn_8052390C(void* x, int a);
extern "C" int fn_80523960(void* x, int a);
extern "C" int fn_805239B4(void* x, int a);
extern "C" int fn_80523A08(void* x, int a);
extern "C" int fn_80523A5C(void* x, int a, int b, int c, int d);
extern "C" void fn_805243C4(void* x);
extern "C" FeScrN* fn_805244C8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_805246C4(FeScrG* x);
extern "C" FeScrN* fn_80524708(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80524850(void);
extern "C" void fn_80524BE8(void* x);
extern "C" FeScrN* fn_80524C1C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80524C94(void* x);
extern "C" void fn_805255F8(void);
extern "C" FeScrH* fn_80525624(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80520C0C(FeV10B* x);
extern "C" void fn_80520C60(FeV10B* x);

extern "C" FE_OVERLAY void fn_80520C0C(FeV10B* x)
{
    int v = fn_8051E910(x->m4, lbl_80622648);
    x->s3(v);
}

extern "C" FE_OVERLAY void fn_80520C60(FeV10B* x)
{
    fn_8051EDDC(x->m4, lbl_80622648, x->s2());
}

extern "C" FE_OVERLAY FeSingle* fn_805210A0(void)
{
    if (lbl_8062264C == 0) {
        lbl_8062264C = new (0) FeSingle;
    }
    return lbl_8062264C;
}

/* near-miss: delete through the virtual dtor loads the pfn before the delta (lwz/lha swapped) */
extern "C" FE_OVERLAY void fn_805210EC(void)
{
    if (lbl_8062264C != 0) {
        delete (FeSingleV*)lbl_8062264C;
        lbl_8062264C = 0;
    }
}

//@80521144
FE_OVERLAY FeSingle::FeSingle()
{
    mB8 = lbl_8067A190;
    mA8 = 0;
    mAC = 0;
    mB0 = 0;
    mB4 = 0;
    for (int i = 0; i < 42; i++) {
        m0[i] = 0;
    }
}

extern "C" FE_OVERLAY int fn_80522890(FeSingle* x, unsigned i)
{
    if (i <= 0x29) {
        return x->m0[i];
    }
    if (i == 0x50) {
        return x->mAC;
    }
    if (i == 0x51) {
        return x->mB0;
    }
    if (i == 0x53) {
        return x->mB4;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_805228DC(FeSingle* x)
{
    for (int i = 0; i < 42; i++) {
        x->m0[i] = 0;
    }
    x->mA8 = 0;
    x->mAC = 0;
}

extern "C" FE_OVERLAY void fn_80522A74(FeScrD* x)
{
    fn_800ECF18(x);
}

extern "C" FE_OVERLAY int fn_8052388C(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        fn_80523A90(x, FeP(x, 0x2DC)->fn_vslot61());
        r = 1;
    }
    return r;
}

/* near-miss: retail loads r3 = 0 first and returns with bnelr (9 spellings tried) */
extern "C" FE_OVERLAY int fn_805238EC(void* x, int a)
{
    int v = FeI(x, 0x2E4);
    if (v != -1 && a == v) {
        return 1;
    }
    return 0;
}

/* near-miss (family fn_8052390C..fn_80523A08): retail tests the call result with cmpwi r3,0, ours emits mr. */
extern "C" FE_OVERLAY int fn_8052390C(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot54();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80523960(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot55();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_805239B4(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot56();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80523A08(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot57();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80523A5C(void* x, int a, int b, int c, int d)
{
    if (a == FeI(x, 0x2DC)) {
        fn_80523A90(x, d);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_805243C4(void* x)
{
    if (FeI(x, 0x308) > 1) {
        fn_80524408(x, 0);
    }
    fn_800EC208__FP3UiS(x);
}

/* near-miss: ours keeps 0x3364 in a callee-saved register (one more register saved than retail) */
extern "C" FE_OVERLAY FeScrN* fn_805244C8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x1E, lbl_8062265C);
    self->SetVptr(lbl_80669780);
    FeI(self, 0x178) = 0;
    FeI(self, 0x174) = 0;
    fn_80134E38((char*)self + 0x17C, 0);
    FeI(self, 0x1C4) = (int)lbl_80669498;
    self->SetVptr(lbl_806694B0);
    return self;
}

extern "C" FE_OVERLAY void fn_805246C4(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

extern "C" FE_OVERLAY FeScrN* fn_80524708(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x2E, lbl_806226D4);
    self->SetVptr(lbl_80669780);
    FeI(self, 0x178) = 0;
    FeI(self, 0x174) = 0;
    fn_80134E38((char*)self + 0x17C, 0);
    FeI(self, 0x1C4) = (int)lbl_80667638;
    self->SetVptr(lbl_80667650);
    return self;
}

extern "C" FE_OVERLAY void fn_80524850(void)
{
    fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C);
    fn_80087B10__Fv();
}

extern "C" FE_OVERLAY void fn_80524BE8(void* x)
{
    fn_804D34A0(x);
    fn_80524B54(x);
}

extern "C" FE_OVERLAY FeScrN* fn_80524C1C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669FA0);
    FeI(self, 0x130) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80524C94(void* x)
{
    fn_8040B61C((char*)x + 0x134);
    FeI(x, 0x148) = 1;
}

extern "C" FE_OVERLAY void fn_805255F8(void)
{
    fn_800C5E28();
    fn_800C618C();
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY FeScrH* fn_80525624(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669CF8);
    self->m130 = 0;
    return self;
}
