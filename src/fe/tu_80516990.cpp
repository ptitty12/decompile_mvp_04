/*
 * Front-end overlay code, .frontend_codeoverlay 0x80516990-0x80519600 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"
struct FeWf : Unk800C7B40_Data {
    virtual ~FeWf();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(int a, int b); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127();
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
extern "C" int fn_8055645C(FeIdx* self, int* out);
extern "C" int fn_805559D4(int a, FeIdxE* idx, int b, int c);
extern "C" void fn_800D0074(void* a, int b, int c);
struct FeWe : Unk800C7B40_Data {
    virtual ~FeWe();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(int a);
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(int a, int b, int c); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127();
};
class FeSubM {
public:
    char pad0[0x24];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int a);
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
};
struct FeWd : Unk800C7B40_Data {
    virtual ~FeWd();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(char* a); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106();
    virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116();
    virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120(); virtual void s121();
    virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126();
    virtual void s127();
};
extern "C" int sprintf(char*, const char*, ...);
extern "C" float fn_8007BB28__18Unk8007B2B0_Screeniii(void* g, int a, int b, int c);
extern "C" int fn_804CE204(int a);
extern "C" FeW* fn_800C8044(FeW* w);
extern "C" void fn_800C4568(void* a, FeW* b, int c);
extern const char lbl_805F514C[];
extern const char lbl_805F5C28[];
extern const char lbl_805F7864[];
extern const char lbl_805FA6D4[];
extern const char lbl_805FBA90[];
extern const char lbl_805FBAA8[];
struct FeWc : Unk800C7B40_Data {
    virtual ~FeWc();
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
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(int a, int b);
    virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85();
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
struct FeDate9 {
    unsigned short y;
    unsigned short m;
};
extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
extern "C" void fn_80403DE4(char* dst, const char* fmt, ...);
extern "C" void fn_80329FA0(void* out, ...);
extern "C" FeW* fn_800C8038(FeW* w);
extern "C" FeW* fn_800C8040(FeW* w);
extern "C" FeW* fn_800C8054(FeW* w);
extern "C" void fn_800DD204__FP3UiST0(void* a, void* b);
extern "C" int fn_8057CF60(int a, int b);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned i);
extern const char lbl_805FBA6C[];
extern const char lbl_805FBA78[];
extern const char lbl_805FBA84[];
extern const char lbl_805FA3B8[];
extern const char lbl_805F4F84[];
extern const char lbl_805F54F8[];
extern const char lbl_805F5100[];
struct FeTab2 {
    int m0;
    int m4[29];
    int m78[3];
    int m84;
    int m88;
    char pad8C[0x94 - 0x8C];
    FeW* m94;
};
extern "C" void fn_80599BC8(int w, int a, int b);
extern "C" double fn_8007824C(int v, int a);

inline void FeSet(char* a, int i, int v)
{
    int o = i * 4;
    *(int*)(a + o) = v;
}

struct FeSideRec2 {
    char pad0[0x78];
    int m78[4];
    int m88;
    char pad8C[0xA4 - 0x8C];
    FeW* mA4;
    FeW* mA8;
};
extern "C" unsigned fn_80599C40(int w, int a);
extern "C" int fn_80599C50(int w, int a, int b);
extern "C" int fn_80599C80(int w, int a);
extern const char lbl_8066A248[];
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
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual int s21();
};
struct FeRow16 {
    int a;
    int b;
    int c;
    int d;
};
extern FeRow16 lbl_80622344[];
struct FeSideRec {
    char pad0[0x78];
    int m78[4];
    int m88;
    char pad8C[0xA8 - 0x8C];
    FeW* mA8;
};
extern "C" void fn_80599B54(int w);
extern "C" void fn_80599B84(int w, int a, int b, int c);
extern "C" void fn_80599B94(int w, int a, int b);

extern "C" void fn_8051667C(void* x);
extern "C" void fn_80517518(void* x, int a, int b);
extern const char lbl_80669A50[];
extern "C" void fn_80517910(void* x, int a);
extern "C" void fn_80518784(void* x, int a);
extern "C" void fn_80518AAC(void* x);
extern "C" int fn_805190D8(void* x);
extern "C" void fn_80528524(int a, void* x);
extern "C" void fn_80516990(int a, void* x);
extern "C" void fn_805169BC(int a, FeScrT* x);
extern "C" int fn_80516A3C(FeScrT* x);
extern "C" int fn_80516A84(FeScrT* x);
extern "C" int fn_80516ACC(FeScrT* x);
extern "C" int fn_80516B1C(FeScrT* x);
extern "C" void fn_80516D24(FeScrT* x, char* dst);
extern "C" void fn_80516D54(FeScrT* x, int a);
extern "C" int fn_80516DA8(void* self, FeTab* t, int k);
extern "C" FeScrN* fn_80517200(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_805174CC(void* x, int a, int b);
extern "C" void fn_80517C48(FeScrD* x);
extern "C" int fn_80517C70(void* x);
extern "C" int fn_80517CEC(void* x);
extern "C" int fn_80517D58(FeScrN* x);
extern "C" int fn_80517D98(FeScrN* x, int a);
extern "C" int fn_80517DD4(FeScrN* x);
extern "C" int fn_80517E14(FeScrN* x);
extern "C" void fn_8051840C(FeScrD* x);
extern "C" int fn_8051848C(FeScrN* x);
extern "C" int fn_805184C8(FeScrN* x);
extern "C" int fn_80518504(FeScrN* x);
extern "C" int fn_80518540(FeScrN* x);
extern "C" int fn_8051857C(FeScrF* x);
extern "C" int fn_805185B8(FeScrF* x);
extern "C" int fn_805185F4(FeScrF* x);
extern "C" int fn_80518630(FeScrF* x);
extern "C" int fn_8051866C(FeScrN* x);
extern "C" int fn_80518718(void* x);
extern "C" void fn_80517BD4(void* x, int a);
extern "C" void fn_80518434(void* x, int a);
extern "C" void fn_80518FF8(void* x, int i);
extern "C" void fn_80519038(FeScrN* x, int a);
extern "C" void fn_80516FEC(FeScrT* x);

extern "C" FE_OVERLAY void fn_80516990(int a, void* x)
{
    if (a == 1) {
        fn_8051667C(x);
    }
}

extern "C" FE_OVERLAY void fn_805169BC(int a, FeScrT* x)
{
    if (a == 1) {
        x->m2C0 = a;
        x->fn_vslot80(1);
        fn_800B7ADC(FeGetMgr(), x);
    }
}

extern "C" FE_OVERLAY int fn_80516A3C(FeScrT* x)
{
    return x->m2BC->fn_vslot86() != 0;
}

extern "C" FE_OVERLAY int fn_80516A84(FeScrT* x)
{
    return x->m2BC->fn_vslot87() != 0;
}

extern "C" FE_OVERLAY int fn_80516ACC(FeScrT* x)
{
    FeSubA* p = x->m2A8;
    if (p == (FeSubA*)((char*)x + 0x1EC)) {
        return fn_80516A3C(x);
    }
    return p == (FeSubA*)((char*)x + 0x134) ? fn_80516A84(x) : 0;
}

extern "C" FE_OVERLAY int fn_80516B1C(FeScrT* x)
{
    int r = 0;
    if (fn_80516A3C(x) != 0 || fn_80516A84(x) != 0) {
        r = 1;
    }
    return r;
}

/* near-miss: 99%+; only the loop's slwi/addi pair order differs (retail slwi first); b-first variants hoist the base, off-first ones fold it */
extern "C" FE_OVERLAY void fn_80516B6C(FeScrT* x)
{
    fn_80125100(FeP(x, 0x2B8));
    FeW* p = FeP(x, 0x2B8);
    int a0 = fn_80516ACC(x);
    int code = 0x1A2F;
    if (a0 != 0) {
        code = 0x37A2;
    }
    ((int (*)(void*, int, int))fn_80125180)(p, 3, code);
    if (fn_80516B1C(x) == 0 && FeI(x, 0x1BC) > 0 && FeI(x, 0x274) > 0) {
        fn_80125180(FeP(x, 0x2B8), 2, 0x1A3D);
    } else {
        fn_80125084(FeP(x, 0x2B8), 2);
    }
    if (fn_80516ACC(x) != 0) {
        goto K;
    }
    {
        FeTab2* t;
        FeTab2* u;
        int idx;
        int val;
        int found;
        if (((FeTab2*)x->m2A8)->m94->fn_vslot60() < ((FeTab2*)x->m2A8)->m84) {
            t = (FeTab2*)x->m2A8;
            idx = t->m94->fn_vslot60();
            u = (FeTab2*)x->m2A8;
            val = t->m4[idx];
            found = 0;
            for (int i = 0; i < *(volatile int*)&u->m88; i++) {
                char* b = (char*)u + 0x78;
                if (val == *(int*)(b + i * 4)) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                fn_80125180(FeP(x, 0x2B8), 0, 0x1A46);
                return;
            }
            if (((FeTab2*)((volatile FeScrT*)x)->m2A8)->m88 <= 2) {
                fn_80125180(FeP(x, 0x2B8), 0, 0x1A45);
                return;
            }
        K:
            fn_80125084(FeP(x, 0x2B8), 0);
        } else {
            fn_80125084(FeP(x, 0x2B8), 0);
            fn_80125084(FeP(x, 0x2B8), 3);
        }
    }
}

extern "C" FE_OVERLAY void fn_80516D24(FeScrT* x, char* dst)
{
    *dst = 0;
    if (x->m2C0 != 0) {
        *(FeS5*)dst = lbl_805F4450;
    }
}

extern "C" FE_OVERLAY void fn_80516D54(FeScrT* x, int a)
{
    fn_800ED310(x, a);
    x->m2A8->m94->fn_vslot14(a);
}

extern "C" FE_OVERLAY int fn_80516DA8(void* self, FeTab* t, int k)
{
    int n = t->m84;
    int i = 0;
    if (i < n) {
        int o = 0;
        do {
            int v = t->m78[k];
            char* b = (char*)t + 4;
            if (v == *(int*)(b + o)) {
                return i;
            }
            i++;
            o += 4;
        } while (i < n);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80516DF0(FeSideRec* a, FeSideRec* b, int w)
{
    fn_80599B54(w);
    int i = 0;
    int ia = ((FeSubK*)((char*)a->mA8 + 0xDC))->s21();
    int ib = ((FeSubK*)((char*)b->mA8 + 0xDC))->s21();
    fn_80599B84(w, ia, ib, (unsigned short)fn_800A2AE8(lbl_80619948));
    do {
        FeSideRec* p = i == 0 ? a : b;
        for (int j = 0; j < p->m88; j++) {
            fn_80599B94(w, i, p->m78[j]);
        }
        i++;
    } while (i <= 1);
}

extern "C" FE_OVERLAY void fn_80516EEC(int w, FeSideRec2* a, FeSideRec2* b)
{
    int i = 0;
    do {
        FeSideRec2* p = i == 0 ? a : b;
        int id = fn_80599C80(w, i);
        unsigned j = 0;
        ((FeSubV*)((char*)p->mA4 + 0x98))->s20(id, 0);
        ((FeSubV*)((char*)p->mA8 + 0xDC))->s20(id, 0);
        p->m88 = fn_80599C40(w, i);
        while (j < fn_80599C40(w, i)) {
            p->m78[j] = fn_80599C50(w, i, (unsigned char)j);
            j++;
        }
        i++;
    } while (i <= 1);
}

extern "C" FE_OVERLAY void fn_80516FEC(FeScrT* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    int b = 0x4DA0;
    if (x->m2A8 == (FeSubA*)((char*)x + 0x134)) {
        b = 0x4D9F;
    }
    fn_80131F34(p, x, fn_80528524, 0, b, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY FeScrN* fn_80517200(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669A50);
    FeI(self, 0x130) = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8051725C(FeScrN* x)
{
    char buf[0x68];
    fn_800ECF18(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->m134 = fn_800C805C(x->fn_vslot32(lbl_805FBA6C, 1));
    x->m138 = (FeW*)fn_800C8058(x->m134->fn_vslot32(lbl_805FBA78, 1));
    x->m13C = (FeW*)fn_800C8058(x->fn_vslot32(lbl_805FBA84, 1));
    x->m140 = fn_800C8054(x->fn_vslot32(lbl_805FA3B8, 1));
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    if (((FeState0*)fn_800B555C())->m0 != 0x2F || fn_800B5898(fn_800B555C()) == 0) {
        fn_801250D8(p);
    }
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        fn_80125100(p);
    }
    FeDate9 d;
    fn_80329FA0(&d, fn_800A2AE8(lbl_80619948));
    fn_80403DE4(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26BB), d.m);
    FeW* w = fn_800C8040(x->fn_vslot32(lbl_805F54F8, 1));
    w->fn_vslot28(buf);
    fn_800DD204__FP3UiST0(w, fn_800C8038(x->fn_vslot32(lbl_805F5100, 1)));
    int g = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    int m = ((FeStateX*)fn_800B555C())->m608;
    int r = fn_8057CF60(g, m);
    ((FeWc*)x)->s70(m, r);
}

extern "C" FE_OVERLAY void fn_805174CC(void* x, int a, int b)
{
    fn_80517518(x, a, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B8C4(0, b));
}

extern "C" FE_OVERLAY void fn_80517518(void* xp, int kind, int extra)
{
    FeScrN* x = (FeScrN*)xp;
    FeIdxE arr[12];
    int out;
    int t;
    fn_805559D4(2, arr, 12, kind);
    out = 0;
    fn_800D0074((char*)x->m140 + 0x98, kind, 0);
    ((FeSubM*)((char*)x->m138 + 0xDC))->s15();
    switch (kind) {
    case 0:
        t = fn_8055645C(&arr[0].v, &out);
        ((FeWf*)x->m138)->s51(0x26C5, t);
        x->m134->fn_vslot8(0);
        x->m134->fn_vslot16(0);
        ((FeSubM*)((char*)x->m138 + 0xDC))->s6(0);
        break;
    case 1:
        t = fn_8055645C(&arr[0].v, &out);
        ((FeWf*)x->m138)->s51(0x26BA, t);
        t = fn_8055645C(&arr[1].v, &out);
        ((FeWf*)x->m138)->s51(0x26B9, t);
        x->m134->fn_vslot8(1);
        x->m134->fn_vslot16(1);
        ((FeSubM*)((char*)x->m138 + 0xDC))->s6(extra - 2);
        break;
    case 2:
        t = fn_8055645C(&arr[0].v, &out);
        ((FeWf*)x->m138)->s51(0x26B6, t);
        t = fn_8055645C(&arr[1].v, &out);
        ((FeWf*)x->m138)->s51(0x26B7, t);
        t = fn_8055645C(&arr[2].v, &out);
        ((FeWf*)x->m138)->s51(0x26B8, t);
        x->m134->fn_vslot8(1);
        x->m134->fn_vslot16(1);
        ((FeSubM*)((char*)x->m138 + 0xDC))->s6(extra - 4);
        break;
    case 3:
        t = fn_8055645C(&arr[0].v, &out);
        ((FeWf*)x->m138)->s51(0x5A71, t);
        t = fn_8055645C(&arr[1].v, &out);
        ((FeWf*)x->m138)->s51(0x5A72, t);
        t = fn_8055645C(&arr[2].v, &out);
        ((FeWf*)x->m138)->s51(0x5A73, t);
        x->m134->fn_vslot8(1);
        x->m134->fn_vslot16(1);
        ((FeSubM*)((char*)x->m138 + 0xDC))->s6(extra - 7);
        break;
    }
    fn_80517910(x, extra);
}

extern "C" FE_OVERLAY void fn_80517910(void* xp, int a)
{
    FeScrN* x = (FeScrN*)xp;
    char buf[16];
    FeSubK* o = (FeSubK*)((char*)x->m138 + 0xDC);
    int id = o->s11();
    int u = fn_804CE204(a);
    int p = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(lbl_8061930C, 0, id, 1);
    sprintf(buf, lbl_805F514C, p, (int)fn_8007BB28__18Unk8007B2B0_Screeniii(lbl_8061930C, 1, id, 1));
    if (fn_800B5898(fn_800B555C()) == 0) {
        FeW* w1 = fn_800C8044(x->fn_vslot32(lbl_805F5C28, 1));
        FeW* w2 = fn_800C8044(w1->fn_vslot32(lbl_805F7864, 1));
        ((FeWd*)fn_800C8040(w1->fn_vslot29(lbl_805FBA90)))->s30(buf);
        int q = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(lbl_8061930C, 0, id, 0);
        sprintf(buf, lbl_805F514C, q, (int)fn_8007BB28__18Unk8007B2B0_Screeniii(lbl_8061930C, 1, id, 0));
        ((FeWd*)fn_800C8040(w2->fn_vslot32(lbl_805FBAA8, 1)))->s30(buf);
        x->fn_vslot32(lbl_805FA6D4, 1)->fn_vslot8(0);
        void* t = fn_800C33D0();
        fn_800C4568(t, fn_800C8038(x->fn_vslot32(lbl_805FA6D4, 1)), u);
    }
    ((FeSubV*)((char*)x->m140 + 0x98))->s20(id, 0);
    ((FeSubV*)((char*)x->m13C + 0xDC))->s20(id, 0);
}

extern "C" FE_OVERLAY void fn_80517BD4(void* x, int a)
{
    if (a == FeI(x, 0x134)) {
        int v = ((FeSub24*)((char*)FeP(x, 0x138) + 0xDC))->s11();
        fn_80517910(x, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B8C4(0, v));
    }
}

extern "C" FE_OVERLAY void fn_80517C48(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_80517C70(void* x)
{
    if (((FeState0*)fn_800B555C())->m0 != 0x2F || fn_800B5898(fn_800B555C()) == 0) {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80517CEC(void* x)
{
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80517D58(FeScrN* x)
{
    x->m134->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80517D98(FeScrN* x, int a)
{
    x->m134->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80517DD4(FeScrN* x)
{
    x->m134->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80517E14(FeScrN* x)
{
    x->m134->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_80517E50(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066A248);
    FeI(self, 0x134) = -1;
    FeI(self, 0x130) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x228) = 0;
    for (int i = 0; i < 0x30; i++) {
        int v = lbl_80622344[i].a;
        int found = 0;
        for (int j = 0; j < FeI(self, 0x228); j++) {
            if (FeAt((char*)self + 0x22C, j) == v) {
                found = 1;
                break;
            }
        }
        if (!found) {
            (&FeI(self, 0x22C))[FeI(self, 0x228)] = v;
            FeI(self, 0x228) = FeI(self, 0x228) + 1;
        }
    }
    for (int i = 0; i < 0x30; i++) {
        FeSet((char*)self + 0x168, i, 0);
    }
    return self;
}

extern "C" FE_OVERLAY void fn_8051840C(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_80518434(void* x, int a)
{
    if (a == FeI(x, 0x13C)) {
        fn_80518784(x, a);
        fn_80518AAC(x);
        return;
    }
    if (a == FeI(x, 0x140)) {
        fn_80518AAC(x);
    }
}

extern "C" FE_OVERLAY int fn_8051848C(FeScrN* x)
{
    x->m138->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_805184C8(FeScrN* x)
{
    x->m138->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80518504(FeScrN* x)
{
    x->m138->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80518540(FeScrN* x)
{
    x->m138->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051857C(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_805185B8(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_805185F4(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80518630(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051866C(FeScrN* x)
{
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        if (FeI(x, 0x134) > -1) {
            fn_800B7ADC(FeGetMgr(), x);
        }
    } else {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80518718(void* x)
{
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80518F18(FeScrN* x)
{
    int a = 0;
    int b = ((FeSubK*)((char*)x->m144 + 0xDC))->s11();
    if (((FeSubK*)((char*)x->m148 + 0xDC))->s13() > 0) {
        a = ((FeSubK*)((char*)x->m148 + 0xDC))->s11();
    }
    for (int i = 0; i < 0x30; i++) {
        int p = lbl_80622344[i].a;
        int q = lbl_80622344[i].b;
        if (p == b && q == a) {
            return i;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80518FF8(void* x, int i)
{
    char* b = (char*)x + 0x168;
    int o = i * 4;
    if (*(int*)(b + o) == 0) {
        *(int*)(b + o) = fn_805190D8(x);
    }
}

extern "C" FE_OVERLAY void fn_80519038(FeScrN* x, int a)
{
    ((FeSubV*)((char*)x->m154 + 0x98))->s20(a, 0);
    ((FeSubV*)((char*)x->m158 + 0x98))->s20(a, 0);
    ((FeSubV*)((char*)x->m15C + 0x98))->s20(a, 0);
}
