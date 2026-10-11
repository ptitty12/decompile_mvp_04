/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80029000-0x8002B430 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"

extern const float lbl_805A6348;
extern const float lbl_805A6350;
extern const float lbl_805A6368;
extern const float lbl_805A6378;
extern const float lbl_805A6388;

extern "C" void fn_80029000(Unk80023AC4_Obj* x)
{
    x->m56C = 1;
    x->m564 = fn_801C3E28(x->m80[0]->m700->m3A4);
}

extern "C" void fn_80029044(Unk80023AC4_Obj* x)
{
    x->m570 = 1;
}

extern "C" void fn_80029050(Unk80023AC4_Obj* x)
{
    fn_800220EC(x, x->m80[0]);
}

extern "C" void fn_8002A218(Unk80023AC4_Obj* x)
{
    if (x->m6DC == 0)
        fn_800289F8(x);
}

extern "C" void fn_8002A244(Unk80023AC4_Obj* x, int id, float f)
{
    fn_800488C4(fn_800475EC(), id, f, &x->m12C, &x->m160, x->m80[0]);
}

extern "C" void fn_8002A290(Unk80023AC4_Obj* x, int i, float f)
{
    if (i >= 0)
        fn_80039790(fn_80038EB4(), f);
}

extern "C" void fn_8002A2C4(Unk80023AC4_Obj* x, float f)
{
}

/* near-miss: 62/66 insns. Retail reloads tbl->m14 before each byte-sum loop (lwz r7/r9,0x14(r8))
 * and hoists `addi r6,r9,0xe64` for the second row; here the second row's base folds into the
 * loop (addi r9,r10,4120) and the two loads merge. Tried row-pointer locals, an inline row-sum
 * helper and casts (same shape as fn_8001F788 in tu_8001F64C.cpp). */
extern "C" int fn_8002A2D4(Unk80023AC4_Obj* x)
{
    Unk8001F5CC_Tbl* t = x->mC8;
    unsigned a = 0;
    for (int i = 0; i < 0x80; i++)
        a += t->m14->e[0].m1B4[(unsigned char)i];
    unsigned b = 0;
    for (int j = 0; j < 0x80; j++)
        b += t->m14->e[1].m1B4[(unsigned char)j];
    int r = 0;
    if (a >= b + 4)
        return 2;
    if (b >= a + 4)
        return 3;
    if ((float)(t->m14->m1CC8 + 1) / (float)t->m10->m1C > lbl_805A6350)
        r = 1;
    return r;
}

extern "C" int fn_8002A3DC(Unk80023AC4_Obj* x)
{
    int r = 9;
    if (x->m634 > 2) {
        if (fn_8006BE18(x->m80[0]->m6F8) == 1) {
            r = 8;
        } else if (x->m514 == 0) {
            int v = x->m160.m40;
            if (v > 2) {
                r = 3;
            } else if (v == 0) {
                r = fn_8002A4C0(x, x->m80[0]) > 1;
            } else if (v <= 2) {
                r = 2;
            }
        } else {
            int v = x->m160.m40;
            if (v == 0) {
                r = 5;
                if (fn_8002A4C0(x, x->m80[0]) <= 1)
                    r = 4;
            } else {
                r = 7;
                if (v <= 2)
                    r = 6;
            }
        }
    }
    return r;
}

extern "C" unsigned fn_8002A4C0(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    unsigned n = 0;
    if (fn_8002A534(x, y) != 0)
        n = 1;
    if (fn_8002A53C(x, y) != 0)
        n = n + 1;
    if (fn_8002A544(x, y) != 0)
        n = n + 1;
    return n;
}

extern "C" int fn_8002A534(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    return y->m684;
}

extern "C" int fn_8002A53C(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    return y->m688;
}

extern "C" int fn_8002A544(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    return y->m68C;
}

extern "C" void fn_8002ABC4(Unk80023AC4_Obj* x)
{
    x->m12C = 0;
    x->m130.i = -1;
    for (int i = 0; i <= 2; i++) {
        if (x->m77C[i] != 0) {
            x->m12C = x->m77C[i];
            x->m130.i = x->m788[i];
            x->m77C[i] = 0;
            break;
        }
    }
    if (x->m12C != 0)
        fn_8002A244(x, 0x24, (float)x->m80[0]->m48 * lbl_805A6368);
    fn_8003CC98(x->m6C8);
}

extern "C" void fn_8002ACB8(Unk80023AC4_Obj* x, int unused, int v)
{
    int d = x->mD0;
    if (d != 0) {
        int c = x->m514;
        fn_80035A58(d, c, 1, fn_8002A2D4(x));
    }
    x->m12C = v;
    fn_8002A244(x, 0x34, (float)x->m80[0]->m48 * lbl_805A6378);
}

extern "C" void fn_8002AD50(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x5F);
    x->m774 = fn_801A4910(x->m80[0], x->m514, m->m10);
    x->m778 = m->m8;
    x->m6BC = 0;
    if (!(x->m774->m58C.m4 & 0x20000000))
        x->m160.m54 = x->m160.m54 + 1;
    else
        x->m6F5 = x->m6F5 + 1;
    if (x->m160.m54 + x->m6F4 + x->m6F5 == x->m160.m50) {
        int d = x->mD0;
        if (d != 0) {
            int c = x->m514;
            fn_80035A58(d, c, 1, fn_8002A2D4(x));
        }
        x->fn_800233B4(0x20, 1, 0);
    }
}

extern "C" void fn_8002AE4C(Unk80023AC4_Obj* x)
{
    if (x->m160.m54 + x->m6F4 + x->m6F5 == x->m160.m50) {
        x->m12C = (int)x->m774;
        x->m130.i = x->m778;
        fn_8002A244(x, 0x25, (float)x->m80[0]->m48 * lbl_805A6388);
    }
}
