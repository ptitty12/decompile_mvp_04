/*
 * Database overlay code, .database_codeoverlay 0x805721F8-0x80574AE4 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"
#include "game/clampiter.h"

/* Table of 16-byte rows (four floats), indexed through a screen lookup. */
struct DbRow16 {
    float m0, m4, m8, mC;
};
struct DbTbl16 {
    DbRow16 r[1];
};

/* Growable record list: data at +0, count at +4, capacity at +8, cursor at +0xC; a second
 * buffer (data +0x14, flags +0x18, capacity +0x1C, count +0x20). */
struct DbList {
    void* m0;
    int m4;
    int m8;
    int mC;
    char pad10[4];
    void* m14;
    int m18;
    int m1C;
    int m20;
};

extern void* lbl_8061930C;
extern const float lbl_805FFEF8;
extern const float lbl_805FFEFC;
extern const float lbl_805FFF00;
extern const float lbl_805FFF04;
extern const float lbl_805FFEE8;
extern "C" void fn_805744D4(DbTbl16* t);

extern const float lbl_805FFE7C;
extern const float lbl_805FFE68;
extern const float lbl_805FFE6C;
extern const float lbl_805FFE70;
extern const float lbl_805FFEA0;
extern const float lbl_805FFEA4;
extern const float lbl_805FFEA8;
extern const float lbl_805FFEAC;
extern const float lbl_805FFEB0;

extern const float lbl_805FFF08;

extern const float lbl_805FFE18;
extern const float lbl_805FFE1C;
extern const float lbl_805FFE20;

extern const float lbl_805FFE04;
extern const float lbl_805FFE08;
extern const float lbl_805FFE0C;
extern const float lbl_805FFE10;
extern const float lbl_805FFE14;

extern const float lbl_805FFE24;
extern const float lbl_805FFE28;

extern "C" {
float fn_80089E48__FP15Unk80089894_Objii(void* pt, unsigned i, int cur);
}

extern const float lbl_805FFE74;
extern const float lbl_805FFE78;

extern const float lbl_805FFEB4;
extern const float lbl_805FFEB8;
extern const float lbl_805FFEBC;
extern const float lbl_805FFEC0;
extern const float lbl_805FFEC4;
struct Db80573E10_S {
    char pad0[0x58];
    float m58;
    float m5C;
    float m60;
};
inline float Db80573E10_R(void* p, int id, int who)
{
    return ((float (*)(void*, int, int))fn_8007189C__FP1Wii)(p, id, who);
}

extern const float lbl_805FFEC8;
extern const float lbl_805FFECC;
extern const float lbl_805FFED0;
struct Db80573FB8_S {
    char pad0[0x4C];
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    float m60;
};
/* forward declarations (definitions are in address order) */
extern "C" int fn_805724AC(int unused, int a, int b, int c, int d, int e, float x);
extern "C" int fn_805725E4(int unused, int k, float x);
extern "C" int fn_80572648(int unused, int a, int b, int c, int d, int e, int p6, int f, float x, int g, int h);
extern "C" int fn_80573440(DbMgr* self, int side, int id, float thr);
extern "C" int fn_80573548(DbMgr* self, int side);
extern "C" int fn_805736CC(DbMgr* self, int side);
extern "C" float fn_8057375C(DbMgr* self);
extern "C" void fn_8057378C(DbMgr* self);
extern "C" void fn_80573840(DbSub50* p);
extern "C" void fn_805738F0(DbSub50* p, DbSelSrc* src);
extern "C" float fn_80573D44(DbSub50* p, int i);
extern "C" void fn_80573D84(DbSub50* p, int i, float v);
extern "C" float fn_80573E10(Db80573E10_S* self, DbT* t);
extern "C" float fn_80573FB8(Db80573FB8_S* self, DbT* t);
extern "C" float fn_805742B0(void* unused, DbT* t);
extern "C" float fn_8057437C(void* unused, DbT* t);
extern "C" int fn_80574420(DbSub50* p, DbT* t);
extern "C" DbTbl16* fn_80574478(DbTbl16* t);
extern "C" unsigned fn_80574728(DbTbl16* t, int idx);
extern "C" float fn_80574750(DbTbl16* t, int idx);
extern "C" float fn_80574798(DbTbl16* t, int idx);
extern "C" float fn_805747E4(DbTbl16* t, int idx);
extern "C" float fn_80574830(DbTbl16* t, int idx);
extern "C" void fn_8057487C(char* p);
extern "C" int fn_8057493C(DbHost* self, int a, int b);
extern "C" float fn_80574A04(DbHost* self, int a, int b);

extern "C" DB_OVERLAY int fn_805724AC(int unused, int a, int b, int c, int d, int e, float x)
{
    if (a == 0 && c > 0)
        goto zero;
    if (b == 0) {
        if (c > 4 && x < lbl_805FFE04)
            goto one;
        if (c > 2 && x < lbl_805FFE08)
            goto one;
        if (x < lbl_805FFE0C)
            goto one;
        goto zero;
    }
    if (d <= 2) {
        if (x < lbl_805FFE10)
            goto one;
        if (b > 5)
            goto one;
        if (e > 4)
            goto one;
    }
    if (d <= 4) {
        if (x < lbl_805FFE08)
            goto one;
        if (b > 6)
            goto one;
        if (e <= 3)
            goto zero;
        goto one;
    }
    if (b > 3)
        goto one;
    if ((unsigned)c > 4 && x < lbl_805FFE04)
        goto one;
    if (c == 0 && x < lbl_805FFE14)
        goto one;
    if (x >= lbl_805FFE08)
        goto zero;
one:
    return 1;
zero:
    return 0;
}

extern "C" DB_OVERLAY int fn_805725E4(int unused, int k, float x)
{
    if (x < lbl_805FFE18 || (k == 1 && x < lbl_805FFE1C) || (k == 2 && x < lbl_805FFE20) || k > 2)
        return 1;
    return 0;
}

extern "C" DB_OVERLAY int fn_80572648(int unused, int a, int b, int c, int d, int e, int p6, int f, float x, int g, int h)
{
    int lo = 0, hi = 3;
    if (d == 1)
        return 1;
    if (f != 0) {
        if (a == 0)
            goto zero;
        if (b == 0 && x > lbl_805FFE24)
            goto zero;
        if ((unsigned)(b - 1) <= 2 && x > lbl_805FFE28)
            goto zero;
    }
    if (e == 7) {
        if (c > lo && c <= hi && h == 0 && g == 0)
            return 1;
    }
    if (e <= 7)
        goto zero;
    if (c > lo && c <= hi && e == 8 && g == 0)
        return 1;
zero:
    return 0;
}

/* near-miss: 5 slots; same code, float registers f12/f13 swapped in the select */
extern "C" DB_OVERLAY int fn_80573440(DbMgr* self, int side, int id, float thr)
{
    DbT* t = TeamAt(self->m8->m14, side);
    if (fn_80097148(t, id) == 0) {
        char* tt = (char*)t + 0xC74;
        float cnt = fn_80089AA0__FP20Unk80089894_PackTabDUiUi(tt, 0, id);
        float tot = fn_80089AA0__FP20Unk80089894_PackTabDUiUi(tt, 0x1B, id);
        float v = !(cnt <= lbl_805FFE68) ? tot / cnt : lbl_805FFE68;
        return v < thr;
    }
    return 2;
}

extern "C" DB_OVERLAY int fn_80573548(DbMgr* self, int side)
{
    int n = 0;
    DbT* t = TeamAt(self->m8->m14, side);
    DbBL* b1 = &t->l[1];
    for (unsigned i = 0; i < b1->m4; i++) {
        if (fn_80573440(self, side, t->l[1].m0[(unsigned char)i], lbl_805FFE6C) == 0)
            n += 1;
    }
    DbBL* b2 = &t->l[2];
    for (unsigned i = 0; i < b2->m4; i++) {
        if (fn_80573440(self, side, t->l[2].m0[(unsigned char)i], lbl_805FFE6C) == 0)
            n += 1;
    }
    DbBL* b3 = &t->l[3];
    for (unsigned i = 0; i < b3->m4; i++) {
        if (fn_80573440(self, side, t->l[3].m0[(unsigned char)i], lbl_805FFE6C) == 0)
            n += 1;
    }
    DbBL* b4 = &t->l[4];
    for (unsigned i = 0; i < b4->m4; i++) {
        if (fn_80573440(self, side, t->l[4].m0[(unsigned char)i], lbl_805FFE6C) == 0)
            n += 1;
    }
    return n;
}

extern "C" DB_OVERLAY int fn_805736CC(DbMgr* self, int side)
{
    int n = 0;
    unsigned i = 0;
    DbT* t = TeamAt(self->m8->m14, side);
    for (; i < t->l[0].m4; i++) {
        if (fn_80573440(self, side, t->l[0].m0[(unsigned char)i], lbl_805FFE70) == 2)
            n += 1;
    }
    return n;
}

extern "C" DB_OVERLAY float fn_8057375C(DbMgr* self)
{
    DbSub50* p = &self->m50;
    float r = fn_80573D44(p, p->m4);
    return r;
}

extern "C" DB_OVERLAY void fn_8057378C(DbMgr* self)
{
    DbSub50* p = &self->m50;
    int side = p->m4;
    DbT* t = TeamAt(self->mC, side);
    unsigned char cur = t->m17C;
    float v = p->e[side].m4;
    v = v - (fn_8056FFB0() + lbl_805FFE74);
    if (!(v >= lbl_805FFE78))
        v = lbl_805FFE78;
    fn_80573D84(p, side, v);
    fn_80089EE0__FP20Unk80089894_PackTabDUiUii((char*)t + 0xC74, 0x1B, cur, (int)v);
}

/* near-miss: 6 slots; retail forms the entry pointer with add + stwu (pre-update) and loads the constant after it */
extern "C" DB_OVERLAY void fn_80573840(DbSub50* p)
{
    p->m0 = 1;
    p->m10 = 1;
    p->m4 = 0;
    p->m8 = 0;
    p->mC = 0;
    Unk8006A138_It<1> it(0);
    int i = 0;
    do {
        DbEnt18* e = (DbEnt18*)((char*)(i * 0x18 + (int)p) + 0x14);
        e->m0 = 0;
        e->m14 = lbl_805FFE7C;
        e->m4 = lbl_805FFE7C;
        e->m8 = lbl_805FFE7C;
        e->mC = lbl_805FFE7C;
        e->m10 = lbl_805FFE7C;
        i = it.Next();
    } while (i <= 1);
    p->m70 = lbl_805FFE7C;
    p->m44 = lbl_805FFE7C;
    p->m48 = lbl_805FFE7C;
    p->m4C = lbl_805FFE7C;
    p->m50 = lbl_805FFE7C;
    p->m54 = lbl_805FFE7C;
    p->m58 = lbl_805FFE7C;
    p->m5C = lbl_805FFE7C;
    p->m60 = lbl_805FFE7C;
    p->m64 = lbl_805FFE7C;
    p->m68 = lbl_805FFE7C;
    p->m6C = lbl_805FFE7C;
}

extern "C" DB_OVERLAY void fn_805738F0(DbSub50* p, DbSelSrc* src)
{
    int side = 0;
    if (src->m14->m1CD0 != 0)
        side = 1;
    p->m0 = side;
    p->m4 = side ^ 1;
}

extern "C" DB_OVERLAY float fn_80573D44(DbSub50* p, int i)
{
    if (p->e[i].m8 <= lbl_805FFEA0)
        return lbl_805FFEA0;
    float q = p->e[i].m4 / p->e[i].m8;
    return q;
}

extern "C" DB_OVERLAY void fn_80573D84(DbSub50* p, int i, float v)
{
    p->e[i].m4 = v;
    float t = v / p->e[i].m8;
    float u = 2.0f * t - lbl_805FFEA4;
    float w = (u * u * u + lbl_805FFEA8) * lbl_805FFEAC;
    p->m70 = w >? lbl_805FFEB0;
}

extern "C" DB_OVERLAY float fn_80573E10(Db80573E10_S* self, DbT* t)
{
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float r;
    char* pt = (char*)t + 0xC9C;
    unsigned char* pb = &t->m17C;
    a = Db80573E10_R(pt, 0x10, t->m17C);
    b = Db80573E10_R(pt, 0x10, pb[2]);
    c = Db80573E10_R(pt, 0x10, pb[1]);
    unsigned char u3 = pb[3];
    d = Db80573E10_R(pt, 0x10, u3) * lbl_805FFEB4 + Db80573E10_R(pt, 0xF, u3) * lbl_805FFEB8;
    unsigned char u5 = pb[5];
    e = Db80573E10_R(pt, 0x10, u5) * lbl_805FFEB4 + Db80573E10_R(pt, 0xF, u5) * lbl_805FFEB8;
    unsigned char u4 = pb[4];
    f = Db80573E10_R(pt, 0x10, u4) * lbl_805FFEB4 + Db80573E10_R(pt, 0xF, u4) * lbl_805FFEB8;
    r = ((self->m60 * (b * lbl_805FFEBC + d * lbl_805FFEBC) + self->m5C * (d * lbl_805FFEBC + e * lbl_805FFEBC)) + self->m58 * (f * lbl_805FFEBC + e * lbl_805FFEBC)) * lbl_805FFEC0 + (c * lbl_805FFEBC + a * lbl_805FFEBC) * lbl_805FFEC4;
    return r;
}

/* near-miss: 2 slots; retail loads +0x58 before +0x4C in the closing sum */
extern "C" DB_OVERLAY float fn_80573FB8(Db80573FB8_S* self, DbT* t)
{
    float r;
    unsigned char* pb = &t->m17C;
    char* pt = (char*)t + 0xC9C;
    unsigned char w = pb[7];
    self->m50 = Db80573E10_R(pt, 0xD, w) * lbl_805FFEC8 + Db80573E10_R(pt, 0x10, w) * lbl_805FFECC + Db80573E10_R(pt, 0xF, w) * lbl_805FFED0 + Db80573E10_R(pt, 0xE, w) * lbl_805FFED0 + Db80573E10_R(pt, 0x11, w) * lbl_805FFED0;
    unsigned char w2 = pb[6];
    self->m4C = Db80573E10_R(pt, 0xD, w2) * lbl_805FFEC8 + Db80573E10_R(pt, 0x10, w2) * lbl_805FFECC + Db80573E10_R(pt, 0xF, w2) * lbl_805FFED0 + Db80573E10_R(pt, 0xE, w2) * lbl_805FFED0 + Db80573E10_R(pt, 0x11, w2) * lbl_805FFED0;
    unsigned char w3 = pb[8];
    self->m54 = Db80573E10_R(pt, 0xD, w3) * lbl_805FFEC8 + Db80573E10_R(pt, 0x10, w3) * lbl_805FFECC + Db80573E10_R(pt, 0xF, w3) * lbl_805FFED0 + Db80573E10_R(pt, 0xE, w3) * lbl_805FFED0 + Db80573E10_R(pt, 0x11, w3) * lbl_805FFED0;
    r = self->m60 * self->m54 + (self->m5C * self->m50 + self->m58 * self->m4C);
    return r;
}

extern "C" DB_OVERLAY float fn_805741DC(void* unused, DbT* t)
{
    int cur = t->m17C;
    char* pt = (char*)t + 0xC74;
    unsigned i = 0;
    float s = fn_80089E48__FP15Unk80089894_Objii(pt, 0, cur);
    int cnt = 1;
    int k = 9;
    int j = 6;
    while (fn_80089AA0__FP20Unk80089894_PackTabDUiUi(pt, j, (unsigned char)cur) != 0) {
        i += 1;
        s += Db80573E10_R(pt, k, (unsigned char)cur);
        cnt += 1;
        k += 5;
        j += 5;
        if (i > 3)
            break;
    }
    float r = s / (float)cnt;
    return r;
}

/* near-miss: ~10 slots; retail passes the byte `cur` through clrlwi once and keeps `i*5+6` as an explicit step variable */
extern "C" DB_OVERLAY float fn_805742B0(void* unused, DbT* t)
{
    unsigned char cur = t->m17C;
    char* pt = (char*)t + 0xC74;
    unsigned i = 0;
    float s = fn_80089E48__FP15Unk80089894_Objii(pt, 0, cur);
    int cnt = 1;
    int k = 6;
    while (fn_80089AA0__FP20Unk80089894_PackTabDUiUi(pt, k, cur) != 0) {
        i += 1;
        cnt += 1;
        k += 5;
        s += fn_80089E48__FP15Unk80089894_Objii(pt, i, cur);
        if (i > 3)
            break;
    }
    float r = s / (float)cnt;
    return r;
}

/* near-miss: ~10 slots; retail recomputes i*5+6 each pass (no strength reduction) */
extern "C" DB_OVERLAY float fn_8057437C(void* unused, DbT* t)
{
    unsigned char cur = t->m17C;
    char* pt = (char*)t + 0xC74;
    unsigned i = 0;
    float best = fn_80089E48__FP15Unk80089894_Objii(pt, 0, cur);
    while (fn_80089AA0__FP20Unk80089894_PackTabDUiUi(pt, i * 5 + 6, cur) != 0) {
        i += 1;
        float v = fn_80089E48__FP15Unk80089894_Objii(pt, i, cur);
        if (!(v <= best))
            best = v;
        if (i > 3)
            break;
    }
    return best;
}

extern "C" DB_OVERLAY int fn_80574420(DbSub50* p, DbT* t)
{
    int r = fn_8008CFD8((char*)t + 0xC9C, 8, t->m168[t->m174]);
    if (r == 2)
        r = (p->m10 ^ 1) == 0;
    return r;
}

extern "C" DB_OVERLAY DbTbl16* fn_80574478(DbTbl16* t)
{
    for (int i = 0; i < 0x7E; i++) {
        t->r[i].m0 = lbl_805FFEE8;
        t->r[i].m4 = lbl_805FFEE8;
    }
    fn_805744D4(t);
    return t;
}

extern "C" DB_OVERLAY unsigned fn_80574728(DbTbl16* t, int idx)
{
    return fn_8007A0D0__18Unk8007B2B0_Screeni(lbl_8061930C, idx);
}

extern "C" DB_OVERLAY float fn_80574750(DbTbl16* t, int idx)
{
    unsigned i = fn_80574728(t, idx);
    if (i <= 0x7D)
        return t->r[i].m0;
    return lbl_805FFEF8;
}

extern "C" DB_OVERLAY float fn_80574798(DbTbl16* t, int idx)
{
    unsigned i = fn_80574728(t, idx);
    if (i <= 0x7D)
        return t->r[i].m4;
    return lbl_805FFEFC;
}

extern "C" DB_OVERLAY float fn_805747E4(DbTbl16* t, int idx)
{
    unsigned i = fn_80574728(t, idx);
    if (i <= 0x7D)
        return t->r[i].m8;
    return lbl_805FFF00;
}

extern "C" DB_OVERLAY float fn_80574830(DbTbl16* t, int idx)
{
    unsigned i = fn_80574728(t, idx);
    if (i <= 0x7D)
        return t->r[i].mC;
    return lbl_805FFF04;
}

extern "C" DB_OVERLAY void fn_8057487C(char* p)
{
    unsigned i = 0;
    DbList* q = (DbList*)(p + 0xC);
    do {
        i += 1;
        fn_8040074C(q->m0, q->m8 * 0x24);
        q->m4 = 0;
        q->mC = 0;
        fn_8040074C(q->m14, q->m1C * 4);
        q->m18 = 0;
        q->m20 = 0;
        q = (DbList*)((char*)q + 0x150);
    } while (i <= 8);
    q = (DbList*)(p + 0xBDC);
    i = 0;
    do {
        i += 1;
        fn_8040074C(q->m0, q->m8 * 0x1C);
        q->m4 = 0;
        q->mC = 0;
        fn_8040074C(q->m14, q->m1C * 4);
        q->m18 = 0;
        q->m20 = 0;
        q = (DbList*)((char*)q + 0xA0);
    } while (i <= 2);
}

extern "C" DB_OVERLAY int fn_8057493C(DbHost* self, int a, int b)
{
    unsigned i = 0;
    unsigned n = self->v4(a)->m4;
    if (i < n) {
        int off = 0;
        do {
            if (*(int*)((char*)self->v4(a)->m0 + off) == b)
                return *(int*)((char*)self->v4(a)->m0 + off + 0x20);
            i += 1;
            off += 0x24;
        } while (i < n);
    }
    return 0;
}

extern "C" DB_OVERLAY float fn_80574A04(DbHost* self, int a, int b)
{
    unsigned i = 0;
    unsigned n = self->v4(a)->m4;
    if (i < n) {
        int off = 0;
        do {
            if (*(int*)((char*)self->v4(a)->m0 + off) == b)
                return *(float*)((char*)self->v4(a)->m0 + off + 0x10);
            i += 1;
            off += 0x24;
        } while (i < n);
    }
    fn_800758F8__Fi(b);
    return lbl_805FFF08;
}
