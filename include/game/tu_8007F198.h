/*
 * Types for game/tu_8007F198.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_8007F198_H
#define GAME_TU_8007F198_H

/* Two-word entry of Unk8007F198_Rec::m1B0 (fn_8007F6C4 reads the first word). */
struct Unk8007F198_P {
    int w0;
    int w1;
};

/* The 0x1E0-byte record of the table behind Unk8007F198_A::m58 (same stride
 * as Unk8007DB74_Rec). m0/m4/m8 are an int list (data, size, capacity:
 * fn_8007F24C reads m0[i], fn_8007F330 appends); fn_8007F198 reads the low
 * byte of m4. */
struct Unk8007F198_Rec {
    int* m0;
    unsigned m4;
    unsigned m8;
    char padC[0x1B0 - 0xC];
    Unk8007F198_P m1B0[2][2];
    int m1D0[4];
};

/* Table behind Unk8007F198_A::m58: record count at +0xC, records at +0x10.
 * fn_805A19C8(tbl) is the current record's index. */
struct Unk8007F198_Tbl {
    char pad0[0xC];
    unsigned mC;
    Unk8007F198_Rec* m10;
};

struct Unk8007F198_A {
    char pad0[0x58];
    Unk8007F198_Tbl* m58;
};

/* One 0x20-byte item of the list behind Unk8007F198_B::m4. */
struct Unk8007F198_Item {
    char pad0[0x18];
    int m18;
    int m1C;
};

/* List header: count at +0, items from +4 (fn_8007F7D0, fn_8007F7FC). */
struct Unk8007F198_List {
    unsigned m0;
    Unk8007F198_Item m4[1];
};

struct Unk8007F198_B {
    int m0;
    Unk8007F198_List* m4;
};

/* Second word of a 12-byte sub-entry: two bytes, then four nibbles
 * (fn_8007FD2C/FD54 read the bytes; fn_8007FD7C and fn_8007FC40 the nibbles). */
struct Unk8007F198_W1 {
    unsigned char b0;
    unsigned char b1;
    unsigned n16 : 4;
    unsigned n20 : 4;
    unsigned n24 : 4;
    unsigned n28 : 4;
};

/* Third word: nine more nibbles (fn_8007FC40 cases 3..8). */
struct Unk8007F198_W2 {
    unsigned n0 : 4;
    unsigned n4 : 4;
    unsigned n8 : 4;
    unsigned n12 : 4;
    unsigned n16 : 4;
    unsigned n20 : 4;
    unsigned n24 : 8;
};

struct Unk8007F198_Sub {
    int w0;
    Unk8007F198_W1 w1;
    Unk8007F198_W2 w2;
};

/* First word of an entry: a halfword, a 10-bit field, a flag and 5 bits
 * (fn_8007FBC0, FBDC, FC00, FC20, FDA8). */
struct Unk8007F198_W0 {
    unsigned short h0;
    unsigned a : 10;
    unsigned b : 1;
    unsigned c : 5;
};

/* 0x1C-byte entry: W0, then two 12-byte sub-entries (fn_8007FB98.. index them
 * as e*0x1C + s*0xC + 4). */
struct Unk8007F198_Entry {
    Unk8007F198_W0 w0;
    Unk8007F198_Sub s[2];
};

struct Unk8007F198_Obj {
    int m0;
    int m4;
    Unk8007F198_Entry* m8;
};

/* Holder with an array of Unk8007F198_Obj pointers at +0xC. */
struct Unk8007F198_C {
    char pad0[0xC];
    Unk8007F198_Obj* mC[1];
};

/* Object with a pointer at +0 to a block holding an int at +0x22C
 * (fn_8007FDF8; fn_8007FDD4 and fn_8007FE04 pass or return the pointer). */
struct Unk8007F198_DI {
    char pad0[0x22C];
    int m22C;
};

struct Unk8007F198_D {
    Unk8007F198_DI* m0;
};

/* Object with a pointer at +0x1C to a block with ints at +0x528 and +0x694
 * (fn_8007FE0C, fn_8007FEF0); the other fn_8007FE18.. methods pass the pointer
 * to fn_8059Axxx. */
struct Unk8007F198_EI {
    char pad0[0x528];
    int m528;
    char pad52C[0x694 - 0x52C];
    int m694;
};

struct Unk8007F198_E {
    char pad0[0x1C];
    Unk8007F198_EI* m1C;
};

/* 12-byte value that fn_8052BD58 returns through a hidden pointer (fn_8007F980
 * reads the third word; fn_8007FA1C compares and copies the whole value). */
struct Unk8007F198_S12 {
    int w0;
    int w1;
    int w2;
};

#endif
