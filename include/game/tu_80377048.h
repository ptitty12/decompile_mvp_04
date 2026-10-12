#ifndef GAME_TU_80377048_H
#define GAME_TU_80377048_H

/*
 * EA gamelib (C:/mvp2004/libraries/gamelib) shared types.
 *
 * SortRec / SortArr: a sorted array of 12-byte records {key, m4, m8}, kept
 * ordered by key (binary search fn_80377A14, insert fn_80377B1C, erase
 * fn_80377BEC). Evidence: the ctors fn_803779B8 / fn_80377944 (m0 = storage from
 * fn_803774A8(cap * 12, heap), m4 = count, mC = capacity, m10 = duplicates
 * allowed, vptr lbl_80684970 at +0x14), the dtor fn_803778EC, and the accessors
 * in gamelib/tu_80377CD4 (fn_80377DBC / fn_80377DE4 read and write m4 / m8 of
 * record idx).
 */
struct SortRec {
    int key;
    int m4;
    int m8;
};

struct SortArr {
    SortRec* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    const void* m14;
};

/* The virtual view of SortArr (vptr at +0x14); only the slots the code calls. */
struct SortArrV {
    char pad0[0x14];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, void* b);
};

#endif /* GAME_TU_80377048_H */
