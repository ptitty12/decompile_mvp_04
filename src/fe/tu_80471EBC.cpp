/*
 * Front-end overlay code, .frontend_codeoverlay 0x80471EBC-0x804740A8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY void fn_804726A0(void* x)
{
    int r = FeWp(x, 0x140)->fn_vslot60();
    if (r >= 0) {
        void* p = fn_80548E1C(lbl_80619948->m58, r);
        fn_804A96A4(FeVp(x, 0x134), p, 1, 2, 1, 0, 1, 0);
    }
}

extern "C" FE_OVERLAY int fn_80472BBC(void* x)
{
    FeAt(x, 0x140)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472BF8(void* x)
{
    FeAt(x, 0x140)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472C34(void* x)
{
    FeAt(x, 0x140)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472C70(void* x)
{
    FeAt(x, 0x140)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472CAC(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x140)) {
        w->fn_vslot68(c);
        x->fn_vslot67(1, 0);
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrH* fn_80472E04(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678808);
    self->m130 = 0;
    FeI(self, 0x13C) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804731C4(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804731E4(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473220(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047325C(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473298(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804732D4(FeW* x)
{
    FeI(fn_800B555C(), 0x640) = 0;
    x->fn_vslot80(0);
    x->fn_vslot67(FeWp(x, 0x134)->fn_vslot60(), 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047336C(FeW* x, int a, int b, int c)
{
    int r;
    if (a != FeI(x, 0x134)) {
        r = 0;
    } else {
        x->fn_vslot67(c, 0);
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804733C4(void* x, char* buf)
{
    *buf = 0;
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    fn_8040B830(buf, (char*)w + 0xC, 16);
}

extern "C" FE_OVERLAY void fn_80473630(FeScrD* x)
{
    fn_80473560(x);
}

extern "C" FE_OVERLAY void fn_80473650(int a, void* b)
{
    if (a != 0) {
        if (a == 1)
            fn_80473440(b);
    }
}

extern "C" FE_OVERLAY int fn_80473718(void* x)
{
    int v = FeWp(x, 0x134)->fn_vslot60();
    return v > FeI(fn_800B555C(), 0x63C);
}

extern "C" FE_OVERLAY void fn_80473A98(void* x, int a)
{
    fn_800ED310(x, a);
    FeWp(x, 0x134)->fn_vslot14(a);
}

extern "C" FE_OVERLAY FeScrH* fn_80473AE8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678560);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_80473E48(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80473EB4(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473EF0(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473F2C(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473F68(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}
