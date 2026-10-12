/*
 * Game code, .text 0x80310934-0x80313C14 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

extern char lbl_806657A8[];
extern char lbl_80665748[];
extern char lbl_806656E8[];
extern const char lbl_805E9474[];
extern const char lbl_805E9478[];
extern const char lbl_805E9484[];
extern unsigned int lbl_8061FE88;
extern unsigned int lbl_8061FE1C;
extern int lbl_8061FE20;
extern int lbl_8061FE84;
extern int lbl_8061FF74;
extern void* lbl_8061E978;
extern int lbl_8061F94C;
extern char lbl_8068E1C0[];

struct Unk80310934_At0 {
    const void* m0;
};
struct Unk80310934_At1C {
    const void* m0;
    char pad4[0x1C - 4];
    int m1C;
    char pad20[0x20 - 0x20];
};
struct Unk80310934_V3 {
    int a;
    int b;
    int c;
};
struct Unk80310934_F3 {
    float x;
    float y;
    float z;
};
struct Unk80310934_Cp {
    char pad0[0x20];
    Unk80310934_V3 m20;
    char pad2C[0x3C - 0x2C];
    Unk80310934_V3 m3C;
};
struct Unk80310934_I0 {
    int m0;
};
struct Unk80310934_Z {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
struct Unk80310934_O1C {
    char pad0[0x1C];
    int m1C;
};
struct Unk80310934_Hd {
    char pad0[4];
    int m4;
};
struct Unk80310934_P60 {
    char pad0[0x38];
    Unk80310934_Hd* m38;
    char pad3C[0x60 - 0x3C];
    int m60;
};
struct Unk80310934_P10 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Unk80310934_X24 {
    char pad0[0x24];
    void* m24;
};
struct Unk80310934_P38 {
    char pad0[0x38];
    Unk80310934_X24* m38;
};
struct Unk80310934_P1F8 {
    char pad0[0x1F8];
    int m1F8;
};

struct Unk80310934_Bx {
    char pad0[0x10];
    int m10;
    int m14;
    char pad18[4];
    int m1C;
    int m20;
};
class Unk80310934_ScV {
public:
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual ~Unk80310934_ScV();
};
class Unk80310934_Sc : public Unk80310934_ScV {
public:
    char pad4[0x38 - 4];
    Unk80310934_Hd* m38;
};
extern Unk80310934_Sc* lbl_8061FEDC;
extern char lbl_80634B54[];
extern char lbl_80634AA0[];

struct lbl_Node;
class lbl_Owner {
public:
    char pad0[0x8];
    void* m8;
    void fn_803DA098(lbl_Node* node);
};
struct Unk803D7ED4Item;
class Unk803D7ED4Pool {
public:
    char pad0[0xC];
    Unk803D7ED4Item* mC;
    void fn_803D803C(Unk803D7ED4Item* item);
};
struct Unk80310934_Sd {
    lbl_Node* m0;
    lbl_Owner* m4;
    void* m8;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
};
struct Unk80310934_Big {
    int w[40];
};
int fn_803D81FC();
Unk80310934_Big* fn_80311508(void* p, int a, int b, int c, int d);

struct Unk80310934_Mx {
    char pad0[4];
    float v[4][30];
};
extern "C" double atof(const char* s);

extern "C" {
void VISetBlack(int b);
void VIFlush(void);
void VIWaitForRetrace(void);
void fn_80436F58(int a);
void fn_803D9DDC(int h, void* p, int n);
void fn_803D8918(int h);
void fn_803D9E70(int h, int a, int b, int c, int d, int e, int f, int g, int s);
void fn_803D9ECC(int h, int a, int b, int c, int d);
void fn_80314894(int a, int b, int c, int d, int e, int f);
void* fn_8030FECC(void* p);
void fn_8037B424(void* p, int c);
void* fn_80356798(void* p);
void fn_8040074C(void* p, int n);
void fn_802AD538(void* p, int k);
void fn_80311A70(Unk80310934_At0* p, int c);
void fn_80377408(void* p);
void fn_803DD73C(void* h, int k);
void fn_80359A40(void* p);
void fn_80312018(Unk80310934_I0* p);
int fn_8031228C(void* p);
void fn_80319CD4(void* p);
void fn_80319D20(void* p);
void fn_803D983C(int h, int k);
int fn_803D986C(int h, int* out);
int fn_803ED604(int b, int a, int k);
void fn_803FFC58(int a, unsigned int tag, int b);
int fn_803EE310(int a);
void fn_803EDA0C(int a);
int fn_803DBD84(void* p, int k);
void fn_803198B8(void* p, int k);
void fn_803120CC(void* p, int a, int b, int c, int d, int e);
void fn_803DD7C8(void* p, int k);
void fn_802B0C44(void* p, int k);
}

void* fn_80311A28(void* p);
void fn_803123E0(Unk80310934_Bx* p, int a);
Unk80310934_O1C* fn_80311F2C();

void* fn_80310934()
{
    return fn_8030FECC(operator new(0x115C, lbl_806EF9B4));
}

void fn_80310964(Unk80310934_F3* out, Unk80310934_V3* in, float* s)
{
    out->x = (float)in->a * *s;
    out->y = (float)in->b * *s;
    out->z = (float)in->c * *s;
}

void fn_80311464(void* p, int a, int b)
{
    *(Unk80310934_Big*)((char*)p + 4) = *fn_80311508(p, 0, 1, b, a);
}

void* fn_80311680(void* p, int a, int b, int c, int d)
{
    if ((a != 0 || b != 1) && (c == 1 || c == 5))
        return fn_80311508(p, a, b, d, c);
    return (char*)p + 4;
}

extern "C" void* fn_803119C0()
{
    if (lbl_8061FE20 == 0) {
        Unk8037C7FC* m = fn_8037C7FC();
        int* q = &lbl_8061FE84;
        *q = m->fn_8037CE98(0xABA1DAEF, lbl_8061FE1C, 0);
        lbl_8061FE20 = 1;
    }
    return (void*)lbl_8061FE84;
}

void* fn_80311A28(void* p)
{
    fn_80356798(p);
    ((Unk80310934_At0*)p)->m0 = lbl_806657A8;
    fn_8040074C((char*)p + 4, 0x1E0);
    return p;
}

void fn_80311A70(Unk80310934_At0* p, int c)
{
    p->m0 = lbl_806657A8;
    if (c & 1)
        fn_80377408(p);
}

void fn_80311AA4(Unk80310934_Mx* p, char* a, int n)
{
    char* cur;
    int rem;
    char* tok;
    int len;
    cur = a;
    tok = 0;
    len = 0;
    rem = n;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 0x1D; j++) {
            fn_80378E48(&cur, &rem, ',', &tok, &len);
            if (len <= 0)
                return;
            p->v[i][j] = (float)atof(tok);
        }
    }
}

void* fn_80311B4C(Unk80310934_At0* p)
{
    new (p) Unk8037B3E8(0xC22CAFD4u);
    p->m0 = lbl_80665748;
    fn_80311A28((char*)p + 4);
    return p;
}

void fn_80311B98(Unk8037B3E8* p)
{
    p->fn_8037B7E4(lbl_805E9474);
    p->fn_8037B728(lbl_805E9478, lbl_805E9484, (char*)p + 4, 0);
}

extern "C" void fn_80311BEC(Unk80310934_At0* p, int c)
{
    p->m0 = lbl_80665748;
    fn_80311A70((Unk80310934_At0*)((char*)p + 4), 2);
    fn_8037B424(p, c);
}

void* fn_80311C3C()
{
    return fn_80311B4C((Unk80310934_At0*)operator new(0x1E8, lbl_806EF9B4));
}

void fn_80311C6C()
{
    if (lbl_8061E978)
        fn_802AD538(lbl_8061E978, 0);
}

void* fn_80311CA0(Unk80310934_At1C* p)
{
    new (p) Unk8037B3E8(0x10B3208Eu);
    p->m0 = lbl_806656E8;
    p->m1C = 0;
    if (lbl_8061FE88 == 0)
        lbl_8061FE88 = 0xCFCDABCEu;
    return p;
}

extern "C" void fn_80311D08(Unk80310934_At0* p, int c)
{
    p->m0 = lbl_806656E8;
    fn_8037B424(p, c);
}

void* fn_80311EE0()
{
    return fn_80311CA0((Unk80310934_At1C*)operator new(0x48, lbl_806EF9B4));
}

void fn_80311F10(Unk80310934_Cp* p)
{
    p->m20.a = p->m3C.a;
    p->m20.b = p->m3C.b;
    p->m20.c = p->m3C.c;
}

Unk80310934_O1C* fn_80311F2C()
{
    return (Unk80310934_O1C*)fn_8037C7FC()->fn_8037CE98(0x10B3208E, lbl_8061FE88, 0);
}

void* fn_80311F64(Unk80310934_I0* p)
{
    void* q = (char*)p + 4;
    p->m0 = 0;
    fn_80359A40(q);
    return p;
}

void fn_80311FA0(Unk80310934_I0* p, int c)
{
    fn_80312018(p);
    if (c & 1)
        fn_80377408(p);
}

void fn_80311FE0(Unk80310934_I0* p)
{
    fn_80319CD4(p);
    p->m0 = lbl_8061FF74;
}

void fn_80312018(Unk80310934_I0* p)
{
    fn_80319D20(p);
    p->m0 = 0;
}

void fn_8031204C(Unk80310934_P10* p, int a, int b)
{
    p->m10 = a != 0 ? b : 0;
}

inline void ClearZ(Unk80310934_Z* z)
{
    z->m8 = 0;
    z->mC = 0;
    z->m10 = 0;
    z->m14 = 0;
    z->m18 = 0;
    z->m0 = 0;
    z->m4 = 0;
}

Unk80310934_Z* fn_80312064(Unk80310934_Z* p)
{
    ClearZ(p);
    return p;
}

void fn_8031208C(void* p, int c)
{
    fn_8031228C(p);
    if (c & 1)
        fn_80377408(p);
}

extern "C" int fn_8031228C(void* q)
{
    Unk80310934_Sd* p = (Unk80310934_Sd*)q;
    if (p->m4 != 0 && p->m0 != 0) {
        p->m4->fn_803DA098(p->m0);
        ((Unk803D7ED4Pool*)fn_803D81FC())->fn_803D803C((Unk803D7ED4Item*)p->m4);
        p->m4 = 0;
        p->m0 = 0;
    }
    if (p->m14 != 0) {
        fn_803DD73C(p->m14, 3);
        p->m14 = 0;
    }
    if (p->m18 != 0) {
        fn_803DD73C(p->m18, 3);
        p->m18 = 0;
    }
    if (p->m10 != 0) {
        fn_803DD73C(p->m10, 3);
        p->m10 = 0;
    }
    if (p->m8 != 0) {
        fn_80377408(p->m8);
        p->m8 = 0;
    }
    if (p->mC != 0) {
        fn_80377408(p->mC);
        p->mC = 0;
    }
    return 1;
}

void fn_80312370(Unk80310934_Bx* p)
{
    fn_803123E0(p, p->m14);
    fn_80314894(p->m10, 0, 0, p->m1C, p->m20, -1);
}

void fn_803123BC(Unk80310934_Bx* p)
{
    fn_803123E0(p, p->m10);
}

void fn_803123E0(Unk80310934_Bx* p, int a)
{
    fn_803D9E70(lbl_8061FEDC->m38->m4 + 0x10, 0, 0, p->m1C, p->m20, p->m1C, p->m20, 6, 0);
    fn_803D9ECC(lbl_8061FEDC->m38->m4 + 0x10, a, 0, 1, 0);
}

void fn_80312544()
{
    if (lbl_8061FEDC) {
        delete lbl_8061FEDC;
        lbl_8061FEDC = 0;
    }
}

extern "C" void fn_8031259C(Unk80310934_P60* p)
{
    p->m60 = 0;
    fn_803D983C(p->m38->m4, 0);
}

extern "C" void fn_803125D0(Unk80310934_P60* p)
{
    p->m60 = 1;
    fn_803D983C(p->m38->m4, 1);
}

int fn_80312604(Unk80310934_P60* p)
{
    int v = 0;
    fn_803D986C(p->m38->m4, &v);
    return v;
}

int fn_8031263C(int a, int b)
{
    int r = fn_803ED604(b, a, 0);
    fn_803FFC58(r, 0xCC55CC55u, a);
    return r;
}

void fn_8031268C(int a)
{
    fn_803FFC58(a, 0xDD55DD55u, fn_803EE310(a));
    fn_803EDA0C(a);
}

int fn_803126D4()
{
    return fn_803DBD84(lbl_8068E1C0, 2);
}

void fn_80312DA0()
{
}

void fn_80312DA4()
{
}

void fn_80312DA8()
{
}

void fn_80312DAC()
{
}

extern "C" void fn_80313634(void* p)
{
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    fn_80436F58(1);
    fn_803D9DDC(((Unk80310934_P60*)p)->m38->m4 + 0x10, lbl_80634B54, 0x10);
    fn_803D8918(((Unk80310934_P60*)p)->m38->m4);
}

extern "C" void fn_803136A0(void* p)
{
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    fn_80436F58(0);
    fn_803D9DDC(((Unk80310934_P60*)p)->m38->m4 + 0x10, lbl_80634AA0, 0x10);
    fn_803D8918(((Unk80310934_P60*)p)->m38->m4);
}

void fn_8031370C()
{
    VISetBlack(0);
    VIFlush();
    VIWaitForRetrace();
}

void fn_80313738(void* a, int b)
{
    Unk80310934_O1C* o = fn_80311F2C();
    char* q = (char*)o + 0x20;
    int k = 0;
    if (o->m1C != 0 && b != 0)
        k = 1;
    fn_803198B8(q, k);
}

void fn_80313B44(Unk80310934_P38* p)
{
    fn_803120CC((char*)p->m38 + 0x10, 0x80, 0x80, 0x20, 0, 0);
    void* x = p->m38->m24;
    if (x)
        fn_803DD7C8(x, 0);
}

void fn_80313BA4(Unk80310934_P38* p)
{
    fn_8031228C((char*)p->m38 + 0x10);
}

extern "C" void fn_80313BCC(Unk80310934_P1F8* p)
{
    fn_802B0C44(lbl_8061E978, 0x16);
    p->m1F8 = 0;
    lbl_8061F94C = 0;
}
