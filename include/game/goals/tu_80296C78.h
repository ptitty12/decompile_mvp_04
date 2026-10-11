/*
 * Types for animation/goals/tu_80296C78.cpp (goal logic). Reconstructed from
 * the field offsets that unit uses; names are placeholders.
 */
#ifndef GAME_GOALS_TU_80296C78_H
#define GAME_GOALS_TU_80296C78_H

#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

typedef Unk80273498_Vec3 Vec3;

/* The goal's flag word at +0x18C. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N). Evidence that it is a bitfield:
 * fn_80297668 tests f9 with andis. and extracts f10 with extrwi. */
struct Unk80296C78_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Goal record of the +0x18C-flag family. Evidence: offsets used by the
 * functions of animation/goals/tu_80296C78.cpp (0x80296C78..0x80299920). */
struct Unk80296C78_Goal {
    int m0;                        /* goal code (9 in fn_80298B74, 2 in fn_80298E50) */
    char pad4[0xC - 4];
    int mC;
    Vec3 m10;
    Vec3 m1C;
    int m28;
    int m2C;
    char pad30[0x38 - 0x30];
    int m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    char pad44[0x48 - 0x44];
    int m48;
    int m4C;
    Vec3 m50;
    char pad5C[4];
    int m60;
    int m64;
    int m68;
    int m6C;
    char pad70[0x158 - 0x70];
    float m158;
    char pad15C[0x160 - 0x15C];
    int m160;
    Vec3 m164;
    Vec3 m170;
    int m17C;
    int m180;
    char pad184[0x18C - 0x184];
    union {
        unsigned int m18C;
        Unk80296C78_Flags m18Cbits;
    };

    /* Testing two bits with && directly folds them into one mask compare;
     * the original keeps separate andis. tests (as in tu_8027FD64.h). */
    int IsF8() const { return m18Cbits.f8; }
    int IsF9() const { return m18Cbits.f9; }
};

/* Position getter by value: gives retail's temp copy when assigned (fn_80298E9C). */
inline Vec3 GetPos(const Unk80296C78_Goal* p)
{
    return p->m10;
}

/* Writes through a by-value parameter: gives retail's temp-to-member copy. */
inline void SetVec(Vec3& dst, Vec3 v)
{
    dst = v;
}

extern const Vec3 lbl_806055AC;
extern int lbl_806242B4;

/* Fields of the player object (Unk80270BA0_X) hidden in chooser.h padding. */
struct Unk80296C78_Player {
    char pad0[0x934];
    Unk8027A84C_Owner* m934;
};

/* Link object reached through Unk80270BA0_X::m618 (see Unk80271DBC_Link). */
void fn_80381E9C(Unk80271DBC_Link* l, int v, int a, int b);

#endif /* GAME_GOALS_TU_80296C78_H */
