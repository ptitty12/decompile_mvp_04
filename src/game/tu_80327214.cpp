/*
 * Game code, .text 0x80327214-0x8032AC58 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"
#include "game/clampiter.h"

extern const void* const lbl_80664020[];
extern const void* const lbl_80666F98[];
extern const void* const lbl_80665E60[];
extern const char lbl_805EBBF8[];
extern const unsigned char lbl_805F340C[];
extern int lbl_806E2A44[];
extern int lbl_806E2184[][20];
extern int lbl_806202EC;
extern FxSlot8 lbl_806E2274[];
extern int lbl_806202F0;
extern int lbl_806202F4;
extern int lbl_806202FC;
extern FxSing* lbl_80620304;
extern int lbl_806202A8;
extern int lbl_80691AEC;

extern "C" {
void fn_80325000(FxZT* t);
void fn_8032713C(FxAI* self, int a, int b);
void fn_80327354(int a, int b);
void fn_8040B61C(void* p, const char* s);
void fn_80328690(FxBase* self, int a);
void fn_80328760(FxBase* self);
void fn_80377408(void* p);
void fn_80328858(void* a, int b, int c);
void fn_80321628(void* a, int b);
void fn_80320DD0(void* a, int b);
void fn_80329AAC(FxSing* p, int a);
int fn_802B96C4(void* a, int b);
int fn_802B9300(void* a, int b, int c, int d);
void fn_803EDA0C();
// PROTOS-BEGIN
void fn_80327214(FxAI* self);
void fn_80327274(FxAI* self);
int fn_803272D0(FxAI* self, unsigned i);
void fn_803272F0(FxAI* self);
void fn_80328208();
FxBase* fn_80328234(FxBase* self, int a, int b);
FxBase* fn_803282A8(FxBase* self, int a);
void fn_80328318(FxBase* self, int a, int b);
void fn_80328374(FxBase* self, int a);
int fn_803283D8(int a, int b, int* idx, int* out);
void fn_8032847C(int p);
int fn_803285A0(int n);
int fn_803285F4(int n);
int fn_80328648(int n);
void fn_803289C0(int a);
void fn_80329498();
void fn_803296AC();
void fn_803296BC(int a);
int fn_803296E8();
void fn_80329924(FxSing* self, int a);
FxSing* fn_80329988();
void fn_80329A50();
void fn_80329AA8();
void fn_80329AAC(FxSing* p, int a);
void fn_80329AE0();
int fn_80329AE4();
int fn_80329DF0(void* a, int* out, int c);
int fn_80329E50();
void fn_8032A0C0(FxMS* out, int t);
int fn_8032A118(FxMS* p);
unsigned char fn_8032A2CC(int a, int b);
int fn_8032A338(unsigned y);
// PROTOS-END
}

// FUNCS-BEGIN

void fn_80327214(FxAI* self) {
    fn_803272F0(self);
    int old = self->m4B8;
    if (old) {
        int idx = 0;
        self->m4B8 = idx;
        FxZT* t = (&self->m0)[idx];
        if (t) fn_80325000(t);
        fn_8032713C(self, old, self->m4B8);
    }
}

void fn_80327274(FxAI* self) {
    int old = self->m4B8;
    if (old != 1) {
        FxZT* t = self->m4;
        self->m4B8 = 1;
        if (t) fn_80325000(t);
        fn_8032713C(self, old, self->m4B8);
    }
}

int fn_803272D0(FxAI* self, unsigned i) {
    if (i <= 0xC) return self->a4C0[i];
    return 0;
}

void fn_803272F0(FxAI* self) {
    Unk8006A138_It<0x15> it(0);
    int i = 0;
    do {
        int v;
        if ((unsigned)i > 0xC) v = 0;
        else v = self->m4BC->a65C[i];
        self->a4C0[it.v] = v;
        i = it.Next();
    } while (i <= 0xC);
}

void fn_80328208() { fn_80327354(1, 0xFFFF); }

FxBase* fn_80328234(FxBase* self, int a, int b) {
    self->m14 = 0;
    self->m18 = lbl_80664020;
    fn_8040B61C(self, lbl_805EBBF8);
    self->m20 = 0;
    self->m18 = lbl_80666F98;
    fn_80328318(self, a, b);
    return self;
}

FxBase* fn_803282A8(FxBase* self, int a) {
    self->m14 = 0;
    self->m18 = lbl_80664020;
    fn_8040B61C(self, lbl_805EBBF8);
    self->m20 = 0;
    self->m18 = lbl_80666F98;
    fn_80328318(self, 0x13, a);
    return self;
}

void fn_80328318(FxBase* self, int a, int b) {
    fn_8032847C(b);
    self->m1C = b;
    if (a != 0 && self->m20 == 0) fn_80328690(self, a);
}

void fn_80328374(FxBase* self, int a) {
    self->m18 = lbl_80666F98;
    if (self->m20 != 0) fn_80328760(self);
    self->m18 = lbl_80664020;
    if (a & 1) fn_80377408(self);
}

int fn_803283D8(int a, int b, int* idx, int* out) {
    int i = *idx;
    if (i <= 0) {
        *idx = lbl_806E2184[a][b];
    } else {
        if (lbl_806E2274[i].m0 != 0 && lbl_806E2274[i].m4 > 0) {
            *idx = lbl_806E2274[i].m4;
        } else {
            *out = 0;
            return 0;
        }
    }
    if (*idx > 0) {
        *out = lbl_806E2274[*idx].m0;
        return 1;
    }
    *out = 0;
    return 0;
}

void fn_8032847C(int p) {
    if (p != 0) {
        if (fn_803285F4(p) < 0) {
            for (int i = 1; i <= 2; i++) {
                if (lbl_806E2A44[i] == 0) {
                    lbl_806E2A44[i] = p;
                    lbl_806202EC = lbl_806202EC + 1;
                    fn_80328318((FxBase*)p, 0x11, p);
                    return;
                }
            }
        }
    }
}

int fn_803285A0(int n) {
    if (n == 0) return 0;
    int cnt = 0;
    for (int i = 1; i <= 2; i++) {
        int v = lbl_806E2A44[i];
        if (v != 0) cnt++;
        if (cnt == n) return v;
    }
    return 0;
}

int fn_803285F4(int n) {
    if (n == 0) return 0;
    int cnt = 0;
    for (int i = 1; i <= 2; i++) {
        int v = lbl_806E2A44[i];
        if (v != 0) cnt++;
        if (v == n) return cnt;
    }
    return -1;
}

int fn_80328648(int n) {
    if (n == 0) return 0;
    for (int i = 0; i < 3; i++) {
        if (lbl_806E2A44[i] == n) return i;
    }
    return -1;
}

void fn_803289C0(int a) { fn_80328858(&lbl_806202A8, 0x11, a); }

void fn_80329498() {
    lbl_806202F4 = 1;
    fn_80321628(&lbl_80691AEC, lbl_806202FC);
    lbl_806202F4 = 0;
    lbl_806202FC = 0;
}

void fn_803296AC() { lbl_806202FC = 1; }

void fn_803296BC(int a) { fn_80320DD0(&lbl_80691AEC, a); }

int fn_803296E8() {
    int i = lbl_806202F0;
    if (i <= 0xF9) {
        do {
            if (lbl_806E2274[i].m0 == 0) return i;
            i++;
        } while (i <= 0xF9);
    }
    for (i = 0; i < 0xFA; i++) {
        if (lbl_806E2274[i].m0 == 0) return i;
    }
    return 0;
}

// fn_80329908
FxSing::FxSing() {
    m8 = lbl_80665E60;
    m4 = 0;
}

void fn_80329924(FxSing* self, int a) {
    self->m8 = lbl_80665E60;
    if (self->m4) {
        fn_80329AAC((FxSing*)self->m4, 3);
        self->m4 = 0;
    }
    if (a & 1) fn_80377408(self);
}

FxSing* fn_80329988() {
    if (lbl_80620304 == 0) {
        lbl_80620304 = new (0) FxSing;
    }
    return lbl_80620304;
}

void fn_80329A50() {
    FxSingV* o = (FxSingV*)lbl_80620304;
    if (o) {
        delete o;
        lbl_80620304 = 0;
    }
}

void fn_80329AA8() {}

void fn_80329AAC(FxSing* p, int a) {
    *(int*)((char*)p + 0x23674) = 0;
    if (a & 1) fn_80377408(p);
}

void fn_80329AE0() {}

int fn_80329AE4() { return 0; }

int fn_80329DF0(void* a, int* out, int c) {
    if (fn_802B96C4(a, 0)) {
        *out = fn_802B9300(a, 0x500, 0xE, c);
        return 1;
    }
    return 0;
}

int fn_80329E50() {
    fn_803EDA0C();
    return 1;
}

void fn_8032A0C0(FxMS* out, int t) {
    FxMS r;
    r.m = 0;
    r.s = 0;
    r.m = t / 60;
    r.s = t - r.m * 60;
    *out = r;
}

int fn_8032A118(FxMS* p) {
    unsigned short v = *(unsigned short*)p;
    return (v >> 8) * 60 + (v & 0xFF);
}

unsigned char fn_8032A2CC(int a, int b) {
    if (a == 1) {
        int v = lbl_805F340C[a];
        if (fn_8032A338(b) == 1) return v + 1;
        return v;
    }
    return lbl_805F340C[a];
}

int fn_8032A338(unsigned y) {
    if ((y & 3) == 0) {
        unsigned short r1 = y % 100;
        if (r1 == 0) {
            unsigned short r2 = y % 400;
            return r2 == 0;
        }
        return 1;
    }
    return 0;
}
