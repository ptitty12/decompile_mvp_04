/*
 * Game code, .text 0x8008CE64-0x80090880 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8008CE64.h"

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */
void fn_80071604(void* self);
void fn_80071688(void* self, int flags);
void fn_80071E2C(void* self);
void* fn_8007366C(const char* a, const char* b);
void fn_8040074C(void* p, int n);
void* fn_8040B61C(char* dst, const char* src);
extern char lbl_805B3B4C[];
typedef Unk8008CE64_G G;
typedef Unk8008CE64_VObj VObj;

extern char lbl_8064B138[];



extern char lbl_8064A220[];



extern void* lbl_8061930C;
extern float lbl_805B55F8;
extern float lbl_805B5608;
extern float lbl_805B5628;
extern char* lbl_80619308;
extern int lbl_80619738[];
extern void* lbl_80619760;
extern Unk8008CE64_Own* lbl_8061977C;
extern char lbl_805B56C0[];
float fn_800799D0(void* a, int v);
float fn_80079A90(void* a, int v);
void* fn_80329FA0(void* out, int v, ...);
void fn_803EDA0C(void* p);
void fn_80377408(void* p);
void fn_80534E80(void* a, const char* b);
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* p);
void fn_8009075C(Unk8008CE64_Own* p, int flags);
void fn_80090814(Unk8008CE64_Own* p, int a, int b);
int fn_800903B8(void* a);




struct Unk8008CE64_Buf3 {
    unsigned short a;
    unsigned short b;
};
struct Unk8008CE64_Buf2 {
    unsigned char a;
    unsigned char b;
    unsigned short pad;
};

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf);
float fn_8008E77C(G* self, int a);
float fn_8008E7F0(G* self, int a);
float fn_8008E864(G* self, int a);
float fn_8008E8D4(G* self, int a);
float fn_8008E950(G* self, int a);
float fn_8008E9CC(G* self, int a);
/* near-miss: same code; retail keeps obj, self and a in r30, r29, r28. */
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self);
void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags);
void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i);
void* fn_8008F08C(void* self, int a, int b, char* buf);
float fn_8008F0B8();
void fn_8008F7E0();
/* near-miss: same register-assignment difference as fn_8008EA20. */
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self);
void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags);
void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i);
int fn_8008F940(void* self);
int fn_8008F948(void* self);
int fn_8008FCC8(int t);
int fn_8008FD14(int t);
void fn_8009010C();
void fn_80090164();
int fn_800901A4();
float fn_80090380(void* a);
void fn_800906B8();
void fn_80090700();
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self);
void fn_8009075C(Unk8008CE64_Own* self, int flags);
void fn_80090814(Unk8008CE64_Own* self, int a, int b);
































extern Unk8008CE64_Pmf lbl_805B6C50[];

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf);
float fn_8008D7B8(Unk8008CE64_Obj* o, int i, int a);
float fn_8008E77C(G* self, int a);
float fn_8008E7F0(G* self, int a);
float fn_8008E864(G* self, int a);
float fn_8008E8D4(G* self, int a);
float fn_8008E950(G* self, int a);
float fn_8008E9CC(G* self, int a);
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self);
void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags);
void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i);
void* fn_8008F08C(void* self, int a, int b, char* buf);
float fn_8008F0B8();
void fn_8008F7E0();
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self);
void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags);
void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i);
int fn_8008F940(void* self);
int fn_8008F948(void* self);
unsigned fn_8008F950(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i);
char* fn_8008F99C(Unk8008CE64_K<Unk8008CE64_T1C>* self, int t, unsigned i, char* buf);
/* near-miss: same register-assignment difference as fn_8008EA20. */
void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj);
int fn_8008FBE8(int v);
int fn_8008FCC8(int t);
int fn_8008FD14(int t);
void fn_8009010C();
void fn_80090164();
int fn_800901A4();
float fn_80090380(void* a);
void fn_800906B8();
void fn_80090700();
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self);
void fn_8009075C(Unk8008CE64_Own* self, int flags);
void fn_80090814(Unk8008CE64_Own* self, int a, int b);





































int fn_8040B6A0(const char* s);
void fn_8040B830(char* dst, const char* src, int n);

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf);
float fn_8008D7B8(Unk8008CE64_Obj* o, int i, int a);
float fn_8008E77C(G* self, int a);
float fn_8008E7F0(G* self, int a);
float fn_8008E864(G* self, int a);
float fn_8008E8D4(G* self, int a);
float fn_8008E950(G* self, int a);
float fn_8008E9CC(G* self, int a);
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self);
void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags);
void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i);
void* fn_8008F08C(void* self, int a, int b, char* buf);
float fn_8008F0B8();
void fn_8008F7E0();
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self);
void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags);
void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i);
int fn_8008F940(void* self);
int fn_8008F948(void* self);
unsigned fn_8008F950(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i);
char* fn_8008F99C(Unk8008CE64_K<Unk8008CE64_T1C>* self, int t, unsigned i, char* buf);
/* near-miss: clamp arms and the store registers/address order differ (35 vs 37 slots). */
void fn_8008FA1C(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i, int v);
/* near-miss: register assignment of the parameters differs. */
void fn_8008FAA8(Unk8008CE64_K<Unk8008CE64_T1C>* self, signed char t, unsigned i, const char* str, int n);
void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj);
int fn_8008FBE8(int v);
int fn_8008FCC8(int t);
int fn_8008FD14(int t);
void fn_8009010C();
void fn_80090164();
int fn_800901A4();
float fn_80090380(void* a);
void fn_800906B8();
void fn_80090700();
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self);
void fn_8009075C(Unk8008CE64_Own* self, int flags);
void fn_80090814(Unk8008CE64_Own* self, int a, int b);

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf)
{
    if (i < self->m1C) {
        switch (t) {
        case 0:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x3C + 0x1F);
            break;
        case 1:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x3C + 0x2B);
            break;
        }
    }
    return buf;
}

float fn_8008D7B8(Unk8008CE64_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6C50[i])(a);
    return r;
}

float fn_8008E77C(G* self, int a)
{
    float r = (float)self->m20->pfn((char*)self + self->m20->delta, 2, a) + lbl_805B55F8;
    return r;
}

float fn_8008E7F0(G* self, int a)
{
    float r = (float)self->m20->pfn((char*)self + self->m20->delta, 3, a) + lbl_805B5608;
    return r;
}

float fn_8008E864(G* self, int a)
{
    unsigned char buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 1, a));
    return (float)buf;
}

float fn_8008E8D4(G* self, int a)
{
    Unk8008CE64_Buf3 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 1, a));
    return (float)buf.b;
}

float fn_8008E950(G* self, int a)
{
    Unk8008CE64_Buf2 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 1, a));
    return (float)buf.b;
}

float fn_8008E9CC(G* self, int a)
{
    int v = self->m20->pfn((char*)self + self->m20->delta, 0x18, a);
    float r = fn_800799D0(lbl_8061930C, v);
    return r;
}

/* near-miss: same code; retail keeps obj, self and a in r30, r29, r28. */
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj)
{
    fn_80071E2C(self);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x3C);
}

Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064B138;
    self->m24 = 0;
    Unk8008CE64_T10* p = new (0) Unk8008CE64_T10[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x10);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags)
{
    self->m20 = lbl_8064B138;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x10);
}

void* fn_8008F08C(void* self, int a, int b, char* buf)
{
    return fn_8040B61C(buf, lbl_80619308);
}

float fn_8008F0B8()
{
    float f;
    return f = lbl_805B5628;
}

void fn_8008F7E0()
{
}

/* near-miss: same register-assignment difference as fn_8008EA20. */
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj)
{
    fn_80071E2C(self);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x10);
}

Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064A220;
    self->m24 = 0;
    Unk8008CE64_T1C* p = new (0) Unk8008CE64_T1C[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x1C);
    return self;
}

void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags)
{
    self->m20 = lbl_8064A220;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x1C);
}

int fn_8008F940(void* self)
{
    return 0;
}

int fn_8008F948(void* self)
{
    return 0;
}

unsigned fn_8008F950(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0:
            r = self->m24[i].h0;
            break;
        case 1:
            r = self->m24[i].f;
            break;
        }
    }
    return r;
}

char* fn_8008F99C(Unk8008CE64_K<Unk8008CE64_T1C>* self, int t, unsigned i, char* buf)
{
    if (i < self->m1C) {
        switch (t) {
        case 0:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x1C + 3);
            break;
        case 1:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x1C + 0xE);
            break;
        }
    }
    return buf;
}

/* near-miss: clamp arms and the store registers/address order differ (35 vs 37 slots). */
void fn_8008FA1C(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk8008CE64_E1C* e = (Unk8008CE64_E1C*)(i * 0x1C + (int)self->m24);
            if (!(v > 0xFFFF)) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFFFF;
            e->h0 = v;
            break;
        }
        case 1: {
            Unk8008CE64_E1C* e = (Unk8008CE64_E1C*)(i * 0x1C + (int)self->m24);
            if (!(v > 1)) {
                if (v < 0)
                    v = 0;
            } else
                v = 1;
            e->f = v;
            break;
        }
        }
    }
}

/* near-miss: register assignment of the parameters differs. */
void fn_8008FAA8(Unk8008CE64_K<Unk8008CE64_T1C>* self, signed char t, unsigned i, const char* str, int n)
{
    if (i < self->m1C) {
        if (n == 0)
            n = fn_8040B6A0(str);
        switch (t) {
        case 0: {
            int m = n;
            if (m > 10)
                m = 10;
            char* dst = (char*)self->m24 + i * 0x1C + 3;
            fn_8040B830(dst, str, m);
            dst[m] = 0;
            break;
        }
        case 1: {
            int m = n;
            if (m > 13)
                m = 13;
            char* dst = (char*)self->m24 + i * 0x1C + 0xE;
            fn_8040B830(dst, str, m);
            dst[m] = 0;
            break;
        }
        }
    }
}

/* near-miss: same register-assignment difference as fn_8008EA20. */
void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj)
{
    fn_80071E2C(self);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, 0x348);
}

/* near-miss: retail keeps v in r3 and the count in r10; here v moves to r10 and
 * the count takes r3, and i is reloaded from its slot in the loop. */
int fn_8008FBE8(int v)
{
    Unk8008CE64_Iter<9> it;
    int n = 0;
    int k = 0;
    do {
        if (lbl_80619738[k] == v)
            n++;
        k = it.Next();
    } while (k <= 9);
    return n;
}

int fn_8008FCC8(int t)
{
    switch (t) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 0;
    case 3:
        return 0;
    case 4:
        return 0;
    }
    return 0;
}

int fn_8008FD14(int t)
{
    switch (t) {
    case 0:
        return 0x5942;
    case 1:
        return 0x5944;
    case 2:
        return 0x5943;
    case 3:
        return 0x5945;
    case 4:
        return 0x5B05;
    }
    return 0;
}

void fn_8009010C()
{
    if (lbl_80619760 == 0)
        lbl_80619760 = operator new(0xE294, 0x100);
    fn_80534E80(lbl_80619760, lbl_805B56C0);
}

void fn_80090164()
{
    if (lbl_80619760) {
        fn_80377408(lbl_80619760);
        lbl_80619760 = 0;
    }
}

int fn_800901A4()
{
    if (lbl_80619760)
        return 1;
    return 0;
}

float fn_80090380(void* a)
{
    int v = fn_800903B8(a);
    float r = fn_80079A90(lbl_8061930C, v);
    return r;
}

void fn_800906B8()
{
    if (lbl_8061977C == 0)
        lbl_8061977C = fn_80090744((Unk8008CE64_Own*)operator new(0xC, 0));
}

void fn_80090700()
{
    if (lbl_8061977C) {
        fn_8009075C(lbl_8061977C, 3);
        lbl_8061977C = 0;
    }
}

Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    return self;
}

void fn_8009075C(Unk8008CE64_Own* self, int flags)
{
    fn_80090814(self, 1, 1);
    if (flags & 1)
        fn_80377408(self);
}

void fn_80090814(Unk8008CE64_Own* self, int a, int b)
{
    if (self->m4 != 0 && a != 0) {
        fn_803EDA0C(self->m4);
        self->m4 = 0;
    }
    if (self->m8 != 0 && b != 0) {
        fn_803EDA0C(self->m8);
        self->m8 = 0;
    }
}
