/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic between cShortestPathChooser and catchgoal.cpp.
 * Original file name unknown; placeholder. 25 functions.
 *
 * .text 0x8027DE3C-0x8027FD64, .rodata 0x805DD134-0x805DD24C, .data 0x8061E6C8-0x8061E6D0.
 */
#include "game/chooser.h"
#include "game/goals/tu_8027DE3C.h"

Unk8027DE3C* Unk8027DE3C::fn_8027DE3C(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b)
{
    mB0 = *a;
    mBC = *b;
    mE8 |= 0x100000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DE88(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b)
{
    mB0 = *a;
    mBC = *b;
    mE8 |= 0x80000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DED4()
{
    fn_8027DDE8(8);
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DF08()
{
    mE8 |= 0x40000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DF1C(int a)
{
    if (a == 1) {
        fn_8027DDE8(0x1B);
        mE8 |= 0x1000;
    } else {
        fn_8027DDE8(0x1A);
    }
    m7C = 2;
    return this;
}

void Unk8027DE3C::fn_8027DF7C()
{
    m7C = 2;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DF88(int a)
{
    mA0 = a;
    m9C = -1;
    mE8 |= 0x4000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DFA8(int a)
{
    mA0 = a;
    m9C = 0;
    return this;
}

void Unk8027DE3C::fn_8027DFBC(int a, const Unk80273498_Vec3* v)
{
    mA4 = *v;
    mE8 |= 0x80000000;
    fn_8027DFA8(a);
}

Unk8027DE3C* Unk8027DE3C::fn_8027E008(int a)
{
    mA0 = a;
    m9C = 1;
    return this;
}

void Unk8027DE3C::fn_8027E01C(int a, const Unk80273498_Vec3* v)
{
    mA4 = *v;
    mE8 |= 0x80000000;
    fn_8027E008(a);
}

void Unk8027DE3C::fn_8027E068(int a)
{
    mA0 = a;
}

Unk8027DE3C* Unk8027DE3C::fn_8027E070(int a)
{
    mE8bits.f8 = a;
    return this;
}
