/*
 * Types for game/tu_8029B6C8.cpp (reconstructed, placeholder names).
 * Evidence: fn_8029B6C8/fn_8029B6F0/fn_8029B6F8 are accessors of an object with
 * an int at +0x60, a float at +0x68 and a bit-field word at +0xD0.
 */
#ifndef GAME_TU_8029B6C8_H
#define GAME_TU_8029B6C8_H

struct Unk8029B6C8_S {
    char pad0[0x60];
    int m60;
    char pad64[4];
    float m68;
    char pad6C[0xD0 - 0x6C];
    unsigned f0 : 1;
    unsigned f1 : 7;
    unsigned f8 : 1;
    unsigned f9 : 23;
};

#endif /* GAME_TU_8029B6C8_H */
