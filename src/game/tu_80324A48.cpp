/*
 * Game code, .text 0x80324A48-0x80327214 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern const float lbl_805EBA30;
extern const float lbl_805EBA34;
extern const float lbl_805EBA44;
extern const float lbl_805EBA48;
extern const void* const lbl_80665E30[];
extern const void* const lbl_80665E48[];
extern int lbl_80620860;
extern int lbl_80620298;
extern FxZ lbl_805EBA10;
struct FxShorts;
struct FxGlobal { char pad0[0x30]; FxShorts* m30; };
extern FxGlobal* lbl_8061B8C0;

extern "C" {
void fn_80325080(FxZT* self, int a, int b, int c, int d, float x, float y);
int fn_803256C8(FxZT* self, int kind, int flag, float t);
void fn_80327274(FxAI* self);
FxZ fn_80325158(FxZT* tab, int kind, float t);
FxZ fn_80325410(FxZT* tab, int kind, float t);
FxZ fn_80325848(FxZT* tab, int kind, float t);
void fn_80326300(FxZT* t, int a, int b, int c, float f1, float f2);
int fn_80324A24(FxZ* a);
int fn_80324C6C(FxZ* a, int b);
void fn_80377488(void* p);
void fn_80377408(void* p);
void* fn_803774A8(unsigned size, int heap);
// PROTOS-BEGIN
int fn_80324A48(FxZ* a);
int fn_80324A70(FxZ* a);
int fn_80324A98(FxZ* a);
int fn_80324AC0(FxZ* a);
int fn_80324AE8(FxZ* a, int unused);
int fn_80324B0C(FxZ* a);
int fn_80324B58(FxZ* a);
int fn_80324BA8(FxZ* a);
int fn_80324BF8(FxZ* a);
int fn_80324C48(FxZ* a, int unused);
int fn_80324D74(FxZ* a);
int fn_80324DB4(FxZ* a, int unused);
int fn_80324DCC(FxZ* a);
int fn_80324E38(FxZ* a);
int fn_80324E54(FxZ* a);
int fn_80324E6C(FxZ* a);
int fn_80324E84(short* p);
char* fn_80324EC8(char* a);
void fn_80324ED0(short* p, int v);
FxZT* fn_80324EF0(FxZT* self, int a, int b, int c);
void fn_80324F78(FxZT* self, int a);
void fn_80325000(FxZT* self);
void fn_80325080(FxZT* self, int a, int b, int c, int d, float x, float y);
void fn_803250EC(FxZT* self);
float fn_803250F8(FxZT* self, int flag, float a);
float fn_80325128(FxZT* self, int flag, float a);
FxPred fn_80325D18(void* self, int kind);
FxAI* fn_803263C4(FxAI* self, FxAIB* a);
void fn_80326410(FxAI* self, int a);
void fn_803264B4(FxAI* self, int a);
void fn_80326534(FxAI* self);
void fn_80326554(FxAI* self);
void fn_80326574(FxAI* self);
FxShorts* fn_803265F0();
int fn_80326C20(FxAI* a);
void fn_80326ED4(FxZ6C* a, int* o1, int* o2);
void fn_80326EF4(FxZ6C* a, int p4, int p5, int p6, int p7, float f1, float f2);
int fn_80326F30(int a);
FxZ fn_80326F44(FxPtr* p, int kind, float t);
FxZ fn_80326FC4(FxPtr* p, int kind, float t);
FxZ fn_80327044(FxPtr* p, int kind, float t);
int fn_803270C4(FxPtr* p, int kind, int flag, float t);
void fn_80327100(FxPtr* p, int a, int b, int c, float f1, float f2);
// PROTOS-END
}

// FUNCS-BEGIN

int fn_80324A48(FxZ* a) {
    int r = 0;
    if (a->m0 == 0x7F) r = a->m8 == 9;
    return r;
}

int fn_80324A70(FxZ* a) {
    int r = 0;
    if (a->m0 == 0x7F) r = a->m8 == 0xA;
    return r;
}

int fn_80324A98(FxZ* a) {
    int r = 0;
    if (a->m0 == 0x7F) r = a->m8 == 0xB;
    return r;
}

int fn_80324AC0(FxZ* a) {
    int r = 0;
    if (a->m0 == 0x7F) r = a->m8 == 0xC;
    return r;
}

int fn_80324AE8(FxZ* a, int unused) {
    int r = 0;
    if (a->m0 == 0x62 || a->m0 == 0x39) r = 1;
    return r;
}

int fn_80324B0C(FxZ* a) {
    int r = 0;
    if (fn_80324AE8(a, 0)) r = a->mC == 0;
    return r;
}

int fn_80324B58(FxZ* a) {
    int r = 0;
    if (fn_80324AE8(a, 0)) r = a->mC == 1;
    return r;
}

int fn_80324BA8(FxZ* a) {
    int r = 0;
    if (fn_80324AE8(a, 0)) r = a->mC == 2;
    return r;
}

int fn_80324BF8(FxZ* a) {
    int r = 0;
    if (fn_80324AE8(a, 0)) r = a->mC == 3;
    return r;
}

int fn_80324C48(FxZ* a, int unused) {
    int r = 0;
    if (a->m0 == 0x62 || a->m0 == 0x39) r = 1;
    return r;
}

int fn_80324D74(FxZ* a) {
    const float t = lbl_805EBA30;
    int r = 0;
    if (a->m0 == 0xAE) r = a->m10 <= t;
    return r;
}

int fn_80324DB4(FxZ* a, int unused) {
    if (a->m14 & 0x10) return 1;
    return 0;
}

int fn_80324DCC(FxZ* a) {
    int r = 0;
    if (a->m0 == 0xAD) {
        if (fn_80324DB4(a, 0)) r = 1;
        else {
            int t = 1;
            if ((a->m14 & 0x80) == 0) t = 0;
            if (t) r = 1;
        }
    }
    return r;
}

int fn_80324E38(FxZ* a) { return a->m10 < lbl_805EBA34; }

int fn_80324E54(FxZ* a) {
    if (a->m14 & 2) return 1;
    return 0;
}

int fn_80324E6C(FxZ* a) { return (unsigned)(a->m0 - 0xAD) <= 1; }

int fn_80324E84(short* p) {
    short* last = p;
    short* cur = p;
    while (cur) {
        int d = cur[0];
        short* nx = 0;
        if (d) nx = (short*)(d + (int)cur);
        cur = nx;
        if (cur) last = cur;
    }
    return (char*)last - (char*)p + 4;
}

char* fn_80324EC8(char* a) { return a + 4; }

void fn_80324ED0(short* p, int v) {
    v += 4;
    p[0] = v;
    short off = v;
    *(short*)((char*)p + off) = 0;
    *(short*)((char*)p + off + 2) = 0;
}

FxZT* fn_80324EF0(FxZT* self, int a, int b, int c) {
    self->m28 = b;
    *(const void**)((char*)self + 0x2C) = lbl_80665E48;
    self->m24 = a;
    self->m0 = (int*)fn_803774A8(a * 16, 0);
    self->m4 = (char*)fn_803774A8(b * 0x18, 0);
    self->mC = (int*)fn_803774A8(c, 0);
    self->m10 = c;
    fn_80325000(self);
    return self;
}

void fn_80324F78(FxZT* self, int a) {
    *(const void**)((char*)self + 0x2C) = lbl_80665E48;
    if (self->m0) fn_80377488(self->m0);
    self->m0 = 0;
    if (self->m4) fn_80377488(self->m4);
    self->m4 = 0;
    if (self->mC) fn_80377488(self->mC);
    self->mC = 0;
    if (a & 1) fn_80377408(self);
}

void fn_80325000(FxZT* self) {
    for (int i = 0; i < self->m24; i++) {
        self->m0[i * 4] = 0;
        self->m0[i * 4 + 3] = 0;
    }
    self->m14 = self->mC;
    self->m18 = 0;
    self->m1C = 0;
    self->m20 = 0;
    fn_803250EC(self);
}

void fn_80325080(FxZT* self, int a, int b, int c, int d, float x, float y) {
    if (self->m8 < self->m28) {
        float fx = x;
        float fy = y;
        FxEnt* e = (FxEnt*)(self->m8 * 0x18 + (int)self->m4);
        e->m0 = a;
        e->m4 = fx;
        e->m8 = b;
        e->mC = c;
        e->m10 = fy;
        e->m14 = d;
        self->m8 = self->m8 + 1;
    }
}

void fn_803250EC(FxZT* self) { self->m8 = 0; }

float fn_803250F8(FxZT* self, int flag, float a) {
    if (flag == 0) a = a - lbl_805EBA44;
    return a;
}

float fn_80325128(FxZT* self, int flag, float a) {
    if (flag == 0) a = a + lbl_805EBA48;
    return a;
}

FxPred fn_80325D18(void* self, int kind) {
    switch (kind) {
    case 0xB6: return (FxPred)fn_80324C48;
    case 0xB7: return (FxPred)fn_80324C6C;
    case 0xB9: return (FxPred)fn_80324E54;
    case 0xBA: return (FxPred)fn_80324E6C;
    case 0xBB: return (FxPred)fn_80324DCC;
    case 0xBC: return (FxPred)fn_80324A48;
    case 0xBD: return (FxPred)fn_80324A70;
    case 0xBE: return (FxPred)fn_80324A98;
    case 0xBF: return (FxPred)fn_80324AC0;
    case 0xC0: return (FxPred)fn_80324B0C;
    case 0xC1: return (FxPred)fn_80324B58;
    case 0xC2: return (FxPred)fn_80324BA8;
    case 0xC3: return (FxPred)fn_80324BF8;
    case 0xC4: return (FxPred)fn_80324A24;
    }
    return 0;
}

FxAI* fn_803263C4(FxAI* self, FxAIB* a) {
    self->m4F4 = lbl_80665E30;
    self->m4BC = a;
    self->m0 = 0;
    self->m4 = 0;
    fn_80326574(self);
    return self;
}

void fn_80326410(FxAI* self, int a) {
    self->m4F4 = lbl_80665E30;
    if (self->m0) delete self->m0;
    self->m0 = 0;
    if (self->m4) delete self->m4;
    self->m4 = 0;
    if (a & 1) fn_80377408(self);
}

void fn_803264B4(FxAI* self, int a) {
    if (self->m0 == 0) {
        self->m0 = fn_80324EF0((FxZT*)operator new(0x30, 0), 0x4B0, 0x32, a);
        self->m4 = fn_80324EF0((FxZT*)operator new(0x30, 0), 0x28, 0, 0x4E20);
        fn_80326574(self);
    }
}

void fn_80326534(FxAI* self) { fn_80326574(self); }

void fn_80326554(FxAI* self) { fn_80326574(self); }

void fn_80326574(FxAI* self) {
    if (self->m0) {
        fn_80325000(self->m0);
        fn_80325000(self->m4);
    }
    self->m4B8 = 1;
    fn_80327274(self);
    lbl_80620298 = 0;
    for (int i = 0; i < 13; i++) self->a4C0[i] = 0;
}

FxShorts* fn_803265F0() {
    FxShorts* p = lbl_8061B8C0->m30;
    p->m0 = 0;
    p->m2 = 0;
    return p;
}

int fn_80326C20(FxAI* a) {
    if (a->m0->m18 == 0) return 0;
    if (lbl_80620860 != 0) return 0;
    int r = 0;
    int k = a->m4BC->m564->m14;
    if (k != 9) {
        if (k != 0xA) {
            if (k != 2) r = 1;
        }
    }
    return r;
}

void fn_80326ED4(FxZ6C* a, int* o1, int* o2) {
    FxZ6C* p = (FxZ6C*)a->m0;
    if (p == 0) return;
    *o1 = p->m4;
    *o2 = p->m8;
}

void fn_80326EF4(FxZ6C* a, int p4, int p5, int p6, int p7, float f1, float f2) {
    FxZT* t = (FxZT*)a->m0;
    if (t) fn_80325080(t, p4, p5, p6, p7, f1, f2);
}

int fn_80326F30(int a) { return (unsigned)(a - 0xB3) <= 0x12; }

FxZ fn_80326F44(FxPtr* p, int kind, float t) {
    FxZT* tab = p->m0;
    if (tab) return fn_80325158(tab, kind, t);
    return lbl_805EBA10;
}

FxZ fn_80326FC4(FxPtr* p, int kind, float t) {
    FxZT* tab = p->m0;
    if (tab) return fn_80325410(tab, kind, t);
    return lbl_805EBA10;
}

FxZ fn_80327044(FxPtr* p, int kind, float t) {
    FxZT* tab = p->m0;
    if (tab) return fn_80325848(tab, kind, t);
    return lbl_805EBA10;
}

int fn_803270C4(FxPtr* p, int kind, int flag, float t) {
    if (p->m0 == 0) return 0;
    return fn_803256C8(p->m0, kind, flag, t);
}

void fn_80327100(FxPtr* p, int a, int b, int c, float f1, float f2) {
    if (p->m0) fn_80326300(p->m0, a, b, c, f1, f2);
}
