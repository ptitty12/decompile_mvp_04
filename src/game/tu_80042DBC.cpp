/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80042DBC-0x800437AC only: every data object is extern by its lbl_ name.
 *
 * Small pure helpers of the sound-event code: float rounding and a family of
 * "id to bit mask" mappings (one bit per sound-event id range).
 */
#include "game/tu_80042DBC.h"

extern float lbl_805A8E00;
extern float lbl_805A8E08;
extern int lbl_805B1CAC[][3];
extern int lbl_805B1D1C[];
extern int* lbl_8061B9C4;

int fn_803445A0(int* p);

int fn_80042DBC(float f)
{
    int r = (int)f;
    if (!(f - (float)r <= lbl_805A8E00))
        r += 1;
    return r;
}

int fn_80042E24(float f)
{
    return fn_80042DBC(f * lbl_805A8E08);
}

int fn_80042E58(int a)
{
    if (a > 0x4e1f)
        return a - 0x4e20;
    return a;
}

int fn_80042E68(int a, int b)
{
    if (a <= 3 && b < *lbl_8061B9C4)
        return lbl_805B1CAC[a][b];
    return 0;
}

int fn_80042EA8(int a, int b)
{
    int r = 0;
    if (b <= 2) {
        r = 1 << (a * 3 + b + 3);
        if (a == 2)
            r |= 2;
        else if (a == 3)
            r |= 4;
        if (b == 2)
            r |= 1;
    }
    return r;
}

int fn_80042EF8(unsigned int a)
{
    int r = 0;
    if (a - 1 <= 0x1d)
        r = 1 << (a - 1);
    return r;
}

int fn_80042F18(int a)
{
    int r = 0;
    if (a > 0x1b)
        r = 0x400;
    else if (a > 10)
        r = 1 << a;
    else if (a > 0)
        r = 1 << (a - 1);
    return r;
}

int fn_80042F5C(int a)
{
    int r = 0;
    if (a == 0x14)
        r = 1;
    else if (a == 0x1e)
        r = 2;
    else if (a == 0x28)
        r = 4;
    else if (a == 0x32)
        r = 8;
    else if (a == 0x3c)
        r = 0x10;
    else if (a == 0x46)
        r = 0x20;
    else if (a == 0x49)
        r = 0x40;
    else if (a == 0x4a)
        r = 0x80;
    return r;
}

int fn_80042FE4(int a)
{
    int r = 0;
    if (a <= 9)
        r = 1 << (a - 1);
    return r;
}

int fn_80043004(unsigned int a)
{
    int r = 0;
    if (a - 2 <= 8)
        r = 1 << (a - 2);
    return r;
}

int fn_80043024(int a)
{
    if (a == 0x19)
        return 1;
    if (a != 0x32)
        return (a == 0x33) ? 4 : 0;
    return 2;
}

int fn_80043058(int a, int b)
{
    int r = 0;
    if (b == 2 && a > 2 && a <= 7)
        r = 1 << (a + 0xb);
    else if (a > 0xf)
        r = 0x400;
    else if (a > 0xd)
        r = 1 << (a + 5);
    else if (a > 10)
        r = 1 << a;
    else if (a > 0)
        r = 1 << (a - 1);
    return r;
}

int fn_800430CC(int a)
{
    int r = 0;
    if (a == 0x64)
        r = 1;
    else if (a == 0x96)
        r = 2;
    else if (a == 0xaf)
        r = 4;
    else if (a == 0xbe)
        r = 8;
    else if (a == 0xbf)
        r = 0x10;
    return r;
}

int fn_80043124(float f)
{
    int t = fn_80042DBC(f);
    int r = 0;
    if (t == 0)
        r = 0x4000;
    else if (t <= 0xe)
        r = 1 << (t - 1);
    return r;
}

int fn_80043178(float f)
{
    int t = fn_80042DBC(f);
    int r = 0;
    if (t > 0xe)
        r |= 0x8000;
    else
        r = 1 << t;
    return r;
}

int fn_800431BC(unsigned int a)
{
    int r = 0;
    if (a - 1 <= 9)
        r = 1 << (a - 1);
    return r;
}

int fn_800431DC(unsigned int a)
{
    int r = 0;
    if (a - 1 <= 0x18) {
        r = 1 << (a - 1);
        if (a > 0x15)
            return r | 0x2000000;
    }
    return r;
}

int fn_80043208(int a)
{
    return a == 0x64;
}

int fn_80043218(unsigned int a)
{
    int r = 0;
    if (a - 1 <= 3)
        r = 1 << (a - 1);
    return r;
}

int fn_80043238(int a)
{
    int r = 0;
    if (a > 0x18f) {
        if (a <= 0x1a9)
            r = 1;
        else if (a <= 0x1c2)
            r = 0x200;
        else if (a <= 0x1db)
            r = 2;
        else if (a <= 0x1f4)
            r = 4;
        else if (a <= 0x1fe)
            r = 0x40008;
        else if (a <= 0x203)
            r = 0x40400;
        else if (a <= 0x208)
            r = 0x10;
        else if (a <= 0x212)
            r = 0x800;
        else if (a <= 0x21c)
            r = 0x20;
        else if (a <= 0x226)
            r = 0x40;
        else if (a <= 0x230)
            r = 0x80;
        else if (a <= 0x23a)
            r = 0x1000;
        else if (a <= 0x244)
            r = 0x2000;
        else if (a <= 0x24e)
            r = 0x4000;
        else if (a <= 0x258)
            r = 0x8000;
        else
            r = 0x100;
    }
    return r;
}

int fn_80043348(unsigned int a)
{
    return a > 1 ? 1 : 2;
}

int fn_8004335C(unsigned int a)
{
    int r = 0;
    if (a <= 0x10) {
        r = lbl_805B1D1C[a];
        if (r == 0x10)
            r = 0x14;
        else if (r == 0x2000 || r == 0x800)
            r |= 1;
        else if (r == 0x100 || r == 0x200)
            r |= 2;
        else if (a == 8)
            r = 3;
    }
    return r;
}

int fn_800433CC(Unk800433CC_Obj* o)
{
    int r = 0;
    Unk800433CC_Outer* p = o->m130->m44C->m700;
    if (fn_803445A0((int*)(p->m3A4 + 0x28c)) == 7)
        r |= 8;
    else
        r |= 0x10;
    if (o->m104 == 0 || (o->m104 == 1 && o->m118 != 0))
        r |= 4;
    else if (o->m120 != 0)
        r |= 2;
    else
        r |= 1;
    return r;
}

int fn_80043460(Unk80043460_Obj* o, int b)
{
    int r = 0;
    int t4 = o->m4;
    int t14 = o->m14;
    int t0;
    int t10;
    int t18;
    int t8;
    if (t4 != t14 && t14 != 0 && t4 <= 5)
        r = (t4 >= 4) << 4;
    t0 = o->m0;
    t10 = o->m10;
    if (t0 != t10 && t10 != 0) {
        switch (t0) {
        case 9:
            r |= 0x80;
            break;
        case 10:
        case 11:
            if (b == 0)
                r |= 8;
            break;
        case 4:
        case 5:
            if ((unsigned int)(o->m8 - 4) <= 1)
                r |= 0x10000;
            break;
        case 6:
        case 7:
            if ((unsigned int)(o->m8 - 6) <= 1)
                r |= 0x8000;
            break;
        case 15:
            r |= 0x20;
            break;
        case 16:
            r |= 0x40;
            break;
        }
    }
    t8 = o->m8;
    t18 = o->m18;
    if (t8 != t18 && t18 != 0) {
        switch (t8) {
        case 11:
            r |= 0x800;
            break;
        case 4:
        case 5:
            if ((unsigned int)(t0 - 4) <= 1)
                r |= 0x10000;
            break;
        case 6:
        case 7:
            if ((unsigned int)(t0 - 6) <= 1)
                r |= 0x8000;
            break;
        case 12:
            r |= 0x200;
            break;
        case 13:
            r |= 0x400;
            break;
        }
    }
    return r;
}

int fn_800435E8(int a, int b)
{
    int r = 0;
    if (a != 0) {
        if (a == 2) {
            r = 1;
            if (b == 1)
                r = 2;
        }
    } else {
        r = 2;
        if (b == 1)
            r = 1;
    }
    return r;
}

int fn_80043628(int a)
{
    int r = 0;
    if (a == 2)
        r = 1;
    else if (a == 0)
        r = 2;
    return r;
}

int fn_80043650(int a)
{
    return a == 1 ? 1 : 2;
}

int fn_80043664(int a)
{
    switch (a) {
    case 0:
        return 1;
    case 2:
        return 2;
    default:
        return 0;
    }
}

int fn_80043690(int a)
{
    int r = 0;
    switch (a) {
    case 15:
        r = 0x20002;
        break;
    case 8:
        r = 0x40002;
        break;
    case 9:
        r = 0x400;
        break;
    case 1:
        r = 0x80;
        break;
    case 5:
        r = 0x240;
        break;
    case 3:
        r = 0x10;
        break;
    case 6:
        r = 0x204;
        break;
    case 2:
        r = 0x201;
        break;
    case 4:
        r = 0x208;
        break;
    case 7:
        r = 0x220;
        break;
    case 11:
        r = 0x300;
        break;
    case 12:
        r = 0x10000;
        break;
    case 13:
        r = 0x8000;
        break;
    case 14:
        r = 0xa00;
        break;
    case 10:
        r = 0x1000;
        break;
    }
    return r;
}

int fn_8004378C(unsigned int a)
{
    int r = 0;
    if (a - 1 <= 3)
        r = 1 << (a - 1);
    return r;
}
