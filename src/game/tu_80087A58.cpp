/*
 * Game code, .text 0x80087A58-0x80089894 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80087A58.h"

typedef Unk80087A58_O O;
typedef Unk80087A58_H H;
typedef Unk80087A58_E E;

extern int lbl_8068B618;
extern char lbl_8064A208[];
extern float lbl_805B4640;
extern double lbl_805B4638;
extern const char lbl_805B475C[];
extern const char lbl_805B47A8[];
extern "C" void fn_8033E958(const char* fmt, ...);
extern "C" void fn_80088B9C(O* o, int a, int b);
extern "C" void fn_800888F4(O* o);
extern float lbl_805B47D4;





struct Unk80087A58_X3 {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk80087A58_X2 {
    char pad0[0x14];
    Unk80087A58_X3* m14;
};
struct Unk80087A58_X {
    char pad0[0x6F4];
    int m6F4;
    Unk80087A58_X2* m6F8;
};

struct Unk80087A58_Y {
    int m0;
    int m4;
    Unk80087A58_X* m8;
};

extern Unk80087A58_Y* lbl_8061B8C0;



void fn_80087CC4(H* h);

void fn_80087A58(O* s, int a, char v, int w, int flag);
char fn_80087A88(O* s, int a, int w, int flag);
float fn_80087ABC(O* s, int a, int w);
void fn_80087B10();
int fn_80087B60(int t);
int fn_80087BE8(int a, int b);
H* fn_80087C88(H* h);
void fn_80087CC4(H* h);
void fn_80087D08();
void fn_80087F7C(H* h, int v);
int fn_80087F94(H* h);
void fn_8008801C();
void fn_80088020();


















void fn_80088024(void* s, int a, int b, int c, Unk80087A58_Pair* p, int d);







extern float lbl_805B4860;
extern float lbl_805B4864;

void fn_80087A58(O* s, int a, char v, int w, int flag);
char fn_80087A88(O* s, int a, int w, int flag);
float fn_80087ABC(O* s, int a, int w);
void fn_80087B10();
Unk80087A58_X* fn_80087B14();
int fn_80087B60(int t);
int fn_80087BE8(int a, int b);
H* fn_80087C88(H* h);
void fn_80087CC4(H* h);
void fn_80087D08();
void fn_80087D0C(H* h);
int fn_80087E0C(H* h, int a, int b);
E* fn_80087E5C(H* h, int a, int b, int k);
void fn_80087F7C(H* h, int v);
int fn_80087F94(H* h);
void fn_8008801C();
void fn_80088020();
void fn_800881FC(void* s, int a, int b, int c, Unk80087A58_Rec* z);
int fn_80088234(O* o, int v);
int fn_80088280(O* o);
int fn_800882D0(O* o);
int fn_8008838C(O* o, int a, int b);
int fn_80088640(O* o, int a, int b);
float fn_80088E74(O* o);
float fn_80088EA4(O* o);
E* fn_80088EAC(O* o, int a, int b, int c);
int fn_80088EDC(O* o, int i);
int fn_80088EFC(O* o, int i);
int fn_80088F48(O* o, int i);
int fn_80088F84(O* o, int i);
int fn_80088FBC(O* o, int i);
int fn_80088FFC(O* o, int i);
void fn_80089108(O* o);
int fn_80089304(void* x, int t);
int fn_80089348(void* x, int t, int* out);
Unk80087A58_X* fn_80089798();





































void* operator new[](unsigned int size, int heap); /* 0x803774A8 */
void fn_80071604(void* self);
void fn_80071688(void* self, int flags);
void* fn_8007366C(const char* a, const char* b);
void fn_8040074C(void* p, int n);
extern char lbl_805B3B4C[];
extern char lbl_805B4BAC[];
extern char lbl_8064AE98[];

void fn_80087A58(O* s, int a, char v, int w, int flag);
char fn_80087A88(O* s, int a, int w, int flag);
float fn_80087ABC(O* s, int a, int w);
void fn_80087B10();
Unk80087A58_X* fn_80087B14();
int fn_80087B60(int t);
int fn_80087BE8(int a, int b);
H* fn_80087C88(H* h);
void fn_80087CC4(H* h);
void fn_80087D08();
void fn_80087D0C(H* h);
int fn_80087E0C(H* h, int a, int b);
E* fn_80087E5C(H* h, int a, int b, int k);
void fn_80087F7C(H* h, int v);
int fn_80087F94(H* h);
void fn_8008801C();
void fn_80088020();
void fn_800881FC(void* s, int a, int b, int c, Unk80087A58_Rec* z);
int fn_80088234(O* o, int v);
int fn_80088280(O* o);
int fn_800882D0(O* o);
int fn_8008838C(O* o, int a, int b);
int fn_80088640(O* o, int a, int b);
float fn_80088E74(O* o);
float fn_80088EA4(O* o);
E* fn_80088EAC(O* o, int a, int b, int c);
int fn_80088EDC(O* o, int i);
int fn_80088EFC(O* o, int i);
int fn_80088F48(O* o, int i);
int fn_80088F84(O* o, int i);
int fn_80088FBC(O* o, int i);
int fn_80088FFC(O* o, int i);
void fn_80089108(O* o);
int fn_80089304(void* x, int t);
int fn_80089348(void* x, int t, int* out);
Unk80087A58_X* fn_80089798();
Unk80087A58_K* fn_800897B8(Unk80087A58_K* self);
void fn_80089838(Unk80087A58_K* self, int flags);







































extern Unk80087A58_Pair lbl_8060558C;

void fn_80087A58(O* s, int a, char v, int w, int flag);
char fn_80087A88(O* s, int a, int w, int flag);
float fn_80087ABC(O* s, int a, int w);
void fn_80087B10();
Unk80087A58_X* fn_80087B14();
int fn_80087B60(int t);
int fn_80087BE8(int a, int b);
void fn_80087C40(E* e);
H* fn_80087C88(H* h);
void fn_80087CC4(H* h);
void fn_80087D08();
void fn_80087D0C(H* h);
int fn_80087E0C(H* h, int a, int b);
E* fn_80087E5C(H* h, int a, int b, int k);
void fn_80087F7C(H* h, int v);
int fn_80087F94(H* h);
void fn_8008801C();
void fn_80088020();
void fn_800881FC(void* s, int a, int b, int c, Unk80087A58_Rec* z);
int fn_80088234(O* o, int v);
int fn_80088280(O* o);
int fn_800882D0(O* o);
int fn_8008838C(O* o, int a, int b);
int fn_80088640(O* o, int a, int b);
float fn_80088E74(O* o);
float fn_80088EA4(O* o);
E* fn_80088EAC(O* o, int a, int b, int c);
int fn_80088EDC(O* o, int i);
int fn_80088EFC(O* o, int i);
int fn_80088F48(O* o, int i);
int fn_80088F84(O* o, int i);
int fn_80088FBC(O* o, int i);
int fn_80088FFC(O* o, int i);
void fn_80089108(O* o);
int fn_80089304(void* x, int t);
int fn_80089348(void* x, int t, int* out);
Unk80087A58_X* fn_80089798();
Unk80087A58_K* fn_800897B8(Unk80087A58_K* self);
void fn_80089838(Unk80087A58_K* self, int flags);








































extern float lbl_805B4868;
double fabs(double);
struct Unk80087A58_V2 {
    float x;
    float y;
};

void fn_80087A58(O* s, int a, char v, int w, int flag);
char fn_80087A88(O* s, int a, int w, int flag);
float fn_80087ABC(O* s, int a, int w);
void fn_80087B10();
Unk80087A58_X* fn_80087B14();
int fn_80087B60(int t);
int fn_80087BE8(int a, int b);
void fn_80087C40(E* e);
H* fn_80087C88(H* h);
void fn_80087CC4(H* h);
void fn_80087D08();
void fn_80087D0C(H* h);
int fn_80087E0C(H* h, int a, int b);
E* fn_80087E5C(H* h, int a, int b, int k);
void fn_80087F7C(H* h, int v);
int fn_80087F94(H* h);
void fn_8008801C();
void fn_80088020();
void fn_800881FC(void* s, int a, int b, int c, Unk80087A58_Rec* z);
int fn_80088234(O* o, int v);
int fn_80088280(O* o);
int fn_800882D0(O* o);
int fn_8008838C(O* o, int a, int b);
int fn_80088640(O* o, int a, int b);
float fn_80088E74(O* o);
float fn_80088EA4(O* o);
E* fn_80088EAC(O* o, int a, int b, int c);
int fn_80088EDC(O* o, int i);
int fn_80088EFC(O* o, int i);
int fn_80088F48(O* o, int i);
int fn_80088F84(O* o, int i);
int fn_80088FBC(O* o, int i);
int fn_80088FFC(O* o, int i);
void fn_80089108(O* o);
int fn_80089114(void* s, Unk80087A58_V2* v);
int fn_80089304(void* x, int t);
int fn_80089348(void* x, int t, int* out);
Unk80087A58_X* fn_80089798();
Unk80087A58_K* fn_800897B8(Unk80087A58_K* self);
void fn_80089838(Unk80087A58_K* self, int flags);

extern float lbl_805B4758;



extern "C" void* fn_803774A8(unsigned size, int heap);
void* fn_80089368(void* p);
void fn_8008928C(O* o);


extern float lbl_805B486C;


extern "C" int fn_80353D9C(void* p);
void fn_80087D5C(H* h, int a, int b, int c);





extern "C" void fn_8040B320(void* p, int v, int n);


void fn_80087A58(O* s, int a, char v, int w, int flag)
{
    int i = flag == 0 ? s->m14[w] : s->m234;
    s->m238[a + i * 0x59] = v;
}

char fn_80087A88(O* s, int a, int w, int flag)
{
    int i = flag == 0 ? s->m14[w] : s->m234;
    return s->m238[a + i * 0x59];
}

float fn_80087ABC(O* s, int a, int w)
{
    return (float)fn_80087A88(s, a, w, 0) * lbl_805B4640;
}

void fn_80087B10()
{
}

Unk80087A58_X* fn_80087B14()
{
    if (lbl_8068B618 == 0)
        return 0;
    Unk80087A58_X* p = lbl_8061B8C0->m8;
    if (p == 0)
        return 0;
    if (p->m6F4 != 0)
        return 0;
    return p;
}

int fn_80087B60(int t)
{
    int r = 1;
    if (t == 3)
        r = 0;
    else if (t <= 3)
        r = 1;
    else if (t == 4)
        r = 1;
    else if (t <= 6)
        r = 0;
    return r;
}

inline float AbsF(float v) { return __builtin_fabs(v); }
int fn_80087B8C(Unk80087A58_V2 v)
{
    int r = 0;
    if (!(AbsF(v.x) > lbl_805B4758)) {
        int f = AbsF(v.y) <= lbl_805B4758;
        r = f;
    }
    return r;
}

int fn_80087BE8(int a, int b)
{
    int r = 0;
    int c = fn_80087B60(a);
    if ((b == 0 && (unsigned)(a - 2) <= 1) || c == 0)
        r = 1;
    return r;
}

void fn_80087C40(E* e)
{
    e->m4 = 0;
    e->m0 = 0;
    e->b10.hi = 0;
    e->b10.b = 0;
    *(Unk80087A58_Pair*)&e->m8 = lbl_8060558C;
    e->b10.a = 0;
    e->b10.c = 0;
}

H* fn_80087C88(H* h)
{
    h->m7E0 = lbl_8064A208;
    fn_80087CC4(h);
    return h;
}

void fn_80087CC4(H* h)
{
    E* p = h->e;
    for (int n = 100; n; n--) {
        p->mC = 0;
        p->m8 = 0;
        p->m4 = 0;
        p->m10 = 0;
        p++;
    }
    h->m7D8 = 2;
    h->m7D0 = 0;
    h->m7D4 = 0;
    h->m7DC = 0;
}

void fn_80087D08()
{
}

void fn_80087D0C(H* h)
{
    if (fn_80087B14()) {
        int i = h->m7D0 - 1;
        E* e = &h->e[i];
        e->mC++;
    }
}

/* near-miss (8 slots, register choice only): retail keeps the byte offset in r0 and the
 * zero for the stb in r11; fn_80087D08 receives h (pass-through). */
void fn_80087D08(H* h);
inline void StI(char* b, int off, int v) { *(int*)(b + off) = v; }
void fn_80087D5C(H* h, int a, int b, int c)
{
    int i = h->m7D0 - 1;
    if (h->e[i].mC != 0 || h->e[i].m10 != 0)
        i = fn_80087F94(h);
    if (i > 99)
        i = 99;
    int off = i * 0x14;
    ((E*)((char*)h + off))->mC = 0;
    StI((char*)h, off, a);
    StI((char*)h + 4, off, b);
    StI((char*)h + 8, off, c);
    StI((char*)h + 0x10, off, 0);
    h->m7D4 = b;
    fn_80087D08(h);
}

int fn_80087E0C(H* h, int a, int b)
{
    int cnt = 0;
    unsigned n = h->m7D0;
    for (unsigned i = 0; i < n; i++) {
        if (a == h->e[i].m0 && h->e[i].m4 == b)
            cnt++;
    }
    return cnt;
}

E* fn_80087E5C(H* h, int a, int b, int k)
{
    unsigned i = 0;
    int cnt = 0;
    unsigned n = h->m7D0;
    E* p = h->e;
    for (; i < n; p++, i++) {
        if (a == h->e[i].m0 && h->e[i].m4 == b) {
            if (cnt == k)
                return p;
            cnt++;
        }
    }
    return 0;
}

void fn_80087EBC(H* h, unsigned t)
{
    unsigned n = 0;
    unsigned i = 0;
    for (; i < h->m7D0; i++) {
        if ((unsigned)h->e[i].m8 < t) {
            n = i;
            continue;
        }
        n++;
        break;
    }
    if (n <= 99) {
        for (unsigned k = n; k < 100; k++) {
            h->e[k - n] = h->e[k];
            h->e[k - n].m8 -= 30;
        }
    }
    h->m7D0 -= n;
}

void fn_80087F7C(H* h, int v)
{
    h->e[h->m7D0 - 1].m10 = v;
}

int fn_80087F94(H* h)
{
    h->m7D0 = h->m7D0 + 1;
    if (h->m7D0 > 100) {
        h->m7D0 = 1;
        h->m7DC = 1;
    }
    return h->m7D0 - 1;
}

O* fn_80087FC0(O* o)
{
    o->m0 = 0;
    fn_80089368((char*)o + 0xC);
    fn_80087C88(&o->mF60);
    o->mF5C = (E*)fn_803774A8(0x2EE0, 0);
    fn_8008928C(o);
    return o;
}

void fn_8008801C()
{
}

void fn_80088020()
{
}

/* near-miss 98.3%: only the order of the entry moves differs (retail copies r8 after the two loads of *p) */
void fn_80088024(void* s, int hi, int a, int b, Unk80087A58_Pair* p, int c)
{
    O* o = (O*)s;
    unsigned cur = o->m4;
    Unk80087A58_Pair q = *p;
    if (cur <= 0x256) {
        o->m8 = cur;
        o->m4 = cur + 1;
    } else {
        fn_8033E958(lbl_805B475C);
        fn_8033E958(lbl_805B47A8, o->m8);
        int src = 0x258;
        int dst = 0;
        int n = 0x23A;
        do {
            E* t = o->mF5C;
            *(E*)(dst + (int)t) = *(E*)(src + (int)t);
            src += 0x14;
            dst += 0x14;
        } while (--n != 0);
        o->m4 = 0x23A;
        o->m8 = 0x239;
        fn_80087EBC(&o->mF60, 0x1E);
    }
    fn_80087C40(&o->mF5C[o->m8]);
    o->mF5C[o->m8].b10.hi = hi;
    o->mF5C[o->m8].m0 = a;
    o->mF5C[o->m8].m4 = b;
    *(Unk80087A58_Pair*)&o->mF5C[o->m8].m8 = q;
    o->mF5C[o->m8].b10.a = c;
    unsigned idx = o->m8;
    E* e2;
    int r = fn_80087B8C(*(Unk80087A58_V2*)&q);
    e2 = (E*)(idx * 0x14 + (int)o->mF5C);
    e2->b10.c = r;
    ((void (*)(H*, int, int, int))fn_80087D0C)(&o->mF60, hi, b, o->m8);
    fn_80088B9C(o, a, b);
    fn_800888F4(o);
    o->m1750 = 0;
}

void fn_800881FC(void* s, int a, int b, int c, Unk80087A58_Rec* z)
{
    Unk80087A58_Pair tmp = *(Unk80087A58_Pair*)&z->m8;
    fn_80088024(s, a, b, c, &tmp, z->m14);
}

int fn_80088234(O* o, int v)
{
    int n = 0;
    unsigned cnt = o->m4;
    for (unsigned i = 0; i < cnt; i++) {
        if ((int)o->mF5C[i].b10.hi != v)
            n++;
    }
    return n;
}

int fn_80088280(O* o)
{
    H* h = &o->mF60;
    int i = h->m7D0 - 1;
    if (i < 0)
        return 0;
    E* e = &h->e[i];
    int v = e->m10;
    if (v != 0)
        return v;
    if (i <= 0)
        return 0;
    int j = i - 1;
    E* f = &h->e[j];
    return f->m10;
}

/* near-miss (2 slots): retail has add r9,r7,r11 + lwz 0x10(r9); here addi r9,r7,16 + lwzx. */
inline int Cnt14(H* h)
{
    unsigned i = 0;
    unsigned cnt = h->m7D0;
    int n = 0;
    for (; i < cnt; i++) {
        if (h->e[i].m10 == 14)
            n++;
    }
    return n;
}

int fn_800882D0(O* o)
{
    return Cnt14(&o->mF60);
}

/* near-miss (24 slots): retail keeps o in r12 and the entry offset as a separate counter. */
inline E* AtE3(H* h, unsigned i) { return &h->e[i]; }
int fn_80088314(O* o, int a, int b)
{
    int n = 0;
    unsigned cnt = o->mF60.m7D0;
    for (unsigned i = 0; i < cnt; i++) {
        E* e = AtE3(&o->mF60, i);
        if (e->m10 == 14 && e->m0 != a && o->mF5C[e->m8 + e->mC - 1].m0 == b)
            n++;
    }
    return n;
}

int fn_8008838C(O* o, int a, int b)
{
    int n = 0;
    unsigned cnt = o->m4;
    for (unsigned i = 0; i < cnt; i++) {
        E* e = (E*)(i * 0x14 + (int)o->mF5C);
        if (e->m0 == a && (int)e->b10.hi != b)
            n++;
    }
    return n;
}

extern "C" float fn_80088518(O* o, int flag, int* out, int lim)
{
    if (o->m4 != 0) {
        if (lim < 0)
            lim = o->m4;
        unsigned cnt = 0;
        unsigned i = 0;
        *out = 0;
        if (i < o->m4) {
            int off = 0;
            do {
                E* e = (E*)(off + (int)o->mF5C);
                if ((int)e->b10.hi == flag && !e->b10.c) {
                    cnt++;
                    if (fn_80087BE8(e->b10.b, 0) != 0) {
                        ++*out;
                        if (*out >= lim)
                            break;
                    }
                }
                i++;
                off += 0x14;
            } while (i < o->m4);
        }
        if (cnt != 0)
            return (float)*out / (float)cnt;
    }
    return lbl_805B47D4;
}

int fn_80088640(O* o, int a, int b)
{
    return fn_80087E0C(&o->mF60, a, b);
}

struct Unk8008882C_Teams {
    char pad0[0x14];
    char* m14;
};
struct Unk8008882C_Self {
    Unk8008882C_Teams* m0;
};
extern "C" unsigned char fn_800968C0(void* o, int key, int flag);
extern "C" int fn_8008CFD8(void* p, int a, int b);

int fn_8008882C(Unk8008882C_Self* s, int k, int side, int k2)
{
    int z = side == 0;
    int off1 = side * 0xE64;
    int a = fn_800968C0(s->m0->m14 + off1, k, 1);
    int off2 = z * 0xE64;
    int b = fn_800968C0(s->m0->m14 + off2, k2, 1);
    int c = fn_8008CFD8(s->m0->m14 + off1 + 0xC9C, 9, a);
    int d = fn_8008CFD8(s->m0->m14 + off2 + 0xC9C, 8, b);
    if (d == 2)
        d = c == 0;
    return d == 1;
}

float fn_80088E74(O* o)
{
    float r = (o->m1748 - lbl_805B4860) * lbl_805B4864;
    return r;
}

float fn_80088EA4(O* o)
{
    return o->m1748;
}

E* fn_80088EAC(O* o, int a, int b, int c)
{
    return fn_80087E5C(&o->mF60, a, c, b);
}

int fn_80088EDC(O* o, int i)
{
    if (i == -1 || i > o->m8)
        i = o->m8;
    return i;
}

int fn_80088EFC(O* o, int i)
{
    int k = fn_80088EDC(o, i);
    int z = 0; /* a variable zero: a literal 0 takes the not/srwi sign-bit path */
    return o->mF5C[k].m10 >= z;
}

int fn_80088F48(O* o, int i)
{
    return o->mF5C[fn_80088EDC(o, i)].m4;
}

int fn_80088F84(O* o, int i)
{
    return o->mF5C[fn_80088EDC(o, i)].m0;
}

int fn_80088FBC(O* o, int i)
{
    return o->mF5C[fn_80088EDC(o, i)].b10.b;
}

int fn_80088FFC(O* o, int i)
{
    return o->mF5C[fn_80088EDC(o, i)].b10.a;
}

Unk80087A58_Pair* fn_8008903C(Unk80087A58_Pair* out, O* o, int i)
{
    int k = fn_80088EDC(o, i);
    E* e = (E*)(k * 0x14 + (int)o->mF5C);
    *out = *(Unk80087A58_Pair*)&e->m8;
    return out;
}

void fn_80089094(O* o, int b)
{
    Unk80087A58_X* x = fn_80087B14();
    if (x != 0) {
        H* h = &o->mF60;
        int f = 0;
        if (x->m6F8->m14->m1CD0 != 0)
            f = 1;
        fn_80087D5C(h, f, b, fn_80353D9C(o));
    }
}

void fn_80089108(O* o)
{
    o->m1744 = 1;
}

int fn_80089114(void* s, Unk80087A58_V2* v)
{
    int r = 0;
    if (AbsF(v->x) > lbl_805B4868)
        r = 1;
    else if (!(AbsF(v->y) <= lbl_805B4868))
        r = 1;
    return r;
}

struct Unk80089164_Y {
    char pad0[0x3A4];
    int m3A4;
};
struct Unk80089164_X {
    char pad0[0x700];
    Unk80089164_Y* m700;
};
extern "C" int fn_801D0294(int x);
void fn_80353C60(O* o, int a);
void fn_800895F8(char* base, int a, int b, int c, Unk80087A58_V2* v);

/* near-miss: stack slots of the pair copy are swapped (retail: out-pair at 0x10, copy at 8), crclr/li order */
void fn_80089164(O* o)
{
    Unk80087A58_X* x = fn_80087B14();
    if (x != 0 && o->m1744 != 0 && fn_80353D9C(o) != 0 && o->m1750 == 0) {
        if (fn_80088FBC(o, -1) == 2 && fn_801D0294(((Unk80089164_X*)((Unk80087A58_X*(*)(O*))fn_80089798)(o))->m700->m3A4 + 0x28C) != 0)
            fn_80353C60(o, 3);
        if (fn_80088FBC(o, -1) != 6) {
            int f = ((Unk80087A58_X2*)o->m0)->m14->m1CD0 == 0;
            int k = fn_80088FBC(o, -1);
            int a = fn_80088FFC(o, -1);
            Unk80087A58_Pair p;
            ((Unk80087A58_Pair*(*)(Unk80087A58_Pair*, O*, ...))fn_8008903C)(&p, o, -1);
            Unk80087A58_Pair q = p;
            fn_800895F8((char*)o + 0xC, f, a, k, (Unk80087A58_V2*)&q);
            o->m1744 = 0;
        }
    }
}

void fn_8008928C(O* o)
{
    for (int i = 0; i < 600; i++)
        fn_80087C40(&o->mF5C[i]);
    H* h = &o->mF60;
    fn_80087CC4(h);
    o->m1744 = 1;
    o->m4 = 0;
    o->m8 = 0;
    o->m1748 = lbl_805B486C;
    fn_80087CC4(h);
}

int fn_80089304(void* x, int t)
{
    int r = 0;
    switch (t) {
    case 2:
    case 3:
        break;
    case 4:
        r = 1;
        break;
    case 1:
    case 5:
        r = 4;
        break;
    }
    return r;
}

int fn_80089348(void* x, int t, int* out)
{
    if (t > 7) {
        *out = t - 7;
        return 2;
    }
    return 3;
}

/* near-miss (many slots): retail walks the outer loop on a pointer compared against base + 0xC00 with
 * a byte-offset counter; the mid/inner loops are count-down (addic./bdnz) and the entry is written
 * through stwu r9,0x50(r11). Not reproduced. */
void* fn_80089368(void* pp)
{
    char* p = (char*)pp;
    fn_8040B320(p + 0x50, 0, 0xF00);
    char* q = p;
    int off = 0;
    do {
        int b = 0;
        int boff = 0;
        char* cnt = off + p;
        do {
            int c = 0;
            *cnt = 0;
            int coff = 0;
            do {
                int* e = (int*)(coff + (boff + (int)q));
                e[0x50 / 4] = 0;
                int k = 0;
                int koff = 0;
                do {
                    *(int*)((char*)e + 0x50 + 4 + koff) = 0;
                    koff += 4;
                    k++;
                } while (k < 5);
                coff += 0x18;
                c++;
            } while (c < 2);
            b++;
            boff += 0x30;
            cnt++;
        } while (b <= 15);
        q += 0x300;
        off += 0x10;
    } while (q <= p + 0xC00);
    return p;
}

void fn_800895F8(char* base, int a, int b, int c, Unk80087A58_V2* v)
{
    Unk80087A58_V2 p = *v;
    int k = fn_80089114(base, &p);
    int o = fn_80089304(base, c) * 4;
    char* e = (char*)(k * 0x18 + (b * 0x30 + (a * 0x300 + (int)base)));
    e += 0x50;
    char* b4 = e + 4;
    *(int*)(b4 + o) = *(int*)(b4 + o) + 1;
    *(int*)e = *(int*)e + 1;
    int idx = b + a * 0x10;
    base[idx] = base[idx] + 1;
}

/* near-miss (3 slots, register only): retail keeps the else-branch byte offset in r10, here r0. */
void fn_800896AC(char* base, int a, int b, int c, Unk80087A58_V2* v)
{
    Unk80087A58_V2 p = *v;
    int k = fn_80089114(base, &p);
    int extra = 0;
    int t = fn_80089348(base, c, &extra);
    char* e = (char*)(k * 0x18 + (b * 0x30 + (a * 0x300 + (int)base)));
    e += 0x50;
    if (extra != 0 && t == 2) {
        int o = t * 4;
        char* b4 = e + 4;
        *(int*)(b4 + o) = *(int*)(b4 + o) + extra;
    } else {
        int o = t * 4;
        char* b4 = e + 4;
        *(int*)(b4 + o) = *(int*)(b4 + o) + 1;
    }
    *(int*)e = *(int*)e + 1;
    int idx = b + a * 0x10;
    base[idx] = base[idx] + 1;
}

Unk80087A58_X* fn_80089798()
{
    return fn_80087B14();
}

Unk80087A58_K* fn_800897B8(Unk80087A58_K* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064AE98;
    self->m24 = 0;
    Unk80087A58_T14* p = new (0) Unk80087A58_T14[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x14);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B4BAC);
    return self;
}

void fn_80089838(Unk80087A58_K* self, int flags)
{
    self->m20 = lbl_8064AE98;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}
