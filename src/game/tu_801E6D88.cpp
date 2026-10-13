/*
 * Game code, .text 0x801E6D88-0x801EA36C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801DB948.h"
#include "game/clampiter.h"

typedef Unk801DD660 I;
typedef Unk801DB948_Vec3 Vec3;
typedef Unk80270BA0_X P;

extern const char lbl_80660AC0[];
extern const Vec3 lbl_805D4040[];
extern const Vec3 lbl_805D4070[];
extern const Vec3 lbl_805D40A0[];
extern const Vec3 lbl_805D40D0[];
extern const Vec3 lbl_805D3F98[];
extern const float lbl_805D4254;
extern const float lbl_805D4A0C;
extern float lbl_805D4A00;
extern float lbl_805D4A04;
extern float lbl_805D4A08;

struct Unk801E6D88_W {
    int m0;
    int m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    int m1C;
    int m20;
};

extern "C" void fn_801E99A0(Unk801E6D88_W* s, int a);

struct Unk801E6D88_F160 {
    char pad0[0x160];
    float m160;
};
struct Unk801E6D88_S {
    char pad0[0xC];
    char pad_c[0x20 - 0xC];
    int m20;
    int m24;
    int m28;
};

extern "C" {
int fn_802055F4(Unk801DD660_Ctx* c);
int fn_801E923C(I* i, int v);
int fn_801E9280(I* i, int v);
int fn_801E8328(I* i, Vec3* out, float f);
void fn_801E8640(Unk801E6D88_F160* s, float v);
int fn_801A2034(Unk801DB948_Game* g, int a);
int fn_801A700C(Unk801DB948_Game* g, int a, int b);
int fn_802D7DB4(int a, int b);
void fn_801E9AC4(I* i);
void fn_801F5E18(I* i);
void fn_801F5EF0(I* i);
void fn_8014E09C(Unk801DB948_It* it, Unk801DB948_Game* g, int k);
P* fn_801A497C(Unk801DB948_Game* g, int a, int b);
int fn_802D7DB4(int a, int b);
int fn_8020543C(Unk801DD660_Ctx* c);
void fn_802053AC(Unk801DD660_Ctx* c);
void fn_80253950(void* o, void* a);
void fn_80253A30(void* o, void* a, void* b);
void fn_801F5FD4(I* s, void* a);
}

struct Unk8019F8C0_Owner;
int fn_801A2034(Unk8019F8C0_Owner* o, int k);
float fn_802D7E2C(int a, int b);

struct Unk801EA03C_A {
    char pad0[0x5B8];
    int m5B8;
};
struct Unk801EA03C_Obj {
    char pad0[0x580];
    char m580[1];
};

struct Unk801E6D88_Obj {
    int m0;
    int m4[17];
    int m48[6];
    int m60[14];
    const void* m98;
};
extern const int lbl_8061CA70[];
extern const int lbl_8061CAB4[];
extern const int lbl_8061CADC[];
extern "C" int fn_801E5F3C(int h);
extern "C" int fn_801E63B0(int h);
extern "C" int fn_801E6920(int h);

extern "C" Unk801E6D88_Obj* fn_801E6D88(Unk801E6D88_Obj* s, int a)
{
    s->m0 = a;
    s->m98 = lbl_80660AC0;
    int i;
    for (i = 0; i < 17; i++)
        s->m4[i] = fn_801E5F3C(lbl_8061CA70[i]);
    for (i = 0; i < 6; i++)
        s->m48[i] = fn_801E63B0(lbl_8061CAB4[i]);
    for (i = 0; i < 14; i++)
        s->m60[i] = fn_801E6920(lbl_8061CADC[i]);
    return s;
}

extern "C" void fn_801E6E48(I* s, int chrg)
{
    *(const void**)((char*)s + 0x98) = lbl_80660AC0;
    if (chrg & 1)
        operator delete(s);
}

inline Vec3 Unk801E7218_Sub(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
inline float Unk801E7218_Len2(Vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}
extern const Vec3 lbl_805D3FE0[];
extern "C" Vec3 fn_801DC814(Unk801DB948* self, Unk801DB948_Obj* o, int c, int d);
extern "C" int fn_801E7E00(Unk801DD660_Ctx* self, int idx, Vec3* v, int a, int b);

extern "C" Vec3 fn_801E7218(Unk801DD660_Ctx* self, int idx, Unk801DB948_Obj* o, int c, const Vec3* pos)
{
    Unk801DB948_J* j = self->m0->m700;
    Vec3 base = fn_801DC814(j->m3B8, o, c, idx);
    int f1 = 0;
    int f2 = 0;
    if (pos != 0) {
        if (!(Unk801E7218_Len2(Unk801E7218_Sub(*pos, lbl_805D3FE0[idx * 2])) >= 36.0f))
            f2 = 1;
        if (!(Unk801E7218_Len2(Unk801E7218_Sub(*pos, lbl_805D3FE0[idx * 2 + 1])) >= 36.0f)) {
            f1 = 1;
            f2 = 1;
        }
    }
    int k = fn_801E7E00(self, idx, &base, f1, f2);
    return *(const Vec3*)((const char*)lbl_805D3FE0 + idx * 24 + k * 12);
}

extern "C" Vec3 fn_801E73B8(void* self, int k)
{
    return lbl_805D4040[k];
}

extern "C" Vec3 fn_801E73E8(void* self, int k, int sel)
{
    if (sel == 1)
        return lbl_805D4070[k];
    return lbl_805D40A0[k];
}

extern "C" Vec3 fn_801E7448(void* self, int k)
{
    return lbl_805D40D0[k];
}

struct Unk801A96E0_Init;
int fn_801A9E0C(Unk801A96E0_Init* o, int i);
extern "C" Vec3 fn_801DC890(Unk801DB948* w, Unk801DB948_Obj* o, P* p, int a, int b, int c);
extern const Vec3 lbl_805D3F68[];

extern "C" Vec3 fn_801E7D1C(Unk801DD660_Ctx* self, int k, int sel)
{
    if (sel == 2)
        return lbl_805D3F68[k];
    Unk801DB948_Game* g = self->m0;
    Unk801DB948_J* j = g->m700;
    Unk801DB948_Obj* o = g->m6CC;
    Unk801DB948* w = j->m3B8;
    P* p = fn_801A497C(g, 4, k);
    return fn_801DC890(w, o, p, fn_801A9E0C((Unk801A96E0_Init*)j->m3C4, k), 4, 10);
}

extern "C" Vec3 fn_801E7DD0(void* self, int k)
{
    return lbl_805D3F98[k];
}

/* near-miss: retail tests a == 2 first and uses cmpwi cr7,r7,4 + LT bit for d < 4 (we get <= 3) */
extern "C" int fn_801E7FD8(void* self, int a, int b, int c, int d)
{
    int r = 0;
    if (a == 2) {
        if (b != 3)
            return r;
        r = 1;
        if (d > 5)
            return r;
        return d < 4;
    }
    if (a == 4) {
        int f = 1;
        if (b == 1)
            f = 0;
        if (f != 1)
            return r;
        r = 1;
        if (c == 9 || (c >= 12 && c <= 14))
            r = 0;
        if (d > 5)
            return r;
        if (d < 3)
            return r;
        return 0;
    }
    return r;
}

extern "C" void fn_801E8068(I* s)
{
    s->m798 = 0;
    Unk801DB948_It it;
    fn_8014E09C(&it, s->m9C->m0, 1);
    while (it.Cur() != 10) {
        P* p = fn_801A497C(s->m9C->m0, 4, it.Cur());
        if (p != 0)
            p->m71C = p->m71C & 0xFFFFBFFF;
        it.Next();
    }
}

extern "C" void fn_801E80F0(I* s, int v)
{
    if (s->m798 <= 2 && fn_801E923C(s, v) == 0) {
        int n = s->m798;
        s->m7A8[n] = v;
        s->m798 = n + 1;
        P* p = fn_801A497C(s->m9C->m0, 4, v);
        p->m71C = p->m71C | 0x4000;
    }
}

extern "C" int fn_801E816C(I* s, int i)
{
    return s->m7A8[i];
}

extern "C" int fn_801E817C(I* s, int a)
{
    if (fn_802055F4(s->m9C) == 0)
        return 0;
    return fn_801E923C(s, a);
}

extern "C" void fn_801E81C8(I* s)
{
    s->m794 = 0;
    Unk801DB948_It it;
    fn_8014E09C(&it, s->m9C->m0, 1);
    while (it.Cur() != 10) {
        P* p = fn_801A497C(s->m9C->m0, 4, it.Cur());
        if (p != 0)
            p->m71C = p->m71C & 0xFFFFDFFF;
        it.Next();
    }
}

extern "C" void fn_801E8250(I* s, int v)
{
    if (s->m794 <= 2 && fn_801E9280(s, v) == 0) {
        int n = s->m794;
        s->m79C[n] = v;
        s->m794 = n + 1;
        P* p = fn_801A497C(s->m9C->m0, 4, v);
        p->m71C = p->m71C | 0x2000;
    }
}

extern "C" int fn_801E82CC(I* s, int i)
{
    return s->m79C[i];
}

extern "C" int fn_801E82DC(I* s, int a)
{
    if (fn_802055F4(s->m9C) == 0)
        return 0;
    return fn_801E9280(s, a);
}

extern "C" {
int fn_80188EF4(Unk801DB948_Obj* o);
int fn_801DE314(I* i, P* o, int k);
}
extern const float lbl_805D422C;

float fn_802D7F40(int k);
float fn_802D7E88(int k, int h);
float fn_802D7E2C(int k, int h);
extern "C" float fn_80411554(float x);
extern "C" float fn_8041171C(float x);
extern const float lbl_805D4208;
extern const float lbl_805D420C;
extern const Vec3 lbl_806055AC;

extern "C" int fn_801E8328(I* s, Vec3* out, float f)
{
    int r = 0;
    int k = fn_801A2034((Unk8019F8C0_Owner*)s->m9C->m0, 4);
    float a = fn_802D7F40(k);
    float b = fn_802D7E88(k, 0xBC);
    float c = fn_802D7E2C(k, 0xBC);
    if (!(c <= f)) {
        r = 1;
        a = -a;
        b = b - lbl_805D4208;
        out->x = fn_80411554(a + b);
        out->y = lbl_805D420C;
        out->z = fn_8041171C(a + b);
    } else {
        *out = lbl_806055AC;
    }
    return r;
}

extern "C" int fn_801E8428(I* s, int a, Vec3* out, float* outf)
{
    int r = 0;
    int k = fn_801A2034((Unk8019F8C0_Owner*)s->m9C->m0, 4);
    *outf = 3.0f;
    float c = fn_802D7E2C(k, 0xBC);
    if (!(c <= 1.0f))
        c = 1.0f;
    float a1 = fn_802D7F40(k);
    float b1 = fn_802D7E88(k, 0xBC);
    P* p = fn_801A497C(s->m9C->m0, 4, a);

    float thr;
    if (!(c <= (thr = 0.04f))) {
        r = 1;
        a1 = -a1;
        *outf = c;
        b1 = b1 - 3.1415927f;
        out->x = fn_80411554(a1 + b1) * 240.0f;
        out->y = 0.0f;
        out->z = fn_8041171C(a1 + b1) * 240.0f;
        const Vec3* pv = &p->m60;
        out->x = out->x + pv->x;
        out->y = out->y + pv->y;
        out->z = out->z + pv->z;
    } else {
        *outf = 0.0f;
        *out = p->m60;
    }
    return r;
}

extern "C" int fn_801E85D0()
{
    return 1;
}

extern const float lbl_805D4228;

extern "C" int fn_801E85D8(I* s)
{
    float f = fn_802D7E2C(fn_801A2034((Unk8019F8C0_Owner*)s->m9C->m0, 4), 0xBD);
    fn_801E8640((Unk801E6D88_F160*)s, f);
    int r = f > lbl_805D4228;
    return r;
}

extern "C" void fn_801E8640(Unk801E6D88_F160* s, float v)
{
    s->m160 = v;
}

extern "C" float fn_801E8658(Unk801E6D88_F160* s)
{
    return s->m160;
}

extern "C" int fn_801E8660(I* s, int a, int* out, float* outf)
{
    int k = fn_801A2034((Unk8019F8C0_Owner*)s->m9C->m0, 4);
    int r;
    if (fn_802D7DB4(k, 0xC0) != 0)
        r = 0;
    else if (fn_802D7DB4(k, 0xC1) != 0)
        r = 1;
    else if (fn_802D7DB4(k, 0xC2) != 0)
        r = 2;
    else if (fn_802D7DB4(k, 0xC3) != 0)
        r = 3;
    else
        r = -1;
    *out = r;
    if (fn_80188EF4(s->m9C->m0->m6CC) == 1)
        *out = -1;
    Unk801E6D88_W* w = (Unk801E6D88_W*)s->mC4;
    if (w->m1C == *out)
        return 0;
    if (*out != -1) {
        P* p = fn_801A497C(s->m9C->m0, 4, a);
        if (p != 0 && fn_801DE314(s, p, *out) == 1)
            *out = -1;
    }
    *outf = lbl_805D422C;
    if (*out != -1)
        w->m1C = *out;
    int ret = 1;
    if (*out == -1)
        ret = 0;
    return ret;
}

extern "C" int fn_801E87C4(I* s, int a, int* out1, int b, int* out2)
{
    Unk801E6D88_S* sub = (Unk801E6D88_S*)((char*)s->m9C->m0->m700->m3B0 + 0xC);
    *out1 = sub->m28;
    if (sub->m20 == 1) {
        *out2 = sub->m24 == 1;
        return 1;
    }
    return 0;
}

struct Unk80250244_S;
void fn_80250180(Unk80250244_S* o, int k);
void fn_802501E0(Unk80250244_S* o);
extern "C" int fn_801E90F4(I* s);
struct Unk801E8A3C_Tbl {
    int a[4];
};
extern const Unk801E8A3C_Tbl lbl_805D4244;

struct Unk801E8810_Q {
    char pad0[0x14];
    float m14;
    char pad18[8];
    int m20;
    char pad24[0x38 - 0x24];
    int m38;
};
struct Unk801E8810_R {
    char pad0[8];
    float m8;
    char padC[8];
    float m14;
    float m18;
};
struct Unk802F8324_O3;
struct Unk802F8324_Rec;
void fn_802FAD5C(Unk802F8324_O3* o, int k, Unk802F8324_Rec* r);
extern int lbl_8061B9C8;

extern "C" int fn_801E8810(I* s, int a, int sel, float* out, float f)
{
    int r = 0;
    int k = fn_801A2034((Unk8019F8C0_Owner*)s->m9C->m0, 4);
    Unk801E8810_Q* q = (Unk801E8810_Q*)(s->m9C->m0->m700->m3B0 + 0xC);
    if (q->m20 == 1)
        r = q->m38 == 0;
    if (sel == -1) {
        if (fn_802D7DB4(k, 0xC5) == 1 || fn_802D7DB4(k, 0xC6) == 1)
            r = 1;
    } else if (sel == 0) {
        if (fn_802D7DB4(k, 0xC0) == 1)
            r = 1;
    } else if (sel == 1) {
        if (fn_802D7DB4(k, 0xC1) == 1)
            r = 1;
    } else if (sel == 2) {
        if (fn_802D7DB4(k, 0xC2) == 1)
            r = 1;
    } else if (sel == 3) {
        if (fn_802D7DB4(k, 0xC3) == 1)
            r = 1;
    }
    Unk801E8810_R* rec = (Unk801E8810_R*)((char*)s + 0xC4);
    fn_801A497C(s->m9C->m0, 4, a);
    float v0 = -1.0f;
    float w;
    if (r == 1) {
        if (!(f >= 0.0f))
            v0 = rec->m14;
        else
            v0 = rec->m18 + f;
        w = v0;
        rec->m14 = w;
        w = (float)lbl_8061B9C8 * 0.016666668f + rec->m18;
        rec->m18 = w;
        if (!(rec->m18 <= v0)) {
            w = v0;
            r = 0;
            rec->m18 = w;
        }
    }
    if (q->m20 == 1 && q->m38 == 0) {
        fn_802FAD5C(*(Unk802F8324_O3**)((char*)s->m9C->m0 + 0x720), k, (Unk802F8324_Rec*)q);
        *out = q->m14;
    } else {
        *out = rec->m18 / rec->m14;
    }
    w = *out;
    rec->m8 = w;
    return r;
}

extern "C" int fn_801E8A3C(I* s, int a, int skip)
{
    int found = 0;
    int idx = -1;
    int k = fn_801A2034((Unk8019F8C0_Owner*)s->m9C->m0, 4);
    Unk801E8A3C_Tbl tbl = lbl_805D4244;
    int* t = tbl.a;
    for (Unk8006A138_It<3> it(0); it.v <= 3; it.Next()) {
        if (fn_802D7DB4(k, t[it.v]) == 1 && skip != it.v) {
            idx = it.v;
            found = 1;
            break;
        }
    }
    if (((Unk801E6D88_W*)s->mC4)->m1C == idx)
        return 0;
    if (found == 0 && fn_801E90F4(s) == 1) {
        found = 1;
        idx = -1;
    }
    if (found == 1) {
        P* p = fn_801A497C(s->m9C->m0, 4, a);
        if (idx == -1)
            fn_802501E0((Unk80250244_S*)((char*)p + 0x4D8));
        else
            fn_80250180((Unk80250244_S*)((char*)p + 0x4D8), idx);
    }
    return found;
}

/* near-miss: retail returns via cmpwi r3,1; li r3,1; beq; li r3,0 instead of the xori/subfic/adde bool (10 slots) */
extern "C" int fn_801E8B80(I* s)
{
    if (fn_802055F4(s->m9C) == 0)
        return 0;
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC4) == 1;
}

extern "C" void fn_801E8BEC(I* s, Vec3* b)
{
    float v;
    fn_801E8328(s, b, v = lbl_805D4254);
}

struct Unk8024EF40_A;
int fn_80254A90(Unk8024EF40_A* a);
extern "C" int fn_801EFD98(I* s, P** out);
extern const float lbl_805D4268;
struct Unk801E8EF4_Dn {
    int v;
    Unk801E8EF4_Dn(int x) { v = x; }
    ~Unk801E8EF4_Dn() {}
    int Next()
    {
        int t;
        if (v > -1)
            t = v - 1;
        else
            t = v;
        v = t;
        return t;
    }
};
inline Vec3 Unk801E8EF4_Sub(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
inline P* Unk801E8EF4_At(Unk801DB948_Game* g, int i)
{
    if ((unsigned)i <= 12) {
        int off = i * 4;
        char* b = (char*)g + 0x65C;
        return *(P**)(b + off);
    }
    return 0;
}

/* near-miss (1 slot): retail slwi writes r11 (the loop index) in place; ours uses r0 for the scaled offset. Tried: unsigned idx,
   ii copy, int/unsigned At() param, branch/early-return forms, off/base order */
extern "C" int fn_801E8EF4(I* s, int idx, P** out)
{
    float u = lbl_805D4268;
    int r = 0;
    P* o = fn_801A497C(s->m9C->m0, 4, idx);
    P* best = 0;
    Vec3 pos = o->m60;
    float bestD = lbl_805D4268;
    P* found = 0;
    if (fn_801EFD98(s, &found) == 1) {
        best = found;
        Vec3 d = Unk801E8EF4_Sub(best->m60, pos);
        bestD = d.x * d.x + d.z * d.z;
    } else {
        int cnt = 12;
        int idx = 12;
        do {
            P* c = Unk801E8EF4_At(s->m9C->m0, idx);
            if (c != 0 && fn_80254A90((Unk8024EF40_A*)((char*)c + 0x58C)) == 1) {
                float d2;
                Vec3 d = Unk801E8EF4_Sub(c->m60, pos);
                d2 = d.x * d.x + d.z * d.z;
                if (!(d2 >= bestD)) {
                    bestD = d2;
                    best = c;
                }
            }
            int cc = *(volatile int*)&cnt;
            int t;
            if (cc <= -1)
                t = cc;
            else
                t = cc - 1;
            *(volatile int*)&cnt = t;
            idx = t;
        } while (idx > 8);
    }
    if (best != 0) {
        *out = best;
        r = 1;
    }
    return r;
}

extern "C" int fn_801E90F4(I* s)
{
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC5) == 1;
}

extern "C" int fn_801E914C(I* s)
{
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC5) == 1;
}

extern "C" int fn_801E91A4(I* s)
{
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC7) == 1;
}

extern "C" int fn_801E91FC(I* s)
{
    return fn_802D7DB4(fn_801A2034(s->m9C->m0, 4), 0xBE) == 1;
}

extern "C" int fn_801E923C(I* s, int v)
{
    int n = s->m798;
    for (int i = 0; i < n; i++) {
        if (v == s->m7A8[i])
            return 1;
    }
    return 0;
}

extern "C" int fn_801E9280(I* s, int v)
{
    int n = s->m794;
    for (int i = 0; i < n; i++) {
        if (v == s->m79C[i])
            return 1;
    }
    return 0;
}

extern "C" void fn_801E98C0(I* s)
{
    fn_802053AC(s->m9C);
    s->mC0 = 0;
    Unk801DD660_Blk* b = &s->mF8;
    s->mF8.m0 = lbl_805D4A00;
    b->m4 = 0;
    b->m8 = lbl_805D4A00;
    b->mC = lbl_805D4A00;
    b->m10 = lbl_805D4A00;
    b->m14 = lbl_805D4A04;
    b->m20 = 1;
    b->m18 = lbl_805D4A08;
    b->m1C = 0;
    s->mF0 = lbl_805D4A00;
    s->mAC.m4 = -1;
    s->mE8 = lbl_805D4A00;
    s->mEC = lbl_805D4A00;
    s->mF4 = lbl_805D4A00;
    s->mAC.m0 = -1;
    fn_801E99A0((Unk801E6D88_W*)s->mC4, (int)s->m9C->m0);
    s->mBC = 1;
    s->mB8 = 0;
}

/* near-miss: float store order (3 slots) */
extern "C" Unk801E6D88_W* fn_801E9970(Unk801E6D88_W* s, int a)
{
    fn_801E99A0(s, a);
    return s;
}

/* near-miss: float store order (3 slots) */
extern "C" void fn_801E99A0(Unk801E6D88_W* s, int a)
{
    s->m1C = -1;
    s->m0 = a;
    s->m4 = 0;
    s->m8 = lbl_805D4A0C;
    s->m20 = 0;
    s->mC = lbl_805D4A0C;
    s->m10 = lbl_805D4A0C;
    s->m14 = lbl_805D4A0C;
    s->m18 = lbl_805D4A0C;
}

/* near-miss: s/f registers swapped (r29/r30) */
extern "C" void fn_801E99D8(Unk801E6D88_W* s)
{
    int f = 0;
    int k = fn_801A2034((Unk801DB948_Game*)s->m0, 4);
    if (fn_802D7DB4(k, 0xC0) != 0 || fn_802D7DB4(k, 0xC1) != 0 || fn_802D7DB4(k, 0xC2) != 0 || fn_802D7DB4(k, 0xC3) != 0)
        f = 1;
    if (f == 0)
        s->m1C = -1;
}

extern "C" void fn_801E9A74(I* s)
{
    Unk801DD660_Ctx* c = s->m9C;
    c->m3A6C = 0;
    c->m3A68 = 0;
    s->mBC = 1;
    fn_801E9AC4(s);
    s->mAC.m0 = -1;
    s->mAC.m4 = -1;
}

struct Unk801E9AC4_Rec {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
};
struct Unk801E9AC4_Sub {
    char pad0[0x5EC];
    int m5EC;
    int m5F0;
    int m5F4;
    int m5F8;
    int m5FC;
    int m600;
};
struct Unk801E9AC4_Row {
    int m0;
    char pad4[0x510];
};
struct Unk8035BE7C {
    void fn_8035BED0(int v);
};
struct Unk805D4A10_F {
    float v;
};
extern Unk805D4A10_F lbl_805D4A10;
extern "C" {
void fn_80204AC8(void* a);
void fn_802121D0(void* a);
void fn_80201764(void* a);
}

extern "C" void fn_801E9AC4(I* i)
{
    if (i->mBC == 1) {
        i->mBC = 0;
        i->mC0 = 0;
        *(int*)((char*)i->m9C + 0x3A5C) = 0;
        *(int*)((char*)i->m9C + 0x3A60) = 0;
        *(int*)((char*)i->m9C + 0xCA4) = 0;
        fn_80204AC8((char*)i->m9C + 0x6A8);
        Unk801E9AC4_Sub* sb = (Unk801E9AC4_Sub*)((char*)i->m9C + 0x6A8);
        sb->m600 = 0;
        sb->m5FC = 0;
        sb->m5F4 = 0;
        sb->m5F0 = 0;
        sb->m5EC = 0;
        fn_802121D0((char*)i->m9C + 0x30);
        Unk801DD660_Ctx* c = i->m9C;
        c->m3A6C = 0;
        c->m3A68 = 0;
        Unk801E9AC4_Row* r = (Unk801E9AC4_Row*)((char*)i->m9C + 0xCA8);
        for (int k = 0; k < 9; k++, r++) {
            int n = r->m0;
            for (int j = 0; j < n; j++) {
            }
            r->m0 = 0;
        }
        fn_80201764(i->m9C);
        Unk801E9AC4_Rec* base = (Unk801E9AC4_Rec*)((char*)i->m9C + 0x62C);
        Unk801E9AC4_Rec* q = base;
        for (int k = 0; k < 4; k++, q++) {
            q->m0 = 0;
            q->m8 = q->m4 = lbl_805D4A10.v;
            q->mC = 0;
        }
        ((Unk8035BE7C*)base)->fn_8035BED0(0);
        fn_801E99A0((Unk801E6D88_W*)i->mC4, *(int*)i->mC4);
    }
}

extern "C" void fn_801E9BE4(I* s)
{
    s->mAC.m0 = -1;
    s->mBC = 1;
    s->mAC.m4 = -1;
}

extern "C" void fn_801E9BFC(I* s)
{
    s->mBC = 1;
}

extern "C" int fn_801E9DE4(I* s)
{
    if (s->mC0 != 3)
        return -1;
    int r = s->m9C->mA4;
    if (r == -1) {
        P* p = s->m9C->m4->m36C;
        if (p != 0)
            r = p->m460;
    }
    return r;
}

extern "C" void fn_801E9E20(I* s)
{
    fn_801F5E18(s);
    fn_801F5EF0(s);
    s->m9C->m44 = 1;
}

extern "C" void fn_801E9E60(I* s)
{
    fn_801F5E18(s);
    fn_801F5EF0(s);
}

extern "C" int fn_801E9E94(I* s)
{
    Unk801DD660_Ctx* c = s->m9C;
    if ((unsigned)(c->m30 - 5) <= 2 || c->m44 == 1)
        return 1;
    return fn_8020543C(c) > 2;
}

extern "C" {
void fn_801EAC60(I* s);
int fn_801EADD4(I* s, int a);
int fn_801EAF38(I* s, int a);
int fn_801EB00C(I* s, int a);
void fn_801EB070(I* s, int a);
void fn_801EB200(I* s, int a);
int fn_8020B898(void* o, int a);
}

static inline int Unk801E9EE8_NZ(int v)
{
    int t = 1;
    if (v == 0)
        t = 0;
    return t;
}

extern "C" int fn_801E9EE8(I* s, int a)
{
    int again;
    do {
        again = 0;
        switch (s->mC0) {
        case 0:
            s->mBC = 1;
            again = Unk801E9EE8_NZ(fn_801EADD4(s, a));
            fn_801EAC60(s);
            break;
        case 1: {
            Unk801DD660_Ctx* c = s->m9C;
            c->m3A6C = 0;
            c->m3A68 = c->m3A68 + 1;
            again = Unk801E9EE8_NZ(fn_801EAF38(s, a));
            break;
        }
        case 2: {
            again = Unk801E9EE8_NZ(fn_801EB00C(s, a));
            int r = fn_8020B898((char*)s + 0xA8, a);
            int u = Unk801E9EE8_NZ(again);
            int w = Unk801E9EE8_NZ(r);
            again = u | w;
            fn_801EB070(s, a);
            break;
        }
        case 3: {
            fn_801EB200(s, a);
            Unk801DD660_Ctx* c = s->m9C;
            c->m3A6C = c->m3A6C + 1;
            break;
        }
        }
    } while (again == 1);
    return 1;
}

/* near-miss: GCC shares the cur != -1 compare across the first call (cmpwi cr4 + mfcr/mtcrf), retail recomputes it (3 insns) */
extern "C" void fn_801EA03C(I* s, Unk801EA03C_A* a, P* p, int k)
{
    if (p != 0) {
        int v = p->m460;
        Unk801DD660_Hist* h = &s->mAC;
        if (v != h->m0) {
            h->m4 = h->m0;
            h->m0 = v;
        }
    }
    int cur = s->mAC.m0;
    if (cur != -1 && k != 6) {
        Unk801EA03C_Obj** tbl = (Unk801EA03C_Obj**)((char*)s->m9C + 8);
        fn_80253950(tbl[cur]->m580, a);
    }
    int prev = s->mAC.m4;
    if (prev != -1 && cur != -1 && k != 6) {
        Unk801EA03C_Obj** tbl = (Unk801EA03C_Obj**)((char*)s->m9C + 8);
        fn_80253A30(tbl[prev]->m580, a, tbl[cur]);
    }
    if (a->m5B8 != -1)
        fn_801F5FD4(s, a);
}

extern "C" {
void fn_80205450(Unk801DD660_Ctx* c, int v);
void fn_802123D4(I* s, int a, int b);
void fn_8021D4A4(I* s);
void fn_802296D0(I* s, int a);
}
extern const float lbl_805D4A2C;

extern "C" int fn_801EA118(I* s, int a, P* p)
{
    if (fn_802055F4(s->m9C) != 0) {
        int z = p->m460;
        if (z == 0 && (s->m9C->mA4 == 3 || s->m9C->mA4 == 5)) {
            fn_80205450(s->m9C, s->m9C->mA4);
            fn_802123D4(s, 0, 0);
            fn_8021D4A4(s);
            fn_801E81C8(s->m9C->m3A64);
            fn_801E8068(s->m9C->m3A64);
            fn_801E8250(s->m9C->m3A64, 0);
            s->m9C->mA4 = z;
            fn_80205450(s->m9C, 0);
            fn_802123D4(s, 0, 0);
            fn_802296D0(s, 0);
            float v = lbl_805D4A2C;
            s->mE8 = v;
            return 1;
        }
    }
    return 0;
}

Unk801DB948_Rt* fn_801A6DB8(Unk801DB948_Game* g);
void fn_801EC5F8(I* s, int v);
void fn_802456C8(P* p, int a, int b, float f);
extern const float lbl_805D4A30;
extern const float lbl_805D4A40;
extern const float lbl_805D4A44;
/* near-miss: 89 vs 88 insns, 11 slots: retail compares fabs(d) against the lim register f11 itself;
 * here lim is a dead spill and the compare constant is re-read (extra fmr f12,f11). Tried const lim, lim only,
 * cur const, fabs inline (extra param spill), d initialised. */
extern "C" void fn_801EA20C(I* s, int mode, int a, P* p)
{
    if (fn_801A6DB8(s->m9C->m0)->m4 != 0) {
        if (mode == 1) {
            if (fn_802055F4(s->m9C) == 0)
                fn_801EC5F8(s, -1);
        } else if (mode == 0) {
            Unk801DD660_Ctx* c = s->m9C;
            if (c->m30 != 0) {
                float lim = lbl_805D4A30;
                float cur = (float)c->m0->m4C * lbl_805D4A40;
                float d;
                if (p->m460 != c->mA4 || (d = cur - c->mA8, !(__builtin_fabs(d) <= lbl_805D4A30))) {
                    if (fn_801EA118(s, a, p) == 0)
                        fn_801EC5F8(s, s->m9C->mA4);
                }
            } else if (p->m458 == 9 && c->m0->m660 != 0) {
                fn_802456C8(c->m0->m660, 1, 0, lbl_805D4A44);
            }
        }
    }
}
