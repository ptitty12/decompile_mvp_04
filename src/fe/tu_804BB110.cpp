/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BB110-0x804BE560 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"
extern "C" FeObj* fn_800C803C(void* p);
struct FeQ4 {
    int a;
    int b;
    int c;
    int d;
};
extern char lbl_805F7E4C[];
class FeCamV {
public:
    char pad0[0xCC0];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4(int a);
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
};
struct FeObjS26 {
    char pad0[0x26];
    short m26;
    short m28;
    short m2A;
    short m2C;
};
extern char lbl_805F7DE0[];
extern char lbl_805F4450[];
extern char lbl_805F7E98[];
extern char lbl_805F7E0C[];
extern char lbl_805F7E10[];
extern char lbl_805F7E04[];
class FeObjB : public UiBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual int v30(const char* a, int b);
    virtual int v31(int a, int b);
    virtual FeObj* v32(const char* a, int b);
    virtual FeObj* v33(int a, int b);
};
extern char lbl_805F7E54[];
extern char lbl_805F7E60[];
extern float lbl_805F7DF0;
extern float lbl_805F7E18;
extern char lbl_80670C10[];
struct Unk80360F2C;
struct Unk80360EF8;
void fn_80360F2C(Unk80360F2C* s);
void fn_80360EF8(Unk80360EF8* s);
extern char lbl_80672168[];

extern char lbl_80671440[];

extern "C" FE_OVERLAY FeCam* fn_804BB110(FeCam* c)
{
    c->mCC0 = lbl_80672168;
    FeCamRec* r = c->rec;
    fn_80360F2C((Unk80360F2C*)c);
    int k = 3;
    fn_80360F2C((Unk80360F2C*)&c->m10);
    do {
        fn_80360EF8((Unk80360EF8*)r);
        r++;
    } while (k-- != 0);
    fn_804BB334(c);
    return c;
}

extern "C" FE_OVERLAY void fn_804BB17C(FeCam* c, FeObj* w, int a)
{
    ((FeCamV*)c)->s3();
    c->mCBC = w;
    ((FeCamV*)c)->s4(a);
    c->m10 = (float)((FeObjS26*)((FeObjB*)c->mCBC)->v32(lbl_805F7DE0, 1))->m26;
    c->m14 = (float)((FeObjS26*)((FeObjB*)c->mCBC)->v32(lbl_805F7DE0, 1))->m28;
    c->m18 = c->m10 + (float)((FeObjS26*)((FeObjB*)c->mCBC)->v32(lbl_805F7DE0, 1))->m2A;
    c->m1C = c->m14 + (float)((FeObjS26*)((FeObjB*)c->mCBC)->v32(lbl_805F7DE0, 1))->m2C;
    ((FeCamV*)c)->s22();
}

extern "C" FE_OVERLAY void fn_804BB3D0(FeCam* c, float a, float b, float d, float e)
{
    c->m0 = a;
    c->m4 = b;
    c->m8 = d;
    c->mC = e;
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

extern "C" FE_OVERLAY void fn_804BB64C(FeCam* c, int a, int b)
{
    char buf[7];
    if (((FeObjB*)c->mCBC)->v30(lbl_805F7E04, 1) != 0) {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E04, 1));
        fn_804089B4(buf, lbl_805F7E0C, b);
        if (w->v30(buf, 1) != 0) {
            FeObjB* w2 = (FeObjB*)fn_800C8044(w->v32(buf, 1));
            ((FeObj1*)fn_800C8040(w2->v32(lbl_805F7E10, 1)))->v29(a);
        }
    }
}

extern "C" FE_OVERLAY void fn_804BB780(FeCam* c, int a, int b)
{
    char buf[7];
    if (((FeObjB*)c->mCBC)->v30(lbl_805F7E04, 1) != 0) {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E04, 1));
        fn_804089B4(buf, lbl_805F7E0C, b);
        if (w->v30(buf, 1) != 0) {
            FeObjB* w2 = (FeObjB*)fn_800C8044(w->v32(buf, 1));
            ((FeObj1*)fn_800C8040(w2->v32(lbl_805F7E10, 1)))->v30(a);
        }
    }
}

/* near-miss: 98.5%; retail keeps the record index in r0 and the zero in r9, ours swaps the two */
extern "C" FE_OVERLAY int fn_804BB8B4(FeCam* c, int n)
{
    for (int i = 0; i < n; i++) {
        int k = c->mCB4;
        FeCamRec* r = (FeCamRec*)((char*)c + k * 0x324 + 0x24);
        r->cnt = 0;
        for (int j = 0; j < 100; j++) {
            r->p[j].a = lbl_805F7E18;
            r->p[j].b = lbl_805F7E18;
        }
    }
    c->rec[c->mCB4].cnt = n;
    return c->mCB4++;
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

extern "C" FE_OVERLAY void fn_804BB988(FeCam* c, int i, int j, float a, float b)
{
    c->rec[i].p[j].a = a;
    c->rec[i].p[j].b = b;
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

extern "C" FE_OVERLAY void fn_804BC124(FeCam* c)
{
    if (c->mCB8 & 2) {
        ((FeObj1*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E04, 1)))->v8(1);
    } else if (((FeObjB*)c->mCBC)->v30(lbl_805F7E04, 1) != 0) {
        ((FeObj1*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E04, 1)))->v8(0);
    }
}

extern "C" FE_OVERLAY int fn_804BC218(FeCam* c)
{
    if (c->m4 >= 0.0f)
        return 0;
    return (int)(-c->m4 / (c->mC - c->m4) * (c->m1C - c->m14));
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

extern "C" FE_OVERLAY void fn_804BC2F0(FeCam* c, FeQ4* v)
{
    char buf[7];
    fn_804089B4(buf, lbl_805F7E4C);
    if (((FeObjB*)c->mCBC)->v30(buf, 1) != 0) {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(buf, 1));
        if (w->v31(0xD, 1) != 0) {
            FeQ4 t = *v;
            ((FeObj1*)fn_800C803C(w->v33(0xD, 1)))->v28((int)&t);
        }
    }
}

extern "C" FE_OVERLAY void fn_804BC414(FeCam* c, float a)
{
    c->mCC4 = a;
}

extern "C" FE_OVERLAY void fn_804BC42C(FeCam* c, int a, int b)
{
    char buf[7];
    if (((FeObjB*)c->mCBC)->v30(lbl_805F7E54, 1) != 0) {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E54, 1));
        fn_804089B4(buf, lbl_805F7E60, b);
        if (w->v30(buf, 1) != 0) {
            ((FeObj1*)fn_800C8040(w->v32(buf, 1)))->v29(a);
        }
    }
}

extern "C" FE_OVERLAY void fn_804BC538(FeCam* c, int a, int b)
{
    char buf[7];
    if (((FeObjB*)c->mCBC)->v30(lbl_805F7E54, 1) != 0) {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E54, 1));
        fn_804089B4(buf, lbl_805F7E60, b);
        if (w->v30(buf, 1) != 0) {
            ((FeObj1*)fn_800C8040(w->v32(buf, 1)))->v30(a);
        }
    }
}

extern "C" FE_OVERLAY void fn_804BC644(FeCam* c, int a, int b)
{
    char buf[7];
    if (((FeObjB*)c->mCBC)->v30(lbl_805F7E54, 1) != 0) {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E54, 1));
        fn_804089B4(buf, lbl_805F7E60, b);
        if (w->v30(buf, 1) != 0) {
            ((FeObj1*)fn_800C8040(w->v32(buf, 1)))->v28(a);
        }
    }
}

extern "C" FE_OVERLAY void fn_804BC750(FeCam* c)
{
    char buf[7];
    int i = 0;
    int f = ((unsigned)c->mCB8 >> 6) & 1;
    do {
        FeObjB* w = (FeObjB*)fn_800C8044(((FeObjB*)c->mCBC)->v32(lbl_805F7E54, 1));
        fn_804089B4(buf, lbl_805F7E60, i++);
        if (w->v30(buf, 1) != 0 && f == 0) {
            ((FeObj1*)fn_800C8040(w->v32(buf, 1)))->v8(0);
        }
    } while (i <= 99);
}

extern "C" FE_OVERLAY FeRaw* fn_804BD37C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80671440;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
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

extern "C" FE_OVERLAY void fn_804BDAF8(FeScr* x, int k)
{
    UiMsg m;
    UiMsg* p;
    switch (k) {
    case 0: {
        UiMsg* q = &m;
        fn_8035682C(q);
        fn_8040B830(q->name, lbl_805F4450, 15);
        q->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), q, x);
        break;
    }
    case 1:
        fn_804BD4D0(x, 1);
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        ((FeFnOIII)fn_801251CC)(x->m138, 0, 0x37F2, 2);
        break;
    case 2:
        fn_804BD4D0(x, 0);
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        ((FeFnOIII)fn_801251CC)(x->m138, 0, 0x57FD, 1);
        break;
    case 3:
        p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F7E98, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
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

extern "C" FE_OVERLAY FeRaw* fn_804BDD58(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80670C10;
    self->m460 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m130 = 0;
    self->m460 = *(int*)((FeMgr30*)lbl_8061930C)->m30;
    return self;
}

extern "C" FE_OVERLAY void fn_804BDDC8(FeScr* x)
{
    fn_800ECE34(x);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)fn_800C8044(((FeObj*)x)->v32("ASSETGRID", 1)))->v32("GRID", 1));
    x->m138 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
    ((FeObj1*)x->m134)->v105(1);
    ((FeObj1*)x->m134)->v88(0);
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

extern "C" FE_OVERLAY void fn_804BDFB4(FeScr* x)
{
    fn_800ED254(x);
}
