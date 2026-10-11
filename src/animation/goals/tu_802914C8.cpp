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

/* near-miss (97 vs 95 instructions): flags, locals and the Lerp parameter slots
 * match; the nested-ternary clamp (r) takes other registers than retail (b in
 * f12, result in f0) and the 0.5/1.5 locals are stored before t instead of after. */
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
    float r = !(b > hi) ? (!(b >= lo) ? lo : b) : hi;
    if (m4C == 0x40) {
        float t = fn_8024D0F8(x, 0x4A);
        float a = 0.5f;
        float c = 1.5f;
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

/* near-miss (43 vs 46 instructions): retail also stores 150.0 and 0.2 at 0x18/0x1c
 * and clamps t in place in f0 with one store (a ternary or if chain stores per arm
 * or takes another register); Sign() param slot at 0x10 matches. */
float Unk802914C8_Goal::fn_80296624(float v)
{
    float sign = Sign(v);
    float t = v * 150.0f - 0.2f;
    if (t > 0.5f) {
        t = 0.5f;
    } else if (!(t >= 0.0f)) {
        t = 0.0f;
    }
    t = t * sign;
    return t;
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
