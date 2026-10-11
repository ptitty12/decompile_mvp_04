/*
 * Game code, .text 0x801D771C-0x801DB948 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801D771C.h"

typedef Unk801D771C_V20 V20;
typedef Unk801D771C_V18 V18;
typedef Unk801D771C_P8 P8;

extern int lbl_806EF9B4;
extern int lbl_8068C41C;
extern int lbl_8061CBF8;
extern const char lbl_80660CD8[];
extern const char lbl_80660760[];
extern const float lbl_805D3048;
extern const float lbl_805D304C;
extern const float lbl_805D3050;

/* Record views (offsets only). */
struct Unk801D771C_A {
    char pad0[0x34];
    V20 m34[4];
};
struct Unk801D771C_B {
    char pad0[0xB4];
    V20 mB4[6];
};
struct Unk801D771C_C {
    char pad0[4];
    V18 m4[2];
};
struct Unk801D771C_D {
    int m0[9];
    int m24[9];
};
struct Unk801D771C_E {
    int m0[14];
};
struct Unk801D771C_F {
    char pad0[0x38];
    P8 m38[9];
    P8 m80[9];
};
struct Unk801D771C_G {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
};
struct Unk801D771C_Gm;
struct Unk801D771C_I {
    Unk801D771C_Gm* m0;
    char pad4[0x18 - 4];
    int m18;
    char pad1C[0x2C - 0x1C];
    int m2C;
};
struct Unk801D771C_Sub58C {
    int m0;
    unsigned m4;
    char pad8[0x34 - 0x8];
    int m34;
    int m38;
};
/* Character-like object returned by fn_801A4B34 (as in Unk801A4B34_Pos): flags record at +0x58C. */
struct Unk801D771C_J {
    char pad0[0x458];
    int m458;
    char pad45C[0x58C - 0x45C];
    Unk801D771C_Sub58C m58C;
};
struct Unk801D771C_T2 {
    char pad0[0x1CC9];
    unsigned char m1CC9;
};
struct Unk801D771C_T {
    char pad0[0x14];
    Unk801D771C_T2* m14;
};
struct Unk801D771C_X700 {
    char pad0[0x3B4];
    int m3B4;
};
struct Unk801D771C_Gm {
    char pad0[0x65C];
    Unk801D771C_J* m65C[13];
    char pad690[0x6F8 - 0x690];
    Unk801D771C_T* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk801D771C_X700* m700;
};
struct Unk801D771C_N {
    Unk801D771C_Gm* m0;
    char pad4[4];
    int m8;
    int mC;
    char pad10[0x18 - 0x10];
    int m18;
    int m1C;
    int m20;
    char pad24[0x34 - 0x24];
    int m34;
    int m38;
};
struct Unk801D771C_Vec3 {
    float x;
    float y;
    float z;
};
struct Unk801D771C_E4C {
    char pad0[0x28 - 0x28];
    Unk801D771C_Vec3 m0;
    char padC[0x4C - 0xC];
};
struct Unk801D771C_O {
    char pad0[0x24];
    int m24;
    Unk801D771C_E4C m28[5];
};
struct Unk801D771C_R {
    char pad0[0x28];
    Unk801D771C_E4C m28[6];
};
struct Unk801D771C_K {
    char pad0[0x18];
    const char* m18;
};
struct Unk801D771C_L {
    char pad0[0x18];
    const char* m18;
    char pad1C[0x24 - 0x1C];
    int m24;
};
struct Unk801D771C_M {
    char pad0[0x68];
    int m68;
};

extern "C" {
void* fn_801D70A8(void* mem);
void* fn_8037C7FC();
int fn_8037CE98(void* self, int a, int b, int c);
int fn_8014E310(int x);
Unk801D771C_J* fn_801A4B34(Unk801D771C_Gm* g);
void fn_801D885C(int a, int b);
void fn_801D9800(void* p);
void fn_80328374(void* p);
void fn_803282A8(void* p);
void fn_801DA190(void* p);
void fn_801DACB8(void* p);
void fn_80254DA4(Unk801D771C_Sub58C* s, int a);
void fn_8035B53C(void* p);
Unk801D771C_J* fn_80257B40(int x);
Unk801D771C_J* fn_80257DFC(int x, Unk801D771C_J* c, int k);
int fn_801D85AC(void* self, Unk801D771C_J* p);
void fn_801D8788(Unk801D771C_N* s, Unk801D771C_J* p, int flag);
float fn_801D77E8(Unk801D771C_B* s, int i);
float fn_801D7818(Unk801D771C_C* s, int i);
float fn_801D7888(Unk801D771C_A* s, int i);
}

extern "C" void* fn_801D771C()
{
    return fn_801D70A8(operator new(0x1E0, lbl_806EF9B4));
}

extern "C" void fn_801D774C()
{
}

extern "C" int fn_801D7750()
{
    return fn_8037CE98(fn_8037C7FC(), 0xC12D4655, lbl_8068C41C, 0);
}

extern "C" float fn_801D7788(Unk801D771C_B* s)
{
    float sum = lbl_805D3048;
    int k = 0;
    do {
        sum = sum + fn_801D77E8(s, k);
        k++;
    } while (k <= 5);
    return sum;
}

extern "C" float fn_801D77E8(Unk801D771C_B* s, int i)
{
    return s->mB4[i].x;
}

extern "C" float fn_801D77F8(Unk801D771C_B* s, int i)
{
    return s->mB4[i].y;
}

extern "C" float fn_801D7808(Unk801D771C_B* s, int i)
{
    return s->mB4[i].z;
}

extern "C" float fn_801D7818(Unk801D771C_C* s, int i)
{
    return s->m4[i].x;
}

extern "C" float fn_801D7828(Unk801D771C_C* s)
{
    float sum = lbl_805D304C;
    int k = 0;
    do {
        sum = sum + fn_801D7818(s, k);
        k++;
    } while (k <= 1);
    return sum;
}

extern "C" float fn_801D7888(Unk801D771C_A* s, int i)
{
    return s->m34[i].x;
}

extern "C" float fn_801D7898(Unk801D771C_A* s, int i)
{
    return s->m34[i].y;
}

extern "C" float fn_801D78A8(Unk801D771C_A* s, int i)
{
    return s->m34[i].z;
}

extern "C" float fn_801D78B8(Unk801D771C_A* s)
{
    float sum = lbl_805D3050;
    int k = 0;
    do {
        sum = sum + fn_801D7888(s, k);
        k++;
    } while (k <= 3);
    return sum;
}

/* near-miss: retail stores the m24 permutation through stwx with offset registers (r4=0, r3=8, ...), 32 vs 26 insns */
extern "C" void fn_801D7918(Unk801D771C_D* s)
{
    for (int i = 0; i < 9; i++)
        s->m0[i] = -1;
    s->m24[0] = 5;
    s->m24[2] = 7;
    s->m24[1] = 1;
    s->m24[6] = 6;
    s->m24[7] = 2;
    s->m24[3] = 3;
    s->m24[4] = 0;
    s->m24[8] = 8;
    s->m24[5] = 4;
}

extern "C" int fn_801D7A3C(Unk801D771C_E* s, int k)
{
    if (k == -1)
        return -1;
    return s->m0[k - 2];
}

extern "C" void fn_801D7A5C(Unk801D771C_F* s, int idx, P8* a, P8* b)
{
    P8 ta = *a;
    P8 tb = *b;
    s->m80[idx] = ta;
    s->m38[idx] = tb;
}

extern "C" void fn_801D7A88(Unk801D771C_F* s, int idx, P8* a, P8* b)
{
    *a = s->m80[idx];
    *b = s->m38[idx];
}

extern "C" void fn_801D7AB4(Unk801D771C_E* s, int k, int v)
{
    s->m0[k - 2] = v;
}

extern "C" void fn_801D7FC0(int* s, int v)
{
    s[0] = v;
}

extern "C" void fn_801D7FC8()
{
}

extern "C" void fn_801D7FCC(Unk801D771C_G* s)
{
    s->m34 = 0;
}

/* near-miss: store order of m2C/m30/m38 differs (2 slots); statement orders searched */
extern "C" void fn_801D7FD8(Unk801D771C_G* s)
{
    s->m4 = 6;
    s->m8 = 0;
    s->mC = 0;
    s->m10 = 0;
    s->m14 = 0;
    s->m18 = 0;
    s->m1C = 0;
    s->m38 = 0;
    s->m20 = -1;
    s->m24 = -1;
    s->m28 = -1;
    s->m2C = -1;
    s->m30 = -1;
}

extern "C" void fn_801D801C(int* s, int v)
{
    s[1] = v;
}

extern "C" int fn_801D8024(Unk801D771C_N* s)
{
    int r = 0;
    Unk801D771C_Gm* g = s->m0;
    if (((g->m65C[9]->m58C.m4 & 0x20000000) != 0 || s->m38 != 0) && (s->m8 != 0 || s->mC != 0)) {
        int j = g->m700->m3B4;
        Unk801D771C_J* c = fn_80257B40(j);
        while (c != 0) {
            if (fn_801D85AC(s, c) != 0) {
                r = 1;
                break;
            }
            if ((s->m8 != 0 && c->m458 <= 9) || (s->mC != 0 && c->m458 <= 10))
                c = 0;
            else
                c = fn_80257DFC(j, c, 0);
        }
    }
    return r;
}

static inline Unk801D771C_J* PlAt(Unk801D771C_Gm* g, unsigned j)
{
    return j <= 12 ? g->m65C[j] : 0;
}

extern "C" int fn_801D85AC(void* self, Unk801D771C_J* p)
{
    Unk801D771C_Sub58C* s = &p->m58C;
    int v = s->m38;
    if (s->m34 != -1)
        v = s->m34;
    return v > fn_8014E310(p->m458);
}

extern "C" void fn_801D85FC(Unk801D771C_N* s, Unk801D771C_J* p)
{
    s->m18 = 1;
    Unk801D771C_Sub58C* sub = &fn_801A4B34(s->m0)->m58C;
    if (!(sub->m4 & 0x20000000) && (int)p->m58C.m4 >= 0)
        fn_80254DA4(sub, 0);
}

extern "C" void fn_801D865C(Unk801D771C_I* s)
{
    Unk801D771C_J* o = fn_801A4B34(s->m0);
    if (o != 0)
        s->m2C = o->m58C.m38;
}

extern "C" void fn_801D869C(Unk801D771C_N* s, Unk801D771C_J* p, int k)
{
    Unk801D771C_J* o = fn_801A4B34(s->m0);
    if (o != 0 && s->m20 == -1) {
        int v;
        if (p == o)
            v = k;
        else
            v = o->m58C.m38 + 1;
        s->m20 = v;
        if (v == 0)
            s->m38 = 1;
        if (s->m20 >= 0) {
            fn_80254DA4(&p->m58C, 0);
            unsigned j = 10;
            s->m34 = s->m34 + 1;
            do {
                Unk801D771C_J* x = PlAt(s->m0, j);
                if (x != 0)
                    fn_801D8788(s, x, 1);
                j++;
            } while ((int)j <= 12);
        }
    }
    s->m1C = 1;
}

extern "C" void fn_801D8788(Unk801D771C_N* s, Unk801D771C_J* p, int flag)
{
    if (p != 0) {
        if ((int)s->m0->m6F8->m14->m1CC9 + s->m34 > 2) {
            fn_80254DA4(&p->m58C, 0);
        } else if (p->m458 == 9 || flag != 0) {
            fn_80254DA4(&p->m58C, 1);
        }
    }
}

extern "C" int fn_801D87FC(Unk801D771C_N* s)
{
    int r = 0;
    if (s->m18 == 1) {
        Unk801D771C_Sub58C* sub = &fn_801A4B34(s->m0)->m58C;
        if (sub->m4 & 0x20000000)
            r = sub->m38 == -1;
    }
    return r;
}

extern "C" int fn_801D9730()
{
    return lbl_8061CBF8;
}

extern "C" int fn_801D973C()
{
    return 0xC12D4655;
}

extern "C" void fn_801D9748()
{
    fn_801D885C(1, 0xFFFF);
}

/* near-miss: retail keeps p (loop pointer) in r31 and computes it after the call; regalloc/sched differ (11 slots) */
extern "C" Unk801D771C_O* fn_801D9774(Unk801D771C_O* s, int a)
{
    fn_803282A8(s);
    *(const char**)((char*)s + 0x18) = lbl_80660CD8;
    Unk801D771C_E4C* p = s->m28;
    int i = 4;
    do {
        fn_8035B53C(p);
        p++;
    } while (i-- != 0);
    s->m24 = a;
    fn_801D9800(s);
    return s;
}

extern "C" void fn_801D97E0(void* s)
{
    fn_801D9800(s);
}

extern "C" void fn_801D9B18(Unk801D771C_K* s)
{
    s->m18 = lbl_80660CD8;
    fn_80328374(s);
}

extern "C" void fn_801DA094()
{
}

extern "C" Unk801D771C_Vec3 fn_801DA098(Unk801D771C_R* s, int sel)
{
    int k = 5;
    switch (sel) {
    case -1:
        k = 4;
        break;
    case 0:
        k = 3;
        break;
    case 1:
        k = 2;
        break;
    case 2:
        k = 1;
        break;
    case 3:
        k = 0;
        break;
    }
    return s->m28[k].m0;
}

extern "C" Unk801D771C_L* fn_801DA124(Unk801D771C_L* s, int a)
{
    fn_803282A8(s);
    s->m24 = a;
    s->m18 = lbl_80660760;
    fn_801DA190(s);
    return s;
}

extern "C" void fn_801DA170(void* s)
{
    fn_801DA190(s);
}

extern "C" void fn_801DA34C(Unk801D771C_K* s)
{
    s->m18 = lbl_80660760;
    fn_80328374(s);
}

extern "C" void fn_801DA37C(Unk801D771C_M* s)
{
    if (s->m68 != 0)
        fn_801DACB8(s);
}
