/*
 * Front-end overlay code, .frontend_codeoverlay 0x80505484-0x80508C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

/* Q16-DECL-BEGIN */
#define FS_V(n) virtual void s##n();
#define FS_R2_83(X) \
    X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19) \
    X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31) X(32) X(33) X(34) X(35) X(36) \
    X(37) X(38) X(39) X(40) X(41) X(42) X(43) X(44) X(45) X(46) X(47) X(48) X(49) X(50) X(51) X(52) X(53) \
    X(54) X(55) X(56) X(57) X(58) X(59) X(60) X(61) X(62) X(63) X(64) X(65) X(66) X(67) X(68) X(69) X(70) \
    X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) X(81) X(82) X(83)
#define FS_R85_86(X) X(85) X(86)
#define FS_R88_127(X) \
    X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) X(97) X(98) X(99) X(100) X(101) X(102) X(103) \
    X(104) X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112) X(113) X(114) X(115) X(116) X(117) \
    X(118) X(119) X(120) X(121) X(122) X(123) X(124) X(125) X(126) X(127)
/* Widget view whose slot 87 returns an int (the base FeW declares it void). */
struct FeWQ87 : Unk800C7B40_Data {
    virtual ~FeWQ87();
    FS_R2_83(FS_V) virtual void s84(int a, int b); FS_R85_86(FS_V) virtual int s87(); FS_R88_127(FS_V)
};
/* Q16-DECL-END */

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

extern "C" FE_OVERLAY int fn_80506E74(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    if (x->m13C[1]->fn_vslot59() > 0) {
        if (x->m154 == 1 && ((FeWQ87*)x->m138)->s87() == 0) {
            int o = x->m13C[1]->fn_vslot60() * 4;
            FeList* l = x->m138;
            char* b = (char*)x + 0x1F8;
            fn_80126CF4(l, l->m164, *(int*)(b + o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            ((FeWQ87*)x->m138)->s84(1, 0);
        } else {
            FeList* l = x->m138;
            fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
        fn_80507D10(q);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
    }
    return 1;
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

extern "C" FE_OVERLAY void fn_80507DD0(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    if (x->m154 == 1) {
        if (((FeWQ87*)x->m138)->s87() != 0) {
            int o = x->m13C[1]->fn_vslot60() * 4;
            FeList* l = x->m138;
            char* b = (char*)x + 0x1F8;
            fn_80126CF4(l, l->m164, *(int*)(b + o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
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
