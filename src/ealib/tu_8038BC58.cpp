/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x8038BC58-0x8038EC58 (code-only unit, 58 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* EA video/stream buffer code: shared types (evidence: offsets read by the functions below). */
struct VdFilter {
    char pad0[0x70];
    float m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
    float m8C;
    float m90;
};

struct VdCb {
    int m0;
    int m4;
    int m8;
    void (*mC)(VdCb*, int, int);
};

class VdA {
public:
    int m0;
    int m4;
    int m8;
    VdA();
};

class VdB {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    VdB();
    VdB(int a, int b, int c, int d);
};

class VdC {
public:
    void* (*m0)(const char*, int, int, int, int);
    void (*m4)(void*);
    int m8;
    VdC();
    virtual ~VdC() {}
};
extern VdC lbl_80699B94;

/* Interface owned by a VdCbObj at +0x14 (vtable slots read by fn_8038E8A4..fn_8038E9D8). */
struct VdObj5 {
    virtual ~VdObj5();
    virtual void v2(void*);
    virtual int v3(int);
    virtual int v4();
    virtual float v5();
    virtual int v6();
};

/* Callback holder, flat view: m0 state, m4 cookie, m8 callback, m14 owned VdObj5 (vptr at +0x18). */
struct VdCbObj {
    int m0;
    int m4;
    void (*m8)(VdCbObj*, int, int*);
    int mC;
    int m10;
    VdObj5* m14;
};

extern "C" void fn_8038E8EC(VdCbObj* s);
extern "C" int fn_8038EA64(VdCbObj* h, int a);
extern "C" int fn_8038E9D8(VdCbObj* s, int a);
extern "C" int fn_8038E944(VdCbObj* s);
extern "C" float fn_8038E98C(VdCbObj* s);

/* Same object with its VdB sub-object at +4 (fn_8038E7D8 ctor, fn_8038E84C dtor). */
class VdD {
public:
    int m0;
    VdB m4;
    VdObj5* m14;
    virtual ~VdD();
    VdD(const VdB* s);
    void operator delete(void* p) { lbl_80699B94.m4(p); }
};

extern "C" void fn_8038D110(char* o);

struct VdRes;

struct VdClock {
    unsigned long long m0;
    unsigned long long m8;
    unsigned m10;
};

/* 64-bit clock (fn_80438628 returns the current time): m0 last time, m8 accumulated, m10 rate (0x1000 = 1.0).
 * Stream state: m0 resource (VdRes), m60 clock. */
struct VdStream {
    VdRes* m0;
    char pad4[0x60 - 4];
    VdClock* m60;
};

typedef VdStream I;

extern "C" int fn_8038E694(VdRes* o, int a);
extern "C" unsigned long long fn_80438628();


struct VdRes {
    int m0;
    void* m4;
    int m8;
    int mC;
    int m10;
};

struct VdBufs {
    char pad0[0x600];
    void* m600;
    void* m604;
};

/* Stream object: m0 owner holder, vptr at +4 (base vtable lbl_80605EC8, derived lbl_80605E88). */
class VdBase {
public:
    VdCbObj* m0;
    virtual ~VdBase() {}
};

class VdMain : public VdBase {
public:
    VdBufs* m8;
    char padC[0x40 - 0xC];
    unsigned m40;
    unsigned m44;
    float m48;
    char pad4C[0x68 - 0x4C];
    VdCbObj* m68;
    int m6C;
    char pad70[0x78 - 0x70];
    int m78;
    virtual ~VdMain();
    void operator delete(void* p) { lbl_80699B94.m4(p); }
};

struct VdTile {
    unsigned m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
    unsigned m10;
    unsigned m14;
    unsigned m18;
};

struct DtorAt0 { const void* m; };

extern "C" void fn_8038C058(DtorAt0*, int);

extern "C" VdMain* fn_8038BCD0(VdMain* p, int a, int b, int c);
extern "C" void fn_803D9E00(void* a, int* b, int* c);

extern "C" VdMain* fn_8038BC58(int a, int b, int unused, char* c)
{
    int sp8;
    int spC;
    fn_803D9E00(c + 0x10, &sp8, &spC);
    VdMain* p = (VdMain*)lbl_80699B94.m0("", 0x98, 0, 0, lbl_80699B94.m8);
    return fn_8038BCD0(p, a, b, spC);
}

extern "C" void fn_8038BF80(VdFilter* o, float a, float b, float c)
{
    o->m84 = o->m70 * o->m8C + a;
    o->m88 = o->m74 * o->m90 + b;
    o->m7C = a;
    o->m80 = b;
    o->m78 = c;
}

extern "C" void fn_8038BFB0(VdFilter* o, float a, float b)
{
    o->m84 = o->m70 * a + o->m7C;
    o->m8C = a;
    o->m90 = b;
    o->m88 = o->m74 * b + o->m80;
}

extern "C" void fn_8038C6E0(VdMain* self, int v)
{
    if (self->m6C != 0)
        fn_8038EA64(self->m0, self->m6C);
    self->m6C = v;
    ((void (*)(VdMain*))fn_8038C058)(self);
}

extern "C" void fn_8038C72C(DtorAt0* s, int chrg)
{
    fn_8038C058(s, chrg);
}

extern "C" void fn_8038C74C()
{
}

struct DtorAt4 { char pad[0x4]; const void* m; };

extern char lbl_80605EC8[];

extern "C" void fn_80377408(void* p);

extern "C" void fn_8038C750(DtorAt4* self, int chrg)
{
    self->m = lbl_80605EC8;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" void fn_8038C784()
{
}

extern "C" void fn_8038C788(VdBufs* s)
{
    fn_8038D110((char*)s->m600);
    fn_8038D110((char*)s->m604);
    lbl_80699B94.m4(s);
}

/* 8038BFDC */
VdMain::~VdMain()
{
    fn_8038C788(m8);
    if (m6C != 0)
        fn_8038EA64(m0, m6C);
}

extern "C" void fn_8038D02C(VdTile* t, unsigned a, unsigned b, unsigned c, unsigned d)
{
    t->m0 = a;
    t->m4 = b;
    t->m8 = c;
    unsigned cm = c - 1;
    t->mC = d;
    unsigned dm = d - 1;
    t->m10 = (cm + a) / a;
    t->m14 = (dm + b) / b;
    t->m18 = a * b;
}

extern "C" int fn_8038D0E0(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 3) >> 2)) + (x >> 2)) << 5) + (((y & 3) << 3) + ((x & 3) << 1));
}

extern "C" void fn_8038D110(char* o)
{
    lbl_80699B94.m4(*(void**)(o + 0x10));
    lbl_80699B94.m4(*(void**)(o + 0x3C));
    lbl_80699B94.m4(o);
}

extern "C" int fn_8038DDE8(VdMain* s, float f)
{
    s->m48 = f;
    s->m78 = fn_8038E9D8(s->m68, (unsigned)f);
    s->m44 = fn_8038E944(s->m68);
    return s->m78;
}

extern "C" unsigned fn_8038E080(VdMain* s);

extern "C" int fn_8038DE6C(VdMain* s)
{
    unsigned t = fn_8038E080(s);
    float f = fn_8038E98C(s->m68);
    t += s->m40;
    float r = (float)t * 0.001f * f;
    s->m48 = r;
    return r > (float)s->m44;
}

extern "C" int fn_8038E748(VdRes* o);

extern "C" int fn_8038DF08(int* s)
{
    VdRes* p = *(VdRes**)s;
    return p ? fn_8038E748(p) : 1;
}

extern "C" int fn_8038DF3C(I* s, unsigned rate)
{
    if (rate > 0x4000)
        rate = 0x4000;
    if (s->m0 != 0)
        fn_8038E694(s->m0, rate);
    VdClock* c = s->m60;
    unsigned long long t = fn_80438628();
    if (c->m10 == 0x1000)
        c->m8 += t - c->m0;
    else
        c->m8 += ((unsigned long long)c->m10 * (t - c->m0)) >> 12;
    c->m0 = t;
    c->m10 = rate;
    return 0;
}



extern "C" void fn_8038E038(I* i)
{
    fn_8038DF3C(i, 0);
}

extern "C" void fn_8038E05C(I* p)
{
    fn_8038DF3C(p, 0x1000);
}

extern "C" int fn_8038E1A8(int a, int b);

extern "C" int fn_8038E3EC(int a, int* b)
{
    return fn_8038E1A8(*b, a);
}

extern "C" int fn_803FE7E0(int a, int b);

extern "C" int fn_8038E418(char* a, int* b)
{
    return fn_803FE7E0(*(int*)(a + 0x30), *b);
}

extern "C" int fn_8038E440(int a, int* b, int c)
{
    return fn_8038E418((char*)*b, (int*)c);
}

extern "C" int fn_8038E468(VdClock* c)
{
    unsigned long long t = fn_80438628();
    if (c->m10 == 0x1000)
        c->m8 += t - c->m0;
    else
        c->m8 += ((unsigned long long)c->m10 * (t - c->m0)) >> 12;
    c->m0 = t;
}

extern "C" void fn_803AA95C(int a);
extern "C" int fn_803A975C();
extern "C" int fn_803A979C();
extern "C" int fn_803AB56C(int a, int b);
extern "C" int fn_803AB3D8(int a, int b);

extern "C" void fn_8038E61C(VdRes* o, int chrg)
{
    if (o->m4 != 0) {
        fn_803AA95C(o->mC);
        lbl_80699B94.m4(o->m4);
        o->m4 = 0;
    }
    if (chrg & 1)
        lbl_80699B94.m4(o);
}

extern "C" int fn_8038E694(VdRes* o, int a)
{
    if (o->mC != -1) {
        fn_803A975C();
        int r = fn_803AB56C(o->mC, a);
        fn_803A979C();
        return r;
    }
    return 0;
}

extern "C" int fn_8038E6F0(VdRes* o)
{
    if (o->m10 != -1) {
        fn_803A975C();
        int r = fn_803AB3D8(o->m10, 0);
        fn_803A979C();
        return r;
    }
    return 0;
}

/* Static object: allocator hooks. m0 = allocate(tag, size, 0, 0, m8), m4 = free(ptr), filled in at run time;
 * the compiler-made static initializer is 0x8038EB78 (with 0x8038EBCC, 0x8038EC00 and 0x8038EC2C after it). */
VdC lbl_80699B94;

extern "C" int fn_803AB8A4(int h, void* out);
extern "C" int fn_803AB644(int h, void* out);

struct VdQ16 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" int fn_8038E748(VdRes* o)
{
    VdQ16 a;
    VdQ16 b;
    fn_803A975C();
    if (fn_803AB8A4(o->mC, &b) >= 0 && fn_803AB644(b.m4, &a) >= 0) {
        fn_803A979C();
        return a.m8 == 0;
    }
    fn_803A979C();
    return 0;
}

/* 8038E7B8 */
VdC::VdC()
{
    m0 = 0;
    m4 = 0;
}

/* 8038E7D8 */
VdD::VdD(const VdB* s)
{
    m4 = *s;
    m14 = 0;
    m0 = 0;
}

extern "C" int fn_8038E8A4(VdCbObj* s, VdObj5* obj, int v)
{
    s->m0 = v;
    s->m14 = obj;
    obj->v2(s);
}

extern "C" void fn_8038E8EC(VdCbObj* s)
{
    VdObj5* p = s->m14;
    if (p != 0) {
        delete p;
        s->m14 = 0;
    }
}

/* 8038E84C */
VdD::~VdD()
{
    fn_8038E8EC((VdCbObj*)this);
}

extern "C" int fn_8038E944(VdCbObj* s)
{
    VdObj5* p = s->m14;
    if (p == 0)
        return 0;
    return p->v4();
}

extern "C" float fn_8038E98C(VdCbObj* s)
{
    VdObj5* p = s->m14;
    if (p == 0)
        return 0.0f;
    return p->v5();
}

extern "C" int fn_8038E9D8(VdCbObj* s, int a)
{
    if (s->m14 == 0 && s->m0 == 0)
        s->m8(s, s->m4, (int*)s);
    if (s->m14 == 0)
        return 0;
    return s->m14->v3(a);
}

extern "C" int fn_8038EA64(VdCbObj* h, int)
{
    return h->m14->v6();
}

extern "C" int fn_8038EA9C(VdCbObj* s)
{
    int v = s->m0;
    if (v != 0) {
        s->m0 = 0;
        return v;
    }
    s->m8(s, s->m4, &v);
    return v;
}

extern "C" void fn_8038EAF4(VdCb* s, int b)
{
    s->mC(s, s->m4, b);
}

/* 8038EB28 */
VdA::VdA()
{
    m4 = 0;
    m8 = 0;
    m0 = 0;
}

/* 8038EB40 */
VdB::VdB()
{
    mC = 2;
    m0 = 0;
    m4 = 0;
    m8 = 0;
}

/* 8038EB60 */
VdB::VdB(int a, int b, int c, int d)
{
    mC = d;
    m0 = a;
    m4 = b;
    m8 = c;
}

struct DtorAtC { char pad[0xc]; const void* m; };

extern char lbl_80606108[];

/* 8038EBCC: deleting dtor of VdC (the class's own copy is linkonce and unpairable). */
extern "C" void fn_8038EBCC(DtorAtC* self, int chrg)
{
    self->m = lbl_80606108;
    if (chrg & 1)
        fn_80377408(self);
}
