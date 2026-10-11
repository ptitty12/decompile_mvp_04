/*
 * Game code, .text 0x80171A10-0x80174318 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80171A10.h"

void fn_80172118() {}

void fn_8017211C() {}

void fn_8017227C(Unk8017227C_T* p, int a, int b, int i)
{
    p->m1C[i].m0 = a;
    p->m1C[i].m4 = b;
}

int fn_80173274(Unk80173274_T* p)
{
    int idx = p->m4;
    if (idx != 0) {
        return p->m0;
    }
    return *(int*)((char*)p + idx);
}
void fn_80174274(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 5);
}

void fn_8017429C(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 6);
}
