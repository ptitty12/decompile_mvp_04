/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B985C-0x804BB110 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" FE_OVERLAY void fn_804B98F8(FeScr* x)
{
    fn_804B47C0(x);
}

extern "C" FE_OVERLAY void fn_804B9918(FeScr* x)
{
    fn_804B5FC4(x);
}

extern "C" FE_OVERLAY void fn_804B9C08(FeScr* x)
{
    fn_804B6108(x);
}

extern "C" FE_OVERLAY void fn_804B9EA0(FeScr* x)
{
    fn_804B47C0(x);
}

extern "C" FE_OVERLAY void fn_804B9EC0(FeScr* x)
{
    fn_804B5FC4(x);
}

extern "C" FE_OVERLAY void fn_804BA2D8(FeScr* x)
{
    fn_804B6108(x);
}

extern "C" FE_OVERLAY void fn_804BA52C(FeScr* x)
{
    fn_804B7D2C(x);
}

extern "C" FE_OVERLAY void fn_804BA54C(FeScr* x)
{
    fn_804B7E24(x);
}

extern "C" FE_OVERLAY void fn_804B9938(FeScr* x)
{
    fn_804B4908(x);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER1", 1)))->v29(22400);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER2", 1)))->v29(22401);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER3", 1)))->v29(22402);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER4", 1)))->v29(22403);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER5", 1)))->v29(22404);
}


extern "C" FE_OVERLAY void fn_804B9EE0(FeScr* x)
{
    fn_804B4908(x);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER1", 1)))->v29(22410);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER2", 1)))->v29(22401);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER3", 1)))->v29(22409);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER4", 1)))->v29(22403);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER5", 1)))->v29(22404);
}

extern "C" FE_OVERLAY int fn_804B9E6C(void)
{
    if (fn_800B555C()->m0 == 0x5C)
        return 2;
    return 1;
}

extern "C" FE_OVERLAY int fn_804BB0DC(void)
{
    if (fn_800B555C()->m0 == 0x5C)
        return 0xB;
    return 0xA;
}

extern "C" FE_OVERLAY void fn_804BAB14(int a, FeScr* x)
{
    if (a == 1)
        ((FeObj2*)x)->v91(((FeObjI*)x->m134)->v60(), FI(x, 0x148));
}

