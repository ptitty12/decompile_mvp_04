#ifndef GAME_TU_80034BBC_H
#define GAME_TU_80034BBC_H

/*
 * Types for src/game/tu_80034BBC.cpp (reconstructed).
 *
 * Unk80034D00 is a small polymorphic class (m0, m4, then the vptr at +8; ctor
 * fn_80034D00, virtual destructor fn_80034D20, virtual 2 = fn_80034D54 which
 * receives the address of one table element). Its derived classes
 * (fn_80034E14) forward addresses into the big table returned by fn_80038EB4
 * through virtual 2; the fn_800349xx.. fn_80035xxx wrappers below compute
 * those addresses from bounds-checked indices.
 */
#include "game/tu_8002D15C.h"

struct Unk80034D00 {
    int m0;
    int m4;
    virtual ~Unk80034D00();
    virtual void v2(void* p);
    void SetVptr(const void* v)
    {
        *(const void**)((char*)this + 8) = v;
    }
};

/* 0x10-byte handle object (ctor fn_80034B94, dtor fn_80034BBC, vtable 0x80649D70 at +0xC). */
struct Unk80034B94 {
    int m0;
    int m4;
    int m8;
    const void* mC;
};

extern char lbl_80649A90[];
extern char lbl_806499D0[];
extern char lbl_80649D70[];

extern "C" {
void* fn_80030938();
void fn_80030C90(void* mgr, int i);
void fn_80030EA4(void* mgr, int i, int a, int b, int c);
void fn_80030F18(void* mgr, int i, float f);
void fn_80030F94(void* mgr, int i);
int fn_800309AC(void* mgr, Unk80034B94* o, int a);
int fn_8040ABA0();
void fn_80039A3C(int a, int b, int c);
void fn_80035E94(int a);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
void fn_8004181C(void* o, int a, int b, int c, int d, int e, int f);
}

/* Table object returned by fn_80038EB4; only the arrays these wrappers address are named. */
struct Unk80038EB4_Tbl {
    int m0[2][4][3][4];
    int m180[2][4][3][4];
    int m300[2][4][3][4];
    int m480[2][4][4];
    int m500[2][4][4];
    int m580[2][4][10][4];
    int mA80[2][4][10][4];
    int mF80[2][4][2][10][4];
    int m1980[2][3][4];
    int m19E0[2][5][5][2];
    int m1B70[2][5][3][2][4];
    int m1F30[2][5][5][2][2][4];
    int m2BB0[2][5][2][2][2][4];
    int m30B0[2][4][2][10][2][4];
    char pad44B0[0x4DB0 - 0x44B0];
    int m4DB0[2][4][4];
    int m4E30[2][2][4];
    int m4E70[2][2][4];
};

#endif /* GAME_TU_80034BBC_H */
