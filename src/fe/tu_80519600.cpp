/*
 * Front-end overlay code, .frontend_codeoverlay 0x80519600-0x8051E878 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern const char lbl_806691F0[];
extern "C" int fn_8051DB28(FeScrN* x);
extern "C" int fn_8051DB64(FeScrN* x);
extern "C" int fn_8051DBA0(FeScrN* x);
extern "C" int fn_8051DBDC(FeScrN* x);
extern "C" int fn_8051D9F8(FeScrN* x);
extern "C" int fn_8051DA44(FeScrN* x);
extern "C" int fn_8051DA90(FeScrN* x);
extern "C" int fn_8051DADC(FeScrN* x);
extern "C" int fn_8051DC18(FeScrN* x);
extern "C" int fn_8051DCCC(FeScrN* x);
extern "C" int fn_8051DD28(FeScrN* x);
extern "C" int fn_8051DD80(FeScrN* x);
extern "C" int fn_8051DE1C(FeScrN* x);
extern "C" int fn_8051DE6C(FeScrN* x);
extern "C" FeScrN* fn_80519600(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);

extern "C" FE_OVERLAY FeScrN* fn_80519600(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806691F0);
    FeI(self, 0x130) = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 1;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    FeI(self, 0x16C) = 0;
    FeI(self, 0x170) = 0;
    FeI(self, 0x174) = 0;
    FeI(self, 0x380) = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_8051D9F8(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DA44(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DA90(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DADC(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DB28(FeScrN* x)
{
    x->m160->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DB64(FeScrN* x)
{
    x->m160->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DBA0(FeScrN* x)
{
    x->m160->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DBDC(FeScrN* x)
{
    x->m160->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DC18(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DCCC(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DD28(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot39();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DD80(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DE1C(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DE6C(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot39();
    }
    return 1;
}
