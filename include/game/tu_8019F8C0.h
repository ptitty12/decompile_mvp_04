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
    char pad0[0x3A4];
    void* m3A4;
    char pad3A8[4];
    struct Unk80178BBC_T* m3AC;
    Unk8019F8C0_Ctrl* m3B0;
    void* m3B4;
    int m3B8;
    void* m3BC;
    void* m3C0;
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

/* Ring cursor at +0x168 of a team element: byte table, count, cursor at +0xC. */
struct Unk8019F8C0_Ring {
    unsigned char* m0;
    unsigned m4;
    int m8;
    unsigned mC;
};

/* Element of the array at m14 of the manager (stride 0xE64); element 2 also
 * holds the flags read at 0x1CC9 / 0x1CD0 (evidence: fn_801A2034, fn_801A48F8). */
struct Unk8019F8C0_Inner {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    char pad4[4];
    int m8;
    char padC[0x78 - 0xC];
    int m78;
    char pad7C[0x108 - 0x7C];
    int m108;
    char pad10C[0x164 - 0x10C];
    int m164;
    Unk8019F8C0_Ring m168;
    char pad178[0x17C - 0x178];
    unsigned char m17C[0x198 - 0x17C];
    int m198;
    char pad19C[4];
    int m1A0;
    char pad1A4[0x1B4 - 0x1A4];
    unsigned char m1B4[0x3E4 - 0x1B4];
    unsigned char m3E4;
    char pad3E5[0xE64 - 0x3E5];
    int GetM1() { return m1; }
    int GetM2() { return m2; }
    int GetM3() { return m3; }
};

struct Unk8019F8C0_Obj4A4 {
    char pad0[0x3F4];
    float m3F4;
    char pad3F8[0x4A4 - 0x3F8];
    unsigned m4A4;
};

struct Unk8019F8C0_Ent {
    int m0;
    Unk8019F8C0_Obj4A4* m4;
};

struct Unk8019F8C0_Dev {
    char padcc[0xCC];
    int mCC;
};

struct Unk8019F8C0_Mgr10 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x6C - 0x20];
    int m6C;
    int m70;
    char pad74[0x22C - 0x74];
    int m22C;
};

struct Unk8019F8C0_Mgr {
    char pad0[0xC];
    int mC;
    Unk8019F8C0_Mgr10* m10;
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

/* The owner object seen as a class with a vptr at +0x18 (data-only base, then the virtuals). */
class Unk8019F8C0_OVBase {
public:
    char pad0[0x18];
};
class Unk8019F8C0_OV : public Unk8019F8C0_OVBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24(int a);
};

/* State-machine style object with a vptr at +8 (fn_801A4CE8 result, Sub::m3C). */
class Unk8019F8C0_MBase {
public:
    char pad0[8];
};
class Unk8019F8C0_M : public Unk8019F8C0_MBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual int fn_vslot9();
};

class Unk8019F8C0_M2 : public Unk8019F8C0_M {
public:
    int mC;
};

/* Same layout, fourth virtual takes no argument (fn_801A3860). */
class Unk8019F8C0_W : public Unk8019F8C0_VBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual int fn_vslot4();
};

/* Sub-object of the owner at index 0..5 of its table at +0x30 (fn_801A04A8). */
struct Unk8019F8C0_Sub {
    char pad0[4];
    int m4;
    char pad8[4];
    Unk8019F8C0_V* mC;
    char pad10[0x38 - 0x10];
    int m38;
    Unk8019F8C0_M2* m3C;
    Unk8019F8C0_Ref* m40;
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
    char pad0[0x24];
    char m24[4];
    char pad28[0x8];
    Unk8019F8C0_Sub* m30[6];
    int m48;
    int m4C;
    char pad50[0x4F8];
    int m548;
    int m54C;
    int m550;
    void* m554;
    int m558;
    int m55C;
    char m560[0x28];
    void* m588;
    int m58C[2];
    int m594[33];
    void* m618[3];
    int m624[14];
    int m65C[13];
    int m690[4];
    int m6A0[2][2];
    int m6B0[2];
    int m6B8;
    int m6BC;
    int m6C0;
    int* m6C4;
    char pad6C8[0x4];
    int m6CC;
    int m6D0;
    int m6D4;
    int m6D8;
    int m6DC;
    Unk8019F8C0_Ent* m6E0;
    struct Unk80198AA0* m6E4;
    struct Unk80198AA0* m6E8;
    char pad6EC[8];
    int m6F4;
    Unk8019F8C0_Mgr* m6F8;
    int m6FC;
    Unk8019F8C0_Pl* m700;
    char m704[4];
    char pad708[0x8];
    void* m710;
    char pad714[0xC];
    Unk8019F8C0_Dev* m720;
    char pad724[0x1C];
    int m740;
    void* m744;
    char pad748[0x38];
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
