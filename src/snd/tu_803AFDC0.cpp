/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803AFDC0-0x803B21AC (code-only unit, 42 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

#include "snd/cmn/sndcmn.h"
#include <string.h>

extern "C" void fn_80435CE8(void* p);

extern char lbl_806AA030[];

extern "C" void fn_803B5D30(int a);
extern "C" void* fn_803B5B6C(int a);
extern "C" void fn_80432FD4(int a, int b);
extern "C" void fn_803AEB50(int a, int b, int c, int d, int e);
extern int* lbl_806AA2C4;

static inline CHANPUB* ChanAt(CHANPUB* a, int i) { return &a[i]; }

extern "C" int fn_803B270C(int voice, int ch, int v);
extern "C" int fn_803B115C(int a, int p);

struct Unk803B0714 {
    char pad[0x2580];
    int m2580[6];
    signed char m2598;
    char pad2599[3];
    int m259C[6];
};

struct Unk8069E200 {
    char pad[0x1410];
    Unk803B0714* mVoices[16];
};
extern Unk8069E200 lbl_8069E200;

extern "C" void fn_80435D20(void* p);

extern "C" void fn_80435DFC(void* p);

extern "C" void fn_803B1B30();
extern "C" void fn_803B1DF0();
extern "C" void fn_803B2354();
extern "C" void fn_803B1EF4();
/* near-miss: 41 insns, identical except scratch register choice for the early li 0 / lis constants (retail: li r11,0 right after the lwz; ours li r0,0 after the lfs); statement-order variants tried */
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

extern "C" void fn_803B6AF8();
extern "C" void fn_803B343C();

struct Unk806AA2D4B {
    char pad0[9];
    unsigned char m9;
    char padA[2];
    short mC;
    char padE[6];
    float* m14;
    char pad18[0xD0];
    float mE8[6];
    float* m100;
    char pad104[0xDC];
    void* m1E0;
    void* m1E4;
};
extern Unk806AA2D4B lbl_806AA2D4;

extern "C" void* fn_803B1118(int unused, int size);
extern "C" void fn_803AEC70(int id);
extern "C" unsigned int OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(unsigned int);
extern char lbl_806AE200[];

struct Unk803B11FC_Rec {
    int m0;
    char pad4[0x30];
    unsigned int m34;
    char pad38[8];
};

struct Unk803B1378_Node {
    Unk803B1378_Node* m0;
};
extern Unk803B1378_Node** lbl_806AA2C0;
extern int lbl_806262B0;
extern int lbl_80625448;

struct Unk803B21EC_L {
    unsigned char m0;
    unsigned char m1;
    char pad2[2];
    float m4[6];
    float m1C[6];
    float* m34;
    float* m38;
    float m3C;
    char pad40[0x1C];
};
extern Unk803B21EC_L* lbl_806AA4B0;
extern float lbl_8060984C;

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

extern "C" int fn_803B0368(int slot, Unk803B0714* p)
{
    memset(p, 0, 0x25e4);
    p->m259C[0] = (int)fn_803B1118(0, 0x4800);
    if (p->m259C[0] == 0)
        return -9;
    int i;
    for (i = 0; i <= 5; i++) {
        p->m259C[i] = p->m259C[0] + i * 0xC00;
        p->m2580[i] = ((int)p + i * 0x640 + 0x1f) & ~0x1f;
    }
    p->m2598 = -1;
    lbl_8069E200.mVoices[slot] = p;
    return 0;
}

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

extern "C" int fn_803B11FC(int id)
{
    unsigned int en = OSDisableInterrupts();
    int i;
    char* base = lbl_806AE200;
    char* ba = base - 0x61d0;
    char* bb = base - 0x619c;
    for (i = 0; i <= 63; i++) {
        int off = i << 6;
        if (*(volatile int*)(ba + off) != -1 && *(volatile int*)(ba + off) == id) {
            if (sndgs.audiotick - *(unsigned int*)(bb + off) > 200) {
                OSRestoreInterrupts(en);
                fn_803AEC70(id);
            } else {
                OSRestoreInterrupts(en);
            }
            return 0;
        }
    }
    OSRestoreInterrupts(en);
    return 1;
}

extern "C" void fn_803B12A4()
{
    fn_80435CE8(lbl_806AA030);
}

extern "C" void fn_803B12CC()
{
}

extern "C" void fn_803B12D0()
{
    fn_80435D20(lbl_806AA030);
}

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

/* near-miss: size expression (n+n+n)<<2 now matches; retail keeps only lbl_80625448 and lbl_806AA2C0 in saved registers (lbl_806AA2C4 is stored through a scratch lis) and does the m14/m100 stores before the memset; ours hoists lbl_806AA2C4 into r28 */
extern "C" void fn_803B1378()
{
    int n = lbl_80625448;
    int t = n + n + n;
    int size = t << 2;
    float* p = (float*)SNDMEMI_allocz(size);
    lbl_806AA2C4 = (int*)p;
    lbl_806AA2D4.m14 = p + lbl_80625448;
    lbl_806AA2D4.m100 = p + lbl_80625448 * 2;
    memset(p, 0, size);
    lbl_806AA2C0 = (Unk803B1378_Node**)SNDMEMI_allocz(lbl_80625448 * 4);
    memset(lbl_806AA2C0, 0, lbl_80625448 * 4);
    lbl_806262B0 = 1;
}

extern "C" void fn_803B141C()
{
    if (lbl_806262B0 != 0) {
        SNDMEMI_free(lbl_806AA2C4);
        int i;
        for (i = 0; i < lbl_80625448; i++) {
            Unk803B1378_Node* head = lbl_806AA2C0[i];
            if (head != 0) {
                Unk803B1378_Node* p = head;
                do {
                    Unk803B1378_Node* next = p->m0;
                    SNDMEMI_free(p);
                    p = next;
                } while (p != 0);
            }
        }
        SNDMEMI_free(lbl_806AA2C0);
        lbl_806262B0 = 0;
    }
}

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

extern "C" void fn_803B1EC8()
{
    lbl_806AA2D4.m1E0 = (void*)fn_803B6AF8;
    lbl_806AA2D4.m1E4 = (void*)fn_803B343C;
    lbl_806AA2D4.mC = 0x140;
}

extern "C" void fn_803B2108(int idx)
{
    Unk803B21EC_L* e = &lbl_806AA4B0[idx];
    int i;
    float k = lbl_8060984C;
    e->m1 = 0;
    e->m3C = k;
    for (i = 0; i < lbl_80625448; i++)
        e->m34[i] = e->m38[i];
    for (i = 0; i < lbl_806AA2D4.m9; i++)
        e->m4[i] = e->m1C[i];
    e->m0 = 2;
}
