/*
 * Game code, .text 0x802D3E44-0x802D73B4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802D3E44.h"
#include "game/tu_802CBD04.h"

extern const char lbl_805E4194[];
extern const char lbl_805E414C[];
extern const char lbl_805E415C[];
extern const char lbl_805E416C[];
extern const char lbl_805E4180[];
extern "C" Unk802D4BD0_Obj* fn_801A4B34(void* owner);
extern const char lbl_805E26DC[];
extern const char lbl_805E26EC[];
extern const char lbl_805E2700[];
extern const char lbl_805E270C[];
extern const void* lbl_806646F0[];
extern int lbl_8061EDB8;
extern Unk802D58E8_Flags* lbl_8061B8C0;

Unk802D58E8* fn_801A4CE8(void* owner, int k);
Unk802D58E8_Pad* fn_801A6DB8(void* owner);
void fn_8017C72C(void* t);
int fn_802CBDB4(Unk802CBD04* o);
void fn_802CBDBC(Unk802CBD04* o, int a, int b, int kind);
void fn_8040B830(char* dst, const char* src, int n);
unsigned int fn_80378568(const char* token, int len);
void fn_802D6008(Unk802D58E8* o, int k, int a, int b);
void fn_802D5D24(Unk802D58E8* o, int* p);
int fn_801A2034(Unk802D58E8_Owner* ow, int f);

void fn_8037B424(void* p, int c);
void fn_802CBD04(void* p);
void fn_802D58E8(Unk802D58E8* o, int k);
const char* fn_802D7218();
const char* fn_802D7288();
const char* fn_802D7324();
const char* fn_802D7394();
const char* fn_802D4BD0(Unk802D58E8* o, int k);
const char* fn_802D4CBC();
void fn_802D4DE8(Unk802D58E8* o, int k);
void fn_802D4CC8(Unk802D58E8* o, int k);
void fn_802D4434(Unk802D58E8* o, int k);
void fn_802D4280(Unk802D58E8* o)
{
    fn_802D58E8(o, 1);
}

const char* fn_802D4BD0(Unk802D58E8* o, int k)
{
    switch (k) {
    case 1:
    case 3: {
        Unk802D4BD0_Obj* t = fn_801A4B34(o->m60);
        if (t != 0 && t->s5(1) == 1) {
            return lbl_805E414C;
        }
        return lbl_805E415C;
    }
    case 2:
    case 4: {
        Unk802D4BD0_Obj* t = fn_801A4B34(o->m60);
        if (t != 0 && t->s5(1) == 1) {
            return lbl_805E416C;
        }
        return lbl_805E4180;
    }
    case 0:
    default:
        return 0;
    }
}

const char* fn_802D4CBC()
{
    return lbl_805E4194;
}

void fn_802D4F64(Unk802D58E8* o, int k)
{
    switch (o->m60->m6F4) {
    case 2:
        fn_802D4BD0(o, k);
        break;
    case 3:
        fn_802D4DE8(o, k);
        break;
    case 4:
        fn_802D4CC8(o, k);
        break;
    case 9:
        fn_802D4CBC();
        break;
    case 0:
    default:
        fn_802D4434(o, k);
        break;
    }
}

void fn_802D4FE0(Unk802D58E8* o)
{
    if (o->m88 != 0) {
        o->m8C = o->m8C - 0.016666668f;
        if (!(o->m8C > 0.0f)) {
            fn_802D58E8(o, o->m88);
            o->m84 = o->m90;
            o->m8C = 0.0f;
            o->m88 = 0;
        }
    }
}

void fn_802D5618(Unk802D5618* o)
{
    Unk802D5618_Blob tmp = *(Unk802D5618_Blob*)(o->m64->m40 + 0x3D48);
    *(Unk802D5618_Blob*)(o->m70 + 0x184) = tmp;
}

void fn_802D58E8(Unk802D58E8* o, int k)
{
    if (fn_801A4CE8(o->m60, 1) == o && k == 2 && o->m7C != 2 && o->m80 != 2) {
        if (fn_801A6DB8(o->m60)->m6C == 0) {
            lbl_8061B8C0->m2C = 5;
        }
    }
    o->m80 = k;
}

void fn_802D5970(Unk802D58E8* o)
{
    Unk802D58E8* c = fn_801A4CE8(o->m60, 1);
    if (c == o) {
        void* t = c->m60->m700;
        if (t != 0) {
            fn_8017C72C(t);
        }
    }
}

void fn_802D5B64(Unk802D58E8* o, int k)
{
    o->m18 = 1;
    int a = o->m160;
    if ((int)o->m78->mA0 != a || fn_802CBDB4(o->m78) != k) {
        fn_802CBDBC(o->m78, a, 1, 0);
        o->m78->mD4 = k;
    }
    if (k != 0) {
        o->m64->m4 = 1;
    } else {
        o->m64->m4 = k;
    }
}

void fn_802D5BF4(Unk802D58E8* o, int a, const char* s)
{
    o->m98 = a;
    if (a != 0) {
        fn_8040B830(o->mA4, s, 0x1F);
        o->mC3 = 0;
        if (s != 0) {
            o->m9C = fn_80378568(s, 0);
            o->mA0 = 1;
        }
    }
}

int fn_802D5C64(Unk802D5C64* o)
{
    if (o->m7C == 2 && o->m14 == 0 && o->m28 == 0) {
        return 1;
    }
    return 0;
}

int fn_802D5C94(Unk802D58E8* o)
{
    if (o->s9() != 0) {
        int sp8 = o->m60->m6F8->m10->m124;
        fn_802D5D24(o, &sp8);
        if (o->m154 != 0) {
            sp8 = o->m158;
        }
        if (sp8 == 5) {
            return 1;
        }
    }
    return 0;
}

void fn_802D5D24(Unk802D58E8* o, int* p)
{
    Unk802D58E8_Owner* ow = o->m60;
    int m = ow->m6F4;
    if (m != 3) {
        if (m == 7) {
            *p = 0;
            return;
        }
        if (*p > 5) {
            int f = 0;
            if (ow->m6F8->m14->m1CD0 != 0) {
                f = 1;
            }
            if (fn_801A2034(ow, f) != -1) {
                *p = *p - 6;
                return;
            }
            *p = 5;
        }
        return;
    }
    *p = 5;
}

void fn_802D61AC(Unk802D58E8* o, int k, int a)
{
    fn_802D6008(o, k, fn_801A4B34(o->m60)->m390, a);
}

void fn_802D62D8(Unk802D62D8* o)
{
    fn_802CBD04(o->m78);
}

void fn_802D62FC()
{
}

void fn_802D6300()
{
}

void fn_802D71B8(Unk802D71B8* p, int c)
{
    p->vptr = lbl_806646F0;
    fn_8037B424(p, c);
}

void fn_802D71E8()
{
}

const char* fn_802D71EC()
{
    return fn_802D7218();
}

int fn_802D720C()
{
    return 0xB38E54D3;
}

const char* fn_802D7218()
{
    return lbl_805E26DC;
}

int fn_802D7224(Unk802D7224* o)
{
    return o->m54;
}

void fn_802D722C(Unk802D71B8* p, int c)
{
    p->vptr = lbl_806646F0;
    fn_8037B424(p, c);
}

const char* fn_802D725C()
{
    return fn_802D7288();
}

int fn_802D727C()
{
    return lbl_8061EDB8;
}

const char* fn_802D7288()
{
    return lbl_805E26EC;
}

int fn_802D7294()
{
    return 0;
}

const char* fn_802D72F8()
{
    return fn_802D7324();
}

int fn_802D7318()
{
    return 0xB7E56E61;
}

const char* fn_802D7324()
{
    return lbl_805E2700;
}

int fn_802D7330(Unk802D7224* o)
{
    return o->m20;
}

void fn_802D7338(Unk802D71B8* p, int c)
{
    p->vptr = lbl_806646F0;
    fn_8037B424(p, c);
}

const char* fn_802D7368()
{
    return fn_802D7394();
}

int fn_802D7388()
{
    return 0x2B376453;
}

const char* fn_802D7394()
{
    return lbl_805E270C;
}

int fn_802D73A0()
{
    return 0;
}

void fn_802D73A8()
{
}

int fn_802D73AC()
{
    return 0;
}
