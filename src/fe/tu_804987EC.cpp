/*
 * Front-end overlay code, .frontend_codeoverlay 0x804987EC-0x8049B0CC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY void fn_80498880(FeW* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    FeI(x, 0x150) = (int)fn_800C8044(x->fn_vslot32(lbl_805F5500, 0));
    *(float*)((char*)x + 0x164) = lbl_806192E0->m4->m14->m1D48;
}

FE_OVERLAY void fn_80498F9C(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY FeScrL* fn_8049A1F0(FeScrL* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8046FED8(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677448);
    FeI(self, 0x35C) = 0;
    FeI(self, 0x360) = 0;
    FeI(self, 0x364) = 0x3C;
    *(float*)((char*)self + 0x368) = lbl_805F7434;
    FeI(self, 0x36C) = 0;
    return self;
}

FE_OVERLAY void fn_8049A330(void* x, int a)
{
    if (FeI(x, 0x338) != 0 && ((FeWI*)x)->s120() == 0) {
        ((FeWI*)x)->s117();
    } else {
        FeI(x, 0x36C) = 0;
        fn_80470F20((FeScrL*)x, a);
    }
}

FE_OVERLAY int fn_8049A480(char* x)
{
    if (FeI(x, 0x36C) != 0) {
        if ((float)*(short*)((char*)FeP(x, 0x34C) + 0x2A) < *(float*)(x + 0x32C)) {
            return 0;
        }
    }
    return 1;
}

FE_OVERLAY void fn_8049A760(FeScrL* x)
{
    x->m314 = 6;
    FeGlobal80619948* g = lbl_80619948;
    if (g->m80 == 8) {
        g->m74 = 0;
        g->m80 = 0;
        FeI(g, 0xA4) = 0;
    }
    ((void (*)(FeGlobal80619948*))fn_800A2948)(g);
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 5, -1);
    fn_8001BC4C()->fn_8001BDAC(0x9D);
}

FE_OVERLAY void fn_8049A988(FeScrL* x, int a)
{
    x->m314 = 0xA;
    FeGlobal80619948* g = lbl_80619948;
    if (g->m80 == 0xB) {
        g->m74 = 0;
        g->m80 = 0;
        FeI(g, 0xA4) = 0;
    }
    fn_800A2948(g, a);
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 9, -1);
}

FE_OVERLAY void fn_8049AB70(void* a, void* b)
{
    fn_8049A4DC(b);
}

FE_OVERLAY void fn_8049AB94(FePopup* p)
{
    FeScrL* x = (FeScrL*)p;
    x->m314 = 0xB;
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 0xA, -1);
}

FE_OVERLAY void fn_8049ABD4(FePopup* p)
{
    FeScrL* x = (FeScrL*)p;
    x->m314 = 0xC;
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 0xB, -1);
}

extern const char lbl_80675868[];
FE_OVERLAY FeScrH* fn_8049AC14(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675868);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8049AC60(FeScrD* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_8049AD0C(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_8049AD2C(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8049AD4C(void) {}

FE_OVERLAY void fn_8049AD50(void) {}

FE_OVERLAY void fn_8049AD54(void) {}

FE_OVERLAY int fn_8049AD58(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8049ADB4(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8049AE10(void) { return 0; }

FE_OVERLAY void fn_8049AE18(int a, char* dst)
{
    fn_8040B830(dst, &lbl_805F36A0.c0, 16);
}

FE_OVERLAY FeScrH* fn_8049AE48(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806755C0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

FE_OVERLAY void fn_8049AE98(FeScrD* x)
{
    fn_800ECE34(x);
}

}
