/*
 * Shared types for game code 0x8026C414-0x8026DDE8 (unit game/tu_8026C414;
 * reconstructed, placeholder names, everything is named by offset).
 *
 * Evidence:
 *  - Unk8026C414_O is a mover object: fn_8026D55C reads its state either from
 *    the optional context X (mCC) or from m618->m830. The 0x2C-byte predicate
 *    wrappers (fn_8026D578 .. fn_8026DDA4) all call fn_8026D55C with the same
 *    (self, ctx) pair and compare the result against constants.
 */
#ifndef GAME_TU_8026C414_H
#define GAME_TU_8026C414_H

struct Unk8026C414_W {
    char pad0[0x830];
    int m830;
};

struct Unk8026C414_X {
    char padBC[0xBC];
    unsigned int mBC;
    char padC0[0xCC - 0xC0];
    int mCC;
};

struct Unk8026C414_O {
    char pad0[0x618];
    Unk8026C414_W* m618;
};

struct Unk8026C414_V3 {
    int a;
    int b;
    int c;
};

/* 0x20-byte element of the table at +0xC4 of the mover (fn_8026CB30 clears one,
   fn_8026CB9C copies one, fn_8026C65C constructs six). */
struct Unk8026C414_E {
    Unk8026C414_V3 pos;
    unsigned f0 : 1;
    unsigned f1 : 3;
    unsigned f4 : 1;
    unsigned f5 : 27;
    float m10;
    int m14;
    int m18;
    int m1C;
};

/* Packed header word written by fn_8026CA8C (bit numbers are MSB-first). */
struct Unk8026CA8C_W {
    unsigned f0 : 1;
    unsigned f1 : 3;
    unsigned f4 : 8;
    unsigned f12 : 10;
    unsigned f22 : 1;
    unsigned f23 : 9;
};

struct Unk8026C414_M {
    char pad0[0x6C];
    int m6C;
    char pad70[0xC4 - 0x70];
    Unk8026C414_E e[6];
    char pad184[0x240 - 0x184];
    int m240;
    char m244[0x264 - 0x244];
    int m264;
    int m268;
    char pad26C[0x354 - 0x26C];
    int m354;
};

/* vptr at +0x98 of the mover. */
class Unk8026C414_VT98 {
public:
    char pad0[0x98];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9(int a);
};

struct Unk8026CF70_P {
    char pad0[0x60];
    float m60[3];
    char pad6C[0x5BC - 0x6C];
    int m5BC;
};

#endif /* GAME_TU_8026C414_H */
