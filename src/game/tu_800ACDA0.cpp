/*
 * Game code, .text 0x800ACDA0-0x800AF248 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAt1C {
    char pad0[0x1C];
    void* m1C;
};
struct UnkAt20F {
    char pad0[0x20];
    float m20;
};
struct UnkAtAA4 {
    char pad0[0xAA4];
    int mAA4;
};
struct UnkAtEF0 {
    char pad0[0xEF0];
    int mEF0;
};
struct UnkFEPair {
    int m0;
    int m4;
};
extern const float lbl_805B95B8;


class FEO8B {
public:
    char pad0[8];
    virtual void s1();
    virtual void s2();
    virtual int s3();
    virtual void s4();
    virtual int s5();
    virtual int s6();
};
extern const float lbl_805B95A4;
extern const float lbl_805B96A0;
extern const float lbl_805B96A4;
extern const char lbl_8065B360[];
extern const char lbl_8065B268[];
extern const char lbl_8065B690[];
struct UnkAt1C20 {
    char pad0[0x1C];
    void* m1C;
    float m20;
};
struct FEOb12 {
    int m0;
    int m4;
    const void* m8;
};
struct FE190 {
    char pad0[0x190];
    int m190;
};
struct FE6F8 {
    char pad0[0x10];
    FE190* m10;
};
struct FE6F8H {
    char pad0[0x6F8];
    FE6F8* m6F8;
};
extern "C" {
FEO8B* fn_800AB80C(void* t, int i, int j);
int fn_800AE150(char* self, int* oi, int* oj, int key);
void fn_800AE3FC(char* self);
void fn_800AD58C(char* self, int i, int j);
void fn_800AD6FC(char* self);
void fn_800AD1D4(char* self);
void fn_800AB3F8(void* self);
int fn_800ABC30(void* t, int i);
void fn_8033E5C4(void* o, int a);
void fn_800ADE10(void* p);
void fn_800AD78C(void* p);
void fn_8033E4F0(void* p);
void fn_800AE574(void* p);
void* fn_800AF010(void* p, int k);
void fn_800ADCD8(void* p);
void fn_800ABC9C(void* p);
void fn_800AE944(void* p);
void* fn_800AEDDC(void* p);
int fn_80356C98(void* p);
void fn_8033E600(void* p, int c);
void fn_80377408(void* p);
}

/* ---- generated externs ---- */






/* ---- unit prototypes ---- */
extern "C" {
void fn_800ACDA0();
void fn_800ACDA4(UnkAt1C20* self);
void fn_800ACF24(UnkAt1C* p);
void fn_800ACF48(UnkAt20F* p);
void fn_800ACFE8();
void fn_800AD17C(char* self, int c);
void fn_800AD6FC(char* self);
void fn_800AD774(UnkAtAA4* p);
void fn_800AD948(char* self, int key, float v);
void fn_800ADAD8(char* self);
UnkFEPair fn_800ADB34(char* base, int a, int b);
void fn_800ADE10(void* p);
int fn_800ADE80(char* self, int a, int b);
void fn_800ADED0(char* self, int a, int b);
int fn_800ADF28(char* self, int a, int b);
float fn_800ADF6C(char* self, int a, int b);
int fn_800AE150(char* self, int* oi, int* oj, int key);
void fn_800AE2E4(void* p);
void fn_800AE4F4(char* self);
void fn_800AE944(void* p);
void fn_800AE964(UnkAtEF0* p, int v);
int fn_800AEA04(char* self, int k);
void fn_800AEA64();
void fn_800AEB88(char* p);
void fn_800AEBAC(char* p);
void fn_800AEBD0(char* self);
void fn_800AEC04(char* self);
void fn_800AEC74();
char* fn_800AEC78(char* p);
void* fn_800AEC80(void* self);
void* fn_800AEDDC(void* self);
int fn_800AEE44(void* self);
FEOb12* fn_800AEFF4(FEOb12* self, int a, int b);
void* fn_800AF010(void* p, int k);
FEO8B* fn_800AF020(FEO8B* self);
FEO8B* fn_800AF070(FEO8B* self);
FEO8B* fn_800AF0C0(FEO8B* self);
int fn_800AF110();
void* fn_800AF118(void* p, int k);
}
/* ---- end prototypes ---- */

/* ---- functions ---- */
extern "C" void fn_800ACDA0()
{
}

extern "C" void fn_800ACDA4(UnkAt1C20* self)
{
    fn_800ADCD8(self->m1C);
    self->m20 = lbl_805B95A4;
}

extern "C" void fn_800ACF24(UnkAt1C* p)
{
    fn_800ADE10(p->m1C);
}

extern "C" void fn_800ACF48(UnkAt20F* p)
{
    p->m20 = lbl_805B95B8;
}

extern "C" void fn_800ACFE8()
{
}

extern "C" void fn_800AD17C(char* self, int c)
{
    *(const void**)(self + 0xC) = lbl_8065B268;
    fn_8033E600(self, c);
    *(const void**)(self + 0xC) = lbl_8065B690;
    if (c & 1) {
        fn_80377408(self);
    }
}

/* near-miss (retail reloads the count before the inner loop pre-test and keeps self in r31; ours reuses r0 and swaps r30/r31): 4 loop forms tried */
extern "C" void fn_800AD6FC(char* self)
{
    for (int i = 0; i < *(int*)(self + 0xAA4); i++) {
        for (int j = 0; j < *(int*)(self + 0xAA4); j++) {
            fn_800AD58C(self, i, j);
        }
    }
}

extern "C" void fn_800AD774(UnkAtAA4* p)
{
    if (p->mAA4 <= 7) {
        p->mAA4 = p->mAA4 + 1;
    }
}

/* near-miss: same nested-loop allocation difference as fn_800AD6FC */
extern "C" void fn_800AD948(char* self, int key, float v)
{
    for (int i = 0; i < *(int*)(self + 0xAA4); i++) {
        for (int j = *(int*)(self + 0xAA4) - 1; j >= 0; j--) {
            char* b1 = self + 0x14;
            int off = j * 0xC + i * 0x60;
            if (*(int*)(b1 + off) == key) {
                char* b2 = self + 0x1C;
                *(float*)(b2 + off) = v;
            }
        }
    }
}

/* near-miss: same nested-loop allocation difference as fn_800AD6FC (retail has one extra count reload) */
extern "C" void fn_800ADAD8(char* self)
{
    for (int i = 0; i < *(int*)(self + 0xAA4); i++) {
        for (int j = *(int*)(self + 0xAA4) - 1; j >= 0; j--) {
            char* e = self + i * 0xE0 + j * 0x1C;
            *(UnkFEPair*)(e + 0x328) = *(UnkFEPair*)(e + 0x318);
        }
    }
}

extern "C" UnkFEPair fn_800ADB34(char* base, int a, int b)
{
    return *(UnkFEPair*)(base + a * 0xe0 + b * 0x1c + 0x328);
}

extern "C" void fn_800ADE10(void* p)
{
    char* self = (char*)p;
    int i;
    int j;
    while (fn_800AE150(self, &i, &j, 3)) {
        int o1 = i * 0x60 + 0x14;
        int o2 = j * 0xC;
        *(int*)(self + o1 + o2) = 0;
    }
    fn_800AD6FC(self);
}

/* near-miss (6 slots): retail keeps i in r3 (the return register) and recomputes the row base each iteration */
extern "C" int fn_800ADE80(char* self, int a, int b)
{
    int i = b;
    if (i >= 0 && i <= *(int*)(self + 0xAA4)) {
        for (; i >= 0; i--) {
            char* base = self + 0x14;
            int off = i * 0xC + a * 0x60;
            if (*(int*)(base + off) == 0) {
                return i;
            }
        }
    }
    return -1;
}

extern "C" void fn_800ADED0(char* self, int a, int b)
{
    for (int i = b; i >= 0 && i <= *(int*)(self + 0xAA4); i--) {
        char* p14 = self + 0x14;
        char* p1C = self + 0x1C;
        int off = i * 0xC + a * 0x60;
        *(int*)(p14 + off) = 2;
        *(float*)(p1C + off) = lbl_805B96A0;
    }
}

extern "C" int fn_800ADF28(char* self, int a, int b)
{
    int n = *(int*)(self + 0xAA4);
    int r = -1;
    if (a < n && b < n && a >= 0 && b >= 0) {
        char* base = self + 0x18;
        int off = b * 0xC + a * 0x60;
        r = *(int*)(base + off);
    }
    return r;
}

extern "C" float fn_800ADF6C(char* self, int a, int b)
{
    float r = lbl_805B96A4;
    int n = *(int*)(self + 0xAA4);
    if (a < n && b < n && a >= 0 && b >= 0) {
        char* base = self + 0x1C;
        int off = b * 0xC + a * 0x60;
        r = *(float*)(base + off);
    }
    return r;
}

/* near-miss: same nested-loop allocation difference as fn_800AD6FC (i and i*0x60 swap registers) */
extern "C" int fn_800AE150(char* self, int* oi, int* oj, int key)
{
    for (int i = 0; i < *(int*)(self + 0xAA4); i++) {
        for (int j = *(int*)(self + 0xAA4) - 1; j >= 0; j--) {
            char* b1 = self + 0x14;
            int off = j * 0xC + i * 0x60;
            if (*(int*)(b1 + off) == key) {
                *oi = i;
                *oj = j;
                return 1;
            }
        }
    }
    return 0;
}

extern "C" void fn_800AE2E4(void* p)
{
    fn_800AD78C(p);
}

extern "C" void fn_800AE4F4(char* self)
{
    fn_800AE3FC(self);
    for (int i = 0; i < *(int*)(self + 0xAA4); i++) {
        for (int j = *(int*)(self + 0xAA4) - 1; j >= 0; j--) {
            char* b1 = self + 0x14;
            int off = j * 0xC + i * 0x60;
            *(int*)(b1 + off) = 0;
        }
    }
}

extern "C" void fn_800AE944(void* p)
{
    fn_8033E4F0(p);
}

extern "C" void fn_800AE964(UnkAtEF0* p, int v)
{
    p->mEF0 = v;
}

/* near-miss (7 slots): second branch keeps temporaries in r0 / result in r3 in retail */
extern "C" int fn_800AEA04(char* self, int k)
{
    int* p = (int*)(self + 0xED0);
    if (k == 1) {
        int a = *(int*)(self + 0xED0);
        int b = p[3];
        int r = a * b;
        if (p[6] != 0) {
            if (a != 0) {
                r += b / 2;
            }
        }
        return r;
    }
    int a = *(int*)(self + 0xED0);
    int b = p[3];
    return a * a * b / 2;
}

extern "C" void fn_800AEA64()
{
}

extern "C" void fn_800AEB88(char* p)
{
    fn_800AE574(p + 0x448);
}

extern "C" void fn_800AEBAC(char* p)
{
    fn_800AE2E4(p + 0x448);
}

extern "C" void fn_800AEBD0(char* self)
{
    fn_800ABC9C(self);
    fn_800AE944(self + 0x448);
}

extern "C" void fn_800AEC04(char* self)
{
    FE6F8H* o = (FE6F8H*)fn_800ABC30(self, 0);
    int v = o->m6F8->m10->m190;
    v = v > 8 ? 8 : (v >? 4);
    char* p = self + 0x448;
    *(int*)(p + 0xAA4) = v;
    fn_800AB3F8(self);
    fn_800AD1D4(p);
}

extern "C" void fn_800AEC74()
{
}

extern "C" char* fn_800AEC78(char* p)
{
    return p + 0x448;
}

extern "C" void* fn_800AEC80(void* self)
{
    FEO8B* o = fn_800AB80C(self, 0, 0);
    if (o) {
        if (o->s5()) {
            return fn_800AF070(o);
        }
    }
    return 0;
}

extern "C" void* fn_800AEDDC(void* self)
{
    FEO8B* o = fn_800AB80C(self, 0, 0);
    if (o) {
        if (o->s6()) {
            return fn_800AF0C0(o);
        }
    }
    return 0;
}

extern "C" int fn_800AEE44(void* self)
{
    void* o = fn_800AEDDC(self);
    int r;
    if (o == 0) {
        r = 1;
    } else {
        r = fn_80356C98((char*)o + 0x60);
    }
    return r;
}

extern "C" FEOb12* fn_800AEFF4(FEOb12* self, int a, int b)
{
    self->m0 = a;
    self->m8 = lbl_8065B360;
    self->m4 = b;
    return self;
}

extern "C" void* fn_800AF010(void* p, int k)
{
    if (k == 0) {
        return p;
    }
    return 0;
}

extern "C" FEO8B* fn_800AF020(FEO8B* self)
{
    if (self->s3() != 0) {
        return self;
    }
    return 0;
}

extern "C" FEO8B* fn_800AF070(FEO8B* self)
{
    if (self->s5() != 0) {
        return self;
    }
    return 0;
}

extern "C" FEO8B* fn_800AF0C0(FEO8B* self)
{
    if (self->s6() != 0) {
        return self;
    }
    return 0;
}

extern "C" int fn_800AF110()
{
    return 1;
}

extern "C" void* fn_800AF118(void* p, int k)
{
    if (k == 2) {
        return (char*)p + 0xC;
    }
    return fn_800AF010(p, k);
}
