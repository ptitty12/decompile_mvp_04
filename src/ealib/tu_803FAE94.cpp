/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803FAE94-0x803FBF54 (code-only unit, 29 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct RcReq {
    int a0, a1, a2, a3, a4, a5;
};

struct RcLNode {
    int m0;
    RcLNode* m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void (*m18)(int);
    volatile int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

struct RcLHead {
    RcLNode* m0;
    RcLNode* m4;
};

struct RcEnt {
    int m0;
    char pad[0x2c];
};

extern char lbl_806ADEA0[];
extern void (*lbl_806ADE94[3])(int);
extern int lbl_806EF474;
extern int lbl_806EF468;
extern RcEnt* lbl_806EEA98;
extern RcLHead lbl_806EF46C;
extern int lbl_806EEAA0;
extern "C" RcEnt* fn_803FAF8C(int id);
extern "C" void fn_803FAFD4(RcLNode* n);
extern "C" void fn_803FB040(RcLNode* n);

extern "C" int fn_80400828(void*);
extern "C" int fn_8040084C(void*);
extern "C" int fn_803FEE14(int, int);
extern "C" int fn_803FA3B4(int (*)(int, RcReq*), int, int, RcReq*);
extern "C" int fn_803FEBDC(int, int, int, int*);
extern "C" int fn_803FECF8(int, int);
extern "C" void fn_803FEC9C(int, int);
extern "C" void fn_803F9A80(int);
extern "C" int fn_803FB978(int, RcReq*);
extern "C" int fn_803FBA28(int, RcReq*);
extern "C" int fn_803FBB48(int, RcReq*);
extern "C" int fn_803FBC94(int, RcReq*);
extern "C" int fn_803FBDC4(int, RcReq*);
extern "C" int fn_803FEC4C(int, int, int, int, int);
extern "C" void fn_803F9884(int);
extern "C" void fn_803F99E8(int);
extern "C" int fn_803FC300(void*);
extern "C" int fn_803FC360(void*);
extern "C" void fn_803FFA60(void*, void*, int);
struct RcBuf14 {
    int m0, m4, m8, mC, m10;
};
extern RcBuf14 lbl_806ADE8C;
extern "C" void fn_804007D4(void*);
extern "C" int fn_803FB888(int);
extern "C" void fn_804007FC(void*);
extern "C" int fn_80400008(int);
extern "C" void fn_80400CE4(int);
extern "C" void fn_803FFFA8(int);
extern void* (*lbl_806ADE90[4])(const char*, int, int);
extern char lbl_8060E7C8[];
extern RcLNode* lbl_806EF470;
extern "C" void fn_803F96B0(int, void (*)(int, int, int));
extern "C" int fn_803F9CE8(int, int, RcLNode*);
extern "C" int fn_803F9E90(int, int, RcLNode*);
extern "C" int fn_803F9D74(int, int, int, int, int, RcLNode*);
extern "C" void fn_803FB0F8(int, int, RcLNode*);
extern char lbl_8060E7B8[];
extern "C" int fn_803F9C58(int, int, int, RcLNode*);
extern "C" void fn_803FB2D4(int, int, RcLNode*);

extern "C" void fn_803FAE94(RcLHead* l, RcLNode* n)
{
    fn_80400828(lbl_806ADEA0);
    if (l->m0 == 0)
        l->m0 = n;
    else
        l->m4->m4 = n;
    l->m4 = n;
    n->m4 = 0;
    fn_8040084C(lbl_806ADEA0);
}

extern "C" RcLNode* fn_803FAF00(RcLHead* l)
{
    RcLNode* r = 0;
    fn_80400828(lbl_806ADEA0);
    if (l->m0 != 0) {
        r = l->m0;
        l->m0 = r->m4;
    }
    fn_8040084C(lbl_806ADEA0);
    return r;
}

extern "C" void fn_803FAF5C(RcLNode* n)
{
    lbl_806EF474 += 0x100;
    if (lbl_806EF474 == 0)
        lbl_806EF474 = 0x100;
    n->m0 = ((unsigned char*)n)[3] | lbl_806EF474;
}

/* near-miss: 17 slots; retail keeps id in r10 and builds the result in r3 (li r3,0 ... bnelr), many spellings tried */
extern "C" RcEnt* fn_803FAF8C(int id)
{
    int idx = id & 0xff;
    if (id > 0xff && idx < lbl_806EF468) {
        RcEnt* e = (RcEnt*)((char*)lbl_806EEA98 + idx * 0x30);
        if (e->m0 == id)
            return e;
        return 0;
    }
    return 0;
}

extern "C" void fn_803FAFD4(RcLNode* n)
{
    if (n->m10 != 0) {
        unsigned a = n->m14;
        if (a > 1)
            lbl_806ADE94[0](a);
    }
    n->m1C = 0;
    n->m0 = ((unsigned char*)n)[3];
    fn_803FAE94(&lbl_806EF46C, n);
}

extern "C" void fn_803FB040(RcLNode* n)
{
    fn_80400828(lbl_806ADEA0);
    int a = n->m10;
    void (*cb)(int) = n->m18;
    int b = n->mC;
    n->m1C = 0;
    fn_8040084C(lbl_806ADEA0);
    if (a != 0) {
        if (b == 0)
            fn_803FAFD4(n);
    } else if (cb != 0)
        cb(n->m0);
}

extern "C" void fn_803FB0C0(int a, int b, RcLNode* n)
{
    fn_803F9A80(n->m1C);
    fn_803FB040(n);
}

extern "C" void fn_803FB0F8(int a, int b, RcLNode* n)
{
    int v = ((int (*)(int))fn_803F9A80)(n->m1C);
    n->m8 += v;
    n->m2C += v;
    if (v <= 0xfffff || n->m10 != 0) {
        n->m1C = fn_803F9CE8(n->m20, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB0C0);
    } else {
        int rem = n->m28 - v;
        n->m24 += v;
        n->m28 = rem;
        int len = rem;
        if (len > 0x100000)
            len = 0x100000;
        n->m1C = fn_803F9D74(n->m20, n->m24, n->m2C, len, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB0F8);
    }
}

extern "C" void fn_803FB1EC(int a, int b, RcLNode* n)
{
    int v = ((int (*)(int))fn_803F9A80)(n->m1C);
    if (n->m10 != 0) {
        n->m1C = fn_803F9CE8(n->m20, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB0C0);
    } else {
        int old = n->m28;
        n->m28 = v;
        void* mem = ((void* (*)(const char*, int, int))lbl_806ADE90[0])(lbl_8060E7B8, v, old);
        n->m14 = (int)mem;
        n->m2C = (int)mem;
        int len = n->m28;
        if (len > 0x100000)
            len = 0x100000;
        n->m1C = fn_803F9D74(n->m20, n->m24, (int)mem, len, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB0F8);
    }
}

extern "C" void fn_803FB2D4(int a, int b, RcLNode* n)
{
    int v = ((int (*)(int))fn_803F9A80)(n->m1C);
    n->m20 = v;
    if (v == 0) {
        fn_803FB040(n);
        return;
    }
    if (n->m10 != 0) {
        n->m1C = fn_803F9CE8(n->m20, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB0C0);
    } else if (n->m14 == 0) {
        int len = n->m28;
        if (len > 0x100000)
            len = 0x100000;
        n->m1C = fn_803F9D74(n->m20, n->m24, n->m2C, len, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB0F8);
    } else {
        n->m1C = fn_803F9E90(n->m20, 0x63, n);
        if (n->m1C != 0)
            fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB1EC);
    }
}

extern "C" void fn_803FB3DC(int count, int arg)
{
    if (lbl_806EEA98 == 0 && count <= 0x100) {
        int size = count * 0x30;
        lbl_806EF468 = count;
        char* mem = (char*)lbl_806ADE90[0](lbl_8060E7C8, size, arg);
        lbl_806EF470 = (RcLNode*)(mem + (size - 0x30));
        lbl_806EF46C.m0 = (RcLNode*)mem;
        lbl_806EEA98 = (RcEnt*)mem;
        fn_804007D4(lbl_806ADEA0);
        for (int i = 0; i < count; i++) {
            ((RcLNode*)lbl_806EEA98)[i].m0 = i;
            ((RcLNode*)lbl_806EEA98)[i].m4 = &((RcLNode*)lbl_806EEA98)[i + 1];
            ((RcLNode*)lbl_806EEA98)[i].m1C = 0;
        }
        ((RcLNode*)(size + (int)lbl_806EEA98) - 1)->m4 = 0;
    }
}


extern "C" int fn_803FB59C(int a, int b)
{
    RcLNode* n = fn_803FAF00(&lbl_806EF46C);
    if (n == 0)
        return 0;
    fn_803FAF5C(n);
    n->m14 = 1;
    n->m8 = 0;
    n->mC = 0;
    n->m10 = 0;
    n->m18 = 0;
    n->m24 = 0;
    n->m2C = 0;
    n->m28 = b;
    n->m1C = fn_803F9C58(a, 1, 0x64, n);
    if (n->m1C == 0)
        return 0;
    fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB2D4);
    return n->m0;
}

extern "C" int fn_803FB64C(int a, int b, int c)
{
    RcLNode* n = fn_803FAF00(&lbl_806EF46C);
    if (n == 0)
        return 0;
    fn_803FAF5C(n);
    n->m8 = 0;
    n->mC = 0;
    n->m10 = 0;
    n->m14 = 0;
    n->m18 = 0;
    n->m24 = 0;
    n->m28 = c;
    n->m2C = b;
    n->m1C = fn_803F9C58(a, 1, 0x64, n);
    if (n->m1C == 0)
        return 0;
    fn_803F96B0(n->m1C, (void (*)(int, int, int))fn_803FB2D4);
    return n->m0;
}

extern "C" int fn_803FB6FC(int id)
{
    int r;
    fn_80400828(lbl_806ADEA0);
    RcEnt* e = fn_803FAF8C(id);
    if (e == 0)
        r = -1;
    else
        r = ((int*)e)[7] == 0;
    fn_8040084C(lbl_806ADEA0);
    return r;
}

extern "C" int fn_803FB764(int id, int* p1, int* p2)
{
    int a = 0;
    fn_80400828(lbl_806ADEA0);
    RcLNode* n = (RcLNode*)fn_803FAF8C(id);
    if (n != 0) {
        a = n->m10;
        if (a == 0)
            n->mC = 1;
    }
    fn_8040084C(lbl_806ADEA0);
    if (n == 0 || a != 0)
        return -1;
    if (n->m1C != 0) {
        do {
            fn_803F99E8(n->m1C);
        } while (n->m1C != 0);
    }
    if (n->m10 != 0) {
        if (p1 != 0)
            *p1 = 0;
        if (p2 != 0)
            *p2 = 0;
        fn_803FAFD4(n);
        return -1;
    }
    if (p1 != 0)
        *p1 = n->m2C - n->m8;
    if (p2 != 0)
        *p2 = n->m8;
    fn_803FAFD4(n);
    return 1;
}

extern "C" int fn_803FB888(int id)
{
    int a = 0;
    int b = 0;
    int c = 0;
    fn_80400828(lbl_806ADEA0);
    RcLNode* n = (RcLNode*)fn_803FAF8C(id);
    if (n != 0) {
        a = n->m1C;
        b = n->m10;
        c = n->mC;
        if (a != 0 || c == 0)
            n->m10 = 1;
    }
    fn_8040084C(lbl_806ADEA0);
    if (n == 0 || b != 0 || n->m10 == 0)
        return -1;
    if (a != 0)
        fn_803F9884(a);
    else if (c == 0)
        fn_803FAFD4(n);
    return 1;
}

extern "C" int fn_803FB954(int a)
{
    return fn_803FEE14(a, lbl_806EEAA0);
}

extern "C" int fn_803FB978(int n, RcReq* p)
{
    int out;
    if (fn_803FEBDC(p->a0, 1, n, &out) != 0) {
        int m = n - 1;
        int r = fn_803FECF8(out, m);
        fn_803FEC9C(out, m);
        return r;
    } else
        return 0;
}

extern "C" int fn_803FB9E8(int a)
{
    RcReq q;
    q.a0 = a;
    q.a3 = 1;
    return fn_803FA3B4(fn_803FB978, 0, lbl_806EEAA0, &q);
}

/* near-miss: 99.7%, 2 slots; the reloaded p->a4 test uses r5/r0 in retail, r0/r9 here */
extern "C" int fn_803FBA28(int n, RcReq* p)
{
    int out;
    int mode = 1;
    if (p->a4 & 0x40)
        mode = 0x41;
    if (fn_803FEBDC(p->a0, mode, n, &out) != 0) {
        int m = n - 1;
        int len = fn_803FECF8(out, m);
        if (p->a4 & 0x40)
            len = (len + 0x7ff) & ~0x7ff;
        int r = ((int (*)(int, int))lbl_806ADE90[0])(p->a0, len);
        if (r != 0) {
            fn_803FEC4C(out, 0, r, len, m);
            fn_803FEC9C(out, m);
            return r;
        }
        fn_803FEC9C(out, m);
    }
    return 0;
}

extern "C" int fn_803FBB04(int a, int b)
{
    RcReq q;
    q.a0 = a;
    q.a4 = b;
    q.a3 = 1;
    return fn_803FA3B4(fn_803FBA28, 0, lbl_806EEAA0, &q);
}

/* near-miss: 98.6%; retail copies n-1 from r4 (addi r4,r31,-1; mr r28,r4) and rotates p/m/len0 registers */
extern "C" int fn_803FBB48(int n, RcReq* p)
{
    int out;
    int mode = 1;
    if (p->a4 & 0x40)
        mode = 0x41;
    if (fn_803FEBDC(p->a0, mode, n, &out) != 0) {
        int m = n - 1;
        int len0 = fn_803FECF8(out, m);
        int len;
        if (p->a4 & 0x40)
            len = (len0 + 0x7ff) & ~0x7ff;
        else
            len = len0;
        int r = ((int (*)(int, int, int))lbl_806ADE90[0])(p->a0, len, p->a4);
        if (r != 0) {
            fn_803FEC4C(out, 0, r, len, m);
            fn_803FEC9C(out, m);
            p->a2 = len0;
            return r;
        }
        fn_803FEC9C(out, m);
    }
    return 0;
}

extern "C" void fn_803FBC34(int a, int* out, int c)
{
    RcReq q;
    q.a0 = a;
    q.a4 = c;
    q.a3 = 0;
    fn_803FA3B4(fn_803FBB48, 0, lbl_806EEAA0, &q);
    if (out != 0)
        *out = q.a2;
}

/* near-miss: 97.6%; callee-saved registers rotated (retail p=r29 n=r30 lim=r31, ours n=r29 lim=r30 p=r31) */
extern "C" int fn_803FBC94(int n, RcReq* p)
{
    int out;
    int lim = p->a2;
    if (lim <= 0)
        lim = 0x7fffffff;
    if (fn_803FEBDC(p->a0, 1, n, &out) != 0) {
        int m = n - 1;
        int r = fn_803FEC4C(out, 0, p->a1, lim, m);
        fn_803FEC9C(out, m);
        return r;
    } else
        return 0;
}

extern "C" int fn_803FBD28(int a, int b, int c)
{
    RcReq q;
    q.a0 = a;
    q.a2 = c;
    q.a3 = 1;
    q.a1 = b;
    q.a4 = 0;
    return fn_803FA3B4(fn_803FBC94, 0, lbl_806EEAA0, &q);
}

extern "C" int fn_803FBD78(int a, int b, int c)
{
    RcReq q;
    q.a0 = a;
    q.a2 = c;
    q.a1 = b;
    q.a3 = 0;
    q.a4 = 0;
    return fn_803FA3B4(fn_803FBC94, 0, lbl_806EEAA0, &q);
}

extern "C" int fn_803FBF10(int a, int b)
{
    RcReq q;
    q.a0 = a;
    q.a2 = b;
    q.a3 = 1;
    return fn_803FA3B4(fn_803FBDC4, 0, lbl_806EEAA0, &q);
}
