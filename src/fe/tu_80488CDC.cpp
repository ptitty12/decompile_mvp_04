/*
 * Front-end overlay code, .frontend_codeoverlay 0x80488CDC-0x8048E6A0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY FeScrH* fn_80488CDC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806765D8);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80488D30(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

extern "C" FE_OVERLAY void fn_80489324(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_8048977C(void* x)
{
    FeAt(x, 0x154)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804897B8(void* x)
{
    FeAt(x, 0x154)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804897F4(void* x)
{
    FeAt(x, 0x154)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80489830(void* x)
{
    FeAt(x, 0x154)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_8048A378(FeScrCell* x)
{
    fn_800ECE34(x);
    x->fn_vslot32("CELL", 1);
    x->m134 = fn_800C8060();
    x->m138 = fn_800B7AB8(FeGetMgr(), "PLAYERINFOBAR");
    x->m13C = fn_800B7AB8(FeGetMgr(), "BATPITCHSTATS");
}

extern "C" FE_OVERLAY void fn_8048AB24(void* x)
{
    fn_800ED254(x);
    FeI(fn_800B555C(), 0x640) = 0;
}

extern "C" FE_OVERLAY int fn_8048AC44(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AC80(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ACBC(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ACF8(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AD34(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AD80(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ADCC(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AE18(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AE64(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x134)) {
        w->fn_vslot68(c);
        x->fn_vslot67(2, fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrH* fn_8048B248(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80682508);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeF(self, 0x13C) = 0.0f;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 1;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8048B2C0(void* x)
{
    fn_800ECE34(x);
    fn_8048E7E4(x);
    fn_8048E6A0(x);
}

extern "C" FE_OVERLAY void fn_8048B76C(void* x)
{
    FeI(fn_800B555C(), 0x18) = FeI(x, 0x134);
}

extern "C" FE_OVERLAY void fn_8048B7A0(FeW* x)
{
    if (FeW24(x) < 0) {
        fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1);
        FeI(x, 0x138) = ((FeSub*)((char*)fn_800C8058() + 0xDC))->s5();
    }
}

extern "C" FE_OVERLAY int fn_8048B9B8(FeW* x)
{
    FeW* p = x->fn_vslot32("INFOMODE", 1);
    ((FeWV*)fn_800C805C(p))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_8048BB94(FeW* x)
{
    FeW* p = x->fn_vslot32("INFOMODE", 1);
    fn_800C805C(p)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_8048BBF4(void* x, int v)
{
    FeI(x, 0x140) = v;
    fn_8048BCE4(x);
}

extern "C" FE_OVERLAY void fn_8048BC18(void* x)
{
    fn_8048E8B0(x)->fn_vslot32("MOMENTUM", 1);
    fn_800C8044()->fn_vslot32("METER", 1);
    FeF(x, 0x13C) = (float)fn_800C8044()->fn_vslot32("METERBAR", 1)->m2A;
}

extern "C" FE_OVERLAY int fn_8048E450(void* x)
{
    return fn_8057CE00(0) == -1;
}

extern "C" FE_OVERLAY void fn_8048E4D8(void)
{
    fn_800B555C();
    fn_800B5758();
}
