/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005F4E4-0x80060250 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8005F4E4.h"

typedef Unk8005DF2C_Ctx Ctx;
typedef Unk8005F4E4_Id16 Id16;

int fn_8001F4F0(Ctx* c);
int fn_8006BE18(Unk8005DF2C_O6F8* a);
float fn_80253EC4(Unk8005DF2C_Stat* s, int a, int b, int c);
int fn_8001F9B4(Ctx* c);
int fn_8004FF78(Unk8005DF2C_P* p, int a, int b);
int fn_803270C4(char* p, int a, int b, float f);
void fn_80326F44(Unk8005F4E4_Buf* out, char* p, int a, int b, float f);
Unk8005F4E4_G* fn_800B555C();
int fn_800B57EC();
float fn_8025401C(Unk8005DF2C_Stat* s, int a);
int fn_80253FDC(Unk8005DF2C_Stat* s, int a);
int fn_80253F9C(Unk8005DF2C_Stat* s, int a);
float fn_80254128(Unk8005DF2C_Stat* s, int a, int b);
int fn_8001FD44(Ctx* c);
int fn_80344180(char* p, int a, int b);
int fn_803441E0(char* p, int a, int b);

float fn_8005F4E4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m104 == 0)
        result = 100.0f;
    return result;
}

float fn_8005F518(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m48 > 0)
        result = 100.0f;
    return result;
}

float fn_8005F54C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m3B0->m588.m8 & 0x20000000)
        result = 100.0f;
    return result;
}

float fn_8005F584(void* a, int b, int c, Ctx* ctx)
{
    Unk8005DF2C_O3B0* q = ctx->m120;
    float result = 0.0f;
    if (q && (q->m588.m8 & 0x20000000))
        result = 100.0f;
    return result;
}

float fn_8005F5C4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int fl = fn_8001F4F0(ctx);
    if (fl & 4) {
        if (ctx->m3B0) {
            int* r = &ctx->m3B0->m588.m4;
            if (!(r[1] & 0x20000000)) {
                int v = r[14];
                if (v >= 0) {
                    if (v <= 2)
                        result = 100.0f;
                }
            }
        }
    } else if (fl & 2) {
        if (ctx->m48 > 0)
            result = 100.0f;
    } else if (fl & 1) {
        if (ctx->m38 > 0)
            result = 100.0f;
    }
    return result;
}

float fn_8005F670(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m104 > 0)
        result = 100.0f;
    return result;
}

float fn_8005F6A4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (!fn_8006BE18(ctx->m130->m44C->m6F8))
        result = 100.0f;
    return result;
}

float fn_8005F6F4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_O130* o = ctx->m130;
    int k = ctx->m3B4 == 0;
    Unk8005DF2C_Y* y = &o->m44C->m6F8->m14[k];
    unsigned int v = (unsigned int)fn_80253EC4(&o->m588, 0, 2, 0);
    if ((unsigned int)ctx->m130->m44C->m6F8->m10->m1C > 8 && y->m235 == 1 && v == 0)
        result = 100.0f;
    return result;
}

float fn_8005F7D8(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int y = *(int*)((char*)ctx->m130->m44C->m6F8 + 0x14);
    int s0 = SumYBytes(y);
    int s1 = SumYBytes(y + 0xe64);
    if (s0 == s1)
        result = 100.0f;
    return result;
}

float fn_8005F86C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m1 == 0)
        result = 100.0f;
    return result;
}

float fn_8005F8A0(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m1 == 1)
        result = 100.0f;
    return result;
}

float fn_8005F8D4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m130->m44C->m6F8->m10->m1C == ctx->m0)
        result = 100.0f;
    return result;
}

float fn_8005F91C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_8001F9B4(ctx) > 2)
        result = 100.0f;
    return result;
}

float fn_8005F964(Unk8005DF2C_A* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int i = fn_8004FF78(a->m0, a->m0->m9D8, 0x48);
    if (i >= 0 && a->m0->m4[i].m0->m458 == 0)
        result = 100.0f;
    return result;
}

float fn_8005F9DC(Unk8005DF2C_A* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int i = fn_8004FF78(a->m0, a->m0->m9D8, 0x48);
    if (i >= 0) {
        int t = a->m0->m4[i].mC;
        if (a->m0->m4[i].m0->m458 == 0 && (t == 0 || t == 0xb))
            result = 100.0f;
    }
    return result;
}

/* near-miss: same instructions; the stack layout differs (retail has the -1.0
 * float at 0x10 and the 0x1C-byte buffer at 0x18 in a 0x40 frame, here 0xC and
 * 0x10). Declaration orders, buffer sizes, literal vs variable arguments tried. */
float fn_8005FA6C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    const float k = -1.0f;
    char* p = &ctx->m130->m44C->m50;
    int ok = fn_803270C4(p, 0x42, 1, k) != 0;
    if (ok) {
        Unk8005F4E4_Buf buf;
        fn_80326F44(&buf, p, 0xad, 1, k);
        int ok2 = 1;
        if (buf.m0 == 0xc7)
            ok2 = 0;
        if (ok2 && buf.m8 == 0)
            result = 100.0f;
    }
    return result;
}

/* near-miss: same as fn_8005FA6C (stack layout only). */
float fn_8005FB38(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    const float k = -1.0f;
    char* p = &ctx->m130->m44C->m50;
    int ok = fn_803270C4(p, 0x42, 1, k) != 0;
    if (ok) {
        Unk8005F4E4_Buf buf;
        fn_80326F44(&buf, p, 0xad, 1, k);
        int ok2 = 1;
        if (buf.m0 == 0xc7)
            ok2 = 0;
        if (ok2 && buf.m8 != 0)
            result = 100.0f;
    }
    return result;
}

float fn_8005FC04(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    fn_800B555C();
    if (fn_800B57EC()) {
        Unk8005DF2C_O130* o = ctx->m130;
        if (o->m44C->m6F8->mC->m1C == 2) {
            int v = ctx->m290[o->m708];
            Unk8005DF2C_Stat* s = &o->m588;
            float f = fn_8025401C(s, 0);
            Id16 id = fn_800B555C()->m688;
            if (id.m0 == -1) {
                int lim = v ? 0x18 : 5;
                if (!(f < (float)lim))
                    result = 100.0f;
            } else {
                int n = fn_80253FDC(s, 0);
                if (v) {
                    if (n > 0)
                        result = 100.0f;
                } else if (!(f <= 0.0f))
                    result = 100.0f;
            }
        }
    }
    return result;
}

float fn_8005FD4C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    fn_800B555C();
    if (fn_800B57EC()) {
        Unk8005DF2C_O130* o = ctx->m130;
        if (o->m44C->m6F8->mC->m1C == 2) {
            int v = ctx->m290[o->m708];
            Unk8005DF2C_Stat* s = &o->m588;
            float f = fn_8025401C(s, 0);
            Id16 id = fn_800B555C()->m688;
            if (id.m0 == -1) {
                int lim = v ? 0x18 : 5;
                if (!(f < (float)lim))
                    result = 100.0f;
            } else {
                int n = fn_80253FDC(s, 0);
                if (v) {
                    if (n > 0)
                        result = 100.0f;
                } else if (!(f <= 0.0f))
                    result = 100.0f;
            }
        }
    }
    return result;
}

float fn_8005FE94(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    float t = fn_8005FD4C(a, b, c, ctx);
    fn_800B555C();
    if (fn_800B57EC()) {
        Id16 id = fn_800B555C()->m688;
        if (id.m0 != -1)
            t = 100.0f;
    }
    return result - t;
}

float fn_8005FF24(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    fn_800B555C();
    if (fn_800B57EC() && ctx->m130->m44C->m6F8->mC->m1C == 2) {
        Id16 id = fn_800B555C()->m688;
        if (id.m0 == -1) {
            if (fn_80253F9C(&ctx->m3B0->m588, 0) > 4)
                result = 100.0f;
        } else {
            if ((int)fn_80254128(&ctx->m3B0->m588, 1, 2) > 0)
                result = 100.0f;
        }
    }
    return result;
}

float fn_8006000C(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    float t = fn_8005FF24(a, b, c, ctx);
    fn_800B555C();
    if (fn_800B57EC()) {
        Id16 id = fn_800B555C()->m688;
        if (id.m0 != -1)
            t = 100.0f;
    }
    return result - t;
}

float fn_8006009C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if ((unsigned int)(ctx->m3CC - 2) <= 1)
        result = 100.0f;
    return result;
}

float fn_800600D4(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m3D0 <= 1)
        result = 100.0f;
    return result;
}

float fn_80060108(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_8001FD44(ctx) == 0x12c)
        result = 100.0f;
    return result;
}

float fn_80060150(Ctx* c)
{
    float result = 100.0f;
    if (c->m104) {
        if (c->m10C <= 0x4b) {
            if (fn_80344180(&c->m70[2].mC, c->m10C, 0x13))
                result = 0.0f;
        }
    } else if (c->m108 <= 0x1d7) {
        if (fn_803441E0(&c->m70[0].mC, c->m108, 0x13))
            result = 0.0f;
    }
    return result;
}

float fn_800601D0(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m1 == 1)
        result = 100.0f;
    return result;
}

float fn_80060204(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m1 == 0)
        result = 100.0f;
    return result;
}

float fn_80060238()
{
    return 85.0f;
}

float fn_80060244()
{
    return 86.0f;
}
