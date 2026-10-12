/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803AC88C-0x803AFDC0 (code-only unit, 43 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

struct DtorAt0 { const void* m; };

extern "C" void fn_803B9DDC(DtorAt0* s, int chrg);

extern "C" void fn_803AC904(DtorAt0* s, int chrg)
{
    fn_803B9DDC(s, chrg);
}

extern "C" void fn_803B9E08(DtorAt0* s, int chrg);

extern "C" void fn_803AC924(DtorAt0* s, int chrg)
{
    fn_803B9E08(s, chrg);
}
