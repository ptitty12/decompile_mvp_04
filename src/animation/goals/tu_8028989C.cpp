/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028989C-0x8028B194, .rodata 0x805DD640-0x805DD6DC.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028989C.h"

Unk80273498_Vec3 fn_8014E388(Unk8014E388_H* h);
int fn_8028AA4C(Unk8028989C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* q);
float fn_8028AB4C(Unk8028989C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* q, int k, float dist, Unk80273498_Vec3* out, int c,
                  int n);
void fn_8028A2E0(Unk8028989C_Goal* g, Unk80270BA0_X* x);
void fn_80289FB8(Unk8028989C_Goal* g, Unk80270BA0_X* x);
void fn_8028A05C(Unk8028989C_Goal* g, Unk80270BA0_X* x);
void fn_8028A13C(Unk8028989C_Goal* g, Unk80270BA0_X* x);
void fn_8028A21C(Unk8028989C_Goal* g, Unk80270BA0_X* x);
void fn_8028A450(Unk8028989C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* q, int sel, float dist, Unk80273498_Vec3* out, int c,
                 int n);
extern int lbl_806242B0;
extern int lbl_806242B4;

static inline Unk80273498_Vec3 GetQueryPos(Unk80279BB8* q)
{
    Unk80273498_Vec3 v = fn_8037B128(q);
    return v;
}

static inline float HeadingOf(Unk80273498_Vec3 d)
{
    return fn_80410CE8(d.x, d.z);
}

static inline Unk80273498_Vec3 FlatPos(Unk80270BA0_X* x)
{
    Unk80273498_Vec3 v = x->m60;
    v.y = 0.0f;
    return v;
}

static inline float LenSq(Unk80273498_Vec3 v)
{
    return v.x * v.x + v.z * v.z;
}

static inline Unk80273498_Vec3 VSub(Unk80273498_Vec3 a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

/* The int/float angle setters index with an explicit byte offset (retail forms
 * (m190 * 4 + const) in a register, base register kept apart). For ints the
 * first store goes through a zero index variable. */
static inline void SetAngleI(Unk802726BC_Angles* p, int v)
{
    int i = 0;
    if (p->m190 == 1) {
        int off0 = i * 4 + 88;
        *(int*)((char*)p + off0) = v;
    }
    int off = p->m190 * 4 + 88;
    *(int*)((char*)p + off) = v;
}

static inline void SetAngleF(Unk802726BC_Angles* p, float v)
{
    if (p->m190 == 1) {
        p->mC0[0] = v;
    }
    int off = p->m190 * 4 + 192;
    *(float*)((char*)p + off) = v;
}

static inline void SetAngleFb(Unk802726BC_Angles* p, float v)
{
    SetAngleF(p, v);
}

static inline void SetAngleF48(Unk802726BC_Angles* p, float v)
{
    if (p->m190 == 1) {
        p->m48[0] = v;
    }
    p->m48[p->m190] = v;
}

static inline void SetAngleF48b(Unk802726BC_Angles* p, float v)
{
    SetAngleF48(p, v);
}

static inline void SetPair(float* dst, float v)
{
    for (int i = 0; i < 2; i++) {
        dst[i] = v;
    }
}

void fn_8028989C(Unk8028989C_Goal* g)
{
    g->m0 = 6;
    g->m48 = 0;
    g->m4C = 0;
    g->m70 = 0;
    g->m64 = -1.0f;
    g->m6C = -1.0f;
    g->m54 = lbl_806055AC;
    g->m60 = 0.0f;
    g->m50 = -1.0f;
}

void fn_802898FC(Unk8028989C_Goal* g, float f)
{
    /* near-miss: retail stores the 0.1f case through f0 (fmr f0,f13) sharing
     * the store of f, and keeps the 10.0f store separate. */
    if (f > 10.0f) {
        g->m64 = 10.0f;
    } else if (f >= 0.1f) {
        g->m64 = f;
    } else {
        g->m64 = 0.1f;
    }
}

Unk8028989C_Goal* fn_80289944(Unk8028989C_Goal* g, float f, Unk8014E388_H** p, int n)
{
    /* near-miss: retail reloads all three words of w; here y and z are forwarded. */
    Unk80273498_Vec3 v = fn_8014E388(*p);
    v.y = 0.0f;
    Unk80273498_Vec3 w = v;
    g->m10 = w;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 2;
    g->m4C = n;
    return g;
}

Unk8028989C_Goal* fn_802899E8(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.z = v.z;
    g->m10.y = 0.0f;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 3;
    return g;
}

Unk8028989C_Goal* fn_80289A4C(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.z = v.z;
    g->m10.y = 0.0f;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 4;
    return g;
}

Unk8028989C_Goal* fn_80289AB0(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.z = v.z;
    g->m10.y = 0.0f;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 5;
    return g;
}

Unk8028989C_Goal* fn_80289B14(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p)
{
    Unk80273498_Vec3 v = *p;
    g->m10.x = v.x;
    g->m10.z = v.z;
    g->m10.y = 0.0f;
    g->m28 = 1;
    g->m6C = f;
    g->m48 = 6;
    return g;
}

int fn_80289B78(Unk8028989C_Goal* g)
{
    switch (g->m4C) {
    case 4:
    case 5:
    case 6:
        return 1;
    }
    return 0;
}

int fn_80289B98(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    /* near-miss: retail clamps m64 with a single store through f0 (see
     * fn_802898FC) and stores the float argument of the second SetAngleF48b
     * call in each arm of the ternary. */
    Unk80271DBC_Link* link = x->m618;
    Unk80273498_Vec3 pos = FlatPos(x);
    float t = (float)UnkCtx4C(x->m44C) * 0.016666668f;

    if (g->mC <= 2) {
        g->m54 = FlatPos(x);
        g->m60 = fn_80382BB8(x->m618);
        g->m50 = t;
        g->m68 = LenSq(VSub(g->GetM10(), g->m54));
    }
    if (g->mC <= 1 && !(g->m6C <= 0.0f)) {
        SetAngleF48b(&x->m734, -1.0f);
        Unk80279BB8 q(x);
        fn_8028A450(g, x, &q, 1, -1.0f, 0, 0, 0);
        float d = q.mD4;
        g->m64 = d / g->m6C;
        if (g->m64 > 10.0f) {
            g->m64 = 10.0f;
        } else if (g->m64 < 0.1f) {
            g->m64 = 0.1f;
        }
    }
    {
        SetAngleF48b(&x->m734, g->m64 > 0.0f ? g->m64 : -1.0f);
    }
    if (link->m838 == 0x7873C72B) {
        g->m70 = 1;
    }
    float len = LenSq(VSub(pos, g->m54));
    if (len > (((unsigned int)(g->m48 - 3) <= 3) ? g->m68 : g->m68 * 0.5f)) {
        fn_80242E6C(x);
        return 2;
    }
    if (g->mC <= 1) {
        fn_8028A2E0(g, x);
    }
    switch (g->m48) {
    case 1:
        fn_80289FB8(g, x);
        break;
    case 3:
    case 4:
        fn_8028A05C(g, x);
        break;
    case 5:
    case 6:
        fn_8028A13C(g, x);
        break;
    case 2:
        fn_8028A21C(g, x);
        break;
    }
    return 1;
}

void fn_80289FB8(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;

    if (g->mC <= 2 && g->m70 == 0) {
        float angle = fn_80410CE8(g->m1C.x, g->m1C.z);
        fn_80244858(x, angle);
    }
    fn_80381E9C(link, UNK8028989C_STATE_A, 0, 0);
    if (link->m838 == UNK8028989C_STATE_A) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

void fn_8028A05C(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    Unk80271DBC_Link* link = x->m618;
    int hash = fn_8028AA4C(g, x, 0);

    if (g->m28) {
        Unk80273498_Vec3 v = g->GetM10();
        x->m93C = g->m10;
    } else {
        x->m93C.y = -1000.0f;
    }
    if (g->mC <= 2) {
        float angle = fn_80410CE8(g->m1C.x, g->m1C.z);
        fn_80244858(x, angle);
    }
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

void fn_8028A13C(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    int hash = fn_8028AA4C(g, x, 0);
    Unk80271DBC_Link* link = x->m618;

    if (g->m28) {
        Unk80273498_Vec3 v = g->GetM10();
        x->m93C = g->m10;
    } else {
        x->m93C.y = -1000.0f;
    }
    if (g->mC <= 2) {
        float angle = fn_80410CE8(g->m1C.x, g->m1C.z);
        fn_80244858(x, angle);
    }
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

void fn_8028A21C(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    int hash = fn_8028AA4C(g, x, 0);
    Unk80271DBC_Link* link = x->m618;

    if (g->mC <= 2) {
        if (g->m28) {
            Unk80273498_Vec3 v = g->GetM10();
            x->m93C = g->m10;
        } else {
            x->m93C.y = -1000.0f;
        }
    }
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        int four = 4;
        if (four > g->mC) {
            g->mC = four;
        }
    }
}

void fn_8028A2E0(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    switch (g->m48) {
    case 1:
        break;
    case 3:
    case 5:
        SetAngleI(&x->m734, 0);
        break;
    case 4:
    case 6: {
        int v = 1;
        if (x->m458 == 0xB) {
            v = 2;
        }
        SetAngleI(&x->m734, v);
        break;
    }
    case 2:
        switch (g->m4C) {
        case 1:
            SetAngleFb(&x->m734, 0.1f);
            break;
        case 2:
            SetAngleFb(&x->m734, 0.2f);
            break;
        case 3:
            SetAngleFb(&x->m734, 0.3f);
            break;
        case 4:
            SetAngleFb(&x->m734, 0.5f);
            break;
        case 5:
            SetAngleFb(&x->m734, 0.6f);
            break;
        case 6:
            SetAngleFb(&x->m734, 0.7f);
            break;
        }
        break;
    }
}

void fn_8028A450(Unk8028989C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* q, int sel, float dist, Unk80273498_Vec3* out, int c,
                 int n)
{
    if (sel == 1) {
        sel = g->m0;
    }
    float res = 0.0f;
    float ang;
    Unk80273498_Vec3 base = lbl_805DED28[UnkX5C4(x)];
    fn_8028A2E0(g, x);
    switch (g->m48) {
    case 1: {
        ang = HeadingOf(VSub(g->GetM10(), base));
        q->SetYaw(ang);
        q->mBC |= 1;
        res = fn_8028AB4C(g, x, q, sel, dist, out, c, n);
        q->mCC = 0x11;
        break;
    }
    case 3: {
        ang = HeadingOf(VSub(g->GetM10(), base)) + 1.5707964f;
        q->SetYaw(ang);
        q->mBC |= 1;
        res = fn_8028AB4C(g, x, q, sel, dist, out, c, n);
        if (!(dist >= 0.0f)) {
            q->SetPos(g->GetM10());
            q->mBC |= 1;
        }
        q->mCC = 0x11;
        break;
    }
    case 4: {
        ang = HeadingOf(VSub(g->GetM10(), base)) + 1.5707964f;
        q->SetYaw(ang);
        q->mBC |= 1;
        res = fn_8028AB4C(g, x, q, sel, dist, out, c, n);
        q->mCC = 0x11;
        break;
    }
    case 5: {
        ang = HeadingOf(VSub(g->GetM10(), base)) - 1.5707964f;
        q->SetYaw(ang);
        q->mBC |= 1;
        res = fn_8028AB4C(g, x, q, sel, dist, out, c, n);
        if (!(dist >= 0.0f)) {
            q->SetPos(g->GetM10());
            q->mBC |= 1;
        }
        q->mCC = 0x12;
        break;
    }
    case 6: {
        ang = HeadingOf(VSub(g->GetM10(), base)) - 1.5707964f;
        q->SetYaw(ang);
        q->mBC |= 1;
        res = fn_8028AB4C(g, x, q, sel, dist, out, c, n);
        q->mCC = 0x12;
        break;
    }
    case 2:
        res = fn_8028AB4C(g, x, q, sel, dist, out, c, n);
        if (!(dist >= 0.0f)) {
            q->SetPos(g->GetM10());
            q->mBC |= 1;
        }
        q->mCC = 0x12;
        break;
    }
    q->SetPos(g->GetM10());
    q->mD8 = 1;
    q->mBC |= 1;
}

int fn_8028AA4C(Unk8028989C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* q)
{
    int hash = 0;

    switch (g->m48) {
    case 1:
        hash = 0x75027FEF;
        break;
    case 3:
        hash = 0x152396E5;
        break;
    case 4:
        hash = 0xB6129A0D;
        break;
    case 5:
        hash = 0xB98F3D5B;
        break;
    case 6:
        hash = 0x785EA583;
        break;
    case 2:
        hash = fn_80289B78(g) ? 0x78B61236 : 0x2F10F625;
        break;
    }
    return hash;
}

int fn_8028AB04(Unk8028989C_Goal* g, int k)
{
    int r = 0;

    switch (k) {
    case 6:
        if (g->m48 == 2) {
            r = 0xCF4ABDEE;
        } else {
            r = lbl_806242B4;
        }
        break;
    case 2:
        r = lbl_806242B4;
        break;
    }
    return r;
}

float fn_8028AB4C(Unk8028989C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* q, int k, float dist, Unk80273498_Vec3* out, int c,
                  int n)
{
    /* near-miss (5 insns): the dist spill sits after the parameter moves; retail
     * tests dist < 0.0f with `blt` twice (a dead second branch). */
    float rem = 0.0f;
    int flags = 0;
    int s22 = fn_8028AB04(g, k);
    int hash = fn_8028AA4C(g, x, q);

    if (!(dist < 0.0f)) {
        rem = dist - q->mD4;
        if (!(rem > 0.0f)) {
            q->mD8 = 1;
            q->SetD4(dist);
            if (out) {
                for (int i = 0; i < n; i++) {
                    out[i] = GetQueryPos(q);
                }
            }
            return 0.0f;
        }
        flags = 0x20;
    }
    float tmp = rem;
    fn_80386188(x->m618, q, hash, lbl_806242B0, &tmp, n, c, out, 0, 0, flags | 2);
    rem -= tmp;
    q->AddD4(tmp);
    if (!(dist >= 0.0f && rem <= 0.0001f)) {
        if (g->m28) {
            q->mA4 = g->GetM10();
            flags |= 0x10;
            q->mBC |= 0x10;
        }
        fn_80386188(x->m618, q, hash, s22, &rem, n, c, out, 0, 0, flags | 0xA);
        q->mBC &= ~0x10;
        q->AddD4(rem);
    }
    q->mD8 = 1;
    return rem;
}

int fn_8028ADB8(Unk8028989C_Goal* g, Unk8028989C_Goal* o, float f, Unk80270BA0_X* x)
{
    if (o && o->m28 && g->m28) {
        fn_80249298(x, g->m40, 1);
        Unk80273498_Vec3 a = o->GetM10();
        Unk80273498_Vec3 b = g->GetM10();
        if ((a.x - b.x) * (a.x - b.x) + (a.z - b.z) * (a.z - b.z) < f) {
            return 1;
        }
    }
    return 0;
}

int fn_8028AE80(Unk8028989C_Goal* g, Unk80270BA0_X* x)
{
    /* near-miss: the second return-0 of the last check gets its own `li r3,0` (10 insns) */
    Unk80271DBC_Link* link = x->m618;
    int hash;
    float c;

    fn_80249B40(x, 0, 0, 0, 0.1f);
    if (g->m48 == 3) {
        fn_80381E9C(link, 0xA1183B01, 0, 0);
        return x == ((Unk8028989C_Obj36C*)x->m44C->m6CC)->m36C;
    }
    hash = link->m838;
    if (hash == (int)0xA1183B01) {
        if ((unsigned int)(g->m48 - 1) <= 1) {
            if (g->m48 == 1) {
                c = 0.0f;
                SetPair(x->m734.mF8, c);
            } else {
                c = 1.0f;
                SetPair(x->m734.mF8, c);
            }
            fn_80381E9C(link, 0x225A007B, 0, 0);
            return 0;
        }
        fn_80381E9C(link, 0xCE8E4E29, 0, 0);
    } else if (hash != (int)0xCE8E4E29) {
        if (hash != 0x225A007B) {
            fn_80381E9C(link, 0xA1183B01, 0, 0);
        }
    }
    if (hash == (int)0xCE8E4E29) {
        if (fn_8027A8F0(g)->m10 == 4) {
            float v = fn_80382BD8(link, 0);
            if (v < 0.0f) {
                return 0;
            } else if (v > 0.98f) {
                return 0;
            }
            return 1;
        }
        return 0;
    }
    return 1;
}

int fn_8028B068(Unk8028989C_Goal* g, float* out)
{
    Unk8035EB7C q;

    q.m44 = 0;
    q.Init();
    *out = 0.0f;
    q.mBC = 0;
    if (!fn_8027A90C(g) || !fn_8027A90C(g)->m618) {
        return 0;
    }
    return !(fn_80386110(fn_8027A90C(g)->m618, &q, 0xA1183B01, 0x2F71A764, out, 0) & 0x10000);
}

void fn_8028B12C(Unk8028989C_Goal* g)
{
}

int fn_8028B130(Unk8028989C_Goal* g)
{
    return 0;
}

void fn_8028B138(Unk8028989C_Goal* g)
{
}

void fn_8028B13C(Unk8028B13C_Obj* g)
{
    /* near-miss: m0 = 5 and the mA8 mask are stored in the other order (4 insns) */
    g->m4C = 0;
    g->mA8 &= 0x1FFF;
    g->m48 = 0x1A;
    g->m50 = -1;
    g->m5C = -1000.0f;
    g->m60 = -1000.0f;
    g->m78 = 0;
    g->m64 = -1000.0f;
    g->m70 = -1.0f;
    g->m90 = 0;
    g->m0 = 5;
}
