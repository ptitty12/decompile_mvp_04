/*
 * Types shared by game/tu_800A8684.cpp .. game/tu_800B5C68.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The functions are the methods of the front-end "action"/"condition" classes
 * (SetGameMode, ChangeMovie, ActionList, ... named by their attribute strings)
 * and the FE state objects. Their vtables live in .data, so the methods are
 * written as extern "C" functions that take the object explicitly; only the
 * virtual slots the code calls through are declared.
 */
#ifndef GAME_TU_800A8684_H
#define GAME_TU_800A8684_H

void* operator new(unsigned int size, int heap);
extern int lbl_806EF9B4;

extern "C" {
void fn_80400560(void* p, int n);
char* fn_8040B61C(char* dst, const char* src);          /* behaves like strcpy */
int fn_8040B6A0(const char* s);                          /* behaves like strlen */
int fn_8040B574(const char* a, const char* b);           /* behaves like strcmp */
/* Token reader: copies the next delimited token of s (length len) into out
 * (capacity size) and stores the number of characters consumed in *used. */
void fn_80378B68(const char* s, unsigned len, char* out, int size, int delim, int flag, unsigned* used);
}

/* Front-end action/condition object. Only the slots the code calls are
 * given (vslot3 = "is valid", vslot6 = parse one token). The derived structs
 * below add the value fields the individual classes use at +4. */
class UnkFEVirt {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual int fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual int fn_vslot6(char** s, int n);
};
struct UnkFEObj : UnkFEVirt {   /* int value (+4), two more ints */
    int m4;
    int m8;
    int mC;
};
struct UnkFEByte : UnkFEVirt {  /* flag byte (+4) */
    unsigned char m4;
};
struct UnkFEStr : UnkFEVirt {   /* string (+4) */
    char m4[0x40];
};

/* Object returned by fn_800B555C (front-end state): +0 and +4 written by the
 * flag actions (fn_800A94B4, fn_800A9328), +8 address passed to fn_800C1D6C
 * (fn_800A89DC), +0x608 compared by fn_800A9B0C / fn_800A9C90. */
struct Unk800B555C {
    int m0;
    int m4;
    int m8[0x180];
    int m608;
    char pad60C[0x660 - 0x60C];
    int m660;
    char pad664[0x674 - 0x664];
    int m674;
    int m678;
    int m67C;
    float m680;
    int m684;
    char pad688[0x6A0 - 0x688];
    const void* m6A0;
};
extern "C" Unk800B555C* fn_800B555C();


/* ---- virtual-slot placeholder classes used by game/tu_800B5C68.cpp (added by pass 2) ---- */
/* vptr at +0x3C (virtual N is at vtable +8N); only the slots called are typed. */
class FEV3C {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79(char* a);
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90(int a, int b);
    virtual void s91(int a, int b);
    virtual void s92(int a, int b, int c);
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
};
/* vptr at +0x64 (virtual N is at vtable +8N); only the slots called are typed. */
class FEV64 {
public:
    char pad0[0x64];
    virtual ~FEV64();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7(char* a);
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(char* a);
};
/* vptr at +0x18 (virtual N is at vtable +8N); only the slots called are typed. */
class FEV18 {
public:
    char pad0[0x18];
    virtual ~FEV18();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int s17();
    virtual void s18();
    virtual int s19();
    virtual int s20();
};

/* vptr at +0x3C, variant of FEV3C whose slots 85..91 have other signatures. */
class FEV3Cq {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85(int a, int b);
    virtual void s86(int a, int b);
    virtual void s87(int a, int b);
    virtual void s88(int a, int b, int c);
    virtual void s89(int a);
    virtual void s90(float* a, float* b, float* c, float* d);
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
};

/* object with just a vptr at +0 (subobject at +0xC of the AF248 objects) */
class FEV0b {
public:
    virtual void s1();
    virtual void s2();
};

/* 0x68-byte sub-object of the manager (at +0x38): vptr at +0x64 (lbl_8065CBD0),
 * ctor fn_800B85FC, dtor fn_800B8654, reset fn_800B86A0. */
struct FEColor {
    float m0;
    float m4;
    float m8;
    float mC;
};
/* Text-line table (fn_800B5E68): up to 0x2E4 element pointers, count at +0xB90, vptr at +0xB94. */
struct FEList {
    FEV64* m[0x2E4];
    int mB90;
    const void* mB94;
};
/* Element object, 0x68 bytes, vptr at +0x64 (ctor fn_800B622C, dtor fn_800B62FC): ints at
 * 0..0x30, a count at +0x34, two colors at +0x40 and +0x50. */
struct FEElem {
    unsigned short* m[13];
    int m34;
    int m38;
    int m3C;
    FEColor m40;
    FEColor m50;
    int m60;
    const void* m64;
};
extern const char lbl_806583A8[];
extern const char lbl_80658680[];
struct UiMsgBuf {
    char name[16];
};
struct FEObj68 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    char m1C;
    char pad1D[0x34 - 0x1D];
    int m34;
    int m38;
    int m3C;
    char m40;
    char pad41[0x48 - 0x41];
    int m48;
    char pad4C[0x58 - 0x4C];
    int m58;
    int m5C;
    int m60;
    const void* m64;
};

#endif
