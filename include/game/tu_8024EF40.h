/*
 * Shared types for game code 0x8024EF40-0x80268190 (units game/tu_8024EF40 ..
 * game/tu_80264378; reconstructed, placeholder names, everything is named by
 * offset). Nothing here comes from original headers.
 *
 * Evidence (functions of tu_802547C0 unless noted):
 *  - Unk8024EF40_A is a controller embedded in the player at +0x58C
 *    (fn_80254B60 does `A - 0x58C` to get the player back; fn_802548F0 and
 *    fn_80255284 take `&p->m58C`). m0 is the owner, m4 a bit-field word
 *    (bit 0 / bit 2 tested and rlwimi'd in fn_80254DA4 / fn_802547C0).
 *  - Unk8024EF40_P is the player (m44C, m458, m58C, m708, m70C, m730 seen).
 *  - Q = player->m44C (m4C tick count read as unsigned, m6CC, m6F8, m700,
 *    queue at +0x704); Ctx = Q->m700 (m3B4 list, m3BC state).
 */
#ifndef GAME_TU_8024EF40_H
#define GAME_TU_8024EF40_H

struct Unk8024EF40_A;
struct Unk8024EF40_P;

extern char lbl_80649DA0[];
extern char lbl_80660EC0[];

struct Unk8024EF40_Pos {
    char pad0[0x70C];
    unsigned char m70C;
};

struct Unk8024EF40_Sub6F8 {
    char pad0[0x14];
    void* m14;
};

struct Unk8024EF40_Ctx {
    char pad0[0x3B4];
    void* m3B4;
    int m3B8;
    int m3BC;
};

struct Unk8024EF40_Q {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6CC - 0x50];
    Unk8024EF40_P* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Unk8024EF40_Sub6F8* m6F8;
    char pad6FC[4];
    Unk8024EF40_Ctx* m700;
    char m704[4];
};

struct Unk8024EF40_A {
    Unk8024EF40_P* m0;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 29;
    float m8;
    float mC;
    int m10;
    float m14;
    float m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    float m48;
    char pad4C[4];
    struct Unk8024EF40_Ref* m50;
};

struct Unk8024EF40_Ref {
    float m0;
    float m4;
};

struct Unk8024EF40_P {
    char pad0[0x60];
    float m60;
    char pad64[4];
    float m68;
    char pad6C[0x264 - 0x6C];
    int m264;
    char pad268[0x36C - 0x268];
    int m36C;
    char pad370[0x44C - 0x370];
    Unk8024EF40_Q* m44C;
    char pad450[8];
    int m458;
    char pad45C[0x58C - 0x45C];
    Unk8024EF40_A m58C;
    char pad5E0[0x708 - 0x5E0];
    int m708;
    unsigned char m70C;
    char pad70D[0x730 - 0x70D];
    int m730;
};

/* Tick count of the owner in 1/60 s units; an inline in retail (a plain expression
   gives a different constant/load schedule: fn_802554BC). */
inline float Secs(Unk8024EF40_Q* q)
{
    return (float)q->m4C * 0.016666668f;
}

#endif /* GAME_TU_8024EF40_H */
