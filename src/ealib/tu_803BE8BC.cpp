/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803BE8BC-0x803C1DD0 (code-only unit, 43 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */


/* EAGLAnim resource base classes (vtable slot N is at byte offset 8*N). */
struct EAGLHeap {
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
    virtual void v13(void*);
};

struct EAGLSelfA {
    void* m0;
    int m4;
    int m8;
    int mC;
};

struct EAGLInfo {
    unsigned short m0;
    unsigned short m2;
    unsigned short m4;
    unsigned short m6;
    unsigned short* m8;
};

struct EAGLSelfB {
    char pad0[0xC];
    EAGLInfo* mC;
};

struct EAGLInfoB {
    int pad0;
    int m4;
};

struct EAGLSelfF {
    char pad0[0xC];
    EAGLInfoB* mC;
};

struct EAGLSelfD {
    char pad0[8];
    unsigned short m8;
    unsigned short padA;
    int mC[1];
};

struct EAGLSelfE {
    void* m0;
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

struct EAGLSelfV7 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int, float, int);
};

extern EAGLHeap* lbl_80626DD0;
extern char lbl_80685860[];
extern char lbl_806859D0[];

extern "C" int fn_803BE8BC() { return 0; }

extern "C" int fn_803BE8C4() { return 0; }

extern "C" int fn_803BE8CC() { return 0; }

extern "C" int fn_803BE8D4() { return 0; }

extern "C" int fn_803BE8DC() { return 0; }

extern "C" int fn_803BE8E4() { return 0; }

extern "C" EAGLSelfA* fn_803BE8EC(EAGLSelfA* s)
{
    s->m0 = lbl_80685860;
    s->m4 = 0;
    s->mC = 0;
    return s;
}

struct DtorAt0 { const void* m; };

extern char lbl_80685268[];

extern "C" void fn_80377408(void* p);

extern "C" void fn_803BE90C(DtorAt0* self, int chrg)
{
    self->m = lbl_80685268;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" void fn_803BE940(EAGLSelfA* s, int v)
{
    s->mC = v;
}

extern "C" int fn_803BE948(EAGLSelfA* s)
{
    return s->mC;
}

extern "C" int fn_803BE950(EAGLSelfA* s)
{
    return s->mC;
}

extern "C" int fn_803BE958(EAGLSelfB* s)
{
    return s->mC->m2;
}

extern "C" int fn_803BF490(EAGLSelfB* s)
{
    return s->mC->m2;
}

extern "C" int fn_803BF688(EAGLSelfF* s)
{
    return s->mC->m4;
}

extern "C" void fn_803BF9F0(EAGLSelfD* s)
{
    int i;
    for (i = s->m8 - 1; i >= 0; i--)
        lbl_80626DD0->v13((void*)s->mC[i]);
}

/* near-miss: constants land in swapped registers (-1 in r10, 18 in r11; retail r11/r10) */
extern "C" EAGLSelfE* fn_803C1B50(EAGLSelfE* s)
{
    fn_803BE8EC((EAGLSelfA*)s);
    s->m0 = lbl_806859D0;
    s->m28 = -1;
    s->m3C = 0;
    s->m8 = 0x12;
    s->m10 = 0;
    s->m14 = 0;
    s->m18 = -1;
    s->m1C = -1;
    s->m20 = 0;
    s->m24 = 0;
    s->m2C = 0;
    s->m30 = 0;
    s->m34 = 0;
    s->m38 = 0;
    return s;
}

extern "C" int fn_803C1C60(EAGLSelfB* s, float* out)
{
    EAGLInfo* p = s->mC;
    int v;
    if (p->m8 == 0)
        v = p->m4;
    else
        v = p->m8[p->m4 - 2] + 1;
    *out = (float)v;
    return 1;
}

extern "C" void fn_803C1CC4(EAGLSelfV7* s, int a, float x, float y)
{
    s->v7(a, y, 0);
}
