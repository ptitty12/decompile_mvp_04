/*
 * Game code, .text 0x801C6D2C-0x801CAFA0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801C6D2C.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Z Z;

extern "C" {
void fn_801C66E8(Z* z, float f);
void fn_801C6A34(Z* z, float f);
void fn_801C6BB0(Z* z, float f);
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
}

extern "C" void fn_801C6D2C(Z* z, float f)
{
    if (!(f <= 0.67f))
        fn_801C66E8(z, f);
    else if (!(f > 0.33f))
        fn_801C6BB0(z, f);
    else
        fn_801C6A34(z, f);
}

extern "C" int fn_801C8154(Z* z) { return z->m1DC > 0.0f; }

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
    float lo = 44.0f;
    float hi = 52.0f;
    return Lerp(lo, hi, RandF(z->m204->m554, 1.0f, 0x1060));
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
