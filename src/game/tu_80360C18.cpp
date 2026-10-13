/*
 * Game code, .text 0x80360C18-0x80361580 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

extern char lbl_806827B0[];
struct DtorAt10 { char pad[0x10]; const void* m; };
struct Unk80360C4C {
    char pad0[0x18];
    int m18;
};
extern "C" void fn_8051F964(void* s);
extern "C" void fn_8051FBD0(void* s, int a);
struct Unk80360CB8_Y {
    char pad0[0x17C];
    unsigned char m17C;
    char pad17D[0xC74 - 0x17D];
    char mC74[0x28];
    char mC9C[1];
};
struct Unk80360CB8_W {
    char pad0[0x14];
    Unk80360CB8_Y* m14;
};
struct Unk80360CB8_G {
    char pad0[4];
    Unk80360CB8_W* m4;
};
extern Unk80360CB8_G* lbl_806192E0;
struct Unk80360CB8_Pad24 {
    char pad[0x24];
};
struct Unk80360CB8_Sub : Unk80360CB8_Pad24 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11();
};
struct Unk80360CB8_Obj {
    char pad[0xDC];
    char m[1];
};
extern "C" Unk80360CB8_Obj* fn_8051F4D8();
struct Unk80089894_PackTabD;
void fn_80089EE0(Unk80089894_PackTabD* a, unsigned b, unsigned c, int d);
extern "C" void fn_8008D850(char* a, int b, int c, int d);
extern "C" int fn_8008CFD8(char* a, int b, int c);
struct Unk80360D24_Pad10 {
    char pad[0x10];
};
struct Unk80360D24 : Unk80360D24_Pad10 {
    virtual void v1();
    virtual void v2();
    virtual void v3(int a);
};
struct Unk80360DFC : Unk80360D24_Pad10 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a);
};
extern char lbl_8067A190[];
struct DtorAtB8 { char pad[0xb8]; const void* m; };
struct Unk80360ED0 {
    int m0;
    int m4;
};
struct Unk80360EF8_P {
    float a;
    float b;
};
struct Unk80360EF8 {
    Unk80360EF8_P e[100];
    int m320;
};
extern float lbl_805FC4D4;
struct Unk80360F2C {
    float m0, m4, m8, mC;
};
extern float lbl_805FC4D8;
struct UiScrRaw;
void fn_800EC5F4(UiScrRaw* self);
extern char lbl_80667118[];
struct DtorAt4 { char pad[0x4]; const void* m; };
extern char lbl_80683F28[];
struct Unk80361534 {
    int m0;
    const void* m4;
    Unk80361534();
};

void fn_80360C18(DtorAt10* self, int chrg)
{
    self->m = lbl_806827B0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360C4C(Unk80360C4C* s)
{
    fn_8051F964(s);
    fn_8051FBD0(s, s->m18);
}

void fn_80360C84(DtorAt10* self, int chrg)
{
    self->m = lbl_806827B0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360CB8(void)
{
    Unk80360CB8_Y* y = lbl_806192E0->m4->m14;
    unsigned char b = y->m17C;
    Unk80360CB8_Obj* o = fn_8051F4D8();
    Unk80360CB8_Sub* sub = (Unk80360CB8_Sub*)(o->m);
    int r = sub->v11();
    fn_80089EE0((Unk80089894_PackTabD*)y->mC74, 0x1a, b, r);
}

void fn_80360D24(Unk80360D24* s)
{
    s->v3(0xe);
}

void fn_80360D5C(DtorAt10* self, int chrg)
{
    self->m = lbl_806827B0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360D90(void)
{
    Unk80360CB8_Y* y = lbl_806192E0->m4->m14;
    unsigned char b = y->m17C;
    Unk80360CB8_Obj* o = fn_8051F4D8();
    Unk80360CB8_Sub* sub = (Unk80360CB8_Sub*)(o->m);
    int r = sub->v11();
    fn_8008D850(y->mC9C, 9, b, r);
}

void fn_80360DFC(Unk80360DFC* s)
{
    s->v5(fn_8008CFD8(lbl_806192E0->m4->m14->mC9C, 9, lbl_806192E0->m4->m14->m17C));
}

void fn_80360E68(DtorAt10* self, int chrg)
{
    self->m = lbl_806827B0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360E9C(DtorAtB8* self, int chrg)
{
    self->m = lbl_8067A190;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80360ED0(Unk80360ED0* s)
{
    return s->m4;
}

extern "C" int fn_80360ED8(Unk80360ED0* s)
{
    return s->m0 != 6;
}

int fn_80360EF0(Unk80360ED0* s)
{
    return s->m0;
}

void fn_80360EF8(Unk80360EF8* s)
{
    s->m320 = 0;
    for (int i = 0; i < 100; i++) {
        s->e[i].a = lbl_805FC4D4;
        s->e[i].b = lbl_805FC4D4;
    }
}

void fn_80360F2C(Unk80360F2C* s)
{
    s->m0 = lbl_805FC4D8;
    s->m4 = lbl_805FC4D8;
    s->m8 = lbl_805FC4D8;
    s->mC = lbl_805FC4D8;
}

extern "C" void fn_80360F48(void* self, int a)
{
    fn_800EC5F4((UiScrRaw*)self);
}

void fn_80360F68(DtorAt4* self, int chrg)
{
    self->m = lbl_80667118;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360F9C(void)
{
}

int fn_80360FA0(void)
{
    return 0;
}

void fn_80360FA8(void)
{
}

void fn_80360FAC(DtorAt4* self, int chrg)
{
    self->m = lbl_80667118;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360FE0(Unk80361034* s)
{
    fn_800A29C4(s->m0, 0x7fffffff);
}

int fn_8036100C(Unk80361034* s)
{
    return fn_800A1A6C(s->m0) ^ 1;
}

void fn_80361034(Unk80361034* s)
{
    s->m0->v5();
    for (;;) {
        if (s->m0->m74 != 2)
            break;
        int k = s->m0->m80;
        if (k == 2)
            goto hit;
        if (k == 3)
            goto hit;
        if (k != 4)
            goto skip;
    hit : {
        int a, b;
        if (fn_800A3270(s->m0, &a, &b) == 0)
            fn_8055EAFC(a);
    }
    skip:
        fn_800A2F9C(s->m0, 1);
    }
    fn_800A29C4(s->m0, 0x7fffffff);
}

void fn_803610E4(DtorAt4* self, int chrg)
{
    self->m = lbl_80667118;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361118(Unk80361034* s)
{
    fn_800A2948(s->m0);
    s->m0->v5();
}

int fn_80361164(Unk80361034* s)
{
    return fn_800A2EFC(s->m0) ^ 1;
}

void fn_8036118C(Unk80361034* s)
{
    fn_800A29C4(s->m0, 0x7fffffff);
    s->m0->v5();
    for (;;) {
        if (s->m0->m74 != 2)
            break;
        int k = s->m0->m80;
        if (k == 2)
            goto hit;
        if (k == 3)
            goto hit;
        if (k != 4)
            goto skip;
    hit : {
        int a, b;
        if (fn_800A3270(s->m0, &a, &b) == 0)
            fn_8055EAFC(a);
    }
    skip:
        fn_800A2F9C(s->m0, 1);
    }
    fn_800A2948(s->m0);
    s->m0->v5();
}

void fn_80361260(DtorAt4* self, int chrg)
{
    self->m = lbl_80667118;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361294(void)
{
}

int fn_80361298(Unk80361034* s)
{
    return fn_800A2EFC(s->m0);
}

void fn_803612BC(Unk80361034* s)
{
    s->m0->v5();
    for (;;) {
        if (s->m0->m74 != 2)
            break;
        fn_800A2F9C(s->m0, 1);
    }
}

void fn_80361320(DtorAt4* self, int chrg)
{
    self->m = lbl_80667118;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361354(Unk80361034* s)
{
    fn_800A3430(s->m0);
}

int fn_80361378(Unk80361034* s)
{
    return fn_800A1B20(s->m0) ^ 1;
}

void fn_803613A0(Unk80361034* s)
{
    s->m0->v5();
    for (;;) {
        if (s->m0->m74 != 2)
            break;
        fn_800A2F9C(s->m0, 1);
    }
    fn_800A29C4(s->m0, 0x7fffffff);
}

void fn_80361414(DtorAt4* self, int chrg)
{
    self->m = lbl_80667118;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361448(Unk80361034* s)
{
    fn_800A3430(s->m0);
}

int fn_8036146C(Unk80361034* s)
{
    return fn_800A2E90(s->m0) ^ 1;
}

void fn_80361494(Unk80361034* s)
{
    fn_800A2948(s->m0);
    s->m0->v5();
    for (;;) {
        if (s->m0->m74 != 2)
            break;
        fn_800A2F9C(s->m0, 1);
    }
}

void fn_80361500(DtorAt10* self, int chrg)
{
    self->m = lbl_806827B0;
    if (chrg & 1)
        fn_80377408(self);
}

Unk80361534::Unk80361534()
{
    m0 = 0;
    m4 = lbl_80683F28;
}

int fn_80361550(char* s, int i)
{
    char* p = s + i * 0x34;
    return *(unsigned char*)(p + 0x3f0);
}

int fn_80361560(char* s, int i)
{
    char* p = s + i * 0x34;
    return *(unsigned char*)(p + 0x3f2);
}

int fn_80361570(char* s, int i)
{
    char* p = s + i * 0x34;
    return *(unsigned char*)(p + 0x3f3);
}
