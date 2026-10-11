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
struct Unk8005DF2C_Ent24;
struct Unk8005DF2C_Stat;
struct Unk8005DF2C_Y;
struct Unk8005DF2C_Q;
struct Unk8005DF2C_Rec;
struct Unk8005DF2C_Slot28;
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

struct Unk8005DF2C_Ent24 {
    Unk8005DF2C_O3B0* m0;
    char pad4[0x8];
    char mC;
    char padD[0x17];
};

struct Unk8005DF2C_Stat {
    char pad0[0x4];
    int m4;
    int m8;
    char padC[0x30];
    int m3C;
};

struct Unk8005DF2C_Y {
    char pad0[0x1B4];
    unsigned char m1B4[128];
    char pad234[0x1];
    unsigned char m235;
    char pad236[0xC2E];
};

struct Unk8005DF2C_Q {
    char pad0[0x458];
    int m458;
};

struct Unk8005DF2C_Rec {
    Unk8005DF2C_Q* m0;
    char pad4[0x8];
    int mC;
    char pad10[0x38];
};

struct Unk8005DF2C_Slot28 {
    int m0;
    int m4;
    char pad8[0x20];
};

struct Unk8005DF2C_Ctx {
    unsigned char m0;
    unsigned char m1;
    char pad2[0x36];
    int m38;
    char pad3C[0xC];
    int m48;
    char pad4C[0x24];
    Unk8005DF2C_Ent24 m70[3];
    char padDC[0x28];
    int m104;
    int m108;
    int m10C;
    int m110;
    char pad114[0x4];
    int m118;
    char pad11C[0x4];
    Unk8005DF2C_O3B0* m120;
    char pad124[0xC];
    Unk8005DF2C_O130* m130;
    char pad134[0x4];
    int m138;
    Unk8005DF2C_Slot28 m13C[1];
    char pad164[0x110];
    int m274;
    int m278;
    char pad27C[0x14];
    int m290[1];
    char pad294[0x11C];
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
    int m4D8;
};

struct Unk8005DF2C_O130 {
    char pad0[0x44C];
    Unk8005DF2C_O44C* m44C;
    char pad450[0x138];
    Unk8005DF2C_Stat m588;
    char pad5C8[0x13C];
    int m704;
    int m708;
};

struct Unk8005DF2C_O44C {
    char pad0[0x50];
    char m50;
    char pad51[0x633];
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
    Unk8005DF2C_Stat m588;
};

struct Unk8005DF2C_O6F8 {
    char pad0[0xC];
    Unk8005DF2C_O6F8C* mC;
    Unk8005DF2C_O6F810* m10;
    Unk8005DF2C_Y* m14;
};

struct Unk8005DF2C_O6F8C {
    char pad0[0xC];
    int mC;
    char pad10[0xC];
    int m1C;
    char pad20[0x8];
    int m28;
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
    char pad450[0x138];
    Unk8005DF2C_Stat m588;
    char pad5C8[0x140];
    int m708;
    char pad70C[0x2F8];
    int mA04;
    char padA08[0x4];
    char mA0C;
};

struct Unk8005DF2C_P {
    char pad0[0x4];
    Unk8005DF2C_Rec m4[1];
    char pad4C[0x98C];
    int m9D8;
};

struct Unk8005DF2C_A {
    Unk8005DF2C_P* m0;
};



#endif
