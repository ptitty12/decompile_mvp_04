/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80011950-0x800124C0 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
int fn_80391C04(int, int, int);

void fn_80011950()
{
    fn_80056C9C(0x153);
    lbl_80624408(fn_80391C04(0, 0, 0x359), 0);
}

void fn_800119A4()
{
    fn_80056C9C(0x1b9);
    lbl_80624408(fn_80391C04(0, 0, 0x35a), 0);
}

void fn_800119F8(int a0, int a1, int a2)
{
    fn_80056C9C(0xbb);
    lbl_80624408(fn_80391C04(0, 0, 0x35b), 3, a0, a1, a2);
}

void fn_80011A64(int a0)
{
    fn_80056C9C(0x28);
    lbl_80624408(fn_80391C04(0, 0, 0x35c), 1, a0);
}

void fn_80011AC0()
{
    fn_80056C9C(0x9e);
    lbl_80624408(fn_80391C04(0, 0, 0x35d), 0);
}

void fn_80011B14(int a0, int a1, int a2)
{
    fn_80056C9C(0x182);
    lbl_80624408(fn_80391C04(0, 0, 0x35e), 3, a0, a1, a2);
}

void fn_80011B80(int a0, int a1)
{
    fn_80056C9C(0x2a);
    lbl_80624408(fn_80391C04(0, 0, 0x363), 2, a0, a1);
}

void fn_80011BE4()
{
    fn_80056C9C(0x2e);
    lbl_80624408(fn_80391C04(0, 0, 0x364), 0);
}

void fn_80011C38()
{
    fn_80056C9C(0x23);
    lbl_80624408(fn_80391C04(0, 0, 0x365), 0);
}

void fn_80011C8C(int a0, int a1)
{
    fn_80056C9C(0x45);
    lbl_80624408(fn_80391C04(0, 0, 0x367), 2, a0, a1);
}

void fn_80011CF0(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x13d);
    lbl_80624408(fn_80391C04(0, 0, 0x369), 5, a0, a1, a2, a3, a4);
}

void fn_80011D6C(int a0, int a1, int a2)
{
    fn_80056C9C(0x16f);
    lbl_80624408(fn_80391C04(0, 0, 0x36b), 3, a0, a1, a2);
}

void fn_80011DD8(int a0, int a1)
{
    fn_80056C9C(0x1cc);
    lbl_80624408(fn_80391C04(0, 0, 0x36d), 2, a0, a1);
}

void fn_80011E3C(int a0, int a1, int a2)
{
    fn_80056C9C(0x1d3);
    lbl_80624408(fn_80391C04(0, 0, 0x370), 3, a0, a1, a2);
}

void fn_80011EA8(int a0, int a1)
{
    fn_80056C9C(0x14a);
    lbl_80624408(fn_80391C04(0, 0, 0x371), 2, a0, a1);
}

void fn_80011F0C(int a0, int a1, int a2)
{
    fn_80056C9C(0xb1);
    lbl_80624408(fn_80391C04(0, 0, 0x372), 3, a0, a1, a2);
}

void fn_80011F78()
{
    fn_80056C9C(0x10);
    lbl_80624408(fn_80391C04(0, 0, 0x374), 0);
}

void fn_80011FCC(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x66);
    lbl_80624408(fn_80391C04(0, 0, 0x377), 6, a0, a1, a2, a3, a4, a5);
}

void fn_80012050(int a0)
{
    fn_80056C9C(0x94);
    lbl_80624408(fn_80391C04(0, 0, 0x378), 1, a0);
}

void fn_800120AC(int a0, int a1, int a2)
{
    fn_80056C9C(0x4c);
    lbl_80624408(fn_80391C04(0, 0, 0x379), 3, a0, a1, a2);
}

void fn_80012118(int a0, int a1)
{
    fn_80056C9C(0x53);
    lbl_80624408(fn_80391C04(0, 0, 0x37a), 2, a0, a1);
}

void fn_8001217C(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x7f);
    lbl_80624408(fn_80391C04(0, 0, 0x37d), 4, a0, a1, a2, a3);
}

void fn_800121F0(int a0, int a1)
{
    fn_80056C9C(0x87);
    lbl_80624408(fn_80391C04(0, 0, 0x37e), 2, a0, a1);
}

void fn_80012254()
{
    fn_80056C9C(0x89);
    lbl_80624408(fn_80391C04(0, 0, 0x37f), 0);
}

void fn_800122A8(int a0, int a1, int a2)
{
    fn_80056C9C(0x12c);
    lbl_80624408(fn_80391C04(0, 0, 0x380), 3, a0, a1, a2);
}

void fn_80012314()
{
    fn_80056C9C(0xcc);
    lbl_80624408(fn_80391C04(0, 0, 0x381), 0);
}

void fn_80012368(int a0)
{
    fn_80056C9C(0x155);
    lbl_80624408(fn_80391C04(0, 0, 0x382), 1, a0);
}

void fn_800123C4()
{
    fn_80056C9C(0x156);
    lbl_80624408(fn_80391C04(0, 0, 0x383), 0);
}

void fn_80012418()
{
    fn_80056C9C(0xd9);
    lbl_80624408(fn_80391C04(0, 0, 0x384), 0);
}

void fn_8001246C()
{
    fn_80056C9C(0xb6);
    lbl_80624408(fn_80391C04(0, 0, 0x385), 0);
}
