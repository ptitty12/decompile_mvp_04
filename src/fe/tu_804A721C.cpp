/*
 * Front-end overlay code, .frontend_codeoverlay 0x804A721C-0x804AA58C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"
struct Fe83D0V : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    int m13C;
    FeW* m140;
    FeW* m144;
};
struct FeW79 : Unk800C7B40_Data {
    virtual ~FeW79();
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
    virtual void s77(); virtual void s78(); virtual void s79(int a, int b); virtual void s80();
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
struct Fe8118A {
    int* m0;
    unsigned m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
struct Fe8118V : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    int m13C;
    FeW* m140;
    char pad144[0x14C - 0x144];
    Fe8118A m14C;
};
extern "C" {
void fn_80535650(void* l, int a);
void fn_805364E0(void* l, int a);
int fn_8007A6A0__18Unk8007A4DC_Screenii(void* g, int a, int b);
int fn_800E5F38__Fi(int v);
void fn_8007824C(int v, int a);
float fn_800E0164__Ff();
int fn_804089B4(char* dst, const char* fmt, ...);
}
struct Fe7A40V : FeW {
    char pad40[0xF0];
    int m130;
    void* m134;
    void* m138;
    void* m13C;
    FeW* m140;
    FeW* m144;
    int m148;
    int* m14C;
    unsigned m150;
    char pad154[0x204 - 0x154];
    FeW* m204;
};
struct Fe7A40St {
    char pad0[0x598];
    int m598;
    int m59C;
};

static inline int Fe8CE8At(int* a, int i)
{
    int o = i * 4;
    return *(int*)((char*)a + o);
}

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
struct Fe8CE8S {
    int* mArr;
    unsigned mCnt;
};
struct Fe8CE8V {
    char pad0[0x14C];
    Fe8CE8S m14C;
};
extern "C" FeW* fn_800C8038(FeW* w);
typedef void (*FeCbF)(int, void*);
extern void* lbl_8061977C;
extern "C" {
const char* fn_80090880__FP11Unk80090880(void* t, int id);
void fn_801321D4(FeW* o, void* self, FeCbF cb, int a, void* b, int c, int d, int e, const char* s1, const char* s2,
                 const char* s3, int f, int g, int h);
}

static inline int Fe90C8Pick(char* b, int o)
{
    return *(int*)(b + o);
}

struct FeArrL { char* m0; int m4; int m8; int mC; const void* m10; int m14; };
extern const char lbl_80673888[];
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A4C8[];
extern "C" void fn_8040074C(void* p, int n);
extern "C" int fn_8057CF60(void* l, int a);
struct FeHoldDC { char pad0[0xDC]; FeSub mDC; };
extern "C" void fn_800C2034(void* p, int a);
extern "C" void fn_8007F438__FP13Unk8007F198_Aii(void* g, int a, int b);
extern "C" void fn_804A90C8(void* x);
extern "C" void fn_804A9228(void* x);
extern "C" void fn_804A8CE8(void* x);
extern "C" void fn_804A89D0(void* x);
extern "C" int fn_804A9048(int x, int v);
extern "C" int fn_8007F488__FP13Unk8007F198_A(void* g, int a);
extern "C" int fn_8007F4D0__FP13Unk8007F198_Aii(void* g, int a, int b);
extern "C" {

FE_OVERLAY int fn_804A721C(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY void fn_804A7278(void* a, char* p)
{
    *p = 0;
}

FE_OVERLAY void fn_804A7284(void) {}

FE_OVERLAY FeScrH* fn_804A7288(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80681F30);
    self->m130 = 0;
    FeI(self, 0x140) = 1;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    return self;
}

FE_OVERLAY void fn_804A72E4(FeW* x)
{
    fn_800ECE34(x);
    FeP(x, 0x134) = fn_800C8058(x->fn_vslot32("TEAMNAME", 1));
    FeP(x, 0x138) = fn_800C8058(x->fn_vslot32("TEAMNAMESHD", 1));
    FeP(x, 0x13C) = fn_800C8054(x->fn_vslot32("TEAMLOGO", 1));
    FeW* t = fn_800C805C(x->fn_vslot32("LEAGUESG", 1));
    FeP(x, 0x144) = t;
    FeP(x, 0x148) = fn_800C8058(t->fn_vslot32("LEAGUE", 1));
    FeMem(x, 0x144)->fn_vslot8(FeI(x, 0x140));
}

FE_OVERLAY void fn_804A740C(FeW* x)
{
    fn_800ECF18(x);
    if (fn_800B57EC(fn_800B555C()) == 0) {
        x->fn_vslot8(0);
        x->fn_vslot16(0);
    } else {
        fn_804A7760(x);
    }
}

FE_OVERLAY void fn_804A748C(void* x, int a)
{
    fn_800ECDCC(x, a);
    fn_804A763C(x, a ^ 1);
}

FE_OVERLAY void fn_804A74C8(FeW* x, int v)
{
    if (v == *(int*)((char*)x + 0x144)) {
        fn_804A7874(x, v);
    }
}

FE_OVERLAY int fn_804A74F4(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        FeMem(x, 0x144)->fn_vslot40(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A7548(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        ((FeWV*)FeMem(x, 0x144))->s41();
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A7598(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        FeMem(x, 0x144)->fn_vslot38(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A75EC(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        FeMem(x, 0x144)->fn_vslot39();
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_804A763C(void* x, int a)
{
    int v = a ^ 1;
    FeMem(x, 0x144)->fn_vslot8(v);
    FeI(x, 0x140) = v;
}

FE_OVERLAY void fn_804A768C(void* x)
{
    FeMem(x, 0x134)->fn_vslot8(0);
    FeMem(x, 0x138)->fn_vslot8(0);
    FeMem(x, 0x13C)->fn_vslot8(0);
    ((FeW*)x)->fn_vslot32("FC2", 1)->fn_vslot8(0);
    fn_804A763C(x, 1);
}

FE_OVERLAY void fn_804A7760(FeW* x)
{
    if (FeW24(x) < 0) {
        fn_804A77AC(x, fn_800C203C((char*)fn_800B555C() + 8));
    }
}

FE_OVERLAY void fn_804A77AC(void* x, int a)
{
    ((FeSubB*)((char*)FeP(x, 0x134) + 0xDC))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x138) + 0xDC))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x13C) + 0x98))->s20(a, 0);
    ((FeSub*)((char*)FeP(x, 0x148) + 0xDC))->s6(FeI(FeP(x, 0x134), 0xE8));
}

FE_OVERLAY void fn_804A7874(void* x, int unused)
{
    FeHoldDC* hh = (FeHoldDC*)FeMem(x, 0x148);
    int a = ((FeSub*)&hh->mDC)->s5();
    void* lst = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    int b = fn_8057CF60(lst, a);
    fn_800C2034((char*)fn_800B555C() + 8, a);
    void* l = FeP(FeGetMgr(), 0xA0);
    int i = 0;
    if (i < FeI(l, 0x1C4)) {
        int o = 0;
        do {
            char* t = (char*)l + 0x34;
            FeWR* e = *(FeWR**)(t + o);
            i++;
            o += 4;
            e->s70(a, b);
        } while (i < FeI(l, 0x1C4));
    }
    fn_804A7760((FeW*)x);
}

FE_OVERLAY FeScrH* fn_804A7970(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeArrL* s = (FeArrL*)((char*)self + 0x14C);
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80673888);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    s->m10 = lbl_8064B298;
    s->m0 = (char*)self + 0x164;
    s->m8 = 0x28;
    fn_8040074C(s->m0, 0xA0);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->m4 = 0;
    s->mC = 0;
    s->m14 = 0;
    s->m10 = lbl_8064A4C8;
    FeI(self, 0x204) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804A7A40(Fe7A40V* x)
{
    fn_800ECF18(x);
    x->m134 = fn_800B7AB8(FeGetMgr(), "NAVBAR");
    x->m138 = fn_800B7AB8(FeGetMgr(), "PLAYERINFOBAR");
    x->m13C = fn_800B7AB8(FeGetMgr(), "TBPLAYERINFO");
    x->m140 = fn_800C8060(fn_800C8044(x->fn_vslot32("TEAM", 1))->fn_vslot33(8, 1));
    x->m144 = fn_800C8060(fn_800C8044(x->fn_vslot32("BLOCK", 1))->fn_vslot33(8, 1));
    fn_80126CF4((FeList*)x->m138, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0);
    fn_80124FA8(x->m134, x);
    fn_80125154(x->m134, 0);
    x->m204 = x->m140;
    fn_804A7FBC(x, fn_800C203C((char*)fn_800B555C() + 8));
    fn_804A8004(x, (int)x->m204);
    if (((Fe7A40St*)fn_800B555C())->m598 != 0) {
        int t = ((Fe7A40St*)fn_800B555C())->m59C;
        if (fn_804A9048(fn_804A7FFC(x), t) == 0) {
            void* s = lbl_8061930C;
            if ((unsigned)fn_8007F488__FP13Unk8007F198_A(s, fn_804A7FFC(x)) <= 2) {
                unsigned i;
                for (i = 0; i < x->m150; i++) {
                    if (Fe8CE8At(x->m14C, i) == t) {
                        x->m140->fn_vslot68(i);
                        break;
                    }
                }
                x->fn_vslot67(1, -1);
            }
        }
    }
}

FE_OVERLAY void fn_804A7CEC(void* x, int k)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = k;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    case 1:
        fn_804A90C8(x);
        break;
    case 2:
        fn_804A9228(x);
        break;
    case 3:
        fn_804A8CE8(x);
        break;
    case 4:
        fn_804A8ED4(x);
        break;
    }
}

FE_OVERLAY void fn_804A7DD4(void* x)
{
    fn_804A8750(x);
    fn_804A89D0(x);
}

FE_OVERLAY int fn_804A7E08(char* x, int a)
{
    if (a == *(int*)(x + 0x140) || a == *(int*)(x + 0x144)) {
        fn_804A8004(x, a);
    }
    return 0;
}

FE_OVERLAY void fn_804A7E44(void* a, int b, int c)
{
    fn_804A7FBC(a, c);
}

FE_OVERLAY void fn_804A7E68(void) {}

FE_OVERLAY int fn_804A7E6C(void* x)
{
    FeMem(x, 0x204)->fn_vslot50();
    return 0;
}

FE_OVERLAY int fn_804A7EA8(void* x)
{
    FeMem(x, 0x204)->fn_vslot52();
    return 0;
}

FE_OVERLAY int fn_804A7EE4(void* x)
{
    FeMem(x, 0x204)->fn_vslot51();
    return 0;
}

FE_OVERLAY int fn_804A7F20(void* x)
{
    FeMem(x, 0x204)->fn_vslot53();
    return 0;
}

FE_OVERLAY int fn_804A7F5C(char* x)
{
    fn_804A8004(x, *(int*)(x + 0x144));
    return 0;
}

FE_OVERLAY int fn_804A7F84(char* x)
{
    fn_804A8004(x, *(int*)(x + 0x140));
    return 0;
}

FE_OVERLAY int fn_804A7FAC(void) { return 0; }

FE_OVERLAY int fn_804A7FB4(void) { return 0; }

FE_OVERLAY void fn_804A7FBC(void* x, int a)
{
    FeI(x, 0x148) = a;
    fn_804A80E4(x);
    fn_804A8750(x);
    fn_804A89D0(x);
}

FE_OVERLAY int fn_804A7FFC(void* x)
{
    return FeI(x, 0x148);
}

FE_OVERLAY int fn_804A8004(void* x, int a)
{
    FeI(x, 0x204) = a;
    FeW* w = FeMem(x, 0x140);
    ((FeWQ*)w)->s14(a == (int)w);
    FeW* w2 = FeMem(x, 0x144);
    ((FeWQ*)w2)->s14(FeI(x, 0x204) == (int)w2);
    ((FeWR*)FeMem(x, 0x138))->s84(a == FeI(x, 0x140), 0);
    ((FeWQ*)x)->s69(a);
    fn_804A89D0(x);
}

FE_OVERLAY int fn_804A80DC(void* x)
{
    return FeI(x, 0x204);
}

FE_OVERLAY void fn_804A80E4(void* x)
{
    fn_804A8118(x);
    fn_804A83D0(x);
}

extern "C" FE_OVERLAY void fn_804A8118(void* xv)
{
    Fe8118V* x = (Fe8118V*)xv;
    char sbuf[0x68];
    char wbuf[200];
    unsigned i = 0;
    Fe8118A* arr = &x->m14C;
    int id = fn_804A7FFC(x);
    void* g = lbl_8061930C;
    fn_8040074C(x->m14C.m0, arr->m8 * 4);
    arr->m4 = 0;
    arr->mC = 0;
    arr->m14 = 0;
    fn_80535650(arr, id);
    fn_805364E0(arr, 0);
    int flag = ((unsigned)FeW24(x->m140) >> 28) & 1;
    ((FeW79*)x->m140)->s79(arr->m4, 0);
    x->m140->fn_vslot3();
    for (i = 0; i < arr->m4; i++) {
        int v = Fe8CE8At(x->m14C.m0, i);
        int sid = fn_8007A6A0__18Unk8007A4DC_Screenii(g, 5, v);
        x->m140->fn_vslot44(i, 0, (char*)fn_800E5F38__Fi(sid), 4);
        fn_800DE440(wbuf, v, 1);
        x->m140->fn_vslot43(i, 1, wbuf, 4);
        fn_8007824C(v, 0);
        float f = fn_800E0164__Ff();
        fn_804089B4(sbuf, "%f", f);
        x->m140->fn_vslot44(i, 2, sbuf, 4);
    }
    x->m140->fn_vslot14(1);
    ((FeWV*)x->m140)->s69(1);
    fn_804A86BC(x);
    x->m140->fn_vslot14(flag);
    if (x->m138->fn_vslot87() != 0) {
        int v = Fe8CE8At(x->m14C.m0, x->m140->fn_vslot60());
        FeList* l = (FeList*)x->m138;
        fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    }
}

extern "C" FE_OVERLAY void fn_804A83D0(void* xv)
{
    Fe83D0V* x = (Fe83D0V*)xv;
    char sbuf[0x68];
    char wbuf[200];
    unsigned i = 0;
    int id = fn_804A7FFC(x);
    void* g = lbl_8061930C;
    int flag = ((unsigned)FeW24(x->m144) >> 28) & 1;
    unsigned n = fn_8007F488__FP13Unk8007F198_A(g, id);
    ((FeW79*)x->m144)->s79(n, 0);
    x->m144->fn_vslot3();
    for (i = 0; i < n; i++) {
        int v = fn_8007F4D0__FP13Unk8007F198_Aii(g, id, i);
        int sid = fn_8007A6A0__18Unk8007A4DC_Screenii(g, 5, v);
        x->m144->fn_vslot44(i, 0, (char*)fn_800E5F38__Fi(sid), 4);
        fn_800DE440(wbuf, v, 1);
        x->m144->fn_vslot43(i, 1, wbuf, 4);
        fn_8007824C(v, 0);
        float f = fn_800E0164__Ff();
        fn_804089B4(sbuf, "%f", f);
        x->m144->fn_vslot44(i, 2, sbuf, 4);
    }
    x->m144->fn_vslot14(1);
    ((FeWV*)x->m144)->s69(1);
    x->m144->fn_vslot14(flag);
    if (x->m138->fn_vslot86() != 0) {
        unsigned k = x->m144->fn_vslot60();
        if (k < (unsigned)fn_8007F488__FP13Unk8007F198_A(g, id)) {
            int v = fn_8007F4D0__FP13Unk8007F198_Aii(g, id, k);
            FeList* l = (FeList*)x->m138;
            fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        } else {
            FeList* l = (FeList*)x->m138;
            fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
}

struct FeVecI {
    int* d;
    unsigned n;
};
FE_OVERLAY void fn_804A86BC(void* x)
{
    unsigned i = 0;
    FeVecI* v = (FeVecI*)((char*)x + 0x14C);
    int id = fn_804A7FFC(x);
    if (i < v->n) {
        int o = 0;
        do {
            int e = *(int*)((char*)FeP(x, 0x14C) + o);
            o += 4;
            int c = fn_804A9048(id, e);
            ((FeW3*)FeMem(x, 0x140))->s90(i, 1, c);
            i++;
        } while (i < v->n);
    }
}

extern "C" FE_OVERLAY void fn_804A8750(void* x)
{
    if (FeMem(x, 0x204) == FeMem(x, 0x140)) {
        int v = Fe8CE8At((int*)FeP(x, 0x14C), FeMem(x, 0x204)->fn_vslot60());
        if (FeMem(x, 0x138)->fn_vslot87() != 0) {
            FeList* l = (FeList*)FeMem(x, 0x138);
            fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
        if (v == 0)
            fn_804AA554((FeScrL*)FeP(x, 0x13C));
        else
            fn_804A96A4(FeP(x, 0x13C), v, 1, 2, 1, 0, 0, 0);
        if (FeMem(x, 0x140)->fn_vslot61() != 1)
            ((FeWV*)FeMem(x, 0x140))->s69(1);
    } else {
        int k = FeMem(x, 0x144)->fn_vslot60();
        int id = fn_804A7FFC(x);
        int v;
        if (fn_8007F488__FP13Unk8007F198_A(lbl_8061930C, id) != 0)
            v = fn_8007F4D0__FP13Unk8007F198_Aii(lbl_8061930C, id, k);
        else
            v = 0;
        if (FeMem(x, 0x138)->fn_vslot86() != 0) {
            FeList* l = (FeList*)FeMem(x, 0x138);
            fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
        if (v == 0)
            fn_804AA554((FeScrL*)FeP(x, 0x13C));
        else
            fn_804A96A4(FeP(x, 0x13C), v, 1, 2, 1, 0, 0, 0);
        if (FeMem(x, 0x144)->fn_vslot61() != 1)
            ((FeWV*)FeMem(x, 0x144))->s69(1);
    }
}

extern "C" FE_OVERLAY void fn_804A89D0(void* x)
{
    int id = fn_804A7FFC(x);
    int a;
    int b;
    fn_80125084(FeP(x, 0x134), 0);
    if (fn_804A80DC(x) == FeI(x, 0x140)) {
        a = 1;
        if (FeI(x, 0x150) == 0)
            a = 0;
        b = 1;
        if (FeMem(x, 0x138)->fn_vslot87() == 0)
            b = 0;
        if (a != 0) {
            int v = Fe90C8Pick((char*)FeP(x, 0x14C), FeMem(x, 0x140)->fn_vslot60() * 4);
            if (fn_804A9048(id, v) != 0)
                fn_801251CC(FeP(x, 0x134), 0, 0x1A46, 2);
            else if ((unsigned)fn_8007F488__FP13Unk8007F198_A(lbl_8061930C, id) <= 2)
                fn_801251CC(FeP(x, 0x134), 0, 0x1A45, 1);
        }
    } else {
        a = 1;
        if (fn_8007F488__FP13Unk8007F198_A(lbl_8061930C, id) == 0)
            a = 0;
        b = 1;
        if (FeMem(x, 0x138)->fn_vslot86() == 0)
            b = 0;
        if (a != 0)
            fn_801251CC(FeP(x, 0x134), 0, 0x1A46, 2);
    }
    if (a != 0) {
        if (b != 0)
            fn_801251CC(FeP(x, 0x134), 3, 0x37A2, 4);
        else
            fn_801251CC(FeP(x, 0x134), 3, 0x1A2F, 3);
    } else
        fn_80125084(FeP(x, 0x134), 3);
}

FE_OVERLAY void fn_804A8B9C(void* x)
{
    int id = fn_804A7FFC(x);
    int idx = FeMem(x, 0x140)->fn_vslot60();
    int o = idx * 4;
    fn_8007F3E8__FP13Unk8007F198_Aii(lbl_8061930C, id, *(int*)((char*)FeP(x, 0x14C) + o));
    fn_804A8F98(x);
    fn_804A86BC(x);
    fn_804A83D0(x);
}

FE_OVERLAY void fn_804A8C1C(void* x)
{
    void* g = lbl_8061930C;
    int id = fn_804A7FFC(x);
    int w = fn_804A80DC(x);
    int v;
    if (w == FeI(x, 0x144))
        v = fn_8007F4D0__FP13Unk8007F198_Aii(g, id, ((FeWI*)w)->s60());
    else {
        int o = ((FeWI*)FeMem(x, 0x140))->s60() * 4;
        v = *(int*)((char*)FeP(x, 0x14C) + o);
    }
    fn_8007F438__FP13Unk8007F198_Aii(g, id, v);
    fn_804A8F98(x);
    fn_804A86BC(x);
    fn_804A83D0(x);
}

extern "C" FE_OVERLAY void fn_804A8CE8(void* x)
{
    FeW* w = (FeW*)fn_804A80DC(x);
    if (w == FeMem(x, 0x140)) {
        Fe8CE8S* s = &((Fe8CE8V*)x)->m14C;
        int v = Fe8CE8At(s->mArr, w->fn_vslot60());
        FeMem(x, 0x138)->fn_vslot84(1, 0);
        FeList* l = (FeList*)FeMem(x, 0x138);
        fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        ((FeW88*)FeMem(x, 0x138))->s88(1, s->mCnt > 1);
    } else {
        int k = FeMem(x, 0x144)->fn_vslot60();
        int id = fn_804A7FFC(x);
        int v = fn_8007F4D0__FP13Unk8007F198_Aii(lbl_8061930C, id, k);
        FeMem(x, 0x138)->fn_vslot84(0, 0);
        FeList* l = (FeList*)FeMem(x, 0x138);
        fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        ((FeW88*)FeMem(x, 0x138))->s88(0, (unsigned)fn_8007F488__FP13Unk8007F198_A(lbl_8061930C, id) > 1);
    }
    fn_804A89D0(x);
}

FE_OVERLAY void fn_804A8ED4(void* x)
{
    if (fn_804A80DC(x) == FeI(x, 0x140)) {
        FeList* l = (FeList*)FeP(x, 0x138);
        fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    } else {
        FeList* l = (FeList*)FeP(x, 0x138);
        fn_80126CF4(l, 0, FeI(l, 0x168), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    }
    fn_804A89D0(x);
}

FE_OVERLAY void fn_804A8F98(void* x)
{
    FeList* l = (FeList*)FeP(x, 0x138);
    fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    l = (FeList*)FeP(x, 0x138);
    fn_80126CF4(l, 0, FeI(l, 0x168), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    fn_804A89D0(x);
}

FE_OVERLAY int fn_804A9048(int x, int v)
{
    void* g = lbl_8061930C;
    int n = fn_8007F488__FP13Unk8007F198_A(g, x);
    int i = 0;
    if (i < n) {
        do {
            if (fn_8007F4D0__FP13Unk8007F198_Aii(g, x, i) == v)
                return 1;
            i++;
        } while (i < n);
    }
    return 0;
}

FE_OVERLAY void fn_804A90C8(void* x)
{
    char small[200];
    char big[400];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    fn_800DE440(small, Fe90C8Pick((char*)FeP(x, 0x14C), FeMem(x, 0x140)->fn_vslot60() * 4), 1);
    fn_80403DE4(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4D98), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(p, x, (FeCbF)fn_804A91FC, 0, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_804A91FC(int a, void* b)
{
    if (a == 1) {
        fn_804A8B9C(b);
    }
}

extern "C" FE_OVERLAY void fn_804A9228(void* x)
{
    char small[200];
    char big[400];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    void* s = lbl_8061930C;
    int a = fn_804A7FFC(x);
    FeW* w = (FeW*)fn_804A80DC(x);
    int v;
    if (w == FeMem(x, 0x144)) {
        v = fn_8007F4D0__FP13Unk8007F198_Aii(s, a, w->fn_vslot60());
    } else {
        v = Fe90C8Pick((char*)FeP(x, 0x14C), FeMem(x, 0x140)->fn_vslot60() * 4);
    }
    fn_800DE440(small, v, 1);
    char* bp = big;
    fn_80403DE4(bp, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4D99), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(p, x, (FeCbF)fn_804A93B8, 0, bp, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_804A93B8(int a, void* b)
{
    if (a == 1) {
        fn_804A8C1C(b);
    }
}

FE_OVERLAY FeScrH* fn_804A93E4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806735E0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804A944C(FeScrL* x)
{
    fn_800ECE34(x);
    FeW* w;
    if (x->fn_vslot28("ANIMFROMLEFT1") != 0) {
        w = fn_800C8044(x->fn_vslot29("ANIMFROMLEFT1"));
    } else {
        w = x;
    }
    FeP(x, 0x134) = fn_800C8040(w->fn_vslot29("NAME"));
    FeP(x, 0x138) = fn_800C8038(w->fn_vslot29("FACE"));
    FeP(x, 0x13C) = fn_800C8060(w->fn_vslot29("STATS"));
    FeP(x, 0x140) = fn_800C8044(w->fn_vslot29("CONTRACT"));
    FeP(x, 0x144) = fn_800C8044(w->fn_vslot29("INFOGROUP"));
    FeP(x, 0x148) = fn_800C8040(FeMem(x, 0x140)->fn_vslot32("CONTRACTINFO", 1));
    FeP(x, 0x14C) = fn_800C8054(w->fn_vslot29("TEAMLOGO"));
    FeMem(x, 0x138)->fn_vslot8(0);
    fn_804AA554(x);
    fn_800C3AB4(fn_800C33D0(), 9);
}

FE_OVERLAY void fn_804A9620(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_804A9648(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_804A9668(FeW* x)
{
    if (x) {
        ((FeWV*)x)->s8();
    }
}

FE_OVERLAY void fn_804AA554(FeScrL* x)
{
    x->fn_vslot8(0);
}

}
