/*
 * Game code, .text 0x8014F47C-0x801527C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct Unk50Ent { char m0; char pad1[8]; char m9; char pad2[0x4C - 0xA]; int m4C; };
void* operator new(unsigned int size, int heap);
extern int lbl_806EF9B4;
struct Unk80151FA0_Obj { char pad0[0x48]; int m48; char pad4C[8]; int m54; int m58; };
struct UnkAt20F2 { char pad0[0x20]; float m20; };
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
    void fn_8037B728(const char* name, const char* name2, void* list, int flags);
    int m0;
};
extern const char lbl_805C5E58[];
extern const char lbl_805C7BC4[];
extern const char lbl_805C7994[];
class Unk80359B48 {
public:
    void fn_8037B584(const char* name, void* data, int len, const char* names);
    void fn_8037B458(const char* name, int* field, const void* a, const void* b);
    void fn_8037B458(const char* name, int* field, int a, const char* b);
    void fn_8037B50C(const char* name, float* field, const char* range, int a);
    void fn_8037B5C0(const char* name, int* field, const char* typeList);
    void fn_8037B548(const char* name, int a);
    void fn_8037B548(const char* name, const char* def);
    void fn_8037B7E4(const char* group);
    void fn_8037B6B0(const char* name, int* field, const char* typeList);
    void fn_8037B7E8(const char* group);
    void fn_8037B830(const char* group);
};

extern const char lbl_8065EB20[];
extern const char lbl_8065E968[];
extern const char lbl_8065E800[];
extern const char lbl_8065EB48[];
extern const char lbl_8065EAA0[];
extern const char lbl_8065EB00[];
extern const float lbl_805C7970;
extern const float lbl_805C7528;
struct Unk150E1C_V3 { float x, y, z; };
extern Unk150E1C_V3 lbl_806055AC;

struct KnotBuf;

struct Unk8027C728_Goal;
struct Unk8027C728_Player { char pad0[0x934]; Unk8027C728_Goal* m934; };
int fn_8027D574(Unk8027C728_Goal* g);
int fn_8027D670(Unk8027C728_Goal* g, Unk8027C728_Player* p, int flag);
struct Unk802D5618;
void fn_802D5618(Unk802D5618* o);
struct Unk8019F8C0_Owner { char pad0[0x554]; void* m554; };
struct Ent3C { char pad0[0x3C]; Unk802D5618* m3C; };
struct Ctx8015 { char pad0[0xA4C]; Unk8019F8C0_Owner* mA4C; Ent3C* mA50; Ent3C* mA54; };
void* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
extern const float lbl_805C7CD4;
struct Sub8061FEDC { int m0; int m4; int m8; float mC; };
struct Obj8061FEDC { char pad0[0x40]; Sub8061FEDC m40; };
extern Obj8061FEDC* lbl_8061FEDC;
struct Self8015272C { int m0; int m4; int m8; };

extern const char lbl_8065E8F0[];
extern const float lbl_805C7A28;
class Unk802CF484 {
public:
    Unk802CF484();
    char pad0[0x1C];
};
struct Obj80151C40 {
    const void* m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    int m18;
    int m1C;
    float m20;
    char pad24[0x1C];
    int m40;
    int m44;
    char pad48[4];
    int m4C;
    int m50;
    char pad54[4];
    int m58;
    char m5C[12];
};

extern int lbl_8068B870;
extern int lbl_8068B874;
extern int lbl_8068B878;

extern const char lbl_805C79A0[];
extern const float lbl_805C79DC;
extern const float lbl_805C79E8;
struct Unk8016C1C4_List {
    void fn_8016C620(int idx, int p);
};
struct Self80151B48 { int m0; int m4; float m8; int mC; };

class Obj801510A8 {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11(int a, int b, float x, float y, float z);
    virtual int s12(int a, int b, float x, float y, float z);
    virtual float s13(float t);
};
struct Ent801510A8 {
    void* m0;
    int m4;
    float m8;
    float mC;
    Obj801510A8* m10;
};
typedef void* (*Create801513C4_t)(void*, void*, int, int);
struct Self801510A8 {
    int m0;
    int m4;
    Ent801510A8* m8;
};
extern const float lbl_805C75B4;
extern const float lbl_805C75B8;

extern const char lbl_805C7974[];
extern const char lbl_805C797C[];
extern const char lbl_805C7988[];
extern const char lbl_805C770C[];
extern const char lbl_805C771C[];
extern const char lbl_805C7890[];
extern const char lbl_805C7BE8[];
extern const char lbl_805C7BEC[];
extern const char lbl_805C7BF8[];
extern const char lbl_805C7C04[];
extern const char lbl_805C7C10[];
extern const char lbl_805C7C1C[];
extern const char lbl_805C6240[];
extern const char lbl_805C7C34[];
extern const char lbl_805C7C44[];
extern const char lbl_805C7C54[];
extern const char lbl_805C7C64[];
extern const char lbl_805C7C7C[];
extern const char lbl_805C7CB0[];
extern const char lbl_805C7CB8[];
extern const char lbl_805C7BCC[];
extern const char lbl_805C7B5C[];
extern const char lbl_805C7B68[];
extern const char lbl_805C60F8[];
extern const char lbl_805C7B78[];
extern const char lbl_805C7B84[];
extern const char lbl_805C7B90[];
extern const char lbl_805C7CBC[];

extern const char lbl_805C752C[];
extern const char lbl_805C5FD4[];
extern const char lbl_805C7530[];
extern const char lbl_805C7540[];
extern const char lbl_805C7544[];
extern const char lbl_805C7548[];
extern const char lbl_805C755C[];
extern const char lbl_805C7564[];
extern const char lbl_805C7574[];
extern const char lbl_805C7580[];
extern const char lbl_805C758C[];
extern const char lbl_805C75A0[];

inline int GetW(char* base, int off) { return *(int*)(base + off); }

inline void SetM4C(Sub8061FEDC* o, float v)
{
    o->mC = v;
}

inline void* operator new(unsigned int, void* p) { return p; }

struct Unk801522E4_Obj { const void* m0; char m4; };
struct UnkAt13B { char pad0[0x13]; char m13; };
struct Unk8015242C_Obj { int m0; int m4; float m8; float mC; int m10; float m14; float m18; };

extern const char lbl_805C75C0[];
extern const char lbl_805C75C4[];
extern const char lbl_805C75D0[];
extern const char lbl_805C75E4[];
extern const char lbl_805C75EC[];
extern const char lbl_805C7620[];
extern const char lbl_805C7634[];
extern const char lbl_805C7640[];
extern const char lbl_805C764C[];
extern const char lbl_805C76F8[];
extern const char lbl_805C7728[];
extern const char lbl_805C7864[];
extern const char lbl_805C786C[];
extern const char lbl_805C7878[];
extern const char lbl_805C7884[];
extern const char* lbl_8061BD80;
int sprintf(char* buf, const char* fmt, ...);
extern "C" {
unsigned fn_8014D8AC(void* rng, int max, const char* file, int line);
void fn_802D5A64(Unk802D5618* o, int a, int b, int c, void* d, int e, float f1, float f2, float f3, float f4, float f5, float f6);
void fn_80244A64(void* p, int a, int b);
void fn_80244BA4(void* p, int a, int b);
void fn_80359A40(int* p);
int fn_8040B574(const char* a, const char* b);
char* fn_8040B830(char* dst, const char* src, unsigned n);
void fn_8033CCE0(void* p);
void fn_803599F8(void* p, int c);
void fn_8037B424(void* p, int c);
void fn_80151048(KnotBuf* p, int c);
void fn_8014F47C(Unk50Ent* p);
int fn_8014F530(void* self, int c);
int fn_80150D8C();
int fn_80150D98();
void fn_80150DA4();
void fn_80150DC4();
void fn_80150DF0();
void* fn_80150F90();
void fn_80150FC0(void* p);
void fn_801519A4();
void* fn_801519A8();
void fn_801519D8(void* p);
char* fn_80151A18(char* p, int i);
int fn_80151A28(char* p, int i);
int fn_80151A38(char* p, int i);
void* fn_80151C10();
void fn_80151FA0(Unk80151FA0_Obj* p);
float fn_80152064(UnkAt20F2* p, float f);
void* fn_801522B4();
void* fn_801522E4(void* self);
void fn_8015238C(float a, float b, float c);
void fn_801523A4(UnkAt13B* p);
void* fn_801523B0();
void* fn_801523E0(void* self);
void fn_8015242C(Unk8015242C_Obj* p);
void* fn_80152580();
void fn_801525B0(void* p);
void fn_80152728();
extern int lbl_8061B880;
void fn_80149F6C();
void fn_8014FC50(int, int);
void* fn_80150E1C(void*);
void* fn_8037C7FC();
void fn_8037CE98(void*, unsigned, void*, int);
void* fn_80151684(void*);
void* fn_80151A48(void*);
void fn_8033CD74(void*);
void* fn_80151C40(void*);
extern const char lbl_8065E878[];
extern const char lbl_8065EA40[];
extern const float lbl_805C7BE4;

inline void SetW(char* base, int off, int v) { *(int*)(base + off) = v; }

void fn_8014F47C(Unk50Ent* p)
{
    Unk50Ent* b = p;
    int off = 0;
    for (int i = 0; i < 8; i++) {
        p->m9 = 0;
        p->m0 = 0;
        SetW((char*)b + 0x4C, off, 0);
        p++;
        off += 0x50;
    }
}

void fn_8014F4B4(Unk50Ent* p, char* s)
{
    if (fn_8040B574(s, lbl_805C5E58) != 0) {
        int a = (int)p;
        int end = a + 0x230;
        while (a <= end) {
            char c = *(char*)a;
            if (c == 0) {
                fn_8040B830((char*)a, s, 9);
                *((char*)a + 8) = c;
                break;
            }
            a += 0x50;
        }
    }
}

int fn_8014F530(void* self, int c)
{
    int t = c - 0x30;
    int r = c - 0x57;
    if ((unsigned char)t <= 9) {
        r = t;
    }
    return r;
}

char fn_8014F54C(void* self, char a, char b, int* carry)
{
    int t = fn_8014F530(self, a);
    int s = t + fn_8014F530(self, b) + *carry;
    *carry = s / 16;
    s = s % 16;
    return s <= 9 ? s + 0x30 : s + 0x57;
}

void fn_8014F5D4(void* self, char* a, char* b, char* out)
{
    int carry = 0;
    for (int i = 7; i >= 0; i--) {
        out[i] = fn_8014F54C(self, a[i], b[i], &carry);
    }
    out[8] = 0;
}

int fn_8014F644(void* self, unsigned char* s)
{
    int n = 0;
    int i = 0;
    if (s[n] == ' ') {
        do {
            i++;
            n++;
            if (i > 255) break;
        } while (s[i] == ' ');
    }
    return n > 0x18;
}

int fn_8014F684(Unk50Ent* base, const char* a, const char* b)
{
    int found = 0;
    int i = 0;
    Unk50Ent* p = base;
    int off = 0;
    do {
        if (GetW((char*)base + 0x4C, off) == 0 && p->m0 != 0) {
            found = 1;
            if (fn_8040B574(a, (char*)p) < 0 && fn_8040B574(b, (char*)p) > 0) {
                return i;
            }
        }
        i++;
        p++;
        off += 0x50;
    } while (i <= 7);
    return found != 0 ? -1 : -2;
}

int fn_80150D8C() { return lbl_8061B880; }

int fn_80150D98() { return 0xA22DD41B; }

void fn_80150DA4() { fn_80149F6C(); }

void fn_80150DC4() { fn_8014FC50(0x1, 0xFFFF); }

void fn_80150DF0() { fn_8014FC50(0x0, 0xFFFF); }

struct Unk80150E1C_Obj { const void* m0; Unk150E1C_V3 m4; float m10; };

void* fn_80150E1C(void* self)
{
    new (self) Unk8037B3E8(0x149EF3D8);
    Unk80150E1C_Obj* p = (Unk80150E1C_Obj*)self;
    p->m0 = lbl_8065EB48;
    p->m4 = lbl_806055AC;
    p->m10 = lbl_805C7528;
    return p;
}

void fn_80150E90(Unk80359B48* self)
{
    self->fn_8037B7E4(lbl_805C752C);
    self->fn_8037B50C(lbl_805C5FD4, (float*)((char*)self + 4), lbl_805C7530, 0);
    self->fn_8037B50C(lbl_805C7540, (float*)((char*)self + 8), lbl_805C7530, 0);
    self->fn_8037B50C(lbl_805C7544, (float*)((char*)self + 0xC), lbl_805C7530, 0);
    self->fn_8037B548(lbl_805C7548, lbl_805C755C);
    self->fn_8037B548(lbl_805C7564, lbl_805C755C);
    self->fn_8037B50C(lbl_805C7574, (float*)((char*)self + 0x10), lbl_805C7580, 0);
    self->fn_8037B548(lbl_805C758C, lbl_805C7574);
    self->fn_8037B548(lbl_805C75A0, lbl_805C7574);
}

void* fn_80150F90() { return fn_80150E1C(operator new(0x14, lbl_806EF9B4)); }

void fn_80150FC0(void* p) { fn_8037CE98(fn_8037C7FC(), 0x149EF3D8, p, 0x0); }

struct KnotBuf { const void* m0; void* m4; char* m8; int mC; };

extern "C" void fn_80356798(void* p);

extern const char lbl_8065EB20[];

extern "C" KnotBuf* fn_80151000(KnotBuf* p)
{
    fn_80356798(p);
    p->m4 = 0;
    p->m0 = lbl_8065EB20;
    p->m8 = 0;
    return p;
}

void fn_80151048(KnotBuf* p, int c)
{
    p->m0 = lbl_8065EB20;
    if (p->m8 != 0) {
        delete[] p->m8;
        p->m8 = 0;
    }
    if (c & 1) {
        delete p;
    }
}

float fn_801510A8(Self801510A8* self, int start, float t)
{
    float sum = lbl_805C75B4;
    int any = 0;
    for (int i = start; i < self->m4; i++) {
        Obj801510A8* o = self->m8[i].m10;
        if (o != 0) {
            any = 1;
            float v = lbl_805C75B4;
            if (i == start) {
                v = t;
            }
            sum += o->s13(v);
        }
    }
    if (any != 0) {
        return sum;
    }
    return lbl_805C75B8;
}

int fn_801513C4(Self801510A8* self, int a, int b, float t, int idx, int flag)
{
    if (self->m4 == 0) {
        return 3;
    }
    int i;
    for (i = 0; i < self->m4; i++) {
        if (self->m8[i].m10 == 0) {
            void* mgr = fn_8037C7FC();
            self->m8[i].m10 = (Obj801510A8*)((Create801513C4_t)fn_8037CE98)(mgr, self->m8[i].m0, self->m8[i].m4, 0);
        }
    }
    if (idx >= 0 && idx < self->m4) {
        float x = self->m8[idx].m8;
        float y = self->m8[idx].mC;
        if (flag != 0) {
            self->m8[idx].m10->s11(a, b, x, y, t);
        }
        if (self->m8[idx].m10->s12(a, b, x, y, t) != 0) {
            return 1;
        }
        return 0;
    }
    return 2;
}

void fn_8015152C(Unk8027C728_Player* p, int a)
{
    Unk8027C728_Goal* g = p->m934;
    if (g != 0) {
        if (fn_8027D574(g) == 1 && fn_8027D670(g, p, 0) != 0) {
            fn_80244A64(p, 0, 0);
        }
    }
    fn_80244BA4(p, a, 1);
}

void fn_801515AC(int* a, int* b, int* c)
{
    switch (lbl_8068B870) {
    case 0:
        *a = 1;
        break;
    case 1:
        *a = 2;
        break;
    case 2:
        *a = 3;
        break;
    default:
        *a = 2;
        break;
    }
    switch (lbl_8068B874) {
    case 0:
        *b = 1;
        break;
    case 1:
        *b = 2;
        break;
    case 2:
        *b = 3;
        break;
    default:
        *b = 2;
        break;
    }
    switch (lbl_8068B878) {
    case 0:
        *c = 4;
        break;
    case 1:
        *c = 5;
        break;
    case 2:
        *c = 10;
        break;
    default:
        *c = 5;
        break;
    }
}

struct Unk80151684_Ent { int m0; int m4; KnotBuf m8; };
struct Unk80151684_Obj { const void* m0; KnotBuf m4; KnotBuf m14; const void* m24; Unk80151684_Ent m28[13]; };

void* fn_80151684(void* self)
{
    new (self) Unk8037B3E8(0x916112DD);
    Unk80151684_Obj* p = (Unk80151684_Obj*)self;
    Unk80151684_Ent* e = p->m28;
    int k = 12;
    p->m0 = lbl_8065EAA0;
    fn_80151000(&p->m4);
    fn_80151000(&p->m14);
    fn_80356798(&p->m24);
    p->m24 = lbl_8065EB00;
    do {
        e->m0 = 0;
        e->m4 = -1;
        fn_80151000(&e->m8);
        e++;
    } while (k-- != 0);
    return p;
}

void fn_8015171C(Unk80359B48* self)
{
    char buf[100];
    self->fn_8037B7E4(lbl_805C75C0);
    self->fn_8037B7E8(lbl_805C75C4);
    ((Unk8037B3E8*)self)->fn_8037B728(lbl_805C75D0, lbl_805C75E4, (char*)self + 0x24, (int)lbl_805C75EC);
    self->fn_8037B830(lbl_805C75C4);
    self->fn_8037B7E8(lbl_805C7620);
    int i = 0;
    ((Unk8037B3E8*)self)->fn_8037B728(lbl_805C7634, lbl_805C7640, (char*)self + 4, (int)lbl_805C764C);
    self->fn_8037B830(lbl_805C7620);
    self->fn_8037B7E8(lbl_805C76F8);
    ((Unk8037B3E8*)self)->fn_8037B728(lbl_805C770C, lbl_805C771C, (char*)self + 0x14, (int)lbl_805C7728);
    self->fn_8037B830(lbl_805C76F8);
    do {
        int n = i + 1;
        sprintf(buf, lbl_805C7864, n);
        self->fn_8037B7E8(buf);
        sprintf(buf, lbl_805C786C, n);
        char* e = (char*)self + (i * 0x18 + 0x28);
        self->fn_8037B458(buf, (int*)e, lbl_805C60F8, lbl_805C6240);
        sprintf(buf, lbl_805C7878, n);
        self->fn_8037B6B0(buf, (int*)(e + 4), lbl_8061BD80);
        sprintf(buf, lbl_805C7884, n);
        ((Unk8037B3E8*)self)->fn_8037B728(lbl_805C770C, buf, e + 8, (int)lbl_805C7890);
        sprintf(buf, lbl_805C7864, n);
        self->fn_8037B830(buf);
        i = n;
    } while (i <= 12);
}

void fn_80151910(void* sv, int c)
{
    Unk80151684_Obj* self = (Unk80151684_Obj*)sv;
    Unk80151684_Ent* begin = self->m28;
    self->m0 = lbl_8065EAA0;
    if (begin != 0) {
        Unk80151684_Ent* end = begin + 13;
        if (begin != end) {
            do {
                end--;
                fn_803599F8(end, 0);
            } while (begin != end);
        }
    }
    self->m24 = lbl_8065EB00;
    fn_80151048(&self->m14, 2);
    fn_80151048(&self->m4, 2);
    fn_8037B424(self, c);
}

void fn_801519A4() {}

void* fn_801519A8() { return fn_80151684(operator new(0x160, lbl_806EF9B4)); }

void fn_801519D8(void* p) { fn_8037CE98(fn_8037C7FC(), 0x916112DD, p, 0x0); }

char* fn_80151A18(char* p, int i)
{
    return (char*)(i * 0x18 + (int)p + 0x30);
}

int fn_80151A28(char* p, int i)
{
    char* b = p + 0x28;
    int o = i * 0x18;
    return *(int*)(b + o);
}

int fn_80151A38(char* p, int i)
{
    char* b = p + 0x2C;
    int o = i * 0x18;
    return *(int*)(b + o);
}

struct Unk80151A48_Obj { const void* m0; int m4; float m8; KnotBuf mC; };

void* fn_80151A48(void* self)
{
    new (self) Unk8037B3E8(0x323DA6EA);
    Unk80151A48_Obj* p = (Unk80151A48_Obj*)self;
    p->m0 = lbl_8065E968;
    fn_80151000(&p->mC);
    p->m4 = 0;
    p->m8 = lbl_805C7970;
    return p;
}

void fn_80151AA8(Unk80359B48* self)
{
    self->fn_8037B458(lbl_805C7974, (int*)((char*)self + 4), 0, 0);
    self->fn_8037B50C(lbl_805C797C, (float*)((char*)self + 8), lbl_805C7988, 0);
    ((Unk8037B3E8*)self)->fn_8037B728(lbl_805C770C, lbl_805C771C, (char*)self + 0xC, (int)lbl_805C7890);
    self->fn_8037B584(lbl_805C7994, 0, 0, lbl_805C797C);
}

void fn_80151B48(Self80151B48* self, Ctx8015* ctx, int a, float f1, float f2, float f3)
{
    if (self->m4 != 0) {
        float u;
        float k = lbl_805C79DC;
        const char* nm = lbl_805C79A0;
        unsigned r = fn_8014D8AC(ctx->mA4C->m554, 1000000, nm, 0x36);
        if (!((float)r * k * lbl_805C79E8 >= self->m8)) {
            ((Unk8016C1C4_List*)ctx)->fn_8016C620(a, (int)&self->mC);
        }
    }
}

void* fn_80151C10() { return fn_80151A48(operator new(0x1C, lbl_806EF9B4)); }

void* fn_80151C40(void* self)
{
    new (self) Unk8037B3E8(0xFFA19369);
    Obj80151C40* p = (Obj80151C40*)self;
    p->m0 = lbl_8065E8F0;
    new (p->pad24) Unk802CF484;
    fn_8033CCE0(p->m5C);
    p->m40 = 0;
    p->m4C = 0;
    p->m44 = 0;
    p->m50 = 0;
    p->m58 = 0;
    p->m1C = 0;
    p->m18 = 0;
    p->m20 = lbl_805C7A28;
    p->m4 = lbl_805C7A28;
    p->m8 = lbl_805C7A28;
    p->mC = lbl_805C7A28;
    p->m10 = lbl_805C7A28;
    p->m14 = lbl_805C7A28;
    return p;
}

void fn_80151FA0(Unk80151FA0_Obj* p)
{
    p->m48 = p->m48 + 1;
    p->m54 = p->m54 + 1;
    if (p->m58 == 0) {
        fn_8033CD74((char*)p + 0x5C);
    }
}

void fn_80151FE8(char* self, Ctx8015* ctx, float f1, float f2, float f3)
{
    Unk802D5618* o = ctx->mA54->m3C;
    fn_802D5618(o);
    fn_802D5A64(o, 0, 0, 0, self + 0x24, 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

float fn_80152064(UnkAt20F2* p, float f)
{
    return p->m20 - f;
}

void* fn_801522B4() { return fn_80151C40(operator new(0x68, lbl_806EF9B4)); }

void* fn_801522E4(void* self)
{
    new (self) Unk8037B3E8(0x1BE7961C);
    Unk801522E4_Obj* p = (Unk801522E4_Obj*)self;
    p->m4 = 0;
    p->m0 = lbl_8065E878;
    return p;
}

void fn_80152330(Unk80359B48* self)
{
    self->fn_8037B584(lbl_805C7BC4, (char*)self + 4, 0xF, 0);
    self->fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7BC4);
}

void fn_8015238C(float a, float b, float c)
{
}

void fn_801523A4(UnkAt13B* p)
{
    p->m13 = 0;
}

void* fn_801523B0() { return fn_801522E4(operator new(0x14, lbl_806EF9B4)); }

void* fn_801523E0(void* self)
{
    new (self) Unk8037B3E8(0x37EF0C2A);
    *(const void**)self = lbl_8065EA40;
    fn_8015242C((Unk8015242C_Obj*)self);
    return self;
}

void fn_8015242C(Unk8015242C_Obj* p)
{
    p->m4 = 0;
    p->m10 = 0;
    p->m8 = lbl_805C7BE4;
    p->mC = lbl_805C7BE4;
    p->m14 = lbl_805C7BE4;
    p->m18 = lbl_805C7BE4;
}

void fn_80152454(Unk80359B48* self)
{
    self->fn_8037B7E8(lbl_805C7BE8);
    self->fn_8037B458(lbl_805C7BEC, (int*)((char*)self + 4), 0, 0);
    self->fn_8037B50C(lbl_805C7BF8, (float*)((char*)self + 8), lbl_805C7C04, 0);
    self->fn_8037B50C(lbl_805C7C10, (float*)((char*)self + 0xC), lbl_805C7C04, 0);
    self->fn_8037B458(lbl_805C7C1C, (int*)((char*)self + 0x10), 0, lbl_805C6240);
    self->fn_8037B50C(lbl_805C7C34, (float*)((char*)self + 0x14), lbl_805C7C04, 0);
    self->fn_8037B50C(lbl_805C7C44, (float*)((char*)self + 0x18), lbl_805C7C04, 0);
    self->fn_8037B830(lbl_805C7BE8);
    self->fn_8037B548(lbl_805C7C54, 0);
    self->fn_8037B548(lbl_805C7C64, 0);
    self->fn_8037B548(lbl_805C7C7C, 0);
}

void* fn_80152580() { return fn_801523E0(operator new(0x1C, lbl_806EF9B4)); }

void fn_801525B0(void* p) { fn_8037CE98(fn_8037C7FC(), 0x37EF0C2A, p, 0x0); }

struct Unk801525F0_Obj { const void* m0; int m4; int m8; int mC; char m10[12]; };

void* fn_801525F0(void* self)
{
    new (self) Unk8037B3E8(0x3003FE5B);
    Unk801525F0_Obj* p = (Unk801525F0_Obj*)self;
    p->m0 = lbl_8065E800;
    fn_8033CCE0(p->m10);
    p->m4 = 0;
    p->m8 = 0;
    p->mC = 0;
    return p;
}

void fn_8015264C(Unk80359B48* self)
{
    self->fn_8037B5C0(lbl_805C7CB0, (int*)((char*)self + 4), lbl_805C7BCC);
    self->fn_8037B5C0(lbl_805C7CB8, (int*)((char*)self + 8), lbl_805C7BCC);
    self->fn_8037B7E8(lbl_805C7B5C);
    self->fn_8037B458(lbl_805C7B68, (int*)((char*)self + 0xC), lbl_805C60F8, lbl_805C6240);
    ((Unk8037B3E8*)self)->fn_8037B728(lbl_805C7B78, lbl_805C7B84, (char*)self + 0x10, (int)lbl_805C7B90);
    self->fn_8037B830(lbl_805C7B5C);
    self->fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7CBC);
}

void fn_80152728() {}

void fn_8015272C(Self8015272C* self, Ctx8015* ctx, float f1, float f2, float f3)
{
    Ent3C* cur = ctx->mA54;
    if (cur == fn_801A04A8(ctx->mA4C, 1)) {
        int r = ((int (*)(int))fn_801525B0)(self->m4);
        Sub8061FEDC* s = &lbl_8061FEDC->m40;
        if (r == 0) {
            fn_80359A40(&s->m4);
        } else {
            s->m4 = r;
        }
        s->m8 = ((int (*)(int))fn_801525B0)(self->m8);
        SetM4C(s, lbl_805C7CD4);
    }
}

}
