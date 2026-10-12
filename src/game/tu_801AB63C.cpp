/*
 * Game code, .text 0x801AB63C-0x801AE30C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801AB63C.h"

/* Argument object as the float probes fn_8024F048/fn_8024F20C see it. */
struct Unk801ADA8C_Q {
    char pad0[0x44C];
    void* m44C;
    char pad450[0x708 - 0x450];
    int m708;
    char pad70C[0xA04 - 0x70C];
    void* mA04;
    char padA08[4];
    char mA0C[4];
};
float fn_8024F048(void* a, void* b, void* c, int d, int e);
float fn_8024F20C(void* a, void* b, void* c, int d, int e);
float fn_80253434(int p);
void fn_8017DD80(void* a, int x, int* b, int* c);
extern float lbl_805CEF74;
extern float lbl_805CEF78;

/* Iterator object (ctor 0x8014E09C, advance 0x8014E108); current index at +8. */
struct Unk801AD254_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
void fn_8014E09C(Unk801AD254_It* it, Unk8019F8C0_Owner* o, int a);
void fn_8014E108(Unk801AD254_It* it);
extern float lbl_805CF71C;
float fn_801B35F0(Unk801AB63C_P* p, void* h, int i, int c);
int fn_8025416C(void* a, int b);
int fn_801AE008(Unk801AB63C_P* p, int i);
int fn_801ADDFC(Unk801AB63C_P* p, Unk801AB63C_Q* q, int a);
int fn_801AE018(Unk801AB63C_P* p, int i);
int fn_801AE05C(Unk801AB63C_P* p, int i);

struct Unk801AD044_H {
    char pad0[0x460];
    int m460;
};
struct Unk801AD044_Rec {
    int m0;
    float m4;
};
Unk801AD044_Rec fn_801B3094(Unk801AB63C_P* p, void* h, int a, int b, int c, int d, ...);
extern float lbl_805CF714;

int fn_801C1870(void* a, int b, int c);
void* fn_801AD044(Unk801AB63C_P* p, int key, int* tbl);
struct Unk801AD118_X {
    char pad0[0x10];
    float m10;
};
void fn_800B555C();
int fn_800B57EC();
extern float lbl_805CEF70;
void* fn_801AD254(Unk801AB63C_P* p, int key, int* tbl, int c);

void fn_8024DB54(void* o, const char* s, int n);
int fn_801B2FB0(void* a, Unk801AB63C_Q* q, int c);
void fn_8017DE28(void* a, Unk801AB63C_Q* q);
extern char lbl_805CEF7C[];
extern char lbl_805CEFA4[];
extern char lbl_805CEFD0[];

void fn_801AB964(Unk801AB63C_P* p);
void fn_801ABA0C(Unk801AB63C_P* p);
void fn_8017DD80(void* a, int x, int* b, int* c);
void fn_801AB748(Unk801AB63C_P* p, int v);
int fn_801A7130(Unk8019F8C0_Owner* o, int i);
void fn_8017D640(void* a, int b, Unk801AB63C_Q* c, int d, int e);
int fn_8017D6B8(void* a, int b, Unk801AB63C_Q* c, int d, int e, int f);
void fn_801B2944(void* a, int b, int c, int d, int e, int f, int g, int h);
void fn_80235780(void* a, int b, int c, int d);
int fn_801AD470(void* a, int b, int c);
int fn_801AD900(void* a, int b, int c);
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
void fn_801AC594(Unk801AB63C_P* p, Unk801AB63C_Q* q);
void fn_801AC7E4(Unk801AB63C_P* p, int f, int a, int b);
void* fn_801A497C(Unk8019F8C0_Owner* o, int f, int n);
void fn_801AB914(Unk801AB63C_P* p, int x);
int fn_801ACDCC(Unk801AB63C_P* p, Unk801AB63C_Q* h, Unk801AB63C_Q* s);
void fn_801ABD10(Unk801AB63C_P* p, int a, Unk801AB63C_Q* c, int d);
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

int fn_801B5EDC(Unk801AB63C_P* p, int i, int c);
int fn_801B62E4(Unk801AB63C_P* p, int i);
int fn_801B5F4C(Unk801AB63C_P* p);
int fn_801B5F70(Unk801AB63C_P* p);
int fn_801B38A8(Unk801AB63C_P* p, int i, int c);
int fn_801C184C(void* a, int b, int c);
int fn_801C192C(void* a, int b);
struct Unk801AB748_H {
    char pad0[0x4C8];
    int m4C8;
};

/* near-miss: same code; q/side swap r28/r29 and the case-1/case-0 tail layout of the final branch differs. */
void fn_801AB748(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    if (q != 0) {
        char* sub = (char*)q + 0x480;
        Unk801AD044_Rec rec = fn_801B3094(p, q, 0, 3, 0, 0);
        int lim = 3;
        Unk801AB748_H* h = (Unk801AB748_H*)fn_801A497C(q->m44C, q->m708, 0);
        int side = q->m708;
        int y = fn_801B5EDC(p, side, 0);
        int z = fn_801B5F4C(p);
        int x = fn_801B5FC4(p, side);
        int w = fn_801B62E4(p, side);
        w = w + fn_801B38A8(p, side, 1);
        if (*(int*)(sub + 0x50) != 0 && fn_801ADDFC(p, q, 0) == 0) {
            fn_8017DF2C(p->m4, q);
        }
        if (fn_801C184C(p, y, 0) != 0 || w < x) {
            if (h != 0 && h->m4C8 == 0x13) {
                lim = 2;
            }
            if (rec.m0 >= lim) {
                if (q->m44C->m6F8->m14[2].m0 - *(int*)(sub + 0x3C) > 2) {
                    {
                    fn_801AB6E0(p, q);
                    return;
                }
                }
            } else {
                {
                    fn_801AB6E0(p, q);
                    return;
                }
            }
        } else if (fn_801C1870(p, z, 1) != 0 && fn_801C192C(p, x) != 0) {
            switch (q->m708) {
            case 1:
                {
                    fn_801AB6E0(p, q);
                    return;
                }
            case 0:
                if (fn_801B5F70(p) != 0) {
                    fn_801AB6E0(p, q);
                }
                break;
            }
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
            fn_801AC594(p, (Unk801AB63C_Q*)fn_801A497C(p->m8, f, 0));
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

void fn_801ABB0C(Unk801AB63C_P* p)
{
    for (int i = 0; i < 2; i++) {
        int* s = &p->mC;
        int o = i * 4;
        Unk801AB63C_Q* h = (Unk801AB63C_Q*)fn_801A497C(p->m8, i, 0);
        Unk801AB63C_Q* q = *(Unk801AB63C_Q**)((char*)s + o);
        if (q != 0 && h != q) {
            if (fn_801ACDCC(p, h, q) == 0) {
                fn_801ABD10(p, (int)h, *(Unk801AB63C_Q**)((char*)s + o), 1);
            }
        }
        *(int*)((char*)s + o) = 0;
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

struct Unk801B23A8_Q;
int fn_801B371C(void* a, Unk801B23A8_Q* q, int c);
int fn_801B2834(Unk801AB63C_P* p, Unk801B23A8_Q* q);
int fn_801B3850(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c);
int fn_801B5DE8(void* a, void* b, int c);
int fn_801B5EDC(Unk801AB63C_P* p, int i, int c);
int fn_801B5FC4(void* a, int b);
Unk801AB63C_Q* fn_801B63A0(Unk801AB63C_P* p, int t);
int fn_801C1870(void* a, int b, int c);
int fn_801C18C4(void* a, int b, int c);
int fn_801ACB68(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d);
int fn_801AD6FC(void* a, int b);
int fn_801AD720(void* a, int b);
int fn_801ADCE8(Unk801AB63C_P* p, int a);

void fn_801AC594(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    int d = -1;
    int r = 0;
    int g = 0;
    if (fn_801B371C(p, (Unk801B23A8_Q*)q, 0) != 0) {
        d = fn_801B2834(p, (Unk801B23A8_Q*)q);
        fn_801AC7E4(p, q->m708, 8, d);
        return;
    }
    Unk801AB63C_Q* t = fn_801B63A0(p, q->m708);
    if (t != 0 && fn_801B5DE8(p, t, 0) == 0) {
        g = 1;
    } else if (fn_801B5DE8(p, q, 0) == 0) {
        g = 1;
    }
    if (g == 1) {
        if (r == 0) {
            if (fn_801AD6FC(p, (int)q) == 1) {
                r = fn_801ACB68(p, q, 0, -1);
            }
            if (r == 0) {
                if (fn_801AD720(p, (int)q) == 1) {
                    r = fn_801ACB68(p, q, 1, -1);
                }
                if (r == 0) {
                    if (fn_801ADCE8(p, (int)q) == 1) {
                        r = fn_801ACB68(p, q, 2, -1);
                    }
                    if (r == 0) {
                        d = fn_801B2834(p, (Unk801B23A8_Q*)q);
                        if (d <= 0x77) {
                            int f = 0;
                            int x = fn_801B5FC4(p, q->m708);
                            int y = fn_801B3850(p, (Unk801B23A8_Q*)q, 1);
                            int z = fn_801B5EDC(p, q->m708, 0);
                            if (*(int*)((char*)q + 0x4C4) < 0 && fn_801C1870(p, z, 0) != 0) {
                                f = 1;
                            }
                            if ((fn_801C18C4(p, 2, x) != 0 && y > 4) || f != 0) {
                                r = fn_801ACB68(p, q, 3, d);
                            }
                        } else {
                            r = fn_801ACB68(p, q, 3, d);
                        }
                    }
                }
            }
        }
    }
    if (r == 0) {
        if (d == -1) {
            d = fn_801B2834(p, (Unk801B23A8_Q*)q);
        }
        fn_801AC7E4(p, q->m708, 8, d);
    }
}

void fn_801ACB30(void* a, int b, int c, int d)
{
    fn_801B2944(a, b, 0, c, 0, 1, 0, d);
}

struct Unk801B23A8_Q;
struct Unk801ACDCC_G {
    char pad0[0x44C];
    void* m44C;
    char pad450[0x460 - 0x450];
    int m460;
    char pad464[0x708 - 0x464];
    int m708;
    char pad70C[0xA04 - 0x70C];
    void* mA04;
    char padA08[4];
    char mA0C[4];
};
int fn_801B4244(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c);
int fn_801C18F8(void* a, int b);
extern "C" int fn_80097190(void* o, int k);
Unk801ACDCC_G* fn_801A4910(Unk8019F8C0_Owner* o, int a, int b);

int fn_801ACDCC(Unk801AB63C_P* p, Unk801AB63C_Q* h, Unk801AB63C_Q* s)
{
    if (fn_801C1870(p, fn_801B5F4C(p), 4)) {
        if (fn_801C18F8(p, fn_801B5FC4(p, h->m708))) {
            if (fn_801B4244(p, (Unk801B23A8_Q*)h, 3) == 1) {
                int idx = h->m708;
                Unk8019F8C0_Inner* e = p->m8->m6F8->m14 + idx;
                int k = fn_80097190(e, -1);
                Unk801ACDCC_G* g = fn_801A4910(p->m8, idx, e->m168.m0[(unsigned char)k]);
                char* t = g->mA0C;
                if (!(fn_8024F048(t, g->mA04, g->m44C, g->m708, 1) + fn_8024F20C(t, g->mA04, g->m44C, g->m708, 1) > 1.4f)) {
                    Unk801AB63C_Q* r = fn_801B2944(p, g, g->m460, 4, 3, 0, 0, 0);
                    if (r != 0) {
                        return fn_801ABD44(p, (int)h, s, (int)g, (int)r);
                    }
                }
            }
        }
    }
    return 0;
}

void fn_801ACF2C(Unk801AB63C_P* p)
{
    if (fn_801C1870(p, fn_801B5F4C(p), 1)) {
        int side = p->m8->m6F8->m14[2].m8 == 0;
        if (fn_801C18A4(p, 1, 2, fn_801B5FC4(p, side))) {
            int flags[9];
            int* d = flags;
            for (int i = 0; i < 9; i++) {
                *d++ = 0;
            }
            int* h;
            while ((h = (int*)fn_801AD044(p, side, flags)) != 0) {
                int k = ((Unk801AD044_H*)h)->m460;
                if ((unsigned)(k - 1) > 7) {
                    return;
                }
                Unk801AB63C_Q* q = fn_801B2944(p, h, k, 5, 0, 0, 0, 0);
                if (q) {
                    fn_801ABD88(p, (int)h, q);
                }
                flags[k] = 1;
            }
        }
    }
}

void* fn_801AD044(Unk801AB63C_P* p, int key, int* tbl)
{
    float best = lbl_805CF714;
    Unk801AD254_It it;
    fn_8014E09C(&it, p->m8, 2);
    void* bi = 0;
    while (it.m8 != 10) {
        if (tbl[it.m8] == 0) {
            void* h = fn_801A497C(p->m8, key, it.m8);
            Unk801AD044_Rec r = fn_801B3094(p, h, ((Unk801AD044_H*)h)->m460, 4, 0, 0);
            if (!(r.m4 > best)) {
                best = r.m4;
                bi = h;
            }
        }
        fn_8014E108(&it);
    }
    return bi;
}

void fn_801AD118(Unk801AB63C_P* p)
{
    if (fn_801C1870(p, fn_801B5F4C(p), 4)) {
        int side = p->m8->m6F8->m14[2].m8 == 0;
        if ((unsigned)(fn_801B5FC4(p, side) + 9) > 0x12) {
            fn_800B555C();
            if (fn_800B57EC() != 0) {
                if (((Unk801AD118_X*)p->m8->m6F8->mC)->m10 > lbl_805CEF70) {
                    return;
                }
            }
            int flags[9];
            int* d = flags;
            for (int i = 0; i < 9; i++) {
                *d++ = 0;
            }
            int* h;
            while ((h = (int*)fn_801AD254(p, side, flags, 6)) != 0) {
                int k = ((Unk801AD044_H*)h)->m460;
                if ((unsigned)(k - 1) > 7) {
                    return;
                }
                Unk801AB63C_Q* q = fn_801B2944(p, h, k, 6, 2, 0, 0, 0);
                if (q) {
                    fn_801ABD88(p, (int)h, q);
                }
                flags[k] = 1;
            }
        }
    }
}

void* fn_801AD254(Unk801AB63C_P* p, int key, int* tbl, int c)
{
    float best = lbl_805CF71C;
    Unk801AD254_It it;
    fn_8014E09C(&it, p->m8, 2);
    void* bi = 0;
    while (it.m8 != 10) {
        if (tbl[it.m8] == 0) {
            void* h = fn_801A497C(p->m8, key, it.m8);
            float f = fn_801B35F0(p, h, it.m8, c);
            if (!(f < best)) {
                best = f;
                bi = h;
            }
        }
        fn_8014E108(&it);
    }
    return bi;
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

int fn_801AD3C4(Unk801AB63C_P* p, int x)
{
    int a;
    int b;
    fn_8017DD80(p->m4, x, &a, &b);
    int ra = 1;
    int rb = 1;
    if (a != 0) {
        ra = fn_80253434(a + 0x480) <= lbl_805CEF74;
    }
    if (b != 0) {
        if (!(fn_80253434(b + 0x480) <= lbl_805CEF74)) {
            rb = 0;
        }
    }
    return ra != 0 || rb != 0;
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

int fn_801B5FA0(Unk801AB63C_P* p, int i);
int fn_801B5F70(Unk801AB63C_P* p);
int fn_801B62E4(Unk801AB63C_P* p, int i);
int fn_801C18EC(void* a, int b);
int fn_801B2AD4(Unk801AB63C_P* p, Unk801B23A8_Q* q);

/* near-miss: same code; p and the result swap r30/r31 (as in fn_801AD744). */
int fn_801AD558(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    int r = fn_801AD31C(p, q, 1);
    if (r != 0) {
        r = 0;
        int t = fn_801B5F4C(p);
        if ((q->m708 == 0 && fn_801B5F70(p) != 0 && t == 1) || fn_801C1880(p, t, 0) != 0) {
            r = 1;
        }
        if (r != 0) {
            int side = q->m708;
            int k;
            if (side > 2) {
                int u;
                if (side == 3) {
                    u = 4;
                } else {
                    u = 3;
                }
                k = u;
            } else {
                k = side == 0;
            }
            r = 0;
            int x = fn_801B5FC4(p, side);
            int b = fn_801B5FA0(p, k);
            int y = fn_801B5EDC(p, q->m708, 0);
            if (fn_801C18A4(p, 1, 3, x) != 0 || (fn_801C18EC(p, x) != 0 && fn_801C1870(p, y, 1) != 0 && side == 0) || (fn_801C18A4(p, 4, 6, x) != 0 && b + fn_801B62E4(p, side) > 1)) {
                r = 1;
            }
            if (r != 0 && fn_801B2AD4(p, (Unk801B23A8_Q*)q) != 0) {
                r = 0;
            }
        }
    }
    return r;
}

int fn_801AD6FC(void* a, int b)
{
    return fn_801AD470(a, b, 0);
}

int fn_801AD720(void* a, int b)
{
    return fn_801AD900(a, b, 1);
}

int fn_801B40F8(Unk801AB63C_P* p, Unk801B23A8_Q* q);
int fn_801B5FA0(Unk801AB63C_P* p, int i);
int fn_801B5F70(Unk801AB63C_P* p);
int fn_801B62E4(Unk801AB63C_P* p, int i);
int fn_801B5EDC(Unk801AB63C_P* p, int i, int c);

/* near-miss: same code; q and the result swap r26/r27 (retail gives the result the higher global-alloc priority). */
int fn_801AD744(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c)
{
    int r = 0;
    if (c == 0 || fn_801B40F8(p, (Unk801B23A8_Q*)q) == 0) {
        int t = fn_801B5F4C(p);
        if ((q->m708 == 0 && fn_801B5F70(p) != 0 && t == 2) || fn_801C1880(p, t, 1) != 0) {
            r = 1;
        }
    }
    if (r != 0) {
        int t2 = q->m708;
        r = 0;
        int k;
        if (t2 > 2) {
            int u;
            if (t2 == 3) {
                u = 4;
            } else {
                u = 3;
            }
            k = u;
        } else {
            k = t2 == 0;
        }
        int a = fn_801B5FC4(p, t2);
        int b = fn_801B5FA0(p, k);
        if ((unsigned)(a - 1) <= 2 || (a > 5 && b + fn_801B62E4(p, t2) > 1) || (a == 0 && fn_801B5EDC(p, q->m708, 0) <= 1)) {
            r = 1;
        }
    }
    return r;
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

int fn_801ADA8C(void* a, Unk801AB63C_Q* b, Unk801ADA8C_Q* q)
{
    int r = 0;
    if (fn_801B4190(a, b, q) == 0) {
        char* t = q->mA0C;
        r = fn_8024F048(t, q->mA04, q->m44C, q->m708, 1) + fn_8024F20C(t, q->mA04, q->m44C, q->m708, 1) > lbl_805CEF78;
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

int fn_801ADC34(int a, int b, int c)
{
    return c > 0x54;
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

/* near-miss: same code; callee-saved roles (p/out) swap and `mr r3,r30` before fn_801AE008 is missing (the k = 4 / 3
 * select variants fix the registers but not the mr). */
int fn_801ADD3C(Unk801AB63C_P* p, Unk801AB63C_Q* q, int b, int* out)
{
    if ((unsigned)p->m8->m6F8->m14[q->m708].m78 <= 1) {
        if (q != 0) {
            if (fn_801AE008(p, q->m708) <= 3) {
                *out = -1;
                int k = 4;
                if (fn_8025416C((char*)q + 0x588, 0x16) > 1) {
                    k = 3;
                }
                if (fn_801AD9EC(p, q, k, 0, 2)) {
                    fn_801ADDFC(p, q, 1);
                }
            }
        }
    }
    return 0;
}

Unk801AB63C_Q* fn_801A4B7C(Unk8019F8C0_Owner* o, int a, int b);

/* near-miss: same code; in the second fn_801A4B7C call the scheduler emits mr r5 before li r4 (retail: li r4 first, as in the first call). */
int fn_801ADDFC(Unk801AB63C_P* p, Unk801AB63C_Q* q, int u)
{
    int f = 0;
    int idx = q->m708;
    if (p->m8->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    int e = idx == f;
    int i = 0;
    int a = fn_801AE05C(p, idx);
    int b = fn_801AE018(p, q->m708);
    if (a != 0 && b != 0) {
        f = e ^ 1;
        fn_801A4B7C(p->m8, 0, f);
        i = (int)fn_801A4B7C(p->m8, 0, f) == b;
    }
    if (i <= 0) {
        i = 1;
    }
    if (a != 0) {
        q = (Unk801AB63C_Q*)a;
    }
    for (; i <= 4; i++) {
        Unk801AB63C_Q* x = fn_801A4B7C(p->m8, i, e ^ 1);
        if (fn_801ADA8C(p, q, (Unk801ADA8C_Q*)x) != 0 && fn_801ADC44(p, q, x) == 0) {
            return 1;
        }
    }
    return 0;
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

void fn_801AE180(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c)
{
    void* h = fn_801A497C(p->m8, q->m708, 0);
    int a;
    int b;
    fn_8017DD80(p->m4, q->m708, &a, &b);
    if ((int)q == a || (int)q == b || q == h) {
        fn_8024DB54(q, lbl_805CEF7C, 0x20);
        return;
    }
    void* pl = p->m8->m700;
    if (a != 0 && b != 0) {
        if (fn_801B2FB0(*(void**)((char*)pl + 0x3c8), q, c) == a) {
            fn_8017DF2C(pl, b);
            fn_8024DB54((void*)b, lbl_805CEFA4, 0x20);
        } else {
            fn_8017DF2C(pl, a);
            fn_8024DB54((void*)b, lbl_805CEFA4, 0x20);
        }
    }
    fn_8017DE28(pl, q);
    fn_8024DB54(q, lbl_805CEFD0, 0x20);
}

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
