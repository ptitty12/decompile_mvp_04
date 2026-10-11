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

extern "C" {
void* fn_8030FECC(void* p);
void fn_8037B424(void* p, int c);
void* fn_80356798(void* p);
void fn_8040074C(void* p, int n);
void fn_802AD538(void* p, int k);
void fn_80311A70(Unk80310934_At0* p, int c);
void fn_80377408(void* p);
void* fn_80359A40(void* p);
void fn_80312018(Unk80310934_I0* p);
void fn_8031228C(void* p);
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
Unk80310934_O1C* fn_80311F2C();

void* fn_80310934()
{
    return fn_8030FECC(operator new(0x115C, lbl_806EF9B4));
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

inline void CopyV3(Unk80310934_V3* d, const Unk80310934_V3* s)
{
    *d = *s;
}

/* near-miss: retail copies the 12 bytes with plain displacements off r3; ours forms two address registers (inline CopyV3 tried) */
void fn_80311F10(Unk80310934_Cp* p)
{
    CopyV3(&p->m20, &p->m3C);
}

Unk80310934_O1C* fn_80311F2C()
{
    return (Unk80310934_O1C*)fn_8037C7FC()->fn_8037CE98(0x10B3208E, lbl_8061FE88, 0);
}

/* near-miss: retail computes addi r3,r30,4 before the store of 0 to +0 */
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
    z->m4 = 0;
    z->m8 = 0;
    z->mC = 0;
    z->m10 = 0;
    z->m14 = 0;
    z->m18 = 0;
    z->m0 = 0;
}

/* near-miss: retail copies r3 to r9 first and stores +4..+0x18 before +0 */
void fn_80312064(Unk80310934_Z* p)
{
    ClearZ(p);
}

void fn_8031208C(void* p, int c)
{
    fn_8031228C(p);
    if (c & 1)
        fn_80377408(p);
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
