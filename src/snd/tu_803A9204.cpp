/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803A9204-0x803A9830 (code-only unit, 13 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

#include "snd/cmn/sndcmn.h"

extern unsigned char lbl_8069C9E4[7];
extern unsigned int lbl_8069CAB8[6];
extern const unsigned int lbl_806251F0[6];
extern int lbl_80625208;
extern void (*lbl_8062520C)();
extern void (*lbl_80625210)();
extern int lbl_8069CAD4;
extern float lbl_80609598;

extern "C" int fn_803B0798();
extern "C" void fn_803AF9C0();
extern "C" void fn_803AB480(int handle);
extern "C" void fn_803B41C8(int voice);
extern "C" int fn_803AD2F0(void** pptp, SNDIPATCHHEADER* pph);
extern "C" void fn_803AFD88(SNDIPATCHHEADER* pph, int a, int b);
extern "C" void fn_803A81E0(SNDIPATCHHEADER* pph, int a);
extern "C" void fn_803B12D0(void* s, int chrg);
extern "C" void fn_803B12F8(void* s, int chrg);
extern "C" void fn_803A97DC(int initialize, int priority);

/* SNDplaysetdef: default SNDPLAYOPTS. */
extern "C" int fn_803A9204(SNDPLAYOPTS* pspo)
{
    pspo->pitchmult = 0x1000;
    pspo->timemult = 0x1000;
    pspo->highpasscutoff = 0;
    pspo->keynum = 0x3C;
    pspo->tempomult = 0x1000;
    pspo->lowpasscutoff = 0xFFFF;
    pspo->velocity = 0x7F;
    pspo->vol = 0x7F;
    pspo->drylevel = 0x7F;
    pspo->bend = 0x40;
    pspo->fxlevel0 = 0;
    pspo->azimuth = 0;
    pspo->elevation = 0;
    return 0;
}

extern "C" int fn_803A925C()
{
    if (lbl_8069C9E4[0] == 0)
        return 0;
    return fn_803B0798();
}

/* Seeds the iSNDrandom state: six words of the seed table plus the given seed. */
extern "C" void fn_803A9294(unsigned int seed)
{
    int i;
    for (i = 0; i <= 5; i++)
        lbl_8069CAB8[i] = lbl_806251F0[i] + seed;
}

/* near-miss: 62 vs 66 insns; retail reloads the s[5..1] words for the carry increments (no store-to-load forwarding across the early returns) and returns s[0] through r3; tried global-array, local-copy, nested-if, goto and loop forms */
unsigned int iSNDrandom()
{
    unsigned int t = lbl_8069CAB8[5] + lbl_8069CAB8[4];
    unsigned int carry = 0;
    if (t < lbl_8069CAB8[5] || t < lbl_8069CAB8[4])
        carry = 1;
    unsigned int b = lbl_8069CAB8[3];
    unsigned int c = lbl_8069CAB8[2];
    lbl_8069CAB8[4] = t;
    t = t + b + carry;
    unsigned int d = lbl_8069CAB8[1];
    lbl_8069CAB8[3] = t;
    unsigned int u = t + c + (t < b);
    lbl_8069CAB8[2] = u;
    unsigned int v = u + d + (u < c);
    lbl_8069CAB8[1] = v;
    unsigned int w = v + lbl_8069CAB8[0] + (v < d);
    lbl_8069CAB8[0] = w;
    if (++lbl_8069CAB8[5] != 0) return w;
    if (++lbl_8069CAB8[4] != 0) return w;
    if (++lbl_8069CAB8[3] != 0) return w;
    if (++lbl_8069CAB8[2] != 0) return w;
    if (++lbl_8069CAB8[1] != 0) return w;
    return lbl_8069CAB8[0] = w + 1;
}

/* near-miss: all 32 insns, but retail loads r4 (a) before the addi r3 for &pph in the fn_803AFD88 call; inline wrapper, local pointer and != / > 0 loop forms did not move it */
extern "C" int fn_803A93D0(unsigned int rendermodes, void* ptp, int a, int b)
{
    SNDIPATCHHEADER pph;
    void* p = (char*)ptp + 4;
    int more;
    do {
        more = fn_803AD2F0(&p, &pph);
        if (pph.rendermode & rendermodes) {
            fn_803AFD88(&pph, a, b);
            fn_803A81E0(&pph, 0);
        }
    } while (more != 0);
    return 0;
}

/* Runs the variable-timer clients once the timer period changes. */
extern "C" void fn_803A9450()
{
    if (lbl_8069CAD4 != lbl_80625208) {
        lbl_80625208 = lbl_8069CAD4;
        Snd::VariableTimerClient* c = (Snd::VariableTimerClient*)Snd::gVariableTimerList.GetHead();
        while (c != 0) {
            Snd::VariableTimerClient* next = (Snd::VariableTimerClient*)c->ln.GetNext();
            c->pClientFunc(c->pClientData);
            c = next;
        }
    }
}

/* near-miss: 152 insns; mine hoists the 0.0f constant into f31 (retail reloads lbl_80609598 in each block with lis/lfs, so no loop-invariant move) and lays out the fade clamp branches differently; extern float, local float and goto-stop forms tried */
extern "C" void fn_803A94BC()
{
    int i = 0;
    sndgs.audiotick++;
    fn_803AF9C0();
    for (i = 0; i < sndgs.numserverclients100hz; i++)
        sndgs.serverclient100hz[i]();
    for (i = 0; i < sndgs.voicestotal; i++) {
        CHANPUB* p = &sndgs.chan[i];
        if (p->status == 1) {
            if (sndgs.chan[i].handle >= 0 && p->ppitchlfo != 0) {
                if (++p->curpitchlfoentry >= p->pitchlfolength)
                    p->curpitchlfoentry = 0;
                p->detunepitch = 0;
                iSNDcalcpitch(i);
                SNDPLATFORM_setpitch(i);
            }
            int dirty = 0;
            if (p->pvollfo != 0) {
                dirty = 1;
                if (++p->curvollfoentry >= p->vollfolength)
                    p->curvollfoentry = 0;
            }
            float f = p->fadePer100Hz;
            if (f != 0.0f) {
                dirty = 1;
                p->programmedVol += f;
                if (f >= 0.0f ? !(p->programmedVol < p->fadeTargetVol) : !(p->programmedVol > p->fadeTargetVol)) {
                    p->programmedVol = p->fadeTargetVol;
                    p->fadePer100Hz = 0.0f;
                }
                if (p->programmedVol < 0.0f) {
                    fn_803AB480(p->handle);
                    continue;
                }
            }
            p->envduration--;
            if (p->envpertick != 0) {
                dirty = 1;
                p->envvol += p->envpertick;
            }
            if (p->envduration == 0) {
                if (++p->curenvelope >= p->numenvelopes) {
                    fn_803AB480(p->handle);
                    continue;
                }
                ENVELOPE* e = &p->paenvelope[p->curenvelope];
                p->envduration = e->duration;
                if (e->duration < 0)
                    p->envduration = 0x7FFFFFFF;
                p->envpertick = ((e->targetvol << 16) - p->envvol) / p->envduration;
            }
            if (dirty) {
                fn_803B41C8(i);
                Snd::Hal::SetVol(i);
            }
        }
    }
}

extern "C" void fn_803A971C(void* s, int chrg)
{
    fn_803B12D0(s, chrg);
}

extern "C" void fn_803A973C(void* s, int chrg)
{
    fn_803B12F8(s, chrg);
}

/* SNDSYS_entercritical */
extern "C" void fn_803A975C()
{
    lbl_8062520C();
    sndgs.incritical++;
}

/* SNDSYS_leavecritical */
extern "C" void fn_803A979C()
{
    sndgs.incritical--;
    lbl_80625210();
}

/* __static_initialization_and_destruction_0: Snd::gVariableTimerList(). */
extern "C" void fn_803A97DC(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize != 0)
        *(void**)&Snd::gVariableTimerList = 0;
}

/* _GLOBAL_.I */
extern "C" void fn_803A9804()
{
    fn_803A97DC(1, 0xFFFF);
}
