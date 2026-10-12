/*
 * Game code, .text 0x800ACDA0-0x800AF248 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAt1C {
    char pad0[0x1C];
    void* m1C;
};
struct UnkAt20F {
    char pad0[0x20];
    float m20;
};
struct UnkAtAA4 {
    char pad0[0xAA4];
    int mAA4;
};
struct UnkAtEF0 {
    char pad0[0xEF0];
    int mEF0;
};
struct UnkFEPair {
    int m0;
    int m4;
};
extern const float lbl_805B95B8;


class FEO8B {
public:
    char pad0[8];
    virtual void s1();
    virtual int s2(int a);
    virtual int s3();
    virtual void s4();
    virtual int s5();
    virtual int s6();
};
extern const float lbl_805B95A4;
extern const float lbl_805B96A0;
extern const float lbl_805B96A4;
extern const char lbl_8065B360[];
extern const char lbl_8065B268[];
extern const char lbl_8065B690[];
struct FEBarO {
    char pad0[0x10];
    float m10;
};
struct FEBar {
    char pad0[0x1C];
    FEBarO* m1C;
    float m20;
    float m24;
};

inline float Clamp01(float r)
{
    return !(r > 1.0f) ? (r >? 0.0f) : 1.0f;
}

/* reading the divisor through an inline puts the m24 load before the m20 load, as in retail */
inline float Dur(FEBar* s)
{
    return s->m24;
}

inline float Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

/* ratio u/d written to o->m10, 0.0f when d is not positive (inline body shared with tu_800AB0E8) */
inline void Ratio(FEBarO* o, float d, float u)
{
    if (!(d >= 0.0f)) {
        o->m10 = 0.0f;
    } else {
        o->m10 = u / d;
    }
}

struct UnkAt1C20 {
    char pad0[0x1C];
    void* m1C;
    float m20;
};
struct FEOb12 {
    int m0;
    int m4;
    const void* m8;
};
struct FE190 {
    char pad0[0x190];
    int m190;
};
struct FE6F8 {
    char pad0[0x10];
    FE190* m10;
};
struct FE6F8H {
    char pad0[0x6F8];
    FE6F8* m6F8;
};
extern "C" {
FEO8B* fn_800AB80C(void* t, int i, int j);
int fn_800AE150(char* self, int* oi, int* oj, int key);
void fn_800AD58C(char* self, int i, int j);
void fn_800AD6FC(char* self);
void fn_800AD1D4(char* self);
void fn_800AD838(void* p, float f);
void fn_800AB3F8(void* self);
int fn_800ABC30(void* t, int i);
void fn_8033E5C4(void* o, int a);
void fn_800ADE10(void* p);
void fn_800AD78C(void* p);
void fn_8033E4F0(void* p);
void fn_800AE574(void* p);
void* fn_800AF010(void* p, int k);
void fn_800ADCD8(void* p);
void fn_800ABC9C(void* p);
void fn_800AE944(void* p);
void* fn_800AEDDC(void* p);
int fn_80356C98(void* p);
void fn_8033E600(void* p, int c);
void fn_80377408(void* p);
}

extern const float lbl_805B966C;
extern const char lbl_805B962C[];
struct FEG554 {
    char pad0[0x554];
    int m554;
};
struct FEGrid {
    char pad0[0xA84];
    FEG554* mA84;
};
extern "C" void* fn_8014D8AC(int a, int b, const char* s, int c);

struct Unk8019F8C0_Owner;
struct Unk80084910_W;
int fn_801A2034(Unk8019F8C0_Owner* o, int k);
int fn_80086D34(Unk80084910_W* w, int h);
void fn_80086D24(Unk80084910_W* w, int h, int k);

struct FEObjAF {
    int m0;
    char pad4[0x34 - 4];
    int m34;
    FEV3Cz* m38;
    int m3C;
};
extern const char lbl_805B96C4[];
extern const char lbl_805B96D0[];
extern const char lbl_805B96DC[];
extern const char lbl_805B6F58[];
extern "C" void fn_8011A9B8(const char* a, int b, const char* c);

struct FEV4 {
    int m0;
    int m4;
    int m8;
    float mC;
};
extern FEV4 lbl_8068B588;
extern const float lbl_805B96AC;
extern const float lbl_805B96B0;

struct FEOb108 {
    int m0;
    int m4;
    const void* m8;
    char padC[0x58 - 0xC];
    const void* m58;
};
extern const char lbl_8065AF38[];
extern const char lbl_8065BA00[];
extern const char lbl_8065AC28[];
extern const char lbl_8065AC08[];
struct FEIT {
    char pad0[0x18];
    const void* m18;
};
extern "C" {
FEIT* fn_800AB1CC(FEIT* self, int* src, int n);
void fn_803569D8(void* p);
void fn_80356C68(void* p);
void fn_800B32A4(void* p);
void fn_800B385C(void* p);
void fn_800AB758(FEIT* t, int idx, int v);
}

struct FEOb150 {
    int m0;
    int m4;
    const void* m8;
    const void* mC;
    int m10;
    int m14;
    char pad18[4];
    const void* m1C;
    char pad20[0xDC - 0x20];
    int mDC;
};
extern const char lbl_8065B010[];
extern const char lbl_8065B9C0[];
extern const char lbl_8065B690[];
extern const char lbl_8065B280[];
extern const char lbl_8065B2D8[];
extern const char lbl_8065B298[];
/* Sub-object at +0x10 of FEOb150 (vptr at +0xC). Its inlined ctor keeps its own
 * base register (o + 0x10), so flow does not see through the stores and keeps
 * the earlier mC store (PATTERNS.md, "Hard-case families 3"). */
struct FESub10 {
    int m0;
    int m4;
    int m8;
    const void* mC;
};
inline void FESub10Init(FESub10* s)
{
    s->mC = lbl_8065B690;
    s->m0 = 0;
    s->m4 = 0;
}

extern "C" {
void fn_800ACFEC(void* p, int a);
void fn_800B1C7C(void* p);
void fn_800B2C6C(void* p);
}

/* ---- generated externs ---- */
















/* ---- unit prototypes ---- */
extern "C" {
void fn_800ACDA0();
void fn_800ACDA4(UnkAt1C20* self);
void fn_800ACF24(UnkAt1C* p);
void fn_800ACF48(UnkAt20F* p);
void fn_800ACFE8();
void fn_800AD17C(char* self, int c);
void fn_800AD6FC(char* self);
void fn_800AD774(UnkAtAA4* p);
void fn_800AD78C(void* p);
void fn_800AD948(char* self, int key, float v);
void fn_800ADAD8(char* self);
UnkFEPair fn_800ADB34(char* base, int a, int b);
void fn_800ADE10(void* p);
int fn_800ADE80(char* self, int a, int b);
void fn_800ADED0(char* self, int a, int b);
int fn_800ADF28(char* self, int a, int b);
float fn_800ADF6C(char* self, int a, int b);
int fn_800AE150(char* self, int* oi, int* oj, int key);
FEV4 fn_800AE1BC(char* self, int x, int y);
void fn_800AE2E4(void* p);
int fn_800AE304(char* self, int id, int x, int y);
int fn_800AE3FC(char* self, int id, int x, int y);
void fn_800AE4F4(char* self);
void fn_800AE944(void* p);
void fn_800AE964(UnkAtEF0* p, int v);
void fn_800AE96C(char* self);
int fn_800AEA04(char* self, int k);
void fn_800AEA64();
FEIT* fn_800AEA68(FEIT* self, int* src, int n);
void fn_800AEB88(char* p);
void fn_800AEBAC(char* p);
void fn_800AEBD0(char* self);
void fn_800AEC04(char* self);
void fn_800AEC74();
char* fn_800AEC78(char* p);
void* fn_800AEC80(void* self);
FEIT* fn_800AECE8(FEIT* self, int* src, int n);
void* fn_800AEDDC(void* self);
int fn_800AEE44(void* self);
FEOb12* fn_800AEFF4(FEOb12* self, int a, int b);
void* fn_800AF010(void* p, int k);
FEO8B* fn_800AF020(FEO8B* self);
FEO8B* fn_800AF070(FEO8B* self);
FEO8B* fn_800AF0C0(FEO8B* self);
int fn_800AF110();
void* fn_800AF118(void* p, int k);
void fn_800AF148(FEObjAF* self);
}
/* ---- end prototypes ---- */

/* ---- functions ---- */
extern "C" void fn_800ACDA0()
{
}

extern "C" void fn_800ACDA4(UnkAt1C20* self)
{
    fn_800ADCD8(self->m1C);
    self->m20 = lbl_805B95A4;
}

extern "C" void fn_800ACDE0(FEBar* self)
{
    self->m20 = self->m20 + 0.016666668f;
    Ratio(self->m1C, self->m24, self->m20);
    float r = Clamp01(self->m20 / Dur(self));
    float v = Lerp(0.0f, r, 0.6f);
    fn_800AD948((char*)self->m1C, 3, v);
    fn_800AD838(self->m1C, 1.0f - r);
    if (!(self->m20 <= self->m24)) {
        fn_8033E5C4(self->m1C, 0);
    }
}

extern "C" void fn_800ACF24(UnkAt1C* p)
{
    fn_800ADE10(p->m1C);
}

extern "C" void fn_800ACF48(UnkAt20F* p)
{
    p->m20 = lbl_805B95B8;
}

extern "C" void fn_800ACF58(FEBar* self)
{
    self->m20 = self->m20 + 0.016666668f;
    Ratio(self->m1C, self->m24, self->m20);
    if (!(self->m20 <= self->m24)) {
        fn_8033E5C4(self->m1C, 0);
    }
}

extern "C" void fn_800ACFE8()
{
}

extern "C" void fn_800AD17C(char* self, int c)
{
    *(const void**)(self + 0xC) = lbl_8065B268;
    fn_8033E600(self, c);
    *(const void**)(self + 0xC) = lbl_8065B690;
    if (c & 1) {
        fn_80377408(self);
    }
}

struct FEVec2 {
    float x;
    float y;
};
inline FEVec2 operator-(const FEVec2& a, const FEVec2& b)
{
    FEVec2 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

inline FEVec2 operator*(const FEVec2& a, float s)
{
    FEVec2 r;
    r.x = a.x * s;
    r.y = a.y * s;
    return r;
}

struct FECell {
    int m0;
    FEVec2 p0;
    FEVec2 p1;
    FEVec2 out;
};
struct FERow {
    FECell c[8];
};
struct FERowsObj {
    char pad0[0x314];
    FERow rows[8];
    char pad[0xAA4 - 0x314 - 0x700];
    int mAA4;
};

inline FEVec2 operator+(const FEVec2& a, const FEVec2& b)
{
    FEVec2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}
#define FECELL(s, i, j) (((FERowsObj*)(s))->rows[i].c[j])
extern "C" void fn_800AD58C(char* self, int i, int j)
{
    FEVec2 P = *(FEVec2*)(self + 0xA74);
    FEVec2* st = (FEVec2*)(self + 0xA68);
    P.x = P.x - st->x * (float)i;
    P.y = P.y - st->y * (float)j;
    FEVec2 Q = P;
    Q.x = Q.x - st->x;
    Q.y = Q.y - st->y;
    FEVec2 R = Q + P;
    FEVec2 S = R * 0.5f;
    FECELL(self, i, j).m0 = 0;
    FECELL(self, i, j).p1 = FECELL(self, i, j).out = FECELL(self, i, j).p0 = S;
}

/* near-miss (retail reloads the count before the inner loop pre-test and keeps self in r31; ours reuses r0 and swaps r30/r31): 4 loop forms tried */
extern "C" void fn_800AD6FC(char* self)
{
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = 0;
        while (1) {
            if (!(j < *(int*)(self + 0xAA4))) {
                break;
            }
            fn_800AD58C(self, i, j);
            j++;
        }
        i++;
    }
}

extern "C" void fn_800AD774(UnkAtAA4* p)
{
    if (p->mAA4 <= 7) {
        p->mAA4 = p->mAA4 + 1;
    }
}

extern "C" void fn_800AD78C(void* p)
{
    char* self = (char*)p;
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        char* row = self + 0x14 + i * 0x60;
        int j = 0;
        while (1) {
            if (!(j < *(int*)(self + 0xAA4))) {
                break;
            }
            int* c = (int*)(row + j * 0xC);
            c[1] = (int)fn_8014D8AC(((FEGrid*)self)->mA84->m554, 5, lbl_805B962C, 0x17E);
            *(float*)(c + 2) = lbl_805B966C;
            c[0] = 0;
            j++;
        }
        i++;
    }
}

extern "C" void fn_800AD838(void* p, float s)
{
    FERowsObj* self = (FERowsObj*)p;
    int i = 0;
    while (1) {
        if (!(i < self->mAA4)) {
            break;
        }
        int j = self->mAA4 - 1;
        while (1) {
            if (!(j >= 0)) {
                break;
            }
            FECell* e = &self->rows[i].c[j];
            if (e && e->m0) {
                e->out = e->p1 - (e->p1 - e->p0) * s;
            }
            j--;
        }
        i++;
    }
}

extern "C" void fn_800AD948(char* self, int key, float v)
{
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = *(int*)(self + 0xAA4) - 1;
        while (1) {
            if (!(j >= 0)) {
                break;
            }
            int off = j * 0xC + i * 0x60;
            char* b1 = self + 0x14;
            if (*(int*)(b1 + off) == key) {
                char* b2 = self + 0x1C;
                *(float*)(b2 + off) = v;
            }
            j--;
        }
        i++;
    }
}

inline float FEMin(float a, float b)
{
    return a <? b;
}

extern "C" void fn_800AD9C0(void* p, int id)
{
    char* self = (char*)p;
    const float a = 0.02f;
    const float b = 0.2f;
    const float c = 0.025f;
    float st = FEMin(b, (float)*(int*)(self + 0xA88) * c + a);
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = *(int*)(self + 0xAA4) - 1;
        while (1) {
            if (!(j >= 0)) {
                break;
            }
            int off = j * 0xC + i * 0x60;
            char* b2 = self + 0x14;
            FECell* e = &((FERowsObj*)self)->rows[i].c[j];
            if (*(int*)(b2 + off) == id) {
                if (!(e->out.x >= e->p0.x)) {
                    e->out.x = e->p0.x + st;
                } else {
                    e->out.x = e->p0.x - st;
                }
            }
            j--;
        }
        i++;
    }
}

extern "C" void fn_800ADAD8(char* self)
{
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = *(int*)(self + 0xAA4) - 1;
        while (1) {
            if (!(j >= 0)) {
                break;
            }
            char* e = self + i * 0xE0 + j * 0x1C;
            *(UnkFEPair*)(e + 0x328) = *(UnkFEPair*)(e + 0x318);
            j--;
        }
        i++;
    }
}

extern "C" UnkFEPair fn_800ADB34(char* base, int a, int b)
{
    return *(UnkFEPair*)(base + a * 0xe0 + b * 0x1c + 0x328);
}

extern "C" int fn_800ADB5C(char* self, FEVec2* pt, int* oi, int* oj)
{
    FEVec2 pv = *pt;
    *oi = -1;
    *oj = -1;
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = 0;
        while (1) {
            if (!(j < *(int*)(self + 0xAA4))) {
                break;
            }
            FEVec2 P = *(FEVec2*)(self + 0xA74);
            FEVec2* st = (FEVec2*)(self + 0xA68);
            P.x = P.x - st->x * (float)i;
            P.y = P.y - st->y * (float)j;
            FEVec2 Q = P;
            Q.x = Q.x - st->x;
            Q.y = Q.y - st->y;
            if (!(pv.x <= P.x || pv.x >= Q.x || pv.y >= P.y || pv.y <= Q.y)) {
                *oi = i;
                *oj = j;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

extern "C" void fn_800ADE10(void* p)
{
    char* self = (char*)p;
    int i;
    int j;
    while (fn_800AE150(self, &i, &j, 3)) {
        int o1 = i * 0x60 + 0x14;
        int o2 = j * 0xC;
        *(int*)(self + o1 + o2) = 0;
    }
    fn_800AD6FC(self);
}

/* near-miss (6 slots): retail keeps i in r3 (the return register) and recomputes the row base each iteration */
extern "C" int fn_800ADE80(char* self, int a, int b)
{
    int i = b;
    if (i >= 0 && i <= *(int*)(self + 0xAA4)) {
        for (; i >= 0; i--) {
            char* base = self + 0x14;
            int off = i * 0xC + a * 0x60;
            if (*(int*)(base + off) == 0) {
                return i;
            }
        }
    }
    return -1;
}

extern "C" void fn_800ADED0(char* self, int a, int b)
{
    for (int i = b; i >= 0 && i <= *(int*)(self + 0xAA4); i--) {
        char* p14 = self + 0x14;
        char* p1C = self + 0x1C;
        int off = i * 0xC + a * 0x60;
        *(int*)(p14 + off) = 2;
        *(float*)(p1C + off) = lbl_805B96A0;
    }
}

extern "C" int fn_800ADF28(char* self, int a, int b)
{
    int n = *(int*)(self + 0xAA4);
    int r = -1;
    if (a < n && b < n && a >= 0 && b >= 0) {
        char* base = self + 0x18;
        int off = b * 0xC + a * 0x60;
        r = *(int*)(base + off);
    }
    return r;
}

extern "C" float fn_800ADF6C(char* self, int a, int b)
{
    float r = lbl_805B96A4;
    int n = *(int*)(self + 0xAA4);
    if (a < n && b < n && a >= 0 && b >= 0) {
        char* base = self + 0x1C;
        int off = b * 0xC + a * 0x60;
        r = *(float*)(base + off);
    }
    return r;
}

extern "C" int fn_800AE150(char* self, int* oi, int* oj, int key)
{
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = *(int*)(self + 0xAA4) - 1;
        while (1) {
            if (!(j >= 0)) {
                break;
            }
            int off = j * 0xC + i * 0x60;
            char* b1 = self + 0x14;
            if (*(int*)(b1 + off) == key) {
                *oi = i;
                *oj = j;
                return 1;
            }
            j--;
        }
        i++;
    }
    return 0;
}

extern "C" FEV4 fn_800AE1BC(char* self, int x, int y)
{
    FEV4 v = lbl_8068B588;
    FEV4* p = &v;
    int n = *(int*)(self + 0xAA4);
    if (x < n && x >= 0 && y < n && y >= 0) {
        v = *(FEV4*)(self + 0xA14 + fn_800ADF28(self, x, y) * 16);
        float f = fn_800ADF6C(self, x, y);
        p->mC = f > lbl_805B96AC ? lbl_805B96AC : (f >? lbl_805B96B0);
    }
    return v;
}

extern "C" void fn_800AE2E4(void* p)
{
    fn_800AD78C(p);
}

extern "C" int fn_800AE304(char* self, int id, int x, int y)
{
    int cnt = 0;
    if (x >= 0 && x < *(int*)(self + 0xAA4) && y >= 0 && y < *(int*)(self + 0xAA4)) {
        int c = fn_800ADF28(self, x, y);
        if (c == id) {
            char* b = self + 0x14;
            int off = y * 0xC + x * 0x60;
            if (*(int*)(b + off) == 0) {
                cnt = 1;
                *(int*)(b + off) = cnt;
                cnt = fn_800AE304(self, c, x - 1, y) + 1;
                cnt += fn_800AE304(self, c, x + 1, y);
                cnt += fn_800AE304(self, c, x, y - 1);
                cnt += fn_800AE304(self, c, x, y + 1);
            }
        }
    }
    return cnt;
}

extern "C" int fn_800AE3FC(char* self, int id, int x, int y)
{
    int cnt = 0;
    if (x >= 0 && x < *(int*)(self + 0xAA4) && y >= 0 && y < *(int*)(self + 0xAA4)) {
        int c = fn_800ADF28(self, x, y);
        if (c == id) {
            char* b = self + 0x14;
            int off = y * 0xC + x * 0x60;
            if (*(int*)(b + off) == 0) {
                cnt = 1;
                *(int*)(b + off) = cnt;
                cnt = fn_800AE3FC(self, c, x - 1, y) + 1;
                cnt += fn_800AE3FC(self, c, x + 1, y);
                cnt += fn_800AE3FC(self, c, x, y - 1);
                cnt += fn_800AE3FC(self, c, x, y + 1);
            }
        }
    }
    return cnt;
}

extern "C" void fn_800AE4F4(char* self)
{
    ((void (*)(char*))fn_800AE3FC)(self);
    int i = 0;
    while (1) {
        if (!(i < *(int*)(self + 0xAA4))) {
            break;
        }
        int j = *(int*)(self + 0xAA4) - 1;
        while (1) {
            if (!(j >= 0)) {
                break;
            }
            char* b1 = self + 0x14;
            int off = j * 0xC + i * 0x60;
            *(int*)(b1 + off) = 0;
            j--;
        }
        i++;
    }
}

extern "C" void fn_800AE944(void* p)
{
    fn_8033E4F0(p);
}

extern "C" void fn_800AE964(UnkAtEF0* p, int v)
{
    p->mEF0 = v;
}

extern "C" void fn_800AE96C(char* self)
{
    char* p = self + 0x448;
    Unk80084910_W* w = (Unk80084910_W*)((FE6F8H*)fn_800ABC30(self, 0))->m6F8->m10;
    int h = fn_801A2034((Unk8019F8C0_Owner*)fn_800ABC30(self, 0), 4);
    if (*(int*)(p + 0xAA4) <= 7) {
        fn_800AD774((UnkAtAA4*)p);
    } else if (fn_80086D34(w, h) == 1) {
        fn_80086D24(w, h, 0);
    }
    fn_800AD1D4(p);
}

extern "C" int fn_800AEA04(char* self, int k)
{
    int* p = (int*)(self + 0xED0);
    int r;
    if (k == 1) {
        int a = *(int*)(self + 0xED0);
        int b = p[3];
        r = a * b;
        if (p[6] != 0) {
            if (a != 0) {
                r += b / 2;
            }
        }
    } else {
        int a = *(int*)(self + 0xED0);
        int b = p[3];
        r = a * a * b / 2;
    }
    return r;
}

extern "C" void fn_800AEA64()
{
}

extern "C" FEIT* fn_800AEA68(FEIT* self, int* src, int n)
{
    fn_800AB1CC(self, src, n);
    self->m18 = lbl_8065B010;
    fn_800ACFEC((char*)self + 0x448, src[0]);
    *(int*)((char*)self + 0xEF4) = 0;
    for (int i = 0; i < n; i++) {
        FEOb150* o = (FEOb150*)operator new(0x150, 0x400);
        fn_800AEFF4((FEOb12*)o, i, src[i]);
        o->mC = lbl_8065B9C0;
        FESub10Init((FESub10*)((char*)o + 0x10));
        o->mC = lbl_8065B298;
        o->m1C = lbl_8065B280;
        o->m8 = lbl_8065B2D8;
        o->mDC = 0;
        fn_800B1C7C(o);
        fn_800B2C6C(o);
        fn_800AB758(self, i, ((FEO8B*)o)->s2(0));
    }
    return self;
}

extern "C" void fn_800AEB88(char* p)
{
    fn_800AE574(p + 0x448);
}

extern "C" void fn_800AEBAC(char* p)
{
    fn_800AE2E4(p + 0x448);
}

extern "C" void fn_800AEBD0(char* self)
{
    fn_800ABC9C(self);
    fn_800AE944(self + 0x448);
}

extern "C" void fn_800AEC04(char* self)
{
    FE6F8H* o = (FE6F8H*)fn_800ABC30(self, 0);
    int v = o->m6F8->m10->m190;
    v = v > 8 ? 8 : (v >? 4);
    char* p = self + 0x448;
    *(int*)(p + 0xAA4) = v;
    fn_800AB3F8(self);
    fn_800AD1D4(p);
}

extern "C" void fn_800AEC74()
{
}

extern "C" char* fn_800AEC78(char* p)
{
    return p + 0x448;
}

extern "C" void* fn_800AEC80(void* self)
{
    FEO8B* o = fn_800AB80C(self, 0, 0);
    if (o) {
        if (o->s5()) {
            return fn_800AF070(o);
        }
    }
    return 0;
}

extern "C" FEIT* fn_800AECE8(FEIT* self, int* src, int n)
{
    fn_800AB1CC(self, src, n);
    int i = 0;
    self->m18 = lbl_8065AF38;
    for (; i < n; i++) {
        FEOb108* o = (FEOb108*)operator new(0x108, 0x400);
        fn_800AEFF4((FEOb12*)o, i, src[i]);
        char* sub = (char*)o + 0xC;
        *(const void**)(sub + 0x4C) = lbl_8065BA00;
        fn_803569D8(sub);
        o->m58 = lbl_8065AC08;
        o->m8 = lbl_8065AC28;
        fn_80356C68((char*)o + 0x60);
        fn_800B32A4(o);
        fn_800B385C(o);
        fn_800AB758(self, i, ((FEO8B*)o)->s2(0));
    }
    return self;
}

extern "C" void* fn_800AEDDC(void* self)
{
    FEO8B* o = fn_800AB80C(self, 0, 0);
    if (o) {
        if (o->s6()) {
            return fn_800AF0C0(o);
        }
    }
    return 0;
}

extern "C" int fn_800AEE44(void* self)
{
    void* o = fn_800AEDDC(self);
    int r;
    if (o == 0) {
        r = 1;
    } else {
        r = fn_80356C98((char*)o + 0x60);
    }
    return r;
}

extern "C" FEOb12* fn_800AEFF4(FEOb12* self, int a, int b)
{
    self->m0 = a;
    self->m8 = lbl_8065B360;
    self->m4 = b;
    return self;
}

extern "C" void* fn_800AF010(void* p, int k)
{
    if (k == 0) {
        return p;
    }
    return 0;
}

extern "C" FEO8B* fn_800AF020(FEO8B* self)
{
    if (self->s3() != 0) {
        return self;
    }
    return 0;
}

extern "C" FEO8B* fn_800AF070(FEO8B* self)
{
    if (self->s5() != 0) {
        return self;
    }
    return 0;
}

extern "C" FEO8B* fn_800AF0C0(FEO8B* self)
{
    if (self->s6() != 0) {
        return self;
    }
    return 0;
}

extern "C" int fn_800AF110()
{
    return 1;
}

extern "C" void* fn_800AF118(void* p, int k)
{
    if (k == 2) {
        return (char*)p + 0xC;
    }
    return fn_800AF010(p, k);
}

extern "C" void fn_800AF148(FEObjAF* self)
{
    FEV3Cz* o = self->m38;
    self->m34 = 0;
    if (o) {
        if (self->m0 == 0) {
            o->s32(lbl_805B96C4, 1)->s8(0);
        } else {
            o->s32(lbl_805B96D0, 1)->s8(0);
        }
        fn_8011A9B8(lbl_805B6F58, self->m3C, lbl_805B96DC);
    }
    ((FEV1C*)((char*)self + 0xC))->s2();
}
