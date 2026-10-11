/*
 * Front-end overlay code, .frontend_codeoverlay 0x804987EC-0x8049B0CC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY void fn_80498F9C(void)
{
    fn_800C33D0();
    fn_800C3BE0();
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

FE_OVERLAY void fn_8049AE98(FeScrD* x)
{
    fn_800ECE34(x);
}

}
