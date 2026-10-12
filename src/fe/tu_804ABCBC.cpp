/*
 * Front-end overlay code, .frontend_codeoverlay 0x804ABCBC-0x804AECD0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"
struct Fe4164R {
    char pad0[0xC];
    unsigned p0 : 2;
    unsigned id : 6;
    unsigned rest : 24;
    unsigned short m10;
};
class Fe4164L {
public:
    char pad0[4];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6(Fe4164R* r);
    virtual int s7(Fe4164R* r);
};
struct Fe4164Mgr {
    char pad0[0x1D4];
    int m1D4;
};
extern "C" int fn_805825BC(Fe4164L* l, Fe4164R* r, int* a, int* b);
extern "C" Fe4164Mgr* fn_8007FE04__FP13Unk8007F198_D(void* g);
extern "C" int fn_800A4EA4(FeGame* g);
int fn_800E4FDC();

struct FeArrL { char* m0; int m4; int m8; int mC; const void* m10; int m14; };
extern const char lbl_80673DD8[];
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A4C8[];
extern "C" void fn_8040074C(void* p, int n);
extern "C" FE_OVERLAY int fn_804ABCBC(FeSc1* x)
{
    x->m138->v56();
    x->m140 = (x->m140 + 3) % 4;
    fn_804AC564(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804ABD30(FeScr* x)
{
    x->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804ABD6C(FeSc1* x)
{
    x->m138->v54();
    x->m140 = (x->m140 + 1) % 4;
    fn_804AC564(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804ABDE0(FeScr* x)
{
    x->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804AC060(int a, FeSc1* x)
{
    switch (a) {
    case 0:
        fn_804ABF48(x, 0);
        break;
    case 1:
        fn_804ABF48(x, 1);
        break;
    case 2:
        break;
    }
}

extern "C" FE_OVERLAY void fn_804AC0AC(int a, FeSc1* x)
{
    if (a != 0) {
        if (a == 1)
            fn_804AC114(x);
    }
}

extern "C" FE_OVERLAY void fn_804AC0E0(int a, FeSc1* x)
{
    if (a != 0) {
        if (a == 1)
            fn_804AC1C0(x);
    }
}

extern "C" FE_OVERLAY void fn_804AC114(FeSc1* x)
{
    int idx = ((FeObjI*)x->m134)->v60();
    int id = x->m144[idx];
    if (idx > 0) {
        if (((FeObjI*)x->m134)->v59() - 1 > 0)
            x->m1C8 = idx - 1;
    }
    fn_8058200C(((FeScrMgrView*)lbl_8061930C)->m2C, id);
    fn_804AC564(x);
    fn_804ACA20(x);
}

extern "C" FE_OVERLAY void fn_804AC1C0(FeSc1* x)
{
    FeObj* list = x->m134;
    Unk8007B2B0_Screen* mgr = lbl_8061930C;
    FeGame* game = lbl_80619948;
    int h = ((FeScrMgrView*)mgr)->m2C;
    int n = ((FeObjI*)list)->v59();
    int lvl = fn_800A2AE8(game);
    for (int i = 0; i < n; i++) {
        int id = x->m144[i];
        if (fn_8008007C((Unk8007FF8C_G*)mgr, id)->m10 < lvl)
            fn_8058200C(h, id);
    }
    fn_804AC564(x);
    fn_804ACA20(x);
}

extern "C" FE_OVERLAY void fn_804AC280(FeSc1* x)
{
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_804AC348, 0, 0, 3, -1, 1, 0x1D0F, 0x1D0E, 0x26DF, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AC348(int a, FeSc1* x)
{
    switch (a) {
    case 0: {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "REQUEST", 15);
        p->name[15] = 0;
        ((FeObj1*)x)->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
        break;
    }
    case 1: {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "FREQUENCY", 15);
        p->name[15] = 0;
        ((FeObj1*)x)->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
        break;
    }
    case 2:
        break;
    }
}

extern "C" FE_OVERLAY void fn_804AC478(FeSc1* x, int a)
{
    switch (a) {
    case 0: {
        FeBase8* b = (FeBase8*)((char*)fn_800B555C() + 8);
        UiMsg m;
        UiMsg* p = &m;
        fn_800C2034(b, b->m38);
        b->m70 = a;
        b->m6C = a;
        fn_800C2088(b, 1, x->m1C4);
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = a;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
    case 2:
        fn_804ABE1C(x);
        break;
    case 3:
        fn_804AC280(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804ACAFC(FeSc1* unused, int k)
{
    int r = 0;
    switch (k) {
    case 0:
        r = 0x45BE;
        break;
    case 1:
        r = 0x1F9B;
        break;
    case 2:
        r = 0x1D59;
        break;
    case 3:
        r = 0x45BF;
        break;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804AD830(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804AE128(int unused, int a)
{
    char buf[100];
    lbl_8061930C->fn_8007BC64(0, a, buf);
    fn_800736EC(buf);
}

extern "C" FE_OVERLAY void fn_804AE300(int a, FeObj* w)
{
    if (a != 0) {
        if (a == 1) {
            ((FeSt68*)fn_800B555C())->m68 = a;
            ((FeObj1*)w)->v80(1);
            ((FeObj2*)w)->v67(0, 0);
        }
    }
}

extern "C" FE_OVERLAY void fn_804AE47C(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_804AE300, 0, 0x1D3E, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE660(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_805291C8, 0, 0x1CED, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE71C(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_805291C8, 0, 0x1CEE, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE920(FeSc1* x)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, x, (FeCb)fn_805291C8, 0, 0x1CEA, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->v86();
}

/* void call: a call that only clobbers r3 leaves the later `addi r3,r1,8` output-dependent on the `mr r3` argument move, which then wins the sched2 tie */
extern "C" FE_OVERLAY void fn_804ACA20(FeSc1* x)
{
    char buf[0x100];
    char fmt[0x20];
    char out[0x20];
    int i = 0;
    do {
        int p = (int)fn_800E4874(i);
        fn_80403144(buf, fn_80090880(lbl_8061977C, fn_804ACAFC(x, i)));
        if (p != 0) {
            fn_804031BC(fmt, "(%d)");
            ((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, p);
            fn_800DFF0C(buf, out);
        }
        ((FeObjS43*)x->m138)->v43(0, i, buf, 5);
        i++;
    } while (i <= 3);
}

extern "C" FE_OVERLAY void fn_804AE37C(FeSc1* x, int a)
{
    char fmtd[0x200];
    char name[0x200];
    Unk80090880* t = lbl_8061977C;
    fn_800DE440(name, a, 0);
    fn_80403DE4(fmtd, fn_80090880(t, 0x1CF0), name);
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_801321D4(p, x, (FeCb)fn_805291C8, 0, fmtd, 1, -1, 1, fn_80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 0, 0);
    p->v86();
}

struct Unk80360AB4 {
    int m0, m4, m8, mC, m10;
    Unk80360AB4(const Unk80360AB4& o);
    ~Unk80360AB4() {}
    virtual void vfn();
};
struct FeMsgB8 {
    char pad0[0x3C];
    Unk80360AB4 m3C;
    int m54;
    int m58;
    int m5C;
    int m60;
    void Set(Unk80360AB4 s, int id, int h, int i)
    {
        m3C = s;
        m54 = id;
        m58 = h;
        m5C = i;
    }
};
extern "C" FE_OVERLAY void* fn_804ACD0C(FeSc1* x, int i)
{
    FeLvlRec* rec = fn_8008007C((Unk8007FF8C_G*)lbl_8061930C, x->m144[i]);
    FeMsgB8* b = (FeMsgB8*)((char*)fn_800B555C() + 8);
    b->Set(*(Unk80360AB4*)rec, x->m144[i], x->m140, i);
    FeMsgB8* c = (FeMsgB8*)((char*)fn_800B555C() + 8);
    c->m60 = 0;
    return c;
}

extern "C" FE_OVERLAY int fn_804ACDDC(FeSc1* x)
{
    int idx = ((FeObjI*)x->m134)->v60();
    if (idx >= 0 && fn_800E4874(FI(x, 0x140)) != 0) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "EMAILITEM", 15);
        p->name[15] = 0;
        fn_804ACD0C(x, idx);
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804ACEAC(FeSc1* x, FeObj* w, int u, int c, int d)
{
    if ((int)w == FI(x, 0x134) && fn_800E4874(FI(x, 0x140)) != 0) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "EMAILITEM", 15);
        p->name[15] = 0;
        fn_804ACD0C(x, c);
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
    } else {
        if ((int)w != FI(x, 0x138))
            return 0;
        FeObj* r = (FeObj*)((FeObjP2*)w)->v73(0, FI(x, 0x140));
        ((FeObj1*)r)->v14(0);
        FI(x, 0x140) = d;
        fn_804AC564(x);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_804AE53C(FeSc1* x, int a, int b)
{
    char fmtd[0x200];
    char name[0x200];
    Unk80090880* t = lbl_8061977C;
    fn_800DE440(name, b, 0);
    int s = fn_800E190C(a);
    fn_8040321C(fmtd, fn_80090880(t, 0x1CEF), name, (char*)fn_80090880(t, s));
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_801321D4(p, x, (FeCb)fn_805291C8, 0, fmtd, 1, -1, 1, fn_80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE7D8(FeSc1* x, int a, int b, int c)
{
    char fmtd[0x200];
    char name[0x200];
    Unk80090880* t = lbl_8061977C;
    fn_800DE440(name, a, 0);
    int s1 = fn_80083F6C(b);
    int s2 = fn_80083F6C(c);
    fn_80403DE4(fmtd, fn_80090880(t, 0x1CEC), name, fn_80090880(t, s1), fn_80090880(t, s2));
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_801321D4(p, x, (FeCb)fn_805291C8, 0, fmtd, 1, -1, 1, fn_80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AE9DC(FeSc1* x, int a)
{
    char fmtd[0x200];
    char name[0x200];
    Unk80090880* t = lbl_8061977C;
    fn_800DE440(name, a, 0);
    fn_80403DE4(fmtd, fn_80090880(t, 0x1CE8), name);
    int k = fn_80077BC4(lbl_8061930C, a);
    if (k == 0) {
        fn_800DFF0C(fmtd, (char*)fn_80090880(t, 0x1CEA));
    } else {
        int j = lbl_8061930C->fn_80078A38(k);
        if (j == 0) {
            fn_80403DE4(name, fn_80090880(t, 0x1CE9), fn_80090880(t, fn_800E18D4(k)));
        } else {
            int q = lbl_8061930C->fn_80075948(k);
            int s = lbl_8061930C->fn_8007B320(0, q);
            fn_80403DE4(name, fn_80090880(t, 0x1CEB), fn_80090880(t, fn_800E190C(s)), fn_80090880(t, fn_80083F6C(j)), fn_80090880(t, fn_800E190C(k)));
        }
        fn_800DFF0C(fmtd, name);
    }
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_801321D4(p, x, (FeCb)fn_805291C8, 0, fmtd, 1, -1, 1, fn_80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804AD040(FeSc1* x)
{
    fn_800ECE34(x);
    x->m138 = fn_800B7AB8(UiGetMsgMgr(), "PLAYERINFOBAR");
}

extern "C" FE_OVERLAY void fn_804ABF48(FeSc1* x, int a)
{
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    if (a != 0)
        fn_80131F34(p, x, (FeCb)fn_804AC0E0, 0, 0x1D08, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    else
        fn_80131F34(p, x, (FeCb)fn_804AC0AC, 0, 0x1D3E, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804ABE1C(FeSc1* x)
{
    char buf[0x190];
    int s1 = fn_804ACAFC(x, FI(x, 0x140));
    Unk80090880* t = lbl_8061977C;
    fn_80403DE4(buf, fn_80090880(t, 0x1D10), fn_80090880(t, s1));
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    const char* a = fn_80090880(t, 0x1D11);
    const char* b = fn_80090880(t, 0x1D12);
    fn_801321D4(p, x, (FeCb)fn_804AC060, 0, buf, 3, -1, 1, a, b, fn_80090880(t, 0x26DF), 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY FeRaw* fn_804ACFC8(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80674080;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = -1;
    FeSub14* s = (FeSub14*)((char*)self + 0x144);
    s->m14 = lbl_806841F8;
    fn_8052DD58(s);
    return self;
}

extern "C" FE_OVERLAY FeRaw* fn_804AEC04(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeArrL* s = (FeArrL*)((char*)self + 0x19C);
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80673DD8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    s->m10 = lbl_8064B298;
    s->m0 = (char*)self + 0x1B4;
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
    return self;
}

extern "C" FE_OVERLAY void fn_804AE164(FeScr* x, Fe4164R* r)
{
    Unk8007B2B0_Screen** sp = &lbl_8061930C;
    FeGame** gp = &lbl_80619948;
    Fe4164L* lst = ((Fe4164L * (*)(int, int)) fn_8058211C)(((FeScrMgrView*)*sp)->m2C, r->id);
    int a = 0;
    int b = 0;
    if (fn_805825BC(lst, r, &a, &b) != 0) {
        int t = lst->s7(r);
        if (t == 2) {
            int g = fn_800A2AE8(*gp);
            if (r->m10 != g)
                return;
        } else if (t == 3) {
            if (fn_8007FE04__FP13Unk8007F198_D(*sp)->m1D4 == 1 && fn_800A4EA4(*gp) != 0)
                return;
        } else if (t == 4) {
            if (fn_800A2E90(*gp) == 0)
                return;
        }
        if (fn_800E4FDC() == 0) {
            int tbl[13] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
            if (tbl[lst->s6(r)] != 0)
                return;
        }
        fn_801251CC(x->m134, 0, a, 2);
    }
}
