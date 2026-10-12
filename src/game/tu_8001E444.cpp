/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001E444-0x8001F64C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8001E444.h"

extern const float lbl_805A5360;
extern const float lbl_805A5364;
extern const float lbl_805A5368;
extern const float lbl_805A536C;
extern const float lbl_805A5370;

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

extern int lbl_805B19D0[];
int fn_80253678(void* p);
int fn_80254228(void* p, int a, int b);
extern "C" int fn_80046B98(float f);
struct Unk8024EF40_W;
float fn_80253F54(Unk8024EF40_W* p, int a, int b, int c);

extern "C" int fn_8001E4F4(Unk8001E444_Obj* x)
{
    Unk8001E444_Owner* o = x->m130;
    Unk8001F5CC_Ent* e = (Unk8001F5CC_Ent*)((char*)o->m44C->m6F8->m14 + x->m3B0->m708 * 0xE64);
    int c = e->m19C;
    int h = fn_80253678(o->m480);
    int v = fn_80254228(x->m3B0->m588, 0, h);
    float d = 2.0f * (float)lbl_805B19D0[c];
    float ratio = ((float)v / d) <? 1.0f;
    int r = fn_80046B98(ratio);
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        float q = fn_80253F54((Unk8024EF40_W*)x->m3B0->m588, 2, 2, 1);
        if ((unsigned)(r - 1) <= 1) {
            if (!(q >= 0.275f))
                r = 0;
        } else if ((r == 4 || r == 8) && !(q < 0.275f)) {
            r = 0;
        }
    }
    return r;
}


extern int lbl_805B19E0[];
int fn_80097520(Unk8001F5CC_Ent* row, int id);
void fn_800446D8(float b, float c, int a);

extern "C" void fn_8001E664(Unk8001E444_Obj* x)
{
    Unk8001E444_Owner* o = x->m130;
    Unk8001F5CC_Tbl* t = o->m44C->m6F8;
    Unk8001F5CC_Ent* e = (Unk8001F5CC_Ent*)((char*)t->m14 + x->m3B0->m708 * 0xE64);
    int c = e->m19C;
    int h = fn_80253678(o->m480);
    int a = fn_80254228(x->m3B0->m588, 0, h);
    int b = fn_80254228(x->m3B0->m588, 1, h);
    float d1 = 2.0f * (float)lbl_805B19E0[c];
    float d0 = 2.0f * (float)lbl_805B19D0[c];
    float p10 = ((float)b / d1) <? 1.0f;
    float p14 = ((float)a / d0) <? 1.0f;
    int z = t->m14->m1CD0 == 0;
    Unk8001F5CC_Ent* row = &t->m14->e[z];
    fn_800446D8(p14, p10, fn_80097520(row, x->m130->m704));
}

extern "C" void fn_8001E810(Unk8001E444_Obj* x)
{
    int a = x->m154[x->m274].m4;
    int b = x->m154[x->m274].m0;
    fn_8004390C(fn_8001D1A4(x, x->m130->m704, b, a));
}

/* near-miss: 64/66 insns. Retail keeps lbl_805A5360/lbl_805A5368 in f30/f31 across both calls
 * (they are stored with the local triple at sp8..sp10) and reloads the other constants; two
 * fewer instructions here (the float temporaries are scheduled differently). Tried array,
 * Vec3 and const-float locals. */
extern "C" int fn_8001EB78(Unk8001E444_Obj* x)
{
    Unk801A4B34_Vec3 a;
    a.x = lbl_805A5360;
    a.y = lbl_805A5364;
    a.z = lbl_805A5368;
    int r = 0;
    Unk801A4B34_Vec3 b;
    b.x = fn_80254330(x->m130->m588, 0);
    b.y = lbl_805A536C;
    b.z = lbl_805A5370;
    float v1 = fn_80254330(x->m130->m588, 1);
    if (!(b.x > a.z))
        r = 2;
    else if (!(b.x < a.x))
        r = 1;
    if (!(v1 > lbl_805A5370) && !(b.x <= lbl_805A5364))
        r |= 0x10;
    else if (!(v1 < lbl_805A536C))
        r |= 8;
    return r;
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

/* near-miss: 99/99 insns, branch targets only: retail shares one `li r30,4` block between the
 * cases 0, 1 and 2 (separate compares, one body); here the three identical bodies are not
 * cross-jumped. Fallthrough labels give a range compare instead; default/if-chain forms differ more. */
extern "C" int fn_8001EE28(Unk8001E444_Obj* x)
{
    int r = 0;
    int buf[3];
    int* b = buf;
    Unk801A4B34_Pos* pp = x->m130->m44C->m6CC;
    int pl = x->m130->m44C->m700->m3B0;
    fn_80235C18(b, pl);
    if (fn_8022EC70(pl) != 0)
        return 0x2000;
    int c = fn_8018CE28(pp, ((Unk80023F98_Pl*)x->m3B0)->fn_vslot24(), b);
    switch (c) {
    case 0:
        r = 4;
        break;
    case 1:
        r = 4;
        break;
    case 2:
        r = 4;
        break;
    case 3:
        r = 1;
        break;
    case 4:
        r = 0x10;
        break;
    case 5:
        r = 8;
        break;
    case 6:
        r = 2;
        break;
    case 7:
        r = 0x22;
        break;
    case 8:
        r = 0x42;
        break;
    }
    if (fn_8022EAF4(pl, b) != 0) {
        r |= 0x1800;
        switch (c) {
        case 1:
            r |= 0x180;
            break;
        case 2:
            r |= 0x600;
            break;
        case 7:
            r |= 0x80;
            break;
        case 8:
            r |= 0x400;
            break;
        }
    }
    return r;
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
