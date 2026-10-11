/*
 * Game code, .text 0x801AE30C-0x801B23A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"
#include "game/tu_801AB63C.h"

void fn_801AE5F0(void* p);
void fn_801AE6A8(void* p);
void fn_801B113C(void* p);
void fn_801AE2B0(void* p);
int fn_801AE2FC(void* p);
int fn_801AE304(void* p);
int fn_801A7130(Unk8019F8C0_Owner* o, int i);
void fn_801B25E4(Unk801AB63C_P* p, int n);
void fn_801B2428(void* p);
int fn_801B1380(Unk801AB63C_P* p);
void fn_801B1FE8(void* p);

struct Unk801AE30C_Pair {
    int m0;
    char m4[8];
    char mC[8];
};
struct Unk801AE30C_Clr {
    int m0;
    char m4[2][8];
};

void fn_801AE360(Unk801AE30C_Clr* p)
{
    p->m0 = 0;
    for (int i = 0; i < 2; i++) {
        fn_801AE2B0(p->m4[i]);
    }
}

void fn_801AE3A8(Unk801AE30C_Pair* p, int* a, int* b)
{
    *a = fn_801AE2FC(p->m4);
    *b = fn_801AE304(p->m4);
}

void fn_801AE494(Unk801AE30C_Pair* p, int* a, int* b)
{
    *a = fn_801AE2FC(p->mC);
    *b = fn_801AE304(p->mC);
}

Unk801AE5C0::~Unk801AE5C0() {}

void fn_801AE688(void* p)
{
    fn_801AE5F0(p);
}

void fn_801AE75C() {}

void fn_801B032C() {}

void fn_801B0330() {}

void fn_801B0334(void* p)
{
    fn_801AE6A8(p);
}

struct Unk801AE30C_St {
    char pad0[0x14];
    int m14;
};

void fn_801B03B8(Unk801AE30C_St* p)
{
    int s = p->m14;
    if ((unsigned)(s - 1) <= 1 || s == 4) {
        p->m14 = 0;
    }
}

void Unk801B10C8::Init()
{
    Setup();
    fn_801B2428(this);
}

void fn_801B0ACC() {}

void fn_801B108C() {}

Unk801B10C8::Unk801B10C8(int a, int b) : Unk801B2490(a, b)
{
    Init();
}

Unk801B10C8::~Unk801B10C8() {}

void fn_801B1170(void* p)
{
    fn_801B113C(p);
}

void fn_801B1220(Unk801AB63C_P* p)
{
    if (fn_801B1380(p) == 1) {
        int f = 0;
        if (p->m8->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        fn_801B25E4(p, f);
    }
}

void fn_801B127C(Unk801AB63C_P* p)
{
    fn_801B2428(p);
    if (fn_801B1380(p) == 1) {
        fn_801B1FE8(p);
    }
}

void fn_801B12C0(Unk801AB63C_P* p)
{
    if (fn_801B1380(p) == 1) {
        int f = 0;
        if (p->m8->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        fn_801B25E4(p, f);
    }
}

int fn_801B1380(Unk801AB63C_P* p)
{
    Unk8019F8C0_Owner* o = p->m8;
    int f = 0;
    if (o->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    return fn_801A7130(o, f) != 0 ? 1 : 0;
}
