/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028F178-0x802914C8, .rodata 0x805DD848-0x805DD938.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028F178.h"

float fn_804028E4(float x);               /* square root */
float fn_8041171C(float x);
float fn_80411554(float x);
float fn_80410CE8(float y, float x);

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Unk80273498_Vec3 operator*(Unk80273498_Vec3 v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline Unk80273498_Vec3 Direction(float angle)
{
    Unk80273498_Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
    return r;
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

inline float Length(Unk80273498_Vec3 v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline void Scale(Unk80273498_Vec3& v, float s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
}

inline float Abs(float v)
{
    return fabsf(v);
}

inline Unk80273498_Vec3 FlatPos(Unk80270BA0_X* x)
{
    Unk80273498_Vec3 t = x->m60;
    t.y = 0.0f;
    return t;
}

inline Unk80273498_Vec3 GetPos(const Unk8037B128_Mtx* m)
{
    Unk80273498_Vec3 v = fn_8037B128(m);
    return v;
}

inline float RSub(float b, float a)
{
    float r = a - b;
    return r;
}

Unk80273498_Vec3 fn_8028FD38(Unk8028F178_Goal* g, float angle, float a, float b);
float fn_8028FAEC(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o);

/* near-miss: 32 of 32 instructions, 3 differ in order only (retail spills f1 right after the first
 * lwz, mine places the stfs after `mr r11,r9`). The temps for the three root stores give retail's
 * value-before-pointer loads. Tried: owner pointer local, copy of the float parameter, local copy
 * of `a`, all three loads before the stores. */
void fn_8028F178(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk80279BB8* r, int a, int b, int c, int d, float f)
{
    if (g->m44->m14 != 0) {
        r->mD8 = 1;
        return;
    }
    if (a == 1) {
        a = g->m0;
    }
    int t1 = g->m38;
    g->m4->m38 = t1;
    int t2 = g->m34;
    g->m4->m34 = t2;
    int t3 = g->m40;
    g->m4->m40 = t3;
    fn_802977FC(g->m4, x, r, a, b, c, d, f);
}

void fn_8028F1F8(Unk8028F178_Goal* g, Unk8028F178_Goal* o)
{
    fn_802987C8(g->m4, o->m4);
}

float fn_8028F220(Unk80270BA0_X* x, int idx)
{
    int which = 0;
    if (lbl_8061E770[which] == 0) {
        Unk8028F220_Entry* e = fn_80384A48(0x2D9F492A);
        Unk8028F220_Chooser* c = fn_8037D028(fn_8037C7FC(), e->m28);
        cMatrixChooser* m;
        if (c->fn_vslot4() == 0x42D34230) {
            m = (cMatrixChooser*)c;
        } else {
            Unk8028F220_Chooser* p = c->fn_vslot18(0);
            m = (cMatrixChooser*)fn_8037D028(fn_8037C7FC(), p->fn_vslot24());
        }
        m->fn_8026FB80(x, lbl_806E0B70[which]);
        lbl_8061E770[which] = 1;
    }
    return lbl_806E0B70[which][idx];
}

/* The shared local `m1` gives retail's single -1 register for the byte store and the two ints. The
 * statement order was found by a hill-climb on the order of independent stores (see PATTERNS). */
void fn_8028F34C(Unk8028F178_Goal* g)
{
    int m1 = -1;
    g->m0 = 2;
    g->m4C = 0;
    g->m50 = m1;
    g->m5C = m1;
    g->m158 = 0.0f;
    g->m15C = 0.0f;
    g->m88 = 0.0f;
    g->m70 = -1.0f;
    g->m84 = -1.0f;
    g->m78 = -1.0f;
    g->m54 = 0;
    g->m18C.f12 = 0;
    g->m18C.f13 = 0;
    g->m18C.f14 = 0;
    g->m18C.f15 = 0;
    g->m18C.f16 = 0;
    g->m18C.f17 = 0;
    g->m18C.f18 = 0;
    g->m18C.top = m1;
    g->m58 = 0;
    g->m7C = -1.0f;
    g->m184 = 0.0f;
    g->m188 = 1.0f;
    g->m160 = 0;
    g->m18C.f8 = 0;
    g->m18C.f9 = 0;
    g->m164 = lbl_806055AC;
    g->m170 = lbl_806055AC;
    g->m180 = 2;
    g->m98 = 0;
    g->m18C.f10 = 0;
    g->m18C.f11 = 0;
    g->m18C.f19 = 0;
    g->m17C = 5;
}

void fn_8028F440(Unk8028F178_Goal* g)
{
    g->mC = 0;
    g->m4C = 0;
    g->m50 = 0;
    g->m54 = 0;
    g->m58 = 0;
}

/* Inline setter taking the vector by value: reading the temp copy back word by word is retail's shape. */
inline void SetVec10(Unk8028F178_Goal* g, Unk80273498_Vec3 t)
{
    g->m10 = t;
}

Unk8028F178_Goal* fn_8028F45C(Unk8028F178_Goal* g, Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    SetVec10(g, v);
    g->m28 = 1;
    return g;
}

Unk8028F178_Goal* fn_8028F4B8(Unk8028F178_Goal* g, unsigned int idx)
{
    g->m5C = idx;
    Unk80273498_Vec3 v = ((Unk8027A84C*)g)->fn_8027AF54(idx);
    fn_8028F45C(g, v);
    return g;
}

Unk8028F178_Goal* fn_8028F528(Unk8028F178_Goal* g, Unk80273498_Vec3* v)
{
    v->y = 0.0f;
    Unk80273498_Vec3 t = *v;
    ((Unk8027A84C*)g)->fn_8027A898(&t);
    return g;
}

void fn_8028F588(Unk8028F178_Goal* g, float f)
{
    if (!(f <= 0.0f)) {
        g->m74 = f;
        g->m18C.f12 = 1;
    } else {
        g->m18C.f12 = 0;
    }
}

Unk8028F178_Goal* fn_8028F5CC(Unk8028F178_Goal* g, float f)
{
    g->m80 = f;
    g->m18C.f13 = 1;
    return g;
}

Unk8028F178_Goal* fn_8028F5F4(Unk8028F178_Goal* g, float f)
{
    g->m84 = f;
    return g;
}

int fn_8028F610(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o)
{
    if (g->mC > 2) {
        return 0;
    }
    if (g->m18C.f12) {
        Unk8028F178_Ctx* ctx = (Unk8028F178_Ctx*)x->m44C;
        float t = (float)ctx->m4C * 0.016666668f;
        if (t < g->m74) {
            return 0;
        }
    }
    int hash = 0;
    Unk80273498_Vec3 pos = lbl_806055AC;
    ((Unk8027A84C*)g)->fn_8027AD3C(x, o, &pos, 0, 0, 0, &hash, 0);
    switch ((unsigned int)hash) {
    case 0x12A7B064:
    case 0x2D9F492A:
    case 0x58A2B20F:
    case 0x67A49CBA:
        return 0;
    }
    Unk80273498_Vec3 d = g->fn_GetM10() - pos;
    float d2 = d.x * d.x + d.z * d.z;
    if (hash == 0xFA52B1B5 || hash == 0xA84A0C58 || hash == 0x7942CA79 || hash == 0xF90D27A1) {
        if (d2 < 2304.0f) {
            return 1;
        }
    }
    float lim = fn_80249298(x, fn_8029771C(g), 1);
    return d2 < lim;
}

int fn_8028F848(Unk8028F178_Goal* g)
{
    Unk80270BA0_X* x = ((Unk8027A84C*)g)->fn_8027A90C();
    if (x && x->m618 && x->m618->m838 == 0x998C3D11) {
        return 1;
    }
    return 0;
}

Unk80273498_Vec3 fn_8028F898(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o, float f)
{
    Unk80273498_Vec3 pos;
    float heading;
    ((Unk8027A84C*)g)->fn_8027AD3C(x, o, &pos, &heading, 0, 0, 0, 0);
    Unk80273498_Vec3 d = fn_80297614(g) - pos;
    if (fn_8026DC18(x, 0) == 0) {
        heading = fn_80410CE8(d.x, d.z);
    }
    float len = fn_804028E4(d.x * d.x + d.y * d.y + d.z * d.z);
    Unk80273498_Vec3 r = fn_8028FD38(g, heading, f, len);
    return r;
}

/* The named `t` keeps the call result's slot ahead of `len`, as in retail's frame layout. */
Unk80273498_Vec3 fn_8028F9C8(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o, float f)
{
    Unk80273498_Vec3 pos;
    ((Unk8027A84C*)g)->fn_8027AD3C(x, o, &pos, 0, 0, 0, 0, 0);
    float heading = fn_8028FAEC(g, x, o);
    Unk80273498_Vec3 t = fn_80297614(g);
    float len = Length(t - pos);
    Unk80273498_Vec3 r = fn_8028FD38(g, heading, f, len);
    return r;
}

float fn_8028FAEC(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o)
{
    float result = 0.0f;
    if (fn_80297668(g) && (g->m18C.f8 || g->m48->m44->m10 != 10)) {
        Unk80273498_Vec3 v = fn_802976A8(g);
        result = fn_80410CE8(v.x, v.z);
        return result;
    }
    Unk80273498_Vec3 pos;
    float heading;
    ((Unk8027A84C*)g)->fn_8027AD3C(x, o, &pos, &heading, 0, 0, 0, 0);
    Unk80273498_Vec3 d = fn_80297614(g) - pos;
    Unk8028F178_Owner* root = g->m44->m0;
    if (root && ((Unk8028F178_Goal*)((Unk8027A84C_Owner*)root)->fn_8027C67C())->m28 != 0) {
        Unk80273498_Vec3 d2 =
            ((Unk8028F178_Goal*)((Unk8027A84C_Owner*)root)->fn_8027C67C())->fn_GetM10() - fn_80297614(g);
        float a1 = fn_80410CE8(d2.x, d2.z);
        float a2 = fn_80410CE8(d.x, d.z);
        float diff = AngleDiff(a1, a2);
        result = diff * 0.5f + a2;
    } else {
        result = fn_80410CE8(d.x, d.z);
    }
    return result;
}

/* near-miss: 88 of 88 instructions, 5 differ in float register numbers only: retail keeps the
 * clamped value in the register of the loaded `t` (the two constants both go through f13 and
 * `fmr f0,f13`), mine puts the ternary temp in f13. Tried ~40 forms of the clamp (if/else chains,
 * nested ternaries in both orders and with swapped operands, inline Clamp with early returns, goto
 * forms, a temp for the result); this ternary is the closest. */
Unk80273498_Vec3 fn_8028FD38(Unk8028F178_Goal* g, float angle, float a, float b)
{
    Unk80273498_Vec3 w = Direction(angle) * (a * 3.0f);
    float t = b * 0.0009259259f;
    t = t < 0.001f ? 0.001f : (t > 1.0f ? 1.0f : t);
    Scale(w, t);
    return w;
}

/* near-miss: 245 of 247 instructions. Retail's frame is 8 bytes smaller (the `sel` float lives in the freed
 * AngleDiff slot 0x30 instead of a new slot) and its final else-if chain is `andi.; beq next; li r0,N; b end`
 * where mine pre-loads the value and branches once. Tried: result variable forms, ternary chain, `sel` declared
 * before/after the AngleDiff statement, call result hoisted. */
int fn_8028FE98(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o)
{
    Unk80273498_Vec3 pos = lbl_806055AC;
    int hash = 0;
    ((Unk8027A84C*)g)->fn_8027AD3C(x, o, &pos, 0, 0, 0, &hash, 0);
    Unk80273498_Vec3 d = fn_80297614(g) - pos;
    float d2 = d.x * d.x + d.z * d.z;
    float lim = fn_80249298(x, fn_8029771C(g), 1);
    if (hash == 0xB4F5C907) {
        lim = 576.0f;
    }
    int ok1 = 1;
    if (!g->m18C.f12) {
        float v = fn_80248FC8(x, fn_80297740(g));
        ok1 = v >= ((Unk8028F178_Player*)x)->m724 + 39.37008f;
    }
    int ok2 = 0;
    if (g->m2C != 0) {
        float diff = AngleDiff(fn_80410CE8(d.x, d.z), fn_80410CE8(g->m1C.x, g->m1C.z));
        float sel = !(diff <= 0.3926991f) ? 1.0f : 0.0f;
        if (fabsf(sel) != 0.0f) {
            ok2 = 1;
        }
    }
    int avail = d2 < lim;
    if (!(d2 >= 1764.0f)) {
        avail |= 2;
    }
    if (!(d2 >= 7056.0f) && ok1) {
        avail |= 4;
    }
    if (!(d2 >= 36864.0f) && ok1 && ok2) {
        avail |= 8;
    }
    int c = fn_8026DC18(x, o);
    avail |= 0x10;
    int b0 = 1, b1 = 1, b2 = 1, b3 = 1, b4 = 1;
    if (c || fn_8026D7E0(x, o) || fn_8026D6AC(x, o)) {
        b0 = 0;
        b1 = 0;
        b2 = 0;
    }
    if (hash == 0x2D9F492A) {
        b3 = 0;
    }
    int allow = 0;
    if (b0) {
        allow |= 1;
    }
    if (b1) {
        allow |= 2;
    }
    if (b2) {
        allow |= 4;
    }
    if (b3) {
        allow |= 8;
    }
    if (b4) {
        allow |= 0x10;
    }
    int m = ((avail & allow) & ~g->m58) | g->m54;
    if (m == 0) {
        m = avail & allow;
    }
    int result;
    if (m & 1) {
        result = 1;
    } else if (m & 2) {
        result = 2;
    } else if (m & 4) {
        result = 4;
    } else if (m & 8) {
        result = 8;
    } else {
        result = ((Unk8027A84C*)g)->fn_8027B2CC(x) ? 0x20 : 0x10;
    }
    return result;
}

/* near-miss: 157 of 159 instructions, but the frame layout differs from retail (xp and the call result are
 * statement temporaries there, mine are named locals), so ~30 stack offsets differ. Tried: FlatPos/AngleTo
 * inlines with by-value and const-reference parameters, a Heading wrapper, ok/p assignment orders. */
int fn_802908FC(Unk8028F178_Goal* g, Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;
    float lim = 0.25f;
    int hash = link->m838;
    int hash2 = link->m83C;
    int p = 0;
    int ok;
    switch ((unsigned int)hash) {
    case 0xA713FF5B:
    case 0x3453C76B:
        p = 0xEA68D008;
        ok = 1;
        if (((Unk8027A84C*)g)->fn_8027B2CC(x)) {
            p = 0x0E42832C;
        }
        break;
    case 0xECC40882:
        p = 0x8BE34829;
        ok = 1;
        break;
    default:
        ok = 0;
        break;
    }
    if (ok) {
        if (hash2 == 0x2D9F492A || hash2 == 0x67A49CBA) {
            if (!(fn_80382BD8(link, 0) >= lim)) {
                Unk80279BB8 req(x);
                float out = 0.0f;
                fn_8038614C(link, &req, hash2, lbl_806242B8, &out, 0, 0, 0, 2);
                float yaw = fn_8037B1F0(&req.m0);
                Unk80273498_Vec3 xp = FlatPos(x);
                Unk80273498_Vec3 t = fn_80297614(g);
                float a = fn_80410CE8(t.x - xp.x, t.z - xp.z);
                float diff = AngleDiff(a, yaw);
                if (!(Abs(diff) <= 0.3926991f)) {
                    fn_803814A4(link, p, 0.0f, 0);
                    g->mC = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int fn_80290B78(Unk8028F178_Goal* g, Unk80270BA0_X* x)
{
    if (g->m34 <= 2 && fn_80297740(g) != 4) {
        return 0;
    }
    Unk8028F178_Owner* owner = g->m48->m44;
    Unk8028F178_Goal* ng = 0;
    if (owner->m10 == 10) {
        ng = (Unk8028F178_Goal*)owner->m18;
    }
    if (!ng) {
        return 0;
    }
    Unk80271DBC_Link* link = x->m618;
    float lim = 0.4f;
    int hash = link->m838;
    if (hash == 0x7133B4CB || hash == 0xC96D745B) {
        if (!(fn_80382BD8(link, 0) <= lim)) {
            Unk80279BB8 req(x);
            float out = 0.0f;
            fn_8038614C(link, &req, hash, lbl_806242B4, &out, 0, 0, 0, 2);
            Unk80273498_Vec3 p = GetPos(&req.m0);
            Unk80273498_Vec3 t = fn_80297614(g);
            float d2 = (p.x - t.x) * (p.x - t.x) + (p.z - t.z) * (p.z - t.z);
            if (!(d2 <= 3600.0f)) {
                fn_803814A4(link, 0xEA68D008, 0.0f, 0);
                g->mC = 0;
                return 1;
            }
        }
    }
    return 0;
}

int fn_80290D3C(Unk8028F178_Goal* g, Unk80270BA0_X* x);

int fn_80290D1C(Unk8028F178_Goal* g, Unk80270BA0_X* x)
{
    return fn_80290D3C(g, x);
}

/* near-miss: 84 of 84 instructions, 5 differ in the order of the early loads of x->m724/m728 and the
 * constants (scheduling only). Tried: operand order of the average, statement permutations, a local for it. */
void fn_80291378(Unk8028F178_Goal* g, Unk80270BA0_X* x)
{
    if (!(g->m70 > 0.0f) && g->m70 == 0.0f) {
        if (fn_8026DAE8(x, 0) || fn_8026D7B4(x, 0) || fn_8026D838(x, 0)) {
            Unk8028F178_Ctx* ctx = (Unk8028F178_Ctx*)x->m44C;
            Unk8028F178_Player* px = (Unk8028F178_Player*)x;
            float t = (float)ctx->m4C * 0.016666668f;
            float old = g->m78;
            g->m78 = (px->m728 + px->m724) * 0.5f;
            Unk80279BB8 req(x);
            fn_802977FC(g, x, &req, 1, 0, 0, 0, -1.0f);
            g->m78 = old;
            g->m70 = t + RSub(req.mD4, g->m74 - t);
        }
    }
}
