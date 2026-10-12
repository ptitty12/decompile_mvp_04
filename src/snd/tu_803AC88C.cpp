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

extern "C" void fn_803B9E08(DtorAt0* s, int chrg);

extern void (*lbl_8062520C)(DtorAt0*, int);
extern void (*lbl_80625210)(DtorAt0*, int);

extern "C" void fn_803AC88C();

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

extern "C" unsigned int OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(unsigned int);
extern "C" void fn_80417B10(void* p);
extern "C" void fn_804176B0(void* p);
/* near-miss: 70 vs 72 insns: retail keeps the table slot in r5 (the fn_803AEA78 result, or the idx argument copied there) and the aligned size in r8/r11 across both arms; ours keeps the argument registers in different saved registers (stmw r25 vs r26); slot-variable and record-pointer forms tried */
extern "C" int fn_803AEB50(int a, int b, int c, int d, int e);

struct Unk8069E200_RecA {
    char pad0[0x18];
    int m18;
    char pad1C[3];
    unsigned char m1F;
    char pad20[4];
    unsigned char m24;
    unsigned char m25;
    char pad26[0x16];
    void* m3C;
};

struct Unk8069E200_RecB {
    int m0;
    int m4;
    char pad8[0x1C];
    int m24;
    int m28;
    int m2C;
    int m30;
    unsigned int m34;
    char pad38[8];
};

struct Unk8069E200 {
    Unk8069E200_RecA recA[0x30];
    char padC00[0x1410 - 0xC00];
    void* mVoices[16];
    char pad1450[0x9DE8 - 0x1450];
    int m9DE8;
    int m9DEC;
    char pad9DF0[0x9E30 - 0x9DF0];
    Unk8069E200_RecB recB[64];
    char padAE30[0xC048 - 0xAE30];
    unsigned char mC048;
    unsigned char mC049;
    char padC04A[6];
    void* mBufs[6];
    unsigned int mAligned[6];
};
extern Unk8069E200 lbl_8069E200;

extern "C" void fn_803B14D0();
extern "C" void fn_803B5ACC();
extern "C" int fn_8041818C(int a, int b);
extern "C" void fn_80437D18(void* p);
extern "C" void fn_80417808();
extern "C" void fn_803A979C();
extern "C" void fn_803A975C();
extern "C" void fn_803AEF88();
extern char lbl_8069FCC8[];

struct Unk803AEE98 {
    unsigned int w0;
    void (*fn)(int);
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
};
extern void (*lbl_806AA4C8)(Unk803AEE98*);
extern void (*lbl_806AA4CC)();

extern "C" int fn_80415A70();

extern "C" void fn_803AE964(int v, int k);
extern unsigned short lbl_80625468[][4];

struct Unk803AE618 {
    char pad0[0x14];
    int m14;
};

extern "C" void fn_803AE0E0(Unk803AE0E0* p);

extern "C" void fn_80417554(void* p, int t, int z, int a, int b, int c, int aligned, void (*cb)(Unk8069E200_RecB*));

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

extern "C" void fn_803AC924(DtorAt0* s, int chrg)
{
    fn_803B9E08(s, chrg);
}

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

extern "C" void fn_803ADD4C(Unk803AE0E0* o, float* in, unsigned int v, int flag)
{
    Unk803ADD08* e = &lbl_8069CBC4[o->m18];
    if (lbl_8069E1C4 == 4) {
        unsigned int idx = v >> 8;
        if (flag == 0) {
            e->m3A = lbl_80625468[idx][1];
            e->m52 = lbl_80625468[idx][3];
            e->m4E = lbl_80625468[idx][2];
            e->m36 = lbl_80625468[idx][0];
        } else {
            e->m36 = 0;
            e->m4E = 0;
            e->m52 = 0;
            e->m3A = 0;
        }
    } else {
        e->m3A = (short)(in[0] * 32767.0f);
        e->m36 = (short)(in[1] * 32767.0f);
    }
    e->m4 |= 0x40000000;
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

extern "C" void fn_803AE550()
{
    int i;
    if (lbl_8069E200.mC049 != 0) {
        for (i = 0; i <= 0x2f; i++) {
            if (lbl_8069E200.recA[i].m1F != 0) {
                fn_80417B10(lbl_8069E200.recA[i].m3C);
                lbl_8069E200.recA[i].m1F = 0;
                lbl_8069E200.mC049--;
                lbl_8069E200.recA[i].m3C = 0;
                if (lbl_8069E200.mC049 == 0)
                    break;
            }
        }
    }
}

extern "C" void fn_803AE5EC(int v)
{
    SNDVOICEI_free(v + sndgs.sso.set.voicesdsp);
}

/* near-miss: 53 vs 54 insns: retail loads o->m14 into r11 before the chan base (lbl_8069CA48 in r10) and keeps both live for the second chan index; ours loads m14 into r0 and rebuilds the base */
extern "C" void fn_803AE618(Unk803AE618* o)
{
    int idx = o->m14;
    CHANPUB* c = &sndgs.chan[idx];
    int m = c->masterchan;
    int base = m;
    if (m == -1)
        base = idx;
    CHANPUB* mc = &sndgs.chan[base];
    int i;
    for (i = 0; i < mc->numchan; i++) {
        int v = mc->voices[i];
        if (lbl_8069E200.recA[v].m3C != 0) {
            if (v == o->m14)
                fn_803AE964(v, 1);
            else
                fn_803AE964(v, 2);
            lbl_8069E200.recA[mc->voices[i]].m24 = 0;
        }
    }
}

extern CHANPUB* lbl_8069CA48; /* sndgs.chan (sndgs + 0x1CC), named by its own symbols.txt entry */

extern "C" void fn_803AE964(int v, int mode)
{
    Unk8069E200_RecA* r = &lbl_8069E200.recA[v];
    CHANPUB* c = &lbl_8069CA48[v];
    void* p = r->m3C;
    fn_803AE0E0((Unk803AE0E0*)p);
    r->m18 = -1;
    if (c->status != 0)
        SNDVOICEI_free(v);
    if (mode == 0) {
        if (p != 0) {
            fn_80417B10(p);
            r->m3C = 0;
        }
    } else if (mode == 2) {
        /* the signed read keeps the compiler from threading this exit past the m25 retest below */
        if ((signed char)r->m25 == 0 && p != 0) {
            r->m1F = 1;
            lbl_8069E200.mC049++;
        }
    } else if (mode == 1) {
        if (r->m1F == 1) {
            r->m1F = 0;
            lbl_8069E200.mC049--;
        }
        r->m3C = 0;
    }
    if (r->m25 == 0)
        r->m25 = 1;
}

extern "C" int fn_803AEA78(int v)
{
    int i = 0;
    unsigned int en = OSDisableInterrupts();
    while (i < 64 && lbl_8069E200.recB[i].m0 != -1)
        i++;
    lbl_8069E200.recB[i].m0 = v;
    OSRestoreInterrupts(en);
    return i;
}

extern "C" void fn_803AEB04(Unk8069E200_RecB* r)
{
    int i;
    lbl_8069E200.m9DE8 = r->m4;
    for (i = 0; i <= 63; i++) {
        if (lbl_8069E200.recB[i].m0 == r->m4) {
            lbl_8069E200.recB[i].m0 = -1;
            return;
        }
    }
}

extern "C" int fn_803AEB50(int a, int b, int c, int d, int idx)
{
    unsigned int en = OSDisableInterrupts();
    int t;
    int aligned;
    int slot;
    if (idx == -1) {
        slot = fn_803AEA78(lbl_8069E200.m9DEC);
        t = lbl_8069E200.m9DEC;
        lbl_8069E200.recB[slot].m24 = a;
        lbl_8069E200.recB[slot].m28 = b;
        lbl_8069E200.recB[slot].m2C = c;
        aligned = d + 0x1f;
        lbl_8069E200.recB[slot].m30 = aligned & ~0x1f;
        lbl_8069E200.recB[slot].m34 = sndgs.audiotick;
    } else {
        slot = idx;
        aligned = d + 0x1f;
        t = lbl_8069E200.recB[slot].m0;
    }
    fn_80417554(&lbl_8069E200.recB[slot].m4, t, 0, a, b, c, aligned & ~0x1f, fn_803AEB04);
    OSRestoreInterrupts(en);
    return lbl_8069E200.m9DEC++;
}

extern "C" void fn_803AEC70(int id)
{
    int i;
    unsigned int en = OSDisableInterrupts();
    for (i = 0; i <= 63; i++) {
        if (lbl_8069E200.recB[i].m0 == id) {
            fn_804176B0(&lbl_8069E200.recB[i].m4);
            fn_803AEB50(lbl_8069E200.recB[i].m24, lbl_8069E200.recB[i].m28, lbl_8069E200.recB[i].m2C, lbl_8069E200.recB[i].m30, i);
        }
    }
    OSRestoreInterrupts(en);
}

extern "C" void fn_803AEE98()
{
    Unk803AEE98 b;
    int i;
    fn_803B14D0();
    b.m10 = sndgs.sso.set.voicesmaincpu;
    if (sndgs.sso.set.outputchannels != 1)
        b.m11 = sndgs.sso.set.outputchannels;
    else
        b.m11 = 2;
    b.w0 = sndgs.sso.set.outputrate;
    b.fn = fn_803AE5EC;
    b.m12 = 0;
    lbl_806AA4C8(&b);
    fn_803A975C();
    for (i = 0; i < b.m11; i++) {
        void* p = SNDMEMI_allocz(0x2a0);
        lbl_8069E200.mBufs[i] = p;
        lbl_8069E200.mAligned[i] = ((unsigned int)p + 0x1f) & ~0x1f;
    }
    fn_803A979C();
    lbl_8069E200.mC048 = 1;
}

extern "C" void fn_803AEF88()
{
    int i;
    lbl_8069E200.mC048 = 0;
    fn_803A975C();
    for (i = 0; i < sndgs.sso.set.outputchannels; i++)
        SNDMEMI_free(lbl_8069E200.mBufs[i]);
    fn_803A979C();
    lbl_806AA4CC();
}

extern "C" int fn_803AF374()
{
    sndgs.sso.cap.voicesmaincpumax = 0x20;
    sndgs.sso.cap.voicesdspmax = 0x30;
    sndgs.sso.cap.outputratemax = 0x7d00;
    sndgs.sso.cap.outputchannelsmin = 1;
    sndgs.sso.set.outputspdifmode = 1;
    sndgs.sso.cap.outputratemin = 0x7d00;
    sndgs.sso.cap.numrendermodes = 2;
    sndgs.sso.cap.rendermode[0] = 0x220;
    sndgs.sso.cap.rendermode[1] = 0x24;
    sndgs.sso.set.rendermode[0] = 0x220;
    sndgs.sso.cap.outputchannelsmax = 4;
    sndgs.sso.set.rendermode[1] = 0x24;
    sndgs.sso.set.voicesdsp = 0x30;
    sndgs.sso.set.numrendermodes = 2;
    sndgs.sso.set.voicesmaincpu = 8;
    sndgs.sso.set.maxstreams = 8;
    sndgs.sso.set.outputrate = 0x7d00;
    sndgs.sso.set.outputchannels = 2;
    sndgs.sso.set.initaram = 1;
    int a = fn_80415A70() + 0x100;
    sndgs.sso.set.arampooladdr = a;
    sndgs.sso.set.arampoolsize = 0x800000 - a;
    return 0;
}

extern "C" int fn_803AF934()
{
    fn_8041818C(0, 0);
    if (lbl_8069E200.mC048 != 0)
        fn_803AEF88();
    fn_803B5ACC();
    if (sndgs.incritical != 0) {
        do {
            fn_803A979C();
        } while (sndgs.incritical != 0);
    }
    fn_80437D18(lbl_8069FCC8);
    fn_80417808();
    return 0;
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
