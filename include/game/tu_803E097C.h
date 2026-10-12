#ifndef GAME_TU_803E097C_H
#define GAME_TU_803E097C_H

/*
 * Shared declarations for the EAGL tail units 0x803E097C..0x803EB2AC (tu_803E097C ... tu_803EAF50).
 *
 * lbl_Owner / lbl_Impl / lbl_Node: the 0x1AC-byte node (ctor fn_803E1F98, deleting dtor fn_803E2188)
 * is allocated by lbl_Owner::fn_803DA038 in src/ealibs/tu_803D9FE8.cpp, which defines these classes;
 * only the declarations the tail units need are repeated here.
 */
struct lbl_Impl;
struct lbl_Node;

class lbl_Owner {
public:
    char pad0[0x8];
    lbl_Impl* m8;
    void fn_803DA038();
    lbl_Node* fn_803DA148();
    void fn_803DA154(lbl_Impl* impl);
};

/* 64-byte block copied as a unit (the 24+24+16 word-copy loop). */
struct Unk803E097C_Blk64 {
    float w[16];
};

struct Unk803E1F98_Node;

/*
 * State embedded at Node+0xC (ctor fn_803E198C). Offsets are relative to the view; Node+0xC is its m0.
 * Evidence: fn_803E198C (stores), fn_803E1F98 (three 64-byte blocks at +0xC/+0x4C/+0x8C),
 * fn_803E1C10 / fn_803E21DC (float getters), fn_803E1C44, fn_803E1E88, fn_803E1F0C.
 */
struct Unk803E198C_View {
    lbl_Owner* m0;
    int m4;
    int m8;
    Unk803E097C_Blk64 mC;
    Unk803E097C_Blk64 m4C;
    Unk803E097C_Blk64 m8C;
    float mCC, mD0, mD4, mD8, mDC, mE0, mE4, mE8, mEC;
    float mF0;
    char padF4[0x14C - 0xF4];
    float m14C[16]; /* 4x4 identity */
    int m18C;
    char pad190[4];
    int m194;
    int m198;
    Unk803E1F98_Node* m19C;
};

/* The 0x1AC-byte node: allocated by lbl_Owner::fn_803DA038, ctor fn_803E1F98, deleting dtor fn_803E2188. */
struct Unk803E1F98_Node {
    Unk803E1F98_Node* m0;
    unsigned int m4;
    int m8;
    Unk803E198C_View mC;
};

extern void (*lbl_8062C66C)(void* p, int size);
extern void* (*lbl_8062C668)(int size, int heap);

#endif
