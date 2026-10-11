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
void fn_8017D640(void* a, int b, Unk801B23A8_Q* c, int d, int e);
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
void fn_801AE180(void* a, int b, int c, void* d);

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

void fn_801B25BC() {}

void fn_801B25C0() {}

void fn_801B25C4(void* p)
{
    fn_801B4300(p);
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

float fn_801B3580(void* a, Unk801B23A8_Q* q)
{
    return q->m5D8;
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

/* near-miss: retail builds the 3/4 team index through a separate register (li r0,3 / li r0,4 / mr r4,r0). */
unsigned char fn_801B38A8(Unk801AB63C_P* p, int i, int flag)
{
    if (flag == 1) {
        if (i > 2) {
            int r = 3;
            if (i == 3) {
                r = 4;
            }
            i = r;
        } else {
            i = i == 0;
        }
    }
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    return m[i].m1B4[m[2].m0];
}

int fn_801B38FC(Unk801AB63C_P* a, Unk801B23A8_Q* q)
{
    int i = q->m708;
    int r = 2 - fn_801B5F8C(a, q);
    r += fn_801B62E4(a, i);
    r += fn_801B38A8(a, i, 1);
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

void fn_801B45D8(Unk801AB63C_P* p, int a, Unk801B23A8_Q* c)
{
    fn_8017D640(p->m4, c->m708, c, a, 0);
}
