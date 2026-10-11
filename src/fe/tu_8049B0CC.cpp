/*
 * Front-end overlay code, .frontend_codeoverlay 0x8049B0CC-0x8049E0BC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

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

extern const char lbl_80675070[];
FE_OVERLAY FeScrH* fn_8049C4D8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675070);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8049CC78(FeScrD* x)
{
    fn_800ED254(x);
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

FE_OVERLAY void fn_8049D430(char* x)
{
    int i;
    for (i = 0; i < 0x1D; i++) {
        char* b = x + 0x164;
        int o = i * 4;
        *(int*)(b + o) = 0;
    }
}

FE_OVERLAY void fn_8049DEEC(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

}
