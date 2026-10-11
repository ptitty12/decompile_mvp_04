/*
 * Types shared by game/tu_80317B88.cpp .. game/tu_8032ECD8.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The functions are methods of effect/particle-style classes (vtables in .data,
 * vptr at +0x18) written as extern "C" functions taking the object explicitly.
 */
#ifndef GAME_TU_80317B88_H
#define GAME_TU_80317B88_H


void* operator new(unsigned int size, int heap);      /* 0x80377428 */
inline void* operator new(unsigned int, void* p) { return p; }

// STRUCTS-BEGIN
struct Vtx16 { float x; float y; float z; float w; };
/* Particle/effect-style object (vtable lbl_806658C0, vptr at +0x18).
 * Evidence: fn_80317B88 (dtor), fn_803188C4/fn_803188FC (slots at m124, counts m118..m120). */
struct Fx {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x8];
    int m24;
    int m28;
    char pad2C[0x4];
    int* m30;
    int* m34;
    int* m38;
    char pad3C[0x40];
    char m7C[60];
    char mB8[60];
    int mF4;
    char padF8[0x20];
    int m118;
    int m11C;
    int m120;
    int m124[6];
    char* m13C;
    char* m140;
    char* m144;
    int* m148[6];
    char pad160[0x10];
};
/* 0x98-byte particle record (array at FxB::mF8; fn_80319C2C, fn_80319D78). */
struct FxPart {
    int m0;
    char pad4[0xc];
    Vtx16 a10[4];
    Vtx16 a50[4];
    int m90;
    int m94;
};
/* Effect batch with a particle array (vtable lbl_80665650, size 0xFC; ctor fn_80319A58).
 * mB4 / m78 are embedded helper objects (render-state / vertex-format builders). */
struct FxB {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x8];
    int m24;
    int m28;
    char* m2C;
    char* m30;
    char* m34;
    const void* m38;
    int m3C;
    char pad40[0x8];
    int m48;
    int m4C;
    int m50;
    char pad54[0x24];
    char m78[60];
    char mB4[60];
    int mF0;
    int mF4;
    FxPart* mF8;
};
/* Object that owns an Unk802A6334 node pool at +0 (vptr lbl_80664008 at +0x1C; ctor fn_80319218). */
struct FxList {
    char m0[28];
    const void* m1C;
};
class FxP {
public:
    int m0;
    int m4;
    virtual ~FxP();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(char c);
};
struct FxReg {
    int m0;
    const void* m4;
    FxReg();
};
class FxRegV {
public:
    int m0;
    virtual ~FxRegV();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
};
/* Payload of the pool nodes (vptr at +8, id at +4; slots 2/4/5 called by fn_8031925C).
 * Small registry object with vptr at +4 (vtable lbl_80665828; ctor fn_803193CC, dtor fn_803193F0).
 * Config object created by fn_8031984C (cBeastScalability, size 0x5C; hash 0xCED26CE8). */
struct FxCfg {
    const void* m0;
    char pad4[0x30];
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
};
class FxBV {
public:
    char pad0[0x18];
    virtual ~FxBV();
};
/* FxB seen through its virtual destructor (slot 1 of the vtable at +0x18).
 * 0x14-byte entry of the two 5-element tables at FxC::a74 / FxC::aD8 (ctor fn_8031A7CC,
 * copy loop in fn_8031B2A8). */
struct FxItem {
    int m0;
    float m4;
    float m8;
    float mC;
    int m10;
};
/* Variable-length source list: a count followed by FxItem entries (fn_8031B2A8). */
struct FxSrc {
    int m0;
    FxItem m4;
};
/* 12-byte entry of the table at FxC+0x28 (fn_8031B228 .. fn_8031B2A8); m4 points at an FxSrc. */
struct FxSlot {
    int m0;
    FxSrc* m4;
    float m8;
};
/* 0x40-byte record (array at FxC::m24; fn_8031A948 parses them, fn_8031AC78 steps them).
 * name at +0, flag m20, counts m28/m2C, rate m30/m34, kind m38, output pointer m3C. */
struct FxRec {
    char name[0x20];
    int m20;
    int m24;
    int m28;
    int m2C;
    float m30;
    float m34;
    int m38;
    float* m3C;
    FxRec();
};
/* Second effect class (vtable lbl_806659F8, vptr at +0x18; ctor fn_8031A7CC). */
struct FxC {
    char pad0[0x14];
    int m14;
    const void* m18;
    int m1C;
    char pad20[0x4];
    FxRec* m24;
    FxSlot a28[6];
    int m70;
    FxItem a74[5];
    FxItem aD8[5];
};
// STRUCTS-END

extern int lbl_8061FF50;
extern int lbl_8061FF44;

#endif
