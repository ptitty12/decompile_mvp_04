/*
 * Game code, .text 0x8009FC5C-0x800A23F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80090880.h"
struct Unk800A083C_Obj {
    virtual void M(int a);
};
typedef void (Unk800A083C_Obj::*Unk800A083C_Pmf)(int);
extern Unk800A083C_Pmf lbl_805B6E18[];

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

/* Every column yields 0; the original keeps the case tree as dead compares
   (PATTERNS, "Hard-case families 4"). */
extern "C" int fn_8009FDC8(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    }
    return r;
}

extern "C" int fn_8009FDD4(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    }
    return r;
}

struct Unk8009FDE0 {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    unsigned char* m24;
};

extern "C" unsigned char fn_8009FDE0(Unk8009FDE0* p, int ch, unsigned idx)
{
    unsigned char r = 0;
    if (idx < p->m1C) {
        switch ((unsigned)ch) {
        case 0:
            r = p->m24[idx * 4];
            break;
        case 1:
            r = p->m24[idx * 4 + 1];
            break;
        case 2:
            r = p->m24[idx * 4 + 2];
            break;
        case 3:
            r = p->m24[idx * 4 + 3];
            break;
        }
    }
    return r;
}

extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

extern "C" void fn_8009FE64(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

struct Unk8009FE90_Obj {
    virtual float M(int a);
};
typedef float (Unk8009FE90_Obj::*Unk8009FE90_Pmf)(int);
extern Unk8009FE90_Pmf lbl_805B6DD8[];

extern "C" float fn_8009FE90(Unk8009FE90_Obj* o, int i, int a)
{
    return (o->*lbl_805B6DD8[i])(a);
}

extern "C" void fn_8009FF20(Unk8009FDE0* p, int ch, unsigned idx, int v)
{
    if (idx < p->m1C) {
        switch ((unsigned)ch) {
        case 0: {
            int b = (int)p->m24;
            unsigned char* q = (unsigned char*)(idx * 4 + b);
            if (v <= 255) {
                if (v < 0)
                    v = 0;
                q[0] = v;
            } else
                q[0] = 255;
            break;
        }
        case 1: {
            unsigned char* q = (unsigned char*)(idx * 4 + (int)p->m24);
            if (v <= 255) {
                if (v < 0)
                    v = 0;
                q[1] = v;
            } else
                q[1] = 255;
            break;
        }
        case 2: {
            unsigned char* q = (unsigned char*)(idx * 4 + (int)p->m24);
            if (v <= 255) {
                if (v < 0)
                    v = 0;
                q[2] = v;
            } else
                q[2] = 255;
            break;
        }
        case 3: {
            unsigned char* q = (unsigned char*)(idx * 4 + (int)p->m24);
            q[3] = v > 255 ? 255 : (v < 0 ? 0 : v);
            break;
        }
        }
    }
}

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

extern "C" float fn_800A03B0(Unk800A0020* p, int idx)
{
    float a = p->v7(0, idx);
    float b = p->v7(1, idx);
    float s = a + b;
    float r = !(s <= 0.0f) ? a / s : 0.0f;
    return r;
}

extern "C" float fn_800A0460(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(0, idx);
    float b = (float)p->v5(1, idx);
    float s = a + b;
    float r = !(s <= 0.0f) ? a / s : 0.0f;
    return r;
}

extern "C" float fn_800A0554(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(2, idx);
    float b = (float)p->v5(3, idx);
    float s = a + b;
    float r = !(s <= 0.0f) ? a / s : 0.0f;
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

extern "C" unsigned short fn_800A07C4(Unk8009FDE0* p, int ch, unsigned idx)
{
    unsigned short r = 0;
    if (idx < p->m1C) {
        switch (ch) {
        case 0:
            r = *(unsigned short*)(p->m24 + idx * 4);
            break;
        case 1:
            r = *(unsigned short*)(p->m24 + idx * 4 + 2);
            break;
        }
    }
    return r;
}

extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

extern "C" void fn_800A0810(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A083C(Unk800A083C_Obj* o, int i, int a)
{
    (o->*(*(lbl_805B6E18 + i)))(a);
}

extern "C" void fn_800A08C8(Unk8009FDE0* p, int ch, unsigned idx, int v)
{
    if (idx < p->m1C) {
        switch ((unsigned)ch) {
        case 0: {
            int b = (int)p->m24;
            unsigned short* q = (unsigned short*)(idx * 4 + b);
            if (v <= 65535) {
                if (v < 0)
                    v = 0;
                q[0] = v;
            } else
                q[0] = 65535;
            break;
        }
        case 1: {
            unsigned short* q = (unsigned short*)(idx * 4 + (int)p->m24);
            q[1] = v > 65535 ? 65535 : (v < 0 ? 0 : v);
            break;
        }
        }
    }
}

extern "C" void fn_800A0954() {}

extern "C" float fn_800A0958(Unk800A0020* p, int idx)
{
    float a = (float)p->v5(0, idx);
    float b = (float)p->v5(1, idx);
    float s = a + b;
    float r = !(s <= 0.0f) ? a / s : 0.0f;
    return r;
}

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

struct Unk800A13A4 {
    char pad0[0x18];
    const void* m18;
    char pad1C[8];
    int m24;
    void* m28;
    char pad2C[0x6C - 0x2C];
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    float mA0;
    int mA4;
    char padA8[0xD4 - 0xA8];
    int mD4;
    int mD8;
    char padDC[0xE8 - 0xDC];
    int mE8;
};
extern "C" void fn_803282A8(void* p, int a);
extern "C" void fn_80599B24(void* p);
extern "C" void* fn_8056A248(void* mem, int g);
struct Unk800A14B8;
extern "C" void fn_800A14B8(Unk800A14B8* p, int c);
extern "C" int fn_8007F9B4(int g);
extern int lbl_80619948;
extern int lbl_8061930C;
extern const char lbl_80649F20[];

extern "C" void* fn_800A13A4(void* q)
{
    Unk800A13A4* p = (Unk800A13A4*)q;
    fn_803282A8(p, 0);
    p->m24 = 0;
    p->m28 = 0;
    p->m18 = lbl_80649F20;
    fn_800A0AA8((Unk800A0AA8*)((char*)p + 0x2C));
    p->m70 = 0;
    p->m74 = 0;
    p->m78 = 0;
    p->m7C = 0;
    p->m80 = 0;
    p->m9C = 0;
    p->mA4 = 0;
    p->m6C = 3;
    p->m84 = -1;
    p->m88 = -1;
    p->m8C = -1;
    p->m90 = -1;
    p->m94 = -1;
    p->m98 = -1;
    p->mA0 = 0.0f;
    fn_80599B24((char*)p + 0xA8);
    p->mD4 = 0;
    p->mD8 = 0;
    p->mE8 = 0;
    if (lbl_80619948 != 0) {
        if (p) {
            fn_800A14B8((Unk800A14B8*)p, 3);
        }
    } else {
        lbl_80619948 = (int)p;
        p->m8C = fn_8007F9B4(lbl_8061930C);
        if (p->m28 == 0) {
            p->m28 = fn_8056A248(operator new(0x30, 0), lbl_8061930C);
        }
    }
    return p;
}

extern "C" void fn_80328374(void* p, int c);
extern const char lbl_80649F20[];
struct Unk800A14B8 {
    char pad0[0x18];
    const void* m18;
    char pad1C[0xC];
    int* m28;
};

extern "C" void fn_800A14B8(Unk800A14B8* p, int c)
{
    p->m18 = lbl_80649F20;
    fn_800A1164((char*)p + 0x2C);
    if (p->m28) {
        delete p->m28;
        p->m28 = 0;
    }
    fn_800A0AF4((char*)p + 0x2C, 2);
    fn_80328374(p, c);
}

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

extern "C" void fn_8057C8F8(void* s, int a);
extern "C" void fn_8057CBA4(void* s);
extern "C" void fn_8057C9D0(void* s, int a);
extern "C" void fn_8057CAF8(void* s);
extern "C" void fn_8057C99C(void* s, int a);

extern "C" void fn_800A19E4(int a, int flag)
{
    char sp8[0x418];
    fn_8057C8F8(sp8, a);
    if (flag != 0) {
        fn_8057CBA4(sp8);
        fn_8057C9D0(sp8, 0);
        fn_8057CAF8(sp8);
        fn_8057C9D0(sp8, 1);
    } else {
        fn_8057CAF8(sp8);
        fn_8057C9D0(sp8, 1);
    }
    fn_8057C99C(sp8, 2);
}

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

extern int lbl_8061930C;
extern "C" int fn_8007FB2C(int g, int a);
extern "C" int fn_8007FDA8(int g, int a, int b);

extern "C" int fn_800A1B74()
{
    int g = lbl_8061930C;
    int a0 = fn_8007FB2C(g, 0);
    int a1 = fn_8007FB2C(g, 1);
    int a2 = fn_8007FB2C(g, 2);
    int a3 = fn_8007FB2C(g, 3);
    if (fn_8007FDA8(g, a0 - 1, 0) != 0
        && (a3 == 0
            || (fn_8007FDA8(g, a1 - 1, 1) == 1 && fn_8007FDA8(g, a2 - 1, 2) == 1
                && fn_8007FDA8(g, a3 - 1, 3) == 1)))
        return 1;
    return 0;
}

struct Unk800A1F24 {
    char pad0[0x24];
    void* m24;
    char pad28[0x6C - 0x28];
    int m6C;
    int m70;
    int m74;
    int m78;
    char pad7C[4];
    int m80;
    char pad84[0x90 - 0x84];
    int m90;
    int m94;
    char pad98[0xD4 - 0x98];
    int mD4;
    int mD8;
};
struct Unk800B555C_R {
    char pad0[0x594];
    int m594;
};
extern "C" void fn_800A286C(void* p, int a);
extern "C" void fn_80554228(void* o);
extern "C" void fn_80554260(void* o, int k, int a);
extern "C" void fn_80554284(void* o, int a, int b);
extern "C" Unk800B555C_R* fn_800B555C();
extern "C" void fn_8007C134(int g);

extern "C" void fn_800A1F24(Unk800A1F24* p, int flags, int a, int b)
{
    if (p->m24 == 0) {
        fn_800A286C(p, p->m6C);
    }
    fn_80554228(p->m24);
    int r = 0;
    if (a != 0 && (flags & 0x38)) {
        r = 1;
    }
    if (r == 1) {
        int k = 2;
        if (flags & 8) {
            k = 0;
        } else if (flags & 0x10) {
            k = 1;
        }
        if (k == 2) {
            p->mD4 = 1;
        }
        fn_80554260(p->m24, k, a);
        p->m80 = 0xF;
        p->m78 = 2;
        p->m70 = 2;
        p->m90 = -1;
        p->m94 = -1;
        p->m74 = 2;
    }
    if (b != 0) {
        int t = fn_800B555C()->m594;
        fn_80554284(p->m24, t, b);
        if (t == 2) {
            p->mD8 = 1;
        }
        fn_8007C134(lbl_8061930C);
    }
}

struct Unk800A2030 {
    char pad0[0x24];
    void* m24;
    char pad28[0x6C - 0x28];
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
};
struct Unk800A2030_E {
    char pad0[0x1E0];
    int m1E0;
};
extern "C" Unk800A2030_E* fn_8007FE04(int g);
extern "C" void fn_8007F858(int g);
extern "C" void fn_8007295C(int g);
extern "C" void fn_8007F8E4(int g, int e);
extern "C" void fn_8058F08C(int a);
extern "C" void fn_80590A48(int a);
extern "C" void fn_80581770(int a);
extern "C" void fn_800A4F54(void* p);
extern "C" void fn_800A6618(void* p, int a);
extern "C" void fn_80553668(void* p, int a);
extern "C" int fn_800A2EB4(Unk800A1A6C* p);
extern "C" void fn_800766B8(int g, int a);

extern "C" void fn_800A2030(Unk800A2030* p, int flag)
{
    if (p->m6C == 1) {
        if (flag != 0) {
            if (fn_800A1A6C((Unk800A1A6C*)p) != 0) {
                fn_800A6618(p, 0);
            } else if (fn_800A1AC0((Unk800A1A6C*)p) != 0 || fn_800A2EB4((Unk800A1A6C*)p) != 0) {
                fn_800A6618(p, 1);
            }
        }
        fn_8007FE04(lbl_8061930C)->m1E0 = 1;
    }
    fn_8058F08C(*(int*)(lbl_8061930C + 0x34));
    fn_8007F858(lbl_8061930C);
    fn_8007295C(lbl_8061930C);
    fn_80590A48(*(int*)(lbl_8061930C + 0x30));
    fn_80581770(*(int*)(lbl_8061930C + 0x2C));
    fn_800A4F54(p);
    volatile int sp8 = 0;
    int e = 0;
    do {
        fn_8007F8E4(lbl_8061930C, e);
        int c = sp8;
        int t;
        if (c > 3) {
            t = c;
        } else {
            t = c + 1;
        }
        sp8 = t;
        e = t;
    } while (e <= 3);
    fn_800766B8(lbl_8061930C, 0);
    p->m6C = 3;
    p->m70 = 0;
    p->m74 = 0;
    p->m78 = 0;
    p->m7C = 0;
    p->m80 = 0;
    if (p->m24 != 0) {
        fn_80553668(p->m24, 3);
        p->m24 = 0;
    }
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

struct Unk800A2330 {
    char pad0[0x48];
    int m48;
    char pad4C[0x70 - 0x4C];
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    char pad8C[0x98 - 0x8C];
    int m98;
};

extern "C" void fn_80565090(int a);
extern "C" void fn_80590910(int a);
extern "C" void fn_800766B8(int g, int a);
extern "C" int fn_8007F9B4(int g);
extern "C" int fn_8007F9E8(int g);
extern "C" void fn_800A42EC(void* p);

extern "C" void fn_800A2330(Unk800A2330* p)
{
    p->m70 = 2;
    p->m7C = p->m78;
    p->m78 = 0;
    int g = lbl_8061930C;
    if (fn_800A2E6C((Unk800A1A6C*)p) == 1) {
        fn_80565090(p->m48);
        fn_80590910(*(int*)(lbl_8061930C + 0x30));
        p->m74 = 2;
        p->m80 = 0xC;
        fn_800A19E4(0x3F, 1);
    } else {
        fn_800766B8(g, 0);
    }
    int old = p->m84;
    p->m84 = fn_8007F9B4(lbl_8061930C);
    p->m88 = fn_8007F9E8(lbl_8061930C);
    p->m98 = p->m84 - old;
    fn_800A42EC(p);
}
