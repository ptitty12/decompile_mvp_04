/*
 * Game code, .text 0x80264378-0x80268190 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"
#include "game/tu_80268190.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

extern "C++" {
struct Unk80266418_R {
    P* m0[4];
    P* m10[4];
    P* m20[4];
    P* m30[4];
    int m40;
};
typedef Unk80266418_R R4;
void fn_80265EA4(void* self);
void* fn_8035E604(void* p);
void fn_802663B8(void* p);
void fn_802663D8(R4* r);
void fn_80266434(R4* r, P* p, int a);
void fn_80266CC0(void* p);
void fn_8037893C(void* p, int a, int b, int c, int d);
void fn_8025713C(void* list, int a);
void fn_8025D054(I* self, int a);
void fn_80265DDC(I* self);
void fn_80265E40(I* self);
void fn_80267458(void* self, P** a, int* b);
void fn_80251124(P* p);
void fn_8025124C(P* p);
void fn_80251374(P* p);
void fn_8025147C(P* p);
int fn_801DC1CC(int a, int b, int c);
}


/* Manager object of fn_80267F34 (see Unk80268190_M): four 0x18-byte entries at +8 whose sub-object at +0x10
   is the Unk8035E4D8 pair, vptr (retail data object lbl_80661800) at +0x68. */
struct Unk8035E4D8_S {
    int m0;
    int m4;
    void Clear()
    {
        m4 = 0;
        m0 = 0;
    }
};
struct Unk8035E4D8 {
    int m0;
    int m4;
    int m8;
    int mC;
    Unk8035E4D8_S m10;
    Unk8035E4D8();
};
extern char lbl_80661800[];
struct Unk80267F34_C {
    Unk80268190_Q* m0;
    int m4;
    Unk8035E4D8 e[4];
    const void* m68;
    Unk80267F34_C(Unk80268190_Q* q);
};

inline void EntReset(Unk8035E4D8* e)
{
    e->m4 = 0;
    e->m0 = 0;
    e->m8 = 0;
    e->mC = -1;
    e->m10.Clear();
}

inline Unk80268190_Q* SetVp(Unk80267F34_C* c, Unk80268190_Q* q)
{
    c->m68 = lbl_80661800;
    return q;
}

inline int EntLevel(Unk8024EF40_Ent* e)
{
    return *((unsigned char*)e + 0x1CC9);
}

void fn_802647C0(I* self, int a)
{
    if (EntLevel(self->m1EC->m6F8->m14) > 2) {
        fn_8025D054(self, 9);
        fn_8025713C(self->m1F0, 1);
        fn_80265DDC(self);
    } else {
        fn_8025713C(self->m1F0, a);
        if (a != 0)
            fn_80265DDC(self);
        else
            fn_80265E40(self);
    }
}

typedef Unk80268190_M M8;
typedef Unk80268190_Pl Pl8;
extern "C++" {
void fn_80268144(M8* m);
void fn_802680B0(M8* m, int i);
void fn_80242E28(Pl8* p, float f);
int fn_8035DA58(void* p);
}


/* Tracker object (fn_80266568 ctor): m0 world, m4 mode, m8/mC/m10 copied from the world's context
   (fn_802665B4), m14 = world->m6CC, four {value, valid} slots at +0x18 (fn_80266D70). */
struct Unk80266568_Slot {
    float v;
    int f;
};
struct Unk80266568_V3 {
    int a;
    int b;
    int c;
};
struct Unk80266568_Rec {
    int a0;
    int a4;
    Unk80266568_V3 pos;
    float a14;
    int a18;
    void Reset();
};
struct Unk80266568_T {
    Unk8024EF40_Q* m0;
    int m4;
    Unk8024EF40_Ctx* m8;
    void* mC;
    int m10;
    P* m14;
    Unk80266568_Slot s[4];
    Unk80266568_Rec m38;
};
typedef Unk80266568_T T;
struct Unk80267EEC_O {
    char pad0[0x460];
    int m460;
};
struct Unk8026774C_V {
    float x;
    float y;
    float z;
};
extern Unk8026774C_V lbl_805DBA34;
extern Unk80266568_V3 lbl_806055AC;
inline void Unk80266568_Rec::Reset()
{
    a18 = 0;
    a0 = 0;
    a4 = 0;
    pos = lbl_806055AC;
    a14 = 0.0f;
}

extern "C++" {
int fn_801DC67C(int a);
int fn_801BBF24(int a);
void fn_80266CC0(void* p);
float fn_80266FE8(T* t, int k);
}

P* fn_80264844(I* self)
{
    return self->m434;
}

void fn_80265858(void* self)
{
    fn_80265EA4(self);
}

void fn_80265878()
{
}

void fn_8026587C() {}

void fn_80265DDC(I* self)
{
    unsigned t = self->m44C;
    if ((t & 0x40000000) == 0) {
        self->m44C = t | 0x40000000;
        fn_8037893C((char*)self->m1EC + 0x704, 0x37, 0, 0, 0);
    }
    self->m44C = self->m44C & 0xDFFFFFFF;
}

void fn_80265E40(I* self)
{
    unsigned t = self->m44C;
    if ((t & 0x40000000) != 0) {
        self->m44C = t & 0xBFFFFFFF;
        fn_8037893C((char*)self->m1EC + 0x704, 0x38, 0, 0, 0);
    }
    self->m44C = self->m44C | 0x20000000;
}

void fn_80265EA4()
{
}

void* fn_80266358(void* self)
{
    fn_8035E604(self);
    return self;
}

void* fn_80266388(void* self)
{
    fn_802663B8(self);
    return self;
}

void fn_802663B8(void* self)
{
    fn_802663D8((R4*)self);
}

void fn_802663D8(R4* self)
{
    for (int i = 0; i < 4; i++) {
        self->m0[i] = 0;
        self->m30[i] = 0;
        self->m10[i] = 0;
        self->m20[i] = 0;
    }
    self->m40 = 6;
}

void fn_80266418(R4* self, int a)
{
    self->m40 = a;
}

void fn_80266420(R4* self, P* p)
{
    self->m0[p->m458 - 9] = p;
}

void fn_80266434(R4* self, P* p, int a)
{
    int idx = p->m458 - 9;
    if (a == 1)
        self->m10[idx] = p;
    else
        self->m30[idx] = p;
}

void fn_80266464(R4* self, P* p)
{
    self->m20[p->m458 - 9] = p;
}

void fn_8026647C(R4* self)
{
    for (int i = 0; i < 4; i++) {
        if (self->m30[i] != 0)
            fn_8025124C(self->m30[i]);
        if (self->m10[i] != 0)
            fn_8025147C(self->m10[i]);
        if (self->m20[i] != 0)
            fn_80251374(self->m20[i]);
        if (self->m0[i] != 0 && self->m40 == 6)
            fn_80251124(self->m0[i]);
    }
}

void fn_8026651C(R4* self, P* p)
{
    int t = p->m58C.m28;
    int lo = 11;
    if (t >= lo) {
        if (t > 13) {
            if (t <= 16)
                fn_80266434(self, p, 1);
        } else
            fn_80266434(self, p, 0);
    }
}

T* fn_80266568(T* self, Unk8024EF40_Q* q, int b)
{
    self->m0 = q;
    self->m4 = b;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 0;
    fn_80266CC0(self);
    return self;
}

void fn_802665B4(T* self)
{
    Unk8024EF40_Q* q = self->m0;
    self->m14 = q->m6CC;
    Unk8024EF40_Ctx* c = q->m700;
    self->m8 = c;
    self->mC = c->m3B4;
    self->m10 = c->m3B8;
}

int fn_802665DC(void* x, int a, int b, int c)
{
    int r = 6;
    if (c != 0) {
        if (a == 1) {
            switch (b) {
            case 0: r = 4; break;
            case 1: r = 5; break;
            case 2: r = 6; break;
            }
        } else {
            switch (b) {
            case 0: r = 4; break;
            case 1: r = 4; break;
            case 2: r = 5; break;
            }
        }
    } else {
        if (a == 1) {
            switch (b) {
            case 0: r = 2; break;
            case 1: r = 3; break;
            case 2: r = 6; break;
            }
        } else {
            switch (b) {
            case 0: r = 1; break;
            case 1: r = 2; break;
            case 2: r = 3; break;
            }
        }
    }
    return r;
}

int fn_80266784(T* self)
{
    int c = fn_801BBF24(self->m0->m700->m3BC) == 6 ? 0 : 1;
    int r = 0;
    if (c == 0) {
        P* p = self->m14;
        int t = 0;
        if (p != 0 && p->m388 == 3)
            t = p->m38C == 1;
        r = t;
    }
    return r;
}

void fn_80266CC0(T* self)
{
    int t;
    self->m38.Reset();
    self->s[0].f = 0;
    self->s[1].f = 0;
    t = self->m10;
    self->s[2].f = 0;
    self->s[3].f = 0;
    if (t != 0 && fn_801DC67C(t) == 0) {
        self->s[0].v = 100.0f;
        self->s[1].v = 100.0f;
        self->s[2].v = 100.0f;
        self->s[3].v = 100.0f;
    }
}

void fn_80266D6C() {}

/* near-miss (parked, 44 vs 44 insns): retail forms the slot address (addi r9,self,0x18) after the >? diamond, ours hoists it above the compare */
float fn_80266D70(T* self, int k)
{
    if (self->m10 == 0 || fn_801DC67C(self->m10) == 0)
        return 100.0f;
    if (self->s[k].f == 0) {
        float lo = 0.0f;
        float v = fn_80266FE8(self, k);
        self->s[k].v = v >? lo;
        self->s[k].f = 1;
    }
    return self->s[k].v;
}

int fn_80267410(void* self)
{
    int x;
    int* px = &x;
    P* p = 0;
    fn_80267458(self, &p, px);
    int r = 12;
    if (p->m458 == 5)
        r = 13;
    return r;
}

int fn_8026774C(void* self, Unk8026774C_V* pos, float t)
{
    return (pos->x - lbl_805DBA34.x) * (pos->x - lbl_805DBA34.x) + (pos->z - lbl_805DBA34.z) * (pos->z - lbl_805DBA34.z) < t * (t * 144.0f);
}

int fn_802679D4(T* self, int a, int b)
{
    return fn_801DC1CC(self->m10, a, b);
}

int fn_80267EEC(T* self)
{
    P* p = self->m14;
    if (p == 0)
        return 0;
    Unk80267EEC_O* o = (Unk80267EEC_O*)p->m36C;
    if (o == 0) {
        o = (Unk80267EEC_O*)p->m378;
        if (o == 0)
            return 0;
    }
    return (unsigned)(o->m460 - 6) <= 2;
}

/* 80267F34 */
Unk80267F34_C::Unk80267F34_C(Unk80268190_Q* q) : m0(SetVp(this, q)), m4(0)
{
    EntReset(&e[0]);
    fn_80268144((M8*)this);
}

inline void SetTimer(Unk8035E4D8_S* s, float t)
{
    s->m0 = 1;
    s->m4 = (int)(t * 60.0f);
}

inline Unk8035E4D8_S* SubAt(Unk80267F34_C* m, int idx)
{
    return &m->e[idx].m10;
}

/* near-miss (parked, 15 vs 14 insns; same for fn_80267FFC / fn_80268054): retail computes (m458-9)*0x18 + self and reaches the sub-object
   with a pre-update load (lwzu 0x18(r9)); ours folds the -9 into the displacement and loads before the addi */
int fn_80267FC4(M8* self, Pl8* p)
{
    int ok = 0;
    int idx = p->m458 - 9;
    Unk8035E4D8_S* s = SubAt((Unk80267F34_C*)self, idx);
    if (s->m0 == 0 || s->m4 <= 0)
        ok = 1;
    return ok;
}

void fn_80267FFC(Unk80267F34_C* self, Pl8* p, float t)
{
    if (p != 0)
        SetTimer(&self->e[p->m458 - 9].m10, t);
}

void fn_80268054(Unk80267F34_C* self, Pl8* p)
{
    Unk8035E4D8_S* s = &self->e[p->m458 - 9].m10;
    if (fn_8035DA58(s) == 1) {
        if (s->m4 > 0)
            s->m4 = s->m4 - 1;
    }
}

void fn_802680B0(M8* m, int i)
{
    Pl8* p = PlayerAt(m->m0, i + 9);
    if (p != 0)
        fn_80242E28(p, 1.0f);
    EntReset(&((Unk80267F34_C*)m)->e[i]);
}

void fn_80268144(M8* m)
{
    m->m4 = 0;
    for (int i = 1; i <= 3; i++)
        fn_802680B0(m, i);
}
