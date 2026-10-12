/*
 * Game code, .text 0x8009BC3C-0x8009FC5C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80090880.h"
#include "game/tu_80094578.h"

extern const char lbl_805B3B4C[];

extern "C" void fn_8009CBC8(void* o, int x);
extern "C" void fn_8009CF6C(void* o, int x);
extern "C" void fn_8009D0D4(void* o);

extern int lbl_8061930C;
struct Unk8007F198_A;
struct Unk8007A4DC_Screen {
    int fn_8007A6A0(int a, int b);
};
unsigned char fn_8007F198(Unk8007F198_A* self);
int fn_8007F24C(Unk8007F198_A* self, int a, int x);

struct Unk80089894_PackTabD;
int fn_80089AA0(Unk80089894_PackTabD* self, unsigned t, unsigned i);
struct TailE48_8009C398 {
    char pad[0xE48];
    unsigned char mE48[25];
};
extern "C" Sub198* fn_80096244(Sub198* d, Sub198* s);

extern "C" void fn_8009C398(Obj3* o)
{
    View80096C10* w = (View80096C10*)o;
    unsigned i;
    for (i = 0; i < o->m3E4; i++)
        ((TailE48_8009C398*)o)->mE48[i] = fn_80089AA0((Unk80089894_PackTabD*)((char*)o + 0xC74), 0, (unsigned char)i);
    ByteVec* v = &w->saved.v;
    Snap80096C10* dst = &w->saved;
    Snap80096C10* src = &w->cur;
    w->saved.m0 = w->cur.m0;
    unsigned n = w->cur.v.m4;
    fn_8040074C(w->saved.v.m0, v->m8);
    v->m4 = 0;
    *(int*)v->padC = 0;
    unsigned j;
    for (j = 0; j < n; j++) {
        ByteVec* d = &dst->v;
        unsigned char b = src->v.m0[j];
        unsigned c = d->m4;
        if (c < d->m8) {
            dst->v.m0[c] = b;
            d->m4 = d->m4 + 1;
        }
    }
    for (j = 0; j < 10; j++)
        dst->list[j] = src->list[j];
    fn_80096244((Sub198*)((char*)o + 0xDAC), &o->m198);
}

extern "C" void fn_8009C498(Obj3* o)
{
    int g = lbl_8061930C;
    int a = o->m198.m0;
    o->m3E4 = ((unsigned char (*)(Unk8007F198_A*, int))fn_8007F198)((Unk8007F198_A*)g, a);
    for (unsigned char i = 0; i < o->m3E4; i++) {
        int off = i * 0x34;
        int v = fn_8007F24C((Unk8007F198_A*)g, a, i);
        char* b = (char*)o + 0x3E8;
        *(int*)(b + off) = v;
        int r = ((Unk8007A4DC_Screen*)g)->fn_8007A6A0(0x1E, v);
        if (r == 0) {
            char* b2 = (char*)o + 0x3EC;
            *(int*)(b2 + off) = r;
        } else {
            char* b2 = (char*)o + 0x3EC;
            *(int*)(b2 + off) = 1;
        }
    }
}

extern "C" void fn_8009CB5C(void* o, int kind, int x)
{
    if (kind != 0) {
        switch (kind) {
        case 0:
            break;
        case 1:
            fn_8009CBC8(o, x);
            break;
        case 2:
            fn_8009CF6C(o, x);
            break;
        }
        fn_8009D0D4(o);
    }
}

extern "C" int fn_8009CDC8(void* self, int* arr)
{
    int best = 0;
    int idx = -1;
    volatile int sp8 = 0;
    int i = 0;
    do {
        int v = arr[i];
        if (v > best) {
            best = v;
            idx = i;
        }
        int t;
        if (i > 9)
            t = i;
        else
            t = i + 1;
        sp8 = t;
        i = t;
    } while (i <= 9);
    return idx;
}

extern "C" int rand(void);
extern "C" int fn_8008CFD8(void* p, int a, int b);
struct Unk80089894_PackTabD;
int fn_80089AA0(Unk80089894_PackTabD* self, unsigned t, unsigned i);
extern "C" void fn_80096830(Obj3* o, int a);

extern int lbl_8061930C;
extern "C" unsigned fn_8007F84C__FP13Unk8007F198_B(int g);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(int g, int x);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(int g, unsigned i);
extern "C" int fn_8007B6F0__18Unk8007B2B0_Screen(int g, int a, int b, int c);
extern "C" unsigned char fn_800968C0(Obj3* o, int key, int flag);

extern int lbl_8061930C;
extern "C" int fn_80097210(Obj3* o, int i);
extern "C" int fn_8007E2D8__FP13Unk8007DB74_AiiPi(int g, int a, int b, int* out);
extern "C" unsigned char fn_800968C0(Obj3* o, int key, int flag);
struct Unk80089894_PackTabD;
int fn_80089AA0(Unk80089894_PackTabD* self, unsigned t, unsigned i);
extern "C" float fn_8056FFB0();
extern "C" void fn_8009D9AC(Obj3* o);

/* near-miss: the ratio is stored in each arm of the ternary; retail joins them with one store */
extern "C" void fn_8009D0D4(void* ov)
{
    Obj3* o = (Obj3*)ov;
    float thr;
    float tmp;
    int kind;
    int g = lbl_8061930C;
    int id = fn_80097210(o, 0);
    kind = 0;
    fn_8007E2D8__FP13Unk8007DB74_AiiPi(g, o->m198.m0, id, &kind);
    thr = 0.0f;
    if (kind == 3) {
        thr = 0.05f;
    } else if (kind == 4) {
        thr = 0.15f;
    } else {
        Unk80089894_PackTabD* t = (Unk80089894_PackTabD*)((char*)o + 0xC74);
        unsigned char k = fn_800968C0(o, id, 1);
        int num = fn_80089AA0(t, 0x1B, k);
        int den = fn_80089AA0(t, 0, k);
        tmp = !((float)den <= 0.0f) ? (float)num / (float)den : 0.0f;
        if (!(tmp >= 0.7f))
            thr = 1.0f;
    }
    tmp = fn_8056FFB0();
    if (!(tmp >= thr))
        fn_8009D9AC(o);
}

extern "C" void fn_8009D8A8(Obj3* o, int a, ByteVec* v)
{
    int g = lbl_8061930C;
    unsigned i;
    unsigned n = fn_8007F84C__FP13Unk8007F198_B(g);
    int id = fn_80075948__18Unk8007B2B0_Screeni(g, o->m198.m0);
    fn_8040074C(v->m0, v->m8);
    v->m4 = 0;
    *(int*)v->padC = 0;
    for (i = 0; i < n; i++) {
        if (fn_8007F7D0__FP13Unk8007F198_BUi(g, i) == id) {
            unsigned char j;
            for (j = 0; j <= 9; j++) {
                int r = fn_8007B6F0__18Unk8007B2B0_Screen(g, id, a, j);
                if (r != 0) {
                    unsigned char k = fn_800968C0(o, r, 0);
                    if (k != 0xFF) {
                        unsigned c = v->m4;
                        if (c < v->m8) {
                            v->m0[c] = k;
                            v->m4 = v->m4 + 1;
                        }
                    }
                }
            }
        }
    }
}

extern "C" void fn_8009D9AC(Obj3* o)
{
    unsigned n = o->m14.m4;
    if (n != 0) {
        unsigned char k = o->m14.m0[(unsigned char)(rand() % n)];
        Unk80089894_PackTabD* t = (Unk80089894_PackTabD*)((char*)o + 0xC74);
        int s = fn_8008CFD8((char*)o + 0xC9C, 0x1E, k);
        int a = fn_80089AA0(t, 0x1B, k);
        int b = fn_80089AA0(t, 0, k);
        if (s == 0 && a >= b)
            fn_80096830(o, o->m3E8[k].m0);
    }
}

extern "C" int fn_8009DA60(Obj3* o, int x);
extern "C" int fn_80097A9C(char* o, int a, int b, int c, int i);
extern "C" int fn_80097A70(char* o, int a, int b, int i);

extern "C" int fn_8009DB0C(Obj3* o, int x)
{
    int a = 0;
    if (fn_8009DA60(o, x))
        a = 1;
    int b = 0;
    if (a)
        b = fn_80097A9C((char*)o, 3, x, 2, 0) == 0;
    int c = 0;
    if (b)
        c = fn_80097A9C((char*)o, 0, x, 2, 0) == 0;
    int d = 0;
    if (c) {
        int sum = 0;
        unsigned char i;
        for (i = 0; i < o->m3E4; i++)
            sum += fn_80097A70((char*)o, 1, i, 0);
        if (sum == 0)
            d = 1;
    }
    return d;
}

extern "C" int fn_8009DC00(char* o, int slot, int base, int kind)
{
    if (kind == 1) {
        char* b = o + 0x40A;
        int off = base + slot * 0x34;
        return (signed char)b[off];
    }
    if (kind == 0) {
        char* b = o + 0x412;
        int off = base + slot * 0x34;
        return (signed char)b[off];
    }
    return -1;
}

struct Unk8009DC48 {
    char pad0[0x114];
    int m114;
    char m118[1];
};

extern "C" void fn_8023C858(void* p, int a, int b);

extern "C" void fn_8009DC48(Unk8009DC48* o, int v)
{
    o->m114 = v;
    fn_8023C858(o->m118, 1, o->m114);
    fn_8023C858(o->m118, 2, o->m114);
    fn_8023C858(o->m118, 0xD, o->m114);
}

struct Unk8009DCAC {
    char pad0[0x114];
    int m114;
};

extern "C" void fn_8009DC48(Unk8009DC48* o, int v);

extern "C" void fn_8009DCAC(Unk8009DC48* o, int x) { fn_8009DC48(o, o->m114 + x); }

RecC::RecC(const char* name, DbObj* db, int c) : Rec(name, db, c), m24(0)
{
    m24 = new (0) Ent3C[m1C];
    fn_8040074C(m24, m1C * 0x3C);
    m14 = fn_800736EC(lbl_805B3B4C);
}

RecC::~RecC()
{
    if (m24) {
        delete[] m24;
        m24 = 0;
    }
}

struct Unk8009DDA8 {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    Ent3C* m24;
};

extern "C" void fn_8009DDA8(Unk8009DDA8* p, unsigned i)
{
    if (i < p->m1C)
        fn_8040074C(&p->m24[i], 0x3C);
}

union Unk8009DDE4_Val {
    int i;
    float f;
};

/* Column default: 5 for columns 54 and 55, 0 otherwise. The value lives in a
   union, so it stays in its stack slot. */
extern "C" int fn_8009DDE4(void* l, int k)
{
    Unk8009DDE4_Val v;
    v.i = 0;
    switch ((unsigned)k) {
    case 0:
        v.i = 0;
        break;
    case 1:
        v.i = 0;
        break;
    case 2:
        v.i = 0;
        break;
    case 3:
        v.i = 0;
        break;
    case 4:
        v.i = 0;
        break;
    case 5:
        v.i = 0;
        break;
    case 6:
        v.i = 0;
        break;
    case 7:
        v.i = 0;
        break;
    case 8:
        v.i = 0;
        break;
    case 9:
        v.i = 0;
        break;
    case 10:
        v.i = 0;
        break;
    case 11:
        v.i = 0;
        break;
    case 12:
        v.i = 0;
        break;
    case 13:
        v.i = 0;
        break;
    case 14:
        v.i = 0;
        break;
    case 15:
        v.i = 0;
        break;
    case 16:
        v.i = 0;
        break;
    case 17:
        v.i = 0;
        break;
    case 18:
        v.i = 0;
        break;
    case 19:
        v.i = 0;
        break;
    case 20:
        v.i = 0;
        break;
    case 21:
        v.i = 0;
        break;
    case 22:
        v.i = 0;
        break;
    case 23:
        v.i = 0;
        break;
    case 24:
        v.i = 0;
        break;
    case 25:
        v.i = 0;
        break;
    case 26:
        v.i = 0;
        break;
    case 27:
        v.i = 0;
        break;
    case 28:
        v.i = 0;
        break;
    case 29:
        v.i = 0;
        break;
    case 30:
        v.i = 0;
        break;
    case 31:
        v.i = 0;
        break;
    case 32:
        v.i = 0;
        break;
    case 33:
        v.i = 0;
        break;
    case 34:
        v.i = 0;
        break;
    case 35:
        v.i = 0;
        break;
    case 36:
        v.i = 0;
        break;
    case 37:
        v.i = 0;
        break;
    case 38:
        v.i = 0;
        break;
    case 39:
        v.i = 0;
        break;
    case 40:
        v.i = 0;
        break;
    case 41:
        v.i = 0;
        break;
    case 42:
        v.i = 0;
        break;
    case 43:
        v.i = 0;
        break;
    case 44:
        v.i = 0;
        break;
    case 45:
        v.i = 0;
        break;
    case 46:
        v.i = 0;
        break;
    case 47:
        v.i = 0;
        break;
    case 48:
        v.i = 0;
        break;
    case 49:
        v.i = 0;
        break;
    case 50:
        v.i = 0;
        break;
    case 51:
        v.i = 0;
        break;
    case 52:
        v.i = 0;
        break;
    case 53:
        v.i = 0;
        break;
    case 54:
        v.i = 5;
        break;
    case 55:
        v.i = 5;
        break;
    }
    return v.i;
}

/* Every column yields 0; the original keeps the case tree as dead compares
   (PATTERNS, "Hard-case families 4"). */
extern "C" int fn_8009E060(void* l, int k)
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
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    case 12:
        r = 0;
        break;
    case 13:
        r = 0;
        break;
    case 14:
        r = 0;
        break;
    case 15:
        r = 0;
        break;
    case 16:
        r = 0;
        break;
    case 17:
        r = 0;
        break;
    case 18:
        r = 0;
        break;
    case 19:
        r = 0;
        break;
    case 20:
        r = 0;
        break;
    case 21:
        r = 0;
        break;
    case 22:
        r = 0;
        break;
    case 23:
        r = 0;
        break;
    case 24:
        r = 0;
        break;
    case 25:
        r = 0;
        break;
    case 26:
        r = 0;
        break;
    case 27:
        r = 0;
        break;
    case 28:
        r = 0;
        break;
    case 29:
        r = 0;
        break;
    case 30:
        r = 0;
        break;
    case 31:
        r = 0;
        break;
    case 32:
        r = 0;
        break;
    case 33:
        r = 0;
        break;
    case 34:
        r = 0;
        break;
    case 35:
        r = 0;
        break;
    case 36:
        r = 0;
        break;
    case 37:
        r = 0;
        break;
    case 38:
        r = 0;
        break;
    case 39:
        r = 0;
        break;
    case 40:
        r = 0;
        break;
    case 41:
        r = 0;
        break;
    case 42:
        r = 0;
        break;
    case 43:
        r = 0;
        break;
    case 44:
        r = 0;
        break;
    case 45:
        r = 0;
        break;
    case 46:
        r = 0;
        break;
    case 47:
        r = 0;
        break;
    case 48:
        r = 0;
        break;
    case 49:
        r = 0;
        break;
    case 50:
        r = 0;
        break;
    case 51:
        r = 0;
        break;
    case 52:
        r = 0;
        break;
    case 53:
        r = 0;
        break;
    case 54:
        r = 0;
        break;
    case 55:
        r = 0;
        break;
    }
    return r;
}

struct Unk8009E93C {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    char* m24;
};

extern "C" char* fn_8040B61C(char* dst, const char* src);

extern "C" char* fn_8009E93C(Unk8009E93C* p, int kind, unsigned idx, char* out)
{
    if (idx < p->m1C) {
        switch ((unsigned)kind) {
        case 0:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x10);
            break;
        case 1:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x14);
            break;
        case 2:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x28);
            break;
        case 3:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x2C);
            break;
        }
    }
    return out;
}

struct Unk8009EA04_Obj {
    virtual float M(int a);
};
typedef float (Unk8009EA04_Obj::*Unk8009EA04_Pmf)(int);
extern Unk8009EA04_Pmf lbl_805B6DA0[];

extern "C" float fn_8009EA04(Unk8009EA04_Obj* o, int i, int a)
{
    return (o->*lbl_805B6DA0[i])(a);
}

extern "C" float fn_8009F6CC(void* o, int a);
extern "C" float fn_8009F870(void* o, int a);
extern "C" float fn_8009F98C(void* o, int a);
extern "C" float fn_8009FAA8(void* o, int a);

extern int lbl_8061930C;
struct NameSrc8009F870 {
    char pad[0x20];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual const char* v6(int a, int b, char* buf);
};
extern "C" unsigned fn_8007F198__FP13Unk8007F198_A(int g, int id);
extern "C" int fn_8007F24C__FP13Unk8007F198_Aii(int g, int id, int i);
extern "C" float fn_8007A3FC__18Unk8007A4DC_Screenii(int g, int a, int b);

extern "C" float fn_8007A48C__18Unk8007A4DC_Screeniii(int g, int a, int b, int c);

extern "C" unsigned strlen(const char* s);
extern "C" char* strncpy(char* d, const char* s, unsigned n);
extern int lbl_805B6DC8[];

extern "C" void fn_8009F574(Unk8009E93C* p, int kind, unsigned idx, const char* s, int len)
{
    if (idx < p->m1C) {
        if (len <= 0)
            len = strlen(s);
        int cap = lbl_805B6DC8[kind];
        if (len > cap)
            len = cap - 1;
        switch ((unsigned)kind) {
        case 0: {
            int t = idx * 0x3C;
            strncpy(p->m24 + t + 0x10, s, len);
            char* q = (char*)(t + (int)p->m24 + 0x10);
            q[len] = 0;
            break;
        }
        case 1: {
            int t = idx * 0x3C;
            strncpy(p->m24 + t + 0x14, s, len);
            char* q = (char*)(t + (int)p->m24 + 0x14);
            q[len] = 0;
            break;
        }
        case 2: {
            int t = idx * 0x3C;
            strncpy(p->m24 + t + 0x28, s, len);
            char* q = (char*)(t + (int)p->m24 + 0x28);
            q[len] = 0;
            break;
        }
        case 3: {
            int t = idx * 0x3C;
            strncpy(p->m24 + t + 0x2C, s, len);
            char* q = (char*)(t + (int)p->m24 + 0x2C);
            q[len] = 0;
            break;
        }
        }
    }
}

extern "C" float fn_8009F6CC(void* o, int x)
{
    NameSrc8009F870* s = (NameSrc8009F870*)o;
    char buf[24];
    unsigned i = 0;
    int g = lbl_8061930C;
    int id = fn_800736EC(s->v6(0, x, buf));
    float t = 0.0f;
    unsigned lim;
    unsigned n = lim = fn_8007F198__FP13Unk8007F198_A(g, id);
    for (; i < lim; ) {
        int k = fn_8007F24C__FP13Unk8007F198_Aii(g, id, (unsigned char)i);
        i++;
        float a = (fn_8007A48C__18Unk8007A4DC_Screeniii(g, 0, k, 0) + fn_8007A48C__18Unk8007A4DC_Screeniii(g, 0, k, 1)) * 0.5f;
        float b = (fn_8007A48C__18Unk8007A4DC_Screeniii(g, 1, k, 0) + fn_8007A48C__18Unk8007A4DC_Screeniii(g, 1, k, 1)) * 0.5f;
        t += b * 0.5f + a;
    }
    t /= (float)n;
    return !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
}

extern "C" float fn_8009F870(void* o, int x)
{
    NameSrc8009F870* s = (NameSrc8009F870*)o;
    char buf[24];
    unsigned i = 0;
    int g = lbl_8061930C;
    int id = fn_800736EC(s->v6(0, x, buf));
    float t = 0.0f;
    unsigned lim;
    unsigned n = lim = fn_8007F198__FP13Unk8007F198_A(g, id);
    for (; i < lim; ) {
        int k = fn_8007F24C__FP13Unk8007F198_Aii(g, id, (unsigned char)i);
        i++;
        t += fn_8007A3FC__18Unk8007A4DC_Screenii(g, 0x10, k);
    }
    t /= (float)n;
    return !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
}

extern "C" float fn_8009F98C(void* o, int x)
{
    NameSrc8009F870* s = (NameSrc8009F870*)o;
    char buf[24];
    unsigned i = 0;
    int g = lbl_8061930C;
    int id = fn_800736EC(s->v6(0, x, buf));
    float t = 0.0f;
    unsigned lim;
    unsigned n = lim = fn_8007F198__FP13Unk8007F198_A(g, id);
    for (; i < lim; ) {
        int k = fn_8007F24C__FP13Unk8007F198_Aii(g, id, (unsigned char)i);
        i++;
        t += fn_8007A3FC__18Unk8007A4DC_Screenii(g, 0x10, k);
    }
    t /= (float)n;
    return !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
}

extern "C" float fn_8009FAA8(void* o, int x)
{
    NameSrc8009F870* s = (NameSrc8009F870*)o;
    char buf[24];
    unsigned i = 0;
    int g = lbl_8061930C;
    int id = fn_800736EC(s->v6(0, x, buf));
    float t = 0.0f;
    unsigned lim;
    unsigned n = lim = fn_8007F198__FP13Unk8007F198_A(g, id);
    for (; i < lim; ) {
        int k = fn_8007F24C__FP13Unk8007F198_Aii(g, id, (unsigned char)i);
        i++;
        t += fn_8007A3FC__18Unk8007A4DC_Screenii(g, 0x15, k);
    }
    t /= (float)n;
    return !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
}

extern "C" float fn_8009FBC4(void* o, int a)
{
    float r = (fn_8009F6CC(o, a) + fn_8009F870(o, a) + fn_8009F98C(o, a) + fn_8009FAA8(o, a)) * 0.25f;
    return r;
}
