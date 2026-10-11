/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B38C4-0x804B4908 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" FE_OVERLAY void fn_804B39EC(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_8066AF90[];
extern "C" FE_OVERLAY FeRaw* fn_804B3DB8(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066AF90;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B3E0C(FeScr* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804B3F74(FeScr* x)
{
    fn_800ED254(x);
}

extern char lbl_8066A4F0[];
extern "C" FE_OVERLAY FeRaw* fn_804B41AC(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066A4F0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B4570(FeScr* x)
{
    fn_800E49DC(x);
}


extern "C" FE_OVERLAY int fn_804B3CD0(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3D7C(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B3F94(void) {}

extern "C" FE_OVERLAY void fn_804B3F98(void) {}

extern "C" FE_OVERLAY void fn_804B3F9C(void) {}

extern "C" FE_OVERLAY int fn_804B4118(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B4174(void) { return 0; }





extern "C" FE_OVERLAY void fn_804B43C8(FeScr* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 22331);
}

extern "C" FE_OVERLAY void fn_804B4680(FeScr* x)
{
    ((FeObj1*)x)->v80(1);
    fn_804B44AC(x);
}








extern "C" FE_OVERLAY int fn_804B3C60(FeScr* x)
{
    ((FeObj*)x->m134)->v52();
    fn_804B3A14(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3D0C(FeScr* x)
{
    ((FeObj*)x->m134)->v50();
    fn_804B3A14(x, ((FeObjI*)x->m134)->v60());
    return 1;
}




extern "C" FE_OVERLAY void fn_804B3954(FeScr* x)
{
    fn_800ECF18(x);
    fn_804B3A14(x, 0);
    FeObj* t2 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(t2, x);
    ((FeFnOI)fn_80125154)(t2, 0);
    ((FeFnOIII)fn_801251CC)(t2, 0, 16, 1);
}


extern "C" FE_OVERLAY void fn_804B41F8(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* t1 = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(t1, x);
    ((FeFnOI)fn_80125154)(t1, 0);
}

extern "C" FE_OVERLAY void fn_804B4600(void)
{
    FeObj* t0 = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    ((FeObj1*)t0)->v85(0);
    FI(t0, 0x314) = 1;
}


extern "C" FE_OVERLAY void fn_804B38C4(FeScr* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("MENU", 1));
    x->m138 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
}

extern "C" FE_OVERLAY void fn_804B417C(int unused, char* dst)
{
    fn_8040B830(dst, "", 16);
}

extern "C" FE_OVERLAY void fn_804B47C0(FeScr* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->m140 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)fn_800C8044(((FeObj*)x)->v32("PRICEGRID", 1)))->v32("GRID", 1));
    FeObj* t10 = fn_800C8044(((FeObj*)x)->v32("TOPRIGHT", 1));
    x->m138 = (FeObj*)t10;
    x->m13C = (FeObj*)fn_800C805C(((FeObj*)t10)->v32("SUBSECTION", 1));
    ((FeObj1*)x->m134)->v105(1);
    ((FeObj*)x)->v84();
}
