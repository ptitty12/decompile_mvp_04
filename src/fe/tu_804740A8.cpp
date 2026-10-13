/*
 * Front-end overlay code, .frontend_codeoverlay 0x804740A8-0x80477068 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
struct FeV10D {
    char pad0[0x10];
};
struct FeV10 : FeV10D {
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
    virtual int s13(int a);
};
extern "C" char* strncpy(char*, const char*, unsigned);
struct FeW57 : Unk800C7B40_Data {
    virtual ~FeW57();
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
    virtual void s57(const char* a, float b, float c, float d); virtual float s58();
    virtual void s59(float a); virtual void s60(); virtual float s61(); virtual float s62();
    virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67();
    virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72();
    virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77();
    virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81(); virtual void s82();
    virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87();
    virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91(); virtual void s92();
    virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96(); virtual void s97();
    virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101(); virtual void s102();
    virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106(); virtual void s107();
    virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111(); virtual void s112();
    virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116(); virtual void s117();
    virtual void s118(); virtual void s119(); virtual void s120(); virtual void s121(); virtual void s122();
    virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126(); virtual void s127();
};
extern "C" {
void fn_80476258(void* x);
void fn_80476584(void* x);
}
extern "C" {
int fn_800E5D74__Fi(int v);
int fn_8013484C();
}

extern "C" FE_OVERLAY FeScrH* fn_804740A8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806782B8);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_80474660(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804746CC(FeW* x)
{
    if (fn_8040B574((char*)FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1) + 0xC, "AUTODOROSTERS") == 0) {
        fn_804749D8(x);
    } else if (fn_8040B574((char*)FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1) + 0xC, "AUTOSELECT") == 0) {
        fn_80474AF8(x);
    } else {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804747E8(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80474824(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80474860(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047489C(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804748D8(void* x)
{
    ((FeW*)x)->fn_vslot41(0);
    return 1;
}

extern "C" FE_OVERLAY void fn_80474914(void* x, char* buf)
{
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    fn_8040B830(buf, (char*)w + 0xC, 16);
}

extern "C" FE_OVERLAY void fn_80474988(void* x, int a)
{
    fn_800ED310(x, a);
    FeWp(x, 0x134)->fn_vslot14(a);
}

extern "C" FE_OVERLAY void fn_804749D8(FeW* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    fn_80131F34(p, x, (FeCbT)fn_80474A98, 0, 0x4DA7, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80474A98(int a)
{
    if (a == 1) {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 0);
        fn_8055EAFC(fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0));
    }
}

extern "C" FE_OVERLAY void fn_80474AF8(FeW* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    fn_80131F34(p, x, (FeCbT)fn_80474BB8, 0, 0x5A3D, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80474BB8(int a)
{
    FeGlobal80619948* g = lbl_80619948;
    if (a == 1) {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 1);
        void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        void* h = fn_8007F9B4__FP13Unk8007F198_C(lbl_8061930C);
        fn_80560B44(t, fn_8056681C(FeVp(g, 0x48), h), 1);
    }
}

extern "C" FE_OVERLAY FeScrH* fn_80474C44(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677818);
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804753E8(FeW* x, int sel, int c)
{
    switch (sel) {
    case 0:
        fn_804756F0(x);
        break;
    case 1:
        fn_804757EC(x);
        break;
    case 2:
        fn_80475EF0(x);
        break;
    case 3: {
        int r = fn_80476C44(x);
        if (r == 4)
            x->fn_vslot67(1, c);
        else if (r == 5)
            x->fn_vslot67(2, c);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804754C0(void* x)
{
    FeAt(x, 0x164)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804754FC(void* x)
{
    FeAt(x, 0x164)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475538(void* x)
{
    FeAt(x, 0x164)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475574(void* x)
{
    FeAt(x, 0x164)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804755B0(void* x)
{
    FeAt(x, 0x164)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804755EC(void* x)
{
    FeAt(x, 0x164)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475628(void* x)
{
    FeAt(x, 0x164)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475664(void* x)
{
    FeAt(x, 0x164)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804756A0(void* x, int a)
{
    fn_800ED310(x, a);
    FeWp(x, 0x164)->fn_vslot14(a);
}

extern "C" FE_OVERLAY void fn_804756F0(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

extern "C" FE_OVERLAY int fn_80475774(int a, int b, int c)
{
    return fn_8007A270__18Unk8007A4DC_Screeni(lbl_8061930C, a) == 0 ? *(int*)((char*)lbl_805FD54C + b * 4 + c * 16) : *(int*)((char*)lbl_805FD4FC + b * 4 + c * 20);
}

extern "C" FE_OVERLAY void fn_80475EF0(void* x)
{
    char small[200];
    char big[1000];
    fn_800DE440(small, FeI(x, 0x138), 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, fn_800E5D74__Fi(FeI(x, 0x138))), (int)small);
    ((FeWV*)FeWp(x, 0x168))->s84(1);
    const char* s1 = (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(FeWp(x, 0x168), x, (FeCbT)fn_80476A28, (int)fn_8013484C, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    FeWp(x, 0x168)->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80475FFC(void* x)
{
    ((void (*)(void*, int, int))fn_80079564)(lbl_8061930C, FeI(x, 0x138), 0);
    fn_80131F34(FeWp(x, 0x168), x, (FeCbT)fn_80476C24, (int)fn_8013484C, 0x1C5C, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    fn_804766FC(x);
    fn_80476258(x);
    fn_80476584(x);
    ((FeWV*)FeWp(x, 0x168))->s84(0);
    FeWp(x, 0x168)->fn_vslot86();
    FeWp(x, 0x164)->fn_vslot14(0);
    ((FeW*)x)->fn_vslot16(0);
    FeWp(x, 0x16C)->fn_vslot16(0);
}

extern "C" FE_OVERLAY int fn_80476134(int x, int b)
{
    if (b != 0)
        return 3 - x / 5;
    return 3 - x / 4;
}

extern "C" FE_OVERLAY int fn_80476178(int x, int b)
{
    if (b != 0)
        return 4 - x % 5;
    return 3 - x % 4;
}

extern "C" FE_OVERLAY int fn_804761D0(int x, int b)
{
    return b == 0 ? lbl_806217D8[fn_80476178(x, 0)] : lbl_806217C4[fn_80476178(x, b)];
}

extern "C" FE_OVERLAY int fn_80476220(int x, int b)
{
    return lbl_806217E8[fn_80476134(x, b)];
}

extern "C" FE_OVERLAY void fn_80476258(void* x)
{
    char b8[0x68];
    char b70[200];
    float fv[4];
    float* p26C;
    int i270;
    char b148[0x20];
    char b168[0x100];
    char* p8 = b8;
    char* p70 = b70;
    char* p148 = b148;
    char* p168 = b168;
    int id = FeI(x, 0x138);
    fn_80563F3C(*(int*)((char*)lbl_80619948 + 0x3C), FeI(x, 0x134), id, &fv[0], &p26C, &i270, 0, 0);
    fv[2] = fv[0];
    ((char* (*)(char*, int, int, float))fn_800DF254)(p8, 0, 3, fv[2]);
    ((char* (*)(char*, const char*, ...))fn_80403DE4)(p70, (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x389D), p26C, p8);
    ((FeWV*)FeWp(x, 0x170))->s28(p70);
    ((void (*)(void*, void*))fn_804031BC)(p148, lbl_805F5EEC);
    int g = fn_8007A270__18Unk8007A4DC_Screeni(lbl_8061930C, id);
    const char* s1 = (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, fn_804761D0(i270, g));
    ((void (*)(char*, char*, const char*, ...))fn_80403DE4)(p168, p148, (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, fn_80476220(i270, g)), s1);
    ((FeWV*)FeWp(x, 0x174))->s28(p168);
    int c;
    float b = ((c = fn_80476134(i270, g)) != 3) ? FeF(lbl_8061930C, 0x1F4) : lbl_805F5EF4;
    FeW57* fw = (FeW57*)FeWp(x, 0x154);
    fw->s57(lbl_805F5EB4, b, ((FeW57*)FeWp(x, 0x154))->s61(), ((FeW57*)FeWp(x, 0x154))->s62());
    ((FeW57*)FeWp(x, 0x154))->s59(!(((FeW57*)FeWp(x, 0x154))->s61() >= fv[0]) ? ((FeW57*)FeWp(x, 0x154))->s61() : fv[0]);
    ((FeW57*)FeWp(x, 0x158))->s59((float)(unsigned)p26C);
    FeW* w160 = FeWp(x, 0x160);
    ((FeSub*)((char*)w160 + 0xDC))->s6(c);
    FeW* w15C = FeWp(x, 0x15C);
    ((FeSub*)((char*)w15C + 0xDC))->s6(fn_80476178(i270, g));
    fn_8012E1C4(FeI(x, 0x16C), 1, 0x234F);
}

extern "C" FE_OVERLAY void fn_80476584(void* x)
{
    char buf[0xC8];
    void* g = lbl_8061930C;
    int id = fn_80075948__18Unk8007B2B0_Screeni(g, FeI(x, 0x134));
    int c = (fn_8007FE04((Unk8007F198_D*)g)->m1E0 == 1);
    int d = c;
    if (c) {
        float f = fn_80079B14__18Unk8007B2B0_Screeni(g, id);
        ((char* (*)(char*, int, int, float))fn_800DF254)(buf, 0, 3, f);
        ((FeWV*)FeWp(x, 0x148))->s28(buf);
    } else {
        ((FeWV*)FeWp(x, 0x148))->s29(0x1A4B);
    }
    float f2 = fn_80079E74__18Unk8007B2B0_Screeni(g, (void*)id);
    ((char* (*)(char*, int, int, float))fn_800DF254)(buf, 0, 3, f2);
    ((FeWV*)FeWp(x, 0x14C))->s28(buf);
    if (d) {
        float f3 = fn_80079EFC__18Unk8007B2B0_Screeni(g, (void*)id);
        ((char* (*)(char*, int, int, float))fn_800DF254)(buf, 0, 3, f3);
        ((FeWV*)FeWp(x, 0x150))->s28(buf);
    } else {
        ((FeWV*)FeWp(x, 0x150))->s29(0x1A4B);
    }
}

extern "C" FE_OVERLAY void fn_804766FC(void* x)
{
    FeW* w = FeWp(x, 0x15C);
    void* g = lbl_8061930C;
    ((FeSubV15*)((char*)w + 0xDC))->s15();
    if (fn_8007A270__18Unk8007A4DC_Screeni(g, FeI(x, 0x138)) != 0) {
        int i;
        for (i = 0; i < 5; i++)
            ((FeWV51*)FeWp(x, 0x15C))->s51(lbl_806217C4[i], 0);
    } else {
        int i;
        for (i = 0; i < 4; i++)
            ((FeWV51*)FeWp(x, 0x15C))->s51(lbl_806217D8[i], 0);
    }
}

extern "C" FE_OVERLAY void fn_804767E4(int a, FeScrD* x)
{
    int c = 0;
    if (FeI(x, 0x140) != 0) {
        int cnt = 0;
        int i = 0;
        int cat = fn_800A1960(lbl_80619948);
        FeV10* o = (FeV10*)fn_800A199C(lbl_80619948);
        int k = o->s13(FeI(x, 0x134));
        while (fn_80546B18(cat, k, i) != 0) {
            if (fn_80546CA8(cat, k, i) == 0)
                cnt++;
            i++;
        }
        c = cnt == 0;
    } else if (FeI(x, 0x13C) == 0) {
        FeArr arr;
        char buf[1000];
        FeArr* s = &arr;
        int cnt = 0;
        int i;
        s->m10 = lbl_8064B298;
        s->m0 = buf;
        s->m8 = 0xFA;
        fn_8040074C(s->m0, 0x3E8);
        s->m4 = 0;
        s->mC = 0;
        s->m10 = lbl_8064A550;
        fn_8040074C(s->m0, s->m8 * 4);
        s->m10 = lbl_8065C1B0;
        s->m4 = 0;
        s->mC = 0;
        s->m14 = 0;
        fn_80535360((void**)s, fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x134)));
        int n = s->m4;
        for (i = 0; i < n; i++) {
            if (((int (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(lbl_8061930C, 0x19, FePick(arr.m0, i * 4)) == 0)
                cnt++;
        }
        c = cnt == 0;
        s->m10 = lbl_8064A550;
    }
    const char* str = "SIGNED";
    if (c != 0 && (FeI(fn_800B555C(), 4) & 0x1000) != 0)
        str = "EMPTY";
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    strncpy(mp->name, str, 15);
    mp->name[15] = 0;
    ((FeW*)x)->fn_vslot80(1);
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_80476A28(int a, void* x)
{
    FeWp(x, 0x164)->fn_vslot14(1);
    if (a == 1)
        fn_80475FFC(x);
}

extern "C" FE_OVERLAY void fn_80476A84(int a, FeScrD* x)
{
    int c = 0;
    if (FeI(x, 0x140) == 0 && FeI(x, 0x13C) == 0) {
        FeArr arr;
        char buf[1000];
        FeArr* s = &arr;
        int cnt = 0;
        int i;
        s->m10 = lbl_8064B298;
        s->m0 = buf;
        s->m8 = 0xFA;
        fn_8040074C(s->m0, 0x3E8);
        s->m4 = 0;
        s->mC = 0;
        s->m10 = lbl_8064A550;
        fn_8040074C(s->m0, s->m8 * 4);
        s->m10 = lbl_8065C1B0;
        s->m4 = 0;
        s->mC = 0;
        s->m14 = 0;
        fn_80535360((void**)s, fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x134)));
        int n = s->m4;
        for (i = 0; i < n; i++) {
            if (((int (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(lbl_8061930C, 0x19, FePick(arr.m0, i * 4)) == 0)
                cnt++;
        }
        c = cnt == 0;
        s->m10 = lbl_8064A550;
    }
    const char* str = "BACK";
    if (c != 0 && (FeI(fn_800B555C(), 4) & 0x1000) != 0)
        str = "EMPTY";
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    strncpy(mp->name, str, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_80476C24(int a, FeScrD* x)
{
    fn_80476A84(a, x);
}

extern "C" FE_OVERLAY int fn_80476C44(void* x)
{
    FeW* w = FeWp(x, 0x164)->fn_vslot70();
    if (w->fn_vslot30("SALARY", 1) != 0)
        return 0;
    if (w->fn_vslot30("TERM", 1) != 0)
        return 1;
    if (w->fn_vslot30("STATUS", 1) != 0)
        return 2;
    if (w->fn_vslot30("LEVEL", 1) != 0)
        return 3;
    if (w->fn_vslot30("RESIGNPLAYERST", 1) != 0)
        return 4;
    w->fn_vslot30("RELEASEPLAYERST", 1);
    return 5;
}

extern "C" FE_OVERLAY int fn_80476DB4(void* x)
{
    switch (fn_80476C44(x)) {
    case 4:
    case 5:
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80476DEC(void* x, int a)
{
    if (a == FeI(x, 0x164)) {
        if (fn_80476DB4(x) != 0)
            fn_801251CC(FeVp(x, 0x178), 0, 0x10, 3);
        else
            fn_80125084(FeVp(x, 0x178), 0);
    }
}

extern "C" FE_OVERLAY int fn_80476E50(FeW* x, int a)
{
    int r;
    if (a == FeI(x, 0x164) && fn_80476DB4(x)) {
        x->fn_vslot67(3, 0);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_80476EBC(void* x)
{
    float a = ((FeW57*)FeWp(x, 0x154))->s58();
    FeW* w = FeWp(x, 0x160);
    float b = (((FeSub*)((char*)w + 0xDC))->s5() != 3) ? FeF(lbl_8061930C, 0x1F4) : lbl_805F5F30;
    FeW57* fw = (FeW57*)FeWp(x, 0x154);
    fw->s57(lbl_805F5EB4, b, ((FeW57*)FeWp(x, 0x154))->s61(), ((FeW57*)FeWp(x, 0x154))->s62());
    ((FeW57*)FeWp(x, 0x154))->s59(a >? b);
}

extern "C" FE_OVERLAY FeScrH* fn_80477000(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676DD0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = -1;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 4;
    FeI(self, 0x144) = -1;
    return self;
}
