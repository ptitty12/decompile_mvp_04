#ifndef GAME_TU_802F42A4_H
#define GAME_TU_802F42A4_H

/*
 * Declarations for game/tu_802F42A4.cpp (reconstructed, placeholder names).
 * A game object class (base constructor 0x803282A8, base destructor 0x80328374,
 * vtable lbl_80665050 stored at +0x18 right after the base data) with a
 * sub-object at +0xCC (constructor 0x802FD088, destructor 0x802FD0C4).
 */

/* Base: 0x18 bytes of data, then its vptr. */
class Unk803282A8 {
public:
    char pad0[0x18];
    Unk803282A8();
    virtual ~Unk803282A8();
};

class Unk802FD088 {
public:
    char pad0[0xC];
    Unk802FD088();
    ~Unk802FD088();
};

struct Unk802F4F40_V3 {
    int m0;
    int m4;
    int m8;
};
struct Unk802F44D0_V3 {
    float x;
    float y;
    float z;
};
struct Unk802F44D0_Own {
    char pad0[0x3BC];
    struct Unk802F44D0_Lim* m3BC;
};
struct Unk802F44D0_Lim {
    char pad0[0x28];
    float m28;
    float m2C;
    float m30;
    float m34;
};
/* Record at +0x6CC of the object at +0x64 (fn_802F4F40). */
struct Unk802F4F40_P {
    char pad0[0x38C];
    int m38C;
    char pad390[0x3C0 - 0x390];
    Unk802F4F40_V3 m3C0;
    char pad3CC[0x3F4 - 0x3CC];
    float m3F4;
    char pad3F8[0x420 - 0x3F8];
    Unk802F44D0_V3 m420;
    char pad42C[0x438 - 0x42C];
    float m438;
    float m43C;
    float m440;
    float m444;
};
struct Unk802F4F40_Q {
    char pad0[0x6CC];
    Unk802F4F40_P* m6CC;
    char pad6D0[0x700 - 0x6D0];
    Unk802F44D0_Own* m700;
};
float fn_80190F0C(Unk802F4F40_P* p);
int fn_80328648(Unk802F4F40_Q* q);
void fn_802FD0F8(Unk802FD088* m);
extern Unk802F4F40_V3 lbl_806055AC;

class Unk802F42A4 : public Unk803282A8 {
public:
    char pad1C[0x24 - 0x1C];
    int m24;
    int m28;
    int m2C;
    Unk802F44D0_V3 m30;
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
    Unk802F4F40_Q* m64;
    int m68;
    int m6C;
    int m70;
    float m74;
    int m78;
    float m7C;
    int m80;
    Unk802F4F40_V3 m84;
    int m90;
    Unk802F4F40_V3 m94;
    int mA0;
    int mA4;
    int mA8;
    float mAC;
    int mB0;
    float mB4;
    float mB8;
    float mBC;
    int mC0;
    int mC4;
    int mC8;
    Unk802FD088 mCC;
    int mD8;
    int mDC;
    int mE0;
    int mE4;
    float mE8;
    float mEC;
    int mF0;
    Unk802F42A4(Unk802F4F40_Q* a);
    virtual ~Unk802F42A4();
    void fn_802F4368();
    void fn_802F4F40();
    void fn_802F4628();
    void fn_802F44D0();
};

/* Object with the two extents at +0x3C/+0x40 read by fn_802F7EE8 / fn_802F7F04. */
struct Unk802F7EE8_S {
    char pad0[0x3C];
    float m3C;
    float m40;
};
/* 16-byte result of fn_802B0ACC, kept in the table at lbl_806E0E00. */
struct Unk802F4628_Q {
    float m0;
    float m4;
    float m8;
    float mC;
};
Unk802F4628_Q fn_802B0ACC(int a, int b);
int fn_802B0850(int a, int b, int c);
extern int lbl_8061E978;
extern int lbl_8061F804[];
extern int lbl_806E0DD8[];
extern Unk802F4628_Q lbl_806E0E00[];
extern float lbl_8061CBC4;
extern float lbl_8061F6EC;

#endif
