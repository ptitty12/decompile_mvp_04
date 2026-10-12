/*
 * Front-end overlay code, .frontend_codeoverlay 0x8047D454-0x80481634 (code-only unit;
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
extern "C" void fn_804805B4(void* x);

extern "C" FE_OVERLAY void fn_8047D9CC(void* x)
{
    fn_800ECAA4(x);
    if (FeWp(x, 0x138)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x138))->s69(1);
        if (FeWp(x, 0x14C) != FeWp(x, 0x138))
            FeWp(x, 0x138)->fn_vslot14(0);
    }
    if (FeWp(x, 0x13C)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x13C))->s69(1);
        if (FeWp(x, 0x14C) != FeWp(x, 0x13C))
            FeWp(x, 0x13C)->fn_vslot14(0);
    }
    if (fn_8047F3B0(x) != 0) {
        if (FeWp(x, 0x14C) == FeWp(x, 0x138)) {
            char* t = (char*)x + 0x158;
            int cur = FeWp(x, 0x144)->fn_vslot86();
            if (cur != FePick(t, FeWp(x, 0x14C)->fn_vslot60() * 4)) {
                int v = FePick(t, FeWp(x, 0x14C)->fn_vslot60() * 4);
                FeList* l = (FeList*)FeWp(x, 0x144);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        } else if (FeWp(x, 0x14C) == FeWp(x, 0x13C)) {
            char* t = (char*)x + 0x1BC;
            int cur = FeWp(x, 0x144)->fn_vslot87();
            if (cur != FePick(t, FeWp(x, 0x14C)->fn_vslot60() * 4)) {
                int v = FePick(t, FeWp(x, 0x14C)->fn_vslot60() * 4);
                FeList* l = (FeList*)FeWp(x, 0x144);
                fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        }
    }
    fn_8047E244(x);
}

extern "C" FE_OVERLAY int fn_8047DC70(void* x)
{
    if (fn_8047F450(x) != 0 || FeI(x, 0x220) != 0)
        return 0;
    int idx = FeWp(x, 0x14C)->fn_vslot60();
    FeW* cur = FeWp(x, 0x14C);
    if (cur == FeWp(x, 0x138))
        fn_8047F0A4(x, idx);
    else if (cur == FeWp(x, 0x13C))
        fn_8047F1C0(x, idx);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047DD0C(void* x)
{
    if (FeI(x, 0x228) == 0 || FeI(x, 0x22C) == 0)
        fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047DD80(void* x)
{
    if (fn_8047F3B0(x) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        if (FeWp(x, 0x14C) == FeWp(x, 0x138)) {
            FeList* l = (FeList*)FeWp(x, 0x144);
            fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        } else if (FeWp(x, 0x14C) == FeWp(x, 0x13C)) {
            FeList* l = (FeList*)FeWp(x, 0x144);
            fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    } else {
        int idx = FeWp(x, 0x14C)->fn_vslot60();
        int v;
        if (FeWp(x, 0x14C) == FeWp(x, 0x138)) {
            char* t1 = (char*)x + 0x158;
            v = FePick(t1, idx * 4);
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x144);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeWV88*)FeWp(x, 0x144))->s88(0, FeWp(x, 0x14C)->fn_vslot59() > 1);
            }
        } else if (FeWp(x, 0x14C) == FeWp(x, 0x13C)) {
            int o = idx * 4;
            char* t = (char*)x + 0x1BC;
            v = FePick(t, o);
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x144);
                fn_80126CF4(l, l->m164, FePick(t, o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeWV88*)FeWp(x, 0x144))->s88(1, FeWp(x, 0x14C)->fn_vslot59() > 1);
            }
        }
    }
    fn_8047E244(x);
    ((FeWV88*)FeWp(x, 0x144))->s84(FeWp(x, 0x14C) == FeWp(x, 0x138) ? 0 : 1, 0);
    fn_8047E490(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E028(void* x)
{
    FeAt(x, 0x14C)->fn_vslot50();
    fn_8047E490(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E078(void* x)
{
    FeAt(x, 0x14C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E0B4(void* x)
{
    FeAt(x, 0x14C)->fn_vslot52();
    fn_8047E490(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E104(void* x)
{
    FeAt(x, 0x14C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E140(void* x)
{
    if (FeI(x, 0x14C) != FeI(x, 0x138))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_8047E7E8(x, FeI(x, 0x138));
    fn_8047E490(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_8047E19C(void* x)
{
    if (FeI(x, 0x220) == 0) {
        if (FeI(x, 0x14C) != FeI(x, 0x13C))
            fn_8001BC4C()->fn_8001BDAC(0x9C);
        fn_8047E7E8(x, FeI(x, 0x13C));
        fn_8047E490(x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8047E204(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E20C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E214(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E21C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E224(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E22C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E234(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E23C(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_8047E244(void* x)
{
    if (FeI(x, 0x228) == 0 || FeI(x, 0x22C) == 0)
        fn_80125100(FeVp(x, 0x140));
    if (fn_8047F450(x) != 0) {
        fn_80125084(FeVp(x, 0x140), 0);
    } else {
        int f = 0;
        if (FeI(x, 0x150) != -1) {
            f = 1;
            if (FeI(x, 0x14C) == FeI(x, 0x138))
                f = 0;
        } else if (FeI(x, 0x154) != -1) {
            f = 1;
            if (FeI(x, 0x14C) == FeI(x, 0x13C))
                f = 0;
        }
        if (f != 0)
            fn_80125180(FeVp(x, 0x140), 0, 0xE12);
        else
            fn_80125180(FeVp(x, 0x140), 0, 0x10);
        int r = 0;
        if ((FeWp(x, 0x14C) == FeWp(x, 0x138) && FeI(x, 0x150) == FeWp(x, 0x14C)->fn_vslot60())
            || (FeWp(x, 0x14C) == FeWp(x, 0x13C) && FeI(x, 0x154) == FeWp(x, 0x14C)->fn_vslot60()))
            r = 1;
        if (r != 0)
            fn_80125180(FeVp(x, 0x140), 0, 0x3B97);
    }
    fn_80125180(FeVp(x, 0x140), 3, fn_8047F3B0(x) != 0 ? 0x37A2 : 0x1A2F);
    if (FeI(x, 0x220) != 0)
        fn_80125084(FeVp(x, 0x140), 0);
    if ((FeWp(x, 0x14C) == FeWp(x, 0x13C) && FePick((char*)x + 0x1BC, FeWp(x, 0x14C)->fn_vslot60() * 4) == 0)
        || (FeWp(x, 0x14C) == FeWp(x, 0x138) && FePick((char*)x + 0x158, FeWp(x, 0x14C)->fn_vslot60() * 4) == 0)) {
        fn_80125084(FeVp(x, 0x140), 3);
        if (FeWp(x, 0x14C) != FeWp(x, 0x138) || FeI(x, 0x150) == -1)
            fn_80125084(FeVp(x, 0x140), 0);
    }
}

extern "C" FE_OVERLAY void fn_8047E490(void* x)
{
    int v = 0;
    FeW* cur = FeWp(x, 0x14C);
    if (cur == FeWp(x, 0x138)) {
        v = FePick((char*)x + 0x158, cur->fn_vslot60() * 4);
        fn_80122D40(FeWp(x, 0x148), v, 1, 1, 0, 0, (char*)x + 0x158);
    } else if (cur == FeWp(x, 0x13C)) {
        v = FePick((char*)x + 0x1BC, cur->fn_vslot60() * 4);
        fn_80122D40(FeWp(x, 0x148), v, 1, 1, 0, 0, (char*)x + 0x1BC);
    }
    if (v != 0) {
        FeWp(x, 0x148)->fn_vslot32("TEAMLOGO", 1);
        ((FeSubV8*)((char*)fn_800C8054() + 0x98))->s8(FeI(x, 0x134));
    }
}

extern "C" FE_OVERLAY int fn_8047E5B0(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x138)) {
        int t = FeI(x, 0x150);
        if ((t == -1 && FeI(x, 0x154) == -1) || t == c || t != -1)
            fn_8047F0A4(x, c);
        fn_8047E7E8(x, FeI(x, 0x138));
    } else if (a == FeI(x, 0x13C)) {
        if (FeI(x, 0x150) == -1)
            fn_8047F1C0(x, c);
        fn_8047E7E8(x, FeI(x, 0x13C));
    }
    fn_8047E490(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_8047E660(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x138)) {
        fn_8047E7E8(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    } else if (w == FeWp(x, 0x13C)) {
        fn_8047E7E8(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    }
    fn_8047E490(x);
    return 0;
}

extern "C" FE_OVERLAY void fn_8047E758(void* x, int a)
{
    FeI(x, 0x134) = a;
    fn_8047E8E0(x);
    FeWp(x, 0x14C)->fn_vslot68(0);
    FeWp(x, 0x138)->fn_vslot14(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
}

extern "C" FE_OVERLAY void fn_8047E7E8(void* x, int wi)
{
    FeW* w = (FeW*)wi;
    FeWp(x, 0x138)->fn_vslot14(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x14C) = w;
    w->fn_vslot14(1);
    if (w == FeWp(x, 0x138))
        FeWp(x, 0x144)->fn_vslot84(0, 0);
    else if (w == FeWp(x, 0x13C))
        FeWp(x, 0x144)->fn_vslot84(1, 0);
    fn_8047E244(x);
}

extern "C" FE_OVERLAY void fn_8047F0A4(void* x, int a)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    int t = FeI(x, 0x150);
    if (t == -1) {
        int u = FeI(x, 0x154);
        if (u == -1) {
            FeI(x, 0x150) = a;
            ((FeWV90*)FeWp(x, 0x138))->s90(a, 1, 1);
        } else {
            fn_8047F2DC((char*)x, a, u);
        }
    } else if (a == t) {
        ((FeWV90*)FeWp(x, 0x138))->s90(a, 1, 0);
        FeI(x, 0x150) = -1;
    } else {
        ((FeWV90*)FeWp(x, 0x138))->s90(t, 1, 0);
        FeI(x, 0x150) = a;
        ((FeWV90*)FeWp(x, 0x138))->s90(a, 1, 1);
    }
}

extern "C" FE_OVERLAY void fn_8047F1C0(void* x, int a)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    int t = FeI(x, 0x154);
    if (t == -1) {
        int u = FeI(x, 0x150);
        if (u == -1) {
            FeI(x, 0x154) = a;
            ((FeWV90*)FeWp(x, 0x13C))->s90(a, 1, 1);
        } else {
            fn_8047F2DC((char*)x, u, a);
        }
    } else if (a == t) {
        ((FeWV90*)FeWp(x, 0x13C))->s90(a, 1, 0);
        FeI(x, 0x154) = -1;
    } else {
        ((FeWV90*)FeWp(x, 0x13C))->s90(t, 1, 0);
        FeI(x, 0x154) = a;
        ((FeWV90*)FeWp(x, 0x13C))->s90(a, 1, 1);
    }
}

extern "C" FE_OVERLAY void fn_8047F2DC(char* x, int a, int b)
{
    int idx = fn_8047F4CC(x);
    FeNode4* n = lbl_806192E0->m4;
    char* base = (char*)n->m14;
    char* rec = base + idx * 0xE64;
    int o1 = b * 4;
    char* b1 = x + 0x1BC;
    int r = fn_800968C0(rec, *(int*)(b1 + o1), 1);
    int o2 = a * 4;
    char* b2 = x + 0x158;
    fn_80081BA8__FP13Unk8007FF8C_Yiii(base, idx, fn_80097288(rec, *(int*)(b2 + o2)), r);
    if (FeI(x, 0x228) == 1 && FeI(x, 0x22C) == 1) {
        FeI(fn_800B555C(), 0x628) = 0;
        fn_80125100(FeWp(x, 0x140));
        FeI(x, 0x22C) = 0;
    }
    fn_8047E8E0(x);
    fn_8047E490(x);
}

extern "C" FE_OVERLAY int fn_8047F3B0(void* x)
{
    if (FeWp(x, 0x14C) == FeWp(x, 0x138)) {
        if (FeWp(x, 0x144)->fn_vslot86() != 0)
            return 1;
    }
    if (FeWp(x, 0x14C) == FeWp(x, 0x13C)) {
        if (FeWp(x, 0x144)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8047F450(void* x)
{
    int r = 0;
    if (FeWp(x, 0x144)->fn_vslot86() != 0 || FeWp(x, 0x144)->fn_vslot87() != 0)
        r = 1;
    return r;
}

extern "C" FE_OVERLAY int fn_8047F4CC(void* x)
{
    FeNode4* n = lbl_806192E0->m4;
    FeA70* a = n->m10;
    FeAFFC* b = n->m14;
    if (FeI(x, 0x134) == b->mFFC && a->m70 != -1)
        return 1;
    return 0;
}

extern "C" FE_OVERLAY FeScrH* fn_8047F508(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677D68);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = -1;
    FeI(self, 0x164) = -1;
    FeI(self, 0x230) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8047FAF0(void* x)
{
    fn_800ECAA4(x);
    if (FeWp(x, 0x138)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x138))->s69(1);
        if (FeWp(x, 0x15C) != FeWp(x, 0x138))
            FeWp(x, 0x138)->fn_vslot14(0);
    }
    if (FeWp(x, 0x13C)->fn_vslot61() != 1) {
        ((FeWV*)FeWp(x, 0x13C))->s69(1);
        if (FeWp(x, 0x15C) != FeWp(x, 0x13C))
            FeWp(x, 0x13C)->fn_vslot14(0);
    }
    if (fn_804814DC(x) != 0) {
        if (FeWp(x, 0x15C) == FeWp(x, 0x138)) {
            char* t = (char*)x + 0x168;
            int cur = FeWp(x, 0x154)->fn_vslot86();
            if (cur != FePick(t, FeWp(x, 0x15C)->fn_vslot60() * 4)) {
                int v = FePick(t, FeWp(x, 0x15C)->fn_vslot60() * 4);
                FeList* l = (FeList*)FeWp(x, 0x154);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        } else if (FeWp(x, 0x15C) == FeWp(x, 0x13C)) {
            char* t = (char*)x + 0x1CC;
            int cur = FeWp(x, 0x154)->fn_vslot87();
            if (cur != FePick(t, FeWp(x, 0x15C)->fn_vslot60() * 4)) {
                int v = FePick(t, FeWp(x, 0x15C)->fn_vslot60() * 4);
                FeList* l = (FeList*)FeWp(x, 0x154);
                fn_80126CF4(l, l->m164, v, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        }
    }
    fn_80480380(x);
}

extern "C" FE_OVERLAY int fn_8047FD94(void* x)
{
    if (fn_8048157C(x) != 0 || FeI(x, 0x230) != 0)
        return 0;
    int idx = FeWp(x, 0x15C)->fn_vslot60();
    FeW* cur = FeWp(x, 0x15C);
    if (cur == FeWp(x, 0x138))
        fn_80481200(x, idx);
    else if (cur == FeWp(x, 0x13C))
        fn_8048131C(x, idx);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047FE30(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047FE8C(void* x)
{
    if (fn_804814DC(x) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        if (FeWp(x, 0x15C) == FeWp(x, 0x138)) {
            FeList* l = (FeList*)FeWp(x, 0x154);
            fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        } else if (FeWp(x, 0x15C) == FeWp(x, 0x13C)) {
            FeList* l = (FeList*)FeWp(x, 0x154);
            fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    } else {
        int idx = FeWp(x, 0x15C)->fn_vslot60();
        int v;
        if (FeWp(x, 0x15C) == FeWp(x, 0x138)) {
            char* t1 = (char*)x + 0x168;
            v = FePick(t1, idx * 4);
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x154);
                fn_80126CF4(l, v, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeWV88*)FeWp(x, 0x154))->s88(0, FeWp(x, 0x15C)->fn_vslot59() > 1);
            }
        } else if (FeWp(x, 0x15C) == FeWp(x, 0x13C)) {
            int o = idx * 4;
            char* t = (char*)x + 0x1CC;
            v = FePick(t, o);
            if (v != 0) {
                fn_8001BC4C()->fn_8001BDAC(0xA3);
                FeList* l = (FeList*)FeWp(x, 0x154);
                fn_80126CF4(l, l->m164, FePick(t, o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                ((FeWV88*)FeWp(x, 0x154))->s88(1, FeWp(x, 0x15C)->fn_vslot59() > 1);
            }
        }
    }
    FeWp(x, 0x140)->fn_vslot16(fn_8048157C(x) ^ 1);
    fn_80480380(x);
    ((FeWV88*)FeWp(x, 0x154))->s84(FeWp(x, 0x15C) == FeWp(x, 0x138) ? 0 : 1, 0);
    fn_804805B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80480164(void* x)
{
    FeAt(x, 0x15C)->fn_vslot50();
    fn_804805B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804801B4(void* x)
{
    FeAt(x, 0x15C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804801F0(void* x)
{
    FeAt(x, 0x15C)->fn_vslot52();
    fn_804805B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80480240(void* x)
{
    FeAt(x, 0x15C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048027C(void* x)
{
    if (FeI(x, 0x15C) != FeI(x, 0x138))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80480960(x, FeI(x, 0x138));
    fn_804805B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804802D8(void* x)
{
    if (FeI(x, 0x230) == 0) {
        if (FeI(x, 0x15C) != FeI(x, 0x13C))
            fn_8001BC4C()->fn_8001BDAC(0x9C);
        fn_80480960(x, FeI(x, 0x13C));
        fn_804805B4(x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80480340(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480348(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480350(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480358(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480360(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480368(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480370(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480378(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_80480380(void* x)
{
    fn_80125100(FeVp(x, 0x150));
    if (fn_8048157C(x) != 0) {
        fn_80125084(FeVp(x, 0x150), 0);
    } else {
        int f = 0;
        if (FeI(x, 0x160) != -1) {
            f = 1;
            if (FeI(x, 0x15C) == FeI(x, 0x138))
                f = 0;
        } else if (FeI(x, 0x164) != -1) {
            f = 1;
            if (FeI(x, 0x15C) == FeI(x, 0x13C))
                f = 0;
        }
        if (f != 0)
            fn_80125180(FeVp(x, 0x150), 0, 0xE12);
        else
            fn_80125180(FeVp(x, 0x150), 0, 0x10);
        int r = 0;
        if ((FeWp(x, 0x15C) == FeWp(x, 0x138) && FeI(x, 0x160) == FeWp(x, 0x15C)->fn_vslot60())
            || (FeWp(x, 0x15C) == FeWp(x, 0x13C) && FeI(x, 0x164) == FeWp(x, 0x15C)->fn_vslot60()))
            r = 1;
        if (r != 0)
            fn_80125180(FeVp(x, 0x150), 0, 0x3B97);
    }
    fn_80125180(FeVp(x, 0x150), 3, fn_804814DC(x) != 0 ? 0x37A2 : 0x1A2F);
    if (FeI(x, 0x230) != 0)
        fn_80125084(FeVp(x, 0x150), 0);
    if ((FeWp(x, 0x15C) == FeWp(x, 0x13C) && FePick((char*)x + 0x1CC, FeWp(x, 0x15C)->fn_vslot60() * 4) == 0)
        || (FeWp(x, 0x15C) == FeWp(x, 0x138) && FePick((char*)x + 0x168, FeWp(x, 0x15C)->fn_vslot60() * 4) == 0)) {
        fn_80125084(FeVp(x, 0x150), 3);
        if (FeWp(x, 0x15C) != FeWp(x, 0x138) || FeI(x, 0x160) == -1)
            fn_80125084(FeVp(x, 0x150), 0);
    }
}

extern "C" FE_OVERLAY void fn_804805B4(void* x)
{
    int v = 0;
    FeW* cur = FeWp(x, 0x15C);
    if (cur == FeWp(x, 0x138)) {
        v = FePick((char*)x + 0x168, cur->fn_vslot60() * 4);
        fn_80122D40(FeWp(x, 0x158), v, 1, 1, 0, 0, (char*)x + 0x168);
    } else if (cur == FeWp(x, 0x13C)) {
        v = FePick((char*)x + 0x1CC, cur->fn_vslot60() * 4);
        fn_80122D40(FeWp(x, 0x158), v, 1, 1, 0, 0, (char*)x + 0x1CC);
    }
    if (v != 0) {
        FeWp(x, 0x158)->fn_vslot32("TEAMLOGO", 1);
        ((FeSubV8*)((char*)fn_800C8054() + 0x98))->s8(FeI(x, 0x134));
    }
}

extern "C" FE_OVERLAY int fn_804806D4(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x138)) {
        int t = FeI(x, 0x160);
        if ((t == -1 && FeI(x, 0x164) == -1) || t == c || t != -1)
            fn_80481200(x, c);
        fn_80480960(x, FeI(x, 0x138));
    } else if (a == FeI(x, 0x13C)) {
        if (FeI(x, 0x160) == -1)
            fn_8048131C(x, c);
        fn_80480960(x, FeI(x, 0x13C));
    }
    fn_804805B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_80480784(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x138)) {
        fn_80480960(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    } else if (w == FeWp(x, 0x13C)) {
        fn_80480960(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    }
    fn_804805B4(x);
    return 0;
}

extern "C" FE_OVERLAY void fn_8048087C(void* x, int a)
{
    FeI(x, 0x134) = a;
    FeW* w = FeWp(x, 0x148);
    ((FeSubV20*)((char*)w + 0x98))->s20(a, 0);
    FeW* v = FeWp(x, 0x14C);
    ((FeSubV20*)((char*)v + 0xDC))->s20(a, 0);
    fn_80480A58(x);
    FeWp(x, 0x15C)->fn_vslot68(0);
    FeWp(x, 0x138)->fn_vslot14(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
}

extern "C" FE_OVERLAY void fn_80480960(void* x, int wi)
{
    FeW* w = (FeW*)wi;
    FeWp(x, 0x138)->fn_vslot14(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x15C) = w;
    w->fn_vslot14(1);
    if (w == FeWp(x, 0x138))
        FeWp(x, 0x154)->fn_vslot84(0, 0);
    else if (w == FeWp(x, 0x13C))
        FeWp(x, 0x154)->fn_vslot84(1, 0);
    fn_80480380(x);
}

extern "C" FE_OVERLAY void fn_80481200(void* x, int a)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    int t = FeI(x, 0x160);
    if (t == -1) {
        int u = FeI(x, 0x164);
        if (u == -1) {
            FeI(x, 0x160) = a;
            ((FeWV90*)FeWp(x, 0x138))->s90(a, 1, 1);
        } else {
            fn_80481438((char*)x, a, u);
        }
    } else if (a == t) {
        ((FeWV90*)FeWp(x, 0x138))->s90(a, 1, 0);
        FeI(x, 0x160) = -1;
    } else {
        ((FeWV90*)FeWp(x, 0x138))->s90(t, 1, 0);
        FeI(x, 0x160) = a;
        ((FeWV90*)FeWp(x, 0x138))->s90(a, 1, 1);
    }
}

extern "C" FE_OVERLAY void fn_8048131C(void* x, int a)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    int t = FeI(x, 0x164);
    if (t == -1) {
        int u = FeI(x, 0x160);
        if (u == -1) {
            FeI(x, 0x164) = a;
            ((FeWV90*)FeWp(x, 0x13C))->s90(a, 1, 1);
        } else {
            fn_80481438((char*)x, u, a);
        }
    } else if (a == t) {
        ((FeWV90*)FeWp(x, 0x13C))->s90(a, 1, 0);
        FeI(x, 0x164) = -1;
    } else {
        ((FeWV90*)FeWp(x, 0x13C))->s90(t, 1, 0);
        FeI(x, 0x164) = a;
        ((FeWV90*)FeWp(x, 0x13C))->s90(a, 1, 1);
    }
}

extern "C" FE_OVERLAY void fn_80481438(char* x, int a, int b)
{
    int idx = fn_804815F8(x);
    FeNode4* n = lbl_806192E0->m4;
    char* base = (char*)n->m14;
    char* rec = base + idx * 0xE64;
    int o1 = b * 4;
    char* b1 = x + 0x1CC;
    int r = fn_800968C0(rec, *(int*)(b1 + o1), 1);
    int o2 = a * 4;
    char* b2 = x + 0x168;
    fn_80081BA8__FP13Unk8007FF8C_Yiii(base, idx, fn_80097288(rec, *(int*)(b2 + o2)), r);
    fn_80480A58(x);
    fn_804805B4(x);
}

extern "C" FE_OVERLAY int fn_804814DC(void* x)
{
    if (FeWp(x, 0x15C) == FeWp(x, 0x138)) {
        if (FeWp(x, 0x154)->fn_vslot86() != 0)
            return 1;
    }
    if (FeWp(x, 0x15C) == FeWp(x, 0x13C)) {
        if (FeWp(x, 0x154)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8048157C(void* x)
{
    int r = 0;
    if (FeWp(x, 0x154)->fn_vslot86() != 0 || FeWp(x, 0x154)->fn_vslot87() != 0)
        r = 1;
    return r;
}

extern "C" FE_OVERLAY int fn_804815F8(void* x)
{
    FeNode4* n = lbl_806192E0->m4;
    FeA70* a = n->m10;
    FeAFFC* b = n->m14;
    if (FeI(x, 0x134) == b->mFFC && a->m70 != -1)
        return 1;
    return 0;
}
