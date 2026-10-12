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

struct Unk803417B0 { void* m0; void* m4; int m8; };
void fn_803417C8(Unk803417B0* self);
struct Unk8034186C { void* m0; void* m4; int m8; };
void fn_80341884(Unk8034186C* self);
struct Unk80341928 { void* m0; void* m4; int m8; };
void fn_80341940(Unk80341928* self);
struct Unk803419E4 { void* m0; void* m4; int m8; };
void fn_803419FC(Unk803419E4* self);

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
int fn_803EE7BC();

struct Unk803416F4 {
    void* m0;
    void* m4;
    int m8;
};
void fn_8034170C(Unk803416F4* self);
extern "C" {
const char* fn_802B9300(const char* s, int a, int b, unsigned* outn);
void fn_802B961C(const char* p, int a);
void fn_803792AC(const char** pp, unsigned* pn);
int fn_80329D1C(const char** pp, unsigned* pn, unsigned* out, int lo, int hi, int delim);
void fn_80329AEC(const char** pp, const char** out, unsigned* pn, int delim);
int strcmp(const char* a, const char* b);
}
/* Row loader object: m0 flag bytes, m4 index table, m8 expected row count, mC rows read, mD id bound. */
struct Unk80342148 {
    unsigned char* m0;
    int* m4;
    int m8;
    unsigned char mC;
    unsigned char mD;
};

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
extern "C" void fn_8034243C(Unk80342148* self, const char* text, const char** names)
{
    unsigned n;
    const char* cur;
    unsigned rem;
    unsigned id1;
    unsigned id2;
    const char* tok;
    if (fn_8034241C((Unk80341FDC*)self) != 0)
        return;
    const char* buf = fn_802B9300(text, 0x500, 0xC, &n);
    const char* end;
    if (n == 0) goto done;
    end = buf + n;
    cur = buf;
    rem = n;
    fn_803792AC(&cur, &rem);
    self->mC = 0;
    self->mD = 0;
    while (cur != end && rem > 1) {
        id1 = 0;
        fn_80329D1C(&cur, &rem, &id1, 1, 1000000, 0x2C);
        if (!(self->mD > id1))
            self->mD = (unsigned char)id1 + 1;
        fn_803792AC(&cur, &rem);
        self->mC++;
    }
    if (self->mC >= self->m8) goto alloc;
done:
    fn_802B961C(buf, 0xC);
    return;
alloc:
    self->m0 = (unsigned char*)fn_803774A8(self->mC, 0);
    fn_803EE7BC();
    self->m4 = (int*)fn_803774A8(self->mD * 4, 0);
    fn_803EE7BC();
    int k;
    for (k = 0; k < self->mD; k++)
        self->m4[k] = fn_80342434((Unk80341FDC*)self);
    cur = buf;
    rem = n;
    unsigned prev = 0;
    int j = 0;
    int rows = 0;
    int x = self->m8;
    fn_803792AC(&cur, &rem);
    while (cur != end && rem > 1) {
        fn_80329D1C(&cur, &rem, &id2, 1, 1000000, 0x2C);
        if (rows != 0 && !(prev < id2)) {
            fn_802B961C(buf, 0xC);
            fn_803417C8((Unk803417B0*)self);
            return;
        }
        fn_80329AEC(&cur, &tok, &rem, 0xD);
        if (j < self->m8 && strcmp(tok, *names) == 0) {
            self->m0[j] = (unsigned char)id2;
            self->m4[id2] = j;
            names++;
            j++;
        } else {
            self->m0[x] = (unsigned char)id2;
            self->m4[id2] = x;
            x++;
        }
        rows++;
        prev = id2;
    }
    for (; j != self->m8; j++) {
    }
    fn_802B961C(buf, 0xC);
}

int fn_80342710(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342728(Unk80341FDC* self) { return self->mC; }
extern "C" void fn_80342730(Unk80342148* self, const char* text, const char** names)
{
    unsigned n;
    const char* cur;
    unsigned rem;
    unsigned id1;
    unsigned id2;
    const char* tok;
    if (fn_80342710((Unk80341FDC*)self) != 0)
        return;
    const char* buf = fn_802B9300(text, 0x500, 0xC, &n);
    const char* end;
    if (n == 0) goto done;
    end = buf + n;
    cur = buf;
    rem = n;
    fn_803792AC(&cur, &rem);
    self->mC = 0;
    self->mD = 0;
    while (cur != end && rem > 1) {
        id1 = 0;
        fn_80329D1C(&cur, &rem, &id1, 1, 1000000, 0x2C);
        if (!(self->mD > id1))
            self->mD = (unsigned char)id1 + 1;
        fn_803792AC(&cur, &rem);
        self->mC++;
    }
    if (self->mC >= self->m8) goto alloc;
done:
    fn_802B961C(buf, 0xC);
    return;
alloc:
    self->m0 = (unsigned char*)fn_803774A8(self->mC, 0);
    fn_803EE7BC();
    self->m4 = (int*)fn_803774A8(self->mD * 4, 0);
    fn_803EE7BC();
    int k;
    for (k = 0; k < self->mD; k++)
        self->m4[k] = fn_80342728((Unk80341FDC*)self);
    cur = buf;
    rem = n;
    unsigned prev = 0;
    int j = 0;
    int rows = 0;
    int x = self->m8;
    fn_803792AC(&cur, &rem);
    while (cur != end && rem > 1) {
        fn_80329D1C(&cur, &rem, &id2, 1, 1000000, 0x2C);
        if (rows != 0 && !(prev < id2)) {
            fn_802B961C(buf, 0xC);
            fn_80341884((Unk8034186C*)self);
            return;
        }
        fn_80329AEC(&cur, &tok, &rem, 0xD);
        if (j < self->m8 && strcmp(tok, *names) == 0) {
            self->m0[j] = (unsigned char)id2;
            self->m4[id2] = j;
            names++;
            j++;
        } else {
            self->m0[x] = (unsigned char)id2;
            self->m4[id2] = x;
            x++;
        }
        rows++;
        prev = id2;
    }
    for (; j != self->m8; j++) {
    }
    fn_802B961C(buf, 0xC);
}

int fn_80342A04(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342A1C(Unk80341FDC* self) { return self->mC; }
extern "C" void fn_80342A24(Unk80342148* self, const char* text, const char** names)
{
    unsigned n;
    const char* cur;
    unsigned rem;
    unsigned id1;
    unsigned id2;
    const char* tok;
    if (fn_80342A04((Unk80341FDC*)self) != 0)
        return;
    const char* buf = fn_802B9300(text, 0x500, 0xC, &n);
    const char* end;
    if (n == 0) goto done;
    end = buf + n;
    cur = buf;
    rem = n;
    fn_803792AC(&cur, &rem);
    self->mC = 0;
    self->mD = 0;
    while (cur != end && rem > 1) {
        id1 = 0;
        fn_80329D1C(&cur, &rem, &id1, 1, 1000000, 0x2C);
        if (!(self->mD > id1))
            self->mD = (unsigned char)id1 + 1;
        fn_803792AC(&cur, &rem);
        self->mC++;
    }
    if (self->mC >= self->m8) goto alloc;
done:
    fn_802B961C(buf, 0xC);
    return;
alloc:
    self->m0 = (unsigned char*)fn_803774A8(self->mC, 0);
    fn_803EE7BC();
    self->m4 = (int*)fn_803774A8(self->mD * 4, 0);
    fn_803EE7BC();
    int k;
    for (k = 0; k < self->mD; k++)
        self->m4[k] = fn_80342A1C((Unk80341FDC*)self);
    cur = buf;
    rem = n;
    unsigned prev = 0;
    int j = 0;
    int rows = 0;
    int x = self->m8;
    fn_803792AC(&cur, &rem);
    while (cur != end && rem > 1) {
        fn_80329D1C(&cur, &rem, &id2, 1, 1000000, 0x2C);
        if (rows != 0 && !(prev < id2)) {
            fn_802B961C(buf, 0xC);
            fn_80341940((Unk80341928*)self);
            return;
        }
        fn_80329AEC(&cur, &tok, &rem, 0xD);
        if (j < self->m8 && strcmp(tok, *names) == 0) {
            self->m0[j] = (unsigned char)id2;
            self->m4[id2] = j;
            names++;
            j++;
        } else {
            self->m0[x] = (unsigned char)id2;
            self->m4[id2] = x;
            x++;
        }
        rows++;
        prev = id2;
    }
    for (; j != self->m8; j++) {
    }
    fn_802B961C(buf, 0xC);
}

int fn_80342CF8(Unk80341FDC* self) { return self->m0 == 0 ? 0 : 1; }
unsigned char fn_80342D10(Unk80341FDC* self) { return self->mC; }

struct Unk80342FEC {
    int m0;
    int* m4;
    int m8;
};
extern "C" void fn_80342D18(Unk80342148* self, const char* text, const char** names)
{
    unsigned n;
    const char* cur;
    unsigned rem;
    unsigned id1;
    unsigned id2;
    const char* tok;
    if (fn_80342CF8((Unk80341FDC*)self) != 0)
        return;
    const char* buf = fn_802B9300(text, 0x500, 0xC, &n);
    const char* end;
    if (n == 0) goto done;
    end = buf + n;
    cur = buf;
    rem = n;
    fn_803792AC(&cur, &rem);
    self->mC = 0;
    self->mD = 0;
    while (cur != end && rem > 1) {
        id1 = 0;
        fn_80329D1C(&cur, &rem, &id1, 1, 1000000, 0x2C);
        if (!(self->mD > id1))
            self->mD = (unsigned char)id1 + 1;
        fn_803792AC(&cur, &rem);
        self->mC++;
    }
    if (self->mC >= self->m8) goto alloc;
done:
    fn_802B961C(buf, 0xC);
    return;
alloc:
    self->m0 = (unsigned char*)fn_803774A8(self->mC, 0);
    fn_803EE7BC();
    self->m4 = (int*)fn_803774A8(self->mD * 4, 0);
    fn_803EE7BC();
    int k;
    for (k = 0; k < self->mD; k++)
        self->m4[k] = fn_80342D10((Unk80341FDC*)self);
    cur = buf;
    rem = n;
    unsigned prev = 0;
    int j = 0;
    int rows = 0;
    int x = self->m8;
    fn_803792AC(&cur, &rem);
    while (cur != end && rem > 1) {
        fn_80329D1C(&cur, &rem, &id2, 1, 1000000, 0x2C);
        if (rows != 0 && !(prev < id2)) {
            fn_802B961C(buf, 0xC);
            fn_803419FC((Unk803419E4*)self);
            return;
        }
        fn_80329AEC(&cur, &tok, &rem, 0xD);
        if (j < self->m8 && strcmp(tok, *names) == 0) {
            self->m0[j] = (unsigned char)id2;
            self->m4[id2] = j;
            names++;
            j++;
        } else {
            self->m0[x] = (unsigned char)id2;
            self->m4[id2] = x;
            x++;
        }
        rows++;
        prev = id2;
    }
    for (; j != self->m8; j++) {
    }
    fn_802B961C(buf, 0xC);
}

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

/* Loader object of the 168-instruction family (fn_80343024): m0/m4 are the two tables read through
   fn_80343004/fn_80343014, m8 an array of {first, last} halfword pairs per entry, mC the entry count. */
struct Unk80343024_P { unsigned short a; unsigned short b; };
struct Unk80343024 {
    Unk80341FDC* m0;
    Unk80341FDC* m4;
    Unk80343024_P* m8;
    unsigned char mC;
    int* m10;
    unsigned short m14;
};
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

/* near-miss: 16 slots, instruction count and layout identical (168 of 168). Only the two callee-saved address registers of the
   second loop are swapped: retail &cur r28, &rem r29; here &cur r29 (equal priority, lower pseudo number allocated first).
   Same shape at fn_803432EC, fn_803435B4, fn_8034387C. */
extern "C" void fn_80343024(Unk80343024* self, const char* text)
{
    unsigned n;
    const char* cur;
    unsigned rem;
    unsigned tok;
    unsigned id;
    unsigned id2;
    if (fn_80342FEC((Unk80342FEC*)self) != 0)
        return;
    if (fn_80342128(self->m0) == 0)
        return;
    if (fn_80341FDC(self->m4) == 0)
        return;
    const char* buf = fn_802B9300(text, 0x500, 0xC, &n);
    self->m14 = 0;
    const char* end = buf + n;
    cur = buf;
    rem = n;
    fn_803792AC(&cur, &rem);
    while (cur != end && rem > 1) {
        fn_803792AC(&cur, &rem);
        self->m14++;
    }
    self->mC = self->m0->mC;
    self->m8 = (Unk80343024_P*)fn_803774A8(self->mC * 4, 0);
    fn_803EE7BC();
    self->m10 = (int*)fn_803774A8(self->m14 * 4, 0);
    fn_803EE7BC();
    int i;
    for (i = 0; i < self->mC; i++) {
        char* p = (char*)self->m8;
        int off = i * 4;
        char* q = (char*)(off + (int)p);
        *(unsigned short*)q = 1;
        *(unsigned short*)(q + 2) = 0;
    }
    cur = buf;
    rem = n;
    int j = 0;
    fn_803792AC(&cur, &rem);
    int prev = 0;
    int i2 = 0;
    while (cur != end && rem > 1) {
        fn_80329AEC(&cur, (const char**)&tok, &rem, 0x2C);
        fn_80329D1C(&cur, &rem, &id, 1, 1000000, 0x2C);
        int k = fn_80343004((Unk80342FEC*)self->m0, (unsigned char)id);
        if (j != 0) {
            if (prev == k)
                goto next;
            self->m8[prev].b = j;
        }
        prev = k;
        if (self->m8[k].a < self->m8[k].b) {
            fn_802B961C(buf, 0xC);
            fn_80341B78((Unk80341B5C*)self);
            return;
        }
        self->m8[k].a = j;
    next:
        fn_80329D1C(&cur, &rem, &id2, 1, 1000000, 0xD);
        j++;
        self->m10[i2] = fn_80343014((Unk80342FEC*)self->m4, (unsigned short)id2);
        i2++;
    }
    self->m8[prev].b = j;
    fn_802B961C(buf, 0xC);
}

/* near-miss (99.6%, 10 slots): instruction sequence and block layout are identical to retail (181 of 181 insns); only the
   callee-saved register numbering of three values differs: retail names r24, end r23, rows r22; here end r24, rows r23,
   names r22 (buf r25 and x r26 match). One shared `done:` free block (a goto from the n == 0 test) keeps buf at 7
   references (a second free site made it 8 and moved it above x). global-alloc priority of names (4 refs) stays below end
   (5 refs, test copies counted) and rows; the init order below (cur/rem first) was the best of 144 orders and ~130 spelling
   toggles. The same loader repeats verbatim at fn_8034243C, fn_80342730, fn_80342A24, fn_80342D18 (cloned below, same score). */
extern "C" void fn_80342148(Unk80342148* self, const char* text, const char** names)
{
    unsigned n;
    const char* cur;
    unsigned rem;
    unsigned id1;
    unsigned id2;
    const char* tok;
    if (fn_80342128((Unk80341FDC*)self) != 0)
        return;
    const char* buf = fn_802B9300(text, 0x500, 0xC, &n);
    const char* end;
    if (n == 0) goto done;
    end = buf + n;
    cur = buf;
    rem = n;
    fn_803792AC(&cur, &rem);
    self->mC = 0;
    self->mD = 0;
    while (cur != end && rem > 1) {
        id1 = 0;
        fn_80329D1C(&cur, &rem, &id1, 1, 1000000, 0x2C);
        if (!(self->mD > id1))
            self->mD = (unsigned char)id1 + 1;
        fn_803792AC(&cur, &rem);
        self->mC++;
    }
    if (self->mC >= self->m8) goto alloc;
done:
    fn_802B961C(buf, 0xC);
    return;
alloc:
    self->m0 = (unsigned char*)fn_803774A8(self->mC, 0);
    fn_803EE7BC();
    self->m4 = (int*)fn_803774A8(self->mD * 4, 0);
    fn_803EE7BC();
    int k;
    for (k = 0; k < self->mD; k++)
        self->m4[k] = fn_80342140((Unk80341FDC*)self);
    cur = buf;
    rem = n;
    unsigned prev = 0;
    int j = 0;
    int rows = 0;
    int x = self->m8;
    fn_803792AC(&cur, &rem);
    while (cur != end && rem > 1) {
        fn_80329D1C(&cur, &rem, &id2, 1, 1000000, 0x2C);
        if (rows != 0 && !(prev < id2)) {
            fn_802B961C(buf, 0xC);
            fn_8034170C((Unk803416F4*)self);
            return;
        }
        fn_80329AEC(&cur, &tok, &rem, 0xD);
        if (j < self->m8 && strcmp(tok, *names) == 0) {
            self->m0[j] = (unsigned char)id2;
            self->m4[id2] = j;
            names++;
            j++;
        } else {
            self->m0[x] = (unsigned char)id2;
            self->m4[id2] = x;
            x++;
        }
        rows++;
        prev = id2;
    }
    for (; j != self->m8; j++) {
    }
    fn_802B961C(buf, 0xC);
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
