/*
 * Front-end overlay code, .frontend_codeoverlay 0x804CB430-0x804CE408 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

struct FeAttr {
    float m0;
    char pad4[4];
    int m8;
};
struct FeCntC {
    char pad0[0xC];
    int mC;
};
struct FeStat14 {
    char pad0[0x14];
    FeCntC* m14;
    FeCntC* m18;
    FeCntC* m1C;
};
extern "C" FeAttr* fn_805932E4(void* o, int t, int i, int a);
extern "C" float fn_80593370(void* o, int a);

struct FeCnt5 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
extern "C" int fn_8058F1F0(void* o, int n);

extern "C" void fn_804CB51C(FeScrN* x, int a);
extern "C" FeW* fn_800C8060(FeW* w);
extern const char lbl_805F4450[];

struct FeCnt {
    int m0;
    int m4;
};
extern int lbl_806219E8[];
extern int lbl_80621998[][2];
extern int lbl_80621970[];
extern int lbl_80621A88[];
extern int lbl_80621A38[][2];
extern int lbl_80621A10[];

extern const char lbl_80670EF0[];
extern const char lbl_80672168[];
extern "C" void fn_804CD878(FeScrE0C* x);
extern const char lbl_8066EB80[];
extern "C" int fn_804CD194(FeScrN* x);
extern "C" int fn_804CD1D0(FeScrN* x);
extern "C" int fn_804CD20C(FeScrN* x);
extern "C" int fn_804CD248(FeScrN* x);
extern "C" void fn_804CD2FC(FeScrE0C* x);
extern "C" int fn_804CD754(FeScrE0C* x);
extern "C" int fn_804CD794(FeScrE0C* x);
extern "C" int fn_804CD7D0(FeScrE0C* x);
extern "C" int fn_804CD810(FeScrE0C* x, int a);
extern "C" void fn_804CD84C(FeScrE0C* x, int a);
extern "C" FeScrH* fn_804CDE24(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CDE70(FeScrN* x);
extern "C" void fn_804CDE90(FeScrH* x);
extern "C" void fn_804CDF04(FeScrN* x);
extern "C" void fn_804CDF24(FeScrN* x);
extern "C" int fn_804CDF50(FeScrB* x);
extern "C" int fn_804CDFAC(void);
extern "C" void fn_804CDFB4(int a, char* dst);
extern "C" void fn_804CDFE4(FePair* p);
extern "C" void fn_804CDFF8(FePair* p, int a, int b);
extern "C" int fn_804CE0C8(int k);
extern "C" void fn_804CE004(FePair* p);
extern "C" int fn_804CCF20(void* x, int a);
extern "C" void fn_804CD530(FeScrE0C* x);

extern "C" FE_OVERLAY void fn_804CB430(FeScrN* x)
{
    fn_800ECF18(x);
    x->m138 = fn_800B7AB8(FeGetMgr(), "NAVBAR");
    fn_80124FA8(x->m138, x);
    fn_801251CC(x->m138, 1, 0x1A0C, 0);
    fn_801251CC(x->m138, 3, 0x57FD, 1);
    x->m134 = fn_800C8060(x->fn_vslot32("GRID", 1));
    x->m134->fn_vslot105(1);
    fn_804CB51C(x, 0);
}

extern "C" FE_OVERLAY int fn_804CCF20(void* x, int a)
{
    FeStats* s = (FeStats*)((Unk8007B2B0_Screen*)lbl_8061930C)->m30;
    switch (a) {
    case 0:
        return s->m14;
    case 1:
        return s->m18;
    case 2:
        return s->m1C;
    case 3:
        return s->m20;
    default:
        return 0;
    }
}

extern "C" FE_OVERLAY void fn_804CCF80(FeScrN* x, int sel)
{
    switch (sel) {
    case 0: {
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
    case 1:
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        fn_804CB51C(x, 1);
        fn_801251CC(x->m138, 3, 0x37F2, 2);
        break;
    case 2:
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        fn_804CB51C(x, 0);
        fn_801251CC(x->m138, 3, 0x57FD, 1);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804CD088(void* x, int k)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    FeCnt5* c = (FeCnt5*)s->m30;
    void* o = *(void**)((char*)s + 0x34);
    switch (k) {
    case 0:
        return 0;
    case 1:
        return 0;
    case 2:
        return fn_8058F1F0(o, 0);
    case 3:
        return fn_8058F1F0(o, 1);
    case 4:
        return fn_8058F1F0(o, 2);
    case 5:
        return fn_8058F1F0(o, 3);
    case 6:
        return fn_8058F1F0(o, 4);
    case 7:
        return fn_8058F1F0(o, 5);
    case 8:
        return c->m8;
    case 9:
        return c->m10;
    case 10:
        return c->m4;
    case 11:
        return c->mC;
    default:
        return 0;
    }
}

extern "C" FE_OVERLAY int fn_804CD194(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD1D0(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD20C(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD248(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804CD2FC(FeScrE0C* x)
{
    x->SetVptr(lbl_80670EF0);
    x->mE04 = lbl_80672168;
    fn_8035686C(x);
}

extern "C" FE_OVERLAY void fn_804CD530(FeScrE0C* x)
{
    if (x->m164 != 0) {
        if (x->m13C != 0) {
            fn_801251CC(x->mE14, 3, 0x5CC7, 1);
            return;
        }
        fn_801251CC(x->mE14, 3, 0x5CC6, 1);
    }
}

extern "C" FE_OVERLAY void fn_804CD590(FeScrE0C* x)
{
    ((FeSub*)((char*)x->mE10 + 0xDC))->s15();
    ((FeVQ*)x->mE10)->s51(0x58B9, 0);
    ((FeVQ*)x->mE10)->s51(0x57FF, 1);
    ((FeVQ*)x->mE10)->s51(0x5801, 2);
    ((FeVQ*)x->mE10)->s51(0x5803, 3);
    ((FeSub*)((char*)x->mE10 + 0xDC))->s6(0);
}

extern "C" FE_OVERLAY void fn_804CD68C(FeScrE0C* x, int sel)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (sel) {
    case 0:
        fn_8040B830(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1:
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        *(int*)&x->m13C ^= 1;
        if (x->m164 != 0)
            fn_804CD878(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804CD754(FeScrE0C* x)
{
    x->mE0C->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD794(FeScrE0C* x)
{
    x->mE0C->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD7D0(FeScrE0C* x)
{
    x->mE0C->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD810(FeScrE0C* x, int a)
{
    x->mE0C->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY void fn_804CD84C(FeScrE0C* x, int a)
{
    if (a == (int)x->mE0C) {
        fn_804CD878(x);
    }
}

extern "C" FE_OVERLAY float fn_804CDCE8(FeScrN* x, int a, int sel)
{
    float sum = 0.0f;
    FeStat14* st = (FeStat14*)((Unk8007B2B0_Screen*)lbl_8061930C)->m30;
    int t;
    int n;
    switch (sel) {
    case 0:
        return fn_80593370(x->m140, a);
    case 1:
        t = 0;
        n = st->m14->mC;
        break;
    case 2:
        t = 2;
        n = st->m1C->mC;
        break;
    case 3:
        t = 1;
        n = st->m18->mC;
        break;
    default:
        return 0.0f;
    }
    int i = 0;
    while (i < n) {
        FeAttr* p = fn_805932E4(x->m140, t, i, a);
        sum = sum + (float)p->m8 * fn_805932E4(x->m140, t, i++, a)->m0;
    }
    return sum;
}

extern "C" FE_OVERLAY FeScrH* fn_804CDE24(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066EB80);
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CDE70(FeScrN* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804CDE90(FeScrH* x)
{
    fn_800ECF18(x);
    void* w = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    fn_801250D8(w);
}

extern "C" FE_OVERLAY void fn_804CDF04(FeScrN* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804CDF24(FeScrN* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_804CDF44(void) {}

extern "C" FE_OVERLAY void fn_804CDF48(void) {}

extern "C" FE_OVERLAY void fn_804CDF4C(void) {}

extern "C" FE_OVERLAY int fn_804CDF50(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CDFAC(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804CDFB4(int a, char* dst)
{
    fn_8040B830(dst, lbl_805F3CA8, 16);
}

extern "C" FE_OVERLAY void fn_804CDFE4(FePair* p)
{
    p->a = 0x23;
    p->b = 0;
}

extern "C" FE_OVERLAY void fn_804CDFF8(FePair* p, int a, int b)
{
    p->b = b;
    p->a = a;
}

extern "C" FE_OVERLAY void fn_804CE004(FePair* p)
{
    ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(p->a, p->b);
}

extern "C" FE_OVERLAY int fn_804CE038(FeCnt* p)
{
    switch (p->m0) {
    case 0:
        p->m0 = 1;
        break;
    case 1:
        p->m0 = 2;
        break;
    case 2:
        p->m0 = 3;
        break;
    case 3:
        return 0;
    }
    return ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(p->m0, p->m4);
}

extern "C" FE_OVERLAY int fn_804CE0C8(int k)
{
    switch (k) {
    case 0:
        return 0x4637;
    case 2:
        return 0x4635;
    case 4:
        return 0x4636;
    default:
        return 0x4637;
    }
}

extern "C" FE_OVERLAY int fn_804CE10C(int k, int i, int j)
{
    if (i > 9)
        i = 0;
    if (k == 0)
        return lbl_806219E8[i];
    if (k == 1) {
        if (j > 1)
            j = 1;
        return lbl_80621998[i][j];
    }
    if (k == 2)
        return lbl_80621970[i];
    return 0x37B6;
}

extern "C" FE_OVERLAY int fn_804CE188(int k, int i, int j)
{
    if (i > 9)
        i = 0;
    if (k == 0)
        return lbl_80621A88[i];
    if (k == 1) {
        if (j > 1)
            j = 1;
        return lbl_80621A38[i][j];
    }
    if (k == 2)
        return lbl_80621A10[i];
    return 0x37B6;
}

extern "C" FE_OVERLAY int fn_804CE204(int k)
{
    int r = 0;
    switch (k) {
    case 0:
    case 1:
        r = 0;
        break;
    case 2:
        r = 12;
        break;
    case 3:
        r = 13;
        break;
    case 4:
        r = 14;
        break;
    case 5:
        r = 15;
        break;
    case 6:
        r = 16;
        break;
    case 7:
        r = 17;
        break;
    case 8:
        r = 18;
        break;
    case 9:
        r = 19;
        break;
    }
    return r;
}
