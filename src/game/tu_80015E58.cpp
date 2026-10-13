/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80015E58-0x80016B40 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
extern "C" unsigned fn_80391C04(unsigned char, unsigned char, unsigned short);

void fn_80015E58(int a0)
{
    fn_80056C9C(0x112);
    lbl_80624408(fn_80391C04(0, 0, 0x543), 1, a0);
}

void fn_80015EB4(int a0)
{
    fn_80056C9C(0x12a);
    lbl_80624408(fn_80391C04(0, 0, 0x544), 1, a0);
}

void fn_80015F10(int a0)
{
    fn_80056C9C(0x11b);
    lbl_80624408(fn_80391C04(0, 0, 0x546), 1, a0);
}

void fn_80015F6C(int a0, int a1)
{
    fn_80056C9C(0x10e);
    lbl_80624408(fn_80391C04(0, 0, 0x547), 2, a0, a1);
}

void fn_80015FD0(int a0, int a1)
{
    fn_80056C9C(0x114);
    lbl_80624408(fn_80391C04(0, 0, 0x549), 2, a0, a1);
}

void fn_80016034(int a0)
{
    fn_80056C9C(0x10f);
    lbl_80624408(fn_80391C04(0, 0, 0x54d), 1, a0);
}

void fn_80016090(int a0, int a1)
{
    fn_80056C9C(0x111);
    lbl_80624408(fn_80391C04(0, 0, 0x550), 2, a0, a1);
}

void fn_800160F4(int a0, int a1, int a2)
{
    fn_80056C9C(0x109);
    lbl_80624408(fn_80391C04(0, 0, 0x552), 3, a0, a1, a2);
}

void fn_80016160(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x110);
    lbl_80624408(fn_80391C04(0, 0, 0x554), 6, a0, a1, a2, a3, a4, a5);
}

void fn_800161E4(int a0, int a1, int a2)
{
    fn_80056C9C(0x10b);
    lbl_80624408(fn_80391C04(0, 0, 0x555), 3, a0, a1, a2);
}

void fn_80016250(int a0)
{
    fn_80056C9C(0x10d);
    lbl_80624408(fn_80391C04(0, 0, 0x556), 1, a0);
}

void fn_800162AC(int a0)
{
    fn_80056C9C(0x108);
    lbl_80624408(fn_80391C04(0, 0, 0x557), 1, a0);
}

void fn_80016308(int a0)
{
    fn_80056C9C(0x10c);
    lbl_80624408(fn_80391C04(0, 0, 0x559), 1, a0);
}

void fn_80016364(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x18b);
    lbl_80624408(fn_80391C04(0, 0, 0x55a), 5, a0, a1, a2, a3, a4);
}

void fn_800163E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    fn_80056C9C(0x176);
    lbl_80624408(fn_80391C04(0, 0, 0x55b), 13, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

void fn_8001649C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    fn_80056C9C(0x17b);
    lbl_80624408(fn_80391C04(0, 0, 0x55c), 10, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

void fn_80016540(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80056C9C(0x1f);
    lbl_80624408(fn_80391C04(0, 0, 0x55e), 7, a0, a1, a2, a3, a4, a5, a6);
}

void fn_800165CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    fn_80056C9C(0x2c);
    lbl_80624408(fn_80391C04(0, 0, 0x55f), 9, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

void fn_80016668(int a0, int a1)
{
    fn_80056C9C(0x38);
    lbl_80624408(fn_80391C04(0, 0, 0x560), 2, a0, a1);
}

void fn_800166CC(int a0)
{
    fn_80056C9C(0x3f);
    lbl_80624408(fn_80391C04(0, 0, 0x561), 1, a0);
}

void fn_80016728(int a0)
{
    fn_80056C9C(0x5c);
    lbl_80624408(fn_80391C04(0, 0, 0x562), 1, a0);
}

void fn_80016784(int a0, int a1)
{
    fn_80056C9C(0x74);
    lbl_80624408(fn_80391C04(0, 0, 0x563), 2, a0, a1);
}

void fn_800167E8(int a0)
{
    fn_80056C9C(0x115);
    lbl_80624408(fn_80391C04(0, 0, 0x564), 1, a0);
}

void fn_80016844(int a0, int a1)
{
    fn_80056C9C(0x19a);
    lbl_80624408(fn_80391C04(0, 0, 0x567), 2, a0, a1);
}

void fn_800168A8(int a0, int a1)
{
    fn_80056C9C(0x19b);
    lbl_80624408(fn_80391C04(0, 0, 0x568), 2, a0, a1);
}

void fn_8001690C(int a0, int a1)
{
    fn_80056C9C(0x19c);
    lbl_80624408(fn_80391C04(0, 0, 0x56b), 2, a0, a1);
}

void fn_80016970(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x36);
    lbl_80624408(fn_80391C04(0, 0, 0x56c), 5, a0, a1, a2, a3, a4);
}

void fn_800169EC(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x37);
    lbl_80624408(fn_80391C04(0, 0, 0x56d), 5, a0, a1, a2, a3, a4);
}

void fn_80016A68(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x3b);
    lbl_80624408(fn_80391C04(0, 0, 0x570), 4, a0, a1, a2, a3);
}

void fn_80016ADC(int a0, int a1)
{
    fn_80056C9C(0x39);
    lbl_80624408(fn_80391C04(0, 0, 0x573), 2, a0, a1);
}
