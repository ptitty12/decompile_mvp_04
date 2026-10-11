/*
 * Game code, .text 0x800AF248-0x800B2AAC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAt2C {
    char pad0[0x2C];
    int m2C;
    int m30;
    char pad34[4];
    int m38;
    int m3C;
    int m40;
};
struct UnkAt10 {
    char pad0[0x10];
    int m10;
};
struct UnkAt10P {
    char pad0[0x10];
    void* m10;
};

struct FEOb68 {
    char pad0[0x68];
    float m68;
    char pad6C[0x78 - 0x6C];
    int m78;
};
struct FEOb110 {
    char pad0[0xAC];
    int mAC[10];
    char padD4a[0xD4 - 0xD4];
    int mD4;
    char padD8[0x110 - 0xD8];
    int m110;
};
struct FEOb118 {
    char pad0[0x118];
    int m118[5];
};
struct FEOb210 {
    char pad0[0x5C];
    int m5C;
    char pad60[0x7C - 0x60];
    int m7C[12];
    char padAC[0xD4 - 0xAC];
    int mD4;
    int mD8;
    char padDC[0xE0 - 0xDC];
    int mE0[12];
    int m110;
    int m114;
};
struct FEObj10v {
    char pad0[4];
    int m4;
    char pad8[8];
    FEV3Cq* m10;
};
struct FEObjC {
    char pad0[0xC];
    FEV0b mC;
};
struct FEMgrB8 {
    char pad0[0xB8];
    int mB8;
};
extern FEMgrB8* lbl_8061A32C;
extern void* lbl_8061E978;
extern const char lbl_805B99D8[];
extern const char lbl_805B99E8[];
extern const char lbl_805B99F0[];
extern int lbl_80620414;
extern const float lbl_805B99F8;
extern const float lbl_805B99FC;
extern const float lbl_805B9A00;
struct FEOb214 {
    char pad0[4];
    struct FEOb4* m4;
    char pad8[0x140 - 8];
    int m140;
};
struct FEOb4 {
    char pad0[0x14];
    int m14;
};
struct FEOb4p {
    char pad0[4];
    FEOb4* m4;
};
struct FEOb7C {
    char pad0[0x7C];
    int m7C[12];
};
struct FEOb6F8h {
    char pad0[0x10];
    struct FEOb154* m10;
};
struct FEOb154 {
    char pad0[0x154];
    int m154[4];
};
struct FEOb6F8 {
    char pad0[4];
    struct FEOb6F8x* m4;
};
struct FEOb6F8x {
    char pad0[0x6F8];
    FEOb6F8h* m6F8;
};
struct FEObAF {
    int m0;
    FEOb6F8x* m4;
    char pad8[4];
    int mC;
};
struct FEStats {
    char pad0[0x118];
    int m118;
    int m11C;
    int m120;
    int m124;
    int m128;
};
struct FEEv {
    int m0;
    char pad4[0x10];
    int m14;
    int m18;
};
extern FEV18* lbl_80619D10;
struct FEOb107 {
    char pad0[0x10];
    FEV3Cz* m10;
    char pad14[0x20 - 0x14];
    int m20;
};
extern const char lbl_805B9A04[];
extern "C" FEV3Cz* fn_800C8044(FEV3Cz* o);
extern "C" void fn_800FC1F0(FEV3Cz* o, int a, int b);
struct FEOb1DBC {
    char pad0[0x20];
    int m20;
    int m24;
    int m28;
    char pad2C[0x60 - 0x2C];
    int m60;
    char pad64[0x70 - 0x64];
    int m70;
    char pad74[0x110 - 0x74];
    int m110;
};
struct Unk8019F8C0_Owner;
int fn_801A2034(Unk8019F8C0_Owner* o, int k);
struct FEOb245 {
    char pad0[4];
    Unk8019F8C0_Owner* m4;
    char pad8[0x68 - 8];
    float m68;
    char pad6C[0xAC - 0x6C];
    int mAC[10];
    int mD4;
    int mD8;
};
extern const float lbl_805B9B7C;
extern const float lbl_805B9B80;
struct FEOb2588 {
    char pad0[0x68];
    float m68;
    char pad6C[4];
    int m70;
    char pad74[0xDC - 0x74];
    void* mDC;
    char padE0[0x110 - 0xE0];
    int m110;
};
extern "C" void fn_80120144(void* o, float f);
extern "C" void fn_800B2DD4(void* self, int k);
extern "C" int fn_802D7DB4(int a, int b);
struct FEOb65C {
    char pad0[0x65C];
    char* m65C;
};
struct FEOb1F04 {
    char pad0[4];
    FEOb65C* m4;
    char pad8[0x114 - 8];
    int m114;
};
extern const float lbl_805B9B70;
extern "C" void fn_80252DF4(char* p, float f);
struct FEOb26 {
    char pad0[0x68];
    float m68;
    float m6C;
};
struct Unk80040640;
Unk80040640* fn_8004072C();
void fn_800412AC(Unk80040640* o, int a, int b, int c, int d, int e);
extern const float lbl_805B9B98;
extern const float lbl_805B9B9C;
extern const float lbl_805B9BA0;
extern const float lbl_805B9BA4;
struct FEOb2390 {
    char pad0[0x68];
    float m68;
    char pad6C[0x74 - 0x6C];
    int m74;
    char pad78[0x114 - 0x78];
    int m114;
};
struct FEOb806 {
    char pad0[4];
    struct FEOb806b* m4;
};
struct FEOb806b {
    char pad0[0xC];
    char* mC;
};
extern FEOb806* lbl_806192E0;
extern const float lbl_805B9B78;
struct FEOb14 {
    char pad0[0xC];
    FEV0b mC;
    char pad10[4];
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
};
extern const float lbl_805B9B90;
extern const float lbl_805B9B94;
struct FEOb74 {
    char pad0[0x68];
    float m68;
    char pad6C[0x74 - 0x6C];
    int m74;
};
inline float FMax2(float a, float b)
{
    return b >? a;
}

struct FEObj14 {
    char pad0[0x14];
    void* m14;
};
struct FEObj24 {
    char pad0[0x24];
    int m24;
};
struct FEObj44 {
    char pad0[0x44];
    int m44;
};
struct FEObj58 {
    char pad0[0x48];
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
};
extern const float lbl_805B9B74;
extern const char lbl_805B97A4[];
extern "C" {
FEMgrB8* fn_800B64BC(FEMgrB8* p);
void* fn_800B7AB8(FEMgrB8* mgr, const char* name);
void fn_802B09CC(void* o, const char* s, int a, int b, int c);
void fn_800AF110(void* p);
void fn_800FC6B4(void* p);
void* fn_800AF010(void* p, int k);
void fn_800AE96C(char* p);
void fn_800AEBAC(char* p);
void fn_800B1D90(FEOb110* p);
void fn_800B1E84(FEOb7C* p);
void fn_800B228C(FEOb118* p);
void fn_800A74C8(char* p, int a);
FEV18* fn_800AB5C8(FEV18* p);
char* fn_800AEC78(char* p, int a);
int fn_800B214C(FEOb214* p);
int fn_800B210C(FEOb210* p);
void fn_800AF148(void* p);
void fn_800AF544(UnkAt2C* p);
void fn_8011A0A4(void* o, void* a, const char* s);
}

/* ---- generated externs ---- */















/* ---- unit prototypes ---- */
extern "C" {
void fn_800AF544(UnkAt2C* p);
void fn_800AF560(FEObj14* self, FEObj24* a);
void fn_800AF878(void* p);
void fn_800AFAE4(FEObj44* self);
void fn_800AFD2C(FEObj58* self);
void fn_800AFD70(FEObAF* self);
void fn_800B0484(FEOb14* self);
void* fn_800B04D4(void* p, int k);
void fn_800B0504(FEObj10v* self);
void fn_800B0564(UnkAt10* p);
void fn_800B0570(FEObj10v* self, int a);
void fn_800B05B8(int a, int b, int c, int d, int e);
void fn_800B061C(FEObj10v* self, int a);
void fn_800B0664(FEObj10v* self, int a);
void fn_800B06AC(FEObj10v* self, int a, int b);
void fn_800B06F8(FEObj10v* self, int a);
void fn_800B0738(FEObj10v* self, float* a, float* b, float* c, float* d);
void fn_800B07A0(FEObj10v* self);
void fn_800B07E0(FEOb107* self, int a, int b);
void fn_800B0884(UnkAt10P* p);
void fn_800B1D90(FEOb110* self);
void fn_800B1DBC(FEOb1DBC* self, int lvl);
void fn_800B1E84(FEOb7C* self);
void fn_800B1F04(FEOb1F04* self);
int fn_800B1FCC(FEOb210* self);
int fn_800B2034(char* p);
int fn_800B2048(char* p);
int fn_800B20E0(FEOb68* self);
int fn_800B210C(FEOb210* self);
int fn_800B214C(FEOb214* self);
int fn_800B21C0(FEOb210* self);
int fn_800B2204(FEOb210* self);
int fn_800B2238(FEOb2390* self);
void fn_800B228C(FEOb118* self);
void fn_800B22B0(FEStats* self, FEEv* e);
void fn_800B2390(FEOb2390* self);
void fn_800B243C(void* p);
void fn_800B245C(FEOb245* self);
void fn_800B2544(void* self);
void fn_800B2588(FEOb2588* self);
void fn_800B2668(FEOb74* self);
void fn_800B26CC(FEOb26* self);
}
/* ---- end prototypes ---- */

/* ---- functions ---- */
extern "C" void fn_800AF544(UnkAt2C* p)
{
    p->m38 = 0;
    p->m3C = 0;
    p->m40 = 0;
    p->m2C = 0;
    p->m30 = 0;
}

extern "C" void fn_800AF560(FEObj14* self, FEObj24* a)
{
    if (a->m24 < 0) {
        fn_8011A0A4(self->m14, a, lbl_805B97A4);
    }
}

extern "C" void fn_800AF878(void* p)
{
    fn_800AF110(p);
}

extern "C" void fn_800AFAE4(FEObj44* self)
{
    fn_800AF148(self);
    self->m44 = 0;
}

extern "C" void fn_800AFD2C(FEObj58* self)
{
    fn_800AF544((UnkAt2C*)self);
    self->m48 = 0;
    self->m4C = 0;
    self->m50 = 0;
    self->m54 = 0;
    self->m58 = 0;
}

/* near-miss (3 slots): retail loads the switch index into r11 (not r0) before the table add; forms with a local index, byte offset or int* base tried */
extern "C" void fn_800AFD70(FEObAF* self)
{
    char* t = (char*)self->m4->m6F8->m10 + 0x154;
    int o = self->m0 * 4;
    int v = *(int*)(t + o);
    int r;
    switch (v) {
    case 0:
        r = 3000;
        break;
    case 1:
        r = 5280;
        break;
    case 2:
        r = 7500;
        break;
    case 3:
        r = 10000;
        break;
    default:
        r = 5280;
        break;
    }
    self->mC = r;
}

extern "C" void fn_800B0484(FEOb14* self)
{
    self->m14 = 0;
    self->m18 = 0;
    self->m1C = 0;
    self->m20 = 0;
    self->m24 = 0;
    ((FEV0b*)((char*)self + 0xC))->s2();
}

extern "C" void* fn_800B04D4(void* p, int k)
{
    if (k == 1) {
        return (char*)p + 0xC;
    }
    return fn_800AF010(p, k);
}

extern "C" void fn_800B0504(FEObj10v* self)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC((FEMgrB8*)operator new(0xD8, 0));
    }
    self->m10 = (FEV3Cq*)fn_800B7AB8(lbl_8061A32C, lbl_805B99D8);
}

extern "C" void fn_800B0564(UnkAt10* p)
{
    p->m10 = 0;
}

extern "C" void fn_800B0570(FEObj10v* self, int a)
{
    if (self->m10) {
        self->m10->s86(self->m4, a);
    }
}

extern "C" void fn_800B05B8(int a, int b, int c, int d, int e)
{
    fn_802B09CC(lbl_8061E978, lbl_805B99E8, 1, 0xFF, d);
    fn_802B09CC(lbl_8061E978, lbl_805B99F0, 1, 0xFF, e);
}

extern "C" void fn_800B061C(FEObj10v* self, int a)
{
    if (self->m10) {
        self->m10->s85(self->m4, a);
    }
}

extern "C" void fn_800B0664(FEObj10v* self, int a)
{
    if (self->m10) {
        self->m10->s87(self->m4, a);
    }
}

extern "C" void fn_800B06AC(FEObj10v* self, int a, int b)
{
    if (self->m10) {
        self->m10->s88(self->m4, a, b);
    }
}

extern "C" void fn_800B06F8(FEObj10v* self, int a)
{
    if (self->m10) {
        self->m10->s89(a);
    }
}

extern "C" void fn_800B0738(FEObj10v* self, float* a, float* b, float* c, float* d)
{
    *a = lbl_805B99F8;
    *b = lbl_805B99F8;
    *c = lbl_805B99FC;
    *d = lbl_805B9A00;
    if (self->m10) {
        self->m10->s90(a, b, c, d);
    }
}

extern "C" void fn_800B07A0(FEObj10v* self)
{
    if (self->m10) {
        self->m10->s91();
    }
}

extern "C" void fn_800B07E0(FEOb107* self, int a, int b)
{
    if (self->m10) {
        if (a != 10 && a != 11) {
            fn_800C8044(self->m10->s32(lbl_805B9A04, 1))->s8(0);
            self->m20 = 0;
        }
        fn_800FC1F0(self->m10, a, b);
    }
}

extern "C" void fn_800B0884(UnkAt10P* p)
{
    if (p->m10) {
        fn_800FC6B4(p->m10);
    }
}

extern "C" void fn_800B1D90(FEOb110* self)
{
    for (int i = 0; i < 10; i++) {
        self->mAC[i] = 0;
    }
    self->m110 = 0;
    self->mD4 = 0;
}

extern "C" void fn_800B1DBC(FEOb1DBC* self, int lvl)
{
    int t[6] = {1000, 2500, 4000, 6000, 8000, 10000};
    for (int i = 0; i < 6; i++) {
        int v = 30 - lvl * 5;
        v -= i * 2;
        int w = 15;
        if (w < v) {
            w = v;
        }
        int o = i * 0xC;
        char* b24 = (char*)self + 0x24;
        char* b20 = (char*)self + 0x20;
        char* b28 = (char*)self + 0x28;
        *(int*)(b24 + o) = w;
        *(int*)(b20 + o) = t[i];
        *(int*)(b28 + o) = 0;
    }
    self->m60 = 0;
    self->m110 = 0;
    self->m70 = 0;
}

extern "C" void fn_800B1E84(FEOb7C* self)
{
    int t[12] = {0xBB8, 0x1388, 0x1D4C, 0x2710, 0x30D4, 0x3A98, 0x4E20, 0x7530, 0x9C40, 0xC350, 0x124F8, 0x186A0};
    for (int i = 0; i < 12; i++) {
        self->m7C[i] = t[i];
    }
}

extern "C" void fn_800B1F04(FEOb1F04* self)
{
    int t[12] = {100, 100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50};
    char* p = self->m4->m65C;
    if (p) {
        fn_80252DF4(p + 0x480, (float)t[self->m114] * lbl_805B9B70);
    }
}

extern "C" int fn_800B1FCC(FEOb210* self)
{
    int sum = 0;
    for (int i = 0; i < 12; i++) {
        sum += self->mE0[i];
    }
    if (fn_800B214C((FEOb214*)self) == 0) {
        sum += self->m110;
    }
    return sum;
}

extern "C" int fn_800B2034(char* p)
{
    int* q = (int*)(p + 0x24);
    return q[*(int*)(p + 0x70) * 3];
}

extern "C" int fn_800B2048(char* p)
{
    int* q = (int*)(p + 0x20);
    return q[*(int*)(p + 0x70) * 3];
}

extern "C" int fn_800B20E0(FEOb68* self)
{
    int r = 0;
    if (!(self->m68 > lbl_805B9B74)) {
        r = self->m78 == 0;
    }
    return r;
}

extern "C" int fn_800B210C(FEOb210* self)
{
    int r;
    if (self->mD8 == 1) {
        r = fn_800B20E0((FEOb68*)self);
    } else {
        r = self->mD4 == 10;
    }
    return r;
}

extern "C" int fn_800B214C(FEOb214* self)
{
    int r = 0;
    FEOb4p* o = (FEOb4p*)fn_800AEC78((char*)fn_800AB5C8(lbl_80619D10), (int)self->m4);
    if (o) {
        if (o->m4->m14 == 0) {
            if (self->m140 <= 0) {
                r = fn_800B210C((FEOb210*)self);
            }
        }
    }
    return r;
}

extern "C" int fn_800B21C0(FEOb210* self)
{
    int m = 0;
    for (int i = 0; i < 12; i++) {
        if (self->mE0[i] > m) {
            m = self->mE0[i];
        }
    }
    if (self->m110 > m) {
        m = self->m110;
    }
    return m;
}

extern "C" int fn_800B2204(FEOb210* self)
{
    if (self->mD8 == 1) {
        return self->m5C;
    }
    int v = self->m114;
    if (v > 11) {
        v = 11;
    }
    return self->m7C[v];
}

/* near-miss (4 slots): retail roots the compare tree at 2 and tests case 1 after case 0 (beqlr on the pre-set r3); enum-typed index did not move the root */
extern "C" int fn_800B2238(FEOb2390* self)
{
    int r = 0;
    switch (self->m114) {
    case 0:
        break;
    case 1:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    default:
        r = 4;
        break;
    }
    return r;
}

extern "C" void fn_800B228C(FEOb118* self)
{
    for (int i = 0; i < 5; i++) {
        self->m118[i] = 0;
    }
}

extern "C" void fn_800B22B0(FEStats* self, FEEv* e)
{
    if (e == 0) {
        return;
    }
    if (e->m18 != 0) {
        self->m120++;
    }
    if (e->m14 == 2) {
        self->m128++;
    }
    if (e->m14 == 1) {
        self->m124++;
    }
    int v = e->m0;
    self->m118 = self->m118 >? v;
    self->m11C += e->m0;
}

extern "C" void fn_800B2390(FEOb2390* self)
{
    fn_800B228C((FEOb118*)self);
    fn_800B1F04((FEOb1F04*)self);
    fn_800B1DBC((FEOb1DBC*)self, self->m114);
    fn_800B1E84((FEOb7C*)self);
    self->m74 = 0;
    self->m68 = lbl_805B9B78;
    fn_800AE96C((char*)fn_800AB5C8(lbl_80619D10));
    fn_800AEBAC((char*)fn_800AB5C8(lbl_80619D10));
    self->m114 = self->m114 + 1;
    fn_800B1D90((FEOb110*)self);
    fn_800A74C8(lbl_806192E0->m4->mC + 0xA0, self->m114 + 1);
}

extern "C" void fn_800B243C(void* p)
{
    fn_800B245C((FEOb245*)p);
}

/* near-miss (4 slots): retail loads m68 into f0 and the constant into f13 (compare operands swapped in ours); 5 operand forms tried */
extern "C" void fn_800B245C(FEOb245* self)
{
    if (fn_802D7DB4(fn_801A2034(self->m4, 4), 0x106)) {
        int did = 0;
        if (self->mD8 == 1) {
            if (!(self->m68 < lbl_805B9B7C)) {
                self->m68 = FMax2(self->m68 - lbl_805B9B7C, lbl_805B9B80);
                did = 1;
            }
        } else {
            int n = self->mD4;
            if (!(n > 9)) {
                self->mAC[n] = did;
                self->mD4 = n + 1;
                did = 1;
            }
        }
        if (did) {
            fn_800AEBAC((char*)fn_800AB5C8(lbl_80619D10));
            fn_800B2DD4(self, 5);
        }
    }
}

extern "C" void fn_800B2544(void* self)
{
    fn_800B2588((FEOb2588*)self);
    fn_800B2668((FEOb74*)self);
    fn_800B245C((FEOb245*)self);
    fn_800B26CC((FEOb26*)self);
}

extern "C" void fn_800B2588(FEOb2588* self)
{
    if (self->m70 <= 6) {
        int off = self->m70 * 0xC;
        char* b28 = (char*)self + 0x28;
        if (*(int*)(b28 + off) == 0) {
            int lvl = self->m110;
            char* b20 = (char*)self + 0x20;
            if (lvl >= *(int*)(b20 + off)) {
                char* b24 = (char*)self + 0x24;
                self->m68 = self->m68 + (float)*(int*)(b24 + off);
                *(int*)(b28 + off) = 1;
                if (self->m70 <= 4) {
                    self->m70 = self->m70 + 1;
                }
                if (fn_800B214C((FEOb214*)self) == 0) {
                    fn_800B2DD4(self, 1);
                }
            }
        }
        if (self->mDC) {
            fn_80120144(self->mDC, self->m68);
        }
    }
}

extern "C" void fn_800B2668(FEOb74* self)
{
    if (lbl_80620414 == 0) {
        if (self->m74 != 0) {
            self->m68 = FMax2(self->m68 - lbl_805B9B90, lbl_805B9B94);
        }
    }
}

extern "C" void fn_800B26CC(FEOb26* self)
{
    if (!(self->m68 < lbl_805B9B98)) {
        self->m6C = lbl_805B9B98;
    }
    if (!(self->m68 >= self->m6C)) {
        if (!(self->m6C <= lbl_805B9B9C)) {
            self->m6C = self->m6C - lbl_805B9BA0;
            fn_800412AC(fn_8004072C(), 0x32, 0, 0, 0, 0);
        } else {
            self->m6C = self->m6C - lbl_805B9BA4;
            fn_800412AC(fn_8004072C(), 0x31, 0, 0, 0, 0);
        }
    }
}
