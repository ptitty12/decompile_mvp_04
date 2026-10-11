/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028C6B8-0x8028F178, .rodata 0x805DD754-0x805DD848, .data 0x8061E700-0x8061E778.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028C6B8.h"

unsigned int fn_8028E73C(void* g, int k)
{
    unsigned int r = 0;
    switch (k) {
    case 2:
        r = lbl_806242B4;
        break;
    case 5:
        r = 0x8BF0ACA6;
        break;
    case 7:
        r = 0xA5422C1B;
        break;
    }
    return r;
}

int fn_8026DC5C(int a, int b);

int fn_8028E788(void* g, int a)
{
    return fn_8026DC5C(a, 0);
}

void Unk8028ED00_Req::fn_8028ED00()
{
    m0 = 2;
    m48 = -1;
    m50 = 0;
    m58 = 0;
    m60 = 0;
    m5C = -1.0f;
}

Unk8028ED00_Req* Unk8028ED00_Req::fn_8028EEF4()
{
    int v = 1;
    m60 = v;
    m4->m18C.f18 = v;
    return this;
}

Unk8028ED00_Req* Unk8028ED00_Req::fn_8028F01C(float f)
{
    m58 = 1;
    m54 = f;
    m4->fn_8028F5CC(f);
    return this;
}

Unk8028ED00_Req* Unk8028ED00_Req::fn_8028F068(float f)
{
    m5C = f;
    m4->fn_8028F5F4(f);
    return this;
}

void Unk8028ED00_Req::fn_8028F0AC()
{
    m4->fn_8028F610();
}

void Unk8028ED00_Req::fn_8028F0D0()
{
    m4->fn_8028F848();
}
