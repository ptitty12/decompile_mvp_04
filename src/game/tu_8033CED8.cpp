/*
 * Game code, .text 0x8033CED8-0x8033FAFC (spline/curve math, node lists, memory
 * counters; original file and TU boundaries unknown, placeholder). Every data
 * object is extern by its lbl_ name.
 */
#include "game/tu_80331C60.h"
#include "game/tu_8000C2C4.h"

/* Intrusive singly linked node list. Evidence: fn_8033E464 (append walks +0x10,
 * stores the list in node+0xC via fn_8033E3F4), fn_8033E4C4 (find by +0x14),
 * fn_8033E600 (unlinks and deletes through the virtual dtor, slot 1). */
struct MList;
class MNodeBase {
public:
    char pad0[0x8];
    virtual ~MNodeBase();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
};
class MNode : public MNodeBase {
public:
    MList* mC;
    MNode* m10;
    int m14;
};
struct MList {
    MNode* m0;
    MNodeBase* m4;
    char pad8[4];
    MList* mC;
};

struct UnkAt4Sel { char pad0[0x4]; MNodeBase* m4; };
struct UnkAtCP { char pad0[0xC]; MList* mC; };
struct UnkAt14 { char pad0[0x14]; int m14; };
struct UnkAt4P14 { char pad0[0x4]; UnkAt14* m4; };

extern "C" {
void fn_8033E3F4(MNode* n, MList* l);
void fn_8033E5C4(MList* l, int k);
MNode* fn_8033E4C4(MList* l, int k);
void fn_8033E5A4(MList* l, MNodeBase* n);
void fn_8033E530(MList* l, MNodeBase* n);
void fn_8033E6DC();
void fn_8033E670(int a, unsigned* b, unsigned* c, unsigned* d, unsigned* e);
unsigned fn_803EE3D4(int a);
unsigned fn_803EE348(int a);
}

/* 4-byte calendar record: fn_8033E8E8 builds {3, 26, 2005} (month, day, year)
 * and passes it to fn_80329E74. */
struct UnkDate {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    UnkDate() : m0(0), m1(0), m2(0) {}
};
struct VT18 {
    char pad0[0x18];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
};
extern "C" int fn_80329E74(UnkDate d);
extern "C" int fn_80409BF0(char* buf, const char* fmt, va_list ap);
extern char lbl_80691628[];
extern int lbl_8061B9BC;
extern void (*lbl_80624220)(char*);

/* Hermite spline pieces. Evidence: fn_8033D14C evaluates the cubic Hermite basis
 * (2t^3-3t^2+1, -2t^3+3t^2, t^3-2t^2+t, t^3-t^2) over (p0, p1, m0, m1, t);
 * fn_8033D084 inlines it over two consecutive 12-byte knots of a table at +4. */
struct Spl4 { float m0; float m4; float m8; float mC; };
struct SplVec3 { float x; float y; float z; };
/* Piecewise Hermite spline of up to 3 segments through 3-vectors: one Spl4 per
 * segment and channel (x at +4, y at +0x34, z at +0x64, stride 0x10), the last
 * point/tangent at +0x94/+0xA0. Evidence: fn_8033D5D8 (append), fn_8033D3EC
 * (evaluate, per-channel fn_8033D24C), fn_8033D6C0 (copy). */
struct Spline {
    int m0;
    Spl4 cx[3];
    Spl4 cy[3];
    Spl4 cz[3];
    SplVec3 m94;
    SplVec3 mA0;
    float mAC;
    float mB0;
    float mB4;
    float mB8;
};
struct SplKnot { float m0; float m4; float m8; };
struct UnkSplObj { char pad0[0x4]; SplKnot* m4; };
struct UnkSplLoad { char pad0[0x4]; SplKnot* m4; int m8; };

inline SplVec3 Cross(const SplVec3& a, const SplVec3& b)
{
    SplVec3 c;
    c.x = a.y * b.z - b.y * a.z;
    c.y = b.x * a.z - a.x * b.z;
    c.z = a.x * b.y - b.x * a.y;
    return c;
}
inline float Sign(float v)
{
    if (!(v >= 0.0f))
        return -1.0f;
    return 1.0f;
}
inline SplVec3 SubV(const SplVec3& a, const SplVec3& b)
{
    SplVec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
inline float LenSq(SplVec3 v) { return v.z * v.z + (v.x * v.x + v.y * v.y); }
extern "C" float fn_804028E4(float x);
extern "C" SplVec3 fn_8033D490(Spline* s, float t);
extern "C" SplVec3 fn_8033D534(Spline* s, float t);
extern "C" {
int fn_8033D79C(Spline* s, float* tp);
void fn_8033D1EC(Spl4* p, float a, float b, float c, float d);
void fn_8033D228(Spl4* p, float* a, float* b, float* c, float* d);
float fn_8033D24C(Spl4* p, float t);
float fn_8033D2C4(Spl4* p, float t);
float fn_8033D334(Spl4* p, float t);
void fn_8033D5D8(Spline* s, SplVec3* p, SplVec3* q);
}

extern int lbl_8061B88C;
extern unsigned lbl_80621588, lbl_8062158C, lbl_80621590, lbl_80621594;
extern unsigned lbl_80621598, lbl_8062159C, lbl_806215A0, lbl_806215A4;
extern unsigned lbl_806215A8, lbl_806215AC, lbl_806215B0, lbl_806215B4;
extern int lbl_8061A5A8, lbl_806EF9B4;
extern "C" void fn_80378D70(const char* src, unsigned int len, char* dst, int cap, int delim, unsigned int* outn);
extern "C" double fn_80409D88(const char* s);
extern "C" int fn_80409DAC(const char* s);
extern "C" void fn_80377488(void* p);
extern "C" void* fn_803774A8(unsigned int size, int heap);

extern "C" {
/* near-miss: 13 slots differ (store/reload scheduling of the three element stores and the
 * cursor update; register choice r9/r11). Tried: cursor update before/after the stores,
 * index-first address operands, loop shapes. */
extern "C" void fn_8033CED8(UnkSplLoad* o, const char* s, unsigned int len)
{
    const char* cur = s;
    unsigned int n = 0;
    char buf[0x20];
    fn_80378D70(cur, len, buf, 0x19, 0x23, &n);
    int cnt = fn_80409DAC(buf);
    cur += n + 1;
    if (cnt) {
        o->m8 = cnt;
        if (o->m4) {
            fn_80377488(o->m4);
            o->m4 = 0;
        }
        if (o->m8) {
            o->m4 = (SplKnot*)fn_803774A8(o->m8 * 12, lbl_806EF9B4 | 0x100);
            int i = 0;
            if (i < o->m8) {
                int off = 0;
                do {
                    fn_80378D70(cur, len, buf, 0x19, 0x2C, &n);
                    i++;
                    float a = (float)fn_80409D88(buf);
                    cur += n + 1;
                    fn_80378D70(cur, len, buf, 0x19, 0x2C, &n);
                    float b = (float)fn_80409D88(buf);
                    cur += n + 1;
                    fn_80378D70(cur, len, buf, 0x19, 0x23, &n);
                    float c = (float)fn_80409D88(buf);
                    *(float*)(off + (int)o->m4) = a;
                    *(float*)(off + (int)o->m4 + 4) = b;
                    *(float*)(off + (int)o->m4 + 8) = c;
                    cur += n + 1;
                    off += 12;
                } while (i < o->m8);
            }
        }
    }
}

float fn_8033D084(UnkSplObj* o, int idx, float t)
{
    float t2 = t * t;
    float t3 = t2 * t;
    float p0 = o->m4[idx].m4;
    float p1 = o->m4[idx + 1].m4;
    float m0 = o->m4[idx].m8 * 10.0f;
    float m1 = o->m4[idx + 1].m8 * 10.0f;
    return ((2.0f * t3 - 3.0f * t2) + 1.0f) * p0 + (t3 * -2.0f + 3.0f * t2) * p1
         + ((t3 - 2.0f * t2) + t) * m0 + (t3 - t2) * m1;
}

float fn_8033D14C(float p0, float p1, float m0, float m1, float t)
{
    float t2 = t * t;
    float t3 = t2 * t;
    return ((2.0f * t3 - 3.0f * t2) + 1.0f) * p0 + (t3 * -2.0f + 3.0f * t2) * p1
         + ((t3 - 2.0f * t2) + t) * m0 + (t3 - t2) * m1;
}

int fn_8033D1E4() { return 0; }

void fn_8033D1EC(Spl4* p, float a, float b, float c, float d)
{
    p->m0 = a;
    p->m4 = b;
    p->m8 = c;
    p->mC = d;
}

void fn_8033D228(Spl4* p, float* a, float* b, float* c, float* d)
{
    *a = p->m0;
    *b = p->m4;
    *c = p->m8;
    *d = p->mC;
}

float fn_8033D24C(Spl4* p, float t)
{
    float r;
    float t2 = t * t;
    float t3 = t2 * t;
    r = t3 * (2.0f * (p->m0 - p->m4) + p->m8 + p->mC)
        + ((t * p->m8 + p->m0) - t2 * ((p->m0 - p->m4) * 3.0f + 2.0f * p->m8 + p->mC));
    return r;
}

float fn_8033D2C4(Spl4* p, float t)
{
    float r;
    float t2 = t * t;
    r = p->m8 - 2.0f * t * ((p->m0 - p->m4) * 3.0f + 2.0f * p->m8 + p->mC)
        + t2 * ((2.0f * (p->m0 - p->m4) + p->m8 + p->mC) * 3.0f);
    return r;
}

float fn_8033D334(Spl4* p, float t)
{
    float r;
    r = ((p->m0 - p->m4) * 3.0f + 2.0f * p->m8 + p->mC) * -2.0f
        + t * ((2.0f * (p->m0 - p->m4) + p->m8 + p->mC) * 6.0f);
    return r;
}

void fn_8033D3A0(Spline* p, float t)
{
    p->m0 = 0;
    p->mAC = 0.0f;
    p->mB0 = t;
    p->mB4 = (t + 1.0f) * (t + 1.0f);
    p->mB8 = (1.0f - t) * (1.0f - t);
}

SplVec3 fn_8033D3EC(Spline* s, float t)
{
    float tt = t;
    int seg = fn_8033D79C(s, &tt);
    SplVec3 v;
    v.x = fn_8033D24C(&s->cx[seg], tt);
    v.y = fn_8033D24C(&s->cy[seg], tt);
    v.z = fn_8033D24C(&s->cz[seg], tt);
    return v;
}

SplVec3 fn_8033D490(Spline* s, float t)
{
    float tt = t;
    int seg = fn_8033D79C(s, &tt);
    SplVec3 v;
    v.x = fn_8033D2C4(&s->cx[seg], tt);
    v.y = fn_8033D2C4(&s->cy[seg], tt);
    v.z = fn_8033D2C4(&s->cz[seg], tt);
    return v;
}

SplVec3 fn_8033D534(Spline* s, float t)
{
    float tt = t;
    int seg = fn_8033D79C(s, &tt);
    SplVec3 v;
    v.x = fn_8033D334(&s->cx[seg], tt);
    v.y = fn_8033D334(&s->cy[seg], tt);
    v.z = fn_8033D334(&s->cz[seg], tt);
    return v;
}

void fn_8033D5D8(Spline* s, SplVec3* p, SplVec3* q)
{
    if (s->m0 > 0) {
        fn_8033D1EC(&s->cx[s->m0 - 1], s->m94.x, p->x, s->mA0.x, q->x);
        fn_8033D1EC(&s->cy[s->m0 - 1], s->m94.y, p->y, s->mA0.y, q->y);
        fn_8033D1EC(&s->cz[s->m0 - 1], s->m94.z, p->z, s->mA0.z, q->z);
    }
    s->m94 = *p;
    s->mA0 = *q;
    s->m0++;
}

void fn_8033D6C0(Spline* dst, Spline* src)
{
    int n = src->m0 - 1;
    for (int i = 0; i < n; i++) {
        SplVec3 p0, p1, t0, t1;
        fn_8033D228(&src->cx[i], &p0.x, &p1.x, &t0.x, &t1.x);
        fn_8033D228(&src->cy[i], &p0.y, &p1.y, &t0.y, &t1.y);
        fn_8033D228(&src->cz[i], &p0.z, &p1.z, &t0.z, &t1.z);
        if (i == 0)
            fn_8033D5D8(dst, &p0, &t0);
        fn_8033D5D8(dst, &p1, &t1);
    }
}

/* near-miss: 1 slot differs (retail keeps n = m0 - 2 in r9 and copies it into
 * seg with `mr r3,r9`; mine folds n into r3). Tried: n/seg split, inline clamps. */
int fn_8033D79C(Spline* s, float* tp)
{
    int i = (int)*tp;
    int n = s->m0 - 2;
    int seg = n;
    if (!(i > n)) {
        seg = i;
        if (seg < 0)
            seg = 0;
    }
    *tp = *tp - (float)seg;
    *tp = *tp > (float)(s->m0 - 1) ? (float)(s->m0 - 1) : (*tp >? 0.0f);
    return seg;
}

/* Finds the parameter u whose point lies `len` away from the point at t (Newton-style step
 * refinement with tolerance band [len^2*mB8, len^2*mB4]; mAC is the stored step).
 * near-miss (173/173 instructions, stack slots all match): retail keeps `s` in r30 and the
 * &A pointer in r31, mine has them swapped, which shifts most register operands. */
extern "C" float fn_8033D860(Spline* s, int* out, float t, float len)
{
    if (!(t >= 0.0f)) {
        *out = 0;
        return 0.0f;
    }
    float maxT = (float)(s->m0 - 1);
    if (!(t <= maxT)) {
        *out = 0;
        return maxT;
    }
    if (len == 0.0f) {
        *out = 1;
        return t;
    }
    SplVec3 B;
    SplVec3 A = fn_8033D3EC(s, t);
    float d2;
    float step;
    float u;
    float len2;
    float lo2;
    float hi2;
    int clipped = 0;
    len2 = len * len;
    lo2 = len2 * s->mB4;
    hi2 = len2 * s->mB8;
    if (s->mAC <= 0.0f || !(s->mAC < 1.0f))
        step = 0.05f;
    else
        step = s->mAC;
    int iter = 1;
    A = fn_8033D3EC(s, t);
    u = t + step;
    int result;
    goto test;
loop:
    B = fn_8033D3EC(s, u);
    d2 = LenSq(SubV(A, B));
    if (!(d2 < hi2) && d2 <= lo2) {
        result = 1;
        goto fin;
    }
    if (iter > 10) {
        result = 1;
        goto fin;
    }
    iter++;
    step = step * fn_804028E4(len2 / d2);
    u = t + step;
test:
    if (u <= maxT) {
        clipped = 0;
        goto loop;
    }
    u = maxT;
    if (!clipped) {
        clipped = 1;
        goto loop;
    }
    result = 0;
fin:
    *out = result;
    s->mAC = step;
    return u;
}

extern "C" float fn_8033DB14(Spline* s, float t0, float len)
{
    SplVec3 cur;
    SplVec3 prev;
    float acc = 0.0f;
    float t = t0;
    float maxT = (float)(s->m0 - 1);
    prev = fn_8033D3EC(s, t);
    for (;;) {
        t = t + 0.01f;
        if (!(t < maxT))
            return 1.0f;
        cur = fn_8033D3EC(s, t);
        float d = fn_804028E4(LenSq(SubV(cur, prev)));
        if (acc + d >= len) {
            float over = (acc + d - len) / d;
            t = t - over * 0.01f;
            return t;
        }
        acc = acc + d;
        prev = cur;
    }
}

/* Arc length of the spline from t0 to its end, summed in steps clamped to [0.001, 0.01].
 * near-miss (164 vs 163 instructions): retail keeps the address of the int->float magic
 * constant in r27 (one lis for both conversions) where mine reloads it; everything else,
 * including the unrotated loop (goto form) and all stack slots, matches. */
extern "C" float fn_8033DCD4(Spline* s, float t0)
{
    SplVec3 cur;
    SplVec3 prev;
    float acc = 0.0f;
    float t = t0;
    float maxT = (float)(s->m0 - 1);
    prev = fn_8033D3EC(s, t);
    float step = (maxT - t0) * 0.01f;
    step = !(step > 0.01f) ? (step >? 0.001f) : 0.01f;
loop:
    t = t + step;
    if (t >= maxT)
        goto done;
    cur = fn_8033D3EC(s, t);
    acc = acc + fn_804028E4(LenSq(SubV(cur, prev)));
    prev = cur;
    goto loop;
done:
    cur = fn_8033D3EC(s, (float)(s->m0 - 1));
    acc = acc + fn_804028E4(LenSq(SubV(cur, prev)));
    return acc;
}

/* Curvature of the spline at t: |p''| / |p'|^2, signed by the y component of
 * p' x p'' when sgn is set. Evidence: fn_8033D490 / fn_8033D534 are the first
 * and second derivatives (fn_8033D2C4 / fn_8033D334 per channel), fn_804028E4
 * is sqrt (used the same way in tu_8033EA44). */
float fn_8033E2A4(Spline* s, int sgn, float t)
{
    SplVec3 v = fn_8033D490(s, t);
    SplVec3 a = fn_8033D534(s, t);
    float vv = v.z * v.z + (v.x * v.x + v.y * v.y);
    float am = fn_804028E4(a.z * a.z + (a.x * a.x + a.y * a.y));
    float k = am / vv;
    if (sgn) {
        k *= Sign(Cross(v, a).y);
    }
    return k;
}

void fn_8033E3E0(float a, float b)
{
    char buf[0x60];
}

void fn_8033E3F4(MNode* n, MList* l) { n->mC = l; }

void fn_8033E3FC(UnkAtCP* p, int k) { fn_8033E5C4(p->mC, k); }

int fn_8033E420(UnkAt4P14* p)
{
    switch (p->m4->m14) {
    case 1: case 2: case 3:
    case 7: case 8: case 9: case 10: case 11: case 12: case 13:
    case 17:
        return 1;
    }
    return 0;
}

void fn_8033E464(MList* l, MNode* n)
{
    MNode* prev = 0;
    MNode* cur = l->m0;
    while (cur) {
        prev = cur;
        cur = prev->m10;
    }
    if (prev == 0)
        l->m0 = n;
    else
        prev->m10 = n;
    fn_8033E3F4(n, l);
}

MNode* fn_8033E4C4(MList* l, int k)
{
    for (MNode* n = l->m0; n; n = n->m10) {
        if (k == n->m14)
            return n;
    }
    return 0;
}

void fn_8033E4F0(UnkAt4Sel* p)
{
    if (p->m4)
        p->m4->s5();
}

void fn_8033E530(MList* l, MNodeBase* n)
{
    if (l->m4)
        l->m4->s6();
    l->m4 = n;
    if (n)
        n->s4();
}

void fn_8033E5A4(MList* l, MNodeBase* n) { fn_8033E530(l, n); }

void fn_8033E5C4(MList* l, int k)
{
    MNode* n = fn_8033E4C4(l, k);
    if (n)
        fn_8033E5A4(l, n);
}

void fn_8033E600(MList* l)
{
    MNode* n = l->m0;
    l->m0 = 0;
    while (n) {
        MNode* next = n->m10;
        n->m10 = 0;
        delete n;
        n = next;
    }
}

void fn_8033E670(int a, unsigned* b, unsigned* c, unsigned* d, unsigned* e)
{
    unsigned t = fn_803EE3D4(a);
    *b = t;
    if (t < *d)
        *d = t;
    t = fn_803EE348(a);
    *c = t;
    if (t < *e)
        *e = t;
}

void fn_8033E6DC()
{
    if (lbl_8061B88C) {
        fn_8033E670(0, &lbl_80621588, &lbl_8062158C, &lbl_80621590, &lbl_80621594);
        if (lbl_806EF9B4 != lbl_8061A5A8)
            fn_8033E670(lbl_806EF9B4, &lbl_80621598, &lbl_8062159C, &lbl_806215A0, &lbl_806215A4);
        if (lbl_8061A5A8)
            fn_8033E670(lbl_8061A5A8, &lbl_806215A8, &lbl_806215AC, &lbl_806215B0, &lbl_806215B4);
    }
}

void fn_8033E7A4() { fn_8033E6DC(); }

unsigned fn_8033E7C4() { return lbl_80621588 >> 10; }

unsigned fn_8033E7D4() { return lbl_8062158C >> 10; }

unsigned fn_8033E7E4() { return lbl_80621590 >> 10; }

unsigned fn_8033E7F4() { return lbl_80621594 >> 10; }

unsigned fn_8033E804() { return lbl_806215A0 >> 10; }

unsigned fn_8033E814() { return lbl_806215A4 >> 10; }

unsigned fn_8033E824() { return lbl_80621598 >> 10; }

unsigned fn_8033E834() { return lbl_8062159C >> 10; }

unsigned fn_8033E844() { return lbl_806215B0 >> 10; }

unsigned fn_8033E854() { return lbl_806215B4 >> 10; }

unsigned fn_8033E864() { return lbl_806215A8 >> 10; }

unsigned fn_8033E874() { return lbl_806215AC >> 10; }

void fn_8033E884() {}

int fn_8033E888(int a, int b)
{
    float unused = 365.25f;
    return (int)((float)(b - a + 1) * 0.0027378509f);
}

/* near-miss: 29 vs 28 instructions. Retail zeroes the {month, year, day} record with a single
 * `li r4,0` and loads 3, 26 and 2005 early; mine zeroes twice (li r0 / li r11). Tried: ctor
 * orders (24), setter inline, parameterised ctor, MakeDate() returning by value. */
int fn_8033E8E8(int a)
{
    UnkDate d;
    d.m0 = 3;
    d.m2 = 2005;
    d.m1 = 26;
    return fn_8033E888(a, fn_80329E74(d));
}

int fn_8033E958(const char* fmt, ...)
{
    if (lbl_8061B9BC) {
        if (fmt) {
            va_list ap;
            va_start(ap, fmt);
            fn_80409BF0(lbl_80691628, fmt, ap);
        } else {
            lbl_80691628[0] = 0;
        }
        if (lbl_80624220)
            lbl_80624220(lbl_80691628);
    }
    return 0;
}

void fn_8033FA6C(VT18* p) { p->s5(); }

int fn_8033FAA0(VT18* p) { return p->s5(); }

int fn_8033FAD4() { return 0; }

void fn_8033FADC(float a) {}

void fn_8033FAEC() {}

void fn_8033FAF0() {}

void fn_8033FAF4() {}

void fn_8033FAF8() {}

}
