/*
 * Game code, .text 0x801FE850-0x802028E4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801FA73C.h"

struct Unk80201738_Owner {
    char pad0[0x6CC];
    void* m6CC;
};

/* Roster of the nine player slots (G+0 in tu_801EE438.h terms): owner, a pointer copied from owner+0x6CC,
 * and nine slot words. Cleared by fn_80201738, refilled by fn_80201764. */
struct Unk80201738_Roster {
    Unk80201738_Owner* m0;
    void* m4;
    int m8[9];
};

struct Unk80201738_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern "C" {
void fn_8014E09C(Unk80201738_It* it, Unk80201738_Owner* o, int k);
void fn_8014E108(Unk80201738_It* it);
int fn_801A497C(Unk80201738_Owner* o, int a, int b);
}

extern float lbl_805D50F0;
extern float lbl_805D50F4;
extern float lbl_805D50F8;
extern float lbl_805D50FC;
extern float lbl_805D5100;
extern float lbl_805D5104;
extern float lbl_805D5108;
extern float lbl_805D510C;
extern float lbl_805D5110;
extern float lbl_805D5114;
extern float lbl_805D5118;
extern float lbl_805D511C;
extern float lbl_805D5120;
extern float lbl_805D5124;
extern float lbl_805D5128;
extern float lbl_805D512C;
extern float lbl_805D5130;
extern float lbl_805D5134;
extern float lbl_805D5138;
extern float lbl_805D513C;
extern float lbl_805D5140;
extern float lbl_805D5144;
extern float lbl_805D5148;
extern float lbl_805D514C;
extern float lbl_805D5150;
extern float lbl_805D5154;
extern float lbl_805D5158;
extern float lbl_805D515C;
extern float lbl_805D5160;
extern float lbl_805D5164;
extern float lbl_805D5168;
extern float lbl_805D516C;
extern float lbl_805D5170;
extern float lbl_805D5174;
extern float lbl_805D5178;
extern const float lbl_805D517C;
extern const float lbl_805D5180;

struct Unk802017E0_Game {
    char pad0[0x38C];
    int m38C;
};

struct Unk802017E0_G {
    char pad0[4];
    Unk802017E0_Game* m4;
};

struct Unk802017E0_Scr {
    char pad0[0x9C];
    Unk802017E0_G* m9C;
};

struct Unk802027B0_J {
    char pad0[0x3B4];
    void* m3B4;
};

struct Unk802027B0_Own {
    char pad0[0x4C];
    unsigned m4C;
    char pad50[0x554 - 0x50];
    void* m554;
    char pad558[0x700 - 0x558];
    Unk802027B0_J* m700;
};

struct Unk802027B0_G {
    Unk802027B0_Own* m0;
};

struct Unk802027B0_Scr {
    char pad0[0x9C];
    Unk802027B0_G* m9C;
};

struct Unk802027B0_P {
    char pad0[0x540];
    float m540;
};

extern const char lbl_805D51F8[];
extern const float lbl_805D5230;
extern const float lbl_805D5240;
extern const float lbl_805D5244;
extern const float lbl_805D5248;
extern const float lbl_805D524C;
extern const float lbl_805D5250;
extern "C" unsigned fn_8014D8AC(void* o, int max, const char* file, int line);
extern "C" float fn_80259A74(void* list, int id, int k);

struct Unk802017E0_Vec {
    float x;
    float y;
    float z;
};

extern "C" float fn_804028E4(float x); /* square root */

extern "C" {

void fn_801FE850(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 5);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50F0);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FE9CC(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50F4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FEB3C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50F8);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FECC0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50FC);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FEE30(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D5100);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 3);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FEFB4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D5104);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 3);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FF138(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5108);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80214F1C(p, 1, 2, lbl_805D5108);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FF2B0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D510C);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FF438(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D5110);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FF5C0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5114);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_802138AC(p, 3, 4, lbl_805D5118);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FF748(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D511C);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_802138AC(p, 3, 4, lbl_805D5120);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FF8D0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5124);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213B80(p, 1, 2, 3);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FFA48(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D5128);
    fn_8021D4A4(p);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 1, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FFBC8(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D512C);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 3);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FFD4C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 3);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5130);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5130);
    fn_80205450(p->m9C, 3);
    fn_80214F1C(p, 1, 2, lbl_805D5130);
    fn_80205450(p->m9C, 4);
    fn_80214F1C(p, 1, 2, lbl_805D5130);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5130);
    fn_801F8E40(&p->mA0);
}

void fn_801FFEE8(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 5);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5134);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5134);
    fn_80205450(p->m9C, 3);
    fn_80214F1C(p, 1, 2, lbl_805D5134);
    fn_80205450(p->m9C, 4);
    fn_80214F1C(p, 1, 2, lbl_805D5134);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5134);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_80200084(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 8);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 1);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5138);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 1, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_80213B80(p, 1, 2, 3);
    fn_80205450(p->m9C, 8);
    fn_80214C68(p, 3, 3);
    fn_801F8E40(&p->mA0);
}

void fn_80200200(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 8);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 1);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80213B80(p, 3, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80214F1C(p, 1, 2, lbl_805D513C);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 8);
    fn_80214C68(p, 3, 3);
    fn_801F8E40(&p->mA0);
}

void fn_8020036C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 8);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 1);
    fn_801F8530(&p->mA0, 2);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80213B80(p, 3, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213B80(p, 0, 2, 3);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214BE8(p, 3, 3);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 8);
    fn_80214C68(p, 3, 3);
    fn_801F8E40(&p->mA0);
}

void fn_802004D4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 8);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 4);
    fn_801F83F0(&p->mA0, 1);
    fn_801F8530(&p->mA0, 2);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5140);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80214F1C(p, 1, 2, lbl_805D5140);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_8020064C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 4);
    fn_80205450(p->m9C, 0);
    fn_8021A4A0(p, 1);
    fn_80214F1C(p, 1, 2, lbl_805D5144);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5144);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5144);
    fn_80205450(p->m9C, 1);
    fn_802195D4(p, 1);
    fn_80213DF4(p, 3);
    fn_801F8E40(&p->mA0);
}

void fn_802007C4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 4);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5148);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_80214BE8(p, 3, 3);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5148);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5148);
    fn_80205450(p->m9C, 1);
    fn_802195D4(p, 2);
    fn_80213DF4(p, 3);
    fn_801F8E40(&p->mA0);
}

void fn_80200938(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 4);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D514C);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_80214BE8(p, 3, 3);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D514C);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D514C);
    fn_801F8E40(&p->mA0);
}

void fn_80200AA0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5150);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5150);
    fn_80205450(p->m9C, 0);
    fn_802197A0(p, 1);
    fn_80214F1C(p, 1, 2, lbl_805D5150);
    fn_801F8E40(&p->mA0);
}

void fn_80200C0C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5154);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5154);
    fn_80205450(p->m9C, 0);
    fn_802197A0(p, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5154);
    fn_801F8E40(&p->mA0);
}

void fn_80200D80(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5158);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5158);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5158);
    fn_80205450(p->m9C, 0);
    fn_802197A0(p, 3);
    fn_80214F1C(p, 1, 2, lbl_805D5158);
    fn_801F8E40(&p->mA0);
}

void fn_80200F00(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 0x10);
    fn_80205450(p->m9C, 1);
    fn_80214CE8(p, 1, 0, 2, 3, lbl_805D515C);
    fn_80213E30(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213FAC(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213E30(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213FAC(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214F1C(p, 1, 2, lbl_805D5160);
    fn_80205450(p->m9C, 7);
    fn_80214F1C(p, 1, 2, lbl_805D5160);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 0);
    fn_802197A0(p, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5160);
    fn_801F8E40(&p->mA0);
}

void fn_8020106C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 0x10);
    fn_80205450(p->m9C, 1);
    fn_80214CE8(p, 1, 0, 2, 3, lbl_805D5164);
    fn_80213E30(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213E30(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214F1C(p, 1, 2, lbl_805D5168);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 8);
    fn_80214F1C(p, 1, 2, lbl_805D5168);
    fn_80205450(p->m9C, 0);
    fn_802197A0(p, 1);
    fn_80214F1C(p, 1, 2, lbl_805D5168);
    fn_801F8E40(&p->mA0);
}

void fn_802011D8(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 0x10);
    fn_80205450(p->m9C, 1);
    fn_80214CE8(p, 1, 0, 2, 3, lbl_805D516C);
    fn_80213E30(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213E30(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213FAC(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213FAC(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 7);
    fn_80214F1C(p, 1, 2, lbl_805D5170);
    fn_80205450(p->m9C, 8);
    fn_80214F1C(p, 1, 2, lbl_805D5170);
    fn_80205450(p->m9C, 0);
    fn_802197A0(p, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5170);
    fn_801F8E40(&p->mA0);
}

void fn_80201344(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 1);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80213B80(p, 3, 3, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 1, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 1, 1);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_80201488(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5174);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214BE8(p, 3, 3);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 8);
    fn_80214C68(p, 3, 3);
    fn_801F8E40(&p->mA0);
}

void fn_802015B4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 1);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5178);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213F10(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214BE8(p, 3, 3);
    fn_80205450(p->m9C, 7);
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 8);
    fn_80214C68(p, 3, 3);
    fn_801F8E40(&p->mA0);
}

void fn_802016F4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F8D34(&p->mA0);
}

void fn_80201738(Unk80201738_Roster* r)
{
    r->m4 = 0;
    for (int i = 0; i < 9; i++)
        r->m8[i] = 0;
}

void fn_80201764(Unk80201738_Roster* r)
{
    Unk80201738_It it;
    r->m4 = r->m0->m6CC;
    fn_8014E09C(&it, r->m0, 1);
    Unk80201738_It* ip = &it;
    while (ip->m8 != 10) {
        int i = ip->m8;
        *(int*)((char*)r + i * 4 + 8) = fn_801A497C(r->m0, 4, i);
        fn_8014E108(ip);
    }
}

int fn_802017E0(Unk802017E0_Scr* p, int, Unk802017E0_Vec* v)
{
    int r;
    if (p->m9C->m4->m38C == 1) {
        float len = fn_804028E4(v->x * v->x + v->y * v->y + v->z * v->z) * lbl_805D517C;
        float thr = lbl_805D5180;
        r = len >= lbl_805D5180;
    } else
        r = 0;
    return r;
}

inline float RandPct27B0(Unk802027B0_Own* o, const char* f, int line)
{
    float k = lbl_805D5230;
    return (float)fn_8014D8AC(o->m554, 1000000, f, line) * k * lbl_805D5240;
}

/* near-miss (14 slots): frame (p at 8, RandPct k at 0x10, q at 0x18) and arithmetic match; retail schedules the constant loads in a
   different order (5244 before 5240, k reload into f13) */
float fn_802027B0(Unk802027B0_Scr* s, Unk802027B0_P* pl)
{
    float p = RandPct27B0(s->m9C->m0, lbl_805D51F8, 0x1A7) + lbl_805D5244;
    p = p * (lbl_805D5248 - pl->m540);
    p = p + lbl_805D524C;
    float q = fn_80259A74(s->m9C->m0->m700->m3B4, 9, 0);
    q = q * p;
    return (float)s->m9C->m0->m4C * lbl_805D5250 + q;
}

}
