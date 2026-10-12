/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803AFDC0-0x803B21AC (code-only unit, 42 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

extern "C" void fn_80435CE8(void* p);

extern char lbl_806AA030[];

extern "C" void fn_803B12A4()
{
    fn_80435CE8(lbl_806AA030);
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
