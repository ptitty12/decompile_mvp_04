/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B998C-0x803BA9DC (code-only unit, 43 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

extern "C" void fn_803BA988(int a, int b);

struct SndErrObj {
    int pad0;
    int m4;
};

extern "C" void fn_803B99DC(SndErrObj* s)
{
    s->m4 = -3;
}

extern "C" void fn_803BA9B0()
{
    fn_803BA988(1, 0xFFFF);
}
