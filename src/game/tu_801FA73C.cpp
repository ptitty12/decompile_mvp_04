/*
 * Game code, .text 0x801FA73C-0x801FE850 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801FA73C.h"

struct Unk801FAFD0_Rec {           /* stride 0x5C, G+0x6B8 */
    char pad0[0x50];
    float m50;
    char pad54[0x5C - 0x54];
};

struct Unk801FAFD0_G {
    void* m0;                      /* owner */
    char pad4[0x6B8 - 4];
    Unk801FAFD0_Rec m6B8[10];
    char padA50[0x3A64 - 0xA50];
    int m3A64;
};

struct Unk801FAFD0_Scr {
    Unk801FAFD0_G* m0;
};

struct Unk801FAFD0_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern const float lbl_805D5068;

extern "C" {
void fn_8014E09C(Unk801FAFD0_It* it, void* owner, int k);
void fn_8014E108(Unk801FAFD0_It* it);
void fn_80212A28(int g, int a, int b, int c, int d, float f);
}

extern float lbl_805D506C;
extern float lbl_805D5070;
extern float lbl_805D5074;
extern float lbl_805D5078;
extern float lbl_805D507C;
extern float lbl_805D5080;
extern float lbl_805D5084;
extern float lbl_805D5088;
extern float lbl_805D508C;
extern float lbl_805D5090;
extern float lbl_805D5094;
extern float lbl_805D5098;
extern float lbl_805D509C;
extern float lbl_805D50A0;
extern float lbl_805D50A4;
extern float lbl_805D50A8;
extern float lbl_805D50AC;
extern float lbl_805D50B0;
extern float lbl_805D50B4;
extern float lbl_805D50B8;
extern float lbl_805D50BC;
extern float lbl_805D50C0;
extern float lbl_805D50C4;
extern float lbl_805D50C8;
extern float lbl_805D50CC;
extern float lbl_805D50D0;
extern float lbl_805D50D4;
extern float lbl_805D50D8;
extern float lbl_805D50DC;
extern float lbl_805D50E0;
extern float lbl_805D50E4;
extern float lbl_805D50E8;
extern float lbl_805D50EC;

extern "C" {

void fn_801FAFD0(Unk801FAFD0_Scr* p)
{
    Unk801FAFD0_It it;
    fn_8014E09C(&it, p->m0->m0, 1);
    Unk801FAFD0_It* ip = &it;
    while (ip->m8 != 10) {
                Unk801FAFD0_Rec* e = &p->m0->m6B8[ip->m8];
        if (!(e->m50 <= lbl_805D5068)) {
            fn_80205450((Unk801FA73C_List*)p->m0, ip->m8);
            fn_80212A28(p->m0->m3A64, 1, 0, 2, 3, e->m50);
        }
        e->m50 = lbl_805D5068;
        fn_8014E108(ip);
    }
}

void fn_801FB084(Unk801FA73C_Scr* p)
{
}

void fn_801FB088(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 8);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80219B8C(p, 0);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FB20C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_802124B8(p);
    fn_80205450(p->m9C, 1);
    fn_80219328(p);
    fn_80205450(p->m9C, 2);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_80205450(p->m9C, 3);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_80205450(p->m9C, 4);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_80205450(p->m9C, 5);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D506C);
    fn_801F8E40(&p->mA0);
}

void fn_801FB3C4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5070);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_8021458C(p, 1, -1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FB538(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D5074);
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
    fn_8021458C(p, 1, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FB6B4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D5078);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_8021458C(p, 2, -1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FB83C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D507C);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_8021458C(p, 3, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FB9B8(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 1);
    fn_801F86B0(&p->mA0, 4);
    fn_801F86B0(&p->mA0, 1);
    fn_801F86B0(&p->mA0, 6);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 3);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 4);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 5);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 6);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 7);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_80205450(p->m9C, 8);
    fn_80214F1C(p, 1, 2, lbl_805D5080);
    fn_801F8E40(&p->mA0);
}

void fn_801FBB48(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5084);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80214040(p);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80214040(p);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FBCC8(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D5088);
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
    fn_8021458C(p, 2, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FBE68(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D508C);
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
    fn_8021458C(p, 2, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FC008(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 8);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D5090);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_8021458C(p, 3, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FC19C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D5094);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_8021458C(p, 1, 1);
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

void fn_801FC310(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D5098);
    fn_8021D4A4(p);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_8021458C(p, 1, 1);
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

void fn_801FC48C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D509C);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_8021458C(p, 1, 1);
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

void fn_801FC614(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D50A0);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_8021458C(p, 1, 1);
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

void fn_801FC79C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80213B80(p, 0, 2, 3);
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
    fn_80214B10(p, 2, 2);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FC910(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 2);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80213B80(p, 0, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_8021458C(p, 3, 1);
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

void fn_801FCA80(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 1);
    fn_801F86B0(&p->mA0, 2);
    fn_801F86B0(&p->mA0, 1);
    fn_801F86B0(&p->mA0, 8);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 3);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 4);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 5);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 6);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 7);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_80205450(p->m9C, 8);
    fn_80214F1C(p, 1, 2, lbl_805D50A4);
    fn_801F8E40(&p->mA0);
}

void fn_801FCC10(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50A8);
    fn_80213B80(p, 2, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FCD7C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50AC);
    fn_80213B80(p, 2, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 3);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FCEF4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50B0);
    fn_80213B80(p, 3, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FD078(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50B4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FD1F4(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 4);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50B8);
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
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FD384(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 3);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50BC);
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
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FD508(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50C0);
    fn_80213B80(p, 2, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FD674(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50C4);
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
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

void fn_801FD7E0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 1);
    fn_801F86B0(&p->mA0, 4);
    fn_801F86B0(&p->mA0, 6);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50C8);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50C8);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50C8);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50C8);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50C8);
    fn_801F8E40(&p->mA0);
}

void fn_801FD984(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50CC);
    fn_80213B80(p, 2, 2, 2);
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

void fn_801FDAF0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D50D0);
    fn_80213B80(p, 3, 2, 2);
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

void fn_801FDC68(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 3, lbl_805D50D4);
    fn_80213B80(p, 2, 2, 2);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 6);
    fn_80214BE8(p, 3, 3);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_8021354C(p, 3, 4);
    fn_801F8E40(&p->mA0);
}

void fn_801FDDE0(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 3);
    fn_801F803C(&p->mA0, 8);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 2);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D50D8);
    fn_80213B80(p, 3, 2, 2);
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

void fn_801FDF58(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F7FC4(&p->mA0, 1);
    fn_801F86B0(&p->mA0, 2);
    fn_801F86B0(&p->mA0, 8);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50DC);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80214F1C(p, 1, 2, lbl_805D50DC);
    fn_80205450(p->m9C, 5);
    fn_80213B80(p, 1, 2, 3);
    fn_80205450(p->m9C, 6);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50DC);
    fn_80205450(p->m9C, 7);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50DC);
    fn_80205450(p->m9C, 8);
    fn_8021B6EC(p, 2, 2);
    fn_80214F1C(p, 1, 2, lbl_805D50DC);
    fn_801F8E40(&p->mA0);
}

void fn_801FE0FC(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50E0);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FE26C(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 1, 2, lbl_805D50E4);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80213DF4(p, 0);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FE3DC(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D50E8);
    fn_80213B80(p, 2, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 1);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FE560(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 4);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 1, 1);
    fn_801F8E40(&p->mA0);
}

void fn_801FE6CC(Unk801FA73C_Scr* p)
{
    fn_801F7F64(&p->mA0);
    fn_801F803C(&p->mA0, 5);
    fn_801F803C(&p->mA0, 6);
    fn_801F803C(&p->mA0, 7);
    fn_801F803C(&p->mA0, 0);
    fn_801F803C(&p->mA0, 3);
    fn_801F8D34(&p->mA0);
    fn_80205450(p->m9C, 0);
    fn_80214F1C(p, 2, 2, lbl_805D50EC);
    fn_80213B80(p, 3, 2, 3);
    fn_80205450(p->m9C, 1);
    fn_80213DF4(p, 3);
    fn_80205450(p->m9C, 2);
    fn_80214620(p, 3);
    fn_80205450(p->m9C, 3);
    fn_80213DF4(p, 1);
    fn_80205450(p->m9C, 4);
    fn_80213DF4(p, 2);
    fn_80205450(p->m9C, 5);
    fn_80219B8C(p, 2);
    fn_80205450(p->m9C, 6);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 7);
    fn_8021354C(p, 3, 4);
    fn_80205450(p->m9C, 8);
    fn_80214B10(p, 2, 2);
    fn_801F8E40(&p->mA0);
}

}
