/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80383E00-0x80387E28 (code-only unit, 44 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "game/tu_802CFED4.h"

/* The object fn_80384A88 builds: 0x40 bytes, ctor at 0x80384858. */
class Unk80384858 {
public:
    Unk80384858();
    char data[0x40];
};

extern "C" Unk80384858* fn_80384A88()
{
    return new (lbl_806EF9B4) Unk80384858;
}

struct Unk80384B3C {
    char pad0[4];
    int m4;
    int m8;
    struct Unk80384B3C_Inner* mC;
    char pad10[0x38 - 0x10];
    int m38;
};

struct Unk80384B3C_Inner {
    char pad0[4];
    int m4;
};

extern "C" {
void fn_80384F74(char* a, char* b);
void* fn_80384C88(int a, int b, void* c, int d, const void* e, int f);
void fn_8037B5FC(void* self, const char* name, int* field);
void* fn_803853F8(void* p);
}
extern const char lbl_80605D34[];
extern int lbl_806242C0;
extern const char lbl_80605BF0[];
extern int lbl_806EF9B4;

extern "C" void fn_80384B3C(Unk80384B3C* o, int v)
{
    o->m38 = v;
}

extern "C" void fn_80384B44(char* a, char* b)
{
    fn_80384F74(b + 0x18, a + 0x18);
}

extern "C" void fn_803850D0(Unk80384B3C* o, int a, int b)
{
    o->m4 = (int)fn_80384C88(a, b, &o->mC, 1, lbl_80605D34, lbl_806242C0);
}

extern "C" int fn_803852E4(Unk80384B3C* o)
{
    if (o->mC == 0)
        return 0;
    return o->mC->m4;
}

extern "C" void fn_80385444(Unk80384B3C* o)
{
    fn_8037B5FC(o, lbl_80605BF0, &o->m8);
}

extern "C" void* fn_80385620()
{
    return fn_803853F8(operator new(0xC, lbl_806EF9B4));
}

extern "C" void fn_80385674() {}

extern "C" void fn_80387D3C()
{
    for (int i = 0; i < 15; i++) {
    }
    for (int i = 0; i < 15; i++) {
    }
}
