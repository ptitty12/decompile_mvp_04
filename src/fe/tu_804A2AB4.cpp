/*
 * Front-end overlay code, .frontend_codeoverlay 0x804A2AB4-0x804A721C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY FeScrH* fn_804A2AB4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674B20);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

FE_OVERLAY int fn_804A2DBC(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY int fn_804A2E28(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_804A2E84(void* x)
{
    FeMem(x, 0x134)->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804A2EC0(void* x)
{
    FeMem(x, 0x134)->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804A2EFC(void* x)
{
    FeMem(x, 0x134)->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804A2F38(void* x)
{
    FeMem(x, 0x134)->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804A2F74(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern const char lbl_80674878[];
FE_OVERLAY FeScrH* fn_804A3044(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674878);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_804A3090(FeScrD* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_804A31D8(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_804A31F8(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_804A3218(void) {}

FE_OVERLAY void fn_804A321C(void) {}

FE_OVERLAY void fn_804A3220(void) {}

FE_OVERLAY void fn_804A32F4(void* a, void* b)
{
    fn_800B7ADC(FeGetMgr(), b);
}

FE_OVERLAY int fn_804A334C(void) { return 0; }

FE_OVERLAY int fn_804A3354(void) { return 0; }

FE_OVERLAY void fn_804A335C(void* x, char* dst)
{
    const char* s = FeI(x, 0x138) ? lbl_805F763C : lbl_805F7648;
    fn_8040B830(dst, s, 16);
}

FE_OVERLAY FeScrH* fn_804A33A4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    /* near-miss (2 slots: the stw 0x134/0x138 pair swapped): all 720 orders of these six statements
     * with a shared int zero tried; the float needs an extern const float to hoist its lfs. */
    int z = 0;
    self->SetVptr(lbl_80682260);
    self->m130 = z;
    FeI(self, 0x138) = z;
    FeI(self, 0x134) = z;
    *(float*)((char*)self + 0x10E0) = lbl_805F7708;
    *(short*)((char*)self + 0x140) = z;
    return self;
}

FE_OVERLAY void fn_804A34F8(FeW* x)
{
    fn_800ECF18(x);
    ((FeWV*)x)->s40();
}

FE_OVERLAY void fn_804A3658(void* x)
{
    ((FeStateY*)fn_800B555C())->m2C = FeI(x, 0x134);
    ((FeStateY*)fn_800B555C())->m28 = FeI(x, 0x10E4);
}

FE_OVERLAY void fn_804A40EC(FeScrD* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_804A410C(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_804A4AA8(void* x, int a, void* c)
{
    fn_804A4558(x, c);
    fn_804A560C(x);
    fn_804A5854(x, FeI(x, 0x210));
}

FE_OVERLAY int fn_804A507C(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        FeMem(x, 0x224)->fn_vslot40(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A50E0(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        ((FeWV*)FeMem(x, 0x224))->s41();
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A5140(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        FeMem(x, 0x224)->fn_vslot38(1);
        r = 1;
    }
    return r;
}

}
