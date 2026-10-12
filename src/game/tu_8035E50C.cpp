/*
 * Game code, .text 0x8035E50C-0x8035ECE4 (code-only unit; original file and TU
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
extern char lbl_80661800[];
extern char lbl_80661880[];
extern char lbl_80664020[];
extern char lbl_80664068[];
extern char lbl_80664008[];
void fn_8014D9C4(void* p);
int fn_8035E654(int* a, int i);
int fn_8035E6B0(int* a, int i, int v);
char* fn_8035E8CC(char* p, unsigned i);
struct Unk8035E568_S {
    int m0;
    int m4;
    Unk8035E568_S() { fn_8014D9C4(this); }
};
struct Unk8035E568 {
    char pad0[8];
    Unk8035E568_S m8;
    Unk8035E568();
};
struct Unk8035E630_Obj {
    char pad0[0x458];
    int m458;
};
struct Unk8035E604 {
    int m0[4];
    int m10[4];
};
extern const float lbl_805DED20;
struct Unk8035EA10 {
    int m0;
    int m4;
    int m8;
    unsigned f0 : 1;
    unsigned f1 : 4;
    unsigned fr : 27;
    float m10;
    int m14;
    int m18;
    int m1C;
};
class Unk802A6334 {
public:
    virtual ~Unk802A6334();
};
class Unk8035EA80 {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
};
struct Unk8035E704_V {
    float x;
    float y;
    float z;
};
extern const Unk8035E704_V lbl_806055AC;
extern float lbl_805DB9F4[1];
struct Unk8035E704_E {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    int m20;
    int m24;
    Unk8035E704_V m28;
    int m34;
};
struct Unk8035E78C_Q {
    char pad0[0x4C];
    unsigned m4C;
};
struct Unk8035E78C_El {
    char pad0[0x458];
    unsigned m458;
    char pad45C[0x5D4 - 0x45C];
    float m5D4;
};
struct Unk8035E78C_P {
    char pad0[0x1EC];
    Unk8035E78C_Q* m1EC;
    char pad1F0[0x438 - 0x1F0];
    Unk8035E78C_El* m438[4];
    int m448;
};
struct Unk8035E78C {
    Unk8035E78C_P* m0;
};
extern "C" int fn_8026A75C(Unk8035E704_E* a, Unk8035E704_E* b);
void fn_8037B16C(void* p, float v);
void fn_8037D768(void* p);
struct Unk8035EB7C_M {
    int w[16];
};
struct Unk8035EB7C_Src {
    int m0;
    char pad4[0x1C];
    Unk8035EB7C_M m20;
};
struct Unk8035EB7C_Dst {
    Unk8035EB7C_M m0;
    char pad40[0xBC - 0x40];
    unsigned mBC;
};
#include "game/chooser.h"
class Unk8038B7E4 : public Unk8037B3E8 {
public:
    Unk8038B7E4(unsigned int h);
    virtual ~Unk8038B7E4();
};
class Unk8035EB18 : public Unk8037B3E8 {
public:
    Unk8035EB18(unsigned int h);
    virtual ~Unk8035EB18();
};

void fn_8035E50C(U* self, int chrg)
{
    PUT(0x68, lbl_80661800);
    if (chrg & 1)
        fn_80377408(self);
}

int fn_8035E540(U* self, int i) { return i - 9; }

int fn_8035E548(char* p, int i)
{
    char* b = p + 0x14;
    int o = i * 12;
    return *(int*)(b + o);
}

int fn_8035E558(char* p, int i)
{
    char* b = p + 0x10;
    int o = i * 12;
    return *(int*)(b + o);
}

Unk8035E568::Unk8035E568() {}

void fn_8035E59C(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E5D0(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E604(Unk8035E604* s)
{
    for (int i = 0; i < 4; i++) {
        s->m0[i] = -1;
        s->m10[i] = 0;
    }
}

int fn_8035E630(int* a, Unk8035E630_Obj* o)
{
    return fn_8035E654(a, o->m458);
}

int fn_8035E654(int* a, int i)
{
    int o = (i - 9) * 4;
    return *(int*)((char*)a + o);
}

int fn_8035E664(int* a, Unk8035E630_Obj* o, int v)
{
    return fn_8035E6B0(a, o->m458, v);
}

void fn_8035E688(char* p, int i, int v)
{
    char* b = p + 0x10;
    int o = (i - 9) * 4;
    *(int*)(b + o) = v;
}

int fn_8035E69C(char* p, int i)
{
    char* b = p + 0x10;
    int o = (i - 9) * 4;
    return *(int*)(b + o);
}

int fn_8035E6B0(int* a, int i, int v)
{
    int k = i - 9;
    int z = 0;
    char* b = (char*)a + 0x10;
    int o = k * 4;
    *(int*)(b + o) = z;
    *(int*)((char*)a + o) = v;
    for (int j = 0; j < k; j++) {
        if (a[j] > *(int*)((char*)a + o) && z != 0)
            a[j] = *(int*)((char*)a + o);
    }
}

void fn_8035E704(char* p, unsigned i)
{
    Unk8035E704_E* e = (Unk8035E704_E*)fn_8035E8CC(p, i);
    e->m8 = 4;
    e->mC = -1;
    e->m4 = 0;
    e->m14 = 0;
    e->m1C = e->m18 = lbl_805DB9F4[0];
    e->m20 = 6;
    e->m24 = 0;
    e->m28 = lbl_806055AC;
    e->m10 = 0;
    e->m0 = 0;
    e->m34 = 0;
}

void fn_8035E78C(Unk8035E78C* self, char* other)
{
    for (int i = 0; i < self->m0->m448; i++) {
        Unk8035E78C_El* el = self->m0->m438[i];
        unsigned idx = el->m458;
        Unk8035E704_E* a = (Unk8035E704_E*)fn_8035E8CC((char*)self, idx);
        Unk8035E704_E* b = (Unk8035E704_E*)fn_8035E8CC(other, idx);
        if (el->m5D4 > (float)self->m0->m1EC->m4C * 0.016666668f)
            continue;
        if (fn_8026A75C(a, b) == 0) {
            *a = *b;
            a->m14 = 0;
        }
    }
}

/* near-miss: 5 slots. The result is accumulated in one int (r = i * 0x38; r -= 0x1F4; r += p), which puts the temporaries in r3 and
   p in r9 as retail does; left: sched order of the first four insns (retail addi r0,r4,-9 first) and the final add operand order. */
char* fn_8035E8CC(char* p, unsigned i)
{
    int r = 0;
    if (i - 9 <= 3) {
        r = i * 0x38;
        r -= 0x1F4;
        r += (int)p;
    }
    return (char*)r;
}

void fn_8035E8F0(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E924(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E958(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E98C(U* self, int chrg)
{
    PUT(0x18, lbl_80664020);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E9C0(U* self, int chrg)
{
    PUT(0x1C, lbl_80664008);
    ((Unk802A6334*)self)->Unk802A6334::~Unk802A6334();
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035EA10(Unk8035EA10* s)
{
    s->f0 = 1;
    s->m10 = lbl_805DED20;
    s->f1 = 0;
    s->m18 = 0;
    s->m14 = -1;
    s->m1C = 0;
}

Unk8038B7E4::~Unk8038B7E4() {}

void fn_8035EA74() {}

int fn_8035EA78() { return 0; }

void fn_8035EA80(Unk8035EA80* p) { p->s14(); }

void fn_8035EAB4(Unk8035EA80* p) { p->s16(); }

extern "C" void fn_8037B424(void*, int);

extern "C" void fn_8035EAE8(void* a, int b) { fn_8037B424(a, b); }


void fn_8035EB08() {}

void fn_8035EB0C() {}

void fn_8035EB10() {}

void fn_8035EB14() {}

Unk8035EB18::~Unk8035EB18() {}

void fn_8035EB48(U* self, int chrg)
{
    PUT(0x8, lbl_80664068);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035EB7C(Unk8035EB7C_Dst* d, Unk8035EB7C_Src* s)
{
    if (s->m0 == 0)
        fn_8037D768(s);
    s->m0 = 1;
    d->m0 = s->m20;
    d->mBC |= 1;
}

void fn_8035EC3C(Unk8035EB7C_Dst* d, float v)
{
    fn_8037B16C(d, v);
    d->mBC |= 1;
}

void fn_8035EC7C(U* self, int chrg)
{
    PUT(0x4, lbl_80661880);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035ECB0(U* self, int chrg)
{
    PUT(0x8, lbl_80664068);
    if (chrg & 1)
        fn_80377408(self);
}
