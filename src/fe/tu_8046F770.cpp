/*
 * Front-end overlay code, .frontend_codeoverlay 0x8046F770-0x80471EBC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"
extern "C" {
void fn_800DC50C__FP3UiSff(int a, float b, float c);
}

extern "C" {

FE_OVERLAY FeScrK* fn_8046F770(FeScrK* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80679128);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8046F7BC(FeScrK* x)
{
    fn_800ECE34(x);
    fn_800E49A4();
}

FE_OVERLAY void fn_8046FAC8(FeScrK* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_8046FAE8(FeScrK* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8046FB08(void) {}

FE_OVERLAY void fn_8046FB0C(void) {}

FE_OVERLAY void fn_8046FB10(void) {}

FE_OVERLAY int fn_8046FB14(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY int fn_8046FB80(FeScrK* x)
{
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY int fn_8046FBDC(FeScrK* x)
{
    x->m134->fn_vslot56();
    return 1;
}

FE_OVERLAY int fn_8046FC18(FeScrK* x)
{
    x->m134->fn_vslot57();
    return 1;
}

FE_OVERLAY int fn_8046FC54(FeScrK* x)
{
    x->m134->fn_vslot54();
    return 1;
}

FE_OVERLAY int fn_8046FC90(FeScrK* x)
{
    x->m134->fn_vslot55();
    return 1;
}

FE_OVERLAY int fn_8046FCCC(FeScrK* x, FeW* w)
{
    int r;
    if (w == x->m134) {
        fn_800B7ADC(FeGetMgr(), x);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

FE_OVERLAY FeScrL* fn_8046FED8(FeScrL* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, 0, c, d, e, f, g, h);
    self->SetVptr(lbl_80678D58);
    self->m2DC = 0;
    self->m2E0 = 0;
    self->m2E4 = 0;
    self->m2E8 = 1;
    self->m2EC = 0;
    self->m2F0 = 0;
    self->m2F4 = 0;
    self->m2F8 = 0;
    self->m2FC = 0;
    self->m300 = 0;
    self->m30C = 0;
    self->m310 = 0;
    self->m314 = 1;
    self->m318 = 0;
    self->m31C = 0;
    self->m320 = 0;
    self->m324 = 0;
    self->m328 = 0;
    self->m32C = lbl_805F5BEC;
    self->m330 = 0;
    self->m334 = 0;
    self->m338 = 0;
    self->m33C = -1;
    self->m340 = 0;
    self->m344 = 0;
    self->m348 = 0;
    self->m34C = 0;
    self->m350 = 0;
    self->m354 = 0;
    self->m358 = 0x1BC9;
    return self;
}

FE_OVERLAY void fn_80470404(FeScrL* x, int a, int b, int c, int d, int e)
{
    x->m318 = a;
    x->m314 = 0;
    fn_800A29C4(lbl_80619948, a);
    x->m330 = 1;
    fn_80470E30(x, b, c, d, e);
}

FE_OVERLAY void fn_80470478(FeScrL* x, int a, int b, int c, int d, int e)
{
    int v = a + 1;
    x->m314 = 1;
    x->m318 = v;
    fn_800A29C4(lbl_80619948, v);
    x->m330 = 1;
    fn_80470E30(x, b, c, d, e);
}

FE_OVERLAY void fn_804704EC(FeScrL* x, int a, int b, int c, int d)
{
    x->m314 = 3;
    fn_800A2948(lbl_80619948, a);
    x->m330 = 1;
    fn_80470E30(x, a, b, c, d);
}

FE_OVERLAY void fn_80470558(FeScrL* x, int a, int b, int c, int d)
{
    x->m314 = 4;
    int v;
    if (b != 0) {
        v = fn_800C2208((char*)fn_800B555C() + 8);
    } else {
        v = fn_800A2AE8(lbl_80619948);
    }
    int w = v + 1;
    x->m318 = w;
    fn_800A29C4(lbl_80619948, w);
    x->m330 = 1;
    fn_80470E30(x, a, b, c, d);
}

/* near-miss: 8 slots; same constant register swap as fn_804707B8 */
FE_OVERLAY void fn_80470710(FeScrL* x, int a)
{
    FeGlobal80619948* g = lbl_80619948;
    x->m324 = a;
    x->m334 = 0;
    x->m338 = 1;
    int v = fn_800A2AE8(g);
    x->m318 = v;
    fn_800A29C4(g, v);
    x->m330 = 5;
    x->m314 = 0xD;
    x->fn_vslot89(0);
    x->fn_vslot8(0);
}

/* near-miss: 4 slots; retail puts the 0 in r9 and the 1 in r0 (we swap them); all 120 store orders tried */
FE_OVERLAY void fn_804707B8(FeScrL* x, int a)
{
    x->m334 = 0;
    x->m338 = 1;
    x->m324 = a;
    x->m314 = 0xD;
    x->m330 = 4;
    x->fn_vslot89(0);
    x->fn_vslot8(0);
}

FE_OVERLAY void fn_8047083C(FeScrL* x)
{
    switch (x->m314) {
    case 0:
    case 1:
    case 4:
        fn_800A29C4(lbl_80619948, x->m318);
        break;
    case 5:
        fn_800A29C4(lbl_80619948, x->m318);
        x->m330 = 1;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    case 3:
        ((void (*)(FeGlobal80619948*))fn_800A2948)(lbl_80619948);
        break;
    case 13:
        x->fn_vslot8(0);
        fn_800A29C4(lbl_80619948, x->m318);
        break;
    }
}

/* near-miss: store/load order of the m338/m328/m324 group differs */
FE_OVERLAY void fn_80470E30(FeScrL* x, int a, int b, int c, int d)
{
    FeGlobal80619948* g = lbl_80619948;
    x->m338 = b;
    x->m328 = g->m8C;
    x->m324 = d;
    x->m334 = 0;
    if (x->m33C != a) {
        x->m33C = a;
        fn_8047091C(x);
    }
    fn_80470C08(x, c);
    x->fn_vslot89(0);
    if (x->m314 != 5) {
        x->fn_vslot116();
    }
}

FE_OVERLAY int fn_80470EDC(FeScrL* x)
{
    if (lbl_80619948->m74 != 2 && (unsigned)x->m314 <= 1) {
        fn_80471D8C(x);
    }
    return 1;
}

FE_OVERLAY void fn_80470F20(FeScrL* x)
{
    x->m330 = 0;
    x->fn_vslot89(1);
    if (x->m334 == 0 && x->m338 == 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
    }
    if (x->m30C != 0) {
        x->m30C(x->m334, x->m324);
    }
}

FE_OVERLAY void fn_80471830(FeScrL* x)
{
    float f;
    int lo = x->m328;
    FeGlobal80619948* g = lbl_80619948;
    int cur = g->m84;
    int hi = g->m90;
    if (lo != hi) {
        f = (float)(cur - lo) / (float)(hi - lo);
    } else {
        f = 1.0f;
    }
    if (!(f >= 0.0f)) {
        f = 0.0f;
    }
    if (!(f <= 1.0f)) {
        f = 1.0f;
    }
    fn_800DC50C__FP3UiSff(x->m34C, x->m32C, f);
}

FE_OVERLAY void fn_80471910(FeScrL* x)
{
    x->fn_vslot8(0);
}

FE_OVERLAY void fn_80471948(FeScrL* x)
{
    FeObj138* w = (FeObj138*)fn_800B7A94(FeGetMgr(), lbl_805F5CB8);
    if (w != 0) {
        w->m138 = 1;
    }
    x->fn_vslot8(1);
}

FE_OVERLAY void fn_804719D0(FeScrL* x)
{
    FeW* w = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4ED4);
    if (w != 0) {
        w->fn_vslot39();
    }
    fn_800EAC30(x);
}

FE_OVERLAY int fn_80471D30(FeScrL* x, FeEvt* e)
{
    if (e->m1C == 3) {
        if (fn_8040B574(e->name, lbl_805F5D84) == 0) {
            fn_80471D8C(x);
        }
    }
    return 0;
}

FE_OVERLAY void fn_80471D8C(FeScrL* x)
{
    fn_8001BC4C()->fn_8001BDAC(0xA0);
    fn_800A2B10(lbl_80619948);
    x->m334 = 1;
}

FE_OVERLAY void fn_80471DD4(FeScrL* x, int k)
{
    if (k == 0xD || k == 7) {
        if (x->m310 != 0) {
            x->m310();
        }
    }
}

FE_OVERLAY void fn_80471E14(FeScrL* x, int k)
{
    if (k == 0xD || k == 7) {
        if (x->m310 != 0) {
            x->m310();
        }
    }
    fn_80471D8C(x);
}

FE_OVERLAY void fn_80471E68(FeScrL* x, int k)
{
    if (k == 0xD || k == 7) {
        if (x->m310 != 0) {
            x->m310();
        }
    }
    fn_8047083C(x);
}

}
