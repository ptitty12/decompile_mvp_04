/*
 * Front-end overlay code, .frontend_codeoverlay 0x80459228-0x8045B134 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY int fn_80459228(FeScrA* x)
{
    FePair p1 = fn_8045A9C0(x, x->m14C);
    if (p1.a != 0) {
        int idx = x->m14C;
        if (idx == 1) {
            if (x->m138->fn_vslot87() == 0) {
                FePair p2 = fn_8045A9C0(x, x->m14C);
                FeList* l = x->m138;
                fn_80126CF4(l, l->m164, p2.a, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m138->fn_vslot84(1, 0);
            } else {
                FeList* l = x->m138;
                fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m13C[1]->fn_vslot14(1);
            }
        } else if (idx == 0) {
            if (x->m138->fn_vslot86() == 0) {
                FePair p3 = fn_8045A9C0(x, x->m14C);
                FeList* l = x->m138;
                fn_80126CF4(l, p3.a, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m138->fn_vslot84(0, 0);
            } else {
                FeList* l = x->m138;
                fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m13C[0]->fn_vslot16(1);
            }
        }
        fn_80459FEC(x);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
    }
    return 1;
}

FE_OVERLAY int fn_80459484(FeScrA* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9B);
    x->m14C = fn_8045A9AC(x, x->m14C);
    fn_80458B58(x, -1);
    return 1;
}

FE_OVERLAY int fn_804594D8(void) { return 1; }

FE_OVERLAY int fn_804594E0(FeScrA* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9C);
    x->m14C = fn_8045A9AC(x, x->m14C);
    fn_80458B58(x, -1);
    return 1;
}

FE_OVERLAY int fn_80459534(void) { return 1; }

FE_OVERLAY int fn_8045953C(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot50();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_804595A4(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot51();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_8045960C(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot52();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_80459674(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot53();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_8045987C(FeScrA* x, int a)
{
    x->m144[x->m14C]->fn_vslot41(a);
    return 0;
}

FE_OVERLAY int fn_80459A64(FeScrA* x)
{
    x->m144[x->m14C]->fn_vslot39();
    return 0;
}

FE_OVERLAY int fn_80459AAC(void) { return 0; }
FE_OVERLAY int fn_80459AB4(void) { return 0; }
FE_OVERLAY int fn_80459ABC(void) { return 0; }
FE_OVERLAY int fn_80459AC4(void) { return 0; }

FE_OVERLAY int fn_80459F14(FeScrA* x)
{
    if (x->m138->fn_vslot86() != 0) {
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80459F5C(FeScrA* x)
{
    if (x->m138->fn_vslot87() != 0) {
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80459FA4(FeScrA* x)
{
    int m = x->m14C;
    int r;
    if (m == 0) {
        r = fn_80459F14(x);
    } else {
        r = 0;
        if (m == 1) {
            r = fn_80459F5C(x);
        }
    }
    return r;
}

FE_OVERLAY void fn_8045A85C(FeScrA* x)
{
    int i = 1;
    int rowoff = 0;
    do {
        int j = 0;
        int coloff = 0;
        do {
            void* g = lbl_8061930C;
            char* b = (char*)x + 0x164;
            int o = coloff + rowoff;
            fn_8007B714__18Unk8007B2B0_Screen(g, (int)x->m160, i, j, *(int*)(b + o));
            j++;
            coloff += 8;
        } while (j <= 9);
        i++;
        rowoff += 0x50;
    } while (i <= 9);
}

FE_OVERLAY void fn_8045A8D8(FeScrA* x)
{
    int i = 1;
    char* q = (char*)x;
    int rowoff = 0;
    fn_8007B738__18Unk8007B2B0_Screen(lbl_8061930C, (int)x->m160);
    do {
        int j = 0;
        int coloff = 0;
        int* p = (int*)(q + 0x164);
        do {
            int off = coloff + rowoff;
            int v = fn_8007B6F0__18Unk8007B2B0_Screen(lbl_8061930C, (int)x->m160, i, j);
            j++;
            coloff += 8;
            char* b1 = (char*)x + 0x164;
            *(int*)(b1 + off) = v;
            int t = *p;
            p += 2;
            if (t == 0) {
                char* b2 = (char*)x + 0x168;
                *(int*)(b2 + off) = 4;
            } else {
                int h = fn_80077BC4(lbl_8061930C, v);
                char* b3 = (char*)x + 0x168;
                *(int*)(b3 + off) = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, h);
            }
        } while (j <= 9);
        i++;
        q += 0x50;
        rowoff += 0x50;
    } while (i <= 9);
}

FE_OVERLAY int fn_8045A9AC(FeScrA* x, int a)
{
    return a == 1 ? 0 : 1;
}

FE_OVERLAY FePair fn_8045A9C0(FeScrA* x, int idx)
{
    FePair r;
    fn_80360B80(&r);
    if (idx != 0) {
        if (idx == 1) {
            if (x->m13C[1]->fn_vslot60() < x->m7D4) {
                return x->m434[x->m13C[1]->fn_vslot60()];
            }
        }
    } else {
        int k = x->m15C - 1;
        return x->m164[k][x->m13C[0]->fn_vslot60()];
    }
    return r;
}

FE_OVERLAY FePair fn_8045AAB4(FeScrA* x, int idx)
{
    FePair r;
    fn_80360B80(&r);
    if (idx != 0) {
        if (idx == 1) {
            int i = x->m154;
            if (i <= x->m7D4 && i != -1) {
                return x->m434[i];
            }
        }
    } else {
        int j = x->m158;
        if (j != -1) {
            int k = x->m15C - 1;
            return x->m164[k][j];
        }
    }
    return r;
}

FE_OVERLAY FeScrB* fn_8045B074(FeScrB* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067B310);
    self->m130 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m1B8 = 0;
    self->m1BC = 0;
    self->m1C0 = 0;
    self->m1C4 = 0;
    self->m1C8 = 0;
    self->m1CC = 0;
    self->m1D0 = 0;
    self->m1D4 = 0;
    self->m1D8 = 0;
    self->m1DC = 0;
    self->m1E0 = 0;
    self->m1E4 = 0;
    self->m1E8 = 0;
    self->m1EC = 0;
    self->m1F0 = 0;
    return self;
}

FE_OVERLAY void fn_8045B108(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

}
