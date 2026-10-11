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

extern "C" int fn_800983C8(char* o, int a, int b) { return fn_80097620(o, a, b, 0) + fn_80097620(o, a, b, 1); }

extern "C" int fn_8009841C(char* o, int a, int b) { return fn_8009764C(o, a, b, 0) + fn_8009764C(o, a, b, 1); }

extern "C" int fn_80098918(char* o, int a, int b) { return fn_80097A70(o, a, b, 0) + fn_80097A70(o, a, b, 1); }

extern "C" int fn_80097A9C(char* o, int a, int b, int c, int i);

extern "C" int fn_8009896C(char* o, int a, int b, int c) { return fn_80097A9C(o, a, b, c, 0) + fn_80097A9C(o, a, b, c, 1); }

extern "C" int fn_80097EA4(char* o, int a, int b, int c, int i);

extern "C" int fn_80098C68(char* o, int a, int b, int c) { return fn_80097EA4(o, a, b, c, 0) + fn_80097EA4(o, a, b, c, 1); }

/* near-miss: case order / jump layout of the switch differs */
extern "C" int fn_8008AC94(void* p);

extern "C" int fn_80099278(Obj3* o, int k, int p)
{
    int base = fn_8008AC94((char*)o + 0xD44);
    int r = 0;
    switch (k) {
    case 0:
        r = fn_8009764C((char*)o, 0, p, 0);
        break;
    case 1:
        r = fn_8009764C((char*)o, 6, p, 0);
        break;
    case 2:
        r = fn_8009764C((char*)o, 4, p, 0);
        break;
    case 3:
        r = fn_8009764C((char*)o, 3, p, 0);
        break;
    case 4:
        r = fn_8009764C((char*)o, 7, p, 0);
        break;
    case 5:
        r = fn_80097A9C((char*)o, 0, p, 2, 0);
        break;
    case 6:
        r = fn_80097A9C((char*)o, 2, p, 2, 0);
        break;
    case 7:
        r = fn_8009764C((char*)o, 1, p, 0);
        break;
    case 8:
        r = fn_8009764C((char*)o, 2, p, 0);
        break;
    }
    return base + r;
}

extern "C" void fn_800994D4(char* o, int x)
{
    unsigned a = fn_8009764C(o, 2, x, 0) + 1;
    unsigned b = fn_8009764C(o, 1, x, 0);
    if (a > 2) {
        a = 0;
        b += 1;
    }
    fn_800975A8(o, 2, x, a, 0);
    fn_800975A8(o, 1, x, b, 0);
}

/* near-miss: retail lays out the c <= 1 branch first */
struct Unk80099570 {
    char pad0[0xCC4];
    Rec* mCC4;
    Rec* mCC8;
};

extern "C" int fn_80099570(Unk80099570* o, int a, int b, int c)
{
    if (c <= 1)
        return (&o->mCC4)[c]->v5(a, b);
    Rec* x = o->mCC8;
    int r = x->v5(a, b);
    return r + o->mCC4->v5(a, b);
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
