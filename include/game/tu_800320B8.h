#ifndef GAME_TU_800320B8_H
#define GAME_TU_800320B8_H

/*
 * Types for src/game/tu_800320B8.cpp (reconstructed). Same family as
 * Unk800311D0 in tu_80030778.h: derived from Unk80021A60 (ctor 0x80021A60),
 * with a second 0xC-byte sub-object at +0xBC (vptr at +0xC4) and the object
 * size 0x150 (ctor fn_8003265C, vtables 0x80649880 / 0x80649858).
 */
#include "game/tu_80030778.h"

struct Unk8003265C_Vec2 {
    float m0;
    float m4;
};

struct Unk8003265C_P {
    char pad0[0x3B8];
    Unk8003265C_Vec2 m3B8;
    char pad3C0[0x3F0 - 0x3C0];
    float m3F0;
    float m3F4;
};

struct Unk8003265C;
typedef void (Unk8003265C::*Unk8003265C_Handler)(int);
struct Unk8003265C_HEnt {
    int id;
    Unk8003265C_Handler h;
};
extern Unk8003265C_HEnt lbl_80616B6C[];

struct Unk8003265C : public Unk80021A60 {
    int mBC[2];
    const void* mC4;
    int mC8[3];
    int mD4[3];
    int mE0[3];
    int mEC[3];
    int mF8[3];
    int m104[3];
    int m110[3];
    Unk8003265C_P* m11C[3];
    int m128;
    int m12C;
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int* m144;
    int* m148;
    int m14C;
};

extern char lbl_80649858[];
extern char lbl_80649880[];
extern char lbl_80649DB8[];

struct Unk8003265C_Vec3 {
    float m0;
    float m4;
    float m8;
};

extern "C" {
float fn_8018A214(Unk8003265C_P* p);
Unk8003265C_Vec3 fn_8018959C(Unk8003265C_P* p, float f);
void fn_803785E4(void* sub);
void fn_80378620(void* sub, int a);
int* fn_80377458(unsigned int n);
void fn_80377488(void* p);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
void fn_8004181C(void* o, int a, int b, int c, int d, int e, int f);
void fn_8018CA5C(Unk8003265C_P* p, float* a, float* b, float* c);
void fn_80021D6C(void* self, void* o, int a);
void fn_80021E30(void* self, void* o, int a);
void fn_80378A34(void* sub, void* o);
}

#endif /* GAME_TU_800320B8_H */
