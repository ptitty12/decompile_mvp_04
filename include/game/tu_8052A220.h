#ifndef GAME_TU_8052A220_H
#define GAME_TU_8052A220_H

#include "game/tu_80070DDC.h"

/*
 * Database overlay 0x8052A220-0x8052CA60 (names are placeholders).
 *
 * Unk8052A220_PalData: 0x1C bytes, 41 five-bit fields, six per word (the last
 * word holds five). fn_8052A220 writes every field, fn_8052A404 sets field
 * `idx` (switch 0..0x28), fn_8052A894 reads it. Bitfields fill from the MSB
 * (rlwimi shifts 27, 22, 17, 12, 7, 2).
 * Unk8052A220_Pal: the same data plus a vptr at +0x1C (0x20 bytes): fn_8052ADDC
 * walks an array of them calling fn_8052A220, fn_8052AE1C calls virtual 2
 * (vtable +0x10) on each. fn_8052AD9C is a serializer slot: it hands the 0x1C
 * data bytes to the stream.
 */
struct Unk8052A220_PalData {
    unsigned f0 : 5;
    unsigned f1 : 5;
    unsigned f2 : 5;
    unsigned f3 : 5;
    unsigned f4 : 5;
    unsigned f5 : 5;
    unsigned p0 : 2;
    unsigned f6 : 5;
    unsigned f7 : 5;
    unsigned f8 : 5;
    unsigned f9 : 5;
    unsigned f10 : 5;
    unsigned f11 : 5;
    unsigned p1 : 2;
    unsigned f12 : 5;
    unsigned f13 : 5;
    unsigned f14 : 5;
    unsigned f15 : 5;
    unsigned f16 : 5;
    unsigned f17 : 5;
    unsigned p2 : 2;
    unsigned f18 : 5;
    unsigned f19 : 5;
    unsigned f20 : 5;
    unsigned f21 : 5;
    unsigned f22 : 5;
    unsigned f23 : 5;
    unsigned p3 : 2;
    unsigned f24 : 5;
    unsigned f25 : 5;
    unsigned f26 : 5;
    unsigned f27 : 5;
    unsigned f28 : 5;
    unsigned f29 : 5;
    unsigned p4 : 2;
    unsigned f30 : 5;
    unsigned f31 : 5;
    unsigned f32 : 5;
    unsigned f33 : 5;
    unsigned f34 : 5;
    unsigned f35 : 5;
    unsigned p5 : 2;
    unsigned f36 : 5;
    unsigned f37 : 5;
    unsigned f38 : 5;
    unsigned f39 : 5;
    unsigned f40 : 5;
};
struct Unk8052A220_Pal : Unk8052A220_PalData {
    virtual int v08();
    virtual void v10(int a, Unk80070DDC_Stream* io);
};

/*
 * Unk8052B978_Tbl: a growable list of 0x1C-byte keys (fn_8052B978 is its ctor
 * and builds m0 entries into m8; m4 is the used count, fn_8052BE28 appends).
 * Unk8052B5C4_Ent: word 0 is a halfword (fn_8052B5C4 clamps into it), then a
 * 10-bit field (fn_8052B5E8), a 1-bit field (fn_8052B624) and a 5-bit field
 * (fn_8052BED8 sets it to 8; fn_8052BCC8 tests it for 0). Two 12-byte subrecords
 * follow at +4 and +0x10 (fn_8052B204 streams m0 then the other 8 bytes).
 */
extern "C" void* fn_803FFC58(void* p, int v, int n);
struct Unk8052B1DC_Sub {
    int m0;
    unsigned char m4;
    char pad5[7];
    Unk8052B1DC_Sub();
};
struct Unk8052B5C4_Ent {
    unsigned short m0;
    unsigned f2 : 10;
    unsigned f3 : 1;
    unsigned f4 : 5;
    Unk8052B1DC_Sub m4[2];
    Unk8052B5C4_Ent();
};
extern "C" void fn_8052B1DC(Unk8052B1DC_Sub* p);
extern "C" void fn_8052B59C(Unk8052B5C4_Ent* p);
inline Unk8052B1DC_Sub::Unk8052B1DC_Sub() { fn_8052B1DC(this); }
inline Unk8052B5C4_Ent::Unk8052B5C4_Ent() { fn_8052B59C(this); }
struct Unk8052B978_Tbl {
    int m0;
    unsigned m4;
    Unk8052B5C4_Ent* m8;
};

/*
 * Record-collection family (Unk80071604 base: m14 id, m1C count, m20 vptr, m24
 * element array; see tu_80070DDC.h). The overlay units hold many near-identical
 * tables of it: ctor (base ctor, vptr, new[] of count elements, bzero, default
 * name hash), dtor with in-charge, clear-element, stream slot. Element sizes
 * differ (8, 0x2C, 0x54 ...).
 */
Unk80071604* fn_80071604(Unk80071604* self, const char* name, Obj* type, unsigned count);
void fn_80071688(Unk80071604* self, int chrg);
void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io);
unsigned fn_8007366C(const char* a, const char* b);
unsigned fn_800736EC(const char* s);
void* operator new(unsigned int size, int heap);
void* operator new[](unsigned int size, int heap);
extern "C" void fn_8040074C(void* p, unsigned n);
extern "C" void fn_80377488(void* p);
extern "C" void fn_80377408(void* p);

/* By-value result of fn_80329FA0 (returned through a hidden pointer; the function
 * is variadic: callers emit crclr). Evidence: fn_8052D5F4/D664/D6E0 read byte 0,
 * halfword 2 and byte 1 of the result. */
struct Unk80329FA0_Out {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
};
extern "C" Unk80329FA0_Out fn_80329FA0(int v, ...);

/* 12 bytes copied by fn_8052DD20 (three ints read from lbl_805FE1D4). */
struct Unk8052DD20_Tri {
    int w[3];
};

/*
 * Unk8052DD58_Ent: 0x18-byte record (fn_8052DD58 clears it: three ints, then two
 * 4-byte members cleared with bzero; the vptr is at +0x14, vtable lbl_80682810).
 * Unk8052DD58_Set: count at +0, 32 entries from +4 (fn_8052DE9C builds them).
 */
struct Unk8052DD58_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    const void* m14;
};
struct Unk8052DD58_Set {
    int m0;
    Unk8052DD58_Ent m4[32];
};
struct Unk8052E408_Obj {
    char pad0[0x14];
    const void* m14;
};
struct Unk8052DE88_Rec {
    char pad0[0xC];
    unsigned mC_flag : 1;
    unsigned mC_rest : 31;
    char pad10[2];
    unsigned short m12;
};

#endif
