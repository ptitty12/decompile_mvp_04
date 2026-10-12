/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80382BB8-0x80383E00 (code-only unit, 42 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern "C" FxK* fn_80383C9C(FxK* self);

struct Unk80382BB8 {
    char pad0[0x1A8];
    int m1A8;
    char pad1AC[8];
    int m1B4;
    char pad1B8[0x830 - 0x1B8];
    int m830;
    char pad834[0x888 - 0x834];
    float m888;
};

struct Unk80383394 {
    int m0;
    int m4;
    int m8;
};

struct Unk803833B4 {
    int key;
    int v[2];
};

struct Unk80383C78 {
    char padC[0xC];
    float mC;
    float m10;
    int m14;
    int m18;
};

struct Unk80383DC0 {
    char pad0[0x1C];
    unsigned m1C;
};

extern "C" {
void* fn_80383548(void* p);
void* fn_803837F8(void* p);
void* fn_80383B24(void* p);
void fn_803836DC(void* p);
void fn_80383928(void* p);
}

extern "C" float fn_80382BB8(Unk80382BB8* o)
{
    return o->m888;
}

extern "C" void fn_80382BC0(Unk80382BB8* o, float f)
{
    o->m888 = f;
}

extern "C" int fn_80382C8C(Unk80382BB8* o)
{
    return o->m1A8;
}

extern "C" int fn_80382C94(Unk80382BB8* o)
{
    int n = o->m1A8;
    int* e = (int*)((char*)o + 0x1AC);
    for (int i = 0; i < n; i++) {
        if (e[2] != 0)
            return 1;
    }
    return 0;
}

extern "C" void fn_80382D60(Unk80382BB8* o, int v)
{
    if (v != 0)
        o->m830 = v;
}

/* near-miss: retail copies the pointer to r11 (end pointer kept as an int, cmpw); 7 vs 8 insns */
extern "C" void fn_80383394(Unk80383394* buf)
{
    Unk80383394* last = buf;
    for (Unk80383394* p = buf; p <= last; p++)
        p->m0 = 0;
}

extern "C" int fn_803833B4(Unk803833B4* t, int key, int idx)
{
    int off = 0;
    for (int i = 0; i <= 0; i++) {
        if (*(int*)(off + (int)t) == key) {
            int o = idx * 4;
            char* b = (char*)t + 4;
            return *(int*)(b + (o + off));
        }
        off += 12;
    }
    return 0;
}

extern "C" void fn_803834AC(Unk803833B4* t, int key)
{
    for (int i = 0; i < 1; i++) {
        if (t[i].key == key)
            t[i].key = 0;
    }
}

extern int lbl_806EF9B4;

extern "C" void* fn_80383644()
{
    return fn_80383548(operator new(0x24, lbl_806EF9B4));
}

extern "C" int fn_8038377C(Unk80382BB8* o)
{
    fn_803836DC(o);
    return *(int*)((char*)o + 0x20);
}

extern "C" void fn_803837EC(char* o)
{
    *(int*)(o + 0x1C) = 0;
}

extern "C" void* fn_803838D0()
{
    return fn_803837F8(operator new(0x34, lbl_806EF9B4));
}

extern "C" int fn_803839C8(Unk80382BB8* o)
{
    fn_80383928(o);
    return *(int*)((char*)o + 0x28);
}

extern "C" void fn_80383A38(char* o)
{
    *(int*)(o + 0x24) = 0;
}

extern "C" void* fn_80383C48()
{
    return fn_80383B24(operator new(0x1C, lbl_806EF9B4));
}

extern "C" void fn_80383C78(Unk80383C78* o, float* a, float* b, int* c, int* d)
{
    *a = o->mC;
    *b = o->m10;
    *c = o->m14;
    *d = o->m18;
}

extern "C" void fn_80383DC0(Unk80383DC0* o)
{
    o->m1C = o->m1C & 0xFFFDFFFF;
}

extern "C" FxK* fn_80383DD0() { return fn_80383C9C((FxK*)operator new(0x20, lbl_806EF9B4)); }
