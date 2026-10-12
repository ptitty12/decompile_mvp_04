/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B3E18-0x803B3FE0 (code-only unit, 4 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

#include "snd/cmn/sndcmn.h"

struct DtorAt0 { const void* m; };

extern "C" void fn_803AC134(DtorAt0* s, int chrg);

extern unsigned char lbl_8060990A[];
extern int lbl_8069CBC0;

/* near-miss: 28 insns, same shape; retail keeps numchan in r0 and computes (table + g*0x24) before + numchan*6, so the add operand order and the lha/mulli registers differ; declaration-order and expression-order variants tried */
extern "C" void fn_803B3E18(CHANPUB* c)
{
    const unsigned char* t = lbl_8060990A + c->numchan * 6 + lbl_8069CBC0 * 0x24;
    int i;
    for (i = 0; i < c->numchan; i++)
        sndgs.chan[c->voices[i]].azimuth = t[i] << 8;
}

extern "C" void fn_803B3E88(DtorAt0* s, int chrg)
{
    fn_803AC134(s, chrg);
}

extern "C" int fn_803B3EA8(int shandle, int ch, int level)
{
    int setvoice;
    int voice = SNDVOICEI_get(shandle);
    if (voice >= 0) {
        setvoice = -1;
        while (iSNDpatchkey(voice, &setvoice)) {
            sndgs.chan[setvoice].pFxVolume[ch].fxLevel = level / 127.0f;
            SNDPLATFORM_setfxlevel(setvoice, ch);
        }
    }
    return voice;
}

/* near-miss: 29/32: retail does cmpwi r4,0 then subi (we emit mr. and a different order); loop and rem placement variants tried */
extern "C" int fn_803B3F60(const unsigned char* p, int n)
{
    int v = 0;
    if (n != 0) {
        int rem = n - 1;
        do {
            v = (v << 8) + *p++;
        } while (rem-- != 0);
    }
    if (n == 1 && v > 0x7f)
        v -= 0x100;
    else if (n == 2 && v > 0x7fff)
        v -= 0x10000;
    else if (n == 3 && v > 0x7fffff)
        v -= 0x1000000;
    return v;
}
