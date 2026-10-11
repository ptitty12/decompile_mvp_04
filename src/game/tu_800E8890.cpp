/*
 * Game code, .text 0x800E8890-0x800EBF2C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E8890.h"

void fn_800EAD38(void* t, Unk800EAD5C_C* u)
{
    fn_800EAD5C(u);
}

void fn_800EAD5C(Unk800EAD5C_C* t)
{
    if (t->m2F0 != 0) {
        t->m2F0();
    }
}

int fn_800EB930(Unk800EAD5C_T* t, int x)
{
    return x == t->m17C;
}

int fn_800EB944(char* t)
{
    return fn_804D2310(t + 0x144);
}

int fn_800EBDB0()
{
    return 0;
}

int fn_800EBDB8()
{
    return 0;
}
