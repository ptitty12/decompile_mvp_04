/*
 * Game code, .text 0x801C16B0-0x801C2C64 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801C16B0.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Cmp C;

extern "C" {
void fn_801C0538(int a, int b);
void fn_801C38F0(void* self, float f);
void fn_801D6044(void* p);
void fn_801D7FCC(void* p);
void fn_801C1E44(void* self);
const char* fn_801C1710(void);
const char* fn_801C1778(void);
const char* fn_801C17E0(void);
}

typedef Unk801C16B0_Z Z;
typedef Unk801B7FB0_Ai A;
extern "C" {
P* fn_801A4B34(P* ctx);
void fn_801A656C(P* ctx, P* p, int k);
void fn_8017B1A4(Unk801C16B0_M4* a);
int fn_801C3FD0(Z* z, P* p);
void fn_801C3B04(Z* z, P* p);
void fn_801D5C5C(void* p);
void fn_801D5C1C(void* p);
void fn_801D7FD8(void* p);
void fn_801D5CBC(void* p);
void fn_801C34AC(Z* z, int k);
void fn_801D5F2C(void* p);
int fn_801D0294(void* p);
int fn_801C3F00(Z* z);
void fn_801CF1BC(Z* z);
int fn_801C4128(Z* z);
void fn_801D6178(void* p, int a, int b);
void fn_801D8788(void* p, P* q, int k);
void fn_801D801C(void* p, int a);
}
extern int* lbl_8061B9C4;

extern int lbl_8061CB38;
extern int lbl_8061CB34;
extern int lbl_8061CBBC;
extern const char lbl_805CCCE4[];
extern const char lbl_805CD948[];
extern const char lbl_805CD958[];

extern "C" void fn_801C16B0(void) {}
extern "C" int fn_801C16B4(void) { return lbl_8061CB38; }
extern "C" unsigned fn_801C16C0(void) { return 0xEA9F4BCE; }
extern "C" int fn_801C16CC(void) { return lbl_8061CB34; }
extern "C" unsigned fn_801C16D8(void) { return 0xE608C67F; }
extern "C" const char* fn_801C16E4(void) { return fn_801C1710(); }
extern "C" unsigned fn_801C1704(void) { return 0x6F618F85; }
extern "C" const char* fn_801C1710(void) { return lbl_805CCCE4; }
extern "C" const char* fn_801C174C(void) { return fn_801C1778(); }
extern "C" unsigned fn_801C176C(void) { return 0xDA319B21; }
extern "C" const char* fn_801C1778(void) { return lbl_805CD948; }
extern "C" const char* fn_801C17B4(void) { return fn_801C17E0(); }
extern "C" unsigned fn_801C17D4(void) { return 0x0F245603; }
extern "C" const char* fn_801C17E0(void) { return lbl_805CD958; }

extern "C" float fn_801C17EC(P* p)
{
    P* q = p->m44C->m65C[9];
    if (q != 0)
        return q->mAB4;
    return 1.0f;
}

extern "C" void fn_801C1840(void) {}
extern "C" void fn_801C1844(void) {}
extern "C" void fn_801C1848(void) {}
extern "C" int fn_801C184C(C* c, int a, int b) { return a > b; }
extern "C" int fn_801C185C(C* c, int a, int b) { return a >= b; }
extern "C" int fn_801C1870(C* c, int a, int b) { return a < b; }
extern "C" int fn_801C1880(C* c, int a, int b) { return a <= b; }
extern "C" int fn_801C1894(C* c, int a, int b) { return a == b; }
extern "C" int fn_801C18A4(C* c, int lo, int hi, int x)
{
    int r = 0;
    if (x >= lo)
        r = x <= hi;
    return r;
}

extern "C" int fn_801C18C4(C* c, int a, int b) { return b <= a; }
extern "C" int fn_801C18D8(C* c, int a, int b) { return b >= a; }
extern "C" int fn_801C18EC(C* c, int a) { return a >= 0; }
extern "C" int fn_801C18F8(C* c, int a)
{
    if (a <= 0)
        return 1;
    return 0;
}

extern "C" int fn_801C190C(C* c, int a) { return a == 0; }
extern "C" int fn_801C1918(C* c, int a)
{
    if (a > 0)
        return 1;
    return 0;
}

extern "C" int fn_801C192C(C* c, int a) { return a < 0; }
extern "C" int fn_801C1934(void) { return lbl_8061CBBC; }
extern "C" unsigned fn_801C1940(void) { return 0xD1E132A4; }
extern "C" void fn_801C194C(void) {}
extern "C" int fn_801C1950(A* a) { return a->m8->mC; }
extern "C" void fn_801C195C(void) { fn_801C0538(1, 0xFFFF); }
extern "C" void fn_801C1988(void) { fn_801C0538(0, 0xFFFF); }

extern "C" void fn_801C1E24(void* self) { fn_801C1E44(self); }
extern "C" void fn_801C20CC(Z* z)
{
    P* c = z->m204;
    if (c->m6F4 == 3) {
        P* q = fn_801A4B34(c);
        if (q)
            q->v8(1);
    }
}

extern "C" void fn_801C20A8(char* self) { fn_801D6044(self + 0x20C); }
extern "C" void fn_801C2120(char* self) { fn_801D7FCC(self + 0xE0); }
extern "C" void fn_801C26FC(void* self) { fn_801C38F0(self, 2.0f); }
extern "C" void fn_801C2A18(void* self) { fn_801C38F0(self, 0.0f); }

extern "C" void fn_801C2144(Z* z)
{
    P* p = 0;
    while (p != fn_801A4B34(z->m204)) {
        p = fn_801A4B34(z->m204);
        if (p->m458 != 9) {
            fn_801A656C(z->m204, p, 9);
            fn_8017B1A4(z->m4);
        }
    }
    if (p)
        p->m92C = 0xF;
    if (fn_801C3FD0(z, p))
        fn_801C3B04(z, p);
    fn_801D5C5C(z->m20C);
}

extern "C" void fn_801C21EC(Z* z)
{
    fn_801D5C1C(z->m20C);
    z->m288 = 0;
    z->m4->s8.SetC(0);
    if (z->m208 == 9 || z->m208 == 7)
        fn_801C34AC(z, 0);
    fn_801D7FD8(z->mE0);
    P* p = fn_801A4B34(z->m204);
    if (fn_801C3FD0(z, p))
        fn_801C3B04(z, p);
}

extern "C" void fn_801C2724(Z* z)
{
    Unk801C16B0_Mode* m = &z->m28C;
    m->m0 = 1;
    m->m4 = 0;
    if (z->m124 == 2 && m->m0 != 0)
        m->m4 = 4;
    fn_801D5CBC(z->m20C);
}

extern "C" void fn_801C2A40(Z* z)
{
    fn_801D5F2C(z->m20C);
    if (fn_801D0294(&z->m28C) == 1 && z->m4->s8.m8 == *lbl_8061B9C4 - 1) {
        P* c = z->m204;
        if (c->m65C[10] == 0 || c->m6F8->m14->m1CC9 == 2)
            fn_801C34AC(z, 9);
    }
}

extern "C" void fn_801C2AD0(Z* z, int flag)
{
    z->m28C.m0 = 0;
    if (flag) {
        fn_801C38F0(z, 0.0f);
    } else {
        if (z->m208 == 4)
            fn_801C34AC(z, 9);
        int s = z->m288;
        if ((unsigned)(s - 3) <= 1 || s == 7) {
            if (fn_801C3F00(z)) {
                fn_801CF1BC(z);
                z->m288 = 4;
                fn_801C34AC(z, 4);
            } else
                fn_801C34AC(z, 4);
        }
    }
}

extern "C" void fn_801C2B84(Z* z, int a, int b)
{
    if (fn_801C4128(z))
        fn_801D6178(z->m20C, a, b);
    if (a)
        fn_801C34AC(z, 8);
    else
        fn_801C34AC(z, 9);
    P* p = fn_801A4B34(z->m204);
    if (p)
        fn_801D8788(z->mE0, p, 0);
}

extern "C" void fn_801C2C10(Z* z, int a)
{
    if (fn_801C3F00(z))
        fn_801C38F0(z, 0.0f);
    fn_801D801C(z->mE0, a);
}
