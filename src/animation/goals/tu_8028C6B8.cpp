/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028C6B8-0x8028F178, .rodata 0x805DD754-0x805DD848, .data 0x8061E700-0x8061E778.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028C6B8.h"

#define REACHGOAL_FILE "C:/mvp2004/source/common/animation/goals/reachgoal.cpp"

/* .data 0x8061E700 (this unit's split): squared distances indexed by Goal::m4C
 * (read by fn_8028E9E8) and the word at 0x8061E76C (read by fn_8028DB44). */
float lbl_8061E700[27] = {
    23963.037f, 23963.037f, 16796.162f, 10404.0f, 17108.637f, 0.0f, 0.0f, 3600.0f, 3600.0f,
    5715.361f, 7056.0f, 57600.0f, 49818.246f, 30695.045f, 29036.158f, 48224.156f, 57600.0f, 8100.0f,
    30276.0f, 1383.8397f, 3600.0f, 36864.0f, 3600.0f, 3600.0f, 3600.0f, 3600.0f, 0.0f
};
int lbl_8061E76C = 1;

extern Unk80273498_Vec3 lbl_805DED4C;       /* 7.5, 0, 7.5 (preceded by 1072.5, 0, 7.5) */

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

/* Cross product with by-value parameters, as fn_8028D8D8 uses it. */
inline Unk80273498_Vec3 Unk8028D8D8_Cross(Unk80273498_Vec3 a, Unk80273498_Vec3 b)
{
    Unk80273498_Vec3 r;
    r.x = b.y * a.z - a.y * b.z;
    r.y = a.x * b.z - b.x * a.z;
    r.z = b.x * a.y - a.x * b.y;
    return r;
}

void Unk8028C6B8_Goal::fn_8028D0EC(Unk8028C6B8_X* x, Unk8028C6B8_Ctx* ctx)
{
    if (!mA8.f15) {
        Unk80270BA0_Obj* p = ctx->m6CC->m36C;

        if (p) {
            float lim = 0.18f * Unk8028D0EC_M540(p->fn_vslot1()) + 0.8f;
            float r;           /* never read: reserves stack slot 0xC */
            Unk8014D8AC_Ctx* c = fn_8027A918();
            float scale = 1.0f;
            const char* file = REACHGOAL_FILE;

            if (!((float)(unsigned int)c->m554->fn_8014D8AC(1000000, file, 1361) * scale * 0.000001f <= lim)) {
                mA8.f14 = 1;
            }
        }
        mA8.f15 = 1;
    }
}

int Unk8028C6B8_Goal::fn_8028D4E4(int mode, Unk8028C6B8_X* x, int c)
{
    if (x->m618->m838 == 0x5B23BCCF) {
        if (m48 == 2) {
            if (!(m6C >= 32400.0f)) {
                return 24;
            }
        } else if (m28 == 0) {
            return 25;
        }
    }
    if (m28 == 0 || mode == 3 || mode == 10 || mode == 22 || mode == 23) {
        return mode;
    }

    float zz = m8->fn_8027A358(0).z;
    int i30 = 0;

    fn_8027AD3C(x, c, 0, 0, 0, 0, &i30, 0);
    float s = fn_804028E4(m6C);
    const float lim = 3600.0f;
    if (!(m68 >= lim)) {
        s = m64;
    }
    if (!(s <= zz - 12.0f)) {
        return mode;
    }
    if (mode != 0 && mode != 20) {
        int m = fn_8028C560(0, i30);
        int e = fn_8028E73C(this, 5);
        m8->fn_8027A17C(m, m, e, 0);
        zz = m8->fn_8027A358(0).z;
        if (!(s <= zz - 12.0f)) {
            return 0;
        }
    }
    int st = x->m458;
    if (st > 8)
        if (st <= 12) {
            if (mode != 0 && mode != 20) {
                int m = fn_8028C560(20, i30);
                int e = fn_8028E73C(this, 5);
                m8->fn_8027A17C(m, m, e, 0);
                zz = m8->fn_8027A358(0).z;
                if (s > zz - 12.0f) {
                    return 20;
                }
            }
            return 19;
        }
    if (!mA8.f4) {
        int m = fn_8028C560(20, i30);
        int e = fn_8028E73C(this, 5);
        m8->fn_8027A17C(m, m, e, 0);
        zz = m8->fn_8027A358(0).z;
        if (!(s <= zz - 12.0f)) {
            mA8.f3 = 0;
        } else {
            mA8.f3 = 1;
            mA8.f4 = 1;
        }
    }
    return 20;
}

void Unk8028C6B8_Goal::fn_8028D808(Unk8028C6B8_X* x, int c)
{
    if (mA8.f16) {
        m4C = fn_8028D8D8(x);
    }
    unsigned int mode = m4C;
    if (mode <= 1) {
        if (m4->mC > 1 && m4->m4C == 8) {
            mode = 20;
        }
        if (mA8.f11) {
            mode = 20;
        }
    }
    m48 = mode;
    fn_8028C6B8(x, c);
    int r = fn_8028D4E4(mode, x, c);
    m48 = r;
    if (r != mode) {
        fn_8028C6B8(x, c);
    }
    fn_8025596C(x->m58C, m48);
}

/* near-miss: 77 of 77 instructions in the same order as retail; the 28 that
 * differ are stack offsets only. Retail keeps the two Vec3 differences at
 * sp+0x28 and sp+0x38 and the by-value copies below them (sp+0x18, sp+0x28);
 * here every temp sits 0x10 higher except the final copy of the cross product.
 * Tried: named locals for the differences and the product (double copies, 95
 * instructions), const-reference parameters, Cross with swapped parameters,
 * a ternary return, declaration order of the locals. */
int Unk8028C6B8_Goal::fn_8028D8D8(Unk8028C6B8_X* x)
{
    Unk80273498_Vec3 p = fn_801837F4(x->m44C->m6B8, x->m708);
    int r = 7;

    if (!(Unk8028D8D8_Cross(p - lbl_805DED4C, lbl_805DED4C - (&lbl_805DED4C)[-1]).y > 0.0f)) {
        r = 8;
    }
    return r;
}

int fn_8028DA0C(void* g, Unk8028C6B8_X* x)
{
    if (x && x->m458 == 1) {
        float a = 20.0f;
        float b = 2.25f;

        Unk8028DA0C_FacingDiff(x);
        Unk80273498_Vec3 pos = x->m60;
        Unk80273498_Vec3 w = fn_8014E388(3);

        w.x += a;
        if ((w.x - pos.x) * (w.x - pos.x) + (w.z - pos.z) * (w.z - pos.z) < b * (b * 144.0f)) {
            return 1;
        }
    }
    return 0;
}

unsigned int fn_8028E73C(void* g, int k)
{
    unsigned int r = 0;
    switch (k) {
    case 2:
        r = lbl_806242B4;
        break;
    case 5:
        r = 0x8BF0ACA6;
        break;
    case 7:
        r = 0xA5422C1B;
        break;
    }
    return r;
}

int fn_8026DC5C(int a, int b);

int fn_8028E788(void* g, int a)
{
    return fn_8026DC5C(a, 0);
}

void Unk8028C6B8_Goal::fn_8028E7B0(Unk8028C6B8_X* x)
{
    m4->fn_8028F45C(fn_GetTarget());
    if (m2C && m48 != 2 && m48 != 22 && m48 != 23 && m48 != 24 && m48 != 25) {
        m4->fn_8028F528(fn_GetM1C());
    }
    m4->m98 = m78;
    int t38 = m38;
    m4->m38 = t38;
    int t34 = m34;
    m4->m34 = t34;
    m4->m40 = 10;
    m4->m18C.f18 = mA8.f5;
    if (mA8.f11) {
        float d = m70 - m8->fn_8027A280(0);
        fn_8028F588(d, m4);
        float v = x->m724;
        if (mA8.f12) {
            v = fn_80248FC8(x, m38);
        }
        m4->fn_SetM78(v);
    }
    if (mA8.f17) {
        m4->m54 = 8;
        m4->m18C.f19 = mA8.f18;
    }
}

int Unk8028C6B8_Goal::fn_8028E944(Unk8028C6B8_X* x, int c)
{
    if (m4->m28 == 0) {
        fn_8028E7B0(x);
    }
    int r = m4->fn_80290D1C(x);
    int result = -1;
    switch (r) {
    case 0:
    case 2:
        result = c ? -1 : 2;
        break;
    case 3:
        result = 3;
        break;
    case 1:
        result = 1;
        break;
    }
    return result;
}

/* near-miss: 198 of 198 instructions in the same order as retail; 32 differ,
 * all in stack offsets (frame is 136 bytes, retail 152: retail keeps d2/dist2
 * above block 1's freed temps, here d2 reuses them) plus the operand order of
 * the xor and the cmpw on m4C (retail loads o->m4C first, then compares
 * this->m4C against it). Tried: dist2/d2 declaration order and scope, the
 * m4C comparison written both ways, by-value getters vs lvalue arguments, a
 * flag instead of gotos (adds instructions). */
int Unk8028C6B8_Goal::fn_8028E9E8(Unk8028C6B8_Goal* o, Unk8028C6B8_X* x)
{
    if (!o) {
        goto fail;
    }
    if (m28 == 0) {
        if (o->m28 != 0) {
            goto fail;
        }
        return o->m4C == m4C;
    }
    {
        int ot = o->m38 == 4 ? 3 : o->m38;
        int gt = m38 == 4 ? 3 : m38;

        if (ot != gt) {
            goto fail;
        }
        float lim = fn_80249298(x, m40, 1);
        if (o->m28 == 0) {
            goto fail;
        }
        Unk80273498_Vec3 d = Unk8028E9E8_Sub(fn_GetTarget(), o->fn_GetTarget());
        if (d.x * d.x + d.z * d.z >= lim) {
            goto fail;
        }
        if (mC > 2 && m44->m14 == 0) {
            goto ok;
        }
        if (fn_8026DC18(x, 0)) {
            float dist2;
            Unk80273498_Vec3 d2 = Unk8028E9E8_Sub(x->m60, fn_GetTarget());

            dist2 = d2.x * d2.x + d2.z * d2.z;
            if (dist2 < lbl_8061E700[m4C]) {
                goto ok;
            }
        }
        if (o->m4C != m4C) {
            goto fail;
        }
        if (o->m2C && m2C) {
            float diff = AngleDiff(fn_80410CE8(o->m1C.x, o->m1C.z), fn_80410CE8(m1C.x, m1C.z));

            if (fabsf(diff) >= 0.26179942f) {
                goto fail;
            }
        }
    }
ok:
    if (o->mA8.f11) {
        m70 = o->m70;
        mA8.f11 = 1;
    }
    return 1;
fail:
    return 0;
}

void Unk8028C6B8_Goal::fn_8028ED00()
{
    m0 = 2;
    m48 = -1;
    m50 = 0;
    m58 = 0;
    m60I = 0;
    m5C = -1.0f;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028ED30(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    fn_SetTarget(v);
    m28 = 1;
    m4->fn_8028F45C(v);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EDD0(int idx)
{
    m48 = idx;
    Unk80273498_Vec3 p = fn_8027AF54(idx);
    fn_8028ED30(p);
    m4->fn_8028F4B8(idx);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EE4C(int idx, Unk80273498_Vec3* pos)
{
    if (pos) {
        fn_8028ED30(*pos);
    } else {
        Unk80273498_Vec3 p = fn_801837F4(fn_8027A90C()->m44C->m6B8, idx);
        fn_8028ED30(p);
    }
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EEF4()
{
    int v = 1;
    m60I = v;
    m4->m18C.f18 = v;
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EF14(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    fn_8027A898(v);
    m4->fn_8028F528(v);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EF98(float f)
{
    if (!(f <= 0.0f)) {
        m4CF = f;
        m50 = 1;
    } else {
        m50 = 0;
    }
    fn_8028F588(f, m4);
    Unk8028F45C_Inner* i = m4;
    float unused;
    float t = fn_8027A90C()->m724;
    i->m78 = t;
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028F01C(float f)
{
    m58 = 1;
    m54 = f;
    m4->fn_8028F5CC(f);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028F068(float f)
{
    m5C = f;
    m4->fn_8028F5F4(f);
    return this;
}

void Unk8028C6B8_Goal::fn_8028F0AC()
{
    m4->fn_8028F610();
}

void Unk8028C6B8_Goal::fn_8028F0D0()
{
    m4->fn_8028F848();
}

void Unk8028C6B8_Goal::fn_8028F0F4(Unk8028C6B8_X* x)
{
    int t38 = m38;
    m4->m38 = t38;
    int t34 = m34;
    m4->m34 = t34;
    m4->m40 = m40;
    if (x->m458 <= 8) {
        fn_8027AFA8(x->m44C, x, 0);
    }
    m4->fn_80290D1C(x);
    mC = m4->mC;
}
