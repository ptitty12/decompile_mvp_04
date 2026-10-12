/*
 * Types for the database overlay units db/tu_8054FA04 .. db/tu_8056A248
 * (range 43). Names are placeholders: Db<addr> for the first function that
 * proves a type, m<off> for offsets.
 * (tu_8052A220.h and db_8053967C.h conflict on a few prototypes; this range
 * builds on tu_8052A220.h.)
 */
#ifndef GAME_DB_8054FA04_H
#define GAME_DB_8054FA04_H

#include "game/tu_8052A220.h"
#include "game/tu_8007F198.h"
#include "game/overlay.h"


/*
 * Draft/schedule object of the 0x80565FD4 unit: counts at +8/+0xC/+0x10/+0x14 and two key tables
 * (Unk8052B978_Tbl) at +0x28 and +0x2C.
 */
struct Db80565CDC_S {
    char pad0[8];
    int m8;
    int mC;
    int m10;
    int m14;
    char pad18[0x10];
    Unk8052B978_Tbl* m28;
    Unk8052B978_Tbl* m2C;
};

#endif
