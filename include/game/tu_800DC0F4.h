#ifndef GAME_TU_800DC0F4_H
#define GAME_TU_800DC0F4_H

/*
 * Declarations for game/tu_800DC0F4.cpp (reconstructed; placeholders only).
 */

extern int lbl_8061977C;
extern int lbl_8061E978;
extern int lbl_805C2EB4[];
extern int lbl_805C2E84[];
extern int lbl_805C2EE4[];
extern const unsigned char lbl_805B6F58;
extern const unsigned short lbl_805BDADC;
extern const unsigned short lbl_805BDAE0;
extern const unsigned short lbl_805BDAE4;
extern const unsigned short lbl_805BDAE8;
struct Unk800DE930_T {
    int m[6];
};
extern Unk800DE930_T lbl_805BD9BC;
struct Unk800DD610_P {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
};
struct Unk800DEDC0_Row {
    int m0;
    int m4;
};
extern Unk800DEDC0_Row lbl_805BD894[];

void* fn_80090880(int obj, int id);
int fn_8032A130(int a, int b, int c);
int fn_803EB434(int h, void* s, float* a, float* b, float* c, float* d);
void fn_800DC3D8(int* a, int* b, int c);
int fn_800DB9A8(int a, int b, int c, int d);

#endif
