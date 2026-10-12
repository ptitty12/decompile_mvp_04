/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803A6B64-0x803A6D80 (code-only unit, 3 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/sndo.h"
#include "snd/cmn/sndcmn.h"
#undef override
#include "snd/extern/aemsdef.h"
#include "snd/cmn/saemsi.h"

extern "C" {

void fn_803A6D1C(int a, int b)
{
    if (b != 0xFFFF) {
        return;
    }
    if (a == 0) {
        return;
    }
    sndaems.timerclient = CListDStack();
    sndaems.modulebank = CListDStack();
    sndaems.allocatedstreams = CListDStack();
    sndaems.freestreams = CListDStack();
}

void fn_803A6D54()
{
    fn_803A6D1C(1, 0xFFFF);
}

}
