/*
 * Game code, .text 0x80308874-0x8030C5D8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

extern char lbl_80665950[];
extern char lbl_80665A88[];
extern char lbl_80665470[];
extern char lbl_80665500[];
extern char lbl_80665D88[];
extern char lbl_806653F8[];
extern int lbl_806E0FA4[];

inline void SetD(char* p, int i, int v)
{
    int off = i * 4;
    *(int*)(p + off) = v;
}

struct Unk80308874_Ent50 {
    char pad0[0x50];
};
struct Unk80308874_Mgr {
    char pad0[0x100];
    Unk80308874_Ent50* m100;
    char pad104[4];
    int m108;
    int m10C;
};
struct Unk80308874_Slot3 {
    int* p;
    int n;
    int cap;
};
struct Unk80308874_Slots {
    Unk80308874_Slot3 s[1];
};
struct Unk80308874_At20C {
    char pad0[0x20C];
    char* m20C;
};
struct Unk80308874_At24 {
    char pad0[0x24];
    int m24;
};
struct Unk80308874_AtD0 {
    char pad0[0xD0];
    const void* mD0;
};
struct Unk80308874_At18 {
    char pad0[0x18];
    const void* m18;
    char pad1C[8];
    int m24;
};
struct Unk80308874_At4 {
    int m0;
    int m4;
};
struct Unk80308874_P8 {
    int a;
    int b;
};
struct Unk80308874_Pair {
    char pad0[0x28];
    int m28;
    int m2C;
};
struct Unk80308874_FSlot {
    float* m0;
    int m4;
    float m8;
};
struct Unk80308874_FSlots {
    char pad0[0x28];
    float m28;
    char pad2C[0x4C - 0x2C];
    Unk80308874_FSlot s[1];
    Unk80308874_FSlot m58;
};
struct Unk80308874_Hdr {
    short m0;
    short m2;
};
struct Unk80308874_List {
    int m0;
    int m4;
    Unk80308874_Hdr* m8[0x50];
};
struct Unk80308874_B8 {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
};
struct Unk80308874_At8 {
    int m0;
    int m4;
    const void* m8;
};
struct Unk80308874_At10 {
    char pad0[0x10];
    int m10;
};

extern "C" {
void* fn_80308678(void* e, int a, int b, int c, int d, int f);
void fn_80308414(void* e, int a, int b, int c, float f);
void* fn_803774A8(int size, int heap);
void fn_80308B5C(void* p);
void fn_80308E5C(void* p);
void fn_80377408(void* p);
void fn_80308FF0();
void fn_80328374(void* p, int c);
void fn_8030ACCC(Unk80308874_List* p);
void* fn_8026C75C(void* p, int a, int b);
void fn_8026C864(void* p, int c);
void fn_80319310(int a, void* p, int k);
void fn_803E6B3C(void* p);
void fn_803E6B74(void* p);
void fn_8030C11C(Unk80308874_At10* p);
void fn_803DD73C(int h, int k);
void fn_8037B424(void* p, int c);
void* fn_8030BEB8(void* p);
}

struct Unk80308C74_R {
    float m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
};
struct Unk80308C74_O {
    Unk80308C74_R r[6];
    char pad90[0x24];
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    int mCC;
    const void* mD0;
    Unk80308C74_O();
};
struct Unk80308874_Buf {
    int m0;
    int m4;
    void* m8;
    void* mC;
    int m10;
    int m14;
    int m18;
};
extern void (*lbl_8062C66C)(void*, int);
extern const float lbl_805E8898;
extern "C" void fn_803D79A0(int h, int k);
extern "C" void fn_80377488(void* p);
inline void Unk80308874_FreeArr(void* p, int sz)
{
    int n = *(int*)((char*)p - 8);
    lbl_8062C66C((char*)p - 8, n * sz | 8);
}

int fn_80308874(Unk80308874_Buf* p)
{
    if (p->m18 != 0) {
        fn_803D79A0(p->m18, 3);
        p->m18 = 0;
    }
    if (p->m4 != 0) {
        fn_80377488((void*)p->m4);
        p->m4 = 0;
    }
    if (p->m0 != 0) {
        fn_80377488((void*)p->m0);
        p->m0 = 0;
    }
    if (p->mC != 0) {
        Unk80308874_FreeArr(p->mC, 16);
        p->mC = 0;
    }
    if (p->m8 != 0) {
        Unk80308874_FreeArr(p->m8, 16);
        p->m8 = 0;
    }
    p->m14 = 0;
    p->m10 = 0;
    return 1;
}

int fn_80308960(Unk80308874_Mgr* m, int i, int a, int b, int c)
{
    fn_80308678(m->m100 + i, a, m->m108, m->m10C, b, c);
    return 1;
}

int fn_80308A7C(Unk80308874_Slots* m, int i, int n)
{
    m->s[i].cap = n;
    m->s[i].n = 0;
    m->s[i].p = (int*)fn_803774A8(n * 4, 0);
    return 1;
}

void fn_80308AD0(Unk80308874_Mgr* m, int a, int b, int c, int i, float f)
{
    fn_80308414(m->m100 + i, a, b, c, f);
}

void fn_80308B04(Unk80308874_Slots* m, int v, int i)
{
    int n = m->s[i].n;
    int q = (int)m->s[i].p;
    *(int*)(q + n * 4) = v;
    m->s[i].n = ++n;
}

/* near-miss: retail keeps this in r30 and the argument in r29 (callee-saved order swapped; pass-through of r4 tried) */
void fn_80308B28(Unk80308874_At4* m, int v)
{
    fn_80308B5C(m);
    *(int*)((char*)m + 0x10C) = v;
}

extern "C" void fn_80308C60(Unk80308874_At20C* p, int i, int v)
{
    SetD(p->m20C + 0xC0, i, v);
}

//@80308C74
//@80308C74
Unk80308C74_O::Unk80308C74_O()
{
    mD0 = lbl_80665950;
    Unk80308C74_R* q = r;
    for (int i = 0; i < 6; i++) {
        r[i].mC = lbl_805E8898;
        q->m8 = lbl_805E8898;
        q->m4 = lbl_805E8898;
        q->m0 = lbl_805E8898;
        q++;
    }
    int z = 0;
    mB4 = 4;
    mB8 = 2;
    mBC = 3;
    mC0 = 1;
    mC4 = z;
    mC8 = 5;
    mCC = 6;
}

void fn_80308CFC(Unk80308874_AtD0* p, int c)
{
    p->mD0 = lbl_80665950;
    if (c & 1)
        fn_80377408(p);
}

void fn_80308DD8(Unk80308874_At18* p, int c)
{
    p->m18 = lbl_80665A88;
    p->m24 = 0;
    fn_80308FF0();
    fn_80328374(p, c);
}

/* near-miss: same register order issue as fn_80308B28 */
void fn_80308E28(Unk80308874_At4* p, int v)
{
    fn_80308E5C(p);
    p->m4 = v;
}

void fn_80308FF0()
{
}

void fn_80309A74(Unk80308874_At24* p, int v)
{
    p->m24 = v;
}

int fn_80309A7C(Unk80308874_Pair* s, int** pp)
{
    int* d = *pp;
    *(Unk80308874_P8*)d = *(Unk80308874_P8*)&s->m28;
    *pp = d + 2;
    return 1;
}

void fn_80309AA0(Unk80308874_FSlots* p, int i)
{
    Unk80308874_FSlot* s = &p->s[i];
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = 0.0f;
}

void fn_80309AC8(Unk80308874_FSlots* p, int i, float* a, int b, float f)
{
    Unk80308874_FSlot* s = &p->s[i];
    s->m0 = a;
    s->m4 = b;
    s->m8 = f;
}

void fn_80309AF4(Unk80308874_FSlots* p, int i)
{
    int off = i * 0xC + 0x4C;
    *(Unk80308874_FSlot*)((char*)p + off) = p->m58;
}

void fn_80309B20(Unk80308874_FSlots* p, int i)
{
    int off = i * 0xC + 0x4C;
    float* q = *(float**)((char*)p + off);
    if (q)
        p->m28 = *q;
}

void* fn_8030AC4C(Unk80308874_List* p)
{
    p->m0 = 0;
    p->m4 = 0;
    fn_8030ACCC(p);
    return p;
}

extern "C" void fn_8030AC88(Unk80308874_List* p)
{
    for (int i = 0; i < p->m0; i++) {
        Unk80308874_Hdr* h = p->m8[i];
        if (h)
            h->m2 = 1;
    }
}

void fn_8030ACCC(Unk80308874_List* p)
{
    for (int i = 0; i < 0x50; i++) {
        p->m8[i] = 0;
        if (p->m4 != 0)
            lbl_806E0FA4[i] = 0x51;
    }
    p->m0 = 0;
}

void fn_8030AF34(void* pv, int k)
{
    Unk80308874_List* p = (Unk80308874_List*)pv;
    if (p->m4 != 0) {
        if (k != 0x51) {
            do {
                char* b = (char*)p + 8;
                int o = k * 4;
                Unk80308874_Hdr* h = *(Unk80308874_Hdr**)(b + o);
                if (h)
                    h->m2 = 1;
                k = lbl_806E0FA4[k];
            } while (k != 0x51);
        }
    } else {
        int o = k * 4;
        char* b = (char*)p + 8;
        Unk80308874_Hdr* h = *(Unk80308874_Hdr**)(b + o);
        if (h)
            h->m2 = 1;
    }
}

void fn_8030AF9C(void* pv, int k)
{
    Unk80308874_List* p = (Unk80308874_List*)pv;
    if (p->m4 != 0) {
        if (k != 0x51) {
            do {
                char* b = (char*)p + 8;
                int o = k * 4;
                Unk80308874_Hdr* h = *(Unk80308874_Hdr**)(b + o);
                if (h)
                    h->m2 = 0;
                k = lbl_806E0FA4[k];
            } while (k != 0x51);
        }
    } else {
        int o = k * 4;
        char* b = (char*)p + 8;
        Unk80308874_Hdr* h = *(Unk80308874_Hdr**)(b + o);
        if (h)
            h->m2 = 0;
    }
}

void* fn_8030B000(Unk80308874_B8* p, int a)
{
    fn_8026C75C(p, 7, a);
    p->mB8 = lbl_80665470;
    p->m98 = lbl_80665500;
    return p;
}

void fn_8030B050(Unk80308874_B8* p, int c)
{
    p->mB8 = lbl_80665470;
    p->m98 = lbl_80665500;
    fn_8026C864(p, c);
}

void fn_8030B088()
{
}

void* fn_8030B130(Unk80308874_At8* p, int a, int b)
{
    p->m8 = lbl_80665D88;
    fn_80319310(a, p, 0);
    p->m4 = b;
    p->m0 = 0;
    return p;
}

void fn_8030B5F4(void* p)
{
    fn_803E6B3C((char*)p + 0x94);
}

void fn_8030B618(void* p)
{
    fn_803E6B74((char*)p + 0x94);
}

extern "C" void fn_8030BFB0(Unk80308874_At4* p, int c)
{
    *(const void**)p = lbl_806653F8;
    fn_8030C11C((Unk80308874_At10*)p);
    fn_8037B424(p, c);
}

void fn_8030C11C(Unk80308874_At10* p)
{
    if (p->m10) {
        fn_803DD73C(p->m10, 3);
        p->m10 = 0;
    }
}

void* fn_8030C554()
{
    return fn_8030BEB8(operator new(0xA8, lbl_806EF9B4));
}
