/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B7C98-0x804B985C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" FE_OVERLAY void fn_804B7FBC(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_80672DC0[];
extern "C" FE_OVERLAY FeRaw* fn_804B8820(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80672DC0;
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern char lbl_80672B18[];
extern "C" FE_OVERLAY FeRaw* fn_804B8BE4(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80672B18;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B8CFC(FeScr* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_804B9138(FeScr* x)
{
    fn_804B7D2C(x);
}

extern "C" FE_OVERLAY void fn_804B9158(FeScr* x)
{
    fn_804B7E24(x);
}


extern "C" FE_OVERLAY int fn_804B8748(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B87E4(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8AF4(FeScr* x)
{
    x->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8B30(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8B6C(FeScr* x)
{
    x->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8BA8(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B8D1C(void) {}

extern "C" FE_OVERLAY int fn_804B8D8C(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8DE8(FeScr* x)
{
    x->m134->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8E24(FeScr* x)
{
    x->m134->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8E60(FeScr* x)
{
    x->m134->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8E9C(FeScr* x)
{
    x->m134->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8ED8(FeScr* x)
{
    x->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8F14(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8F50(FeScr* x)
{
    x->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8F8C(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B86E8(FeScr* x)
{
    ((FeObj*)x->m134)->v52();
    ((FeObj*)x)->v89();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8784(FeScr* x)
{
    ((FeObj*)x->m134)->v50();
    ((FeObj*)x)->v89();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B8870(FeScr* x)
{
    fn_800ECE34(x);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("MENU", 1));
}



extern "C" FE_OVERLAY void fn_804B927C(FeScr* x)
{
    fn_804B83A4(x);
    fn_800C4AC8(fn_800C33D0(), fn_800C8038(((FeObj*)x->m138)->v32("PIC", 1)), ((FeObjI*)x->m134)->v60());
    ((FeObj*)x)->v90();
    ((FeObj*)x)->v88();
}

extern "C" FE_OVERLAY void fn_804B8C30(FeScr* x)
{
    fn_800ECE34(x);
    fn_800E49A4();
}

extern "C" FE_OVERLAY void fn_804B9740(int a, FeObj* w)
{
    if (a == 1)
        w->v93();
}

extern "C" FE_OVERLAY void fn_804B8C54(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* t1 = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(t1, x);
    fn_80125100(t1);
    fn_801250D8(t1);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("GRID", 1));
}

extern "C" FE_OVERLAY void fn_804B88C8(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(p, x);
    ((FeFnOI)fn_80125154)(p, 0);
    ((FeFnOI)fn_80125128)(p, 1);
    if (fn_800A2E6C(lbl_80619948) != 0)
        ((FeObj3*)x->m134)->v91(3, 0, 0);
}

extern "C" FE_OVERLAY int fn_804B8FC8(FeScr* x, int v)
{
    if (v == FI(x, 0x134)) {
        fn_800B7ADC(UiGetMsgMgr(), x);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804B85E4(FeScr* x)
{
    for (int i = 0; i < ((FeObjI*)x->m134)->v59(); i++) {
        if (fn_80593E8C(x->m140, i) == 0) {
            ((FeObj2*)x->m134)->v100(i, 1);
            ((FeObj2*)x->m134)->v101(i, 1);
        } else if (fn_80593EB0(x->m140, i, 1) != 0) {
            ((FeObj2*)x->m134)->v100(i, 0);
            ((FeObj2*)x->m134)->v101(i, 1);
        } else {
            ((FeObj2*)x->m134)->v101(i, 0);
        }
    }
}

extern "C" FE_OVERLAY void fn_804B977C(FeScr* x)
{
    int a = ((FeObjI*)x->m134)->v60();
    FeObj* o = x->m140;
    fn_804B8570(x, a, fn_80593E7C(o, ((FeObjI*)x->m134)->v60()) > 0);
    ((FeObj*)x)->v87();
    ((FeObj1*)x->m134)->v14(1);
    ((FeObj*)x)->v89();
}

extern "C" FE_OVERLAY void fn_804B8570(FeScr* x, int a, int b)
{
    if (b != 0) {
        ((FeV1C*)x->m140)->s3(a, 1);
    } else {
        ((FeV1C*)x->m140)->s2(a, 1, -1.0f, -1.0f);
    }
}

extern "C" FE_OVERLAY void fn_804B7FE4(FeScr* x)
{
    ((FeObjS79*)x->m134)->v79(FI(x->m140, 0x14), 0);
    x->m134->v3();
}

extern "C" FE_OVERLAY void fn_804B9178(FeScr* x)
{
    int i = 0;
    fn_804B7FE4(x);
    while (i < FI(x->m140, 0x14)) {
        ((FeObjS86*)x)->v86(0, x->m134, i, 0, i);
        ((FeObjS86*)x)->v86(1, x->m134, i, 1, i);
        ((FeObjS86*)x)->v86(3, x->m134, i, 2, i);
        i++;
    }
    ((FeObj*)x)->v87();
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY int fn_804B8D20(FeObj* x)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_800B7B4C(UiGetMsgMgr(), p, x);
    return 1;
}

extern "C" FE_OVERLAY void fn_804B9038(FeScr* x, char* dst)
{
    fn_8040B830(dst, ((FeObjQ*)((FeObjQ*)x->m134)->v70())->v33(5, 1)->name, 16);
}

extern "C" FE_OVERLAY void fn_804B933C(FeScr* x)
{
    FeObj* l = x->m140;
    ((FeObj1*)fn_800C8040(((FeObj*)x->m138)->v32("NAME", 1)))->v29(FI(fn_80594240(x->m140, ((FeObjI*)x->m134)->v60()), 0x10));
    ((FeObj1*)fn_800C8040(((FeObj*)x->m138)->v32("PROS", 1)))->v29(FI(fn_80593B68(l, ((FeObjI*)x->m134)->v60()), 0));
}
