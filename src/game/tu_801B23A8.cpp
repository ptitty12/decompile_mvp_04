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
int fn_801B38A8(Unk801AB63C_P* a, int i, int flag);
int fn_801B608C(Unk801AB63C_P* a, Unk801B23A8_Q* q);
int fn_801B5F8C(Unk801AB63C_P* a, Unk801B23A8_Q* q);
int fn_801B62E4(Unk801AB63C_P* a, int i);
int fn_801B3B90(void* a, void* b);
int fn_801B3A34(void* a, void* b);
int fn_800974B8(Unk8019F8C0_Inner* t, int v);
int fn_80097450(Unk8019F8C0_Inner* t, int v);
void fn_8017D640(void* a, int b, Unk801B23A8_Q* c, int d, int e);
extern float lbl_805CF740;
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

int fn_801B28F8(void* a, void* b)
{
    return fn_801B5DE8(a, b, 0) == 1 ? fn_801B5298(a, b) : 0;
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

float fn_801B3580(void* a, Unk801B23A8_Q* q)
{
    return q->m5D8;
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
