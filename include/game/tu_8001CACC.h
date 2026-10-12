/*
 * Types for game/tu_8001CACC.cpp and game/tu_8001D7F8.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * Unk8001CE80: one large object (at least 0x4D8 bytes) whose methods fill both
 * units; most are thin forwarders that load a field and pass it to a function
 * in 0x8004xxxx (fn_8001D42C: this+0x3CC/+0x3D0 to fn_80042E68, ...). Only the
 * offsets those functions read or write are given; each is named after the
 * first function that touches it.
 *
 * The pointer at +0x130 leads to a second object whose +0x44C leads to a third
 * (+0x6F8 and +0x700 point to the next level; +0x708 is an int record index
 * and +0x480 / +0x588 are embedded sub-objects passed by address). Evidence:
 * fn_8001CF18, fn_8001CFCC, fn_8001D280, fn_8001D47C, fn_8001D62C.
 */
#ifndef GAME_TU_8001CACC_H
#define GAME_TU_8001CACC_H

struct Unk8001CE80_Vec2 {
    float x;
    float y;
};

/* +0x6F8 target: +0xC and +0x10 point to small records, +0x14 to the table of
 * 0xE64-byte entries (fn_8001CFCC, fn_8001D47C, fn_8001DC88, fn_8001E0C8). */
struct Unk8001D62C_Rec {
    char pad0[0x1C];
    int m1C;
};

struct Unk8001E0C8_Rec {
    char pad0[0x24];
    int m24;
    char pad28[0x80 - 0x28];
    int m80;
    char pad84[4];
    int m88;
};

/* Entity table row (stride 0xE64); the 128 bytes at +0x1B4 are summed (fn_8001DDFC). */
struct Unk8001D47C_Row {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
    char pad234[0xE64 - 0x234];
};

/* Sum of the 128 bytes at Row+0x1B4. Taking the row pointer as a parameter gives retail's
 * `addi r11,row,0x1b4; lbzx` pair inside the loop (a plain byte pointer gave `add` + `lbz 436(r9)`).
 * Callers that index a row by k * 0xE64 must compute the product in its own statement
 * (`int o = k * 0xE64; SumRow((Row*)(t + o))`): inline in the argument, the product is built
 * in place in the parameter register (`mulli r10; add r10,r10,t`), retail has `mulli r0; add r10,t,r0`. */
inline int Unk8001D47C_SumRow(Unk8001D47C_Row* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->m1B4[(unsigned char)i];
    }
    return s;
}

struct Unk8001D47C_Level {
    char pad0[0xC];
    Unk8001E0C8_Rec* mC;
    Unk8001D62C_Rec* m10;
    unsigned char* m14;
};

/* +0x700 target (fn_8001D8DC): +0x3A4 leads to a record with a word at +0x108, +0x3B8 is an id. */
struct Unk8001D8DC_Inner {
    char pad0[0x108];
    int m108;
};

struct Unk8001D8DC_Outer {
    char pad0[0x3A4];
    Unk8001D8DC_Inner* m3A4;
    char pad3A8[8];
    int m3B0;
    char pad3B4[4];
    int m3B8;
};

struct Unk8001D47C_Mid {
    char pad0[0x6CC];
    void* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Unk8001D47C_Level* m6F8;
    char pad6FC[4];
    Unk8001D8DC_Outer* m700;
};

struct Unk8001D62C_Mid {
    char pad0[0x44C];
    Unk8001D47C_Mid* m44C;
    char pad450[0x708 - 0x450];
    int m708;
};

struct Unk8001CE80_Entry {
    int m0;
    int m4;
    char pad8[0x20];
};

struct Unk8001CE80_Sub {
    char pad0[0x98];
    int m98;
};

/* vptr at +0x98 of the object at Unk8001CE80+0x3B0 (fn_8001D780 calls slot 24, vtable +0xC0) */
class Unk8001D780_VT {
public:
    char pad0[0x98];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16();
    virtual int s17();
    virtual int s18();
    virtual int s19();
    virtual int s20();
    virtual int s21();
    virtual int s22();
    virtual int s23();
    virtual int s24();
};

/* 0x24-byte records at Unk8001CE80+0x70 (four of them, count at +0x100); fn_8001D974 searches for m0 == m3B0. */
struct Unk8001D974_Ent {
    Unk8001CE80_Sub* m0;
    char pad4[8];
    int mC;
    int m10;
    char pad14[0x24 - 0x14];
};

class Unk8001CE80 {
public:
    void fn_8001CCE0(Unk8001CE80* o);
    int fn_8001CD94(int a, int flag);
    void fn_8001CE80();
    void fn_8001CEA8(float* b, float* a);
    int fn_8001D204(int v);
    int fn_8001CFCC(int a, int b);
    float fn_8001D0AC(int a, int k);
    int fn_8001D1A4(int a, int k, int x);
    void fn_8001D218();
    void fn_8001D248();
    void fn_8001D42C();
    void fn_8001D454();
    int fn_8001D47C();
    int fn_8001D538();
    int fn_8001D5D8();
    int fn_8001D62C();
    int fn_8001D694();
    void fn_8001D6CC();
    void fn_8001D70C();
    void fn_8001D75C();
    void fn_8001D780();
    void fn_8001D7D0();
    void fn_8001DA28();
    void fn_8001DA4C();
    void fn_8001DB4C();
    void fn_8001DB70();
    void fn_8001DBA0();
    void fn_8001DBE0();
    void fn_8001DC58();
    void fn_8001DC88();
    void fn_8001DCCC();
    void fn_8001DCF8();
    void fn_8001DDD8();
    void fn_8001DDFC();
    void fn_8001DE9C();
    void fn_8001E054();
    int fn_8001E084();
    int fn_8001D7F8();
    int fn_8001D850();
    int fn_8001D8DC();
    int fn_8001D974();
    void fn_8001DA7C();
    int fn_8001DA9C();
    void fn_8001E0C8();
    void fn_8001E294();
    void fn_8001E2EC();
    void fn_8001E31C();
    void fn_8001E34C();
    void fn_8001E3C8();

    unsigned char m0;
    unsigned char m1;
    char pad2[0x3A];
    int m3C;
    char pad40[0x8];
    int m48;
    char pad4C[0x24];
    Unk8001D974_Ent m70[4];
    int m100;
    int m104;
    char pad108[0x8];
    int m110;
    char pad114[0x4];
    int m118;
    char pad11C[0x4];
    int m120;
    char pad124[0xC];
    Unk8001D62C_Mid* m130;
    char pad134[0x20];
    Unk8001CE80_Entry m154[7];
    char pad26C[0x8];
    int m274;
    char pad278[0x10];
    Unk8001CE80_Vec2 m288;
    char pad290[0x120];
    Unk8001CE80_Sub* m3B0;
    int m3B4;
    Unk8001CE80_Vec2 m3B8;
    char pad3C0[0x4];
    int m3C4;
    float m3C8;
    int m3CC;
    int m3D0;
    char pad3D4[0xC];
    int m3E0;
    int m3E4;
    char pad3E8[0x10];
    int m3F8;
    char pad3FC[0x8];
    int m404;
    int m408;
    int m40C;
    char pad410[0x34];
    int m444;
    int m448;
    int m44C;
    int m450;
    int m454;
    int m458;
    int m45C;
    char pad460[0x8];
    int m468;
    char pad46C[0x8];
    int m474;
    char pad478[0x8];
    int m480;
    char pad484[0x50];
    int m4D4;
    char mEnd;

};

#endif
