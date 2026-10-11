/*
 * Game code, .text 0x80084910-0x80087A58 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80084910.h"

typedef Unk80084910_T30 T30;
typedef Unk80084910_T8 T8;
typedef Unk80084910_K<T30> K30;
typedef Unk80084910_K<T8> K8;
typedef Unk80084910_VObj VObj;
typedef Unk80084910_G G;

void* operator new[](unsigned int size, int heap); /* 0x803774A8 */

void fn_80071604(void* self);
void fn_80071688(void* self, int flags);
/* fn_80071E2C is the base-class version of these functions: it takes the same
 * (self, a, obj) and calls obj's slot 1 itself (r4/r5 used without a copy). */
void fn_80071E2C(void* self, int a, void* obj);
void* fn_8007366C(const char* a, const char* b);
void fn_8040074C(void* p, int n);
extern char lbl_805B3B4C[];
extern char lbl_8064B388[];
extern char lbl_8064B318[];
extern void* lbl_8061930C;

int fn_80084660(void* a);
int fn_8008453C(int a, int b, int c, int d);
int fn_80084600(int a);
int fn_8008461C(int a);
int fn_8008462C(int a);









struct Unk80084910_Buf3 {
    unsigned short a;
    unsigned short b;
};
struct Unk80084910_Buf2 {
    unsigned char a;
    unsigned char b;
    unsigned short pad;
};
void fn_80329FA0(void* out, int v, ...);
extern double lbl_805B4438;






float fn_80079A90(void* a, int v);










extern float lbl_805B4460;







void* fn_803FFA60(void* s, int a, int n);



struct Unk80084910_N {
    void* m0;
    int m4;
};

extern char lbl_805B6B98[];
extern char lbl_805B45CC[];
extern char lbl_805B45D4[];
extern char lbl_805B45E0[];
extern char lbl_805B45E4[];
extern char lbl_805B45EC[];
extern char lbl_805B45F8[];
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_800E1AC8(void* p);







struct Unk80084910_P {
    int m0;
    int m4;
};

struct Unk80084910_R {
    char pad0[0x78];
    Unk80084910_P m78[2];
    char pad88[0x39C - 0x88];
    void* m39C;
};

extern char lbl_8064B5B8[];
void fn_800864D4(Unk80084910_R* self, int a);


struct Unk80084910_W {
    char pad0[0x58];
    int m58[1];
};



extern int lbl_80619418[];


int fn_80403060(const short* s);
void fn_8040316C(short* dst, const short* src, int n);

struct Unk80084910_Str {
    char pad0[0x204];
    short m204[1];
};


struct Unk80084910_S {
    char pad0[0x234];
    int m234;
};


extern Unk80084910_Pmf lbl_805B6B60[];

int fn_80084910(void* self, int a, int b, int c);
int fn_80084954(void* self);
int fn_80084978(void* self);
int fn_8008499C(void* self);
int fn_800849C0(int t);
K30* fn_80084A10(K30* self);
void fn_80084A8C(K30* self, int flags);
void fn_80084AE8(K30* self, unsigned i);
float fn_80084FEC(Unk80084910_PObj* o, int i, int a);
float fn_8008574C(G* self, int a);
float fn_800857B8(G* self, int a);
float fn_80085824(G* self, int a);
float fn_80085894(G* self, int a);
float fn_80085910(G* self, int a);
float fn_8008598C(G* self, int a);
void fn_800859E0(K30* self, int a, VObj* obj);
K8* fn_80085A3C(K8* self);
void fn_80085AB8(K8* self, int flags);
void fn_80085B14(K8* self, unsigned i);
int fn_80085B50(void* self);
int fn_80085B58(void* self);
int fn_80085B60(void* self);
int fn_80085B68(void* self, int a, int b, int c);
float fn_80085B70();
void fn_80085B8C();
void fn_80085B90();
void fn_80085B94(K8* self, int a, VObj* obj);
T8* fn_80085BF0(K8* self, int i);
T8* fn_80085C00(K8* self, int i);
void* fn_80085EF8(void* self, int a);
int fn_80085FB0();
void fn_80085FF8(Unk80084910_N* self, int key);
void fn_80086030(Unk80084910_N* self, char* buf);
void fn_80086078(Unk80084910_N* self, char* buf);
void fn_800860E0(Unk80084910_N* self, char* buf);
void fn_80086140(Unk80084910_N* self, char* buf);
void fn_800861A8(Unk80084910_N* self, char* buf);
Unk80084910_R* fn_80086210(Unk80084910_R* self);
void fn_80086D24(Unk80084910_W* self, int i, int v);
int fn_80086D34(Unk80084910_W* self, int i);
int fn_80086DD8(void* self, unsigned i);
void fn_80086E58(Unk80084910_Str* self, const short* str);
void fn_80087A50(Unk80084910_S* self, int v);












































void fn_80403060_(void);
struct Unk80084910_Q {
    char pad0[0x88];
    short m88[1];
};

int fn_80084910(void* self, int a, int b, int c);
int fn_80084954(void* self);
int fn_80084978(void* self);
int fn_8008499C(void* self);
int fn_800849C0(int t);
K30* fn_80084A10(K30* self);
void fn_80084A8C(K30* self, int flags);
void fn_80084AE8(K30* self, unsigned i);
float fn_80084FEC(Unk80084910_PObj* o, int i, int a);
float fn_8008574C(G* self, int a);
float fn_800857B8(G* self, int a);
float fn_80085824(G* self, int a);
float fn_80085894(G* self, int a);
float fn_80085910(G* self, int a);
float fn_8008598C(G* self, int a);
void fn_800859E0(K30* self, int a, VObj* obj);
K8* fn_80085A3C(K8* self);
void fn_80085AB8(K8* self, int flags);
void fn_80085B14(K8* self, unsigned i);
int fn_80085B50(void* self);
int fn_80085B58(void* self);
int fn_80085B60(void* self);
int fn_80085B68(void* self, int a, int b, int c);
float fn_80085B70();
void fn_80085B8C();
void fn_80085B90();
void fn_80085B94(K8* self, int a, VObj* obj);
T8* fn_80085BF0(K8* self, int i);
T8* fn_80085C00(K8* self, int i);
void* fn_80085EF8(void* self, int a);
int fn_80085FB0();
void fn_80085FF8(Unk80084910_N* self, int key);
void fn_80086030(Unk80084910_N* self, char* buf);
void fn_80086078(Unk80084910_N* self, char* buf);
void fn_800860E0(Unk80084910_N* self, char* buf);
void fn_80086140(Unk80084910_N* self, char* buf);
void fn_800861A8(Unk80084910_N* self, char* buf);
Unk80084910_R* fn_80086210(Unk80084910_R* self);
void fn_80086D24(Unk80084910_W* self, int i, int v);
int fn_80086D34(Unk80084910_W* self, int i);
int fn_80086DD8(void* self, unsigned i);
void fn_80086E58(Unk80084910_Str* self, const short* str);
/* near-miss: retail forms the destination as (i*34 + 0x88) from self and the
 * terminator offset as (n-1)*2 + i*34 from self+0x88; one slot of address
 * arithmetic differs. */
void fn_80086F6C(Unk80084910_Q* self, int i, const short* str);
void fn_800879B8(void* out, int a, VObj* obj);
void fn_80087A50(Unk80084910_S* self, int v);

void* fn_8040B61C(char* dst, const char* src);


extern int lbl_806193B8[];
void fn_804031BC(short* dst, const char* src);


extern "C" double fn_804103C0(double x);


extern int lbl_805B6B90[];
int fn_8040B6A0(const char* s);
void fn_8040B830(char* dst, const char* src, int n);


extern int* lbl_8061977C;
const short* fn_80090880(void* names, int id);




struct Unk80084910_S4 {
    unsigned short a;
    unsigned short b;
};
struct Unk80084910_Rec {
    unsigned c0 : 8;
    unsigned f1 : 6;
    unsigned f2 : 3;
    unsigned rest : 15;
};
int fn_80329FA0(int* out, int c, ...);


int fn_80084910(void* self, int a, int b, int c)
{
    return fn_8008453C(fn_80084660(self), a, b, c);
}

int fn_80084954(void* self)
{
    return fn_80084600(fn_80084660(self));
}

int fn_80084978(void* self)
{
    return fn_8008461C(fn_80084660(self));
}

int fn_8008499C(void* self)
{
    return fn_8008462C(fn_80084660(self));
}

int fn_800849C0(int t)
{
    switch (t) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    }
    return 0;
}

K30* fn_80084A10(K30* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064B388;
    self->m24 = 0;
    T30* p = new (0) T30[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x30);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_80084A8C(K30* self, int flags)
{
    self->m20 = lbl_8064B388;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_80084AE8(K30* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x30);
}

unsigned fn_80084C50(Unk80084910_PackTabA* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].a00; break;
        case 1: r = self->m24[i].a01; break;
        case 2: r = self->m24[i].a02; break;
        case 3: r = self->m24[i].a03; break;
        case 4: r = self->m24[i].a04; break;
        case 5: r = self->m24[i].a05; break;
        case 6: r = self->m24[i].a06; break;
        case 7: r = self->m24[i].a07; break;
        case 8: r = self->m24[i].a08; break;
        case 9: r = self->m24[i].a09; break;
        case 10: r = self->m24[i].a0A; break;
        case 11: r = self->m24[i].a0B; break;
        case 12: r = self->m24[i].a0C; break;
        case 13: r = self->m24[i].a0D; break;
        case 14: r = self->m24[i].a0E; break;
        case 15: r = self->m24[i].a0F; break;
        case 16: r = self->m24[i].a10; break;
        case 17: r = self->m24[i].a11; break;
        case 18: r = self->m24[i].a12; break;
        case 19: r = self->m24[i].a13; break;
        case 20: r = self->m24[i].a14; break;
        case 21: r = self->m24[i].a15; break;
        }
    }
    return r;
}

char* fn_80084F6C(K30* self, int t, unsigned i, char* out)
{
    if (i < self->m1C) {
        switch (t) {
        case 0:
            fn_8040B61C(out, (char*)self->m24 + i * 0x30 + 0x13);
            break;
        case 1:
            fn_8040B61C(out, (char*)self->m24 + i * 0x30 + 0x1F);
            break;
        }
    }
    return out;
}

float fn_80084FEC(Unk80084910_PObj* o, int i, int a)
{
    float r = (o->*lbl_805B6B60[i])(a);
    return r;
}

void fn_80085084(Unk80084910_PackTabA* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0xFFFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFFFF;
            p->a00 = v;
            break;
        }
        case 1: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x7FFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7FFF;
            p->a01 = v;
            break;
        }
        case 2: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->a02 = v;
            break;
        }
        case 3: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->a03 = v;
            break;
        }
        case 4: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFF;
            p->a04 = v;
            break;
        }
        case 5: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a05 = v;
            break;
        }
        case 6: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x3FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3FF;
            p->a06 = v;
            break;
        }
        case 7: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->a07 = v;
            break;
        }
        case 8: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a08 = v;
            break;
        }
        case 9: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->a09 = v;
            break;
        }
        case 10: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->a0A = v;
            break;
        }
        case 11: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->a0B = v;
            break;
        }
        case 12: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->a0C = v;
            break;
        }
        case 13: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->a0D = v;
            break;
        }
        case 14: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->a0E = v;
            break;
        }
        case 15: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a0F = v;
            break;
        }
        case 16: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->a10 = v;
            break;
        }
        case 17: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->a11 = v;
            break;
        }
        case 18: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->a12 = v;
            break;
        }
        case 19: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->a13 = v;
            break;
        }
        case 20: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->a14 = v;
            break;
        }
        case 21: {
            Unk80084910_PackA* p = (Unk80084910_PackA*)(i * 48 + (int)self->m24);
            int w;
            if (v <= 0x64) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0x64;
            p->a15 = w;
            break;
        }
        }
    }
}

void fn_80085660(K30* self, signed char t, unsigned i, const char* str, int n)
{
    if (i < self->m1C) {
        if (n <= 0)
            n = fn_8040B6A0(str);
        int mx = lbl_805B6B90[t] - 1;
        if (n > mx)
            n = mx;
        switch (t) {
        case 0: {
            int o = i * 0x30;
            fn_8040B830((char*)self->m24 + o + 0x13, str, n);
            char* d = (char*)(o + (int)self->m24 + 0x13);
            d[n] = 0;
            break;
        }
        case 1: {
            int o = i * 0x30;
            fn_8040B830((char*)self->m24 + o + 0x1F, str, n);
            char* d = (char*)(o + (int)self->m24 + 0x1F);
            d[n] = 0;
            break;
        }
        }
    }
}

float fn_8008574C(G* self, int a)
{
    float r = (float)(self->m20->pfn((char*)self + self->m20->delta, 3, a) + 0x30);
    return r;
}

float fn_800857B8(G* self, int a)
{
    float r = (float)(self->m20->pfn((char*)self + self->m20->delta, 4, a) + 0x64);
    return r;
}

float fn_80085824(G* self, int a)
{
    unsigned char buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf;
}

float fn_80085894(G* self, int a)
{
    Unk80084910_Buf3 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

float fn_80085910(G* self, int a)
{
    Unk80084910_Buf2 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

float fn_8008598C(G* self, int a)
{
    int v = self->m20->pfn((char*)self + self->m20->delta, 0xF, a);
    float r = fn_80079A90(lbl_8061930C, v);
    return r;
}

void fn_800859E0(K30* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x30);
}

K8* fn_80085A3C(K8* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064B318;
    self->m24 = 0;
    T8* p = new (0) T8[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 8);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_80085AB8(K8* self, int flags)
{
    self->m20 = lbl_8064B318;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_80085B14(K8* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 8);
}

int fn_80085B50(void* self)
{
    return 0;
}

int fn_80085B58(void* self)
{
    return 0;
}

int fn_80085B60(void* self)
{
    return 0;
}

int fn_80085B68(void* self, int a, int b, int c)
{
    return c;
}

float fn_80085B70()
{
    float f;
    return f = lbl_805B4460;
}

void fn_80085B8C()
{
}

void fn_80085B90()
{
}

void fn_80085B94(K8* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 8);
}

T8* fn_80085BF0(K8* self, int i)
{
    return &self->m24[i];
}

T8* fn_80085C00(K8* self, int i)
{
    return &self->m24[i];
}

void* fn_80085EF8(void* self, int a)
{
    fn_803FFA60(self, a, 8);
    return self;
}

/* near-miss (2 slots): retail emits addi r3,r1,8 before li r4,1 for the first fn_80329FA0 call. */
struct S4D {
    unsigned short a;
    unsigned short b;
    ~S4D() {}
};
extern "C" Unk80084910_Rec* fn_80085F2C(Unk80084910_Rec* out, char* in)
{
    S4D s1;
    S4D s2;
    fn_80329FA0((int*)&s1, 1);
    int base = s1.b;
    fn_80329FA0((int*)&s2, *(unsigned short*)(in + 1));
    int d = s2.b - base;
    out->c0 = d;
    out->f1 = (*(unsigned*)(in + 0xC) >> 13) & 0x7F;
    out->f2 = (*(unsigned*)(in + 0xC) >> 10) & 7;
    return out;
}

int fn_80085FB0()
{
    return 4;
}

int fn_80085FB8(int i)
{
    int tbl[4] = { 0x12, 0x13, 0x14, 0x15 };
    return tbl[i];
}

void fn_80085FF8(Unk80084910_N* self, int key)
{
    for (int i = 0; i < 16; i++) {
        if (lbl_805B6B98[i] == key) {
            self->m4 = i;
            return;
        }
    }
}

void fn_80086030(Unk80084910_N* self, char* buf)
{
    fn_804089B4(buf, lbl_805B45CC, fn_800E1AC8(self->m0));
}

void fn_80086078(Unk80084910_N* self, char* buf)
{
    fn_804089B4(buf, lbl_805B45D4, fn_800E1AC8(self->m0), lbl_805B6B98[self->m4], lbl_805B45E0);
}

void fn_800860E0(Unk80084910_N* self, char* buf)
{
    fn_804089B4(buf, lbl_805B45E4, fn_800E1AC8(self->m0), lbl_805B6B98[self->m4]);
}

void fn_80086140(Unk80084910_N* self, char* buf)
{
    fn_804089B4(buf, lbl_805B45EC, fn_800E1AC8(self->m0), lbl_805B6B98[self->m4], lbl_805B45E0);
}

void fn_800861A8(Unk80084910_N* self, char* buf)
{
    fn_804089B4(buf, lbl_805B45F8, fn_800E1AC8(self->m0), lbl_805B6B98[self->m4], lbl_805B45E0);
}

Unk80084910_R* fn_80086210(Unk80084910_R* self)
{
    self->m39C = lbl_8064B5B8;
    Unk80084910_P* p = self->m78;
    int n = 1;
    do {
        p->m0 = 0;
        p->m4 = 0;
        p++;
    } while (n-- != 0);
    fn_800864D4(self, 1);
    return self;
}

void fn_80086D24(Unk80084910_W* self, int i, int v)
{
    self->m58[i] = v;
}

int fn_80086D34(Unk80084910_W* self, int i)
{
    return self->m58[i];
}

/* near-miss (3 slots, register only): retail holds the stored value in r9, here r0. */
void fn_80086D44(char* base, int idx, float f)
{
    float t = (float)fn_804103C0(f * 255.0f);
    char* p = base + 4;
    int v = !(t > 255.0f) ? (int)(t >? 0.0f) : 255;
    p[idx] = v;
}

int fn_80086DD8(void* self, unsigned i)
{
    if (i <= 0x17)
        return lbl_80619418[i];
    return 0;
}

extern "C" void fn_80086DFC(Unk80084910_Str* self, unsigned i)
{
    *(unsigned*)((char*)self + 0x22C) = i;
    *(int*)((char*)self + 0x74) = fn_80086DD8(self, i);
    short buf[18];
    fn_804031BC(buf, (const char*)lbl_806193B8[i]);
    fn_80086E58(self, buf);
}

void fn_80086E58(Unk80084910_Str* self, const short* str)
{
    int n = fn_80403060(str) + 1;
    if (n > 0x12)
        n = 0x12;
    fn_8040316C(self->m204, str, n);
    self->m204[n - 1] = 0;
}

extern "C" void fn_80086EC0(Unk80084910_Q* self, int slot, int v)
{
    int tbl[4] = { 0x261B, 0x261C, 0x3959, 0x395A };
    char* b = (char*)self + 0x6C;
    int o = slot * 4;
    *(int*)(b + o) = v;
    if (v != -1) {
        int ok = 1;
        if (*lbl_8061977C == 0)
            ok = 0;
        if (ok)
            fn_80086F6C(self, v, fn_80090880(lbl_8061977C, tbl[v]));
    }
}

void fn_80086F6C(Unk80084910_Q* self, int i, const short* str)
{
    int n = fn_80403060(str) + 1;
    if (n > 0x10)
        n = 0x10;
    int off = i * 0x22;
    fn_8040316C((short*)((char*)self + (off + 0x88)), str, n);
    char* b = (char*)self + 0x88;
    int o2 = (n - 1) * 2 + off;
    *(short*)(b + o2) = 0;
}

void fn_800879B8(void* out, int a, VObj* obj)
{
    obj->m4->pfn((char*)obj + obj->m4->delta, a, out, 4);
    obj->m4->pfn((char*)obj + obj->m4->delta, a, (char*)out + 4, 5);
    obj->m4->pfn((char*)obj + obj->m4->delta, a, (char*)out + 0xA, 2);
}

void fn_80087A50(Unk80084910_S* self, int v)
{
    self->m234 = v;
}
