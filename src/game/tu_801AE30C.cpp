/*
 * Game code, .text 0x801AE30C-0x801B23A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"
#include "game/tu_801AB63C.h"
#include "game/chooser.h"

void fn_801AE5F0(void* p);
void fn_801AE6A8(void* p);
void fn_801B113C(void* p);
int fn_801A7130(Unk8019F8C0_Owner* o, int i);
void fn_801B25E4(Unk801AB63C_P* p, int n);
void fn_801B2428(void* p);
int fn_801B1380(Unk801AB63C_P* p);
void fn_801B1FE8(void* p);
inline int Unk801AEA58_B(unsigned char* b, int i) { return b[i]; }
inline int Unk801AEA58_U8(Unk8019F8C0_Inner* a, int off) { return *((unsigned char*)a + off); }
int fn_801C1638(Unk8019F8C0_Owner* o, int i);
struct Unk801B1FE8_Q {
    char pad0[0x5D8];
    float m5D8;
};
Unk801B1FE8_Q* fn_801B6438(Unk801AB63C_P* p, int id);
int fn_801B5F4C(Unk801AB63C_P* p);
int fn_801B5FC4(void* p, int t);
int fn_801B20F0(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d);
extern float lbl_805CF6D8;


/* Script-command style classes (hash 0xE608C67F, size 0xB4, vtable 0x8065FB08;
 * hash 0xEA9F4BCE, size 0x88, vtable 0x8065FB68); slot 2 registers the attributes. */
class Unk801B03DC : public Unk8037B3E8 {
public:
    Unk801B03DC();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot8();
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    float m6C;
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
};

class Unk801B0B08 : public Unk8037B3E8 {
public:
    Unk801B0B08();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot8();
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
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
};

extern char lbl_805CF1B0[];
extern char lbl_805CF1B4[];
extern char lbl_805CF1C0[];
extern char lbl_805CF1D0[];
extern char lbl_805CF1DC[];
extern char lbl_805CF1E4[];
extern char lbl_805CF1F0[];
extern char lbl_805CF1FC[];
extern char lbl_805CF204[];
extern char lbl_805CF210[];
extern char lbl_805CF218[];
extern char lbl_805CF224[];
extern char lbl_805CF230[];
extern char lbl_805CF23C[];
extern char lbl_805CF248[];
extern char lbl_805CF254[];
extern char lbl_805CF260[];
extern char lbl_805CF268[];
extern char lbl_805CF274[];
extern char lbl_805CF280[];
extern char lbl_805CF28C[];
extern char lbl_805CF294[];
extern char lbl_805CF2A0[];
extern char lbl_805CF2AC[];
extern char lbl_805CF2B8[];
extern char lbl_805CF2C0[];
extern char lbl_805CF2CC[];
extern char lbl_805CF2D8[];
extern char lbl_805CF2E4[];
extern char lbl_805CF2F0[];
extern char lbl_805CF2FC[];
extern char lbl_805CF308[];
extern char lbl_805CF314[];
extern char lbl_805CF320[];
extern char lbl_805CF32C[];
extern char lbl_805CF338[];
extern char lbl_805CF344[];
extern char lbl_805CF354[];
extern char lbl_805CF368[];
extern char lbl_805CF37C[];
extern char lbl_805CF390[];
extern char lbl_805CF3A0[];
extern char lbl_805CF3B4[];
extern char lbl_805CF3C8[];
extern char lbl_805CF3DC[];
extern char lbl_805CF3EC[];
extern char lbl_805CF400[];
extern char lbl_805CF414[];
extern char lbl_805CF428[];
extern char lbl_805CF438[];
extern char lbl_805CF44C[];
extern char lbl_805CF460[];
extern char lbl_805CF474[];
extern char lbl_805CF480[];
extern char lbl_805CF490[];
extern char lbl_805CF49C[];
extern char lbl_805CF4AC[];
extern char lbl_805CF4BC[];
extern char lbl_805CF4C8[];
extern char lbl_805CF4D8[];
extern char lbl_805CF4E8[];
extern char lbl_805CF50C[];
extern char lbl_805CF510[];
extern char lbl_805CF51C[];
extern char lbl_805CF524[];
extern char lbl_805CF52C[];
extern char lbl_805CF534[];
extern char lbl_805CF540[];
extern char lbl_805CF548[];
extern char lbl_805CF550[];
extern char lbl_805CF558[];
extern char lbl_805CF560[];
extern char lbl_805CF568[];
extern char lbl_805CF570[];
extern char lbl_805CF578[];
extern char lbl_805CF588[];
extern char lbl_805CF590[];
extern char lbl_805CF598[];
extern char lbl_805CF5A0[];
extern char lbl_805CF5B0[];
extern char lbl_805CF5B8[];
extern char lbl_805CF5C0[];
extern char lbl_805CF5C8[];
extern char lbl_805CF5D8[];
extern char lbl_805CF5E0[];
extern char lbl_805CF5E8[];
extern char lbl_805CF5F0[];
extern char lbl_805CF600[];
extern char lbl_805CF608[];
extern char lbl_805CF610[];
extern char lbl_805CF618[];
extern char lbl_805CF628[];
extern char lbl_805CF634[];
extern char lbl_805CF640[];
extern char lbl_805CF64C[];
extern char lbl_805CF65C[];
extern char lbl_805CF668[];
extern char lbl_805CF674[];
extern char lbl_805CF680[];
extern char lbl_805CF688[];
extern char lbl_805CF690[];
extern char lbl_805CF698[];
extern char lbl_805CF6A0[];
extern char lbl_805CF6AC[];
extern char lbl_805CF6B4[];
extern char lbl_805CF6BC[];
extern int lbl_8068BEC4;
extern int lbl_8068BEC8;
extern int lbl_806EF9B4;

Unk801B03DC* fn_801B0AD0();
Unk801B0B08* fn_801B1090();

int fn_8006BE18(void* p);
void fn_801B445C(Unk801AB63C_P* p, int f);
int fn_801AED58(void* a, void* q);
void fn_801AE6A8(Unk801AB63C_P* p);
int fn_8014D8AC(void* a, int b, const char* c, int d);
int fn_80259C28(void* a, void* q);
extern char lbl_805CF058[];
extern float lbl_805CF08C;
extern float lbl_805CF098;

struct Unk801AE30C_Tbl {
    int m0;
    Unk801AB63C_E m4[2];
    Unk801AB63C_E mC_unused[1];
};
int fn_801AE2C0(Unk801AB63C_E* e);
void fn_801AE2A4(Unk801AB63C_E* e, int a, int b);
int fn_801AE2E8(Unk801AB63C_E* e, int v);
int fn_801AE2FC(Unk801AB63C_E* e);
int fn_801AE304(Unk801AB63C_E* e);
void fn_801AE2B0(Unk801AB63C_E* e);
int fn_80259C28(void* a, void* q);
int fn_801B2470(void* p, int i);
void fn_801B2480(void* p, int i, int v);
void fn_801B185C(Unk801AB63C_P* p);
int fn_801AEBB0(void* a, void* q);
int fn_801B19E8(Unk801AB63C_P* p, Unk801AB63C_Q* q);
int fn_801B5EDC(void* a, int b, int c);
Unk801AB63C_Q* fn_801B1DD8(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d, int e);
int fn_801B350C(Unk801AB63C_P* p, Unk801AB63C_Q* t, Unk801AB63C_Q* q, int d);
int fn_801B13D0(Unk801AB63C_P* p, Unk801AB63C_Q* q, Unk801AB63C_Q* t, int c);
int fn_801B1D60(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d);
int fn_802530E8(void* a);
int fn_801B371C(void* a, Unk801AB63C_Q* q, int c);
Unk801AB63C_Q* fn_801B21A4(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d);
int fn_801B3588(Unk801AB63C_P* p, Unk801AB63C_Q* t, Unk801AB63C_Q* q);
int fn_801B15EC(Unk801AB63C_P* p, Unk801AB63C_Q* q, Unk801AB63C_Q* t, int c);

struct Unk801AE30C_Pair {
    int m0;
    Unk801AB63C_E m4;
    Unk801AB63C_E mC;
};
/* Element of the pair table: its constructor is fn_801AE2B0 (loop in fn_801AE30C, evidence: do/while
 * post-decrement over two 8-byte entries starting at +4). */
struct Unk801AE30C_Elem : Unk801AB63C_E {
    Unk801AE30C_Elem() { fn_801AE2B0(this); }
};
struct Unk801AE30C_Clr {
    int m0;
    Unk801AE30C_Elem m4[2];
    Unk801AE30C_Clr();
};

struct Unk801AE30C_St {
    char pad0[0x14];
    int m14;
};

void fn_801AE360(Unk801AE30C_Clr* p);

Unk801AE30C_Clr::Unk801AE30C_Clr()
{
    fn_801AE360(this);
}

void fn_801AE360(Unk801AE30C_Clr* p)
{
    p->m0 = 0;
    for (int i = 0; i < 2; i++) {
        fn_801AE2B0(&p->m4[i]);
    }
}

void fn_801AE3A8(Unk801AE30C_Pair* p, int* a, int* b)
{
    *a = fn_801AE2FC(&p->m4);
    *b = fn_801AE304(&p->m4);
}

void fn_801AE3F0(Unk801AE30C_Tbl* t, int a, int b)
{
    if (a != 0 && b != 0) {
        int i = 0;
        Unk801AB63C_E* e = t->m4;
        while (i <= 1 && fn_801AE2C0(e) != 0) {
            if (fn_801AE304(e) == b && fn_801AE2FC(e) == a) {
                return;
            }
            e++;
            i++;
        }
        if (i <= 1) {
            fn_801AE2A4(e, a, b);
            t->m0 += 1;
        }
    }
}

void fn_801AE494(Unk801AE30C_Pair* p, int* a, int* b)
{
    *a = fn_801AE2FC(&p->mC);
    *b = fn_801AE304(&p->mC);
}

/* near-miss: same loop-shape problem; retail keeps a second pointer copy (r29) alive across the call (35 vs 36 insns). */
void fn_801AE4DC(Unk801AE30C_Tbl* t, int v)
{
    if (v != 0) {
        Unk801AB63C_E* e = t->m4;
        for (int i = 0; i <= 1; i++, e++) {
            if (fn_801AE2E8(e, v) != 0) {
                if (i == 0) {
                    t->m4[0] = t->m4[1];
                    fn_801AE2B0(&t->m4[1]);
                    return;
                }
                fn_801AE2B0(e);
                break;
            }
        }
    }
}

void fn_801AE5F0(void* pp)
{
    Unk801AB63C_P* p = (Unk801AB63C_P*)pp;
    fn_801AE6A8(p);
    int z = 0;
    char* s = lbl_805CF058;
    p->m20[0] = z;
    p->m20[1] = z;
    p->m20[2] = z;
    p->m20[3] = z;
    p->m20[4] = z;
    p->m20[5] = z;
    p->m20[6] = z;
    p->m20[7] = z;
    p->m18 = fn_8014D8AC(p->m8->m554, 2, s, 0x52) + 1;
    p->m1C = fn_8014D8AC(p->m8->m554, 2, s, 0x53) + 1;
}

Unk801AE5C0::Unk801AE5C0(int a, int b) : Unk801B5A44(a, b)
{
    m10 = fn_801B1090();
    mC = fn_801B0AD0();
    Init();
}

Unk801AE5C0::~Unk801AE5C0() {}

void fn_801AE688(void* p)
{
    fn_801AE5F0(p);
}

void fn_801AE6A8(Unk801AB63C_P* p)
{
    char* s = lbl_805CF058;
    p->m14 = -1;
    float k = lbl_805CF08C;
    p->m40 = (float)(unsigned)fn_8014D8AC(p->m8->m554, 0xf4240, s, 0x63) * k * lbl_805CF098;
    p->m44 = fn_8014D8AC(p->m8->m554, 0x64, s, 0x64);
}

/* near-miss: same code; retail reloads m14[2].m8 for the second team index (subfic/adde), ours shares the first load
 * and branches (85 vs 86 insns). */
int fn_801AEA58(Unk801AB63C_P* p)
{
    int r = -1;
    int a = 1;
    if (fn_801C1638(p->m8, 0xa) == 0) {
        a = 0;
    }
    int b = 1;
    if (fn_801C1638(p->m8, 0xc) == 0) {
        b = 0;
    }
    Unk8019F8C0_Owner* o = p->m8;
    Unk8019F8C0_Inner* m = o->m6F8->m14;
    int f = 0;
    if (m[2].m8 != 0) {
        f = 1;
    }
    Unk8019F8C0_Inner* ia = m + f;
    int sa = 0;
    for (int i = 0; i < 128; i++) {
        sa += Unk801AEA58_B(ia->m1B4, (unsigned char)i);
    }
    Unk8019F8C0_Inner* ib = m + (m[2].m8 == 0);
    int sb = 0;
    for (int i = 0; i < 128; i++) {
        sb += Unk801AEA58_B(ib->m1B4, (unsigned char)i);
    }
    int d = sa - sb;
    int x = Unk801AEA58_U8(m, 0x1cca);
    int y = Unk801AEA58_U8(m, 0x1cc9);
    if (a != 0) {
        if (x == 2 || (x == 1 && (unsigned)fn_8014D8AC(o->m554, 0x64, lbl_805CF058, 0x133) <= 0x31)) {
            r = 0x20;
        }
    }
    if (y <= 1 && b != 0 && d > -4) {
        r = 0x10;
    }
    return r;
}

void fn_801AE75C() {}

void fn_801B032C() {}

void fn_801B0330() {}

void fn_801B0334(void* p)
{
    fn_801AE6A8(p);
}

void fn_801B0354(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    if (q != 0) {
        Unk8019F8C0_Pl* pl = p->m8->m700;
        if (fn_80259C28(pl->m3B4, q) != 0) {
            p->m20[q->m708] = p->m20[q->m708] + 1;
        }
    }
}

void fn_801B03B8(Unk801AE30C_St* p)
{
    int s = p->m14;
    if ((unsigned)(s - 1) <= 1 || s == 4) {
        p->m14 = 0;
    }
}

Unk801B03DC::Unk801B03DC() : Unk8037B3E8(0xE608C67Fu) {}

void Unk801B03DC::fn_vslot2()
{
    fn_8037B7E4(lbl_805CF1B0);
    fn_8037B494(lbl_805CF1B4, &m4, lbl_805CF1C0, 0);
    fn_8037B494(lbl_805CF1D0, &m8, lbl_805CF1C0, 0);
    fn_8037B494(lbl_805CF1DC, &mC, lbl_805CF1C0, 0);
    fn_8037B494(lbl_805CF1E4, &m10, lbl_805CF1C0, 0);
    fn_8037B494(lbl_805CF1F0, &m14, lbl_805CF1C0, 0);
    fn_8037B7E8(lbl_805CF1FC);
    fn_8037B50C(lbl_805CF204, &m18, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF218, &m1C, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF224, &m84, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF1FC);
    fn_8037B7E8(lbl_805CF230);
    fn_8037B50C(lbl_805CF23C, &m20, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF248, &m24, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF254, &m80, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF230);
    fn_8037B7E8(lbl_805CF260);
    fn_8037B50C(lbl_805CF268, &m28, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF274, &m2C, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF280, &m88, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF260);
    fn_8037B7E8(lbl_805CF28C);
    fn_8037B50C(lbl_805CF294, &m30, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF2A0, &m34, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF2AC, &m8C, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF28C);
    fn_8037B7E8(lbl_805CF2B8);
    fn_8037B50C(lbl_805CF2C0, &m38, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF2CC, &m3C, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF2D8, &m90, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF2B8);
    fn_8037B7E8(lbl_805CF2E4);
    fn_8037B50C(lbl_805CF2F0, &m40, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF2FC, &m44, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF308, &m94, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF2E4);
    fn_8037B7E8(lbl_805CF314);
    fn_8037B50C(lbl_805CF320, &m48, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF32C, &m4C, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF338, &m98, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF314);
    fn_8037B7E8(lbl_805CF344);
    fn_8037B50C(lbl_805CF354, &m50, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF368, &m54, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF37C, &m7C, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF344);
    fn_8037B7E8(lbl_805CF390);
    fn_8037B50C(lbl_805CF3A0, &m58, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF3B4, &m5C, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF3C8, &m78, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF390);
    fn_8037B7E8(lbl_805CF3DC);
    fn_8037B50C(lbl_805CF3EC, &m60, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF400, &m64, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF414, &m74, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF3DC);
    fn_8037B7E8(lbl_805CF428);
    fn_8037B50C(lbl_805CF438, &m68, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF44C, &m6C, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF460, &m70, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF428);
    fn_8037B7E8(lbl_805CF474);
    fn_8037B494(lbl_805CF480, &m9C, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF49C, &mA0, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF4AC, &mA4, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF474);
    fn_8037B7E8(lbl_805CF4BC);
    fn_8037B494(lbl_805CF4C8, &mA8, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF4D8, &mAC, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF4E8, &mB0, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF4BC);
}

Unk8037B3E8* Unk801B03DC::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk801B03DC;
}

void Unk801B03DC::fn_vslot8() {}

Unk801B03DC* fn_801B0AD0()
{
    return (Unk801B03DC*)fn_8037C7FC()->fn_8037CE98(0xE608C67F, lbl_8068BEC4, 0);
}

Unk801B0B08::Unk801B0B08() : Unk8037B3E8(0xEA9F4BCEu) {}

void Unk801B0B08::fn_vslot2()
{
    fn_8037B7E4(lbl_805CF50C);
    fn_8037B7E8(lbl_805CF510);
    fn_8037B50C(lbl_805CF51C, &m4, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF524, &m8, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF52C, &m4C, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF510);
    fn_8037B7E8(lbl_805CF534);
    fn_8037B50C(lbl_805CF540, &mC, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF548, &m10, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF550, &m50, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF534);
    fn_8037B7E8(lbl_805CF558);
    fn_8037B50C(lbl_805CF560, &m14, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF568, &m18, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF570, &m5C, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF558);
    fn_8037B7E8(lbl_805CF578);
    fn_8037B50C(lbl_805CF588, &m1C, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF590, &m20, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF598, &m54, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF578);
    fn_8037B7E8(lbl_805CF5A0);
    fn_8037B50C(lbl_805CF5B0, &m24, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF5B8, &m28, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF5C0, &m58, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF5A0);
    fn_8037B7E8(lbl_805CF5C8);
    fn_8037B50C(lbl_805CF5D8, &m2C, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF5E0, &m30, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF5E8, &m60, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF5C8);
    fn_8037B7E8(lbl_805CF5F0);
    fn_8037B50C(lbl_805CF600, &m34, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF608, &m38, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF610, &m64, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF5F0);
    fn_8037B7E8(lbl_805CF618);
    fn_8037B50C(lbl_805CF628, &m3C, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF634, &m40, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF640, &m68, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF618);
    fn_8037B7E8(lbl_805CF64C);
    fn_8037B50C(lbl_805CF65C, &m44, lbl_805CF210, 0);
    fn_8037B50C(lbl_805CF668, &m48, lbl_805CF210, 0);
    fn_8037B494(lbl_805CF674, &m6C, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF64C);
    fn_8037B7E8(lbl_805CF680);
    fn_8037B494(lbl_805CF688, &m70, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF690, &m74, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF698, &m78, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF680);
    fn_8037B7E8(lbl_805CF6A0);
    fn_8037B494(lbl_805CF6AC, &m7C, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF6B4, &m80, lbl_805CF490, 0);
    fn_8037B494(lbl_805CF6BC, &m84, lbl_805CF1C0, 0);
    fn_8037B830(lbl_805CF6A0);
}

Unk8037B3E8* Unk801B0B08::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk801B0B08;
}

void Unk801B0B08::fn_vslot8() {}

Unk801B0B08* fn_801B1090()
{
    return (Unk801B0B08*)fn_8037C7FC()->fn_8037CE98(0xEA9F4BCE, lbl_8068BEC8, 0);
}

Unk801B10C8::Unk801B10C8(int a, int b) : Unk801B2490(a, b)
{
    Init();
}

Unk801B10C8::~Unk801B10C8() {}

void Unk801B10C8::Init()
{
    Setup();
    fn_801B2428(this);
}

void fn_801B1170(void* p)
{
    fn_801B113C(p);
}

void fn_801B1190(Unk801AB63C_P* p)
{
    int f = 0;
    Unk8019F8C0_Inner* m = p->m8->m6F8->m14;
    if (m[2].m8 != 0) {
        f = 1;
    }
    Unk8019F8C0_Inner* t = &m[f];
    unsigned char b = *((unsigned char*)&t->m168.mC + 3);
    if (fn_801B2470(p, f) != b) {
        fn_801B2480(p, f, b);
        if (fn_801B1380(p) == 1) {
            fn_801B185C(p);
        }
    }
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

void fn_801B131C(Unk801AB63C_P* p)
{
    if (fn_8006BE18(p->m8->m6F8) == 0) {
        int f = 0;
        if (p->m8->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        fn_801B445C(p, f);
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

int fn_801B17F0(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    Unk8019F8C0_Pl* pl = p->m8->m700;
    if (fn_801AED58(pl->m3C0, q) == 8 || fn_801AEBB0(p->m8->m700->m3C0, q) == 8) {
        return 1;
    }
    return 0;
}

void fn_801B1B88(Unk801AB63C_P* p, Unk801AB63C_Q* q)
{
    if (fn_801B19E8(p, q) != 0) {
        int v = fn_801B5EDC(p, q->m708, 0);
        fn_801B1D60(p, q, 2, v > 3);
    }
}

int fn_801B1D60(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d)
{
    Unk801AB63C_Q* t = fn_801B1DD8(p, q, c, d, 0);
    if (t != 0 && fn_801B350C(p, t, q, 0) == 1) {
        return fn_801B13D0(p, q, t, c);
    }
    return 0;
}

void fn_801B1FE8(void* pp)
{
    Unk801AB63C_P* p = (Unk801AB63C_P*)pp;
    if (fn_801B5F4C(p) <= 1) {
        int n = fn_801B5FC4(p, 3);
        int side = 1;
        if (fn_801B5F4C(p) <= 0) {
            side = 2;
        }
        if (fn_801B6438(p, 2) != 0) {
            n++;
        }
        Unk801B1FE8_Q* a = fn_801B6438(p, 1);
        if (a != 0) {
            n++;
            if ((unsigned)n <= 1) {
                if (!(a->m5D8 >= lbl_805CF6D8)) {
                    fn_801B20F0(p, (Unk801AB63C_Q*)a, side, 0);
                }
            }
        }
        Unk801B1FE8_Q* b = fn_801B6438(p, 0);
        if (b != 0) {
            if ((unsigned)(n + 1) <= 1) {
                if (!(b->m5D8 >= lbl_805CF6D8)) {
                    fn_801B20F0(p, (Unk801AB63C_Q*)b, side, 0);
                }
            }
        }
    }
}

int fn_801B20F0(Unk801AB63C_P* p, Unk801AB63C_Q* q, int c, int d)
{
    if (q != 0 && fn_802530E8((char*)q + 0x480) != 0 && fn_801B371C(p, q, 1) != 0) {
        return 0;
    }
    Unk801AB63C_Q* t = fn_801B21A4(p, q, c, d);
    if (t != 0 && fn_801B3588(p, t, q) == 1) {
        return fn_801B15EC(p, q, t, c);
    }
    return 0;
}
