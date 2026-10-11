/*
 * Types for the 0x801DB948.. controller units (game/tu_801DB948 .. tu_801E2D84).
 * Reconstructed from field offsets only; nothing is known about the original
 * names. Everything is named by offset (m<off>) or address (Unk<addr>).
 */
#ifndef GAME_TU_801DB948_H
#define GAME_TU_801DB948_H

void* operator new(unsigned int size, int heap); /* 0x80377428 */

struct Unk801DD660;

/*
 * Wrapper (0x8 bytes, vptr at +0 = lbl_80660BF8, impl pointer at +4). Ctor
 * fn_801DB974 builds the 0x422C-byte implementation object with fn_801DD660 and
 * stores it at +4; almost every method forwards to a function on m4.
 */
struct Unk801DB948 {
    const void* m0;
    Unk801DD660* m4;
};

struct Unk801DB948_Vec3 {
    float x;
    float y;
    float z;
};

/* Level-three object reached from the controller context (Game::m700). */
struct Unk801DB948_J {
    char pad0[0x3BC];
    int m3BC;
};

/* Object behind Game::m6CC (a position holder with a vector at +0x60). */
struct Unk801DB948_Obj {
    char pad0[0x60];
    Unk801DB948_Vec3 m60;
    char pad6C[0x36C - 0x6C];
    int m36C;
    char pad370[0x38C - 0x370];
    int m38C;
};

/* Controller context returned by fn_801DCC0C (Ctx::m0). */
struct Unk801DB948_Game {
    char pad0[0x4C];
    int m4C;
    char pad50[0x6CC - 0x50];
    Unk801DB948_Obj* m6CC;
    char pad6D0[0x700 - 0x6D0];
    Unk801DB948_J* m700;
};

/* Object at Unk801DD660::m9C (reads +0x30, +0xA8, +0x1B8, +0x0 here). */
struct Unk801DD660_Ctx {
    Unk801DB948_Game* m0;
    char pad4[0x30 - 0x4];
    int m30;
    char pad34[0xA8 - 0x34];
    float mA8;
    char padAC[0x1B8 - 0xAC];
    int m1B8;
};

/* 0x14-byte sub-object at Unk801DD660::m11C (reset by fn_801DC8E8). */
struct Unk801DD660_Sub {
    int m0;
    int m4;
    int m8;
    int mC;
    float m10;
    float m14;
};

/* Base part before the vptr (+0x98). */
struct Unk801DD660_Base {
    char pad0[0x98];
};

/*
 * Implementation object (0x422C bytes, ctor fn_801DD660, vptr at +0x98 whose
 * first virtual is the destructor: fn_801DB9E4 deletes it through slot 1).
 */
class Unk801DD660_Virt : public Unk801DD660_Base {
public:
    virtual ~Unk801DD660_Virt();
};

struct Unk801DD660 : public Unk801DD660_Virt {
    Unk801DD660_Ctx* m9C;
    char padA0[0xC0 - 0xA0];
    int mC0;
    char padC4[0x11C - 0xC4];
    Unk801DD660_Sub m11C;
    char pad134[0x168 - 0x134];
    int m168;
    char pad16C[0x78C - 0x16C];
    int m78C;
    char pad790[0x798 - 0x790];
    int m798;
};

#endif
