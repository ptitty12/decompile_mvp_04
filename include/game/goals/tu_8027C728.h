/*
 * Types for the goal logic at 0x8027C728-0x8027DE3C (reconstructed).
 *
 * Nothing here comes from original headers: layouts are inferred from the
 * code in animation/goals/tu_8027C728.cpp (and the neighbouring goal units).
 * Placeholder names only (Unk<addr> = named after the first function that
 * shows the layout, m<offset> = field at that offset).
 */
#ifndef GAME_GOALS_TU_8027C728_H
#define GAME_GOALS_TU_8027C728_H

#include "game/chooser.h"

/* Sub-object of the player at +0x58C (fn_8027D708: fn_80255028/fn_80254EA4
 * take it, +0x38 is read as an int). */
struct Unk8027C728_Track {
    char pad0[0x38];
    int m38;
};

/* Link object at player+0x618 (fn_8027CA10 tests +0x838; same pointer as
 * Unk80270BA0_X::m618). */
struct Unk8027C728_Link {
    char pad0[0x838];
    int m838;
};

/* Goal angle block at player+0x734 (same object as Unk80270BA0_X::m734, see
 * Unk802726BC_Angles in chooser.h): fn_8027D150 saves +0x190 into +0x194. */
struct Unk8027C728_Angles {
    char pad0[0x190];
    int m190;
    int m194;
};

struct Unk8027C728_Goal;

/* Player object (Unk80270BA0_X in chooser.h); only the fields the goal logic
 * uses, at their real offsets. */
struct Unk8027C728_Player {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x58C - 0x6C];
    Unk8027C728_Track m58C;
    char pad5C8[0x618 - 0x5C8];
    Unk8027C728_Link* m618;
    char pad61C[0x734 - 0x61C];
    Unk8027C728_Angles m734;
    char pad8CC[0x934 - 0x8CC];
    Unk8027C728_Goal* m934;
};

/* Goal base part, at goal+0x18 (and +0x104). Set up by fn_8027A84C(base,
 * goal); the per-type goal data extends it. */
struct Unk8027C728_Base {
    int m0;
    char pad4[8];
    int mC;
    char pad10[0x48 - 0x10];
    void* m48;
    int m4C;
    char pad50[0xA8 - 0x50];
    unsigned int mA8;
};

/* Result record built by fn_80279BB8(out, player) (tu_80279AE4.cpp); the goal
 * logic reads +0xD4 (float) and +0xD8 (int). Size taken from fn_8027D3E8's
 * stack frame (a local at +8, the next local at +0xE8). */
struct Unk80279BB8 {
    char pad0[0xD4];
    float mD4;
    int mD8;
    Unk80279BB8(Unk8027C728_Player* player);        /* 0x80279BB8 */
};

/* Pair of ints built on the stack by fn_8027D3E8 and passed to fn_8027D150. */
struct Unk8027D150_Pair {
    int m0;
    int m4;
};

/* Goal node. Evidence: fn_8027C728 (type switch on m10, data at +0x18,
 * sub-objects at +0x104 and +0x294), fn_8027D2DC/2FC/31C (list walks via
 * +4 and +0), fn_8027D33C/368 (owner at +0xC), fn_8027D598 (flag +0x14). */
struct Unk8027C728_Goal {
    Unk8027C728_Goal* m0;
    Unk8027C728_Goal* m4;
    char pad8[4];
    Unk8027C728_Player* mC;
    int m10;
    int m14;
    char m18[0xEC];
    char m104[0x190];
    char m294[0x20];
};

#endif /* GAME_GOALS_TU_8027C728_H */
