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

struct Unk80044C10_Entry;
struct Unk80044C10_Side;
struct Unk80044C10_E;
struct Unk80044C10_D;
struct Unk80044C10_C;
struct Unk80044C10_B;
class Unk80044C10_A;
struct Unk8004763C_Slot;
struct Unk8004763C;
struct Unk80044C98_Arg;

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

struct Unk80044C10_C {
    char pad0[0x10];
    Unk80044C10_D* m10;
    Unk80044C10_E* m14;
};

struct Unk80044C10_B {
    char pad0[0x6F8];
    Unk80044C10_C* m6F8;
};

struct Unk80044C10_A_Base {
    unsigned char m0;
    unsigned char m1;
    char pad2[0x96];
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
    char pad9C[0x94];
    Unk80044C10_A* m130;
    char pad134[0x280];
    int m3B4;
    char pad3B8[0x94];
    Unk80044C10_B* m44C;
    char pad450[0x8];
    int m458;
    char pad45C[0x4];
    int m460;
    char pad464[0x70];
    int m4D4;
    char pad4D8[0xB0];
    char m588[1];
    char pad589[0x143];
    void* m6CC;
    char pad6D0[0x34];
    int m704;
    int m708;
};

struct Unk8004763C_Slot {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    char pad18[0x4];
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
    char mFC[0xA9C];
    void* mB98;
    char padB9C[0x44];
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
void fn_8004838C(Unk8004763C* t, int i);
int fn_800484A8(Unk8004763C* t, int i);
void fn_80048818(Unk8004763C* t, int i);
void fn_80048A10(void* p);
void fn_80048B2C(void* p, int flags);
void fn_80048BC0(void* p);
void fn_80048BE4(void* p);
void fn_800490F4(void* p);
void fn_80377408(void* p); /* __builtin_delete */
void fn_80391348(unsigned a);
void fn_803EE7BC();
extern Unk8004763C* lbl_80617800;

#endif
