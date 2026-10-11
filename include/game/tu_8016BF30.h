/*
 * Types for tu_8016BF30.cpp (script manager lists). Reconstructed.
 *
 * Evidence: the manager (tu_80167DCC.h) and each of its three slots start with
 * 15 lists of 0xAC bytes (fn_8016D258 initialises 15 of them, fn_8016C698 bumps
 * 15 counters). A list holds a current index, eight entries of 0x14 bytes and two
 * words (+0xA4, +0xA8).
 */
#ifndef GAME_TU_8016BF30_H
#define GAME_TU_8016BF30_H

#include "game/tu_80163390.h"

struct Unk8016C2D0_Obj {
    char pad0[0xC];
    float mC;
};

float fn_801510A8(Unk8016C2D0_Obj* o, int a, float t);

struct Unk8016C1C4_Ent {
    float fn_8016C2D0(int flag);

    int m0;
    Unk8016C2D0_Obj* m4;
    int m8;
    float mC;
    float m10;
};

struct Unk8016C1C4_List {
    int fn_8016C1C4(int idx);
    int fn_8016C1EC();
    float fn_8016C248(int flag);
    void fn_8016C424(int idx);
    void fn_8016C620(int idx, int p);
    void fn_8016C660(int idx);
    void fn_8016C698(int a);
    void fn_8016C004(int a, int b);
    void fn_8016D258();
    int fn_8016C788(int idx);
    int fn_8016C798(int idx);
    void fn_8016D3DC(int idx);
    float fn_8016BF94();

    int mCur;
    Unk8016C1C4_Ent m4[8];
    int mA4;
    int mA8;
};

/* Object whose +0x98 word is a "done" flag (fn_8016DBA4/fn_8016DBAC). */
struct Unk8016DBAC_Obj {
    int fn_8016DBA4();
    void fn_8016DBAC();
    char pad0[0x98];
    int m98;
};

#endif
