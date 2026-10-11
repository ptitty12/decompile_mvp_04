/*
 * Shared types for game code 0x802ACD88-0x802B9218 (units game/tu_802ACD88,
 * game/tu_802B0ACC, game/tu_802B5234; reconstructed, placeholder names,
 * everything is named by offset). Nothing here comes from original headers.
 *
 * Evidence: the functions of tu_802ACD88 take one big manager object. Sub-objects
 * sit at +8 (fn_802AE374/fn_802AE408 forward it), +0x3B78 (fn_802AE984 /
 * fn_802AEB4C hand it to fn_80378024), +0xFAB0 (fn_802B03F4..fn_802B0444),
 * +0x11F78 and +0x12204 (fn_802AE474..fn_802AE5D8). The object is at least
 * 0x20000 bytes (fn_802AE398 reads +0x18700).
 */
#ifndef GAME_TU_802ACD88_H
#define GAME_TU_802ACD88_H

struct Unk802ACD88_Ent {
    int cnt;
    char name[0x20];
};

struct Unk802ACD88_Mgr {
    char pad0[0x3B08];
    void* m3B08;
    int m3B0C;
    int m3B10;
    void* m3B14;
    void* m3B18;
    int m3B1C;
    char pad3B20[0x3B50 - 0x3B20];
    char* m3B50;
    char pad3B54[0x3BAC - 0x3B54];
    Unk802ACD88_Ent ent[32];
};

/* 0xB0-byte table of ints cleared by fn_802B53C4. */
struct Unk802B5234_T {
    int m[44];
};

struct Unk802B5234_V3 {
    float x;
    float y;
    float z;
};

/* Name/value table (fn_802B1D44 ctor, fn_802B1E38 insert, fn_802B1EE8 lookup):
   32 records {char name[0x14]; int val;} of 0x18 bytes, count at +0x300. */
struct Unk802B0ACC_Rec {
    char name[0x14];
    int val;
};

struct Unk802B0ACC_T {
    Unk802B0ACC_Rec e[32];
    int m300;
    int m304;
    int m308;
    int m30C;
    int m310;
    int m314;
    int m318;
    int m31C;
    int m320;
    int m324;
    int m328;
    struct {
        int a;
        int b;
    } g[20];
    char pad3CC_[0x3CC - 0x32C - 0xA0];
    char m3CC[0x18];
    int m3E4;
    char pad3E8[4];
    int m3EC;
    int m3F0;
    int m3F4;
};

struct Unk802B0ACC_V4 {
    int a;
    int b;
    int c;
    int d;
};

struct Unk802B0ACC_F4 {
    float a;
    float b;
    float c;
    float d;
};

#endif /* GAME_TU_802ACD88_H */
