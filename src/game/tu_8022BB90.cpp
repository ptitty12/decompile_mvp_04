/*
 * Game code, .text 0x8022BB90-0x8022FE34 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8022BB90.h"
#include "game/goals/tu_8027C728.h"

void* operator new(unsigned int size, int heap);

inline void* operator new(unsigned int, void* p) { return p; }

struct Unk8022FE34_Ctx;
struct Unk8022FE34_Z {
    Unk8022FE34_Ctx* m0;
    Unk8022FE34_Z(Unk8022FE34_Ctx* c);
};
extern int lbl_806EF9B4;
extern char lbl_80660D80[];
extern int lbl_8061CCC4;
extern int lbl_8061CCC8;
extern int lbl_8061CCCC;
extern const Pair8 lbl_8060558C;
extern int lbl_80620750;
extern float lbl_80620754;

extern "C" {
void fn_801F0174(void* a, void* b, int c);
int fn_8022E5D8();
int fn_8022E610();
int fn_8022E648();
void fn_8022D708(int a, int b);
void fn_8035AB00(void* p);
Fe73C* fn_8022F17C(Fe73C* d, Fe8022* owner, int b);
void fn_8022E748(Fe8022* c);
void fn_8035DC4C(void* p, int x);
void __builtin_delete(void* p);
void fn_80377408(void* p);
void fn_8035DC00(void* p);
void fn_8022F264(Fe73C* d);
int fn_801A497C(FeOther* o, int k, int z);
int fn_802536D0(int o);
float fn_80232820(int p, FeOther* o, int k, float th);
int fn_8025416C(int* p, int z);
FeObj84* fn_801A6DB8(FeOther* o);
Player* fn_80257B40(void* list);
void fn_8022FF2C(Sub38* p, Fe73C* d);
void fn_8035DA48(void* p);
Sub440* fn_802376A0(Sub440* p, Fe73C* d, Fe8022* owner, int b);
int fn_802366B0();
FeOther* fn_80235FA8(Fe8022* c);
Pair8 fn_80235BE0(Fe8022* c, ...);
Pair8 fn_80235C18(Fe8022* c, ...);
int fn_802F92CC(int x);
void fn_8023262C(Fe73C* d);
void fn_80235780(Fe8022* c, int a, int b, int d);
void fn_802326C4(Fe73C* d, int x, int y);
void fn_8022F204(Fe73C* d);
void fn_8022F2B8(Fe73C* d, int v);
void fn_80237734(Sub440* p);
float fn_8023A888(Fe8022* c);
float fabsf(float x);
float fn_804028E4(float x);
}

extern "C" {

extern Vec3f lbl_805D669C;
void fn_8022BB90(void* a, void* b, RecQueue* q)
{
    Rec* e = &q->e[0];
    e->mA4 = 1;
    e->m80 = lbl_805D669C.x;
    e->m9C = 0;
    e->mAC = 0;
    fn_801F0174(a, b, 0);
}

void fn_8022BBD8() {}

struct Unk80270BA0_X;
Unk8027C728_Goal* fn_80244C84(Unk80270BA0_X* x);
extern "C" Vec3f fn_8018959C(Obj4_36C* c, float t);

extern float lbl_805D6730[1];

/* Unsigned-to-float in an inline: its constant-pool read stays below the int stores. */
inline float UF(unsigned v)
{
    return (float)v;
}

struct GoalSub54 {
    char pad0[0x54];
    float m54;
};

inline float SubF(GoalSub54* s)
{
    if (s != 0) {
        return s->m54;
    }
    return -1.0f;
}

void fn_8022D5F4(Task* t, int a)
{
    Unk8027C728_Goal* g = fn_80244C84((Unk80270BA0_X*)ObjAt(t->m9C->m8, a));
    GoalSub54* s;
    if (g != 0) {
        s = 0;
        if (g->m10 == 14) {
            s = (GoalSub54*)g->m18;
        }
    } else {
        s = 0;
    }
    float f = SubF(s);
    if (!(f <= 0.0f)) {
        t->m9C->mA4 = a;
        t->m9C->mA8 = f;
        TaskInner* in = t->m9C;
        in->mAC = fn_8018959C(in->m4, in->mA8 - UF(in->m0->m4C) * lbl_805D6730[0]);
    }
}

int fn_8022E5AC() { return fn_8022E5D8(); }

unsigned fn_8022E5CC() { return 0xDA07F2A0; }

int fn_8022E5D8() { return lbl_8061CCC4; }

int fn_8022E5E4() { return fn_8022E610(); }

unsigned fn_8022E604() { return 0xEC1BCE8D; }

int fn_8022E610() { return lbl_8061CCC8; }

int fn_8022E61C() { return fn_8022E648(); }

unsigned fn_8022E63C() { return 0xEAB27FC1; }

int fn_8022E648() { return lbl_8061CCCC; }

void fn_8022E654() { fn_8022D708(1, 0xFFFF); }

Fe8022* fn_8022E680(Fe8022* self, FeCtxA* a, int b)
{
    fn_8035AB00(self);
    self->vptr = lbl_80660D80;
    self->m4 = fn_8022F17C((Fe73C*)operator new(0x73C, 0), self, b);
    self->m8 = a;
    fn_8022E748(self);
    return self;
}

void fn_8022E6EC(Fe8022* self, int flags)
{
    self->vptr = lbl_80660D80;
    if (self->m4) {
        fn_8035DC4C(self->m4, 3);
    }
    if (flags & 1) {
        fn_80377408(self);
    }
}

void fn_8022E748(Fe8022* c)
{
    c->m68 = 0;
    FeSub* s = &c->mC;
    fn_8035DC00(s);
    s->m3C = 0;
    for (int i = 0; i < 5; i++) {
        s->m40 = 0;
    }
    fn_8022F264(c->m4);
    c->m78 = 0;
    c->m7C = 0;
    c->m64 = 0;
    c->m6C = -1.0f;
    c->m70 = 0;
    c->m74 = 0;
    c->m60 = 0;
    c->m80 = 0;
}

void fn_8022E7D0(Fe8022* c)
{
    fn_8022E748(c);
}

/* near-miss: retail reads th into f31 before the fn_80235FA8 call (arguments evaluated last-to-first here); 42 slots off.
   Tried th as the first parameter (63 insns, worse). */
float fn_8022E7F0(Fe8022* c, int k)
{
    float th = 80.0f;
    int p = 1;
    int o = fn_801A497C(fn_80235FA8(c), k, 0);
    if (o) {
        p = fn_802536D0(o);
        th = *(float*)((char*)c->m4 + 0x22C + k * 0x1F8) * 20.152f;
    }
    float q = fn_80232820(p, fn_80235FA8(c), k, th);
    if (fn_80235FA8(c)->m6F4 == 3) {
        th = th >? 50.0f;
    }
    return th * q * 0.056818184f;
}

void fn_8022E8E8(Fe8022* c)
{
    fn_8023262C(c->m4);
    fn_80235780(c, 3, 1, 1);
}

void fn_8022E92C(Fe8022* c, int x)
{
    fn_802326C4(c->m4, x, 0);
}

float fn_8022E954(Fe8022* c)
{
    return (float)c->m4->m438.m4 * 0.016666668f;
}

}

/* Called by tu_80271C64.cpp as fn_8022E998(int), so it is a C++ function here. */
int fn_8022E998(int a)
{
    Fe8022* c = (Fe8022*)a;
    FeCtxB* b = c->m8->m4;
    Player* p = b->m65C;
    if (p == 0) {
        return 0;
    }
    if (b->m6F4 == 2) {
        return 1;
    }
    switch (fn_8025416C(&p->m588, 0)) {
    case 0x275:
    case 0x276:
        return 1;
    }
    if ((unsigned)(p->m4C8 - 0x12) <= 1) {
        return 1;
    }
    if (fn_801A6DB8(fn_80235FA8(c))->m84 != 0) {
        return 1;
    }
    Player* l = fn_80257B40(c->m8->m3B4);
    if (l) {
        if ((unsigned)(l->m458 - 0xA) <= 2) {
            return 1;
        }
    }
    return 0;
}

extern "C" {

Pair8 fn_8022EA60(Fe8022* c)
{
    return c->m4->m28;
}

inline float AbsF(float v)
{
    return fabsf(v);
}

int fn_8022EA7C(Fe8022* c, Pair8* p, float eps)
{
    Pair8 v;
    if (p) {
        v = *p;
    } else {
        v = c->m4->m28;
    }
    int r = 0;
    if (!(AbsF(v.x) > eps)) {
        r = AbsF(v.y) <= eps;
    }
    return r;
}

int fn_8022EAF4(Fe8022* c, Pair8* p)
{
    int r = 0;
    if (p->x < -0.8f || p->y < -0.8f || p->x > 0.8f || !(p->y <= 0.8f)) {
        if (fn_8022EA7C(c, p, 1.0f)) {
            r = 1;
        }
    }
    return r;
}

int fn_8022EB74(Fe8022* c, Pair8* a, Pair8* b)
{
    const float th = 1.0f;
    if (!fn_8022EAF4(c, a) || !fn_8022EAF4(c, b)) {
        return 0;
    }
    float d = fn_804028E4((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
    return d <= th;
}

inline float Pick(Fe73C* d)
{
    if (lbl_80620750) {
        return lbl_80620754;
    }
    return d->m14;
}

int fn_8022EC1C(Fe8022* c)
{
    float v = Pick(c->m4);
    return fabsf(v) >= 0.75f;
}

int fn_8022EC70(Fe8022* c)
{
    Pair8 a = fn_80235C18(c);
    int r = 0;
    Pair8 b = fn_80235BE0(c);
    if (fn_8022EC1C(c) == 0 && fn_8022EA7C(c, &a, 1.0f) == 0 && fn_8022EA7C(c, &b, 1.0f) == 0) {
        r = fn_802F92CC(fn_80235FA8(c)->m720) == 1;
    }
    return r;
}

int fn_8022ED28(Fe8022* c)
{
    Pair8 a = fn_80235C18(c);
    int r = 0;
    Pair8 b = fn_80235BE0(c);
    if (fn_8022EC1C(c) == 0 && fn_8022EA7C(c, &a, 1.0f) == 1) {
        r = fn_8022EA7C(c, &b, 1.0f) == 0;
    }
    return r;
}

int fn_8022EDC4(Fe8022* c)
{
    Pair8 a = fn_80235C18(c);
    int r = 0;
    Pair8 b = fn_80235BE0(c);
    if (fn_8022EC1C(c) == 0 && fn_8022EAF4(c, &a) == 1) {
        r = fn_8022EA7C(c, &b, 1.0f) == 0;
    }
    return r;
}

int fn_8022EE5C(Fe8022* c)
{
    Pair8 a = fn_80235BE0(c);
    int r = 0;
    if (fn_8022EC1C(c) == 1) {
        r = fn_8022EA7C(c, &a, 1.0f) == 0;
    }
    return r;
}

int fn_8022EECC(Fe8022* c)
{
    Pair8 a = fn_80235C18(c);
    int r = 0;
    Pair8 b = fn_80235BE0(c);
    if (fn_8022EC1C(c) == 0 && fn_8022EA7C(c, &a, 1.0f) == 1 && fn_8022EA7C(c, &b, 1.0f) == 1) {
        r = fn_802F92CC(fn_80235FA8(c)->m720) == 1;
    }
    return r;
}

int fn_8022EF84(Fe8022* c)
{
    Pair8 a = fn_80235C18(c);
    int r = 0;
    Pair8 b = fn_80235BE0(c);
    if (fn_8022EC1C(c) == 0 && fn_8022EA7C(c, &a, 1.0f) == 0) {
        r = fn_8022EA7C(c, &b, 1.0f) == 1;
    }
    return r;
}

int fn_8022F024(Fe8022* c)
{
    Pair8 a = fn_80235C18(c);
    int r = 0;
    Pair8 b = fn_80235BE0(c);
    if (fn_8022EC1C(c) == 0 && fn_8022EB74(c, &a, &b) == 1) {
        r = fn_8022EA7C(c, &b, 1.0f) == 1;
    }
    return r;
}

int fn_8022F0C4(Fe8022* c)
{
    Pair8 a = fn_80235BE0(c);
    int r = 0;
    if (fn_8022EC1C(c) == 1) {
        r = fn_8022EA7C(c, &a, 1.0f) == 1;
    }
    return r;
}

int fn_8022F138(Fe8022* c)
{
    return fn_802F92CC(fn_80235FA8(c)->m720) == 0;
}

int fn_8022F168(Fe8022* c)
{
    return c->m4->m430;
}

void fn_8022F174(Fe8022* c, int v)
{
    c->m60 = v;
}

Fe73C* fn_8022F17C(Fe73C* d, Fe8022* owner, int b)
{
    d->m0 = b;
    d->m4 = owner;
    fn_8022FF2C(&d->m38, d);
    fn_8035DA48(&d->m438);
    fn_802376A0(&d->m440, d, owner, b);
    new (&d->m734) Unk8022FE34_Z((Unk8022FE34_Ctx*)b);
    d->m738 = 0;
    d->m738 = fn_802366B0();
    fn_8022F264(d);
    return d;
}

void fn_8022F204(Fe73C* d)
{
    d->m20 = lbl_8060558C;
    d->m28 = lbl_8060558C;
    d->m30 = lbl_8060558C;
    d->mC = 0;
    d->m10 = 0.0f;
    d->m14 = 0.0f;
    d->m1C = 0;
    d->m430 = 0;
    d->m434 = 0;
}

void fn_8022F264(Fe73C* d)
{
    d->m18 = 0;
    fn_8022F2B8(d, 0);
    fn_8022F204(d);
    d->m438.Clear();
    fn_80237734(&d->m440);
}

void fn_8022F2B8(Fe73C* d, int v)
{
    d->m8 = v;
}

int fn_8022F2C0(Fe8022* a, Fe8022* b)
{
    float d = fn_8023A888(a) - fn_8023A888(b);
    if (d > 0.0f) {
        return -1;
    }
    return d < 0.0f;
}

}
