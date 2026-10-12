/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C19EC-0x804C3ECC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"
extern char lbl_805F556C[];
extern char lbl_805F7F00[];
extern char lbl_805F7F04[];
extern "C" int fn_800A2E6C(FeGlobal80619948* g);
extern "C" int fn_800A2EB4(FeGlobal80619948* g);
extern "C" int fn_805560A8(int a, int b);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, int a);
extern "C" FeW* fn_800C8040(FeW* w);
extern char lbl_805F5AE4[];
extern "C" int fn_800D8500(void);
extern "C" void fn_804C1DB4(FeScrN* x, int a);
extern "C" void fn_804C3818(int a, void* x);
extern "C" void fn_804C389C(int a, void* x);
struct FeVecS {
    int* m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
};
struct FeScrV : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    char pad138[0x14C - 0x138];
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    char pad168[4];
    int m16C;
    int m170;
    int m174;
    int m178;
    int m17C;
    int m180;
    char pad184[4];
    int m188;
    char pad18C[4];
    FeVecS m190;
    int m1A8[446];
};
extern char lbl_8066F8C8[];
extern char lbl_8064B298[];
extern char lbl_8064A550[];
extern char lbl_80666F10[];
extern "C" void fn_8040074C(void* p, int n);
struct FeScrMgr34 {
    char pad0[0x30];
    int* m30;
    int m34;
};
extern "C" int fn_8058F1F0(int a, int b);
extern "C" FeW* fn_800C8060(FeW* w);
extern char lbl_805F4EF4[];
extern char lbl_805F4450[];
extern "C" int fn_80125154(void* w, int a);
extern "C" int fn_80125128(void* w, int a);
extern char lbl_805F7F38[];

extern const char lbl_8066FB70[];
extern const char lbl_80670418[];
extern "C" int fn_804C19EC(FeScrN* x, int a);
extern "C" int fn_804C1A28(FeScrN* x);
extern "C" int fn_804C1A68(FeScrN* x);
extern "C" int fn_804C3920(FeScrN* x);
extern "C" int fn_804C395C(FeScrN* x);
extern "C" int fn_804C3998(FeScrN* x);
extern "C" int fn_804C39D4(FeScrN* x);
extern "C" FeScrN* fn_804C3A10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804C3A60(FeScrN* self);
extern "C" int fn_804C3B4C(FeScrN* x);
extern "C" int fn_804C3B88(FeScrN* x);
extern "C" int fn_804C3BC4(FeScrN* x);
extern "C" int fn_804C3C00(FeScrN* x);
extern "C" int fn_804C3C3C(FeScrN* x);
extern "C" void fn_804C3D68(FeScrN* x, char* dst);
extern "C" FeScrN* fn_804C1AA4(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804C33E4(void* x, int a);

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

extern "C" FE_OVERLAY FeScrN* fn_804C1AA4(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80670418);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804C1AF8(FeScrN* x)
{
    fn_800ECF18(x);
    x->m138 = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    x->m148 = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    fn_80124FA8(x->m138, x);
    if (fn_800B555C()->m0 == 0x14) {
        fn_80125128(x->m138, 3);
        x->m144 = (FeW*)1;
    } else {
        fn_80125154(x->m138, 0);
        x->m144 = 0;
    }
    if (x->m144 == 0) {
        if (fn_800A2E6C(lbl_80619948) != 0) {
            x->m144 = (FeW*)1;
        }
        if (fn_800A2EB4(lbl_80619948) != 0) {
            if (fn_805560A8(fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0), 0) == 2) {
                x->m144 = (FeW*)1;
            }
        }
    }
    fn_801251CC(x->m138, 3, 0x57FD, 1);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F556C, 1));
    x->m134->fn_vslot105(1);
    if (x->m144 != 0) {
        x->fn_vslot32(lbl_805F7F00, 1)->fn_vslot8(0);
        fn_800C8040(x->fn_vslot32(lbl_805F7F04, 1))->fn_vslot29((const char*)0x58B1);
    } else {
        x->fn_vslot32(lbl_805F7F00, 1)->fn_vslot8(1);
        fn_800C8040(x->fn_vslot32(lbl_805F7F04, 1))->fn_vslot29((const char*)0x58B2);
    }
    fn_804C1DB4(x, 0);
}

extern "C" FE_OVERLAY int fn_804C33E4(void* x, int a)
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

extern "C" FE_OVERLAY int fn_804C3444(void* x, int k)
{
    int* t = ((FeScrMgr34*)lbl_8061930C)->m30;
    int m = ((FeScrMgr34*)lbl_8061930C)->m34;
    switch (k) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 0;
        break;
    case 2:
        return fn_8058F1F0(m, 0);
    case 3:
        return fn_8058F1F0(m, 1);
    case 4:
        return fn_8058F1F0(m, 2);
    case 5:
        return fn_8058F1F0(m, 3);
    case 6:
        return fn_8058F1F0(m, 4);
    case 7:
        return fn_8058F1F0(m, 5);
    case 8:
        return t[2];
    case 9:
        return t[4];
    case 10:
        return t[1];
    case 11:
        return t[3];
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C3550(FeScrN* x, int k)
{
    FeMsg m;
    FeMsg* p;
    switch (k) {
    case 0: {
        FeMsg* q = &m;
        fn_8035682C(q);
        fn_8040B830(q->name, lbl_805F4450, 15);
        q->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), q, x);
        break;
    }
    case 1:
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        fn_804C1DB4(x, 1);
        fn_801251CC(x->m138, 3, 0x37F2, 2);
        break;
    case 2:
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        fn_804C1DB4(x, 0);
        fn_801251CC(x->m138, 3, 0x57FD, 1);
        break;
    case 3: {
        p = &m;
        fn_8035682C(p);
        int r = fn_800D8500();
        if (r == 1) {
            fn_8040B830(p->name, lbl_805F5AE4, 15);
            p->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), p, x);
        } else if (r == 2) {
            fn_80131F34(x->m148, x, fn_804C3818, 0, 0x5CFA, 1, -1, 1, 0x63C, 0, 0, 0, 0, 0);
            x->m148->fn_vslot86();
        } else if (r == 3) {
            fn_80131F34(x->m148, x, fn_804C389C, 0, 0x5CFB, 1, -1, 1, 0x63C, 0, 0, 0, 0, 0);
            x->m148->fn_vslot86();
        } else if (r == 4) {
            fn_80131F34(x->m148, x, fn_804C3818, 0, 0x5CFC, 1, -1, 1, 0x63C, 0, 0, 0, 0, 0);
            x->m148->fn_vslot86();
        } else {
            fn_8040B830(p->name, lbl_805F3CA8, 15);
            p->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), p, x);
        }
        break;
    }
    }
}

extern "C" FE_OVERLAY void fn_804C3818(int a, void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F7F38, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

extern "C" FE_OVERLAY void fn_804C389C(int a, void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F3CA8, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
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

extern "C" FE_OVERLAY void fn_804C3A90(FeScrN* x)
{
    fn_800ECF18(x);
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125154(p, 0);
    fn_80125128(p, 1);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    fn_800B555C()->m38 = 0;
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

extern "C" FE_OVERLAY void fn_804C3C7C(FeScrN* x, int k)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    case 1:
        ((FeWV*)x)->s79(p);
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    }
}

extern "C" FE_OVERLAY void fn_804C3D68(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}

extern "C" FE_OVERLAY FeScrV* fn_804C3DDC(FeScrV* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeVecS* sub = &self->m190;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F8C8);
    self->m130 = 0;
    self->m134 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m188 = 0;
    sub->m10 = lbl_8064B298;
    self->m190.m0 = self->m1A8;
    sub->m8 = 0x1BE;
    fn_8040074C(self->m190.m0, 0x6F8);
    sub->m4 = 0;
    sub->mC = 0;
    sub->m10 = lbl_8064A550;
    fn_8040074C(self->m190.m0, sub->m8 * 4);
    sub->m10 = lbl_80666F10;
    sub->m4 = 0;
    sub->mC = 0;
    sub->m14 = 0;
    return self;
}
