/*
 * Types for game/tu_800239F4.cpp .. game/tu_8002B430.cpp (reconstructed; nothing here comes
 * from original headers). Unk80023AC4_Obj is the state-machine class whose methods fill
 * these units. Its first base is Unk80021A60 (data 0x00..0xB8, vptr +0xB8; m80[0] is the
 * game context Unk8001F2C4_World, the stride-12 table at +0 is used through fn_800233B4
 * and friends); fn_8002A244(this, id, duration) switches state. Only the fields the
 * functions touch are declared; the real class has more bases and vtables at +0xC4 that
 * no function here needs.
 */
#ifndef GAME_TU_800239F4_H
#define GAME_TU_800239F4_H

#include "game/tu_80021BE8.h"

struct Unk80023AC4_Obj;

/* Sub-object at Obj+0x160 (initialised by fn_8001CE80; m8 is a counter at +0x168, m44 at +0x1A4). */
struct Unk8001CE80_Sub {
    char pad0[8];
    int m8;
    char padC[0x44 - 0xC];
    int m44;
    char pad48[0x5C - 0x48];
};
struct Unk8001F5CC_Tbl;

/* A 4-byte slot read as an int by some functions and as a float by others. */
union Unk80023AC4_Word {
    int i;
    float f;
};

/* Player object (same as Unk80270BA0_X) with its vptr at +0x98; only slot 24 is called here. */
struct Unk80023F98_PlBase {
    char pad0[0x98];
};
class Unk80023F98_Pl : public Unk80023F98_PlBase {
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
    virtual int fn_vslot24();
};

struct Unk80023F98_Vec2 {
    float x;
    float y;
};

/* Entry of the stride-0x28 array at Obj+0x2A4 (fn_80023E18, fn_80023F98). */
struct Unk80023E18_Ent {
    Unk80023F98_Vec2 m0;
    Unk80023F98_Vec2 m8;
    int m10;
    int m14;
    char pad18[0x10];
};

struct Unk80023ED8_Pair {
    int m0;
    int m4;
};

/* Entry of the stride-0x24 array at Obj+0x1E4 (fn_80023ED8 clears the first word). */
struct Unk80023ED8_Ent {
    int m0;
    char pad4[0x20];
};

/* Message type 0x50 (a position at +8 and a float at +0x14). */
struct Unk800239F4_Msg50 {
    int m0;
    int m4;
    Unk801A4B34_Vec3 m8;
    float m14;
};
inline Unk801A4B34_Vec3 Unk800239F4_Pos(const Unk800239F4_Msg50* m) { return m->m8; }

/* Message record behind Unk80023AC4_Obj::m6BC (type id at +0; state handlers copy fields out). */
struct Unk8002569C_Msg {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[8];
    float m18;
    float m1C;
    char pad20[8];
    int m28;
    int m2C;
    int m30;
    int m34;
};

/* Checked cast of a message record to the layout for type id (null if the id differs). */
inline Unk8002569C_Msg* Unk8002569C_Cast(Unk8002569C_Msg* m, int id)
{
    Unk8002569C_Msg* r;
    if (m != 0) {
        r = 0;
        if (m->m0 == id)
            r = m;
    } else {
        r = 0;
    }
    return r;
}


extern "C" {
void fn_8002A244(Unk80023AC4_Obj* x, int id, float duration);
int fn_803445A0(char* p);
void fn_8002F850(Unk80023AC4_Obj* x);
void fn_8003C804(int a, int b);
int fn_8006BE18(Unk8001F5CC_Tbl* t);
void fn_80344494(int* p, int a);
void fn_8003F974(int a);
void fn_80030274();
void fn_8003EAB0(int a);
int fn_801C3E28(Unk8001F2C4_Inner* v);
void fn_80038EB4();
void fn_80039F04();
void fn_8003C9A0(int a);
void fn_80035E94(int a);
void fn_8002B5B0();
void fn_80035AE8(int a, int b, int c);
void fn_8003CC0C(int a, int b);
void fn_8003F8A4(int a);
void fn_8001CE80(Unk8001CE80_Sub* p);
float fn_80190F0C(Unk801A4B34_Pos* p);
void fn_80189618(Unk801A4B34_Vec3* out, Unk801A4B34_Pos* p, float t);
Unk80023F98_Vec2 fn_80235BE0(int a, ...);
float fn_8018A214(Unk801A4B34_Pos* p);
void fn_8018959C(Unk801A4B34_Vec3* out, Unk801A4B34_Pos* p, float t);
float fn_8002559C(Unk80023AC4_Obj* x, float f);
}

struct Unk80023AC4_Obj : public Unk80021A60 {
    Unk80023AC4_Obj(); /* ctor is fn_800234D8 (tu_80021BE8.cpp), not defined here */
    char padBC[0x14];
    int mD0;
    char padD4[0x8];
    int mDC;
    char padE0[0x20];
    int m100;
    int m104;
    char pad108[0x4];
    int m10C;
    char pad110[0x4];
    int m114;
    unsigned m118;
    int m11C;
    char pad120[0x4];
    int m124;
    int m128;
    int m12C;
    Unk80023AC4_Word m130;
    int m134;
    int m138;
    float m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    char pad150[0x10];
    Unk8001CE80_Sub m160;
    int m1BC;
    int m1C0[3];
    char pad1CC[0x18];
    Unk80023ED8_Ent m1E4[1];
    char pad208[0x58];
    int m260;
    char pad264[0xC];
    Unk80023ED8_Pair m270[3];
    char pad288[0x8];
    Unk801A4B34_Pos* m290;
    char pad294[0x10];
    Unk80023E18_Ent m2A4[1];
    char pad2CC[0x108];
    int m3D4;
    char pad3D8[0xC];
    int m3E4;
    char pad3E8[0x128];
    Unk80023F98_Pl* m510;
    int m514;
    char pad518[0x4C];
    int m564;
    int m568;
    int m56C;
    char pad570[0x4];
    int m574;
    int m578;
    char pad57C[0xBC];
    int m638;
    char pad63C[0x4];
    Unk801A4B34_Vec3 m640[9];
    char pad6AC[0x10];
    Unk8002569C_Msg* m6BC;
    char pad6C0[0x8];
    int m6C8;
    float m6CC;
    int m6D0;
    char pad6D4[0x28];
    int m6FC;
    int m700;
    char pad704[0x8];
    int m70C;
    int m710;
    char pad714[0x4];
    Unk801A4B34_Pos* m718;
    char pad71C[0x8];
    Unk801A4B34_Pos* m724;
    char pad728[0x6C];
    int m794;
    char pad798[0x24];
    int m7BC;
    char pad7C0[0x34];
    int m7F4;
};

#endif
