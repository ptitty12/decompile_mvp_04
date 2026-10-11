#ifndef GAME_TU_8006902C_H
#define GAME_TU_8006902C_H

/*
 * Game-session class at 0x80069F0C (size 0x5C: fn_80069F0C is called right
 * after `new (0) 0x5C`). Placeholder names; layouts come from the offsets the
 * methods in 0x8006902C-0x8006D05C use.
 *
 * Unk80069F0C: vptr at +8 (lbl_8064A1B8 in the ctor, lbl_80649DB8 in the dtor),
 * mC -> Unk8006902C_Ctx, m10 -> Unk8006902C_Mode, m14 is a 0x10-byte handle
 * object (fn_8006F4D0 constructs it, allocating 0x1DA4 bytes) whose first word
 * points at two 0xE64-byte per-side records (evidence: fn_8006A138 and
 * fn_8006A238 index it with mulli 0xE64 and test the side with m1CD0).
 */
struct Unk80069F0C;

struct Unk8006902C_CtxC {
    Unk80069F0C* m0;
};

struct Unk8006902C_Ctx {
    char pad0[0xC];
    Unk8006902C_CtxC* mC;
    char pad10[0x10];
    Unk80069F0C* m20;
    int m24;
    char pad28[0x7C - 0x28];
    int m7C;
    int m80;
    int m84;
    int m88;
    char pad8C[0x600 - 0x8C];
    int m600;
};

struct Unk8014D81C_Obj {
    char pad0[0x1C];
};

struct Unk8006902C_EvC088 {
    char pad0[8];
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

struct Unk8006902C_EvCFA4 {
    char pad0[8];
    int m8;
    char padC[7];
    unsigned char m13;
};

struct Unk8006902C_EvC17C {
    char pad0[8];
    int m8;
    int mC;
};

struct Unk8006902C_Ev75C {
    char pad0[8];
    int m8;
};

struct Unk8006902C_Mode {
    char pad0[0x1C];
    int m1C;
    char pad20[0x22C - 0x20];
    int m22C;
};

struct Unk8006902C_Entry {
    int m0;
    int m4;
};

struct Unk8006902C_Rec {
    char pad0[0xA];
    unsigned char mA;
    char padB[0x34 - 0xB];
};

struct Unk8006902C_Side {
    char pad0[0x198];
    int m198;
    char pad19C[0x1B4 - 0x19C];
    unsigned char m1B4[0x80];
    unsigned char m234;
    unsigned char m235;
    char pad236[2];
    Unk8006902C_Entry m238[16];
    char pad2B8[0x3E8 - 0x2B8];
    Unk8006902C_Rec m3E8[16];
    char pad728[0x92C - 0x728];
    char m92C[0x30];
    char pad95C[0xC9C - 0x95C];
    char mC9C[0x30];
    char padCCC[0xE64 - 0xCCC];
};

struct Unk8006902C_Players {
    Unk8006902C_Side s[2];
    unsigned char m1CC8;
    unsigned char m1CC9;
    unsigned char m1CCA;
    unsigned char m1CCB;
    unsigned char m1CCC;
    unsigned char m1CCD;
    char pad1CCE[2];
    int m1CD0;
    int GetC8() { return m1CC8; }
    int GetC9() { return m1CC9; }
    int GetCA() { return m1CCA; }
    int GetCB() { return m1CCB; }
};

struct Unk8006902C_Handle {
    Unk8006902C_Players* m0;
    int m4;
    int m8;
    int mC;
};

struct Unk80069F0C {
    char pad0[8];
    void* m8;
    Unk8006902C_Ctx* mC;
    Unk8006902C_Mode* m10;
    Unk8006902C_Handle m14;
    int m24;
    Unk8014D81C_Obj m28;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;

    Unk80069F0C* fn_80069F0C(Unk8006902C_Ctx* a);
    void fn_80069F9C(int chrg);
    void fn_8006A004();
    void fn_8006A070();
    void fn_8006A0C4(int a, int b, int c, int d);
    void fn_8006A12C(int a);
    int fn_8006A138();
    int fn_8006A1B4();
    int fn_8006BDCC();
    int fn_8006BE18();
    void fn_8006C930();
    int fn_8006BF10();
    void fn_8006C088(Unk8006902C_EvC088* ev);
    Unk8006902C_Side* SideAt(int off) { return (Unk8006902C_Side*)((char*)m14.m0 + off); }
    void fn_8006CFA4(Unk8006902C_EvCFA4* ev);
    void fn_8006EC94(unsigned char c, int k);
    int fn_8006A238(int idx);
    void fn_8006C17C(Unk8006902C_EvC17C* ev);
    void fn_8006A22C();
    int fn_8006A214();
    void fn_8006C02C();
    void fn_8006C064();
    void fn_8006C038(void* a);
    void fn_8006C698();
    void fn_8006C75C(Unk8006902C_Ev75C* ev);
    void fn_8006C7E8(int a);
};

void fn_8006902C(int initialize, int priority);

#endif
