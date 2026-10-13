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

struct RcTri {
    int a, b, c;
};

struct RcEvT : RcEv0 {
    union {
        short s;
        int i;
    } m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    RcTri m2C;
};

extern RcEvT lbl_806AAF58;
extern int lbl_806AAF6C[16];
extern int lbl_806AAF70[3];
extern "C" int fn_803F8730(void*, void*, int*, int*);
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

struct RcFeE {
    int m0, m4;
    char pad8[0x38];
    int m40, m44, m48;
    unsigned short m4C;
    char pad4E[0x1e];
    int m6C, m70, m74, m78, m7C, m80, m84, m88;
    int m8C;
    char m90[0x24];
};
struct RcFeS {
    short s0, s2;
    const char* m4;
    int m8, mC, m10;
    char m14[4];
    char m18[2];
};
inline void RcFeInit(RcFeE* e, int a, int b)
{
    e->m0 = a;
    e->m4 = b;
    e->m6C = 0;
    e->m70 = 0;
    e->m74 = 0;
    e->m78 = 0;
    e->m7C = 0;
    e->m80 = 0;
    e->m84 = 0;
    e->m88 = 0;
}
extern RcFeE lbl_806AADFC;
extern RcFeS lbl_806AB5B8;
extern int lbl_806EF464;
extern "C" void fn_803EFBA4(void*);
extern "C" int fn_803F89B0(void*, int, void*);
extern "C" int fn_803F8A2C(void*);
extern "C" char* strcpy(char*, const char*);
extern "C" void* memset(void*, int, unsigned);
extern "C" char fn_803F2404(const char* wild, const char* str);

extern "C" RcFeE* fn_803F2240(int, const char*, int);

struct RcEvM : RcEv {
    int m40;
    int m44;
};
struct RcSysC {
    int m0, m4;
    int w[33];
    const void* vp;
};
extern RcEvM lbl_806AB364;
extern char lbl_806AB378[];
extern const void* lbl_806AB554[3];

extern "C" void fn_803F2000()
{
    switch (lbl_806AB364.m8) {
    case 0:
        lbl_806AB364.mC = lbl_806AB364.m8;
        lbl_806AB364.m8 = 0xC;
    case 0xC: {
        RcFeE* r = fn_803F2240((int)lbl_806AB378, lbl_806AB378 + 0xC, 1);
        if (r->m4 == 0xB) {
            lbl_806AB364.m8 = 0x7B;
            lbl_806AB364.mC = 0;
        } else {
            lbl_806AB364.m44++;
            if (lbl_806AB364.m1C != 0) {
                RcSysC* y = (RcSysC*)&lbl_806AB4C8;
                const void* volatile sv = y->vp;
                *y = *(RcSysC*)r;
                lbl_806AB554[0] = sv;
            }
            lbl_806AB364.m8 = 0xD;
            lbl_806AB364.mC = 0;
        }
        break;
    }
    case 0xD: {
        RcFeE* r = fn_803F2240((int)&lbl_806AB364.m14, (const char*)&lbl_806AB364 + 0x20, 0);
        if (r->m4 == 0xB) {
            lbl_806AB364.m8 = 0x7B;
            lbl_806AB364.mC = 0;
            break;
        }
        lbl_806AB364.m44++;
        if (lbl_806AB364.m1C != 0) {
            RcSysC* y = (RcSysC*)&lbl_806AB4C8;
            const void* volatile sv = y->vp;
            *y = *(RcSysC*)r;
            lbl_806AB554[0] = sv;
        }
        break;
    }
    case 0x7B: {
        lbl_806AB364.m0->v1(&lbl_806AB364);
        if (lbl_806AB364.m1C != 0) {
            RcSys* y = &lbl_806AB4C8;
            y->m6C = 0;
            y->m70 = 0;
            y->m74 = 0;
            y->m78 = 0;
            y->m7C = 0;
            y->m80 = 0;
            y->m84 = 0;
            y->m88 = 0;
            y->m0 = 0xc;
            y->m4 = 0;
        }
        break;
    }
    }
}

extern "C" RcFeE* fn_803F2240(int a0, const char* pat, int a2)
{
    RcFeInit(&lbl_806AADFC, 0, 0);
    memset(lbl_806AADFC.m90, 0, 0x24);
    lbl_806AADFC.m0 = 0x19;
    lbl_806AADFC.m4 = 0xb;
    lbl_806AADFC.m70 = 0;
    lbl_806AADFC.m74 = 0;
    lbl_806AADFC.m78 = 0;
    lbl_806AADFC.m7C = 0;
    lbl_806AADFC.m80 = 0;
    lbl_806AADFC.m84 = 0;
    lbl_806AADFC.m88 = 0;
    lbl_806AADFC.m6C = 0;
    if (lbl_806EF464 == 0) {
        lbl_806AB5B8.s0 = 0;
        lbl_806AB5B8.s2 = 0;
        fn_803EFBA4(&lbl_806AB5B8);
        lbl_806EF464 = 1;
    }
    int r;
    if (a2 != 0) {
        lbl_806AB5B8.m4 = 0;
        lbl_806AB5B8.m8 = 0;
        lbl_806AB5B8.mC = 0;
        lbl_806AB5B8.m10 = 0;
        memset(lbl_806AB5B8.m14, 0, 4);
        memset(lbl_806AB5B8.m18, 0, 2);
        r = fn_803F89B0(lbl_806EEA2C, a0, &lbl_806AB5B8);
    } else
        r = fn_803F8A2C(lbl_806EEA2C);
    int found = 0;
    while (r == 0 && found == 0) {
            int t = fn_803F2404(pat, lbl_806AB5B8.m4);
            if (t == 0) {
                found = 1;
                lbl_806AADFC.m4 = t;
                lbl_806AADFC.m44 = lbl_806AB5B8.m8;
                lbl_806AADFC.m48 = lbl_806AB5B8.mC;
                lbl_806AADFC.m4C = *(unsigned short*)lbl_806AB5B8.m18;
                *(int*)((char*)&lbl_806AADFC + 0x4e) = *(int*)lbl_806AB5B8.m14;
                lbl_806AADFC.m40 = (int)lbl_806AB5B8.m4;
                strcpy(lbl_806AADFC.m90, lbl_806AB5B8.m4);
            } else
                r = fn_803F8A2C(lbl_806EEA2C);
    }
    return &lbl_806AADFC;
}

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
        int v34 = lbl_806AAF2C.m4;
        int v14 = lbl_806AAF2C.m14.i;
        e->m14.i = v14;
        e->m34 = v34;
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

/* near-miss: 2 slots; same m14 / m34 store order issue as fn_803F28A4 */
extern "C" void fn_803F2A70()
{
    switch (lbl_806AAF58.m8) {
    case 0:
        lbl_806AAF58.m8 = 0x65;
        lbl_806AAF58.m24 = 0;
        lbl_806AAF58.mC = 0;
    case 0x65: {
        RcEv* e = &lbl_806AB3AC;
        lbl_806AAF58.mC = 0;
        e->m1C = 0;
        lbl_806AAF58.m8 = 0x69;
        e->m14.s = 0;
        e->m18 = -1;
        e->m34 = lbl_806AAF58.m4;
        e->m14.i = lbl_806AAF58.m14.i;
        e->m30 = 0xf;
        e->m8 = 0;
        e->m2C = 0;
        e->m38 = 0;
        e->m3C = 0;
        e->m0->v0(e);
        break;
    }
    case 0x69:
        if (lbl_806AB3C4[0] != 0 && lbl_806AB3C4[0] != 3) {
            lbl_806AAF58.m18 = lbl_806AB3C4[0];
            lbl_806AAF58.m8 = 0x7c;
            lbl_806AAF58.m24 = 0;
            lbl_806AAF58.mC = 0;
            break;
        }
        lbl_806AAF58.m24 = 1;
        lbl_806AAF58.m18 = lbl_806AB3C4[0];
        lbl_806AAF58.m8 = 0x17;
        lbl_806AAF58.mC = 0;
    case 0x17: {
        int r = fn_803F8730(lbl_806EEA2C, lbl_806AAF6C, &lbl_806AAF6C[7], &lbl_806AAF6C[8]);
        if (r == 0)
            lbl_806AAF70[0] = r;
        lbl_806AAF58.m8 = 0x7c;
        lbl_806AAF58.mC = 0;
    }
    case 0x7c: {
        RcEvT* s = &lbl_806AAF58;
        if (s->m24 != 0) {
            fn_803F78CC(lbl_806EEA2C, &s->m14);
            s->m24 = 0;
        }
        RcSys* y = &lbl_806AB4C8;
        y->m0 = 3;
        y->m6C = 0;
        y->m70 = 0;
        y->m74 = 0;
        y->m78 = 0;
        y->m7C = 0;
        y->m80 = 0;
        y->m84 = 0;
        y->m88 = 0;
        y->m4 = s->m18;
        *(RcTri*)&y->m34 = s->m2C;
        s->m0->v1((RcEv*)s);
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

struct RcMsk {
    char pad0[8];
    int m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30;
    char pad34[0x6c - 0x34];
    int m6C, m70, m74, m78, m7C, m80, m84, m88;
};
extern "C" int fn_803F6AE0(int, ...);
extern "C" void* memset(void*, int, unsigned);

extern "C" void fn_803F6460(RcMsk* o, int mask, int flag, int arg3)
{
    int arr[16];
    int n = 0;
    memset(arr, 0, 0x40);
    if (mask & 1)
        arr[n++] = 3;
    if (mask & 2)
        arr[n++] = 7;
    if (mask & 4)
        arr[n++] = 4;
    if (mask & 8)
        arr[n++] = 9;
    if ((mask & 0x10) && flag == 1)
        arr[n++] = 6;
    if (mask & 0x20)
        arr[n++] = 8;
    if (mask & 0x40)
        arr[n++] = 7;
    if (mask & 0x100)
        arr[n++] = 0xb;
    if (mask & 0x80)
        arr[n++] = 0xa;
    if (mask & 0x200)
        arr[n++] = 0xc;
    o->m10 = n;
    o->m14 = arr[0];
    o->m18 = arr[1];
    o->m1C = arr[2];
    o->m20 = arr[3];
    switch (o->m6C) {
    case 0:
        o->mC = fn_803F6AE0(o->m8, 0);
        break;
    case 1:
        o->mC = fn_803F6AE0(o->m8, arg3, o->m70);
        break;
    case 2:
        o->mC = fn_803F6AE0(o->m8, arg3, o->m70, o->m74);
        break;
    case 3:
        o->mC = fn_803F6AE0(o->m8, arg3, o->m70, o->m74, o->m78);
        break;
    case 4:
        o->mC = fn_803F6AE0(o->m8, arg3, o->m70, o->m74, o->m78, o->m7C);
        break;
    case 7:
        o->mC = fn_803F6AE0(o->m8, arg3, o->m70, o->m74, o->m78, o->m7C, o->m80, o->m84, o->m88);
        break;
    }
    int cnt = o->m10;
    if (cnt > 0)
        o->m24 = fn_803F6AE0(o->m14, 0);
    if (cnt > 1)
        o->m28 = fn_803F6AE0(o->m18, 0);
    if (cnt > 2)
        o->m2C = fn_803F6AE0(o->m1C, 0);
    if (cnt > 3)
        o->m30 = fn_803F6AE0(o->m20, 0);
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

inline RcReq* RcLink(const RcReq& x, const RcReq& y)
{
    ((RcReq&)y).next = (RcReq*)&x;
    return (RcReq*)&y;
}

extern "C" void* fn_803F6F50(int a, int b, int c, int d, int e)
{
    return lbl_806EEA74->v0(b, RcLink(RcReq(1, a), RcReq(2, c)));
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
