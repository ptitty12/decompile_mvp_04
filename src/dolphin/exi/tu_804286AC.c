/*
 * Dolphin SDK EXI (MWCC GC/1.2.5n, cflags_dolphin_dvd = cflags_dolphin_sdk with -char signed: -O4,p),
 * .text 0x804286AC-0x80428C64 (code-only unit, 4 functions; placeholder name).
 * EXIUart.c (shape of the code, with the reference dolsdk2004 EXIUart.c): fn_804286AC EXIGetRevision-like
 * probe, then the UART/barnacle init and write routines. Split off dolphin/exi/tu_80426CD0.c
 * (docs/DECISIONS.md 2026-10-12). Every data object is extern by its lbl_ name.
 */
