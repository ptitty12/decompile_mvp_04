/*
 * Game code, .text 0x8032ECD8-0x80331C60 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern const char lbl_805ED9C0[];
extern const char lbl_805ED9AC[];
extern const char lbl_805EDA04[];
extern const void* const lbl_80666C90[];
extern const void* const lbl_80666BD8[];
extern const char lbl_805ED9E8[];
extern const char lbl_805ED9F0[];
extern const char lbl_805ED9F4[];
extern const float lbl_805ED9F8;
extern const float lbl_805EDAAC;
extern const float lbl_805EDAB0;
extern const float lbl_805EDAB4;
extern const void* const lbl_80666C40[];
extern const void* const lbl_80666B70[];
extern const void* const lbl_80666A18[];
extern const void* const lbl_806669C8[];
extern int lbl_806204F4;
extern int lbl_806204F8;
extern int lbl_806204FC;
extern int lbl_80620500;
extern FxBlk44 lbl_80691B14;
extern FxBlk44 lbl_80691B5C;
extern FxBlk44 lbl_80691BA4;
extern float lbl_80691B58;
extern float lbl_80691BA0;
extern float lbl_80691BE8;
extern FxApp* lbl_8061B8C0;
extern int lbl_8061B998;
extern FxCtx* lbl_8061FEDC;
extern char** lbl_80691DC4;
extern FxModal* lbl_80620410;
extern int lbl_80620414;
extern int lbl_8062042C;
extern int lbl_8061EDFC;
extern int lbl_80620298;
extern int lbl_8061EDC0;
extern int lbl_8061FE90;
extern int lbl_8061FDCC;
extern int lbl_8068B4BC;
extern int lbl_8061FE94;
extern int lbl_8061FE9C;
extern int lbl_8061C8F8;
extern int lbl_80620134;
extern int lbl_8061B898;

extern "C" void fn_8032D868(void* self, int a);
/* Inlined mid-level widget ctor (vtable lbl_80666E70): root, mC = 0, set the name. */
inline void FxWidInit(FxListD* self, int name) {
    FxRootInit(self);
    *(const void**)((char*)self + 8) = lbl_80666E70;
    self->mC = 0;
    fn_8032D868(self, name);
}
/* Polymorphic int ring (vptr lbl_8064B298 at +0x10; see Unk80353E68 in tu_8034B370.h). */
struct FxRingI {
    int* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    const void* m10;
};
extern "C" void fn_8040074C(void* p, unsigned n); /* bzero */
extern const void* const lbl_8064B298[];
extern const void* const lbl_80666A68[];
inline void FxRingInit(FxRingI* r, int* buf, int n) {
    r->m10 = lbl_8064B298;
    r->m0 = buf;
    r->m8 = n;
    fn_8040074C(r->m0, r->m8 << 2);
    r->m4 = 0;
    r->mC = 0;
}
/* Widget with a 10-entry ring at +0x48 (inline buffer at +0x64; vtable lbl_80666A68,
 * ctor fn_803302D4). */
class FxRingW : public FxListV {
public:
    int mC;
    char pad10[0x38];
    FxRingI m48;
    int m5C;
    int m60;
    int m64[10];
};

struct FxViewB { int pad[3]; int mC; int m10; char pad14[0x60]; FxWid3* m74; };

class FxElemV { public: virtual void s1(int); };
class FxListE : public FxListD {
public:
    FxElemV* m64[2];
    unsigned m6C;
};
class FxItemV {
public:
    char pad0[8];
    virtual ~FxItemV();
    virtual void s2();
    virtual void s3();
    virtual void s4();
};
struct FxStackH {
    FxItemV* a0[93];
    int m174;
    int m178;
};
struct Unk802CBD04;
struct FxBlk48 { FxBlk44 b; float m44; };
float fn_802CBD90(Unk802CBD04* o);
struct FxSaved { int v; ~FxSaved() {} };
extern const char lbl_805EDA10[];
extern const char lbl_805EDA14[];
extern const char lbl_805EDA18[];
extern const char lbl_805EDA1C[];
extern const char lbl_805EDA24[];
extern const char lbl_805EDA30[];
extern const float lbl_805EDA38;
extern const float lbl_805EDA3C;
extern "C" {
float fn_80313F28(FxCtx* c, const void* s);
void fn_803144A0(FxCtx* c, const char* s, float x, float y, int a, int b);
void fn_8032D8D0(void* self);
int fn_8032D8C8();
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_8032D868(void* self, int a);
int fn_8040B6A0(const char* s);
int fn_8040B750(const char* a, const char* b, int n);
FxListD* fn_8032F38C(FxListD* self, int a, int b, int c, int d, int e);
FxListD* fn_8032F428(FxListD* self, int a, int b, int c, int d);
void fn_803E4B40(void* p, int a);
void fn_80377408(void* p);
void* fn_803774A8(unsigned size, int heap);
void fn_80377488(void* p);
void fn_8040A208(void* base, int n, int size, int (*cmp)(int*, int*));
void fn_8035F8CC(void* idx, int a, int n);
void fn_8035F95C(void* idx, char** names, int n);
void fn_802D8294(int a);
void fn_801A750C(void* v, int a);
void fn_802D7ACC();
void fn_8033E6DC();
void fn_80331508();
FxViewB* fn_801A4CE8(FxView* v, int a);
void fn_802CBDBC(void* w, void* b, int a, int c);
int fn_8040B574(const char* a, const char* b);
// PROTOS-BEGIN
FxRingW* fn_803302D4(FxRingW* self, int a, int b);
FxIntD* fn_8032ECD8(FxIntD* self, int a, int b, int c, int d);
FxListD* fn_8032F19C(FxListD* self, int a, int* b, int c);
FxListD* fn_8032F4CC(FxListD* self, int a, int b, int c);
void fn_8032ED80(FxListD* self);
FxListD* fn_8032F120(FxListD* self, int a, int b);
void fn_8032F22C(FxListD* self);
void fn_8032F574(FxListD* self, int a);
void fn_8032F5AC(FxListD* self);
int fn_8032F5C4(FxListD* self, int k);
int fn_8032F620(FxListD* self, int k);
int fn_8032F684(FxListD* self, int a, int b);
FxListD* fn_8032FA3C(FxListD* self, int a, int b, int c, int* p, int d, int n);
FxListD* fn_8032FAB0(FxListD* self, int a, int b, int* p, int c, int n);
void fn_8032FB24(FxListD* self);
void fn_8032FB78(FxListD* self, int a);
int fn_8032FBCC(int* a, int* b);
void fn_8032FC0C(int a, char** names, int n);
void fn_8032FF54(FxCmd2* self, int a);
int fn_80330018(FxCmd* self, int k);
void fn_80330778(FxStackG* self, int a);
void fn_80330870(FxModal* self, int a);
void fn_80330ACC(FxStack* self, int v);
void fn_80330B08(FxStack* self, int v);
void fn_80330B48(FxModal* self);
void fn_80331234(FxModal* self);
void fn_80331294(FxModal* self);
void fn_803312E0(FxStackF* self);
float fn_80331394();
void fn_803313A0();
void fn_8033140C();
void fn_80331468();
void fn_803314B8();
void fn_80331508();
void fn_80331548();
void fn_80331568();
void fn_803318CC();
void fn_80331918();
void fn_80331A30();
void fn_80331B48();
void fn_8032FCC0(FxListE* self);
int fn_8032F2E0(FxListD* self, int k);
int fn_80330384(FxCmd* self, int k);
void fn_80330BC8(FxStackH* self, int d);
void fn_803315E8();
void fn_803316DC();
void fn_803317D4();
int fn_8032F71C(FxListD* self, int k);
void fn_8032F8A4(FxListD* self);
void fn_8032D8F8(void* self, float w);
char* fn_8040B830(char* dst, const char* src, int n);
// PROTOS-END
}

// FUNCS-BEGIN

FxIntD* fn_8032ECD8(FxIntD* self, int a, int b, int c, int d) {
    FxWidInit((FxListD*)self, (int)lbl_805ED9AC);
    self->m50 = b;
    *(const void**)((char*)self + 8) = lbl_80666C90;
    self->m58 = c;
    self->m5C = d;
    self->m48 = 0;
    self->m54 = a;
    self->m60 = 1;
    self->m64 = 0;
    self->m4C = a;
    return self;
}

/* near-miss: argument evaluation order and frame size */
void fn_8032ED80(FxListD* self) {
    char buf[0x30];
    int t = self->s6();
    fn_804089B4(buf, lbl_805ED9C0, t, self->m48 == 0 ? self->m4C : *self->m48);
    fn_80313F28(lbl_8061FEDC, buf);
}

FxListD* fn_8032F120(FxListD* self, int a, int b) {
    FxRootInit(self);
    *(const void**)((char*)self + 8) = lbl_80666E70;
    self->mC = 0;
    fn_8032D868(self, a);
    self->m48 = 0;
    self->m50 = b;
    *(const void**)((char*)self + 8) = lbl_80666C40;
    self->m4C = b;
    return self;
}

FxListD* fn_8032F19C(FxListD* self, int a, int* b, int c) {
    FxWidInit(self, a);
    self->m48 = b;
    self->m50 = c;
    *(const void**)((char*)self + 8) = lbl_80666C40;
    if (b) *b = c;
    else self->m4C = c;
    return self;
}

void fn_8032F22C(FxListD* self) {
    char buf[0x30];
    int v = self->m48 ? *self->m48 : self->m4C;
    fn_804089B4(buf, lbl_805ED9E8, v ? lbl_805ED9F0 : lbl_805ED9F4);
    float w = lbl_805ED9F8 - fn_80313F28(lbl_8061FEDC, buf);
    fn_8032D8D0(self);
    fn_803144A0(lbl_8061FEDC, buf, w, self->m4, self->mC, 0x16);
}

int fn_8032F2E0(FxListD* self, int k) {
    int r = fn_8032D8C8();
    if (r == 0) {
        int* p = self->m48;
        int v = p ? *p : self->m4C;
        switch (k) {
        case 3:
        case 4:
            v ^= 1;
            if (self->m48) *self->m48 = v;
            else self->m4C = v;
            return 1;
        case 7:
            v = self->m50;
            if (self->m48) *self->m48 = v;
            else self->m4C = v;
            return r;
        }
        r = 0;
    }
    return r;
}

FxListD* fn_8032F38C(FxListD* self, int a, int b, int c, int d, int e) {
    FxWidInit(self, a);
    self->m48 = (int*)b;
    self->m50 = c;
    self->m54 = d;
    self->m58 = 0;
    self->m5C = e;
    *(const void**)((char*)self + 8) = lbl_80666BD8;
    fn_8032F574(self, e);
    return self;
}

FxListD* fn_8032F428(FxListD* self, int a, int b, int c, int d) {
    FxWidInit(self, a);
    self->m48 = 0;
    self->m4C = 0;
    self->m50 = b;
    self->m54 = c;
    self->m58 = 0;
    self->m5C = d;
    *(const void**)((char*)self + 8) = lbl_80666BD8;
    if (c > 0) fn_8032F574(self, d);
    return self;
}

FxListD* fn_8032F4CC(FxListD* self, int a, int b, int c) {
    FxWidInit(self, (int)lbl_805EDA04);
    self->m48 = 0;
    self->m50 = a;
    self->m54 = b;
    self->m58 = 0;
    self->m5C = c;
    *(const void**)((char*)self + 8) = lbl_80666BD8;
    if (b > 0) fn_8032F574(self, c);
    return self;
}

void fn_8032F574(FxListD* self, int a) {
    self->m4C = a;
    self->s11();
}

void fn_8032F5AC(FxListD* self) {
    if (self->m48) *self->m48 = self->m4C;
}

int fn_8032F5C4(FxListD* self, int k) {
    while (k > 0) {
        int j = k - 1;
        if (fn_8032F684(self, j, k) == 0) break;
        k = j;
    }
    return k;
}

int fn_8032F620(FxListD* self, int k) {
    while (k < self->m54 - 1) {
        int j = k + 1;
        if (fn_8032F684(self, k, j) == 0) break;
        k = j;
    }
    return k;
}

/* near-miss: one instruction; retail copies the first length into the min register before the compare (cmpw r5,r3), ours compares the saved register directly */
int fn_8032F684(FxListD* self, int a, int b) {
    int la = fn_8040B6A0(((char**)self->m50)[a]);
    int lb = fn_8040B6A0(((char**)self->m50)[b]);
    int n;
    if (la > lb) n = lb; else n = la;
    if (n < self->m58) { if (la != lb) return 0; }
    if (n > self->m58) n = self->m58;
    return !fn_8040B750(((char**)self->m50)[a], ((char**)self->m50)[b], n);
}

int fn_8032F71C(FxListD* self, int k) {
    int r = fn_8032D8C8();
    int cur = self->m4C;
    if (r == 0) {
        r = 1;
        switch (k) {
        case 3:
            if (cur > 0) {
                int n = cur - 1;
                if (fn_8032F684(self, cur, n) != 0) cur = n;
            }
            break;
        case 4:
            if (cur < self->m54 - 1) {
                int n = cur + 1;
                if (fn_8032F684(self, cur, n) != 0) cur = n;
            }
            break;
        case 6:
            cur = fn_8032F620(self, cur);
            break;
        case 9:
            cur = fn_8032F620(self, cur);
            if (cur < self->m54 - 1) cur++;
            break;
        case 8:
            cur = fn_8032F5C4(self, cur);
            if (cur > 0) cur--;
        case 5:
            cur = fn_8032F5C4(self, cur);
            break;
        case 13:
            if (self->m58 > 0) self->m58 = self->m58 - 1;
            break;
        case 14:
            self->m58 = self->m58 + 1;
            break;
        case 7:
            cur = self->m5C;
            break;
        default:
            r = 0;
        }
        fn_8032F574(self, cur);
    }
    return r;
}

void fn_8032F8A4(FxListD* self) {
    char buf[0x40];
    char a[0x38];
    char b[0x38];
    int cur = self->m4C;
    const char* post = lbl_805EDA10;
    const char* pre = post;
    if (cur > 0) pre = lbl_805EDA14;
    if (cur < self->m54 - 1) post = lbl_805EDA18;
    int names = self->m50;
    if (names) {
        char* s = *(char**)(names + cur * 4);
        if (self->m58 > 0) {
            int rest = fn_8040B6A0(s) - self->m58;
            if (rest < 0) {
                fn_804089B4(buf, lbl_805EDA1C, pre, s, post);
            } else {
                fn_8040B830(a, s, self->m58);
                a[self->m58] = 0;
                fn_8040B830(b, s + self->m58, rest);
                b[rest] = 0;
                fn_804089B4(buf, lbl_805EDA24, pre, a, b, post);
            }
        } else {
            fn_804089B4(buf, lbl_805EDA30, pre, s, post);
        }
    }
    float w = lbl_805EDA38 - fn_80313F28(lbl_8061FEDC, buf);
    if (!(w >= lbl_805EDA3C)) w = lbl_805EDA3C;
    fn_8032D8F8(self, w);
    fn_803144A0(lbl_8061FEDC, buf, w, self->m4, self->mC, 0x16);
}

FxListD* fn_8032FA3C(FxListD* self, int a, int b, int c, int* p, int d, int n) {
    fn_8032F38C(self, a, b, c, d, 0);
    self->m60 = p;
    *(const void**)((char*)self + 8) = lbl_80666B70;
    if (n < 0) fn_8032FB78(self, *p);
    else fn_8032FB78(self, n);
    return self;
}

FxListD* fn_8032FAB0(FxListD* self, int a, int b, int* p, int c, int n) {
    fn_8032F428(self, a, b, c, 0);
    self->m60 = p;
    *(const void**)((char*)self + 8) = lbl_80666B70;
    if (n < 0) fn_8032FB78(self, *p);
    else fn_8032FB78(self, n);
    return self;
}

void fn_8032FB24(FxListD* self) {
    if (self->m48) *self->m48 = self->s9();
}

void fn_8032FB78(FxListD* self, int a) {
    for (int i = 0; i < self->m54; i++) {
        if (self->m60[i] == a) {
            fn_8032F574(self, i);
            break;
        }
    }
}

int fn_8032FBCC(int* a, int* b) {
    return fn_8040B574(lbl_80691DC4[*a], lbl_80691DC4[*b]);
}

void fn_8032FC0C(int a, char** names, int n) {
    int* idx = (int*)fn_803774A8(n * 4, 0x100);
    for (int i = 0; i < n; i++) idx[i] = i;
    lbl_80691DC4 = names;
    fn_8040A208(idx, n, 4, fn_8032FBCC);
    fn_8035F8CC(idx, a, n);
    fn_8035F95C(idx, names, n);
    if (idx) fn_80377488(idx);
}

void fn_8032FCC0(FxListE* self) {
    unsigned i = 0;
    fn_8032FB24(self);
    for (; i < self->m6C; i++) {
        self->m64[i]->s1(self->s9());
    }
}

/* near-miss: body matches but the register pair is swapped (retail self=r31, embedded pointer=r30); tried keeping the pointer lazy, member access (turns the calls static), and bound/operand order */
void fn_8032FF54(FxCmd2* self, int a) {
    FxEmb2* e = (FxEmb2*)((char*)self + 0x48);
    e->v0();
    self->m68 = 0;
    while (self->m68 < e->m4 && e->v2() != a) {
        e->v9();
        self->m68++;
    }
    e->v11(self->m68);
}

/* near-miss: switch tree (retail splits at <3 / >4 and reuses the compare with 3 in cr7) */
int fn_80330018(FxCmd* self, int k) {
    int r = fn_8032D8C8();
    if (r == 0) {
        switch (k) {
        case 3:
            ((FxEmb*)((char*)self + 0x48))->s7();
            r = 1;
            break;
        case 4:
            ((FxEmb*)((char*)self + 0x48))->s6();
            r = 1;
            break;
        case 7:
            r = 1;
            break;
        }
    }
    return r;
}

/* near-miss (2 slots): retail stores the vptr before m5C; every order of the tail
 * stores gives m5C first or swaps the ring/vtable registers (r28/r29) */
FxRingW* fn_803302D4(FxRingW* self, int a, int b) {
    FxWidInit((FxListD*)self, a);
    FxRingInit(&self->m48, self->m64, 10);
    self->m48.m10 = lbl_8064B298;
    self->m5C = 0;
    *(const void**)((char*)self + 8) = lbl_80666A68;
    self->m60 = b;
    return self;
}

int fn_80330384(FxCmd* self, int k) {
    int r = ((int (*)(FxCmd*, int))fn_8032D8C8)(self, k);
    if (r == 0) {
        r = 1;
        switch (k) {
        case 3:
            if (((FxEmb*)((char*)self + 0x48))->s4())
                ((FxEmb*)((char*)self + 0x48))->s2();
            else
                ((FxEmb*)((char*)self + 0x48))->s7();
            break;
        case 4:
            ((FxEmb*)((char*)self + 0x48))->s6();
            break;
        case 7:
            break;
        default:
            r = 0;
        }
    }
    return r;
}

void fn_80330778(FxStackG* self, int a) {
    int i;
    *(const void**)((char*)self + 0x2DC) = lbl_806669C8;
    for (i = 0; i < self->m178; i++) {
        if (self->a0[i]) delete self->a0[i];
        self->a0[i] = 0;
    }
    for (i = 0; i < self->m1FC; i++) {
        if (self->a17C[i]) delete self->a17C[i];
        self->a17C[i] = 0;
    }
    fn_80330870((FxModal*)self, a);
}

/* near-miss: store order of lbl_80620410 / lbl_80620414 clears */
void fn_80330870(FxModal* self, int a) {
    *(const void**)((char*)self + 0x2DC) = lbl_80666A18;
    if (self == lbl_80620410) {
        lbl_80620414 = 0;
        lbl_80620410 = 0;
    }
    fn_803E4B40((char*)self + 0x210, 2);
    if (a & 1) fn_80377408(self);
}

void fn_80330ACC(FxStack* self, int v) {
    self->a0[self->m178] = v;
    self->m178 = self->m178 + 1;
    fn_803312E0((FxStackF*)self);
}

void fn_80330B08(FxStack* self, int v) {
    self->a17C[self->m1FC] = v;
    self->m1FC = self->m1FC + 1;
    fn_803312E0((FxStackF*)self);
}

void fn_80330B48(FxModal* self) {
    FxModal* cur = lbl_80620410;
    if (cur != 0 && lbl_80620414 != 0) cur->s3();
    lbl_80620410 = self;
    self->s2();
}

void fn_80330BC8(FxStackH* self, int d) {
    int lo = 1, hi = 2;
    if (d <= hi && d >= lo) {
        int old = self->m174;
        if (d == 1) self->m174 = old - 1;
        else self->m174 = old + 1;
        int v = self->m174;
        if (v < 0) self->m174 = 0;
        else if (v >= self->m178) self->m174 = self->m178 - 1;
        self->a0[old]->s3();
        self->a0[self->m174]->s2();
    } else {
        self->a0[self->m174]->s4();
    }
}

void fn_80331234(FxModal* self) {
    lbl_80620414 = 1;
    self->s2();
    if (lbl_8061EDFC) lbl_8062042C = lbl_8061EDFC;
    fn_802D8294(4);
}

void fn_80331294(FxModal* self) {
    lbl_80620414 = 0;
    self->s3();
    fn_802D8294(lbl_8062042C);
}

void fn_803312E0(FxStackF* self) {
    self->m20C = lbl_805EDAAC;
    for (int i = 0; i < self->m178; i++) {
        float v = self->a0[i]->s7();
        if (!(v <= self->m20C)) self->m20C = v;
    }
    self->m20C = self->m20C >? lbl_805EDAB0;
}

float fn_80331394() { return lbl_805EDAB4; }

void fn_803313A0() {
    FxView* v = lbl_8061B8C0->m8;
    int arg = 1;
    if (v->m744->m20 == 1) arg = 0;
    fn_801A750C(v->m744, arg);
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_8033140C() {
    int t = 1;
    if (lbl_80620298 == 1) t = 0;
    lbl_80620298 = t;
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_80331468() {
    FxApp* a = lbl_8061B8C0;
    a->m20 = 3;
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    a->m24 = 0;
    fn_802D7ACC();
}

void fn_803314B8() {
    FxApp* a = lbl_8061B8C0;
    a->m20 = 1;
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    a->m24 = 0;
    fn_802D7ACC();
}

void fn_80331508() {
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_80331548() { fn_8033E6DC(); }

void fn_80331568() {
    lbl_8061EDC0 = 0;
    FxView* v = lbl_8061B8C0->m8;
    int t = 1;
    if (fn_801A4CE8(v, 1)->mC == 1) t = 0;
    fn_801A4CE8(v, 1)->m10 = 0;
    fn_801A4CE8(v, 1)->mC = t;
    fn_80331508();
}

void fn_803315E8() {
    FxWid3* w = fn_801A4CE8(lbl_8061B8C0->m8, 1)->m74;
    if (w) {
        FxBlk44* b = w->mA0;
        FxSaved s;
        s.v = lbl_80691B14.m0;
        lbl_80691B14 = *b;
        lbl_80691B14.m0 = s.v;
        ((FxBlk48*)&lbl_80691B14)->m44 = fn_802CBD90((Unk802CBD04*)w);
        lbl_806204F4 = 1;
        lbl_80620500 = 1;
    }
}

void fn_803316DC() {
    FxWid3* w = fn_801A4CE8(lbl_8061B8C0->m8, 1)->m74;
    if (w) {
        FxBlk44* b = w->mA0;
        FxSaved s;
        s.v = lbl_80691B5C.m0;
        lbl_80691B5C = *b;
        lbl_80691B5C.m0 = s.v;
        ((FxBlk48*)&lbl_80691B5C)->m44 = fn_802CBD90((Unk802CBD04*)w);
        lbl_806204F8 = 1;
        lbl_80620500 = 2;
    }
}

void fn_803317D4() {
    FxWid3* w = fn_801A4CE8(lbl_8061B8C0->m8, 1)->m74;
    if (w) {
        FxBlk44* b = w->mA0;
        FxSaved s;
        s.v = lbl_80691BA4.m0;
        lbl_80691BA4 = *b;
        lbl_80691BA4.m0 = s.v;
        ((FxBlk48*)&lbl_80691BA4)->m44 = fn_802CBD90((Unk802CBD04*)w);
        lbl_806204FC = 1;
        lbl_80620500 = 3;
    }
}

void fn_803318CC() {
    lbl_8068B4BC = 0;
    lbl_8061FE94 = 1;
    lbl_8061FE9C = 0;
    lbl_8061C8F8 = 0;
    lbl_8061FE90 = 1;
    lbl_80620134 = 0;
    lbl_8061B898 = 0;
    lbl_8061FDCC = 0;
}

/* near-miss: retail spills the saved first word to the stack (sp+8) around the 0x44-byte template copy; ours keeps it in a register */
void fn_80331918() {
    FxWid3* w = fn_801A4CE8(lbl_8061B8C0->m8, 1)->m74;
    if (w && lbl_806204F4) {
        FxBlk44* b = w->mA0;
        int saved = b->m0;
        *b = lbl_80691B14;
        b->m0 = saved;
        fn_802CBDBC(w, b, 1, 0);
        float f = lbl_80691B58;
        w->mA4 = f;
        fn_803318CC();
        lbl_80620500 = 1;
    }
}

/* near-miss: retail spills the saved first word to the stack (sp+8) around the 0x44-byte template copy; ours keeps it in a register */
void fn_80331A30() {
    FxWid3* w = fn_801A4CE8(lbl_8061B8C0->m8, 1)->m74;
    if (w && lbl_806204F8) {
        FxBlk44* b = w->mA0;
        int saved = b->m0;
        *b = lbl_80691B5C;
        b->m0 = saved;
        fn_802CBDBC(w, b, 1, 0);
        float f = lbl_80691BA0;
        w->mA4 = f;
        fn_803318CC();
        lbl_80620500 = 2;
    }
}

/* near-miss: retail spills the saved first word to the stack (sp+8) around the 0x44-byte template copy; ours keeps it in a register */
void fn_80331B48() {
    FxWid3* w = fn_801A4CE8(lbl_8061B8C0->m8, 1)->m74;
    if (w && lbl_806204FC) {
        FxBlk44* b = w->mA0;
        int saved = b->m0;
        *b = lbl_80691BA4;
        b->m0 = saved;
        fn_802CBDBC(w, b, 1, 0);
        float f = lbl_80691BE8;
        w->mA4 = f;
        fn_803318CC();
        lbl_80620500 = 3;
    }
}
