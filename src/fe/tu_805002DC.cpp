/*
 * Front-end overlay code, .frontend_codeoverlay 0x805002DC-0x80505484 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" void fn_8050103C(FeScrN* x, int a);
extern "C" void fn_80500C40(FeScrN* x, int a);
extern "C" void fn_80504AD8(FeScrD* x);
extern const char lbl_805F4EF4[];
extern const char lbl_805F4450[];
extern "C" void fn_80500C20(FeScrD* x);
extern "C" int fn_80501004(void* self, int* arr, int n, int v);
extern "C" int fn_80501134(int* arr, int n, int v);
extern "C" int fn_80504274(FeScrN* x);
extern "C" int fn_805042E8(FeScrN* x);
extern "C" int fn_8050435C(FeScrN* x);
extern "C" int fn_805043D0(FeScrN* x);
extern "C" int fn_80504538(FeScrN* x);
extern "C" int fn_80504598(FeScrN* x);
extern "C" int fn_805045F8(FeScrN* x);
extern "C" int fn_80504658(FeScrN* x);
extern "C" int fn_805046B8(FeScrN* x);
extern "C" int fn_805046F8(FeScrN* x, int a);
extern "C" int fn_80504734(FeScrN* x);
extern "C" int fn_80504774(FeScrN* x);
extern "C" int fn_805047B0(FeScrN* x);
extern "C" int fn_805047F0(FeScrN* x, int a);
extern "C" int fn_8050482C(FeScrN* x);
extern "C" int fn_8050486C(FeScrN* x);
extern "C" void fn_80504938(FeScrQ* x, int a);
extern "C" void fn_80504D68(FeScrD* x);
extern "C" void fn_80504E10(void* x);
extern "C" int fn_805053A8(int v);
extern "C" int fn_80505400(int a, int b);
extern "C" int fn_8050544C(int a, int b);

extern "C" FE_OVERLAY void fn_80500C20(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY int fn_80501004(void* self, int* arr, int n, int v)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80501134(int* arr, int n, int v)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            return i;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80504274(FeScrN* x)
{
    if (FeW24(x->m154) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805042E8(FeScrN* x)
{
    if (FeW24(x->m154) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050435C(FeScrN* x)
{
    if (FeW24(x->m154) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805043D0(FeScrN* x)
{
    if (FeW24(x->m154) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80504538(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80504598(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_805045F8(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80504658(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_805046B8(FeScrN* x)
{
    x->m138->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_805046F8(FeScrN* x, int a)
{
    x->m138->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80504734(FeScrN* x)
{
    x->m138->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80504774(FeScrN* x)
{
    x->m138->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_805047B0(FeScrN* x)
{
    x->m144->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_805047F0(FeScrN* x, int a)
{
    x->m144->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050482C(FeScrN* x)
{
    x->m144->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050486C(FeScrN* x)
{
    x->m144->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY void fn_80504938(FeScrQ* x, int a)
{
    if (a == x->m138) {
        fn_8050103C((FeScrN*)x, a);
    } else if (a == x->m144) {
        fn_80500C40((FeScrN*)x, a);
    }
}

extern "C" FE_OVERLAY void fn_80504D68(FeScrD* x)
{
    fn_80504AD8(x);
}

extern "C" FE_OVERLAY void fn_80504E10(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY int fn_805053A8(int v)
{
    switch (v) {
    case 0:
    case 3:
        return 2;
    case 1:
    case 4:
        return 0;
    case 2:
    case 5:
        return 1;
    }
    return 2;
}

extern "C" FE_OVERLAY int fn_80505400(int a, int b)
{
    if (a == 0) {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        }
    }
    return 1;
}

int fn_80084014(int a, int b);
extern "C" FE_OVERLAY int fn_8050544C(int a, int b)
{
    return fn_80084014(a, fn_80505400(a, b));
}
