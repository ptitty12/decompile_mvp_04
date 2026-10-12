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
extern const float lbl_805FFEA0;
extern const float lbl_805FFEA4;
extern const float lbl_805FFEA8;
extern const float lbl_805FFEAC;
extern const float lbl_805FFEB0;

extern "C" float fn_80573D44(DbSub50* p, int i);

extern "C" DB_OVERLAY float fn_8057375C(DbMgr* self)
{
    DbSub50* p = &self->m50;
    float r = fn_80573D44(p, p->m4);
    return r;
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
