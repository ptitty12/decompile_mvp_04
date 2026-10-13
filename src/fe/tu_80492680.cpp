/*
 * Front-end overlay code, .frontend_codeoverlay 0x80492680-0x804987EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_805F6BC4[];
extern const char lbl_805F4ECC[];
extern const char lbl_805F7060[];
extern "C" int sprintf(char*, const char*, ...);
extern "C" int fn_80097210(void* team, int a);
extern "C" void fn_80529150(void);
extern const char lbl_805F6AAC[];
extern const char lbl_805F6AB0[];
extern const char lbl_805F6AB4[];
extern const char lbl_805F6B2C[];
extern const char lbl_805F6B48[];
extern const char lbl_805F6B60[];
extern const char lbl_805F6B84[];
extern const char lbl_805F6BA4[];
extern const char lbl_805F7090[];
struct Fe4F94A {
    int m0;
    unsigned char m4;
    int m8;
};
struct Fe4F94B {
    int a;
    int b;
};
struct Fe4F94 {
    char pad0[0x338];
    Fe4F94A e[4];
    char pad368[0x368 - 0x338 - 48];
    Fe4F94B p[4];
};
extern "C" void fn_80496EE4(void* x, int a, int b, int c, int d, void* w, int e, int f, int g);
extern const char lbl_805F6AA8[];
extern const char lbl_805F6AB8[];
extern "C" void fn_8009E93C(char* p, int a, int b, char* out);
extern "C" int fn_80403088(const unsigned short* s, int ch);
extern "C" void fn_8040316C(unsigned short* dst, const unsigned short* src, int n);
extern "C" void fn_800DFF0C(unsigned short* dst, unsigned short* src);
extern const char lbl_805F7010[];
extern const char lbl_805F7030[];
struct Fe5080Rec {
    char pad0[0x1B4];
    unsigned char a[0x80];
    char pad234[0x3E4 - 0x234];
    unsigned char m3E4;
};
extern "C" int fn_80097A70(void* r, int a, int i, int b);
extern "C" float fn_80097F68(void* r, int a, int i, int b, int c);
static inline int SumB5080(Fe5080Rec* r)
{
    int s = 0;
    for (int j = 0; j < 0x80; j++) {
        s += r->a[(unsigned char)j];
    }
    return s;
}
extern "C" int fn_8008CFD8(void* p, int a, int b);
extern "C" int fn_80353870__FP11Unk80353870(void* t);
extern "C" int fn_80097148(void* team, int a);
extern "C" void fn_80497E00(void* x, int i);
extern "C" void fn_804980E4(void* x, int i);
struct Fe8620St {
    char pad0[0x628];
    int m628;
    char pad62C[8];
    int m634;
};
extern const char lbl_805F4F0C[];
extern const char lbl_805F59CC[];
extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
extern "C" void fn_804031F8(char* out, const char* a, const char* b);
extern "C" void fn_800DFEAC(char* a, const char* b);
extern "C" void fn_800C80C0(void* p, int v);
extern "C" void fn_80498620(int mode, void* x);
extern "C" void fn_801321D4(FeW* o, void* self, void (*cb)(int, void*), int a, void* b, int c, int d, int e, const char* s1, const char* s2, const char* s3, int f, int g, int h);
struct Fe498478Sec {
    unsigned char* p;
    int n;
    int u[3];
};
struct Fe498478Rec {
    Fe498478Sec s[5];
    char pad64[0x3E8 - 0x64];
    struct {
        int m0;
        char p[0x30];
    } e[1];
};
extern "C" int fn_800968C0(void* t, int a, int b);
extern "C" int fn_80097520(void* t, int a);
extern "C" int fn_80097238(void* t, int a);
extern "C" void fn_80571F4C(int a, int b, int c);
extern "C" void fn_80572710(int a);
extern "C" void fn_80572CB0(int a);
extern "C" void fn_80492680(void* x, int a, int b, int c);
extern const char lbl_805F69BC[];
extern "C" char* strncpy(char*, const char*, unsigned);
struct Fe3F20Sub {
    char pad0[0x4C];
    int m4C;
    int m50;
};
struct Fe3F20 {
    char pad0[0x184];
    int m184;
    int m188;
    int m18C;
    int m190;
    char pad194[0x19C - 0x194];
    Fe3F20Sub* m19C;
    char pad1A0[4];
    void* m1A4;
    char pad1A8[0x338 - 0x1A8];
    int m338;
    unsigned char m33C;
    int m340;
    int m344;
    unsigned char m348;
    int m34C;
    int m350;
    unsigned char m354;
    int m358;
};
extern "C" unsigned char* fn_80081CF8__FP13Unk8007FF8C_Yi(void* p, int k);
extern "C" int fn_80097620(void* rec, int a, int b, int c);
extern const char lbl_805F69E4[];
extern "C" FeW* fn_800C8060();
extern const char lbl_805F6940[];
extern "C" int fn_80099704(void* t);
extern "C" int fn_8006BC74(int a, int b);
extern "C" int fn_800E6058__Fi(int v);
extern "C" void fn_8040321C(char* out, const char* a, const char* b, const char* c);
extern "C" void fn_80403144(char* out, const char* a);
extern "C" int fn_800A2E6C(void* g);
extern "C" int fn_8056B7D0(int v);
extern const char lbl_805F54A0[];
extern const char lbl_805F54A8[];
extern const char lbl_805F6808[];
extern "C" void fn_80495CA4(void* x);
extern const char lbl_805F6934[];
extern "C" int fn_800971C8(void* t, int a);
extern const char lbl_805F7098[];
extern const char lbl_805F67E0[];
extern const char lbl_805F5340[];
extern const char lbl_805F5338[];
extern const char lbl_805F70C8[];
extern const char lbl_805F70CC[];
extern "C" void fn_800DE354__FiP8UdE354_Tiii(char* out, int a, int b, int c, int d);
extern const float lbl_805F6A98;
extern char* lbl_8061E978;
extern "C" int fn_80403060(const unsigned short* s);
extern "C" void fn_800D4254(unsigned short* s, int a, int* b, float* c);
extern "C" {

inline void Fe2FB4Get(char* rec, char* nm)
{
    fn_8009E93C(rec + 0x8C, 3, 0, nm);
}
inline char* FeIdc(char* p)
{
    return p;
}
/* near-miss: 97.1%, same instructions; retail has sp8 at r1+8 and spC at r1+12 (ours swapped: the first address-taken local gets the higher slot) and p/cnt in r30/r31 in the line-count loop */
FE_OVERLAY void fn_80492BA8(void* x, char* sc)
{
    unsigned short* s = (unsigned short*)sc;
    float spC = lbl_805F6A98;
    int sp8;
    int i;
    int n = fn_80403060((unsigned short*)FeI(x, 0x32C));
    if (s != 0) {
        int len;
        while (n + (len = fn_80403060(s)) > 0x270F && (i = fn_80403088((unsigned short*)FeI(x, 0x32C), 10)) != 0xFFFF) {
            unsigned short* m = (unsigned short*)FeI(x, 0x32C);
            fn_80403144((char*)m, (const char*)(m + i + 1));
            n = fn_80403060((unsigned short*)FeI(x, 0x32C));
        }
        char* tbase = lbl_8061E978;
        int j = len;
        int idx = (int)FeMem(x, 0x1D4)->fn_vslot34();
        char* tb = tbase + 0x11E88;
        int q = *(int*)(tb + idx * 4);
        fn_800D4254(s, q, &sp8, &spC);
        if (!(spC < (float)*(short*)(*(char**)((char*)x + 0x1CC) + 0x2A))) {
                do {
                if (j < len) {
                    s[j] = 0x20;
                }
                j--;
                if (j > 0) {
                    if (s[j] != 0x20) {
                        do {
                            j--;
                            if (j <= 0) {
                                break;
                            }
                        } while (s[j] != 0x20);
                    }
                    if (j > 0) {
                        s[j] = 0xA;
                    }
                }
                fn_800D4254(s, q, &sp8, &spC);
            } while (spC >= (float)*(short*)(*(char**)((char*)x + 0x1CC) + 0x2A));
        }
        fn_800DFF0C((unsigned short*)FeI(x, 0x32C), s);
    }
    unsigned short* p = (unsigned short*)FeI(x, 0x32C);
    int cnt = 0;
    while ((i = fn_80403088(p, 10)) != 0xFFFF) {
        cnt++;
        p += i + 1;
    }
    unsigned short* q2 = (unsigned short*)FeI(x, 0x32C);
    FeI(x, 0x330) = cnt;
    while (cnt > 3 && (i = fn_80403088(q2, 10)) != 0xFFFF) {
        cnt--;
        q2 += i + 1;
    }
    ((FeWV*)FeMem(x, 0x1D0))->s28(q2);
    FeW* w248 = FeMem(x, 0x248);
    int c2 = FeI(x, 0x330);
    int b2 = c2 - 10;
    int a1 = c2 - 9;
    ((FeWQ*)w248)->s33(a1 < 0 ? 0 : a1);
    ((FeWQ*)FeMem(x, 0x248))->s35(b2 < 0 ? 0 : b2);
    fn_80492E94(x);
}

FE_OVERLAY void fn_80492E94(void* x)
{
    unsigned short buf[200];
    unsigned short out[1000];
    int n = 0;
    int cnt = (int)FeMem(x, 0x248)->fn_vslot34();
    const unsigned short* p = (const unsigned short*)FeI(x, 0x32C);
    int i;
    while (n < cnt) {
        i = fn_80403088(p, 10);
        if (i == 0xFFFF) {
            break;
        }
        n++;
        p += i + 1;
    }
    int k = 0;
    out[0] = 0;
    while (k <= 9) {
        i = fn_80403088(p, 10);
        if (i == 0xFFFF) {
            break;
        }
        int m = i + 1;
        fn_8040316C(buf, p, m);
        k++;
        buf[m] = 0;
        fn_800DFF0C(out, buf);
        p += i + 1;
    }
    ((FeWV*)FeMem(x, 0x1CC))->s28(out);
}

/* near-miss (97.5%): the second range bound compiles to cmpwi 10 / ble where retail has cmpwi 11 / blt */
FE_OVERLAY void fn_80492FB4(void* x)
{
    char suf[0x10];
    char fmt[0x20];
    char nm[0x20];
    char out[0x80];
    unsigned char b = *(unsigned char*)((char*)FeP(x, 0x1A4) + 0x1CC8);
    int n = b + 1;
    int m = b + 1;
    if (n <= 0xD && b + 1 >= 0xB) {
        fn_804031BC(suf, lbl_805F6AA8);
    } else {
        switch (n % 10) {
        case 1:
            fn_804031BC(suf, lbl_805F6AAC);
            break;
        case 2:
            fn_804031BC(suf, lbl_805F6AB0);
            break;
        case 3:
            fn_804031BC(suf, lbl_805F6AB4);
            break;
        default:
            fn_804031BC(suf, lbl_805F6AA8);
            break;
        }
    }
    fn_804031BC(fmt, lbl_805F6AB8);
    Fe2FB4Get((char*)((FeScrB*)x)->m1A8[FeI(x, 0x184)], nm);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, FeIdc(nm), n, suf);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_804933A0(void* x)
{
    fn_804930F8(x);
    fn_80492FB4(x);
}

FE_OVERLAY void fn_804933D4(void* x, int a)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    fn_804031BC(fmt, lbl_805F6B18);
    fn_800DE440(n, a, 1);
    fn_80403DE4(out, fmt, n);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_80493448(void* x, int a, int u, int b)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    char suf[24];
    switch (b % 10) {
    case 1:
        fn_804031BC(suf, lbl_805F6AAC);
        break;
    case 2:
        fn_804031BC(suf, lbl_805F6AB0);
        break;
    case 3:
        fn_804031BC(suf, lbl_805F6AB4);
        break;
    }
    fn_804031BC(fmt, lbl_805F6B2C);
    fn_800DE440(n, a, 1);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, n, b, suf);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_80493544(void* x, int a, int b)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    char suf[24];
    fn_800DE440(n, a, 1);
    switch (b % 10) {
    case 2: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB0);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B48);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 3: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB4);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B48);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 4: {
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B60);
        fn_80403DE4(out, fp, n);
        break;
    }
    }
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_8049364C(void* x, int a)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    fn_804031BC(fmt, lbl_805F6B74);
    fn_800DE440(n, a, 1);
    fn_80403DE4(out, fmt, n);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_804936C0(void* x, int a, int b)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    char suf[24];
    fn_800DE440(n, a, 1);
    switch (b % 10) {
    case 2: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB0);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B84);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 3: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB4);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B84);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 4: {
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6BA4);
        fn_80403DE4(out, fp, n);
        break;
    }
    }
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_804937C8(void* x, int a, int b)
{
    char n1[0x40];
    char n2[0x40];
    char fmt[0x80];
    char out[0x100];
    fn_800DE440(n1, a, 1);
    fn_800DE440(n2, b, 1);
    fn_804031BC(fmt, lbl_805F6BC4);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, n2, n1);
    fn_80492BA8(x, out);
}

/* near-miss: 99.1%, only one slot differs: retail re-extends the m348 byte (clrlwi r0,r9,24) before the last cmpwi 0xFF, ours reuses r9 */
FE_OVERLAY void fn_80493F20(Fe3F20* x)
{
    if (x->m19C->m50 == 1) {
        unsigned char a = *fn_80081CF8__FP13Unk8007FF8C_Yi(x->m1A4, 1);
        char* bb = (char*)x + 0x1A8;
        int off = x->m184 * 4;
        int s = fn_80097620(*(void**)(bb + off), 3, x->m33C, 0);
        if (a == x->m33C || *fn_80081CF8__FP13Unk8007FF8C_Yi(x->m1A4, 2) == x->m33C || (s > x->m340 && x->m33C != 0xFF)) {
            fn_80493544(x, x->m338, 2);
        } else if (a == 0xFF) {
            fn_804936C0(x, x->m338, 2);
        }
    }
    if (x->m19C->m4C == 1) {
        unsigned char b = *fn_80081CF8__FP13Unk8007FF8C_Yi(x->m1A4, 2);
        char* bb = (char*)x + 0x1A8;
        int off = x->m184 * 4;
        int s = fn_80097620(*(void**)(bb + off), 3, x->m348, 0);
        int t2 = x->m348;
        if (b == t2 || (b != 0xFF && b == x->m33C) || (s > x->m34C && (unsigned char)t2 != 0xFF)) {
            fn_80493544(x, x->m344, 3);
        } else if (b == 0xFF) {
            fn_804936C0(x, x->m344, 3);
        }
    }
    if ((unsigned)(x->m190 - 2) <= 1) {
        unsigned char t = x->m354;
        int v;
        if (t != 0xFF) {
            char* bb = (char*)x + 0x1A8;
            int off = x->m184 * 4;
            int s = fn_80097620(*(void**)(bb + off), 3, t, 0);
            if (s <= x->m358) {
                fn_804936C0(x, x->m350, 4);
                v = 2;
            } else {
                fn_80493544(x, x->m350, 4);
                v = 0;
            }
        } else {
            v = 0;
        }
        x->m190 = v;
    }
}

/* near-miss: 99.6%, retail clrlwi r11,r5,24 then slwi r6 then mulli r11 (r11 not r0, mulli after slwi) */
FE_OVERLAY void fn_80494108(void* x, int k, int a, int b)
{
    char fmt[0x68];
    char n[200];
    char out[304];
    char* bb = (char*)x + 0x1A8;
    int off = b * 4;
    int o2 = (unsigned char)a * 0x34;
    char* r = *(char**)(bb + off);
    char* t = r + 0x3E8;
    fn_800DE440(n, *(int*)(t + o2), 1);
    switch (k) {
    case 1:
        fn_804031BC(fmt, lbl_805F7010);
        fn_80403DE4(out, fmt, n);
        break;
    case 3:
        fn_804031BC(fmt, lbl_805F7030);
        fn_80403DE4(out, fmt, n);
        break;
    }
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_80494F94(Fe4F94* x)
{
    for (int i = 0; i < 4; i++) {
        if (x->e[i].m0 != 0) {
            char buf[0x68];
            sprintf(buf, lbl_805F7090, i);
            FeW* w = fn_800C8044(FeMem(x, 0x1EC)->fn_vslot32(buf, 1));
            fn_80496EE4(x, x->p[i].a, x->p[i].b, x->p[i].a, x->p[i].b, w, 1, 1, -1);
        }
        x->e[i].m0 = 0;
        x->e[i].m4 = 0xFF;
        x->e[i].m8 = 0;
    }
}

FE_OVERLAY void fn_80495080(void* x)
{
    FeI(x, 0x1B0) = SumB5080((Fe5080Rec*)FeP(x, 0x1A8));
    int s0b = 0;
    Fe5080Rec* r0b = (Fe5080Rec*)FeP(x, 0x1A8);
    for (unsigned char i = 0; i < r0b->m3E4; i++) {
        s0b += (int)fn_80097F68(r0b, 0, i, 2, 0);
    }
    FeI(x, 0x1B4) = s0b;
    int s0c = 0;
    Fe5080Rec* r0c = (Fe5080Rec*)FeP(x, 0x1A8);
    for (unsigned char i = 0; i < r0c->m3E4; i++) {
        s0c += fn_80097A70(r0c, 1, i, 0);
    }
    FeI(x, 0x1B8) = s0c;
    FeI(x, 0x1BC) = SumB5080((Fe5080Rec*)FeP(x, 0x1AC));
    int s1b = 0;
    Fe5080Rec* r1b = (Fe5080Rec*)FeP(x, 0x1AC);
    for (unsigned char i = 0; i < r1b->m3E4; i++) {
        s1b += (int)fn_80097F68(r1b, 0, i, 2, 0);
    }
    FeI(x, 0x1C0) = s1b;
    int s1c = 0;
    Fe5080Rec* r1c = (Fe5080Rec*)FeP(x, 0x1AC);
    for (unsigned char i = 0; i < r1c->m3E4; i++) {
        s1c += fn_80097A70(r1c, 1, i, 0);
    }
    FeI(x, 0x1C4) = s1c;
}

/* near-miss: 95.1%, both byte-sum loops match; retail computes j*4 (slwi r0,r31,2) twice in the second half, ours shares one slwi (GCSE) */
FE_OVERLAY void fn_80495248(void* x)
{
    char buf[16];
    char* bb = (char*)x + 0x1A8;
    int s = SumB5080(*(Fe5080Rec**)(bb + FeI(x, 0x184) * 4));
    char* ww = (char*)x + 0x238;
    sprintf(buf, lbl_805F4ECC, s);
    ((FeWV*)*(void**)(ww + FeI(x, 0x184) * 4))->s30(buf);
    int j = FeI(x, 0x184) == 0;
    int s2 = SumB5080(*(Fe5080Rec**)(bb + j * 4));
    sprintf(buf, lbl_805F4ECC, s2);
    ((FeWV*)*(void**)(ww + j * 4))->s30(buf);
}

FE_OVERLAY void fn_8049535C(void* x)
{
    char buf[8];
    char* p = buf;
    sprintf(p, lbl_805F4ECC, *(unsigned char*)((char*)FeP(x, 0x1A4) + 0x1CC9));
    ((FeWQ*)fn_800C8040(FeMem(x, 0x1F0)->fn_vslot32(lbl_805F7060, 1)))->s30((int)p);
}

FE_OVERLAY void fn_80495AB4(void* x)
{
    FeWV* w = (FeWV*)fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 1));
    if (FeI(x, 0x338) != 0 && FeI(x, 0x344) == 0) {
        w->s101(0, 1);
    } else {
        w->s101(0, 0);
    }
    if (FeI(x, 0x344) != 0 && FeI(x, 0x350) == 0) {
        w->s101(1, 1);
    } else {
        w->s101(1, 0);
    }
    if (FeI(x, 0x350) != 0 && FeI(x, 0x35C) == 0) {
        w->s101(2, 1);
    } else {
        w->s101(2, 0);
    }
    if ((FeI(x, 0x338) != 0 && FeI(x, 0x344) != 0) || (FeI(x, 0x344) != 0 && FeI(x, 0x350) != 0) || (FeI(x, 0x338) != 0 && FeI(x, 0x350) != 0)) {
        w->s101(3, 1);
    } else {
        w->s101(3, 0);
    }
}

FE_OVERLAY void fn_80495CA4(void* x)
{
    int cur = FeI(x, 0x184);
    if (cur == FeI(x, 0x188)) {
        int flag = 0;
        FeW* w1 = FeMem(x, 0x1DC);
        char* bb = (char*)x + 0x1A8;
        int off = cur * 4;
        char* rec = *(char**)(bb + off);
        FeWV* w = (FeWV*)fn_800C8060(w1->fn_vslot32(lbl_805F6934, 1));
        int saved = ((FeW*)w)->fn_vslot60();
        w->s101(1, 0);
        w->s101(3, 0);
        w->s101(4, 0);
        w->s101(5, 0);
        w->s101(6, 0);
        w->s101(7, 0);
        unsigned char d = *(unsigned char*)(*(char**)(rec + 0x168) + *(int*)(rec + 0x174));
        if (d == *(unsigned char*)(rec + 0x17C)) {
            flag = fn_800971C8(rec, d) == 1;
        }
        int t26 = fn_8006BC74(FeI(x, 0x19C), FeI(x, 0x184));
        int t27 = fn_80099704(rec);
        if (flag == 0 || (t26 == 1 && t27 == 1)) {
            w->s101(6, 1);
        }
        volatile int sp8 = 0;
        int e = 0;
        do {
            char* a338 = (char*)x + 0x338;
            if (*(int*)(a338 + e * 12) != 0) {
                w->s101(1, 1);
                w->s101(3, 1);
                w->s101(4, 1);
                w->s101(5, 1);
                int q = fn_800968C0(rec, *(int*)(a338 + sp8 * 12), 1);
                int f2 = 0;
                if (q == *(unsigned char*)(rec + 0x17C)) {
                    f2 = fn_800971C8(rec, q) == 1;
                }
                if (f2 == 0 || (t26 == 1 && t27 == 1)) {
                    w->s101(7, 1);
                }
            }
            int c = sp8;
            int t;
            if (c > 3) {
                t = c;
            } else {
                t = c + 1;
            }
            sp8 = t;
            e = t;
        } while (e <= 2);
        if (*(int*)(rec + 0x108) != 0) {
            w->s101(6, 0);
            w->s101(7, 0);
            w->s101(8, 0);
        }
        if (FeW24(((FeW*)w)->fn_vslot73(saved, 0)) & 0x40000000) {
            ((FeWQ*)w)->s68(saved);
        } else {
            ((FeWQ*)w)->s68(0);
        }
    }
}

FE_OVERLAY void fn_80496088(void* x)
{
    if (FeI(x, 0x184) != FeI(x, 0x188)) {
        if (FeI(x, 0x164) > 0x63) {
            ((FeWV*)fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1)))->s101(2, 0);
        }
        char* bb = (char*)x + 0x1A8;
        int o1 = (FeI(x, 0x184) == 0) * 4;
        int a1 = fn_80099704(*(void**)(bb + o1));
        if (a1 == 0) {
            ((FeWV*)fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1)))->s101(3, 0);
        }
        int o2 = (FeI(x, 0x184) == 0) * 4;
        int a2 = fn_80099704(*(void**)(bb + o2));
        if (a2 == 0) {
            ((FeWV*)fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1)))->s101(4, 0);
        } else {
            ((FeWV*)fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1)))->s101(4, fn_8006BC74(FeI(x, 0x19C), FeI(x, 0x188)));
        }
        int o3 = (FeI(x, 0x184) == 0) * 4;
        char* r3 = *(char**)(bb + o3);
        if (*(int*)(r3 + 0x108) != 0) {
            ((FeWV*)fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1)))->s101(4, 0);
            ((FeWV*)fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1)))->s101(5, 0);
        }
    }
}

FE_OVERLAY void fn_80496560(void* x)
{
    int k = FeI(x, 0x184);
    if ((k == 0 && FeI(x, 0x140) == 0) || (k == 1 && FeI(x, 0x140) != 0)) {
        fn_8001BC4C()->fn_8001C190(0, FeI(x, 0x180), 0);
    } else {
        fn_8001BC4C()->fn_8001C190(2, FeI(x, 0x180), 0);
    }
}

FE_OVERLAY void fn_804965E0(void* x)
{
    int v = 0;
    if (*(int*)(*(char**)((char*)FeP(x, 0x19C) + 0x14) + 0x1CD0) != 0) {
        v = 1;
    }
    FeI(x, 0x184) = v;
    char* b = (char*)x + 0x240;
    (*(FeW**)(b + v * 4))->fn_vslot32(lbl_805F54A0, 1)->fn_vslot8(1);
    (*(FeW**)(b + FeI(x, 0x184) * 4))->fn_vslot32(lbl_805F54A8, 1)->fn_vslot8(0);
    int o1 = (FeI(x, 0x184) == 0) * 4;
    (*(FeW**)(b + o1))->fn_vslot32(lbl_805F54A0, 1)->fn_vslot8(0);
    int o2 = (FeI(x, 0x184) == 0) * 4;
    (*(FeW**)(b + o2))->fn_vslot32(lbl_805F54A8, 1)->fn_vslot8(1);
    FeW* w27 = fn_800C8040(FeMem(x, 0x1F0)->fn_vslot32(lbl_805F54A8, 1));
    FeW* w28 = fn_800C8040(FeMem(x, 0x1F0)->fn_vslot32(lbl_805F6808, 1));
    fn_80495CA4(x);
    if (FeI(x, 0x188) == FeI(x, 0x184)) {
        FeMem(x, 0x1DC)->fn_vslot8(1);
        FeMem(x, 0x1D8)->fn_vslot8(0);
    } else {
        FeMem(x, 0x1DC)->fn_vslot8(0);
        FeMem(x, 0x1D8)->fn_vslot8(1);
    }
    if ((unsigned)FeI(x, 0x188) <= 1) {
        int c = FeI(x, 0x184);
        if (c == 0) {
            int t = FeI(x, 0x258);
            fn_80496EE4(x, *(short*)((char*)w28 + 0x26), t, FeI(x, 0x254), t, w28, 0, 0, -1);
            int t2 = FeI(x, 0x260);
            fn_80496EE4(x, *(short*)((char*)w27 + 0x26), t2, FeI(x, 0x25C), t2, w27, 0, 0, -1);
        } else if (c == 1) {
            int t3 = FeI(x, 0x260);
            int dd = *(short*)((char*)w27 + 0x2A) - *(short*)((char*)w28 + 0x2A);
            fn_80496EE4(x, *(short*)((char*)w28 + 0x26), t3, FeI(x, 0x25C), t3, w28, 0, 0, -1);
            int t4 = FeI(x, 0x258);
            fn_80496EE4(x, *(short*)((char*)w27 + 0x26), t4, FeI(x, 0x254) - dd, t4, w27, 0, 0, -1);
        }
    }
    fn_8049693C((char*)x);
}

FE_OVERLAY void fn_8049693C(char* x)
{
    if (FeI(x, 0x188) != FeI(x, 0x184)) {
        char* b = x + 0x1A8;
        int o = FeI(x, 0x188) * 4;
        int id = *(int*)(b + o);
        if (fn_80096988((void*)id, (int)fn_80081B60__FP13Unk8007FF8C_Y(FeP(x, 0x1A4)), 0) == 1) {
            fn_804982C0(x);
        }
    }
}

/* near-miss: 99.x%, the first mulli index (fn_80353870 result * 0x34) lands in r0 where retail has r9 */
FE_OVERLAY void fn_804969A8(void* x)
{
    char big[1000];
    char small1[200];
    char small2[200];
    if (FeI(x, 0x13C) != 1) {
        int cur = FeI(x, 0x184);
        if (cur != FeI(x, 0x188)) {
            char* bb = (char*)x + 0x1A8;
            char* rec = *(char**)(bb + cur * 4);
            unsigned char c = *(unsigned char*)(rec + 0x17C);
            unsigned char d = *(unsigned char*)(*(char**)(rec + 0x168) + *(int*)(rec + 0x174));
            int r = fn_8008CFD8(rec + 0xC9C, 5, c);
            if (d == c && (r == 0 || r == 10)) {
                fn_80572710(*(int*)((char*)lbl_80619948 + 0x4C));
                char* rec2 = *(char**)(bb + FeI(x, 0x184) * 4);
                if (d != *(unsigned char*)(*(char**)(rec2 + 0x168) + *(int*)(rec2 + 0x174))) {
                    FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
                    char* r3 = *(char**)(bb + FeI(x, 0x184) * 4);
                    int t = fn_80353870__FP11Unk80353870(r3);
                    int o1 = t * 0x34;
                    char* tb = r3 + 0x3E8;
                    fn_800DE440(small1, *(int*)(tb + o1), 0);
                    int o2 = d * 0x34;
                    char* r4 = *(char**)(bb + FeI(x, 0x184) * 4);
                    char* tb2 = r4 + 0x3E8;
                    fn_800DE440(small2, *(int*)(tb2 + o2), 0);
                    ((void (*)(char*, const char*, ...))fn_80403DE4)(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4F9F), small1, small2);
                    fn_801321D4(p, x, (void (*)(int, void*))fn_804987E8, (int)fn_80529150, big, 1, -1, 1, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 0, 0);
                    p->fn_vslot86();
                }
            }
        }
    }
}

FE_OVERLAY int fn_804977FC(char* x)
{
    int i;
    for (i = 0; i < 8; i++) {
        char* b = x + 0x38C;
        int o = i * 0x44;
        if (*(int*)(b + o) != 0) {
            return 0;
        }
    }
    return 1;
}

FE_OVERLAY void fn_80497830(void* x, int a, int b)
{
    char s8[0x68];
    char s70[200];
    char* bb = (char*)x + 0x1A8;
    int off = FeI(x, 0x184) * 4;
    if (fn_800968C0(*(void**)(bb + off), a, 0) != 0xFF) {
        fn_800DE354__FiP8UdE354_Tiii(s70, FeI(x, 0x19C), FeI(x, 0x184), a, 3);
        sprintf(s8, lbl_805F7098, b);
        FeW* w30 = fn_800C8040(FeMem(x, 0x1EC)->fn_vslot29(s8));
        ((FeWV*)w30)->s28(s70);
        w30->fn_vslot8(1);
        sprintf(s8, lbl_805F67E0, b);
        FeW* w = fn_800C8044(FeMem(x, 0x1EC)->fn_vslot32(s8, 1));
        w->fn_vslot8(1);
        FeW* w31 = fn_800C8044(w->fn_vslot32(lbl_805F5340, 1));
        FeW* w29 = fn_800C8044(w->fn_vslot32(lbl_805F5338, 1));
        if (FeI(x, 0x184) == 0) {
            w31->fn_vslot8(1);
            w29->fn_vslot8(0);
            FeW* t = fn_800C8054(w31->fn_vslot32(lbl_805F70C8, 1));
            char* b5a8 = (char*)x + 0x5A8;
            int o5 = b * 4;
            *(FeW**)(b5a8 + o5) = t;
            char* bb2 = (char*)x + 0x1A8;
            int off2 = FeI(x, 0x184) * 4;
            ((FeSub*)((char*)t + 0x98))->s20(*(int*)(*(char**)(bb2 + off2) + 0x198), 0);
        } else {
            int o5 = b * 4;
            w31->fn_vslot8(0);
            w29->fn_vslot8(1);
            FeW* t1 = fn_800C8054(w29->fn_vslot32(lbl_805F70C8, 1));
            char* b5a8 = (char*)x + 0x5A8;
            *(FeW**)(b5a8 + o5) = t1;
            int off3 = FeI(x, 0x184) * 4;
            ((FeSub*)((char*)t1 + 0x98))->s20(*(int*)(*(char**)(bb + off3) + 0x198), 0);
            FeW* t2 = fn_800C8054(w29->fn_vslot32(lbl_805F70CC, 1));
            char* b5b8 = (char*)x + 0x5B8;
            *(FeW**)(b5b8 + o5) = t2;
            int off4 = FeI(x, 0x184) * 4;
            ((FeSub*)((char*)t2 + 0x98))->s20(*(int*)(*(char**)(bb + off4) + 0x198), 0);
        }
    }
}

FE_OVERLAY void fn_80497B74(char* x, int idx)
{
    int o = idx * 0x44;
    FeSt(x + 0x388, o, -1);
    FeSt(x + 0x38C, o, 0);
    FeSt(x + 0x390, o, 0);
    FeSt(x + 0x394, o, 0);
    FeSt(x + 0x398, o, 1);
    FeSt(x + 0x3A4, o, -1);
    FeSt(x + 0x3A8, o, -1);
    FeSt(x + 0x39C, o, -1);
    FeSt(x + 0x3A0, o, -1);
    FeSt(x + 0x3B0, o, -1);
    FeSt(x + 0x3AC, o, -1);
    FeSt(x + 0x3B4, o, 0);
    char* bf = x + 0x3B8;
    *(float*)(bf + o) = lbl_805F7110;
    FeSt(x + 0x3BC, o, 0);
    FeSt(x + 0x3C8, o, -1);
}

FE_OVERLAY void fn_80497C08(void* x, int a)
{
    switch (a) {
    case -1:
        break;
    case 0:
        fn_80495248(x);
        break;
    case 1:
        fn_8049535C(x);
        break;
    }
}

FE_OVERLAY void fn_80497C48(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_80498438((char*)x);
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F7114, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

FE_OVERLAY void fn_80497CD0(void* x, int a)
{
    volatile int sp8 = 0;
    int e = 0;
    do {
        char* bb = (char*)x + 0x1A8;
        char* s = *(char**)(bb + e * 4);
        unsigned char i = 0;
        unsigned char n = *(unsigned char*)(s + 0x3E4);
        while (i < n) {
            int k = fn_80097148(s, i);
            if (k == 1 || k == 3) {
                int c0 = sp8;
                char* p = (char*)x + 0x264;
                int off = i * 4 + c0 * 0x64;
                if (*(int*)(p + off) == 0) {
                    *(int*)(p + off) = 1;
                    if (a == 0) {
                        fn_80494108(x, k, i, c0);
                        if (FeI(x, 0x188) == sp8) {
                            switch (k) {
                            case 1:
                                fn_80497E00(x, i);
                                break;
                            case 3:
                                fn_804980E4(x, i);
                                break;
                            }
                        }
                    }
                }
            }
            i++;
        }
        int c = sp8;
        int t;
        if (c > 1) {
            t = c;
        } else {
            t = c + 1;
        }
        sp8 = t;
        e = t;
    } while (e <= 1);
}

FE_OVERLAY void fn_80497E00(void* x, int a)
{
    char n20[200];
    char s0E8[0x18];
    char s100[400];
    char s290[400];
    char s420[1000];
    FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    unsigned char b = a;
    char* bb = (char*)x + 0x1A8;
    int off = FeI(x, 0x188) * 4;
    char* rec = *(char**)(bb + off);
    int o2 = b * 0x34;
    char* tb = rec + 0x3E8;
    char* t = rec + 0xC9C;
    int v = *(int*)(tb + o2);
    int k1 = fn_8008CFD8(t, 0x1E, b);
    int k2 = fn_8008CFD8(t, 0x1F, b);
    void* tbl = lbl_8061977C;
    fn_800DE440(n20, v, 0);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(s0E8, fn_80090880__FP11Unk80090880(tbl, 0x3950), k2);
    const char* w1 = fn_80090880__FP11Unk80090880(tbl, 0x3458);
    fn_8040321C(s100, w1, n20, fn_80090880__FP11Unk80090880(tbl, fn_800E6058__Fi(k1)));
    fn_804031F8(s290, fn_80090880__FP11Unk80090880(tbl, 0x345B), s0E8);
    if (k1 != 0x31) {
        int c = fn_800A2AE8(lbl_80619948);
        if (k2 >= fn_8056B7D0(*(int*)((char*)lbl_80619948 + 0x28)) - c) {
            if (fn_800A2E6C(lbl_80619948) != 0) {
                fn_80403144(s290, fn_80090880__FP11Unk80090880(tbl, 0x5D13));
            } else {
                fn_80403144(s290, fn_80090880__FP11Unk80090880(tbl, 0x5D0D));
            }
        }
    }
    fn_8040321C(s420, fn_80090880__FP11Unk80090880(tbl, 0x345A), s100, s290);
    fn_800DFF0C((unsigned short*)s420, (unsigned short*)fn_80090880__FP11Unk80090880(tbl, 0x345D));
    ((Fe8620St*)fn_800B555C())->m628 = v;
    int cnt = *(int*)(rec + 0x108);
    if (cnt != 0) {
        const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3398);
        fn_801321D4(p, x, fn_80498620, (int)fn_80529150, s420, 1, -1, 1, s1, 0, 0, 0, 0, 0);
    } else {
        const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3398);
        const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3396);
        fn_801321D4(p, x, fn_80498620, (int)fn_80529150, s420, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    }
    p->fn_vslot86();
}

FE_OVERLAY void fn_804980E4(void* x, int a)
{
    char big[1000];
    char small[200];
    FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    int o2 = (unsigned char)a * 0x34;
    char* bb = (char*)x + 0x1A8;
    int off = FeI(x, 0x188) * 4;
    char* rec = *(char**)(bb + off);
    char* tb = rec + 0x3E8;
    int v = *(int*)(tb + o2);
    fn_800DE440(small, v, 0);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x414A), small);
    fn_800DFEAC(big, lbl_805F59CC);
    fn_800DFF0C((unsigned short*)big, (unsigned short*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x345D));
    ((Fe8620St*)fn_800B555C())->m628 = v;
    int cnt = *(int*)(rec + 0x108);
    if (cnt != 0) {
        const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3398);
        fn_801321D4(p, x, fn_80498620, (int)fn_80529150, big, 1, -1, 1, s1, 0, 0, 0, 0, 0);
    } else {
        const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3398);
        const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3396);
        fn_801321D4(p, x, fn_80498620, (int)fn_80529150, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    }
    *(int*)((char*)p + 0x2F0) = -0x63;
    fn_800C80C0(p, fn_800B555C()->m570);
    p->fn_vslot86();
}

FE_OVERLAY void fn_804982C0(void* x)
{
    FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    char* st = (char*)fn_800B555C() + 8;
    FeI(st, 0x620) = fn_80097210((void*)((FeScrB*)x)->m1A8[FeI(x, 0x184)], 0);
    fn_80131F34(p, x, (void (*)(int, void*))fn_804987C0, (int)fn_80529150, 0x37A1, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_804983A8(void) {}

FE_OVERLAY void fn_804983AC(void* x)
{
    FeI(x, 0x32C) = FeI(fn_800B555C(), 0x634);
    FeI(fn_800B555C(), 0x634) = 0;
    short* p = (short*)FeP(x, 0x32C);
    if (p == 0) {
        short* a = (short*)fn_803774A8(0x4E22, FeI(FeGetMgr(), 0x38) | 0x100);
        *a = 0;
        FeP(x, 0x32C) = a;
    }
}

FE_OVERLAY void fn_80498438(char* x)
{
    if (*(void**)(x + 0x32C) != 0) {
        fn_80377488(*(void**)(x + 0x32C));
        *(int*)(x + 0x32C) = 0;
    }
}

FE_OVERLAY int fn_80498478(void* x)
{
    unsigned char v = 0;
    char* bb = (char*)x + 0x1A8;
    int off = FeI(x, 0x188) * 4;
    Fe498478Rec* r = *(Fe498478Rec**)(bb + off);
    int n0 = r->s[0].n;
    int n1 = r->s[1].n;
    int n2 = r->s[2].n;
    int n3 = r->s[3].n;
    int n4 = r->s[4].n;
    int c1 = n0 + n1;
    int c2 = c1 + n2;
    int c3 = c2 + n3;
    int c4 = c3 + n4;
    int i = FeMem(x, 0x21C)->fn_vslot60() - 1;
    if (i < n0) {
        v = r->s[0].p[(unsigned char)i];
    } else if (i < c1) {
        v = r->s[1].p[(unsigned char)(i - n0)];
    } else if (i < c2) {
        v = r->s[2].p[(unsigned char)(i - n0 - n1)];
    } else if (i < c3) {
        v = r->s[3].p[(unsigned char)(i - n0 - n1 - n2)];
    } else if (i < c4) {
        v = r->s[4].p[(unsigned char)(i - n0 - n1 - n2 - n3)];
    }
    return r->e[v].m0;
}

FE_OVERLAY void fn_80498580(void) {}

FE_OVERLAY void fn_80498584(void)
{
    char buf[0xA0];
}

FE_OVERLAY void fn_80498590(int a, void* x)
{
    if (a == 1) {
        FeMsg m;
        FeMsg* p = &m;
        fn_80498438((char*)x);
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F5ABC, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, 0);
    }
}

FE_OVERLAY void fn_80498620(int mode, void* x)
{
    int cur = ((Fe8620St*)fn_800B555C())->m628;
    char* bb = (char*)x + 0x1A8;
    int off = FeI(x, 0x188) * 4;
    void* t = *(void**)(bb + off);
    int a = fn_800968C0(t, cur, 1);
    int b = fn_80097520(t, cur);
    switch (mode) {
    case 1:
        if (b == 1) {
            fn_804920B8(x, 1);
            ((Fe8620St*)fn_800B555C())->m628 = 0;
        } else {
            ((Fe8620St*)fn_800B555C())->m634 = FeI(x, 0x32C);
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            strncpy(mp->name, lbl_805F69BC, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
        break;
    case 0:
        if (b == 1) {
            int v = 0;
            if (*(int*)(*(char**)((char*)FeP(x, 0x19C) + 0x14) + 0x1CD0) != 0) {
                v = 1;
            }
            if (v == FeI(x, 0x188)) {
                fn_80572710(*(int*)((char*)lbl_80619948 + 0x4C));
            } else {
                fn_80572CB0(*(int*)((char*)lbl_80619948 + 0x4C));
            }
        } else {
            int r = fn_80097238(t, a);
            fn_80571F4C(*(int*)((char*)lbl_80619948 + 0x4C), FeI(x, 0x188), r);
        }
        ((Fe8620St*)fn_800B555C())->m628 = 0;
        fn_80492680(x, 0, 0, 0);
        break;
    }
}

FE_OVERLAY void fn_804987C0(void* a, void* b)
{
    fn_804920B8(b, 1);
}

FE_OVERLAY void fn_804987E8(void) {}

}
