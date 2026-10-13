/*
 * Front-end overlay code, .frontend_codeoverlay 0x80488CDC-0x8048E6A0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
struct FeWD : Unk800C7B40_Data {
    virtual ~FeWD();
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
    virtual void s67(); virtual void s68(); virtual void s69(int a); virtual FeW* s70(); virtual void s71();
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
extern "C" int strcmp(const char* a, const char* b);
extern "C" void fn_804895B8(void* x, int a);

static inline int Fe8EECAt(int* a, int i)
{
    int o = i * 4;
    return *(int*)((char*)a + o);
}

struct FeWC : Unk800C7B40_Data {
    virtual ~FeWC();
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
    virtual void s87(int a, int b, int c); virtual void s88(int a, int b); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127();
};
struct FeWQ28 : Unk800C7B40_Data {
    virtual ~FeWQ28();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(const char* a); virtual void s29(int a); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
    virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70();
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
extern "C" void fn_800DC580__FP3UiSf(void* o, float f);
extern "C" void fn_800E5380__FP3UiS(void* o);
extern "C" FeW* fn_800C805C(FeW* w);
extern "C" {
void fn_80489BEC(void* x, int a);
void fn_804898CC(void* x);
}
struct FeRow9B3C {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
};

static inline int FeSumRow(FeRow9B3C* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->m1B4[(unsigned char)i];
    }
    return s;
}

typedef int (*Fn9764_t)(void*, int, int, int);
/* fn_8009764C takes its third argument as int here (the header's unsigned char adds a clrlwi). */
static inline int FeCheck9764(void* t, int k, int r, int z)
{
    return ((Fn9764_t)fn_8009764C)(t, k, r, z);
}

extern "C" FE_OVERLAY FeScrH* fn_80488CDC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806765D8);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80488D30(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

extern "C" FE_OVERLAY void fn_80489324(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_80489348(void* x)
{
    void* s = lbl_8061930C;
    FeNode4* node = lbl_806192E0->m4;
    FeGlobal80619948* g = lbl_80619948;
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_800B555C();
    int b = ((int (*)(void))fn_800B5BD4)();
    if (b != 0) {
        char* name = (char*)((FeWD*)FeAt(x, 0x154))->s70()->fn_vslot33(5, 1) + 0xC;
        int c = strcmp(name, "ADVANCE");
        if (c == 0) {
            fn_8040B830(p->name, "QUIT", 15);
            p->name[15] = c;
            fn_800DB7DC__Fv();
        } else {
            fn_8040B830(p->name, name, 15);
            p->name[15] = 0;
        }
        fn_800B7B4C(FeGetMgr(), &m, x);
    } else {
        if (lbl_8061A48C != 0) {
            FeW* w = FeAt(x, 0x154);
            ((FeWD*)w)->s69(w->fn_vslot58() - 1);
        }
        char* name = (char*)((FeWD*)FeAt(x, 0x154))->s70()->fn_vslot33(5, 1) + 0xC;
        if (strcmp(name, "ADVANCE") == 0) {
            int q = FeI(FeVp(node, 0xC), 0x88);
            if (fn_8007FDA8__FP13Unk8007F198_Cii(s, q, fn_80078A38__18Unk8007B2B0_Screeni(s, FeI(FeVp(node, 0x14), 0x198))) == 0)
                fn_800A3670(g);
            fn_804707B8(FeAt(x, 0x158), 0);
            ((FePopup*)FeAt(x, 0x158))->m30C = (void*)fn_804895B8;
        } else {
            fn_8040B830(p->name, name, 15);
            p->name[15] = b;
            fn_800B7B4C(FeGetMgr(), p, x);
        }
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8048977C(void* x)
{
    FeAt(x, 0x154)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804897B8(void* x)
{
    FeAt(x, 0x154)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804897F4(void* x)
{
    FeAt(x, 0x154)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80489830(void* x)
{
    FeAt(x, 0x154)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048986C(FeW* x, int w)
{
    if (w == FeI(x, 0x154))
        x->fn_vslot41(fn_800C8070(x));
    return 1;
}

extern "C" FE_OVERLAY void fn_804898CC(void* xv)
{
    FeW* x = (FeW*)xv;
    char buf[12];
    FeNode4* n = lbl_806192E0->m4;
    FeW* w0 = ((FeW* (*)(FeW*))fn_800C8040)(x->fn_vslot29("TEAMSCORE/HOMESCORE"));
    FeW* w1 = ((FeW* (*)(FeW*))fn_800C8040)(x->fn_vslot29("TEAMSCORE/AWAYSCORE"));
    w0->fn_vslot8(1);
    w1->fn_vslot8(1);
    fn_804089B4(buf, "%d", FeSumRow((FeRow9B3C*)n->m14));
    ((FeWV*)w0)->s30(buf);
    fn_804089B4(buf, "%d", FeSumRow((FeRow9B3C*)((char*)n->m14 + 0xE64)));
    ((FeWV*)w1)->s30(buf);
}

extern "C" FE_OVERLAY int fn_80489A44(int u, int idx, int mode)
{
    char* team = (char*)lbl_806192E0->m4->m14 + idx * 0xE64;
    int i;
    int n = *(unsigned char*)(team + 0x235);
    for (i = 0; i < n; i++) {
        int off = (unsigned char)i * 8;
        char* arr = team + 0x238;
        int id = *(int*)(arr + off);
        int r = fn_800968C0(team, id, 1);
        if (FeCheck9764(team, 3, r, 0) != 0) {
            if (mode == 0) {
                return id;
            }
        } else if (FeCheck9764(team, 4, r, 0) != 0 && mode == 1) {
            return id;
        }
        if (FeCheck9764(team, 7, r, 0) != 0 && mode == 2) {
            return id;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80489B3C(void* self, int mode)
{
    int a = FeSumRow((FeRow9B3C*)((char*)lbl_806192E0->m4->m14 + 0xE64));
    int b = FeSumRow((FeRow9B3C*)lbl_806192E0->m4->m14);
    int gt = a > b;
    if ((mode == 1 && gt) || (mode == 0 && !gt))
        return 1;
    return 0;
}

extern "C" FE_OVERLAY void fn_8048A144(FeW* x)
{
    char* t0 = (char*)lbl_806192E0->m4->m14;
    char* t1 = t0 + 0xE64;
    int a;
    int b;
    if (fn_80489B3C(x, 1) != 0) {
        a = fn_80489A44((int)x, 1, 0);
        b = fn_80489A44((int)x, 0, 1);
    } else {
        b = fn_80489A44((int)x, 0, 0);
        a = fn_80489A44((int)x, 1, 1);
    }
    FeW* wl = ((FeW* (*)(FeW*))fn_800C8044)(x->fn_vslot32("LEFTPLAYER", 1));
    FeW* wr = ((FeW* (*)(FeW*))fn_800C8044)(x->fn_vslot32("RIGHTPLAYER", 1));
    fn_800E2F24(wl, (int)t1, a);
    fn_800E2F24(wr, (int)t0, b);
    fn_800E31A8(wl, (int)t1, a);
    fn_800E31A8(wr, (int)t0, b);
    fn_80489BEC(x, 1);
    fn_80489BEC(x, 0);
    fn_804898CC(x);
    fn_80590CA8(*(int*)((char*)lbl_8061930C + 0x30));
}

/* near-miss: 2 slots differ (order of the final m4/mC stores after the vptr store) */
extern "C" FE_OVERLAY FeScrArr* fn_8048A2AC(FeScrArr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676330);
    self->m144 = 2;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    FeArr* s = &self->m148;
    s->m10 = lbl_8064B298;
    s->m0 = self->m160;
    s->m8 = 0xCB2;
    fn_8040074C(s->m0, 0x32C8);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->mC = 0;
    s->m10 = lbl_8064A3B8;
    s->m4 = 0;
    s->m14 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8048A378(FeScrCell* x)
{
    fn_800ECE34(x);
    x->fn_vslot32("CELL", 1);
    x->m134 = fn_800C8060();
    x->m138 = fn_800B7AB8(FeGetMgr(), "PLAYERINFOBAR");
    x->m13C = fn_800B7AB8(FeGetMgr(), "BATPITCHSTATS");
}

struct Fe8A43C_List {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    int m10;
    int m14;
    int At(unsigned i)
    {
        int o = i * 4;
        return *(int*)((char*)m0 + o);
    }
};
struct Fe8A43C_Buf {
    unsigned short a;
    unsigned short b;
};
#define FE8A43C_TIME ((Fe8A43C_Buf(*)(int, ...))fn_80329FA0)
#define FE8A43C_SCR ((int (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)
/* near-miss: 96.2%; retail stores the incremented m4 before the full test and compares a copy of it (mr r0,r9), with m8 loaded before the add (6 slots) */
extern "C" FE_OVERLAY void fn_8048A43C(Fe8A43C_List* a, Fe8A43C_List* b)
{
    unsigned i;
    void* g = lbl_8061930C;
    unsigned short base = FE8A43C_TIME(fn_800A2AE8(lbl_80619948)).b;
    fn_8040074C(b->m0, b->m8 * 4);
    b->m4 = 0;
    b->mC = 0;
    b->m14 = 0;
    i = 0;
    for (; i < a->m4; i++) {
        int id = a->At(i);
        int z = fn_80077BC4(g, id) == 0;
        int r = FE8A43C_SCR(g, 0x16, id);
        int d = base - FE8A43C_TIME(FE8A43C_SCR(g, 1, id)).b;
        if (!(z && (d <= 0x18 || r <= 1))) {
            if (b->m4 >= b->m8)
                break;
            b->m0[b->m4] = id;
            b->m4++;
            if (b->m4 >= b->m8)
                break;
        }
    }
}

extern "C" FE_OVERLAY void fn_8048AB24(void* x)
{
    fn_800ED254(x);
    FeI(fn_800B555C(), 0x640) = 0;
}

extern "C" FE_OVERLAY void fn_8048AB50(void* x)
{
    if (FeWp(x, 0x134)->fn_vslot59() > 0) {
        int a = FeWp(x, 0x138)->fn_vslot87();
        int v = FePick((char*)FeVp(x, 0x148), FeWp(x, 0x134)->fn_vslot60() * 4);
        if (a != 0 && a != v) {
            char* s = (char*)FeVp(x, 0x138);
            fn_80126CF4((FeList*)s, FeI(s, 0x164), v, FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
        }
        fn_80123858(FeVp(x, 0x13C), v, 1);
    }
}

extern "C" FE_OVERLAY int fn_8048AC44(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AC80(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ACBC(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ACF8(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AD34(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AD80(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ADCC(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AE18(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AE64(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x134)) {
        w->fn_vslot68(c);
        x->fn_vslot67(2, fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_8048AEEC(void* x, int mode)
{
    switch (mode) {
    case 3: {
        FeMsg m;
        FeMsg* p = &m;
        ((void (*)(void*, int))fn_800A2F9C)(lbl_80619948, 1);
        fn_8035682C(p);
        fn_8040B830(p->name, "ADVANCE", 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    }
    case 0: {
        FeMsg m;
        FeMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = mode;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    }
    case 1: {
        int v = FeAt(x, 0x134)->fn_vslot61();
        if (v != FeI(x, 0x144)) {
            FeI(x, 0x144) = v;
            FeI(x, 0x140) = 0;
        }
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        FeW* l = FeAt(x, 0x134);
        ((FeWC*)l)->s87(l->fn_vslot61(), FeI(x, 0x140), (int)((char*)x + 0x148));
        FeI(x, 0x140) = FeI(x, 0x140) ^ 1;
        break;
    }
    case 2:
        if (FeAt(x, 0x134)->fn_vslot59() > 0) {
            int k = FeAt(x, 0x134)->fn_vslot60();
            FePopup* p = fn_800B7AB8(FeGetMgr(), "NAVBAR");
            int v;
            if (FeAt(x, 0x138)->fn_vslot87() == 0) {
                v = Fe8EECAt((int*)FeVp(x, 0x148), k);
                ((int (*)(FePopup*, int, int, int))fn_801251CC)(p, 3, 0x37A2, 2);
                fn_80125084(p, 2);
            } else {
                ((int (*)(FePopup*, int, int, int))fn_801251CC)(p, 3, 0x1A2F, 2);
                v = 0;
                ((int (*)(FePopup*, int, int, int))fn_801251CC)(p, 2, 0x201A, 1);
                FeAt(x, 0x134)->fn_vslot16(1);
            }
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            fn_80126CF4((FeList*)FeAt(x, 0x138), 0, v, 0, 0, 0, 0, 1, 0, 1, 0);
            ((FeWC*)FeAt(x, 0x138))->s88(1, FeAt(x, 0x134)->fn_vslot59() > 1);
        }
        break;
    }
}

extern "C" FE_OVERLAY FeScrH* fn_8048B248(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80682508);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeF(self, 0x13C) = 0.0f;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 1;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8048B2C0(void* x)
{
    fn_800ECE34(x);
    fn_8048E7E4(x);
    fn_8048E6A0(x);
}

extern "C" FE_OVERLAY void fn_8048B76C(void* x)
{
    FeI(fn_800B555C(), 0x18) = FeI(x, 0x134);
}

extern "C" FE_OVERLAY void fn_8048B7A0(FeW* x)
{
    if (FeW24(x) < 0) {
        fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1);
        FeI(x, 0x138) = ((FeSub*)((char*)fn_800C8058() + 0xDC))->s5();
    }
}

extern "C" FE_OVERLAY int fn_8048B840(void* xv)
{
    FeW* x = (FeW*)xv;
    FeW* w = ((FeW* (*)(FeW*))fn_800C8058)(fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1));
    int cur = FeI(x, 0x134);
    if (!(FeW24(x->fn_vslot32("INFOMODE", 1)) & 0x40000000))
        return 0;
    fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot40(1);
    do {
        cur--;
        if (cur < 0)
            cur = 5;
    } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
    ((FeSub*)((char*)w + 0xDC))->s6(cur);
    FeI(x, 0x134) = cur;
    fn_8048BCE4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048B9B8(FeW* x)
{
    FeW* p = x->fn_vslot32("INFOMODE", 1);
    ((FeWV*)fn_800C805C(p))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_8048BA18(void* xv)
{
    FeW* x = (FeW*)xv;
    FeW* w = ((FeW* (*)(FeW*))fn_800C8058)(fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1));
    int cur = FeI(x, 0x134);
    if (!(FeW24(x->fn_vslot32("INFOMODE", 1)) & 0x40000000))
        return 0;
    fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot38(1);
    do {
        if (cur++ == 5)
            cur = 0;
    } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
    ((FeSub*)((char*)w + 0xDC))->s6(cur);
    FeI(x, 0x134) = cur;
    fn_8048BCE4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048BB94(FeW* x)
{
    FeW* p = x->fn_vslot32("INFOMODE", 1);
    fn_800C805C(p)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_8048BBF4(void* x, int v)
{
    FeI(x, 0x140) = v;
    fn_8048BCE4(x);
}

extern "C" FE_OVERLAY void fn_8048BC18(void* x)
{
    fn_8048E8B0(x)->fn_vslot32("MOMENTUM", 1);
    fn_800C8044()->fn_vslot32("METER", 1);
    FeF(x, 0x13C) = (float)fn_800C8044()->fn_vslot32("METERBAR", 1)->m2A;
}

extern "C" FE_OVERLAY void fn_8048C6AC(void* x)
{
    char b8[0x100];
    float f;
    char b110[0x460];
    void** gp = &lbl_8061930C;
    fn_800B555C();
    int n = fn_800B56C4();
    int lst = (int)fn_8007F7D0__FP13Unk8007F198_BUi(*gp, 0);
    int sel = (int)((int (*)(void*, int, int))fn_8007B320__18Unk8007B2B0_Screenii)(*gp, 0, lst);
    ((FeW*)fn_8048E76C(x))->fn_vslot32("COLORBAR", 1);
    ((FeSubV8*)((char*)fn_800C8054() + 0x98))->s8(sel);
    ((FeW*)fn_8048E76C(x))->fn_vslot32("GRADIENT", 1);
    ((FeSubV8*)((char*)fn_800C8054() + 0x98))->s8(sel);
    int id = fn_800C203C((int)((char*)fn_800B555C() + 8));
    fn_8048E8B0(x)->fn_vslot32("MOMENTUM", 1)->fn_vslot8(1);
    f = fn_800A39C4(lbl_80619948, (void*)id);
    fn_800DC580__FP3UiSf(((FeW* (*)(FeW*))fn_800C8044)(((FeW* (*)(FeW*))fn_800C8044)(fn_8048E8B0(x)->fn_vslot32("MOMENTUM", 1))->fn_vslot32("METER", 1)), f);
    if (n != 0) {
        int v = fn_80553260();
        ((FeWQ28*)((FeW* (*)(FeW*))fn_800C8040)(fn_8048E8B0(x)->fn_vslot32("MGRRATINGVAL", 1)))->s29(v);
        ((FeWQ28*)((FeW* (*)(FeW*))fn_800C8040)(fn_8048E8B0(x)->fn_vslot32("MGRRATINGVAL1", 1)))->s29(v);
    } else {
        fn_800E5380__FP3UiS(((FeW* (*)(FeW*))fn_800C8044)(fn_8048E8B0(x)->fn_vslot32("FANSTATUS", 1)));
        ((int (*)(char*, int, int, float))fn_800DF254)(b8, 0, 3, *(float*)(**(char***)((char*)*gp + 0x30) + 0x12B78));
        ((FeWQ28*)((FeW* (*)(FeW*))fn_800C8040)(fn_8048E8B0(x)->fn_vslot32("BANKBALANCE", 1)))->s28(b8);
    }
    char* p = b110;
    fn_8055AC44(p, fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, id));
    fn_800DD800(fn_8048E8B0(x), p, id, 0);
}

extern "C" FE_OVERLAY void fn_8048E3BC(FeW* x)
{
    void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, t);
    int v = fn_8059897C();
    x->fn_vslot32("OWNERRATINGVAL", 1);
    ((FeWV29*)fn_800C8040())->s29(v);
}

extern "C" FE_OVERLAY int fn_8048E450(void* x)
{
    return fn_8057CE00(0) == -1;
}

extern "C" FE_OVERLAY int fn_8048E480(void* x)
{
    int r = 0;
    if (fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->m1E0 == 1)
        r = fn_8048E4D8(x) == 0;
    return r;
}

extern "C" FE_OVERLAY int fn_8048E4D8(void* x)
{
    fn_800B555C();
    return fn_800B5758();
}

extern "C" FE_OVERLAY void fn_8048E4FC(void* xv, int unused, int mode)
{
    FeW* x = (FeW*)xv;
    FeW* w = ((FeW* (*)(FeW*))fn_800C8058)(fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1));
    int cur = FeI(x, 0x134);
    if (FeW24(x->fn_vslot32("INFOMODE", 1)) & 0x40000000) {
        switch (mode) {
        case 0:
            do {
                cur--;
                if (cur < 0)
                    cur = 5;
            } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
            break;
        case 1:
            do {
                if (cur++ == 5)
                    cur = 0;
            } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
            break;
        }
        ((FeSub*)((char*)w + 0xDC))->s6(cur);
        FeI(x, 0x134) = cur;
        fn_8048BCE4(x);
    }
}
