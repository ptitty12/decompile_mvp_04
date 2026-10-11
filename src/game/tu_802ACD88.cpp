/*
 * Game code, .text 0x802ACD88-0x802B0ACC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802ACD88.h"

typedef Unk802ACD88_Mgr Mgr;

extern const char* lbl_8061C728[];
extern const char lbl_805DFC08[];
extern const char lbl_805DFFD0[];
extern const char lbl_805E0004[];

extern "C++" {
void fn_802AA7A4(int a, int b);
int fn_8040B574(const char* a, const char* b);
void* fn_802B9300(const char* name, int a, int b, int* n);
void fn_802ACE20(Mgr* m, void* p, int n);
int fn_802B6368(void* p, float x);
void* fn_802AFA54(Mgr* m, const char* s);
void fn_803DDA8C(void* a, void* b);
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
