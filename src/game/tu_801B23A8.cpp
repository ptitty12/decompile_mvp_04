/*
 * Game code, .text 0x801B23A8-0x801B460C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"
#include "game/tu_801B23A8.h"

void fn_801B37C0(void* p);
void fn_801B4300(void* p);
int fn_801B5DE8(void* a, void* b, int c);
int fn_801B5298(void* a, void* b);
int fn_8025416C(void* a, int b);
unsigned char fn_801B38A8(Unk801AB63C_P* a, int i, int flag);
int fn_801B608C(Unk801AB63C_P* a, Unk801B23A8_Q* q);
int fn_801B5F8C(Unk801AB63C_P* a, Unk801B23A8_Q* q);
int fn_801B62E4(Unk801AB63C_P* a, int i);
int fn_801B3B90(void* a, void* b);
int fn_801B3A34(void* a, void* b);
int fn_800974B8(Unk8019F8C0_Inner* t, int v);
int fn_80097450(Unk8019F8C0_Inner* t, int v);
int fn_8017D640(void* a, int b, Unk801B23A8_Q* c, int d, int e);
extern float lbl_805CF740;
extern float lbl_805CF754;
extern float lbl_805CF744;
extern float lbl_805CF748;
float fn_8024EF40(void* a, void* b, int c);
float fn_8024F048(void* a, void* b, void* c, int d, int e);
float fn_8024F20C(void* a, void* b, void* c, int d, int e);
int fn_80097380(Unk8019F8C0_Inner* t, int v);
int fn_800973E8(Unk8019F8C0_Inner* t, int v);
int fn_80097318(Unk8019F8C0_Inner* t, int v);
int fn_801B3E48(void* a, Unk801B23A8_Q* q, int c);
int fn_801B3FD0(void* a, Unk801B23A8_Q* q, int c);
int fn_801B40DC(void* a, Unk801B23A8_Q* q);
float fn_801B3460(void* a, Unk801B23A8_Q* q, int c);
float fn_801B3430(void* a, Unk801B23A8_Q* q);
int fn_801B5FC4(void* a, int b);
int fn_801B5EDC(void* a, int b, int c);
Unk801B23A8_Q* fn_801B2F2C(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q, int d, int e);
int fn_801B5F4C(Unk801AB63C_P* p);
int fn_801B5120(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c);
int fn_801B51E4(Unk801AB63C_P* p, Unk801B23A8_Q* q);
Unk801B23A8_Q* fn_801B2944(void* a, Unk801B23A8_Q* q, int b, int c, int d, int e, int f, int g);
int fn_801B2AD4(void* p, Unk801B23A8_Q* q);
int fn_801B6354(void* a, int b, int c);
int fn_801B40F8(Unk801AB63C_P* a, Unk801B23A8_Q* q);
int fn_801B4144(Unk801AB63C_P* a, Unk801B23A8_Q* q);
int fn_8017DD64(void* a, int b);
void fn_8017DD80(void* a, int x, Unk801B23A8_Q** b, Unk801B23A8_Q** c);
Unk801B23A8_Q* fn_801B2DC4(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q);
Unk801B23A8_Q* fn_801B2E10(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q, int d);
Unk801B23A8_Q* fn_801B2C5C(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q, int e);
Unk801B23A8_Q* fn_801B4368(Unk801B23A8_V* p, int team, int idx);
void fn_801AE180(void* a, Unk801B23A8_Q* q, int c);

float fn_801B3580(void* a, Unk801B23A8_Q* q);
void fn_800B555C();
int fn_800B55A8();
int fn_80075808(int v);
extern int lbl_8061CB3C;
extern float lbl_805CF74C;
extern float lbl_805CF750;

/* Controller argument object with a vptr at +0x98 (virtual 22 returns a state code). */
class Unk801B4190_VB {
public:
    char pad0[0x98];
};
class Unk801B4190_V : public Unk801B4190_VB {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual int fn_vslot22();
};
class Unk801B4190_Q : public Unk801B4190_V {
public:
    char pad9C[0x388 - 0x9C];
    int m388;
    char pad38C[0x704 - 0x38C];
    int m704;
    int m708;
    unsigned char m70C;
};
extern "C" void* fn_801A497C(Unk8019F8C0_Owner* o, int f, int n);
Unk801B4190_Q* fn_801B63A0(Unk801AB63C_P* p, int t);
int fn_801B45D8(Unk801AB63C_P* p, int a, Unk801B23A8_Q* q);
int fn_801A4910(Unk8019F8C0_Owner* o, int team, int slot);
void fn_801B43BC(Unk801B23A8_V* p, int team, int idx, Unk801B23A8_Q* q, int flag);

/* Iterator object (ctor 0x8014E09C, advance 0x8014E108); current index at +8. */
struct Unk801B25E4_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
void fn_8014E09C(Unk801B25E4_It* it, Unk8019F8C0_Owner* o, int a);
void fn_8014E108(Unk801B25E4_It* it);
int fn_80097148(Unk8019F8C0_Inner* t, int v);
int fn_801B26D0(Unk801AB63C_P* p, Unk801B4190_Q* q);

int fn_801C1870(void* a, int b, int c);
int fn_801C1880(void* a, int b, int c);
int fn_801C18C4(void* a, int b, int c);

struct Unk801B2FB0_Rec {
    int m0;
    float m4;
};
Unk801B2FB0_Rec fn_801B3094(Unk801AB63C_P* p, void* a, int b, int c, int d, int e, ...);
int fn_801B4190(Unk801AB63C_P* a, Unk801B4190_Q* q, Unk801B4190_Q* r);

extern float lbl_805CF730;
extern float lbl_805CF734;

int fn_80097190(Unk8019F8C0_Inner* t, int v);
int fn_80097300(Unk8019F8C0_Inner* t, int v);

class Unk80069F0C {
public:
    char pad0[1];
    float fn_8006C038(void* p);
};
extern float lbl_805CF760;

/* Candidate table used by fn_801B2E10 (same layout as Unk801B460C_Tbl in tu_801B460C.cpp). */
struct Unk801B460C_Ent {
    int a;
    float b;
};
struct Unk801B460C_Tbl {
    Unk801AB63C_P* m0;
    int m4;
    int m8;
    Unk801B460C_Ent m0C[25];
};
void fn_801B564C(Unk801B460C_Tbl* t);
void fn_801B5688(Unk801B460C_Tbl* t, int id, int limit, float v);
int fn_801B5700(Unk801B460C_Tbl* t, int k);
int fn_801C184C(void* a, int b, int c);
float fn_80097F68(Unk8019F8C0_Inner* t, int a, int b, int c, int d);
int fn_801C1894(void* a, int b, int c);
int fn_801C18A4(void* a, int b, int c, int d);
float fn_8025356C(void* p);
int fn_800968C0(Unk8019F8C0_Inner* t, int key, int c);
int fn_8009692C(Unk8019F8C0_Inner* t, int v);
extern float lbl_805CF758;
extern float lbl_805CF75C;
int fn_801C18D8(void* a, int b, int c);
inline int Unk801B3FD8_B(unsigned char* b, int i) { return b[i]; }

struct Unk801B2470_T {
    char pad0[0x5C];
    int m5C[1];
};

struct Unk801B2480_T {
    char pad0[0x5C];
    int m5C[1];
};

void fn_801B2480(Unk801B2480_T* p, int i, int v);

int fn_801B23A8(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int r = 4;
    if (q->m460 == 0) {
        r = 3;
        if ((unsigned)(fn_801B5FC4(p, q->m708) - 1) <= 1) {
            if (fn_801B5F4C(p) <= 0) {
                r = 0;
            } else if (fn_801B5F4C(p) <= 1) {
                r = 1;
            }
        }
    }
    return r;
}

void fn_801B2428(Unk801B2480_T* p)
{
    int i = 0;
    do {
        fn_801B2480(p, i, 0xff);
        i++;
    } while (i <= 1);
}

int fn_801B2470(Unk801B2470_T* p, int i)
{
    return p->m5C[i];
}

void fn_801B2480(Unk801B2480_T* p, int i, int v)
{
    p->m5C[i] = v;
}

Unk801B2490::Unk801B2490(int a, int b) : Unk801B5A44(a, b)
{
    Setup();
}

Unk801B2490::~Unk801B2490() {}

void Unk801B2490::Setup()
{
    fn_vslot3();
}

void fn_801B2538(Unk8019F8C0_Owner* o)
{
    fn_800B555C();
    if (fn_800B55A8() == 1) {
        Unk8019F8C0_Inner* m = o->m6F8->m14;
        if (fn_80075808(m[0].m198) == 1 || fn_80075808(m[1].m198) == 1) {
            lbl_8061CB3C = 2;
        } else {
            lbl_8061CB3C = 0;
        }
    } else {
        lbl_8061CB3C = 1;
    }
}

void fn_801B25BC() {}

void fn_801B25C0() {}

void fn_801B25C4(void* p)
{
    fn_801B4300(p);
}

void fn_801B25E4(Unk801AB63C_P* p, int team)
{
    Unk8019F8C0_Owner* o = p->m8;
    int a = team;
    if (a > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
        team = a;
    }
    Unk8019F8C0_Inner* t = o->m6F8->m14 + team;
    Unk801B25E4_It it;
    fn_8014E09C(&it, o, 0);
    Unk801B25E4_It* ip;
    if (it.m8 != 10) {
        do {
            ip = &it;
            Unk801B4190_Q* q = (Unk801B4190_Q*)fn_801A497C(p->m8, team, ip->m8);
            if (q) {
                int s = fn_80097148(t, (unsigned char)q->m70C);
                if (s == 1 || s == 3) {
                    fn_801B26D0(p, q);
                }
            }
            fn_8014E108(&it);
        } while (ip->m8 != 10);
    }
}

/* near-miss: same code; callee-saved roles differ (retail: p r29, q r28, slot r31, x r30, result r26), 22 slots. */
int fn_801B26D0(Unk801AB63C_P* p, Unk801B4190_Q* qq)
{
    Unk801B23A8_Q* q = (Unk801B23A8_Q*)qq;
    int idx = q->m708;
    int r = 0;
    Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[idx];
    unsigned slot = (unsigned char)fn_8009692C(e, fn_800968C0(e, q->m704, 1));
    Unk801B23A8_Q* x;
    if (slot < e->m168.m4) {
        x = fn_801B4368((Unk801B23A8_V*)p, idx, slot);
    } else {
        x = 0;
    }
    if (x != 0) {
        fn_801B43BC((Unk801B23A8_V*)p, idx, slot, 0, 0);
        r = fn_801B45D8(p, (int)q, x);
        if (r == 0) {
            fn_801B43BC((Unk801B23A8_V*)p, idx, slot, x, 0);
        }
    } else {
        int s = q->m460;
        int k = 4;
        if (s == 0) {
            k = 3;
        }
        Unk801B23A8_Q* y = fn_801B2944(p, q, s, k, 3, 0, 0, 0);
        if (y == 0) {
            y = fn_801B2944(p, q, s, 7, 3, 0, 0, 0);
        }
        if (y != 0) {
            r = fn_801B45D8(p, (int)q, y);
        }
    }
    return r;
}

int fn_801B2834(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int r = 0x78;
    if (q != 0 && (fn_801B5DE8(p, q, 0) != 0 || q->m708 != (p->m8->m6F8->m14[2].m8 == 0))) {
        if ((int)q->m4C4 < 0) {
            r = fn_801B5120(p, q, 1);
        } else if (fn_801B5F4C(p) > 2) {
            r = fn_801B5120(p, q, 0);
        } else {
            r = fn_801B51E4(p, q);
        }
    }
    return r;
}

int fn_801B28F8(void* a, void* b)
{
    return fn_801B5DE8(a, b, 0) == 1 ? fn_801B5298(a, b) : 0;
}

/* near-miss: 2 slots differ (retail sets the return register to 0 before testing q). */
int fn_801B2AD4(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int r = 0;
    int ret = 0;
    if (q != 0) {
        if (fn_801B40F8(p, q) != 0) {
            int i = q->m708;
            if (fn_801B5EDC(p, i, 1) == 2 && i == 0 && fn_8017DD64(p->m4, 0) == 2) {
                Unk801B23A8_Q* a;
                Unk801B23A8_Q* b;
                fn_8017DD80(p->m4, q->m708, &a, &b);
                if (fn_801B4144(p, a) != 0 && fn_801B4144(p, b) != 0) {
                    r = 1;
                }
            }
        }
        ret = r;
    }
    return ret;
}

/* near-miss: 48/48 insns but register allocation differs (retail keeps q in r30, t in r29, p in r31;
 * `li r3,0` is the pre-set result). */
Unk801B23A8_Q* fn_801B2B9C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c)
{
    Unk801B23A8_Q* r = 0;
    if (q != 0) {
        Unk801B23A8_Q* t = fn_801B2944(p, q, 0, c, 0, 1, 1, 0);
        if (t == 0 || fn_801B2AD4(p, t) != 0) {
            return q;
        }
        if (fn_801B6354(p, q->m708, 5) != 1) {
            r = fn_801B2F2C(p, t, q, c, 0);
            if (r == q) {
                r = 0;
            }
        }
    }
    return r;
}

Unk801B23A8_Q* fn_801B2C5C(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q, int e)
{
    int x = fn_801B4190((Unk801AB63C_P*)a, (Unk801B4190_Q*)p, (Unk801B4190_Q*)e);
    int y = fn_801B4190((Unk801AB63C_P*)a, (Unk801B4190_Q*)q, (Unk801B4190_Q*)e);
    Unk801B2FB0_Rec ra = fn_801B3094((Unk801AB63C_P*)a, p, 0, 2, 0, 0);
    Unk801B2FB0_Rec rb = fn_801B3094((Unk801AB63C_P*)a, q, 0, 2, 0, 0);
    if (y != 0 && ra.m0 <= rb.m0) {
        if (x == 0 || ra.m0 < rb.m0) {
            return q;
        }
        if (ra.m4 >= rb.m4) {
            return q;
        }
    }
    return p;
}

int fn_801B2D48(int a, int b, int c, int d)
{
    if (b == c) {
        return d;
    }
    return c;
}

Unk801B23A8_Q* fn_801B2D5C(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    Unk801B23A8_Q* a;
    Unk801B23A8_Q* b;
    fn_8017DD80(p->m4, q->m708, &a, &b);
    Unk801B23A8_Q* r = a;
    if (r == 0 && b == 0) {
        return 0;
    }
    if (q == r) {
        r = b;
    }
    return r;
}

Unk801B23A8_Q* fn_801B2DC4(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q)
{
    int x = p->m4C8;
    Unk801B23A8_Q* r = 0;
    int y = q->m4C8;
    if (x != y) {
        if (x == 0x13 || y == 0x13) {
            r = q;
            if (x == 0x13) {
                r = p;
            }
        } else if (x == 0x12 || y == 0x12) {
            r = q;
        }
    }
    return r;
}

Unk801B23A8_Q* fn_801B2E10(void* pp, Unk801B23A8_Q* a, Unk801B23A8_Q* b, int c)
{
    Unk801AB63C_P* p = (Unk801AB63C_P*)pp;
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    Unk801B2FB0_Rec ra = fn_801B3094(p, a, 0, c, 0, 0);
    Unk801B2FB0_Rec rb = fn_801B3094(p, b, 0, c, 0, 0);
    Unk801B460C_Tbl t;
    Unk801B460C_Tbl* tp = &t;
    tp->m0 = p;
    tp->m4 = 0;
    fn_801B564C(tp);
    fn_801B5688(tp, (int)a, ra.m0, ra.m4);
    fn_801B5688(tp, (int)b, rb.m0, rb.m4);
    Unk801B23A8_Q* r = (Unk801B23A8_Q*)fn_801B5700(tp, 0);
    if (r == 0) {
        if (c != 3) {
            r = fn_801B2E10(p, a, b, 3);
        }
        if (r == 0) {
            r = b;
        }
    }
    return r;
}

Unk801B23A8_Q* fn_801B2F2C(void* a, Unk801B23A8_Q* p, Unk801B23A8_Q* q, int d, int e)
{
    Unk801B23A8_Q* r = fn_801B2DC4(a, p, q);
    if (r == 0) {
        if (d != 2) {
            r = fn_801B2E10(a, p, q, d);
        } else {
            r = fn_801B2C5C(a, p, q, e);
        }
        if (r == 0) {
            r = q;
        }
    }
    return r;
}

Unk801B23A8_Q* fn_801B2FB0(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c)
{
    Unk801B23A8_Q* a;
    Unk801B23A8_Q* b;
    Unk801B23A8_Q* r = 0;
    fn_8017DD80(p->m4, q->m708, &a, &b);
    int k = fn_8017DD64(p->m4, q->m708);
    if (k == 0) {
        r = fn_801B2944(p, q, 0, c, 3, 0, 0, 0);
    } else if (k == 1) {
        Unk801B2FB0_Rec rec = fn_801B3094(p, a, 0, c, 0, 0);
        if (rec.m0 != -1) {
            r = a;
        }
    } else {
        r = fn_801B2F2C(p, a, b, c, 0);
    }
    return r;
}

/* near-miss: same code; the float register numbering (f0/f13/f12/f11) differs (14 slots). */
float fn_801B333C(void* a, Unk801B23A8_Q* q)
{
    float* f = (float*)((char*)q + 0x480);
    float sum = f[3];
    float t = f[5];
    sum = sum + f[4];
    int n = 2;
    if (!(t <= lbl_805CF730)) {
        sum = sum + t;
        n = 3;
    }
    t = f[6];
    if (!(t <= lbl_805CF730)) {
        sum = sum + t;
        n++;
    }
    t = f[7];
    if (!(t <= lbl_805CF730)) {
        sum = sum + t;
        n++;
    }
    sum = sum * lbl_805CF734;
    sum = sum / (float)n;
    return sum;
}

float fn_801B3430(void* a, Unk801B23A8_Q* q)
{
    Unk801B23A8_F* f = &q->m4D8;
    float r = (f->m5C + f->m68) * lbl_805CF740;
    return r;
}

/* near-miss: retail keeps the first partial result in f31 across the second call (stfd f31 in the prologue);
 * mine spills it to a stack slot (43 vs 42 insns). */
float fn_801B3460(void* a, Unk801B23A8_Q* q, int c)
{
    float r = lbl_805CF744;
    if (c != 0) {
        r = fn_8024EF40((char*)q + 0xA0C, q->m44C, q->m708);
    } else {
        char* s = (char*)q + 0xA0C;
        const float t = fn_8024F048(s, q->mA04, q->m44C, q->m708, 1);
        r = (t + fn_8024F20C(s, q->mA04, q->m44C, q->m708, 1)) * lbl_805CF748;
    }
    return r;
}

int fn_801B350C(void* a, Unk801B23A8_Q* q, Unk801B23A8_Q* r, int c)
{
    float x = fn_801B3460(a, q, c);
    float y = fn_801B3460(a, r, c);
    return x >= y + lbl_805CF74C;
}

float fn_801B3580(void* a, Unk801B23A8_Q* q)
{
    return q->m5D8;
}

int fn_801B3588(void* a, Unk801B23A8_Q* q, Unk801B23A8_Q* r)
{
    float x = fn_801B3580(a, q);
    float y = fn_801B3580(a, r);
    return x >= y + lbl_805CF750;
}

float fn_801B35F0(void* a, Unk801B23A8_Q* q)
{
    float t = fn_801B3460(a, q, 0);
    float u = fn_801B3430(a, q);
    return (t + u) * lbl_805CF754;
}

int fn_801B3650(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    Unk8019F8C0_Inner* t = &p->m8->m6F8->m14[q->m708];
    if (fn_80097380(t, q->m704) == 1) {
        return 1;
    }
    if (fn_800973E8(t, q->m704) == 1) {
        return 2;
    }
    if (fn_80097450(t, q->m704) == 1) {
        return 3;
    }
    if (fn_800974B8(t, q->m704) == 1) {
        return 4;
    }
    int x = fn_80097318(t, q->m704);
    int r = 5;
    if (x == 1) {
        r = 0;
    }
    return r;
}

int fn_801B371C(void* a, Unk801B23A8_Q* q, int c)
{
    int r = 0;
    if (fn_801B5DE8(a, q, 0) == 1) {
        if (fn_801B40DC(a, q) == 1) {
            r = fn_801B3E48(a, q, c);
        } else {
            r = fn_801B3FD0(a, q, c);
        }
    }
    return r;
}

void fn_801B37A0(void* p)
{
    fn_801B37C0(p);
}

int fn_801B37C0(void* a, Unk801B23A8_Q* q)
{
    int v = fn_8025416C(q->m588, 0x16);
    if (v == 3) {
        return 6;
    }
    if (v == 4) {
        return 7;
    }
    return 5;
}

int fn_801B380C(void* a, Unk801B23A8_Q* q)
{
    int v = fn_8025416C(q->m588, 0x16);
    return (v == 3 || v == 4) ? 4 : 3;
}

int fn_801B3850(Unk801AB63C_P* a, Unk801B23A8_Q* q, int c)
{
    int x = fn_801B38A8(a, q->m708, c);
    int y = fn_801B608C(a, q);
    return x > y ? y : x;
}

inline Unk8019F8C0_Inner* Unk801B38A8_At(Unk8019F8C0_Inner* a, int i) { return &a[i]; }
inline int Unk801B38A8_Other(int t)
{
    if (t > 2) {
        int u = 3;
        if (t == 3) {
            u = 4;
        }
        return u;
    }
    return t == 0;
}
unsigned char fn_801B38A8(Unk801AB63C_P* p, int i, int flag)
{
    if (flag == 1) {
        i = Unk801B38A8_Other(i);
    }
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    return Unk801B38A8_At(m, i)->m1B4[m[2].m0];
}

int fn_801B38FC(Unk801AB63C_P* a, Unk801B23A8_Q* q)
{
    int i = q->m708;
    int r = 2 - fn_801B5F8C(a, q);
    r += fn_801B62E4(a, i);
    r += fn_801B38A8(a, i, 1);
    return r;
}

int fn_801B3954(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c)
{
    int r = 0;
    int i = q->m708;
    int x = fn_801B5FC4(p, i);
    int y = fn_801B5EDC(p, i, 0);
    int z = fn_801B62E4(p, i);
    if (fn_801C1870(p, y, -1) != 0) {
        r = 1;
    } else if (fn_801C1870(p, y, 1) != 0) {
        if (fn_801C18C4(p, -1, x) != 0) {
            r = 1;
        } else if (c != 0) {
            r = z > x;
        } else {
            r = z >= x;
        }
    }
    return r ^ 1;
}

/* near-miss: same code; retail loads the two constants into f30/f31 after the byte-sum loop (85 vs 87 insns). */
int fn_801B3A34(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    float k1 = lbl_805CF758;
    float k2 = lbl_805CF75C;
    int t = Unk801B38A8_Other(q->m708);
    Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[t];
    int sum = 0;
    for (int i = 0; i < 128; i++) {
        sum += Unk801B3FD8_B(e->m1B4, (unsigned char)i);
    }
    int x = fn_801B5FC4(p, q->m708);
    int r = sum == 0;
    if (r != 0) {
        if (fn_801C1894(p, 0, x)) {
            r = fn_8025356C((char*)q + 0x480) >= lbl_805CF75C;
        } else if (fn_801C18A4(p, 1, 3, x)) {
            r = fn_8025356C((char*)q + 0x480) >= lbl_805CF758;
        }
        if (r != 0) {
            r = 0;
            if (fn_801B3954(p, q, 0)) {
                r = 1;
            }
        }
    }
    return r;
}

/* near-miss: same code; retail sets the result register to 0 before the branch on the old value (`cmpwi r31,0; li r31,0; beq`), 3 slots. */
int fn_801B3B90(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int t = Unk801B38A8_Other(q->m708);
    Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[t];
    int sum = 0;
    for (unsigned char i = 0; i < e->m3E4; i++) {
        sum += (int)fn_80097F68(e, 0, i, 2, 0);
    }
    int r = sum == 0;
    if (r != 0) {
        int x = fn_801B5FC4(p, q->m708);
        int y = fn_801B5EDC(p, q->m708, 0);
        if (fn_801C1870(p, y, 2)) {
            r = 0;
            if (fn_801C18D8(p, 0, x)) {
                r = 1;
            }
        }
        if (r != 0) {
            r = 0;
            if (fn_801B3954(p, q, 1)) {
                r = 1;
            }
        }
    }
    return r;
}

int fn_801B3CD8(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c)
{
    int r = 1;
    int x = fn_801B5FC4(p, q->m708);
    int y = fn_801B5EDC(p, q->m708, 0);
    if (x >= -6) {
        if (fn_801C1880(p, y, 1) && x <= -1) {
            r = 0;
        } else if (fn_801C1880(p, y, 2) && fn_801C18C4(p, -2, x)) {
            r = 0;
        } else if (c != 0 && fn_801C18C4(p, 3, x)) {
            float f = ((Unk80069F0C*)p->m8->m6F8)->fn_8006C038((void*)q->m704);
            if (!(f >= lbl_805CF760) && fn_801C1880(p, y, 2)) {
                r = 0;
            }
        }
    } else {
        r = 0;
    }
    return r;
}

int fn_801B3DF0(void* a, void* b)
{
    int r = 0;
    if (fn_801B3B90(a, b) != 0 || fn_801B3A34(a, b) != 0) {
        r = 1;
    }
    return r;
}

int fn_801B3FD8(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int r = 0;
    if (fn_801B40DC(p, q) == 1) {
        if (fn_801C184C(p, fn_801B5F4C(p), 2)) {
            int s = fn_8025416C((char*)q + 0x588, 0x16);
            unsigned k;
            switch (s) {
            case 4:
                k = 2;
                break;
            case 3:
                k = 1;
                break;
            default:
                k = 0;
                break;
            }
            int t = Unk801B38A8_Other(q->m708);
            Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[t];
            unsigned sum = 0;
            for (int i = 0; i < 128; i++) {
                sum += Unk801B3FD8_B(e->m1B4, (unsigned char)i);
            }
            r = k >= sum;
        }
    }
    return r;
}

int fn_801B3FD0() { return 0; }

/* near-miss: retail loads the flag word straight into r3 (lwz r3 / srwi r3,r3), 2 slots differ. */
int fn_801B40DC(void* a, Unk801B23A8_Q* q)
{
    return q ? q->m4C4 >> 31 : 0;
}

int fn_801B40F8(Unk801AB63C_P* a, Unk801B23A8_Q* q)
{
    int r;
    if (q) {
        r = fn_800974B8(&a->m8->m6F8->m14[q->m708], q->m704);
    } else {
        r = 0;
    }
    return r;
}

int fn_801B4144(Unk801AB63C_P* a, Unk801B23A8_Q* q)
{
    int r;
    if (q) {
        r = fn_80097450(&a->m8->m6F8->m14[q->m708], q->m704);
    } else {
        r = 0;
    }
    return r;
}

int fn_801B4190(Unk801AB63C_P* a, Unk801B4190_Q* q, Unk801B4190_Q* r)
{
    if (q != 0) {
        Unk801B4190_Q* o = fn_801B63A0(a, q->m708);
        if (r != 0) {
            o = r;
        }
        if (o != 0) {
            if ((o->m388 == 0 && q->fn_vslot22() == 0) || (o->m388 == 1 && q->fn_vslot22() == 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int fn_801B4244(Unk801AB63C_P* p, Unk801B23A8_Q* q, int n)
{
    if (q == 0) {
        return 0;
    }
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    int idx = q->m708;
    Unk8019F8C0_Inner* t = m + idx;
    int side = 0;
    int f = 0;
    if (m[2].m8 != 0) {
        f = 1;
    }
    if (idx == f) {
        side = 1;
    }
    for (int i = 0; i < n; i++) {
        if (fn_80097300(t, fn_80097190(t, side)) == q->m704) {
            return 1;
        }
        side++;
    }
    return 0;
}

void fn_801B4300(Unk801B23A8_V* p)
{
    for (int t = 0; t < 2; t++) {
        Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[t];
        for (unsigned i = 0; i < e->m168.m4; i++) {
            p->m14[t][i] = 0;
        }
    }
}

/* near-miss: retail loads p->m8 before copying team to r0 and compares the original register (r4);
 * mine copies first and compares r0 (5 slots differ). Same team-resolve snippet as fn_801A2034. */
Unk801B23A8_Q* fn_801B4368(Unk801B23A8_V* p, int team, int idx)
{
    Unk8019F8C0_Owner* o = p->m8;
    int t = team;
    if (team > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        t = f;
        if (team != 3) {
            t ^= 1;
        }
    }
    return p->m14[t][idx];
}

void fn_801B43BC(Unk801B23A8_V* p, int team, int idx, Unk801B23A8_Q* q, int flag)
{
    Unk8019F8C0_Owner* o = p->m8;
    int a = team;
    if (a > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
        team = a;
    }
    if (flag != 0) {
        fn_801AE180(*(void**)((char*)o->m700 + 0x3c8), q, 3);
    }
    p->m14[team][idx] = q;
}

/* near-miss: same code; retail keeps team in r29 and the loop index in r31 (mine swaps them), 15 slots differ. */
void fn_801B445C(Unk801B23A8_V* p, int team)
{
    Unk8019F8C0_Inner* t = &p->m8->m6F8->m14[team];
    int a = team;
    if (a > 2) {
        int f = 0;
        if (p->m8->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
        team = a;
    }
    Unk8019F8C0_Ring* ring = &t->m168;
    for (unsigned i = 0; i < ring->m4; i++) {
        Unk801B23A8_Q* q = fn_801B4368(p, team, i);
        if (q) {
            int x = fn_801A4910(p->m8, team, t->m168.m0[(unsigned char)i]);
            fn_801B43BC(p, team, i, 0, 0);
            fn_801B45D8((Unk801AB63C_P*)p, x, q);
        }
    }
}

int fn_801B454C(Unk801B23A8_V* p, Unk801B23A8_Q* q)
{
    if (q) {
        int t = q->m708;
        Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[t];
        for (unsigned i = 0; i < e->m168.m4; i++) {
            if (fn_801B4368(p, t, i) == q) {
                return i;
            }
        }
    }
    return 0xFF;
}

int fn_801B45D8(Unk801AB63C_P* p, int a, Unk801B23A8_Q* c)
{
    return fn_8017D640(p->m4, c->m708, c, a, 0);
}
