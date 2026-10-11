/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005EDCC-0x8005F4E4 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8005EDCC.h"

typedef Unk8005DF2C_Ctx Ctx;
typedef Unk8005EDCC_Ent Ent;

extern Unk8005EDCC_G* lbl_8061EA68;

unsigned int fn_80253E7C(Unk8005DF2C_Stat* p, int a, int b, int c);
int fn_8040ABA0();
void fn_80235BE0(float* out, int a, ...);
int fn_8022EA7C(int a, float* v, float s);
Unk8005EDCC_T* fn_801A6D84(Unk8005DF2C_O44C* p, int a);
int fn_80324DB4(Ent* e, int a);
int fn_80324E38(Ent* e, int a);
float fn_8005F20C(void* a, int b, int c, Ctx* ctx);
float fn_8005F2FC(void* a, int b, int c, Ctx* ctx);

float fn_8005EDCC(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m13C[ctx->m274].m0)
        result = 100.0f;
    return result;
}

float fn_8005EE0C(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (fn_80253E7C(&ctx->m130->m588, 2, 2, 0) > 4 && fn_8040ABA0() % 100 > 0x4b)
        result = 100.0f;
    return result;
}

float fn_8005EE90(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m278 <= 8 && ctx->m13C[0].m4)
        result = 100.0f;
    return result;
}

float fn_8005EED0(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m278 <= 8 && ctx->m138)
        result = 100.0f;
    return result;
}

float fn_8005EF10(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    float v[2];
    Unk8005DF2C_O700* o = ctx->m130->m44C->m700;
    int h = o->m3B0;
    fn_80235BE0(v, h);
    if (fn_8022EA7C(h, v, 1.0f) == 1)
        result = 100.0f;
    return result;
}

float fn_8005EF90(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    float v[2];
    Unk8005DF2C_O700* o = ctx->m130->m44C->m700;
    int h = o->m3B0;
    fn_80235BE0(v, h);
    if (fn_8022EA7C(h, v, 1.0f) == 0)
        result = 100.0f;
    return result;
}

float fn_8005F010(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m4D8 == 1)
        result = 100.0f;
    return result;
}

float fn_8005F044(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m4D8 == 0)
        result = 100.0f;
    return result;
}

float fn_8005F078(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    if (ctx->m4D8 == 2)
        result = 100.0f;
    return result;
}

float fn_8005F0AC(Ctx* ctx, int (*pred)(Ent*, int))
{
    int base = (int)fn_801A6D84(ctx->m130->m44C, 1);
    int end = base + 0x3d78;
    int p = base + 0x3d48;
    do {
        int ok = 1;
        if (*(int*)p == 0xc7)
            ok = 0;
        if (ok && pred((Ent*)p, 0))
            return 100.0f;
        p += 0x18;
    } while (p <= end);
    return 0.0f;
}

int fn_8005F140(Ent* e, int)
{
    if (e->m14 & 2)
        return 1;
    return 0;
}

int fn_8005F158(Ent* e, int)
{
    if (e->m14 & 0x200)
        return 1;
    return 0;
}

int fn_8005F170(Ent* e, int)
{
    if (e->m14 & 4)
        return 1;
    return 0;
}

int fn_8005F188(Ent* e, int)
{
    if (e->m14 & 8)
        return 1;
    return 0;
}

int fn_8005F1A0(Ent* e, int)
{
    return e->m0 == 0xae;
}

float fn_8005F1B4(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_8005F170);
}

float fn_8005F1E0(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_8005F188);
}

float fn_8005F20C(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_8005F1A0);
}

float fn_8005F238(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_8005F140);
}

float fn_8005F264(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_8005F158);
}

float fn_8005F290(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_80324DB4);
}

float fn_8005F2BC(void* a, int b, int c, Ctx* ctx)
{
    float t = fn_8005F20C(a, b, c, ctx);
    if (t == 100.0f)
        return 0.0f;
    return 100.0f;
}

float fn_8005F2FC(void* a, int b, int c, Ctx* ctx)
{
    return fn_8005F0AC(ctx, fn_80324E38);
}

float fn_8005F328(void* a, int b, int c, Ctx* ctx)
{
    float t = fn_8005F2FC(a, b, c, ctx);
    if (t == 100.0f)
        return 0.0f;
    return 100.0f;
}

float fn_8005F368()
{
    return 80.0f;
}

float fn_8005F374()
{
    return 90.0f;
}

float fn_8005F380()
{
    return 95.0f;
}

float fn_8005F38C(void* a, int b, int c, Ctx* ctx)
{
    float result = 100.0f;
    int v = ctx->m130->m44C->m6F8->mC->m28;
    if (v == 0x37) {
        if (lbl_8061EA68->m3E4)
            result = 0.0f;
    } else if (v == 0x19 || v == 0xa || v == 0x27 || v == 0x18 || v == 0x1e || v == 0x2d)
        result = 0.0f;
    return result;
}

/* near-miss: only the register of q differs (retail r9, here r6); 13 variants
 * (if/else, ternary, inline pick, flags local, ordering) all give r6. */
float fn_8005F418(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    Unk8005DF2C_O3B0* q = ctx->m104 > 0 ? ctx->m70[0].m0 : ctx->m3B0;
    if (q->m588.m8 & 0x20000000)
        result = 100.0f;
    return result;
}

float fn_8005F464(void* a, int b, int c, Ctx* ctx)
{
    float result = 0.0f;
    int n = ctx->m104;
    for (int i = 0; i < n; i++) {
        if (ctx->m70[i].m0->m588.m8 & 0x20000000) {
            result = 100.0f;
            break;
        }
    }
    if (ctx->m3B0->m588.m8 & 0x20000000)
        result = 100.0f;
    return result;
}
