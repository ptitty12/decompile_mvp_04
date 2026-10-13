/*
 * Front-end overlay code, .frontend_codeoverlay 0x8050C9DC-0x80512D10 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"
struct FeWm : Unk800C7B40_Data {
    virtual ~FeWm();
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
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(int a, int b);
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
struct FeAC {
    char pad0[0x1C];
    int m1C;
    char pad20[0xC];
    int m2C;
    int m30;
    int m34;
    char pad38[0x7C - 0x38];
    int m7C;
    int m80;
};
struct FeAD {
    char pad0[0x198];
    int m198;
};
struct FeAB {
    char pad0[0xC];
    FeAC* mC;
    char pad10[4];
    FeAD* m14;
};
extern "C" void fn_804CF6A4(void* x);
extern const char lbl_805FB7C4[];
extern const char lbl_805F85E0[];
extern const char lbl_805F8698[];
extern "C" int fn_800B5520(int v);
extern "C" int fn_800B57EC(void* s);
extern "C" int fn_800A2E6C(void* g);
extern "C" int fn_8007B3E0__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" int fn_8006A1B4__11Unk80069F0C(void* x);
extern "C" int fn_80075CC0__Fi(int v);
extern "C" int fn_80075D80__Fi(int v);
extern "C" int fn_80076058__Fii(int a, int b);
extern "C" int fn_8007B320__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" int fn_8007B8C4__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned i);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_800B5758(void* s);
extern "C" int fn_800B55A8(void* s);
extern "C" int fn_800ED4F0(void* x, int a);
extern "C" void fn_8006F784(void* p, int a);
extern "C" void fn_8006A12C__11Unk80069F0Ci(void* x, int a);
extern "C" int fn_8014013C(int v);
extern "C" int fn_8014014C(int v);
extern "C" int fn_800B5BD4(void* s);
extern "C" void fn_804CF948(void* x, int a, int b);
extern const char lbl_805F4F0C[];
extern "C" char* strncpy(char*, const char*, unsigned);
extern const char lbl_805F4450[];
extern const char lbl_805F3CA8[];
extern const char lbl_805FB7B4[];
extern "C" void fn_80086EC0(void* o, int a, int b);
extern const char lbl_80667BC8[];
extern const char lbl_805FB764[];
extern "C" void fn_8051095C(FeScrQ* x);
extern "C" void fn_80510F28(FeScrQ* x);
extern "C" void fn_8055AC44(void* p, int v);
extern "C" void fn_804CEF98(FeScrM* x);
extern "C" void fn_804D292C(FeSlot44* p, int v);
extern const char lbl_80667E70[];
extern "C" void fn_804CF368(void* x);
extern "C" FeScrN* fn_8050C9DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_8050CA30(FeScrN* x);
extern "C" int fn_8050D628(void* x);
extern "C" int fn_8050D6B0(FeScrN* x);
extern "C" int fn_8050D714(FeScrN* x);
extern "C" int fn_8050D778(FeScrN* x);
extern "C" int fn_8050D7DC(FeScrN* x);
extern "C" void fn_8050DAEC(FeScrM* x);
extern "C" void fn_8050DFC8(FeScrD* x);
extern "C" void fn_8050E574();
extern "C" void fn_8050E888(FeScrM* x);
extern "C" void fn_8050FB34(FeScrN* x);
extern "C" void fn_80510020(FeScrD* x);
extern "C" FeScrQ* fn_80510048(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80510500(FeScrQ* x, int a);
extern "C" void fn_8051052C();
extern "C" void fn_80510530(FeScrQ* x);
extern "C" int fn_805105A4(FeScrN* x);
extern "C" int fn_805105FC(FeScrN* x);
extern "C" int fn_80510654(FeScrN* x);
extern "C" int fn_805106AC(FeScrN* x);
extern "C" int fn_80510704(FeScrN* x);
extern "C" int fn_8051075C(FeScrN* x);
extern "C" int fn_805107B4(FeScrN* x);
extern "C" int fn_8051080C(FeScrN* x);
extern "C" int fn_80510864(FeScrN* x);
extern "C" int fn_805108A4(FeScrN* x, int a);
extern "C" int fn_805108E0(FeScrN* x);
extern "C" int fn_80510920(FeScrN* x);
inline int& FeI(void* p, int off)
{
    return *(int*)((char*)p + off);
}

typedef void (*FeDtorFn)(void* self, int c);
extern "C" void fn_804D3DD0(void* p, int c);
extern "C" void fn_804D61F4(void* p, int c);
extern "C" void fn_800EC5F4__FP8UiScrRaw(void* self, int c);
extern const char lbl_8067F420[];
extern const char lbl_806800B0[];
extern const char lbl_80655E98[];
extern const char lbl_80655BA8[];

struct Fe3CVMulti {
    char pad0[0x3C];
    const void* m3C;
    char pad1[0x184 - 0x40];
    const void* m184;
    char pad2[0x1C8 - 0x188];
    const void* m1C8;
};

extern "C" void fn_80360F48(void* self, int c);
extern const char lbl_8066E538[];

extern "C" void fn_804CEF34(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804D4704(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804D7FE0(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804D6184(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804D3D74(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804D24E8(void* nav, void* w);

extern "C" void fn_804CF304(void* x);
extern "C" void fn_8007DA8C__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" int fn_8007DA28__18Unk8007B2B0_Screen(void* g);
extern "C" void* fn_800B8144();
extern "C" void fn_800B83F8(void* a, int b, int c);
extern "C" void fn_804D28B4(void* n);
extern "C" void fn_804D4F4C(void* w);
extern "C" void fn_801389A4(void* w, int v);
extern "C" int fn_800ED2B0(void* x, const char* s);
extern "C" int fn_800CFB38();
extern const char lbl_805F852C[];
extern const char lbl_805FB7A8[];

struct FeSl144 {
    char pad0[0x144];
    int m144;
};
/* Widget view whose vtable slot 29 (+0xE8) takes an int id (fn_8050E8DC). */
class FeV29i {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29(int a);
};
extern "C" FeW* fn_800C8044(void* w);
extern "C" FeW* fn_800C8040(void* w);
extern "C" FeW* fn_800C8038(void* w);
extern "C" void fn_800DD204__FP3UiST0(void* a, void* b);
extern const char lbl_805F54F8[];
extern const char lbl_805F5100[];
extern const char lbl_805FB7EC[];


extern "C" FeW* fn_800C8044(void* w);
extern "C" FeW* fn_800C8058(void* w);
extern "C" void fn_801257C0(void* w);
extern const char lbl_805F5060[];
extern const char lbl_805F5C28[];
extern const char lbl_805F4EF4[];
extern const char lbl_805FB8A0[];
extern const char lbl_805FB8AC[];
extern const char lbl_805F4F20[];

extern "C" FE_OVERLAY FeScrN* fn_8050C9DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80667E70);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8050CA30(FeScrN* x)
{
    fn_800ECE34(x);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    x->m138 = fn_800C8060(x->fn_vslot32(lbl_805FB764, 1));
    ((FeWX*)x->m138)->s104(0);
}

extern "C" FE_OVERLAY int fn_8050D628(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D6B0(FeScrN* x)
{
    x->m134->fn_vslot50();
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D714(FeScrN* x)
{
    x->m134->fn_vslot51();
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D778(FeScrN* x)
{
    x->m134->fn_vslot52();
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D7DC(FeScrN* x)
{
    x->m134->fn_vslot53();
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_8050D840(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804CEF34(self, a, b, c, d, e, f, g, h);
    char* s1E0 = (char*)self + 0x1E0;
    self->SetVptr(lbl_8067F420);
    fn_804D4704(s1E0, a, b, c, d, e, f, g, h);
    char* s390 = (char*)self + 0x390;
    char* s540 = (char*)self + 0x540;
    fn_804D4704(s390, a, b, c, d, e, f, g, h);
    char* s6C8 = (char*)self + 0x6C8;
    char* s850 = (char*)self + 0x850;
    fn_804D6184(s540, a, b, c, d, e, f, g, h);
    char* s9B8 = (char*)self + 0x9B8;
    char* n144 = (char*)self + 0x144;
    fn_804D6184(s6C8, a, b, c, d, e, f, g, h);
    char* n188 = (char*)self + 0x188;
    fn_804D3D74(s850, a, b, c, d, e, f, g, h);
    fn_804D3D74(s9B8, a, b, c, d, e, f, g, h);
    FeI(self, 0xF80) = 1;
    fn_804D24E8(n144, s1E0);
    fn_804D24E8(n188, s390);
    if (fn_800B5BD4(fn_800B555C()) == 0) {
        fn_804D24E8(n144, s540);
        fn_804D24E8(n188, s6C8);
        if (fn_800B57EC(fn_800B555C()) == 0) {
            fn_804D24E8(n144, s850);
            fn_804D24E8(n188, s9B8);
        }
    }
    fn_800C3AB4(fn_800C33D0(), 9);
    return self;
}

/* near-miss: 99.2%; trailing three stores come out vptr-first (retail m184, vptr, m1C8), same family as fn_801470E0 / fn_8052849C */
extern "C" FE_OVERLAY void fn_8050DA2C(FeScrN* self, int c)
{
    self->SetVptr(lbl_8067F420);
    fn_804D3DD0((char*)self + 0x9B8, 2);
    fn_804D3DD0((char*)self + 0x850, 2);
    fn_804D61F4((char*)self + 0x6C8, 2);
    fn_804D61F4((char*)self + 0x540, 2);
    FeW* a = (FeW*)((char*)self + 0x390);
    a->SetVptr(lbl_806800B0);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(a, 2);
    FeW* b = (FeW*)((char*)self + 0x1E0);
    b->SetVptr(lbl_806800B0);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(b, 2);
    Fe3CVMulti* t = (Fe3CVMulti*)self;
    t->m3C = lbl_80655BA8;
    t->m1C8 = lbl_80655E98;
    t->m184 = lbl_80655E98;
    ((FeDtorFn)fn_8035686C)(self, c);
}

extern "C" FE_OVERLAY void fn_8050DAEC(FeScrM* x)
{
    fn_8055AC44((char*)x + 0xB20, 0);
    fn_804CEF98(x);
}

extern "C" FE_OVERLAY int fn_8050DB28(FeScrQ* x)
{
    fn_804CF304(x);
    if (fn_800B57EC(fn_800B555C()) == 0 && (FeI(fn_800B555C(), 4) & 1)) {
        int i = 0;
        void* g = lbl_8061930C;
        do {
            int k = i;
            i++;
            fn_8007DA8C__18Unk8007B2B0_Screenii(g, k, -1);
        } while (i <= 3);
        int k = FeI(x, 0x1C0);
        fn_8007DA8C__18Unk8007B2B0_Screenii(g, k, fn_8007DA28__18Unk8007B2B0_Screen(g));
    }
    fn_800B83F8(fn_800B8144(), 1, 1);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    ((int (*)(void*, int))fn_80125128)(p, -1);
    ((int (*)(void*, int))fn_80125154)(p, -2);
    int f = ((FeI(fn_800B555C(), 4) >> 2) & 1) ^ 1;
    FeI(x, 0xF80) = f;
    if (f != 0) {
        fn_801251CC(p, 3, 0x3BEE, -4);
        if (fn_800B57EC(fn_800B555C()) == 0) {
            fn_801251CC(p, 2, 0x3CA5, 0);
        }
    }
    if (FeI(fn_800B555C(), 4) & 1) {
        ((FeWm*)x)->s95(1, 1);
        ((FeWm*)x)->s95(0, 1);
    }
    fn_804D28B4((char*)x + 0x144);
    fn_804D28B4((char*)x + 0x188);
    if (fn_800B5BD4(fn_800B555C()) != 0) {
        int a = FeI(fn_800B555C(), 0x558);
        int b = FeI(fn_800B555C(), 0x55C);
        if (a != 0) {
            FeSl144* w = (FeSl144*)((char*)x + 0x390);
            w->m144 = a;
            fn_804D4F4C(w);
        }
        if (b != 0) {
            FeSl144* w = (FeSl144*)((char*)x + 0x1E0);
            w->m144 = b;
            fn_804D4F4C(w);
        }
    }
    void* q = fn_800B7A94(FeGetMgr(), lbl_805F852C);
    if (q != 0) {
        fn_801389A4(q, 0);
    }
    int r = fn_800ED2B0(x, lbl_805FB7A8);
    if (r != 0) {
        r = fn_800CFB38();
    }
    return r;
}

extern "C" FE_OVERLAY void fn_8050DFC8(FeScrD* x)
{
    fn_804CF368(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_8050DFF0(FeScrQ* x)
{
    fn_804CF6A4(x);
    FeW* p = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    FeSlot44* a = (FeSlot44*)((char*)x + 0x144);
    int m = a->m38;
    if ((m == 5 || m == -1) && (FeI(x, 0x1C0) == 5 || FeI(x, 0x1C0) == -1)) {
        ((int (*)(void*, int))fn_80125084)(p, 0);
        ((int (*)(void*, int))fn_80125084)(p, 2);
        ((int (*)(void*, int))fn_80125084)(p, 3);
    } else {
        ((int (*)(void*, int))fn_80125154)(p, -2);
        if (fn_804D2310(a) == (FeW*)((char*)x + 0x540) || fn_804D2310((FeSlot44*)((char*)x + 0x188)) == (FeW*)((char*)x + 0x6C8)) {
            if (FeI(fn_804D2310(a), 0x134) != 0 && FeI(fn_804D2310((FeSlot44*)((char*)x + 0x188)), 0x134) != 0) {
                fn_80125128(p, -1);
            }
        } else {
            fn_80125128(p, -1);
        }
        if (FeI(x, 0xF80) != 0) {
            if (fn_800B57EC(fn_800B555C()) == 0) {
                FeW* q = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805FB7C4);
                if ((FeW24(q->fn_vslot32(lbl_805F85E0, 1)) < 0 && (a->m38 == 5 || a->m38 == -1)) || (FeW24(q->fn_vslot32(lbl_805F8698, 1)) < 0 && (FeI(x, 0x1C0) == 5 || FeI(x, 0x1C0) == -1))) {
                    ((int (*)(void*, int))fn_80125084)(p, 2);
                    ((int (*)(void*, int))fn_80125084)(p, 3);
                } else {
                    ((int (*)(void*, int, int, int))fn_801251CC)(p, 2, 0x3CA5, 0);
                    ((int (*)(void*, int, int, int))fn_801251CC)(p, 3, 0x3BEE, -4);
                }
            }
        }
    }
    ((FeWm*)x)->s95(0, 0);
    ((FeWm*)x)->s95(1, 0);
}

extern "C" FE_OVERLAY void fn_8050E268(FeScrQ* x, int k, int a)
{
    if (fn_800B5BD4(fn_800B555C()) != 0 && k == -1) {
        int v = x->m17C;
        if (v != 5 && v != -1) {
            int w = x->m1C0;
            if (w != 5 && w != -1) {
                void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
                fn_80131F34((FeW*)p, x, (FeCbF)fn_8050E574, 0, 0x4FA0, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
                ((FeW*)p)->fn_vslot86();
                return;
            }
        }
        fn_804CF948(x, k, a);
        return;
    }
    fn_804CF948(x, k, a);
}

extern "C" FE_OVERLAY void fn_8050E394(void* a0, FeAB* y)
{
    int id = y->m14->m198;
    int s5520 = fn_800B5520(id);
    int sel = 2;
    int code;
    int v;
    if (fn_800B57EC(fn_800B555C()) == 1 && fn_800A2E6C(lbl_80619948) == 1) {
        code = 0x36;
        int t = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, id);
        sel = fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 0x14, t);
        if (sel == 0) {
            code = 0x35;
        }
    } else if (fn_8006A1B4__11Unk80069F0C(y) == 1) {
        struct {
            short a;
            unsigned short b;
        } u;
        *(int*)&u = y->mC->m7C;
        code = fn_80075CC0__Fi(u.b);
        void* g = lbl_8061930C;
        if (fn_80075D80__Fi(fn_800B5520(fn_8007B320__18Unk8007B2B0_Screenii(g, 0, fn_8007F7D0__FP13Unk8007F198_BUi(g, 0)))) == code) {
            code = 0x37;
        }
    } else {
        if (fn_800B5758(fn_800B555C()) == 1 && id == fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0))) {
            code = 0x37;
        } else {
            code = fn_80075D80__Fi(s5520);
        }
    }
    if (fn_800B55A8(fn_800B555C()) == 1) {
        v = fn_800ED4F0(a0, 3);
    } else {
        v = y->mC->m80;
    }
    int r = fn_80076058__Fii(code, v);
    y->mC->m2C = fn_8007B8C4__18Unk8007B2B0_Screenii(lbl_8061930C, 5, id);
    fn_8006F784(y->mC, r);
    fn_8006A12C__11Unk80069F0Ci(y, v);
    y->mC->m30 = fn_8014013C(code);
    y->mC->m34 = fn_8014014C(code);
    y->mC->m1C = sel;
}

extern "C" FE_OVERLAY void fn_8050E574()
{
}

extern "C" FE_OVERLAY FeScrN* fn_8050E578(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804CEF34(self, a, b, c, d, e, f, g, h);
    char* s390 = (char*)self + 0x390;
    char* s1E0 = (char*)self + 0x1E0;
    self->SetVptr(lbl_8066E538);
    fn_804D4704(s1E0, a, b, c, d, e, f, g, h);
    char* s540 = (char*)self + 0x540;
    char* s6B4 = (char*)self + 0x6B4;
    fn_804D4704(s390, a, b, c, d, e, f, g, h);
    char* s828 = (char*)self + 0x828;
    char* s9B0 = (char*)self + 0x9B0;
    fn_804D7FE0(s540, a, b, c, d, e, f, g, h);
    char* sB38 = (char*)self + 0xB38;
    char* sCA0 = (char*)self + 0xCA0;
    fn_804D7FE0(s6B4, a, b, c, d, e, f, g, h);
    char* n144 = (char*)self + 0x144;
    char* n188 = (char*)self + 0x188;
    fn_804D6184(s828, a, b, c, d, e, f, g, h);
    fn_804D6184(s9B0, a, b, c, d, e, f, g, h);
    fn_804D3D74(sB38, a, b, c, d, e, f, g, h);
    fn_804D3D74(sCA0, a, b, c, d, e, f, g, h);
    fn_804D24E8(n144, s1E0);
    fn_804D24E8(n188, s390);
    fn_804D24E8(n144, s540);
    fn_804D24E8(n188, s6B4);
    fn_804D24E8(n144, s828);
    fn_804D24E8(n188, s9B0);
    fn_804D24E8(n144, sB38);
    fn_804D24E8(n188, sCA0);
    fn_800C3AB4(fn_800C33D0(), 9);
    return self;
}

/* near-miss: 99%; trailing three stores differ only in register/store order (retail m184, vptr, m1C8 with lis r10/r11); same family as fn_8050DA2C */
extern "C" FE_OVERLAY void fn_8050E7B0(FeScrN* self, int c)
{
    self->SetVptr(lbl_8066E538);
    fn_804D3DD0((char*)self + 0xCA0, 2);
    fn_804D3DD0((char*)self + 0xB38, 2);
    fn_804D61F4((char*)self + 0x9B0, 2);
    fn_804D61F4((char*)self + 0x828, 2);
    fn_80360F48((char*)self + 0x6B4, 2);
    fn_80360F48((char*)self + 0x540, 2);
    FeW* a = (FeW*)((char*)self + 0x390);
    a->SetVptr(lbl_806800B0);
    fn_800EC5F4__FP8UiScrRaw(a, 2);
    FeW* b = (FeW*)((char*)self + 0x1E0);
    b->SetVptr(lbl_806800B0);
    fn_800EC5F4__FP8UiScrRaw(b, 2);
    Fe3CVMulti* t = (Fe3CVMulti*)self;
    t->m3C = lbl_80655BA8;
    t->m1C8 = lbl_80655E98;
    t->m184 = lbl_80655E98;
    ((FeDtorFn)fn_8035686C)(self, c);
}

extern "C" FE_OVERLAY void fn_8050E888(FeScrM* x)
{
    fn_8055AC44((char*)x + 0xE08, 0);
    fn_804CEF98(x);
    fn_804D292C(&x->m144, -1);
    fn_804D292C(&x->m188, 0);
}

extern "C" FE_OVERLAY void fn_8050E8DC(FeScrQ* x)
{
    fn_804CF304(x);
    if (fn_800B57EC(fn_800B555C()) == 0 && (FeI(fn_800B555C(), 4) & 1)) {
        int i = 0;
        void* g = lbl_8061930C;
        do {
            int k = i;
            i++;
            fn_8007DA8C__18Unk8007B2B0_Screenii(g, k, -1);
        } while (i <= 3);
        int k = FeI(x, 0x1C0);
        fn_8007DA8C__18Unk8007B2B0_Screenii(g, k, fn_8007DA28__18Unk8007B2B0_Screen(g));
    }
    fn_800B83F8(fn_800B8144(), 1, 1);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    ((int (*)(void*, int))fn_80125128)(p, -1);
    ((int (*)(void*, int))fn_80125154)(p, -2);
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 3, 0x3BEE, -4);
    FeW* w1 = fn_800C8044(((FeW*)x)->fn_vslot32(lbl_805F54F8, 1));
    FeW* w2 = fn_800C8040(w1->fn_vslot32(lbl_805F54F8, 1));
    FeW* w3 = fn_800C8038(w1->fn_vslot32(lbl_805F5100, 1));
    FeW* w4 = fn_800C8044(((FeW*)x)->fn_vslot32(lbl_805FB7EC, 1));
    w4->fn_vslot8(0);
    if (FeI(fn_800B555C(), 0) == 0x4B) {
        ((FeV29i*)w2)->s29(0x2C1);
    } else if (FeI(fn_800B555C(), 0) == 0x4A) {
        ((FeV29i*)w2)->s29(0x2C0);
        w4->fn_vslot8(1);
        fn_801251CC(p, 2, 0x3CA5, 0);
    } else {
        ((FeV29i*)w2)->s29(0x2C2);
    }
    fn_800DD204__FP3UiST0(w2, w3);
    if (FeI(fn_800B555C(), 4) & 1) {
        ((FeWm*)x)->s95(1, 1);
        ((FeWm*)x)->s95(0, 1);
    }
    fn_804D28B4((char*)x + 0x144);
    fn_804D28B4((char*)x + 0x188);
}

extern "C" FE_OVERLAY void fn_8050EBC8(FeScrQ* x)
{
    fn_804CF6A4(x);
    FeW* p = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    FeSlot44* a = (FeSlot44*)((char*)x + 0x144);
    int m = a->m38;
    if ((m == 5 || m == -1) && (FeI(x, 0x1C0) == 5 || FeI(x, 0x1C0) == -1)) {
        ((int (*)(void*, int))fn_80125084)(p, 0);
        ((int (*)(void*, int))fn_80125084)(p, 2);
        ((int (*)(void*, int))fn_80125084)(p, 3);
    } else {
        ((int (*)(void*, int))fn_80125154)(p, -2);
        if (fn_804D2310(a) == (FeW*)((char*)x + 0x828) || fn_804D2310((FeSlot44*)((char*)x + 0x188)) == (FeW*)((char*)x + 0x9B0)) {
            if (FeI(fn_804D2310(a), 0x134) != 0 && FeI(fn_804D2310((FeSlot44*)((char*)x + 0x188)), 0x134) != 0) {
                fn_80125128(p, -1);
            }
        } else {
            fn_80125128(p, -1);
        }
        if (!(FeI(fn_800B555C(), 4) & 4)) {
            if (fn_800B57EC(fn_800B555C()) == 0) {
                FeW* q = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805FB7C4);
                if ((FeW24(q->fn_vslot32(lbl_805F85E0, 1)) < 0 && (a->m38 == 5 || a->m38 == -1)) || (FeW24(q->fn_vslot32(lbl_805F8698, 1)) < 0 && (FeI(x, 0x1C0) == 5 || FeI(x, 0x1C0) == -1))) {
                    ((int (*)(void*, int))fn_80125084)(p, 2);
                    ((int (*)(void*, int))fn_80125084)(p, 3);
                } else {
                    ((int (*)(void*, int, int, int))fn_801251CC)(p, 2, 0x3CA5, 0);
                    ((int (*)(void*, int, int, int))fn_801251CC)(p, 3, 0x3BEE, -4);
                }
            }
        }
    }
    ((FeWm*)x)->s95(0, 0);
    ((FeWm*)x)->s95(1, 0);
}

/* near-miss: first s88 vcall loads lwz r0/lha in the other order (4 lines); 4 variants tried */
extern "C" FE_OVERLAY void fn_8050FB34(FeScrN* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805FB7B4);
    if (p != 0) {
        FeLink10* o = lbl_806192E0->m4->m10;
        int a = ((FeWX*)p)->s88(1);
        fn_80086EC0(o, 1, a);
        int b = ((FeWX*)p)->s88(0);
        fn_80086EC0(o, 0, b);
    }
    ((FeWX*)x)->s89();
}

extern "C" FE_OVERLAY void fn_80510020(FeScrD* x)
{
    fn_804CF368(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY FeScrQ* fn_80510048(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80667BC8);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m14C = 0;
    self->m150 = 1;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_805100BC(FeScrN* x)
{
    fn_800ECF18(x);
    int* st = (int*)fn_800B555C();
    x->m134 = fn_800C805C(x->fn_vslot32(lbl_805F5060, 1));
    x->m148 = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(x->m148, x);
    if (*st == 0x17) {
        fn_80125128(x->m148, 1);
    } else {
        fn_80125154(x->m148, 0);
    }
    fn_801257C0(x->m148);
    if (*st == 0x16) {
        x->m140 = fn_800C8044(x->fn_vslot32(lbl_805F5C28, 1));
        x->m13C = fn_800C8060(x->m140->fn_vslot32(lbl_805F4EF4, 1));
        x->fn_vslot32(lbl_805FB8A0, 1)->fn_vslot8(0);
        x->m138 = fn_800C8058(x->m140->fn_vslot32(lbl_805FB8AC, 1));
    } else {
        x->m140 = fn_800C8044(x->fn_vslot32(lbl_805FB8A0, 1));
        x->m13C = fn_800C8060(x->m140->fn_vslot32(lbl_805F4EF4, 1));
        x->fn_vslot32(lbl_805F5C28, 1)->fn_vslot8(0);
        x->m138 = fn_800C8058(x->m140->fn_vslot32(lbl_805FB8AC, 1));
        x->m134->fn_vslot16(0);
    }
    x->m140->fn_vslot8(1);
    FeW* q = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F20);
    q->fn_vslot8(fn_800A2E6C(lbl_80619948) == 0);
    fn_8051095C((FeScrQ*)x);
    fn_80510F28((FeScrQ*)x);
}

extern "C" FE_OVERLAY void fn_805103EC(FeScrQ* x, int k)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (k) {
    case 0:
        strncpy(mp->name, lbl_805F4450, 15);
        mp->name[15] = k;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1:
        strncpy(mp->name, lbl_805F3CA8, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 2:
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        x->m15C = x->m15C ^ 1;
        fn_80510F28(x);
        break;
    }
}

extern "C" FE_OVERLAY void fn_80510500(FeScrQ* x, int a)
{
    if (a == x->m134) {
        fn_80510F28(x);
    }
}

extern "C" FE_OVERLAY void fn_8051052C()
{
}

extern "C" FE_OVERLAY void fn_80510530(FeScrQ* x)
{
    FeW* w = (FeW*)x->m13C;
    ((FeWX*)w)->s69(((FeWX*)w)->s84());
    fn_8051095C(x);
    fn_80510F28(x);
}

extern "C" FE_OVERLAY int fn_805105A4(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805105FC(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80510654(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805106AC(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80510704(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot50();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051075C(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot51();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805107B4(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot52();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051080C(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot53();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80510864(FeScrN* x)
{
    x->m134->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_805108A4(FeScrN* x, int a)
{
    x->m134->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_805108E0(FeScrN* x)
{
    x->m134->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80510920(FeScrN* x)
{
    x->m134->fn_vslot39();
    return 1;
}

