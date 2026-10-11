/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x80299920-0x8029B6C8, .rodata 0x805DDBF0-0x805DDD0C.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 *
 * Status: 18 of 25 match. Parked near-misses: fn_80299FD4, fn_8029A788, fn_8029A9A4, fn_8029AC74,
 * fn_8029B3F8, fn_8029B520 (notes above each). Not attempted: fn_8029B030 (242 instructions).
 * The 0x805DDC74 float pool (0, 1/(2*pi), 0.5, 2*pi, 100) belongs to fn_8029AC74 in retail but only
 * its first entry is used by the live code; the rest are leftovers of removed code.
 */
#include "game/chooser.h"
#include "game/goals/tu_80299920.h"

inline Vec3 operator-(Vec3 a, Vec3 b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

int Unk80299920_Goal::fn_80299920(Unk80270BA0_X* x)
{
    if (m28) {
        if (m2C) {
            float ang = fn_80410CE8(m1C.x, m1C.z);
            fn_80299B98(x, GetM10(), &ang);
        } else {
            fn_80299B98(x, GetM10(), 0);
        }
    }
    return 2;
}

void Unk80299920_Goal::fn_802999D4(float t, Unk80270BA0_X* x, Unk80299920_Req* req, int a6, Vec3* out, int unused, int n)
{
    req->mA0 = fn_80299E54(x);
    req->mBC = 10;
    req->m40 = 0.0f;
    req->fn_8037B10C(GetM10());
    req->mBC |= 1;
    if (m2C) {
        float ang = fn_80410CE8(m1C.x, m1C.z);

        req->SetScale(ang);
        req->mBC |= 1;
    }
    req->SetD0(0.0f);
    req->AddD4(0.0f);
    ((Unk8027A84C*)this)->fn_8027AC90((Unk8037B128_Mtx*)req, n, unused, out);
    req->mD8 = 1;
}

int Unk80299920_Goal::fn_80299AE8(const Unk80299920_Goal* o) const
{
    Vec3 d = o->GetM10() - GetM10();

    return d.x * d.x + d.z * d.z < 576.0f;
}

void fn_80299B98(Unk80270BA0_X* x, const Vec3& pos, float* ang)
{
    Unk80299920_XV* xv = (Unk80299920_XV*)x;
    Unk80271DBC_Link** ls = xv->m618;

    fn_80381E9C(ls[2], 0, 0, 0);
    fn_80381E9C(ls[1], 0, 0, 0);
    Unk80271DBC_Link* link = xv->m618[0];
    fn_803814A4(link, fn_80299E54(x), 0.0f, 0);
    Unk80299920_SetM8(&xv->m734, 0.0f);
    if (xv->m458 == 0 && xv->m44C->m6F4 == 7) {
        Vec3 p = pos;
        Unk8018514C_Obj* o = xv->m44C->m6B8;

        p.y = Unk8018514C_Height(o, pos);
        xv->fn_vslot3(p);
        SetVec(&xv->m320, pos);
    } else {
        xv->fn_vslot3(pos);
        SetVec(&xv->m320, pos);
    }
    xv->fn_vslot6()->fn_vslot3(pos);
    if (ang) {
        Vec3 t = lbl_806055AC;

        t.y = *ang;
        SetVec(&xv->m32C, t);
        fn_80244858(x, *ang);
    }
    xv->fn_comp13();
    fn_80249B40(x, 0.016666668f, 0, 0, 0);
}

unsigned int fn_80299E54(Unk80270BA0_X* x)
{
    switch (x->m458) {
    case 9:
        return 0x94C34DBD;
    case 10:
    case 11:
    case 12:
    case 18:
        return 0x0E42832C;
    case 0:
        return 0xFFE46816;
    case 13:
    case 17:
        return 0xB632DA95;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        return 0xEA68D008;
    }
}

void Unk80299920_Goal::fn_80299EE4()
{
    m0 = 3;
    m48 = 1;
    m4C = 0;
    m50 = 0;
    m54i = 0;
    m60 = 0;
}

Unk80299920_Goal* Unk80299920_Goal::fn_80299F0C(Vec3* v)
{
    SetVec(&m10, *v);
    m28 = 1;
    return this;
}

void Unk80299920_Goal::fn_80299F5C(Unk80299920_Tgt* t)
{
    m50 = t;
}

void Unk80299920_Goal::fn_80299F64(int v)
{
    m48 = v;
}

int Unk80299920_Goal::fn_80299F6C(Unk80299920_XV* x)
{
    if (x->m570 == 1 && m60 == 1) {
        return fn_8029A54C(x);
    }
    return fn_8029A308(x, fn_8029ADC8(m48));
}

/* near-miss (211 vs 205 instructions, registers and control flow right): retail has ONE copy of the
 * SetM48 tail shared by the clamp path and the "m48 != 0x1d" path (cross-jumped), with the wrapper
 * slots at 0x110/0x118 in both; here the else path gets its own copy in slots 0xF0/0xF8 because the
 * params record t is out of scope there. Declaring t/a/b at function scope moves them below q and
 * breaks the layout (q must come first, then a, b, t). Also differs: order of the event stores and
 * which side of the 3.0f compare is loaded first. ~12 variants tried. */
void Unk80299920_Goal::fn_80299FD4(Unk80299920_XV* x)
{
    if ((unsigned int)(m48 - 0x17) <= 1) {
        Unk80279BB8 q;
        float a = 0.0f;
        float b;

        fn_8027D3E8(m50->m934, 7, &a, 0, 0, 0);
        if (fn_8026D7B4(x, 0) == 1) {
            if (!(x->m60.x >= lbl_805DED34.x)) {
                a = a - 0.17f;
                b = 0.17f;
            }
        }
        unsigned int h = 0;
        switch (m48) {
        case 0x17:
            h = 0xF951234A;
            break;
        case 0x18:
            h = 0xB88DC566;
            break;
        }
        Unk80279BB8* qp = &q;

        b = 0.0f;
        qp->fn_80279DD0((Unk80270BA0_X*)x);
        fn_80386110(x->m618[0], qp, h, 0xA5422C1B, &b, 0);
        Unk80299920_Params t;

        t.m0 = 1.0f;
        t.m4 = 1.7f;
        t.m8 = 1.9f;
        t.mC = 1.6f;
        t.m10 = 0.5f;
        t.m14 = 3.0f;
        t.m18 = 1.0f;
        t.m1C = 0.0f;

        switch (m48) {
        case 0x17:
            t.m18 = 1.7f;
            break;
        case 0x18:
            t.m18 = 1.9f;
            break;
        }
        if (a > 0.0f) {
            t.m0 = b / a;
        } else {
            t.m0 = 99.0f;
        }
        if (!(t.m0 <= 3.0f)) {
            Unk8035E1AC ev(0x8d, (Unk80270BA0_X*)x);

            m48 = 0x19;
            ev.mC = 0;
            fn_8037893C((char*)((Unk8027A84C*)this)->fn_8027A918() + 0x704, ev.m0, &ev, 0, 0);
            float c = 0.0f;

            qp->fn_80279DD0((Unk80270BA0_X*)x);
            fn_80386110(x->m618[0], qp, 0xF1977099, 0x6A552F40, &c, 0);
            t.m18 = 1.6f;
            t.m1C = 0.5f;
            if (a > 0.0f) {
                t.m0 = c / a;
            } else {
                t.m0 = t.m18;
            }
        }
        if (t.m0 > t.m18) {
            t.m0 = t.m18;
        } else if (!(t.m0 >= t.m1C)) {
            t.m0 = t.m1C;
        }
        Unk80299920_SetM48(&x->m734, t.m0);
    } else if (m48 != 0x1d) {
        Unk80299920_SetM48(&x->m734, -1.0f);
    }
}

int Unk80299920_Goal::fn_8029A308(Unk80299920_XV* x, unsigned int hash)
{
    Unk80299920_Ctx* ctx = x->m44C;
    Unk80271DBC_Link* link = x->m618[0];
    float t = (float)ctx->m4C * 0.016666668f;
    Unk80299920_Pos* pos = ctx->m6CC;

    if (fn_80188EF4(pos) == 0) {
        if (mC <= 3) {
            fn_8029B030(x, 0, 0);
        }
        if (mC <= 2) {
            m5C = fn_80382BB8(x->m618[0]);
            fn_80299FD4(x);
            fn_8029ADC8(m48);
        } else if (m48 == 0x19) {
            fn_8024D178((Unk80270BA0_X*)x, 0);
        }
        if (mC <= 1) {
            m58 = t;
        }
        if (!(t <= m58 + 0.2f)) {
            if (fn_80188EF4(pos) == 0) {
                if (m4C != 0) {
                    fn_80249B40((Unk80270BA0_X*)x, 0.2f, m4C, 0, 0);
                    fn_80249DF8((Unk80270BA0_X*)x, 1);
                } else if (m28) {
                    Vec3 p = GetM10();

                    fn_80249958((Unk80270BA0_X*)x, &p, 0, 0.2f);
                    fn_80249DF8((Unk80270BA0_X*)x, 1);
                }
            }
        }
        int v = 3;
        if (v > mC) {
            mC = v;
        }
        int cur = link->m838;
        if (fn_80380964(link) == 0) {
            fn_80381E9C(link, hash, 0, 0);
        }
        if (cur != (int)hash && cur != (int)0xC4FBE281) {
            m5C = fn_80382BB8(x->m618[0]);
            return 1;
        }
        int w = 4;
        if (w > mC) {
            mC = w;
        }
        if (pos) {
            if (pos->m36C != (Unk80270BA0_X*)x) {
                return 0;
            }
        }
    }
    return 1;
}

int Unk80299920_Goal::fn_8029A54C(Unk80299920_XV* x)
{
    Unk80271DBC_Link* link = x->m618[0];

    fn_80381E9C(link, 0xC331A6BF, 0, 0);
    if (link->m838 == (int)0xC331A6BF) {
        if (fn_80380964(link) == 0) {
            x->m570 = 0;
            return 0;
        }
    }
    return 1;
}

float Unk80299920_Goal::fn_8029A5C4(Unk80299920_XV* x, Vec3* target, Unk8027AD3C_Obj* obj, int flag)
{
    Vec3 pos = lbl_806055AC;
    float heading = 0.0f;

    ((Unk8027A84C*)this)->fn_8027AD3C((Unk80270BA0_X*)x, obj, &pos, &heading, 0, 0, 0, 0);
    if (flag == 0) {
        switch (m48) {
        case 6:
        case 7:
        case 11:
        case 13: {
            float dist = 96.0f;
            Vec3 off = Direction(heading) * dist;

            Vec3* pp = &pos;

            pp->x = pp->x + off.x;
            pp->y = pp->y + off.y;
            pp->z = pp->z + off.z;
            break;
        }
        }
    }
    float a = fn_80410CE8(target->x - pos.x, target->z - pos.z);

    return a;
}

int Unk80299920_Goal::fn_8029A768(Unk80299920_XV* x)
{
    return fn_8029A788(x);
}

/* near-miss (116 vs 112 instructions, frame 96 vs 112): retail keeps the float locals (a, b, the angle
 * difference) below the three Vec3 temps (copy of m10, result of the subtraction, d); every declaration
 * order tried puts the Vec3 temps lowest. Heading(Vec3) wrapper and split declarations were worse. */
int Unk80299920_Goal::fn_8029A788(Unk80299920_XV* x)
{
    int v = -1;
    int r = 0;

    fn_8029AC74(0, &v);
    if (!((float)v < 0.0f)) {
        r = v;
    }
    int k = r - 1;
    if ((unsigned int)k <= 2) {
        Vec3 d = Sub(GetM10(), x->m60);
        float a = fn_80410CE8(d.x, d.z);
        float b = fn_80382BB8(x->m618[0]);
        float diff = AngleDiff(a, b);

        if (!(Unk80299920_Abs(diff) >= 1.0471977f)) {
            if (m48 == 6) {
                r = k;
            }
        }
        if (!(Unk80299920_Abs(diff) <= 1.7453294f)) {
            r = r + 1;
        }
    }
    return r;
}

float Unk80299920_Goal::fn_8029A948()
{
    float a = 60.0f;
    float b = -1.0f;

    fn_8029AC74(&b, 0);
    if (!(b < 0.0f)) {
        a = b;
    }
    return a;
}

/* near-miss (177 vs 180 instructions): the only difference is the copy chain of the position into
 * out->a. Retail has the call result at 0x38, a by-value copy at 0x28 that y and z are read from; GetPos()
 * keeps the frame size but forwards the copy through registers, a plain call or a named local
 * changes the frame. The final stores (mCC before mD8) match. */
void Unk80299920_Goal::fn_8029A9A4(float t, Unk80299920_XV* x, Unk80299920_Req* req, int k, Unk80299920_Out* out, Unk80299920_Ref* ref, int c)
{
    if (k == 1) {
        k = m0;
    }
    int flags = 0;
    unsigned int h1 = fn_8029ADC8(m48);
    unsigned int h2 = fn_8029B000(k);

    fn_8029B030(x, (Unk8027AD3C_Obj*)req, 1);
    float tmp = 0.0f;
    Unk80271DBC_Link* link = x->m618[0];

    if (mC <= 2) {
        if (fn_8026D9D0(x, req)) {
            fn_80386188(link, req, 0xC331A6BF, lbl_806242B0, &tmp, c, ref, out, 0, 0, 2);
            req->AddD4(tmp);
        }
    }
    if (!(t < 0.0f)) {
        tmp = t - req->mD4;
        if (tmp > 0.0f) {
            flags = 0x20;
        } else {
            req->mD8 = 1;
            req->SetD4(t);
            return;
        }
    }
    if (out) {
        int same = ref->m4 == lbl_8061EC9C;

        fn_80386188(link, req, h1, h2, &tmp, c, ref, out, 0, 0, flags | 2);
        if (same) {
            if (ref->m4 == lbl_8061EC9C) {
                SetVec(&out->a, GetPos(&req->mtx));
                out->b = lbl_806055AC;
                out->b.y = -1000.0f;
            }
        }
    } else {
        fn_80386110(link, req, h1, h2, &tmp, flags | 2);
    }
    req->AddD4(tmp);
    switch (m48) {
    case 2:
    case 3:
    case 6:
    case 7:
    case 11:
    case 13:
    case 0x1c:
        req->mCC = 0x1d;
        break;
    }
    req->mCC = 0x1c;
    req->mD8 = 1;
}

/* near-miss (same length, 31 of 85 slots differ): the query record's inline constructor stores. Retail
 * reaches the type nibble (+0x44) and +0xBC with direct frame offsets and +0xA0 through the pointer;
 * here all three use the pointer. Ctor statement orders (all 6) and a private copy of the record made no
 * difference. */
void Unk80299920_Goal::fn_8029AC74(float* outA, int* outB)
{
    if (m48 == 0x19) {
        if (outA) {
            *outA = 0.0f;
        }
        if (outB) {
            *outB = 0;
        }
    }
    Unk80299920_XV* p = (Unk80299920_XV*)((Unk8027A84C*)this)->fn_8027A90C();
    Unk80299920_Angles* a = &p->m734;
    unsigned int h1 = fn_8029ADC8(m48);
    unsigned int h2 = fn_8029B000(m0);
    int saved = a->m190;

    a->m190 = 0;
    a->m194 = saved;
    fn_8029B030(p, 0, 1);
    Unk8027A9AC_Req req;
    float t = 0.0f;
    Unk80386188_Result* res;
    int r = fn_80386188(p->m618[0], &req, h1, h2, &t, 0, 0, 0, 0, &res, 0);

    if (!(r & 2)) {
        if (outA) {
            *outA = res->m20;
        }
        if (outB) {
            *outB = res->m24;
        }
    }
    a->m190 = a->m194;
}

unsigned int Unk80299920_Goal::fn_8029ADC8(int kind)
{
    unsigned int h = 0;

    switch (kind) {
    case 1:
        break;
    case 2:
        h = 0x3CB4E440;
        break;
    case 3:
        h = 0xDB07F9E2;
        break;
    case 4:
        h = 0xA1BE7E8B;
        break;
    case 5:
        h = 0xC6D1F6CD;
        break;
    case 6:
        h = 0x6ED777BA;
        break;
    case 7:
        h = 0x75D8282C;
        break;
    case 8:
        h = 0xFDBC7097;
        break;
    case 9:
        h = 0xDB1EA395;
        break;
    case 10:
        h = 0xBAA6A49C;
        break;
    case 11:
        h = 0x9F158777;
        break;
    case 16:
        h = 0xF0BD397B;
        break;
    case 17:
        h = 0x79FC6B13;
        break;
    case 19:
        h = 0xD78C3087;
        break;
    case 18:
        h = 0x7AF90F46;
        break;
    case 20:
        h = 0x60605AAC;
        break;
    case 22:
        h = 0xE039EB20;
        break;
    case 21:
        h = 0xD322191F;
        break;
    case 23:
        h = 0xF951234A;
        break;
    case 24:
        h = 0xB88DC566;
        break;
    case 25:
        h = 0xF1977099;
        break;
    case 26:
        h = 0x0C1AEC03;
        break;
    case 27:
        h = 0x313F6F12;
        break;
    case 30:
        h = 0x7A4EF4D1;
        break;
    case 12:
        h = 0xF69F4563;
        break;
    case 13:
        h = 0x27A12553;
        break;
    case 28:
        h = 0xABED4526;
        break;
    case 29:
        h = 0xAADBF77D;
        break;
    }
    return h;
}

unsigned int Unk80299920_Goal::fn_8029B000(int k)
{
    unsigned int h = 0;

    switch (k) {
    case 2:
        h = lbl_806242B4;
        break;
    case 3:
        h = 0x2F71A764;
        break;
    }
    return h;
}

/* near-miss (73 vs 74 instructions): retail sets r3 = 0 before the null test and keeps both m48 == 0x1d
 * tests (the second one is not folded into the first); the distance goes through a float local. */
int Unk80299920_Goal::fn_8029B3F8(const Unk80299920_Goal* o) const
{
    if (o == 0) {
        return 0;
    }
    int k = m48;

    if (k == 0x1d) {
        if (o->m48 != 0x1d) {
            return 0;
        }
    }
    if (k == 0x19) {
        int ok = o->m48;

        if (ok != 0x18) {
            if (ok != 0x17) {
                if (ok != 0x1a) {
                    return 0;
                }
            }
        }
    }
    if (m48 == 0x1d) {
        if (o->m48 != 0x1d) {
            return 0;
        }
    }
    if (o->m60 == 1 || m60 == 1) {
        return 0;
    }
    int a = m4C;
    int b = o->m4C;

    if (a != 0 && b != 0) {
        return a == b;
    }
    float d2 = DistSq2D(GetM10(), o->GetM10());

    return d2 < 32400.0f;
}

/* near-miss (72 vs 74 instructions): retail clears flag bits 0, 3, {6,7}, {1,2}, {8,9,10} as five separate
 * rlwinm; consecutive bit-field assignments here are merged into lis/ori/and (interleaving stores, a
 * local flags copy and a pointer to the flags did not stop the merge). */
void Unk80299920_Goal::fn_8029B520()
{
    mD0.f0 = 0;
    mD0.f3 = 0;
    mD0.f6 = 0;
    mD0.f7 = 0;
    mD0.f1 = 0;
    mD0.f2 = 0;
    mD0.f8 = 0;
    mD0.f9 = 0;
    mD0.f10 = 0;
    m4C = 2;
    m0 = 2;
    m60 = 0;
    m48 = 0;
    m54 = -1.0f;
    m94 = 0.0f;
    m98 = 0.0f;
    m78 = -1.0f;
    m7C = -1.0f;
    m80 = -1.0f;
    m84 = -1.0f;
    m74 = 0.0f;
    m88 = 0.0f;
    m9C = lbl_806055AC;
    mA8 = -1.0f;
    mD0.f11 = 0;
    mAC = lbl_806055AC;
    m90 = -1;
    mD0.f12 = 0;
    mD0.f4 = 0;
    mB8 = lbl_806055DC;
    mCC = -1;
    mC8 = 0.0f;
    mD0.f5 = 1;
    m8C = -1.0f;
    mD0.f15 = 0;
    mC4 = -1;
}

Unk80299920_Goal* Unk80299920_Goal::fn_8029B648(const Vec3* v)
{
    if (!(v->x * v->x + v->y * v->y + v->z * v->z >= 0.01f)) {
        mD0.f1 = 0;
    } else {
        float a = fn_80410CE8(v->x, v->z);

        m6C = a;
        mD0.f1 = 1;
    }
    return this;
}
