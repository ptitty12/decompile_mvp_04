/*
 * Game code, .text 0x801A96E0-0x801AB63C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A96E0.h"
#include "game/tu_801A57C8.h"

void fn_801AA088(void* p);
void fn_801AB49C(void* p);
void fn_801AA284(void* p);
void fn_801AA570(void* p);
void fn_801AB2EC(void* p);
void fn_801AB188(void* p, int v);
void fn_801AB470(void* p);
extern float lbl_805CEEF8;
extern int lbl_80620388;
extern unsigned lbl_8062038C;
extern unsigned lbl_80620390;
extern unsigned lbl_806203A4;
extern unsigned lbl_806203A8;
int fn_801A9B78(Unk801A96E0_Sel* a, int b);
int fn_801A9B90(Unk801A96E0_Sel* a, int b);
int fn_801A9BA8(Unk801A96E0_Sel* a, int b);
int fn_801A9BC0(Unk801A96E0_Sel* a, int b, int c);
int fn_801A99B4(Unk801A96E0_Init* o);
int fn_801A9A20(Unk801A96E0_Init* o);
int fn_801A9A8C(Unk801A96E0_Init* o);
void fn_801A9684(void* p);
void fn_801AA038(void* p, int n);
void fn_801AA284(void* p, int n);
void fn_801AB5CC(void* p);

struct Unk801A9CFC_T {
    char pad0[0x38];
    int m38[1];
};

struct Unk801A9D0C_T {
    char pad0[0x40];
    int m40[1];
};

struct Unk801A9D1C_T {
    char pad0[0x48];
    int m48[1];
};

struct Unk801A9D2C_T {
    char pad0[0x50];
    int m50[1];
};

struct Unk801AB460_T {
    char pad0[0x2C];
    int m2C[1];
};

void fn_801A9700(void* p)
{
    fn_801AA038(p, 0);
}

void fn_801A985C(void* p)
{
    fn_801AB470(p);
}

void fn_801A987C(void* p)
{
    fn_801AA038(p, 0);
}

void fn_801A98A0(void* p)
{
    fn_801AA284(p, 1);
}

void fn_801A9980(void* p)
{
    fn_801AA088(p);
    fn_801AB49C(p);
}

int fn_801A99B4(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_8062038C;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    return fn_801A9B78((Unk801A96E0_Sel*)o, o->m38[f]);
}

int fn_801A9A20(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_80620390;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    return fn_801A9B90((Unk801A96E0_Sel*)o, o->m40[f]);
}

int fn_801A9A8C(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_806203A4;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    return fn_801A9BA8((Unk801A96E0_Sel*)o, o->m48[f]);
}

int fn_801A9AF8(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_806203A8;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    int a = fn_801A9A8C(o);
    return fn_801A9BC0((Unk801A96E0_Sel*)o, a, o->m50[f]);
}

int fn_801A9B78(Unk801A96E0_Sel* a, int b)
{
    if (b == 1) {
        return a->mC;
    }
    return b;
}

int fn_801A9B90(Unk801A96E0_Sel* a, int b)
{
    if (b == 1) {
        return a->m10;
    }
    return b;
}

int fn_801A9BA8(Unk801A96E0_Sel* a, int b)
{
    if (b == 1) {
        return a->m24;
    }
    return b;
}

int fn_801A9BC0(Unk801A96E0_Sel* a, int b, int c)
{
    if (b != 0xb) {
        if (c != 1) {
            return c;
        }
        return a->m28;
    }
    return 2;
}

void fn_801A9CFC(Unk801A9CFC_T* p, int i, int v)
{
    p->m38[i] = v;
}

void fn_801A9D0C(Unk801A9D0C_T* p, int i, int v)
{
    p->m40[i] = v;
}

void fn_801A9D1C(Unk801A9D1C_T* p, int i, int v)
{
    p->m48[i] = v;
}

void fn_801A9D2C(Unk801A9D2C_T* p, int i, int v)
{
    p->m50[i] = v;
}

void fn_801A9D3C(Unk801A96E0_Pair* p, int a, int b)
{
    p->m70 = a;
    p->m74 = b;
}

void fn_801AA038(void* p)
{
    fn_801AA284(p);
    fn_801AA570(p);
    fn_801AB2EC(p);
    fn_801AB188(p, 0);
    fn_801AB470(p);
}

void fn_801A96E0(void* p)
{
    fn_801A9684(p);
}

void fn_801AA248(Unk801A96E0_Init* p)
{
    for (int i = 0; i < 2; i++) {
        p->m38[i] = 2;
        p->m48[i] = 2;
        p->m40[i] = 2;
        p->m50[i] = 2;
    }
}

void fn_801AA570(Unk801A96E0_Init* p)
{
    p->mC = 0;
    p->m10 = 0;
    p->m24 = 0;
    p->m28 = 0;
    p->m58 = 0;
    p->m5C = 0;
    p->m60 = 0;
    p->m64 = 0;
}

int fn_801AAE10() { return 0; }

int fn_801AAE18() { return 0; }

int fn_801AAE20() { return 0; }

void fn_801AB188(Unk801A96E0_Init* p, int v)
{
    for (int i = 0; i < 4; i++) {
        p->m14[i] = v;
    }
}

int fn_801AB460(Unk801AB460_T* p, int i)
{
    return p->m2C[i];
}

/* near-miss: same stores; retail's store order is 0x78, 0x6C, 0x7C, 0x68, 0x70, 0x74 (no permutation found, 2 slots differ). */
void fn_801AB470(Unk801A96E0_Late* p)
{
    p->m78 = 0;
    p->m6C = -1;
    p->m7C = lbl_805CEEF8;
    p->m68 = 0;
    p->m70 = 0;
    p->m74 = -1;
}

Unk801AB59C::~Unk801AB59C() {}

void fn_801AB618(void* p)
{
    fn_801AB5CC(p);
}

void fn_801AB638() {}
