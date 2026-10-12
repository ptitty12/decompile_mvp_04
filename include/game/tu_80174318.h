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
    int m8;
    void* mC;
    char pad10[0x44 - 0x10];
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
struct Unk80176ADC_Sub {
    char pad0[0x838];
    int m838;
};
struct Unk80176ADC_Obj {
    char pad0[0x264];
    int m264;
    char pad268[0x618 - 0x268];
    Unk80176ADC_Sub* m618;
};
void fn_801A656C(void* ctx, void* a, int b);
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
struct Unk8017757C_T;
void fn_8017757C(Unk8017757C_T* self, int a);
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
    Unk8016FF40();
    virtual ~Unk8016FF40();
    char pad4[0x108];
    Unk80174318_Pair* m108[4];
    char pad118[0x124 - 0x118];
};
struct Unk80174438_T {
    char pad0[8];
    Unk8016FF40* m8[4];
};
/* Menu object of tu_80171A10.h (Unk80171A10_Menu): four info records at +8, the pair table at +0x1C,
 * a flag at +0x5C and a name buffer at +0x88. */
struct Unk80174348_T {
    char pad0[8];
    Unk8016FF40* m8[4];
    int m18;
    Unk80174318_Pair m1C[4];
    char pad3C[0x5C - 0x3C];
    int m5C;
    char pad60[0x88 - 0x60];
    char m88[1];
};
void* operator new(unsigned int size, int heap);              /* 0x80377428 */
extern "C" void fn_8017008C(Unk8016FF40* info, const char* name);
void fn_80174438(Unk80174438_T* p);
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

/* Player object (vptr at +0x98): only slot 8 is used here. */
class Unk80177974_Obj {
public:
    char pad0[0x98];
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
};
struct Unk80177974_T {
    char pad0[0x40];
    Unk80177974_Obj* m40;
    Unk80177974_Obj* m44;
};
struct Unk80177900_Obj {
    char pad0[0x618];
    void* m618;
    char pad61C[0x8F0 - 0x61C];
    int m8F0;
    char pad8F4[0x908 - 0x8F4];
    int m908;
};
struct Unk8017706C_T {
    char pad0[0x18];
    int m18;
    char pad1C[0x60 - 0x1C];
    int m60;
    char pad64[0xA8 - 0x64];
    int mA8;
    char padAC[0xF0 - 0xAC];
    int mF0;
};
void fn_80244A64(void* p, int a, int b);
void fn_8037EBE8(void* p);
void fn_803814A4(void* p, int a, int b, float f);
void fn_8024D178(void* p, int a);
void fn_80189300(void* p, int a);
extern const float lbl_805CBD24;
void fn_80177C74(void* self, int a);
void fn_80177BF4(Unk80177B74_T* p, void* a);

struct Unk80177A90_V3 {
    int m0;
    int m4;
    int m8;
};
struct Unk80177A90_T {
    char pad0[0x10];
    Unk80177A90_V3 m10;
    Unk80177A90_V3 m1C;
    Unk80177A90_V3 m28;
    Unk80177A90_V3 m34;
};
extern const Unk80177A90_V3 lbl_806055AC;
extern const char lbl_805CB1DC[];
extern const char lbl_805CB208[];
int fn_802B9300(int n, int a, int b, int c);
int fn_80402DE4(int a, int b);
void fn_80402BEC(int a, int b, int c);
int fn_804089B4(char* dst, const char* fmt, ...);
void fn_8040074C(void* p, unsigned int n);
int fn_80359BAC();
int fn_80359C58();
int fn_80359E94();
void fn_803EE8F8(void* cfg);
void fn_80174824(int a);
int fn_801747AC(const char* name);

#endif
