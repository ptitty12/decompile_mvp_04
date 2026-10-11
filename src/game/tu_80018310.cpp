/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80018310-0x80018E98 only: every data object is extern by its lbl_ name.
 *
 * The one-line trace wrappers here share the shape described in
 * include/game/tu_800101C0.h (fn_80056C9C(id); then a variadic call through
 * lbl_80624408 with the fn_80391C04(0, 0, line) tag and the argument count).
 */
#include "game/tu_800101C0.h"

void fn_80018310(int a, int b, int c, int d)
{
    fn_80056C9C(0x18a);
    lbl_80624408(fn_80391C04(0, 0, 0x649), 4, a, b, c, d);
}

void fn_80018384(int a, int b)
{
    fn_80056C9C(0x68);
    lbl_80624408(fn_80391C04(0, 0, 0x64e), 2, a, b);
}

void fn_800183E8(int a)
{
    fn_80056C9C(0x69);
    lbl_80624408(fn_80391C04(0, 0, 0x64f), 1, a);
}

void fn_80018444(int a, int b, int c)
{
    fn_80056C9C(0x64);
    lbl_80624408(fn_80391C04(0, 0, 0x654), 3, a, b, c);
}

void fn_800184B0(int a, int b, int c)
{
    fn_80056C9C(0x63);
    lbl_80624408(fn_80391C04(0, 0, 0x655), 3, a, b, c);
}

void fn_8001851C(void)
{
    fn_80056C9C(0x15f);
    lbl_80624408(fn_80391C04(0, 0, 0x657), 0);
}

void fn_80018570(int a, int b, int c)
{
    fn_80056C9C(0x135);
    lbl_80624408(fn_80391C04(0, 0, 0x659), 3, a, b, c);
}

void fn_800185DC(int a, int b)
{
    fn_80056C9C(0xf8);
    lbl_80624408(fn_80391C04(0, 0, 0x65a), 2, a, b);
}

void fn_80018640(void)
{
    fn_80056C9C(0xe3);
    lbl_80624408(fn_80391C04(0, 0, 0x65b), 0);
}

void fn_80018694(void)
{
    fn_80056C9C(0xd2);
    lbl_80624408(fn_80391C04(0, 0, 0x65c), 0);
}

void fn_800186E8(void)
{
    fn_80056C9C(0xa4);
    lbl_80624408(fn_80391C04(0, 0, 0x65e), 0);
}

void fn_8001873C(void)
{
    fn_80056C9C(0x7a);
    lbl_80624408(fn_80391C04(0, 0, 0x65f), 0);
}

void fn_80018790(int a)
{
    fn_80056C9C(0x1ce);
    lbl_80624408(fn_80391C04(0, 0, 0x660), 1, a);
}

void fn_800187EC(int a, int b)
{
    fn_80056C9C(0x136);
    lbl_80624408(fn_80391C04(0, 0, 0x662), 2, a, b);
}

void fn_80018850(int a, int b)
{
    fn_80056C9C(0x7b);
    lbl_80624408(fn_80391C04(0, 0, 0x663), 2, a, b);
}

void fn_800188B4(int a, int b)
{
    fn_80056C9C(0x17);
    lbl_80624408(fn_80391C04(0, 0, 0x666), 2, a, b);
}

void fn_80018918(int a, int b)
{
    fn_80056C9C(0x7c);
    lbl_80624408(fn_80391C04(0, 0, 0x668), 2, a, b);
}

void fn_8001897C(void)
{
    fn_80056C9C(0x7d);
    lbl_80624408(fn_80391C04(0, 0, 0x669), 0);
}

void fn_800189D0(int a)
{
    fn_80056C9C(0x88);
    lbl_80624408(fn_80391C04(0, 0, 0x66a), 1, a);
}

void fn_80018A2C(void)
{
    fn_80056C9C(0x1a2);
    lbl_80624408(fn_80391C04(0, 0, 0x66b), 0);
}

void fn_80018A80(int a)
{
    fn_80056C9C(0x18f);
    lbl_80624408(fn_80391C04(0, 0, 0x66c), 1, a);
}

void fn_80018ADC(int a, int b)
{
    fn_80056C9C(0x54);
    lbl_80624408(fn_80391C04(0, 0, 0x66d), 2, a, b);
}

void fn_80018B40(int a, int b)
{
    fn_80056C9C(0x5a);
    lbl_80624408(fn_80391C04(0, 0, 0x66f), 2, a, b);
}

void fn_80018BA4(int a, int b, int c)
{
    fn_80056C9C(0x5d);
    lbl_80624408(fn_80391C04(0, 0, 0x670), 3, a, b, c);
}

void fn_80018C10(void)
{
    fn_80056C9C(0x1c1);
    lbl_80624408(fn_80391C04(0, 0, 0x671), 0);
}

void fn_80018C64(int a)
{
    fn_80056C9C(0x52);
    lbl_80624408(fn_80391C04(0, 0, 0x672), 1, a);
}

void fn_80018CC0(int a, int b, int c, int d, int e)
{
    fn_80056C9C(0x194);
    lbl_80624408(fn_80391C04(0, 0, 0x673), 5, a, b, c, d, e);
}

void fn_80018D3C(int a, int b, int c, int d)
{
    fn_80056C9C(0x196);
    lbl_80624408(fn_80391C04(0, 0, 0x674), 4, a, b, c, d);
}

void fn_80018DB0(int a, int b, int c, int d)
{
    fn_80056C9C(0x199);
    lbl_80624408(fn_80391C04(0, 0, 0x675), 4, a, b, c, d);
}

void fn_80018E24(int a, int b, int c, int d)
{
    fn_80056C9C(0xdf);
    lbl_80624408(fn_80391C04(0, 0, 0x676), 4, a, b, c, d);
}
