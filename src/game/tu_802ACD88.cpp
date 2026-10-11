/*
 * Game code, .text 0x802ACD88-0x802B0ACC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802ACD88.h"

typedef Unk802ACD88_Mgr Mgr;

class Unk802ACD88_G {
public:
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11(void* a);
    virtual int s12(void* a);
};

struct Unk802AE9C8_R {
    void* m0;
    void* m4;
    struct Unk802AE9C8_Q* m8;
    float mC;
};

struct Unk802AE9C8_Q {
    char pad0[0x10];
    int m10;
};

class Unk802AE200_VT18 {
public:
    char pad0[0x18];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4(const char* name);
};

struct Unk802AE13C_Z {
    int m0;
    int m4;
    int m8;
};

extern void* (*lbl_8062C668)(int size, int heap);
extern const char lbl_805DFFB0[];
extern const char lbl_805DFFC0[];
extern char lbl_8060D190[];
extern Unk802ACD88_G* lbl_80626DD0;
extern const char* lbl_8061C728[];
extern const char lbl_805E00B4[];
extern const char lbl_805DFC08[];
extern const char lbl_805DFFD0[];
extern const char lbl_805E0004[];

void* operator new(unsigned int size, int heap);

extern "C++" {
void* fn_803E9640(void* a, void* b, int c, void* fn);
void fn_803E9994(void* a, char* tbl, int* n, void* z);
void fn_803D6144(int a, int b);
void fn_80314D60(int a);
void fn_80312700();
void* fn_80187190(void* mem, void* a, void* b);
void* fn_80306350(void* mem, int a, void* b, void* c);
void fn_8030427C(void* a, int b);
void fn_802AA7A4(int a, int b);
int fn_8040B574(const char* a, const char* b);
void* fn_802B9300(const char* name, int a, int b, int* n);
void fn_802ACE20(Mgr* m, void* p, int n);
int fn_802B6368(void* p, float x);
void* fn_802AFA54(Mgr* m, const char* s);
void fn_803DDA8C(void* a, void* b);
void fn_802AF1C4(Mgr* m, void* a, int b);
void fn_802BBA88(void* p);
int fn_8040B6A0(const char* s);
void fn_80379094(const char* s, int len, int a);
void fn_80378EF8(const char* s, int len, char* buf, int cap, int* n);
int fn_8033E958(const char* fmt, ...);
char* fn_8040B8FC(const char* s, int c);
int fn_802AF6F8(Mgr* m, char* buf, int flag);
void fn_802B7C50(void* p);
void fn_802C40BC(void* p);
void fn_802C40DC(void* p);
void* fn_80086140(void* x, char* buf);
void* fn_8014EB44(void* x);
void fn_8014EC24(void* x, char* buf);
void fn_8014EC5C(void* x, char* buf);
void fn_802C3D2C(void* p, int a);
void fn_802C79F0(void* p, int a);
void fn_802C7B54(void* p);
void fn_802C3EC0(void* p);
void fn_802C78B8(void* p);
void fn_802C4030(void* p);
int fn_802B34E0(void* p);
int fn_802B7A28(void* p);
int fn_802C4100(void* p);
int fn_802C417C(void* p);
int* fn_80378024(void* p, void* q);
void* fn_802AEC14(Mgr* m, const char* s, int a, int b);
int fn_802AED2C(void* a, void* b, int c);
int fn_802AF624(void* a, void* b, int c);
void* fn_803ED604(void* a, int b, void* c);
void* fn_803DD628(void* a, void* b);
void fn_803DD73C(void* a, int b);
void* fn_803EDA0C(void* a);
unsigned int fn_80378568(const char* s, int n);
int fn_80377E90(void* t, int* a, int* b, unsigned int h);
int fn_802AFB88(Mgr* m);
void fn_80377CD8(void* t, int idx, int a, unsigned int h);
void fn_802AFC7C(Mgr* m, void* e, int idx, int a, int b);
void* fn_802B98AC(const char* name, int a);
void fn_802BA310(void* t, const char* s);
void fn_802BA218(void* t);
void fn_802BA750(void* t);
void fn_802BA820(void* t, int b);
int* fn_802BA4D8(void* t, int a);
Mgr* fn_802BAD48(Mgr* m, int a);
Mgr* fn_802BAD84(Mgr* m, int a);
}

void fn_802ACD88()
{
    fn_802AA7A4(1, 0xFFFF);
}

void fn_802ACDB4() {}

int fn_802ACDB8(Mgr* m, const char* s)
{
    for (int i = 0; i <= 0x56; i++) {
        if (fn_8040B574(lbl_8061C728[i], s) == 0)
            return i;
    }
    return 0;
}

void fn_802ACF58(Mgr* m)
{
    int n = 0;
    void* p = fn_802B9300(lbl_805DFC08, 0, 14, &n);
    fn_802ACE20(m, p, n);
}

Mgr* fn_802AD4C8(Mgr* m, int a)
{
    fn_802BAD48(m, a + 0x16EF0);
    return m;
}

Mgr* fn_802AD500(Mgr* m, int a)
{
    fn_802BAD84(m, a + 0x16EF0);
    return m;
}

/* near-miss: retail reaches the stack Z object through a callee-saved pointer (r29) and has a larger frame */
void fn_802AE13C(Mgr* m)
{
    int n = 0;
    Unk802AE13C_Z z;
    int out = 0;
    z.m0 = 0;
    z.m8 = 0;
    m->m3B14 = fn_802B9300(lbl_805DFFB0, 0x400, 1, &out);
    void* o = lbl_8062C668(0x30, 0);
    m->m3B1C = 1;
    void* r = fn_803E9640(o, m->m3B14, out, (void*)fn_80312700);
    m->m3B18 = r;
    fn_803E9994(r, lbl_8060D190, &n, &z);
    m->m3B10 = z.m8;
    fn_803D6144(z.m8, m->m3B0C);
    fn_80314D60(m->m3B10);
}

void* fn_802AE200(Mgr* m, void* a, void* b)
{
    void* r = fn_80187190(operator new(0xC20, 0), a, b);
    ((Unk802AE200_VT18*)((char*)r + 0xA0))->s4(lbl_805DFFC0);
    fn_8030427C(fn_80306350(operator new(0x198, 0), 0x1C, r, a), m->m3B10);
    return r;
}

int fn_802AE374(Mgr* m)
{
    return fn_802B34E0((char*)m + 8);
}

int fn_802AE398(Mgr* m, float x)
{
    if (!fn_802B6368((char*)m + 8, x))
        return 0;
    void* r = fn_802AFA54(m, lbl_805DFFD0);
    if (r != 0)
        fn_803DDA8C(*(void**)((char*)m + 0x18700), r);
    return 1;
}

int fn_802AE408(Mgr* m)
{
    return fn_802B7A28((char*)m + 8);
}

void fn_802AE42C(Mgr* m)
{
    char* p = m->m3B50;
    fn_803DDA8C(*(void**)((char*)m + 0x18700), p + *(int*)(p + 0x14));
    fn_802B7C50((char*)m + 8);
}

/* near-miss: retail copies x to r30 before forming m+0x11F78 (mr/addis swapped) */
void fn_802AE474(Mgr* m, void* x)
{
    char buf[16];
    fn_802C40BC((char*)m + 0x11F78);
    fn_8014EC24(fn_8014EB44(fn_80086140(x, buf)), buf);
}

/* near-miss: same swap as fn_802AE474 */
void fn_802AE4C0(Mgr* m, void* x)
{
    char buf[16];
    fn_802C40DC((char*)m + 0x11F78);
    fn_8014EC5C(fn_8014EB44(fn_80086140(x, buf)), buf);
}

int fn_802AE50C(Mgr* m)
{
    return fn_802C4100((char*)m + 0x11F78);
}

int fn_802AE534(Mgr* m)
{
    return fn_802C417C((char*)m + 0x11F78);
}

void fn_802AE55C(Mgr* m, int a)
{
    char* b = (char*)m + 0x10000;
    fn_802C3D2C(b + 0x1F78, 0x23);
    fn_802C79F0(b + 0x2204, a);
}

void fn_802AE5A0(Mgr* m)
{
    char* b = (char*)m + 0x10000;
    fn_802C7B54(b + 0x2204);
    fn_802C3EC0(b + 0x1F78);
}

void fn_802AE5D8(Mgr* m)
{
    char* b = (char*)m + 0x10000;
    fn_802C78B8(b + 0x2204);
    fn_802C4030(b + 0x1F78);
}

int fn_802AE984(Mgr* m, void* p)
{
    int* r = fn_80378024((char*)m + 0x3B78, p);
    int ok = 0;
    if (r != (int*)-1) {
        if (*r != 0)
            ok = 1;
    }
    return ok;
}

int fn_802AE9C8(Mgr* m, void* key, float* a, int* b, int* c)
{
    Unk802AE9C8_R* r = (Unk802AE9C8_R*)fn_80378024((char*)m + 0x3B78, key);
    if (r != (Unk802AE9C8_R*)-1) {
        if (*(int*)r == 0)
            fn_802AF1C4(m, (char*)r->m8 + 0x18, 0);
        r->m8->m10++;
        *b = lbl_80626DD0->s11(r->m0);
        *a = r->mC;
        *c = lbl_80626DD0->s11(r->m4);
        return 1;
    }
    return 0;
}

void fn_802AEAA0(Mgr* m, void* key, void* a, void* b)
{
    void* p = 0;
    int* r = fn_80378024((char*)m + 0x3B78, key);
    if (r != (int*)-1)
        p = (void*)r[2];
    if (a != 0)
        lbl_80626DD0->s12(a);
    if (b != 0)
        lbl_80626DD0->s12(b);
    if (p != 0)
        fn_802BBA88(p);
}

float fn_802AEB4C(Mgr* m, void* p)
{
    float r = ((float*)fn_80378024((char*)m + 0x3B78, p))[3];
    return r;
}

int fn_802AEB7C(Mgr* m)
{
    if (m->m3B08 == 0)
        m->m3B08 = fn_802AEC14(m, lbl_805E0004, 1, 1);
    return 1;
}

int fn_802AEBCC(void* a, void* b)
{
    return fn_802AED2C(a, b, 0);
}

int fn_802AEBF0(void* a, void* b)
{
    return fn_802AF624(a, b, 0);
}

/* near-miss (parked, 2 insns swapped): retail saves flag (r5) to r30 before s (r4) to r31 in the prologue; every loop shape tried gives the opposite order */
int fn_802AF624(Mgr* m, const char* s, int flag)
{
    char buf[0x1388];
    int n = 0;
    while (fn_80379094(s, fn_8040B6A0(s), 0), *s != 0) {
        fn_80378EF8(s, fn_8040B6A0(s), buf, 0x1388, &n);
        s += n;
        if (n != 0) {
            fn_8033E958(lbl_805E00B4, buf);
            char* p = fn_8040B8FC(buf, 0x2F);
            if (p != 0)
                *p = 0;
            fn_802AF6F8(m, buf, flag);
        }
    }
    return 1;
}

int fn_802AFB50(Mgr* m)
{
    int i;
    for (i = 0; i < 0x5C3; i++) {
        char* b = (char*)m + 0x402C;
        int o = i * 0x1C;
        if (*(int*)(b + o) == 0)
            return i;
    }
    return 0;
}

int fn_802AFB88(Mgr* m)
{
    int i;
    for (i = 0; i < 0x96; i++) {
        char* b = (char*)m + 0xE180;
        int o = i * 4;
        if (*(int*)(b + o) == 0)
            return i;
    }
    return 0;
}

int fn_802AFBC4(Mgr* m)
{
    int i;
    for (i = 0; i < 0x5AA; i++) {
        char* b = (char*)m + 0xE3D8;
        int o = i * 4;
        if (*(int*)(b + o) == 0)
            return i;
    }
    return 0;
}

void* fn_802AFC00(void* a, void* b, void* c)
{
    return fn_803DD628(fn_803ED604(a, 0x58, b), c);
}

void* fn_802AFC3C(void* p)
{
    if (p != 0)
        fn_803DD73C(p, 2);
    return fn_803EDA0C(p);
}

/* near-miss: retail keeps only m+0x10000 in a register and re-forms every table address per use (no cached table pointers) */
void fn_802B0140(Mgr* m, const char* name, int flag, int n)
{
    unsigned int h = fn_80378568(name, 0);
    char* t = (char*)m + 0x10000 - 0x568;
    int a;
    int b;
    if (fn_80377E90(t, &a, &b, h) == 0) {
        int idx = fn_802AFB88(m);
        void* asset;
        if (flag != 0)
            asset = fn_802B98AC(name, n);
        else
            asset = fn_802B9300(name, n, 14, 0);
        char* tb = (char*)m + 0x10000 - 0x1E80;
        int o = idx * 4;
        *(void**)(tb + o) = asset;
        fn_80377CD8(t, idx, 0, h);
        char* e = *(char**)(tb + o);
        fn_802AFC7C(m, e + *(int*)(e + 0x14), idx, a, 0);
    }
}

void fn_802B0388(Mgr* m, const char* s, int flag)
{
    char* b = (char*)m + 0x10000;
    int x;
    int y;
    unsigned int h = fn_80378568(s, 0);
    if (fn_80377E90(b - 0x568, &x, &y, h) == 0 && flag != 0)
        fn_802BA310(b - 0x550, s);
}

void fn_802B03F4(Mgr* m)
{
    fn_802BA218((char*)m + 0xFAB0);
}

void fn_802B041C(Mgr* m)
{
    fn_802BA750((char*)m + 0xFAB0);
}

void fn_802B0444(Mgr* m, int a, int b)
{
    char* t = (char*)m + 0xFAB0;
    fn_802BA820(t, b);
    int* r = fn_802BA4D8(t, a);
    r[1] = b;
}

void fn_802B058C(Mgr* m, const char* name, void* asset)
{
    unsigned int h = fn_80378568(name, 0);
    char* t = (char*)m + 0x10000 - 0x568;
    int a;
    int b;
    if (fn_80377E90(t, &a, &b, h) == 0) {
        int idx = fn_802AFB88(m);
        char* tb = (char*)m + 0x10000 - 0x1E80;
        int o = idx * 4;
        *(void**)(tb + o) = asset;
        fn_80377CD8(t, idx, 0, h);
        char* e = *(char**)(tb + o);
        fn_802AFC7C(m, e + *(int*)(e + 0x14), idx, a, 0);
    }
}
