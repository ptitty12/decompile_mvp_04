/*
 * Game code, .text 0x803414A4-0x80341B78 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

extern char lbl_806648E8[];
struct Unk805A3AD8 { float v; };
extern Unk805A3AD8 lbl_805A3AD8;
/* Retail 0x802DC9CC is Unk802DC9F8's constructor; its subobject is 0x24 bytes. */
struct Unk802DC9F8 {
    char pad[0x24];
    Unk802DC9F8();
};
inline void* operator new(unsigned int, void* address) { return address; }
extern "C" void fn_80377488(void* p);
extern "C" void fn_80377408(void* p);

struct Unk803414A4_Ent {
    short m0;
    short m2;
    short m4;
    short m6;
    short m8;
    float mC;
    Unk803414A4_Ent()
    {
        m8 = -1;
        m0 = -1;
        m2 = -1;
        m4 = -1;
        m6 = -1;
        mC = lbl_805A3AD8.v;
    }
};

struct Unk803414A4 {
    Unk803414A4_Ent m0[0x10B];
    char pad10B0[0x1558 - 0x10B0];
    char m1558[0x24];
    const void* m157C;
};

Unk803414A4* fn_803414A4(Unk803414A4* self)
{
    self->m157C = lbl_806648E8;
    for (int i = 0; i < 0x10B; i++) {
        Unk803414A4_Ent* e = &self->m0[i];
        e->m0 = -1;
        e->m2 = -1;
        e->m4 = -1;
        e->m6 = -1;
        e->m8 = -1;
        e->mC = lbl_805A3AD8.v;
    }
    new (self->m1558) Unk802DC9F8;
    return self;
}

unsigned char fn_8034151C(Unk8034151C* t, int v)
{
    unsigned char i;
    for (i = 0; i < t->m9A; i++) {
        if (v == t->m4[i]) {
            return i;
        }
    }
    return t->m9A;
}

unsigned char fn_80341560(Unk8034151C* t, int v)
{
    t->m4[t->m9A] = v;
    t->m7C[t->m9A] = 0;
    return t->m9A++;
}

void fn_80341598(Unk8034151C* t, int v)
{
    unsigned char i = fn_8034151C(t, v);
    if (t->m9A == i)
        i = fn_80341560(t, v);
    t->m7C[i]++;
}

unsigned char fn_803415F0(Unk803415F0* t, int v)
{
    unsigned char i;
    for (i = 0; i < t->mFE; i++) {
        if (v == t->m4[i]) {
            return i;
        }
    }
    return t->mFE;
}

unsigned char fn_80341634(Unk803415F0* t, int v)
{
    t->m4[t->mFE] = v;
    t->mCC[t->mFE] = 0;
    return t->mFE++;
}

void fn_8034166C(Unk803415F0* t, int v)
{
    unsigned char i = fn_803415F0(t, v);
    if (t->mFE == i)
        i = fn_80341634(t, v);
    t->mCC[i]++;
}

struct Unk803416C4 {
    int m0;
    char m4;
};
void fn_803416C4(Unk803416C4* s) { s->m4 = 0; }
void fn_803416D0(Unk803416C4* s) { s->m4 = 0; }
void fn_803416DC(Unk803416C4* s) { s->m4 = 0; }
void fn_803416E8(Unk803416C4* s) { s->m4 = 0; }

struct Unk803416F4 {
    void* m0;
    void* m4;
    int m8;
};

Unk803416F4* fn_803416F4(Unk803416F4* self, int v)
{
    self->m8 = v;
    self->m0 = 0;
    self->m4 = 0;
    return self;
}

void fn_8034170C(Unk803416F4* self)
{
    if (self->m0 != 0) {
        fn_80377488(self->m0);
        self->m0 = 0;
    }
    if (self->m4 != 0) {
        fn_80377488(self->m4);
        self->m4 = 0;
    }
}

void fn_80341764(Unk803416F4* self, int chrg)
{
    if (self->m0 != 0)
        fn_8034170C(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk803417B0 {
    void* m0;
    void* m4;
    int m8;
};

Unk803417B0* fn_803417B0(Unk803417B0* self, int v)
{
    self->m8 = v;
    self->m0 = 0;
    self->m4 = 0;
    return self;
}

void fn_803417C8(Unk803417B0* self)
{
    if (self->m0 != 0) {
        fn_80377488(self->m0);
        self->m0 = 0;
    }
    if (self->m4 != 0) {
        fn_80377488(self->m4);
        self->m4 = 0;
    }
}

void fn_80341820(Unk803417B0* self, int chrg)
{
    if (self->m0 != 0)
        fn_803417C8(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk8034186C {
    void* m0;
    void* m4;
    int m8;
};

Unk8034186C* fn_8034186C(Unk8034186C* self, int v)
{
    self->m8 = v;
    self->m0 = 0;
    self->m4 = 0;
    return self;
}

void fn_80341884(Unk8034186C* self)
{
    if (self->m0 != 0) {
        fn_80377488(self->m0);
        self->m0 = 0;
    }
    if (self->m4 != 0) {
        fn_80377488(self->m4);
        self->m4 = 0;
    }
}

void fn_803418DC(Unk8034186C* self, int chrg)
{
    if (self->m0 != 0)
        fn_80341884(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341928 {
    void* m0;
    void* m4;
    int m8;
};

Unk80341928* fn_80341928(Unk80341928* self, int v)
{
    self->m8 = v;
    self->m0 = 0;
    self->m4 = 0;
    return self;
}

void fn_80341940(Unk80341928* self)
{
    if (self->m0 != 0) {
        fn_80377488(self->m0);
        self->m0 = 0;
    }
    if (self->m4 != 0) {
        fn_80377488(self->m4);
        self->m4 = 0;
    }
}

void fn_80341998(Unk80341928* self, int chrg)
{
    if (self->m0 != 0)
        fn_80341940(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk803419E4 {
    void* m0;
    void* m4;
    int m8;
};

Unk803419E4* fn_803419E4(Unk803419E4* self, int v)
{
    self->m8 = v;
    self->m0 = 0;
    self->m4 = 0;
    return self;
}

void fn_803419FC(Unk803419E4* self)
{
    if (self->m0 != 0) {
        fn_80377488(self->m0);
        self->m0 = 0;
    }
    if (self->m4 != 0) {
        fn_80377488(self->m4);
        self->m4 = 0;
    }
}

void fn_80341A54(Unk803419E4* self, int chrg)
{
    if (self->m0 != 0)
        fn_803419FC(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341AA0 {
    void* m0;
    void* m4;
    int m8;
};

Unk80341AA0* fn_80341AA0(Unk80341AA0* self, int v)
{
    self->m8 = v;
    self->m0 = 0;
    self->m4 = 0;
    return self;
}

void fn_80341AB8(Unk80341AA0* self)
{
    if (self->m0 != 0) {
        fn_80377488(self->m0);
        self->m0 = 0;
    }
    if (self->m4 != 0) {
        fn_80377488(self->m4);
        self->m4 = 0;
    }
}

void fn_80341B10(Unk80341AA0* self, int chrg)
{
    if (self->m0 != 0)
        fn_80341AB8(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341B5C {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

Unk80341B5C* fn_80341B5C(Unk80341B5C* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
    self->m8 = 0;
    self->m10 = 0;
    return self;
}
