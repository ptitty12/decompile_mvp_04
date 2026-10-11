#ifndef GAME_TU_8017A930_H
#define GAME_TU_8017A930_H

/*
 * Declarations for game/tu_8017A930.cpp (reconstructed; placeholders only).
 * Screen object with sub-objects at +0x3A8..+0x3BC (the unit's functions are
 * thin forwarders to them).
 */

struct Unk8017C954_Rec {
    char pad0[0x1CCA];
    unsigned char m1CCA;
    unsigned char m1CCB;
};
struct Unk8017C954_Mid {
    char pad0[0x14];
    Unk8017C954_Rec* m14;
};
struct Unk8017B0A4_Ctx {
    char pad0[0x6F4];
    int m6F4;
    Unk8017C954_Mid* m6F8;
};
struct Unk8017A930_T {
    int m0;
    Unk8017B0A4_Ctx* m4;
    char pad8[0xC];
    int m14;
    int m18;
    char pad1C[0x3A8 - 0x1C];
    char* m3A8;
    char pad3AC[4];
    void* m3B0;
    char pad3B4[4];
    void* m3B8;
    void* m3BC;
    char pad3C0[0x3DC - 0x3C0];
    int m3DC;
    int m3E0;
    char pad3E4[0x414 - 0x3E4];
    int m414;
    int m418;
};

void fn_80176B90(char* p);
void fn_80176F04(char* p);
void fn_8017671C(char* p);
void fn_801DBB50(void* p);
void fn_801BB800(void* p);
void fn_801DBCB4(void* p);
void fn_801DC918(void* p);
void fn_80235A40(void* p);
void fn_80235AD4(void* p);

#endif
