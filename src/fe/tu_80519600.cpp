/*
 * Front-end overlay code, .frontend_codeoverlay 0x80519600-0x8051E878 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"
struct FeLst {
    char* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    const void* m10;
    int m14;
};
struct FeIdx {
    int m0;
    int m4;
    int m8;
    int mC[7];
};
extern "C" FeIdx* fn_80556348(FeIdx* self);
struct FeIdxE {
    FeIdx v;
    FeIdxE() { fn_80556348(&v); }
};
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A330[];
extern "C" void fn_8040074C(void* p, int n);
extern "C" void fn_805371C4(FeLst* l, unsigned f);
extern "C" int fn_80539A84(int a);
extern "C" int fn_805559D4(int a, FeIdxE* idx, int b, int c);
extern "C" int fn_805563C4(FeIdx* e);
extern "C" int fn_80556410(FeIdx* e);
class FeSubK {
public:
    char pad0[0x24];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual int s13();
};
extern "C" void fn_8051A20C(void* x);
extern "C" int fn_80084014__Fii(int, int);
struct FeWb : Unk800C7B40_Data {
    virtual ~FeWb();
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
extern "C" int fn_800B57EC(void* s);
extern "C" int sprintf(char*, const char*, ...);
extern const char lbl_805F4ECC[];
extern "C" FeW* fn_800C8040(FeW* w);
extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
extern "C" void fn_80403144(char* dst, const char* src);
extern "C" void fn_80403DE4(char* dst, const char* fmt, ...);
extern "C" void fn_80329FA0(void* out, ...);
extern "C" int fn_8057CE00(int v);
extern const char lbl_805F82C8[];
extern const char lbl_805FBAFC[];
extern const char lbl_805F5080[];
extern const char lbl_805FA764[];
extern const char lbl_805F54F8[];
extern const char lbl_805F4F8C[];
struct FeDate9 {
    unsigned short y;
    unsigned short m;
};
extern "C" unsigned fn_8007FB2C__FP13Unk8007F198_Ci(void* g, int a);
extern "C" int fn_8007FDA8__FP13Unk8007F198_Cii(void* g, unsigned i, int a);
extern "C" int fn_8007FB98__FP13Unk8007F198_Ciii(void* g, unsigned i, int a, int b);
extern "C" int fn_8007B8C4__18Unk8007B2B0_Screenii(void* g, int a, int b);
struct FeWa : Unk800C7B40_Data {
    virtual ~FeWa();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(int a, int b); virtual void s68(int a); virtual void s69(); virtual void s70();
    virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(); virtual void s82(); virtual int s83(); virtual int s84(); virtual void s85();
    virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
extern "C" void fn_800B7ADC(FeMsgMgr* m, void* x);
extern "C" void fn_80125268(int a, int b, int c, int d);
extern "C" void fn_8051E41C(void* x);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned i);
extern "C" void fn_8007F784__FP13Unk8007F198_BUiii(void* g, unsigned i, int a, int b);
extern "C" unsigned fn_8007F84C__FP13Unk8007F198_B(void* g);
extern "C" void fn_800EC624__FP13Unk800EC624_Tiii(void* x, void* w, int a, int b);
extern "C" void* fn_804DC128(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804D29F0(int a, int b, void* c);
extern const char lbl_80668BB8[];

extern const char lbl_806691F0[];
extern "C" void fn_8051C374(void* x, int a, int b);
extern "C" int fn_80084114__Fi(int a);
extern "C" int fn_805399BC(int a);
extern int lbl_805F5A2C;
extern "C" FeScrN* fn_80519600(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_8051D9F8(FeScrN* x);
extern "C" int fn_8051DA44(FeScrN* x);
extern "C" int fn_8051DA90(FeScrN* x);
extern "C" int fn_8051DADC(FeScrN* x);
extern "C" int fn_8051DB28(FeScrN* x);
extern "C" int fn_8051DB64(FeScrN* x);
extern "C" int fn_8051DBA0(FeScrN* x);
extern "C" int fn_8051DBDC(FeScrN* x);
extern "C" int fn_8051DC18(FeScrN* x);
extern "C" int fn_8051DCCC(FeScrN* x);
extern "C" int fn_8051DD28(FeScrN* x);
extern "C" int fn_8051DD80(FeScrN* x);
extern "C" int fn_8051DE1C(FeScrN* x);
extern "C" int fn_8051DE6C(FeScrN* x);
extern "C" int fn_8051DC74(FeScrN* x, int a);
extern "C" int fn_8051DDD0(FeScrN* x, int a);
extern "C" int fn_8051A4EC(void* x, int b, int c);
extern "C" void fn_8051C31C(void* x, int a);
extern "C" void fn_8051A1C4(int unused, int* dst, int k);
extern "C" int fn_8051E198(int k);
extern "C" int fn_8051E25C(int n);
extern "C" int fn_8051E29C(int n);

extern "C" FE_OVERLAY FeScrN* fn_80519600(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806691F0);
    FeI(self, 0x130) = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 1;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    FeI(self, 0x16C) = 0;
    FeI(self, 0x170) = 0;
    FeI(self, 0x174) = 0;
    FeI(self, 0x380) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80519698(FeScrN* x)
{
    fn_800ECE34(x);
    x->m150 = fn_800C805C(x->fn_vslot32(lbl_805F82C8, 1));
    x->m158 = (FeW*)fn_800C8058(x->m150->fn_vslot32(lbl_805FBAFC, 1));
    x->m154 = fn_800C805C(x->fn_vslot32(lbl_805F5080, 1));
    FeW* w = (FeW*)fn_800C8058(x->m154->fn_vslot32(lbl_805FA764, 1));
    x->m15C = w;
    ((FeSub24*)((char*)w + 0xDC))->s15();
    if (fn_800B5898(fn_800B555C()) != 0) {
        ((FeWV*)fn_800C8040(x->fn_vslot32(lbl_805F54F8, 1)))->s29(0x277);
    }
    void* t = lbl_8061977C;
    char* a = (char*)x + 0x178;
    char* b = (char*)x + 0x1A0;
    char* c = (char*)x + 0x1C8;
    char* d = (char*)x + 0x1F0;
    FeDate9 dt;
    fn_80403144(a, fn_80090880__FP11Unk80090880(t, 0x3A62));
    fn_80403144(b, fn_80090880__FP11Unk80090880(t, 0x204C));
    fn_80329FA0(&dt, fn_800A2AE8(lbl_80619948));
    fn_80403DE4(c, fn_80090880__FP11Unk80090880(t, 0x206C), dt.m);
    fn_80403DE4(d, fn_80090880__FP11Unk80090880(t, 0x206C), dt.m - 1);
    if (fn_8057CE00(0) >= 0) {
        FeI(x, 0x218) = (int)a;
        FeI(x, 0x21C) = (int)b;
    } else {
        FeI(x, 0x218) = (int)c;
        FeI(x, 0x21C) = (int)d;
    }
    x->m174 = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
}

extern "C" FE_OVERLAY void fn_80519EDC(FeScrN* x)
{
    char buf[8];
    int i = 1;
    for (; i <= (int)x->m168; i++) {
        sprintf(buf, lbl_805F4ECC, i);
        x->m160->fn_vslot44(i, 0, buf, 4);
    }
    if (FeI(x, 0x134) == 2) {
        x->m160->fn_vslot43(0, 1, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1876), 4);
        x->m160->fn_vslot43(0, 2, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0xCEF), 4);
        x->m160->fn_vslot43(0, 3, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1976), 4);
    } else {
        x->m160->fn_vslot43(0, 1, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1876), 4);
        x->m160->fn_vslot43(0, 2, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0xCF8), 4);
        x->m160->fn_vslot43(0, 3, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0xCEF), 4);
        x->m160->fn_vslot43(0, 4, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1976), 4);
    }
}

extern "C" FE_OVERLAY void fn_8051A13C(void* self, int a, int b)
{
    void* g = lbl_8061930C;
    for (unsigned i = 0; i < fn_8007F84C__FP13Unk8007F198_B(g); i++) {
        int s = fn_80075948__18Unk8007B2B0_Screeni(g, b);
        if (fn_8007F7D0__FP13Unk8007F198_BUi(g, i) == s) {
            fn_8007F784__FP13Unk8007F198_BUiii(g, i, a, 0);
        }
    }
}

extern "C" FE_OVERLAY void fn_8051A1C4(int unused, int* dst, int k)
{
    if (k == 0) {
        *dst = lbl_805F5A2C;
    } else {
        ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B924(2, k, (char*)dst);
    }
}

extern "C" FE_OVERLAY int fn_8051A4EC(void* x, int b, int c)
{
    return fn_8051E198(c) == b;
}

extern "C" FE_OVERLAY void fn_8051C044(FeScrN* x)
{
    if (FeI(x, 0x138) != ((FeSubK*)((char*)x->m158 + 0xDC))->s5()) {
        if (FeI(x, 0x13C) != ((FeSubK*)((char*)x->m15C + 0xDC))->s11()) {
            FeI(x, 0x13C) = ((FeSubK*)((char*)x->m15C + 0xDC))->s11();
            fn_8051A20C(x);
        }
        FeI(x, 0x138) = ((FeSubK*)((char*)x->m158 + 0xDC))->s5();
        fn_8051C374(x, -1, 0);
    } else {
        if (((FeSubK*)((char*)x->m15C + 0xDC))->s13() != 0) {
            if (FeI(x, 0x13C) != ((FeSubK*)((char*)x->m15C + 0xDC))->s11()) {
                int t = ((FeSubK*)((char*)x->m15C + 0xDC))->s11();
                FeI(x, 0x13C) = t;
                FeI(x, 0x170) = FeI(x, 0x16C);
                FeI(x, 0x16C) = fn_8051E25C(t);
                if (FeI(x, 0x16C) == 0) {
                    if ((unsigned)FeI(x, 0x14C) > 1) {
                        FeI(x, 0x14C) = 1;
                    }
                    fn_80125268(FeI(x, 0x164), 2, (&FeI(x, 0x218))[FeI(x, 0x14C)], 3);
                } else {
                    FeI(x, 0x14C) = fn_80084014__Fii(FeI(x, 0x16C), 1);
                    fn_80125084(x->m164, 2);
                }
                fn_8051A20C(x);
                fn_8051C31C(x, 0);
                FeI(x, 0x170) = FeI(x, 0x16C);
            }
        }
    }
    if (((FeWb*)x->m160)->s59() > 0) {
        int k = ((FeWb*)x->m160)->s60();
        int e = ((FeWb*)x->m174)->s87();
        int a = FeAt((char*)x + 0x220, k - 1);
        if (e != 0 && e != a) {
            FeList* q = (FeList*)x->m174;
            fn_80126CF4(q, q->m164, a, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
        }
        fn_801251CC(x->m164, 3, FeW24(x->m174) < 0 ? 0x37A2 : 0x1A2F, 2);
    } else {
        fn_80125084(x->m164, 3);
    }
}

extern "C" FE_OVERLAY void fn_8051C31C(void* x, int a)
{
    fn_8051C374(x, FeP(x, 0x160)->fn_vslot61(), a);
}

extern "C" FE_OVERLAY int fn_8051D9F8(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DA44(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DA90(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DADC(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m160->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DB28(FeScrN* x)
{
    x->m160->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DB64(FeScrN* x)
{
    x->m160->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DBA0(FeScrN* x)
{
    x->m160->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DBDC(FeScrN* x)
{
    x->m160->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DC18(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DC74(FeScrN* x, int a)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot41(a);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DCCC(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DD28(FeScrN* x)
{
    if (FeW24(x->m174) >= 0 && FeI(x, 0x134) != 1) {
        x->m154->fn_vslot39();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DD80(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DDD0(FeScrN* x, int a)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot41(a);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DE1C(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DE6C(FeScrN* x)
{
    if (FeW24(x->m174) >= 0) {
        x->m150->fn_vslot39();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DEB8(FeScrN* x, FeWa* w, int u, int c, int d)
{
    if ((FeW*)w != x->m160) {
        return 0;
    }
    if (c == 0 && d >= w->s84()) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        w->s67(w->s83(), d);
        fn_8051C31C(x, 0);
    } else {
        if (c >= w->s83()) {
            if (d < w->s84()) {
                w->s68(c);
            }
        }
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051DFE0(FeW* x, FeW* w, int b, int d)
{
    if (w == FeP(x, 0x160)) {
        w->fn_vslot68(d);
        x->fn_vslot67(2, fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8051E068(void* x, int k)
{
    void* g = lbl_8061930C;
    if (FeI(x, 0x134) == 2) {
        if ((unsigned)(k - 0xB) > 1) {
            for (unsigned i = 0; i < fn_8007FB2C__FP13Unk8007F198_Ci(g, FeI(x, 0x16C)); i++) {
                if (fn_8007FDA8__FP13Unk8007F198_Cii(g, i, FeI(x, 0x16C)) != 0) {
                    if (k != 0xA && k != 2) {
                        int t = fn_8051E198(k);
                        for (int j = 0; j <= 1; j++) {
                            int r = fn_8007FB98__FP13Unk8007F198_Ciii(g, i, j == 0, FeI(x, 0x16C));
                            if (fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, r) == t) {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
            return 0;
        }
        return 1;
    }
    int n = fn_8007FB2C__FP13Unk8007F198_Ci(g, FeI(x, 0x16C));
    for (int i = 0; i < n; i++) {
        if (fn_8007FDA8__FP13Unk8007F198_Cii(g, i, FeI(x, 0x16C)) != 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8051E198(int k)
{
    switch (k) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    default:
        return 0;
    }
}

extern "C" FE_OVERLAY int fn_8051E25C(int n)
{
    switch (n) {
    case 10:
    case 11:
    case 12:
        return 0;
    default:
        return fn_80084114__Fi(fn_8051E198(n));
    }
}

enum FeE29 { FeE29_Neg = -1, FeE29_10 = 10, FeE29_12 = 12 };
extern "C" FE_OVERLAY int fn_8051E29C(int n)
{
    switch ((FeE29)n) {
    case 10:
        return 0x2000003F;
    case 11:
        return 0x24000000;
    case 12:
        return 0x28000000;
    default:
        return fn_805399BC(fn_8051E198(n)) | 0x20000000;
    }
}

extern "C" FE_OVERLAY void fn_8051E304(void* x, int k)
{
    switch (k) {
    case 0:
        if (lbl_8061A32C == 0) {
            lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
        }
        fn_800B7ADC(lbl_8061A32C, x);
        break;
    case 1:
        if (FeI(x, 0x168) > 0) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
        }
        fn_8051C31C(x, 0);
        break;
    case 3:
        if (FeI(x, 0x134) == 2) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            if (FeI(x, 0x14C) == 0) {
                FeI(x, 0x14C) = 1;
            } else {
                FeI(x, 0x14C) = 0;
            }
            if (FeI(x, 0x16C) == 0) {
                fn_80125268(FeI(x, 0x164), 2, (&FeI(x, 0x218))[FeI(x, 0x14C)], 3);
            }
            fn_8051C31C(x, 0);
        }
        break;
    case 2:
        fn_8051E41C(x);
        break;
    }
}

extern "C" FE_OVERLAY void fn_8051E41C(void* xp)
{
    FeScrN* x = (FeScrN*)xp;
    if (((FeWb*)x->m160)->s59() > 0) {
        int k = ((FeWb*)x->m160)->s60();
        int v;
        if (((FeWb*)x->m174)->s87() == 0) {
            int km = k - 1;
            v = (&FeI(x, 0x220))[km];
            fn_801251CC(x->m164, 3, 0x37A2, 2);
            fn_80125084(x->m164, 2);
            fn_80125084(x->m164, 0);
            ((FeWb*)x->m150)->s44(0);
            ((FeWb*)x->m150)->s16(0);
            ((FeWb*)x->m154)->s44(0);
            ((FeWb*)x->m154)->s16(0);
        } else {
            v = 0;
            fn_801251CC(x->m164, 3, FeW24(x->m174) < 0 ? 0x37A2 : 0x1A2F, 2);
            if (FeI(x, 0x16C) == 0) {
                fn_80125268(FeI(x, 0x164), 2, (&FeI(x, 0x218))[FeI(x, 0x14C)], 3);
            }
            fn_801251CC(x->m164, 0, 0x201A, 1);
            ((FeWb*)x->m160)->s16(1);
            ((FeWb*)x->m150)->s44(1);
            ((FeWb*)x->m150)->s16(1);
            ((FeWb*)x->m154)->s44(1);
            ((FeWb*)x->m154)->s16(1);
        }
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        ((void (*)(FeList*, int, int, int, int, int, int, int, int, int, int))fn_80126CF4)((FeList*)x->m174, 0, v, 0, FeI(x, 0x14C), 0, 0, 1, 0, fn_800B57EC(fn_800B555C()), 0);
        ((FeWb*)x->m174)->s88(1, ((FeWb*)x->m160)->s59() > 1);
    }
}

extern "C" FE_OVERLAY FeScrN* fn_8051E714(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668BB8);
    fn_804DC128((char*)self + 0x2DC, a, b, c, d, e, f, g, h);
    fn_804DC128((char*)self + 0x440, a, b, c, d, e, f, g, h);
    FeI(self, 0x5A4) = 0;
    FeI(self, 0x5A8) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8051E7D0(void* x, int a, int b)
{
    if (FeI(x, 0x5A4) == 0) {
        FeI(x, 0x5A4) = 1;
        char* p = (char*)x + 0x2DC;
        FeI(x, 0x5A8) = 1;
        char* q = (char*)x + 0x440;
        fn_800EC624__FP13Unk800EC624_Tiii(p, x, 0, fn_800B548C(0));
        fn_800EC624__FP13Unk800EC624_Tiii(q, x, 1, fn_800B548C(0));
        fn_804D29F0(a, 0, p);
        fn_804D29F0(b, 0, q);
    }
}
