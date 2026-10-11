/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80013078-0x80013C88 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
int fn_80391C04(int, int, int);

void fn_80013078(int a0, int a1)
{
    fn_80056C9C(0x141);
    lbl_80624408(fn_80391C04(0, 0, 0x3b3), 2, a0, a1);
}

void fn_800130DC(int a0, int a1)
{
    fn_80056C9C(0x142);
    lbl_80624408(fn_80391C04(0, 0, 0x3b4), 2, a0, a1);
}

void fn_80013140(int a0)
{
    fn_80056C9C(0x50);
    lbl_80624408(fn_80391C04(0, 0, 0x3b6), 1, a0);
}

void fn_8001319C()
{
    fn_80056C9C(0x16c);
    lbl_80624408(fn_80391C04(0, 0, 0x3b9), 0);
}

void fn_800131F0(int a0)
{
    fn_80056C9C(0x140);
    lbl_80624408(fn_80391C04(0, 0, 0x3bb), 1, a0);
}

void fn_8001324C()
{
    fn_80056C9C(0x145);
    lbl_80624408(fn_80391C04(0, 0, 0x3bc), 0);
}

void fn_800132A0(int a0, int a1)
{
    fn_80056C9C(0xa2);
    lbl_80624408(fn_80391C04(0, 0, 0x3bd), 2, a0, a1);
}

void fn_80013304(int a0, int a1, int a2)
{
    fn_80056C9C(0xf0);
    lbl_80624408(fn_80391C04(0, 0, 0x3bf), 3, a0, a1, a2);
}

void fn_80013370(int a0, int a1, int a2)
{
    fn_80056C9C(0x98);
    lbl_80624408(fn_80391C04(0, 0, 0x3c1), 3, a0, a1, a2);
}

void fn_800133DC(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0xfa);
    lbl_80624408(fn_80391C04(0, 0, 0x3c6), 4, a0, a1, a2, a3);
}

void fn_80013450(int a0, int a1)
{
    fn_80056C9C(0x99);
    lbl_80624408(fn_80391C04(0, 0, 0x3c7), 2, a0, a1);
}

void fn_800134B4(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x4d);
    lbl_80624408(fn_80391C04(0, 0, 0x3c8), 5, a0, a1, a2, a3, a4);
}

void fn_80013530(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0xbf);
    lbl_80624408(fn_80391C04(0, 0, 0x3c9), 4, a0, a1, a2, a3);
}

void fn_800135A4(int a0, int a1)
{
    fn_80056C9C(0x117);
    lbl_80624408(fn_80391C04(0, 0, 0x3cb), 2, a0, a1);
}

void fn_80013608(int a0, int a1, int a2)
{
    fn_80056C9C(0x124);
    lbl_80624408(fn_80391C04(0, 0, 0x3cc), 3, a0, a1, a2);
}

void fn_80013674(int a0)
{
    fn_80056C9C(0xfe);
    lbl_80624408(fn_80391C04(0, 0, 0x3cd), 1, a0);
}

void fn_800136D0()
{
    fn_80056C9C(0x6e);
    lbl_80624408(fn_80391C04(0, 0, 0x3ce), 0);
}

void fn_80013724(int a0)
{
    fn_80056C9C(0x72);
    lbl_80624408(fn_80391C04(0, 0, 0x3cf), 1, a0);
}

void fn_80013780(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    fn_80056C9C(0x44);
    lbl_80624408(fn_80391C04(0, 0, 0x3d0), 8, a0, a1, a2, a3, a4, a5, a6, a7);
}

void fn_80013814()
{
    fn_80056C9C(0xdd);
    lbl_80624408(fn_80391C04(0, 0, 0x3d1), 0);
}

void fn_80013868(int a0)
{
    fn_80056C9C(0x143);
    lbl_80624408(fn_80391C04(0, 0, 0x3da), 1, a0);
}

void fn_800138C4(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x164);
    lbl_80624408(fn_80391C04(0, 0, 0x3e1), 4, a0, a1, a2, a3);
}

void fn_80013938(int a0)
{
    fn_80056C9C(0x8d);
    lbl_80624408(fn_80391C04(0, 0, 0x3e2), 1, a0);
}

void fn_80013994(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x55);
    lbl_80624408(fn_80391C04(0, 0, 0x3e3), 6, a0, a1, a2, a3, a4, a5);
}

void fn_80013A18(int a0, int a1, int a2)
{
    fn_80056C9C(0xbc);
    lbl_80624408(fn_80391C04(0, 0, 0x3e4), 3, a0, a1, a2);
}

void fn_80013A84(int a0, int a1)
{
    fn_80056C9C(0xb9);
    lbl_80624408(fn_80391C04(0, 0, 0x3e5), 2, a0, a1);
}

void fn_80013AE8()
{
    fn_80056C9C(0xb8);
    lbl_80624408(fn_80391C04(0, 0, 0x3e6), 0);
}

void fn_80013B3C(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x151);
    lbl_80624408(fn_80391C04(0, 0, 0x3e7), 5, a0, a1, a2, a3, a4);
}

void fn_80013BB8(int a0, int a1, int a2)
{
    fn_80056C9C(0x168);
    lbl_80624408(fn_80391C04(0, 0, 0x3e8), 3, a0, a1, a2);
}

void fn_80013C24(int a0, int a1)
{
    fn_80056C9C(0x144);
    lbl_80624408(fn_80391C04(0, 0, 0x3e9), 2, a0, a1);
}
