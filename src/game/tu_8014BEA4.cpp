/*
 * Game code, .text 0x8014BEA4-0x8014F47C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkB8_Obj { char pad0[0xB8]; int mB8; };
void* operator new(unsigned int size, int heap);
struct Unk8014D860_Obj { int m0; int m4; int m8; int mC; int m10; int m14; int m18; };
struct Unk8014D9C4_Obj { float m0; float m4; float m8; float mC; };
struct Unk2C { char b[0x2C]; };
struct Unk8014E09C_Obj { int m0; int m4; int m8; const char* mC; const char* m10; Unk2C* m14; };
struct Unk8014E108_Obj { char pad0[8]; int m8; };
struct V3i { int a; int b; int c; };
struct UnkAt2014 { char pad0[0x2014]; int m2014; };
struct UnkAt2ACS { char pad0[0x2AC]; char m2AC[0x10]; };
struct UnkAt2BCS { char pad0[0x2BC]; char m2BC[0x10]; };
struct UnkAt2CCS { char pad0[0x2CC]; char m2CC[0x10]; };

extern "C" {
void fn_8014BEA4();
void fn_8014C3BC();
void fn_8014C4E8();
void fn_8014C540();
void fn_8014D63C(int a, int b);
void fn_8014D81C(int* p);
void fn_8014D860(Unk8014D860_Obj* p, int a);
Unk8014D9C4_Obj* fn_8014D9C4(Unk8014D9C4_Obj* p);
void fn_8014DD30();
int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3);
/* near-miss (27 vs 30 insns): all 720 store orders tried; retail computes the element pointer with mulli/add
   before the vptr-like stores and keeps the three symbol addresses in distinct registers */
Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b);
void* fn_8014E108(Unk8014E108_Obj* p);
int fn_8014E2B4(int a);
int fn_8014E310(int a);
int fn_8014E374(int a);
/* near-miss: struct-copy form schedules like retail, but the two arms are joined by a cross-jump
   (retail keeps two separate copy+blr tails); field-wise copies schedule differently */
void fn_8014E388(V3i* p, unsigned i);
int fn_8014E3E0(int a);
void fn_8014E57C(UnkAt2014* p);
void* fn_8014E88C(void* p);
void fn_8014E8DC(void* p);
void* fn_8014EB44();
void fn_8014EBEC(UnkAt2ACS* p, const char* s);
void fn_8014EC24(UnkAt2BCS* p, const char* s);
void fn_8014EC5C(UnkAt2CCS* p, const char* s);
int fn_8014EC94(int a, unsigned b, unsigned c);
void* fn_8014F008(int a, int b, int c, int d);
void fn_8014F34C(int a);
void fn_8014F42C();
extern const void* lbl_8068B3CC;
extern const char lbl_8065D448[];
void fn_80378744();
extern UnkB8_Obj* lbl_8061A32C;
UnkB8_Obj* fn_800B64BC(void*);
void fn_8014C468();
extern int lbl_8061930C;
void fn_80072B98(int);
void fn_8014C3DC();
extern int* lbl_8068B618;
void __main();
void fn_8014C5A4(int, int);
void fn_8014C8BC();
int fn_80148930(void*);
int fn_8014D1EC();
void fn_8014D5C0();
void fn_8014D488();
extern const char lbl_805C5F90[];
void fn_803FFA60(void*, const char*, int);
extern const float lbl_805C58AC;
extern const float lbl_805C58B0;
unsigned fn_8014DDAC();
extern Unk2C lbl_8061BAD4[];
extern char lbl_8061B9CC[];
extern char lbl_8061BA7C[];
void fn_8014E15C(void*, void*, void*);
void fn_803579D4(void*);
extern V3i lbl_805C5F54[];
extern V3i lbl_805C5F78;
extern const char lbl_805C5A90[];
extern const char lbl_805C5A98[];
void fn_8014E588(void*, const char*);
void fn_8014E7EC(void*, const char*);
extern void* lbl_8061BD74;
void* fn_8014E9E0(void*);
void fn_8040B830(char*, const char*, int);
void* fn_8014F05C(void*, int, int, int, int);
extern int lbl_8068B704;
extern int lbl_8068B700;
extern int lbl_8068B6FC;
int fn_803FEBDC(int, int, int, int*);
int fn_803FEC9C(int, int);

void fn_8014BEA4()
{
    lbl_8068B3CC = lbl_8065D448;
}

void fn_8014C3BC() { fn_80378744(); }

void fn_8014C4E8()
{
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    lbl_8061A32C->mB8 = 0;
    fn_8014C468();
}

void fn_8014C540()
{
    fn_80072B98(lbl_8061930C);
    fn_8014C3DC();
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    lbl_8061A32C->mB8 = 1;
}

void fn_8014D63C(int a, int b)
{
    __main();
    fn_8014C5A4(a, b);
    for (;;) {
        fn_8014C8BC();
        fn_80148930(lbl_8068B618);
        if (fn_8014D1EC() == 1) {
            while ((unsigned)(fn_80148930(lbl_8068B618) - 2) <= 1) {
                fn_8014D5C0();
            }
        }
        fn_8014D488();
    }
}

void fn_8014D81C(int* p)
{
    fn_803FFA60(p + 1, lbl_805C5F90, 0x18);
    *p = 0;
}

void fn_8014D860(Unk8014D860_Obj* p, int a)
{
    int t = a + 0xF22D0E56;
    p->m4 = t;
    t = t + 0x96041893;
    p->m8 = t;
    t = t + 0x3DF3B646;
    p->mC = t;
    t = t + 0x40DDE76D;
    p->m10 = t;
    t = t + 0x97327AE1;
    p->m14 = t;
    p->m18 = t + 0xD1A9FBE7;
}

Unk8014D9C4_Obj* fn_8014D9C4(Unk8014D9C4_Obj* p)
{
    p->m0 = lbl_805C58AC;
    p->m4 = lbl_805C58AC;
    p->m8 = lbl_805C58AC;
    p->mC = lbl_805C58B0;
    return p;
}

void fn_8014DD30()
{
    unsigned c = fn_8014DDAC();
    fn_8014DD68(c >> 24, (c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF);
}

int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3)
{
    int r;
    if (a3 > 0xDF) {
        r = (a2 >> 3) | (((a0 << 7) & 0x7C00) | ((a1 * 4) & 0x3E0)) | 0x8000;
    } else {
        r = (a2 >> 4) | ((a1 & 0xF0) | ((a0 * 0x10) & 0xF00)) | ((a3 << 7) & 0x7000);
    }
    return r;
}

/* near-miss (27 vs 30 insns): all 720 store orders tried; retail computes the element pointer with mulli/add
   before the vptr-like stores and keeps the three symbol addresses in distinct registers */
Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b)
{
    Unk2C* t = &lbl_8061BAD4[b];
    p->m0 = a;
    p->m8 = 0;
    p->mC = lbl_8061B9CC;
    p->m10 = lbl_8061BA7C;
    p->m14 = t;
    p->m4 = b;
    fn_8014E15C(t, lbl_8061BAD4, lbl_8061BA7C);
    return p;
}

void* fn_8014E108(Unk8014E108_Obj* p)
{
    int t = p->m8;
    if (t != 0xA) {
        int v;
        if (t > 9) {
            v = t;
        } else {
            v = t + 1;
        }
        p->m8 = v;
        fn_803579D4(p);
    }
    return p;
}

int fn_8014E2B4(int a)
{
    int r = 9;
    switch (a) {
    case -1:
        break;
    case 0:
        r = 10;
        break;
    case 1:
        r = 11;
        break;
    case 2:
        r = 12;
        break;
    case 3:
        r = 18;
        break;
    }
    return r;
}

int fn_8014E310(int a)
{
    switch (a) {
    case 9:
        return -1;
    case 10:
        return 0;
    case 11:
        return 1;
    case 12:
        return 2;
    case 13:
        return 3;
    default:
        return -1;
    }
}

int fn_8014E374(int a)
{
    a = a + 1;
    if (a > 3) {
        a = 3;
    }
    return a;
}

/* near-miss: struct-copy form schedules like retail, but the two arms are joined by a cross-jump
   (retail keeps two separate copy+blr tails); field-wise copies schedule differently */
void fn_8014E388(V3i* p, unsigned i)
{
    if (i <= 3) {
        *p = lbl_805C5F54[i];
        return;
    }
    *p = lbl_805C5F78;
}

int fn_8014E3E0(int a)
{
    if (a > 9) {
        if (a == 10) {
            return 0;
        }
        if (a != 11) {
            return 2;
        }
        return 7;
    }
    return a;
}

void fn_8014E57C(UnkAt2014* p) { p->m2014 = 0x0; }

void* fn_8014E88C(void* p)
{
    fn_8014E57C((UnkAt2014*)p);
    fn_8014E588(p, lbl_805C5A90);
    fn_8014E7EC(p, lbl_805C5A98);
    return p;
}

void fn_8014E8DC(void* p)
{
    fn_8014E588(p, lbl_805C5A90);
}

void* fn_8014EB44() { if (!lbl_8061BD74) lbl_8061BD74 = fn_8014E9E0(operator new(0x2DC, 0)); return lbl_8061BD74; }

void fn_8014EBEC(UnkAt2ACS* p, const char* s) { p->m2AC[0] = 0; if (s) fn_8040B830(p->m2AC, s, 0x10); }

void fn_8014EC24(UnkAt2BCS* p, const char* s) { p->m2BC[0] = 0; if (s) fn_8040B830(p->m2BC, s, 0x10); }

void fn_8014EC5C(UnkAt2CCS* p, const char* s) { p->m2CC[0] = 0; if (s) fn_8040B830(p->m2CC, s, 0x10); }

int fn_8014EC94(int a, unsigned b, unsigned c) { return (b & (c - 1)) == 0; }

void* fn_8014F008(int a, int b, int c, int d)
{
    void* r = fn_8014EB44();
    if (r != 0) {
        r = fn_8014F05C(r, a, b, c, d);
    }
    return r;
}

void fn_8014F34C(int a)
{
    lbl_8068B700 = 1;
    lbl_8068B704 = 0;
    int r = fn_803FEBDC(a, 6, 0x64, &lbl_8068B6FC);
    if (r == 0) {
        lbl_8068B700 = r;
    }
}

void fn_8014F42C()
{
    if (lbl_8068B700 != 0) {
        int r = fn_803FEC9C(lbl_8068B6FC, 0x64);
        if (r == 0) {
            lbl_8068B700 = r;
        }
    }
}

}
