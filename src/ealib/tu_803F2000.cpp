/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803F2000-0x803F73B0 (code-only unit, 36 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern unsigned short lbl_806EEA5C[2];
extern unsigned short lbl_806EEA58[2];

extern "C" unsigned short* fn_803F644C(void* l, int k)
{
    if (k == 1)
        return lbl_806EEA5C;
    return lbl_806EEA58;
}

extern char lbl_8060E4F8[];

extern "C" void fn_80377408(void*);

extern "C" void fn_803F6AA4(void** self, int c)
{
    *self = lbl_8060E4F8;
    if (c & 1)
        fn_80377408(self);
}

extern char lbl_8060E358[];

extern "C" void fn_803F7100(void** self, int c)
{
    *self = lbl_8060E358;
    if (c & 1)
        fn_80377408(self);
}
