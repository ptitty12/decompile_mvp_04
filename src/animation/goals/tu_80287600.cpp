/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x80287600-0x8028989C, .rodata 0x805DD54C-0x805DD640.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/goals/tu_80287600.h"

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline float LengthSq(Unk80273498_Vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline Unk80273498_Vec3 operator*(const Unk80273498_Vec3& v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline Unk80273498_Vec3 Normalize(const Unk80273498_Vec3& v, float len)
{
    float inv = 1.0f / len;
    Unk80273498_Vec3 r;
    r.x = v.x * inv;
    r.y = v.y * inv;
    r.z = v.z * inv;
    return r;
}

inline void SetVec(Unk80273498_Vec3* dst, Unk80273498_Vec3 v)
{
    *dst = v;
}

inline void Scale(Unk80273498_Vec3* v, float s)
{
    v->x = v->x * s;
    v->y = v->y * s;
    v->z = v->z * s;
}

/* near-miss (302 vs 295 instructions): the [0,1] clamp is the >? form and the
 * operator* factors are literals (their float parameters live in the inline
 * frames, retail's 0x68/0x90 slots). Left: the frame is 8 bytes bigger, the
 * d == 3 temporaries land in other slots, and the Vec4 build after the loop
 * (four (float)(signed char) conversions) is scheduled differently. Tried:
 * rec/no rec variable, operator* by value/reference, named temporaries, a
 * nested block for len, plain instead of const frame/two. */
Unk80287600_Vec4 fn_80287600(Unk80270BA0_X* x, int a, int b, int c, int d, float* e)
{
    int idx = fn_802871D8(a);
    Unk80287600_Rec* rec = &lbl_806E07E0[idx];
    int count = rec->count;
    float pos[2];

    fn_802872AC(pos, idx, b, c, d);
    if (a == 7) {
        pos[0] = *e * 0.15915494f + 0.5f;
        pos[0] = !(pos[0] > 1.0f) ? (pos[0] >? 0.0f) : 1.0f;
    }
    if (x->fn_vslot4()) {
        pos[0] = 1.0f - pos[0];
    }

    float da;
    float db;
    float d2;
    float bestd = 10.0f;
    const float inv255 = 0.003921569f;
    int best = -1;
    Unk80287600_Entry* p = rec->e;

    for (int i = 0; i < count; i++) {
        da = (float)p->m4 * inv255 - pos[0];
        db = (float)p->m5 * inv255 - pos[1];
        d2 = da * da + db * db;
        if (!(d2 >= bestd)) {
            bestd = d2;
            best = i;
        }
        p++;
    }

    Unk80287600_Vec4 v;
    const float frame = 0.016666668f;
    const float two = 2.0f;

    v.w = (float)lbl_806E07E0[idx].e[best].m3 * frame;
    v.x = two * (float)lbl_806E07E0[idx].e[best].m0;
    v.y = two * (float)lbl_806E07E0[idx].e[best].m1;
    v.z = two * (float)lbl_806E07E0[idx].e[best].m2;
    if ((unsigned int)(c - 4) <= 2) {
        if ((unsigned int)(d - 2) <= 1) {
            v.y = -v.y;
        }
    } else if (d == 3) {
        float len = fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
        Unk80273498_Vec3 n;

        if (len != 0.0f) {
            n = Normalize(v, len);
        } else {
            n = lbl_806055AC;
        }
        Unk80273498_Vec3 off = (n * 1.0f) * 12.0f;

        v.x = v.x + off.x;
        v.y = v.y + off.y;
        v.z = v.z + off.z;
    }
    fn_80287A9C(x, &v);
    return v;
}

void fn_80287A9C(Unk80270BA0_X* x, Unk80273498_Vec3* v)
{
    if (x->fn_vslot4()) {
        v->x = -v->x;
    }
    float s = x->mAB4;
    Scale(v, s);
}

/* The goal's "kind" reset. */
void Unk80287D70::fn_80287B2C()
{
    m0 = 0;
    m48 = 0;
}

int Unk80287D70::fn_80287B3C(Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;

    if (m48 == 1) {
        if (!(fn_80382BD8(link, 0) >= 1.0f)) {
            return 1;
        }
    }
    x->fn_vslot8(1);
    return 0;
}

void Unk80287D70::fn_80287BB8()
{
    m4C = 0;
}

int Unk80287D70::fn_80287BC4(Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;

    if (m4C == 0) {
        m4C = 1;
        if (link->m838 == m48) {
            fn_803814A4(link, m48, 0.0f, 0);
        } else {
            fn_80381E9C(link, m48, 0, 0);
        }
    }
    if (link->m838 != m48) {
        return 1;
    }
    return x->m44C->m6F4 == 3 ? 2 : 0;
}

void Unk80287D70::fn_80287C70(float t, Unk80270BA0_X* x, Unk80287C70_State* st, int a3, int a4, int a5, int a6)
{
    float dt = 0.0f;
    int ev = lbl_806242B4;
    int flags = 0;

    if (!(t < 0.0f)) {
        dt = t - st->mD4;
        if (dt > 0.0f) {
            flags = 0x20;
        } else {
            float v = t;

            st->mD8 = 1;
            st->mD4 = v;
            return;
        }
    }
    fn_80386188(x->m618, st, m48, ev, &dt, a6, a5, a4, 0, 0, flags | 2);
    float v = dt;

    st->mD8 = 1;
    st->mD4 = st->mD4 + v;
}

void Unk80287D70::fn_80287D50(int v)
{
    m48 = v;
}

int Unk80287D70::fn_80287D58(Unk80287D70* o)
{
    return o->m48 == m48;
}

void Unk80287D70::fn_80287D70()
{
    m0 = 0;
    m48 = 0;
    m4C = -1;
    m50 = -1;
    m54 = lbl_806055AC;
    m60 = 0;
    m64 = 0;
}

Unk80287D70* Unk80287D70::fn_80287DB8(int kind)
{
    if (fn_8027A90C()->m458 > 8) {
        fn_8027A90C();
    }
    m48 = kind;
    return this;
}

void Unk80287D70::fn_80287E04(int v)
{
    m50 = v;
}

void Unk80287D70::fn_80287E0C(int v, const Unk80273498_Vec3* pos)
{
    m54 = *pos;
    m60 = 1;
    fn_80287E04(v);
}

int Unk80287D70::fn_80287E54(Unk80270BA0_X* x)
{
    if (fn_80380964(x->m618) == 0) {
        if (m48 == 0) {
            m48 = fn_80289268();
        }
        if (x->m458 >= 0 && x->m458 <= 8) {
            fn_8027AFA8(x->m44C, x, 0);
        }
        if (m4C == 1) {
            fn_80288658(x);
        }
        if (m4C == -1 || m4C == 0) {
            fn_80287F00(x);
        }
    }
    return 1;
}

float Unk80287D70::fn_80288E88(Unk80270BA0_X* x)
{
    float a = fn_80410CE8(m1C.x, m1C.z);

    if (m48 == 7) {
        float b = 0.0f;

        if (x->fn_vslot23()) {
            b = -b;
        }
        a = a - b;
    }
    return a;
}

/* near-miss (195 vs 196 instructions, ~96%). The extra `case 0/1/2:` labels make
 * g++ balance the case tree around 8 as retail does (as in fn_80289268). Left:
 * the ctx pointer `c` lands in r6 instead of r3, and retail's case 9 shares one
 * `r = 0x94C34DBD` block between the "not 2" and "predicate failed" paths with
 * the success block first; here the success path is inverted (ble) and
 * `r = 0x18A18DEB` is hoisted above the compare. Tried: if/else (duplicates the
 * constant), goto, repeating x->m44C->m6CC (worse). */
unsigned int Unk80287D70::fn_80288F1C(Unk80270BA0_X* x, int kind)
{
    Unk80271DBC_Link* link = x->m618;
    int h0 = link->m838;
    int h1 = link->m83C;
    unsigned int r;

    switch (kind) {
    case 8:
        r = 0xFFE46816;
        break;
    case 9: {
        Unk80273498_Pos* c = x->m44C->m6CC;

        if (c->m38C == 2) {
            Unk80273498_Vec3 p = c->m60;

            p.y = 0.0f;
            float len2 = LengthSq(p - lbl_805DED4C);
            if (!(len2 >= 9216.0f)) {
                r = 0x0AB6992B;
                break;
            }
            float a = c->m3F4;
            float b = fn_80190F0C();

            if (fn_801D0294((char*)x->m44C->m700->m3A4 + 0x28C) == 0 && !(a > b)) {
                r = 0x18A18DEB;
                break;
            }
        }
        r = 0x94C34DBD;
        break;
    }
    case 6:
        r = 0xEFF17291;
        break;
    case 12:
        r = 0x0AA2B889;
        break;
    case 13:
        r = 0x63A1DF0F;
        break;
    case 14:
        r = 0x180E3998;
        break;
    case 15:
        r = 0x7A3DB77D;
        break;
    case 10:
        r = 0x0E42832C;
        break;
    case 11:
        r = 0x8BE34829;
        break;
    case 7:
        if (h0 == (int)0xFA52B1B5 || h0 == 0xA84A0C58 || h0 == (int)0xF90D27A1 || h0 == 0x7942CA79) {
            r = 0x7942CA79;
        } else {
            r = 0xFA52B1B5;
            SetVec(&x->m948, fn_80289334());
        }
        break;
    case 5:
        if (h0 == (int)0xEA68D008 || h1 == (int)0xACA0284C) {
            r = 0xACA0284C;
            break;
        }
        r = 0xEA68D008;
        break;
    case 3:
    case 4:
        r = 0xBC3E4517;
        break;
    case 0:
    case 1:
    case 2:
    default:
        r = 0xEA68D008;
        break;
    }
    if (fn_8026D6AC(x, 0) != 0 && ((unsigned int)(kind - 1) <= 1 || kind == 5)) {
        r = h1;
    }
    return r;
}

unsigned int Unk80287D70::fn_8028922C(int a, int kind)
{
    return kind == 7 ? 0xF90D27A1u : 0xB4F5C907u;
}

int fn_80289248(Unk80270BA0_X* x)
{
    return x->m618->m838 == 0x94C34DBD;
}

int Unk80287D70::fn_80289268()
{
    int kind = m48;

    if (kind == 0) {
        switch (fn_8027A90C()->m458) {
        case 0:
            return 8;
        case 9:
            if (fn_8027A90C()->m594 == 0.0f) {
                return 9;
            }
        case 10:
        case 11:
        case 12:
        case 18:
            return 10;
        case 1:
            return 12;
        case 6:
        case 7:
        case 8:
            return 2;
        case 2:
        case 3:
        case 4:
        case 5:
        default:
            return 1;
        }
    }
    return kind;
}

Unk80273498_Vec3 Unk80287D70::fn_80289334()
{
    if (m60 == 1) {
        return m54;
    }
    return lbl_805DED28[m50];
}

float Unk80287D70::fn_80289390()
{
    float r = 0.39269912f;

    if (m48 == 7) {
        r = 0.087266475f;
    }
    if (m38 == 1) {
        r = r + r;
    }
    return r;
}

int Unk80287D70::fn_80289808(Unk80287D70* o)
{
    if (fn_80289268() != o->fn_80289268() || o->m38 != m38) {
        return 0;
    }
    if (o->m2C != 0) {
        fn_8027A898(o->GetM1C());
    }
    return 1;
}
