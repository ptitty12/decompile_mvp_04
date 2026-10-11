#ifndef GAME_TU_801800FC_H
#define GAME_TU_801800FC_H

/*
 * Types for src/game/tu_801800FC.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/chooser.h"

/* 0x5C-byte record: eight words at +0/+4/+8/+C and +0x10..+0x1C, then byte
 * flags at +0x24 (ten-byte rows), +0x38..+0x3C, and the owner ctx at +0x58.
 * Evidence: reset fn_80180124, row sum fn_80180168, dtor fn_801800FC (deleted
 * by the owner), fn_8018019C / fn_801808A4. */
struct Unk801808A4_Ctx;
struct Unk801800FC {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    char pad20[4];
    unsigned char m24[20];
    unsigned char m38;
    unsigned char m39;
    unsigned char m3A;
    unsigned char m3B;
    unsigned char m3C;
    char pad3D[0x58 - 0x3D];
    Unk801808A4_Ctx* m58;
    ~Unk801800FC();
};

/* Two team sides of 0xE64 bytes each, then side flags. Evidence: fn_801808A4
 * (m1B4 byte table, 128 bytes summed), fn_80180534 (m16C count), the getters
 * at 0x80183918 (m1CD0 selects which side an index above 2 maps to). */
struct Unk801808A4_Side {
    char pad0[0x16C];
    int m16C;
    char pad170[0x1B4 - 0x170];
    unsigned char m1B4[0x80];
    char pad234[0xE64 - 0x234];
};
struct Unk801808A4_Z {
    Unk801808A4_Side m0[2];
    unsigned char m1CC8;
    unsigned char m1CC9;
    unsigned char m1CCA;
    unsigned char m1CCB;
    char pad1CCC[4];
    int m1CD0;
};
struct Unk801808A4_Y {
    char pad0[0x14];
    Unk801808A4_Z* m14;
};
struct Unk801808A4_Ctx {
    char pad0[0x6F4];
    int m6F4;
    Unk801808A4_Y* m6F8;
};

struct Unk80183918_Vec3 {
    float m0;
    float m4;
    float m8;
};
struct Unk80183918_Ent16 {
    Unk80183918_Vec3 v;
    float mC;
};
struct Unk80181140_Mtx {
    float w[16];
};
struct Unk80181140_E {
    Unk80183918_Vec3 m0;
    char pad0C[0x20 - 0x0C];
    Unk80181140_Mtx m20;
    float m60;
    float m64;
    float m68;
    int m6C;
    char m70[0x20];
    char pad90[0xA0 - 0x90];
};
/* 0x38-byte named marker (8 at +0x37C, count at +0x540; fn_801855FC / fn_801857D4). */
struct Unk801855FC_E {
    int m0;
    Unk80183918_Vec3 m4;
    char m10[0x20];
    int m30;
    int m34;
};
/* 0x30-byte named point (64 at +0x544, count at +0x53C; fn_8018567C). */
struct Unk8018567C_E {
    int m0;
    Unk80183918_Vec3 m4;
    char m10[0x20];
};

/* The stadium object (ctor fn_80181140; vptrs at +0x98 and +0xB8, owner ctx at
 * +0xBC and again at +0x1D40). Arrays seen through the getters at 0x80183918. */
struct Unk80181140 {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
    Unk801808A4_Ctx* mBC;
    char padC0[0x360 - 0xC0];
    int m360;
    Unk80183918_Vec3 m364;
    int m370;
    struct Unk80182E54_H* m374;
    float m378;
    Unk801855FC_E m37C[8];
    int m53C;
    int m540;
    Unk8018567C_E m544[64];
    int m1144;
    char pad1148[0x1160 - 0x1148];
    Unk80181140_E m1160[16];
    Unk80183918_Ent16 m1B60[2][8];
    Unk80183918_Vec3 m1C60[2][4];
    Unk80183918_Vec3 m1CC0[2][4];
    Unk80183918_Ent16 m1D20[2];
    Unk801808A4_Ctx* m1D40;
    char pad1D44[0x1D6C - 0x1D44];
    int m1D6C;
};

extern char lbl_8065FF08[];
extern char lbl_8065FF98[];
extern Unk80181140_Mtx lbl_8060E938;
struct Unk80181140_F {
    float m0;
};
extern Unk80181140_F lbl_805CD510;
extern Unk80183918_Vec3 lbl_806055AC;

/* Maps an index above 2 onto a side: 3 follows m1CD0, the rest are inverted. */
inline int Unk801808A4_Sel(Unk801808A4_Ctx* c, int idx)
{
    int t = idx;
    if (idx > 2) {
        int f = 0;
        if (c->m6F8->m14->m1CD0)
            f = 1;
        t = f;
        if (idx != 3)
            t = f ^ 1;
    }
    return t;
}

/* Record returned by the lookup fn_80150FC0: a position at +4, a value at +0x10. */
struct Unk80182464_Rec {
    char pad0[4];
    Unk80183918_Vec3 m4;
    float m10;
};

inline Unk80183918_Vec3 Unk80182464_Pos(const Unk80182464_Rec* r)
{
    return r->m4;
}

struct Unk80182E54_H {
    short h0;
    short h2;
};
struct Unk80182E54_Base8 {
    char pad0[8];
};
class Unk80182E54_XV : public Unk80182E54_Base8 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};
struct Unk80182E54_X : public Unk80182E54_XV {
    char pad0C[0x94 - 0xC];
    int m94;
};
class Unk80182E54_EV : public Unk80182E54_Base8 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
extern int lbl_8061C8F8;
extern int lbl_8061C8FC;
extern void* lbl_8061FEDC;

extern "C" {
Unk80270BA0_X* fn_801A4B34(Unk801808A4_Ctx* c);
void fn_801A4C84(Unk801808A4_Ctx* c);
Unk80182E54_X* fn_801A4CE8(void* c, int a);
void fn_8031259C(void* p);
void fn_803125D0(void* p);
void* fn_80319330(void* p, int k);
int fn_80183EA0(void* a, void* b, int c);
void fn_80308C60(void* a, int b, int c);
void fn_8030AC88(void* p);
void fn_802CBE04(Unk80273498_Pos* p, float* a, float* b, float* c);
void fn_80183FFC(Unk80181140* o, int k, void* x, void* y, int z);
Unk80182464_Rec* fn_80150FC0(int key);
void fn_8026CA58(void* o);
void fn_801829FC(void* o);
Unk80270BA0_X* fn_801A49F0(Unk801808A4_Ctx* c, int side, int idx);
int fn_80097190(Unk801808A4_Side* p, int j);
int fn_80097300(Unk801808A4_Side* p, int x);
int fn_80180A34(Unk801808A4_Ctx* c, int x);
int fn_801806C8(Unk801808A4_Ctx* c, int a, int b, int d);
unsigned int fn_8035E318(void* p);
void fn_80081CCC(Unk801808A4_Z* z, int v);
void fn_801A656C(void* c, Unk80270BA0_X* o, int a);
void fn_802547C0(void* p, int a);
void fn_80244A64(Unk80270BA0_X* o, int a, int b);
void* fn_8026C75C(void* self, int a, void* owner);
void fn_80181D84(Unk80181140* o);
void fn_80181D48(Unk80181140* o);
void fn_80182140(Unk80181140* o);
void fn_80182590(Unk80181140* o);
void fn_80181280(Unk80181140* o);
void fn_80181670(Unk80181140* o, int a);
}


/* Skeleton ("skt") attribute class derived from the chooser root Unk8037B3E8:
 * ctor fn_80180FE8 (hash 0x6F618F85, size 0x8C, vtable 0x8065F950), slot 2
 * registers 17 flag/float pairs (flags at +4..+0x44, floats at +0x48..+0x88). */
class Unk80180FE8 : public Unk8037B3E8 {
public:
    Unk80180FE8();
    virtual ~Unk80180FE8();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
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
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
};
extern Unk80180FE8* lbl_8061C714[5];
extern void* lbl_806E03C8[5];
extern Unk80180FE8* lbl_8061C724;
extern "C" void* fn_8037CF5C(Unk8037C7FC* c, unsigned int hash, void* obj);
extern "C" void* fn_8018105C(Unk80180FE8* self);

#endif /* GAME_TU_801800FC_H */
