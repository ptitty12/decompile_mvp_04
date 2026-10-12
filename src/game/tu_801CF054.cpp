/*
 * Game code, .text 0x801CF054-0x801D31D8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801CF054.h"
#include "game/tu_801C6D2C.h"
#include "game/goals/tu_8027A84C.h"
#include "game/goals/tu_8027C728.h"

typedef Unk801CF054_Y Y;
struct Unk801CF054_Tbl4 {
    Vec3 v[4];
};
extern Unk801CF054_Tbl4 lbl_805D1D5C;
extern "C" int fn_801CF96C(Unk801C16B0_Z* z, float f, float* out);
extern int lbl_8062036C;
extern float lbl_80620370;
extern "C" int fn_802536D0(Unk801B7FB0_P* p);
struct Unk801CF054_T {
    char pad0[8];
    Unk801B7FB0_P* m8[3];
};
extern Unk801CF054_T* lbl_8068B618;

inline Unk801B7FB0_P* GetP(Unk801B7FB0_P** a, unsigned i)
{
    if (i <= 2)
        return a[i];
    return 0;
}

inline int GetJ(Unk801B7FB0_Arr* a, int i) { return a->m14[i]; }

typedef Unk801C16B0_Z Z;

/* Goal storage at goal+0x18 (full layout in goals/tu_80287600.h, which also declares
 * globals const that retail reloads, so only the method is declared here). */
class Unk80287D70 {
public:
    Unk80287D70* fn_80287DB8(int kind);
};
extern "C" Unk8027C728_Goal* fn_802448F4(Unk801B7FB0_P* p, int k);
void fn_8027C728(Unk8027C728_Goal* g);
void fn_8027D33C(Unk8027C728_Goal* g);
void fn_8027D368(Unk8027C728_Goal* g);
int fn_8027D3E8(Unk8027C728_Goal* g, int a, float* outF, Vec3* pos6, Vec3* pos7, float* out8);
extern "C" Vec3* fn_801C342C(Vec3* out, Z* z);
extern "C" void fn_80187D20(Unk801B7FB0_P* c, int k, float a, float b, float c2);
extern "C" Unk801B7FB0_P* fn_801A4B34(Unk801B7FB0_P* ctx);
extern "C" void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
typedef Unk801B7FB0_P P;
extern const char lbl_805D26C8[];
extern float lbl_805D26E8;
extern float lbl_805D26EC;
extern float lbl_805D26F0;

extern "C" {
void fn_801D04C0(Y* y);
int fn_801A2034(Unk801B7FB0_P* p, int k);
void fn_8035B1C8(void* p);
void fn_801D6FE4(void* p);
void fn_801D5CF0(Y* y);
int fn_8022F138(void* p);
}

struct Unk801CF054_V2 {
    float x;
    float y;
};
extern "C" void fn_8022EA60(Unk801CF054_V2* out, void* a, ...);
inline float AbsF(float v) { return (float)__builtin_fabs(v); }

extern "C" float fn_80235DA8(void* p);
extern "C" float fn_801A0AA8(P* p, float f1, float f2);
typedef Unk801CF054_V2 (*Unk801CF054_VaFn)(void*, ...);
extern "C" Unk801CF054_V2 fn_801CD94C(void* z);
struct Unk801CF054_Q4 {
    float x;
    float y;
    float z;
    float w;
};
extern "C" int fn_801C5AE0(Z* z, void* b, int c, int d, int e, int f, int g, float t);
extern "C" Unk801CF054_Q4 fn_80379C80(const Vec3* a, const Vec3* b, int c);
extern "C" int fn_801C4128(Z* z);
extern "C" float fn_8041171C(float x);
extern "C" float fn_80411554(float x);
extern "C" float fn_804028E4(float x);
float fn_802D7E88(int a, int b);
float fn_802D7E2C(int a, int b);
extern "C" float fn_80190F0C(P* p);
extern "C" int fn_801D7998(void* self, Unk801CF054_V2 v);
extern "C" int fn_801D7A3C(void* self, int k);
struct Unk801CF054_R {
    char pad0[0x30];
    int m30;
};
extern "C" Unk801CF054_R* fn_801A6DB8(P* p);
struct Unk801CF054_F4 {
    float v[4];
};
extern Unk801CF054_F4 lbl_805D2788;
extern "C" float fn_801D1994(Y* y);
extern "C" float fn_801D15C0(Y* y);
extern "C" float fn_8024D0F8(P* p, int k);
extern "C" float fn_801D21F4(Y* y, Unk801CF054_V2* v);
extern "C" void fn_801D0C38(Y* y, Unk801CF054_V2 in, Unk801CF054_V2* out);
extern Unk801CF054_V2 lbl_8060558C;
extern const char lbl_805D25E0[];
inline float RandF2(Unk8014D8AC* r, float scale, const char* file, int line)
{
    return (float)(unsigned)r->fn_8014D8AC(1000000, file, line) * scale * 1e-6f;
}

void fn_80303CA0(const char* fmt, float a, float b, float c, ...);

inline void SetMode(Unk801C16B0_Mode* m, int v)
{
    if (m->m0 != 0)
        m->m4 = v;
}

extern "C" void fn_801CF054(Z* z, float* a, float* b)
{
    if (fn_801C4128(z)) {
        *a = 0.0f;
        return;
    }
    int k = fn_801A2034(z->m204, 3);
    float x = fn_802D7E88(k, 0xB3);
    float y = fn_802D7E2C(k, 0xB3);
    if (!(y <= 1.0f))
        y = 1.0f;
    y = y * (AbsF(fn_8041171C(x + x)) * (fn_804028E4(2.0f) - 1.0f) + 1.0f);
    *a = fn_80411554(x) * y;
    *b = -fn_8041171C(x) * y;
    *a = !(*a > 1.0f) ? (*a >? -1.0f) : 1.0f;
    *b = !(*b > 1.0f) ? (*b >? -1.0f) : 1.0f;
}

extern "C" void fn_801CF1BC(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p) {
        P* c = z->m204->m6CC;
        Unk801C16B0_Mode* md = &z->m28C;
        if (md->m0 != 0) {
            if (c->m38C == 2) {
                const float k = 0.2f;
                if (!(fn_80190F0C(c) - c->m3F4 < k)) {
                    SetMode(md, 5);
                    fn_8037893C(&z->m204->m704, 0x66, 0, 0, 0);
                } else {
                    SetMode(md, 6);
                }
            } else {
                SetMode(md, 5);
                fn_8037893C(&z->m204->m704, 0x66, 0, 0, 0);
            }
        }
        Unk8027C728_Goal* g = fn_802448F4(p, 1);
        g->m10 = 2;
        fn_8027C728(g);
        Vec3 v;
        fn_801C342C(&v, z);
        ((Unk8027A84C*)g->m18)->fn_8027A898(&v);
        ((Unk80287D70*)g->m18)->fn_80287DB8(9);
        fn_8027D33C(g);
    }
}

extern "C" void fn_801CF304(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p) {
        if (z->m124 != 2) {
            P* c = z->m204->m6CC;
            if (c->m38C == 2)
                fn_80187D20(c, 0, 1.0f, 1.0f, 1.0f);
            if (z->m1CC == 0)
                SetMode(&z->m28C, 3);
            else
                SetMode(&z->m28C, 2);
            Unk8027C728_Goal* g = fn_802448F4(p, 2);
            g->m10 = 0;
            fn_8027C728(g);
            *(int*)((char*)g + 0x60) = 2;
            Unk8027C728_Goal* g0 = g->m0;
            g0->m10 = 2;
            fn_8027C728(g0);
            Vec3 v;
            fn_801C342C(&v, z);
            ((Unk8027A84C*)g0->m18)->fn_8027A898(&v);
            ((Unk80287D70*)g0->m18)->fn_80287DB8(9);
            fn_8027D33C(g);
            fn_8037893C(&z->m204->m704, 0x56, 0, 0, 0);
        }
    }
}

extern "C" int fn_801CF588(Z* z, Unk801CF054_Q4* out, Vec3* in, int idx, float f)
{
    P* p = fn_801A4B34(z->m204);
    out->w = 0.0f;
    *(Vec3*)out = lbl_806055AC;
    char t10[16];
    char t20[16];
    char t30[16];
    if (!fn_801C5AE0(z, p, (int)in, idx, (int)t10, (int)t20, (int)t30, f))
        return 0;
    Vec3 tmp = *in;
    tmp.y = 0.0f;
    *out = fn_80379C80(in, &tmp, idx);
    return 1;
}

extern "C" void fn_801CF68C(Z* z, float* a, float* b, float* c)
{
    int r = fn_802536D0(fn_801A4B34(z->m204));
    Unk801CF054_Tbl4 t = lbl_805D1D5C;
    *a = t.v[r].x;
    *b = t.v[r].y;
    *c = t.v[r].z;
}

extern "C" float fn_801CF8CC(float x)
{
    float a = 0.033333335f;
    float b = 0.008333334f;
    float c = 0.19f;
    if (lbl_8062036C != 0)
        c = lbl_80620370;
    else
        lbl_80620370 = c;
    if (!(x >= 0.0f))
        c = x * 0.008333334f + c;
    else
        c = x * 0.033333335f + c;
    return c;
}

extern "C" void fn_801CFB28(Z* z, float a, float b, float c)
{
    float oa, ob, oc;
    int r1 = fn_801CF96C(z, a, &oa);
    int r2 = fn_801CF96C(z, b, &ob);
    int r3 = fn_801CF96C(z, c, &oc);
    if (r1 && r2 && r3)
        fn_80187D20(z->m204->m6CC, 1, oa, ob, oc);
}

extern "C" void fn_801CFBC4(Y* y, P* p, float* a, float* b, float* c, float* d, float* e)
{
    Unk8027C728_Goal* g = fn_802448F4(p, 1);
    g->m10 = 0;
    fn_8027C728(g);
    fn_8027D3E8(g, 8, a, 0, 0, 0);
    fn_8027D3E8(g, 9, b, 0, 0, 0);
    fn_8027D3E8(g, 10, c, 0, 0, 0);
    fn_8027D3E8(g, 11, d, 0, 0, 0);
    fn_8027D3E8(g, 12, e, 0, 0, 0);
    fn_8027D368(g);
}

extern "C" void fn_801D0288(Y* y) { y->m1F4 = 1; }

extern "C" int fn_801D0294(Y* y)
{
    switch (y->m4) {
    case 1:
    case 2:
    case 4:
    case 6:
    case 7:
        return 1;
    case 0:
    case 3:
    case 5:
        return 0;
    default:
        return 0;
    }
}

extern "C" int fn_801D02E0(Y* y)
{
    switch (y->m4) {
    case 4:
    case 5:
    case 6:
    case 7:
        return 1;
    case 0:
    case 1:
    case 2:
    case 3:
        return 0;
    default:
        return 0;
    }
}

extern "C" int fn_801D0314(Y* y)
{
    switch (y->m4) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
        return 1;
    case 4:
    case 5:
    case 6:
        return 2;
    case 7:
        return 1;
    default:
        return 0;
    }
}

extern "C" int fn_801D0368(Y* y)
{
    switch (y->m4) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
        return 0;
    case 2:
    case 3:
        return 1;
    default:
        return 0;
    }
}

extern "C" Y* fn_801D03A8(Y* y)
{
    fn_8035B1C8(y->m44);
    fn_801D6FE4(y->m6C);
    y->m2C = 0;
    y->m30 = 0;
    y->m38 = 0;
    fn_801D5CF0(y);
    return y;
}

extern "C" void fn_801D03FC(Y* y, void* a, Unk801B7FB0_P* p)
{
    y->m2C = a;
    y->m30 = p;
    y->m34 = p->m700;
    y->m38 = 0;
    y->m28 = 0;
    fn_801D5CF0(y);
}

extern "C" void fn_801D043C(void) {}

extern "C" void fn_801D0440(Y* y)
{
    if (y->m38 == 0) {
        P* c = y->m30->m6CC;
        if (c->m38C == 2 && !(c->m3F4 <= 0.033333335f || c->m3F4 >= 0.5f)) {
            fn_801D04C0(y);
            y->m38 = 1;
        }
    }
}

inline P* GetPB(P** a, unsigned i)
{
    if (i <= 2) {
        int o = i * 4;
        return *(P**)((char*)a + o);
    }
    return 0;
}

extern "C" int fn_801D0B48(Y* y)
{
    Unk801CF054_T* t = lbl_8068B618;
    P* p = GetPB(t->m8, t->m8[0] == y->m30);
    int k = 0;
    if (p->m6F8->m14->m1CD0 != 0)
        k = 1;
    return GetJ(p->m6F8->m10, k);
}

extern "C" int fn_801D0BB0(Y* y)
{
    int e = y->m30->m6F8->m14->m1CD0 == 0;
    int ok = fn_801A2034(y->m30, e) != -1 ? 1 : 0;
    if (ok)
        return GetJ(y->m30->m6F8->m10, e);
    return 2;
}

extern "C" int fn_801D0C30(void) { return 1; }

extern "C" int fn_801D112C(Y* y)
{
    int v = ((Unk801CF054_O*)y->m30->m6F8->mC->mC)->m174C;
    if (v)
        fn_80303CA0("CPU sees obvious repeat pitch", lbl_805D26E8, lbl_805D26EC, lbl_805D26F0);
    return v;
}

extern "C" int fn_801D1198(Y* y) { return fn_8022F138(((Unk801C16B0_M4*)y->m34)->m3B0) != 0; }

/* near-miss: same code; the frame slots differ (retail: lim 8, abs 0x10, f 0x18, by-value temp 0x20, b 0x28). */
extern "C" int fn_801D14A0(Y* y)
{
    Unk801CF054_V2 b = lbl_8060558C;
    float f;
    fn_801D0C38(y, lbl_8060558C, &b);
    const float lim = 2.0f;
    if (AbsF(b.x) > lim)
        return 0;
    if (AbsF(b.y) > lim)
        return 0;
    f = fn_801D21F4(y, &b);
    return RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x283) <= f;
}

extern "C" float fn_801D17D0(Y* y, Unk801CF054_V2* pos)
{
    float r = 0.0f;
    char* self = (char*)y->m2C + 8;
    int k = fn_801D7A3C(self, fn_801D7998(self, *pos));
    if (fn_801A6DB8(y->m30)->m30)
        k = 2;
    switch (k) {
    case -1:
        r = 0.0f;
        break;
    case 0:
        r = 0.333333f;
        break;
    case 1:
        r = 0.666667f;
        break;
    case 2:
        r = 1.0f;
        break;
    }
    return r;
}

extern "C" float fn_801D18B4(void)
{
    char buf[16];
    return 0.0f;
}

extern "C" float fn_801D18C8(Y* y)
{
    float t = 1.0f - fn_80235DA8(((Unk801C16B0_M4*)y->m34)->m3B0);
    Unk801CF054_F4 tbl = lbl_805D2788;
    t = t * tbl.v[fn_801D0BB0(y)];
    t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
    return t;
}

extern "C" float fn_801D21F4(Y* y, Unk801CF054_V2* v)
{
    int small = 0;
    if (!(AbsF(v->x) > 1.0f))
        small = AbsF(v->y) <= 1.0f;
    float t = 0.0f;
    if (small)
        t = fn_801D1994(y);
    else
        t = fn_801D15C0(y);
    P* q = fn_801A4B34(y->m30);
    t = t + LerpATB(-0.25f, fn_8024D0F8(q, 0x11), 0.25f);
    return t;
}

/* near-miss: same code; retail keeps 1e-6 in f29 and 1.0 in f30 (ours swapped) and stores the scale slot after the lwz. */
extern "C" void fn_801D28E4(Y* y)
{
    y->m54 = 0.75f + RandF2(y->m30->m554, 0.25f, lbl_805D25E0, 0x46C);
    y->m50 = RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x46F);
    if (!(RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x471) >= 0.33f))
        y->m50 = -y->m50;
}

/* near-miss: same code; retail stores the second RandF scale slot before loading the RNG pointer. */
extern "C" void fn_801D2A40(Y* y)
{
    Unk801CF054_V2 v = ((Unk801CF054_VaFn)fn_801CD94C)(((Unk801C16B0_M4*)y->m34)->m3A4);
    float t;
    t = !(v.x > 1.0f) ? -(v.x >? -1.0f) : -1.0f;
    y->m50 = t + LerpATB(-0.1f, RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x487), 0.1f);
    if (fn_801A4B34(y->m30)->v4())
        y->m50 = -y->m50;
    if (!(RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x48F) >= 0.25f))
        y->m54 = 1.0f;
    else
        y->m54 = LerpATB(-1.0f, RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x495), 1.0f);
}

/* near-miss: same code; the integer temporaries of the last statement are numbered r11/r10 where retail has r10/r11. */
extern "C" void fn_801D2C74(Y* y)
{
    Unk801CF054_V2 v = ((Unk801CF054_VaFn)fn_801CD94C)(((Unk801C16B0_M4*)y->m34)->m3A4);
    float t;
    t = !(v.x > 1.0f) ? -(v.x >? -1.0f) : -1.0f;
    float u = AbsF(t);
    y->m50 = fn_801A0AA8(y->m30, u, 0.35f);
    if (!(t >= 0.0f))
        y->m50 = -y->m50;
    if (fn_801A4B34(y->m30)->v4())
        y->m50 = -y->m50;
    y->m54 = LerpATB(-0.8f, RandF2(y->m30->m554, 1.0f, lbl_805D25E0, 0x4B7), 1.0f);
}

extern "C" int fn_801D251C(Y* y)
{
    Unk801CF054_V2 v;
    fn_8022EA60(&v, ((Unk801C16B0_M4*)y->m34)->m3B0);
    float ax = AbsF(v.x);
    float ay = AbsF(v.y);
    if (!(ax >= 1.0f)) {
        if (ay < 1.0f)
            return 1;
    }
    return 0;
}
