/*
 * Front-end overlay code, .frontend_codeoverlay 0x804F81E0-0x804FE34C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern "C" int fn_804FB7F4(FeS19* s);
extern "C" int fn_804FB84C(FeS19* s);

extern "C" FE_OVERLAY void fn_804F84A0(void)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "CREATEAPLAYER");
    ((FeObj1*)p)->v8(1);
    ((FeObj1*)p)->v16(1);
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
