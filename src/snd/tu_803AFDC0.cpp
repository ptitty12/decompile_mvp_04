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
