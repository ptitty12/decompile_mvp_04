/*
 * Front-end overlay code, .frontend_codeoverlay 0x8049B0CC-0x8049E0BC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_805F74C4[];
extern "C" char* strncpy(char*, const char*, unsigned);
extern "C" char fn_800B56C4(void* s);
extern "C" void fn_8049D5C8(void* x);
struct Fe9B90Arr {
    char* m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
};
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A4C8[];
extern const char lbl_805F5010[];
extern const char lbl_805F4ECC[];
extern void* lbl_8061977C;
extern "C" int sprintf(char*, const char*, ...);
extern "C" void fn_8040074C(void* p, int n);
extern "C" void fn_80538868(Fe9B90Arr* l, int a);
extern "C" float fn_8007824C(int v, int a);
extern "C" int fn_8007A6A0__18Unk8007A4DC_Screenii(void* g, int a, int b);
extern "C" int fn_800E5F38__Fi(int v);
inline int IntAt9B90(char* b, int o) { return *(int*)(b + o); }
extern const char lbl_805F4F8C[];
extern const char lbl_805F54DC[];
extern const char lbl_805F55BC[];
extern const char lbl_805F55C8[];
extern const char lbl_805F55D4[];
extern const char lbl_805F55DC[];
extern const char lbl_805F55E4[];
extern const char lbl_805F55F0[];
extern const char lbl_805F55F8[];
extern const char lbl_805F5600[];
extern const char lbl_805F74D0[];
extern "C" int fn_800C203C(void* p);
extern "C" FeW* fn_800C8038(FeW* w);

struct Fe9B304Scr : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    char pad138[0x19C - 0x138];
    FeW* m19C;
    FeW* m1A0;
    FeW* m1A4;
    FeW* m1A8;
    FeW* m1AC;
    FeW* m1B0;
    FeW* m1B4;
    FeW* m1B8;
    FeW* m1BC;
    FeW* m1C0;
    FeW* m1C4;
};
struct FeW9CF5 : Unk800C7B40_Data {
    virtual ~FeW9CF5();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(int a); virtual void s15();
    virtual void s16(int a); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25();
    virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual int s59(); virtual void s60();
    virtual int s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
    virtual void s66(); virtual void s67(); virtual void s68(int a); virtual void s69(int a);
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(int a, int b, void* c); virtual void s87();
    virtual void s88(int a, int b); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106();
    virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116();
    virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120(); virtual void s121();
    virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126();
    virtual void s127();
};
struct Fe9CF5St {
    char pad0[0x66C];
    int m66C;
    int m670;
};
extern "C" int fn_80084014__Fii(int a, int b);
extern const char lbl_805F74F0[];
extern const char lbl_805F57D0[];
extern const char lbl_805F4F20[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F5DA0[];
extern const char lbl_805F5D8C[];
extern const char lbl_805F5854[];
extern const char lbl_805F5818[];
extern const char lbl_805F5068[];
extern const char lbl_805F5080[];
extern const char lbl_805F74E0[];
extern const char lbl_805F74E8[];
extern const char lbl_805F5D94[];
extern "C" void fn_8049DCE0(void* x);
extern "C" void fn_800DD204__FP3UiST0(FeW* a, FeW* b);
struct Fe9C524Sub : FeSubData {
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
    virtual void s11();
    virtual void s12(int a);
};
struct Fe9C524St {
    int m0;
    char pad4[0x508 - 4];
    int m508;
    int m50C;
    int m510;
    int m514;
    char pad518[0x66C - 0x518];
    int m66C;
    int m670;
};
static inline int Hi9C524(FeW9CF5* w)
{
    return w->s59() - 1 > 0 ? w->s59() - 1 : 0;
}
struct Fe9C524Scr : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    FeW* m13C;
    FeW* m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    FeW* m150;
    FeW* m154;
    FeW* m158;
    int m15C;
    int m160;
    char pad164[0x334 - 0x164];
    int m334;
};
extern "C" {

FE_OVERLAY void fn_8049B0CC(void* x)
{
    fn_800ECAA4(x);
    int* p = (int*)FeP(x, 0x134);
    if (p != 0 && *p == 0) {
        fn_800CFB38(p);
    }
}

FE_OVERLAY void fn_8049B114(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8049B134(void) {}

FE_OVERLAY void fn_8049B138(void) {}

FE_OVERLAY void fn_8049B13C(void) {}

FE_OVERLAY int fn_8049B140(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8049B19C(FeW* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    char t = fn_800B56C4(fn_800B555C());
    if (t != 0) {
        strncpy(mp->name, lbl_805F3CA8, 15);
        mp->name[15] = 0;
    } else if (fn_800B5758(fn_800B555C()) != 0) {
        strncpy(mp->name, lbl_805F74C4, 15);
        mp->name[15] = t;
    } else {
        ((FeWQ*)x)->s79((int)mp);
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}

FE_OVERLAY int fn_8049B280(void) { return 0; }

FE_OVERLAY void fn_8049B288(int a, char* dst)
{
    fn_8040B830(dst, &lbl_805F36A0.c0, 16);
}

extern const char lbl_80675318[];
FE_OVERLAY FeScrH* fn_8049B2B8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675318);
    self->m130 = 0;
    return self;
}

extern "C" void fn_8049B90C(FeScrB* x);
extern "C" void fn_8049BB90(FeScrB* x);
extern "C" void fn_8049C440(FeScrB* x);
FE_OVERLAY void fn_8049B304(Fe9B304Scr* x)
{
    fn_800ECF18(x);
    x->m1A0 = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    x->m1A4 = fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
    fn_80126CF4((FeList*)x->m1A4, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0);
    x->m19C = fn_800C8060(x->fn_vslot29(lbl_805F74D0));
    x->m1A8 = fn_800C8044(x->fn_vslot32(lbl_805F55BC, 1));
    x->m1AC = fn_800C8044(x->fn_vslot32(lbl_805F55C8, 1));
    FeW* w30 = fn_800C8044(x->m1AC->fn_vslot32(lbl_805F55D4, 1));
    x->m1B0 = fn_800C8038(x->m1A8->fn_vslot32(lbl_805F55DC, 1));
    x->m1B4 = fn_800C8040(x->m1AC->fn_vslot32(lbl_805F55E4, 1));
    x->m1B8 = fn_800C8040(x->m1AC->fn_vslot32(lbl_805F54DC, 1));
    x->m1BC = fn_800C8040(w30->fn_vslot32(lbl_805F55F0, 1));
    x->m1C0 = fn_800C8040(w30->fn_vslot32(lbl_805F55F8, 1));
    x->m1C4 = fn_800C8040(w30->fn_vslot32(lbl_805F5600, 1));
    x->m134 = fn_800C203C((char*)fn_800B555C() + 8);
    fn_8049B90C((FeScrB*)x);
    fn_8049BB90((FeScrB*)x);
    fn_8049C440((FeScrB*)x);
}

FE_OVERLAY void fn_8049B5BC(void* x, int kind)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (kind) {
    case 0:
        strncpy(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1: {
        int idx = FeMem(x, 0x19C)->fn_vslot60();
        FeList* q = (FeList*)FeP(x, 0x1A4);
        char* b = (char*)x + 0x138;
        int off = idx * 4;
        fn_80126CF4(q, q->m164, *(int*)(b + off), q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
        ((FeWR*)FeP(x, 0x1A4))->s84(1, 0);
        ((FeWQ*)FeP(x, 0x1A4))->s8(1);
        ((FeWQ*)FeP(x, 0x19C))->s16(0);
        fn_8049C440((FeScrB*)x);
        break;
    }
    case 2:
        ((FeWR*)FeP(x, 0x1A4))->s84(2, 0);
        ((FeWQ*)FeP(x, 0x1A4))->s8(0);
        ((FeWQ*)FeP(x, 0x19C))->s16(1);
        fn_8049C440((FeScrB*)x);
        break;
    }
}

FE_OVERLAY void fn_8049B7A8(FeScrB* x, int a, int b)
{
    x->m134 = b;
    fn_8049B90C(x);
    fn_8049BB90(x);
    fn_8049C440(x);
}

FE_OVERLAY int fn_8049B7E8(void* x)
{
    FeMem(x, 0x19C)->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8049B824(void* x)
{
    FeMem(x, 0x19C)->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8049B860(void* x)
{
    FeMem(x, 0x19C)->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8049B89C(void* x)
{
    FeMem(x, 0x19C)->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_8049B8D8(FeScrB* x)
{
    fn_8049BB90(x);
    fn_8049C440(x);
}

FE_OVERLAY void fn_8049B90C(FeScrB* x)
{
    Fe9B90Arr l1;
    int b1[0x28];
    char sbuf[0x68];
    char wbuf[200];
    Fe9B90Arr* s1 = &l1;
    unsigned i;
    s1->m10 = lbl_8064B298;
    l1.m0 = (char*)b1;
    s1->m8 = 0x28;
    FeI(x, 0x138) = 0;
    fn_8040074C(l1.m0, 0xA0);
    s1->m4 = 0;
    s1->mC = 0;
    s1->m10 = lbl_8064A550;
    fn_8040074C(l1.m0, s1->m8 * 4);
    void* g = lbl_8061930C;
    s1->m10 = lbl_8064A4C8;
    s1->m4 = 0;
    s1->mC = 0;
    s1->m14 = 0;
    fn_80538868(s1, FeI(x, 0x134));
    FeMem(x, 0x19C)->fn_vslot79(s1->m4, 0);
    FeMem(x, 0x19C)->fn_vslot3();
    i = 0;
    for (; i < (unsigned)s1->m4; i++) {
        int off = i * 4;
        int id = IntAt9B90(l1.m0, off);
        char* b138 = (char*)x + 0x138;
        *(int*)(b138 + off) = id;
        FeMem(x, 0x19C)->fn_vslot44(i, 0, (char*)fn_800E5F38__Fi(fn_8007A6A0__18Unk8007A4DC_Screenii(g, 5, id)), 4);
        fn_800DE440(wbuf, id, 3);
        FeMem(x, 0x19C)->fn_vslot43(i, 1, wbuf, 4);
        float f = fn_8007824C(id, 0);
        sprintf(sbuf, lbl_805F5010, f);
        FeMem(x, 0x19C)->fn_vslot44(i, 2, sbuf, 4);
        sprintf(sbuf, lbl_805F4ECC, fn_8007A6A0__18Unk8007A4DC_Screenii(g, 0x1F, id));
        FeMem(x, 0x19C)->fn_vslot44(i, 3, sbuf, 4);
    }
    FeMem(x, 0x19C)->fn_vslot14(1);
    l1.m10 = lbl_8064A550;
}

FE_OVERLAY void fn_8049C440(FeScrB* x)
{
    fn_80124FA8(FeP(x, 0x1A0), x);
    fn_80125154(FeP(x, 0x1A0), 0);
    if (FeW24(FeP(x, 0x1A4)) < 0) {
        fn_801251CC(FeP(x, 0x1A0), 3, 0x37A2, 2);
    } else if (FeI(x, 0x138) != 0) {
        fn_801251CC(FeP(x, 0x1A0), 3, 0x1A2F, 1);
    } else {
        fn_80125084(FeP(x, 0x1A0), 3);
    }
}

extern const char lbl_80675070[];
FE_OVERLAY FeScrH* fn_8049C4D8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675070);
    self->m130 = 0;
    return self;
}

static inline int Kind9C524()
{
    if (((Fe9C524St*)fn_800B555C())->m0 == 0x18) {
        return 0;
    }
    int r = 2;
    if (((Fe9C524St*)fn_800B555C())->m0 == 0x19) {
        r = 1;
    }
    return r;
}
FE_OVERLAY void fn_8049C524(FeScrD* xx)
{
    Fe9C524Scr* x = (Fe9C524Scr*)xx;
    fn_800ECF18(x);
    fn_8049D430((char*)x);
    FeW* w29 = fn_800C8044(x->fn_vslot32(lbl_805F57D0, 1));
    if (((Fe9C524St*)fn_800B555C())->m0 == 0x18) {
        x->m334 = 0;
    } else if (((Fe9C524St*)fn_800B555C())->m0 == 0x19) {
        x->m334 = 1;
    } else {
        x->m334 = 2;
    }
    ((FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F20))->fn_vslot8(0);
    int sv = 0x190B;
    switch (FeI(x, 0x334)) {
    case 1:
        break;
    case 2:
        sv = 0x1AEF;
        break;
    case 0:
        sv = 0x1B94;
        break;
    }
    FeW* w30 = fn_800C8040(w29->fn_vslot33(4, 1));
    ((FeWQ*)w30)->s29(sv);
    fn_800DD204__FP3UiST0(w30, fn_800C8038(w29->fn_vslot33(2, 1)));
    x->m138 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    x->m13C = fn_800C8040(x->fn_vslot32(lbl_805F5DA0, 1));
    x->m140 = fn_800C8040(x->fn_vslot32(lbl_805F5D8C, 1));
    x->m144 = fn_800C8040(x->fn_vslot32(lbl_805F5854, 1));
    x->m148 = fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
    x->m150 = fn_800B7AB8(FeGetMgr(), lbl_805F5818);
    FeW* w154 = fn_800C805C(x->fn_vslot32(lbl_805F5068, 1));
    x->m154 = w154;
    x->m158 = fn_800C8058(w154->fn_vslot32(lbl_805F5080, 1));
    x->fn_vslot32(lbl_805F74E0, 1)->fn_vslot8(x->m334 == 2);
    x->fn_vslot32(lbl_805F74E8, 1)->fn_vslot8(x->m334 == 2 ? 0 : 1);
    x->fn_vslot32(lbl_805F5D94, 1)->fn_vslot8(fn_800B56C4(fn_800B555C()));
    if (x->m334 == 1) {
        ((FeW9CF5*)FeMem(x, 0x154))->s16(0);
        FeMem(x, 0x154)->fn_vslot8(0);
    }
    int m = FeI(x, 0x334);
    if (m == 0) {
        ((Fe9C524Sub*)((char*)FeP(x, 0x158) + 0xDC))->s6(((Fe9C524St*)fn_800B555C())->m66C);
    } else if (m == 2) {
        ((Fe9C524Sub*)((char*)FeP(x, 0x158) + 0xDC))->s6(((Fe9C524St*)fn_800B555C())->m670);
    } else {
        Fe9C524St* st2 = (Fe9C524St*)fn_800B555C();
        Fe9C524Sub* sb = (Fe9C524Sub*)((char*)x->m158 + 0xDC);
        sb->s12(st2->m50C);
    }
    fn_8049D5C8(x);
    fn_8049DCE0(x);
    x->m15C = ((Fe9C524St*)fn_800B555C())->m510;
    int t = ((Fe9C524St*)fn_800B555C())->m514;
    x->m160 = t;
    if (FeI(x, 0x15C) == 1) {
        ((FeW9CF5*)FeP(x, 0x138))->s86(2, t ^ 1, (char*)x + 0x164);
    }
    ((FeW9CF5*)FeP(x, 0x138))->s86(FeI(x, 0x15C), FeI(x, 0x160), (char*)x + 0x164);
    ((FeW9CF5*)FeP(x, 0x138))->s68(0);
    x->m14C = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_8049CBD4(x);
    int st = ((Fe9C524St*)fn_800B555C())->m508;
    if (st == -1) {
        st = 0;
    }
    ((FeW9CF5*)x->m138)->s68(((((FeW9CF5*)x->m138)->s59() - 1 > 0) ? (((FeW9CF5*)x->m138)->s59() - 1 >= st) : (st <= 0)) ? st : (((FeW9CF5*)x->m138)->s59() - 1 > 0 ? ((FeW9CF5*)x->m138)->s59() - 1 : 0));
    ((FeWV*)x)->s40();
}

FE_OVERLAY void fn_8049CBD4(void* x)
{
    fn_80124FA8(FeP(x, 0x14C), x);
    fn_80125154(FeP(x, 0x14C), 0);
    if (FeI(x, 0x164) != 0) {
        fn_801251CC(FeP(x, 0x14C), 0, 0x37F2, 1);
        fn_801251CC(FeP(x, 0x14C), 3, 0x1A2F, 2);
        fn_801251CC(FeP(x, 0x14C), 2, 0x201A, 4);
    } else {
        fn_80125084(FeP(x, 0x14C), 0);
        fn_80125084(FeP(x, 0x14C), 3);
    }
}

FE_OVERLAY void fn_8049CC78(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8049CC98(void* x)
{
    char* p = (char*)fn_800B555C() + 8;
    FeI(p, 0x500) = FeMem(x, 0x138)->fn_vslot60();
    char* q = (char*)fn_800B555C() + 8;
    FeI(q, 0x504) = fn_800B548C(((FeSub*)((char*)FeP(x, 0x158) + 0xDC))->s5());
    FeI(fn_800B555C(), 0x510) = FeI(x, 0x15C);
    FeI(fn_800B555C(), 0x514) = FeI(x, 0x160);
}

FE_OVERLAY void fn_8049CD30(void* x, FeW* y)
{
    if (y == FeMem(x, 0x138)) {
        if (((FeWI*)FeMem(x, 0x148))->s86() != 0) {
            int idx = FeMem(x, 0x138)->fn_vslot60();
            int o = idx * 4;
            char* b = (char*)x + 0x164;
            FeList* l = (FeList*)FeP(x, 0x148);
            fn_80126CF4(l, *(int*)(b + o), FeI(l, 0x168), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
        fn_8049DE70((char*)x);
    }
}

FE_OVERLAY int fn_8049CDF4(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8049CE30(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8049CE6C(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8049CEA8(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_8049CEE4(FeScrF* x, FeW* w, int a, int b)
{
    if (w == x->m138) {
        w->fn_vslot68(b);
        x->fn_vslot67(2, 0);
    }
    return 0;
}

FE_OVERLAY void fn_8049CF5C(void* x, int kind)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (kind) {
    case 0: {
        ((FeW9CF5*)FeP(x, 0x138))->s68(0);
        int t = FeI(x, 0x334);
        if (t == 0) {
            ((Fe9CF5St*)fn_800B555C())->m66C = 4;
        } else if (t == 2) {
            ((Fe9CF5St*)fn_800B555C())->m670 = 4;
        }
        FeI(x, 0x15C) = 3;
        FeI(x, 0x160) = 1;
        strncpy(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
    case 1: {
        int idx = FeMem(x, 0x138)->fn_vslot60();
        char* b = (char*)x + 0x164;
        int off = idx * 4;
        int v = *(int*)(b + off);
        fn_800B555C()->m30 = v;
        strncpy(mp->name, lbl_805F74F0, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
    case 2: {
        int f = 1;
        ((FeW9CF5*)FeP(x, 0x138))->s14(1);
        int own = FeI(x, 0x334) == 1;
        int idx = FeMem(x, 0x138)->fn_vslot60();
        char* b = (char*)x + 0x164;
        int off = idx * 4;
        int v = *(int*)(b + off);
        int q = fn_80077BC4(lbl_8061930C, v);
        if (q != 0) {
            f = fn_80084014__Fii(fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, q), 1);
        }
        fn_80126CF4((FeList*)FeP(x, 0x148), v, 0, 0, f, 0, own, 1, 0, 1, 0);
        ((FeW9CF5*)FeP(x, 0x148))->s88(0, ((FeW9CF5*)FeP(x, 0x138))->s59() > 1);
        fn_801251CC(FeP(x, 0x14C), 3, 0x37A2, 3);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        FeW* w = FeMem(x, 0x154);
        if (FeW24(w) < 0) {
            ((FeW9CF5*)w)->s16(0);
        }
        break;
    }
    case 3: {
        FeList* l = (FeList*)FeP(x, 0x148);
        fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        fn_801251CC(FeP(x, 0x14C), 3, 0x1A2F, 2);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        FeW* w = FeMem(x, 0x154);
        if (FeW24(w) < 0) {
            ((FeW9CF5*)w)->s16(1);
        }
        break;
    }
    case 4: {
        if (((FeW9CF5*)FeP(x, 0x138))->s61() == FeI(x, 0x15C)) {
            FeI(x, 0x160) = FeI(x, 0x160) ^ 1;
        } else {
            int f = 0;
            if (((FeW9CF5*)FeP(x, 0x138))->s61() == 3 || ((FeW9CF5*)FeP(x, 0x138))->s61() == 5) {
                f = 1;
            }
            FeI(x, 0x160) = f;
        }
        FeI(x, 0x15C) = ((FeW9CF5*)FeP(x, 0x138))->s61();
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        fn_8049D5C8(x);
        if (FeI(x, 0x15C) == 1) {
            ((FeW9CF5*)FeP(x, 0x138))->s86(2, FeI(x, 0x160) ^ 1, (char*)x + 0x164);
        }
        ((FeW9CF5*)FeP(x, 0x138))->s86(FeI(x, 0x15C), FeI(x, 0x160), (char*)x + 0x164);
        ((FeW9CF5*)FeP(x, 0x138))->s68(0);
        ((FeW9CF5*)FeP(x, 0x138))->s69(FeI(x, 0x15C));
        break;
    }
    }
}

FE_OVERLAY void fn_8049D430(char* x)
{
    int i;
    for (i = 0; i < 0x1D; i++) {
        char* b = x + 0x164;
        int o = i * 4;
        *(int*)(b + o) = 0;
    }
}

FE_OVERLAY void fn_8049D454(void* x, FeW* w)
{
    if (w == FeMem(x, 0x154)) {
        int k = FeI(x, 0x334);
        if (k == 0) {
            char* b = (char*)fn_800B555C() + 8;
            FeI(b, 0x664) = ((FeSubI*)((char*)FeP(x, 0x158) + 0xDC))->s5();
        } else if (k == 2) {
            char* b = (char*)fn_800B555C() + 8;
            FeI(b, 0x668) = ((FeSubI*)((char*)FeP(x, 0x158) + 0xDC))->s5();
        }
        int v = ((FeWI*)FeMem(x, 0x138))->s61();
        fn_8049D5C8(x);
        fn_8049CBD4(x);
        if (FeI(x, 0x15C) == 1) {
            ((FeWT*)FeMem(x, 0x138))->s86(2, FeI(x, 0x160) ^ 1, (char*)x + 0x164);
        }
        ((FeWT*)FeMem(x, 0x138))->s86(FeI(x, 0x15C), FeI(x, 0x160), (char*)x + 0x164);
        FeMem(x, 0x138)->fn_vslot68(0);
        ((FeWQ*)FeMem(x, 0x138))->s69(v);
    }
}

FE_OVERLAY void fn_8049DE70(char* x)
{
    int idx = FeMem(x, 0x138)->fn_vslot60();
    char* b = x + 0x164;
    int o = idx * 4;
    fn_804A96A4(FeP(x, 0x150), *(int*)(b + o), 1, 2, 1, FeI(x, 0x334) == 1, 0, 0);
}

FE_OVERLAY void fn_8049DEEC(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

FE_OVERLAY int fn_8049DF3C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot56();
    return 1;
}

FE_OVERLAY int fn_8049DF9C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot57();
    return 1;
}

FE_OVERLAY int fn_8049DFFC(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot54();
    return 1;
}

FE_OVERLAY int fn_8049E05C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot55();
    return 1;
}

}
