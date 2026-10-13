/*
 * Game code, .text 0x80344180-0x80344E90 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

extern char lbl_80649E88[];
extern char lbl_80649C48[];
extern char lbl_80649DB8[];
extern char lbl_80649DA0[];
extern char lbl_80649E50[];
extern char lbl_80649E18[];
extern char lbl_80649DE0[];
extern "C" void fn_80377408(void* p);
extern "C" void fn_80378620(void* p, int chrg);
unsigned int fn_80378568(const char* token, int len);
extern "C" char* strcpy(char* dst, const char* src);

struct Rng { unsigned short lo; unsigned short hi; };
struct K { char pad0[8]; Rng* m8; int pad; int* m10; };

int fn_80344180(K* t, int idx, int v)
{
    int found = 0;
    if ((unsigned)t->m8[idx].lo < (unsigned)t->m8[idx].hi) {
        for (int j = t->m8[idx].lo; j < t->m8[idx].hi; j++) {
            if (t->m10[j] == v) {
                found = 1;
                break;
            }
        }
    }
    return found;
}

int fn_803441E0(K* t, int idx, int v)
{
    int found = 0;
    if ((unsigned)t->m8[idx].lo < (unsigned)t->m8[idx].hi) {
        for (int j = t->m8[idx].lo; j < t->m8[idx].hi; j++) {
            if (t->m10[j] == v) {
                found = 1;
                break;
            }
        }
    }
    return found;
}

struct Unk80344240 {
    int m0;
    unsigned char m4;
};

void fn_80344240(Unk80344240* self, int a)
{
    if (a == 2)
        self->m4 = 0;
}

void fn_80344254(Unk80344240* self) { self->m4++; }

void fn_80344264(Unk80344240* self, int a)
{
    if (a == 1)
        self->m4 = 0;
}

void fn_80344278(Unk80344240* self) { self->m4++; }

void fn_80344288(Unk80344240* self, int a)
{
    if (a == 0)
        self->m4 = 0;
}

void fn_80344298(Unk80344240* self) { self->m4++; }

void fn_803442A8(Unk80344240* self, int a)
{
    if (a == 3)
        self->m4 = 0;
}

void fn_803442BC(Unk80344240* self) { self->m4++; }

struct Unk803442CC {
    const void* m0;
};

void fn_803442CC(Unk803442CC* self, int chrg)
{
    self->m0 = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80344300(Unk803442CC* self, int chrg)
{
    self->m0 = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80344334(Unk803442CC* self, int chrg)
{
    self->m0 = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80344368(Unk803442CC* self, int chrg)
{
    self->m0 = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk8034439C {
    char pad0[8];
    const void* m8;
};

void fn_8034439C(Unk8034439C* self, int chrg)
{
    self->m8 = lbl_80649DB8;
    fn_80378620(self, chrg);
}

void fn_803443CC() {}

struct Unk803443D0_VT {
    char pad0[8];
    virtual void s0();
    virtual void s1();
    virtual int s2();
};

int fn_803443D0(Unk803443D0_VT* self)
{
    return self->s2();
}

void fn_80344404() {}

extern float lbl_805AE3D4;
extern float lbl_805AE3D8;
extern float lbl_805AE3DC;

struct Unk80344408 {
    char pad0[0x10];
    unsigned int m10;
    int m14;
    virtual void s0();
    virtual const char* s1();
};

unsigned int fn_80344408(Unk80344408* self)
{
    if (self->m14 == 0) {
        self->m10 = fn_80378568(self->s1(), 0);
        self->m14 = 1;
    }
    return self->m10;
}

void fn_8034446C(char* self, const char* s)
{
    *(int*)(self + 0x14) = 0;
    strcpy(self, s);
}

void fn_80344494(char* self, int v)
{
    *(int*)(self + 0x1E20) = v;
}

struct Unk8034449C {
    int m0;
    const void* m4;
};

void fn_8034449C(Unk8034449C* self, int chrg)
{
    self->m4 = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_803444D0(Unk8034449C* self, int chrg)
{
    self->m4 = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80344504(Unk8034449C* self, int chrg)
{
    self->m4 = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80344538 {
    int m0;
    float m4;
    float m8;
    float mC;
    float m10;
    int m14;
    int m18;
    int m1C;
    float m20;
    float m24;
    int m28;
};

void fn_80344538(Unk80344538* self)
{
    self->m28 = 1;
    self->m20 = lbl_805AE3D4;
    self->m8 = lbl_805AE3D4;
    self->m10 = lbl_805AE3D4;
    self->mC = lbl_805AE3D4;
    self->m14 = 2;
    self->m0 = 0;
    self->m1C = -1;
    self->m4 = lbl_805AE3D4;
    self->m24 = lbl_805AE3D8;
}

struct Unk80344584 {
    float m0;
    int m4;
    int m8;
};

void fn_80344584(Unk80344584* self, int a)
{
    self->m0 = lbl_805AE3DC;
    self->m4 = 0x1D8;
    self->m8 = a;
}

int fn_803445A0(int* self)
{
    return self[1];
}

Unk803442CC* fn_803445A8(Unk803442CC* self)
{
    self->m0 = lbl_80649C48;
    return self;
}

void fn_803445BC(Unk803442CC* self, int chrg)
{
    self->m0 = lbl_80649C48;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_803445F0(Unk8034449C* self, int chrg)
{
    self->m4 = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80344624 {
    int m0;
    int m4;
    int m8;
};

void fn_80344624(Unk80344624* self)
{
    self->m0 = 0;
    self->m4 = 0x1D8;
    self->m8 = 0x4C;
}

Unk803442CC* fn_80344640(Unk803442CC* self)
{
    self->m0 = lbl_80649E88;
    return self;
}

struct Unk80344654_VT {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(int a);
};
struct Unk80344654_Arg {
    int m0;
    int m4;
};

void fn_80344654(Unk80344654_VT* self, Unk80344654_Arg* arg)
{
    self->s3(arg->m4);
}

struct Unk8034468C {
    const void* m0;
    char pad4[0x9A - 4];
    unsigned char m9A;
    char pad9B[0xFE - 0x9B];
    unsigned char mFE;
};

Unk8034468C* fn_8034468C(Unk8034468C* self)
{
    fn_80344640((Unk803442CC*)self);
    self->m0 = lbl_80649E50;
    return self;
}

Unk8034468C* fn_803446C8(Unk8034468C* self)
{
    fn_80344640((Unk803442CC*)self);
    self->m9A = 0;
    self->m0 = lbl_80649E18;
    return self;
}

Unk8034468C* fn_8034470C(Unk8034468C* self)
{
    fn_80344640((Unk803442CC*)self);
    self->mFE = 0;
    self->m0 = lbl_80649DE0;
    return self;
}


extern char lbl_80686E0C[];
extern char lbl_80686DF4[];
extern char lbl_80686DE4[];
extern char lbl_80686E14[];
extern char lbl_80686E4C[];
extern char lbl_80686DEC[];
extern char lbl_80686E04[];

Unk803B9D60_Rec* fn_80344750(Unk803B9D60_In4* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x14, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8, w = s->mC;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0xc8) v = 0xc8;
    r->mC = v;
    int q = w;
    if (q < 0) q = 0; else if (q > 0x2) q = 0x2;
    r->m10 = q;
    fn_803BA240(lbl_80686E0C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80344878(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    r->mC = v;
    fn_803BA240(lbl_80686DF4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034497C(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    r->mC = v;
    fn_803BA240(lbl_80686DE4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80344A80(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x96) v = 0x96;
    r->mC = v;
    fn_803BA240(lbl_80686E14, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80344B84(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0xc8) v = 0xc8;
    r->mC = v;
    fn_803BA240(lbl_80686E4C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80344C88(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    r->mC = v;
    fn_803BA240(lbl_80686DEC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80344D8C(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x2710) t = 0x2710;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    r->mC = v;
    fn_803BA240(lbl_80686E04, &r->m4, r);
    return r;
}

