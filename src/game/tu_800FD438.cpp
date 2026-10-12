/*
 * Game code, .text 0x800FD438-0x80101254 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"

/* Widget (vptr at +0xC) that picks an object out of the table at owner+0x2B8 through the
 * index array at +0x10 (fn_800FF404, fn_800FF508). Evidence: those two functions. */
struct UiVt0 {
    virtual void s1(int a, int b);
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5(int a);
};
struct UiTblOwner {
    char pad0[0x2AC];
    int m2AC;
    char pad2B0[0x2B8 - 0x2B0];
    UiVt0* a2B8[8];
};
class UiWI : public UiW {
public:
    int a10[8];
};
class UiWV13 : public UiWBase {
public:
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual void k4();
    virtual void k5();
    virtual void k6();
    virtual void k7();
    virtual void k8();
    virtual void k9();
    virtual void k10();
    virtual void k11();
    virtual void k12();
    virtual int k13();
};
extern "C" int fn_80097300(char* e, unsigned char p);
struct UiOwner298 {
    char pad0[0x298];
    int m298;
};
inline int UiIntAt(char* b, int i)
{
    int o = i * 4;
    return *(int*)(b + o);
}
class UiWV13b : public UiWV13 {
public:
    Ui3C4* m10;
};
struct Unk80178BBC_T;
struct Unk80179284_Ctx;
struct Unk8019F8C0_Owner;
struct Ui700b {
    char pad0[0x3AC];
    Unk80178BBC_T* m3AC;
};
void fn_80178F64(Unk80178BBC_T* a, Unk80179284_Ctx* b);
void fn_80178FF0(Unk80178BBC_T* a);
void fn_801A3ACC(Unk8019F8C0_Owner* a, int b);
inline UiVt0* UiTblAt2(char* b, int i)
{
    int o = i * 4;
    return *(UiVt0**)(b + o);
}


void fn_800FD4F8()
{
}

void fn_800FE23C(UiV_1C4i* self, int a)
{
    fn_800C8044(self->m1C4)->v8(a);
}

extern char lbl_805BEE18[];
int fn_800FE390(UiV_1DCi* self)
{
    int r = self->m1DC;
    if (r != 0) {
        r = fn_800ED2B0(r, lbl_805BEE18);
        if (r != 0)
            r = fn_800CFB38();
    }
    return r;
}

extern char lbl_805BE138[];
void fn_800FEB30(const char* s, int idx)
{
    const char* name = s;
    if (name == 0)
        name = lbl_805BE138;
    else {
        int pid = UiIntAt((char*)fn_8011AA24(0)->m6F8->m10 + 0x6C, idx);
        fn_800B555C()->m570 = pid;
        fn_802DC9C0();
        lbl_8061B8C0->m24 = 1;
        fn_802D7ADC();
    }
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, name, 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, 0);
}

extern char lbl_80659A60[];
UiWRaw::UiWRaw()
{
    mC = lbl_80659A60;
    m0 = 0;
    m4 = 0;
    m8 = 0;
}

void fn_800FEC24(UiV_0i_4i* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
}

void fn_800FEC30(UiV_8* self)
{
    if (self->m8 != 0)
        self->m8->v71();
}

void fn_800FEC70(UiV_8* self)
{
    if (self->m8 != 0)
        self->m8->v72();
}

void fn_800FECB0(UiV_0* self)
{
    UiObj* o = self->m0;
    o->v67(1, fn_80101254(o));
}

extern char lbl_805BEF1C[];
extern char lbl_805BEF28[];
extern char lbl_805B6F58[];
void fn_800FF0C4(int a, UiObj* obj)
{
    if (a == 0)
        fn_800C8040(obj->v32((int)lbl_805BEF1C, 1))->v29(0x4F8C);
    else
        fn_800C8040(obj->v32((int)lbl_805BEF1C, 1))->v29(0x4F8D);
    fn_800C8040(obj->v32((int)lbl_805BEF28, 1))->v30((int)lbl_805B6F58);
}

extern char lbl_806599F0[];
UiW2::UiW2()
{
    m30 = 0;
    mC = lbl_806599F0;
}

void fn_800FF20C(UiFlagOwner* self, UiFlagged* a)
{
    self->m8 = a;
    a->bit7 = self->m30;
}

void fn_800FF224(UiV_8_2Ci* self)
{
    self->m2C = 0;
    self->m8->v79(0, 0);
}

void fn_800FF404(UiWI* self, int* a, int* b)
{
    int k = self->m8->v60();
    *a = ((UiTblOwner*)self->m0)->m2AC;
    int j = self->a10[k];
    *b = UiTblAt2((char*)self->m0 + 0x2B8, j)->s5(*a);
}

int fn_800FF494(UiWM* self, int a)
{
    if ((UiObj*)a == self->m8) {
        self->w6(fn_8011AA24(0), self->m0->m2AC);
        return 1;
    }
    return 0;
}

void fn_800FF508(UiWI* self, int a, int b)
{
    int k = self->m8->v60();
    int j = self->a10[k];
    UiTblAt2((char*)self->m0 + 0x2B8, j)->s1(a, b);
}

int fn_800FF590(UiPtr0* self)
{
    return self->m0->m2AC;
}

void fn_800FF59C(UiWV13b* self, int a)
{
    self->m4->v8();
    int v = self->k13();
    int t;
    if (fn_8011AA24(0)->m6F8->m14->m1CD0 != 0)
        t = 1;
    else
        t = 0;
    if (v == t) {
        Unk80178BBC_T* o = ((Ui700b*)fn_8011AA24(0)->m700)->m3AC;
        if (a == 1)
            fn_80178F64(o, (Unk80179284_Ctx*)self->m10);
        else
            fn_80178FF0(o);
        fn_801A3ACC((Unk8019F8C0_Owner*)fn_8011AA24(0), a);
    } else
        fn_801A3A54(fn_8011AA24(0), a);
}

void fn_800FFA1C(UiWV13* self, int* a, int* b)
{
    *a = self->k13();
    char* e = (char*)fn_8011AA24(0)->m6F8->m14 + *a * 0xE64;
    if (self->m8 == 0)
        *b = 0;
    else
        *b = fn_80097300(e, self->m8->v60());
}

void fn_800FFAC0(UiCopy* self, UiV4* p)
{
    self->m9C = *p;
    self->mCC = *p;
    self->m8C = *p;
}

void fn_800FFE28(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A39B8(fn_8011AA24(0), a);
}

void fn_80100020(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A39B8(fn_8011AA24(0), a);
}

void fn_80100150(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A3A54(fn_8011AA24(0), a);
}

void fn_801002F4(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A3A54(fn_8011AA24(0), a);
}

extern char lbl_805BD828[];
void fn_80100348(UiWM* self)
{
    Ui8011AA24* g = fn_8011AA24(0);
    int b = self->m0->m2AC == 0;
    g->m790 = b;
    fn_800FF0C4(b, fn_800C8044(self->m4->v32((int)lbl_805BD828, 1)));
}

void fn_80100644(UiV_28i* self, int a)
{
    self->m28 = a;
    fn_80100744(self);
}

void fn_80100668(UiV_2Ci* self, int a)
{
    self->m2C = a;
    fn_80100744(self);
}

void fn_8010068C(UiV_20i* self, int a)
{
    self->m20 = a;
    fn_80100744(self);
}

void fn_801006B0(UiV_24i* self, int a)
{
    self->m24 = a;
    fn_80100744(self);
}

void fn_801006D4(UiV_20i_24i_28i_2Ci* self, int idx)
{
    Ui3C4* q = fn_8011AA24(0)->m700->m3C4;
    self->m28 = q->a48[idx];
    self->m2C = q->a50[idx];
    self->m20 = q->a38[idx];
    self->m24 = q->a40[idx];
}

void fn_8010098C(UiV_20i_24i_28i_2Ci* self, int a)
{
    Ui3C4* q = fn_8011AA24(0)->m700->m3C4;
    fn_801A9D1C(q, a, self->m28);
    fn_801A9D2C(q, a, self->m2C);
    fn_801A9CFC(q, a, self->m20);
    fn_801A9D0C(q, a, self->m24);
}

void fn_80100A08(UiV_30b* self, int a)
{
    self->m30->v8();
}

void fn_80100A40(UiWM* self, int a)
{
    self->m4->v8();
    fn_80100A08((UiV_30b*)((char*)self->m0 + 0x270), a);
}

extern char lbl_805BE1C4[];
void fn_80100A98(UiWM* self, int a, int b)
{
    fn_800FEC24((UiV_0i_4i*)self, a, b);
    self->w11(fn_800C8060(self->m4->v32((int)lbl_805BE1C4, 1)));
    self->m10 = fn_8011AA24(0)->m700->m3C4;
    self->m14 = fn_8011B5A4() == 0;
}

extern int lbl_805BF008[][2];
void fn_80100B38(UiWM* self)
{
    int row = self->m8->v60();
    fn_80100644((UiV_28i*)((char*)self->m0 + 0x270), lbl_805BF008[row][self->m14]);
}

extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
extern int lbl_805BF008[][2];
/* near-miss: same code; the loop counter lands in r8 here, retail has it in r4 (3 slots, register names only) */
extern int lbl_805BF008[][2];
void fn_80100BA4(UiWM* self, int a, int b)
{
    fn_80100A98(self, a, b);
    int cur = UiIntAt((char*)self->m10 + 0x48, self->m0->m2AC);
    for (int i = 0; i < 8; i++) {
        if (cur == lbl_805BF008[i][self->m14]) {
            self->m8->v68();
            self->w13();
            break;
        }
    }
}

extern int lbl_805BF048[];
void fn_80100C58(UiWM* self)
{
    int row = self->m8->v60();
    fn_80100668((UiV_2Ci*)((char*)self->m0 + 0x270), lbl_805BF048[row]);
}

void fn_80100CB8(UiWM* self)
{
    int flag = ((UiOwner298*)self->m0)->m298 == 0xB;
    for (int i = 0; i < 4; i++) {
        int en = 1;
        if (flag) {
            int v = lbl_805BF048[i];
            if (v != 2)
                en = v == 1;
        }
        self->m8->v101(i, en);
    }
}

/* near-miss: same code; the loop counter lands in r8 here, retail has it in r4 (3 slots, register names only) */
void fn_80100D58(UiWM* self, int a, int b)
{
    fn_80100A98(self, a, b);
    int cur = UiIntAt((char*)self->m10 + 0x50, self->m0->m2AC);
    int i = 0;
    do {
        if (cur == lbl_805BF048[i]) {
            self->m8->v68();
            self->w13();
            break;
        }
        i++;
    } while (i < 4);
}

extern int lbl_805BF058[][2];
void fn_80100E00(UiWM* self)
{
    int row = self->m8->v60();
    fn_8010068C((UiV_20i*)((char*)self->m0 + 0x270), lbl_805BF058[row][self->m14]);
}

extern int lbl_805BF058[][2];
/* near-miss: same code; the loop counter lands in r8 here, retail has it in r4 (3 slots, register names only) */
extern int lbl_805BF058[][2];
void fn_80100E6C(UiWM* self, int a, int b)
{
    fn_80100A98(self, a, b);
    int cur = UiIntAt((char*)self->m10 + 0x38, self->m0->m2AC);
    for (int i = 0; i < 10; i++) {
        if (cur == lbl_805BF058[i][self->m14]) {
            self->m8->v68();
            self->w13();
            break;
        }
    }
}

extern int lbl_805BF0A8[][2];
void fn_80100F20(UiWM* self)
{
    int row = self->m8->v60();
    fn_801006B0((UiV_24i*)((char*)self->m0 + 0x270), lbl_805BF0A8[row][self->m14]);
}

extern int lbl_805BF0A8[][2];
/* near-miss: same code; the loop counter lands in r8 here, retail has it in r4 (3 slots, register names only) */
extern int lbl_805BF0A8[][2];
void fn_80100F8C(UiWM* self, int a, int b)
{
    fn_80100A98(self, a, b);
    int cur = UiIntAt((char*)self->m10 + 0x40, self->m0->m2AC);
    for (int i = 0; i < 4; i++) {
        if (cur == lbl_805BF0A8[i][self->m14]) {
            self->m8->v68();
            self->w13();
            break;
        }
    }
}
