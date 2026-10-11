/*
 * Types for game/tu_802BB4BC.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802BB4BC_H
#define GAME_TU_802BB4BC_H

/* 8-byte singleton registered in lbl_8061EAF0 by fn_802BB4FC; fn_802BB518 is its
 * deleting destructor, fn_802BB580 the getter. */
struct Unk802BB4FC {
    int m0;
    int m4;
};

/* Object with a counted resource: +0 resource, +4 handle, +8 resource kind (fn_802BB948). */
struct Unk802BB948 {
    const char* m0;
    void* m4;
    int m8;
};

/* Reference-counted entry: +0x10 count, +0x14 live flag, +0x18 name (fn_802BBA40 / fn_802BBA88). */
struct Unk802BBA40 {
    int m0;
    int m4;
    int m8;
    char padC[4];
    int m10;
    int m14;
    char m18[1];
};

/* Object with its vptr at +0x24 (vtable 0x80664080, 0x18 bytes; ctor fn_802BB9E8, dtor fn_802BBA0C). */
struct Unk802BB9E8 {
    char pad0[0xC];
    int mC;
    int m10;
    int m14;
    char pad18[0xC];
    const void* m24;
};

/* 0x34-byte record: a position (x, y, z) followed by 10 more words. Evidence: fn_802BC228 copies it
 * with the 24+24+4 word loop and adds a Vec3 to the first three floats. */
struct Unk802BC228 {
    float x;
    float y;
    float z;
    float rest[10];
};
struct Unk802BC228_V3 {
    float x;
    float y;
    float z;
};

/* Collision body loader result (fn_802BB894): +0 handle, +4 loaded "models/collbody.gld". */
struct Unk802BB894 {
    int m0;
    int m4;
};

#endif
