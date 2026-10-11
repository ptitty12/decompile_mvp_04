/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x80296C78-0x80299920, .rodata 0x805DDB58-0x805DDBF0, .data 0x8061E794-0x8061E7A4.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 *
 * Status: 20/25 match. Near-misses (noted above their functions): fn_802987C8, fn_80299100,
 * fn_802993D4. Not attempted: fn_80296C78 (615 insns) and fn_802977FC (1011 insns); both are
 * dominated by the same inline Vec3 temp-copy shapes as the near-misses.
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

/* near-miss (about 91%, 237 vs 235 insns): control flow and the first branch are identical; the
 * second branch's Sub/DistSq2D temp slots sit 8 bytes higher than retail's (retail 0x10/0x20/0x30,
 * result 0x60), the `return 0` after the angle test is `li r3,0; b` instead of the shared tail, and
 * the epilogue ternary differs by an `li`. `float spare` reserves retail's slot at 0xc. Needed:
 * by-value GetPos() operands (direct sp stores for the temps), no `ad` variable, `goto tail`
 * (tail block after the else branch), a pruned-style ternary for the 1.0/0.0 flag. About 25
 * variants (declaration placement, merged conditions, goto/early-return shapes). */
int fn_802987C8(Unk80296C78_Goal* g, Unk80296C78_Goal* o, int a, int b)
{
    if (g->m4C != 0) {
        float th = fn_80249298(a, g->m40, 1);
        float spare;
        if (o != 0) {
            if (g->m4C == 0x20) {
                float d = g->m84 - o->m84;
                if (!((float)fabs(d) > 0.05f) && g->m38 == o->m48p->m38 && g->m28 != 0) {
                    if (!(DistSq2D(Sub(GetPos(g), GetPos(o))) > th)) {
                        if (o->m2C != 0) {
                            float t1 = fn_80410CE8(g->m1C.x, g->m1C.z);
                            float t2 = fn_80410CE8(o->m1C.x, o->m1C.z);
                            d = !(AngleDiff(t1, t2) >= 0.17453295f) ? 1.0f : 0.0f;
                            if ((float)fabs(d) != 0.0f) {
                                return 0;
                            }
                        }
                        goto tail;
                    }
                }
            } else if (g->m38 == o->m48p->m38 && g->m28 != 0) {
                if (!(DistSq2D(Sub(GetPos(g), GetPos(o))) > th)) {
                    if (g->IsF13() && o->IsF13()) {
                        float t = g->m80 - o->m80;
                        if ((float)fabs(t) > 0.05f) {
                            return 0;
                        }
                    }
                    if (g->IsF12() && o->IsF12()) {
                        float t = g->m74 - o->m74;
                        if ((float)fabs(t) > 0.15f) {
                            return 0;
                        }
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
tail:
    int p1 = *g->m44;
    int p2 = *o->m44;
    if (p1 == 0) {
        if (p2 != 0) {
            return 0;
        }
        return 1;
    }
    if (p2 == 0) {
        return 0;
    }
    return fn_8027CFA8(a, b) ? 1 : 0;
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

void fn_80298CB8(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80298CB8_Req* o, float f, int c, Vec3* out, int unused,
                 int n)
{
    if (c == 1) {
        c = g->m0;
    }
    int flag = 0;
    int h = fn_80298DB8(g, c, &flag);
    int flags = 0;
    if (flag != 0) {
        flags = 4;
    }
    if (g->m48 == 0) {
        o->mA0 = 0x53CFCF84;
        o->mBC |= 8;
    }
    float t = 0.0f;
    fn_80386110(x->m618, o, 0x53CFCF84, h, &t, flags | 2);
    float u = t;
    float spare;                   /* never read: reserves stack slot 0x14 */
    o->mD8 = 1;
    o->mD4 = o->mD4 + u;
    ((Unk8027A84C*)g)->fn_8027AC90(&o->mtx, n, unused, out);
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

int fn_80298FE0(Unk80296C78_Goal* g, Unk80270BA0_X* x)
{
    Unk80296C78_Player* t = (Unk80296C78_Player*)g->m4C;
    int r = 1;
    if (t->m264 != 0) {
        if (x->mB3C & 0x10000000) {
            fn_80249B40(x, 0.2f, 0, 0, 0);
            fn_80249DF8(x, 0);
        }
        return 0;
    }
    if (t != 0) {
        fn_80249DF8(x, 1);
        fn_80249B40(x, 0.2f, g->m4C, 0, 0);
    }
    Unk80695950* mgr = &lbl_80695950;
    if (!mgr->fn_803834D8(x)) {
        if (g->m48 != 0 && g->m60 == 0) {
            r = fn_802993B4(g, x, (Unk80270BA0_X*)g->m4C);
        } else {
            r = fn_80299100(g, x, (Unk80270BA0_X*)g->m4C);
            g->m60 = 0;
        }
    }
    return r;
}

inline Vec3 FlatPos(const Unk80270BA0_X* x)
{
    Vec3 v = x->m60;
    v.y = 0.0f;
    return v;
}

/* near-miss (about 88%, 179 vs 173 insns): same blocks as retail; the vector setup differs.
 * Retail builds the y-zeroed position in place (y word through slot +4), copies it to a second
 * Vec3 from registers and to a third; mine reloads the copy from memory (extra lwz/stw pair) and
 * the saved-register count is one higher (stmw r25 vs r26). The first SetSlot78 store needs a
 * hoisted `li r6,1` in retail (mine reuses the compared register). About 20 declaration-order and
 * helper shapes tried (FlatPos/Flatten by value, copies, A/B/C permutations). */
int fn_80299100(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* p)
{
    Unk80271DBC_Link* link = x->m618;
    Unk80296C78_Player* t;
    if (g->m64 != 0 || (g->m64 = (((Unk8027A84C*)g)->fn_8027BB88(x, (Unk8027BBA8_Obj*)p, 0, 1, 1) != 0)) != 0) {
        float v = fn_80382BD8(link, 0);
        t = (Unk80296C78_Player*)g->m4C;
        if ((t->m590 & 0x20000000) || !(v <= 0.8f)) {
            if (x->mB3C & 0x10000000) {
                fn_80249B40(x, 0.2f, 0, 0, 0);
                fn_80249DF8(x, 0);
            }
            return 0;
        }
        return 1;
    }
    Unk80296C78_Angles* a = (Unk80296C78_Angles*)&x->m734;
    int one = 1;
    if (a->m190 == 1) {
        a->m78[0] = one;
    }
    SetSlot78(a, a->m190, one);
    Vec3 A = FlatPos(x);
    Vec3 B = FlatPos(p);
    Vec3 C = B;
    int i1;
    int i2;
    float f;
    if (fn_8026CF70(x, p, &i1, &i2, &f)) {
        if (fn_8026CFF8(i1, &A, i2, &B) == 0) {
            if (g->m4->m28 == 0) {
                g->m4->fn_8028F34C();
                g->m4->m98 = p;
                g->m4->fn_8028F45C(B);
                g->m4->fn_8028F528(C - A);
                g->m4->m38 = 3;
                g->m4->m40 = 5;
            }
            int r = fn_80290D1C(g->m4, x);
            if (r != 0 && r != 2) {
                return 1;
            }
        }
        g->m4->fn_8028F440();
        fn_80381E9C(link, 0xEA68D008, 0, 0);
    } else {
        fn_80381E9C(link, 0xEA68D008, 0, 0);
    }
    return 1;
}

int fn_802993B4(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* target)
{
    return fn_802993D4(g, x, target);
}

/* near-miss for fn_802993D4 (about 85%, 265 vs 263 insns): the vector arithmetic (Direction * speed *
 * f * k, sum, the Ent calls) matches instruction for instruction; the difference is the
 * prologue: retail builds the y-zeroed position of p in place at sp+0x18 (y word through the slot),
 * copies it to sp+8, and keeps the sum result in a fresh temp (frame 0x118 vs mine 0x108). Tried:
 * pos/start declaration orders, FlatPos/Flatten helpers, single-statement sum, Add() by-value
 * and by-reference variants (see PATTERNS: this temp-copy shape recurs in fn_802857C4). */
inline Vec3 Flatten(Vec3 v)
{
    v.y = 0.0f;
    return v;
}

int fn_802993D4(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* p)
{
    Vec3 start = Flatten(p->m60);
    Vec3 pos;
    Unk80271DBC_Link* link = x->m618;
    float ang = fn_80382BB8(p->m618);
    float speed = fn_804028E4(p->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f);
    float f = 1.0f;
    if (fn_8026D654(p, 0) != 0 || fn_8026D6AC(p, 0) != 0) {
        f = 0.2f;
    }
    if (fn_8026DAE8(p, 0) != 0) {
        f = 0.0f;
    }
    f = !(f > 1.0f) ? (!(f >= 0.0f) ? 0.0f : f) : 1.0f;
    float k = 0.5f;
    Vec3 off = Direction(ang) * speed * f * k;
    pos = start + off;
    g->m4->fn_8028F45C(pos);
    g->m4->m38 = g->m38;
    g->m4->m4C = fn_8027D708(g, x, p) == 1 ? 0x40 : 0x10;
    int busy = g->m64;
    if (busy != 0) {
        float v = fn_80382BD8(link, 0);
        if (((Unk80296C78_Player*)g->m4C)->m590 & 0x20000000 || !(v <= 0.8f)) {
            if (x->mB3C & 0x10000000) {
                fn_80249B40(x, 0.2f, 0, 0, 0);
                fn_80249DF8(x, 0);
            }
            return 0;
        }
    } else {
        g->m4->m98 = p;
        int r = fn_80290D1C(g->m4, x);
        if (r == 3) {
            g->m64 = 1;
        } else if (r == 0 || r == 2) {
            fn_80381E9C(link, 0xEA68D008, 0, 0);
            g->m64 = busy;
            g->m60 = 1;
            g->m4->fn_8028F440();
        }
    }
    return 1;
}

void fn_802997F0(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80298CB8_Req* o, int c, Vec3* out, int unused, int n,
                 float f)
{
    ((Unk8027A84C*)g)->fn_8027AC90(&o->mtx, n, unused, out);
    o->mD8 = 0;
}

int fn_80299834(const Unk80296C78_Goal* a, const Unk80296C78_Goal* b)
{
    if (b) {
        if (b->m48 == a->m48 || a->m64 != 0) {
            if (b->m4C != 0 && b->m4C == a->m4C) {
                return DistSq2D(a->m50 - GetPos50(b)) <= 14400.0f;
            }
        }
    }
    return 0;
}

void fn_80299914(Unk80296C78_Goal* g)
{
    g->m0 = 0;
}
