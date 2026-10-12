/*
 * Types for the database overlay units db/tu_8053967C .. db/tu_8054CBBC
 * (range 42). Names are placeholders: Db<addr> for the first function that
 * proves a type, m<off> for offsets.
 */
#ifndef GAME_DB_8053967C_H
#define GAME_DB_8053967C_H

#include "game/tu_80070DDC.h"
#include "game/tu_80084910.h"
#include "game/tu_8007F198.h"
#include "game/clampiter.h"
#include "game/overlay.h"

void* operator new[](unsigned int size, int heap); /* 0x803774A8 */

extern "C" {
void fn_8040074C(void* p, unsigned n); /* bzero */
char* fn_8040B61C(char* dst, const char* src); /* strcpy */
char* fn_8040B830(char* dst, const char* src, unsigned n); /* strncpy */
int fn_8040B6A0(const char* s); /* strlen */
void fn_80329FA0(void* out, int v, ...);
}
unsigned fn_8007366C(const char* a, const char* b);
Unk80071604* fn_80071604(Unk80071604* self, const char* name, Obj* type, unsigned count);
void fn_80071688(Unk80071604* self, int chrg);
void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io);
extern void* lbl_8061930C;
extern const char lbl_805B3B4C[];

/* Member-pointer table dispatch (see Unk80084910_PObj). */
struct DbPObj {
    virtual float M(int a);
};
typedef float (DbPObj::*DbPmf)(int);

/*
 * Record of the 0x2C-stride table (ctor fn_8053CC9C, getter fn_8053CE9C,
 * setter fn_8053D1A8, string setter fn_8053D580). Bit layout from the getter's
 * extrwi/srwi operands; two strings follow the 14 bits at +0xE and +0x1A.
 */
struct Db8053CC9C_Rec {
    unsigned a0 : 8;
    unsigned f0 : 16;
    unsigned f1 : 6;
    unsigned p0 : 2;
    unsigned f2 : 8;
    unsigned f3 : 1;
    unsigned f4 : 1;
    unsigned f5 : 3;
    unsigned f6 : 1;
    unsigned f7 : 7;
    unsigned f8 : 6;
    unsigned p1 : 5;
    unsigned f9 : 8;
    unsigned f10 : 7;
    unsigned f11 : 7;
    unsigned f12 : 7;
    unsigned p2 : 3;
    unsigned f13 : 7;
    unsigned f14 : 7;
    char name1[12];
    char name2[18];
};

struct Db8053CC9C_Buf3 {
    unsigned short a;
    unsigned short b;
};
struct Db8053CC9C_Buf2 {
    unsigned char a;
    unsigned char b;
    unsigned short pad;
};

/* Packed source record that fn_8053DB30 converts: two words, decoded by shifts. */
struct Db8053CC9C_Src {
    unsigned w0;
    unsigned w4;
};

/* Destination of fn_8053DD68: first words of a Src, three fields. */
struct Db8053CC9C_SrcBits {
    unsigned char yr;
    unsigned g1 : 6;
    unsigned g2 : 3;
    unsigned rest : 15;
    unsigned w4;
};

/* Source of fn_8053DD68 (a Rec2C's leading words, seen as a halfword at +1 etc.). */
struct Db8053CC9C_Src2 {
    unsigned a0 : 8;
    unsigned f0 : 16;
    unsigned f1 : 6;
    unsigned p0 : 2;
    unsigned f2 : 8;
    unsigned f3 : 1;
    unsigned f4 : 1;
    unsigned f5 : 3;
    unsigned f6 : 1;
    unsigned f7 : 7;
    unsigned f8 : 6;
    unsigned p1 : 5;
    unsigned f9 : 8;
};

/* 4-byte calendar record passed by value to fn_80329E74 (month, day, year). */
struct Db8053CC9C_Date {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    Db8053CC9C_Date() {}
};

struct Db8053CC9C_A5 {
    int w[5];
};

extern "C" {
void fn_800901C0(char* a, int b, unsigned c, char* d, int e, unsigned f);
int fn_80090244(unsigned v);
unsigned fn_8032A2CC(unsigned m, unsigned short y);
int fn_80329E74(Db8053CC9C_Date d);
void* fn_803FFA60(void* s, int a, int n);
}

/*
 * Int list used by the roster screens (fn_8053967C, fn_80539900, ...): data
 * pointer, count, capacity, cursor, vptr slot at +0x10 and a built flag at +0x14.
 */
struct Db8053967C_List {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    int m10;
    int m14;
};

/*
 * 0x1E0-byte roster record (Unk8007F198_Rec): an int list at +0 (data, count,
 * capacity), two pairs of {id, value} per half at +0x1B0 and three ids at +0x1D0.
 */
struct Db8053967C_Pair {
    int id;
    int val;
};
struct Db8053967C_Rost {
    int* m0;
    unsigned m4;
    unsigned m8;
    char padC[0x1B0 - 0xC];
    Db8053967C_Pair m1B0[2][2];
    int m1D0[3];
};

/* Byte index list embedded at +0x14 of Db8053967C_Idx (data, count, capacity, cursor). */
struct Db8053967C_Bytes {
    unsigned char* m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
};

/* An int list (data, count, ...) followed by a byte index list at +0x14. */
struct Db8053967C_Idx {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    int m10;
    Db8053967C_Bytes m14;
};

/* Object built by fn_8053BB80 (size 0x58): records of 0x1E0 bytes at +0x10. */
struct Db8053967C_DbObj {
    char* m0;
    int m4;
    int m8;
    int mC;
};
struct Db8053967C_Obj58 {
    int m0;
    Db8053967C_DbObj* m4;
    unsigned m8;
    int mC;
    char* m10;
};

int fn_800736EC(const char* s);

unsigned fn_8007F488(Unk8007F198_A* a, int b);
int fn_8007F4D0(Unk8007F198_A* a, int b, int c);
extern const char* lbl_80622AC4[];

extern "C" {
void fn_80539C44(Db8053967C_List* l, int e);
int fn_8053CA58(Db8053967C_Idx* x);
int fn_8053CA8C(Db8053967C_Idx* x, int i);
unsigned char fn_8053CAD4(Db8053967C_Idx* x, int i);
unsigned fn_8053B6CC(Db8053967C_Rost* r, int id);
unsigned char fn_8053B210(Db8053967C_Rost* r, int id);
int fn_8053BA1C(Db8053967C_Rost* r, int h);
void fn_8053B548(char* p, int v);
int fn_80377E90(Db8053967C_DbObj* d, int* a, int* b, int id);
void fn_80377CD8(Db8053967C_DbObj* d, int a, int b, int c);
void fn_803791BC();
int fn_800902B0(int a, int b);
}
int fn_80083FC0(int a);
int fn_8008FCC8(int a);

/* 0x30-byte result record built by fn_8053E240 (m0 returned, m8 optional float out). */
struct Db8053E240_Ctx {
    int m0;
    int m4;
    float m8;
    char padC[0x24];
};

/* ---- unit 80541F40 ---- */
/* Object whose +0x44 field is passed to the fn_8057Dxxx helpers (fn_80543A68). */
struct Db80541F40_Obj {
    char pad0[0x40];
    int m40;
    int m44;
};
extern Db80541F40_Obj* lbl_80619948;
/* 0x6C-byte slot of the table at +0 (id, count, 25 words); the count of slots is at +0x3528. */
struct Db80541F40_Slot {
    int m0;
    int m4;
    int m8[25];
};
struct Db80541F40_Slots {
    Db80541F40_Slot s[1];
};
/* Int list as returned by fn_800A199C: data pointer and count. */
struct Db80541F40_IL {
    int* m0;
    unsigned m4;
};
extern int lbl_80622BE8;
/* Front-end state object: int array at +0x32E0 and its current index at +0x32EC. */
struct Db80541F40_Cur {
    char pad0[0x32E0];
    int* m32E0;
    char pad32E4[8];
    int m32EC;
};
extern int lbl_80602DC0[][11];
extern unsigned char lbl_8060E9F1[];
int fn_80378568(const char* s, int n);
unsigned fn_8007FE0C(Unk8007F198_E* e);
unsigned fn_8007FE60(Unk8007F198_E* e, unsigned a, int b);
int fn_8007FE84(Unk8007F198_E* e, unsigned a, int b, unsigned char c);
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);

#endif
