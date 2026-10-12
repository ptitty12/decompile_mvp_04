/*
 * Types for game/tu_801C6D2C.cpp (reconstructed, placeholder names). The player
 * object (Unk801B7FB0_P) is shared with game/tu_801B7FB0.cpp; the batter state
 * object (Unk801C16B0_Z) with game/tu_801C16B0.cpp.
 */
#ifndef GAME_TU_801C6D2C_H
#define GAME_TU_801C6D2C_H

#include "game/tu_801C16B0.h"

extern const char lbl_805D1404[];

/* Random float: fn_8014D8AC(max 1000000) scaled by `scale` and 1e-6 (inline, so
 * that its float parameter takes a frame slot like the retail code). */
inline float RandF(Unk8014D8AC* r, float scale, int line)
{
    const char* f = lbl_805D1404;
    return (float)(unsigned)r->fn_8014D8AC(1000000, f, line) * scale * 1e-6f;
}

/* Same random float, but the player object is the argument and the RNG pointer (m554) is loaded
 * inside, after the scale slot store, as retail does in the scalers (fn_801C6A34 family). */
inline float RandFP(Unk801B7FB0_P* p, float scale, int line)
{
    const char* f = lbl_805D1404;
    return (float)(unsigned)p->m554->fn_8014D8AC(1000000, f, line) * scale * 1e-6f;
}

inline float Lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

/* Same lerp with the parameters in (a, t, b) order: the retail frame slots are a, t, b. */
inline float LerpATB(float a, float t, float b)
{
    return a + t * (b - a);
}

#endif
