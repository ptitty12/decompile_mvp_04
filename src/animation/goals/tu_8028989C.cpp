/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028989C-0x8028B194, .rodata 0x805DD640-0x805DD6DC.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028989C.h"

void fn_8028989C(Unk8028989C_Goal* g)
{
    g->m0 = 6;
    g->m48 = 0;
    g->m4C = 0;
    g->m70 = 0;
    g->m64 = -1.0f;
    g->m6C = -1.0f;
    g->m54 = lbl_806055AC;
    g->m60 = 0.0f;
    g->m50 = -1.0f;
}

void fn_802898FC(Unk8028989C_Goal* g, float f)
{
    if (!(f > 10.0f)) {
        g->m64 = (f < 0.1f) ? 0.1f : f;
    } else {
        g->m64 = 10.0f;
    }
}

Unk80273498_Vec3 fn_8014E388(Unk8014E388_H* h);

Unk8028989C_Goal* fn_80289944(Unk8028989C_Goal* g, float f, Unk8014E388_H** p, int n)
{
    Unk80273498_Vec3 v = fn_8014E388(*p);
    v.y = 0.0f;
    g->m10 = v;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 2;
    g->m4C = n;
    return g;
}

Unk8028989C_Goal* fn_802899E8(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.y = 0.0f;
    g->m10.z = v.z;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 3;
    return g;
}

Unk8028989C_Goal* fn_80289A4C(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.y = 0.0f;
    g->m10.z = v.z;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 4;
    return g;
}

Unk8028989C_Goal* fn_80289AB0(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.y = 0.0f;
    g->m10.z = v.z;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 5;
    return g;
}

Unk8028989C_Goal* fn_80289B14(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.y = 0.0f;
    g->m10.z = v.z;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 6;
    return g;
}

int fn_80289B78(Unk8028989C_Goal* g)
{
    switch (g->m4C) {
    case 4:
    case 5:
    case 6:
        return 1;
    }
    return 0;
}

void fn_80289FB8(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;

    if (g->mC <= 2 && g->m70 == 0) {
        float angle = fn_80410CE8(g->m1C.x, g->m1C.z);
        fn_80244858(x, angle);
    }
    fn_80381E9C(link, UNK8028989C_STATE_A, 0, 0);
    if (link->m838 == UNK8028989C_STATE_A) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

int fn_8028AA4C(Unk8028989C_Goal* g, Unk80270BA0_X* x, int flag);

void fn_8028A05C(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;
    int hash = fn_8028AA4C(g, x, 0);

    if (g->m28) {
        Unk80273498_Vec3 v = g->m10;
        x->m93C = v;
    } else {
        x->m93C.y = -1000.0f;
    }
    if (g->mC <= 2) {
        float angle = fn_80410CE8(g->m1C.x, g->m1C.z);
        fn_80244858(x, angle);
    }
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

void fn_8028A13C(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    int hash = fn_8028AA4C(g, x, 0);
    Unk80271DBC_Link* link = x->m618;

    if (g->m28) {
        Unk80273498_Vec3 v = g->m10;
        x->m93C = v;
    } else {
        x->m93C.y = -1000.0f;
    }
    if (g->mC <= 2) {
        float angle = fn_80410CE8(g->m1C.x, g->m1C.z);
        fn_80244858(x, angle);
    }
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

void fn_8028A21C(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    int hash = fn_8028AA4C(g, x, 0);
    Unk80271DBC_Link* link = x->m618;

    if (g->mC <= 2) {
        if (g->m28) {
            Unk80273498_Vec3 v = g->m10;
            x->m93C = v;
        } else {
            x->m93C.y = -1000.0f;
        }
    }
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

int fn_8028AA4C(Unk8028989C_Goal* g, Unk80270BA0_X* x, int flag)
{
    int hash = 0;

    switch (g->m48) {
    case 1:
        hash = 0x75027FEF;
        break;
    case 3:
        hash = 0x152396E5;
        break;
    case 4:
        hash = 0xB6129A0D;
        break;
    case 5:
        hash = 0xB98F3D5B;
        break;
    case 6:
        hash = 0x785EA583;
        break;
    case 2:
        hash = fn_80289B78(g) ? 0x78B61236 : 0x2F10F625;
        break;
    }
    return hash;
}

extern int lbl_806242B4;

int fn_8028AB04(Unk8028989C_Goal* g, int k)
{
    int r = 0;

    switch (k) {
    case 6:
        if (g->m48 == 2) {
            r = 0xCF4ABDEE;
        } else {
            r = lbl_806242B4;
        }
        break;
    case 2:
        r = lbl_806242B4;
        break;
    }
    return r;
}

void fn_8028B12C(Unk8028989C_Goal* g)
{
}

int fn_8028B130(Unk8028989C_Goal* g)
{
    return 0;
}

void fn_8028B138(Unk8028989C_Goal* g)
{
}
