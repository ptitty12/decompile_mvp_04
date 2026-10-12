/*
 * Translation unit at 0x800034A0 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 2 functions.
 *
 * .text 0x800034A0-0x800042B0, .rodata 0x805A301C-0x805A3400, .bss 0x80686860-0x806868FC.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 */

extern "C" void fn_800034A0(int initialize, int priority);

extern "C" void fn_80004284(void)
{
    fn_800034A0(1, 0xffff);
}
