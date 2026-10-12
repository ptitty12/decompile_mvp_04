/*
 * Game code, .text 0x80268190-0x8026C414 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80268190.h"
#include "game/tu_8024EF40.h"

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
typedef Unk80268190_Cmd Cmd;

extern char lbl_806617D0[];
extern Unk80268190_V3 lbl_806055AC;
extern const char lbl_805DB170[];
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
void fn_8014E388(char* buf);
float fn_80189D88(Pl* pl, Pl* o, void* v, char* buf, float f);
float fn_80259A74(void* list, int type, int idx);
int fn_80261050(Q* q, Pl** out);
Pl* fn_80257B40(void* p);
float fn_80266EF4(void* p, Pl* x);
void fn_8025713C(void* list, int a);
void fn_80268A4C(S* s, int t, Pl* p);
int fn_80268684(M* m, Pl* p);
void* fn_8040B320(void* p, int v, int n);
void fn_80269E80(G* g, int idx, const char* s);
int fn_80269F88(G* g, Pl* p, int ev);
int fn_8026A0F4(G* g, Pl* p);
int fn_8026A0DC(G* g, Pl* p);
int fn_8025CBFC(void* x, Pl* p);
void fn_8025D054(C* c, int a);
void fn_80266418(void* x, int a);
void fn_8025E4B4(C* c);
void fn_8025E654(C* c);
int fn_801BBEFC(int a);
void fn_802665B4(void* x);
void fn_8025E55C(C* c);
void fn_8026AA04(R* self, int v, const char* file, int line);
void fn_8025E26C(C* c, Cmd* cmd, int a, int type);
int fn_8025DC40(C* c, int* a, int* b, int* cc, int* d);
int fn_802665DC(void* x, int a, int b, int c);
void fn_8035E664(void* x, Pl* p, int a);
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
    Unk80268190_Msg5F() : MsgB(0x5F) {}
    void Set(int a, Pl* o, Pl* p)
    {
        int t = o->m70C;
        int u = p->m70C;
        m8 = a;
        mC = t;
        m10 = u;
    }
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
                Unk80268190_Msg5F m;
                m.Set(a, o, p);
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

/* near-miss: retail loads rec->aC into r4 for the first compare (we use r0); everything else equal */
int fn_802691AC(R* self, Unk80268190_Rec* rec, int unused, Pl* o)
{
    float f;
    char buf[16];
    if (rec->aC == -1)
        return 0;
    Pl* pl = self->m58->m44C->m6CC;
    char* bp = buf;
    void* pos = (char*)o + 0x60;
    fn_8014E388(bp);
    f = fn_80189D88(pl, o, pos, bp, 1320.0f);
    rec->a14 = rec->a14 + f;
    rec->a10 = fn_80259A74(self->m58->m44C->m700->m3B4, self->m58->m458, rec->aC);
    const float k = 0.25f;
    rec->a18 = rec->a10 - rec->a14;
    return rec->a18 > k;
}

/* near-miss (parked, 75 vs 76 insns): retail walks three induction values (tmp pointer with a precomputed end, record pointer, byte offset) and re-forms self+off each pass;
   the zero-fill of tmp is a libcall memset (crclr cr1eq) in retail */
void fn_80269288(R* self)
{
    Pl* x = 0;
    if (fn_80261050(self->m0, &x) != 0) {
        if (fn_80254EA4(&self->m58->m58C, 0) == -1) {
            if (self->m58 != fn_80257B40(self->m0->m1F0)) {
                if (self->m58->m58C.m30 <= 2) {
                    if (x != 0) {
                        int tmp[3] = { 0, 0, 0 };
                        float f = fn_80266EF4(self->m0->m48, x);
                        for (int i = 0; i < 3; i++) {
                            self->rec[i].a14 = f;
                            if (self->rec[i].a0 == 1 && fn_802691AC(self, &self->rec[i], 0, x) != 0) {
                                tmp[i] = 1;
                                self->rec[i].a0 = 0;
                                self->rec[i].a4 = 4;
                            }
                        }
                    }
                }
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
    void Set(int a, Pl* p)
    {
        m8 = a;
        mC = (int)p;
    }
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

int fn_80269F88(G* self, Pl* p, int ev)
{
    int sent = 0;
    Unk80268190_Msg8A m;
    int idx = p->m458 - 9;
    int r = fn_8026A0DC(self, p);
    if ((unsigned)(r - 2) <= 1 || r == 0) {
        if (ev == 7 && self->rec[idx].b <= 1) {
            fn_80269E80(self, idx, "SetState RUNASSIGNMENT_LEADOFFADV");
            m.Set(0, p);
            sent = 1;
        } else if (ev == 8 && self->rec[idx].b > 0) {
            fn_80269E80(self, idx, "SetState RUNASSIGNMENT_LEADOFFRET");
            m.Set(1, p);
            sent = 1;
        }
    } else {
        self->rec[idx].a = ev;
    }
    if (sent != 0) {
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

extern int fn_801A37D8(void* q);
extern void fn_8025DED4(Unk80256C80_Inner* self);
extern void fn_8025D738(Unk80256C80_Inner* self, int a);
extern void fn_8025DD20(Unk80256C80_Inner* self, void* p);
extern void fn_8026A1D8(Unk80256C80_Inner* self, int a, int b);
extern void fn_8025D4A4(Unk80256C80_Inner* self, int a);
extern void fn_8026A1D4();
void fn_8026A110(Unk80256C80_Inner* self, int a, int b)
{
    if (fn_801A37D8(self->m1EC) == 0) {
        int f = 0;
        if (a == 2 || a == 4 || a == 5)
            f = 1;
        fn_8025DED4(self);
        fn_8025D738(self, a);
        if (f != 0)
            fn_8025DD20(self, self->m434);
        fn_8026A1D8(self, a, b);
        fn_8025D4A4(self, a);
        if (a != 2)
            ((void (*)(Unk80256C80_Inner*, int))fn_8026A1D4)(self, b);
    }
}

void fn_8026A1D4() {}

void fn_8026AA04(R* self, int v, const char* file, int line)
{
    self->rec[0].a0 = v;
}

/* near-miss (parked, 76 vs 75 insns): retail keeps the four out-values at r1+0x10 (8-aligned struct-like block) and returns 0 from one shared tail; register assignment cascades from that */
int fn_8026A630(C* self, Cmd* cmd)
{
    int a;
    int b;
    int c;
    int d;
    if (fn_8025DC40(self, &a, &b, &c, &d) == 0)
        return 0;
    if (d == 0 && b == 0)
        return 0;
    Pl* p = cmd->m10;
    int g = fn_8026A0F4((G*)((char*)self + 0x190), p);
    A* ac = &p->m58C;
    int r = fn_802665DC(self->m48, fn_8035E318(ac), g, 1);
    if (ac->m3C != self->m420)
        fn_8035E664((char*)self + 0x1CC, p, -1);
    fn_8026AA04((R*)cmd, 5, lbl_805DB170, 0xF57);
    cmd->m8 = 4;
    cmd->m0 = 3;
    cmd->mC = ac->m38;
    cmd->m20 = r;
    float f = (float)g;
    cmd->m18 = f;
    cmd->m1C = f;
    return 1;
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

/* near-miss (parked): same instructions, the independent field stores of the command record are scheduled in a different order (tried 5 source orders) */
void fn_8026BD5C(C* self, Cmd* cmd, Pl* p)
{
    cmd->m8 = 4;
    cmd->mC = -1;
    cmd->m4 = 0;
    cmd->m14 = 0;
    cmd->m18 = -1.0f;
    cmd->m1C = -1.0f;
    cmd->m20 = 6;
    cmd->m24 = 0;
    cmd->m28 = lbl_806055AC;
    cmd->m10 = p;
    cmd->m34 = 0;
    cmd->m0 = 1;
    fn_8026AA04((R*)cmd, 3, lbl_805DB170, 0x65D);
    cmd->mC = p->m58C.m38;
    fn_80269F88((G*)((char*)self + 0x190), p, 3);
    fn_8025E26C(self, cmd, 2, p->m458);
}

int fn_8026BE3C(C* self, Pl* p)
{
    return self->m4C4[p->m458 - 9];
}
