/*
 * Game-object types for units game/tu_80094578 and game/tu_800975A8
 * (reconstructed from the accessor functions; everything is named by offset).
 */
#ifndef GAME_TU_80094578_H
#define GAME_TU_80094578_H

/*
 * Game-object layout seen by the unit's tail (offsets from the functions below):
 * Sub198 at +0x198 (0x9C bytes, name buffer at +0x1C), ByteVec at +0x168
 * (data, count, capacity; vptr at +0x178), byte list at +0x17C, 0x34-byte
 * records from +0x3E8 with their count at +0x3E4.
 */
struct Sub198 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    char m1C[0x80];
};

struct ByteVec {
    unsigned char* m0;
    unsigned m4;
    unsigned m8;
    char padC[3];
    unsigned char mF;
    void* vptr10;
};

struct Slot34 {
    int m0;
    int m4;
    char pad8[0x2C];
};

struct Obj3 {
    ByteVec m0;
    ByteVec m14;
    ByteVec m28;
    ByteVec m3C;
    ByteVec m50;
    char pad64[0x74 - 0x64];
    ByteVec m74;
    char pad88[0x164 - 0x88];
    int m164;
    ByteVec m168;
    unsigned char m17C[12];
    int m188;
    char pad18C[0xC];
    Sub198 m198;
    unsigned char m234;
    char pad235[0x3E4 - 0x235];
    unsigned char m3E4;
    char pad3E5[3];
    Slot34 m3E8[25];
};


#endif
