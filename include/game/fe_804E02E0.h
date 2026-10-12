/*
 * Shared types for the front-end overlay units fe/tu_804E02E0 .. fe/tu_804F81E0
 * (0x804E02E0..0x804FE34C; reconstructed, placeholder names, nothing here comes from
 * original headers). The widget view classes (FeObj family) come from tu_8043FDC0.h.
 */
#ifndef GAME_FE_804E02E0_H
#define GAME_FE_804E02E0_H

#include "game/tu_8043FDC0.h"

/* BEGIN-VWRAP */
/* Screens whose only data is one widget pointer at the given offset (one-call button handlers). */
struct FeWf134 : FeObj { char pad40[0x134 - 0x40]; FeObj* m134; };
struct FeWf138 : FeObj { char pad40[0x138 - 0x40]; FeObj* m138; };
struct FeWf138b : FeObj { char pad40[0x138 - 0x40]; FeObj1* m138; };
struct FeWf13C : FeObj { char pad40[0x13C - 0x40]; FeObj* m13C; };
struct FeWf140 : FeObj { char pad40[0x140 - 0x40]; FeObj* m140; };
struct FeWf140b : FeObj { char pad40[0x140 - 0x40]; FeObj1* m140; };
struct FeWf184 : FeObj { char pad40[0x184 - 0x40]; FeObj* m184; };
struct FeWf604 : FeObj { char pad40[0x604 - 0x40]; FeObj* m604; };
struct FeWf604b : FeObj { char pad40[0x604 - 0x40]; FeObj1* m604; };
/* END-VWRAP */

#endif
