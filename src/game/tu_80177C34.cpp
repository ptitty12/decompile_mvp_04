/*
 * Game code, .text 0x80177C34-0x8017A930 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80177C34.h"
#include "game/goals/tu_8027C728.h"
#include "game/goals/tu_8027A84C.h"
#include "game/tu_8017A930.h"
#include "game/tu_801A57C8.h"
struct Unk80177C74_T {
    int m0;
    float m4;
    Unk8014D8AC_Ctx* m8;
};
class Unk8017F628 {
public:
    virtual ~Unk8017F628();
};
void fn_8017EF78(void* p, void* ctx);
extern "C" void fn_80377408(void* p);
extern int lbl_8061C68C, lbl_8061C690;
extern int lbl_8061D3F8, lbl_8061D3FC, lbl_8061D400, lbl_8061D404, lbl_8061D408, lbl_8061D40C;
extern int lbl_8061D410, lbl_8061D414, lbl_8061D418, lbl_8061D41C;
void fn_80303E38(const char* fmt, float a, float b, ...);

inline void* operator new(unsigned int, void* p) { return p; }

void* operator new(unsigned int size, int heap);
struct Unk8017EE58_Ctx;
class Unk8017EDF0 {
public:
    Unk8017EDF0(Unk8017EE58_Ctx* ctx, int b);
    virtual ~Unk8017EDF0();
};
extern char lbl_806601F8[];
struct Unk801B7FB0_P;
class Unk801BA9CC {
public:
    Unk801BA9CC(int a, Unk801B7FB0_P* b);
};
extern "C" {
void* fn_8017F428(void* self, void* ctx);
void fn_8017EE7C(void* p);
void* fn_801C1B24(void* self, void* a, void* b);
void* fn_80176654(void* self, void* a, void* b);
void* fn_8022E680(void* self, void* a, void* b);
void* fn_8025700C(void* self, void* a, void* b);
void* fn_801DB974(void* self, void* a, void* b);
void* fn_801B659C();
}
void* fn_80178A98(void* self, void* a, void* b);
void fn_8017A880(void* p);
struct Unk801797C4_L {
    int m0;
    int m4;
};
struct Unk801797C4_Side {
    char pad0[0x74];
    Unk801797C4_L m74;
    char pad7C[0x3E8 - 0x7C];
    Unk801792BC_Ent m3E8[25];
};
extern "C" {
int fn_80097210(void* s, int i);
int fn_80099B50(void* s, int i);
}
int fn_80353870(void* p);
unsigned char* fn_80081CF8(void* p, int i);
extern "C" {
unsigned char fn_80097190(Unk801792BC_Side* s, int j);
int fn_80097300(Unk801792BC_Side* s, int x);
int fn_8008CFD8(void* p, int k);
}
void fn_8017940C(Unk80177C34_Sub* p, int v);
extern "C" {
Unk80273498_Vec3 fn_80183AB8(Unk80181140* o, int idx, unsigned int k);
float fn_80183B38(Unk80181140* o, int idx, unsigned int k);
void fn_8024C118(void* o);
}
struct Unk80178A98_R {
    char pad0[0x10];
    int m10;
};
extern "C" {
void* fn_8035AB00(void* self);
Unk80178A98_R* fn_801A6DB8(void* o);
}
struct Unk80178944_P {
    char pad0[0x8F8];
    Unk80273498_Vec3 m8F8;
    float m904;
};
struct Unk80178944_T {
    char padC[0xC];
    Unk80178944_P* mC;
    char pad10[0x28 - 0x10];
    Unk80273498_Vec3 m28;
};
class Unk8027DE3C {
public:
    Unk8027DE3C* fn_8027DED4();
};
Unk8027C728_Base* fn_8027DAE8(Unk8027C728_Base* b, Unk80273498_Vec3 v);
Unk8027D9A4* fn_8027DB38(Unk8027D9A4* d, Unk80273498_Vec3* p, Unk80273498_Vec3* q);
Unk8027D9A4* fn_8027DD54(Unk8027D9A4* d, float f);
extern const Unk80273498_Vec3 lbl_806055AC;
extern "C" {
Unk80273498_Vec3 fn_8018398C(Unk80181140* o, int idx);
float fn_801839F8(Unk80181140* o, int idx);
void fn_80198E70(void* o, int a);
}
void fn_80299B98(Unk80270BA0_X* x, const Unk80273498_Vec3& pos, float* ang);
class Unk8028B194 {
public:
    Unk8028B194* fn_8028B194(Unk80273498_Vec3 v);
};
class Unk80287D70 {
public:
    Unk80287D70* fn_80287DB8(int kind);
    void fn_80287D50(int v);
};
struct Unk80177DF0_T {
    char pad0[0x10];
    Unk80273498_Vec3 m10;
    char pad1C[0x28 - 0x1C];
    Unk80273498_Vec3 m28;
};
class Unk80299920_Goal {
public:
    int fn_80299F64(int v);
};
void fn_8027C728(Unk8027C728_Goal* g);
void fn_8027D368(Unk8027C728_Goal* g);
int fn_8027D3E8(Unk8027C728_Goal* g, int a, float* outF, Unk80273498_Vec3* pos6, Unk80273498_Vec3* pos7, float* out8);

inline Unk80273498_Vec3 operator*(const Unk80273498_Vec3& v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline float Unk80177C74_Rand(Unk8014D8AC* r, float s)
{
    return (float)(unsigned)r->fn_8014D8AC(1000000, "C:/mvp2004/source/common/ai/bullpen/bullpenai.cpp", 0x34C) * s * 0.000001f;
}

extern "C" {
void fn_80244A64(void* o, int a, int b);
void fn_8037EBE8(void* p);
void fn_803814A4(void* link, unsigned hash, int a, float b);
void fn_80198DD8(void* o, int a);
}
struct Vec2f_8061C678 {
    float x;
    float y;
};
extern Vec2f_8061C678 lbl_8061C678;
void fn_80303BC4(const char* fmt, float a, float b, ...);

struct Unk8027C728_Goal;
extern "C" Unk8027C728_Goal* fn_802448F4(void* o, int a);
void fn_8027D33C(Unk8027C728_Goal* g);
void fn_80177DF0(void* self, Unk8027C728_Goal* g);

extern char lbl_8065FBC8[];

void fn_80177C34(Unk80177C34_X* p, void* a)
{
    if (a != p->m40) {
        fn_80177900(p, p->m40);
        p->m40 = a;
    }
}

/* near-miss: 99.4%; the switch tree needs `case 1:` in the default group (a node that jumps to the default label
 * is balanced but emits no test). Only the first float loads differ (lo/s swap f0/f13, lis order). */
void fn_80177C74(void* self, int a)
{
    Unk80177C74_T* p = (Unk80177C74_T*)self;
    p->m0 = a;
    switch (a) {
    case 1:
    case 0:
        p->m4 = -1.0f;
        break;
    case 2: {
        float lo = 0.5f;
        float x;
        float hi;
        x = Unk80177C74_Rand(p->m8->m554, 1.0f);
        hi = 2.5f;
        p->m4 = x * (hi - lo) + lo;
        break;
    }
    case 3:
        p->m4 = (float)p->m8->m4C * 0.016666668f + 8.0f;
        break;
    case 4:
        p->m4 = -1.0f;
        break;
    case 5:
        p->m4 = (float)p->m8->m4C * 0.016666668f + 8.0f;
        break;
    default:
        p->m4 = -1.0f;
        break;
    }
}

void fn_80177DF0(void* self, Unk8027C728_Goal* g)
{
    Unk80177DF0_T* p = (Unk80177DF0_T*)self;
    g->m10 = 10;
    fn_8027C728(g);
    Unk8027A84C* b = (Unk8027A84C*)g->m18;
    ((Unk8028B194*)b)->fn_8028B194(p->m10);
    Unk80273498_Vec3 v = p->m28;
    b->fn_8027A898(&v);
    b->m38 = 1;
    b->m34 = 1;
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk8027A84C* c = (Unk8027A84C*)h->m18;
    ((Unk80287D70*)c)->fn_80287DB8(8);
    v = p->m28;
    c->fn_8027A898(&v);
    c->m38 = 1;
    c->m34 = 1;
}

void fn_80177EE0(void* self) /* 80177EE0 */
{
    Unk8027C728_Goal* g = fn_802448F4(*(void**)((char*)self + 0xC), 2);
    fn_80177DF0(self, g);
    fn_8027D33C(g);
}

void fn_801783BC(Unk80177C34_X* p, Unk80273498_Vec3* a, float* b)
{
    Unk8027C728_Goal* g = fn_802448F4(p->m40, 1);
    g->m10 = 5;
    fn_8027C728(g);
    Unk8027A84C* base = (Unk8027A84C*)g->m18;
    Unk80273498_Vec3 v = p->m28 * -1.0f;
    base->fn_8027A898(&v);
    ((Unk80299920_Goal*)base)->fn_80299F64(0x10);
    fn_8027D3E8(g, 3, b, a, 0, 0);
    fn_8027D368(g);
}

void fn_80178944(void* self)
{
    Unk80178944_T* p = (Unk80178944_T*)self;
    Unk8027C728_Goal* g = fn_802448F4(p->mC, 2);
    Unk80273498_Vec3 v = p->mC->m8F8;
    float f = p->mC->m904;
    g->m10 = 6;
    fn_8027C728(g);
    Unk8027D9A4* d = (Unk8027D9A4*)g->m18;
    fn_8027DB38(d, &p->m28, (Unk80273498_Vec3*)&lbl_806055AC);
    ((Unk8027C728_Base * (*)(Unk8027C728_Base*, const Unk80273498_Vec3&))fn_8027DAE8)(d, v);
    fn_8027DD54(d, f);
    ((Unk8027A84C*)d)->m38 = 3;
    ((Unk8027A84C*)d)->m34 = 3;
    ((Unk8027A84C*)d)->m40 = 9;
    ((Unk8027DE3C*)d)->fn_8027DED4();
    Unk8027C728_Goal* h = g->m0;
    h->m10 = 2;
    fn_8027C728(h);
    Unk8027A84C* c = (Unk8027A84C*)h->m18;
    ((Unk80287D70*)c)->fn_80287DB8(8);
    Unk80273498_Vec3 w = p->m28;
    c->fn_8027A898(&w);
    c->m38 = 1;
    c->m34 = 1;
    fn_8027D33C(g);
}

class Unk80178A64 {
public:
    virtual ~Unk80178A64();
};

/* 80178A64 */
Unk80178A64::~Unk80178A64() {}

Unk80178BBC_T* fn_80178A98(Unk80178BBC_T* self, int a, Unk80177C34_Ctx* ctx)
{
    fn_8035AB00(self);
    self->m0 = lbl_8065FBC8;
    Unk80177C34_Sub* s = self->mC;
    int i = 1;
    do {
        fn_801791A0(s);
        s++;
    } while (i-- != 0);
    Unk80178BBC_Entry* e = self->m134;
    int j = 1;
    do {
        fn_80179B58(&e->m0);
        e++;
    } while (j-- != 0);
    fn_801791DC((Unk801791DC_T*)&self->mC[0], 0, (int)ctx);
    fn_801791DC((Unk801791DC_T*)&self->mC[1], 1, (int)ctx);
    fn_80179B90((Unk80179B90_T*)&self->m134[0], 0, (int)ctx);
    fn_80179B90((Unk80179B90_T*)&self->m134[1], 1, (int)ctx);
    self->m4 = a;
    self->m8 = ctx;
    self->m14C = 1;
    int t = fn_801A6DB8(ctx)->m10;
    if (t == 0) {
        self->m14C = 0;
    }
    if (fn_80179464(&self->mC[0]) <= 0 || fn_80179464(&self->mC[1]) <= 0) {
        self->m14C = 0;
    }
    return self;
}

void fn_80178BB8() {}

void fn_80178BBC(Unk80178BBC_T* p)
{
    if (p->m14C != 0) {
        Unk80177C34_Sub* s = p->mC;
        for (int i = 0; i < 2; i++) {
            fn_80179784(s);
            s++;
        }
    }
}

void fn_80178C08() {}

void fn_80178C0C(Unk80178BBC_T* p)
{
    Unk80177C34_Sub* s = p->mC;
    Unk80178BBC_Entry* e = p->m134;
    for (int i = 0; i < 2; i++) {
        fn_80179BBC(e);
        e++;
        fn_80179250(s);
        s++;
    }
}

void fn_80178C5C(Unk80178BBC_T* p)
{
    if (p->m14C != 0) {
        Unk80177C34_Sub* s = p->mC;
        for (int i = 0; i < 2; i++) {
            fn_801797A4(s);
            s++;
        }
    }
}

void fn_80178CA8(Unk80178BBC_T* p)
{
    if (p->m14C != 0) {
        Unk80177C34_Sub* s = p->mC;
        for (int i = 0; i < 2; i++) {
            fn_8017946C(s);
            s++;
        }
    }
}

void fn_80178CF4() {}

void fn_80178CF8(void* self)
{
    Unk80178BBC_T* p = (Unk80178BBC_T*)self;
    Unk80177C34_Rec* r = p->m8->m6F8->m14;
    int a = r->mF78;
    int h = r->m114;
    if (a != 0) {
        fn_80303BC4("Away team attribute boost: %d", lbl_8061C678.x, lbl_8061C678.y - 0.03f, a);
    }
    if (h != 0) {
        fn_80303BC4("Home team attribute boost: %d", lbl_8061C678.x, lbl_8061C678.y - 0.06f, h);
    }
}

void fn_80178D9C(unsigned* p)
{
    if (*p > 1) {
        *p = 0;
    }
}

int fn_80178DB4(Unk80178BBC_T* p)
{
    if (p->m14C == 0) {
        return 0;
    }
    Unk80177C34_Ctx* c = p->m8;
    int t = c->m564->m14;
    if (t == 9 || t == 2 || t == 1) {
        if (c->m744->m20 == 0) {
            return 0;
        }
    }
    return 1;
}

/* near-miss: p and o swap callee-saved registers (r29/r30) in retail; 2 slots plus the address add order. */
int fn_80178E08(Unk80178BBC_T* p, Unk80179284_Ctx* o)
{
    unsigned sp = o->m708;
    fn_80178D9C(&sp);
    int r = fn_8017995C(p->mC[sp].m0, (int)o);
    return r == -1 ? 0 : 1;
}

int fn_80178E6C(Unk80178BBC_T* p, unsigned a, unsigned b)
{
    if (a > 1 || b > 8) {
        return 0;
    }
    return fn_80179990(p->mC[a].m0, b);
}

void fn_80178EBC(Unk80178BBC_T* p, Unk80179284_Ctx* o)
{
    unsigned sp = o->m708;
    fn_80178D9C(&sp);
    fn_80179284((Unk80179284_T*)&p->mC[sp], o);
}

void fn_80178F10(Unk80178BBC_T* p, Unk80179284_Ctx* o)
{
    unsigned sp = o->m708;
    fn_80178D9C(&sp);
    fn_80179648(&p->mC[sp], o);
}

void fn_80178F64(Unk80178BBC_T* p, Unk80179284_Ctx* o)
{
    unsigned sp = o->m708;
    fn_80178D9C(&sp);
    int k = 0;
    if (p->m8->m6F8->m14->m1CD0 != 0) {
        k = 1;
    }
    if (sp == k) {
        fn_80178D9C(&sp);
        fn_80179BE0(&p->m134[sp], o);
    }
}

void fn_80178FF0(Unk80178BBC_T* p)
{
    int k = 0;
    if (p->m8->m6F8->m14->m1CD0 != 0) {
        k = 1;
    }
    unsigned sp = k;
    fn_80178D9C(&sp);
    fn_80179CD0(&p->m134[sp]);
}

int fn_80179058(Unk80178BBC_T* p)
{
    int k = 0;
    if (p->m8->m6F8->m14->m1CD0 != 0) {
        k = 1;
    }
    unsigned sp = k;
    fn_80178D9C(&sp);
    return *(int*)((char*)p + sp * 12 + 0x134);
}

/* near-miss: retail stores the integer argument before spilling the float one (2 slots swapped). */
void fn_801790BC(Unk80178BBC_T* p, int a, int b, float f)
{
    unsigned sp = a;
    fn_80178D9C(&sp);
    fn_801799AC(&p->mC[sp], b, f);
}

void fn_80179114(Unk80178BBC_T* p, int a)
{
    unsigned sp = a;
    fn_80178D9C(&sp);
    *(int*)((char*)p + sp * 0x94 + 0x98) = 1;
}

int fn_8017915C(Unk80178BBC_T* p, int a)
{
    unsigned sp = a;
    fn_80178D9C(&sp);
    return *(int*)((char*)p + sp * 0x94 + 0x9C);
}

Unk80177C34_Sub* fn_801791A0(Unk80177C34_Sub* p)
{
    p->m84 = 0;
    p->m88 = 0;
    fn_80179208(p);
    return p;
}

void fn_801791DC(Unk801791DC_T* p, int a, int b)
{
    p->m84 = a;
    p->m88 = b;
    fn_80179250(p);
}

void fn_80179208(void* self)
{
    Unk80177C34_Sub* p = (Unk80177C34_Sub*)self;
    for (int i = 0; i < 25; i++) {
        p->m20[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        p->m0[i] = 0;
    }
    p->m8C = 0;
    p->m90 = 0;
}

void fn_80179250(void* self)
{
    fn_80179208(self);
    fn_801792BC(self);
}

int fn_80179284(Unk80179284_T* p, Unk80179284_Ctx* ctx)
{
    int v = ctx->m704;
    for (int i = 0; i < 14; i++) {
        if (p->m20[i] == v) {
            return 1;
        }
    }
    return 0;
}

/* near-miss: 98.8%; only the callee-saved pair is swapped (retail: j in r31, list pointer in r30; ours the reverse,
 * priorities 0.260 vs 0.267 in global alloc). Tried: j hoisted, no list local, ++j, do-while, byte temp. */
void fn_801792BC(void* self)
{
    Unk80177C34_Sub* p = (Unk80177C34_Sub*)self;
    Unk80177C34_Rec* r = p->m88->m6F8->m14;
    int off = p->m84 * 0xE64;
    Unk801792BC_Side* side = (Unk801792BC_Side*)((char*)r + off);
    for (int i = 0; i < 25; i++) {
        p->m20[i] = 0;
    }
    Unk801792BC_List* l = &side->m168;
    if (l->m4 != 0) {
        int first = fn_80097300(side, fn_80097190(side, 1));
        for (unsigned j = 0; j < l->m4; j++) {
            int t = fn_80097300(side, (unsigned char)j);
            if (first != t) {
                fn_8017940C(p, t);
            }
        }
    }
    for (unsigned k = 0; k < 25; k++) {
        int e = side->m3E8[(unsigned char)k].m0;
        if (e != 0) {
            int q = fn_8008CFD8(side->mC9C, 5);
            if (q != 0 && q != 10) {
                fn_8017940C(p, e);
            }
        }
    }
    for (unsigned k = 0; k < 25; k++) {
        int e = side->m3E8[(unsigned char)k].m0;
        if (e != 0) {
            fn_8017940C(p, e);
        }
    }
}

void fn_8017940C(Unk80177C34_Sub* p, int v)
{
    if (v != 0) {
        int i = 0;
        while (i <= 0x18) {
            int cur = p->m20[i];
            if (v == cur) {
                break;
            }
            if (cur == 0) {
                p->m20[i] = v;
                break;
            }
            i++;
        }
    }
}

int fn_80179464(Unk80177C34_Sub* s)
{
    return 6;
}

void fn_8017946C(Unk80177C34_Sub* p)
{
    Unk80177C34_Rec* r = p->m88->m6F8->m14;
    int off = p->m84 * 0xE64;
    if (((Unk80177C34_Rec*)((char*)r + off))->m108 != 0) {
        p->m90 = 1;
    }
    fn_801794B8(p);
}

void fn_80179648(void* self, void* obj)
{
    Unk80177C34_Sub* p = (Unk80177C34_Sub*)self;
    Unk80179648_Obj* o = (Unk80179648_Obj*)obj;
    int k = fn_8017995C(p->m0, (int)obj);
    if (k == -1) {
        if (o->m458 == 0xD) {
            o->fn_vslot8(1);
        }
    } else if (o != 0) {
        if (p->m8C != 0) {
            p->m90 = 1;
            p->m8C = 0;
        }
        if (o->m458 == 0x11 && p->m90 != 0) {
            fn_8024C118(o);
        }
        o->fn_vslot8(0);
        Unk80273498_Vec3 pos = fn_80183AB8(p->m88->m6B8, p->m84, k);
        float ang = fn_80183B38(p->m88->m6B8, p->m84, k);
        fn_80299B98((Unk80270BA0_X*)o, pos, &ang);
        Unk8027C728_Goal* g = fn_802448F4(o, 1);
        g->m10 = 0xB;
        fn_8027C728(g);
        ((Unk80287D70*)g->m18)->fn_80287D50(0xB632DA95);
        fn_8027D33C(g);
    }
}

void fn_80179784()
{
    fn_801794B8();
}

void fn_801797A4()
{
    fn_801794B8();
}

int fn_801797C4(Unk80177C34_Sub* self, int id)
{
    Unk80177C34_Rec* z = self->m88->m6F8->m14;
    int f = 0;
    if (z->m1CD0 != 0) {
        f = 1;
    }
    int e = z->m1CD0 == 0;
    Unk801797C4_Side* a = (Unk801797C4_Side*)((char*)z + f * 0xE64);
    Unk801797C4_Side* b = (Unk801797C4_Side*)((char*)z + e * 0xE64);
    int g = 0;
    if (z->m1CD0 != 0) {
        g = 1;
    }
    if (self->m84 == g) {
        Unk801792BC_Ent* t = a->m3E8;
        if (t[fn_80353870(a)].m0 == id) {
            return 0;
        }
        fn_80097300((Unk801792BC_Side*)a, fn_80097190((Unk801792BC_Side*)a, 1));
        for (int i = 0; i <= 2; i++) {
            int k = *fn_80081CF8(self->m88->m6F8->m14, i);
            if (k != 0xFF && t[k].m0 == id) {
                return 0;
            }
        }
        Unk801797C4_L* l = &a->m74;
        for (int i = 0; i < l->m4; i++) {
            if (fn_80099B50(a, i) == id) {
                return 0;
            }
        }
        return 1;
    } else {
        for (int i = 0; i <= 8; i++) {
            if (id == fn_80097210(b, i)) {
                return 0;
            }
        }
        Unk801797C4_L* l = &b->m74;
        for (int i = 0; i < l->m4; i++) {
            if (fn_80099B50(b, i) == id) {
                return 0;
            }
        }
        return 1;
    }
}

int fn_8017995C(int* arr, int v)
{
    for (int i = 0; i < 8; i++) {
        if (arr[i] == v) {
            return i;
        }
    }
    return -1;
}

int fn_80179990(int* arr, unsigned i)
{
    if (i > 8) {
        return 0;
    }
    return arr[i];
}

int* fn_80179B58(int* p)
{
    *p = 0;
    fn_80179BDC();
    return p;
}

void fn_80179B90(Unk80179B90_T* p, int a, int b)
{
    p->m4 = a;
    p->m8 = b;
    fn_80179BBC(p);
}

void fn_80179BBC(void* self)
{
    fn_80179BDC();
}

void fn_80179BDC() {}

void fn_80179BE0(void* self, void* a)
{
    Unk80179CD0_T* p = (Unk80179CD0_T*)self;
    p->m0 = (Unk80179CD0_Obj*)a;
    Unk80179CD0_Obj* o = p->m8->m6E8;
    fn_80198DD8(o, (int)a);
    fn_80198E70(o, 1);
    o->fn_vslot8(0);
    p->m0->fn_vslot8(0);
    Unk80273498_Vec3 pos = fn_8018398C(p->m8->m6B8, p->m4);
    float ang = fn_801839F8(p->m8->m6B8, p->m4);
    fn_80299B98((Unk80270BA0_X*)p->m0, pos, &ang);
    Unk8027C728_Goal* g = fn_802448F4(p->m0, 1);
    g->m10 = 0xB;
    fn_8027C728(g);
    ((Unk80287D70*)g->m18)->fn_80287D50(0x31CCCC85);
    fn_8027D33C(g);
}

void fn_80179CD0(void* self)
{
    Unk80179CD0_T* p = (Unk80179CD0_T*)self;
    if (p->m0 != 0) {
        p->m0->fn_vslot8(1);
        fn_80244A64(p->m0, 0, 0);
        fn_8037EBE8(*(void**)((char*)p->m0 + 0x618));
        fn_803814A4(*(void**)((char*)p->m0 + 0x618), 0, 0, 0.0f);
        Unk80179CD0_Obj* o = p->m8->m6E8;
        fn_80198DD8(o, 0);
        o->fn_vslot8(1);
        p->m0 = 0;
    }
}

void fn_8017A1FC(Unk8017B0A4_Ctx* p)
{
    if (lbl_8061C690 == 0) {
        lbl_8061C690 = 1;
    }
    if (lbl_8061C68C == 1) {
        float x = 0.75f;
        float y = 0.3f;
        const float dy = 0.05f;
        fn_80303E38("Bobbled = %d\n", x, y, lbl_8061D404);
        y = y + dy;
        fn_80303E38("Dropped = %d\n", x, y, lbl_8061D408);
        y = y + dy;
        fn_80303E38("Intent. Tip = %d\n", x, y, lbl_8061D400);
        y = y + dy;
        fn_80303E38("Intent. Miss = %d\n", x, y, lbl_8061D3FC);
        y = y + dy;
        fn_80303E38("Unintent. M. = %d\n", x, y, lbl_8061D3F8);
        y = 0.3f;
        x = 0.58f;
        fn_80303E38("Rout. = %d\n", x, y, lbl_8061D40C);
        y = y + dy;
        fn_80303E38("Easy = %d\n", x, y, lbl_8061D410);
        y = y + dy;
        fn_80303E38("Med. = %d\n", x, y, lbl_8061D414);
        y = y + dy;
        fn_80303E38("Hard = %d\n", x, y, lbl_8061D418);
        y = y + dy;
        fn_80303E38("Extr. = %d\n", x, y, lbl_8061D41C);
        y = y + dy;
    }
}

Unk8017A930_T* fn_8017A430(Unk8017A930_T* self, Unk8017B0A4_Ctx* ctx)
{
    fn_8035AB00(self);
    self->m4 = ctx;
    *(const void**)self = lbl_806601F8;
    new ((char*)self + 8) Unk8017EDF0((Unk8017EE58_Ctx*)ctx, (int)self);
    fn_8017F428((char*)self + 0x24, ctx);
    fn_8017EE7C((char*)self + 0x228);
    self->m3A4 = 0;
    self->m3A8 = 0;
    self->m3AC = 0;
    self->m3B0 = 0;
    self->m3B4 = 0;
    self->m3B8 = 0;
    self->m3BC = 0;
    self->m3C0 = 0;
    fn_8017A880(self);
    self->m3A4 = fn_801C1B24(operator new(0x2E4, 0x400), self, ctx);
    self->m3A8 = (char*)fn_80176654(operator new(0x178, 0x400), self, ctx);
    self->m3AC = fn_80178A98(operator new(0x150, 0x400), self, ctx);
    self->m3B0 = fn_8022E680(operator new(0x84, 0x400), self, ctx);
    self->m3B4 = fn_8025700C(operator new(0x24, 0x400), self, ctx);
    self->m3B8 = fn_801DB974(operator new(8, 0x400), self, ctx);
    self->m3BC = new (operator new(0x6C, 0x400)) Unk801BA9CC((int)self, (Unk801B7FB0_P*)ctx);
    self->m3C0 = new (operator new(0x48, 0x400)) Unk801AE5C0((int)self, (int)ctx);
    self->m3C4 = new (operator new(0x80, 0x400)) Unk801A9610((int)self, (int)ctx);
    self->m3C8 = new (operator new(0x88, 0x400)) Unk801AB59C((int)self, (int)ctx);
    self->m3CC = new (operator new(0x64, 0x400)) Unk801B10C8((int)self, (int)ctx);
    *(void**)((char*)self + 0x404) = fn_801B659C();
    return self;
}

void fn_8017A600(Unk8017A930_T* self, int flag)
{
    *(const void**)self = lbl_806601F8;
    fn_8017A880(self);
    fn_8017EF78((char*)self + 0x228, self->m4);
    if (self->m3A4) {
        delete (Unk801B5A44*)self->m3A4;
        self->m3A4 = 0;
    }
    if (self->m3A8) {
        delete (Unk801B5A44*)self->m3A8;
        self->m3A8 = 0;
    }
    if (self->m3AC) {
        delete (Unk801B5A44*)self->m3AC;
        self->m3AC = 0;
    }
    if (self->m3B0) {
        delete (Unk801B5A44*)self->m3B0;
        self->m3B0 = 0;
    }
    if (self->m3B4) {
        delete (Unk801B5A44*)self->m3B4;
        self->m3B4 = 0;
    }
    if (self->m3B8) {
        delete (Unk801B5A44*)self->m3B8;
        self->m3B8 = 0;
    }
    if (self->m3BC) {
        delete (Unk801B5A44*)self->m3BC;
        self->m3BC = 0;
    }
    if (self->m3C0) {
        delete (Unk801B5A44*)self->m3C0;
        self->m3C0 = 0;
    }
    if (self->m3C4) {
        delete (Unk801B5A44*)self->m3C4;
        self->m3C4 = 0;
    }
    if (self->m3C8) {
        delete (Unk801B5A44*)self->m3C8;
        self->m3C8 = 0;
    }
    if (self->m3CC) {
        delete (Unk801B5A44*)self->m3CC;
        self->m3CC = 0;
    }
    ((Unk8017F628*)((char*)self + 0x24))->Unk8017F628::~Unk8017F628();
    ((Unk8017EDF0*)((char*)self + 8))->Unk8017EDF0::~Unk8017EDF0();
    if (flag & 1) {
        fn_80377408(self);
    }
}

void fn_8017A880(Unk8017A880_T* p)
{
    p->m3D0 = 0;
    p->m3D4 = 0;
    p->m3D8 = -1;
    p->m3DC = 2;
    p->m3E0 = 2;
    p->m3E4 = lbl_805CC758;
    p->m400 = lbl_805CC758;
    p->m3E8 = lbl_805EBA10;
    p->m408 = 0;
    p->m40C = 0;
    p->m410 = 0;
    p->m414 = 0;
    p->m418 = 1;
    p->m41C = 10;
    p->m420 = 4;
    p->m424 = 4;
    p->m428 = 0;
}
