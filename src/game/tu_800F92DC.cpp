/*
 * Game code, .text 0x800F92DC-0x800FD438 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_800F92DC(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v50();
    return 1;
}

int fn_800F933C(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v51();
    return 1;
}

int fn_800F939C(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v52();
    return 1;
}

int fn_800F93FC(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v53();
    return 1;
}

int fn_800F9B70(UiObj* self, int a)
{
    int v = fn_800B555C()->m570;
    if (a == v || v == -1)
        return 1;
    return 0;
}

int fn_800F9BBC(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v50();
    return 1;
}

int fn_800F9C10(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v51();
    return 1;
}

int fn_800F9C64(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v52();
    return 1;
}

int fn_800F9CB8(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v53();
    return 1;
}

int fn_800FC084()
{
    return 1;
}

void fn_800FCA30(UiV_1E0* self)
{
    self->m1E0->v8();
}

void fn_800FCA68(UiV_1E4* self)
{
    self->m1E4->v8();
}

int fn_800FCFA4()
{
    return 0;
}
