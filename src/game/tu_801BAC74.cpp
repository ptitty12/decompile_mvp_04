/*
 * Game code, .text 0x801BAC74-0x801BDD60 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801BAC74.h"
#include "game/tu_801C16B0.h"
#include "game/clampiter.h"

typedef Unk801B7FB0_P P;
typedef Unk801B7FB0_B B;
typedef Unk801B7FB0_Ai A;
extern float lbl_805CFCA0;
extern int lbl_8061CB78;
extern int lbl_8061CB7C;
extern const char lbl_805CFBAC[];
struct Unk801BAC74_PV32 : public Unk801B7FB0_PBase {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int x);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual int v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31(void* x);
    virtual void v32(void* x);
};
struct Unk801BAC74_O {
    char pad0[0x1750];
    int m1750;
};
struct Unk801BAC74_Rec {
    char pad0[0x2C];
    int m2C;
};

extern "C" {
P* fn_801A4C74(P* ctx, int i);
int fn_801BA130(B* b, unsigned i, int* p, float f);
void fn_801B7FD4(P* p);
void fn_801B9EC0(B* b);
int fn_801BA958(B* b);
int fn_801BA974(B* b);
int fn_801BA9A4(B* b);
int fn_801BA9B8(B* b);
void fn_801BE0A4(B* b);
void fn_801B6AC4(P* p);
void fn_801B6CD0(P* p);
void fn_801B7394(P* p);
void fn_801B9004(P* p);
void fn_801BCFA8(A* a);
struct Unk801BAC74_Rec* fn_801A6DB8(P* p);
void fn_801BFB7C(void* o);
void fn_802520F8(P* p);
void fn_801B9E04(B* b, P* p);
void fn_8017B6C0(int a, int b, int c);
void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
void fn_801BFC1C(void* o);
P* fn_80259C78(int h, int k);
void fn_801B7D1C(P* p);
int fn_801BFA20(const Vec3* v);
void fn_801BFC8C(void* o);
void fn_801BFBEC(void* o);
void fn_801BDDC8(B* b, P* p);
int fn_801C1950(A* a);
int fn_801DBF68(int h);
int fn_80254984(void* s);
int fn_802548F0(void* s);
int fn_80247858(P* p, float* t);
P* fn_801A4B34(P* ctx);
int fn_8014E310(int x);
P* fn_80257DFC(int h, P* q, int dir);
int fn_8035E318(void* p);
void fn_8017B658(int a, int k);
void* fn_80234E44(void* p);
void fn_8017B9F8(int a);
void fn_801BDB84(B* b, P* p, int a, int c, const Vec3* v);
int fn_801BFAF8(const Vec3* v);
void fn_801B9880(B* b, P* q);
void fn_801B7FF8(P* p);
void fn_801BB0C8(A* a);
void fn_801BDE24(B* b, P* p);
void fn_801BDE58(B* b, P* p, int z);
int fn_8017E1E0(int h, P* p, P* q);
int fn_801BDD18(A* a, P* q);
void fn_801BB668(A* a, P* q);
int fn_801BC660(A* a, P* q, P* p3, int mode, int flag);
void fn_8025777C(int h, P* q, int mode);
void fn_801BFD64(void* o, P* q, int idx, int mode);
}
struct Unk8024EF40_A;
int fn_80254EA4(Unk8024EF40_A* s, int i);
void fn_802553BC(Unk8024EF40_A* s, int i);
void fn_802547C0(Unk8024EF40_A* s, int i);
void fn_8025505C(Unk8024EF40_A* s, int i, int j);
struct Unk8024EF40_W;
int fn_8025416C(Unk8024EF40_W* s, int i);
struct Unk8017A930_T;
void fn_8017BAA0(Unk8017A930_T* t, int a, int b, int c);
int fn_803445A0(int* p);
void fn_80303CA0(const char* fmt, float a, float b, float c, ...);
extern const char lbl_805CFD34[];
struct Unk801BC660_S {
    int m0;
    unsigned m4;
    float m8;
    char padC[0xC];
    float m18;
    int m1C;
    char pad20[0x10];
    int m30;
};
extern char lbl_80660380[];
class Unk801BB668_Ev {
public:
    Unk801BB668_Ev(int id) { m0 = id; }
    int m0;
    virtual ~Unk801BB668_Ev() {}
};
class Unk802A9C34 : public Unk801BB668_Ev {
public:
    Unk802A9C34() : Unk801BB668_Ev(0x39)
    {
        m8 = 0;
        m18 = 0;
        m1C = -1.0f;
    }
    virtual ~Unk802A9C34() {}
    int m8;
    int mC;
    float m10;
    char m14;
    char m15;
    char m16;
    int m18;
    float m1C;
};
extern "C" void fn_802A9C34__11Unk802A9C34ifcicc(Unk802A9C34* e, int a, float f, unsigned char b, int c, unsigned char d, unsigned char g);
struct Unk8024EF40_P;
void fn_80252588(Unk8024EF40_P* p, int n);

















inline P* Get(P* c, unsigned i)
{
    if (i <= 0xC)
        return c->m65C[i];
    return 0;
}



inline void NextR(int& r)
{
    int x = r;
    int n = x + 1;
    if (x > 0x15)
        n = x;
    r = n;
}

extern "C" int fn_801BAC74(A* a, unsigned i, int* p, float f) { return fn_801BA130(a->m8, i, p, f); }

inline float Unk801BACA0_Roll(A* a, const char* file, int line, float k)
{
    unsigned n = a->m14->m554->fn_8014D8AC(1000000, file, line);
    return (float)n * k * 1e-6f;
}

extern "C" void fn_801BACA0(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                p->v30();
        }
    }
    a->m8->m30 = 0;
    a->m24 = 0;
    const char* file = lbl_805CFBAC;
    a->m28 = Unk801BACA0_Roll(a, file, 0x443, 0.22999996f) + 0.92f;
    a->m2C = -(Unk801BACA0_Roll(a, file, 0x444, 0.22999996f) + 0.92f);
    a->m34 = Unk801BACA0_Roll(a, file, 0x445, 0.30000007f) + 0.9f;
    a->m30 = -(Unk801BACA0_Roll(a, file, 0x446, 0.30000007f) + 0.9f);
}

extern "C" void fn_801BAE90(A* a)
{
    void* v = a->m14->m65C[9];
    if (v) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                p->v31(v);
        }
    }
}

extern "C" void fn_801BAF08(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                p->v33();
        }
    }
    a->m14->m6F8->m14->t[0].m110 = 0;
    Unk801B7FB0_Team* e = &a->m14->m6F8->m14->t[1];
    e->m110 = 0;
}

extern "C" void fn_801BAFA4(A* a)
{
    lbl_8061CB78 = 0;
    lbl_8061CB7C = 0;
    a->m8->m10 = 0;
    a->m8->m18 = 0;
    a->m8->m1C = 0;
    a->m8->m20 = 0;
    a->m1C = 0;
    a->m20 = 0;
    a->m4 = 0;
    B* b = a->m8;
    b->m2C = 6;
    b->mC = 0;
    Unk8006A138_It<3> it(0);
    int i = it.v;
    do {
        int q = i * 12 + (int)a;
        q += 0x38;
        *(int*)q = 0;
        *(int*)(q + 4) = -1;
        *(float*)(q + 8) = lbl_805CFCA0;
        i = it.Next();
    } while (i <= 3);
    if (a->m14->m6F4 == 0) {
        void* v = a->m14->m65C[9];
        if (v) {
            for (int j = 0; j <= 3; j++) {
                P* p = fn_801A4C74(a->m14, j);
                if (p)
                    ((Unk801BAC74_PV32*)p)->v32(v);
            }
        }
    }
}

extern "C" void fn_801BB0C8(A* a)
{
    a->m14->m6F8->m14->t[0].m10C = 0;
    Unk801B7FB0_Team* e = &a->m14->m6F8->m14->t[1];
    e->m10C = 0;
}

extern "C" void fn_801BB0F4(A* a)
{
    fn_801BB0C8(a);
    fn_801BDDC8(a->m8, a->m14->m6CC);
    a->m8->m28 = 4;
}

extern "C" void fn_801BB13C(A* a)
{
    fn_801BB0C8(a);
    B* b = a->m8;
    b->mC = 1;
    b->m2C = 6;
    P* p = fn_801A4C74(a->m14, 0);
    if (p)
        fn_801B7FD4(p);
}

extern "C" void fn_801BB194(A* a) { a->m8->m18 = 1; }

extern "C" void fn_801BB1A4(A* a) { fn_801BDDC8(a->m8, a->m14->m6CC); }

extern "C" void fn_801BB1D0(A* a) { a->m8->m1C = 1; }

struct Unk8017A930_T;
void fn_8017B994(Unk8017A930_T* p);
extern int* lbl_8061B9C4;
extern "C" {
void fn_801BBC9C(A* a, int* out);
void fn_801BB338(A* a, int x, int y);
int fn_801D0294(void* p);
void* fn_801C1638(P* p, unsigned i);
void fn_801BD878(A* a, P* q);
void fn_801BDA38(A* a, P* q);
void fn_801BDB38(A* a, P* q);
int fn_801BBF0C(A* a);
int fn_801BBF18(A* a);
}

extern "C" void fn_801BB1E0(A* a, int flag)
{
    a->m8->m28 = 3;
    if (flag) {
        a->m8->m0 = 0;
        a->m4 = 1;
    } else
        a->m4 = flag;
    a->m24 = 0;
    int r = 0;
    fn_801BBC9C(a, &r);
    int m10 = a->m10;
    P* cur = a->m14->m6CC;
    Unk801B7FB0_Game* g = a->m14->m6F8;
    fn_801BB338(a, flag, r);
    if (fn_801D0294((char*)((Unk801C16B0_M4*)m10)->m3A4 + 0x28C) != 0 || r != 0) {
        if (g->m14->m1CCA == *lbl_8061B9C4 - 1 && (fn_801BBF0C(a) != 0 || fn_801BBF18(a) != 0)) {
            int ok = fn_801C1638(a->m14, 10) != 0;
            if (ok == 0 || g->m14->m1CC9 == 2) {
                fn_8017B994((Unk8017A930_T*)m10);
                fn_801BDB38(a, cur);
            } else
                fn_801BD878(a, cur);
        } else
            fn_801BD878(a, cur);
    } else
        fn_801BDA38(a, cur);
}

extern "C" int fn_801DC10C(int h);
struct Unk801BB338_Five {
    float v[5];
};
extern Unk801BB338_Five lbl_805CFCA4;
extern Unk801BB338_Five lbl_805CFCB8;
inline float Unk801BB338_Pick(const Unk801BB338_Five* t, int idx)
{
    Unk801BB338_Five tbl = *t;
    return tbl.v[idx];
}
inline float Unk801BB338_Roll(A* a, const char* file, int line, float k)
{
    unsigned n = a->m14->m554->fn_8014D8AC(1000000, file, line);
    return (float)n * k * 1e-6f;
}
extern "C" void fn_801BB338(A* a, int x, int y)
{
    Unk801C16B0_M4* m10 = (Unk801C16B0_M4*)a->m10;
    Unk801B7FB0_Game* g = a->m14->m6F8;
    int kind = fn_801DC10C(m10->m3B8);
    if (x == 0 && y == 0 && (kind == 0xB || kind == 0xD)) {
        int w = fn_803445A0((int*)((char*)m10->m3A4 + 0x28C));
        if ((unsigned)(w - 2) <= 1) {
            int f = 0;
            Unk801B7FB0_Teams* t = g->m14;
            int idx = *(int*)((char*)a->m14->m6F8->m10 + 0x140);
            if (Unk801BAC74_Byte(t->m1CCA) > 1 || Unk801BAC74_Byte(t->m1CCB) > 2)
                f = 1;
            float lim = 0.0f;
            if (w == 2 || f != 0) {
                Unk801BB338_Five tbl = lbl_805CFCA4;
                lim = tbl.v[idx];
            } else {
                Unk801BB338_Five tbl = lbl_805CFCB8;
                lim = tbl.v[idx];
            }
            a->m24 = 0;
            if (!(Unk801BB338_Roll(a, lbl_805CFBAC, 0x556, 1.0f) > lim))
                a->m24 = 1;
        }
    }
}

extern "C" void fn_801BB4D8(A* a, int x)
{
    B* b = a->m8;
    b->mC = 2;
    b->m2C = x;
}

extern "C" int fn_801BB4EC(A* a) { return a->m8->m0 == -1 ? 0 : 1; }

extern "C" int fn_801BB508(A* a) { return a->m8->m0 == 1; }

extern "C" void fn_801BB520(A* a) { fn_801B9EC0(a->m8); }

/* near-miss: same code; the list cursor and its saved copy swap r30/r31. */
extern "C" void fn_801BB544(A* a, int flag)
{
    if (fn_801C1950(a) == 0) {
        ((Unk801BAC74_O*)a->m14->m6F8->mC->mC)->m1750 = 1;
        fn_801BDDC8(a->m8, a->m14->m6CC);
    }
    a->m20 = 1;
    P* p = fn_801A4B34(a->m14);
    P* last = 0;
    if (p) {
        P* cur;
        do {
            p->m5CC = fn_8014E310(p->m458 + 1);
            cur = p;
            p = fn_80257DFC(((Unk801C16B0_M4*)a->m10)->m3B4, cur, 1);
        } while (p);
        last = fn_80257DFC(((Unk801C16B0_M4*)a->m10)->m3B4, cur, 0);
    }
    if (flag) {
        P* q = last;
        if (q) {
            do {
                Unk801B7FB0_Sub58C* s = &q->m58C;
                *(int*)((char*)s + 0x40) = fn_8035E318(s);
                q = fn_80257DFC(((Unk801C16B0_M4*)a->m10)->m3B4, q, 1);
            } while (q);
        }
        fn_8017B658(a->m10, 3);
        a->m8->m28 = 2;
    }
}

extern "C" void fn_801BB65C(A* a) { a->m1C = 1; }

extern const Vec3 lbl_806055AC;
inline int Unk801BB800_M4A4(P* p) { return *(int*)((char*)p + 0x4A4); }
extern "C" void fn_801BB668(A* a, P* q)
{
    if (fn_801BC660(a, q, 0, 8, 1) == 1) {
        float t = 0.0f;
        fn_801BFD64(a->mC, q, fn_80247858(q, &t), 1);
        Unk802A9C34 m;
        fn_802A9C34__11Unk802A9C34ifcicc(&m, 8, t, *(unsigned char*)((char*)q + 0x70C), q->m5C4, 0xFF, 0xFF);
        fn_8037893C(&a->m14->m704, m.m0, &m, 0, 0);
        int kind = q->m458;
        for (int i = 0; i <= 3; i++) {
            int idx = i + 9;
            P* p = Get(a->m14, idx);
            if (idx != kind && p) {
                if (idx == 9) {
                    p->m5CC = 0;
                } else {
                    Unk801B7FB0_Sub58C* s = &p->m58C;
                    int v;
                    if (fn_80254EA4((Unk8024EF40_A*)s, 0) != -1)
                        v = fn_80254EA4((Unk8024EF40_A*)s, 0);
                    else
                        v = fn_8035E318(s);
                    *(int*)((char*)s + 0x40) = v;
                }
                Unk801B7FB0_Sub58C* s2 = &p->m58C;
                *(int*)((char*)s2 + 0x30) = *(int*)((char*)s2 + 0x40);
            }
        }
        fn_8017B658(a->m10, 4);
    }
}

extern "C" void fn_801BB800(A* a, int kind, P* p, P* q, int x)
{
    if (p == a->m14->m6CC) {
        if (kind == 1) {
            fn_801BDDC8(a->m8, p);
        } else if (kind == 0 || kind == 2) {
            if (p->m38C == 1 && Unk801BB800_M4A4(p) >= 0) {
                int k = q->m458;
                if (k == 9) {
                    if (fn_8017E1E0(a->m10, p, q) == 0) {
                        fn_80252588((Unk8024EF40_P*)q, x);
                        fn_801BDE24(a->m8, p);
                        fn_801BDE58(a->m8, p, 0);
                    } else {
                        fn_801BB668(a, q);
                    }
                } else if ((unsigned)(k - 10) <= 2 && fn_801BDD18((A*)a->m8, p)) {
                    fn_801BB668(a, q);
                } else {
                    Vec3 v = lbl_806055AC;
                    fn_801BDB84(a->m8, p, 1, 0, &v);
                }
            }
        } else if (kind == 3) {
            Vec3 v = lbl_806055AC;
            fn_801BDB84(a->m8, p, 1, 0, &v);
        }
    }
}

extern "C" void fn_801BB988(A* a) { a->m24 = 0; }

extern "C" void fn_801BB994(A* a)
{
    fn_801BE0A4(a->m8);
    a->m8->m28 = 0;
    int i = 0;
    do {
        P* p = fn_801A4C74(a->m14, i++);
        if (p)
            p->v34();
    } while (i <= 3);
}

extern "C" void fn_801BBA0C(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                fn_801B6AC4(p);
        }
    }
}

extern "C" void fn_801BBA6C(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            if (i != 0) {
                P* p = fn_801A4C74(a->m14, i);
                if (p)
                    fn_801B6CD0(p);
            }
        }
    }
}

extern "C" void fn_801BBAD4(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                fn_801B7394(p);
        }
    }
}

extern "C" void fn_801BBB34(A* a)
{
    P* c = a->m14;
    if (c->m6F4 == 0) {
        P* p = fn_801A4C74(c, 0);
        if (p)
            fn_801B9004(p);
    }
}

/* Stack object whose vptr is stored on entry and again at each scope exit. */
extern char lbl_8065F9B0[];
struct Unk801BAC74_G {
    const void* vptr;
    Unk801BAC74_G() { vptr = lbl_8065F9B0; }
    ~Unk801BAC74_G() { vptr = lbl_8065F9B0; }
};

extern "C" void fn_801BBB74(A* a)
{
    Unk801BAC74_G g;
    if (a->m4 != 0) {
        P* p = fn_80259C78(((Unk801C16B0_M4*)a->m10)->m3B4, 1);
        if (p != 0 && p->m5C4 != 0) {
            a->m4 = 0;
            return;
        }
        P* q = fn_801A4C74(a->m14, 2);
        if (q)
            fn_801B7D1C(q);
    }
}

extern "C" int fn_801BBC0C(A* a) { return fn_801BA958(a->m8); }

extern "C" int fn_801BBC30(A* a) { return fn_801BA974(a->m8); }

extern "C" int fn_801BBC54(A* a) { return fn_801BA9A4(a->m8); }

extern "C" int fn_801BBC78(A* a) { return fn_801BA9B8(a->m8); }

extern "C" int fn_801BBED4(A* a)
{
    int r = 0;
    if (a->m1C != 0 || a->m20 != 0)
        r = 1;
    return r;
}

extern "C" int fn_801BBEFC(A* a) { return a->m1C; }

extern "C" int fn_801BBF04(A* a) { return a->m20; }

extern "C" int fn_801BBF0C(A* a) { return a->m8->m18; }

extern "C" int fn_801BBF18(A* a) { return a->m8->m1C; }

extern "C" int fn_801BBF24(A* a) { return a->m8->m2C; }

extern "C" int fn_801BBF30(A* a, P* q)
{
    const float lim = 2.0f;
    int r = 1;
    if (a->m8->m0 == -1) {
        Vec3 v = q->m60;
        if (v.x * 0.083333336f < lim || !(v.z * 0.083333336f >= lim))
            r = 0;
    }
    return r;
}

extern "C" void fn_801BBFAC(A* a, P* q)
{
    B* b = a->m8;
    b->m2C = 6;
    b->mC = 1;
    a->m8->m0 = -1;
    fn_8017B9F8(a->m10);
    fn_801B9880(a->m8, q);
    a->m8->m28 = 1;
    P* p = fn_801A4C74(a->m14, 0);
    if (p)
        fn_801B7FF8(p);
}

extern const Vec3 lbl_806055AC;
extern "C" float fn_8018CA78(P* p);
extern "C" float fn_8018CAF0(P* p);
extern "C" void fn_801BC170(A* a, P* p, int mode, int z, int flag);

extern "C" void fn_801BC02C(A* a, P* p)
{
    if (a->m14->m6CC == p && a->m14->m6F4 != 9) {
        int flag = 0;
        int mode;
        if (p->m38C == 1) {
            Vec3 v = lbl_806055AC;
            fn_801BDB84(a->m8, p, 1, 0, &v);
            if (a->m8->m0 == 1) {
                mode = 5;
            } else {
                int g = 0;
                float x = fn_8018CA78(p);
                float y = fn_8018CAF0(p);
                if (!(y < 0.0f))
                    g = y < x;
                P** t = a->m14->m65C;
                P* e10 = t[10];
                P* e11 = t[11];
                P* e12 = t[12];
                if (e10 && e11 && e12)
                    flag = 1;
                mode = 0;
                if (g)
                    mode = 1;
            }
        } else
            mode = 2;
        fn_801BC170(a, p, mode, 0, flag);
    }
}

extern "C" void fn_801BC364(A* a)
{
    Unk8006A138_It<0x15> it(9);
    int i = it.v;
    while (i <= 0xC) {
        P* p = Get(a->m14, i);
        if (p)
            p->m5CC = 3;
        i = it.Next();
    }
}

enum Unk801BAC74_E { E_Neg = -1, E_Lo = 9, E_Hi = 12 };

extern "C" void fn_801BC3D0(A* a)
{
    Unk8006A138_It<0x15> it(9);
    int i = it.v;
    while (i <= 0xC) {
        int v = -1;
        switch ((Unk801BAC74_E)i) {
        case 9:
            v = 1;
            break;
        case 10:
            v = 2;
            break;
        case 11:
        case 12:
            v = 3;
            break;
        }
        P* p = Get(a->m14, it.v);
        if (p)
            p->m5CC = v;
        i = it.Next();
    }
}

/* near-miss: same code; retail keeps the player in r30 and its +0x58C sub-object in r31 (ours swapped). */
extern "C" void fn_801BC478(A* a)
{
    float t;
    int own = fn_801DBF68(((Unk801C16B0_M4*)a->m10)->m3B8);
    Unk8006A138_It<0x15> it(9);
    int i = it.v;
    do {
        P* p = Get(a->m14, i);
        if (p) {
            Unk801B7FB0_Sub58C* s = &p->m58C;
            if (fn_80254984(s) == 1 || *(int*)((char*)s + 0x44) == 1) {
                int k = fn_802548F0(s);
                int cnt;
                if (own != 0 || k != 0)
                    cnt = 1;
                else
                    cnt = 2;
                int base = *(int*)((char*)s + 0x38);
                if (p->m458 == 9) {
                    int w = fn_80247858(p, &t);
                    if (!(t >= 0.0f)) {
                        if (*(int*)((char*)s + 0x38) == w && w == 0)
                            cnt = 1;
                    }
                }
                int v = base + cnt;
                if (v <= 0)
                    v = 1;
                if (v > 3)
                    v = 3;
                *(int*)((char*)s + 0x40) = v;
            }
        }
        i = it.Next();
    } while (i <= 0xC);
}

extern "C" void fn_801BC5B4(A* a, P* p, int x, Vec3* v)
{
    if (p->m38C == 1) {
        int ok = 0;
        if (fn_801BFAF8(v) == 1 || x == 10 || x == 12 || x == 3)
            ok = 1;
        if (ok == 1) {
            Vec3 t = *v;
            fn_801BDB84(a->m8, p, 1, 1, &t);
        }
    }
}

extern "C" int fn_801BC660(A* a, P* q, P* p3, int mode, int flag)
{
    if (Unk801BAC74_Byte(a->m14->m6F8->m14->m1CC9) > 2)
        return 0;
    int r;
    if (q) {
        r = (((Unk801BC660_S*)&q->m58C)->m4 >> 29) & 1;
        r ^= 1;
    } else
        r = 0;
    if (q) {
        Unk801BC660_S* s = (Unk801BC660_S*)&q->m58C;
        if (!(s->m4 & 0x20000000) && (s->m8 == 0.0f || flag == 1)) {
            fn_802553BC((Unk8024EF40_A*)s, 0);
            fn_802547C0((Unk8024EF40_A*)s, 1);
            fn_8017BAA0((Unk8017A930_T*)a->m10, (int)q, (int)p3, mode);
            if (p3) {
                Unk801BC660_S* s3 = (Unk801BC660_S*)&p3->m58C;
                if (s3->m18 != 0.0f)
                    fn_80303CA0(lbl_805CFD34, 4.0f, 0.1f, 0.8f, s3->m1C + 1);
            }
            if (a->m24 == 0) {
                Unk801C16B0_M4* m4 = (Unk801C16B0_M4*)a->m10;
                char* o = (char*)m4->m3A4;
                if (mode == 6) {
                    if (a->m14->m6F4 == 0) {
                        switch (fn_803445A0((int*)(o + 0x28C))) {
                        case 1:
                            if (fn_8025416C((Unk8024EF40_W*)((char*)fn_801A4B34(a->m14) + 0x588), 0x21) != 0xE)
                                *(int*)(o + 0x288) = 3;
                            break;
                        case 2:
                        case 3:
                            *(int*)(o + 0x288) = 7;
                            break;
                        case 0:
                        case 4:
                        case 5:
                        case 6:
                            *(int*)(o + 0x288) = 4;
                            break;
                        case 7:
                            break;
                        }
                    }
                } else {
                    fn_8025777C(m4->m3B4, q, mode);
                }
            }
            s->m30 = -1;
            fn_8025505C((Unk8024EF40_A*)s, -1, 0);
        }
    }
    return r;
}

extern "C" void fn_801BCF88(A* a) { fn_801BCFA8(a); }

extern "C" void fn_801BD80C(A* a, P* q)
{
    if (fn_801A6DB8(a->m14)->m2C == 1) {
        fn_801BFB7C(a->mC);
        fn_802520F8(q);
        fn_801B9E04(a->m8, q);
        fn_8017B6C0(a->m10, 1, 0);
    }
}

extern "C" void fn_801BDA38(A* a, P* q)
{
    if (fn_801A6DB8(a->m14)->m2C == 1) {
        fn_801BDDC8(a->m8, q);
        Unk801BAC74_Msg m;
        m.Base(0x48);
        m.Derived();
        int t = *(int*)((char*)((Unk801C16B0_M4*)a->m10)->m3B0 + 0x38);
        m.Set(t, (int)fn_80234E44(((Unk801C16B0_M4*)a->m14->m700)->m3B0));
        fn_8037893C(&a->m14->m704, m.m0, &m, 0, 0);
        if (Unk801BAC74_Byte(a->m14->m6F8->m14->m1CCB) > 3) {
            fn_8017B6C0(a->m10, 0, 0);
            fn_801BFC8C(a->mC);
        } else
            fn_801BFBEC(a->mC);
        m.End();
    }
}

extern "C" void fn_801BDB38(A* a, P* q)
{
    fn_8037893C(&a->m14->m704, 0x55, 0, 0, 0);
    fn_801BFC1C(a->mC);
}

extern "C" int fn_801BDD18(A* a, P* q)
{
    Vec3 v = q->m60;
    return fn_801BFA20(&v) ^ 1;
}
