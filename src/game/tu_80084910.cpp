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

float fn_80084FEC(Unk80084910_PObj* o, int i, int a)
{
    float r = (o->*lbl_805B6B60[i])(a);
    return r;
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

int fn_80085FB0()
{
    return 4;
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

int fn_80086DD8(void* self, unsigned i)
{
    if (i <= 0x17)
        return lbl_80619418[i];
    return 0;
}

void fn_80086E58(Unk80084910_Str* self, const short* str)
{
    int n = fn_80403060(str) + 1;
    if (n > 0x12)
        n = 0x12;
    fn_8040316C(self->m204, str, n);
    self->m204[n - 1] = 0;
}

/* near-miss: retail forms the destination as (i*34 + 0x88) from self and the
 * terminator offset as (n-1)*2 + i*34 from self+0x88; one slot of address
 * arithmetic differs. */
void fn_80086F6C(Unk80084910_Q* self, int i, const short* str)
{
    int n = fn_80403060(str) + 1;
    if (n > 0x10)
        n = 0x10;
    short* dst = (short*)((char*)self + i * 0x22 + 0x88);
    fn_8040316C(dst, str, n);
    dst[n - 1] = 0;
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
