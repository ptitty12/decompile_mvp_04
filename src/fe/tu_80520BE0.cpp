/*
 * Front-end overlay code, .frontend_codeoverlay 0x80520BE0-0x805283C4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern const char lbl_80669CF8[];
extern const char lbl_80669FA0[];
extern "C" void fn_80522A74(FeScrD* x);
extern "C" void fn_805246C4(FeScrG* x);
extern "C" FeScrH* fn_80525624(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" FeScrN* fn_80524C1C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);

extern "C" FE_OVERLAY void fn_80522A74(FeScrD* x)
{
    fn_800ECF18(x);
}

extern "C" FE_OVERLAY void fn_805246C4(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

extern "C" FE_OVERLAY FeScrN* fn_80524C1C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669FA0);
    FeI(self, 0x130) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    return self;
}

extern "C" FE_OVERLAY FeScrH* fn_80525624(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669CF8);
    self->m130 = 0;
    return self;
}
