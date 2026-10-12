/*
 * Game code, .text 0x801BDD60-0x801C16B0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801BDD60.h"

typedef Unk801B7FB0_P P;
typedef Unk801B7FB0_B B;
typedef Unk801B7FB0_Ai A;
typedef Unk801BDD60_O8 O;

extern "C" {
void fn_801BDB84(B* b, P* p, int a, int c, const Vec3* v);
void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
void fn_8017B658(void* p, int k);
P* fn_801A4C74(P* ctx, int i);
int fn_801BCA0C(A* a, P* p);
void fn_801BCF88(A* a, int x, P* p);
void fn_80377408(void* p);
P* fn_801C01E4(O* o, int i);
P* fn_801C0248(O* o, const Vec3* v);
void fn_801B8204(P* p);
void fn_801B801C(P* p, int a);
void fn_801B8088(P* p);
void fn_801B80CC(P* p);
void fn_801B8110(P* p, int a);
void fn_801B81C0(P* p);
void fn_801B817C(P* p);
void fn_801B8248(P* p, const Vec3* v);
void fn_801B848C(P* p);
void fn_801B84D0(P* p);
void fn_801B8514(P* p);
void fn_801B8558(P* p);
void fn_801B8874(P* p);
void fn_801B82AC(P* p, const Vec3* a, P* q, int flag);
void fn_801B838C(P* p, const Vec3* a, P* q, int flag);
int fn_801BBC54(A* a);
}
struct Unk801BDD60_Sim {
    char pad0[0x3BC];
    A* m3BC;
};

extern Vec3 lbl_806055AC;
extern Vec3 lbl_805D0058;
extern float lbl_8061CBB8;
extern "C" float fn_804028E4(float x);
extern const char lbl_805CF874[];
extern const char lbl_805CFECC[];
extern const char lbl_805CFED8[];
extern const char lbl_805CFEE8[];
extern const char lbl_805CFEF8[];
extern const char lbl_805CFF08[];
extern const char lbl_805CFF20[];
extern const char lbl_805CFF38[];
extern const char lbl_805CFF50[];
extern const char lbl_805CF8A4[];
extern int lbl_8068BF04;
extern const char lbl_805CBCEC[];
extern int lbl_8061CB4C;
extern "C" {
void fn_8040B320(void* p, int v, ...);
const char* fn_801C160C(void);
}

inline Unk801B7FB0_Slot* At(Unk801B7FB0_Slot* a, int i) { return &a[i]; }
extern "C" {
int fn_80254EA4(void* p, int k);
void fn_80327100(void* p, int a, int b, int c, float f1, float f2);
}

extern "C" void fn_801BDD60(B* b, P* p)
{
    if (p->m38C == 1 && b->m0 == -1) {
        Vec3 v = lbl_806055AC;
        fn_801BDB84(b, p, 0, 0, &v);
    }
}

extern "C" void fn_801BDDC8(B* b, P* p)
{
    b->m0 = 0;
    b->mC = 1;
    b->m2C = 6;
    if (p->m38C == 1)
        fn_8037893C(&b->m4->m704, 0x47, 0, 0, 0);
}

extern "C" void fn_801BDE24(B* b)
{
    b->m0 = 1;
    fn_8017B658(b->m4->m700, 5);
}

extern "C" void fn_801BE430(B* b)
{
    P* t = b->m4->m6CC->m36C;
    if (t) {
        int r = fn_801BCA0C(b->m8, t);
        if (r != -1) {
            t->m730 = r;
            fn_801BCF88(b->m8, r, t);
        }
    }
}

extern "C" void fn_801BF66C(A* a, void* x, int idx)
{
    if (idx != -1) {
        float t = (float)a->m14->m4C * 0.016666668f;
        Unk801B7FB0_Slot* s = (Unk801B7FB0_Slot*)((char*)a + idx * 12 + 0x38);
        s->m0 = x;
        s->m4 = 0;
        s->m8 = t;
    }
}

extern "C" void fn_801BF6D4(A* a, P* p, int idx)
{
    if (idx != -1) {
        int k = 2;
        if (fn_80254EA4(&p->m58C, 0) == idx)
            k = 1;
        float t = (float)a->m14->m4C * 0.016666668f;
        Unk801B7FB0_Slot* s = At(a->m38, idx);
        s->m0 = p;
        s->m4 = k;
        s->m8 = t;
    }
}

extern "C" int fn_801BFA20(const Vec3* v)
{
    int r = 0;
    if (v->x < 0.0f || !(v->z >= 0.0f))
        r = 1;
    return r;
}

inline float Len3(const Vec3& v) { return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z); }

extern "C" int fn_801BFA54(const Vec3* v)
{
    Vec3 d = *v - lbl_805D0058;
    return Len3(d) <= lbl_8061CBB8;
}

extern "C" int fn_801BFAF8(const Vec3* v)
{
    int r = 0;
    if (v->x > 1065.0f || v->z > 1065.0f || v->z < -48.0f || !(v->x >= -48.0f))
        r = 1;
    return r;
}

extern "C" O* fn_801BFB44(O* o, P* p, A* a)
{
    o->m0 = p;
    o->m4 = a;
    return o;
}

extern "C" void fn_801BFB54(void* p, int f)
{
    if (f & 1)
        fn_80377408(p);
}

extern "C" void fn_801BFB7C(O* o)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B8204(p);
}

extern "C" void fn_801BFBAC(O* o, int a)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B801C(p, a);
}

extern "C" void fn_801BFBEC(O* o)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B8088(p);
}

extern "C" void fn_801BFC1C(O* o)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B80CC(p);
}

extern "C" void fn_801BFC4C(O* o, int a)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B8110(p, a);
}

extern "C" void fn_801BFC8C(O* o)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B81C0(p);
}

extern "C" void fn_801BFCBC(O* o)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B817C(p);
}

extern "C" void fn_801BFCEC(O* o, P* q)
{
    const Vec3* pos = &q->m60;
    Vec3 v = *pos;
    P* p = fn_801C0248(o, &v);
    if (p) {
        v = *pos;
        fn_801B8248(p, &v);
    }
}

extern "C" void fn_801BFEC0(O* o, P* q, int mode)
{
    const Vec3* pos = &q->m60;
    Vec3 v = *pos;
    P* p = fn_801C0248(o, &v);
    if (p) {
        if (mode == 1) {
            v = *pos;
            fn_801B82AC(p, &v, q, 1);
        } else if (fn_801BBC54(((Unk801BDD60_Sim*)o->m0->m700)->m3BC) == 1) {
            v = *pos;
            fn_801B838C(p, &v, q, 0);
        } else {
            v = *pos;
            fn_801B838C(p, &v, q, 1);
        }
    }
}

extern "C" void fn_801BFFCC(O* o, P* q)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B848C(p);
    Vec3 v = q->m60;
    p = fn_801C0248(o, &v);
    if (p)
        fn_801B848C(p);
}

extern "C" void fn_801C0044(O* o, P* q)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B84D0(p);
    Vec3 v = q->m60;
    p = fn_801C0248(o, &v);
    if (p)
        fn_801B84D0(p);
}

extern "C" void fn_801C00BC(O* o, P* q)
{
    P* p = fn_801C01E4(o, 3);
    if (p)
        fn_801B8514(p);
    Vec3 v = q->m60;
    p = fn_801C0248(o, &v);
    if (p)
        fn_801B8514(p);
}

/* near-miss: same code; retail loads v.z (f13) before the first compare, ours after the branch. */
extern "C" void fn_801C0134(O* o, P* q)
{
    P* a = 0;
    P* b = 0;
    Vec3 v = q->m60;
    int xp = v.x > 0.0f;
    if (!xp) {
        if (!(v.z <= 0.0f))
            a = fn_801C01E4(o, 0);
    } else
        b = fn_801C01E4(o, 2);
    if (a)
        fn_801B8558(a);
    else if (b)
        fn_801B8874(b);
}

extern "C" P* fn_801C01E4(O* o, int i)
{
    int j;
    switch (i) {
    case 0:
        j = 1;
        break;
    case 1:
        j = 2;
        break;
    case 2:
        j = 3;
        break;
    default:
        j = 0;
        break;
    }
    return fn_801A4C74(o->m0, j);
}

extern "C" P* fn_801C0248(O* o, const Vec3* v)
{
    float best = 0.0f;
    int bi = -1;
    int j = 0;
    do {
        P* p = fn_801A4C74(o->m0, j);
        Vec3 d = *v - p->m60;
        float dist = d.x * d.x + d.z * d.z;
        if (bi == -1 || !(dist >= best)) {
            best = dist;
            bi = j;
        }
        j++;
    } while (j <= 3);
    return fn_801A4C74(o->m0, bi);
}

Unk801C0334::Unk801C0334()
    : Unk8037B3E8(0xD1E132A4U)
{
}

void Unk801C0334::fn_vslot2()
{
    fn_8037B7E4(lbl_805CF874);
    fn_8037B7E8(lbl_805CFECC);
    fn_8037B50C(lbl_805CFED8, &m4, lbl_805CFEE8, 0);
    fn_8037B50C(lbl_805CFEF8, &m8, lbl_805CF8A4, 0);
    fn_8037B50C(lbl_805CFF08, &mC, lbl_805CF8A4, 0);
    fn_8037B50C(lbl_805CFF20, &m10, lbl_805CF8A4, 0);
    fn_8037B50C(lbl_805CFF38, &m14, lbl_805CF8A4, 0);
    fn_8037B50C(lbl_805CFF50, &m18, lbl_805CF8A4, 0);
    fn_8037B830(lbl_805CFECC);
}

extern "C" int fn_801C0478()
{
    return fn_8037C7FC()->fn_8037CE98(0xD1E132A4U, lbl_8068BF04, 0);
}

Unk8037B3E8* Unk801C0334::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk801C0334;
}

float Unk801C0334::fn_801C04E0(int base)
{
    switch (base) {
    case 0:
        return mC;
    case 1:
        return m10;
    case 2:
        return m14;
    case 3:
        return m18;
    default:
        return 0.0f;
    }
}

extern "C" void fn_801C156C(void) {}

extern "C" void fn_801C1570(void) {}

extern "C" void fn_801C1574(void) {}

extern "C" int fn_801C1578(void) { return 0; }

extern "C" Vec3 fn_801C1580(void)
{
    Vec3 v;
    Vec3* p = &v;
    fn_8040B320(p, 0, 12);
    return *p;
}

extern "C" void fn_801C15DC(void) {}

extern "C" const char* fn_801C15E0(void) { return fn_801C160C(); }

extern "C" unsigned fn_801C1600(void) { return 0xEF8A9748; }

extern "C" const char* fn_801C160C(void) { return lbl_805CBCEC; }

extern "C" int fn_801C1618(void) { return lbl_8061CB4C; }

extern "C" unsigned fn_801C1624(void) { return 0x575DF764; }

extern "C" void fn_801C1630(void) {}

extern "C" void fn_801C1634(void) {}

extern "C" P* fn_801C1638(P* p, unsigned i)
{
    if (i <= 0xC)
        return p->m65C[i];
    return 0;
}

struct Unk80308874_B8 {
    char pad0[0x98];
    const void* m98;
    char pad9C[0xB8 - 0x9C];
    const void* mB8;
};

extern char lbl_8065FF08[];

extern char lbl_8065FF98[];

extern "C" void fn_8026C864(void* p, int c);

extern "C" void fn_801C1658(Unk80308874_B8* p, int c)
{
    p->mB8 = lbl_8065FF08;
    p->m98 = lbl_8065FF98;
    fn_8026C864(p, c);
}


extern "C" int fn_801C1690(void) { return 0; }

extern "C" void fn_801C1698(float f) {}

extern "C" void fn_801C16A8(void) {}

extern "C" void fn_801C16AC(void) {}
