#ifndef GAME_TU_8019F8C0_H
#define GAME_TU_8019F8C0_H

/*
 * Declarations for game/tu_8019F8C0.cpp (reconstructed; placeholders only).
 *
 * State classes of a state machine (one per game mode step): each has a
 * constructor (State ctor 0x803785E4 first, then fields 0xC..0x18, vptr at +8)
 * and virtual slots 4 (enter), 5 (update) and 6 (exit). Evidence: vtables
 * 0x8065F208..0x8065F3C8 (0x40 bytes each, slot 1 = shared dtor 0x8035A4C4,
 * slots 2/3 = 0x803443D0/0x803443CC).
 */

/* Root with two ints cleared to -1 by 0x80378734; vptr after them at +8. */
class Unk803785E4 {
public:
    Unk803785E4();
    int m0;
    int m4;
    virtual ~Unk803785E4();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};


struct Unk8019F8C0_Owner;   /* state machine owner, m18 of every state */
class Unk8019F8C0_Obj;

/* Mid class: fields 0xC..0x18 set by every state's constructor. */
class Unk8019F8C0_State : public Unk803785E4 {
public:
    Unk8019F8C0_State(Unk8019F8C0_Owner* owner, int id) : mC(0), m10(0), m14(id), m18(owner) {}
    int mC;
    int m10;
    int m14;
    Unk8019F8C0_Owner* m18;
};

struct Unk8019F8C0_Ctl {   /* mC.. block of a control (flag words at +0xC, +0x10, +0x3C) */
    int m0;
    int m4;
    char pad8[0x30 - 0x8];
    int m30;
};

struct Unk8019F8C0_Ctrl {
    char pad0[0xC];
    Unk8019F8C0_Ctl mC;
};

/* m700 of the owner: a player object with control pointers at 0x3B0.. */
struct Unk8019F8C0_Pl {
    char pad0[0x3B0];
    Unk8019F8C0_Ctrl* m3B0;
    void* m3B4;
    int m3B8;
    void* m3BC;
};

struct Unk8019F8C0_Ref {   /* fn_801A6D84 result */
    char pad0[0x3D90];
    int m3D90;
};

struct Unk8019F8C0_Glob {   /* *lbl_8061B8C0 */
    char pad0[0x20];
    int m20;
    char pad24[0x2C - 0x24];
    int m2C;
};

struct Unk8019F8C0_Inner {
    char pad0[0x1CD0];
    int m1CD0;
};

struct Unk8019F8C0_Mgr {
    char pad0[0x14];
    Unk8019F8C0_Inner* m14;
};

/* Object with a vptr at +0x98 (data-only base, then the virtuals class). */
class Unk8019F8C0_VBase {
public:
    char pad0[0x98];
};
class Unk8019F8C0_V : public Unk8019F8C0_VBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4(void* out);
};

/* Sub-object of the owner at index 0..5 of its table at +0x30 (fn_801A04A8). */
struct Unk8019F8C0_Sub {
    char pad0[4];
    int m4;
    char pad8[4];
    Unk8019F8C0_V* mC;
    char pad10[0x38 - 0x10];
    int m38;
    char pad3C[0x44 - 0x3C];
    int m44;
    int m48;
    float m4C;
    float m50;
    void SetM4C(float v) { m4C = v; }
    void SetM50(float v) { m50 = v; }
};

/* State owner / game flow object (m18 of every state). Evidence: fn_8019F8C0..
 * fn_801A2264 accessors at 0x30 (table), 0x48, 0x4C, 0x50 (inline), 0x548..0x55C,
 * 0x58C, 0x618, 0x65C, 0x680, 0x6C4..0x6DC, 0x6F8, 0x700, 0x704 (inline), 0x710. */
struct Unk8019F8C0_Owner {
/*BEGIN Unk8019F8C0_Owner*/
    char pad0[0x30];
    Unk8019F8C0_Sub* m30[6];
    int m48;
    int m4C;
    char pad50[0x4F8];
    int m548;
    int m54C;
    int m550;
    char pad554[0x8];
    int m55C;
    char pad560[0x28];
    void* m588;
    int m58C[2];
    char pad594[0x84];
    void* m618[3];
    char pad624[0x38];
    int m65C[13];
    char pad690[0x34];
    int* m6C4;
    char pad6C8[0x4];
    int m6CC;
    int m6D0;
    int m6D4;
    char pad6D8[0x4];
    int m6DC;
    char pad6E0[0x18];
    Unk8019F8C0_Mgr* m6F8;
    int m6FC;
    Unk8019F8C0_Pl* m700;
    char m704[4];
    char pad708[0x8];
    void* m710;
    char pad714[0x6C];
    int m780;
    int m784;
    int m788;
    int m78C;
    int m790;
    int m794;
/*END Unk8019F8C0_Owner*/
};

/* State 4 */
class Unk8019F930 : public Unk8019F8C0_State {
public:
    Unk8019F930(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 5 */
class Unk8019FA50 : public Unk8019F8C0_State {
public:
    Unk8019FA50(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 6 */
class Unk8019FAF8 : public Unk8019F8C0_State {
public:
    Unk8019FAF8(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 7 */
class Unk8019FBB4 : public Unk8019F8C0_State {
public:
    Unk8019FBB4(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 8 */
class Unk8019FD50 : public Unk8019F8C0_State {
public:
    Unk8019FD50(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 9 */
class Unk8019FE5C : public Unk8019F8C0_State {
public:
    Unk8019FE5C(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 3: constructor lives in the previous unit; slots 5 and 6 are here. */
class Unk8019F8C0_S3 : public Unk8019F8C0_State {
public:
    Unk8019F8C0_S3(Unk8019F8C0_Owner* o);
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

/* State 0xB keeps a second owner pointer at +0x1C. */
class Unk8019FFB0 : public Unk8019F8C0_State {
public:
    Unk8019FFB0(Unk8019F8C0_Owner* o);
    Unk8019F8C0_Owner* m1C;
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
};

#endif
