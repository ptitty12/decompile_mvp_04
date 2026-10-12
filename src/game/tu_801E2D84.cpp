/*
 * Game code, .text 0x801E2D84-0x801E6D88 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/goals/tu_80287600.h"
#include "game/goals/tu_8027C728.h"

inline void* operator new(unsigned int, void* p) { return p; }

extern int lbl_806EF9B4;
extern const Unk80273498_Vec3 lbl_806055DC;
extern "C" int fn_801DCC1C(Unk80270BA0_X* p, const Unk80273498_Vec3* v);
/* Minimal view of Unk80299920_Goal (the full header clashes with tu_80287600.h). */
struct Unk80299920_Goal {
    char pad0[0x60];
    int m60;
    void fn_80299F64(int v);
};
struct Unk801E4048_Src {
    char pad0[0x1C];
    int m1C;
};
extern "C" Unk8027C728_Goal* fn_802448F4(Unk80270BA0_X* p, int k);
void fn_8027C728(Unk8027C728_Goal* g);

struct Unk801E5D7C_Src {
    char pad0[0xA8];
    int mA8;
};

extern "C" Unk8027C728_Goal* fn_801E3FF8(void* self, Unk80270BA0_X* p)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 1);
    g->m10 = 2;
    fn_8027C728(g);
    ((Unk80287D70*)g->m18)->fn_80287DB8(0xC);
    return g;
}

extern "C" Unk8027C728_Goal* fn_801E4048(void* self, Unk80270BA0_X* p, Unk801E4048_Src* x)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    g->m10 = 5;
    fn_8027C728(g);
    Unk80299920_Goal* sub = (Unk80299920_Goal*)g->m18;
    sub->fn_80299F64(x->m1C);
    sub->m60 = 1;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    ((Unk80287D70*)h->m18)->fn_80287DB8(fn_801DCC1C(p, &lbl_806055DC));
    return g;
}

/* Goal-base views for the setters called on goal+0x18 / +0x104 (full classes in goals/tu_8027A84C.h
 * and goals/tu_8028B194.h, which clash with this unit's headers). */
class Unk8027A84C {
public:
    int m0;
    Unk8027A84C* m4;
    void* m8;
    int mC;
    char pad10[0x34 - 0x10];
    int m34;
    int m38;
    int m3C;
    int m40;
    void fn_8027A898(const Unk80273498_Vec3* v);
};
class Unk8027A84C_Owner {
public:
    Unk8027A84C* fn_8027C67C();
};
class Unk8028B194 {
public:
    Unk8028B194* fn_8028B194(Unk80273498_Vec3 v);
    void fn_8028B48C(float f);
    void fn_8028B4D0(float f);
};
struct Unk801E4E60_Src {
    char pad0[8];
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    char pad1C[0xC];
    Unk80273498_Vec3 m28;
    char pad34[0x30];
    Unk80273498_Vec3 m64;
    char pad70[4];
    float m74;
    char pad78[4];
    int m7C;
};

inline Unk80273498_Vec3 Unk801E4E60_Pos(const Unk80273498_Vec3* p)
{
    return *p;
}

inline Unk8028B194* Unk801E54E4_Init(Unk8027C728_Goal* g)
{
    g->m10 = 0xA;
    fn_8027C728(g);
    return (Unk8028B194*)g->m18;
}

extern const float lbl_805D3C4C;

extern "C" Unk8027C728_Goal* fn_801E3698(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    const Unk80273498_Vec3* pv = &x->m28;
    Unk8028B194* o = Unk801E54E4_Init(g)->fn_8028B194(Unk801E4E60_Pos(pv));
    if (x->m7C == 1) {
        Unk80273498_Vec3 w = Unk801E4E60_Pos(&x->m64);
        ((Unk8027A84C*)o)->fn_8027A898(&w);
    }
    if (!(x->m74 <= lbl_805D3C4C))
        o->fn_8028B4D0(x->m74);
    int a = x->mC;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    g104->m38 = a;
    int b = x->m8;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = b;
    g104->m34 = b;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    Unk8027A84C* hb = (Unk8027A84C*)hs->fn_80287DB8(fn_801DCC1C(p, &lbl_806055DC));
    if (x->m7C == 1) {
        Unk80273498_Vec3 w = Unk801E4E60_Pos(&x->m64);
        hb->fn_8027A898(&w);
    }
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    return g;
}

struct Unk80296C78_Goal;
Unk80296C78_Goal* fn_80298E9C(Unk80296C78_Goal* g, Unk80270BA0_X* x, int a);

extern "C" Unk8027C728_Goal* fn_801E465C(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    int six = 6;
    g->m10 = 0xD;
    fn_8027C728(g);
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    fn_80298E9C((Unk80296C78_Goal*)g->m18, (Unk80270BA0_X*)x->m14, 1);
    int a = x->mC;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    g104->m38 = a;
    int b = x->m8;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = b;
    g104->m34 = b;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = six;
    g104->m40 = six;
    Unk8027C728_Goal* h = g->m0;
    const Unk80273498_Vec3* pv = &x->m64;
    Unk80273498_Vec3 v = Unk801E4E60_Pos(pv);
    h->m10 = 2;
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    fn_8027C728(h);
    ((Unk8027A84C*)hs->fn_80287DB8(fn_801DCC1C(p, &lbl_806055DC)))->fn_8027A898(&v);
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    int c2 = x->m18;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m40 = c2;
    h104->m40 = c2;
    return g;
}

extern const float lbl_805D3C68;

extern "C" Unk8027C728_Goal* fn_801E4CB4(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    const Unk80273498_Vec3* pv = &x->m28;
    Unk8028B194* o = Unk801E54E4_Init(g)->fn_8028B194(Unk801E4E60_Pos(pv));
    if (x->m7C == 1) {
        Unk80273498_Vec3 w = Unk801E4E60_Pos(&x->m64);
        ((Unk8027A84C*)o)->fn_8027A898(&w);
    }
    if (!(x->m74 <= lbl_805D3C68))
        o->fn_8028B48C(x->m74);
    int a = x->mC;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    g104->m38 = a;
    int b = x->m8;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = b;
    g104->m34 = b;
    int c = x->m18;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = c;
    g104->m40 = c;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    Unk8027A84C* hb = (Unk8027A84C*)hs->fn_80287DB8(fn_801DCC1C(p, &lbl_806055DC));
    if (x->m7C == 1) {
        Unk80273498_Vec3 w = Unk801E4E60_Pos(&x->m64);
        hb->fn_8027A898(&w);
    }
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    int c2 = x->m18;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m40 = c2;
    h104->m40 = c2;
    return g;
}

extern "C" Unk8027C728_Goal* fn_801E4E60(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    const Unk80273498_Vec3* pv = &x->m64;
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    g->m10 = 0xA;
    fn_8027C728(g);
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    ((Unk8028B194*)g->m18)->fn_8028B194(Unk801E4E60_Pos(&x->m28));
    {
        Unk80273498_Vec3 v = Unk801E4E60_Pos(pv);
        ((Unk8027A84C*)g->m18)->fn_8027A898(&v);
    }
    int a = x->mC;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    g104->m38 = a;
    int b = x->m8;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = b;
    g104->m34 = b;
    int c = x->m18;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = c;
    g104->m40 = c;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    hs->fn_80287DB8(1);
    if (x->m7C == 1) {
        Unk80273498_Vec3 v = Unk801E4E60_Pos(pv);
        ((Unk8027A84C*)hs)->fn_8027A898(&v);
    }
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    int c2 = x->m18;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m40 = c2;
    h104->m40 = c2;
    return g;
}

extern "C" Unk8027C728_Goal* fn_801E4FD0(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    const Unk80273498_Vec3* pv = &x->m64;
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    g->m10 = 0xA;
    fn_8027C728(g);
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    ((Unk8028B194*)g->m18)->fn_8028B194(Unk801E4E60_Pos(&x->m28));
    {
        Unk80273498_Vec3 v = Unk801E4E60_Pos(pv);
        ((Unk8027A84C*)g->m18)->fn_8027A898(&v);
    }
    int a = x->mC;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    g104->m38 = a;
    int b = x->m8;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = b;
    g104->m34 = b;
    int c = x->m18;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = c;
    g104->m40 = c;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    hs->fn_80287DB8(1);
    if (x->m7C == 1) {
        Unk80273498_Vec3 v = Unk801E4E60_Pos(pv);
        ((Unk8027A84C*)hs)->fn_8027A898(&v);
    }
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    int c2 = x->m18;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m40 = c2;
    h104->m40 = c2;
    return g;
}


extern "C" Unk8027C728_Goal* fn_801E5140(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    int two = 2;
    int ten = 0xA;
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    const Unk80273498_Vec3* pv = &x->m64;
    g->m10 = ten;
    Unk8027A84C* gb = (Unk8027A84C*)g->m18;
    fn_8027C728(g);
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    ((Unk8028B194*)gb)->fn_8028B194(Unk801E4E60_Pos(&x->m28));
    {
        Unk80273498_Vec3 v = Unk801E4E60_Pos(pv);
        gb->fn_8027A898(&v);
    }
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = two;
    g104->m38 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = two;
    g104->m34 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
    g104->m40 = ten;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = two;
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    fn_8027C728(h);
    hs->fn_80287DB8(fn_801DCC1C(p, &lbl_806055DC));
    if (x->m7C == 1) {
        Unk80273498_Vec3 w = Unk801E4E60_Pos(pv);
        ((Unk8027A84C*)hs)->fn_8027A898(&w);
    }
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    int c2 = x->m18;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m40 = c2;
    h104->m40 = c2;
    return g;
}

struct Unk801E54E4_P {
    char pad0[0x5BC];
    int m5BC;
};

extern "C" Unk8027C728_Goal* fn_801E54E4(void* self, Unk80270BA0_X* p, Unk801E4E60_Src* x)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    ((Unk801E54E4_P*)p)->m5BC = x->m10;
    const Unk80273498_Vec3* pv = &x->m28;
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    Unk801E54E4_Init(g)->fn_8028B194(Unk801E4E60_Pos(pv));
    int a = x->mC;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    g104->m38 = a;
    int b = x->m8;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = b;
    g104->m34 = b;
    int six = 6;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = six;
    g104->m40 = six;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk80287D70* hs = (Unk80287D70*)h->m18;
    Unk8027A84C* hb = (Unk8027A84C*)hs->fn_80287DB8(fn_801DCC1C(p, &lbl_806055DC));
    if (x->m7C == 1) {
        Unk80273498_Vec3 w = Unk801E4E60_Pos(&x->m64);
        hb->fn_8027A898(&w);
    }
    int a2 = x->mC;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m38 = a2;
    Unk8027A84C* h104 = (Unk8027A84C*)h->m104;
    h104->m38 = a2;
    int b2 = x->m8;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m34 = b2;
    h104->m34 = b2;
    int c2 = x->m18;
    ((Unk8027A84C_Owner*)h)->fn_8027C67C()->m40 = c2;
    h104->m40 = c2;
    return g;
}

/* near-miss: retail keeps a second pointer copy of g (mr r31,r29) and reuses r0 for the 8/9 select (2 insns) */
extern "C" Unk8027C728_Goal* fn_801E5D7C(void* self, Unk80270BA0_X* p, Unk801E5D7C_Src* x)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    g->m10 = 0x10;
    fn_8027C728(g);
    ((Unk80287D70*)g->m18)->m48 = x->mA8 == 1 ? 8 : 9;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    return g;
}

struct Unk801E5DF8_Rec {
    Unk8027C728_Goal* m0;
    int m4;
};
typedef Unk8027C728_Goal* (*Unk801E5DF8_Fn)(void*);
extern Unk801E5DF8_Fn lbl_8061CC04[];

extern "C" Unk8027C728_Goal* fn_801E5DF8(void* g, void* p, Unk801E5DF8_Rec* r)
{
    Unk8027C728_Goal* x = r->m0;
    if (x == 0)
        x = lbl_8061CC04[r->m4](g);
    return x;
}

extern "C" {
void fn_801E5F78(char* s);
void fn_801E63EC(char* s);
void fn_801E695C(char* s);
void fn_8037B424(void* s);
int fn_801E6290(unsigned x);
int fn_801E67B4(unsigned x);
void* fn_801E5E44(void* mem);
void* fn_801E62A4(void* mem);
void* fn_801E67C8(void* mem);



void fn_8037CF5C(Unk8037C7FC* reg, unsigned hash, void* s);
}

extern const float lbl_805D3C8C;
extern const char lbl_80660B98[];
extern const char lbl_80660B38[];
extern const char lbl_80660AD8[];
struct Unk801E5E44_V3 {
    float x;
    float y;
    float z;
};
struct Unk801E5E44_Obj {
    const void* m0;
    Unk801E5E44_V3 m4[6];
};

extern "C" void* fn_801E5E44(void* mem)
{
    Unk801E5E44_Obj* o = (Unk801E5E44_Obj*)mem;
    new (mem) Unk8037B3E8(0xDA07F2A0u);
    o->m0 = lbl_80660B98;
    for (int i = 0; i < 6; i++) {
        o->m4[i].x = lbl_805D3C8C;
        o->m4[i].y = lbl_805D3C8C;
        o->m4[i].z = lbl_805D3C8C;
    }
    return o;
}

struct Unk801E5EBC {
    const void* m0;
};

extern "C" void fn_801E5EBC(Unk801E5EBC* s)
{
    s->m0 = lbl_80660B98;
    fn_8037B424(s);
}

extern "C" void* fn_801E5EEC()
{
    return fn_801E5E44(operator new(0x4C, lbl_806EF9B4));
}

extern "C" void fn_801E5F1C(void* s)
{
    fn_801E5F78((char*)s);
}

extern "C" void fn_801E5F3C(void* s)
{
    fn_8037CF5C(fn_8037C7FC(), 0xDA07F2A0, s);
}

extern const char lbl_805D3370[];
extern const char lbl_805D3C90[];
extern const char lbl_805D3C94[];
extern const char lbl_805D3C9C[];
extern const char lbl_805D3CAC[];
extern const char lbl_805D3CB8[];
extern const char lbl_805D3CC0[];
extern const char lbl_805D3CD0[];
extern const char lbl_805D3CD8[];
extern const char lbl_805D3CE8[];
extern const char lbl_805D3CF0[];
extern const char lbl_805D3D00[];
extern const char lbl_805D3D0C[];
extern const char lbl_805D3D1C[];
extern const char lbl_805D3D24[];
extern const char lbl_805D3D34[];
extern const char lbl_805D3D3C[];
extern const char lbl_805D3D48[];
extern const char lbl_805D3D58[];
extern const char lbl_805D3D60[];
extern const char lbl_805D3D70[];
extern const char lbl_805D3D78[];
extern const char lbl_805D3D84[];
extern const char lbl_805D3D94[];
extern const char lbl_805D3DA4[];
extern const char lbl_805D3DB0[];
extern const char lbl_805D3DC0[];
extern const char lbl_805D3DF4[];
extern const char lbl_805D3DF8[];
extern const char lbl_805D3E08[];
extern const char lbl_805D3E0C[];
extern const char lbl_805D3E1C[];
extern const char lbl_805D3E2C[];
extern const char lbl_805D3E3C[];
extern const char lbl_805D3E4C[];
extern const char lbl_805D3EBC[];
extern const char lbl_805D3EC0[];
extern const char lbl_805D3ECC[];
extern const char lbl_805D3ED8[];
extern const char lbl_805D3EE4[];
extern const char lbl_805D3EE8[];
extern const char lbl_805D3EF8[];
extern const char lbl_805D3EFC[];
extern const char lbl_805D3F08[];
extern const char lbl_805D3F18[];
extern const char lbl_805D3F28[];
extern const char lbl_805D3F2C[];
extern const char lbl_805D3F38[];
extern const char lbl_805D3F44[];
extern const char lbl_805D3F54[];
extern "C" {
void fn_8037B7E4(void* s, const char* name);
void fn_8037B7E8(void* s, const char* name);
void fn_8037B830(void* s, const char* name);
void fn_8037B50C(void* s, const char* name, void* field, const char* type, const char* def);
void fn_8037B458(void* s, const char* name, void* field, const char* type, const char* def);
}

extern "C" void fn_801E5F78(char* s)
{
    fn_8037B7E4(s, lbl_805D3C90);
    fn_8037B7E8(s, lbl_805D3C94);
    fn_8037B50C(s, lbl_805D3C9C, (char*)s + 4, lbl_805D3CAC, lbl_805D3CB8);
    fn_8037B50C(s, lbl_805D3CC0, (char*)s + 0xC, lbl_805D3CAC, lbl_805D3CB8);
    fn_8037B830(s, lbl_805D3C94);
    fn_8037B7E8(s, lbl_805D3CD0);
    fn_8037B50C(s, lbl_805D3CD8, (char*)s + 0x10, lbl_805D3CAC, lbl_805D3CE8);
    fn_8037B50C(s, lbl_805D3CF0, (char*)s + 0x18, lbl_805D3CAC, lbl_805D3CE8);
    fn_8037B830(s, lbl_805D3CD0);
    fn_8037B7E8(s, lbl_805D3D00);
    fn_8037B50C(s, lbl_805D3D0C, (char*)s + 0x1C, lbl_805D3CAC, lbl_805D3D1C);
    fn_8037B50C(s, lbl_805D3D24, (char*)s + 0x24, lbl_805D3CAC, lbl_805D3D34);
    fn_8037B830(s, lbl_805D3D00);
    fn_8037B7E8(s, lbl_805D3D3C);
    fn_8037B50C(s, lbl_805D3D48, (char*)s + 0x28, lbl_805D3CAC, lbl_805D3D58);
    fn_8037B50C(s, lbl_805D3D60, (char*)s + 0x30, lbl_805D3CAC, lbl_805D3D70);
    fn_8037B830(s, lbl_805D3D3C);
    fn_8037B7E8(s, lbl_805D3D78);
    fn_8037B50C(s, lbl_805D3D84, (char*)s + 0x34, lbl_805D3CAC, lbl_805D3D34);
    fn_8037B50C(s, lbl_805D3D94, (char*)s + 0x3C, lbl_805D3CAC, lbl_805D3D1C);
    fn_8037B830(s, lbl_805D3D78);
    fn_8037B7E8(s, lbl_805D3DA4);
    fn_8037B50C(s, lbl_805D3DB0, (char*)s + 0x40, lbl_805D3CAC, lbl_805D3D70);
    fn_8037B50C(s, lbl_805D3DC0, (char*)s + 0x48, lbl_805D3CAC, lbl_805D3D58);
    fn_8037B830(s, lbl_805D3DA4);
}

struct Unk801E61C0_Vec3 {
    float x;
    float y;
    float z;
};
struct Unk801E61C0_O {
    char pad0[4];
    Unk801E61C0_Vec3 m4[6];
};
extern const Unk801E61C0_Vec3 lbl_805D6790;
extern const float lbl_805D3DD0;
extern const float lbl_805D3DD4;

extern "C" Unk801E61C0_Vec3 fn_801E61C0(Unk801E61C0_O* o, int k)
{
    Unk801E61C0_Vec3 v;
    if (k == 0) {
        v = lbl_805D6790;
    } else {
        v = o->m4[fn_801E6290(k)];
        v.y = lbl_805D3DD4;
        v.x = v.x * lbl_805D3DD0;
        v.z = v.z * lbl_805D3DD0;
    }
    return v;
}

extern "C" int fn_801E6290(unsigned x)
{
    if (x <= 5)
        return x;
    return 0;
}

extern const float lbl_805D3DF0;
struct Unk801E62A4_Obj {
    const void* m0;
    Unk801E5E44_V3 m4[6];
    int m4C[6];
};

extern "C" void* fn_801E62A4(void* mem)
{
    Unk801E62A4_Obj* o = (Unk801E62A4_Obj*)mem;
    new (mem) Unk8037B3E8(0xEC1BCE8Du);
    o->m0 = lbl_80660B38;
    for (int i = 0; i < 6; i++) {
        o->m4[i].x = lbl_805D3DF0;
        o->m4[i].y = lbl_805D3DF0;
        o->m4[i].z = lbl_805D3DF0;
        o->m4C[i] = 1;
    }
    return o;
}

extern "C" void fn_801E6330(Unk801E5EBC* s)
{
    s->m0 = lbl_80660B38;
    fn_8037B424(s);
}

extern "C" void* fn_801E6360()
{
    return fn_801E62A4(operator new(0x64, lbl_806EF9B4));
}

extern "C" void fn_801E6390(void* s)
{
    fn_801E63EC((char*)s);
}

extern "C" void fn_801E63B0(void* s)
{
    fn_8037CF5C(fn_8037C7FC(), 0xEC1BCE8D, s);
}

extern "C" void fn_801E63EC(char* s)
{
    fn_8037B7E4(s, lbl_805D3DF4);
    fn_8037B7E8(s, lbl_805D3C94);
    fn_8037B50C(s, lbl_805D3C9C, (char*)s + 4, lbl_805D3CAC, lbl_805D3CB8);
    fn_8037B50C(s, lbl_805D3CC0, (char*)s + 0xC, lbl_805D3CAC, lbl_805D3CB8);
    fn_8037B458(s, lbl_805D3DF8, (char*)s + 0x4C, lbl_805D3E08, lbl_805D3370);
    fn_8037B830(s, lbl_805D3C94);
    fn_8037B7E8(s, lbl_805D3CD0);
    fn_8037B50C(s, lbl_805D3CD8, (char*)s + 0x10, lbl_805D3CAC, lbl_805D3CE8);
    fn_8037B50C(s, lbl_805D3CF0, (char*)s + 0x18, lbl_805D3CAC, lbl_805D3CE8);
    fn_8037B458(s, lbl_805D3E0C, (char*)s + 0x50, lbl_805D3E08, lbl_805D3370);
    fn_8037B830(s, lbl_805D3CD0);
    fn_8037B7E8(s, lbl_805D3D00);
    fn_8037B50C(s, lbl_805D3D0C, (char*)s + 0x1C, lbl_805D3CAC, lbl_805D3D1C);
    fn_8037B50C(s, lbl_805D3D24, (char*)s + 0x24, lbl_805D3CAC, lbl_805D3D34);
    fn_8037B458(s, lbl_805D3E1C, (char*)s + 0x54, lbl_805D3E08, lbl_805D3370);
    fn_8037B830(s, lbl_805D3D00);
    fn_8037B7E8(s, lbl_805D3D3C);
    fn_8037B50C(s, lbl_805D3D48, (char*)s + 0x28, lbl_805D3CAC, lbl_805D3D58);
    fn_8037B50C(s, lbl_805D3D60, (char*)s + 0x30, lbl_805D3CAC, lbl_805D3D70);
    fn_8037B458(s, lbl_805D3E2C, (char*)s + 0x58, lbl_805D3E08, lbl_805D3370);
    fn_8037B830(s, lbl_805D3D3C);
    fn_8037B7E8(s, lbl_805D3D78);
    fn_8037B50C(s, lbl_805D3D84, (char*)s + 0x34, lbl_805D3CAC, lbl_805D3D34);
    fn_8037B50C(s, lbl_805D3D94, (char*)s + 0x3C, lbl_805D3CAC, lbl_805D3D1C);
    fn_8037B458(s, lbl_805D3E3C, (char*)s + 0x5C, lbl_805D3E08, lbl_805D3370);
    fn_8037B830(s, lbl_805D3D78);
    fn_8037B7E8(s, lbl_805D3DA4);
    fn_8037B50C(s, lbl_805D3DB0, (char*)s + 0x40, lbl_805D3CAC, lbl_805D3D70);
    fn_8037B50C(s, lbl_805D3DC0, (char*)s + 0x48, lbl_805D3CAC, lbl_805D3D58);
    fn_8037B458(s, lbl_805D3E4C, (char*)s + 0x60, lbl_805D3E08, lbl_805D3370);
    fn_8037B830(s, lbl_805D3DA4);
}

extern const float lbl_805D3E5C;
extern const float lbl_805D3E60;

extern "C" Unk801E61C0_Vec3 fn_801E66E4(Unk801E61C0_O* o, int k)
{
    Unk801E61C0_Vec3 v;
    if (k == 0) {
        v = lbl_805D6790;
    } else {
        v = o->m4[fn_801E67B4(k)];
        v.y = lbl_805D3E60;
        v.x = v.x * lbl_805D3E5C;
        v.z = v.z * lbl_805D3E5C;
    }
    return v;
}

extern "C" int fn_801E67B4(unsigned x)
{
    if (x <= 5)
        return x;
    return 0;
}

extern const float lbl_805D3EB8;
struct Unk801E67C8_F2 {
    float x;
    float y;
};
struct Unk801E67C8_E {
    float x;
    float y;
    float z;
    int w;
    int v;
};
struct Unk801E67C8_Obj {
    const void* m0;
    Unk801E67C8_F2 m4[3];
    Unk801E67C8_E m1C[3];
};

extern "C" void* fn_801E67C8(void* mem)
{
    Unk801E67C8_Obj* o = (Unk801E67C8_Obj*)mem;
    new (mem) Unk8037B3E8(0xEAB27FC1u);
    o->m0 = lbl_80660AD8;
    for (int i = 0; i < 3; i++) {
        o->m4[i].x = lbl_805D3EB8;
        o->m4[i].y = lbl_805D3EB8;
        o->m1C[i].x = lbl_805D3EB8;
        o->m1C[i].y = lbl_805D3EB8;
        o->m1C[i].z = lbl_805D3EB8;
        o->m1C[i].w = 0;
        o->m1C[i].v = 2;
    }
    return o;
}

extern "C" void fn_801E6870(Unk801E5EBC* s)
{
    s->m0 = lbl_80660AD8;
    fn_8037B424(s);
}

extern "C" void* fn_801E68A0()
{
    return fn_801E67C8(operator new(0x58, lbl_806EF9B4));
}

extern "C" void fn_801E68D0(void* s)
{
    fn_801E695C((char*)s);
}

struct Unk801E68F0_R14 {
    int ma;
    int mb;
    char pad8[0x14 - 8];
};
struct Unk801E68F0_S {
    char pad0[0x28];
    Unk801E68F0_R14 m28[3];
};

extern "C" void fn_801E68F0(Unk801E68F0_S* s)
{
    for (int i = 0; i < 3; i++) {
        s->m28[i].ma = 0;
        s->m28[i].mb = 2;
    }
}

extern "C" void fn_801E6920(void* s)
{
    fn_8037CF5C(fn_8037C7FC(), 0xEAB27FC1, s);
}

extern "C" void fn_801E695C(char* s)
{
    fn_8037B7E4(s, lbl_805D3EBC);
    fn_8037B7E8(s, lbl_805D3EC0);
    fn_8037B50C(s, lbl_805D3ECC, (char*)s + 4, lbl_805D3ED8, lbl_805D3EE4);
    fn_8037B50C(s, lbl_805D3EE8, (char*)s + 8, lbl_805D3ED8, lbl_805D3EF8);
    fn_8037B830(s, lbl_805D3EC0);
    fn_8037B7E8(s, lbl_805D3EFC);
    fn_8037B50C(s, lbl_805D3F08, (char*)s + 0xC, lbl_805D3ED8, lbl_805D3EE4);
    fn_8037B50C(s, lbl_805D3F18, (char*)s + 0x10, lbl_805D3ED8, lbl_805D3F28);
    fn_8037B830(s, lbl_805D3EFC);
    fn_8037B7E8(s, lbl_805D3F2C);
    fn_8037B50C(s, lbl_805D3F38, (char*)s + 0x14, lbl_805D3ED8, lbl_805D3EE4);
    fn_8037B50C(s, lbl_805D3F44, (char*)s + 0x18, lbl_805D3ED8, lbl_805D3F54);
    fn_8037B830(s, lbl_805D3F2C);
}

extern "C" unsigned fn_801E6B84(int x)
{
    unsigned d = x - 6;
    if (d <= 2)
        return d;
    return 1;
}
