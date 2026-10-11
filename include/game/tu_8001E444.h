/*
 * Types for game/tu_8001E444.cpp .. game/tu_8002B430.cpp (reconstructed from
 * the code in those units; no original header survives). Everything is named
 * by offset (m<off>) or address (Unk<addr>) until a string proves a real name.
 *
 * Unk8001E444_Obj is the object most of these functions take as `this`
 * (r3): a controller with a pointer to a "character" at +0x3B0 and an owner
 * at +0x130. Evidence: fn_8001E444, fn_8001E4F4, fn_8001E810, fn_8001F2C4,
 * fn_8001F9EC and their neighbours.
 */
#ifndef GAME_TU_8001E444_H
#define GAME_TU_8001E444_H

/* Stride-0x28 entry array at Obj+0x154 (m0 and m4 read in fn_8001E810). */
struct Unk8001E810_Entry {
    int m0;
    int m4;
    char pad8[0x20];
};

/* Object at Obj+0x3B0. A controller object is embedded at +0x588. */
struct Unk8001E444_Char {
    char pad0[0x388];
    int m388;
    char pad38C[0x460 - 0x38C];
    int m460;
    char pad464[0x588 - 0x464];
    char m588[0x180];
    int m708;
    int m70C;
};

/* Entity record, stride 0xE64 (fn_8001F5CC, fn_8001E4F4). */
struct Unk8001F5CC_Ent {
    char pad0[0x19C];
    int m19C;
    char pad1A0[0x1B4 - 0x1A0];
    unsigned char m1B4[0x80];
    char pad234[0xE64 - 0x234];
};

/* Sum of the 128 bytes at Ent+0x1B4 (fn_8001F788, fn_8002A2D4). */
inline unsigned Unk8001F5CC_RowSum(const Unk8001F5CC_Ent* e)
{
    unsigned s = 0;
    for (int i = 0; i < 0x80; i++)
        s += e->m1B4[(unsigned char)i];
    return s;
}

/* Pointed to by Unk8001F5CC_Tbl::m14: two entities, then a selector at +0x1CD0. */
struct Unk8001F218_Pair {
    Unk8001F5CC_Ent e[2];
    unsigned char m1CC8;
    char pad1CC9[7];
    int m1CD0;
};

/* Record at Tbl+0xC (m28 is compared against four ids in fn_8001F914). */
struct Unk8001F914_Rec {
    char pad0[0x28];
    int m28;
};

/* Record at Tbl+0x10 (m1C is scaled by a float constant in fn_8001F788). */
struct Unk8001F788_Rec {
    char pad0[0x1C];
    int m1C;
};

struct Unk8001F5CC_Tbl {
    char pad0[0xC];
    Unk8001F914_Rec* mC;
    Unk8001F788_Rec* m10;
    Unk8001F218_Pair* m14;
};

/* Three floats at Pos+0x60 (position); same layout as Unk80273498_Vec3 in chooser.h. */
struct Unk801A4B34_Vec3 {
    float x;
    float y;
    float z;
};
extern "C" float fn_804028E4(float x);
/* Euclidean length through a const reference (the sqrt of retail's fn_804028E4). */
inline float Unk801A4B34_Len(const Unk801A4B34_Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* Sub-record at Pos+0x58C (flags at +4, a count at +0x30, an id at +0x38). */
struct Unk801A4B34_Rec58C {
    int m0;
    unsigned m4;
    char pad8[0x30 - 8];
    int m30;
    char pad34[4];
    int m38;
};

/* Character-like object returned by fn_801A4B34/fn_801A497C (position at +0x60). */
struct Unk801A4B34_Pos {
    char pad0[0x60];
    Unk801A4B34_Vec3 m60;
    char pad6C[0x388 - 0x6C];
    int m388;
    int m38C;
    char pad390[0x3E8 - 0x390];
    float m3E8;
    char pad3EC[0x3F4 - 0x3EC];
    float m3F4;
    char pad3F8[0x44C - 0x3F8];
    struct Unk8001F2C4_World* m44C;
    char pad450[0x458 - 0x450];
    int m458;
    char pad45C[4];
    int m460;
    char pad464[0x58C - 0x464];
    Unk801A4B34_Rec58C m58C;
    char pad5C8[0x708 - 0x5C8];
    int m708;
    unsigned char m70C;
};

/* Object at Outer+0x3A4 (fn_800243D4 reads a float at +0x1F8, fn_800245D0 passes +0x28C on). */
struct Unk8001F2C4_Inner {
    char pad0[0x1F8];
    float m1F8;
    char pad1FC[0x28C - 0x1FC];
    char m28C[4];
};

struct Unk8001F2C4_Outer {
    char pad0[0x3A4];
    Unk8001F2C4_Inner* m3A4;
    char pad3A8[8];
    int m3B0;
    struct Unk8001F2C4_Rec* m3B4;
};

struct Unk8001F2C4_Rec {
    char pad0[0xC];
    int mC;
};

/* Game context (same object as Unk8014D8AC_Ctx in chooser.h). */
struct Unk8001F2C4_World {
    char pad0[0x48];
    unsigned m48;
    unsigned m4C;
    char pad50[0x684 - 0x50];
    int m684;
    int m688;
    int m68C;
    char pad690[0x6CC - 0x690];
    Unk801A4B34_Pos* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Unk8001F5CC_Tbl* m6F8;
    char pad6FC[4];
    Unk8001F2C4_Outer* m700;
    char pad704[0x720 - 0x704];
    int m720;
    char pad724[0x780 - 0x724];
    int m780;
    int m784;
    int m788;
    int* fn_801A6D84(int a);
};

/* Object at Obj+0x130. */
struct Unk8001E444_Owner {
    char pad0[0x44C];
    Unk8001F2C4_World* m44C;
    char pad450[0x480 - 0x450];
    char m480[0x108];
    char m588[0x17C];
    int m704;
    int m708;
};


/* 0x2C-byte record built in an array of five (fn_8001ED28). */
struct Unk80344538_Rec {
    Unk80344538_Rec();
    char data[0x2C];
};

struct Unk8001E444_Obj {
    unsigned char m0;
    char pad1[0x12F];
    Unk8001E444_Owner* m130;
    char pad134[0x154 - 0x134];
    Unk8001E810_Entry m154[1];
    char pad17C[0x274 - 0x17C];
    int m274;
    char pad278[0x360 - 0x278];
    int m360;
    int m364;
    char pad368[0x3B0 - 0x368];
    Unk8001E444_Char* m3B0;
    int m3B4;
    char pad3B8[0x408 - 0x3B8];
    int m408;
    int m40C;
    int m410;
    char pad414[0x444 - 0x414];
    int m444;
};

struct Unk8001F764_Obj {
    char pad0[0xC];
    int mC;
};

struct Unk8001F8B8_Obj {
    char pad0[0x60];
    int m60;
    int m64;
    int m68;
    char pad6C[0x284 - 0x6C];
    int m284;
};

/* C++ linkage on purpose: the animation units declare it that way (chooser.h). */
int fn_8025416C(void* p, int n);

extern "C" {
float fn_80254474(void* p, int a, int b);
float fn_80254330(void* p, int a);
float fn_8025454C(void* p, int a);
void fn_8009E1D4(void* p, int a, int b);
void fn_80045024(int a);
void fn_8004618C(bool a);
void fn_80043B78(int a);
void fn_80046780(int a);
int fn_800458C0(float a);
void fn_800474A4();
void fn_800433CC();
void fn_80046160(int a, int b);
void fn_80043650(bool a);
void fn_8004390C(int a);
void fn_80045FEC(int a);
int fn_8001D1A4(Unk8001E444_Obj* x, int a, int b, int c);
struct Unk800B555C_Quad {
    int m0;
    int m4;
    int m8;
    int mC;
};
struct Unk800B555C_Obj {
    char pad0[0x688];
    Unk800B555C_Quad m688;
};
Unk800B555C_Obj* fn_800B555C();
int fn_8001CF18(Unk8001E444_Obj* x, Unk80344538_Rec* arr);
void fn_800437AC(int a);
int fn_802F922C(int p);
int fn_802F92CC(int p);
int fn_802F92A4(int p);
float fn_80254618(void* p, int a);
int fn_80097318(Unk8001F5CC_Ent* e, int a);
void fn_80046DCC(float f);
void fn_80046D30(float f);
int fn_80097210(Unk8001F5CC_Ent* e, int a);
int fn_80097A70(Unk8001F5CC_Ent* e, int a, int b, int c);
int fn_800638F0(Unk8001F5CC_Tbl* t, Unk8001F218_Pair* base, int idx, int a, int* outSize, int** outArr);
void fn_8004378C(int a);
Unk801A4B34_Pos* fn_801A4B34(Unk8001F2C4_World* w);
Unk801A4B34_Pos* fn_801A497C(Unk8001F2C4_World* w, int a, int b);
int fn_80045BD8(Unk801A4B34_Pos* p);
int fn_802540E4(void* p, int a, int b);
void fn_80045F88(float f);
void fn_80046C64(float f);
int fn_80253F0C(void* p, int a, int b, int c);
void fn_800431BC(int a);
float fn_80253F54(void* p, int a, int b, int c);
void fn_80043208(int a);
void fn_80043124(float f);
void fn_80043178(float f);
int fn_80253DB0(void* p, int a, int b);
float fn_8025401C(void* p, int a);
void fn_80042DBC(float f);
int fn_80253FDC(void* p, int a);
int fn_8025405C(void* p, int a, int b);
int fn_802540A0(void* p, int a, int b);
void fn_80042E24(int a);
int fn_800B57EC();
}

#endif
