/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028B194-0x8028C6B8, .rodata 0x805DD6DC-0x805DD754.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028B194.h"

Unk80273498_Vec3 fn_8027AF54(Unk8028B194* g, int a);
Unk80270BA0_X* fn_8027A90C(Unk8028B194* g);
Unk80273498_Vec3 fn_801837F4(int obj, int a);
void fn_8028F5CC(void* p, float f);

Unk8028B194* Unk8028B194::fn_8028B194(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    SetTarget(v);
    m28 = 1;
    return this;
}

Unk8028B194* Unk8028B194::fn_8028B1F0(int a)
{
    m50 = a;
    Unk80273498_Vec3 v = fn_8027AF54(this, a);
    fn_8028B194(v);
    return this;
}

Unk8028B194* Unk8028B194::fn_8028B260(int a, Unk80273498_Vec3* p)
{
    if (p) {
        fn_8028B194(*p);
    } else {
        Unk8028B194_Ctx* ctx = (Unk8028B194_Ctx*)fn_8027A90C(this)->m44C;
        Unk80273498_Vec3 v = fn_801837F4(ctx->m6B8, a);
        fn_8028B194(v);
    }
    return this;
}

Unk8028B194* Unk8028B194::fn_8028B308()
{
    mA8 |= 0x4000000;
    return this;
}

void Unk8028B194::fn_8028B31C(int id)
{
    m4C = id;
}

void Unk8028B194::fn_8028B324(int id)
{
    switch (id) {
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        break;
    default:
        id = 11;
        break;
    }
    fn_8028B31C(id);
}

void Unk8028B194::fn_8028B358()
{
    fn_8028B31C(0x11);
}

void Unk8028B194::fn_8028B37C()
{
    fn_8028B31C(9);
}

void Unk8028B194::fn_8028B3A0()
{
    fn_8028B31C(4);
}

Unk8028B194* Unk8028B194::fn_8028B3C4()
{
    mA8 |= 0x8000;
    return this;
}

void Unk8028B194::fn_8028B3D8()
{
    fn_8028B31C(2);
}

void Unk8028B194::fn_8028B3FC()
{
    fn_8028B31C(0x16);
}

void Unk8028B194::fn_8028B420()
{
    fn_8028B31C(0x17);
}

void Unk8028B194::fn_8028B444()
{
    fn_8028B31C(1);
}

void Unk8028B194::fn_8028B468()
{
    fn_8028B31C(3);
}

void Unk8028B194::fn_8028B48C(float a)
{
    if (!(a <= 0.0f)) {
        m70 = a;
        mA8 |= 0x100000;
    } else {
        mA8 &= ~0x100000;
    }
}

void Unk8028B194::fn_8028B4D0(float a)
{
    if (!(a <= 0.0f)) {
        m70 = a;
        mA8 |= 0x180000;
    } else {
        mA8 &= ~0x100000;
    }
}

void Unk8028B194::fn_8028B514(int a)
{
    m78 = a;
}

Unk8028B194* Unk8028B194::fn_8028B51C(float a)
{
    mA8 |= 0x20000000;
    m74 = a;
    fn_8028F5CC(m4, a);
    return this;
}
