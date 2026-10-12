/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8004E364-0x80050A68 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8004E364.h"

void fn_8004EAD4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D8 == 3 && s->mA60 == 0) {
        s->mA60 = 1;
        fn_80010AA4();
        if (((Unk80069F0C*)a->m130->m44C->m6F8)->fn_8006BE18() != 0)
            fn_80050324(s, idx, a, 0, 0);
    }
}

void fn_8004EB58(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D8 > 0) {
        fn_8004FBE4(s, a);
        if (a->m4D8 == 2)
            fn_8004E954(s, idx, a);
        else if (a->m4D8 == 3)
            fn_8004EAD4(s, idx, a);
    }
}

void fn_8004EC18(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m54 == 0 && a->m40C != 0) {
        char* b8 = (char*)s + 8;
        int off = idx * 0x48;
        if (*(int*)(b8 + off) == 1) {
            char* b4 = (char*)s + 4;
            Unk8004EC18_Q* q = (Unk8004EC18_Q*)(*(char**)(b4 + off) + 0x58C);
            if (((q->m4 & 0x20000000) != 0 || q->m3C == 0) && (a->m3BC == 0 || a->m3E8 != 0) && s->mA84 == 0)
                fn_80013AE8();
        }
    }
}

/* near-miss: retail computes addi r9,r3,4 then lwzx (index in r0); here mulli/add/lwz 4(r9) */
void fn_8004EBD4(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 4;
    if (idx >= 0 && *(int*)(b + idx * 0x48) != 0) {
        fn_8001A714();
        return;
    }
    fn_800106A4();
}

void fn_8004FBE4(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    if (a->m3D0 < *lbl_8061B9C4 && a->m448 == 4 && a->m4D4 <= 2 && s->mAB4 == 0) {
        fn_80058FE4(s->mA9C, 0x3D, a);
        s->mAB4 = 1;
    }
}

void fn_8004FC60(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    if (a->m3D0 < *lbl_8061B9C4 && a->m448 == 4 && a->m4D4 <= 2 && s->mAB8 == 0) {
        fn_80058FE4(s->mA9C, 0x2A, a);
        s->mAB8 = 1;
    }
}

void fn_8004FEA4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (idx >= 0 && a->m4D4 == 3 && a->m50 == 0) {
        Unk80044C10_C* c = EntObj(s, idx)->m6F8;
        if (a->m1 == 1 && a->m4 == 0 && a->mC > 0) {
            Unk80044C10_E* e = c->m14;
            char* rec = (char*)e + a->m130->m708 * 0xE64;
            int f = *(int*)(rec + 0x198);
            fn_80015700(fn_8001F764(a), f);
        }
    }
    if (a->m4D4 <= 2)
        fn_80058FE4(s->mA9C, 4, a);
    fn_8004E68C(s, idx, a);
}

int fn_8004FF78(Unk800493D4_Sm* s, int idx, int type)
{
    int r = -1;
    if ((unsigned)idx <= 0x22 && *(int*)((char*)s + idx * 0x48) != 0x16 && idx != s->m9E0) {
        int i = idx;
        for (;;) {
            i = fn_80050094(s, i);
            int k = *(int*)((char*)s + i * 0x48);
            if (type == k) {
                r = i;
                break;
            }
            if (k == 0x16)
                break;
            if (i == s->m9E0)
                break;
        }
    }
    return r;
}

int fn_8005000C(Unk800493D4_Sm* s, int idx, int type)
{
    int r = -1;
    if ((unsigned)idx <= 0x22 && *(int*)((char*)s + idx * 0x48) != 0x15) {
        int i = idx;
        for (;;) {
            i = fn_800500A8(s, i);
            int k = *(int*)((char*)s + i * 0x48);
            if (type == k) {
                r = i;
                break;
            }
            if (k == 0x15)
                break;
            if (i == s->m9E0)
                break;
        }
    }
    return r;
}

int fn_80050094(Unk800493D4_Sm* s, int i)
{
    int n = i + 1;
    if (n > 0x22)
        n = 0;
    return n;
}

int fn_800500A8(Unk800493D4_Sm* s, int i)
{
    int n = i - 1;
    if (n < 0)
        n = 0x22;
    return n;
}

void fn_800502D4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    float sp8;
    float spC;
    ((Unk8001CE80*)a)->fn_8001CEA8(&spC, &sp8);
    if (a->m104 <= 2)
        fn_80010EE0(fn_8001E664(a));
}

void fn_80050324(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a, int b, int c)
{
    if (s->mA70 == 0) {
        int x = ((Unk8001CE80*)a)->fn_8001D538();
        int y = ((Unk8001CE80*)a)->fn_8001DC88();
        fn_80010C34(c, x, y, ((Unk8001CE80*)a)->fn_8001DCCC());
        s->mA70 = 1;
    }
}

void fn_8005039C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D4 == 2 && a->m4D8 == 0) {
        int x = ((Unk8001CE80*)a)->fn_8001E054();
        fn_800178A0(x, ((Unk8001CE80*)a)->fn_8001DB4C());
    }
}

struct Unk80052794_Ctx;

int fn_8005481C(Unk80052794_Ctx* ctx, int idx);

extern "C" int fn_800507A8(Unk80052794_Ctx* ctx, int idx)
{
    return fn_8005481C(ctx, idx) <= 3;
}

int fn_800507D8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    float f = fn_800547A4((Unk80052794_Ctx*)s, (unsigned char*)a, idx);
    int r = 0;
    if (((int (*)(Unk800493D4_Sm*, int, Unk80044C10_A*))fn_800507A8)(s, idx, a) != 0)
        r = f > 0.67f;
    return r;
}

int fn_80050850(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int r = 0;
    if (fn_800507D8(s, idx, a) != 0 && a->m104 > 0)
        r = 1;
    return r;
}
