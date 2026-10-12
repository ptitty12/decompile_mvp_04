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

extern "C" void fn_8057C2C4(void* self, int* a, int* b, int* c);
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
/* forward declarations (definitions are in address order) */
extern "C" void fn_805788CC(char* self);
extern "C" int fn_80578974(DbHost* self, int a, int b);
extern "C" void fn_80578A60(DbHost* self, int a, int b);
extern "C" void fn_80578AE8(DbHost* self, int a, int b);
extern "C" void fn_8057C0B8(int* nA, int* nB, float* ratio, int cur, int mode, int who, int p6, int p7, int s8, int sC, int left);
extern "C" int fn_8057C21C(int id);
extern "C" int fn_8057C270(int id);
extern "C" int fn_8057C3F8(void* self);
extern "C" DbFixList* fn_8057C8F8(DbFixList* self, unsigned flags);
extern "C" void fn_8057C99C(void* self, int chrg);
extern "C" void fn_8057C9D0(DbSL* self, int flag);
extern "C" void fn_8057CA60(DbSL* self, int flag);
extern "C" void fn_8057CAF8(DbSL* self);
extern "C" void fn_8057CBA4(DbSL* self);
extern "C" unsigned fn_8057CC30(DbSL* self, int id);
extern "C" int fn_8057CCA4(DbSL* self, int id);
extern "C" void fn_8057CCE8(DbSL* self);

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

extern "C" DB_OVERLAY int fn_8057C3F8(void* self)
{
    int a, b, c;
    fn_8057C2C4(self, &a, &b, &c);
    return b;
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
