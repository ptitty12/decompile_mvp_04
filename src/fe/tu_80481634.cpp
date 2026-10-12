/*
 * Front-end overlay code, .frontend_codeoverlay 0x80481634-0x8048511C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
struct FeW88 : Unk800C7B40_Data {
    virtual ~FeW88();
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
    virtual void s87(); virtual void s88(int a, int b); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};

static inline int Fe2044At(int* a, int i)
{
    int o = i * 4;
    return *(int*)((char*)a + o);
}

struct Fe2DBCV {
    char pad0[0x178];
    int m178[25];
    int m1DC[25];
};
struct FeW92 : Unk800C7B40_Data {
    virtual ~FeW92();
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
    virtual void s92(int a, int b, int c); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
extern "C" void fn_804847CC(void* x, int a, int b);
struct Fe4178V {
    char pad0[0x178];
    int m178[25];
};
extern "C" void fn_80484BE4(int a);

static inline int Fe47CCAt(void* x, int off, int i)
{
    int o = i * 4;
    return *(int*)((char*)x + off + o);
}

extern "C" int fn_80484EB4(void* x, int a);

static inline int Fe23D8Pos(void* s, int k, int id)
{
    return (int)((void* (*)(void*, int, int))fn_8007B320__18Unk8007B2B0_Screenii)(s, k, id);
}

typedef void (*Fe4EB4Pop)(void*, void*, FeCbT, int, void*, int, int, int, int, int, int, int, int, int);
extern "C" void fn_800E4234__FiiPUs(int, int, unsigned short*);

extern "C" FE_OVERLAY FeScrH* fn_80481634(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677AC0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    FeI(self, 0x16C) = 0;
    FeI(self, 0x170) = -1;
    FeI(self, 0x174) = -1;
    FeI(self, 0x240) = 0;
    FeI(self, 0x244) = 1;
    FeI(self, 0x248) = 1;
    FeI(self, 0x24C) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80481F5C(char* x)
{
    int s = (int)lbl_8061930C;
    if (((int (*)(int, int))fn_8007E10C__FP13Unk8007DB74_A)(s, FeI(x, 0x134)) == 5) {
        int i = 0;
        int h = fn_8007E154__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), 0);
        do {
            fn_8007DD38__FP13Unk8007DB74_Aiiii(s, (int*)FeI(x, 0x134), i++, 0, h);
        } while (i <= 3);
    }
    if (FeI(x, 0x24C) == 1) {
        volatile int sp8 = 0;
        int e = 0;
        do {
            char* team = (char*)lbl_806192E0->m4->m14 + e * 0xE64;
            if (FeI(team, 0x198) == FeI(x, 0x134)) {
                ((void (*)(char*))fn_8009C6CC)(team);
            }
            int c = sp8;
            int t;
            if (c > 1)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 1);
    }
}

extern "C" FE_OVERLAY void fn_80482044(void* x)
{
    fn_800ECAA4(x);
    if (FeWp(x, 0x13C)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x13C))->s69(1);
        if (FeWp(x, 0x16C) != FeWp(x, 0x13C))
            FeWp(x, 0x13C)->fn_vslot14(0);
    }
    if (FeWp(x, 0x140)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x140))->s69(1);
        if (FeWp(x, 0x16C) != FeWp(x, 0x140))
            FeWp(x, 0x140)->fn_vslot14(0);
    }
    if (fn_8048495C(x) != 0) {
        FeW* cur = FeWp(x, 0x16C);
        if (cur == FeWp(x, 0x13C)) {
            int* a = ((Fe2DBCV*)x)->m178;
            int c = FeWp(x, 0x164)->fn_vslot86();
            if (c != Fe2044At(a, FeWp(x, 0x16C)->fn_vslot60())) {
                int v = Fe2044At(a, FeWp(x, 0x16C)->fn_vslot60());
                FeList* l = (FeList*)FeWp(x, 0x164);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        } else if (cur == FeWp(x, 0x140)) {
            int* a = ((Fe2DBCV*)x)->m1DC;
            int c = FeWp(x, 0x164)->fn_vslot87();
            if (c != Fe2044At(a, FeWp(x, 0x16C)->fn_vslot60())) {
                int v = Fe2044At(a, FeWp(x, 0x16C)->fn_vslot60());
                FeList* l = (FeList*)FeWp(x, 0x164);
                fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        }
    }
    fn_80482DBC(x);
    fn_800B555C();
    if (fn_800B57EC() == 0) {
        int f = ((unsigned)FeW24(FeWp(x, 0x144)) >> 30) & 1;
        if (f != (fn_804849FC(x) ^ 1))
            FeWp(x, 0x144)->fn_vslot16(fn_804849FC(x) ^ 1);
    }
}

extern "C" FE_OVERLAY int fn_80482348(void* x)
{
    if (fn_804849FC(x) != 0)
        return 0;
    int idx = FeWp(x, 0x16C)->fn_vslot60();
    FeW* cur = FeWp(x, 0x16C);
    if (cur == FeWp(x, 0x13C))
        fn_80484178(x, idx);
    else if (cur == FeWp(x, 0x140))
        fn_8048432C(x, idx);
    return 1;
}

extern "C" FE_OVERLAY int fn_804823D8(void* x)
{
    void* s = lbl_8061930C;
    int id;
    if (((int (*)(void*))fn_800A2EFC)(lbl_80619948) != 0
        || (fn_80484EB4(x, FeI(x, 0x134)) != 0
            && ((id = fn_80075948__18Unk8007B2B0_Screeni(s, FeI(x, 0x134)), ((int (*)(void*, int, int))fn_8007B3E0__18Unk8007B2B0_Screenii)(s, 0xE, id) == 0)
                || (fn_80484EB4(x, FeI(x, 0x134)) != 0 && fn_80484EB4(x, Fe23D8Pos(s, 0, id)) != 0 && fn_80484EB4(x, Fe23D8Pos(s, 1, id)) != 0
                    && fn_80484EB4(x, Fe23D8Pos(s, 2, id)) != 0 && fn_80484EB4(x, Fe23D8Pos(s, 3, id)) != 0)))) {
        FeMsg m;
        FeMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
    }
    return 1;
}

/* near-miss: 13 slots differ: callee-saved permutation of the element pointer, j, cnt and the saved base (p is merged with a) */
extern "C" FE_OVERLAY int fn_8048255C(void* x)
{
    if (fn_8048495C(x) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        FeW* cur = FeWp(x, 0x16C);
        if (cur == FeWp(x, 0x13C)) {
            FeList* l = (FeList*)FeWp(x, 0x164);
            fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            fn_80484A78(x, 1);
        } else if (cur == FeWp(x, 0x140)) {
            FeList* l = (FeList*)FeWp(x, 0x164);
            fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            fn_80484B18(x, 1);
        }
    } else {
        int v;
        int k = FeWp(x, 0x16C)->fn_vslot60();
        FeW* cur = FeWp(x, 0x16C);
        if (cur == FeWp(x, 0x13C)) {
            v = ((Fe2DBCV*)x)->m178[k];
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x164);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeW88*)FeWp(x, 0x164))->s88(0, FeWp(x, 0x16C)->fn_vslot59() > 1);
                fn_80484A78(x, 0);
            }
        } else if (cur == FeWp(x, 0x140)) {
            char* a = (char*)x + 0x1DC;
            int o = k * 4;
            v = *(int*)(a + o);
            if (v != 0) {
                Unk8001BC8C* c = fn_8001BC4C();
                int* p = (int*)a;
                int cnt = 0;
                c->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x164);
                fn_80126CF4(l, l->m164, *(int*)(a + o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                fn_80484B18(x, 0);
                int j;
                for (j = 0; j < FeWp(x, 0x140)->fn_vslot59(); j++, p++) {
                    if (*p != 0) {
                        cnt++;
                        if (cnt > 1)
                            break;
                    }
                }
                ((FeW88*)FeWp(x, 0x164))->s88(1, cnt > 1);
            }
        }
    }
    fn_800B555C();
    if (fn_800B57EC() == 0)
        FeWp(x, 0x144)->fn_vslot16(fn_804849FC(x) ^ 1);
    fn_80482DBC(x);
    FeWp(x, 0x164)->fn_vslot84(FeWp(x, 0x16C) != FeWp(x, 0x13C) ? 1 : 0, 0);
    fn_80483094(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804828CC(void* x)
{
    FeAt(x, 0x16C)->fn_vslot50();
    fn_80483094(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048291C(void* x)
{
    FeAt(x, 0x16C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80482958(void* x)
{
    FeAt(x, 0x16C)->fn_vslot52();
    fn_80483094(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804829A8(void* x)
{
    FeAt(x, 0x16C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804829E4(void* x)
{
    if (FeI(x, 0x16C) != FeI(x, 0x13C))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80483708(x, FeI(x, 0x13C));
    fn_80483094(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_80482A40(void* x)
{
    if (FeI(x, 0x16C) != FeI(x, 0x140))
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    fn_80483708(x, FeI(x, 0x140));
    fn_80483094(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_80482A9C(void* x)
{
    FeAt(x, 0x144)->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80482ADC(void* x, int a)
{
    FeAt(x, 0x144)->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80482B18(void* x)
{
    FeAt(x, 0x144)->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80482B58(void* x)
{
    FeAt(x, 0x144)->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_80482B94(void* x)
{
    if (FeI(x, 0x244) != 0) {
        FeWp(x, 0x148)->fn_vslot40(1);
        fn_80482D1C(x);
        fn_80483094(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80482BFC(void* x)
{
    if (FeI(x, 0x244) != 0) {
        ((FeWV*)FeWp(x, 0x148))->s41();
        fn_80482D1C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80482C58(void* x)
{
    if (FeI(x, 0x244) != 0) {
        FeWp(x, 0x148)->fn_vslot38(1);
        fn_80482D1C(x);
        fn_80483094(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80482CC0(void* x)
{
    if (FeI(x, 0x244) != 0) {
        ((FeWV*)FeWp(x, 0x148))->s39();
        fn_80482D1C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_80482D1C(void* x)
{
    FeW* a = FeWp(x, 0x15C);
    int v = ((FeSubB*)((char*)a + 0xDC))->s5();
    fn_800D0074((char*)FeWp(x, 0x14C) + 0x98, v, 1);
    fn_800D0074((char*)FeWp(x, 0x150) + 0xDC, v, 1);
    FeW* b = FeWp(x, 0x14C);
    fn_804834AC(x, ((FeSubC*)((char*)b + 0x98))->s21());
}

extern "C" FE_OVERLAY void fn_80482DBC(void* x)
{
    fn_80125100(FeVp(x, 0x160));
    if (fn_804849FC(x) != 0) {
        fn_80125084(FeVp(x, 0x160), 0);
    } else {
        if (FeI(x, 0x170) == -1 && FeI(x, 0x174) == -1) {
            fn_80125180(FeVp(x, 0x160), 0, 0x10);
        } else {
            int c = FeI(x, 0x174);
            int ok = 1;
            if (c != -1) {
                if (FeWp(x, 0x16C) == FeWp(x, 0x140)) {
                    int k = FeWp(x, 0x16C)->fn_vslot60();
                    int tbl[5] = { 0, 3, 7, 9, 10 };
                    if (c == tbl[3] && ((Fe2DBCV*)x)->m1DC[k] == 0) {
                        ok = 0;
                    } else {
                        int i;
                        for (i = 0; i < 4; i++) {
                            int lo = tbl[i];
                            if (k >= lo && c >= lo) {
                                int hi = tbl[i + 1];
                                if (k < hi && c < hi)
                                    ok = 0;
                            }
                        }
                    }
                }
            }
            if (ok != 0)
                fn_80125180(FeVp(x, 0x160), 0, 0xE12);
            else
                fn_80125084(FeVp(x, 0x160), 0);
        }
        int g = 0;
        if ((FeWp(x, 0x16C) == FeWp(x, 0x13C) && FeI(x, 0x170) == FeWp(x, 0x16C)->fn_vslot60())
            || (FeWp(x, 0x16C) == FeWp(x, 0x140) && FeI(x, 0x174) == FeWp(x, 0x16C)->fn_vslot60()))
            g = 1;
        if (g != 0)
            fn_80125180(FeVp(x, 0x160), 0, 0x3B97);
    }
    fn_80125180(FeVp(x, 0x160), 3, fn_8048495C(x) != 0 ? 0x37A2 : 0x1A2F);
    if (((FeWp(x, 0x16C) == FeWp(x, 0x140) && ((Fe2DBCV*)x)->m1DC[FeWp(x, 0x16C)->fn_vslot60()] == 0)
         || (FeWp(x, 0x16C) == FeWp(x, 0x13C) && ((Fe2DBCV*)x)->m178[FeWp(x, 0x16C)->fn_vslot60()] == 0))
        && (fn_80125084(FeVp(x, 0x160), 3), (FeI(x, 0x170) != -1 || FeI(x, 0x174) == -1)))
        fn_80125084(FeVp(x, 0x160), 0);
}

extern "C" FE_OVERLAY void fn_80483094(void* x)
{
    int v = 0;
    FeW* cur = FeWp(x, 0x16C);
    if (cur == FeWp(x, 0x13C)) {
        v = FePick((char*)x + 0x178, cur->fn_vslot60() * 4);
        fn_80122D40(FeWp(x, 0x168), v, 1, 1, FeI(x, 0x248) ^ 1, 0, (char*)x + 0x178);
    } else if (cur == FeWp(x, 0x140)) {
        v = FePick((char*)x + 0x1DC, cur->fn_vslot60() * 4);
        fn_80122D40(FeWp(x, 0x168), v, 1, 1, FeI(x, 0x248) ^ 1, 0, (char*)x + 0x1DC);
    }
    if (v != 0 && fn_80075808__Fi(FeI(x, 0x134)) == 0) {
        FeWp(x, 0x168)->fn_vslot32("TEAMLOGO", 1);
        ((FeSubV8*)((char*)fn_800C8054() + 0x98))->s8(FeI(x, 0x134));
    }
}

extern "C" FE_OVERLAY void fn_804831CC(void* x, FeW* w)
{
    if (w == FeWp(x, 0x144)) {
        FeW* a = FeWp(x, 0x150);
        fn_804834AC(x, ((FeSubC*)((char*)a + 0xDC))->s21());
    } else if (w == FeWp(x, 0x148)) {
        FeW* a = FeWp(x, 0x15C);
        int v = ((FeSubB*)((char*)a + 0xDC))->s5();
        fn_800D0074((char*)FeWp(x, 0x14C) + 0x98, v, 1);
        fn_800D0074((char*)FeWp(x, 0x150) + 0xDC, v, 1);
        FeW* b = FeWp(x, 0x14C);
        fn_804834AC(x, ((FeSubC*)((char*)b + 0x98))->s21());
    }
    fn_80483094(x);
}

extern "C" FE_OVERLAY void fn_804832BC(void* x, int a, int b)
{
    fn_804834AC(x, b);
    fn_80483094(x);
}

extern "C" FE_OVERLAY int fn_804832F4(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x13C)) {
        int t = FeI(x, 0x170);
        if ((t == -1 && FeI(x, 0x174) == -1) || t == c)
            fn_80484178(x, c);
        fn_80483708(x, FeI(x, 0x13C));
    } else if (a == FeI(x, 0x140)) {
        if (FeI(x, 0x170) == -1 && (FeI(x, 0x174) == -1 || FeI(x, 0x174) == c))
            fn_8048432C(x, c);
        fn_80483708(x, FeI(x, 0x140));
    }
    fn_80483094(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804833B4(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x13C)) {
        fn_80483708(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    } else if (w == FeWp(x, 0x140)) {
        fn_80483708(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    }
    fn_80483094(x);
    return 0;
}

extern "C" FE_OVERLAY void fn_804834AC(void* x, int a)
{
    fn_80484BE4(a);
    FeI(x, 0x134) = a;
    char* p14c = (char*)FeVp(x, 0x14C);
    ((FeSub*)(p14c + 0x98))->s20(a, 1);
    char* p150 = (char*)FeVp(x, 0x150);
    ((FeSub*)(p150 + 0xDC))->s20(a, 1);
    FePopup* p = fn_800B7AB8(FeGetMgr(), "FTOPBAR");
    int b = 1;
    void* s = lbl_8061930C;
    if (((int (*)(void*, int, int))fn_8007B3E0__18Unk8007B2B0_Screenii)(s, 0xE, fn_80075948__18Unk8007B2B0_Screeni(s, a)) == 0)
        b = 0;
    fn_804A763C(p, b ^ 1);
    FeAt(x, 0x148)->fn_vslot16(b);
    ((FeWV*)FeAt(x, 0x148))->s44(b);
    fn_80483A9C(x);
    FeAt(x, 0x16C)->fn_vslot68(0);
    FeAt(x, 0x13C)->fn_vslot14(0);
    FeAt(x, 0x140)->fn_vslot14(0);
}

extern "C" FE_OVERLAY void fn_80483654(void* x, int a)
{
    FeI(x, 0x138) = a;
    FeW* w = FeWp(x, 0x158);
    ((FeSubB*)((char*)w + 0xDC))->s6();
    fn_80483A9C(x);
    FeWp(x, 0x16C)->fn_vslot68(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x140)->fn_vslot14(0);
}

extern "C" FE_OVERLAY void fn_80483708(void* x, int wi)
{
    FeW* w = (FeW*)wi;
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x140)->fn_vslot14(0);
    FeWp(x, 0x16C) = w;
    w->fn_vslot14(1);
    if (w == FeWp(x, 0x13C))
        FeWp(x, 0x164)->fn_vslot84(0, 0);
    else if (w == FeWp(x, 0x140))
        FeWp(x, 0x164)->fn_vslot84(1, 0);
}

extern "C" FE_OVERLAY void fn_804837F8(void* g, FeW* w, int v, int* arr, int idx, int strid)
{
    char buf[80];
    char sbuf[104];
    int ok;
    if (((int (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(g, 0x1F, v) <= 0)
        ok = 0;
    else
        ok = 1;
    if (ok != 0)
        v = 0;
    arr[idx] = v;
    w->fn_vslot43(idx, 0, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, strid), 4);
    if (v != 0) {
        fn_800DE440(buf, v, 1);
        w->fn_vslot43(idx, 1, buf, 4);
        int r = ((int (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(g, 9, v);
        w->fn_vslot43(idx, 2, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, ((int (*)(int))fn_800E60E0__Fi)(r)), 4);
        float fa = (float)((int (*)(void*, int, int))fn_8007AB9C__18Unk8007A4DC_Screenii)(g, 0x1B, v);
        float fb = (float)((int (*)(void*, int, int))fn_8007AB9C__18Unk8007A4DC_Screenii)(g, 0, v);
        ((int (*)(char*, const char*, ...))fn_804089B4)(sbuf, "%d%%", (int)(fa / fb * 100.0f));
        w->fn_vslot44(idx, 3, sbuf, 5);
    } else {
        fn_80403144(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x37F5));
        w->fn_vslot43(idx, 1, buf, 4);
        w->fn_vslot44(idx, 2, " ", 4);
        ((FeW92*)w)->s92(idx, 3, 0);
    }
}

/* near-miss: 11 slots differ: callee-saved r29/r30 swapped (b vs id); same instructions otherwise */
extern "C" FE_OVERLAY void fn_80484178(void* x, int b)
{
    int e = ((Fe4178V*)x)->m178[b];
    int s = (int)lbl_8061930C;
    int id;
    if (FeI(x, 0x170) == -1) {
        if (FeI(x, 0x174) != -1 || e != 0) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            int c = FeI(x, 0x174);
            if (c == -1) {
                FeI(x, 0x170) = b;
                ((FeWV90*)FeAt(x, 0x13C))->s90(b, 1, 1);
            } else
                fn_804847CC(x, b, c);
        }
    } else {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        if (b == FeI(x, 0x170)) {
            ((FeWV90*)FeAt(x, 0x13C))->s90(b, 1, 0);
            FeI(x, 0x170) = -1;
        } else if (((Fe4178V*)x)->m178[b] != 0) {
            ((FeWV90*)FeAt(x, 0x13C))->s90(FeI(x, 0x170), 1, 0);
            fn_800B555C();
            if (fn_800B57EC() == 1)
                id = fn_8007E1F8__FP13Unk8007DB74_A(s, (int*)FeI(x, 0x134));
            else
                id = 0;
            fn_8007E39C__FP13Unk8007DB74_Aiii(s, (int*)FeI(x, 0x134), ((Fe4178V*)x)->m178[FeI(x, 0x170)], b);
            fn_8007E39C__FP13Unk8007DB74_Aiii(s, (int*)FeI(x, 0x134), ((Fe4178V*)x)->m178[b], FeI(x, 0x170));
            if (id != 0)
                fn_8007E43C__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), id);
            FeI(x, 0x170) = -1;
            fn_80483A9C(x);
        }
    }
}

extern "C" FE_OVERLAY void fn_804847CC(void* x, int a, int b)
{
    int o = b * 4;
    char* p1 = (char*)x + 0x1DC;
    int s = (int)lbl_8061930C;
    int idB = *(int*)(p1 + o);
    int idA = Fe47CCAt(x, 0x178, a);
    if (((int (*)(int, int*, int))fn_8007E7F0__FP13Unk8007DB74_Aii)(s, (int*)FeI(x, 0x134), idB) != 0) {
        fn_8007E618__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB);
        if (idA != 0)
            fn_8007E598__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idA);
    } else if (fn_8007EAF0__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB) != 0) {
        fn_8007E994__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB);
        if (idA != 0)
            fn_8007E898__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idA);
    } else if (fn_8007EDF0__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB) != 0) {
        fn_8007EC94__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB);
        if (idA != 0)
            fn_8007EB98__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idA);
    } else if (fn_8007F0F0__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB) != 0) {
        fn_8007EF94__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idB);
        if (idA != 0)
            fn_8007EE98__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), idA);
    } else
        return;
    if (a <= 4)
        fn_8007E39C__FP13Unk8007DB74_Aiii(s, (int*)FeI(x, 0x134), *(int*)(p1 + o), a);
    else
        fn_8007E34C__FP13Unk8007DB74_Aii(s, (int*)FeI(x, 0x134), *(int*)(p1 + o));
    fn_80483A9C(x);
}

extern "C" FE_OVERLAY int fn_8048495C(void* x)
{
    if (FeI(x, 0x16C) == FeI(x, 0x13C)) {
        if (FeWp(x, 0x164)->fn_vslot86() != 0)
            return 1;
    }
    if (FeI(x, 0x16C) == FeI(x, 0x140)) {
        if (FeWp(x, 0x164)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804849FC(void* x)
{
    int r = 0;
    if (FeWp(x, 0x164)->fn_vslot86() != 0 || FeWp(x, 0x164)->fn_vslot87() != 0)
        r = 1;
    return r;
}

extern "C" FE_OVERLAY void fn_80484A78(void* x, int a)
{
    int i;
    int n = FeWp(x, 0x13C)->fn_vslot59();
    for (i = 0; i < n; i++) {
        int o = i * 4;
        char* b = (char*)x + 0x178;
        if (*(int*)(b + o) == 0)
            ((FeWV*)FeWp(x, 0x13C))->s101(i, a);
    }
}

extern "C" FE_OVERLAY void fn_80484B18(void* x, int a)
{
    int i = 0;
    int o = 0;
    for (; i < FeWp(x, 0x140)->fn_vslot59(); i++) {
        if (FePick((char*)x + 0x1DC, o) == 0) {
            int j;
            for (j = 0; j < FeWp(x, 0x140)->fn_vslot58(); j++)
                ((FeWV91*)FeWp(x, 0x140))->s91(i, j, a);
        }
        o += 4;
    }
}

extern "C" FE_OVERLAY void fn_80484BE4(int a)
{
    FeArr arr;
    char buf[160];
    FeArr* p = &arr;
    int* ap = (int*)a;
    unsigned i;
    p->m10 = lbl_8064B298;
    arr.m0 = buf;
    p->m8 = 0x28;
    int s = (int)lbl_8061930C;
    fn_8040074C(arr.m0, 0xA0);
    p->m4 = 0;
    p->mC = 0;
    p->m10 = lbl_8064A550;
    fn_8040074C(arr.m0, p->m8 * 4);
    p->m10 = lbl_8064A4C8;
    p->m4 = 0;
    p->mC = 0;
    p->m14 = 0;
    fn_80536D68((void**)p, ap);
    fn_805362AC((void**)p, 1);
    for (i = 0; i < (unsigned)p->m4; i++) {
        int id = *(int*)((char*)arr.m0 + (i << 2));
        if (fn_8007A270__18Unk8007A4DC_Screeni((void*)s, id) != 0) {
            int f;
            if (((int (*)(int, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(s, 0x1E, id) == 0)
                f = 0;
            else
                f = 1;
            if (f == 0 && fn_8007E48C__FP13Unk8007DB74_Aii(s, ap, id) == 0 && ((int (*)(int, int*, int))fn_8007E7F0__FP13Unk8007DB74_Aii)(s, ap, id) == 0
                && fn_8007EAF0__FP13Unk8007DB74_Aii(s, ap, id) == 0 && fn_8007EDF0__FP13Unk8007DB74_Aii(s, ap, id) == 0
                && fn_8007F0F0__FP13Unk8007DB74_Aii(s, ap, id) == 0) {
                int found = 0;
                int z = ((int (*)(int, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(s, 5, id) == 0;
                int j;
                for (j = 0; j <= 1; j++) {
                    if ((j == 0 && z != 0) || (j == 1 && z == 0)) {
                        if (((int (*)(int, int*))fn_8007E10C__FP13Unk8007DB74_A)(s, ap) <= 4) {
                            fn_8007E34C__FP13Unk8007DB74_Aii(s, ap, id);
                            found = 1;
                        }
                    } else if (fn_8007F0A8__FP13Unk8007DB74_Ai(s, ap) <= 0) {
                        fn_8007EE98__FP13Unk8007DB74_Aii(s, ap, id);
                        found = 1;
                    } else if (fn_8007E7A8__FP13Unk8007DB74_Ai(s, ap) <= 2) {
                        fn_8007E598__FP13Unk8007DB74_Aii(s, ap, id);
                        found = 1;
                    } else if (fn_8007EAA8__FP13Unk8007DB74_Ai(s, ap) <= 3) {
                        fn_8007E898__FP13Unk8007DB74_Aii(s, ap, id);
                        found = 1;
                    } else if (fn_8007EDA8__FP13Unk8007DB74_Ai(s, ap) <= 1) {
                        fn_8007EB98__FP13Unk8007DB74_Aii(s, ap, id);
                        found = 1;
                    }
                    if (found != 0)
                        break;
                }
            }
        }
    }
    arr.m10 = lbl_8064A550;
}

extern "C" FE_OVERLAY int fn_80484EB4(void* x, int a)
{
    int s = (int)lbl_8061930C;
    if (((int (*)(int))fn_8007E10C__FP13Unk8007DB74_A)(s) > 4 && ((int (*)(int, int))fn_8007F0A8__FP13Unk8007DB74_Ai)(s, a) > 0)
        return 1;
    char buf[2000];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    fn_800E4234__FiiPUs(a, 2, (unsigned short*)buf);
    fn_800DFF0C(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F40));
    FeI(x, 0x240) = a;
    int s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4558);
    int s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4DA6);
    int s3 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F41);
    ((Fe4EB4Pop)fn_801321D4)(p, x, (FeCbT)fn_80485008, 0, buf, 3, -1, 1, s1, s2, s3, 0, 0, 0);
    p->fn_vslot86();
    return 0;
}

extern "C" FE_OVERLAY void fn_80485008(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            if (fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x240)) == 0) {
                fn_8055F5A0(FeI(x, 0x240));
            } else {
                int sp18;
                int sp1C;
                fn_80562E34(FeI(x, 0x240));
                sp18 = 0;
                sp1C = 0;
                if (fn_800A3270(lbl_80619948, &sp18, &sp1C) == 0)
                    fn_8055EAFC((void*)FeI(x, 0x240));
            }
            fn_80483A9C(x);
            fn_80483094(x);
            fn_80482DBC(x);
        } else if (a == 2) {
            FeMsg m;
            FeMsg* p = &m;
            fn_8035682C(p);
            fn_8040B830(p->name, "BACK", 15);
            p->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), p, x);
        }
    }
}
