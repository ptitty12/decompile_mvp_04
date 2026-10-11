/*
 * Types shared by game/tu_801EE438.cpp .. game/tu_8020ADC4.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * These units are front-end/game "screen" code. A screen object has a pointer
 * to a large context object G at +0x9C (and a second view of the same context
 * at +0 in some screens). Evidence: tu_801EE438 getters/setters load
 * 0x9C(screen) then a field of G (+0x1B8, +0x1BC, +0x1CC, +0x1D0), and
 * fn_80205450(G, i) stores i at G+0x3A5C and &G[0xCA8 + i*0x514] at G+0x3A60.
 */
#ifndef GAME_TU_801EE438_H
#define GAME_TU_801EE438_H

struct Unk801EE438_Sub {           /* 0x14 bytes, G+0xC0 and G+0xD4 */
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

struct Unk801EE438_Ent {           /* 0xD8 bytes, Slot+4 + i*0xD8 */
    int m0;                        /* kind (switch in fn_80204E58 / fn_80204F8C) */
    int m4;
    char pad8[0x1C - 8];
    int m1C;
    char pad20[0xA8 - 0x20];
    int mA8;
    char padAC[0xD8 - 0xAC];
};

struct Unk801EE438_Slot {          /* stride 0x514 = 4 + 6 * 0xD8, G+0xCA8 */
    int m0;                        /* entry count */
    Unk801EE438_Ent m4[6];
};

struct Unk801EE438_It {            /* iterator (24 bytes) filled by fn_8014E09C; m8 = current (10 = end) */
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct Unk801EE438_G {
    void* m0;
    char pad4[0x30 - 4];
    int m30;
    char pad34[0xC0 - 0x34];
    Unk801EE438_Sub mC0;
    Unk801EE438_Sub mD4;
    char padE8[0x1B8 - 0xE8];
    int m1B8;
    int m1BC;
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    char pad1D4[0xCA8 - 0x1D4];
    Unk801EE438_Slot mCA8[9];
    int m3A5C;
    Unk801EE438_Slot* m3A60;
    int m3A64;
};

struct Unk801EE438_Scr {
    char pad0[0x9C];
    Unk801EE438_G* m9C;
};

struct Unk801EE438_Scr;
extern "C" {
void fn_8014E09C(Unk801EE438_It* it, void* owner, int k);
void fn_8014E108(Unk801EE438_It* it);
void fn_80205450(Unk801EE438_G* g, int i);
void fn_80211B58(Unk801EE438_Sub* s);
void fn_802123D4(Unk801EE438_Scr* p, int a, int b);
void fn_8021B6EC(Unk801EE438_Scr* p, int a, int b);
void fn_8021BA44(Unk801EE438_Scr* p);
void fn_8021C4E0(Unk801EE438_Scr* p);
void fn_8021CE28(Unk801EE438_Scr* p, float f);
void fn_801F0EA8(Unk801EE438_Scr* p, int a);
int fn_801E817C(int x);
int fn_801E82DC(int x, int slot);
int fn_80204E58(Unk801EE438_Ent* e);
int fn_80204F8C(Unk801EE438_Ent* e);
int fn_80211BB0(Unk801EE438_Sub* s, int a);
void fn_80211BA0(Unk801EE438_Sub* s, int a);
}
#endif
