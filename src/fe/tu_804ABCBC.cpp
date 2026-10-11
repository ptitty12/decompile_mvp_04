/*
 * Front-end overlay code, .frontend_codeoverlay 0x804ABCBC-0x804AECD0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" FE_OVERLAY int fn_804ABCBC(FeSc1* x)
{
    x->m138->v56();
    x->m140 = (x->m140 + 3) % 4;
    fn_804AC564(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804ABD30(FeScr* x)
{
    x->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804ABD6C(FeSc1* x)
{
    x->m138->v54();
    x->m140 = (x->m140 + 1) % 4;
    fn_804AC564(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804ABDE0(FeScr* x)
{
    x->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804AC060(int a, FeSc1* x)
{
    switch (a) {
    case 0:
        fn_804ABF48(x, 0);
        break;
    case 1:
        fn_804ABF48(x, 1);
        break;
    case 2:
        break;
    }
}

extern "C" FE_OVERLAY void fn_804AC0AC(int a, FeSc1* x)
{
    if (a != 0) {
        if (a == 1)
            fn_804AC114(x);
    }
}

extern "C" FE_OVERLAY void fn_804AC0E0(int a, FeSc1* x)
{
    if (a != 0) {
        if (a == 1)
            fn_804AC1C0(x);
    }
}

extern "C" FE_OVERLAY void fn_804AC114(FeSc1* x)
{
    int idx = ((FeObjI*)x->m134)->v60();
    int id = x->m144[idx];
    if (idx > 0) {
        if (((FeObjI*)x->m134)->v59() - 1 > 0)
            x->m1C8 = idx - 1;
    }
    fn_8058200C(((FeScrMgrView*)lbl_8061930C)->m2C, id);
    fn_804AC564(x);
    fn_804ACA20(x);
}

extern "C" FE_OVERLAY void fn_804AC1C0(FeSc1* x)
{
    FeObj* list = x->m134;
    Unk8007B2B0_Screen* mgr = lbl_8061930C;
    FeGame* game = lbl_80619948;
    int h = ((FeScrMgrView*)mgr)->m2C;
    int n = ((FeObjI*)list)->v59();
    int lvl = fn_800A2AE8(game);
    for (int i = 0; i < n; i++) {
        int id = x->m144[i];
        if (fn_8008007C((Unk8007FF8C_G*)mgr, id)->m10 < lvl)
            fn_8058200C(h, id);
    }
    fn_804AC564(x);
    fn_804ACA20(x);
}

extern "C" FE_OVERLAY void fn_804AC280(FeSc1* x)
{
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_804AC348, 0, 0, 3, -1, 1, 0x1D0F, 0x1D0E, 0x26DF, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AC348(int a, FeSc1* x)
{
    switch (a) {
    case 0: {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "REQUEST", 15);
        p->name[15] = 0;
        ((FeObj1*)x)->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
        break;
    }
    case 1: {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "FREQUENCY", 15);
        p->name[15] = 0;
        ((FeObj1*)x)->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
        break;
    }
    case 2:
        break;
    }
}

extern "C" FE_OVERLAY void fn_804AC478(FeSc1* x, int a)
{
    switch (a) {
    case 0: {
        FeBase8* b = (FeBase8*)((char*)fn_800B555C() + 8);
        UiMsg m;
        UiMsg* p = &m;
        fn_800C2034(b, b->m38);
        b->m70 = a;
        b->m6C = a;
        fn_800C2088(b, 1, x->m1C4);
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = a;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
    case 2:
        fn_804ABE1C(x);
        break;
    case 3:
        fn_804AC280(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804ACAFC(int unused, int k)
{
    int r = 0;
    switch (k) {
    case 0:
        r = 0x45BE;
        break;
    case 1:
        r = 0x1F9B;
        break;
    case 2:
        r = 0x1D59;
        break;
    case 3:
        r = 0x45BF;
        break;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804AD830(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804AE128(int unused, int a)
{
    char buf[100];
    lbl_8061930C->fn_8007BC64(0, a, buf);
    fn_800736EC(buf);
}

extern "C" FE_OVERLAY void fn_804AE300(int a, FeObj* w)
{
    if (a != 0) {
        if (a == 1) {
            ((FeSt68*)fn_800B555C())->m68 = a;
            ((FeObj1*)w)->v80(1);
            ((FeObj2*)w)->v67(0, 0);
        }
    }
}

extern "C" FE_OVERLAY void fn_804AE47C(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_804AE300, 0, 0x1D3E, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE660(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_805291C8, 0, 0x1CED, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE71C(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_805291C8, 0, 0x1CEE, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE920(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_805291C8, 0, 0x1CEA, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AD040(FeScr* x)
{
    fn_800ECE34(x);
    x->m138 = (FeObj*)fn_800B7AB8(UiGetMsgMgr(), "PLAYERINFOBAR");
}
