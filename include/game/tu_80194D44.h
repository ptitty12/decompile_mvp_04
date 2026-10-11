#ifndef GAME_TU_80194D44_H
#define GAME_TU_80194D44_H

/*
 * Types for src/game/tu_80194D44.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_80190A00.h"

/* Helper object of the ball (class Unk80195404, size 0xB04): fields seen here. */
struct Unk80194D44_O {
    char pad0[0x20];
    int m20;
    char pad24[0x2C - 0x24];
    float m2C;
    float m30;
    float m34;
    char pad38[0x48 - 0x38];
    float m48;
    int m4C;
    char pad50[0x58 - 0x50];
    float m58;
    char pad5C[0x68 - 0x5C];
    int m68;
    char pad6C[0x70 - 0x6C];
    int m70;
    char pad74[0x78 - 0x74];
    int m78;
    char pad7C[0xC8 - 0x7C];
    int mC8;
    char padCC[0xAF8 - 0xCC];
    int mAF8[3];
};

/* View of the sub-record at +0x58 of Unk80194D44_O. */
struct Unk80195E60_P {
    char pad0[0x24];
    int m24;
    char pad28[0x68 - 0x28];
    int m68;
    int m6C;
};
struct Unk80195E60_Q {
    char pad0[0x38];
    int m38;
};
struct Unk80198188_Ring {
    int m0;
    char* m4;
    char pad8[4];
    int mC;
};

extern "C" {
int fn_80195E60(Unk80194D44_O* o, Unk80195E60_Q* q);
float fn_80195EE0(Unk80194D44_O* o);
int fn_80195FD8(Unk80194D44_O* o, float t);
Unk8018A254_Ret fn_8019601C(Unk80194D44_O* o, float d);
int fn_80193AB0(void* o);
void fn_8019427C(void* o);
}

#endif /* GAME_TU_80194D44_H */
