/*
 * Game code, .text 0x802B9218-0x802BB4BC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802B9218.h"
#include "game/tu_8000E618.h"

extern int lbl_8061EAE0;
extern int lbl_8061E978;
extern Unk802BA828* lbl_8061EAE4;
void* operator new(unsigned int n, int heap);
float fn_801A0744(int a);
extern int lbl_8061EAB4;
extern int lbl_8061EAB8;
extern int lbl_8061EABC;
extern int lbl_8061EAC0;
extern int lbl_8061EAC4;
extern int lbl_8061EAC8;
extern int lbl_8061EACC;
extern int lbl_8061EAD0;
extern int lbl_8061EAD4;
extern int lbl_8061EAD8;
extern int lbl_8061EADC;
extern Unk8068B4F8 lbl_8068B4F8;

void fn_803EDA0C(int p);
Unk8000E618* fn_8000E65C();
void* fn_8040B190(void* dst, const void* src, ...);
void fn_803ED95C(int a);
void fn_803ED8EC(int a);
int fn_803ED9D4();
int fn_803ED720(int a, const char* b, int c, int d, int e, int f, int g, int h, int i, int j);
extern const char lbl_805E10B8[];
extern const char lbl_805E0F5C[];
extern const char lbl_805E0F68[];
void fn_8033E958(const char* fmt, ...);
void fn_8033E7A4();
int fn_803FC410(int a, const char* name, int b, int* c, void* d);
int fn_804017D0(int a);
int fn_803ED604(const char* name, int a, int b);
int fn_803EE310(int a);
void fn_803FFA60(int a, int b);
int fn_803FBD28(int a, int b, int c);
int fn_803FB954(int a);
int fn_803FB9E8(int a);
int fn_803FBF10(int a, int b);
int fn_803FC190(int a, int b);
int fn_803FC2E0(int a, int b, int c);
int fn_803FC034(int a);
void fn_803FB64C();
void fn_802B9EFC(Unk8068B4F8* p, int v);
void* fn_802B9CCC(int a, int* b, int c);
void fn_802B9ED4(int a);
int fn_803F9C58(int a, int b, int c, int d);
void fn_803F99E8(int h);
int fn_803F9A80(int h);
int fn_803F9E90(int a, int b, int c);
void* fn_803774A8(unsigned n, int heap);
int fn_803F9D74(int a, int b, void* c, int d, int e, int f);
void fn_803FEC9C(int a, int b);
void fn_80377488(void* p);
int fn_8000446C(int a, int b);
void fn_804017B0(int a, int b);
int fn_80401904(int a);
void fn_80433004(void* p, int n);
int fn_803EBFF8(void* p);
int fn_803EC3D4(void* p);
void fn_8040B61C(void* dst, int src);
int fn_803EBD14(void* a, int b);
void* fn_803EBF90(void* p);
int fn_8040B574(const char* a, const char* b);
void fn_802B0638(int a, void* b, int c);
int fn_803EC418(void* a, int x, int y, int z);
void fn_803ECA70(void* a, int x, int y, int z, unsigned v);

void fn_802B9218()
{
    fn_803EDA0C(lbl_8061EAE0);
    lbl_8061EAE0 = 0;
}

int fn_802B9250(int a, int b, int c)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FBD28(a, b, c);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

/* near-miss: 123 insns as retail; sp14/sp18 stack slots swapped (retail &sp18 = sp+0x18, &sp14 = sp+0x14) and name/result
   callee-saved registers swapped (name r28, result r29 in retail). Declaration and init order of the five locals do not change it. */
extern "C" const char* fn_802B9300(const char* name, int size, int kind, unsigned int* outn)
{
    int sp8;
    int spC;
    int sp10;
    int sp14;
    int sp18;
    int r = 0;
    int h;
    sp10 = 0;
    sp18 = 0;
    sp14 = 0;
    sp8 = 0;
    spC = 0;
    fn_8033E958(lbl_805E0F5C, name);
    fn_802B9D7C(kind, &sp8, &spC);
    switch (spC) {
    case 0:
        break;
    case 1:
        if (sp8 != 0) {
            fn_803FC410(sp8, name, 0, &sp10, outn);
            r = sp8 + sp10;
            break;
        }
        goto L_default;
    case 2:
        if (sp8 != 0) {
            fn_803FC410(sp8, name, 0, &sp10, &sp18);
            int a = sp8 + sp10;
            int n = fn_804017D0(a);
            if (n != 0) {
                if (outn != 0) {
                    *outn = n;
                }
                h = fn_803ED604(name, n, size);
                fn_804017B0(a, h);
            } else {
                if (outn != 0) {
                    *outn = sp18;
                }
                h = fn_803ED604(name, sp18, size);
                fn_803FFA60(a, sp18);
            }
            r = h;
            break;
        }
    L_default:
        r = (int)fn_802B9CCC((int)name, &sp14, size);
        if (outn != 0) {
            *outn = sp14;
        }
        break;
    case 3:
        r = (int)fn_802B9CCC((int)name, &sp14, size);
        if (r != 0) {
            if (outn != 0) {
                *outn = fn_803EE310(r);
            }
        } else if (outn != 0) {
            *outn = r;
        }
        break;
    }
    if (r == 0) {
        fn_8033E958(lbl_805E0F68);
    }
    fn_8033E7A4();
    return (const char*)r;
}

extern "C" void fn_802B961C(const char* p, int x)
{
    int obj = (int)p;
    int sp8 = 0;
    int spC = 0;
    fn_802B9D7C(x, &sp8, &spC);
    switch (spC) {
    case 0:
        break;
    case 1:
        if (sp8 != 0) {
            break;
        }
    case 2:
        fn_803EDA0C(obj);
        break;
    case 3:
        fn_803EDA0C(obj);
        break;
    }
}

void fn_802B96A4()
{
    fn_803FB64C();
}

int fn_802B96C4(int a)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FB954(a);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

int fn_802B9764(int a)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FB9E8(a);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

int fn_802B9804(int a, int b)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FBF10(a, b);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

int fn_802B98AC(int a, int b)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FC190(a, b);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

int fn_802B9954(int a, int b, int c)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FC2E0(a, b, c);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

int fn_802B9A04(int a)
{
    int r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_803FC034(a);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

void* fn_802B9AA4(int a, int* b, int c)
{
    int h = fn_803F9C58(a, 0x21, 0, 0);
    fn_803F99E8(h);
    int s = fn_803F9A80(h);
    h = fn_803F9E90(s, 0, 0);
    fn_803F99E8(h);
    *b = fn_803F9A80(h);
    void* p = fn_803774A8(*b, c | 0x400);
    h = fn_803F9D74(s, 0, p, *b, 0, 0);
    fn_803F99E8(h);
    fn_803F9A80(h);
    fn_803FEC9C(s, 0);
    return p;
}

void* fn_802B9B60(int a, int* b, int c)
{
    int h = fn_803F9C58(a, 0x21, 0, 0);
    fn_803F99E8(h);
    int s = fn_803F9A80(h);
    h = fn_803F9E90(s, 0, 0);
    fn_803F99E8(h);
    *b = fn_803F9A80(h);
    void* p = fn_803774A8(*b, c);
    h = fn_803F9D74(s, 0, p, *b, 0, 0);
    fn_803F99E8(h);
    fn_803F9A80(h);
    fn_803FEC9C(s, 0);
    return p;
}

void* fn_802B9C1C(int a, int* b, int c)
{
    void* r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_802B9B60(a, b, c);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

void* fn_802B9CCC(int a, int* b, int c)
{
    void* r;
    int tries = 1;
    do {
        fn_802B9EFC(&lbl_8068B4F8, 0);
        r = fn_802B9AA4(a, b, c);
    } while (lbl_8068B4F8.Get() != 0 && --tries > 0);
    if (lbl_8068B4F8.Get() != 0) {
        fn_802B9ED4(a);
        return 0;
    }
    return r;
}

void fn_802B9D7C(int kind, int* a, int* b)
{
    switch (kind) {
    case 0:
        break;
    case 1:
        *a = lbl_8061EAB4;
        *b = kind;
        break;
    case 2:
        *a = lbl_8061EAB8;
        *b = 1;
        break;
    case 3:
        *b = 2;
        break;
    case 4:
        *a = lbl_8061EABC;
        *b = 2;
        break;
    case 5:
        *a = lbl_8061EAC0;
        *b = 2;
        break;
    case 6:
        *a = lbl_8061EAC8;
        *b = 2;
        break;
    case 7:
        *a = lbl_8061EAC4;
        *b = 2;
        break;
    case 8:
        *a = lbl_8061EACC;
        *b = 2;
        break;
    case 9:
        *a = lbl_8061EAD0;
        *b = 2;
        break;
    case 10:
        *a = lbl_8061EAD4;
        *b = 1;
        break;
    case 11:
        *a = lbl_8061EAD8;
        *b = 1;
        break;
    case 12:
        *a = lbl_8061EADC;
        *b = 1;
        break;
    case 13:
        *a = lbl_8061EAE0;
        *b = 1;
        break;
    case 14:
        *a = 0;
        *b = 3;
        break;
    }
}

/* needs fn_8000446C(int, int) (r3 = 1, r4 = 0 set here); tu_800042B0.cpp defines it with no parameters, so the call
   relocates against a different mangled name until that definition gets its two parameters. */
void fn_802B9ED4(int)
{
    fn_8000446C(1, 0);
}

void fn_802B9EFC(Unk8068B4F8* p, int v)
{
    fn_80400828(p->m4);
    p->m0 = v;
    fn_8040084C(p->m4);
}

/* near-miss (7 slots): retail keeps p live and forms the second loop pointer in r11 (addi r11,r3,0x1ef0); ours reuses r3.
   Pointer, index and p->a[i] loop forms and all 120 store orders of the second loop tried. */
void fn_802B9F40(Unk802B9F40* p)
{
    p->m2354 = 0;
    p->m2350 = 0;
    for (int i = 0; i < 0x84; i++) {
        p->a0[i].m38 = 0;
        p->a0[i].m0 = 0;
        p->a0[i].m4 = 0;
        p->a0[i].m8 = 0;
    }
    for (int j = 0; j < 0x14; j++) {
        p->a1EF0[j].m0 = -1;
        p->a1EF0[j].m2C = 0;
        p->a1EF0[j].m4 = 0;
        p->a1EF0[j].m8 = 0;
        p->a1EF0[j].m28 = 0;
    }
}

unsigned fn_802B9FA8(unsigned x)
{
    if (x & 0x8000) {
        return ((x << 9) & 0x00F80000) | 0xFF000000u | ((x << 6) & 0x0000F800) | ((x & 0x1F) << 3);
    }
    return ((x << 17) & 0xE0000000) | ((x << 12) & 0x00F00000) | ((x << 8) & 0x0000F000) | ((x & 0xF) << 4);
}

/* near-miss (4 slots): retail has the palette base in r11 and the index*2 in r9 (add r9,r3,r3; lhzx r3,r9,r11); ours r9/r0. */
void fn_802B9FF0(void* a, Unk802B9FF0_Hdr* b)
{
    int cnt = b->m8;
    if (cnt > 0) {
        int* pp = &b->m14;
        for (int n = cnt; n != 0; n--) {
            char* e = (char*)b + *pp;
            pp += 2;
            void* tex = (void*)fn_803EBD14(a, fn_803EC3D4(e));
            int w = *(short*)(e + 4);
            int h = *(short*)(e + 6);
            Unk802B9FF0_Pal* pal = (Unk802B9FF0_Pal*)fn_803EBF90(e);
            for (int x = 0; x < w; x++) {
                for (int y = 0; y < h; y++) {
                    int idx = fn_803EC418(e, x, y, 0);
                    unsigned short* tab;
                    if (pal->mC & 0x10000000) {
                        tab = (unsigned short*)((char*)pal + pal->m10);
                    } else {
                        tab = (unsigned short*)((char*)pal + 0x10);
                    }
                    unsigned c = fn_802B9FA8(tab[idx]) & 0xFFFFFF;
                    unsigned o = fn_803EC418(tex, x, y, 0) & 0xFF000000;
                    fn_803ECA70(tex, x, y, 0, c | o);
                }
            }
        }
    }
}

void fn_802BA110(void* a, Unk802BA110_Src* b)
{
    fn_804017B0(b->m4, (int)a);
    void* buf = fn_803774A8(fn_80401904(b->m0), 0x100);
    fn_804017B0(b->m0, (int)buf);
    fn_802B9FF0(a, (Unk802B9FF0_Hdr*)buf);
    delete[] (char*)buf;
    fn_80433004(a, 0x19260);
}

void fn_802BA194(Unk802B9F40* p, Unk802B9FF0_Hdr* h)
{
    if (fn_803EBFF8((char*)h + h->m14) == 0) {
        int n = h->m8;
        int i;
        if (n > 0) {
            char* d = (char*)p + 0x12;
            int* s = &h->m14;
            for (i = n; i != 0; i--) {
                fn_8040B61C(d, fn_803EC3D4((char*)h + *s));
                s += 2;
                d += 5;
            }
        }
        p->a0[0].m38 = n;
    }
}

void fn_802BA218(Unk802B9F40* p)
{
    int off = 0;
    for (int i = 0; i < 0x14; i++) {
        char* base = (char*)p + 0x1F18;
        *(void**)(base + off) = fn_803774A8(0x19260, 0x400);
        off += 0x38;
    }
    p->m2354 = 1;
}

void fn_802BA274(Unk802B9F40* t, Unk802B9F40_A0* s, const void* a1, int n1, const void* a2, int n2)
{
    if (fn_802BA45C(t, s)) {
        s->m0 = fn_803774A8(n1, fn_8000E65C()->fn_8000E6F0());
        s->m4 = fn_803774A8(n2, fn_8000E65C()->fn_8000E6F0());
    }
    fn_8040B190(s->m0, a1, n1);
    fn_8040B190(s->m4, a2, n2);
}

int fn_802BA45C(Unk802B9F40*, Unk802B9F40_A0* s)
{
    return s->m0 == 0 && s->m4 == 0;
}

Unk802B9F40_A0* fn_802BA47C(Unk802B9F40* t)
{
    int s = (int)t;
    int last = s + 0x1EB4;
    do {
        if (!fn_802BA45C(t, (Unk802B9F40_A0*)s)) {
            s += 0x3C;
            continue;
        }
        return (Unk802B9F40_A0*)s;
    } while (s <= last);
    return 0;
}

Unk802B9F40_A1EF0* fn_802BA4D8(Unk802B9F40* t, int key)
{
    for (int i = 0; i < 0x14; i++) {
        Unk802B9F40_A1EF0* s = &t->a1EF0[i];
        if (s->m0 != -1) {
            int cnt = s->m8;
            for (int j = 0; j < cnt; j++) {
                if (s->mC[j] == key) {
                    return s;
                }
            }
        }
    }
    return 0;
}

void fn_802BA540(Unk802B9F40_A1EF0* s, int v)
{
    s->mC[s->m8++] = v;
}

Unk802B9F40_A0* fn_802BA55C(Unk802B9F40* t, const char* name)
{
    int s = (int)t;
    int last = s + 0x1EB4;
    do {
        Unk802B9F40_A0* e = (Unk802B9F40_A0*)s;
        if (!fn_802BA45C(t, e)) {
            int n = e->m38;
            for (int i = 0; i < n; i++) {
                if (fn_8040B574(e->m12 + i * 5, name) == 0) {
                    return e;
                }
            }
        }
        s += 0x3C;
    } while (s <= last);
    return 0;
}

Unk802B9F40_A1EF0* fn_802BA5F4(Unk802B9F40* t)
{
    Unk802B9F40_A1EF0* best = 0;
    for (int i = 0; i < 0x14; i++) {
        Unk802B9F40_A1EF0* s = &t->a1EF0[i];
        if (s->m0 != -1) {
            if (best == 0 || s->m4 < best->m4) {
                best = s;
            }
        } else {
            fn_802BA67C(t, s);
            return s;
        }
    }
    fn_802BA67C(t, best);
    return best;
}

void fn_802BA67C(Unk802B9F40* t, Unk802B9F40_A1EF0* s)
{
    if (s->m0 != -1) {
        fn_802B0638(lbl_8061E978, &s->m2C, 0);
    }
    s->m0 = -1;
    s->m8 = 0;
    s->m2C = 0;
    for (int i = 0; i < 7; i++) {
        s->mC[i] = 0;
    }
    s->m4 = t->m2350 + 1;
}

void fn_802BA708(Unk802B9F40* t)
{
    for (int i = 0; i < 0x14; i++) {
        fn_802BA67C(t, &t->a1EF0[i]);
    }
}

/* near-miss (52 vs 53 insns): retail uses a do-while with s=r29, off=r28, e=r27 and forms t+4 inside the branch; ours hoists it. */
void fn_802BA750(Unk802B9F40* t)
{
    t->m2354 = 0;
    int s = (int)t;
    int last = s + 0x1EB4;
    int off = 0;
    for (; s <= last; s += 0x3C, off += 0x3C) {
        int e = fn_802BA45C(t, (Unk802B9F40_A0*)s);
        if (e == 0) {
            if (*(void**)((char*)t + off) != 0) {
                delete[] *(char**)((char*)t + off);
                *(int*)((char*)t + off) = e;
            }
            char* b = (char*)t + 4;
            if (*(void**)(b + off) != 0) {
                delete[] *(char**)(b + off);
                *(int*)(b + off) = e;
            }
        }
    }
    int so = 0;
    Unk802B9F40_A1EF0* q = t->a1EF0;
    for (int i = 0; i < 0x14; i++) {
        fn_802BA67C(t, q);
        char* b = (char*)t + 0x1F18;
        if (*(void**)(b + so) != 0) {
            delete[] *(char**)(b + so);
            *(int*)(b + so) = 0;
        }
        q++;
        so += 0x38;
    }
}

void fn_802BA820(Unk802B9F40* t, int v)
{
    t->m2350 = v;
}

/* near-miss (store order): retail stores m24, m0, m4, m8, mC, m18, m10, m14, m1C, m20, m28, m2C. */
Unk802BA828::Unk802BA828(int a)
{
    m24 = 0;
    m0 = -1.0f;
    m4 = 0.0f;
    m8 = a;
    mC = 0;
    m18 = 0;
    m10 = 0.0f;
    m14 = 0.0f;
    m1C = 0.0f;
    m20 = 0.0f;
    m28 = 0.0f;
    m2C = 0.0f;
}

Unk802BA828* fn_802BA874(int a)
{
    if (lbl_8061EAE4 == 0) {
        lbl_8061EAE4 = new (0x400) Unk802BA828(a);
    }
    return lbl_8061EAE4;
}

void fn_802BA8C8()
{
    if (lbl_8061EAE4 != 0) {
        delete lbl_8061EAE4;
        lbl_8061EAE4 = 0;
    }
}

/* near-miss: retail keeps v in the sp+8 float temp and f13 = v - m0 directly; ours spills through sp+12. */
void fn_802BA908(Unk802BA828* p)
{
    float v = fn_801A0744(p->m8);
    float d;
    if (p->m0 < 0.0f) {
        d = 0.0f;
    } else {
        d = v - p->m0;
    }
    p->m4 = d;
    p->m0 = v;
}

extern const char lbl_805E0FBC[];
extern const char lbl_805DFC34[];
extern const char lbl_805E0FE4[];
extern const char lbl_805E0FF4[];
extern const char lbl_805E1008[];
extern char lbl_8061C9F0[];
extern const int lbl_805E101C[];
extern void* lbl_8061EAEC;

int fn_804089B4(char* buf, const char* fmt, ...);
void fn_802BADC0(Unk802BACDC_Bat* b, const char* name, void* a, void* c, void* d, int e);
void fn_802AD2B8(void* a, void* b, const char* name, void* c, int d);
void fn_8035A71C(void* a, void* b);
void fn_80314D60(int a);
void* fn_803773D8(unsigned int n);
void* fn_802BB0E4(void* p);
void fn_802BB4BC(Unk802BB1E4_Obj* o);
void fn_802BB334(Unk802BB1E4_Obj* a, Unk802BB1E4_Obj* b);
void fn_802BB29C(Unk802BB1E4_Obj* a, Unk802BB1E4_Obj* b);

void fn_802BACDC(Unk802BACDC_Bat* b)
{
    char buf[0x40];
    fn_804089B4(buf, lbl_805E0FBC, lbl_805DFC34);
    b->m0 = (int)fn_802B9300(buf, 0x400, 1, 0);
    fn_802BAFD0(b);
    fn_802BB038(b);
}

void* fn_802BAD48(void* o, char* base, int idx)
{
    fn_8035A71C(o, base + (idx * 0x168 + 0x10));
    return o;
}

void* fn_802BAD84(void* o, char* base, int idx)
{
    fn_8035A71C(o, base + (idx * 0x168 + 0xB5C));
    return o;
}

void fn_802BAFD0(Unk802BACDC_Bat* b)
{
    fn_802BADC0(b, lbl_805E0FE4, &b->m4, &b->m10, 0, 0);
    Unk802BACDC_Bat* c = b;
    char* d = lbl_8061C9F0;
    fn_802BADC0(c, lbl_805E0FF4, &c->mB50, &c->mB5C, d, 2);
}

void fn_802BB038(Unk802BACDC_Bat* b)
{
    char* d = lbl_8061C9F0;
    fn_802AD2B8(&b->m16A8, &b->m169C, lbl_805E1008, d, 2);
}

void fn_802BB074(Unk802BACDC_Bat* b)
{
    unsigned char i;
    for (i = 0; i <= 7; i++) {
        fn_80314D60(*(int*)((char*)b + i * 0x168 + 0x10));
    }
    for (i = 0; i <= 7; i++) {
        fn_80314D60(*(int*)((char*)b + i * 0x168 + 0xB5C));
    }
}

void* fn_802BB19C()
{
    if (lbl_8061EAEC == 0) {
        lbl_8061EAEC = fn_802BB0E4(fn_803773D8(0x38));
    }
    return lbl_8061EAEC;
}

void fn_802BB1E4(Unk802BB1E4_Obj* o, int k)
{
    fn_802BB4BC(o);
    switch (k) {
    case 0:
        fn_802BB334(o, o);
        fn_802BB334(o, o + 1);
        break;
    case 1:
        fn_802BB29C(o, o);
        fn_802BB29C(o, o + 1);
        break;
    case 2:
        fn_802BB29C(o, o);
        break;
    }
}

int fn_802BB27C(char* o, int idx)
{
    char* b = o + 8;
    int t = *(int*)((char*)lbl_805E101C + idx * 4);
    return *(int*)(b + t * 0x1C);
}

void fn_802BB400(Unk802BB1E4_Obj*, Unk802BB1E4_Obj* o)
{
    int h = fn_803ED9D4();
    o->m8 = h;
    int hi = o->m4;
    o->mC = fn_803ED720(h, lbl_805E10B8, o->m0 + 0x10, hi - 0x20, 0x20, 0x20, 0, 0, 0, 1);
}

void fn_802BB474(Unk802BB1E4_Obj*, Unk802BB1E4_Obj* o)
{
    fn_803ED95C(o->m8);
    fn_803ED8EC(o->m8);
    o->m8 = 0;
    o->mC = 0;
}

void fn_802BB4B8()
{
}
