/*
 * Game code, .text 0x8035ECE4-0x8035F63C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8035B60C.h"
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))
#define PUTB(o, v) (*(unsigned char*)((char*)self + (o)) = (v))
#define PUTF(o, v) (*(float*)((char*)self + (o)) = (v))
#define CPUT(o, v) (*(const void**)((char*)this + (o)) = (v))
#define CPUTI(o, v) (*(int*)((char*)this + (o)) = (v))
#define CPUTB(o, v) (*(unsigned char*)((char*)this + (o)) = (v))
#define CPUTF(o, v) (*(float*)((char*)this + (o)) = (v))
#define GETI(o) (*(int*)((char*)self + (o)))
struct U {
    char pad0[0x4000];
};
void fn_80377408(void* p);
extern char lbl_80649DA0[];
extern char lbl_806604F8[];
extern char lbl_806641D0[];
extern char lbl_80664390[];
extern char lbl_80664868[];
extern char lbl_80664268[];
extern char lbl_806642A8[];
extern char lbl_80664348[];
void fn_802D8A84__15Unk802D73B4_Mgr(void* p, int chrg);
void fn_802D8AD8__15Unk802D73B4_Mgrii(void* p, int chrg);
void fn_80328374(void* p, int chrg);
extern char lbl_80664AA8[];
int fn_803BE7B4(void* p);
void fn_80377458(void* p);
void fn_80377488(void* p);
void fn_803ED664(void* p);
void fn_803EDA0C(void* p);
void fn_803EE310(void* p);
struct Unk8035EDD8_T {
    int m0;
    int m4;
    int m8;
    int mC;
    int* m10;
    int* m14;
};
struct Unk8035EDD8 {
    int m0;
    Unk8035EDD8_T* m4;
};
struct Unk8035ED5C {
    int m0;
    int m4[15];
};
struct Unk8035F3A0 {
    char pad0[0x28];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};
struct Unk8035F47C {
    float m0;
    float m4;
    float m8;
    float mC;
    Unk8035F47C(const Unk8035F47C& o);
};
struct Unk8035F4A4 {
    float m0;
    float m4;
    float m8;
    float mC;
    Unk8035F4A4(float a, float b, float c, float d);
};
struct Unk8035F4EC_V {
    float m0;
    float m4;
    float m8;
    float mC;
    Unk8035F4EC_V(const Unk8035F4EC_V& o) { m0 = o.m0; m4 = o.m4; m8 = o.m8; mC = o.mC; }
};
struct Unk8035F4EC {
    Unk8035F4EC_V m0;
    Unk8035F4EC_V m10;
    Unk8035F4EC(const Unk8035F4EC& o);
};
struct Unk8035DD24_Heap {
    int m0;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* p);
};
extern Unk8035DD24_Heap* lbl_8061F68C;

struct Unk8035ECE4 {
    char pad0[0x400];
    Unk8035ECE4();
};

Unk8035ECE4::Unk8035ECE4()
{
    CPUTI(0x0, 0);
    CPUT(0x4, lbl_80664268);
}

void fn_8035ED00(U* self, int chrg)
{
    PUT(0x4, lbl_80664390);
    if (chrg & 1)
        fn_80377408(self);
}

char* fn_8035ED34(char* p) { return p + 0x10; }

char* fn_8035ED3C(char* p) { return p + 0x14; }

char* fn_8035ED44(char* p) { return p + 0x18; }

char* fn_8035ED4C(char* p) { return p + 0x1c; }

char* fn_8035ED54(char* p) { return p + 0x20; }

void fn_8035ED5C(Unk8035ED5C* s)
{
    s->m0 = 0;
    for (int i = 0; i < 15; i++)
        s->m4[i] = 0;
}

struct Unk8035ED88 {
    char pad0[0x400];
    Unk8035ED88();
};

Unk8035ED88::Unk8035ED88()
{
    CPUT(0x0, lbl_80664348);
}

void fn_8035ED9C(U* self, int chrg)
{
    PUT(0x0, lbl_806641D0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035EDD0(U* self, int v) { PUTI(0x4, v); }

int fn_8035EDD8(Unk8035EDD8* s) { return s->m4->m4; }

int fn_8035EDE4(Unk8035EDD8* s, int i) { return s->m4->m10[i]; }

int fn_8035EDF8(Unk8035EDD8* s, int i) { return s->m4->m14[i]; }

int fn_8035EE0C(Unk8035EDD8* s)
{
    Unk8035EDD8_T* t = s->m4;
    int i = fn_803BE7B4(t);
    int r;
    if (i == -1)
        r = 0;
    else
        r = t->m10[i];
    return r;
}

int fn_8035EE58(Unk8035EDD8* s) { return fn_803BE7B4(s->m4); }

int fn_8035EE7C(Unk8035EDD8* s) { return s->m4->m8; }

struct Unk8035EE88 {
    char pad0[0x400];
    Unk8035EE88();
};

Unk8035EE88::Unk8035EE88()
{
    CPUT(0x0, lbl_806642A8);
}

void fn_8035EE9C(U* self, int chrg)
{
    fn_80328374(self, chrg);
}

void fn_8035EEBC(U* self)
{
    PUTI(0x0, 0);
    PUTI(0x4, 0);
    PUTI(0x8, 0);
}

void fn_8035EED0(U* self, int chrg)
{
    PUT(0x4, lbl_80664390);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035EF04() {}

void fn_8035EF08() {}

void fn_8035EF0C(U* self, void* p) { fn_80377458(p); }

void fn_8035EF30(U* self, void* p)
{
    if (p)
        fn_80377488(p);
}

int fn_8035EF58() { return 0; }

void fn_8035EF60() {}

void fn_8035EF64() {}

void fn_8035EF68(U* self, void* p) { fn_803ED664(p); }

void fn_8035EF8C(U* self, void* p) { fn_803EDA0C(p); }

void fn_8035EFB0(U* self, void* p) { fn_803EE310(p); }

void fn_8035EFD4(U* self, int chrg)
{
    PUT(0x98, lbl_806604F8);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035F36C(U* self, int chrg)
{
    PUT(0x28, lbl_80664868);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035F3A0(Unk8035F3A0* p) { p->v13(); }

void fn_8035F3D4(Unk8035F3A0* p) { p->v14(); }

void fn_8035F408(U* self, int chrg)
{
    fn_802D8A84__15Unk802D73B4_Mgr(self, chrg);
}

void fn_8035F428(U* self, int chrg)
{
    fn_802D8AD8__15Unk802D73B4_Mgrii(self, chrg);
}

void fn_8035F448(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

Unk8035F47C::Unk8035F47C(const Unk8035F47C& o)
{
    m0 = o.m0;
    m4 = o.m4;
    m8 = o.m8;
    mC = o.mC;
}

Unk8035F4A4::Unk8035F4A4(float a, float b, float c, float d)
{
    m0 = a;
    m4 = b;
    m8 = c;
    mC = d;
}

void fn_8035F4E4() {}

void fn_8035F4E8() {}

Unk8035F4EC::Unk8035F4EC(const Unk8035F4EC& o) : m0(o.m0), m10(o.m10) {}

void fn_8035F53C(U* self, int chrg)
{
    PUT(0x74, lbl_80664AA8);
    if (chrg & 1)
        lbl_8061F68C->v5(self);
}

int fn_8035F590() { return 0; }

void fn_8035F598(U* self)
{
    PUTB(0x8, 0);
    PUTI(0x18, 0);
    PUTI(0x1c, 0);
    PUTI(0x4, 0);
    PUTI(0x0, 0);
}

void fn_8035F5B8(U* self, int chrg)
{
    PUT(0x74, lbl_80664AA8);
    if (chrg & 1)
        lbl_8061F68C->v5(self);
}

int fn_8035F60C() { return 1; }

void fn_8035F614() {}

void fn_8035F618() {}
