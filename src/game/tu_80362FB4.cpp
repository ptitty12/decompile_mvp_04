/*
 * Game code, .text 0x80362FB4-0x80365C10 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

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
