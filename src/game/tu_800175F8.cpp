/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800175F8-0x80018310 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
extern "C" unsigned fn_80391C04(unsigned char, unsigned char, unsigned short);

void fn_800175F8()
{
    fn_80056C9C(0x17d);
    lbl_80624408(fn_80391C04(0, 0, 0x5af), 0);
}

void fn_8001764C()
{
    fn_80056C9C(0x159);
    lbl_80624408(fn_80391C04(0, 0, 0x5b0), 0);
}

void fn_800176A0()
{
    fn_80056C9C(0x15a);
    lbl_80624408(fn_80391C04(0, 0, 0x5b1), 0);
}

void fn_800176F4()
{
    fn_80056C9C(0x33);
    lbl_80624408(fn_80391C04(0, 0, 0x5b3), 0);
}

void fn_80017748()
{
    fn_80056C9C(0x180);
    lbl_80624408(fn_80391C04(0, 0, 0x5b4), 0);
}

void fn_8001779C(int a0)
{
    fn_80056C9C(0x49);
    lbl_80624408(fn_80391C04(0, 0, 0x5b5), 1, a0);
}

void fn_800177F8()
{
    fn_80056C9C(0xa1);
    lbl_80624408(fn_80391C04(0, 0, 0x5b6), 0);
}

void fn_8001784C()
{
    fn_80056C9C(0xdc);
    lbl_80624408(fn_80391C04(0, 0, 0x5b7), 0);
}

void fn_800178A0(int a0, int a1)
{
    fn_80056C9C(0x0);
    lbl_80624408(fn_80391C04(0, 0, 0x5ba), 2, a0, a1);
}

void fn_80017904(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0xf2);
    lbl_80624408(fn_80391C04(0, 0, 0x5be), 4, a0, a1, a2, a3);
}

void fn_80017978(int a0, int a1, int a2)
{
    fn_80056C9C(0xc2);
    lbl_80624408(fn_80391C04(0, 0, 0x5c0), 3, a0, a1, a2);
}

void fn_800179E4(int a0, int a1, int a2)
{
    fn_80056C9C(0xa8);
    lbl_80624408(fn_80391C04(0, 0, 0x5c1), 3, a0, a1, a2);
}

void fn_80017A50()
{
    fn_80056C9C(0x1cf);
    lbl_80624408(fn_80391C04(0, 0, 0x5c5), 0);
}

void fn_80017AA4(int a0, int a1)
{
    fn_80056C9C(0x1cd);
    lbl_80624408(fn_80391C04(0, 0, 0x5c6), 2, a0, a1);
}

void fn_80017B08(int a0, int a1, int a2)
{
    fn_80056C9C(0xd6);
    lbl_80624408(fn_80391C04(0, 0, 0x5cc), 3, a0, a1, a2);
}

void fn_80017B74(int a0, int a1)
{
    fn_80056C9C(0x8e);
    lbl_80624408(fn_80391C04(0, 0, 0x5ce), 2, a0, a1);
}

void fn_80017BD8()
{
    fn_80056C9C(0xf1);
    lbl_80624408(fn_80391C04(0, 0, 0x5d2), 0);
}

void fn_80017C2C()
{
    fn_80056C9C(0x31);
    lbl_80624408(fn_80391C04(0, 0, 0x639), 0);
}

void fn_80017C80()
{
    fn_80056C9C(0x4f);
    lbl_80624408(fn_80391C04(0, 0, 0x63a), 0);
}

void fn_80017CD4(int a0, int a1)
{
    fn_80056C9C(0xa7);
    lbl_80624408(fn_80391C04(0, 0, 0x63c), 2, a0, a1);
}

void fn_80017D38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    fn_80056C9C(0x1e);
    lbl_80624408(fn_80391C04(0, 0, 0x63d), 12, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

void fn_80017DEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    fn_80056C9C(0x175);
    lbl_80624408(fn_80391C04(0, 0, 0x63e), 14, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}

void fn_80017EB0(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x183);
    lbl_80624408(fn_80391C04(0, 0, 0x640), 6, a0, a1, a2, a3, a4, a5);
}

void fn_80017F34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    fn_80056C9C(0xe6);
    lbl_80624408(fn_80391C04(0, 0, 0x641), 8, a0, a1, a2, a3, a4, a5, a6, a7);
}

void fn_80017FC8(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0xe5);
    lbl_80624408(fn_80391C04(0, 0, 0x642), 5, a0, a1, a2, a3, a4);
}

void fn_80018044(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0xe9);
    lbl_80624408(fn_80391C04(0, 0, 0x644), 7, a0, a1, a2, a3, a4, a5, a6);
}

void fn_800180D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    fn_80056C9C(0xea);
    lbl_80624408(fn_80391C04(0, 0, 0x645), 11, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

void fn_8001817C(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0xe8);
    lbl_80624408(fn_80391C04(0, 0, 0x646), 5, a0, a1, a2, a3, a4);
}

void fn_800181F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0x2b);
    lbl_80624408(fn_80391C04(0, 0, 0x647), 7, a0, a1, a2, a3, a4, a5, a6);
}

void fn_80018284(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0x17a);
    lbl_80624408(fn_80391C04(0, 0, 0x648), 7, a0, a1, a2, a3, a4, a5, a6);
}
