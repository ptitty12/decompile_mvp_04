/*
 * Front-end overlay code, .frontend_codeoverlay 0x80464090-0x804654A0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY void fn_804642AC(FeScrF* x)
{
    fn_800ECAA4(x);
    if (fn_80360ED8(x->m144 + 0xCE8) != 0) {
        if (lbl_8061A328 % 5 == 0) {
            fn_80548EC0(x->m144);
        }
    }
}

FE_OVERLAY void fn_80464324(FeScrF* x, int a)
{
    fn_800ED310(x, a);
    if (a != 0) {
        x->m138->fn_vslot14(1);
    } else {
        x->m138->fn_vslot14(0);
    }
}

FE_OVERLAY void fn_804647CC(FeScrF* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    fn_80131F34(p, x, fn_8046488C, 0, 0x46B2, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_8046488C(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            if (lbl_80619948->m80 == 0x13) {
                fn_80464AF0(x);
                return;
            }
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F5284, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
            fn_8054899C(lbl_80619948->m58);
        }
    }
}

FE_OVERLAY void fn_8046494C(FeScrF* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    fn_80131F34(p, x, fn_80464A0C, 0, 0x4846, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_80464AF0(void* x)
{
    fn_80449168(fn_800B7AB8(FeGetMgr(), lbl_805F528C), 0x13, x, fn_80464B60);
}

FE_OVERLAY void fn_80464B60(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F5284, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
    fn_8054899C(lbl_80619948->m58);
}

FE_OVERLAY void fn_80464BF4(FeScrF* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    x->m140 = x->m140 + 1;
    fn_800B555C()->m638 = x->m140;
    fn_80548E68(x->m144, x->m140);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_80464C94;
    fn_8049AB94(p);
}

FE_OVERLAY void fn_80464C94()
{
    fn_8046468C(fn_800B7AB8(FeGetMgr(), lbl_805F5894));
}

FE_OVERLAY void fn_80464CF0()
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_80464D68;
    fn_8049ABD4(p);
}

FE_OVERLAY void fn_80464D68()
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F5894);
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F5284, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, p);
}

FE_OVERLAY int fn_80464E1C(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_80464E58(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_80464E94(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_80464ED0(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_80464F0C(FeScrF* x, FeW* w, int b, int c)
{
    int r;
    if (w != x->m138) {
        r = 0;
    } else {
        x->fn_vslot67(c, 0);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_80464F64(FeScrF* x)
{
    x->fn_vslot80(0);
    x->fn_vslot67(x->m138->fn_vslot60(), 0);
    return 1;
}

FE_OVERLAY FeScrG* fn_80464FF0(FeScrG* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x26, lbl_8062167C);
    self->SetVptr(lbl_80679BF0);
    return self;
}

FE_OVERLAY void fn_80465058(FeScrG* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0xC1B);
    x->m13C = 1;
    x->fn_vslot87();
}

FE_OVERLAY void fn_804650B0(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

FE_OVERLAY void fn_804650F4(FeScrG* x)
{
    fn_804D32A0(x);
    int one = 1;
    lbl_8061A308 = one;
}

FE_OVERLAY FeScrG* fn_80465120(FeScrG* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x26, lbl_80621714);
    self->SetVptr(lbl_80679920);
    return self;
}

FE_OVERLAY void fn_80465188(FeScrG* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0xC1B);
    x->m13C = 1;
    x->fn_vslot87();
}

FE_OVERLAY void fn_804651E0(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

FE_OVERLAY void fn_80465224(FeScrG* x)
{
    fn_804D32A0(x);
    int one = 1;
    lbl_8061A308 = one;
}

FE_OVERLAY FeScrH* fn_80465250(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80679678);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8046529C(FeScrH* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_804652BC(FeScrH* x)
{
    fn_800ECF18(x);
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    fn_801250D8(w);
}

FE_OVERLAY void fn_80465330(FeScrH* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_80465350(FeScrH* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_80465370(void) {}
FE_OVERLAY void fn_80465374(void) {}
FE_OVERLAY void fn_80465378(void) {}

FE_OVERLAY int fn_8046537C(FeScrH* x)
{
    fn_800A2030(lbl_80619948, 1);
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY int fn_804653E8(void) { return 0; }

FE_OVERLAY void fn_804653F0(int a, char* dst)
{
    fn_8040B830(dst, lbl_805F3CA8, 16);
}

FE_OVERLAY FeScrI* fn_80465420(FeScrI* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80681C88);
    self->m130 = 0;
    self->m16C = 0;
    self->m208 = 0;
    self->m20C = 0;
    self->m210 = 1;
    return self;
}

FE_OVERLAY void fn_80465480(FeScrI* x)
{
    fn_800ECE34(x);
}

}
