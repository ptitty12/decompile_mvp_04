/*
 * Game code, .text 0x801C6D2C-0x801CAFA0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801C6D2C.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Z Z;
struct Unk801C6D2C_V2 {
    float x;
    float y;
};

extern "C" {
float fn_801C6D2C(Z* z, float f);
float fn_801C66E8(Z* z, float f);
float fn_801C6A34(Z* z, float f);
float fn_801C6BB0(Z* z, float f);
Vec3 fn_801C5BD4(Z* z);
float fn_804028E4(float x);
float fn_801C8170(Z* z);
void fn_801C7F38(Z* z, float f);
void fn_801CB8B0(Z* z, float f);
float fn_801C8240(Z* z);
void fn_801C8014(Z* z, float f);
void fn_803DF4E4(void* out, float angle, float x, float y, float z);
void fn_803DED40(void* m, void* in, void* out);
float fn_801C8C38(Z* z);
float fn_801C8B7C(Z* z);
float fn_801C8EFC(Z* z);
float fn_801C8CF4(Z* z);
float fn_801C8AC0(Z* z);
float fn_801C8A04(Z* z);
float fn_801C8DB0(Z* z);
void fn_801C93BC(Z* z, float a, float b, float c, float d);
float fn_801C7964(Z* z);
float fn_801C5D74(Z* z);
float fn_801C72FC(Z* z, float f, float a, float b);
void fn_801CC894(Z* z);
void fn_801C84FC(Z* z);
void fn_801CFCAC(Z* z);
int fn_801CDA84(Z* z);
void fn_801CB360(Z* z);
void fn_801CBE08(Z* z);
void fn_801C983C(Z* z);
void fn_801CA144(Z* z);
void fn_801CA654(Z* z);
void fn_801C97AC(Z* z);
void fn_801C97F4(Z* z);
void fn_801C9184(Z* z);
void fn_801C92A0(Z* z);
P* fn_801A4B34(P* ctx);
float fn_801C7BF0(Z* z, float f);
float fn_801C7D90(Z* z, float f);
Vec3 fn_801CE6E4(Z* z, float a, float b, float c);
}
struct Unk801C6D2C_G {
    char pad0[0x60];
    float m60;
    float m64;
    char pad68[0x380 - 0x68];
    float m380;
    float m384;
    float m388;
    float m38C;
};
extern Unk801C6D2C_G lbl_8068C420;
extern int lbl_80620358;
extern float lbl_8062035C;
float fn_801CD068(Z* z);
extern int lbl_80620378;
extern int lbl_8062034C;
extern int lbl_8068C6C8;
extern Unk801C6D2C_V2 lbl_80691DBC;

/* The callees' float result is left in f1 (a `return` per arm changes the branch layout). */
extern "C" float fn_801C6D2C(Z* z, float f)
{
    if (!(f <= 0.67f))
        fn_801C66E8(z, f);
    else if (!(f > 0.33f))
        fn_801C6BB0(z, f);
    else
        fn_801C6A34(z, f);
}

inline float AbsF(float v) { return (float)__builtin_fabs(v); }

extern "C" float fn_801C6FD8(Z* z)
{
    float r = 0.0f;
    const float u = -3.0f;
    float c = 31.0f;
    float d = 31.0f;
    float e = 31.0f;
    if (!(AbsF(z->m140) >= 0.28f))
        r = 11.0f;
    else if (!(z->m140 >= 0.0f))
        r = AbsF(z->m140) * u;
    else
        r = z->m140 * e;
    return r;
}

struct Unk801C6D2C_Pt {
    float x;
    float y;
};
struct Unk801C6D2C_Curve {
    Unk801C6D2C_Pt p[25];
};
extern Unk801C6D2C_Curve lbl_805D15B4;

/* near-miss: same code; retail keeps the table index in r11 and the scan counter in r9 (ours r10/r9). */
extern "C" float fn_801C7070(float t)
{
    Unk801C6D2C_Curve c = lbl_805D15B4;
    if (!(t < c.p[24].x))
        return c.p[24].y;
    int idx = 0;
    int j = 0;
    if (c.p[j].x > t)
        goto done;
again:
    j = j + 1;
    if (j > 24)
        goto done;
    if (c.p[j].x <= t)
        goto again;
    idx = j;
done:
    if (idx == 0)
        return c.p[0].y;
    float dx = c.p[idx].x - c.p[idx - 1].x;
    if (!(dx > 0.1f))
        return c.p[idx].y;
    float u = (t - c.p[idx - 1].x) / dx;
    u = !(u > 1.0f) ? (u >? 0.0f) : 1.0f;
    return u * c.p[idx].y + (1.0f - u) * c.p[idx - 1].y;
}

extern "C" float fn_801C71EC(Z* z)
{
    const float lo = 65.0f;
    const float hi = 105.0f;
    Vec3 v = fn_801C5BD4(z);
    float t = fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z) * 0.05681818f;
    t = t / z->m204->m6CC->m3E8;
    float r = !(t > hi) ? ((t >? lo) - lo) * 0.025f : 1.0f;
    r = !(r > 1.0f) ? (r >? 0.0f) : 1.0f;
    return r;
}

extern "C" float fn_801C7BF0(Z* z, float f)
{
    float a = 0.0f;
    float b = 0.0f;
    if (!(RandFP(z->m204, 1.0f, 0xE34) >= 0.5f)) {
        const float c = 30.0f;
        b = a - (1.0f - f) * c;
    } else {
        const float c = 18.0f;
        b = (1.0f - f) * c + a;
    }
    b = b * LerpATB(0.8f, RandFP(z->m204, 1.0f, 0xE46), 1.2f);
    return b;
}

extern "C" float fn_801C7D90(Z* z, float f)
{
    float a = 30.0f;
    float b = 0.0f;
    if (!(RandFP(z->m204, 1.0f, 0xE56) >= 0.5f)) {
        const float c = 15.0f;
        b = a - (1.0f - f) * c;
    } else {
        const float c = 15.0f;
        b = (1.0f - f) * c + a;
    }
    b = b + LerpATB(-6.0f, RandFP(z->m204, 1.0f, 0xE66), 6.0f);
    return b;
}

extern "C" void fn_801C7F38(Z* z, float f)
{
    f = !(f > 1.0f) ? (f >? 0.0f) : 1.0f;
    float a = fn_801C7964(z);
    float b = fn_801C7BF0(z, f);
    float c = fn_801C7D90(z, f);
    lbl_8068C420.m380 = a;
    lbl_8068C420.m384 = b;
    lbl_8068C420.m38C = c;
    z->m1B0 = fn_801CE6E4(z, b, a, c);
}

extern "C" void fn_801C8014(Z* z, float f)
{
    f = !(f > 1.0f) ? (f >? 0.0f) : 1.0f;
    float a = fn_801C5D74(z);
    float b = fn_801C6D2C(z, f);
    float c = fn_801C72FC(z, f, b, a);
    P* p = fn_801A4B34(z->m204);
    if (z->m204->m6F4 == 0) {
        int ok;
        if (lbl_80620378 != 0)
            ok = 1;
        else
            ok = p->mB3C.f;
        if (ok) {
            a = 45.0f;
            b = -5.0f;
            c = 15.0f;
        }
    }
    lbl_8068C420.m380 = a;
    lbl_8068C420.m384 = b;
    lbl_8068C420.m38C = c;
    z->m1B0 = fn_801CE6E4(z, b, a, c);
}

extern "C" int fn_801C8154(Z* z) { return z->m1DC[0] > 0.0f; }

extern "C" float fn_801C8170(Z* z)
{
    float a = fn_801CD068(z);
    float b = z->m1DC[0];
    float c = z->m1DC[3];
    float t = a * 0.4f + b * 0.4f + c * 0.2f;
    t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
    lbl_8068C420.m64 = t;
    if (lbl_80620358 != 0)
        t = lbl_8062035C;
    lbl_8068C420.m60 = t;
    return t;
}

extern "C" void fn_801C891C(void* self, void* q, const Vec3* axis, float angle)
{
    char m[0x40];
    fn_803DF4E4(m, angle, axis->x, axis->y, axis->z);
    fn_803DED40(m, q, q);
}

extern "C" int fn_801C8974(Z* z)
{
    return RandF(z->m204->m554, 1.0f, 0x1034) > 0.5f;
}

extern "C" float fn_801C8A04(Z* z)
{
    const float hi = 52.0f;
    const float lo = 44.0f;
    return LerpATB(lo, RandF(z->m204->m554, 1.0f, 0x1060), hi);
}

extern "C" float fn_801C8AC0(Z* z)
{
    const float hi = 65.0f;
    const float lo = 50.0f;
    return LerpATB(lo, RandF(z->m204->m554, 1.0f, 0x1067), hi);
}

extern "C" float fn_801C8B7C(Z* z)
{
    const float hi = 85.0f;
    const float lo = 45.0f;
    return LerpATB(lo, RandF(z->m204->m554, 1.0f, 0x106E), hi);
}

extern "C" float fn_801C8C38(Z* z)
{
    const float hi = 77.5f;
    const float lo = 65.0f;
    return LerpATB(lo, RandF(z->m204->m554, 1.0f, 0x1075), hi);
}

extern "C" float fn_801C8CF4(Z* z)
{
    const float hi = 45.0f;
    const float lo = 35.0f;
    return -LerpATB(lo, RandF(z->m204->m554, 1.0f, 0x107C), hi);
}

extern "C" float fn_801C8DB0(Z* z)
{
    const float hi = 85.0f;
    const float lo = 88.0f;
    float v = LerpATB(lo, RandFP(z->m204, 1.0f, 0x1083), hi);
    if (!(RandFP(z->m204, 1.0f, 0x1085) >= 0.5f))
        v = -v;
    return v;
}

extern "C" float fn_801C8EFC(Z* z)
{
    const float hi = 75.5f;
    const float lo = 45.0f;
    return -LerpATB(lo, RandF(z->m204->m554, 1.0f, 0x1092), hi);
}

extern "C" float fn_801C8FB8(Z* z)
{
    float r = 0.0f;
    switch (z->m130) {
    case 0:
        if (z->m124 == 2 || z->m128 == 5)
            r = fn_801C8C38(z);
        else
            r = fn_801C8B7C(z);
        break;
    case 1:
        r = fn_801C8EFC(z);
        break;
    case 2:
        r = fn_801C8CF4(z);
        break;
    case 3:
        if (z->m124 == 2 || z->m128 == 5)
            r = fn_801C8AC0(z);
        else
            r = fn_801C8A04(z);
        break;
    case 4:
        r = fn_801C8DB0(z);
        break;
    case 5:
        r = 100.0f;
        break;
    default:
        r = 100.0f;
        break;
    }
    return r;
}

/* near-miss: same code; the switch tree differs by one range node (retail tests cases 0..1 as
 * `cmpwi 0; blt; cmpwi 1; ble`, ours as two beq). */
extern "C" void fn_801C8790(Z* z)
{
    int one = 1;
    z->m120 = one;
    fn_801CC894(z);
    fn_801C84FC(z);
    fn_801CFCAC(z);
    if (lbl_8062034C == 0) {
        if (z->m1A8 != 4) {
            if (fn_801CDA84(z) == 0)
                z->m1A8 = one;
            if (z->m12C != 0)
                z->m1A8 = 5;
        }
        switch (z->m1A8) {
        case 4:
            fn_801CBE08(z);
            break;
        case 0:
            fn_801CB360(z);
            break;
        case 1:
            fn_801CB360(z);
            break;
        case 3:
            fn_801CB360(z);
            break;
        case 5:
            fn_801CB360(z);
            break;
        case 6:
            if (fn_801C8154(z) != 0) {
                z->m1AC = 1;
                fn_801C983C(z);
                {
                    int* q = &lbl_8068C6C8;
                    *q = z->m130;
                }
                if (z->m128 == 5) {
                    if (z->m130 == 5)
                        fn_801C97AC(z);
                    else
                        fn_801C9184(z);
                } else {
                    if (z->m130 == 5)
                        fn_801C97F4(z);
                    else
                        fn_801C92A0(z);
                }
                fn_801CA144(z);
                fn_801CA654(z);
                lbl_80691DBC = *(Unk801C6D2C_V2*)z->m150;
            } else {
                fn_801CB360(z);
            }
            break;
        }
    }
}

extern "C" void fn_801C90AC(Z* z)
{
    float x = fn_801C8FB8(z);
    const float a = 43.0f;
    const float b = 25.0f;
    fn_801C93BC(z, x, RandFP(z->m204, 1.0f, 0x10CC), a, b);
}

typedef Unk801C6D2C_V2 (*Unk801C6D2C_VaFn)(Z*, ...);
extern "C" Unk801C6D2C_V2 fn_801CD94C(Z* z);

extern "C" void fn_801C9184(Z* z)
{
    float a = RandFP(z->m204, 0.499f, 0x10D9);
    Unk801C6D2C_V2 v = ((Unk801C6D2C_VaFn)fn_801CD94C)(z);
    if (!(v.x >= 0.6) && !(v.x <= -0.6))
        a = a + 0.5f;
    fn_801CB8B0(z, a);
    float b = fn_801C8FB8(z);
    const float c = 50.0f;
    fn_801C93BC(z, b, a, 40.0f, c);
}

extern "C" void fn_801C92A0(Z* z)
{
    float a = RandFP(z->m204, 0.499f, 0x10F4);
    Unk801C6D2C_V2 v = ((Unk801C6D2C_VaFn)fn_801CD94C)(z);
    if (!(v.x >= 0.6) && !(v.x <= -0.6))
        a = a + 0.5f;
    fn_801CB8B0(z, a);
    float b = fn_801C8FB8(z);
    const float c = 85.0f;
    fn_801C93BC(z, b, a, 40.0f, c);
}

extern "C" void fn_801C97AC(Z* z)
{
    float t = fn_801C8170(z);
    fn_801C7F38(z, t);
    fn_801CB8B0(z, t);
}

extern "C" void fn_801C97F4(Z* z)
{
    float t = fn_801C8240(z);
    fn_801C8014(z, t);
    fn_801CB8B0(z, t);
}
