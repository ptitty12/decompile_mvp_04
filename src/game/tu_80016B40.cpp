/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80016B40-0x800175F8 only: every data object is extern by its lbl_ name.
 *
 * Trace wrappers: each calls fn_80056C9C(K), builds a tag word with
 * fn_80391C04(0, 0, C) and passes it to the function pointer at 0x80624408
 * together with the argument count and the wrapper's own arguments
 * (variadic call: crclr cr1eq).
 */

extern int (*lbl_80624408)(int, int, ...);
void fn_80056C9C(int);
int fn_80391C04(int, int, int);

void fn_80016B40(int a0, int a1)
{
    fn_80056C9C(0x3a);
    lbl_80624408(fn_80391C04(0, 0, 0x575), 2, a0, a1);
}

void fn_80016BA4(int a0, int a1)
{
    fn_80056C9C(0x3c);
    lbl_80624408(fn_80391C04(0, 0, 0x57a), 2, a0, a1);
}

void fn_80016C08(int a0, int a1)
{
    fn_80056C9C(0x3d);
    lbl_80624408(fn_80391C04(0, 0, 0x57c), 2, a0, a1);
}

void fn_80016C6C(int a0, int a1)
{
    fn_80056C9C(0x3e);
    lbl_80624408(fn_80391C04(0, 0, 0x57e), 2, a0, a1);
}

void fn_80016CD0(int a0, int a1, int a2, int a3)
{
    fn_80056C9C(0x46);
    lbl_80624408(fn_80391C04(0, 0, 0x582), 4, a0, a1, a2, a3);
}

void fn_80016D44(int a0, int a1, int a2, int a3, int a4)
{
    fn_80056C9C(0x47);
    lbl_80624408(fn_80391C04(0, 0, 0x583), 5, a0, a1, a2, a3, a4);
}

void fn_80016DC0(int a0)
{
    fn_80056C9C(0x9d);
    lbl_80624408(fn_80391C04(0, 0, 0x586), 1, a0);
}

void fn_80016E1C(int a0)
{
    fn_80056C9C(0x1a7);
    lbl_80624408(fn_80391C04(0, 0, 0x587), 1, a0);
}

void fn_80016E78(int a0)
{
    fn_80056C9C(0xed);
    lbl_80624408(fn_80391C04(0, 0, 0x588), 1, a0);
}

void fn_80016ED4(int a0)
{
    fn_80056C9C(0x32);
    lbl_80624408(fn_80391C04(0, 0, 0x589), 1, a0);
}

void fn_80016F30()
{
    fn_80056C9C(0x1d1);
    lbl_80624408(fn_80391C04(0, 0, 0x58b), 0);
}

void fn_80016F84()
{
    fn_80056C9C(0x127);
    lbl_80624408(fn_80391C04(0, 0, 0x58d), 0);
}

void fn_80016FD8()
{
    fn_80056C9C(0x13f);
    lbl_80624408(fn_80391C04(0, 0, 0x58e), 0);
}

void fn_8001702C(int a0)
{
    fn_80056C9C(0x129);
    lbl_80624408(fn_80391C04(0, 0, 0x58f), 1, a0);
}

void fn_80017088()
{
    fn_80056C9C(0x128);
    lbl_80624408(fn_80391C04(0, 0, 0x590), 0);
}

void fn_800170DC()
{
    fn_80056C9C(0x1a8);
    lbl_80624408(fn_80391C04(0, 0, 0x591), 0);
}

void fn_80017130()
{
    fn_80056C9C(0x30);
    lbl_80624408(fn_80391C04(0, 0, 0x597), 0);
}

void fn_80017184(int a0, int a1)
{
    fn_80056C9C(0xf6);
    lbl_80624408(fn_80391C04(0, 0, 0x598), 2, a0, a1);
}

void fn_800171E8(int a0)
{
    fn_80056C9C(0xac);
    lbl_80624408(fn_80391C04(0, 0, 0x59b), 1, a0);
}

void fn_80017244()
{
    fn_80056C9C(0x1b4);
    lbl_80624408(fn_80391C04(0, 0, 0x59d), 0);
}

void fn_80017298()
{
    fn_80056C9C(0x1b3);
    lbl_80624408(fn_80391C04(0, 0, 0x59e), 0);
}

void fn_800172EC()
{
    fn_80056C9C(0x1b5);
    lbl_80624408(fn_80391C04(0, 0, 0x59f), 0);
}

void fn_80017340()
{
    fn_80056C9C(0x119);
    lbl_80624408(fn_80391C04(0, 0, 0x5a0), 0);
}

void fn_80017394()
{
    fn_80056C9C(0x118);
    lbl_80624408(fn_80391C04(0, 0, 0x5a1), 0);
}

void fn_800173E8(int a0)
{
    fn_80056C9C(0xeb);
    lbl_80624408(fn_80391C04(0, 0, 0x5a3), 1, a0);
}

void fn_80017444()
{
    fn_80056C9C(0xa0);
    lbl_80624408(fn_80391C04(0, 0, 0x5a4), 0);
}

void fn_80017498()
{
    fn_80056C9C(0x9f);
    lbl_80624408(fn_80391C04(0, 0, 0x5a5), 0);
}

void fn_800174EC()
{
    fn_80056C9C(0x149);
    lbl_80624408(fn_80391C04(0, 0, 0x5a7), 0);
}

void fn_80017540()
{
    fn_80056C9C(0xf4);
    lbl_80624408(fn_80391C04(0, 0, 0x5a8), 0);
}

void fn_80017594(int a0, int a1)
{
    fn_80056C9C(0xa9);
    lbl_80624408(fn_80391C04(0, 0, 0x5ae), 2, a0, a1);
}
