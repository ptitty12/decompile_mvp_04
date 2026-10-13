/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C713C-0x804C931C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" int fn_800A2EFC(FeGlobal80619948* g);
extern "C" void fn_804C846C(FeScrN* x);

extern const char lbl_805F8074[];

extern "C" char* fn_800DF254(char* out, int a, int b, float f);
extern "C" void fn_804C8544(int a, void* x);
extern const char lbl_8066F620[];

struct Unk8007F198_B;
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);
int fn_8009047C(int a, int b);
extern "C" void fn_80125154(void* w, int a);
extern "C" int fn_804C7F30(FeScrN* x);
struct FeV8 : Unk800C7B40_Data {
    virtual ~FeV8();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(int a); virtual void s9(); virtual void s10(); virtual void s11();
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
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106();
    virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116();
    virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120(); virtual void s121();
    virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126();
    virtual void s127();
};
struct FeV32 : Unk800C7B40_Data {
    virtual ~FeV32();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual FeW* s32(const char* a, int b); virtual void s33(); virtual void s34(); virtual void s35();
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
struct FeV28 : Unk800C7B40_Data {
    virtual ~FeV28();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(const char* a); virtual void s29(); virtual void s30();
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
int fn_8008FD78(int a);
int fn_8008FD14(int a);
extern "C" float fn_80090380__FPv(int a, int b);
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
extern "C" void fn_800C40B4(void* h, void* w, int a, int b);
extern "C" int fn_800DE538__Fiiii(char* out, int a, int b, int c);
inline char* DfW(char* o, int a, int b, float f)
{
    return fn_800DF254(o, a, b, f);
}
extern "C" void fn_80403DE4(char* dst, const char* fmt, ...);
extern "C" void fn_804C8874(FeScrN* x, int i);
extern const char lbl_805F55DC[];
extern void* lbl_8061977C;
extern "C" void* fn_800C8038(void* w);
class FeVt18 {
public:
    char pad0[0x18];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
};
extern "C" void fn_800A2F9C(FeGlobal80619948* g, int a);

extern "C" void fn_804C81A0(FeScrN* x);
extern const char lbl_805F8060[];
extern const char lbl_805F806C[];
extern const char lbl_8066F378[];
extern "C" void fn_804C7ACC(FeScrN* x);
extern "C" void fn_804C7FE4(FeScrN* x);
extern "C" void fn_804C8354(void* x);
extern "C" void fn_804C86E8(FeScrN* x);
extern "C" void fn_804C87F0(void* x);
extern "C" void fn_804C7724(FeScrN* x);
extern "C" void fn_804C7744(FeScrN* x);
extern "C" int fn_804C77C0(FeScrN* x);
extern "C" int fn_804C77FC(FeScrN* x);
extern "C" int fn_804C7838(FeScrN* x);
extern "C" int fn_804C7874(FeScrN* x);
extern "C" int fn_804C78B0(void);
extern "C" int fn_804C78B8(void);
extern "C" int fn_804C78C0(void);
extern "C" int fn_804C78C8(void);
extern "C" int fn_804C78D0(FeScrN* x, int a);
extern "C" int fn_804C7900(FeScrN* x, FeW* w, int c, int d);
extern "C" void fn_804C794C(FeScrN* x);
extern "C" void fn_804C796C(FeScrN* x);
extern "C" void fn_804C7990(FeScrJ* x, int a);
extern "C" void fn_804C85BC();
extern "C" void fn_804C8634();
extern "C" void fn_804C92B0(FeScrN* x);
extern "C" FeScrH* fn_804C92D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804C8314(FeScrN* x, int a);
extern "C" void fn_804C776C(void* x, int a);
extern "C" int fn_804C713C(FeScrN* x, int a);

extern "C" FE_OVERLAY int fn_804C713C(FeScrN* x, int a)
{
    if (x->m138 != 0 && x->m134 == 0 && x->m13C == 0) {
        x->fn_vslot67(4, a);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrN* fn_804C71AC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F620);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    volatile int sp10 = 0;
    int i = 0;
    do {
        int q = i << 2;
        char* p = (char*)self + 0x178;
        *(int*)(p + q) = 0;
        int c2 = sp10;
        int t;
        if (c2 > 9)
            t = c2;
        else
            t = c2 + 1;
        sp10 = t;
        i = t;
    } while (i <= 9);
    return self;
}

extern "C" FE_OVERLAY void fn_804C7724(FeScrN* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804C7744(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804C776C(void* x, int a)
{
    switch (a) {
    case 0:
        fn_804C8354(x);
        break;
    case 1:
        fn_804C86E8((FeScrN*)x);
        break;
    case 2:
        fn_804C87F0(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804C77C0(FeScrN* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C77FC(FeScrN* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C7838(FeScrN* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C7874(FeScrN* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C78B0(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78B8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78C0(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78C8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78D0(FeScrN* x, int a)
{
    if (a == (int)x->m138) {
        fn_804C92B0((FeScrN*)x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804C7900(FeScrN* x, FeW* w, int c, int d)
{
    if ((int)w == (int)x->m138) {
        w->fn_vslot68(d);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C794C(FeScrN* x)
{
    fn_804C92B0(x);
}

extern "C" FE_OVERLAY void fn_804C796C(FeScrN* x)
{
    fn_804C81A0(x);
}

extern "C" FE_OVERLAY void fn_804C798C(void) {}

extern "C" FE_OVERLAY void fn_804C7990(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

extern "C" FE_OVERLAY int fn_804C79E0(FeScrN* x)
{
    switch (x->m138->fn_vslot60()) {
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
        return 9;
    }
}

extern "C" FE_OVERLAY int fn_804C7F30(FeScrN* x)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int h = fn_8007F7D0((Unk8007F198_B*)s, 0);
    volatile int sp8 = 0;
    int i = 0;
    do {
        int a = fn_8008FE14(i);
        int b = fn_8008FD78(*(int*)&sp8);
        int r = s->fn_8007B380(a, h);
        if (r != 0 && fn_8009047C(b, r) == 0)
            return 1;
        int c = sp8;
        int t;
        if (c > 9)
            t = c;
        else
            t = c + 1;
        sp8 = t;
        i = t;
    } while (i <= 9);
    return 0;
}

extern "C" FE_OVERLAY void fn_804C7FE4(FeScrN* x)
{
    int idx = fn_804C79E0(x);
    int a = fn_8008FD78(idx);
    int ioff = idx * 4;
    char* ib = (char*)x + 0x178;
    int item = *(int*)(ib + ioff);
    ((FeV8*)x->m160)->s8(1);
    if (item != 0) {
        void* h = fn_800C33D0();
        char wb[0x100];
        char nb[0x320];
        FeW* w = ((FeV32*)x->m160)->s32(lbl_805F55DC, 1);
        fn_800C40B4(h, fn_800C8038(w), a, item);
        fn_800DE538__Fiiii(nb, a, item, 1);
        ((FeV28*)x->m164)->s28(nb);
        ((FeV28*)x->m168)->s28(fn_80090880__FP11Unk80090880(lbl_8061977C, fn_8008FD14(a)));
        int b = fn_8009047C(a, item);
        float f = fn_80090380__FPv(a, item);
        DfW(nb, 0, 3, f);
        fn_80403DE4(wb, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x389D), b, nb);
        ((FeV28*)x->m16C)->s28(wb);
        fn_804C8874(x, idx);
    }
}

extern "C" FE_OVERLAY void fn_804C81A0(FeScrN* x)
{
    if (fn_804C7F30(x) != 0)
        fn_80125084(x->m140, 1);
    else
        fn_80125154(x->m140, 0);
    if (fn_800B555C()->m0 == 0x13) {
        fn_801251CC(x->m140, 2, 0x4DA2, 2);
        return;
    }
    fn_801251CC(x->m140, 0, 0x5B06, 1);
}

extern "C" FE_OVERLAY void fn_804C822C(FeScrN* x)
{
    char buf[0x100];
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    float v = s->fn_80079E74(fn_8007F7D0((Unk8007F198_B*)s, 0));
    fn_800DF254(buf, 0, 3, v);
    ((FeWV*)x->m144)->s28(buf);
    float w = *(float*)((char*)*(void**)s->m30 + 0x12B78);
    fn_800DF254(buf, 0, 3, w);
    ((FeWV*)x->m148)->s28(buf);
    x->m170->fn_vslot8(1);
}

extern "C" FE_OVERLAY void fn_804C8314(FeScrN* x, int a)
{
    if (a == (int)x->m160) {
        fn_804C7ACC(x);
        fn_804C7FE4(x);
    }
}

extern "C" FE_OVERLAY void fn_804C8354(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    if (fn_800B555C()->m0 == 0x13) {
        fn_8040B830(mp->name, "BACK_ORGINFO", 15);
        mp->name[15] = 0;
        fn_800B555C()->m3C = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
    } else {
        int g = fn_800A2EFC(lbl_80619948);
        if (g != 0) {
            fn_804C846C((FeScrN*)x);
        } else {
            fn_8040B830(mp->name, "BACK", 15);
            mp->name[15] = 0;
            fn_800B555C()->m3C = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

extern "C" FE_OVERLAY void fn_804C846C(FeScrN* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    int t = fn_804C7F30(x) != 0 ? 0x5CA9 : 0x5D85;
    fn_80131F34(p, x, (void (*)(int, void*))fn_804C8544, 0, t, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804C8544(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            fn_800A2F9C(lbl_80619948, 1);
            ((FeVt18*)lbl_80619948)->s5();
            fn_800B555C()->m3C = 0;
            ((void (*)(void*))fn_804C85BC)(x);
        }
    }
}

extern "C" FE_OVERLAY void fn_804C85BC()
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_804C8634;
    fn_8049ABD4(p);
}

extern "C" FE_OVERLAY void fn_804C8634()
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F8060);
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F806C, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, p);
}

extern "C" FE_OVERLAY void fn_804C86E8(FeScrN* x)
{
    int h = fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
    int id = fn_8008FE14(x->m138->fn_vslot60());
    int r = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(id, h);
    fn_800B555C()->m34 = r;
    char* t = (char*)fn_800B555C() + 8;
    *(int*)(t + 0x30) = x->m138->fn_vslot60();
    fn_800B555C()->m3C = 1;
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F8074, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern const char lbl_805F5B3C[];

extern "C" FE_OVERLAY void fn_804C87F0(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F5B3C, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_804C92B0(FeScrN* x)
{
    fn_804C7FE4(x);
}

extern "C" FE_OVERLAY FeScrH* fn_804C92D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F378);
    self->m130 = 0;
    return self;
}
