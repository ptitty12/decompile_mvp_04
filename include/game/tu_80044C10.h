#ifndef GAME_TU_80044C10_H
#define GAME_TU_80044C10_H

/*
Types for game/tu_80044C10.cpp and the units that follow it up to 0x80052794
(reconstructed; nothing here comes from original headers). Names are
placeholders (Unk<addr>, m<offset>).

Unk80044C10_A is a game object with a vtable pointer at +0x98 (a data-only
base of 0x98 bytes, then the polymorphic part). Evidence: fn_80044E20,
fn_80044EC0, fn_800459B0 and fn_80045BD8 read m0/m1 (bytes), m130 (an object
of the same shape), m44C, m458, m460, m4D4, m6CC, m700, m704 and m708, and
fn_80045BD8 calls virtual slots 22 and 24 (delta at +8N, function at +8N+4).
m44C -> B (m6F8 -> C), C -> D (m10) and E (m14); E holds two 0xE64-byte
per-side records and the flag m1CD0 that selects the side.
*/

struct Unk80044C10_Obj590;
struct Unk80044C10_Entry;
struct Unk80044C10_Side;
struct Unk80044C10_E;
struct Unk80044C10_D;
struct Unk80044C10_C;
struct Unk80044C10_G;
struct Unk80044C10_B;
class Unk80044C10_A;
struct Unk80048A10_Ent;
struct Unk80048A10_Sub;
struct Unk8004763C_Slot;
struct Unk8004763C;
struct Unk80044C98_Arg;

struct Unk80044C10_Obj590 {
    char pad0[0x590];
    unsigned m590;
    char pad594[0x170];
    int m704;
    int m708;
};

struct Unk80044C10_Entry {
    int m0;
    char pad4[0x30];
};

struct Unk80044C10_Side {
    char pad0[0x50];
    unsigned char* m50;
    int m54;
    char pad58[0x15C];
    unsigned char m1B4[0x80];
    char pad234[0x1B4];
    Unk80044C10_Entry m3E8[51];
    char padE44[0x20];
};

struct Unk80044C10_E {
    Unk80044C10_Side sides[2];
    unsigned char m1CC8;
    char pad1CC9[0x7];
    int m1CD0;
};

struct Unk80044C10_D {
    char pad0[0x1C];
    int m1C;
};

struct Unk80044C10_G {
    char pad0[0xC];
    int mC;
    char pad10[0x14];
    int m24;
    char pad28[0x50];
    int m78;
};

struct Unk80044C10_C {
    char pad0[0xC];
    Unk80044C10_G* mC;
    Unk80044C10_D* m10;
    Unk80044C10_E* m14;
};

struct Unk80044C10_F;

struct Unk80044C10_B {
    char pad0[0x6F8];
    Unk80044C10_C* m6F8;
    char pad6FC[0x4];
    Unk80044C10_F* m700;
};

struct Unk80044C10_Vec3 {
    float x;
    float y;
    float z;
};

struct Unk80044C10_A_Base {
    unsigned char m0;
    unsigned char m1;
    char pad2[0x2];
    int m4;
    char pad8[0x4];
    int mC;
    char pad10[0x40];
    int m50;
    int m54;
    char pad58[0x8];
    Unk80044C10_Vec3 m60;
    char pad6C[0x2C];
};

class Unk80044C10_A_Vt : public Unk80044C10_A_Base {
public:
    virtual int vslot1();
    virtual int vslot2();
    virtual int vslot3();
    virtual int vslot4();
    virtual int vslot5();
    virtual int vslot6();
    virtual int vslot7();
    virtual int vslot8();
    virtual int vslot9();
    virtual int vslot10();
    virtual int vslot11();
    virtual int vslot12();
    virtual int vslot13();
    virtual int vslot14();
    virtual int vslot15();
    virtual int vslot16();
    virtual int vslot17();
    virtual int vslot18();
    virtual int vslot19();
    virtual int vslot20();
    virtual int vslot21();
    virtual int vslot22();
    virtual int vslot23();
    virtual int vslot24();
};

class Unk80044C10_A : public Unk80044C10_A_Vt {
public:
    char pad9C[0x68];
    int m104;
    char pad108[0x28];
    Unk80044C10_A* m130;
    char pad134[0x150];
    int m284;
    char pad288[0x128];
    Unk80044C10_Obj590* m3B0;
    int m3B4;
    char pad3B8[0x4];
    int m3BC;
    char pad3C0[0xC];
    int m3CC;
    int m3D0;
    char pad3D4[0x8];
    int m3DC;
    char pad3E0[0x8];
    int m3E8;
    char pad3EC[0x10];
    int m3FC;
    char pad400[0xC];
    int m40C;
    char pad410[0x18];
    float m428;
    char pad42C[0x4];
    float m430;
    char pad434[0x14];
    int m448;
    Unk80044C10_B* m44C;
    char pad450[0x4];
    int m454;
    int m458;
    char pad45C[0x4];
    int m460;
    char pad464[0x70];
    int m4D4;
    int m4D8;
    char pad4DC[0xAC];
    char m588[1];
    char pad589[0x7];
    unsigned m590;
    char pad594[0x138];
    void* m6CC;
    char pad6D0[0x34];
    int m704;
    int m708;
};

/* 13-word block at Ent + 4 (copied by fn_80048E50). */
struct Unk80048A10_Blk {
    int w[13];
};

struct Unk80048A10_Ent {
    int m0;
    Unk80048A10_Blk m4;
    int m38;
    int m3C;
    float m40;
    int m44;
};

struct Unk80048A10_Sub {
    Unk80048A10_Ent mEnt[35];
    int m9D8;
    int m9DC;
    int m9E0;
    float m9E4;
    float m9E8;
    float m9EC;
    float m9F0;
    int m9F4;
    char pad9F8[0x4];
    int m9FC;
    int mA00;
    char padA04[0x1C];
    int mA20;
    int mA24;
    char padA28[0x4];
    int mA2C;
    int mA30;
    int mA34;
    char padA38[0x8];
    int mA40;
    int mA44;
    int mA48;
    int mA4C;
    int mA50;
    int mA54;
    int mA58;
    int mA5C;
    int mA60;
    int mA64;
    int mA68;
    int mA6C;
    int mA70;
    int mA74;
    int mA78;
    int mA7C;
    int mA80;
    char padA84[0x8];
    int mA8C;
    int mA90;
    char padA94[0x8];
    void* mA9C;
    char padAA0[0x3C];
    struct Unk80048B2C_Obj* mADC;
    const void* mAE0;
};

struct Unk8004763C_Slot {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

struct Unk8004763C {
    Unk8004763C_Slot mSlots[8];
    int mE0;
    int mE4;
    char padE8[0x4];
    int mEC;
    int mF0;
    int mF4;
    int mF8;
    Unk80048A10_Sub mFC;
    int mBE0[8];
    int mC00;
    unsigned mC04;
    void fn_80047DE0(int a, int b, int c, int d);
};

struct Unk80044C98_Arg {
    int m0;
    int m4;
    int m8;
    unsigned short mC;
    char padE[0xE];
    int m1C;
};

extern int lbl_806E0288;
extern int lbl_806E028C;
extern int lbl_806EF9A8;
extern int lbl_806EF9AC;
extern int lbl_806EF9B0;

int fn_80247858(int a, float* out);
Unk80044C10_A* fn_801A4B34(Unk80044C10_B* b);
int fn_80043B78(int a);
int fn_80043650(int a);
Unk8004763C* fn_800475EC();
void fn_80057C30(void* a, unsigned short b);
void fn_8018CA5C(void* a, float* b, float* c, float* d);
void* operator new(unsigned int size, int heap); /* 0x80377428 */
Unk8004763C* fn_8004763C(Unk8004763C* t);
void fn_8004778C(Unk8004763C* t, int flags);
int fn_80047B08(Unk8004763C* t);
void fn_80047CA4(Unk8004763C* t);
void fn_80047D40(Unk8004763C* t, int i);
int fn_80048294(Unk8004763C* t, int i);
int fn_8004838C(Unk8004763C* t, int i);
int fn_800484A8(Unk8004763C* t, int i);
void fn_80048818(Unk8004763C* t, int i);
Unk80048A10_Sub* fn_80048A10(Unk80048A10_Sub* p);
void fn_80048B2C(Unk80048A10_Sub* p, int flags);
void fn_80048BC0(Unk80048A10_Sub* p);
void fn_80048BE4(Unk80048A10_Sub* p);
void fn_800490F4(Unk80048A10_Sub* p);
void fn_80377408(void* p); /* __builtin_delete */
void fn_80391348(unsigned a);
void fn_803EE7BC();
extern Unk8004763C* lbl_80617800;

#endif
