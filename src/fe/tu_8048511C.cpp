/*
 * Front-end overlay code, .frontend_codeoverlay 0x8048511C-0x80488CDC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

static inline int Fe596CAt(int* a, int i)
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
extern "C" int fn_80529118(void);
typedef void (*Fe81F4Print)(char*, int, ...);
#define PrintX ((void (*)(char*, int, ...))fn_80403DE4)
typedef void (*Fe81F4Pop)(void*, void*, FeCbT, int (*)(void), void*, int, int, int, int, int, int, int, int, int);
#define PopX ((Fe81F4Pop)fn_801321D4)

static inline void Fe7D44Swap(void* s, int a, int b, int va, int vb)
{
    fn_8007F29C__FP13Unk8007F198_Aii(s, a, va);
    fn_8007F330__FP13Unk8007F198_Aii(s, a, vb);
    fn_8007F29C__FP13Unk8007F198_Aii(s, b, vb);
    fn_8007F330__FP13Unk8007F198_Aii(s, b, va);
}

static inline int T(int t, int id)
{
    return fn_80090880__FP11Unk80090880(t, id);
}

static inline int Fe7D44Pos(void* s, int k, int sel)
{
    return ((int (*)(void*, int, int))fn_8007B320__18Unk8007B2B0_Screenii)(s, k, sel);
}

struct Fe7A64View {
    char pad0[0x164];
    int m164[25];
    int m1C8[25];
};
extern "C" {
void fn_8048856C(void* x);
void fn_804886DC(void* x);
void fn_804881F4(void* x);
void fn_80488A14(void* x);
void fn_80488B74(void* x);
}

extern "C" {
void fn_80488CD4(void);
void fn_80488CD8(void);
}
typedef void (*Fe8A14Pop)(void*, void*, FeCbT, int, void*, int, int, int, int, int, int, int, int, int);

extern "C" FE_OVERLAY FeScrH* fn_8048511C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676880);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = -1;
    FeI(self, 0x158) = -1;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x254) = 0;
    FeI(self, 0x258) = 0;
    FeI(self, 0x25C) = 0;
    FeI(self, 0x260) = 1;
    return self;
}

extern "C" FE_OVERLAY void fn_804851B0(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

extern "C" FE_OVERLAY void fn_80485944(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_8048596C(void* x)
{
    fn_800ECAA4(x);
    if (FeWp(x, 0x13C)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x13C))->s69(1);
        if (FeWp(x, 0x150) != FeWp(x, 0x13C))
            FeWp(x, 0x13C)->fn_vslot14(0);
    }
    if (FeWp(x, 0x140)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x140))->s69(1);
        if (FeWp(x, 0x150) != FeWp(x, 0x140))
            FeWp(x, 0x140)->fn_vslot14(0);
    }
    if (FeWp(x, 0x138)->fn_vslot87() != 0) {
        int* a = ((Fe7A64View*)x)->m1C8;
        int cur = FeWp(x, 0x138)->fn_vslot87();
        if (cur != Fe596CAt(a, FeWp(x, 0x140)->fn_vslot60())) {
            int v = Fe596CAt(a, FeWp(x, 0x140)->fn_vslot60());
            FeList* l = (FeList*)FeWp(x, 0x138);
            fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
    if (FeWp(x, 0x138)->fn_vslot86() != 0) {
        int* a = ((Fe7A64View*)x)->m164;
        int cur = FeWp(x, 0x138)->fn_vslot86();
        if (cur != Fe596CAt(a, FeWp(x, 0x13C)->fn_vslot60())) {
            int v = Fe596CAt(a, FeWp(x, 0x13C)->fn_vslot60());
            FeList* l = (FeList*)FeWp(x, 0x138);
            fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
    fn_80486650(x);
}

extern "C" FE_OVERLAY int fn_80485C28(void* x)
{
    if (fn_80488178(x) != 0)
        return 0;
    int idx = FeWp(x, 0x150)->fn_vslot60();
    FeW* cur = FeWp(x, 0x150);
    if (cur == FeWp(x, 0x13C))
        fn_80487A64(x, idx);
    else if (cur == FeWp(x, 0x140))
        fn_80487BD4(x, idx);
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80485CC4(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    int v = FeI(fn_800B555C(), 0x598);
    if (v != 0) {
        fn_8040B830(p->name, "DEPTHCHART", 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80485D78(void* x)
{
    if (fn_804880D8(x) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        FeW* cur = FeWp(x, 0x150);
        if (cur == FeWp(x, 0x13C)) {
            FeList* l = (FeList*)FeWp(x, 0x138);
            fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        } else if (cur == FeWp(x, 0x140)) {
            FeList* l = (FeList*)FeWp(x, 0x138);
            fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    } else {
        int v;
        int k = FeWp(x, 0x150)->fn_vslot60();
        FeW* cur = FeWp(x, 0x150);
        if (cur == FeWp(x, 0x13C)) {
            v = ((Fe7A64View*)x)->m164[k];
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x138);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeW88*)FeWp(x, 0x138))->s88(0, FeWp(x, 0x150)->fn_vslot59() > 1);
            }
        } else if (cur == FeWp(x, 0x140)) {
            v = ((Fe7A64View*)x)->m1C8[k];
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x138);
                fn_80126CF4(l, l->m164, ((Fe7A64View*)x)->m1C8[k], l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeW88*)FeWp(x, 0x138))->s88(1, FeWp(x, 0x150)->fn_vslot59() > 1);
            }
        }
    }
    fn_80486650(x);
    FeWp(x, 0x138)->fn_vslot84(FeWp(x, 0x150) != FeWp(x, 0x13C) ? 1 : 0, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_80486018(void* x, int w, int dir)
{
    if (w == FeI(x, 0x14C)) {
        if (dir == 0) {
            int t = FeI(x, 0x250) - 1;
            if (t >= 0)
                FeI(x, 0x250) = t;
            else
                FeI(x, 0x250) = 5;
        } else {
            int t = FeI(x, 0x250) + 1;
            if (t <= 5)
                FeI(x, 0x250) = t;
            else
                FeI(x, 0x250) = 0;
        }
    } else if (w == FeI(x, 0x244)) {
        FeW* a = FeWp(x, 0x24C);
        void* g = lbl_8061930C;
        FeI(x, 0x254) = fn_80075948__18Unk8007B2B0_Screeni(g, fn_800B548C(((FeSubB*)((char*)a + 0x98))->s5()));
    }
    fn_80486800(x);
    fn_80486D7C(x);
    fn_804873B4(x);
}

extern "C" FE_OVERLAY int fn_804860F8(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x13C)) {
        int t = FeI(x, 0x154);
        if ((t == -1 && FeI(x, 0x158) == -1) || t == c || t != -1)
            fn_80487A64(x, c);
        fn_80487FE0(x, FeI(x, 0x13C));
    } else if (a == FeI(x, 0x140)) {
        if (FeI(x, 0x154) == -1)
            fn_80487BD4(x, c);
        fn_80487FE0(x, FeI(x, 0x140));
    }
    fn_804873B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804861A8(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x13C)) {
        fn_80487FE0(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    } else if (w == FeWp(x, 0x140)) {
        fn_80487FE0(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    }
    fn_804873B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804862A0(void* x)
{
    FeAt(x, 0x150)->fn_vslot50();
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804862F0(void* x)
{
    FeAt(x, 0x150)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048632C(void* x)
{
    FeAt(x, 0x150)->fn_vslot52();
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048637C(void* x)
{
    FeAt(x, 0x150)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804863B8(void* x)
{
    if (FeI(x, 0x150) != FeI(x, 0x13C))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80487FE0(x, FeI(x, 0x13C));
    return 0;
}

extern "C" FE_OVERLAY int fn_8048640C(void* x)
{
    if (FeI(x, 0x150) != FeI(x, 0x140))
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    fn_80487FE0(x, FeI(x, 0x140));
    return 0;
}

extern "C" FE_OVERLAY int fn_80486460(void* x)
{
    FeAt(x, 0x14C)->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804864A0(void* x, int a)
{
    FeAt(x, 0x14C)->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804864DC(void* x)
{
    FeAt(x, 0x14C)->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_8048651C(void* x)
{
    FeAt(x, 0x14C)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_80486558(void* x)
{
    FeAt(x, 0x244)->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80486598(void* x, int a)
{
    FeAt(x, 0x244)->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804865D4(void* x)
{
    FeAt(x, 0x244)->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80486614(void* x)
{
    FeAt(x, 0x244)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_80486650(void* x)
{
    fn_80125100(FeVp(x, 0x134));
    if (FeAt(x, 0x150)->fn_vslot59() == 0) {
        fn_80125084(FeVp(x, 0x134), 0);
        fn_80125084(FeVp(x, 0x134), 3);
        return;
    }
    if (fn_80488178(x) != 0) {
        fn_80125084(FeVp(x, 0x134), 0);
    } else {
        int f = 0;
        if (FeI(x, 0x154) != -1) {
            f = 1;
            if (FeI(x, 0x150) == FeI(x, 0x13C))
                f = 0;
        } else if (FeI(x, 0x158) != -1) {
            f = 1;
            if (FeI(x, 0x150) == FeI(x, 0x140))
                f = 0;
        }
        if (f != 0)
            fn_80125180(FeVp(x, 0x134), 0, 0x41BB);
        else
            fn_80125180(FeVp(x, 0x134), 0, 0x10);
        int g = 0;
        FeW* cur = FeWp(x, 0x150);
        if ((cur == FeWp(x, 0x13C) && FeI(x, 0x154) == cur->fn_vslot60()) || (FeWp(x, 0x150) == FeWp(x, 0x140) && FeI(x, 0x158) == FeWp(x, 0x150)->fn_vslot60()))
            g = 1;
        if (g != 0)
            fn_80125180(FeVp(x, 0x134), 0, 0x3B97);
    }
    fn_80125180(FeVp(x, 0x134), 3, fn_804880D8(x) != 0 ? 0x37A2 : 0x1A2F);
}

extern "C" FE_OVERLAY void fn_80487A64(void* x, int a)
{
    if (((Fe7A64View*)x)->m164[0] != 0 && ((Fe7A64View*)x)->m164[a] != 0) {
        {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            int sel = FeI(x, 0x154);
            if (sel == -1) {
                if (FeI(x, 0x158) == -1) {
                    FeI(x, 0x154) = a;
                    ((FeWV90*)FeAt(x, 0x13C))->s90(a, 1, 1);
                    if (fn_8007F198__FP13Unk8007F198_A((int)lbl_8061930C, FeI(x, 0x25C)) <= 0x18)
                        fn_8048856C(x);
                    else
                        fn_80488A14(x);
                } else {
                    FeI(x, 0x154) = a;
                    fn_804881F4(x);
                }
            } else if (a == sel) {
                ((FeWV90*)FeAt(x, 0x13C))->s90(a, 1, 0);
                FeI(x, 0x154) = -1;
            } else {
                ((FeWV90*)FeAt(x, 0x13C))->s90(sel, 1, 0);
                FeI(x, 0x154) = a;
                ((FeWV90*)FeAt(x, 0x13C))->s90(a, 1, 1);
                fn_80488A14(x);
            }
        }
    }
}

extern "C" FE_OVERLAY void fn_80487BD4(void* x, int a)
{
    if (((Fe7A64View*)x)->m1C8[0] != 0 && ((Fe7A64View*)x)->m1C8[a] != 0) {
        {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            int sel = FeI(x, 0x158);
            if (sel == -1) {
                if (FeI(x, 0x154) == -1) {
                    FeI(x, 0x158) = a;
                    ((FeWV90*)FeAt(x, 0x140))->s90(a, 1, 1);
                    if (fn_8007F198__FP13Unk8007F198_A((int)lbl_8061930C, FeI(x, 0x258)) <= 0x18)
                        fn_804886DC(x);
                    else
                        fn_80488B74(x);
                } else {
                    FeI(x, 0x158) = a;
                    fn_804881F4(x);
                }
            } else if (a == sel) {
                ((FeWV90*)FeAt(x, 0x140))->s90(a, 1, 0);
                FeI(x, 0x158) = -1;
            } else {
                ((FeWV90*)FeAt(x, 0x140))->s90(sel, 1, 0);
                FeI(x, 0x158) = a;
                ((FeWV90*)FeAt(x, 0x140))->s90(a, 1, 1);
                fn_80488B74(x);
            }
        }
    }
}

extern "C" FE_OVERLAY void fn_80487D44(void* x, int a, int b)
{
    void* s = lbl_8061930C;
    int sel = FeI(x, 0x254);
    int va = ((Fe7A64View*)x)->m164[a];
    int vb = ((Fe7A64View*)x)->m1C8[b];
    int p0 = Fe7D44Pos(s, 0, sel);
    int p1 = Fe7D44Pos(s, 1, sel);
    int p2 = Fe7D44Pos(s, 2, sel);
    int p3 = Fe7D44Pos(s, 3, sel);
    switch (FeI(x, 0x250)) {
    case 0:
        Fe7D44Swap(s, p1, p0, va, vb);
        break;
    case 1:
        Fe7D44Swap(s, p2, p0, va, vb);
        break;
    case 2:
        Fe7D44Swap(s, p3, p0, va, vb);
        break;
    case 3:
        Fe7D44Swap(s, p2, p1, va, vb);
        break;
    case 4:
        Fe7D44Swap(s, p3, p1, va, vb);
        break;
    case 5:
        Fe7D44Swap(s, p3, p2, va, vb);
        break;
    }
    ((FeWV90*)FeAt(x, 0x13C))->s90(a, 1, 0);
    ((FeWV90*)FeAt(x, 0x140))->s90(b, 1, 0);
    FeI(x, 0x154) = -1;
    FeI(x, 0x158) = -1;
    fn_80486D7C(x);
    fn_804873B4(x);
}

extern "C" FE_OVERLAY void fn_80487FE0(void* x, int wi)
{
    FeW* w = (FeW*)wi;
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x140)->fn_vslot14(0);
    FeWp(x, 0x150) = w;
    w->fn_vslot14(1);
    if (w == FeWp(x, 0x13C))
        FeWp(x, 0x138)->fn_vslot84(0, 0);
    else if (w == FeWp(x, 0x140))
        FeWp(x, 0x138)->fn_vslot84(1, 0);
    fn_80486650(x);
}

extern "C" FE_OVERLAY int fn_804880D8(void* x)
{
    if (FeI(x, 0x150) == FeI(x, 0x13C)) {
        if (FeWp(x, 0x138)->fn_vslot86() != 0)
            return 1;
    }
    if (FeI(x, 0x150) == FeI(x, 0x140)) {
        if (FeWp(x, 0x138)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80488178(void* x)
{
    int r = 0;
    if (FeWp(x, 0x138)->fn_vslot86() != 0 || FeWp(x, 0x138)->fn_vslot87() != 0)
        r = 1;
    return r;
}

extern "C" FE_OVERLAY void fn_804881F4(void* x)
{
    char big[600];
    char s1[64];
    char s2[64];
    int t = (int)lbl_8061977C;
    FeAt(x, 0x13C)->fn_vslot16(0);
    FeAt(x, 0x140)->fn_vslot16(0);
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), "POPUP");
    char* q1 = s1;
    char* q2 = s2;
    char* a = (char*)x + 0x164;
    ((int (*)(char*, int, int))fn_800DE440)(q1, *(int*)(a + FeI(x, 0x154) * 4), 0);
    char* b = (char*)x + 0x1C8;
    fn_800DE440(q2, *(int*)(b + FeI(x, 0x158) * 4), 0);
    switch (FeI(x, 0x250)) {
    case 0:
        PrintX(big, T(t, 0x41BF), q1, T(t, 0x3FB7), q2, T(t, 0x3FB8));
        break;
    case 1:
        PrintX(big, T(t, 0x41BF), q1, T(t, 0x3FB7), q2, T(t, 0x3FB9));
        break;
    case 2:
        PrintX(big, T(t, 0x41BF), q1, T(t, 0x3FB7), q2, T(t, 0x5A1A));
        break;
    case 3:
        PrintX(big, T(t, 0x41BF), q1, T(t, 0x3FB8), q2, T(t, 0x3FB9));
        break;
    case 4:
        PrintX(big, T(t, 0x41BF), q1, T(t, 0x3FB8), q2, T(t, 0x5A1A));
        break;
    case 5:
        PrintX(big, T(t, 0x41BF), q1, T(t, 0x3FB9), q2, T(t, 0x5A1A));
        break;
    }
    int n1 = T(t, 0x26DE);
    int n2 = T(t, 0x26DF);
    PopX(p, x, fn_804884C0, fn_80529118, big, 2, -1, 1, n1, n2, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804884C0(int a, void* x)
{
    FeWp(x, 0x13C)->fn_vslot16(1);
    FeWp(x, 0x140)->fn_vslot16(1);
    if (a == 0) {
        fn_80487D44(x, FeI(x, 0x154), FeI(x, 0x158));
    } else if (FeI(x, 0x150) == FeI(x, 0x13C)) {
        FeI(x, 0x154) = -1;
    } else {
        FeI(x, 0x158) = -1;
    }
}

extern "C" FE_OVERLAY void fn_8048856C(void* x)
{
    char big[1000];
    char small[200];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    int t = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x25C));
    int id;
    if (t != 0) {
        if (t != 1) {
            id = 0x5A1A;
            if (t == 2)
                id = 0x3BE3;
        } else
            id = 0x3BE2;
    } else
        id = 0x3FB7;
    char* sp = small;
    char* b = (char*)x + 0x164;
    fn_800DE440(sp, *(int*)(b + FeI(x, 0x154) * 4), 0);
    int fmt = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F1A);
    ((void (*)(char*, int, ...))fn_80403DE4)(big, fmt, sp, fn_80090880__FP11Unk80090880(lbl_8061977C, id));
    int s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    int s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    ((Fe8A14Pop)fn_801321D4)(p, x, (FeCbT)fn_8048884C, 0, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804886DC(void* x)
{
    char big[1000];
    char small[200];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    int t = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x258));
    int id;
    if (t != 0) {
        if (t != 1) {
            id = 0x5A1A;
            if (t == 2)
                id = 0x3BE3;
        } else
            id = 0x3BE2;
    } else
        id = 0x3FB7;
    char* sp = small;
    char* b = (char*)x + 0x1C8;
    fn_800DE440(sp, *(int*)(b + FeI(x, 0x158) * 4), 0);
    int fmt = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F1B);
    ((void (*)(char*, int, ...))fn_80403DE4)(big, fmt, sp, fn_80090880__FP11Unk80090880(lbl_8061977C, id));
    int s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    int s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    ((Fe8A14Pop)fn_801321D4)(p, x, (FeCbT)fn_80488930, 0, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_8048884C(int a, void* x)
{
    if (a == 0) {
        ((FeWV90*)FeWp(x, 0x13C))->s90(FeI(x, 0x154), 1, 0);
        FeI(x, 0x154) = -1;
    } else if (a == 1) {
        int i = FeI(x, 0x154);
        void* g = lbl_8061930C;
        int o = i * 4;
        char* b = (char*)x + 0x164;
        int v = *(int*)(b + o);
        fn_8007F29C__FP13Unk8007F198_Aii(g, FeI(x, 0x258), v);
        fn_8007F330__FP13Unk8007F198_Aii(g, FeI(x, 0x25C), v);
        ((FeWV90*)FeWp(x, 0x13C))->s90(FeI(x, 0x154), 1, 0);
        FeI(x, 0x154) = -1;
        fn_80486D7C(x);
        fn_804873B4(x);
    }
}

extern "C" FE_OVERLAY void fn_80488930(int a, void* x)
{
    if (a == 0) {
        ((FeWV90*)FeWp(x, 0x140))->s90(FeI(x, 0x158), 1, 0);
        FeI(x, 0x158) = -1;
    } else if (a == 1) {
        int i = FeI(x, 0x158);
        void* g = lbl_8061930C;
        int o = i * 4;
        char* b = (char*)x + 0x1C8;
        int v = *(int*)(b + o);
        fn_8007F29C__FP13Unk8007F198_Aii(g, FeI(x, 0x25C), v);
        fn_8007F330__FP13Unk8007F198_Aii(g, FeI(x, 0x258), v);
        ((FeWV90*)FeWp(x, 0x140))->s90(FeI(x, 0x158), 1, 0);
        FeI(x, 0x158) = -1;
        fn_80486D7C(x);
        fn_804873B4(x);
    }
}

extern "C" FE_OVERLAY void fn_80488A14(void* x)
{
    char big[1000];
    char small[200];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    int t = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x25C));
    int id;
    if (t != 0) {
        if (t != 1) {
            id = 0x5A1A;
            if (t == 2)
                id = 0x3BE3;
        } else
            id = 0x3BE2;
    } else
        id = 0x3FB7;
    char* sp = small;
    char* b = (char*)x + 0x164;
    fn_800DE440(sp, *(int*)(b + FeI(x, 0x154) * 4), 0);
    int fmt = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F1C);
    ((void (*)(char*, int, ...))fn_80403DE4)(big, fmt, fn_80090880__FP11Unk80090880(lbl_8061977C, id), sp);
    int s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE);
    ((Fe8A14Pop)fn_801321D4)(p, x, (FeCbT)fn_80488CD4, 0, big, 1, -1, 1, s1, 0, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80488B74(void* x)
{
    char big[1000];
    char small[200];
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    int t = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x258));
    int id;
    if (t != 0) {
        if (t != 1) {
            id = 0x5A1A;
            if (t == 2)
                id = 0x3BE3;
        } else
            id = 0x3BE2;
    } else
        id = 0x3FB7;
    char* sp = small;
    char* b = (char*)x + 0x1C8;
    fn_800DE440(sp, *(int*)(b + FeI(x, 0x158) * 4), 0);
    int fmt = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F1C);
    ((void (*)(char*, int, ...))fn_80403DE4)(big, fmt, fn_80090880__FP11Unk80090880(lbl_8061977C, id), sp);
    int s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE);
    ((Fe8A14Pop)fn_801321D4)(p, x, (FeCbT)fn_80488CD8, 0, big, 1, -1, 1, s1, 0, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80488CD4(void) {}

extern "C" FE_OVERLAY void fn_80488CD8(void) {}
