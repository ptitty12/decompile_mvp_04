/*
 * Front-end overlay code, .frontend_codeoverlay 0x8046C6F8-0x8046F770 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY void fn_8046D988(void)
{
    ((FeObj144*)fn_800B7A94(FeGetMgr(), lbl_805F5AA4))->m144 = 1;
}

FE_OVERLAY void fn_8046D9E8(FeScrJ* x)
{
    fn_80470710(x->m144, 0);
}

FE_OVERLAY void fn_8046DB30(FeScrJ* x)
{
    fn_8046DA10(x);
}

FE_OVERLAY void fn_8046DB50(FeScrJ* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY int fn_8046DB70(FeScrJ* x)
{
    x->m138->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8046DBAC(FeScrJ* x)
{
    x->m138->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_8046DBE8(FeScrJ* x)
{
    x->m138->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8046DC24(FeScrJ* x)
{
    x->m138->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8046DC60(FeScrJ* x)
{
    fn_8046EB7C(x);
    return 1;
}

FE_OVERLAY void fn_8046E354(int a, FeScrJ* x)
{
    if (a == 0) {
        fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->m1E0 = a;
    }
    fn_8046D9E8(x);
}

FE_OVERLAY int fn_8046E4AC(FeScrJ* x, int v)
{
    fn_800B555C()->m570 = v;
    fn_8046DC84(x);
    return 1;
}

FE_OVERLAY void fn_8046EFB8(int a, FeScrJ* x)
{
    if (lbl_8061A48C != 0) {
        a = 1;
    }
    if (a != 0) {
        if (a == 1) {
            fn_8046F000(x);
        }
    }
}

FE_OVERLAY void fn_8046F000(FeScrJ* x)
{
    fn_8046F3A8(x, lbl_805F5240);
    fn_804705F0(x->m144, 0, 1, -1);
}

FE_OVERLAY void fn_8046F048(FeScrJ* x)
{
    fn_804704EC(x->m144, 0, 1, 2, -1);
}

FE_OVERLAY void fn_8046F07C(FeScrJ* x)
{
    fn_80470558(x->m144, 0, 1, 1, -1);
}

FE_OVERLAY void fn_8046F130(FeScrJ* x)
{
    fn_8046F3A8(x, lbl_805F5B68);
    x->fn_vslot80(1);
    fn_8049A760(x->m144);
}

FE_OVERLAY void fn_8046F188(FeScrJ* x)
{
    fn_8046F3A8(x, lbl_805F5B78);
    x->fn_vslot80(1);
    fn_8049A7E4(x->m144);
}

FE_OVERLAY void fn_8046F3A8(FeScrJ* x, const char* s)
{
    if (s != 0) {
        fn_8040B830(x->m150, s, 16);
    }
}

FE_OVERLAY void fn_8046F3D8(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

FE_OVERLAY void fn_8046F4B0(void)
{
    fn_800E25E0(fn_800B7A94(FeGetMgr(), lbl_805F4F84), 0);
}

}
