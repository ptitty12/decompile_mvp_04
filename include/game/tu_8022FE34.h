#ifndef GAME_TU_8022FE34_H
#define GAME_TU_8022FE34_H

/*
 * Pitcher AI classes at 0x8022FE34-0x80233F08 (placeholders; names are the first
 * function address that proves them).
 *
 * Ent (0x2C bytes): element of the 5-entry array at Sub::m4. fn_8022FE34 stores
 * ints at +0, +0x14, +0x1C, +0x28 and floats at +4, +8, +0xC, +0x10, +0x20,
 * +0x24; fn_80230CC8 copies a whole Ent (24-byte loop plus 20-byte tail).
 * fn_80344538 is its constructor (fn_8022FF2C calls it on each element of the
 * g++ array-construct loop).
 *
 * Sub (0x1F8 bytes): four 5-element tables of {int, float, float} at +0xE0,
 * +0x11C, +0x158, +0x194 (stride 0xC), then three ints at +0x1D0 (entry count,
 * fn_80230CC8), +0x1D4 and +0x1D8. fn_80230024 reads +0x1D4 of element i.
 * Pai: a 4-byte owner pointer, then two Sub at +4 and +0x1FC (loop count 2 and
 * the stride 0x1F8 in fn_8022FF2C), then a copy of the owner's first word at +0x3F4.
 */
struct Unk8022FE34_Row {
    char pad0[0x8];
    int m8;
    char pad1[0x78 - 0xC];
    int m78;
    char pad2[0x70C - 0x7C];
    unsigned char m70C;
    char pad3[0xE64 - 0x70D];
};
struct Unk8022FE34_GameC {
    char pad0[0xC];
    void* mC;
};
struct Unk8022FE34_Game {
    char pad0[0xC];
    Unk8022FE34_GameC* mC;
    char pad10[4];
    Unk8022FE34_Row* m14;
};
struct Unk8022FE34_Ctx {
    char pad0[0x554];
    void* m554;
    char pad1[0x65C - 0x558];
    void* m65C;
    char pad2[0x6CC - 0x660];
    int m6CC;
    char pad3[0x6F4 - 0x6D0];
    int m6F4;
    Unk8022FE34_Game* m6F8;
    char pad4[0x704 - 0x6FC];
    char m704[0x1C];
    void* m720;
};
struct Unk8022FE34_V2 {
    float a;
    float b;
};
struct Unk8022FE34_V3 {
    int a;
    int b;
    int c;
};
struct Unk8022FE34_Pair {
    int a;
    int b;
};
struct Unk8022FE34_Owner;
struct Unk8022FE34_Obj480 {
    char pad0[0x44];
    unsigned m44;
};
struct Unk8022FE34_Pl {
    char pad0[0x480];
    Unk8022FE34_Obj480 m480;
    char pad1[0x704 - 0x480 - sizeof(Unk8022FE34_Obj480)];
    int m704;
    char pad2[0x8F0 - 0x708];
    int m8F0;
};
struct Unk8022FE34_W {
    int m0;
};

extern "C" void fn_80344538(void* p);

struct Unk8022FE34_Ent {
    int m0;
    float m4;
    float m8;
    float mC;
    float m10;
    int m14;
    int m18;
    int m1C;
    float m20;
    float m24;
    int m28;
    Unk8022FE34_Ent() { fn_80344538(this); }
};

struct Unk8022FE34_Tab {
    int m0;
    float m4;
    float m8;
};

struct Unk8022FE34_Sub {
    Unk8022FE34_Owner* m0;
    Unk8022FE34_Ent m4[5];
    Unk8022FE34_Tab mE0[5];
    Unk8022FE34_Tab m11C[5];
    Unk8022FE34_Tab m158[5];
    Unk8022FE34_Tab m194[5];
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
    int m1F4;
    Unk8022FE34_Sub() { fn_8022FE34(0); }
    void fn_8022FE34(Unk8022FE34_Owner* o);
    void fn_80230CC8(const Unk8022FE34_Ent* e);
    void fn_80231018();
};

struct Unk8022FE34_Pai {
    Unk8022FE34_Owner* m0;
    Unk8022FE34_Sub m4[2];
    Unk8022FE34_Ctx* m3F4;
    Unk8022FE34_Pai(Unk8022FE34_Owner* o);
    void fn_8022FFC4(Unk8022FE34_Owner* o, int i);
    int fn_80230024(int i);
    void fn_80230B54(int i);
    void fn_80230B88(int i);
    void fn_80230BBC(int i);
    void fn_80230268(int a, int b, Unk8022FE34_Ent* out);
};

struct Unk8022FE34_U;

struct Unk8022FE34_Z {
    Unk8022FE34_Ctx* m0;
    Unk8022FE34_Z(Unk8022FE34_Ctx* c);
    void fn_802361F8(float f, int a);
    void fn_80236240(float f);
};

struct Unk8022FE34_Owner {
    Unk8022FE34_Ctx* m0;
    Unk8022FE34_U* m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    int m1C;
    Unk8022FE34_V2 m20;
    Unk8022FE34_V2 m28;
    Unk8022FE34_V2 m30;
    Unk8022FE34_Pai m38;
    int m430;
    int m434;
    Unk8022FE34_Pair m438;
    Unk8022FE34_W m440;
    char pad444[0x728 - 0x444];
    float m728;
    char pad72C[0x734 - 0x72C];
    char m734[4];
    void fn_80231D0C(int i);
    int fn_80231DDC();
    Unk8022FE34_V3 fn_80231E4C();
    void fn_80231FC0();
    void fn_802321BC();
    void fn_8023246C();
    int fn_802324E0();
    int fn_802324EC();
    void fn_8023262C(int i, Unk8022FE34_Pl* pl, Unk8022FE34_Row* r);
    void fn_802326C4(int i, int j);
};

struct Unk8022FE34_U8s {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Unk8022FE34_U8 {
    char pad0[0x8];
    Unk8022FE34_U8s m8;
    char pad1C[0x3A4 - 0x1C];
    void* m3A4;
};
struct Unk8022FE34_X6D {
    char pad0[0x14];
    int m14;
};

struct Unk8022FE34_U {
    int m0;
    Unk8022FE34_Owner* m4;
    Unk8022FE34_U8* m8;
    char padC[0x44 - 0xC];
    int m44;
    int m48;
    int m4C[5];
    int m60;
    int m64;
    unsigned short m68;
    short pad6A;
    float m6C;
    char pad70[0x78 - 0x70];
    int m78;
    char pad7C[4];
    int m80;
    void fn_8023276C(int i);
    Unk8022FE34_Ctx* fn_80235FA8();
    void fn_80234E0C(float f);
    Unk8022FE34_Pai* fn_80234E38();
    int fn_80234E44();
    void fn_80235160();
    void fn_8023533C();
    void fn_80235364();
    void fn_80235A28();
    int fn_80235AB8();
    void fn_80235AC4();
    void fn_80235AD4();
    Unk8022FE34_V2 fn_80235BE0();
    Unk8022FE34_V2 fn_80235BFC();
    Unk8022FE34_V2 fn_80235C18();
    int fn_80235C68();
    float fn_80235D80();
    float fn_80235DA8();
    int fn_80235E28();
    int fn_80235E34(int a, int idx);
    void fn_80235EDC(float f);
    void fn_80235F7C();
    void fn_80235164();
    void fn_80235220();
    void fn_8023522C(int a);
    void fn_80235240();
    void fn_80235294();
    void fn_80235300();
    void fn_802356D4();
    void fn_802350F8();
    void fn_80235618();
    void fn_80235730();
    void fn_80235780(int a, int b, int c);
    void fn_8023584C();
    void fn_802358D0();
    void fn_8023590C();
    void fn_8023596C();
    void fn_80235A40();
    float fn_802354AC();
    Unk8022FE34_V3 fn_80235C34();
    float fn_80235C74(int a);
    Unk8022FE34_V3 fn_80235CEC(int a);
    float fn_80235DD0(int a, int b);
    int fn_80235E44(int a, int key);
    int fn_80235E84(int a, int b);
};

#endif
