/*
 * Shared types for game code 0x8024EF40-0x80268190 (units game/tu_8024EF40 ..
 * game/tu_80264378; reconstructed, placeholder names, everything is named by
 * offset). Nothing here comes from original headers.
 *
 * Evidence (functions of tu_802547C0 unless noted):
 *  - Unk8024EF40_A is a controller embedded in the player at +0x58C
 *    (fn_80254B60 does `A - 0x58C` to get the player back; fn_802548F0 and
 *    fn_80255284 take `&p->m58C`). m0 is the owner, m4 a bit-field word
 *    (bit 0 / bit 2 tested and rlwimi'd in fn_80254DA4 / fn_802547C0).
 *  - Unk8024EF40_P is the player (m44C, m458, m58C, m708, m70C, m730 seen).
 *  - Q = player->m44C (m4C tick count read as unsigned, m6CC, m6F8, m700,
 *    queue at +0x704); Ctx = Q->m700 (m3B4 list, m3BC state).
 */
#ifndef GAME_TU_8024EF40_H
#define GAME_TU_8024EF40_H

struct Unk8024EF40_A;
struct Unk8024EF40_P;

struct Unk8024EF40_Obj618 {
    char pad0[0x838];
    int m838;
};

void* operator new(unsigned int size, int heap); /* 0x80377428 */
void* operator new[](unsigned int size, int heap); /* 0x803774A8 */

/* Object at P+0x588: only the back pointer is read (fn_80253DB0 family). */
struct Unk8024EF40_W {
    Unk8024EF40_P* m0;
};

extern char lbl_80649DA0[];
extern char lbl_80660EC0[];

struct Unk8024EF40_Pos {
    char pad0[0x70C];
    unsigned char m70C;
};

/* 0xE64-byte per-player record, array behind Q->m6F8->m14 indexed by P->m708
   (fn_80253DB0 .. fn_80254618: `mulli r0,r0,0xe64`). Sub-objects at +0x118, +0xC74, +0xC9C. */
struct Unk8024EF40_Ent {
    char pad0[0xE64];
};

struct Unk8024EF40_T10 {
    char pad0[0x14];
    int m14[3];
};

struct Unk8024EF40_Sub6F8 {
    char pad0[0x10];
    Unk8024EF40_T10* m10;
    Unk8024EF40_Ent* m14;
};

struct Unk8024EF40_Ctx {
    char pad0[0x3B4];
    void* m3B4;
    int m3B8;
    int m3BC;
};

struct Unk8024EF40_Q {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x554 - 0x50];
    int m554;
    char pad558[0x65C - 0x558];
    Unk8024EF40_P* m65C[13]; /* roster by position; 9..12 are the on-field slots */
    char pad690[0x6CC - 0x690];
    Unk8024EF40_P* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    Unk8024EF40_Sub6F8* m6F8;
    char pad6FC[4];
    Unk8024EF40_Ctx* m700;
    char m704[4];
};

struct Unk8024EF40_A {
    Unk8024EF40_P* m0;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 29;
    float m8;
    float mC;
    int m10;
    float m14;
    float m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    float m48;
    char pad4C[4];
    struct Unk8024EF40_Ref* m50;
};

struct Unk8024EF40_Ref {
    float m0;
    float m4;
};

struct Unk8024EF40_P {
    char pad0[0x60];
    float m60;
    char pad64[4];
    float m68;
    char pad6C[0x264 - 0x6C];
    int m264;
    char pad268[0x36C - 0x268];
    int m36C;
    char pad370[0x44C - 0x370];
    Unk8024EF40_Q* m44C;
    char pad450[8];
    int m458;
    char pad45C[0x588 - 0x45C];
    Unk8024EF40_W m588;
    Unk8024EF40_A m58C;
    char pad5E0[0x618 - 0x5E0];
    struct Unk8024EF40_Obj618* m618;
    char pad61C[0x704 - 0x61C];
    int m704;
    int m708;
    unsigned char m70C;
    char pad70D[0x730 - 0x70D];
    int m730;
};

/* Tick count of the owner in 1/60 s units; an inline in retail (a plain expression
   gives a different constant/load schedule: fn_802554BC). */
inline float Secs(Unk8024EF40_Q* q)
{
    return (float)q->m4C * 0.016666668f;
}

inline Unk8024EF40_Ent* EntOf(Unk8024EF40_P* p)
{
    return p->m44C->m6F8->m14 + p->m708;
}

/* Random percentage roll used by the injury checks (fn_80252460 family); the file
   string and line are parameters of the inline (a hard-coded string changes the argument
   setup order). */
unsigned fn_8014D8AC(int seed, int max, const char* file, int line);
inline float RandPct(Unk8024EF40_P* x, const char* f, int line)
{
    float k = 100.0f;
    return (float)fn_8014D8AC(x->m44C->m554, 1000000, f, line) * k * 0.000001f;
}

/* Object with its vptr at +0x98 (the data before it belongs to a non-polymorphic base);
   virtual N is the call through `lha r,8N(vptr); lwz r,8N+4(vptr)` (fn_80256A90 family). */
struct Unk80256A90_Data {
    char pad0[0x98];
};
struct Unk80256A90_V : Unk80256A90_Data {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
};


/* Roster/manager object (units 80256C80 .. 8025877C): m4 points to the 0x548-byte inner
   object built by fn_8025CDFC; its m1EC is the Q (fn_802570D4). */
struct Unk80256C80_Inner;
struct Unk80256C80_M {
    const void* m0;
    Unk80256C80_Inner* m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};
struct Unk80256C80_Inner {
    char pad0[0x128];
    int m128;
    char pad12C[0x194 - 0x12C];
    int m194;
    char pad198[0x1EC - 0x198];
    Unk8024EF40_Q* m1EC;
    char pad1F0[0x1FC - 0x1F0];
    int m1FC;
    char pad200[0x434 - 0x200];
    Unk8024EF40_P* m434;
    Unk8024EF40_P* m438[4];
    int m448;
    char pad44C[0x464 - 0x44C];
    int m464;
    char pad468[0x4C4 - 0x468];
    int m4C4[4];
    char pad4D4[0x544 - 0x4D4];
    virtual ~Unk80256C80_Inner();
};

/* Float setter inline: the parameter spills to its own 8-byte frame slot (fn_80256CB4). */
inline void SetF(float* p, float v)
{
    *p = v;
}

/* Table read through an inline taking the table pointer: the index load lands in r11 as in retail
   (the plain `m10->m14[i]` expression puts it in r0): fn_802536D0. */
inline int Pick(Unk8024EF40_T10* t, int i)
{
    return t->m14[i];
}

#endif /* GAME_TU_8024EF40_H */
