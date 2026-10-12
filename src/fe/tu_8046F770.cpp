/*
 * Front-end overlay code, .frontend_codeoverlay 0x8046F770-0x80471EBC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"
struct FeNew4C4 {
    char pad0[0x4C4];
    int m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
};
extern "C" {
int fn_800B5758(void* s);
int strcmp(const char* a, const char* b);
char* strcpy(char* a, const char* b);
char* strncpy(char* a, const char* b, unsigned n);
}
extern int lbl_806217B0;
extern int lbl_806217B4;
extern int lbl_806217B8;
extern int lbl_806217BC;
extern "C" {
void fn_800E8BCC__FP3UiS(FeScrL* x);
FeW* fn_800C8044();
FeW* fn_800C8060();
void* fn_800C8040();
}
extern void* lbl_8061977C;
extern "C" {
int fn_800A2E90(void* g);
void fn_800DD44C__FP13Unk800DD610_PPvi(void* a, void* b, int c);
const char* fn_80090880__FP11Unk80090880(void* t, int id);
void fn_804031F8(char* out, const char* a, const char* b);
void fn_80471390(FeScrL* x);
}
struct FeDate4 {
    unsigned char a;
    unsigned char b;
    unsigned short c;
    FeDate4() {}
};
extern "C" {
int fn_8057CE00(int v);
int fn_8007FB2C__FP13Unk8007F198_Ci(void* g, int a);
int fn_8007FBC0__FP13Unk8007F198_Cii(void* g, int a, int b);
void fn_80329FA0(void* buf, ...);
int fn_80329E74(FeDate4 d);
}
extern "C" {
void fn_800DC50C__FP3UiSff(int a, float b, float c);
}

extern "C" {

FE_OVERLAY FeScrK* fn_8046F770(FeScrK* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80679128);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8046F7BC(FeScrK* x)
{
    fn_800ECE34(x);
    fn_800E49A4();
}

FE_OVERLAY void fn_8046FAC8(FeScrK* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_8046FAE8(FeScrK* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8046FB08(void) {}

FE_OVERLAY void fn_8046FB0C(void) {}

FE_OVERLAY void fn_8046FB10(void) {}

FE_OVERLAY int fn_8046FB14(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY int fn_8046FB80(FeScrK* x)
{
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY int fn_8046FBDC(FeScrK* x)
{
    x->m134->fn_vslot56();
    return 1;
}

FE_OVERLAY int fn_8046FC18(FeScrK* x)
{
    x->m134->fn_vslot57();
    return 1;
}

FE_OVERLAY int fn_8046FC54(FeScrK* x)
{
    x->m134->fn_vslot54();
    return 1;
}

FE_OVERLAY int fn_8046FC90(FeScrK* x)
{
    x->m134->fn_vslot55();
    return 1;
}

FE_OVERLAY int fn_8046FCCC(FeScrK* x, FeW* w)
{
    int r;
    if (w == x->m134) {
        fn_800B7ADC(FeGetMgr(), x);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

FE_OVERLAY void fn_8046FD3C(FeScrK* x, char* dst)
{
    char buf[16];
    int r;
    const char* s = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x610);
    if (fn_800B5758(fn_800B555C()) != 0) {
        s = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x61E);
    }
    strcpy(buf, (char*)x->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC);
    if (strcmp(buf, "NEWOWNER") == 0) {
        strcpy(buf, "NEWFRANCHISE");
    } else {
        r = strcmp(buf, "LOADFRANCHISE");
        if (r == 0) {
            FeNew4C4* n = (FeNew4C4*)((char*)fn_800B555C() + 8);
            n->m4C4 = r;
            n->m4C8 = 0x01101311;
            n->m4CC = r;
            n->m4D0 = (int)s;
        } else {
            r = strcmp(buf, "LOADOWNER");
            if (r == 0) {
                FeNew4C4* n = (FeNew4C4*)((char*)fn_800B555C() + 8);
                n->m4C4 = r;
                n->m4C8 = 0x02131311;
                n->m4CC = r;
                n->m4D0 = (int)s;
                strcpy(buf, "LOADFRANCHISE");
            }
        }
    }
    strncpy(dst, buf, 16);
}

FE_OVERLAY FeScrL* fn_8046FED8(FeScrL* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, 0, c, d, e, f, g, h);
    self->SetVptr(lbl_80678D58);
    self->m2DC = 0;
    self->m2E0 = 0;
    self->m2E4 = 0;
    self->m2E8 = 1;
    self->m2EC = 0;
    self->m2F0 = 0;
    self->m2F4 = 0;
    self->m2F8 = 0;
    self->m2FC = 0;
    self->m300 = 0;
    self->m30C = 0;
    self->m310 = 0;
    self->m314 = 1;
    self->m318 = 0;
    self->m31C = 0;
    self->m320 = 0;
    self->m324 = 0;
    self->m328 = 0;
    self->m32C = lbl_805F5BEC;
    self->m330 = 0;
    self->m334 = 0;
    self->m338 = 0;
    self->m33C = -1;
    self->m340 = 0;
    self->m344 = 0;
    self->m348 = 0;
    self->m34C = 0;
    self->m350 = 0;
    self->m354 = 0;
    self->m358 = 0x1BC9;
    return self;
}

FE_OVERLAY void fn_8046FFB0(FeScrL* x)
{
    fn_800E8BCC__FP3UiS(x);
    x->fn_vslot32("FANCY", 1);
    FeW* w = fn_800C8044();
    x->m32C = (float)w->fn_vslot29("METER/METERBAR")->m2A;
    w->fn_vslot32("DESTNDATE", 1);
    x->m344 = (int)fn_800C8040();
    w->fn_vslot32("CURDATE", 1);
    x->m340 = (int)fn_800C8040();
    w->fn_vslot32("CELL", 1);
    x->m350 = (int)fn_800C8060();
    fn_8047091C(x);
    fn_80470C08(x, 0);
    x->fn_vslot16(0);
    x->fn_vslot8(0);
    lbl_806217B0 = 0;
    lbl_806217B4 = 0;
    lbl_806217B8 = 0;
    lbl_806217BC = 0;
}

FE_OVERLAY void fn_80470404(FeScrL* x, int a, int b, int c, int d, int e)
{
    x->m318 = a;
    x->m314 = 0;
    fn_800A29C4(lbl_80619948, a);
    x->m330 = 1;
    fn_80470E30(x, b, c, d, e);
}

FE_OVERLAY void fn_80470478(FeScrL* x, int a, int b, int c, int d, int e)
{
    int v = a + 1;
    x->m314 = 1;
    x->m318 = v;
    fn_800A29C4(lbl_80619948, v);
    x->m330 = 1;
    fn_80470E30(x, b, c, d, e);
}

FE_OVERLAY void fn_804704EC(FeScrL* x, int a, int b, int c, int d)
{
    x->m314 = 3;
    fn_800A2948(lbl_80619948, a);
    x->m330 = 1;
    fn_80470E30(x, a, b, c, d);
}

FE_OVERLAY void fn_80470558(FeScrL* x, int a, int b, int c, int d)
{
    x->m314 = 4;
    int v;
    if (b != 0) {
        v = fn_800C2208((char*)fn_800B555C() + 8);
    } else {
        v = fn_800A2AE8(lbl_80619948);
    }
    int w = v + 1;
    x->m318 = w;
    fn_800A29C4(lbl_80619948, w);
    x->m330 = 1;
    fn_80470E30(x, a, b, c, d);
}

FE_OVERLAY void fn_804705F0(FeScrL* x, int a, int b, int c)
{
    FeDate4 d1;
    FeDate4 d2;
    int k;
    x->m314 = 5;
    k = 4;
    if (fn_8057CE00(0) == -1) {
        k = 5;
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
        ((void (*)(FeGlobal80619948*))fn_800A2948)(lbl_80619948);
        x->fn_vslot116();
    }
    int q = fn_8007FB2C__FP13Unk8007F198_Ci(lbl_8061930C, 0) - 1;
    fn_80329FA0(&d1, fn_8007FBC0__FP13Unk8007F198_Cii(lbl_8061930C, q, 0));
    fn_80329FA0(&d2, x->m318);
    d2.b = 1;
    d2.a = 1;
    d2.c = d1.c + 1;
    x->m318 = fn_80329E74(d2);
    x->m330 = 2;
    fn_80470E30(x, a, b, k, c);
}

/* near-miss: 8 slots; same constant register swap as fn_804707B8 */
FE_OVERLAY void fn_80470710(FeScrL* x, int a)
{
    FeGlobal80619948* g = lbl_80619948;
    x->m324 = a;
    x->m334 = 0;
    x->m338 = 1;
    int v = fn_800A2AE8(g);
    x->m318 = v;
    fn_800A29C4(g, v);
    x->m330 = 5;
    x->m314 = 0xD;
    x->fn_vslot89(0);
    x->fn_vslot8(0);
}

/* near-miss: 4 slots; retail puts the 0 in r9 and the 1 in r0 (we swap them); all 120 store orders tried */
FE_OVERLAY void fn_804707B8(FeScrL* x, int a)
{
    x->m334 = 0;
    x->m338 = 1;
    x->m324 = a;
    x->m314 = 0xD;
    x->m330 = 4;
    x->fn_vslot89(0);
    x->fn_vslot8(0);
}

FE_OVERLAY void fn_8047083C(FeScrL* x)
{
    switch (x->m314) {
    case 0:
    case 1:
    case 4:
        fn_800A29C4(lbl_80619948, x->m318);
        break;
    case 5:
        fn_800A29C4(lbl_80619948, x->m318);
        x->m330 = 1;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    case 3:
        ((void (*)(FeGlobal80619948*))fn_800A2948)(lbl_80619948);
        break;
    case 13:
        x->fn_vslot8(0);
        fn_800A29C4(lbl_80619948, x->m318);
        break;
    }
}

FE_OVERLAY void fn_80470C08(FeScrL* x, int c)
{
    if (c != 0) {
        ((FeW*)x->m348)->fn_vslot32("TEXT", 1)->fn_vslot8(0);
        ((FeW*)x->m348)->fn_vslot32("VARTEXT", 1)->fn_vslot8(1);
        ((FeW*)x->m348)->fn_vslot32("VARTEXT", 1);
        fn_800C8044()->fn_vslot32("CAPTION", 1);
        FeW* w = (FeW*)fn_800C8040();
        switch (c) {
        case 1: ((FeWV*)w)->s29(0x392D); break;
        case 2: ((FeWV*)w)->s29(0x3926); break;
        case 3: ((FeWV*)w)->s29(0x392B); break;
        case 4: ((FeWV*)w)->s29(0x392C); break;
        case 5: ((FeWV*)w)->s29(0x3923); break;
        case 6: ((FeWV*)w)->s29(0x3925); break;
        case 7: ((FeWV*)w)->s29(0x3924); break;
        case 8: ((FeWV*)w)->s29(0x3921); break;
        case 9: ((FeWV*)w)->s29(0x3922); break;
        case 10: ((FeWV*)w)->s29(0x419F); break;
        case 11: ((FeWV*)w)->s29(0x4FBD); break;
        }
    }
}

/* near-miss: store/load order of the m338/m328/m324 group differs */
FE_OVERLAY void fn_80470E30(FeScrL* x, int a, int b, int c, int d)
{
    FeGlobal80619948* g = lbl_80619948;
    x->m338 = b;
    x->m328 = g->m8C;
    x->m324 = d;
    x->m334 = 0;
    if (x->m33C != a) {
        x->m33C = a;
        fn_8047091C(x);
    }
    fn_80470C08(x, c);
    x->fn_vslot89(0);
    if (x->m314 != 5) {
        x->fn_vslot116();
    }
}

FE_OVERLAY int fn_80470EDC(FeScrL* x)
{
    if (lbl_80619948->m74 != 2 && (unsigned)x->m314 <= 1) {
        fn_80471D8C(x);
    }
    return 1;
}

FE_OVERLAY void fn_80470F20(FeScrL* x)
{
    x->m330 = 0;
    x->fn_vslot89(1);
    if (x->m334 == 0 && x->m338 == 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
    }
    if (x->m30C != 0) {
        x->m30C(x->m334, x->m324);
    }
}

FE_OVERLAY void fn_80470FAC(FeScrL* x)
{
    char sp8[200];
    char spD0[200];
    FeDate4 d;
    FeGlobal80619948* g = lbl_80619948;
    if (fn_800A2E90(g) != 0) {
        void* h = lbl_8061930C;
        int a0 = fn_8007FB2C__FP13Unk8007F198_Ci(h, 0) - 1;
        int a1 = fn_8007FB2C__FP13Unk8007F198_Ci(h, 1) - 1;
        int a2 = fn_8007FB2C__FP13Unk8007F198_Ci(h, 2) - 1;
        int a3 = fn_8007FB2C__FP13Unk8007F198_Ci(h, 3) - 1;
        x->m2F4 = fn_8007FBC0__FP13Unk8007F198_Cii(h, a0, 0);
        x->m2F8 = fn_8007FBC0__FP13Unk8007F198_Cii(h, a1, 1);
        x->m2FC = fn_8007FBC0__FP13Unk8007F198_Cii(h, a2, 2);
        x->m300 = fn_8007FBC0__FP13Unk8007F198_Cii(h, a3, 3);
    }
    if (x->m33C == 1) {
        fn_80329FA0(&d, g->m90);
        fn_800DD44C__FP13Unk800DD610_PPvi(&d, sp8, 2);
        fn_804031F8(spD0, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x41C2), sp8);
        ((FeWV*)x->m344)->s28(spD0);
    }
    fn_80471390(x);
}

FE_OVERLAY void fn_80471830(FeScrL* x)
{
    float f;
    int lo = x->m328;
    FeGlobal80619948* g = lbl_80619948;
    int cur = g->m84;
    int hi = g->m90;
    if (lo != hi) {
        f = (float)(cur - lo) / (float)(hi - lo);
    } else {
        f = 1.0f;
    }
    if (!(f >= 0.0f)) {
        f = 0.0f;
    }
    if (!(f <= 1.0f)) {
        f = 1.0f;
    }
    fn_800DC50C__FP3UiSff(x->m34C, x->m32C, f);
}

FE_OVERLAY void fn_80471910(FeScrL* x)
{
    x->fn_vslot8(0);
}

FE_OVERLAY void fn_80471948(FeScrL* x)
{
    FeObj138* w = (FeObj138*)fn_800B7A94(FeGetMgr(), lbl_805F5CB8);
    if (w != 0) {
        w->m138 = 1;
    }
    x->fn_vslot8(1);
}

FE_OVERLAY void fn_804719D0(FeScrL* x)
{
    FeW* w = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4ED4);
    if (w != 0) {
        w->fn_vslot39();
    }
    fn_800EAC30(x);
}

FE_OVERLAY int fn_80471D30(FeScrL* x, FeEvt* e)
{
    if (e->m1C == 3) {
        if (fn_8040B574(e->name, lbl_805F5D84) == 0) {
            fn_80471D8C(x);
        }
    }
    return 0;
}

FE_OVERLAY void fn_80471D8C(FeScrL* x)
{
    fn_8001BC4C()->fn_8001BDAC(0xA0);
    fn_800A2B10(lbl_80619948);
    x->m334 = 1;
}

FE_OVERLAY void fn_80471DD4(FeScrL* x, int k)
{
    if (k == 0xD || k == 7) {
        if (x->m310 != 0) {
            x->m310();
        }
    }
}

FE_OVERLAY void fn_80471E14(FeScrL* x, int k)
{
    if (k == 0xD || k == 7) {
        if (x->m310 != 0) {
            x->m310();
        }
    }
    fn_80471D8C(x);
}

FE_OVERLAY void fn_80471E68(FeScrL* x, int k)
{
    if (k == 0xD || k == 7) {
        if (x->m310 != 0) {
            x->m310();
        }
    }
    fn_8047083C(x);
}

}
