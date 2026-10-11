/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8002B430-0x8002D15C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"

extern const float lbl_805A6468;
extern const float lbl_805A64B0;
extern const float lbl_805A64C0;

extern "C" int fn_8002B82C(Unk80023AC4_Obj* x)
{
    int v = x->m160.m48;
    int r = 0;
    if (v == 1)
        r = 1;
    else if (v > 1)
        r = 2;
    return r;
}

extern "C" int fn_8002BAD8(Unk80023AC4_Obj* x, int a, int b)
{
    int r = 0;
    for (int i = 0; i < x->m260; i++) {
        Unk80023ED8_Ent* e = &x->m1D0[i];
        if (e->m0 == a) {
            int v = e->m8;
            if (e->m14 == v + 1 && v == b)
                r = 1;
            e->m20 = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_8002BD04(Unk80023AC4_Obj* x, Unk80023F98_Pl* y)
{
    int r = 0;
    if (x->m160.m44 > 0) {
        r = 3;
    } else if (x->mFC == 1) {
        if (x->mDC == 0) {
            if (x->m52C > 3)
                r = 2;
            if (x->mF4 == 1)
                r = 4;
        } else if (x->m10C == 1) {
            r = 1;
        }
    }
    if (y == x->m510)
        r = 1;
    return r;
}

extern "C" void fn_8002BD80()
{
}

extern "C" void fn_8002BD84()
{
}

extern "C" void fn_8002BD88(Unk80023AC4_Obj* x)
{
    x->m6E4 = 1;
}

extern "C" void fn_8002BD94(Unk80023AC4_Obj* x)
{
    fn_80048914(fn_800475EC(), x->m80[0]);
}

extern "C" void fn_8002BDC8(Unk80023AC4_Obj* x)
{
    int v = Unk8002569C_Cast(x->m6BC, 0x6E)->m8;
    if (x->m71C != v)
        x->m71C = v;
    x->m6BC = 0;
}

extern "C" void fn_8002C274(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x43, (float)x->m80[0]->m48 * lbl_805A6468);
}

extern "C" void fn_8002C2CC()
{
}

extern "C" void fn_8002C51C(Unk80023AC4_Obj* x)
{
    fn_8003E8E4(x->m6C8);
}

extern "C" void fn_8002C66C(Unk80023AC4_Obj* x)
{
    int d = x->mD0;
    if (d != 0) {
        Unk8001F2C4_World* w = x->m80[0];
        int c = x->m514;
        unsigned n = fn_8002A4C0(x, w);
        fn_8003538C(d, c, n, fn_8002A2D4(x));
    }
}

extern "C" void fn_8002C6CC(Unk80023AC4_Obj* x)
{
    if (x->m6F8 != 0)
        fn_8002C6F8(x);
}

extern "C" void fn_8002C6F8(Unk80023AC4_Obj* x)
{
    x->m6E0 = 0;
    if (x->m6F0 == 0)
        fn_80026D7C(x);
    x->fn_800233B4(0x12, 0xA, 0);
}

extern "C" void fn_8002CC7C(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x30, (float)x->m80[0]->m48 * lbl_805A64B0);
}

extern "C" void fn_8002CCD4(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x31, (float)x->m80[0]->m48 * lbl_805A64C0);
}
