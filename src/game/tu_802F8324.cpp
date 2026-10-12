/*
 * Game code, .text 0x802F8324-0x802FCAC0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

extern char lbl_80664FF0[];
extern Unk802F8324_VT18* lbl_80619D10;
extern float lbl_8061F874;
extern float lbl_8061F7D0;
extern char lbl_8068E0FC[];

struct Unk802F8324_M3B0 {
    char pad0[0x24];
    float m24;
};
struct Unk802F8324_Own700 {
    char pad0[0x3B0];
    Unk802F8324_M3B0* m3B0;
};
struct Unk802F8324_Own {
    char pad0[0x700];
    Unk802F8324_Own700* m700;
};
struct Unk802F8324_Obj {
    char pad0[0x64];
    Unk802F8324_Own* m64;
};
struct Unk802F8324_AA4 {
    char pad0[0xAA4];
    int mAA4;
};
struct Unk802F8324_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char pad14[0xC];
    int m20;
    char pad24[8];
    int m2C;
    int m30;
    int m34;
    int m38;
    char pad3C[4];
    int m40;
};
struct Unk802F8324_Own2 {
    char pad0[0x6F4];
    int m6F4;
    struct Unk802F8324_T6F8* m6F8;
    Unk802F8324_Own700* m700;
};
struct Unk802F8324_Slot10 {
    char pad0[0x6C];
    int m6C[2];
};
struct Unk802F8324_T14 {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk802F8324_T6F8 {
    char pad0[0x10];
    Unk802F8324_Slot10* m10;
    Unk802F8324_T14* m14;
};
struct Unk802F8324_O3 {
    char pad0[0x64];
    Unk802F8324_Own2* m64;
    char pad68[4];
    int m6C;
    char pad70[0xA0 - 0x70];
    int mA0;
    char pad94[0xAC - 0xA4];
    float mAC;
    int mB0;
};
struct Unk802F8324_P54 {
    char pad0[0x50];
    int m50;
    int m54;
};
extern int lbl_8061F830;
struct Unk802F8324_At0 {
    const void* m0;
};

extern "C" {
Unk802F8324_P54* fn_801A6DB8(void* o);
int fn_802D7DB4(int a, int b);
Unk802F8324_VT8* fn_801A4CE8(void* o, int k);
Unk802F8324_VT0* fn_800ABE80(void* mgr, void* o);
void* fn_800AB5C8(void* mgr);
Unk802F8324_AA4* fn_800AEC78(void* mgr, Unk802F8324_Own* o);
float fn_8033CDC4(void* self, float t);
void* fn_800AB528(void* mgr);
void fn_800AC264(void* mgr, Unk802F8324_Own* o, int k);
void fn_800AB9A8(void* mgr, int k);
float fn_802F9BB8(Unk802F8324_Obj* o);
void fn_802FA22C(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r);
float fn_802F9B60(Unk802F8324_Obj* o);
int fn_802F922C(Unk802F8324_Obj* o);
int fn_802F91CC(Unk802F8324_Obj* o);
int fn_802F92CC(Unk802F8324_Obj* o);
}

struct Unk801A96E0_Late;
void fn_801A9D48(Unk801A96E0_Late* p, int v);
struct Unk802FAA78_Own700 {
    char pad0[0x3BC];
    int m3BC;
    char pad3C0[4];
    Unk801A96E0_Late* m3C4;
};
struct Unk802FAA78_Own {
    char pad0[0x6F4];
    int m6F4;
    Unk802F8324_T6F8* m6F8;
    char pad6FC[4];
    Unk802FAA78_Own700* m700;
};
struct Unk802FAA78_Obj {
    char pad0[0x64];
    Unk802FAA78_Own* m64;
};
struct Unk802FAA78_E {
    char pad0[0xE64];
};
struct Unk802FAA78_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x10];
    int m20;
    char pad24[8];
    int m2C;
    int m30;
    int m34;
    char pad38[8];
    int m40;
};
extern "C" {
int fn_801BBF04(int k);
void fn_8017B6C0(void* o, int a, int b);
int fn_80099704(void* p);
}

float fn_802F8324(Unk802F8324_Obj* o)
{
    float r = 1.0f;
    Unk802F8324_AA4* y = fn_800AEC78(fn_800AB5C8(lbl_80619D10), o->m64);
    if (y && y->mAA4 > 5) {
        r = 1.0f - 5.0f / (float)y->mAA4;
        r = r * lbl_8061F874;
        r = 1.0f - r;
    }
    return r;
}

float fn_802F9140()
{
    float r = fn_8033CDC4(lbl_8068E0FC, 1.0f) * lbl_8061F7D0;
    return r;
}

int fn_802F9184(Unk802F8324_Obj* o)
{
    if (fn_802F922C(o) != 0)
        return 0;
    return fn_802F91CC(o) == 0;
}

int fn_802F91CC(Unk802F8324_Obj* o)
{
    return fn_802F922C(o) == 0 ? o->m64->m700->m3B0->m24 > 0.0f : 0;
}

int fn_802F922C(Unk802F8324_Obj* o)
{
    float a = o->m64->m700->m3B0->m24;
    return __builtin_fabs(a) > fn_802F9140() ? 0 : fn_802F9B60(o) > 0.0f;
}

extern "C" int fn_802F92A4(Unk802F8324_Obj* o)
{
    return fn_802F92CC(o) == 0;
}

/* near-miss: retail evaluates fabs(a) first and keeps it in f31 across the call; ours calls fn_8033CDC4 first (8 variants: separate float local, a = fabs(a), negated compare, int result) */
int fn_802F92CC(Unk802F8324_Obj* o)
{
    float a = o->m64->m700->m3B0->m24;
    return __builtin_fabs(a) <= fn_8033CDC4(lbl_8068E0FC, 1.0f);
}

float fn_802F9B60(Unk802F8324_Obj* o)
{
    float r = fn_802F9BB8(o) * lbl_8061F7D0;
    if (!(r >= 0.01f))
        r = 0.0f;
    return r;
}

inline int AtD(int* p, int i)
{
    int off = i * 4;
    return *(int*)((char*)p + off);
}

/* near-miss: same 7 stores, scheduled in a different order than retail (40 random permutations of the statement order tried) */
void fn_802FA9E4(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r)
{
    if (fn_801A6DB8(o->m64)->m54 != 0 && fn_802D7DB4(a, 0xAA) != 0) {
        r->mC = 0xA2;
        r->m2C = 1;
        r->m8 = 0x67;
        r->m4 = r->m40;
        o->mB0 = 0;
        o->mAC = 0.0f;
        o->m6C = 2;
    }
}

void fn_802FAA78(Unk802FAA78_Obj* o, int key, Unk802FAA78_Rec* r)
{
    r->m34 = 0;
    if (o->m64->m6F4 == 0) {
        if (fn_802D7DB4(key, 0xAC) != 0) {
            if (fn_801BBF04(o->m64->m700->m3BC) == 0)
                fn_8017B6C0(o->m64->m700, 0, 1);
        } else if (fn_802D7DB4(key, 0xAD) != 0) {
            if (fn_801A6DB8(o->m64)->m50 != 0) {
                Unk802F8324_T14* t = o->m64->m6F8->m14;
                int k = t->m1CD0 == 0;
                if (fn_80099704((Unk802FAA78_E*)t + k) != 0) {
                    r->m4 = r->m40;
                    r->m8 = 0x67;
                    r->mC = 0xA2;
                    r->m30 = 1;
                }
            }
        } else if (fn_802D7DB4(key, 0x75) != 0 && r->m20 == 0 && r->m2C == 0) {
            r->m34 = 1;
        }
    }
    fn_801A9D48(o->m64->m700->m3C4, r->m34);
}

struct Unk802FABC4_I {
    char pad0[0x14];
    int m14;
};
struct Unk802FABC4_Y {
    char pad0[4];
    Unk802FABC4_I* m4;
};
extern "C" {
int fn_800AC398();
int fn_800AEC80();
int fn_800B214C();
int fn_800B210C(int a);
void fn_802F99D8(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r);
void fn_802FA80C(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r);
}
void fn_802FA9E4(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r);
void fn_802FAA78(Unk802FAA78_Obj* o, int key, Unk802FAA78_Rec* r);

void fn_802FABC4(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r)
{
    if (lbl_80619D10->s17() != 0) {
        fn_800AB528(lbl_80619D10);
        if (fn_800AC398() != 0)
            return;
    }
    if (o->m64 != 0 && o->m64->m6F4 == 8) {
        Unk802FABC4_Y* y = (Unk802FABC4_Y*)fn_800AEC78(fn_800AB5C8(lbl_80619D10), (Unk802F8324_Own*)o->m64);
        if (y == 0 || y->m4->m14 != 0)
            return;
        fn_800AB5C8(lbl_80619D10);
        int u = fn_800AEC80();
        if (fn_800B214C() != 0)
            return;
        if (fn_800B210C(u) != 0)
            return;
    }
    if (r->m0 == 0 && r->m10 == 0) {
        fn_802FA80C(o, a, r);
        if (r->m20 == 0) {
            fn_802FA9E4(o, a, r);
            if (r->m2C == 0)
                fn_802FAA78((Unk802FAA78_Obj*)o, a, (Unk802FAA78_Rec*)r);
        }
    }
    if (r->m20 == 0 && r->m2C == 0 && r->m34 == 0 && r->m0 == 0) {
        fn_802F99D8(o, a, r);
    } else if (r->m10 == 0) {
        fn_802FA22C(o, a, r);
    }
}

void fn_802FAD5C(Unk802F8324_O3* o, int a, Unk802F8324_Rec* r)
{
    if (r->m38 == 0)
        fn_802FA22C(o, a, r);
}

void fn_802FAD88(Unk802F8324_O3* o)
{
    Unk802F8324_VT0* h = fn_800ABE80(lbl_80619D10, o->m64);
    if (h) {
        int v = 1;
        if (o->mA0 == 0 || fn_801A4CE8(o->m64, 1)->s9() == 0
            || AtD(o->m64->m6F8->m10->m6C, o->m64->m6F8->m14->m1CD0 == 0) == -1 || lbl_8061F830 == 0)
            v = 0;
        h->s3(v);
    }
}

void fn_802FAE64(Unk802F8324_Obj* o)
{
    Unk802F8324_VT18* m = lbl_80619D10;
    if (m) {
        if (m->s17()) {
            fn_800AC264(fn_800AB528(m), o->m64, 1);
        }
    }
}

void fn_802FAED0()
{
    fn_800AB9A8(lbl_80619D10, 2);
}

extern "C" void* fn_802FBC38(void* q)
{
    Unk802F8324_At0* p = (Unk802F8324_At0*)q;
    new (p) Unk8037B3E8(0x71B43039u);
    p->m0 = lbl_80664FF0;
    return p;
}
