/*
 * Front-end overlay code, .frontend_codeoverlay 0x8048E6A0-0x80492680 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_805F66CC[];
extern const char lbl_805F66D8[];
extern const char lbl_805F66E4[];
extern const char lbl_805F66F0[];
extern const char lbl_805F6934[];
extern const char lbl_805F6940[];
extern const char lbl_805F69E4[];
extern "C" {

extern "C" void fn_800E49DC(FeScrD* x);

FE_OVERLAY void fn_8048E6A0(FeScrO* x)
{
    if (fn_800B5758(fn_800B555C()) != 0) {
        x->m148 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66CC, 1));
        x->m14C = (int)fn_800C8044(x->fn_vslot32(lbl_805F66D8, 1));
    } else {
        x->m148 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66D8, 1));
        x->m14C = (int)fn_800C8044(x->fn_vslot32(lbl_805F66CC, 1));
    }
}

FE_OVERLAY int fn_8048E76C(FeScrO* x)
{
    if (x->m148 == 0) {
        fn_8048E6A0(x);
    }
    return x->m148;
}

FE_OVERLAY int fn_8048E7A8(FeScrO* x)
{
    if (x->m14C == 0) {
        fn_8048E6A0(x);
    }
    return x->m14C;
}

FE_OVERLAY void fn_8048E7E4(FeScrO* x)
{
    if (fn_800B5758(fn_800B555C()) != 0) {
        x->m150 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66E4, 1));
        x->m154 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66F0, 1));
    } else {
        x->m150 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66F0, 1));
        x->m154 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66E4, 1));
    }
}

FE_OVERLAY int fn_8048E8B0(FeScrO* x)
{
    if (x->m150 == 0) {
        fn_8048E7E4(x);
    }
    return x->m150;
}

FE_OVERLAY int fn_8048E8EC(FeScrO* x)
{
    if (x->m154 == 0) {
        fn_8048E7E4(x);
    }
    return x->m154;
}

FE_OVERLAY FeScrH* fn_8048E928(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 0x12, lbl_806217F8);
    self->SetVptr(lbl_80676060);
    return self;
}

FE_OVERLAY void fn_8048E990(void* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0x2422);
}

FE_OVERLAY int fn_8048E9C8(void* x, int a)
{
    FeI(fn_800B555C(), 0x570) = a;
    fn_80132438(fn_804D2D50(x), x, fn_804D3BA0, fn_8048EC48, fn_8048EBC8, 0x3A61, -1, 1, lbl_805F66FC);
    fn_804D2D50(x)->fn_vslot86();
    ((FeWV*)x)->s40();
    return 1;
}

FE_OVERLAY void fn_8048EA74(FeW* x)
{
    FeMsg m;
    FeMsg* p = &m;
    int v = FeI(fn_800B555C(), 0x570);
    ((void (*)(void*, int))fn_804D32A0)(x, v);
    fn_800E2944(fn_804D2ED0(x, 0x52)->x4(), v);
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F3CA8, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

FE_OVERLAY void fn_8048EB38(FeScrD* x)
{
    fn_800E49DC(x);
}

FE_OVERLAY void fn_8048EB58(void* x)
{
    int v = fn_804D2ED0(x, 0x4D)->x4();
    if (v == 1 && FeI(x, 0x170) == 0) {
        fn_8007295C__18Unk8007A4DC_Screen(lbl_8061930C);
        FeI(x, 0x170) = v;
    }
}

FE_OVERLAY void fn_8048EBC8(void)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    ((FeWQ*)w)->s85(0);
    FeI(w, 0x314) = 1;
}

FE_OVERLAY void fn_8048EC48(FeW* x)
{
    x->fn_vslot80(1);
    fn_8048EA74(x);
}

FE_OVERLAY void fn_8048FC64(void)
{
    ((FeStateX*)fn_800B555C())->m650 = 0;
    fn_800C33D0();
    fn_800C3BE0();
    fn_8001BC4C();
    fn_8001C168();
}

FE_OVERLAY int fn_80491630(FeW* x)
{
    if (FeI(x, 0x13C) == 1) {
        return 0;
    }
    switch (FeI(x, 0x134)) {
    case 0: {
        int v = 0;
        if (FeI(FeP(x, 0x1A4), 0x1CD0) != 0) {
            v = 1;
        }
        if (v == FeI(x, 0x188)) {
            fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 0))->fn_vslot51();
        } else {
            fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 0))->fn_vslot51();
        }
        break;
    }
    case 1:
        FeMem(x, 0x21C)->fn_vslot51();
        break;
    case 2:
        fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 0))->fn_vslot51();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_80491998(FeW* x)
{
    if (FeI(x, 0x13C) != 0) {
        return 0;
    }
    switch (FeI(x, 0x134)) {
    case 0: {
        int v = 0;
        if (FeI(FeP(x, 0x1A4), 0x1CD0) != 0) {
            v = 1;
        }
        if (v == FeI(x, 0x188)) {
            fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 0))->fn_vslot53();
        } else {
            fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 0))->fn_vslot53();
        }
        break;
    }
    case 1:
        FeMem(x, 0x21C)->fn_vslot53();
        break;
    case 2:
        fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 0))->fn_vslot53();
        break;
    }
    return 1;
}

FE_OVERLAY void fn_80491ADC(void* x)
{
    FeI(x, 0x334) = FeMem(x, 0x198)->fn_vslot85();
}

FE_OVERLAY int fn_80491B24(void* x)
{
    if (FeMem(x, 0x198)->fn_vslot86() != 0 && FeW24(FeP(x, 0x198)) < 0 && FeMem(x, 0x198)->fn_vslot85() != FeI(x, 0x334)) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80491BBC(void* x)
{
    if (FeMem(x, 0x198)->fn_vslot86() != 0 && FeW24(FeP(x, 0x198)) < 0 && FeMem(x, 0x198)->fn_vslot85() != FeI(x, 0x334)) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80491C54(void* x)
{
    ((FeWV*)FeMem(x, 0x248))->s47();
    fn_80492E94(x);
    return 1;
}

FE_OVERLAY int fn_80491CA4(void* x)
{
    FeMem(x, 0x248)->fn_vslot48();
    return 1;
}

FE_OVERLAY int fn_80491CE0(void* x)
{
    ((FeWV*)FeMem(x, 0x248))->s45();
    fn_80492E94(x);
    return 1;
}

FE_OVERLAY int fn_80491D30(void* x)
{
    FeMem(x, 0x248)->fn_vslot46();
    return 1;
}

FE_OVERLAY void fn_80491EE0(char* x)
{
    int i = FeI(x, 0x188);
    int o = i * 4;
    char* a = x + 0x240;
    char* b = x + 0x24C;
    int r = fn_800E2E8C(*(int*)(a + o), i, *(int*)(b + o), 0);
    *(int*)(b + FeI(x, 0x188) * 4) = r;
}

}
