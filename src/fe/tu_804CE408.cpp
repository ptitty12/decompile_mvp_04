/*
 * Front-end overlay code, .frontend_codeoverlay 0x804CE408-0x804D08D0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" FeSlot44* fn_804CF92C(FeScrM* x, int a);
extern "C" void fn_804D2310();
extern "C" void fn_80330BC8(void* x);
extern "C" int fn_804CEBAC(FeScrM* x, int* out);
extern "C" void fn_804CE7F0(FeScrM* x, int v);

extern "C" FE_OVERLAY void fn_804CEC64(FeScrM* x)
{
    int sp8;
    fn_80330BC8(x);
    if (fn_804CEBAC(x, &sp8) != 0) {
        fn_804CE7F0(x, sp8);
    }
}

extern "C" FE_OVERLAY void fn_804CEEF0(FeScrM* x)
{
    if (x->m998 != 0) {
        fn_80377488(x->m998);
        x->m998 = 0;
        x->m99C = 0;
    }
}

extern "C" FE_OVERLAY int fn_804CF884(FeScrM* x, int a)
{
    if (a == x->m188.m38 || a == x->m144.m38) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804CF908(FeScrM* x, int a)
{
    fn_804CF92C(x, a);
    fn_804D2310();
}

extern "C" FE_OVERLAY FeSlot44* fn_804CF92C(FeScrM* x, int a)
{
    FeSlot44* p = &x->m188;
    if (p->m38 == a) {
        return p;
    }
    return &x->m144;
}

extern "C" FE_OVERLAY int fn_804D0308(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804D0310(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804D0510(FeScrM* x, int a)
{
    if (a == 1) {
        FeW* p = x->m1CC;
        if (p != 0) {
            return p->b0;
        }
    } else if (a == 0) {
        FeW* p = x->m1D0;
        if (p != 0) {
            return p->b0;
        }
    }
    return 0;
}
