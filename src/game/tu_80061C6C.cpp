/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80061C6C-0x80063648 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80061C6C.h"

typedef Unk8005DF2C_Ctx Ctx;
typedef Unk8005DF2C_A A;
typedef Unk80060250_O O;
typedef Unk8005F4E4_Id16 Id16;
typedef Unk8005EDCC_Ent Ent;

Unk8005F4E4_G* fn_800B555C();
int fn_800B57EC();
float fn_80253F54(Unk8005DF2C_Stat* s, int a, int b, int c);
int fn_80253F0C(Unk8005DF2C_Stat* s, int a, int b, int c);
int fn_80253F9C(Unk8005DF2C_Stat* s, int a);
void fn_8001A5F0(int a, int b, int c, int d);
void fn_8000F5F4(int, int, int, int, int);
void fn_800198D4(int, int, int, int, int);
void fn_80019D4C(int, int);
int fn_8001DC58(Ctx* c);
int fn_8001DE9C(Ctx* c);
int fn_8001E054(Ctx* c);
int fn_8001F954(Ctx* c);
int fn_8001F9B4(Ctx* c);
int fn_8001F9EC(Ctx* c);
void fn_800166CC();
void fn_8001916C();
void fn_8004CC8C(Unk8005DF2C_P* p, int a, Ctx* c, int b);
void fn_8004FC60(Unk8005DF2C_P* p, Ctx* c);
void fn_8004B5C0(Unk8005DF2C_P* p, int v);
void fn_8004D738(Unk8005DF2C_P* p, int v);
void fn_80054D7C(Unk8005DF2C_P* p, int a, int b);
void fn_80054D88(Unk8005DF2C_P* p);
void fn_80019B9C(int, int, int, int, int, int, int, int);
void fn_80014D0C(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
Unk8005EDCC_T* fn_801A6D84(Unk8005DF2C_O44C* p, int a);
int fn_8001EDE4(Ctx* c);
int fn_8001D62C(Ctx* c);
int fn_8001EFB4(Ctx* c);
int fn_8001D218(Ctx* c);
int fn_8001E31C(Ctx* c);
int fn_8001DCF8(Ctx* c);
int fn_8001DA7C(Ctx* c);
int fn_8001E2EC(Ctx* c);
int fn_8001D42C(Ctx* c);
int fn_8001D454(Ctx* c);
int fn_8001EE28(Ctx* c);
int fn_8001D248(Ctx* c);
int fn_8001DA9C(Ctx* c);
int fn_8001DDD8(Ctx* c);
int fn_8001E810(Ctx* c);
int fn_8001D538(Ctx* c);
int fn_8001FDDC(Ctx* c);
int fn_8001F8B8(Ctx* c);
int fn_8001F904(Ctx* c);
int fn_8001E664(Ctx* c);
int fn_8001F030(Ctx* c);
int fn_8001D850(Ctx* c);
void fn_800128FC(int, int, int, int, int, int, int);
void fn_80018310(int, int, int, int);
void fn_80016364(int, int, int, int, int);
void fn_8000FF10(int, int, int, int, int, int, int, int);
void fn_80018284(int, int, int, int, int, int, int);
void fn_8001649C(int, int, int, int, int, int, int, int, int, int);
void fn_800197E4(int, int, int, int, int);
void fn_80019638(int, int, int, int, int, int, int, int);
void fn_80019860(int, int, int, int);
void fn_80012CFC(int, int, int, int, int, int, int, int, int, int);
void fn_80017EB0(int, int, int, int, int, int);
void fn_800104ACi(int, int, int, int, int, int, int, int, int);
void fn_800181F8(int, int, int, int, int, int, int);
void fn_800165CC(int, int, int, int, int, int, int, int, int);
void fn_80019760(int, int, int, int, int, int);
void fn_800195A4(int, int, int, int, int, int, int, int);
void fn_800196CC(int, int, int, int, int, int, int, int);
void fn_80016540(int, int, int, int, int, int, int);
void fn_80017D38(int, int, int, int, int, int, int, int, int, int, int, int);
void fn_80014C58(int, int, int, int, int, int, int, int, int, int, int, int);
void fn_800163E0(int, int, int, int, int, int, int, int, int, int, int, int, int);
void fn_80017DEC(int, int, int, int, int, int, int, int, int, int, int, int, int, int);

void fn_80061C6C()
{
}

void fn_80061C70(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0x48;
    Unk8005DF2C_O3B0* t = ctx->m3B0;
    fn_800B555C();
    int x, y, z;
    if (fn_800B57EC()) {
        Unk8005DF2C_Stat* s = &t->m588;
        x = (int)((fn_80253F54(s, 2, 2, 2) + 0.0005f) * 1000.0f);
        y = fn_80253F0C(s, 0, 2, 2);
        z = fn_80253F0C(s, 1, 2, 2);
    } else {
        Unk8005DF2C_Stat* s = &t->m588;
        x = (int)((fn_80253F54(s, 2, 2, 1) + 0.0005f) * 1000.0f);
        z = fn_80253F0C(s, 1, 2, 1);
        y = fn_80253F0C(s, 0, 2, 1);
    }
    fn_8001A5F0(0x260, x - 0xc8, z, y);
}

void fn_80061DA0(A* a, O* out, Ctx* ctx)
{
    fn_8000F5F4(1, fn_8001D42C(ctx), fn_8001DC58(ctx), fn_8001D454(ctx), fn_8001D218(ctx));
    if (ctx->m348[ctx->m130->m708].v[0] > 1 && (ctx->m278 == 0 || (ctx->m278 == 1 && ctx->m138)))
        fn_80019D4C(fn_8001E054(ctx), fn_8001DE9C(ctx));
}

void fn_80061E68(A* a, O* out, Ctx* ctx)
{
    fn_800198D4(fn_8001D454(ctx), fn_8001D42C(ctx), 1, fn_8001D218(ctx), fn_8001DE9C(ctx));
    if (ctx->m348[ctx->m130->m708].v[0] > 1 && (ctx->m278 == 0 || (ctx->m278 == 1 && ctx->m138)))
        fn_80019D4C(fn_8001E054(ctx), fn_8001DE9C(ctx));
}

void fn_80061F30(A* a, O* out, Ctx* ctx)
{
    fn_8001F954(ctx);
    fn_800166CC();
    fn_8001F954(ctx);
    fn_8001916C();
}

void fn_80061F70(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x38, ctx, -1);
    fn_8004CC8C(a->m0, 0x2e, ctx, -1);
    fn_8004CC8C(a->m0, 0x58, ctx, -1);
}

void fn_80061FD4(A* a, O* out, Ctx* ctx)
{
    fn_8004FC60(a->m0, ctx);
}

void fn_80061FFC(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0xe, ctx, -1);
}

void fn_80062028(A* a, O* out, Ctx* ctx)
{
    fn_8004B5C0(a->m0, a->m0->m9DC);
}

void fn_80062050(A* a, O* out, Ctx* ctx)
{
    fn_800128FC(fn_8001EDE4(ctx), fn_8001D62C(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001E31C(ctx), fn_8001DCF8(ctx), fn_8001DA7C(ctx));
    fn_80018310(fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001EDE4(ctx), fn_8001DCF8(ctx));
}

void fn_80062128(A* a, O* out, Ctx* ctx)
{
    fn_80016364(fn_8001EDE4(ctx), fn_8001DA7C(ctx), fn_8001E2EC(ctx), fn_8001D218(ctx), fn_8001DCF8(ctx));
    fn_80018310(fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001EDE4(ctx), fn_8001DCF8(ctx));
}

void fn_800621E0(A* a, O* out, Ctx* ctx)
{
    fn_8004D738(a->m0, a->m0->m9DC);
}

void fn_80062208(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0xf, ctx, -1);
    fn_8004CC8C(a->m0, 0x2f, ctx, -1);
}

void fn_80062258(A* a, O* out, Ctx* ctx)
{
    fn_8000FF10(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001DCF8(ctx), fn_8001EE28(ctx), fn_8001D218(ctx), fn_8001E31C(ctx), fn_8001D248(ctx));
    fn_80018284(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001D218(ctx), fn_8001DCF8(ctx), fn_8001D248(ctx), fn_8001D42C(ctx), fn_8001D454(ctx));
}

void fn_80062370(A* a, O* out, Ctx* ctx)
{
    fn_8001649C(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001D248(ctx), fn_8001D218(ctx), fn_8001EE28(ctx), fn_8001DA9C(ctx), fn_8001DCF8(ctx), fn_8001DDD8(ctx), fn_8001E2EC(ctx));
    fn_80018284(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001D218(ctx), fn_8001DCF8(ctx), fn_8001D248(ctx), fn_8001D42C(ctx), fn_8001D454(ctx));
}

void fn_800624A8(A* a, O* out, Ctx* ctx)
{
    fn_800197E4(fn_8001DCF8(ctx), fn_8001D218(ctx), fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx));
    fn_80019638(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001D218(ctx), fn_8001DCF8(ctx), fn_8001E810(ctx), fn_8001EE28(ctx), fn_8001DA9C(ctx));
}

void fn_800625A0(A* a, O* out, Ctx* ctx)
{
    fn_80019860(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001D218(ctx));
    fn_80019638(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001D218(ctx), fn_8001DCF8(ctx), fn_8001E810(ctx), fn_8001EE28(ctx), fn_8001DA9C(ctx));
}

void fn_80062688(A* a, O* out, Ctx* ctx)
{
    int v = 0;
    fn_800B555C();
    if (fn_800B57EC() && ctx->m130->m44C->m6F8->mC->m1C == 2) {
        Id16 id = fn_800B555C()->m688;
        if (id.m0 == -1 && fn_80253F9C(&ctx->m3B0->m588, 0) > 4)
            v = fn_8001F9EC(ctx);
    }
    fn_80019B9C(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001F9B4(ctx), fn_8001D218(ctx), fn_8001D62C(ctx),
                fn_8001EE28(ctx), fn_8001D538(ctx), v);
    fn_80017EB0(fn_8001D62C(ctx), fn_8001EDE4(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx),
                fn_8001FDDC(ctx));
}

void fn_80062810(A* a, O* out, Ctx* ctx)
{
    fn_80012CFC(fn_8001EDE4(ctx), fn_8001EE28(ctx), fn_8001D62C(ctx), fn_8001D218(ctx), fn_8001EFB4(ctx), fn_8001E810(ctx), fn_8001D538(ctx), fn_8001FDDC(ctx), fn_8001DA9C(ctx), fn_8001F8B8(ctx));
    fn_80017EB0(fn_8001D62C(ctx), fn_8001EDE4(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001FDDC(ctx));
}

void fn_80062938(A* a, O* out, Ctx* ctx)
{
    fn_800104ACi(fn_8001EDE4(ctx), fn_8001EFB4(ctx), fn_8001DA9C(ctx), fn_8001D218(ctx), fn_8001F8B8(ctx), fn_8001D248(ctx), fn_8001E31C(ctx), fn_8001D42C(ctx), fn_8001D454(ctx));
    fn_800181F8(fn_8001DA9C(ctx), fn_8001D218(ctx), fn_8001EE28(ctx), fn_8001EDE4(ctx), fn_8001EFB4(ctx), fn_8001D248(ctx), fn_8001F8B8(ctx));
}

void fn_80062A60(A* a, O* out, Ctx* ctx)
{
    fn_800165CC(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001DA9C(ctx), fn_8001D454(ctx), fn_8001E2EC(ctx), fn_8001F904(ctx), fn_8001D218(ctx), fn_8001EFB4(ctx), fn_8001EE28(ctx));
    fn_800181F8(fn_8001DA9C(ctx), fn_8001D218(ctx), fn_8001EE28(ctx), fn_8001EDE4(ctx), fn_8001EFB4(ctx), fn_8001D248(ctx), fn_8001F904(ctx));
}

void fn_80062B88(A* a, O* out, Ctx* ctx)
{
    fn_80019760(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001D454(ctx), fn_8001D218(ctx), fn_8001D42C(ctx), fn_8001E664(ctx));
    fn_800195A4(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001D218(ctx), fn_8001D62C(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx));
}

void fn_80062C90(A* a, O* out, Ctx* ctx)
{
    fn_800196CC(fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001EE28(ctx), fn_8001D218(ctx), fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001F030(ctx), fn_8001EFB4(ctx));
    fn_800195A4(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001D218(ctx), fn_8001D62C(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx));
}

void fn_80062DB8(A* a, O* out, Ctx* ctx)
{
    fn_80016540(fn_8001EDE4(ctx), fn_8001D42C(ctx), fn_8001D454(ctx), fn_8001EFB4(ctx), fn_8001DA9C(ctx), fn_8001EE28(ctx), fn_8001D218(ctx));
    fn_80017D38(fn_8001DA9C(ctx), fn_8001E664(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001EDE4(ctx), fn_8001D62C(ctx), fn_8001D454(ctx), fn_8001D248(ctx), fn_8001DCF8(ctx), fn_8001D850(ctx), fn_8001D42C(ctx));
}

void fn_80062F10(A* a, O* out, Ctx* ctx)
{
    fn_80014C58(fn_8001EDE4(ctx), fn_8001D454(ctx), fn_8001EE28(ctx), fn_8001D62C(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001DA9C(ctx), fn_8001E664(ctx), fn_8001D248(ctx), fn_8001E810(ctx), fn_8001D850(ctx), fn_8001D42C(ctx));
    fn_80017D38(fn_8001DA9C(ctx), fn_8001E664(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001EDE4(ctx), fn_8001D62C(ctx), fn_8001D454(ctx), fn_8001D248(ctx), fn_8001DCF8(ctx), fn_8001D850(ctx), fn_8001D42C(ctx));
}

void fn_800630B8(A* a, O* out, Ctx* ctx)
{
    fn_800163E0(fn_8001EE28(ctx), fn_8001F904(ctx), fn_8001D62C(ctx), fn_8001DCF8(ctx), fn_8001D218(ctx), fn_8001EFB4(ctx), fn_8001D248(ctx), fn_8001D538(ctx), fn_8001EDE4(ctx), fn_8001DDD8(ctx), fn_8001DA9C(ctx), fn_8001E664(ctx), fn_8001D454(ctx));
    fn_80017DEC(fn_8001DA9C(ctx), fn_8001EDE4(ctx), fn_8001EE28(ctx), fn_8001EFB4(ctx), fn_8001D218(ctx), fn_8001D62C(ctx), fn_8001DCF8(ctx), fn_8001F904(ctx), fn_8001E810(ctx), fn_8001D538(ctx), fn_8001D248(ctx), fn_8001D454(ctx), fn_8001D42C(ctx), fn_8001DDD8(ctx));
}

void fn_80063290(A* a, O* out, Ctx* ctx)
{
    int p = fn_8001DA9C(ctx);
    int b = fn_8001DCF8(ctx);
    int c = fn_8001EE28(ctx);
    int d = fn_8001EFB4(ctx);
    if (d == 2) {
        if (((c & 4) && (b & 4)) || ((c & 2) && (b & 2))) {
            if (((c & 8) && (b & 8)) || ((c & 0x10) && (b & 0x10)))
                d = 0;
        } else if ((c & 1) && (b & 1))
            d = 0;
    }
    fn_80014D0C(c, fn_8001F8B8(ctx), fn_8001D62C(ctx), b, fn_8001D218(ctx), d, fn_8001D248(ctx), fn_8001E810(ctx),
                fn_8001D538(ctx), fn_8001EDE4(ctx), p, fn_8001D454(ctx), fn_8001D42C(ctx), fn_8001DDD8(ctx));
    fn_80017DEC(p, fn_8001EDE4(ctx), c, d, fn_8001D218(ctx), fn_8001D62C(ctx), b, fn_8001F8B8(ctx), fn_8001E810(ctx),
                fn_8001D538(ctx), fn_8001D248(ctx), fn_8001D454(ctx), fn_8001D42C(ctx), fn_8001DDD8(ctx));
}

void fn_800634A4(A* a, O* out, Ctx* ctx)
{
    fn_80018310(fn_8001EFB4(ctx), fn_8001D218(ctx), 0, fn_8001DCF8(ctx));
}

void fn_80063500(A* a, Ctx* ctx, Ent* e)
{
    fn_80054D7C(a->m0, e->m8, e->mC);
    fn_8004CC8C(a->m0, 0x26, ctx, -1);
    fn_8004CC8C(a->m0, 0x27, ctx, -1);
    fn_8004CC8C(a->m0, 0x28, ctx, -1);
    fn_8004CC8C(a->m0, 0x32, ctx, -1);
    fn_8004CC8C(a->m0, 0x20, ctx, -1);
    fn_80054D88(a->m0);
}

void fn_800635AC(A* a, O* out, Ctx* ctx)
{
    Unk8005EDCC_T* t = fn_801A6D84(ctx->m130->m44C, 1);
    Ent* p = &t->m3D48[0];
    int ok = 1;
    if (p->m0 == 0xc7)
        ok = 0;
    if (ok) {
        Ent e = *p;
        fn_80063500(a, ctx, &e);
    }
}

