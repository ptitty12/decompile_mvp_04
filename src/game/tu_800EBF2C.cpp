/*
 * Game code, .text 0x800EBF2C-0x800EE048 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800EBF2C.h"

void fn_800EBF2C(UiS* self)
{
    lbl_8061930C->fn_8007DA8C(self->m17C, -1);
    self->v94(0);
}

extern "C" UiScrRaw* fn_800EC150(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80659DC0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 1;
    self->m144 = 1;
    self->m148 = 0;
    return self;
}

extern "C" void fn_800EC1B8(UiScrRaw* self)
{
    self->m3C = lbl_80659DC0;
    fn_8035686C(self);
}

void fn_800EC1E8(void* t)
{
    fn_800ECE34((UiS*)t);
}

void fn_800EC208(UiS* self)
{
    if (self->v90() != 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
    }
    self->v89(0);
}

extern "C" void fn_800EC278(UiS* self)
{
    self->v89(1);
}

UiScrRaw* fn_800EC594(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80655EB0;
    self->m130 = 0;
    self->m13C = 1;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    return self;
}

void fn_800EC5F4(UiScrRaw* self)
{
    self->m3C = lbl_80655EB0;
    fn_8035686C(self);
}

void fn_800EC624(Unk800EC624_T* t, int a, int b, int c)
{
    t->m140 = a;
    t->m13C = b;
    t->m144 = c;
}

void fn_800EC634()
{
}

void fn_800EC638()
{
}

void fn_800EC63C()
{
}

void fn_800EC640()
{
}

void fn_800EC644()
{
}

extern "C" UiScrRaw* fn_800EC648(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800CEEF0(self, a, 0, b, c, d, e, f, g, 0, 0, 0, 1.0f);
    self->m44 = 0;
    self->m48 &= 0x3FFFFFFF;
    self->m4C = 0;
    self->m64 = self;
    self->m1C = 0;
    self->m3C = lbl_8065C788;
    fn_800CEFEC(self, h);
    self->m54 = 0;
    self->m48 &= 0xDFFFFFFF;
    return self;
}

void fn_800EC704(UiScrRaw* self, int a)
{
    UiS* p = self->m4;
    self->m3C = lbl_8065C788;
    while (p != 0) {
        UiS* q = p;
        p = p->m4;
        delete q;
    }
    UiNB* n = self->m4C;
    while (n != 0) {
        UiNB* q = n;
        n = n->m24;
        delete q;
    }
    fn_80356838(self, a);
}

void fn_800EC7C0(UiS* self, UiS* v)
{
    v->v18(self->m2E);
    if (self->m44 != 0)
        self->m44->m4 = v;
    if (self->m4 == 0)
        self->m4 = v;
    self->m44 = v;
}

void fn_800EC82C(Unk800EC82C_T* t, Unk800EC82C_N* v)
{
    Unk800EC82C_N* old = t->m4C;
    if (old == 0) {
        t->m4C = v;
    } else {
        v->m24 = old;
        t->m4C = v;
    }
}

extern "C" void fn_800EC84C(UiS* self)
{
    if (self->m24 < 0) {
        for (UiS* c = self->m40; c != 0; c = c->m8) {
            if (c->m24 < 0)
                c->v2();
        }
    }
}

int fn_800EC8B8(UiS* t)
{
    for (UiN* n = ((UiS*)t)->m4C; n != 0; n = n->m24) {
        if (n->m0 != 0)
            return 1;
    }
    return 0;
}

extern "C" void fn_800ECAA4(UiS* self)
{
    if (!(self->m48 & 0x40000000)) {
        fn_800EC8EC(self);
        fn_800ECB0C(self);
        while ((self = self->m4) != 0)
            self->v4();
    }
}

struct UiMsgMgrCC {
    char pad0[0xCC];
    int mCC;
};
struct UiNode8EC {
    int m0;
    char pad4[0x24 - 4];
    UiNode8EC* m24;
    int m28;
};
struct UiSelfB0 {
    char pad0[0x4C];
    UiNode8EC* m4C;
    char pad50[0x64 - 0x50];
    UiS* m64;
    char pad68[4];
};
int fn_800CFC28(UiNode8EC* n, float t);
void fn_800CFD1C(UiNode8EC* n, int* a, int* b, float* c, float t);
extern int lbl_8061A328;
inline void SetIntAt(char* b, int off, int v)
{
    *(int*)(b + off) = v;
}
inline void SetFloatAt(char* b, int off, float v)
{
    *(float*)(b + off) = v;
}
/* near-miss: one pair swapped (retail loads ang before the i2 store; ours after) */
extern "C" void fn_800ECB0C(UiSelfB0* self0)
{
    UiS* self = (UiS*)self0;
    int count = 0;
    UiNode8EC* n = ((UiSelfB0*)self)->m4C;
    float t = (float)lbl_8061A328 * 0.016666668f;
    UiRec12 rec[50];
    float ang = 0.0f;
    int i1;
    int i2;
    if (n != 0) {
        do {
            if (n->m0 != 0) {
                int off = count * 12;
                n->m28 = 0;
                while (fn_800CFC28(n, t) != 0) {
                    fn_800CFD1C(n, &i1, &i2, &ang, t);
                    char* base = (char*)self + 0x68;
                    int o1 = i1 * 4;
                    int o2 = i2 * 4;
                    UiS* a = *(UiS**)(base + o1);
                    UiS* b = *(UiS**)(base + o2);
                    if (a != 0 && b != 0 && (a->m48 & 0x40000000) && (b->m48 & 0x40000000)) {
                        SetIntAt((char*)rec, off, i1);
                        count++;
                        SetIntAt((char*)rec + 4, off, i2);
                        float* pf = (float*)((char*)rec + 8);
                        *(float*)((char*)pf + off) = ang;
                        off += 12;
                    }
                }
            }
            n = n->m24;
        } while (n != 0);
    }
    if (count != 0) {
        fn_800ECC9C(self, ((UiSelfB0*)self)->m64->m4, rec, count);
        ((UiMsgMgrCC*)UiGetMsgMgr())->mCC = 1;
    }
}

/* near-miss: ~20 slots, register numbering of self/arr and lwzx base/index order of the table reads */
void fn_800ECC9C(UiS* self, UiS* node, UiRec12* arr, int n)
{
    for (; node != 0; node = (UiS*)node->m8) {
        if (node->m24 & 0x200000) {
            for (int i = 0; i < n; i++) {
                UiRec12* r = &arr[i];
                UiS* a = ((UiS**)((char*)self + 0x68))[r->m0];
                UiS* b = ((UiS**)((char*)self + 0x68))[r->m4];
                UiS* x = a->v30((char*)node + 0xC, 1);
                UiS* y = b->v30((char*)node + 0xC, 1);
                if (x != 0 && y != 0)
                    ((UiVH*)node)->v7(x, y, r->m8);
            }
        }
        if (node->m1C == 3 || node->m1C == 0xB)
            fn_800ECC9C(self, node->m40, arr, n);
    }
}

extern "C" void fn_800ECDCC(UiS* self, int flag)
{
    fn_800C7E0C(self, flag);
    UiN* r;
    if (flag != 0)
        r = fn_800ED2B0(self, lbl_805BE188);
    else
        r = fn_800ED2B0(self, lbl_805BE190);
    if (r != 0)
        fn_800CFB38(r);
}

extern "C" void fn_800ECE34(UiS* self)
{
    fn_800CEF98(self);
    fn_800B83F8(fn_800B8144(), 0, 0);
    UiS* w = self->v30(lbl_805BE19C, 0);
    if (w != 0) {
        UiS* t = fn_800C8044(w);
        UiS* a = ((UiVG*)t)->v31(4, 1);
        UiS* b = ((UiVG*)t)->v31(2, 1);
        if (b != 0 && a != 0)
            fn_800DD204(fn_800C8040(a), fn_800C8038(b));
    }
}

extern char lbl_805BE1C4[];
extern "C" void fn_800ECF18(UiS* self)
{
    if (lbl_8061FEDC->m204 != 0) {
        UiS* r = self->v30(lbl_805BE1A8, 1);
        if (r != 0)
            r->m24 |= 0x800000;
    }
    self->v78();
    UiN* n = fn_800ED2B0(self, lbl_805BE1B0);
    if (n != 0)
        fn_800CFB38(n);
}

void fn_800ECFC0()
{
}

int fn_800ECFC4()
{
    return 0;
}

int fn_800ECFCC()
{
    return 0;
}

void fn_800ECFD4(UiS* t)
{
    for (UiS* n = t->m4; n != 0; n = n->m4) {
        for (int i = 0; i < n->m20; i++) {
        }
    }
}

class UiV23 : public UiS0 {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual int v23(int a);
};
extern void* lbl_8061ABE4;
class UiV22 : public UiS0 {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual int v22(int a);
};
extern "C" int fn_800ED00C(UiS* self, int a)
{
    if (self->m24 >= 0)
        return 0;
    if (!(self->m24 & 0x40000000))
        return 0;
    UiS* n = self->m4;
    lbl_8061ABE4 = self;
    int found = 0;
    unsigned key = 0;
    if (n != 0) {
        if (n->m24 >= 0 || !(n->m24 & 0x40000000)) {
            key = n->m20;
            found = 1;
        }
    }
    if (n != 0) {
        do {
            if (found == 0 && ((UiV22*)n)->v22(a) != 0) {
                lbl_8061ABE4 = 0;
                return 1;
            }
            n = n->m4;
            if (n != 0) {
                if (found != 0) {
                    if (n->m24 < 0 && (n->m24 & 0x40000000) && (unsigned)n->m20 <= key)
                        found = 0;
                } else {
                    if (n->m24 >= 0 || !(n->m24 & 0x40000000))
                        found = 1;
                    if (found != 0)
                        key = n->m20;
                }
            }
        } while (n != 0);
    }
    lbl_8061ABE4 = 0;
    return 0;
}

int fn_800ED144(UiS* self, int a)
{
    if (self->m24 >= 0)
        return 0;
    UiS* n = self->m4;
    lbl_8061ABE4 = self;
    int found = 0;
    unsigned key = 0;
    if (n != 0) {
        if (n->m24 >= 0) {
            key = n->m20;
            found = 1;
        }
        do {
            if (found == 0 && ((UiV23*)n)->v23(a) != 0) {
                lbl_8061ABE4 = 0;
                return 1;
            }
            n = n->m4;
            if (n != 0) {
                if (found != 0) {
                    if (n->m24 < 0 && (unsigned)n->m20 <= key)
                        found = 0;
                } else {
                    found = (unsigned)n->m24 >> 31;
                    found ^= 1;
                    if (found != 0)
                        key = n->m20;
                }
            }
        } while (n != 0);
    }
    lbl_8061ABE4 = 0;
    return 0;
}

extern "C" void fn_800ED254(UiS* self)
{
    if ((int)self->m48 < 0) {
        self->m48 &= 0x7FFFFFFF;
        self->v39();
    }
    fn_800B83F8(fn_800B8144(), 1, 0);
}

extern "C" UiN* fn_800ED2B0(UiS* self, const char* name)
{
    for (UiN* n = self->m4C; n != 0; n = n->m24) {
        if (fn_8040B574(n->name, name) == 0)
            return n;
    }
    return 0;
}

void fn_800C7E90();
UiS* fn_800C804C(UiS* p);
UiS* fn_800C8050(UiS* p);
UiS* fn_800C805C(UiS* p);
class UiV39 : public UiS0 {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
  virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
  virtual void v36(); virtual void v37(); virtual void v38(); virtual int v39();
};
void fn_800ED310(UiS* self, int a)
{
    fn_800C7E90();
    if (a == 0) {
        for (UiS* n = self->m4; n != 0; n = n->m4) {
            switch (n->m1C) {
            case 11:
                fn_800C805C(n)->v41();
                ((UiV39*)fn_800C805C(n))->v39();
                break;
            case 8:
                fn_800C8060(n)->v51();
                fn_800C8060(n)->v53();
                fn_800C8060(n)->v57();
                fn_800C8060(n)->v55();
                break;
            case 6:
                fn_800C804C(n)->v46();
                fn_800C804C(n)->v48();
                break;
            case 7:
                fn_800C8050(n)->v46();
                fn_800C8050(n)->v48();
                break;
            }
        }
    }
}

void fn_800ED4CC(char* t, const char* s)
{
    fn_8040B61C(t + 0x54, s);
}

extern "C" unsigned fn_800ED4F0(void* t, unsigned n)
{
    unsigned r;
    if (n != 0)
        r = fn_8040ABA0() % n;
    else
        r = 0;
    return r;
}

UiS* fn_800ED534(UiS* self)
{
    fn_800C6794(self);
    self->m1C8 = lbl_8065A430;
    void* r = fn_800C6CEC(self, lbl_805BE1B8);
    if (r != 0)
        r = fn_800C8040(r);
    self->m1CC = r;
    return self;
}

/* near-miss: 8 slots; the pointer-to-member dispatch is right but the virtual-arm temporaries are numbered r9/r0 (retail r11/r9); tried loop shapes, a PMF copy, const, the .* form */
void fn_800ED590(Unk800ED590_C* self, int a, Unk800ED590_Fn f)
{
    for (int i = self->m1C4 - 1; i >= 0; i--) {
        Unk800ED590_W* w = self->m34[i];
        if (w->m24 & 0x40000000) {
            if ((w->*f)(a) != 0)
                break;
        }
    }
}

UiScrRaw* fn_800ED654(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 1, lbl_8061B31C);
    self->m3C = lbl_806551F8;
    return self;
}

void fn_800ED6BC(UiScrRaw* self)
{
    fn_804D3164(self);
    fn_804D2DC0(self, 0x3937);
    fn_804D3CA8(self, 1);
}

void fn_800ED700(UiS* self, int a)
{
    if (fn_804D3B18(self) == 1)
        self->v40();
    fn_804D32A0(self, a);
}

void fn_800ED75C()
{
    fn_8006C698(lbl_806192E0->m4);
    fn_8006C698(lbl_806192E0->m8);
}

UiScrRaw* fn_800ED79C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 1, lbl_8061B320);
    self->m3C = lbl_80654C80;
    return self;
}

void fn_800ED804(UiScrRaw* self)
{
    fn_804D3164(self);
    fn_804D2DC0(self, 0x3938);
}

UiScrRaw* fn_800ED83C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 1, lbl_8061B324);
    self->m3C = lbl_80653E60;
    return self;
}

void fn_800ED8A4(UiScrRaw* self)
{
    fn_804D3164(self);
    fn_804D2DC0(self, 0x3939);
}

UiScrRaw* fn_800ED8DC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806518E0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

void fn_800ED930(UiS* self)
{
    UiS* w = fn_800C8060(self->v32(lbl_805BE1C4, 1));
    self->m13C = w->v77();
    self->m140 = w->v75();
}

void fn_800ED9BC(UiS* self)
{
    int v = fn_800C8060(self->v32(lbl_805BE1C4, 1))->v77();
    if (v != self->m13C) {
        UiS* w = fn_800C8060(self->v32(lbl_805BE1CC, 1));
        ((UiVG*)w)->v78(v);
        w->v14(1);
        w->v14(0);
    }
}

int fn_800EDAB4(UiS* self, int a)
{
    if (self->m138 == 0 && fn_800B555C()->m570 == a) {
        fn_800B7ADC(UiGetMsgMgr(), self);
        UiEvtPlain e;
        e.vt = lbl_80649DA0;
        e.id = 0x9E;
        e.vt = lbl_8065B888;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, (UiEvtRaw*)&e, 0, 0);
        e.vt = lbl_80649DA0;
    }
    return 1;
}

int fn_800EDB78(Unk800EDB78_T* t)
{
    if (t->m138 == 0) {
        fn_800B555C();
    }
    return 1;
}

int fn_800EDBA8(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a)
        fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

void fn_800EDC24(void* t, char* c)
{
    *c = 0;
}

void fn_800EDF5C(void* t)
{
    fn_800ED254((UiS*)t);
}

int fn_800EDF7C(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a) {
        fn_800C8060(self->v32(lbl_805BE1CC, 1))->v50();
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v50();
    }
    return 1;
}
