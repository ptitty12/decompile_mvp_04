/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803AFDC0-0x803B21AC (code-only unit, 42 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

#include "snd/cmn/sndcmn.h"

extern "C" void fn_80435CE8(void* p);

extern char lbl_806AA030[];

extern "C" void fn_803B5D30(int a);
extern "C" void* fn_803B5B6C(int a);
extern "C" void fn_80432FD4(int a, int b);
extern "C" void fn_803AEB50(int a, int b, int c, int d, int e);
extern int* lbl_806AA2C4;

static inline CHANPUB* ChanAt(CHANPUB* a, int i) { return &a[i]; }

extern "C" int fn_803B02CC(int v)
{
    int idx = v + sndgs.sso.set.voicesdsp;
    int m = ChanAt(sndgs.chan, idx)->masterchan;
    if (m == -1)
        return idx;
    return m;
}

/* near-miss: one register: retail keeps masterchan in r0 (lha r0), we use r9; lha/short/inline-index variants tried */
extern "C" int fn_803B02FC(int v)
{
    int idx = v + sndgs.sso.set.voicesdsp;
    int m = ChanAt(sndgs.chan, idx)->masterchan;
    if (m == -1)
        return 0;
    CHANPUB* mc = ChanAt(sndgs.chan, m);
    int i;
    for (i = 1; i <= 5; i++) {
        if (mc->voices[i] == idx)
            return i;
    }
    return 0;
}

extern "C" int fn_803B0360()
{
    return 0x25e4;
}

extern "C" int fn_803B270C(int voice, int ch, int v);
extern "C" int fn_803B115C(int a, int p);

struct Unk803B0714 {
    char pad[0x259C];
    int m259C[6];
};

struct Unk8069E200 {
    char pad[0x1410];
    Unk803B0714* mVoices[16];
};
extern Unk8069E200 lbl_8069E200;

extern "C" int fn_803B0714(int idx)
{
    Unk803B0714* p = lbl_8069E200.mVoices[idx];
    fn_803B115C(0, p->m259C[0]);
    int i;
    for (i = 0; i <= 5; i++)
        p->m259C[i] = 0;
    lbl_8069E200.mVoices[idx] = 0;
    return 0;
}

extern "C" int fn_803B0798()
{
    return -15;
}

void Snd::Hal::SetDry(int voice)
{
    CHANPUB* c = (CHANPUB*)((char*)sndgs.chan + voice * 0x90);
    if (*(unsigned int*)&c->rendermode & 0x2040000)
        SetVol(voice);
}

extern "C" int fn_803B1080(int voice, int v)
{
    CHANPUB* c = &sndgs.chan[voice];
    if (c->rendermode & 4) {
        int i;
        for (i = 0; i < c->numchan; i++)
            fn_803B270C(c->voices[i] - sndgs.sso.set.voicesdsp, i, v);
        return 0;
    }
    return -7;
}

extern "C" void* fn_803B1118(int unused, int size)
{
    size = (size + 0x1f) & ~0x1f;
    if (sndgs.sso.vec.aramalloc != 0)
        return (void*)sndgs.sso.vec.aramalloc(size);
    return fn_803B5B6C(size);
}

extern "C" int fn_803B115C(int unused, int p)
{
    if (sndgs.sso.vec.aramfree == 0)
        fn_803B5D30(p);
    else
        sndgs.sso.vec.aramfree(p);
    return 0;
}

extern "C" void fn_803B11A8(int unused, int a, int b, int c)
{
    fn_80432FD4(a, c);
    fn_803AEB50(0, a, b, c, -1);
}

extern "C" void fn_803B12A4()
{
    fn_80435CE8(lbl_806AA030);
}

extern "C" void fn_803B12CC()
{
}

extern "C" void fn_80435D20(void* p);

extern "C" void fn_803B12D0()
{
    fn_80435D20(lbl_806AA030);
}

extern "C" void fn_80435DFC(void* p);

extern "C" void fn_803B12F8()
{
    fn_80435DFC(lbl_806AA030);
}

extern "C" int fn_803B1320(SNDSYSOPTS* p, int kind)
{
    switch (kind) {
    case 0:
        p->set.outputchannels = 1;
        break;
    case 1:
        p->set.outputchannels = 2;
        break;
    case 8:
        p->set.outputchannels = 4;
        break;
    }
    return 0;
}

extern "C" int fn_803B1364(int i)
{
    return lbl_806AA2C4[i];
}

extern "C" void fn_803B1B30();
extern "C" void fn_803B1DF0();
extern "C" void fn_803B2354();
extern "C" void fn_803B1EF4();
extern "C" void fn_803B2108();
extern "C" void fn_803B21EC();
extern "C" void fn_803B29F8();
extern void* lbl_806AA4C8;
extern void* lbl_806AA4CC;
extern void* lbl_806AA4D0;
extern void* lbl_806AA4D4;
extern void* lbl_806AA4D8;
extern void* lbl_806AA4DC;
extern void* lbl_806AA4E0;

extern "C" void fn_803B14D0()
{
    lbl_806AA4C8 = (void*)fn_803B1B30;
    lbl_806AA4CC = (void*)fn_803B1DF0;
    lbl_806AA4D0 = (void*)fn_803B2354;
    lbl_806AA4D4 = (void*)fn_803B1EF4;
    lbl_806AA4D8 = (void*)fn_803B2108;
    lbl_806AA4DC = (void*)fn_803B21EC;
    lbl_806AA4E0 = (void*)fn_803B29F8;
}

extern "C" void fn_803B18BC()
{
}

extern "C" void* fn_803B1AF0(int n)
{
    return SNDMEMI_allocz(n);
}

extern "C" void fn_803B1B10(void* p)
{
    SNDMEMI_free(p);
}

extern "C" void fn_803B6AF8();
extern "C" void fn_803B343C();

struct Unk806AA2D4B {
    char pad0[0xC];
    short mC;
    char padE[0x1D2];
    void* m1E0;
    void* m1E4;
};
extern Unk806AA2D4B lbl_806AA2D4;

extern "C" void fn_803B1EC8()
{
    lbl_806AA2D4.m1E0 = (void*)fn_803B6AF8;
    lbl_806AA2D4.m1E4 = (void*)fn_803B343C;
    lbl_806AA2D4.mC = 0x140;
}
