/*
 * Game code, .text 0x801CF054-0x801D31D8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801CF054.h"

typedef Unk801CF054_Y Y;

extern "C" {
void fn_8035B1C8(void* p);
void fn_801D6FE4(void* p);
void fn_801D5CF0(Y* y);
int fn_8022F138(void* p);
}

extern "C" void fn_801D0288(Y* y) { y->m1F4 = 1; }

extern "C" int fn_801D0294(Y* y)
{
    switch (y->m4) {
    case 1:
    case 2:
    case 4:
    case 6:
    case 7:
        return 1;
    case 0:
    case 3:
    case 5:
        return 0;
    default:
        return 0;
    }
}
extern "C" int fn_801D02E0(Y* y)
{
    switch (y->m4) {
    case 4:
    case 5:
    case 6:
    case 7:
        return 1;
    case 0:
    case 1:
    case 2:
    case 3:
        return 0;
    default:
        return 0;
    }
}
extern "C" int fn_801D0314(Y* y)
{
    switch (y->m4) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
        return 1;
    case 4:
    case 5:
    case 6:
        return 2;
    case 7:
        return 1;
    default:
        return 0;
    }
}
extern "C" int fn_801D0368(Y* y)
{
    switch (y->m4) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
        return 0;
    case 2:
    case 3:
        return 1;
    default:
        return 0;
    }
}

extern "C" Y* fn_801D03A8(Y* y)
{
    fn_8035B1C8(y->m44);
    fn_801D6FE4(y->m6C);
    y->m2C = 0;
    y->m30 = 0;
    y->m38 = 0;
    fn_801D5CF0(y);
    return y;
}

extern "C" void fn_801D03FC(Y* y, void* a, Unk801B7FB0_P* p)
{
    y->m2C = a;
    y->m30 = p;
    y->m34 = p->m700;
    y->m38 = 0;
    y->m28 = 0;
    fn_801D5CF0(y);
}

extern "C" void fn_801D043C(void) {}
extern "C" int fn_801D0C30(void) { return 1; }

extern "C" int fn_801D1198(Y* y) { return fn_8022F138(((Unk801C16B0_M4*)y->m34)->m3B0) != 0; }
