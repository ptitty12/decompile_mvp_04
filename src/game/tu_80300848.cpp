/*
 * Game code, .text 0x80300848-0x80304858 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"
#include "game/goals/tu_8027C728.h"

extern char lbl_80664D18[];
extern char lbl_806604E0[];
extern char lbl_80665D88[];
extern void* lbl_80619D10;
extern const char* lbl_8061F884;
extern unsigned int lbl_8061F888;
extern const char* lbl_8061F88C;
extern unsigned int lbl_8061F890;
extern const char* lbl_8061F894;
extern unsigned int lbl_8061F898;
extern int lbl_8068F1F4;
struct Unk80303ADC_Ent {
    char text[0x32];
    char m32;
    char pad33;
    float x;
    float y;
    int frames;
    int color;
};
struct Unk80303ADC_Mgr {
    char pad0[0x24];
    Unk80303ADC_Ent e[0x40];
    int m1124;
};
extern Unk80303ADC_Mgr* lbl_8068F1FC;
extern int lbl_8068B4BC;
extern int lbl_80620334;
extern void* lbl_8061FEDC;
extern int lbl_8061F950;
extern int lbl_8061F954;

struct Unk80300848_Q {
    int w[4];
};
extern Unk80300848_Q lbl_806E03DC;
struct Unk80300848_W {
    int v;
};
struct Unk80300848_Blk {
    int w[0x5A];
};
struct Unk80300848_P224 {
    char pad0[0x618];
    char* m618;
};
struct Unk80300848_Q4C {
    char pad0[0x4C];
    unsigned m4C;
};
struct Unk80300848_S;
extern Unk80300848_S* lbl_8061F928;
extern int lbl_8061F92C;
struct Unk80300848_S {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x224 - 0x1C];
    Unk80300848_P224* m224;
    Unk80300848_Q4C* m228;
    float m22C;
    float m230;
    int m234;
    float m238;
    int m23C;
    int m240;
    int m244;
};
struct Unk80300848_At8 {
    char pad0[8];
    const void* m8;
    char pad0C[0x10 - 0xC];
    char pad10[0xC];
    int m1C;
    char pad20[0x188 - 0x20];
    const void* m188;
};
struct Unk80300848_P188 {
    char pad0[0x24];
    Unk80300848_Blk m24;
};
struct Unk80300848_P1124 {
    char pad0[0x1124];
    int m1124;
};

struct Unk80300848_SpdM {
    char pad0[4];
    float m4;
};
struct Unk80300848_Spd {
    char pad0[4];
    void* m4;
    Unk80300848_SpdM* m8;
    char padC[8];
    float m14;
};
struct Unk8019F8C0_Owner;
struct Unk802ACD88_Mgr;
float fn_802AEB4C(Unk802ACD88_Mgr* m, void* p);
float fn_801A0744(Unk8019F8C0_Owner* o);
void fn_801A0790(Unk8019F8C0_Owner* o, float v);
void fn_801A07D8(Unk8019F8C0_Owner* o, float v);
extern Unk802ACD88_Mgr* lbl_8061E978;
struct Unk80300848_Sl {
    int m0;
    char pad4[0x14C - 4];
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
};
struct Unk80300848_Ob {
    char pad0[0x24];
    int m24;
};
struct Unk80305C88_P;
void fn_80305C88(Unk80305C88_P* p, short v);
extern const char lbl_805E7B04[];
extern const char lbl_805E7B1C[];
extern const char lbl_805E7B24[];
extern "C" {
void fn_800ABA88(void* mgr, int a, int b, int c);
void* fn_803282A8(void* p, int a);
void fn_80328374(void* p, int a);
void fn_80377408(void* p);
void fn_803020BC(Unk80300848_S* p);
void fn_803020DC(Unk80300848_S* p);
char* fn_8040B830(char* dst, const char* src, int n);
void fn_80409BF0(char* buf, const char* fmt, va_list_tag ap);
void fn_80315358(void* g);
void fn_8031259C(void* g);
void fn_803125D0(void* g);
void fn_803144A0(void* g, const char* text, float x, float y, int color, int k);
void fn_803021A4(Unk80300848_S* p);
void fn_803022A8(Unk80300848_S* p);
Unk8027C728_Goal* fn_802448F4(void* o, int a);
void fn_8028B138__FP16Unk8028989C_Goal(char* a, char* b);
void fn_80244A64(void* o, Unk8027C728_Goal* g, int flag);
void fn_8030ACCC(void* p);
void fn_803D775C(int* out, int h, const char* s, ...);
void fn_803D7378(int* out, int h, const char* s, ...);
}

void fn_8027C728(Unk8027C728_Goal* g);

void fn_80301730()
{
    fn_800ABA88(lbl_80619D10, 2, 0, 0);
}

void fn_80301764()
{
    fn_800ABA88(lbl_80619D10, 2, 1, 0);
}

void fn_80301798(Unk80300848_S* p)
{
    *(int*)((char*)p + 0x2C) = 0;
    fn_800ABA88(lbl_80619D10, 3, 0, 0);
}

Unk80300848_S* fn_80301F7C(Unk80300848_S* p)
{
    fn_803282A8(p, 0);
    p->m18 = lbl_80664D18;
    lbl_8061F928 = p;
    p->m23C = 1;
    *(int*)((char*)p + 0x234) = 0;
    *(int*)((char*)p + 0x244) = 0;
    return p;
}

Unk80300848_S* fn_80301FD8()
{
    if (lbl_8061F928 == 0)
        lbl_8061F928 = fn_80301F7C((Unk80300848_S*)operator new(0x248, 0));
    return lbl_8061F928;
}

void fn_80302024(Unk80300848_S* p)
{
    if (p->m244 != 0) {
        switch (p->m23C) {
        case 0:
            fn_803020BC(p);
            break;
        case 1:
            fn_803020DC(p);
            break;
        case 2:
            fn_803022A8(p);
            break;
        case 3:
            fn_803021A4(p);
            break;
        }
    }
}

void fn_80302098()
{
}

void fn_8030209C(Unk80300848_S* p)
{
    if (p->m244 != 0) {
        p->m244 = 0;
        lbl_8061F92C = 0;
    }
}

void fn_803020BC(Unk80300848_S* p)
{
    p->m240 = p->m240 - 1;
    if (p->m240 <= 0)
        p->m23C = 1;
}

void fn_803020DC(Unk80300848_S* p)
{
    p->m22C = (float)p->m228->m4C * 0.016666668f + 0.033333335f;
    p->m230 = p->m22C + 10.0f;
    if (p->m224 != 0) {
        Unk8027C728_Goal* g = fn_802448F4(p->m224, 1);
        g->m10 = 8;
        fn_8028B138__FP16Unk8028989C_Goal(g->m18, (char*)p + 0x24);
        fn_8027C728(g);
        fn_80244A64(p->m224, g, 1);
    }
    p->m23C = 2;
}

const char* fn_803039DC()
{
    return lbl_8061F884;
}

int fn_803039E8()
{
    return 0x71B43039;
}

const char* fn_803039F4()
{
    return lbl_8061F88C;
}

unsigned int fn_80303A00()
{
    return lbl_8061F890;
}

const char* fn_80303A0C()
{
    return lbl_8061F894;
}

unsigned int fn_80303A18()
{
    return lbl_8061F898;
}

unsigned int fn_80303A24()
{
    return lbl_8061F888;
}

int fn_80303A30()
{
    return 0x7A17F3A4;
}

void fn_80303A3C(Unk80300848_S* p, int c)
{
    p->m18 = lbl_80664D18;
    fn_80328374(p, c);
}

extern "C" void fn_803029AC(int a, int b);

extern "C" void fn_80303A6C()
{
    fn_803029AC(1, 0xFFFF);
}

extern "C" void fn_80303A98() { fn_803029AC(0, 0xFFFF); }



int fn_80303AC4()
{
    return lbl_8068F1F4;
}

Unk80303ADC_Mgr* fn_80303AD0()
{
    return lbl_8068F1FC;
}

/* near-miss: same instructions, but retail stores f1 before the register copies and the order of the float stores differs (f >? 1 gives the right clamp branch) */
void fn_80303ADC(Unk80303ADC_Mgr* m, const char* text, int color, float dur, float x, float y)
{
    if (m->m1124 <= 0x3F) {
        fn_8040B830(m->e[m->m1124].text, text, 0x32);
        m->e[m->m1124].m32 = 0;
        int f = (int)(dur * 60.0f);
        m->e[m->m1124].x = x;
        m->e[m->m1124].y = y;
        f = f >? 1;
        m->e[m->m1124].frames = f;
        m->e[m->m1124].color = color;
        m->m1124 = m->m1124 + 1;
    }
}

/* near-miss: va_list word lives in r12 in retail (va copy is emitted inside the if); ours hoists the copy above the test and keeps the word in r30 (frame 0x1B0 vs 0x1A0) */
void fn_80303BC4(const char* fmt, float a, float b, ...)
{
    char buf[0x100];
    va_list ap;
    va_start(ap, b);
    if (lbl_8068B4BC != 0) {
        fn_80409BF0(buf, fmt, *ap);
        fn_80303ADC(fn_80303AD0(), buf, 1, 0.0f, a, b);
    }
}

/* near-miss: same va_list issue as fn_80303BC4 */
void fn_80303CA0(const char* fmt, float a, float b, float c, ...)
{
    char buf[0x100];
    va_list ap;
    va_start(ap, c);
    if (lbl_8068B4BC != 0) {
        fn_80409BF0(buf, fmt, *ap);
        fn_80303ADC(fn_80303AD0(), buf, 1, a, b, c);
    }
}

void fn_80303D78(Unk80303ADC_Mgr* m)
{
    if (lbl_8068B4BC != 0) {
        void* g = lbl_8061FEDC;
        if (lbl_80620334 != 0)
            fn_80315358(g);
        int i = 0;
        fn_8031259C(g);
        for (; i < m->m1124; i++)
            fn_803144A0(g, m->e[i].text, m->e[i].x, m->e[i].y, m->e[i].color, 0x16);
        fn_803125D0(g);
    }
}

/* near-miss: same va_list issue as fn_80303BC4 */
void fn_80303E38(const char* fmt, float a, float b, ...)
{
    char buf[0x100];
    va_list ap;
    va_start(ap, b);
    if (lbl_8068B4BC != 0) {
        fn_80409BF0(buf, fmt, *ap);
        void* g = lbl_8061FEDC;
        fn_8031259C(g);
        fn_803144A0(g, buf, a, b, 1, 0x16);
        fn_803125D0(g);
    }
}

void fn_8030408C(Unk80300848_P1124* p)
{
    p->m1124 = 0;
}

void fn_80304218(Unk80300848_P188* p, const Unk80300848_Blk* src)
{
    volatile int t = *(int*)((char*)p + 0x188);
    p->m24 = *src;
    *(int*)((char*)p + 0x188) = t;
}

void fn_8030427C(Unk80300848_Ob* p, int h)
{
    Unk80300848_Sl* slot = (Unk80300848_Sl*)&p->m24;
    p->m24 = 0;
    fn_8030ACCC((char*)p + 0x28);
    p->m24 = h;
    if (h != 0) {
        int v1, v2, v3, v4, v5, v6;
        fn_803D775C(&v1, p->m24, lbl_805E7B04);
        slot->m14C = v1;
        fn_803D7378(&v2, p->m24, lbl_805E7B04);
        slot->m150 = v2;
        fn_803D775C(&v3, p->m24, lbl_805E7B1C);
        slot->m154 = v3;
        fn_803D7378(&v4, p->m24, lbl_805E7B1C);
        slot->m158 = v4;
        fn_803D775C(&v5, p->m24, lbl_805E7B24);
        slot->m15C = v5;
        fn_803D7378(&v6, p->m24, lbl_805E7B24);
        slot->m160 = v6;
        fn_80305C88((Unk80305C88_P*)slot, 0);
    }
}

/* near-miss: retail puts the two vtable addresses in r11/r10, ours r9/r11 (statement permutations and typed vptr fields tried) */
void fn_80304388(Unk80300848_At8* p, int c)
{
    p->m1C = 0;
    p->m188 = lbl_806604E0;
    p->m8 = lbl_80665D88;
    if (c & 1)
        fn_80377408(p);
}

void fn_803043D0()
{
}

void fn_803043D4(int a, int b)
{
    lbl_8061F950 = a;
    lbl_8061F954 = b;
}

void fn_8030482C(int a, int b, const Unk80300848_Q* q)
{
    lbl_806E03DC = *q;
}
