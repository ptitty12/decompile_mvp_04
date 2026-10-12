/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B21AC-0x803B3D60 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/cmn/sndcmn.h"

struct Unk803B31B4 {
    char pad[0x24];
    float m24;
};

struct Unk803B21EC_Node {
    int m0;
    void (*m4)(Unk803B21EC_Node*);
    Unk803B21EC_Node* m8;
    char padC[0xC];
    short m18;
    char m1A;
};

struct Unk803B270C_Desc {
    int m0;
    int m4;
    char pad8[2];
    unsigned short mA;
    void (*mC)(void*, int, int);
    int m10;
    void (*m14)(Unk803B21EC_Node*);
};

struct Unk803B27DC_Obj {
    char pad0[4];
    int m4;
    char pad8[0x10];
    short m18;
    char m1A;
};

/* 0x5C-byte mixer slot array, reached through lbl_806AA2D4+0x1DC. */
struct Unk803B21EC {
    unsigned char m0;
    unsigned char m1;
    char pad2[2];
    float m4[6];
    float m1C[6];
    float* m34;
    float* m38;
    float m3C;
    Unk803B21EC_Node* m40;
    int (*m44)(int);
    int m48;
    Unk803B31B4* m4C;
    void* m50;
    int m54;
    Unk803B27DC_Obj* m58;
};

struct Unk806AA2D4 {
    char pad0[9];
    unsigned char m9;
    char padA[4];
    unsigned char mE;
    char padF[0xD9];
    float mE8[6];
    float* m100;
    char pad104[0xD8];
    Unk803B21EC* m1DC;
};
extern Unk806AA2D4 lbl_806AA2D4;
extern Unk803B21EC* lbl_806AA4B0;
extern int lbl_80625448;
extern void (*lbl_806AA2D8)(int);

extern "C" void fn_803B21EC(int idx);

extern "C" void fn_803B21AC(int idx)
{
    fn_803B21EC(idx);
    lbl_806AA2D8(idx);
}

extern "C" void fn_803B5F9C(Unk803B21EC_Node** head, void* node);
extern "C" void fn_803B6004(Unk803B21EC_Node** head, void* node);
extern "C" void fn_803B5EC4(void* obj);
extern "C" void fn_803B5F18(void* obj, int* buf);
extern "C" void fn_803B31B4(Unk803B31B4* obj, int v);

extern "C" void fn_803B21EC(int idx)
{
    Unk803B21EC* e = &lbl_806AA2D4.m1DC[idx];
    int i;
    for (i = 0; i < lbl_80625448; i++)
        lbl_806AA2D4.m100[i] += e->m34[i] * e->m3C;
    for (i = 0; i < lbl_806AA2D4.m9; i++)
        lbl_806AA2D4.mE8[i] += e->m4[i] * e->m3C;
    Unk803B21EC_Node* next;
    do {
        if (e->m40->m4 != 0)
            e->m40->m4(e->m40);
        next = e->m40->m8;
        SNDMEMI_free(e->m40);
        e->m40 = next;
    } while (next != 0);
    e->m0 = 0;
}

extern "C" void fn_803B22EC(int idx, int ch, float v)
{
    lbl_806AA2D4.m1DC[idx].m1C[ch] = v;
    lbl_806AA2D4.m1DC[idx].m1 = 1;
}

extern "C" void fn_803B2320(int idx, int ch, float v)
{
    lbl_806AA2D4.m1DC[idx].m38[ch] = v;
    lbl_806AA2D4.m1DC[idx].m1 = 1;
}

extern "C" void fn_803B270C(int idx, int a, Unk803B270C_Desc* d)
{
    Unk803B21EC* e = &lbl_806AA4B0[idx];
    Unk803B21EC_Node* n = (Unk803B21EC_Node*)SNDMEMI_allocz(d->m4);
    d->mC(n, d->m0, a);
    n->m18 = d->mA;
    n->m0 = d->m10;
    n->m4 = d->m14;
    n->m1A = 0;
    fn_803B5F9C(&e->m40, n);
}

extern "C" int fn_803B2794(int idx)
{
    Unk803B21EC* e = &lbl_806AA4B0[idx];
    return e->m44 != 0 ? e->m44(e->m48) : -1;
}

extern "C" void fn_803B27DC(int idx, int n)
{
    Unk803B21EC* e = &lbl_806AA4B0[idx];
    if (n > 0) {
        Unk803B27DC_Obj* old = e->m58;
        if (old == 0) {
            Unk803B27DC_Obj* o = (Unk803B27DC_Obj*)SNDMEMI_allocz(0x58);
            e->m58 = o;
            o->m4 = 0;
            e->m58->m18 = 0x50;
            e->m58->m1A = 0;
            fn_803B5EC4(e->m58);
            fn_803B5F9C(&e->m40, e->m58);
        }
        int buf[2];
        buf[0] = n << 8;
        buf[1] = sndgs.sso.set.outputrate << 8;
        fn_803B5F18(e->m58, buf);
    } else if (e->m58 != 0) {
        fn_803B6004(&e->m40, e->m58);
        SNDMEMI_free(e->m58);
        e->m58 = 0;
    }
}

extern "C" void fn_803B2AB4(int idx, int v)
{
    Unk803B21EC* e = &lbl_806AA4B0[idx];
    if (e->m4C != 0)
        fn_803B31B4(e->m4C, v);
}

extern "C" void fn_803B31B4(Unk803B31B4* o, int v)
{
    o->m24 = v * 0.000244140625f;
}

struct Unk803B3334 {
    char pad[0x1828];
    void* m1828;
    int m182C;
};

extern "C" void fn_803B3334(Unk803B3334* o)
{
    if (o->m1828 != 0) {
        SNDMEMI_free(o->m1828);
        o->m1828 = 0;
        o->m182C = 0;
    }
}

extern "C" void fn_803B343C(int n, short* src, float* dst)
{
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

extern "C" void fn_803B1080(int voice, int v);

extern "C" int fn_803B3CF8(int shandle, int v)
{
    int setvoice;
    int voice = SNDVOICEI_get(shandle);
    if (voice >= 0) {
        setvoice = -1;
        while (iSNDpatchkey(voice, &setvoice))
            fn_803B1080(setvoice, v);
    }
    return voice;
}
