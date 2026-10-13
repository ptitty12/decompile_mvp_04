/*
 * Types for game/tu_802C79F0.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802C79F0_H
#define GAME_TU_802C79F0_H

/* 0x1EC-byte element of the player model table (fn_802CA5A0 indexes it). */
struct Unk802CA5A0_Elem {
    char pad0[0x1EC];
};

/* 0x10-byte resource pair (fn_802C83A4 ctor, fn_802C85AC release): +0/+4 handles, +8/+C counters. */
class Unk802C83A4 {
public:
    Unk802C83A4();
    int m0;
    int m4;
    int m8;
    int mC;
};

/* Model loader object: +0xA8 table of lbl_805E1B34 12-byte entries, +0x3C0 array of 0x10-byte pairs, +0x3D4 count.
 * Evidence: fn_802C7B54. */
struct Unk802C95F8;
struct Unk802C7B54 {
    char pad0[0xA8];
    int mA8[1];
    char padAC[0x3C0 - 0xAC];
    char* m3C0;
    Unk802C95F8* m3C4[4];
    unsigned char m3D4;
};

/* Resource record with two sub-buffers (fn_802C851C / fn_802C8564 load the +0 / +4 blobs, fn_802C85F0 / fn_802C8654 refill them). */
struct Unk802C851C {
    int m0;
    int m4;
    int m8;
    int mC;
};

/* Load size out-parameter helpers (fn_802C83C0 / fn_802C8424): +0 / +4 source handle. */
struct Unk802C83C0 {
    int m0;
    int m4;
};

/* Object whose +0x438 points at one of two sub-objects (+0x168 or +0x2D0), fn_802C95F8. */
struct Unk802C95F8_Sub {
    int m0;
};
struct Unk802C95F8 {
    int m0;
    char pad4[0x438 - 4];
    Unk802C95F8_Sub* m438;
    char* m43C;
    int m440;
    char pad444[0x46C - 0x444];
    int m46C;
    char pad470[0x4B0 - 0x470];
    int m4B0;
    char pad4B4[0];
};

/* Per-slot record of 0x1EC bytes (0x52 floats, then 0x29 ints); ctor fn_802C9618 fills the floats with 1.0f. 0x26 slots,
 * +0x4908 a handle read by fn_802C9EA4, +0x490C the vptr (vtable 0x80664250, shared with the dtor fn_802C968C). */
struct Unk802C9618_Row {
    float f[0x52];
    int g[0x29];
};
class Unk802C9618 {
public:
    Unk802C9618();
    Unk802C9618_Row rows[0x26];
    int m4908;
    const void* m490C;
};

/* Texture-name request: +0x28 flag, +0x2C base id, +0x74 variant. Evidence: fn_802C920C. */
struct Unk802C920C_Req {
    char pad0[0x28];
    int m28;
    int m2C;
    char pad30[0x44];
    int m74;
};

#endif
