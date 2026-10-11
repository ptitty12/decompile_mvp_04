#ifndef GAME_TU_80045C8C_H
#define GAME_TU_80045C8C_H

#include "game/tu_80044C10.h"

/*
Types for game/tu_80045C8C.cpp (see tu_80044C10.h for the shared game object).
*/

struct Unk801A497C_Ret;

struct Unk801A497C_Ret {
    char pad0[0x60];
    float m60;
    char pad64[0x4];
    float m68;
};

extern float lbl_806177F0;
extern float lbl_806177F4;
extern float lbl_806177F8;
extern float lbl_806177FC;

int fn_8025416C(void* stats, int a);
int fn_80253DF4(void* stats, int a, int b);
Unk801A497C_Ret* fn_801A497C(Unk80044C10_B* o, int a, int b);
float fn_80410CE8(float a, float b);

#endif
