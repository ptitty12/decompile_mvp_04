/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80013C88-0x800147D8 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
int fn_80391C04(int, int, int);

void fn_80013C88(int a0)
{
    fn_80056C9C(0x150);
    lbl_80624408(fn_80391C04(0, 0, 0x3eb), 1, a0);
}

void fn_80013CE4(int a0, int a1)
{
    fn_80056C9C(0x1c6);
    lbl_80624408(fn_80391C04(0, 0, 0x3f5), 2, a0, a1);
}

void fn_80013D48(int a0, int a1)
{
    fn_80056C9C(0x56);
    lbl_80624408(fn_80391C04(0, 0, 0x3f7), 2, a0, a1);
}

void fn_80013DAC(int a0)
{
    fn_80056C9C(0x5f);
    lbl_80624408(fn_80391C04(0, 0, 0x3f9), 1, a0);
}

void fn_80013E08()
{
    fn_80056C9C(0x6b);
    lbl_80624408(fn_80391C04(0, 0, 0x3fa), 0);
}

void fn_80013E5C(int a0, int a1)
{
    fn_80056C9C(0x96);
    lbl_80624408(fn_80391C04(0, 0, 0x3fd), 2, a0, a1);
}

void fn_80013EC0(int a0)
{
    fn_80056C9C(0x57);
    lbl_80624408(fn_80391C04(0, 0, 0x3fe), 1, a0);
}

void fn_80013F1C(int a0, int a1)
{
    fn_80056C9C(0xc5);
    lbl_80624408(fn_80391C04(0, 0, 0x408), 2, a0, a1);
}

void fn_80013F80()
{
    fn_80056C9C(0x126);
    lbl_80624408(fn_80391C04(0, 0, 0x40a), 0);
}

void fn_80013FD4(int a0)
{
    fn_80056C9C(0x12b);
    lbl_80624408(fn_80391C04(0, 0, 0x40b), 1, a0);
}

void fn_80014030(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0xfb);
    lbl_80624408(fn_80391C04(0, 0, 0x40e), 4, a0, a1, a2, a3);
}

void fn_800140A4(int a0, int a1)
{
    fn_80056C9C(0x14b);
    lbl_80624408(fn_80391C04(0, 0, 0x40f), 2, a0, a1);
}

void fn_80014108(int a0, int a1)
{
    fn_80056C9C(0x14c);
    lbl_80624408(fn_80391C04(0, 0, 0x410), 2, a0, a1);
}

void fn_8001416C(int a0, int a1, int a2)
{
    fn_80056C9C(0x158);
    lbl_80624408(fn_80391C04(0, 0, 0x411), 3, a0, a1, a2);
}

void fn_800141D8()
{
    fn_80056C9C(0xc6);
    lbl_80624408(fn_80391C04(0, 0, 0x415), 0);
}

void fn_8001422C()
{
    fn_80056C9C(0xc7);
    lbl_80624408(fn_80391C04(0, 0, 0x416), 0);
}

void fn_80014280()
{
    fn_80056C9C(0xdb);
    lbl_80624408(fn_80391C04(0, 0, 0x417), 0);
}

void fn_800142D4()
{
    fn_80056C9C(0x187);
    lbl_80624408(fn_80391C04(0, 0, 0x418), 0);
}

void fn_80014328()
{
    fn_80056C9C(0x133);
    lbl_80624408(fn_80391C04(0, 0, 0x41b), 0);
}

void fn_8001437C()
{
    fn_80056C9C(0x134);
    lbl_80624408(fn_80391C04(0, 0, 0x41c), 0);
}

void fn_800143D0(int a0, int a1)
{
    fn_80056C9C(0x21);
    lbl_80624408(fn_80391C04(0, 0, 0x41d), 2, a0, a1);
}

void fn_80014434()
{
    fn_80056C9C(0x25);
    lbl_80624408(fn_80391C04(0, 0, 0x41e), 0);
}

void fn_80014488(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0xc8);
    lbl_80624408(fn_80391C04(0, 0, 0x41f), 7, a0, a1, a2, a3, a4, a5, a6);
}

void fn_80014514(int a0)
{
    fn_80056C9C(0x131);
    lbl_80624408(fn_80391C04(0, 0, 0x420), 1, a0);
}

void fn_80014570(int a0)
{
    fn_80056C9C(0x14d);
    lbl_80624408(fn_80391C04(0, 0, 0x421), 1, a0);
}

void fn_800145CC(int a0)
{
    fn_80056C9C(0x4b);
    lbl_80624408(fn_80391C04(0, 0, 0x422), 1, a0);
}

void fn_80014628()
{
    fn_80056C9C(0x11d);
    lbl_80624408(fn_80391C04(0, 0, 0x423), 0);
}

void fn_8001467C(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0xba);
    lbl_80624408(fn_80391C04(0, 0, 0x424), 4, a0, a1, a2, a3);
}

void fn_800146F0(int a0, int a1, int a2)
{
    fn_80056C9C(0x165);
    lbl_80624408(fn_80391C04(0, 0, 0x42f), 3, a0, a1, a2);
}

void fn_8001475C(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x43);
    lbl_80624408(fn_80391C04(0, 0, 0x44f), 5, a0, a1, a2, a3, a4);
}
