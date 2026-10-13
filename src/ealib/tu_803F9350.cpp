/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803F9350-0x803FAE94 (code-only unit, 37 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */


union RcH {
    int i;
    struct {
        unsigned short g;
        unsigned char x;
        unsigned char idx;
    } s;
};

struct RcJob {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

struct RcSysJ {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    RcJob* m18;
    char* m1C;
};

struct RcBuf14 {
    int m0, m4, m8, mC, m10;
};

extern RcJob* lbl_806ADE64[3];
extern RcJob* lbl_806ADE70[3];
extern RcSysJ lbl_806ADE4C;
extern char lbl_806ADE74[];
extern RcBuf14 lbl_806ADE8C;
extern int lbl_806EEAA8;
extern int lbl_806EEAAC;
extern unsigned short lbl_806EEA90;
extern char* lbl_806ADE68[3];
extern char lbl_8060E700[];
extern char lbl_8060E748[];

extern "C" int fn_804002BC(const char*, ...);
extern "C" void fn_80435D20(void*);
extern "C" void fn_80435DFC(void*);
extern "C" void fn_803FFC58(void*, int, int);
extern "C" int fn_803F9A80(int);
extern "C" void fn_803FA410(int);
extern "C" int fn_80400008(int);
extern "C" void fn_80400CE4(int);
extern "C" void fn_803FFFA8(int);
extern "C" void fn_8040074C(void*, int);
extern "C" void fn_803FFA60(void*, void*, int);
extern "C" int fn_803F93F4(int);
extern "C" RcJob* fn_803FA94C();
extern "C" int fn_803FAA84(RcJob*);
extern "C" void fn_803FA948(RcJob*);
extern "C" char* strncpy(char*, const char*, unsigned);

extern "C" void* memset(void*, int, unsigned, ...);
extern "C" void fn_803F9EFC(int, int, int);
struct RcB30x {
    int w[12];
};
/* Object whose vptr sits at +0x44 (data-only base, then the virtuals). */
struct RcPad44 {
    char pad[0x44];
};
struct RcObj44 : RcPad44 {
    virtual void v0();
};

extern "C" void fn_803FADD0(int, int);

extern RcJob* lbl_806ADE60[3];
extern char lbl_8060E790[];
extern "C" int fn_803F9544(int, int, int, void*);
extern "C" int fn_803F9434();
extern "C" int fn_803F9464();

extern "C" int fn_803F963C(int a, int b, int c);

extern "C" void fn_80435CE8(void*);
extern "C" void fn_803FEE70(void);

extern "C" int strncmp(const char*, const char*, unsigned);
extern char lbl_8060E7AC[];
typedef void* (*RcAllocFn)(const char*, int, int);

extern "C" void fn_803F9350(RcObj44* o, int* a, RcB30x* b, int c)
{
    o->v0();
    *(int*)((char*)o + 8) = a[0];
    *(RcB30x*)((char*)o + 0xc) = *b;
    *(int*)((char*)o + 0x3c) = c;
    *(int*)((char*)o + 0x40) = 0;
}

extern "C" int fn_803F93F4(int h)
{
    int r = 0;
    if (h != 0)
        r = *(unsigned short*)&h == *(unsigned short*)((char*)lbl_806ADE64[0] + ((unsigned char*)&h)[3] * 0x30);
    return r;
}

extern "C" int fn_803F9434()
{
    fn_804002BC(lbl_8060E700);
    return 0;
}

extern "C" int fn_803F9464()
{
    fn_804002BC(lbl_8060E748);
    return 0;
}

extern "C" int fn_803F9494(int a, int b, int c)
{
    RcBuf14* q = &lbl_806ADE8C;
    if (q->m4 == 0) {
        q->m4 = (int)fn_803F9434;
        q->m8 = (int)fn_803F9464;
    }
    if (lbl_806ADE4C.m0 == 0) {
        void* mem = ((void* (*)(const char*, int, int))q->m4)(lbl_8060E790, fn_803F963C(a, b, c), 0);
        return fn_803F9544(a, b, c, mem);
    }
    return 0;
}

extern "C" int fn_803F9544(int a, int b, int c, void* mem)
{
    if (a == 0)
        a = 0x18;
    if (b == 0)
        b = 0x800;
    if (c == 0)
        c = 0xa;
    RcBuf14* q = &lbl_806ADE8C;
    if (q->m4 == 0) {
        q->m4 = (int)fn_803F9434;
        q->m8 = (int)fn_803F9464;
    }
    if (lbl_806ADE4C.m0 == 0) {
        lbl_806ADE4C.m18 = (RcJob*)mem;
        lbl_806ADE4C.m8 = 0xff;
        lbl_806ADE4C.m0 = c;
        lbl_806ADE4C.m4 = a;
        fn_80435CE8(lbl_806ADE74);
        fn_803FFC58(lbl_806ADE4C.m18, 0, fn_803F963C(a, b, c));
        lbl_806ADE4C.m1C = (char*)lbl_806ADE4C.m18 + lbl_806ADE4C.m0 * 0x30;
        fn_803FEE70();
        return 1;
    }
    return 0;
}

extern "C" int fn_803F963C(int a, int b, int c)
{
    if (a == 0)
        a = 0x18;
    if (c == 0)
        c = 0xa;
    return c * 0x30 + a * 0x144;
}

extern "C" int fn_803F9664(int h)
{
    int r;
    if (fn_803F93F4(h) != 0)
        r = (lbl_806ADE64[0] + ((unsigned char*)&h)[3])->m8;
    else
        r = -3;
    return r;
}

/* near-miss: 2 slots; retail loads j->m8 into r4 before j->m14 into r5 for the callback args */
extern "C" void fn_803F96B0(int h, void (*cb)(int, int, int))
{
    RcJob* j = lbl_806ADE4C.m18 + ((unsigned char*)&h)[3];
    int m8 = j->m8;
    j->m28 = (int)cb;
    if (m8 != 0) {
        lbl_806ADE4C.m10++;
        cb(h, j->m8, j->m14);
        lbl_806ADE4C.m10--;
    }
}

extern "C" int fn_803F99E8(int h)
{
    RcJob* j = lbl_806ADE64[0] + ((unsigned char*)&h)[3];
    if (fn_803F93F4(h) == 0)
        return -3;
    for (;;) {
        if (fn_80400008(0) != 0)
            fn_80400CE4(0);
        else
            fn_803FFFA8(10);
        if (fn_803F93F4(h) == 0)
            return -3;
        if (((volatile RcJob*)j)->m8 != 0)
            return ((volatile RcJob*)j)->m8;
    }
}

extern "C" int fn_803F9BC8(const char* name, int a, int b)
{
    RcJob* j = fn_803FA94C();
    j->m14 = b;
    j->m10 = a;
    *((unsigned char*)j + 2) = 8;
    j->m18 = 1;
    j->m24 = fn_803FAA84(j);
    if (j->m24 == 0) {
        j->mC = 2;
        fn_803FA948(j);
    }
    strncpy((char*)j->m24 + 5, name, 0xff);
    fn_803FA410((int)j);
    return j->m0;
}

extern "C" int fn_803F9C58(const char* name, int a, int b, int c)
{
    RcJob* j = fn_803FA94C();
    j->m14 = c;
    j->m18 = a;
    j->m10 = b;
    *((unsigned char*)j + 2) = 2;
    j->m24 = fn_803FAA84(j);
    if (j->m24 == 0) {
        j->mC = 2;
        fn_803FA948(j);
    }
    strncpy((char*)j->m24 + 5, name, 0xff);
    fn_803FA410((int)j);
    return j->m0;
}

extern "C" int fn_803F9CE8(int x, int a, int b)
{
    RcJob* j = fn_803FA94C();
    RcJob* p = lbl_806ADE70[0];
    *((unsigned char*)j + 2) = 3;
    j->m10 = a;
    j->m14 = b;
    j->m24 = x;
    while (p != 0) {
        if (p->mC == x) {
            j->mC = 3;
            fn_803FA948(j);
            break;
        }
        p = (RcJob*)p->m14;
    }
    fn_803FA410((int)j);
    return j->m0;
}

extern "C" int fn_803F9D74(RcJob* x, int a, int b, int c, int d, int e)
{
    RcJob* j = fn_803FA94C();
    *((unsigned char*)j + 2) = 4;
    j->m14 = e;
    j->m10 = d;
    if (x == 0) {
        j->mC = 6;
        fn_803FA948(j);
    }
    j->m24 = (int)x;
    int lim = ((int*)x)[0x104 / 4];
    if (a + c > lim)
        c = lim - a;
    j->m1C = c;
    j->m20 = b;
    j->m18 = a;
    fn_803FA410((int)j);
    return j->m0;
}

extern "C" int fn_803F9E0C(RcJob* x, int a, int b, int c, int d, int e)
{
    RcJob* j = fn_803FA94C();
    *((unsigned char*)j + 2) = 5;
    j->m14 = e;
    if (x == 0) {
        j->mC = 6;
        fn_803FA948(j);
    }
    j->m24 = (int)x;
    j->m10 = d;
    j->m1C = c;
    j->m18 = a;
    j->m20 = b;
    fn_803FA410((int)j);
    return j->m0;
}

extern "C" int fn_803F9E90(RcJob* x, int a, int b)
{
    RcJob* j = fn_803FA94C();
    *((unsigned char*)j + 2) = 6;
    j->m14 = b;
    j->m10 = a;
    if (x == 0) {
        j->mC = 6;
        fn_803FA948(j);
    }
    j->m24 = (int)x;
    fn_803FA410((int)j);
    return j->m0;
}

extern "C" void fn_803FA068(int h, int k, RcJob* req)
{
    int sav = (lbl_806ADE64[0] + ((unsigned char*)&h)[3])->m10;
    int x = fn_803F9A80(h);
    if (k != 1) {
        ((RcJob*)req->m10)->mC = 4;
        fn_803FA410(req->m10);
    } else {
        h = fn_803F9D74((RcJob*)x, 0, req->m0, 0x800, sav, (int)req);
        fn_803F96B0(h, (void (*)(int, int, int))fn_803F9EFC);
    }
}

extern "C" void fn_803FA214(int a, int b, int p)
{
    fn_803F9A80(a);
    fn_803FA410(p);
}

extern "C" int fn_803FA3B4(int (*cb)(int, int), int unused, int ctx, int arg)
{
    RcSysJ* s = &lbl_806ADE4C;
    int saved = s->m8;
    s->m8 = ctx;
    int r = cb(ctx, arg);
    s->m8 = saved;
    fn_803FA410(0);
    return r;
}

extern "C" void fn_803FA948()
{
}

extern "C" RcJob* fn_803FA94C()
{
    int i = 0;
    fn_80435D20(lbl_806ADE74);
    for (; i < lbl_806ADE4C.m0; i++) {
        if (*((unsigned char*)(lbl_806ADE4C.m18 + i) + 2) == 0) {
            *((unsigned char*)(lbl_806ADE4C.m18 + i) + 2) = 1;
            *((unsigned char*)(lbl_806ADE4C.m18 + i) + 3) = i;
            lbl_806EEA90++;
            if (lbl_806EEA90 == 0)
                lbl_806EEA90 = 1;
            *(unsigned short*)(lbl_806ADE4C.m18 + i) = lbl_806EEA90;
            break;
        }
    }
    fn_80435DFC(lbl_806ADE74);
    if (i == lbl_806ADE4C.m0)
        for (;;)
            ;
    return lbl_806ADE64[0] + i;
}

extern "C" void fn_803FAA38(void* p)
{
    fn_80435D20(lbl_806ADE74);
    fn_803FFC58(p, 0, 0x30);
    fn_80435DFC(lbl_806ADE74);
}

extern "C" int fn_803FAA84(RcJob*)
{
    int i = 0;
    fn_80435D20(lbl_806ADE74);
    for (; i < lbl_806ADE4C.m4; i++) {
        if (*((unsigned char*)lbl_806ADE4C.m1C + i * 0x144 + 4) == 0) {
            *((unsigned char*)lbl_806ADE4C.m1C + i * 0x144 + 4) = 1;
            break;
        }
    }
    fn_80435DFC(lbl_806ADE74);
    if (i == lbl_806ADE4C.m4)
        for (;;)
            ;
    return (int)(lbl_806ADE68[0] + i * 0x144);
}

extern "C" void fn_803FAB1C(void* p)
{
    fn_80435D20(lbl_806ADE74);
    fn_803FFC58(p, 0, 0x144);
    fn_80435DFC(lbl_806ADE74);
}

extern "C" int fn_803FACFC(int* p)
{
    int n = p[0];
    if (n > 0x14)
        fn_8040074C(p, n);
    lbl_806ADE8C.mC = lbl_806EEAAC;
    lbl_806ADE8C.m10 = lbl_806EEAA8;
    fn_803FFA60(p, &lbl_806ADE8C, n);
    return 1;
}

extern "C" int fn_803FAD60(int* p)
{
    if (p[0] <= 0x13)
        fn_8040074C(&lbl_806ADE8C, 0x14);
    fn_803FFA60(&lbl_806ADE8C, p, p[0]);
    lbl_806EEAA8 = lbl_806ADE8C.m10;
    lbl_806EEAAC = lbl_806ADE8C.mC;
    return 1;
}

/* near-miss: 99.1%; retail loads lbl_806EEAAC into r11 and lbl_806EEAA8 into r0, ours swap those temporaries */
extern "C" void fn_803FADD0(int a, int b)
{
    if (b == 0xffff && a != 0) {
        RcBuf14 s;
        RcBuf14* sp = &s;
        memset(sp, 0, 0x14);
        int x = lbl_806EEAAC;
        int y = lbl_806EEAA8;
        s.mC = x;
        s.m10 = y;
        s.m0 = 0x14;
        lbl_806ADE8C = s;
    }
}

extern "C" void fn_803FAE68()
{
    fn_803FADD0(1, 0xffff);
}
