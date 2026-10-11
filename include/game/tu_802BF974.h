/*
 * Types for game/tu_802BF974.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802BF974_H
#define GAME_TU_802BF974_H

/* 16 two-bit texel indices of a 4x4 block, first field in the most significant bits (fn_802C2E60
 * reverses each row of four). */
struct Unk802C2E60_Idx {
    unsigned f0 : 2;
    unsigned f1 : 2;
    unsigned f2 : 2;
    unsigned f3 : 2;
    unsigned f4 : 2;
    unsigned f5 : 2;
    unsigned f6 : 2;
    unsigned f7 : 2;
    unsigned f8 : 2;
    unsigned f9 : 2;
    unsigned f10 : 2;
    unsigned f11 : 2;
    unsigned f12 : 2;
    unsigned f13 : 2;
    unsigned f14 : 2;
    unsigned f15 : 2;
};
/* 8-byte compressed texture block: two 16-bit colours and the index word at +4. */
struct Unk802C2E60 {
    short c0;
    short c1;
    Unk802C2E60_Idx idx;
};

struct Unk802C2134 {
    void* m0;
};

struct Unk802C2188_Fmt {
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    inline void Set(int a, int b, int c, int d)
    {
        c0 = a;
        c1 = b;
        c2 = c;
        c3 = d;
    }
};

struct Unk802C2188_Pair {
    int x;
    int y;
    inline void Clear()
    {
        x = 0;
        y = 0;
    }
};

/* Texture-conversion object (fn_802C2188 ctor, fn_802C2214 deleting dtor, fn_802C2254 reset): +0 size, +4 source buffer,
 * 0x22 pointers from +8, scratch buffers at +0x78..+0x8C, +0x90/+0x94 buffers, +0x9C height, +0xA0 width,
 * +0xA4 pair, +0xAC four format bytes, +0xB0 constant 0x7D4. Evidence: fn_802C2254, fn_802C2188, fn_802C2314. */
struct Unk802C2188 {
    int m0;
    char* m4;
    int a8[0x22];
    char* m90;
    char* m94;
    int m98;
    int m9C;
    int mA0;
    Unk802C2188_Pair mA4;
    Unk802C2188_Fmt mAC;
    int mB0;
    int mB4;
    int mB8;
};
struct Unk802C3794_Img {
    char pad0[4];
    short w;
    short h;
};

Unk802C2188* fn_802C2188(Unk802C2188* o);
int fn_802C2304(Unk802C2188* o, int i);
void fn_802C2214(Unk802C2188* o, int c);
void fn_802C2254(Unk802C2188* o);
void fn_802C2314(Unk802C2188* o, Unk802C2188_Pair* a);
void fn_802C23BC(Unk802C2188* o, Unk802C2188_Pair* a);

#endif
