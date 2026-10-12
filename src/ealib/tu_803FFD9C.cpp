/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803FFD9C-0x80400DA4 (code-only unit, 41 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* RealCore threading / diagnostics helpers (EA). */
extern "C" {
int fn_803FF850(void);
int fn_80437444(void);
int fn_80437A4C(int, int, int, int, int, int, int);
void fn_80437ED4(int);
void fn_80435CE8(int);
int fn_80437450(int);
void fn_80437D18(void);
void fn_804384BC(int, int);
int fn_804000C8(int);
void fn_803FFFA8(int);
int OSSendMessage(void*, int, int);
int OSReceiveMessage(void*, int*, int);
void OSInitMessageQueue(void*, void*, int);
void fn_803F9D74x(void);
void fn_803FF9D4(void);
void fn_80400EF8(void);
}
extern char lbl_806B8308[];
extern char lbl_806B8328[];
extern char lbl_806B83A8[];
extern char lbl_806B96C0[];
extern int lbl_806EEAB8;
extern "C" int fn_8040024C();
extern int lbl_806EF47C;
extern int lbl_8062EE40[8];
extern unsigned short lbl_8062E520[];
struct BitRec {
    int m0;
    int m4;
    unsigned m8 : 1;
    unsigned m8b : 31;
};
extern BitRec lbl_8062EE60[];

extern "C" {
void exit(int);
void fn_8040061C(void);
void fn_803FFF30(long long ticks);
void fn_803FFA60(void* d, const void* s, int n);
void fn_80400870(int idx, int v);
void fn_80400890(int a, int b);
void fn_80400948(void);
void fn_80437A10(void);
void fn_80400F80(void* p);
void fn_80400FE4(void* p);
void fn_80432224(void* alarm);
void fn_80432484(void* alarm, long long tick, void (*cb)(void*));
void fn_80432568(void* alarm);
void fn_803FFF0C(char* p);
void fn_80433CE8(const char* file, int line, const char* msg, ...);
}
extern void (*lbl_8062EB20[64])();
extern unsigned lbl_8062E720[256];
extern char lbl_8060E864[];
extern int lbl_806EEAD8;
extern int lbl_806EEAC8;

/* OS low-memory globals: 0xF8 bus clock, 0xFC CPU clock (read as 0x800000F8 / 0x800000FC). */
struct LowMem {
    char pad[0xF8];
    unsigned busClock;
    unsigned cpuClock;
};
#define LOWMEM ((LowMem*)0x80000000)

/* SysV varargs record (see include/game/tu_8000C2C4.h): __builtin_saveregs returns it, va_start copies it. */
struct va_list_tag {
    char gpr;
    char fpr;
    char* overflow_arg_area;
    char* reg_save_area;
};
typedef va_list_tag va_list[1];
#define va_start(AP, LASTARG) (__builtin_next_arg(LASTARG), *(AP) = *(va_list_tag*)__builtin_saveregs())
extern "C" int vsprintf(char*, const char*, va_list);
extern "C" void fn_80400ADC(int ch, const char* fmt, ...);
extern "C" void fn_80400A30(int ch, const char* fmt, va_list ap);
extern "C" void fn_80400678(void);
/* Log channel table lbl_8062EC20 (64 x 8): flag bits at +4 (MSB: enabled, next: follow-all). */
struct LogCh {
    int m0;
    unsigned f0 : 1;
    unsigned f1 : 1;
    unsigned rest : 30;
};
extern LogCh lbl_8062EC20[64];
/* Log sink table lbl_8062EE60 (8 x 12): m4 = callback(ch, text). */
struct LogSink {
    int m0;
    void (*m4)(int, char*);
    unsigned m8 : 1;
    unsigned m8b : 31;
};
/* Timer table lbl_806B96D8 (16 x 16). */
struct TimerEnt {
    int (*m0)(int, int);
    int m4;
    int m8;
    int m12;
};
extern TimerEnt lbl_806B96D8[16];
extern volatile int lbl_806EEAE4;
extern int lbl_806EEAD0;
extern int lbl_806EEACC;
extern void (*lbl_806EEAEC)(const char*, ...);
extern char lbl_8060E830[];
extern char lbl_8060E834[];
extern char lbl_8060E840[];
extern int lbl_806EEAC0;
extern int lbl_806EEAC4;

extern "C" void fn_80400BD4(int a, int b);
extern "C" void fn_80400B70(int idx, int v);

/* priority map: a thread-priority class (3..-3) to the OS priority */
extern "C" int fn_803FFD9C(int k)
{
    switch (k) {
    case 3:
        return 0;
    case 2:
        return 5;
    case 1:
        return 10;
    case 0:
        return 16;
    case -1:
        return 20;
    case -2:
        return 25;
    case -3:
        return 31;
    default:
        return 16;
    }
}

extern "C" void fn_803FFE14()
{
    fn_803FF850();
    lbl_806EF47C = fn_80437444();
}

extern "C" int fn_803FFE3C(int a, int b, int c, int d, int e, int f)
{
    int ok = 1;
    if (fn_80437A4C(a, b, c, d + e, e, fn_803FFD9C(f), 1) == 0)
        ok = 0;
    fn_80437ED4(a);
    return ok;
}

/* near-miss: 22 vs 21 slots. */
extern "C" void fn_803FFEB8(int h)
{
    int t;
    if (fn_804000C8(0) == 0) {
        if (h == -1)
            t = fn_80437444();
        else
            t = h;
        if (t != 0)
            fn_80437D18();
    }
}

extern "C" void fn_80400FB0(void* p);

extern "C" void fn_803FFF0C(char* p)
{
    fn_80400FB0(p + 0x28);
}

extern "C" void fn_803FFF30(long long ticks)
{
    char alarm[0x28];
    char ev[0x28];
    if (ticks == 0) {
        fn_80437A10();
        return;
    }
    fn_80400F80(ev);
    fn_80432224(alarm);
    fn_80432484(alarm, ticks, (void (*)(void*))fn_803FFF0C);
    fn_80400FE4(ev);
    fn_80432568(alarm);
}

extern "C" void fn_803FFFA8(int ms)
{
    fn_803FFF30((long long)ms * (LOWMEM->busClock / 4000));
}

extern "C" int fn_80400008(int h)
{
    int cur = fn_80437444();
    int t;
    if (h == 0)
        t = lbl_806EF47C;
    else if (h == -1)
        t = fn_80437444();
    else
        t = h;
    return cur == t;
}

extern "C" int fn_80400068(int h, int prio)
{
    int t;
    if (h == 0) {
        t = lbl_806EF47C;
    } else {
        if (h == -1)
            h = fn_80437444();
        t = h;
    }
    fn_804384BC(t, fn_803FFD9C(prio));
    return 1;
}

extern "C" int fn_804000C8(int h)
{
    if (h == 0)
        h = lbl_806EF47C;
    else if (h == -1)
        h = fn_80437444();
    return fn_80437450(h) != 0;
}

extern "C" int fn_80400114(int h)
{
    while (fn_804000C8(h) == 0)
        fn_803FFFA8(10);
    return 1;
}

extern "C" void fn_8040015C()
{
    if (lbl_806EEAB8 == 0) {
        fn_80437A4C((int)lbl_806B83A8, (int)fn_8040024C, 0, (int)lbl_806B96C0, 0x1000, 4, 1);
        OSInitMessageQueue(lbl_806B8308, lbl_806B8328, 0x20);
        fn_80437ED4((int)lbl_806B83A8);
    }
    lbl_806EEAB8++;
}

extern "C" void fn_8040021C(int msg);

extern "C" void fn_804001E4()
{
    lbl_806EEAB8--;
    if (lbl_806EEAB8 == 0)
        fn_8040021C(2);
}

extern "C" void fn_8040021C(int msg)
{
    OSSendMessage(lbl_806B8308, msg, 0);
}

/* near-miss: retail forms &msg per call (addi r4,r1,8); ours keeps it in a callee-saved register. */
extern "C" int fn_8040024C()
{
    int msg = 0;
    do {
        OSReceiveMessage(lbl_806B8308, &msg, 1);
        if (msg == 0)
            fn_803FF9D4();
        else if (msg == 1)
            fn_80400EF8();
    } while (msg != 2);
    return 0;
}

extern "C" void fn_804002BC(const char* fmt, ...)
{
    va_list ap;
    char buf[0x200];
    if (fmt) {
        va_start(ap, fmt);
        vsprintf(buf, fmt, ap);
    } else
        buf[0] = 0;
    lbl_806EEAEC(lbl_8060E830, buf);
}

extern "C" void fn_80400398(const char* fmt, ...)
{
    va_list ap;
    char buf[0x200];
    if (fmt) {
        va_start(ap, fmt);
        vsprintf(buf, fmt, ap);
    } else
        buf[0] = 0;
    fn_80400ADC(2, lbl_8060E834, buf);
    if (lbl_806EEAC0)
        fn_80400ADC(2, lbl_8060E840, lbl_806EEAC0, lbl_806EEAC4);
    fn_80400678();
}

extern "C" void fn_80400498(int v)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (lbl_8062EE40[i] == v) {
            lbl_8062EE40[i] = 0;
            return;
        }
    }
}

extern "C" unsigned short fn_80400520(const unsigned char* p, int n, unsigned crc)
{
    const unsigned char* end = p + n;
    while (p < end) {
        crc = lbl_8062E520[(*p++ ^ crc) & 0xFF] ^ (crc >> 8);
    }
    return crc;
}

extern "C" unsigned fn_80400560(const unsigned char* p, int n)
{
    unsigned crc;
    int i;
    if (n <= 3)
        return 0;
    crc = *p++ << 24;
    crc |= *p++ << 16;
    crc |= *p++ << 8;
    crc |= *p++;
    crc = ~crc;
    n -= 4;
    for (i = 0; i < n; i++) {
        crc = ((crc << 8) | *p++) ^ lbl_8062E720[crc >> 24];
    }
    return ~crc;
}

extern "C" void fn_804005DC()
{
    if (lbl_806EEAD8 != 0)
        fn_80433CE8(lbl_8060E864, 0, lbl_8060E864);
}

extern "C" void fn_8040061C()
{
    int i;
    for (i = 63; i >= 0; i--) {
        if (lbl_8062EB20[i])
            lbl_8062EB20[i]();
        lbl_8062EB20[i] = 0;
    }
}

extern "C" void fn_80400678()
{
    fn_8040061C();
    exit(0);
}

extern "C" void fn_803FFC58(void* x, int k, int a);

extern "C" void fn_8040074C(void* x, int a)
{
    fn_803FFC58(x, 0, a);
}

extern "C" void fn_80400774(unsigned char* d, unsigned char* s, unsigned n)
{
    if (d <= s || d >= s + n) {
        fn_803FFA60(d, s, n);
    } else {
        d += n;
        s += n;
        while (n-- != 0)
            *--d = *--s;
    }
}

extern "C" int fn_804007D4(int p)
{
    fn_80435CE8(p + 4);
    return 1;
}

extern "C" void fn_804007FC(void* x)
{
    fn_803FFC58(x, 0xDEADBEEF, 4);
}

struct Unk8037E6F4 {
    float m0;
    char m4;
    int m8;
};

extern "C" void fn_80435D20(Unk8037E6F4* o);

extern "C" void fn_80400828(char* self)
{
    fn_80435D20((Unk8037E6F4*)(self + 4));
}

extern "C" void fn_80435DFC(Unk8037E6F4* o);

extern "C" void fn_8040084C(char* self)
{
    fn_80435DFC((Unk8037E6F4*)(self + 4));
}

extern "C" void fn_80400870(int idx, int v)
{
    lbl_8062EE60[idx].m8 = v;
}

extern "C" void fn_80400890(int a, int b)
{
    int i;
    if (a == 0) {
        for (i = 0; i < 64; i++)
            lbl_8062EC20[i].f0 = (b != 0);
    } else if (a == 1) {
        for (i = 0; i < 64; i++) {
            if (lbl_8062EC20[i].f1)
                lbl_8062EC20[i].f0 = (b != 0);
        }
    } else {
        lbl_8062EC20[a].f0 = (b != 0);
    }
}

extern "C" void fn_80400948()
{
    int i;
    if (lbl_806EEAC8 == 0) {
        lbl_806EEAC8 = 1;
        for (i = 0; i < 8; i++)
            ((LogSink*)lbl_8062EE60)[i].m8 = 0;
        for (i = 0; i < 64; i++)
            lbl_8062EC20[i].f0 = 0;
        for (i = 4; i < 8; i++) {
            ((LogSink*)lbl_8062EE60)[i].m0 = 0;
            ((LogSink*)lbl_8062EE60)[i].m4 = 0;
        }
        for (i = 14; i < 64; i++) {
            lbl_8062EC20[i].m0 = 0;
            lbl_8062EC20[i].f1 = 0;
        }
        fn_80400BD4(2, 1);
        fn_80400B70(1, 1);
    }
}

extern "C" void fn_80400A30(int ch, const char* fmt, va_list ap)
{
    char buf[0x2000];
    int i;
    if (lbl_806EEAC8 == 0)
        fn_80400948();
    if (lbl_8062EC20[ch].f0) {
        vsprintf(buf, fmt, ap);
        for (i = 0; i <= 7; i++) {
            LogSink* s = &((LogSink*)lbl_8062EE60)[i];
            if (s->m8 && s->m4 != 0)
                s->m4(ch, buf);
        }
    }
}

extern "C" void fn_80400ADC(int ch, const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fn_80400A30(ch, fmt, ap);
}

extern "C" void fn_80400B70(int idx, int v)
{
    if (lbl_8062EE60[idx].m4 != 0) {
        if (lbl_806EEAC8 == 0)
            fn_80400948();
        fn_80400870(idx, v);
    }
}

extern "C" void fn_80400BD4(int a, int b)
{
    if (lbl_806EEAC8 == 0)
        fn_80400948();
    fn_80400890(a, b);
}

extern "C" void fn_80400C1C(int (*cb)(int, int), int a, int b)
{
    int slot = -1;
    int cnt;
    int i;
    if (a == -1)
        a = 0;
    else if (a == 0)
        a = 1;
    cnt = lbl_806EEACC;
    lbl_806EEACC = cnt + 1;
    for (i = 0; i < 16; i++) {
        TimerEnt* e = &lbl_806B96D8[i];
        if (e->m0 != cb) {
            if (e->m0 != 0 || slot != -1)
                continue;
            if (cnt != 0) {
                cnt--;
                continue;
            }
        }
        slot = i;
    }
    if (slot != -1) {
        lbl_806B96D8[slot].m4 = a;
        lbl_806B96D8[slot].m8 = lbl_806EEAE4 + b;
        lbl_806B96D8[slot].m0 = cb;
        lbl_806B96D8[slot].m12 = 0;
    }
    lbl_806EEACC--;
}

extern "C" int fn_80400CE4(int x)
{
    int res = 0;
    int i;
    lbl_806EEAD0 = lbl_806EEAE4;
    for (i = 0; i < 16; i++) {
        TimerEnt* e = &lbl_806B96D8[i];
        int (*f)(int, int) = e->m0;
        if (f != 0 && lbl_806EEAE4 >= lbl_806B96D8[i].m8 && lbl_806B96D8[i].m12 == 0) {
            lbl_806B96D8[i].m12 = 1;
            res |= f(x, lbl_806EEAE4 - lbl_806B96D8[i].m8);
            lbl_806B96D8[i].m8 = lbl_806EEAE4 + e->m4;
            lbl_806B96D8[i].m12 = 0;
        }
    }
    return res;
}
