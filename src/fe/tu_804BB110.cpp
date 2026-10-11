/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BB110-0x804BE560 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern char lbl_80671440[];
extern "C" FE_OVERLAY FeRaw* fn_804BD37C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80671440;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804BDFB4(FeScr* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY int fn_804BDC68(FeScr* x)
{
    x->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BDCA4(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BDCE0(FeScr* x)
{
    x->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BDD1C(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804BB40C(FeScr* x, int a, int b)
{
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("XAXIS", 1)))->v29(a);
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("YAXIS", 1)))->v29(b);
}

extern "C" FE_OVERLAY void fn_804BB4CC(FeScr* x, int a, int b)
{
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("XAXIS", 1)))->v30(a);
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("YAXIS", 1)))->v30(b);
}

extern "C" FE_OVERLAY void fn_804BB58C(FeScr* x, int a, int b)
{
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("XAXIS", 1)))->v28(a);
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("YAXIS", 1)))->v28(b);
}

extern "C" FE_OVERLAY void fn_804BDDC8(FeScr* x)
{
    fn_800ECE34(x);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)fn_800C8044(((FeObj*)x)->v32("ASSETGRID", 1)))->v32("GRID", 1));
    x->m138 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
    ((FeObj1*)x->m134)->v105(1);
    ((FeObj1*)x->m134)->v88(0);
}

extern "C" FE_OVERLAY void fn_804BD3D0(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* t1 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    x->m138 = (FeObj*)t1;
    fn_80124FA8(t1, x);
    ((FeFnOIII)fn_801251CC)(x->m138, 1, 6668, 0);
    ((FeFnOIII)fn_801251CC)(x->m138, 0, 22525, 1);
    ((FeFnOIII)fn_801251CC)(x->m138, 2, 23705, 3);
    FeObj* t7 = fn_800C8060(((FeObj*)x)->v32("GRID", 1));
    x->m134 = (FeObj*)t7;
    ((FeObj1*)t7)->v105(1);
    fn_804BD4D0(x, 0);
}


extern "C" FE_OVERLAY void fn_804BDEB4(FeScr* x)
{
    fn_800ECF18(x);
    fn_800DD204(fn_800C8040(((FeObj*)x)->v32("TITLE", 1)), fn_800C8038(((FeObj*)x)->v32("SH1", 1)));
    FeObj* t6 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    x->m13C = (FeObj*)t6;
    fn_80124FA8(t6, x);
    ((FeObj*)x)->v84();
    ((FeObj*)x)->v87();
}
