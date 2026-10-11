#ifndef GAME_TU_8005DF2C_H
#define GAME_TU_8005DF2C_H

/*
 * 0x8005DF2C..0x8005EDCC: thirty float "score" functions. Each takes the
 * caller's argument in r3, two ints it ignores, and a game-state record in r6
 * (the 4th argument, called Ctx here), and returns a score in f1: 0.0 or
 * 100.0 in most. Every function stores a default score in a stack float,
 * overwrites it when its condition holds, and returns it.
 *
 * Evidence for Ctx: offsets read from r6 across the unit are 0x0 (u8), 0x104,
 * 0x110, 0x118, 0x120, 0x130 (pointer), 0x278, 0x3B0 (pointer), 0x3B4..0x3BC,
 * 0x3CC, 0x3D0, 0x408..0x414 and 0x4D4. Only the offsets these functions touch
 * are named, and the types behind the pointers are unknown (Unk8005DF2C_O*).
 */
struct Unk8005DF2C_Ctx;
struct Unk8005DF2C_O130;
struct Unk8005DF2C_O44C;
struct Unk8005DF2C_O684;
struct Unk8005DF2C_O6F8;
struct Unk8005DF2C_O6F8C;
struct Unk8005DF2C_O6F810;
struct Unk8005DF2C_O700;
struct Unk8005DF2C_O3B0;
struct Unk8005DF2C_P;
struct Unk8005DF2C_A;

struct Unk8005DF2C_Ctx {
    unsigned char m0;
    char pad1[0x103];
    int m104;
    char pad108[0x8];
    int m110;
    char pad114[0x4];
    int m118;
    char pad11C[0x4];
    int m120;
    char pad124[0xC];
    Unk8005DF2C_O130* m130;
    char pad134[0x144];
    int m278;
    char pad27C[0x134];
    Unk8005DF2C_O3B0* m3B0;
    int m3B4;
    int m3B8;
    int m3BC;
    char pad3C0[0xC];
    int m3CC;
    int m3D0;
    char pad3D4[0x34];
    int m408;
    int m40C;
    int m410;
    int m414;
    char pad418[0xBC];
    int m4D4;
};

struct Unk8005DF2C_O130 {
    char pad0[0x44C];
    Unk8005DF2C_O44C* m44C;
    char pad450[0x2B4];
    int m704;
    int m708;
};

struct Unk8005DF2C_O44C {
    char pad0[0x684];
    Unk8005DF2C_O684* m684;
    char pad688[0x70];
    Unk8005DF2C_O6F8* m6F8;
    char pad6FC[0x4];
    Unk8005DF2C_O700* m700;
    char pad704[0x1C];
    int m720;
};

struct Unk8005DF2C_O684 {
    char pad0[0x588];
    char m588;
};

struct Unk8005DF2C_O6F8 {
    char pad0[0xC];
    Unk8005DF2C_O6F8C* mC;
    Unk8005DF2C_O6F810* m10;
};

struct Unk8005DF2C_O6F8C {
    char pad0[0xC];
    int mC;
};

struct Unk8005DF2C_O6F810 {
    char pad0[0x1C];
    int m1C;
};

struct Unk8005DF2C_O700 {
    char pad0[0x3B0];
    int m3B0;
};

struct Unk8005DF2C_O3B0 {
    char pad0[0x44C];
    int m44C;
    char pad450[0x2B8];
    int m708;
    char pad70C[0x2F8];
    int mA04;
    char padA08[0x4];
    char mA0C;
};

struct Unk8005DF2C_P {
    char pad0[0x9D8];
    int m9D8;
};

struct Unk8005DF2C_A {
    Unk8005DF2C_P* m0;
};



#endif
