/*
 * Game code, .text 0x8017D640-0x801800FC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8017D640.h"
#include "game/clampiter.h"
struct Unk8017E1E0_Vec {
    float x;
    float y;
    float z;
};
struct Unk8017E1E0_Obj {
    char pad0[0x60];
    Unk8017E1E0_Vec m60;
    char pad6C[0x458 - 0x6C];
    int m458;
    char pad45C[0x5C4 - 0x45C];
    int m5C4;
};
extern "C" void fn_801C33B0(void* z, Unk8017E1E0_Vec* a, Unk8017E1E0_Vec* b);

extern const float lbl_805CCB84;

struct Unk8017DD64_T {
    char pad0[4];
    Unk8017DD64_Ctx* m4;
};

int fn_8017D640(Unk8017A930_T* p, int a, char* b, int c, int d)
{
    fn_8017C72C(p);
    int r = fn_8017E374(p, a, b, c, c, d);
    if (r == 1) {
        fn_80252C1C(b + 0x480);
        fn_801A6820(p->m4);
    }
    return r;
}

int fn_8017DCCC(Unk8017DD64_T* p, Unk8017DCCC_Obj* b)
{
    int r = 0;
    if (b) {
        int off = b->m708 * 0xE64;
        Unk8017DD64_Item* it = (Unk8017DD64_Item*)((char*)p->m4->m6F8->m14 + off);
        int n = it->m78;
        if (n > 0) {
            int v = b->m704;
            r = v == fn_80099B50(it, 0);
        }
        if (n > 1) {
            int v = b->m704;
            if (v == fn_80099B50(it, 1)) {
                r = 1;
            }
        }
    }
    return r;
}

int fn_8017DD64(Unk8017DD64_T* p, int idx)
{
    int off = idx * 0xE64;
    return ((Unk8017DD64_Item*)((char*)p->m4->m6F8->m14 + off))->m78;
}

void fn_8017DD80(Unk8017DD64_T* p, int idx, int* out0, int* out1)
{
    *out0 = 0;
    *out1 = 0;
    int off = idx * 0xE64;
    Unk8017DD64_Item* it = (Unk8017DD64_Item*)((char*)p->m4->m6F8->m14 + off);
    int n = it->m78;
    if (n > 0) {
        int h = fn_80099B50(it, 0);
        *out0 = fn_801A49F0(p->m4, idx, h);
    }
    if (n > 1) {
        int h = fn_80099B50(it, 1);
        *out1 = fn_801A49F0(p->m4, idx, h);
    }
}

int fn_8017E030(Unk8017DD64_T* p, int a, int b)
{
    if (fn_8006BE18(p->m4->m6F8) == 1) {
        return 0;
    }
    int h = fn_80081B60(p->m4->m6F8->m14);
    int off = a * 0xE64;
    int r = fn_80096988((char*)p->m4->m6F8->m14 + off, h, b);
    int k = 0;
    if (((Unk8017E030_Rec*)p->m4->m6F8->m14)->m1CD0 != 0) {
        k = 1;
    }
    if (k == a && r == 1) {
        return 0;
    }
    int k2 = 0;
    if (((Unk8017E030_Rec*)p->m4->m6F8->m14)->m1CD0 != 0) {
        k2 = 1;
    }
    if (k2 == a && r == 2 && ((Unk8017E030_Rec*)p->m4->m6F8->m14)->m1CC9 == 3) {
        return 0;
    }
    return r;
}

/* near-miss (18 of 33 slots differ): the clamp-iterator step, the loop counter copy and the
 * hoisted p->m4 + 0x65C match. Retail returns the call result in r3 with no saved copy
 * (`mr r3,r0` is the argument move before `cmpwi r0,0`) and computes slwi before the cmplwi;
 * ours keeps r in r30 (stmw). Tried: r = x / x = f(x) / shared x, Slot as inline with byte
 * offset (kept), plain volatile counter. */
inline int Slot(Unk8017DD64_T* p, int i)
{
    int* t = p->m4->m65C;
    int o = i * 4;
    int x = 0;
    if ((unsigned)i <= 12)
        x = *(int*)((char*)t + o);
    return x;
}

int fn_8017E120(Unk8017A930_T* p, int unused, Unk8017E1E0_Obj* o)
{
    int r = 0;
    if (o->m458 == 9 && o->m5C4 == -1) {
        Unk8017E1E0_Vec v0;
        Unk8017E1E0_Vec c = o->m60;
        Unk8017E1E0_Vec v1;
        fn_801C33B0(p->m3A4, &v0, &v1);
        if (!((c.x - v0.x) * (c.x - v0.x) + (c.z - v0.z) * (c.z - v0.z) < 1296.0f)) {
            r = c.x * c.x + c.z * c.z < 9216.0f;
        }
    }
    return r;
}

int fn_8017E1E0(Unk8017A930_T* p, int unused, Unk8017E1E0_Obj* o)
{
    Unk8017E1E0_Vec v0;
    Unk8017E1E0_Vec c = o->m60;
    Unk8017E1E0_Vec v1;
    fn_801C33B0(p->m3A4, &v0, &v1);
    return (c.x - v0.x) * (c.x - v0.x) + (c.z - v0.z) * (c.z - v0.z) >= 1296.0f;
}

int fn_8017E264(Unk8017DD64_T* p)
{
    Unk8006A138_It<21> it(0);
    int i = 0;
    int r;
    do {
    int r;
    int x = Slot(p, i);
    r = x;
    if (x)
        r = fn_802491D8(x);
        i = it.Next();
    } while (i <= 12);
    return r;
}

/* near-miss: the arguments are copied to r28..r31 before the first load in retail; 3 slots differ. */
void fn_8017E2E8(Unk8017E2E8_T* p, int a, int b, int c)
{
    void* x = p->m3B0;
    fn_8023522C(x);
    fn_801DBE30(p->m3B8, a, b, c);
    fn_8017F67C(p->m24, a, b, c);
    switch (a) {
    case 0x2D:
    case 0x2F:
    case 0x9F:
        fn_801ABC14(p->m3C8);
        break;
    }
}

int fn_8017ED94(Unk8017DD64_Ctx* p)
{
    if (p) {
        return p->m704;
    }
    return 0;
}

Unk8017EDF0::Unk8017EDF0(Unk8017EE58_Ctx* ctx, int b)
{
    m0 = ctx;
    m4 = b;
    fn_8017EE24(this);
}

Unk8017EDF0::~Unk8017EDF0() {}

void fn_8017EE24(Unk8017EE24_T* p)
{
    p->mC = 0;
    p->m10 = 0;
}

void fn_8017EE34(Unk8017EE24_T* p)
{
    fn_8017EE24(p);
}

void fn_8017EE54() {}

void fn_8017EE58(Unk8017EE24_T* p)
{
    p->m8 = p->m0->m6F8->m14->m1CCA;
}

void fn_8017EE70(Unk8017EE24_T* p)
{
    p->mC = 0;
}

Unk8017EE24_T* fn_8017EE7C(Unk8017EE24_T* p)
{
    fn_8017EF00(p);
    return p;
}

void fn_8017EEAC() {}

int fn_8017EEB0()
{
    return 1;
}

void fn_8017EEB8(Unk8017EED0_T* p, int i)
{
    p->m110[i] += 1;
}

void fn_8017EED0(Unk8017EED0_T* p)
{
    for (int i = 0; i < 20; i++) {
        p->m0[i] = -1;
        p->m50[i] = 0;
    }
    p->mA0 = 0;
}

void fn_8017EF00(void* pp)
{
    Unk8017EED0_T* p = (Unk8017EED0_T*)pp;
    for (int i = 0; i < 20; i++) {
        p->m0[i] = -1;
        p->m50[i] = 0;
    }
    p->mA0 = 0;
    for (int i = 0; i < 27; i++) {
        p->mA4[i] = 0;
        p->m110[i] = 0;
    }
}

void fn_8017EF58(void* p)
{
    fn_8017EF00(p);
}

void fn_8017EF78() {}

Unk8017EF7C::Unk8017EF7C() : Unk8037B3E8(0xEF8A9748) {}

Unk8017EF7C::~Unk8017EF7C() {}

void fn_8017F3B4(int a)
{
    fn_8037C7FC()->fn_8037CE98(0xEF8A9748, a, 0);
}

Unk8037B3E8* Unk8017EF7C::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8017EF7C;
}

void fn_8017F424() {}

Unk8017F628::~Unk8017F628() {}

void fn_8017F744(Unk8017F744_T* p)
{
    Unk8017F744_Ctx* c = p->m0;
    p->m4 = c->m700;
    p->m8 = c->m6F8;
    fn_80034CA4(p->m10);
    p->m48 = 0;
    p->m1DC = -1;
    p->m30 = p->m2C = p->m28 = p->m24 = p->m20;
    p->m44 = p->m40 = p->m3C = p->m38 = p->m34 = lbl_805CCB84;
    for (int i = 0; i < 100; i++) {
        p->m4C[i] = p->m20;
    }
    p->m1E0 = 1;
}

/* near-miss: 97.3%; the one-float struct keeps -ffloat-store from spilling the running sum, but the add
 * comes out as `fadds f0,f0,f13; fmr f13,f0` (retail: `fadds f13,f13,f0`). Tried += / s = s + x / x + s,
 * the cnt clamp in four spellings, register, loop forms. */
struct Unk8017F7F0_F {
    float f;
};
float fn_8017F7F0(Unk8017F744_T* p, unsigned n)
{
    unsigned cnt = n > 100 ? 100 : (n == 0 ? 1 : n);
    int idx = p->m1DC;
    float sum = 0.0f;
    float avg = 0.0f;
    if (cnt != 0) {
        Unk8017F7F0_F s;
        s.f = sum;
        do {
            s.f += p->m4C[idx];
            idx--;
            if (idx < 0) {
                idx = 99;
            }
        } while (--cnt != 0);
        sum = s.f;
    }
    if (n != 0) {
        avg = sum / (float)n;
    }
    return avg;
}

void fn_8017F8A0(Unk8017F8A0_T* p)
{
    if (!(p->m30 <= p->m2C)) {
        p->m2C = p->m30;
    }
}

void fn_8017F8BC(void* p)
{
    fn_8017FF74(p);
}

void fn_8017F8DC(void* p)
{
    fn_8017FF74(p);
}

void fn_8017F8FC(void* p)
{
    fn_8017FF74(p);
}

void fn_8017F91C(void* p)
{
    fn_8017FF74(p);
}

void fn_8017F93C(Unk8017F8A0_T* p)
{
    p->m48 = 0;
    fn_8017FF74(p);
}

void fn_8017F964(Unk8017F8A0_T* p)
{
    p->m48 = 0;
    fn_8017FF74(p);
}

void fn_8017F98C(void* p)
{
    fn_8017FF74(p);
}

void fn_8017F9AC(Unk8017F8A0_T* p)
{
    p->m48 = 1;
    fn_8017FF74(p);
}

void fn_8017F9D4(void* p)
{
    fn_8017FF74(p);
}

void fn_8017F9F4(Unk8017F8A0_T* p)
{
    p->m28 = p->m30;
    p->m2C = p->m28;
}

void* fn_80180088(void* p)
{
    fn_801800B8(p);
    return p;
}

void fn_801800B8(Unk801800B8_T* p, int a)
{
    p->m58 = a;
    int base = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            p->m24[j + base] = 0;
        }
        base += 10;
    }
    p->m20 = 0;
}
