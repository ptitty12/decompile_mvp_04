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

#ifndef GAME_CHOOSER_H
/* Chooser base (ctor 0x8037B3E8); only the constructor is used here. */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
    virtual ~Unk8037B3E8();
};
extern int lbl_806EF9B4;   /* default heap passed to new */
#endif

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
/* Helper object with its vptr at +4 (deleted in fn_8031D014).
 * Chooser-derived settings object (hash 0xE33E6A08, size 0x20; ctor fn_8031D988, factory fn_8031DB7C). */
struct FxK {
    const void* m0;
    float m4;
    float m8;
    float mC;
    float m10;
    int m14;
    int m18;
    int m1C;
};
class FxLObj3C {
public:
    char pad0[8];
    virtual ~FxLObj3C();
};
class FxLObj40 {
public:
    char pad0[0x42A4];
    virtual ~FxLObj40();
};
struct FxLOwner;
/* Two-level pointer chain read by fn_8031E2C8 (FxL::mC -> +0xA0 -> +0x1C). */
struct FxN {
    char pad0[0x1c];
    int m1C;
};
struct FxM {
    char pad0[0xa0];
    FxN* mA0;
};
/* Object with vptr lbl_80665CF8 at +0 (ctor fn_8031DD54, dtor fn_8031DE38). */
struct FxL {
    const void* m0;
    int m4;
    void* m8;
    FxM* mC;
    void* m10;
    char pad14[0x4];
    float m18;
    void* m1C;
    int m20;
    char pad24[0x8];
    int m2C;
    float m30;
    int m34;
    int m38;
    FxLObj3C* m3C;
    FxLObj40* m40;
    int m44;
    int m48;
    float m4C;
    float m50;
    int m54;
    int m58;
};
/* Box of four floats at lbl_8068F1D4 (default value returned by fn_8031E1D4). */
struct FxBox {
    char pad0[0x4];
    float m4;
    float m8;
    float mC;
    float m10;
};
struct FxQ2;
/* Object of fn_8031F080: an int stack (count at +0x5C, entries from +0x64). */
struct FxQ {
    char pad0[0xc];
    FxQ2* mC;
    char pad10[0x4c];
    int m5C;
    char pad60[0x4];
    int a64[8];
};
struct FxVec { int x; int y; int z; };
/* Helper reached through FxQ::mC (vector at +0x60 is copied by fn_8031F0A0). */
struct FxQ2 {
    char pad0[0x60];
    FxVec m60;
    char pad64[0x8];
};
struct FxS {
    int m0;
    int m4;
    const void* m8;
    FxS(int a);
};
struct FxT {
    const void* m0;
    FxT();
};
/* Small object with vptr lbl_80665110 at +8 (ctor fn_8031F0C4, dtor fn_8031F0EC).
 * Sort record of fn_8031F170 (key m8, secondary key m10). */
struct FxR {
    char pad0[0x8];
    int m8;
    char padC[0x4];
    float m10;
};
struct FxColor { float a; float b; float c; float d; };
struct FxMat { float m[16]; };
struct FxU {
    int m0;
    int m4;
    FxU();
};
struct FxV;
/* Two-int record initialised to -1 (ctor fn_803220E0).
 * Second node of the class that fn_80323848 walks (m44 / m48 / m4C / m50, see FxL). */
struct FxV {
    char pad0[0x44];
    int m44;
    FxV* m48;
    float m4C;
    float m50;
};
struct FxW {
    int m0;
    const void* m4;
    float m8;
};
/* Singleton helper (size 0x10, ctor fn_803224E8, vptr lbl_80665248 at +4).
 * Object with the owner pointer at +8 (fn_803238D0, fn_80323904, fn_80323928). */
struct FxX {
    char pad0[0x8];
    void* m8;
    char padC[0x4];
};
/* Any object whose vptr sits at +0x18 (dtor stubs that only rewrite the vptr). */
struct FxHdr {
    char pad0[0x18];
    const void* m18;
};
/* Key record compared by fn_803249D4 (int, float, int, int) and tested by fn_80324A24. */
struct FxY {
    int m0;
    float m4;
    int m8;
    int mC;
};
struct FxZ {
    int m0;
    float m4;
    int m8;
    int mC;
    float m10;
    int m14;
};
/* Growable ring table of 16-byte entries plus 0x18-byte records (ctor fn_80324EF0, dtor fn_80324F78);
 * vptr (lbl_80665E48) at +0x2C. m24 entries in m0, m28 records in m4, byte buffer mC (size m10). */
class FxZT {
public:
    int* m0;
    char* m4;
    int m8;
    int* mC;
    int m10;
    int* m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    virtual ~FxZT();
};
/* Pair of shorts at the pointer held by lbl_8061B8C0+0x30 (fn_803265F0). */
struct FxShorts {
    short m0;
    short m2;
};
struct FxZ6C {
    int m0;
    int m4;
    int m8;
};
struct FxAIB;
struct FxAIC;
struct FxAID;
class FxZT;
/* Controller object with its vptr at +0x4F4 (vtable lbl_80665E30; ctor fn_803263C4). */
struct FxAI {
    FxZT* m0;
    FxZT* m4;
    char pad8[0x4b0];
    int m4B8;
    FxAIB* m4BC;
    int a4C0[13];
    const void* m4F4;
    char pad4F8[0x8];
};
/* Pointer chain of fn_80326C20: ctx->m4BC->m564->m14 is the state id. */
struct FxAIC {
    char pad0[0x14];
    int m14;
};
struct FxAIB {
    char pad0[0x564];
    FxAIC* m564;
    char pad568[0xf4];
    int a65C[13];
    char pad690[0x10];
};
/* Two-level record walked by fn_80326DF0 / fn_80326E64 (ring of 16-byte entries). */
struct FxRingH {
    int* m0;
    char pad4[0x14];
    int m18;
    int m1C;
    int m20;
};
struct FxRing {
    FxRingH* m0;
    FxRingH* m4;
};
struct FxAID {
    char pad0[0x18];
    int m18;
};
struct FxV2 { float x; float y; };
/* 0x18-byte record of FxZT::m4 (written by fn_80325080). */
struct FxEnt {
    int m0;
    float m4;
    int m8;
    int mC;
    float m10;
    int m14;
};
struct FxPtr { FxZT* m0; };
typedef int (*FxPred)(FxZ*, int);
/* Pointer holder passed by pointer to the struct-returning lookups (fn_80326F44 ..).
 * Base of the effect classes (ctor fn_803282A8 / fn_80328318, dtor fn_80328374; vptr at +0x18,
 * vtables lbl_80664020 -> lbl_80666F98 while the dtor runs). */
struct FxBase {
    char pad0[0x14];
    int m14;
    const void* m18;
    int m1C;
    int m20;
    char pad24[0x1c];
};
struct FxMS {
    unsigned char m;
    unsigned char s;
};
struct FxSing {
    int m0;
    int m4;
    const void* m8;
    FxSing();
};
class FxSingV {
public:
    int m0;
    int m4;
    virtual ~FxSingV();
};
/* Minutes / seconds pair packed in a halfword (fn_8032A0C0, fn_8032A118, fn_8032A278).
 * Singleton helper with vptr lbl_80665E60 at +8 (ctor fn_80329908, dtor fn_80329924).
 * Entry of the 0xFA-element table at lbl_806E2274 (fn_803296E8 searches for a free one). */
struct FxSlot8 {
    int m0;
    int m4;
};
// STRUCTS-END

extern int lbl_8061FF50;
extern int lbl_8061FF44;

#endif
