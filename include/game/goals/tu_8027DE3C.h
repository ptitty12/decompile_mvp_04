/*
 * Types for animation/goals/tu_8027DE3C.cpp (reconstructed; placeholders).
 * Nothing here comes from original headers: layouts are inferred from the
 * offsets the functions of that unit use.
 */
#ifndef GAME_GOALS_TU_8027DE3C_H
#define GAME_GOALS_TU_8027DE3C_H

#include "game/chooser.h"

/* Bit view of the flag word at +0xE8 (fn_8027E070 inserts bit 8 from the MSB). */
struct Unk8027DE3C_Flags {
    unsigned int pad0 : 8;
    unsigned int f8 : 1;
    unsigned int rest : 23;
};

/* Goal object ("this" of the unit's functions). Offsets seen: +0x4 owner
 * object, +0xC mode (0/1 in fn_8027E084), +0x34 and +0x38 copied to the owner
 * by fn_8027E084, +0x78 state, +0x7C set to 2 by fn_8027DF1C/fn_8027DF7C,
 * +0x9C/+0xA0 pair set by fn_8027DF88, fn_8027DFA8, fn_8027E008 and
 * fn_8027E068, +0xA4/+0xB0/+0xBC three float vectors, +0xE8 flag word. */
class Unk8027DE3C {
public:
    char pad0[0x7C];
    int m7C;
    char pad80[0x9C - 0x80];
    int m9C;
    int mA0;
    Unk80273498_Vec3 mA4;
    Unk80273498_Vec3 mB0;
    Unk80273498_Vec3 mBC;
    char padC8[0xE8 - 0xC8];
    union {
        unsigned int mE8;
        Unk8027DE3C_Flags mE8bits;
    };

    void fn_8027DDE8(int a);                                   /* other unit */
    Unk8027DE3C* fn_8027DE3C(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b);
    Unk8027DE3C* fn_8027DE88(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b);
    Unk8027DE3C* fn_8027DED4();
    Unk8027DE3C* fn_8027DF08();
    Unk8027DE3C* fn_8027DF1C(int a);
    void fn_8027DF7C();
    Unk8027DE3C* fn_8027DF88(int a);
    Unk8027DE3C* fn_8027DFA8(int a);
    void fn_8027DFBC(int a, const Unk80273498_Vec3* v);
    Unk8027DE3C* fn_8027E008(int a);
    void fn_8027E01C(int a, const Unk80273498_Vec3* v);
    void fn_8027E068(int a);
    Unk8027DE3C* fn_8027E070(int a);
};

#endif /* GAME_GOALS_TU_8027DE3C_H */
