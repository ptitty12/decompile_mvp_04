/*
 * Game code, .text 0x8025B59C-0x8025F708 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"
#include "game/goals/tu_8027C728.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

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

void fn_8025CAF0(F* self)
{
    self->m1C = 0;
    self->m0 = -1.0f;
    for (int i = 0; i < 4; i++)
        self->m4[i] = -1;
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

struct Unk8025D054_I {
    char pad0[0x1FC];
    int m1FC;
    int m200;
};
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

extern "C" void fn_8025E804(F* self);

extern "C" void fn_8025E7E4(F* self)
{
    fn_8025E804(self);
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
