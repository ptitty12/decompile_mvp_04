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
