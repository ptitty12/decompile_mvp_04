/*
 * Types for animation/goals/tu_8028989C.cpp (reconstructed; placeholders).
 * Nothing here comes from original headers: layouts are inferred from the
 * offsets the functions of that unit use.
 */
#ifndef GAME_GOALS_TU_8028989C_H
#define GAME_GOALS_TU_8028989C_H

#include "game/chooser.h"

extern const Unk80273498_Vec3 lbl_806055AC;    /* zero vector */

/* Handle whose method fn_8014E388 returns a position (called by fn_80289944). */
struct Unk8014E388_H {
    char pad0[4];
};

/* Goal parameter block ("this" of the unit's first functions). Offsets seen:
 * +0 type (6 after fn_8028989C), +0xC mode (compared with 1 and 2), +0x10 target
 * position, +0x1C direction, +0x28 "has target" flag, +0x48 kind (1..6), +0x4C
 * sub-kind, +0x50..+0x6C floats, +0x70 flag. */
struct Unk8028989C_Goal {
    int m0;
    char pad4[0xC - 4];
    int mC;
    Unk80273498_Vec3 m10;
    Unk80273498_Vec3 m1C;
    int m28;
    char pad2C[0x40 - 0x2C];
    int m40;
    char pad44[0x48 - 0x44];
    int m48;
    int m4C;
    float m50;
    Unk80273498_Vec3 m54;
    float m60;
    float m64;
    float m68;
    float m6C;
    int m70;
    /* By-value getter: reading the vector through it gives the direct stack
     * copies of retail (a plain local copy takes an address register). */
    Unk80273498_Vec3 GetM10() { return m10; }
};

/* Object reset by fn_8028B13C (a different record from the goal block above:
 * +0x64/+0x70 are floats here). Offsets seen: +0 type (5), +0x48 kind (0x1A),
 * +0x4C, +0x50 (-1), +0x5C/+0x60/+0x64 (-1000.0f), +0x70 (-1.0f), +0x78, +0x90,
 * +0xA8 flags (low 13 bits kept). */
struct Unk8028B13C_Obj {
    int m0;
    char pad4[0x48 - 4];
    int m48;
    int m4C;
    int m50;
    char pad54[0x5C - 0x54];
    float m5C;
    float m60;
    float m64;
    char pad68[0x70 - 0x68];
    float m70;
    char pad74[0x78 - 0x74];
    int m78;
    char pad7C[0x90 - 0x7C];
    int m90;
    char pad94[0xA8 - 0x94];
    unsigned int mA8;
};

/* Query record handed to fn_80386110 (size 0xC0). Duplicate of the layout subset
 * of Unk8035EB7C in animation/choosers/tu_80279AE4.cpp (offsets seen in that
 * unit's constructors and in fn_8028B068 here). */
struct Unk8035EB7C_Vec3i {
    int a;
    int b;
    int c;
    void Clear()
    {
        a = 0;
        b = 0;
        c = 0;
    }
};
struct Unk8035EB7C {
    char pad0[0x44];
    unsigned int m44 : 4;
    unsigned int m44r : 28;
    char pad48[0x68 - 0x48];
    Unk8035EB7C_Vec3i m68;
    char pad74[0xA0 - 0x74];
    int mA0;
    char padA4[0xBC - 0xA4];
    unsigned int mBC;
    void Init()
    {
        m68.Clear();
        mA0 = 0;
        mBC = 0;
    }
};

/* Path query (Unk80279BB8 in animation/choosers/tu_80279AE4.cpp, size 0xDC): only
 * the fields used here. */
class Unk80279BB8 {
public:
    Unk80279BB8(Unk80270BA0_X* x);
    char pad0[0xA4];
    Unk80273498_Vec3 mA4;
    char padB0[0xBC - 0xB0];
    unsigned int mBC;
    char padC0[0xCC - 0xC0];
    int mCC;
    char padD0[0xD4 - 0xD0];
    float mD4;
    int mD8;
    void SetYaw(float yaw);
    void SetPos(Unk80273498_Vec3 v);
    void SetD4(float v) { mD4 = v; }
    void AddD4(float v) { mD4 = mD4 + v; }
};

/* Objects behind the goal's owner (fn_8027A8F0 / fn_8027A90C results). */
struct Unk8027A8F0_Ret {
    char pad0[0x10];
    int m10;
};
struct Unk8028989C_Obj36C {
    char pad0[0x36C];
    Unk80270BA0_X* m36C;
};

/* Functions of other units used here. */
float fn_80410CE8(float x, float z);                       /* heading of (x, z) */
void fn_80244858(Unk80270BA0_X* x, float angle);
void fn_80242E6C(Unk80270BA0_X* x);
void fn_80381E9C(Unk80271DBC_Link* link, int hash, int a, int b);
void fn_80249298(Unk80270BA0_X* x, int a, int b);
void fn_80249B40(Unk80270BA0_X* x, int a, int b, int c, float f);
float fn_80382BD8(Unk80271DBC_Link* link, int a);
struct Unk8028989C_Goal;
Unk8027A8F0_Ret* fn_8027A8F0(Unk8028989C_Goal* g);
Unk80270BA0_X* fn_8027A90C(Unk8028989C_Goal* g);
Unk80273498_Vec3 fn_8037B128(Unk80279BB8* q);
void fn_80386188(Unk80271DBC_Link* link, Unk80279BB8* q, int a, int b, float* f1, int c, int d,
                 Unk80273498_Vec3* e, Unk80273498_Vec3* g, int h, int i);
int fn_80386110(Unk80271DBC_Link* link, Unk8035EB7C* q, int a, int b, float* out, int c);

/* Not a member in retail (r3 = query, f1 = yaw / r4 = vector): called by the
 * inline SetYaw / SetPos below. */
void fn_8037B16C(Unk80279BB8* q, float yaw);
void fn_8037B10C(Unk80279BB8* q, Unk80273498_Vec3* v);
inline void Unk80279BB8::SetYaw(float yaw)
{
    fn_8037B16C(this, yaw);
}
inline void Unk80279BB8::SetPos(Unk80273498_Vec3 v)
{
    fn_8037B10C(this, &v);
}

/* Side/team index of the player object (+0x5C4 lies inside XMid::m588). */
inline int& UnkX5C4(Unk80270BA0_X* x)
{
    return *(int*)((char*)x + 0x5C4);
}
extern const Unk80273498_Vec3 lbl_805DED28[];

/* Word at +0x4C of the context behind the player object (frame counter?). */
inline unsigned int UnkCtx4C(Unk8014D8AC_Ctx* c)
{
    return *(unsigned int*)((char*)c + 0x4C);
}
float fn_80382BB8(Unk80271DBC_Link* link);
void fn_80242E6C(Unk80270BA0_X* x);

#define UNK8028989C_STATE_A 0x75027FEF

#endif /* GAME_GOALS_TU_8028989C_H */
