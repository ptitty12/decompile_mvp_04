/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803FEB34-0x803FFD9C (code-only unit, 31 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
/* newlib ctype table: byte zero is the EOF sentinel. */
extern "C" const char _ctype_[];


/* RealCore async file I/O front end (hd: device). Callees are the request-queue entry points of tu_803F9350. */
extern "C" void fn_8040021C(int on);

/* RealCore async request state (lbl_806ADEC0, 0x334 bytes). */
struct FsState {
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
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
};
extern FsState lbl_806ADEC0;
extern char lbl_806B8238[];
extern unsigned char lbl_806EEAB0;
extern "C" {
int OSSendMessage(void* q, int msg, int flags);
int PCclose(int h);
int PCwrite(int h, int a, int b);
int PClseek(int h, int a, int b);
int DVDClose(void* p);
void fn_804321CC(void);
void fn_803FF5E8(int, int);
}

extern "C" {
void fn_803F96B0(void* p);
int fn_803F99E8(int h);
int fn_803F9664(int h);
int fn_803F9A80(int h);
int fn_803F9C58(const char* a, int b, int c, int d);
int fn_803F9CE8(int a, int b, int c);
int fn_803F9E90(int a, int b, int c);
int fn_803FA100(const char* a, int b, int c, int d);
int fn_803FA248(int a, int b, int c);
int fn_803F9BC8(int a, int b, int c);
extern char fn_803FEA38[];
extern char fn_803F9D74[];
extern char fn_803F9E0C[];
}

/* One transfer request, passed by address to the low-level read/write routine in the last argument. */
struct FsReq {
    int e;
    int a;
    int b;
    int d;
    int result;
    int len;
    int c;
    int (*fn)(int, int, int, int, int, FsReq*);
    int h;
};

extern "C" {
void OSCancelAlarm(void* alarm);
void fn_804001E4(void);
int OSCreateThread(void* thread, void* entry, int arg, int stackTop, int stackSize, int prio, int attr);
void OSResumeThread(void* thread);
void OSInitMessageQueue(void* q, void* msgs, int n);
void OSReceiveMessage(void* q, int* msg, int flags);
void PCinit(void);
int PCopen(int h, int a, int b);
int PCcreat(int h, int a);
int fn_804002BC(const char* fmt, ...);
int fn_803FF618();
int PCread(int h, int a, int b);
int fn_804250B0();
int fn_803FF424(void* p, int a, int c, int b);
void fn_803FF244(void* p);
void fn_803FA888(int);
void fn_803FFFA8(int);
}
extern unsigned char lbl_806EEAB1;
extern char lbl_806B82E0[0x28];
extern char lbl_806B5F20[0x318];
extern char lbl_806B8258[0x88];
extern int lbl_806EEAA8;
extern int lbl_806EEAAC;
extern volatile int lbl_806EEAE0;
extern volatile int lbl_806EEAE4;
typedef void (*Fn0)(void);
extern Fn0 lbl_8062EE40[8];
extern char lbl_8060E7D4[];

/* near-miss: 43 vs 42 slots; retail compares a reloaded r.len and stores fn after that load (volatile struct is the closest). */
extern "C" int fn_803FEB34(int a, int b, int c, int d, int e, int (*fn)(int, int, int, int, int, FsReq*))
{
    volatile FsReq r;
    r.e = e;
    r.a = a;
    r.b = b;
    r.d = d;
    r.result = 0;
    r.len = d;
    r.c = c;
    r.fn = fn;
    if (r.len > 0x100000)
        r.len = 0x100000;
    r.h = fn(a, b, r.c, r.len, e, (FsReq*)&r);
    if (r.h != 0) {
        fn_803F96B0(fn_803FEA38);
        do {
            fn_803F99E8(r.h);
        } while (r.d != 0 || r.h != 0);
    }
    return r.result;
}

/* Retail xori/subfic/adde returns one exactly when the request status is one. */
extern "C" int fn_803FEBDC(int a, int b, int c, int* out)
{
    int ok = 0;
    int h = fn_803F9C58((const char*)a, b, c, 0);
    if (h != 0) {
        fn_803F99E8(h);
        ok = fn_803F9664(h) == 1;
        *out = fn_803F9A80(h);
    } else {
        *out = ok;
    }
    return ok;
}

extern "C" void fn_803FEC4C(int a, int b, int c, int d, int e)
{
    fn_803FEB34(a, b, c, d, e, (int (*)(int, int, int, int, int, FsReq*))fn_803F9D74);
}

extern "C" void fn_803FEC74(int a, int b, int c, int d, int e)
{
    fn_803FEB34(a, b, c, d, e, (int (*)(int, int, int, int, int, FsReq*))fn_803F9E0C);
}

extern "C" int fn_803FEC9C(int a, int b)
{
    int ok = 0;
    int h = fn_803F9CE8(a, b, 0);
    if (h != 0) {
        ok = 1;
        fn_803F99E8(h);
        if (fn_803F9A80(h) == 0)
            ok = 0;
    }
    return ok;
}

extern "C" int fn_803FECF8(int a, int b)
{
    int r = 0;
    int h = fn_803F9E90(a, b, 0);
    if (h != 0) {
        fn_803F99E8(h);
        r = fn_803F9A80(h);
    }
    return r;
}

/* Same request-status equality test as fn_803FEBDC. */
extern "C" int fn_803FED48(int a, int b, int c, int* out)
{
    int ok = 0;
    int h = fn_803FA100((const char*)a, b, c, 0);
    if (h != 0) {
        fn_803F99E8(h);
        ok = fn_803F9664(h) == 1;
        *out = fn_803F9A80(h);
    } else {
        *out = ok;
    }
    return ok;
}

extern "C" int fn_803FEDB8(int a, int b)
{
    int ok = 0;
    int h = fn_803FA248(a, b, 0);
    if (h != 0) {
        ok = 1;
        fn_803F99E8(h);
        if (fn_803F9A80(h) == 0)
            ok = 0;
    }
    return ok;
}

extern "C" int fn_803FEE14(int a, int b)
{
    int ok = 0;
    int h = fn_803F9BC8(a, b, 0);
    if (h != 0) {
        ok = 1;
        fn_803F99E8(h);
        if (fn_803F9A80(h) == 0)
            ok = 0;
    }
    return ok;
}

extern "C" void fn_803FEE70()
{
    OSCreateThread(lbl_806B5F20, (void*)fn_803FF618, 0, lbl_806EEAAC + lbl_806EEAA8, lbl_806EEAA8, 2, 1);
    OSInitMessageQueue(lbl_806B8238, lbl_806B8258, 0x20);
    OSResumeThread(lbl_806B5F20);
    PCinit();
}

extern "C" void fn_8040021C(int on);

extern "C" int fn_803FEEE8(int h, unsigned mode, int* out)
{
    switch (mode & 7) {
    case 0:
        *out = PCopen(h, 2, 0);
        break;
    case 1:
        *out = PCopen(h, 0, 0);
        break;
    case 2:
        *out = PCopen(h, 2, 0);
        if (*out != -1)
            break;
    case 6:
        *out = PCcreat(h, 0);
        break;
    default:
        fn_804002BC(lbl_8060E7D4, mode);
        *out = -1;
        return 0;
    }
    return *out != -1;
}

extern "C" void fn_803FEFC4(char* dst, const unsigned char* src)
{
    int i = 0;
    unsigned char c = src[i];
    if (c != 0) {
        do {
            if (c == 0x5C)
                dst[i] = '/';
            else
                dst[i] = c;
            i++;
            c = src[i];
        } while (c != 0);
    }
    dst[i] = src[i];
}

/* Prefix scan with the increment block preceding the shared test. */
extern "C" int fn_803FF008(const char* a, const char* b)
{
    const unsigned char* table = (const unsigned char*)_ctype_ + 1;
    int i = 0;
    char cb;
    int ca;
    goto test;
next:
    i++;
test:
    cb = b[i];
    if (cb == 0)
        return i;
    ca = a[i];
    if (*(const unsigned char*)((unsigned)ca + (unsigned)table) & 1)
        ca += 0x20;
    if (ca == cb)
        goto next;
    return 0;
}

/* subfic/adde converts zero to one after the shared close result. */
extern "C" int fn_803FF1BC(FsState* s)
{
    int r = 0;
    if (s->m0 == 3)
        r = PCclose(((int*)s)[0x108 / 4]);
    else if (s->m0 == 2)
        r = DVDClose((char*)s + 0x108);
    return r == 0;
}

extern "C" void fn_803FF210()
{
    lbl_806ADEC0.m0 = 5;
    fn_803FF5E8(0, 0);
}

extern "C" void fn_803FFA60(char* d, const char* s, int n);
extern "C" int DVDReadAsyncPrio(void* fi, void* addr, int len, int off, void (*cb)(int, int), int prio);
extern "C" void fn_80432FA8(void* p, int n);

extern "C" void fn_803FF244(void* fi)
{
    int st = lbl_806ADEC0.m0;
    if (st == 2) {
        fn_803FFA60((char*)lbl_806ADEC0.m4, (char*)(((int*)&lbl_806ADEC0)[0x30 / 4] + (int)((char*)&lbl_806ADEC0 + 0x60)), lbl_806ADEC0.m34);
        lbl_806ADEC0.m8 += lbl_806ADEC0.m34;
        lbl_806ADEC0.m4 += lbl_806ADEC0.m34;
    } else if (st == 3) {
        fn_80432FA8((void*)lbl_806ADEC0.m4, lbl_806ADEC0.m1C - lbl_806ADEC0.m4);
        int t = lbl_806ADEC0.m1C - lbl_806ADEC0.m4;
        lbl_806ADEC0.m8 += t;
        lbl_806ADEC0.m4 += t;
    } else if (st == 4) {
        int n = lbl_806ADEC0.m18 - lbl_806ADEC0.m4;
        if (n > 0x4000)
            n = 0x4000;
        fn_803FFA60((char*)lbl_806ADEC0.m4, (char*)&lbl_806ADEC0 + 0x60, n);
        lbl_806ADEC0.m8 += n;
        lbl_806ADEC0.m4 += n;
    } else if (st == 1) {
        fn_803FFA60((char*)lbl_806ADEC0.m4, (char*)(((int*)&lbl_806ADEC0)[0x30 / 4] + (int)((char*)&lbl_806ADEC0 + 0x60)), lbl_806ADEC0.mC);
        lbl_806ADEC0.m0 = st;
        fn_803FF210();
        return;
    }
    if (lbl_806ADEC0.m4 == lbl_806ADEC0.m14 && lbl_806ADEC0.m4 < lbl_806ADEC0.m1C) {
        lbl_806ADEC0.m0 = 3;
        lbl_806ADEC0.m38 = DVDReadAsyncPrio(fi, (void*)lbl_806ADEC0.m4, lbl_806ADEC0.m1C - lbl_806ADEC0.m4, lbl_806ADEC0.m8, fn_803FF5E8, 2);
        return;
    }
    if (lbl_806ADEC0.m18 > lbl_806ADEC0.m4) {
        int n = (lbl_806ADEC0.m18 - lbl_806ADEC0.m4 + 0x1f) & ~0x1f;
        if (n > 0x4000)
            n = 0x4000;
        lbl_806ADEC0.m0 = 4;
        lbl_806ADEC0.m38 += DVDReadAsyncPrio(fi, (char*)&lbl_806ADEC0 + 0x60, n, lbl_806ADEC0.m8, fn_803FF5E8, 2);
        return;
    }
    fn_803FF210();
}

extern "C" void fn_803FF5E8(int, int)
{
    OSSendMessage(lbl_806B8238, 1, 1);
}

extern "C" int fn_803FF618()
{
    int msg;
    for (;;) {
        OSReceiveMessage(lbl_806B8238, &msg, 1);
        int c = ((volatile FsState*)&lbl_806ADEC0)->m44;
        FsState* d = (FsState*)((volatile FsState*)&lbl_806ADEC0)->m3C;
        int b = ((volatile FsState*)&lbl_806ADEC0)->m48;
        int a = ((volatile FsState*)&lbl_806ADEC0)->m40;
        if (d->m0 == 3) {
            PClseek(((int*)d)[0x108 / 4], c, 0);
            PCread(((int*)d)[0x108 / 4], a, b);
        } else {
            fn_803FF424((char*)d + 0x108, a, c, b);
            OSReceiveMessage(lbl_806B8238, &msg, 1);
            while (lbl_806ADEC0.m0 != 5) {
                fn_803FF244((char*)d + 0x108);
                OSReceiveMessage(lbl_806B8238, &msg, 1);
            }
        }
        for (;;) {
            int r = fn_804250B0();
            if (r == 0 || r == 8 || r == 1)
                break;
            fn_803FFFA8(100);
        }
        fn_803FA888(1);
    }
}


/* near-miss: same length; the queue address (lis/addi) is formed between the stores in retail. */
extern "C" int fn_803FF714(int a, int b, int c, int d)
{
    lbl_806ADEC0.m3C = a;
    lbl_806ADEC0.m44 = c;
    lbl_806ADEC0.m40 = b;
    lbl_806ADEC0.m48 = d;
    OSSendMessage(lbl_806B8238, 0, 1);
    return 1;
}

/* near-miss: 26 vs 25 slots. */
extern "C" int fn_803FF760(FsState* s, int a, int b, int c)
{
    int r = -1;
    if (s->m0 == 3) {
        int h = ((int*)s)[0x108 / 4];
        PClseek(h, b, 0);
        PCwrite(h, a, c);
        r = 1;
    }
    return r;
}

/* Reload the request handle after each seek call. */
extern "C" int fn_803FF7C4(FsState* s)
{
    int r;
    if (s->m0 == 3) {
        int h = ((int*)s)[0x108 / 4];
        int a = PClseek(h, 0, 1);
        int b = PClseek(((int*)s)[0x108 / 4], 0, 2);
        PClseek(((int*)s)[0x108 / 4], a, 0);
        return b;
    }
    r = 0;
    if (s->m0 == 2)
        r = ((int*)s)[0x13C / 4];
    return r;
}

extern "C" int fn_803FF848()
{
    return -1;
}

extern "C" void fn_803FF850()
{
    if (lbl_806EEAB0 == 0) {
        fn_804321CC();
        lbl_806EEAB0++;
    }
}

/* OS low-memory globals: 0xF8 bus clock (read as 0x800000F8). */
struct LowMem {
    char pad[0xF8];
    unsigned busClock;
};
#define LOWMEM ((LowMem*)0x80000000)
extern int lbl_806EEADC;
extern "C" {
long long fn_80438628(void);
void fn_804324EC(void* alarm, long long start, long long period, void (*handler)());
void fn_8040015C(void);
void fn_80400690(void (*cb)());
void fn_803FF994();
void fn_803FFA3C();
}

/* EA TIMER_init(int hz): starts the periodic alarm that ticks the RealCore timer thread (hz defaults to 100). */
extern "C" int fn_803FF888(int hz)
{
    if (lbl_806EEAB1 != 0)
        return lbl_806EEADC;
    if (hz == 0)
        hz = 100;
    lbl_806EEADC = hz;
    long long start = fn_80438628();
    long long period = (int)((float)(LOWMEM->busClock >> 2) * (1.0f / (float)hz));
    fn_8040015C();
    fn_804324EC(lbl_806B82E0, start, period, fn_803FFA3C);
    lbl_806EEAB1 = 1;
    fn_80400690(fn_803FF994);
    return lbl_806EEADC;
}

extern "C" void fn_803FF994()
{
    if (lbl_806EEAB1) {
        lbl_806EEAB1 = 0;
        OSCancelAlarm(lbl_806B82E0);
        fn_804001E4();
    }
}

extern "C" void fn_803FF9D4()
{
    lbl_806EEAE0++;
    lbl_806EEAE4++;
    for (int i = 0; i < 8; i++) {
        Fn0 f = lbl_8062EE40[i];
        if (f != 0)
            f();
    }
}

extern "C" void fn_803FFA3C() { fn_8040021C(0); }

extern "C" void fn_803FFA60(char* d, const char* s, int n)
{
    int diff = s - d;
    if (n == 0)
        return;
    if (diff == 0)
        return;
    if (diff & 1) {
        while (n > 3) {
            char a = s[0];
            char b = s[1];
            char c = s[2];
            char e = s[3];
            n -= 4;
            s += 4;
            d[0] = a;
            d[1] = b;
            d[2] = c;
            d[3] = e;
            d += 4;
        }
        while (n > 0) {
            *d++ = *s++;
            n--;
        }
        return;
    }
    if (diff & 2) {
        char* d2;
        const char* s2;
        s2 = s;
        d2 = d;
        if (((unsigned)s & 1) && n > 0) {
            *d2 = *s2;
            d2++;
            s2++;
            n--;
        }
        while (n > 7) {
            int a = ((const short*)s2)[0];
            int b = ((const short*)s2)[1];
            int c = ((const short*)s2)[2];
            int e = ((const short*)s2)[3];
            n -= 8;
            s2 += 8;
            ((short*)d2)[0] = a;
            ((short*)d2)[1] = b;
            ((short*)d2)[2] = c;
            ((short*)d2)[3] = e;
            d2 += 8;
        }
        while (n > 1) {
            *(unsigned short*)d2 = *(const unsigned short*)s2;
            n -= 2;
            s2 += 2;
            d2 += 2;
        }
        if (n > 0)
            *d2 = *s2;
        return;
    }
    if (((unsigned)s & 1) && n > 0) {
        *d++ = *s++;
        n--;
    }
    if (((unsigned)s & 2) && n > 1) {
        *(unsigned short*)d = *(const unsigned short*)s;
        n -= 2;
        s += 2;
        d += 2;
    }
    while (n > 15) {
        int a = ((const int*)s)[0];
        int b = ((const int*)s)[1];
        int c = ((const int*)s)[2];
        int e = ((const int*)s)[3];
        n -= 16;
        s += 16;
        ((int*)d)[0] = a;
        ((int*)d)[1] = b;
        ((int*)d)[2] = c;
        ((int*)d)[3] = e;
        d += 16;
    }
    while (n > 3) {
        *(int*)d = *(const int*)s;
        n -= 4;
        s += 4;
        d += 4;
    }
    if (n > 1) {
        *(unsigned short*)d = *(const unsigned short*)s;
        n -= 2;
        s += 2;
        d += 2;
    }
    if (n > 0)
        *d = *s;
}

extern "C" void fn_803FFC58(char* p, int v, int n)
{
    if (n > 0 && ((unsigned)p & 1)) {
        *p = v;
        n -= 1;
        p += 1;
    }
    if (n > 1 && ((unsigned)p & 2)) {
        *(short*)p = v;
        n -= 2;
        p += 2;
    }
    if (n > 3 && ((unsigned)p & 4)) {
        *(int*)p = v;
        n -= 4;
        p += 4;
    }
    if (n > 7 && ((unsigned)p & 8)) {
        ((int*)p)[0] = v;
        ((int*)p)[1] = v;
        n -= 8;
        p += 8;
    }
    if (n > 15 && ((unsigned)p & 16)) {
        ((int*)p)[0] = v;
        ((int*)p)[1] = v;
        ((int*)p)[2] = v;
        ((int*)p)[3] = v;
        n -= 16;
        p += 16;
    }
    while (n > 31) {
        ((int*)p)[0] = v;
        ((int*)p)[1] = v;
        ((int*)p)[2] = v;
        ((int*)p)[3] = v;
        ((int*)p)[4] = v;
        ((int*)p)[5] = v;
        ((int*)p)[6] = v;
        ((int*)p)[7] = v;
        n -= 32;
        p += 32;
    }
    if (n > 15) {
        ((int*)p)[0] = v;
        ((int*)p)[1] = v;
        ((int*)p)[2] = v;
        ((int*)p)[3] = v;
        n -= 16;
        p += 16;
    }
    if (n > 7) {
        ((int*)p)[0] = v;
        ((int*)p)[1] = v;
        n -= 8;
        p += 8;
    }
    if (n > 3) {
        *(int*)p = v;
        n -= 4;
        p += 4;
    }
    if (n > 1) {
        *(short*)p = v;
        n -= 2;
        p += 2;
    }
    if (n > 0)
        *p = v;
}
