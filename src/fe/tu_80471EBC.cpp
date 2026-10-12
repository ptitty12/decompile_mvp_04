/*
 * Front-end overlay code, .frontend_codeoverlay 0x80471EBC-0x804740A8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
struct FeWV88 : Unk800C7B40_Data {
    virtual ~FeWV88();
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
    virtual void s82(); virtual void s83(); virtual void s84(int a, int b); virtual void s85();
    virtual void s86(); virtual void s87(); virtual void s88(int a, int b); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127();
};
struct FeSt28 {
    char pad0[0x28];
    int m28;
};
struct FeInfo2 {
    float f;
    int n;
    int m;
};
extern "C" {
char* strncpy(char* a, const char* b, unsigned n);
void fn_804722D4(void* x);
}
struct FeS134 {
    char pad0[0x134];
    int m134;
    int m138;
    int m13C;
};
struct FeSt634 {
    char pad0[0x634];
    int m634;
};
extern "C" int fn_805290E0();

extern "C" FE_OVERLAY FeScrH* fn_80471EBC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678AB0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804726A0(void* x)
{
    int r = FeWp(x, 0x140)->fn_vslot60();
    if (r >= 0) {
        void* p = fn_80548E1C(lbl_80619948->m58, r);
        fn_804A96A4(FeVp(x, 0x134), p, 1, 2, 1, 0, 1, 0);
    }
}

extern "C" FE_OVERLAY void fn_80472724(void* x)
{
    char* g = (char*)lbl_80619948->m58;
    fn_80124FA8(FeVp(x, 0x13C), x);
    fn_80125154(FeVp(x, 0x13C), 0);
    if (FeI(g, 0xCE4) != 0 && FeWp(x, 0x138) != 0) {
        if (FeWp(x, 0x138)->fn_vslot86() == 0)
            fn_801251CC(FeVp(x, 0x13C), 3, 0x1A2F, 1);
        else
            fn_801251CC(FeVp(x, 0x13C), 3, 0x37A2, 2);
    } else {
        fn_80125084(FeVp(x, 0x13C), 3);
    }
    if (FeWp(x, 0x140) != 0 && FeWp(x, 0x140)->fn_vslot59() > 0 && *fn_80548E2C(g, FeWp(x, 0x140)->fn_vslot60()) == 0) {
        fn_801251CC(FeVp(x, 0x13C), 0, 0x1C58, 4);
        fn_801251CC(FeVp(x, 0x13C), 2, 0x416D, 3);
    } else {
        fn_80125084(FeVp(x, 0x13C), 2);
        fn_80125084(FeVp(x, 0x13C), 0);
    }
}

extern "C" FE_OVERLAY void fn_80472888(void* p, int a)
{
    FeScrH* x = (FeScrH*)p;
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    int g = lbl_80619948->m58;
    int sel = FeWp(x, 0x140)->fn_vslot60();
    switch (a) {
    case 0:
        strncpy(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 4: {
        FeSt28* st = (FeSt28*)((char*)fn_800B555C() + 8);
        st->m28 = (int)fn_80548E1C(g, sel);
        strncpy(mp->name, "OFFER", 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
    case 3: {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        FeInfo2 info;
        info.f = 0.0f;
        info.n = 0;
        void* r = fn_80548E1C(g, sel);
        fn_80548C7C((void*)g, (int)r, fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0));
        fn_804722D4(x);
        fn_804726A0(x);
        break;
    }
    case 1: {
        int v = FeWp(x, 0x140)->fn_vslot60();
        if (v >= 0) {
            int g2 = lbl_80619948->m58;
            FeWp(x, 0x140)->fn_vslot14(1);
            void* r = fn_80548E1C(g2, v);
            fn_80126CF4((FeList*)FeWp(x, 0x138), (int)r, 0, 0, 0, 0, 0, 1, a, a, 0);
            ((FeWV88*)FeWp(x, 0x138))->s84(0, 0);
            ((FeWV88*)FeWp(x, 0x138))->s88(0, FeWp(x, 0x140)->fn_vslot59() > 1);
            fn_801251CC(FeVp(x, 0x13C), 3, 0x37A2, 2);
            fn_8001BC4C()->fn_8001BDAC(0xA3);
        }
        break;
    }
    case 2: {
        FeList* l = (FeList*)FeWp(x, 0x138);
        fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        fn_801251CC(FeVp(x, 0x13C), 3, 0x1A2F, 1);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_80472BBC(void* x)
{
    FeAt(x, 0x140)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472BF8(void* x)
{
    FeAt(x, 0x140)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472C34(void* x)
{
    FeAt(x, 0x140)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472C70(void* x)
{
    FeAt(x, 0x140)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80472CAC(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x140)) {
        w->fn_vslot68(c);
        x->fn_vslot67(1, 0);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80472D24(void* x, int w)
{
    if (w == FeI(x, 0x140)) {
        fn_804726A0(x);
        int r = FeWp(x, 0x140)->fn_vslot60();
        if (FeWp(x, 0x138)->fn_vslot86() != 0 && r >= 0) {
            void* p = fn_80548E1C(lbl_80619948->m58, r);
            char* s = (char*)FeVp(x, 0x138);
            fn_80126CF4((FeList*)s, (int)p, FeI(s, 0x168), FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
        }
        fn_80472724(x);
    }
}

extern "C" FE_OVERLAY FeScrH* fn_80472E04(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678808);
    self->m130 = 0;
    FeI(self, 0x13C) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80472E54(void* p)
{
    FeS134* x = (FeS134*)p;
    fn_800ECF18(x);
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    fn_801250D8(w);
    fn_800C2034((char*)fn_800B555C() + 8, 0);
    fn_800B555C();
    if (fn_800B5758() != 0) {
        ((FeW*)x)->fn_vslot32("OWNER", 1);
        x->m134 = (int)fn_800C8060();
        ((FeW*)x)->fn_vslot32("DYNASTY", 1)->fn_vslot8(0);
    } else {
        ((FeW*)x)->fn_vslot32("DYNASTY", 1);
        x->m134 = (int)fn_800C8060();
        ((FeW*)x)->fn_vslot32("OWNER", 1)->fn_vslot8(0);
    }
    ((FeW*)x->m134)->fn_vslot8(1);
    x->m138 = (int)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    x->m13C = (int)fn_800B7AB8(FeGetMgr(), lbl_805F528C);
    if (fn_800B555C()->m0 == 0x55) {
        FeSt634* s = (FeSt634*)((char*)fn_800B555C() + 8);
        s->m634++;
    }
    ((FeW*)x->m134)->fn_vslot105(1);
    fn_804730A4(x);
    fn_804739BC((FeW*)x);
}

extern "C" FE_OVERLAY void fn_804730A4(void* x)
{
    int i = 0;
    int n = FeI(fn_800B555C(), 0x63C);
    for (; i < n; i++) {
        ((FeWV91*)FeWp(x, 0x134))->s91(i, 0, 0);
        ((FeWV91*)FeWp(x, 0x134))->s91(i, 1, 0);
        FeWp(x, 0x134)->fn_vslot73(i, 0)->fn_vslot32("DONE", 1)->fn_vslot8(1);
    }
    FeWp(x, 0x134)->fn_vslot67(i, 0);
}

extern "C" FE_OVERLAY void fn_804731C4(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804731E4(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473220(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047325C(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473298(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804732D4(FeW* x)
{
    FeI(fn_800B555C(), 0x640) = 0;
    x->fn_vslot80(0);
    x->fn_vslot67(FeWp(x, 0x134)->fn_vslot60(), 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047336C(FeW* x, int a, int b, int c)
{
    int r;
    if (a != FeI(x, 0x134)) {
        r = 0;
    } else {
        x->fn_vslot67(c, 0);
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804733C4(void* x, char* buf)
{
    *buf = 0;
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    fn_8040B830(buf, (char*)w + 0xC, 16);
}

extern "C" FE_OVERLAY void fn_80473440(void* x)
{
    int v = 0;
    int s = FeWp(x, 0x134)->fn_vslot60();
    FeI(fn_800B555C(), 0x63C) = s;
    fn_800B555C();
    if (fn_800B5758() != 0) {
        switch (s) {
        case 1:
            v = 0xE;
            break;
        case 2:
            v = 0xF;
            break;
        case 3:
            v = 0x10;
            break;
        case 4:
            v = 0x11;
            break;
        case 5:
            v = 0x12;
            break;
        case 6:
            v = 0x13;
            break;
        case 7:
            v = 0x14;
            break;
        }
    } else {
        switch (s) {
        case 1:
            v = 0xE;
            break;
        case 2:
            v = 0xF;
            break;
        case 3:
            v = 0x10;
            break;
        case 4:
            v = 0x11;
            break;
        case 5:
            v = 0x12;
            break;
        case 6:
            v = 0x13;
            break;
        }
    }
    fn_80449168((FePopup*)FeVp(x, 0x13C), v, x, (void (*)(void*))fn_80473630);
}

extern "C" FE_OVERLAY void fn_80473560(FeScrD* x)
{
    if (lbl_80619948->m80 == 10) {
        void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 15, t) == 0) {
            void* u = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, t);
            int w = fn_8007B8C4__18Unk8007B2B0_Screenii(lbl_8061930C, 0x37, u);
            fn_805819A4(FeVp(lbl_8061930C, 0x2C), u, w);
        }
    }
    fn_800B7ADC(FeGetMgr(), x);
}

extern "C" FE_OVERLAY void fn_80473630(FeScrD* x)
{
    fn_80473560(x);
}

extern "C" FE_OVERLAY void fn_80473650(int a, void* b)
{
    if (a != 0) {
        if (a == 1)
            fn_80473440(b);
    }
}

extern "C" FE_OVERLAY void fn_80473684(int a, FeW* x)
{
    if (a != 0) {
        if (a == 1) {
            fn_800A2030(lbl_80619948, 1);
            x->fn_vslot80(1);
            fn_800B7ADC(FeGetMgr(), x);
        }
    }
}

extern "C" FE_OVERLAY int fn_80473718(void* x)
{
    int v = FeWp(x, 0x134)->fn_vslot60();
    return v > FeI(fn_800B555C(), 0x63C);
}

extern "C" FE_OVERLAY void fn_80473770(void* x, int k)
{
    char buf[1400];
    fn_800B555C();
    if ((fn_800B56C4() != 0 && k == 7) || ((fn_800B555C(), fn_800B5758() != 0) && k == 8)) {
        int id;
        fn_800B555C();
        id = 0x1D;
        if (fn_800B56C4() != 0) {
            id = 0x4FBA;
        } else {
            fn_800B555C();
            if (fn_800B5758() != 0)
                id = 0x5740;
        }
        fn_80131F34(FeWp(x, 0x138), x, (FeCbT)fn_80473684, (int)fn_805290E0, id, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        FeWp(x, 0x138)->fn_vslot86();
    } else if (fn_80473718(x) != 0) {
        int g = lbl_8061977C;
        fn_800B555C();
        if ((fn_800B56C4() != 0 && k == 6) || ((fn_800B555C(), fn_800B5758() != 0) && k == 7)) {
            fn_80403144(buf, fn_80090880__FP11Unk80090880(g, 0x4FBC));
        } else {
            FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
            FeW* w = (FeW*)fn_800C8048();
            int s = fn_80090880__FP11Unk80090880(g, 0x1911);
            fn_804031F8(buf, s, w->fn_vslot31());
        }
        int s1 = fn_80090880__FP11Unk80090880(g, 0x3E9);
        int s2 = fn_80090880__FP11Unk80090880(g, 0x3E8);
        fn_801321D4(FeWp(x, 0x138), x, (FeCbT)fn_80473650, 0, buf, 2, -1, 1, (const char*)s1, (const char*)s2, 0, 0, 0, 0);
        FeWp(x, 0x138)->fn_vslot86();
    } else {
        fn_80473560((FeScrD*)x);
    }
}

extern "C" FE_OVERLAY void fn_804739BC(FeW* x)
{
    int z = ((FeWV93*)FeWp(x, 0x134))->s93(4, 0) == 0;
    x->fn_vslot32("REQINFO", 1);
    FeW* w = fn_800C8044();
    if (z != 0) {
        fn_800E4C1C(fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0), w);
        w->fn_vslot8(1);
    } else {
        w->fn_vslot8(0);
    }
}

extern "C" FE_OVERLAY void fn_80473A98(void* x, int a)
{
    fn_800ED310(x, a);
    FeWp(x, 0x134)->fn_vslot14(a);
}

extern "C" FE_OVERLAY FeScrH* fn_80473AE8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678560);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80473B38(void* x)
{
    fn_800ECF18(x);
    fn_800B555C();
    if (fn_800B56C4() != 0) {
        void* g = lbl_8061930C;
        int st = fn_8007FE04((Unk8007F198_D*)g)->m1E0;
        if (lbl_806217C0 == 0 && st == 1) {
            int i;
            int n = fn_8007B2B0__18Unk8007B2B0_Screen(g);
            for (i = 0; i < n; i++) {
                void* k = fn_8007B2FC__18Unk8007B2B0_Screeni(g, i);
                if (!(fn_80079EFC__18Unk8007B2B0_Screeni(g, k) > 0.0f)) {
                    float a = fn_80079E74__18Unk8007B2B0_Screeni(g, k);
                    float b = a * 1.01f;
                    fn_8007B4A8__18Unk8007B2B0_Screeniii(g, 0x15, k, fn_80079F90__18Unk8007B2B0_Screenf(g, b));
                }
            }
        }
        lbl_806217C0 = st;
    }
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
    ((FeW*)x)->fn_vslot32(lbl_805F4EF4, 1);
    FeI(x, 0x134) = (int)fn_800C8060();
    fn_800B555C();
    if (fn_800B57EC() != 0 && fn_800A2E6C(lbl_80619948) != 0) {
        FePopup* q = fn_800B7AB8(FeGetMgr(), "FTOPBAR");
        fn_800C2034((char*)fn_800B555C() + 8, 0);
        fn_804A7760(q);
        q->fn_vslot8(0);
    }
}

extern "C" FE_OVERLAY int fn_80473D44(void* x)
{
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    char* s = (char*)w + 0xC;
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, s, 15);
    p->name[15] = 0;
    int c = fn_8040B574(s, "GAMEPLAYOPTIONS");
    if (c == 0) {
        fn_800B555C();
        if (fn_800B5758() != 0) {
            fn_8040B830(p->name, "OM_GAMEPLAYOPTS", 15);
            p->name[15] = c;
        }
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80473E48(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80473EB4(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473EF0(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473F2C(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473F68(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473FA4(void* x)
{
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    char* s = (char*)w + 0xC;
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, s, 15);
    p->name[15] = 0;
    int c = fn_8040B574(s, "GAMEPLAYOPTIONS");
    if (c == 0) {
        fn_800B555C();
        if (fn_800B5758() != 0) {
            fn_8040B830(p->name, "OM_GAMEPLAYOPTS", 15);
            p->name[15] = c;
        }
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}
