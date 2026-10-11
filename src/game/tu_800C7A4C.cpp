/*
 * Game code, .text 0x800C7A4C-0x800CB3A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

void Unk800C7A4C_Group::fn_800C7A4C(int v)
{
    m2A = v;
    if (m40 != 0)
        m40->fn_vslot12(v);
    if (m44 != 0)
        m44->fn_vslot12(v);
    if (m48 != 0)
        m48->fn_vslot12(v);
    if (m4C != 0)
        m4C->fn_vslot12(v);
    if (m50 != 0)
        m50->fn_vslot12(v);
}

extern "C" void fn_800C7E0C(Unk800C7B40_Data* w, int v)
{
    if (w->b0 != v)
        lbl_8061A330 = 1;
    w->b0 = v;
}

extern "C" void fn_800C7E38(Unk800C7B40_Data* w, int v)
{
    if (w->b3 != v)
        lbl_8061A330 = 1;
    w->b3 = v;
}

extern "C" void fn_800C7E64(Unk800C7B40_Data* w, int v)
{
    if (w->b4 != v)
        lbl_8061A330 = 1;
    w->b4 = v;
}

extern "C" void fn_800C7E90(Unk800C7B40_Data* w, int v)
{
    if (w->b1 != v)
        lbl_8061A330 = 1;
    w->b1 = v;
}

extern "C" void fn_800C7EBC(Unk800C7B40_Data* w, int v)
{
    if (w->b2 != v)
        lbl_8061A330 = 1;
    w->b2 = v;
}

extern "C" void fn_800C8010(Unk800C7B40_Data* w, int a, int b, int c, int d)
{
    w->b6 = 1;
    w->m30 = a;
    w->m32 = b;
    w->m34 = c;
    w->m36 = d;
}

extern "C" void* fn_800C8030(void* p) { return p; }
extern "C" void* fn_800C8034(void* p) { return p; }
extern "C" void* fn_800C8038(void* p) { return p; }
extern "C" void* fn_800C803C(void* p) { return p; }
extern "C" void* fn_800C8040(void* p) { return p; }
extern "C" void* fn_800C8044(void* p) { return p; }
extern "C" void* fn_800C8048(void* p) { return p; }
extern "C" void* fn_800C804C(void* p) { return p; }
extern "C" void* fn_800C8050(void* p) { return p; }
extern "C" void* fn_800C8054(void* p) { return p; }
extern "C" void* fn_800C8058(void* p) { return p; }
extern "C" void* fn_800C805C(void* p) { return p; }
extern "C" void* fn_800C8060(void* p) { return p; }
extern "C" void* fn_800C8064(void* p) { return p; }
extern "C" void* fn_800C8068(void* p) { return p; }
extern "C" void* fn_800C806C(void* p) { return p; }

extern "C" void fn_800C80C0(int* p, int v)
{
    *p = v;
}

extern "C" void fn_800C80C8(int* p)
{
    *p = -1;
}

extern "C" int fn_800C80D4()
{
    return 0;
}

extern "C" int fn_800C8110()
{
    return 0;
}
