/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B21AC-0x803B3D60 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/cmn/sndcmn.h"

extern "C" void fn_803A975C();
extern "C" void fn_803A979C();
extern "C" float fn_803B44E4(float x);
extern "C" float fn_803B457C(float x);
extern unsigned char* lbl_806AA4E8[];
extern void* lbl_806AA4E4;
extern unsigned char lbl_806262F4[];

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

extern "C" void fn_803B5F9C(Unk803B21EC_Node** head, void* node);
extern "C" void fn_803B6004(Unk803B21EC_Node** head, void* node);
extern "C" void fn_803B5EC4(void* obj);
extern "C" void fn_803B5F18(void* obj, int* buf);
extern "C" void fn_803B31B4(Unk803B31B4* obj, int v);

struct Unk803B3334 {
    void* m0;
    void* m4;
    char pad8[0x14];
    unsigned char* m1C;
    int m20;
    float m24;
    float m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    char pad40[0x17E8];
    void* m1828;
    int m182C;
    int m1830;
};

extern "C" int fn_803B02CC(int v);
extern "C" int fn_803B4BEC(int v);
extern "C" int fn_803B3F60(const unsigned char* p, int n);
extern "C" void fn_803B31F4();
extern "C" void fn_803B3334(Unk803B3334* o);
extern int lbl_8069CBC0;

extern "C" void fn_803B1080(int voice, int v);

extern "C" void fn_803B21AC(int idx)
{
    fn_803B21EC(idx);
    lbl_806AA2D8(idx);
}

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

/* near-miss: 38 vs 39 insns: retail keeps o in r31 and n in r29 (loads m3C, m38, *count up front, then n = m38 / *count); ours swaps those two saved registers and orders the loads differently; local-variable and load-order variants tried */
extern "C" int fn_803B2EAC(Unk803B3334* o, int* pcount, char** pdst)
{
    int pos = o->m3C;
    int avail = o->m38;
    int want = *pcount;
    int n = avail;
    if (want <= avail)
        n = want;
    Snd::Util::MemCpy(*pdst, (char*)o + (pos << 2) + 0x838, n * 4);
    o->m3C += n;
    o->m38 -= n;
    *pcount -= n;
    *pdst += n * 4;
    return n;
}

extern "C" void fn_803B31B4(Unk803B31B4* o, int v)
{
    o->m24 = v * 0.000244140625f;
}

extern "C" void fn_803B3334(Unk803B3334* o)
{
    if (o->m1828 != 0) {
        SNDMEMI_free(o->m1828);
        o->m1828 = 0;
        o->m182C = 0;
    }
}

extern "C" int fn_803B3378(Unk803B3334* o, unsigned char* p, int v)
{
    o->m0 = (void*)fn_803B31F4;
    o->m4 = (void*)fn_803B3334;
    if (v >= 0)
        o->m20 = fn_803B4BEC(fn_803B02CC(v));
    else
        o->m20 = -1;
    o->m1C = p + 6;
    o->m24 = 1.0f;
    o->m28 = 0.0f;
    o->m2C = p[1] * 2;
    o->m30 = fn_803B3F60(p + 2, 4);
    o->m1830 = 0xabc;
    o->m34 = 0;
    o->m38 = 0;
    o->m3C = 0;
    o->m1828 = 0;
    o->m182C = 0;
    return 0;
}

extern "C" void fn_803B343C(int n, short* src, float* dst)
{
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

extern "C" void fn_803B3494(float* out, float a, float b, float c)
{
    float bk = b * 0.0174532942f;
    float x = a * 0.0174532942f - bk;
    float y = c * 0.0174532942f - bk;
    y = y / x;
    y = y * 1.5707964f;
    out[0] = fn_803B457C(y);
    out[1] = fn_803B44E4(y);
}

extern "C" void fn_803B3908(unsigned int idx, float* out)
{
    int i;
    idx = (idx >> 8) & 0xff;
    for (i = 0; i < sndgs.sso.set.outputchannels; i++)
        out[i] = (unsigned int)lbl_806AA4E8[i][idx] / 255.0f;
    if (lbl_8069CBC0 == 3)
        out[5] = 0.0f;
}

extern "C" void fn_803B39A4()
{
    fn_803A975C();
    if (lbl_806AA4E8 != 0)
        SNDMEMI_free(lbl_806AA4E4);
    fn_803A979C();
}

extern "C" int fn_803B3B98(int a)
{
    int s = 0x1000;
    while (a > 0x4af) {
        a -= 0x4b0;
        s <<= 1;
    }
    while (a <= -0x4b0) {
        a += 0x4b0;
        s >>= 1;
    }
    int idx = (a * 0x369d) >> 16;
    if (idx < -0xff)
        idx = -0xff;
    if (idx < 0)
        s = (s * (lbl_806262F4[idx + 0x100] + 0x100)) >> 9;
    else
        s = (s * (lbl_806262F4[idx] + 0x100)) >> 8;
    return s;
}

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
