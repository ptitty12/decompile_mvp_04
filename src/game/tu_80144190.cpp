/*
 * Game code, .text 0x80144190-0x801445F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"
extern "C" void fn_80377408(void*);

extern const char lbl_8065CCE8[];
extern const char lbl_8065CFD0[];

struct UnkB4A {
    char pad0[0x4A];
    unsigned char m4A;
};
struct UnkF38 {
    char pad0[0x38];
    float m38;
};
struct UnkI48 {
    char pad0[0x48];
    int m48;
};
struct UnkP0 {
    const void* m0;
};
struct UnkP3C {
    char pad0[0x3C];
    const void* m3C;
};
struct UnkS26 {
    char pad0[0x26];
    short m26;
};
struct UnkS28 {
    char pad0[0x28];
    short m28;
};
struct UnkS2A {
    char pad0[0x2A];
    short m2A;
};
struct UnkS2C {
    char pad0[0x2C];
    short m2C;
};
struct UnkS2E {
    char pad0[0x2E];
    short m2E;
};

extern "C" void fn_80144190(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_801441C4(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_801441F8(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_8014422C(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_80144260(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_80144294(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_801442C8(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_801442FC(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_80144330(UnkP0* p, int chrg)
{
    p->m0 = lbl_8065CFD0;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_80144364(UnkP3C* p, int chrg)
{
    p->m3C = lbl_8065CCE8;
    if (chrg & 1) {
        fn_80377408(p);
    }
}

extern "C" void fn_80144398() {}

extern "C" int fn_8014439C() { return 0; }

extern "C" void fn_801443A4(UnkS26* p, short v) { p->m26 = v; }

extern "C" void fn_801443AC(UnkS28* p, short v) { p->m28 = v; }

extern "C" void fn_801443B4(Unk800C7B40_Widget* x, Unk800C7B40_Data* y)
{
    x->fn_vslot9(y->m26);
    x->fn_vslot10(y->m28);
}

extern "C" void fn_80144418(UnkS2A* p, short v) { p->m2A = v; }

extern "C" void fn_80144420(UnkS2C* p, short v) { p->m2C = v; }

extern "C" void fn_80144428(UnkS2E* p, short v) { p->m2E = v; }

extern "C" float fn_80144430(UnkF38* p) { return p->m38; }

extern "C" void fn_80144438(Unk800C7B40_Widget* x, float v)
{
    x->m38 = v;
}

extern "C" void fn_80144450(float v)
{
}

extern "C" void fn_80144460(Unk800C7B40_Widget* x, int v)
{
    x->b5 = v;
}

extern "C" int fn_80144470(Unk800C7B40_Widget* x)
{
    return x->b5;
}

extern "C" void fn_8014447C() {}

extern "C" void* fn_80144480(UnkB4A* p) { return &p->m4A; }

struct Unk80144488 : Unk800C7B40_Widget {
    char pad40[0x54];
    float m94;
};
extern "C" void fn_80144488(Unk80144488* x, float v)
{
    x->fn_vslot20(v * x->m94);
}

extern "C" void fn_801444CC() {}

extern "C" void fn_801444D0(UnkI48* x)
{
    x->m48 |= 0x80000000;
}

extern "C" int fn_801444E0() { return 0; }

extern "C" int fn_801444E8() { return 0; }

extern "C" int fn_801444F0() { return 0; }

extern "C" int fn_801444F8() { return 0; }

extern "C" int fn_80144500() { return 0; }

extern "C" int fn_80144508() { return 0; }

extern "C" int fn_80144510() { return 0; }

extern "C" int fn_80144518() { return 0; }

extern "C" int fn_80144520() { return 0; }

extern "C" int fn_80144528() { return 0; }

extern "C" int fn_80144530() { return 0; }

extern "C" int fn_80144538() { return 0; }

extern "C" int fn_80144540() { return 0; }

extern "C" int fn_80144548() { return 0; }

extern "C" int fn_80144550() { return 0; }

extern "C" int fn_80144558() { return 0; }

extern "C" int fn_80144560() { return 0; }

extern "C" int fn_80144568() { return 0; }

extern "C" int fn_80144570() { return 0; }

extern "C" int fn_80144578() { return 0; }

extern "C" int fn_80144580() { return 0; }

extern "C" int fn_80144588() { return 0; }

extern "C" int fn_80144590() { return 0; }

extern "C" void fn_80144598(Unk800C7B40_Widget* x, int a)
{
    x->fn_vslot41(a);
}

extern "C" void fn_801445CC() {}

extern "C" void fn_801445D0() {}

extern "C" void fn_801445D4() {}

extern "C" void fn_801445D8() {}

extern "C" void fn_801445DC() {}

extern "C" void fn_801445E0() {}

extern "C" int fn_801445E4() { return 0; }

extern "C" int fn_801445EC() { return 0; }
