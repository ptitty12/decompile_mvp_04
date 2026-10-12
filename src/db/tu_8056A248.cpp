/*
 * Database overlay code, .database_codeoverlay 0x8056A248-0x8056BAEC (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"
#include "game/clampiter.h"

extern "C" void fn_8037866C(void* p);

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

struct Unk8024F730_C {
    const void* m0;
    Unk8024F730_C();
};

inline void* operator new(unsigned int, void* p) { return p; }

/* Screen link object (ctor fn_8056B9DC, dtor fn_8056BA20, init fn_8056BA80): base ctor fn_803785E4 at
 * +0, vptr at +8, a Unk8024F730_C-style member at +0xC, mode word at +0x10, owner at +0x14. */
struct Db8056B9DC_S {
    int m0;
    int m4;
    const void* m8;
    Unk8024F730_C mC;
    int m10;
    void* m14;
};
extern char lbl_80683ED0[];
extern char lbl_80660F08[];
extern char lbl_80649DB8[];
extern "C" void fn_803785E4(void* sub);
extern "C" void fn_80378620(void* sub, int a);
extern "C" void fn_80378A34(void* sub, void* o);
extern "C" void fn_8056BACC(void* p);

extern "C" int fn_80078A38__18Unk8007B2B0_Screeni(void* a0, int a1);
extern "C" int fn_8007E10C__FP13Unk8007DB74_A(void* a0, int a1);
extern "C" int fn_8007E1F8__FP13Unk8007DB74_A(void* a0, int a1);
extern "C" int fn_8007E2D8__FP13Unk8007DB74_AiiPi(void* a0, int a1, int a2, int* a3);
extern "C" void fn_8007E154__FP13Unk8007DB74_Aii(void* a0, int a1, int a2);
extern "C" unsigned fn_8056A2F8(TblSet t, unsigned from, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_8056B328(TblSet t, unsigned lim, int id);

struct Db8056B8C0_Src;
extern "C" void fn_8056B8C0(int* dst, Db8056B8C0_Src* src);
extern const char* lbl_80622810;
extern const char* lbl_80622814;

/* Name-hash object (ctor fn_8056A248): four words copied from the source by fn_8056B8C0, then six
 * hashes of the strings 3A1 .. 1A2 and two of the shared name pointers. */
struct Db8056A248_S {
    int m0[4];
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

int fn_8007FB98(Unk8007F198_C* s, int a, int b, int c);
int fn_8007FDA8(Unk8007F198_C* s, int a, int b);
extern void* lbl_80619948;
extern "C" int fn_800A2EB4(void* p);

extern "C" int fn_8056B094(TblSet t, int a, int* out, int max, int X);
extern "C" int fn_8056B8E4(TblSet t, int val, int* out, int cnt, int max, int kind);

extern "C" int fn_8007B320__18Unk8007B2B0_Screenii(void* a0, int a1, int a2);
int fn_80083FC0(int a);
extern "C" int fn_8056B628(TblSet t, int key, int k2);

extern "C" DB_OVERLAY Db8056A248_S* fn_8056A248(Db8056A248_S* self, Db8056B8C0_Src* src)
{
    fn_8056B8C0(self->m0, src);
    self->m10 = fn_800736EC(lbl_80622810);
    self->m14 = fn_800736EC(lbl_80622814);
    self->m18 = fn_800736EC("3A1");
    self->m1C = fn_800736EC("3A2");
    self->m20 = fn_800736EC("2A1");
    self->m24 = fn_800736EC("2A2");
    self->m28 = fn_800736EC("1A1");
    self->m2C = fn_800736EC("1A2");
    return self;
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

extern "C" DB_OVERLAY int fn_8056AA08(TblSet t, int key, int kind)
{
    unsigned n = TblAt(t, kind)->m4;
    int lo = fn_8056A8E0(t, key, kind);
    if (lo == -1)
        return 0;
    Unk80329FA0_Out ref = fn_80329FA0(key);
    int a = ref.m0;
    unsigned i = lo;
    if (i < n) {
        do {
            int v = KeyAt(TblAt(t, kind), i);
            if (v != key) {
                Unk80329FA0_Out o = fn_80329FA0(v);
                if (o.m0 != a)
                    return 1;
                break;
            }
            i++;
        } while (i < n);
    }
    return key == KeyAt(TblAt(t, kind), n - 1);
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

extern "C" DB_OVERLAY int fn_8056AB84(TblSet t, int key, int kind)
{
    Unk8007F198_C* sc = (Unk8007F198_C*)lbl_8061930C;
    int lo = fn_8056A8E0(t, key, kind);
    int hi = fn_8056A908(t, key, kind);
    if (lo != -1 && hi != -1) {
        if (fn_800A2EB4(lbl_80619948) == 0) {
            while (fn_8007FB98(sc, hi, 1, kind) == 0) {
                hi--;
                if ((unsigned)hi < (unsigned)lo)
                    return 1;
            }
            return fn_8007FDA8(sc, hi, kind);
        }
        return fn_8007FDA8(sc, hi, kind);
    }
    return 1;
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

inline int EntUsed(Unk8052B5C4_Ent* base, int o)
{
    return ((Unk8052B5C4_Ent*)(o + (int)base))->f4 != 0;
}

extern "C" DB_OVERLAY int fn_8056AE78(TblSet t, int a, int k, int* out, int max)
{
    int kind = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(k);
    int cnt = 0;
    int other = fn_8056A5F4(t, kind, a, k);
    unsigned n = TblAt(t, kind)->m4;
    unsigned i = 0;
    i = cnt;
    if (i < n) {
        int* p = out;
        int o = 0;
        do {
            if (!EntUsed(TblAt(t, kind)->m8, o))
                break;
            if (fn_8056A580(t, kind, i, k) != 0 && fn_8056A580(t, kind, i, other) != 0) {
                *p = i;
                cnt++;
                p++;
                if (cnt >= max)
                    break;
            }
            i++;
            o += 0x1C;
        } while (i < n);
    }
    return cnt;
}

struct Db8056AF84_G {
    char pad0[0x28];
    TblSet m28;
};

extern "C" DB_OVERLAY void fn_8056AF84(TblSet t, int a, int X, int* c1, int* c2)
{
    int buf[0x3E];
    TblSet ts = ((Db8056AF84_G*)lbl_80619948)->m28;
    int n = fn_8056B094(t, a, buf, 0x3E, X);
    int skip = -1;
    int kind = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(a);
    if (kind == 0)
        skip = fn_8056AD54(t, 0);
    *c1 = 0;
    *c2 = 0;
    int i;
    for (i = 0; i < n; i++) {
        int idx = buf[i];
        if (EntUsed(TblAt(t, kind)->m8, idx * 0x1C) == 1 && skip != idx) {
            if (fn_8056A838(ts, idx, a) == 1)
                (*c1)++;
            else
                (*c2)++;
        }
    }
}

extern "C" DB_OVERLAY int fn_8056B094(TblSet t, int a, int* out, int max, int X)
{
    int kind = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(a);
    int cnt = 0;
    unsigned from = 0;
    int* p = out;
    int i;
top:
    i = fn_8056A2F8(t, from, 0, 2, 4, a, 0, 2, 0, 0x1A);
    if (i == -1)
        goto done;
    {
        Unk80329FA0_Out o = fn_80329FA0(KeyAt(TblAt(t, kind), i));
        int d = o.m0 - 1;
        if (d == X) {
            int ofs = i * 0x1C;
            Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(ofs + (int)TblAt(t, kind)->m8);
            if (e->m4[0].m0 != e->m4[1].m0) {
                *p = i;
                cnt++;
                p++;
            }
        } else if (d >= X)
            goto done;
        from = i + 1;
    }
    goto top;
done:
    int j;
    for (j = cnt; j < max; j++)
        out[j] = -1;
    return fn_8056B8E4(t, X, out, cnt, max, kind);
}

extern "C" DB_OVERLAY int fn_8056B1D0(TblSet t, unsigned* pos, int kind)
{
    int a = 0;
    unsigned n = TblAt(t, kind)->m4;
    Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(*pos * 0x1C + (int)TblAt(t, kind)->m8);
    unsigned i = *pos;
    int b = 0;
    int k1 = e->m4[0].m0;
    int k2 = e->m4[1].m0;
    if (i < n) {
        do {
            if (fn_8056A838(t, i, k1) != 0)
                a++;
            else
                b++;
            unsigned nx = i + 1;
            i = fn_8056A2F8(t, nx, 0, 2, kind, k1, 0, 2, 0, 0x1A);
            if ((int)i == -1) {
                *pos = n;
                break;
            }
            if (fn_8056A5F4(t, kind, i, k1) != k2) {
                *pos = nx;
                break;
            }
            if (!EntUsed(TblAt(t, kind)->m8, i * 0x1C)) {
                *pos = i;
                return 3;
            }
        } while (i < n);
    }
    if (b != 0)
        return a != 0 ? 2 : 1;
    return 0;
}

extern "C" DB_OVERLAY int fn_8056B328(TblSet t, unsigned lim, int id)
{
    int r = 0;
    int k = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, id);
    unsigned i = 0;
    for (;;) {
        i = fn_8056A2F8(t, i, 0, 1, k, id, 0, 2, 0, 0x1A);
        if (i >= lim || i == (unsigned)-1)
            return r;
        i++;
        r++;
    }
}

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

extern "C" DB_OVERLAY void fn_8056B45C(TblSet t, int a, int id)
{
    void* sc = lbl_8061930C;
    int n = fn_8007E10C__FP13Unk8007DB74_A(sc, id);
    int v = fn_8007E1F8__FP13Unk8007DB74_A(sc, id);
    int sp8 = 0;
    fn_8007E2D8__FP13Unk8007DB74_AiiPi(sc, id, v, &sp8);
    fn_8007E154__FP13Unk8007DB74_Aii(sc, id, (sp8 + fn_8056B328(t, a, id)) % n);
}

extern "C" DB_OVERLAY int fn_8056B4FC(TblSet t, int key, int X)
{
    void* sc = lbl_8061930C;
    Unk8006A138_It<3> it(0);
    int k = 0;
    do {
        int m = fn_8007B320__18Unk8007B2B0_Screenii(sc, fn_80083FC0(k), X);
        if (TblAt(t, it.v)->m4 != 0) {
            unsigned lo = fn_8056A8E0(t, key, it.v);
            unsigned hi = fn_8056A908(t, key, it.v);
            if (fn_8056B628(t, key, m) == 1) {
                unsigned i = fn_8056A2F8(t, 0, 0, 1, 4, m, 0, 2, 0, 0x1A);
                if ((int)i != -1 && i <= hi && i >= lo)
                    return 1;
            }
        }
        k = it.Next();
    } while (k <= 3);
    return 0;
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

extern "C" DB_OVERLAY int fn_8056B8E4(TblSet t, int val, int* out, int cnt, int max, int kind)
{
    int r = cnt;
    int idx = fn_8056AD54(t, kind);
    if (idx != -1) {
        Unk80329FA0_Out o = fn_80329FA0(KeyAt(TblAt(t, kind), idx));
        if (val == o.m0 - 1) {
            if (r == 0) {
                out[0] = idx;
            } else {
                int i;
                for (i = 0; i < r; i++) {
                    if ((unsigned)out[i] > (unsigned)idx) {
                        int j;
                        for (j = cnt; j > i; j--)
                            out[j] = out[j - 1];
                        out[i] = idx;
                        break;
                    }
                }
            }
            r = cnt + 1;
        }
    }
    return r;
}

extern "C" DB_OVERLAY Db8056B9DC_S* fn_8056B9DC(Db8056B9DC_S* self)
{
    fn_803785E4(self);
    self->m8 = lbl_80683ED0;
    new (&self->mC) Unk8024F730_C;
    return self;
}

extern "C" DB_OVERLAY void fn_8056BA20(Db8056B9DC_S* self, int chrg)
{
    self->m8 = lbl_80683ED0;
    fn_8056BACC(self);
    self->mC.m0 = lbl_80660F08;
    self->m8 = lbl_80649DB8;
    fn_80378620(self, chrg);
}

extern "C" DB_OVERLAY void fn_8056BA80(Db8056B9DC_S* self, void* src, int flag)
{
    if (flag == 1)
        self->m10 = flag;
    else
        self->m10 = 0;
    self->m14 = src;
    fn_80378A34(src, self);
}

extern "C" DB_OVERLAY void fn_8056BACC(void* p)
{
    fn_8037866C(p);
}
