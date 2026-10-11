/* generated header: see source file comments for evidence */
#ifndef GAME_TU_801B7FB0_H
#define GAME_TU_801B7FB0_H
#include "game/chooser.h"
typedef Unk80273498_Vec3 Vec3;
struct Unk801B7FB0_Ump;
struct Unk801B7FB0_P;
struct Unk801B7FB0_B;
struct Unk80087A58_O;
struct Unk801B7FB0_Ai;

/* Game-state object at P::m6F8 + 0x14: two 0xE64-byte team records, then
 * counters (fn_801B838C reads +0x1CCB, fn_801B9880 +0x1CC9, fn_801B9C5C +0x1CCA,
 * fn_801B9940 +0x1CD0, fn_801B9A18 +0x1CC8, fn_801BA130/fn_801BA288 +0x104..+0x110). */
struct Unk801B7FB0_Team {
    char pad0[0x104];
    float m104;
    int m108;
    int m10C;
    int m110;
    char pad114[0xA0];
    unsigned char m1B4[0x80];
    char pad234[0xC30];
};


struct Unk801B7FB0_Teams {
    Unk801B7FB0_Team t[2];
    unsigned char m1CC8;
    unsigned char m1CC9;
    unsigned char m1CCA;
    unsigned char m1CCB;
    char pad1CCC[0x4];
    int m1CD0;
};


struct Unk801B7FB0_Arr {
    char pad0[0x14];
    int m14[3];
};

struct Unk801B7FB0_GM {
    char pad0[0xC];
    Unk80087A58_O* mC;
};


struct Unk801B7FB0_Game {
    char pad0[0xC];
    Unk801B7FB0_GM* mC;
    Unk801B7FB0_Arr* m10;
    Unk801B7FB0_Teams* m14;
};



struct Unk801B7FB0_Ump {
    int m0;
    Unk801B7FB0_P* m4;
    Unk801B7FB0_P* m8;
    float mC;
};


struct Unk801B7FB0_B {
    int m0;
    Unk801B7FB0_P* m4;
    Unk801B7FB0_Ai* m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    float m24;
    int m28;
    int m2C;
    int m30;
};


/* Flag word at P::mB3C (fn_801C8014 tests bit 4 from the top). */
struct Unk801B7FB0_Bits {
    unsigned a : 4;
    unsigned f : 1;
    unsigned rest : 27;
};

struct Unk801B7FB0_Sub58C {
    char pad0[0xC];
    float mC;
    int m10;
};


struct Unk801B7FB0_M934 {
    char pad0[0x10];
    int m10;
};

struct Unk801B7FB0_Link {
    char pad0[0x838];
    int m838;
};

struct Unk801B7FB0_PBase {
    char pad0[0x4C];
    unsigned m4C;
    char pad50[0x10];
    Vec3 m60;
    char pad6C[0x2C];
};


struct Unk801B7FB0_PV : public Unk801B7FB0_PBase {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int x);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual int v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31(void* x);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
};


struct Unk801B7FB0_P : public Unk801B7FB0_PV {
    char pad9C[0x1C8];
    int m264;
    char pad268[0x104];
    Unk801B7FB0_P* m36C;
    char pad370[0x8];
    int m378;
    char pad37C[0x10];
    int m38C;
    char pad390[0x60];
    float m3F0;
    float m3F4;
    char pad3F8[0x40];
    float m438;
    char pad43C[0x10];
    Unk801B7FB0_P* m44C;
    char pad450[0x8];
    int m458;
    char pad45C[0xF8];
    Unk8014D8AC* m554;
    char pad558[0x30];
    int m588;
    Unk801B7FB0_Sub58C m58C;
    float m5A0;
    char pad5A4[0x24];
    int m5C8;
    int m5CC;
    char pad5D0[0x48];
    Unk801B7FB0_Link* m618;
    char pad61C[0x40];
    Unk801B7FB0_P* m65C[13];
    char pad690[0x3C];
    Unk801B7FB0_P* m6CC;
    char pad6D0[0x14];
    Unk801B7FB0_P* m6E4;
    char pad6E8[0xC];
    int m6F4;
    Unk801B7FB0_Game* m6F8;
    char pad6FC[0x4];
    void* m700;
    int m704;
    int m708;
    char pad70C[0x24];
    int m730;
    char pad734[0x1F8];
    int m92C;
    char pad930[0x4];
    Unk801B7FB0_M934* m934;
    char pad938[0xCC];
    int mA04;
    char padA08[0x4];
    char mA0C[4];
    char padA10[0xA4];
    float mAB4;
    char padAB8[0x84];
    Unk801B7FB0_Bits mB3C;
    char padB40[0x2C];
    int mB6C;
    char padB70[0x10];
    float mB80;
    float mB84;
    Unk801B7FB0_Ump* mB88;
};

struct Unk801B7FB0_Slot {
    void* m0;
    int m4;
    float m8;
};


struct Unk801B7FB0_Ai {
    void* m0;
    char pad4[0x4];
    Unk801B7FB0_B* m8;
    void* mC;
    int m10;
    Unk801B7FB0_P* m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    Unk801B7FB0_Slot m38[4];
    int m68;
    char pad6C[0x4];
};

/* Stack event object (same shape as Unk8002F894_Obj): id at +0, vptr at +4 (stored
 * twice: base vtable, then the derived one), two payload words. */
extern char lbl_80649DA0[];
extern char lbl_80649D88[];
extern char lbl_8065FA78[];
struct Unk801B7FB0_Msg {
    int m0;
    const void* vptr;
    int m8;
    int mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived2(int b, int a)
    {
        vptr = lbl_8065FA78;
        mC = b;
        m8 = a;
    }
    void End() { vptr = lbl_80649DA0; }
};
#endif
