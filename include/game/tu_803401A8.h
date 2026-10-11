#ifndef GAME_TU_803401A8_H
#define GAME_TU_803401A8_H

/*
 * Shared types for the game tail 0x803401A8..0x8034B370 (range 26).
 *
 * "Observable value" makers (tu_80344E90 .. tu_80349880, about 200 functions of
 * a few shapes). Each one calls fn_803B9D60(&a) to fetch an allocator pointer
 * (it copies lbl_806AA8A0), brackets the work with fn_803B9DDC / fn_803B9E08 (a
 * lock pair, the same one fn_803BA240 takes), then calls virtual 1 of the
 * allocator (vtable entry 1: lha delta at +8, lwz pfn at +0xC) with
 * (size, {0, 0, 0}) to get a record (8, 0xC or 0x10 bytes), stores clamped
 * words from its argument into record+4.., and registers the record with
 * fn_803BA240(&lbl_xxx, &rec->m4, rec). The record is returned.
 * Evidence: fn_8034699C (no argument), fn_80346E64 (one int), fn_80344F94
 * (two) and fn_80344E90 (three).
 */
struct Unk803B9D60_Z {
    int m0;
    int m4;
    int m8;
    Unk803B9D60_Z() : m0(0), m4(0), m8(0) {}
};

struct Unk803B9D60_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Unk803B9D60_Alloc {
    virtual Unk803B9D60_Rec* v1(int size, const Unk803B9D60_Z& z);
};

struct Unk803B9D60_In1 {
    int m0;
};
struct Unk803B9D60_In2 {
    int m0;
    int m4;
};
struct Unk803B9D60_In3 {
    int m0;
    int m4;
    int m8;
};

int fn_803B9D60(Unk803B9D60_Alloc** out);
int fn_803B9DDC();
int fn_803B9E08();
int fn_803BA240(void* tbl, int* p, Unk803B9D60_Rec* rec);

#endif
