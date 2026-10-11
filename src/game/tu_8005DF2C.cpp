/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005DF2C-0x8005EDCC only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8005DF2C.h"

typedef Unk8005DF2C_Ctx Ctx;

int fn_800570D8(void* a, int n);
int fn_80344138(int h, int v);
int fn_801C1638(Unk8005DF2C_O44C* p, int idx);
Unk8005DF2C_O3B0* fn_801A4B34(Unk8005DF2C_O44C* p);
Unk8005DF2C_O3B0* fn_801A4B7C(Unk8005DF2C_O44C* p, int a, int b);
float fn_8024F048(char* p, int a, int b, int c, int d);
float fn_8024F20C(char* p, int a, int b, int c, int d);
int fn_8008838C(int a, int b, int c);
void fn_8005DA1C(Ctx* c, int* a, int* b, int* d, int* e);
int fn_80088FFC(int a, int b);
int fn_8001CEA8(Ctx* c, float* a, float* b);
int fn_8005CDC4(void* a, Ctx* c);
float fn_8025454C(Unk8005DF2C_Stat* p, int idx);
int fn_8004FF78(Unk8005DF2C_P* p, int a, int b);
void fn_80235BE0(float* out, int a, ...);
int fn_802F92CC(int a);

float fn_8005DF2C(void* a, int b, int c, Ctx* ctx)
{
    int h = fn_800570D8(a, 4);
    if (fn_80344138(h, ctx->m130->m704))
        return 100.0f;
    return 0.0f;
}

float fn_8005DF84(void* a, int b, int c, Ctx* ctx)
{
    int h = fn_800570D8(a, 5);
    if (fn_80344138(h, ctx->m130->m704))
        return 100.0f;
    return 0.0f;
}

float fn_8005DFDC(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_O44C* p = ctx->m130->m44C;
    int v25 = 1;
    if (!fn_801C1638(p, 0xa))
        v25 = 0;
    int v26 = 1;
    if (!fn_801C1638(p, 0xb))
        v26 = 0;
    int v27 = 1;
    if (!fn_801C1638(p, 0xc))
        v27 = 0;
    Unk8005DF2C_O3B0* t = fn_801A4B34(p);
    float x0 = fn_8024F048(&t->mA0C, t->mA04, t->m44C, t->m708, 1);
    float x1 = fn_8024F20C(&t->mA0C, t->mA04, t->m44C, t->m708, 1);
    t = fn_801A4B7C(p, 1, 1);
    float x2 = fn_8024F048(&t->mA0C, t->mA04, t->m44C, t->m708, 1);
    float x3 = fn_8024F20C(&t->mA0C, t->mA04, t->m44C, t->m708, 1);
    if (!v25 && (v26 || v27) && ctx->m4D4 <= 1
        && ((!(x1 < 0.85f) && x3 < 0.8f) || (!(x0 < 0.85f) && !(x2 >= 0.8f))))
        result = 100.0f;
    return result;
}

float fn_8005E184(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_O130* o = ctx->m130;
    int s = o->m44C->m6F8->mC->mC;
    if (fn_8008838C(s, o->m704, o->m708) == 0x32) {
        int i0, i1, i2, i3;
        fn_8005DA1C(ctx, &i0, &i1, &i2, &i3);
        if (fn_80088FFC(s, -1) == i1 && !((float)i0 < 2.0f * (float)i2))
            result = 100.0f;
    }
    return result;
}

float fn_8005E278(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_O130* o = ctx->m130;
    int s = o->m44C->m6F8->mC->mC;
    if (fn_8008838C(s, o->m704, o->m708) == 0x32) {
        int i0, i1, i2, i3;
        fn_8005DA1C(ctx, &i0, &i1, &i2, &i3);
        if (fn_80088FFC(s, -1) == i1 && !((float)i0 < 2.0f * (float)i2))
            result = 100.0f;
    }
    return result;
}

float fn_8005E36C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m110 && ctx->m4D4 <= 1)
        result = 100.0f;
    return result;
}

float fn_8005E3AC(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    float v0c;
    float v10;
    fn_8001CEA8(ctx, &v10, &v0c);
    if (ctx->m3CC == 2 && ctx->m3D0 <= 1 && ctx->m104 == 1
        && (v0c >= 0.75f || v0c <= 0.4f || fn_8005CDC4(a, ctx)))
        result = 100.0f;
    return result;
}

float fn_8005E468(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m104 == 1 && ctx->m4D4 <= 1 && ctx->m118 && fn_8005CDC4(a, ctx) && ctx->m4D4 == 0) {
        if (!(fn_8024F048(&ctx->m3B0->mA0C, ctx->m3B0->mA04, ctx->m3B0->m44C, ctx->m3B0->m708, 1)
                  + fn_8024F20C(&ctx->m3B0->mA0C, ctx->m3B0->mA04, ctx->m3B0->m44C, ctx->m3B0->m708, 1)
              > 1.4f))
            result = 100.0f;
    }
    return result;
}

float fn_8005E544(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m104 == 1 && ctx->m4D4 <= 1 && ctx->m118 && !fn_8005CDC4(a, ctx))
        result = 100.0f;
    return result;
}

float fn_8005E5B0(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m110 && !ctx->m118 && fn_8005CDC4(a, ctx)
        && (((ctx->m3CC == 1 || ctx->m3CC == 2) && ctx->m3D0 == 0) || (ctx->m3CC == 2 && ctx->m3D0 == 1)
            || (ctx->m3CC == 0 && ctx->m3D0 == 1) || (ctx->m3CC == 1 && ctx->m3D0 == 2))) {
        Unk8005DF2C_O684* o = ctx->m130->m44C->m684;
        if (o) {
            Unk8005DF2C_Stat* q = &o->m588;
            float f0 = fn_8025454C(q, 0xd);
            float f1 = fn_8025454C(q, 0x14);
            if (f0 >= 0.8f || !(f1 < 0.75f))
                result = 100.0f;
        }
    }
    return result;
}

float fn_8005E6D8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m110 && !ctx->m118 && fn_8005CDC4(a, ctx)
        && (((ctx->m3CC == 1 || ctx->m3CC == 2) && ctx->m3D0 == 0) || (ctx->m3CC == 2 && ctx->m3D0 == 1)
            || (ctx->m3CC == 0 && ctx->m3D0 == 1) || (ctx->m3CC == 1 && ctx->m3D0 == 2))) {
        Unk8005DF2C_O684* o = ctx->m130->m44C->m684;
        if (o) {
            Unk8005DF2C_Stat* q = &o->m588;
            float f0 = fn_8025454C(q, 0xd);
            float f1 = fn_8025454C(q, 0x14);
            if (!(f0 >= 0.8f) && !(f1 >= 0.75f) && !(f0 < 0.7f) && !(f1 < 0.7f))
                result = 100.0f;
        }
    }
    return result;
}

float fn_8005E81C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m4D4 <= 1 && ctx->m120)
        result = 100.0f;
    return result;
}

float fn_8005E85C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_8005CDC4(a, ctx) && (ctx->m120 || ctx->m118))
        result = 100.0f;
    return result;
}

float fn_8005E8C8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m410)
        result = 100.0f;
    return result;
}

float fn_8005E8FC(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m414)
        result = 100.0f;
    return result;
}

float fn_8005E930(Unk8005DF2C_A* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_P* p = a->m0;
    if (fn_8004FF78(p, p->m9D8, 0x2a) == -1)
        result = 100.0f;
    return result;
}

float fn_8005E980(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m3BC)
        result = 100.0f;
    return result;
}

float fn_8005E9B4(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    if (ctx->m3BC)
        result = 0.0f;
    return result;
}

float fn_8005E9E8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    float v[2];
    Unk8005DF2C_O700* o = ctx->m130->m44C->m700;
    fn_80235BE0(v, o->m3B0);
    if (!(v[0] >= 1.0f || v[0] <= -1.0f || v[1] >= 1.0f || v[1] <= -1.0f))
        result = 100.0f;
    return result;
}

float fn_8005EA90(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    float v[2];
    Unk8005DF2C_O700* o = ctx->m130->m44C->m700;
    fn_80235BE0(v, o->m3B0);
    if (!(v[0] >= 1.0f || v[0] <= -1.0f || v[1] >= 1.0f || v[1] <= -1.0f))
        result = 0.0f;
    return result;
}

float fn_8005EB38(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    if (!fn_802F92CC(ctx->m130->m44C->m720))
        result = 0.0f;
    return result;
}

float fn_8005EB88(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m110)
        result = 100.0f;
    return result;
}

float fn_8005EBBC(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_O6F8* q = ctx->m130->m44C->m6F8;
    if (ctx->m3B8 && ctx->m3B4 == 1 && ctx->m3CC + ctx->m3D0 == 0
        && ctx->m0 == q->m10->m1C && ctx->m4D4 == 0)
        result = 100.0f;
    return result;
}

float fn_8005EC3C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m4D4 <= 2)
        result = 100.0f;
    return result;
}

float fn_8005EC70(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if ((unsigned)(ctx->m408 - 4) <= 3)
        result = 100.0f;
    return result;
}

float fn_8005ECA8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if ((unsigned)(ctx->m408 - 4) > 3)
        result = 100.0f;
    return result;
}

float fn_8005ECE0(Unk8005DF2C_A* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_P* p = a->m0;
    if (fn_8004FF78(p, p->m9D8, 0x10) >= 0)
        result = 100.0f;
    return result;
}

float fn_8005ED30(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m40C)
        result = 100.0f;
    return result;
}

float fn_8005ED64(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (!ctx->m40C)
        result = 100.0f;
    return result;
}

float fn_8005ED98(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m278 == 3)
        result = 100.0f;
    return result;
}
