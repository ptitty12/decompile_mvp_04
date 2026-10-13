/*
 * Game code, .text 0x802362A8-0x8023A6C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_802362A8.h"

extern const char lbl_805D7380[];
extern const char lbl_805D7384[];
extern const char lbl_805D7394[];
extern const char lbl_805D73A0[];
extern const char lbl_805D73AC[];
extern const char lbl_805D73B8[];
extern const char lbl_805D73BC[];
extern const char lbl_805D73CC[];
extern const char lbl_805D73D0[];
extern const char lbl_805D73E8[];
extern const char lbl_805D7400[];
extern const char lbl_805D740C[];
extern const char lbl_805D7428[];
extern const char lbl_805D7440[];
extern const char lbl_805D7458[];
extern const char lbl_805D7470[];
extern const char lbl_805D748C[];
extern const char lbl_805D74A4[];
extern const char lbl_805D74C0[];
extern const char lbl_805D74D8[];
extern const char lbl_805D74F0[];
extern const char lbl_805D7508[];
extern const char lbl_805D7524[];
extern const char lbl_805D753C[];
extern const char lbl_805D7558[];
extern const char lbl_805D7570[];
extern const char lbl_805D7588[];
extern const char lbl_805D75A0[];
extern const char lbl_805D75BC[];
extern const char lbl_805D75D4[];
extern const char lbl_805D75F0[];
extern const char lbl_805D7608[];
extern const char lbl_805D7620[];
extern const char lbl_805D7638[];
extern const char lbl_805D7644[];
extern const char lbl_805D7660[];
extern const char lbl_805D7684[];
extern const char lbl_805D7698[];
extern int lbl_8068CA8C;
extern const float lbl_805D7C18;
extern const char lbl_805D7978[];
extern float lbl_8061D220;
extern const float lbl_805D7B1C;
extern const char lbl_80660E00[];
extern const char lbl_80660E30[];
extern const char lbl_80660E48[];
extern const float lbl_805D7A94;
extern const float lbl_805D7A98;
struct Unk80270BA0_X;
float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2);
extern "C" float fn_8024F048(char* a, int b, int c, int d, int e);
extern "C" float fn_801A0AA8(Unk8022FE34_Ctx* c, float a, float b);

inline float Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

cPitcherTunables::cPitcherTunables() : Unk8037B3E8(0x1011A855)
{
}

void cPitcherTunables::fn_vslot2()
{
    fn_8037B7E4(lbl_805D7380);
    fn_8037B50C(lbl_805D7384, &m24, lbl_805D7394, 0);
    fn_8037B50C(lbl_805D73A0, &m1C, lbl_805D73AC, lbl_805D73B8);
    fn_8037B50C(lbl_805D73BC, &m20, lbl_805D73AC, lbl_805D73CC);
    fn_8037B7E8(lbl_805D73D0);
    fn_8037B50C(lbl_805D73E8, &m28, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D740C, &m2C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7428, &m30, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7440, &m34, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7458, &m68, lbl_805D7400, 0);
    fn_8037B830(lbl_805D73D0);
    fn_8037B7E8(lbl_805D7470);
    fn_8037B50C(lbl_805D748C, &m38, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74A4, &m3C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74C0, &m40, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74D8, &m44, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74F0, &m6C, lbl_805D7400, 0);
    fn_8037B830(lbl_805D7470);
    fn_8037B7E8(lbl_805D7508);
    fn_8037B50C(lbl_805D7524, &m48, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D753C, &m4C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7558, &m50, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7570, &m54, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7588, &m70, lbl_805D7400, 0);
    fn_8037B830(lbl_805D7508);
    fn_8037B7E8(lbl_805D75A0);
    fn_8037B50C(lbl_805D75BC, &m58, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D75D4, &m5C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D75F0, &m60, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7608, &m64, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7620, &m74, lbl_805D7400, 0);
    fn_8037B830(lbl_805D75A0);
    fn_8037B728(lbl_805D7638, lbl_805D7644, &m4, (int)lbl_805D7660);
    fn_8037B728(lbl_805D7638, lbl_805D7684, &m10, (int)lbl_805D7698);
}

Unk8037B3E8* cPitcherTunables::fn_vslot5()
{
    return new (lbl_806EF9B4) cPitcherTunables;
}

void cPitcherTunables::fn_vslot8() {}

void fn_802366B0()
{
    fn_8037C7FC()->fn_8037CE98(0x1011A855, lbl_8068CA8C, 0);
}

/*
 * Unk80236ABC_Quad: four corners built from two opposite corners (fn_80236ABC).
 * Evidence: offsets 0x0/0x4/0x2C ints, V2 corners at 0xC/0x14/0x1C/0x24.
 */
struct Unk80236ABC_Quad {
    int m0;
    int m4;
    int m8;
    Unk8022FE34_V2 mC;
    Unk8022FE34_V2 m14;
    Unk8022FE34_V2 m1C;
    Unk8022FE34_V2 m24;
    int m2C;
    void fn_80236B8C();
};
inline Unk8022FE34_V2 Unk80236ABC_Mk(float x, float y)
{
    Unk8022FE34_V2 r;
    r.a = x;
    r.b = y;
    return r;
}
void fn_80236ABC(Unk80236ABC_Quad* self, Unk8022FE34_V2 a, Unk8022FE34_V2 b, int p3, int p4, int p5)
{
    self->mC = a;
    self->m14 = Unk80236ABC_Mk(a.a, b.b);
    self->m1C = b;
    self->m24 = Unk80236ABC_Mk(b.a, a.b);
    self->m0 = p4;
    self->m4 = p3;
    self->m2C = p5;
    self->fn_80236B8C();
}

void Unk80236ABC_Quad::fn_80236B8C() {}

char* Unk802362A8_Slots::fn_80236B90()
{
    return (char*)this + 0x268;
}

char* Unk802362A8_Slots::fn_80236B98()
{
    return (char*)this + 0x29C;
}

char* Unk802362A8_Slots::fn_80236BA0(int k)
{
    int idx;
    if (k == 6) {
        int a[3] = { 1, 5, 7 };
        idx = a[m90->m554->fn_8014D8AC(3, lbl_805D7978, 0xCA)];
    } else if (k == 7) {
        int a[2] = { 3, 4 };
        idx = a[m90->m554->fn_8014D8AC(2, lbl_805D7978, 0xD1)];
    } else {
        int a[3] = { 2, 6, 8 };
        idx = a[m90->m554->fn_8014D8AC(3, lbl_805D7978, 0xD7)];
    }
    return (char*)this + (idx * 0x34 + 0x94);
}

/* near-miss: retail presets li r3,0 and ends in a shared 'li r3,0; blr'; case 6 then returns through beqlr.
   Tried return-chain, int r preset (39 vs 41 insns) and empty-case-6 forms */
struct Unk80236C9C_P {
    int a;
    int b;
};
extern Unk80236C9C_P lbl_8060558C;
void fn_802366E8(char* slot, Unk8014D8AC_Ctx* c, Unk80236C9C_P* r, int flag);
char* fn_80236DB0(Unk802362A8_Slots* s, int k);
Unk80236C9C_P fn_80236C9C(Unk802362A8_Slots* s, int k)
{
    Unk80236C9C_P r = lbl_8060558C;
    switch (k) {
    case 1:
        fn_802366E8(fn_80236DB0(s, 1), s->m90, &r, 1);
        break;
    case 0:
        fn_802366E8((char*)s + 0x94, s->m90, &r, 0);
        break;
    case 2:
        break;
    case 3:
    case 4:
    case 5:
        fn_802366E8(fn_80236DB0(s, k), s->m90, &r, 1);
        break;
    case 6:
    case 7:
    case 8:
        fn_802366E8(s->fn_80236BA0(k), s->m90, &r, 1);
        break;
    case 9:
        fn_802366E8(s->fn_80236B90(), s->m90, &r, 1);
        break;
    case 10:
        fn_802366E8(s->fn_80236B98(), s->m90, &r, 1);
        break;
    }
    return r;
}

char* fn_80236DB0(Unk802362A8_Slots* s, int k)
{
    int idx = 0;
    if (k <= 1) {
        return (char*)s + (s->m90->m554->fn_8014D8AC(8, lbl_805D7978, 0x11C) * 0x34 + 0xC8);
    }
    if (k == 5 && s->m8C > 0) {
        idx = s->m58[s->m90->m554->fn_8014D8AC(s->m8C, lbl_805D7978, 0x123)];
    } else if ((unsigned)(k - 4) <= 1 && s->m88 > 0) {
        idx = s->m2C[s->m90->m554->fn_8014D8AC(s->m88, lbl_805D7978, 0x128)];
    } else if ((unsigned)(k - 3) <= 2 && s->m84 > 0) {
        idx = s->m0[s->m90->m554->fn_8014D8AC(s->m84, lbl_805D7978, 0x12D)];
    } else if (k == 3 && s->m84 == 0) {
        if (s->m88 > 0)
            idx = s->m2C[s->m90->m554->fn_8014D8AC(s->m88, lbl_805D7978, 0x134)];
        else
            idx = s->m58[s->m90->m554->fn_8014D8AC(s->m8C, lbl_805D7978, 0x139)];
    }
    return (char*)s + (idx * 0x34 + 0x94);
}

int fn_80236F34(void* p, int k)
{
    switch (k) {
    case 2:
        return 5;
    case 3:
        return 1;
    case 4:
        return 7;
    case 5:
        return 3;
    case 6:
        return 0;
    case 7:
        return 4;
    case 8:
        return 6;
    case 9:
        return 2;
    case 10:
        return 8;
    }
    return 0;
}

int fn_801D7A3C(void* p, int k);
inline void Unk80236FD8_Put(char* b, int off, int v)
{
    *(int*)(b + off) = v;
}
void fn_80236FD8(Unk802362A8_Slots* s)
{
    for (int i = 0; i < 11; i++) {
        s->m0[i] = -1;
        s->m2C[i] = -1;
        s->m58[i] = -1;
    }
    s->m84 = 0;
    s->m88 = 0;
    s->m8C = 0;
    char* base = (char*)s->m90->m700->m3A4 + 8;
    int k = 2;
    int off = 0;
    for (; k <= 10; k++) {
        int v = fn_801D7A3C(base, k);
        char* tb = base + 0x24;
        int e = *(int*)(tb + off);
        Unk80236FD8_Put((char*)s + 0x9C, fn_80236F34(s, k) * 0x34, v);
        if (v == -1)
            v = 1;
        if (v == 0) {
            if (e != -1) {
                s->m58[s->m8C++] = e;
            }
        } else if (v == 1) {
            if (e != -1) {
                s->m2C[s->m88++] = e;
            }
        } else if (v == 2) {
            if (e != -1) {
                s->m0[s->m84++] = e;
            }
        }
        off += 4;
    }
}

void Unk802362A8_Slots::fn_80237114()
{
    for (int i = 0; i < 11; i++) {
        m0[i] = -1;
        m2C[i] = -1;
        m58[i] = -1;
    }
    m84 = 0;
    m88 = 0;
    m8C = 0;
}

/* Array element read with the byte offset in a local: base-first lwzx (PATTERNS, indexing). */
inline int At(char* base, int i)
{
    int o = i * 4;
    return *(int*)(base + o);
}

/* fn_80237734 (48 insns): not matched; builds two V2 ranges and passes them by value to fn_80237154 (best attempts 37+ slots off). */
extern "C" void fn_80237734(Unk802362A8_Cpu* self);
extern "C" Unk802362A8_Cpu* fn_802376A0(Unk802362A8_Cpu* self, Unk8022FE34_Owner* o, Unk8022FE34_U* u, Unk8022FE34_Ctx* c)
{
    Unk802362A8_Slots* s = &self->m4;
    *(const void**)((char*)self + 0x2F0) = lbl_80660E00;
    *(const void**)((char*)s + 0x2D4) = lbl_80660E30;
    char* e = (char*)self + 0x98;
    for (int i = 0; i < 11; i++) {
        *(const void**)(e + 0x30) = lbl_80660E48;
        e += 0x34;
    }
    s->m90 = (Unk8014D8AC_Ctx*)c;
    s->fn_80237114();
    self->m2DC = o;
    self->m2E0 = u;
    self->m2E4 = c;
    fn_80237734(self);
    return self;
}

/* near-miss: 59/59 insns, 8 slots: retail loads the 0.0 initial constant after lwz r9,0(r31) and the six argument loads
   (ours hoists all pool reads to the top). Tried scalar/array/inline-wrapped constants. */
float Unk802362A8_Cpu::fn_802377F4(Unk802362A8_Pg* p)
{
    float r = 0.0f;
    char* g = p->m0;
    if (!(fn_8024F048(g + 0xA0C, *(int*)(g + 0xA04), *(int*)(g + 0x44C), *(int*)(g + 0x708), 1) <= 0.9f)) {
        r += 0.03f;
    }
    if (!(*(float*)(p->m0 + 0x5D8) <= 0.95f)) {
        r -= 0.06f;
    } else if (!(*(float*)(p->m0 + 0x5D8) <= 0.9f)) {
        r -= 0.04f;
    } else if (!(*(float*)(p->m0 + 0x5D8) <= 0.85f)) {
        r -= 0.02f;
    }
    return r;
}

inline float Unk802378E0_Rand(Unk802362A8_Cpu* c, float scale, int line)
{
    const char* f = lbl_805D7978;
    return (float)(unsigned)((Unk8014D8AC*)c->m2E4->m554)->fn_8014D8AC(1000000, f, line) * scale * 0.000001f;
}
struct Unk801AB63C_P;
struct Unk801B23A8_Q;
int fn_801B38A8(Unk801AB63C_P* p, int i, int c);
int fn_801AD3C4(Unk801AB63C_P* p, int x);
int fn_801B2834(Unk801AB63C_P* p, Unk801B23A8_Q* q);
extern "C" float fn_80088518(void* a, int idx, int* out, int k);
extern int lbl_805D7DD8[];
inline Unk801AB63C_P* Unk802378E0_P3C8(Unk8022FE34_Ctx* c)
{
    return *(Unk801AB63C_P**)(*(char**)((char*)c + 0x700) + 0x3C8);
}

int Unk802362A8_Cpu::fn_802378E0(Unk802362A8_Req* p)
{
    float tbl[16] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.37f, 0.34f, 0.3f, 0.0f, 0.5f, 0.43f, 0.35f, 0.0f, 0.52f, 0.45f, 0.37f, 0.0f };
    int o = *(int*)((char*)p + 0x10) * 4;
    Unk8022FE34_Game* gm = m2E4->m6F8;
    int idx = gm->m14[2].m8 == 0;
    int pl = At(gm->m10 + 0x14, idx);
    o += pl * 16;
    float sp48 = *(float*)((char*)tbl + o);
    int sp68 = 0;
    float sp4C = fn_80088518(gm->mC->mC, idx, &sp68, lbl_805D7DD8[pl]);
    float v2[4] = { 0.0f, 0.1f, 0.15f, 0.25f };
    Unk801AB63C_P* q = Unk802378E0_P3C8(m2E4);
    sp48 = v2[pl] * sp4C + sp48;
    int n = fn_801B38A8(q, idx, 1);
    if (n > 0 && fn_801AD3C4(Unk802378E0_P3C8(m2E4), idx) != 0
        && fn_801B2834(q, (Unk801B23A8_Q*)fn_801C1638(m2E4, 0)) > 0x78)
        sp48 = (float)n * 0.2f + sp48;
    sp48 = sp48 + fn_802377F4((Unk802362A8_Pg*)p);
    fn_80237B60(&sp48);
    if (Unk802378E0_Rand(this, 1.0f, 0x275) >= sp48)
        return 1;
    return 9;
}

void Unk802362A8_Cpu::fn_80237B60(float* out)
{
    float tbl[4] = { -0.6f, -0.5f, -0.3f, -0.2f };
    Unk8022FE34_Game* g = m2E4->m6F8;
    int idx = g->m14[2].m8 == 0;
    int pl = At(g->m10 + 0x14, idx);
    float f = fn_8024D0C4((Unk80270BA0_X*)fn_801C1638(m2E4, 0), 2, lbl_805D7A94, lbl_805D7A98);
    f = f + tbl[pl];
    *out = *out * f;
}

int Unk802362A8_Cpu::fn_80237C24(Unk802362A8_Req* p)
{
    float tbl[16] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.42f, 0.4f, 0.32f, 0.05f, 0.47f, 0.45f, 0.32f, 0.05f, 0.5f, 0.46f, 0.32f, 0.05f };
    int o = *(int*)((char*)p + 0x10) * 4;
    Unk8022FE34_Game* gm = m2E4->m6F8;
    int idx = gm->m14[2].m8 == 0;
    int pl = At(gm->m10 + 0x14, idx);
    o += pl * 16;
    float sp48 = *(float*)((char*)tbl + o);
    int sp68 = 0;
    float sp4C = fn_80088518(gm->mC->mC, idx, &sp68, lbl_805D7DD8[pl]);
    float v2[4] = { 0.0f, 0.1f, 0.15f, 0.25f };
    Unk801AB63C_P* q = Unk802378E0_P3C8(m2E4);
    sp48 = v2[pl] * sp4C + sp48;
    int n = fn_801B38A8(q, idx, 1);
    if (n > 0 && fn_801AD3C4(q, idx) != 0
        && fn_801B2834(q, (Unk801B23A8_Q*)fn_801C1638(m2E4, 0)) > 0x78)
        sp48 = (float)n * 0.2f + sp48;
    sp48 = sp48 + fn_802377F4((Unk802362A8_Pg*)p);
    fn_80237B60(&sp48);
    if (Unk802378E0_Rand(this, 1.0f, 0x2B2) >= sp48)
        return 1;
    return 9;
}

inline float Unk80237E9C_Rand(Unk802362A8_Cpu* c, float scale, int line)
{
    const char* f = lbl_805D7978;
    return (float)(unsigned)((Unk8014D8AC*)c->m2E4->m554)->fn_8014D8AC(1000000, f, line) * scale * 0.000001f;
}
extern "C" float fn_80088518(void* a, int idx, int* out, int k);
extern int lbl_805D7DD8[];

/* near-miss: 98.4%, 3 slots of 123: retail stores sp38 (stw r6,0x38) before 'slwi r30' and the sp18 store (stfs f0,0x18) after it; ours emits the stfs first.
   Tried reordering the sp18/sp38 declarations and moving either earlier or later (all worse or equal). */
int Unk802362A8_Cpu::fn_80237E9C(Unk802362A8_Req* p)
{
    if (fn_80238B84() != 0)
        return 9;
    char* g = ((Unk802362A8_Pg*)p)->m0;
    if (!(fn_8024F048(g + 0xA0C, *(int*)(g + 0xA04), *(int*)(g + 0x44C), *(int*)(g + 0x708), 1) <= 0.9f)
        && (*(int*)((char*)p + 8) != 0 || *(int*)((char*)p + 0xC) != 0))
        return 1;
    float v1[3] = { 0.2f, 0.3f, 0.4f };
    Unk8022FE34_Game* gm = m2E4->m6F8;
    int idx = gm->m14[2].m8 == 0;
    int pl = At(gm->m10 + 0x14, idx);
    float sp18 = v1[p->m14];
    int sp38 = 0;
    float sp1C = fn_80088518(gm->mC->mC, idx, &sp38, lbl_805D7DD8[pl]);
    float v2[4] = { 0.0f, 0.1f, 0.15f, 0.25f };
    sp18 = v2[pl] * sp1C + sp18;
    sp18 = sp18 + fn_802377F4((Unk802362A8_Pg*)p);
    fn_80237B60(&sp18);
    if (Unk80237E9C_Rand(this, 1.0f, 0x2DC) >= sp18)
        return 1;
    return 9;
}

int Unk802362A8_Cpu::fn_80238088(Unk802362A8_Req* p)
{
    if (fn_80238B84()) {
        return 9;
    }
    char* g = m2E4->m680;
    int r;
    if (!(fn_8024F048(g + 0xA0C, *(int*)(g + 0xA04), *(int*)(g + 0x44C), *(int*)(g + 0x708), 1) >= lbl_805D7B1C) && p->m14 == 0) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

struct Unk8019F8C0_Owner;
extern "C" void* fn_801A4B34(Unk8022FE34_Ctx* c);
void* fn_801A4B7C(Unk8019F8C0_Owner* o, int a, int b);
extern int* lbl_8061B9C4;
inline int RB80238110(const unsigned char* p, int off)
{
    return p[off];
}
int Unk802362A8_Cpu::fn_80238110()
{
    int r = 0;
    char* a = (char*)fn_801A4B34(m2E4);
    char* b = (char*)fn_801A4B7C((Unk8019F8C0_Owner*)m2E4, 1, 1);
    Unk8022FE34_Ctx* c = m2E4;
    Unk8022FE34_Game* gm = c->m6F8;
    if (b != 0 && a != 0 && gm != 0 && *(int*)(b + 0x460) != 0) {
        unsigned char* row = (unsigned char*)gm->m14;
        if (RB80238110(row, 0x1CCA) < *lbl_8061B9C4 - 1 && RB80238110(row, 0x1CC9) > 0 && RB80238110(row, 0x1CC8) > 5) {
            int s1 = 0;
            for (int n = 0; n < 128; n++)
                s1 += RB80238110(row + 0x1B4, (unsigned char)n);
            unsigned char* row2 = row + 0xE64;
            int s2 = 0;
            for (int n = 0; n < 128; n++)
                s2 += RB80238110(row2 + 0x1B4, (unsigned char)n);
            int d = s1 - s2;
            int ad = d < 0 ? -d : d;
            if (ad <= 3) {
                int x1 = fn_801C1638(c, 0xA) != 0;
                int x2 = fn_801C1638(c, 0xB) != 0;
                int x3 = fn_801C1638(c, 0xC) != 0;
                if ((x2 != 0 || x3 != 0) && x1 == 0) {
                    int a3 = *(int*)(a + 0x708);
                    int a1 = *(int*)(a + 0xA04);
                    int a2 = *(int*)(a + 0x44C);
                    const float k = 0.75f;
                    if (!(fn_8024F048(a + 0xA0C, a1, a2, a3, 1) < k)) {
                        if (!(fn_8024F048(b + 0xA0C, *(int*)(b + 0xA04), *(int*)(b + 0x44C), *(int*)(b + 0x708), 1) >= k))
                            r = 1;
                    }
                }
            }
        }
    }
    return r;
}

struct Unk8017A930_T;
int fn_8017C954(Unk8017A930_T* p);
int Unk802362A8_Cpu::fn_802382F4(Unk802362A8_Req* p)
{
    int k = fn_8017C954((Unk8017A930_T*)((Unk8014D8AC_Ctx*)m2E4)->m700);
    if (fn_80238110() != 0)
        return 10;
    if (fn_80238B84() != 0)
        return 10;
    switch (k) {
    case 3:
    case 7:
    case 11:
        return fn_80238088(p);
    case 2:
    case 6:
    case 10:
        return fn_80237E9C(p);
    case 0:
    case 1:
    case 5:
        return fn_802378E0(p);
    case 4:
    case 8:
    case 9:
        return fn_80237C24(p);
    }
    return 5;
}

inline float Unk80238A40_RandC(Unk802362A8_Cpu* c, float scale, int line)
{
    const char* f = lbl_805D7978;
    return (float)(unsigned)((Unk8014D8AC*)c->m2E4->m554)->fn_8014D8AC(1000000, f, line) * scale * 0.000001f;
}
inline float Unk80238A40_LerpATB(float a, float t, float b)
{
    return a + t * (b - a);
}
int Unk802362A8_Cpu::fn_802386A8(float* out)
{
    if (m2EC == 0) {
        m2EC = 1;
        out[1] = Unk80238A40_LerpATB(-1.0f, Unk80238A40_RandC(this, 1.0f, 0x41D), 1.0f);
        float r = Unk80238A40_RandC(this, 1.0f, 0x41F);
        if (!(r >= 0.33f)) {
            out[0] = Unk80238A40_LerpATB(-1.0f, Unk80238A40_RandC(this, 1.0f, 0x423), -0.4f);
        } else if (!(r >= 0.67f)) {
            out[0] = Unk80238A40_LerpATB(-0.4f, Unk80238A40_RandC(this, 1.0f, 0x427), 0.4f);
        } else {
            out[0] = Unk80238A40_LerpATB(0.4f, Unk80238A40_RandC(this, 1.0f, 0x42B), 1.0f);
        }
        fn_80238934(out);
    }
    return 1;
}

extern char lbl_80649DA0[];
extern char lbl_80660D68[];
extern "C" void fn_8037893C(void* q, int id, void* e, int a, int b);
class Unk80238934_Pl {
public:
    char pad0[0x98];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
struct Unk80238934_Msg {
    int m0;
    const void* vptr;
    int m8;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived() { vptr = lbl_80660D68; }
    void Dtor() { vptr = lbl_80649DA0; }
    void Set(int v) { m8 = v; }
};
void Unk802362A8_Cpu::fn_80238934(float* p)
{
    int v = ((Unk80238934_Pl*)fn_801A4B34(m2E4))->v4();
    Unk80238934_Msg m;
    m.Base(0xAA);
    m.Derived();
    if (!(p[0] < -1.0f) && !(p[0] > -0.4f)) {
        if (v)
            m.Set(2);
        else
            m.Set(0);
    } else if (!(p[0] < -0.4f) && !(p[0] > 0.4f)) {
        m.Set(1);
    } else {
        if (v)
            m.Set(0);
        else
            m.Set(2);
    }
    Unk80238934_Msg* mp = &m;
    fn_8037893C((char*)m2E4 + 0x704, m.m0, mp, 0, 0);
    mp->Dtor();
}

int fn_80238A40(Unk802362A8_Cpu* c, float* out)
{
    out[0] = Unk80238A40_LerpATB(-1.0f, Unk80238A40_RandC(c, 1.0f, 0x461), 1.0f);
    out[1] = Unk80238A40_LerpATB(-1.0f, Unk80238A40_RandC(c, 1.0f, 0x462), 1.0f);
    return 1;
}

struct Unk80238ECC_V {
    float x;
    float y;
};
extern "C" void* fn_800AB5C8(void* self);
extern "C" char* fn_800AEC78(void* self, void* ctx);
extern "C" void fn_800ADB5C(char* self, Unk80238ECC_V* v, int* a, int* b);
extern "C" int fn_800ADF28(char* self, int a, int b);
extern void* lbl_80619D10;
inline float Unk80238ECC_Rand(Unk802362A8_Cpu* c, float scale, int line)
{
    const char* f = lbl_805D7978;
    return (float)(unsigned)((Unk8014D8AC*)c->m2E4->m554)->fn_8014D8AC(1000000, f, line) * scale * 0.000001f;
}
int Unk802362A8_Cpu::fn_80238ECC(float* out, int* res)
{
    char* p = fn_800AEC78(fn_800AB5C8(lbl_80619D10), m2E4);
    if (p != 0) {
        float h = *(float*)(p + 0xA64) - 0.1f;
        out[0] = Unk80238ECC_Rand(this, h + h, 0x4BE) - h;
        out[1] = Unk80238ECC_Rand(this, h + h, 0x4BF) - h;
        Unk80238ECC_V v = *(Unk80238ECC_V*)out;
        int a;
        int b;
        fn_800ADB5C(p, &v, &a, &b);
        int k = fn_800ADF28(p, a, b);
        *res = m2E0->fn_80235E34(4, k);
    }
    return 1;
}

int Unk802362A8_Cpu::fn_80239448()
{
    int b = m2E4->m6F8->m14[2].m0;
    int a = fn_80238110();
    int c = fn_802394CC();
    if (a != 0) {
        if (c == 0) {
            return 0;
        }
    } else {
        int r = 0;
        if (c != 0) {
            r = 1;
        }
        return r;
    }
    return (unsigned)(b - 5) > 1;
}

float fn_802398C8(Unk8022FE34_W* w)
{
    return lbl_805D7C18;
}

int Unk802362A8_Cpu::fn_802398D4()
{
    Unk8022FE34_Game* gm = m2E4->m6F8;
    unsigned char* row = (unsigned char*)gm->m14;
    int cnt = *(int*)(gm->m10 + 0x1C) - 1;
    if (cnt - RB80238110(row, 0x1CC8) <= 5) {
        int s1 = 0;
        int ia = *(int*)(row + 0x1CD0) == 0;
        unsigned char* ra = row + ia * 0xE64;
        for (int n = 0; n < 128; n++)
            s1 += RB80238110(ra + 0x1B4, (unsigned char)n);
        int ib = 0;
        if (*(volatile int*)(row + 0x1CD0) != 0)
            ib = 1;
        int s2 = 0;
        unsigned char* rb = row + ib * 0xE64;
        for (int n = 0; n < 128; n++)
            s2 += RB80238110(rb + 0x1B4, (unsigned char)n);
        int d = s1 - s2;
        int ad = d < 0 ? -d : d;
        if (ad <= 3) {
            char* o = *(char**)((char*)m2E4 + 0x684);
            if (o != 0) {
                if (!(*(float*)(o + 0x5D8) <= 0.7f)) {
                    int x1 = fn_801C1638(m2E4, 0xB) != 0;
                    int x2 = fn_801C1638(m2E4, 0xC) != 0;
                    if (x1 == 0 && x2 == 0) {
                        unsigned char* row2 = (unsigned char*)gm->m14;
                        int b = row2[0x1CCB];
                        int a = row2[0x1CCA];
                        if (b == 0) {
                            if (a == 2)
                                return ((Unk8014D8AC*)m2E4->m554)->fn_8014D8AC(2, lbl_805D7978, 0x6BE) == 0;
                            if (a == 1)
                                return ((Unk8014D8AC*)m2E4->m554)->fn_8014D8AC(4, lbl_805D7978, 0x6C3) == 0;
                            if (a == 0)
                                return ((Unk8014D8AC*)m2E4->m554)->fn_8014D8AC(6, lbl_805D7978, 0x6C8) == 0;
                        }
                        if (b == 1 && a == 2)
                            return ((Unk8014D8AC*)m2E4->m554)->fn_8014D8AC(5, lbl_805D7978, 0x6CD) == 0;
                    }
                }
            }
        }
    }
    return 0;
}

inline float Unk80239DFC_AbsF(float v)
{
    return (float)__builtin_fabs(v);
}
int fn_8018AA98(int a);
float Unk802362A8_Cpu::fn_80239DFC(int a)
{
    float u0 = 0.05f;
    float u1 = 0.35f;
    Unk8022FE34_V2 d = m2E0->fn_80235BFC();
    float y = 0.4f;
    if (Unk80239DFC_AbsF(d.a) > 1.0f || !(Unk80239DFC_AbsF(d.b) <= 1.0f)) {
        if (fn_8018AA98(a) != 0)
            y = 0.15f;
    }
    float r = 0.0f;
    float t = Unk80238A40_RandC(this, y, 0x78B);
    r = t + -0.05f;
    if (m2E4->m6F4 == 8)
        r = 1.0f;
    return r;
}

double fn_804103C0(double x);

float fn_80239F58(float a, float b, float c, float d)
{
    float tab[6];
    tab[0] = 0.75f;
    tab[1] = 1.0f;
    tab[2] = 0.9f;
    tab[3] = 1.0f;
    tab[4] = 0.85f;
    tab[5] = 1.0f;
    if (!(c >= a * 0.5f))
        c = 0.0f;
    float x = Lerp(0.75f, a, 1.0f);
    float y = Lerp(0.9f, b, 1.0f);
    float z = Lerp(0.85f, 1.0f - c, 1.0f);
    float w = 0.0f;
    int n0 = (int)(float)fn_804103C0(d * 5.0f);
    int n;
    if (n0 <= 5) {
        n = n0;
        if (n <= 0)
            n = 1;
    } else {
        n = 5;
    }
    switch (n) {
    case 1:
        w = 0.1f;
        break;
    case 2:
        w = 0.05f;
        break;
    case 3:
        w = 0.0f;
        break;
    case 4:
        w = -0.05f;
        break;
    case 5:
        w = -0.1f;
        break;
    }
    float r = x * y * z - w;
    return r;
}

void Unk802362A8_Cpu::fn_8023A13C()
{
    char* p = (char*)m2E0 + 0xC;
    float t = fn_801A0AA8(m2E4, 0.5f, lbl_8061D220);
    t = Lerp(-1.0f, t, 1.0f);
    *(float*)(p + 0x18) = t;
    *(float*)(p + 0x14) = 1.0f;
}
