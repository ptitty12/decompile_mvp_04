#ifndef GAME_TU_8018C9C8_H
#define GAME_TU_8018C9C8_H

/*
 * Types for src/game/tu_8018C9C8.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_80188698.h"

/* Flag word at Unk80188698::m4A4, seen as bitfields (MSB first): rlwimi 21,10,10 sets
 * b10, rlwimi 22,9,9 sets b9 (fn_8018C9C8, fn_8018D258); the getters at 0x8018AD20 /
 * 0x8018B648 read the same bits. */
struct Unk8018C9C8_Bits {
    unsigned int f0 : 9;
    unsigned int b9 : 1;
    unsigned int b10 : 1;
    unsigned int f11 : 21;
};

/* Result buffer of fn_8018A254 (64 bytes: the caller reserves it in its frame). */
struct Unk8018A254_Ret {
    float m[16];
};

/* Ball object fields only used here. */
struct Unk8018CA5C_Obj : public Unk80188698 {
};

struct Unk8018CA5C_Helper {
    char pad0[0xAC8];
    float mAC8;
};

extern Unk80181140_F lbl_805CDDCC;

extern "C" {
float fn_801937B4(void* p, int k, float t);
float fn_80193750(void* p, float t);
float fn_80193828(void* p, float t);
int fn_8018AABC(Unk80188698* o);
int fn_8018B4D0(Unk80188698* o);
Unk8018A254_Ret fn_8018A254(Unk80188698* o, int a, const Unk80183918_Vec3* v, int b, int c, int d, int e);
int fn_8018CE28(Unk80188698* o, int a, int b);
int fn_801A2400(void* c);
void fn_8037893C(void* sub, int a, int b, int c, int d);
void fn_8018ED00(Unk80188698* o);
void fn_8018EB14(Unk80188698* o);
void fn_8018EA18(Unk80188698* o);
void fn_8018E8C4(Unk80188698* o);
void fn_8018E4CC(Unk80188698* o);
}

inline float Unk8018CA78_Eval(void* p, int k, float t)
{
    return fn_801937B4(p, k, t);
}
inline float Unk8018CA78_Eval2(void* p, float t)
{
    return fn_80193750(p, t);
}
inline float Unk8018CA78_Eval3(void* p, float t)
{
    return fn_80193828(p, t);
}

#endif /* GAME_TU_8018C9C8_H */
