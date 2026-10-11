/*
 * Game code, .text 0x80188698-0x8018C9C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80188698.h"
//@BODY
//@80188698
extern "C" void fn_80188698(Unk80188698* o, float f)
{
    o->m4B0 = f;
}

//@801886B0
extern "C" int fn_801886B0(Unk80188698* o)
{
    return o->m4B4;
}

//@801886B8
extern "C" void fn_801886B8(Unk80188698* o, int v)
{
    o->m4B4 = v;
}

//@801888C0
extern "C" int fn_801888C0(Unk80188698* o)
{
    int v = fn_8025416C((char*)fn_801C1638(o->m44C, 0) + 0x588, 0);
    if (v == 0x85C || v == 0x84A || v == 0x84D || v == 0x855)
        return 1;
    return 0;
}

//@80188920
extern "C" Unk80183918_Vec3 fn_80188920(Unk80188698* o)
{
    return o->mC04;
}

//@80188944
extern "C" int fn_80188944(Unk80188698* o)
{
    Unk80188944_Ctx* c = o->m44C;
    int s = c->m6F4;
    if (s == 1)
        return 0;
    if (s == 2)
        return 0;
    if (s == 3)
        return 0;
    if (s == 8)
        return 0;
    if (s == 12)
        return 0;
    if (c->m6F8->m10->m184 != 0)
        return fn_801C4128(c->m700->m3A4) == 0;
    return 0;
}

//@80188EF4
extern "C" int fn_80188EF4(Unk80188698* o)
{
    int r = o->m4E8 > (float)o->m44C->m4C * lbl_805CDB20.m0;
    return r;
}

//@80188F44
extern "C" void fn_80188F44(Unk80188698* o, float f)
{
    o->m4E8 = (float)o->m44C->m4C * lbl_805CDB30.m0 + f;
}

//@80188F90
extern "C" void fn_80188F90()
{
}

//@80188F94
extern "C" void fn_80188F94(Unk80188698* o, void* p)
{
    o->m264 = p;
    if (p)
        fn_80189300(o, 0);
}

//@80189510
extern "C" void fn_80189510(Unk80188698* o, Unk80188698* t, float f)
{
    if (o->m36C == (int)t || o->m4D4 == 0) {
        if (!(f <= lbl_805CDB6C.m0)) {
            o->m4D4 = t;
            o->m384 = (float)t->m44C->m4C * lbl_805CDB78.m0 + f;
        } else {
            o->m384 = lbl_805CDB6C.m0;
            o->m4D4 = 0;
        }
    }
}

//@8018959C
extern "C" Unk80183918_Vec3 fn_8018959C(Unk80188698* o, float t)
{
    if (o->m36C != 0)
        return o->m60;
    t = t + o->m3F4;
    return fn_80196AC0(o->m448, t);
}

//@80189618
extern "C" Unk80183918_Vec3 fn_80189618(Unk80188698* o, float t)
{
    if (o->m36C != 0)
        return lbl_806055AC;
    t = t + o->m3F4;
    return fn_80196E3C(o->m448, t);
}

//@80189698
extern "C" int fn_80189698(Unk80188698* o, float t)
{
    int r;
    if (o->m36C == 0) {
        t = t + o->m3F4;
        r = fn_801973F4(o->m448, t);
    } else
        r = o->m388;
    return r;
}

//@80189D60
extern "C" float fn_80189D60(Unk80188698* o)
{
    float r;
    if (o->mBFC)
        r = *(float*)((char*)o->mBFC + 0xEE0) + o->m418;
    else
        r = lbl_805CDBDC.m0;
    return r;
}

//@80189D88
inline void Unk80189D88_Fwd(Unk80188698* x, float f, int a, int b, int c)
{
    fn_8019E114(*(void**)((char*)x->m44C + 0x6C8), x, a, b, c, f);
}

extern "C" void fn_80189D88(Unk80188698* o, float f, int a, int b, int c)
{
    Unk80189D88_Fwd(*(Unk80188698**)o->m448, f, a, b, c);
}

//@80189DDC
extern "C" void fn_80189DDC(Unk80188698* o, float f, int a, int b)
{
    fn_8019DF6C(*(void**)((char*)o->m44C + 0x6C8), o, a, b, f);
}

//@80189E20
extern "C" void fn_80189E20(Unk80188698* o, int a, int b)
{
    fn_8019DE2C(*(void**)((char*)o->m44C + 0x6C8), o, a, b);
}

//@8018A194
/* near-miss: 32/32 insns, 5 slots differ (store order of the nine trailing field resets;
 * 1500 of 362880 orders sampled; the f31 zero register and the mask match). */
extern "C" void fn_8018A194(Unk80188698* o)
{
    o->m3F4 = 0.0f;
    fn_80189300(o, 0);
    o->m4A4 &= 0xC9FFFFFF;
    o->m3F8 = 0.0f;
    o->m384 = 0.0f;
    o->m374 = 0;
    o->m4D4 = 0;
    o->m378 = 0;
    o->m380 = 0;
    o->m4DC = 0;
    o->m4E0 = 0;
    o->m37C = 0.0f;
}

//@8018A214
extern "C" float fn_8018A214(Unk80188698* o)
{
    float v = *(float*)((char*)o->m448 + 0x48) - o->m3F4;
    if (!(v >= lbl_805CDC00.m0))
        v = lbl_805CDC00.m0;
    return v;
}

//@8018A8C4
extern "C" void fn_8018A8C4(Unk80188698* o, float a, float b, float c)
{
    if (!(c <= lbl_805CDC1C.m0))
        c = c + o->m3F4;
    fn_801965CC(o->m448, o->m3F4 + a, o->m3F4 + b, c);
}

//@8018AA44
extern "C" int fn_8018AA44(int v)
{
    int r = 0;
    if (v == 1 || v == 2 || v == 4 || v == 3 || v == 5 || v == 10 || v == 12 || v == 13 || v == 14)
        r = 1;
    return r;
}

//@8018AA98
extern "C" int fn_8018AA98(int v)
{
    return fn_8018AA44(v) ^ 1;
}

//@8018AD20
extern "C" unsigned int fn_8018AD20(Unk80188698* o)
{
    return (o->m4A4 >> 21) & 1;
}

//@8018AD2C
extern "C" int fn_8018AD2C(Unk80188698* o)
{
    int a = o->m38C;
    if (a != 1 && (a != 4 || o->m390 != 1))
        return 1;
    if (o->m44C->m6F4 == 0)
        return (o->m4C4 ^ 1) == 0;
    return 1;
}

//@8018B43C
extern "C" int fn_8018B43C(Unk80188698* o, int a, Unk80183918_Vec3* p, float rr)
{
    Unk80183918_Vec3* q = (Unk80183918_Vec3*)fn_801A497C(o->m44C, 4, a);
    if (q != 0) {
        float d2 = (p->m0 - *(float*)((char*)q + 0x60)) * (p->m0 - *(float*)((char*)q + 0x60))
            + (p->m8 - *(float*)((char*)q + 0x68)) * (p->m8 - *(float*)((char*)q + 0x68));
        if (!(d2 > rr * (rr * lbl_805CDCA4.m0)))
            return 1;
    }
    return 0;
}

//@8018B648
extern "C" unsigned int fn_8018B648(Unk80188698* o)
{
    return (o->m4A4 >> 22) & 1;
}

