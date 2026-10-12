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

/*
 * Lookup-result plumbing shared by the gamelib registry classes (tu_80382BB8.cpp,
 * tu_80383E00.cpp). ResBig is the 0x5C-byte result record the lookup vcalls fill
 * (type in the top nibble of word 0, id at +4; the 3 words at +0x24 are zeroed by the
 * inline ctor); VCls / VCls2 are views of the looked-up objects with the virtual
 * slots those callers use (11..14 here; evidence: vcalls at vtable offsets
 * 0x58/0x60/0x68/0x70 in fn_80383A44 and fn_80385470).
 */
struct Zero3 {
    int m0;
    int m4;
    int m8;
    Zero3()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
    }
};

/* Result record of the lookups behind the chooser tables (type in the top nibble). */
struct ResBig {
    unsigned type : 4;
    unsigned pad0 : 28;
    int id;
    char pad8[0x24 - 8];
    Zero3 z24;
    char pad30[0x5C - 0x30];
    ResBig() : type(0) {}
};

struct Tgt38 {
    char pad0[0x38];
    int m38;
};

struct VCls2 {
    virtual ~VCls2();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual Tgt38* s11();
};

struct VCls {
    virtual ~VCls();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11(ResBig* out, int b, int c, int d);
    virtual int s12(ResBig* out, int b, int c);
    virtual int s13(ResBig* out, int b);
    virtual int s14(ResBig* out, int b);
};

#endif /* GAME_TU_80377048_H */
