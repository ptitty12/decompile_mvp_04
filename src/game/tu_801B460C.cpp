/*
 * Game code, .text 0x801B460C-0x801B7FB0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"
#include "game/tu_801B23A8.h"
#include "game/chooser.h"
inline int Unk801B460C_KeyAt(char* base, int off) { return *(int*)(base + off); }
float fn_8025356C(void* p);
int fn_80253DF4(void* p, int a, int b);
extern "C" int fn_801A49F0(Unk8019F8C0_Owner* o, int team, int key);
extern float lbl_805CF6E8[];
extern int lbl_805CF6F8[];
void fn_801B6778(void* p);
void fn_801B8D1C(void* p, int n);
extern "C" void* fn_801A4910(Unk8019F8C0_Owner* o, int team, unsigned char slot);
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

/* Object family with many embedded vptrs (+0x98, +0xB8, +0x4D4, +0x530, +0x584, +0x5E0, +0x5EC, +0x5F0);
 * the vtables are retail data objects, so the pointers are stored by hand. */
struct Unk801B6604_F398 {
    unsigned f0 : 1;
    unsigned rest : 31;
};
struct Unk801B6604_F39C {
    unsigned a : 11;
    unsigned b : 2;
    unsigned c : 19;
};
struct Unk801B6604_V3 {
    int m0;
    int m4;
    int m8;
};
struct Unk801B6604_T {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
    char padBC[0x398 - 0xBC];
    Unk801B6604_F398 m398;
    Unk801B6604_F39C m39C;
    char pad3A0[0x4D4 - 0x3A0];
    const void* m4D4;
    char pad4D8[0x530 - 0x4D8];
    const void* m530;
    char pad534[0x584 - 0x534];
    const void* m584;
    char pad588[0x5E0 - 0x588];
    const void* m5E0;
    char pad5E4[0x5EC - 0x5E4];
    const void* m5EC;
    const void* m5F0;
    char pad5F4[0xB80 - 0x5F4];
    float mB80;
    float mB84;
    void* mB88;
    Unk801B6604_V3 mB8C;
    char padB98[0xB98 - 0xB98];
    int mB98;
    int mB9C;
};
extern char lbl_8065F058[];
extern char lbl_8065F040[];
extern char lbl_8065F028[];
extern char lbl_8065F010[];
extern char lbl_8065EFF8[];
extern char lbl_8065EFD0[];
extern char lbl_80661058[];
extern char lbl_8065F0E8[];
extern float lbl_805CF8E4;
extern float lbl_805CF8E8;
extern Unk801B6604_V3 lbl_806055AC;
void fn_8023CB50(Unk801B6604_T* self, int a, int b, int c, unsigned char d);
void fn_8023DBB0(Unk801B6604_T* self, int inchrg);
void fn_8023CD70(Unk801B6604_T* self);
void fn_801B9034(void* p, int n);
void* fn_801B9014(void* mem, Unk801B6604_T* self);
void fn_801B901C(void* p);
int fn_801B6A44(void* p);
void* operator new(unsigned int size, int heap);

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
    int m4;
    int m8;
    Unk801B460C_Ent m0C[25];
};
int fn_8014D8AC(void* a, int b, const char* c, int d);
extern char lbl_805CF800[];
extern float lbl_805CF7FC;
int fn_8014E2B4(int a);
struct Unk801B6438_Sub {
    char pad0[4];
    unsigned m4;
    char pad8[0x38 - 0x8];
    int m38;
};
struct Unk801B6438_Obj {
    char pad0[0x58C];
    Unk801B6438_Sub m58C;
};
int fn_801B5F8C(Unk801AB63C_P* p);
Unk801B6438_Obj* fn_801B6438(Unk801AB63C_P* p, int id);
int fn_801B5EDC(Unk801AB63C_P* p, int b, int c);
void fn_801B564C(Unk801B460C_Tbl* t);
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
void fn_801B484C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc);
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

/* near-miss: same code; retail keeps the byte offset (slwi r0,r10,2) per iteration and inc in r11 (41 vs 40 insns). */
void fn_801B484C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    float x = fn_8025356C((char*)q + 0x480);
    int inc = 0;
    int i = 0;
    if (!(x >= lbl_805CF6E8[0])) {
        inc = lbl_805CF6F8[0];
    } else {
        for (;;) {
            i++;
            if (i > 3) {
                break;
            }
            if (!(x >= lbl_805CF6E8[i])) {
                inc = lbl_805CF6F8[i];
                break;
            }
        }
    }
    *acc += inc;
}

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

void fn_801B4C6C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    int inc = 0;
    int s = fn_8025416C((char*)q + 0x588, 0x16);
    if (s > 2) {
        if (s == 4) {
            inc = -30;
        } else if (s == 3) {
            inc = -15;
        }
        unsigned a = fn_801B608C(p, q);
        unsigned b = fn_801B380C(p, q);
        if (fn_801B3FD8(p, q) == 0) {
            if (a <= b) {
                inc = inc / 2;
            } else {
                inc = 0;
            }
        }
        *acc += inc;
    }
}

struct Unk801B4D2C_Five {
    float a[5];
};
extern Unk801B4D2C_Five lbl_805CF7B4;
unsigned fn_801B616C(Unk801AB63C_P* p, Unk801B23A8_Q* q);

void fn_801B4D2C(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    Unk801B4D2C_Five tbl = lbl_805CF7B4;
    unsigned k = q->m4C8 - 0xF;
    int idx = 0;
    if (k <= 4) {
        idx = k;
    }
    float f = tbl.a[idx];
    *acc += (unsigned)((float)fn_801B616C(p, q) * f);
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

struct Unk801B4F14_Pair {
    float a;
    float b;
};
struct Unk801B4F14_O {
    char pad0[0x44C];
    int m44C;
    char pad450[0x708 - 0x450];
    int m708;
    char pad70C[0xA04 - 0x70C];
    int mA04;
    char padA08[4];
    char mA0C[4];
};
extern Unk801B4F14_Pair lbl_805CF7E0;
extern Unk801B4F14_Pair lbl_805CF7D8;
float fn_8024F048(char* p, int a, int b, int c, int d);
float fn_8024F20C(char* p, int a, int b, int c, int d);
inline float Unk801B4F14_Norm(float lo, float t, float hi)
{
    float span = hi - lo;
    if (!(span <= 0.0f))
        return (t - lo) / span;
    return 0.0f;
}
inline float Unk801B4F14_Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}
void fn_801B4F14(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* acc)
{
    int r = 0;
    float x = 0.0f;
    Unk801B4F14_O* o = (Unk801B4F14_O*)fn_801B63A0(p, q->m708);
    if (o) {
        x = fn_8024F048(o->mA0C, o->mA04, o->m44C, o->m708, 1) + fn_8024F20C(o->mA0C, o->mA04, o->m44C, o->m708, 1);
    }
    Unk801B4F14_Pair rng = lbl_805CF7E0;
    Unk801B4F14_Pair out = lbl_805CF7D8;
    if (!(x < rng.a)) {
        float u = Unk801B4F14_Norm(rng.a, x, rng.b);
        u = !(u > 1.0f) ? (u >? 0.0f) : 1.0f;
        float res = Unk801B4F14_Lerp(out.a, u, out.b);
        r = (int)res;
    }
    *acc += r;
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
    fn_801B484C(p, q, &s);
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
    fn_801B484C(p, q, &s);
    fn_801B48EC(p, q, &s);
    fn_801B4AB4(p, q, &s);
    fn_801B4B88(p, q, &s);
    fn_801B4C6C(p, q, &s);
    fn_801B4D2C(p, q, &s);
    fn_801B4E24(p, q, &s);
    fn_801B4F14(p, q, &s);
    return s;
}

int fn_801B5F8C(Unk801AB63C_P* p);
struct Unk801B5298_T3 {
    int v[3];
};
extern Unk801B5298_T3 lbl_805CF7F0;
unsigned fn_801B2834(Unk801AB63C_P* p, Unk801B23A8_Q* q);
int fn_801B5DE8(void* a, void* q, int c);
int fn_801C1638(Unk8019F8C0_Owner* o, int i);
int fn_801B5298(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int v = 0;
    unsigned sc = 0;
    int t = fn_801B5EDC(p, q->m708, 0);
    if (fn_801B5DE8(p, q, 0) == 1)
        sc = fn_801B2834(p, q);
    if (sc > 0x6D) {
        v = 0x5A;
    } else if (sc > 0x59) {
        v = 0x41;
    } else if (fn_801C1870(p, t, 4) != 0) {
        int x = sc;
        if (x > 0x41)
            x = 0x41;
        v = x;
    }
    int d = fn_801B5FC4(p, q->m708);
    if (d <= -4)
        v += 0x1E;
    else if (d <= -1)
        v += 0x14;
    else if (d <= 0)
        v += 0xA;
    else if (d > 3)
        v -= 0xA;
    int idx = fn_801B5F8C(p);
    Unk801B5298_T3 tbl = lbl_805CF7F0;
    int off = idx * 4;
    char* tb = (char*)&tbl;
    v += *(int*)(tb + off);
    int ok = fn_801C1638(p->m8, 0xA);
    int f = 1;
    if (ok == 0)
        f = 0;
    if (f)
        v += 5;
    ok = fn_801C1638(p->m8, 0xB);
    f = 1;
    if (ok == 0)
        f = 0;
    if (f)
        v += 0xA;
    ok = fn_801C1638(p->m8, 0xC);
    f = 1;
    if (ok == 0)
        f = 0;
    if (f)
        v += 0x14;
    if (t <= 0)
        v += 0x32;
    else if (t == 1)
        v += 0x28;
    else if (t == 2)
        v += 0x1E;
    else if (t == 3)
        v += 0xA;
    else if (t > 5)
        v -= 0xA;
    return v;
}
int fn_801B5F8C(Unk801AB63C_P* p);
Unk801B6438_Obj* fn_801B6438(Unk801AB63C_P* p, int id);
int fn_801B5EDC(Unk801AB63C_P* p, int b, int c);
/* near-miss: same code (99.4%); retail keeps p in r31 and the first out pointer in r30 (mine swaps them, 13 slots).
 * Allocation priorities: out1 5 refs/40 insns (0.25) vs p 8 refs/99 insns (0.242). Tried: p->m8 reloads, order of
 * declarations, inline team selector. */
void fn_801B5498(Unk801AB63C_P* p, Unk801B23A8_Q* q, int* a, int* b, int* c, int* d, int* e, int* f)
{
    Unk8019F8C0_Owner* o = p->m8;
    int idx = q->m708;
    if (idx == (o->m6F8->m14[2].m8 == 0)) {
        if (a)
            *a = (int)fn_801B63A0(p, 2);
        if (b)
            *b = fn_801B5F8C(p);
        if (c) {
            Unk801B6438_Obj* ob = fn_801B6438(p, 0);
            int v = 1;
            if (ob == 0)
                v = 0;
            *c = v;
        }
        if (d) {
            Unk801B6438_Obj* ob = fn_801B6438(p, 1);
            int v = 1;
            if (ob == 0)
                v = 0;
            *d = v;
        }
        if (e) {
            Unk801B6438_Obj* ob = fn_801B6438(p, 2);
            int v = 1;
            if (ob == 0)
                v = 0;
            *e = v;
        }
    } else {
        if (a) {
            int t;
            if (idx > 2) {
                t = 3;
                if (idx == 3)
                    t = 4;
            } else
                t = idx == 0;
            Unk8019F8C0_Inner* en = p->m8->m6F8->m14 + t;
            *a = (int)fn_801A4910(o, t, en->m168.m0[(unsigned char)en->m168.mC]);
        }
        if (b)
            *b = 0;
        if (c)
            *c = 0;
        if (d)
            *d = 0;
        if (e)
            *e = 0;
    }
    if (f)
        *f = fn_801B5EDC(p, q->m708, 0);
}

void fn_801B564C(Unk801B460C_Tbl* t)
{
    t->m8 = 0;
    for (int i = 0; i < 25; i++) {
        t->m0C[i].a = 0;
        t->m0C[i].b = lbl_805CF7FC;
    }
}

void fn_801B5688(Unk801B460C_Tbl* t, int id, int limit, float v)
{
    if (limit > t->m4) {
        fn_801B564C(t);
        t->m4 = limit;
    }
    if (limit >= t->m4) {
        Unk801B460C_Ent* e = &t->m0C[t->m8++];
        e->a = id;
        e->b = v;
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

int fn_801B57EC(Unk801B460C_Tbl* t)
{
    Unk801B460C_Ent* best = 0;
    Unk801B460C_Ent* second = 0;
    for (int i = 0; i < t->m8; i++) {
        if (best == 0 || !(t->m0C[i].b <= best->b)) {
            best = &t->m0C[i];
        } else if (second == 0 || !(t->m0C[i].b <= second->b)) {
            second = &t->m0C[i];
        }
    }
    if (second == 0) {
        return best->a;
    }
    return second->a;
}

int fn_801B5880(Unk801B460C_Tbl* t)
{
    return t->m0C[fn_8014D8AC(t->m0->m8->m554, t->m8, lbl_805CF800, 0x945)].a;
}

/* near-miss: same code; only the order of the two arg-address loads (lis r4/r5) before fn_8014D8AC differs. */
int fn_801B58D4(Unk801B460C_Tbl* t)
{
    float w[25];
    float total = 0.0f;
    float x;
    int i;
    for (i = 0; i < t->m8; i++) {
        w[i] = t->m0C[i].b * t->m0C[i].b;
        total += w[i];
    }
    float s = total;
    x = (float)(unsigned)fn_8014D8AC(t->m0->m8->m554, 1000000, lbl_805CF800, 0x960) * s * 1e-6f;
    volatile float pad;
    float acc = 0.0f;
    int res = 0;
    for (i = 0; i < t->m8; i++) {
        acc += w[i];
        if (!(x > acc)) {
            res = t->m0C[i].a;
            break;
        }
    }
    return res;
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

inline int Unk801B5FA0_At(unsigned char* t, int k) { int o = k; return t[o]; }
int fn_801B5FA0(Unk801AB63C_P* p, int i)
{
    Unk8019F8C0_Inner* m14 = p->m8->m6F8->m14;
    Unk8019F8C0_Inner* e = m14 + i;
    unsigned char k = m14[2].m0;
    return Unk801B5FA0_At(e->m1B4, k);
}

inline int Unk801B5FC4_B(unsigned char* b, int i) { return b[i]; }
int fn_801B5FC4(void* pp, int t)
{
    Unk801AB63C_P* p = (Unk801AB63C_P*)pp;
    Unk8019F8C0_Mgr* m = p->m8->m6F8;
    int a = t;
    if (a > 2) {
        int f = 0;
        if (m->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
        t = a;
    }
    Unk8019F8C0_Inner* ia = m->m14 + t;
    int sa = 0;
    for (int i = 0; i < 128; i++) {
        sa += Unk801B5FC4_B(ia->m1B4, (unsigned char)i);
    }
    int u;
    if (t > 2) {
        u = 3;
        if (t == 3) {
            u = 4;
        }
    } else {
        u = t == 0;
    }
    Unk8019F8C0_Inner* ib = m->m14 + u;
    int sb = 0;
    for (int i = 0; i < 128; i++) {
        sb += Unk801B5FC4_B(ib->m1B4, (unsigned char)i);
    }
    return sa - sb;
}

inline int Unk801B608C_Other(int t)
{
    if (t > 2) {
        int u = 3;
        if (t == 3) {
            u = 4;
        }
        return u;
    }
    return t == 0;
}
int fn_801B608C(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    int r = fn_80253DF4((char*)q + 0x588, 5, 0);
    Unk8019F8C0_Mgr10* x = p->m8->m6F8->m10;
    if (x != 0 && x->m22C == 0xb && (int)q->m4C4 < 0 && r == 0) {
        int t = Unk801B608C_Other(q->m708);
        Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[t];
        if (e != 0) {
            r = 0;
            for (int i = 0; i < 128; i++) {
                r += e->m1B4[(unsigned char)i];
            }
        } else {
            r = 0;
        }
    }
    return r;
}

/* near-miss: 29 vs 28 insns; the three flag tests (q[10..12] != 0) are laid out differently. */
struct Unk8024EF40_W;
float fn_80253EC4(Unk8024EF40_W* w, int a, int b, int c);
float fn_80097F68(Unk8019F8C0_Inner* t, int a, int b, int c, int d);
inline int Unk801B616C_B(unsigned char* b, int i) { return b[i]; }

/* near-miss: same code; in the 128-byte sum loop retail keeps the counter in r11 with the index in r0 (here r10/r9). */
unsigned fn_801B616C(Unk801AB63C_P* p, Unk801B23A8_Q* q)
{
    unsigned r = (unsigned)fn_80253EC4((Unk8024EF40_W*)q->m588, 2, 2, 0);
    Unk8019F8C0_Mgr10* m = p->m8->m6F8->m10;
    if (m != 0 && m->m22C == 0xB && (int)q->m4C4 < 0 && r == 0) {
        int t = q->m708;
        int k;
        if (t > 2) {
            int u = 3;
            if (t == 3) {
                u = 4;
            }
            k = u;
        } else {
            k = t == 0;
        }
        Unk8019F8C0_Inner* e = &p->m8->m6F8->m14[k];
        if (e != 0) {
            int sum = 0;
            for (int i = 0; i < 128; i++) {
                sum += Unk801B616C_B(e->m1B4, (unsigned char)i);
            }
            int cnt = 0;
            unsigned char j = 0;
            while (j < e->m3E4) {
                cnt += (int)fn_80097F68(e, 0, j, 2, 0);
                j++;
            }
            r = sum * 3 + cnt;
        } else {
            r = 0;
        }
    }
    return r;
}

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

/* near-miss: same code; retail reloads o->m6F8->m14 for the final entry address (one more lwz, 37 vs 38 insns). */
/* near-miss: same code; retail reloads o->m6F8->m14 for the final entry address (one more lwz, 37 vs 38 insns). */
Unk801B460C_Ob* fn_801B63A0(Unk801AB63C_P* p, int t)
{
    Unk8019F8C0_Owner* o = p->m8;
    int f = o->m6F8->m14[2].m8 == 0;
    if (t == f || t == 2) {
        return (Unk801B460C_Ob*)o->m65C[9];
    }
    if (t > 2) {
        if (t == 3) {
            t = 4;
        } else {
            t = 3;
        }
    } else {
        t = t == 0;
    }
    Unk8019F8C0_Inner* e = o->m6F8->m14 + t;
    return (Unk801B460C_Ob*)fn_801A49F0(o, t, Unk801B460C_KeyAt((char*)e + 0x3e8, e->m168.m0[e->m168.mC] * 0x34));
}

/* near-miss: same code; the index temporary lands in r0 instead of r11 (2 slots). */
Unk801B6438_Obj* fn_801B6438(Unk801AB63C_P* p, int id)
{
    Unk8019F8C0_Owner* o = p->m8;
    unsigned k = fn_8014E2B4(id);
    Unk801B6438_Obj* obj = k <= 12 ? (Unk801B6438_Obj*)o->m65C[k] : 0;
    if (obj != 0) {
        Unk801B6438_Sub* s = &obj->m58C;
        if (!(s->m4 & 0x20000000)) {
            if (s->m38 == id) {
                return obj;
            }
        }
    }
    return 0;
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

Unk801B6604_T* fn_801B6604(Unk801B6604_T* self, int a, int c)
{
    fn_8023CB50(self, a, 0, 2, c);
    self->mB8 = lbl_8065F058;
    self->m4D4 = lbl_8065F040;
    self->m530 = lbl_8065F028;
    self->m584 = lbl_8065F010;
    self->m5E0 = lbl_8065EFF8;
    self->m5EC = lbl_8065EFD0;
    self->m5F0 = lbl_80661058;
    self->m98 = lbl_8065F0E8;
    self->mB88 = fn_801B9014(new (0) char[16], self);
    fn_801B6778(self);
    return self;
}

void fn_801B66C0(Unk801B6604_T* self, int inchrg)
{
    self->mB8 = lbl_8065F058;
    self->m4D4 = lbl_8065F040;
    self->m530 = lbl_8065F028;
    self->m584 = lbl_8065F010;
    self->m5E0 = lbl_8065EFF8;
    self->m5EC = lbl_8065EFD0;
    self->m5F0 = lbl_80661058;
    self->m98 = lbl_8065F0E8;
    if (self->mB88 != 0) {
        fn_801B9034(self->mB88, 3);
    }
    self->mB88 = 0;
    fn_8023DBB0(self, inchrg);
}

void fn_801B6778(void* p)
{
    Unk801B6604_T* self = (Unk801B6604_T*)p;
    fn_8023CD70(self);
    fn_801B901C(self->mB88);
    if (fn_801B6A44(self) == 0) {
        self->m398.f0 = 1;
    } else {
        self->m398.f0 = 0;
    }
    self->m39C.b = 2;
    self->mB80 = lbl_805CF8E4;
    self->mB8C = lbl_806055AC;
    self->mB98 = 0;
    self->mB9C = -1;
    self->mB84 = lbl_805CF8E8;
}

struct Unk801B6830_P {
    char pad0[0x384];
    unsigned m384;
    char pad388[0x398 - 0x388];
    unsigned m398;
    unsigned m39C;
    int m3A0;
    int m3A4;
    int m3A8;
    int m3AC;
    int m3B0;
    int m3B4;
    int m3B8;
    int m3BC;
    int m3C0;
    int m3C4;
    int m3C8;
    char pad3CC[0x458 - 0x3CC];
    int m458;
    char pad45C[0x708 - 0x45C];
    int m708;
};
struct Unk801B6830_R {
    char m0[0x20];
    unsigned m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
};
extern int lbl_8061D460;
extern int lbl_8061D468;
extern int lbl_8061B9BC;
int fn_80337830(int i);
int fn_80337844(int i);
int fn_8023EB80(void* p, int i);
void fn_801B6830(Unk801B6830_P* p, Unk801B6830_R* r, int slot)
{
    r->m0[0] = 0;
    r->m20 = fn_80378568(r->m0, 0);
    r->m58 = 0;
    r->m24 = p->m384 >> 25;
    r->m2C = 0x385;
    if (lbl_8061D460 != 0)
        r->m2C = lbl_8061D468;
    r->m30 = (p->m39C >> 21) & 1;
    r->m28 = 0;
    if (lbl_8061D460 != 0)
        r->m28 = 1;
    r->m34 = (p->m398 >> 20) & 7;
    r->m38 = 0;
    r->m3C = 2;
    if (lbl_8061B9BC != 0 && lbl_8061D460 != 0) {
        r->m60 = fn_80337830(lbl_8061D468);
        r->m30 = (fn_80337844(lbl_8061D468) ^ 1) == 0;
    } else {
        r->m60 = fn_8023EB80(p, r->m2C - 0x385);
    }
    r->m48 = 0;
    r->m4C = 0;
    r->m50 = 0;
    r->m54 = 1;
    r->m5C = 0;
    r->m64 = p->m708;
    int s = slot;
    if (s == -1)
        s = p->m458;
    r->m68 = s;
    r->m6C = 0;
    r->m8C = p->m3A0 ^ 1;
    r->m90 = p->m3A4 ^ 1;
    r->m94 = p->m3B8 ^ 1;
    r->m98 = p->m3B0 ^ 1;
    r->m9C = p->m3B4 ^ 1;
    r->mA0 = p->m3A8 ^ 1;
    r->mA4 = p->m3AC ^ 1;
    r->mA8 = p->m3BC ^ 1;
    r->mAC = p->m3C0 ^ 1;
    r->mB0 = p->m3C4 ^ 1;
    r->mB4 = p->m3C8 ^ 1;
    r->m74 = 1;
    r->mB8 = 0;
    r->m70 = 0;
    r->m84 = 0;
    r->m80 = 0;
    r->m40 = 0;
    r->m44 = 0;
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

class Unk80287D70 {
public:
    Unk80287D70* fn_80287DB8(int kind);
};
struct Unk8027C728_Goal {
    Unk8027C728_Goal* m0;
    char pad4[0x10 - 0x4];
    int m10;
    char pad14[0x18 - 0x14];
    char m18[0x104 - 0x18];
    char m104[4];
};
class Unk8027A84C {
public:
    int m0;
    Unk8027A84C* m4;
    void* m8;
    int mC;
    char pad10[0x34 - 0x10];
    int m34;
    int m38;
    int m3C;
    int m40;
    void fn_8027A898(const Unk80273498_Vec3* v);
};
class Unk8027A84C_Owner {
public:
    Unk8027A84C* fn_8027C67C();
};
class Unk8028B194 {
public:
    Unk8028B194* fn_8028B194(Unk80273498_Vec3 v);
};
struct Unk801B7BC4_P {
    char pad0[0xB84];
    float mB84;
};
extern "C" Unk8027C728_Goal* fn_802448F4(Unk801B7BC4_P* p, int k);
void fn_8027C728(Unk8027C728_Goal* g);
void fn_8027D33C(Unk8027C728_Goal* g);
extern float lbl_805CF944;

/* near-miss: same code; retail keeps a second copy of the goal pointer (mr r26,r31) alive until the final g->m0 load, so its callee-saved set is r24-r31 (mine r25-r31), 53 slots differ. */
void fn_801B7BC4(Unk801B7BC4_P* p, const Unk80273498_Vec3* a, const Unk80273498_Vec3* b, int mode)
{
    if (!(p->mB84 > lbl_805CF944)) {
        int ten = 0xA;
        Unk8027C728_Goal* g = fn_802448F4(p, 2);
        g->m10 = ten;
        fn_8027C728(g);
        ((Unk8028B194*)g->m18)->fn_8028B194(*b);
        Unk80273498_Vec3 u = *a;
        ((Unk8027A84C*)g->m18)->fn_8027A898(&u);
        if (mode == 1) {
            int three = 3;
            ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = three;
            Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
            g104->m38 = three;
            ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = three;
            g104->m34 = three;
            ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
            g104->m40 = ten;
        } else {
            int two = 2;
            int five = 5;
            ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = two;
            Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
            g104->m38 = two;
            ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = two;
            g104->m34 = two;
            ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = five;
            g104->m40 = five;
        }
        Unk8027C728_Goal* h = g->m0;
        h->m10 = 2;
        fn_8027C728(h);
        ((Unk80287D70*)h->m18)->fn_80287DB8(0xF);
        fn_8027D33C(g);
    }
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
