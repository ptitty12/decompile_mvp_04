/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803C1DD0-0x803CB728 (code-only unit, 34 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct EAGLInit81F4 {
    char pad0[0xC];
    int mC;
    int m10;
    char pad14[8];
    int m1C;
};

extern "C" void fn_803C81F4(EAGLInit81F4* s, int v)
{
    s->mC = v;
    s->m10 = -1;
    s->m1C = -1;
}
