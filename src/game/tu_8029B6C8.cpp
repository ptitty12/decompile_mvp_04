/*
 * Game code, .text 0x8029B6C8-0x8029B70C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8029B6C8.h"

typedef Unk8029B6C8_S S;

S* fn_8029B6C8(S* self, float v)
{
    self->m68 = v;
    self->f0 = 1;
    return self;
}

void fn_8029B6F0(S* self, int v)
{
    self->m60 = v;
}

S* fn_8029B6F8(S* self, int v)
{
    self->f8 = v;
    return self;
}
