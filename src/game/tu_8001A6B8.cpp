/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001A6B8-0x8001B190 only: every data object is extern by its lbl_ name.
 *
 * The one-line trace wrappers here share the shape described in
 * include/game/tu_800101C0.h (fn_80056C9C(id); then a variadic call through
 * lbl_80624408 with the fn_80391C04(0, 0, line) tag and the argument count).
 */
#include "game/tu_800101C0.h"

void fn_8001A6B8__Fi(int a)
{
    fn_80056C9C(0x10a);
    lbl_80624408(fn_80391C04(0, 0, 0x72c), 1, a);
}

void fn_8001A714__Fv(void)
{
    fn_80056C9C(0x1d7);
    lbl_80624408(fn_80391C04(0, 0, 0x72e), 0);
}

void fn_8001A768__Fv(void)
{
    fn_80056C9C(0x1d6);
    lbl_80624408(fn_80391C04(0, 0, 0x730), 0);
}

void fn_8001A7BC__Fi(int a)
{
    fn_80056C9C(0x14);
    lbl_80624408(fn_80391C04(0, 0, 0x732), 1, a);
}

void fn_8001A818__Fii(int a, int b)
{
    fn_80056C9C(0x15);
    lbl_80624408(fn_80391C04(0, 0, 0x733), 2, a, b);
}

void fn_8001A87C__Fiiii(int a, int b, int c, int d)
{
    fn_80056C9C(0x1a5);
    lbl_80624408(fn_80391C04(0, 0, 0x734), 4, a, b, c, d);
}

void fn_8001A8F0__Fii(int a, int b)
{
    fn_80056C9C(0x13);
    lbl_80624408(fn_80391C04(0, 0, 0x735), 2, a, b);
}

void fn_8001A954__Fiiii(int a, int b, int c, int d)
{
    fn_80056C9C(0x1a4);
    lbl_80624408(fn_80391C04(0, 0, 0x736), 4, a, b, c, d);
}

void fn_8001A9C8__Fi(int a)
{
    fn_80056C9C(0x161);
    lbl_80624408(fn_80391C04(0, 0, 0x737), 1, a);
}

void fn_8001AA24(int a, int b)
{
    lbl_80624408(fn_80391C04(0x6, 0x0, 0xc000), 2, a, b);
}

void fn_8001AA84(int a, int b)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x6075), 2, a, b);
}

void fn_8001AAE0(int a, int b, int c)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x6077), 3, a, b, c);
}

void fn_8001AB44(int a, int b, int c)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x6079), 3, a, b, c);
}

void fn_8001ABA8(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x607b), 1, a);
}

void fn_8001ABFC(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x607d), 1, a);
}

void fn_8001AC50(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x607e), 1, a);
}

void fn_8001ACA4(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x607f), 1, a);
}

void fn_8001ACF8(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x6083), 1, a);
}

void fn_8001AD4C(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x6085), 1, a);
}

void fn_8001ADA0(int a)
{
    lbl_80624408(fn_80391C04(0x3, 0x0, 0x6087), 1, a);
}

void fn_8001ADF4(void)
{
    lbl_80624408(fn_80391C04(0x4, 0x0, 0x8089), 0);
}

void fn_8001AE3C(void)
{
    lbl_80624408(fn_80391C04(0x4, 0x0, 0x808a), 0);
}

void fn_8001AE84(void)
{
    lbl_80624408(fn_80391C04(0x4, 0x0, 0x808f), 0);
}

void fn_8001AECC(int a, int b, int c, int d)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2008), 4, a, b, c, d);
}

void fn_8001AF38(int a, int b, int c, int d)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2009), 4, a, b, c, d);
}

void fn_8001AFA4(int a, int b, int c, int d)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x200c), 4, a, b, c, d);
}

void fn_8001B010(int a)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x200d), 1, a);
}

void fn_8001B064(int a, int b, int c, int d)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x200e), 4, a, b, c, d);
}

void fn_8001B0D0(int a, int b)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x200f), 2, a, b);
}

void fn_8001B12C(int a, int b, int c)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2011), 3, a, b, c);
}
