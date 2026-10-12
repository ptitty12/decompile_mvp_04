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
extern int lbl_8061F904[];
extern int lbl_806E0F68[];
extern Unk802FCAC0_Q lbl_806E0F74[];
extern Unk802FCAC0_Q lbl_806E0EC8[];
extern "C" {
int fn_802B0850(void* e, int a, int b);
Unk802FCAC0_Q fn_802B0ACC(void* e, int a);
int fn_801A04A8(int a, int b);
void fn_8031E1D4(int a, int b);
int fn_801A2034(void* p, int k);
void fn_802CBDB4(void* p);
int fn_802FDAD4(void* p);
void fn_802FD378(void* p);
void fn_802FD6CC(void* p);
void fn_800AB9A8(void* mgr, int k);
void* fn_802FBC38(void* p);
void fn_802FD0F8(int* p);
void fn_802FF748(Unk802FCAC0_Obj* p);
void* fn_803282A8(void* p, int a);
void fn_80328374(void* p, int a);
void fn_80377408(void* p);
void fn_8035F69C(void* p);
}

struct Unk802FE96C_T {
    int w[3];
};
extern const Unk802FE96C_T lbl_805E750C __attribute__((aligned(4)));

struct Unk802FDE1C_S {
    char pad0[0x6F4];
    int m6F4;
};
struct Unk802FDE1C_O {
    char pad0[0x24];
    Unk802FDE1C_S* m24;
    char pad28[0x34];
    int m5C;
};
struct Unk802FDE1C_G {
    char pad0[0x2C];
    int m2C;
};
extern Unk802FDE1C_G* lbl_8061FF44;
extern "C" {
void fn_803188FC(void* p, int a);
int fn_802FDCD8(void* p);
void fn_802FDEC4(void* p);
void fn_802FDFE8(void* p);
void fn_802FE178(void* p);
void fn_802FE284(void* p);
void fn_802FEDA8(void* p);
void fn_802FF3B8(void* p);
}

struct Unk802FD1D4_O {
    char pad0[0x18];
    const void* m18;
    char pad1C[8];
    int m24;
    int m28[3];
    int m34[3];
    int m40[3];
    float m4C[3];
    int pad58;
    int m5C;
};
extern int lbl_8061F8E4;
void fn_802FF688(Unk802FCAC0_Obj* p, int a);

void* fn_802FCAC0()
{
    return fn_802FBC38(operator new(0x64, lbl_806EF9B4));
}

struct Unk802FCAF0_C {
    float m0;
    float m4;
    float m8;
    float mC;
};
struct Unk802FCAF0_O {
    char pad0[0x14];
    Unk802FCAF0_C m14[5];
};
extern "C" void fn_8014D9EC(Unk802FCAF0_C* c, float a, float b, float d, float e, float f);
extern Unk802FCAF0_C lbl_8068E0B0;
extern Unk802FCAF0_C lbl_8068E0C0;
extern Unk802FCAF0_C lbl_8068E0D0;
extern Unk802FCAF0_C lbl_8068E114;
extern Unk802FCAF0_C lbl_8068E124;
extern float lbl_8061F6E0;

void fn_802FCAF0(Unk802FCAF0_O* o)
{
    Unk802FCAF0_C* g0 = &lbl_8068E0B0;
    Unk802FCAF0_C* g1 = &lbl_8068E0C0;
    Unk802FCAF0_C* g2 = &lbl_8068E0D0;
    Unk802FCAF0_C* g3 = &lbl_8068E124;
    Unk802FCAF0_C* g4 = &lbl_8068E114;
    Unk802FCAF0_C c;
    fn_8014D9EC(&c, o->m14[0].m0, o->m14[0].m4, o->m14[0].m8, o->m14[0].mC, 255.0f);
    *g0 = c;
    fn_8014D9EC(&c, o->m14[1].m0, o->m14[1].m4, o->m14[1].m8, o->m14[1].mC, 255.0f);
    *g1 = c;
    fn_8014D9EC(&c, o->m14[2].m0, o->m14[2].m4, o->m14[2].m8, o->m14[2].mC, 255.0f);
    *g2 = c;
    fn_8014D9EC(&c, o->m14[3].m0, o->m14[3].m4, o->m14[3].m8, o->m14[3].mC, 255.0f);
    *g3 = c;
    fn_8014D9EC(&c, o->m14[4].m0, o->m14[4].m4, o->m14[4].m8, o->m14[4].mC, 255.0f);
    *g4 = c;
    lbl_8061F6E0 *= 12.0f;
}

void* fn_802FCC8C(void* p)
{
    new (p) Unk8037B3E8(0x7A17F3A4u);
    *(const void**)p = lbl_80664ED0;
    return p;
}

extern const char lbl_805E7290[];
extern const char lbl_805E7294[];
extern const char lbl_805E72A0[];
extern const char lbl_805E72AC[];
extern const char lbl_805E72BC[];
extern const char lbl_805E72C8[];
extern const char lbl_805E72D8[];
extern const char lbl_805E72E4[];
extern const char lbl_805E72F8[];
extern const char lbl_805E7304[];
extern const char lbl_805E7310[];
extern const char lbl_805E7318[];
extern const char lbl_805E7324[];
extern const char lbl_805E7334[];
extern const char lbl_805E73C0[];
extern const char lbl_805E73CC[];
extern float lbl_8061F7D8;
extern float lbl_8061F7DC;
extern float lbl_8061F7E0;
extern float lbl_8061F7E4;
extern float lbl_8061F7E8;
extern float lbl_8061F7EC;
struct Unk802FCCD0_E {
    int m0;
    float m4;
    float m8;
};
extern Unk802FCCD0_E lbl_8068E178[];
extern "C" int fn_804089B4(char* dst, const char* fmt, ...);

void fn_802FCCD0(Unk8037B3E8* o)
{
    char a[40];
    char b[40];
    o->fn_8037B7E4(lbl_805E7290);
    o->fn_8037B7E8(lbl_805E7294);
    int i = 0;
    o->fn_8037B50C(lbl_805E72A0, &lbl_8061F7D8, lbl_805E72AC, 0);
    o->fn_8037B50C(lbl_805E72BC, &lbl_8061F7DC, lbl_805E72AC, 0);
    o->fn_8037B50C(lbl_805E72C8, &lbl_8061F7E0, lbl_805E72D8, 0);
    o->fn_8037B50C(lbl_805E72E4, &lbl_8061F7EC, lbl_805E72D8, 0);
    o->fn_8037B50C(lbl_805E72F8, &lbl_8061F7E4, lbl_805E72AC, 0);
    o->fn_8037B50C(lbl_805E7304, &lbl_8061F7E8, lbl_805E72AC, 0);
    do {
        int n = i + 1;
        fn_804089B4(a, lbl_805E7310, n);
        o->fn_8037B7E8(a);
        o->fn_8037B7E8(lbl_805E7318);
        i = n;
        fn_804089B4(b, lbl_805E7324, n);
        o->fn_8037B674(b, &lbl_8068E178[i - 1].m0, lbl_805E7334, 0);
        o->fn_8037B830(lbl_805E7318);
        fn_804089B4(b, lbl_805E73C0, n);
        o->fn_8037B50C(b, &lbl_8068E178[i - 1].m4, lbl_805E72AC, 0);
        fn_804089B4(b, lbl_805E73CC, n);
        o->fn_8037B50C(b, &lbl_8068E178[i - 1].m8, lbl_805E72AC, 0);
        o->fn_8037B830(a);
    } while (i <= 3);
    o->fn_8037B830(lbl_805E7294);
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

void* fn_802FD1D4(Unk802FD1D4_O* p, int a)
{
    fn_803282A8(p, 0);
    p->m24 = a;
    p->m18 = lbl_80664E40;
    int i = 0;
    do {
        int h = fn_801A04A8(a, i + 2);
        p->m28[i] = h;
        fn_8031E1D4(h, lbl_8061F8E4);
        p->m40[i] = 0;
        p->m4C[i] = (float)i;
        i++;
    } while (i <= 2);
    p->m5C = 0;
    return p;
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
    fn_802FDAD4(p);
}

struct Unk8019F8C0_Owner;
int fn_801A37D8(Unk8019F8C0_Owner* o);
struct Unk802FDCD8_A {
    char pad0[0x20];
    int m20;
};
struct Unk802FDCD8_S {
    char pad0[0x744];
    Unk802FDCD8_A* m744;
};
struct Unk802FDCD8_O {
    char pad0[0x24];
    Unk8019F8C0_Owner* m24;
    char pad28[0x40 - 0x28];
    int m40[3];
};
struct Unk802FDCD8_M {
    char pad0[0x2C];
    int m2C;
};
struct Unk802FDCD8_G {
    char pad0[0x20];
    int m20;
    int m24;
};
extern Unk802FDCD8_G* lbl_8061B8C0;
extern int lbl_8061FE9C;
extern "C" {
void fn_800ABA88(void* mgr, int a, int b, int c);
void fn_800AB528(void* mgr);
int fn_800AC398();
int fn_802FD4F8(void* p);
}

struct Unk802FDAD4_X {
    char pad0[0xC];
    int mC;
};
struct Unk802FDAD4_Y {
    char pad0[0x3D90];
    int m3D90;
};
struct Unk802FDAD4_Z {
    char pad0[0x2C];
    int m2C;
};
struct Unk802FDAD4_K {
    char pad0[0x14];
    int m14;
};
struct Unk802FDAD4_L {
    char pad0[0x3BC];
    int m3BC;
};
struct Unk802FDAD4_S {
    char pad0[0x564];
    Unk802FDAD4_K* m564;
    char pad568[0x700 - 0x568];
    Unk802FDAD4_L* m700;
    char pad704[0x744 - 0x704];
    Unk802FDCD8_A* m744;
    char pad748[0x780 - 0x748];
    int m780;
    int m784;
};
struct Unk802FDAD4_O {
    char pad0[0x24];
    Unk802FDAD4_S* m24;
};
extern "C" {
Unk802FDAD4_X* fn_801A4CE8(void* o, int a);
int fn_801BBF24(int a);
Unk802FDAD4_Z* fn_8031C6A8();
}
Unk802FDAD4_Y* fn_801A6D84(Unk8019F8C0_Owner* o, int a);

int fn_802FDAD4(void* p)
{
    Unk802FDAD4_O* o = (Unk802FDAD4_O*)p;
    int k = o->m24->m564->m14;
    if (o->m24->m744->m20 != 0)
        return 0;
    if (lbl_8061B8C0->m24 != 0)
        return 0;
    if (((Unk802F8324_VT18*)lbl_80619D10)->s17() != 0) {
        fn_800AB528(lbl_80619D10);
        if (fn_800AC398() != 0)
            return 0;
    }
    if (fn_801A4CE8(o->m24, 1)->mC != 0)
        return 0;
    if (fn_801BBF24(o->m24->m700->m3BC) == 5)
        return 0;
    if (fn_801A6D84((Unk8019F8C0_Owner*)o->m24, 1)->m3D90 != 0)
        return 0;
    int f = fn_8031C6A8()->m2C != 0;
    if (f != 0)
        return 0;
    int g = 0;
    if (o->m24->m780 != 0 || o->m24->m784 != 0)
        g = 1;
    if (g != 0)
        return 0;
    int r = 0;
    if ((unsigned)(k - 3) <= 3 || k == 8 || k == 7)
        r = 1;
    return r;
}

void fn_802FDC34(Unk802FD1D4_O* p)
{
    int r = fn_802FDAD4(p);
    if (r == 0) {
        for (int i = 0; i < 3; i++) {
            p->m40[i] = 0;
            p->m4C[i] = (float)i;
        }
    }
    fn_802FD378(p);
    fn_802FD6CC(p);
    fn_802FF688((Unk802FCAC0_Obj*)p, r);
}

int fn_802FDCD8(void* p)
{
    Unk802FDCD8_O* o = (Unk802FDCD8_O*)p;
    if (((Unk802FDCD8_S*)o->m24)->m744->m20 != 0 || fn_801A37D8(o->m24) != 0) {
        fn_802FF688((Unk802FCAC0_Obj*)o, 0);
        return 0;
    }
    if (((Unk802FDCD8_M*)lbl_80619D10)->m2C == 0)
        return 0;
    if (((int (*)(void*))fn_802FDAB4)(o) == 0) {
        fn_800ABA88(lbl_80619D10, 4, 0, 0);
        return 0;
    }
    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (o->m40[i] != 0) {
            found = 1;
            break;
        }
    }
    if (!found || lbl_8061B8C0->m24 != 0)
        return 0;
    fn_800AB528(lbl_80619D10);
    if (fn_800AC398() != 0 || lbl_8061B8C0->m20 == 1 || lbl_8061FE9C == 0)
        return 0;
    int t = fn_802FD4F8(o);
    fn_800ABA88(lbl_80619D10, 4, t, 0);
    return 1;
}

void fn_802FDE1C(Unk802FDE1C_O* o)
{
    Unk802FDE1C_G** g = &lbl_8061FF44;
    fn_803188FC(*g, 1);
    (*g)->m2C = 1;
    if (o->m24->m6F4 != 8 && fn_802FDCD8(o) != 0) {
        if (o->m5C == 0)
            fn_802FD2C0((Unk802FCAC0_Obj*)o);
        fn_802FE178(o);
        fn_802FDEC4(o);
        fn_802FDFE8(o);
        fn_802FE284(o);
        fn_802FF3B8(o);
        fn_802FEDA8(o);
    }
}

struct Unk802FE178_G {
    char pad0[0x204];
    int m204;
    int m208;
};
struct Unk802FE178_O {
    char pad0[0x60];
    Unk802F8324_V2 m60;
    Unk802F8324_V2 m68;
};
extern Unk802F8324_V2 lbl_8060558C;
extern Unk802F8324_V2 lbl_8061F89C;
extern Unk802F8324_V2 lbl_8061F8A4;
extern Unk802FE178_G* lbl_8061FEDC;

void fn_802FE178(void* p)
{
    Unk802FE178_O* o = (Unk802FE178_O*)p;
    o->m68 = lbl_8060558C;
    if (fn_802FD4F8(o) != 0) {
        o->m68 = lbl_8061F89C;
        if (lbl_8061FEDC->m204 != 0 && lbl_8061FEDC->m208 == 0)
            o->m68.x = o->m68.x - 0.094f;
    } else {
        o->m68 = lbl_8061F8A4;
        if (lbl_8061FEDC->m204 != 0 && lbl_8061FEDC->m208 == 0)
            o->m68.x = o->m68.x + 0.094f;
    }
    o->m60 = o->m68;
    const float k = 0.07225f;
    o->m60.y = o->m60.y + k;
}

int fn_802FE96C(void* self, int k)
{
    Unk802FE96C_T t __attribute__((aligned(4))) = lbl_805E750C;
    return t.w[k];
}

int fn_802FF3A0(void* a, Unk802FCAC0_S5C4* b)
{
    int v = b->m5C4;
    if (v != -1)
        return v;
    return 3;
}

inline Unk802F8324_V2 EntPos(Unk802FCAC0_Obj* o, int i) { return o->m28[i]->m24; }

struct Unk80256C80_M;
struct Unk8024EF40_P;
int fn_80257CC0(Unk80256C80_M* m, Unk8024EF40_P* p);
int fn_80257D68(Unk80256C80_M* m, Unk8024EF40_P* p);
struct Unk802FF4DC_T {
    char pad0[0x14];
    int m14;
};
struct Unk802FF4DC_U {
    char pad0[0x3B4];
    Unk80256C80_M* m3B4;
};
struct Unk802FF4DC_S {
    char pad0[0x564];
    Unk802FF4DC_T* m564;
    char pad568[0x700 - 0x568];
    Unk802FF4DC_U* m700;
};
struct Unk802FF4DC_O {
    char pad0[0x24];
    Unk802FF4DC_S* m24;
};
extern Unk802FCAF0_C lbl_8068B588;

/* near-miss: 80 of 82 instructions identical; the first-call `addi r3,r1,8` is scheduled before
   `lwz r29,948(r9)` (retail has the lwz first). Local order, inline accessor, split chains and a
   non-void fn_8014D9EC did not change it. */
Unk802FCAF0_C fn_802FF4DC(Unk802FF4DC_O* o, Unk8024EF40_P* p)
{
    Unk80256C80_M* m = o->m24->m700->m3B4;
    Unk802FCAF0_C a;
    Unk802FCAF0_C b;
    fn_8014D9EC(&a, 0.7f, 0.7f, 0.7f, 1.0f, 1.0f);
    fn_8014D9EC(&b, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f);
    int r = fn_80257CC0(m, p);
    int r2 = fn_80257D68(m, p);
    int gt = o->m24->m564->m14 > 4;
    if (r2 == 1 && gt)
        a = lbl_8068B588;
    if (r)
        a = b;
    return a;
}

Unk802F8324_V2 fn_802FF624(Unk802FCAC0_Obj* o, int i)
{
    Unk802F8324_V2 v = EntPos(o, i);
    Unk802F8324_V2 r;
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

void fn_802FF7AC(Unk802FCAC0_Obj* p)
{
    void* e = lbl_8061E978;
    for (int i = 0; i < 3; i++) {
        lbl_806E0F68[i] = fn_802B0850(e, lbl_8061F904[i], 0);
        lbl_806E0F74[i] = fn_802B0ACC(e, lbl_8061F904[i]);
    }
    *(int*)((char*)p + 0x64) = 1;
}

void fn_802FF864()
{
}

void fn_802FF868()
{
    fn_800AB9A8(lbl_80619D10, 3);
}

struct Unk802FFA20_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
struct Unk802FFA20_M {
    char pad0[0x3B8];
    int m3B8;
};
struct Unk802FFA20_S {
    char pad0[0x700];
    Unk802FFA20_M* m700;
};
struct Unk802FFA20_A {
    int w[10];
};
extern "C" {
int fn_8011AA4C();
void fn_8014E09C(Unk802FFA20_It* it, void* o, int k);
void fn_8014E108(Unk802FFA20_It* it);
int fn_801A497C(void* o, int a, int b);
}

struct Unk80300848_S;
void fn_80301798(Unk80300848_S* p);
void fn_802FFA20(Unk802FFA20_A* a, Unk802FFA20_S* s);
int fn_802FFE94(Unk802FCAC0_P24* p);
struct Unk802FF894_M {
    char pad0[0x20];
    int m20;
};
struct Unk802FF894_N {
    char pad0[0xC];
    int mC;
};
struct Unk802FF894_L {
    char pad0[0x10];
    Unk802FF894_N* m10;
};
struct Unk802FF894_S {
    char pad0[0x550];
    int m550;
    char pad554[0x6F4 - 0x554];
    int m6F4;
    Unk802FF894_L* m6F8;
    char pad6FC[0x744 - 0x6FC];
    Unk802FF894_M* m744;
};
struct Unk802FF894_O {
    char pad0[0x24];
    Unk802FF894_S* m24;
    char pad28[0x3C - 0x28];
    Unk802FFA20_A m3C;
    int m64;
};
extern "C" {
void fn_80300848(void* o);
void fn_803005CC(void* o);
void fn_80300B4C(void* o);
void fn_80300F44(void* o);
void fn_803013D8(void* o);
void fn_803015D8(void* o);
void fn_803017D4(void* o);
}

void fn_802FF894(Unk802FF894_O* o)
{
    fn_803188FC(lbl_8061FF44, 4);
    lbl_8061FF44->m2C = 4;
    if (o->m24->m550 == 1) {
        if (o->m64 == 0)
            fn_802FF7AC((Unk802FCAC0_Obj*)o);
        if (o->m24->m744->m20 != 0 || fn_801A6D84((Unk8019F8C0_Owner*)o->m24, 1)->m3D90 != 0) {
            fn_80301798((Unk80300848_S*)o);
            ((void (*)(void*))fn_802FF868)(o);
            fn_802FFA20(&o->m3C, (Unk802FFA20_S*)o->m24);
            if (fn_801A6D84((Unk8019F8C0_Owner*)o->m24, 1)->m3D90 == 0 && fn_8011AA4C() != 10) {
                fn_80300848(o);
                fn_803005CC(o);
                fn_80300B4C(o);
            }
        } else {
            int t = o->m24->m6F8->m10->mC;
            if (fn_802FFE94((Unk802FCAC0_P24*)o) != 0) {
                fn_802FFA20(&o->m3C, (Unk802FFA20_S*)o->m24);
                if (o->m24->m6F4 != 8) {
                    fn_80300848(o);
                    fn_803005CC(o);
                    fn_80300B4C(o);
                    fn_80300F44(o);
                    fn_803017D4(o);
                    fn_803013D8(o);
                    fn_803015D8(o);
                }
            } else if (t == 2) {
                fn_802FFA20(&o->m3C, (Unk802FFA20_S*)o->m24);
                fn_803017D4(o);
                fn_803013D8(o);
                fn_803015D8(o);
            } else {
                fn_80301798((Unk80300848_S*)o);
                ((void (*)(void*))fn_802FF868)(o);
            }
        }
    }
}

void fn_802FFA20(Unk802FFA20_A* a, Unk802FFA20_S* s)
{
    if (fn_8011AA4C() != 10) {
        a->w[9] = s->m700->m3B8;
        Unk802FFA20_It it;
        Unk802FFA20_It* p;
        fn_8014E09C(&it, s, 1);
        p = &it;
        while (p->m8 != 10) {
            int k = p->m8;
            int r = fn_801A497C(s, 4, k);
            *(int*)((char*)(k * 4) + (int)a) = r;
            fn_8014E108(p);
        }
    }
}

void fn_802FFAAC(float v)
{
    lbl_8061F900 = v;
}

float fn_802FFAC8()
{
    return lbl_8061F900;
}

int fn_802FFE94(Unk802FCAC0_P24* p)
{
    if (fn_801A2034(p->m24, 4) == -1)
        return 0;
    unsigned v = p->m24->m6F8->m10->mC;
    return v <= 1;
}
