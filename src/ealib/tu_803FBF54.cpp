/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803FBF54-0x803FEB34 (code-only unit, 53 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern int lbl_806EEAA0;

struct RcArgs {
    int m0, m4, m8, mC, m10, m14;
};

struct RcSlot {
    int m0;
    int m4;
    char pad[0x11c];
};

struct RcTab {
    char pad[0x20];
    RcSlot* m20;
    int m24;
};

struct RcHnd {
    int m0;
    int m4;
    int m8;
};

struct RcNd {
    int m0;
    int m4;
    RcNd* m8;
    RcNd* mC;
};

struct RcMap {
    int m0;
    int m4;
    int m8;
};

/* evidence: fn_803FCCCC (handle -> object 'MRTS'), fn_803FCDCC/CE50/CF1C (node lists at +0x68..+0x74), fn_803FDBC4 (map at +0x28/+0x2C) */
struct RcFile {
    int m0;
    char m4[0x24];
    RcMap* m28;
    int m2C;
    char* m30;
    int m34;
    int m38;
    int pad3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int pad5C[3];
    RcNd* m68;
    RcNd* m6C;
    RcNd* m70;
    RcNd* m74;
    char pad78[0x100];
    int m178;
    int m17C;
    int m180;
    int m184;
};

struct RcCtx {
    int m0, m4, m8;
};
struct RcBuf14 {
    int m0, m4, m8, mC, m10;
};
extern RcBuf14 lbl_806ADE8C;
extern void (*lbl_806ADE94[3])(int);
extern "C" int fn_803FBC34(int, int*, int);
extern "C" int fn_80401710(void*, void*);
extern "C" void fn_80432FD4(void*, int);
extern "C" void fn_803FFA60(void*, void*, int);
extern "C" int fn_803FBF54(int, RcCtx*);
extern "C" int fn_803FA3B4(int (*)(int, RcCtx*), int, int, RcArgs*);
extern "C" void fn_803FBD78(int, char*, int);
extern "C" void fn_804017D0(char*);
extern "C" int fn_803FC064(int, int);
extern "C" int fn_803FC1B0(int, char*, int);
extern "C" int fn_803FC798(int, int, int, int, int, int, int);
extern "C" int fn_803FCCAC(int, int, int, int, int, int, int);
extern "C" int fn_803FC438(int, int);
extern "C" int fn_803FCCCC(RcHnd*, RcFile**, RcHnd**);

extern int lbl_806EF478;
extern "C" int fn_80400828(void*);
extern "C" int fn_8040084C(void*);
extern "C" void fn_803F972C(int, int);
extern "C" char* strcpy(char*, const char*);
extern "C" int strcmp(const char*, const char*);
extern "C" int fn_803F9CE8(int, int, RcFile*);

extern "C" int fn_803F9A80(int);
extern "C" int fn_803F9C58(void*, int, int, void*);
extern "C" void fn_803F96B0(int, void (*)(int, int, RcFile*));
extern "C" void fn_803FD5F8(RcFile*, int);

struct RcMapTab {
    char pad[0x28];
    RcMap* m28;
    int m2C;
};

extern "C" void fn_803FE418(int);
extern "C" int fn_80400008(int);
extern "C" void fn_80400CE4(int);
extern "C" void fn_803FFFA8(int);
extern "C" void fn_804007FC(void*);
extern "C" void fn_803FEC9C(int, int);
extern "C" void fn_803FDDEC(int, int);

extern "C" int fn_803FEBDC(int, int, int, int*);
extern "C" int fn_803FEC74(int, int, int, int, int);

/* One async transfer request (see tu_803FEB34: FsReq). Accessed through a volatile pointer in the completion callback. */
struct FsReqC {
    volatile int e;
    volatile int a;
    volatile int b;
    volatile int d;
    volatile int result;
    volatile int len;
    int c;
    int (*fn)(int, int, int, int, int, FsReqC*);
    int h;
};
extern "C" void fn_803FEA38(int h, int k, FsReqC* r);

extern "C" char* strncpy(char*, const char*, unsigned);
extern "C" void fn_803FD494(RcFile*, int);
extern "C" RcNd* fn_803FCDCC(RcFile*);
extern "C" void fn_803FCE50(RcFile*, RcNd*);
#define RCI(p, off) (*(int*)((char*)(p) + (off)))

extern "C" int fn_803FD010(RcFile*);

extern "C" int fn_803FBF54(int n, RcCtx* ctx)
{
    int out;
    if (fn_803FEBDC(ctx->m0, 6, n, &out) != 0) {
        int m = n - 1;
        int v = fn_803FEC74(out, 0, ctx->m4, ctx->m8, m);
        fn_803FEC9C(out, m);
        return v == ctx->m8;
    } else
        return 0;
}

extern "C" int fn_803FBFE0(int a, int b, int c)
{
    RcArgs args;
    args.m0 = a;
    args.m4 = b;
    args.m8 = c;
    args.mC = 1;
    return fn_803FA3B4(fn_803FBF54, 0, lbl_806EEAA0, &args) == 1;
}

extern "C" void fn_803FC034(int a)
{
    char buf[0x80];
    fn_803FBD78(a, buf, 0x80);
    fn_804017D0(buf);
}

/* near-miss: 2 slots; retail moves r3 (src) before r4 (len) for the fn_80432FD4 call; return-type toggles of the neighbouring callees did not change it */
extern "C" int fn_803FC064(int a, int b)
{
    int sz;
    char* src = (char*)fn_803FBC34(a, &sz, b);
    if (src == 0)
        return 0;
    int len = ((int (*)(char*))fn_804017D0)(src);
    if (sz != 0 && len != 0) {
        RcBuf14* q = &lbl_806ADE8C;
        char* tmp = (char*)((void* (*)(int, int, int))q->m4)(a, sz, b ^ 0x100);
        if (tmp == 0) {
            ((void (*)(char*))q->m8)(src);
            return 0;
        }
        fn_803FFA60(tmp, src, sz);
        ((void (*)(char*))q->m8)(src);
        src = (char*)((void* (*)(int, int, int))q->m4)(a, len, b);
        if (src != 0 && fn_80401710(tmp, src) == 0) {
            char* t = src;
            src = 0;
            ((void (*)(char*))q->m8)(t);
        }
        lbl_806ADE94[0]((int)tmp);
        fn_80432FD4(src, len);
    }
    return (int)src;
}

extern "C" void fn_803FC190(int a, int b)
{
    fn_803FC064(a, b);
}

extern "C" void fn_803FC2E0(int a, char* b, int c)
{
    fn_803FC1B0(a, b, c);
}

extern "C" int fn_803FC300(const unsigned char* p)
{
    int r = 0;
    if (((p[0] << 24) | (p[1] << 16) | (p[2] << 8)) == 0x42494700)
        r = 3;
    else if (((p[0] << 8) | p[1]) == 0xc0fb)
        r = 1;
    return r;
}

extern "C" int fn_803FC360(const unsigned char* p)
{
    int r = 0;
    switch (fn_803FC300(p)) {
    case 3: {
        const unsigned char* q = p + 0xc;
        r = (q[0] << 24) | (q[1] << 16) | (q[2] << 8) | q[3];
        break;
    }
    case 1:
        r = ((p[2] << 8) | p[3]) + 4;
        break;
    }
    return r;
}

extern "C" int fn_803FC3E8(int a, int b, int c, int d, int e)
{
    return fn_803FC798(a, b, c, d, e, 0, 0);
}

extern "C" int fn_803FC410(int a, int b, int c, int d, int e)
{
    return fn_803FC798(a, b, c, d, e, 0, 0);
}

extern "C" int fn_803FC438(int a, int b)
{
    int r = 0;
    if (b != 0)
        fn_803FCCAC(a, b, 0, (int)&r, 0, 0, 0);
    return r;
}

extern "C" int fn_803FC480(int a, int b)
{
    int r = 0;
    int n = fn_803FC438(a, b);
    if (n != 0)
        r = a + n;
    return r;
}

extern "C" int fn_803FC4C0(const unsigned char* p)
{
    int r = 0;
    switch (fn_803FC300(p)) {
    case 1:
        r = (p[4] << 8) | p[5];
        break;
    case 3: {
        const unsigned char* q = p + 8;
        r = (q[0] << 24) | (q[1] << 16) | (q[2] << 8) | q[3];
        break;
    }
    }
    return r;
}

extern "C" char* fn_803FC548(int a, int b, char* buf)
{
    char* r;
    char* s = (char*)fn_803FCCAC(a, 0, b, 0, 0, 0, 0);
    if (s == 0) {
        *buf = 0;
        r = 0;
    } else {
        strcpy(buf, s);
        r = buf;
    }
    return r;
}

extern "C" int fn_803FC5B0(const unsigned char* p)
{
    int r = 0;
    if (((p[0] << 24) | (p[1] << 16) | (p[2] << 8)) == 0x42494700)
        r = 3;
    else if (((p[0] << 8) | p[1]) == 0xc0fb)
        r = 1;
    return r;
}

extern "C" int fn_803FC610(const unsigned char* p)
{
    int r = 0;
    switch (fn_803FC5B0(p)) {
    case 3: {
        const unsigned char* q = p + 0xc;
        r = (q[0] << 24) | (q[1] << 16) | (q[2] << 8) | q[3];
        break;
    }
    case 1:
        r = ((p[2] << 8) | p[3]) + 4;
        break;
    }
    return r;
}

extern "C" int fn_803FC698(const unsigned char* base, int* pa, int* pb)
{
    int r = 0;
    const unsigned char* e = base + fn_803FC610(base);
    const unsigned char* s = e - 8;
    unsigned c0 = s[0];
    if (c0 - 0x41 <= 0x19 || c0 - 0x61 <= 0x19) {
        unsigned c1 = s[1];
        if (c1 - 0x30 <= 9) {
            unsigned c2 = s[2];
            if (c2 - 0x30 <= 9) {
                unsigned c3 = s[3];
                if (c3 - 0x30 <= 9) {
                    r = 8;
                    if (pa != 0)
                        *pa = ((char)c1 - 0x30) * 100 + ((char)c2 - 0x30) * 10 + ((char)c3 - 0x30);
                    if (pb != 0) {
                        const unsigned char* t = e - 4;
                        *pb = (e[-4] << 24) | (t[1] << 16) | (t[2] << 8) | t[3];
                    }
                }
            }
        }
    }
    return r;
}

extern "C" int fn_803FCCAC(int a, int b, int c, int d, int e, int f, int g)
{
    return fn_803FC798(a, b, c, d, e, f, g);
}

extern "C" int fn_803FCCCC(RcHnd* h, RcFile** o1, RcHnd** o2)
{
    if (h == 0)
        return 1;
    int* q = (int*)h->m0;
    if (q[0] != 0x4d525453)
        return 1;
    *o2 = h;
    *o1 = (RcFile*)q;
    return 0;
}

/* near-miss: 7 slots; unsigned b >= a is subfc/subfe/neg in retail, li/adde here */
extern "C" int fn_803FCD0C(unsigned x, unsigned a, unsigned b)
{
    if (x <= a) {
        if (b < x)
            return 0;
        return b >= a;
    }
    if (b >= x)
        return 1;
    if (b >= a)
        return 0;
    return 1;
}

extern "C" void fn_803FCD4C(RcFile* o, int n)
{
    fn_80400828(o->m4);
    int old = o->m58;
    int nw = old - n;
    o->m58 = nw;
    fn_8040084C(o->m4);
    if (old >= o->m50 && nw < o->m50) {
        o->m54 = 1;
        if (o->m44 == 1)
            fn_803F972C(o->m180, o->m4C);
    }
}

extern "C" RcNd* fn_803FCDCC(RcFile* o)
{
    RcNd* r = 0;
    fn_80400828(o->m4);
    RcNd* n = o->m74;
    if (n != 0) {
        r = n;
        o->m74 = n->mC;
        lbl_806EF478 += 0x100;
        if (lbl_806EF478 == 0)
            lbl_806EF478 = 0x100;
        n->m0 = ((unsigned char*)n)[3] | lbl_806EF478;
    }
    fn_8040084C(o->m4);
    return r;
}

extern "C" void fn_803FCE50(RcFile* o, RcNd* n)
{
    n->m4 = 1;
    n->mC = 0;
    fn_80400828(o->m4);
    RcNd* t = o->m70;
    if (t == 0) {
        n->m8 = t;
    o->m68 = n;
    o->m6C = n;
    o->m70 = n;
    } else {
        n->m8 = t;
        o->m70->mC = n;
        o->m70 = n;
    }
    fn_8040084C(o->m4);
}

extern "C" RcSlot* fn_803FCECC(RcTab* t, int k)
{
    int idx = k & 0xff;
    if (idx >= t->m24)
        return 0;
    RcSlot* e = (RcSlot*)((char*)t->m20 + idx * 0x124);
    if (k == e->m0) {
        RcSlot* r = 0;
        if (e->m4 != 0)
            r = e;
        return r;
    }
    return 0;
}

extern "C" void fn_803FCF1C(RcFile* o, RcNd* n)
{
    if (n == o->m68)
        o->m68 = n->mC;
    else
        n->m8->mC = n->mC;
    if (n == o->m70)
        o->m70 = n->m8;
    else
        n->mC->m8 = n->m8;
    if (n == o->m6C) {
        RcNd* t = n->mC;
        if (t == 0)
            t = n->m8;
        o->m6C = t;
    }
    n->m4 = 0;
    n->mC = o->m74;
    o->m74 = n;
}

/* near-miss: 1 slot; retail loads t->m28 after the count test and copies the bound (mr r11,r8) */
extern "C" int fn_803FCF9C(RcMapTab* t, const unsigned char* p)
{
    int k = (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
    int i;
    RcMap* e = t->m28;
    for (i = 0; i < t->m2C; i++) {
        if ((k & e->m0) == e->m4)
            return e->m8;
        e++;
    }
    return -2;
}

extern "C" void fn_803FD2F4(int a, int b, RcFile* o)
{
    int t = fn_803F9A80(*(int*)((char*)o + 0x180));
    *(int*)((char*)o + 0x178) = t;
    if (t != 0)
        fn_803FD5F8(o, o->m4C);
}

extern "C" void fn_803FD33C(int a, int b, RcFile* o)
{
    fn_803F9A80(o->m180);
    int h = fn_803F9C58((char*)o + 0x78, 1, o->m4C, o);
    o->m180 = h;
    if (h != 0)
        fn_803F96B0(h, fn_803FD2F4);
}

extern "C" void fn_803FD398(int, int, RcFile* f)
{
    RcNd* p = f->m6C;
    int amt;
    int flag;
    int r;
    if (RCI(p, 0x10) == 1) {
        amt = f->m184;
        flag = f->m17C + amt >= RCI(p, 0x118);
    } else {
        amt = fn_803F9A80(f->m180);
        flag = amt < f->m184;
    }
    f->m17C += amt;
    RCI(f, 0x64) += amt;
    r = fn_803FD010(f);
    if (p->m4 == 4) {
        fn_803FD494(f, f->m4C);
    } else if (flag != 0 || r != 0) {
        fn_80400828(f->m4);
        if (p->m4 != 4)
            p->m4 = 3;
        fn_8040084C(f->m4);
        fn_803FD494(f, f->m4C);
    } else {
        fn_803FD5F8(f, f->m4C - 1);
    }
}

/* near-miss: 96.5%; callee-saved registers rotated (retail: a=r27 job=r28 cr=r29 empty=r30; ours a=r28 job=r29 cr=r30 empty=r27) */
extern "C" void fn_803FD494(RcFile* o, int a)
{
    char* job = 0;
    fn_80400828(o->m4);
    int empty;
    RcNd* h = o->m6C;
    if (h == 0)
        empty = 1;
    else if (h->m4 != 1) {
        RcNd* nx = h->mC;
        if (nx == 0)
            empty = 1;
        else {
            o->m6C = nx;
            empty = 0;
        }
    } else
        empty = 0;
    if (empty != 0) {
        o->m44 = 0;
    } else {
        job = (char*)o->m6C;
        int cur = RCI(o, 0x60);
        RCI(job, 4) = 2;
        RCI(job, 0x120) = cur;
    }
    fn_8040084C(o->m4);
    if (empty == 0) {
        RCI(o, 0x64) = RCI(o, 0x60);
        if (RCI(job, 0x10) == 1) {
            o->m17C = 0;
        } else {
            o->m17C = RCI(job, 0x118);
            if (strcmp(job + 0x14, (char*)o + 0x78) != 0) {
                strcpy((char*)o + 0x78, job + 0x14);
                int k = o->m178;
                if (k == 0) {
                    int hd = fn_803F9C58((char*)o + 0x78, 1, a, o);
                    o->m180 = hd;
                    if (hd != 0)
                        fn_803F96B0(hd, fn_803FD2F4);
                } else {
                    int hd = fn_803F9CE8(k, a, o);
                    o->m180 = hd;
                    if (hd != 0)
                        fn_803F96B0(hd, fn_803FD33C);
                }
                return;
            }
        }
        fn_803FD5F8(o, a);
    }
}

extern "C" int fn_803FD944(int a, int b, int c)
{
    int t1 = b * 0xc;
    int t2 = c << 4;
    int t3 = a * 0x124;
    t1 += 0x18c;
    return t3 + t1 + t2 + 0x20;
}

extern "C" void fn_803FDBC4(int h, int a, int b, int c, int d)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC((RcHnd*)h, &o, &p) == 0) {
        if (a > 0) {
            RcFile* q = o;
            if (a <= o->m2C) {
                if (a == o->m2C && (b | c) != 0)
                    return;
                if (d > 0 || d == -1 || d == -2) {
                    if (d <= o->m34) {
                        if (o->m44 == 0) {
                            char* tab = (char*)o->m28;
                            int off = a * 0xc - 0xc;
                            *(int*)(tab + off) = b;
                            tab += off;
                            ((RcMap*)tab)->m4 = c;
                            ((RcMap*)tab)->m8 = d;
                        }
                    }
                }
            }
        }
    }
}

extern "C" void fn_803FDC80(int h)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC((RcHnd*)h, &o, &p) == 0) {
        fn_803FE418(h);
        while (o->m44 == 1) {
            if (fn_80400008(0) != 0)
                fn_80400CE4(0);
            fn_803FFFA8(0);
        }
        o->m0 = 0;
        fn_804007FC(o->m4);
        if (o->m178 != 0)
            fn_803FEC9C(o->m178, 0x64);
    }
}

extern "C" void fn_803FDD28(RcHnd* h, int a, int b)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC(h, &o, &p) == 0) {
        o->m48 = a;
        o->m4C = b;
    }
}

extern "C" void fn_803FDD78(int h, int v)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC((RcHnd*)h, &o, &p) == 0) {
        int old = o->m50;
        o->m50 = v;
        int a = o->m58 < v;
        int b = o->m58 < old;
        if (b != a)
            fn_803FDDEC(h, a);
    }
}

extern "C" void fn_803FDDEC(int h, int flag)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC((RcHnd*)h, &o, &p) == 0) {
        o->m54 = flag;
        if (flag != 0 && o->m44 == 1)
            fn_803F972C(o->m180, o->m4C);
    }
}

extern "C" char* fn_803FDE54(int h, int n)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC((RcHnd*)h, &o, &p) != 0 || n <= 0 || n > o->m34)
        return 0;
    return o->m30 + (n * 16 - 16);
}

extern "C" int fn_803FDEC0(RcHnd* h, const char* name, int a, int b)
{
    RcFile* o;
    RcHnd* p;
    int err = fn_803FCCCC(h, &o, &p);
    if (err != 0)
        return 0;
    RcNd* n = fn_803FCDCC(o);
    if (n == 0)
        return 0;
    RCI(n, 0x10) = err;
    strncpy((char*)n + 0x14, name, 0xfe);
    RCI(n, 0x118) = a;
    RCI(n, 0x11c) = b;
    fn_803FCE50(o, n);
    fn_80400828(o->m4);
    int was = o->m44;
    if (was == 0)
        o->m44 = 1;
    fn_8040084C(o->m4);
    if (was == 0) {
        if (o->m54 != 0)
            fn_803FD494(o, o->m4C);
        else
            fn_803FD494(o, o->m48);
    }
    return n->m0;
}

struct RcHndV {
    int m0, m4, m8;
    unsigned char* mC;
};
/* near-miss: 2 slots; the loop-back compare value is r0 in retail (or r0,r9,r10; cmpw r0,r28), r9 here */
extern "C" int fn_803FDFB4(RcHnd* h, unsigned char* data, int len, int tag)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC(h, &o, &p) != 0)
        return 0;
    RcNd* n = fn_803FCDCC(o);
    if (n == 0)
        return 0;
    if (len == 0) {
        unsigned char* q = data;
        if (((q[3] << 24) | (q[2] << 16) | (q[1] << 8) | q[0]) != tag) {
            do {
                const unsigned char* t = q + 4;
                int sz = (t[3] << 24) | (t[2] << 16) | (t[1] << 8) | q[4];
                q += sz;
                len += sz;
            } while (((q[3] << 24) | (q[2] << 16) | (q[1] << 8) | q[0]) != tag);
        }
        const unsigned char* t = q + 4;
        len += (t[3] << 24) | (t[2] << 16) | (t[1] << 8) | q[4];
    }
    RCI(n, 0x114) = (int)data;
    RCI(n, 0x118) = len;
    RCI(n, 0x11c) = tag;
    RCI(n, 0x10) = 1;
    fn_803FCE50(o, n);
    fn_80400828(o->m4);
    int was = o->m44;
    if (was == 0)
        o->m44 = 1;
    fn_8040084C(o->m4);
    if (was == 0)
        fn_803FD494(o, 0);
    return n->m0;
}

extern "C" void fn_803FCF1C(RcFile*, RcNd*);
struct RcFileV {
    char pad0[0x30];
    char* m30;
    int m34;
    char* m38;
    char* m3C;
    char pad40[4];
    int m44;
    char pad48[0x10];
    int m58;
    char* m5C;
    char* m60;
    char pad64[4];
    RcNd* m68;
    RcNd* m6C;
    RcNd* m70;
};
extern "C" void fn_803FE154(int, int);
/* near-miss: 96.0%; retail reuses the reloaded handle (r3 / r8) across the loop bodies, ours reloads it from the stack in each body */
extern "C" void fn_803FE418(int h)
{
    RcFileV* o;
    RcHnd* p;
    unsigned sz = 0;
    if (fn_803FCCCC((RcHnd*)h, (RcFile**)&o, &p) == 0) {
        RcNd* nd = o->m70;
        if (nd != 0) {
            while ((unsigned)(nd->m4 - 1) <= 1) {
                fn_803FE154(h, nd->m0);
                nd = o->m70;
            }
            while (o->m68 != o->m6C)
                fn_803FCF1C((RcFile*)o, o->m68);
            o->m6C->m4 = 4;
            int i;
            for (i = 0; i < o->m34; i++)
                RCI(o->m30, i * 0x10 + 8) = 0;
            fn_803FCD4C((RcFile*)o, o->m58);
            char* q = o->m5C;
            if (q != o->m60) {
                do {
                    if ((((unsigned char)q[3] << 24) | ((unsigned char)q[2] << 16) | ((unsigned char)q[1] << 8) | (unsigned char)q[0]) == -1)
                        q = o->m3C;
                    else {
                        char* t = q + 4;
                        sz = (((unsigned char)t[3] << 24) | ((unsigned char)t[2] << 16) | ((unsigned char)t[1] << 8) | (unsigned char)q[4]) & 0xffffff;
                        q[0] = -2;
                        q[1] = -1;
                        q[2] = -1;
                        q[3] = -1;
                        q[4] = sz;
                        t[3] = sz >> 24;
                        q += sz;
                        t[1] = sz >> 8;
                        t[2] = sz >> 16;
                    }
                } while (q != o->m60);
            }
            if (o->m44 == 2) {
                if (q == o->m3C) {
                    o->m60 = o->m38;
                    o->m3C = o->m60;
                } else {
                    int pad = 0x20 - ((int)o->m60 & 0x1f);
                    if (pad == 0x20)
                        pad = 0;
                    char* r = o->m60 - sz;
                    sz += pad;
                    char* t2 = r + 4;
                    r[4] = sz;
                    t2[3] = sz >> 24;
                    t2[1] = sz >> 8;
                    t2[2] = sz >> 16;
                    o->m60 = o->m60 + pad;
                }
                o->m44 = 0;
            }
        }
    }
}

/* near-miss: 2 slots; retail schedules slwi before the mr r4,r9 copy of the handle in the first loop test */
extern "C" unsigned char* fn_803FE660(RcHnd* hnd)
{
    RcFile* o;
    RcHndV* h;
    if (fn_803FCCCC(hnd, &o, (RcHnd**)&h) != 0)
        return 0;
    {
        if (h->m8 == 0)
            return 0;
        unsigned char* p = h->mC;
        const unsigned char* t = p + 4;
        unsigned sz = ((t[3] << 24) | (t[2] << 16) | (t[1] << 8) | p[4]) & 0xffffff;
        p[4] = sz;
        ((unsigned char*)t)[1] = sz >> 8;
        ((unsigned char*)t)[2] = sz >> 16;
        ((unsigned char*)t)[3] = sz >> 24;
        fn_80400828(o->m4);
        int rem = h->m8 - sz;
        h->m8 = rem;
        fn_8040084C(o->m4);
        if (rem > 0) {
            unsigned char* q = p + sz;
            int key = h->m4 << 24;
            if ((q[7] << 24) != key) {
                do {
                    if (((q[3] << 24) | (q[2] << 16) | (q[1] << 8) | q[0]) == -1)
                        q = (unsigned char*)o->pad3C;
                    else {
                        const unsigned char* t2 = q + 4;
                        sz = ((t2[3] << 24) | (t2[2] << 16) | (t2[1] << 8) | q[4]) & 0xffffff;
                        q += sz;
                    }
                } while ((q[7] << 24) != key);
            }
            h->mC = q;
        }
        return p;
    }
}

extern "C" void fn_803FE7E0(RcHnd* h, char* p)
{
    RcFile* o;
    RcHnd* hh;
    if (fn_803FCCCC(h, &o, &hh) == 0 && (unsigned)p >= (unsigned)o->pad3C && (unsigned)p <= (unsigned)(o->m40 - 8)
        && (((unsigned char)p[3] << 24) | ((unsigned char)p[2] << 16) | ((unsigned char)p[1] << 8) | (unsigned char)p[0]) != -2) {
        p[0] = -2;
        const unsigned char* t = (unsigned char*)p + 4;
        p[1] = -1;
        p[2] = -1;
        p[3] = -1;
        fn_803FCD4C(o, (t[3] << 24) | (t[2] << 16) | (t[1] << 8) | (unsigned char)p[4]);
        fn_80400828(o->m4);
        int v = o->m44;
        if (v == 2)
            o->m44 = 1;
        fn_8040084C(o->m4);
        if (v == 2) {
            if (o->m54 != 0)
                fn_803FD5F8(o, o->m4C);
            else
                fn_803FD5F8(o, o->m48);
        }
    }
}

extern "C" int fn_803FE914(RcHnd* h)
{
    RcFile* o;
    RcHnd* p;
    int r;
    if (fn_803FCCCC(h, &o, &p) == 0)
        r = p->m8;
    else
        r = 0;
    return r;
}

extern "C" int fn_803FE954(RcHnd* h)
{
    RcFile* o;
    RcHnd* p;
    int r;
    if (fn_803FCCCC(h, &o, &p) == 0)
        r = o->m44;
    else
        r = 0;
    return r;
}

extern "C" int fn_803FE994(RcHnd* h)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC(h, &o, &p) != 0)
        return 0;
    int r = 0;
    if (o->m44 == 0)
        r = p->m8 == 0;
    return r;
}

extern "C" int fn_803FE9F0(RcHnd* h)
{
    RcFile* o;
    RcHnd* p;
    if (fn_803FCCCC(h, &o, &p) != 0)
        return 0;
    return o->m40 - o->m38;
}

extern "C" void fn_803FEA38(int h, int k, FsReqC* r)
{
    int n = fn_803F9A80(h);
    r->h = 0;
    if (k == 1) {
        r->b += n;
        r->c += n;
        r->result += n;
        if (n < r->len)
            r->d = 0;
        else
            r->d -= n;
        if (r->d > 0) {
            if (r->d > 0x100000)
                r->len = 0x100000;
            else
                r->len = r->d;
            r->h = r->fn(r->a, r->b, r->c, r->len, r->e, (FsReqC*)r);
            if (r->h != 0)
                fn_803F96B0(r->h, (void (*)(int, int, RcFile*))fn_803FEA38);
            else
                r->d = r->h;
        }
    } else
        r->d = 0;
}
