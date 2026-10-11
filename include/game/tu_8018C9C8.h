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

struct Unk8018ED00_S {
    char pad0[0x288];
    int m288;
};
struct Unk8018ED00_M {
    char pad0[0x3A4];
    Unk8018ED00_S* m3A4;
    char pad3A8[0x3BC - 0x3A8];
    void* m3BC;
};
struct Unk8018ED00_Ctx {
    char pad0[0x680];
    Unk80188698* m680;
    char pad684[0x700 - 0x684];
    Unk8018ED00_M* m700;
};
struct Unk8018ED00_B {
    char pad0[0x50];
    int m50;
    char pad54[0x6C - 0x54];
    int m6C;
};
struct Unk8018EA18_Ent {
    int m0;
    float m4;
    Unk80183918_Vec3 m8;
};
struct Unk8018CE28_V {
    int m0;
    int m4;
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

inline void Unk8018D410_SetPos(Unk80188698* o, float x, float y, float z)
{
    o->m60.m0 = x;
    o->m60.m4 = y;
    o->m60.m8 = z;
}
extern Unk80181140_F lbl_805CDDCC;

struct Unk8018E8F4_Rec16 {
    float m[4];
};
struct Unk8018E8F4_Ctx {
    char pad0[0x6BC];
    void** m6BC;
    char pad6C0[0x700 - 0x6C0];
    void* m700;
};
extern Unk80183918_Vec3 lbl_806055B8;
extern "C" {
int fn_8019BBC0(void** o, void* a, void* b, float* t, void* p1, void* p2, float k);
void fn_801923CC(void* ret, void* a, void* b, void* c, void* d, int e, int f);
void fn_8017BB18(void* p, int a, void* o, int b, int c);
void fn_8017BB3C(void* p, int a, void* o, int b);
void fn_8018A930(Unk80188698* o, int a, float t, void* b, void* c, void* d);
Unk80188698* fn_801A4C74(void* c, int i);
float fn_804028E4(float x);
float fn_80190F0C(struct Unk80190EB4_Obj* o);
void fn_8018EFC0(Unk80188698* o, Unk80188698* t);
Unk8018ED00_B* fn_801A6DB8(void* c);
int fn_801C3F60(void* p);
int fn_8018F684(Unk80188698* o, Unk80188698* t, int* slot, float k, int flag);
void fn_801BD80C(void* p, void* t);
void fn_8018EE84(Unk80188698* o, Unk80188698* t);
int fn_8018E8F4(Unk80188698* o, Unk80183918_Vec3* a, Unk80183918_Vec3* b);
Unk80183918_Vec3 fn_8018959C(Unk80188698* o, float t);
Unk80183918_Vec3 fn_80189618(Unk80188698* o, float t);
float fn_801937B4(void* p, int k, float t);
void* fn_80193750(void* p, float t);
void* fn_80193828(void* p, float t);
int fn_8018AABC(Unk80188698* o);
int fn_8018B4D0(Unk80188698* o);
Unk8018A254_Ret fn_8018A254(Unk80188698* o, int a, const Unk80183918_Vec3* v, int b, int c, int d, int e);
int fn_8018CE28(Unk80188698* o, int neg, Unk8018CE28_V* p);
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
inline void* Unk8018CA78_Eval2(void* p, float t)
{
    return fn_80193750(p, t);
}
inline void* Unk8018CA78_Eval3(void* p, float t)
{
    return fn_80193828(p, t);
}

#endif /* GAME_TU_8018C9C8_H */
