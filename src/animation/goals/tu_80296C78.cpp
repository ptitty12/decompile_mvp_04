/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x80296C78-0x80299920, .rodata 0x805DDB58-0x805DDBF0, .data 0x8061E794-0x8061E7A4.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/goals/tu_80296C78.h"

Vec3 fn_80297614(const Unk80296C78_Goal* g)
{
    if (g->IsF8() && !g->IsF9()) {
        return g->m164;
    }
    return g->m10;
}

int fn_80297668(const Unk80296C78_Goal* g)
{
    if (g->m4C == 2 || g->m4C == 4) {
        return g->m2C;
    }
    if (g->IsF8() && !g->IsF9()) {
        return g->m18Cbits.f10;
    }
    return g->m2C;
}

Vec3 fn_802976A8(const Unk80296C78_Goal* g)
{
    if (g->m4C == 2 || g->m4C == 4) {
        return g->m1C;
    }
    if (g->IsF8() && !g->IsF9()) {
        return g->m170;
    }
    return g->m1C;
}

int fn_8029771C(const Unk80296C78_Goal* g)
{
    if (g->IsF8() && !g->IsF9()) {
        return g->m17C;
    }
    return g->m40;
}

int fn_80297740(const Unk80296C78_Goal* g)
{
    if (g->IsF8() && !g->IsF9()) {
        return g->m180;
    }
    return g->m38;
}

int fn_80297764(Unk80296C78_Goal* g)
{
    if (g->m18Cbits.f8) {
        g->m18C &= ~0x800000;
        g->mC = 0;
        g->m4C = 0;
        g->m158 = 0.0f;
        g->m160++;
        return 1;
    }
    return 0;
}

int fn_802977B0(Unk80296C78_Goal* g)
{
    if (g->m18Cbits.f8) {
        g->m18C &= ~0x800000;
        g->mC = 0;
        g->m4C = 0;
        g->m158 = 0.0f;
        g->m160++;
        return 1;
    }
    return 2;
}

void fn_80298B74(Unk80296C78_Goal* g)
{
    g->m0 = 9;
    g->m48 = 0;
    g->m4C = 0;
}

int fn_80298B8C(Unk80296C78_Goal* g, Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;
    switch (g->m48) {
    case -1:
        break;
    case 0:
        fn_80381E9C(link, 0x53CFCF84, 0, 0);
        if (link->m838 == 0x53CFCF84) {
            return 0;
        }
        break;
    case 1:
        fn_80381E9C(link, 0x294A8535, 0, 0);
        if (link->m83C == 0x294A8535) {
            break;
        }
    case 2:
        switch (g->m4C) {
        case 0:
            fn_80381E9C(link, 0x18AC23C2, 0, 0);
            if (link->m83C == 0x18AC23C2) {
                g->m4C = 1;
                return 1;
            }
            break;
        case 1:
            if (link->m838 == 0x18AC23C2) {
                g->m4C = 2;
                return 0;
            }
            break;
        }
        break;
    }
    return 1;
}

int fn_80298DB8(Unk80296C78_Goal* g, int code, int* out)
{
    int r = 0;
    *out = 0;
    switch (code) {
    case 2:
        r = lbl_806242B4;
        break;
    case 8:
        r = 0x9DB287CD;
        break;
    case 9:
        r = 0xC45471DE;
        break;
    case 10:
        r = 0x9DB287CD;
        *out = 1;
        break;
    case 11:
        r = 0xA47337B4;
        break;
    case 12:
        *out = 1;
        r = 0xA47337B4;
        break;
    }
    return r;
}

void fn_80298E50(Unk80296C78_Goal* g)
{
    g->m48 = 0;
    g->m0 = 2;
    g->m60 = 0;
    g->m64 = 0;
    g->m4C = 0;
    g->m50 = lbl_806055AC;
    g->m68 = 0;
    g->m6C = 0;
}

Unk80296C78_Goal* fn_80298E9C(Unk80296C78_Goal* g, Unk80270BA0_X* x, int a)
{
    g->m48 = a;
    g->m4C = (int)x;
    Unk8027A84C_Owner* o = ((Unk80296C78_Player*)x)->m934;
    if (o) {
        if (o->fn_8027C67C()->m28) {
            g->m50 = GetPos((Unk80296C78_Goal*)o->fn_8027C67C());
        }
    }
    return g;
}

Unk80296C78_Goal* fn_80298F30(Unk80296C78_Goal* g, Vec3* v)
{
    v->y = 0.0f;
    SetVec(g->m10, *v);
    g->m28 = 1;
    return g;
}

Unk8027A84C* fn_80298F8C(Unk8027A84C* g, const Vec3* v)
{
    Vec3 t = *v;
    g->fn_8027A898(&t);
    return g;
}
