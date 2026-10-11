/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80060250-0x80060F94 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80060250.h"

typedef Unk8005DF2C_Ctx Ctx;
typedef Unk8005F4E4_Id16 Id16;
typedef Unk80060250_S S;

extern int lbl_80618F90;

int fn_80353D9C(int h);
int fn_8040ABA0();
int fn_8004FF78(Unk8005DF2C_P* p, int a, int b);
int fn_80057010(void* a, int b);
unsigned int fn_803440E8(int h);
Unk8005F4E4_G* fn_800B555C();
int fn_800B57EC();
int fn_80253DB0(Unk8005DF2C_Stat* s, int a, int b);
int fn_80253DF4(Unk8005DF2C_Stat* s, int a, int b);
void fn_80326F44(S* out, char* p, int a, int b, float f);
int fn_8001F954(Ctx* c);
int fn_80253E7C(Unk8005DF2C_Stat* s, int a, int b, int c);
Unk8005DF2C_O3B0* fn_801A497C(Unk8005DF2C_O44C* p, int a, int b);
float fn_8025454C(Unk8005DF2C_Stat* s, int idx);
int fn_80045F28();
void fn_80017184(int a, int b);

float fn_80060250(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int t = fn_80353D9C(ctx->m130->m44C->m6F8->mC->mC);
    if (ctx->m3B8 && ctx->m0 == 1 && ctx->m3B4 == 1 && ctx->m3C == 1 && t == 1 && ctx->m4D4 == 0 && ctx->m104 == 0)
        result = 100.0f;
    return result;
}

float fn_800602FC()
{
    float result = 0.0f;
    if (fn_8040ABA0() % 100 <= 0x4a)
        result = 100.0f;
    return result;
}

float fn_80060360()
{
    float result = 0.0f;
    if (fn_8040ABA0() % 100 <= 0x18)
        result = 100.0f;
    return result;
}

float fn_800603C4(Unk8005DF2C_A* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int i = fn_8004FF78(a->m0, a->m0->m9D8, 0x57);
    if (i == -1 || a->m0->m4[i].mC != 2 || ctx->m13C[ctx->m274].m0 == 0)
        result = 100.0f;
    return result;
}

float fn_80060454(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_803440E8(fn_80057010(a, c)) <= 2)
        result = 100.0f;
    return result;
}

float fn_800604A0(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m418)
        result = 100.0f;
    return result;
}

float fn_800604D4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (!ctx->m418)
        result = 100.0f;
    return result;
}

float fn_80060508(void* a, int b, int c, Ctx* ctx)
{
    Unk8005DF2C_O3B0* t = ctx->m3B0;
    fn_800B555C();
    int n = fn_800B57EC() ? 2 : 1;
    int cond = fn_80253DB0(&t->m588, 0, n);
    float result = 0.0f;
    if (cond > 0)
        result = 100.0f;
    return result;
}

float fn_80060578(void* a, int b, int c, Ctx* ctx)
{
    Unk8005DF2C_O130* t = ctx->m130;
    fn_800B555C();
    int n = fn_800B57EC() ? 2 : 1;
    int cond = fn_80253DF4(&t->m588, 0, n);
    float result = 0.0f;
    if (cond > 0)
        result = 100.0f;
    return result;
}

S fn_800605E8(Ctx* ctx)
{
    char* p = &ctx->m130->m44C->m50;
    S s;
    fn_80326F44(&s, p, 0x41, 1, -1.0f);
    S* ps = &s;
    int ok = 1;
    if (ps->m0 == 0xc7)
        ok = 0;
    if (!ok) {
        S t;
        fn_80326F44(&t, p, 0x48, 1, -1.0f);
        *ps = t;
    }
    return s;
}

float fn_800606D8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    S s = fn_800605E8(ctx);
    int ok = 1;
    if (!(s.m14 & 0x1000))
        ok = 0;
    if (ok)
        result = 100.0f;
    return result;
}

float fn_80060738(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    S s = fn_800605E8(ctx);
    int ok = 1;
    if (!(s.m14 & 0x2000))
        ok = 0;
    if (ok)
        result = 100.0f;
    return result;
}

float fn_80060798(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    S s = fn_800605E8(ctx);
    int ok = 1;
    if (!(s.m14 & 0x4000))
        ok = 0;
    if (ok)
        result = 100.0f;
    return result;
}

float fn_800607F8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    S s = fn_800605E8(ctx);
    int ok = 1;
    if (!(s.m14 & 0x8000))
        ok = 0;
    if (ok)
        result = 100.0f;
    return result;
}

float fn_80060858(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    int z = ctx->m3B0->m460;
    if (lbl_80618F90)
        result = 0.0f;
    if (z == 0)
        lbl_80618F90 = 1;
    return result;
}

float fn_800608A8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m110 == 0 && ctx->m118)
        result = 100.0f;
    return result;
}

float fn_800608E8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m41C)
        result = 100.0f;
    return result;
}

float fn_8006091C(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    if (ctx->m41C)
        result = 0.0f;
    return result;
}

float fn_80060950(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m290[ctx->m130->m708])
        result = 100.0f;
    return result;
}

float fn_80060994(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m130->m44C->m6F8->m10->m1C > 1)
        result = 100.0f;
    return result;
}

float fn_800609D8(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    Unk8005DF2C_Y* y = &ctx->m130->m44C->m6F8->m14[ctx->m3B4];
    if ((unsigned int)(y->m177 - 2) <= 3)
        result = 0.0f;
    return result;
}

float fn_80060A2C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m4D4 <= 1)
        result = 100.0f;
    return result;
}

float fn_80060A60(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_80253E7C(&ctx->m130->m588, 2, 2, 0) > 2)
        result = 100.0f;
    return result;
}

/* near-miss: same control flow and loops as fn_8005F7D8 (two bdnz sums over
 * the 0x80 bytes at +0x1B4 of two adjacent 0xE64 records), but register numbers
 * differ, and retail keeps (id.mC >> 1) + 1 in a register across the loops. */
float fn_80060AB8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    fn_800B555C();
    if (fn_800B57EC()) {
        Id16 id = fn_800B555C()->m688;
        Unk8005DF2C_O130* o = ctx->m130;
        Unk8005DF2C_O6F8* q = o->m44C->m6F8;
        int f = q->mC->m84 == 0;
        if (id.m0 == 2 && f) {
            Unk8005DF2C_Y* y = q->m14;
            int s0 = 0;
            for (int i = 0; i < 128; i++)
                s0 += y->m1B4[(unsigned char)i];
            y++;
            int s1 = 0;
            for (int i = 0; i < 128; i++)
                s1 += y->m1B4[(unsigned char)i];
            int h = (id.mC >> 1) + 1;
            if (((s0 >= s1 && id.m8 == h - 1) || (s1 >= s0 && id.m4 == h - 1)) && ctx->m3B8 && ctx->m3B4 == 1
                && ctx->m4D4 == 0 && ctx->m3CC + ctx->m3D0 == 0 && ctx->m0 == o->m44C->m6F8->m10->m1C)
                result = 100.0f;
        }
    }
    return result;
}

float fn_80060C50(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int lim = (int)((float)(1 << (ctx->m3CC + ctx->m3D0)) * 3.125f);
    if (fn_8040ABA0() % 100 < lim)
        result = 100.0f;
    return result;
}

float fn_80060D10(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int k = ctx->m130->m708;
    int x, y;
    for (int j = 0; j < 2; j++) {
        y = ctx->m318[k].v[j];
        x = ctx->m330[k].v[j];
    }
    if (x > 1 || y > 3)
        result = 100.0f;
    return result;
}

float fn_80060D7C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_8001F954(ctx) != 2)
        result = 100.0f;
    return result;
}

float fn_80060DC4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int k = ctx->m130->m708;
    int a0 = ctx->m2E8[k];
    int sum = a0 + ctx->m2F0[k];
    float ratio = (float)a0 / (float)sum;
    int x, y;
    for (int j = 0; j < 2; j++) {
        y = ctx->m318[k].v[j];
        x = ctx->m330[k].v[j];
    }
    if (sum > 0x32 && !(ratio <= 0.7f) && y <= 2 && x == 0)
        result = 100.0f;
    return result;
}

float fn_80060EB4()
{
    float result = 0.0f;
    fn_800B555C();
    if (fn_800B57EC()) {
        Id16 id = fn_800B555C()->m688;
        if (id.m0 == -1)
            result = 100.0f;
    }
    return result;
}

void fn_80060F34(void* a, Unk80060250_O* out, Ctx* ctx)
{
    out->m4 = 0xf6;
    fn_8025454C(&fn_801A497C(ctx->m130->m44C, ctx->m3B4 == 0, 7)->m588, 0xe);
    fn_80017184(0x80, fn_80045F28());
}
