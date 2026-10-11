/*
 * Front-end overlay code, .frontend_codeoverlay 0x804654A0-0x8046C6F8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY int fn_8046BDE0(FeScrI* x)
{
    if (fn_8046C5C0(x) != 0) {
        x->m17C->fn_vslot52();
    }
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BE40(FeScrI* x)
{
    x->m17C->fn_vslot53();
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BE94(FeScrI* x)
{
    if (fn_8046C5C0(x) != 0) {
        x->m17C->fn_vslot50();
    }
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BEF4(FeScrI* x)
{
    x->m17C->fn_vslot51();
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BF48(FeScrI* x)
{
    fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1))->fn_vslot40(1);
    return 1;
}

FE_OVERLAY int fn_8046BFB0(FeScrI* x)
{
    ((FeWV*)fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1)))->s41();
    return 1;
}

FE_OVERLAY int fn_8046C014(FeScrI* x)
{
    fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1))->fn_vslot38(1);
    return 1;
}

FE_OVERLAY int fn_8046C07C(FeScrI* x)
{
    fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1))->fn_vslot39();
    return 1;
}

FE_OVERLAY int fn_8046C0E0(FeScrI* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8046C13C(void) { return 0; }

FE_OVERLAY int fn_8046C144(FeScrI* x)
{
    fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1))->fn_vslot38(1);
    return 0;
}

FE_OVERLAY int fn_8046C1AC(FeScrI* x)
{
    fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1))->fn_vslot39();
    return 0;
}

FE_OVERLAY int fn_8046C210(FeScrI* x)
{
    fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1))->fn_vslot40(1);
    fn_8046BBC0(x, 1);
    return 0;
}

FE_OVERLAY int fn_8046C290(FeScrI* x)
{
    ((FeWV*)fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1)))->s41();
    fn_8046BBC0(x, 1);
    return 0;
}

FE_OVERLAY int fn_8046C30C(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1))->fn_vslot38(1);
    } else if ((unsigned)x->m208 <= 2) {
        x->m158->fn_vslot38(1);
    }
    return 0;
}

FE_OVERLAY int fn_8046C3BC(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1))->fn_vslot39();
    } else if ((unsigned)x->m208 <= 2) {
        x->m158->fn_vslot39();
    }
    return 0;
}

FE_OVERLAY int fn_8046C464(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1))->fn_vslot40(1);
    } else if ((unsigned)x->m208 <= 2) {
        x->m158->fn_vslot40(1);
    }
    return 0;
}

FE_OVERLAY int fn_8046C514(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        ((FeWV*)fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1)))->s41();
    } else if ((unsigned)x->m208 <= 2) {
        ((FeWV*)x->m158)->s41();
    }
    return 0;
}

FE_OVERLAY void fn_8046C5BC(void) {}

FE_OVERLAY int fn_8046C5C0(FeScrI* x)
{
    switch (x->m208) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    case 6:
        return x->m20C;
    case 7:
        return 0;
    case 8:
        return 0;
    }
    return 1;
}

FE_OVERLAY FeScrJ* fn_8046C63C(FeScrJ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806793D0);
    self->m130 = 0;
    self->m138 = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 1;
    self->m150[0] = lbl_805F36A0.c0;
    fn_800C21D0((char*)fn_800B555C() + 8);
    return self;
}

FE_OVERLAY void fn_8046C6B8(FeScrJ* x)
{
    fn_800ECE34(x);
    if (fn_800C2248((char*)fn_800B555C() + 8) == 0) {
        fn_800C2210((char*)fn_800B555C() + 8);
    }
}

}
