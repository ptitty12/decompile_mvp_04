/*
 * Game code, .text 0x8017D640-0x801800FC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8017D640.h"

struct Unk8017DD64_T {
    char pad0[4];
    Unk8017DD64_Ctx* m4;
};

int fn_8017DD64(Unk8017DD64_T* p, int idx)
{
    int off = idx * 0xE64;
    return ((Unk8017DD64_Item*)((char*)p->m4->m6F8->m14 + off))->m78;
}

int fn_8017ED94(Unk8017DD64_Ctx* p)
{
    if (p) {
        return p->m704;
    }
    return 0;
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

Unk8037B3E8* Unk8017EF7C::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8017EF7C;
}

void fn_8017F424() {}

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
