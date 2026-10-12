/*
 * Front-end overlay code, .frontend_codeoverlay 0x80519600-0x8051E878 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"
extern "C" void fn_800B7ADC(FeMsgMgr* m, void* x);
extern "C" void fn_80125268(int a, int b, int c, int d);
extern "C" void fn_8051E41C(void* x);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned i);
extern "C" void fn_8007F784__FP13Unk8007F198_BUiii(void* g, unsigned i, int a, int b);
extern "C" unsigned fn_8007F84C__FP13Unk8007F198_B(void* g);
extern "C" void fn_800EC624__FP13Unk800EC624_Tiii(void* x, void* w, int a, int b);
extern "C" void* fn_804DC128(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804D29F0(int a, int b, void* c);
extern const char lbl_80668BB8[];

extern const char lbl_806691F0[];
extern "C" void fn_8051C374(void* x, int a, int b);
extern "C" int fn_80084114__Fi(int a);
extern "C" int fn_805399BC(int a);
extern int lbl_805F5A2C;
extern "C" FeScrN* fn_80519600(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_8051D9F8(FeScrN* x);
extern "C" int fn_8051DA44(FeScrN* x);
extern "C" int fn_8051DA90(FeScrN* x);
extern "C" int fn_8051DADC(FeScrN* x);
extern "C" int fn_8051DB28(FeScrN* x);
extern "C" int fn_8051DB64(FeScrN* x);
extern "C" int fn_8051DBA0(FeScrN* x);
extern "C" int fn_8051DBDC(FeScrN* x);
extern "C" int fn_8051DC18(FeScrN* x);
extern "C" int fn_8051DCCC(FeScrN* x);
extern "C" int fn_8051DD28(FeScrN* x);
extern "C" int fn_8051DD80(FeScrN* x);
extern "C" int fn_8051DE1C(FeScrN* x);
extern "C" int fn_8051DE6C(FeScrN* x);
extern "C" int fn_8051DC74(FeScrN* x, int a);
extern "C" int fn_8051DDD0(FeScrN* x, int a);
extern "C" int fn_8051A4EC(void* x, int b, int c);
extern "C" void fn_8051C31C(void* x, int a);
extern "C" void fn_8051A1C4(int unused, int* dst, int k);
extern "C" int fn_8051E198(int k);
extern "C" int fn_8051E25C(int n);
extern "C" int fn_8051E29C(int n);

extern "C" FE_OVERLAY FeScrN* fn_80519600(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806691F0);
    FeI(self, 0x130) = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 1;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    FeI(self, 0x16C) = 0;
    FeI(self, 0x170) = 0;
    FeI(self, 0x174) = 0;
    FeI(self, 0x380) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8051A1C4(int unused, int* dst, int k)
{
    if (k == 0) {
        *dst = lbl_805F5A2C;
    } else {
        ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B924(2, k, (char*)dst);
    }
}

extern "C" FE_OVERLAY int fn_8051A4EC(void* x, int b, int c)
{
    return fn_8051E198(c) == b;
}

extern "C" FE_OVERLAY void fn_8051C31C(void* x, int a)
{
    fn_8051C374(x, FeP(x, 0x160)->fn_vslot61(), a);
}

extern "C" FE_OVERLAY int fn_8051D9F8(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DA44(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DA90(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DADC(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DB28(FeScrN* x)
{
    x->m160->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DB64(FeScrN* x)
{
    x->m160->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DBA0(FeScrN* x)
{
    x->m160->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DBDC(FeScrN* x)
{
    x->m160->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DC18(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DC74(FeScrN* x, int a)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot41(a);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DCCC(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DD28(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot39();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DD80(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DDD0(FeScrN* x, int a)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot41(a);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DE1C(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DE6C(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot39();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DFE0(FeW* x, FeW* w, int b, int d)
{
    if (w == FeP(x, 0x160)) {
        w->fn_vslot68(d);
        x->fn_vslot67(2, fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8051E198(int k)
{
    switch (k) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    default:
        return 0;
    }
}

extern "C" FE_OVERLAY int fn_8051E25C(int n)
{
    if (n > 12) {
        return fn_80084114__Fi(fn_8051E198(n));
    }
    if (n >= 10) {
        return 0;
    }
    return fn_80084114__Fi(fn_8051E198(n));
}

enum FeE29 { FeE29_Neg = -1, FeE29_10 = 10, FeE29_12 = 12 };
extern "C" FE_OVERLAY int fn_8051E29C(int n)
{
    switch ((FeE29)n) {
    case 10:
        return 0x2000003F;
    case 11:
        return 0x24000000;
    case 12:
        return 0x28000000;
    default:
        return fn_805399BC(fn_8051E198(n)) | 0x20000000;
    }
}

extern "C" FE_OVERLAY void fn_8051E304(void* x, int k)
{
    switch (k) {
    case 0:
        if (lbl_8061A32C == 0) {
            lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
        }
        fn_800B7ADC(lbl_8061A32C, x);
        break;
    case 1:
        if (FeI(x, 0x168) > 0) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
        }
        fn_8051C31C(x, 0);
        break;
    case 3:
        if (FeI(x, 0x134) == 2) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            if (FeI(x, 0x14C) == 0) {
                FeI(x, 0x14C) = 1;
            } else {
                FeI(x, 0x14C) = 0;
            }
            if (FeI(x, 0x16C) == 0) {
                fn_80125268(FeI(x, 0x164), 2, (&FeI(x, 0x218))[FeI(x, 0x14C)], 3);
            }
            fn_8051C31C(x, 0);
        }
        break;
    case 2:
        fn_8051E41C(x);
        break;
    }
}

extern "C" FE_OVERLAY FeScrN* fn_8051E714(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668BB8);
    fn_804DC128((char*)self + 0x2DC, a, b, c, d, e, f, g, h);
    fn_804DC128((char*)self + 0x440, a, b, c, d, e, f, g, h);
    FeI(self, 0x5A4) = 0;
    FeI(self, 0x5A8) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8051E7D0(void* x, int a, int b)
{
    if (FeI(x, 0x5A4) == 0) {
        FeI(x, 0x5A4) = 1;
        char* p = (char*)x + 0x2DC;
        FeI(x, 0x5A8) = 1;
        char* q = (char*)x + 0x440;
        fn_800EC624__FP13Unk800EC624_Tiii(p, x, 0, fn_800B548C(0));
        fn_800EC624__FP13Unk800EC624_Tiii(q, x, 1, fn_800B548C(0));
        fn_804D29F0(a, 0, p);
        fn_804D29F0(b, 0, q);
    }
}
