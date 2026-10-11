/*
 * Types for game/tu_8007DB74.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_8007DB74_H
#define GAME_TU_8007DB74_H

/* Array header behind Unk8007DB74_A::m8 (fn_8007DB74, fn_8007DB80,
 * fn_8007DBB0, fn_8007DBBC): count at +0, 0x6EC-byte elements from +0x18,
 * one more int at +0x1BC8. */
struct Unk8007DB74_Elem {
    char pad[0x6EC];
};

struct Unk8007DB74_Arr {
    int m0;
    char pad4[0x14];
    Unk8007DB74_Elem m18[1];
    char pad_[0x1BC8 - 0x18 - 0x6EC];
    int m1BC8;
};

/* A growable byte list: data pointer, size, capacity (fn_8007E598 push,
 * fn_8007E6D0 store, fn_8007E618 erase). The record holds four of them, 0x14
 * bytes apart from +0x28. */
struct Unk8007DB74_Vec {
    unsigned char* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    int m10;
};

/* 0x30-byte slot in the record's table at +0xF0: bytes at +0 (fn_8007DDC8,
 * fn_8007DE50 read them; 0xFF means none), ints at +0xC (fn_8007DEF8 writes,
 * fn_8007DF5C reads). */
struct Unk8007DB74_Slot {
    unsigned char b[0xC];
    int w[9];
};

/* The 0x1E0-byte record that Unk8007DB74_Tbl holds (stride proven by
 * fn_8007E53C's 0x1E0 step). Other fields are untouched here. */
struct Unk8007DB74_Rec {
    int* m0;
    char pad4[0x10];
    unsigned char* m14;
    char pad18[8];
    int m20;
    char pad24[4];
    Unk8007DB74_Vec m28[4];
    char pad78[0x78];
    Unk8007DB74_Slot mF0[5];
};

/* Table behind Unk8007DB74_A::m58: record count at +0xC, records at +0x10.
 * fn_805A19C8(tbl) is the index of the current record. */
struct Unk8007DB74_Tbl {
    char pad0[0xC];
    unsigned mC;
    Unk8007DB74_Rec* m10;
};

/* Object of this unit's functions. +8 -> Unk8007DB74_Arr, +0x58 ->
 * Unk8007DB74_Tbl. */
struct Unk8007DB74_A {
    char pad0[8];
    Unk8007DB74_Arr* m8;
    char pad0C[0x4C];
    Unk8007DB74_Tbl* m58;
};

#endif
