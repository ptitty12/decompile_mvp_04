/*
 * Game code, .text 0x8008CE64-0x80090880 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"
#include "game/tu_8008CE64.h"

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */
void fn_80071604(void* self);
void fn_80071688(void* self, int flags);
/* fn_80071E2C is the base-class version of these functions: it takes the same
 * (self, a, obj) and calls obj's slot 1 itself (r4/r5 used without a copy). */
void fn_80071E2C(void* self, int a, void* obj);
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




extern const char* lbl_80619764[];
extern "C" void fn_80534F64(void* obj, int a, int b, int c, int d, int e, int f);
extern "C" const char* fn_802B9300(const char* s, int a, int b, unsigned int* outn);
extern "C" void fn_80402DE4(const void* p, int n);



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

void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
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

void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
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

void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, 0x348);
}

int fn_8008FBE8(int v)
{
    int n = 0;
    int k = 0;
    Unk8008CE64_IterW<9> it;
    do {
        if (lbl_80619738[k] == v)
            n++;
        k = it.Next(k);
    } while (k <= 9);
    return n;
}

int fn_8008FC40(int v, int nth)
{
    int cnt = 0;
    int res = 10;
    Unk8008CE64_Iter<9> it;
    for (int k = 0; k <= 9; k = it.Next()) {
        if (lbl_80619738[k] == v) {
            if (cnt == nth) {
                res = k;
                break;
            }
            cnt++;
        }
    }
    return res;
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

int fn_8008FD78(int t)
{
    switch (t) {
    case 0:
        return 0;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 2;
    case 5:
        return 2;
    case 6:
        return 3;
    case 7:
        return 3;
    case 8:
        return 3;
    case 9:
        return 4;
    }
    return 5;
}

int fn_8008FE14(int t)
{
    switch (t) {
    case 0:
        return 4;
    case 1:
        return 5;
    case 2:
        return 6;
    case 3:
        return 7;
    case 4:
        return 8;
    case 5:
        return 9;
    case 6:
        return 10;
    case 7:
        return 11;
    case 8:
        return 12;
    case 9:
        return 13;
    }
    return 4;
}

int fn_8008FED8(int v)
{
    int tbl[10] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Unk8008CE64_IterW<9> it;
    for (int k = 0; k <= 9; k = it.Next(k)) {
        if (tbl[k] == v)
            return k;
    }
    return 10;
}

int fn_8008FF98(int t)
{
    switch (t) {
    case 0:
        return 0x5AA0;
    case 1:
        return 0x5AA1;
    case 2:
        return 0x5AA2;
    case 3:
        return 0x5AA3;
    case 4:
        return 0x5AA4;
    case 5:
        return 0x5AA5;
    case 6:
        return 0x5AA6;
    case 7:
        return 0x5AA7;
    case 8:
        return 0x5AA8;
    case 9:
        return 0x5AA9;
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

void fn_800901C0(int a0, int a1, int a2, int a3, int a4, int a5)
{
    if (fn_800901A4() == 1) {
        int m = *(int*)((char*)lbl_80619760 + 0xE290);
        fn_80534F64(lbl_80619760, a0, a1, a2 % m, a3, a4, a5 % m);
    }
}

int fn_80090244(int a)
{
    float z = 64.0f;
    float f = (float)a * 0.5f;
    return (int)(f + 36.0f);
}

int fn_800902B0(int t, int a)
{
    int r = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        r = s->fn_8007C514(2, a) != 0;
        break;
    case 1:
        r = s->fn_8007C770(8, a) != 0;
        break;
    case 2:
        r = s->fn_8007C994(1, a) != 0;
        break;
    case 3:
        r = s->fn_8007CBB8(6, a) != 0;
        break;
    case 4:
        r = s->fn_8007CDDC(5, a) != 0;
        break;
    }
    return r;
}

float fn_80090380(void* a)
{
    int v = fn_800903B8(a);
    float r = fn_80079A90(lbl_8061930C, v);
    return r;
}

int fn_800903B8(int t, int a)
{
    int r = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        r = s->fn_8007C514(15, a);
        break;
    case 1:
        r = s->fn_8007C770(11, a);
        break;
    case 2:
        r = s->fn_8007C994(11, a);
        break;
    case 3:
        r = s->fn_8007CBB8(9, a);
        break;
    case 4:
        r = s->fn_8007CDDC(8, a);
        break;
    }
    return r;
}

int fn_8009047C(int t, int a)
{
    int r = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        r = s->fn_8007C514(16, a);
        break;
    case 1:
        r = s->fn_8007C770(12, a);
        break;
    case 2:
        r = s->fn_8007C994(12, a);
        break;
    case 3:
        r = s->fn_8007CBB8(5, a);
        break;
    case 4:
        r = s->fn_8007CDDC(9, a);
        break;
    }
    return r;
}

void fn_80090540(int t, int a, int v)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        s->fn_8007C574(15, a, v);
        break;
    case 1:
        s->fn_8007C7D0(11, a, v);
        break;
    case 2:
        s->fn_8007C9F4(11, a, v);
        break;
    case 3:
        s->fn_8007CC18(9, a, v);
        break;
    case 4:
        s->fn_8007CE3C(8, a, v);
        break;
    }
}

void fn_800905FC(int t, int a, int v)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        s->fn_8007C574(16, a, v);
        break;
    case 1:
        s->fn_8007C7D0(12, a, v);
        break;
    case 2:
        s->fn_8007C9F4(12, a, v);
        break;
    case 3:
        s->fn_8007CC18(5, a, v);
        break;
    case 4:
        s->fn_8007CE3C(9, a, v);
        break;
    }
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

void fn_800907A4(Unk8008CE64_Own* p, int idx, int flag)
{
    void** slot = &p->m8;
    if (flag != 0)
        slot = &p->m4;
    if (*slot == 0) {
        p->m0 = idx;
        const char* r = fn_802B9300(lbl_80619764[idx], 0, 0xE, 0);
        *slot = (void*)r;
        fn_80402DE4(r, 1);
    }
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
