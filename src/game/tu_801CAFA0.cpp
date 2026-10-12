/*
 * Game code, .text 0x801CAFA0-0x801CF054 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801CAFA0.h"
#include "game/tu_801C6D2C.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Z Z;
typedef Unk801CAFA0_V2 V2;
typedef V2 (*Unk801CAFA0_VaFn)(Z*, ...);

extern "C" {
void fn_801CB360(Z* z);
P* fn_801A4B34(P* ctx);
float fn_8024F20C(void* a, int b, P* c, int d, int e);
float fn_8024F048(void* a, int b, P* c, int d, int e);
float fn_80235DA8(void* p);
int fn_80235E28(void* p);
float fn_801D7818(int h, int k);
float fn_801D7828(int h);
float fn_801CCBE8(Z* z);
float fn_801CF740(Z* z);
float fn_80190F0C(P* p);
float fn_801CF8CC(float x);
int fn_801D7998(void* self, V2 v);
int fn_801D7A3C(void* self, int k);
struct Unk801CAFA0_R {
    char pad0[0x30];
    int m30;
};
Unk801CAFA0_R* fn_801A6DB8(P* p);
float fn_801CCA40(Z* z);
float fn_80235D80(void* p);
int fn_8022F138(void* p);
int fn_801C4128(Z* z);
void fn_801D5A50(void* a, float* b, float* c);
void fn_801C4B14(Z* z, float* b, float* c);
float fn_80235DD0(void* p, int a, int b);
P* fn_801C1638(P* c, int i);
float fn_804028E4(float x);
Vec3* fn_801C34D0(Vec3* out, Z* z);
float fn_801CD068(Z* z);
float fn_801A0AA8(P* p, float f1, float f2);
int fn_80380964(Unk801B7FB0_Link* l);
void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
void fn_801D7AC4(void* p, P* q);
float fn_801CEB34(Z* z);
float fn_8024EF40(void* a, P* b, int c);
V2 fn_8022EA60(void* a, ...);
float fn_801CD8D4(Z* z);
void fn_801CC964(Z* z);
V2 fn_801CD94C(Z* z);
float fn_801CC218(Z* z);
float fn_801CC30C(Z* z);
float fn_801CC648(Z* z);
float fn_801CC578(Z* z);
float fn_801CC0CC(Z* z);
}

struct Unk801CAFA0_G {
    float m0[6];
    char pad18[0x78 - 0x18];
    float m78;
    float m7C;
    int m80;
    V2 m84;
    float m8C;
    float m90;
    char pad94[0x390 - 0x94];
    float m390;
    float m394;
    float m398;
};
extern Unk801CAFA0_G lbl_8068C420;
int fn_80289248(Unk80270BA0_X* x);
extern V2 lbl_8060558C;
extern int lbl_8068C6C8;
extern V2 lbl_80691DBC;
extern "C" {
void fn_801CCE0C(Z* z);
void fn_801CB344(Z* z);
void fn_801CB324(Z* z);
void fn_801CD0F0(Z* z);
int fn_801C8974(Z* z);
void fn_801CB148(Z* z);
void fn_801CD400(Z* z);
void fn_801C90AC(Z* z);
void fn_801CA144(Z* z);
void fn_801CA654(Z* z);
int fn_801CDA84(Z* z);
}
extern float lbl_805D1C18;

extern "C" void fn_801CB324(Z* z) { fn_801CB360(z); }

extern "C" void fn_801CB344(Z* z) { *(V2*)z->m150 = lbl_8060558C; }

extern "C" void fn_801CBE08(Z* z)
{
    z->m150[0] = z->m13C;
    P* p = fn_801A4B34(z->m204);
    if (p->v4() == 0)
        z->m150[0] = -z->m150[0];
    z->m150[1] = z->m140;
}

extern "C" float fn_801CBE74(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    float r = fn_8024F20C(p->mA0C, p->mA04, p->m44C, p->m708, 0);
    return r;
}

extern "C" float fn_801CBEBC(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    float r = fn_8024F048(p->mA0C, p->mA04, p->m44C, p->m708, 0);
    return r;
}

inline float AbsF(float v) { return (float)__builtin_fabs(v); }

extern "C" float fn_801CBF04(Z* z)
{
    float w = AbsF(fn_80235D80(z->m4->m3B0));
    w = !(w > 1.0f) ? (w >? 0.0f) : 1.0f;
    if (fn_8022F138(z->m4->m3B0))
        w = LerpATB(0.8f, w, 1.0f);
    return w;
}

extern "C" float fn_801CBFC8(Z* z)
{
    float v = fn_80235DA8(z->m4->m3B0);
    v = !(v > 1.0f) ? (v >? 0.0f) : 1.0f;
    return v;
}

extern "C" float fn_801CC028(Z* z)
{
    int h = fn_80235E28(z->m4->m3B0);
    P* p = fn_801C1638(z->m204, 0);
    if (!p)
        return 0.0f;
    float t = fn_80235DD0(z->m4->m3B0, p->m708, h);
    t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
    return t;
}

extern "C" float fn_801CC0CC(Z* z)
{
    P* c = z->m204->m6CC;
    float scale = fn_801CF740(z);
    z->m1A8 = 6;
    z->m144 = 0.0f;
    z->m148 = 0.0f;
    float out = 0.0f;
    if (c->m38C == 2) {
        float d = fn_80190F0C(c) - c->m3F4;
        float e = ((float (*)(Z*, float))fn_801CF8CC)(z, z->m13C);
        z->m148 = d - e;
        z->m144 = z->m148 / scale;
        if (z->m144 >= 1.0f || !(z->m144 > -1.0f))
            z->m1A8 = 3;
        z->m144 = !(z->m144 > 1.0f) ? (z->m144 >? -1.0f) : 1.0f;
        if (z->m1A8 == 6)
            out = 1.0f - AbsF(z->m144);
        lbl_8068C420.m8C = z->m148;
        lbl_8068C420.m90 = z->m144;
    }
    return out;
}

extern "C" float fn_801CC218(Z* z)
{
    float r = 0.0f;
    V2 v = fn_8022EA60(z->m4->m3B0);
    int k = fn_801D7A3C(z->m8, fn_801D7998(z->m8, v));
    if (fn_801A6DB8(z->m204)->m30)
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

extern "C" float fn_801CC578(Z* z)
{
    float a = z->m1D4;
    a = !(a > 1.0f) ? (a >? -1.0f) : 1.0f;
    float b = z->m140;
    b = !(b > 1.0f) ? (b >? -1.0f) : 1.0f;
    float r = AbsF(b - a);
    r = 2.0f - r;
    r *= 0.5f;
    return r;
}

extern "C" float fn_801CC648(Z* z)
{
    float a = z->m1D0;
    a = !(a > 1.0f) ? (a >? -1.0f) : 1.0f;
    float b = z->m140;
    b = !(b > 1.0f) ? (b >? -1.0f) : 1.0f;
    float r = AbsF(b - a);
    r = 2.0f - r;
    r *= 0.5f;
    return r;
}

extern "C" void fn_801CC894(Z* z)
{
    for (int i = 0; i < 6; i++)
        z->m1DC[i] = 0.0f;
    if (z->m204->m6CC->m38C == 2) {
        fn_801CC964(z);
        z->m1DC[1] = fn_801CC218(z);
        z->m1DC[2] = z->m1FC;
        z->m1DC[3] = fn_801CC30C(z);
        z->m1DC[4] = fn_801CC648(z);
        z->m1DC[5] = fn_801CC578(z);
        z->m1DC[0] = fn_801CC0CC(z);
    }
    for (int i = 0; i < 6; i++)
        lbl_8068C420.m0[i] = z->m1DC[i];
}

extern "C" void fn_801CC964(Z* z)
{
    z->m1D0 = fn_801CCBE8(z);
    z->m1D4 = fn_801CCA40(z);
    z->m1D8 = z->m1D0 * fn_801D7818(z->m11C, 1) + z->m1D4 * fn_801D7818(z->m11C, 0);
    z->m1D8 = z->m1D8 / fn_801D7828(z->m11C);
    lbl_8068C420.m390 = z->m1D0;
    lbl_8068C420.m394 = z->m1D4;
    lbl_8068C420.m398 = z->m1D8;
    lbl_8068C420.m80 = fn_80235E28(z->m4->m3B0);
    lbl_8068C420.m84 = fn_8022EA60(z->m4->m3B0);
}

extern "C" float fn_801CCA40(Z* z)
{
    V2 v = ((Unk801CAFA0_VaFn)fn_801CD94C)(z);
    float r = 0.0f;
    if (!(v.y >= 0.0f)) {
        const float lo = 0.5f;
        float t = AbsF(v.y);
        t = !(t > 1.3f) ? (t >? lo) : 1.3f;
        t = t - lo;
        t = t * 1.2500001f;
        t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
        r = -t;
    } else {
        const float lo = 0.5f;
        float t;
        t = !(v.y > 1.3f) ? (v.y >? lo) : 1.3f;
        t = t - lo;
        t = t * 1.2500001f;
        t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
        r = t;
    }
    return r;
}

/* near-miss: retail keeps the low bound in f31 across the call (33 vs 34 instructions here). */
extern "C" float fn_801CD068(Z* z)
{
    float r = 0.0f;
    P* p = fn_801A4B34(z->m204);
    if (p) {
        float v = fn_8024EF40(p->mA0C, p->m44C, p->m708);
        r = !(v > 1.0f) ? (v >? 0.0f) : 1.0f;
    }
    return r;
}

/* near-miss: same code; retail schedules the RandF scale slot stores after the file-pointer moves and
 * ends with `li 2; cror; bso; li 1` (ours bns/li 2). */
extern "C" void fn_801CD0F0(Z* z)
{
    if (z->m204->m6F4 == 2) {
        z->m130 = 5;
    } else {
        float x = fn_801CD068(z);
        x = !(x > 1.0f) ? (x >? 0.2f) : 1.0f;
        if (!(x <= RandF(z->m204->m554, 1.0f, 0x1713))) {
            z->m130 = 5;
        } else if (fn_801C8974(z)) {
            if (RandF(z->m204->m554, 1.0f, 0x1720) < 0.5f)
                z->m130 = 3;
            else
                z->m130 = 0;
        } else {
            if (RandF(z->m204->m554, 1.0f, 0x172B) >= 0.5f)
                z->m130 = 2;
            else
                z->m130 = 1;
        }
    }
}

/* near-miss (62 vs 61 instructions): retail emits the 0..3 case block before the case 6 test. */
extern "C" void fn_801CD2CC(Z* z)
{
    fn_801CCE0C(z);
    if (z->m1A8 == 4) {
        fn_801CB344(z);
    } else {
        int one = 1;
        z->m120 = one;
        if (fn_801CDA84(z) == 0)
            z->m1A8 = one;
        switch (z->m1A8) {
        case 0:
        case 1:
        case 2:
        case 3:
            fn_801CB324(z);
            break;
        case 4:
            break;
        case 6:
            z->m1AC = one;
            fn_801CD0F0(z);
            lbl_8068C6C8 = z->m130;
            fn_801CB148(z);
            if (z->m130 == 5)
                fn_801CD400(z);
            else
                fn_801C90AC(z);
            fn_801CA144(z);
            fn_801CA654(z);
            lbl_80691DBC = *(V2*)z->m150;
            break;
        }
    }
}

extern "C" float fn_801CD3C0(Z* z)
{
    P* p = z->m204;
    return fn_801A0AA8(p, fn_801CD068(z), 0.23f);
}

extern "C" float fn_801CD7F4(Z* z)
{
    const float lo = 6.0f;
    const float hi = 84.0f;
    float x = z->m13C;
    P* p = fn_801A4B34(z->m204);
    if (p && p->v4())
        x = -x;
    x = (x + 1.0f) * 0.5f;
    x = !(x > 1.0f) ? (x >? 0.0f) : 1.0f;
    return x * (hi - lo) + lo;
}

extern "C" float fn_801CD8D4(Z* z)
{
    P* c = z->m204->m6CC;
    float f = fn_801CEB34(z);
    P* p = fn_801A4B34(z->m204);
    if (p->v4())
        f = -f;
    return f / c->m438;
}

extern "C" V2 fn_801CD94C(Z* z)
{
    V2 v = fn_8022EA60(z->m4->m3B0);
    float f = fn_801CD8D4(z);
    v.x = v.x - f;
    return v;
}

extern "C" float fn_801CD9BC(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p->v4())
        return -1.5f;
    return -1.25f;
}

extern "C" float fn_801CDA14(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p->v4())
        return 1.25f;
    return 1.5f;
}

extern "C" float fn_801CDA6C(void) { return -1.3f; }

extern "C" float fn_801CDA78(void) { return 1.3f; }

extern "C" int fn_801CDA84(Z* z)
{
    if (z->m204->m6CC->m38C != 2)
        return 0;
    V2 v = ((Unk801CAFA0_VaFn)fn_801CD94C)(z);
    int bad = v.x >= fn_801CDA14(z);
    if (!(v.x > fn_801CD9BC(z)))
        bad = 1;
    if (!(v.y >= ((float (*)(Z*))fn_801CDA6C)(z)))
        bad = 1;
    if (!(v.y <= ((float (*)(Z*))fn_801CDA78)(z)))
        bad = 1;
    return bad ^ 1;
}

extern "C" int fn_801CDB4C(Z* z)
{
    return fn_80289248((Unk80270BA0_X*)fn_801A4B34(z->m204)) != 0;
}

extern "C" int fn_801CDB84(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    Unk801B7FB0_Link* l = p->m618;
    int h = l->m838;
    int v = fn_80380964(l);
    if (h != 0x294A8535 && v != 0x294A8535)
        return 1;
    return 0;
}

extern "C" void fn_801CE974(Z* z)
{
    if (z->m124 != 2) {
        z->m1C8 = 1;
        if (z->m1AC == 0)
            fn_8037893C(&z->m204->m704, 0x65, 0, 0, 0);
    }
}

extern "C" void fn_801CE9CC(Z* z) { z->m1CC = 1; }

extern "C" void fn_801CE9D8(Z* z) { fn_801D7AC4(z->m8, z->m204); }

extern "C" int fn_801CEA00(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p->m934 != 0 && p->m934->m10 == 0x11)
        return 0;
    return 1;
}

extern "C" Vec3 fn_801CEA44(Z* z, int i)
{
    if (i <= 2) {
        if (i < 0)
            i = 0;
    } else
        i = 2;
    return z->m29C[i].a;
}

extern "C" Vec3 fn_801CEA90(Z* z, int i)
{
    if (i <= 2) {
        if (i < 0)
            i = 0;
    } else
        i = 2;
    return z->m29C[i].b;
}

extern "C" int fn_801CEADC(Z* z)
{
    float f = fn_801CEB34(z);
    if (f < -1.0f)
        return 0;
    if (f > 1.0f)
        return 2;
    return 1;
}

inline Vec3 Pos320(P* p) { return p->m320; }

extern "C" float fn_801CEB34(Z* z)
{
    float r = 0.0f;
    P* p = fn_801A4B34(z->m204);
    if (p) {
        float a;
        Vec3 v = Pos320(p);
        a = fn_804028E4(v.x * v.x + v.z * v.z);
        fn_801C34D0(&v, z);
        float b = fn_804028E4(v.x * v.x + v.z * v.z);
        r = b - a;
    }
    return r;
}

extern "C" void fn_801CEE40(Z* z)
{
    if (fn_801C4128(z))
        fn_801D5A50(z->m20C, &z->m13C, &z->m140);
    else
        fn_801C4B14(z, &z->m13C, &z->m140);
    z->m13C = !(z->m13C > 1.0f) ? (z->m13C >? -1.0f) : 1.0f;
    z->m140 = !(z->m140 > 1.0f) ? (z->m140 >? -1.0f) : 1.0f;
    lbl_8068C420.m78 = z->m13C;
    lbl_8068C420.m7C = z->m140;
}
