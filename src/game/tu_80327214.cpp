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
extern char lbl_80691D18[];
extern FxApp* lbl_8061B8C0;
extern int lbl_8061B998;
extern int lbl_80620360;
extern const float lbl_805ECABC;
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
FxDate fn_80329FA0(char* p);
int fn_8032A130(int a, int b, int c);
void fn_80378D70(char* src, unsigned n, char* dst, int cap, int delim, int* outLen);
void fn_80379094(char* s, int len, int a);
double fn_80409D88(const char* s);
int fn_80409DAC(const char* s);
void fn_801A750C(void* v, int a);
float fn_801C337C(void* p, int a);
void fn_801A0790(FxView* v, float f);
void fn_80331294(void* p);
void fn_802D7ACC();
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
void fn_8032850C(int p);
int fn_803285A0(int n);
int fn_803285F4(int n);
int fn_80328648(int n);
void fn_80328690(FxBase* self, int a);
void fn_80328760(FxBase* self);
void fn_803289C0(int a);
void fn_80329498();
void fn_803296AC();
void fn_803296BC(int a);
int fn_803296E8(void* unused);
void fn_80329924(FxSing* self, int a);
FxSing* fn_80329988();
void fn_803299D4(FxSing* self);
void fn_80329A50();
void fn_80329AA8(void* p);
void fn_80329AAC(FxSing* p, int a);
void fn_80329AE0(void* p);
int fn_80329AE4(void* p);
void fn_80329AEC(char** cur, const char** out, unsigned* n, int delim);
int fn_80329B98(char** cur, unsigned* n, float* out, int delim);
int fn_80329C4C(char** cur, unsigned* n, int* out, int lo, int hi, int delim);
int fn_80329D1C(char** cur, unsigned* n, unsigned* out, unsigned lo, unsigned hi, int delim);
int fn_80329DF0(void* a, int* out, int c);
int fn_80329E50();
FxMS fn_8032A0C0(int t);
int fn_8032A118(FxMS v);
int fn_8032A130(int month0, int day, int year);
int fn_8032A1EC(int kind);
int fn_8032A278(int t);
unsigned char fn_8032A2CC(int a, int b);
int fn_8032A338(unsigned y);
char* fn_8032A394(char* base, int target);
void fn_8032ABC8();
// PROTOS-END
}

// FUNCS-BEGIN

/* near-miss: retail indexes the table with a zero register (lwzx r3,r31,r0) */
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

/* near-miss: iterator body order */
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

/* near-miss: same as the neighbouring function */
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

/* near-miss: retail keeps two copies of the fail block */
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

void fn_8032850C(int p) {
    if (p != 0) {
        int idx = fn_80328648(p);
        fn_80328760((FxBase*)p);
        if (idx >= 0) {
            for (int k = 0; k < 20; k++) lbl_806E2184[idx][k] = 0;
            lbl_806E2A44[idx] = 0;
            lbl_806202EC = lbl_806202EC - 1;
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

/* near-miss: retail keeps two separate -1 constants (list tail index in r29, search cursor stored to sp+8); ours merges them */
void fn_80328690(FxBase* self, int a) {
    self->m20 = a;
    int last = -1;
    int row = fn_80328648(self->m1C);
    int cur = -1;
    int tmp;
    while (fn_803283D8(row, a, &cur, &tmp)) last = cur;
    cur = fn_803296E8(self);
    if (last > 0) lbl_806E2274[last].m4 = cur;
    else lbl_806E2184[row][a] = cur;
    lbl_806E2274[cur].m4 = 0;
    lbl_806E2274[cur].m0 = (int)self;
}

/* near-miss: loop shape matches (goto form keeps it unrotated); retail shares one lis for the slot table across the unlink stores, ours emits it twice */
void fn_80328760(FxBase* self) {
    int row = fn_80328648(self->m1C);
    if (row >= 0) {
        int a = self->m20;
        int cur = -1;
        int prev = -1;
        int tmp;
    again:
        if (fn_803283D8(row, a, &cur, &tmp)) {
            if (tmp == (int)self) {
                int nxt = lbl_806E2274[cur].m4;
                if (prev > 0) lbl_806E2274[prev].m4 = nxt;
                else lbl_806E2184[row][a] = nxt;
                lbl_806E2274[cur].m4 = 0;
                lbl_806E2274[cur].m0 = 0;
            } else {
                prev = cur;
                goto again;
            }
        }
        if (cur > 0 && cur < lbl_806202F0) lbl_806202F0 = cur;
    }
}

void fn_803289C0(int a) { fn_80328858(&lbl_806202A8, 0x11, a); }

/* near-miss: callee-saved lis registers for lbl_806202FC / lbl_806202F4 swapped */
void fn_80329498() {
    lbl_806202F4 = 1;
    fn_80321628(&lbl_80691AEC, lbl_806202FC);
    lbl_806202F4 = 0;
    lbl_806202FC = 0;
}

void fn_803296AC() { lbl_806202FC = 1; }

void fn_803296BC(int a) { fn_80320DD0(&lbl_80691AEC, a); }

int fn_803296E8(void* unused) {
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

/* near-miss: tail shape */
void fn_803299D4(FxSing* self) {
    if (self->m4) {
        if (fn_80329AE4((void*)self->m4) && *(int*)self->m4 != 0xB) {
            fn_80329AE0((void*)self->m4);
        } else {
            if (self->m4) fn_80329AAC((FxSing*)self->m4, 3);
            self->m4 = 0;
            fn_80329AA8(self);
        }
    }
}

void fn_80329A50() {
    FxSingV* o = (FxSingV*)lbl_80620304;
    if (o) {
        delete o;
        lbl_80620304 = 0;
    }
}

void fn_80329AA8(void* p) {}

void fn_80329AAC(FxSing* p, int a) {
    *(int*)((char*)p + 0x23674) = 0;
    if (a & 1) fn_80377408(p);
}

void fn_80329AE0(void* p) {}

int fn_80329AE4(void* p) { return 0; }

void fn_80329AEC(char** cur, const char** out, unsigned* n, int delim) {
    int len = 0;
    *out = 0;
    fn_80378D70(*cur, *n, lbl_80691D18, 0x80, delim, &len);
    if ((unsigned)len < *n) {
        fn_80379094(lbl_80691D18, len, 0);
        *cur = *cur + len + 1;
        *n -= 1;
        *n -= len;
        *out = lbl_80691D18;
    } else {
        *n = 0;
    }
}

int fn_80329B98(char** cur, unsigned* n, float* out, int delim) {
    int len = 0;
    fn_80378D70(*cur, *n, lbl_80691D18, 0x80, delim, &len);
    if ((unsigned)len < *n) {
        fn_80379094(lbl_80691D18, len, 0);
        *out = fn_80409D88(lbl_80691D18);
        *cur = *cur + len + 1;
        *n -= 1;
        *n -= len;
    } else {
        *n = 0;
    }
    return 1;
}

int fn_80329C4C(char** cur, unsigned* n, int* out, int lo, int hi, int delim) {
    int len = 0;
    int ok = 1;
    fn_80378D70(*cur, *n, lbl_80691D18, 0x80, delim, &len);
    if ((unsigned)len < *n) {
        fn_80379094(lbl_80691D18, len, 0);
        *out = fn_80409DAC(lbl_80691D18);
        if (*out < lo || *out > hi) ok = 0;
        *cur = *cur + len + 1;
        *n -= 1;
        *n -= len;
    } else {
        *n = 0;
    }
    return ok;
}

/* near-miss: same as the neighbouring function */
int fn_80329D1C(char** cur, unsigned* n, unsigned* out, unsigned lo, unsigned hi, int delim) {
    int len = 0;
    int ok = 1;
    fn_80378D70(*cur, *n, lbl_80691D18, 0x80, delim, &len);
    if ((unsigned)len < *n) {
        fn_80379094(lbl_80691D18, len, 0);
        unsigned v = fn_80409DAC(lbl_80691D18);
        if (v < lo || v > hi) ok = 0;
        else *out = v;
        *cur = *cur + len + 1;
        *n -= 1;
        *n -= len;
    } else {
        *n = 0;
    }
    return ok;
}

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

FxMS fn_8032A0C0(int t) {
    FxMS r;
    FxMS* p = &r;
    r.m = 0;
    p->s = 0;
    r.m = t / 60;
    p->s = t - r.m * 60;
    return r;
}

int fn_8032A118(FxMS v) {
    unsigned short h = *(unsigned short*)&v;
    return (h >> 8) * 60 + (h & 0xFF);
}

int fn_8032A130(int month0, int day, int year) {
    int m = month0 + 1;
    int a = (14 - m) / 12;
    int y = year - a;
    int mm = m + 12 * a - 2;
    int d = day + y;
    return (d + y / 4 - y / 100 + y / 400 + (31 * mm) / 12) % 7;
}

int fn_8032A1EC(int kind) {
    FxMS r;
    FxMS* p = &r;
    r.m = 0;
    p->s = 0;
    r.m = 0xD;
    p->s = 5;
    switch (kind) {
    case 0:
        r.m = 0xD;
        p->s = 5;
        break;
    case 1:
        r.m = 0x12;
        p->s = 5;
        break;
    case 2:
        r.m = 0x13;
        p->s = 5;
        break;
    }
    return fn_8032A118(r);
}

int fn_8032A278(int t) {
    FxMS r = fn_8032A0C0(t);
    if (r.m > 0x10) {
        if ((unsigned)(r.m - 0x11) <= 1) return 1;
        return 2;
    }
    return 0;
}

/* near-miss: return value conversions (clrlwi) differ */
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

char* fn_8032A394(char* base, int target) {
    for (int i = 0; i <= 6; i++) {
        char* p = base + i;
        FxDate d = fn_80329FA0(p);
        unsigned w = *(unsigned*)&d;
        if (fn_8032A130((w >> 24) - 1, (w >> 16) & 0xFF, w & 0xFFFF) == target) return p;
    }
    return base;
}

void fn_8032ABC8() {
    FxView* v = lbl_8061B8C0->m8;
    if (v->m744->m20 == 0) fn_801A750C(v->m744, 1);
    fn_801A0790(v, fn_801C337C(v->m700->m3A4, lbl_80620360) - lbl_805ECABC);
    fn_80331294((char*)lbl_8061B998 + 0x24);
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}
