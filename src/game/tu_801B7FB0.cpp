/*
 * Game code, .text 0x801B7FB0-0x801BAC74 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801B7FB0.h"
#include "game/goals/tu_8027A84C.h"
#include "game/goals/tu_8027C728.h"

typedef Unk801B7FB0_P P;
typedef Unk801B7FB0_Ump U;
typedef Unk801B7FB0_B B;
typedef Unk801B7FB0_Ai A;
typedef Unk801B7FB0_Msg M;

extern "C" {
Vec3 fn_8014E388(int idx);
void fn_803295F0(void);
void fn_80303CA0(const char* fmt, ...);
void fn_801B9620(U* u, const Vec3* v, int ev);
void fn_801B97E8(U* u);
void fn_801B9258(U* u);
void fn_801B9348(U* u);
void fn_801B979C(U* u, P* p);
void fn_80377408(void* p);
int fn_801C1638(P* p, int k);
Vec3 fn_80189618(P* p, float f);
void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
int fn_802BB920(int a);
void fn_80099620(void* t);
void fn_80099704(void* t);
void fn_80099670(void* t);
void fn_801B9A18(B* u, P* a, P* b);
void fn_801B9CE0(B* u, P* a, P* b);
int fn_801B9940(B* u, P* a);
int fn_801B9C5C(B* u);
int fn_801B9CC0(B* u);
void fn_801B9E80(B* u);
void fn_801BA0B8(B* u, P* a);
void fn_801B9838(B* u);
int fn_801C0478(A* a);
void fn_801BAAC8(A* a);
}

/* Goal storage at goal+0x18 (full layout in goals/tu_80287600.h, which declares the
 * vector below const; retail reloads it after calls, so only the method is declared). */
class Unk80287D70 {
public:
    Unk80287D70* fn_80287DB8(int kind);
};
inline Vec3& L() { return (Vec3&)lbl_806055AC; }
inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

extern "C" Unk8027C728_Goal* fn_802448F4(P* p, int k);
void fn_80299B98(P* p, const Vec3* pos, float* ang);
float fn_80410CE8(float y, float x);
void fn_8027C728(Unk8027C728_Goal* g);
void fn_8027D33C(Unk8027C728_Goal* g);
struct Unk801B7FB0_Tbl {
    Vec3 v[2][4];
};
extern Unk801B7FB0_Tbl lbl_805CF9E4;
extern "C" int fn_801B6A44(void);
extern "C" void fn_801B8DF8(P* p, int a);
extern "C" void fn_801B913C(U* u, const Vec3* pos, int k);
extern int lbl_8061CB78;
extern int lbl_8061CB7C;
extern float lbl_8061CB84;
extern float lbl_805CFBA8;
int fn_80088280(Unk80087A58_O* o);

extern const char lbl_805CF95C[];
extern const float lbl_805CF978;
extern const float lbl_805CF97C;
extern const float lbl_805CF980;
extern const float lbl_805CF998;
extern const float lbl_805CF99C;
extern const float lbl_805CF9A0;
extern const char lbl_805CF984[];

extern "C" void fn_801B7FB0(P* p) { fn_801B97E8(p->mB88); }
extern "C" void fn_801B7FD4(P* p) { fn_801B9258(p->mB88); }
extern "C" void fn_801B7FF8(P* p) { fn_801B9348(p->mB88); }

extern "C" void fn_801B801C(P* p, int a)
{
    if (a == 1) {
        Vec3 v = fn_8014E388(3);
        fn_801B9620(p->mB88, &v, 2);
    } else {
        Vec3 v = fn_8014E388(3);
        fn_801B9620(p->mB88, &v, 3);
    }
}

extern "C" void fn_801B8088(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 1);
}

extern "C" void fn_801B80CC(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 0x12);
}

extern "C" void fn_801B8110(P* p, int a)
{
    if (a == 1) {
        Vec3 v = fn_8014E388(3);
        fn_801B9620(p->mB88, &v, 0xC);
    } else {
        Vec3 v = fn_8014E388(3);
        fn_801B9620(p->mB88, &v, 4);
    }
}

extern "C" void fn_801B817C(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 0xC);
}

extern "C" void fn_801B81C0(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 6);
}

extern "C" void fn_801B8204(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 5);
}

extern "C" void fn_801B8248(P* p, const Vec3* a)
{
    Vec3 v = *a;
    fn_801B9620(p->mB88, &v, 0xC);
    p->mB80 = 1.0f;
}

/* near-miss: retail loads the int argument (lwz r4) before the three lis for the float
 * constants and the format string; the scheduler here puts it after. */
extern "C" void fn_801B82AC(P* p, const Vec3* a, P* q, int flag)
{
    Unk801B7FB0_Sub58C* s = &q->m58C;
    if (s->mC != 0.0f)
        fn_80303CA0(lbl_805CF95C, s->m10 + 1, lbl_805CF978, lbl_805CF97C, lbl_805CF980);
    if (flag == 1) {
        Vec3 v = *a;
        fn_801B9620(p->mB88, &v, 0xD);
    } else {
        Vec3 v = *a;
        fn_801B9620(p->mB88, &v, 0xC);
    }
    fn_803295F0();
}

extern "C" void fn_801B838C(P* p, const Vec3* a, P* q, int flag)
{
    if (q->m5A0 != 0.0f)
        fn_80303CA0(lbl_805CF984, lbl_805CF998, lbl_805CF99C, lbl_805CF9A0);
    if (p->mB88->m8 != q) {
        if (p->m44C->m6F8->m14->m1CCB <= 3) {
            if (flag == 1) {
                Vec3 v = *a;
                fn_801B9620(p->mB88, &v, 0xB);
            } else {
                Vec3 v = *a;
                fn_801B9620(p->mB88, &v, 0xA);
            }
        }
        fn_801B979C(p->mB88, q);
    }
}

extern "C" void fn_801B848C(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 0xE);
}

extern "C" void fn_801B84D0(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 0xF);
}

extern "C" void fn_801B8514(P* p)
{
    Vec3 v = fn_8014E388(3);
    fn_801B9620(p->mB88, &v, 0xF);
}

extern "C" void fn_801B8D1C(P* p, int a)
{
    int r = fn_801B6A44();
    if (r == 2) {
        fn_801B8DF8(p, a);
        return;
    }
    Unk801B7FB0_Tbl tbl = lbl_805CF9E4;
    Vec3 v = tbl.v[a][r];
    fn_801B913C(p->mB88, &v, 1);
}

extern "C" void fn_801B9004(P* p) { p->mB88->m0 = 0; }
extern "C" void fn_801B9014(U* u, P* p) { u->m4 = p; }
extern "C" void fn_801B901C(U* u)
{
    u->m8 = 0;
    u->mC = 0.0f;
}

extern "C" void fn_801B9034(void* p, int f)
{
    if (f & 1)
        fn_80377408(p);
}

extern "C" void fn_801B905C(U* u)
{
    P* t = u->m8;
    if (t) {
        if (t->m5C8 == -1)
            fn_801B97E8(u);
        else if (!((float)u->m4->m44C->m4C * 0.016666668f - u->mC <= 5.0f))
            fn_801B97E8(u);
    }
    {
        P* o = u->m4;
        if (!(o->mB84 <= 0.0f)) {
            o->mB84 = o->mB84 - 1.0f;
            P* o2 = u->m4;
            if (o2->mB84 == 0.0f)
                o2->mB80 = 1.0f;
        }
    }
}

extern "C" void fn_801B913C(U* u, const Vec3* pos, int k)
{
    int two = 2;
    int ten = 0xA;
    float ang = fn_80410CE8(L().x - pos->x, L().z - pos->z);
    fn_80299B98(u->m4, pos, &ang);
    Unk8027C728_Goal* g = fn_802448F4(u->m4, 1);
    g->m10 = two;
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    fn_8027C728(g);
    Unk8027A84C* b = (Unk8027A84C*)((Unk80287D70*)g->m18)->fn_80287DB8(0xF);
    Vec3 v = L() - *pos;
    b->fn_8027A898(&v);
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = two;
    g104->m38 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = two;
    g104->m34 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
    g104->m40 = ten;
    fn_8027D33C(g);
}

extern "C" void fn_801B9258(U* u)
{
    int two = 2;
    int ten = 0xA;
    Unk8027C728_Goal* g = fn_802448F4(u->m4, 1);
    g->m10 = two;
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    fn_8027C728(g);
    Unk8027A84C* b = (Unk8027A84C*)((Unk80287D70*)g->m18)->fn_80287DB8(0xE);
    Vec3 v = L() - u->m4->m60;
    b->fn_8027A898(&v);
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = two;
    g104->m38 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = two;
    g104->m34 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
    g104->m40 = ten;
    fn_8027D33C(g);
}

extern "C" void fn_801B9348(U* u)
{
    int two = 2;
    int ten = 0xA;
    Unk8027C728_Goal* g = fn_802448F4(u->m4, 1);
    g->m10 = two;
    Unk8027A84C* g104 = (Unk8027A84C*)g->m104;
    fn_8027C728(g);
    Unk8027A84C* b = (Unk8027A84C*)((Unk80287D70*)g->m18)->fn_80287DB8(0xF);
    Vec3 v = L() - u->m4->m60;
    b->fn_8027A898(&v);
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = two;
    g104->m38 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m34 = two;
    g104->m34 = two;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = ten;
    g104->m40 = ten;
    fn_8027D33C(g);
}

extern "C" void fn_801B979C(U* u, P* p)
{
    u->m8 = p;
    u->mC = (float)u->m4->m44C->m4C * 0.016666668f;
}

extern "C" void fn_801B97E8(U* u)
{
    u->m8 = 0;
    u->mC = 0.0f;
}

extern "C" B* fn_801B9800(B* u, P* p, A* q)
{
    u->m4 = p;
    u->m8 = q;
    fn_801B9838(u);
    return u;
}

extern "C" void fn_801B9838(B* u)
{
    u->mC = 2;
    u->m24 = 0.0f;
    u->m0 = -1;
    u->m2C = 6;
    u->m10 = 0;
    u->m14 = 0;
    u->m28 = 0;
    u->m30 = 0;
    u->m18 = 0;
    u->m1C = 0;
    u->m20 = 0;
}

extern "C" void fn_801B9880(B* u, P* q)
{
    u->m14 = 0;
    P* p = u->m4;
    int a = 1;
    int b = p->m6F8->m14->m1CC9;
    if (fn_801C1638(p, 0xA) == 0)
        a = 0;
    int c = fn_801C1638(u->m4, 0xB) != 0 ? 1 : 0;
    if (b <= 1 && a != 0 && c != 0) {
        Vec3 v = fn_80189618(q, lbl_805CFBA8);
        if (!(v.y <= lbl_805CFBA8))
            u->m14 = 1;
    }
}

extern "C" int fn_801B9940(B* u, P* q)
{
    int k = fn_8025416C(&q->m588, 5);
    int t = q->m708;
    P* p = u->m4;
    if (t > 2) {
        int x = 0;
        if (p->m6F8->m14->m1CD0 != 0)
            x = 1;
        int y = x;
        if (t != 3)
            y ^= 1;
        t = y;
    }
    if (k == 0 || k == 10) {
        if (q->m458 == 9)
            fn_80099620(&p->m6F8->m14->t[t]);
        else
            fn_80099704(&p->m6F8->m14->t[t]);
    } else
        fn_80099670(&p->m6F8->m14->t[t]);
}

extern "C" int fn_801B9C5C(B* u)
{
    Unk801B7FB0_Game* g = u->m4->m6F8;
    int k = fn_80088280(g->mC->mC);
    int r = 0;
    if ((k == 0xB || k == 0xE) && g->m14->m1CCA == 0)
        r = 1;
    return r;
}

extern "C" int fn_801B9CC0(B* u) { return u->m4->m6F8->m14->m1CCA == 1; }
extern "C" void fn_801B9E04(B* u, P* q)
{
    P* t = u->m4->m65C[0];
    if (t && fn_801B9940(u, t)) {
        if (u->m30 == 0)
            fn_801B9A18(u, t, q);
        else
            fn_801B9CE0(u, t, q);
    }
}

extern "C" void fn_801B9E80(B* u)
{
    P* p = u->m4;
    u->m30 = 1;
    fn_8037893C(&p->m704, 0x3C, 0, 0, 0);
}

extern "C" void fn_801BA288(B* u, unsigned i)
{
    if (i <= 1) {
        Unk801B7FB0_Team* e = &u->m4->m6F8->m14->t[i];
        e->m108 = 1;
    }
}

extern "C" void fn_801BA4A8(void) {}
extern "C" void fn_801BA4AC(void) {}
extern "C" int fn_801BA9A4(B* u) { return u->m28 == 4; }
extern "C" int fn_801BA9B8(B* u) { return u->m28 == 2; }
extern "C" int fn_801BA958(B* u) { return u->m24 < 0.0f; }
extern "C" int fn_801BA974(B* u)
{
    int r = 0;
    if (!(u->m24 < 0.0f))
        r = u->m24 < lbl_8061CB84;
    return r;
}

extern "C" void fn_801BAAC8(A* a)
{
    a->m18 = 0;
    a->m1C = 0;
    a->m20 = 0;
    a->m24 = 0;
    a->m28 = 0.0f;
    a->m2C = 0.0f;
    a->m30 = 0.0f;
    a->m34 = 0.0f;
    a->m68 = fn_801C0478(a);
    fn_801B9838(a->m8);
    lbl_8061CB78 = 0;
    lbl_8061CB7C = 0;
}

extern "C" void fn_801BAB3C(A* a) { fn_801BAAC8(a); }
extern "C" void fn_801BA0B8(B* u, P* q)
{
    M m;
    m.Base(0x79);
    m.Derived2(q->m708, q->m704);
    fn_8037893C(&u->m4->m704, m.m0, &m, 0, 0);
    m.End();
}
