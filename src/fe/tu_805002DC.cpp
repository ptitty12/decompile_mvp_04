/*
 * Front-end overlay code, .frontend_codeoverlay 0x805002DC-0x80505484 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" int fn_800B57EC(FeState* s);
extern "C" int fn_8057CE00(int v);
extern "C" char* fn_8040321C(char* dst, const char* fmt, const char* a, const char* b);
extern "C" void fn_80403144(char* dst, const char* src);
extern "C" void fn_80504978(void* x, int v);
extern "C" void fn_80504F14(void* x);
extern "C" void fn_8050511C(void* x);
extern "C" void fn_8050103C(FeScrN* x, int a);
extern "C" void fn_80500C40(FeScrN* x, int a);
extern "C" void fn_80504AD8(FeScrD* x);
extern const char lbl_805F4EF4[];
extern const char lbl_805F4450[];
extern "C" void fn_80500C20(FeScrD* x);
extern "C" int fn_80501004(void* self, int* arr, int n, int v);
extern "C" int fn_80501134(int* arr, int n, int v);
extern "C" void fn_80504210(FeScrN* x, int a);
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
extern "C" int fn_805048A8(FeScrQ* x, FeW* w, int b, int n);
extern "C" void fn_80504938(FeScrQ* x, int a);
extern "C" void fn_80504D68(FeScrD* x);
extern "C" void fn_80504D88(FeScrQ* x);
extern "C" void fn_80504E10(void* x);
extern "C" void fn_80504E94(FeScrN* x);
extern "C" char* fn_80505178(char* buf, int k);
extern "C" char* fn_805051F8(char* buf, int a, int b);
extern "C" char* fn_80505288(char* out, int a, int b);
extern "C" int fn_80505310(int k);
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

extern "C" FE_OVERLAY void fn_80504210(FeScrN* x, int a)
{
    switch (a) {
    case 0:
        fn_80504E10(x);
        break;
    case 1:
        fn_80504E94(x);
        break;
    case 2:
        fn_80504F14(x);
        break;
    case 3:
        fn_8050511C(x);
        break;
    }
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

extern "C" FE_OVERLAY int fn_805048A8(FeScrQ* x, FeW* w, int b, int n)
{
    if (w == (FeW*)x->m134) {
        if (n > 0) {
            w->fn_vslot68(n);
            x->fn_vslot67(2, fn_800C8070(x));
        }
    }
    return 0;
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

extern "C" FE_OVERLAY void fn_80504D88(FeScrQ* x)
{
    int s = x->m1E8;
    if (s > 5) {
        x->m1E8 = 0;
        return;
    }
    if (x->m1DC > 0) {
        if (x->m15C == 0) {
            x->m1E8 = 0;
            return;
        }
        if ((unsigned)(s - 1) <= 1) {
            x->m1E8 = 3;
            return;
        }
        if (s > 3) {
            x->m1E8 = 0;
            return;
        }
    }
    if ((unsigned)(x->m164 - 2) <= 1) {
        x->m1E8 = 0;
        return;
    }
    if (x->m15C != 0) {
        return;
    }
    if (s <= 2) {
        return;
    }
    x->m1E8 = s - 3;
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

extern "C" FE_OVERLAY void fn_80504E94(FeScrN* x)
{
    int r = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot61();
    fn_80504978(x, r);
    fn_8001BC4C()->fn_8001BDAC(0xA3);
}

extern "C" FE_OVERLAY char* fn_80505178(char* buf, int k)
{
    int id = 0x204D;
    switch (k) {
    case 1:
        id = 0x2050;
        break;
    case 2:
        id = 0x2051;
        break;
    case 3:
        id = 0x2052;
        break;
    case 0:
        break;
    }
    fn_80403144(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, id));
    return buf;
}

/* near-miss: switch tree and c copy differ (retail: root 1 + separate copy of a == 1 for case 0; ours root 0); 8 attempts */
extern "C" FE_OVERLAY char* fn_805051F8(char* buf, int a, int b)
{
    int c = a == 1;
    int id = 0x206D;
    switch (b) {
    case 0:
        id = 0x2070;
        if (c) {
            id = 0x206E;
        }
        break;
    case 1:
        id = 0x2071;
        if (c) {
            id = 0x206F;
        }
        break;
    case -1:
        break;
    }
    fn_80403144(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, id));
    return buf;
}

extern "C" FE_OVERLAY char* fn_80505288(char* out, int a, int b)
{
    char b1[0xC8];
    char b2[0xC8];
    fn_80505178(b1, fn_80505310(b));
    fn_805051F8(b2, a, fn_805053A8(b));
    fn_8040321C(out, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x2334), b1, b2);
    return out;
}

extern "C" FE_OVERLAY int fn_80505310(int k)
{
    int g = 0;
    if (fn_800B57EC(fn_800B555C()) != 0) {
        int z = 0;
        g = fn_8057CE00(((FeStateX*)fn_800B555C())->m608) >= z;
    }
    int t = 1;
    if (k >= 0) {
        if (k > 2) {
            t = k > 5;
        }
    }
    if (g == 0) {
        return t ^ 1;
    }
    int r = 2;
    if (t == 0) {
        r = 3;
    }
    return r;
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
