/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C3ECC-0x804C713C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_804C4D18(FeScrN* x);
extern "C" void fn_804C4FA8(FeScrN* x);
extern "C" void fn_804C4E30(FeScrN* x);
extern "C" void fn_804C6918(FeScrN* x, int v);
extern "C" void fn_804C5F98(FeScrN* x);
extern "C" void fn_804C506C(FeScrN* x);
extern "C" void fn_804A77AC(FeW* w, int v);
extern "C" void fn_804C60F4(FeScrN* x, int v);
extern "C" void fn_804C6F08(FeScrN* x);
extern "C" void fn_804C4520(FeScrN* x);
extern "C" int fn_804C4608(FeScrN* x);
extern "C" int fn_804C4644(FeScrN* x);
extern "C" int fn_804C4680(FeScrN* x);
extern "C" int fn_804C46BC(FeScrN* x);
extern "C" int fn_804C474C(void);
extern "C" int fn_804C47A8(void);
extern "C" int fn_804C47B0(FeScrN* x);
extern "C" int fn_804C47F0(FeScrN* x, int a);
extern "C" int fn_804C482C(FeScrN* x);
extern "C" int fn_804C486C(FeScrN* x);
extern "C" void fn_804C4958(FeScrN* x);
extern "C" void fn_804C4B30(FeScrN* x, FeScrN* y);
extern "C" void fn_804C686C(FeScrN* x, int a);
extern "C" int fn_804C4DF4(FeScrN* x);
extern "C" void fn_804C6AA4(FeScrN* x);
extern "C" void fn_804C6368(FeScrN* x, int a);
extern "C" int fn_804C46F8(FeScrN* x);
extern "C" int fn_804C4754(FeScrN* x);
extern "C" void fn_804C68B4(FeScrN* x, int v);
extern "C" int fn_804C60A4(FeScrN* x);
extern "C" void fn_804C4B5C(int a, FeScrN* x);
extern "C" void fn_804C61B4(FeScrN* x, FeW* w);

extern "C" FE_OVERLAY void fn_804C4520(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_804C4608(FeScrN* x)
{
    x->m154->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C4644(FeScrN* x)
{
    x->m154->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C4680(FeScrN* x)
{
    x->m154->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C46BC(FeScrN* x)
{
    x->m154->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C46F8(FeScrN* x)
{
    if (x->m154 != x->m14C) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    fn_804C61B4(x, x->m14C);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C474C(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C4754(FeScrN* x)
{
    if (x->m154 != x->m150) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    fn_804C61B4(x, x->m150);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47A8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47B0(FeScrN* x)
{
    x->m158->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47F0(FeScrN* x, int a)
{
    x->m158->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C482C(FeScrN* x)
{
    x->m158->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C486C(FeScrN* x)
{
    x->m158->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_804C4958(FeScrN* x)
{
    fn_804C6AA4(x);
}

extern "C" FE_OVERLAY void fn_804C4B30(FeScrN* x, FeScrN* y)
{
    if (x != 0) {
        fn_804C4D18(y);
    }
}

extern "C" FE_OVERLAY void fn_804C4B5C(int a, FeScrN* x)
{
    if (a != 0) {
        fn_804C60F4(x, fn_804C60A4(x));
        if (x->m138 != 0) {
            fn_804C6F08(x);
        }
    }
}

extern "C" FE_OVERLAY int fn_804C4DF4(FeScrN* x)
{
    return ((FeSub*)((char*)x->m15C + 0xDC))->s5();
}

extern "C" FE_OVERLAY int fn_804C60A4(FeScrN* x)
{
    return FeAt((char*)x->m190, x->m14C->fn_vslot60());
}

extern "C" FE_OVERLAY void fn_804C61B4(FeScrN* x, FeW* w)
{
    x->m154->fn_vslot14(0);
    x->m154 = w;
    w->fn_vslot14(1);
    fn_804C6AA4(x);
}

extern "C" FE_OVERLAY void fn_804C6368(FeScrN* x, int a)
{
    if (a == (int)x->m158) {
        fn_804C4FA8(x);
        fn_804C4E30(x);
        fn_804C6AA4(x);
    }
}

extern "C" FE_OVERLAY void fn_804C686C(FeScrN* x, int a)
{
    fn_804C68B4(x, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, a));
}

extern "C" FE_OVERLAY void fn_804C68B4(FeScrN* x, int v)
{
    ((FeSubV*)((char*)x->m188 + 0x98))->s20(v, 0);
    fn_804A77AC(x->m168, v);
    fn_804C4FA8(x);
}

extern "C" FE_OVERLAY void fn_804C6AA4(FeScrN* x)
{
    fn_804C6918(x, fn_804C4DF4(x));
    fn_804C5F98(x);
    fn_804C506C(x);
}
