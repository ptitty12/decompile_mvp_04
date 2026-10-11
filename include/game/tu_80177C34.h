#ifndef GAME_TU_80177C34_H
#define GAME_TU_80177C34_H

/*
 * Declarations for game/tu_80177C34.cpp (reconstructed; placeholders only).
 */

struct Unk80177C34_Rec {
    char pad0[0x108];
    int m108;
    char pad10C[0x1CD0 - 0x10C];
    int m1CD0;
};
struct Unk80177C34_Mid {
    char pad0[0x14];
    Unk80177C34_Rec* m14;
};
struct Unk80177C34_P564 {
    char pad0[0x14];
    int m14;
};
struct Unk80177C34_P744 {
    char pad0[0x20];
    int m20;
};
struct Unk80177C34_Ctx {
    char pad0[0x564];
    Unk80177C34_P564* m564;
    char pad568[0x6F8 - 0x568];
    Unk80177C34_Mid* m6F8;
    char pad6FC[0x744 - 0x6FC];
    Unk80177C34_P744* m744;
};
struct Unk801791DC_T {
    char pad0[0x84];
    int m84;
    int m88;
};
struct Unk80179284_T {
    char pad0[0x20];
    int m20[14];
};
struct Unk80179284_Ctx {
    char pad0[0x704];
    int m704;
    int m708;
};
struct Unk80179B90_T {
    int m0;
    int m4;
    int m8;
};

/* 0x94-byte entry; two of them at container+0xC */
struct Unk80177C34_Sub {
    int m0[8];
    int m20[25];
    int m84;
    Unk80177C34_Ctx* m88;
    int m8C;
    int m90;
};
struct Unk80178BBC_Entry {
    int m0;
    int m4;
    int m8;
};
struct Unk80178BBC_T {
    char pad0[8];
    Unk80177C34_Ctx* m8;
    Unk80177C34_Sub mC[2];
    Unk80178BBC_Entry m134[2];
    int m14C;
};
struct Unk80177C34_X {
    char pad0[0x40];
    void* m40;
};
void fn_80177900(void* self, void* a);
void fn_80179784(void* p);
void fn_8017946C(Unk80177C34_Sub* p);
void fn_801797A4(void* p);
void fn_80179BBC(void* p);
void fn_80179250(void* p);
void fn_80178D9C(unsigned* p);
int fn_8017995C(int* arr, int v);
int fn_80179990(int* arr, unsigned i);
int fn_80179284(Unk80179284_T* p, Unk80179284_Ctx* ctx);
void fn_80179648(void* p, void* o);
void fn_80179BE0(void* p, void* o);
void fn_80179CD0(void* p);
void fn_801799AC(void* p, int a, float f);
void fn_801794B8(void* p);
void fn_80179208(void* self);
void fn_80179250(void* self);
void fn_801792BC(void* self);
void fn_801794B8();
void fn_80179BBC(void* self);
void fn_80179BDC();

#endif
