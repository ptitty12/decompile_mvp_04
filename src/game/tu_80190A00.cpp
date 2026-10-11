/*
 * Game code, .text 0x80190A00-0x80194D44 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80190A00.h"
//@BODY
//@80190E40
/* near-miss: 29 vs 28 insns, 7 slots differ: retail keeps the cursor arithmetic as r9 = p+4
 * and r11 = r9+8 (stw r3,4(r9)); every spelling tried (post-increment, q = p+1, char
 * offsets) folds to p+12. The early-return shape and the load order match. */
extern "C" int fn_80190E40(Unk80190EB4_Obj* o, int** pp)
{
    if (o->m264 != 0)
        return 0;
    fn_8026CA8C(o);
    int* p = *pp;
    int v = fn_80188EF4(o);
    *p = o->m36C;
    *pp = Unk80190E40_Put(p + 1, o->m4D4, v);
    return 1;
}

//@80190EB4
extern "C" void fn_80190EB4(Unk80190EB4_Obj* o)
{
    fn_8026CB30(o);
    o->v9(1);
    o->m370 = 0;
}

//@80190F04
extern "C" void fn_80190F04(Unk80190EB4_Obj* o, int v)
{
    o->m394 = v;
}

//@80190F0C
extern "C" float fn_80190F0C(Unk80190EB4_Obj* o)
{
    return o->m41C;
}

//@80190F14
extern "C" int fn_80190F14(Unk80190EB4_Obj* o)
{
    return fn_80196C50(o->m448);
}

//@8019144C
extern "C" void fn_8019144C(Unk80190EB4_Obj* o)
{
    o->mBF8 = 0;
}

//@80191720
Unk80191720::Unk80191720()
    : Unk8037B3E8(0x0F245603U)
{
}

//@80191764
void Unk80191720::fn_vslot2()
{
    fn_8037B7E4(lbl_805CE008);
    fn_8037B50C(lbl_805CE00C, &m4, lbl_805CE014, lbl_805CE020);
    fn_8037B50C(lbl_805CE024, &mC, lbl_805CE030, lbl_805CE03C);
    fn_8037B50C(lbl_805CE040, &m8, lbl_805CE030, lbl_805CE04C);
}

//@80191800
extern "C" void* fn_80191800(Unk80191720* self)
{
    return fn_8037CF5C(fn_8037C7FC(), 0x0F245603U, self);
}

//@8019183C
Unk8037B3E8* Unk80191720::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk80191720;
}

//@8019186C
Unk8019186C::Unk8019186C()
    : Unk8037B3E8(0xDA319B21U)
{
}

//@801918B0
void Unk8019186C::fn_vslot2()
{
    fn_8037B7E4(lbl_805CE050);
    fn_8037B50C(lbl_805CE054, &m4, lbl_805CE030, 0);
    fn_8037B50C(lbl_805CE05C, &m8, lbl_805CE068, 0);
    fn_8037B494(lbl_805CE074, &m10, 0, 0);
    fn_8037B50C(lbl_805CE084, &mC, lbl_805CE090, 0);
    fn_8037B50C(lbl_805CE09C, &m14, lbl_805CE090, 0);
    fn_8037B50C(lbl_805CE0B4, &m18, lbl_805CE090, 0);
    fn_8037B50C(lbl_805CE0C8, &m1C, lbl_805CE0D8, 0);
    fn_8037B7E8(lbl_805CE0E4);
    fn_8037B458(lbl_805CE0F0, &m20, 0, 0);
    fn_8037B50C(lbl_805CE0FC, &m30, lbl_805CE100, 0);
    fn_8037B50C(lbl_805CB6EC, &m24, lbl_805CE108, 0);
    fn_8037B50C(lbl_805CE114, &m28, lbl_805CE108, 0);
    fn_8037B50C(lbl_805CE118, &m2C, lbl_805CE108, 0);
    fn_8037B830(lbl_805CE0E4);
}

//@80191A68
extern "C" void* fn_80191A68(void* self)
{
    return (void*)fn_8037C7FC()->fn_8037CE98(0xDA319B21U, (int)self, 0);
}

//@80191AA8
Unk8037B3E8* Unk8019186C::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8019186C;
}

//@80191AD8
/* near-miss: 38/38 insns, ~12 slots differ: the mode 1/2/3 bodies match (sub-object pointer
 * for the +4 record, Vec3 copies, store order) but retail shares the `m4 = -1.0f` tail of
 * modes 1 and 2 as one block at the end (beq from both tests); here it is laid out first. */
extern "C" void fn_80191AD8(Unk80191AD8_S* s, int mode)
{
    s->m0 = mode;
    if (mode == 2) {
        s->m4 = -1.0f;
    } else if (mode > 2) {
        if (mode != 3)
            return;
        Unk80191AD8_Q* q = (Unk80191AD8_Q*)&s->m4;
        q->m0 = -1.0f;
        q->m4 = lbl_806055AC;
        q->m10 = -1.0f;
        s->m18 = lbl_806055AC;
        q->m20 = -1.0f;
        q->m24 = 0;
    } else if (mode == 1) {
        s->m4 = -1.0f;
    }
}

//@80191B70
extern "C" Unk80191B70_S* fn_80191B70(Unk80191B70_S* s)
{
    Unk80191B70_Sub* sub = &s->m4;
    fn_8037936C(sub, lbl_8069429C);
    *(Unk80183918_Vec3*)((char*)s + 0x14) = lbl_806055AC;
    sub->m1C = 0;
    s->m78 = 0;
    return s;
}

//@80191BE0
extern "C" Unk80191B70_S* fn_80191BE0(Unk80191B70_S* s, void* owner)
{
    Unk80191B70_Sub* sub = &s->m4;
    fn_8037936C(sub, lbl_8069429C);
    *(Unk80183918_Vec3*)((char*)s + 0x14) = lbl_806055AC;
    sub->m1C = 0;
    fn_80191C5C((Unk80191C5C_S*)s, owner);
    return s;
}

//@80191C5C
/* near-miss: 54/54 insns, 2 slots differ: the m70 and m0 stores swap places (400 orders of the
 * last eight stores sampled). */
extern "C" void fn_80191C5C(Unk80191C5C_S* s, void* owner)
{
    s->m24 = 0;
    s->m20 = 3;
    s->m28 = lbl_806055AC;
    s->m34 = lbl_806055AC;
    s->m40 = lbl_806055AC;
    s->m4C = lbl_806055AC;
    s->m58 = 0.0f;
    s->m5C = 1.0f;
    s->m64 = 0;
    s->m68 = 0;
    s->m6C = 0;
    s->m60 = 0.0f;
    s->m78 = (char*)owner + 0xD4;
    s->m74 = 0;
    s->m0 = owner;
    s->m70 = 0;
}

//@80193750
/* near-miss family (this, 0x801937B4, 0x80193828, 0x80193880): the searches over the
 * 0x18-byte entries match except for the loop variables: retail keeps the byte offset
 * i*0x18 as its own induction variable (add r3,r9,r10) where this compiles a pointer
 * variable (addi r3,r3,24). `a[i]`, `(char*)a + i*0x18`, `(int)a + i*0x18` and an explicit
 * `off += 0x18` were tried. */
extern "C" void* fn_80193750(void* hv, float t)
{
    Unk80193750_H* h = (Unk80193750_H*)hv;
    char* a = (char*)h->m78;
    if (a == 0)
        return 0;
    int n = h->m74;
    for (int i = 0; i < n; i++) {
        Unk80193750_Ent* e = (Unk80193750_Ent*)(a + i * 0x18);
        if (t <= e->m4)
            return e;
    }
    return 0;
}

//@801937B4
extern "C" float fn_801937B4(void* hv, int k, float t)
{
    Unk80193750_H* h = (Unk80193750_H*)hv;
    char* a = (char*)h->m78;
    if (a == 0)
        return -1.0f;
    int n = h->m74;
    int off = 0;
    for (int i = 0; i < n; i++) {
        Unk80193750_Ent* e = (Unk80193750_Ent*)(a + off);
        if (!(t > e->m4) && e->m0 == k)
            return e->m4;
        off += 0x18;
    }
    return -1.0f;
}

//@80193828
extern "C" void* fn_80193828(void* hv, float t)
{
    Unk80193750_H* h = (Unk80193750_H*)hv;
    char* a = (char*)h->m78;
    if (a == 0)
        return 0;
    int off = (h->m74 - 1) * 0x18;
    for (int i = h->m74 - 1; i >= 0; i--) {
        Unk80193750_Ent* e = (Unk80193750_Ent*)(a + off);
        if (t > e->m4)
            return e;
        off -= 0x18;
    }
    return 0;
}

//@80193880
extern "C" float fn_80193880(Unk80193750_H* h, int k, float t)
{
    char* a = (char*)h->m78;
    if (a == 0)
        return -1.0f;
    int off = (h->m74 - 1) * 0x18;
    for (int i = h->m74 - 1; i >= 0; i--) {
        Unk80193750_Ent* e = (Unk80193750_Ent*)(a + off);
        if (!(t <= e->m4) && e->m0 == k)
            return e->m4;
        off -= 0x18;
    }
    return -1.0f;
}

