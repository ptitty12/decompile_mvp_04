#ifndef GAME_TU_80188698_H
#define GAME_TU_80188698_H

/*
 * Types for src/game/tu_80188698.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_8018423C.h"

struct Unk80188944_Z {
    char pad0[0x184];
    int m184;
};
struct Unk80188944_Y {
    char pad0[0x10];
    Unk80188944_Z* m10;
};
/* Owner context (same object as Unk8014D8AC_Ctx / Unk801808A4_Ctx). */
struct Unk80188944_Ctx {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6F4 - 0x50];
    int m6F4;
    Unk80188944_Y* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk8027107C_Outer* m700;
};

/* The ball-like object built by fn_80187190 (size 0xB04): fields seen by the
 * accessors of this unit. m448 is the 0xB04-byte helper (Unk80195404). */
struct Unk80188698 {
    char pad0[0x60];
    Unk80183918_Vec3 m60;
    char pad6C[0x264 - 0x6C];
    void* m264;
    char pad268[0x36C - 0x268];
    int m36C;
    char pad370[0x374 - 0x370];
    int m374;
    int m378;
    float m37C;
    int m380;
    float m384;
    int m388;
    int m38C;
    int m390;
    char pad394[0x3F4 - 0x394];
    float m3F4;
    float m3F8;
    char pad3FC[0x418 - 0x3FC];
    float m418;
    char pad41C[0x448 - 0x41C];
    Unk80195404* m448;
    Unk80188944_Ctx* m44C;
    char pad450[0x4A4 - 0x450];
    unsigned int m4A4;
    char pad4A8[0x4B0 - 0x4A8];
    float m4B0;
    int m4B4;
    char pad4B8[0x4C4 - 0x4B8];
    int m4C4;
    char pad4C8[0x4D4 - 0x4C8];
    Unk80188698* m4D4;
    char pad4D8[0x4DC - 0x4D8];
    int m4DC;
    int m4E0;
    char pad4E4[0x4E8 - 0x4E4];
    float m4E8;
    char pad4EC[0xBFC - 0x4EC];
    void* mBFC;
    char padC00[4];
    Unk80183918_Vec3 mC04;
};

extern Unk80181140_F lbl_805CDBDC;
extern Unk80181140_F lbl_805CDBFC;
extern Unk80181140_F lbl_805CDC00;
extern Unk80181140_F lbl_805CDC1C;
extern Unk80181140_F lbl_805CDCA4;
extern Unk80181140_F lbl_805CDB20;
extern Unk80181140_F lbl_805CDB30;
extern Unk80181140_F lbl_805CDB6C;
extern Unk80181140_F lbl_805CDB78;
extern Unk80183918_Vec3 lbl_806055AC;

extern "C" {
void fn_8019E114(void* a, void* b, int c, int d, int e, float f);
void fn_8019DF6C(void* a, void* b, int c, int d, float f);
void fn_8019DE2C(void* a, void* b, int c, int d);
void fn_801965CC(Unk80195404* p, float a, float b, float c);
void* fn_801A497C(void* ctx, int a, int b);
void* fn_801C1638(void* ctx, int a);
int fn_801C4128(void* p);
void fn_80189300(Unk80188698* o, int a);
Unk80183918_Vec3 fn_80196AC0(Unk80195404* p, float t);
Unk80183918_Vec3 fn_80196E3C(Unk80195404* p, float t);
int fn_801973F4(Unk80195404* p, float t);
}

#endif /* GAME_TU_80188698_H */
