#ifndef GAME_TU_803606B0_H
#define GAME_TU_803606B0_H

#include "game/tu_8034B370.h"

/*
 * Shared types for the game tail 0x803606B0..0x803663B0 (range 30).
 */

/* Float variant of the ring container of tu_8034B370.h (fn_803624D0 ..
 * fn_803626B8): m0 is the element buffer, m4 the count, mC the cursor; the
 * polymorphic variant has its vptr at +0x10 (virtual 3 returns the current
 * element). Evidence: the float getters fn_803624D0 / fn_803624E4 /
 * fn_8036250C mirror the int ones fn_80362114 / fn_80362128 / fn_80362150. */
struct Unk803624D0 {
    float* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    inline void Clear()
    {
        fn_8040074C(m0, m8 << 2);
        m4 = 0;
        mC = 0;
    }
    inline void Add(float v)
    {
        if (m4 < m8) {
            m0[m4] = v;
            m4++;
        }
    }
};
struct Unk803624D0V : Unk803624D0 {
    virtual void v1();
    virtual void v2();
    virtual float v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

/* Game-flow task wrappers (tu_80360C18): a task holds its owner at +0 and its
 * vptr (lbl_80667118) at +4. The owner is a class whose vptr sits at +0x18
 * (virtual 5 steps the owner), with a state word at +0x74 and a mode word at
 * +0x80. Evidence: fn_80361034 .. fn_80361494 loop `while (owner->m74 == 2)`
 * around fn_800A2F9C(owner, 1) after calling virtual 5. */
struct Unk80361034_Pad18 {
    char pad[0x18];
};
struct Unk80361034_OwnV : Unk80361034_Pad18 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Unk80361034_Own : Unk80361034_OwnV {
    char pad1C[0x74 - 0x1C];
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
};
struct Unk80361034 {
    Unk80361034_Own* m0;
    const void* m4;
};
extern "C" int fn_800A29C4(Unk80361034_Own* o, int a);
extern "C" int fn_800A2948(Unk80361034_Own* o);
extern "C" int fn_800A2F9C(Unk80361034_Own* o, int a);
extern "C" int fn_800A3270(Unk80361034_Own* o, int* a, int* b);
extern "C" void fn_8055EAFC(int a);
extern "C" int fn_800A1A6C(Unk80361034_Own* o);
extern "C" int fn_800A2EFC(Unk80361034_Own* o);
extern "C" int fn_800A1B20(Unk80361034_Own* o);
extern "C" int fn_800A2E90(Unk80361034_Own* o);
extern "C" int fn_800A3430(Unk80361034_Own* o);

/* Screen-class task wrappers (tu_80361580): a task holds its owner object at
 * +0, the owner's first word is the Unk8007B2B0_Screen it drives (methods are
 * declared in tu_8007A4DC.h; only the ones these wrappers call are repeated
 * here, which gives the same mangled names). Evidence: fn_80361A80 /
 * fn_80361B34 compare the slot id of the owner's headers (+0xC, +0x1C ->
 * +0x198) with the task's mC; fn_80361DF0 / E84 / F18 are
 * m0->m0->fn_8007D0E0(m0->m28, K, 1). */
struct Unk8007B2B0_Screen {
    int fn_8007D0E0(unsigned i, int a, int b);
    int fn_8007D180(unsigned i, int a);
    int fn_8007D998(unsigned i, int a);
    int fn_80078A38(int a);
};
struct Unk80361A80_R {
    char pad[0x24];
    int m24;
};
struct Unk80361A80_Q {
    char pad[0xC];
    Unk80361A80_R* mC;
};
struct Unk80361A80_H {
    char pad[0x198];
    int m198;
};
struct Unk80361A80_Obj {
    Unk8007B2B0_Screen* m0;
    Unk80361A80_Q* m4;
    Unk80361A80_H* m8;
    Unk80361A80_H* mC;
    int m10;
    char pad14[0x1C - 0x14];
    Unk80361A80_H* m1C;
    char pad20[0x28 - 0x20];
    unsigned m28;
};
struct Unk80361A80 {
    Unk80361A80_Obj* m0;
    int m4;
    int m8;
    int mC;
};

struct Unk80361C58_T {
    short delta;
    short pad;
    int (*pfn)(void*, int);
};
/* Member-function-pointer style call record: fn_80361C58 / fn_80361CB4 call
 * pfn(owner->mC + delta, mC) to count the entries to process. */
struct Unk80361C58 {
    Unk80361A80_Obj* m0;
    int m4;
    int m8;
    unsigned char mC;
    char padD[3];
    Unk80361C58_T m10;
};
struct Unk803619AC_G {
    char pad[0x64];
    int m64;
};

/* Out-of-line dtor of tu_803606B0 (vptr at +0x14), used as a member dtor. */
struct DtorAt14;
void fn_80360AF0(DtorAt14* self, int chrg);

/* Float block cleared by fn_803628A0 (tu_80361F98); fn_80361600 constructs one. */
struct Unk803628A0 {
    int m0;
    float m4, m8, mC, m10, m14;
};
void fn_803628A0(Unk803628A0* s);

/* Member of the big task container of fn_80361834: out-of-line dtor
 * (fn_80362930) that resets the vptr at +0x1C to lbl_8064A550. */
struct Unk80362930 {
    char pad[0x1c];
    const void* m1C;
    ~Unk80362930();
};

/* Serialization stream of the ring containers (fn_803622F0 / fn_803626B8):
 * m0 is nonzero while writing a snapshot, virtual 1 copies n bytes between
 * the buffer behind *cur and a value, virtual 2 answers whether the stream is
 * in "save" mode. Evidence: both ring serializers branch on v2() == 1 and write
 * m4 / mC / the elements, or read them back (m0 == 0). */
struct Unk803622F0_Data {
    int m0;
};
struct Unk803622F0 : Unk803622F0_Data {
    virtual void v1(char** cur, void* buf, int n);
    virtual int v2();
};

#endif
