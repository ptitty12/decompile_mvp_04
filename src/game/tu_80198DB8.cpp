/*
 * Game code, .text 0x80198DB8-0x8019C1F8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80198DB8.h"
//@BODY
//@80198DB8
extern "C" void* fn_80198DB8(void* o)
{
    return fn_80198CC0(o);
}

//@80198DD8
extern "C" void fn_80198DD8(Unk80198E5C_Obj* o, int v)
{
    if (v)
        o->v8(0);
    *(int*)((char*)o + 0x378) = v;
    if (v)
        o->m384 = 1;
    else if (o->m384 == 1)
        o->m384 = v;
}

//@80198E5C
extern "C" void fn_80198E5C(Unk80198E5C_Obj* o, int v)
{
    if (v == 0)
        o->m384 = 0;
    o->m264 = v;
}

//@80198E70
extern "C" void fn_80198E70(Unk80198E5C_Obj* o, int v)
{
    o->m37C = v;
}

//@80198E78
extern "C" char* fn_80198E78(Unk80198E5C_Obj* o)
{
    int m = o->m37C;
    if (m == 1)
        return lbl_805D053C;
    if (m == 3)
        return lbl_805D056C;
    return lbl_805D059C;
}

//@80198EB0
extern "C" char* fn_80198EB0(Unk80198E5C_Obj* o)
{
    int m = o->m37C;
    if (m == 1)
        return lbl_805D051C;
    if (m == 3)
        return lbl_805D054C;
    return lbl_805D057C;
}

//@80198EE8
extern "C" char* fn_80198EE8(Unk80198E5C_Obj* o)
{
    int m = o->m37C;
    if (m == 1)
        return lbl_805D052C;
    if (m == 3)
        return lbl_805D055C;
    return lbl_805D058C;
}

//@80198F20
extern "C" float fn_80198F20(Unk80198E5C_Obj* o)
{
    if (o->m37C == 3)
        return 1.25f;
    return 1.0f;
}

//@80198F44
extern "C" float fn_80198F44(Unk80198E5C_Obj* o)
{
    if (o->m37C == 2)
        return 1.25f;
    return 1.35f;
}

//@80199158
/* near-miss: 21 vs 22 insns: retail tests case 1, then `ble` to the end, then cases 2 and 3
 * in a straight line (case bodies out of line); a three-case switch compiles here as a tree
 * rooted at 2, nested ifs give the other layout. */
extern "C" void fn_80199158(Unk80198E5C_Obj* o)
{
    switch (o->m384) {
    case 1:
        fn_80198F68(o);
        break;
    case 2:
        fn_80199554(o);
        break;
    case 3:
        fn_80199414();
        break;
    }
}

//@80199414
extern "C" void fn_80199414()
{
}

//@8019A404
extern "C" void fn_8019A404(void* o, void* x, float* out)
{
    fn_8019A44C(o, x);
    out[0] = *(float*)((char*)o + 0x30);
    out[1] = *(float*)((char*)o + 0x34);
    out[2] = *(float*)((char*)o + 0x38);
}

//@8019AAF0
extern "C" void fn_8019AAF0(Unk8019AC78_Obj* o, void* a)
{
    int m = o->m370;
    if (m == 1) {
        fn_8030AC88(a);
    } else if (m == 2) {
        fn_8030AF34(a, 0);
        fn_8030AF9C(a, 1);
    } else if (m == 3) {
        fn_8030AF9C(a, 0);
        fn_8030AF34(a, 1);
    }
}

//@8019AC78
extern "C" void fn_8019AC78(Unk8019AC78_Obj* o)
{
    void* e = fn_80319330((char*)o + 0x244, 0x17);
    fn_803116D4(fn_803119C0(), e, 0, 0, 1, o->m3E0->m54C, o->m3E0->m550, 0, 0.0f);
}

//@8019ACE0
extern "C" void fn_8019ACE0(Unk8019AC78_Obj* o)
{
    if (lbl_8061B894 != 0 && o->m36C == 0 && o->m240 == 0 && o->mBC->m54C->m10->m14 == 0) {
        fn_8019AB74(o);
        fn_8019AC78(o);
        if (lbl_8061C9F8 == 0) {
            fn_803DE374(1, 0);
            fn_8026CA5C(o);
            fn_803DE374(0, 0);
        }
    }
}

//@8019AE68
extern "C" void fn_8019AE68(void* o, float f)
{
    fn_8026CC04(o, f);
}

//@8019B004
extern "C" void fn_8019B004(Unk80198E5C_Obj* o)
{
    fn_8026CB30(o);
    o->v9(1);
}

//@8019B0E4
extern "C" void fn_8019B0E4(Unk8019B0E4_Obj* self, int chrg)
{
    self->mB8 = lbl_8065F760;
    self->m368 = lbl_8065F738;
    self->m3FC = lbl_8065F720;
    self->m98 = lbl_8065F7F0;
    fn_8019755C((Unk8019755C_Data*)((char*)self + 0x36C), 0);
    void* sub = &self->m360;
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_8026C864(self, chrg);
}

//@8019B174
extern "C" void fn_8019B174(Unk80198E5C_Obj* o, int v)
{
    o->m404 = v;
}

//@8019B17C
extern "C" void fn_8019B17C(Unk80198E5C_Obj* o, int v)
{
    o->m264 = v;
}

//@8019B184
extern "C" void fn_8019B184(Unk80198E5C_Obj* o)
{
    fn_80197604((char*)o + 0x36C);
}

//@8019B1A8
extern "C" void fn_8019B1A8(Unk80198E5C_Obj* o)
{
    fn_8019B174(o, 0);
}

//@8019B1CC
extern "C" void fn_8019B1CC()
{
}

//@8019B1D0
extern "C" void fn_8019B1D0(void* o, float f)
{
    fn_8026CC04(o, f);
}

//@8019B1F8
extern "C" void fn_8019B1F8()
{
}

//@8019B1FC
extern "C" void fn_8019B1FC(Unk80198E5C_Obj* o)
{
    fn_8026CB30(o);
    o->v9(1);
}

//@8019B244
extern "C" int fn_8019B244()
{
    return 0;
}

//@8019B24C
extern "C" Unk8019B24C_Obj* fn_8019B24C(Unk8019B24C_Obj* self, void* owner)
{
    fn_80328234(self, 4, owner);
    self->m24 = owner;
    self->m18 = lbl_8065F688;
    fn_8019B2A0((Unk80198E5C_Obj*)self);
    return self;
}

//@8019B2A0
extern "C" void fn_8019B2A0(Unk80198E5C_Obj* o)
{
    o->m3E8 = 0;
}

//@8019B5AC
extern "C" int fn_8019B5AC(float* a, float* b)
{
    if (a[2] < b[2])
        return -1;
    return a[2] != b[2];
}

//@8019B99C
extern "C" void fn_8019B99C(Unk8019B99C_Obj* o)
{
    if (o->m24->m6F4 != 1)
        fn_8019B490(o);
}

//@8019B9CC
Unk8019B9CC::Unk8019B9CC(int a)
{
    m4 = a;
    m0 = lbl_8061E978->m3650;
}

//@8019B9F4
Unk8019B9CC::~Unk8019B9CC()
{
    m0 = 0;
}

//@8019BA30
extern "C" void fn_8019BA30(void** o, float t)
{
    fn_802C0888(*o, t);
}

//@8019BBC0
extern "C" void fn_8019BBC0(void** o, float t)
{
    fn_802C0050(*o, t);
}

//@8019BBEC
extern "C" void fn_8019BBEC(void** o)
{
    fn_802C0EC4(*o);
}

