/*
 * Database overlay code, .database_codeoverlay 0x8056A248-0x8056BAEC (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"
#include "game/clampiter.h"

extern "C" void fn_8037866C();

typedef Unk8052B978_Tbl** TblSet;
extern Unk8007A4DC_Screen* lbl_8061930C;
extern "C" int fn_8052C390(Unk8052B978_Tbl* self, int key);
extern "C" int fn_8052BCC8(Unk8052B978_Tbl* self);
extern "C" int fn_8056A5B0(TblSet t, int kind, int idx, int key);
extern "C" int fn_8056A8E0(TblSet t, int key, int kind);
extern "C" int fn_8056A908(TblSet t, int key, int kind);
extern "C" int fn_8056AC44(TblSet t, int a, int kind);
extern "C" int fn_8056AC74(TblSet t, Unk8052B978_Tbl* tb, int idx);
extern "C" int fn_8056B658(TblSet t, int key, int k2);
extern "C" int fn_8056A580(TblSet t, int kind, int idx, int key);
int fn_8007FB2C(Unk8007F198_C* s, int a);

inline Unk8052B978_Tbl* TblAt(TblSet a, int i)
{
    int o = i * 4;
    return *(Unk8052B978_Tbl**)((char*)a + o);
}

inline int KeyAt(Unk8052B978_Tbl* t, int i)
{
    return *(unsigned short*)((char*)t->m8 + i * 0x1C);
}

extern "C" DB_OVERLAY int fn_8056A580(TblSet t, int kind, int idx, int key)
{
    return fn_8056A5B0(t, kind, idx, key) == 2 ? 0 : 1;
}

extern "C" DB_OVERLAY int fn_8056A5B0(TblSet t, int kind, int idx, int key)
{
    Unk8052B978_Tbl* g = TblAt(t, kind);
    int o = idx * 0x1C;
    Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(o + (int)g->m8);
    int k0 = e->m4[0].m0;
    int k1 = e->m4[1].m0;
    if (key != k0)
        return key == k1 ? 1 : 2;
    return 0;
}

extern "C" DB_OVERLAY int fn_8056A5F4(TblSet t, int kind, int idx, int key)
{
    int w = fn_8056A5B0(t, kind, idx, key) == 0;
    Unk8052B978_Tbl* g = TblAt(t, kind);
    int o = idx * 0x1C;
    char* e = (char*)(o + (int)g->m8);
    int off = w * 12 + 4;
    return *(int*)(e + off);
}

/* near-miss: registers only (42 vs 42 insns): retail keeps idx*0x1C in r0 and the table base in r10. */
extern "C" DB_OVERLAY int fn_8056A838(TblSet t, int idx, int k2)
{
    int kind = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(k2);
    int w = fn_8056A5B0(t, kind, idx, k2);
    int r;
    if (w == 2) {
        r = 0;
    } else {
        int o = idx * 0x1C;
        Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(o + (int)TblAt(t, kind)->m8);
        int z = w == 0;
        int b = e->m4[z].m4;
        int a = e->m4[w].m4;
        r = a > b;
    }
    return r;
}

extern "C" DB_OVERLAY int fn_8056A8E0(TblSet t, int key, int kind)
{
    return fn_8052C390(TblAt(t, kind), key);
}

/* near-miss: lower/upper-bound scan; same instructions except the loop is entered by the pretest and
 * rotated differently (39 vs 41 insns). */
extern "C" DB_OVERLAY int fn_8056A908(TblSet t, int key, int kind)
{
    int i = fn_8052C390(TblAt(t, kind), key);
    unsigned n = TblAt(t, kind)->m4;
    int last = 0;
    if ((unsigned)i < n) {
        int v = KeyAt(TblAt(t, kind), i);
        while (key == v) {
            i++;
            if ((unsigned)i >= n)
                goto done;
            v = KeyAt(TblAt(t, kind), i);
        }
        last = i - 1;
    }
done:
    if (i == n)
        return i - 1;
    if ((unsigned)last < n)
        return last;
    return -1;
}

extern "C" DB_OVERLAY int fn_8056A9AC(TblSet t, int key, int kind)
{
    int lo = fn_8056A8E0(t, key, kind);
    if (lo == -1)
        return 0;
    return fn_8056A908(t, key, kind) - lo + 1;
}

extern "C" DB_OVERLAY int fn_8056AAE4(TblSet t, int key, int kind)
{
    int i = fn_8052C390(TblAt(t, kind), key);
    for (; i != -1 && (unsigned)i < TblAt(t, kind)->m4 && KeyAt(TblAt(t, kind), i) == key; i++) {
        if (fn_8056AC44(t, i, kind) == 1)
            return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8056AC44(TblSet t, int a, int kind)
{
    return fn_8056AC74(t, TblAt(t, kind), a);
}

extern "C" DB_OVERLAY int fn_8056AC74(TblSet tt, Unk8052B978_Tbl* tb, int idx)
{
    int* t = (int*)tt;
    int o = idx * 0x1C;
    Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(o + (int)tb->m8);
    int k0 = e->m4[0].m0;
    int k1 = e->m4[1].m0;
    int s0 = t[4];
    if (k0 == s0 || k0 == t[5] || k0 == t[6] || k0 == t[7] || k0 == t[8] || k0 == t[9] || k0 == t[10] || k0 == t[11]) {
        if (k1 == s0 || k1 == t[5] || k1 == t[6] || k1 == t[7] || k1 == t[8] || k1 == t[9] || k1 == t[10] || k1 == t[11])
            return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8056AD54(TblSet t, int kind)
{
    Unk8007F198_C* sc = (Unk8007F198_C*)lbl_8061930C;
    if (kind == 0) {
        unsigned i = 0;
        unsigned n = fn_8007FB2C(sc, 0);
        for (; i < n; i++) {
            if (fn_8056AC44(t, i, kind) == 1)
                return i;
        }
    }
    return -1;
}

extern "C" DB_OVERLAY int fn_8056ADD4(TblSet t, int key, int* out, int unused, int kind)
{
    unsigned n = TblAt(t, kind)->m4;
    int cnt = 0;
    unsigned i = fn_8052C390(TblAt(t, kind), key);
    if (i < n) {
        int* p = out;
        do {
            int o = i * 0x1C;
            Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(o + (int)TblAt(t, kind)->m8);
            if (*(unsigned short*)e != key)
                break;
            int b = e->m4[1].m0;
            int a = e->m4[0].m0;
            if (b != 0 && a != b) {
                *p = i;
                cnt++;
                p++;
            }
            i++;
        } while (i < n);
    }
    return cnt;
}

int fn_8007FB2C(Unk8007F198_C* s, int a);

extern "C" DB_OVERLAY int fn_8056B3CC(TblSet t, int x)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    unsigned cnt = 0;
    int j = 0;
    int kind = sc->fn_80078A38(x);
    unsigned n = fn_8007FB2C((Unk8007F198_C*)sc, kind);
    if (cnt < n) {
        do {
            if (fn_8056A580(t, kind, j, x) != 0)
                cnt++;
            j++;
        } while ((unsigned)j < n);
    }
    return cnt;
}

extern "C" DB_OVERLAY int fn_8056B628(TblSet t, int key, int k2)
{
    return fn_8056B658(t, key, k2) == -1 ? 0 : 1;
}

/* near-miss: ours rotates the scan loop through a bottom test (56 vs 55 insns); retail repeats the
 * key test after the increment and branches straight back to the body. */
extern "C" DB_OVERLAY int fn_8056B658(TblSet t, int key, int k2)
{
    int res = -1;
    int kind = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(k2);
    unsigned n = TblAt(t, kind)->m4;
    unsigned i = fn_8052C390(TblAt(t, kind), key);
    if (i < n && KeyAt(TblAt(t, kind), i) == key) {
        do {
            Unk8052B5C4_Ent* e = &TblAt(t, kind)->m8[i];
            int a = e->m4[0].m0;
            int b = e->m4[1].m0;
            if (a == k2 || b == k2) {
                if (a == b)
                    return -1;
                res = i;
                break;
            }
            i++;
        } while (i < n && KeyAt(TblAt(t, kind), i) == key);
    }
    return res;
}

extern "C" DB_OVERLAY int fn_8056B734(TblSet t, int k)
{
    int kind = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(k);
    unsigned n = TblAt(t, kind)->m4;
    unsigned i = fn_8052BCC8(TblAt(t, kind));
    int cnt = 0;
    for (; i < n; i++) {
        int o = i * 0x1C;
        Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(o + (int)TblAt(t, kind)->m8);
        int a = e->m4[0].m0;
        int b = e->m4[1].m0;
        if (a == k || b == k) {
            if (a != b)
                cnt++;
        }
    }
    return cnt;
}

extern "C" DB_OVERLAY int fn_8056B7D0(TblSet t)
{
    int best = 0;
    Unk8006A138_It<3> it(0);
    int i = 0;
    do {
        Unk8052B978_Tbl* g = t[i];
        if (g->m4 != 0) {
            int v = KeyAt(g, g->m4 - 1);
            if (v > best)
                best = v;
        }
        i = it.Next();
    } while (i <= 3);
    return best;
}

extern "C" DB_OVERLAY int fn_8056B840(int a, int b)
{
    switch (b) {
    case 0:
        return 0x51;
    case 1:
        return 0x51;
    case 2:
        return 0xA2;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8056B87C(TblSet t)
{
    int best = 0x7FFFFFFF;
    int i;
    for (i = 0; i < 4; i++) {
        Unk8052B978_Tbl* g = t[i];
        if (g->m4 != 0) {
            int v = *(unsigned short*)g->m8;
            if (v < best)
                best = v;
        }
    }
    return best;
}

struct Db8056B8C0_Src {
    int pad[3];
    int m0C[4];
};

extern "C" DB_OVERLAY void fn_8056B8C0(int* dst, Db8056B8C0_Src* src)
{
    int i;
    for (i = 0; i < 4; i++)
        dst[i] = src->m0C[i];
}

extern "C" DB_OVERLAY void fn_8056BACC()
{
    fn_8037866C();
}
