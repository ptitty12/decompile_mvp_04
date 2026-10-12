/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803F2000-0x803F73B0 (code-only unit, 36 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern unsigned short lbl_806EEA5C[2];
extern unsigned short lbl_806EEA58[2];

struct RcRef {
    virtual void v0();
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
    virtual void v26(int);
    virtual void v27();
    virtual void v28();
    virtual void v29();
};

struct RcAllocIf {
    virtual void* v0(int, void*);
    virtual void v1(int, int);
};

struct RcReq {
    int kind;
    int val;
    RcReq* next;
    RcReq(int k, int v)
    {
        kind = k;
        val = v;
        next = 0;
    }
};

struct RcRefObj : RcRef {
    int m4, m8, mC, m10;
    int m14;
};

extern RcRef* lbl_806EEA60;
extern int lbl_806EEA70;
extern RcAllocIf* lbl_806EEA74;
extern char lbl_8060E5E0[];

extern "C" void fn_803F7098(int*);

struct RcVO {
    virtual void v0();
};

extern "C" int fn_803F7584(void*, int, void*, int*);
extern "C" int fn_803F6754(short**);

struct RcEv;

struct RcTgt0 {
    char d[0x4c];
};

struct RcTgt : RcTgt0 {
    virtual void v0(RcEv*);
    virtual void v1(RcEv*);
};

struct RcEvBase {
    RcTgt* m0;
    int m4;
    int m8;
    int mC;
};

struct RcEv0 : RcEvBase {
    virtual void s0();
    virtual void s1();
};

struct RcEv : RcEv0 {
    union {
        short s;
        int i;
    } m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};

struct RcSys {
    int m0, m4;
    char pad8[0x2c];
    int m34, m38, m3C;
    char pad40[0x2c];
    int m6C, m70, m74, m78, m7C, m80, m84, m88;
};

extern RcEv lbl_806AAF2C;
extern RcEv lbl_806AB3AC;
extern RcSys lbl_806AB4C8;
extern int lbl_806AB3C4[3];
extern int lbl_806AAF50[3];
extern void* lbl_806EEA2C;
extern "C" int fn_803F78CC(void*, void*);

struct RcD {
    virtual RcD* v0();
    virtual void v1(int, int);
    virtual void v2();
    virtual void v3();
};

struct RcE {
    virtual RcD* v0();
    virtual void v1();
    virtual void v2();
};

struct RcPack {
    RcD* a;
    RcD* b;
    RcD* c;
    short* (*d)(int);
};

struct RcDt1 {
    void* vp;
    RcPack p;
    int m14;
    RcD* m18;
};

struct RcDt2 {
    void* vp;
    char pad4[0x2b4];
    RcD* m2B8;
    int m2BC;
    int m2C0;
};

extern char lbl_8060E3F8[];
extern char lbl_8060E4F8[];
extern char lbl_8060E690[];
extern char lbl_8060E6E8[];
extern "C" void fn_803F6FC4(int a, int b);
extern "C" void fn_803F6AD8(int a);
extern short* (*lbl_806EEA68)(int);

extern "C" char fn_803F2404(const char* wild, const char* str)
{
    const char* cp = 0;
    const char* mp = 0;
    while (*str != 0 && *wild != '*') {
        if (*wild != *str && *wild != '?')
            return 1;
        str++;
        wild++;
    }
    while (*str != 0) {
        if (*wild == '*') {
            if (*++wild == 0)
                return 0;
            mp = wild;
            cp = str + 1;
        } else if (*wild == *str || *wild == '?') {
            wild++;
            str++;
        } else {
            wild = mp;
            str = cp++;
        }
    }
    while (*wild == '*')
        wild++;
    return *wild;
}

/* near-miss: 2 slots; the m14 / m34 stores of the 0x65 state are in the other order */
enum RcFindState { RFS_INIT = 0, RFS_START = 0x65, RFS_WAIT = 0x69, RFS_DONE = 0x7c };

extern "C" void fn_803F28A4()
{
    switch ((RcFindState)lbl_806AAF2C.m8) {
    case RFS_INIT:
        lbl_806AAF2C.m8 = 0x65;
        lbl_806AAF2C.m24 = 0;
        lbl_806AAF2C.mC = 0;
    case RFS_START: {
        RcEv* e = &lbl_806AB3AC;
        lbl_806AAF2C.mC = 0;
        e->m1C = 0;
        lbl_806AAF2C.m8 = 0x69;
        e->m14.s = 0;
        e->m18 = -1;
        e->m34 = lbl_806AAF2C.m4;
        e->m14.i = lbl_806AAF2C.m14.i;
        e->m30 = 0xf;
        e->m8 = 0;
        e->m2C = 0;
        e->m38 = 0;
        e->m3C = 0;
        e->m0->v0(e);
        break;
    }
    case RFS_WAIT:
        if (lbl_806AB3C4[0] != 0 && lbl_806AB3C4[0] != 3)
            lbl_806AAF2C.m24 = 0;
        else
            lbl_806AAF50[0] = 1;
        lbl_806AAF2C.m18 = lbl_806AB3C4[0];
        lbl_806AAF2C.m8 = 0x7c;
        lbl_806AAF2C.mC = 0;
    case RFS_DONE: {
        RcEv* s = &lbl_806AAF2C;
        if (s->m24 != 0) {
            fn_803F78CC(lbl_806EEA2C, &s->m14);
            s->m24 = 0;
        }
        RcSys* y = &lbl_806AB4C8;
        y->m0 = 2;
        y->m34 = s->m14.i;
        y->m4 = s->m18;
        y->m6C = 0;
        y->m70 = 0;
        y->m74 = 0;
        y->m78 = 0;
        y->m7C = 0;
        y->m80 = 0;
        y->m84 = 0;
        y->m88 = 0;
        s->m0->v1(s);
        break;
    }
    }
}

extern "C" unsigned short* fn_803F644C(void* l, int k)
{
    if (k == 1)
        return lbl_806EEA5C;
    return lbl_806EEA58;
}

extern "C" void fn_803F67C8()
{
    short* a = lbl_806EEA68(1);
    short* b = lbl_806EEA68(2);
    fn_803F6754(&a);
    fn_803F6754(&a);
    fn_803F6754(&a);
    fn_803F6754(&b);
    fn_803F6754(&b);
    fn_803F6754(&b);
}

extern "C" RcDt1* fn_803F684C(RcDt1* self, RcPack* src)
{
    self->vp = lbl_8060E3F8;
    self->p = *src;
    self->m14 = 1;
    self->m18 = 0;
    ((RcE*)self->p.a)->v2();
    ((RcE*)self->p.c)->v1();
    ((RcE*)self->p.b)->v1();
    lbl_806EEA68 = self->p.d;
    fn_803F6AD8((int)self->p.d);
    self->m18 = ((RcE*)self->p.c)->v0();
    return self;
}

extern "C" void fn_803F693C(RcDt1* self, int c)
{
    self->vp = lbl_8060E3F8;
    self->m18->v2();
    self->p.b->v2();
    self->p.c->v2();
    self->p.a->v3();
    self->vp = lbl_8060E4F8;
    if (c & 1)
        fn_803F6FC4((int)self, 0x1c);
}

extern char lbl_8060E4F8[];

extern "C" void fn_80377408(void*);

extern "C" int fn_803F6A04(int* o)
{
    int v = o[5] + 1;
    o[5] = v;
    return v;
}

extern "C" int fn_803F6A18(RcRefObj* o)
{
    ((RcRef*)o)->v29();
    int c = o->m14 - 1;
    o->m14 = c;
    if (c == 0) {
        if (o == (RcRefObj*)lbl_806EEA60)
            lbl_806EEA60 = 0;
        if (o != 0)
            ((RcRef*)o)->v26(3);
    }
    return o->m14;
}

extern "C" void fn_803F6AA4(void** self, int c)
{
    *self = lbl_8060E4F8;
    if (c & 1)
        fn_80377408(self);
}

extern char lbl_8060E358[];

extern "C" void fn_803F6AD8(int a)
{
    lbl_806EEA70 = a;
}

extern "C" int fn_803F6F18(unsigned short* p)
{
    int n = 0;
    if (p != 0) {
        while (*p++ != 0)
            n++;
    }
    return n;
}

extern "C" void fn_803F6F48(RcAllocIf* a)
{
    lbl_806EEA74 = a;
}

extern "C" void fn_803F6FC4(int a, int b)
{
    lbl_806EEA74->v1(a, b);
}

extern "C" void** fn_803F7004(void** o)
{
    *o = lbl_8060E5E0;
    ((int*)o)[4] = 0;
    fn_803F7098((int*)o);
    return o;
}

extern "C" void fn_803F7048(RcRefObj* o, int a, int b)
{
    ((RcVO*)o)->v0();
    o->m4 = a;
    o->m10 = b;
}

extern "C" void fn_803F7098(int* o)
{
    o[2] = 0;
    o[3] = 0;
    o[5] = 0;
}

extern "C" void fn_803F70AC(RcRefObj* x, int a, void* b)
{
    int r = fn_803F7584((void*)x->m4, a, b, 0);
    x->m8 += r;
    x->mC += 1;
    x->m14 = 1;
}

extern "C" void fn_803F7100(void** self, int c)
{
    *self = lbl_8060E358;
    if (c & 1)
        fn_80377408(self);
}

extern "C" int fn_803F7134(int* o)
{
    return o[2];
}

extern "C" void fn_803F7310(RcDt2* self, int c)
{
    self->vp = lbl_8060E690;
    self->m2B8->v1(self->m2BC, 0);
    self->m2B8->v1(self->m2C0, 0);
    self->vp = lbl_8060E6E8;
    if (c & 1)
        fn_803F6FC4((int)self, 0x2d0);
}
