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
extern "C" int fn_803FBF54(int, RcCtx*);
extern "C" int fn_803FA3B4(int (*)(int, RcCtx*), int, int, RcArgs*);
extern "C" void fn_803FBD78(int, char*, int);
extern "C" void fn_804017D0(char*);
extern "C" void fn_803FC064(int);
extern "C" void fn_803FC1B0(int);
extern "C" int fn_803FC798(int, int, int, int, int, int, int);
extern "C" int fn_803FCCAC(int, int, int, int, int, int, int);
extern "C" int fn_803FC438(int, int);
extern "C" int fn_803FCCCC(RcHnd*, RcFile**, RcHnd**);

extern int lbl_806EF478;
extern "C" int fn_80400828(void*);
extern "C" int fn_8040084C(void*);
extern "C" void fn_803F972C(int, int);
extern "C" char* strcpy(char*, const char*);

extern "C" int fn_803F9A80(int);
extern "C" int fn_803F9C58(void*, int, int, void*);
extern "C" void fn_803F96B0(int, void (*)(int, int, RcFile*));
extern "C" void fn_803FD5F8(RcFile*, int);

struct RcMapTab {
    char pad[0x28];
    RcMap* m28;
    int m2C;
};

extern "C" int fn_803FE418(int);
extern "C" int fn_80400008(int);
extern "C" void fn_80400CE4(int);
extern "C" void fn_803FFFA8(int);
extern "C" void fn_804007FC(void*);
extern "C" void fn_803FEC9C(int, int);
extern "C" void fn_803FDDEC(int, int);

extern "C" int fn_803FEBDC(int, int, int, int*);
extern "C" int fn_803FEC74(int, int, int, int, int);

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

extern "C" void fn_803FC190(int a)
{
    fn_803FC064(a);
}

extern "C" void fn_803FC2E0(int a)
{
    fn_803FC1B0(a);
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
