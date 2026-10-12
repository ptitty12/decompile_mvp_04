/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x8038EC58-0x8038F73C (code-only unit, 24 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "../../include/ealib/tu_8038BC58.h"

class VdGBase {
public:
    virtual ~VdGBase() {}
};

class VdG : public VdGBase {
public:
    int m4;
    int m8;
    int mC;
    int m10;
    VdG()
    {
        m4 = 1;
        m8 = 0;
        mC = 0;
        m10 = 0;
    }
    virtual ~VdG() {}
};

extern VdG lbl_80699BA4;

struct VdFcc {
    int m0;
    unsigned char* m4;
};

/* Pool/owner object: m8 high-water mark, mC bytes in use, m10 live allocations (fn_8038F56C/fn_8038F5F4). */
struct VdPool {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

/* Source object: m18 float, m20 counter, m34 callback holder. */
struct VdSrc {
    char pad0[0x18];
    float m18;
    int m1C;
    int m20;
    char pad24[0x34 - 0x24];
    VdCbObj* m34;
};

struct VdRes2 {
    int m0;
    void* m4;
    int m8;
    int mC;
};

class VdRefBase {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual ~VdRefBase();
};

class VdRef : public VdRefBase {
public:
    int m4;
};

extern "C" int fn_8038EA9C(VdCbObj* s);
extern "C" void fn_8038EAF4(VdCbObj* s, int b);
extern "C" void fn_803EC054(void* p);

/* Frame pool of the VP6 codec: two intrusive lists (used at +0x24, free at +0x2C); a frame carries its
 * list node at +8 and a reference count at +0x10. */
struct VdNode {
    VdNode* next;
    VdNode* prev;
    inline void Reset()
    {
        next = this;
        prev = this;
    }
    inline void Init()
    {
        next = (VdNode*)3;
        prev = (VdNode*)3;
        Reset();
        Reset();
    }
    inline void Poison()
    {
        next = (VdNode*)7;
        prev = (VdNode*)7;
    }
};

struct VdFrame {
    int m0;
    int m4;
    VdNode link;
    int m10;
};

struct VdFramePool {
    char pad0[0x24];
    VdNode used;
    VdNode free;
};

inline VdFrame* VdToFrame(VdNode* n)
{
    return n ? (VdFrame*)((char*)n - 8) : 0;
}

inline VdNode* VdToNode(VdFrame* f)
{
    return f ? &f->link : 0;
}

extern "C" unsigned fn_8038EC58(VdFcc* x)
{
    if (x != 0) {
        unsigned char* p = x->m4;
        return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
    }
    return 0x4D56304B;
}

/* Packed pair of 16-bit fields that is also passed whole as an int. */
union VdPack {
    int w;
    struct {
        unsigned short hi;
        unsigned short lo;
    } h;
};

struct VdFrameHdr {
    int m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    unsigned mC;
    int m10;
};

struct VdSub {
    void* m0;
};

struct VdCodec {
    const void* m0;
    VdSub m4;
    VdPack m8;
    VdPack mC;
    int m10;
    int m14;
    float m18;
    int m1C;
    int m20;
    VdNode used;
    VdNode free;
};

struct VdPacket {
    int m0;
    char* m4;
    int m8;
};

extern "C" int fn_80397990(void* a, char* b, int c, int d, int e);
extern "C" void fn_80397438(void* a, void* out);

extern "C" VdFrame* fn_8038F370(VdFramePool* pool);

extern "C" void fn_80397A4C(void* a);
extern "C" void fn_80395E14();
extern char lbl_806061B0[];
extern char lbl_806061F0[];


extern "C" void fn_80395D94();
extern "C" void fn_803959D8(VdG* g);
extern int lbl_806EF380;
extern int lbl_806EF384;

struct VdBlk {
    unsigned char m0;
    char pad1[3];
    unsigned short m4;
    unsigned short m6;
};

struct VdVid {
    int m0;
    VdBlk* m4;
    int m8;
    int mC;
    int m10;
};


extern "C" void* fn_803EBBA4(int a, int b, int c, int d, int e, int f, int g, int h);

extern "C" VdVid* fn_8038EC9C(VdVid* v, int a, int b)
{
    v->m10 = 0;
    v->m8 = 3;
    v->mC = 3;
    v->m0 = 3;
    VdBlk* p = (VdBlk*)fn_803EBBA4(4, 1, 0x20, 0, 0, lbl_80699B94.m8, 0, 0);
    v->m4 = p;
    p->m0 = 0x1C;
    v->m4->m4 = a;
    v->m4->m6 = b;
    return v;
}

extern "C" void fn_8038ED2C(VdRes2* o, int chrg)
{
    if (o->m4 != 0) {
        fn_803EC054(o->m4);
        o->m4 = 0;
    }
    o->m8 = 7;
    o->mC = 7;
    if (chrg & 1)
        lbl_80699B94.m4(o);
}

extern "C" VdCodec* fn_8038ED98(VdCodec* c)
{
    c->m0 = lbl_806061B0;
    c->used.Init();
    c->free.Init();
    c->m1C = 1;
    c->m18 = 0.0f;
    c->m8.w = 0;
    c->mC.w = 0;
    c->m10 = 0;
    c->m14 = 0;
    c->m4.m0 = 0;
    lbl_806EF380 = 0;
    lbl_806EF384 = -1;
    fn_803959D8(&lbl_80699BA4);
    fn_80395D94();
    return c;
}

extern "C" void fn_8038EE54(VdCodec* c, int chrg)
{
    c->m0 = lbl_806061B0;
    while (c->used.next != &c->used) {
        VdNode* n = c->used.next;
        VdNode* nx = n->next;
        VdNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (VdNode*)0xB;
        n->prev = (VdNode*)0xB;
        VdFrame* f = VdToFrame(n);
        if (f != 0)
            fn_8038ED2C((VdRes2*)f, 3);
    }
    while (c->free.next != &c->free) {
        VdNode* n = c->free.next;
        VdNode* nx = n->next;
        VdNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (VdNode*)0xB;
        n->prev = (VdNode*)0xB;
        VdFrame* f = VdToFrame(n);
        if (f != 0)
            fn_8038ED2C((VdRes2*)f, 3);
    }
    fn_80397A4C(&c->m4);
    fn_80395E14();
    c->free.Poison();
    c->used.Poison();
    c->m0 = lbl_806061F0;
    if (chrg & 1)
        lbl_80699B94.m4(c);
}

extern "C" int fn_8038EF9C(VdSrc* s, int v)
{
    s->m20 = 0;
    *(int*)((char*)s + 0x34) = v;
    return 2;
}

extern "C" int fn_8038EFB4(VdSrc* s)
{
    return s->m20;
}

extern "C" float fn_8038EFBC(VdSrc* s)
{
    return s->m18;
}

extern "C" int fn_804002BC(const char* fmt, ...);

extern "C" void fn_8038F278(VdFramePool* pool, VdFrame* f)
{
    if (--f->m10 > 0)
        return;
    VdNode* n = &f->link;
    VdNode* nx = n->next;
    VdNode* pv = n->prev;
    pv->next = nx;
    nx->prev = pv;
    n->next = (VdNode*)0xB;
    n->prev = (VdNode*)0xB;
    VdNode* in = VdToNode(f);
    VdNode* head = &pool->free;
    VdNode* tail = head->prev;
    tail->next = in;
    head->prev = in;
    in->prev = tail;
    in->next = head;
}

extern "C" VdFrame* fn_8038F2D8(VdCodec* c, VdPacket* pk)
{
    int info[10];
    VdFrame* f = fn_8038F370((VdFramePool*)c);
    VdFrameHdr* h = (VdFrameHdr*)f->m4;
    if (fn_80397990(c->m4.m0, pk->m4 + 8, pk->m8 - 8, c->m8.w, c->mC.w) == 0) {
        fn_80397438(c->m4.m0, info);
        h->m10 = info[9] - (int)h;
        h->mC = h->mC | 0x10000000;
        h->m4 = c->m8.h.lo;
        h->m6 = c->mC.h.lo;
    }
    return f;
}

extern "C" VdFrame* fn_8038F370(VdFramePool* pool)
{
    VdNode* n = pool->free.next;
    if (n != &pool->free) {
        VdNode* nx = n->next;
        VdNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (VdNode*)0xB;
        n->prev = (VdNode*)0xB;
        VdFrame* f = VdToFrame(n);
        VdNode* in = VdToNode(f);
        VdNode* head = &pool->used;
        VdNode* tail = head->prev;
        tail->next = in;
        head->prev = in;
        in->prev = tail;
        in->next = head;
        f->m10 = 1;
        return f;
    }
    fn_804002BC("VP6_CODEC_INTERNAL::GetFrameFromList() out of frames did you call CODEC::ReleaseFrame( FRAME *Frame )\n");
    return 0;
}

extern "C" void fn_8038F414(VdSrc* s, int* out)
{
    *out = fn_8038EA9C(s->m34);
    s->m20++;
}

extern "C" void fn_8038F458(VdSrc* s, int a)
{
    if (a != 0)
        fn_8038EAF4(s->m34, a);
}

extern "C" void* fn_8038F484()
{
    void* p = lbl_80699B94.m0("", 0x38, 0, 0, lbl_80699B94.m8);
    return fn_8038ED98((VdCodec*)p);
}

struct DtorAt0 { const void* m; };

extern char lbl_806061F0[];

extern "C" void fn_8038F52C(DtorAt0* self, int chrg)
{
    self->m = lbl_806061F0;
    if (chrg & 1)
        lbl_80699B94.m4(self);
}

extern "C" int* fn_8038F56C(VdPool* s, int n)
{
    s->mC += n;
    if (s->mC > s->m8)
        s->m8 = s->mC;
    s->m10++;
    int* p = (int*)lbl_80699B94.m0("MyAllocator::Alloc", n + 4, 0, 4, lbl_80699B94.m8);
    *p = n;
    return p + 1;
}

extern "C" void fn_8038F5F4(VdPool* s, int* user)
{
    int* b = user - 1;
    s->mC -= *b;
    lbl_80699B94.m4(b);
}

extern "C" int fn_8038F638(int* self) { return ++self[1]; }

extern "C" int fn_8038F64C(VdRef* self)
{
    if (--self->m4 == 0 && self != 0)
        delete self;
    return self->m4;
}

extern char lbl_80649C48[];

extern "C" void fn_80377408(void* p);

extern "C" void fn_8038F6B0(DtorAt0* self, int chrg)
{
    self->m = lbl_80649C48;
    if (chrg & 1)
        fn_80377408(self);
}

/* Static object at 0x80699BA4; its compiler-made init/destroy functions are 0x8038F4D0, 0x8038F6E4 and 0x8038F710. */
VdG lbl_80699BA4;
