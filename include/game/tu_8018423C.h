#ifndef GAME_TU_8018423C_H
#define GAME_TU_8018423C_H

/*
 * Types for src/game/tu_8018423C.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_801800FC.h"

struct Unk8018423C_B {
    char pad0[0x24];
    int m24;
};

struct Unk80184E0C_Vec {
    float m0;
    float m4;
    float m8;
};

/* One-word value, passed and returned through memory (fn_801854C8 swaps its bytes). */
struct Unk801854C8_U32 {
    unsigned int v;
};
extern "C" Unk801854C8_U32 fn_801854C8(Unk801854C8_U32 x);

/* Object with a word at +0x370 read and written through the U32 helpers. */
struct Unk801855A4_Obj {
    char pad0[0x370];
    Unk801854C8_U32 m370;
};

/* Owner context of the class below (same object as Unk801808A4_Ctx, other fields). */
struct Unk80185D80_Owner {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6F8 - 0x50];
    Unk801808A4_Y* m6F8;
    char pad6FC[0x72C - 0x6FC];
    void* m72C;
    void* m730;
};

/* Class constructed at 0x80185CD4 (vtable 0x8065FE78, vptr at +0x18). Its bases: a
 * data-only part of 0x18 bytes, then the polymorphic root Unk803282A8 (ctor 0x803282A8,
 * dtor 0x80328374) with 8 more bytes after the vptr; the class adds m24/m28. */
struct Unk803282A8_Data {
    char pad0[0x18];
};
class Unk803282A8_Virt : public Unk803282A8_Data {
public:
    virtual ~Unk803282A8_Virt();
};
class Unk803282A8 : public Unk803282A8_Virt {
public:
    Unk803282A8();
    virtual ~Unk803282A8();
    Unk80185D80_Owner* m1C;
    int m20;
};
class Unk80185CD4 : public Unk803282A8 {
public:
    Unk80185CD4();
    virtual ~Unk80185CD4();
    void fn_80185D48();
    void fn_80185D60();
    void fn_80185D80();
    void fn_80185DE8();
    void fn_80186704(int a);
    void fn_80186738(int a);
    void fn_80186788();
    void fn_80186890();
    int m24;
    float m28;
};
extern Unk80181140_F lbl_805CD8A0;
extern Unk80181140_F lbl_805CD870;
extern int lbl_8061C728[];

extern Unk80181140_F lbl_805CD8B0;
extern Unk80181140_F lbl_805CD8B4;
extern Unk80181140_F lbl_805CD874;
extern Unk80181140_F lbl_805CD878;
extern Unk80181140_F lbl_805CDA8C;
extern Unk80181140_F lbl_805CDA90;
extern void* lbl_8068BEAC;
extern void* lbl_8068BF0C;

struct Unk80187190;
/* Object of size 0xB04 created by the ctor below (ctor 0x80195404, dtor 0x80195568). */
class Unk80195404 {
public:
    Unk80195404(Unk80187190* owner, int flag);
    ~Unk80195404();
    char pad0[0xAB0];
    int* mAB0;
    char padAB4[0xB04 - 0xAB4];
};
class Unk80187190_M {
public:
    Unk80187190_M();
    char pad0[0x10];
};
extern "C" void fn_8035ABB0(void* p);
/* 0x20-byte element of the array at +0xBFC (120 of them; ctor loop in fn_80187190). */
struct Unk80187190_T {
    char pad0[0x10];
    Unk80187190_M m10;
    Unk80187190_T() { fn_8035ABB0(this); }
};
/* The 0xB04-byte object built by fn_80187190 (physics/ball style object; its vptrs
 * at +0x98 and +0xB8 and the sub-object at +0x360 with its vptr at +0x368 are stored by hand). */
struct Unk80187190 {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
    char padBC[0x360 - 0xBC];
    char m360[8];
    const void* m368;
    int m36C;
    char pad370[0x448 - 0x370];
    Unk80195404* m448;
    void* m44C;
    char pad450[0x4A0 - 0x450];
    int m4A0;
    unsigned int m4A4;
    char pad4A8[0x4E4 - 0x4A8];
    int m4E4;
    char pad4E8[0xBFC - 0x4E8];
    void* mBFC;
};
extern char lbl_8065FD80[];
extern char lbl_8065FD58[];
extern char lbl_8065FE10[];
extern char lbl_80649DB8[];
extern "C" {
void fn_8026C65C(void* self, void* owner, int flag);
void fn_803785E4(void* sub);
void fn_80378620(void* sub, int a);
int fn_80328648(void* owner);
void fn_80189E58(void* self);
void fn_80377488(void* p);
void fn_8026C864(void* self, int chrg);
}

/* Object whose flag word at +0x4A4 holds a bitfield (fn_80187D20) and a float at +0x4B0. */
struct Unk80187D20_Obj {
    char pad0[0x4A4];
    unsigned int a : 8;
    unsigned int flag : 1;
    unsigned int b : 23;
    char pad4A8[0x4B0 - 0x4A8];
    float m4B0;
    char pad4B4[4];
    float m4B8;
    float m4BC;
    float m4C0;
};
struct Unk801850B4_Obj {
    char pad0[0x1C7C];
    float m1C7C[1];
};

inline int Unk80185E28_Abs(int x)
{
    if (x > 0)
        return x;
    return -x;
}

/* Ctx fields used by fn_80184278: object at +0x734, a table of records at +0x570..+0x584. */
struct Unk80184278_Ctx {
    char pad0[0x570];
    Unk8018423C_B* m570[6];
    char pad588[0x734 - 0x588];
    void* m734;
};
struct Unk8014D9EC_C {
    float m[4];
};
struct Unk80186788_Pair {
    int a;
    int b;
};
struct Unk80186788_S {
    char pad0[0x308];
    int m308;
    int m30C;
    int m310;
    int m314;
    int m318;
    char pad31C[0x328 - 0x31C];
    int m328;
    Unk80186788_Pair m32C[20];
    char pad3CC[0x3F4 - 0x3CC];
    int m3F4;
};
extern Unk80186788_S* lbl_8061EA68;
extern Unk80181140_F lbl_805CD890;
extern Unk80181140_F lbl_805CD894;

extern "C" {
void* fn_80319330(void* p, int k);
void fn_8014D9EC(Unk8014D9EC_C* c, float a, float b, float d, float e, float f);
int fn_8014DDAC(Unk8014D9EC_C* c);
void fn_801A081C(Unk801808A4_Ctx* c, int v);
void* fn_8040B830(void* dst, const char* src, int n);
int fn_8040B6A0(const char* s);
int fn_8040B750(const char* a, const char* b, int n);
void fn_802B1FC0(void* p);
void fn_8031C328(void* a, int b);
void fn_8031C454(void* a, int b);
void fn_8031B470(void* a, int b, int c, int d);
void fn_80185E38(Unk80185CD4* o);
void* fn_80191A68(void* p);
void fn_801955BC(void* p);
void fn_8018D894(void* o, int a, float f);
int fn_80184E5C(Unk801850B4_Obj* o, float* v, int idx);
void fn_8040B61C(void* a, int b);
void fn_8018405C(Unk80181140* o, void* x, void* y, int z);
}

#endif /* GAME_TU_8018423C_H */
