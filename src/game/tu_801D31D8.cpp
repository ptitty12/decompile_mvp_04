/*
 * Game code, .text 0x801D31D8-0x801D771C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801D31D8.h"
#include "game/tu_801800FC.h"
#include "game/tu_801B7FB0.h"

inline void* operator new(unsigned int, void* p) { return p; }

typedef Unk801D31D8 B;

extern float lbl_805D2C40;
extern const float lbl_805D2CD8;
extern const float lbl_805D2CDC;
extern const float lbl_805D2CE8;
extern float lbl_805D2CEC;
extern float lbl_805D2CF0;
extern float lbl_8061CBDC;
extern const float lbl_805D2CF4;
extern float lbl_805D2CF8;
extern float lbl_805D2D08;
extern float lbl_805D2D0C;
extern const char lbl_805D25E0[];
extern float lbl_805D29D8;
extern const float lbl_805D29DC;
extern float lbl_805D29E8;
extern float lbl_805D29EC;
extern float lbl_805D2BFC;
extern float lbl_805D2C00;
extern float lbl_805D2C10;
extern float lbl_805D2C14;
extern float lbl_805D2CC0;
extern const float lbl_805D2CC4;
extern float lbl_805D2CC8;
extern float lbl_805D2CCC;
extern float lbl_805D2CD0;
extern float lbl_805D2CD4;
extern float lbl_805D2C50;
extern float lbl_805D2C54;
extern float lbl_805D2C7C;
extern const float lbl_805D2D78;
extern float lbl_805D2D7C;
extern float lbl_805D2D80;
extern float lbl_805D2D84;
extern float lbl_8061CBE0;
extern float lbl_805D2C80;
extern float lbl_805D2D98;
extern float lbl_805D2C84;

extern "C" {
void fn_801D5CF0(B* s);
void fn_801D5D00(B* s);
void fn_801D67CC(B* s);
void fn_801D6D30(B* s, float a, float b);
void fn_801D6CE4(B* s, float a, float b);
void fn_801D6A1C(B* s, float* a, float* b);
void fn_801D7084(Unk801D31D8_Pair* s, int i, float v);
int fn_801C1638(Unk801D31D8_Game* g, int i);
void fn_801D7030(Unk801D31D8_Pair* s, int i, float v);
int fn_8035B3BC(void* p);
int fn_8018AD20(Unk801D31D8_Obj* o);
float fn_8022E7F0(int a, int b);
float fn_804028E4(float x);
Unk80183918_Vec3 fn_80189618(Unk801D31D8_Obj* o, float t);
float fn_801CF8CC(void* p, float f);
float fn_801CF740(void* p);
}

typedef void (*Pair2Fn)(Unk801D31D8_Pair*, int);

static inline int FlagZ(B* s)
{
    return s->m30->m6F8->m14->m1CD0 == 0;
}

static inline int FlagNZ(B* s)
{
    int t = 0;
    if (s->m30->m6F8->m14->m1CD0 != 0)
        t = 1;
    return t;
}

inline float AbsF(float v) { return (float)__builtin_fabs(v); }
inline float RandG(Unk801D31D8_Game* g, float scale, const char* file, int line)
{
    return (float)(unsigned)g->m554->fn_8014D8AC(1000000, file, line) * scale * 1e-6f;
}
struct Unk801D31D8_V2 {
    float x;
    float y;
};
struct Unk801D31D8_M34 {
    char pad0[0x3A4];
    void* m3A4;
};
typedef Unk801D31D8_V2 (*Unk801D31D8_VaFn)(void*, ...);
extern "C" Unk801D31D8_V2 fn_801CD94C(void* p);
struct Unk801D31D8_W {
    char pad0[0x34];
    Unk801D31D8_M34* m34;
};
inline float LerpATB(float a, float t, float b)
{
    return a + t * (b - a);
}

extern "C" float fn_801D2E0C(B* s);

extern "C" void fn_801D31D8(B* s)
{
    int h = ((Unk801B7FB0_P*)fn_801A4B34((Unk801808A4_Ctx*)s->m30))->v24();
    Unk801D31D8_V2 v = ((Unk801D31D8_VaFn)fn_801CD94C)(((Unk801D31D8_W*)s)->m34->m3A4);
    float t = !(v.x > 1.0f) ? -(v.x >? -1.0f) : -1.0f;
    float u = fn_801D2E0C(s);
    float w = LerpATB(0.0f, 1.0f - u, 1.7f);
    if (!(t <= 0.0f))
        s->m44.mC = t - w;
    else
        s->m44.mC = t + w;
    if (h != 0)
        s->m44.mC = -s->m44.mC;
    s->m44.mC = !(s->m44.mC > 1.0f) ? (s->m44.mC >? -1.0f) : 1.0f;
    float r = RandG(s->m30, 1.0f, lbl_805D25E0, 0x535);
    if (!(r >= 0.3f))
        s->m44.m10 = LerpATB(-1.0f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x539), 0.3f);
    else if (!(r >= 0.6f))
        s->m44.m10 = LerpATB(0.3f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x53E), 0.6f);
    else if (!(r >= 0.8f))
        s->m44.m10 = LerpATB(0.6f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x543), 1.0f);
    else
        s->m44.m10 = 1.0f;
}

extern "C" void fn_801D34E4(B* s)
{
    float lo = lbl_805D29D8;
    float t;
    float hi;
    volatile int pad;
    float x = lbl_805D29DC;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0x552);
    hi = lbl_805D29DC;
    t = (float)r * x * lbl_805D29E8;
    s->m44.m10 = lbl_805D29EC;
    s->m44.mC = t * (hi - lo) + lo;
}

static inline int Ok(int f) { int ok; if ((unsigned)(f + 1) > 1) { ok = 1; if ((f & 8) == 0) ok = 0; } else ok = 0; return ok; }

struct Unk801D31D8_Q66 {
    char pad0[0x60];
    Vec3 m60;
};
struct Unk801D31D8_GV {
    char pad0[0x66C];
    Unk801D31D8_Q66* m66C;
    char pad670[0x688 - 0x670];
    int m688;
};
extern "C" Vec3 fn_8014E388(int idx);
inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

extern "C" void fn_801D35AC(B* s)
{
    int flag = 1;
    s->m44.mC = 0.9f;
    s->m44.m10 = -0.2f;
    if (((Unk801D31D8_GV*)s->m30)->m688 == 0)
        flag = 0;
    Unk801B7FB0_P* p = (Unk801B7FB0_P*)fn_801A4B34((Unk801808A4_Ctx*)s->m30);
    if (p) {
        int near = 0;
        Unk801D31D8_Q66* q = ((Unk801D31D8_GV*)s->m30)->m66C;
        if (q) {
            float d2;
            Vec3 d = q->m60 - fn_8014E388(3);
            d2 = d.x * d.x + d.z * d.z;
            near = d2 < 1166400.0f;
        }
        if (flag != 0 || near != 0) {
            s->m44.mC = 0.95f;
        } else {
            float r = RandG(s->m30, 1.0f, lbl_805D25E0, 0x570);
            if (!(r >= 0.65f)) {
                s->m44.mC = -0.95f;
            } else {
                s->m44.mC = 0.8f;
                s->m44.m10 = 0.5f;
            }
        }
        if (p->v24() == 0)
            s->m44.mC = -s->m44.mC;
    }
}

extern "C" int fn_801D3798(B* s)
{
    Unk801D31D8_Game* g = s->m30;
    int ok = Ok(g->m700->m3C0->m14);
    int r = 0;
    if (ok) {
        int a = 1;
        if (fn_801C1638(g, 0xA) == 0)
            a = 0;
        int b = 1;
        if (fn_801C1638(g, 0xB) == 0)
            b = 0;
        int c = fn_801C1638(g, 0xC) != 0;
        int t = 0;
        if (a != 0 || b != 0 || c != 0)
            t = 1;
        r = t ^ 1;
    }
    return r;
}

struct Unk801D31D8_V2b {
    float x;
    float y;
};
struct Unk801D31D8_M34b {
    char pad0[0x3B0];
    void* m3B0;
};
struct Unk801D31D8_Wb {
    char pad0[0x34];
    Unk801D31D8_M34b* m34;
};
extern "C" void fn_8022EA60(Unk801D31D8_V2b* out, void* a, ...);
struct Unk801D31D8_Tbl4 {
    float v[4];
};
extern Unk801D31D8_Tbl4 lbl_805D2B7C;
extern Unk801D31D8_Tbl4 lbl_805D2BBC;
struct Unk801D31D8_Z2C {
    char pad0[0x1FC];
    float m1FC;
};
extern "C" int fn_801D0BB0(B* s);

extern Unk801D31D8_Tbl4 lbl_805D296C;
extern "C" float fn_80235DA8(void* p);
extern "C" float fn_801A0AA8(Unk801B7FB0_P* p, float a, float b);
extern "C" float fn_801D18C8(B* s);
struct Unk80087A58_O;
float fn_80088E74(Unk80087A58_O* o);
struct Unk801D31D8_GMV {
    char pad0[0xC];
    Unk80087A58_O* mC;
};
struct Unk801D31D8_G6V {
    char pad0[0xC];
    Unk801D31D8_GMV* mC;
};

static inline int OkM(int f, int m)
{
    int ok;
    if ((unsigned)(f + 1) > 1) {
        ok = 1;
        if ((f & m) == 0)
            ok = 0;
    } else
        ok = 0;
    return ok;
}
extern "C" int fn_801D112C(B* s);
extern "C" int fn_801D1198(B* s);
extern "C" void fn_801D2A40(B* s);
extern "C" void fn_801D2C74(B* s);

extern "C" void fn_801D386C(B* s)
{
    Unk801D31D8_X3C0* x = s->m30->m700->m3C0;
    if (OkM(x->m14, 8) != 0) {
        if (fn_801D3798(s) != 0) {
            fn_801D34E4(s);
            return;
        }
        fn_801D35AC(s);
        return;
    }
    if (fn_801D112C(s) != 0)
        fn_801D2A40(s);
    else if (fn_801D1198(s) != 0)
        fn_801D2C74(s);
    else
        fn_801D31D8(s);
    if (OkM(x->m14, 4) != 0) {
        s->m44.m10 = LerpATB(-1.0f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x5BC), -0.2f);
        return;
    }
    if (OkM(x->m14, 0x10) != 0) {
        s->m44.m10 = LerpATB(0.75f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x5C1), 1.0f);
        return;
    }
    if (OkM(x->m14, 0x20) != 0) {
        float v = LerpATB(0.6f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x5C6), 1.0f);
        if (((Unk801B7FB0_P*)fn_801A4B34((Unk801808A4_Ctx*)s->m30))->v4() != 0)
            v = -v;
        s->m44.mC = v;
        s->m44.m10 = LerpATB(-0.5f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x5CE), 0.2f);
    }
}

extern "C" float fn_801D40AC(B* s)
{
    float r = 0.0f;
    int flag = 0;
    if (!(fn_80235DA8(((Unk801D31D8_Wb*)s)->m34->m3B0) <= 0.75f))
        flag = RandG(s->m30, 1.0f, lbl_805D25E0, 0x626) < 0.25f;
    if (flag != 0) {
        r = RandG(s->m30, 0.3f, lbl_805D25E0, 0x62E);
    } else {
        Unk801D31D8_Tbl4 t = lbl_805D296C;
        r = t.v[fn_801D0BB0(s)];
        r = !(r > 1.0f) ? (r >? 0.0f) : 1.0f;
        float x = ((Unk801D31D8_Z2C*)s->m2C)->m1FC;
        x = !(x > 1.0f) ? (x >? 0.0f) : 1.0f;
        r *= LerpATB(0.8f, x, 1.2f);
        r = fn_801A0AA8((Unk801B7FB0_P*)s->m30, r, 0.25f);
        r = !(r > 1.0f) ? (r >? 0.0f) : 1.0f;
        float y = fn_801D18C8(s);
        y = !(y > 1.0f) ? (y >? 0.0f) : 1.0f;
        r *= LerpATB(1.0f, y, 1.25f);
        r *= LerpATB(1.0f, fn_80088E74(((Unk801D31D8_G6V*)s->m30->m6F8)->mC->mC), 1.2f);
        r = !(r > 1.0f) ? (r >? 0.0f) : 1.0f;
    }
    return r;
}

extern "C" void fn_801D5158(B* s)
{
    Unk801D31D8_Tbl4 t = lbl_805D2B7C;
    float v = t.v[fn_801D0BB0(s)];
    float w = ((Unk801D31D8_Z2C*)s->m2C)->m1FC;
    v *= LerpATB(0.9f, w, 1.1f);
    Unk801D31D8_V2b vv;
    fn_8022EA60(&vv, ((Unk801D31D8_Wb*)s)->m34->m3B0);
    if (!(AbsF(vv.x) >= 0.4f) && !(AbsF(vv.y) >= 0.4f))
        v *= 1.25f;
    v = !(v > 0.98f) ? (v >? 0.0f) : 0.98f;
    if (!(RandG(s->m30, 1.0f, lbl_805D25E0, 0x7DD) >= v))
        s->m44.m8 = 1;
    float a = fn_801CF8CC(s->m2C, s->m44.mC);
    float b = fn_801CF740(s->m2C);
    s->m44.m4 = b * LerpATB(-0.2f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x7E5), 0.2f) + a;
}

extern "C" void fn_801D53D4(B* s)
{
    Unk801D31D8_Tbl4 t = lbl_805D2BBC;
    float v = t.v[fn_801D0BB0(s)];
    float w = ((Unk801D31D8_Z2C*)s->m2C)->m1FC;
    v *= LerpATB(0.8f, w, 1.1f);
    Unk801D31D8_V2b vv;
    fn_8022EA60(&vv, ((Unk801D31D8_Wb*)s)->m34->m3B0);
    if (!(AbsF(vv.x) >= 0.4f) && !(AbsF(vv.y) >= 0.4f))
        v *= 1.25f;
    v = !(v > 0.98f) ? (v >? 0.0f) : 0.98f;
    if (!(RandG(s->m30, 1.0f, lbl_805D25E0, 0x80A) >= v))
        s->m44.m8 = 1;
    float a = fn_801CF8CC(s->m2C, s->m44.mC);
    float b = fn_801CF740(s->m2C);
    s->m44.m4 = b * LerpATB(-0.6f, RandG(s->m30, 1.0f, lbl_805D25E0, 0x812), 0.6f) + a;
}

extern "C" void fn_801D5650(B* s)
{
    float a;
    float b;
    float lo;
    float t;
    float hi;
    volatile int pad;
    float x;
    s->m44.m8 = 1;
    a = fn_801CF8CC(s->m2C, s->m44.mC);
    b = fn_801CF740(s->m2C);
    lo = lbl_805D2BFC;
    x = lbl_805D2C00;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0x824);
    t = (float)r * x * lbl_805D2C10;
    hi = lbl_805D2C14;
    s->m44.m4 = b * (t * (hi - lo) + lo) + a;
}

extern "C" int fn_801D112C(B* s);
extern "C" int fn_801D1198(B* s);
extern "C" void fn_801D49CC(B* s);
extern "C" void fn_801D5158(B* s);
extern "C" void fn_801D53D4(B* s);

extern "C" void fn_801D573C(B* s)
{
    if (fn_801D3798(s))
        fn_801D5650(s);
    else if (fn_801D112C(s))
        fn_801D5158(s);
    else if (fn_801D1198(s))
        fn_801D53D4(s);
    else
        fn_801D49CC(s);
    if (s->m44.m8 == 0) {
        int h = ((Unk801B7FB0_P*)fn_801A4B34((Unk801808A4_Ctx*)s->m30))->v24();
        Unk801D31D8_V2 v = ((Unk801D31D8_VaFn)fn_801CD94C)(((Unk801D31D8_W*)s)->m34->m3A4);
        float t = !(v.x > 1.0f) ? -(v.x >? -1.0f) : -1.0f;
        if (h != 0)
            t = -t;
        int ok = 1;
        if (!(AbsF(t) <= 0.85f))
            ok = RandG(s->m30, 1.0f, lbl_805D25E0, 0x855) >= 0.25f;
        if (ok)
            s->m44.mC = t;
        else
            s->m44.mC = -t;
    }
}

extern "C" int fn_801D5914(B* s, int a, int b)
{
    if (s->m38 != 0 && s->m44.m14 != 0) {
        if (s->m44.m1C != 0) {
            if (b != 0)
                return 1;
            return 0;
        }
        return (unsigned)(a + s->m44.m18) < s->m30->m4C;
    }
    return 0;
}

struct Unk801D31D8_Q {
    char pad0[0x64];
    int m64;
    float m68;
};

extern "C" int fn_801D5974(B* s)
{
    if (((Unk801D31D8_Q*)s)->m64 != 0 && ((Unk801D31D8_Q*)s)->m68 < (float)s->m30->m4C * lbl_805D2C40)
        return 1;
    return 0;
}

extern "C" int fn_801D59D8(B* s)
{
    if (fn_8035B3BC((char*)s->m2C + 0x28C) == 0 || (s->m38 != 0 && s->m44.m0 == 0))
        return 1;
    return fn_8018AD20(s->m30->m6CC) != 0;
}

extern "C" void fn_801D5A50(B* s, float* a, float* b)
{
    *a = s->m44.mC;
    *b = s->m44.m10;
}

static inline int Ok2(int f)
{
    int t;
    if ((unsigned)(f + 1) > 1) {
        int u = 1;
        if ((f & 8) == 0)
            u = 0;
        t = u;
    } else
        t = 0;
    return t;
}

struct Unk801D31D8_Obj {
    char pad0[0x38C];
    int m38C;
    char pad390[0x3F4 - 0x390];
    float m3F4;
};
extern "C" float fn_80190F0C(Unk801D31D8_Obj* o);
extern const double lbl_805D2C48;

extern "C" int fn_801D5A64(B* s, int* o1, int* o2, int* o3)
{
    Unk801D31D8_Game* g = s->m30;
    int ok = Ok2(g->m700->m3C0->m14);
    Unk801D31D8_Obj* o = (Unk801D31D8_Obj*)g->m6CC;
    *o2 = 0;
    *o3 = 0;
    float d;
    if (ok != 0) {
        if (fn_801D3798(s) == 0) {
            int v = 0;
            if (fn_8035B3BC((char*)s->m2C + 0x28C) != 0 && (s->m38 == 0 || s->m44.m0 != 0))
                v = 1;
            if (v != 0) {
                *o1 = 2;
                return 1;
            }
            return 0;
        }
        if (s->m38 != 0 && s->m44.m0 != 0 && o->m38C == 2) {
            d = fn_80190F0C(o) - o->m3F4;
            if (!(d > s->m44.m4 + lbl_805D2C48)) {
                *o1 = 1;
                *o2 = 1;
                *o3 = s->m44.m8;
                return 1;
            }
        }
        return 0;
    }
    if (s->m38 != 0 && s->m44.m0 != 0 && o->m38C == 2) {
        d = fn_80190F0C(o) - o->m3F4;
        if (!(d > s->m44.m4 + lbl_805D2C48)) {
            *o1 = 1;
            *o3 = s->m44.m8;
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_801D5C1C(B* s)
{
    int* a = &s->m44.m0;
    int* b = &s->m38;
    *b = 0;
    *a = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C50;
    q->m8 = 0;
    q->mC = lbl_805D2C50;
    q->m10 = lbl_805D2C50;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C50;
}

extern "C" void fn_801D5C5C(B* s)
{
    fn_801D5CF0(s);
}

extern "C" void fn_801D5C7C(B* s)
{
    int* a = &s->m44.m0;
    int* b = &s->m38;
    *b = 0;
    *a = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C54;
    q->m8 = 0;
    q->mC = lbl_805D2C54;
    q->m10 = lbl_805D2C54;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C54;
}

extern "C" void fn_801D5CBC(B* s)
{
    fn_801D5D00(s);
}

extern "C" void fn_801D5CDC(B* s, int* a, int* b)
{
    *a = s->m3C;
    *b = s->m40;
}

extern "C" void fn_801D5CF0(B* s)
{
    s->m3C = 0;
    s->m40 = 0;
}

extern "C" void fn_801D5F2C(B* s)
{
    if (s->m30->m6F4 == 0)
        return;
    int* a = &s->m44.m0;
    int* b = &s->m38;
    *b = 0;
    *a = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C7C;
    q->m8 = 0;
    q->mC = lbl_805D2C7C;
    q->m10 = lbl_805D2C7C;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C7C;
}

extern "C" void fn_801D5F7C(B* s)
{
    int* a = &s->m38;
    int* b = &s->m44.m0;
    *a = 0;
    *b = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C80;
    q->m8 = 0;
    q->mC = lbl_805D2C80;
    q->m10 = lbl_805D2C80;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C80;
    float len;
    Unk80183918_Vec3 v = fn_80189618(s->m30->m6CC, lbl_805D2C80);
    len = fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8) * lbl_805D2C84;
    fn_801D7030(&s->m6C, FlagZ(s), len);
}

extern "C" void fn_801D6044(B* s)
{
    Unk801D31D8_Pair* p = &s->m6C;
    fn_8022E7F0(s->m30->m700->m3B0, FlagZ(s));
    ((Pair2Fn)fn_801D7084)(p, FlagZ(s));
    fn_8022E7F0(s->m30->m700->m3B0, FlagNZ(s));
    ((Pair2Fn)fn_801D7084)(p, FlagNZ(s));
}

extern "C" void fn_801D6108(B* s)
{
    Unk801D31D8_Pair* p = &s->m6C;
    fn_8022E7F0(s->m30->m700->m3B0, FlagZ(s));
    ((Pair2Fn)fn_801D7084)(p, FlagZ(s));
}

extern "C" void fn_801D63A8(B* s)
{
    s->m44.mC = lbl_805D2CC0;
    s->m44.m10 = lbl_805D2CC0;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    float r = fn_801CF8CC(s->m2C, s->m44.mC);
    s->m44.m4 = r;
}

extern "C" void fn_801D6404(B* s, int flag)
{
    s->m44.m10 = lbl_805D2CC4;
    s->m44.mC = lbl_805D2CC4;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    float a = fn_801CF740(s->m2C);
    float b = fn_801CF8CC(s->m2C, s->m44.mC);
    float c;
    if (flag != 0)
        c = lbl_805D2CC4;
    else
        c = lbl_805D2CC8;
    s->m44.m4 = a * c + b;
}

extern "C" void fn_801D64A0(B* s, int flag)
{
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    s->m44.m10 = lbl_805D2CCC;
    s->m44.mC = lbl_805D2CCC;
    float a = fn_801CF740(s->m2C);
    float b = fn_801CF8CC(s->m2C, s->m44.mC);
    float c;
    if (flag != 0)
        c = lbl_805D2CD0;
    else
        c = lbl_805D2CD4;
    s->m44.m4 = a * c + b;
}

/* near-miss: second lerp's load order after the 2nd RNG call differs (hi2/x2 reload order, ~8 slots) */
extern "C" void fn_801D6538(B* s)
{
    float lo;
    float t;
    float hi;
    volatile int pad1;
    float x;
    volatile int pad2;
    float a;
    float b;
    float x2;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    lo = lbl_8061CBDC - lbl_805D2CD8;
    x = lbl_805D2CDC;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0xA1F);
    hi = lbl_8061CBDC + lbl_805D2CD8;
    t = (float)r * x * lbl_805D2CE8;
    s->m44.mC = lbl_805D2CDC;
    s->m44.m10 = t * (hi - lo) + lo;
    a = fn_801CF740(s->m2C);
    b = fn_801CF8CC(s->m2C, s->m44.mC);
    lo = lbl_805D2CEC;
    x2 = lbl_805D2CDC;
    unsigned r2 = s->m30->m554->fn_8014D8AC(1000000, file, 0xA24);
    hi = lbl_805D2CF0;
    t = (float)r2 * x2 * lbl_805D2CE8;
    s->m44.m4 = a * (t * (hi - lo) + lo) + b;
}

extern "C" void fn_801D66C8(B* s)
{
    float a;
    float b;
    float lo;
    float t;
    float hi;
    volatile int pad;
    float x;
    s->m44.m10 = lbl_805D2CF4;
    s->m44.mC = lbl_805D2CF4;
    s->m44.m0 = 1;
    s->m44.m8 = 0;
    a = fn_801CF740(s->m2C);
    b = fn_801CF8CC(s->m2C, s->m44.mC);
    lo = lbl_805D2CF8;
    x = lbl_805D2CF4;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0xA31);
    t = (float)r * x * lbl_805D2D08;
    hi = lbl_805D2D0C;
    s->m44.m4 = a * (t * (hi - lo) + lo) + b;
}

extern "C" void fn_801D67CC(B* s)
{
    s->m44.m0 = 0;
    s->m44.m8 = 0;
}

extern "C" void fn_801D6CE4(B* s, float a, float b)
{
    if (!(b >= lbl_8061CBE0))
        fn_801D6D30(s, a, b);
    else
        fn_801D67CC(s);
}

extern float lbl_8061CBE4;
extern float lbl_8061CBE8;
extern float lbl_8061CBEC;
extern float lbl_8061CBF0;
extern float lbl_8061CBF4;

extern "C" void fn_801D6D30(B* s, float a, float b)
{
    if (!(a >= lbl_8061CBE4 * lbl_8061CBF4)) {
        fn_801D63A8(s);
        return;
    }
    if (a < lbl_8061CBE8 * lbl_8061CBF4) {
        fn_801D6538(s);
        return;
    }
    if (!(a >= lbl_8061CBEC * lbl_8061CBF4)) {
        fn_801D64A0(s, 0);
        return;
    }
    if (!(a >= lbl_8061CBF0 * lbl_8061CBF4)) {
        float r = RandG(s->m30, 1.0f, lbl_805D25E0, 0xAD6);
        if (!(r >= 0.1f)) {
            fn_801D66C8(s);
            return;
        }
        if (!(r >= 0.2f)) {
            fn_801D6538(s);
            return;
        }
        fn_801D6404(s, 0);
        return;
    }
    float t = b + 0.3f;
    t = !(t > 0.9f) ? (t >? 0.0f) : 0.9f;
    if (!(RandG(s->m30, 1.0f, lbl_805D25E0, 0xAEA) >= t))
        fn_801D67CC(s);
    else
        fn_801D66C8(s);
}

extern "C" void fn_801D6F6C(B* s)
{
    float a = lbl_805D2D78;
    float b = lbl_805D2D78;
    fn_801D6A1C(s, &a, &b);
    if (!(b <= lbl_805D2D78))
        fn_801D6CE4(s, a, b);
    else
        fn_801D6D30(s, a, b);
}

extern "C" Unk801D31D8_Pair* fn_801D6FE4(Unk801D31D8_Pair* s)
{
    fn_801D7084(s, 0, lbl_805D2D7C);
    fn_801D7084(s, 1, lbl_805D2D7C);
    return s;
}

extern "C" void fn_801D7030(Unk801D31D8_Pair* s, int i, float v)
{
    float k;
    s->m0[i] = s->m8[i] * (k = lbl_805D2D80) + s->m0[i] * lbl_805D2D84;
    s->m8[i] = v;
}

extern "C" float fn_801D7078(Unk801D31D8_Pair* s, int i)
{
    return s->m0[i];
}

extern "C" void fn_801D7084(Unk801D31D8_Pair* s, int i, float v)
{
    s->m8[i] = v;
    s->m0[i] = v;
}

/* Table object built by fn_801D70A8 (vtable lbl_80660700, name hash 0xC12D4655). */
extern "C" void fn_8033CCE0(void* p);
struct Unk801D70A8_E18 {
    float m0;
    char m4;
    char pad5[0x13];
    Unk801D70A8_E18()
    {
        m0 = lbl_805D2D98;
        m4 = 0;
    }
};
struct Unk801D70A8_E20 {
    float m0;
    float m4;
    float m8;
    char mC;
    char padD[0x13];
    Unk801D70A8_E20()
    {
        m0 = lbl_805D2D98;
        m4 = lbl_805D2D98;
        m8 = lbl_805D2D98;
        mC = 0;
    }
};
struct Unk801D70A8_List {
    int d0;
    int d1;
    int d2;
    Unk801D70A8_List() { fn_8033CCE0(this); }
};
class Unk801D70A8_Obj : public Unk8037B3E8 {
public:
    virtual const char* fn_vslot3();
    Unk801D70A8_Obj() : Unk8037B3E8(0xC12D4655u) {}
    Unk801D70A8_E18 m4[2];
    Unk801D70A8_E20 m34[4];
    Unk801D70A8_E20 mB4[6];
    Unk801D70A8_E18 m174[3];
    Unk801D70A8_List m1BC;
    Unk801D70A8_List m1C8;
    Unk801D70A8_List m1D4;
};

extern "C" void* fn_801D70A8(void* mem)
{
    return new (mem) Unk801D70A8_Obj;
}
