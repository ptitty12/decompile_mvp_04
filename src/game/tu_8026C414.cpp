/*
 * Game code, .text 0x8026C414-0x8026DDE8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8026C414.h"
#include "game/chooser.h"

typedef Unk8026C414_O O;
typedef Unk8026C414_X X;
typedef Unk8026C414_W W;

typedef Unk8026C414_M M;
typedef Unk8026C414_E E;
typedef Unk8026C414_V3 V3;

/* View of the mover for fn_8026CCF8: three V3 slots (+0x8C source, +0x200 current, +0x22C saved) and the
   stream cursor object at +0x1A0 (its first word is cleared). */
struct Unk8026CCF8_M {
    char pad0[0x8C];
    Unk8026C414_V3 m8C;
    char pad98[0x1A0 - 0x98];
    int m1A0;
    char pad1A4[0x200 - 0x1A4];
    Unk8026C414_V3 m200;
    char pad20C[0x22C - 0x20C];
    Unk8026C414_V3 m22C;
    char pad238[0x240 - 0x238];
    int m240;
};

extern "C++" {
int fn_8026D55C(O* self, X* ctx);
void fn_8026AA0C(int a, int b);
int fn_80247858(O* o, float* f);
void fn_8037D92C(M* m, char** pp);
void fn_8037DAD0(M* m, char** pp);
int fn_8026CE60(int a, float* v);
void fn_8031925C(void* x);
/* near-miss: retail emits the flag read-modify-write before loading the 0.0f constant; ours hoists the lfs and orders the stores differently */
void fn_8026CB30(M* self, int i);
void fn_8026CCF8(M* self, int i, int* a, int* b);
float fn_8037B1F0(X* x);
float fn_80382BB8(W* w);
float fn_80382BD8(W* w, int a);
}

inline int Ge(int s, int lo)
{
    return s >= lo;
}

void fn_8026C630()
{
    fn_8026AA0C(1, 0xFFFF);
}

struct Unk8026C8FC_V4 {
    int a;
    int b;
    int c;
    int d;
};
extern Unk8026C8FC_V4 lbl_8069429C;
extern V3 lbl_806055AC;

struct Unk8026C8FC_B {
    int m0;
    char pad4[0x5C];
    float m60;
    float m64;
    float m68;
    int m6C;
    float m70;
    float m74;
    float m78;
    Unk8026C8FC_V4 m7C;
    float m8C;
    float m90;
    float m94;
    inline void Reset()
    {
        m0 = 0;
        m6C = 0;
        m94 = 1.0f;
        m90 = 1.0f;
        m8C = 1.0f;
        m78 = 0.0f;
        m74 = 0.0f;
        m70 = 0.0f;
        m7C = lbl_8069429C;
        m68 = 0.0f;
        m64 = 0.0f;
        m60 = 0.0f;
    }
};

struct Unk8026C8FC_M : Unk8026C8FC_B {
    char pad98[0x240 - 0x98];
    int m240;
    char pad244[0x264 - 0x244];
    int m264;
    char pad268[0x280 - 0x268];
    Unk8026C8FC_B m280;
    char pad318[0x320 - 0x318];
    V3 m320;
    V3 m32C;
    V3 m338;
    V3 m344;
    float m350;
};

void fn_8026C8FC(Unk8026C8FC_M* s)
{
    s->Reset();
    s->m240 = 1;
    s->m264 = 1;
    s->m320 = lbl_806055AC;
    s->m32C = lbl_806055AC;
    s->m338 = lbl_806055AC;
    s->m344 = lbl_806055AC;
    s->m280.Reset();
    s->m350 = 0.0f;
}

void fn_8026CA58() {}

void fn_8026CA5C(M* self)
{
    if (self->m240 == 0)
        fn_8031925C(self->m244);
}

/* near-miss (parked, same 41 insns): scheduling/register differences around the packed-word build (retail builds the bool with li r7,0 / beq / li r7,1 and forms &p in r30 up front) */
int fn_8026CA8C(M* self, char** pp)
{
    Unk8026CA8C_W w;
    char* p = *pp;
    w.f0 = self->m264;
    w.f1 = self->m268;
    w.f4 = self->m354;
    w.f22 = self->m6C != 0;
    *(Unk8026CA8C_W*)p = w;
    p += 4;
    if (self->m264 == 0) {
        fn_8037D92C(self, &p);
        fn_8037DAD0(self, &p);
    }
    *pp = p;
    return 1;
}

/* near-miss: retail emits the flag read-modify-write before loading the 0.0f constant; ours hoists the lfs and orders the stores differently */
void fn_8026CB30(M* self, int i)
{
    E* e = (E*)((char*)(i * 0x20 + (int)self) + 0xC4);
    e->f0 = 1;
    e->f1 = 0;
    e->f4 = 0;
    e->m10 = 0.0f;
    e->m14 = -1;
    e->m18 = 0;
    e->m1C = 0;
}

extern V3 lbl_806055AC;

V3 fn_8026CB70(M* self, int i)
{
    return self->e[i].pos;
}

void fn_8026CB9C(M* self, int i)
{
    E* d = &self->e[i];
    E* s = &self->e[1];
    *d = *s;
}

extern void fn_8037DB54(void* obj, int* a, int* b, int bitA, int bitB, float f);
void fn_8026CCF8(M* self, int i, int* a, int* b)
{
    Unk8026CCF8_M* m = (Unk8026CCF8_M*)self;
    E* e = &self->e[i];
    int* c = &m->m1A0;
    *a = e->m18;
    *b = e->m1C;
    m->m240 = (unsigned)*(int*)((char*)e + 0xC) >> 31;
    m->m1A0 = 0;
    m->m22C = m->m8C;
    m->m1A0 = 0;
    m->m200 = e->pos;
    float f = e->m10;
    if (*(int*)((char*)e + 0xC) >= 0) {
        int pa = *a;
        int wa = *(int*)pa;
        *a = pa + 0x10;
        int pb = *b;
        int wb = *(int*)pb;
        *b = pb + 0x10;
        fn_8037DB54(c, a, b, (wa >> 9) & 1, (wb >> 9) & 1, f);
    }
}

void fn_8026CDE4(M* self, int i)
{
    int a = 0;
    int b = 0;
    fn_8026CCF8(self, i, &a, &b);
}

void fn_8026CE18(M* self, int i)
{
    fn_8026CB30(self, i);
    ((Unk8026C414_VT98*)self)->s9(1);
}

extern Unk80273498_Vec3 fn_8014E388(int idx);
int fn_8026CE60(int a, float* v)
{
    Unk80273498_Vec3 p;
    switch (a) {
    case 3:
        return v[0] > v[2];
    case 1:
        return v[0] < v[2];
    case 0:
        p = fn_8014E388(0);
        return v[0] < p.z - v[2];
    case 2:
        p = fn_8014E388(2);
        return p.x - v[0] < v[2];
    }
    return 1;
}

int fn_8026CF70(O* self, Unk8026CF70_P* p, int* out1, int* out2, float* fp)
{
    *out1 = fn_80247858(self, fp);
    *out2 = 1;
    int r = 0;
    if (!(*fp >= 230400.0f)) {
        if (*out1 == p->m5BC) {
            *out2 = fn_8026CE60(*out1, p->m60);
            r = 1;
        }
    }
    return r;
}

float fn_8026D504(O* self, X* ctx)
{
    float r = 0.0f;
    if (ctx != 0 && (ctx->mBC & 1))
        r = fn_8037B1F0(ctx);
    else
        r = fn_80382BB8(self->m618);
    return r;
}

int fn_8026D55C(O* self, X* ctx)
{
    return ctx ? ctx->mCC : self->m618->m830;
}

int fn_8026D578(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 4;
}

int fn_8026D5A4(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 5;
}

int fn_8026D5D0(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 6;
}

int fn_8026D5FC(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 7;
}

int fn_8026D628(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 8;
}

int fn_8026D654(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 10;
}

int fn_8026D680(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 11;
}

int fn_8026D6AC(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 12;
}

int fn_8026D6D8(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 13;
}

int fn_8026D704(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 14;
}

int fn_8026D730(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 15;
}

int fn_8026D75C(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 16;
}

int fn_8026D788(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 17;
}

int fn_8026D7B4(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 20;
}

int fn_8026D7E0(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 24;
}

int fn_8026D80C(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 27;
}

int fn_8026D838(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 28;
}

int fn_8026D864(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 29;
}

int fn_8026D890(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 30;
}

int fn_8026D8BC(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 32;
}

int fn_8026D8E8(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 33;
}

int fn_8026D914(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 34;
}

int fn_8026D940(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 27)
        r = Ge(s, 20);
    return r;
}

int fn_8026D988(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 15)
        r = Ge(s, 13);
    return r;
}

int fn_8026D9D0(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 29)
        r = Ge(s, 28);
    return r;
}

int fn_8026DA18(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 31)
        r = Ge(s, 30);
    return r;
}

int fn_8026DA60(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 22 || s == 25)
        r = 1;
    return r;
}

int fn_8026DAA4(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 23 || s == 26)
        r = 1;
    return r;
}

int fn_8026DAE8(O* self, X* ctx)
{
    switch (fn_8026D55C(self, ctx)) {
    case 3:
    case 4:
    case 7:
    case 16:
        return 1;
    }
    return 0;
}

int fn_8026DB3C(O* self, X* ctx)
{
    int s = fn_8026D55C(self, ctx);
    float f = 0.0f;
    if (ctx == 0)
        f = fn_80382BD8(self->m618, 0);
    switch (s) {
    case 3:
    case 4:
    case 7:
    case 16:
    case 20:
        return 1;
    case 12:
        return f <= 0.1f;
    case 13:
    case 14:
    case 15:
        return f > 0.8f;
    }
    return 0;
}

int fn_8026DC18(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 9 || s == 11)
        r = 1;
    return r;
}

int fn_8026DC5C(O* self, X* ctx)
{
    int s = fn_8026D55C(self, ctx);
    int r = 0;
    float f = 0.0f;
    if (ctx == 0)
        f = fn_80382BD8(self->m618, 0);
    switch (s) {
    case 9:
    case 10:
    case 11:
    case 24:
    case 25:
    case 26:
        r = 1;
        break;
    case 12:
        r = f > 0.1f;
        break;
    case 13:
    case 14:
    case 15:
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

int fn_8026DD18(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 19)
        r = Ge(s, 16);
    return r;
}

int fn_8026DD60(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 14 || s == 19)
        r = 1;
    return r;
}

int fn_8026DDA4(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 22 || s == 25)
        r = 1;
    return r;
}
