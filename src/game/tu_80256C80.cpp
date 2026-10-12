/*
 * Game code, .text 0x80256C80-0x8025877C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_W W;

extern "C++" {
void fn_8025707C(Unk80256C80_M* self);
void fn_8025707C(Unk80256C80_M* self, int a);
char* fn_8035E8CC(char* p, unsigned i);
float fn_8014E40C(Unk8024EF40_P* p, int k);
int fn_801A2034(Unk8024EF40_Q* q, int k);
void fn_8025E55C(Unk80256C80_Inner* i, Unk8024EF40_P* p);
Unk8024EF40_P* fn_80257B40(Unk80256C80_M* self);
struct Unk801A6DB8_R {
    char pad0[0x14];
    int m14;
    int m18;
};
void fn_8025505C(Unk8024EF40_A* a, int v, int w);
void fn_8026B94C(Unk80256C80_Inner* i, int k);
Unk801A6DB8_R* fn_801A6DB8(Unk8024EF40_Q* q);
void fn_8025777C(Unk80256C80_M* self, Unk8024EF40_P* p, int a);
void fn_80268564(void* p);
struct Unk80258390_C {
    char pad0[0x10];
    int m10;
    char pad14[0x3A4 - 0x14];
    char* m3A4;
};
int fn_801D0294(void* p);
int fn_801C1638(Unk8024EF40_Q* q, int k);
extern int* lbl_8061B9C4;
struct Unk80257458_E {
    int m0;
    char pad4[0x1C];
    int m20;
};
extern char lbl_80660F68[];
extern char lbl_80661818[];
extern int lbl_8061D5FC;
void* fn_8037D768(void* x);
float fn_80382BB8(void* p);
void fn_8023ECD4(int self, int k, int b);
void fn_8037EB3C(void* p, int a);
void fn_8037B424(void* self, int a);
void fn_80255974(int a, int b);
void fn_8035AB00(void* self);
struct Unk8025CDFC_Obj {
    char d[0x548];
};
Unk80256C80_Inner* fn_8025CDFC(Unk8025CDFC_Obj* p, Unk80256C80_M* m, int a, int b);
void fn_8025CF64(Unk80256C80_Inner* i, int a);
void fn_80377408(void* p);
void fn_80265858(Unk80256C80_Inner* i);
void fn_802649B4(Unk80256C80_Inner* i);
void fn_80265A80(Unk80256C80_Inner* i);
void fn_8026BA30(Unk80256C80_Inner* i);
void fn_80269DE4(void* p);
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;
typedef Unk8024EF40_Q Q;
Unk8024EF40_Q* fn_802570D4(Unk80256C80_M* self);
void* fn_801A4B34(void* w);

inline P* Roster(Q* q, unsigned i) { if (i <= 0xC) return q->m65C[i]; return 0; }

int fn_80258740(void* list, P* p);
P* fn_8026B918(I* i, unsigned pos);
int fn_8026B8E4(I* i, unsigned pos);
int fn_80254984(A* a);
int fn_80254A34(A* a);
int fn_801A2034(int a);
int fn_8035E69C(void* p, int a);
int fn_8035E630(void* p, int a);
int fn_8035E8CC(void* p, int a);
void fn_80264844(I* i);
int fn_80254EA4(A* a, int b);
int fn_8014E310(int a);
void fn_8025480C(A* a, int b);
void fn_8025D054(I* i, int a);
void fn_8025EA9C(I* i);
void fn_8025E924(I* i, int a, int b);
void fn_8025ED44(I* i);
void fn_8025E7E4(I* i);
void fn_8025E4B4(I* i);
void fn_8026BAD8(I* i);
void fn_80268928(void* p);
void fn_80259E3C(void* p);
void fn_802449F4(P* p);
void fn_80255910(A* a);
int fn_801C1950(int a);
int fn_8017C94C(Unk8024EF40_Ctx* c);
int fn_801BBF04(int a);
int fn_80259330(M* self);
int fn_802676C0(void* p);
int fn_80266784(void* p);
void fn_802683CC(void* p, P* q);
void fn_80269E24(void* p, int a);
void fn_80268144(void* p);
int fn_8035E318(A* a);
}

struct Unk80256CB4_S350 {
    char pad0[0x350];
    float m350;
};

struct Unk80256CD4_Vec3 {
    float m0;
    float m4;
    float m8;
};
struct Unk80256CD4_O {
    char pad0[0x320];
    Unk80256CD4_Vec3 m320;
    Unk80256CD4_Vec3 m32C;
    Unk80256CD4_Vec3 m338;
};

struct Unk80256D40_Mtx {
    int m0;
    char pad4[0x1C];
    char m20[4];
};

struct Unk80256D84_Data {
    char pad0[0x98];
};
struct Unk80256D84_V : Unk80256D84_Data {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Unk80256D40_Mtx* v6();
};

struct Unk80256DE0_S618 {
    char pad0[0x618];
    void* m618;
};

struct Unk80256E04_SAB8 {
    char pad0[0x618];
    int m618[4];
    char pad628[0xAB8 - 0x628];
    int mAB8;
};

struct Unk80256EC4_S {
    char pad0[0x240];
    int m240;
    char pad244[0x618 - 0x244];
    void* m618;
};

void fn_80256C80(Unk80256A90_V* self)
{
    self->v3();
}

void fn_80256CB4(Unk80256CB4_S350* self, float f)
{
    SetF(&self->m350, f);
}

Unk80256CD4_Vec3 fn_80256CD4(Unk80256CD4_O* o)
{
    return o->m320;
}

Unk80256CD4_Vec3 fn_80256CF8(Unk80256CD4_O* o)
{
    return o->m338;
}

Unk80256CD4_Vec3 fn_80256D1C(Unk80256CD4_O* o)
{
    return o->m32C;
}

char* fn_80256D40(Unk80256D40_Mtx* x)
{
    if (x->m0 == 0)
        fn_8037D768(x);
    x->m0 = 1;
    return x->m20;
}

char* fn_80256D84(Unk80256D84_V* self)
{
    Unk80256D40_Mtx* m = self->v6();
    if (m->m0 == 0)
        fn_8037D768(m);
    m->m0 = 1;
    return m->m20;
}

float fn_80256DE0(Unk80256DE0_S618* self)
{
    return fn_80382BB8(self->m618);
}

int fn_80256E04(Unk80256E04_SAB8* self)
{
    return self->mAB8;
}

int fn_80256E0C(Unk80256E04_SAB8* self, int i)
{
    return self->m618[i];
}

void fn_80256E1C(int self, int b)
{
    fn_8023ECD4(self, 0, b);
}

void fn_80256E44(int self, int b)
{
    fn_8023ECD4(self, 1, b);
}

void fn_80256E6C(int self, int b)
{
    fn_8023ECD4(self, 2, b);
}

void fn_80256E94(int self, int b)
{
    fn_8023ECD4(self, 3, b);
}

int fn_80256EBC()
{
    return 0;
}

void fn_80256EC4(Unk80256EC4_S* self, int a)
{
    self->m240 = a;
    fn_8037EB3C(self->m618, a ^ 1);
}

void fn_80256EF8(const void** self, int a)
{
    *self = lbl_80660F68;
    fn_8037B424(self, a);
}

int fn_80256F28()
{
    return lbl_8061D5FC;
}

int fn_80256F34()
{
    return 0x4DACE415;
}

void fn_80256F40()
{
}

void fn_80256F44()
{
    fn_80255974(1, 0xFFFF);
}

void fn_80256F70()
{
    fn_80255974(0, 0xFFFF);
}

void fn_80256F9C(Unk80256C80_M* self, int a)
{
    self->m0 = lbl_80661818;
    if (self->m4 != 0)
        delete self->m4;
    if (a & 1)
        fn_80377408(self);
}

Unk80256C80_M* fn_8025700C(Unk80256C80_M* self, int a, int b)
{
    fn_8035AB00(self);
    self->m0 = lbl_80661818;
    self->m4 = fn_8025CDFC(new (0) Unk8025CDFC_Obj, self, a, b);
    self->m10 = a;
    fn_8025707C(self);
    return self;
}

void fn_8025707C(Unk80256C80_M* self, int a)
{
    self->m1C = 0;
    self->mC = 0;
    self->m14 = 0;
    self->m18 = 0;
    self->m20 = -1;
    self->m8 = 1;
    fn_8025CF64(self->m4, a);
    self->m1C = 0;
}

Unk8024EF40_Q* fn_802570D4(Unk80256C80_M* self)
{
    return self->m4->m1EC;
}

void fn_802570E0(Unk80256C80_M* self)
{
    fn_80265858(self->m4);
}

void fn_80257104(Unk80256C80_M* self)
{
    fn_802649B4(self->m4);
    fn_80265A80(self->m4);
}

void fn_8025713C(M* self, int a)
{
    if (fn_80266784((char*)self->m4 + 0x48) != 0)
        self->mC = 0;
    else
        self->mC = a;
    if (a != 0 && fn_80259330(self) != 0) {
        for (int i = 12; i > 9; i--) {
            P* p = Roster(fn_802570D4(self), i);
            fn_802683CC((char*)self->m4 + 0x124, p);
            if (p != 0) {
                A* ac = &p->m58C;
                fn_80254A34(ac);
                int t = ac->m38;
                if (t > fn_8035E318(ac))
                    fn_80269E24((char*)self->m4 + 0x190, p->m458 - 9);
            }
        }
        fn_80268144((char*)self->m4 + 0x124);
    }
}

void fn_80257234(Unk80256C80_M* self)
{
    fn_8026BA30(self->m4);
}

void fn_80257258(M* self)
{
    for (int i = 12; i > 8; i--) {
        P* p = Roster(fn_802570D4(self), i);
        if (p != 0)
            fn_8025777C(self, p, 0);
    }
}

void fn_802572CC(Unk80256C80_M* self)
{
    fn_80269DE4((char*)self->m4 + 0x190);
}

/* near-miss: 46 vs 47 instructions; retail reloads m44 after the q tests (lwz 0x44(r11) twice), ours keeps it in a register. Tried tests as nested ifs, a go flag, inline accessors */
void fn_8025739C(M* self, P* p)
{
    if (fn_801A2034(fn_802570D4(self), 3) != -1) {
        P* q = fn_802570D4(self)->m6CC;
        A* a = &p->m58C;
        if (a->b2 || a->m44 == 2 || ((q == 0 || q->m38C != 1 || q->m388 != 3) && a->m44 == 1)) {
            fn_8025E55C(self->m4, p);
            I* i = self->m4;
            if (i->m434 == p)
                i->m434 = fn_80257B40(self);
        }
    }
}

int fn_80257458(M* self, P* p)
{
    int r = 0;
    if (p != 0) {
        A* a = &p->m58C;
        if (a->m38 == a->m30) {
            Unk80257458_E* e = (Unk80257458_E*)fn_8035E8CC((char*)self->m4 + 0x204, (unsigned)p->m458);
            if (e != 0 && e->m0 != 3) {
                int t = e->m20;
                int lo = 2, hi = 3;
                if (t == lo || t == hi)
                    r = 1;
            }
        }
    }
    return r;
}

int fn_802576E4(M* self, P* p, int c)
{
    int r = 0;
    if (p->m458 == 10) {
        A* a = &p->m58C;
        if (a->m38 == 0 && a->m30 == 1 && !(fn_8014E40C(p, 1) >= 291600.0f) && self->m4->m464 != 2)
            r = c == 4;
    }
    return r;
}

P* fn_80257B40(M* self)
{
    P* a = fn_802570D4(self)->m65C[12];
    if (a != 0)
        return a;
    P* b = fn_802570D4(self)->m65C[11];
    if (b != 0)
        return b;
    P* c = fn_802570D4(self)->m65C[10];
    if (c != 0)
        return c;
    P* d = (P*)fn_801A4B34(fn_802570D4(self));
    if (d != 0 && d->m458 == 9)
        return d;
    return 0;
}

int fn_80257CC0(M* self, P* p)
{
    if (fn_801A2034(fn_802570D4(self), 3) != -1) {
        int s = self->m4->m1FC;
        int f = 0;
        if (s == 6 || s == 4 || s == 5 || s == 3)
            f = 1;
        if (f != 0 && fn_80254A34(&p->m58C) != 0 && fn_8035E69C((char*)self->m4 + 0x1CC, p->m458) != 0)
            return 1;
    }
    return 0;
}

int fn_80257D68(M* self, P* p)
{
    if (fn_801A2034(fn_802570D4(self), 3) != -1 && fn_80254A34(&p->m58C) != 0) {
        if (fn_8035E630((char*)self->m4 + 0x1CC, (int)p) != -1)
            return 1;
    }
    return 0;
}

void fn_80257DD8(M* self)
{
    fn_80264844(self->m4);
}

/* near-miss: retail tests the slot at the loop top (cmpwi/bne after the first call, back edge to it); ours rotates the test to the bottom with an entry jump. `for(;;) { if (r) break; ... }` and do/while variants tried */
P* fn_80257DFC(M* self, P* p, int a)
{
    unsigned i = p->m458;
    if (i - 9 > 2)
        return 0;
    P* r;
    if (a != 0) {
        r = (P*)fn_8026B8E4(self->m4, i);
    } else {
        int o = i * 4;
        r = (P*)fn_8026B8E4(self->m4, i);
        while (r == 0) {
            i += 1;
            o += 4;
            if (i - 9 > 3)
                break;
            Q* q = fn_802570D4(self);
            if (i <= 0xC)
                r = *(P**)((char*)q + 0x65C + o);
        }
    }
    return r;
}

P* fn_80257EA8(M* self, int a)
{
    if (a < 0)
        return 0;
    for (int i = 9; i <= 12; i++) {
        P* p = Roster(fn_802570D4(self), i);
        if (p != 0 && fn_80254EA4(&p->m58C, 0) == a)
            return p;
    }
    return 0;
}

void fn_80257F3C(M* self, int a)
{
    for (int i = 10; i <= 12; i++) {
        P* p = Roster(fn_802570D4(self), i);
        int k = fn_8014E310(i);
        if (p != 0) {
            A* ac = &p->m58C;
            int z = ac->b2;
            if (z == 0) {
                if (ac->m3C == k) {
                    fn_8025480C(ac, -1);
                } else {
                    fn_8025480C(ac, k);
                    if (ac->m44 == 1)
                        ac->m44 = z;
                }
            }
        }
    }
    self->m8 = a;
}

void fn_80258000(M* self)
{
    I* i = self->m4;
    i->m194 = 0;
    fn_8025D054(self->m4, 4);
    fn_8025EA9C(self->m4);
}

void fn_80258048(M* self)
{
    fn_8025D054(self->m4, 5);
}

void fn_80258070(M* self, int a)
{
    fn_8025E924(self->m4, a, 1);
}

void fn_80258098(M* self, int a)
{
    if (fn_802570D4(self) != 0 && (fn_801A2034(fn_802570D4(self), 3) == -1 || fn_801BBF04(((Unk8024EF40_Ctx*)self->m10)->m3BC) == 0)) {
        if (fn_80259330(self) != 0 || a != 0) {
            if (fn_801C1950(fn_802570D4(self)->m700->m3BC) == 2)
                fn_8025D054(self->m4, 6);
            else
                fn_8025D054(self->m4, 6);
        } else if (fn_8017C94C((Unk8024EF40_Ctx*)self->m10) != 0 || fn_802676C0((char*)self->m4 + 0x48) != 0) {
            fn_8025D054(self->m4, 6);
        } else if (fn_801BBF04(((Unk8024EF40_Ctx*)self->m10)->m3BC) == 0) {
            fn_8025D054(self->m4, 8);
        } else {
            fn_8025D054(self->m4, 6);
        }
    }
}

void fn_80258194(M* self, int a)
{
    if (fn_801A6DB8(fn_802570D4(self))->m18 != 0) {
        fn_8025ED44(self->m4);
        fn_80268564((char*)self->m4 + 0x124);
        if (a == 0 && fn_80259330(self) != 0) {
            fn_8025D054(self->m4, 6);
        } else {
            fn_8025D054(self->m4, 9);
            fn_8025E4B4(self->m4);
            if (fn_802570D4(self)->m6F4 == 3)
                fn_8025777C(self, fn_802570D4(self)->m65C[9], 0);
        }
    }
}

void fn_80258250(M* self, int a)
{
    if (self->m4->m1FC != 8) {
        if (a == 5) {
            if (fn_801A6DB8(fn_802570D4(self))->m14 != 0) {
                fn_8025D054(self->m4, 7);
            } else {
                for (int i = 9; i <= 12; i++) {
                    P* p = Roster(fn_802570D4(self), i);
                    if (p != 0) {
                        int k = fn_8014E310(p->m458);
                        fn_8025505C(&p->m58C, k, 0);
                    }
                }
            }
        } else if (a == 3) {
            fn_8025E4B4(self->m4);
        } else {
            fn_8025D054(self->m4, 9);
            fn_8025713C(self, 0);
        }
        fn_8026B94C(self->m4, a);
        fn_80268144((char*)self->m4 + 0x124);
    }
}

void fn_80258354(M* self)
{
    fn_8025D054(self->m4, 6);
    fn_8025ED44(self->m4);
}

inline int Nz(int x)
{
    return x != 0;
}

void fn_80258390(M* self)
{
    Unk80258390_C* c = (Unk80258390_C*)self->m10;
    if (fn_801D0294(c->m3A4 + 0x28C) != 0 && c->m10 == *lbl_8061B9C4 - 1) {
        int f = Nz(fn_801C1638(fn_802570D4(self), 10));
        if (f == 0 || *((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 2) {
            fn_8025D054(self->m4, 6);
            fn_8025ED44(self->m4);
        }
    }
}

void fn_802585E8(M* self)
{
    self->m4->m194 = 0;
}

void fn_802585F8(M* self, int a)
{
    fn_8025707C(self, a);
    fn_8026BAD8(self->m4);
    fn_8025D054(self->m4, 1);
    fn_80268928((char*)self->m4 + 0xBC);
}

void fn_80258644(M* self)
{
    fn_8025E7E4(self->m4);
}

void fn_80258668(M* self)
{
    fn_80259E3C((char*)self->m4 + 0x468);
    self->m20 = -1;
    self->m14 = 0;
    self->m18 = 0;
    for (int i = 9; i <= 12; i++) {
        P* p = Roster(fn_802570D4(self), i);
        if (p != 0) {
            if (p->m458 == 9)
                fn_802449F4(p);
            A* ac = &p->m58C;
            int z = 0;
            ac->m44 = z;
            fn_8025480C(ac, -1);
            ac->b1 = z;
            fn_80255910(ac);
        }
    }
    fn_8026BAD8(self->m4);
    self->m8 = 0;
}

/* near-miss: 14 vs 15 instructions; retail loads m38 before m30 and computes lo + 1 before the bgtlr, ours schedules the loads the other way round */
int fn_80258740(void* list, P* p)
{
    A* a = &p->m58C;
    int lo = a->m38;
    int hi = a->m30;
    int d = hi - lo;
    if (d > 1) {
        if (hi > lo)
            return lo + 1;
        return lo;
    }
    if (d < 0)
        return lo;
    return hi;
}
