/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x8038F73C-0x803912F8 (code-only unit, 34 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "../../include/ealib/tu_8038BC58.h"

/* MAD/VP6 codec objects: same frame-pool design as ealib/tu_8038EC58.cpp (intrusive lists, poison 0xB/7/3). */
struct McNode {
    McNode* next;
    McNode* prev;
    inline void Reset()
    {
        next = this;
        prev = this;
    }
    inline void Init()
    {
        next = (McNode*)3;
        prev = (McNode*)3;
        Reset();
        Reset();
    }
    inline void Poison()
    {
        next = (McNode*)7;
        prev = (McNode*)7;
    }
};

struct McFrame {
    int m0;
    int m4;
    McNode link;
    int m10;
};

/* Pool: vptr, m4 data, lists at +0x20 (used) and +0x28 (free). */
struct McPool {
    const void* m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x20 - 0x10];
    McNode used;
    McNode free;
    int m30;
};

struct McRes {
    int m0;
    void* m4;
    int m8;
    int mC;
};

struct McHdr {
    unsigned char m0;
    char pad1[3];
    unsigned short m4;
    unsigned short m6;
};

struct McVid {
    int m0;
    McHdr* m4;
    int m8;
    int mC;
    int m10;
};

struct McFcc {
    int m0;
    unsigned char* m4;
};

struct McSrc {
    char pad0[0x18];
    int m18;
    int m1C;
    char pad20[0x30 - 0x20];
    VdCbObj* m30;
};

inline McFrame* McToFrame(McNode* n)
{
    return n ? (McFrame*)((char*)n - 8) : 0;
}

inline McNode* McToNode(McFrame* f)
{
    return f ? &f->link : 0;
}

extern char lbl_80606398[];
extern char lbl_806061F0[];

extern "C" int fn_804002BC(const char* fmt, ...);
extern "C" void* fn_803FFC58(void* p, int v, int n);
extern "C" int fn_8038EA9C(VdCbObj* s);
extern "C" void fn_8038EAF4(VdCbObj* s, int b);

extern "C" int fn_8038F73C(int x)
{
    return x == 0x4D566864;
}

extern "C" int fn_8038F754(int x)
{
    if (x == 0x4D563046 || x == 0x4D56304B)
        return 1;
    return 0;
}

extern "C" unsigned fn_8038F784(McFcc* x)
{
    if (x != 0) {
        unsigned char* p = x->m4;
        return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
    }
    return 0x4D41446B;
}

/* near-miss: same length; w/h land in swapped callee-saved registers (r28/r29) and the zero/one constants load in a
 * different order; 4 operand/store-order spellings tried. */
extern "C" McVid* fn_8038F7C8(McVid* v, unsigned w, unsigned h)
{
    unsigned sz = w * (h * 3) / 2 + 0x10;
    v->m0 = 1;
    v->mC = 3;
    v->m8 = 3;
    v->m10 = 0;
    v->m4 = (McHdr*)lbl_80699B94.m0("MAD_FRAME::m_Shape", sz, 0, 0x10, lbl_80699B94.m8);
    fn_803FFC58(v->m4, 0, 0x10);
    v->m4->m0 = 0x6C;
    v->m4->m4 = w;
    v->m4->m6 = h;
    return v;
}

extern "C" void fn_8038F884(McRes* o, int chrg)
{
    if (o->m4 != 0) {
        lbl_80699B94.m4(o->m4);
        o->m4 = 0;
    }
    o->m8 = 7;
    o->mC = 7;
    if (chrg & 1)
        lbl_80699B94.m4(o);
}

extern "C" McPool* fn_8038F8FC(McPool* p)
{
    p->m0 = lbl_80606398;
    p->used.Init();
    p->free.Init();
    p->mC = 1;
    return p;
}

extern "C" void fn_8038F954(McPool* p, int chrg)
{
    p->m0 = lbl_80606398;
    while (p->used.next != &p->used) {
        McNode* n = p->used.next;
        McNode* nx = n->next;
        McNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (McNode*)0xB;
        n->prev = (McNode*)0xB;
        McFrame* f = McToFrame(n);
        if (f != 0)
            fn_8038F884((McRes*)f, 3);
    }
    while (p->free.next != &p->free) {
        McNode* n = p->free.next;
        McNode* nx = n->next;
        McNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (McNode*)0xB;
        n->prev = (McNode*)0xB;
        McFrame* f = McToFrame(n);
        if (f != 0)
            fn_8038F884((McRes*)f, 3);
    }
    p->free.Poison();
    p->used.Poison();
    p->m0 = lbl_806061F0;
    if (chrg & 1)
        lbl_80699B94.m4(p);
}

extern "C" int fn_8038FA8C(McSrc* s, int v)
{
    *(int*)((char*)s + 0x30) = v;
    s->m1C = 0;
    s->m18 = 0;
    return 2;
}

extern "C" int fn_8038FAA8(McSrc* s)
{
    return s->m1C;
}

extern "C" float fn_8038FAB0(float* s)
{
    return s[1];
}

extern "C" void fn_8038FAB8(McSrc* s, int* out)
{
    *out = fn_8038EA9C(s->m30);
    s->m1C++;
}

extern "C" void fn_8038FAFC(McSrc* s, int a)
{
    if (a != 0)
        fn_8038EAF4(s->m30, a);
}

struct McVT {
    char pad0[0x30];
    short m30;
    short pad32;
    void (*m34)(void*);
};
struct McSrcV {
    McVT* m0;
    char pad4[8];
    int mC;
    char pad10[8];
    int m18;
    int m1C;
};
extern "C" int fn_8038FB28(McSrc* s, int p);
/* near-miss (95.5%): retail copies &p into r4 before saving it in r28 and keeps p in r30 across the tail; one extra `ble` in the
   short-count loop is not reproduced (the loop is entered through two tests). */
extern "C" int fn_8038FEF4(McSrcV* o, int n)
{
    int p;
    int* pp = &p;
    fn_8038FAB8((McSrc*)o, pp);
    if (o->mC == 0) {
        int d = n - o->m1C;
        if (d > 2) {
            do {
                fn_8038FAFC((McSrc*)o, p);
                fn_8038FAB8((McSrc*)o, pp);
            } while (fn_8038F784((McFcc*)p) != 0x4D41446B);
        } else if (d > 0) {
            int k = d;
            if (k > 0) {
                do {
                    if (fn_8038F784((McFcc*)p) == 0x4D414465) {
                        fn_8038FAFC((McSrc*)o, p);
                        fn_8038FAB8((McSrc*)o, pp);
                    }
                    k--;
                } while (k != 0);
            }
        }
    }
    int q = p;
    if (q != 0) {
        int r = fn_8038FB28((McSrc*)o, q);
        fn_8038FAFC((McSrc*)o, p);
        return r;
    }
    if (o->m18 != 0) {
        o->m0->m34((char*)o + o->m0->m30);
        o->m18 = q;
    }
    return 0;
}

extern "C" McFrame* fn_80390020(McPool* p)
{
    McNode* n = p->free.next;
    if (n != &p->free) {
        McNode* nx = n->next;
        McNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (McNode*)0xB;
        n->prev = (McNode*)0xB;
        McFrame* f = McToFrame(n);
        McNode* in = McToNode(f);
        McNode* head = &p->used;
        McNode* tail = head->prev;
        tail->next = in;
        head->prev = in;
        in->prev = tail;
        in->next = head;
        f->m10 = 2;
        return f;
    }
    fn_804002BC("MAD_CODEC_INTERNAL::CreateIorP() out of frames did you call CODEC::ReleaseFrame( FRAME *Frame )
");
    return 0;
}

extern "C" McFrame* fn_803900C4(McPool* p)
{
    McNode* n = p->free.next;
    if (n != &p->free) {
        McNode* nx = n->next;
        McNode* pv = n->prev;
        pv->next = nx;
        nx->prev = pv;
        n->next = (McNode*)0xB;
        n->prev = (McNode*)0xB;
        McFrame* f = McToFrame(n);
        McNode* in = McToNode(f);
        McNode* head = &p->used;
        McNode* tail = head->prev;
        tail->next = in;
        head->prev = in;
        in->prev = tail;
        in->next = head;
        f->m10 = 1;
        return f;
    }
    fn_804002BC("MAD_CODEC_INTERNAL::CreateB() out of frames did you call CODEC::ReleaseFrame( FRAME *Frame )
");
    return 0;
}

extern "C" void fn_80390168(McPool* pool, McFrame* f)
{
    if (--f->m10 > 0)
        return;
    McNode* n = &f->link;
    McNode* nx = n->next;
    McNode* pv = n->prev;
    pv->next = nx;
    nx->prev = pv;
    n->next = (McNode*)0xB;
    n->prev = (McNode*)0xB;
    McNode* in = McToNode(f);
    McNode* head = &pool->free;
    McNode* tail = head->prev;
    tail->next = in;
    head->prev = in;
    in->prev = tail;
    in->next = head;
}

extern "C" McPool* fn_8038F8FC(McPool* p);

extern "C" McPool* fn_803901C8()
{
    void* p = lbl_80699B94.m0("", 0x34, 0, 0, lbl_80699B94.m8);
    return fn_8038F8FC((McPool*)p);
}

extern const int lbl_8060641C[];

extern "C" int fn_80390214(int x)
{
    for (int i = 0; i < 3; i++) {
        if (lbl_8060641C[i] == x)
            return 1;
    }
    return 0;
}

/* Bit reader state of the MAD decoder: buffer, bit count and byte cursor (small data). */
extern unsigned lbl_806EF38C;
extern int lbl_806EF390;
extern unsigned char* lbl_806EF388;

extern "C" void fn_80390504(int n)
{
    unsigned buf = lbl_806EF38C << n;
    int cnt = lbl_806EF390 - n;
    lbl_806EF38C = buf;
    lbl_806EF390 = cnt;
    if (cnt > 15)
        return;
    unsigned char* p = lbl_806EF388;
    unsigned w = (p[1] << 8) | p[0];
    lbl_806EF390 = cnt + 16;
    lbl_806EF388 = p + 2;
    lbl_806EF38C = buf | (w << (16 - cnt));
}

extern const int lbl_8069ABB8[];

extern "C" int fn_8039055C()
{
    int e = lbl_8069ABB8[lbl_806EF38C >> 26];
    fn_80390504(e & 0xFF);
    return e >> 22;
}

extern int lbl_8069B5B8[];

extern "C" void fn_803905A0(int* dst, int stride)
{
    for (int i = 0; i < 8; i++) {
        dst[0] = lbl_8069B5B8[0];
        dst[1] = lbl_8069B5B8[0];
        dst[2] = lbl_8069B5B8[0];
        dst[3] = lbl_8069B5B8[0];
        dst[4] = lbl_8069B5B8[0];
        dst[5] = lbl_8069B5B8[0];
        dst[6] = lbl_8069B5B8[0];
        dst[7] = lbl_8069B5B8[0];
        dst += stride;
    }
}

extern const unsigned char lbl_8069B3B8[];

inline int McClip(int v)
{
    return lbl_8069B3B8[v & 0x1FF];
}

extern "C" void fn_803905FC(unsigned char* src, int stride, int* dst, int bias)
{
    for (int i = 0; i < 8; i++) {
        dst[0] = (src[0] + bias) << 16;
        dst[1] = (src[1] + bias) << 16;
        dst[2] = (src[2] + bias) << 16;
        dst[3] = (src[3] + bias) << 16;
        dst[4] = (src[4] + bias) << 16;
        dst[5] = (src[5] + bias) << 16;
        dst[6] = (src[6] + bias) << 16;
        dst[7] = (src[7] + bias) << 16;
        src += stride;
        dst += 16;
    }
}

extern "C" void fn_80390694(unsigned char* src, int stride, int* dst, int bias)
{
    for (int i = 0; i < 8; i++) {
        dst[0] = (src[0] + bias) << 16;
        dst[1] = (src[1] + bias) << 16;
        dst[2] = (src[2] + bias) << 16;
        dst[3] = (src[3] + bias) << 16;
        dst[4] = (src[4] + bias) << 16;
        dst[5] = (src[5] + bias) << 16;
        dst[6] = (src[6] + bias) << 16;
        dst[7] = (src[7] + bias) << 16;
        src += stride;
        dst += 8;
    }
}

extern "C" void fn_8039072C(short* src, unsigned char* dst, int stride)
{
    for (int i = 0; i < 16; i++) {
        dst[0] = McClip(src[0]);
        dst[1] = McClip(src[2]);
        dst[2] = McClip(src[4]);
        dst[3] = McClip(src[6]);
        dst[4] = McClip(src[8]);
        dst[5] = McClip(src[10]);
        dst[6] = McClip(src[12]);
        dst[7] = McClip(src[14]);
        dst[8] = McClip(src[16]);
        dst[9] = McClip(src[18]);
        dst[10] = McClip(src[20]);
        dst[11] = McClip(src[22]);
        dst[12] = McClip(src[24]);
        dst[13] = McClip(src[26]);
        dst[14] = McClip(src[28]);
        dst[15] = McClip(src[30]);
        src += 32;
        dst += stride;
    }
}

extern "C" void fn_8039084C(short* src, unsigned char* dst, int stride)
{
    for (int i = 0; i < 8; i++) {
        dst[0] = McClip(src[0]);
        dst[1] = McClip(src[2]);
        dst[2] = McClip(src[4]);
        dst[3] = McClip(src[6]);
        dst[4] = McClip(src[8]);
        dst[5] = McClip(src[10]);
        dst[6] = McClip(src[12]);
        dst[7] = McClip(src[14]);
        src += 16;
        dst += stride;
    }
}

extern int lbl_806EF394;
extern int lbl_806EF398;
extern int lbl_80607218[];
extern int lbl_806242E0[];
extern int lbl_8069ACB8[];
extern "C" int fn_80401BBC(int a, int b);
extern "C" void fn_80390248();
extern "C" void fn_803908EC(unsigned char* src, int a, int b)
{
    if (lbl_806EF394 == 0)
        fn_80390248();
    lbl_806EF38C = ((src[1] << 8 | src[0]) << 16) | (src[3] << 8 | src[2]);
    lbl_806EF390 = 0x20;
    lbl_806EF388 = src + 4;
    lbl_806EF398 = a;
    lbl_8069ACB8[0] = fn_80401BBC(lbl_80607218[0] << 16, lbl_806242E0[0]);
    for (int i = 1; i < 64; i++)
        lbl_8069ACB8[i] = fn_80401BBC((b * lbl_80607218[i]) << 13, lbl_806242E0[i]);
}

extern "C" void fn_80390CFC(int n)
{
    unsigned buf = lbl_806EF38C << n;
    int cnt = lbl_806EF390 - n;
    lbl_806EF38C = buf;
    lbl_806EF390 = cnt;
    if (cnt > 15)
        return;
    unsigned char* p = lbl_806EF388;
    unsigned w = (p[1] << 8) | p[0];
    lbl_806EF390 = cnt + 16;
    lbl_806EF388 = p + 2;
    lbl_806EF38C = buf | (w << (16 - cnt));
}

extern int lbl_8069B5B8[];
extern int lbl_8069B6B8[];
extern int lbl_8069B6D8[];
extern "C" void fn_80390EC0(int* in, int* out);
extern "C" void fn_80391060(int* in, int* out);
extern const unsigned lbl_80699BB8[];
extern const unsigned lbl_8069A3B8[];
extern const unsigned lbl_8069A7B8[];
extern const int lbl_80607318[];
extern "C" int fn_80390D54()
{
    lbl_8069B5B8[0] = ((int)lbl_806EF38C >> 24) * lbl_8069ACB8[0];
    fn_80390CFC(8);
    int* z = lbl_8069B5B8 + 1;
    for (int i = 0; i < 9; i++) {
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        z[3] = 0;
        z[4] = 0;
        z[5] = 0;
        z[6] = 0;
        z += 7;
    }
    int k = 1;
    for (;;) {
        unsigned e = lbl_80699BB8[lbl_806EF38C >> 23];
        int n = e & 0xFF;
        if (n > 9) {
            if (!(e & 0x20)) {
                if (!(e & 0x10)) {
                    fn_80390CFC(9);
                    e = lbl_8069A3B8[*(unsigned char*)&lbl_806EF38C];
                    n = e & 0xFF;
                } else {
                    fn_80390CFC(6);
                    e = lbl_8069A7B8[*(unsigned char*)&lbl_806EF38C];
                    n = e & 0xFF;
                }
            } else {
                if (e & 0x10) {
                    fn_80390CFC(2);
                    return k;
                }
                fn_80390CFC(6);
                e = lbl_806EF38C;
                n = 0x10;
            }
        }
        fn_80390CFC(n);
        k += (e >> 16) & 0x3F;
        lbl_8069B5B8[lbl_80607318[k]] = ((int)e >> 22) * lbl_8069ACB8[lbl_80607318[k]];
        k++;
    }
}

extern "C" void fn_80391194(int* dst, int stride)
{
    fn_80390EC0(lbl_8069B5B8 + 0, lbl_8069B6B8 + 0);
    fn_80390EC0(lbl_8069B5B8 + 8, lbl_8069B6B8 + 1);
    fn_80390EC0(lbl_8069B5B8 + 16, lbl_8069B6B8 + 2);
    fn_80390EC0(lbl_8069B5B8 + 24, lbl_8069B6B8 + 3);
    fn_80390EC0(lbl_8069B5B8 + 32, lbl_8069B6B8 + 4);
    fn_80390EC0(lbl_8069B5B8 + 40, lbl_8069B6B8 + 5);
    fn_80390EC0(lbl_8069B5B8 + 48, lbl_8069B6B8 + 6);
    fn_80390EC0(lbl_8069B5B8 + 56, lbl_8069B6B8 + 7);
    fn_80391060(lbl_8069B6B8, dst);
    fn_80391060(lbl_8069B6D8 + 0, dst + stride * 1);
    fn_80391060(lbl_8069B6D8 + 8, dst + stride * 2);
    fn_80391060(lbl_8069B6D8 + 16, dst + stride * 3);
    fn_80391060(lbl_8069B6D8 + 24, dst + stride * 4);
    fn_80391060(lbl_8069B6D8 + 32, dst + stride * 5);
    fn_80391060(lbl_8069B6D8 + 40, dst + stride * 6);
    fn_80391060(lbl_8069B6D8 + 48, dst + stride * 7);
}
