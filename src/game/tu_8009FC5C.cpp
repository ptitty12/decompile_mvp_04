/*
 * Game code, .text 0x8009FC5C-0x800A23F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80090880.h"

extern const char lbl_805B3B4C[];

extern "C" void fn_80071E2C(void* p, int a, void* s);

struct Unk8009FC5C_Stream {
    int m0;
    virtual void v1(int a, int* p, int n);
};

struct Unk8009FC5C {
    char pad0[0x1C];
    int m1C;
    char pad20[4];
    int* m24;
};

extern "C" void fn_8009FC5C(Unk8009FC5C* p, int a, Unk8009FC5C_Stream* s)
{
    fn_80071E2C(p, a, s);
    s->v1(a, p->m24, p->m1C * 0x3C);
}

RecA::RecA(const char* name, DbObj* db, int c) : Rec(name, db, c), m24(0)
{
    m24 = new (0) int[m1C];
    fn_8040074C(m24, m1C * 4);
    m14 = fn_800736EC(lbl_805B3B4C);
}

RecA::~RecA()
{
    if (m24) {
        delete[] m24;
        m24 = 0;
    }
}

extern "C" void fn_8009FD8C(Unk8009FC5C* p, unsigned i)
{
    if (i < p->m1C)
        fn_8040074C(&p->m24[i], 4);
}

extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

extern "C" void fn_8009FE64(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A001C() {}

struct Unk800A0020 {
    char pad0[0x20];
    virtual ~Unk800A0020();
    virtual void v2(int idx);
    virtual int v3(int a);
    virtual int v4(int a);
    virtual int v5(int ch, int idx);
    virtual void v6(int a, int b, char* out);
    virtual float v7(int ch, int idx);
};

extern "C" float fn_800A0020(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(0, idx);
    float b = (float)p->v5(2, idx);
    return a + b;
}

extern "C" float fn_800A00E4(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(1, idx);
    float b = (float)p->v5(3, idx);
    return a + b;
}

extern "C" float fn_800A01A8(Unk800A0020* p, int idx)
{
    float a = p->v7(3, idx);
    float b = p->v7(4, idx);
    return a + b;
}

extern "C" float fn_800A0228(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(0, idx);
    float b = (float)p->v5(1, idx);
    return a + b;
}

extern "C" float fn_800A02EC(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(2, idx);
    float b = (float)p->v5(3, idx);
    return a + b;
}

extern const float lbl_805B5DB0;

extern "C" float fn_800A03B0(Unk800A0020* p, int idx)
{
    float a = p->v7(0, idx);
    float b = p->v7(1, idx);
    float s = a + b;
    float r;
    if (!(s <= lbl_805B5DB0))
        r = a / s;
    else
        r = lbl_805B5DB0;
    return r;
}

extern const float lbl_805B5DC0;

extern "C" float fn_800A0460(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(0, idx);
    float b = (float)p->v5(1, idx);
    float s = a + b;
    float r;
    if (!(s <= lbl_805B5DC0))
        r = a / s;
    else
        r = lbl_805B5DC0;
    return r;
}

extern const float lbl_805B5DD0;

extern "C" float fn_800A0554(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(2, idx);
    float b = (float)p->v5(3, idx);
    float s = a + b;
    float r;
    if (!(s <= lbl_805B5DD0))
        r = a / s;
    else
        r = lbl_805B5DD0;
    return r;
}

extern "C" void fn_800A0648(Unk8009FC5C* p, int a, Unk8009FC5C_Stream* s)
{
    fn_80071E2C(p, a, s);
    s->v1(a, p->m24, p->m1C * 4);
}

RecB::RecB(const char* name, DbObj* db, int c) : Rec(name, db, c), m24(0)
{
    m24 = new (0) int[m1C];
    fn_8040074C(m24, m1C * 4);
    m14 = fn_800736EC(lbl_805B3B4C);
}

RecB::~RecB()
{
    if (m24) {
        delete[] m24;
        m24 = 0;
    }
}

extern "C" void fn_800A0778(Unk8009FC5C* p, unsigned i)
{
    if (i < p->m1C)
        fn_8040074C(&p->m24[i], 4);
}

extern "C" int fn_800A07B4() { return 0; }

extern "C" int fn_800A07BC() { return 0; }

extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

extern "C" void fn_800A0810(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A0954() {}

extern "C" void fn_800A0A4C(Unk8009FC5C* p, int a, Unk8009FC5C_Stream* s)
{
    fn_80071E2C(p, a, s);
    s->v1(a, p->m24, p->m1C * 4);
}

struct Unk800A0AA8 {
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
    int m3C;
};

extern "C" Unk800A0AA8* fn_800A0AA8(Unk800A0AA8* p)
{
    p->m0 = 0;
    p->m4 = 0;
    p->m8 = 0;
    p->mC = 0;
    p->m10 = 0;
    p->m14 = 0;
    p->m18 = 0;
    p->m1C = 0;
    p->m20 = 0;
    p->m24 = 0;
    p->m28 = 0;
    p->m2C = 0;
    p->m30 = 0;
    p->m34 = 0;
    p->m38 = 0;
    p->m3C = 0;
    return p;
}

extern "C" void fn_800A1164(void* p);
extern "C" void fn_80377408(void* p); /* __builtin_delete */

extern "C" void fn_800A0AF4(void* p, int c)
{
    fn_800A1164(p);
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_800A13A4(void* p);
extern int lbl_80619948;

extern "C" void fn_800A152C()
{
    if (lbl_80619948 == 0)
        fn_800A13A4(operator new(0x108, 0));
}

struct Unk800A188C {
    char pad0[0x28];
    int m28;
};

extern "C" void fn_800A0B34(void* p, int a, int b);
extern int lbl_8061930C;

extern "C" void fn_800A188C(Unk800A188C* p) { fn_800A0B34((char*)p + 0x2C, lbl_8061930C, p->m28); }

extern "C" void fn_800A18C0(char* p) { fn_800A1164(p + 0x2C); }

struct Unk800A18E4_Q {
    char pad0[8];
    int m8;
};

struct Unk800A18E4 {
    char pad0[0x24];
    Unk800A18E4_Q* m24;
    char pad28[0x4C];
    int m74;
    char pad78[8];
    int m80;
    char pad84[0x20];
    int mA4;
};

extern "C" int fn_805467E0(int a);

extern "C" void fn_800A18E4(Unk800A18E4* p)
{
    int r = fn_805467E0(p->m24->m8);
    if (r == 0) {
        p->m74 = 1;
        p->mA4 = r;
        p->m80 = r;
    }
}

extern "C" void fn_80546A24(int a, float x);

extern "C" void fn_800A1930(Unk800A18E4* p, float x)
{
    fn_80546A24(p->m24->m8, x);
}

struct Unk800A1960_Q {
    char pad0[8];
    int m8;
};

struct Unk800A1960 {
    char pad0[0x24];
    Unk800A1960_Q* m24;
};

extern "C" int fn_800A1960(Unk800A1960* p)
{
    Unk800A1960_Q* q = p->m24;
    if (!q)
        return 0;
    return q->m8;
}

extern "C" int fn_80553E4C(void* p);

struct Unk800A1978 {
    char pad0[0x24];
    void* m24;
};

extern "C" int fn_800A1978(Unk800A1978* p) { return fn_80553E4C(p->m24); }

extern "C" int fn_80553E54(void* p);

struct Unk800A199C {
    char pad0[0x24];
    void* m24;
};

extern "C" int fn_800A199C(Unk800A199C* p) { return fn_80553E54(p->m24); }

extern "C" int fn_80553E60(void* p);

struct Unk800A19C0 {
    char pad0[0x24];
    void* m24;
};

extern "C" int fn_800A19C0(Unk800A19C0* p) { return fn_80553E60(p->m24); }

struct Unk800A1A6C {
    char pad0[0x80];
    int m80;
};

extern "C" int fn_800A2E90(Unk800A1A6C* p);
extern "C" int fn_800A1B74(Unk800A1A6C* p);

extern "C" int fn_800A1A6C(Unk800A1A6C* p)
{
    if (p->m80 == 8)
        return 1;
    if (!fn_800A2E90(p))
        return 0;
    return fn_800A1B74(p);
}

extern "C" int fn_800A2EB4(Unk800A1A6C* p);
extern "C" int fn_800A2ED8(Unk800A1A6C* p);

extern "C" int fn_800A1AC0(Unk800A1A6C* p)
{
    if (p->m80 == 9)
        return 1;
    if (fn_800A2EB4(p) && fn_800A2ED8(p) == 10)
        return 1;
    return 0;
}

extern "C" int fn_800A2E6C(Unk800A1A6C* p);

extern "C" int fn_800A1B20(Unk800A1A6C* p)
{
    if (p->m80 == 0xB)
        return 1;
    if (!fn_800A2E6C(p))
        return 0;
    return fn_800A1B74(p);
}

struct Unk800A22F0 {
    char pad0[0x60];
    int m60;
};

extern "C" int fn_805421B8(int a);

extern "C" int fn_800A22F0(Unk800A22F0* p)
{
    int r = fn_805421B8(p->m60);
    if (r > 0)
        return r + 0x4E20;
    return 0;
}

struct Unk800A2328 {
    char pad0[0x6C];
    int m6C;
};

extern "C" void fn_800A2328(Unk800A2328* p, int v) { p->m6C = v; }
