/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803F00FC-0x803F2000 (code-only unit, 34 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct RcLockIf {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

struct RcSysX {
    char pad[0x18];
    RcLockIf* m18;
};

struct RcEv;

struct RcTgt0 {
    char d[0x4c];
};

struct RcTgt : RcTgt0 {
    virtual void v0(RcEv*);
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
};

extern RcEv lbl_806AB158;
extern RcEv lbl_806AB17C;
extern RcEv lbl_806AB19C;
extern RcEv lbl_806AB1BC;
extern RcEv lbl_806AB1DC;
extern RcEv lbl_806AB204;
extern RcEv lbl_806AB228;
extern RcEv lbl_806AB258;
extern RcEv lbl_806AB288;
extern RcEv lbl_806AB2B4;

extern "C" void fn_803F09FC(RcSysX* s, int* a)
{
    s->m18->v3();
    int v = a[0];
    RcEv* e = &lbl_806AB158;
    e->m14.s = 0;
    e->m1C = 1;
    e->m18 = -1;
    e->m14.i = v;
    e->m8 = 0;
    e->m20 = 0;
    e->m0->v0(e);
    s->m18->v4();
}

extern "C" void fn_803F0AB4(RcSysX* s, int* a)
{
    s->m18->v3();
    int v = a[0];
    RcEv* e = &lbl_806AB17C;
    e->m14.s = 0;
    e->m8 = 0;
    e->m18 = -1;
    e->m1C = 1;
    e->m14.i = v;
    e->m0->v0(e);
    s->m18->v4();
}

extern "C" void fn_803F0B68(RcSysX* s, int* a)
{
    s->m18->v3();
    int v = a[0];
    RcEv* e = &lbl_806AB19C;
    e->m14.s = 0;
    e->m8 = 0;
    e->m18 = -1;
    e->m1C = 1;
    e->m14.i = v;
    e->m0->v0(e);
    s->m18->v4();
}

extern "C" void fn_803F0C1C(RcSysX* s, int* a)
{
    s->m18->v3();
    int v = a[0];
    RcEv* e = &lbl_806AB1BC;
    e->m14.s = 0;
    e->m8 = 0;
    e->m18 = -1;
    e->m1C = 1;
    e->m14.i = v;
    e->m0->v0(e);
    s->m18->v4();
}

extern "C" void fn_803F0CD0(RcSysX* s, int* a, int x, int y)
{
    s->m18->v3();
    int v = a[0];
    RcEv* e = &lbl_806AB1DC;
    e->m14.s = 0;
    e->m8 = 0;
    e->m18 = -1;
    e->m1C = 1;
    e->m14.i = v;
    e->m20 = x;
    e->m24 = y;
    e->m0->v0(e);
    s->m18->v4();
}

/* near-miss: 9 slots; retail stores m14 (short) last with its own zero register, every store order tried */
extern "C" void fn_803F0D94(RcSysX* s, int v)
{
    s->m18->v3();
    RcEv* e = &lbl_806AB204;
    e->m14.s = 0;
    e->m1C = 1;
    e->m18 = -1;
    e->m8 = 0;
    e->m20 = v;
    e->m0->v0(e);
    s->m18->v4();
}

extern "C" void fn_803F0E44(RcSysX* s, int p1, int p2, int p3)
{
    s->m18->v3();
    RcEv* e = &lbl_806AB228;
    e->m1C = 1;
    e->m14.s = 0;
    e->m18 = -1;
    e->m8 = 0;
    e->m20 = p1;
    e->m24 = p2;
    e->m28 = p3;
    e->m2C = 0;
    e->m0->v0(e);
    s->m18->v4();
}

extern "C" void fn_803F0F08(RcSysX* s, int p1, int p2, int p3)
{
    s->m18->v3();
    RcEv* e = &lbl_806AB258;
    e->m1C = 1;
    e->m14.s = 0;
    e->m18 = -1;
    e->m8 = 0;
    e->m20 = p1;
    e->m24 = p2;
    e->m28 = p3;
    e->m2C = 0;
    e->m0->v0(e);
    s->m18->v4();
}

/* near-miss: 5 slots; store order of m1C/m18/m24/m28 not found by hill-climb */
extern "C" void fn_803F0FCC(RcSysX* s, int p1, int p2, int p3)
{
    s->m18->v3();
    RcEv* e = &lbl_806AB288;
    e->m1C = 1;
    e->m18 = -1;
    e->m24 = p2;
    e->m14.s = 0;
    e->m8 = 0;
    e->m20 = p1;
    e->m28 = p3;
    e->m0->v0(e);
    s->m18->v4();
}

/* near-miss: same as fn_803F0D94 (9 slots) */
extern "C" void fn_803F108C(RcSysX* s, int v)
{
    s->m18->v3();
    RcEv* e = &lbl_806AB2B4;
    e->m14.s = 0;
    e->m1C = 1;
    e->m18 = -1;
    e->m8 = 0;
    e->m20 = v;
    e->m0->v0(e);
    s->m18->v4();
}
