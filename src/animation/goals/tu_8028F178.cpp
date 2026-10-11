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

Unk80273498_Vec3 fn_8028FD38(Unk8028F178_Goal* g, float angle, float a, float b);
float fn_8028FAEC(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8027AD3C_Obj* o);

/* near-miss: 32 of 32 instructions, 3 differ in order only (retail spills f1 right after the first
 * lwz, mine places the stfs after `mr r11,r9`). The temps for the three root stores give retail's
 * value-before-pointer loads. Tried: owner pointer local, copy of the float parameter, local copy
 * of `a`, all three loads before the stores. */
void fn_8028F178(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8028F178_Req* r, int a, int b, int c, int d, float f)
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
    if (g->mC == 2) {
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

int fn_80290D3C(Unk8028F178_Goal* g, Unk80270BA0_X* x);

int fn_80290D1C(Unk8028F178_Goal* g, Unk80270BA0_X* x)
{
    return fn_80290D3C(g, x);
}
