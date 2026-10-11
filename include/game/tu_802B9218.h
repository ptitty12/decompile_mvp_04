/*
 * Types for game/tu_802B9218.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802B9218_H
#define GAME_TU_802B9218_H

void fn_80400828(void* p);
void fn_8040084C(void* p);

/* File-IO error state at 0x8068B4F8: +0 is the last error flag, +4 the lock that guards it
 * (fn_80400828 locks, fn_8040084C unlocks). Evidence: fn_802B9EFC stores +0 under the lock,
 * the retry wrappers fn_802B9250..fn_802B9CCC read it under the same lock. */
struct Unk8068B4F8 {
    int m0;
    char m4[4];
    inline int Get() {
        fn_80400828(m4);
        int v = m0;
        fn_8040084C(m4);
        return v;
    }
};

struct Unk802B9F40_A0 {
    void* m0;
    void* m4;
    char m8;
    char pad9[9];
    char m12[0x26];
    int m38;
};
struct Unk802B9F40_A1EF0 {
    int m0;
    int m4;
    int m8;
    int mC[7];
    void* m28;
    char m2C;
    char pad2D[0xB];
};
/* Texture table object: 0x84 slots of 0x3C bytes, 0x14 slots of 0x38 bytes at +0x1EF0
 * (the +0x28 field of each holds a 0x19260-byte buffer, fn_802BA218), counters at +0x2350.
 * Evidence: fn_802B9F40 (clears), fn_802BA218 (allocates), fn_802BA194 (+0x12/+0x38). */
struct Unk802B9F40 {
    Unk802B9F40_A0 a0[0x84];
    Unk802B9F40_A1EF0 a1EF0[0x14];
    int m2350;
    int m2354;
};
struct Unk802B9FF0_Hdr {
    char pad0[8];
    int m8;
    char padC[8];
    int m14;
};
struct Unk802B9FF0_Pal {
    char pad0[0xC];
    unsigned mC;
    int m10;
};
struct Unk802BA110_Src {
    int m0;
    int m4;
};

/* 0x30-byte object (factory fn_802BA874 allocates it; ctor fn_802BA828). */
struct Unk802BA828 {
    Unk802BA828(int a);
    float m0;
    float m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    float m1C;
    float m20;
    int m24;
    float m28;
    float m2C;
    int m30;
};

/* Bat model set: bat model parts (8 entries of 0x168 bytes at +0x10 and +0xB5C), loaded by
 * fn_802BACDC from "models/textures/bat.%s". */
struct Unk802BACDC_Bat {
    int m0;
    int m4;
    char pad8[8];
    int m10;
    char pad14[0xB50 - 0x14];
    int mB50;
    char padB54[8];
    int mB5C;
    char padB60[0x169C - 0xB60];
    int m169C;
    char pad16A0[8];
    int m16A8;
};
/* 0x1C-byte overlay descriptors (fn_802BB1E4 selects them with +0x1C). */
struct Unk802BB1E4_Obj {
    char pad0[0x1C];
};

void fn_802BAFD0(Unk802BACDC_Bat* b);
void fn_802BB038(Unk802BACDC_Bat* b);
void fn_802B9D7C(int kind, int* a, int* b);
extern "C" void fn_802B961C(const char* p, int a);
extern "C" const char* fn_802B9300(const char* s, int a, int b, unsigned int* outn);

#endif
