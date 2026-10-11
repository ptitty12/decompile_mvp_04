#ifndef GAME_TU_80174318_H
#define GAME_TU_80174318_H

/*
 * Declarations for game/tu_80174318.cpp (reconstructed; placeholders only).
 */

/* Pointer-to-member-function constant (g++ 2.95: delta, index, pfn). */
struct Unk80174318_Fn {
    int m0;
    int m4;
};

struct Unk80174318_Pair {
    int m0;
    int m4;
};

/* Menu/popup object: state at +0x7C, current handler PTMF at +0x80, previous
 * at +0x74; four {int, int} pairs at +0x1C. */
struct Unk80174318_T {
    char pad0[0x1C];
    Unk80174318_Pair m1C[4];
    char pad3C[0x74 - 0x3C];
    Unk80174318_Fn m74;
    int m7C;
    Unk80174318_Fn m80;
};
struct Unk801757D4_T {
    char padC0[0xC0];
    int mC0;
};

void fn_80402CAC(int a, int b);
void fn_8017493C(int a, int b);
void fn_80175810(int a, int b);
void fn_80176C0C(void* self);
void fn_8017696C(void* self);
void fn_80177B40(void* self);
void fn_80177974(void* self);
void fn_80177A0C(void* self);
void fn_80177C34(void* self, void* b);

#endif
