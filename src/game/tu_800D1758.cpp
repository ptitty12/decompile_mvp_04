/*
 * Game code, .text 0x800D1758-0x800D4D0C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern int lbl_8061A328;

void Unk800D238C_Obj::fn_800D238C(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E38(this, v);
}

void Unk800D238C_Obj::fn_800D23BC(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E64(this, v);
}

void Unk800D238C_Obj::fn_800D23EC(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E0C(this, v);
}

void Unk800D238C_Obj::fn_800D241C(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E90(this, v);
}

void Unk800D238C_Obj::fn_800D244C(const Unk800D244C_Vec4& v)
{
    m6C = v;
}

void Unk800D238C_Obj::fn_800D2474(int v)
{
    m5C = lbl_8061A328;
    fn_800C7EBC(this, v);
}

extern "C" void fn_800D2CD8(Unk800D2CD8_Obj* o, int i, int v)
{
    o->m17C[i] = v;
}

extern "C" int fn_800D2CE8(Unk800D2CD8_Obj* o, int i)
{
    return o->m17C[i];
}

extern "C" void fn_800D3164()
{
}

extern "C" int fn_800D4578()
{
    return 0;
}

extern "C" void fn_800D4B88(Unk800D4B88_Obj* o, int a, int c)
{
    o->b0 = a;
    o->m84 = c;
}
