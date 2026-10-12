/*
 * Front-end overlay code, .frontend_codeoverlay 0x804D08D0-0x804D2AC0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_804D08D0.h"

extern "C" {
/* near-miss: 2 slots; retail loads n->m38 into r5 (we use r0) */
FE_OVERLAY void fn_804D08D0(FeS804D08D0* x)
{
    if (x->m134 != 0) {
        if (x->fn_vslot91() == 0) {
            FeNav* n = &x->m188;
            int a = ((FeWX*)x->m134)->s88(0);
            int t = n->m38;
            if (t != -1 && a == -1) {
                ((FeWX*)x)->s67(-3);
            }
            fn_804D292C(n, a);
            FeNav* m = &x->m144;
            int b = ((FeWX*)x->m134)->s88(1);
            t = m->m38;
            if (t != -1 && b == -1) {
                ((FeWX*)x)->s67(-3);
            }
            fn_804D292C(m, b);
        }
    }
}

FE_OVERLAY void fn_804D09EC(FeS804D08D0* x, int a)
{
    x->m134->fn_vslot84(a == 1, 0);
}

FE_OVERLAY void fn_804D0A34(FeS804D08D0* x, int a, int b, int c)
{
    if (a == 0 && x->m134 != 0) {
        if (b != 0) {
            ((FeWX*)x->m134)->s86(0, 0);
            if (c != 0) {
                ((FeWX*)x)->s95(0, 1);
            }
        } else {
            ((FeWX*)x->m134)->s86(1, 0);
            if (c != 0) {
                ((FeWX*)x)->s95(1, 1);
            }
        }
    }
}

FE_OVERLAY void fn_804D0DD8(FeW* x)
{
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    fn_80131F34(p, x, fn_804D0E98, 0, 0x5CDC, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_804D0E98(int a, FeS804D08D0* x)
{
    if (a != 0) {
        if (a == 1) {
            fn_804D2654(&x->m188);
            fn_804D2654(&x->m144);
            x->fn_vslot86();
            x->fn_vslot92();
            lbl_806192E0->m4->mC->m600 = a;
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_80621AEC, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

FE_OVERLAY int fn_804D0F80(FeS804D08D0* x)
{
    int p = ((FeWX*)x->m134)->s88(1);
    int q = ((FeWX*)x->m134)->s88(0);
    int a = 0;
    if (x->m1D8 == -1 || x->m1D8 == 5) {
        a = 1;
    }
    int b = 0;
    if (x->m1DC == -1 || x->m1DC == 5) {
        b = 1;
    }
    int c = 0;
    if (q == -1 || q == 5) {
        c = 1;
    }
    int d = 0;
    if (p == -1 || p == 5) {
        d = 1;
    }
    int r = 0;
    if (a != c || b != d) {
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_804D0B10(FeS804D08D0* x, int a)
{
    if (a == 1) {
        fn_8007DA8C__18Unk8007B2B0_Screenii(lbl_8061930C, x->m144.m38, -1);
    } else {
        fn_8007DA8C__18Unk8007B2B0_Screenii(lbl_8061930C, x->m188.m38, -1);
    }
}

FE_OVERLAY FeS804D1070* fn_804D1070(FeS804D1070* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80681180);
    self->m144 = 4;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m148 = 0;
    return self;
}

FE_OVERLAY void fn_804D10D8(FeS804D1070* x)
{
    fn_800ECE34(x);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F54B8, 1));
    x->m138 = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    x->m13C = (FeList*)fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
    for (int i = 0; i < 1000; i++) {
        x->m14C[i] = 0;
    }
}

FE_OVERLAY void fn_804D11BC(FeS804D1070* x)
{
    fn_800ECF18(x);
    fn_800B555C();
    int v = fn_800B57EC();
    fn_80124FA8(x->m138, x);
    fn_80125154(x->m138, 0);
    fn_80126CF4(x->m13C, 0, 0, 0, 1, 0, 0, 1, 1, 0, v ^ 1);
    fn_8012E1C4(x->m13C, 1, 0x2353);
    x->m134->fn_vslot105(1);
}

FE_OVERLAY int fn_804D1278(FeS804D1070* x)
{
    return x->m14C[x->m134->fn_vslot60()];
}

FE_OVERLAY int fn_804D1810(void) { return 0; }

FE_OVERLAY int fn_804D1818(FeS804D1070* x)
{
    x->m134->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804D1854(FeS804D1070* x)
{
    x->m134->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804D1890(FeS804D1070* x)
{
    x->m134->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804D18CC(FeS804D1070* x)
{
    x->m134->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804D1908(FeS804D1070* x)
{
    if (FeW24(x->m13C) >= 0) {
        x->m134->fn_vslot56();
    }
    return 1;
}

FE_OVERLAY int fn_804D1954(FeS804D1070* x)
{
    if (FeW24(x->m13C) >= 0) {
        x->m134->fn_vslot57();
    }
    return 1;
}

FE_OVERLAY int fn_804D19A0(FeS804D1070* x)
{
    if (FeW24(x->m13C) >= 0) {
        x->m134->fn_vslot54();
    }
    return 1;
}

FE_OVERLAY int fn_804D19EC(FeS804D1070* x)
{
    if (FeW24(x->m13C) >= 0) {
        x->m134->fn_vslot55();
    }
    return 1;
}

FE_OVERLAY void fn_804D1A38(FeW* x)
{
    FePop* p = (FePop*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    fn_80132438(p, x, 0, fn_804D1B7C, fn_804D1AFC, 0x3A61, -1, 1, lbl_805F8518);
    ((FeWY*)p)->s84(0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_804D1AFC()
{
    FePop* p = (FePop*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    ((FeWY*)p)->s85(0);
    p->m314 = 1;
}

FE_OVERLAY void fn_804D1B7C(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F3CA8, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

FE_OVERLAY void fn_804D1C00(FeS804D1070* x, FeW* w)
{
    if (w == x->m134) {
        if (x->m13C->fn_vslot87() != 0) {
            int idx = fn_804D1278(x);
            FeList* l = x->m13C;
            fn_80126CF4(l, l->m164, idx, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
    x->fn_vslot85();
}

}

/* near-miss: same length; retail stores the vptr before the m14[] member-init loop and reuses the loop counter (-1) for m34/m38; the manual vptr store comes after the member inits here (a real virtual dtor would move it but emits a local vtable) */
FE_OVERLAY FeNav::FeNav()
{
    m40 = lbl_80655E98;
    m38 = -1;
    m24 = 1;
    m3C = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m34 = -1;
    for (int i = 0; i < 5; i++) {
        m0[i] = 0;
    }
}

extern "C" {
FE_OVERLAY void fn_804D2044(FeNav* n, int a, int b, int c)
{
    for (int i = 0; i < n->m28; i++) {
        ((FeWZ*)n->m0[i])->s84(a, b, c);
    }
    for (int i = 0; i < n->m2C; i++) {
        ((FeWZ*)n->m0[i])->s84(a, b, c);
    }
}

FE_OVERLAY void fn_804D2118(FeNav* n, int a)
{
    n->m24 = a;
    fn_804D2144(n, a);
}

FE_OVERLAY void fn_804D2144(FeNav* n, int a)
{
    for (int i = 0; i < n->m28; i++) {
        n->m0[i]->fn_vslot16(a);
    }
}

FE_OVERLAY void fn_804D21B8(FeNav* n, void (FeW::*f)(void))
{
    for (int i = 0; i < n->m28; i++) {
        (n->m0[i]->*f)();
    }
    for (int i = 0; i < n->m2C; i++) {
        (n->m14[i].w->*f)();
    }
}

FE_OVERLAY FeW* fn_804D2310(FeNav* n)
{
    if (n->m34 == -1) {
        return n->m0[n->m30];
    }
    return n->m14[n->m34].w;
}

FE_OVERLAY void fn_804D233C(FeNav* n)
{
    if (FeNavSub(n)) {
        if (((FeWY*)n->m14[n->m34].w)->s102() != 0) {
            int flag = ((FeList*)fn_804D2310(n))->m150 == 1;
            int id = n->m14[n->m34].a;
            n->m34 = -1;
            fn_804D2144(n, 1);
            ((FeWY*)fn_804D2310(n))->s98();
            if (n->m3C != 0) {
                ((FeWZ*)n->m3C)->s87(id, ((FeList*)fn_804D2310(n))->m13C, flag);
                n->m3C = 0;
            }
        }
    }
    fn_804D2310(n)->fn_vslot4();
}

FE_OVERLAY int fn_804D2470(FeNav* n)
{
    int r = 0;
    if (!FeNavSub(n)) {
        if (n->m30 == n->m28 - 1) {
            r = 1;
        }
    }
    return r;
}

FE_OVERLAY int fn_804D24B0(FeNav* n)
{
    int r = 0;
    if (!FeNavSub(n)) {
        if (n->m30 == 0) {
            r = 1;
        }
    }
    return r;
}

FE_OVERLAY void fn_804D24E8(FeNav* n, FeW* w)
{
    n->m0[n->m28] = w;
    n->m28 = n->m28 + 1;
}

FE_OVERLAY void fn_804D2504(FeNav* n)
{
    if (n->m30 < n->m28 - 1) {
        n->m0[n->m30]->fn_vslot86();
        ((FeWX*)n->m0[n->m30])->s38();
        n->m30 = n->m30 + 1;
        n->m0[n->m30]->fn_vslot87();
    }
}

FE_OVERLAY void fn_804D25B0(FeNav* n)
{
    if (n->m30 > 0) {
        n->m0[n->m30]->fn_vslot85();
        ((FeWX*)n->m0[n->m30])->s38();
        n->m30 = n->m30 - 1;
        n->m0[n->m30]->fn_vslot87();
    }
}

FE_OVERLAY void fn_804D2654(FeNav* n)
{
    for (int i = n->m30; i < n->m28; i++) {
        n->m0[i]->fn_vslot86();
    }
    for (int i = 0; i < n->m28; i++) {
        ((FeWY*)n->m0[i])->s88();
    }
}

FE_OVERLAY void fn_804D2708(FeNav* n)
{
    for (int i = n->m30; i >= 0; i--) {
        n->m0[i]->fn_vslot85();
    }
    for (int i = 0; i < n->m28; i++) {
        ((FeWY*)n->m0[i])->s89();
    }
}

FE_OVERLAY void fn_804D27B4(FeNav* n, int a)
{
    if (n->m34 != -1) {
        n->m14[n->m34].w->fn_vslot101();
        n->m34 = -1;
    }
    if (a < n->m30) {
        n->m0[n->m30]->fn_vslot85();
        n->m30 = a;
        n->m0[a]->fn_vslot87();
        return;
    }
    if (a > n->m30) {
        n->m0[n->m30]->fn_vslot86();
        n->m30 = a;
        n->m0[a]->fn_vslot87();
    }
}

FE_OVERLAY void fn_804D28B4(FeNav* n)
{
    if (n->m30 != 0) {
        n->m0[n->m30]->fn_vslot85();
    }
    n->m30 = 0;
    n->m0[n->m30]->fn_vslot87();
}

FE_OVERLAY void fn_804D292C(FeNav* n, int a)
{
    n->m38 = a;
    for (int i = 0; i < n->m28; i++) {
        ((FeWY*)n->m0[i])->s99(a);
    }
    for (int i = 0; i < n->m2C; i++) {
        ((FeWY*)n->m14[i].w)->s99(a);
    }
}

FE_OVERLAY void fn_804D29F0(FeNav* n, int a, FeW* w)
{
    if (n->m2C > 1) {
        return;
    }
    n->m14[n->m2C].a = a;
    n->m14[n->m2C].w = w;
    n->m2C = n->m2C + 1;
}

FE_OVERLAY void fn_804D2A28(FeNav* n, int a, FeW* w)
{
    for (int i = 0; i < n->m2C; i++) {
        if (n->m14[i].a == a) {
            fn_804D2144(n, 0);
            n->m14[i].w->fn_vslot100();
            n->m34 = i;
            n->m3C = w;
            return;
        }
    }
}
}
