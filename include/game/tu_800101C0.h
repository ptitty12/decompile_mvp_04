#ifndef GAME_TU_800101C0_H
#define GAME_TU_800101C0_H

/*
 * 0x800101C0..0x80010E38: thirty thin wrappers that all share one shape.
 * Each calls fn_80056C9C(<id>), then calls through the function pointer at
 * 0x80624408 with the result of fn_80391C04(0, 0, <line>) as the first
 * argument, the number of remaining arguments as the second (0..9), and its
 * own integer parameters passed through unchanged (variadic call: crclr cr1eq,
 * arguments beyond the eighth go on the stack). The <line> values run from
 * 0x22C to 0x315 in .text order, so they look like source line numbers of a
 * trace/log macro; the ids are not monotonic.
 *
 * Evidence for the prototypes: fn_80391C04 (0x80391C04) only packs its
 * arguments into a word on the stack (stb r3 -> +0xB, stb r4 -> +0xA, sth r5
 * -> +8) and returns it, so it takes (u8, u8, u16) and returns a 32-bit
 * value. fn_80056C9C copies its argument to r4 and returns nothing. The
 * pointer at 0x80624408 is 0 in the initial .data (installed at runtime) and
 * is called with crclr cr1eq, i.e. no floating-point varargs.
 */
void fn_80056C9C(int id);
/* C linkage and unsigned result confirmed by ealib/tu_803912F8.cpp. */
extern "C" unsigned fn_80391C04(unsigned char a, unsigned char b, unsigned short line);
extern void (*lbl_80624408)(int, int, ...);

#endif
