/*
 * Game code, .text 0x801445F4-0x80144CF0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

extern "C" const char* fn_80144630();
extern "C" const char* fn_801446C4();
extern "C" const char* fn_80144BB4();
extern const float lbl_805C2C80;
extern const float lbl_805C2C84;
extern const float lbl_805C2C88;
extern const float lbl_805C2C8C;
extern const char lbl_8065BDF8[];
extern const char lbl_8065B780[];
extern const char lbl_8065B690[];
extern const char lbl_8065B9C0[];
extern const char lbl_8065B360[];

struct UnkVec4 {
    float m0;
    float m4;
    float m8;
    float mC;
};
/* Widget with a 16-byte vector at +0x4C whose last component is a clamped scalar. */
struct Unk80144788 : Unk800C7B40_Widget {
    char pad40[0xC];
    UnkVec4 m4C;
};
extern "C" {
void fn_8033CD28(void* p, int in_chrg);
void fn_8037B424(void* p, int in_chrg);
int fn_800D43F0(void* p, int v);
void fn_8014DDAC(void* p);
void fn_800AB308(void* p);
int fn_803EE310(int v);
}

extern const char lbl_805B7084[];
extern const char lbl_805B8A58[];
extern const char lbl_805B8C38[];
extern const char lbl_8065BC28[];

struct UnkI28 {
    char pad0[0x28];
    int m28;
};
struct UnkI30 {
    char pad0[0x30];
    int m30;
};
struct UnkI40 {
    char pad0[0x40];
    int m40;
};
struct UnkI44 {
    char pad0[0x44];
    int m44;
};
struct UnkI48 {
    char pad0[0x48];
    int m48;
};
struct UnkI5C {
    char pad0[0x5C];
    int m5C;
};
struct UnkI60 {
    char pad0[0x60];
    int m60;
};
struct UnkI6C {
    char pad0[0x6C];
    int m6C;
};
struct UnkI74 {
    char pad0[0x74];
    int m74;
};
struct UnkI444 {
    char pad0[0x444];
    int m444;
};
struct UnkP0 {
    const void* m0;
};
struct UnkP8 {
    char pad0[0x8];
    const void* m8;
};

extern "C" int fn_801445F4() { return 0; }

extern "C" int fn_801445FC() { return 0; }

extern "C" int fn_80144604() { return 0x8CA866F4; }

extern "C" const char* fn_80144610()
{
    return fn_80144630();
}

extern "C" const char* fn_80144630() { return lbl_805B7084; }

struct Unk8014463C {
    const void* m0;
    char pad4[0xAC];
    char mB0[0xC];
    char mBC[4];
};
extern "C" void fn_8014463C(Unk8014463C* p, int chrg)
{
    p->m0 = lbl_8065BDF8;
    fn_8033CD28(p->mBC, 2);
    fn_8033CD28(p->mB0, 2);
    fn_8037B424(p, chrg);
}

extern "C" const char* fn_80144698()
{
    return fn_801446C4();
}

extern "C" int fn_801446B8() { return 0x6D896082; }

extern "C" const char* fn_801446C4() { return lbl_805B8A58; }

struct Unk801446D0 : Unk800C7B40_Widget {
    char pad40[0x3C];
    int m7C;
};
extern "C" void fn_801446D0(Unk801446D0* x, int v)
{
    x->m2A = v;
    x->m7C = fn_800D43F0(x, x->fn_vslot31());
}

extern "C" int fn_80144724(UnkI44* p) { return p->m44; }

struct Unk8014472C : Unk800C7B40_Widget {
    char pad40[8];
    int m48;
    char pad4C[0x30];
    int m7C;
};
extern "C" void fn_8014472C(Unk8014472C* x, int v)
{
    x->m48 = v;
    x->m7C = fn_800D43F0(x, x->fn_vslot31());
}

extern "C" int fn_80144780(UnkI48* p) { return p->m48; }

extern "C" void fn_80144788(Unk80144788* x, const UnkVec4* y)
{
    UnkVec4* v = &x->m4C;
    *v = *y;
    float t = x->fn_vslot19();
    v->mC = !(t > lbl_805C2C80) ? (t >? lbl_805C2C84) : lbl_805C2C80;
}

extern "C" void fn_8014481C(Unk80144788* x)
{
    fn_8014DDAC(&x->m4C);
}

extern "C" UnkVec4 fn_80144840(Unk80144788* x)
{
    return x->m4C;
}

extern "C" int fn_8014486C(UnkI74* p) { return p->m74; }

extern "C" void fn_80144874(Unk800C7B40_Widget* x)
{
    x->fn_vslot47(0);
}

struct Unk801448AC : Unk800C7B40_Widget {
    char pad40[0x24];
    int m64;
    char pad68[0x14];
    int m7C;
};
extern "C" void fn_801448AC(Unk801448AC* x, int v)
{
    x->m64 = v;
    x->m7C = fn_800D43F0(x, x->fn_vslot31());
}

extern "C" int fn_80144900(UnkI5C* p) { return p->m5C; }

extern "C" int fn_80144908(UnkI60* p) { return p->m60; }

/* near-miss: 22/24 insns; retail clamps in the register shared with the hi constant (f13,
 * one fmr) after two float spills of v into one slot; here the hi constant is hoisted into
 * f12 and the arms get a branch. Tried SetA/SetB inline pairs, block-scoped locals. */
extern "C" void fn_80144910(Unk80144788* x, float v)
{
    float a = v;
    x->m38 = a;
    float b = v;
    x->m4C.mC = !(b > lbl_805C2C88) ? (b >? lbl_805C2C8C) : lbl_805C2C88;
}

extern "C" void fn_80144968(Unk800C7B40_Widget* x, float v)
{
    x->fn_vslot20(v);
}

extern "C" void fn_801449A4(UnkI6C* p, int v) { p->m6C = v; }

struct Unk801449AC : Unk800C7B40_Widget {
    char pad40[0x28];
    int m68;
};
extern "C" int fn_801449AC(Unk801449AC* x)
{
    int r = 0;
    if (x->m68 < 0 && (x->b3)) {
        r = 1;
    }
    return r;
}

struct Unk801449D4 {
    char pad0[0x78];
    int m78;
    char pad7C[0xC];
    int m88;
};
extern "C" void fn_801449D4(Unk801449D4* x, int a, int b)
{
    x->m78 = a;
    x->m88 = b;
}

struct Unk801449E0 {
    char pad0[0x40];
    int m40;
};
extern "C" int fn_801449E0(Unk801449E0* x)
{
    int v = x->m40;
    return v ? fn_803EE310(v) : 0;
}

extern "C" int fn_80144A14(UnkI40* p) { return p->m40; }

extern "C" void fn_80144A1C(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" void fn_80144A50(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" void fn_80144A84(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" void fn_80144AB8(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" void fn_80144AEC(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" void fn_80144B20(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" void fn_80144B54(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065BC28;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" int fn_80144B88() { return 0x6A8513FF; }

extern "C" const char* fn_80144B94()
{
    return fn_80144BB4();
}

extern "C" const char* fn_80144BB4() { return lbl_805B8C38; }

extern "C" int fn_80144BC0() { return 0; }

extern "C" int fn_80144BC8() { return 0; }

extern "C" int fn_80144BD0() { return 0; }

extern "C" int fn_80144BD8() { return 0; }

extern "C" void fn_80144BE0() {}

extern "C" void fn_80144BE4(UnkI444* p, int v) { p->m444 = v; }

extern "C" int fn_80144BEC(UnkI28* p) { return p->m28; }

extern "C" int fn_80144BF4(UnkI30* p) { return p->m30; }

struct Unk80144BFC {
    char pad0[0x18];
    const void* m18;
};
extern "C" void fn_80144BFC(Unk80144BFC* x)
{
    x->m18 = lbl_8065B780;
    fn_800AB308(x);
}

extern "C" int fn_80144C2C() { return 1; }

extern "C" void fn_80144C34(UnkP8* p, int chrg)
{
    p->m8 = lbl_8065B360;
    if (chrg & 1) {
        delete p;
    }
}

extern "C" int fn_80144C68() { return 0; }

extern "C" int fn_80144C70() { return 0; }

extern "C" int fn_80144C78() { return 0; }

extern "C" int fn_80144C80() { return 0; }

extern "C" void fn_80144C88() {}

extern "C" void fn_80144C8C() {}

extern "C" void fn_80144C90() {}

extern "C" void fn_80144C94() {}

extern "C" void fn_80144C98() {}

extern "C" int fn_80144C9C() { return 1; }

struct Unk80144CA4 {
    char pad0[8];
    const void* m8;
    const void* mC;
    char pad10[0xC];
    const void* m1C;
};
/* near-miss: 19/19 insns, three vptr-address registers differ (retail r9/r10/r8, here
 * r9/r11/r10); all six store orders tried. */
extern "C" void fn_80144CA4(Unk80144CA4* x, int chrg)
{
    x->m1C = lbl_8065B690;
    x->mC = lbl_8065B9C0;
    x->m8 = lbl_8065B360;
    if (chrg & 1) {
        delete x;
    }
}
