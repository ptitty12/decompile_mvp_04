/*
 * Game code, .text 0x80362FB4-0x80365C10 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

struct Unk80626DD0_T {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int a);
};
extern Unk80626DD0_T* lbl_80626DD0;
extern char lbl_80686110[];
extern char lbl_80685EE8[];
struct Unk80363ECC {
    const void* m0;
    char pad4[0x10];
    int m14;
    int m18;
    int m1C;
};
struct Unk806AA8E0 {
    float m0, m4, m8, mC;
    float m10;
    float m14;
    float m18;
};
extern Unk806AA8E0 lbl_806AA8E0;

inline void Lerp3(float* a, float* b, float t)
{
    a[0] = t * (a[0] - b[0]) + b[0];
    a[1] = t * (a[1] - b[1]) + b[1];
    a[2] = t * (a[2] - b[2]) + b[2];
}

struct Unk80363CEC {
    char pad0[4];
    unsigned short m4;
    unsigned char m6;
    unsigned char m7;
    char pad8[8];
    unsigned char m10;
};
struct Unk80364310 {
    char pad0[0x10];
    float m10;
    float m14;
    float m18;
};
struct Unk8036344C_T {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(float b, float c, int a);
};
struct Unk8036344C {
    char pad0[0xC];
    Unk8036344C_T** mC;
    int m10;
};

struct DtorAt0 { const void* m; };
extern "C" void fn_803BE90C(void* s, int a);
extern char lbl_806855D0[];
void fn_80363BE4(void* p, int n);
extern float lbl_80609E1C;
struct Unk80363008 {
    char pad0[0xC];
    int mC;
    int m10;
    float m14;
};
extern "C" int fn_803CF3C0(int a, int* b, float* c, int d, int e);
struct Unk80363060 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a, int b);
};
extern char lbl_80685518[];
void fn_80363C10(void* p, int n);
extern float lbl_80609E20;
extern "C" int fn_803CF77C(int a, int* b, float* c, int d, int e);
extern char lbl_80685460[];
void fn_80363C3C(void* p, int n);
struct Unk803633D4_I {
    char pad0[6];
    unsigned short m6;
};
struct Unk803633D4 {
    char pad0[0xC];
    Unk803633D4_I* mC;
};
extern char lbl_80685268[];
void fn_80363C68(void* p, int n);
void fn_80363C94(void* p, int n);
struct Unk8036351C_T {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a);
    virtual void v5();
    virtual void v6();
    virtual int v7(int a, int b);
};
extern "C" void fn_803BA9DC(int a, int b, int c, int d, int e);
struct Unk8036351C {
    char pad0[0xC];
    Unk8036351C_T* mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};
void fn_80363CC0(void* p, int n);
extern void (*lbl_8062C66C)(void*, int);
struct Unk80364A20 {
    int m0, m4, m8, mC, m10;
    Unk80364A20(int a, int b, int c, int d, int e);
};
struct Unk80364A3C {
    int m0, m4;
    Unk80364A3C(int a, int n);
};

struct Unk803639F4_T {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(float a, float b);
    virtual void v5();
    virtual void v6();
    virtual void v7(float t);
    virtual void v8(float t);
    virtual void v9();
    virtual void v10(float a, float b);
};
struct Unk803639F4 {
    char pad0[0xC];
    float mC;
    float m10;
    float m14;
    Unk803639F4_T* m18;
};
/* Wraps a time into [mC, m10] by the period m14, as an argument so the virtual
 * call target is computed before the branches (retail does that). near-miss
 * (98.3% in fn_803639F4, fn_80363AEC, fn_80363694, fn_80363844): only the
 * integer registers of the (float)(int) conversion temporaries differ
 * (retail: 0x4330 constant in r8, converted word in r0, call target in r6/r7;
 * ours: r0, r11, r7/r8). The float side matches, including which loads are
 * shared between the two wraps. Tried: in-place t, separate d, named int n,
 * operand order, direct member use (all the same score). */
inline float Unk803639F4_Wrap(Unk803639F4* s, float t)
{
    float lo = s->mC;
    if (t < lo) {
        float r = s->m14;
        t -= lo;
        t = s->m10 - (t - (float)(int)(t / r) * r);
    } else if (t > s->m10) {
        float r = s->m14;
        t -= s->m10;
        t = lo + (t - (float)(int)(t / r) * r);
    }
    return t;
}
struct Unk803646DC_Q {
    float m0, m4, m8, mC;
};
extern "C" float sqrtf(float x);
inline float Unk803646DC_Zero()
{
    return 0.0f;
}
void fn_80362FB4(DtorAt0* s, int chrg)
{
    s->m = lbl_806855D0;
    fn_803BE90C(s, 0);
    if (chrg & 1)
        fn_80363BE4(s, 0x18);
}

void fn_80363008(Unk80363008* s, int a)
{
    s->mC = a;
    s->m10 = 0;
    s->m14 = lbl_80609E1C;
}

int fn_80363024(Unk80363008* s, int a, int b)
{
    fn_803CF3C0(s->mC, &s->m10, &s->m14, a, b);
    return 1;
}

void fn_80363060(Unk80363060* s, int a)
{
    s->v10(a, 0);
}

void fn_80363098(DtorAt0* s, int chrg)
{
    s->m = lbl_80685518;
    fn_803BE90C(s, 0);
    if (chrg & 1)
        fn_80363C10(s, 0x18);
}

void fn_803630EC(Unk80363008* s, int a)
{
    s->mC = a;
    s->m10 = 0;
    s->m14 = lbl_80609E20;
}

int fn_80363108(Unk80363008* s, int a, int b)
{
    fn_803CF77C(s->mC, &s->m10, &s->m14, a, b);
    return 1;
}

void fn_80363144(Unk80363060* s, int a)
{
    s->v10(a, 0);
}

void fn_8036317C(DtorAt0* s, int chrg)
{
    s->m = lbl_80685460;
    fn_803BE90C(s, 0);
    if (chrg & 1)
        fn_80363C3C(s, 0x14);
}

int fn_803633D4(Unk803633D4* s, float* out)
{
    int v = s->mC->m6;
    *out = (float)v;
    return 1;
}

void fn_80363414(DtorAt0* s, int chrg)
{
    s->m = lbl_80685268;
    if (chrg & 1)
        fn_80363C68(s, 0x14);
}

void fn_8036344C(Unk8036344C* s, float b, float c, int a)
{
    for (int i = 0; i < s->m10; i++)
        s->mC[i]->v4(b, c, a);
}

void fn_803634E4(DtorAt0* s, int chrg)
{
    s->m = lbl_80685268;
    if (chrg & 1)
        fn_80363C94(s, 0x20);
}

void fn_8036351C(Unk8036351C* s, int a)
{
    if (s->m1C != 0) {
        s->mC->v4(s->m14);
        fn_803BA9DC(s->m10, s->m14, a, s->m18, 0);
    } else {
        s->mC->v4(a);
    }
}

int fn_803635B0(Unk8036351C* s, int a, int b)
{
    int r;
    if (s->m1C != 0) {
        r = s->mC->v7(s->m14, b);
        if (r != 0)
            fn_803BA9DC(s->m10, s->m14, a, s->m18, b);
    } else {
        r = s->mC->v7(a, b);
    }
    return r;
}

void fn_8036365C(DtorAt0* s, int chrg)
{
    s->m = lbl_80685268;
    if (chrg & 1)
        fn_80363CC0(s, 0x1c);
}

void fn_80363694(Unk803639F4* s, float a, float b)
{
    s->m18->v4(Unk803639F4_Wrap(s, a), Unk803639F4_Wrap(s, b));
}

void fn_80363844(Unk803639F4* s, float a, float b)
{
    s->m18->v10(Unk803639F4_Wrap(s, a), Unk803639F4_Wrap(s, b));
}

void fn_803639F4(Unk803639F4* s, float t)
{
    s->m18->v7(Unk803639F4_Wrap(s, t));
}

void fn_80363AEC(Unk803639F4* s, float t)
{
    s->m18->v8(Unk803639F4_Wrap(s, t));
}

void fn_80363BE4(void* p, int n)
{
    lbl_8062C66C(p, n);
}

void fn_80363C10(void* p, int n)
{
    lbl_8062C66C(p, n);
}

void fn_80363C3C(void* p, int n)
{
    lbl_8062C66C(p, n);
}

void fn_80363C68(void* p, int n)
{
    lbl_8062C66C(p, n);
}

void fn_80363C94(void* p, int n)
{
    lbl_8062C66C(p, n);
}

void fn_80363CC0(void* p, int n)
{
    lbl_8062C66C(p, n);
}

char* fn_80363CEC(Unk80363CEC* s)
{
    char* b = (char*)s + 0x12;
    unsigned n = 1 << s->m10;
    unsigned c = s->m6;
    unsigned q = s->m4 / n;
    int r = s->m4 - q * n;
    b += c * 16;
    char* p = b + ((c * ((n - 1) * 3 + 6) + 1) & ~1) * q;
    if (r > 0)
        p += c * ((r - 1) * 3 + 6);
    return p;
}

char* fn_80363D5C(Unk80363CEC* s)
{
    char* b = (char*)s + 0x12;
    unsigned n = 1 << s->m10;
    unsigned c = s->m6;
    unsigned q = s->m4 / n;
    int r = s->m4 - q * n;
    b += c * 16;
    char* p = b + ((c * ((n - 1) * 3 + 6) + 1) & ~1) * q;
    if (r > 0)
        p += c * ((r - 1) * 3 + 6);
    return (char*)((int)(p + s->m7 + 1) & ~1);
}

char* fn_80363DDC(Unk80363CEC* s)
{
    char* b = (char*)s + 0x12;
    unsigned n = 1 << s->m10;
    unsigned c = s->m6;
    unsigned q = s->m4 / n;
    int r = s->m4 - q * n;
    b += c * 12;
    char* p = b + ((c * ((n - 1) * 3 + 6) + 1) & ~1) * q;
    if (r > 0)
        p += c * ((r - 1) * 3 + 6);
    return p;
}

char* fn_80363E4C(Unk80363CEC* s)
{
    char* b = (char*)s + 0x12;
    unsigned n = 1 << s->m10;
    unsigned c = s->m6;
    unsigned q = s->m4 / n;
    int r = s->m4 - q * n;
    b += c * 12;
    char* p = b + ((c * ((n - 1) * 3 + 6) + 1) & ~1) * q;
    if (r > 0)
        p += c * ((r - 1) * 3 + 6);
    return (char*)((int)(p + s->m7 + 1) & ~1);
}

extern "C" void fn_80363ECC(Unk80363ECC* s, int chrg)
{
    s->m0 = lbl_80686110;
    if (s->m14 != 0)
        lbl_80626DD0->v7(s->m14);
    if (s->m1C != 0)
        lbl_80626DD0->v7(s->m1C);
    fn_803BE90C(s, 0);
    if (chrg & 1)
        lbl_8062C66C(s, 0x24);
}

extern "C" void fn_80363F8C(Unk80363ECC* s, int chrg)
{
    s->m0 = lbl_80686110;
    if (s->m14 != 0)
        lbl_80626DD0->v7(s->m14);
    if (s->m1C != 0)
        lbl_80626DD0->v7(s->m1C);
    fn_803BE90C(s, 0);
    if (chrg & 1)
        lbl_8062C66C(s, 0x24);
}

extern "C" void fn_8036404C(Unk80363ECC* s, int chrg)
{
    s->m0 = lbl_80685EE8;
    if (s->m14 != 0)
        lbl_80626DD0->v7(s->m14);
    if (s->m1C != 0)
        lbl_80626DD0->v7(s->m1C);
    fn_803BE90C(s, 0);
    if (chrg & 1)
        lbl_8062C66C(s, 0x24);
}

extern "C" void fn_8036410C(Unk80363ECC* s, int chrg)
{
    s->m0 = lbl_80685EE8;
    if (s->m14 != 0)
        lbl_80626DD0->v7(s->m14);
    if (s->m1C != 0)
        lbl_80626DD0->v7(s->m1C);
    fn_803BE90C(s, 0);
    if (chrg & 1)
        lbl_8062C66C(s, 0x24);
}

void fn_80364310(float** pp, float* out)
{
    out[0] = *(*pp)++;
    out[1] = *(*pp)++;
    out[2] = *(*pp)++;
    out[3] = *(*pp)++;
}

void fn_80364358(float** pp, Unk80364310* o)
{
    o->m10 = *(*pp)++;
    o->m14 = *(*pp)++;
    o->m18 = *(*pp)++;
}

extern "C" void fn_803646DC(float** p0, float** p1, Unk803646DC_Q* q, float t)
{
    lbl_806AA8E0.m0 = *(*p0)++;
    lbl_806AA8E0.m4 = *(*p0)++;
    lbl_806AA8E0.m8 = *(*p0)++;
    lbl_806AA8E0.mC = *(*p0)++;
    q->m0 = *(*p1)++;
    q->m4 = *(*p1)++;
    q->m8 = *(*p1)++;
    q->mC = *(*p1)++;
    float a = q->m0, b = q->m4, c = q->m8, d = q->mC;
    if (lbl_806AA8E0.mC * d + (lbl_806AA8E0.m8 * c + (lbl_806AA8E0.m0 * a + lbl_806AA8E0.m4 * b)) > Unk803646DC_Zero()) {
        q->m0 = t * (a - lbl_806AA8E0.m0) + lbl_806AA8E0.m0;
        q->m4 = t * (b - lbl_806AA8E0.m4) + lbl_806AA8E0.m4;
        q->m8 = t * (c - lbl_806AA8E0.m8) + lbl_806AA8E0.m8;
        q->mC = t * (d - lbl_806AA8E0.mC) + lbl_806AA8E0.mC;
    } else {
        q->m0 = lbl_806AA8E0.m0 - t * (a + lbl_806AA8E0.m0);
        q->m4 = lbl_806AA8E0.m4 - t * (b + lbl_806AA8E0.m4);
        q->m8 = lbl_806AA8E0.m8 - t * (c + lbl_806AA8E0.m8);
        q->mC = lbl_806AA8E0.mC - t * (d + lbl_806AA8E0.mC);
    }
    float s = 1.0f / sqrtf(q->mC * q->mC + (q->m8 * q->m8 + (q->m0 * q->m0 + q->m4 * q->m4)));
    q->m0 *= s;
    q->m4 *= s;
    q->m8 *= s;
    q->mC *= s;
}

extern "C" void fn_803648C0(float** p0, float** p1, Unk80364310* o, float t)
{
    lbl_806AA8E0.m10 = *(*p0)++;
    lbl_806AA8E0.m14 = *(*p0)++;
    lbl_806AA8E0.m18 = *(*p0)++;
    o->m10 = *(*p1)++;
    o->m14 = *(*p1)++;
    o->m18 = *(*p1)++;
    Lerp3(&o->m10, &lbl_806AA8E0.m10, t);
}

void fn_80364978(void* s, int chrg)
{
    fn_803BE90C(s, 0);
    if (chrg & 1)
        lbl_8062C66C(s, 0x1c);
}

void fn_803649CC(void* s, int chrg)
{
    fn_803BE90C(s, 0);
    if (chrg & 1)
        lbl_8062C66C(s, 0x14);
}

Unk80364A20::Unk80364A20(int a, int b, int c, int d, int e)
{
    m0 = a;
    m4 = b;
    m8 = c;
    mC = d;
    m10 = e;
}

Unk80364A3C::Unk80364A3C(int a, int n)
{
    m0 = a;
    m4 = n * 0x60;
}

void fn_80364A50(void* p, int n)
{
    lbl_8062C66C(p, n);
}

int fn_80364A7C(void* s, int a, int b)
{
    int r = a;
    if (r < b)
        r = b;
    return r;
}

char* fn_80364A90(void* s, char* p)
{
    while (p != 0 && *p != 0 && (*p == ';' || *p == ',' || *p == '='))
        p++;
    return p;
}

int fn_80364AF4(void* s, char* p, char** out)
{
    while (p != 0 && *p != 0 && *p != ';' && *p != ',' && *p != '=')
        p++;
    *out = p;
    if (p != 0) {
        char c = *p;
        *p = 0;
        return c;
    }
    return 0;
}
