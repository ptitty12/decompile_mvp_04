/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x802914C8-0x80296C78, .rodata 0x805DD938-0x805DDB58, .data 0x8061E778-0x8061E794.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_802914C8.h"

int Unk802914C8_Goal::fn_802914C8(Unk80270BA0_X* x)
{
    if (!fn_8026D9D0(x, 0) && !fn_8026D890(x, 0) && !fn_8026D940(x, 0)) {
        if (fn_8029543C(x)) {
            return 2;
        }
    } else {
        fn_80296924(x);
    }
    return 1;
}

int Unk802914C8_Goal::fn_802931B0(Unk80270BA0_X* x)
{
    return fn_802931D0(x);
}

/* `if (lo > v) v = lo;` with lo an inline parameter: the constant 3 stays in a
 * register for both the compare and the store (retail li r9,3; cmpw r9,r0). */
inline void AtLeast(int& v, int lo)
{
    if (lo > v) {
        v = lo;
    }
}

/* near-miss (339 vs 339 instructions, 5 differ): only the final `mC = 4` picks
 * r9/r0 the other way round (retail: m190 index r9, the 4 in r0). sched1 hoists
 * the li 4 to the top of the last block, which gives it the longer local-alloc
 * range. Passing the pointer unflagged to the last SetPairF fixes it but breaks
 * the alias-based scheduling of the earlier stores. Needed here: LengthR
 * (reference param), `hashB = link->m838; int h = hashB;`, a second inline
 * level in SetPairF (parameter slots 8 bytes apart), AtLeast. Tried: mC = 4
 * via a variable, an inline setter, a Finish inline, store first. */
int Unk802914C8_Goal::fn_802931D0(Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;
    if (mC <= 2) {
        fn_80380964(link);
    }
    Vec3 pos;
    float heading;
    int hashB;
    fn_8027AD3C(x, 0, &pos, &heading, 0, 0, &hashB, 0);
    float f24 = fn_80249298(x, fn_8029771C(), 0);
    float f28 = fn_802958F4(x, 0, -1.0f);
    Vec3 d = VSub(fn_80297614(), pos);
    float dist = LengthR(d);
    float ang = fn_80410CE8(d.x, d.z);
    float f68 = fn_802963C4(x, 0, ang);
    if (!fn_8026D9D0(x, 0) && !fn_8026D890(x, 0) && !fn_8026D940(x, 0) && !(dist >= f24)) {
        if (fn_8029543C(x)) {
            return 2;
        }
        return 1;
    }
    if (mC <= 1) {
        if (fn_802908FC(x)) {
            return 1;
        }
        int r = fn_80290274(m4C, x, 0);
        if (r == 2) {
            m50 = r;
            return 1;
        }
    }
    int z = fn_80290B78(x);
    if (z != 0) {
        return 1;
    }
    int k = fn_80296998(m4C, hashB);
    float res = -1.0f;
    if (mC <= 2) {
        float v1 = fn_802962D0(x, 0);
        res = fn_80296030(x, heading, v1, f68, ang, f28, -1.0f);
    }
    fn_80381E9C(link, k, 0, 0);
    hashB = link->m838;
    int h = hashB;
    if (h != k) {
        if (h == (int)0xECC40882 || h == (int)0x858075AA || h == 0x3453C76B || h == 0x44D39191
            || h == (int)0xA713FF5B || h == (int)0xCA0C5FC1) {
            if (mC <= 2) {
                SetPairF((Unk802914C8_Angles*)((char*)x + 0x734), 0x48, res);
            }
            AtLeast(mC, 3);
        } else if (h == 0x193EE819) {
            SetPairF((Unk802914C8_Angles*)((char*)x + 0x734), 0x48, -1.0f);
        }
        return 1;
    }
    m50 = z;
    if (mC <= 3) {
        int r = fn_80290274(m4C, x, 0);
        m50 = r;
        if (r == 1 || r == 4) {
            mC = z;
            return 1;
        }
    }
    if (mC > 3 && m88 != 0.0f) {
    } else {
        Vec3 v;
        float outF = 0.0f;
        fn_8027A9AC(x, k, lbl_806242B4, &outF, (int)&v, 0, 0);
        v.y = 0.0f;
        m88 = LengthR(v) / outF;
    }
    Unk802914C8_Angles* a = (Unk802914C8_Angles*)((char*)x + 0x734);
    float q = f28 / m88;
    SetPairF(a, 0x48, q);
    SetPairF(a, 0x8, f28);
    fn_80244858(x, ang);
    SetPairF(a, 0, 0.0f);
    mC = 4;
    return 1;
}

float Unk802914C8_Goal::fn_8029589C(Unk80270BA0_X* x, Unk8027AD3C_Obj* o)
{
    float r = -1.0f;
    if (m18C & 0x40000) {
        r = fn_80249188(x, m80);
    } else {
        r = fn_80295A70(x, o, -1, 0);
    }
    return r;
}

/* The clamp is the >? form; the Lerp bounds are const float locals (stored
 * after the computation, which keeps their registers). */
float Unk802914C8_Goal::fn_802958F4(Unk80270BA0_X* x, Unk8027AD3C_Obj* o, float b)
{
    if (!(b >= 0.0f)) {
        b = fn_8029589C(x, o);
    }
    float lo = fn_80248FC8(x, 0);
    float hi = ((Unk802914C8_X*)x)->m72C;
    if (!(m7C <= 0.0f)) {
        hi = m7C;
    }
    if (m4C != 2 && m4C != 4) {
        if (!(m78 <= 0.0f)) {
            lo = m78;
        }
    }
    if (fn_IsF16() && !fn_IsF17() && o == 0) {
        hi *= 1.15f;
    }
    float r = !(b > hi) ? (b >? lo) : hi;
    if (m4C == 0x40) {
        float t = fn_8024D0F8(x, 0x4A);
        const float a = 0.5f;
        const float c = 1.5f;
        float m = Lerp(a, t, c);
        r *= m;
    }
    return r;
}

int Unk802914C8_Goal::fn_80295F90(Unk80270BA0_X* x, float t)
{
    Unk802914C8_X* v = (Unk802914C8_X*)x;
    float a = v->m720;
    float b = v->m724;
    float c = v->m728;
    float d = v->m72C;
    float m1 = (a + b) * 0.5f;
    float m2 = (b + c) * 0.5f;
    float m3 = (c + d) * 0.5f;
    if (!(t >= m1)) {
        return 0;
    }
    int r = 2;
    if (!(t >= m2)) {
        r = 1;
    }
    return r;
}

/* near-miss (168 vs 168 instructions, 22 differ): slots match (SetPairF with two
 * inline levels, AngleDiff computed into `ad` before the call) and the final
 * clamp is the >? form. Left: sched1 puts each inline parameter `stfs` (and the
 * AngleDiff parameter stores) before the preceding stwx/stfsx through `a`;
 * retail lets the frame loads pass that store but not the frame stores. Without
 * the `a` local (unflagged pointer) nothing passes. 8 attempts + pointer forms. */
float Unk802914C8_Goal::fn_80296030(Unk80270BA0_X* x, float f1, float f2, float f3, float f4, float f5, float f6)
{
    Unk802914C8_Angles* a = (Unk802914C8_Angles*)((char*)x + 0x734);
    int ret = fn_8027BA64(f1, f4, f3);
    SetPairI(a, 0x158, ret);
    SetPairF(a, 0x10, f2);
    SetPairF(a, 0x140, f2);
    int r2 = fn_80295F90(x, f5);
    SetPairI(a, 0x18, r2);
    SetPairF(a, 0x8, f5);
    float ad = AngleDiff(f3, f4);
    SetPairF(a, 0x100, ad);
    float res = -1.0f;
    if (f18C.f12) {
        Unk802914C8_X* v = (Unk802914C8_X*)x;
        float lo = (v->m720 + v->m724) * 0.5f;
        float hi = v->m728;
        res = 1.0f;
        float q = f5 / lo;
        if (q < 1.0f) {
            res = q;
        } else {
            float q2 = f5 / hi;
            if (!(q2 <= 1.0f)) {
                res = q2;
            }
        }
        res = !(res > 2.0f) ? (res >? 0.5f) : 2.0f;
    }
    return res;
}

float Unk802914C8_Goal::fn_802962D0(Unk80270BA0_X* x, Unk8027AD3C_Obj* o)
{
    Vec3 pos;
    float heading;
    int hash;
    fn_8027AD3C(x, o, &pos, &heading, 0, 0, &hash, 0);
    float speed = 0.0f;
    if (hash == (int)0x8BE34829 || hash == 0x152396E5 || hash == (int)0xB98F3D5B || hash == (int)0xBC3E4517) {
        speed = 24.0f;
    }
    float r = fn_802964C4(pos, fn_80297614(), heading, speed);
    return r;
}

float Unk802914C8_Goal::fn_802963C4(Unk80270BA0_X* x, Unk8027AD3C_Obj* ob, float f)
{
    float r = f;
    Unk8027A84C_Owner* o = m48->m44;
    if (o->m10 == 6) {
        Unk80273498_Pos* p = x->m44C->m6CC;
        if (p) {
            Vec3 v;
            fn_8027AD3C(x, ob, &v, 0, 0, 0, 0, 0);
            Vec3 d = VSub(p->m60, v);
            r = fn_80410CE8(d.x, d.z);
        }
    } else if (fn_80297668()) {
        Vec3 v = fn_802976A8();
        r = fn_80410CE8(v.x, v.z);
    }
    return r;
}

float Unk802914C8_Goal::fn_802964C4(Vec3 pos, Vec3 target, float angle, float speed)
{
    if (speed != 0.0f) {
        Vec3 step = VScale(Direction(angle), speed);
        pos.x += step.x;
        pos.y += step.y;
        pos.z += step.z;
    }
    Vec3 d = VSub(target, pos);
    float r = fn_80410CE8(d.x, d.z);
    return r;
}

/* The scale and offset are const float locals: stored once (0x18, 0x1c) while
 * the fmsubs keeps using their registers. The clamp is the >? form. */
float Unk802914C8_Goal::fn_80296624(float v)
{
    float sign = Sign(v);
    const float k = 150.0f;
    const float c = 0.2f;
    float t;
    t = v * k - c;
    t = !(t > 0.5f) ? (t >? 0.0f) : 0.5f;
    t = t * sign;
    return t;
}

/* The by-value Vec3 operands are copied inside inlines (FlatPos60, Diff10), so
 * the copies into the parameter slots use direct sp-relative stores, as in
 * retail (PATTERNS, "Vec3 copy destination addressing"). */
inline Vec3 FlatPos60(Unk80270BA0_X* x)
{
    return Flatten(x->m60);
}

inline Vec3 Diff10(Unk802914C8_Goal* g, const Vec3& p)
{
    return VSubV(g->fn_Pos10(), p);
}

float Unk802914C8_Goal::fn_802966DC(Unk80270BA0_X* x)
{
    Unk802914C8_X* v = (Unk802914C8_X*)x;
    float r = 0.7853982f;
    if (fn_8027B2CC(x)) {
        r = 2.3561947f;
        return r;
    }
    Unk8027A84C_Owner* o = m48->m44;
    Unk802914C8_Goal* s = 0;
    if (o->m10 == 10) {
        s = (Unk802914C8_Goal*)o->m18;
    }
    if (s != 0) {
        switch (s->m4C) {
        case 2:
        case 0x16:
        case 0x17:
            r = 1.3962636f;
        }
    }
    o = m48->m44;
    Unk802914C8_Goal* g6 = 0;
    if (o->m10 == 6) {
        g6 = (Unk802914C8_Goal*)o->m18;
    }
    if (g6 != 0 && f18C.f12 && m28 != 0) {
        Vec3 pp = FlatPos60(x);
        float t = (float)x->m44C->m4C * 0.016666668f;
        float rem = m74 - t;
        if (!(rem <= 0.5f)) {
            float dist = Length(Diff10(this, pp));
            float sp = dist / rem;
            float lim = (v->m728 + v->m72C) * 0.5f;
            if (!(sp <= lim)) {
                r = 1.3962636f;
            }
        }
    }
    return r;
}

void Unk802914C8_Goal::fn_80296924(Unk80270BA0_X* x)
{
    Unk80271DBC_Link* l = x->m618;
    if (x->m458 == 9) {
        if (((Unk802914C8_X*)x)->m5BC == -1) {
            fn_80381E9C(l, (int)0x94C34DBD, 0, 0);
        } else {
            fn_80381E9C(l, 0x0E42832C, 0, 0);
        }
    } else {
        fn_80381E9C(l, (int)0xEA68D008, 0, 0);
    }
}

int Unk802914C8_Goal::fn_80296998(int kind, int h)
{
    int r = 0;
    switch (kind) {
    case 2:
        r = 0x58A2B20F;
        break;
    case 4: {
        r = 0x12A7B064;
        Unk8027A84C_Owner* o = m48->m44;
        Unk80283934_Goal* s = 0;
        if (o->m10 == 6) {
            s = (Unk80283934_Goal*)o->m18;
        }
        if (s && fn_80285498(s)) {
            r = (int)0xEF34393E;
        }
        break;
    }
    case 8:
        if (h == (int)0xC96D745B || h == 0x7133B4CB || h == (int)0x8EF65025) {
            r = (int)0xEA68D008;
        } else if (h == 0x3453C76B || h == 0x44D39191) {
            r = 0x2D9F492A;
        } else {
            r = 0x67A49CBA;
        }
        break;
    case 0x10:
    case 0x20:
        if (h == (int)0xC96D745B || h == 0x7133B4CB || h == (int)0x8EF65025) {
            r = (int)0xEA68D008;
        } else if (h == (int)0xA713FF5B || h == (int)0xCA0C5FC1) {
            r = 0x67A49CBA;
        } else {
            r = 0x2D9F492A;
        }
        break;
    case 0x40:
        r = 0x6A939117;
        break;
    case 1:
    case 0x80:
        r = 0;
        break;
    }
    return r;
}

int Unk802914C8_Goal::fn_80296B4C(int kind, int* out)
{
    int n = 0;
    switch (kind) {
    case 1:
        fn_80296C60(out, (int)0xEA68D008, &n);
        fn_80296C60(out, 0x0E42832C, &n);
        break;
    case 2:
        fn_80296C60(out, 0x58A2B20F, &n);
        break;
    case 4:
        fn_80296C60(out, 0x12A7B064, &n);
        break;
    case 8:
        fn_80296C60(out, 0x67A49CBA, &n);
        break;
    case 0x10:
    case 0x20:
        fn_80296C60(out, 0x2D9F492A, &n);
        break;
    case 0x40:
    case 0x80:
        break;
    }
    return n;
}

void Unk802914C8_Goal::fn_80296C60(int* arr, int value, int* count)
{
    arr[(*count)++] = value;
}
