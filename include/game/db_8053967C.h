/*
 * Types for the database overlay units db/tu_8053967C .. db/tu_8054CBBC
 * (range 42). Names are placeholders: Db<addr> for the first function that
 * proves a type, m<off> for offsets.
 */
#ifndef GAME_DB_8053967C_H
#define GAME_DB_8053967C_H

#include "game/tu_80070DDC.h"
#include "game/tu_80084910.h"
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

#endif
