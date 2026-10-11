/*
 * Game code, .text 0x801CAFA0-0x801CF054 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801CAFA0.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Z Z;
typedef Unk801CAFA0_V2 V2;

extern "C" {
void fn_801CB360(Z* z);
P* fn_801A4B34(P* ctx);
float fn_8024F20C(void* a, int b, P* c, int d, int e);
float fn_8024F048(void* a, int b, P* c, int d, int e);
float fn_80235DA8(void* p);
float fn_801CD068(Z* z);
float fn_801A0AA8(P* p, float f1, float f2);
int fn_80380964(Unk801B7FB0_Link* l);
void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
void fn_801D7AC4(void* p, P* q);
float fn_801CEB34(Z* z);
}
int fn_80289248(Unk80270BA0_X* x);
extern V2 lbl_8060558C;

extern "C" void fn_801CB324(Z* z) { fn_801CB360(z); }

extern "C" void fn_801CB344(Z* z) { *(V2*)z->m150 = lbl_8060558C; }

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

extern "C" float fn_801CBFC8(Z* z)
{
    float v = fn_80235DA8(z->m4->m3B0);
    v = !(v > 1.0f) ? (v >? 0.0f) : 1.0f;
    return v;
}

extern "C" float fn_801CD3C0(Z* z)
{
    P* p = z->m204;
    return fn_801A0AA8(p, fn_801CD068(z), 0.23f);
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
