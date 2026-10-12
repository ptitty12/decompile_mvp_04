/*
 * Game code, .text 0x802BB4BC-0x802BF974 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802BB4BC.h"
#include "game/tu_802B9218.h"
#include "game/tu_802ACD88.h"

extern Unk802BB4FC* lbl_8061EAF0;
extern const void* lbl_80664080[];
extern int lbl_8061E978;

void fn_803EDA0C(int p);
extern const char lbl_805E11C4[];
extern int lbl_8061F688;
extern char lbl_8068D9D8[];
void* operator new(unsigned int n, int heap);
void fn_802E377C(void* p);
void fn_802E3834(int a, char* b, int c);
int fn_802E3F00(int a, int b, int c, int (*cb)(int, const char*, int*, char**));
void fn_80377408(void* p);
int fn_803EE3D4(int a);
void fn_803E9744(void* p, int a);
void fn_8040B61C(void* dst, const void* src);
void fn_802AF6F8(int a, void* b, int c);

void fn_802BB4BC(Unk802BB1E4_Obj*)
{
}

int fn_802BB4C0(char* o, int i)
{
    char* b = o + 0xC;
    int off = i * 0x1C;
    return *(int*)(b + off);
}

int fn_802BB4D0(char* o, int i)
{
    char* b = o + 8;
    int off = i * 0x1C;
    return fn_803EE3D4(*(int*)(b + off));
}

extern "C" void* fn_802BB4FC(void* p)
{
    Unk802BB4FC* o = (Unk802BB4FC*)p;
    o->m0 = 0;
    o->m4 = 0;
    lbl_8061EAF0 = o;
    return p;
}

void fn_802BB518(Unk802BB4FC* o, int c)
{
    if (o->m0 != 0) {
        fn_803EDA0C(o->m0);
        o->m0 = 0;
    }
    if (o->m4 != 0) {
        o->m4 = 0;
    }
    if (c & 1) {
        fn_80377408(o);
    }
}

Unk802BB4FC* fn_802BB580()
{
    return lbl_8061EAF0;
}

extern const char lbl_805E1144[];
extern const char lbl_805E114C[];
extern const char lbl_805E1158[];
extern const char lbl_805E1164[];
extern const char lbl_805E116C[];
extern const char lbl_805E1174[];
extern const char lbl_805E117C[];
extern const char lbl_805E1184[];
extern const char lbl_805E118C[];
extern const char lbl_805E1194[];
extern const char lbl_805E11A4[];
extern const char lbl_805E11B4[];
extern const char lbl_805E11BC[];
extern char lbl_806EF9DD;
extern char lbl_806EF9DC;
extern char lbl_806EF9CC;
extern char lbl_806EF9CB;
extern char lbl_806EF9DE;
extern char lbl_806EF9DF;
extern char lbl_806EF9CA;
extern char lbl_806EF9E0;
extern char lbl_806EF9E1;
extern char lbl_806EF9E2;
extern char lbl_806EF9E3;
extern char lbl_806EF9E4;
extern char lbl_806EF9E5;
extern int lbl_8061EAF4;
extern int lbl_806E03EC[];
extern char lbl_8068D9E0[];
extern const char* lbl_8061EAF8[];
int fn_8040B3B4(const char* a, const char* b);

int fn_802BB58C(int kind, const char* name, int* out, char** out2)
{
    int r = 0;
    int i;
    switch (kind) {
    case 0:
        if (fn_8040B3B4(name, lbl_805E1144) == 0)
            *out = lbl_806EF9DD;
        else if (fn_8040B3B4(name, lbl_805E114C) == 0)
            *out = lbl_806EF9DC;
        else if (fn_8040B3B4(name, lbl_805E1158) == 0)
            *out = lbl_806EF9CC;
        else if (fn_8040B3B4(name, lbl_805E1164) == 0)
            *out = lbl_806EF9CB;
        else if (fn_8040B3B4(name, lbl_805E116C) == 0)
            *out = lbl_806EF9DE;
        else if (fn_8040B3B4(name, lbl_805E1174) == 0)
            *out = lbl_806EF9DF;
        else if (fn_8040B3B4(name, lbl_805E117C) == 0)
            *out = lbl_806EF9CA;
        else if (fn_8040B3B4(name, lbl_805E1184) == 0)
            *out = lbl_806EF9E0;
        else if (fn_8040B3B4(name, lbl_805E118C) == 0)
            *out = lbl_806EF9E1;
        else if (fn_8040B3B4(name, lbl_805E1194) == 0)
            *out = lbl_806EF9E2;
        else if (fn_8040B3B4(name, lbl_805E11A4) == 0)
            *out = lbl_806EF9E3;
        else if (fn_8040B3B4(name, lbl_805E11B4) == 0)
            *out = lbl_806EF9E4;
        else if (fn_8040B3B4(name, lbl_805E11BC) == 0)
            *out = lbl_806EF9E5;
        r = *out >= 0;
        if (r != 0) {
            lbl_806E03EC[lbl_8061EAF4++] = *out;
        }
        break;
    case 1: {
        i = 0;
        char* p = lbl_8068D9E0;
        for (; i <= 2; p += 0x24, i++) {
            if (fn_8040B3B4(p, name) == 0) {
                *out2 = p;
                r = 1;
                break;
            }
        }
        if (r == 0) {
            r = 1;
            *out2 = lbl_8068D9E0;
        }
        break;
    }
    case 2:
        *out = -1;
        for (i = 0; i <= 15; i++) {
            if (fn_8040B3B4(lbl_8061EAF8[i], name) == 0) {
                *out = i;
                r = 1;
                break;
            }
        }
        break;
    }
    return r;
}

void fn_802BB894(Unk802BB894* o)
{
    fn_802E377C(operator new(0x28, 0));
    fn_802E3834(lbl_8061F688, lbl_8068D9D8, 0x64);
    int h = (int)fn_802B9300(lbl_805E11C4, 0, 1, 0);
    o->m4 = h;
    o->m0 = fn_802E3F00(lbl_8061F688, h, 1, fn_802BB58C);
}

int fn_802BB920(int v)
{
    if (v >= 0) {
        if (v <= 3 || v == 0xB) {
            return 1;
        }
    }
    return 0;
}

void fn_802BB948(Unk802BB948* o)
{
    if (o->m4 != 0) {
        fn_803E9744(o->m4, 3);
        o->m4 = 0;
    }
    if (o->m0 != 0) {
        fn_802B961C(o->m0, o->m8);
        o->m0 = 0;
    }
}

void* fn_802BB9A8(void* p)
{
    Unk802BBA40* o = (Unk802BBA40*)p;
    o->m10 = 0;
    o->m14 = 0;
    return p;
}

void fn_802BB9BC(void* p, int c)
{
    if (c & 1) {
        fn_80377408(p);
    }
}

void fn_802BB9E4()
{
}

void* fn_802BB9E8(void* p)
{
    Unk802BB9E8* o = (Unk802BB9E8*)p;
    o->m24 = lbl_80664080;
    o->mC = 0;
    o->m10 = 0;
    o->m14 = 0;
    return p;
}

void fn_802BBA0C(void* p, int c)
{
    ((Unk802BB9E8*)p)->m24 = lbl_80664080;
    if (c & 1) {
        fn_80377408(p);
    }
}

void fn_802BBA40(Unk802BBA40* o, const char* name, int b, int c, int d)
{
    fn_8040B61C(o->m18, name);
    o->m4 = b;
    o->m8 = c;
    o->m0 = d;
}

void fn_802BBA88(Unk802BBA40* o)
{
    int n = o->m10 - 1;
    o->m10 = n;
    if (o->m14 != 0 && n == 0) {
        o->m14 = 0;
        fn_802AF6F8(lbl_8061E978, o->m18, 0);
    }
}

void fn_802BBAE0(int a, int b, int n, int* lo, int* hi)
{
    int m = n - 1;
    int x = (b - a) & m;
    int y = (a - b) & m;
    if (y < x) {
        int t = a;
        a = b;
        b = t;
    }
    if (b < a) {
        b += n;
    }
    *lo = a;
    *hi = b;
}

extern const char lbl_805E02C0[];
extern float lbl_805E11D8;
extern Unk802B0ACC_T* lbl_8061EA68;
int fn_802B1EE8(Unk802B0ACC_T* t, const char* name);
int fn_8040B574(const char* a, const char* b);
int fn_8040B6A0(const char* s);
char* fn_8040B61C(char* d, const char* s);
void fn_80329AEC(const char** pp, const char** out, int* pn, int delim);
int fn_80329C4C(const char** pp, int* pn, int* out, int lo, int hi, int delim);
int fn_80329B98(const char** pp, int* pn, float* out, int delim);

void* fn_803774A8(unsigned n, int heap);

int* fn_802BBB20(const char* text)
{
    int len = fn_8040B6A0(text);
    int count = 0;
    int i = 0;
    int* blk = 0;
    char name[0x18];
    fn_80329C4C(&text, &len, &count, 0, 100000, 10);
    if (i < count) {
        do {
            const char* s;
            int lvl;
            fn_80329AEC(&text, &s, &len, 0x2C);
            fn_8040B61C(name, s);
            fn_80329C4C(&text, &len, &lvl, 0, 0x7FFFFFFF, 10);
            if (lvl == fn_802B1EE8(lbl_8061EA68, name) || fn_8040B574(name, lbl_805E02C0) == 0) {
                int n = 0;
                fn_80329C4C(&text, &len, &n, 0, 100000, 10);
                int row = 0;
                blk = (int*)fn_803774A8(n * 0x24 + 4, 0x100);
                *blk = n;
                if (row < *blk) {
                    char* p = (char*)blk + 4;
                    do {
                        int off = 0;
                        int j = 3;
                        char* q2 = p + 8;
                        char* q1 = p + 4;
                        do {
                            fn_80329B98(&text, &len, (float*)(p + off), 0x2C);
                            off += 0xC;
                            fn_80329B98(&text, &len, (float*)q1, 0x2C);
                            q1 += 0xC;
                            fn_80329B98(&text, &len, (float*)q2, 0xA);
                            q2 += 0xC;
                        } while (--j != 0);
                        row++;
                        p += 0x24;
                    } while (row < *blk);
                }
            } else {
                int n2 = 0;
                fn_80329C4C(&text, &len, &n2, 0, 100000, 10);
                int row = 0;
                if (row < n2) {
                    do {
                        int k = 3;
                        do {
                            float f;
                            fn_80329B98(&text, &len, &f, 0x2C);
                            fn_80329B98(&text, &len, &f, 0x2C);
                            fn_80329B98(&text, &len, &f, 0xA);
                        } while (--k != 0);
                        row++;
                    } while (row < n2);
                }
            }
            i++;
        } while (i < count);
    }
    return blk;
}

int fn_802BBD80(const char* text)
{
    int len = fn_8040B6A0(text);
    int n = 0;
    int count = 0;
    int i = 0;
    int total = 0;
    char name[0x18];
    fn_80329C4C(&text, &len, &count, 0, 100000, 10);
    if (i < count) {
        do {
            const char* s;
            int lvl;
            fn_80329AEC(&text, &s, &len, 0x2C);
            fn_8040B61C(name, s);
            fn_80329C4C(&text, &len, &lvl, 0, 0x7FFFFFFF, 10);
            int have = fn_802B1EE8(lbl_8061EA68, name);
            fn_80329C4C(&text, &len, &n, 0, 100000, 10);
            if (lvl <= have || fn_8040B574(name, lbl_805E02C0) == 0)
                total += n;
            int j = 0;
            if (j < n) {
                do {
                    int v = 0;
                    fn_80329C4C(&text, &len, &v, 0x80000000, 0x7FFFFFFF, 10);
                    int k = 3;
                    do {
                        float f = lbl_805E11D8;
                        fn_80329B98(&text, &len, &f, 0x2C);
                        fn_80329B98(&text, &len, &f, 0x2C);
                        fn_80329B98(&text, &len, &f, 0xA);
                    } while (--k != 0);
                    j++;
                } while (j < n);
            }
            i++;
        } while (i < count);
    }
    return total;
}

struct Unk802BBF54_Rec {
    float f[9];
    int v;
};

struct Unk802BBF54_Blk {
    int n;
    Unk802BBF54_Rec rec[1];
};

extern float lbl_805E11DC;

/* near-miss (175/181): same code as retail; the two strength-reduced record pointers (v field / float base) get swapped registers (r19/r20, r26/r27). 1680 header orders tried. */
Unk802BBF54_Blk* fn_802BBF54(const char* text)
{
    int total = fn_802BBD80(text);
    int n = 0;
    int len = fn_8040B6A0(text);
    Unk802BBF54_Blk* blk = (Unk802BBF54_Blk*)fn_803774A8((total * 0x28) | 4, 0x100);
    blk->n = total;
    int count = 0;
    int idx = 0;
    int i = 0;
    char name[0x18];
    fn_80329C4C(&text, &len, &count, 0, 100000, 10);
    if (i < count) {
        do {
            const char* s;
            int lvl;
            fn_80329AEC(&text, &s, &len, 0x2C);
            fn_8040B61C(name, s);
            fn_80329C4C(&text, &len, &lvl, 0, 0x7FFFFFFF, 10);
            if (lvl <= fn_802B1EE8(lbl_8061EA68, name) || fn_8040B574(name, lbl_805E02C0) == 0) {
                int row = 0;
                fn_80329C4C(&text, &len, &n, 0, 100000, 10);
                if (row < n) {
                    do {
                        int off = 0;
                        fn_80329C4C(&text, &len, &blk->rec[idx].v, 0x80000000, 0x7FFFFFFF, 10);
                        int j = 3;
                        float* q2 = &blk->rec[idx].f[2];
                        float* q1 = &blk->rec[idx].f[1];
                        do {
                            fn_80329B98(&text, &len, (float*)((char*)&blk->rec[idx] + off), 0x2C);
                            off += 0xC;
                            fn_80329B98(&text, &len, q1, 0x2C);
                            q1 += 3;
                            fn_80329B98(&text, &len, q2, 0xA);
                            q2 += 3;
                        } while (--j != 0);
                        row++;
                        idx++;
                    } while (row < n);
                }
            } else {
                int v = 0;
                int row = 0;
                fn_80329C4C(&text, &len, &n, 0, 100000, 10);
                if (row < n) {
                    do {
                        int j = 3;
                        fn_80329C4C(&text, &len, &v, 0x80000000, 0x7FFFFFFF, 10);
                        do {
                            float f = lbl_805E11DC;
                            fn_80329B98(&text, &len, &f, 0x2C);
                            fn_80329B98(&text, &len, &f, 0x2C);
                            fn_80329B98(&text, &len, &f, 0xA);
                        } while (--j != 0);
                        row++;
                    } while (row < n);
                }
            }
            i++;
        } while (i < count);
    }
    return blk;
}

/* near-miss (57 vs 56 insns): retail adds m.x through the stack slot (lfs f0,8(r1) ... stfs f0,8(r1)) but y and z through a
   pointer to m (r8 = &m); both field-wise and inline-Add forms tried. */
void fn_802BC228(Unk802BC228* out, Unk802BC228* in, Unk802BC228_V3* add)
{
    Unk802BC228 m = *in;
    m.x += add->x;
    m.y += add->y;
    m.z += add->z;
    *out = m;
}
