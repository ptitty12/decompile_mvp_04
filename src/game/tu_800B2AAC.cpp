/*
 * Game code, .text 0x800B2AAC-0x800B5C68 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"
#include "game/tu_8007A4DC.h"

struct UnkAt5C {
    char pad0[0x5C];
    int m5C;
};
struct UnkAtA8 {
    char pad0[0xA8];
    int mA8;
};
struct UnkAt1C24 {
    char pad0[0x1C];
    void* m1C;
    int m20;
    int m24;
};
extern int lbl_805C3CC4[];
extern const char* lbl_80619D34[];
extern int lbl_8061A114[];
int fn_800736EC(const char* s);
extern Unk8007B2B0_Screen* lbl_8061930C;

/* Seven-word record at +0xC of the game object seen by fn_800B526C / fn_800B5290. */
struct GRec7 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
/* Game-state object (vptr-less data part): record at +0xC, counters at +0x9C..+0xA8,
 * +0xD4, the helper object (vptr at +0x3C) at +0xDC. */
struct GObj {
    int m0;
    int m4;
    int m8;
    GRec7 mC;
    char pad28[0x9C - 0x28];
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    char padAC[0xD4 - 0xAC];
    int mD4;
    int mD8;
    FEV3C* mDC;
    char padE0[0x110 - 0xE0];
    int m110;
};
struct GVec {
    float m0;
    float m4;
    float m8;
};
struct G10;
struct G4Rec {
    char pad0[0xC];
    char* mC;
    G10* m10;
};
struct G10 {
    char pad0[0x18];
    int m18;
    char pad1C[0x22C - 0x1C];
    int m22C;
};
struct G806192E0 {
    int m0;
    G4Rec* m4;
};
extern G806192E0* lbl_806192E0;
extern void* lbl_8061E978;
extern const float lbl_805B9E00;
extern const float lbl_805B9D30;
extern const float lbl_805B9D34;
extern const float lbl_805B9D38;
extern const char lbl_805B99E8[];
extern const char lbl_805B99F0[];
extern int lbl_80619F24[];
extern Unk800B555C* lbl_8061A304;
extern const char lbl_8065BEF0[];
extern const float lbl_805B9FF4;
extern const char lbl_805B9D18[];

struct Unk8007F198_D;
int fn_8007FDF8(Unk8007F198_D* self);
struct Unk8004072C;
Unk8004072C* fn_8004072C();

struct FEMgrB8 {
    char pad0[0xA0];
    int mA0;
    char padA4[0xB8 - 0xA4];
    int mB8;
    int mBC;
};
extern FEMgrB8* lbl_8061A32C;
struct Row16 {
    int m0;
    int m4;
    int m8;
    int mC;
};
extern Row16 lbl_805C3C84[];
struct GObj2 {
    char pad0[0x24];
    int m24;
    int m28;
    char pad2C[0x38 - 0x2C];
    int m38;
};
struct GObj5 {
    char pad0[0xB8];
    int mB8;
    int mBC;
    int mC0;
    int mC4;
};
struct GRec60 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    void Clear()
    {
        m0 = 0;
        m8 = 0;
        mC = 0;
        m10 = 0;
        m14 = 0;
        m18 = 0;
        m1C = 0;
        m20 = 0;
        m24 = 0;
        m28 = 0;
        m2C = 0;
        m30 = 0;
        m4 = 0;
        m38 = 0;
        m34 = 1;
    }
};
struct GObj6 {
    char pad0[0x60];
    GRec60 m60;
    char pad9C[0xA0 - 0x9C];
    int mA0;
    int mA4;
    char padA8[0xF8 - 0xA8];
    int mF8;
    int mFC;
    float m100;
    int m104;
};
extern const float lbl_805B9BD4;
extern const char lbl_805B9BA8[];
class FEV8 {
public:
    char pad0[8];
    virtual void s1();
    virtual void s2();
    virtual void s3();
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
    virtual void s15();
    virtual int s16();
};
struct GObj7 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x9C - 0x20];
    int m9C;
    int mA0;
    char padA4[4];
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    char padB8[0xC8 - 0xB8];
    int mC8;
    int mCC;
    int mD0;
    int mD4;
    int mD8;
    int mDC;
    int mE0;
    int mE4;
    int mE8;
    int mEC;
    int mF0;
    int mF4;
};
struct GObj3 {
    char pad0[0x148];
    int m148;
    int m14C;
};
struct GObj5C {
    char pad0[0x5C];
    void* m5C;
};

/* ---- generated externs ---- */


extern "C" {
void fn_801200C4(void* o, int a);
void fn_800B302C(GObj* self);
void fn_800B33D4(GObj6* self);
void fn_800B5170(GObj5* self);
FEMgrB8* fn_800B64BC(FEMgrB8* p);
void* fn_800B7AB8(FEMgrB8* mgr, const char* name);
void fn_8011D850(void* w, int a, int b);
void fn_8004181C(Unk8004072C* o, int a, int b, int c, int d, int e, int f);
int fn_80089AA0(char* p, int a, int b);
int fn_800B4D8C(GObj2* self, int a);
int fn_800B5D34();
void fn_800C1C8C(void* p);
void fn_800B5414(void* self);
void* fn_800AF010(void* p, int k);
void fn_800B3218(GObj3* self);
void fn_800B3348(GObj6* self);
int fn_800B2204(GObj* self);
int fn_8011B494(void* p, int a, int b);
void fn_8012004C(FEV3C* o, int a, int b);
int fn_80403060(const char* s);
void fn_800A7080(char* a, char* b, int c, int d, int e);
void fn_802B09CC(void* o, const char* s, int a, int b, int c);
}

inline FEMgrB8* GetMgr()
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC((FEMgrB8*)operator new(0xD8, 0));
    }
    return lbl_8061A32C;
}

inline int FEIsBC(int v)
{
    if (v == 0x42 || v == 0x43) {
        return 1;
    }
    return 0;
}


/* ---- unit prototypes ---- */
extern "C" {
int fn_800B2B78();
void* fn_800B2B80(void* self, int k);
void fn_800B2BB0(GObj* self);
void fn_800B2C6C(GObj* self);
void fn_800B2C94(int a, int b, int c, int d, int e);
void fn_800B2CF8(GObj* self, int a);
void fn_800B2D40(GObj* self, int a);
void fn_800B2D88(GObj* self, int a, int b);
void fn_800B2FCC(GObj* self);
int fn_800B3150(void* self, int idx);
void fn_800B3198(GObj* self, int a);
void fn_800B3218(GObj3* self);
void fn_800B32A4(GObj7* self);
void fn_800B3348(GObj6* self);
int fn_800B3734(void* self, int target, char* obj, int c);
void* fn_800B37A8(void* self, int k);
void fn_800B37D8(GObj5C* self);
void fn_800B385C(UnkAt5C* p);
void fn_800B3868();
int fn_800B386C(UnkAtA8* p);
float fn_800B3890(GObj* self);
int fn_800B4C64();
void* fn_800B4CFC(UnkAt1C24* p);
int fn_800B4D18(GObj2* self, int a);
void fn_800B5170(GObj5* self);
int fn_800B522C(void* self, int n, GVec* v);
void fn_800B526C(GObj* self);
void fn_800B5290(GObj* self);
void fn_800B52F8(void* unused, int a);
void fn_800B5364(GObj* self);
int fn_800B53A4(int a, int i);
Unk800B555C* fn_800B53B8(Unk800B555C* self);
void fn_800B5414(void* self);
void fn_800B548C(int i);
int fn_800B54BC(int i);
void fn_800B54D0(Unk800B555C* self);
int fn_800B5520(int key);
Unk800B555C* fn_800B555C();
int fn_800B55A8();
int fn_800B5634();
int fn_800B56C4();
int fn_800B5758();
int fn_800B57EC();
int fn_800B5898();
int fn_800B5948();
int fn_800B59DC();
int fn_800B5A70();
int fn_800B5B04(int* p);
int fn_800B5B40();
int fn_800B5BD4();
}
/* ---- end prototypes ---- */

/* ---- functions ---- */

extern "C" int fn_800B2B78()
{
    return 0;
}

extern "C" void* fn_800B2B80(void* self, int k)
{
    if (k == 1) {
        return (char*)self + 0xC;
    }
    return fn_800AF010(self, k);
}

extern "C" void fn_800B2BB0(GObj* self)
{
    if (GetMgr()->mA0 != 0) {
        self->mDC = (FEV3C*)fn_800B7AB8(GetMgr(), lbl_805B9BA8);
    }
    if (self->mD8 == 0) {
        if (self->mDC) {
            fn_801200C4(self->mDC, 10 - self->mD4);
        }
    } else {
        fn_800B302C(self);
    }
}

extern "C" void fn_800B2C6C(GObj* self)
{
    self->mDC = 0;
    fn_800B3218((GObj3*)self);
}

extern "C" void fn_800B2C94(int a, int b, int c, int d, int e)
{
    fn_802B09CC(lbl_8061E978, lbl_805B99E8, 1, 0xFF, d);
    fn_802B09CC(lbl_8061E978, lbl_805B99F0, 1, 0xFF, e);
}

extern "C" void fn_800B2CF8(GObj* self, int a)
{
    if (self->mDC) {
        self->mDC->s90(self->m4, a);
    }
}

extern "C" void fn_800B2D40(GObj* self, int a)
{
    if (self->mDC) {
        self->mDC->s91(self->m4, a);
    }
}

extern "C" void fn_800B2D88(GObj* self, int a, int b)
{
    if (self->mDC) {
        self->mDC->s92(self->m4, a, b);
    }
}

extern "C" void fn_800B2FCC(GObj* self)
{
    int v = fn_8011B494((char*)self + 0x140, self->m110, 0x14);
    FEV3C* o = self->mDC;
    if (o) {
        fn_8012004C(o, v, fn_800B2204(self));
    }
}

extern "C" int fn_800B3150(void* self, int idx)
{
    int t[5] = {0x5A25, 0x5A26, 0x5A1F, 0x5A20, 0x5A21};
    return t[idx];
}

extern "C" void fn_800B3198(GObj* self, int a)
{
    G4Rec* p = lbl_806192E0->m4;
    char* s = p->mC + 0x5EC;
    if (fn_80403060(s) > 0) {
        int c = p->m10->m18;
        int k = 1;
        if (self->mD8 == 0) {
            k = 2;
        }
        fn_800A7080(p->mC + 0xA0, s, c, a, k);
    }
}

extern "C" void fn_800B3218(GObj3* self)
{
    int n = -1;
    if (self->m148 != -1) {
        fn_8004181C(fn_8004072C(), 0xF, self->m148, 0, 0, 0, 0);
        self->m148 = n;
    }
    if (self->m14C != -1) {
        fn_8004181C(fn_8004072C(), 0x10, self->m14C, 0, 0, 0, 0);
        self->m14C = n;
    }
}

/* near-miss (2 slots): retail stores mF4 before m1C (`li r9,1`); ~400 store orders tried by hill-climb */
extern "C" void fn_800B32A4(GObj7* self)
{
    ((FEV8*)self)->s16();
    self->mA8 = 0;
    self->m9C = 0;
    self->mA0 = 0;
    self->mAC = 0;
    self->m1C = 1;
    self->mB0 = 0;
    self->mB4 = 0;
    self->mC8 = 0;
    self->mCC = 0;
    self->mD0 = 0;
    self->mD4 = 0;
    self->mD8 = 0;
    self->mDC = 0;
    self->mE0 = 0;
    self->mE4 = 0;
    self->mE8 = 0;
    self->mEC = 0;
    self->mF0 = 0;
    self->mF4 = 0;
    fn_800B5170((GObj5*)self);
    fn_800B3348((GObj6*)self);
}

extern "C" void fn_800B3348(GObj6* self)
{
    self->mA4 = 0;
    self->m100 = lbl_805B9BD4;
    self->mF8 = 0;
    self->mA0 = 0;
    self->mFC = 0;
    self->m104 = 0;
    self->m60.Clear();
    fn_800B33D4(self);
}

extern "C" int fn_800B3734(void* self, int target, char* obj, int c)
{
    for (int i = 0; i <= 3; i++) {
        if (fn_80089AA0(obj + 0xC74, lbl_805C3C84[i].m0, c) == target) {
            return 1;
        }
    }
    return 0;
}

extern "C" void* fn_800B37A8(void* self, int k)
{
    if (k == 3) {
        return (char*)self + 0xC;
    }
    return fn_800AF010(self, k);
}

extern "C" void fn_800B37D8(GObj5C* self)
{
    void* w = fn_800B7AB8(GetMgr(), lbl_805B9D18);
    self->m5C = w;
    if (w) {
        fn_8011D850(w, 0, fn_800B386C((UnkAtA8*)self));
    }
}

extern "C" void fn_800B385C(UnkAt5C* p)
{
    p->m5C = 0;
}

extern "C" void fn_800B3868()
{
}

extern "C" int fn_800B386C(UnkAtA8* p)
{
    int r;
    if (p->mA8 > 3) {
        r = (p->mA8 - 3) * 500;
    } else {
        r = 0;
    }
    return r + 2000;
}

extern "C" float fn_800B3890(GObj* self)
{
    float t = (float)self->mA8 * lbl_805B9D30 + lbl_805B9D34;
    return t <? lbl_805B9D38;
}

extern "C" int fn_800B4C64()
{
    return 1;
}

extern "C" void* fn_800B4CFC(UnkAt1C24* p)
{
    void* r = 0;
    if (p->m24 == 0) {
        r = p->m1C;
    }
    return r;
}

extern "C" int fn_800B4D18(GObj2* self, int a)
{
    int p = (int)fn_800B4CFC((UnkAt1C24*)self);
    int q = fn_800B4D8C(self, a);
    int t = 0;
    if (self->m24 == 0) {
        t = self->m38;
    }
    int r = p + q + t;
    if (self->m24 != 0) {
        r = 0;
    }
    if (self->m28 != 0) {
        r = 0;
    }
    return r;
}

extern "C" void fn_800B5170(GObj5* self)
{
    int n = -1;
    if (self->mBC != -1) {
        fn_8004181C(fn_8004072C(), self->mB8, self->mBC, 0, 0, 0, 0);
        self->mBC = n;
    }
    if (self->mC0 != -1) {
        fn_8004181C(fn_8004072C(), 0xF, self->mC0, 0, 0, 0, 0);
        self->mC0 = n;
    }
    if (self->mC4 != -1) {
        fn_8004181C(fn_8004072C(), 0x10, self->mC4, 0, 0, 0, 0);
        self->mC4 = n;
    }
}

extern "C" int fn_800B522C(void* self, int n, GVec* v)
{
    int r = 0x18;
    if (n > 0) {
        if (v->m8 >= lbl_805B9E00 || !(v->m0 < lbl_805B9E00)) {
            r = 0x16;
        } else {
            r = 0x17;
        }
    }
    return r;
}

extern "C" void fn_800B526C(GObj* self)
{
    GRec7* r = &self->mC;
    r->m0 = 10 - self->mA4;
    r->mC = self->mA0;
    r->m18 = self->m9C;
}

extern "C" void fn_800B5290(GObj* self)
{
    GRec7* r = &self->mC;
    int a = 10 - self->mA4;
    r->m0 = a;
    r->m4 = 0x5DC;
    int b = a * 0x5DC;
    r->m8 = b;
    r->mC = self->mA0;
    r->m14 = self->m9C;
    r->m10 = self->mA8 + 1;
    self->m9C += self->mA0 + b;
    r->m18 = self->m9C;
    self->mD4 += self->mA4;
}

extern "C" void fn_800B52F8(void* unused, int a)
{
    G4Rec* p = lbl_806192E0->m4;
    char* s = p->mC + 0x5EC;
    if (fn_80403060(s) > 0) {
        fn_800A7080(p->mC + 0xA0, s, p->m10->m18, a, 0);
    }
}

extern "C" void fn_800B5364(GObj* self)
{
    fn_800B3348((GObj6*)self);
    int n = self->mA8 + 1;
    self->mA8 = n;
    self->mC.m10 = n + 1;
}

extern "C" int fn_800B53A4(int a, int i)
{
    return lbl_805C3CC4[i];
}

extern "C" Unk800B555C* fn_800B53B8(Unk800B555C* self)
{
    self->m6A0 = lbl_8065BEF0;
    fn_800C1C8C((char*)self + 8);
    self->m680 = lbl_805B9FF4;
    self->m684 = 0;
    fn_800B54D0(self);
    return self;
}

extern "C" void fn_800B5414(void* self)
{
    for (int i = 0; i < 0x7C; i++) {
        int v = fn_800736EC(lbl_80619D34[i]);
        lbl_80619F24[i] = v;
        lbl_8061A114[i] = lbl_8061930C->fn_8007B8C4(2, v);
    }
}

extern "C" void fn_800B548C(int i)
{
    fn_800736EC(lbl_80619D34[i]);
}

extern "C" int fn_800B54BC(int i)
{
    return lbl_8061A114[i];
}

extern "C" void fn_800B54D0(Unk800B555C* self)
{
    self->m678 = -1;
    self->m0 = 0;
    self->m4 = 0;
    self->m674 = 0;
    self->m67C = fn_800B5D34();
    fn_800B5414(self);
}

extern "C" int fn_800B5520(int key)
{
    int i;
    for (i = 0; i < 0x7C; i++) {
        if (lbl_80619F24[i] == key) {
            return i;
        }
    }
    return 0;
}

extern "C" Unk800B555C* fn_800B555C()
{
    if (lbl_8061A304 == 0) {
        lbl_8061A304 = fn_800B53B8((Unk800B555C*)operator new(0x6A4, 0));
    }
    return lbl_8061A304;
}

extern "C" int fn_800B55A8()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 0;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0;
    }
    return r;
}

extern "C" int fn_800B5634()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 0;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 1;
    }
    return r;
}

extern "C" int fn_800B56C4()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 0xC;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xC;
    }
    return r;
}

extern "C" int fn_800B5758()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 0xD;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xD;
    }
    return r;
}

extern "C" int fn_800B57EC()
{
    int r = 0;
    if (GetMgr()->mB8 == 1) {
        int v = lbl_806192E0->m4->m10->m22C;
        if (v == 0xC) {
            r = 1;
        } else if (v == 0xD) {
            r = 1;
        }
    } else {
        if (fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xC) {
            r = 1;
        } else if (fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xD) {
            r = 1;
        }
    }
    return r;
}

extern "C" int fn_800B5898()
{
    int r = 0;
    if (GetMgr()->mB8 == 1) {
        int v = lbl_806192E0->m4->m10->m22C;
        if (v > 0xF) {
            r = v <= 0x17;
        }
    } else {
        if (fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) > 0xF) {
            r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) <= 0x17;
        }
    }
    return r;
}

extern "C" int fn_800B5948()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 0xB;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xB;
    }
    return r;
}

extern "C" int fn_800B59DC()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 7;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 7;
    }
    return r;
}

extern "C" int fn_800B5A70()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 8;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 8;
    }
    return r;
}

extern "C" int fn_800B5B04(int* p)
{
    int v = *p;
    int a = 0;
    if (v == 0x42) {
        a = 1;
    } else if (v == 0x43) {
        a = 1;
    }
    int r = 0;
    if (a || v == 0x44) {
        r = 1;
    }
    return r;
}

extern "C" int fn_800B5B40()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 9;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 9;
    }
    return r;
}

extern "C" int fn_800B5BD4()
{
    int r;
    if (GetMgr()->mB8 == 1) {
        r = lbl_806192E0->m4->m10->m22C == 0xA;
    } else {
        r = fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xA;
    }
    return r;
}
