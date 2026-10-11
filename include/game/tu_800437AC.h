/*
 * Declarations for game/tu_800437AC.cpp (reconstructed, placeholder names).
 */
#ifndef GAME_TU_800437AC_H
#define GAME_TU_800437AC_H

/* Two-word records at 0x806EF990, 0x806EF998 and 0x806EF9A0: fn_80044994
 * copies m4 into m0 for each and clears m4; fn_80044B94 ORs into m4. */
struct Unk800437AC_Pair {
    int m0;
    int m4;
};

/* Object behind fn_800438F8: +0xC points to a record whose word at +0x84 is a
 * flag. */
struct Unk800438F8_Sub {
    char pad0[0x84];
    int m84;
};
struct Unk800438F8_Obj {
    char pad0[0xC];
    Unk800438F8_Sub* mC;
};

/* Player-like record (flags at +0x590, bit 0x20000000), see Unk8003C9A0_Pl. */
struct Unk80043B00_Pl {
    char pad0[0x590];
    unsigned int m590;
};

/* Chain walked by fn_80043884: obj->m130->m44C->m6F8->m14 is the array of two
 * 0xE64-byte records (see Unk8003FC18_Entry in tu_8003EF18.h). */
struct Unk80043884_Rec;
struct Unk80043884_Sub6F8 {
    char pad0[0x14];
    Unk80043884_Rec* m14;
};
struct Unk80043884_B {
    char pad0[0x6F8];
    Unk80043884_Sub6F8* m6F8;
};
struct Unk80043884_A {
    char pad0[0x44C];
    Unk80043884_B* m44C;
};
struct Unk80043884_Obj {
    char pad0[0x130];
    Unk80043884_A* m130;
};

#endif
