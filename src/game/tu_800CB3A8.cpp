/*
 * Game code, .text 0x800CB3A8-0x800CF178 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

void Unk800CD5A4_Obj::fn_800CD5A4()
{
    fn_vslot73(m68, m6C);
}

void Unk800CD5A4_Obj::fn_800CD5E4()
{
    fn_vslot74();
}

void Unk800CD5A4_Obj::fn_800CDA14(int a, int b, int c)
{
    fn_vslot125(a, b, 0, c, 0);
}

void Unk800CD5A4_Obj::fn_800CDA54(int a, int b, int c)
{
    fn_vslot125(a, b, c, 0, 0);
}

extern "C" void fn_800CEBB8()
{
}

void Unk800C7A4C_Group::fn_800CF114(int v)
{
    fn_800C7E38(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot14(v);
}
