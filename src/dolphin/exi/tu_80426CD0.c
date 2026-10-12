/*
 * Dolphin SDK EXI (MWCC GC/1.2.5n, cflags_dolphin_exi = -O3,p as EXIBios.c needs;
 * EXIUart.c at the end of this range may want -O4,p),
 * .text 0x80426CD0-0x80428F14 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * The tail of this range (fn_80428C64.., GXGetTexObj users and GX FIFO callers) is probably GX code.
 * Every data object is extern by its lbl_ name.
 */
