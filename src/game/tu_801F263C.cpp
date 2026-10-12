/*
 * Game code, .text 0x801F263C-0x801F6680 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

struct Unk80283934_Goal;
float fn_802855C4(Unk80283934_Goal* g);

struct Unk801F263C_Node {
    Unk801F263C_Node* m0;
    char pad4[0x10 - 4];
    int m10;
    int m14;
    char m18[1];
};

struct Unk801F263C_Cmd {
    char pad0[0x14];
    int m14;
    char pad18[4];
    int m1C;
    int m20;
};

struct Unk801F263C_List {
    char pad0[0x934];
    Unk801F263C_Node* m934;
};

extern const float lbl_805D4EA8;
extern const float lbl_805D4E80;
extern Unk801EE438_Vec lbl_805D6790;
extern float lbl_805D4D68;

extern "C" {
int fn_801F5DD8(Scr* p, int a);
int fn_8024D408(int a);
int fn_8026D8E8(int a, int b);
int fn_80210FC4(Unk801EE438_G** g, int a, int b, int c);
int fn_80210DA8(Unk801EE438_G** g, int a, int b);
int fn_80211D34(void* p);
int fn_80247858(int a, int b);
int fn_80210D20(Unk801EE438_G** g, int a);
int fn_80210C98(Unk801EE438_G** g, int a);

float fn_801F263C(Scr* p, void* v)
{
    int tmp;
    return fn_801F2668(p, &tmp, v, -1);
}

inline Unk801EE438_Player* PlayerAt5E18(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

Unk801EE438_Player* fn_801F29AC(Scr* p, Unk801EE438_Game* g, Unk801EE438_Player* x)
{
    Unk801EE438_Player* r = fn_801EDE4C(p, g);
    return r != 0 ? (r == x ? p->m9C->m8[0] : r)
                  : (g->m38C == 3 ? (g->m374 == x ? g->m378 : g->m374)
                                  : (p->m9C->mA4 != -1 ? p->m9C->m8[p->m9C->mA4] : p->m9C->m8[0]));
}

extern const float lbl_805D4D58;

inline Unk801EE438_Vec Flat2FE0(Unk801EE438_Player* pl)
{
    Unk801EE438_Vec v = *(Unk801EE438_Vec*)((char*)pl + 0x60);
    v.m4 = lbl_805D4D58;
    return v;
}

extern "C" Unk801EE438_Vec fn_8020FF00(Scr* s, Unk801EE438_Game* g, Unk801EE438_Player* a, Unk801EE438_Player* b, int c, int d,
                                       Unk801EE438_Vec* pos, int e, int f);

/* near-miss (42 slots): same length and call shape; retail frame is 0x80 (return temp at sp+0x10, 0x1C bytes of other temps,
   flat-vector pair at 0x38/0x48 plus an 8-byte stack argument), ours 0x58 */
Unk801EE438_Vec fn_801F2FE0(Scr* s, Unk801EE438_Game* g, Unk801EE438_Player* pl, int c, int d, int e)
{
    Unk801EE438_Player* t = fn_801F29AC(s, g, pl);
    Unk801EE438_Vec w = Flat2FE0(pl);
    Unk801EE438_Vec r = fn_8020FF00(s, g, t, pl, c, d, &w, e, 0);
    return r;
}

/* near-miss (6 slots): only the f11/f12 assignment of the double (0x4330...) and float constants is swapped. */
int fn_801F30B8(Scr* p, Unk801EE438_Vec* out, float* outf)
{
    Unk801EE438_G* g = p->m9C;
    if (!(g->mC80 <= (float)g->m0->m4C * lbl_805D4D68)) {
        *out = g->mC4C;
        if (outf != 0) {
            Unk801EE438_G* h = p->m9C;
            *outf = h->mC80 - (float)h->m0->m4C * lbl_805D4D68;
        }
        return 1;
    }
    return 0;
}

extern "C" int fn_8020CFA8(Scr* p, Unk801EE438_Vec* a);
extern const Unk801EE438_Vec lbl_806055DC;
extern const float lbl_805D4D6C;
extern const float lbl_805D4D78;

int fn_801F316C(Scr* p)
{
    float k = lbl_805D4D6C;
    Unk801EE438_Vec v = lbl_806055DC;
    int r = 0;
    float f = fn_801F263C(p, &v);
    if (fn_8020CFA8((Scr*)((char*)p->m9C + 0x2C), &v) == 1)
        r = f - (float)p->m9C->m0->m4C * lbl_805D4D78 < lbl_805D4D6C;
    return r;
}

int fn_801F3B54(Scr* p)
{
    Unk801EE438_G* g = p->m9C;
    int r = 0;
    if (g->m54 == 1)
        r = g->m5C == 1;
    return r;
}

struct Unk801F3DB4_Cfg {
    char pad0[0x838];
    unsigned m838;
};

struct Unk801F3DB4_P {
    char pad0[0x618];
    Unk801F3DB4_Cfg* m618;
};

int fn_801F3DB4(Scr*, Unk801F3DB4_P* p)
{
    if (p == 0)
        return 0;
    Unk801F3DB4_Cfg* c = p->m618;
    if (c == 0)
        return 0;
    switch (c->m838) {
    case 0x0B0B3C8F:
    case 0x0E246B08:
    case 0x125671E2:
    case 0x1D2A62BD:
    case 0x5112B944:
    case 0x60075EEA:
    case 0x61469778:
    case 0x7BF65171:
    case 0x97DAA625:
    case 0xA68012D3:
    case 0xC3879806:
    case 0xFBBC2A99:
        return 1;
    }
    return 0;
}

void fn_801F418C(Scr* p, int v)
{
    p->m9C->m1C4 = v;
}

void fn_801F4198(Scr* p, int v)
{
    p->m9C->m1C0 = v;
}

inline int SubVal4EF4(int* base, int i)
{
    if (i == -1)
        return -1;
    int* q = base + i;
    return *q;
}

inline Unk801EE438_Player* PlayerAt4EF4(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

extern const float lbl_805D4E34;
extern const Unk801EE438_Vec lbl_805D6784;

extern const float lbl_805D4E1C;

inline Unk801EE438_Vec VecSub4844(const Unk801EE438_Vec& a, const Unk801EE438_Vec& b)
{
    Unk801EE438_Vec r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}

inline float Len2_4844(Unk801EE438_Vec v)
{
    return v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8;
}

extern "C" Unk801EE438_Vec fn_8014E388(unsigned idx);
extern "C" Unk801EE438_Vec fn_80379530(const Unk801EE438_Vec& a, const Unk801EE438_Vec& b, const Unk801EE438_Vec& c, float e, float f, int d);

float fn_801F4844(int, int a1, int idx, Unk801EE438_Vec* v, Unk801EE438_Vec* out)
{
    Unk801EE438_Vec p0 = fn_8014E388(a1);
    Unk801EE438_Vec p1 = fn_8014E388(idx);
    *out = fn_80379530(p0, p1, *v, lbl_805D4E1C, lbl_805D4E1C, 0);
    return Len2_4844(VecSub4844(*out, *v));
}

extern "C" Unk801EE438_Vec fn_801F4A10(Scr* s, int a, int b, Unk801EE438_Vec* pos, int c, float f);

Unk801EE438_Vec fn_801F492C(Scr* s, Unk801EE438_Vec* pos, int c, float f)
{
    Unk801EE438_Vec cur = *pos;
    int cnt = 0;
    int e = 0;
    do {
        int next = e != 3 ? e + 1 : 0;
        cur = fn_801F4A10(s, *(volatile int*)&cnt, next, &cur, c, f);
        int k = *(volatile int*)&cnt;
        int t;
        if (k > 3)
            t = k;
        else
            t = k + 1;
        *(volatile int*)&cnt = t;
        e = t;
    } while (e <= 3);
    return cur;
}

inline Unk801EE438_Vec Flat4E80(Unk801EE438_Game* g)
{
    Unk801EE438_Vec v = *(Unk801EE438_Vec*)((char*)g + 0x60);
    v.m4 = lbl_805D4E34;
    return v;
}

float fn_801F4E80(Scr* p)
{
    Unk801EE438_Vec w = Flat4E80(p->m9C->m4);
    return (w.m0 - lbl_805D6784.m0) * (w.m0 - lbl_805D6784.m0) + (w.m8 - lbl_805D6784.m8) * (w.m8 - lbl_805D6784.m8);
}

int fn_801F4EF4(Scr* p, int a1, int a2)
{
    Unk801EE438_G* g = p->m9C;
    Unk801EE438_Game* t = g->m0->m6CC;
    int v = SubVal4EF4(&g->mC0.m0, a1);
    if (v != -1) {
        if (t->m378 == PlayerAt4EF4(g->m8, a2) && t->m374 == PlayerAt4EF4(g->m8, v))
            return 0;
    }

    if (a1 == 3 && a2 != 1)
        return fn_80210D20(&p->m9C, 3) > 1;
    return fn_80210C98(&p->m9C, 1);
}

int fn_801F5214(float* a, float* b)
{
    return *a > *b;
}

struct Unk801F522C_Ow {
    char pad0[0x6BC];
    void** m6BC;
};
extern const Unk801EE438_Vec lbl_806055AC;
int fn_8019BA30(void** o, Unk801EE438_Vec* a, Unk801EE438_Vec* b, float* t, Unk801EE438_Vec* v, Unk801EE438_Vec* out, int* i, double* e, float f);

/* near-miss (4 slots): retail puts the 8-byte scratch at sp+0x20 and the first vector copy at sp+0x28; ours swaps them */
int fn_801F522C(Scr* p, const Unk801EE438_Vec* a, const Unk801EE438_Vec* b, Unk801EE438_Vec* out, Unk801EE438_Vec* out2, float f)
{
    void** o = ((Unk801F522C_Ow*)p->m9C->m0)->m6BC;
    if (o == 0) {
        *out = lbl_806055AC;
        return 0;
    }
    float x = 0.0f;
    Unk801EE438_Vec v = lbl_806055AC;
    int iv = 0;
    Unk801EE438_Vec a2 = *a;
    a2.m4 = a->m4 >? 6.0f;
    double e;
    Unk801EE438_Vec b2 = *b;
    b2.m4 = b->m4 >? 6.0f;
    int r = fn_8019BA30(o, &a2, &b2, &x, &v, out, &iv, &e, f) == -1 ? 0 : 1;
    if (out2 != 0)
        *out2 = v;
    return r;
}

int fn_801F5394()
{
    char buf[0xB8];
    return 0;
}

int fn_801F5DD8(Scr* unused, int a)
{
    if (a == 0x11 || a == 0x13 || a == 0x12 || a == 0x14 || a == 0x16 || a == 0x15)
        return 1;
    return 0;
}

inline Unk801EE438_Player* PlayerAt5FD4(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

inline Unk801EE438_Player* PlayerAtIdx5EF0(Unk801EE438_Owner* o, unsigned k)
{
    if (k <= 12)
        return o->m65C[k];
    return 0;
}

inline Unk801EE438_Player* PlayerAt5EF0(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

void fn_801F5E18(Scr* p)
{
    int found = 0;
    Unk801EE438_G* g = p->m9C;
    Unk801EE438_Player* t = g->m4->m36C;
    if (t != 0) {
        float d2 = (t->m60 - lbl_805D6790.m0) * (t->m60 - lbl_805D6790.m0) + (t->m68 - lbl_805D6790.m8) * (t->m68 - lbl_805D6790.m8);
        found = d2 < lbl_805D4E80;
    }
    Unk801EE438_It it;
    fn_8014E09C(&it, g->m0, 1);
    Unk801EE438_It* ip = &it;
    while (it.m8 != 10) {
        int i = it.m8;
        Unk801EE438_Player* q = PlayerAt5E18(p->m9C->m8, i);
        if (q != 0)
            fn_8024FBEC(&q->m4D8, found);
        fn_8014E108(ip);
    }
}

void fn_801F5EF0(Scr* p)
{
    int found = 0;
    unsigned i = 9;
    do {
        Unk801EE438_Player* pl = PlayerAtIdx5EF0(p->m9C->m0, i);
        if (pl != 0 && fn_80254EA4(&pl->m58C, 0) != -1) {
            found = 1;
            break;
        }
        i++;
    } while ((int)i <= 12);
    if (found == 0) {
        Unk801EE438_It it;
        fn_8014E09C(&it, p->m9C->m0, 1);
        Unk801EE438_It* ip = &it;
        while (ip->m8 != 10) {
            int i = ip->m8;
            Unk801EE438_Player* q = PlayerAt5EF0(p->m9C->m8, i);
            if (q != 0)
                fn_8024FC94(&q->m4D8);
            fn_8014E108(ip);
        }
    }
}

void fn_801F5FD4(Scr* p, int a)
{
    Unk801EE438_It it;
    fn_8014E09C(&it, p->m9C->m0, 1);
    Unk801EE438_It* ip = &it;
    while (ip->m8 != 10) {
        int i = ip->m8;
        fn_8024FC74(&PlayerAt5FD4(p->m9C->m8, i)->m4D8, a);
        fn_8014E108(ip);
    }
}

int fn_801F64E4(Unk801F263C_List* p)
{
    Unk801F263C_Node* n = p->m934;
    while (n != 0) {
        if (n->m14 == 0)
            break;
        n = n->m0;
    }
    if (n != 0) {
        Unk80283934_Goal* g = 0;
        if (n->m10 == 6)
            g = (Unk80283934_Goal*)n->m18;
        if (g != 0) {
            float f = fn_802855C4(g);
            if (f < lbl_805D4EA8)
                return 1;
        }
    }
    return 0;
}

int fn_801F6568(Scr* p, int a, Unk801F263C_Cmd* c)
{
    if (fn_801F5DD8(p, c->m14) == 1)
        return 0;
    if (fn_8024D408(a) != 0) {
        if (c->m20 == 5) {
            if (fn_80210FC4(&p->m9C, 2, 3, 0) == 1)
                return 1;
            if (c->m20 == 5 && fn_80210FC4(&p->m9C, 2, c->m1C, 0) == 0)
                return 1;
        }
        if (fn_8026D8E8(a, 0) == 1 && fn_80210DA8(&p->m9C, 4, fn_80211D34(&p->m9C->mE8)) == 0 &&
            fn_80247858(fn_80211D34(&p->m9C->mE8), 0) != c->m1C)
            return 1;
    }
    return 0;
}

}
