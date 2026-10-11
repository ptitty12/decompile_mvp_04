/*
 * Types for game/tu_80087A58.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_80087A58_H
#define GAME_TU_80087A58_H

/* Flag word of an entry (the word at +0x10): a top bit, a 4-bit field at bits
 * 1-4, a 3-bit field at bits 5-7 and a bit at 8 (fn_80088234, fn_80088FBC,
 * fn_80088FFC; fn_80087C40 clears the first four). */
struct Unk80087A58_Bits {
    unsigned hi : 1;
    unsigned a : 4;
    unsigned b : 3;
    unsigned c : 1;
    unsigned rest : 23;
};

/* 0x14-byte entry of the history ring (Unk80087A58_H::e) and of the table at
 * Unk80087A58_O::mF5C. */
struct Unk80087A58_E {
    int m0;
    int m4;
    int m8;
    unsigned char mC;
    char padD[3];
    union {
        int m10;
        Unk80087A58_Bits b10;
    };
};

/* Ring of 100 entries followed by its counters (fn_80087CC4 clears it,
 * fn_80087F94 advances m7D0, wrapping to 1 after 100 and setting m7DC). */
struct Unk80087A58_H {
    Unk80087A58_E e[100];
    unsigned m7D0;
    int m7D4;
    int m7D8;
    int m7DC;
    void* m7E0;
};

/* Table cell used by fn_80087A58 / fn_80087A88: index tables at +0x14 and
 * +0x234, bytes from +0x238 in rows of 0x59. */
struct Unk80087A58_O {
    void* m0;
    unsigned m4;
    int m8;
    char padC[8];
    int m14[1];
    char pad18[0x234 - 0x18];
    int m234;
    char m238[1];
    char pad239[0xF5C - 0x239];
    Unk80087A58_E* mF5C;
    Unk80087A58_H mF60;
    int m1744;
    float m1748;
    int m174C;
    int m1750;
};

/* Pair of words that fn_800881FC copies out of its last argument and passes by
 * address. */
struct Unk80087A58_Pair {
    int a;
    int b;
};

/* Source record of fn_800881FC: words at +8, +0xC and +0x14. */
struct Unk80087A58_Rec {
    char pad0[8];
    int m8;
    int mC;
    char pad10[4];
    int m14;
};

/* Table class with 0x14-byte elements (fn_800897B8 constructs, fn_80089838
 * destroys): base part, a result pointer at +0x14, a count at +0x1C, the vptr
 * at +0x20 and the table at +0x24. */
struct Unk80087A58_T14 {
    char pad0[0x14];
};

struct Unk80087A58_K {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    Unk80087A58_T14* m24;
};

#endif
