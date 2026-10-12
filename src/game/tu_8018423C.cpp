/*
 * Game code, .text 0x8018423C-0x80188698 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8018423C.h"

extern "C" int strcmp(const char* a, const char* b);
struct Unk80186EF4_R {
    int m0;
    char m4[16];
};
struct Unk80186EF4_L {
    int m0;
    Unk80186EF4_R* m4;
    int* m8;
};
struct Unk80186EF4_M {
    char pad0[0x37AC];
    Unk80186EF4_L m37AC;
};
extern Unk80186EF4_M* lbl_8061E978;
struct Unk803DF824_Mtx {
    float m[16];
};
extern "C" void fn_803DF824(Unk803DF824_Mtx* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);

struct Unk8018514C_Y {
    char pad0[0xC];
    Unk8018423C_B* mC;
};
struct Unk8018514C_Ctx {
    char pad0[0x6F8];
    Unk8018514C_Y* m6F8;
};
struct Unk8018514C_O {
    char pad0[0x1D40];
    Unk8018514C_Ctx* m1D40;
};
extern "C" {
int fn_8018469C(Unk80183918_Vec3* p, Unk80183918_Vec3* out, float* r);
float fn_8037AC20(Unk80183918_Vec3* p, void* a, void* b, int c, int* hit);
}
extern char lbl_8061C910[];
extern char lbl_8061C91C[];
extern Unk80183918_Vec3 lbl_8061C928;
extern float lbl_8061C934;
extern Unk80183918_Vec3 lbl_806055C4;


//@BODY
//@8018423C
extern "C" void fn_8018423C(Unk80181140* o, char* a, Unk8018423C_B* b)
{
    if (b->m24 != 0)
        fn_8018405C(o, b, a + 0x28, 0);
}

//@80184278
extern "C" void fn_80184278(Unk80181140* o)
{
    char* sub = (char*)o + 0x244;
    void* a = fn_80319330(sub, 4);
    void* b = fn_80319330(sub, 5);
    if (a != 0 && b != 0) {
        Unk80184278_Ctx* c = (Unk80184278_Ctx*)o->mBC;
        char* pb = (char*)b + 0x28;
        void* z = c->m734;
        fn_8018405C(o, z, (char*)a + 0x28, 1);
        fn_8018405C(o, z, pb, 0);
        if (lbl_8061EA68 != 0 && lbl_8061EA68->m328 != 0) {
            fn_8018423C(o, (char*)fn_80319330(sub, 6), c->m570[0]);
            fn_8018423C(o, (char*)fn_80319330(sub, 7), c->m570[1]);
            fn_8018423C(o, (char*)fn_80319330(sub, 8), c->m570[2]);
            fn_8018423C(o, (char*)fn_80319330(sub, 9), c->m570[3]);
            fn_8018423C(o, (char*)fn_80319330(sub, 10), c->m570[4]);
            fn_8018423C(o, (char*)fn_80319330(sub, 11), c->m570[5]);
        }
    }
}

//@8018466C
extern "C" void fn_8018466C(void* a, int idx)
{
    fn_8040B61C(a, lbl_8061C728[idx]);
}

//@80184E0C
extern "C" int fn_80184E0C(void* unused, Unk80184E0C_Vec* a, Unk80184E0C_Vec* b, Unk80184E0C_Vec* c)
{
    int r = (b->m0 * c->m8 - b->m8 * c->m0 - a->m0 * c->m8 + a->m8 * c->m0 + a->m0 * b->m8 - a->m8 * b->m0) > lbl_805CD870.m0;
    return r;
}

//@801850B4
inline float GetF(Unk801850B4_Obj* o, int idx)
{
    char* b = (char*)o + 0x1C7C;
    int off = idx * 0x30;
    return *(float*)(b + off);
}
extern "C" int fn_801850B4(Unk801850B4_Obj* o, float* v, int idx, float* out)
{
    *out = 0.0f;
    const float c = -240.0f;
    if (!(v[0] < c || !(v[2] >= c)))
        return 0;
    if (fn_80184E5C(o, v, idx) != 0) {
        *out = GetF(o, idx);
        return 1;
    }
    return 0;
}

//@8018514C
extern "C" float fn_8018514C(Unk8018514C_O* o, Unk80183918_Vec3* p, Unk80183918_Vec3* out)
{
    float r = 0.0f;
    if (fn_8018469C(p, out, &r) != 0)
        return r;
    int mode = o->m1D40->m6F8->mC->m24;
    if (mode == 0x10 || mode == 0x36) {
        float t = p->m8 * -1.0833334f - p->m0;
        if (!(t >= -7411.0f)) {
            int hit = 0;
            t = fn_8037AC20(p, lbl_8061C910, lbl_8061C91C, 0, &hit);
            if (hit != 0 && !(t >= 280.0f)) {
                *out = lbl_8061C928;
                t = t / lbl_8061C934;
                return t;
            }
        }
    }
    *out = lbl_806055C4;
    return 0.0f;
}

//@80185424
extern "C" void fn_80185424()
{
}

//@80185428
extern "C" void fn_80185428()
{
}

//@8018542C
/* near-miss: 39/39 insns, 2 slots differ: retail copies the second float argument into the
 * third (fmr f3,f2); every spelling tried (global read three times, const locals, an inline
 * setter) gives fmr f3,f1. */
extern "C" void fn_8018542C(Unk80181140* o, int flag)
{
    Unk8014D9EC_C c1;
    Unk8014D9EC_C c2;
    o->m360 = flag;
    int v;
    if (flag) {
        fn_8014D9EC(&c1, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        v = fn_8014DDAC(&c1);
    } else {
        fn_8014D9EC(&c2, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        v = fn_8014DDAC(&c2);
    }
    fn_801A081C(o->mBC, v);
}

//@801854C8
extern "C" Unk801854C8_U32 fn_801854C8(Unk801854C8_U32 x)
{
    unsigned int v = x.v;
    Unk801854C8_U32 r;
    r.v = (v << 24) | ((v >> 24) << 16) | (((v >> 16) & 0xFF) << 8) | ((v >> 8) & 0xFF);
    return r;
}

//@801854F4
/* near-miss: 44 vs 43 insns: retail keeps the address of the by-value temp (sp+8) in r30
 * across the two U32 swaps (one more saved register, stmw r29); the compare tree itself
 * matches (switch with case ranges). ~5 forms tried. */
extern "C" void fn_801854F4(Unk80181140* o, int x)
{
    Unk801854C8_U32 a;
    a.v = 0x281E1E00;
    Unk801854C8_U32 sa = fn_801854C8(a);
    a.v = 0x1E1E1E00;
    Unk801854C8_U32 sb = fn_801854C8(a);
    switch (x) {
    case 0 ... 0x28:
    case 0x49:
    case 0x56:
        o->m370 = sa.v;
        break;
    case 0x29 ... 0x48:
    case 0x4A ... 0x55:
        o->m370 = sb.v;
        break;
    }
}

//@801855A4
extern "C" Unk801854C8_U32 fn_801855A4(Unk801855A4_Obj* o)
{
    return o->m370;
}

//@801855B4
extern "C" void fn_801855B4(Unk801855A4_Obj* o, Unk801854C8_U32 v)
{
    o->m370 = fn_801854C8(v);
}

//@801855FC
extern "C" void fn_801855FC(Unk80181140* o, int a, const char* name)
{
    if (o->m540 <= 7) {
        o->m37C[o->m540].m0 = a;
        fn_8040B830(o->m37C[o->m540].m10, name, 0x20);
        o->m37C[o->m540].m10[0x1F] = 0;
        o->m540 = o->m540 + 1;
    }
}

//@8018567C
extern "C" void fn_8018567C(Unk80181140* o, int a, Unk80183918_Vec3* p, const char* name)
{
    if (o->m53C <= 0x3F) {
        fn_8040B830(o->m544[o->m53C].m10, name, 0x20);
        o->m544[o->m53C].m10[0x1F] = 0;
        o->m544[o->m53C].m0 = a;
        o->m544[o->m53C].m4 = *p;
        o->m53C = o->m53C + 1;
    }
}

//@80185728
inline Unk80181140_E* AtE(Unk80181140* o)
{
    return &o->m1160[o->m1144];
}
extern "C" void fn_80185728(Unk80181140* o, int a, Unk80183918_Vec3* p, const char* name)
{
    if (o->m1144 <= 0xF) {
        fn_8040B830(o->m1160[o->m1144].m70, name, 0x20);
        AtE(o)->m70[0x1F] = 0;
        AtE(o)->m6C = a;
        o->m1160[o->m1144].m0 = *p;
        o->m1144 = o->m1144 + 1;
    }
}

//@801857D4
extern "C" void fn_801857D4(Unk80181140* o, const char* name, Unk80183918_Vec3* p)
{
    int len = fn_8040B6A0(name);
    for (int i = 0; i < o->m540; i++) {
        if (fn_8040B750(name, o->m37C[i].m10, len) == 0) {
            o->m37C[i].m30 = i;
            o->m37C[i].m4 = *p;
            if (i <= 2)
                o->m37C[i].m34 = i;
            else
                o->m37C[i].m34 = 1;
            break;
        }
    }
}

//@80185CD4
Unk80185CD4::Unk80185CD4()
{
    fn_80185D48();
}

//@80185D18
Unk80185CD4::~Unk80185CD4()
{
}

//@80185D48
void Unk80185CD4::fn_80185D48()
{
    m28 = lbl_805CD8A0.m0;
    m24 = 2;
}

//@80185D60
void Unk80185CD4::fn_80185D60()
{
    fn_80185D48();
}

//@80185D80
void Unk80185CD4::fn_80185D80()
{
    Unk80185D80_Owner* o = m1C;
    m28 = (float)o->m4C * lbl_805CD8B0.m0;
    m24 = 0;
    fn_8031C328(o->m730, 3);
}

//@80185DE8
void Unk80185CD4::fn_80185DE8()
{
    m28 = lbl_805CD8B4.m0;
    m24 = 1;
    fn_8031C454(m1C->m730, 3);
}

//@80185E28
extern "C" int fn_80185E28(int x)
{
    if (x > 0)
        return x;
    return -x;
}

//@80186704
void Unk80185CD4::fn_80186704(int a)
{
    fn_8031B470(m1C->m72C, 4, a, 0);
}

//@80186738
void Unk80185CD4::fn_80186738(int a)
{
    int t = 0;
    if (a > 1) {
        if (a <= 3)
            t = 1;
        else if (a <= 5)
            t = 2;
        else
            t = 3;
    }
    fn_80186704(t);
}

//@80186788
void Unk80185CD4::fn_80186788()
{
    void* ui = m1C->m72C;
    Unk80186788_S* s = lbl_8061EA68;
    fn_8031B470(ui, 0x45, s->m308, 0);
    if (s->m30C == 4)
        fn_8031B470(ui, 0x46, s->m308, 0);
    else
        fn_8031B470(ui, 0x46, s->m30C - 1, 0);
    fn_8031B470(ui, 0x47, s->m3F4, 0);
    int id = 0x4A;
    fn_8031B470(ui, 0x48, s->m310, 0);
    int n = 20;
    fn_8031B470(ui, 0x5F, s->m314, 0);
    Unk80186788_Pair* p = s->m32C;
    fn_8031B470(ui, 0x49, s->m318, 0);
    do {
        fn_8031B470(ui, id, p->a, p->b);
        id++;
        p++;
    } while (--n != 0);
    fn_802B1FC0(s);
}

//@80186890
void Unk80185CD4::fn_80186890()
{
    fn_80185E38(this);
    fn_80186738(m1C->m6F8->m14->m1CC8);
}

//@80186EF4
extern "C" void fn_80186EF4(Unk80181140* o, const char* name, const Unk80183918_Vec3* pos)
{
    Unk80186EF4_L* l = &lbl_8061E978->m37AC;
    if (l != 0) {
        Unk80186EF4_R* d = l->m4;
        if (d != 0) {
            for (int i = 0; i < l->m0; i++) {
                if (strcmp(name, d[i].m4) == 0) {
                    Unk80181140_E* e = &o->m1160[i];
                    *(Unk80183918_Vec3*)&e->m60 = *pos;
                    fn_803DF824((Unk803DF824_Mtx*)&e->m20, 1.0f, 1.0f, 1.0f, pos->m0, pos->m4, pos->m8, e->m0.m0, e->m0.m4, e->m0.m8);
                }
            }
        }
    }
}

//@80187190
/* near-miss: 72 vs 71 insns, ~25 slots differ: retail computes the sub-object address
 * (self+0x360) before the base ctor call and keeps it in r29 (owner in r30); here the
 * addi is sunk after the call and the callee-saved registers swap. The array new matches
 * once the element is 0x20 bytes (the `d == 0 ? d : 5` spelling gives retail's
 * addic./mtctr idiom). ~6 forms tried. */
extern "C" Unk80187190* fn_80187190(Unk80187190* self, void* owner, int flag)
{
    void* sub = &self->m360;
    fn_8026C65C(self, owner, flag);
    fn_803785E4(sub);
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    self->m44C = owner;
    self->mB8 = lbl_8065FD80;
    self->m368 = lbl_8065FD58;
    self->m98 = lbl_8065FE10;
    int d = fn_80328648(owner) - 1;
    self->m4E4 = d == 0 ? d : 5;
    self->m4A4 &= 0x3FFFFFFF;
    self->mBFC = 0;
    if (flag != 0) {
        Unk80187190_T* arr = new (0) Unk80187190_T[120];
        self->mBFC = arr;
    }
    self->m448 = new (0) Unk80195404(self, flag);
    self->m4A0 = 0;
    self->m36C = 0;
    fn_80189E58(self);
    return self;
}

//@801872B0
extern "C" void fn_801872B0(Unk80187190* self, int chrg)
{
    self->mB8 = lbl_8065FD80;
    self->m368 = lbl_8065FD58;
    self->m98 = lbl_8065FE10;
    if (self->mBFC)
        fn_80377488(self->mBFC);
    if (self->m448) {
        delete self->m448;
        self->m448 = 0;
    }
    void* sub = &self->m360;
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_8026C864(self, chrg);
}

//@80187354
extern "C" void fn_80187354(Unk80187D20_Obj* o)
{
    lbl_8068BF0C = fn_80191A68(lbl_8068BEAC);
    fn_801955BC(*(void**)((char*)o + 0x448));
    o->m4B0 = lbl_805CDA8C.m0;
}

//@801873A4
extern "C" void fn_801873A4(void* o)
{
    fn_8018D894(o, 0, lbl_805CDA90.m0);
}

//@80187D20
extern "C" void fn_80187D20(Unk80187D20_Obj* o, int flag, float f1, float f2, float f3)
{
    o->flag = flag;
    o->m4B8 = f1;
    o->m4BC = f2;
    o->m4C0 = f3;
}

