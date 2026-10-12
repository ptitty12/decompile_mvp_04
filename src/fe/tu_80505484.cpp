/*
 * Front-end overlay code, .frontend_codeoverlay 0x80505484-0x80508C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" FeW* fn_800C8058(FeW* w);
extern int lbl_806222B0;
extern "C" void fn_80505FD4(FeScrQ* x, int a, int b, int c);
extern "C" void fn_805082D0(char* x);
extern const char lbl_805FB5E0[];
extern "C" void fn_80507DD0(FeScrQ* x);
extern int lbl_806222A4;
extern int lbl_806222A8;
extern int lbl_806222AC;
extern "C" void fn_80505760(FeScrD* x);
extern "C" void fn_80505E40(FeScrD* x);
extern "C" void fn_80505E60(FeScrQ* x);
extern "C" void fn_80505F1C(FeScrQ* x, int a);
extern "C" void fn_80505F40(FeScrQ* x, int a, int b, int c);
extern "C" void fn_80506C18();
extern "C" int fn_80506C1C();
extern "C" int fn_80506C40(FeScrN* x);
extern "C" int fn_80506D4C(FeScrQ* x, int a);
extern "C" int fn_80506DD0(FeScrQ* x, FeW* w, int b, int n);
extern "C" void fn_80506E70();
extern "C" int fn_80506FD4(FeScrQ* x);
extern "C" int fn_80507038();
extern "C" int fn_80507040(FeScrQ* x);
extern "C" int fn_805070A4();
extern "C" int fn_805070AC(FeScrQ* x);
extern "C" int fn_8050712C(FeScrN* x);
extern "C" int fn_80507184(FeScrQ* x);
extern "C" int fn_80507204(FeScrN* x);
extern "C" int fn_805073EC(FeScrN* x);
extern "C" int fn_80507640(FeScrN* x);
extern "C" int fn_8050787C(FeScrN* x, int a);
extern "C" int fn_80507A6C(FeScrN* x);
extern "C" int fn_80507C38(FeScrA* x);
extern "C" int fn_80507C80(FeScrA* x);
extern "C" int fn_80507CC8(FeScrA* x);
extern "C" void fn_80507D10(FeScrQ* q);
extern "C" int fn_80507DC4(void* self, int a);
extern "C" void fn_80507E8C(FeScrQ* q);
extern "C" FeW* fn_80507F8C(FeScrN* x);
extern "C" int fn_80507FB8(FeScrN* x);
extern "C" int fn_80507FF4(void* self, int k);
extern "C" int fn_805082B8(int c);
extern "C" int fn_80508BF4(char* x, int a, int b);

extern "C" FE_OVERLAY void fn_80505760(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80505E40(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_80505E60(FeScrQ* x)
{
    ((FeW*)x->m13C)->fn_vslot14(0);
    ((FeW*)x->m140)->fn_vslot14(0);
    ((FeW*)x->m13C)->fn_vslot14(x->m154 == 0);
    ((FeW*)x->m140)->fn_vslot14((x->m154 ^ 1) == 0);
}

extern "C" FE_OVERLAY void fn_80505F1C(FeScrQ* x, int a)
{
    x->m154 = a;
    fn_80505E60(x);
}

extern "C" FE_OVERLAY void fn_80505F40(FeScrQ* x, int a, int b, int c)
{
    if (a != -1) {
        fn_80505FD4(x, a, b, c);
    }
    if (x->m154 == 0) {
        ((FeWX*)x->m144)->s44(1);
    } else {
        ((FeWX*)x->m144)->s44(0);
    }
    fn_80505E60(x);
    fn_80507D10(x);
}

extern "C" FE_OVERLAY void fn_80506C18()
{
}

extern "C" FE_OVERLAY int fn_80506C1C()
{
    lbl_806222A4 = -1;
    lbl_806222A8 = -1;
    lbl_806222AC = -1;
    return 1;
}

extern "C" FE_OVERLAY int fn_80506C40(FeScrN* x)
{
    lbl_806222A4 = ((FeSub*)((char*)fn_800C8058(x->m144->fn_vslot33(10, 1)) + 0xDC))->s5();
    lbl_806222A8 = x->m13C->fn_vslot60();
    lbl_806222AC = x->m140->fn_vslot60();
    lbl_806222B0 = ((FeSub*)((char*)fn_800C8058(x->m14C->fn_vslot33(10, 1)) + 0xDC))->s5();
    return 1;
}

extern "C" FE_OVERLAY int fn_80506D4C(FeScrQ* x, int a)
{
    if (a == x->m13C) {
        x->m154 = 0;
        fn_80507E8C(x);
        fn_80505F40(x, 1, -1, -1);
    } else if (a == x->m140) {
        x->m154 = 1;
        fn_80505F40(x, -1, -1, -1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80506DD0(FeScrQ* x, FeW* w, int b, int n)
{
    if (w == (FeW*)x->m140) {
        x->m154 = 1;
        w->fn_vslot68(n);
        fn_80505F40(x, -1, -1, -1);
        ((FeWX*)x)->s44(fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80506E70()
{
}

extern "C" FE_OVERLAY int fn_80506FD4(FeScrQ* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9B);
    x->m154 = fn_80507DC4(x, x->m154);
    fn_80507E8C(x);
    fn_80505F40(x, -1, -1, -1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507038()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80507040(FeScrQ* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9C);
    x->m154 = fn_80507DC4(x, x->m154);
    fn_80507E8C(x);
    fn_80505F40(x, -1, -1, -1);
    return 1;
}

extern "C" FE_OVERLAY int fn_805070A4()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_805070AC(FeScrQ* x)
{
    fn_80507F8C((FeScrN*)x)->fn_vslot50();
    if (x->m154 == 0) {
        fn_80507E8C(x);
        fn_80505F40(x, 1, -1, -1);
    }
    fn_80507DD0(x);
    fn_80507D10(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050712C(FeScrN* x)
{
    fn_80507F8C(x)->fn_vslot51();
    fn_80507DD0((FeScrQ*)x);
    fn_80507D10((FeScrQ*)x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507184(FeScrQ* x)
{
    fn_80507F8C((FeScrN*)x)->fn_vslot52();
    if (x->m154 == 0) {
        fn_80507E8C(x);
        fn_80505F40(x, 1, -1, -1);
    }
    fn_80507DD0(x);
    fn_80507D10(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507204(FeScrN* x)
{
    fn_80507F8C(x)->fn_vslot53();
    fn_80507DD0((FeScrQ*)x);
    fn_80507D10((FeScrQ*)x);
    return 1;
}

extern "C" FE_OVERLAY int fn_805073EC(FeScrN* x)
{
    ((FeWX*)x->m144)->s41();
    ((FeWX*)fn_800C805C(x->fn_vslot32(lbl_805FB5E0, 1)))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_80507640(FeScrN* x)
{
    x->m144->fn_vslot39();
    fn_800C805C(x->fn_vslot32(lbl_805FB5E0, 1))->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_8050787C(FeScrN* x, int a)
{
    x->m14C->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_80507A6C(FeScrN* x)
{
    x->m14C->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C38(FeScrA* x)
{
    if (x->m138->fn_vslot86() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C80(FeScrA* x)
{
    if (x->m138->fn_vslot87() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507CC8(FeScrA* x)
{
    if (x->m154 == 0) {
        return fn_80507C38(x);
    }
    if (x->m154 == 1) {
        return fn_80507C80(x);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80507D10(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    fn_80125154(x->m134, 1);
    if (x->m154 == 1 && x->m13C[1]->fn_vslot59() > 0) {
        fn_80125128(x->m134, 0);
        void* t = x->m134;
        fn_80125180(t, 3, fn_80507CC8(x) ? 0x37A2 : 0x1A2F);
    } else {
        fn_80125084(x->m134, 0);
        fn_80125084(x->m134, 3);
    }
}

extern "C" FE_OVERLAY int fn_80507DC4(void* self, int a)
{
    return a == 0;
}

extern "C" FE_OVERLAY void fn_80507E8C(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    if (x->m154 == 1) {
        x->m144[1]->fn_vslot8(1);
    } else {
        x->m144[1]->fn_vslot8(0);
    }
    FeList* l = x->m138;
    fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    l = x->m138;
    fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    fn_80505E60(q);
}

extern "C" FE_OVERLAY FeW* fn_80507F8C(FeScrN* x)
{
    int c = (int)x->m154;
    if (c == 1) {
        return x->m140;
    }
    if (c == 0) {
        return x->m13C;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507FB8(FeScrN* x)
{
    return ((FeSub11*)((char*)x->m150 + 0xDC))->s11();
}

enum FeKB { FeKB_Neg = -1, FeKB_0 = 0, FeKB_10 = 10 };
extern "C" FE_OVERLAY int fn_80507FF4(void* self, int k)
{
    switch ((FeKB)k) {
    case 0:
        return 0;
    case 10:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 1:
        return 6;
    case 6:
        return 7;
    case 7:
        return 8;
    case 8:
        return 9;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_805082B8(int c)
{
    int t = c - 0x41;
    if ((unsigned char)t > 0x19) {
        t = -1;
    }
    return t;
}

extern "C" FE_OVERLAY int fn_80508BF4(char* x, int a, int b)
{
    switch (a) {
    case 0:
        if (*(int*)(x + b * 0x4EC0 + 0x34D4) == 1) {
            return 1;
        }
        break;
    case 1:
        if (*(int*)(x + b * 0x2800 + 0x1A2B4) == 1) {
            return 1;
        }
        break;
    case 2:
        if (*(int*)(x + b * 0x3330 + 0x242B4) == 1) {
            return 1;
        }
        break;
    }
    fn_805082D0(x);
    return 0;
}
