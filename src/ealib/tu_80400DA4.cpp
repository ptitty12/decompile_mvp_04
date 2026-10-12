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

struct DtorAt0 { const void* m; };

extern "C" void fn_80401710(DtorAt0*, int);

extern "C" void fn_804017B0(DtorAt0* s, int chrg)
{
    fn_80401710(s, chrg);
}

extern "C" void fn_804017D0(DtorAt0*, int);

extern "C" void fn_80401904(DtorAt0* s, int chrg)
{
    fn_804017D0(s, chrg);
}

extern "C" void fn_80402570(int a, int b);

extern "C" void fn_804027B0()
{
    fn_80402570(1, 0xFFFF);
}
