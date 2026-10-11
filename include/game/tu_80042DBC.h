/*
 * Declarations for game/tu_80042DBC.cpp (reconstructed, placeholder names).
 */
#ifndef GAME_TU_80042DBC_H
#define GAME_TU_80042DBC_H

/* Chain walked by fn_800433CC: obj->m130->m44C->m700->m3A4 (+0x28C is handed
 * to fn_803445A0). Offsets are what that function reads. */
struct Unk800433CC_Outer {
    char pad0[0x3A4];
    char* m3A4;
};
struct Unk800433CC_B {
    char pad0[0x700];
    Unk800433CC_Outer* m700;
};
struct Unk800433CC_A {
    char pad0[0x44C];
    Unk800433CC_B* m44C;
};
struct Unk800433CC_Obj {
    char pad0[0x104];
    int m104;
    char pad108[0x118 - 0x108];
    int m118;
    char pad11C[4];
    int m120;
    char pad124[0x130 - 0x124];
    Unk800433CC_A* m130;
};

/* Record read by fn_80043460: three (current, previous) pairs of state codes
 * at +0/+0x10, +4/+0x14 and +8/+0x18. */
struct Unk80043460_Obj {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

#endif
