/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001D7F8-0x8001E444 only: every data object is extern by its lbl_ name.
 *
 * Methods of Unk8001CE80 (include/game/tu_8001CACC.h), the same class as the
 * tail of tu_8001CACC.cpp: thin forwarders that pass a few fields, or a sub-object
 * address, to functions in 0x8004xxxx.
 */
#include "game/tu_8001CACC.h"

float fn_8025356C(char* p);
float fn_80253434(char* p);
int fn_80046380(float a, float b);
void fn_8004335C(int a);
void fn_80044580(int a, int b, int c);
void fn_80044E20(Unk8001CE80* o);
void fn_80043218(int a);
int fn_8025416C(char* p, int a);
void fn_80042E58(int a);
void fn_80045DD8(int a);
void fn_800440E8(int a, int b, int c, Unk8001D47C_Level* d);
void fn_80043DF0(Unk8001D47C_Level* a);
void fn_80043664(int a);
void fn_80043D70(int a);
int fn_80043B00(int a, int b, int c);
void fn_80043DAC(int a);
void fn_800471B0(int a);
int fn_80075E7C(int a);
void fn_800466E4(int a, int b);

struct Unk8061E978 {
    int m0;
    int m4;
};
extern Unk8061E978* lbl_8061E978;

int Unk8001CE80::fn_8001D7F8()
{
    return fn_80046380(fn_8025356C((char*)m130 + 0x480), fn_80253434((char*)m130 + 0x480));
}

int Unk8001CE80::fn_8001D850()
{
    int v = fn_80046380(fn_8025356C((char*)m130 + 0x480), fn_80253434((char*)m130 + 0x480));
    int r = 0;
    if (v == 1) {
        r = 1;
    } else if (v == 2) {
        r = 2;
    } else if (v == 4) {
        r = 4;
    }
    return r;
}

int fn_80045348(int a, int b);
extern "C" int fn_801DC570(int a);
extern "C" int fn_801DC184(int a, int b);

int Unk8001CE80::fn_8001D8DC()
{
    int obj = 0;
    Unk8001D8DC_Outer* o = m130->m44C->m700;
    int a = o->m3B8;
    Unk8001D8DC_Inner* in = o->m3A4;
    int id = fn_801DC570(a);
    int c = in->m108;
    if (id != 0) {
        obj = fn_801DC184(a, id);
    }
    int r = fn_80045348(obj, c);
    if (obj == 0 && c == 1 && m444 == 0xc && m44C == 1) {
        r = 0;
    }
    return r;
}

int fn_80045044(int a, int b, int c, int d, int e, int f);

int Unk8001CE80::fn_8001D974()
{
    Unk8001D974_Ent* e = 0;
    for (int i = m100 - 1; i >= 0; i--) {
        if (m70[i].m0 == m3B0) {
            e = &m70[i];
            break;
        }
    }
    if (e != 0) {
        unsigned t = m408 - 4;
        int c = t <= 3;
        int d = 0;
        if (m458 == 4 || m458 == 6) {
            d = 1;
        }
        return fn_80045044(e->m10, *(int*)&m3B8, c, d, e->mC, m444);
    }
    return 0;
}

void Unk8001CE80::fn_8001DA28()
{
    fn_8004335C(m444);
}

void Unk8001CE80::fn_8001DA4C()
{
    fn_80044580(m458, m44C, m3F8);
}

void Unk8001CE80::fn_8001DA7C()
{
    fn_80044E20(this);
}

extern "C" void fn_80235BE0(float* out, int a, ...);
extern "C" int fn_8022EA7C(int a, float* v, float s);
int fn_80043940(float b, float c, int a);

int Unk8001CE80::fn_8001DA9C()
{
    float v[2];
    Unk8001D8DC_Outer* o = m130->m44C->m700;
    int h = o->m3B0;
    fn_80235BE0(v, h);
    if (fn_8022EA7C(h, v, 1.0f) == 1) {
        return 0;
    }
    return fn_80043940(m288.x, m288.y, ((Unk8001D780_VT*)m3B0)->s24());
}

void Unk8001CE80::fn_8001DB4C()
{
    fn_80043218(m48);
}

void Unk8001CE80::fn_8001DB70()
{
    fn_80042E58(fn_8025416C((char*)m3B0 + 0x588, 0));
}

void Unk8001CE80::fn_8001DBA0()
{
    unsigned char* e = m130->m44C->m6F8->m14 + m3B4 * 0xe64;
    fn_80045DD8(e[0x177]);
}

struct Unk80043884_Obj;
int fn_800437DC(int a, Unk80043884_Obj* o);
extern "C" char* fn_801A497C(Unk8001D47C_Mid* w, int a, int b);

/* near-miss: 30/30 insns, 2 slots swapped: retail issues `li r4,0` before `addi r3,r3,0x588` after the join (ours: addi first).
 * Tried a pointer cast, an inline wrapper taking the pointer, a ternary and per-arm calls. */
void Unk8001CE80::fn_8001DBE0()
{
    char* p;
    if (fn_800437DC(0, (Unk80043884_Obj*)this) != 0) {
        p = fn_801A497C(m130->m44C, 0, 0);
    } else {
        p = fn_801A497C(m130->m44C, 1, 0);
    }
    fn_80042E58(fn_8025416C(p + 0x588, 0));
}

void Unk8001CE80::fn_8001DC58()
{
    fn_80042E58(fn_8025416C((char*)m130 + 0x588, 0));
}

void Unk8001CE80::fn_8001DC88()
{
    Unk8001D47C_Level* l = m130->m44C->m6F8;
    unsigned char* t = l->m14;
    fn_800440E8(*(int*)(t + 0x198), *(int*)(t + 0xffc), l->mC->m88, l);
}

void Unk8001CE80::fn_8001DCCC()
{
    fn_80043DF0(m130->m44C->m6F8);
}

extern "C" int fn_8018CE28(void* p, int v, int* buf);
extern "C" int fn_8018CF7C(void* p);
int fn_80043C60(int a, int b, int c);

void Unk8001CE80::fn_8001DCF8()
{
    float v[2];
    int a = -1;
    int b = 0;
    Unk8001D47C_Mid* w = m130->m44C;
    void* pos = w->m6CC;
    Unk8001D8DC_Outer* o = w->m700;
    int h = o->m3B0;
    fn_80235BE0(v, h);
    if (fn_8022EA7C(h, v, 1.0f) == 1) {
        a = fn_8018CE28(pos, ((Unk8001D780_VT*)m3B0)->s24(), 0);
        b = fn_8018CF7C(pos);
    }
    int c = 0;
    if ((unsigned)(m408 - 4) <= 3 && m40C != 0) {
        c = 1;
    }
    fn_80043C60(a, b, c);
}

void Unk8001CE80::fn_8001DDD8()
{
    fn_80043664(m404);
}

int fn_80044744(int a, int b);

void Unk8001CE80::fn_8001DDFC()
{
    unsigned char* t = m130->m44C->m6F8->m14;
    int o0 = m3B4 * 0xE64;
    int a = Unk8001D47C_SumRow((Unk8001D47C_Row*)(t + o0));
    int z = m3B4 == 0;
    int o1 = z * 0xE64;
    int b = Unk8001D47C_SumRow((Unk8001D47C_Row*)(t + o1));
    fn_80044744(a, b);
}

void Unk8001CE80::fn_8001DE9C()
{
    fn_80043D70(m4D4);
}

struct Unk8001DEC0_St {
    int m0;
    unsigned m4;
    char pad8[0x30];
    int m38;
    char pad3C[8];
    int m44;
};
struct Unk8001DEC0_Pl {
    char pad0[0x5CC];
    int m5CC;
};
inline Unk8001DEC0_St* Unk8001DEC0_StOf(Unk8001DEC0_Pl* p)
{
    return (Unk8001DEC0_St*)((char*)p + 0x58C);
}
struct Unk80043B00_Pl;
int fn_80043B00(Unk80043B00_Pl* a, Unk80043B00_Pl* b, Unk80043B00_Pl* c);

/* near-miss (99.95%, all slots match): retail's first null test of m3B0 branches straight to the
 * end (jump-threaded) while the second test, at the join of the failed conditions, keeps its own
 * cmpwi. Here the first beq goes to that second test. Re-reading m3B0 in the second operand keeps
 * the compare; the plain `p && .. || p && ..` form threads the jump but then drops the compare
 * (cr7 reuse). Also tried: goto chain, else-if, inline Ok/Any helpers, a copy of p. */
extern "C" void fn_8001DEC0(Unk8001CE80* x)
{
    Unk8001DEC0_Pl* sp[4] = { 0, 0, 0, 0 };
    if (x->m400 == 1) {
        sp[0] = (Unk8001DEC0_Pl*)x->m3B0;
        if (x->m110 != 0)
            sp[1] = (Unk8001DEC0_Pl*)x->m110;
        else
            sp[1] = (Unk8001DEC0_Pl*)x->m118;
        if (x->m110 != 0 && x->m118 != 0)
            sp[2] = (Unk8001DEC0_Pl*)x->m118;
        else
            sp[2] = (Unk8001DEC0_Pl*)x->m120;
    } else {
        Unk8001DEC0_Pl* p = (Unk8001DEC0_Pl*)x->m3B0;
        int idx;
        if ((p && !(Unk8001DEC0_StOf(p)->m4 & 0x20000000) && Unk8001DEC0_StOf(p)->m44 != 2
             && (idx = Unk8001DEC0_StOf(p)->m38) > 0 && idx <= 2)
            || ((Unk8001DEC0_Pl*)x->m3B0 && (idx = ((Unk8001DEC0_Pl*)x->m3B0)->m5CC) != -1)) {
            sp[idx] = p;
        }
        for (int i = 0; i < x->m100; i++) {
            Unk8001D974_Ent* e = &x->m70[i];
            Unk8001DEC0_Pl* q = (Unk8001DEC0_Pl*)e->m0;
            if (q && !(Unk8001DEC0_StOf(q)->m4 & 0x20000000) && Unk8001DEC0_StOf(q)->m44 != 2 && e->m8 > 0 && e->m8 <= 2) {
                sp[e->m8] = q;
            } else if (((Unk8001DEC0_Pl*)e->m0)->m5CC != -1) {
                sp[q->m5CC] = q;
            }
        }
    }
    fn_80043B00((Unk80043B00_Pl*)sp[0], (Unk80043B00_Pl*)sp[1], (Unk80043B00_Pl*)sp[2]);
}

void Unk8001CE80::fn_8001E054()
{
    fn_80043B00(m110, m118, m120);
}

int Unk8001CE80::fn_8001E084()
{
    if (m48 > 0) {
        return 0;
    }
    return fn_80043B00(m110, m118, m120);
}

void Unk8001CE80::fn_8001E0C8()
{
    int v = m130->m44C->m6F8->mC->m80;
    if (v == 1) {
        v = 2;
    }
    fn_80043DAC(v);
}

void fn_8001E108()
{
    fn_800471B0(lbl_8061E978->m4);
}

int fn_8040ABA0();
int fn_8004712C(float x);
extern float lbl_805A5168[];

int Unk8001CE80::fn_8001E134()
{
    const float th = 0.15f;
    Unk8001D47C_Level* l = m130->m44C->m6F8;
    Unk8001E0C8_Rec* rec = l->mC;
    int b = rec->m7C;
    int a = rec->m2C;
    float t = (float)(fn_8040ABA0() % 100) * 0.01f;
    int off = ((unsigned)b >> 24 & 0xFF) * 8 - 16;
    off = off + a * 64;
    char* tb = (char*)lbl_805A5168;
    char* tb4 = tb + 4;
    float val = t * (*(float*)(tb4 + off) - *(float*)(tb + off)) + *(float*)(tb + off);
    int r = fn_8004712C(val);
    if ((unsigned)(l->mC->m80 - 1) <= 1) {
        if (!((float)(fn_8040ABA0() % 100) * 0.01f >= th) && r != 4)
            r += r;
    }
    return r;
}

void Unk8001CE80::fn_8001E294()
{
    fn_800466E4(fn_80075E7C(m130->m44C->m6F8->mC->m24), m130->m44C->m6F8->mC->m80);
}

void Unk8001CE80::fn_8001E2EC()
{
    fn_80042E58(fn_8025416C((char*)m3B0 + 0x588, 0));
}

void Unk8001CE80::fn_8001E31C()
{
    fn_80042E58(fn_8025416C((char*)m130 + 0x588, 0));
}

float fn_80254474(char* p, int idx, int h);
void fn_80046A00(float a);
void fn_80046ACC(float a);

void Unk8001CE80::fn_8001E34C()
{
    float a = fn_80254474((char*)m3B0 + 0x588, 0, 0);
    float b = fn_80254474((char*)m3B0 + 0x588, 1, 0);
    float m = a >? b;
    fn_80046A00(m);
}

void Unk8001CE80::fn_8001E3C8()
{
    float a = fn_80254474((char*)m3B0 + 0x588, 0, 1);
    float b = fn_80254474((char*)m3B0 + 0x588, 1, 1);
    float m = a >? b;
    fn_80046ACC(m);
}
