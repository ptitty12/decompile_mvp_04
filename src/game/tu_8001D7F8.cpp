/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001D7F8-0x8001E444 only: every data object is extern by its lbl_ name.
 *
 * Methods of Unk8001CE80 (include/game/tu_8001CACC.h), the same class as the
 * tail of tu_8001CACC.cpp: thin forwarders that pass a few fields, or a sub-object
 * address, to functions in 0x8004xxxx.
 */
#include "game/tu_8001CACC.h"

float fn_8025356C(char* p);
float fn_80253434(char* p);
int fn_80046380(float a, float b);
void fn_8004335C(int a);
void fn_80044580(int a, int b, int c);
void fn_80044E20(Unk8001CE80* o);
void fn_80043218(int a);
int fn_8025416C(char* p, int a);
void fn_80042E58(int a);
void fn_80045DD8(int a);
void fn_800440E8(int a, int b, int c, Unk8001D47C_Level* d);
void fn_80043DF0(Unk8001D47C_Level* a);
void fn_80043664(int a);
void fn_80043D70(int a);
int fn_80043B00(int a, int b, int c);
void fn_80043DAC(int a);
void fn_800471B0(int a);
int fn_80075E7C(int a);
void fn_800466E4(int a, int b);

struct Unk8061E978 {
    int m0;
    int m4;
};
extern Unk8061E978* lbl_8061E978;

int Unk8001CE80::fn_8001D7F8()
{
    return fn_80046380(fn_8025356C((char*)m130 + 0x480), fn_80253434((char*)m130 + 0x480));
}

int Unk8001CE80::fn_8001D850()
{
    int v = fn_80046380(fn_8025356C((char*)m130 + 0x480), fn_80253434((char*)m130 + 0x480));
    int r = 0;
    if (v == 1) {
        r = 1;
    } else if (v == 2) {
        r = 2;
    } else if (v == 4) {
        r = 4;
    }
    return r;
}

void Unk8001CE80::fn_8001DA28()
{
    fn_8004335C(m444);
}

void Unk8001CE80::fn_8001DA4C()
{
    fn_80044580(m458, m44C, m3F8);
}

void Unk8001CE80::fn_8001DA7C()
{
    fn_80044E20(this);
}

void Unk8001CE80::fn_8001DB4C()
{
    fn_80043218(m48);
}

void Unk8001CE80::fn_8001DB70()
{
    fn_80042E58(fn_8025416C((char*)m3B0 + 0x588, 0));
}

void Unk8001CE80::fn_8001DBA0()
{
    unsigned char* e = m130->m44C->m6F8->m14 + m3B4 * 0xe64;
    fn_80045DD8(e[0x177]);
}

void Unk8001CE80::fn_8001DC58()
{
    fn_80042E58(fn_8025416C((char*)m130 + 0x588, 0));
}

void Unk8001CE80::fn_8001DC88()
{
    Unk8001D47C_Level* l = m130->m44C->m6F8;
    unsigned char* t = l->m14;
    fn_800440E8(*(int*)(t + 0x198), *(int*)(t + 0xffc), l->mC->m88, l);
}

void Unk8001CE80::fn_8001DCCC()
{
    fn_80043DF0(m130->m44C->m6F8);
}

void Unk8001CE80::fn_8001DDD8()
{
    fn_80043664(m404);
}

void Unk8001CE80::fn_8001DE9C()
{
    fn_80043D70(m4D4);
}

void Unk8001CE80::fn_8001E054()
{
    fn_80043B00(m110, m118, m120);
}

int Unk8001CE80::fn_8001E084()
{
    if (m48 > 0) {
        return 0;
    }
    return fn_80043B00(m110, m118, m120);
}

void Unk8001CE80::fn_8001E0C8()
{
    int v = m130->m44C->m6F8->mC->m80;
    if (v == 1) {
        v = 2;
    }
    fn_80043DAC(v);
}

void fn_8001E108()
{
    fn_800471B0(lbl_8061E978->m4);
}

void Unk8001CE80::fn_8001E294()
{
    fn_800466E4(fn_80075E7C(m130->m44C->m6F8->mC->m24), m130->m44C->m6F8->mC->m80);
}

void Unk8001CE80::fn_8001E2EC()
{
    fn_80042E58(fn_8025416C((char*)m3B0 + 0x588, 0));
}

void Unk8001CE80::fn_8001E31C()
{
    fn_80042E58(fn_8025416C((char*)m130 + 0x588, 0));
}
