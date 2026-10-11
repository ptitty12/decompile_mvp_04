/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800147D8-0x80015388 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
int fn_80391C04(int, int, int);

void fn_800147D8(int a0)
{
    fn_80056C9C(0xf3);
    lbl_80624408(fn_80391C04(0, 0, 0x464), 1, a0);
}

void fn_80014834(int a0)
{
    fn_80056C9C(0x1d);
    lbl_80624408(fn_80391C04(0, 0, 0x466), 1, a0);
}

void fn_80014890(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0x90);
    lbl_80624408(fn_80391C04(0, 0, 0x468), 6, a0, a1, a2, a3, a4, a5);
}

void fn_80014914(int a0, int a1)
{
    fn_80056C9C(0xaf);
    lbl_80624408(fn_80391C04(0, 0, 0x469), 2, a0, a1);
}

void fn_80014978()
{
    fn_80056C9C(0x12d);
    lbl_80624408(fn_80391C04(0, 0, 0x46b), 0);
}

void fn_800149CC()
{
    fn_80056C9C(0x132);
    lbl_80624408(fn_80391C04(0, 0, 0x46c), 0);
}

void fn_80014A20(int a0)
{
    fn_80056C9C(0x178);
    lbl_80624408(fn_80391C04(0, 0, 0x46d), 1, a0);
}

void fn_80014A7C(int a0, int a1, int a2, int a3, int a4, int a5)
{
    fn_80056C9C(0xe7);
    lbl_80624408(fn_80391C04(0, 0, 0x46f), 6, a0, a1, a2, a3, a4, a5);
}

void fn_80014B00()
{
    fn_80056C9C(0x125);
    lbl_80624408(fn_80391C04(0, 0, 0x472), 0);
}

void fn_80014B54()
{
    fn_80056C9C(0x12f);
    lbl_80624408(fn_80391C04(0, 0, 0x473), 0);
}

void fn_80014BA8()
{
    fn_80056C9C(0x130);
    lbl_80624408(fn_80391C04(0, 0, 0x474), 0);
}

void fn_80014BFC(int a0)
{
    fn_80056C9C(0x5e);
    lbl_80624408(fn_80391C04(0, 0, 0x475), 1, a0);
}

void fn_80014C58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    fn_80056C9C(0x20);
    lbl_80624408(fn_80391C04(0, 0, 0x478), 12, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

void fn_80014D0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    fn_80056C9C(0x177);
    lbl_80624408(fn_80391C04(0, 0, 0x47c), 14, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}

void fn_80014DD0()
{
    fn_80056C9C(0x5b);
    lbl_80624408(fn_80391C04(0, 0, 0x47e), 0);
}

void fn_80014E24(int a0)
{
    fn_80056C9C(0xef);
    lbl_80624408(fn_80391C04(0, 0, 0x480), 1, a0);
}

void fn_80014E80()
{
    fn_80056C9C(0xe4);
    lbl_80624408(fn_80391C04(0, 0, 0x48a), 0);
}

void fn_80014ED4()
{
    fn_80056C9C(0x35);
    lbl_80624408(fn_80391C04(0, 0, 0x48b), 0);
}

void fn_80014F28()
{
    fn_80056C9C(0xbe);
    lbl_80624408(fn_80391C04(0, 0, 0x48c), 0);
}

void fn_80014F7C()
{
    fn_80056C9C(0x4e);
    lbl_80624408(fn_80391C04(0, 0, 0x48d), 0);
}

void fn_80014FD0(int a0)
{
    fn_80056C9C(0x58);
    lbl_80624408(fn_80391C04(0, 0, 0x491), 1, a0);
}

void fn_8001502C(int a0, int a1)
{
    fn_80056C9C(0x59);
    lbl_80624408(fn_80391C04(0, 0, 0x492), 2, a0, a1);
}

void fn_80015090()
{
    fn_80056C9C(0x1c0);
    lbl_80624408(fn_80391C04(0, 0, 0x494), 0);
}

void fn_800150E4(int a0)
{
    fn_80056C9C(0x1bf);
    lbl_80624408(fn_80391C04(0, 0, 0x495), 1, a0);
}

void fn_80015140(int a0, int a1)
{
    fn_80056C9C(0x6f);
    lbl_80624408(fn_80391C04(0, 0, 0x496), 2, a0, a1);
}

void fn_800151A4(int a0)
{
    fn_80056C9C(0x70);
    lbl_80624408(fn_80391C04(0, 0, 0x497), 1, a0);
}

void fn_80015200(int a0)
{
    fn_80056C9C(0x71);
    lbl_80624408(fn_80391C04(0, 0, 0x498), 1, a0);
}

void fn_8001525C()
{
    fn_80056C9C(0xe0);
    lbl_80624408(fn_80391C04(0, 0, 0x49b), 0);
}

void fn_800152B0(int a0, int a1, int a2)
{
    fn_80056C9C(0x11a);
    lbl_80624408(fn_80391C04(0, 0, 0x49c), 3, a0, a1, a2);
}

void fn_8001531C(int a0, int a1, int a2)
{
    fn_80056C9C(0x17f);
    lbl_80624408(fn_80391C04(0, 0, 0x49e), 3, a0, a1, a2);
}
