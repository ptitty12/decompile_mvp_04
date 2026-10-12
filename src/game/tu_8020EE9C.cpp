/*
 * Game code, .text 0x8020EE9C-0x80212AC0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
Player* fn_80257B40(void* list);
Player* fn_80257BD0(void* list, Player* cur, int x);
int fn_80254984(PlayerSub* p);
int fn_80254A34(PlayerSub* p);
int fn_80254B60(PlayerSub* p);
int fn_80254BEC(PlayerSub* p);
int fn_80255028(PlayerSub* p);
int fn_80210DA8(Sub* t, int kind, Player* p);
int fn_802110F8(Sub* t, int kind, Player* p, int x);
void fn_80204CCC(Rec* r);
int fn_8026DAE8(void* obj, int x);
void fn_80214CE8(Task* t, float f, int a, int b, int c, int d);
void fn_80211C04(Ent38* e);
void fn_80211CAC(EntList* l);
float fabsf(float x);
}

extern "C" {

int fn_80210C98(Sub* t, int kind)
{
    void* list = t->m0->m0->m700->m3B4;
    int r = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80210DA8(t, kind, p) == 1) {
            r = 1;
            break;
        }
    }
    return r;
}

int fn_80210D20(Sub* t, int kind)
{
    void* list = t->m0->m0->m700->m3B4;
    int n = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80210DA8(t, kind, p) == 1) {
            n++;
        }
    }
    return n;
}

int fn_80210DA8(Sub* t, int kind, Player* p)
{
    switch (kind) {
    case 0:
        return fn_80254984(&p->m58C);
    case 1: {
        int r = 0;
        if (fn_80254984(&p->m58C) == 1 && p->m458 != 9) {
            r = 1;
        }
        return r;
    }
    case 2:
        return fn_80254A34(&p->m58C);
    case 3:
        return fn_80254B60(&p->m58C);
    case 4:
        return fn_80254BEC(&p->m58C);
    default:
        return 0;
    }
}

extern const float lbl_805D5C14;
extern "C" float fn_80259A74(void* list, int id, int k);
extern "C" int fn_80254EA4(PlayerSub* p, int a);

inline float AbsF(float v)
{
    return fabsf(v);
}

int fn_80210E64(Sub* t, int a, Player** out, float* outf, float f)
{
    void* list = t->m0->m0->m700->m3B4;
    Player* p = fn_80257B40(list);
    *out = 0;
    float best = lbl_805D5C14;
    for (; p; p = fn_80257BD0(list, p, 0)) {
        if (fn_802110F8(t, 2, p, a) == 1 || fn_802110F8(t, 4, p, a) == 1) {
            float d = fn_80259A74(list, p->m458, a);
            int k = fn_80254EA4(&p->m58C, 0);
            if (k != -1 && k != a)
                d = 2.0f * fn_80259A74(list, p->m458, k);
            float diff = f - d;
            if (!(AbsF(diff) >= AbsF(best))) {
                *outf = d;
                best = diff;
                *out = p;
            }
        }
    }
    return *out != 0;
}

int fn_80210FC4(Sub* t, int kind, int x, Player** out)
{
    void* list = t->m0->m0->m700->m3B4;
    int r = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_802110F8(t, kind, p, x) == 1) {
            r = 1;
            if (out) {
                *out = p;
            }
            break;
        }
    }
    return r;
}

struct PlayerSubX {
    char pad0[8];
    float m8;
    char padC[0x28 - 0xC];
    int m28;
    char pad2C[4];
    int m30;
    char pad34[4];
    int m38;
    int m3C;
};

extern const float lbl_805D5C18;
extern "C" int fn_802113E8(Sub* t, Player* p, int x);

int fn_802110F8(Sub* t, int kind, Player* p, int x)
{
    switch (kind) {
    case 0: {
        PlayerSubX* s = (PlayerSubX*)&p->m58C;
        int r = 0;
        if (s->m8 != lbl_805D5C18)
            r = s->m3C == x;
        return r;
    }
    case 1: {
        PlayerSubX* s = (PlayerSubX*)&p->m58C;
        int r = 0;
        if (s->m8 != lbl_805D5C18 && s->m3C == x && x != 3 && x == s->m38 && s->m28 != 0x11)
            r = 1;
        return r;
    }
    case 2: {
        PlayerSubX* s = (PlayerSubX*)&p->m58C;
        int r = 0;
        if (fn_80254B60((PlayerSub*)s) == 1 && (s->m30 == x || fn_80255028((PlayerSub*)s) == x))
            r = 1;
        return r;
    }
    case 3: {
        PlayerSubX* s = (PlayerSubX*)&p->m58C;
        if (fn_80254984((PlayerSub*)s) == 1) {
            if (x == 0) {
                if (s->m38 == -1)
                    return 1;
            } else if (s->m38 == x - 1)
                return 1;
        }
        return 0;
    }
    case 4:
        return fn_80254EA4(&p->m58C, 0) == x;
    case 5:
        return fn_802113E8(t, p, x);
    case 6:
        return *(int*)((char*)p + 0x5C4) == x;
    default:
        return 0;
    }
}

int fn_80211064(Sub* t, int kind, Player* p, int* out)
{
    int r = 0;
    volatile int e = 0;
    int c;
    while ((c = e) <= 3) {
        if (fn_802110F8(t, kind, p, c) == 1) {
            r = 1;
            if (out) {
                *out = e;
            }
            break;
        }
        int d = e;
        int n;
        if (d > 3) {
            n = d;
        } else {
            n = d + 1;
        }
        e = n;
    }
    return r;
}

/* near-miss: retail lays out li -1; b end between ble and addi r3,r3,1; ours speculates the addi above the ble */
int fn_802112B4(Sub* t, Player** out)
{
    void* list = t->m0->m0->m700->m3B4;
    Player* found = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80254A34(&p->m58C) == 1) {
            found = p;
            break;
        }
    }
    if (found) {
        *out = found;
        PlayerSub* s = &found->m58C;
        if (fn_80254B60(s) == 1) {
            return fn_80255028(s);
        }
        int v = s->m38;
        if (v <= 2) {
            return v + 1;
        }
    }
    return -1;
}

Player* fn_80211370(Sub* t)
{
    void* list = t->m0->m0->m700->m3B4;
    Player* found = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80254B60(&p->m58C) == 1) {
            found = p;
            break;
        }
    }
    return found;
}

extern const float lbl_805D5C2C;
extern const float lbl_805D5C30;
extern const float lbl_805D5C34;
extern const float lbl_805D5C38;
extern const float lbl_805D5C3C;
extern "C" int fn_8025995C(void* list, int id, float* a, int* b, int* c);

/* near-miss (30 slots): control flow, stack triple and calls match; retail keeps pl in r31 and &pl->m58C in r30 (ours the
   reverse) and loads a before the constant in each arm of the last compare */
struct Unk802113E8_Q {
    float a;
    int b;
    int c;
};

int fn_802113E8(Sub* t, Player* pl, int x)
{
    int r = 0;
    if (pl != 0) {
        PlayerSub* s = &pl->m58C;
        if (fn_80254984(s) == 1) {
            Unk802113E8_Q q;
            if (fn_8025995C(t->m0->m0->m700->m3B4, pl->m458, &q.a, &q.b, &q.c) == 1) {
                int k = fn_80254EA4(s, 0);
                int v = fn_80255028(s);
                if (v == -1)
                    v = q.c;
                if (k != -1 && k < q.b && (q.b != 3 || q.c != 0)) {
                    v = k;
                    q.c = k + 1;
                    q.a = lbl_805D5C2C;
                    q.b = k;
                }
                if (q.b == x) {
                    if (v == x || v == -1 || k == x) {
                        if (!(q.a >= lbl_805D5C30))
                            r = 1;
                    } else if (k != q.c) {
                        if (!(q.a >= lbl_805D5C34))
                            r = 1;
                    }
                } else if (q.c == x) {
                    if (!(q.a <= ((v != q.c && v != -1) ? lbl_805D5C3C : lbl_805D5C38)))
                        r = 1;
                }
            }
        }
    }
    return r;
}

int fn_8021157C(CmpPos* a, CmpPos* b)
{
    float d = a->m4 - b->m4;
    if (d < 0.0f) {
        return -1;
    }
    return d > 0.0f;
}

int fn_802115B8(CmpPos* a, CmpPos* b)
{
    float d = a->m4 - b->m4;
    if (d < 0.0f) {
        return -1;
    }
    if (!(d <= 0.0f)) {
        return 1;
    }
    float e = a->m8 - b->m8;
    if (e < 0.0f) {
        return -1;
    }
    return e > 0.0f;
}

int fn_80211624(CmpPos* a, CmpPos* b)
{
    return -fn_802115B8(a, b);
}

int fn_80211648(CmpPos* a, CmpPos* b)
{
    float d = a->m4 - b->m4;
    if (d < 0.0f) {
        return -1;
    }
    if (!(d <= 0.0f)) {
        return 1;
    }
    float e = a->m8 - b->m8;
    if (e < 0.0f) {
        return -1;
    }
    return e > 0.0f;
}

struct U;
void fn_8035B7D4(U* self);
void fn_8035B7B0(U* self);

struct Unk802116B4_El {
    int m0;
    float m4;
    float m8;
    Unk802116B4_El() { fn_8035B7B0((U*)this); }
};

inline void* operator new(unsigned, void* p) { return p; }

extern const char lbl_80660A78[];
extern const float lbl_805D5C50;
extern "C" void fn_8014E09C(IterObj* it, CtxOwner* c, int x);
extern "C" void fn_8014E108(IterObj* it);

struct Unk802116B4 {
    TaskInner* m0;
    int m4;
    const void* m8;
    Unk802116B4_El mC[9];
    Unk802116B4(TaskInner* a) : m0(a), m4(0), m8(lbl_80660A78)
    {
        IterObj it;
        fn_8014E09C(&it, m0->m0, 1);
        IterObj* p = &it;
        while (p->m8 != 10) {
            ((Unk802116B4_El*)((char*)this + p->m8 * 12 + 0xC))->m0 = p->m8;
            Unk802116B4_El* e = (Unk802116B4_El*)((char*)(p->m8 * 12 + (int)this) + 0xC);
            e->m4 = lbl_805D5C50;
            e->m8 = lbl_805D5C50;
            fn_8014E108(p);
        }
    }
};

extern "C" Unk802116B4* fn_802116B4(Unk802116B4* self, TaskInner* a)
{
    new (self) Unk802116B4(a);
    return self;
}

extern const float lbl_805D5C58;
extern "C" float fn_804028E4(float x); /* square root */
extern "C" void fn_8040A208(void* base, int n, int size, int (*cmp)(CmpPos*, CmpPos*));

extern "C" void* fn_8040B320(void* dst, int c, unsigned n, ...);
extern "C" void fn_801DC8C4(void* o, Vec3f* out);
extern "C" void fn_8021183C(Unk802116B4* o, Vec3f* pos, int flag);

struct Unk80211778_C {
    char pad0[0x3B8];
    void* m3B8;
};

struct Unk80211778_V : Vec3f {
    Unk80211778_V() { fn_8040B320(this, 0, 12); }
};

inline Vec3f FlatXZ1778(const Vec3f& v)
{
    Unk80211778_V r;
    r.x = v.x;
    r.z = v.z;
    return r;
}

/* by-value copies through two inline layers (each "Vec3f t = f(v); return t;" adds one 12-byte copy in retail) */
inline Vec3f Pass1778A(const Vec3f& v) { Vec3f t = FlatXZ1778(v); return t; }
inline Vec3f Pass1778B(const Vec3f& v) { Vec3f t = Pass1778A(v); return t; }
extern "C" void fn_80211778(Unk802116B4* o, int flag)
{
    Vec3f pos;
    fn_801DC8C4(((Unk80211778_C*)o->m0->m0->m700)->m3B8, &pos);
    pos = Pass1778B(pos);
    fn_8021183C(o, &pos, flag);
}

inline Vec3f Flat183C(PosObj* o)
{
    Vec3f v = o->m60;
    v.y = lbl_805D5C58;
    return v;
}

extern "C" void fn_8021183C(Unk802116B4* o, Vec3f* pos, int flag)
{
    IterObj it;
    fn_8014E09C(&it, o->m0->m0, 1);
    IterObj* p = &it;
    while (p->m8 != 10) {
        int i = p->m8;
        Vec3f w = Flat183C((PosObj*)ObjAt(o->m0->m8, i));
        *(float*)((char*)o + 0x14 + i * 12) = fn_804028E4((w.x - pos->x) * (w.x - pos->x) + (w.z - pos->z) * (w.z - pos->z));
        fn_8014E108(p);
    }
    if (flag)
        fn_8040A208(o->mC, 9, 12, fn_802115B8);
    else
        fn_8040A208(o->mC, 9, 12, fn_80211624);
    o->m4 = 1;
}

struct Unk8021195C_El {
    int m0;
    float m4;
    float m8;
    Unk8021195C_El() { fn_8035B7D4((U*)this); }
};

extern const char lbl_80660A60[];
extern const float lbl_805D5C5C;

struct Unk8021195C {
    int m0;
    int m4;
    const void* m8;
    Unk8021195C_El mC[4];
    Unk8021195C(int a) : m0(a), m4(0), m8(lbl_80660A60)
    {
        volatile int sp8 = 0;
        int e = 0;
        do {
            mC[e].m0 = e;
            int c = sp8;
            mC[c].m4 = lbl_805D5C5C;
            mC[c].m8 = lbl_805D5C5C;
            int t;
            if (c > 3)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 3);
    }
};

extern "C" Unk8021195C* fn_8021195C(Unk8021195C* self, int a)
{
    new (self) Unk8021195C(a);
    return self;
}

extern const Vec3f lbl_805D6760[];
extern const float lbl_805D5C60;

inline Vec3f Flat1A18(PosObj* o)
{
    Vec3f v = o->m60;
    v.y = lbl_805D5C60;
    return v;
}

/* near-miss (13 slots): frame layout now matches (counter as a plain int touched only through *(volatile int*)&cnt sits above
   the temps); left: y/z operand load order in the subtraction and the stfsx store form */
extern "C" void fn_80211A18(Unk802116B4* o, int idx)
{
    Vec3f a = Flat1A18((PosObj*)ObjAt(o->m0->m8, idx));
    int cnt = 0;
    int e = 0;
    do {
        Vec3f d = lbl_805D6760[e] - a;
        int c;
        *(float*)((char*)o + 0x14 + (c = *(volatile int*)&cnt) * 12) = fn_804028E4(d.x * d.x + d.y * d.y + d.z * d.z);
        int t;
        if (c > 3)
            t = c;
        else
            t = c + 1;
        *(volatile int*)&cnt = t;
        e = t;
    } while (e <= 3);
    fn_8040A208(o->mC, 4, 12, fn_80211648);
    o->m4 = 1;
}

void fn_80211B58(Slots4* s)
{
    volatile int sp8 = 0;
    int e = 0;
    do {
        s->m[e] = -1;
        int c = sp8;
        int t;
        if (c > 3) {
            t = c;
        } else {
            t = c + 1;
        }
        sp8 = t;
        e = t;
    } while (e <= 3);
}

void fn_80211BA0(Slots4* s, int i)
{
    s->m[i] = -1;
}

int fn_80211BB0(Slots4* s, int v)
{
    int found = -1;
    volatile int sp8 = 0;
    int e = 0;
    do {
        if (s->m[e] == v) {
            found = e;
        }
        int t;
        if (e > 3) {
            t = e;
        } else {
            t = e + 1;
        }
        sp8 = t;
        e = t;
    } while (e <= 3);
    return found;
}

void fn_80211C04(Ent38* e)
{
    e->m0 = -1;
    e->m4 = 0;
    e->m8 = 99.0f;
    e->mC = 0;
    e->m10 = 0;
    e->m14 = 0;
    e->m18 = 0;
    e->m1C = 0;
    e->m24 = 0;
    e->m28 = -1;
    e->m2C = lbl_806055DC;
}

inline void SetM0(EntList* l, float v)
{
    l->m0 = v;
}

void fn_80211C64(EntList* l)
{
    fn_80211CAC(l);
    l->mC0 = 0;
    SetM0(l, -99.0f);
}

void fn_80211CAC(EntList* l)
{
    l->m4 = 0;
    l->m8 = 0;
    for (int i = 0; i < 3; i++) {
        fn_80211C04(&l->mC[i]);
    }
    l->mB4 = 0;
    l->mB8 = 0;
    l->mBC = 0;
    fn_8035B940(&l->mC4, -1);
}

void fn_80211D14(EntList* l)
{
    Ent38* p = l->mC;
    for (int i = 0; i < 3; i++) {
        p->m20 = 0;
        p++;
    }
}

int fn_80211D34(EntList* l)
{
    return l->mC[l->m8].m24;
}

Vec3f fn_80211D48(EntList* l)
{
    return l->mC[l->m8].m2C;
}

int fn_80211D78(EntList* l)
{
    return l->mC[l->m8].m0;
}

int fn_80211D8C(EntList* l)
{
    int i = l->m8 + 1;
    if (i < l->m4) {
        return l->mC[i].m0;
    }
    return -1;
}

int fn_80211DB8(EntList* l)
{
    return l->mC[l->m8].m4;
}

int fn_80211DCC(EntList* l)
{
    return l->mC[l->m8].m10;
}

float fn_80211DE0(EntList* l)
{
    return l->mC[l->m8].m8;
}

int fn_80211DF4(EntList* l)
{
    return l->mC[l->m8].m18;
}

int fn_80211E08(EntList* l)
{
    return l->mC[l->m8].m1C;
}

int fn_80211E1C(EntList* l)
{
    return l->mC[l->m8].m20;
}

/* near-miss: block layout: retail duplicates the m10 compare in both type arms and shares the -1/1 tails */
int fn_80211E30(CmpKey* a, CmpKey* b)
{
    if (a->m4 == 7) {
        return -1;
    }
    if (b->m4 == 7) {
        return 1;
    }
    float d = a->mC - b->mC;
    int close = fabsf(d) < 0.01f;
    if (a->m4 == 1) {
        if (b->m4 != 1) {
            return -1;
        }
    } else {
        if (b->m4 == 1) {
            return 1;
        }
    }
    if (!close) {
        if (a->mC > b->mC) {
            return 1;
        }
        return -1;
    }
    if (a->m10 > b->m10) {
        return 1;
    }
    if (a->m10 < b->m10) {
        return -1;
    }
    return 0;
}

void fn_80211EF8(Rec2C* r)
{
    r->m0 = -1;
    r->m4 = -1;
    r->m8 = -1;
    r->mC = -1;
    r->m10 = 0;
    r->m14 = 0;
    r->m18 = 99.0f;
    r->m1C = 99.0f;
    r->m20 = -1.0f;
    r->m24 = 0;
}

void fn_80211F3C(Rec34* r)
{
    r->m0 = 0;
    r->m4 = 0;
    r->m8 = 0;
    r->mC = -99.0f;
    r->m14 = -99.0f;
    r->m10 = -99.0f;
    r->m18 = -99.0f;
    r->m1C = -99.0f;
    r->m20 = -99.0f;
    r->m24 = -99.0f;
    r->m28 = -99.0f;
    r->m2C = -99.0f;
}

void fn_80211F7C(Rec1C* r)
{
    r->m0 = -99.0f;
    r->m4 = -99.0f;
    r->m8 = lbl_806055DC;
    r->m14 = -1.0f;
}

void fn_80211FC0(Rec14* r)
{
    r->m0 = -99.0f;
    r->m4 = -1;
    r->m8 = 0;
    r->mC = 0;
}

void fn_80211FE4(Rec40* r)
{
    r->m0 = -1;
    r->m4 = 0;
    r->mC = 0;
    r->m28 = -99.0f;
    r->m8 = 100000000.0f;
    r->m10 = 0;
    r->m14 = 0;
    r->m18 = 0;
    r->m1C = 0;
    r->m20 = 0;
    r->m2C = -99.0f;
    r->m24 = 0;
    r->m30 = lbl_806055DC;
}

struct Unk80212054_Obj {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    Rec34 m1C[4];
    Rec1C mEC[4];
    Rec14 m15C[4];
    char pad1AC[0x2AC - 0x1AC];
    int m2AC;
    int m2B0;
    Rec2C m2B4[4];
};

inline Rec2C* RecA2054(Unk80212054_Obj* o, int i)
{
    if ((unsigned)(i - 9) > 3)
        return 0;
    return (Rec2C*)((char*)o + (i * 0x2C + 0x128));
}

inline Rec40* RecB2054(Unk80212054_Obj* o, int i)
{
    if ((unsigned)(i - 9) > 3)
        return 0;
    return (Rec40*)((char*)o + (i * 0x40 - 0x94));
}

void fn_80212054(Unk80212054_Obj* o)
{
    for (int i = 0; i < 4; i++) {
        fn_80211EF8(&o->m2B4[i]);
        fn_80211F3C(&o->m1C[i]);
        fn_80211F7C(&o->mEC[i]);
        fn_80211FC0(&o->m15C[i]);
    }
    volatile int sp8 = 9;
    int e = 9;
    do {
        fn_80211EF8(RecA2054(o, e));
        fn_80211FE4(RecB2054(o, sp8));
        int c = sp8;
        int t;
        if (c > 0x15)
            t = c;
        else
            t = c + 1;
        sp8 = t;
        e = t;
    } while (e <= 12);
    o->m4 = 0;
    o->m8 = 0;
    o->m10 = -1;
    o->mC = -1;
    o->m14 = 0;
    o->m18 = 0;
    fn_8035B940(&o->m2AC, -1);
}

void fn_80212170(Pair2* p, int i, int v)
{
    p->m4[i] = v;
}

void fn_80212180(Pair2* p)
{
    for (int i = 0; i < 2; i++) {
        fn_80212170(p, i, -1);
    }
    p->m0 = 0;
}

void fn_8021239C(Obj74* o, int a, float f, Vec3f* v)
{
    o->m74 = a;
    o->m78 = f;
    o->m7C = *v;
}

void fn_802123D4(Task* t, int kind, int)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    for (int i = 0; i < n; i++) {
    }
    q->count = 0;
    if (kind == 1) {
        int id = t->m9C->m3A5C;
        int idx = fn_80211BB0(&t->m9C->mC0, id);
        if (idx != -1) {
            fn_80211BA0(&t->m9C->mC0, idx);
        }
        idx = fn_80211BB0(&t->m9C->mD4, id);
        if (idx != -1) {
            fn_80211BA0(&t->m9C->mD4, idx);
        }
    }
}

extern Vec3f lbl_805D5C98;
/* The zero comes from a global struct (lbl_805D5C98): a load from an aggregate stays below the
   record stores, as in retail (a scalar or literal float is hoisted above them). */
extern Vec3f lbl_805D5C98;
void fn_8021247C(Task* t)
{
    RecQueue* q = t->m9C->m3A60;
    if (q->count <= 0) return;
    Rec* e = &q->e[0];
    e->mA4 = 1;
    e->m80 = lbl_805D5C98.x;
    e->m9C = 0;
    e->mAC = 0;
}

void fn_802124B8(Task* t)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 1;
    e->m0 = 1;
}

void fn_80212550(Task* t, Vec3f* pos, float a, float b, int c, int d)
{
    TaskInner* in = t->m9C;
    PosObj* obj = (PosObj*)in->m8[in->m3A5C];
    RecQueue* q = in->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 5;
    e->m0 = 0x1B;
    e->mC = d;
    e->m8 = c;
    e->m9C = 1;
    e->m38 = *pos;
    e->m88 = a;
    e->m80 = b;
    e->m94 = 1;
    e->m50 = *pos - obj->m60;
}

void fn_80212A28(Task* t, float f, int a, int b, int c, int d)
{
    TaskInner* in = t->m9C;
    if (in->m30 == 1 && in->m3A60->count <= 0) {
        if (fn_8026DAE8(in->m8[in->m3A5C], 0)) {
            fn_80214CE8(t, f, a, b, c, d);
        }
    }
}

}
