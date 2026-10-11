#ifndef GAME_TU_80198DB8_H
#define GAME_TU_80198DB8_H

/*
 * Types for src/game/tu_80198DB8.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_80194D44.h"

/* Player/ball-like object with the vtable at +0x98 (virtual 9 takes one argument, as in
 * Unk80190EB4_Obj) and mode fields at +0x37C etc. */
class Unk80198E5C_Virt : public Unk80190EB4_Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a);
    virtual void v9(int a);
};
struct Unk80198E5C_Obj : public Unk80198E5C_Virt {
    char pad9C[0x264 - 0x9C];
    int m264;
    char pad268[0x37C - 0x268];
    int m37C;
    int m380;
    int m384;
    char pad388[0x3E8 - 0x388];
    int m3E8;
    char pad3EC[0x404 - 0x3EC];
    int m404;
};

struct Unk8019AC78_E {
    char pad0[0x54C];
    int m54C;
    int m550;
};
struct Unk8019ACE0_B {
    char pad0[0x14];
    int m14;
};
struct Unk8019ACE0_A {
    char pad0[0x10];
    Unk8019ACE0_B* m10;
};
struct Unk8019ACE0_C {
    char pad0[0x54C];
    Unk8019ACE0_A* m54C;
};
struct Unk8019AC78_Obj {
    char pad0[0xBC];
    Unk8019ACE0_C* mBC;
    char padC0[0x240 - 0xC0];
    int m240;
    char pad244[0x36C - 0x244];
    int m36C;
    int m370;
    char pad374[0x3E0 - 0x374];
    Unk8019AC78_E* m3E0;
};
struct Unk8019B99C_Obj {
    char pad0[0x24];
    Unk8014D8AC_Ctx* m24;
};
/* Small polymorphic object (vptr at +8 after two data words; ctor fn_8019B9CC, dtor
 * fn_8019B9F4, vtable 0x8065F938). */
struct Unk8019B9CC_Data {
    int m0;
    int m4;
};
class Unk8019B9CC : public Unk8019B9CC_Data {
public:
    Unk8019B9CC(int a);
    virtual ~Unk8019B9CC();
};
struct Unk8019B9CC_Mgr {
    char pad0[0x3650];
    int m3650;
};
extern Unk8019B9CC_Mgr* lbl_8061E978;

struct Unk8019B0E4_Obj {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
    char padBC[0x360 - 0xBC];
    char m360[8];
    const void* m368;
    char pad36C[0x3FC - 0x36C];
    const void* m3FC;
};
struct Unk8019B24C_Obj {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x24 - 0x1C];
    void* m24;
};
extern char lbl_8065F760[];
extern char lbl_8065F738[];
extern char lbl_8065F720[];
extern char lbl_8065F7F0[];
extern char lbl_8065F688[];
extern int lbl_8061B894;
extern int lbl_8061C9F8;
extern char lbl_805D051C[];
extern char lbl_805D052C[];
extern char lbl_805D053C[];
extern char lbl_805D054C[];
extern char lbl_805D055C[];
extern char lbl_805D056C[];
extern char lbl_805D057C[];
extern char lbl_805D058C[];
extern char lbl_805D059C[];

struct Unk8019755C_Data;
extern "C" {
void fn_8019755C(Unk8019755C_Data* self, int chrg);
void fn_80198F68(void* o);
void fn_80199554(void* o);
void fn_8019A44C(void* o, void* x);
void fn_80328234(void* o, int a, void* owner);
void fn_8019B2A0(struct Unk80198E5C_Obj* o);
void fn_8030AC88(void* p);
void fn_8030AF34(void* p, int a);
void fn_8030AF9C(void* p, int a);
void* fn_80319330(void* p, int a);
void* fn_803119C0();
void fn_803116D4(void* a, void* b, int c, int d, int e, int f, int g, int h, float k);
void fn_8019AB74(void* o);
void fn_8019AC78(struct Unk8019AC78_Obj* o);
void fn_803DE374(int a, int b);
void fn_8026CA5C(void* o);
void fn_8019B490(void* o);
void fn_802C0888(void* p, float t);
int fn_802C0050(void* p, void* a, void* b, float* t, void* p1, void* p2, float k);
void fn_802C0EC4(void* p);
void* fn_80198CC0(void* o);
void fn_80199414();
void fn_8026CC04(void* o, float f);
void fn_80197604(void* p);
void fn_8026CB30(void* o);
}

#endif /* GAME_TU_80198DB8_H */
