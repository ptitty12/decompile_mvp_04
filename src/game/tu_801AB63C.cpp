/*
 * Game code, .text 0x801AB63C-0x801AE30C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801AB63C.h"

struct Unk801AB63C_E {
    int m0;
    int m4;
};

void fn_801AB964(Unk801AB63C_P* p);
void fn_801ABA0C(Unk801AB63C_P* p);
void fn_8017DD80(void* a, int x, int* b, int* c);
void fn_801AB748(Unk801AB63C_P* p, int v);
int fn_801A7130(Unk8019F8C0_Owner* o, int i);
void fn_8017D640(void* a, int b, Unk801AB63C_Q* c, int d, int e);
int fn_8017D6B8(void* a, int b, Unk801AB63C_Q* c, int d, int e, int f);
void fn_801B2944(void* a, int b, int c, int d, int e, int f, int g, int h);
void fn_80235780(void* a, int b, int c, int d);
void fn_801AD470(void* a, int b, int c);
void fn_801AD900(void* a, int b, int c);
int fn_801A4B34(Unk8019F8C0_Owner* o);
int fn_801ADC44(Unk801AB63C_P* p, int a, int b);
int fn_801AE130(Unk801AB63C_P* p, Unk801AB63C_Q* q);
void fn_801AE3A8(Unk801AB63C_Ent* e, int* a, int* b);
int fn_8017DCCC(void* a, Unk801AB63C_Q* q);
int fn_801ABCDC(Unk801AB63C_P* p, int i);
void fn_801ACF2C(Unk801AB63C_P* p);
void fn_801AD118(Unk801AB63C_P* p);
void fn_801B25E4(Unk801AB63C_P* p, int n);
int fn_801B454C(Unk801AB63C_P* p, Unk801AB63C_Q* q);
void fn_8017DF2C(void* a, Unk801AB63C_Q* q);
int fn_801C1880(void* a, int b, int c);
int fn_801B5EDC(void* a, int b, int c);
int fn_801B40F8(void* a, Unk801AB63C_Q* q);
void fn_8017DF2C(void* a, int b);
void fn_80252DD8(void* a, int b);
void fn_801AE3F0(Unk801AB63C_Ent* e, Unk801AB63C_Q* q, int n);
void fn_801AE494(Unk801AB63C_Ent* e, int* a, int* b);
void fn_801AE4DC(Unk801AB63C_Ent* e, int a);
void fn_801AE4DC(Unk801AB63C_Ent* e, Unk801AB63C_Q* q);

void fn_801AB63C(Unk801AB63C_P* p)
{
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    int t = m[2].m8;
    if (fn_801ABCDC(p, t == 0) == 1) {
        fn_801ACF2C(p);
        fn_801AD118(p);
    }
    p->m5C = 0;
}

void fn_801AB6A0(Unk801AB63C_P* p)
{
    p->m5C = p->m5C + 1;
    fn_801AB964(p);
    fn_801ABA0C(p);
}

void fn_801AB6E0(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    if (q) {
        int f = fn_801B454C(p, q) != 0xFF ? 1 : 0;
        if (f == 0 && q->m4D0 == 0) {
            fn_8017DF2C(p->m4, q);
        }
    }
}

void fn_801AB914(Unk801AB63C_P* p, int x)
{
    int a;
    int b;
    fn_8017DD80(p->m4, x, &a, &b);
    fn_801AB748(p, a);
    fn_801AB748(p, b);
}

void fn_801ABAA0(Unk801AB63C_P* p)
{
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    int t = m[2].m8;
    if (fn_801ABCDC(p, t == 0) == 1) {
        fn_801B25E4(p, p->m8->m6F8->m14[2].m8 == 0);
    }
}

void fn_801ABBA8(Unk801AB63C_P* p)
{
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    int t = m[2].m8;
    if (fn_801ABCDC(p, t == 0) == 1) {
        fn_801B25E4(p, p->m8->m6F8->m14[2].m8 == 0);
    }
}

int fn_801ABCDC(Unk801AB63C_P* p, int i)
{
    return fn_801A7130(p->m8, i) != 0 ? 1 : 0;
}

void fn_801ABD10(Unk801AB63C_P* p, int a, Unk801AB63C_Q* c, int d)
{
    fn_8017D640(p->m4, c->m708, c, a, d);
}

int fn_801ABD44(Unk801AB63C_P* p, int a, Unk801AB63C_Q* c, int d, int e)
{
    return fn_8017D6B8(p->m4, c->m708, c, a, e, d) != 2 ? 1 : 0;
}

void fn_801ABD88(Unk801AB63C_P* p, int a, Unk801AB63C_Q* c)
{
    fn_8017D640(p->m4, c->m708, c, a, 0);
}

void fn_801ACB30(void* a, int b, int c, int d)
{
    fn_801B2944(a, b, 0, c, 0, 1, 0, d);
}

int fn_801AD31C(void* a, Unk801AB63C_Q* q, int c)
{
    int r = 0;
    if (fn_801C1880(a, fn_801B5EDC(a, q->m708, 0), c) != 0) {
        r = fn_801B40F8(a, q) == 0;
    }
    return r;
}

void fn_801AD38C(Unk801AB63C_P* p)
{
    fn_80235780(p->m8->m700->m3B0, 5, 1, 0);
}

void fn_801AD6FC(void* a, int b)
{
    fn_801AD470(a, b, 0);
}

void fn_801AD720(void* a, int b)
{
    fn_801AD900(a, b, 1);
}

int fn_801AD880(void* a, Unk801AB63C_Q* q, int c, int d)
{
    int r = 0;
    if (fn_801C1880(a, fn_801B5EDC(a, q->m708, 0), c) != 0 && (d == 0 || fn_801B40F8(a, q) == 0)) {
        r = 1;
    }
    return r;
}

void fn_801ADB20(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    void* pl = p->m8->m700;
    int a;
    int b;
    fn_8017DD80(pl, q->m708, &a, &b);
    if (a) {
        fn_8017DF2C(pl, a);
    }
    if (b) {
        fn_8017DF2C(pl, b);
    }
}

/* near-miss: retail compares in cr7 (cmpwi cr7; mfcr; rlwinm) instead of xori/subfic/adde; 3 slots differ. */
int fn_801ADC34(int a, int b, int c)
{
    return c == 0x54;
}

int fn_801ADCE8(Unk801AB63C_P* p, int a)
{
    return fn_801ADC44(p, a, fn_801A4B34(p->m8)) != 0 ? 1 : 0;
}

void fn_801ADF40(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    if (fn_801AE130(p, q)) {
        fn_801AE4DC(&p->m60[q->m708], q);
    }
}

void fn_801ADF90(Unk801AB63C_P* p, Unk801AB63C_Q* q, int flag)
{
    if (q && fn_8017DCCC(p->m4, q)) {
        fn_80252DD8((char*)q + 0x480, flag);
        if (flag) {
            fn_801AE3F0(&p->m60[q->m708], q, flag);
        }
    }
}

int fn_801AE008(Unk801AB63C_P* p, int i)
{
    return *(int*)((char*)p + i * 0x14 + 0x60);
}

int fn_801AE018(Unk801AB63C_P* p, int i)
{
    int a = 0;
    int b = 0;
    fn_801AE3A8(&p->m60[i], &a, &b);
    return b;
}

int fn_801AE05C(Unk801AB63C_P* p, int i)
{
    int a = 0;
    int b = 0;
    fn_801AE3A8(&p->m60[i], &a, &b);
    return a;
}

void fn_801AE0A0(Unk801AB63C_P* p, int i, int key)
{
    Unk801AB63C_Ent* e = &p->m60[i];
    int a;
    int b;
    fn_801AE3A8(e, &a, &b);
    if (b == key) {
        fn_801AE4DC(e, a);
        return;
    }
    fn_801AE494(e, &a, &b);
    if (b == key) {
        fn_801AE4DC(e, a);
    }
}

int fn_801AE130(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    int r = 0;
    if (q && fn_8017DCCC(p->m4, q)) {
        r = q->m4D0;
    }
    return r;
}

void fn_801AE17C() {}

void fn_801AE2A4(int* p, int a, int b)
{
    p[1] = b;
    p[0] = a;
}

void fn_801AE2B0(Unk801AB63C_E* e)
{
    e->m0 = 0;
    e->m4 = 0;
}

int fn_801AE2C0(Unk801AB63C_E* e)
{
    int r = 0;
    if (e->m4 && e->m0) {
        r = 1;
    }
    return r;
}

int fn_801AE2E8(Unk801AB63C_E* e, int v)
{
    return e->m0 == v;
}

int fn_801AE2FC(Unk801AB63C_E* e)
{
    return e->m0;
}

int fn_801AE304(Unk801AB63C_E* e)
{
    return e->m4;
}
