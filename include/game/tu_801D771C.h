/*
 * Types for game/tu_801D771C (batter/pitcher AI helper classes at
 * 0x801D771C..0x801DB948). Reconstructed from field offsets only.
 */
#ifndef GAME_TU_801D771C_H
#define GAME_TU_801D771C_H

void* operator new(unsigned int size, int heap); /* 0x80377428 */

/* Three floats at the start of a 0x20-byte record (tables at +0x34 and +0xB4). */
struct Unk801D771C_V20 {
    float x;
    float y;
    float z;
    char pad0C[0x20 - 0xC];
};

/* Three floats at the start of a 0x18-byte record (table at +4). */
struct Unk801D771C_V18 {
    float x;
    float y;
    float z;
    char pad0C[0x18 - 0xC];
};

struct Unk801D771C_P8 {
    int m0;
    int m4;
};

/* Selector table object: ints indexed from 2 at +0, pairs at +0x38 / +0x80, vectors at +0x34/+0xB4. */
struct Unk801D771C_Tbl {
    int m0[14];
    Unk801D771C_P8 m38[14];
};

#endif
