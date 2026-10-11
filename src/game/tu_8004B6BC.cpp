/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8004B6BC-0x8004E364 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8004B6BC.h"

void fn_8004B910(Unk800493D4_Sm* s)
{
    int v = s->mA58;
    if (v != 0)
        s->mA58 = v - 1;
}
