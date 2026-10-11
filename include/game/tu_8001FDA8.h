/*
 * Types for game/tu_8001FDA8.cpp (reconstructed; nothing here comes from original
 * headers). Three attribute-style classes, named after their constructor addresses.
 *
 * Unk8001FE34 (ctor 0x8001FE34, size 0x1D4, vtable 0x80649AC8, hash 0x9A0B3B52) and
 * Unk8002118C (ctor 0x8002118C, size 0xBC, vtable 0x80649D10, hash 0x871AE7A9) derive from the
 * chooser root Unk8037B3E8 and register float fields in slot 2 through its
 * attribute helpers (fn_8037B7E8/fn_8037B830 group begin/end, fn_8037B50C float).
 * Unk80021A60 (ctor 0x80021A60, vtable 0x80649CB0 at +0xB8) is a separate class.
 */
#ifndef GAME_TU_8001FDA8_H
#define GAME_TU_8001FDA8_H

#include "game/chooser.h"
#include "game/tu_8001E444.h"

struct Unk8001C394_Obj {
    int fn_8001CC40(int n);
};
Unk8001C394_Obj* fn_8001C394();

struct Unk8004072C_Obj {
    char pad0[0x5D0];
    int m5D0;
};
Unk8004072C_Obj* fn_8004072C();
void fn_80042C78(Unk8004072C_Obj* o, int a);
void fn_800414FC(Unk8004072C_Obj* o, int a, int b);

extern const float lbl_805A5F98;
struct Unk800475EC_Obj {
    char pad0[0xAE0];
    float mAE0;
    float mAE4;
    float mAE8;
    float mAEC;
    /* Two-layer setters: a float passed through two inline layers takes two stack slots. */
    void SetAE0b(float w) { mAE0 = w; }
    void SetAE0(float v) { SetAE0b(v); }
    void SetAE4b(float w) { mAE4 = w; }
    void SetAE4(float v) { SetAE4b(v); }
    void SetAE8b(float w) { mAE8 = w; }
    void SetAE8(float v) { SetAE8b(v); }
    void SetAECb(float w) { mAEC = w * lbl_805A5F98; }
    void SetAEC(float v) { SetAECb(v); }
};
Unk800475EC_Obj* fn_800475EC();
void fn_800489B4(Unk800475EC_Obj* o, int a, int b);

struct Unk8005ACE4_Obj;
Unk8005ACE4_Obj* fn_8005ACE4();
void fn_8005B76C(Unk8005ACE4_Obj* o, int a);

void fn_80046E68(int a);
void fn_800431DC(int a);
int fn_80253E7C(void* p, int a, int b, int c);

extern float lbl_80616508[];
extern const char* lbl_80616524;
extern int lbl_805B09D4[];
extern int lbl_805AF5FC;
extern const float lbl_805A5AA0;
extern const float lbl_805A5AA4;
extern const float lbl_805A5AA8;
extern const float lbl_805A5AB8;
extern const float lbl_805A5ABC;
extern const float lbl_805A5F98;
extern const float lbl_805A5F9C;
extern const float lbl_805A5FA0;
extern const float lbl_805A5FA4;
extern const float lbl_805A5FA8;
extern const float lbl_805A5FAC;
extern const float lbl_805A5FB0;
extern const float lbl_805A5FB4;
extern const float lbl_805A5FB8;
extern const float lbl_805A5FBC;
struct Unk805AF370_Ent {
    int m0;
    int m4;
};
extern Unk805AF370_Ent lbl_805AF370[];

class Unk8001FE34 : public Unk8037B3E8 {
public:
    Unk8001FE34();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual ~Unk8001FE34();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot8();
    int fn_80020BCC();
    void fn_80020C5C();
    void fn_80020D58();
    void fn_80020DC8();
    void fn_80020E3C();
    void fn_80020ECC();
    void fn_80020F4C();
    void fn_80020FCC();
    int fn_80021010(int idx, float f);
    void fn_800210E4(float f, int idx);
    void fn_8002114C(int v);

    int m4;
    float m8[99];
    float m194[8];
    float m1B4[8];
};

class Unk8002118C : public Unk8037B3E8 {
public:
    Unk8002118C();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual ~Unk8002118C();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot8();
    Unk8002118C* fn_8002194C();

    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
    float m8C;
    float m90;
    float m94;
    float m98;
    float m9C;
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    float mB0;
    float mB4;
    float mB8;
};

/* Table entry, 12 bytes: key (-1 = free), then two ints (fn_80021BE8, fn_80023430, fn_80023490). */
struct Unk80021BE8_Ent {
    int m0;
    int m4;
    int m8;
};

/* Data part of Unk80021A60 (0x00..0xB8). The class that introduces the virtuals
 * comes after it, which puts its vptr at +0xB8. */
struct Unk80021A60_Data {
    Unk80021BE8_Ent e[10];
    int m78;
    int m7C;
    Unk8001F2C4_World* m80[3];
    Unk8002118C* m8C;
    float m90;
    float m94;
    float m98;
    float m9C;
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    float mB0;
    int mB4;
};

extern Unk8002118C* lbl_80686DC8;

/* Abstract base; vtable 0x80649CB0: dtor, seven pure virtuals, slot 9 (0x80067728), slot 10 (0x80021BE8). */
class Unk80021A60 : public Unk80021A60_Data {
public:
    Unk80021A60(int arg);
    virtual ~Unk80021A60();
    virtual void fn_vslot2() = 0;
    virtual void fn_vslot3() = 0;
    virtual void fn_vslot4() = 0;
    virtual void fn_vslot5() = 0;
    virtual void fn_vslot6() = 0;
    virtual void fn_vslot7() = 0;
    virtual void fn_vslot8() = 0;
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    int fn_800232A0(int kind, int v);
    int fn_800233B4(int a, int b, int c);
    int fn_80023430(int key, int unused, int* out);
    void fn_80023490(int key, int unused);
};

#endif
