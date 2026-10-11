/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8004E364-0x80050A68 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8004E364.h"

/* near-miss: retail computes addi r9,r3,4 then lwzx (index in r0); here mulli/add/lwz 4(r9) */
void fn_8004EBD4(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 4;
    if (idx >= 0 && *(int*)(b + idx * 0x48) != 0) {
        fn_8001A714();
        return;
    }
    fn_800106A4();
}

void fn_8004FBE4(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    if (a->m3D0 < *lbl_8061B9C4 && a->m448 == 4 && a->m4D4 <= 2 && s->mAB4 == 0) {
        fn_80058FE4(s->mA9C, 0x3D, a);
        s->mAB4 = 1;
    }
}

void fn_8004FC60(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    if (a->m3D0 < *lbl_8061B9C4 && a->m448 == 4 && a->m4D4 <= 2 && s->mAB8 == 0) {
        fn_80058FE4(s->mA9C, 0x2A, a);
        s->mAB8 = 1;
    }
}

int fn_80050094(Unk800493D4_Sm* s, int i)
{
    int n = i + 1;
    if (n > 0x22)
        n = 0;
    return n;
}

int fn_800500A8(Unk800493D4_Sm* s, int i)
{
    int n = i - 1;
    if (n < 0)
        n = 0x22;
    return n;
}
