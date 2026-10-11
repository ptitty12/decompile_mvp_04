/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80021BE8-0x800239F4 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80021BE8.h"

extern const float lbl_805A5FFC;
extern int lbl_805B19F0[];

void Unk80021A60::fn_vslot10()
{
    for (int i = 0; i < 10; i++) {
        e[i].m4 = 0;
        e[i].m8 = 0;
        e[i].m0 = -1;
    }
}

extern "C" void fn_80021C1C(void* x, Unk8001F2C4_World* ctx)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, fn_801A4B34(ctx)->m60);
    fn_800412AC(fn_8004072C(), 0xC, sx, sy, 0x64, 0);
}

extern "C" void fn_80021C9C(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Vec3 pos)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, pos);
    fn_800412AC(fn_8004072C(), 1, sx, sy, 0x1F4, 0);
}

extern "C" void fn_80021D04(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Vec3 pos)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, pos);
    fn_800412AC(fn_8004072C(), 2, sx, sy, 0, 0);
}

extern "C" void fn_80021D6C(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, int n)
{
    int sx, sy;
    int v = n;
    Unk801A4B34_Pos* p = fn_801A4B34(ctx);
    if (v > 0x78)
        v = 0x78;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    if (fn_801C3F00(ctx->m700->m3A4)) {
        fn_800412AC(fn_8004072C(), 3, sx, sy, v, 0);
        return;
    }
    fn_800412AC(fn_8004072C(), 0, sx, sy, v, 0);
}

extern "C" void fn_80021E30(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, int n)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, fn_801A4B34(ctx)->m60);
    fn_800412AC(fn_8004072C(), 0xA, sx, sy, n, 0);
}

extern "C" void fn_80021EB4(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, int a, int b, int n)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, ctx->m6CC->m60);
    if (a == 1 && b == 2) {
        fn_800412AC(fn_8004072C(), 7, sx, sy, n, 0);
        return;
    }
    fn_800412AC(fn_8004072C(), 6, sx, sy, n, 0);
}

/* near-miss: 70/70 insns, 2 slots differ: retail loads `li r4,1` before `mr r3,r31` for the
 * fn_801A6D84(ctx, 1) call (plain call, method call and an int temp all give mr first). */
extern "C" void fn_80021F68(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    int flag = 0;
    int id = p->m458;
    if (ctx->m780 != 0 || ctx->m784 != 0)
        flag = 1;
    int one = 1;
    if (flag != 0 || (ctx->fn_801A6D84(one), fn_8016ADC4() != 0)) {
        if (id == 16) {
            fn_800412AC(fn_8004072C(), 7, 0xA, sy, 0x5F, 0);
        } else if (id == 15) {
            fn_800412AC(fn_8004072C(), 6, 0xA, sy, 0x55, 0);
        }
    } else {
        if (id == 1) {
            fn_800412AC(fn_8004072C(), 7, 0xA, sy, 0x5F, 0);
        } else if (id == 0) {
            fn_800412AC(fn_8004072C(), 6, 0xA, sy, 0x55, 0);
        }
    }
}

extern "C" void fn_80022080(void* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    fn_800412AC(fn_8004072C(), 0xB, sx, sy, 0, 0);
}

extern "C" void fn_800220EC()
{
    fn_800412AC(fn_8004072C(), 0x33, 0x64, 1, 0, 0);
}

extern "C" void fn_80022124(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p, int a, int n)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    if (p != ctx->m6CC)
        sx = 10;
    if (a == 1) {
        fn_800412AC(fn_8004072C(), 5, sx, sy, n, 0);
        return;
    }
    fn_800412AC(fn_8004072C(), 4, sx, sy, n, 0);
}

extern "C" void fn_800221E4(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p, int n)
{
    int sx, sy;
    Unk801A4B34_Vec3 a = p->m60;
    fn_800222B4(ctx, &sx, &sy, a);
    fn_800412AC(fn_8004072C(), 0x40, sx, sy, n, 0);
}

extern "C" void fn_80022270(Unk8001E444_Obj* x, int a, int n)
{
    fn_800412AC(fn_8004072C(), 0x40, 0x12, 0, n, 0);
}

extern "C" int fn_80022708(int unused, int idx)
{
    int r = -1;
    if (idx != -1 && idx <= 3)
        r = lbl_805B19F0[idx];
    return r;
}

extern "C" int fn_80022730(int unused, int b, int c)
{
    int r = -1;
    if (b == 0)
        r = 0;
    else if (b == 1 || b == 2) {
        r = 2;
        if (c != 0)
            r = 1;
    } else if (b == 3) {
        r = 4;
        if (c != 0)
            r = 3;
    }
    return r;
}

extern "C" void fn_80022D64(Unk80021A60_Data* x, Unk801A4B34_Vec3* a, Unk801A4B34_Vec3* b, Unk801A4B34_Vec3* c)
{
    x->m90 = fn_804028E4(a->x * a->x + a->z * a->z) * lbl_805A5FFC;
    x->m94 = fn_804028E4(b->x * b->x + b->z * b->z) * lbl_805A5FFC;
    x->m98 = fn_804028E4(c->x * c->x + c->z * c->z) * lbl_805A5FFC;
}

int Unk80021A60::fn_800232A0(int kind, int v)
{
    int r = 1;
    switch (kind) {
    case 0:
        if ((float)v >= m8C->m54)
            r = 2;
        else if (!((float)v > m8C->m58))
            r = 0;
        break;
    case 1:
        if ((float)v >= m8C->m2C)
            r = 2;
        else if (!((float)v > m8C->m30))
            r = 0;
        break;
    case 2:
        if (!((float)v < m8C->m70))
            r = 2;
        else if (!((float)v > m8C->m74))
            r = 0;
        break;
    case 3:
        break;
    default:
        r = -1;
        break;
    }
    return r;
}

int Unk80021A60::fn_800233B4(int a, int b, int c)
{
    int ok = 0;
    for (int i = 0; i < 10; i++) {
        if (e[i].m4 == 0) {
            e[i].m4 = b;
            e[i].m0 = a;
            ok = 1;
            e[i].m8 = c;
            mB4++;
            break;
        }
    }
    return ok;
}

int Unk80021A60::fn_80023430(int key, int unused, int* out)
{
    int found = 0;
    if (mB4) {
        for (int i = 0; i <= 9; i++) {
            if (key == e[i].m0 && e[i].m4 != 0) {
                if (out)
                    *out = e[i].m4;
                found = 1;
                break;
            }
        }
    }
    return found;
}

void Unk80021A60::fn_80023490(int key, int unused)
{
    if (mB4 == 0)
        return;
    for (int i = 0; i < 10; i++) {
        if (key == e[i].m0 && e[i].m4 != 0)
            e[i].m4 = 0;
    }
}
