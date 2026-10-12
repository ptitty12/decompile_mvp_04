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

extern "C" void fn_8057CCE8(DbSL* self);

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

extern "C" void fn_8057C2C4(void* self, int* a, int* b, int* c);
extern "C" void fn_80377408(void* p);
extern char lbl_8064A550[];

extern "C" DB_OVERLAY int fn_8057C3F8(void* self)
{
    int a, b, c;
    fn_8057C2C4(self, &a, &b, &c);
    return b;
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

extern "C" {
void fn_8055AC44(void* obj, int a);
int fn_8055AF00(void* obj, int id);
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
