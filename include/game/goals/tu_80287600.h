/*
 * Types for animation/goals/tu_80287600.cpp (goal logic, 0x80287600-0x8028989C).
 *
 * Nothing here comes from original headers: layouts are inferred from the
 * functions in that unit and its neighbours. Names are placeholders
 * (Unk<addr> = class named after its init function, fn_<addr>, m<offset>).
 */
#ifndef GAME_GOALS_TU_80287600_H
#define GAME_GOALS_TU_80287600_H

#include "game/chooser.h"

/* The goal object. No vptr; data from +0. Offsets seen in this unit: +0 int,
 * +0x1C position (set by fn_8027A898 in tu_8027A84C.cpp, which also sets +0x2C
 * to "position is non-zero"), +0x38 type, +0x44 context whose +0xC is the
 * owning player (read by fn_8027A90C), +0x48 kind (set by fn_80287D50), +0x4C
 * phase (-1 initially), +0x50 index into the 0x805DED28 position table (also
 * set by fn_80287E04), +0x54 explicit position (valid when +0x60 is 1),
 * +0x64 flag. fn_80287D70 initialises it. */
struct Unk80287D70_Ctx {
    char pad0[0xC];
    Unk80270BA0_X* mC;
};

/* Table of 6 records (0x98 bytes) built by the static initializer fn_802AA7A4:
 * up to 25 six-byte entries (three signed offsets, a frame count, two unsigned
 * coordinates scaled by 1/255) and the entry count at +0x96. */
struct Unk80287600_Entry {
    signed char m0;
    signed char m1;
    signed char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};
struct Unk80287600_Rec {
    Unk80287600_Entry e[25];
    unsigned char count;
    char pad97;
};
extern Unk80287600_Rec lbl_806E07E0[];

/* Vec3 plus a time. */
struct Unk80287600_Vec4 : public Unk80273498_Vec3 {
    float w;
};

void fn_80287A9C(Unk80270BA0_X* x, Unk80273498_Vec3* v);
int fn_802871D8(int a);
void fn_802872AC(float* out, int idx, int b, int c, int d, ...);
float fn_804028E4(float x);               /* square root */
Unk80287600_Vec4 fn_80287600(Unk80270BA0_X* x, int a, int b, int c, int d, float* e);

/* State record passed to fn_80386188 (offsets +0xD4 time, +0xD8 valid flag). */
struct Unk80287C70_State {
    char pad0[0xD4];
    float mD4;
    int mD8;
};

float fn_80382BD8(Unk80271DBC_Link* link, int a);
void fn_803814A4(Unk80271DBC_Link* link, int a, float t, int b);
void fn_80381E9C(Unk80271DBC_Link* link, int a, int b, int c);
void fn_80386188(Unk80271DBC_Link* link, Unk80287C70_State* st, int kind, int ev, float* dt,
                 int a, int b, int c, int d, int e, int flags);
extern int lbl_806242B4;
int fn_80380964(Unk80271DBC_Link* link);
float fn_80410CE8(float a, float b);
float fn_80190F0C();
int fn_801D0294(void* p);
int fn_8026D6AC(Unk80270BA0_X* x, int a);
extern const Unk80273498_Vec3 lbl_805DED4C;   /* (7.5, 0, 7.5) */

class Unk80287D70 {
public:
    void fn_80287D70();                      /* initialises the fields */
    Unk80270BA0_X* fn_8027A90C();            /* tu_8027A84C.cpp: m44->mC */
    void fn_80287B2C();
    void fn_80287BB8();
    void fn_80287D50(int v);
    int fn_80287D58(Unk80287D70* o);
    Unk80287D70* fn_80287DB8(int kind);
    void fn_80287E04(int v);
    void fn_80287E0C(int v, const Unk80273498_Vec3* pos);
    int fn_80287B3C(Unk80270BA0_X* x);
    int fn_80287BC4(Unk80270BA0_X* x);
    void fn_8027AFA8(Unk8014D8AC_Ctx* ctx, Unk80270BA0_X* x, int a);   /* tu_8027A84C.cpp */
    void fn_8027A898(const Unk80273498_Vec3& v);   /* tu_8027A84C.cpp: sets m1C and m2C */
    Unk80273498_Vec3 GetM1C() { return m1C; }
    int fn_80287E54(Unk80270BA0_X* x);
    void fn_80287F00(Unk80270BA0_X* x);
    void fn_80288658(Unk80270BA0_X* x);
    unsigned int fn_8028922C(int a, int kind);
    int fn_80289268();
    Unk80273498_Vec3 fn_80289334();
    float fn_80289390();
    int fn_80289808(Unk80287D70* o);
    float fn_80288E88(Unk80270BA0_X* x);
    unsigned int fn_80288F1C(Unk80270BA0_X* x, int kind);
    void fn_80287C70(float t, Unk80270BA0_X* x, Unk80287C70_State* st, int a3, int a4, int a5, int a6);

    int m0;
    char pad4[0x1C - 4];
    Unk80273498_Vec3 m1C;
    char pad28[4];
    int m2C;
    char pad30[8];
    int m38;
    char pad3C[8];
    Unk80287D70_Ctx* m44;
    int m48;
    int m4C;
    int m50;
    Unk80273498_Vec3 m54;
    int m60;
    int m64;
};

extern const Unk80273498_Vec3 lbl_805DED28[];   /* position table indexed by m50 */
extern const Unk80273498_Vec3 lbl_806055AC;   /* 0xC bytes, shared: the zero vector */

#endif /* GAME_GOALS_TU_80287600_H */
