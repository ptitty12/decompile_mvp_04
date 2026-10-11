#ifndef GAME_TU_8017D640_H
#define GAME_TU_8017D640_H

/*
 * Declarations for game/tu_8017D640.cpp (reconstructed; placeholders only).
 */

#include "game/tu_8017A930.h"

/* Root of the event/script classes (vtable 0x806849D0, dtor 0x8037B424), as in
 * tu_8016F45C.h plus the hash constructor 0x8037B3E8. */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
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
};

void* operator new(unsigned int size, int heap);        /* 0x80377428 */
extern int lbl_806EF9B4;                                /* default heap */

struct Unk8017DD64_Item {
    char pad0[0x78];
    int m78;
    char pad7C[0xE64 - 0x7C];
};
struct Unk8017DD64_Rec {
    char pad0[0x14];
    Unk8017DD64_Item* m14;
};
struct Unk8017DD64_Ctx;
struct Unk8017DD64_Ctx {
    char pad0[0x65C];
    int m65C[13];
    char pad690[0x6F8 - 0x690];
    Unk8017DD64_Rec* m6F8;
    char pad6FC[0x704 - 0x6FC];
    int m704;
};

struct Unk8017EE58_Rec {
    char pad0[0x1CCA];
    unsigned char m1CCA;
};
struct Unk8017EE58_Mid {
    char pad0[0x14];
    Unk8017EE58_Rec* m14;
};
struct Unk8017EE58_Ctx {
    char pad0[0x6F8];
    Unk8017EE58_Mid* m6F8;
};

/* Pointer-owning handle: ctx at +0, m8/mC/m10 state, vptr at +0x18. */
struct Unk8017EE24_T {
    Unk8017EE58_Ctx* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

/* Table object: ints at +0 and +0x50 (20 each), +0xA0, +0xA4 and +0x110 (27 each). */
struct Unk8017EED0_T {
    int m0[20];
    int m50[20];
    int mA0;
    int mA4[27];
    int m110[27];
};

void fn_8017EE24(Unk8017EE24_T* p);

class Unk8017EDF0 : public Unk8017EE24_T {
public:
    Unk8017EDF0(Unk8017EE58_Ctx* ctx, int b);
    virtual ~Unk8017EDF0();
};

/* Member with an out-of-line destructor (0x80034BBC), size not known. */
class Unk80034BBC {
public:
    ~Unk80034BBC();
    char m0[0x1F0];
};
class Unk8017F628 {
public:
    virtual ~Unk8017F628();
    char pad0[0x10];
    Unk80034BBC m10;
};
class Unk8037C7FC {
public:
    int fn_8037CE98(int arg, int value, int flags);
};
Unk8037C7FC* fn_8037C7FC();

struct Unk801800B8_T {
    char pad0[0x20];
    int m20;
    char m24[20];
    char pad38[0x58 - 0x38];
    int m58;
};
struct Unk8017F744_Ctx {
    char pad0[0x6F8];
    int m6F8;
    char pad6FC[4];
    int m700;
};
struct Unk8017F744_T {
    Unk8017F744_Ctx* m0;
    int m4;
    int m8;
    char padC[4];
    char m10[0x10];
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    int m48;
    float m4C[100];
    int m1DC;
    int m1E0;
};
void fn_80034CA4(void* p);

struct Unk8017E030_Rec {
    char pad0[0x1CC9];
    unsigned char m1CC9;
    char pad1CCA[0x1CD0 - 0x1CCA];
    int m1CD0;
};
int fn_8006BE18(void* a);
int fn_80081B60(void* p);
int fn_80096988(void* p, int a, int b);

struct Unk8017DCCC_Obj {
    char pad0[0x704];
    int m704;
    int m708;
};
struct Unk8017E2E8_T {
    char pad0[0x24];
    char m24[0x3B0 - 0x24];
    void* m3B0;
    char pad3B4[4];
    void* m3B8;
    char pad3BC[0x3C8 - 0x3BC];
    void* m3C8;
};
void fn_8023522C(void* p);
void fn_801DBE30(void* p, int a, int b, int c);
void fn_8017F67C(char* p, int a, int b, int c);
void fn_801ABC14(void* p);
int fn_802491D8(int p);

int fn_8017E374(Unk8017A930_T* p, int a, char* b, int c, int d, int e);
void fn_8017C72C(Unk8017A930_T* p);
void fn_80252C1C(char* p);
void fn_801A6820(void* p);
int fn_80099B50(void* p, int i);
int fn_801A49F0(void* ctx, int a, int b);

/* Event class, 0x70 bytes, hash 0xEF8A9748 (vtable 0x806602A8). */
class Unk8017EF7C : public Unk8037B3E8 {
public:
    Unk8017EF7C();
    virtual ~Unk8017EF7C();
    Unk8037B3E8* fn_vslot5();
    char pad4[0x70 - 4];
};

struct Unk8017F8A0_T {
    char pad0[0x28];
    float m28;
    float m2C;
    float m30;
    char pad34[0x48 - 0x34];
    int m48;
};

void fn_8017EF00(void* p);
void fn_801800B8(void* p);
void fn_8017FF74(void* p);

#endif
