/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80045C8C-0x80046964 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80045C8C.h"

int fn_80045C8C(Unk80044C10_A* o)
{
    int t = fn_8025416C(o->m588, 5);
    if (t == 0 || t == 10) {
        float a = (float)fn_80253DF4(o->m588, 6, 0);
        float c = (float)fn_80253DF4(o->m588, 1, 0) + (float)fn_80253DF4(o->m588, 2, 0) * 0.333333f;
        if (!(c < 0.1f)) {
            float d = a / c;
            if (!(d >= 0.45f))
                return 1;
            int r = 2;
            if (!(d < 0.85f))
                r = 4;
            return r;
        }
    }
    return 0;
}

int fn_80045DD8(int a)
{
    switch (a) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    case 4:
        return 0x10;
    case 5:
        return 0x20;
    case 6:
        return 0x40;
    case 7:
        return 0x80;
    case 8:
        return 0x100;
    default:
        return 0;
    }
}

int fn_80045E80(int a)
{
    switch (a) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    case 4:
        return 0x10;
    case 5:
        return 0x20;
    case 6:
        return 0x40;
    case 7:
        return 0x80;
    case 8:
        return 0x100;
    default:
        return 0;
    }
}

int fn_80045F28(float a)
{
    int r = 0;
    if (!(a < 0.75f))
        return 1;
    if (!(a < 0.4f))
        return 2;
    if (!(a <= 0.0f))
        r = 4;
    return r;
}

int fn_80045F88(float a)
{
    int r = 0;
    if (!(a < 0.83f))
        return 1;
    if (!(a >= 0.4f))
        return 4;
    if (!(a <= 0.0f))
        r = 2;
    return r;
}

int fn_80045FEC(int a)
{
    int r = 0;
    if (a == 0)
        r = 2;
    else if (a == 1)
        r = 1;
    else if (a == 2)
        r = 4;
    return r;
}

int fn_80046024(int a, float b)
{
    int r = 0x10;
    if (a != 0)
        return 1;
    if (!(b < 0.93f))
        return 4;
    if (!(b > 0.5f))
        r = 2;
    return r;
}

void fn_80046078(Unk80044C10_B* b)
{
    int idx = b->m6F8->m14->m1CD0 == 0;
    Unk801A497C_Ret* r = fn_801A497C(b, idx, 2);
    lbl_806177F0 = fn_80410CE8(r->m60, r->m68) * 57.295773f;
    r = fn_801A497C(b, idx, 3);
    lbl_806177F4 = fn_80410CE8(r->m60, r->m68) * 57.295773f;
    r = fn_801A497C(b, idx, 4);
    lbl_806177F8 = fn_80410CE8(r->m60, r->m68) * 57.295773f;
    r = fn_801A497C(b, idx, 5);
    lbl_806177FC = fn_80410CE8(r->m60, r->m68) * 57.295773f;
}

int fn_80046160(unsigned a, unsigned b)
{
    int r = 0;
    if (b > a) {
        int d = b - a;
        if (d <= 8) {
            r = 1;
            r <<= d - 1;
        }
    }
    return r;
}

int fn_8004618C(int a)
{
    return a == 0 ? 2 : 1;
}

int fn_800461A0(int a)
{
    return a == 1 ? 1 : 2;
}

int fn_800461B4(int a)
{
    int r = 0;
    switch (a) {
    case 0:
        r = 4;
        break;
    case 1:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    }
    return r;
}

int fn_800461F8(int sel, Unk80044C10_A* a, Unk80044C10_A* b)
{
    int r = 0;
    switch (sel) {
    case 1:
        r = 1;
        if (a != 0 && a->vslot22() != 0)
            r = 5;
        else
            r |= 0x10;
        break;
    case 2:
        r = 2;
        if (a != 0 && b != 0 && a->vslot22() != 0 && b->vslot22() != 0)
            r = 10;
        else if (a != 0 && b != 0 && a->vslot22() == 0 && b->vslot22() == 0)
            r |= 0x20;
        else
            r |= 0x40;
        break;
    }
    return r;
}

int fn_8004633C(int a, int b, int c, int d)
{
    int r = 0;
    if (a != 0)
        r = 2;
    else if (b != 0)
        r = 4;
    else if (c != 0)
        r = 8;
    else if (d != 0)
        r = 1;
    return r;
}

int fn_80046380(float a, float b)
{
    int r = 0;
    if (!(b <= 0.75f)) {
        if (!(a < 0.7f))
            return 1;
        r = 4;
        if (!(a < 0.4f))
            r = 2;
    }
    return r;
}

int fn_800463E4(int a)
{
    switch (a) {
    case 7:
    case 0:
        return 1;
    case 8:
    case 1:
        return 0x10;
    case 9:
    case 2:
        return 2;
    case 10:
    case 3:
        return 0x20;
    case 11:
    case 4:
        return 0x40;
    case 5:
        return 0x2000;
    case 6:
        return 0x8000;
    case 12:
        return 4;
    case 13:
        return 8;
    case 14:
        return 0x80;
    case 15:
        return 0x100;
    default:
        return 0;
    }
}

int fn_800464C4(int a)
{
    switch (a) {
    case 5:
    case 0:
        return 4;
    case 6:
    case 1:
        return 0x100;
    case 7:
    case 2:
        return 0x20;
    case 8:
    case 3:
        return 0x1000;
    case 12:
    case 4:
        return 8;
    case 9:
        return 0x200;
    case 10:
        return 0x400;
    case 11:
        return 0x800;
    default:
        return 0;
    }
}

int fn_80046580(int a)
{
    switch (a) {
    case 1:
        return 1;
    case 0:
        return 2;
    case -1:
        return 4;
    default:
        return 0;
    }
}

int fn_800465C0(int a)
{
    return a == 0 ? 8 : 1;
}

int fn_800465D4(int a)
{
    switch (a) {
    case 0:
        return 8;
    case 1:
        return 8;
    case 2:
        return 8;
    case 3:
        return 8;
    case 4:
        return 8;
    case 5:
        return 8;
    case 6:
        return 8;
    case 7:
        return 2;
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    case 13:
        return 2;
    case 14:
        return 2;
    case 15:
        return 2;
    default:
        return 0;
    }
}

int fn_80046658(int a)
{
    switch (a) {
    case 0:
        return 8;
    case 1:
        return 8;
    case 2:
        return 8;
    case 3:
        return 8;
    case 4:
        return 8;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    default:
        return 0;
    }
}

int fn_800466E4(int a, int b)
{
    if (a == 39 || a == 10 || a == 25)
        return 0;
    if ((a == 22 && b == 2) || (a == 21 && b == 0))
        return 2;
    return 1;
}

int fn_80046734(int a)
{
    if (a <= 10)
        return 1 << a;
    return 0x800;
}

void fn_80046750(int* p)
{
    *p -= 0x32;
}

void fn_80046760(int* p)
{
    *p -= 9;
}

void fn_80046770(int* p)
{
    *p -= 0xC7;
}

/* near-miss: one insn more than retail; retail tests node 1 with `bgt` after `beq` for node 0
 * (case 9: break; gives the range-first tree, ~6 spellings tried) */
int fn_80046780(int a)
{
    int r = 0;
    switch (a) {
    case 0:
        r = 0x21;
        break;
    case 1:
        r = 0x28;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        r = 0x60;
        break;
    case 9:
        break;
    }
    return r;
}

int fn_800467C0(float a)
{
    int r = 0;
    if (!(a < 0.0)) {
        int f = a < 0.2;
        r = f << 6;
    }
    if (!(a < 0.75)) {
        if (!(a >= 1.01))
            r |= 0x20;
    }
    return r;
}

/* near-miss: not matched (22 vs 63 insns). Retail chains interval tests that reuse one cr7 compare
 * across the next test ((x < 0.0) flag via mfcr/rlwinm, then ranges [0,.2) [.2,.4) [.4,.75) [.75,1.01)) */
int fn_80046828(float a)
{
    int r = 0;
    if (!(a < 0.0)) {
        r = (a < 0.2) << 8;
        if (!(a < 0.2) && a < 0.4)
            r |= 1;
    }
    return r;
}

int fn_80046924(float a)
{
    int r = 0;
    if (!(a < 0.5)) {
        int f = a < 1.01;
        r = f << 11;
    }
    return r;
}
