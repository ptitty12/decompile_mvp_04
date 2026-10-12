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

extern "C" void fn_803FFC58(void* x, int k, int a);

extern "C" void fn_8040074C(void* x, int a)
{
    fn_803FFC58(x, 0, a);
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
