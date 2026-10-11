/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80060F94-0x80061C6C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80060F94.h"

typedef Unk8005DF2C_Ctx Ctx;
typedef Unk8005DF2C_A A;
typedef Unk80060250_O O;

extern Unk80060F94_G0* lbl_806192E0;

Unk8005DF2C_O3B0* fn_801A497C(Unk8005DF2C_O44C* p, int a, int b);
float fn_8025454C(Unk8005DF2C_Stat* s, int idx);
int fn_80045F28();
void fn_80017184(int a, int b);
int fn_800968C0(Unk8005DF2C_Y* y, int a, int b);
int fn_8008CFD8(char* p, int a, unsigned char b);
int fn_80045F88(float f);
int fn_80045FEC(int v);
int fn_8001D62C(Ctx* c);
int fn_8001E054(Ctx* c);
void fn_80013994(int a, int b, int c, int d, int e, int f);
int fn_8001DE9C(Ctx* c);
void fn_80013A18(int a, int b, int c);
int fn_8025416C(Unk8005DF2C_Stat* s, int a);
void fn_8001D204(Ctx* c, int v);
int fn_8004390C();
void fn_80013BB8(int a, int b, int c);
int fn_80043B78(int a);
void fn_80013C24(int a, int b);
int fn_8001F490(Ctx* c, int v);
int fn_8001F3FC(Ctx* c, int v);
void fn_80018B40(int a, int b);
int fn_800433CC(Ctx* c);
void fn_80018ADC(int a, int b);
void fn_80014FD0();
void fn_8004CC8C(Unk8005DF2C_P* p, int a, Ctx* c, int b);
void fn_80019048(int a);
int fn_8001F2A0(Ctx* c);
int fn_8001DC58(Ctx* c);
int fn_8001DA7C(Ctx* c);
void fn_80013304(int a, int b, int c);
void fn_80017BD8();

int fn_8009DC00(Unk8005DF2C_Y* y, unsigned char v, int i, int c);
int fn_8040ABA0();
int fn_8004740C(int v);
void fn_80016970(int a, int b, int c, int d, int e);
void fn_800169EC(int a, int b, int c, int d, int e);

inline int RandMod(int n)
{
    return n > 0 ? fn_8040ABA0() % n : 0;
}

void fn_80060F94(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0xf6;
    fn_8025454C(&fn_801A497C(ctx->m130->m44C, ctx->m3B4 == 0, 6)->m588, 0xe);
    fn_80017184(0x100, fn_80045F28());
}

void fn_80060FF4(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0xf6;
    fn_8025454C(&fn_801A497C(ctx->m130->m44C, ctx->m3B4 == 0, 8)->m588, 0xe);
    fn_80017184(0x40, fn_80045F28());
}

void fn_80061054(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0x55;
    float f = fn_8025454C(&ctx->m3B0->m588, 0xd);
    Unk8005DF2C_O3B0* t = ctx->m3B0;
    Unk8005DF2C_Y* y = lbl_806192E0->m4->m14 + t->m708;
    unsigned char v = fn_800968C0(y, t->m704, 1);
    int r = fn_8008CFD8(&y->mC9C, 8, v);
    int p = fn_80045F88(f);
    int q = fn_80045FEC(r);
    int s = fn_8001D62C(ctx);
    fn_80013994(4, p, q, 0, s, fn_8001E054(ctx));
}

void fn_80061124(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0x55;
    int s = fn_8001D62C(ctx);
    fn_80013994(1, 0, 0, 0, s, fn_8001E054(ctx));
}

void fn_80061184(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0xbc;
    fn_80013A18(2, 2, fn_8001DE9C(ctx));
}

void fn_800611C0(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0xbc;
    fn_80013A18(2, 1, fn_8001DE9C(ctx));
}

void fn_800611FC(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0x168;
    fn_8001D204(ctx, fn_8025416C(&ctx->m130->m588, 0x16));
    fn_80013BB8(1, fn_8004390C(), 0);
}

void fn_8006125C(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0x168;
    fn_8001D204(ctx, fn_8025416C(&ctx->m130->m588, 0x16));
    fn_80013BB8(0, fn_8004390C(), 1);
}

void fn_800612BC(A* a, O* out, Ctx* ctx)
{
    out->m4 = 0x144;
    int found = 0;
    int i;
    for (i = 8; i > 5; i--) {
        if (!(fn_8025454C(&fn_801A497C(ctx->m130->m44C, ctx->m3B4 == 0, i)->m588, 0xe) < 0.75f)) {
            found = 1;
            break;
        }
    }
    if (found != 1)
        i = -1;
    fn_80013C24(fn_80043B78(i), found);
}

void fn_8006135C()
{
}

void fn_80061360(A* a, O* out, Ctx* ctx)
{
    int v = a->m0->mA14;
    int r = fn_8001F490(ctx, v);
    fn_80018B40(r, fn_8001F3FC(ctx, v));
}

void fn_800613B8(A* a, O* out, Ctx* ctx)
{
    int v = a->m0->mA14;
    int r = fn_800433CC(ctx);
    fn_80018ADC(r, fn_8001F3FC(ctx, v));
}

void fn_8006140C(A* a, O* out, Ctx* ctx)
{
    fn_8001F3FC(ctx, a->m0->mA14);
    fn_80014FD0();
}

void fn_8006143C(A* a, O* out, Ctx* ctx)
{
    int cand[8];
    int n = 0;
    int kind = 0;
    Unk8005DF2C_Y* y = lbl_806192E0->m4->m14 + ctx->m130->m708;
    int v = fn_800968C0(y, ctx->m130->m704, 1);
    int i;
    for (i = 0; i <= 7; i++) {
        if (fn_8009DC00(y, v, i, 1) == 0) {
            kind = 1;
            cand[n] = i;
            n++;
        }
    }
    if (n == 0) {
        for (i = 0; i <= 7; i++) {
            if ((unsigned char)fn_8009DC00(y, v, i, 1) <= 4) {
                kind = 2;
                cand[n] = i;
                n++;
            }
        }
        if (n == 0) {
            for (i = 0; i <= 7; i++) {
                if ((unsigned char)fn_8009DC00(y, v, i, 1) <= 9) {
                    kind = 4;
                    cand[n] = i;
                    n++;
                }
            }
        }
    }
    if (n > 0) {
        int sel[3] = { -1, -1, -1 };
        int np = 0;
        while (np <= 2 && np < n) {
            int r = RandMod(n);
            i = 0;
            int fresh = 1;
            while (i < np) {
                if (sel[i] == r) {
                    fresh = 0;
                    break;
                }
                i++;
            }
            if (fresh) {
                sel[i] = r;
                np++;
            }
        }
        int a1 = fn_8004740C(cand[sel[0]]);
        int a2 = fn_8004740C(cand[sel[1]]);
        fn_80016970(a1, kind, 1, a2, fn_8004740C(cand[sel[2]]));
    }
}

void fn_80061698(A* a, O* out, Ctx* ctx)
{
    int cand[8];
    int n = 0;
    int kind = 0;
    Unk8005DF2C_Y* y = lbl_806192E0->m4->m14 + ctx->m130->m708;
    int v = fn_800968C0(y, ctx->m130->m704, 1);
    int i;
    for (i = 0; i <= 7; i++) {
        if (fn_8009DC00(y, v, i, 0) == 0) {
            kind = 1;
            cand[n] = i;
            n++;
        }
    }
    if (n == 0) {
        for (i = 0; i <= 7; i++) {
            if ((unsigned char)fn_8009DC00(y, v, i, 0) <= 4) {
                kind = 2;
                cand[n] = i;
                n++;
            }
        }
        if (n == 0) {
            for (i = 0; i <= 7; i++) {
                if ((unsigned char)fn_8009DC00(y, v, i, 0) <= 9) {
                    kind = 4;
                    cand[n] = i;
                    n++;
                }
            }
        }
    }
    if (n > 0) {
        int sel[3] = { -1, -1, -1 };
        int np = 0;
        while (np <= 2 && np < n) {
            int r = RandMod(n);
            i = 0;
            int fresh = 1;
            while (i < np) {
                if (sel[i] == r) {
                    fresh = 0;
                    break;
                }
                i++;
            }
            if (fresh) {
                sel[i] = r;
                np++;
            }
        }
        int a1 = fn_8004740C(cand[sel[0]]);
        int a2 = fn_8004740C(cand[sel[1]]);
        fn_800169EC(a1, kind, 1, a2, fn_8004740C(cand[sel[2]]));
    }
}

void fn_800618F4()
{
}

void fn_800618F8(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x20, ctx, -1);
}

void fn_80061924(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x1b, ctx, -1);
}

void fn_80061950(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x14, ctx, -1);
    fn_8004CC8C(a->m0, 0x1c, ctx, -1);
    fn_8004CC8C(a->m0, 0x24, ctx, -1);
}

void fn_800619B4(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x45, ctx, -1);
}

void fn_800619E0(A* a, O* out, Ctx* ctx)
{
    fn_80061924(a, out, ctx);
    fn_800618F8(a, out, ctx);
}

void fn_80061A24(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x24, ctx, -1);
    fn_8004CC8C(a->m0, 0x1c, ctx, -1);
    fn_8004CC8C(a->m0, 0x25, ctx, -1);
}

void fn_80061A88(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 8, ctx, -1);
}

void fn_80061AB4()
{
    fn_80019048(1);
}

void fn_80061AD8(A* a, O* out, Ctx* ctx)
{
    int r28 = fn_8001F2A0(ctx);
    int r29 = fn_8001DC58(ctx);
    fn_80013304(r28, r29, fn_8001DA7C(ctx));
    fn_80017BD8();
}

void fn_80061B34()
{
}

void fn_80061B38(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x11, ctx, -1);
    fn_8004CC8C(a->m0, 0x26, ctx, -1);
    fn_8004CC8C(a->m0, 0x27, ctx, -1);
    fn_8004CC8C(a->m0, 0x28, ctx, -1);
    fn_8004CC8C(a->m0, 6, ctx, -1);
    fn_8004CC8C(a->m0, 0x4f, ctx, -1);
    fn_8004CC8C(a->m0, 0x32, ctx, -1);
}

void fn_80061BEC(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x14, ctx, -1);
    fn_8004CC8C(a->m0, 0x67, ctx, -1);
}

void fn_80061C3C(A* a, O* out, Ctx* ctx)
{
    fn_8004CC8C(a->m0, 0x1a, ctx, -1);
}

void fn_80061C68()
{
}
