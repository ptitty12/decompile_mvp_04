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
struct FxRec;
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
    FxRec* m0;
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
struct FxV3 { float x; float y; float z; };
class FxEObj;
/* Per-effect record of the FxD class (0x128 bytes; array at FxD::m24, kind at +0x38,
 * rate floats at +0x30/+0x34, id at +0x20). Evidence: fn_8031B354, fn_8031B3E0, fn_8031C1E4. */
struct FxRec2 {
    char pad0[0x20];
    int m20;
    float m24;
    int m28;
    char pad2C[0x4];
    float m30;
    float m34;
    int m38;
    char pad3C[0xec];
};
/* 12-byte entry of the 5-element tables at FxD+0x2C / FxD+0x68 (ctor fn_8031B4EC). */
struct FxItemD {
    FxRec2* m0;
    float m4;
    int m8;
};
/* Variable-length source list: a count followed by FxItemD entries (fn_8031BFD8). */
struct FxSrcD {
    int m0;
    FxItemD m4;
};
/* 12-byte entry of the table at FxD+0xA4 (fn_8031BF58 .. fn_8031BFD8); m4 points at an FxSrcD. */
struct FxSlotD {
    int m0;
    FxSrcD* m4;
    float m8;
};
/* Third effect class (vtable lbl_80665968, vptr at +0x18; ctor fn_8031B4EC). */
struct FxD {
    char pad0[0x14];
    int m14;
    const void* m18;
    char pad1C[0x8];
    FxRec2* m24;
    int m28;
    FxItemD a2C[5];
    FxItemD a68[5];
    FxSlotD aA4[6];
    char padEC[0x14];
};
/* Fourth effect class (vtable lbl_80665128, vptr at +0x18; ctor fn_8031C62C): m2C is a
 * one-shot flag, m24 the start time and m28 the duration (fn_8031C6C0, fn_8031C714). */
struct FxG {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x8];
    int m24;
    int m28;
    int m2C;
};
/* Fifth effect class (vtable lbl_806651B8, vptr at +0x18; ctor fn_8031CD88). */
struct FxH {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x8];
    int m24;
    char pad28[0x8];
};
/* Float triples (20 entries from +0x2C) of the class that fn_8031B880 initialises. */
struct FxE {
    char pad0[0x20];
    int m20;
    float m24;
    int m28;
    FxV3 a2C[20];
    int m11C;
    FxEObj* m120;
    float m124;
    char pad128[0x8];
};
class FxEObj {
public:
    char pad0[0x98];
    virtual ~FxEObj();
};
struct FxCtxB { int m0; int m4; };
class FxIObj;
/* Engine context at lbl_8061FEDC (fields read by fn_8031C714, fn_8031CB4C, fn_8031CED8). */
struct FxCtx {
    char pad0[0x14];
    int m14;
    int m18;
    char pad1C[0xc];
    int m28;
    int m2C;
    int m30;
    char pad34[0x4];
    FxCtxB* m38;
    char pad3C[0x1c8];
    int m204;
    int m208;
    char pad20C[0x4];
};
/* Object created by fn_8031CE68 (size 0x1B0, ctor fn_8031CED8); mCC is an embedded helper. */
struct FxI {
    int m0;
    int m4;
    int m8;
    int mC;
    FxIObj* m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    int m34;
    char pad38[0x8];
    int m40;
    int m44;
    int m48;
    char pad4C[0x80];
    char mCC[220];
    int m1A8;
    int m1AC;
};
struct FxHooks { void* m0; void* m4; int m8; };
class FxIObj {
public:
    int m0;
    virtual ~FxIObj();
};
// STRUCTS-END

extern int lbl_8061FF50;
extern int lbl_8061FF44;

#endif
