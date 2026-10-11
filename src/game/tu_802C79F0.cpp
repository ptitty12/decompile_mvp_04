/*
 * Game code, .text 0x802C79F0-0x802CBD04 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802C79F0.h"
#include "game/warp_b.h"
#include "game/tu_8000E618.h"

extern char lbl_806EF9E9;
extern char lbl_806EF9DD;
extern char lbl_806EF9CD;
extern char lbl_806EF9E7;
extern char lbl_806EF9E8;
extern char lbl_806EF9C7;
extern char lbl_806EF9C8;
extern char lbl_8061EC9C;
extern char lbl_806EF9F5;
extern char lbl_806EF9F6;
extern char lbl_805DEEC0[];
extern int lbl_805E1B34[];
extern const char lbl_805E1884[];
extern const char lbl_805E1898[];

void fn_803EDA0C(int p);
void fn_80377408(void* p);
void fn_80377488(void* p);
void* fn_803774A8(unsigned n, int heap);
int fn_80401904(int h);
void fn_804017B0(int h, int p);
void fn_80433004(int p, int n);
void* fn_8040B190(void* dst, const void* src, ...);
int fn_802B9300(const char* name, int a, int b, unsigned int* outn);
void fn_802CA5AC(int a, int b);
Unk8000E618* fn_8000E65C();
extern int lbl_8061EC60[];
extern int lbl_8061EC70[];
extern int lbl_8061EC80[];
extern const char lbl_805E1918[];
extern const char lbl_805E15E0[];
extern const void* lbl_80664250[];
extern int lbl_806EE9F0;
extern float lbl_805E1920;
extern const char lbl_8060D1CC[];
void fn_802C7C08(Unk802C7B54* o, int n, int i, char* p, int t);
void fn_802C7EF8(Unk802C7B54* o);
void fn_802C86B8(Unk802C7B54* o);
void fn_802C9EF4(void* p);
void fn_802C8748(Unk802C7B54* o, int n, int i, char* p, int t, char* q, int u);
int fn_802C91DC(int v);
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_803ED634(const char* name, int size, int flags);
int fn_803ED604(const char* name, int size, int flags);
void fn_803D74A0(int a, const char* b, int c);
void fn_803E9A54(int a, const char* b, int* c, int* d);
int fn_802C8484(const char* name, int size);
void fn_802C85AC(char* p);
float fn_802AEAA0(Unk802AEB4C* o, int id);
float fn_802AE9C8(Unk802AEB4C* o, int id);

void fn_802C7B54(Unk802C7B54* o)
{
    int i = 0;
    if (i < o->m3D4) {
        int off = 0;
        do {
            i++;
            fn_802C85AC(o->m3C0 + off);
            off += 0x10;
        } while (i < o->m3D4);
    }
    int n = lbl_805E1B34[0];
    if (n > 0) {
        i = n;
        int off2 = 0;
        do {
            char* b = (char*)o + 0xA8;
            fn_803EDA0C(*(int*)(b + off2));
            *(int*)(b + off2) = 0;
            off2 += 0xC;
        } while (--i != 0);
    }
    o->m3D4 = 0;
    if (o->m3C0 != 0) {
        fn_80377488(o->m3C0);
        o->m3C0 = 0;
    }
}

Unk802C83A4::Unk802C83A4()
{
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mC = 0;
}

void fn_802C7E80(Unk802C7B54* o)
{
    for (int i = 0; i <= 3; i++) {
        int n = lbl_805E1B34[i];
        if (n > 0) {
            fn_802C7C08(o, n, i, (char*)o + i * 0xC, lbl_8061EC60[i]);
        }
    }
}

void fn_802C8008(Unk802C7B54* o)
{
    fn_802C7E80(o);
    fn_802C7EF8(o);
    fn_802C86B8(o);
    fn_802C9EF4((char*)lbl_8061E978 + 0x125E0);
}

void* fn_802C83C0(Unk802C83C0* o, int a, int* out)
{
    int h = o->m4;
    int n = fn_80401904(h);
    void* p = fn_803774A8(n, a);
    fn_804017B0(h, (int)p);
    if (out != 0) {
        *out = n;
    }
    return p;
}

void fn_802C8424(Unk802C83C0* o, int dst, int* out)
{
    int h = o->m0;
    int n = fn_80401904(h);
    fn_804017B0(h, dst);
    fn_80433004(dst, n);
    if (out != 0) {
        *out = n;
    }
}

int fn_802C8484(const char* name, int size)
{
    int flags = fn_8000E65C()->fn_8000E6F0() | 0x400;
    int h = fn_803ED634(name, size, flags);
    if (h == 0) {
        h = fn_803ED604(name, size, flags);
        if (h == 0) {
            h = fn_803ED604(name, size, flags);
            if (h == 0) {
                h = fn_803ED604(name, size, lbl_806EE9F0 | 0x400);
            }
        }
    }
    return h;
}

void fn_802C851C(Unk802C851C* o)
{
    o->m0 = fn_802C8484(lbl_805E1884, 0x7918);
    o->m8 = 0;
    o->mC = 0;
}

void fn_802C8564(Unk802C851C* o)
{
    o->m4 = fn_802C8484(lbl_805E1898, 0xFA0);
    o->m8 = 0;
    o->mC = 0;
}

void fn_802C85AC(Unk802C83A4* o)
{
    fn_803EDA0C(o->m0);
    o->m0 = 0;
    fn_803EDA0C(o->m4);
    o->m4 = 0;
}

void fn_802C85F0(Unk802C851C* o, const char* name)
{
    unsigned int n = 0;
    int buf = fn_802B9300(name, 0, 0xE, &n);
    fn_8040B190((void*)o->m0, (void*)buf, n);
    fn_80377408((void*)buf);
}

void fn_802C8654(Unk802C851C* o, const char* name)
{
    unsigned int n = 0;
    int buf = fn_802B9300(name, 0, 0xE, &n);
    fn_8040B190((void*)o->m4, (void*)buf, n);
    fn_80377408((void*)buf);
}

void fn_802C86B8(Unk802C7B54* o)
{
    for (int i = 1; i <= 3; i++) {
        int n = lbl_805E1B34[i];
        if (n > 0) {
            fn_802C8748(o, n, i, (char*)o + 0x48 + i * 0xC, lbl_8061EC70[i], (char*)o + 0x78 + i * 0xC, lbl_8061EC80[i]);
        }
    }
}

int fn_802C91DC(int v)
{
    int r = 0;
    if (v != 0) {
        if (v == 1) {
            r = 0xF;
        } else if (v == 2) {
            r = 0x1E;
        }
    }
    return r;
}

/* near-miss (2 slots): retail does subi r0,r30,0x384 after the call (add r30,r0,r3); ours folds the constant into the call result. */
void fn_802C920C(char* buf, Unk802C920C_Req* req)
{
    int n = req->m2C;
    if (req->m28 == 0) {
        n = fn_802C91DC(req->m74) + (n - 0x384);
    }
    int c = 0x67;
    if (req->m28 != 0) {
        c = 0x63;
    }
    fn_804089B4(buf, lbl_805E1918, c, n);
}

void fn_802C959C(Unk802C95F8* o, int v)
{
    if (v != o->m4B0) {
        if (o->m438->m0 != 0) {
            fn_803D74A0(o->m438->m0, lbl_805E15E0, v);
        }
        o->m4B0 = v;
    }
}

Unk802C9618::Unk802C9618()
{
    m4908 = 0;
    m490C = lbl_80664250;
    for (int i = 0; i < 0x26; i++) {
        for (int j = 0; j < 0x52; j++) {
            rows[i].f[j] = lbl_805E1920;
        }
        for (int k = 0; k < 0x29; k++) {
            rows[i].g[k] = 0;
        }
    }
}

void fn_802C95F8(Unk802C95F8* o, int flag)
{
    if (flag != 0) {
        o->m438 = (Unk802C95F8_Sub*)((char*)o + 0x2D0);
    } else {
        o->m438 = (Unk802C95F8_Sub*)((char*)o + 0x168);
    }
}

void fn_802C968C(Unk802C9618* o, int c)
{
    o->m490C = lbl_80664250;
    o->m4908 = 0;
    if (c & 1) {
        fn_80377408(o);
    }
}

void fn_802C9EA4(Unk802C9618* o, int a)
{
    int sp8 = 0;
    int spC;
    fn_803E9A54(a, lbl_8060D1CC, &sp8, &spC);
    o->m4908 = spC;
}

Unk802CA5A0_Elem* fn_802CA5A0(Unk802CA5A0_Elem* t, int i)
{
    return &t[i];
}

float fn_802CB67C(Unk802AEB4C* o, int id)
{
    return o->fn_802AEB4C(id);
}

char* fn_802CB69C()
{
    return lbl_805DEEC0;
}

float fn_802CB6A8(Unk802AEB4C* o, int id)
{
    return fn_802AEAA0(o, id);
}

float fn_802CB6C8(Unk802AEB4C* o, int id)
{
    return fn_802AE9C8(o, id);
}

char fn_802CB6E8()
{
    return lbl_806EF9E9;
}

char fn_802CB6F8()
{
    return lbl_806EF9DD;
}

char fn_802CB708()
{
    return lbl_806EF9CD;
}

char fn_802CB718()
{
    return lbl_806EF9E7;
}

char fn_802CB728()
{
    return lbl_806EF9E8;
}

char fn_802CB738()
{
    return lbl_806EF9C7;
}

char fn_802CB748()
{
    return lbl_806EF9C8;
}

char fn_802CB758()
{
    return lbl_8061EC9C;
}

char fn_802CB768()
{
    return lbl_806EF9E9;
}

int fn_802CB778()
{
    return 0xF;
}

char fn_802CB780()
{
    return lbl_806EF9F5;
}

int fn_802CB790()
{
    return 8;
}

char fn_802CB798()
{
    return lbl_806EF9F6;
}

int fn_802CB7A8()
{
    return 8;
}

void fn_802CB7B0()
{
    fn_802CA5AC(1, 0xFFFF);
}

void fn_802CB7DC()
{
    fn_802CA5AC(0, 0xFFFF);
}
