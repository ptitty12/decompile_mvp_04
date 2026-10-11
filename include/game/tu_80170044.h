#ifndef GAME_TU_80170044_H
#define GAME_TU_80170044_H

/*
 * Declarations for game/tu_80170044.cpp (reconstructed; placeholders only).
 * Methods of the record class built at 0x8016FF40 (include/game/tu_8016F9A8.h,
 * tu_800057D8 calls it Unk80170034_Info), the message state machine base
 * (ctor 0x80170518, vtable 0x8065EDF8) and the dialog text class (vptr 0x5E0).
 */
#include "game/tu_8016F9A8.h"

extern "C" {
char* fn_8040B61C(char* dst, const char* src);             /* behaves like strcpy */
int fn_8040B574(const char* a, const char* b);             /* behaves like strcmp */
int fn_8040B100(const void* a, const void* b, unsigned n); /* behaves like memcmp */
void fn_8040316C(unsigned short* dst, const unsigned short* src, int n);
int fn_80400560(int p, int n);
void fn_80359B78(void* obj, int n);
void fn_804007FC(void* p);
void fn_8035A09C(void* p, int n);
void fn_803FFEB8(void* p);
}

/* Service object at base+0x64: only the slot used here is named (slot 22,
 * the vtable entry at +0xB0); see Unk80005B88_Svc in tu_800057D8.h. */
class Unk80170518_Svc {
public:
    virtual void vslot1();
    virtual void vslot2();
    virtual void vslot3();
    virtual void vslot4();
    virtual void vslot5();
    virtual void vslot6();
    virtual void vslot7();
    virtual void vslot8();
    virtual void vslot9();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22(int a, int b);
};

struct Unk80170518_Slot {
    short m0;
    short m2;
    int m4;
};
class Unk80170518;
typedef void (Unk80170518::*Unk80170518_Fn)();

/*
 * Message state machine base (ctor 0x80170518, dtor 0x8017061C, vtable
 * 0x8065EDF8); tu_800057D8.h has the fuller picture. The first 0x28 bytes are a
 * queue of five pointers to member functions (8 bytes each: delta, index,
 * pfn; an empty slot has index 0). Data 0x00..0xD4, vptr at 0xD4.
 */
class Unk80170518 {
public:
    Unk80170518(int mode);
    virtual void fn_80005B88(Unk8016FF40* info);
    virtual int fn_8000850C(int a);
    virtual int fn_80005B74(int a);
    virtual int fn_801757C8();
    virtual void fn_80005A7C(Unk8016FF40* info);
    virtual int fn_80005E8C();
    virtual void fn_80005A50();
    virtual void fn_80005F4C(int a, int b, int c);
    virtual int fn_80170B3C();
    virtual void fn_80005C8C();
    virtual void fn_80005E38();
    virtual void fn_80006B60();
    virtual void fn_80006E94();
    virtual void fn_800069B4();
    virtual void fn_800060B4();
    virtual void fn_8000643C();
    virtual void fn_800065B4();
    virtual ~Unk80170518();
    virtual void fn_80005AB0(Unk8016FF40* info);

    void fn_80170668(Unk8016FF40* info, int state);
    void fn_80170780(int a, int b, const void* name, int c);
    void fn_801707F0();
    int fn_801708C0();
    int fn_8017095C(Unk80170518_Fn f);
    Unk80170518_Fn fn_801709A8();
    void fn_801709F8();
    void fn_80170A54(int a);

    Unk80170518_Fn m0[5];
    int m28;
    int m2C;
    int m30;
    int m34;
    Unk8016FF40* m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int* m4C;
    char m50[0x10];
    int m60;
    Unk80170518_Svc* m64;
    unsigned short m68[0x1C];
    int mA0;
    int mA4[4];
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    int mCC;
    int mD0;
};

extern "C" {
int fn_80170A1C(Unk80170518* self);
int fn_80090880(int a, int b);
void fn_80402FCC(char* dst, const void* src);
void fn_80403144(unsigned short* dst, const unsigned short* src);
int fn_80403060(const unsigned short* s);
}

#endif
