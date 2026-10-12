/*
 * Game code, .text 0x8035BF0C-0x8035DA48 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8035B60C.h"
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))
#define PUTB(o, v) (*(unsigned char*)((char*)self + (o)) = (v))
#define PUTF(o, v) (*(float*)((char*)self + (o)) = (v))
#define CPUT(o, v) (*(const void**)((char*)this + (o)) = (v))
#define CPUTI(o, v) (*(int*)((char*)this + (o)) = (v))
#define CPUTB(o, v) (*(unsigned char*)((char*)this + (o)) = (v))
#define CPUTF(o, v) (*(float*)((char*)this + (o)) = (v))
#define GETI(o) (*(int*)((char*)self + (o)))
struct U {
    char pad0[0x4000];
};
void fn_80377408(void* p);
extern char lbl_80660850[];
extern const float lbl_805D675C;
void fn_801DD420(void* p, int chrg);
#include "game/clampiter.h"
void fn_8035D868(U* self);
void fn_8035D8F4(void* p);
void fn_8035D230(U* self);
void fn_8035D224(U* self);
struct Unk8035D9B0_E {
    char pad[0xD8];
    ~Unk8035D9B0_E() {}
};
struct Unk8035D9B0 {
    int m0;
    Unk8035D9B0_E m4[6];
    ~Unk8035D9B0();
};
struct Unk8035D96C {
    Unk8035D9B0 m0;
    ~Unk8035D96C();
};
struct Unk8035D908 {
    Unk8035D96C m0[9];
    ~Unk8035D908();
};
struct Unk8035D87C {
    int m0;
    VElem18 m4[9];
    ~Unk8035D87C();
};
struct Unk8035BF3C_S {
    int m0;
    int m4;
    int m8;
};
inline void Unk8035BF3C_Clear(Unk8035BF3C_S* s)
{
    s->m0 = -1;
    s->m4 = -1;
    s->m8 = -1;
}

U* fn_8035BF0C(U* self)
{
    fn_8035D868(self);
    return self;
}

void fn_8035BF3C(U* self)
{
    Unk8035BF3C_Clear((Unk8035BF3C_S*)self);
    Unk8035BF3C_Clear((Unk8035BF3C_S*)((char*)self + 0xC));
    PUTI(0x18, 0);
}

void fn_8035C1B0(U* self)
{
    Unk8006A138_It<3> it(0);
    int idx = 0;
    while (idx <= 3) {
        fn_8035D8F4((char*)self + (idx * 0xC + 0xC));
        idx = it.Next();
    }
}

void fn_8035C218(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, 0);
    PUTI(0x8, 0);
}

void fn_8035C230(U* self)
{
    PUTI(0x600, 0);
    PUTI(0x5fc, 0);
    PUTI(0x5f4, 0);
    PUTI(0x5f0, 0);
    PUTI(0x5ec, 0);
}

void fn_8035CD68(U* self, int chrg)
{
    PUT(0x8, lbl_80660850);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035CD9C(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, -1);
}

void fn_8035D1D8(U* self, float v) { PUTF(0x18, v); }

void fn_8035D1F0(U* self)
{
    fn_8035D230(self);
    fn_8035D224(self);
}

void fn_8035D224(U* self)
{
    PUTI(0x4, 0);
}

void fn_8035D230(U* self)
{
    PUTI(0x8, 0);
    PUTI(0xc, -1);
    PUTF(0x10, lbl_805D675C);
    PUTF(0x14, lbl_805D675C);
}

void fn_8035D254(U* self, int chrg)
{
    fn_801DD420(self, chrg);
}

void fn_8035D85C(U* self)
{
    PUTI(0x20, 0);
}

void fn_8035D868(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, -1);
    PUTI(0x8, -1);
}

Unk8035D87C::~Unk8035D87C() {}

void fn_8035D8F4(U* self)
{
    PUTI(0x0, 0);
    PUTI(0x4, 0);
    PUTI(0x8, 0);
}

Unk8035D908::~Unk8035D908() {}

Unk8035D96C::~Unk8035D96C() {}

Unk8035D9B0::~Unk8035D9B0() {}
