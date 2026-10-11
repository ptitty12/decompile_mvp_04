/*
 * Game code, .text 0x800CF178-0x800D1758 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

void Unk800C7A4C_Group::fn_800CF178(int v)
{
    fn_800C7E90(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot16(v);
}

void Unk800C7A4C_Group::fn_800CF1DC(int v)
{
    fn_800C7EBC(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot17(v);
}

void Unk800C7A4C_Group::fn_800CF240(int v)
{
    fn_800C7E64(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot15(v);
}

/* near-miss: retail keeps the null check (mr. / li 0 / beq / mr) on the slot-28 result; every ternary form folds it away */
extern "C" Unk800C7B40_Widget* fn_800CF5AC(Unk800C7B40_Widget* w, const char* a, int b)
{
    Unk800C7B40_Widget* r = w->fn_vslot28(a, b);
    return r ? r : 0;
}

/* near-miss: same null check as fn_800CF5AC (slot 30) */
extern "C" Unk800C7B40_Widget* fn_800CF738(Unk800C7B40_Widget* w, const char* a, int b)
{
    Unk800C7B40_Widget* r = w->fn_vslot30(a, b);
    return r ? r : 0;
}

extern "C" Unk800C7B40_Widget* fn_800CF77C(Unk800C7B40_Widget* w, int a, int b)
{
    return w->fn_vslot31(a, b);
}

extern "C" void fn_800D0D8C()
{
}

extern "C" void fn_800D0D90()
{
}

extern "C" int fn_800D0D94()
{
    return 0;
}

extern "C" void fn_800D1254(Unk800C7B40_Data* w, int v)
{
    fn_800C7E38(w, v);
}

void Unk800D1614_Obj::fn_800D1614(Unk800C7B40_Widget* c)
{
    m48 = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D1654(Unk800C7B40_Widget* c)
{
    m4C = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D1694(Unk800C7B40_Widget* c)
{
    m50 = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D16D4(Unk800C7B40_Widget* c)
{
    m54 = c;
    c->fn_vslot18(m2E);
}

/* near-miss: retail compares with cmpwi cr7,r4,1 then mfcr/extrwi for (v == 1); here xori/subfic/adde */
void Unk800D1614_Obj::fn_800D1714(int v)
{
    m40 = v;
    fn_vslot8(v == 1);
}
