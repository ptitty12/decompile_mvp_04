/*
 * Game code, .text 0x800975A8-0x8009BC3C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80090880.h"
#include "game/tu_80094578.h"



extern "C" void fn_8008B690(void* p);

extern "C" void fn_800975A8(char* o, int a, int b, int c, int i) { fn_8008B690(o + (i * 0x128 + 0x8FC)); }

extern "C" void fn_800975D4(char* o, int a, int b, int slot, int c, int player)
{
    char* base = o + 0x924;
    Rec* r = *(Rec**)(base + (player * 0x128 + slot * 4));
    r->v8(a, b, c);
}

extern "C" int fn_8006FB28(void* p);

extern "C" int fn_80097620(char* o, int a, int b, int i) { return fn_8006FB28((char*)(i * 0x128 + (int)o) + 0x92C); }

extern "C" int fn_8008B42C(void* p);

extern "C" int fn_8009764C(char* o, int a, int b, int i) { return fn_8008B42C(o + (i * 0x128 + 0x8FC)); }

extern "C" int fn_80080724(void* p);

extern "C" int fn_80097A70(char* o, int a, int b, int i) { return fn_80080724((char*)(i * 0x128 + (int)o) + 0x95C); }

extern "C" int fn_80097A9C(char* o, int a, int b, int c, int i)
{
    int r;
    if (c <= 1) {
        char* base = o + 0x924;
        int off = c * 4 + i * 0x128;
        r = (*(Rec**)(base + off))->v5(a, b);
    } else {
        int off = i * 0x128;
        char* base2 = o + 0x928;
        int x = (*(Rec**)(base2 + off))->v5(a, b);
        char* base = o + 0x924;
        r = x + (*(Rec**)(base + off))->v5(a, b);
    }
    return r;
}

extern "C" int fn_80097EA4(char* o, int a, int b, int c, int i)
{
    int r;
    if (c <= 1) {
        char* base = o + 0x954;
        int off = c * 4 + i * 0x128;
        r = (*(Rec**)(base + off))->v5(a, b);
    } else {
        int off = i * 0x128;
        char* base2 = o + 0x958;
        int x = (*(Rec**)(base2 + off))->v5(a, b);
        char* base = o + 0x954;
        r = x + (*(Rec**)(base + off))->v5(a, b);
    }
    return r;
}

extern "C" int fn_800983C8(char* o, int a, int b) { return fn_80097620(o, a, b, 0) + fn_80097620(o, a, b, 1); }

extern "C" int fn_8009841C(char* o, int a, int b) { return fn_8009764C(o, a, b, 0) + fn_8009764C(o, a, b, 1); }

extern "C" int fn_80098918(char* o, int a, int b) { return fn_80097A70(o, a, b, 0) + fn_80097A70(o, a, b, 1); }

extern "C" int fn_80097A9C(char* o, int a, int b, int c, int i);

extern "C" int fn_8009896C(char* o, int a, int b, int c) { return fn_80097A9C(o, a, b, c, 0) + fn_80097A9C(o, a, b, c, 1); }

extern "C" int fn_80097EA4(char* o, int a, int b, int c, int i);

extern "C" int fn_80098C68(char* o, int a, int b, int c) { return fn_80097EA4(o, a, b, c, 0) + fn_80097EA4(o, a, b, c, 1); }


extern "C" int fn_8009908C(Obj3* o, int kind, int p);

int fn_80071170(void* self, int a, unsigned b);
extern "C" float fn_80097F68(char* o, int a, int b, int c, int i);

extern "C" int fn_8009908C(Obj3* o, int kind, int p)
{
    int base = fn_80071170((char*)o + 0xD1C, kind, p);
    int r = 0;
    switch (kind) {
    case 0:
        r = fn_80097620((char*)o, 0, p, 0);
        break;
    case 1:
        r = (int)fn_80097F68((char*)o, 1, p, 2, 0);
        break;
    case 2:
        r = (int)fn_80097F68((char*)o, 0, p, 2, 0);
        break;
    case 3:
        r = fn_80097EA4((char*)o, 0, p, 2, 0);
        break;
    case 4:
        r = fn_80097EA4((char*)o, 1, p, 2, 0);
        break;
    case 5:
        r = fn_80097620((char*)o, 3, p, 0);
        break;
    case 6:
        r = fn_80097620((char*)o, 1, p, 0);
        break;
    }
    return base + r;
}

extern "C" float fn_800991AC(Obj3* o, int mode, int p)
{
    float r = 0.0f;
    if (mode == 0) {
        float x = (float)fn_8009908C(o, 2, p);
        float y = (float)fn_8009908C(o, 1, p);
        if (!(y <= 0.0f))
            r = x / y;
    }
    return r;
}

struct Unk80089894_PackTab;
int fn_8008AC94(Unk80089894_PackTab* self, unsigned a, unsigned b);

extern "C" int fn_80099278(Obj3* o, int k, int p)
{
    int base = fn_8008AC94((Unk80089894_PackTab*)((char*)o + 0xD44), k, p);
    int r = 0;
    switch (k) {
    case 0:
        r = fn_8009764C((char*)o, 0, p, 0);
        break;
    case 7:
        r = fn_8009764C((char*)o, 1, p, 0);
        break;
    case 8:
        r = fn_8009764C((char*)o, 2, p, 0);
        break;
    case 1:
        r = fn_8009764C((char*)o, 6, p, 0);
        break;
    case 3:
        r = fn_8009764C((char*)o, 3, p, 0);
        break;
    case 2:
        r = fn_8009764C((char*)o, 4, p, 0);
        break;
    case 4:
        r = fn_8009764C((char*)o, 7, p, 0);
        break;
    case 6:
        r = fn_80097A9C((char*)o, 2, p, 2, 0);
        break;
    case 5:
        r = fn_80097A9C((char*)o, 0, p, 2, 0);
        break;
    }
    return base + r;
}

extern "C" float fn_800993C0(Obj3* o, int mode, int p)
{
    float r = 0.0f;
    if (mode == 0) {
        float a = (float)fn_80099278(o, 1, p);
        float d = (float)fn_80099278(o, 7, p) + (float)fn_80099278(o, 8, p) * 0.33333334f;
        if (!(d <= 0.0f))
            r = a * 9.0f / d;
    }
    return r;
}

extern "C" void fn_800994D4(char* o, int x)
{
    unsigned a = fn_8009764C(o, 2, x, 0);
    unsigned b = fn_8009764C(o, 1, x, 0);
    a += 1;
    if (a > 2) {
        a = 0;
        b += 1;
    }
    fn_800975A8(o, 2, x, a, 0);
    fn_800975A8(o, 1, x, b, 0);
}

struct Unk80099570 {
    char pad0[0xCC4];
    Rec* mCC4;
    Rec* mCC8;
};

extern "C" int fn_80099570(Unk80099570* o, int a, int b, int c)
{
    int r;
    if (c <= 1) {
        char* base = (char*)&o->mCC4;
        r = (*(Rec**)(base + c * 4))->v5(a, b);
    } else {
        Rec* x = o->mCC8;
        int y = x->v5(a, b);
        r = y + o->mCC4->v5(a, b);
    }
    return r;
}

extern "C" int fn_800997DC(Obj3* o, ByteVec* v);
extern "C" int fn_80099670(Obj3* o);
extern "C" int fn_80099704(Obj3* o);

extern "C" int fn_80099620(Obj3* o)
{
    int r = 0;
    if (fn_80099670(o) == 1)
        r = fn_80099704(o) == 1;
    return r;
}

extern "C" int fn_80097148(Obj3* o, unsigned i);
extern "C" int fn_8008CFD8(void* p, int a, int b);

extern "C" int fn_80099670(Obj3* o)
{
    int cnt = 0;
    unsigned char n = o->m3E4;
    unsigned char i = 0;
    if (i < n) {
        do {
            if (fn_80097148(o, i) == 0) {
                int s = fn_8008CFD8((char*)o + 0xC9C, 5, i);
                if (s != 0 && s != 10)
                    cnt++;
            }
            i++;
        } while (i < n);
    }
    return cnt > 0;
}

extern "C" int fn_80099754(Obj3* o);

extern "C" int fn_80099704(Obj3* o)
{
    if (fn_80099754(o) == 1)
        return 1;
    return fn_800997DC(o, &o->m0) == 1;
}

extern "C" int fn_80099754(Obj3* o)
{
    if (fn_800997DC(o, &o->m14) == 1)
        return 1;
    if (fn_800997DC(o, &o->m28) == 1)
        return 1;
    if (fn_800997DC(o, &o->m3C) == 1)
        return 1;
    return fn_800997DC(o, &o->m50) == 1;
}

extern "C" int fn_80097148(Obj3* o, unsigned i);

extern "C" int fn_800997DC(Obj3* o, ByteVec* v)
{
    unsigned i = 0;
    if (i < v->m4) {
        do {
            if (fn_80097148(o, v->m0[i]) == 0)
                return 1;
            i++;
        } while (i < v->m4);
    }
    return 0;
}

extern "C" void fn_80080828(void* p, int a, int k, int b);
extern "C" int fn_80099620(Obj3* o);
extern "C" void fn_80099A44(Obj3* o, int k, int slot);

extern "C" void fn_800999CC(Obj3* o, int k, int slot)
{
    if (o->m17C[slot] != k) {
        fn_80099A44(o, k, slot);
        o->m3E8[k].m4 = 2;
        fn_80080828((char*)o + 0x95C, 0, k, 1);
    }
    if (!fn_80099620(o))
        o->m234 = 0;
}

/* near-miss: retail hoists the count before an entry jump to the loop test */
extern "C" void fn_80099A44(Obj3* o, int k, int slot)
{
    ByteVec* v = &o->m168;
    unsigned i = 0;
    while (i < v->m4) {
        if (v->m0[i] == o->m17C[slot]) {
            if (i >= v->m4)
                v->m4 = i + 1;
            v->m0[i] = k;
            break;
        }
        i++;
    }
    o->m17C[slot] = k;
}

extern "C" void fn_80099AF4(Obj3* o, int k);

extern "C" void fn_80099AA0(Obj3* o, int key)
{
    unsigned i;
    for (i = 0; i <= 0x18; i++) {
        if (o->m3E8[i].m0 == key) {
            fn_80099AF4(o, (unsigned char)i);
            return;
        }
    }
}

extern "C" void fn_80099AF4(Obj3* o, int k)
{
    ByteVec* v = &o->m74;
    int n = v->m4;
    if (n > 0 && v->m0[0] == k)
        return;
    if (n > 1 && v->m0[1] == k)
        return;
    if ((unsigned)n >= v->m8)
        return;
    v->m0[n] = k;
    v->m4 = v->m4 + 1;
}

extern "C" int fn_80099B50(Obj3* o, int i)
{
    int r = 0;
    unsigned char s = o->m74.m0[(unsigned char)i];
    if (s <= 0x18)
        r = o->m3E8[s].m0;
    return r;
}

struct Unk80089894_PackTabD;
int fn_80089AA0(Unk80089894_PackTabD* self, unsigned t, unsigned i);

extern "C" float fn_80099B7C(Obj3* o)
{
    unsigned char k = o->m17C[0];
    Unk80089894_PackTabD* t = (Unk80089894_PackTabD*)((char*)o + 0xC74);
    float a = (float)fn_80089AA0(t, 0, k);
    float b = (float)fn_80089AA0(t, 0x1B, k);
    float r = !(a <= 0.0f) ? b / a : 0.0f;
    return r;
}

/* Container with its vptr at +0x10: count at +4, cursor at +0xC (the ByteVec of Obj3). */
struct VecObj8009A4A4 {
    int m0;
    int m4;
    int m8;
    int mC;
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

extern "C" void fn_8009A4A4(Obj3* o, VecObj8009A4A4* v, int* out, int n)
{
    int cnt = v->m4;
    if (cnt > n)
        cnt = n;
    v->v1();
    if (cnt > 0) {
        do {
            *out = v->v3();
            out++;
            v->v10();
        } while (--cnt != 0);
    }
    v->mC = 0;
}

extern "C" void* fn_800B555C();
extern "C" int fn_800B57EC(void* p);

extern "C" void fn_8009A548(Obj3* o, int n, int* arr, int slot, int off, int mode)
{
    signed char i = 0;
    signed char r = -1;
    if (i < n) {
        char* b = (char*)o + 0x3E8;
        int so = slot * 0x34;
        if (*(volatile int*)(b + so) == arr[0]) {
            r = 0;
        } else {
            do {
                i++;
                if (!(i < n))
                    break;
            } while (*(volatile int*)(b + so) != arr[i]);
            if (i < n)
                r = i;
        }
    }
    if (fn_800B57EC(fn_800B555C()) != 0 && mode == 1) {
        int so2 = slot * 0x34;
        char* p = (char*)o + 0x40A;
        p[off + so2] = r;
    } else if (fn_800B57EC(fn_800B555C()) == 0 || mode == 0) {
        int so2 = slot * 0x34;
        char* p = (char*)o + 0x412;
        p[off + so2] = r;
    }
}

extern "C" void fn_8009A620(Obj3* o, int n, int* arr, int slot, int off, int mode)
{
    unsigned char i = 0;
    signed char r = -1;
    if (i < n) {
        char* b = (char*)o + 0x3E8;
        int so = slot * 0x34;
        if (*(volatile int*)(b + so) == arr[0]) {
            r = 0;
        } else {
            do {
                i++;
                if (!(i < n))
                    break;
            } while (*(volatile int*)(b + so) != arr[i]);
            if (i < n)
                r = i;
        }
    }
    if (fn_800B57EC(fn_800B555C()) != 0 && mode == 1) {
        int so2 = slot * 0x34;
        char* p = (char*)o + 0x3FE;
        p[off + so2] = r;
    } else if (fn_800B57EC(fn_800B555C()) == 0 || mode == 0) {
        int so2 = slot * 0x34;
        char* p = (char*)o + 0x404;
        p[off + so2] = r;
    }
}
