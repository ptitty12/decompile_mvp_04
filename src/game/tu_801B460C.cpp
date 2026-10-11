/*
 * Game code, .text 0x801B460C-0x801B7FB0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"
#include "game/tu_801B23A8.h"
#include "game/chooser.h"
void fn_801B6778(void* p);
void fn_801B8D1C(void* p, int n);
void fn_801B6A24(void* p)
{
    fn_801B6778(p);
}

/* Script-command style class: hash 0x575DF764, vtable 0x80660230. */
class Unk801B64B0 : public Unk8037B3E8 {
public:
    int m4;
    int m8;
    int mC;
    Unk801B64B0();
    virtual Unk8037B3E8* fn_vslot5();
};

extern int lbl_8068BECC;
extern int lbl_806EF9B4;

int fn_801B5FC4(void* a, int b);

Unk801B5A44::Unk801B5A44(int a, int b)
{
    m4 = a;
    m8 = b;
}

Unk801B5A44::~Unk801B5A44()
{
    m4 = 0;
    m8 = 0;
}

int fn_801B5F4C(Unk801AB63C_P* p)
{
    Unk8019F8C0_Mgr* m = p->m8->m6F8;
    int t = m->m10->m1C - 1;
    return t - m->m14[2].m0;
}

int fn_801B5F70(Unk801AB63C_P* p)
{
    return p->m8->m6F8->m14[2].m8 == 0;
}

int fn_801B5F8C(Unk801AB63C_P* p)
{
    return p->m8->m6F8->m14[2].m1;
}

/* near-miss: retail loads the table index byte into r9 (reusing the array pointer's register) and
 * adds r9+r4; 2 slots differ. */
int fn_801B5FA0(Unk801AB63C_P* p, int i)
{
    Unk8019F8C0_Inner* m14 = p->m8->m6F8->m14;
    unsigned char k = m14[2].m0;
    return m14[i].m1B4[k];
}

int fn_801B6354(void* a, int b, int c)
{
    int v = fn_801B5FC4(a, b);
    int r = 0;
    if (v < -c || v > c) {
        r = 1;
    }
    return r;
}

Unk801B64B0::Unk801B64B0() : Unk8037B3E8(0x575DF764u) {}

Unk801B64B0* fn_801B659C()
{
    return (Unk801B64B0*)fn_8037C7FC()->fn_8037CE98(0x575DF764, lbl_8068BECC, 0);
}

Unk8037B3E8* Unk801B64B0::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk801B64B0;
}

void fn_801B7F2C(void* p)
{
    fn_801B8D1C(p, 0);
}
