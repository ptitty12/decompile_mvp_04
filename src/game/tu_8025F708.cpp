/*
 * Game code, .text 0x8025F708-0x80264378 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

extern "C++" {
}

void fn_8025F860(I* self, P* p, int a)
{
    self->m4C4[p->m458 - 9] = a;
}

void fn_8025F878(I* self)
{
    for (int i = 0; i < 4; i++)
        self->m4C4[i] = 0;
}
