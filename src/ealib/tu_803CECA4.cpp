/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803CECA4-0x803D2B20 (code-only unit, 44 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* Data record at +0xC of the objects. Evidence: fn_803CECA4 (mC), fn_803CFC00 (m4), fn_803CFC3C (m6, m8 flags). */
struct Unk803CECA4Rec {
    int m0;
    unsigned short m4;
    unsigned short m6;
    unsigned char m8;
    char pad9[3];
    int mC;
};

/* Object: vptr at +0, record pointer at +0xC. Evidence: fn_803CFC3C (m10, m12, m14, m18 stores). */
struct Unk803CECA4Obj {
    const void* m0;
    int m4;
    int m8;
    Unk803CECA4Rec* mC;
    int m10;
};

/* Second view of the object (fn_803CFC3C). */
struct Unk803CECA4Obj3 {
    const void* m0;
    int m4;
    int m8;
    Unk803CECA4Rec* mC;
    short m10;
    unsigned short m12;
    int m14;
    unsigned char m18;
};

/* Stack object built and torn down by fn_803CF2EC / fn_803CF37C (ctor fn_803D3754 / fn_803D4818, dtor fn_803D37A0 / fn_803D485C). */
struct Unk803CECA4Tmp {
    const void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

class Unk803CECA4Vt {
public:
    virtual ~Unk803CECA4Vt();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int a, float f, int z);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(void* p);
};

class Unk80626DD0 {
public:
    virtual ~Unk80626DD0();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void* p);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(void* p);
};

struct Unk803D1730Obj {
    const void* m0;
    int m4;
    int m8;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    void* m1C;
    void* m20;
    void* m24;
    float m28;
    void* m2C;
    int m30;
    char pad34[0x14];
    float m48;
    float m4C;
    float m50;
    int m54;
    char pad58[0x10];
    void* m68;
    char pad6C[0x10];
    void* m7C;
};

struct Unk803D1A30Rec {
    char pad0[4];
    unsigned short m4;
};

struct Unk803D1A30Obj {
    char pad0[0x10];
    Unk803D1A30Rec** m10;
    char pad14[0x1C];
    int m30;
};

/* Object built by fn_803D2A14 / fn_803D1730 (vtables lbl_80686478 / lbl_806863D8). */
struct Unk803D2A14Obj {
    const void* m0;
    int m4;
    int m8;
    void* mC;
    void* m10;
    void* m14;
    float m18;
    void* m1C;
    int m20;
    char pad24[0x14];
    float m38;
    float m3C;
    float m40;
    int m44;
    char pad48[0x10];
    void* m58;
};

extern const void* lbl_80686478[];
extern const void* lbl_806863D8[];
extern const void* lbl_80685268[];
extern Unk80626DD0* lbl_80626DD0;
extern void (*lbl_8062C66C)(void* p, int size);

extern "C" {
void fn_803D14E8(Unk803D1A30Obj* self, float* out, int a, int b, float x, float y);
}

extern "C" {
Unk803CECA4Tmp* fn_803D3754(Unk803CECA4Tmp* p);
void fn_803D37A0(Unk803CECA4Tmp* p, int c);
Unk803CECA4Tmp* fn_803D4818(Unk803CECA4Tmp* p);
void fn_803D485C(Unk803CECA4Tmp* p, int c);
void* fn_803BD8A8(int a);
void fn_803BD844(void* p);
void fn_803CEECC(Unk803CECA4Rec* rec, int a, int b, int c, float t);
}

extern "C" int fn_803CECA4(Unk803CECA4Obj* self, float* out)
{
    *out = (float)self->mC->mC;
    return 1;
}

extern "C" void fn_803CECE4(Unk803CECA4Obj* self, int a, float x, float y)
{
    fn_803CEECC((Unk803CECA4Rec*)self->mC, a, self->m10, 0, y);
}

extern "C" int fn_803CED14(Unk803CECA4Obj* self, int a, int b, float t)
{
    fn_803CEECC((Unk803CECA4Rec*)self->mC, a, self->m10, b, t);
    return 1;
}

extern "C" void fn_803CF2EC(char* self)
{
    Unk803CECA4Tmp o;
    fn_803D3754(&o);
    *(const void**)(self - 0x18) = o.m0;
    fn_803D37A0(&o, 2);
    char* p = *(char**)(self + 0x10);
    if (p) {
        char* base = p - 0x18;
        fn_803D4818(&o);
        *(const void**)(p - 0x18) = o.m0;
        fn_803D485C(&o, 2);
        ((Unk803CECA4Vt*)base)->v19(p);
        *(char**)(self + 0x10) = base;
    }
}

extern "C" void fn_803CF37C(char* self)
{
    Unk803CECA4Tmp o;
    fn_803D4818(&o);
    *(const void**)(self - 0x18) = o.m0;
    fn_803D485C(&o, 2);
}

extern "C" int fn_803CFBF8(Unk803CECA4Obj* self)
{
    return (int)self->mC;
}

extern "C" int fn_803CFC00(Unk803CECA4Obj* self, float* out)
{
    *out = (float)self->mC->m4;
    return 1;
}

extern "C" void fn_803CFC3C(Unk803CECA4Obj3* self, Unk803CECA4Rec* r)
{
    self->mC = r;
    self->m10 = 0;
    self->m12 = r->m6;
    self->m14 = (r->m8 & 1) ^ 1;
    int f = r->m8;
    unsigned char v;
    if (f & 8) v = 1;
    else if (f & 0x10) v = 2;
    else if (f & 0x20) v = 4;
    else if (f & 0x40) v = 8;
    else v = 1;
    self->m18 = v;
}

extern "C" void fn_803CFCAC(Unk803D1730Obj* self, int c)
{
    self->m0 = lbl_806863D8;
    if (self->m18)
        lbl_80626DD0->v12(self->m18);
    if (self->m1C)
        lbl_80626DD0->v12(self->m1C);
    if (self->m20)
        lbl_80626DD0->v12(self->m20);
    if (self->m24)
        lbl_80626DD0->v12(self->m24);
    if (self->m2C) {
        fn_803BD844(fn_803BD8A8(0));
    }
    if (self->mC)
        lbl_80626DD0->v7(self->mC);
    if (self->m10)
        lbl_80626DD0->v7(self->m10);
    if (self->m14)
        lbl_80626DD0->v7(self->m14);
    if (self->m7C)
        lbl_80626DD0->v7(self->m7C);
    self->m0 = lbl_80685268;
    if (c & 1)
        lbl_8062C66C(self, 0x80);
}

extern "C" Unk803D1730Obj* fn_803D1730(Unk803D1730Obj* self)
{
    self->m0 = lbl_806863D8;
    self->m4 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 0;
    self->m28 = 0.0f;
    self->m2C = 0;
    self->m30 = -100;
    self->m48 = 1.0f;
    self->m4C = 0.0f;
    self->m50 = 0.0f;
    self->m54 = -100;
    self->m68 = 0;
    self->m7C = 0;
    self->m18 = 0;
    self->m1C = 0;
    self->m20 = 0;
    self->m24 = 0;
    self->m8 = 8;
    return self;
}

extern "C" void fn_803D17A8(Unk803CECA4Vt* self, int a, float x, float y)
{
    self->v7(a, y, 0);
}

extern "C" int fn_803D18F8()
{
    return 0;
}

extern "C" float fn_803D19FC(char* self)
{
    return *(float*)(self + 0x48);
}

extern "C" void fn_803D1A04(Unk803D1A30Obj* self, float* out)
{
    ((void (*)(Unk803D1A30Obj*, float*, float, float))fn_803D14E8)(self, out, 0.0f, 0.0f);
}

extern "C" Unk803D2A14Obj* fn_803D2A14(Unk803D2A14Obj* self)
{
    self->m0 = lbl_80686478;
    self->m4 = 0;
    self->mC = 0;
    self->m18 = 0.0f;
    self->m1C = 0;
    self->m20 = -100;
    self->m38 = 1.0f;
    self->m3C = 0.0f;
    self->m40 = 0.0f;
    self->m44 = -100;
    self->m58 = 0;
    self->m10 = 0;
    self->m14 = 0;
    self->m8 = 9;
    return self;
}

extern "C" void fn_803D2A78(Unk803D2A14Obj* self, int c)
{
    self->m0 = lbl_80686478;
    if (self->m1C) {
        fn_803BD844(fn_803BD8A8(1));
    }
    if (self->mC) {
        lbl_80626DD0->v7(self->mC);
    }
    self->m0 = lbl_80685268;
    if (c & 1)
        lbl_8062C66C(self, 0x5c);
}
