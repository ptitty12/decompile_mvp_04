/*
 * Types for animation/goals/tu_80283934.cpp (goal logic). Reconstructed from
 * the field offsets that unit uses; names are placeholders.
 */
#ifndef GAME_GOALS_TU_80283934_H
#define GAME_GOALS_TU_80283934_H

#include "game/chooser.h"

typedef Unk80273498_Vec3 Vec3;

/* The 0x30-byte record copied into a goal at +0x48 by fn_802859A4 (its second
 * argument). Offsets: +4 and +0x10 positions, +0x1c an angle, +0x20 a kind
 * (switch in fn_802859A4), +0x24 flags (0x20 tested). */
struct Unk80283934_Info {
    int m0;
    Vec3 m4;
    Vec3 m10;
    float m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

/* What a goal's +4 points at; only the fields the unit reads. The goal itself
 * shares +0x10 (a position) and +0x28 (non-null test) with it. */
struct Unk80283934_Ent {
    char pad0[0x10];
    Vec3 m10;
    char pad1C[0x28 - 0x1C];
    int m28;
    char pad2C[0x74 - 0x2C];
    float m74;
    char pad78[0x18C - 0x78];
    int m18C;
};

/* Goal record. Evidence: offsets used by the functions of
 * animation/goals/tu_80283934.cpp (0x80283934..0x80287600). */
struct Unk80283934_Goal {
    char pad0[4];
    Unk80283934_Ent* m4;
    char pad8[0x10 - 8];
    Vec3 m10;
    float m1C;
    char pad20[4];
    float m24;
    int m28;
    int m2C;
    char pad30[0x44 - 0x30];
    void* m44;                     /* fn_8027A90C: m44->mC is the player */
    Unk80283934_Info m48;          /* copied from the init record */
    int m78;
    int m7C;
    char pad80[4];
    float m84;
    char pad88[0x94 - 0x88];
    int m94;
    float m98;
    int m9C;
    int mA0;
    Vec3 mA4;
    Vec3 mB0;
    char padBC[0xC8 - 0xBC];
    float mC8;
    float mCC;
    float mD0;
    float mD4;
    Vec3 mD8;
    char padE4[4];
    int mE8;
};

inline Vec3 operator+(Vec3 a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

/* Views of memory reached through the player object (Unk80270BA0_X); the real
 * types live in game/chooser.h with padding where these fields are. */
struct Unk80283934_Pos {
    char pad0[0x38C];
    int m38C;
};
struct Unk80283934_Ctx {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6CC - 0x50];
    Unk80283934_Pos* m6CC;
};
struct Unk80283934_Angles {
    char pad0[0x48];
    float m48[2];
    char pad50[0x190 - 0x50];
    int m190;
};
struct Unk80283934_X {
    char pad0[0x44C];
    Unk80283934_Ctx* m44C;
    char pad450[0x734 - 0x450];
    Unk80283934_Angles m734;
};

/* One of the six 0x98-byte debug records in lbl_806E07E0 (.bss). */
struct Unk80283934_Slot {
    unsigned char data[0x94];
    unsigned int m94;
};

/* fn_8026F590 is a cMatrixChooser method (tu_8026DDE8.cpp); here it is reached
 * through the chooser fn_8037D028 returns, so it is declared as a free function. */
int fn_8026F590(Unk8037B3E8* chooser, Unk80270BA0_Obj* obj, unsigned char* buf);
Unk8037B3E8* fn_8037D028(Unk8037C7FC* c, int key);
Unk80283934_Ent* fn_80384A48(unsigned int hash);

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

extern "C" double fabs(double x);
void fn_8028F588(float v);

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

float fn_80382BB8(Unk80271DBC_Link* p);
float fn_80410CE8(float y, float x);
void fn_80244858(Unk80270BA0_X* x, float v);

float fn_804028E4(float x);               /* square root */
float fn_802958F4(Unk80283934_Ent* e, Unk80270BA0_X* x, int a, float b);

float fn_8041171C(float x);
float fn_80411554(float x);

/* Unit vector for an angle (as in animation/choosers/tu_80272B20.cpp). */
inline Vec3 Direction(float angle)
{
    Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
    return r;
}

Unk80283934_X* fn_8027A90C(Unk80283934_Goal* g);
void fn_8027DAE8(Unk80283934_Goal* g, const Vec3* p);
void fn_8027DB38(Unk80283934_Goal* g, const Vec3* dir, const Vec3* ref);
Vec3 fn_80286E70(const Unk80283934_Goal* g);
float fn_80286F9C(const Unk80283934_Goal* g);
unsigned int fn_8028712C(int kind);
int fn_802871D8(int a);

#endif /* GAME_GOALS_TU_80283934_H */
