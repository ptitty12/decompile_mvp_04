/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BB110-0x804BE560 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern char lbl_80671440[];
extern "C" FE_OVERLAY FeRaw* fn_804BD37C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80671440;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804BDFB4(FeScr* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY int fn_804BDC68(FeScr* x)
{
    x->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BDCA4(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BDCE0(FeScr* x)
{
    x->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BDD1C(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804BB40C(FeScr* x, int a, int b)
{
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("XAXIS", 1)))->v29(a);
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("YAXIS", 1)))->v29(b);
}

extern "C" FE_OVERLAY void fn_804BB4CC(FeScr* x, int a, int b)
{
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("XAXIS", 1)))->v30(a);
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("YAXIS", 1)))->v30(b);
}

extern "C" FE_OVERLAY void fn_804BB58C(FeScr* x, int a, int b)
{
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("XAXIS", 1)))->v28(a);
    ((FeObj1*)fn_800C8040(((FeObj*)FeP(x, 0xCBC))->v32("YAXIS", 1)))->v28(b);
}

extern "C" FE_OVERLAY void fn_804BDDC8(FeScr* x)
{
    fn_800ECE34(x);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)fn_800C8044(((FeObj*)x)->v32("ASSETGRID", 1)))->v32("GRID", 1));
    x->m138 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
    ((FeObj1*)x->m134)->v105(1);
    ((FeObj1*)x->m134)->v88(0);
}

extern "C" FE_OVERLAY void fn_804BD3D0(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* t1 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    x->m138 = (FeObj*)t1;
    fn_80124FA8(t1, x);
    ((FeFnOIII)fn_801251CC)(x->m138, 1, 6668, 0);
    ((FeFnOIII)fn_801251CC)(x->m138, 0, 22525, 1);
    ((FeFnOIII)fn_801251CC)(x->m138, 2, 23705, 3);
    FeObj* t7 = fn_800C8060(((FeObj*)x)->v32("GRID", 1));
    x->m134 = (FeObj*)t7;
    ((FeObj1*)t7)->v105(1);
    fn_804BD4D0(x, 0);
}


extern "C" FE_OVERLAY void fn_804BDEB4(FeScr* x)
{
    fn_800ECF18(x);
    fn_800DD204(fn_800C8040(((FeObj*)x)->v32("TITLE", 1)), fn_800C8038(((FeObj*)x)->v32("SH1", 1)));
    FeObj* t6 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    x->m13C = (FeObj*)t6;
    fn_80124FA8(t6, x);
    ((FeObj*)x)->v84();
    ((FeObj*)x)->v87();
}

extern "C" FE_OVERLAY void fn_804BC414(FeCam* c, float a)
{
    c->mCC4 = a;
}

extern "C" FE_OVERLAY void fn_804BB3D0(FeCam* c, float a, float b, float d, float e)
{
    c->m0 = a;
    c->m4 = b;
    c->m8 = d;
    c->mC = e;
}

extern "C" FE_OVERLAY void fn_804BC270(FeCam* c)
{
    fn_804BB334(c);
    c->mCB8 = 0x4B;
    c->mCC4 = 0.75f;
}

extern "C" FE_OVERLAY void fn_804BC2B0(FeCam* c, float a, float b)
{
    fn_804BB3D0(c, 0.0f, a, 1.0f, b);
}

extern "C" FE_OVERLAY void fn_804BB988(FeCam* c, int i, int j, float a, float b)
{
    c->rec[i].p[j].a = a;
    c->rec[i].p[j].b = b;
}

/* near-miss: retail forms the three base addresses with addi and reloads the count each time; 11 slots differ */
extern "C" FE_OVERLAY int fn_804BB92C(FeCam* c, int i, float a, float b)
{
    int o = i * 0x324;
    char* cnt = (char*)c + 0x344;
    char* pa = (char*)c + 0x24;
    char* pb = (char*)c + 0x28;
    *(float*)(pa + (*(int*)(cnt + o) * 8 + o)) = a;
    *(float*)(pb + (*(int*)(cnt + o) * 8 + o)) = b;
    int r = *(int*)(cnt + o);
    *(int*)(cnt + o) = r + 1;
    return r;
}

extern "C" FE_OVERLAY int fn_804BB9C0(FeCam* c)
{
    int m = 0;
    for (int i = 0; i < c->mCB4; i++) {
        if (c->rec[i].cnt > m)
            m = c->rec[i].cnt;
    }
    return m;
}

extern "C" FE_OVERLAY int fn_804BDAA8(int unused, int k)
{
    FeTbl30* t = ((FeMgr30*)lbl_8061930C)->m30;
    switch (k) {
    case 0:
        return t->m14;
    case 1:
        return t->m18;
    case 2:
        return t->m1C;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804BC218(FeCam* c)
{
    if (c->m4 >= 0.0f)
        return 0;
    return (int)(-c->m4 / (c->mC - c->m4) * (c->m1C - c->m14));
}
