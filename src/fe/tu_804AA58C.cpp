/*
 * Front-end overlay code, .frontend_codeoverlay 0x804AA58C-0x804ABCBC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" void fn_804AB224(void* x);
extern "C" int fn_800E4874(void* p);
struct FeArrL { char* m0; int m4; int m8; int mC; const void* m10; int m14; };
extern const char lbl_80673338[];
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8065C1B0[];
extern "C" void fn_8040074C(void* p, int n);
extern "C" {

FE_OVERLAY FeScrH* fn_804AA58C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeArrL* s = (FeArrL*)((char*)self + 0x14C);
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80673338);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    s->m10 = lbl_8064B298;
    s->m0 = (char*)self + 0x164;
    s->m8 = 0xFA;
    fn_8040074C(s->m0, 0x3E8);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->m4 = 0;
    s->mC = 0;
    s->m14 = 0;
    s->m10 = lbl_8065C1B0;
    FeI(self, 0x54C) = -1;
    FeI(self, 0x550) = 0;
    return self;
}

FE_OVERLAY void fn_804AAA28(void* x, int a)
{
    switch (a) {
    case 0:
        fn_804AAEB0(x);
        break;
    case 1:
        fn_804AAF34(x);
        break;
    case 2:
        fn_804AAFE8(x);
        break;
    case 3:
        fn_804AB0C8(x);
        break;
    case 4:
        fn_804AB188(x);
        break;
    }
}

FE_OVERLAY void fn_804AAA9C(void* x, int a)
{
    if (a == FeI(x, 0x140)) {
        fn_804AB774(x);
        fn_804AB860(x);
    }
}

FE_OVERLAY void fn_804AAADC(void* x, int a)
{
    if (a == FeI(x, 0x144)) {
        int s = ((FeWI*)FeMem(x, 0x140))->s61();
        fn_804AB224(x);
        ((FeW3*)FeMem(x, 0x140))->s87(FeI(x, 0x54C), FeI(x, 0x550) ^ 1, (int)((char*)x + 0x14C));
        ((FeWQ*)FeMem(x, 0x140))->s69(s);
        if (((FeWI*)FeMem(x, 0x140))->s59() == 0)
            ((FeWQ*)FeMem(x, 0x140))->s14(0);
        fn_804AB774(x);
        fn_804AB860(x);
    }
}

FE_OVERLAY int fn_804AABD8(void* x)
{
    FeMem(x, 0x140)->fn_vslot50();
    return 0;
}

FE_OVERLAY int fn_804AAC14(void* x)
{
    FeMem(x, 0x140)->fn_vslot51();
    return 0;
}

FE_OVERLAY int fn_804AAC50(void* x)
{
    FeMem(x, 0x140)->fn_vslot52();
    return 0;
}

FE_OVERLAY int fn_804AAC8C(void* x)
{
    FeMem(x, 0x140)->fn_vslot53();
    return 0;
}

FE_OVERLAY int fn_804AACC8(void* x)
{
    FeMem(x, 0x140)->fn_vslot56();
    return 0;
}

FE_OVERLAY int fn_804AAD04(void* x)
{
    FeMem(x, 0x140)->fn_vslot57();
    return 0;
}

FE_OVERLAY int fn_804AAD40(void* x)
{
    FeMem(x, 0x140)->fn_vslot54();
    return 0;
}

FE_OVERLAY int fn_804AAD7C(void* x)
{
    FeMem(x, 0x140)->fn_vslot55();
    return 0;
}

FE_OVERLAY int fn_804AADB8(void* x)
{
    FeMem(x, 0x144)->fn_vslot40(1);
    return 1;
}

FE_OVERLAY int fn_804AADF8(void* x)
{
    ((FeWV*)FeMem(x, 0x144))->s41();
    return 1;
}

FE_OVERLAY int fn_804AAE34(void* x)
{
    FeMem(x, 0x144)->fn_vslot38(1);
    return 1;
}

FE_OVERLAY int fn_804AAE74(void* x)
{
    FeMem(x, 0x144)->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804AAEB0(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

FE_OVERLAY void fn_804AAF34(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    int idx = FeMem(x, 0x140)->fn_vslot60();
    int o = idx * 4;
    int id = *(int*)((char*)FeP(x, 0x14C) + o);
    FeI(fn_800B555C(), 0x614) = id;
    fn_8040B830(p->name, lbl_805F5510, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

FE_OVERLAY void fn_804AAFE8(void* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    int s = ((FeWI*)FeMem(x, 0x140))->s61();
    if (s != FeI(x, 0x54C)) {
        FeI(x, 0x54C) = s;
        FeI(x, 0x550) = s == 2;
    }
    char* p = (char*)x + 0x14C;
    ((FeW3*)FeMem(x, 0x140))->s87(1, FeI(x, 0x550) ^ 1, (int)p);
    ((FeW3*)FeMem(x, 0x140))->s87(s, FeI(x, 0x550), (int)p);
    FeI(x, 0x550) = FeI(x, 0x550) ^ 1;
    fn_804AB774(x);
}

FE_OVERLAY void fn_804AB0C8(void* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    int idx = FeMem(x, 0x140)->fn_vslot60();
    FeList* l = (FeList*)FeP(x, 0x138);
    int o = idx * 4;
    fn_80126CF4(l, l->m164, *(int*)((char*)FeP(x, 0x14C) + o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    fn_804AB860(x);
    FeMem(x, 0x144)->fn_vslot16(0);
}

FE_OVERLAY void fn_804AB188(void* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    FeList* l = (FeList*)FeP(x, 0x138);
    fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    fn_804AB860(x);
    FeMem(x, 0x144)->fn_vslot16(1);
}

FE_OVERLAY void fn_804AB774(void* x)
{
    int sel = ((FeWI*)FeMem(x, 0x140))->s60();
    int v;
    if (FeI(x, 0x150) != 0) {
        int o = sel * 4;
        v = *(int*)((char*)FeP(x, 0x14C) + o);
    } else {
        v = 0;
    }
    if (((FeWI*)FeMem(x, 0x138))->s87() != 0) {
        void* s = FeMem(x, 0x138);
        fn_80126CF4((FeList*)s, FeI(s, 0x164), v, FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
    }
    fn_804A96A4(FeP(x, 0x13C), v, 1, 2, 1, 0, 0, 0);
}

FE_OVERLAY void fn_804AB860(void* x)
{
    if (FeI(x, 0x150) != 0) {
        fn_801251CC(FeP(x, 0x134), 0, 0x10, 1);
        if (((FeWI*)FeMem(x, 0x138))->s87() == 0) {
            fn_801251CC(FeP(x, 0x134), 3, 0x1A2F, 3);
            fn_801251CC(FeP(x, 0x134), 2, 0x201A, 2);
        } else {
            fn_801251CC(FeP(x, 0x134), 3, 0x37A2, 4);
            fn_80125084(FeP(x, 0x134), 2);
        }
    } else {
        fn_80125084(FeP(x, 0x134), 0);
        fn_80125084(FeP(x, 0x134), 3);
        fn_80125084(FeP(x, 0x134), 2);
    }
}

/* near-miss (2 slots): retail stores the vptr before addi r3,self+0x144; all 5040 statement orders tried. */
FE_OVERLAY FeScrM* fn_804AB940(FeScrM* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674328);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m1C4 = 0;
    self->m1C8 = -1;
    fn_8040B320(self->m144, 0, 0x80);
    return self;
}

FE_OVERLAY void fn_804ABADC(void* x, int a)
{
    fn_800ED310(x, a);
    if (a != 0) {
        if (fn_800E4874(FeP(x, 0x140)) > 0)
            ((FeWQ*)FeMem(x, 0x134))->s14(1);
        else
            ((FeWQ*)FeMem(x, 0x134))->s14(0);
        ((FeWQ*)FeMem(x, 0x138))->s14(1);
    } else {
        ((FeWQ*)FeMem(x, 0x134))->s14(0);
        ((FeWQ*)FeMem(x, 0x138))->s14(0);
    }
}

FE_OVERLAY int fn_804ABBCC(void* x)
{
    FeMem(x, 0x134)->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804ABC08(void* x)
{
    FeMem(x, 0x134)->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804ABC44(void* x)
{
    FeMem(x, 0x134)->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804ABC80(void* x)
{
    FeMem(x, 0x134)->fn_vslot53();
    return 1;
}

}
