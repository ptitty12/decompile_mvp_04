/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803F73B0-0x803F9350 (code-only unit, 40 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#define RCI(p, off) (*(int*)((char*)(p) + (off)))

struct RcSlotC {
    char pad[0x40];
    int m40;
    char pad2[0xa0];
};

struct RcIfV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int);
};

extern RcIfV* lbl_806EEA34;
extern int lbl_806EEA88;
extern char lbl_8060E6E8[];

extern "C" int fn_803F73B0(void*, int);
extern "C" int CARDRename(int, const char*, const char*);
extern "C" int CARDClose(void*);
extern "C" int fn_8041E4E0(int);
extern "C" int fn_8041B964(int, int*, int*);
extern "C" int fn_8042030C(int, int, int);
extern "C" int fn_803F8CB4(void*, void*, int*);
extern "C" void fn_803F8A2C(void*);
extern "C" void* memset(void*, int, unsigned);
extern "C" int strncmp(const char*, const char*, unsigned);
extern "C" void fn_803F6FC4(void*, int);
extern "C" int fn_803F7EB4(void*, void*);
extern "C" int fn_803F7E98(void*, void*);

struct RcB30 {
    int w[12];
};

struct RcRecA {
    int m0, m4, m8, mC, m10;
    char m14[4];
    char m18[2];
};

extern "C" int fn_803F73B0(void* o, int k)
{
    switch (k) {
    case 0:
        return 0;
    case -1:
        return 1;
    case -2:
        return 2;
    case -3:
        return 3;
    case -4:
        return 4;
    case -5:
        return 5;
    case -6:
        return 6;
    case -7:
        return 7;
    case -8:
        return 8;
    case -9:
        return 9;
    case -10:
        return 10;
    case -11:
        return 11;
    case -12:
        return 12;
    case -13:
        return 13;
    case -14:
        return 14;
    case -128:
        return 15;
    }
    return 16;
}

extern "C" RcSlotC* fn_803F74B0(char* p)
{
    RcSlotC* s = (RcSlotC*)(p + 8);
    for (int i = 0; i < 3; i++) {
        if (s->m40 == 0)
            return s;
        s = (RcSlotC*)((char*)s + 0xe4);
    }
    return 0;
}

extern "C" void* fn_803F74D8(void* a, void* b)
{
    return b;
}

extern "C" int fn_803F7584(void* o, int a, void* b, int* out)
{
    int n = fn_803F7EB4(o, b) + 0x44;
    if (RCI(b, 0x20) != 0)
        n += fn_803F7E98(o, b);
    n += 4;
    if (out != 0)
        *out = n;
    n += RCI(b, 4);
    unsigned d = RCI(o, 0x2b4);
    return (unsigned)(n + d - 1) / d;
}

extern "C" void fn_803F773C()
{
    lbl_806EEA88 = 0;
}

extern "C" int fn_803F7E98(void* a, void* b)
{
    int* t = (int*)RCI(b, 0x20);
    if (t[0] == 0)
        return 0x1800;
    return 0xe00;
}

extern "C" int fn_803F7EB4(void* a, void* b)
{
    int* t = (int*)RCI(b, 0x1c);
    if (t[10] == 0)
        return t[0] << 11;
    return t[0] * 3 << 9;
}

extern "C" int fn_803F870C(void* a, void* b)
{
    return RCI(fn_803F74D8(a, b), 0x10);
}

/* near-miss: 9 slots; retail loads *h (lhz) before zeroing the two out slots, order of the zero stores differs */
extern "C" int fn_803F8730(void* o, unsigned short* h, int* out1, int* out2)
{
    int s0 = 0;
    int s1 = 0;
    int r = 0xf;
    if (fn_8041B964(*h, &s1, &s0) == 0)
        r = 0;
    *out1 = s1 / RCI(o, 0x2b4);
    *out2 = s0;
    return r;
}

extern "C" int fn_803F885C(void* o, unsigned short* h, int* name1, const char* name2)
{
    int r;
    do {
        r = CARDRename(*h, (const char*)*name1, name2);
        lbl_806EEA34->v6(1);
    } while (r == -1);
    return fn_803F73B0(o, r);
}

extern "C" int fn_803F88D8(void* o, unsigned short* h)
{
    int r;
    do {
        r = fn_8041E4E0(*h);
        lbl_806EEA34->v6(1);
    } while (r == -1);
    return fn_803F73B0(o, r);
}

extern "C" int fn_803F8944()
{
    return lbl_806EEA88;
}

extern "C" int fn_803F894C(void* o, const char* a, const char* b)
{
    int r = 0;
    if (strncmp(b, (char*)o + 0x2c8, 4) == 0)
        r = strncmp(a, (char*)o + 0x2cc, 2) == 0;
    return r;
}

extern "C" void fn_803F89B0(void* o, int* a, RcRecA* p)
{
    RCI(o, 4) = (int)p;
    p->m4 = 0;
    p->m8 = 0;
    p->mC = 0;
    p->m10 = 0;
    memset(p->m14, 0, 4);
    memset(p->m18, 0, 2);
    RCI(RCI(o, 4), 0) = a[0];
    fn_803F8A2C(o);
}

extern "C" int fn_803F8C44(void* o, int* a, void* b, int c)
{
    unsigned cur = a[0];
    int s8 = -1;
    int r = fn_803F8CB4(o, b, &s8);
    if (r == 0) {
        int q;
        do {
            q = fn_8042030C(cur >> 16, s8, (unsigned char)c);
        } while (q == -1);
        r = fn_803F73B0(o, q);
    }
    return r;
}

extern "C" int fn_803F8D8C(int unused, void* f, int off, int whence)
{
    switch (whence) {
    case 0:
        RCI(f, 0xcc) = off;
        break;
    case 1:
        RCI(f, 0xcc) += off;
        break;
    }
    int p = RCI(f, 0xcc);
    if (p < 0 || p >= RCI(f, 0x7c))
        return 0xb;
    return 0;
}

extern "C" int fn_803F8F80(void* o, char* p)
{
    int r;
    do {
        r = CARDClose(p + 0x48);
        lbl_806EEA34->v6(1);
    } while (r == -1);
    int rc = fn_803F73B0(o, r);
    if (rc == 0)
        RCI(p, 0x40) = rc;
    return rc;
}

extern "C" void fn_803F91FC(void** self, int c)
{
    *self = lbl_8060E6E8;
    if (c & 1)
        fn_803F6FC4(self, 4);
}

extern "C" void fn_803F9234(char* o)
{
    memset(o + 0xc, 0, 0x30);
    RCI(o, 0x3c) = 1;
    RCI(o, 0x40) = 0;
}

extern "C" void fn_803F927C(char* o, int* a, RcB30* b, int c)
{
    RCI(o, 8) = a[0];
    *(RcB30*)(o + 0xc) = *b;
    RCI(o, 0x3c) = c;
    RCI(o, 0x40) = 0;
}

extern "C" void fn_803F92D8(char* o)
{
    memset(o + 0xc, 0, 0x30);
    RCI(o, 0x3c) = 1;
    RCI(o, 0x40) = 0;
    RCI(o, 0) = 0;
    memset(o + 0x48, 0, 0x14);
    RCI(o, 0xc8) = 0;
    RCI(o, 0xcc) = 0;
    RCI(o, 0xd4) = 0;
    RCI(o, 0xd0) = 0;
    RCI(o, 0xe0) = 0;
    RCI(o, 0xd8) = 0;
    RCI(o, 0xdc) = 1;
}
