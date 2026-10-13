/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B21AC-0x803B3D60 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/cmn/sndcmn.h"
#include <string.h>

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
    Unk803B27DC_Obj* m50;
    Unk803B27DC_Obj* m54;
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
extern "C" void fn_803B65BC(void* obj);
extern "C" void fn_803B65FC(void* obj, int* buf);
extern unsigned short lbl_8069C8A2;
extern "C" void fn_803B6004(Unk803B21EC_Node** head, void* node);
extern "C" void fn_803B5EC4(void* obj);
extern "C" void fn_803B5F18(void* obj, int* buf);
extern "C" void fn_803B31B4(Unk803B31B4* obj, int v);

struct Unk803B3334;
struct Unk803B3334_Src {
    int (*fn)(Unk803B3334_Src* self, int a, float* b, float* c, int d);
};

struct Unk803B3334 {
    void* m0;
    void* m4;
    Unk803B3334_Src* m8;
    char padC[0xE];
    unsigned char m1A;
    char pad1B;
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
extern "C" int fn_803B2C0C(int n, unsigned char** pp, float* ps, float x);
extern "C" int fn_803B31F4(Unk803B3334* o, int count, float* src, float* dst);
extern "C" int fn_803B2F48(Unk803B3334* o, int count);
extern "C" int fn_803B306C(Unk803B3334* o, int count, float* src, float* dst);
extern "C" void fn_803B3334(Unk803B3334* o);
extern int lbl_8069CBC0;

extern "C" void fn_803B1080(int voice, int v);

extern "C" void fn_803B69AC(Unk803B27DC_Obj* o, int a, int flag);
extern "C" void fn_803B66CC(Unk803B27DC_Obj* o, int v);
extern unsigned char lbl_8069C9EB;

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

extern "C" void fn_803B28AC(int idx, float v)
{
    Unk803B21EC* e = &lbl_806AA4B0[idx];
    if (v < 1.0f) {
        if (e->m54 == 0) {
            Unk803B27DC_Obj* o = (Unk803B27DC_Obj*)SNDMEMI_allocz(0x28);
            e->m54 = o;
            o->m4 = 0;
            e->m54->m18 = 0x28;
            e->m54->m1A = 0;
            fn_803B65BC(e->m54);
            fn_803B5F9C(&e->m40, e->m54);
        }
        int buf[3];
        float t;
        buf[1] = lbl_8069C8A2 << 8;
        t = v * (float)(int)lbl_8069C8A2;
        int r = (int)(t >= 0.0f ? t + 0.5f : t - 0.5f);
        buf[0] = r << 7;
        buf[2] = 0x100;
        fn_803B65FC(e->m54, buf);
    } else if (e->m54 != 0) {
        fn_803B6004(&e->m40, e->m54);
        SNDMEMI_free(e->m54);
        e->m54 = 0;
    }
}

extern "C" void fn_803B29F8(int idx, int v)
{
    Unk803B21EC* e = &lbl_806AA2D4.m1DC[idx];
    int big = 0;
    if (v > 0x40000)
        v = 0x40000;
    Unk803B27DC_Obj* old = e->m50;
    if (old == 0) {
        Unk803B27DC_Obj* o = (Unk803B27DC_Obj*)SNDMEMI_allocz(0x3c);
        e->m50 = o;
        if (lbl_806AA2D4.mE > 0x31)
            big = 1;
        o->m4 = 0;
        e->m50->m18 = 0xa0;
        e->m50->m1A = 0;
        fn_803B69AC(e->m50, lbl_8069C9EB, big);
        fn_803B5F9C(&e->m40, e->m50);
    }
    fn_803B66CC(e->m50, v);
}

extern "C" void fn_803B2AB4(int idx, int v)
{
    Unk803B21EC* e = &lbl_806AA4B0[idx];
    if (e->m4C != 0)
        fn_803B31B4(e->m4C, v);
}

extern "C" void fn_803B2AF0(float* a, float* b, float* out, int n, int shift)
{
    int off;
    float step, start;
    if (shift > 0) {
        off = shift;
        step = -1.0f / (float)n;
        start = 1.0f;
    } else {
        off = -shift;
        step = 1.0f / (float)n;
        start = 0.0f;
    }
    int i;
    for (i = off; i < n; i++) {
        out[i - off] = start * a[i] + (1.0f - start) * a[i - off];
        start += step;
    }
    for (i = 0; i < off; i++) {
        out[n - off + i] = start * b[i] + (1.0f - start) * a[n - off + i];
        start += step;
    }
}

extern "C" void fn_803B2D58(Unk803B3334* o, float** pp, int shift)
{
    float* a;
    float* b;
    if (o->m34 > 0) {
        a = (float*)((char*)o + 0x40);
        b = *pp;
    } else {
        a = *pp;
        b = a + o->m2C;
    }
    if (shift == 0) {
        Snd::Util::MemCpy((char*)o + 0x838, a, o->m2C * 4);
        o->m30 = o->m30 - o->m2C;
        o->m38 = o->m2C;
        *pp = b;
    } else if (shift > 0) {
        int n = shift * 4;
        Snd::Util::MemCpy((char*)o + 0x838, a, n);
        fn_803B2AF0(a, b, (float*)((char*)o + (n + 0x838)), o->m2C, shift);
        o->m30 = o->m30 - o->m2C;
        o->m38 = o->m2C + shift;
        *pp = b;
    } else {
        fn_803B2AF0(a, b, (float*)((char*)o + 0x838), o->m2C, shift);
        Snd::Util::MemCpy((char*)o + (o->m2C * 4 + 0x838), b - shift, (o->m2C + shift) * 4);
        o->m30 = o->m30 - o->m2C * 2;
        o->m38 = o->m2C * 2 + shift;
        *pp = b + o->m2C;
    }
    o->m34 = 0;
    o->m3C = 0;
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

extern "C" int fn_803B2F48(Unk803B3334* o, int count)
{
    if (count > o->m38) {
        int total = 0;
        int last = 0;
        unsigned char* sp8 = o->m1C;
        float spC = o->m28;
        int avail;
        count -= o->m38;
        avail = o->m30;
        if (count > 0 && avail >= o->m2C) do {
            int used;
            int got;
            if (avail < o->m2C * 2)
                last = 0;
            else
                last = fn_803B2C0C(o->m2C, &sp8, &spC, o->m24);
            if (last >= 0) {
                used = o->m2C;
                got = used + last;
            } else {
                used = o->m2C * 2;
                got = used + last;
            }
            total += used;
            avail -= used;
            if (count <= got)
                count = 0;
            else
                count -= got;
            if (count <= 0) break;
        } while (avail >= o->m2C);
        if (last > 0)
            total += o->m2C;
        if (count > 0) {
            if (count > avail)
                total += avail;
            else
                total += count;
        }
        if (total > o->m34)
            return total - o->m34;
    }
    return 0;
}

/* the loop test reads m30 through an accessor (retail copies the loaded value) */
static inline int A30(Unk803B3334* o) { return o->m30; }
extern "C" int fn_803B306C(Unk803B3334* o, int count, float* src, float* dst)
{
    int sp8 = count;
    float* sp10 = src;
    char* spC = (char*)dst;
    int total = fn_803B2EAC(o, &sp8, &spC);
    if (sp8 == 0)
        return total;
    int last = 0;
    while (sp8 > 0 && A30(o) >= o->m2C) {
        if (o->m30 < o->m2C * 2)
            last = 0;
        else
            last = fn_803B2C0C(o->m2C, &o->m1C, &o->m28, o->m24);
        fn_803B2D58(o, &sp10, last);
        total += fn_803B2EAC(o, &sp8, &spC);
    }
    if (last > 0) {
        Snd::Util::MemCpy((char*)o + 0x40, sp10, o->m2C * 4);
        o->m34 = o->m2C;
        sp10 += o->m2C;
    }
    if (sp8 > 0) {
        int n;
        if (sp8 > o->m30)
            n = o->m30;
        else
            n = sp8;
        total += n;
        Snd::Util::MemCpy(spC, sp10, n * 4);
        o->m30 -= n;
    }
    return total;
}

extern "C" void fn_803B31B4(Unk803B31B4* o, int v)
{
    o->m24 = v * 0.000244140625f;
}

extern "C" int fn_803B31F4(Unk803B3334* o, int count, float* src, float* dst)
{
    float* buf = src;
    int need;
    int r;
    if (o->m30 == 0)
        return o->m8->fn(o->m8, 0xC8, dst, buf, o->m1A);
    need = fn_803B2F48(o, count);
    if (o->m20 >= 0 && need > SNDPKTPLAY_framesoutstanding(o->m20))
        return 0;
    if (need > 0) {
        if (need * 4 > o->m1830) {
            int sz = need & ~0x3F;
            sz += 0x40;
            if (o->m182C < sz)
                Snd::Util::ReallocBuf(&o->m1828, &o->m182C, sz, 4);
            buf = (float*)((char*)o->m1828 + 8);
        }
        r = o->m8->fn(o->m8, need, dst, buf, o->m1A);
        if (r <= 0)
            return r;
    }
    r = fn_803B306C(o, count, buf, dst);
    if (r < count)
        memset(dst + r, 0, (count - r) * 4);
    return count;
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

extern unsigned char lbl_8069CBBC;
extern float lbl_8069CBA8[5];
/* 3D speaker angles per output layout (lbl_8069CBA8) and the source-channel angle table (srcchancfg3d). The stereo pair is stored in both arms, so jump2 merges the identical stores into the shared tail. */
extern "C" void fn_803B39E4()
{
    if (lbl_8069CBBC == 1) {
        lbl_8069CBC0 = 0;
        lbl_8069CBA8[0] = 0.0f;
    } else if (lbl_8069CBBC == 2) {
        lbl_8069CBC0 = 1;
        lbl_8069CBA8[0] = 90.0f;
        lbl_8069CBA8[1] = 270.0f;
    } else if (lbl_8069CBBC == 4) {
        lbl_8069CBC0 = 2;
        lbl_8069CBA8[0] = 45.0f;
        lbl_8069CBA8[1] = 135.0f;
        lbl_8069CBA8[2] = 225.0f;
        lbl_8069CBA8[3] = 315.0f;
    } else if (lbl_8069CBBC == 6) {
        lbl_8069CBC0 = 3;
        lbl_8069CBA8[0] = 0.0f;
        lbl_8069CBA8[1] = 45.0f;
        lbl_8069CBA8[2] = 135.0f;
        lbl_8069CBA8[3] = 225.0f;
        lbl_8069CBA8[4] = 315.0f;
    }
    if (sndgs.sso.set.outputchannels == 2) {
        sndgs.srcchancfg3d[1][0] = -0x4000;
        sndgs.srcchancfg3d[1][1] = 0x4000;
    } else {
        sndgs.srcchancfg3d[1][0] = -0x2000;
        sndgs.srcchancfg3d[1][1] = 0x2000;
    }
    sndgs.srcchancfg3d[3][0] = -0x2000;
    sndgs.srcchancfg3d[3][1] = 0x2000;
    sndgs.srcchancfg3d[3][2] = -0x6000;
    sndgs.srcchancfg3d[3][3] = 0x6000;
    sndgs.srcchancfg3d[4][0] = -0x2000;
    sndgs.srcchancfg3d[4][1] = 0;
    sndgs.srcchancfg3d[4][2] = 0x2000;
    sndgs.srcchancfg3d[4][3] = -0x6000;
    sndgs.srcchancfg3d[4][4] = 0x6000;
    sndgs.srcchancfg3d[5][1] = 0;
    sndgs.srcchancfg3d[2][0] = sndgs.sso.set.virtualspkrcfg3d[2][2];
    sndgs.srcchancfg3d[2][1] = sndgs.sso.set.virtualspkrcfg3d[2][0];
    sndgs.srcchancfg3d[2][2] = sndgs.sso.set.virtualspkrcfg3d[2][1];
    sndgs.srcchancfg3d[5][0] = -0x2000;
    sndgs.srcchancfg3d[5][2] = 0x2000;
    sndgs.srcchancfg3d[5][3] = -0x6000;
    sndgs.srcchancfg3d[5][4] = 0x6000;
    sndgs.srcchancfg3d[5][5] = 0;
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

extern CHANPUB* lbl_8069CA48; /* sndgs.chan (sndgs + 0x1CC), named by its own symbols.txt entry */

void iSNDcalcpitch(int chan)
{
    CHANPUB* c = &lbl_8069CA48[chan];
    if (c->detunepitch == 0) {
        int pitch = c->initialdetune;
        if (c->bendrange != 0) {
            signed char v;
            if (c->pbendtable != 0)
                v = ((signed char*)c->pbendtable)[c->pitchbend];
            else
                v = c->pitchbend;
            pitch += ((v - 0x40) * (short)c->bendrange) >> 6;
        }
        if (c->ppitchlfo != 0)
            pitch += ((((signed char*)c->ppitchlfo)[c->curpitchlfoentry] - 0x40) * c->pitchlfodepth) >> 6;
        c->detunepitch = fn_803B3B98(pitch);
    }
    c->finalpitch = (c->detunepitch * c->progpitch) >> 12;
}
