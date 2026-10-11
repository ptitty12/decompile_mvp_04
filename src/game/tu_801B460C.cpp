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
    float m4;
    float m8;
    float mC;
    Unk801B64B0();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
};

struct Unk801B6A4C_T {
    char pad0[0xB88];
    int* mB88;
};
/* Object with a vptr at +0x98 whose virtual 24 (entry at +0xC0) returns an id/handle. */
class Unk801B460C_ObBase {
public:
    char pad0[0x98];
};
class Unk801B460C_Ob : public Unk801B460C_ObBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual int fn_vslot24();
};
Unk801B460C_Ob* fn_801B63A0(Unk801AB63C_P* p, int t);
void fn_801B8D1C(void* p, int v);
void fn_80249B08(void* p, int a, float f);
extern float lbl_805CF8EC;
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
void fn_801B5498(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* a, int* b, int* c, int* d, int* e, int* f);
struct Unk801B460C_Five {
    int a[5];
};
struct Unk801B460C_F {
    char pad0[0x40];
    int m40;
    int m44;
    int m48;
};
extern Unk801B460C_Five lbl_805CF778;
int fn_801C192C(void* a, int b);
extern Unk801B460C_Five lbl_805CF78C;
extern Unk801B460C_Five lbl_805CF7A0;
int fn_801B3850(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c);
void fn_801B484C(int* acc);
void fn_801B48EC(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B4AB4(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B4B88(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B4C6C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B4D2C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B4E24(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B4F14(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
void fn_801B50B4(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
int fn_801B3FD8(void* a, Unk801B23A8_Q* q);
unsigned fn_801B608C(void* a, Unk801B23A8_Q* q);
int fn_801B380C(void* a, Unk801B23A8_Q* q);
int fn_801B5F70(Unk801AB63C_P* p);
int fn_801C1870(void* a, int b, int c);
int fn_801B5EDC(void* a, int b, int c);
extern int lbl_8068BECC;
extern char lbl_805CF874[];
extern char lbl_805CF878[];
extern char lbl_805CF888[];
extern char lbl_805CF8A4[];
extern char lbl_805CF8B4[];
extern char lbl_805CF8CC[];
extern int lbl_806EF9B4;

int fn_801B5FC4(void* a, int b);

/* near-miss: 72/72 insns; register numbering of the callee-saved set and the table-copy pointer (r6 vs r12)
 * differ, same class as fn_801B4AB4. */
void fn_801B48EC(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    Unk801B460C_Five tbl = lbl_805CF778;
    Unk801B460C_F* f = (Unk801B460C_F*)((char*)q + 0x480);
    int off = 0;
    if (f->m44 >= 0) {
        off = (f->m48 - 0xF) * 4;
    }
    int v = *(int*)((char*)&tbl + off);
    int r = 0;
    int t = fn_801B5FC4(p, q->m708);
    if (fn_801C192C(p, t) != 0) {
        int u = fn_801B608C(p, q);
        int w = -t;
        if (w > u) {
            w = u;
        }
        if ((unsigned)(f->m48 - 0x10) <= 1 && f->m40 <= -5 && v < 0 && u < (int)fn_801B380C(p, q) * 2) {
            v = -v;
        }
        r = v * w;
    }
    *acc += r;
}

void fn_801B4A0C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    if ((int)q->m4C4 < 0 && fn_801B3FD8(p, q) == 0) {
        unsigned t = fn_801B608C(p, q);
        if (t > fn_801B380C(p, q)) {
            int r = fn_801B5EDC(p, q->m708, 0);
            if (fn_801C1870(p, r, 3) != 0) {
                *acc += 3;
                *acc -= r;
            }
        }
    }
}

/* near-miss: 53/53 insns; register allocation differs (retail: p r29, q r31, flag-block pointer in r4,
 * table pointer r6; mine keeps the flag-block pointer in r30). ~3 forms tried. */
void fn_801B4AB4(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    Unk801B460C_Five tbl = lbl_805CF78C;
    Unk801B460C_F* f = (Unk801B460C_F*)((char*)q + 0x480);
    int off = 0;
    if (f->m44 >= 0) {
        off = (f->m48 - 0xF) * 4;
    }
    int v = *(int*)((char*)&tbl + off);
    fn_801B4A0C(p, q, &v);
    int t = fn_801B608C(p, q);
    *acc += v * (t - fn_801B3850(p, q, 1));
}

/* near-miss: same register-allocation difference as fn_801B4AB4. */
void fn_801B4B88(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    if (q->m708 == (p->m8->m6F8->m14[2].m8 == 0)) {
        Unk801B460C_Five tbl = lbl_805CF7A0;
        Unk801B460C_F* f = (Unk801B460C_F*)((char*)q + 0x480);
        int off = 0;
        if (f->m44 >= 0) {
            off = (f->m48 - 0xF) * 4;
        }
        int v = *(int*)((char*)&tbl + off);
        fn_801B4A0C(p, q, &v);
        *acc += fn_801B3850(p, q, 1) * v;
    }
}

void fn_801B4E24(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    if (q->m708 == (p->m8->m6F8->m14[2].m8 == 0)) {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        fn_801B5498(p, q, &a, &b, &c, &d, &e, &f);
        int r = 0;
        if (c == 1) {
            r = 5;
        }
        if (d == 1) {
            r += 0xA;
        }
        if (e == 1) {
            r += 0xF;
        }
        *acc += r;
        if (r > 0) {
            int s = 0;
            if (b == 0 && (d != 0 || e != 0)) {
                s = 0xF;
            } else if (b <= 1) {
                s = 0xA;
            }
            *acc += s;
        }
    }
}

void fn_801B50B4(Unk801AB63C_P* a, Unk801B23A8_Q* q, int* acc)
{
    int r = 0;
    int t = fn_801B5EDC(a, q->m708, 0);
    if (fn_801C1870(a, t, 4) != 0) {
        r = (4 - t) * 10;
    }
    *acc += r;
}

/* near-miss: same code; retail keeps &s in r28 and p in r30 (mine swaps them), 17 slots differ; ~3 forms tried. */
int fn_801B5120(Unk801AB63C_P* p, Unk801B23A8_Q* q, int c)
{
    int s = 0;
    fn_801B484C(&s);
    fn_801B48EC(p, q, &s);
    fn_801B4AB4(p, q, &s);
    fn_801B4B88(p, q, &s);
    fn_801B4C6C(p, q, &s);
    fn_801B4D2C(p, q, &s);
    fn_801B4E24(p, q, &s);
    fn_801B4F14(p, q, &s);
    fn_801B50B4(p, q, &s);
    return s;
}

/* near-miss: same register swap as fn_801B5120. */
int fn_801B51E4(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int s = 0;
    fn_801B484C(&s);
    fn_801B48EC(p, q, &s);
    fn_801B4AB4(p, q, &s);
    fn_801B4B88(p, q, &s);
    fn_801B4C6C(p, q, &s);
    fn_801B4D2C(p, q, &s);
    fn_801B4E24(p, q, &s);
    fn_801B4F14(p, q, &s);
    return s;
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

int fn_801B5AD0(Unk801AB63C_P* p, int t)
{
    Unk801B460C_Ob* o = fn_801B63A0(p, t);
    return o ? o->fn_vslot24() : 0;
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

void Unk801B64B0::fn_vslot2()
{
    fn_8037B7E4(lbl_805CF874);
    fn_8037B7E8(lbl_805CF878);
    fn_8037B50C(lbl_805CF888, &m4, lbl_805CF8A4, 0);
    fn_8037B50C(lbl_805CF8B4, &m8, lbl_805CF8A4, 0);
    fn_8037B50C(lbl_805CF8CC, &mC, lbl_805CF8A4, 0);
    fn_8037B830(lbl_805CF878);
}

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

void fn_801B6A80(void* p)
{
    fn_801B8D1C(p, 0);
    fn_80249B08(p, 0, lbl_805CF8EC);
}

void fn_801B7ED8(void* p, Unk801B460C_Ob* o)
{
    if (o) {
        fn_801B8D1C(p, o->fn_vslot24());
    }
}

void fn_801B7F2C(void* p)
{
    fn_801B8D1C(p, 0);
}

void fn_801B7F50(Unk801B6A4C_T* p, Unk801B460C_Ob* o)
{
    if (o) {
        fn_801B8D1C(p, o->fn_vslot24());
    }
    *p->mB88 = 1;
}
