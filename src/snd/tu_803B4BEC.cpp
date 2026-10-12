/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B4BEC-0x803B6AF8 (code-only unit, 46 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/cmn/sndcmn.h"

extern SNDPACKETSTATE lbl_806AA500;

struct Unk803B5E44_Sub {
    int (*m0)(Unk803B5E44_Sub*, int, float*, float*, int);
};

struct Unk803B5E44 {
    void* m0;
    int m4;
    Unk803B5E44_Sub* m8;
    int mC;
    int m10;
    int m14;
    char pad18[2];
    unsigned char m1A;
    char pad1B;
    float m1C[12];
};

extern "C" int fn_803B5E44(Unk803B5E44* o, int a, float* b, float* c);
extern "C" int fn_803B6514(Unk803B5E44* o, int a, float* b, float* c);
extern "C" void fn_803B6428(float* p);
extern "C" int fn_803B66D4(void* o);
extern "C" int fn_803B9794(void* o);
extern "C" void fn_803B6C08();
extern "C" void fn_803B6D0C();
extern "C" void fn_803B7534();
extern "C" void fn_803B6E14();
extern "C" void fn_803B7374();
extern "C" void fn_803B7010();
extern "C" void fn_803B7670();
extern "C" void fn_803B79BC();
extern "C" void fn_803B7C78();
extern float lbl_80609BA0;
extern float lbl_80609BF4;
extern int lbl_806AA2D4[];


struct Unk806AA88C_Entry {
    unsigned int m0;
    unsigned int m4;
};

struct Unk806AA88C {
    unsigned short m0;
    short m2;
    unsigned int m4;
    unsigned int m8;
    Unk806AA88C_Entry* mC;
};

struct Unk803B5F9C {
    char pad0[8];
    Unk803B5F9C* m8;
    char padC[4];
    Unk803B5F9C* m10;
    char pad14[4];
    unsigned short m18;
};
extern Unk806AA88C lbl_806AA88C;
extern int lbl_806AA884;
extern int lbl_806AA888;
extern int lbl_80626518;
extern float lbl_80609B98;

extern "C" void fn_803A975C();
extern "C" void fn_803A979C();
extern "C" int fn_803B0360();
extern "C" void fn_803B0714(int h);

extern "C" int fn_803B4BEC(int voice)
{
    int i;
    for (i = 0; i < sndgs.sso.set.maxstreams; i++) {
        SNDPACKETCHAN* p = lbl_806AA500.ppc[i];
        if (p != 0 && SNDVOICEI_get(p->shandle) == voice)
            return i;
    }
    return -1;
}

extern "C" int fn_803B4C74(int chan, int n)
{
    int i;
    int best = -1;
    int idx = -1;
    for (i = 0; i < n; i++) {
        int v = sndgs.chan[chan].voices[i];
        if (v > best) {
            best = v;
            idx = i;
        }
    }
    return idx;
}

extern "C" int fn_803B4CC8(int n)
{
    return (n << 5) + 0x9c;
}

extern "C" int fn_803B4CD4(int n)
{
    int a = fn_803B4CC8(n);
    return a + fn_803B0360();
}

extern "C" int fn_803B537C(int h)
{
    SNDPACKETCHAN* p = lbl_806AA500.ppc[h];
    int max = 0;
    int i;
    for (i = 0; i < p->sampleformat.channels; i++) {
        if (p->outstandingpackets[i] >= max)
            max = p->outstandingpackets[i];
    }
    return p->maxpackets - max - 1;
}

extern "C" unsigned int fn_803B53DC(int h)
{
    SNDPACKETCHAN* p = lbl_806AA500.ppc[h];
    return p->outstandingframes + p->outstandingplatformframes;
}

extern "C" int fn_803B5400()
{
    return -15;
}

extern "C" int fn_803B54A8(int h)
{
    fn_803A975C();
    fn_803B0714(h);
    lbl_806AA500.ppc[h] = 0;
    fn_803A979C();
    return 0;
}

extern "C" void fn_803B5738(int h, int chan, int frames)
{
    SNDPACKETCHAN* p = lbl_806AA500.ppc[h];
    if (chan != p->masterpacketchan)
        return;
    p->outstandingplatformframes -= frames;
    if (p->pframesfunc == 0)
        return;
    SNDIPACKETCALLBACK* e = lbl_806AA500.spcb + lbl_806AA500.callbackindex;
    e->type = 0;
    e->chan = h;
    e->u.frames = frames;
    lbl_806AA500.callbackindex++;
}

void Snd::Util::ReallocBuf(void** buffer, int* curSize, int newMinSize, int sizeofDataType)
{
    int cur = *curSize;
    if (cur < newMinSize) {
        if (cur == 0) {
            *curSize = newMinSize;
        } else if (cur < newMinSize) {
            int n = cur;
            do {
                n += n;
            } while (n < newMinSize);
            *curSize = n;
        }
        void* ob = *buffer;
        void* nb = SNDMEMI_allocz(*curSize * sizeofDataType);
        if (ob != 0) {
            Snd::Util::MemCpy(nb, ob, cur * sizeofDataType);
            SNDMEMI_free(ob);
        }
        *buffer = nb;
    }
}

extern "C" int fn_803B59A4(int range)
{
    if (range > 0x10000)
        range = 0x10000;
    else if (range < 0)
        range = 0;
    int r = (int)(iSNDrandom() & 0x7FFF) - 0x4000;
    return (r * range) >> 14;
}

extern "C" void fn_803B5A00(int v)
{
    lbl_806AA884 = v;
}

extern "C" void fn_803B5A0C(int v)
{
    lbl_806AA888 = v;
}

extern "C" int fn_803B5A18(int v)
{
    lbl_80626518 = v;
    return 0;
}

extern "C" void fn_803B5A28(int n)
{
    fn_803A975C();
    lbl_806AA88C.mC = (Unk806AA88C_Entry*)SNDMEMI_allocz(n * 8);
    fn_803A979C();
    lbl_806AA88C.m2 = n;
    lbl_806AA88C.m0 = 0;
}

extern "C" void fn_803B5A78(unsigned int a, unsigned int b)
{
    lbl_806AA88C.m8 = (a + b) & ~4;
    if (a <= 0x1f)
        a = 0x20;
    lbl_806AA88C.m4 = a;
    if ((a & 0x1f) != 0)
        lbl_806AA88C.m4 = (a + 0x1f) & ~0x1f;
    lbl_806AA88C.m4 = lbl_806AA88C.m4 >> 5;
    lbl_806AA88C.m8 = lbl_806AA88C.m8 >> 5;
}

extern "C" void fn_803B5ACC()
{
    if (lbl_806AA88C.mC != 0) {
        fn_803A975C();
        SNDMEMI_free(lbl_806AA88C.mC);
        fn_803A979C();
        lbl_806AA88C.mC = 0;
    }
}

extern "C" void fn_803B5B1C(unsigned int* a, unsigned int* b)
{
    unsigned int x = *a;
    unsigned int lo = lbl_806AA88C.m4;
    if (x < lo) {
        *a = lo;
        *b = *b - (lo - x);
    }
    if (*a + *b > lbl_806AA88C.m8)
        *b = lbl_806AA88C.m8 - *a;
}

extern "C" void fn_803B5D30(unsigned int addr)
{
    unsigned int key = addr >> 5;
    int i;
    for (i = 0; i < lbl_806AA88C.m0; i++) {
        if (*(unsigned int*)((char*)lbl_806AA88C.mC + (i << 3)) == key) {
            lbl_806AA88C.m0--;
            for (; i < lbl_806AA88C.m0; i++)
                lbl_806AA88C.mC[i] = lbl_806AA88C.mC[i + 1];
            return;
        }
    }
}

extern "C" int fn_803B5DCC(int unused, int n, float* in, int* out);

extern "C" int fn_803B5DCC(int unused, int n, float* in, int* out)
{
    int i;
    for (i = 0; i < n; i++) {
        int v = (int)in[i];
        int r;
        if (v < -0x7fff)
            r = -0x7fff;
        else if (v > 0x7fff)
            r = 0x7fff;
        else
            r = v;
        out[i] = r;
    }
    return n;
}

struct Unk803B5E2C {
    void* m0;
    int m4;
};

extern "C" void fn_803B5E2C(Unk803B5E2C* o)
{
    o->m4 = 0;
    o->m0 = (void*)fn_803B5DCC;
}

extern "C" void fn_803B6454(float* st, int n, float* in, float* out);

extern "C" int fn_803B5E44(Unk803B5E44* o, int a, float* in, float* out)
{
    int n;
    Unk803B5E44_Sub* s = o->m8;
    if (s != 0) {
        n = s->m0(s, a, out, in, o->m1A);
        if (n <= 0)
            return n;
    } else {
        n = a;
    }
    fn_803B6454(o->m1C, n, in, out);
    return n;
}

struct Unk803B5EC4 {
    void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    char pad18[3];
    char m1B;
    float m1C[8];
};

extern "C" int fn_803B5EC4(Unk803B5EC4* o)
{
    o->m8 = 0;
    o->mC = 0;
    o->m10 = 0;
    o->m14 = 0;
    o->m1B = 0;
    o->m4 = 0;
    o->m0 = (void*)fn_803B5E44;
    fn_803B6428(o->m1C);
    return 0;
}

extern "C" void fn_803B5F9C(Unk803B5F9C** head, Unk803B5F9C* n)
{
    Unk803B5F9C* cur = *head;
    Unk803B5F9C* prev = 0;
    if (cur != 0 && cur->m18 < n->m18) {
        do {
            prev = cur;
            cur = prev->m8;
        } while (cur != 0 && cur->m18 < n->m18);
    }
    n->m8 = cur;
    if (cur != 0)
        cur->m10 = n;
    if (prev == 0) {
        *head = n;
        return;
    }
    prev->m8 = n;
    n->m10 = prev;
}

extern "C" void fn_803B6004(Unk803B5F9C** head, Unk803B5F9C* n)
{
    Unk803B5F9C* p = *head;
    if (n == p) {
        *head = p->m8;
        return;
    }
    Unk803B5F9C* q = p->m8;
    if (q == 0)
        return;
    while (q != n) {
        p = q;
        q = p->m8;
        if (q == 0)
            return;
    }
    if (q != 0 && q == n) {
        if (n->m8 != 0)
            n->m8->m10 = p;
        p->m8 = p->m8->m8;
    }
}

extern "C" void fn_803B6428(float* p)
{
    float z = lbl_80609B98;
    p[0] = z;
    p[1] = z;
    p[2] = z;
    p[3] = z;
    p[4] = z;
    p[5] = z;
    p[6] = z;
    p[7] = z;
}

extern "C" int fn_803B6514(Unk803B5E44* o, int n, float* in, float* out)
{
    Unk803B5E44_Sub* s = o->m8;
    if (s != 0) {
        int r = s->m0(s, n, out, in, o->m1A);
        if (r <= 0)
            return r;
    }
    float* st = o->m1C;
    int i;
    for (i = 0; i < n; i++) {
        st[0] = st[0] * st[1] + st[2] * in[i];
        out[i] = st[0];
    }
    return n;
}

extern "C" int fn_803B65BC(Unk803B5EC4* o)
{
    o->m1C[0] = lbl_80609BA0;
    o->m4 = 0;
    o->m0 = (void*)fn_803B6514;
    o->m8 = 0;
    o->mC = 0;
    o->m10 = 0;
    o->m14 = 0;
    o->m1B = 0;
    return 0;
}

struct Unk803B66CC {
    char pad[0x1C];
    int m1C;
};

extern "C" void fn_803B66CC(Unk803B66CC* p, int v)
{
    p->m1C = v;
}

struct Unk803B69AC {
    void* m0;
    int m4;
    char pad8[0x18];
    int m20;
    void* m24;
    short m28;
    short m2A;
    float m2C[4];
};

extern "C" void fn_803B69AC(Unk803B69AC* o, int a, int flag)
{
    o->m0 = (void*)fn_803B66D4;
    o->m4 = 0;
    o->m20 = 0;
    o->m28 = 0;
    o->m2A = 0;
    if (flag == 0)
        o->m24 = (void*)fn_803B9794;
    int i;
    for (i = 0; i < 4; i++)
        o->m2C[i] = lbl_80609BF4;
}

extern "C" void fn_803B6A08()
{
    lbl_806AA2D4[0x18 / 4] = (int)fn_803B6C08;
    lbl_806AA2D4[0x60 / 4] = 0x2c;
    lbl_806AA2D4[0x1c / 4] = (int)fn_803B6D0C;
    lbl_806AA2D4[0x64 / 4] = 0x30;
    lbl_806AA2D4[0x20 / 4] = (int)fn_803B7534;
    lbl_806AA2D4[0x68 / 4] = 0x34;
}

extern "C" void fn_803B6A50()
{
    lbl_806AA2D4[0x30 / 4] = (int)fn_803B6E14;
    lbl_806AA2D4[0x78 / 4] = 0x2c;
    lbl_806AA2D4[0x38 / 4] = (int)fn_803B7374;
    lbl_806AA2D4[0x80 / 4] = 0x3c;
    lbl_806AA2D4[0x34 / 4] = (int)fn_803B7010;
    lbl_806AA2D4[0x7c / 4] = 0x30;
    lbl_806AA2D4[0x88 / 4] = 0x30;
    lbl_806AA2D4[0x84 / 4] = 0x2c;
    lbl_806AA2D4[0x44 / 4] = (int)fn_803B7374;
    lbl_806AA2D4[0x8c / 4] = 0x3c;
    lbl_806AA2D4[0x40 / 4] = (int)fn_803B7010;
    lbl_806AA2D4[0x3c / 4] = (int)fn_803B6E14;
}

extern "C" void fn_803B6AB0()
{
    lbl_806AA2D4[0x24 / 4] = (int)fn_803B7670;
    lbl_806AA2D4[0x6c / 4] = 0x2c;
    lbl_806AA2D4[0x70 / 4] = 0x54;
    lbl_806AA2D4[0x28 / 4] = (int)fn_803B79BC;
    lbl_806AA2D4[0x2c / 4] = (int)fn_803B7C78;
    lbl_806AA2D4[0x74 / 4] = 0x3c;
}
