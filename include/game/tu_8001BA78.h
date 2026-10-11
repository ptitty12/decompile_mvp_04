/*
 * Opaque singleton types for game/tu_8001BA78.cpp (reconstructed, placeholder
 * names). Each is the object returned by a parameterless accessor
 * (fn_800475EC, fn_8004072C, ...); only the fields this unit touches are
 * given, padded to the observed offsets. Evidence per field: the store or load
 * in the function named next to it.
 */
#ifndef GAME_TU_8001BA78_H
#define GAME_TU_8001BA78_H

/* fn_800475EC(): +0x74, +0xF4, +0xC00 read in fn_8001BDAC, +0xF4 written in fn_8001C50C. */
struct Unk800475EC {
    char pad0[0x74];
    int m74;
    char pad78[0xF4 - 0x78];
    int mF4;
    char padF8[0xC00 - 0xF8];
    int mC00;
};
Unk800475EC* fn_800475EC();

/* fn_8004072C(): +0x5C4 written in fn_8001C50C. */
struct Unk8004072C {
    char pad0[0x5C4];
    int m5C4;
};
Unk8004072C* fn_8004072C();
void fn_800412AC(Unk8004072C* o, int a, int b, int c, int d, int e);

/* fn_8005ACE4(): +0x7C written in fn_8001C50C. */
struct Unk8005ACE4 {
    char pad0[0x7C];
    int m7C;
};
Unk8005ACE4* fn_8005ACE4();

/* fn_8005BA9C(): +0 written in fn_8001C50C. */
struct Unk8005BA9C {
    int m0;
};
Unk8005BA9C* fn_8005BA9C();

/* fn_80038EB4(): +0x5288 written in fn_8001C50C. */
struct Unk80038EB4 {
    char pad0[0x5288];
    int m5288;
};
Unk80038EB4* fn_80038EB4();

/* fn_80030938(): +0x34 written in fn_8001C50C. */
struct Unk80030938 {
    char pad0[0x34];
    int m34;
};
Unk80030938* fn_80030938();

/*
 * Element of the 0xB0-byte table at lbl_805B10B4 (8 entries, indexed by the
 * Unk8001C314 slot number). Only the flags fn_8001C620 / fn_8001C89C /
 * fn_8001C9B8 test are named: +0x20 selects the fn_8004072C object, +0x24
 * fn_800475EC, +0x28 fn_8005BA9C, +0x30 fn_8005ACE4, +0x34 fn_80038EB4.
 */
struct Unk805B10B4 {
    char pad0[0x20];
    int m20;
    int m24;
    int m28;
    char pad2C[4];
    int m30;
    int m34;
    char pad38[0xB0 - 0x38];
};

#endif
