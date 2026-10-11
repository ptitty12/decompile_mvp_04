/*
 * Front-end overlay code, .frontend_codeoverlay 0x80477068-0x8047BB8C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY void fn_80477068(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80477498(FeW* x)
{
    x->fn_vslot32("TEAMSCORE", 1);
    fn_800C8044()->fn_vslot32("AWAYMETER", 1);
    fn_800C8044()->fn_vslot32("METERBAR", 1);
    FeI(x, 0x134) = fn_800C8038()->m2A;
}

extern "C" FE_OVERLAY void fn_80477540(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_80477560(void* x)
{
    fn_80477594(x);
    fn_804775D0(x);
}

extern "C" FE_OVERLAY void fn_80477594(void* x)
{
    fn_80477608(x, (char*)lbl_806192E0->m4->m14 + 0xE64, "AWAY");
}

extern "C" FE_OVERLAY void fn_804775D0(void* x)
{
    fn_80477608(x, lbl_806192E0->m4->m14, "HOME");
}

extern "C" FE_OVERLAY void fn_80477C04(void* x, void* y, void* z)
{
    char sp8[0x460];
    fn_8055AC44(sp8, FeI(x, 0x140));
    fn_800DD800(z, sp8, FeI(y, 0x198), 0);
}

extern "C" FE_OVERLAY int fn_80477C54(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80477E48(FeW* x, char* y)
{
    char* s = y + 0xC;
    if (fn_8040B574(s, "PLAY") == 0 || fn_8040B574(s, "SIM") == 0 || fn_8040B574(s, "MANAGE") == 0) {
        x->fn_vslot41(0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80477EE4(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_80477F44(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80477FA4(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80478004(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_80478064(FeW* x, int a)
{
    x->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY FeScrH* fn_8047809C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676B28);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = -1;
    FeI(self, 0x1AC) = 0;
    FeI(self, 0x1B0) = 0;
    FeI(self, 0x1B4) = -1;
    FeI(self, 0x1B8) = 0;
    FeI(self, 0x1BC) = 0;
    FeI(self, 0x1C0) = 0;
    FeI(self, 0x1C4) = 0;
    FeI(self, 0x1C8) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80479480(void* x)
{
    fn_80125BC0(FeWp(x, 0x1C8));
}

extern "C" FE_OVERLAY void fn_80479614(void* x, int a)
{
    fn_800ED310(x, a);
    if (a != 0)
        FeWp(x, 0x1C0)->fn_vslot14(1);
    else
        FeWp(x, 0x1C0)->fn_vslot14(0);
}

extern "C" FE_OVERLAY int fn_804799E8(char* x)
{
    int i;
    int n = *(int*)(x + 0x134);
    for (i = 0; i < n; i++) {
        int o = i * 12;
        char* b = x + 0x154;
        if (*(int*)(b + o) == 1)
            return i;
    }
    return -1;
}

extern "C" FE_OVERLAY void fn_80479A28(int a)
{
    if (a != 0)
        fn_8047AE14(fn_800B7A94(FeGetMgr(), "FPLAYORSIMMULTI"), 6);
}

extern "C" FE_OVERLAY void fn_8047AA20(char* x)
{
    int i;
    for (i = 0; i < 8; i++) {
        int o = i * 12;
        FeSet(x + 0x14C, o, -1);
        FeSet(x + 0x150, o, -1);
        FeSet(x + 0x154, o, 0);
    }
    FeI(x, 0x134) = 0;
}

extern "C" FE_OVERLAY void fn_8047AE14(void* x, int v)
{
    FeI(x, 0x1AC) = v;
}

extern "C" FE_OVERLAY void fn_8047B01C(void* x)
{
    FeI(x, 0x1B8) = FeWp(x, 0x1C0)->fn_vslot60();
}

extern "C" FE_OVERLAY int fn_8047B9AC(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() > 0) {
        FeWp(x, 0x1C0)->fn_vslot50();
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047BA20(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() > 0) {
        FeWp(x, 0x1C0)->fn_vslot51();
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047BA94(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() < FeI(x, 0x134) - 1) {
        FeWp(x, 0x1C0)->fn_vslot52();
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047BB10(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() < FeI(x, 0x134) - 1) {
        FeWp(x, 0x1C0)->fn_vslot53();
        fn_8047B15C(x);
    }
    return 1;
}
