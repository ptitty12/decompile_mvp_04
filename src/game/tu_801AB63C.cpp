/*
 * Game code, .text 0x801AB63C-0x801AE30C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801AB63C.h"

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
int fn_801B5DE8(void* a, void* q, int c);
int fn_801AD31C(void* a, Unk801AB63C_Q* q, int c);
int fn_801AD880(void* a, Unk801AB63C_Q* q, int c, int d);
int fn_801B3FD8(void* a, Unk801AB63C_Q* q);
int fn_801B5FC4(void* a, int b);
int fn_801B62E4(void* a, int b);
int fn_801C1894(void* a, int b, int c);
int fn_801C18A4(void* a, int b, int c, int d);
int fn_801C18D8(void* a, int b, int c);
int fn_801C190C(void* a, int b);
int fn_801B4144(void* a, Unk801AB63C_Q* q);
int fn_801B5EDC(void* a, int b, int c);
int fn_8017DD64(void* a, int b);
int fn_801C185C(void* a, int b, int c);
int fn_801B5F4C(Unk801AB63C_P* p);
int fn_801B40F8(void* a, Unk801AB63C_Q* q);
int fn_801B4190(void* a, Unk801AB63C_Q* q, void* r);
Unk801AB63C_Q* fn_801B2944(void* a, void* q, int b, int c, int d, int e, int f, int g);
void fn_801ABD10(Unk801AB63C_P* p, void* a, Unk801AB63C_Q* c, int d);
void fn_8017DD80(void* a, int x, Unk801AB63C_Q** b, Unk801AB63C_Q** c);
int fn_801ADC44(Unk801AB63C_P* p, int a, int b);
int fn_801AE130(Unk801AB63C_P* p, Unk801AB63C_Q* q);
void fn_801AE3A8(Unk801AB63C_Ent* e, int* a, int* b);
int fn_8017DCCC(void* a, Unk801AB63C_Q* q);
int fn_801ABCDC(Unk801AB63C_P* p, int i);
void fn_801ACF2C(Unk801AB63C_P* p);
void fn_801AD118(Unk801AB63C_P* p);
void fn_801B25E4(Unk801AB63C_P* p, int n);
int fn_8006BC74(void* m, int f);
void fn_801AC594(Unk801AB63C_P* p, void* q);
void fn_801AC7E4(Unk801AB63C_P* p, int f, int a, int b);
void* fn_801A497C(Unk8019F8C0_Owner* o, int f, int n);
void fn_801AB914(Unk801AB63C_P* p, int x);
void fn_801AE0A0(Unk801AB63C_P* p, int i, int key);
int fn_801A4B34(Unk8019F8C0_Owner* o);
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

void fn_801AB964(Unk801AB63C_P* p)
{
    int f = p->m8->m6F8->m14[2].m8 == 0;
    if (fn_801ABCDC(p, f) == 1) {
        if (fn_8006BC74(p->m8->m6F8, f) == 1) {
            fn_801AC594(p, fn_801A497C(p->m8, f, 0));
        }
        fn_801AB914(p, f);
    }
    fn_801AE0A0(p, f, fn_801A4B34(p->m8));
}

void fn_801ABA0C(Unk801AB63C_P* p)
{
    int f = 0;
    if (p->m8->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    if (fn_801ABCDC(p, f) == 1) {
        if (fn_8006BC74(p->m8->m6F8, f) == 1) {
            fn_801AC7E4(p, f, 8, -1);
        }
        fn_801AB914(p, f);
    }
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

void fn_801ABC14(Unk801AB63C_P* p)
{
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    int t = m[2].m8;
    if (fn_801ABCDC(p, t == 0) == 1) {
        Unk8019F8C0_Owner* o = p->m8;
        int t2 = o->m6F8->m14[2].m8;
        void* q = fn_801A497C(o, t2 == 0, 0);
        if (q && fn_801B5DE8(p, q, 0) == 0) {
            Unk801AB63C_Q* r = fn_801B2944(p, q, 0, 3, 3, 0, 0, 0);
            if (r != 0) {
                fn_801ABD10(p, q, r, 0);
            }
        }
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

int fn_801AD470(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c)
{
    int r = fn_801AD31C(p, q, c);
    if (r != 0) {
        int idx = q->m708;
        r = 0;
        if (fn_801B3FD8(p, q) == 0) {
            int a = fn_801B5FC4(p, q->m708);
            int b = fn_801B62E4(p, q->m708);
            int c2 = fn_801C1894(p, 0, a);
            if (fn_801C18A4(p, 1, 3, a) != 0 || (c2 != 0 && idx == 0)
                || (fn_801C18D8(p, 1, a) != 0 && b > 0 && a - b <= 3)) {
                r = 1;
            }
        }
    }
    return r;
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

int fn_801AD900(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c)
{
    int r = fn_801AD880(p, q, c, 1);
    if (r != 0) {
        r = 0;
        if (fn_801B3FD8(p, q) == 0 && (fn_801B4144(p, q) == 0 || fn_801B4190(p, q, 0) == 0)) {
            int b = fn_801B62E4(p, q->m708);
            int a = fn_801B5FC4(p, q->m708);
            if (fn_801C18A4(p, 1, 3, a) != 0 || (fn_801C190C(p, a) != 0 && b > 0 && a - b <= 3)) {
                r = 1;
            }
        }
    }
    return r;
}

int fn_801AD9EC(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d, int e)
{
    int r = 0;
    if (fn_801B5EDC(p, q->m708, 0) < c && fn_801B40F8(p, q) == 0 && fn_801B4144(p, q) == 0) {
        int v = fn_801B5FC4(p, q->m708);
        if (v >= d) {
            r = v <= e;
        }
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

/* near-miss: 11 slots differ; retail keeps the team flag in r4 and loads q->m708 into r3 for the xor. */
int fn_801ADB88(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c)
{
    int r = 0;
    if (q != 0) {
        Unk8019F8C0_Owner* ow = q->m44C;
        if (fn_8017DD64(ow->m700, q->m708) != 0 && c <= 0x45 && fn_801C185C(p, fn_801B5F4C(p), 4) != 0) {
            int f = 0;
            if (q->m44C->m6F8->m14[2].m8 != 0) {
                f = 1;
            }
            int t = q->m708 ^ f;
            r = t == 0;
        }
    }
    return r;
}

/* near-miss: retail compares in cr7 (cmpwi cr7; mfcr; rlwinm) instead of xori/subfic/adde; 3 slots differ. */
int fn_801ADC34(int a, int b, int c)
{
    return c == 0x54;
}

int fn_801ADC44(Unk801AB63C_P* p, Unk801AB63C_Q* q, Unk801AB63C_Q* r)
{
    if (r == 0 || q == 0) {
        return 0;
    }
    int res = 0;
    Unk801AB63C_Q* a;
    Unk801AB63C_Q* b;
    fn_8017DD80(p->m4, q->m708, &a, &b);
    if (a != 0) {
        int t = fn_801AE130(p, a) ^ r->m704;
        res = t == 0;
    }
    if (b != 0 && fn_801AE130(p, b) == r->m704) {
        res += 1;
    }
    return res;
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
