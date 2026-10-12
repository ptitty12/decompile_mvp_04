/*
 * Game code, .text 0x8018C9C8-0x80190A00 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8018C9C8.h"
//@BODY
//@8018C9C8
extern "C" void fn_8018C9C8(Unk80188698* o, int a, int b, int c)
{
    o->m390 = o->m38C;
    o->m38C = 1;
    ((Unk8018C9C8_Bits*)&o->m4A4)->b10 = fn_8018AABC(o);
    ((Unk8018C9C8_Bits*)&o->m4A4)->b9 = fn_8018B4D0(o);
    fn_8018A254(o, a, &lbl_806055AC, b, c, 1, 0);
}

//@8018CA5C
extern "C" void fn_8018CA5C(Unk80188698* o, float* a, float* b, float* c)
{
    *a = *(float*)((char*)o + 0x3FC);
    *b = *(float*)((char*)o + 0x400);
    *c = *(float*)((char*)o + 0x404);
}

//@8018CA78
extern "C" float fn_8018CA78(Unk80188698* o)
{
    return Unk8018CA78_Eval((char*)o->m448 + 0x58, 3, 0.0f);
}

//@8018CAB4
extern "C" float fn_8018CAB4(Unk80188698* o)
{
    return Unk8018CA78_Eval((char*)o->m448 + 0x58, 6, 0.0f);
}

//@8018CAF0
extern "C" float fn_8018CAF0(Unk80188698* o)
{
    return Unk8018CA78_Eval((char*)o->m448 + 0x58, 11, 0.0f);
}

//@8018CB2C
extern "C" float fn_8018CB2C(Unk80188698* o)
{
    return Unk8018CA78_Eval((char*)o->m448 + 0x58, 10, 0.0f);
}

//@8018CB68
extern "C" float fn_8018CB68(Unk80188698* o)
{
    return Unk8018CA78_Eval((char*)o->m448 + 0x58, 3, 0.0f);
}

//@8018CBA4
extern "C" float fn_8018CBA4(Unk80188698* o)
{
    return ((Unk8018CA5C_Helper*)o->m448)->mAC8;
}

//@8018CBB0
extern "C" float fn_8018CBB0(Unk80188698* o)
{
    float r = Unk8018CA78_Eval((char*)o->m448 + 0x58, 6, 0.0f);
    if (!(r <= 0.0f))
        r = r - o->m3F4;
    return r;
}

//@8018CC24
extern "C" float fn_8018CC24(Unk80188698* o)
{
    float r = Unk8018CA78_Eval((char*)o->m448 + 0x58, 7, 0.0f);
    if (!(r <= 0.0f))
        r = r - o->m3F4;
    return r;
}

//@8018CC98
extern "C" float fn_8018CC98(Unk80188698* o)
{
    float r = Unk8018CA78_Eval((char*)o->m448 + 0x58, 8, 0.0f);
    if (!(r <= 0.0f))
        r = r - o->m3F4;
    return r;
}

//@8018CD0C
extern "C" float fn_8018CD0C(Unk80188698* o)
{
    float r = Unk8018CA78_Eval((char*)o->m448 + 0x58, 9, 0.0f);
    if (!(r <= 0.0f))
        r = r - o->m3F4;
    return r;
}

//@8018CD80
extern "C" void* fn_8018CD80(Unk80188698* o, float t)
{
    return Unk8018CA78_Eval2((char*)o->m448 + 0x58, t);
}

//@8018CDB8
extern "C" float fn_8018CDB8(Unk80188698* o, int k, float t)
{
    return Unk8018CA78_Eval((char*)o->m448 + 0x58, k, t);
}

//@8018CDF0
extern "C" void* fn_8018CDF0(Unk80188698* o, float t)
{
    return Unk8018CA78_Eval3((char*)o->m448 + 0x58, t);
}

//@8018CE28
extern "C" int fn_8018CE28(Unk80188698* o, int neg, Unk8018CE28_V* p)
{
    int tbl[9] = { 1, 0, 2, 4, 3, 5, 7, 6, 8 };
    Unk8018CE28_V v = *(Unk8018CE28_V*)((char*)o + 0x3B8);
    if (p)
        v = *p;
    int a = 1;
    int b = 1;
    float x = *(float*)&v.m0;
    if (neg)
        x = -x;
    float y = *(float*)&v.m4;
    float hi = 0.5f;
    if (!(x >= -0.5f))
        a = 0;
    else if (!(x <= 0.5f))
        a = 2;
    if (!(y >= -0.5f))
        b = 0;
    else if (!(y <= 0.5f))
        b = 2;
    return tbl[b * 3 + a];
}

//@8018CF7C
extern "C" int fn_8018CF7C(Unk80188698* o)
{
    int v = fn_8018CE28(o, 0, 0);
    int r = 0;
    if (v == 1 || v == 2 || v == 7 || v == 8)
        r = 1;
    return r;
}

//@8018D254
extern "C" void fn_8018D254()
{
}

//@8018D258
extern "C" void fn_8018D258(Unk80188698* o)
{
    int old = o->m38C;
    o->m38C = 4;
    o->m390 = old;
    ((Unk8018C9C8_Bits*)&o->m4A4)->b10 = fn_8018AABC(o);
    ((Unk8018C9C8_Bits*)&o->m4A4)->b9 = fn_8018B4D0(o);
    o->m374 = 0;
    o->m378 = 0;
    o->m37C = 0.0f;
    fn_8037893C((char*)o->m44C + 0x704, 0x43, 0, 0, 0);
}

//@8018D2EC
extern "C" float fn_8018D2EC(Unk80188698* o, int* out)
{
    float best = -1.0f;
    if (out)
        *out = 0;
    int ids[5] = { 11, 10, 3, 4, 12 };
    for (int i = 0; i < 5; i++) {
        float v = fn_8018CDB8(o, ids[i], 0.0f);
        if (!(v <= 0.0f) && (best < 0.0f || !(v >= best))) {
            if (out)
                *out = ids[i];
            best = v;
        }
    }
    return best;
}

//@8018D3E8
extern "C" void fn_8018D3E8(Unk80188698* o, Unk80183918_Vec3* p)
{
    *(int*)o = 0;
    o->m60 = *p;
}

//@8018D410
extern "C" void fn_8018D410(Unk80188698* o, float a, float b, float c)
{
    *(int*)o = 0;
    Unk8018D410_SetPos(o, a, b, c);
}

//@8018E45C
extern "C" void fn_8018E45C(Unk80188698* o)
{
    Unk80188698* p = *(Unk80188698**)((char*)o->m44C + 0x6CC);
    if (p == o && (p->m4A4 & 0x01000000)) {
        fn_8018ED00(p);
        fn_8018EB14(p);
        fn_8018EA18(p);
        if (p->m44C->m6F4 != 0)
            fn_8018E8C4(p);
    }
}

//@8018E8C4
extern "C" void fn_8018E8C4(Unk80188698* o)
{
    if (o->m44C->m6F4 == 7)
        fn_8018E4CC(o);
}

//@8018E8F4
/* near-miss: 73/73 insns, 3 slots differ: the order of the argument moves for the
 * fn_801923CC call (retail sets r4/r6 before r3 = &v40). ~6 forms tried. */
extern "C" int fn_8018E8F4(Unk80188698* o, Unk80183918_Vec3* a, Unk80183918_Vec3* b)
{
    float t = 0.0f;
    Unk8018E8F4_Rec16 vA;
    Unk8018E8F4_Rec16 vB;
    if (fn_8019BBC0(((Unk8018E8F4_Ctx*)o->m44C)->m6BC, a, b, &t, &vA, &vB, 1.5f) != 0) {
        Unk80183918_Vec3 v30 = lbl_806055B8;
        Unk80183918_Vec3 v40 = fn_80189618(o, 0.0f);
        fn_801923CC(&v40, &vA, &vB, &v30, (char*)o->m448 + 4, 5, 0);
        fn_8017BB18(((Unk8018E8F4_Ctx*)o->m44C)->m700, 1, o, 0, 15);
        fn_8018A930(o, 0, t, &v40, &v30, &vA);
        fn_8017BB3C(((Unk8018E8F4_Ctx*)o->m44C)->m700, 1, o, 0);
        return 1;
    }
    return 0;
}

//@8018EA18
extern "C" void fn_8018EA18(Unk80188698* o)
{
    if (o->m38C == 1 && o->m44C->m6F4 == 0) {
        Unk80183918_Vec3 a = o->m60;
        Unk80183918_Vec3 b = fn_8018959C(o, -0.016666668f);
        Unk8018EA18_Ent* e = (Unk8018EA18_Ent*)Unk8018CA78_Eval2((char*)o->m448 + 0x58, o->m3F4 - 0.016666668f);
        if (e != 0 && !(e->m4 >= o->m3F4)) {
            Unk80183918_Vec3* ev = &e->m8;
            if (fn_8018E8F4(o, &b, ev) == 0)
                fn_8018E8F4(o, ev, &a);
        } else {
            fn_8018E8F4(o, &b, &a);
        }
    }
}

//@8018EB14
extern "C" void fn_8018EB14(Unk80188698* o)
{
    if (o->m38C == 1 || o->m38C == 4) {
        int i = 0;
        int slot = 0;
        const float K = 1000.0f;
        Unk8014D8AC_Ctx* c = (Unk8014D8AC_Ctx*)o->m44C;
        Unk80273498_Pos** p = c->m65C;
        Unk80183918_Vec3 v = fn_80189618(o, 0.0f);
        int flag = fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8) < 211.20001f;
        fn_8018F684(o, (Unk80188698*)p[9], &slot, K, flag);
        fn_8018F684(o, (Unk80188698*)p[12], &slot, K, flag);
        if (c->m6F4 == 0) {
            fn_8018F684(o, (Unk80188698*)p[1], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)c->m65C[0], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[2], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[3], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[4], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[5], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[6], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[7], &slot, K, flag);
            fn_8018F684(o, (Unk80188698*)p[8], &slot, K, flag);
        }
        do {
            fn_8018F684(o, fn_801A4C74(c, i), &slot, 1000.0f, flag);
            i++;
        } while (i <= 3);
    }
}

//@8018ED00
extern "C" void fn_8018ED00(Unk80188698* o)
{
    if (o->m38C == 2 && fn_801A6DB8(o->m44C)->m50 != 0 && fn_801C3F60(((Unk8018ED00_Ctx*)o->m44C)->m700->m3A4) != 0) {
        Unk8018ED00_Ctx* c = (Unk8018ED00_Ctx*)o->m44C;
        int slot = -1;
        Unk80188698* t = c->m680;
        Unk8018ED00_S* s = c->m700->m3A4;
        if (t != 0 && s->m288 != 2) {
            if (s->m288 == 1) {
                if (fn_8018F684(o, t, &slot, 0.0f, 0) != 0 && *(int*)((char*)t + 0x92C) == 15) {
                    *(int*)((char*)t + 0x92C) = slot;
                    fn_801BD80C(((Unk8018ED00_Ctx*)o->m44C)->m700->m3BC, t);
                    fn_8037893C((char*)o->m44C + 0x704, 0x87, 0, 0, 0);
                }
            } else {
                fn_8018EE84(o, t);
            }
        }
    }
}

//@8018EE0C
extern "C" int fn_8018EE0C(void* unused, int v)
{
    int r = 2;
    switch (v) {
    case 5 ... 8:
        r = 0;
        break;
    case 9:
    case 10:
        r = 1;
        break;
    case 3:
    case 4:
    case 12:
        r = 2;
        break;
    case 1:
    case 2:
    case 13:
    case 14:
        r = 3;
        break;
    case 0:
    case 11:
        r = 4;
        break;
    }
    return r;
}

//@8018EE84
/* near-miss: 79/79 insns, ~14 slots differ: only the scheduling of the table copy against
 * the m700->m3A4 loads and the idx register (retail copies the index with mr. into r9);
 * the clamp shape (<= 4 arm first) and the state tests match. ~7 forms tried. */
extern "C" void fn_8018EE84(Unk80188698* o, Unk80188698* t)
{
    int st = o->m38C;
    if (st == 2) {
        int m = *(int*)((char*)o + 0x4A8);
        if (m == 1) {
            if (!(fn_80190F0C((Unk80190EB4_Obj*)o) - o->m3F4 >= 0.33333334f)) {
                if (*(int*)((char*)o + 0x4AC) == 5) {
                    ((Unk8018ED00_Ctx*)o->m44C)->m700->m3A4->m288 = m;
                    fn_8037893C((char*)o->m44C + 0x704, 0x89, 0, 0, 0);
                } else {
                    Unk8018ED00_S* s = ((Unk8018ED00_Ctx*)o->m44C)->m700->m3A4;
                    int tbl[5] = { 0, 1, 2, 3, 4 };
                    int idx0 = *(int*)((char*)o + 0x4AC);
                    s->m288 = st;
                    int idx = idx0;
                    if (idx <= 4) {
                        if (idx < 0)
                            idx = 0;
                    } else
                        idx = 4;
                    *(int*)((char*)o + 0x4AC) = idx;
                    *(int*)((char*)t + 0x930) = tbl[idx];
                    fn_8037893C((char*)o->m44C + 0x704, 0x89, 0, 0, 0);
                }
            }
        } else if (m == 0) {
            fn_8018EFC0(o, t);
        }
    }
}

//@8019019C
extern "C" int fn_8019019C(Unk80188698* o)
{
    Unk80188944_Ctx* c = o->m44C;
    if (c->m6F4 == 0 && *(Unk80188698**)((char*)c + 0x6CC) != o) {
        if (fn_801A2400(c) == 0)
            return 0;
    }
    return 1;
}

