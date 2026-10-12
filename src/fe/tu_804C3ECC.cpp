/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C3ECC-0x804C713C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"
extern char lbl_805F8004[];
struct FeS38 {
    char pad0[0x38];
    int m38;
    int m3C;
};
extern "C" void fn_8013484C(void);
extern "C" void fn_80134854(int a, void* x);
extern "C" int fn_8040ABA0(void);
extern "C" void fn_804C5D5C(FeScrN* x);
extern "C" void fn_804C60F4(FeScrN* x, int a);
extern "C" void fn_80539DB4(void* l, int id);
extern "C" void fn_8053A044(void* l, int id, int f);
struct FeS588 {
    char pad0[0x588];
    int m588;
};
struct FeS8b {
    char pad0[0x2C];
    int m2C;
    int m30;
};
extern char lbl_805F7FEC[];
extern char lbl_805F57F8[];
extern char lbl_805F7FFC[];
extern "C" void fn_800A2910(FeGlobal80619948* g);
extern "C" void fn_804089B4(char* dst, const char* fmt, ...);
struct FeWV30 : Unk800C7B40_Data {
    virtual ~FeWV30();
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
    virtual void s29();
    virtual void s30(const char* a);
};
extern char lbl_805F4ECC[];
extern char lbl_805F7FC0[];
extern "C" FeW* fn_800C8044(FeW* w);
extern "C" void fn_800E4FE4__FP3UiSi(void* p, int a);
extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* g, int id);
typedef void (*FeCbF)(int, void*);
extern "C" int fn_800DE538__Fiiii(char* out, int a, int b, int c);
extern "C" void fn_804031F8(char* dst, const char* fmt, const char* arg);
extern "C" void fn_801321D4(FeW* o, void* self, FeCbF cb, int a, void* b, int c, int d, int e, const char* s1, const char* s2,
                            const char* s3, int f, int g, int h);
extern "C" void fn_804C6228(FeScrN* x);
extern "C" void fn_804C63B0(FeScrN* x);
extern "C" void fn_804C65D0(FeScrN* x);
extern "C" void fn_804C66E8(FeScrN* x);
extern "C" void fn_804C67D8(FeScrN* x);
struct FeG40 {
    char pad0[0x40];
    int m40;
};
extern "C" int fn_8007B380__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" int fn_8007C1D0__18Unk8007B2B0_ScreeniiiP16Unk8007B2B0_Pair(void* g, int a, int b, int c, void* d, void* e, void* f);
extern "C" void fn_80564ABC(int h, int s, int a, int c, void* d, void* e, int f);
extern "C" void fn_804C6D00(FeScrN* x, FeW* w, int a, int b, int c);
extern "C" FeW* fn_800C8060(FeW* w);
extern char lbl_805F4450[];
extern char lbl_805F57EC[];
extern "C" void fn_800E4B70__Fv(void);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, int a);
extern "C" void fn_8007C328__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" void fn_805296B4(void);
extern char lbl_805F7FC8[];
extern "C" void fn_804C4BB4(int a, void* x);

extern "C" void fn_804C4D18(FeScrN* x);
extern "C" void fn_804C4FA8(FeScrN* x);
extern "C" void fn_804C4E30(FeScrN* x);
extern "C" void fn_804C6918(FeScrN* x, int v);
extern "C" void fn_804C5F98(FeScrN* x);
extern "C" void fn_804C506C(FeScrN* x);
extern "C" void fn_804A77AC(FeW* w, int v);
extern "C" void fn_804C60F4(FeScrN* x, int v);
extern "C" void fn_804C6F08(FeScrN* x);
extern "C" void fn_804C4520(FeScrN* x);
extern "C" int fn_804C4608(FeScrN* x);
extern "C" int fn_804C4644(FeScrN* x);
extern "C" int fn_804C4680(FeScrN* x);
extern "C" int fn_804C46BC(FeScrN* x);
extern "C" int fn_804C474C(void);
extern "C" int fn_804C47A8(void);
extern "C" int fn_804C47B0(FeScrN* x);
extern "C" int fn_804C47F0(FeScrN* x, int a);
extern "C" int fn_804C482C(FeScrN* x);
extern "C" int fn_804C486C(FeScrN* x);
extern "C" void fn_804C4958(FeScrN* x);
extern "C" void fn_804C4B30(FeScrN* x, FeScrN* y);
extern "C" void fn_804C686C(FeScrN* x, int a);
extern "C" int fn_804C4DF4(FeScrN* x);
extern "C" void fn_804C6AA4(FeScrN* x);
extern "C" void fn_804C6368(FeScrN* x, int a);
extern "C" int fn_804C46F8(FeScrN* x);
extern "C" int fn_804C4754(FeScrN* x);
extern "C" void fn_804C68B4(FeScrN* x, int v);
extern "C" int fn_804C60A4(FeScrN* x);
extern "C" void fn_804C4B5C(int a, FeScrN* x);
extern "C" void fn_804C61B4(FeScrN* x, FeW* w);

extern "C" FE_OVERLAY void fn_804C4520(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804C4548(FeScrN* x, int k)
{
    if ((int)x->m144 == fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0) || x->m138 == 0) {
        switch (k) {
        case 0:
            fn_804C6228(x);
            break;
        case 1:
            fn_804C63B0(x);
            break;
        case 2:
            fn_804C65D0(x);
            break;
        case 3:
            fn_804C66E8(x);
            break;
        case 4:
            fn_804C67D8(x);
            break;
        }
    }
}

extern "C" FE_OVERLAY int fn_804C4608(FeScrN* x)
{
    x->m154->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C4644(FeScrN* x)
{
    x->m154->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C4680(FeScrN* x)
{
    x->m154->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C46BC(FeScrN* x)
{
    x->m154->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C46F8(FeScrN* x)
{
    if (x->m154 != x->m14C) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    fn_804C61B4(x, x->m14C);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C474C(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C4754(FeScrN* x)
{
    if (x->m154 != x->m150) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    fn_804C61B4(x, x->m150);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47A8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47B0(FeScrN* x)
{
    x->m158->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47F0(FeScrN* x, int a)
{
    x->m158->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C482C(FeScrN* x)
{
    x->m158->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C486C(FeScrN* x)
{
    x->m158->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_804C48A8(FeScrN* x, int a)
{
    if (a == (int)x->m14C) {
        fn_804C61B4(x, (FeW*)a);
    } else if (a == (int)x->m150) {
        fn_804C61B4(x, (FeW*)a);
    } else {
        if (a == (int)fn_800C8060(x->fn_vslot32(lbl_805F57EC, 1))) {
            x->fn_vslot67(4, -1);
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C4958(FeScrN* x)
{
    fn_804C6AA4(x);
}

extern "C" FE_OVERLAY void fn_804C4978(FeScrN* x)
{
    void* g0 = lbl_8061930C;
    if ((int)x->m138 != 0 && ((int)x->m144 != fn_8007F7D0__FP13Unk8007F198_BUi(g0, 0) || (int)x->m134 != 0)
        && (int)x->m13C == 0) {
        int arr[10];
        int first = 0;
        int allfree = 1;
        volatile int sp30 = 0;
        int n = 0;
        int e = 0;
        do {
            int a = fn_8008FE14(e);
            if (fn_8007B380__18Unk8007B2B0_Screenii(lbl_8061930C, a, (int)x->m144) == 0) {
                int c = sp30;
                if (c == 0) {
                    allfree = 0;
                    first = n;
                }
                arr[n] = c;
                n++;
            }
            int d = sp30;
            int t;
            if (d > 9)
                t = d;
            else
                t = d + 1;
            sp30 = t;
            e = t;
        } while (e <= 9);
        int sel;
        if (allfree != 0) {
            if (n > 0)
                sel = fn_8040ABA0() % n;
            else
                sel = 0;
        } else {
            sel = first;
        }
        char* l = (char*)x + 0x190;
        ((FeSub*)((char*)x->m15C + 0xDC))->s6(arr[sel]);
        fn_804C4E30(x);
        fn_804C4FA8(x);
        int pick;
        unsigned c1 = *(unsigned*)(l + 4);
        if (c1 > 4) goto rnd;
        if (c1 != 0) {
        rnd:
            unsigned r = fn_8040ABA0();
            unsigned c2 = *(unsigned*)(l + 4);
            if (c2 <= 4)
                pick = r % c2;
            else
                pick = r & 3;
        } else {
            pick = 0;
        }
        fn_804C60F4(x, FeAt((char*)x->m190, pick));
        fn_804C6F08(x);
    }
    fn_804C5D5C(x);
}

extern "C" FE_OVERLAY void fn_804C4B30(FeScrN* x, FeScrN* y)
{
    if (x != 0) {
        fn_804C4D18(y);
    }
}

extern "C" FE_OVERLAY void fn_804C4B5C(int a, FeScrN* x)
{
    if (a != 0) {
        fn_804C60F4(x, fn_804C60A4(x));
        if (x->m138 != 0) {
            fn_804C6F08(x);
        }
    }
}

extern "C" FE_OVERLAY void fn_804C4BB4(int a, void* v)
{
    FeScrN* x = (FeScrN*)v;
    if (a != 0) {
        x->m134 = (FeW*)1;
        x->fn_vslot16(0);
        x->m164->fn_vslot16(0);
        x->m164->fn_vslot8(0);
        x->fn_vslot32(lbl_805F7FC8, 1)->fn_vslot8(0);
    }
}

extern "C" FE_OVERLAY void fn_804C4C88(int a, void* x)
{
    if (a != 0) {
        fn_800E4B70__Fv();
        FeMsg m;
        FeMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
    }
}

extern "C" FE_OVERLAY void fn_804C4D18(FeScrN* x)
{
    if (x->m18C != 0 && fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0) == (int)x->m144) {
        void* g = lbl_8061930C;
        int k = (int)x->m18C;
        fn_8007C328__18Unk8007B2B0_Screenii(g, k, fn_8007F7D0__FP13Unk8007F198_BUi(g, 0));
        fn_804C4E30(x);
        fn_804C4FA8(x);
        fn_804C5F98(x);
    }
}

extern "C" FE_OVERLAY void fn_804C4DA4(FeScrN* x, int v)
{
    fn_800ED310(x, v);
    x->m154->fn_vslot14(v);
}

extern "C" FE_OVERLAY int fn_804C4DF4(FeScrN* x)
{
    return ((FeSub*)((char*)x->m15C + 0xDC))->s5();
}

extern "C" FE_OVERLAY void fn_804C4E30(FeScrN* x)
{
    char* l = (char*)x + 0x190;
    int id = fn_8008FD78(fn_804C4DF4(x));
    fn_80539DB4(l, id);
    fn_8053A044(l, id, 1);
    if (!(FeW24(x) & 0x40000000)) {
        x->m14C->fn_vslot8(0);
    } else {
        unsigned i = 0;
        x->m14C->fn_vslot8(1);
        x->m14C->fn_vslot79(*(int*)(l + 4), 0);
        x->m14C->fn_vslot68(0);
        for (; i < *(unsigned*)(l + 4); i++) {
            fn_804C6D00(x, x->m14C, i, FeAt((char*)x->m190, i), id);
        }
        x->m14C->fn_vslot14(1);
        if (x->m154 != x->m14C) {
            x->m14C->fn_vslot14(0);
        }
    }
}

extern "C" FE_OVERLAY void fn_804C4FA8(FeScrN* x)
{
    int a = fn_8008FE14(fn_804C4DF4(x));
    int b = fn_8008FD78(fn_804C4DF4(x));
    int k = fn_8007B380__18Unk8007B2B0_Screenii(lbl_8061930C, a, (int)x->m144);
    x->m18C = (FeW*)k;
    fn_804C6D00(x, x->m150, 0, k, b);
    x->m150->fn_vslot14(1);
    if (x->m154 != x->m150) {
        x->m150->fn_vslot14(0);
    }
}

extern "C" FE_OVERLAY void fn_804C5F98(FeScrN* x)
{
    char buf[0x80];
    int cnt = 0;
    volatile int sp88 = 0;
    int e = 0;
    do {
        int a = fn_8008FE14(e);
        void* g = lbl_8061930C;
        if (fn_8007B380__18Unk8007B2B0_Screenii(g, a, fn_8007F7D0__FP13Unk8007F198_BUi(g, 0)) != 0) {
            cnt++;
        }
        int c = sp88;
        int t;
        if (c > 9)
            t = c;
        else
            t = c + 1;
        sp88 = t;
        e = t;
    } while (e <= 9);
    fn_804089B4(buf, lbl_805F4ECC, cnt);
    ((FeWV30*)x->m16C)->s30(buf);
    FeW* w = fn_800C8044(x->fn_vslot32(lbl_805F7FC0, 1));
    fn_800E4FE4__FP3UiSi(w, fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0));
}

extern "C" FE_OVERLAY int fn_804C60A4(FeScrN* x)
{
    return FeAt((char*)x->m190, x->m14C->fn_vslot60());
}

extern "C" FE_OVERLAY void fn_804C60F4(FeScrN* x, int a)
{
    if (a != 0 && x->m138 != 0) {
        int p[2];
        int s = (int)x->m144;
        int h = ((FeG40*)lbl_80619948)->m40;
        fn_80564ABC(h, s, a, fn_804C4DF4(x), &p[0], &p[1], 1);
        int s2 = (int)x->m144;
        void* g = lbl_8061930C;
        fn_8007C1D0__18Unk8007B2B0_ScreeniiiP16Unk8007B2B0_Pair(g, a, s2, fn_804C4DF4(x), &p[0], &p[0], &p[0]);
        fn_804C4E30(x);
        fn_804C4FA8(x);
        fn_804C5F98(x);
    }
}

extern "C" FE_OVERLAY void fn_804C61B4(FeScrN* x, FeW* w)
{
    x->m154->fn_vslot14(0);
    x->m154 = w;
    w->fn_vslot14(1);
    fn_804C6AA4(x);
}

extern "C" FE_OVERLAY void fn_804C6228(FeScrN* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    if (x->m138 != 0) {
        fn_800A2910(lbl_80619948);
        if (((FeS588*)fn_800B555C())->m588 != 0) {
            fn_8040B830(p->name, lbl_805F7FEC, 15);
            p->name[15] = 0;
        } else {
            fn_8040B830(p->name, lbl_805F57F8, 15);
            p->name[15] = 0;
        }
        fn_800B7B4C(FeGetMgr(), &m, x);
        return;
    }
    FeS8b* s = (FeS8b*)((char*)fn_800B555C() + 8);
    s->m2C = fn_804C60A4(x);
    FeS8b* s2 = (FeS8b*)((char*)fn_800B555C() + 8);
    s2->m30 = fn_804C4DF4(x);
    fn_8040B830(p->name, lbl_805F7FFC, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

extern "C" FE_OVERLAY void fn_804C6368(FeScrN* x, int a)
{
    if (a == (int)x->m158) {
        fn_804C4FA8(x);
        fn_804C4E30(x);
        fn_804C6AA4(x);
    }
}

extern "C" FE_OVERLAY void fn_804C63B0(FeScrN* x)
{
    FeMsg m;
    int r = 0;
    if ((int)x->m138 == 0) {
        volatile int sp30 = 0;
        int e = 0;
        do {
            int a = fn_8008FE14(e);
            void* g = lbl_8061930C;
            if (fn_8007B380__18Unk8007B2B0_Screenii(g, a, fn_8007F7D0__FP13Unk8007F198_BUi(g, 0)) == 0) {
                r = 1;
                break;
            }
            int c = sp30;
            int t;
            if (c > 9)
                t = c;
            else
                t = c + 1;
            sp30 = t;
            e = t;
        } while (e <= 9);
    }
    if ((int)x->m138 == 0) {
        if (r != 0)
            goto popA;
        goto msg;
    }
    if ((int)x->m134 != 0 && (int)x->m13C == 0) {
    popA:
        fn_80131F34(x->m160, x, (void (*)(int, void*))fn_80134854, (int)fn_8013484C, 0x5D94, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        x->m160->fn_vslot86();
        return;
    }
    if ((int)x->m138 != 0) {
        fn_80131F34(x->m160, x, (void (*)(int, void*))fn_804C4C88, 0, 0x4D9C, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        x->m160->fn_vslot86();
        return;
    }
msg:
    ((FeS38*)fn_800B555C())->m38 = 0;
    FeMsg* p = &m;
    fn_8035682C(p);
    if (((FeS38*)fn_800B555C())->m3C != 0) {
        fn_8040B830(p->name, lbl_805F8004, 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
}

extern "C" FE_OVERLAY void fn_804C65D0(FeScrN* x)
{
    char b20[0x7D0];
    char b7F0[0x190];
    int k = FeAt((char*)x->m190, x->m14C->fn_vslot60());
    fn_800DE538__Fiiii(b7F0, fn_8008FD78(fn_804C4DF4(x)), k, 1);
    fn_804031F8(b20, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x38D1), b7F0);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m160, x, (FeCbF)fn_804C4B5C, (int)fn_805296B4, b20, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m160->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804C66E8(FeScrN* x)
{
    char b20[0x7D0];
    char b7F0[0x190];
    int k = (int)x->m18C;
    fn_800DE538__Fiiii(b7F0, fn_8008FD78(fn_804C4DF4(x)), k, 1);
    fn_804031F8(b20, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1A47), b7F0);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m160, x, (FeCbF)fn_804C4B30, (int)fn_805296B4, b20, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m160->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804C67D8(FeScrN* x)
{
    fn_80131F34(x->m160, x, fn_804C4BB4, (int)fn_805296B4, 0x5CFE, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    x->m160->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804C686C(FeScrN* x, int a)
{
    fn_804C68B4(x, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, a));
}

extern "C" FE_OVERLAY void fn_804C68B4(FeScrN* x, int v)
{
    ((FeSubV*)((char*)x->m188 + 0x98))->s20(v, 0);
    fn_804A77AC(x->m168, v);
    fn_804C4FA8(x);
}

extern "C" FE_OVERLAY void fn_804C6918(FeScrN* x, int a)
{
    x->m174->fn_vslot8(0);
    x->m178->fn_vslot8(0);
    x->m17C->fn_vslot8(0);
    x->m180->fn_vslot8(0);
    x->m184->fn_vslot8(0);
    if ((x->m154 == x->m14C && fn_804C60A4(x) != 0) || x->m18C != 0) {
        switch (a) {
        case 0:
        case 1:
            x->m17C->fn_vslot8(1);
            break;
        case 4:
        case 5:
            x->m174->fn_vslot8(1);
            break;
        case 2:
        case 3:
            x->m178->fn_vslot8(1);
            break;
        case 6:
        case 7:
        case 8:
            x->m180->fn_vslot8(1);
            break;
        case 9:
            x->m184->fn_vslot8(1);
            break;
        }
    }
}

extern "C" FE_OVERLAY void fn_804C6AA4(FeScrN* x)
{
    fn_804C6918(x, fn_804C4DF4(x));
    fn_804C5F98(x);
    fn_804C506C(x);
}
