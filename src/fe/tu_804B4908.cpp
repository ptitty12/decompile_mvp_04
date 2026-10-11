/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B4908-0x804B7C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" FE_OVERLAY void fn_804B4BC4(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}


extern "C" FE_OVERLAY int fn_804B722C(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B73C4(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B77BC(FeScr* x)
{
    x->m13C->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B786C(FeScr* x)
{
    x->m13C->v41();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B52E4(FeScr* x)
{
    fn_80125154(x->m144, 0);
}

extern "C" FE_OVERLAY void fn_804B7948(void)
{
    fn_8057CF60(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), 0);
}

extern "C" FE_OVERLAY int fn_804B70D0(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    ((FeObj*)x->m134)->v52();
    ((FeObj*)x)->v87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7268(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    ((FeObj*)x->m134)->v50();
    ((FeObj*)x)->v87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B74FC(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B76A0(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    return 1;
}
