/*
 * Front-end overlay code, .frontend_codeoverlay 0x8049B0CC-0x8049E0BC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_805F74C4[];
extern "C" char* strncpy(char*, const char*, unsigned);
extern "C" char fn_800B56C4(void* s);
extern "C" void fn_8049D5C8(void* x);
extern "C" {

FE_OVERLAY void fn_8049B0CC(void* x)
{
    fn_800ECAA4(x);
    int* p = (int*)FeP(x, 0x134);
    if (p != 0 && *p == 0) {
        fn_800CFB38(p);
    }
}

FE_OVERLAY void fn_8049B114(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8049B134(void) {}

FE_OVERLAY void fn_8049B138(void) {}

FE_OVERLAY void fn_8049B13C(void) {}

FE_OVERLAY int fn_8049B140(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8049B19C(FeW* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    char t = fn_800B56C4(fn_800B555C());
    if (t != 0) {
        strncpy(mp->name, lbl_805F3CA8, 15);
        mp->name[15] = 0;
    } else if (fn_800B5758(fn_800B555C()) != 0) {
        strncpy(mp->name, lbl_805F74C4, 15);
        mp->name[15] = t;
    } else {
        ((FeWQ*)x)->s79((int)mp);
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}

FE_OVERLAY int fn_8049B280(void) { return 0; }

FE_OVERLAY void fn_8049B288(int a, char* dst)
{
    fn_8040B830(dst, &lbl_805F36A0.c0, 16);
}

extern const char lbl_80675318[];
FE_OVERLAY FeScrH* fn_8049B2B8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675318);
    self->m130 = 0;
    return self;
}

extern "C" void fn_8049B90C(FeScrB* x);
extern "C" void fn_8049BB90(FeScrB* x);
extern "C" void fn_8049C440(FeScrB* x);
FE_OVERLAY void fn_8049B7A8(FeScrB* x, int a, int b)
{
    x->m134 = b;
    fn_8049B90C(x);
    fn_8049BB90(x);
    fn_8049C440(x);
}

FE_OVERLAY int fn_8049B7E8(void* x)
{
    FeMem(x, 0x19C)->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8049B824(void* x)
{
    FeMem(x, 0x19C)->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8049B860(void* x)
{
    FeMem(x, 0x19C)->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8049B89C(void* x)
{
    FeMem(x, 0x19C)->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_8049B8D8(FeScrB* x)
{
    fn_8049BB90(x);
    fn_8049C440(x);
}

FE_OVERLAY void fn_8049C440(FeScrB* x)
{
    fn_80124FA8(FeP(x, 0x1A0), x);
    fn_80125154(FeP(x, 0x1A0), 0);
    if (FeW24(FeP(x, 0x1A4)) < 0) {
        fn_801251CC(FeP(x, 0x1A0), 3, 0x37A2, 2);
    } else if (FeI(x, 0x138) != 0) {
        fn_801251CC(FeP(x, 0x1A0), 3, 0x1A2F, 1);
    } else {
        fn_80125084(FeP(x, 0x1A0), 3);
    }
}

extern const char lbl_80675070[];
FE_OVERLAY FeScrH* fn_8049C4D8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675070);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8049CBD4(void* x)
{
    fn_80124FA8(FeP(x, 0x14C), x);
    fn_80125154(FeP(x, 0x14C), 0);
    if (FeI(x, 0x164) != 0) {
        fn_801251CC(FeP(x, 0x14C), 0, 0x37F2, 1);
        fn_801251CC(FeP(x, 0x14C), 3, 0x1A2F, 2);
        fn_801251CC(FeP(x, 0x14C), 2, 0x201A, 4);
    } else {
        fn_80125084(FeP(x, 0x14C), 0);
        fn_80125084(FeP(x, 0x14C), 3);
    }
}

FE_OVERLAY void fn_8049CC78(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8049CC98(void* x)
{
    char* p = (char*)fn_800B555C() + 8;
    FeI(p, 0x500) = FeMem(x, 0x138)->fn_vslot60();
    char* q = (char*)fn_800B555C() + 8;
    FeI(q, 0x504) = fn_800B548C(((FeSub*)((char*)FeP(x, 0x158) + 0xDC))->s5());
    FeI(fn_800B555C(), 0x510) = FeI(x, 0x15C);
    FeI(fn_800B555C(), 0x514) = FeI(x, 0x160);
}

FE_OVERLAY void fn_8049CD30(void* x, FeW* y)
{
    if (y == FeMem(x, 0x138)) {
        if (((FeWI*)FeMem(x, 0x148))->s86() != 0) {
            int idx = FeMem(x, 0x138)->fn_vslot60();
            int o = idx * 4;
            char* b = (char*)x + 0x164;
            FeList* l = (FeList*)FeP(x, 0x148);
            fn_80126CF4(l, *(int*)(b + o), FeI(l, 0x168), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
        fn_8049DE70((char*)x);
    }
}

FE_OVERLAY int fn_8049CDF4(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8049CE30(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8049CE6C(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8049CEA8(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_8049CEE4(FeScrF* x, FeW* w, int a, int b)
{
    if (w == x->m138) {
        w->fn_vslot68(b);
        x->fn_vslot67(2, 0);
    }
    return 0;
}

FE_OVERLAY void fn_8049D430(char* x)
{
    int i;
    for (i = 0; i < 0x1D; i++) {
        char* b = x + 0x164;
        int o = i * 4;
        *(int*)(b + o) = 0;
    }
}

FE_OVERLAY void fn_8049D454(void* x, FeW* w)
{
    if (w == FeMem(x, 0x154)) {
        int k = FeI(x, 0x334);
        if (k == 0) {
            char* b = (char*)fn_800B555C() + 8;
            FeI(b, 0x664) = ((FeSubI*)((char*)FeP(x, 0x158) + 0xDC))->s5();
        } else if (k == 2) {
            char* b = (char*)fn_800B555C() + 8;
            FeI(b, 0x668) = ((FeSubI*)((char*)FeP(x, 0x158) + 0xDC))->s5();
        }
        int v = ((FeWI*)FeMem(x, 0x138))->s61();
        fn_8049D5C8(x);
        fn_8049CBD4(x);
        if (FeI(x, 0x15C) == 1) {
            ((FeWT*)FeMem(x, 0x138))->s86(2, FeI(x, 0x160) ^ 1, (char*)x + 0x164);
        }
        ((FeWT*)FeMem(x, 0x138))->s86(FeI(x, 0x15C), FeI(x, 0x160), (char*)x + 0x164);
        FeMem(x, 0x138)->fn_vslot68(0);
        ((FeWQ*)FeMem(x, 0x138))->s69(v);
    }
}

FE_OVERLAY void fn_8049DE70(char* x)
{
    int idx = FeMem(x, 0x138)->fn_vslot60();
    char* b = x + 0x164;
    int o = idx * 4;
    fn_804A96A4(FeP(x, 0x150), *(int*)(b + o), 1, 2, 1, FeI(x, 0x334) == 1, 0, 0);
}

FE_OVERLAY void fn_8049DEEC(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

FE_OVERLAY int fn_8049DF3C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot56();
    return 1;
}

FE_OVERLAY int fn_8049DF9C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot57();
    return 1;
}

FE_OVERLAY int fn_8049DFFC(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot54();
    return 1;
}

FE_OVERLAY int fn_8049E05C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot55();
    return 1;
}

}
