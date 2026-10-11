/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001E444-0x8001F64C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8001E444.h"

extern "C" int fn_8001E444(Unk8001E444_Obj* x)
{
    float a = fn_80254474(x->m3B0->m588, 0, 0);
    float b = fn_80254474(x->m3B0->m588, 1, 0);
    float c = fn_80254474(x->m3B0->m588, 0, 1);
    float d = fn_80254474(x->m3B0->m588, 1, 1);
    int r = 1;
    if (!(a + b > c + d))
        r = 2;
    return r;
}

extern "C" void fn_8001E810(Unk8001E444_Obj* x)
{
    int a = x->m154[x->m274].m4;
    int b = x->m154[x->m274].m0;
    fn_8004390C(fn_8001D1A4(x, x->m130->m704, b, a));
}

extern "C" void fn_8001EC80(Unk8001E444_Obj* x)
{
    int sz;
    int* arr;
    Unk8001F5CC_Tbl* t = x->m130->m44C->m6F8;
    int idx = x->m130->m708;
    Unk8001F218_Pair* base = t->m14;
    int n = fn_800638F0(t, base, idx, fn_80097210(&base->e[0] + idx, 0), &sz, &arr);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0x50)
            c++;
    }
    if (c == 0)
        c = 1;
    fn_8004378C(c);
}

/* near-miss: 22/22 insns, 2 slots differ: retail sets up the array address (addi r4,r1,8)
 * before the move of x into r3; member-call, temp and &arr[0] forms give the same order. */
extern "C" void fn_8001ED28(Unk8001E444_Obj* x)
{
    Unk80344538_Rec arr[5];
    fn_800437AC(fn_8001CF18(x, arr));
}

extern "C" void fn_8001ED80(Unk8001E444_Obj* x)
{
    fn_80043650(fn_8025416C(x->m130->m588, 9) == 1);
}

extern "C" void fn_8001EDBC(Unk8001E444_Obj* x)
{
    fn_80045FEC(x->m3B0->m388);
}

extern "C" int fn_8001EDE4(Unk8001E444_Obj* x)
{
    if ((unsigned)(x->m408 - 4) > 3) {
        if (x->m410)
            return 4;
        if (x->m40C)
            return 1;
        return 2;
    }
    return 0;
}

extern "C" int fn_8001EFB4(Unk8001E444_Obj* x)
{
    int r = 0;
    int p = x->m130->m44C->m720;
    if (fn_802F922C(p))
        r = 1;
    else if (fn_802F92CC(p))
        r = 2;
    else if (fn_802F92A4(p))
        r = 4;
    return r;
}

extern "C" void fn_8001F218(Unk8001E444_Obj* x)
{
    Unk8001F218_Pair* base = x->m130->m44C->m6F8->m14;
    int sel = base->m1CD0 == 0;
    Unk8001F5CC_Ent* e = base->e + sel;
    float f = fn_80254618(x->m130->m588, 0);
    if (fn_80097318(e, x->m130->m704) == 0)
        fn_80046DCC(f);
    else
        fn_80046D30(f);
}

extern "C" void fn_8001F2A0(Unk8001E444_Obj* x)
{
    fn_80045024(x->m0);
}

extern "C" void fn_8001F2C4(Unk8001E444_Obj* x)
{
    fn_8009E1D4((char*)x->m130->m44C->m6F8->m14 + 0x8C, 2, 0);
}

extern "C" void fn_8001F300(Unk8001E444_Obj* x)
{
    fn_8009E1D4((char*)x->m130->m44C->m6F8->m14 + 0xEF0, 2, 0);
}

extern "C" void fn_8001F33C(Unk8001E444_Obj* x)
{
    fn_8004618C(fn_8025416C(x->m3B0->m588, 0) > 0x4E1F);
}

extern "C" int fn_8001F378()
{
    int r = 2;
    fn_800B555C();
    if (fn_800B57EC())
        r = 1;
    return r;
}

/* near-miss: 17/17 insns, 2 slots differ. Retail tests y first (mr. r4,r4) and then
 * loads r3 = 0 in the branch delay; every form tried (ternary, &&, if/else, bool/int
 * temps) puts the li r3,0 before the test or adds a join branch. */
extern "C" void fn_8001F3B8(Unk8001E444_Obj* x, Unk8001E444_Char* y)
{
    fn_8004618C(y && fn_8025416C(y->m588, 0) > 0x4E1F);
}

extern "C" void fn_8001F3FC(Unk8001E444_Obj* x, Unk8001E444_Char* y)
{
    int id = -1;
    if (y)
        id = y->m460;
    fn_80043B78(id);
}

extern "C" void fn_8001F42C(Unk8001E444_Obj* x, Unk8001E444_Char* y)
{
    int id = -1;
    if (y)
        id = y->m460;
    fn_80046780(id);
}

extern "C" int fn_8001F45C(Unk8001E444_Obj* x, Unk8001E444_Char* y)
{
    int r = 0;
    if (y)
        r = fn_8025416C(y->m588, 0);
    return r;
}

extern "C" int fn_8001F490(Unk8001E444_Obj* x, Unk8001E444_Char* y)
{
    int r = 0;
    if (y) {
        float f = fn_8025454C(y->m588, 0x10);
        r = fn_800458C0(f);
    }
    return r;
}

extern "C" void fn_8001F4D0()
{
    fn_800474A4();
}

extern "C" void fn_8001F4F0()
{
    fn_800433CC();
}

extern "C" int fn_8001F510(Unk8001E444_Obj* x)
{
    Unk8001F2C4_World* w = x->m130->m44C;
    Unk801A4B34_Pos* c = fn_801A4B34(w);
    int a = fn_80045BD8(fn_801A497C(w, w->m6F8->m14->m1CD0 == 0, 0));
    int b = fn_80045BD8(c);
    int r = 0;
    if (a == 1 && b == 1)
        r = 4;
    else if (a == 1 && b == 2)
        r = 8;
    else if (a == 2 && b == 1)
        r = 2;
    else if (a == 2 && b == 2)
        r = 1;
    return r;
}

extern "C" void fn_8001F5CC(Unk8001E444_Obj* x)
{
    fn_8009E1D4((char*)x->m130->m44C->m6F8->m14 + x->m3B4 * 0xE64 + 0x8C, 2, 0);
}

extern "C" void fn_8001F614(Unk8001E444_Obj* x)
{
    fn_80046160(x->m0, x->m130->m44C->m6F8->m10->m1C);
}
