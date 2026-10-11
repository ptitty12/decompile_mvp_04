/*
 * Game code, .text 0x80341B78-0x80344180 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

void fn_80377488(void* p);
void fn_80377408(void* p);

struct Unk80341B5C {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
};

void fn_80341B78(Unk80341B5C* self)
{
    if (self->m8 != 0) {
        fn_80377488(self->m8);
        self->m8 = 0;
    }
    if (self->m10 != 0) {
        fn_80377488(self->m10);
        self->m10 = 0;
    }
}

void fn_80341BD0(Unk80341B5C* self, int chrg)
{
    if (self->m10 != 0)
        fn_80341B78(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341C1C {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
};

Unk80341C1C* fn_80341C1C(Unk80341C1C* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
    self->m8 = 0;
    self->m10 = 0;
    return self;
}

void fn_80341C38(Unk80341C1C* self)
{
    if (self->m8 != 0) {
        fn_80377488(self->m8);
        self->m8 = 0;
    }
    if (self->m10 != 0) {
        fn_80377488(self->m10);
        self->m10 = 0;
    }
}

void fn_80341C90(Unk80341C1C* self, int chrg)
{
    if (self->m10 != 0)
        fn_80341C38(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341CDC {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
};

Unk80341CDC* fn_80341CDC(Unk80341CDC* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
    self->m8 = 0;
    self->m10 = 0;
    return self;
}

void fn_80341CF8(Unk80341CDC* self)
{
    if (self->m8 != 0) {
        fn_80377488(self->m8);
        self->m8 = 0;
    }
    if (self->m10 != 0) {
        fn_80377488(self->m10);
        self->m10 = 0;
    }
}

void fn_80341D50(Unk80341CDC* self, int chrg)
{
    if (self->m10 != 0)
        fn_80341CF8(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341D9C {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
};

Unk80341D9C* fn_80341D9C(Unk80341D9C* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
    self->m8 = 0;
    self->m10 = 0;
    return self;
}

void fn_80341DB8(Unk80341D9C* self)
{
    if (self->m8 != 0) {
        fn_80377488(self->m8);
        self->m8 = 0;
    }
    if (self->m10 != 0) {
        fn_80377488(self->m10);
        self->m10 = 0;
    }
}

void fn_80341E10(Unk80341D9C* self, int chrg)
{
    if (self->m10 != 0)
        fn_80341DB8(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341E5C {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
};

Unk80341E5C* fn_80341E5C(Unk80341E5C* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
    self->m8 = 0;
    self->m10 = 0;
    return self;
}

void fn_80341E78(Unk80341E5C* self)
{
    if (self->m8 != 0) {
        fn_80377488(self->m8);
        self->m8 = 0;
    }
    if (self->m10 != 0) {
        fn_80377488(self->m10);
        self->m10 = 0;
    }
}

void fn_80341ED0(Unk80341E5C* self, int chrg)
{
    if (self->m10 != 0)
        fn_80341E78(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341F1C {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
};

Unk80341F1C* fn_80341F1C(Unk80341F1C* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
    self->m8 = 0;
    self->m10 = 0;
    return self;
}

void fn_80341F38(Unk80341F1C* self)
{
    if (self->m8 != 0) {
        fn_80377488(self->m8);
        self->m8 = 0;
    }
    if (self->m10 != 0) {
        fn_80377488(self->m10);
        self->m10 = 0;
    }
}

void fn_80341F90(Unk80341F1C* self, int chrg)
{
    if (self->m10 != 0)
        fn_80341F38(self);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80341FDC {
    void* m0;
    int m4;
    int m8;
    unsigned char mC;
};
struct Unk80341FF4 {
    int pad0[3];
    unsigned short mC;
    unsigned short mE;
};

int fn_80341FDC(Unk80341FDC* self)
{
    return self->m0 == 0 ? 0 : 1;
}

unsigned short fn_80341FF4(Unk80341FF4* self)
{
    return self->mC;
}

void* fn_803774A8(int size, int heap);
void fn_803EE7BC();

struct Unk80341FFC {
    unsigned short* m0;
    int* m4;
    int m8;
    unsigned short mC;
    unsigned short mE;
};

void fn_80341FFC(Unk80341FFC* t, unsigned short* src)
{
    if (fn_80341FDC((Unk80341FDC*)t) != 0)
        return;
    int i;
    t->mE = 0;
    t->mC = t->m8;
    for (i = 0; i < t->mC; i++) {
        if (!(t->mE > src[i]))
            t->mE = src[i] + 1;
    }
    t->m0 = (unsigned short*)fn_803774A8(t->m8 * 2, 0);
    fn_803EE7BC();
    t->m4 = (int*)fn_803774A8(t->mE * 4, 0);
    fn_803EE7BC();
    int k;
    for (k = 0; k < t->mE; k++)
        t->m4[k] = fn_80341FF4((Unk80341FF4*)t);
    int j;
    for (j = 0; j < t->mC; j++) {
        unsigned short v = src[j];
        t->m0[j] = v;
        t->m4[v] = j;
    }
}

int fn_80342128(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342140(Unk80341FDC* self) { return self->mC; }
int fn_8034241C(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342434(Unk80341FDC* self) { return self->mC; }
int fn_80342710(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342728(Unk80341FDC* self) { return self->mC; }
int fn_80342A04(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342A1C(Unk80341FDC* self) { return self->mC; }
int fn_80342CF8(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342D10(Unk80341FDC* self) { return self->mC; }

struct Unk80342FEC {
    int m0;
    int* m4;
    int m8;
};
int fn_80342FEC(Unk80342FEC* self) { return self->m8 == 0 ? 0 : 1; }
int fn_80343004(Unk80342FEC* self, int i) { return self->m4[i]; }
int fn_80343014(Unk80342FEC* self, int i) { return self->m4[i]; }
int fn_803432C4(Unk80342FEC* self) { return self->m8 == 0 ? 0 : 1; }
int fn_803432DC(Unk80342FEC* self, int i) { return self->m4[i]; }
int fn_8034358C(Unk80342FEC* self) { return self->m8 == 0 ? 0 : 1; }
int fn_803435A4(Unk80342FEC* self, int i) { return self->m4[i]; }
int fn_80343854(Unk80342FEC* self) { return self->m8 == 0 ? 0 : 1; }
int fn_8034386C(Unk80342FEC* self, int i) { return self->m4[i]; }
int fn_80343B1C(Unk80342FEC* self) { return self->m8 == 0 ? 0 : 1; }
int fn_80343B34(Unk80342FEC* self, int i) { return self->m4[i]; }
int fn_80343DCC(Unk80342FEC* self) { return self->m8 == 0 ? 0 : 1; }

struct Unk8034406C {
    int m0;
    int* m4;
    int m8;
    unsigned short mC;
    unsigned short mE;
};

int fn_8034406C(Unk8034406C* self, unsigned short idx)
{
    int r = 0;
    if (idx < self->mE) {
        int a = self->m4[idx];
        int b = fn_80341FF4((Unk80341FF4*)self);
        int ne = a != b;
        if (ne)
            r = 1;
    }
    return r;
}

struct Unk803440D0 {
    int m0;
    unsigned char m4;
};
unsigned char fn_803440D0(Unk803440D0* self) { return self->m4; }
unsigned char fn_803440D8(Unk803440D0* self) { return self->m4; }
unsigned char fn_803440E0(Unk803440D0* self) { return self->m4; }
unsigned char fn_803440E8(Unk803440D0* self) { return self->m4; }

unsigned char fn_803440F0(Unk803415F0* t, int v)
{
    unsigned char i = fn_803415F0(t, v);
    if (t->mFE == i)
        return 0;
    return t->mCC[i];
}

unsigned char fn_80344138(Unk8034151C* t, int v)
{
    unsigned char i = fn_8034151C(t, v);
    if (t->m9A == i)
        return 0;
    return t->m7C[i];
}
