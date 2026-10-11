/*
 * Game code, .text 0x801B23A8-0x801B460C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"

void fn_801B37C0(void* p);
void fn_801B4300(void* p);

struct Unk801B2470_T {
    char pad0[0x5C];
    int m5C[1];
};

int fn_801B2470(Unk801B2470_T* p, int i)
{
    return p->m5C[i];
}

struct Unk801B2480_T {
    char pad0[0x5C];
    int m5C[1];
};

void fn_801B2480(Unk801B2480_T* p, int i, int v)
{
    p->m5C[i] = v;
}

Unk801B2490::Unk801B2490(int a, int b) : Unk801B5A44(a, b)
{
    Setup();
}

Unk801B2490::~Unk801B2490() {}

void Unk801B2490::Setup()
{
    fn_vslot3();
}

void fn_801B25BC() {}

void fn_801B25C0() {}

void fn_801B25C4(void* p)
{
    fn_801B4300(p);
}

void fn_801B37A0(void* p)
{
    fn_801B37C0(p);
}

int fn_801B3FD0() { return 0; }
