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
struct Unk8052DD58_Bits {
    unsigned p : 2;
    unsigned a : 6;
    unsigned e : 6;
    unsigned f : 6;
    unsigned g : 6;
    unsigned h : 6;
};
struct Unk8052DD58_EntData {
    int m0;
    int m4;
    int m8;
    Unk8052DD58_Bits mC;
    unsigned short m10;
    unsigned short m12;
};
struct Unk8052DD58_Ent : Unk8052DD58_EntData {
    virtual void v08();
    virtual void v10(int a, Unk80070DDC_Stream* io);
};
struct Unk8052DD58_Set {
    int m0;
    Unk8052DD58_Ent m4[32];
};
/* Entry as seen by fn_8052E10C and friends (m12 is the halfword at +0x12). */
/* 0x2C-byte element of the first record table (fn_8052CA60): two 12-byte strings at
 * +0xE and +0x1A (fn_8052CEB4 reads them, fn_8052D430 writes them). */
struct Unk8052CA60_Rec {
    unsigned p0 : 8;
    unsigned f0 : 16;
    unsigned f1 : 6;
    unsigned p1 : 2;
    unsigned f2 : 8;
    unsigned f3 : 7;
    unsigned f4 : 10;
    unsigned f5 : 4;
    unsigned f6 : 3;
    unsigned f7 : 4;
    unsigned f8 : 1;
    unsigned f9 : 1;
    unsigned f10 : 1;
    unsigned f11 : 8;
    unsigned f12 : 3;
    unsigned f13 : 7;
    unsigned f14 : 7;
    unsigned f15 : 7;
    unsigned f16 : 7;
    unsigned p2 : 2;
    char m0E[0xC];
    char m1A[0xC];
    char pad26[6];
};

/* Same for the second table (unit 0x8052FF10): strings at +0xF and +0x1B. */
struct Unk8052FF10_Rec {
    unsigned p0 : 8;
    unsigned f0 : 16;
    unsigned f1 : 1;
    unsigned f2 : 6;
    unsigned p1 : 1;
    unsigned f3 : 8;
    unsigned f4 : 7;
    unsigned f5 : 10;
    unsigned f6 : 4;
    unsigned f7 : 3;
    unsigned f8 : 4;
    unsigned f9 : 1;
    unsigned f10 : 1;
    unsigned f11 : 8;
    unsigned f12 : 3;
    unsigned f13 : 7;
    unsigned f14 : 7;
    unsigned p2 : 1;
    unsigned f15 : 7;
    unsigned f16 : 7;
    unsigned f17 : 7;
    unsigned p3 : 3;
    char m0F[0xC];
    char m1B[0xC];
    char pad27[5];
};

struct Unk80531264_Five {
    int w[5];
};
/* Byte tables indexed by (row, column, range class): fn_80531718 reads from +8 with an extra
 * offset d; fn_80531774..fn_80531984 read from +0x11..+0x17. */
struct Unk80531718_Tbl {
    char pad0[8];
    unsigned char m8[1];
};
struct Unk80531774_Tbl {
    char pad0[0x11];
    unsigned char m11[1];
    unsigned char m12[1];
    unsigned char m13[1];
    unsigned char m14[1];
    unsigned char m15[1];
    unsigned char m16[1];
    unsigned char m17[1];
};

/* The table both lookup families read (fn_805312AC fills it): bytes at +8 (indexed with d),
 * then seven tables at +0x11..+0x17. */
struct Unk805312AC_Tbl {
    char pad0[8];
    unsigned char m8[9];
    unsigned char m11[1];
    unsigned char m12[1];
    unsigned char m13[1];
    unsigned char m14[1];
    unsigned char m15[1];
    unsigned char m16[1];
    unsigned char m17[1];
};

/*
 * Unk8052E4C0_Obj (0x388 bytes): a 10x10 int table at +0, then 25 five-word entries from
 * +0x190 (fn_8052E560 appends one, fn_8052E5FC resets them), then a flag bit and a
 * 5-bit entry count at +0x384 (bits 0 and 1..5).
 * Unk8052FA84_List: count at +0, array of Unk8052E4C0_Obj at +4, vptr at +8
 * (virtual 2 at vtable +0x10 takes an index).
 */
struct Unk8052E4C0_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Unk8052E4C0_Obj {
    int m0[10][10];
    Unk8052E4C0_Ent m190[25];
    unsigned flag : 1;
    unsigned n : 5;
    unsigned rest : 26;
    Unk8052E4C0_Obj();
};
extern "C" Unk8052E4C0_Obj* fn_8052E4C0(Unk8052E4C0_Obj* self);
inline Unk8052E4C0_Obj::Unk8052E4C0_Obj() { fn_8052E4C0(this); }
struct Unk8052FA84_ListData {
    int m0;
    Unk8052E4C0_Obj* m4;
};
struct Unk8052FA84_List : Unk8052FA84_ListData {
    virtual int v08();
    virtual void v10(int i);
};

/* 16-byte element of the third record table (fn_8052E654 family is 0x54; this one is
 * fn_8052F5CC / fn_8052F79C's): thirteen fields, 7 bits each except fields 11 and 12 (11 bits). */
struct Unk8052F5CC_Rec {
    unsigned f0 : 7;
    unsigned f1 : 7;
    unsigned f2 : 7;
    unsigned f3 : 7;
    unsigned p0 : 4;
    unsigned f4 : 7;
    unsigned f5 : 7;
    unsigned f6 : 7;
    unsigned f7 : 7;
    unsigned p1 : 4;
    unsigned f8 : 7;
    unsigned f9 : 7;
    unsigned f10 : 7;
    unsigned f11 : 11;
    unsigned f12 : 11;
    unsigned p3 : 21;
};

/*
 * Weighted-table classes of 0x80531A20..0x80534078: each is a header of 8 bytes followed by a
 * float array (the shapes are placeholders named by their dimensions).
 */
template <int R, int C>
struct Unk80531A20_Tbl {
    char pad0[8];
    float m8[R][C];
};
struct Unk80531A20_T14 {
    char pad0[8];
    float m8[14];
    float m40[14][5];
};
struct Unk80531D2C_T3 {
    char pad0[8];
    float m8[5][8][20];
};
struct Unk805325F8_T20 {
    char pad0[8];
    float m8[20];
};
struct Unk80532A18_T4 {
    char pad0[8];
    float m8[8][3][2][2];
};
/* 16-byte records at +8 (fn_80532D68 sets one, fn_80532DA0 reads the float, fn_80532E34 clears 15). */
struct Unk80532D68_Rec {
    int m0;
    float m4;
    int m8;
    int mC;
};
struct Unk80532D68_T {
    char pad0[8];
    Unk80532D68_Rec m8[15];
};
/* 12-byte records at +8 (fn_805334B0 fills one for index c - 0x42; fn_805334EC/fn_8053350C read). */
struct Unk805334B0_Rec {
    float m0;
    int m4;
    int m8;
};
struct Unk805334B0_T {
    char pad0[8];
    Unk805334B0_Rec m8[19];
};

struct Unk805337C8_Rec {
    float m0;
    int m4;
};
struct Unk805337C8_T {
    char pad0[8];
    Unk805337C8_Rec m8[3][14];
};
struct Unk80533B74_T {
    char pad0[8];
    int m8[19][14];
};
struct Unk80533E14_T {
    char pad0[8];
    float m8[14][14];
};

/* Unit 0x80534078: tables with a pick loop returning (base - index). */
struct Unk80534078_T {
    char pad0[8];
    float m8[5][16];
};
struct Unk80534304_T {
    char pad0[8];
    float m8[13];
};
struct Unk80534530_Base {
    int m0;
};
struct Unk80534530_Obj : Unk80534530_Base {
    virtual int v08();
    virtual void v10(int a);
};
/* [k][b][f]: fn_80534598.. set field f, 0x78 bytes per k, 0x18 per b. */
struct Unk80534598_T {
    char pad0[8];
    int m8[45][5][6];
};
struct Unk80534BAC_T {
    char pad0[8];
    float m8[28][5];
};

#include "game/tu_8007A4DC.h"
/* Growable int list (data pointer, used count, capacity, ... , done flag at +0x14). */
struct Unk805352B0_List {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    int m10;
    int m14;
    int At(unsigned i)
    {
        int o = i * 4;
        return *(int*)((char*)m0 + o);
    }
    void Set(unsigned i, int v)
    {
        if (i >= m4)
            m4 = i + 1;
        m0[i] = v;
    }
    void RemoveAt(unsigned i)
    {
        if (i < m4) {
            unsigned j;
            for (j = i; j < m4; j++)
                m0[j] = m0[j + 1];
            m4--;
        }
    }
    void Push(int v)
    {
        if (m4 < m8) {
            m0[m4] = v;
            m4++;
        }
    }
};

/* Name pools: strings of 11 bytes from +0 (fn_80534F64 picks one by index) and of 14 bytes from
 * +0x55F0; the pick count is at +0xE290 and a per-entry flag table at +0xC350 (fn_80534EA0). */
struct Unk80534EA0_T {
    char m0[0x55F0];
    char m55F0[0x6D60];
    int mC350[0x7D0];
    unsigned mE290;
};

struct Unk80538DD8_G {
    char pad0[0x5C];
    void* m5C;
};

/* View of the screen singleton for fn_80536990, whose caller converts the result of
 * Unk8007A4DC_Screen::fn_8007A768 with fctiwz (the real return type is float; the game
 * header declares int). */
struct Unk80536990_Screen : Unk8007A4DC_Screen {
    float fn_8007A768(int a, int b);
};

/* Four string pointers copied to the stack by fn_80532E78 (from lbl_805FEA90). */
struct Unk80532E78_Names {
    const char* w[4];
};

/* Fourteen name pointers copied to the stack by fn_80533E58 (from lbl_805FE998). */
struct Unk80533E58_Names {
    const char* w[14];
};

/* Same for Unk8007B2B0_Screen::fn_8007BB28, whose result fn_80537D24 stores as a float. */
struct Unk80537D24_Screen : Unk8007B2B0_Screen {
    float fn_8007BB28(int a, int b, int c);
};

/* Receiver of the member-pointer table calls in fn_8052CF34 / fn_80530418. */
struct Unk8052CF34_Obj {
    virtual float M(int a);
};
typedef float (Unk8052CF34_Obj::*Unk8052CF34_Pmf)(int);
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
