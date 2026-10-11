/*
 * Types for game/tu_801BDD60.cpp (reconstructed, placeholder names). The AI
 * wrapper (Unk801B7FB0_Ai), the state object (Unk801B7FB0_B) and the player
 * object (Unk801B7FB0_P) are shared with game/tu_801B7FB0.cpp.
 */
#ifndef GAME_TU_801BDD60_H
#define GAME_TU_801BDD60_H

#include "game/tu_801B7FB0.h"

/* Two-word object made by fn_801BFB44 (new 8 in fn_801BA9CC): the player/context
 * and the AI wrapper. Its methods fetch the player objects with fn_801A4C74(m0, i). */
struct Unk801BDD60_O8 {
    Unk801B7FB0_P* m0;
    Unk801B7FB0_Ai* m4;
};

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

/* Chooser class with six float attributes (ctor 0x801C0334, vtable 0x8065EF70, hash
 * 0xD1E132A4, size 0x1C): slot 2 registers them (fn_801C0378), slot 5 is the factory
 * (fn_801C04B0). Slots 3/4 are defined elsewhere, which keeps g++ from emitting the
 * vtable in this unit. */
class Unk801C0334 : public Unk8037B3E8 {
public:
    Unk801C0334();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual ~Unk801C0334();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    float fn_801C04E0(int base);

    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
};

#endif
