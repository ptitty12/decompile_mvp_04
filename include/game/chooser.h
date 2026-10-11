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
int fn_80383334(unsigned int hash);
/* Random number generator (multi-word add-with-carry state at +0x4..+0x18). */
class Unk8014D8AC {
public:
    int fn_8014D8AC(int max, const char* file, int line);
};

/* Object passed to the choosers' pick functions; only +0x554 is used here. */
struct Unk8027107C_Outer;
struct Unk8014D8AC_Ctx {
    char pad0[0x554];
    Unk8014D8AC* m554;
    char pad558[0x6F4 - 0x558];
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

/* Base of the helper list classes (ctor 0x80356798). */
class Unk80356798 {
public:
    Unk80356798();
    virtual void fn_vslot1();
};

/* Result record filled by the choosers' vtable slot 17. */
struct Unk80270BA0_Result {
    unsigned int type : 4;
    unsigned int pad0 : 28;
    int id;
    char pad8[0xC];
    float m14;
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
};

int fn_8024D9A0(Unk80270BA0_X* x, int* out);

/* Base part of Unk80270BA0_X that precedes its vtable pointer (at +0x98). */
struct Unk80270BA0_XBase {
    char pad0[0x98];
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
    char pad450[0x488 - 0x450];
    int m488;
    char pad48C[0x588 - 0x48C];
    char m588[0x5F0 - 0x588];
};

/* Second argument of vtable slot 17; only its first virtual is used here. */
class Unk80270BA0_Obj {
public:
    virtual Unk80270BA0_X* fn_vslot1();
};

/* Object returned by Unk80270BA0_Obj::fn_vslot1() (a player?).
 * Multiple inheritance: converting it to Unk80270BA0_Obj* adds 0x5F0 with a
 * null check (cEventChooser's slot 17 passes it to the base that way). */
struct Unk80271DBC_Link {
    char pad0[0x880];
    Unk8014D8AC_Ctx* m880;
};

class Unk80270BA0_X : public Unk80270BA0_XMid, public Unk80270BA0_Obj {
public:
    char pad5F4[0x618 - 0x5F4];
    Unk80271DBC_Link* m618;
    char pad61C[0x708 - 0x61C];
    int m708;
    char pad70C[0xB4C - 0x70C];
    int mB4C;
    int mB50;
};

int fn_8025416C(void* p, int n);
int fn_8024DCFC(int a);
int fn_8024D4C0(Unk80270BA0_X* x);
int fn_8022E998(int a);

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
