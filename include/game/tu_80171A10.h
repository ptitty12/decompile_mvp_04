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

struct Unk80171A10_Menu;
typedef void (Unk80171A10_Menu::*Unk80171A10_PFn)();

/* Menu/popup object (vptr at +0x120): state, text buffers and the handler set by fn_80174318. */
struct Unk80171A10_Menu {
    int m0;
    int m4;
    int m8[4];
    int m18;
    char pad1C[0x3C - 0x1C];
    void* m3C;
    int m40;
    int m44;
    int m48;
    char pad4C[0x54 - 0x4C];
    int m54;
    int m58;
    char pad5C[4];
    int m60;
    int m64;
    int m68;
    void* m6C;
    int m70;
    Unk80171A10_PFn m74;
    int m7C;
    Unk80171A10_PFn m80;
    char m88[0xA4 - 0x88];
    unsigned short mA4[0x1B];
    unsigned short mDA[0x1B];
    int m110;
    int m114;
    int m118;
    int m11C;
};
struct Unk80171A10_Svc {
    char padC4[0xC4];
    int mC4;
};
int fn_80173274(Unk80173274_T* p);
void fn_80172D00(Unk80171A10_Menu* p);
int fn_80172D44(Unk80171A10_Menu* p, int a);
void fn_801728A0(Unk80171A10_Menu* p, int a, int b);
void fn_80174438(Unk80171A10_Menu* p);
extern "C" int fn_80090880(int a, int b);
extern int lbl_8061977C;
void fn_80172B60(Unk80171A10_Menu* p, int a, int b);
void fn_80174318(Unk80171A10_Menu* p, int state, Unk80171A10_Fn f);
void fn_801743E0(Unk80171A10_Menu* p);
void fn_80174438(Unk80171A10_Menu* p);
void fn_801744AC(Unk80171A10_Menu* p);
extern "C" {
char* fn_8040B61C(char* dst, const char* src);
void fn_80403144(unsigned short* dst, const unsigned short* src);
int fn_80403060(const unsigned short* s);
}


#endif
