/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803FEB34-0x803FFD9C (code-only unit, 31 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

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
extern const unsigned char lbl_8060E9F1[];
extern unsigned char lbl_806EEAB0;
extern "C" {
int OSSendMessage(void* q, int msg, int flags);
int fn_80406208(int h);
int fn_80406218(int h, int a, int b);
int fn_80406220(int h, int a, int b);
int fn_80422C3C(void* p);
void fn_804321CC(void);
void fn_803FF5E8(int, int);
}

extern "C" {
void fn_803F96B0(void* p);
void fn_803F99E8(int h);
int fn_803F9664(int h);
int fn_803F9A80(int h);
int fn_803F9C58(int a, int b, int c, int d);
int fn_803F9CE8(int a, int b, int c);
int fn_803F9E90(int a, int b, int c);
int fn_803FA100(int a, int b, int c, int d);
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
void fn_80432568(void* alarm);
void fn_804001E4(void);
int fn_80437A4C(void* thread, void* entry, int arg, int stackTop, int stackSize, int prio, int attr);
void fn_80437ED4(void* thread);
void OSInitMessageQueue(void* q, void* msgs, int n);
int OSReceiveMessage(void* q, int* msg, int flags);
void fn_804061F0(void);
int fn_80406200(int h, int a, int b);
int fn_804061F8(int h, int a);
int fn_804002BC(const char* fmt, ...);
int fn_803FF618();
}
extern unsigned char lbl_806EEAB1;
extern char lbl_806B82E0[0x28];
extern char lbl_806B5F20[0x318];
extern char lbl_806B8258[0x88];
extern int lbl_806EEAA8;
extern int lbl_806EEAAC;
extern int lbl_806EEAE0;
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

/* near-miss: 29 vs 28; retail keeps the xori before the subfic/adde (x ^ 1) != 0, gcc folds it to x != 1 in every spelling tried. */
extern "C" int fn_803FEBDC(int a, int b, int c, int* out)
{
    int ok = 0;
    int h = fn_803F9C58(a, b, c, 0);
    if (h != 0) {
        fn_803F99E8(h);
        ok = fn_803F9664(h) != 1;
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

/* near-miss: same as fn_803FEBDC. */
extern "C" int fn_803FED48(int a, int b, int c, int* out)
{
    int ok = 0;
    int h = fn_803FA100(a, b, c, 0);
    if (h != 0) {
        fn_803F99E8(h);
        ok = fn_803F9664(h) != 1;
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
    fn_80437A4C(lbl_806B5F20, (void*)fn_803FF618, 0, lbl_806EEAAC + lbl_806EEAA8, lbl_806EEAA8, 2, 1);
    OSInitMessageQueue(lbl_806B8238, lbl_806B8258, 0x20);
    fn_80437ED4(lbl_806B5F20);
    fn_804061F0();
}

extern "C" void fn_8040021C(int on);

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

/* near-miss: 19 vs 20 slots; retail rotates the loop (jump into the test, increment at the top). */
extern "C" int fn_803FF008(const char* a, const char* b)
{
    int i = 0;
    for (;;) {
        char cb = b[i];
        if (cb == 0)
            return i;
        int ca = a[i];
        if (lbl_8060E9F1[ca] & 1)
            ca += 0x20;
        if (ca != cb)
            return 0;
        i++;
    }
}

/* near-miss: 23 vs 21 slots; retail builds r != 0 with subfic/adde after a shared mr, ours branches. */
extern "C" int fn_803FF1BC(FsState* s)
{
    int r = 0;
    if (s->m0 == 3)
        r = fn_80406208(((int*)s)[0x108 / 4]);
    else if (s->m0 == 2)
        r = fn_80422C3C((char*)s + 0x108);
    return r != 0;
}

extern "C" void fn_803FF210()
{
    lbl_806ADEC0.m0 = 5;
    fn_803FF5E8(0, 0);
}

extern "C" void fn_803FF5E8(int, int)
{
    OSSendMessage(lbl_806B8238, 1, 1);
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
        fn_80406220(h, b, 0);
        fn_80406218(h, a, c);
        r = 1;
    }
    return r;
}

/* near-miss: 34 vs 33 slots. */
extern "C" int fn_803FF7C4(FsState* s)
{
    int r;
    if (s->m0 == 3) {
        int h = ((int*)s)[0x108 / 4];
        int a = fn_80406220(h, 0, 1);
        int b = fn_80406220(h, 0, 2);
        fn_80406220(h, a, 0);
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

extern "C" void fn_803FF994()
{
    if (lbl_806EEAB1) {
        lbl_806EEAB1 = 0;
        fn_80432568(lbl_806B82E0);
        fn_804001E4();
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
