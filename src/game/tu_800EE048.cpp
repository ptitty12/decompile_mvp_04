/*
 * Game code, .text 0x800EE048-0x800F1AEC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800EE048.h"

void fn_800EEB2C(Unk800EEB2C_T* t)
{
    t->m138 = 1;
}

int fn_800EEB38(Unk800EEB2C_T* t, int x)
{
    if (x != t->m140) {
        return 1;
    }
    return 0;
}

void fn_800EEB50(Unk800EEB2C_T* t, int x)
{
    t->m140 = x;
}

void fn_800F0650()
{
    Unk800F0650_C* c = lbl_806192E0->m4->mC;
    if (c->m600 == 0) {
        c->m600 = 1;
    }
}

int fn_800F07EC()
{
    return 1;
}

void fn_800F0968(void* t)
{
    fn_800ECE34(t);
}

void fn_800F1210(void* t)
{
    fn_800ED254(t);
}

int fn_800F15A4()
{
    return 0;
}

void fn_800F181C()
{
}

void fn_800F1820()
{
}

void fn_800F1A04()
{
    fn_800DB5F4();
}
