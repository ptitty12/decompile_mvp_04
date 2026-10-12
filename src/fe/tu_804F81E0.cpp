/*
 * Front-end overlay code, .frontend_codeoverlay 0x804F81E0-0x804FE34C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

/* Q16-DECL-BEGIN */
struct Unk8019F8C0_Owner;
struct FeRec388 {
    char pad0[0x388];
    int m388;
    int m38C;
};
FeRec388* fn_801A4C20(Unk8019F8C0_Owner* o);
struct Unk8007FF8C_G;
float fn_80080110(Unk8007FF8C_G* g, unsigned i, int x);
void fn_800800C8(Unk8007FF8C_G* g, unsigned i, float f, int x);
struct UiS;
float fn_800DC77C(UiS* w);
struct Unk802CA5A0_Elem;
Unk802CA5A0_Elem* fn_802CA5A0(Unk802CA5A0_Elem* t, int i);
extern int lbl_805FD3F4[];
extern "C" int sprintf(char* d, const char* fmt, ...);
extern "C" char* strcpy(char* d, const char* s);

extern "C" int fn_804D1278(void* self);
extern "C" void fn_80123610(FeObj* w);
extern "C" int fn_800B57EC();
#define FE_LO30(X)     X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17)     X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30)
class FeObjR31 : public UiBase {
public:
    FE_LO30(FE_V0) virtual const void* v31(); virtual FeObj* v32(const char* a, int b); FE_HI(FE_V0)
};
struct FeCap : FeObj {
    char pad40[0x134 - 0x40];
    FeObjI* m134;
    char pad138[0x364 - 0x138];
    int m364;
    int m368;
    char pad36C[0x378 - 0x36C];
    int m378;
    char pad37C[0x4F0 - 0x37C];
    float m4F0[0x29];
    Unk8019F8C0_Owner* m594;
    char pad598[0x618 - 0x598];
    FeObjI* m618;
    char pad61C[0x630 - 0x61C];
    int m630;
    char pad634[0x650 - 0x634];
    FeObjS* m650;
    FeObjR31* m654;
    FeObjR31* m658;
    char pad65C[0x680 - 0x65C];
    FeObj* m680;
    FeObj* m684;
    char pad688[0x7F4 - 0x688];
    UiS* m7F4[14];
    char pad82C[0x870 - 0x82C];
    int m870;
    char pad874[0x1100 - 0x874];
    FeObj* m1100;
};
extern "C" {
void fn_804FA1AC(FeCap* self, int mode, int x);
int fn_804F9B84(FeCap* self);
int fn_804FA320(void* self, int v);
int fn_804FA950(FeCap* self);
int fn_804F9B14(FeCap* self, int i, int n);
int fn_804FAA00(FeCap* self, int k, int m, float x);
float fn_804FAB88(void* self, float* a, int i);
float fn_804FA098(FeS23* self, int i, float x);
float fn_804FA104(FeS23* self, int i, int flag, float x);
float fn_804FA7BC(void* self, float x);
}
struct FeTabE {
    int k;
    int thr;
    int a;
    int b;
};
extern FeTabE lbl_80691FC4[];
struct FeCap3 : FeObj {
    char pad40[0x740 - 0x40];
    int m740[19];
};
extern "C" void fn_804FA374(FeCap* self, int i, int a, int mode, int x, int sel);
extern "C" int fn_804FA284(void* self, int v);
extern "C" int fn_80403060(const unsigned short* s);
extern "C" void fn_805283FC(void);
extern "C" int fn_804F9D10(FeCap* self, int a);
extern "C" void fn_804F83C8(FeCap* self);
void fn_800DC580(UiS* w, float f);
extern const int lbl_805FD394[];
extern char lbl_805FB378[];
extern char lbl_805FB380[];
extern char lbl_805FB388[];
extern char lbl_805FB390[];
extern float lbl_805FB394;
extern "C" int strcmp(const char* a, const char* b);
void fn_800E633C(char* s);
extern "C" void fn_80402FCC(char* dst, const void* src);
extern "C" int fn_804F9C64(void* l, int k);
extern const int lbl_805FD3B4[];
extern const int lbl_805FD3D4[];
extern "C" {
void fn_8013D0E0(FeObjI* w, const void* s);
void fn_8013C0A8(FeObjI* w, int a, int b, int c);
}
void fn_802AEBCC(void* a, void* b);
struct FeBigS : FeObj {
    char pad40[0x10EC - 0x40];
    FeObj* m10EC;
    FeObj* m10F0;
    FeObj* m10F4;
    FeObj* m10F8;
    FeObj* m10FC;
    FeObj* m1100;
};
extern "C" void fn_8040074C(void* p, int n);
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A3B8[];
struct FeAr {
    int* m0;
    int m4;
    int m8;
    int mC;
    const void* vp;
    int m14;
};

inline void FeArBase(FeAr* a, int* buf, int cap)
{
    a->vp = lbl_8064B298;
    a->m0 = buf;
    a->m8 = cap;
    fn_8040074C(a->m0, cap * 4);
}

inline void FeArMid(FeAr* a)
{
    a->m4 = 0;
    a->mC = 0;
    a->vp = lbl_8064A550;
    fn_8040074C(a->m0, a->m8 * 4);
}

inline void FeArD2(FeAr* a)
{
    a->vp = lbl_8064A3B8;
    a->m4 = 0;
    a->mC = 0;
    a->m14 = 0;
}

inline void FeArDtor(FeAr* a)
{
    a->vp = lbl_8064A550;
}

extern "C" void fn_80538368(FeAr* a, int v);
struct FeSq : FeObj {
    char pad40[0x740 - 0x40];
    FeObj* a[9];
    FeObj* p0;
    FeObj* b[9];
    FeObj* p1;
    char pad790[0x844 - 0x790];
    FeObj* m844;
    FeObj* m848;
};
extern "C" FeObj* fn_800C8034(void* p);
/* Q16-DECL-END */

extern "C" int fn_804FB7F4(FeS19* s);
extern "C" int fn_804FB84C(FeS19* s);

extern "C" FE_OVERLAY void fn_804F81E0(const unsigned short* s)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "CREATEAPLAYER");
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
    if (fn_80403060(s) > 0) {
        FeObj* q = fn_800C8040(p->v32("FNAMETB", 1));
        ((FeObj1*)q)->v28((int)s);
        fn_804F83C8((FeCap*)p);
    }
}

extern "C" FE_OVERLAY void fn_804F82D4(const unsigned short* s)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "CREATEAPLAYER");
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
    if (fn_80403060(s) > 0) {
        FeObj* q = fn_800C8040(p->v32("LNAMETB", 1));
        ((FeObj1*)q)->v28((int)s);
        fn_804F83C8((FeCap*)p);
    }
}

extern "C" FE_OVERLAY void fn_804F83C8(FeCap* self)
{
    if (self->m630 == 1 && fn_804F9D10(self, 0) != 0) {
        FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
        fn_80131F34(p, self, (FeCb)fn_805283FC, 0, 0x3A8E, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        p->v86();
    }
}

extern "C" FE_OVERLAY void fn_804F84A0(void)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "CREATEAPLAYER");
    ((FeObj1*)p)->v8(1);
    ((FeObj1*)p)->v16(1);
}

extern "C" FE_OVERLAY void fn_804F8534(void* p)
{
    FeCap* self = (FeCap*)p;
    if (self->m618 != 0) {
        int mode = 1;
        ((FeObj1*)self)->v16(0);
        if (self->m618->v60() == 0) {
            FeObjI* w = self->m134;
            fn_8013D0E0(w, ((FeObjR31*)fn_800C8040(self->v32("FNAMETB", 1)))->v31());
        } else {
            mode = 2;
            FeObjI* w = self->m134;
            fn_8013D0E0(w, ((FeObjR31*)fn_800C8040(self->v32("LNAMETB", 1)))->v31());
        }
        fn_8013C0A8(self->m134, 1, 1, mode);
    }
}

/* near-miss: loop bound compiles to cmpwi 105 / bgt where retail has cmpwi 106 / bge (2 slots differ) */
/* near-miss: loop bound compiles to cmpwi 105 / bgt where retail has cmpwi 106 / bge (2 slots differ) */
/* near-miss: loop bound compiles to cmpwi 105 / bgt where retail has cmpwi 106 / bge (2 slots differ) */
extern "C" FE_OVERLAY int fn_804F8668(void* self, int key, int thr, int* out)
{
    int i;
    int best = 0;
    for (i = 0; i < 0x6A && lbl_80691FC4[i].k != key; i++)
        ;
    if (i != 0x6A) {
        best = i;
        while (lbl_80691FC4[i].k == key) {
            if (lbl_80691FC4[i].thr <= thr) {
                best = i;
                i = best + 1;
            } else
                i++;
        }
    }
    *out = lbl_80691FC4[best].b;
    return lbl_80691FC4[best].a;
}

extern "C" FE_OVERLAY void fn_804F872C(FeCap* self)
{
    FeRec388* o = fn_801A4C20(self->m594);
    o->m388 = self->m368;
    o->m38C = self->m364;
}

extern "C" FE_OVERLAY void fn_804F876C(void* self, char* out)
{
    out[0] = 0;
    if (fn_800B555C()->m0 == 0x2E)
        strcpy(out, "DONEEDIT");
    else
        strcpy(out, "DONECREATE");
}

extern "C" FE_OVERLAY int fn_804F87F8(FeS21* s)
{
    if (s->m4A0 == s->m4B4 || s->m4A0 == s->m4C8 || s->m4A0 == s->m4DC)
        return 1;
    if (s->m4B4 == s->m4C8 || s->m4B4 == s->m4DC) {
        if (s->m4B4 != 0)
            return 1;
    }
    if (s->m4C8 == s->m4DC) {
        if (s->m4C8 != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804F885C(FeS22* self)
{
    if (self->m868 != lbl_805FD1A0[self->m3B4])
        return 1;
    if (self->m630 == 1 || fn_804FB7F4((FeS19*)self) != 0 || fn_804FB84C((FeS19*)self) != 0) {
        if (self->m864 != lbl_805FD2A8[self->m484])
            return 1;
        return 0;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804F8900(FeS22* self)
{
    void* g = lbl_8061E978;
    char buf[64];
    if (self->m630 == 1 || fn_804FB7F4((FeS19*)self) != 0 || fn_804FB84C((FeS19*)self) != 0) {
        if (self->m864 != lbl_805FD2A8[self->m484]) {
            if (self->m864 >= 0) {
                sprintf(buf, "SIGP%04d", self->m864);
                fn_802AEBF0(g, buf);
            }
            self->m864 = lbl_805FD2A8[self->m484];
            if (self->m864 >= 0) {
                sprintf(buf, "SIGP%04d", self->m864);
                fn_802AEBCC(g, buf);
            }
        }
    }
    if (self->m868 != lbl_805FD1A0[self->m3B4]) {
        if (self->m868 >= 0) {
            sprintf(buf, "SIGB%04d", self->m868);
            fn_802AEBF0(g, buf);
        }
        self->m868 = lbl_805FD1A0[self->m3B4];
        if (self->m868 >= 0) {
            sprintf(buf, "SIGB%04d", self->m868);
            fn_802AEBCC(g, buf);
        }
    }
}

extern "C" FE_OVERLAY void fn_804F8A58(FeS22* self)
{
    void* g = lbl_8061E978;
    char buf[64];
    if (self->m864 >= 0) {
        fn_804089B4(buf, "SIGP%04d", self->m864);
        fn_802AEBF0(g, buf);
    }
    if (self->m868 >= 0) {
        fn_804089B4(buf, "SIGB%04d", self->m868);
        fn_802AEBF0(g, buf);
    }
}

extern "C" FE_OVERLAY void fn_804F8AE0(FeS22* self, int a)
{
    fn_800ED310(self, a);
    int k = ((FeSub*)((char*)fn_800C8058(((FeObjQ*)self->m604)->v33(10, 1)) + 0xDC))->s5();
    FeObj1* w = (FeObj1*)self->m82C[k];
    if (w != 0)
        w->v14(a);
}

extern "C" FE_OVERLAY int fn_804F8B84(FeS18* s, int* out)
{
    for (int i = 0; i < 25; i++) {
        if (s->e[i].a != 0) {
            *out = i;
            return 1;
        }
    }
    *out = 0;
    return 0;
}

extern "C" FE_OVERLAY int fn_804F9AAC(void* self, UiItemN* it)
{
    char* n = it->name;
    if (fn_8040B574(n, "FNAMETB") == 0 || fn_8040B574(n, "LNAMETB") == 0)
        fn_804F8534(self);
    return 0;
}

extern "C" FE_OVERLAY int fn_804F9B84(FeCap* self)
{
    int r;
    if (self->m630 == 1) {
        int a = ((FeSub*)((char*)self->m680 + 0xDC))->s11();
        int b = ((FeSub*)((char*)self->m684 + 0xDC))->s5();
        r = fn_804F9B14(self, b, a);
        r += fn_804FA950(self);
        self->m378 = r;
    } else
        r = self->m378;
    char buf[100];
    sprintf(buf, "%d", r);
    self->m650->v30(buf);
    return r;
}

extern "C" FE_OVERLAY int fn_804F9C64(void* l, int k)
{
    int r = 12;
    switch (k) {
    case 4:
        r = 12;
        break;
    case 5:
        r = 7;
        break;
    case 6:
        r = 13;
        break;
    case 7:
        r = 8;
        break;
    case 8:
        r = 16;
        break;
    case 9:
        r = 14;
        break;
    case 10:
        r = 17;
        break;
    case 11:
        r = 15;
        break;
    case 12:
        r = 21;
        break;
    case 13:
        r = 22;
        break;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804F9F14(FeCap* self, int x)
{
    fn_804FA1AC(self, 2, x);
    Unk8007FF8C_G* g = (Unk8007FF8C_G*)lbl_8061930C;
    int t = fn_804FA320(self, x);
    for (int i = 0; i <= 0x28; i++)
        self->m4F0[i] = fn_80080110(g, t, i);
    fn_804F9B84(self);
}

extern "C" FE_OVERLAY void fn_804F9F9C(FeCap* self, int b, int c)
{
    if (b != 0)
        fn_804FA1AC(self, 1, c);
    else
        fn_804FA1AC(self, 0, 0);
}

/* near-miss: retail keeps i in r4 and scales it per branch (no mr r10,r4); ours reuses r4 as a table pointer (6 slots differ) */
extern "C" FE_OVERLAY float fn_804FA098(FeS23* self, int i, float x)
{
    float r = 0.0f;
    float* a;
    float* b;
    if (self->m870 != 0) {
        a = lbl_80622260;
        b = lbl_80622280;
    } else {
        a = lbl_80622220;
        b = lbl_80622240;
    }
    r = b[i] * x + a[i];
    return r;
}

/* near-miss: retail loads a[i] inside each branch and b[i] after the join; same register-reuse problem as fn_804FA098 */
extern "C" FE_OVERLAY float fn_804FA104(FeS23* self, int i, int flag, float x)
{
    float r = 0.0f;
    float* a;
    float* b;
    if (self->m870 != 0 && flag == 0) {
        a = lbl_80622260;
        b = lbl_80622280;
    } else {
        a = lbl_80622220;
        b = lbl_80622240;
    }
    r = (x - a[i]) / b[i];
    if (r < 0.0f)
        r = 0.0f;
    else if (!(r <= 1.0f))
        r = 1.0f;
    return r;
}

extern "C" FE_OVERLAY void fn_804FA1AC(FeCap* self, int mode, int x)
{
    int sel = -1;
    if (x != 0) {
        sel = fn_804FA320(self, x);
        if (mode == 1)
            ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A808(0x31, x, sel);
    } else if (mode == 3) {
        int k = ((FeSub*)((char*)self->m684 + 0xDC))->s5();
        sel = lbl_805FD3F4[k];
    }
    for (int i = 0; i <= 0xD; i++)
        fn_804FA374(self, i, fn_804FA284(self, i), mode, x, sel);
}

extern "C" FE_OVERLAY int fn_804FA284(void* self, int v)
{
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
    case 3:
        return 2;
    case 4:
    case 5:
        return 3;
    case 6:
    case 7:
        return 4;
    case 8:
    case 9:
        return 5;
    case 10:
    case 11:
        return 6;
    case 12:
    case 13:
        return 7;
    }
    return 7;
}

extern "C" FE_OVERLAY int fn_804FA320(void* self, int v)
{
    for (int i = 0; i <= 0x18; i++) {
        if (v == fn_800765A8(i))
            return i;
    }
    return -1;
}

extern "C" FE_OVERLAY float fn_804FA7BC(void* self, float x)
{
    Unk8007FF8C_G* g = (Unk8007FF8C_G*)lbl_8061930C;
    float a = fn_80080110(g, 0x18, 0xD);
    fn_800800C8(g, 0x18, x, 0xD);
    float b = fn_80080110(g, 0x18, 0xD);
    fn_800800C8(g, 0x18, a, 0xD);
    return b;
}

extern "C" FE_OVERLAY float fn_804FA840(FeS23* self, int i, float x)
{
    float t = fn_804FA098(self, i, x);
    if (!(t >= lbl_80622220[i]))
        t = lbl_80622220[i];
    else if (!(t <= lbl_80622220[i] + lbl_80622240[i]))
        t = lbl_80622220[i] + lbl_80622240[i];
    t = fn_804FA7BC(self, t);
    float r = fn_804FA104(self, i, 1, t);
    return r;
}

extern "C" FE_OVERLAY void fn_804FA8F0(FeCap* self, int i, float x)
{
    float t = fn_804FA104((FeS23*)self, fn_804FA284(self, i), 0, x);
    fn_800DC580(self->m7F4[i], t);
}

extern "C" FE_OVERLAY int fn_804FA950(FeCap* self)
{
    int sum = 0;
    int i = 0;
    float x = 0.0f;
    int m = ((FeSub*)((char*)self->m684 + 0xDC))->s5();
    do {
        int k = fn_804FA284(self, i);
        x = fn_800DC77C(self->m7F4[i]);
        i++;
        sum += fn_804FAA00(self, k, m, x);
    } while (i <= 0xD);
    return sum;
}

extern "C" FE_OVERLAY int fn_804FAA00(FeCap* self, int i, int sel, float x)
{
    float t = fn_804FA840((FeS23*)self, i, x);
    int v = 0;
    switch (sel) {
    case 0:
        v = lbl_805FD394[i];
        break;
    case 1:
        v = lbl_805FD3B4[i];
        break;
    case 2:
        v = lbl_805FD3D4[i];
        break;
    }
    return (int)((float)v * t);
}

extern "C" FE_OVERLAY void fn_804FAAD0(FeCap* self)
{
    int k = ((FeSub*)((char*)self->m684 + 0xDC))->s5();
    float* e = (float*)fn_802CA5A0((Unk802CA5A0_Elem*)((char*)lbl_8061E978 + 0x125E0), lbl_805FD3F4[k]);
    fn_804FA1AC(self, 3, 0);
    for (int i = 0; i <= 0x28; i++)
        self->m4F0[i] = fn_804FAB88(self, e, i);
    fn_804F9B84(self);
}

/* near-miss: retail forms the byte offsets i*8 / (i*8|4) with lfsx and loads 0.5f from a global before the sum (14 slots differ) */
extern "C" FE_OVERLAY float fn_804FAB88(void* self, float* a, int i)
{
    float x = a[i * 2];
    float y = a[i * 2 + 1];
    return (x + y) * 0.5f;
}

/* near-miss: retail tests r == 10 with cmpwi/bne; ours folds to xori/subfic/adde (3 slots differ) */
extern "C" FE_OVERLAY int fn_804FB7F4(FeS19* s)
{
    if (s->m630 != 0)
        return 0;
    int r = ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A6A0(5, s->m86C);
    if (r == 0)
        return 0;
    if (r != 10)
        return 0;
    return 1;
}

/* near-miss: retail tests r == 10 with cmpwi/bne; ours folds to xori/subfic/adde (3 slots differ) */
extern "C" FE_OVERLAY int fn_804FB84C(FeS19* s)
{
    if (s->m630 != 2)
        return 0;
    int r = ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A6A0(5, s->m86C);
    if (r == 0)
        return 0;
    if (r != 10)
        return 0;
    return 1;
}

extern "C" FE_OVERLAY void fn_804FB8A4(FeS19* s, int a, int b)
{
    s->m630 = a;
    s->m86C = b;
    if (a == 1)
        fn_803043D4(1, b);
    else
        fn_803043D4(0, b);
}

extern "C" FE_OVERLAY int fn_804FB8EC(FeCap3* s, int x)
{
    if (x == s->m740[0] || x == s->m740[1] || x == s->m740[2] || x == s->m740[3] || x == s->m740[4] || x == s->m740[5]
        || x == s->m740[6] || x == s->m740[7] || x == s->m740[8] || x == s->m740[10] || x == s->m740[11]
        || x == s->m740[12] || x == s->m740[13] || x == s->m740[14] || x == s->m740[15] || x == s->m740[16]
        || x == s->m740[17] || x == s->m740[18])
        return 1;
    return 0;
}

extern "C" FE_OVERLAY void fn_804FBF58(void* p)
{
    FeSq* self = (FeSq*)p;
    FeObj* r = 0;
    if (self->m844->m24 < 0) {
        if (self->a[0]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("TOPLEFTSQUARE", 1));
        else if (self->a[1]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("TOPSQUARE", 1));
        else if (self->a[2]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("TOPRIGHTSQUARE", 1));
        else if (self->a[3]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("LEFTSQUARE", 1));
        else if (self->a[4]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("CENTERSQUARE", 1));
        else if (self->a[5]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("RIGHTSQUARE", 1));
        else if (self->a[6]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("BOTTOMLSQUARE", 1));
        else if (self->a[7]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("BOTTOMSQUARE", 1));
        else if (self->a[8]->m24 & 0x10000000)
            r = fn_800C8034(self->p0->v32("BOTTOMRSQUARE", 1));
    } else if (self->m848->m24 < 0) {
        if (self->b[0]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("TOPLEFTSQUARE", 1));
        else if (self->b[1]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("TOPSQUARE", 1));
        else if (self->b[2]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("TOPRIGHTSQUARE", 1));
        else if (self->b[3]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("LEFTSQUARE", 1));
        else if (self->b[4]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("CENTERSQUARE", 1));
        else if (self->b[5]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("RIGHTSQUARE", 1));
        else if (self->b[6]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("BOTTOMLSQUARE", 1));
        else if (self->b[7]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("BOTTOMSQUARE", 1));
        else if (self->b[8]->m24 & 0x10000000)
            r = fn_800C8034(self->p1->v32("BOTTOMRSQUARE", 1));
    }
    if (r != 0) {
        ((FeObj1*)r)->v8(1);
        ((FeObj1*)r)->v16(1);
        ((FeObj1*)r)->v14(1);
        r->m24 &= 0xFEFFFFFF;
    }
}

extern "C" FE_OVERLAY int fn_804FD3C4(FeS20* s, int a)
{
    if (a == s->m844 || a == s->m848) {
        fn_804FC260(s);
        fn_804FBF58(s);
    }
    return 0;
}

extern char lbl_80680EB8[];
extern "C" FE_OVERLAY FeRawBig* fn_804FDB24(FeRawBig* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D1070((FeScr6Raw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80680EB8;
    self->m10EC = 0;
    self->m10F0 = 0;
    self->m10F4 = 0;
    self->m10F8 = 0;
    self->m10FC = 0;
    self->m1100 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804FDB84(FeBigS* self)
{
    fn_804D10D8(self);
    self->m10EC = fn_800C805C(self->v32("LEAGUESG", 1));
    self->m10F4 = fn_800C8058(self->m10EC->v32("LEAGUETL", 1));
    self->m10F0 = fn_800C805C(self->v32("TEAMSG", 1));
    self->m10F8 = fn_800C8058(self->m10F0->v32("TEAMTL", 1));
    self->m10FC = fn_800C8054(self->m10F0->v32("TEAMSL", 1));
    self->m1100 = fn_800B7AB8(UiGetMsgMgr(), "BATPITCHINFO");
}

extern "C" FE_OVERLAY void fn_804FE0F4(FeBigS* self, int kind)
{
    if (kind == 4) {
        ((FeObj1*)self->m10F0)->v8(0);
        ((FeObj1*)self->m10F0)->v16(0);
        FeAr a;
        int buf[0xCB2];
        FeArBase(&a, buf, 0xCB2);
        FeArMid(&a);
        FeArD2(&a);
        fn_80538368(&a, 0);
        ((FeObj1*)self)->v84((int)&a);
        FeArDtor(&a);
    } else {
        int m = 0;
        ((FeObj1*)self->m10F0)->v8(1);
        ((FeObj1*)self->m10F0)->v16(1);
        if (kind == 0) {
        } else if (kind == 1)
            m = 1;
        else if (kind == 2)
            m = 2;
        else if (kind == 3)
            m = 3;
        fn_800D0074((FeSub*)((char*)self->m10F8 + 0xDC), m, 0);
        fn_800D0074((FeSub*)((char*)self->m10FC + 0x98), m, 0);
        ((FeObj2*)self)->v67(5, 0);
    }
}

extern "C" FE_OVERLAY void fn_804FE2C4(FeCap* self)
{
    if (self->m134->v59() > 0) {
        fn_800B555C();
        int t = fn_800B57EC();
        int k = fn_804D1278(self);
        fn_80122D40(self->m1100, k, 1, 1, t ^ 1, 0);
    } else
        fn_80123610(self->m1100);
}
