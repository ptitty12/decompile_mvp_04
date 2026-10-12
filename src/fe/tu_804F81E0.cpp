/*
 * Front-end overlay code, .frontend_codeoverlay 0x804F81E0-0x804FE34C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

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
