/*
 * Types for game/tu_8000E618.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_8000E618_H
#define GAME_TU_8000E618_H

/* Three floats. Evidence: fn_8000E788 (the static initializers in
 * tu_8000E618.cpp) subtracts two of them component by component and
 * normalises the difference with sqrt (fn_804028E4). */
struct Unk8000E618_Vec3 {
    float x;
    float y;
    float z;
};

/* The 4-byte singleton returned by fn_8000E65C (created on first use; +0 is the
 * handle that fn_803ED9D4 returns). Callers elsewhere run
 * `fn_8000E65C(); fn_8000E6F0()` and `fn_8000E65C(); fn_8000E6F8()`, so those
 * two are methods. Evidence: fn_8000E618 (ctor, clears +0), fn_8000E65C. */
class Unk8000E618 {
public:
    Unk8000E618();
    int fn_8000E6F0();
    void fn_8000E6F8();
    int m0;
};

/* 16-byte statistics block at 0x806164D8 (.data); +8 holds 0.1f. Evidence:
 * fn_8000E718 reads and writes +0 only; the rest comes from the data dump. */
struct Unk8000E618_Stats {
    int m0;
    int m4;
    float m8;
    int mC;
};

#endif
