/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80018E98-0x80019B30 only: every data object is extern by its lbl_ name.
 *
 * The one-line trace wrappers here share the shape described in
 * include/game/tu_800101C0.h (fn_80056C9C(id); then a variadic call through
 * lbl_80624408 with the fn_80391C04(0, 0, line) tag and the argument count).
 */
#include "game/tu_800101C0.h"

void fn_80018E98(int a, int b, int c, int d)
{
    fn_80056C9C(0xf7);
    lbl_80624408(fn_80391C04(0, 0, 0x677), 4, a, b, c, d);
}

void fn_80018F0C(int a, int b)
{
    fn_80056C9C(0x195);
    lbl_80624408(fn_80391C04(0, 0, 0x678), 2, a, b);
}

void fn_80018F70(int a, int b, int c, int d)
{
    fn_80056C9C(0x192);
    lbl_80624408(fn_80391C04(0, 0, 0x679), 4, a, b, c, d);
}

void fn_80018FE4(int a, int b)
{
    fn_80056C9C(0x193);
    lbl_80624408(fn_80391C04(0, 0, 0x67a), 2, a, b);
}

void fn_80019048(int a)
{
    fn_80056C9C(0x190);
    lbl_80624408(fn_80391C04(0, 0, 0x67d), 1, a);
}

void fn_800190A4(int a, int b)
{
    fn_80056C9C(0x41);
    lbl_80624408(fn_80391C04(0, 0, 0x67f), 2, a, b);
}

void fn_80019108(int a, int b)
{
    fn_80056C9C(0x42);
    lbl_80624408(fn_80391C04(0, 0, 0x681), 2, a, b);
}

void fn_8001916C(int a)
{
    fn_80056C9C(0x40);
    lbl_80624408(fn_80391C04(0, 0, 0x688), 1, a);
}

void fn_800191C8(int a, int b)
{
    fn_80056C9C(0xb0);
    lbl_80624408(fn_80391C04(0, 0, 0x68a), 2, a, b);
}

void fn_8001922C(int a, int b, int c)
{
    fn_80056C9C(0xa3);
    lbl_80624408(fn_80391C04(0, 0, 0x68f), 3, a, b, c);
}

void fn_80019298(void)
{
    fn_80056C9C(0xb2);
    lbl_80624408(fn_80391C04(0, 0, 0x693), 0);
}

void fn_800192EC(int a)
{
    fn_80056C9C(0xb3);
    lbl_80624408(fn_80391C04(0, 0, 0x694), 1, a);
}

void fn_80019348(int a)
{
    fn_80056C9C(0x16e);
    lbl_80624408(fn_80391C04(0, 0, 0x695), 1, a);
}

void fn_800193A4(int a)
{
    fn_80056C9C(0x179);
    lbl_80624408(fn_80391C04(0, 0, 0x69a), 1, a);
}

void fn_80019400(void)
{
    fn_80056C9C(0x11);
    lbl_80624408(fn_80391C04(0, 0, 0x6a0), 0);
}

void fn_80019454(void)
{
    fn_80056C9C(0x12);
    lbl_80624408(fn_80391C04(0, 0, 0x6a1), 0);
}

void fn_800194A8(void)
{
    fn_80056C9C(0x163);
    lbl_80624408(fn_80391C04(0, 0, 0x6a2), 0);
}

void fn_800194FC(void)
{
    fn_80056C9C(0x162);
    lbl_80624408(fn_80391C04(0, 0, 0x6a3), 0);
}

void fn_80019550(void)
{
    fn_80056C9C(0x79);
    lbl_80624408(fn_80391C04(0, 0, 0x6a4), 0);
}

void fn_800195A4(int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80056C9C(0x1a);
    lbl_80624408(fn_80391C04(0, 0, 0x6a5), 8, a, b, c, d, e, f, g, h);
}

void fn_80019638(int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80056C9C(0x172);
    lbl_80624408(fn_80391C04(0, 0, 0x6a6), 8, a, b, c, d, e, f, g, h);
}

void fn_800196CC(int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80056C9C(0x1b);
    lbl_80624408(fn_80391C04(0, 0, 0x6a7), 8, a, b, c, d, e, f, g, h);
}

void fn_80019760(int a, int b, int c, int d, int e, int f)
{
    fn_80056C9C(0x1c);
    lbl_80624408(fn_80391C04(0, 0, 0x6a9), 6, a, b, c, d, e, f);
}

void fn_800197E4(int a, int b, int c, int d, int e)
{
    fn_80056C9C(0x174);
    lbl_80624408(fn_80391C04(0, 0, 0x6aa), 5, a, b, c, d, e);
}

void fn_80019860(int a, int b, int c, int d)
{
    fn_80056C9C(0x173);
    lbl_80624408(fn_80391C04(0, 0, 0x6ab), 4, a, b, c, d);
}

void fn_800198D4(int a, int b, int c, int d, int e)
{
    fn_80056C9C(0x105);
    lbl_80624408(fn_80391C04(0, 0, 0x6ad), 5, a, b, c, d, e);
}

void fn_80019950(int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80056C9C(0xab);
    lbl_80624408(fn_80391C04(0, 0, 0x6b2), 8, a, b, c, d, e, f, g, h);
}

void fn_800199E4(int a, int b, int c, int d)
{
    fn_80056C9C(0x29);
    lbl_80624408(fn_80391C04(0, 0, 0x6b3), 4, a, b, c, d);
}

void fn_80019A58(int a, int b)
{
    fn_80056C9C(0x81);
    lbl_80624408(fn_80391C04(0, 0, 0x6b4), 2, a, b);
}

void fn_80019ABC(int a, int b, int c, int d)
{
    fn_80056C9C(0x80);
    lbl_80624408(fn_80391C04(0, 0, 0x6b5), 4, a, b, c, d);
}
