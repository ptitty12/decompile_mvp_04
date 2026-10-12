/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x8037B3AC-0x8037C764 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "game/chooser.h"

extern "C" {
void fn_8037B76C(Unk8037B3E8* self, int kind, int a, int b, int c, int d, int e, int f);
void fn_8037BCC0(const char* name, const char* group);
void fn_8037BD34(const char* name, const char* group);
void* fn_803774A8(unsigned size, int heap);
}

extern char lbl_806849A0[];

struct Unk802BA828 {
    Unk802BA828(int a);
    float m0;
    float m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    float m1C;
    float m20;
    int m24;
    float m28;
    float m2C;
    int m30;
};

extern Unk802BA828* lbl_80624254;

/* Attribute registration wrappers of the chooser root class (Unk8037B3E8):
 * each forwards to fn_8037B76C with the attribute kind as the second argument. */
extern "C" void fn_8037B458(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 4, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B494(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 1, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B4D0(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 2, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B50C(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 5, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B548(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 0, 0, p1, 0, 0, p2, 0);
}

extern "C" void fn_8037B584(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 6, 0, p1, p2, p4, 0, p3);
}

extern "C" void fn_8037B5C0(Unk8037B3E8* self, int p1, int p2, int p3)
{
    fn_8037B76C(self, 11, 0, p1, p2, p3, 0, 0);
}

extern "C" void fn_8037B5FC(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 7, 0, p1, p2, 0, 0, 0);
}

extern "C" void fn_8037B638(Unk8037B3E8* self, int p1, int p2, int p3)
{
    fn_8037B76C(self, 8, 0, p1, p2, p3, 0, 0);
}

extern "C" void fn_8037B674(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 13, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B6B0(Unk8037B3E8* self, int p1, int p2, int p3)
{
    fn_8037B76C(self, 10, 0, p1, p2, p3, 0, 0);
}

extern "C" void fn_8037B6EC(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 14, 0, p1, p2, 0, 0, 0);
}

extern "C" void fn_8037B728__11Unk8037B3E8PCcT1Pvi(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 12, p1, p2, p3, p4, 0, 0);
}

extern "C" void fn_8037B7E4() {}

extern "C" void fn_8037B7E8(Unk8037B3E8* self, const char* group)
{
    fn_8037BCC0(self->fn_vslot3(), group);
}

extern "C" void fn_8037B830(Unk8037B3E8* self, const char* group)
{
    fn_8037BD34(self->fn_vslot3(), group);
}

extern "C" void fn_8037B878(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 18, 0, p1, p2, 0, 0, 0);
}

extern "C" void fn_8037B8B4(int n)
{
    lbl_80624254 = (Unk802BA828*)fn_803774A8(n * 0x44, 0);
}

extern "C" void fn_8037B8EC()
{
    if (lbl_80624254 != 0) {
        delete[] lbl_80624254;
        lbl_80624254 = 0;
    }
}

extern Unk8037B3E8* lbl_806E9684[];
extern int lbl_80624250;

extern "C" void fn_8037BF88()
{
    for (int i = 0; i < lbl_80624250; i++)
        lbl_806E9684[i] = 0;
}

extern "C" int fn_8037C544(int key)
{
    for (int i = 0; i < lbl_80624250; i++) {
        Unk8037B3E8* o = lbl_806E9684[i];
        if (o != 0 && key == o->fn_vslot4())
            return i;
    }
    return -1;
}

struct Unk8037C704 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[8];
    int m18;
    const void* m1C;
    Unk8037C704();
};

Unk8037C704::Unk8037C704()
{
    m1C = lbl_806849A0;
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mC = 0;
    m18 = 0;
}

struct DtorAt1C { char pad[0x1c]; const void* m; };


extern "C" void fn_80377408(void* p);

extern "C" void fn_8037C730(DtorAt1C* self, int chrg)
{
    self->m = lbl_806849A0;
    if (chrg & 1)
        fn_80377408(self);
}
