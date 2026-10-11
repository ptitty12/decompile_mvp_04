/*
 * Front-end overlay code, .frontend_codeoverlay 0x8048511C-0x80488CDC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY void fn_804851B0(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

extern "C" FE_OVERLAY void fn_80485944(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_80485C28(void* x)
{
    if (fn_80488178(x) != 0)
        return 0;
    int idx = FeWp(x, 0x150)->fn_vslot60();
    FeW* cur = FeWp(x, 0x150);
    if (cur == FeWp(x, 0x13C))
        fn_80487A64(x, idx);
    else if (cur == FeWp(x, 0x140))
        fn_80487BD4(x, idx);
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80485CC4(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    int v = FeI(fn_800B555C(), 0x598);
    if (v != 0) {
        fn_8040B830(p->name, "DEPTHCHART", 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804860F8(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x13C)) {
        int t = FeI(x, 0x154);
        if ((t == -1 && FeI(x, 0x158) == -1) || t == c || t != -1)
            fn_80487A64(x, c);
        fn_80487FE0(x, FeI(x, 0x13C));
    } else if (a == FeI(x, 0x140)) {
        if (FeI(x, 0x154) == -1)
            fn_80487BD4(x, c);
        fn_80487FE0(x, FeI(x, 0x140));
    }
    fn_804873B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804862A0(void* x)
{
    FeAt(x, 0x150)->fn_vslot50();
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804862F0(void* x)
{
    FeAt(x, 0x150)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048632C(void* x)
{
    FeAt(x, 0x150)->fn_vslot52();
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048637C(void* x)
{
    FeAt(x, 0x150)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804863B8(void* x)
{
    if (FeI(x, 0x150) != FeI(x, 0x13C))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80487FE0(x, FeI(x, 0x13C));
    return 0;
}

extern "C" FE_OVERLAY int fn_8048640C(void* x)
{
    if (FeI(x, 0x150) != FeI(x, 0x140))
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    fn_80487FE0(x, FeI(x, 0x140));
    return 0;
}

extern "C" FE_OVERLAY int fn_80486460(void* x)
{
    FeAt(x, 0x14C)->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804864A0(void* x, int a)
{
    FeAt(x, 0x14C)->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804864DC(void* x)
{
    FeAt(x, 0x14C)->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_8048651C(void* x)
{
    FeAt(x, 0x14C)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_80486558(void* x)
{
    FeAt(x, 0x244)->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80486598(void* x, int a)
{
    FeAt(x, 0x244)->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804865D4(void* x)
{
    FeAt(x, 0x244)->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80486614(void* x)
{
    FeAt(x, 0x244)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_804880D8(void* x)
{
    if (FeI(x, 0x150) == FeI(x, 0x13C)) {
        if (FeWp(x, 0x138)->fn_vslot86() != 0)
            return 1;
    }
    if (FeI(x, 0x150) == FeI(x, 0x140)) {
        if (FeWp(x, 0x138)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80488CD4(void) {}

extern "C" FE_OVERLAY void fn_80488CD8(void) {}
