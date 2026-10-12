/*
 * Database overlay code, .database_codeoverlay 0x80574AE4-0x8057CDB8 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"

extern void* lbl_8061930C;

/* List of ids (data at +0, count at +4) with a parallel array of scores at +0x220. */
struct DbSL {
    int* m0;
    int m4;
    char pad8[0x220 - 8];
    float m220[1];
};

/* Base-first indexed word load. */
inline int IdAt(int* a, int i)
{
    int o = i * 4;
    return *(int*)((char*)a + o);
}

struct DbGlob28 {
    char pad0[0x28];
    void* m28;
};
extern DbGlob28* lbl_80619948;
extern const float lbl_805FFFAC;

extern "C" {
int fn_8056A2F8(void* o, int cur, int mode, int a, int b, int who, int p6, int p7, int s8, int sC);
int fn_8056A838(void* o, int cur, int who);
void fn_8057C0B8(int* nA, int* nB, float* ratio, int cur, int mode, int who, int p6, int p7, int s8, int sC, int left);
}

extern "C" void fn_80377408(void* p);
extern char lbl_8064A550[];

extern "C" {
void fn_8055AC44(void* obj, int a);
int fn_8055AF00(void* obj, int id);
}

extern "C" {
int fn_80084954__FPv(int a);
void fn_80578C80(DbHost* self, int a, int b, int c, int d);
void fn_80574AE4(DbHost* self, int a, int b);
int fn_8057493C(DbHost* self, int a, int b);
}

extern char lbl_8064B298[];
extern char lbl_8064A2A8[];
extern "C" void fn_805371C4(void* self, unsigned flags);

/* Fixed-capacity id list object (0x82 words embedded at +0x18, vptr at +0x10). */
struct DbFixList {
    int* m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
};

inline void GrowTo(DbSL* l, unsigned idx)
{
    if (idx >= (unsigned)l->m4)
        l->m4 = idx + 1;
}

/* Growable record list (data at +0, count at +4, capacity at +8, cursor at +0xC); a second buffer at +0x14. */
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
extern "C" void fn_8057487C(char* p);

struct DbScan {
    int m0;
    void* m4;
};

struct Db80577508_S {
    int m0;
    void* m4;
    void* m8;
};

extern "C" int fn_8056A5B0(void* o, int kind, int idx, int who);
extern "C" int fn_8056B1D0(void* o, int* cur, int a);

extern char lbl_8064A330[];
extern char lbl_8064A550[];
/* Stack id list with a 0x28-word embedded buffer (vptr names as in db/tu_80582578.cpp's DbStkList). */
struct Db8057BA4C_SL {
    int* m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
    const void* vp;
    unsigned m14;
    void C1(int* buf, int cap)
    {
        vp = lbl_8064B298;
        m0 = buf;
        m8 = cap;
        fn_8040074C(m0, cap << 2);
    }
    void C2()
    {
        m4 = 0;
        mC = 0;
        vp = lbl_8064A550;
        fn_8040074C(m0, m8 << 2);
    }
    void C3(const void* v)
    {
        vp = v;
        m4 = 0;
        mC = 0;
        m14 = 0;
    }
    void Reset()
    {
        fn_8040074C(m0, m8 << 2);
        m4 = 0;
        mC = 0;
    }
    void D() { vp = lbl_8064A550; }
};

struct Db80579514_R {
    int m0;
    char pad4[0x18];
    int m1C;
};
class Db80579514_N {
public:
    char pad0[0x10];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(int a);
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual Db80579514_R* v21(int a);
};
extern "C" void fn_8057969C(DbHost* self, int a, int b, void* z, void* y);

struct Db8057C730_O {
    int m[12];
};
extern const float lbl_805FFFC0;
/* forward declarations (definitions are in address order) */
extern "C" int fn_80577508(Db80577508_S* self, int* a, int* b);
extern "C" int fn_8057763C(DbScan* self, int a);
extern "C" void fn_805788CC(char* self);
extern "C" int fn_80578974(DbHost* self, int a, int b);
extern "C" void fn_80578A60(DbHost* self, int a, int b);
extern "C" void fn_80578AE8(DbHost* self, int a, int b);
extern "C" void fn_80578B70(DbHost* self, int a, int b);
extern "C" void fn_80579514(DbHost* self, int a, int b);
extern "C" void fn_8057B29C(DbHost* self);
extern "C" void fn_8057B534(DbHost* self);
extern "C" void fn_8057B7F8(DbHost* self);
extern "C" void fn_8057BA4C(DbHost* self);
extern "C" void fn_8057C0B8(int* nA, int* nB, float* ratio, int cur, int mode, int who, int p6, int p7, int s8, int sC, int left);
extern "C" int fn_8057C21C(int id);
extern "C" int fn_8057C270(int id);
extern "C" void fn_8057C2C4(void* self, int* a, int* b, int* c);
extern "C" int fn_8057C3F8(void* self);
extern "C" void fn_8057C730(int who, int cur, Db8057C730_O* o);
extern "C" DbFixList* fn_8057C8F8(DbFixList* self, unsigned flags);
extern "C" void fn_8057C99C(void* self, int chrg);
extern "C" void fn_8057C9D0(DbSL* self, int flag);
extern "C" void fn_8057CA60(DbSL* self, int flag);
extern "C" void fn_8057CAF8(DbSL* self);
extern "C" void fn_8057CBA4(DbSL* self);
extern "C" unsigned fn_8057CC30(DbSL* self, int id);
extern "C" int fn_8057CCA4(DbSL* self, int id);
extern "C" void fn_8057CCE8(DbSL* self);

extern "C" DB_OVERLAY int fn_80577508(Db80577508_S* self, int* a, int* b)
{
    int s = fn_80078A38__18Unk8007B2B0_Screeni(self->m4, *a);
    int cur = fn_8007FB6C__FP13Unk8007F198_Ci(self->m4, s) + 1;
    unsigned ra = fn_8056A2F8(self->m8, cur, 1, 0, s, *a, 0, 2, 0, 0x1A);
    unsigned rb = fn_8056A2F8(self->m8, cur, 1, 0, s, *b, 0, 2, 0, 0x1A);
    if (ra == (unsigned)-1 || rb == (unsigned)-1)
        return 0;
    if (ra < rb)
        return 1;
    if (rb < ra)
        return 2;
    if (fn_8056A838(self->m8, ra, *a) == 1)
        return 3;
    int r = 0;
    if (fn_8056A838(self->m8, rb, *b) == 1)
        r = 4;
    return r;
}

extern "C" DB_OVERLAY int fn_8057763C(DbScan* self, int a)
{
    int total = 0;
    int hit = 0;
    unsigned n = fn_8007FB2C__FP13Unk8007F198_Ci(self->m4, self->m0);
    unsigned i = fn_8007FB40__FP13Unk8007F198_Ci(self->m4, self->m0);
    if (i < n) {
        do {
            int p0 = fn_8007FB98__FP13Unk8007F198_Ciii(self->m4, i, 0, self->m0);
            int p1 = fn_8007FB98__FP13Unk8007F198_Ciii(self->m4, i, 1, self->m0);
            if (a == p0 || a == p1) {
                total += 1;
                if (fn_8007FDA8__FP13Unk8007F198_Cii(self->m4, i, self->m0) == 1)
                    hit += 1;
            }
            i += 1;
        } while (i < n);
    }
    return total - hit;
}

/* near-miss: ~20 slots; retail walks one base (self+0x1990) with the first list at negative offsets, we pick the lower list as the base */
extern "C" DB_OVERLAY void fn_805788CC(char* self)
{
    unsigned i = 0;
    DbList* b = (DbList*)(self + 0x1990);
    fn_8057487C(self);
    do {
        i += 1;
        DbList* a = (DbList*)((char*)b - 0xBD0);
        fn_8040074C(a->m0, a->m8 * 0x24);
        a->m4 = 0;
        a->mC = 0;
        fn_8040074C(a->m14, a->m1C * 4);
        a->m18 = 0;
        a->m20 = 0;
        fn_8040074C(b->m0, b->m8 * 0x24);
        b->m4 = 0;
        b->mC = 0;
        fn_8040074C(b->m14, b->m1C * 4);
        b->m18 = 0;
        b->m20 = 0;
        b = (DbList*)((char*)b + 0x150);
    } while (i <= 8);
}

extern "C" DB_OVERLAY int fn_80578974(DbHost* self, int a, int b)
{
    if (fn_80084954__FPv(a) == 1) {
        int idx = FindRow(self->v9(a), b);
        if (idx != -1) {
            DbRow24* r = self->v9(a)->m0 + idx;
            return r->m20;
        }
        return 0;
    }
    return fn_8057493C(self, a, b);
}

extern "C" DB_OVERLAY void fn_80578A60(DbHost* self, int a, int b)
{
    self->v11(a, b);
    self->v12(a, b);
    self->v14(a, b);
}

extern "C" DB_OVERLAY void fn_80578AE8(DbHost* self, int a, int b)
{
    if (fn_80084954__FPv(b) == 1)
        fn_80578C80(self, a, b, 0, self->v8(b));
    else
        fn_80574AE4(self, a, b);
}

extern "C" DB_OVERLAY void fn_80578B70(DbHost* self, int a, int b)
{
    if (fn_80084954__FPv(b) == 1) {
        Db80579514_N* x = (Db80579514_N*)self->v8(b);
        Db80579514_N* z = (Db80579514_N*)self->v9(b);
        if (fn_80084978__FPv(b) == 0) {
            if (x->v21(0)->m1C == 0)
                z->v17(x->v21(0)->m0);
        }
        fn_80578C80(self, a, b, 1, (int)z);
    }
}

extern "C" DB_OVERLAY void fn_80579514(DbHost* self, int a, int b)
{
    if (fn_8008499C__FPv(b) == 1) {
        Db80579514_N* x = (Db80579514_N*)self->v8(b);
        Db80579514_N* y = (Db80579514_N*)self->v9(b);
        Db80579514_N* z = (Db80579514_N*)self->v10(b);
        if (x->v21(0)->m1C == 0)
            z->v17(x->v21(0)->m0);
        if (y->v21(0)->m1C == 0)
            z->v17(y->v21(0)->m0);
        fn_8057969C(self, a, b, z, y);
    }
}

extern "C" DB_OVERLAY void fn_8057B29C(DbHost* self)
{
    Db8057BA4C_SL t;
    int buf[0x28];
    Db8057BA4C_SL* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A330);
    self->v2();
    q->Reset();
    fn_805371C4(q, 0x70000001);
    self->v6(q, 0x0);
    q->Reset();
    fn_805371C4(q, 0x70000002);
    self->v6(q, 0x1);
    q->Reset();
    fn_805371C4(q, 0x70000004);
    self->v6(q, 0x2);
    q->Reset();
    fn_805371C4(q, 0x70000008);
    self->v6(q, 0x3);
    q->Reset();
    fn_805371C4(q, 0x70000010);
    self->v6(q, 0x4);
    q->Reset();
    fn_805371C4(q, 0x70000020);
    self->v6(q, 0x5);
    self->v7(0);
    self->v7(1);
    q->D();
}

extern "C" DB_OVERLAY void fn_8057B534(DbHost* self)
{
    Db8057BA4C_SL t;
    int buf[0x28];
    Db8057BA4C_SL* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A330);
    self->v2();
    q->Reset();
    fn_805371C4(q, 0x70000040);
    self->v6(q, 0x6);
    q->Reset();
    fn_805371C4(q, 0x70000080);
    self->v6(q, 0x7);
    q->Reset();
    fn_805371C4(q, 0x70000100);
    self->v6(q, 0x8);
    q->Reset();
    fn_805371C4(q, 0x70000200);
    self->v6(q, 0x9);
    q->Reset();
    fn_805371C4(q, 0x70000400);
    self->v6(q, 0xA);
    q->Reset();
    fn_805371C4(q, 0x70000800);
    self->v6(q, 0xB);
    q->Reset();
    fn_805371C4(q, 0x70001000);
    self->v6(q, 0xC);
    self->v7(2);
    q->D();
}

extern "C" DB_OVERLAY void fn_8057B7F8(DbHost* self)
{
    Db8057BA4C_SL t;
    int buf[0x28];
    Db8057BA4C_SL* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A330);
    self->v2();
    q->Reset();
    fn_805371C4(q, 0x70002000);
    self->v6(q, 0xD);
    q->Reset();
    fn_805371C4(q, 0x70004000);
    self->v6(q, 0xE);
    q->Reset();
    fn_805371C4(q, 0x70008000);
    self->v6(q, 0xF);
    q->Reset();
    fn_805371C4(q, 0x70010000);
    self->v6(q, 0x10);
    q->Reset();
    fn_805371C4(q, 0x70020000);
    self->v6(q, 0x11);
    q->Reset();
    fn_805371C4(q, 0x70040000);
    self->v6(q, 0x12);
    q->D();
}

extern "C" DB_OVERLAY void fn_8057BA4C(DbHost* self)
{
    Db8057BA4C_SL t;
    int buf[0x28];
    Db8057BA4C_SL* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A330);
    self->v2();
    q->Reset();
    fn_805371C4(q, 0x70080000);
    self->v6(q, 0x13);
    q->Reset();
    fn_805371C4(q, 0x70100000);
    self->v6(q, 0x14);
    q->Reset();
    fn_805371C4(q, 0x70200000);
    self->v6(q, 0x15);
    q->Reset();
    fn_805371C4(q, 0x70400000);
    self->v6(q, 0x16);
    q->Reset();
    fn_805371C4(q, 0x70800000);
    self->v6(q, 0x17);
    q->Reset();
    fn_805371C4(q, 0x71000000);
    self->v6(q, 0x18);
    q->D();
}

/* near-miss: 9 slots; same instructions, retail interleaves the parameter copies and stack-argument loads differently */
extern "C" DB_OVERLAY void fn_8057C0B8(int* nA, int* nB, float* ratio, int cur, int mode, int who, int p6, int p7, int s8, int sC, int left)
{
    *nA = 0;
    *nB = 0;
    *ratio = lbl_805FFFAC;
    void* obj = lbl_80619948->m28;
    while (1) {
        cur = fn_8056A2F8(obj, cur, mode, 0, 4, who, p6, p7, s8, sC);
        if (cur == -1)
            break;
        if (fn_8056A838(obj, cur, who) != 0)
            *nA += 1;
        else
            *nB += 1;
        if (mode == 0)
            cur += 1;
        if (left == 1)
            break;
        left -= 1;
    }
    int a = *nA;
    int tot = a + *nB;
    if (tot != 0)
        *ratio = (float)a / (float)tot;
    else
        *ratio = lbl_805FFFAC;
}

extern "C" DB_OVERLAY int fn_8057C21C(int id)
{
    float f;
    int a, b;
    fn_8057C0B8(&a, &b, &f, 0, 0, id, 0, 0, 0, 0x1A, 0);
    return a;
}

extern "C" DB_OVERLAY int fn_8057C270(int id)
{
    float f;
    int a, b;
    fn_8057C0B8(&a, &b, &f, 0, 0, id, 0, 1, 0, 0x1A, 0);
    return a;
}

extern "C" DB_OVERLAY void fn_8057C2C4(void* self, int* a, int* b, int* c)
{
    *a = 0;
    *b = 0;
    *c = 0;
    void* obj = lbl_80619948->m28;
    int cur = 0;
    while ((cur = fn_8056A2F8(obj, cur, 0, 0, 0, (int)self, 1, 2, 0, 0x1A)) != -1) {
        int k = fn_8056A5B0(obj, 0, cur, (int)self);
        if (k == 2)
            k = 1;
        int t = fn_8056B1D0(obj, &cur, 0);
        if (t == 3)
            continue;
        *a += 1;
        if ((k == 0 && t == 0) || (k == 1 && t == 1))
            *b += 1;
        else if ((k == 0 && t == 1) || (k == 1 && t == 0))
            *c += 1;
    }
}

extern "C" DB_OVERLAY int fn_8057C3F8(void* self)
{
    int a, b, c;
    fn_8057C2C4(self, &a, &b, &c);
    return b;
}

/* near-miss: 98.1%; the `w ? 3 : w` argument of the fourth call is laid out with its arms swapped (retail keeps the `li 3` arm in line); the CR4 flag reuse is reproduced */
extern "C" DB_OVERLAY void fn_8057C730(int who, int cur, Db8057C730_O* o)
{
    float f = lbl_805FFFC0;
    fn_8057C0B8(&o->m[0], &o->m[1], &f, cur, 1, who, 0, 2, 0, 0x1A, 10);
    fn_8057C0B8(&o->m[2], &o->m[3], &f, 0, 0, who, 0, 0, 0, 0x1A, 0);
    fn_8057C0B8(&o->m[4], &o->m[5], &f, 0, 0, who, 0, 1, 0, 0x1A, 0);
    int w = fn_8007B8C4__18Unk8007B2B0_Screenii(lbl_8061930C, 0, who);
    fn_8057C0B8(&o->m[6], &o->m[7], &f, 0, 0, who, 3, 2, 0, w ? 3 : w, 0);
    fn_8057C0B8(&o->m[8], &o->m[9], &f, 0, 0, who, 3, 2, 0, w == 0 ? 1 : 4, 0);
    fn_8057C0B8(&o->m[10], &o->m[11], &f, 0, 0, who, 3, 2, 0, w == 0 ? 2 : 5, 0);
}

extern "C" DB_OVERLAY DbFixList* fn_8057C8F8(DbFixList* self, unsigned flags)
{
    int* data = (int*)((char*)self + 0x18);
    self->m8 = 0x82;
    self->m0 = data;
    self->m10 = lbl_8064B298;
    fn_8040074C(data, 0x208);
    self->m4 = 0;
    self->mC = 0;
    self->m10 = lbl_8064A550;
    fn_8040074C(self->m0, self->m8 * 4);
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    self->m10 = lbl_8064A2A8;
    fn_805371C4(self, flags | 0x70000000);
    return self;
}

extern "C" DB_OVERLAY void fn_8057C99C(void* self, int chrg)
{
    *(const void**)((char*)self + 0x10) = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_8057C9D0(DbSL* self, int flag)
{
    int n = self->m4;
    void* s = lbl_8061930C;
    int per = n / 6;
    for (int i = 0; i < n; i++) {
        int q = i / per;
        int id;
        if (flag != 0)
            id = 0x37;
        else
            id = 0x36;
        fn_8007B98C__18Unk8007B2B0_Screeniii(s, id, IdAt(self->m0, i), q);
    }
}

extern "C" DB_OVERLAY void fn_8057CA60(DbSL* self, int flag)
{
    void* s = lbl_8061930C;
    int f = 1;
    if (flag == 0)
        f = 0;
    for (unsigned i = 0; i < self->m4; i++) {
        float v = fn_8007BB28__18Unk8007B2B0_Screeniii(s, 5, IdAt(self->m0, i), f);
        self->m220[i] = v;
    }
    fn_8057CCE8(self);
}

extern "C" DB_OVERLAY void fn_8057CAF8(DbSL* self)
{
    char obj[0x460];
    unsigned i = 0;
    fn_8055AC44(obj, 0);
    for (; i < self->m4; i++) {
        float t = (float)fn_8055AF00(obj, IdAt(self->m0, i));
        self->m220[i] = -t;
    }
    fn_8057CCE8(self);
}

extern "C" DB_OVERLAY void fn_8057CBA4(DbSL* self)
{
    void* s = lbl_8061930C;
    unsigned i = 0;
    for (; i < self->m4; i++) {
        float t = fn_80079E74__18Unk8007B2B0_Screeni(s, fn_80075948__18Unk8007B2B0_Screeni(s, IdAt(self->m0, i)));
        self->m220[i] = t;
    }
    fn_8057CCE8(self);
}

extern "C" DB_OVERLAY unsigned fn_8057CC30(DbSL* self, int id)
{
    unsigned n = self->m4;
    unsigned i = 0;
    for (; i < n; i++) {
        if (id == IdAt(self->m0, i))
            return i;
    }
    int c = fn_800758F8__Fi(id);
    unsigned r = 0;
    if (c == 0)
        r = self->m4;
    return r;
}

extern "C" DB_OVERLAY int fn_8057CCA4(DbSL* self, int id)
{
    int d = self->m4 / 6;
    return (int)fn_8057CC30(self, id) / d;
}

/* near-miss: ~10 slots; same loop nest, retail reloads m4 before the inner loop and keeps the bound in r9 */
extern "C" DB_OVERLAY void fn_8057CCE8(DbSL* self)
{
    for (int i = 0; i < self->m4 - 1; i++) {
        for (int j = i + 1; j < self->m4; j++) {
            if (self->m220[j] <= self->m220[i])
                continue;
            int idi = IdAt(self->m0, i);
            float fi = self->m220[i];
            int idj = IdAt(self->m0, j);
            GrowTo(self, i);
            self->m0[i] = idj;
            self->m220[i] = self->m220[j];
            GrowTo(self, j);
            self->m0[j] = idi;
            self->m220[j] = fi;
        }
    }
}
