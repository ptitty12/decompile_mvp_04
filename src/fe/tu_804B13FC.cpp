/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B13FC-0x804B38C4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" FE_OVERLAY void fn_804B2B18(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}


extern "C" FE_OVERLAY int fn_804B13FC(void) { return 0; }

extern "C" FE_OVERLAY void fn_804B1D20(FeScr* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_804B2564(FeScr* x)
{
    x->m140->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2610(FeScr* x)
{
    x->m140->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B264C(FeScr* x)
{
    x->m140->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2688(FeScr* x)
{
    x->m140->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B26C4(FeScr* x)
{
    x->m140->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2700(FeScr* x)
{
    x->m140->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3774(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3820(FeScr* x)
{
    x->m134->v51();
    return 1;
}











extern "C" FE_OVERLAY int fn_804B24F4(FeScr* x)
{
    ((FeObj*)x->m140)->v52();
    fn_804B1E70(x, ((FeObjI*)x->m140)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B25A0(FeScr* x)
{
    ((FeObj*)x->m140)->v50();
    fn_804B1E70(x, ((FeObjI*)x->m140)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3704(FeScr* x)
{
    ((FeObj*)x->m134)->v52();
    fn_804B2B40(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B37B0(FeScr* x)
{
    ((FeObj*)x->m134)->v50();
    fn_804B2B40(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY void fn_804B3234(int a, int b)
{
    if (a == 1)
        fn_804B3260(b);
}

/* near-miss: retail keeps the element offset in its own register (addi 12 per step) and recomputes the base; 12 slots differ */
extern "C" FE_OVERLAY void fn_804B1D48(FeScr* x, int v)
{
    FI(x, 0x150) = 1;
    int i;
    int o = 0;
    for (i = 0; i <= 12; i++) {
        int k = o;
        o += 12;
        if (FI(x, 0x158 + k) == v)
            break;
    }
    fn_804B1E70(x, i);
}


extern "C" FE_OVERLAY void fn_804B24AC(int a, FeObj* w)
{
    if (a == 1)
        ((FeObj2*)w)->v67(0, 0);
}

extern "C" FE_OVERLAY void fn_804B1DA0(FeScr* x, int a)
{
    ((FeObj1*)FeP(x, 0x15C))->v8(a ^ 1);
    ((FeObj1*)x->m13C)->v8(a);
    FeObj* r = (FeObj*)((FeObjP2*)x->m140)->v73(0, 0);
    ((FeObj1*)((FeObj*)r)->v32("BUTTON", 1))->v8(a);
}

extern "C" FE_OVERLAY void fn_804B23D8(FeScr* x)
{
    fn_804B243C((FeScr*)(void*)fn_800B7AB8(UiGetMsgMgr(), "CSSETUP"), (int)x);
}
