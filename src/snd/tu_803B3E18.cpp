/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B3E18-0x803B3FE0 (code-only unit, 4 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

struct DtorAt0 { const void* m; };

extern "C" void fn_803AC134(DtorAt0* s, int chrg);

extern "C" void fn_803B3E88(DtorAt0* s, int chrg)
{
    fn_803AC134(s, chrg);
}
