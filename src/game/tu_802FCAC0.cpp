/*
 * Game code, .text 0x802FCAC0-0x80300848 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

extern char lbl_80664ED0[];
extern char lbl_80664F90[];
extern char lbl_80664F30[];
extern char lbl_806650E0[];
extern char lbl_80664E40[];
extern char lbl_80664DB0[];
extern const char lbl_805E73F0[];
extern const char lbl_805E740C[];
extern const char* lbl_8061F88C;
extern unsigned int lbl_8061F890;
extern const char* lbl_8061F894;
extern unsigned int lbl_8061F898;
extern float lbl_8061F900;
extern void* lbl_80619D10;
extern int lbl_8061F8FC;
extern int lbl_8061F8F8;
extern Unk802F8324_V2 lbl_8068E13C;

struct Unk802FCAC0_At0 {
    const void* m0;
};
struct Unk802FCAC0_At8 {
    char pad0[8];
    const void* m8;
};
struct Unk802FCAC0_Ent {
    char pad0[4];
    int m4;
    char pad8[0xC - 8];
    int mC;
    char pad10[0x24 - 0x10];
    Unk802F8324_V2 m24;
};
struct Unk802FCAC0_Obj {
    char pad0[0x18];
    const void* m18;
    char pad1C[8];
    int m24;
    Unk802FCAC0_Ent* m28[3];
    int m34_unused;
};

Unk8001BC8C* fn_8001BC4C();
struct Unk802FCAC0_Q {
    int w[4];
};
struct Unk802FCAC0_S5C4 {
    char pad0[0x5C4];
    int m5C4;
};
struct Unk802FCAC0_O24 {
    char pad0[0x6F8];
    struct Unk802FCAC0_X10* m6F8;
};
struct Unk802FCAC0_X10M {
    char pad0[0xC];
    int mC;
};
struct Unk802FCAC0_X10 {
    char pad0[0x10];
    Unk802FCAC0_X10M* m10;
};
struct Unk802FCAC0_P24 {
    char pad0[0x24];
    Unk802FCAC0_O24* m24;
};
extern void* lbl_8061E978;
extern int lbl_8061F8BC[];
extern int lbl_806E0EA0[];
extern Unk802FCAC0_Q lbl_806E0EC8[];
extern "C" {
int fn_802B0850(void* e, int a, int b);
Unk802FCAC0_Q fn_802B0ACC(void* e, int a);
int fn_801A04A8(int a, int b);
void fn_8031E1D4(int a, int b);
int fn_801A2034(void* p, int k);
void fn_802CBDB4(void* p);
void fn_802FDAD4(void* p, int a);
void fn_800AB9A8(void* mgr, int k);
void* fn_802FBC38(void* p);
void fn_802FD0F8(int* p);
void fn_802FF748(Unk802FCAC0_Obj* p);
void* fn_803282A8(void* p, int a);
void fn_80328374(void* p, int a);
void fn_80377408(void* p);
void fn_8035F69C(void* p);
}

void* fn_802FCAC0()
{
    return fn_802FBC38(operator new(0x64, lbl_806EF9B4));
}

void* fn_802FCC8C(void* p)
{
    new (p) Unk8037B3E8(0x7A17F3A4u);
    *(const void**)p = lbl_80664ED0;
    return p;
}

void* fn_802FCEFC()
{
    return fn_802FCC8C(operator new(0x4, lbl_806EF9B4));
}

void fn_802FCF2C()
{
}

void* fn_802FCF30(void* p)
{
    new (p) Unk8037B3E8(lbl_8061F890);
    ((Unk802FCAC0_At0*)p)->m0 = lbl_80664F90;
    if (lbl_8061F890 == 0)
        lbl_8061F890 = fn_80378568(lbl_8061F88C, 0);
    ((Unk8037B3E8*)p)->fn_8037B7E4(lbl_805E73F0);
    return p;
}

void fn_802FCFA4()
{
}

void* fn_802FCFA8()
{
    return fn_802FCF30(operator new(0x4, lbl_806EF9B4));
}

void fn_802FCFD8()
{
}

void* fn_802FCFDC(void* p)
{
    new (p) Unk8037B3E8(lbl_8061F894);
    ((Unk802FCAC0_At0*)p)->m0 = lbl_80664F30;
    if (lbl_8061F898 == 0)
        lbl_8061F898 = fn_80378568(lbl_8061F894, 0);
    ((Unk8037B3E8*)p)->fn_8037B7E4(lbl_805E740C);
    return p;
}

void fn_802FD050()
{
}

void* fn_802FD054()
{
    return fn_802FCFDC(operator new(0x4, lbl_806EF9B4));
}

void fn_802FD084()
{
}

void* fn_802FD088(Unk802FCAC0_At8* p)
{
    p->m8 = lbl_806650E0;
    fn_802FD0F8((int*)p);
    return p;
}

void fn_802FD0C4(Unk802FCAC0_At8* p, int c)
{
    p->m8 = lbl_806650E0;
    if (c & 1)
        fn_80377408(p);
}

void fn_802FD0F8(int* p)
{
    p[0] = -1;
    p[1] = 5;
}

void fn_802FD10C(int* p, int n)
{
    (*p)++;
    if (*p > n - 1)
        *p = 0;
    if (n != 1)
        fn_8001BC4C()->fn_8001BDAC(0x9C);
}

void fn_802FD15C(int* p, int n)
{
    (*p)--;
    if (*p < 0)
        *p = n - 1;
    if (n != 1)
        fn_8001BC4C()->fn_8001BDAC(0x9B);
}

void fn_802FD1A8(int* p, int n)
{
    if (*p == -1)
        *p = n - 1;
    int v = *p;
    if (v < 0)
        v = 0;
    *p = v;
}

void fn_802FD290(Unk802FCAC0_At8* p, int c)
{
    ((Unk802FCAC0_Obj*)p)->m18 = lbl_80664E40;
    fn_80328374(p, c);
}

void fn_802FD2C0(Unk802FCAC0_Obj* p)
{
    void* e = lbl_8061E978;
    for (int i = 0; i < 10; i++) {
        lbl_806E0EA0[i] = fn_802B0850(e, lbl_8061F8BC[i], 0);
        lbl_806E0EC8[i] = fn_802B0ACC(e, lbl_8061F8BC[i]);
    }
    *(int*)((char*)p + 0x5C) = 1;
}

void fn_802FDA84(Unk802FCAC0_Obj* p, int i)
{
    fn_802CBDB4((void*)p->m28[i]->mC);
}

void fn_802FDAB4(void* p, int a)
{
    fn_802FDAD4(p, a);
}

int fn_802FF3A0(void* a, Unk802FCAC0_S5C4* b)
{
    int v = b->m5C4;
    if (v != -1)
        return v;
    return 3;
}

/* near-miss: retail loads the bss Vec2 (lfs f11/f12) before the copy of the entry's Vec2 and uses sp+8/sp+0x10 for copy/result; ours loads after and swaps the slots (declaration order tried) */
Unk802F8324_V2 fn_802FF624(Unk802FCAC0_Obj* o, int i)
{
    Unk802F8324_V2 r;
    Unk802F8324_V2 v = o->m28[i]->m24;
    r.x = v.x - lbl_8068E13C.x;
    r.y = v.y - lbl_8068E13C.y;
    return r;
}

void fn_802FF688(Unk802FCAC0_Obj* p, int a)
{
    if (a == 0) {
        for (int i = 0; i < 3; i++)
            p->m28[i]->m4 = a;
    }
}

void* fn_802FF6B4(Unk802FCAC0_Obj* p, int a)
{
    fn_803282A8(p, a);
    p->m18 = lbl_80664DB0;
    fn_8035F69C((char*)p + 0x3C);
    p->m24 = a;
    return p;
}

void fn_802FF700(Unk802FCAC0_Obj* p, int c)
{
    p->m18 = lbl_80664DB0;
    fn_802FF748(p);
    fn_80328374(p, c);
}

void fn_802FF748(Unk802FCAC0_Obj* p)
{
    *(int*)((char*)p + 0x28) = 0;
    *(int*)((char*)p + 0x30) = -1;
    *(int*)((char*)p + 0x34) = -1;
    *(int*)((char*)p + 0x38) = -1;
    *(int*)((char*)p + 0x64) = 0;
    lbl_8061F8F8 = -1;
    *(int*)((char*)p + 0x2C) = 0;
    lbl_8061F8FC = 0;
    lbl_8061F900 = 0.5f;
}

void fn_802FF78C(Unk802FCAC0_Obj* p)
{
    fn_802FF748(p);
}

void fn_802FF864()
{
}

void fn_802FF868()
{
    fn_800AB9A8(lbl_80619D10, 3);
}

void fn_802FFAAC(float v)
{
    lbl_8061F900 = v;
}

float fn_802FFAC8()
{
    return lbl_8061F900;
}

/* near-miss: retail loads mC straight into r3 (subfic r3,r3,1); ours goes through r0 (5 spellings of (unsigned)v <= 1 tried) */
int fn_802FFE94(Unk802FCAC0_P24* p)
{
    return fn_801A2034(p->m24, 4) != -1 ? ((unsigned)p->m24->m6F8->m10->mC <= 1u) : 0;
}
