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

/* Object behind Obj::m6C8 (vptr at +0); only slot 11 is called here. */
class Unk8002A920_Vt {
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
};

struct Unk80023AC4_Obj;
typedef void (Unk80023AC4_Obj::*Unk8061690C_Fn)();
/* Dispatch table at 0x8061690C: 50 entries of {key, pointer to member function} (12 bytes). */
struct Unk8061690C_Ent {
    int key;
    Unk8061690C_Fn fn;
};
extern Unk8061690C_Ent lbl_8061690C[50];

/* Sub-object at Obj+0x160 (initialised by fn_8001CE80; m8 is a counter at +0x168, m44 at +0x1A4). */
struct Unk8001CE80_Sub {
    char pad0[8];
    int m8;
    char padC[0x20 - 0xC];
    int m20[4];
    char pad30[0x40 - 0x30];
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
};
struct Unk8001F5CC_Tbl;
struct Unk80038EB4_Obj;

/* A 4-byte slot read as an int by some functions and as a float by others. */
union Unk80023AC4_Word {
    int i;
    float f;
};


/* Record behind Obj::m6B8 (its first word is compared against 3 in fn_800256F8). */
struct Unk800256F8_Rec {
    int m0;
    int m4;
};

struct Unk80023F98_Vec2 {
    float x;
    float y;
};

/* Entry of the stride-0x28 array at Obj+0x294 (fn_80023E18, fn_80023F98, fn_80029074). */
struct Unk80023E18_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    Unk80023F98_Vec2 m10;
    Unk80023F98_Vec2 m18;
    int m20;
    int m24;
};

struct Unk80023ED8_Pair {
    int m0;
    int m4;
};

/* Entry of the stride-0x24 array at Obj+0x1D0 (fn_80023ED8 clears m14, fn_8002BAD8 matches m0). */
struct Unk80023ED8_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
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
    int m10;
    int m14;
    float m18;
    float m1C;
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
void fn_800289F8(Unk80023AC4_Obj* x);
void fn_80021D6C(void* x, Unk8001F2C4_World* ctx, int n);
int fn_803445A0(char* p);
void fn_800488C4(Unk800475EC_Obj* o, int id, float f, int* a, Unk8001CE80_Sub* b, Unk8001F2C4_World* w);
void fn_80039790(Unk80038EB4_Obj* o, float f);
Unk801A4B34_Pos* fn_801A4910(Unk8001F2C4_World* w, int a, int b);
void fn_80035A58(int a, int b, int c, int d);
void fn_8003CC98(int a);
int fn_8002A534(Unk80023AC4_Obj* x, Unk8001F2C4_World* y);
int fn_8002A53C(Unk80023AC4_Obj* x, Unk8001F2C4_World* y);
int fn_8002A544(Unk80023AC4_Obj* x, Unk8001F2C4_World* y);
unsigned fn_8002A4C0(Unk80023AC4_Obj* x, Unk8001F2C4_World* y);
int fn_8002A2D4(Unk80023AC4_Obj* x);
void fn_8002F850(Unk80023AC4_Obj* x);
void fn_8003C804(int a, int b);
int fn_8006BE18(Unk8001F5CC_Tbl* t);
void fn_80344494(int* p, int a);
void fn_8003F974(int a);
void fn_80030274();
void fn_800351F8(int a, int b, int c, int d, int e);
void fn_80035090(int a, int b, int c, int d, int e);
int fn_8022EA7C(int pl, Unk80023F98_Vec2* v, float f);
int fn_8018B654(Unk801A4B34_Pos* p);
void fn_8003BB78(int a, int b, int c, int d, int e);
int fn_8002A3DC(Unk80023AC4_Obj* x);
void fn_80030794(Unk80023AC4_Obj* x, int* p);
void fn_80030778(Unk80023AC4_Obj* x, int* p, int n);
int fn_8022ED28(int pl);
int fn_8022EDC4(int pl);
int fn_8022EECC(int pl);
int fn_8022EF84(int pl);
int fn_8022F024(int pl);
int fn_8022EE5C(int pl);
int fn_8022F0C4(int pl);
void fn_800245D0(Unk80023AC4_Obj* x);
extern int* lbl_8061B9C4;
void fn_80057B54(int a, int b);
void fn_8002870C(Unk80023AC4_Obj* x);
void fn_800307B4(Unk80023AC4_Obj* x);
void* fn_801A4CE8(Unk8001F2C4_World* w, int a);
void fn_80378ACC(char* sub, void* p);
void fn_8003A058(Unk80038EB4_Obj* o, int a);
void fn_8003B378(int a);
float fn_8018CDB8(Unk801A4B34_Pos* p, int a, float f);
void fn_803EE7BC();
void fn_80048968(Unk800475EC_Obj* o);
void fn_800396D0(Unk80038EB4_Obj* o, int a);
Unk80038EB4_Obj* fn_8005BA9C();
void fn_8005C250(Unk80038EB4_Obj* o, int a);
void fn_8003968C(Unk80038EB4_Obj* o, int a);
float fn_8017FA08(int a);
void fn_80039854(Unk80038EB4_Obj* o, int a, float f);
void fn_800398E4(Unk80038EB4_Obj* o, float f);
void fn_800395B0(Unk80038EB4_Obj* o, int a);
void fn_80048C08(char* p);
void fn_8003EAB0(int a);
int fn_801C3E28(Unk8001F2C4_Inner* v);
Unk80038EB4_Obj* fn_80038EB4();
void fn_80039F04();
void fn_8003C9A0(int a);
void fn_80035E94(int a);
void fn_8002B5B0();
void fn_80035AE8(int a, int b, int c);
void fn_8003CC0C(int a, int b);
void fn_80048914(Unk800475EC_Obj* o, Unk8001F2C4_World* w);
void fn_8003E8E4(int a);
void fn_8003C9F4(int a);
void fn_8018CA5C(Unk801A4B34_Pos* p, float* a, float* b, float* c);
void fn_8002F160(Unk80023AC4_Obj* x);
int fn_8024D408(Unk801A4B34_Pos* p);
int fn_80257EA8(Unk8001F2C4_Rec* r, int a);
void fn_8003CC54(int a, int b);
void fn_8003CA24(int a, int b);
void fn_8002C830(Unk80023AC4_Obj* x);
void fn_8003538C(int a, int b, int c, int d);
void fn_8002C6F8(Unk80023AC4_Obj* x);
void fn_80026D7C(Unk80023AC4_Obj* x);
void fn_8003F8A4(int a);
void fn_8001CE80(Unk8001CE80_Sub* p);
void fn_8001CCE0(Unk8001CE80_Sub* p, Unk801A4B34_Pos* q);
void fn_8003DD5C(int a);
float fn_801C17EC(Unk801A4B34_Pos* p);
float fn_80190F0C(Unk801A4B34_Pos* p);
void fn_80189618(Unk801A4B34_Vec3* out, Unk801A4B34_Pos* p, float t);
Unk80023F98_Vec2 fn_80235BE0(int a, ...);
float fn_8018A214(Unk801A4B34_Pos* p);
void fn_8018959C(Unk801A4B34_Vec3* out, Unk801A4B34_Pos* p, float t);
float fn_8002559C(Unk80023AC4_Obj* x, float f);
}

struct Unk80023AC4_Obj : public Unk80021A60 {
    Unk80023AC4_Obj(); /* ctor is fn_800234D8 (tu_80021BE8.cpp), not defined here */
    char padBC[0xC];
    Unk8001F5CC_Tbl* mC8;
    int mCC;
    int mD0;
    int mD4;
    char padD8[0x4];
    int mDC;
    int mE0;
    char padE4[0xC];
    int mF0;
    int mF4;
    int mF8;
    int mFC;
    int m100;
    int m104;
    int m108;
    int m10C;
    char pad110[0x4];
    int m114;
    unsigned m118;
    int m11C;
    int m120;
    int m124;
    unsigned m128;
    int m12C;
    Unk80023AC4_Word m130;
    int m134;
    int m138;
    float m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    char pad154[0x4];
    int m158;
    int m15C;
    Unk8001CE80_Sub m160;
    int m1BC;
    int m1C0[3];
    char pad1CC[0x4];
    Unk80023ED8_Ent m1D0[1];
    char pad1F4[0x6C];
    int m260;
    int m264;
    char pad268[0x8];
    Unk80023ED8_Pair m270[3];
    char pad288[0x8];
    Unk801A4B34_Pos* m290;
    Unk80023E18_Ent m294[1];
    char pad2BC[0x118];
    int m3D4;
    int m3D8;
    int m3DC;
    int m3E0;
    int m3E4;
    char pad3E8[0x10];
    int m3F8[10][2];
    char pad448[0x20];
    int m468[2];
    char pad470[0xA0];
    Unk80023F98_Pl* m510;
    int m514;
    char pad518[0x4];
    int m51C;
    float m520;
    int m524;
    float m528;
    int m52C;
    int m530;
    int m534;
    char pad538[0x4];
    int m53C;
    int m540;
    char pad544[0x4];
    int m548;
    char pad54C[0xC];
    int m558;
    char pad55C[0x8];
    int m564;
    int m568;
    int m56C;
    int m570;
    int m574;
    int m578;
    char pad57C[0xC];
    float m588;
    char pad58C[0x4];
    float m590;
    char pad594[0xC];
    unsigned m5A0;
    char pad5A4[0x4];
    int m5A8;
    int m5AC;
    char pad5B0[0x10];
    Unk801A4B34_Pos* m5C0;
    char pad5C4[0x4];
    Unk801A4B34_Vec3 m5C8;
    Unk801A4B34_Vec3 m5D4;
    Unk801A4B34_Vec3 m5E0;
    char pad5EC[0x48];
    int m634;
    int m638;
    char pad63C[0x4];
    Unk801A4B34_Vec3 m640[9];
    int m6AC;
    char pad6B0[0x8];
    Unk800256F8_Rec* m6B8;
    Unk8002569C_Msg* m6BC;
    char pad6C0[0x8];
    int m6C8;
    float m6CC;
    int m6D0;
    int m6D4;
    char pad6D8[0x4];
    int m6DC;
    int m6E0;
    int m6E4;
    int m6E8;
    int m6EC;
    int m6F0;
    unsigned char m6F4;
    unsigned char m6F5;
    char pad6F6[0x2];
    int m6F8;
    int m6FC;
    int m700;
    int m704;
    int m708;
    int m70C;
    int m710;
    int m714;
    Unk801A4B34_Pos* m718;
    int m71C;
    int m720;
    Unk801A4B34_Pos* m724;
    char pad728[0x18];
    float m740;
    char pad744[0x30];
    Unk801A4B34_Pos* m774;
    int m778;
    int m77C[3];
    int m788[3];
    int m794;
    int m798;
    int m79C;
    char pad7A0[0x1C];
    int m7BC;
    int m7C0;
    int m7C4;
    int m7C8;
    int m7CC;
    char pad7D0[0x10];
    int m7E0;
    char pad7E4[0x10];
    int m7F4;
};

#endif
