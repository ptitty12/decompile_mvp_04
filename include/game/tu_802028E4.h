/*
 * Types for game/tu_802028E4.cpp (reconstructed, placeholder names).
 * Evidence: fn_8020543C / fn_802055F4 / fn_80205644 / fn_80205664 load
 * this->m0->m6F8, then ->m10 (field mC, array m6C) and ->m14 (byte m1CC9, int m1CD0).
 */
#ifndef GAME_TU_802028E4_H
#define GAME_TU_802028E4_H

struct Unk802028E4_W {
    char pad0[0x1CC9];
    unsigned char m1CC9;
    char pad1CCA[0x1CD0 - 0x1CCA];
    int m1CD0;
};

struct Unk802028E4_Z {
    char pad0[0xC];
    int mC;
    char pad10[0x6C - 0x10];
    int m6C[2];
};

struct Unk802028E4_Y {
    char pad0[0x10];
    Unk802028E4_Z* m10;
    Unk802028E4_W* m14;
};

struct Unk802028E4_X {
    char pad0[0x6F8];
    Unk802028E4_Y* m6F8;
};

struct Unk802028E4_Obj {
    Unk802028E4_X* m0;
};

/* 4 ints: two (index, count) pairs, reset to (-1, 0) by fn_80204AAC */
struct Unk802028E4_Pair {
    int m0;
    int m4;
    int m8;
    int mC;
};
#endif
