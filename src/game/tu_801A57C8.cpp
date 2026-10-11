/*
 * Game code, .text 0x801A57C8-0x801A96E0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"

void fn_801A57C8(Unk8019F8C0_Owner* o, int a);
int fn_801A57B8();
void fn_801A62D0(Unk8019F8C0_Owner* o, int a);
void fn_801B2538(Unk8019F8C0_Owner* o);
void fn_80235AD4(void* p);
void fn_8033E5C4(void* a, int n);
Unk8019F8C0_Sub* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
void* fn_803FFC58(void* p, int v, int n);
void fn_8037893C(void* a, int b, void* c, void* d, int e);
void fn_801AA038(void* p, int n);
void fn_801AA248(void* p);
extern Unk801A57C8_G lbl_8068BF34;
void fn_8023C514(void* a, Unk8019F8C0_Owner* o);
void fn_8033E958(const char* s, ...);
void fn_801A5394(Unk8019F8C0_Owner* o);
void fn_801A5708(Unk8019F8C0_Owner* o);
void fn_801A57B4(Unk8019F8C0_Owner* o);
void fn_801A5014(Unk8019F8C0_Owner* o);
void fn_8006F918(int a, int b);
int fn_800A8874(void* m, int a, int b, int c);
void fn_801A594C(Unk8019F8C0_Owner* o, int i);
void fn_801A5D3C(Unk8019F8C0_Owner* o);
void fn_801A5C1C(Unk8019F8C0_Owner* o);
void fn_801A5B44(Unk8019F8C0_Owner* o);
void fn_80378A34(void* a, void* b);
extern char lbl_8068CCA8[];
extern char lbl_805CEA04[];
extern char lbl_805CEA28[];
void fn_8028709C(void* x, unsigned h);
int fn_801A2034(Unk8019F8C0_Owner* o, int i);
void fn_801A7764(void* w, int t);
int fn_80400E84();
int fn_80400DA4();
void fn_80107F74(int a, int b, int c);

struct Unk801A57C8_Wrap {
    Unk8019F8C0_Owner* m0;
};
struct Unk801A57C8_Timer {
    char pad0[0x28];
    int m28;
    int m2C;
    int m30;
    int m34;
};

void fn_801A58FC(Unk8019F8C0_Owner* o, int a)
{
    if (o->m6F4 == 0 && fn_801A57B8()) {
        fn_801A57C8(o, a);
    }
}

void fn_801A6240(Unk8019F8C0_Owner* o)
{
    void* t = (void*)o->m594[0];
    if (t) {
        fn_8028709C(t, 0xC3FB7E21u);
        fn_8028709C(t, 0x4901B7BCu);
        fn_8028709C(t, 0x5112B944u);
        fn_8028709C(t, 0x6BCA31A3u);
        fn_8028709C(t, 0xBEE24601u);
        fn_8028709C(t, 0x52D3659Du);
    }
}

void fn_801A642C(Unk8019F8C0_Owner* o)
{
    fn_8023C514(lbl_8068CCA8, o);
    fn_8033E958(lbl_805CEA04);
    fn_801A5394(o);
    fn_801A5708(o);
    fn_801A57B4(o);
    fn_801A5014(o);
    Unk8019F8C0_Mgr* m = o->m6F8;
    int t = m->mC;
    fn_8006F918(t, fn_800A8874(m, 0x64, 0, 0));
    volatile int c = 0;
    int i = 0;
    do {
        fn_801A594C(o, i);
        int w = c;
        int n;
        if (w > 1) {
            n = w;
        } else {
            n = w + 1;
        }
        c = n;
        i = n;
    } while (i <= 1);
    fn_801A5D3C(o);
    fn_801A5C1C(o);
    fn_801A5B44(o);
    fn_80378A34(o->m24, o->m704);
    fn_8033E958(lbl_805CEA28);
}

void fn_801A6528(Unk8019F8C0_Owner* o)
{
    fn_801A62D0(o, 1);
    fn_801A62D0(o, 0);
    fn_801B2538(o);
}

void fn_801A674C() {}

void fn_801A6820(Unk8019F8C0_Owner* o)
{
    Unk801A57C8_Mode* p = (Unk801A57C8_Mode*)o->m560;
    if (p->m4->m14 - 3 <= 1) {
        fn_80235AD4(o->m700->m3B0);
        fn_8033E5C4(p, 3);
    }
}

Unk8019F8C0_Ref* fn_801A6D84(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, i);
    if (s) {
        return s->m40;
    }
    return 0;
}

void fn_801A6FBC()
{
    fn_803FFC58(&lbl_8068BF34, 0, 0x424);
    lbl_8068BF34.m310 = 0;
    lbl_8068BF34.m31C = 0;
    lbl_8068BF34.m314 = 0;
    lbl_8068BF34.m318 = 0;
}

int fn_801A700C(int a, int b, int idx)
{
    return lbl_8068BF34.m0[idx];
}

int fn_801A7020(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Mgr10* p = o->m6F8->m10;
    int r = 0;
    if (p) {
        r = p->m22C == 0xb;
    }
    return r;
}

/* near-miss: retail returns the -1 case from a shared tail at the end (3 slots differ). */
int fn_801A7130(Unk8019F8C0_Owner* o, int i)
{
    if (o->m58C[i] != -1) {
        return o->m6F8->m14[i].m108 != 0;
    }
    return 1;
}

void fn_801A7174(void* a, int b, void* c, void* d)
{
    fn_8037893C(a, b, c, d, 0);
}

int fn_801A7198(Unk8019F8C0_Owner* o)
{
    int* p = o->m65C;
    int r = 0;
    if (p[10] || p[11] || p[12]) {
        r = 1;
    }
    return r;
}

Unk801A734C::Unk801A734C(int a)
{
    m0 = a;
    m28 = 0;
    Reset();
}

Unk801A734C::~Unk801A734C() {}

void Unk801A734C::Clear()
{
    Init(0);
    Reset();
}

void fn_801A7AB0(Unk801A57C8_Wrap* w)
{
    if (w->m0->m6F4 == 0) {
        int t = fn_801A2034(w->m0, 3);
        if (t != -1 && fn_801A700C((int)w->m0, t, 0x76) != 0) {
            fn_801A7764(w, t);
        }
    }
}

int fn_801A7B20(Unk8019F8C0_Owner** a, int* b)
{
    if ((*a)->m6F4 == 0xc) {
        int n = *b + 1;
        if (n <= 3) {
            *b = n;
            return 1;
        }
        return 0;
    }
    return 0;
}

void fn_801A8198(char* p)
{
    *(int*)(p + 0x1C) = 0;
}

void fn_801A9584(Unk801A57C8_Timer* p)
{
    p->m34 = 1;
    int t = fn_80400E84() / 10;
    p->m30 = fn_80400DA4() + t;
    if (p->m28 != 0) {
        fn_80107F74(p->m28, 1, p->m2C);
        fn_80107F74(p->m28, 0, p->m2C ^ 1);
    }
}

Unk801A9610::Unk801A9610(int a, int b) : Unk801B5A44(a, b)
{
    Init();
}

Unk801A9610::~Unk801A9610() {}

void Unk801A9610::Init()
{
    fn_801AA038(this, 1);
}

/* near-miss: retail keeps x-2 in r0 and copies it to r3 before the compare (4 slots differ). */
int fn_801A96A8(int x)
{
    unsigned t = x - 2;
    if (t > 3) {
        return 0;
    }
    return t;
}

void fn_801A96C0(void* p)
{
    fn_801AA248(p);
}
