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

/* Frames to seconds through an inline: the constant-pool loads the inliner copies are not
 * unchanging, so sched1 keeps them below preceding stores (retail's order). */
template <class T> inline float Unk8029B70C_Secs(T n)
{
    return (float)n * 0.016666668f;
}

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
        Unk8029B70C_Mirror8(&x->m734, 0.0f);
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

/* near-miss: 268 of 268 instructions, 12 differ. Retail loads the float arg of
 * the fn_802A2604 call before g->m48 and r3 (here the order is r5, r3, f1),
 * and loads cur/tgt into f13/f0 for the second AngleDiff earlier, with the
 * registers swapped. Tried: arg order of the call (float first fixed
 * fn_8029C914 but not this one), statement orders around the Mirror calls,
 * a local for g->m48. */
int fn_8029C4E4(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    if (!x) {
        return 1;
    }
    Unk80271DBC_Link* link = x->m618;
    unsigned int hash = 0xEA68D008;
    Unk8029B70C_Pos* pos = (Unk8029B70C_Pos*)x->m44C->m6CC;
    unsigned int h83C = link->m83C;
    unsigned int h838 = link->m838;
    float cur = fn_80382BB8(link);
    if (!g->mD0.f4) {
        if (h838 == 0xBC3E4517 || h838 == 0x71D2D816) {
            hash = 0xBC3E4517;
        }
    }
    int state = fn_802A2604(g, x, f, g->m48);
    if (g->mCC == 3) {
        if (fn_8026D628(x, 0) || fn_8026DAE8(x, 0)) {
            hash = 0xBC3E4517;
        }
    }
    int s = fn_802A1790(g, x, f);
    if (s != 0x11) {
        return s;
    }
    if (state != 1) {
        return state;
    }
    if (fn_8026D6AC(x, 0)) {
        return 1;
    }
    float tgt = fn_8029CF14(g, x);
    float diff = AngleDiff(cur, tgt);
    int big = Abs(diff) > 0.39269912f;
    if (fn_8029D7C4(g)) {
        if (!big || h838 == 0x27C57C8B || h83C == 0x27C57C8B) {
            hash = 0x27C57C8B;
        }
        if (fn_802A168C(g, x, hash, tgt)) {
            g->mD0.f10 = 0;
            g->mD0.f7 = 0;
            return state;
        }
        int r = fn_8027B1A0(g, x, &g->m9C);
        Unk8029B70C_Mirror120(&x->m734, r);
    }
    if (fn_8026DC18(x, 0) || fn_8026D7E0(x, 0)) {
        int mine = 0;
        if ((unsigned int)g->m38 > 1) {
            mine = pos->m36C == x;
        }
        Unk802726BC_Angles* p = &x->m734;
        Unk8029B70C_Mirror78(p, mine);
        float d = AngleDiff(cur, tgt);
        Unk8029B70C_Mirror98(p, d);
        Unk8029B70C_MirrorB8(p, 0.0f);
    }
    fn_80381E9C(link, hash, 0, 0);
    Unk802726BC_Angles* q = &x->m734;
    Unk8029B70C_Mirror48(q, -1.0f);
    h838 = link->m838;
    if (h838 == hash) {
        g->mD0.f10 = 0;
        g->mD0.f7 = 0;
        if (state == 1 && big) {
            state = 2;
        }
    }
    return state;
}

int fn_8029C914(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    if (!x) {
        return 1;
    }
    Unk8029B70C_Pos* pos = (Unk8029B70C_Pos*)x->m44C->m6CC;
    int state = fn_802A2604(g, x, f, g->m48);
    if (pos->m36C == x && g->m60) {
        fn_802A2A64(g, x, g->m60);
        if (g->m4->m28 == 0) {
            fn_8028F34C(g->m4);
            g->m4->m98 = g->m60;
            Unk80273498_Vec3 tbl = lbl_805DED28[g->mC4];
            Unk80273498_Vec3 diff = g->m60->m60 - tbl;
            g->m4->fn_8028F45C(g->mB8);
            g->m4->fn_8028F528(diff);
            g->m4->m38 = 3;
            g->m4->m40 = 5;
        }
        int r = fn_80290D1C(g->m4, x);
        if (r == 0 || r == 2) {
            fn_8028F440(g->m4);
            fn_80381E9C(x->m618, 0xEA68D008, 0, 0);
            return 1;
        }
        if (r == 3) {
            g->m50 = x->m618->m83C;
            g->mD0.f6 = 0;
            return 11;
        }
        if (state != 8) {
            fn_8028F440(g->m4);
            fn_80381E9C(x->m618, 0xEA68D008, 0, 0);
        }
        return state;
    }
    return 1;
}

inline float HeadingTo(Unk80273498_Vec3 p)
{
    return fn_80410CE8(lbl_805DED58.x - p.x, lbl_805DED58.z - p.z);
}

/* near-miss: 50 of 50 instructions, 8 differ in the order of the three word
 * loads of the position copy (retail y, x, z; here y, z, x). Tried: FlatPos
 * written field-wise in several orders, a local copy, const& parameters. */
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

void fn_8029D094(Unk8029B70C_Goal* g, Unk8014D8AC_Ctx* ctx)
{
    if (!g->mD0.f11) {
        int id = ctx->m700->m3B8;
        Unk80273498_Vec3 pos = lbl_806055AC;
        float t = 0.0f;
        if (fn_801DC658(id, &pos, &t)) {
            float now = Unk8029B70C_Secs(ctx->m4C);
            g->m9C = pos;
            g->mA8 = now + t;
            g->mD0.f11 = 1;
        }
    }
}

int fn_8029D184(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
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
    return fn_8024B99C(x, &v, &w, &z, 0, 0);
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

int fn_8029D7D4(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int a, int b, int c, int d)
{
    return fn_8029D7F4(g, x, a, b, c, d);
}


/* near-miss: 200 of 200 instructions, 38 differ: callee-saved register
 * assignment (retail keeps the fifth parameter in r23 and the constant 1 in
 * r27, here swapped) and the order of the Query record initialisation
 * (retail reads the type word through r1, here through the record pointer). */
int fn_8029D7F4(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int p2, int p3, int p4, int p5)
{
    if (!x) {
        return 0;
    }
    if (!p2) {
        return 0;
    }
    if (fn_8026D940(x, 0)) {
        return 0;
    }
    Unk8029B70C_Query q;
    float t;
    q.mBC = 1;
    fn_80386110(x->m618, &q, 0xB10CE722, lbl_806242B0, &t, 0);
    if (!(t <= 0.0f)) {
        return 0;
    }
    Unk80271DBC_Link* link = x->m618;
    fn_8029EE50(g);
    fn_8029EF28(g, x, link);
    Unk8029B70C_Req r = fn_8029DB14(g, x, p2, p3, p4);
    if (p5) {
        r.m28 = 1;
    }
    int ret = 0;
    if (g->mD0.f9) {
        int kind = fn_8026D184(fn_801A2034(x->m44C, 4), 0);
        Unk8029B70C_Req r2 = fn_8029E4AC(g, x, kind, p3, p4, r);
        ret = fn_8029EC30(g, x, link, kind, p3, p4, r2);
    } else if (!fn_8024D218(x) && !g->mD0.f6) {
        if (fn_8029E6BC(g, x, link, p3, p4, r)) {
            ret = 1;
        }
    }
    return ret;
}

Unk8029B70C_Req fn_8029E4AC(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int kind, int a, int b, Unk8029B70C_Req o)
{
    Unk8029B70C_Req s;
    fn_8040B320(&s, 0, 0x58);
    if (a) {
        switch (kind) {
        case 0:
            s.m10 = 0;
            s.m4 = 1;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
            s.m8 = 1;
            s.m14 = o.m10;
            break;
        case 4:
            s.mC = 1;
            break;
        }
        if (o.m8 && (unsigned int)(kind - 3) <= 2) {
            int t = fn_8026D344(fn_801A2034(x->m44C, 4), 0);
            if (t == 7 || t <= 1 || (unsigned int)(t - 3) <= 2) {
                s.m8 = 0;
                s.mC = 1;
            }
        }
        if (s.m14 != 0 || s.m8 != 0) {
            if (fn_8029D184(g, x, 6.0f)) {
                s.m14 = 0;
                s.m8 = 0;
                s.m4 = 1;
            }
        }
    }
    if (b) {
        switch (kind) {
        case 0:
            s.m24 = 1;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
            s.m20 = 1;
            break;
        }
    }
    return s;
}

int fn_8029EC30(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80271DBC_Link* link, int kind, int a, int b, Unk8029B70C_Req o)
{
    if (!(g->m74 <= 0.0f)) {
        return 0;
    }
    g->mD0.f9 = 0;
    unsigned int hash = 0;
    if (!fn_8024D218(x)) {
        if (fn_8026DB3C(x, 0)) {
            if (fn_80381E9C(link, 0x36E74862, 0, 0)) {
                hash = 0x36E74862;
            }
        } else if (fn_80381E9C(link, 0xF4318E1D, 0, 0)) {
            hash = 0xF4318E1D;
        } else if (fn_80381E9C(link, 0x4C226115, 0, 0)) {
            hash = 0x4C226115;
        }
    }
    if (hash) {
        g->m50 = hash;
        g->mD0.f6 = 0;
        return 1;
    } else {
        hash = fn_8029D2E0(g, x, kind, a);
        if (!hash) {
            if (a) {
                if (o.mC && !fn_802D7DB4(fn_801A2034(x->m44C, 4), 0xBE)) {
                    hash = 0xC3879806;
                } else if (!o.m4 || (hash = 0x1D2A62BD, fn_802D7DB4(fn_801A2034(x->m44C, 4), 0xBE))) {
                    hash = 0x1D2A62BD;
                }
            } else if (b) {
                if (o.m20) {
                    hash = 0x125671E2;
                } else if (kind != 4) {
                    hash = 0x1259EE16;
                }
            }
        }
        if (!hash) {
            return 0;
        }
        fn_80381E9C(link, hash, 0, 0);
        g->m50 = hash;
        g->mD0.f6 = 0;
        return 2;
    }
}
