/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001B190-0x8001BA78 only: every data object is extern by its lbl_ name.
 *
 * The one-line trace wrappers here share the shape described in
 * include/game/tu_800101C0.h (fn_80056C9C(id); then a variadic call through
 * lbl_80624408 with the fn_80391C04(0, 0, line) tag and the argument count).
 */
#include "game/tu_800101C0.h"
#include "game/tu_8001B190.h"

void fn_8001B190(int a, int b, int c)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2012), 3, a, b, c);
}

void fn_8001B1F4(int a, int b, int c)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2013), 3, a, b, c);
}

/* near-miss (all 0-argument wrappers of this shape, K != 0): retail loads the
 * tag arguments as `li r4,0; li r5,LINE; li r3,K` (r5 before r3); the compiler
 * emits r3 before r5. The versions with arguments (mr moves first) match.
 * Tried: argument/return types of fn_80391C04 and lbl_80624408, inline Tag(),
 * unused parameters, a local for the tag. */
void fn_8001B258(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2014), 0);
}

void fn_8001B2A4(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2015), 0);
}

void fn_8001B2F0(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2016), 0);
}

void fn_8001B33C(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2017), 0);
}

void fn_8001B388(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2018), 0);
}

void fn_8001B3D4(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x2019), 0);
}

void fn_8001B420(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x201a), 0);
}

void fn_8001B46C(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x201b), 0);
}

void fn_8001B4B8(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x201c), 0);
}

void fn_8001B504(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x201d), 0);
}

void fn_8001B550(void)
{
    lbl_80624408(fn_80391C04(0x1, 0x0, 0x201f), 0);
}

void fn_8001B59C(void)
{
    lbl_80624408(fn_80391C04(0x7, 0x0, 0xe000), 0);
}

void fn_8001B5E4(void)
{
    lbl_80624408(fn_80391C04(0x7, 0x0, 0xe001), 0);
}

void fn_8001B62C(void)
{
    lbl_80624408(fn_80391C04(0x7, 0x0, 0xe006), 0);
}

void fn_8001B674(int a, int b)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4000), 2, a, b);
}

void fn_8001B6D0(int a, int b, int c, int d)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4001), 4, a, b, c, d);
}

void fn_8001B73C(int a, int b)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4002), 2, a, b);
}

void fn_8001B798(int a, int b)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4004), 2, a, b);
}

void fn_8001B7F4(int a)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4006), 1, a);
}

void fn_8001B848(int a, int b)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4007), 2, a, b);
}

void fn_8001B8A4(int a)
{
    lbl_80624408(fn_80391C04(0x2, 0x0, 0x4008), 1, a);
}

void fn_8001B8F8(int a)
{
    lbl_80624408(fn_80391C04(0x5, 0x0, 0xa002), 1, a);
}

void* fn_8001B950(unsigned n)
{
    Unk8001BA78* a = fn_8001BB7C();
    if (a) {
        return a->fn_vslot1(n, Unk8001B950_Zero3());
    }
    return 0;
}

void fn_8001B9C0(void* p)
{
    Unk8001BA78* a = fn_8001BB7C();
    if (a) {
        a->fn_vslot2(p, 0);
    }
}

void* Unk8001BA78::fn_vslot1(unsigned n, const Unk8001B950_Zero3& z)
{
    return new (m4) char[n];
}

void Unk8001BA78::fn_vslot2(void* p, int x)
{
    delete[] (char*)p;
}

int Unk8001BA78::fn_vslot3()
{
    return 0;
}

int Unk8001BA78::fn_vslot4()
{
    return 0;
}
