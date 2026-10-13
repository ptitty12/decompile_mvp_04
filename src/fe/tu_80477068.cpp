/*
 * Front-end overlay code, .frontend_codeoverlay 0x80477068-0x8047BB8C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
struct FeSt63C {
    char pad0[0x63C];
    int m63C;
};
extern "C" {
int fn_80084408__Fi(int v);
int strcmp(const char* a, const char* b);
char* strncpy(char* a, const char* b, unsigned n);
}
struct FeS1C0 {
    char pad0[0x1C0];
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
};
struct FePop310 {
    char pad0[0x30C];
    void* m30C;
    void* m310;
};
extern "C" {
void fn_804782DC();
void fn_80479BFC(char* x);
void fn_8047AA5C(char* x);
void fn_804794A4(char* x);
}
extern "C" void fn_800DD344__FP8Udd344_TPv(void* a, void* b);
extern "C" {
void fn_8047A46C(char* x);
void fn_8047ABBC(char* x, FeW* w, int a, int b);
}

extern "C" FE_OVERLAY void fn_80477068(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80477088(void* xv)
{
    FeW* x = (FeW*)xv;
    fn_800ECF18(x);
    int r0 = ((int (*)(void))fn_800B8144)();
    ((void (*)(int, int, int))fn_800B83F8)(r0, 1, 1);
    int g = FeI(lbl_80619948, 0x28);
    char* nb = (char*)lbl_806192E0->m4->m14;
    char* nb2 = nb + 0xE64;
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    fn_801250D8(w);
    FeI(x, 0x140) = FeI(fn_800B555C(), 0x608);
    FeI(x, 0x13C) = fn_800C203C((int)((char*)fn_800B555C() + 8));
    if (FeI(x, 0x140) == 0 && fn_8056AAE4(g, fn_800A2AE8(lbl_80619948), 0) != 0) {
        void* gm = lbl_8061930C;
        x->fn_vslot29(lbl_805F5F34);
        fn_800C8044()->fn_vslot8(0);
        x->fn_vslot29(lbl_805F5F48);
        fn_800C8044()->fn_vslot8(0);
        int t = fn_8007B8C4__18Unk8007B2B0_Screenii(gm, 0, (void*)FeI(x, 0x13C));
        FeI(x, 0x13C) = fn_80084408__Fi(t);
        FeI(x, 0x138) = fn_8056AD54(g, fn_80084114__Fi(t));
    } else {
        FeI(x, 0x138) = FeI(fn_800B555C(), 0x610);
    }
    fn_80477498(x);
    fn_80477560(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->fn_vslot29(lbl_805F5F5C)->fn_vslot8(0);
    x->fn_vslot29(lbl_805F5F80)->fn_vslot8(0);
    int r26 = FeI(nb, 0x198);
    int r27 = FeI(nb2, 0x198);
    int c1 = (int)fn_800C33D0();
    x->fn_vslot29(lbl_805F5F5C);
    fn_800C3ED4(c1, fn_800C8038(), fn_80097210(nb2, 0));
    int c2 = (int)fn_800C33D0();
    x->fn_vslot29(lbl_805F5F80);
    fn_800C3ED4(c2, fn_800C8038(), fn_80097210(nb, 0));
    x->fn_vslot29(lbl_805F5FA4);
    ((FeSubV20*)((char*)fn_800C8054() + 0x98))->s20(r27, 0);
    x->fn_vslot29(lbl_805F5FC8);
    ((FeSubV20*)((char*)fn_800C8054() + 0x98))->s20(r26, 0);
    if (fn_800B555C()->m0 == 0x20) {
        fn_800A3640(lbl_80619948);
    }
}

extern "C" FE_OVERLAY void fn_80477418(void* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
    FeNode4* n = lbl_806192E0->m4;
    FeAFFC* b = n->m14;
    FeA70* a = n->m10;
    int e = b->mFFC == FeI(x, 0x13C);
    fn_80086EC0(a, e == 0, -1);
    fn_80086EC0(a, e, FeI(x, 0x144));
}

extern "C" FE_OVERLAY void fn_80477498(FeW* x)
{
    x->fn_vslot32("TEAMSCORE", 1);
    fn_800C8044()->fn_vslot32("AWAYMETER", 1);
    fn_800C8044()->fn_vslot32("METERBAR", 1);
    FeI(x, 0x134) = fn_800C8038()->m2A;
}

extern "C" FE_OVERLAY void fn_80477540(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_80477560(void* x)
{
    fn_80477594(x);
    fn_804775D0(x);
}

extern "C" FE_OVERLAY void fn_80477594(void* x)
{
    fn_80477608(x, (char*)lbl_806192E0->m4->m14 + 0xE64, "AWAY");
}

extern "C" FE_OVERLAY void fn_804775D0(void* x)
{
    fn_80477608(x, lbl_806192E0->m4->m14, "HOME");
}

extern "C" FE_OVERLAY void fn_80477C04(void* x, void* y, void* z)
{
    char sp8[0x460];
    fn_8055AC44(sp8, FeI(x, 0x140));
    fn_800DD800(z, sp8, FeI(y, 0x198), 0);
}

extern "C" FE_OVERLAY int fn_80477C54(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80477C5C(FeW* x, int b)
{
    x->fn_vslot32(lbl_805F4EF4, 1);
    FeW* w = fn_800C8060();
    char* name = (char*)w->fn_vslot70()->fn_vslot33(5, 1) + 0xC;
    if (strcmp(name, "MANAGE") == 0) {
        void* g = lbl_8061930C;
        void* id = fn_8007F7D0__FP13Unk8007F198_BUi(g, 0);
        FeNode4* n = lbl_806192E0->m4;
        int cur = FeI(n->m14, 0x198);
        if (fn_8006A1B4__11Unk80069F0C(n) == 1) {
            if (fn_80084408__Fi(fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, fn_8007B320__18Unk8007B2B0_Screenii(g, 0, id))) == cur) {
                fn_80086EC0(n->m10, 0, b);
                fn_80086EC0(n->m10, 1, -1);
            } else {
                fn_80086EC0(n->m10, 0, -1);
                fn_80086EC0(n->m10, 1, b);
            }
        } else {
            if (fn_80075948__18Unk8007B2B0_Screeni(g, cur) == (int)id) {
                fn_80086EC0(n->m10, 0, b);
                fn_80086EC0(n->m10, 1, -1);
            } else {
                fn_80086EC0(n->m10, 0, -1);
                fn_80086EC0(n->m10, 1, b);
            }
        }
    }
    FeI(x, 0x144) = b;
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    strncpy(mp->name, name, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80477E48(FeW* x, char* y)
{
    char* s = y + 0xC;
    if (fn_8040B574(s, "PLAY") == 0 || fn_8040B574(s, "SIM") == 0 || fn_8040B574(s, "MANAGE") == 0) {
        x->fn_vslot41(0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80477EE4(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_80477F44(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80477FA4(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80478004(FeW* x)
{
    x->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_80478064(FeW* x, int a)
{
    x->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY FeScrH* fn_8047809C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676B28);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = -1;
    FeI(self, 0x1AC) = 0;
    FeI(self, 0x1B0) = 0;
    FeI(self, 0x1B4) = -1;
    FeI(self, 0x1B8) = 0;
    FeI(self, 0x1BC) = 0;
    FeI(self, 0x1C0) = 0;
    FeI(self, 0x1C4) = 0;
    FeI(self, 0x1C8) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80478118(void* p)
{
    FeS1C0* x = (FeS1C0*)p;
    fn_800ECF18(x);
    FePopup* a = fn_800B7AB8(FeGetMgr(), "FTOPBAR");
    a->fn_vslot8(0);
    a->fn_vslot16(0);
    x->m1C8 = (int)fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    FePop310* b = (FePop310*)fn_800B7A94(FeGetMgr(), "NOTIFIEDSIMPROG");
    x->m1C4 = (int)b;
    b->m30C = (void*)fn_80479A28;
    ((FePop310*)x->m1C4)->m310 = (void*)fn_804782DC;
    x->m1CC = (int)fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    ((FeW*)x)->fn_vslot32("GAMEGRID", 1);
    x->m1C0 = (int)fn_800C8060();
    fn_8047A384((FeW*)x);
    fn_8047AA5C((char*)x);
    fn_80479BFC((char*)x);
    fn_8047B15C(x);
    fn_804794A4((char*)x);
    if (lbl_80619948->m74 == 2)
        ((void (*)(void*, int))fn_800A2F9C)(lbl_80619948, 1);
}

extern "C" FE_OVERLAY void fn_80479378(int a, FeW* x)
{
    x->fn_vslot32("GAMEGRID", 1);
    fn_800C8060()->fn_vslot70()->fn_vslot32("CELL", 1);
    int r = fn_800C8060()->fn_vslot61();
    switch (a) {
    case 0:
        fn_800C2034((char*)fn_800B555C() + 8, FeI(x, 0x1D0));
        break;
    case 1:
        FeI(x, 0x13C) = FeI(x, 0x148) - FeI(x, 0x144);
        if (r == 0)
            fn_8047AE14(x, 2);
        else
            fn_8047AE14(x, 4);
        break;
    }
}

extern "C" FE_OVERLAY void fn_80479480(void* x)
{
    fn_80125BC0(FeWp(x, 0x1C8));
}

extern "C" FE_OVERLAY void fn_804794A4(char* x)
{
    int i = FeWp(x, 0x1C0)->fn_vslot60();
    fn_80124FA8(FeVp(x, 0x1C8), x);
    fn_80125154(FeVp(x, 0x1C8), 0);
    fn_801251CC(FeVp(x, 0x1C8), 0, 0x10, 2);
    int o = i * 12;
    char* b = x + 0x154;
    int k = *(int*)(b + o);
    if (k == 1) {
        fn_801251CC(FeVp(x, 0x1C8), 0, 0x10, 2);
        fn_80125084(FeVp(x, 0x1C8), 3);
    } else if (k == 2) {
        fn_80125084(FeVp(x, 0x1C8), 0);
        fn_801251CC(FeVp(x, 0x1C8), 3, 0x27D7, 3);
    } else if (k == -1) {
        fn_80125084(FeVp(x, 0x1C8), 0);
        fn_80125084(FeVp(x, 0x1C8), 3);
    }
    if (fn_804795D0(x) != 0) {
        fn_80125084(FeVp(x, 0x1C8), 1);
        fn_80125084(FeVp(x, 0x1C8), 4);
        fn_80125128(FeVp(x, 0x1C8), 1);
    }
}

extern "C" FE_OVERLAY int fn_804795D0(char* x)
{
    int i;
    int n = *(int*)(x + 0x134);
    for (i = 0; i < n; i++) {
        int o = i * 12;
        char* b = x + 0x154;
        if (*(int*)(b + o) == 1)
            return 0;
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_80479614(void* x, int a)
{
    fn_800ED310(x, a);
    if (a != 0)
        FeWp(x, 0x1C0)->fn_vslot14(1);
    else
        FeWp(x, 0x1C0)->fn_vslot14(0);
}

extern "C" FE_OVERLAY int fn_804799E8(char* x)
{
    int i;
    int n = *(int*)(x + 0x134);
    for (i = 0; i < n; i++) {
        int o = i * 12;
        char* b = x + 0x154;
        if (*(int*)(b + o) == 1)
            return i;
    }
    return -1;
}

extern "C" FE_OVERLAY void fn_80479A28(int a)
{
    if (a != 0)
        fn_8047AE14(fn_800B7A94(FeGetMgr(), "FPLAYORSIMMULTI"), 6);
}

/* near-miss: 2 slots differ (the two global loads at the top are swapped: retail loads lbl_8061930C first into r29) */
extern "C" FE_OVERLAY void fn_80479A90(char* x)
{
    FeGlobal80619948* g2 = lbl_80619948;
    int g = (int)lbl_8061930C;
    volatile int sp8 = 0;
    int best = 4;
    int ba = -1;
    int bb = -1;
    int e = 0;
    do {
        unsigned k = fn_8007FB40__FP13Unk8007F198_Ci(g, e);
        if (k < fn_8007FB2C__FP13Unk8007F198_Ci(g, sp8)) {
            int a = fn_8007FBC0__FP13Unk8007F198_Cii(g, k, sp8);
            int b = (int)fn_8007FBDC__FP13Unk8007F198_Cii(g, k, sp8);
            if ((ba == -1 || a <= ba) && (bb == -1 || b <= bb || a < ba)) {
                best = sp8;
                ba = a;
                bb = b;
            }
        }
        int c = sp8;
        int t;
        if (c > 3)
            t = c;
        else
            t = c + 1;
        sp8 = t;
        e = t;
    } while (e <= 3);
    if (fn_800A4558(g2, best) != 0)
        fn_800A3490(g2, best, 1, 1);
    if (g2->m80 != 0xD) {
        fn_800A3578(g2);
        while (fn_800A35A8(g2) == 0) {
        }
        fn_800A3670(g2);
    } else {
        char* b = x + 0x154;
        *(int*)(b + FeI(x, 0x144) * 12) = -1;
    }
    FeSt63C* s = (FeSt63C*)((char*)fn_800B555C() + 8);
    s->m63C--;
}

extern "C" FE_OVERLAY void fn_80479BFC(char* x)
{
    void* s = lbl_8061930C;
    int i = 0;
    int o = 0;
    char* a;
    char* b;
    goto test;
inc:
    o += 12;
    i++;
test:
    if (i < *(int*)(x + 0x134)) {
        a = x + 0x14C;
        b = x + 0x150;
        if (fn_8007FDA8__FP13Unk8007F198_Cii(s, *(int*)(a + o), *(int*)(b + o)) == 1) {
            fn_80479C9C(x, i);
            goto inc;
        }
        FeWp(x, 0x1C0)->fn_vslot68(i);
    }
}

extern "C" FE_OVERLAY void fn_8047A384(FeW* x)
{
    char sp8[0x40];
    char sp48[8];
    x->fn_vslot32("DATE", 1);
    FeW* a = (FeW*)fn_800C8040();
    x->fn_vslot32("DATESHADOW", 1);
    FeW* b = (FeW*)fn_800C8040();
    fn_80329FA0(sp48, fn_800A2AE8(lbl_80619948));
    fn_800DD44C(sp48, sp8, 1);
    ((FeWV28*)a)->s28(sp8);
    ((FeWV28*)b)->s28(sp8);
}

extern "C" FE_OVERLAY int fn_8047A9DC(char* x)
{
    int i;
    int c = 0;
    for (i = 0; i < *(int*)(x + 0x134); i++) {
        int o = i * 12;
        char* b = x + 0x154;
        if (*(int*)(b + o) == 1)
            c++;
    }
    return c;
}

extern "C" FE_OVERLAY void fn_8047AA20(char* x)
{
    int i;
    for (i = 0; i < 8; i++) {
        int o = i * 12;
        FeSet(x + 0x14C, o, -1);
        FeSet(x + 0x150, o, -1);
        FeSet(x + 0x154, o, 0);
    }
    FeI(x, 0x134) = 0;
}

extern "C" FE_OVERLAY void fn_8047AA5C(char* x)
{
    int i = 0;
    fn_8047A46C(x);
    FeWp(x, 0x1C0)->fn_vslot67(0, 0);
    FeWp(x, 0x1C0)->fn_vslot79(FeI(x, 0x134), 0);
    FeWp(x, 0x1C0)->fn_vslot14(1);
    for (; i < FeI(x, 0x134); i++) {
        int o = i * 12;
        char* a = x + 0x14C;
        if (*(int*)(a + o) != -1) {
            FeWp(x, 0x1C0)->fn_vslot73(i, 0);
            fn_8047ABBC(x, fn_800C8044(), *(int*)(a + o), FePick(x + 0x150, o));
        }
    }
    if (FeI(x, 0x134) <= 3) {
        FeWp(x, 0x1C0)->fn_vslot32("VSCROLL", 1);
        fn_800C8044()->fn_vslot8(0);
    }
}

extern "C" FE_OVERLAY void fn_8047ABBC(char* x, FeW* w, int a, int b)
{
    char sp8[0x18];
    char sp20[8];
    w->fn_vslot32("AWAY", 1);
    fn_8047AD30((int)x, fn_800C8044(), 1, a, b);
    w->fn_vslot32("HOME", 1);
    fn_8047AD30((int)x, fn_800C8044(), 0, a, b);
    ((void (*)(void*, ...))fn_8032A0C0)(sp20, fn_8007FBDC__FP13Unk8007F198_Cii((int)lbl_8061930C, a, b));
    fn_800DD344__FP8Udd344_TPv(sp20, sp8);
    w->fn_vslot32("TIME", 1);
    ((FeWV*)fn_800C8040())->s28(sp8);
    w->fn_vslot32("LEAGUELOGO", 1);
    ((FeSub*)((char*)fn_800C8054() + 0x98))->s6(b);
}

extern "C" FE_OVERLAY void fn_8047AD30(int u, FeW* x, int b, int c, int d)
{
    char sp8[32];
    int t = fn_8007FB98__FP13Unk8007F198_Ciii(lbl_8061930C, c, b, d);
    fn_8007B924__18Unk8007B2B0_ScreeniiPc(lbl_8061930C, 2, t, sp8);
    x->fn_vslot32("TEAM", 1);
    ((FeWV30*)fn_800C8058())->s30(sp8);
    x->fn_vslot32("LARGELOGOS", 1);
    ((FeSubV20*)((char*)fn_800C8054() + 0x98))->s20(t, 0);
}

extern "C" FE_OVERLAY void fn_8047AE14(void* x, int v)
{
    FeI(x, 0x1AC) = v;
}

extern "C" FE_OVERLAY int fn_8047AE1C(void* x)
{
    FeWp(x, 0x1C0)->fn_vslot70();
    fn_800C8044()->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047AE9C(void* x)
{
    FeWp(x, 0x1C0)->fn_vslot70();
    fn_800C8044()->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047AF1C(void* x)
{
    FeWp(x, 0x1C0)->fn_vslot70();
    fn_800C8044()->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047AF9C(void* x)
{
    FeWp(x, 0x1C0)->fn_vslot70();
    fn_800C8044()->fn_vslot32("CELL", 1);
    fn_800C8060()->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_8047B01C(void* x)
{
    FeI(x, 0x1B8) = FeWp(x, 0x1C0)->fn_vslot60();
}

extern "C" FE_OVERLAY int fn_8047B064(FeW* x, int a)
{
    int idx = FeWp(x, 0x1C0)->fn_vslot60();
    FeWp(x, 0x1C0)->fn_vslot70();
    fn_800C8044()->fn_vslot32("CELL", 1);
    if (a != (int)fn_800C8060()) {
        fn_8047B15C(x);
        return 0;
    }
    int o = idx * 12;
    char* b = (char*)x + 0x154;
    if (*(int*)(b + o) == 1 && FeI(x, 0x1B8) == idx) {
        x->fn_vslot67(2, 0);
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047B9AC(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() > 0) {
        FeWp(x, 0x1C0)->fn_vslot50();
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047BA20(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() > 0) {
        FeWp(x, 0x1C0)->fn_vslot51();
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047BA94(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() < FeI(x, 0x134) - 1) {
        FeWp(x, 0x1C0)->fn_vslot52();
        fn_8047B15C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8047BB10(void* x)
{
    if (FeWp(x, 0x1C0)->fn_vslot60() < FeI(x, 0x134) - 1) {
        FeWp(x, 0x1C0)->fn_vslot53();
        fn_8047B15C(x);
    }
    return 1;
}
