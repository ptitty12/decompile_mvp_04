/*
 * Front-end overlay code, .frontend_codeoverlay 0x805002DC-0x80505484 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

/* Q16-DECL-BEGIN */
struct FeIdx40 {
    char b[0x28];
};
extern "C" {
int fn_80555998(int a);
int fn_805559D4(int a, FeIdx40* idx, int b, int c);
FeIdx40* fn_80556348(FeIdx40* self);
int fn_805563C4(FeIdx40* self);
int fn_80556410(FeIdx40* self);
}
#define FS_V(n) virtual void s##n();
#define FS_A(X) \
    X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19) \
    X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31) X(32) X(33) X(34) X(35) X(36) \
    X(37) X(38) X(39) X(40) X(41) X(42) X(43) X(44) X(45) X(46) X(47) X(48) X(49) X(50) X(51) X(52) X(53) \
    X(54) X(55) X(56) X(57) X(58) X(59) X(60) X(61) X(62) X(63) X(64) X(65) X(66)
#define FS_B(X) \
    X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) X(81) X(82)
#define FS_C(X) X(85)
#define FS_D(X) \
    X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) X(97) X(98) X(99) X(100) X(101) X(102) X(103) \
    X(104) X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112) X(113) X(114) X(115) X(116) X(117) \
    X(118) X(119) X(120) X(121) X(122) X(123) X(124) X(125) X(126) X(127)
/* Widget view: slot 67 (int,int), 68 (int), 83 and 84 and 87 return int. */
struct FeWQ5 : Unk800C7B40_Data {
    virtual ~FeWQ5();
    FS_A(FS_V) virtual void s67(int a, int b); virtual void s68(int a); FS_B(FS_V) virtual int s83(); virtual int s84(); FS_C(FS_V) virtual void s86(int a, int b, int* c); virtual int s87(); FS_D(FS_V)
};
class FeSubI11 {
public:
    char pad0[0x24];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
};
extern "C" {
int fn_805053A8(int a);
int fn_80505310(int a);
int fn_80505400(int a, int b);
void fn_80123830(FeW* w, int a, int b, int c, int d, int e);
}
int fn_80084014(int a, int b);
struct FeT12 {
    int a;
    int b;
    int c;
};
extern FeT12 lbl_805FD5F8[];
extern FeT12 lbl_805FD700[];
extern FeT12 lbl_805FD8BC[];
extern FeT12 lbl_805FD91C[];
struct FeWQ9 : Unk800C7B40_Data {
    virtual ~FeWQ9();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(int a);
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(int a); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual int s59(); virtual int s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual int s87(); virtual void s88(int a, int b); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
class FeSubQ {
public:
    char pad0[0x24];
    virtual int s1(); virtual int s2(); virtual int s3(int a); virtual int s4(); virtual int s5();
    virtual int s6(int a); virtual int s7(); virtual int s8(); virtual int s9(); virtual int s10(int a);
    virtual int s11(); virtual int s12(); virtual int s13();
};
extern "C" void fn_800D0074(FeSubQ* s, int v, int f);
extern "C" int fn_80500F54(void* self, int* out, int a);
/* Q16-DECL-END */

extern "C" void fn_80500AC0(FeScrQ* x);
extern const char lbl_805FB5A0[];
extern "C" FeW* fn_800C8040(FeW* w);
extern "C" void fn_8050116C(FeScrQ* x, int a);
extern "C" int fn_800B57EC(FeState* s);
extern "C" int fn_8057CE00(int v);
extern "C" char* fn_8040321C(char* dst, const char* fmt, const char* a, const char* b);
extern "C" void fn_80403144(char* dst, const char* src);
extern "C" void fn_80504978(void* x, int v);
extern "C" void fn_80504F14(void* x);
extern "C" void fn_80500C40(FeScrN* x, int a);
extern "C" void fn_80504AD8(FeScrD* x);
extern const char lbl_805F4EF4[];
extern const char lbl_805F4450[];
extern "C" void fn_80500C20(FeScrD* x);
extern "C" void fn_80500ED8(FeScrQ* x);
extern "C" int fn_80501004(void* self, int* arr, int n, int v);
extern "C" void fn_8050103C(FeScrQ* x);
extern "C" int fn_80501134(int* arr, int n, int v);
extern "C" void fn_80504210(FeScrN* x, int a);
extern "C" int fn_80504274(FeScrN* x);
extern "C" int fn_805042E8(FeScrN* x);
extern "C" int fn_8050435C(FeScrN* x);
extern "C" int fn_805043D0(FeScrN* x);
extern "C" void fn_80504444(FeScrQ* x);
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
extern "C" void fn_8050511C(FeScrQ* x);
extern "C" char* fn_80505178(char* buf, int k);
extern "C" char* fn_805051F8(char* buf, int a, int b);
extern "C" char* fn_80505288(char* out, int a, int b);
extern "C" int fn_80505310(int k);
extern "C" int fn_805053A8(int v);
extern "C" int fn_80505400(int a, int b);
extern "C" int fn_8050544C(int a, int b);

extern "C" FE_OVERLAY void fn_80500AC0(FeScrQ* q)
{
    FeScrN* x = (FeScrN*)q;
    if (((FeWQ5*)x->m154)->s87() != 0) {
        fn_801251CC(x->m158, 3, 0x37A2, 2);
        fn_80125084(x->m158, 2);
        fn_80125084(x->m158, 0);
    } else {
        fn_801251CC(x->m158, 3, 0x1A2F, 2);
        if (((FeSubI11*)((char*)x->m148 + 0xDC))->s11() == 0 && (int)x->m164 != 3 && (int)x->m164 != 2)
            fn_801251CC(x->m158, 2, 0x204E, 3);
        else
            fn_80125084(x->m158, 2);
        fn_801251CC(x->m158, 0, 0x201A, 1);
    }
    if (x->m134->fn_vslot59() == ((FeWQ5*)x->m134)->s83()) {
        fn_80125084(x->m158, 3);
        fn_80125084(x->m158, 0);
    }
}

extern "C" FE_OVERLAY void fn_80500C20(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_80500C40(FeScrN* xn, int a)
{
    FeScrQ* x = (FeScrQ*)xn;
    int sel = ((FeSubI11*)((char*)x->m148 + 0xDC))->s11();
    fn_800D0074((FeSubQ*)((char*)x->m13C + 0x98), sel, 0);
    fn_800D0074((FeSubQ*)((char*)x->m140 + 0xDC), sel, 0);
    if (fn_8057CE00(sel) >= 0) {
        int sp8[24];
        int n = fn_80500F54(x, sp8, sel);
        int i = ((FeSubQ*)((char*)x->m13C + 0x98))->s13() - 1;
        for (; i >= 0; i--) {
            FeSubQ* hs = (FeSubQ*)((char*)x->m13C + 0x98);
            if (fn_80501004(x, sp8, n, hs->s10(i)) == 0) {
                ((FeSubQ*)((char*)x->m13C + 0x98))->s3(i);
                ((FeSubQ*)((char*)x->m140 + 0xDC))->s3(i);
            }
        }
        ((FeSubQ*)((char*)x->m13C + 0x98))->s6(0);
        ((FeSubQ*)((char*)x->m140 + 0xDC))->s6(0);
    }
    if (sel != 0) {
        if (sel >= 0) {
            if (sel <= 3)
                x->m15C = 0;
        }
    } else {
        x->m15C = fn_800B57EC(fn_800B555C());
    }
    int v = 0;
    if (x->m160 != 0)
        v = sel;
    x->m1DC = v;
    fn_80504D88(x);
    int cnt = ((FeW*)x->m134)->fn_vslot59();
    if (cnt != ((FeWQ5*)x->m134)->s83()) {
        FeWQ5* w = (FeWQ5*)x->m134;
        w->s67(w->s83(), ((FeWQ5*)x->m134)->s84());
    }
    fn_8050103C(x);
    fn_80500ED8(x);
}

extern "C" FE_OVERLAY void fn_80500ED8(FeScrQ* x)
{
    char buf[0xC8];
    fn_80505288(buf, x->m164, x->m1E8);
    fn_800C8040(x->fn_vslot32(lbl_805FB5A0, 1))->fn_vslot28(buf);
}

/* near-miss: loop pointers o/q/c land in r31/r29/r30 where retail has r30/r31/r29 (registers only) */
extern "C" FE_OVERLAY int fn_80500F54(void* self, int* out, int a)
{
    FeIdx40 buf[12];
    int h = fn_80555998(a);
    FeIdx40* p = buf;
    int k = 11;
    do {
        fn_80556348(p);
        p++;
    } while (k-- != 0);
    int n = fn_805559D4(h, buf, 12, a);
    if (n > 0) {
        int* o = out;
        FeIdx40* q = buf;
        int c = n;
        do {
            o[0] = fn_805563C4(q);
            o[1] = fn_80556410(q);
            q++;
            o += 2;
            c--;
        } while (c != 0);
    }
    return n * 2;
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

/* near-miss: retail loads the m134 widget into r3 for the s69 call (we use r11) and orders li r5/addi in the CELL lookup differently (8 lines); 3 variants tried */
extern "C" FE_OVERLAY void fn_8050103C(FeScrQ* x)
{
    int id = ((FeW*)x->m134)->fn_vslot61();
    fn_8050116C(x, 1);
    if (((FeW*)x->m134)->fn_vslot59() > 1) {
        FeWX* w = (FeWX*)x->m134;
        w->s69(id);
        x->m1E4 = x->m1E4 ^ 1;
        fn_80504978(x, fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot61());
        fn_80500AC0(x);
    }
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
        fn_8050511C((FeScrQ*)x);
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

extern "C" FE_OVERLAY void fn_80504444(FeScrQ* x)
{
    if (((FeW*)x->m134)->fn_vslot59() > 0) {
        int cur = ((FeW*)x->m154)->fn_vslot87();
        int want = FeAt((char*)x + 0x168, ((FeW*)x->m134)->fn_vslot60());
        if (cur != 0 && cur != want) {
            if (want == 0) {
                fn_80504F14(x);
            } else {
                FeList* l = (FeList*)x->m154;
                fn_80126CF4(l, l->m164, want, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        }
    }
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
        fn_8050103C(x);
    } else if (a == x->m144) {
        fn_80500C40((FeScrN*)x, a);
    }
}

extern "C" FE_OVERLAY void fn_80504978(void* self, int a)
{
    FeScrQ* x = (FeScrQ*)self;
    if (x->m16C != 0) {
        FeWQ5* p = (FeWQ5*)fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
        if (x->m1E0 == a)
            x->m1E4 = x->m1E4 ^ 1;
        else {
            x->m1E4 = 1;
            x->m1E0 = a;
        }
        int v;
        int k = a - 1;
        int c = x->m164;
        if (c == 0)
            v = lbl_805FD5F8[k].b;
        else if (c == 1)
            v = lbl_805FD700[k].b;
        else if (c == 2)
            v = lbl_805FD8BC[k].b;
        else if (c == 3)
            v = lbl_805FD91C[k].b;
        else
            v = 1;
        if (x->m1E4 == 0)
            v ^= 1;
        p->s86(1, v ^ 1, (int*)((char*)x + 0x168));
        p->s86(a, v, (int*)((char*)x + 0x168));
        fn_80504AD8((FeScrD*)x);
    }
}

extern "C" FE_OVERLAY void fn_80504AD8(FeScrD* d)
{
    FeScrQ* x = (FeScrQ*)d;
    FeW* p = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    int idx = p->fn_vslot60();
    char* b168 = (char*)x + 0x168;
    int off = idx * 4;
    int sel = *(int*)(b168 + off);
    int a = fn_805053A8(x->m1E8);
    int w = x->m1DC;
    int b = fn_80505400(w, fn_80505310(x->m1E8));
    if (sel == 0) {
        ((FeW*)x->m150)->fn_vslot8(0);
    } else {
        ((FeW*)x->m150)->fn_vslot8(1);
        int six = 0;
        if (b != 0)
            six = 1;
        if (six == 1 && x->m160 != 0)
            six = fn_80084014(((FeSubI11*)((char*)x->m148 + 0xDC))->s11(), 1);
        fn_80123830((FeW*)x->m150, sel, 1, six, a, x->m164 == 0);
    }
}

extern "C" FE_OVERLAY int fn_80504C30(FeScrN* x, FeW* w, int c, int a, int b)
{
    if (w == fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))) {
        FeWQ5* v = (FeWQ5*)w;
        if (a == 0 && !(b < v->s84())) {
            fn_80504978(x, b);
            v->s67(v->s83(), b);
        } else if (a >= v->s83() && b < v->s84()) {
            v->s68(a);
        }
    }
    return 0;
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

extern "C" FE_OVERLAY void fn_80504F14(void* xv)
{
    FeScrQ* x = (FeScrQ*)xv;
    if (((FeWQ9*)x->m134)->s59() > 0) {
        int sel = 0;
        int cur = ((FeWQ9*)x->m134)->s60();
        if (((FeWQ9*)x->m154)->s87() == 0) {
            char* b168 = (char*)x + 0x168;
            int off = cur * 4;
            sel = *(int*)(b168 + off);
            ((FeWQ9*)x->m138)->s44(0);
            ((FeWQ9*)x->m138)->s16(0);
        } else {
            ((FeWQ9*)x->m134)->s16(1);
            ((FeWQ9*)x->m138)->s44(1);
            ((FeWQ9*)x->m138)->s16(1);
        }
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        int st = fn_800B57EC(fn_800B555C());
        int w = x->m1DC;
        int t7 = fn_8050544C(w, fn_80505310(x->m1E8));
        fn_80126CF4((FeList*)x->m154, 0, sel, 0, t7, 0, 0, 1, 0, st, x->m160 ^ 1);
        ((FeWQ9*)x->m154)->s88(1, ((FeWQ9*)x->m134)->s59() > 1);
        fn_80500AC0(x);
    }
}

extern "C" FE_OVERLAY void fn_8050511C(FeScrQ* x)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    x->m1E8 = x->m1E8 + 1;
    fn_80504D88(x);
    fn_80500ED8(x);
    fn_8050116C(x, 0);
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
    } else {
        return 1;
    }
    return 1;
}

int fn_80084014(int a, int b);
extern "C" FE_OVERLAY int fn_8050544C(int a, int b)
{
    return fn_80084014(a, fn_80505400(a, b));
}
