/*
 * Shared declarations for the animation chooser classes (reconstructed).
 *
 * Nothing here comes from original headers: layouts and signatures are
 * inferred from the matched code in animation/choosers/*. Names are
 * placeholders (Unk<addr> = class named after its ctor/first known method,
 * fn_<addr>, m<offset>, fn_vslotN = vtable slot N) until evidence exists.
 * Changing anything here requires re-checking every unit that includes it.
 */
#ifndef GAME_CHOOSER_H
#define GAME_CHOOSER_H

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */

extern int lbl_806EF9B4;          /* default heap passed to new */

void fn_80378E48(char** cursor, int* remaining, char delim, char** token, int* tokenLen);
unsigned int fn_80378568(const char* token, int len);
int fn_80409DAC(const char* token);
double fn_80409D88(const char* token);    /* string to double */
double fn_80410634(double x);             /* rounds down (callers add 0.5 to round) */
int fn_80383334(unsigned int hash);
/* Random number generator (multi-word add-with-carry state at +0x4..+0x18). */
class Unk8014D8AC {
public:
    int fn_8014D8AC(int max, const char* file, int line);
};

/* Three floats (x, y, z) at +0x60 of the player objects (Unk80270BA0_X) and
 * of the position holders below. Evidence: fn_80273498 and fn_80272E28 in
 * animation/choosers/tu_80272B20.cpp read 0x60/0x64/0x68 as a vector. */
struct Unk80273498_Vec3 {
    float x;
    float y;
    float z;
};

/* Position holders reached through Unk8014D8AC_Ctx::m54C (+0xC -> object) and
 * m6CC (object), both read by fn_80273498 (tu_80272B20.cpp). */
struct Unk80270BA0_X;
struct Unk80273498_Pos {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x374 - 0x6C];
    Unk80270BA0_X* m374;
    char pad378[0x38C - 0x378];
    int m38C;
    char pad390[0x3D0 - 0x390];
    Unk80273498_Vec3 m3D0;
};
struct Unk80273498_Ref {
    char pad0[0xC];
    Unk80273498_Pos* mC;
};

/* Object passed to the choosers' pick functions; only +0x54C, +0x554, +0x6CC,
 * +0x6F4 and +0x700 are used here. */
struct Unk8027107C_Outer;
struct Unk8014D8AC_Ctx {
    char pad0[0x54C];
    Unk80273498_Ref* m54C;
    char pad550[4];
    Unk8014D8AC* m554;
    char pad558[0x65C - 0x558];
    Unk80273498_Pos* m65C[13];
    char pad690[0x6CC - 0x690];
    Unk80273498_Pos* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    char pad6F8[0x700 - 0x6F8];
    Unk8027107C_Outer* m700;
};

/* Returned by fn_8037C7FC(); resolves a raw value via fn_8037CE98. */
class Unk8037C7FC {
public:
    int fn_8037CE98(int arg, int value, int flags);
};
Unk8037C7FC* fn_8037C7FC();

/* Base of the helper list classes (ctor 0x80356798). Its vtable 0x8065F9B0
 * has one slot, 0x8035B104; the helper in tu_80272B20.cpp overrides it with
 * its parse function (buf, len), which is why it has these parameters. */
class Unk80356798 {
public:
    Unk80356798();
    virtual void fn_vslot1(char* buf, int len);
};

/* Result record filled by the choosers' vtable slot 17. */
struct Unk80270BA0_Result {
    unsigned int type : 4;
    unsigned int pad0 : 28;
    int id;
    int m8;                    /* second id when type == 2 (0x802721E0) */
    char padC[0x14 - 0xC];
    float m14;
    float m18;                 /* second weight when type == 2 (0x802721E0) */
};

struct Unk80270BA0_X;

/* Reached through Unk8014D8AC_Ctx::m700 (two levels down). */
struct Unk8027107C_Inner {
    char pad0[0x128];
    int m128;
};
struct Unk8027107C_Outer {
    char pad0[0x3A4];
    Unk8027107C_Inner* m3A4;
    char pad3A8[0x3B0 - 0x3A8];
    int m3B0;
    char pad3B4[8];
    int m3BC;
};

int fn_8024D9A0(Unk80270BA0_X* x, int* out);

/* 4x4 float matrix with the fourth column unused: rows 0..2 are the axes and
 * row 3 (+0x30) the position (fn_8037B128 reads +0x30..+0x38). Size 0x40.
 * fn_8027AAB0 (animation/goals/tu_8027A84C.cpp) copies one from player+0x20. */
struct Unk8037B128_Mtx {
    float r[4][4];
};

/* Base part of Unk80270BA0_X that precedes its vtable pointer (at +0x98). */
struct Unk80270BA0_XBase {
    int m0;                    /* set to 1 after fn_8037D768 (fn_8027AAB0) */
    char pad4[0x20 - 0x4];
    Unk8037B128_Mtx m20;
    Unk80273498_Vec3 m60;      /* position */
    char pad6C[0x98 - 0x6C];
};

/* g++ 2.95 places the vtable pointer after the data of the class that
 * introduces virtuals, so the vptr at +0x98 means a data-less class adds the
 * virtuals on top of a 0x98-byte base. */
class Unk80270BA0_XVirt : public Unk80270BA0_XBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual int fn_vslot4();
};

/* Data of the player object between its vptr and its second base. */
class Unk80270BA0_XMid : public Unk80270BA0_XVirt {
public:
    char pad9C[0x44C - 0x9C];
    Unk8014D8AC_Ctx* m44C;
    int m450;
    char pad454[4];
    int m458;
    char pad45C[0x488 - 0x45C];
    int m488;
    char pad48C[0x588 - 0x48C];
    char m588[0x5F0 - 0x588];
};

/* Second argument of vtable slot 17; only its first virtual is used here. */
class Unk80270BA0_Obj {
public:
    virtual Unk80270BA0_X* fn_vslot1();
};

/* Sub-object at Unk80270BA0_X+0x734: float pairs indexed by m190 (0 or 1).
 * cCircleChooser's slot 17 (0x802726BC) reads m40, mE0, mE8, m100, m108,
 * m140 and m190. */
struct Unk802726BC_Angles {
    char pad0[0x40];
    float m40[2];
    char pad48[0xE0 - 0x48];
    float mE0[2];
    float mE8[2];
    char padF0[0x100 - 0xF0];
    float m100[2];
    float m108[2];
    char pad110[0x140 - 0x110];
    float m140[2];
    char pad148[0x190 - 0x148];
    int m190;
};

/* Object returned by Unk80270BA0_Obj::fn_vslot1() (a player?).
 * Multiple inheritance: converting it to Unk80270BA0_Obj* adds 0x5F0 with a
 * null check (cEventChooser's slot 17 passes it to the base that way). */
struct Unk80271DBC_Link {
    char pad0[0x830];
    int m830;
    char pad834[4];
    int m838;
    int m83C;
    char pad840[0x880 - 0x840];
    Unk8014D8AC_Ctx* m880;
};

class Unk80270BA0_X : public Unk80270BA0_XMid, public Unk80270BA0_Obj {
public:
    char pad5F4[0x618 - 0x5F4];
    Unk80271DBC_Link* m618;
    char pad61C[0x708 - 0x61C];
    int m708;
    char pad70C[0x71C - 0x70C];
    int m71C;                  /* flags; 0x800 tested by 0x802721E0 */
    char pad720[0x734 - 0x720];
    Unk802726BC_Angles m734;
    char pad8C8[0x8E8 - 0x8C8];
    float m8E8;
    char pad8EC[0x908 - 0x8EC];
    Unk80273498_Pos* m908;
    char pad90C[0xB3C - 0x90C];
    int mB3C;
    char padB40[0xB4C - 0xB40];
    int mB4C;
    int mB50;
};

int fn_8025416C(void* p, int n);
int fn_8024DCFC(int a);
int fn_8024D4C0(Unk80270BA0_X* x);
int fn_8022E998(int a);
float fn_8026D504(Unk80270BA0_X* x, int a);

/* Container embedded in event/hand/pitch choosers at +8 (ctor 0x80384F28,
 * dtor 0x8038501C). Size 0x10. */
class Unk80384F28 {
public:
    Unk80384F28();
    ~Unk80384F28();
    void fn_80385344(const char* name);
    int fn_803851A0(int a, int b);
    void fn_803852FC(int a);
    char pad0[0x10];
};

extern const char lbl_805DC0E4[];   /* 0x14-byte string in another unit's .rodata */
extern const char lbl_805DC0F8[];   /* "cSubContainer" (same unit) */
extern const char lbl_805DC394[];   /* "type": one copy, used by several units' slot 2 */

/* Weights-list helper embedded in cRandomLoaded at +4 (ctor 0x8026FEB8, dtor
 * 0x8026FF08, vtable 0x806625D0: slot 1 parse 0x8027021C, slot 2 dtor). It
 * lives in randomchooser.cpp, which is not decompiled yet. Size 0x14.
 * Offsets seen: +4 entry count (fn_8026FF6C and fn_80270074 bound-check it),
 * +8 array of 16-byte entries (object pointer at +4, float at +8),
 * +0xC index used by fn_80270074 when the player flag 0x800 is set, +0x10
 * (zeroed by the ctor, untouched here). */
class Unk8026FEB8 : public Unk80356798 {
public:
    Unk8026FEB8();
    virtual ~Unk8026FEB8();
    void* fn_8026FF6C(int index);
    int fn_80270074(Unk80270BA0_X* x, int index, int* outId, float* outWeight);

    int m4;
    int m8;
    int mC;
    int m10;
};

/* Object behind lbl_8061E978; fn_802AE984(mgr, p) forwards to fn_80378024(mgr + 0x3B78, p). */
struct Unk802AE984_Mgr;
int fn_802AE984(Unk802AE984_Mgr* mgr, void* p);

/* Base of the choosers (ctor 0x8037B3E8, dtor 0x80362C2C). */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);       /* 0x8037B3E8 */
    Unk8037B3E8(const char* name);        /* 0x8037B3AC */
    virtual ~Unk8037B3E8();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual void fn_vslot15();
    virtual void fn_vslot16(int a);
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
    void fn_8037B6B0(const char* name, int* field, const char* values);
    void fn_8037B728(const char* name, const char* name2, void* list, int flags);
};

#endif /* GAME_CHOOSER_H */
