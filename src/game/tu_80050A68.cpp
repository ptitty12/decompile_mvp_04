/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80050A68-0x80052794 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80050A68.h"

void fn_80050F9C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA6C == 0) {
        Unk80044C10_Obj590* o = a->m3B0;
        if (o != 0 && (o->m590 & 0x20000000) == 0) {
            fn_80011C38(s);
            s->mA6C = 1;
        }
    }
}

void fn_80050FF4()
{
    fn_80011BE4();
}

void fn_80051014(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 0x3C;
    Unk80044C10_E* e = (*(Unk80044C10_B**)(b + idx * 0x48))->m6F8->m14;
    if (e->m1CC8 == 0 && e->m1CD0 == 1)
        fn_80052FBC(s, idx);
}

void fn_80051168()
{
}

void fn_80051370()
{
}

void fn_80051860(Unk800493D4_Sm* s, int idx)
{
    char* p = (char*)s + idx * 0x48;
    if (*(int*)(p + 8) > 1) {
        fn_8000FD5C();
        return;
    }
    fn_8000F6D4(fn_80044D3C(*(int*)(p + 4)));
}

void fn_800518A4()
{
    fn_8000FEBC();
}

void fn_800518C4()
{
}

void fn_800518C8()
{
}

void fn_80051E68(Unk800493D4_Sm* s, int idx)
{
    if (fn_8005000C(s, idx, 0x2E) >= 0) {
        char* b = (char*)s + 8;
        if (*(int*)(b + idx * 0x48) != 0)
            fn_80017C2C();
    }
}

void fn_80051F18()
{
}

void fn_80052124()
{
    fn_8001A450();
}

void fn_80052144()
{
}

void fn_80052790()
{
}
