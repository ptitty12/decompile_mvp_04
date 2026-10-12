/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803AC88C-0x803AFDC0 (code-only unit, 43 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

#include "snd/cmn/sndcmn.h"

struct DtorAt0 { const void* m; };

extern "C" void fn_803B9DDC(DtorAt0* s, int chrg);

extern unsigned char lbl_80625454;
extern void (*lbl_8069C93C)();
extern int lbl_80625460;
extern "C" void fn_80400C1C(int (*fn)(), int a, int b);
extern "C" void fn_80400690(int (*fn)());
extern "C" int fn_803B3E88();

extern "C" void fn_803AC88C()
{
    if (sndgs.installed) {
        int i;
        for (i = 0; i < sndgs.numserverclients; i++)
            sndgs.serverclient[i]();
    }
}

extern "C" void fn_803AC904(DtorAt0* s, int chrg)
{
    fn_803B9DDC(s, chrg);
}

extern "C" void fn_803B9E08(DtorAt0* s, int chrg);

extern "C" void fn_803AC924(DtorAt0* s, int chrg)
{
    fn_803B9E08(s, chrg);
}

extern void (*lbl_8062520C)(DtorAt0*, int);
extern void (*lbl_80625210)(DtorAt0*, int);

extern "C" int fn_803AC944()
{
    if (lbl_8062520C == fn_803AC904)
        return 0;
    lbl_8062520C = fn_803AC904;
    lbl_80625210 = fn_803AC924;
    return 0;
}

extern "C" unsigned char fn_803AC980()
{
    int i;
again:
    lbl_80625454++;
    if (lbl_80625454 == 0)
        lbl_80625454++;
    for (i = 0; i < sndgs.voicestotal; i++) {
        CHANPUB* c = &sndgs.chan[i];
        if (c->status != 0 && c->patchkey == lbl_80625454)
            goto again;
    }
    return lbl_80625454;
}

extern "C" int fn_803AD258(int shandle, int v)
{
    int setvoice;
    if (v > 0x2000)
        v = 0x2000;
    else if (v < 0x800)
        v = 0x800;
    int voice = SNDVOICEI_get(shandle);
    if (voice >= 0) {
        setvoice = -1;
        while (iSNDpatchkey(voice, &setvoice)) {
            sndgs.chan[setvoice].timemult = v;
            SNDPLATFORM_timemult(setvoice, v);
        }
    }
    return 0;
}

extern "C" void fn_803AC88C();

extern "C" int fn_803AD994()
{
    fn_803AC88C();
    return 0;
}

extern "C" void fn_803AD9B8()
{
}

extern "C" int fn_803AD9BC()
{
    lbl_8069C93C = (void (*)())fn_803AD9B8;
    if (lbl_80625460 == 0) {
        fn_80400C1C(fn_803AD994, 0, 1);
        lbl_80625460 = 1;
    }
    fn_80400690(fn_803B3E88);
    return 0;
}

struct Unk803ADD08 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    char pad1C[0x14];
    short m30;
    short m32;
    short m34;
    short m36;
    short m38;
    short m3A;
    short m3C;
    short m3E;
    short m40;
    short m42;
    short m44;
    short m46;
    short m48;
    short m4A;
    short m4C;
    short m4E;
    short m50;
    short m52;
    short m54;
    short m56;
};
extern Unk803ADD08 lbl_8069CBC4[64];

struct Unk803AE0E0 {
    char pad[0x18];
    int m18;
};
extern int lbl_8069E1C4;

extern "C" void fn_803ADD08(Unk803ADD08* p)
{
    p->m4 = 0x50000000;
    p->m8 = 0;
    p->mC = 0;
    p->m10 = 0;
    p->m54 = 0;
    p->m50 = 0;
    p->m4C = 0;
    p->m48 = 0;
    p->m44 = 0;
    p->m40 = 0;
    p->m3C = 0;
    p->m38 = 0;
    p->m34 = 0;
    p->m30 = 0;
}

extern "C" void fn_803ADE24(Unk803AE0E0* p, short v, int kind)
{
    Unk803ADD08* e = &lbl_8069CBC4[p->m18];
    if (kind == 1) {
        e->m46 = v;
        e->m42 = v;
        if (lbl_8069E1C4 == 4) {
            e->m4A = v;
            e->m56 = v;
        }
    } else if (kind == 2) {
        e->m52 = v;
        e->m4E = v;
        if (lbl_8069E1C4 == 3)
            e->m56 = v;
    }
    e->m4 |= 0x40000000;
}

extern "C" void fn_803ADE98(int v)
{
    int i;
    for (i = 0; i < 64; i++)
        fn_803ADD08(&lbl_8069CBC4[i]);
    lbl_8069E1C4 = v;
}

extern "C" void fn_803AE0E0(Unk803AE0E0* p)
{
    lbl_8069CBC4[p->m18].m0 = 0;
}

extern "C" void fn_803AE0FC(Unk803AE0E0* p, int v)
{
    Unk803ADD08* e = &lbl_8069CBC4[p->m18];
    int t = e->m4;
    e->m8 = v;
    e->m4 = t | 0x10000000;
}

extern "C" void fn_803AE5EC(int v)
{
    SNDVOICEI_free(v + sndgs.sso.set.voicesdsp);
}

extern "C" void fn_803AFD44(int flags, int* a, int* b)
{
    if (flags & 0x200) {
        *a = 0;
        *b = sndgs.sso.set.voicesdsp;
    } else if (flags & 4) {
        *a = sndgs.sso.set.voicesdsp;
        *b = sndgs.voicestotal;
    }
}

extern "C" int fn_803AFD88(SNDIPATCHHEADER* pph, int base, int* poff)
{
    if (*poff == 0)
        *poff = pph->sampleoffset[0];
    *pph->paudioramaddr = base + (pph->sampleoffset[0] - *poff);
    return 0;
}
