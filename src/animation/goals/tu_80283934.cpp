/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x80283934-0x80287600, .rodata 0x805DD3F4-0x805DD54C, .data 0x8061E6D4-0x8061E700.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/goals/tu_80283934.h"

extern const Vec3 lbl_805DED28[];   /* table indexed by a goal's mA0 */
extern int lbl_8061D3BC;            /* 0x8061D3BC/C0 and 0x8061E6B8..C4: int flags, */
extern int lbl_8061D3C0;            /* the last four sit in tu_8027A84C's .data split */
extern int lbl_8061E6B8;
extern int lbl_8061E6BC;
extern int lbl_8061E6C0;
extern int lbl_8061E6C4;
extern Unk80283934_Slot lbl_806E07E0[6];
extern const Vec3 lbl_806055AC;      /* shared 0xc-byte object (a position) */

Vec3 fn_802850EC(const Unk80283934_Goal* g)
{
    if (g->mE8 < 0) {
        return g->mA4;
    }
    return lbl_805DED28[g->mA0];
}

int fn_80285148(Unk80283934_Goal* g, Unk80270BA0_X* x)
{
    if (g->m2C) {
        float a = fn_80382BB8(x->m618);
        float b = fn_80410CE8(g->m1C, g->m24);
        float diff = AngleDiff(a, b);
        if (!((float)fabs(diff) <= 0.17453295f)) {
            fn_80244858(x, b);
        } else {
            g->mCC = 1000.0f;
        }
    }
    return 1;
}

int fn_80285238(Unk80283934_Goal* g)
{
    Unk80283934_X* x = fn_8027A90C(g);
    Unk80283934_Pos* p = x->m44C->m6CC;

    if (p && p->m38C == 1 && lbl_8061D3BC) {
        return 1;
    }
    if (lbl_8061E6B8) {
        return 1;
    }
    if (!lbl_8061E6C0 && p && p->m38C == 1 && (g->mE8 & 0x10000) && g->mD0 > 440.0f) {
        return 1;
    }
    return 0;
}

int fn_802852F0(Unk80283934_Goal* g)
{
    Unk80283934_X* x = fn_8027A90C(g);
    Unk80283934_Pos* p = x->m44C->m6CC;

    if (p && p->m38C == 1 && lbl_8061D3C0) {
        return 1;
    }
    if (lbl_8061E6BC) {
        return 1;
    }
    if (lbl_8061E6C4) {
        return 0;
    }
    if (p && p->m38C == 1 && (g->mE8 & 0x8000) && !(g->mD0 <= 440.0f)
        && (g->m7C != 1 || (g->m28 && !(fn_80286E70(g).y >= 24.0f)))) {
        return 1;
    }
    return 0;
}

int fn_802853E4(const Unk80283934_Goal* g)
{
    return (g->mE8 >> 12) & 1;
}

int fn_802853F0(Unk80283934_Goal* g)
{
    if (g->m7C == 1 && g->m94 == 10 && g->m28) {
        int r = 0;
        if (!(fn_80286E70(g).y <= 12.0f)) {
            r = fn_80286E70(g).y < 48.0f;
        }
        if (r) {
            return 1;
        }
    }
    return 0;
}

int fn_80285498(Unk80283934_Goal* g)
{
    if (g->mE8 & 0x400000) {
        Unk80283934_X* x = fn_8027A90C(g);
        float t = (float)x->m44C->m4C * 0.016666668f;
        float lim = 0.7f;
        if (g->m98 - t < lim) {
            return 1;
        }
    }
    return 0;
}

float fn_80285534(Unk80283934_Goal* g)
{
    float r = -1.0f;
    if (!(g->mC8 <= 0.0f)) {
        Unk80283934_Angles* a = &fn_8027A90C(g)->m734;
        float* q = &a->m48[a->m190];
        float lim = *q;
        if (!(lim <= 0.0f)) {
            r = g->mC8 / lim;
        }
    }
    return r;
}

inline Vec3 EntPos(const Unk80283934_Ent* e)
{
    return e->m10;
}

inline Vec3 Flat(Vec3 v)
{
    v.y = 0.0f;
    return v;
}

inline Vec3 FlatPos(const Unk80270BA0_XBase* x)
{
    return Flat(x->m60);
}

/* The xz distance is one inline taking the goal: its local d is allocated
 * before the inlined getters' frames (d 0x18, EntPos 0x28, FlatPos 0x38,
 * Flat/operator- 0x48), as in retail; copies inside inlined bodies give
 * direct sp stores. */
inline float GoalDist2D(Unk80283934_Goal* g)
{
    Vec3 d = EntPos(g->m4) - FlatPos((Unk80270BA0_XBase*)fn_8027A90C(g));
    return fn_804028E4(d.x * d.x + d.z * d.z);
}

float fn_802855C4(Unk80283934_Goal* g)
{
    if (g->m98 == 0.0f) {
        return 999.0f;
    }
    float t = (float)fn_8027A90C(g)->m44C->m4C * 0.016666668f;
    float r = 0.0f;
    Unk80283934_Ent* e = g->m4;
    if (e->m28 && g->m7C == 1) {
        float dist = GoalDist2D(g);
        dist -= 12.0f;
        if (!(dist <= 0.0f)) {
            float s = fn_802958F4(g->m4, (Unk80270BA0_X*)fn_8027A90C(g), 0, -1.0f);
            if (!(s <= 0.0f)) {
                r = dist / s;
            }
            float c = 0.2f;
            r -= c;
        }
    } else {
        r = g->m98 - t;
    }
    return r;
}

inline Vec3 Pos0(const Unk80283934_Goal* g)
{
    return g->m10;
}

inline float Speed(const Unk80283934_Ent* e)
{
    return (e->m18C & 0x80000) ? e->m74 : -1.0f;
}

/* near-miss: 120 of 120 instructions, 11 differ. Pos0 (an inline getter) makes
 * the g->m10 copy direct sp stores, as in retail (see fn_80286E70), and Speed
 * keeps fold from distributing "- u" into the ternary arms. Left: t and u sit at
 * 0x48/0x4C (retail 0x38, reusing operator-'s inline frame, and 0x48), the
 * m9C compare operand order (retail loads o first but compares g, o), and two
 * scratch registers. Needed: `(float)fabs(t)` (see header) for the compare. */
int fn_802857C4(Unk80283934_Goal* g, const Unk80283934_Goal* o)
{
    if (o) {
        if ((g->mE8 & 0x2000000) && (o->mE8 & 0x2000000)) {
            int om = o->m78;
            return g->m78 == om;
        }
        if (g->m28 && o->m28 && ((g->mE8 >> 12) & 1) == ((o->mE8 >> 12) & 1)
            && ((g->mE8 >> 13) & 1) == ((o->mE8 >> 13) & 1) && o->m9C == g->m9C) {
            Vec3 pa = Pos0(g);
            Vec3 pb = fn_80286E70(o);
            Vec3 d = pa - pb;
            if (!(d.x * d.x + d.y * d.y + d.z * d.z >= 144.0f)) {
                float t = g->m84 - fn_80286F9C(o);
                if (!((float)fabs(t) > 0.35f)) {
                    if (g->m4->m18C & 0x80000) {
                        float u = g->m84 - fn_80286F9C(o);
                        fn_8028F588(Speed(g->m4) - u);
                    }
                    g->m84 = fn_80286F9C(o);
                    return 1;
                }
            }
        }
    }
    return 0;
}

void fn_802859A4(Unk80283934_Goal* g, const Unk80283934_Info* info)
{
    g->m48 = *info;
    g->mE8 |= 0x40000000;
    if (info->m24 & 0x20) {
        g->mE8 &= ~0x40000000;
    }
    if ((g->mE8 & 0x40000000) && g->m48.m2C == 3 && (unsigned int)(g->m48.m28 - 4) > 2) {
        g->mE8 |= 0x1000;
    }
    g->m9C = -1;
    switch (info->m20) {
    case 0:
        break;
    case 2:
        g->m9C = 1;
        g->mA4 = info->m4;
        g->mE8 |= 0x80000000;
        break;
    case 3:
        g->m9C = 0;
        g->mA4 = info->m4;
        g->mE8 |= 0x80000000;
        break;
    case 1:
    case 4:
    case 5:
        g->mE8 |= 0x4000;
        break;
    case 6:
        g->mE8 |= 0x2000;
        break;
    case 7:
        if (!g->m28) {
            fn_8027DAE8(g, &info->m10);
        }
        g->mE8 |= 0x20000;
        break;
    case 8:
        g->mE8 |= 0x40000;
        break;
    }
    Vec3 d = Direction(info->m1C);
    fn_8027DB38(g, &d, &lbl_806055AC);
}

/* The sum goes through an inline (Pos): the by-value operator+ argument copy is
 * then part of an inlined body, whose frame addresses fold to sp offsets (see
 * PATTERNS, "Vec3 copy destination addressing"). */
inline Vec3 Pos(const Unk80283934_Goal* g)
{
    return g->m10 + g->mD8;
}

Vec3 fn_80286E70(const Unk80283934_Goal* g)
{
    Vec3 v = Pos(g);
    return v;
}

Vec3 fn_80286F00(const Unk80283934_Goal* g)
{
    Vec3 v = Pos(g);
    v.y = 0.0f;
    return v;
}

float fn_80286F9C(const Unk80283934_Goal* g)
{
    return g->m84 + g->mD4;
}

void fn_80286FAC(Unk80270BA0_X* x)
{
    for (int i = 0; i <= 5; i++) {
        Unk80283934_Slot* e = &lbl_806E07E0[i];
        if (!(e->m94 & 0x80)) {
            Unk80283934_Ent* ent = fn_80384A48(fn_8028712C(i));
            Unk8037B3E8* c = fn_8037D028(fn_8037C7FC(), ent->m28);
            if (c->fn_vslot4() == 0x42D34230) {
                int n = fn_8026F590(c, x, e->data);
                e->data[0x96] = n > 0xFF ? 0xFF : (n >= 0 ? n : 0);
                Unk80283934_Slot* s = &lbl_806E07E0[i];
                s->m94 |= 0x80;
            }
        }
    }
}

void fn_8028709C(Unk80270BA0_X* x, unsigned int id)
{
    Unk80283934_Ent* ent = fn_80384A48(id);
    if (ent) {
        Unk8037B3E8* c = fn_8037D028(fn_8037C7FC(), ent->m28);
        if (c) {
            if (c->fn_vslot4() == 0x42D34230) {
                fn_8026F590(c, x, 0);
            }
        }
    }
}

unsigned int fn_8028712C(int kind)
{
    unsigned int h = 0;
    switch (kind) {
    case 1:
        h = 0x4EEBDCEC;
        break;
    case 2:
        h = 0x193EE819;
        break;
    case 3:
        h = 0xCA50EF74;
        break;
    case 4:
        h = 0x9FE2E6D1;
        break;
    case 0:
        h = 0x6BCA31A3;
        break;
    case 5:
        h = 0x5B23BCCF;
        break;
    }
    return h;
}

unsigned int fn_802871B4(int a)
{
    return fn_8028712C(fn_802871D8(a));
}

int fn_802871D8(int a)
{
    int r = 1;
    switch (a) {
    case 1:
    case 4:
    case 5:
        r = 1;
        break;
    case 6:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    case 2:
        r = 4;
        break;
    case 8:
        r = 0;
        break;
    case 7:
        r = 5;
        break;
    }
    return r;
}

void fn_802872AC(Unk80283934_Goal* g, int a, int b, int c, int d, ...);

Unk80283934_Goal* fn_80287250(Unk80283934_Goal* g, int a, int b, int c, int d)
{
    fn_802872AC(g, fn_802871D8(a), b, c, d);
    return g;
}
