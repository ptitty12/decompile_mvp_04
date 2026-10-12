/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B4BEC-0x803B6AF8 (code-only unit, 46 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/cmn/sndcmn.h"

extern SNDPACKETSTATE lbl_806AA500;

struct Unk806AA88C {
    short m0;
    short m2;
    unsigned int m4;
    unsigned int m8;
    void* mC;
};
extern Unk806AA88C lbl_806AA88C;
extern int lbl_806AA884;
extern int lbl_806AA888;
extern int lbl_80626518;
extern float lbl_80609B98;

extern "C" void fn_803A975C();
extern "C" void fn_803A979C();
extern "C" int fn_803B0360();
extern "C" void fn_803B0714(int h);

extern "C" int fn_803B4BEC(int voice)
{
    int i;
    for (i = 0; i < sndgs.sso.set.maxstreams; i++) {
        SNDPACKETCHAN* p = lbl_806AA500.ppc[i];
        if (p != 0 && SNDVOICEI_get(p->shandle) == voice)
            return i;
    }
    return -1;
}

extern "C" int fn_803B4C74(int chan, int n)
{
    int i;
    int best = -1;
    int idx = -1;
    for (i = 0; i < n; i++) {
        int v = sndgs.chan[chan].voices[i];
        if (v > best) {
            best = v;
            idx = i;
        }
    }
    return idx;
}

extern "C" int fn_803B4CC8(int n)
{
    return (n << 5) + 0x9c;
}

extern "C" int fn_803B4CD4(int n)
{
    int a = fn_803B4CC8(n);
    return a + fn_803B0360();
}

extern "C" int fn_803B537C(int h)
{
    SNDPACKETCHAN* p = lbl_806AA500.ppc[h];
    int max = 0;
    int i;
    for (i = 0; i < p->sampleformat.channels; i++) {
        if (p->outstandingpackets[i] >= max)
            max = p->outstandingpackets[i];
    }
    return p->maxpackets - max - 1;
}

extern "C" unsigned int fn_803B53DC(int h)
{
    SNDPACKETCHAN* p = lbl_806AA500.ppc[h];
    return p->outstandingframes + p->outstandingplatformframes;
}

extern "C" int fn_803B5400()
{
    return -15;
}

extern "C" int fn_803B54A8(int h)
{
    fn_803A975C();
    fn_803B0714(h);
    lbl_806AA500.ppc[h] = 0;
    fn_803A979C();
    return 0;
}

extern "C" void fn_803B5738(int h, int chan, int frames)
{
    SNDPACKETCHAN* p = lbl_806AA500.ppc[h];
    if (chan != p->masterpacketchan)
        return;
    p->outstandingplatformframes -= frames;
    if (p->pframesfunc == 0)
        return;
    SNDIPACKETCALLBACK* e = lbl_806AA500.spcb + lbl_806AA500.callbackindex;
    e->type = 0;
    e->chan = h;
    e->u.frames = frames;
    lbl_806AA500.callbackindex++;
}

extern "C" int fn_803B59A4(int range)
{
    if (range > 0x10000)
        range = 0x10000;
    else if (range < 0)
        range = 0;
    int r = (int)(iSNDrandom() & 0x7FFF) - 0x4000;
    return (r * range) >> 14;
}

extern "C" void fn_803B5A00(int v)
{
    lbl_806AA884 = v;
}

extern "C" void fn_803B5A0C(int v)
{
    lbl_806AA888 = v;
}

extern "C" int fn_803B5A18(int v)
{
    lbl_80626518 = v;
    return 0;
}

extern "C" void fn_803B5A28(int n)
{
    fn_803A975C();
    lbl_806AA88C.mC = SNDMEMI_allocz(n * 8);
    fn_803A979C();
    lbl_806AA88C.m2 = n;
    lbl_806AA88C.m0 = 0;
}

extern "C" void fn_803B5ACC()
{
    if (lbl_806AA88C.mC != 0) {
        fn_803A975C();
        SNDMEMI_free(lbl_806AA88C.mC);
        fn_803A979C();
        lbl_806AA88C.mC = 0;
    }
}

extern "C" void fn_803B6428(float* p)
{
    float z = lbl_80609B98;
    p[0] = z;
    p[1] = z;
    p[2] = z;
    p[3] = z;
    p[4] = z;
    p[5] = z;
    p[6] = z;
    p[7] = z;
}

struct Unk803B66CC {
    char pad[0x1C];
    int m1C;
};

extern "C" void fn_803B66CC(Unk803B66CC* p, int v)
{
    p->m1C = v;
}
