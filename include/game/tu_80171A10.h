#ifndef GAME_TU_80171A10_H
#define GAME_TU_80171A10_H

/*
 * Declarations for game/tu_80171A10.cpp (reconstructed; placeholders only).
 */

struct Unk8017227C_Pair {
    int m0;
    int m4;
};
struct Unk8017227C_T {
    char pad0[0x1C];
    Unk8017227C_Pair m1C[1];
};
struct Unk80173274_T {
    int m0;
    int m4;
};
struct Unk80174274_T {
    char pad0[0x3C];
    void* m3C;
};
void fn_80171A10(void* p, int a);

/* Pointer-to-member-function constant (delta, index, pfn). */
struct Unk80171A10_Fn {
    int m0;
    int m4;
};

/* Menu/popup object (vptr at +0x120): state, text buffers and the handler set by fn_80174318. */
struct Unk80171A10_Menu {
    int m0;
    int m4;
    int m8[4];
    int m18;
    char pad1C[0x3C - 0x1C];
    void* m3C;
    char pad40[0x54 - 0x40];
    int m54;
    int m58;
    char pad5C[4];
    int m60;
    int m64;
    int m68;
    void* m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    int m84;
    char m88[0xA4 - 0x88];
    unsigned short mA4[0x1B];
    unsigned short mDA[0x1D];
    int m114;
    int m118;
    int m11C;
};
void fn_80174318(Unk80171A10_Menu* p, int state, Unk80171A10_Fn f);
void fn_801743E0(Unk80171A10_Menu* p);
void fn_80174438(Unk80171A10_Menu* p);
void fn_801744AC(Unk80171A10_Menu* p);
char* fn_8040B61C(char* dst, const char* src);
void fn_80403144(unsigned short* dst, const unsigned short* src);
int fn_80403060(const unsigned short* s);


#endif
