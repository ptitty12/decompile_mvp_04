/*
 * Game code, .text 0x800E4234-0x800E8890 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E4234.h"

void fn_800E49A4()
{
    Unk800E49A4_S* s = (Unk800E49A4_S*)((char*)fn_800B555C() + 8);
    s->m510 = 0;
    s->m514 = 0;
    s->m518 = 0;
    s->m51C = 0;
}

int fn_800E4FDC()
{
    return 1;
}

int fn_800E5D48(int x)
{
    switch (x) {
    case 0x42:
        return 7;
    case 0x43:
        return 8;
    default:
        return 7;
    }
}

int fn_800E60E0(int x)
{
    int r;
    if (x > 2) {
        r = 0x2B34;
    } else {
        Unk800E60E0_T loc = lbl_805BDFC8;
        r = loc.m[x];
    }
    return r;
}

void fn_800E6128()
{
    fn_800E6158();
    fn_800E6318(fn_8007DA28(lbl_8061930C));
}

int fn_800E62C4(int a, int b)
{
    int o = lbl_8061930C;
    if (a == -1) {
        return 0;
    }
    int r = 0;
    if (b == 4) {
        r = fn_8007D3D4(o, a, 0);
    }
    return r;
}

void fn_800E6318(int a)
{
    fn_800E6258(a, 4);
}

Unk800E6470_O* fn_800E6470(Unk800E6470_O* t)
{
    t->m0 = 0;
    t->m4 = 0;
    t->m8 = 0;
    t->mC = 1;
    t->m10 = 0;
    t->mDC = 0;
    t->mE0 = 0;
    t->mE4 = 0;
    t->mE8 = -1;
    t->mF4 = 0;
    return t;
}

void fn_800E64AC(void* t, int f)
{
    if (f & 1) {
        fn_80377408(t);
    }
}
