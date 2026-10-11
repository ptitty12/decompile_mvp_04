/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic, including the code that uses the
 * userpickupballgoal.cpp assert path (fn_8029B70C). File boundary unknown;
 * placeholder name.
 *
 * .text 0x8029B70C-0x8029EE50, .rodata 0x805DDD0C-0x805DDEEC,
 * .data 0x8061E7FC-0x8061E83C. Data used outside these ranges is extern.
 */
#include "game/chooser.h"
#include "game/goals/tu_8029B70C.h"

float lbl_8061E80C = 0.9f;
float lbl_8061E810 = 0.4f;

/* Random float in [0, scale): the file name goes through a local, which is
 * what produces retail's argument setup order. */
inline float RandF(Unk8014D8AC* rng, float scale)
{
    const char* file = UNK8029B70C_PICKUP_FILE;
    return (float)(unsigned int)rng->fn_8014D8AC(1000000, file, 515) * scale * 0.000001f;
}

int fn_8029B70C(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    if (!x) {
        return 0;
    }
    if (fn_8024D504(x, 1, 0, 0, 0)) {
        float p = Unk8029B70C_Ratio(lbl_8061E810, ((Unk8029B70C_Player*)x)->m540, lbl_8061E80C);
        return RandF(x->m44C->m554, 1.0f) < p;
    }
    return 0;
}

int fn_8029C024(Unk8029B70C_Goal* g, Unk80271DBC_Link* link)
{
    switch (link->m838) {
    case 0xEE1B6C46:
    case 0x8249F53C:
    case 0x9CEA8000:
    case 0xE433AA50:
    case 0xF4318E1D:
    case 0x1F8D6080:
    case 0x512ADB3C:
        return 2;
    case 0xDDC7F61B:
    case 0x6545C691:
        return 4;
    case 0x97DAA625:
    case 0x9FE2E6D1:
    case 0xB9FDE5E3:
    case 0xCA50EF74:
    case 0xFBBC2A99:
    case 0x1A9F719F:
    case 0x4901B7BC:
    case 0x5112B944:
    case 0x51A70327:
        return 3;
    case 0xA68012D3:
    case 0x8C1988B6:
    case 0x8CFB37B7:
    case 0x9D803AF7:
    case 0xDB7AB022:
    case 0xC0F46231:
    case 0xE14981C4:
    case 0xE9868307:
    case 0x34CFAED1:
    case 0x0C0032D1:
    case 0x07CBFA4B:
    case 0x0E246B08:
    case 0x36E74862:
    case 0x5C53C627:
    case 0x7BF65171:
        return 1;
    }
    return 0;
}

/* near-miss: 156 of 154 instructions, structure matches. Retail keeps the two
 * zero floats of the reset (z1/z2) in frame slots 0x18 and 0x20 (inside the
 * freed query record); here they land in the slots of b and c (0xDC, 0xD8).
 * Tried: all 24 declaration orders of a/q/b/c, a at function level, an inline
 * SetBoth, return/else-if shapes of the tail. */
int fn_8029C27C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    if (!x) {
        return 12;
    }
    float now = (float)x->m44C->m4C * 0.016666668f;
    int hit = g->mD0.f6;
    if (!hit) {
        float a = 0.0f;
        Unk8029B70C_Query q;
        g->mD0.f6 = 1;
        q.mBC = 0;
        fn_80386110(x->m618, &q, g->m50, 0x971949A6, &a, 0);
        q.mBC = 0;
        g->m54 = now + a;
        float b = 0.0f;
        if (fn_80386110(x->m618, &q, g->m50, 0xFF0D1452, &b, 0) & 0x10000) {
            g->m5C = now + b;
            g->m58 = now + 9999.0f;
            if (!(g->m5C >= g->m54)) {
                g->m5C = g->m54;
            }
        }
        q.mBC = 0;
        float c = 0.0f;
        if (fn_80386110(x->m618, &q, g->m50, 0x989091AD, &c, 0) & 0x10000) {
            g->m58 = c + now;
            g->m5C = now + 9999.0f;
            if (!(g->m58 >= g->m54)) {
                g->m58 = g->m54;
            }
        }
    }
    if (!(now <= g->m5C)) {
        Unk802726BC_Angles* p = &x->m734;
        float z1 = 0.0f;
        float z2 = z1;
        if (p->m190 == 1) {
            p->m8[0] = z2;
        }
        Unk8029B70C_SetM8(p, p->m190, z2);
        g->mD0.f6 = 0;
        return 1;
    }
    if (g->m58 <= now) {
        g->mD0.f6 = 0;
        return 3;
    }
    g->mD0.f7 = 0;
    return 12;
}

inline float HeadingTo(Unk80273498_Vec3 p)
{
    return fn_80410CE8(lbl_805DED58.x - p.x, lbl_805DED58.z - p.z);
}

float fn_8029CF14(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    float r = fn_80382BB8(x->m618);
    Unk8029B70C_Flags flags = g->mD0;
    if (flags.f1) {
        r = g->m6C;
    } else if (flags.f2) {
        r = g->m70;
    } else {
        r = HeadingTo(FlatPos(x->m60));
    }
    return r;
}

inline float LenSq2D(Unk80273498_Vec3 v)
{
    return v.x * v.x + v.z * v.z;
}

int fn_8029CFDC(Unk8029B70C_Goal* g, const Unk80273498_Vec3* a, const Unk80273498_Vec3* b)
{
    if (LenSq2D(*a - *b) > 1296.0f) {
        g->m70 = fn_80410CE8(b->x - a->x, b->z - a->z);
        g->mD0.f2 = 1;
        return 1;
    }
    return 0;
}

/* near-miss: 60 of 60 instructions, 4 slots differ (retail loads the 0.0166
 * constant before the third word of the pos copy). Tried: field-wise copy,
 * statement orders of the copy, `now` and the flag, a reference to m9C. */
void fn_8029D094(Unk8029B70C_Goal* g, Unk8014D8AC_Ctx* ctx)
{
    if (!g->mD0.f11) {
        int id = ctx->m700->m3B8;
        Unk80273498_Vec3 pos = lbl_806055AC;
        float t = 0.0f;
        if (fn_801DC658(id, &pos, &t)) {
            float now = (float)ctx->m4C * 0.016666668f;
            g->m9C = pos;
            g->mA8 = now + t;
            g->mD0.f11 = 1;
        }
    }
}

void fn_8029D184(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    const float k = 120.0f;
    Unk80273498_Vec3 step = fn_8023F29C(x) * k;
    step.y = f;
    Unk80273498_Vec3 v = x->m60;
    v.y += f;
    Unk80273498_Vec3 w = v + step;
    w.y = v.y;
    Unk80273498_Vec3 z = lbl_806055AC;
    char buf[40];              /* unused local that retail allocates (frame 0xA0); real type unknown */
    fn_8027A918(g);
    fn_8024B99C(x, &v, &w, &z, 0, 0);
}

void fn_8029D6DC(Unk8029B70C_Goal* g, Unk80270BA0_X* x, const Unk80273498_Vec3* t)
{
    float ang = fn_80410CE8(t->x - x->m60.x, t->z - x->m60.z);
    float tgt = fn_80382BB8(x->m618) + AngleDiff(ang, fn_80382BB8(x->m618));
    fn_80244858(x, tgt);
    fn_8029D184(g, x, 6.0f);
}

int fn_8029D7C4(Unk8029B70C_Goal* g)
{
    return g->mCC == 0;
}
