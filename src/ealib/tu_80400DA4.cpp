/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x80400DA4-0x804027DC (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* RealCore timing, wait and one-slot message helpers (EA). */
extern "C" {
void fn_80400CE4(void);
void fn_803FFFA8(int);
void OSInitMessageQueue(void* q, void* buf, int n);
int OSSendMessage(void* q, void* msg, int flags);
int OSReceiveMessage(void* q, void* msg, int flags);
void OSReport(const char* fmt, ...);
}
extern int lbl_806EEAE0;
extern int lbl_806EEADC;
extern int lbl_806EEAF0;
extern int lbl_806EEAF4;
extern char lbl_8060E8E8[];

extern "C" int fn_80400DA4()
{
    return lbl_806EEAE0;
}

extern "C" int fn_80400DAC()
{
    int old = lbl_806EEAF4;
    int now = fn_80400DA4();
    lbl_806EEAF4 = now;
    return now - old;
}

extern "C" void fn_80400DE4(int d)
{
    lbl_806EEAF0 = fn_80400DA4() + d;
}

extern "C" unsigned fn_80400E54();

/* near-miss: same length; retail loads the zero return value (li r3,0) before the loop-back branch, ours after it. */
extern "C" int fn_80400E18()
{
    while (fn_80400E54() == 0) {
        fn_80400CE4();
        fn_803FFFA8(0);
    }
    return 0;
}

extern "C" unsigned fn_80400E54()
{
    int t = fn_80400DA4() - lbl_806EEAF0;
    return (unsigned)~t >> 31;
}

extern "C" int fn_80400E84()
{
    return lbl_806EEADC;
}

extern int lbl_806EEAD4;
extern void (*lbl_8062EE20[8])(void);

extern "C" int fn_80400E8C(unsigned x)
{
    return (x >= 0x80003100 && x <= 0x82FFFFFF)
        || (x >= 0xC0003100 && x <= 0xC2FFFFFF)
        || (x >= 0xE0000000 && x <= 0xE0004000)
        || (x >= 0xC8000000 && x <= 0xC8083FFF)
        || (x >= 0x7E000000 && x <= 0x7FFFFFFF);
}

extern "C" void fn_80400EF8()
{
    lbl_806EEAD4++;
    for (int i = 0; i < 8; i++) {
        void (*f)(void) = lbl_8062EE20[i];
        if (f != 0)
            f();
    }
}

extern "C" void fn_80400F54()
{
    OSReport(lbl_8060E8E8);
}

extern "C" int fn_80400F80(char* s)
{
    OSInitMessageQueue(s + 4, s + 0x24, 1);
    return 1;
}

extern "C" void fn_80400FB0(char* s)
{
    int msg = 0;
    OSSendMessage(s + 4, &msg, 0);
}

extern "C" void fn_80400FE4(char* s)
{
    int msg;
    OSReceiveMessage(s + 4, &msg, 1);
}

extern "C" unsigned fn_80401010(const unsigned char* a, const unsigned char* b, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        if (*a++ != *b++)
            break;
    }
    return i;
}

extern "C" int fn_80401548(int a, int v, unsigned char* buf);

extern "C" int fn_80401610(int a, int v, unsigned char* buf, int flag)
{
    return fn_80401548(a, v, flag ? buf : 0);
}

extern "C" int fn_80401924(int a, const unsigned char* p, int b);

extern "C" int fn_80401710(const unsigned char* p, int a);

extern "C" int fn_804017B0(const unsigned char* p, int a)
{
    return fn_80401710(p, a);
}

extern "C" int fn_804017D0(const unsigned char* p)
{
    int r = 0;
    if (p[1] == 0xFB) {
        switch (p[0] & 0xFE) {
        case 0x10:
        case 0x18:
        case 0x1A:
        case 0x1E:
        case 0x30:
        case 0x32:
        case 0x34:
        case 0x46: {
            const unsigned char* q = p + 2;
            r = (p[2] << 16) | (q[1] << 8) | q[2];
            break;
        }
        case 0x90:
        case 0x98:
        case 0x9A:
        case 0x9E:
        case 0xB0:
        case 0xB2:
        case 0xB4:
        case 0xC6: {
            const unsigned char* q = p + 2;
            r = (p[2] << 24) | (q[1] << 16) | (q[2] << 8) | q[3];
            break;
        }
        case 0xC0:
            break;
        }
    }
    return r;
}

extern "C" int fn_80401904(const unsigned char* p)
{
    return fn_804017D0(p);
}

extern "C" int fn_80401BBC(int a, int b)
{
    return (int)(((long long)a * b + 0x8000) >> 16);
}

extern "C" void fn_80402570(int a, int b);

extern "C" void fn_804027B0()
{
    fn_80402570(1, 0xFFFF);
}
