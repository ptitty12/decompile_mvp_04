/*
 * Game code, .text 0x8025F708-0x80264378 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"
#include "game/chooser.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

/* Command record of fn_80261B74: +4 kind, +0xC id. */
struct Unk80261B74_R {
    char pad0[4];
    int m4;
    char pad8[4];
    int mC;
};

/* Per-player entry of the table at inner+0x204 (m8 state, mC id; fn_8025F708) and the context at inner+0x1F4. */
struct Unk8025F708_E {
    char pad0[8];
    int m8;
    int mC;
};
struct Unk8025F708_C {
    char pad0[0x3A4];
    char* m3A4;
};

extern "C++" {
int fn_8026BE3C(I* self, P* p);
void fn_8025F89C(I* self, P* p);
}

inline int EntLevel(Unk8024EF40_Ent* e)
{
    return *((unsigned char*)e + 0x1CC9);
}

extern const char lbl_805DB170[];
extern void fn_8035E6B0(int* a, int i, int v);
extern void fn_8035E688(char* p, int i, int v);
extern void fn_8026AA04(char* r, int v, const char* file, int line);
extern int fn_801D0368(char* y);
int fn_8025F708(I* self, P* p, Unk8025F708_E* e)
{
    A* a = &p->m58C;
    if (a->m44 == 2 ? 1 : a->m44 == 1)
        a->m40 = -1;
    int k = a->m40;
    if (k != -1 && p != 0) {
        char* t = (char*)self + 0x1CC;
        fn_8035E6B0((int*)t, p->m458, k);
        fn_8035E688(t, p->m458, 0);
        a->m30 = k;
        e->mC = k;
        fn_8026AA04((char*)e, 10, lbl_805DB170, 0x812);
        e->m8 = 1;
        if (p->m458 == 9 && fn_801D0368(((Unk8025F708_C*)*(void**)((char*)self + 0x1F4))->m3A4 + 0x28C) != 0)
            e->m8 = 2;
        return 1;
    }
    return 0;
}

int fn_8025F7F0(I* self, P* p)
{
    if (p == 0)
        return 0;
    if (fn_8026BE3C(self, p) == 0)
        fn_8025F89C(self, p);
    return fn_8026BE3C(self, p) != 0;
}

void fn_8025F860(I* self, P* p, int a)
{
    self->m4C4[p->m458 - 9] = a;
}

void fn_8025F878(I* self)
{
    for (int i = 0; i < 4; i++)
        self->m4C4[i] = 0;
}

extern P* fn_801A497C(Q* q, int a, int b);
extern int fn_8024D41C(Unk80270BA0_X* x);
int fn_80261050(I* self, P** out)
{
    Q* q = self->m1EC;
    P* c = q->m6CC;
    int v = *(int*)((char*)self->m1F0 + 0x18);
    void* x = ((Unk80273498_Pos*)c)->m374;
    int y = c->m378;
    *out = (P*)v;
    if (v == 0 && x != 0 && fn_8024D41C((Unk80270BA0_X*)y) != 0 && c->m36C == 0 && c->m38C == 3) {
        for (int i = 2; i <= 5; i++) {
            P* o = fn_801A497C(self->m1EC, 4, i);
            if (o != 0) {
                char* e = (char*)o + 0x4D8;
                if (*(int*)(e + 0x78) != 0 || *(int*)(e + 0x7C) != 0) {
                    *out = o;
                    break;
                }
            }
        }
    }
    int r = 1;
    if (*out == 0)
        r = 0;
    return r;
}

int fn_80261AFC(I* self, P* p)
{
    A* a = &p->m58C;
    if (a->b2 != 0 || a->m44 == 2)
        return 1;
    Q* q = self->m1EC;
    int lvl = EntLevel(q->m6F8->m14);
    if (lvl > 2)
        return 1;
    if (a->m44 == 1) {
        P* c = q->m6CC;
        if (c->m388 == 3 && c->m38C == 1 && lvl <= 1)
            return 0;
        return 1;
    }
    return 0;
}

extern int fn_8026A630(I* self, Unk80261B74_R* r);
extern void fn_8025DED4(I* self);
extern void fn_8025D738(I* self, int a);
extern void fn_8025DD20(I* self, P* p);
extern void fn_8025D4A4(I* self, int a);
extern int fn_8035E630(int* t, P* p);
extern int fn_8035E69C(char* t, int i);
extern void fn_802687FC(void* h, unsigned t, int a, int b, float f);
extern int fn_8025F474(I* self, P* p, Unk80261B74_R* r, int d);
extern void fn_8025D054(I* self, int a);
void fn_80261B74(I* self, P* p, Unk80261B74_R* r, int d)
{
    if (fn_8026A630(self, r) == 0) {
        int* t = (int*)((char*)self + 0x1CC);
        fn_8025DED4(self);
        fn_8025D738(self, 3);
        fn_8025DD20(self, p);
        fn_8025D4A4(self, 3);
        int v = fn_8035E630(t, p);
        if (fn_8035E69C((char*)t, p->m458) == 1) {
            fn_8026AA04((char*)r, 1, lbl_805DB170, 0xF3A);
            fn_802687FC((char*)self + 0x2E8, p->m458, 3, r->mC, Secs(self->m1EC));
        } else {
            r->mC = v;
        }
        fn_8025F474(self, p, r, d);
        int ty = r->m4;
        if (ty == 10 ? 1 : ty == 11)
            fn_8025D054(self, 6);
    }
}

extern void fn_80260D80(I* i, P* p, int k, float* a, float* b, float* c, int z);
extern void* fn_801A4B34(void* w);
extern float lbl_805DB38C;
void fn_80261CA8(I* self)
{
    int a = -1;
    int b = -1;
    int i = 0;
    P* p = (P*)fn_801A4B34(self->m1EC);
    do {
        float tbl[4] = { 0.0f, 1.0f, 2.5f, 3.0f };
        float s18 = 0.0f;
        float s1c = 0.0f;
        float s20 = 0.0f;
        fn_80260D80(self, p, i, &s1c, &s18, &s20, 0);
        if (!(s20 <= 0.5f))
            b = i;
        if (s20 <= -lbl_805DB38C - tbl[i])
            break;
        a = i;
        i = a + 1;
    } while (i <= 2);
    Unk8025F708_C* c = (Unk8025F708_C*)*(void**)((char*)self + 0x1F4);
    *(int*)(c->m3A4 + 0x104) = a;
    c = (Unk8025F708_C*)*(void**)((char*)self + 0x1F4);
    *(int*)(c->m3A4 + 0x108) = b;
}
