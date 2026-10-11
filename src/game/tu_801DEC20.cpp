/*
 * Game code, .text 0x801DEC20-0x801E2D84 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801DB948.h"

typedef Unk801DB948 W;
typedef Unk801DD660 I;
typedef Unk801DB948_Vec3 Vec3;
typedef Unk801DD660_Rec Rec;
typedef Unk8035B718 Tbl;
typedef Unk80270BA0_X P;

extern const Vec3 lbl_806055AC;
extern const float lbl_805D3B3C;

extern "C" {
void fn_801E9AC4(I* i);
void fn_8014E09C(Unk801DB948_It* it, Unk801DB948_Game* g, int k);
P* fn_801A497C(Unk801DB948_Game* g, int a, int b);
void fn_801DF5C8(I* i, Rec* r, P* p);
void fn_801E0F00(I* i, Tbl* t);
void fn_801E11C8(I* i, Tbl* t);
void fn_801DF7A0(I* i, Rec* r, P* p);
void fn_801DFF5C(I* i, Rec* r, P* p);
Unk801DB948_Rt* fn_801A6DB8(Unk801DB948_Game* g);
void fn_801E1638(I* i);
int fn_801BBC0C(int x);
void fn_801E9E20(I* i);
void fn_801E9EE8(I* i, Tbl* t);
void fn_801DD420(Unk801DD660_Sub2* s);
int fn_8020543C(Unk801DD660_Ctx* c);
void fn_801DF134(I* i, Rec* r, P* p);
void fn_801DFFEC(I* i, Rec* r, P* p);
Unk801DB948_Vec4 fn_801E6E7C(I* i, int idx, int k);
int fn_801E08E0(I* i, P* p, Unk801DB948_Vec4* v);
int fn_8026DAE8(P* p, int a);
Unk801DB948_Q* fn_80244C84(P* p);
Vec3 fn_801E0A6C(I* i, P* p, const void* v, int w);
void fn_8035B710(Rec* r, int a);
void fn_801DD4A8(Unk801DD660_Sub2* s, int a, int b);
void fn_8024A678(P* p);
void fn_801EA390(I* i, int a, int b);
int fn_801C3F00(void* x);
int fn_801E0684(I* i, Rec* r, P* p);
int fn_801E06F8(I* i, Rec* r, P* p);
int fn_801A99B4(int x);
void fn_801E1274(I* i, Tbl* t, int k);
void fn_802D7B88(int k, int a, int b, float f);
}

extern const float lbl_805D3C0C;
extern const float lbl_805D3C10;
extern const float lbl_805D3C14;
extern const float lbl_805D3B40;
extern const float lbl_805D3B44;
extern const float lbl_805D3BA4;

extern "C" void fn_801DEC20(I* i, Tbl* t)
{
    int b = i->m9C->m0->m6CC->m38C == 2;
    if (b == 1) {
        i->m168 = 6;
        fn_801E9AC4(i);
        i->m788 = 1;
        i->m77C = lbl_806055AC;
        i->m790 = lbl_805D3B3C;
        i->m78C = 0;
    }
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 2);
    while (it.Cur() != 10) {
        Rec* r = &t->m0[it.Cur()];
        P* p = fn_801A497C(i->m9C->m0, 4, it.Cur());
        if (p != 0)
            fn_801DF5C8(i, r, p);
        it.Next();
    }
    fn_801E0F00(i, t);
    fn_801E11C8(i, t);
}

extern "C" void fn_801DED34(I* i, Tbl* t)
{
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 2);
    Unk801DB948_It* ip;
    if (it.m8 != 10) {
        do {
            ip = &it;
            Rec* r = &t->m0[ip->m8];
            P* p = fn_801A497C(i->m9C->m0, 4, ip->m8);
            if (p != 0) {
                if (ip->m8 == 1)
                    fn_801DF7A0(i, r, p);
                else
                    fn_801DFF5C(i, r, p);
            }
            fn_8014E108(&it);
        } while (ip->m8 != 10);
    }
    fn_801E0F00(i, t);
    fn_801E11C8(i, t);
}

extern "C" void fn_801DEE04(I* i, Tbl* t)
{
    if (fn_801A6DB8(i->m9C->m0)->m4 == 1) {
        fn_801E1638(i);
        if (fn_801BBC0C(i->m9C->m0->m700->m3BC) == 1)
            fn_801E9E20(i);
        fn_801E9EE8(i, t);
    }
}

extern "C" void fn_801DEE80(I* i, Tbl* t)
{
    fn_801DD420(&i->m134);
    fn_801E1638(i);
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 1);
    Unk801DB948_It* ip;
    if (it.m8 != 10) {
        do {
            ip = &it;
            Rec* r = &t->m0[ip->m8];
            P* p = fn_801A497C(i->m9C->m0, 4, ip->m8);
            if (p != 0) {
                if (fn_8020543C(i->m9C) > 2)
                    fn_801DF134(i, r, p);
                else
                    fn_801DFFEC(i, r, p);
            }
            fn_8014E108(&it);
        } while (ip->m8 != 10);
    }
}

extern "C" void fn_801DEF4C(I* i, Tbl* t)
{
    int ok = 1;
    fn_801DD420(&i->m134);
    fn_801E1638(i);
    if (!(i->m778 <= lbl_805D3B40))
        i->m778 = i->m778 - lbl_805D3B44;
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 1);
    Unk801DB948_It* ip;
    if (it.m8 != 10) {
        do {
            ip = &it;
            Rec* r = &t->m0[ip->m8];
            P* p = fn_801A497C(i->m9C->m0, 4, ip->m8);
            p->m710 = p->m60;
            int res;
            if (ip->m8 == 0)
                res = fn_801E0684(i, r, p);
            else
                res = fn_801E06F8(i, r, p);
            int a = 1;
            if (ok == 0)
                a = 0;
            int b = 1;
            if (res == 0)
                b = 0;
            ok = a & b;
            fn_8014E108(&it);
        } while (ip->m8 != 10);
    }
    if (ok == 1)
        i->m168 = 3;
}

static inline void Put(Vec3* d, const Vec3& s) { *d = s; }
/* near-miss: copy schedule differs by register order of the two Vec3 copies (12 slots) */
extern "C" void fn_801DF08C(I* i, Rec* r, P* p)
{
    Unk801DB948_Vec4 v = ((Unk801DB948_Vec4 (*)(I*, int))fn_801E6E7C)(i, p->m460);
    Vec3 w = fn_801E0A6C(i, p, &v, v.w);
    r->m4 = 2;
    Put(&r->m28, v);
    Put(&r->m64, w);
    fn_8035B710(r, 1);
}

extern "C" void fn_801DFF5C(I* i, Rec* r, P* p)
{
    r->m4 = 4;
    r->mC = 3;
    Vec3 w = fn_801E0A6C(i, p, &p->m60, 0);
    r->m64 = w;
    fn_8035B710(r, 1);
    fn_801DD4A8(&i->m134, p->m460, 0);
}

extern "C" int fn_801E0684(I* i, Rec* r, P* p)
{
    r->m4 = 3;
    Vec3 w = fn_801E0A6C(i, p, &p->m60, 0);
    r->m64 = w;
    fn_8035B710(r, 1);
    return 1;
}

/* near-miss: retail keeps the 2/7 select in r0 and stores it before the Vec3 copy (r8 here) */
extern "C" int fn_801E06F8(I* i, Rec* r, P* p)
{
    int res = 1;
    Unk801DB948_Vec4 v = fn_801E6E7C(i, p->m460, 1);
    if (fn_801E08E0(i, p, &v) == 1) {
        r->m4 = 3;
        r->mC = 2;
        Vec3 w = fn_801E0A6C(i, p, &v, v.w);
        Put(&r->m64, w);
        fn_8035B710(r, 1);
    } else {
        res = 0;
        r->m4 = !(i->m778 <= lbl_805D3BA4) ? 7 : 2;
        Put(&r->m28, v);
        Vec3 w = fn_801E0A6C(i, p, &v, v.w);
        Put(&r->m64, w);
        fn_8035B710(r, 1);
    }
    return res;
}

/* near-miss: retail computes ((m4C ^ 1) == 0) ^ 1 with xori/subfic/adde; fold rewrites it to != 1 */
extern "C" int fn_801E0834(I* i, P* p, Unk801DB948_Vec4* v)
{
    int r = 2;
    if (fn_801E08E0(i, p, v) == 1) {
        r = 1;
        if (fn_8026DAE8(p, 0) != 0) {
            Unk801DB948_Q* q = fn_80244C84(p);
            Unk801DB948_QS* y;
            if (q != 0) {
                y = 0;
                if (q->m10 == 2)
                    y = &q->m18;
            } else
                y = 0;
            int f = 0;
            if (y != 0)
                f = (((y->m4C ^ 1) == 0) ^ 1);
            if (f == 1)
                r = 0;
        }
    }
    return r;
}

extern "C" void fn_801E11C8(I* i, Tbl* t)
{
    if (i->m9C->m0->m6F4 == 0 && fn_801C3F00(i->m9C->m0->m700->m3A4) == 1) {
        if ((unsigned)(fn_801A99B4(i->m9C->m0->m700->m3C4) - 12) <= 1)
            fn_801E1274(i, t, 2);
        else if (i->m9C->m0->m688 == 0)
            fn_801E1274(i, t, 4);
    }
}

extern "C" void fn_801E1638(I* i)
{
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 1);
    while (it.Cur() != 10) {
        P* p = fn_801A497C(i->m9C->m0, 4, it.Cur());
        if (p != 0)
            fn_8024A678(p);
        it.Next();
    }
}

extern "C" void fn_801E16B0(I* i, int a, int b)
{
    fn_801EA390(i, a, b);
}

extern "C" void fn_801E16D0(int a, int k, float f)
{
    if (k != -1) {
        float u = f * lbl_805D3C0C;
        u = !(u > lbl_805D3C10) ? (u >? lbl_805D3C14) : lbl_805D3C10;
        fn_802D7B88(k, 1, 8, u);
    }
}

extern "C" int fn_801E1A04()
{
    return 0;
}
