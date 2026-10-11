/*
 * Game code, .text 0x80268190-0x8026C414 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80268190.h"

typedef Unk80268190_M M;
typedef Unk80268190_Pl Pl;
typedef Unk80268190_Q Q;
typedef Unk80268190_A A;
typedef Unk80268190_MsgB MsgB;
typedef Unk80268190_S S;
typedef Unk80268190_T T;
typedef Unk80268190_H H;
typedef Unk80268190_HE HE;
typedef Unk80268190_R R;
typedef Unk80268190_G G;
typedef Unk80268190_C C;

extern char lbl_806617D0[];
extern char lbl_80660608[];
extern int lbl_8061CB7C;

extern "C++" {
void fn_8037893C(void* q, int id, MsgB* o, int a, int b);
Pl* fn_801A497C(Q* q, int a, int b);
void fn_8008801C(void* x, Pl* p, Pl* o, int a, int b);
int fn_8035E318(A* a);
int fn_8026D8E8(Pl* p, int a);
int fn_8026D914(Pl* p, int a);
int fn_802548BC(A* a, int b);
void fn_80268144(M* m);
int fn_80254EA4(A* a, int b);
void fn_802680B0(M* m, int a);
void fn_80242E28(Pl* p, float f);
int fn_8014E2B4(int a);
void fn_8025713C(void* list, int a);
void fn_80268A4C(S* s, int t, Pl* p);
int fn_80268684(M* m, Pl* p);
void* fn_8040B320(void* p, int v, int n);
void fn_80269E80(G* g, int idx, const char* s);
int fn_80269F88(G* g, Pl* p, int ev);
int fn_8026A0DC(G* g, Pl* p);
int fn_8025CBFC(void* x, Pl* p);
void fn_8025D054(C* c, int a);
void fn_80266418(void* x, int a);
void fn_8025E4B4(C* c);
void fn_8025E654(C* c);
int fn_801BBEFC(int a);
void fn_802665B4(void* x);
void fn_8025E55C(C* c);
}

struct Unk80268190_Msg5E : MsgB {
    int m8;
    int mC;
    Unk80268190_Msg5E(Pl* p) : MsgB(0x5E)
    {
        int t = p->m58C.m30;
        m8 = (int)p;
        mC = t;
    }
    virtual ~Unk80268190_Msg5E() {}
};

struct Unk80268190_Msg5F : MsgB {
    int m8;
    int mC;
    int m10;
    Unk80268190_Msg5F(int a, Pl* o, Pl* p) : MsgB(0x5F), m8(a), mC(o->m70C), m10(p->m70C) {}
    ~Unk80268190_Msg5F();
};

extern Unk80268190_Msg5F lbl_8068BEF0;

void fn_80268190(M* self, Pl* p)
{
    int idx = p->m458 - 9;
    if (self->e[idx].fC == 0) {
        Unk80268190_Msg5E m(p);
        fn_8037893C(self->m0->m704, m.m0, &m, 0, 0);
        self->e[idx].fC = 1;
    }
}

/* near-miss: store/load schedule inside the 0x5F message ctor differs from retail */
void fn_80268228(M* self, Pl* p, int a, int b)
{
    if (p->m458 != 9) {
        Pl* o = fn_801A497C(self->m0, 4, 1);
        fn_8008801C(self->m0->m6F8->mC->mC, p, o, a, b);
        int idx = p->m458 - 9;
        if (self->e[idx].f8 == 0 && b != 0) {
            A* c = &p->m58C;
            int v = c->m38;
            if (v > fn_8035E318(c)) {
                Unk80268190_Msg5F m(a, o, p);
                self->e[p->m458 - 9].f8 = 1;
                Pl* r = self->m0->m65C[1];
                if ((r != 0 && fn_8026D8E8(r, 0) == 1) || fn_8026D914(r, 0) == 1) {
                    lbl_8068BEF0 = m;
                    lbl_8061CB7C = 1;
                } else {
                    fn_8037893C(self->m0->m704, m.m0, &m, 0, 0);
                }
            }
        }
    }
}

void fn_802683CC(M* self, Pl* p)
{
    if (p != 0 && fn_80268684(self, p) != 0) {
        int found = 0;
        int i = 1;
        do {
            Pl* o = self->e[i].p10;
            if (o != 0 && o != p) {
                A* a = &o->m58C;
                int idx = o->m458 - 9;
                if (a->b2) {
                    if (self->e[idx].f14 <= fn_8035E318(a)) {
                        found = 1;
                        break;
                    }
                }
            }
            i++;
        } while (i <= 3);
        if (found == 0) {
            A* a = &p->m58C;
            int r = fn_802548BC(a, 1);
            int f = a->b2;
            fn_80268228(self, p, r, f == 0);
        }
    }
}

/* near-miss: compare operand order (retail cmpw r0,r31 = entry, player) */
void fn_802684B0(M* self)
{
    if (self->m4 != 0) {
        for (int i = 1; i <= 3; i++) {
            Pl* p = PlayerAt(self->m0, i + 9);
            if (p != 0 && p == self->e[i].p10) {
                int r = fn_802548BC(&p->m58C, 1);
                fn_80268228(self, p, r, 0);
            }
        }
    }
    fn_80268144(self);
}

void fn_80268564(M* self)
{
    int any = 0;
    for (int i = 1; i <= 3; i++) {
        Pl* p = self->e[i].p10;
        if (p != 0) {
            if (fn_80254EA4(&p->m58C, 1) != -1)
                fn_802680B0(self, i);
            else
                any = 1;
        }
    }
    self->m4 = any;
}

void fn_802685E4(M* self, Pl* p, int a)
{
    if (self->m4 != 0 && p->m458 != 9) {
        const float t = 1.0f;
        fn_80242E28(p, t);
        self->e[p->m458 - 9].f14 = a;
    }
}

int fn_80268658(M* self, Pl* p)
{
    return self->e[p->m458 - 9].p10 != 0;
}

int fn_80268684(M* self, Pl* p)
{
    if (p == 0 || p->m264 != 0 || p->m458 == 9)
        return 0;
    int r = 0;
    if (self->m4 != 0)
        r = fn_80268658(self, p);
    return r;
}

Pl* fn_802686E4(M* self, int t)
{
    return self->e[fn_8014E2B4(t - 1) - 9].p10;
}

void fn_80268724(M* self, Pl* p)
{
    self->m4 = 1;
    fn_8025713C(self->m0->m700->m3B4, 0);
    fn_80268190(self, p);
    self->e[p->m458 - 9].p10 = p;
}

void fn_8026878C(H* self, float f)
{
    for (int i = 0; i < 4; i++) {
        self->cnt[i] = 0;
        for (int j = 0; j < 6; j++) {
            self->e[i][j].a0 = -1;
            self->e[i][j].c8 = 0;
            self->e[i][j].f4 = -1.0f;
        }
    }
}

/* near-miss: retail spills f1 before `mr r5,r6` (two instructions swapped) */
void fn_802687FC(H* self, unsigned t, int a, int b, float f)
{
    Pl* pl = PlayerAt(self->m130, t);
    if (pl == 0) {
        int idx = pl->m458 - 9;
        int n = self->cnt[idx];
        if (idx >= 0) {
            if (n != 0 && b == self->e[idx][n - 1].a0 && a == self->e[idx][n - 1].c8)
                return;
            if (n > 5) {
                for (int k = 1; k <= 5; k++)
                    self->e[idx][k - 1] = self->e[idx][k];
                n = 5;
                self->cnt[idx] = n;
            }
            self->e[idx][n].a0 = b;
            self->e[idx][n].c8 = a;
            self->e[idx][n].f4 = f;
            self->cnt[idx]++;
        }
    }
}

float fn_80268918(S* self, int idx)
{
    return self->m4C[idx];
}

void fn_80268928(S* self)
{
    self->m4C[0] = 0.0f;
    self->m4C[1] = 0.94f;
    self->m4C[2] = 1.11f;
    self->m4C[3] = 1.21f;
    self->m4C[4] = 0.71f;
    self->m4C[5] = 0.81f;
    self->m4C[6] = 1.08f;
}

float fn_80268980(S* self, int k, int t)
{
    return self->f0[t - 9][k];
}

void fn_80268998(S* self, int t)
{
    if (t == -1) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                self->f0[i][j] = 0.0f;
    } else {
        int row = t - 9;
        for (int j = 0; j < 4; j++)
            self->f0[row][j] = 0.0f;
        fn_80268A4C(self, t, PlayerAt(self->m44->m1EC, t));
    }
}

void fn_80268DB0(S* self)
{
    fn_80268998(self, -1);
    for (int i = 0; i < self->m44->m448; i++) {
        Pl* p = self->m44->m438[i];
        if (p != 0 && (unsigned)(p->m458 - 9) <= 3)
            fn_80268A4C(self, p->m458, p);
    }
}

S* fn_80268E38(S* self, T* t)
{
    self->m44 = t;
    self->m40 = 0;
    self->m48 = -1;
    fn_80268998(self, -1);
    fn_8040B320(self->m4C, 0, 0x1C);
    return self;
}

/* near-miss: retail forms `li r7,0` before `addi r8,r31,4` (two instructions swapped) */
R* fn_80268E90(R* self, Q* q, Pl* p, int x)
{
    self->m0 = q;
    Unk80268190_Rec* r = self->rec;
    for (int i = 0; i < 3; i++) {
        r->a0 = 1;
        r->a4 = 0;
        self->rec[i].a8 = 0;
        self->rec[i].a10 = -1.0f;
        self->rec[i].a14 = -1.0f;
        r++;
    }
    A* a = &p->m58C;
    int k = a->m38;
    int cap = 3;
    if (k < 0)
        k = 0;
    self->rec[0].aC = k;
    self->rec[1].aC = k + 1;
    self->rec[2].aC = k + 2;
    if (self->rec[1].aC > cap)
        self->rec[1].aC = cap;
    if (self->rec[2].aC > cap)
        self->rec[2].aC = cap;
    if (fn_80254EA4(a, 0) != -1) {
        if (self->rec[0].aC != 0 || p == 0 || p->m458 != 9) {
            self->rec[0].a0 = 0;
            self->rec[0].a4 = 7;
        }
    }
    self->m58 = p;
    self->m5C = x;
    return self;
}

void fn_80269128(R* self)
{
    Unk80268190_Rec* r = &self->rec[1];
    if (r->a0 != 0) {
        Pl* p = self->m58;
        if (p != 0 && p->m458 != 9) {
            if (fn_8025CBFC((char*)self->m0 + 0x9C, p) == self->rec[1].aC) {
                self->rec[0].a0 = 0;
                self->rec[1].a0 = 1;
                self->rec[0].a4 = 2;
                r->a4 = 2;
            }
        }
    }
}

int fn_8026986C(R* self, int v)
{
    int r = -1;
    int i;
    for (i = 0; i < 3; ++i) {
        if (self->rec[i].aC == v) {
            r = i;
            break;
        }
    }
    return r;
}

void fn_80269DCC() {}

void fn_80269DD0(G* self, int t, int v)
{
    self->rec[t - 9].c = v;
}

void fn_80269DE4(G* self)
{
    for (int i = 0; i < 4; i++) {
        self->rec[i].a = 0;
        self->rec[i].b = 0;
        self->rec[i].c = 0;
    }
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
}

void fn_80269E24(G* self, int i)
{
    self->rec[i].a = 0;
    self->rec[i].b = 0;
    self->rec[i].c = 0;
}

void fn_80269E48(G* self)
{
    for (int i = 0; i < 4; i++) {
        self->rec[i].a = 0;
        self->rec[i].c = self->rec[i].b;
    }
    self->m0 = 0;
}

void fn_80269E80(G* self, int idx, const char* s) {}

struct Unk80268190_Msg8A : MsgB {
    int m8;
    int mC;
    Unk80268190_Msg8A() : MsgB(0x8A), m8(-1), mC(0) {}
    virtual ~Unk80268190_Msg8A() {}
};

void fn_80269E84(G* self, Pl* p, int ev)
{
    int idx = p->m458 - 9;
    if (ev == 3) {
        self->rec[idx].b++;
        fn_80269E80(self, idx, "Completing LEADSTYLE_ADVANCE");
    } else if (ev == 5) {
        self->rec[idx].b--;
        fn_80269E80(self, idx, "Completing LEADSTYLE_RETREAT");
    }
    if (ev == 2 || ev == 6) {
        fn_80269F88(self, p, 9);
        fn_80269E80(self, idx, "Completing LEADSTYLE_RETREAT");
    } else if (ev == 4) {
        fn_80269F88(self, p, 4);
        fn_80269E80(self, idx, "Completing LEADSTYLE_RETREAT");
    } else {
        fn_80269F88(self, p, 2);
        fn_80269E80(self, idx, "Completing LEADSTYLE_RETREAT");
    }
}

/* near-miss: retail reaches the stack message through its pointer register everywhere (r31); here later stores fold to r1-relative */
int fn_80269F88(G* self, Pl* p, int ev)
{
    int sent = 0;
    Unk80268190_Msg8A m;
    int idx = p->m458 - 9;
    int r = fn_8026A0DC(self, p);
    if ((unsigned)(r - 2) <= 1 || r == 0) {
        if (ev == 7 && self->rec[idx].b <= 1) {
            fn_80269E80(self, idx, "SetState RUNASSIGNMENT_LEADOFFADV");
            m.m8 = 0;
            m.mC = (int)p;
            sent = 1;
        } else if (ev == 8 && self->rec[idx].b > 0) {
            fn_80269E80(self, idx, "SetState RUNASSIGNMENT_LEADOFFRET");
            sent = 1;
            m.mC = (int)p;
            m.m8 = 1;
        }
    } else {
        self->rec[idx].a = ev;
    }
    if (sent) {
        self->rec[idx].a = ev;
        fn_8037893C(p->m44C->m704, m.m0, &m, 0, 0);
    }
    return sent;
}

int fn_8026A0DC(G* self, Pl* p)
{
    return self->rec[p->m458 - 9].a;
}

int fn_8026A0F4(G* self, Pl* p)
{
    return self->rec[p->m458 - 9].b;
}

void fn_8026A10C() {}

void fn_8026A1D4() {}

void fn_8026AA04(R* self, int v)
{
    self->rec[0].a0 = v;
}

Pl* fn_8026B8C0(C* self, unsigned t)
{
    return PlayerAt(self->m1EC, t);
}

/* near-miss: retail returns through one `mr r3,r4` join (result in r4) */
Pl* fn_8026B8E4(C* self, int t)
{
    int u = t + 1;
    if ((unsigned)(t - 8) <= 3)
        return PlayerAt(self->m1EC, u);
    return 0;
}

/* near-miss: same as fn_8026B8E4 */
Pl* fn_8026B918(C* self, int t)
{
    int u = t - 1;
    if ((unsigned)(t - 10) <= 3)
        return PlayerAt(self->m1EC, u);
    return 0;
}

/* near-miss: retail stores m42C before loading the 60.0f constant (lfs f12 / stw swapped) */
void fn_8026B94C(C* self, int ev)
{
    if (ev == 5) {
        self->m42C = 1;
        float t = 1.0f;
        self->m430 = (int)(t * 60.0f);
        fn_8025D054(self, 7);
    } else {
        fn_8025D054(self, 9);
    }
    fn_80266418(self->m4, ev);
}

void fn_8026B9D8(C* self)
{
    fn_8025E4B4(self);
    fn_8025E654(self);
    if (fn_801BBEFC(self->m1EC->m700->m3BC) != 0)
        self->m44C |= 0x80000000;
}

void fn_8026BA30(C* self)
{
    fn_8025E4B4(self);
    fn_8025E654(self);
    if (fn_801BBEFC(self->m1EC->m700->m3BC) != 0)
        self->m44C |= 0x80000000;
    self->m1FC = 1;
    self->m434 = 0;
    self->m44C &= ~0x60000000;
    self->m1F8 = self->m1F4->m3B8;
    fn_802665B4(self->m48);
}

void fn_8026BAB8(C* self)
{
    fn_8025E55C(self);
}

int fn_8026BE3C(C* self, Pl* p)
{
    return self->m4C4[p->m458 - 9];
}
