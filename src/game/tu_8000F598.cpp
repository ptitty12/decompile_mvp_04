/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8000F598-0x800101C0 only: every data object is extern by its lbl_ name.
 *
 * Thirty one-line trace wrappers: each calls fn_80056C9C(K), builds a tag word
 * with fn_80391C04(0, 0, C) (stores u8/u8/u16 into a word and returns it) and
 * passes it to the function pointer at 0x80624408 together with the argument
 * count and the wrapper's own arguments (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
int fn_80391C04(int, int, int);

void fn_8000F598(int a0)
{
    fn_80056C9C(0x1d0);
    lbl_80624408(fn_80391C04(0, 0, 0x24), 1, a0);
}

void fn_8000F5F4(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x106);
    lbl_80624408(fn_80391C04(0, 0, 0x2c), 5, a0, a1, a2, a3, a4);
}

void fn_8000F670(int a0, int a1)
{
    fn_80056C9C(0x51);
    lbl_80624408(fn_80391C04(0, 0, 0x30), 2, a0, a1);
}

void fn_8000F6D4(int a0)
{
    fn_80056C9C(0x1a0);
    lbl_80624408(fn_80391C04(0, 0, 0x5f), 1, a0);
}

void fn_8000F730(int a0, int a1)
{
    fn_80056C9C(0x146);
    lbl_80624408(fn_80391C04(0, 0, 0x6a), 2, a0, a1);
}

void fn_8000F794(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x102);
    lbl_80624408(fn_80391C04(0, 0, 0x73), 4, a0, a1, a2, a3);
}

void fn_8000F808()
{
    fn_80056C9C(0x8f);
    lbl_80624408(fn_80391C04(0, 0, 0x75), 0);
}

void fn_8000F85C(int a0)
{
    fn_80056C9C(0x95);
    lbl_80624408(fn_80391C04(0, 0, 0x81), 1, a0);
}

void fn_8000F8B8(int a0)
{
    fn_80056C9C(0x123);
    lbl_80624408(fn_80391C04(0, 0, 0x84), 1, a0);
}

void fn_8000F914()
{
    fn_80056C9C(0x138);
    lbl_80624408(fn_80391C04(0, 0, 0x85), 0);
}

void fn_8000F968(int a0)
{
    fn_80056C9C(0x73);
    lbl_80624408(fn_80391C04(0, 0, 0x86), 1, a0);
}

void fn_8000F9C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
    fn_80056C9C(0x152);
    lbl_80624408(fn_80391C04(0, 0, 0x107), 16, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
}

void fn_8000FA98(int a0, int a1)
{
    fn_80056C9C(0xd8);
    lbl_80624408(fn_80391C04(0, 0, 0x108), 2, a0, a1);
}

void fn_8000FAFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    fn_80056C9C(0xd5);
    lbl_80624408(fn_80391C04(0, 0, 0x109), 8, a0, a1, a2, a3, a4, a5, a6, a7);
}

void fn_8000FB90()
{
    fn_80056C9C(0x1be);
    lbl_80624408(fn_80391C04(0, 0, 0x114), 0);
}

void fn_8000FBE4(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x62);
    lbl_80624408(fn_80391C04(0, 0, 0x16d), 4, a0, a1, a2, a3);
}

void fn_8000FC58()
{
    fn_80056C9C(0x13a);
    lbl_80624408(fn_80391C04(0, 0, 0x184), 0);
}

void fn_8000FCAC(int a0)
{
    fn_80056C9C(0x13b);
    lbl_80624408(fn_80391C04(0, 0, 0x185), 1, a0);
}

void fn_8000FD08()
{
    fn_80056C9C(0x13e);
    lbl_80624408(fn_80391C04(0, 0, 0x186), 0);
}

void fn_8000FD5C()
{
    fn_80056C9C(0xee);
    lbl_80624408(fn_80391C04(0, 0, 0x189), 0);
}

void fn_8000FDB0(int a0)
{
    fn_80056C9C(0xd7);
    lbl_80624408(fn_80391C04(0, 0, 0x1a6), 1, a0);
}

void fn_8000FE0C()
{
    fn_80056C9C(0x4);
    lbl_80624408(fn_80391C04(0, 0, 0x1be), 0);
}

void fn_8000FE60(int a0)
{
    fn_80056C9C(0x1b0);
    lbl_80624408(fn_80391C04(0, 0, 0x1bf), 1, a0);
}

void fn_8000FEBC()
{
    fn_80056C9C(0x11c);
    lbl_80624408(fn_80391C04(0, 0, 0x1c5), 0);
}

void fn_8000FF10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    fn_80056C9C(0x17c);
    lbl_80624408(fn_80391C04(0, 0, 0x1d0), 8, a0, a1, a2, a3, a4, a5, a6, a7);
}

void fn_8000FFA4(int a0)
{
    fn_80056C9C(0xd4);
    lbl_80624408(fn_80391C04(0, 0, 0x1d3), 1, a0);
}

void fn_80010000(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x9c);
    lbl_80624408(fn_80391C04(0, 0, 0x1f9), 6, a0, a1, a2, a3, a4, a5);
}

void fn_80010084(int a0, int a1)
{
    fn_80056C9C(0x157);
    lbl_80624408(fn_80391C04(0, 0, 0x202), 2, a0, a1);
}

void fn_800100E8(int a0, int a1)
{
    fn_80056C9C(0x86);
    lbl_80624408(fn_80391C04(0, 0, 0x203), 2, a0, a1);
}

void fn_8001014C(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x1b6);
    lbl_80624408(fn_80391C04(0, 0, 0x204), 4, a0, a1, a2, a3);
}
