/*
 * Game code, .text 0x8010A0A4-0x8010E0F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_8010A6C0()
{
    int o = fn_8011AA24(0)->m700;
    return fn_8017E030(o, fn_801059E4(), 0) == 0;
}

int fn_8010D1C8()
{
    return 0;
}

void fn_8010D1D0()
{
}

void fn_8010D8B4(void* self, char* out)
{
    *out = 0;
}

void fn_8010DC14(UiV_148i_14Ci_158i_15Ci_160i_164i* self)
{
    self->m148 = 0;
    self->m14C = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    fn_800ED254(self);
    fn_800C33D0();
    fn_800C3BE0();
}
