/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803CB728-0x803CECA4 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct DtorAt0 { const void* m; };

extern char lbl_80686268[];

extern "C" void fn_803BE90C(void* s, int a);

extern "C" void fn_803CEC78(void* p, int n);

struct EAGLSetC {
    char pad0[0xC];
    int mC;
};

extern "C" void fn_803CB728(EAGLSetC* s, int v)
{
    s->mC = v;
}

extern "C" void fn_803CEC24(DtorAt0* s, int chrg)
{
    s->m = lbl_80686268;
    fn_803BE90C(s, 0);
    if (chrg & 1)
        fn_803CEC78(s, 0x14);
}
