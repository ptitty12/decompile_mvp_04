/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B6AF8-0x803B7D08 (code-only unit, 31 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

struct SndPair {
    float a;
    float b;
};

struct SndT3 {
    int a;
    int b;
    int c;
};

/* Source descriptor passed to every ctor (offsets seen in the ctors). */
struct SndSrc {
    void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    void* m28;
};

extern "C" {
void* memset(void*, int, unsigned);
void* fn_803B84CC(int);
void fn_803B84F8(int);
int fn_803B9448(void*);
void fn_803B9730(SndT3*, int);
void fn_803B9770(int, SndT3*, int);
void fn_803B978C(int, int);
void fn_803B9478(int, void*, int, int);
int fn_803B9508(int, float**, int);
void fn_803B02CC(int, void*);
char fn_803B02FC(int);
int fn_803B4BEC();
void fn_803B5738(int, unsigned char, int);
char* fn_803B54FC(int, unsigned char, void*, void*);
void* fn_803B8214(int);
void fn_803B8240(int);
void* fn_803B826C(void*);
int fn_803B8294(int, void*, int, int);
int fn_803B82D0(int, float**, int);
void fn_803B8488(void*, int, ...);
void fn_803B84B8(int, SndPair*);
}

extern void (*lbl_806AA4B8)(int, short*, float*);
struct SndHal {
    char pad[0x1E4];
    void (*cb)(int, short*, float*);
};
extern SndHal lbl_806AA2D4;

/* fn_803B6AF8: dst[i] = src[i] * gain + dst[i] */
extern "C" void fn_803B6AF8(int n, float* src, float* dst, float gain)
{
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i] * gain + dst[i];
}

struct SndRdA {
    void* m0;
    void* m4;
    int pad8[5];
    short* m1C;
    unsigned m20;
    unsigned m24;
    int m28;
};

extern "C" int fn_803B6B28(SndRdA* r)
{
    return r->m20;
}

extern "C" int fn_803B6B30(SndRdA* r, int n, int unused, float* dst)
{
    unsigned pos = r->m20;
    unsigned end = r->m24;
    if (pos >= end)
        return -1;
    r->m20 = pos + n;
    if (pos + n < end) {
        if (r->m28)
            lbl_806AA4B8(n, (short*)((char*)r->m1C + (pos << 1)), dst);
    } else {
        int k = end - pos;
        if (r->m28)
            lbl_806AA4B8(k, (short*)((char*)r->m1C + (pos << 1)), dst);
        memset(dst + k, 0, (n - k) * 4);
    }
    return 1;
}

struct SndRdA2 {
    void* m0;
    void* m4;
    int pad8[5];
    short* m1C;
    unsigned m20;
    int m24;
    unsigned m28;
    int m2C;
};

extern "C" void fn_803B6C08(SndRdA* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B6B30;
    r->m1C = (short*)s->m0;
    r->m20 = 0;
    r->m24 = s->mC;
    r->m28 = s->m18;
    s->m28 = (void*)fn_803B6B28;
    r->m4 = 0;
}

extern "C" int fn_803B6C48(SndRdA2* r)
{
    return r->m20;
}

extern "C" int fn_803B6C50(SndRdA2* r, int n, int unused, float* dst)
{
    if (n > 0) {
        SndHal* hal = &lbl_806AA2D4;
        do {
            int k = r->m28 - r->m20 + 1;
            unsigned pos = r->m20;
            if (n < k)
                k = n;
            if (r->m2C)
                hal->cb(k, (short*)((char*)r->m1C + (pos << 1)), dst);
            dst += k;
            r->m20 = r->m20 + k;
            n -= k;
            if (r->m20 > r->m28)
                r->m20 = r->m24;
        } while (n > 0);
    }
    return 1;
}

extern "C" void fn_803B6D0C(SndRdA2* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B6C50;
    r->m1C = (short*)s->m0;
    r->m20 = 0;
    r->m24 = s->m10;
    r->m28 = s->m14;
    r->m2C = s->m18;
    s->m28 = (void*)fn_803B6C48;
}

struct SndRdC {
    void* m0;
    void* m4;
    int pad8[5];
    unsigned m1C;
    unsigned m20;
    int m24;
    int m28;
};

extern "C" int fn_803B6D50(SndRdC* r)
{
    return r->m20;
}

/* near-miss: only the position of `li r3,-1` differs (retail puts it between the compare and the branch;
   every spelling of the -1 default tried hoists it to the top of the block) */
extern "C" int fn_803B6D58(SndRdC* r, int n, int unused, float* dst)
{
    int ret = -1;
    float* d = dst;
    if (r->m20 < r->m1C) {
        int k = fn_803B9508(r->m28, &d, n);
        r->m20 = r->m20 + k;
        d = d + k;
        if (k < n) {
            n -= k;
            memset(d, 0, n * 4);
        }
        ret = 1;
    }
    return ret;
}

extern "C" void fn_803B6DE8(SndRdC* r)
{
    if (r->m28)
        fn_803B84F8(r->m28);
}

extern "C" void fn_803B6E14(SndRdC* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B6D58;
    r->m1C = s->mC;
    r->m20 = 0;
    r->m24 = s->m24;
    s->m28 = (void*)fn_803B6D50;
    r->m4 = (void*)fn_803B6DE8;
    r->m28 = fn_803B9448(fn_803B84CC(0xD68));
    SndT3 t;
    SndT3 tmp;
    fn_803B9730(&tmp, r->m28);
    t = tmp;
    t.c = 1;
    fn_803B9770(r->m28, &t, 0);
    if (r->m24 <= 2)
        fn_803B978C(r->m28, 0);
    else
        fn_803B978C(r->m28, 1);
    fn_803B9478(r->m28, s->m0, r->m1C * 4, r->m1C);
}

struct SndRdD {
    void* m0;
    void* m4;
    int pad8[5];
    int m1C;
    int m20;
    int m24;
    int m28;
    void* m2C;
};

extern "C" int fn_803B6F14(SndRdD* r)
{
    return r->m20;
}

extern "C" int fn_803B6F1C(SndRdD* r, int n, int unused, float* dst)
{
    float* d = dst;
    if (n > 0) {
        do {
            int k = fn_803B9508(r->m1C, &d, n);
            n -= k;
            d += k;
            r->m20 = r->m20 + k;
            if (k < n) {
                r->m20 = r->m24;
                SndT3 t;
                t.b = 0;
                t.a = 0;
                t.c = 1;
                fn_803B9770(r->m1C, &t, 0);
                int c = r->m28 - r->m24 + 1;
                fn_803B9478(r->m1C, r->m2C, c * 4, c);
            }
        } while (n > 0);
    }
    return 1;
}

extern "C" void fn_803B6FE4(SndRdD* r)
{
    if (r->m1C)
        fn_803B84F8(r->m1C);
}

extern "C" void fn_803B7010(SndRdD* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B6F1C;
    r->m4 = (void*)fn_803B6FE4;
    r->m2C = (void*)s->m4;
    r->m20 = 0;
    r->m24 = s->m10;
    r->m28 = s->m14;
    r->m1C = fn_803B9448(fn_803B84CC(0xD68));
    SndT3 t;
    SndT3 tmp;
    fn_803B9730(&tmp, r->m1C);
    t = tmp;
    t.c = 1;
    fn_803B9770(r->m1C, &t, 0);
    fn_803B9478(r->m1C, s->m0, r->m24 * 4, r->m24);
    s->m28 = (void*)fn_803B6F14;
}

/* family E: fn_803B70F0 / fn_803B7348 / fn_803B7374 */
struct SndRdE {
    void* m0;
    void* m4;
    int pad8[5];
    char* m1C;
    int m20;
    int m24;
    int m28;
    unsigned short m2C;
    int m30;
    int m34;
    unsigned char m38;
};

extern "C" int fn_803B70F0(SndRdE* r, int n, int unused, float* dst);

extern "C" int fn_803B70F0(SndRdE* r, int n, int unused, float* dst)
{
    SndT3 t;
    SndT3 tmp;
    float* d = dst;
    int flag;
    int total = 0;
    if (r->m28 != 0) {
        fn_803B5738(r->m24, r->m38, r->m28);
        r->m28 = 0;
    }
    if (n > 0) {
        do {
            int k = fn_803B9508(r->m34, &d, n);
            r->m2C = r->m2C + k;
            d += k;
            r->m28 = r->m28 + k;
            total += k;
            if (k < n) {
                n -= k;
                r->m1C = fn_803B54FC(r->m24, r->m38, &r->m20, &flag);
                if (r->m1C != 0) {
                    r->m2C = 0;
                    if (r->m30 <= 2) {
                        if (flag == 0) {
                            fn_803B9730(&tmp, r->m34);
                            t = tmp;
                            t.c = 1;
                            fn_803B9770(r->m34, &t, 0);
                        } else {
                            fn_803B9730(&tmp, r->m34);
                            t = tmp;
                            t.c = 0;
                            fn_803B9770(r->m34, &t, 0);
                        }
                        fn_803B978C(r->m34, 0);
                    } else {
                        int f = flag;
                        if (f == 0) {
                            fn_803B9730(&tmp, r->m34);
                            t = tmp;
                            t.b = f;
                            t.c = 1;
                        } else {
                            fn_803B9730(&tmp, r->m34);
                            t = tmp;
                            t.c = 0;
                        }
                        fn_803B9770(r->m34, &t, 0);
                        fn_803B978C(r->m34, 1);
                    }
                    fn_803B9478(r->m34, r->m1C + 1, r->m20 * 4, r->m20);
                } else {
                    if (n > 0 && r->m28 != 0)
                        memset(d, 0, n * 4);
                    r->m20 = 0;
                    n = 0;
                }
            } else {
                n -= k;
            }
        } while (n > 0);
    }
    return total;
}

extern "C" void fn_803B7348(SndRdE* r)
{
    if (r->m34)
        fn_803B84F8(r->m34);
}

extern "C" void fn_803B7374(SndRdE* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B70F0;
    fn_803B02CC(s->m1C, s);
    r->m24 = fn_803B4BEC();
    r->m38 = fn_803B02FC(s->m1C);
    r->m1C = 0;
    r->m2C = 0;
    r->m30 = s->m24;
    r->m20 = s->mC;
    r->m4 = (void*)fn_803B7348;
    r->m34 = fn_803B9448(fn_803B84CC(0xD68));
    r->m28 = 0;
}

/* family F: fn_803B7404 / fn_803B7534 */
struct SndRdF {
    void* m0;
    void* m4;
    int pad8[5];
    char* m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    unsigned char m30;
    unsigned char m31;
};

extern "C" int fn_803B7404(SndRdF* r, int n, int unused, float* dst)
{
    int sp8;
    int spC;
    if (r->m2C != 0) {
        fn_803B5738(r->m28, r->m31, r->m2C);
        r->m2C = 0;
    }
    if (n > 0) {
        SndHal* hal = &lbl_806AA2D4;
        int z = 0;
        do {
            if (r->m24 >= r->m20) {
                r->m1C = fn_803B54FC(r->m28, r->m31, &sp8, &spC);
                if (r->m1C == 0) {
                    if (r->m2C != 0)
                        memset(dst, 0, n * 4);
                    break;
                }
                r->m24 = z;
                r->m20 = sp8;
            }
            int k = r->m20 - r->m24;
            if (n < k)
                k = n;
            if (r->m30)
                hal->cb(k, (short*)((char*)r->m1C + (r->m24 << 1)), dst);
            dst += k;
            r->m24 = r->m24 + k;
            r->m2C = r->m2C + k;
            n -= k;
        } while (n > 0);
    }
    return r->m2C;
}

extern "C" void fn_803B7534(SndRdF* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B7404;
    fn_803B02CC(s->m1C, s);
    r->m28 = fn_803B4BEC();
    r->m31 = fn_803B02FC(s->m1C);
    r->m20 = -1;
    r->m1C = 0;
    r->m24 = 0;
    r->m30 = *((unsigned char*)&s->m18 + 3);
    r->m2C = 0;
}

/* family G: fn_803B75A8 / fn_803B763C / fn_803B7644 / fn_803B7670 */
struct SndRdG {
    void* m0;
    void* m4;
    int pad8[5];
    int m1C;
    float* m20;
    int m24;
    int m28;
};

/* near-miss: same `li r3,-1` placement as fn_803B6D58 */
extern "C" int fn_803B75A8(SndRdG* r, int n, int unused, float* dst)
{
    float* d = dst;
    int ret = -1;
    if (r->m28 < r->m24) {
        int k = fn_803B82D0(r->m1C, &d, n);
        r->m28 = r->m28 + k;
        d += k;
        if (k < n) {
            n -= k;
            memset(d, 0, n * 4);
            k += n;
        }
        ret = k;
    }
    return ret;
}

extern "C" int fn_803B763C(SndRdG* r)
{
    return r->m28;
}

extern "C" void fn_803B7644(SndRdG* r)
{
    if (r->m1C)
        fn_803B8240(r->m1C);
}

extern "C" void fn_803B7670(SndRdG* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B75A8;
    r->m4 = (void*)fn_803B7644;
    r->m20 = (float*)s->m0;
    r->m24 = s->mC;
    r->m28 = 0;
    r->m1C = (int)fn_803B826C(fn_803B8214(0xA8));
    s->m28 = (void*)fn_803B763C;
    fn_803B8294(r->m1C, r->m20, r->m24 * 4, r->m24);
}

/* family H: fn_803B7700 / fn_803B7988 / fn_803B7990 / fn_803B79BC */
struct SndRdH {
    void* m0;
    void* m4;
    int pad8[5];
    int m1C;
    int m20;
    int m24;
    int m28;
    float* m2C;
    int m30;
    char* m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    float m4C;
    float m50;
};


/* near-miss: 4 instructions differ (r0/r9 swap in the `d += k` pointer update after the first-frame read) */
extern "C" int fn_803B7700(SndRdH* r, int n, int unused, float* dst)
{
    float buf[30];
    float* d = dst;
    SndPair p;
    SndPair q;
    float* d2;
    int rem;
    int total = 0;
    if (r->m30 <= 2) {
        if (r->m40 == 0) {
            rem = r->m44 / 28 * 28;
            fn_803B8294(r->m1C, r->m34, rem * 4, rem);
            r->m40 = 1;
        }
        if (n != 0) {
            do {
                int k = fn_803B82D0(r->m1C, &d, n);
                total += k;
                d += k;
                r->m20 += k;
                if (k < n) {
                    int m44 = r->m44;
                    n -= k;
                    rem = m44 % 28;
                    int base = m44 - rem;
                    r->m20 = base;
                    int cnt = r->m48 - base + 1;
                    fn_803B8294(r->m1C, r->m34 + base / 28 * 15, cnt * 4, cnt);
                    if (r->m3C == 0) {
                        fn_803B8488(&p, r->m1C);
                        q = p;
                        r->m4C = q.a;
                        r->m50 = q.b;
                        k = fn_803B82D0(r->m1C, &d, n);
                        d += k;
                        n -= k;
                        total += k;
                        r->m20 += k;
                        r->m3C = 1;
                    } else {
                        q.a = r->m4C;
                        q.b = r->m50;
                        fn_803B84B8(r->m1C, &q);
                        d2 = buf + 2;
                        r->m20 += fn_803B82D0(r->m1C, &d2, rem);
                    }
                } else {
                    n -= k;
                }
            } while (n != 0);
        }
    } else {
        while (n > 0) {
            int k = fn_803B82D0(r->m1C, &d, n);
            n -= k;
            d += k;
            r->m20 += k;
            total += k;
            if (k < n) {
                r->m20 = r->m24;
                int c = r->m28 - r->m24 + 1;
                fn_803B8294(r->m1C, r->m2C, c * 4, c);
            }
        }
    }
    return total;
}

extern "C" int fn_803B7988(SndRdH* r)
{
    return r->m20;
}

extern "C" void fn_803B7990(SndRdH* r)
{
    if (r->m1C)
        fn_803B8240(r->m1C);
}

extern "C" void fn_803B79BC(SndRdH* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B7700;
    r->m4 = (void*)fn_803B7990;
    r->m2C = (float*)s->m4;
    r->m20 = 0;
    r->m30 = s->m24;
    r->m24 = s->m10;
    r->m28 = s->m14;
    r->m1C = (int)fn_803B826C(fn_803B8214(0xA8));
    s->m28 = (void*)fn_803B7988;
    if (r->m30 <= 2) {
        r->m34 = (char*)s->m0;
        r->m38 = s->mC;
        r->m3C = 0;
        r->m40 = 0;
        r->m44 = s->m10;
        r->m48 = s->m14;
        return;
    }
    fn_803B8294(r->m1C, s->m0, r->m24 * 4, r->m24);
}

/* family I: fn_803B7A94 / fn_803B7C4C / fn_803B7C78 */
struct SndRdI {
    void* m0;
    void* m4;
    int pad8[5];
    int m1C;
    short* m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    unsigned char m38;
};


extern "C" int fn_803B7A94(SndRdI* r, int n, int unused, float* dst)
{
    float* d = dst;
    int flag;
    SndPair q;
    int total = 0;
    int mono = 0;
    if (r->m34 != 0) {
        fn_803B5738(r->m30, r->m38, r->m34);
        r->m34 = 0;
    }
    if (n > 0) {
        do {
            int k = fn_803B82D0(r->m1C, &d, n);
            r->m28 = r->m28 + k;
            d += k;
            r->m34 = r->m34 + k;
            total += k;
            if (k < n) {
                n -= k;
                r->m20 = (short*)fn_803B54FC(r->m30, r->m38, &r->m24, &flag);
                if (r->m20 != 0) {
                    if (r->m2C <= 2)
                        mono = 1;
                    if (mono != 0) {
                        q.a = r->m20[0];
                        q.b = r->m20[1];
                        fn_803B84B8(r->m1C, &q);
                        r->m20 = (short*)((char*)r->m20 + 4);
                    }
                    r->m28 = 0;
                    fn_803B8294(r->m1C, r->m20, r->m24 * 4, r->m24);
                } else {
                    if (n > 0 && r->m34 != 0)
                        memset(d, 0, n * 4);
                    n = 0;
                }
            } else {
                n -= k;
            }
        } while (n > 0);
    }
    return total;
}

extern "C" void fn_803B7C4C(SndRdI* r)
{
    if (r->m1C)
        fn_803B8240(r->m1C);
}

extern "C" void fn_803B7C78(SndRdI* r, SndSrc* s)
{
    r->m0 = (void*)fn_803B7A94;
    r->m4 = (void*)fn_803B7C4C;
    fn_803B02CC(s->m1C, s);
    r->m30 = fn_803B4BEC();
    r->m38 = fn_803B02FC(s->m1C);
    r->m2C = s->m24;
    r->m20 = 0;
    r->m24 = s->mC;
    r->m28 = 0;
    r->m34 = 0;
    r->m1C = (int)fn_803B826C(fn_803B8214(0xA8));
}
