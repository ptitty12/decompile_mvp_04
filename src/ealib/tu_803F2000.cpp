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
    virtual void v0();
    virtual void v1(int, int);
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

extern "C" unsigned short* fn_803F644C(void* l, int k)
{
    if (k == 1)
        return lbl_806EEA5C;
    return lbl_806EEA58;
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
