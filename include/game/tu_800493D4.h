#ifndef GAME_TU_800493D4_H
#define GAME_TU_800493D4_H

#include "game/tu_80047B08.h"

/*
Types for game/tu_800493D4.cpp (see tu_80044C10.h for the shared game object).

Unk800493D4_Sm is the state-machine object whose methods fill 0x800493D4..0x8004B6BC:
entries of 0x48 bytes start at +0 (entry i holds the game object pointer at
+0x3C), +0x9DC holds a current index, and +0xA9C a message sink pointer
(shared with the Unk80048A10_Sub at the manager's +0xFC).
*/

struct Unk800493D4_Sm;

struct Unk800493D4_Sm {
    char pad0[0x9DC];
    int m9DC;
    int m9E0;
    char pad9E4[0x40];
    int mA24;
    char padA28[0xC];
    int mA34;
    char padA38[0x20];
    int mA58;
    char padA5C[0x4];
    int mA60;
    char padA64[0x4];
    int mA68;
    int mA6C;
    char padA70[0x20];
    int mA90;
    char padA94[0x8];
    void* mA9C;
    char padAA0[0x14];
    int mAB4;
    int mAB8;
    char padABC[0x28];
};

int fn_80058FE4(void* sink, int msg); /* returns 1 (li r3,1 at 0x800596BC) */
int fn_80058FE4(void* sink, int msg, Unk80044C10_A* a);
void fn_8004FCDC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_8004B910(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80011890();
void fn_8000F670(int a, int b);
int fn_8001F4F0(Unk80044C10_A* a);
int fn_8001E054(Unk80044C10_A* a);
void fn_80046078(Unk80044C10_B* b);
void fn_801A6D84(Unk80044C10_A* a, int b);
int fn_8016B9F4();
int fn_8006BE18(Unk80044C10_C* c);
void fn_8004B5C0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80057B54(void* sink, int a);

#endif
