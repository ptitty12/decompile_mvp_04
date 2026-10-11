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

struct Unk801B6A4C_T {
    char pad0[0xB88];
    void* mB88;
};
struct Unk801B6A44_T {
    char pad0[0x70C];
    unsigned char m70C;
};
void fn_8023DF58(void* p);
void fn_801B905C(void* p);
struct Unk801B460C_Ent {
    int a;
    float b;
};
struct Unk801B460C_Tbl {
    Unk801AB63C_P* m0;
    char pad4[4];
    int m8;
    Unk801B460C_Ent m0C[25];
};
int fn_8014D8AC(void* a, int b, const char* c, int d);
extern char lbl_805CF800[];
extern float lbl_805CF7FC;
int fn_801B5790(Unk801B460C_Tbl* t);
int fn_801B57EC(Unk801B460C_Tbl* t);
int fn_801B5880(Unk801B460C_Tbl* t);
int fn_801B58D4(Unk801B460C_Tbl* t);
int fn_8025416C(void* a, int b);
int fn_80076644(int a, int b, int c);
int fn_801B5F4C(Unk801AB63C_P* p);
int fn_801B5F70(Unk801AB63C_P* p);
int fn_801C1870(void* a, int b, int c);
int fn_801B5EDC(void* a, int b, int c);
extern int lbl_8068BECC;
extern int lbl_806EF9B4;

int fn_801B5FC4(void* a, int b);

void fn_801B50B4(void* a, Unk801B23A8_Q* q, int* acc)
{
    int r = 0;
    int t = fn_801B5EDC(a, q->m708, 0);
    if (fn_801C1870(a, t, 4) != 0) {
        r = (4 - t) * 10;
    }
    *acc += r;
}

void fn_801B564C(Unk801B460C_Tbl* t)
{
    t->m8 = 0;
    for (int i = 0; i < 25; i++) {
        t->m0C[i].a = 0;
        t->m0C[i].b = lbl_805CF7FC;
    }
}

int fn_801B5700(Unk801B460C_Tbl* t, int k)
{
    int r = 0;
    if (t->m8 > 0) {
        switch (k) {
        case 0:
            r = fn_801B5790(t);
            break;
        case 1:
            r = fn_801B57EC(t);
            break;
        case 2:
            r = fn_801B5880(t);
            break;
        case 3:
            r = fn_801B58D4(t);
            break;
        default:
            r = 0;
            break;
        }
    }
    return r;
}

int fn_801B5790(Unk801B460C_Tbl* t)
{
    Unk801B460C_Ent* best = 0;
    for (int i = 0; i < t->m8; i++) {
        if (best == 0 || !(t->m0C[i].b <= best->b)) {
            best = &t->m0C[i];
        }
    }
    return best->a;
}

int fn_801B5880(Unk801B460C_Tbl* t)
{
    return t->m0C[fn_8014D8AC(t->m0->m8->m554, t->m8, lbl_805CF800, 0x945)].a;
}

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

int fn_801B5DE8(void* a, void* q, int c)
{
    if (q == 0) {
        return 0;
    }
    int r = 0;
    if (c == -1 || fn_80076644(c, fn_8025416C((char*)q + 0x588, 5), fn_8025416C((char*)q + 0x588, 6)) != 0) {
        r = 1;
    }
    return r;
}

int fn_801B5E6C(void* a, void* q, int c)
{
    if (q == 0) {
        return 0;
    }
    int r = 0;
    if (c == -1 || fn_80076644(c, fn_8025416C((char*)q + 0x588, 5), 0xE) != 0) {
        r = 1;
    }
    return r;
}

int fn_801B5EDC(Unk801AB63C_P* p, int b, int c)
{
    int r = fn_801B5F4C(p);
    if (fn_801B5F70(p) != 0 && ((b == 0 && c == 0) || (b == 1 && c == 1))) {
        r -= 1;
    }
    return r;
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

/* near-miss: 29 vs 28 insns; the three flag tests (q[10..12] != 0) are laid out differently. */
int fn_801B62E4(Unk801AB63C_P* p, int i)
{
    Unk8019F8C0_Owner* o = p->m8;
    if ((o->m6F8->m14[2].m8 == 0) == i) {
        int* q = o->m65C;
        int a = q[10] != 0;
        int b = q[11] != 0;
        int c = q[12] != 0;
        return a + b + c;
    }
    return 0;
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

int fn_801B6A44(Unk801B6A44_T* p)
{
    return p->m70C;
}

void fn_801B6A4C(Unk801B6A4C_T* p)
{
    fn_8023DF58(p);
    fn_801B905C(p->mB88);
}

void fn_801B7F2C(void* p)
{
    fn_801B8D1C(p, 0);
}
