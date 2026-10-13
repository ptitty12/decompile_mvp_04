/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80010E38-0x80011950 only: every data object is extern by its lbl_ name.
 *
 * Thirty one-line trace wrappers, the same shape as the ones in
 * tu_8000F598.cpp: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
extern "C" unsigned fn_80391C04(unsigned char, unsigned char, unsigned short);

void fn_80010E38()
{
    fn_80056C9C(0x1c8);
    lbl_80624408(fn_80391C04(0, 0, 0x316), 0);
}

void fn_80010E8C()
{
    fn_80056C9C(0x1c5);
    lbl_80624408(fn_80391C04(0, 0, 0x317), 0);
}

void fn_80010EE0(int a0)
{
    fn_80056C9C(0x1c9);
    lbl_80624408(fn_80391C04(0, 0, 0x319), 1, a0);
}

void fn_80010F3C(int a0, int a1)
{
    fn_80056C9C(0x1ba);
    lbl_80624408(fn_80391C04(0, 0, 0x31c), 2, a0, a1);
}

void fn_80010FA0(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x7e);
    lbl_80624408(fn_80391C04(0, 0, 0x31e), 5, a0, a1, a2, a3, a4);
}

void fn_8001101C(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x1ac);
    lbl_80624408(fn_80391C04(0, 0, 0x32d), 4, a0, a1, a2, a3);
}

void fn_80011090(int a0)
{
    fn_80056C9C(0xcd);
    lbl_80624408(fn_80391C04(0, 0, 0x331), 1, a0);
}

void fn_800110EC(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0xaa);
    lbl_80624408(fn_80391C04(0, 0, 0x332), 4, a0, a1, a2, a3);
}

void fn_80011160(int a0)
{
    fn_80056C9C(0x26);
    lbl_80624408(fn_80391C04(0, 0, 0x333), 1, a0);
}

void fn_800111BC(int a0)
{
    fn_80056C9C(0x185);
    lbl_80624408(fn_80391C04(0, 0, 0x33e), 1, a0);
}

void fn_80011218()
{
    fn_80056C9C(0x167);
    lbl_80624408(fn_80391C04(0, 0, 0x33f), 0);
}

void fn_8001126C(int a0)
{
    fn_80056C9C(0x147);
    lbl_80624408(fn_80391C04(0, 0, 0x340), 1, a0);
}

void fn_800112C8(int a0)
{
    fn_80056C9C(0x139);
    lbl_80624408(fn_80391C04(0, 0, 0x342), 1, a0);
}

void fn_80011324()
{
    fn_80056C9C(0x8c);
    lbl_80624408(fn_80391C04(0, 0, 0x343), 0);
}

void fn_80011378(int a0)
{
    fn_80056C9C(0x19e);
    lbl_80624408(fn_80391C04(0, 0, 0x345), 1, a0);
}

void fn_800113D4(int a0)
{
    fn_80056C9C(0xa6);
    lbl_80624408(fn_80391C04(0, 0, 0x346), 1, a0);
}

void fn_80011430(int a0)
{
    fn_80056C9C(0x101);
    lbl_80624408(fn_80391C04(0, 0, 0x347), 1, a0);
}

void fn_8001148C()
{
    fn_80056C9C(0x9a);
    lbl_80624408(fn_80391C04(0, 0, 0x348), 0);
}

void fn_800114E0()
{
    fn_80056C9C(0x122);
    lbl_80624408(fn_80391C04(0, 0, 0x349), 0);
}

void fn_80011534()
{
    fn_80056C9C(0x121);
    lbl_80624408(fn_80391C04(0, 0, 0x34a), 0);
}

void fn_80011588(int a0)
{
    fn_80056C9C(0x84);
    lbl_80624408(fn_80391C04(0, 0, 0x34c), 1, a0);
}

void fn_800115E4(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x154);
    lbl_80624408(fn_80391C04(0, 0, 0x34d), 4, a0, a1, a2, a3);
}

void fn_80011658(int a0, int a1)
{
    fn_80056C9C(0xd3);
    lbl_80624408(fn_80391C04(0, 0, 0x34e), 2, a0, a1);
}

void fn_800116BC(int a0)
{
    fn_80056C9C(0xae);
    lbl_80624408(fn_80391C04(0, 0, 0x350), 1, a0);
}

void fn_80011718()
{
    fn_80056C9C(0xda);
    lbl_80624408(fn_80391C04(0, 0, 0x351), 0);
}

void fn_8001176C(int a0)
{
    fn_80056C9C(0xcf);
    lbl_80624408(fn_80391C04(0, 0, 0x353), 1, a0);
}

void fn_800117C8(int a0, int a1)
{
    fn_80056C9C(0xc1);
    lbl_80624408(fn_80391C04(0, 0, 0x354), 2, a0, a1);
}

void fn_8001182C(int a0, int a1)
{
    fn_80056C9C(0xca);
    lbl_80624408(fn_80391C04(0, 0, 0x356), 2, a0, a1);
}

void fn_80011890()
{
    fn_80056C9C(0xcb);
    lbl_80624408(fn_80391C04(0, 0, 0x357), 0);
}

void fn_800118E4(int a0, int a1, int a2)
{
    fn_80056C9C(0x83);
    lbl_80624408(fn_80391C04(0, 0, 0x358), 3, a0, a1, a2);
}
