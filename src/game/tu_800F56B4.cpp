/*
 * Game code, .text 0x800F56B4-0x800F92DC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


extern UiP2 lbl_805BE4B8;
extern UiP2 lbl_805BE4C0;
void fn_8011AF34(UiObj* o);
void fn_800F5870(UiObj* a);
extern char lbl_805BA6D0[];
extern char lbl_805BE4B0[];
extern char lbl_805BE22C[];
void fn_800F56B4(UiV_134_138* self)
{
    fn_800ECF18(self);
    self->m138 = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(self->m138, self);
    fn_80125490(self->m138, 1, 4, 0x38C8, 1);
    fn_801251CC(self->m138, 1, 0x1A0B, 0);
    fn_801251CC(self->m138, 0, 0x1A0D, 2);
    UiObj* w = self->m138;
    fn_800C80C0(w, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
    self->m134 = (UiObj*)fn_800C8060((int)self->v33(8, 1));
    self->m134->v79(0, 0);
    self->m134->v8(1);
    fn_800F5870(self);
    if (fn_8011AA24(0)->m6F8->m10->m74 != 0)
        fn_8011AF34(fn_800C8040(self->v32((int)lbl_805BE22C, 1)));
    else
        fn_80118A70(fn_800C8044(self->v32((int)lbl_805BE4B0, 1)));
}

void fn_800F5870(UiObj* a)
{
    UiP2 s1;
    int z;
    UiP2 s2;
    switch (fn_8011AA24(0)->m6F8->m10->m74) {
    case 1:
        s1 = lbl_805BE4B8;
        fn_800F595C(a, &s1.a, 2);
        break;
    case 6:
        z = 0;
        fn_800F595C(a, &z, 1);
        break;
    case 5:
        s2 = lbl_805BE4C0;
        fn_800F595C(a, &s2.a, 2);
        break;
    case 0:
        fn_800F595C(a, 0, 0);
        break;
    }
}

class UiX61v : public UiBase {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
  virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
  virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
  virtual void v41(); virtual void v42(int a, int b, int c, int d); virtual void v43(); virtual void v44();
  virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
  virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
  virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
  virtual void v60(); virtual void v61(); virtual int v62(); virtual void v63(); virtual void v64();
  virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
  virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
  virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
  virtual void v79(int a, int b);
};
struct UiTbl5 {
    int m[5];
};
class UiS595C : public UiObj {
public:
    char pad40[0x134 - 0x40];
    UiX61v* m134;
    int m138;
    int a13C[5];
};
extern UiTbl5 lbl_805BE4C8;
int fn_800F5AA8(UiObj* self, int a, int* b, int c);
void fn_800F595C(UiS595C* self, int* a, int b)
{
    UiTbl5 t = lbl_805BE4C8;
    int n = 0;
    int k = 0;
    self->m134->v79(self->m134->v62(), 0);
    for (int i = 0; i <= 4; i++) {
        if (fn_800F5AA8(self, i, a, b) == 0) {
            int v = t.m[i];
            if (i == 3)
                v = 0x3BBE;
            self->m134->v42(n, 0, v, 5);
            n++;
            self->a13C[k] = i;
            k++;
        }
    }
    self->m134->v79(n, 0);
}

int fn_800F5AA8(UiObj* self, int a, int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        if (a == arr[i])
            return 1;
    }
    return 0;
}

int fn_800F5AE0(UiObj* self, int a)
{
    return fn_800B555C()->m570 == a;
}

void fn_800F5D54(UiV_134* self, int a)
{
    fn_800ED310(self);
    self->m134->v14(a);
}

int fn_800F5DA4(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v50();
    return 1;
}

int fn_800F5DF8(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v51();
    return 1;
}

int fn_800F5E4C(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v52();
    return 1;
}

int fn_800F5EA0(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v53();
    return 1;
}

extern char lbl_80650B78[];
UiScrRaw* fn_800F5EF4(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80650B78;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

/* near-miss: 1 insn over; retail keeps lbl_80649DA0 in r30 across the calls and addresses the event object off r1 */
extern char lbl_805BADC8[];
extern char lbl_8065B888[];
extern char lbl_80649DA0[];
int fn_800F5F48(UiObj* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805BADC8, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
        UiEvtRaw e;
        e.id = 0x9E;
        e.vt = lbl_8065B888;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, &e, 0, 0);
        e.vt = lbl_80649DA0;
    }
    return 1;
}

extern char lbl_805BE138[];
int fn_800F6024(UiObj* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805BE138, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
    return 1;
}

extern char lbl_805B955C[];
int fn_800F60C0(UiV_134* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        int t = self->m134->v60();
        fn_800B555C()->m668 = t;
        fn_8040B830(p->name, lbl_805B955C, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
    return 1;
}

extern "C" {
void fn_80125300(UiObj* o, int a, int b, int c);
void fn_80125180(UiObj* o, int a, int b);
}
extern char lbl_805BA6D0[];
extern char lbl_805BE4B0[];
void fn_800F6184(UiV_134_138* self)
{
    self->m138 = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(self->m138, self);
    fn_80125300(self->m138, 1, 4, 0x38C8);
    UiObj* w = self->m138;
    fn_800C80C0(w, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
    fn_80125180(self->m138, 1, 0x1A0B);
    fn_80125180(self->m138, 0, 0x1A0D);
    self->m134 = (UiObj*)fn_800C8060((int)self->v33(8, 1));
    if (fn_8011AA24(0)->m6F8->m10->m74 == 0)
        fn_80118A70(fn_800C8044(self->v32((int)lbl_805BE4B0, 1)));
    self->m134->v8(1);
}

int fn_800F62D8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_800F6334(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_800F6390(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_800F63EC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_800F6448(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_800F64A4(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_800F6500(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_800F655C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

void fn_800F65B8(UiV_134* self, int a)
{
    fn_800ED310(self);
    self->m134->v14(a);
}

int fn_800F6608(UiV_134i* self, int a)
{
    if (self->m134 == a)
        self->v41(fn_800B555C()->m570);
    return 0;
}

extern char lbl_8064F8C8[];
UiScrRaw* fn_800F6664(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F8C8;
    self->m130 = 0;
    return self;
}

struct UiV_174_1D0 : UiObj {
    char pad40[0x174 - 0x40];
    UiObj* m174;
    char pad178[0x1D0 - 0x178];
    UiObj* m1D0;
};
struct UiRow78 {
    char pad0[0x78];
    int m78;
};
extern "C" {
int fn_80099B50(void* e, int i);
int fn_801A49F0(void* g, int a, int b);
void fn_800F6B24(void* self, int a, int b);
}
int fn_80177148(int* a, int b);
/* near-miss: 5 slots; the first fn_80125490 call has mr r3,w last in retail (after the four li), first here (tried an int-returning fn_80124FA8) */
void fn_800F6964(UiV_174_1D0* self)
{
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
    Ui8011AA24* g = fn_8011AA24(0);
    self->m174->v8(0);
    self->m1D0->v8(0);
    int p = g->m788;
    UiRow78* e = (UiRow78*)((char*)g->m6F8->m14 + p * 0xE64);
    int n = e->m78;
    for (int i = 0; i < n;) {
        int r = fn_80099B50(e, i);
        i++;
        int x = fn_801A49F0(g, p, r);
        fn_800F6B24(self, fn_80177148((int*)g->m700->m3A8, x) == 1, x);
    }
    UiObj* w = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(w, self);
    fn_80125490(w, 1, 1, 0x1A0B, 3);
    fn_80125490(w, 2, 4, 0x38C8, 4);
    fn_800C80C0(w, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
}

void fn_800F6AF4(UiObj* self)
{
    fn_800ED254(self);
    fn_801A3704(fn_8011AA24(0), 0);
}

extern char lbl_8065A640[];
struct UiEvt16 {
    int id;
    const void* vt;
    int m8;
    int mC;
};
/* near-miss: registers/stack slots of the event and message locals are swapped (5 slots differ) */
void fn_800F6F0C(UiObj* self, int kind, int a)
{
    switch (kind) {
    case 3:
        if (fn_800B555C()->m570 == a) {
            lbl_8061B8C0->m24 = 1;
            fn_802D7ADC();
            UiMsg m;
            UiMsg* p = &m;
            fn_8035682C(p);
            fn_8040B830(p->name, lbl_805BE138, 15);
            p->name[15] = 0;
            fn_800B7B4C(UiGetMsgMgr(), p, self);
        }
        break;
    case 4:
        if (fn_800B555C()->m570 == a) {
            UiMsg m;
            UiEvt16 e;
            UiEvt16* pe = &e;
            const void* base = lbl_80649DA0;
            pe->vt = base;
            e.id = 0x9E;
            pe->vt = lbl_8065B888;
            fn_8037893C(fn_8011AA24(0)->m704, e.id, (UiEvtRaw*)pe, 0, 0);
            fn_8035682C(&m);
            UiMsg* p = &m;
            fn_8040B830(p->name, lbl_805BADC8, 15);
            p->name[15] = 0;
            fn_800B7B4C(UiGetMsgMgr(), p, self);
            pe->vt = base;
        }
        break;
    }
}

UiScrRaw* fn_800F7084(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8011BFAC(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8065A640;
    return self;
}

extern char lbl_805B9704[];
extern char lbl_805B9710[];
extern char lbl_805B9778[];
extern char lbl_805BE598[];
void fn_8011C04C();
void fn_800F7338(int unused, int a, UiObj* obj);
extern char lbl_805B9704[];
extern char lbl_805B9710[];
extern char lbl_805B9778[];
extern char lbl_805BE598[];
void fn_8011C04C();
void fn_800F7338(int unused, int a, UiObj* obj);
void fn_800F7614(int unused, int a, UiObj* obj);
/* near-miss: only the placement of three lis (hi) instructions differs; retail hoists them above the earlier calls */
void fn_800F70C8(UiObj* self)
{
    fn_8011C04C();
    fn_800B555C()->m570 = -1;
    int a = (int)lbl_8068B618->m8;
    fn_800F7614((int)self, a, fn_800C8044(fn_800C8044(self->v32((int)lbl_805B9704, 1))->v32((int)lbl_805B9710, 1)));
    fn_800F7338((int)self, a, fn_800C8044(fn_800C8044(self->v32((int)lbl_805BE598, 1))->v32((int)lbl_805B9710, 1)));
    int b = (int)lbl_8068B618->mC;
    fn_800F7614((int)self, b, fn_800C8044(fn_800C8044(self->v32((int)lbl_805B9704, 1))->v32((int)lbl_805B9778, 1)));
    fn_800F7338((int)self, b, fn_800C8044(fn_800C8044(self->v32((int)lbl_805BE598, 1))->v32((int)lbl_805B9778, 1)));
    fn_800C80C0(self, fn_800B555C()->m570);
}

void fn_800F7294(UiObj* self)
{
    fn_8011C15C(self);
    void* t = lbl_8068B618->mC;
    if (fn_801A6D84(lbl_8068B618->m8, 1)->m3D90 != 0 || fn_801A6D84(t, 1)->m3D90 != 0)
        self->v8(0);
    else
        self->v8(1);
}

extern char lbl_805BE224[];
extern char lbl_805BDC84[];
extern char lbl_805BDC40[];
extern char lbl_805BE558[];
void fn_800F7614(int unused, int a, UiObj* obj)
{
    char* t = fn_801A4B34(a);
    UiObj* o = fn_800C8044(obj->v32((int)lbl_805BE224, 1));
    fn_8011A14C(t, o, lbl_805BDC84, 1);
    int k = fn_8025416C(t + 0x588, 5);
    fn_800C8040(o->v32((int)lbl_805BDC40, 1))->v30(fn_800E5F38(k));
    fn_8011A268(t, o, lbl_805BE558);
}

void fn_800F7708()
{
}

extern char lbl_80650368[];
UiScrRaw* fn_800F770C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80650368;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 5;
    self->m148 = 5;
    return self;
}

int fn_800F7BE0(UiV_13C_140i* self)
{
    int r = self->m13C->v60();
    if (self->m140 == 1)
        r += 2;
    return r;
}

int fn_800F7C34(UiScr13C* self, int a)
{
    if (fn_800B555C()->m570 == a || (self->m140 == 1 && (a == self->m144 || a == self->m148 || (self->m144 == -1 && self->m148 == -1))))
        return 1;
    return 0;
}


int fn_800F7E64(UiV_13Ci* self, int a)
{
    if (a == self->m13C) {
        self->v67(1, 0);
        return 1;
    }
    return 0;
}

void fn_800F80D8(UiV_134* self, int a)
{
    fn_80131F34(self->m134, self, fn_800F817C, 0, a, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    fn_800C80C0(self->m134, fn_800B555C()->m570);
    self->m134->v86();
}

void fn_800F817C(int a, UiObj* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_800F7EBC(b);
        break;
    }
}

void fn_800F81B0(UiV_13C* self, int a)
{
    fn_800ED310(self);
    self->m13C->v14(a);
}

int fn_800F8200(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v50();
    return 1;
}

int fn_800F8254(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v51();
    return 1;
}

int fn_800F82A8(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v52();
    return 1;
}

int fn_800F82FC(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v53();
    return 1;
}

extern char lbl_806500C0[];
UiScrRaw* fn_800F8350(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806500C0;
    self->m130 = 0;
    self->m134 = 11;
    self->m138 = 0;
    return self;
}

extern char lbl_805BA6D0[];
void fn_800F83A8(UiV_134i* self)
{
    fn_800ECF18(self);
    fn_802DC9C0();
    lbl_8061B8C0->m24 = 1;
    fn_802D7ADC();
    UiObj* o = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(o, self);
    fn_801251CC(o, 0, 0x1A0A, 0);
    fn_800C80C0(o, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
    int k = fn_8011AA4C();
    self->m134 = k;
    switch (k) {
    case 5:
        fn_800F8698(self);
        break;
    case 6:
        fn_800F8AD8(self);
        break;
    }
    if (lbl_806192E0->m4->m10->m120 == 1) {
        self->v8(0);
        self->v67(0, fn_800B555C()->m570);
    }
}

void fn_800F84F4(UiV_134i* self)
{
    switch (self->m134) {
    case 5:
        lbl_806192E0->m4->m20 = fn_800ABF3C(lbl_80619D10, fn_8011AA24(0))->m18;
        break;
    case 6:
        fn_800AB5C8(lbl_80619D10);
        fn_800AEC80();
        Ui806192E0_B* b = lbl_806192E0->m4;
        b->m20 = fn_800B1FCC();
        break;
    }
}

extern char lbl_805B97B4[];
extern char lbl_805BE628[];
void fn_800F8588(UiV_134i* self, int a, int b)
{
    if (fn_800F9290(self, b) != 0 && a == 0) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        if (fn_800B555C()->m0 == 0x2B) {
            fn_800F84F4(self);
            fn_8040B830(p->name, lbl_805B97B4, 15);
            p->name[15] = 0;
        } else {
            fn_8040B830(p->name, lbl_805BE628, 15);
            int k = self->m134;
            p->name[15] = 0;
            if (k == 6) {
                fn_800AB5C8(lbl_80619D10);
                fn_800AEC80();
                fn_800B2390();
            } else if (k == 5) {
                fn_800AB578(lbl_80619D10);
                fn_800AEDDC();
                fn_800B5364();
            }
        }
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
    }
}

void fn_800F91FC(int unused, int a, UiObj* obj)
{
    char buf[36];
    UiObj* o = fn_800C8040((int)obj->v33(4, 1));
    fn_80403DE4(buf, (const char*)fn_80090880(lbl_8061977C, 0x29CD), a);
    o->v28(buf);
}

int fn_800F9290(UiObj* self, int a)
{
    int v = fn_800B555C()->m570;
    if (a == v || v == -1)
        return 1;
    return 0;
}
