/*
 * Game code, .text 0x8025877C-0x8025B59C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"
#include "game/goals/tu_8027C728.h"
#include "game/goals/tu_8027A84C.h"
#include "game/goals/tu_80287600.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

/* Request record of fn_8025AC0C: +0xC sel, +0x28 target position, +0x34 state. */
struct Unk8025AC0C_E {
    char pad0[0xC];
    int mC;
    char pad10[0x28 - 0x10];
    Unk80273498_Vec3 m28;
    int m34;
};
inline Unk80273498_Vec3 Unk8025AC0C_Pos34(Unk8027C728_Goal* g)
{
    return *(Unk80273498_Vec3*)((char*)g + 0x34);
}
inline Unk80273498_Vec3 Unk8025AC0C_Pos28(Unk8025AC0C_E* e)
{
    return e->m28;
}

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

extern "C++" {
Q* fn_802570D4(M* self);
P* fn_80257B40(M* self);
P* fn_80257BD0(M* self, P* p, int a);
int fn_80254A34(A* a);
int fn_80254B60(A* a);
int fn_80254984(A* a);
void fn_8026BAB8(I* i);
void fn_8025D054(I* i, int a);
void fn_802684B0(void* p);
void fn_8026B9D8(I* i);
void fn_80259E3C(void* p);
void fn_8025596C(A* a, int v);
void fn_80266464(void* p, int a);
void fn_8026A0F4(void* p, int a);
void fn_80268684(void* p, int a);
void fn_802686E4(void* p, int a);
float fn_80259EE8(void* p, int a, int b, int c);
void fn_80268DB0(void* p);
void fn_80265D24(I* i, int a);
void fn_80377408(void* p);
}

struct Unk80259E3C_F {
    float a[4];
    float b[4][4];
};
extern "C" Unk8027C728_Goal* fn_802448F4(void* p, int k);
void fn_8027C728(Unk8027C728_Goal* g);
struct Unk8025A1A0_O {
    char pad0[0x50];
    Q* m50;
};
void fn_8025A1A0(Unk8025A1A0_O* o, float v);
void fn_8025A3DC(Unk8025A1A0_O* o, float v);
extern float lbl_805DADBC;
extern float lbl_805DADC0;
extern float lbl_805DAD00;
extern float lbl_805DACFC;
extern float lbl_805DADD4;
extern float lbl_805DACF8;
extern float lbl_805DADC4;
extern float lbl_805DADD0;

extern "C++" {
float fn_8025A780(float* self, int b);
float fn_80259FFC(void* p, int idx);
float fn_80259FB8(void* p, P* idx, int c);
int fn_8025D9E0(I* i);
int fn_8025A664(void* self, P* p);
void fn_801DC8E8(int a);
}
extern int lbl_8061B9C8;
extern const Unk80273498_Vec3 lbl_8068CE14;
extern const Unk80273498_Vec3 lbl_8068CDD8;
extern const Unk80273498_Vec3 lbl_8068CDC0;
extern const Unk80273498_Vec3 lbl_8068CDF0;
extern const Unk80273498_Vec3 lbl_8068CDCC;
extern const Unk80273498_Vec3 lbl_8068CDB4;
extern float lbl_805DACC0;
char* fn_8035E8CC(char* p, unsigned i);

inline P* Roster(Q* q, unsigned i) { if (i <= 0xC) return q->m65C[i]; return 0; }

int fn_801BBF24(int a);
int fn_8035E318(A* a);
void fn_80255314(A* a, int b, int c);
void fn_80266420(void* l, P* p);
void fn_8026647C(void* l);
int fn_8014E310(int a);
int fn_801C1950(int a);
int fn_8014E2B4(int a);
P* fn_8026B8C0(I* i, unsigned k);
void fn_8025888C(M* self, P* p, int a, int b);
void fn_8025D054(I* i, int a);
void* fn_8035E604(void* p);
int fn_8035E630(void* p, int a);
int fn_80254984(A* a);
int fn_80254EA4(A* a, int b);
int fn_802576E4(M* self, P* p, int k);
void fn_802574DC(M* self, P* p, int k);
Unk8027C728_Goal* fn_80244C84(Unk80270BA0_X* x);
int fn_8027D390(Unk8027C728_Goal* g, float* a, Unk80273498_Vec3* b, Unk80273498_Vec3* c, float* d);
float fn_80266D70(void* o, int k);
extern float lbl_805DACB8;
extern float lbl_805DACBC;
struct Unk8025877C_Ctx {
    char pad0[0x3C0];
    struct Unk8025877C_Sub* m3C0;
};
struct Unk8025877C_Sub {
    char pad0[0x14];
    int m14;
};
extern char lbl_805DAC40[];
int fn_801A2034(Q* q, int k);
struct Unk80259FFC_F4 {
    float v[4];
};
extern Unk80259FFC_F4 lbl_805DAD04;
extern float lbl_805DBAC8[];
extern float lbl_805DBA88[][4];
extern char lbl_805DAD14[];
extern const float lbl_805DAD44;
extern const float lbl_805DAD50;
extern float lbl_805DAD54;
extern float lbl_805DAD58;
extern float lbl_805DAD5C;
float fn_8025454C(Unk8024EF40_W* w, int k);
float fn_80254618(Unk8024EF40_W* w, int k);
P* fn_801C1638(Q* q, int k);
inline float RandK_9FFC(Q* q, const char* f, int line)
{
    float k = lbl_805DAD44;
    return (float)fn_8014D8AC(q->m554, 1000000, f, line) * k * lbl_805DAD50;
}

struct Unk80258BA8_E {
    char pad0[8];
    int m8;
};
struct Unk8025933C_E {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    int m20;
    int m24;
    Unk80273498_Vec3 m28;
    int m34;
};

inline float NegOne() { return -1.0f; }

/* near-miss: 66 vs 68 instructions; retail lays out the c == 0 call first and shares its `addi r3,r3,0x1CC; bl` tail with the rnd > 25 arm, with p in r29 and the result in r28. Tried early return, if/else swaps */
int fn_8025877C(M* self, P* p, int c)
{
    int r = 0;
    if (c == 0) {
        fn_8035E604((char*)self->m4 + 0x1CC);
    } else {
        int rnd = fn_8014D8AC(fn_802570D4(self)->m554, 100, lbl_805DAC40, 0x44D);
        if (fn_801A2034(fn_802570D4(self), 3) == -1) {
            if (rnd > 1) {
                fn_8035E604((char*)self->m4 + 0x1CC);
                ((Unk8025877C_Ctx*)self->m10)->m3C0->m14 = r;
            } else {
                r = 1;
            }
        } else if (rnd > 0x19) {
            fn_8035E604((char*)self->m4 + 0x1CC);
        } else {
            r = 1;
            int n = p->m458 + 1;
            if (n <= 12) {
                if (Roster(fn_802570D4(self), n) != 0)
                    fn_8035E604((char*)self->m4 + 0x1CC);
            }
        }
    }
    return r;
}

void fn_80258BA8(M* self, Unk80258BA8_E* e)
{
    if (fn_801C1950(((Unk8024EF40_Ctx*)self->m10)->m3BC) == 1) {
        self->m4->m420 = e->m8;
        int h = fn_8014E2B4(self->m4->m420);
        P* p = fn_8026B8C0(self->m4, h);
        if (p == 0 || self->m4->m194 > 1) {
            if (p != 0)
                fn_8025888C(self, p, 1, 0);
            fn_8025D054(self->m4, 3);
            fn_8035E604((char*)self->m4 + 0x1CC);
        } else {
            int r = fn_8035E630((char*)self->m4 + 0x1CC, (int)p);
            fn_8025888C(self, p, 0, r > fn_8035E318(&p->m58C));
            self->m4->m434 = p;
        }
    }
}

int fn_80258C90(M* self)
{
    int r;
    if (*((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 3) {
        r = 0;
    } else {
        int f = 0;
        P* p = fn_80257B40(self);
        while (p != 0) {
            if (fn_80254A34(&p->m58C) != 0) {
                f = 1;
                break;
            }
            p = fn_80257BD0(self, p, 0);
        }
        r = f;
    }
    return r;
}

int fn_80258D18(M* self)
{
    int r;
    if (*((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 3) {
        r = 0;
    } else {
        int f = 0;
        P* p = fn_80257B40(self);
        while (p != 0) {
            if (fn_80254B60(&p->m58C) != 0) {
                f = 1;
                break;
            }
            p = fn_80257BD0(self, p, 0);
        }
        r = f;
    }
    return r;
}

int fn_80258DA0(M* self)
{
    int r;
    if (*((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 3) {
        r = 0;
    } else {
        int f = 0;
        P* p = fn_80257B40(self);
        while (p != 0) {
            if (fn_80254984(&p->m58C) != 0) {
                f = 1;
                break;
            }
            p = fn_80257BD0(self, p, 0);
        }
        r = f;
    }
    return r;
}

int fn_80258E28(M* self)
{
    return self->m4->m1FC == 3;
}

void fn_80258E40(M* self)
{
    fn_8026BAB8(self->m4);
}

void fn_80258E64()
{
}

void fn_80258E68(M* self, int a)
{
    self->m18 = a;
}

void fn_80258E70(M* self)
{
    fn_8025D054(self->m4, 6);
}

void fn_80258E98(M* self)
{
    self->m14 = 0;
    self->m18 = 0;
}

void fn_802590E0(M* self)
{
    P* p = fn_802570D4(self)->m65C[10];
    if (p != 0) {
        A* a = &p->m58C;
        if (fn_80254984(a) != 0) {
            int k = 1;
            if (fn_80254EA4(a, 0) == 1)
                k = 4;
            if (fn_802576E4(self, p, k) != 0) {
                float f8 = lbl_805DACB8;
                fn_8027D390(fn_80244C84((Unk80270BA0_X*)p), &f8, 0, 0, 0);
                float fc = fn_80266D70((char*)self->m4 + 0x48, 1);
                if (!(f8 + lbl_805DACBC <= fc))
                    fn_802574DC(self, p, k);
            }
        }
    }
}

void fn_802591CC()
{
}

void fn_802591D0(M* self)
{
    if (self->m4->m1FC != 8)
        fn_8025D054(self->m4, 9);
    for (int i = 12; i > 8; i--) {
        P* p = Roster(fn_802570D4(self), i);
        if (p != 0) {
            if (fn_801BBF24(((Unk8024EF40_Ctx*)self->m10)->m3BC) == 5) {
                A* a = &p->m58C;
                fn_80255314(a, fn_8035E318(a), 0);
            }
            int t = p->m58C.m38;
            if (t > fn_8014E310(p->m458) + 1)
                fn_80266420((char*)self->m4 + 4, p);
        }
    }
    fn_8026647C((char*)self->m4 + 4);
}

void fn_802592B4(M* self)
{
    if (self->m4->m1FC != 8)
        fn_8025D054(self->m4, 9);
}

void fn_802592E8(M* self)
{
    fn_802684B0((char*)self->m4 + 0x124);
    fn_8026B9D8(self->m4);
    fn_80259E3C((char*)self->m4 + 0x468);
}

int fn_80259330(M* self)
{
    return self->m4->m128;
}

void fn_8025933C(char* self, int a)
{
    *(int*)self = a;
    for (int i = 9; i <= 12; i++) {
        Unk8025933C_E* e = (Unk8025933C_E*)fn_8035E8CC(self, i);
        e->m8 = 4;
        e->mC = -1;
        e->m4 = 0;
        e->m14 = 0;
        e->m18 = NegOne();
        e->m20 = 6;
        e->m1C = NegOne();
        e->m24 = 0;
        e->m28 = lbl_806055AC;
        e->m10 = 0;
        e->m0 = 0;
        e->m34 = 0;
    }
}

void fn_802593EC(M* self, int b, int c)
{
    fn_8025D9E0(self->m4);
    if (c != 0)
        fn_801DC8E8(((Unk8024EF40_Ctx*)self->m10)->m3B8);
}

int fn_80259434(M* self)
{
    return self->m4->m1FC;
}

/* near-miss: 75 vs 75 insns, 3 differ: retail loads the +0x6CC player into r3 (lwz r3,0x6cc(r3)), ours uses r9. Tried a Q* temporary, split ifs, a constant temporary */
extern const char lbl_805DACC4[];
extern float lbl_8061E4D4;
extern int fn_801DC67C(int a);
extern int fn_8018B648();
extern int fn_8024D41C(int x);
extern float fn_80259A74(M* self, int a, int b);
extern float fn_80266D70(void* t, int k);
extern int fn_802679D4(void* t, int a, int b);
extern void fn_80303CA0(const char* fmt, float a, float b, float c, ...);
extern void* fn_801A4B34(void* w);
int fn_80259440(M* self)
{
    int r = 0;
    if (fn_801DC67C(((Unk8024EF40_Ctx*)self->m10)->m3B8) != 0) {
        P* c = (P*)fn_801A4B34(fn_802570D4(self));
        if (c != 0 && c->m58C.m38 == -1) {
            P* t = fn_802570D4(self)->m6CC;
            if (t != 0 && t->m38C == 1 && fn_8018B648() == 0) {
                int o = fn_802679D4((char*)self->m4 + 0x48, 0, 0);
                if (o != 0 && fn_8024D41C(o) != 0) {
                    float a = fn_80259A74(self, 9, 0);
                    float b = fn_80266D70((char*)self->m4 + 0x48, 0);
                    if (!(a + lbl_8061E4D4 <= b)) {
                        r = 1;
                        fn_80303CA0(lbl_805DACC4, 8.0f, 0.4f, 0.05f);
                    }
                }
            }
        }
    }
    return r;
}

void fn_8025956C(M* self, P* p)
{
    if (p->m458 == 9 && p->m618->m838 != 0x1463E9BA)
        fn_8025596C(&p->m58C, 0);
}

void fn_802595B8(M* self, int a)
{
    fn_80266464((char*)self->m4 + 4, a);
}

void fn_80259918(void* self, P* p, int* out, int* idx)
{
    int t = p->m58C.m38;
    *out = t;
    if (t == -1) {
        *out = 3;
        *idx = 0;
    } else {
        *idx = t + 1;
    }
    if (*idx > 2)
        *idx = 3;
}

extern Unk80273498_Vec3 fn_8014E388(int idx);
extern float fn_804028E4(float x);
extern "C" int fn_8025995C(M* self, unsigned t, float* out, int* a, int* b)
{
    P* p = fn_8026B8C0(self->m4, t);
    if (p == 0 || p->m58C.b2) {
        *out = 0.0f;
        *a = -1;
        *b = -1;
        return 0;
    }
    float len;
    fn_80259918(self, p, a, b);
    const Unk80273498_Vec3& pos = ((Unk80273498_Pos*)p)->m60;
    Unk80273498_Vec3 d = pos - fn_8014E388(*a);
    len = fn_804028E4(d.x * d.x + d.y * d.y + d.z * d.z);
    const float k = 0.00092592591f;
    *out = len * k;
    return 1;
}

void fn_80259C00(M* self, int a)
{
    fn_8026A0F4((char*)self->m4 + 0x190, a);
}

void fn_80259C28(M* self, int a)
{
    fn_80268684((char*)self->m4 + 0x124, a);
}

void fn_80259C50(M* self, int a)
{
    fn_802686E4((char*)self->m4 + 0x124, a);
}

extern Unk80273498_Vec3 lbl_805DBA04[];
extern "C" P* fn_80259C78(M* self, int sel)
{
    P* best = 0;
    float bestLen = 12000.0f;
    float len;
    int i = 9;
    do {
        P* p = fn_8026B8C0(self->m4, i);
        if (p != 0) {
            A* a = &p->m58C;
            if (a->m30 == sel) {
                int better = 0;
                Unk80273498_Vec3 d = ((Unk80273498_Pos*)p)->m60 - lbl_805DBA04[sel];
                len = fn_804028E4(d.x * d.x + d.y * d.y + d.z * d.z);
                if (best != 0) {
                    int x = a->m38;
                    int y = best->m58C.m38;
                    if (x == y) {
                        if (!(len >= bestLen))
                            better = 1;
                    } else if (x < y)
                        better = 1;
                } else
                    better = 1;
                if (better) {
                    best = p;
                    bestLen = len;
                }
            }
        }
        i++;
    } while (i <= 12);
    return best;
}

float fn_80259DB4(M* self, int a)
{
    float t = fn_80259EE8((char*)self->m4 + 0x468, 0, a, -1);
    return t;
}

void fn_80259DF0(M* self)
{
    fn_80268DB0((char*)self->m4 + 0xBC);
}

void fn_80259E18(M* self, int a)
{
    fn_80265D24(self->m4, a);
}

void fn_80259E3C(void* x)
{
    Unk80259E3C_F* f = (Unk80259E3C_F*)x;
    for (int i = 0; i <= 3; i++) {
        f->a[i] = lbl_805DACF8;
        for (int j = 0; j < 4; j++)
            f->b[i][j] = lbl_805DACF8;
    }
}

void* fn_80259E90(void* x)
{
    fn_80259E3C(x);
    return x;
}

void fn_80259EC0(void* x, int a)
{
    if (a & 1)
        fn_80377408(x);
}

float fn_80259EE8(void* p, int sel, int idx, int c)
{
    float r = lbl_805DACFC;
    switch (sel) {
    case 0:
        r = fn_8025A780((float*)p, idx);
        break;
    case 1:
        r = fn_80259FFC(p, idx);
        break;
    case 2:
        r = fn_80259FB8(p, (P*)idx, c);
        break;
    }
    return r;
}

int fn_80259F60(void* self, float* arr, int n, float v)
{
    float s = lbl_805DAD00;
    int i = 0;
    for (; i < n; i++) {
        if (v < arr[i] + s)
            return i;
        s = arr[i] + s;
    }
    return 0;
}

float fn_80259FB8(void* self, P* p, int c)
{
    Unk80259E3C_F* f = (Unk80259E3C_F*)self;
    return f->b[fn_8025A664(self, p)][c];
}

/* near-miss: 105 vs 105 instructions, 6 slots (fcmpu operand order and the f12/f13 pair of the two `(r - 0.05) max 0.0` clamps). Written `K >? (r - k)`; `(r - k) >? K` loads k first and compares the other way round */
float fn_80259FFC(void* so, int po)
{
    Unk8025A1A0_O* self = (Unk8025A1A0_O*)so;
    P* p = (P*)po;
    self->m50 = p->m44C;
    float a = fn_8025454C(&p->m588, 0x15);
    Unk80259FFC_F4 tbl = lbl_805DAD04;
    int i = fn_80259F60(self, lbl_805DBAC8, 4, a);
    float r;
    r = RandK_9FFC(self->m50, lbl_805DAD14, 0x71);
    P* pl = fn_801C1638(self->m50, 0);
    if (*(int*)((char*)p + 0xA04) == 1)
        r = lbl_805DAD58 >? (r - lbl_805DAD54);
    if (!(fn_80254618(&pl->m588, 1) < lbl_805DAD5C))
        r = lbl_805DAD58 >? (r - lbl_805DAD54);
    return tbl.v[fn_80259F60(self, lbl_805DBA88[i], 4, r)];
}

int fn_8025A3A4(float* p)
{
    for (int i = 0; i < 4; i++) {
        if (!(p[i] <= 0.0f))
            return 1;
    }
    return 0;
}

int fn_8025A664(void* self, P* p)
{
    return p->m458 - 9;
}

void fn_8025A670(Unk8025A1A0_O* o, Q* q)
{
    o->m50 = q;
    fn_8025A3DC(o, lbl_805DADBC);
    fn_8025A1A0(o, lbl_805DADBC);
}

void fn_8025A6B4(Unk8025A1A0_O* o, Q* q)
{
    o->m50 = q;
    fn_8025A3DC(o, lbl_805DADC0);
    fn_8025A1A0(o, lbl_805DADC0);
}

void fn_8025A6F8(float* arr)
{
    for (int i = 0; i < 4; i++) {
        if (!(arr[i] <= lbl_805DADC4))
            arr[i] = (arr[i] - (float)lbl_8061B9C8 * lbl_805DADD0) >? lbl_805DADC4;
    }
}

inline float AtF(float* base, int i)
{
    int o = i * 4;
    return *(float*)((char*)base + o);
}

float fn_8025A780(float* self, int b)
{
    if (b == 0)
        return lbl_805DADD4;
    return AtF(self, fn_8025A664(self, (P*)b));
}

void fn_8025AA28(Unk8027A84C* g, P* p, int sel)
{
    Unk80273498_Vec3 v;
    int s = sel;
    if (s == -1)
        s = p->m58C.m38;
    switch (s) {
    case 0:
        v = lbl_8068CDCC;
        break;
    case 1:
        v = lbl_8068CDB4;
        break;
    case 2:
        v = lbl_8068CDF0;
        break;
    default:
        v = lbl_8068CDF0;
        break;
    }
    Unk80273498_Vec3 w = v;
    g->fn_8027A898(&w);
    ((Unk80287D70*)g)->fn_80287DB8(10);
}

void fn_8025AB00(Unk8027A84C* g, P* p)
{
    Unk80273498_Vec3 v = lbl_806055AC;
    switch (p->m58C.m38) {
    case 0:
        v = lbl_8068CE14;
        break;
    case 1:
        v = lbl_8068CDD8;
        break;
    case 2:
        v = lbl_8068CDC0;
        break;
    default:
        v = lbl_8068CDF0;
        break;
    }
    ((Unk80287D70*)g)->fn_80287DB8(11)->m38 = 3;
    Unk80273498_Vec3 w = v;
    g->fn_8027A898(&w);
}

int fn_8025AC04()
{
    return 0;
}

/* near-miss: 106 vs 106 insns, 4 differ: the vector copy in the no-goal-data arm sits at sp+8 in ours, sp+0x30 in retail (all three copies share one frame slot there). Tried function-level temporaries */
extern float atan2f(float y, float x);
extern void fn_801C33B0(char* a, Unk80273498_Vec3* b, Unk80273498_Vec3* c);
extern void fn_80299B98(P* p, const Unk80273498_Vec3& pos, float* ang);
Unk8027C728_Goal* fn_8025AC0C(Q* self, P* p, Unk8025AC0C_E* e)
{
    p->m58C.m30 = e->mC;
    Unk8027C728_Goal* g = fn_802448F4(p, 1);
    if (p->m458 == 9 && e->mC == -1) {
        Unk8027A84C* gd = (Unk8027A84C*)g->m18;
        Unk80273498_Vec3 v1;
        Unk80273498_Vec3 v2;
        fn_801C33B0(*(char**)((char*)self->m700 + 0x3A4), &v1, &v2);
        float ang = atan2f(v2.x, v2.z);
        fn_80299B98(p, v1, &ang);
        g->m10 = 2;
        fn_8027C728(g);
        Unk80273498_Vec3 w = v2;
        gd->fn_8027A898(&w);
        ((Unk80287D70*)gd)->fn_80287DB8(9);
    } else {
        g->m10 = 2;
        Unk8027A84C* gd = (Unk8027A84C*)g->m18;
        fn_8027C728(g);
        fn_8025AA28(gd, p, e->mC);
        if (gd->m2C != 0) {
            Unk80273498_Vec3 t = Unk8025AC0C_Pos34(g);
            float ang = atan2f(t.x, t.z);
            Unk80273498_Vec3 w = Unk8025AC0C_Pos28(e);
            fn_80299B98(p, w, &ang);
        } else {
            Unk80273498_Vec3 w = Unk8025AC0C_Pos28(e);
            fn_80299B98(p, w, 0);
        }
    }
    e->m34 = 0;
    return g;
}

Unk8027C728_Goal* fn_8025ADB4(void* o, void* p, A* a)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 1);
    g->m10 = 2;
    fn_8027C728(g);
    ((Unk80287D70*)g->m18)->fn_80287DB8(10);
    a->m34 = 0;
    return g;
}
