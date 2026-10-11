/*
 * Types for animation/goals/tu_8027FD64.cpp (reconstructed, placeholder names).
 * Layouts come from the offsets that unit reads and writes; nothing here is
 * from original headers. Fields not listed are unknown.
 */
#ifndef GAME_GOALS_TU_8027FD64_H
#define GAME_GOALS_TU_8027FD64_H

#include "game/chooser.h"

extern "C" float fabsf(float x);          /* inlined as fabs */

/* Current facing angle of a player (its angle table indexed by m190). */
inline float Unk8027FD64_GetAngle(Unk802726BC_Angles* a)
{
    /* Byte offset in a local: `a->m40[a->m190]` folds the +0x40 into the
     * displacement, the original keeps it in the index register. */
    int off = a->m190 * 4 + 0x40;
    return *(float*)((char*)a + off);
}

/* Inline wrapper: its float parameter gets a stack slot of its own, which is how
 * fn_80282CC0 differs from the direct fabsf calls elsewhere. */
inline float Unk8027FD64_Abs(float v)
{
    return fabsf(v);
}

float fn_804028E4(float x);               /* square root */
float fn_80410ABC(float x);

inline float Length(Unk80273498_Vec3 v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* Path of the source file this unit's assert/RNG calls name (catchgoal.cpp). */
#define UNK8027FD64_CATCHGOAL_FILE "C:/mvp2004/source/common/animation/goals/catchgoal.cpp"

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

/* The goal object's flag word at +0xE8. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N). Evidence that it is a bitfield:
 * fn_80282B78 stores comparison results with rlwimi, and fn_80282E5C tests two
 * bits with separate andis. instructions. */
struct Unk8027FD64_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Same object as Unk8014D8AC_Ctx (reached through Unk80270BA0_X::m44C) with the
 * fields this unit reads; callers cast. Evidence: fn_80282B78 (+0x6CC, whose
 * target has an int at +0x38C) and fn_80280F08 (+0x680 position holder,
 * +0x6F8 -> +0x14 -> byte at +0x1CC9, +0x700 -> +0x3B4 -> fn_80257B40). */
struct Unk8027FD64_Pos6CC {
    char pad0[0x38C];
    int m38C;
};
struct Unk8027FD64_Ref6F8 {
    char pad0[0x14];
    struct Unk8027FD64_Ref14* m14;
};
struct Unk8027FD64_Ref14 {
    char pad0[0x1CC9];
    unsigned char m1CC9;
};
struct Unk8027FD64_Outer700 {
    char pad0[0x3B4];
    void* m3B4;
};
/* Position holder at Unk8027FD64_Ctx::m680 (vector at +0x60, returned by value). */
struct Unk8027FD64_Holder680 {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    Unk80273498_Vec3 fn_GetPos() { return m60; }
};
struct Unk8027FD64_Ctx {
    char pad0[0x680];
    Unk8027FD64_Holder680* m680;
    char pad684[0x6CC - 0x684];
    Unk8027FD64_Pos6CC* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Unk8027FD64_Ref6F8* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk8027FD64_Outer700* m700;
};

/* Object returned by fn_80257B40; only the int at +0x458 is read. */
struct Unk80257B40_Obj {
    char pad0[0x458];
    int m458;
};
Unk80257B40_Obj* fn_80257B40(void* p);

/* Sets entry i of the int table at +0x168 of the angle block (fn_80280F08):
 * an inline function, since its constant index stays in an index register. */
inline void Unk8027FD64_SetSlot168(Unk802726BC_Angles* a, int i, int v)
{
    int off = i * 4 + 0x168;
    *(int*)((char*)a + off) = v;
}

/* Object returned by fn_8027B304: only the float at +0x3F4 is read
 * (fn_80282E5C). */
struct Unk8027B304_Obj {
    float fn_8018CDB8(float v, int n);
    char pad0[0x3F4];
    float m3F4;
};

/* Goal object (first argument of most functions here). Evidence: the offsets
 * used by fn_8027FD64, fn_80280F08, fn_80282B78, fn_80282C58, fn_80282CC0 and
 * fn_80282E5C. */
struct Unk8027FD64_Goal {
    char pad0[0x4];
    void* m4;
    char pad8[0x1C - 0x8];
    Unk80273498_Vec3 m1C;
    char pad28[0x2C - 0x28];
    int m2C;
    char pad30[0x74 - 0x30];
    int m74;
    int m78;
    char pad7C[0x80 - 0x7C];
    float m80;
    char pad84[0x8C - 0x84];
    float m8C;
    float m90;
    int m94;
    char pad98[0xA0 - 0x98];
    int mA0;
    char padA4[0xE8 - 0xA4];
    Unk8027FD64_Flags mE8;

    /* Inline accessors: testing two bits with `||` directly folds them into one
     * mask test, the original keeps two separate tests (fn_80282E5C). */
    int fn_IsF12() { return mE8.f12; }
    int fn_IsF11() { return mE8.f11; }
    /* fn_80282B78 tests f14 through this: a direct read lets combine test the
     * word before the f4/f5 clears; retail tests the cleared word. */
    int fn_IsF14() { return mE8.f14; }

    /* Vector at +0x1C returned by value (fn_80282CC0 copies it twice). */
    Unk80273498_Vec3 fn_GetVec() { return m1C; }
    Unk80273498_Vec3 fn_80286E70();
};

/* Query record built on the stack by fn_80280230 and filled in by fn_80386110.
 * Size 0xC0; only the fields its constructor clears are known (+0x44 nibble,
 * +0x68 vector, +0xA0, +0xBC). */
/* Vector member of the query record, cleared with integer stores. */
struct Unk80386110_Zero3 {
    int x;
    int y;
    int z;
    Unk80386110_Zero3()
    {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Unk80386110_Query {
    char pad0[0x44];
    unsigned int mType : 4;
    unsigned int mTypePad : 28;
    char pad48[0x68 - 0x48];
    Unk80386110_Zero3 m68;
    char pad74[0xA0 - 0x74];
    int mA0;
    char padA4[0xBC - 0xA4];
    int mBC;
    char padC0[0xC0 - 0xC0];

    Unk80386110_Query() : mType(0), mA0(0), mBC(0)
    {
    }
};

/* Anim record of a player (Unk80270BA0_X::m618): only +0x838 is read here. */
struct Unk80280230_Anim {
    char pad0[0x838];
    int m838;
};

int fn_8027FC20(Unk8027FD64_Goal* g, int a);
void fn_80386110(Unk80280230_Anim* a, Unk80386110_Query* q, unsigned int hash, int v, float* out, int flag);
extern int lbl_806242B4;

Unk8027B304_Obj* fn_8027B304(Unk8027FD64_Goal* g);
int fn_8024D41C(Unk80270BA0_X* x);
int fn_80296998(void* p, int a, int b);

/* Request/parameter object filled by fn_802833E8. Evidence: the fields that
 * function writes (+0x40, +0xA0, +0xBC, +0xD0) and the member calls on it. */
struct Unk802833E8_Req {
    void fn_80279DD0(int a);
    void fn_80279F40(int a);
    void fn_8037B10C(Unk80273498_Vec3 v);
    void fn_8037B16C(float f);
    char pad0[0x40];
    float m40;
    char pad44[0xA0 - 0x44];
    int mA0;
    char padA4[0xBC - 0xA4];
    unsigned int mBC;
    char padC0[0xD0 - 0xC0];
    float mD0;

    /* Inline setters: a float parameter of an inline function gets its own
     * stack slot (stored then reloaded), as in fn_802833E8. */
    void fn_SetScale(float f) { fn_8037B16C(f); }
    void fn_SetD0(float f) { mD0 = f; }
};

#endif /* GAME_GOALS_TU_8027FD64_H */
