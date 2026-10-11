/*
 * Game code, .text 0x800DC0F4-0x800E0164 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800DC0F4.h"

int fn_800DD5E8(int i)
{
    return lbl_805C2EB4[i];
}

int fn_800DD5FC(int i)
{
    return lbl_805C2E84[i];
}

int fn_800DD610(Unk800DD610_P* p)
{
    return lbl_805C2EE4[fn_8032A130(p->m0 - 1, p->m1, p->m2)];
}

int fn_800DD658(int x)
{
    switch (x) {
    case 0:
        return 0x1A52;
    case 1:
        return 0x1A53;
    case 2:
        return 0x1A54;
    case 3:
        return 0x1A55;
    case 4:
        return 0x1A56;
    case 5:
        return 0x1A57;
    case 6:
        return 0x1A58;
    default:
        return 0x1A7A;
    }
}

void* fn_800DE160(int x)
{
    int id = 0;
    switch (x) {
    case 0:
        id = 0x2B34;
        break;
    case 1:
        id = 0x2B33;
        break;
    case 2:
        id = 0x2B35;
        break;
    }
    return fn_80090880(lbl_8061977C, id);
}

int fn_800DE930(int i)
{
    Unk800DE930_T loc = lbl_805BD9BC;
    return loc.m[i];
}

int fn_800DE980(int i, int id)
{
    float w;
    float h;
    float x;
    float y;
    int* arr = (int*)((char*)lbl_8061E978 + 0x11E88);
    fn_803EB434(arr[i], fn_80090880(lbl_8061977C, id), &w, &h, &x, &y);
    return (int)x;
}

/* near-miss: lwzx operand order of the row load (7 slots) */
int fn_800DEDC0(int i, int b)
{
    int out = 0;
    int sel = 5;
    fn_800DC3D8(&out, &sel, b);
    int r = 0xF;
    int v = lbl_805BD894[i].m0;
    if (v != -1) {
        r = fn_800DB9A8(out, v, sel, b);
    }
    return r;
}

/* near-miss: retail keeps a redundant second test of the first byte (cmpwi r0,0; beqlr) that
 * the compiler removes here */
char* fn_800DF034(char* s)
{
    if (*s == '0' && *s != 0) {
        char* p = s;
        do {
            *p = p[1];
        } while (*++p != 0);
    }
    return s;
}

void fn_800DF064(void* d, int n)
{
    if (n <= 3) {
        *(unsigned char*)d = lbl_805B6F58;
        return;
    }
    if (n <= 6) {
        *(unsigned short*)d = lbl_805BDADC;
        return;
    }
    if (n <= 9) {
        *(unsigned short*)d = lbl_805BDAE0;
        return;
    }
    if (n <= 12) {
        *(unsigned short*)d = lbl_805BDAE4;
        return;
    }
    if (n <= 15) {
        *(unsigned short*)d = lbl_805BDAE8;
    }
}

void fn_800DF1EC(int n, int* a, int* b)
{
    *a = 1;
    *b = 1;
    while ((n /= 10) != 0) {
        (*a)++;
        *b = *b * 10;
    }
}
