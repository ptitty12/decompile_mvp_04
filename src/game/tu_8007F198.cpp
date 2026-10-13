/*
 * Game code, .text 0x8007F198-0x8007FF8C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/clampiter.h"
#include "game/tu_8007F198.h"

typedef Unk8007F198_A A;
typedef Unk8007F198_Rec Rec;
typedef Unk8007F198_Tbl Tbl;
typedef Unk8007F198_B B;
typedef Unk8007F198_Item Item;
typedef Unk8007F198_List List;
typedef Unk8007F198_C C;
typedef Unk8007F198_Obj Obj;
typedef Unk8007F198_S12 S12;
typedef Unk8007F198_D D;
typedef Unk8007F198_E E;

int fn_805A19C8(Tbl* t);
int fn_805A19C8(Tbl* t, int y);
int fn_805A196C(Tbl* t, int i, int x);
int fn_8053B210(Rec* r, int a);
int fn_8053B450(Rec* r, int a);
int fn_8053B064(Rec* r);
int fn_8053B824(Rec* r, int a);
int fn_8053B85C(Rec* r, int a);
int fn_8053B8C0(Rec* r);
int fn_8053B6A4(Rec* r);
int fn_8053B900(Rec* r, int a);
int fn_8053B934(Rec* r, int a, int b, int c);
int fn_8053B980(Rec* r, int a, int b);
int fn_8053BA1C(Rec* r, int a);
int fn_8053BAD0(Rec* r, int a, int b, int c);

static inline Rec* Cur(Tbl* t)
{
    return &t->m10[fn_805A19C8(t)];
}

unsigned char fn_8007F198(A* self)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m4;
}

int fn_8007F1E0(A* self, int x, int y)
{
    Tbl* t = self->m58;
    return (unsigned char)fn_8053B210(&t->m10[fn_805A19C8(t, y)], x) != 0xFF;
}

int fn_8007F24C(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    int* p = t->m10[i].m0 + x;
    return *p;
}

int fn_8007F29C(A* self, int a, int x)
{
    return fn_8053B450(Cur(self->m58), x);
}

int fn_8007F2EC(A* self, int a, int x)
{
    Tbl* t = self->m58;
    return fn_805A196C(t, fn_805A19C8(t), x);
}

void fn_8007F330(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    if (r->m4 < r->m8) {
        t->m10[i].m0[r->m4] = x;
        r->m4++;
    }
}

int fn_8007F3A0(A* self)
{
    return fn_8053B064(Cur(self->m58));
}

int fn_8007F3E8(A* self, int a, int x)
{
    return fn_8053B824(Cur(self->m58), x);
}

int fn_8007F438(A* self, int a, int x)
{
    return fn_8053B85C(Cur(self->m58), x);
}

int fn_8007F488(A* self)
{
    return fn_8053B8C0(Cur(self->m58));
}

int fn_8007F4D0(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m1D0[x];
}

int fn_8007F524(A* self)
{
    return fn_8053B6A4(Cur(self->m58));
}

int fn_8007F56C(A* self, int a, int x)
{
    return fn_8053B900(Cur(self->m58), x);
}

int fn_8007F5BC(A* self, int a, int x, int y, int z)
{
    return fn_8053B934(Cur(self->m58), x, y, z);
}

int fn_8007F61C(A* self, int a, int x, int y)
{
    return fn_8053B980(Cur(self->m58), x, y);
}

int fn_8007F674(A* self, int a, int x)
{
    return fn_8053BA1C(Cur(self->m58), x);
}

int fn_8007F6C4(A* self, int a, int x, int y)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m1B0[x][y].w0;
}

int fn_8007F724(A* self, int a, int x, int y, int z)
{
    return fn_8053BAD0(Cur(self->m58), x, y, z);
}

int fn_805A0530(Item* it, int x, int y);
void fn_805A06F0(List* l);
void fn_805A06A4(List* l);

int fn_8007F784(B* self, unsigned i, int x, int y)
{
    List* l = self->m4;
    return fn_805A0530(i < l->m0 ? &l->m4[i] : 0, x, y);
}

int fn_8007F7D0(B* self, unsigned i)
{
    List* l = self->m4;
    Item* it = i < l->m0 ? &l->m4[i] : 0;
    return it->m18;
}

void fn_8007F7FC(B* self, unsigned i, int v)
{
    List* l = self->m4;
    Item* it = i < l->m0 ? &l->m4[i] : 0;
    it->m18 = v;
}

void fn_8007F828(B* self)
{
    fn_805A06F0(self->m4);
}

unsigned fn_8007F84C(B* self)
{
    return self->m4->m0;
}

void fn_8007F858(B* self)
{
    fn_805A06A4(self->m4);
}

int fn_8007F87C(B* self, int val)
{
    for (unsigned i = 0; i < fn_8007F84C(self); i++) {
        if (fn_8007F7D0(self, i) == val)
            return 1;
    }
    return 0;
}

void fn_8052BA70(Obj* o);
void fn_8052BE28(Obj* o, int a, int b, int c, int d, int e);
void fn_8052BED8(Obj* o, int a);
S12 fn_8052BD58(Obj* o);
void fn_8052BCC8(Obj* o);
void fn_8052BD40(Obj* o);
int fn_8007FA1C(C* self, int* a, int* b);

void fn_8007F8E4(C* self, int idx)
{
    fn_8052BA70(self->mC[idx]);
}

void fn_8007F910(C* self, int idx, int a, int b, int c, int d, int e)
{
    fn_8052BE28(self->mC[idx], a, b, c, d, e);
}

void fn_8007F950(C* self, int idx, int a)
{
    fn_8052BED8(self->mC[idx], a);
}

int fn_8007F980(C* self, int idx)
{
    return fn_8052BD58(self->mC[idx]).w2;
}

/* fn_8007FA1C (0x8007FA1C): a loop over the four fn_8052BD58 results that keeps
 * the greatest 12-byte value by a three-word compare; defined below. */
int fn_8007F9B4(C* self)
{
    int a = 0;
    fn_8007FA1C(self, &a, 0);
    return a;
}

int fn_8007F9E8(C* self)
{
    int a = 0;
    fn_8007FA1C(self, 0, &a);
    return a;
}

/* The saturating iterator (Unk8006A138_It<3> semantics) is an int stepped through a pointer
 * parameter: an address-taken scalar gets its frame slot late, after the 12-byte result temp.
 * The class form put it at the declaration, before the temp. */
inline void InitS12(S12* p, int a, int b, int c) { p->w0 = a; p->w1 = b; p->w2 = c; }
inline int StepP(int* p)
{
    int t;
    if (*p > 3)
        t = *p;
    else
        t = *p + 1;
    *p = t;
    return t;
}
int fn_8007FA1C(C* self, int* o1, int* o2)
{
    S12 best;
    InitS12(&best, -1, -1, 1);
    int v = 0;
    int k = 0;
    do {
        S12 cur = fn_8052BD58(self->mC[k]);
        int g = cur.w0 > best.w0;
        if (cur.w0 == best.w0)
            g = cur.w1 > best.w1;
        if (g == 1) {
            if (best.w2 == 1)
                best = cur;
        } else if (cur.w2 == 0)
            best = cur;
        k = StepP(&v);
    } while (k <= 3);
    if (o1)
        *o1 = best.w0;
    if (o2)
        *o2 = best.w1;
}

int fn_8007FB2C(C* self, int idx)
{
    return self->mC[idx]->m4;
}

void fn_8007FB40(C* self, int idx)
{
    fn_8052BCC8(self->mC[idx]);
}

void fn_8007FB6C(C* self, int idx)
{
    fn_8052BD40(self->mC[idx]);
}

int fn_8007FB98(C* self, int a, int b, int c)
{
    char* base = (char*)(a * 0x1C + (int)self->mC[c]->m8);
    int o = b * 12 + 4;
    return *(int*)(base + o);
}

unsigned fn_8007FBC0(C* self, int a, int c)
{
    return self->mC[c]->m8[a].w0.h0;
}

int fn_8007FBDC(C* self, int a, int c)
{
    return self->mC[c]->m8[a].w0.a + 0x21C;
}

int fn_8007FC00(C* self, int a, int c)
{
    return self->mC[c]->m8[a].w0.b;
}

int fn_8007FC20(C* self, int a, int c)
{
    return self->mC[c]->m8[a].w0.c;
}

int fn_8007FC40(C* self, int a, int b, int n, int c)
{
    char* base = (char*)(a * 0x1C + (int)self->mC[c]->m8);
    Unk8007F198_Sub* s = (Unk8007F198_Sub*)(base + 4) + b;
    int r = 0;
    switch (n) {
    case 0: r = s->w1.n20; break;
    case 1: r = s->w1.n24; break;
    case 2: r = s->w1.n28; break;
    case 3: r = s->w2.n0; break;
    case 4: r = s->w2.n4; break;
    case 5: r = s->w2.n8; break;
    case 6: r = s->w2.n12; break;
    case 7: r = s->w2.n16; break;
    case 8: r = s->w2.n20; break;
    }
    return r;
}

int fn_8007FD2C(C* self, int a, int b, int c)
{
    return ((Unk8007F198_Sub*)((char*)self->mC[c]->m8 + a * 0x1C + 4) + b)->w1.b0;
}

int fn_8007FD54(C* self, int a, int b, int c)
{
    return ((Unk8007F198_Sub*)((char*)self->mC[c]->m8 + a * 0x1C + 4) + b)->w1.b1;
}

int fn_8007FD7C(C* self, int a, int b, int c)
{
    return ((Unk8007F198_Sub*)((char*)self->mC[c]->m8 + a * 0x1C + 4) + b)->w1.n16;
}

int fn_8007FDA8(C* self, int a, int c)
{
    return self->mC[c]->m8[a].w0.c != 0;
}

void fn_80086DFC(Unk8007F198_DI* p);
void fn_8059A580(Unk8007F198_EI* p);
void fn_8059A16C(Unk8007F198_EI* p);
void fn_8059A0C8(Unk8007F198_EI* p);
void fn_8059A108(Unk8007F198_EI* p);
void fn_8059A14C(Unk8007F198_EI* p);
void fn_8059A1DC(Unk8007F198_EI* p);
void fn_8059A360(Unk8007F198_EI* p);
void fn_8059A384(Unk8007F198_EI* p);
void fn_8059A3A8(Unk8007F198_EI* p);
void fn_8059A40C(Unk8007F198_EI* p);

void fn_8007FDD4(D* self)
{
    fn_80086DFC(self->m0);
}

int fn_8007FDF8(D* self)
{
    return self->m0->m22C;
}

Unk8007F198_DI* fn_8007FE04(D* self)
{
    return self->m0;
}

int fn_8007FE0C(E* self)
{
    return self->m1C->m528;
}

void fn_8007FE18(E* self)
{
    fn_8059A580(self->m1C);
}

void fn_8007FE3C(E* self)
{
    fn_8059A16C(self->m1C);
}

void fn_8007FE60(E* self)
{
    fn_8059A0C8(self->m1C);
}

void fn_8007FE84(E* self)
{
    fn_8059A108(self->m1C);
}

void fn_8007FEA8(E* self)
{
    fn_8059A14C(self->m1C);
}

void fn_8007FECC(E* self)
{
    fn_8059A1DC(self->m1C);
}

int fn_8007FEF0(E* self)
{
    return self->m1C->m694;
}

void fn_8007FEFC(E* self)
{
    fn_8059A360(self->m1C);
}

void fn_8007FF20(E* self)
{
    fn_8059A384(self->m1C);
}

void fn_8007FF44(E* self)
{
    fn_8059A3A8(self->m1C);
}

void fn_8007FF68(E* self)
{
    fn_8059A40C(self->m1C);
}
