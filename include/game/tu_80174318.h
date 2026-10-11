#ifndef GAME_TU_80174318_H
#define GAME_TU_80174318_H

/*
 * Declarations for game/tu_80174318.cpp (reconstructed; placeholders only).
 */

/* Pointer-to-member-function constant (g++ 2.95: delta, index, pfn). */
struct Unk80174318_Fn {
    int m0;
    int m4;
};

struct Unk80174318_Pair {
    int m0;
    int m4;
};

/* Menu/popup object: state at +0x7C, current handler PTMF at +0x80, previous
 * at +0x74; four {int, int} pairs at +0x1C. */
struct Unk80174318_T {
    char pad0[0x1C];
    Unk80174318_Pair m1C[4];
    char pad3C[0x74 - 0x3C];
    Unk80174318_Fn m74;
    int m7C;
    Unk80174318_Fn m80;
};
struct Unk801757D4_T {
    char padC0[0xC0];
    int mC0;
};

void fn_80402CAC(int a, int b);

/* 0x48-byte entry; five of them at container+0xC */
struct Unk80176C0C_Entry {
    int m0;
    int m4;
    char pad8[0x44 - 8];
    int m44;
};
struct Unk80176C0C_Rec {
    char pad0[0x1CC8];
    unsigned char m1CC8;
    char pad1CC9[7];
    int m1CD0;
};
struct Unk80176C0C_Mid {
    char pad0[0x14];
    Unk80176C0C_Rec* m14;
};
struct Unk80176C0C_Pair {
    int m0;
    int m4;
};
struct Unk80176C0C_Ctx {
    char pad0[0x65C];
    Unk80176C0C_Pair m65C;
    char pad664[0x6F8 - 0x664];
    Unk80176C0C_Mid* m6F8;
};
struct Unk80176C0C_T {
    char pad0[8];
    Unk80176C0C_Ctx* m8;
    Unk80176C0C_Entry mC[5];
    char pad174_[0x174 - (0xC + 5 * 0x48)];
    int m174;
};
int fn_801A7020(void* p);
int fn_8006BE18(void* a);
int fn_801A2400(void* p);
void fn_80177A48(void* p, int a, int b, int c);
void fn_80177A90(void* p);
void fn_8017739C(Unk80176C0C_Entry* p, int a);
void fn_8017772C(void* p);
void fn_801769A8(void* p, int a);
void fn_80178720(void* p);
void fn_80178944(void* p);
void fn_8017493C(int a, int b);
void fn_80175810(int a, int b);
void fn_80176C0C(void* self);
void fn_8017696C(void* self);
void fn_80177B40(void* self);
extern int lbl_8061B9C8;
void fn_80177974(void* self);
void fn_80177A0C(void* self);
void fn_80177C34(void* self, void* b);
void fn_80177C74(void* self, int a);
void fn_80177900(void* self, void* a);
void fn_8017757C(void* self, int a);
void fn_801773E4(void* self);
struct Unk80177B74_T {
    char pad0[0xC];
    void* mC;
    char pad10[0x40 - 0x10];
    int m40;
};
void fn_80177BCC(void* self, void* a);
void fn_80177B74(Unk80177B74_T* p, void* a, int c);
void fn_80177BF4(Unk80177B74_T* p, void* a);

/* Record with a virtual destructor (vptr at +0x124, see tu_8016F9A8.h), deleted through the
 * in_chrg 3 call. */
class Unk8016FF40 {
public:
    virtual ~Unk8016FF40();
    char pad4[0x124];
};
struct Unk80174438_T {
    char pad0[8];
    Unk8016FF40* m8[4];
};
/* State machine base (vptr at +0xD4, see tu_80170044.h): only slot 8 is used here. */
class Unk80170518 {
public:
    char pad0[0xD4];
    virtual void fn_80005B88(void* a);
    virtual int fn_8000850C(int a);
    virtual int fn_80005B74(int a);
    virtual int fn_801757C8();
    virtual void fn_80005A7C(void* a);
    virtual int fn_80005E8C();
    virtual void fn_80005A50();
    virtual void fn_80005F4C(int a, int b, int c);
};
class Unk801748D8_Obj {
public:
    virtual void vslot1();
    virtual void vslot2();
};
struct Unk80173274_T;
int fn_80173274(Unk80173274_T* p);
int fn_8000587C(int p);
void fn_803EDA0C(int a);

#endif
