#ifndef GAME_TU_80064D48_H
#define GAME_TU_80064D48_H

#include "game/tu_8005DF2C.h"
#include "game/tu_8005EDCC.h"
#include "game/tu_8005F4E4.h"
#include "game/tu_80060250.h"
#include "game/tu_80063648.h"

/*
 * 0x80064D48..0x80067A20: the rest of the bank-name manager (Unk800642F0 of
 * tu_80063648.h: fn_80064D48, fn_80064F0C, fn_80064F78, fn_800650C8), a
 * 50-slot selection table (Unk800652F4: constructor, reset, mark, and the
 * pick helpers fn_800656FC / fn_800657C8), and a run of tiny functions at the
 * end (id getters, clamp-and-store setters).
 *
 * Unk800652F4: 0x7E4 bytes. m0 is the slot count (50), m4/m8/mC three chosen
 * indices (-1 = none), and from +0x10 an array of 0x28-byte slots: a key word
 * followed by nine flag words. The word at +0x7E0 is set by the constructor to
 * the address of lbl_80649780 (a vtable pointer, written first as g++ does).
 */
struct Unk800652F4_Slot;

struct Unk800652F4_Slot {
    int id;
    int f[9];
};


struct Unk800652F4 {
    Unk800652F4();
    void fn_80065338();
    void fn_800653A4();
    void fn_800653F8(Unk8005DF2C_Ctx* c);
    int fn_800656FC(int idx, Unk8005DF2C_Ctx* c);
    int fn_800657C8(int k, int* out, Unk8005DF2C_Ctx* c);

    int m0;
    int m4;
    int m8;
    int mC;
    Unk800652F4_Slot m10[50];
    void* m7E0;
};
#endif
