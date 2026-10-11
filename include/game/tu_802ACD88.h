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
    char pad3B0C[0x3B50 - 0x3B0C];
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

#endif /* GAME_TU_802ACD88_H */
