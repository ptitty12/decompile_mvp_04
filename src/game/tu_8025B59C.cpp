/*
 * Game code, .text 0x8025B59C-0x8025F708 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"
#include "game/goals/tu_8027C728.h"
#include "game/goals/tu_8027A84C.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

/* Object at ctx+0x3C0 read by fn_8025DF8C: signed state word at +0x14 (-1 = none, bit 0 / bit 1 = slot flags). */
struct Unk8025DF8C_O {
    char pad0[0x14];
    int m14;
};
struct Unk8025DF8C_Ctx {
    char pad0[0x3C0];
    Unk8025DF8C_O* m3C0;
};
inline int Unk8025DF8C_Bit(Unk8025DF8C_O* o, int m)
{
    int r;
    if ((unsigned)(o->m14 + 1) > 1) {
        r = 1;
        if (!(o->m14 & m))
            r = 0;
    } else
        r = 0;
    return r;
}

extern "C++" {
extern char lbl_806617E8[];
extern char lbl_80661800[];
struct Unk8025C960_F {
    float m0;
    int m4[4];
    Q* m14;
    int m18;
    int m1C;
};
typedef Unk8025C960_F F;
void fn_8025C998(F* self);
void fn_8025CAF0(F* self);
int fn_8025C9FC(F* self, P* p);
void fn_80259EC0(void* x, int a);
void fn_80377408(void* p);
int fn_8014E374(int a);
void fn_8025D0D4(I* i, int a, int b, int c);

inline P* Roster(Q* q, unsigned i) { if (i <= 0xC) return q->m65C[i]; return 0; }

struct Unk8025CF04_I {
    char pad0[0x18C];
    const void* m18C;
    char pad190[0x544 - 0x190];
    const void* m544;
};
void fn_8025E55C(I* self, P* p);
int fn_80269F88(void* g, P* p, int k);
int fn_80269E84(void* g, P* p, int k);
struct Unk80270BA0_X;
float fn_8024D050(Unk80270BA0_X* x, int a, int b, float c, float d);
int fn_8026DAE8(P* p, int k);
char* fn_8035E8CC(char* p, unsigned i);
void* fn_8035E604(void* p);
void fn_8035E704(char* t, int i);
int fn_8026A0DC(void* g, P* p);
void fn_8026AA04(char* r, int v, const char* file, int line);
int fn_801A2034(Q* q, int k);
int fn_802D7DB4(int a, int b);
int fn_8035E318(A* a);
int fn_802548BC(A* a, int k);
void fn_802609E8(I* i, P* p, int k, float* a, float* b);
void fn_80260D80(I* i, P* p, int k, float* a, float* b, float* c, int z);
int fn_801D0314(void* p);
void fn_8025D0B0(I* self, int a, int b);
int fn_8025CD18(F* self, P* p);
int fn_8025CC54(F* self, P* p);
struct Unk8025CF64_Pair {
    int m0;
    int m4;
    void Clear()
    {
        m4 = 0;
        m0 = 0;
    }
};
struct Unk8025CF64_I {
    char pad0[0x1FC];
    int m1FC;
    int m200;
    char pad204[0x41C - 0x204];
    int m41C;
    int m420;
    Unk8025CF64_Pair m424;
    Unk8025CF64_Pair m42C;
    P* m434;
    int m438[4];
    int m448;
    unsigned m44C;
    int m450[4];
    char pad460[4];
    int m464;
    char pad468[0x4BC - 0x468];
    int m4BC;
    float m4C0;
};
void fn_802663B8(void* p);
int fn_8025933C(char* p, int a);
void fn_80268998(void* p, int a);
void fn_8025F878(I* i);
void fn_80268144(void* p);
void fn_80269DE4(void* p);
extern const float lbl_805DB13C;
int fn_8014E310(int a);
unsigned char* fn_80081CF8(Unk8024EF40_Ent* e, int i);
P* fn_801A4910(Q* q, int f);
void fn_801A656C(Q* q, P* p);
void fn_802547C0(A* a, int v);
void fn_802553BC(A* a, int v);
void fn_8025505C(A* a, int v, int w);
void fn_8025E924(I* i, P* p, int f);
struct Unk8025C8A0_Pair {
    int idx;
    int (*fn)(void*);
};
struct Unk8025C8A0_Ev {
    char pad0[4];
    int m4;
    char pad8[0xC];
    int m14;
};
extern int lbl_8061E54C;
extern int (*lbl_8068CD54[18])(void*);
extern Unk8025C8A0_Pair lbl_805DAE50[18];
int fn_80266784(void* p);
int fn_80267B74(void* p);
void* fn_801A4B34(void* w);
extern const float lbl_805DB11C;
extern const float lbl_805DB120;
int fn_8018AD20(P* p);
void fn_802491D8(P* p);
void fn_8035E704(char* t, int i);
void fn_80242E28(P* p, float f);
extern float lbl_805DB200;
struct Unk8025E680_I {
    char pad0[0x1EC];
    Q* m1EC;
    char pad1F0[4];
    Unk8024EF40_Ctx* m1F4;
    char pad1F8[4];
    int m1FC;
    int m200;
    char pad204[0x438 - 0x204];
    P* m438[4];
    int m448;
};
int fn_801BBEFC(int a);
int fn_801BBF04(int a);
void fn_8025E654(I* i);
void fn_8026AA04(char* r, int v, const char* file, int line);
extern float lbl_805DB1C8;
struct Unk8025CB28_I {
    char pad0[0x1F0];
    M* m1F0;
    char pad1F4[4];
    int m1F8;
};
int fn_801DC67C(int a, int b);
P* fn_80257B40(M* self);
P* fn_80257BD0(M* self, P* p, int a);
float fn_802D7E2C(int a, int b);
float fn_802D7E88(int a, int b);
int fn_802D804C(float a, float b);
extern const float lbl_805DB1A8;
extern const float lbl_805E50BC;
extern const float lbl_805E50AC;
extern const float lbl_805E50B4;
extern const float lbl_805E50C4;
struct Unk8025CD18_C {
    char pad0[0x3A4];
    char* m3A4;
};
struct Unk8025CD18_I {
    char pad0[0x1EC];
    Q* m1EC;
    char pad1F0[4];
    Unk8025CD18_C* m1F4;
};
void* fn_802FDA84(int o, int k);
extern char lbl_805DB170[];
void fn_8027C728(Unk8027C728_Goal* g);
void fn_8025AB00(void* g, P* p);
extern float lbl_805DB20C;
extern float lbl_805DB210;
extern float lbl_805DB214;
}
extern "C" Unk8027C728_Goal* fn_802448F4(void* p, int k);

/* Request record of the goal setters at 0x8025BEC0 / 0x8025C18C / 0x8025C288: +8 id, +0x18 float, +0x28 target position, +0x34 state. */
struct Unk8025BEC0_E {
    char pad0[8];
    int m8;
    char padC[0x18 - 0xC];
    float m18;
    char pad1C[0x28 - 0x1C];
    Unk80273498_Vec3 m28;
    int m34;
};
struct Unk8025C18C_Ctx {
    char pad0[0x3B0];
    void* m3B0;
};
struct Unk8025C18C_Q {
    char pad0[0x700];
    Unk8025C18C_Ctx* m700;
};
struct Unk8028989C_Goal;
extern const float lbl_805DAE20;
extern const float lbl_805DAE34;
extern const float lbl_805DAE38;
extern "C++" {
void fn_80235AE4(void* self);
Unk8027A84C* fn_80289B14(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p);
Unk8027A84C* fn_80289AB0(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p);
Unk8027A84C* fn_802899E8(Unk8028989C_Goal* g, float f, const Unk80273498_Vec3* p);
void fn_802898FC(Unk8027A84C* g, float f);
}

/* By-value getters: the vector copy goes through a stack temporary, as in retail. */
inline Unk80273498_Vec3 Unk8025BEC0_Pos34(Unk8027C728_Goal* g)
{
    return *(Unk80273498_Vec3*)((char*)g + 0x34);
}
inline Unk80273498_Vec3 Unk8025BEC0_Pos28(Unk8025BEC0_E* e)
{
    return e->m28;
}

struct Unk8025D054_I {
    char pad0[0x1FC];
    int m1FC;
    int m200;
};

extern "C" void fn_8025E804(F* self);

inline float Lerp3(float a, float b, float t)
{
    return a + t * (b - a);
}

Unk8027C728_Goal* fn_8025BA38(void* self, P* p, int* z)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 1);
    int two = 2;
    g->m10 = two;
    fn_8027C728(g);
    fn_8025AB00(g->m18, p);
    z[0xD] = two;
    return g;
}

Unk8027C728_Goal* fn_8025BEC0(void* self, P* p, Unk8025BEC0_E* e)
{
    int two = 2;
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    g->m10 = 0xC;
    fn_8027C728(g);
    Unk8027A84C* x;
    {
        Unk80273498_Vec3 v = Unk8025BEC0_Pos28(e);
        x = fn_80289B14((Unk8028989C_Goal*)g->m18, lbl_805DAE20, &v);
    }
    x->m38 = 1;
    Unk8027C728_Goal* g2 = g->m0;
    g2->m10 = two;
    fn_8027C728(g2);
    fn_8025AB00(g2->m18, p);
    Unk80273498_Vec3 t = Unk8025BEC0_Pos34(g2);
    Unk80273498_Vec3 w = t;
    x->fn_8027A898(&w);
    e->m34 = two;
    return g;
}

Unk8027C728_Goal* fn_8025C18C(Unk8025C18C_Q* self, P* p, Unk8025BEC0_E* e)
{
    int two = 2;
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    Unk80273498_Vec3 v = Unk8025BEC0_Pos28(e);
    g->m10 = 0xC;
    fn_8027C728(g);
    Unk8027A84C* x = fn_802899E8((Unk8028989C_Goal*)g->m18, lbl_805DAE34, &v);
    fn_802898FC(x, e->m18);
    x->m38 = e->m8;
    Unk8027C728_Goal* g2 = g->m0;
    g2->m10 = two;
    char* gd = g2->m18;
    fn_8027C728(g2);
    fn_8025AB00(gd, p);
    if (*(int*)(gd + 0x2C) != 0) {
        Unk80273498_Vec3 w = Unk8025BEC0_Pos34(g2);
        x->fn_8027A898(&w);
    }
    e->m34 = two;
    fn_80235AE4(self->m700->m3B0);
    return g;
}

Unk8027C728_Goal* fn_8025C288(void* self, P* p, Unk8025BEC0_E* e)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 2);
    Unk80273498_Vec3 v = Unk8025BEC0_Pos28(e);
    g->m10 = 0xC;
    fn_8027C728(g);
    Unk8027A84C* x = fn_80289AB0((Unk8028989C_Goal*)g->m18, lbl_805DAE38, &v);
    fn_802898FC(x, e->m18);
    x->m38 = e->m8;
    Unk8027C728_Goal* g2 = g->m0;
    g2->m10 = 2;
    fn_8027C728(g2);
    char* gd = g2->m18;
    fn_8025AB00(gd, p);
    if (*(int*)(gd + 0x2C) != 0) {
        Unk80273498_Vec3 w = Unk8025BEC0_Pos34(g2);
        x->fn_8027A898(&w);
    }
    e->m34 = 0;
    return g;
}

Unk8027C728_Goal* fn_8025C378(void* self, P* p, int* z)
{
    Unk8027C728_Goal* g = 0;
    if (*(int*)((char*)p + 0x934) != 0 && fn_8026DAE8(p, 0) == 0) {
        g = fn_802448F4(p, 1);
        int two = 2;
        g->m10 = two;
        fn_8027C728(g);
        fn_8025AB00(g->m18, p);
        z[0xD] = two;
    }
    return g;
}

int fn_8025C8A0(void* self, int unused, Unk8025C8A0_Ev* ev)
{
    if (lbl_8061E54C == 0) {
        lbl_8061E54C = 1;
        for (int i = 0; i < 18; i++)
            lbl_8068CD54[i] = 0;
        for (int i = 0; i < 18; i++)
            lbl_8068CD54[lbl_805DAE50[i].idx] = lbl_805DAE50[i].fn;
    }
    int r = ev->m14;
    if (r == 0)
        r = lbl_8068CD54[ev->m4](self);
    return r;
}

F* fn_8025C960(F* self, int a, int b)
{
    self->m14 = (Q*)a;
    self->m18 = b;
    fn_8025C998(self);
    return self;
}

void fn_8025C998(F* self)
{
    fn_8025CAF0(self);
}

void fn_8025C9B8(F* self)
{
    self->m0 = Secs(self->m14) ;
}

/* near-miss: 63 vs 61 instructions; retail stores the float constant k to its slot but keeps using the register, and merges the early `return 0` exits. Tried const/plain k, nested ifs, inline add/compare */
int fn_8025C9FC(F* self, P* p)
{
    if (self->m0 < lbl_805DB11C)
        return 0;
    if (self->m1C == 0)
        return 0;
    if (fn_80266784((char*)self->m18 + 0x48) != 0 && fn_80267B74((char*)self->m18 + 0x48) != 0)
        return 0;
    P* pl = (P*)fn_801A4B34(((I*)self->m18)->m1EC);
    if (pl->m58C.b2)
        return 0;
    const float k = lbl_805DB120;
    float a = self->m0 + k;
    float s = Secs(self->m14);
    return a > s;
}

void fn_8025CAF0(F* self)
{
    self->m1C = 0;
    self->m0 = -1.0f;
    for (int i = 0; i < 4; i++)
        self->m4[i] = -1;
}

void fn_8025CB28(F* self)
{
    if (self->m1C == 0) {
        Unk8025CB28_I* in = (Unk8025CB28_I*)self->m18;
        if (fn_801DC67C(in->m1F8, self->m18) != 0) {
            M* m = ((Unk8025CB28_I*)self->m18)->m1F0;
            P* p = fn_80257B40(m);
            while (p != 0 && p->m458 != 9) {
                int idx = p->m458 - 9;
                int k = fn_802548BC(&p->m58C, 1);
                if (fn_8025CD18(self, p) != 0 || fn_8025CC54(self, p) != 0)
                    self->m4[idx] = k;
                p = fn_80257BD0(m, p, 0);
            }
            self->m1C = 1;
        }
    }
}

/* near-miss: self/p callee-saved registers swapped (retail self r31, p r30; no mr before the call) */
int fn_8025CBFC(F* self, P* p)
{
    if (p == 0 || fn_8025C9FC(self, p) == 0)
        return -1;
    return self->m4[p->m458 - 9];
}

/* near-miss: 48 vs 49 instructions; retail keeps self r31, p r29, a r30, g r28; ours allocates self r29, p r28. Tried local order, I* local, temp for the fn_8035E318 result */
int fn_8025CC54(F* self, P* p)
{
    int g = ((I*)self->m18)->m464 == 2;
    A* a = &p->m58C;
    if (fn_8035E318(a) == a->m38 && g)
        return 1;
    int k = fn_802548BC(a, 1);
    float s8, sC, s10, s14, s18;
    fn_802609E8((I*)self->m18, p, k, &s8, &s18);
    fn_80260D80((I*)self->m18, p, k, &sC, &s10, &s14, 0);
    return s14 > s8;
}

int fn_8025CD18(F* self, P* p)
{
    A* a = &p->m58C;
    int k = fn_802548BC(a, 1);
    int z = ((int (*)(I*, int, int))fn_8025D0B0)((I*)self->m18, p->m458, k) == 0;
    Unk8025CD18_I* in = (Unk8025CD18_I*)self->m18;
    int c = fn_801D0314(in->m1F4->m3A4 + 0x28C);
    int res = 0;
    if (c == 2 && z) {
        int t = p->m458;
        int lo = 0xA, hi = 0xB;
        P* pq = ((Unk8025CD18_I*)self->m18)->m1EC->m6CC;
        if ((t == hi || t == lo) && pq->m38C == 1 && a->m38 < k)
            res = 1;
    }
    return res;
}

int fn_8025CDD8(int x)
{
    int r = 0;
    int k = 0xB;
    if (x <= 0x10)
        r = x >= k;
    return r;
}

void fn_8025CF04(Unk8025CF04_I* self, int a)
{
    self->m544 = lbl_806617E8;
    fn_80259EC0((char*)self + 0x468, 2);
    self->m18C = lbl_80661800;
    if (a & 1)
        fn_80377408(self);
}

void fn_8025CF64(I* in)
{
    Unk8025CF64_I* self = (Unk8025CF64_I*)in;
    fn_802663B8((char*)self + 4);
    fn_8025C998((F*)((char*)self + 0x9C));
    fn_8025933C((char*)self + 0x204, (int)self);
    fn_8035E604((char*)self + 0x1CC);
    fn_80269DE4((char*)self + 0x190);
    fn_80268998((char*)self + 0xBC, -1);
    self->m420 = -1;
    self->m44C = self->m44C & 0x07FFFFFF;
    self->m4C0 = lbl_805DB13C;
    self->m200 = 0;
    self->m1FC = 0;
    self->m41C = 0;
    self->m434 = 0;
    self->m464 = 0;
    self->m4BC = 0;
    self->m448 = 0;
    for (int i = 0; i < 4; i++) {
        self->m438[i] = 0;
        self->m450[i] = 0;
    }
    fn_8025F878(in);
    self->m42C.Clear();
    self->m424.Clear();
    fn_80268144((char*)self + 0x124);
}

void fn_8025D054(Unk8025D054_I* self, int a)
{
    int t = self->m1FC;
    if (self->m200 != t)
        self->m200 = t;
    self->m1FC = a;
}

void fn_8025D070(int self, int a, int* o1, int* o2)
{
    int t = fn_8014E374(a);
    *o1 = t;
    *o2 = fn_8014E374(t);
}

void fn_8025D0B0(I* self, int a, int b)
{
    fn_8025D0D4(self, a, b, a);
}

void fn_8025D9E0(I* self, P* p, int k)
{
    char* g = (char*)self + 0x190;
    fn_80269E84(g, p, k);
    char* e = fn_8035E8CC((char*)self + 0x204, p->m458);
    if (k == 2) {
        fn_8026AA04(e, 9, lbl_805DB170, 0x312);
    } else if (k != 4) {
        int v = fn_8026A0DC(g, p);
        fn_8026AA04(e, v, lbl_805DB170, 0x316);
    }
}

void fn_8025DA78(I* self, P* p)
{
    char* g = (char*)self + 0x190;
    fn_80269F88(g, p, 3);
    fn_80269E84(g, p, 1);
}

int fn_8025DC40(I* self, int* a, int* b, int* c, int* d)
{
    *a = 0;
    *b = 0;
    *c = 0;
    *d = 0;
    int k = fn_801A2034(self->m1EC, 3);
    float t = fn_802D7E2C(k, 0xCA);
    int r = 0;
    if (!(t < lbl_805DB1A8)) {
        float f = fn_802D7E88(k, 0xCA);
        *a = fn_802D804C(f, lbl_805E50BC);
        *b = fn_802D804C(f, lbl_805E50AC);
        *c = fn_802D804C(f, lbl_805E50B4);
        *d = fn_802D804C(f, lbl_805E50C4);
        r = 1;
    }
    return r;
}

void fn_8025DED4(I* self)
{
    int x = 0;
    int k = fn_801A2034(self->m1EC, 3);
    int o = *(int*)((char*)self->m1EC + 0x724);
    if (fn_802D7DB4(k, 0xCC) != 0)
        x = (int)fn_802FDA84(o, 0);
    if (fn_802D7DB4(k, 0xCD) != 0)
        x = (int)fn_802FDA84(o, 1);
    if (fn_802D7DB4(k, 0xCE) != 0)
        x = (int)fn_802FDA84(o, 2);
    if (x != 0)
        self->m434 = (P*)x;
}

/* near-miss: 58 vs 61 insns: retail leaves a dead range compare (addi/cmplwi) after the second flag test. Tried empty else bodies, redundant-set else bodies */
extern void fn_8025DAC0(I* self);
extern void fn_8035E6B0(int* t, int i, int v);
void fn_8025DF8C(I* self)
{
    Q* q = self->m1EC;
    P** r = q->m65C;
    Unk8025DF8C_O* o = ((Unk8025DF8C_Ctx*)q->m700)->m3C0;
    int a = r[10] != 0;
    int b = r[11] != 0;
    if (Unk8025DF8C_Bit(o, 1) && a)
        fn_8035E6B0((int*)((char*)self + 0x1CC), 10, 1);
    if (Unk8025DF8C_Bit(o, 2)) {
        if (b)
            fn_8035E6B0((int*)((char*)self + 0x1CC), 11, 2);
    }
    fn_8025DAC0(self);
}

void fn_8025E4B4(I* self)
{
    for (int i = 9; i <= 12; i++) {
        P* p = Roster(self->m1EC, i);
        if (p != 0) {
            char* t = (char*)self + 0x204;
            if (*(int*)(fn_8035E8CC(t, i) + 4) != 6)
                fn_8035E704(t, i);
            else
                fn_80269F88((char*)self + 0x190, p, 6);
        }
    }
    fn_8035E604((char*)self + 0x1CC);
}

void fn_8025E55C(I* self, P* p)
{
    int found = 0;
    for (int i = 0; i < self->m448; i++) {
        if (found == 0) {
            if (self->m438[i] == p) {
                self->m438[i] = (P*)found;
                found = 1;
            }
        } else {
            self->m438[i - 1] = self->m438[i];
            self->m438[i] = 0;
        }
    }
    if (found != 0)
        self->m448 = self->m448 - 1;
}

void fn_8025E5E0(I* self)
{
    int lo = 8, hi = 0xC;
    for (int i = 0; i < self->m448; i++) {
        P* p = self->m438[i];
        int t = p->m458;
        if (t <= lo || t > hi)
            fn_8025E55C(self, p);
    }
}

void fn_8025E654(I* self)
{
    self->m448 = 0;
    for (int i = 0; i < 4; i++)
        self->m438[i] = 0;
}

void fn_8025E680(I* in)
{
    Unk8025E680_I* self = (Unk8025E680_I*)in;
    int start = 10;
    fn_8025E654(in);
    if ((self->m1F4 != 0 && fn_801BBEFC(self->m1F4->m3BC) != 0) || fn_801BBF04(self->m1F4->m3BC) != 0)
        start = 9;
    for (int i = start; i <= 12; i++) {
        P* p = Roster(self->m1EC, i);
        if (p != 0) {
            A* pa = &p->m58C;
            pa->b3 = 0;
            fn_80242E28(p, lbl_805DB1C8);
            self->m438[self->m448] = p;
            self->m448 = self->m448 + 1;
        }
    }
    if (self->m1FC == 1 && self->m200 == 8) {
        for (int j = 0; j < self->m448; j++) {
            P* q = self->m438[j];
            fn_80269F88((char*)self + 0x190, q, 3);
            char* e = fn_8035E8CC((char*)self + 0x204, q->m458);
            if (e != 0)
                fn_8026AA04(e, 3, lbl_805DB170, 0x51B);
        }
    }
}

extern "C" void fn_8025E7E4(F* self)
{
    fn_8025E804(self);
}

/* near-miss: 71 vs 72 instructions; retail copies the clamped fn_8014E310 result (r3) into the saved register after the clamp and keeps the byte test in r5. Tried inline clamp, byte local, i + 10 temp */
extern "C" void fn_8025E804(F* f)
{
    I* self = (I*)f;
    for (int i = 0; i <= 2; i++) {
        if (*fn_80081CF8(self->m1EC->m6F8->m14, i) != 0xFF) {
            int f = 0;
            if (*(int*)((char*)self->m1EC->m6F8->m14 + 0x1CD0) != 0)
                f = 1;
            P* p = fn_801A4910(self->m1EC, f);
            if (p != 0) {
                int fl = 1;
                if (p->m458 == i + 10)
                    fl = 0;
                fn_801A656C(self->m1EC, p);
                int k = fn_8014E310(p->m458);
                if (k <= 2) {
                    if (k < 0)
                        k = 0;
                } else {
                    k = 2;
                }
                A* a = &p->m58C;
                fn_802547C0(a, 0);
                fn_802553BC(a, 0);
                a->m30 = k;
                a->b3 = 0;
                fn_8025505C(a, k, 0);
                fn_8025E924(self, p, fl);
            }
        }
    }
}

void fn_8025ED44(I* self)
{
    P* top = (P*)fn_801A4B34(self->m1EC);
    fn_802491D8(top);
    if ((self->m448 == 0 || self->m438[0] != top) && fn_8018AD20(self->m1EC->m6CC) == 0) {
        char* t = (char*)self + 0x204;
        if (fn_8035E8CC(t, 9) != 0)
            fn_8035E704(t, top->m458);
        fn_80242E28(top, lbl_805DB200);
        int j = self->m448;
        if (j > 0) {
            do {
                int k = j - 1;
                P** arr = (P**)((char*)self + 0x438);
                P* x = arr[k];
                int o = j * 4;
                *(P**)((char*)arr + o) = x;
                if (x != 0)
                    fn_80242E28(x, lbl_805DB200);
                j = k;
            } while (j > 0);
        }
        self->m438[0] = top;
        self->m448 = self->m448 + 1;
    }
}

/* near-miss: 36 vs 31 instructions; retail passes the two float locals to fn_8024D050 straight from the registers they were loaded into (f1/f2) while the stores to the frame stay; ours reloads them from the slots. Tried const locals, inline pick(b, a, c), ternary */
float fn_8025EFAC(void* self, Unk80270BA0_X* b)
{
    float v = lbl_805DB20C;
    float w = lbl_805DB210;
    float r;
    if (b != 0)
        r = fn_8024D050(b, 0x25, 0x24, v, w);
    else
        r = Lerp3(v, w, lbl_805DB214);
    return r;
}
