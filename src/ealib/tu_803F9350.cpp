/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803F9350-0x803FAE94 (code-only unit, 37 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" void fn_803FADD0(int, int);

extern "C" void fn_803FAE68()
{
    fn_803FADD0(1, 0xffff);
}
