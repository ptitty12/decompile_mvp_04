/*
 * Game code, .text 0x80177C34-0x8017A930 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80177C34.h"

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

void fn_80177EE0(void* self) /* 80177EE0 */
{
    Unk8027C728_Goal* g = fn_802448F4(*(void**)((char*)self + 0xC), 2);
    fn_80177DF0(self, g);
    fn_8027D33C(g);
}

class Unk80178A64 {
public:
    virtual ~Unk80178A64();
};

Unk80178A64::~Unk80178A64() {}

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

int fn_80179464()
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

void fn_80179784()
{
    fn_801794B8();
}

void fn_801797A4()
{
    fn_801794B8();
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
