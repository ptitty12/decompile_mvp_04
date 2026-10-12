/*
 * Game code, .text 0x8020ADC4-0x8020EE9C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"
#include "game/goals/tu_8027C728.h"

typedef Unk801EE438_Scr Scr;

struct Unk801E7448_G {
    char pad0[8];
    Unk80270BA0_X* m8;
    char pad0C[0x3A64 - 0xC];
    void* m3A64;
};
class Unk80299920_Goal {
public:
    Unk80299920_Goal* fn_80299F0C(Unk80273498_Vec3* v);
    void fn_80299F64(int v);
    float fn_8029A948();
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
};
class Unk8027A84C_Owner {
public:
    Unk8027A84C* fn_8027C67C();
};
extern "C" Unk80273498_Vec3 fn_801E7448(void* o, int k);
extern "C" Unk8027C728_Goal* fn_802448F4(Unk80270BA0_X* p, int k);
void fn_8027C728(Unk8027C728_Goal* g);
int fn_8027D390(Unk8027C728_Goal* g, float* a, Unk80273498_Vec3* b, Unk80273498_Vec3* c, float* d);
void fn_8027D368(Unk8027C728_Goal* g);
extern "C" int fn_80205684(void* g);
extern "C" void fn_8033E958(const char* fmt, ...);

struct Unk8020C5FC_Tbl {
    int m[4];
};
extern Unk8020C5FC_Tbl lbl_805D5950;
extern Unk8020C5FC_Tbl lbl_805D5960;

struct Unk8020DF6C_Buf {
    int* m0;
    int m4;
};

extern "C" {
void fn_80377488(void* p);
int fn_8020B944(Scr* p);
int fn_8020C4B4(Scr* p);
int fn_8020C5FC(Scr* p);
int fn_8020C5F4(Scr* p);
}

extern "C" int fn_8020B898(Scr* p)
{
    int r = 0;
    switch (p->m0->m34) {
    case 0:
        break;
    case 1:
        p->m0->mCA4 = fn_8020B944(p);
        break;
    case 3:
        r = 1;
        p->m0->mCA4 = fn_8020C5FC(p);
        break;
    case 2:
        r = 1;
        p->m0->mCA4 = fn_8020C4B4(p);
        break;
    case 4:
        r = 1;
        p->m0->mCA4 = fn_8020C5F4(p);
        break;
    }
    return r;
}

extern char lbl_80649DA0[];
extern char lbl_80660C78[];
extern Unk8020C5FC_Tbl lbl_805D5940;

struct Unk8020C4B4_Ev {
    int m0;
    const void* vptr;
    int m8;
    int mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived()
    {
        vptr = lbl_80660C78;
        m8 = -1;
    }
    ~Unk8020C4B4_Ev() { vptr = lbl_80649DA0; }
};

struct Unk8020C4B4_Own {
    char pad0[0x660];
    void* m660;
};

struct Unk8020C4B4_J {
    char pad0[0x41C];
    int m41C;
};

extern "C" int fn_80259330(int x);
extern "C" int fn_8020C90C(Scr* p);
extern "C" int fn_8017C94C(void* j);
extern "C" void fn_8037893C(void* q, int id, Unk8020C4B4_Ev* e, int a, int b);

extern "C" int fn_8020C4B4(Scr* s)
{
    int r = 1;
    if (fn_80259330(s->m0->m0->m700->m3B4) == 1) {
        int idx = fn_8020C90C(s);
        if (idx == -1)
            idx = 3;
        Unk8020C5FC_Tbl t = lbl_805D5940;
        r = t.m[idx];
        Unk8020C4B4_Ev e;
        e.Base(0x69);
        e.Derived();
        e.m8 = idx;
        fn_8037893C((char*)s->m0->m0 + 0x704, e.m0, &e, 0, 0);
    } else if (fn_8017C94C(s->m0->m0->m700) == 1) {
        r = 0x44;
        Unk801EE438_Game* g = s->m0->m0->m6CC;
        if ((void*)g->m36C == ((Unk8020C4B4_Own*)s->m0->m0)->m660)
            r = 0x43;
    } else if (((Unk8020C4B4_J*)s->m0->m0->m700)->m41C != 0xA) {
        r = 0x43;
    }
    return r;
}

extern "C" int fn_8020C5F4(Scr* p)
{
    return 0x42;
}

/* near-miss (17 slots): retail computes idx*4 and loads the first table word inside each branch and
 * cross-jumps only the rest of the 16-byte copy; if/else struct assignment gets the right length
 * but schedules the copy differently. */
extern "C" int fn_8020C5FC(Scr* p)
{
    Unk801EE438_G* g = p->m0;
    int idx = g->mC88;
    if (idx == -1)
        idx = 1;
    Unk8020C5FC_Tbl t;
    if (g->mC8C == 1)
        t = lbl_805D5950;
    else
        t = lbl_805D5960;
    return t.m[idx];
}

/* near-miss (6 slots): saturating-decrement loop and volatile counter match; retail puts the final
 * player-slot index/result in r11/r3 where ours uses r0, and schedules cmpwi before the addi. */
extern "C" int fn_8020C90C(Scr* p)
{
    volatile int sp8;
    int t = 3;
    int r = -1;
    int h = p->m0->m0->m700->m3B4;
    int e;
    while (sp8 = t, e = sp8, e > 0) {
        if (fn_80259C50(h, e) != 0) {
            r = sp8;
            break;
        }
        int c = sp8;
        t = c - 1;
        if (c <= -1)
            t = c;
    }
    int s = sp8;
    if (s <= 2) {
        Unk801EE438_Owner* o = p->m0->m0;
        unsigned k = fn_8014E2B4(s);
        Unk801EE438_Player* pl;
        if (k <= 12)
            pl = o->m65C[k];
        else
            pl = 0;
        if (pl != 0)
            r = 3;
    }
    return r;
}

/* near-miss: body matches except for register choice: retail copies p to r10 up front and loads the
 * three m65C[10..12] tests into r3; ours keeps p in r3 and loads into r0 (same shape as fn_8020C90C). */
extern "C" int fn_8020C9CC(Scr* p, int* out)
{
    volatile int sp8;
    int e;
    if (out != 0) {
        sp8 = 0;
        e = 0;
        do {
            out[e] = 0;
            int c = sp8;
            int t;
            if (c > 3)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 2);
    }
    int r = 0;
    if (p->m0->m0->m65C[10] != 0) {
        r = 1;
        if (out != 0)
            out[0] = 1;
    }
    if (p->m0->m0->m65C[11] != 0) {
        r = 2;
        if (out != 0)
            out[1] = 1;
    }
    if (p->m0->m0->m65C[12] != 0) {
        r = 3;
        if (out != 0)
            out[2] = 1;
    }
    return r;
}

extern "C" int fn_8020CCFC(int unused, int k)
{
    return (unsigned)(k - 6) <= 2;
}

extern "C" int fn_8020CD10(int unused, int k)
{
    return fn_8020CCFC(unused, k) == 0;
}

extern "C" int fn_8020CD38(int unused, int a, int b)
{
    int r = 0;
    switch (a) {
    case 0:
        if (b == 2)
            r = 1;
        break;
    case 1:
        if (b == 3 || b == 5)
            r = 1;
        break;
    case 2:
        if (b == 4)
            r = 1;
        break;
    case 3:
        if (b == 1)
            r = 1;
        break;
    }
    return r;
}

extern const Unk801EE438_Vec lbl_805D6790;
extern const float lbl_805D59AC;

inline Unk801EE438_Vec VecSub(const Unk801EE438_Vec& a, const Unk801EE438_Vec& b)
{
    Unk801EE438_Vec r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}

extern "C" int fn_8020CFA8(Scr*, Unk801EE438_Vec* a)
{
    Unk801EE438_Vec d = VecSub(*a, lbl_805D6790);
    return d.m0 * d.m0 + d.m8 * d.m8 < lbl_805D59AC;
}

extern "C" void fn_8020DF6C(Unk8020DF6C_Buf* b)
{
    if (b->m0 != 0) {
        delete[] b->m0;
        b->m0 = 0;
        b->m4 = 0;
    }
}

extern "C" void fn_8020DFB0(int x, int a, int b, int c)
{
    fn_80248488(a, b, b, c, 9, 0, 0);
}

extern "C" void fn_8020DFE4(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6, int a7, int a8)
{
    fn_8020E074(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6), a7, a8);
}

extern "C" float fn_8020E074(Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t, int a7, int a8)
{
    if (t == 1) {
        fn_8033E958("BUG_HUNT! throw_style = ANIM_THROW_UNKNOWN\n");
        *(int*)5 = 6;
    }
    if (t == 0) {
        fn_8033E958("BUG_HUNT! throw_style = ANIM_THROW_NONE\n");
        *(int*)7 = 8;
    }
    float r = 0.0f;
    int ten = 0xA;
    Unk8027C728_Goal* g = fn_802448F4((Unk80270BA0_X*)a2, 1);
    g->m10 = 5;
    fn_8027C728(g);
    Unk80299920_Goal* sub = (Unk80299920_Goal*)g->m18;
    Unk80273498_Vec3 pos = *(Unk80273498_Vec3*)&v;
    sub->fn_80299F0C(&pos);
    sub->fn_80299F64(t);
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
    ((Unk8027A84C*)g->m104)->m40 = ten;
    float tf = 0.0f;
    int res = fn_8027D390(g, &tf, (Unk80273498_Vec3*)a7, 0, 0);
    if (a8 != 0)
        *(float*)a8 = sub->fn_8029A948();
    if (res == 1) {
        if (a7 != 0 && ((Unk80273498_Vec3*)a7)->y == -1000.0f)
            *(Unk80273498_Vec3*)a7 = *(Unk80273498_Vec3*)(a1 + 0x60);
    } else {
        fn_80205684(p->m9C);
    }
    fn_8027D368(g);
    r = tf;
    return r;
}

extern "C" void fn_8020E20C(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6, int a7, int a8)
{
    fn_8020E2A0(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6), a7, a8, 0);
}

extern "C" void fn_8020E6A0(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6)
{
    fn_8020E71C(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6));
}

extern const float lbl_805D5B28;
extern const float lbl_805D5B2C;
extern const Unk801EE438_Vec lbl_806055DC;
extern "C" float fn_804028E4(float x); /* square root */
extern "C" float fn_80250338(void* o, float a, float b);
extern "C" float fn_80189D88(int a, int b, Unk801EE438_Vec* pos, const Unk801EE438_Vec* v, float f);

inline float Len20E71C(Unk801EE438_Vec v)
{
    return fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8);
}

extern "C" float fn_8020E71C(Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t)
{
    Unk801EE438_Vec w = lbl_806055DC;
    float f18 = lbl_805D5B28;
    float r = fn_8020E074(p, a1, a2, v, t, (int)&w, (int)&f18);
    float c = fn_80250338((void*)(a2 + 0x4D8), Len20E71C(VecSub(w, v)), f18);
    float q = fn_80189D88(a1, a2, &w, &v, c);
    return r + q;
}

/* near-miss (2 slots): the two argument moves for the fn_80216590 call (mr r8,r9 / mr r5,r11) are
 * ordered the other way round than retail. */
extern "C" void fn_8020E82C(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6, int a7)
{
    fn_8020E8B4(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6), a7);
}

extern "C" float fn_8020E8B4(Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t, int a7)
{
    Unk801EE438_Vec w = lbl_806055DC;
    float f18 = lbl_805D5B2C;
    float r = fn_8020E2A0(p, a1, a2, v, t, (int)&w, (int)&f18, a7);
    float dist = Len20E71C(VecSub(w, v));
    float c = fn_80250338((void*)(a2 + 0x4D8), dist, f18);
    float q = fn_80189D88(a1, a2, &w, &v, c);
    return r + q;
}

extern const float lbl_805D5B48;
extern const float lbl_805D5B4C;
extern const float lbl_805D5B50;
extern const float lbl_805D5B54;
extern const float lbl_805D5B58;
extern const float lbl_805D5B5C;
extern const float lbl_805D5B60;
extern const float lbl_805D5B64;
extern const float lbl_805D5B68;


extern "C" float fn_8020EC50(Scr* p, int k)
{
    float f = 0.0f;
    Unk80273498_Vec3 pos = fn_801E7448(((Unk801E7448_G*)p->m9C)->m3A64, k);
    int type = 0x11;
    switch (k) {
    case 0:
        break;
    case 1:
        type = 0x13;
        break;
    case 2:
        type = 0x12;
        break;
    default:
        type = 0x11;
        break;
    }
    int two = 2;
    if (((Unk801E7448_G*)p->m9C)->m8->m458 == 0) {
        int ten = 0xA;
        Unk8027C728_Goal* g = fn_802448F4(((Unk801E7448_G*)p->m9C)->m8, 1);
        Unk80273498_Vec3 v = pos;
        Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
        g->m10 = 5;
        fn_8027C728(g);
        ((Unk80299920_Goal*)g->m18)->fn_80299F0C(&v)->fn_80299F64(type);
        ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = two;
        g104->m38 = two;
        ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = two;
        g104->m34 = two;
        ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
        g104->m40 = ten;
        if (fn_8027D390(g, &f, 0, 0, 0) == 0)
            fn_80205684(p->m9C);
        fn_8027D368(g);
    }
    return f;
}

extern "C" float fn_8020EDA8(Scr*, int, int, Unk801EE438_Vec* a, Unk801EE438_Vec* b, float* out)
{
    float d2;
    Unk801EE438_Vec d = VecSub(*a, *b);
    d2 = d.m0 * d.m0 + d.m8 * d.m8;
    float v1 = lbl_805D5B48;
    float v0;
    if (!(d2 >= lbl_805D5B4C)) {
        v0 = lbl_805D5B50;
        v1 = lbl_805D5B54;
    } else if (!(d2 >= lbl_805D5B58)) {
        v0 = lbl_805D5B5C;
        v1 = lbl_805D5B60;
    } else {
        v0 = lbl_805D5B64;
        v1 = lbl_805D5B68;
    }
    if (out != 0)
        *out = v1;
    return v0;
}
