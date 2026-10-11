/*
 * Types for game/tu_801BAC74.cpp (reconstructed, placeholder names). The AI
 * wrapper (Unk801B7FB0_Ai) and the player object (Unk801B7FB0_P) are shared
 * with game/tu_801B7FB0.cpp.
 */
#ifndef GAME_TU_801BAC74_H
#define GAME_TU_801BAC74_H

#include "game/tu_801B7FB0.h"

extern char lbl_80660350[];

/* Event object built on the stack by fn_801BDA38 (id at +0, vptr at +4, two
 * payload words); same shape as Unk801B7FB0_Msg with another derived vtable. */
struct Unk801BAC74_Msg {
    int m0;
    const void* vptr;
    int m8;
    int mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived()
    {
        vptr = lbl_80660350;
        m8 = 0;
    }
    void Set(int a, int b)
    {
        m8 = a;
        mC = b;
    }
    void End() { vptr = lbl_80649DA0; }
};

inline int Unk801BAC74_Byte(unsigned char c) { return c; }

#endif
