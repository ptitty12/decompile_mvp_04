/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028B194-0x8028C6B8, .rodata 0x805DD6DC-0x805DD754.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028B194.h"

Unk80273498_Vec3 fn_8027AF54(Unk8028B194* g, int a);
Unk80270BA0_X* fn_8027A90C(Unk8028B194* g);
Unk80273498_Vec3 fn_801837F4(int obj, int a);
void fn_8028F5CC(void* p, float f);
void fn_8027AD3C(Unk8028B194* g, Unk80270BA0_X* x, int a, Unk80273498_Vec3* out6, float* out7,
                 int b, int c, unsigned int* out10, int s8);
float fn_80410CE8(float a, float b);           /* atan2 */
int fn_8026D940(Unk80270BA0_X* x, int a);
int fn_8026D9D0(Unk80270BA0_X* x, int a);
double __builtin_fabs(double x);
int fn_8026D704(Unk80270BA0_X* x, int a);
void fn_8027A9AC(Unk8028B194* g, Unk80270BA0_X* x, unsigned int h1, unsigned int h2, float* out, int a, int b, int c);
int fn_803164C4(const Unk80273498_Vec3& v);
void fn_8024937C(Unk80270BA0_X* x, float a, float b, Unk80273498_Vec3 v);

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

inline float Heading(Unk80273498_Vec3 t, const Unk80273498_Vec3& vb)
{
    return fn_80410CE8(t.x - vb.x, t.z - vb.z);
}

inline float Abs(float v)
{
    return __builtin_fabs(v);
}
extern const Unk80273498_Vec3 lbl_806055AC;    /* zero vector */
int fn_801A2034(Unk8028B194_Ctx* ctx, int a);
Unk80270BA0_X* fn_80257DD8(int a);
void fn_802D7B88(int a, int b, int c, float f);

inline Unk80273498_Vec3 GetTarget(Unk8028B194* g)
{
    return g->m10;
}

inline Unk80273498_Vec3 FlatPos(const Unk80273498_Vec3& p)
{
    Unk80273498_Vec3 r = p;
    r.y = 0.0f;
    return r;
}

inline Unk80273498_Vec3 operator-(Unk80273498_Vec3 a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

Unk8028B194* Unk8028B194::fn_8028B194(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    SetTarget(v);
    m28 = 1;
    return this;
}

Unk8028B194* Unk8028B194::fn_8028B1F0(int a)
{
    m50 = a;
    Unk80273498_Vec3 v = fn_8027AF54(this, a);
    fn_8028B194(v);
    return this;
}

Unk8028B194* Unk8028B194::fn_8028B260(int a, Unk80273498_Vec3* p)
{
    if (p) {
        fn_8028B194(*p);
    } else {
        Unk8028B194_Ctx* ctx = (Unk8028B194_Ctx*)fn_8027A90C(this)->m44C;
        Unk80273498_Vec3 v = fn_801837F4(ctx->m6B8, a);
        fn_8028B194(v);
    }
    return this;
}

Unk8028B194* Unk8028B194::fn_8028B308()
{
    mA8 |= 0x4000000;
    return this;
}

void Unk8028B194::fn_8028B31C(int id)
{
    m4C = id;
}

void Unk8028B194::fn_8028B324(int id)
{
    switch (id) {
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        break;
    default:
        id = 11;
        break;
    }
    fn_8028B31C(id);
}

void Unk8028B194::fn_8028B358()
{
    fn_8028B31C(0x11);
}

void Unk8028B194::fn_8028B37C()
{
    fn_8028B31C(9);
}

void Unk8028B194::fn_8028B3A0()
{
    fn_8028B31C(4);
}

Unk8028B194* Unk8028B194::fn_8028B3C4()
{
    mA8 |= 0x8000;
    return this;
}

void Unk8028B194::fn_8028B3D8()
{
    fn_8028B31C(2);
}

void Unk8028B194::fn_8028B3FC()
{
    fn_8028B31C(0x16);
}

void Unk8028B194::fn_8028B420()
{
    fn_8028B31C(0x17);
}

void Unk8028B194::fn_8028B444()
{
    fn_8028B31C(1);
}

void Unk8028B194::fn_8028B468()
{
    fn_8028B31C(3);
}

void Unk8028B194::fn_8028B48C(float a)
{
    if (!(a <= 0.0f)) {
        m70 = a;
        mA8 |= 0x100000;
    } else {
        mA8 &= ~0x100000;
    }
}

void Unk8028B194::fn_8028B4D0(float a)
{
    if (!(a <= 0.0f)) {
        m70 = a;
        mA8 |= 0x180000;
    } else {
        mA8 &= ~0x100000;
    }
}

void Unk8028B194::fn_8028B514(int a)
{
    m78 = a;
}

Unk8028B194* Unk8028B194::fn_8028B51C(float a)
{
    mA8 |= 0x20000000;
    m74 = a;
    fn_8028F5CC(m4, a);
    return this;
}

/* fn_8028B56C (0x8028B56C, 0x84C bytes, 531 instructions) is not attempted: it is
 * the goal's per-frame update, int fn_8028B56C(Unk80270BA0_X* x), returning 0..3.
 * Outline from the asm, for whoever picks it up:
 *  - prologue: ang = &x->m734 (Unk8028B194_Angles view); f = fn_8027A928(this);
 *    "if (ang->m190 == 1) ang->m60[0] = f; ang->m60[ang->m190] = f;" (the same
 *    mirror write is repeated for m98 and m48 further down);
 *    ctx = x->m44C; time = (float)ctx->m4C * (1/60); obj = ctx->m6CC->m36C converted
 *    to Unk80270BA0_Obj* (null-checked +0x5F0, address taken: 0x140(r1)), then
 *    other = obj ? obj->fn_vslot1() : 0.
 *  - fn_8027AD3C(this, x, 0, &v, &f24, 0, 0, 0, 0) fills a vector and a float;
 *    m6C = squared distance to m10 (dx*dx + dz*dz, 9999999 if m28 == 0).
 *  - phase mC > 2 skips the first block. Block 1 (x->m5BC == 3): for goal ids
 *    16/14/15 uses fn_8028DA0C(this, other) to set/clear mA8 bit 0x40000, calls
 *    fn_8028C6B8 when bit 0x40000 changed; then fn_8028E788 decides between
 *    fn_8028D200/fn_8028D808 (mA8 bit 0x200000) and "m48 = m4C; fn_8028C6B8".
 *  - link->m838 == 0x5B23BCCF and m48 in {0x16,0x17,0x18}: fn_80382BD8(link, 0) < 0.9
 *    or m6C > 3600 selects the exit; else fn_8028C264 / fn_8028E944 (-1 test).
 *  - ids 2/0x16..0x19 with m2C: angle = atan2(...) (fn_80410CE8) normalised with
 *    the AngleDiff pattern, written to m60 and the m98 mirror; mC clamped to >= 3;
 *    fn_8028C560(m48, link->m838) picks the animation hash; m28/mA8 bit 0x400000
 *    choose x->m93C = m10 or -1000; fn_803833B4/fn_803833F4 keep a handle in sync;
 *    fn_80381E9C(link, hash, 0, 0) starts it and the function returns 1 unless
 *    link->m838 changed.
 *  - tail (mC > 2): m54 = time while mC <= 3; mC >= 4; with mA8 bit 0x100000 set
 *    it runs fn_80386110 with a 0xC0-byte query record (the Unk8035EB7C pattern from
 *    animation/choosers/tu_80279AE4.cpp) to compute a 0..1 ratio clamped into
 *    ang->m48 (mirror write), then fn_8027C2D0(this, x, m78) (nonzero returns 2),
 *    fn_8028BDB8 / fn_8028BFA8 with t = time - m54, and finally a
 *    fn_8027A280(0)-based test that ends the goal (fn_8028B13C, fn_8028F440).
 * Pool order (retail .rodata): 805DD6E8 (2^52+2^31 double), 805DD6F0 (1/60),
 * 9999999, 0.9, 3600, 1/(2*pi), 0.5, 2*pi, -1000, -1, 1.5, 0, 1. */

/* near-miss: 125 of 124 instructions (35 register-normalized diffs). Retail
 * keeps three distinct frame slots (0x18, 0x28, 0x38) for the vector
 * arguments of fn_803164C4 (twice) and fn_8024937C, with direct word stores;
 * the temporaries here share one slot and keep its address in a callee-saved
 * register. Tried: by-value and const& parameters, named locals, one
 * condition expression vs if/else-if, a hit flag vs direct call. */
void Unk8028B194::fn_8028BDB8(Unk80270BA0_X* x, float t)
{
    if (!(mA8 & 0x40000) && fn_8026D704(x, 0)) {
        switch (m48) {
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            if (m28 && !(mA8 & 0x1000000)) {
                if (!(t <= 0.0f)) {
                    unsigned int h = ((Unk8028B194_Link*)x->m618)->m838;
                    float fl0 = 0.0f;
                    float fl1 = 0.0f;
                    fn_8027A9AC(this, x, h, 0xF4E8B1B9u, &fl0, 0, 0, 0);
                    fn_8027A9AC(this, x, h, 0xF4E8B1B9u, &fl1, 0, 0, 1);
                    fl0 = fl0 + (fl1 - fl0) * 0.33f;
                    fl1 = fl1 - (fl1 - fl0) * 0.33f;
                    if (!(fl0 <= 0.0f)) {
                        int hit = 0;
                        if (fn_803164C4(FlatPos(x->m60))) {
                            hit = 1;
                        } else if (fn_803164C4(GetTarget(this))) {
                            hit = 1;
                        }
                        if (hit) {
                            fn_8024937C(x, fl0, fl1, GetTarget(this));
                        }
                    }
                    mA8 |= 0x1000000;
                }
            }
            break;
        }
    }
}

void Unk8028B194::fn_8028BFA8(Unk80270BA0_X* x, Unk8028B194_Ctx* ctx, float t)
{
    if (ctx->m6F4 != 1 && m28 && !(mA8 & 0x800000) && !(t <= 0.0f)) {
        switch (m48) {
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16: {
            int flag = 0;
            if (ctx->m6F8->m14->m1CD0) {
                flag = 1;
            }
            int h = fn_801A2034(ctx, flag);
            if (h != -1) {
                if (x == fn_80257DD8(ctx->m700->m3B4)) {
                    int n = (int)((m8->fn_8027A280(0) - t) * 60.0f);
                    fn_802D7B88(h, 1, n / 4, 1.0f);
                }
            }
            break;
        }
        }
        mA8 |= 0x800000;
    }
}

int Unk8028B194::fn_8028C0CC(Unk80270BA0_X* x, int b)
{
    if (m28 && m4C == 3) {
        unsigned int hash = 0;
        Unk80273498_Vec3 pos = lbl_806055AC;
        float d2;
        fn_8027AD3C(this, x, b, &pos, 0, 0, 0, &hash, 0);
        Unk80273498_Vec3 diff = GetTarget(this) - pos;
        d2 = diff.x * diff.x + diff.z * diff.z;
        if (!(d2 >= 2304.0f)) {
            switch (hash) {
            case 0xA84A0C58u:
            case 0x7942CA79u:
            case 0x9FE2E6D1u:
            case 0xCA50EF74u:
            case 0xF90D27A1u:
            case 0xFA52B1B5u:
                return 1;
            }
        }
    }
    return 0;
}

/* near-miss: 184 of 191 instructions. The hash switch is balanced differently in
 * retail (root 0x858075AA with a three-node chain below it, so the real case
 * list is not just these 11 values), and retail stores the angle difference
 * once more (an extra stfs/lfs pair through a second float slot). Everything
 * before the switch matches except those. */
int Unk8028B194::fn_8028C264(Unk80270BA0_X* x)
{
    Unk80273498_Vec3 v = m8->fn_8027A358(0);
    const float k = 12.0f;
    int c;

    if (!(v.z >= 0.0f)) {
        c = m64 + k > v.z;
    } else {
        c = m6C < (v.z + k) * (v.z + k);
    }
    if (!c) {
        return 0;
    }
    if (!(m68 >= 576.0f)) {
        float flt = 0.0f;
        unsigned int hash = 0;
        Unk80273498_Vec3 vb = lbl_806055AC;
        fn_8027AD3C(this, x, 0, &vb, &flt, 0, 0, &hash, 0);
        if (m48 != 19 && m28) {
            if (Abs(AngleDiff(flt, Heading(GetTarget(this), vb))) >= 0.7853982f) {
                goto fail;
            }
        }
        switch (hash) {
        case 0x858075AAu:
        case 0x3453C76Bu:
        case 0x67A49CBAu:
        case 0x7133B4CBu:
        case 0xCA0C5FC1u:
        case 0xA713FF5Bu:
        case 0x97F6F9F4u:
        case 0xC96D745Bu:
        case 0xECC40882u:
        case 0xDB410FF7u:
        case 0xF469A7C1u:
            goto fail;
        }
        if (!fn_8026D940(x, 0) && !fn_8026D9D0(x, 0)) {
            return 1;
        }
    }
fail:
    mA8 &= ~0x200000;
    return 0;
}

unsigned int Unk8028B194::fn_8028C560(int id, unsigned int cur)
{
    unsigned int h = 0;

    switch (id) {
    case 0:
        h = 0xDB410FF7u;
        break;
    case 1:
    case 20:
        h = 0xF469A7C1u;
        if (mA8 & 0x8000000) {
            h = 0x97F6F9F4u;
        }
        break;
    case 2:
        h = 0x7C084C6Cu;
        break;
    case 22:
    case 23:
    case 24:
        h = 0xA58E08ADu;
        break;
    case 25:
        h = 0x2E726971u;
        break;
    case 3:
        h = 0xA84A0C58u;
        break;
    case 14:
    case 15:
    case 16:
        h = 0xB227F91Du;
        if (mA8 & 0x40000) {
            h = 0xFAA6104Cu;
        }
        break;
    case 4:
    case 9:
    case 19:
        h = 0xFAA6104Cu;
        break;
    case 11:
    case 12:
    case 13:
        h = 0xB227F91Du;
        break;
    case 10:
        h = 0x519E35F8u;
        break;
    case 7:
    case 8:
        h = 0x453DA560u;
        break;
    case 17:
        h = 0x1463E9BAu;
        break;
    case 18:
        break;
    }
    return h;
}
