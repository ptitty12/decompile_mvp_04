#ifndef GAME_TU_80190A00_H
#define GAME_TU_80190A00_H

/*
 * Types for src/game/tu_80190A00.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_8018C9C8.h"

/* Attribute classes derived from the chooser root Unk8037B3E8. Unk80191720 (hash
 * 0x0F245603, size 0x10, slot-2 group "bll": three floats) and Unk8019186C (hash
 * 0xDA319B21, size 0x34, group "blt"). Their vtables (0x8065F878 / 0x8065F8D8) and
 * dtors live in other units, so the dtor is only declared. */
class Unk80191720 : public Unk8037B3E8 {
public:
    Unk80191720();
    virtual ~Unk80191720();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    float m4;
    float m8;
    float mC;
};
class Unk8019186C : public Unk8037B3E8 {
public:
    Unk8019186C();
    virtual ~Unk8019186C();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    float m4;
    float m8;
    float mC;
    int m10;
    float m14;
    float m18;
    float m1C;
    int m20;
    float m24;
    float m28;
    float m2C;
    float m30;
};
extern "C" void* fn_80191800(Unk80191720* self);

inline int* Unk80190E40_Put(int* q, int b, int v)
{
    *q = b;
    q[1] = v;
    return q + 2;
}

/* Player-like object with the vtable at +0x98 (slot 9 takes one argument). */
struct Unk80190EB4_Base {
    char pad0[0x98];
};
class Unk80190EB4_Virt : public Unk80190EB4_Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};
struct Unk80190EB4_Obj : public Unk80190EB4_Virt {
    char pad9C[0x264 - 0x9C];
    int m264;
    char pad268[0x36C - 0x268];
    int m36C;
    int m370;
    char pad374[0x394 - 0x374];
    int m394;
    char pad398[0x41C - 0x398];
    float m41C;
    char pad420[0x448 - 0x420];
    Unk80195404* m448;
    char pad44C[0x4D4 - 0x44C];
    int m4D4;
    char pad4D8[0xBF8 - 0x4D8];
    int mBF8;
};

/* Table of 0x18-byte entries (id at +0, time at +4) searched by time; count at +0x74,
 * entries at +0x78 (fn_80193750 family). */
struct Unk80193750_Ent {
    int m0;
    float m4;
    char pad8[0x10];
};
struct Unk80193750_H {
    char pad0[0x74];
    int m74;
    Unk80193750_Ent* m78;
};
/* Mode record initialised by fn_80191AD8 (mode 1/2/3). */
struct Unk80191AD8_S {
    int m0;
    float m4;
    Unk80183918_Vec3 m8;
    float m14;
    Unk80183918_Vec3 m18;
    float m24;
    int m28;
};
struct Unk80191AD8_Q {
    float m0;
    Unk80183918_Vec3 m4;
    float m10;
    char pad14[0xC];
    float m20;
    int m24;
};
/* Record built by fn_80191B70 / fn_80191BE0 / fn_80191C5C. */
struct Unk80191B70_Sub {
    char pad0[0x1C];
    int m1C;
};
struct Unk80191B70_S {
    void* m0;
    Unk80191B70_Sub m4;
    char pad24[0x78 - 0x24];
    void* m78;
};
struct Unk80191C5C_S {
    void* m0;
    char pad4[0x20 - 4];
    int m20;
    int m24;
    Unk80183918_Vec3 m28;
    Unk80183918_Vec3 m34;
    Unk80183918_Vec3 m40;
    Unk80183918_Vec3 m4C;
    float m58;
    float m5C;
    float m60;
    int m64;
    int m68;
    int m6C;
    int m70;
    int m74;
    void* m78;
};
extern char lbl_8069429C[];

extern "C" {
void fn_8037936C(void* p, const char* s);
float fn_80193880(Unk80193750_H* h, int k, float t);
void fn_80191C5C(Unk80191C5C_S* s, void* owner);
void fn_8026CA8C(void* o);
void fn_8026CB30(void* o);
int fn_80188EF4(void* o);
int fn_80196C50(Unk80195404* p);
}

extern const char lbl_805CB6EC[];
extern const char lbl_805CE008[];
extern const char lbl_805CE00C[];
extern const char lbl_805CE014[];
extern const char lbl_805CE020[];
extern const char lbl_805CE024[];
extern const char lbl_805CE030[];
extern const char lbl_805CE03C[];
extern const char lbl_805CE040[];
extern const char lbl_805CE04C[];
extern const char lbl_805CE050[];
extern const char lbl_805CE054[];
extern const char lbl_805CE05C[];
extern const char lbl_805CE068[];
extern const char lbl_805CE074[];
extern const char lbl_805CE084[];
extern const char lbl_805CE090[];
extern const char lbl_805CE09C[];
extern const char lbl_805CE0B4[];
extern const char lbl_805CE0C8[];
extern const char lbl_805CE0D8[];
extern const char lbl_805CE0E4[];
extern const char lbl_805CE0F0[];
extern const char lbl_805CE0FC[];
extern const char lbl_805CE100[];
extern const char lbl_805CE108[];
extern const char lbl_805CE114[];
extern const char lbl_805CE118[];

#endif /* GAME_TU_80190A00_H */
