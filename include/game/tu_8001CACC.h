/*
 * Types for game/tu_8001CACC.cpp and game/tu_8001D7F8.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * Unk8001CE80: one large object (at least 0x4D8 bytes) whose methods fill both
 * units; most are thin forwarders that load a field and pass it to a function
 * in 0x8004xxxx (fn_8001D42C: this+0x3CC/+0x3D0 to fn_80042E68, ...). Only the
 * offsets those functions read or write are given; each is named after the
 * first function that touches it.
 *
 * The pointer at +0x130 leads to a second object whose +0x44C leads to a third
 * (+0x6F8 and +0x700 point to the next level; +0x708 is an int record index
 * and +0x480 / +0x588 are embedded sub-objects passed by address). Evidence:
 * fn_8001CF18, fn_8001CFCC, fn_8001D280, fn_8001D47C, fn_8001D62C.
 */
#ifndef GAME_TU_8001CACC_H
#define GAME_TU_8001CACC_H

struct Unk8001CE80_Vec2 {
    float x;
    float y;
};

/* +0x6F8 target: +0xC and +0x10 point to small records, +0x14 to the table of
 * 0xE64-byte entries (fn_8001CFCC, fn_8001D47C, fn_8001DC88, fn_8001E0C8). */
struct Unk8001D62C_Rec {
    char pad0[0x1C];
    int m1C;
};

struct Unk8001E0C8_Rec {
    char pad0[0x24];
    int m24;
    char pad28[0x80 - 0x28];
    int m80;
    char pad84[4];
    int m88;
};

struct Unk8001D47C_Level {
    char pad0[0xC];
    Unk8001E0C8_Rec* mC;
    Unk8001D62C_Rec* m10;
    char* m14;
};

struct Unk8001D47C_Mid {
    char pad0[0x6F8];
    Unk8001D47C_Level* m6F8;
};

struct Unk8001D62C_Mid {
    char pad0[0x44C];
    Unk8001D47C_Mid* m44C;
    char pad450[0x708 - 0x450];
    int m708;
};

struct Unk8001CE80_Entry {
    int m0;
    int m4;
    char pad8[0x20];
};

struct Unk8001CE80_Sub {
    char pad0[0x98];
    int m98;
};

class Unk8001CE80 {
public:
    void fn_8001CCE0(Unk8001CE80* o);
    int fn_8001CD94(int a, int flag);
    void fn_8001CE80();
    void fn_8001CEA8(float* b, float* a);
    int fn_8001D204(int v);
    int fn_8001CFCC(int a, int b);
    float fn_8001D0AC(int a, int k);
    int fn_8001D1A4(int a, int k, int x);
    void fn_8001D218();
    void fn_8001D248();
    void fn_8001D42C();
    void fn_8001D454();
    int fn_8001D5D8();
    int fn_8001D62C();
    int fn_8001D694();
    void fn_8001D6CC();
    void fn_8001D70C();
    void fn_8001D75C();
    void fn_8001D7D0();
    void fn_8001DA28();
    void fn_8001DA4C();
    void fn_8001DB4C();
    void fn_8001DB70();
    void fn_8001DBA0();
    void fn_8001DC58();
    void fn_8001DC88();
    void fn_8001DCCC();
    void fn_8001DDD8();
    void fn_8001DE9C();
    void fn_8001E054();
    void fn_8001E084();
    void fn_8001E0C8();
    void fn_8001E294();
    void fn_8001E2EC();
    void fn_8001E31C();

    unsigned char m0;
    unsigned char m1;
    char pad2[0x3A];
    int m3C;
    char pad40[0x8];
    int m48;
    char pad4C[0xB8];
    int m104;
    char pad108[0x8];
    int m110;
    char pad114[0x4];
    int m118;
    char pad11C[0x4];
    int m120;
    char pad124[0xC];
    Unk8001D62C_Mid* m130;
    char pad134[0x20];
    Unk8001CE80_Entry m154[7];
    char pad26C[0x8];
    int m274;
    char pad278[0x10];
    Unk8001CE80_Vec2 m288;
    char pad290[0x120];
    Unk8001CE80_Sub* m3B0;
    int m3B4;
    Unk8001CE80_Vec2 m3B8;
    char pad3C0[0x4];
    int m3C4;
    float m3C8;
    int m3CC;
    int m3D0;
    char pad3D4[0xC];
    int m3E0;
    int m3E4;
    char pad3E8[0x10];
    int m3F8;
    char pad3FC[0x8];
    int m404;
    int m408;
    char pad40C[0x38];
    int m444;
    int m448;
    int m44C;
    int m450;
    int m454;
    int m458;
    int m45C;
    char pad460[0x8];
    int m468;
    char pad46C[0x8];
    int m474;
    char pad478[0x8];
    int m480;
    char pad484[0x50];
    int m4D4;
    char mEnd;

};

#endif
