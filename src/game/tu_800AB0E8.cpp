/*
 * Game code, .text 0x800AB0E8-0x800ACDA0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkFEArr {          /* one-element array, count, pointer (see fn_800AB0C4) */
    int m0[1];
    int m4;
    int m8;
};
struct UnkFETable {        /* vptr +0x18, +0x24 entry count, +0x440 table of 0xC-byte entries */
    char pad0[0x18];
    const void* m18;
    char pad1C[0x24 - 0x1C];
    int m24;
    int m28;
    int m2C;
    int m30;
    char pad34[0x440 - 0x34];
    UnkFEArr* m440;
};
struct UnkAt1C {
    char pad0[0x1C];
    void* m1C;
};
struct UnkAt20F {
    char pad0[0x20];
    float m20;
};
struct UnkFE20 {           /* +0x1C: object, +0x20/+0x24 floats */
    char pad0[0x1C];
    struct UnkFE10* m1C;
    float m20;
    float m24;
};
struct UnkFE10 {
    char pad0[0x10];
    float m10;
};
struct UnkFE40 {
    char pad0[0x34];
    int m34;
    int m38;
    int m3C;
    char m40[1];
};
struct Unk8004072C_Obj;
struct Unk80040640;
struct Unk80069F0C {
    void fn_8006C02C();
};
class FEO8 {
public:
    char pad0[8];
    virtual void s1();
    virtual int s2(int a);
    virtual int s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int s15(int a, int b, int c);
};
struct UnkAt10 {
    char pad0[0x10];
    int m10;
};
struct UnkFE28 {
    char pad0[0x28];
    int m28;
    char pad2C[4];
    int m30;
};
struct UnkFE54 {
    char pad0[0x10];
    struct UnkFE120* m10;
    char pad14[0x54 - 0x14];
    int m54;
};
struct UnkFE120 {
    char pad0[0x120];
    int m120;
};
struct UnkFE806192E0 {
    int m0;
    UnkFE54* m4;
};
struct UnkFEObj8 {         /* vptr at +8 (lbl_8065B228 / lbl_8065B1E8), 0x28 bytes */
    char pad0[8];
    const void* m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    float m24;
};
void fn_800AB0C4(UnkFEArr* a, int v);
void fn_800ADAD8(void* p);
Unk80040640* fn_8004072C();
void fn_800412AC(Unk80040640* o, int a, int b, int c, int d, int e);
extern const float lbl_805B9590;
extern const float lbl_805B9564;
extern const float lbl_805B9568;
extern const float lbl_805B956C;
extern const float lbl_805B9570;
extern const float lbl_805B9580;
extern const float lbl_805B95A0;
extern FEV18* lbl_80619D10;
extern UnkFE806192E0* lbl_806192E0;
extern const char lbl_8065B8B8[];
extern const char lbl_8065B228[];
extern const char lbl_8065B1E8[];
extern const char lbl_8065B1A8[];
extern const char lbl_8065B168[];
extern const char lbl_8065B128[];
extern const char lbl_8065B0E8[];

/* ---- generated externs ---- */

extern "C" {
void* fn_800AF020(void* p);
int fn_800AB850(UnkFETable* t, int i);
void fn_800AB0E8(UnkFEArr* a, int i);
void fn_803FFC58(void* p, int v, int n);
void fn_803FFA60(char* d, const char* s, int n);
int fn_800ABB94(void* self, int k);
void fn_800ADFC4(void* p);
void fn_800AD948(void* p, int a, float f);
void fn_800AD468(void* p);
void fn_803785E4(void* p);
void fn_800B07A0(void* o);
void fn_800B0570(void* o, int a);
void fn_800B06F8(void* o, int a);
void fn_800B0738(void* o, int a, int b, int c, int d);
void fn_800AB788(UnkFETable* t);
FEO8* fn_800AB80C(UnkFETable* t, int i, int j);
void* fn_800AC1FC(void* self);
int fn_800B08B0(void* o);
int fn_800ABEB8(UnkFETable* t, int i);
int fn_800ABF74(UnkFETable* t, int i);
int fn_800ABDFC(UnkFETable* t, int i);
int fn_800ABC58(UnkFETable* t, int key);
void fn_80328374(void* p, int c);
void fn_80377488(void* p);
}


/* ---- unit prototypes ---- */
extern "C" {
int fn_800AB1AC(UnkFEArr* a, int i);
void fn_800AB2B0();
void fn_800AB308(UnkFETable* t, int c);
void fn_800AB368(UnkFETable* t);
void fn_800AB3F8(UnkFETable* t);
void fn_800AB498(UnkFETable* t);
FEV18* fn_800AB528(FEV18* self);
FEV18* fn_800AB578(FEV18* self);
FEV18* fn_800AB5C8(FEV18* self);
void fn_800AB618(UnkFETable* t);
void fn_800AB6B8(UnkFETable* t);
void fn_800AB758(UnkFETable* t, int idx, int v);
void fn_800AB788(UnkFETable* t);
FEO8* fn_800AB80C(UnkFETable* t, int i, int j);
int fn_800AB850(UnkFETable* t, int i);
void fn_800AB878(UnkFE28* self, int a);
void fn_800ABB20(UnkFE40* self, int a, int b, char* s, int d);
int fn_800ABB94(void* self, int k);
int fn_800ABC30(UnkFETable* t, int i);
int fn_800ABC58(UnkFETable* t, int key);
void fn_800ABD80(UnkFE40* self);
int fn_800ABDC4(UnkFETable* t, int k);
int fn_800ABDFC(UnkFETable* t, int key);
int fn_800ABE80(UnkFETable* t, int k);
int fn_800ABEB8(UnkFETable* t, int key);
int fn_800ABF3C(UnkFETable* t, int k);
int fn_800ABF74(UnkFETable* t, int key);
void* fn_800AC1FC(void* self);
void fn_800AC264(void* self, int a, int b);
void fn_800AC2A0(void* self, int a);
void fn_800AC2DC(void* self, int a, int b, int c, int d);
int fn_800AC330(void* self);
void fn_800AC36C(void* self);
int fn_800AC398(void* self);
UnkFEObj8* fn_800AC6D8(UnkFEObj8* self, int a, int b, int c, float f);
UnkFEObj8* fn_800AC744(UnkFEObj8* self, int a, int b, int c, float f);
UnkFEObj8* fn_800AC7B0(UnkFEObj8* self, int a, int b, int c, float f);
UnkFEObj8* fn_800AC81C(UnkFEObj8* self, int a, int b, int c, float f);
UnkFEObj8* fn_800AC888(UnkFEObj8* self, int a, int b, int c, float f);
UnkFEObj8* fn_800AC8F4(UnkFEObj8* self, int a, int b, int c, float f);
void fn_800AC960(UnkFE20* self);
void fn_800AC9C0(UnkFE20* self);
void fn_800ACA08();
void fn_800ACAD0(UnkFE20* self);
void fn_800ACB0C(UnkAt1C* p);
void fn_800ACC34(UnkAt20F* p);
void fn_800ACC44();
void fn_800ACD48(UnkFE20* self);
}
/* ---- end prototypes ---- */

/* ---- functions ---- */

extern "C" int fn_800AB1AC(UnkFEArr* a, int i)
{
    if (i < a->m4) {
        return a->m0[i];
    }
    return 0;
}

extern "C" void fn_800AB2B0()
{
    if (lbl_80619D10) {
        delete lbl_80619D10;
        lbl_80619D10 = 0;
    }
}

extern "C" void fn_800AB308(UnkFETable* t, int c)
{
    t->m18 = lbl_8065B8B8;
    fn_800AB788(t);
    if (t->m440) {
        delete[] t->m440;
        t->m440 = 0;
    }
    fn_80328374(t, c);
}

extern "C" void fn_800AB368(UnkFETable* t)
{
    for (int i = 0; i < t->m24; i++) {
        for (int j = 0; j < fn_800AB850(t, i); j++) {
            fn_800AB80C(t, i, j)->s7();
        }
    }
}

extern "C" void fn_800AB3F8(UnkFETable* t)
{
    t->m28 = 0;
    t->m30 = 0;
    fn_800ABD80((UnkFE40*)t);
    for (int i = 0; i < t->m24; i++) {
        for (int j = 0; j < fn_800AB850(t, i); j++) {
            fn_800AB80C(t, i, j)->s8();
        }
    }
}

extern "C" void fn_800AB498(UnkFETable* t)
{
    for (int i = 0; i < t->m24; i++) {
        for (int j = 0; j < fn_800AB850(t, i); j++) {
            fn_800AB80C(t, i, j)->s10();
        }
    }
}

extern "C" FEV18* fn_800AB528(FEV18* self)
{
    if (self->s17() != 0) {
        return self;
    }
    return 0;
}

extern "C" FEV18* fn_800AB578(FEV18* self)
{
    if (self->s19() != 0) {
        return self;
    }
    return 0;
}

extern "C" FEV18* fn_800AB5C8(FEV18* self)
{
    if (self->s20() != 0) {
        return self;
    }
    return 0;
}

extern "C" void fn_800AB618(UnkFETable* t)
{
    t->m2C = 1;
    for (int i = 0; i < t->m24; i++) {
        int n = fn_800AB850(t, i);
        for (int j = 0; j < n; j++) {
            fn_800AB80C(t, i, j)->s11();
        }
    }
}

extern "C" void fn_800AB6B8(UnkFETable* t)
{
    t->m2C = 0;
    for (int i = 0; i < t->m24; i++) {
        int n = fn_800AB850(t, i);
        for (int j = 0; j < n; j++) {
            fn_800AB80C(t, i, j)->s12();
        }
    }
}

extern "C" void fn_800AB758(UnkFETable* t, int idx, int v)
{
    fn_800AB0C4(t->m440 + idx, v);
}

extern "C" void fn_800AB788(UnkFETable* t)
{
    int cnt = t->m24;
    for (int i = 0; i < cnt; i++) {
        int n = fn_800AB850(t, i);
        for (int j = 0; j < n; j++) {
            fn_800AB0E8(t->m440 + i, j);
        }
    }
}

extern "C" FEO8* fn_800AB80C(UnkFETable* t, int i, int j)
{
    if (i < t->m24) {
        return (FEO8*)fn_800AB1AC(t->m440 + i, j);
    }
    return 0;
}

extern "C" int fn_800AB850(UnkFETable* t, int i)
{
    if (i < t->m24) {
        return t->m440[i].m4;
    }
    return 0;
}

extern "C" void fn_800AB878(UnkFE28* self, int a)
{
    self->m28 = 1;
    self->m30 = a;
    UnkFE54* p = lbl_806192E0->m4;
    if (p->m10->m120 == 1) {
        ((Unk80069F0C*)p)->fn_8006C02C();
    } else {
        p->m54 = 1;
    }
}

extern "C" void fn_800ABB20(UnkFE40* self, int a, int b, char* s, int d)
{
    if (s) {
        int k = fn_800ABB94(self, b);
        fn_803FFA60(self->m40, s, k);
    } else {
        fn_803FFC58(self->m40, 0, 0x400);
    }
    self->m34 = b;
    self->m38 = d;
    self->m3C = a;
}

extern "C" int fn_800ABB94(void* self, int k)
{
    switch (k) {
    case 0x93:
    case 0x49:
        return 0x18;
    case 0x48:
        return 0x10;
    case 0x40:
    case 0x96:
        return 0xC;
    case 0x3A:
        return 0x24;
    case 0x3E:
    case 0x94:
        return 0x1C;
    case 0x39:
        return 0x20;
    }
    return 0;
}

extern "C" int fn_800ABC30(UnkFETable* t, int i)
{
    if (i < t->m24) {
        return t->m440[i].m8;
    }
    return 0;
}

extern "C" int fn_800ABC58(UnkFETable* t, int key)
{
    for (int i = 0; i < t->m24; i++) {
        if (key == t->m440[i].m8) {
            return i;
        }
    }
    return 0;
}

extern "C" void fn_800ABD80(UnkFE40* self)
{
    self->m34 = 0xC7;
    self->m38 = 0;
    self->m3C = 0;
    fn_803FFC58(self->m40, 0, 0x400);
}

extern "C" int fn_800ABDC4(UnkFETable* t, int k)
{
    return fn_800ABDFC(t, fn_800ABC58(t, k));
}

extern "C" int fn_800ABDFC(UnkFETable* t, int key)
{
    int n = fn_800AB850(t, key);
    for (int i = 0; i < n; i++) {
        int r = fn_800AB80C(t, key, i)->s2(2);
        if (r) {
            return r;
        }
    }
    return 0;
}

extern "C" int fn_800ABE80(UnkFETable* t, int k)
{
    return fn_800ABEB8(t, fn_800ABC58(t, k));
}

extern "C" int fn_800ABEB8(UnkFETable* t, int key)
{
    int n = fn_800AB850(t, key);
    for (int i = 0; i < n; i++) {
        int r = fn_800AB80C(t, key, i)->s2(1);
        if (r) {
            return r;
        }
    }
    return 0;
}

extern "C" int fn_800ABF3C(UnkFETable* t, int k)
{
    return fn_800ABF74(t, fn_800ABC58(t, k));
}

extern "C" int fn_800ABF74(UnkFETable* t, int key)
{
    int n = fn_800AB850(t, key);
    for (int i = 0; i < n; i++) {
        int r = fn_800AB80C(t, key, i)->s2(3);
        if (r) {
            return r;
        }
    }
    return 0;
}

extern "C" void* fn_800AC1FC(void* self)
{
    FEO8* o = fn_800AB80C((UnkFETable*)self, 0, 0);
    if (o) {
        if (o->s3()) {
            return fn_800AF020(o);
        }
    }
    return 0;
}

extern "C" void fn_800AC264(void* self, int a, int b)
{
    void* o = fn_800AC1FC(self);
    if (o) {
        fn_800B0570(o, b);
    }
}

extern "C" void fn_800AC2A0(void* self, int a)
{
    void* o = fn_800AC1FC(self);
    if (o) {
        fn_800B06F8(o, a);
    }
}

extern "C" void fn_800AC2DC(void* self, int a, int b, int c, int d)
{
    void* o = fn_800AC1FC(self);
    if (o) {
        fn_800B0738(o, a, b, c, d);
    }
}

extern "C" int fn_800AC330(void* self)
{
    UnkAt10* o = (UnkAt10*)fn_800AC1FC(self);
    if (o) {
        if (o->m10 != 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_800AC36C(void* self)
{
    void* o = fn_800AC1FC(self);
    if (o) {
        fn_800B07A0(o);
    }
}

extern "C" int fn_800AC398(void* self)
{
    void* o = fn_800AC1FC(self);
    if (o) {
        return fn_800B08B0(o);
    }
    return 0;
}

extern "C" UnkFEObj8* fn_800AC6D8(UnkFEObj8* self, int a, int b, int c, float f)
{
    fn_803785E4(self);
    self->mC = 0;
    self->m10 = 0;
    self->m14 = c;
    self->m18 = a;
    self->m8 = lbl_8065B228;
    self->m1C = b;
    self->m24 = f;
    return self;
}

extern "C" UnkFEObj8* fn_800AC744(UnkFEObj8* self, int a, int b, int c, float f)
{
    fn_803785E4(self);
    self->mC = 0;
    self->m10 = 0;
    self->m14 = c;
    self->m18 = a;
    self->m8 = lbl_8065B1E8;
    self->m1C = b;
    self->m24 = f;
    return self;
}

extern "C" UnkFEObj8* fn_800AC7B0(UnkFEObj8* self, int a, int b, int c, float f)
{
    fn_803785E4(self);
    self->mC = 0;
    self->m10 = 0;
    self->m14 = c;
    self->m18 = a;
    self->m8 = lbl_8065B1A8;
    self->m1C = b;
    self->m24 = f;
    return self;
}

extern "C" UnkFEObj8* fn_800AC81C(UnkFEObj8* self, int a, int b, int c, float f)
{
    fn_803785E4(self);
    self->mC = 0;
    self->m10 = 0;
    self->m14 = c;
    self->m18 = a;
    self->m8 = lbl_8065B168;
    self->m1C = b;
    self->m24 = f;
    return self;
}

extern "C" UnkFEObj8* fn_800AC888(UnkFEObj8* self, int a, int b, int c, float f)
{
    fn_803785E4(self);
    self->mC = 0;
    self->m10 = 0;
    self->m14 = c;
    self->m18 = a;
    self->m8 = lbl_8065B128;
    self->m1C = b;
    self->m24 = f;
    return self;
}

extern "C" UnkFEObj8* fn_800AC8F4(UnkFEObj8* self, int a, int b, int c, float f)
{
    fn_803785E4(self);
    self->mC = 0;
    self->m10 = 0;
    self->m14 = c;
    self->m18 = a;
    self->m8 = lbl_8065B0E8;
    self->m1C = b;
    self->m24 = f;
    return self;
}

/* near-miss (6 slots): retail loads the lbl_805B9568 constant into f12 (reusing the spilled d register) and stores u after the compare */
extern "C" void fn_800AC960(UnkFE20* self)
{
    UnkFE10* o = self->m1C;
    self->m20 = self->m20 + lbl_805B9564;
    float d = self->m24;
    float u = self->m20;
    if (!(d >= lbl_805B9568)) {
        o->m10 = lbl_805B9568;
    } else {
        o->m10 = u / d;
    }
}

extern "C" void fn_800AC9C0(UnkFE20* self)
{
    fn_800AD948(self->m1C, 0, lbl_805B956C);
    self->m20 = lbl_805B9570;
}

extern "C" void fn_800ACA08()
{
}

extern "C" void fn_800ACAD0(UnkFE20* self)
{
    fn_800AD468(self->m1C);
    self->m20 = lbl_805B9580;
}

extern "C" void fn_800ACB0C(UnkAt1C* p)
{
    fn_800ADAD8(p->m1C);
}

extern "C" void fn_800ACC34(UnkAt20F* p)
{
    p->m20 = lbl_805B9590;
}

extern "C" void fn_800ACC44()
{
}

extern "C" void fn_800ACD48(UnkFE20* self)
{
    fn_800ADFC4(self->m1C);
    self->m20 = lbl_805B95A0;
    fn_800412AC(fn_8004072C(), 0x28, 0, 0, 0, 0);
}
