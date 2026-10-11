#ifndef GAME_TU_80194D44_H
#define GAME_TU_80194D44_H

/*
 * Types for src/game/tu_80194D44.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_80190A00.h"

/* Helper object of the ball (class Unk80195404, size 0xB04): fields seen here. */
struct Unk80194D44_O {
    char pad0[0x20];
    int m20;
    char pad24[0x2C - 0x24];
    float m2C;
    float m30;
    float m34;
    char pad38[0x48 - 0x38];
    float m48;
    int m4C;
    char pad50[0x58 - 0x50];
    float m58;
    char pad5C[0x68 - 0x5C];
    int m68;
    char pad6C[0x70 - 0x6C];
    int m70;
    char pad74[0x78 - 0x74];
    int m78;
    char pad7C[0xC8 - 0x7C];
    int mC8;
    char padCC[0xAF8 - 0xCC];
    int mAF8[3];
};

/* View of the sub-record at +0x58 of Unk80194D44_O. */
struct Unk80195E60_P {
    char pad0[0x24];
    int m24;
    char pad28[0x68 - 0x28];
    int m68;
    int m6C;
};
struct Unk80195E60_Q {
    char pad0[0x38];
    int m38;
};
struct Unk80198188_Ring {
    int m0;
    char* m4;
    char pad8[4];
    int mC;
};

/* Object with four heap arrays at +0x5C..+0x68 and its vptr at +0x90 (dtor fn_8019755C;
 * unit 7 calls it for a member, so it stays an extern "C" function). */
struct Unk8019755C_Data {
    char pad0[0x5C];
    int* m5C;
    int* m60;
    int* m64;
    int* m68;
    char pad6C[0x90 - 0x6C];
    const void* m90;
};
extern char lbl_8065F848[];
struct Unk80197B88_P {
    float m0;
    float m4;
    float m8;
    char padC[0x3C - 0xC];
    float m3C;
    float m40;
    float m44;
    float m48;
};
struct Unk80197B88_O {
    char pad0[0x5C];
    void* m5C;
    char pad60[0x6C - 0x60];
    void* m6C;
};
struct Unk80198C18_Obj {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
    char padBC[0x360 - 0xBC];
    char m360[8];
    const void* m368;
    char pad36C[0x3FC - 0x36C];
    char m3FC[0x14];
};
extern char lbl_806603D8[];
extern char lbl_806603B0[];
extern char lbl_80660468[];
extern char lbl_806604C8[];
extern Unk80181140_F lbl_805CE394;

extern "C" {
void fn_8019D03C(int a, void* ctx, void* o, int b, int c, int d, int e, int f, int g,
    float f0, float f1, float f2, float f3, float f4);
void fn_80377488(void* p);
void fn_80377408(void* p);
void fn_8019755C(Unk8019755C_Data* self, int chrg);
void fn_803DF4E4(Unk8018A254_Ret* m, float a, float b, float c, float d);
void fn_803DFD90(Unk8018A254_Ret* m, float a, float b, float c);
void fn_803DF028(Unk8018A254_Ret* m, void* a, void* b, int c, void* d, int e);
int fn_80195E60(Unk80194D44_O* o, Unk80195E60_Q* q);
float fn_80195EE0(Unk80194D44_O* o);
int fn_80195FD8(Unk80194D44_O* o, float t);
Unk8018A254_Ret fn_8019601C(Unk80194D44_O* o, float d);
int fn_80193AB0(void* o);
void fn_8019427C(void* o);
}

#endif /* GAME_TU_80194D44_H */
