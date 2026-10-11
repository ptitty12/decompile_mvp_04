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
extern const float lbl_805EBA58;
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
void fn_80326610(FxAI* self, int a, int b, float c);
int fn_80324A24(FxZ* a);
int fn_803249D4(FxY* a, FxY* b);
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
void fn_80326300(FxZT* self, int a, int b, int c, float f1, float f2);
FxAI* fn_803263C4(FxAI* self, FxAIB* a);
void fn_80326410(FxAI* self, int a);
void fn_803264B4(FxAI* self, int a);
void fn_80326534(FxAI* self);
void fn_80326554(FxAI* self);
void fn_80326574(FxAI* self);
FxShorts* fn_803265F0();
int fn_80326C20(FxAI* a);
int fn_80326DF0(FxRing* self, int flag);
int fn_80326E64(FxRing* self, int flag);
void fn_80326ED4(FxZ6C* a, int* o1, int* o2);
void fn_80326EF4(FxZ6C* a, int p4, int p5, int p6, int p7, float f1, float f2);
int fn_80326F30(int a);
FxZ fn_80326F44(FxPtr* p, int kind, float t);
FxZ fn_80326FC4(FxPtr* p, int kind, float t);
FxZ fn_80327044(FxPtr* p, int kind, float t);
int fn_803270C4(FxPtr* p, int kind, int flag, float t);
void fn_80327100(FxPtr* p, float f1, float f2, int a, int b, int c);
void fn_8032713C(FxAI* self, int a, int b);
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

/* near-miss: register choice of the float constant */
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

/* near-miss: register assignment of the walk pointers */
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

/* near-miss: loop shape (retail jumps into a bottom-tested loop, keeps scanning after a hit) and key layout */
void fn_80326300(FxZT* self, int a, int b, int c, float f1, float f2) {
    float t1 = f1;
    float t2 = lbl_805EBA58;
    FxZ key;
    key.m0 = a;
    key.m4 = t1;
    key.m8 = b;
    key.mC = c;
    key.m10 = t2;
    key.m14 = 0;
    for (int i = 0; i < self->m8; i++) {
        FxZ* e = (FxZ*)(self->m4 + i * 0x18);
        if (fn_803249D4((FxY*)e, (FxY*)&key)) {
            if (!(e->m10 <= f2)) e->m10 = f2;
            return;
        }
    }
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

/* near-miss: register assignment (result kept in r10, v in r0) */
int fn_80326DF0(FxRing* self, int flag) {
    FxRingH* h = self->m0;
    int r = -1;
    if (h->m1C != h->m20) r = h->m0[h->m1C * 4 + 1];
    else flag = 1;
    if (flag) {
        FxRingH* h2 = self->m4;
        int v = h2->m0[h2->m1C * 4 + 1];
        if (v < r) r = v;
        else if (r < 0) r = v;
    }
    return r >= 0 ? r : 0;
}

/* near-miss: result kept in r3 in retail */
int fn_80326E64(FxRing* self, int flag) {
    FxRingH* h = self->m0;
    int r = -1;
    if (h->m1C != h->m20) r = h->m0[h->m18 * 4 + 1];
    else flag = 1;
    if (flag) {
        FxRingH* h2 = self->m4;
        int v = h2->m0[h2->m18 * 4 + 1];
        if (v > r || r < 0) r = v;
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

/* near-miss: default-struct return; retail loads the 6-word default through different registers (word copy batching) */
FxZ fn_80326F44(FxPtr* p, int kind, float t) {
    FxZT* tab = p->m0;
    if (tab) return fn_80325158(tab, kind, t);
    return lbl_805EBA10;
}

/* near-miss: same as the neighbouring function */
FxZ fn_80326FC4(FxPtr* p, int kind, float t) {
    FxZT* tab = p->m0;
    if (tab) return fn_80325410(tab, kind, t);
    return lbl_805EBA10;
}

/* near-miss: default-struct return; retail loads the 6-word default through different registers (word copy batching) */
FxZ fn_80327044(FxPtr* p, int kind, float t) {
    FxZT* tab = p->m0;
    if (tab) return fn_80325848(tab, kind, t);
    return lbl_805EBA10;
}

/* near-miss: branch polarity of the kind test is inverted relative to retail */
int fn_803270C4(FxPtr* p, int kind, int flag, float t) {
    if (p->m0 == 0) return 0;
    return fn_803256C8(p->m0, kind, flag, t);
}

void fn_80327100(FxPtr* p, float f1, float f2, int a, int b, int c) {
    if (p->m0) fn_80326300(p->m0, a, b, c, f1, f2);
}

void fn_8032713C(FxAI* self, int a, int b) {
    if (a != b) {
        FxZT* z = ((FxZT**)self)[a];
        int cnt = 0;
        int i = z->m18;
        FxEnt16* e = (FxEnt16*)z->m0;
        int ref = e[i].m4;
        while (i != z->m1C) {
            int prev = i;
            cnt++;
            if (--i < 0) i = z->m24 - 1;
            if (ref - e[i].m4 > 1) { i = prev; break; }
        }
        if (cnt > 0) {
            int n = cnt;
            do {
                int off = i * 16;
                FxEnt16* p = (FxEnt16*)(off + (int)z->m0);
                fn_80326610(self, p->m0, p->m4, p->m8);
                i = (i + 1) % z->m24;
            } while (--n);
        }
    }
}
