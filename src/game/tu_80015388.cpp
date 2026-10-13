/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80015388-0x80015E58 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
extern "C" unsigned fn_80391C04(unsigned char, unsigned char, unsigned short);

void fn_80015388()
{
    fn_80056C9C(0x15b);
    lbl_80624408(fn_80391C04(0, 0, 0x49f), 0);
}

void fn_800153DC()
{
    fn_80056C9C(0x120);
    lbl_80624408(fn_80391C04(0, 0, 0x4a1), 0);
}

void fn_80015430()
{
    fn_80056C9C(0x11f);
    lbl_80624408(fn_80391C04(0, 0, 0x4a2), 0);
}

void fn_80015484(int a0)
{
    fn_80056C9C(0x78);
    lbl_80624408(fn_80391C04(0, 0, 0x4a6), 1, a0);
}

void fn_800154E0()
{
    fn_80056C9C(0x22);
    lbl_80624408(fn_80391C04(0, 0, 0x4a9), 0);
}

void fn_80015534(int a0)
{
    fn_80056C9C(0xec);
    lbl_80624408(fn_80391C04(0, 0, 0x4ab), 1, a0);
}

void fn_80015590(int a0, int a1, int a2)
{
    fn_80056C9C(0xc9);
    lbl_80624408(fn_80391C04(0, 0, 0x4c6), 3, a0, a1, a2);
}

void fn_800155FC(int a0)
{
    fn_80056C9C(0x15e);
    lbl_80624408(fn_80391C04(0, 0, 0x4c7), 1, a0);
}

void fn_80015658()
{
    fn_80056C9C(0x15d);
    lbl_80624408(fn_80391C04(0, 0, 0x4c8), 0);
}

void fn_800156AC()
{
    fn_80056C9C(0x15c);
    lbl_80624408(fn_80391C04(0, 0, 0x4c9), 0);
}

void fn_80015700(int a0, int a1)
{
    fn_80056C9C(0xd0);
    lbl_80624408(fn_80391C04(0, 0, 0x4cd), 2, a0, a1);
}

void fn_80015764(int a0, int a1)
{
    fn_80056C9C(0x1d4);
    lbl_80624408(fn_80391C04(0, 0, 0x4ce), 2, a0, a1);
}

void fn_800157C8(int a0, int a1)
{
    fn_80056C9C(0x1d5);
    lbl_80624408(fn_80391C04(0, 0, 0x4cf), 2, a0, a1);
}

void fn_8001582C()
{
    fn_80056C9C(0x13c);
    lbl_80624408(fn_80391C04(0, 0, 0x4d2), 0);
}

void fn_80015880(int a0, int a1)
{
    fn_80056C9C(0x61);
    lbl_80624408(fn_80391C04(0, 0, 0x4d3), 2, a0, a1);
}

void fn_800158E4()
{
    fn_80056C9C(0x6d);
    lbl_80624408(fn_80391C04(0, 0, 0x4d8), 0);
}

void fn_80015938(int a0)
{
    fn_80056C9C(0x148);
    lbl_80624408(fn_80391C04(0, 0, 0x4d9), 1, a0);
}

void fn_80015994(int a0, int a1, int a2)
{
    fn_80056C9C(0xbd);
    lbl_80624408(fn_80391C04(0, 0, 0x4db), 3, a0, a1, a2);
}

void fn_80015A00(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x198);
    lbl_80624408(fn_80391C04(0, 0, 0x4df), 5, a0, a1, a2, a3, a4);
}

void fn_80015A7C()
{
    fn_80056C9C(0x197);
    lbl_80624408(fn_80391C04(0, 0, 0x4e4), 0);
}

void fn_80015AD0(int a0)
{
    fn_80056C9C(0xad);
    lbl_80624408(fn_80391C04(0, 0, 0x4e7), 1, a0);
}

void fn_80015B2C(int a0)
{
    fn_80056C9C(0x6c);
    lbl_80624408(fn_80391C04(0, 0, 0x4e8), 1, a0);
}

void fn_80015B88()
{
    fn_80056C9C(0x24);
    lbl_80624408(fn_80391C04(0, 0, 0x4eb), 0);
}

void fn_80015BDC()
{
    fn_80056C9C(0x27);
    lbl_80624408(fn_80391C04(0, 0, 0x4ed), 0);
}

void fn_80015C30()
{
    fn_80056C9C(0x103);
    lbl_80624408(fn_80391C04(0, 0, 0x4f8), 0);
}

void fn_80015C84(int a0)
{
    fn_80056C9C(0xf9);
    lbl_80624408(fn_80391C04(0, 0, 0x512), 1, a0);
}

void fn_80015CE0(int a0, int a1)
{
    fn_80056C9C(0xff);
    lbl_80624408(fn_80391C04(0, 0, 0x534), 2, a0, a1);
}

void fn_80015D44(int a0)
{
    fn_80056C9C(0x77);
    lbl_80624408(fn_80391C04(0, 0, 0x53e), 1, a0);
}

void fn_80015DA0(int a0)
{
    fn_80056C9C(0x107);
    lbl_80624408(fn_80391C04(0, 0, 0x540), 1, a0);
}

void fn_80015DFC(int a0)
{
    fn_80056C9C(0x113);
    lbl_80624408(fn_80391C04(0, 0, 0x542), 1, a0);
}
