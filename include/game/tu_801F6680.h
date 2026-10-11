/*
 * Types for game/tu_801F6680.cpp (reconstructed, placeholder names).
 *
 * The "menu" object that the screen-setup routines in tu_801FA73C/tu_801FE850 embed at screen+0xA0:
 * a G pointer (the same context object the screen holds at +0 and +0x9C) and a float.
 * Evidence: fn_801F7F64 (reset) walks the 0x18-byte entries at G+0x1DC (count at G+0x1D8), sets G+0x38 = 1
 * and menu+4 = a float constant; fn_801F7FC4 sets the flag words G+0x48..0x60 from a bit mask;
 * fn_801F8E40 clears G+0x38.
 */
#ifndef GAME_TU_801F6680_H
#define GAME_TU_801F6680_H

#include "game/tu_801EE438.h"

struct Unk801F6680_Menu {
    Unk801EE438_G* m0;
    float m4;
};

extern "C" {
void fn_801F7F64(Unk801F6680_Menu* m);
}
#endif
