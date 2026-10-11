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

/* Two ints at Unk801DD660::mAC (current and previous value). */
struct Unk801DD660_Hist {
    int m0;
    int m4;
};

/* 0x5C-byte entry of the array at Unk801DD660_Ctx::m6D8 (position at +0). */
struct Unk801DD660_Ent {
    Unk801DB948_Vec3 m0;
    float mC;
    char pad10[0x5C - 0x10];
};

struct Unk801DB948_A {
    char pad0[0x68];
    int m68;
};

/* Iterator (24 bytes on the stack) filled by fn_8014E09C; m8 is the current element (10 = end). */
extern "C" void fn_8014E108(struct Unk801DB948_It* it);
struct Unk801DB948_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int Cur() { return m8; }
    void Next() { fn_8014E108(this); }
};

/* Chain behind Game::m6F8 -> m14 (a count at +0x1CD0). */
struct Unk801DB948_T2 {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk801DB948_T {
    char pad0[0x14];
    Unk801DB948_T2* m14;
};

/* Data of the player object before its vptr (+0x98). */
struct Unk801DB948_PlBase {
    char pad0[0x60];
    Unk801DB948_Vec3 m60;
    char pad6C[0x98 - 0x6C];
};

/* Player object: vtable slot 3 (+0x18) takes a vector, slot 8 (+0x40) an int. */
class Unk801DB948_PlVirt : public Unk801DB948_PlBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3(const Unk801DB948_Vec3& v);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a);
};

struct Unk801DB948_Cfg {
    char pad0[0x838];
    unsigned m838;
};

/* Sub-record at Unk80270BA0_X::m4D8 (state at +0x70). */
struct Unk801DB948_PlSub {
    char pad0[0x70];
    int m70;
};

/* Same object as Unk80270BA0_X in chooser.h (name kept for the mangled callee fn_80286FAC). */
class Unk80270BA0_X : public Unk801DB948_PlVirt {
public:
    char pad9C[0x458 - 0x9C];
    int m458;
    char pad45C[4];
    int m460;
    char pad464[0x4D8 - 0x464];
    Unk801DB948_PlSub m4D8;
    char pad4D8b[0x618 - 0x4D8 - sizeof(Unk801DB948_PlSub)];
    Unk801DB948_Cfg* m618;
    char pad61C[0x710 - 0x61C];
    Unk801DB948_Vec3 m710;
    unsigned m71C;
    char pad720[0x8F0 - 0x720];
    int m8F0;
    char pad8F4[0x908 - 0x8F4];
    int m908;
};

/* Position holder behind Game::m6CC (vptr at +0x98 too). */
class Unk801DB948_Obj : public Unk801DB948_PlVirt {
public:
    char pad9C[0x36C - 0x9C];
    Unk80270BA0_X* m36C;
    char pad370[0x378 - 0x370];
    Unk80270BA0_X* m378;
    char pad37C[4];
    int m380;
    char pad384[0x38C - 0x384];
    int m38C;
};

/* Record returned by fn_80244C84 (kind at +0x10, a sub-record at +0x18 with a flag at +0x4C). */
struct Unk801DB948_QS {
    char pad0[0x4C];
    int m4C;
};
struct Unk801DB948_Q {
    char pad0[0x10];
    int m10;
    char pad14[4];
    Unk801DB948_QS m18;
};

/* Result of fn_801A6DB8 (flags at +4 and +0xC). */
struct Unk801DB948_Rt {
    int m0;
    int m4;
    int m8;
    int mC;
};

/* Level-three object reached from the controller context (Game::m700). */
struct Unk801DB948_J {
    char pad0[0x3A4];
    void* m3A4;
    char pad3A8[0x3B0 - 0x3A8];
    int m3B0;
    int m3B4;
    Unk801DB948* m3B8;
    int m3BC;
    char pad3C0[4];
    int m3C4;
    char pad3C8[0x418 - 0x3C8];
    int m418;
};

/* Controller context returned by fn_801DCC0C (Ctx::m0). */
/* Random number generator (same class as in chooser.h). */
class Unk8014D8AC {
public:
    int fn_8014D8AC(int max, const char* file, int line);
};

struct Unk801DB948_Game {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x554 - 0x50];
    Unk8014D8AC* m554;
    char pad558[0x560 - 0x558];
    char m560[1];
    char pad561[0x660 - 0x561];
    Unk80270BA0_X* m660;
    char pad664[0x688 - 0x664];
    int m688;
    char pad68C[0x6B8 - 0x68C];
    void* m6B8;
    char pad6BC[0x6CC - 0x6BC];
    Unk801DB948_Obj* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    Unk801DB948_T* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk801DB948_J* m700;
    char pad704[0x71C - 0x704];
    Unk801DB948_A* m71C;
};

/* Object at Unk801DD660::m9C (reads +0x30, +0xA8, +0x1B8, +0x0 here). */
/* 0x2C-byte record of the table at Unk801DD660_Ctx::m3DC (indexed 9..12). */
struct Unk801DD660_E2C {
    char pad0[4];
    int m4;
    char pad8[0x24 - 0x8];
    int m24;
    char pad28[0x2C - 0x28];
};

/* Table at Unk801DD660_Ctx::m2B4: records from +0x128 (indexed 9..12 here). */
struct Unk801DD660_Tbl {
    char pad0[0x128];
    Unk801DD660_E2C m128[16];
};

struct Unk801DB948_Obj;
struct Unk801DD660_Ctx {
    Unk801DB948_Game* m0;
    Unk801DB948_Obj* m4;
    char pad8[4];
    void* mC;
    char pad10[0x30 - 0x10];
    int m30;
    int m34;
    int m38;
    char pad3C[0x44 - 0x3C];
    int m44;
    char pad48[0x70 - 0x48];
    int m70;
    char pad74[0xA4 - 0x74];
    int mA4;
    float mA8;
    char padAC[0x1B8 - 0xAC];
    int m1B8;
    char pad1BC[0x2B4 - 0x1BC];
    Unk801DD660_Tbl m2B4;
    char pad2B4b[0x6D8 - 0x2B4 - sizeof(Unk801DD660_Tbl)];
    Unk801DD660_Ent m6D8[1];
    char pad734[0x3A68 - 0x6D8 - sizeof(Unk801DD660_Ent)];
    int m3A68;
    int m3A6C;
};

/* 0x14-byte sub-object at Unk801DD660::m11C (reset by fn_801DC8E8). */
struct Unk801DD660_Sub {
    Unk801DD660* m0;
    int m4;
    int m8;
    int mC;
    float m10;
    float m14;
};

/* 0x34-byte record at Unk801DD660::m134 (owner, a float, ten counters). */
struct Unk801DD660_Sub2 {
    Unk801DD660* m0;
    float m4;
    int m8[10];
    char pad30[4];
};

/* 0xAC-byte record of the table at Unk801DD660::m16C. */
struct Unk801DB948_Vec4 : public Unk801DB948_Vec3 {
    int w;
};

struct Unk801DD660_Rec {
    char pad0[4];
    int m4;
    char pad8[4];
    int mC;
    char pad10[0x28 - 0x10];
    Unk801DB948_Vec3 m28;
    char pad34[0x64 - 0x34];
    Unk801DB948_Vec3 m64;
    char pad70[0xAC - 0x70];
};

/* 0x60C-byte table (nine records), built by the out-of-line ctor fn_8035B718. */
extern "C" void* fn_803FFA60(void* d, const void* s, unsigned n); /* memcpy */
struct Unk8035B718 {
    Unk801DD660_Rec m0[9];
};
/* Struct assignment as retail does it: self-check, then memcpy of the whole table. */
inline void Unk8035B718_Assign(const Unk8035B718* s, Unk8035B718* d)
{
    if (d != s)
        fn_803FFA60(d, s, sizeof(*d));
}

/* 0x24-byte block at Unk801DD660::mF8 (set up by fn_801E98C0). */
struct Unk801DD660_Blk {
    float m0;
    int m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    int m1C;
    int m20;
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
    char padA0[0xAC - 0xA0];
    Unk801DD660_Hist mAC;
    char padB4[4];
    int mB8;
    int mBC;
    int mC0;
    char mC4[0x24];
    float mE8;
    float mEC;
    float mF0;
    float mF4;
    Unk801DD660_Blk mF8;
    Unk801DD660_Sub m11C;
    Unk801DD660_Sub2 m134;
    int m168;
    Unk8035B718 m16C;
    float m778;
    Unk801DB948_Vec3 m77C;
    int m788;
    int m78C;
    float m790;
    int m794;
    int m798;
    int m79C[3];
    int m7A8[3];
    int m7B4;
    float m7B8;
};

#endif
