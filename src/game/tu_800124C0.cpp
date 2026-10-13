/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800124C0-0x80013078 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
extern "C" unsigned fn_80391C04(unsigned char, unsigned char, unsigned short);

void fn_800124C0(int a0)
{
    fn_80056C9C(0xb7);
    lbl_80624408(fn_80391C04(0, 0, 0x386), 1, a0);
}

void fn_8001251C(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x1b8);
    lbl_80624408(fn_80391C04(0, 0, 0x387), 6, a0, a1, a2, a3, a4, a5);
}

void fn_800125A0()
{
    fn_80056C9C(0x1bc);
    lbl_80624408(fn_80391C04(0, 0, 0x388), 0);
}

void fn_800125F4()
{
    fn_80056C9C(0xde);
    lbl_80624408(fn_80391C04(0, 0, 0x389), 0);
}

void fn_80012648(int a0)
{
    fn_80056C9C(0x2f);
    lbl_80624408(fn_80391C04(0, 0, 0x38a), 1, a0);
}

void fn_800126A4(int a0, int a1)
{
    fn_80056C9C(0x6a);
    lbl_80624408(fn_80391C04(0, 0, 0x38b), 2, a0, a1);
}

void fn_80012708(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x8b);
    lbl_80624408(fn_80391C04(0, 0, 0x38d), 5, a0, a1, a2, a3, a4);
}

void fn_80012784(int a0)
{
    fn_80056C9C(0x170);
    lbl_80624408(fn_80391C04(0, 0, 0x38e), 1, a0);
}

void fn_800127E0()
{
    fn_80056C9C(0xe1);
    lbl_80624408(fn_80391C04(0, 0, 0x38f), 0);
}

void fn_80012834()
{
    fn_80056C9C(0x12e);
    lbl_80624408(fn_80391C04(0, 0, 0x390), 0);
}

void fn_80012888(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x97);
    lbl_80624408(fn_80391C04(0, 0, 0x392), 4, a0, a1, a2, a3);
}

void fn_800128FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0x18c);
    lbl_80624408(fn_80391C04(0, 0, 0x393), 7, a0, a1, a2, a3, a4, a5, a6);
}

void fn_80012988()
{
    fn_80056C9C(0x1b2);
    lbl_80624408(fn_80391C04(0, 0, 0x394), 0);
}

void fn_800129DC(int a0, int a1)
{
    fn_80056C9C(0x169);
    lbl_80624408(fn_80391C04(0, 0, 0x395), 2, a0, a1);
}

void fn_80012A40(int a0, int a1, int a2)
{
    fn_80056C9C(0x16b);
    lbl_80624408(fn_80391C04(0, 0, 0x397), 3, a0, a1, a2);
}

void fn_80012AAC()
{
    fn_80056C9C(0x16a);
    lbl_80624408(fn_80391C04(0, 0, 0x398), 0);
}

void fn_80012B00(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0x1af);
    lbl_80624408(fn_80391C04(0, 0, 0x399), 7, a0, a1, a2, a3, a4, a5, a6);
}

void fn_80012B8C(int a0, int a1)
{
    fn_80056C9C(0x1ab);
    lbl_80624408(fn_80391C04(0, 0, 0x39b), 2, a0, a1);
}

void fn_80012BF0(int a0)
{
    fn_80056C9C(0x1a9);
    lbl_80624408(fn_80391C04(0, 0, 0x39c), 1, a0);
}

void fn_80012C4C()
{
    fn_80056C9C(0x1ad);
    lbl_80624408(fn_80391C04(0, 0, 0x39d), 0);
}

void fn_80012CA0(int a0)
{
    fn_80056C9C(0x181);
    lbl_80624408(fn_80391C04(0, 0, 0x39e), 1, a0);
}

void fn_80012CFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    fn_80056C9C(0x184);
    lbl_80624408(fn_80391C04(0, 0, 0x3a0), 10, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

void fn_80012DA0()
{
    fn_80056C9C(0x189);
    lbl_80624408(fn_80391C04(0, 0, 0x3a3), 0);
}

void fn_80012DF4()
{
    fn_80056C9C(0x188);
    lbl_80624408(fn_80391C04(0, 0, 0x3a4), 0);
}

void fn_80012E48(int a0, int a1)
{
    fn_80056C9C(0x186);
    lbl_80624408(fn_80391C04(0, 0, 0x3a5), 2, a0, a1);
}

void fn_80012EAC(int a0)
{
    fn_80056C9C(0x1c4);
    lbl_80624408(fn_80391C04(0, 0, 0x3ab), 1, a0);
}

void fn_80012F08(int a0)
{
    fn_80056C9C(0x1c3);
    lbl_80624408(fn_80391C04(0, 0, 0x3ac), 1, a0);
}

void fn_80012F64(int a0, int a1)
{
    fn_80056C9C(0x1cb);
    lbl_80624408(fn_80391C04(0, 0, 0x3ad), 2, a0, a1);
}

void fn_80012FC8(int a0)
{
    fn_80056C9C(0x17e);
    lbl_80624408(fn_80391C04(0, 0, 0x3ae), 1, a0);
}

void fn_80013024()
{
    fn_80056C9C(0x171);
    lbl_80624408(fn_80391C04(0, 0, 0x3b1), 0);
}
