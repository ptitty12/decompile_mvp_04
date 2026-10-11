/*
 * Types for animation/goals/tu_8028B194.cpp (goal logic), reconstructed.
 *
 * Nothing here comes from original headers; layouts are inferred from the
 * functions in that unit. Names are placeholders (Unk<addr>, m<offset>,
 * fn_<addr>) until evidence exists.
 *
 * The "views" below (Unk8028B194_Angles/_Ctx/_Link) describe fields of
 * objects whose main declarations live in game/chooser.h; they are reached
 * with a pointer cast so that chooser.h need not change.
 */
#ifndef GAME_GOALS_TU_8028B194_H
#define GAME_GOALS_TU_8028B194_H

#include "game/chooser.h"

/* Extra fields of Unk802726BC_Angles (the sub-object at player+0x734). Float
 * pairs are indexed by m190 (0 or 1), like the arrays in chooser.h. */
struct Unk8028B194_Angles {
    char pad0[0x48];
    float m48[2];
    char pad50[0x60 - 0x50];
    float m60[2];
    char pad68[0x98 - 0x68];
    float m98[2];
    char padA0[0x190 - 0xA0];
    int m190;
};

/* Fields of the context object at player+0x44C (Unk8014D8AC_Ctx). */
struct Unk8028B194_Pos {
    char pad0[0x36C];
    Unk80270BA0_X* m36C;
};
struct Unk8028B194_Sub2 {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk8028B194_Sub1 {
    char pad0[0x14];
    Unk8028B194_Sub2* m14;
};
struct Unk8028B194_Sub3 {
    char pad0[0x3B4];
    int m3B4;
};
struct Unk8028B194_Ctx {
    char pad0[0x4C];
    int m4C;                   /* frame counter (converted to seconds) */
    char pad50[0x6B8 - 0x50];
    int m6B8;
    char pad6BC[0x6CC - 0x6BC];
    Unk8028B194_Pos* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    Unk8028B194_Sub1* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk8028B194_Sub3* m700;
};

/* Fields of the link object at player+0x618 (Unk80271DBC_Link). */
struct Unk8028B194_Link {
    char pad0[0x838];
    unsigned int m838;         /* current animation hash */
};

class Unk8027A05C {
public:
    float fn_8027A280(int a);
    Unk80273498_Vec3 fn_8027A358(int a);
};

/* The goal object. Offsets seen in tu_8028B194.cpp. */
class Unk8028B194 {
public:
    void* m0;
    void* m4;
    Unk8027A05C* m8;
    int mC;                    /* phase: 0..4 */
    Unk80273498_Vec3 m10;      /* target position */
    float m1C;
    float m20;
    float m24;
    int m28;                   /* target valid */
    int m2C;
    char pad30[0x40 - 0x30];
    int m40;
    char pad44[0x48 - 0x44];
    int m48;                   /* current goal id */
    int m4C;                   /* requested goal id */
    int m50;
    float m54;
    char pad58[0x60 - 0x58];
    float m60;
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
    int m78;
    char pad7C[0xA8 - 0x7C];
    unsigned int mA8;          /* flags */

    void SetTarget(Unk80273498_Vec3 p)
    {
        m10 = p;
    }

    Unk8028B194* fn_8028B194(Unk80273498_Vec3 v);
    Unk8028B194* fn_8028B1F0(int a);
    Unk8028B194* fn_8028B260(int a, Unk80273498_Vec3* p);
    Unk8028B194* fn_8028B308();
    void fn_8028B31C(int id);
    void fn_8028B324(int id);
    void fn_8028B358();
    void fn_8028B37C();
    void fn_8028B3A0();
    Unk8028B194* fn_8028B3C4();
    void fn_8028B3D8();
    void fn_8028B3FC();
    void fn_8028B420();
    void fn_8028B444();
    void fn_8028B468();
    void fn_8028B48C(float a);
    void fn_8028B4D0(float a);
    void fn_8028B514(int a);
    Unk8028B194* fn_8028B51C(float a);
    unsigned int fn_8028C560(int id, unsigned int cur);
    int fn_8028C0CC(Unk80270BA0_X* x, int b);
    void fn_8028BFA8(Unk80270BA0_X* x, Unk8028B194_Ctx* ctx, float t);
};

#endif /* GAME_GOALS_TU_8028B194_H */
