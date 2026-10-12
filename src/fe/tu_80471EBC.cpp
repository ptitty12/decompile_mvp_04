/*
 * Front-end overlay code, .frontend_codeoverlay 0x80471EBC-0x804740A8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY FeScrH* fn_80471EBC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678AB0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804726A0(void* x)
{
    int r = FeWp(x, 0x140)->fn_vslot60();
    if (r >= 0) {
        void* p = fn_80548E1C(lbl_80619948->m58, r);
        fn_804A96A4(FeVp(x, 0x134), p, 1, 2, 1, 0, 1, 0);
    }
}

extern "C" FE_OVERLAY void fn_80472724(void* x)
{
    char* g = (char*)lbl_80619948->m58;
    fn_80124FA8(FeVp(x, 0x13C), x);
    fn_80125154(FeVp(x, 0x13C), 0);
    if (FeI(g, 0xCE4) != 0 && FeWp(x, 0x138) != 0) {
        if (FeWp(x, 0x138)->fn_vslot86() == 0)
            fn_801251CC(FeVp(x, 0x13C), 3, 0x1A2F, 1);
        else
            fn_801251CC(FeVp(x, 0x13C), 3, 0x37A2, 2);
    } else {
        fn_80125084(FeVp(x, 0x13C), 3);
    }
    if (FeWp(x, 0x140) != 0 && FeWp(x, 0x140)->fn_vslot59() > 0 && *fn_80548E2C(g, FeWp(x, 0x140)->fn_vslot60()) == 0) {
        fn_801251CC(FeVp(x, 0x13C), 0, 0x1C58, 4);
        fn_801251CC(FeVp(x, 0x13C), 2, 0x416D, 3);
    } else {
        fn_80125084(FeVp(x, 0x13C), 2);
        fn_80125084(FeVp(x, 0x13C), 0);
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

extern "C" FE_OVERLAY void fn_80472D24(void* x, int w)
{
    if (w == FeI(x, 0x140)) {
        fn_804726A0(x);
        int r = FeWp(x, 0x140)->fn_vslot60();
        if (FeWp(x, 0x138)->fn_vslot86() != 0 && r >= 0) {
            void* p = fn_80548E1C(lbl_80619948->m58, r);
            char* s = (char*)FeVp(x, 0x138);
            fn_80126CF4((FeList*)s, (int)p, FeI(s, 0x168), FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
        }
        fn_80472724(x);
    }
}

extern "C" FE_OVERLAY FeScrH* fn_80472E04(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678808);
    self->m130 = 0;
    FeI(self, 0x13C) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804730A4(void* x)
{
    int i = 0;
    int n = FeI(fn_800B555C(), 0x63C);
    for (; i < n; i++) {
        ((FeWV91*)FeWp(x, 0x134))->s91(i, 0, 0);
        ((FeWV91*)FeWp(x, 0x134))->s91(i, 1, 0);
        FeWp(x, 0x134)->fn_vslot73(i, 0)->fn_vslot32("DONE", 1)->fn_vslot8(1);
    }
    FeWp(x, 0x134)->fn_vslot67(i, 0);
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

extern "C" FE_OVERLAY void fn_80473440(void* x)
{
    int v = 0;
    int s = FeWp(x, 0x134)->fn_vslot60();
    FeI(fn_800B555C(), 0x63C) = s;
    fn_800B555C();
    if (fn_800B5758() != 0) {
        switch (s) {
        case 1:
            v = 0xE;
            break;
        case 2:
            v = 0xF;
            break;
        case 3:
            v = 0x10;
            break;
        case 4:
            v = 0x11;
            break;
        case 5:
            v = 0x12;
            break;
        case 6:
            v = 0x13;
            break;
        case 7:
            v = 0x14;
            break;
        }
    } else {
        switch (s) {
        case 1:
            v = 0xE;
            break;
        case 2:
            v = 0xF;
            break;
        case 3:
            v = 0x10;
            break;
        case 4:
            v = 0x11;
            break;
        case 5:
            v = 0x12;
            break;
        case 6:
            v = 0x13;
            break;
        }
    }
    fn_80449168((FePopup*)FeVp(x, 0x13C), v, x, (void (*)(void*))fn_80473630);
}

extern "C" FE_OVERLAY void fn_80473560(FeScrD* x)
{
    if (lbl_80619948->m80 == 10) {
        void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 15, t) == 0) {
            void* u = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, t);
            int w = fn_8007B8C4__18Unk8007B2B0_Screenii(lbl_8061930C, 0x37, u);
            fn_805819A4(FeVp(lbl_8061930C, 0x2C), u, w);
        }
    }
    fn_800B7ADC(FeGetMgr(), x);
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

extern "C" FE_OVERLAY void fn_80473684(int a, FeW* x)
{
    if (a != 0) {
        if (a == 1) {
            fn_800A2030(lbl_80619948, 1);
            x->fn_vslot80(1);
            fn_800B7ADC(FeGetMgr(), x);
        }
    }
}

extern "C" FE_OVERLAY int fn_80473718(void* x)
{
    int v = FeWp(x, 0x134)->fn_vslot60();
    return v > FeI(fn_800B555C(), 0x63C);
}

extern "C" FE_OVERLAY void fn_804739BC(FeW* x)
{
    int z = ((FeWV93*)FeWp(x, 0x134))->s93(4, 0) == 0;
    x->fn_vslot32("REQINFO", 1);
    FeW* w = fn_800C8044();
    if (z != 0) {
        fn_800E4C1C(fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0), w);
        w->fn_vslot8(1);
    } else {
        w->fn_vslot8(0);
    }
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

extern "C" FE_OVERLAY int fn_80473D44(void* x)
{
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    char* s = (char*)w + 0xC;
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, s, 15);
    p->name[15] = 0;
    int c = fn_8040B574(s, "GAMEPLAYOPTIONS");
    if (c == 0) {
        fn_800B555C();
        if (fn_800B5758() != 0) {
            fn_8040B830(p->name, "OM_GAMEPLAYOPTS", 15);
            p->name[15] = c;
        }
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
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

extern "C" FE_OVERLAY int fn_80473FA4(void* x)
{
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    char* s = (char*)w + 0xC;
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, s, 15);
    p->name[15] = 0;
    int c = fn_8040B574(s, "GAMEPLAYOPTIONS");
    if (c == 0) {
        fn_800B555C();
        if (fn_800B5758() != 0) {
            fn_8040B830(p->name, "OM_GAMEPLAYOPTS", 15);
            p->name[15] = c;
        }
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}
