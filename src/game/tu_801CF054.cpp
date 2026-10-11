/*
 * Game code, .text 0x801CF054-0x801D31D8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801CF054.h"
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
void fn_80303CA0(const char* fmt, ...);
void fn_8035B1C8(void* p);
void fn_801D6FE4(void* p);
void fn_801D5CF0(Y* y);
int fn_8022F138(void* p);
}

inline void SetMode(Unk801C16B0_Mode* m, int v)
{
    if (m->m0 != 0)
        m->m4 = v;
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

extern "C" int fn_801D0B48(Y* y)
{
    Unk801CF054_T* t = lbl_8068B618;
    P* p = GetP(t->m8, t->m8[0] == y->m30);
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

extern "C" float fn_801D18B4(void)
{
    char buf[16];
    return 0.0f;
}
