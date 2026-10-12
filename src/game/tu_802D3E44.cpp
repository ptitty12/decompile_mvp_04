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
extern float lbl_8061EDE4;
extern const char lbl_805E4210[];
extern const char lbl_805E421C[];
extern const char lbl_805E4230[];
extern const char lbl_805E4244[];
extern int lbl_8061EDC8;
void fn_80303BC4(const char* fmt, ...);
float fn_802CBD90(Unk802D56CC_Cam* c);
void fn_802CC53C(Unk802D56CC_Cam* c);
extern Unk802D5618_Blob lbl_8068B828;
extern int lbl_80620150;
void fn_8031E1A0(Unk802D5B64_View* v, int a);
void fn_8031E1D4(Unk802D5B64_View* v, int a);
void fn_8016BA48(int h, int c, int a, int b, Unk802D5618_Blob* blob, int d);
void fn_8016C4A0(int h);
extern char lbl_805E4284[];
extern char lbl_805E4298[];
void* fn_802CF168(void* name);

inline void CopyF(float* dst, float v)
{
    *dst = v;
}

extern float lbl_8061EDE8;
extern float lbl_8061EDEC;
extern const void* lbl_80664528[];
extern const void* lbl_806643D0[];
void fn_8033CD28(void* p, int c);
void fn_802D3B40(void* p, int c);
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
void fn_802D3F38(Unk802D58E8* o, int a, int b, int c);
void fn_802D41C0(Unk802D58E8* o, int key, int, int);
void fn_802D42A4(Unk802D58E8* o, int key, int, int);
void fn_802D4360(Unk802D58E8* o, int key, int, int);
void fn_802D4280(Unk802D58E8* o, int, int, int);
Unk802D5B64_View* fn_801A04A8(void* owner, int k);
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
const char* fn_802D4DE8(Unk802D58E8* o, int k);
struct Unk802D4CC8_Rec;
void fn_802D61AC(Unk802D58E8* o, int k, int a);
Unk802D4CC8_Rec* fn_802D4CC8(Unk802D58E8* o, int k);
void fn_802D4434(Unk802D58E8* o, int k);
void fn_802D3E44(Unk802D58E8* o, int a, int b, int c)
{
    if (fn_801A04A8(o->m60, 5) != o->m64) {
        switch (o->m60->m6F4) {
        case 0:
            fn_802D3F38(o, a, b, c);
            break;
        case 3:
            fn_802D4360(o, a, b, c);
            break;
        case 4:
            fn_802D42A4(o, a, b, c);
            break;
        case 9:
            fn_802D4280(o, a, b, c);
            break;
        default:
            fn_802D41C0(o, a, b, c);
            break;
        }
    }
}

enum KeyE { KeyE_Neg = -1, KeyE_Lo = 0x2B, KeyE_Hi = 0x6A };

struct Unk802D3F38_Vec {
    float x;
    float y;
    float z;
    float w;
};
struct Unk802D3F38_Own {
    char pad0[0x6CC];
    int m6CC;
};
struct Unk802D3F38_Own700 {
    char pad0[0x3A4];
    int m3A4;
    char pad3A8[0x3BC - 0x3A8];
    int m3BC;
};
struct Unk802D3F38_View {
    char pad0[0x54];
    int m54;
};
extern float lbl_8061EDD8;
extern float lbl_8061EDDC;
extern float lbl_8061EDE0;
extern float lbl_805E4064;
extern float lbl_805E4068;
extern float lbl_805E406C;
extern float lbl_805E4070;
void fn_8018959C(Unk802D3F38_Vec* out, int obj, float f);
int fn_8018AD2C(int a);
int fn_801BBF24(int a);
int fn_801D0314(int a);
void fn_8037893C(void* p, int a, int b, int c, int d);
float fn_804028E4(float v);
inline float Unk802D3F38_LenSq(const Unk802D3F38_Vec* v)
{
    return v->z * v->z + (v->x * v->x + v->y * v->y);
}
void fn_802D5970(Unk802D58E8* o);
inline int& M150(Unk802D58E8* o)
{
    return *(int*)((char*)o + 0x150);
}

void fn_802D3F38(Unk802D58E8* o, int key, int, int)
{
    Unk802D3F38_Vec v;
    int sp18;
    switch ((KeyE)key) {
    case 0x69:
        fn_802D58E8(o, 1);
        fn_802D5970(o);
        break;
    case 0x6A:
        M150(o) = 1;
        break;
    case 0x5B:
    case 0x31:
    case 0x2F:
        fn_802D58E8(o, 2);
        break;
    case 0x3D: {
        sp18 = o->m60->m6F8->m10->m124;
        fn_802D5D24(o, &sp18);
        break;
    }
    case 0x43:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
        if (o->m7C == 2) {
            if (fn_8018AD2C(((Unk802D3F38_Own*)o->m60)->m6CC) != 0) {
                if (fn_801BBF24(((Unk802D3F38_Own700*)o->m60->m700)->m3BC) != 5) {
                    fn_802D58E8(o, 3);
                    fn_802D5970(o);
                }
            }
        }
        break;
    case 0x42: {
        int go = 1;
        if (((Unk802D3F38_View*)o->m64)->m54 != 1) {
            if (fn_8018AD2C(((Unk802D3F38_Own*)o->m60)->m6CC) == 0) {
                fn_8037893C((char*)o->m60 + 0x704, 0x46, 0, 0, 0);
                go = 0;
            }
        }
        if (go != 0) {
            if (fn_801D0314(((Unk802D3F38_Own700*)o->m60->m700)->m3A4 + 0x28C) == 2) {
                o->m88 = 3;
                o->m8C = lbl_8061EDD8;
            } else {
                o->m88 = 1;
                fn_8018959C(&v, ((Unk802D3F38_Own*)o->m60)->m6CC, lbl_805E4064);
                if (fn_804028E4(Unk802D3F38_LenSq(&v)) > lbl_805E4068 || !(v.y <= lbl_805E406C))
                    o->m8C = lbl_8061EDDC;
                else
                    o->m8C = lbl_8061EDE0;
            }
            fn_802D5970(o);
        }
        break;
    }
    case 0x30:
        fn_802D58E8(o, 4);
        fn_802D5970(o);
        break;
    case 0x57:
        if (M150(o) != 0) {
            o->m88 = 1;
            fn_802D5970(o);
            o->m8C = lbl_805E4070;
            M150(o) = 0;
        }
        break;
    }
}

void fn_802D41C0(Unk802D58E8* o, int key, int, int)
{
    Unk802D58E8_Owner* ow = o->m60;
    switch ((KeyE)key) {
    case 0x2F:
    case 0x5B:
    case 0x67:
        fn_802D58E8(o, 2);
        break;
    case 0x2B:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x57:
    case 0x68:
    case 0x6A:
        fn_802D58E8(o, 1);
        break;
    case 0x42:
        ow->m6DC = ow->m6D0;
        o->m88 = 1;
        o->m8C = lbl_8061EDE4;
        break;
    }
}

void fn_802D4280(Unk802D58E8* o, int, int, int)
{
    fn_802D58E8(o, 1);
}

void fn_802D42A4(Unk802D58E8* o, int key, int, int)
{
    Unk802D58E8_Owner* ow = o->m60;
    switch ((KeyE)key) {
    case 0x5B:
    case 0x67:
        fn_802D58E8(o, 2);
        break;
    case 0x2B:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x39:
    case 0x57:
    case 0x68:
    case 0x6A:
        fn_802D58E8(o, 1);
        break;
    case 0x42:
        ow->m6DC = ow->m6D0;
        o->m88 = 1;
        o->m8C = lbl_8061EDE8;
        break;
    }
}

void fn_802D4360(Unk802D58E8* o, int key, int, int)
{
    Unk802D58E8_Owner* ow = o->m60;
    switch ((KeyE)key) {
    case 0x39:
    case 0x3A:
    case 0x40:
    case 0x5B:
    case 0x67:
        fn_802D58E8(o, 2);
        break;
    case 0x2B:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x57:
    case 0x68:
    case 0x6A:
        fn_802D58E8(o, 1);
        break;
    case 0x42:
        ow->m6DC = ow->m6D0;
        o->m88 = 1;
        o->m8C = lbl_8061EDEC;
        break;
    }
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

extern const char lbl_805E41A8[];
extern const char lbl_805E41B8[];
extern const char lbl_805E41C8[];
extern const char lbl_805E41D8[];
extern const char lbl_805E41E8[];
extern const char lbl_805E41F8[];
extern "C" Unk802D4BD0_Obj* fn_801C1638(void* owner, int idx);

struct Unk802D4CC8_Rec {
    int w[5];
};
struct Unk802D4CC8_Ctl {
    char pad0[0x38C];
    int m38C;
};
extern Unk802D4CC8_Rec lbl_805E4100;

Unk802D4CC8_Rec* fn_802D4CC8(Unk802D58E8* o, int k)
{
    switch (k) {
    case 1:
    case 3:
        if ((*(Unk802D4CC8_Ctl**)((char*)o->m60 + 0x6CC))->m38C == 1) {
            Unk802D4CC8_Rec* d = (Unk802D4CC8_Rec*)((char*)o + 0x108);
            *d = lbl_805E4100;
            return d;
        }
    case 2:
    case 4: {
        Unk802D4BD0_Obj* t = fn_801A4B34(o->m60);
        int a = o->m60->m6F8->m10->m124;
        if (o->m154 == 0) {
            fn_802D61AC(o, a, 0);
        }
        if (t != 0 && t->s5(1) == 1) {
            return (Unk802D4CC8_Rec*)((char*)o + 0xC8);
        }
        return (Unk802D4CC8_Rec*)((char*)o + 0xE8);
    }
    case 0:
    default:
        return 0;
    }
}

const char* fn_802D4DE8(Unk802D58E8* o, int k)
{
    switch (k) {
    case 1:
    case 3: {
        Unk802D4BD0_Obj* t = fn_801A4B34(o->m60);
        if (t != 0 && t->s5(1) == 1) {
            return lbl_805E41A8;
        }
        return lbl_805E41B8;
    }
    case 2:
    case 4: {
        Unk802D4BD0_Obj* a = fn_801C1638(o->m60, 0);
        Unk802D4BD0_Obj* t = fn_801A4B34(o->m60);
        if (a != 0 && a->s5(1) == 1) {
            if (t != 0 && t->s5(1) == 1) {
                return lbl_805E41C8;
            }
            return lbl_805E41D8;
        }
        if (t != 0 && t->s5(1) == 1) {
            return lbl_805E41E8;
        }
        return lbl_805E41F8;
    }
    case 0:
    default:
        return 0;
    }
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

struct Unk802D505C_Cam {
    char pad0[0xA0];
    int mA0;
};
struct Unk802D505C_Ctl {
    char pad0[0x38];
    int m38;
};
int fn_802CF1A4(void* hash);
Unk802D4BD0_Obj* fn_803272D0(void* tbl, int id);

int fn_802D505C(Unk802D58E8* o)
{
    int changed = 0;
    Unk802D58E8_Owner* ow = o->m60;
    int want = 0;
    switch ((*(Unk802D505C_Ctl**)((char*)ow + 0x744))->m38) {
    case 0:
        want = *(int*)((char*)o + 0x164);
        break;
    case 2:
        want = fn_802CF1A4((void*)0x92166576);
        break;
    case 3:
        want = fn_802CF1A4((void*)0x129747DA);
        break;
    case 4:
        want = fn_802CF1A4((void*)0x58B42CB9);
        break;
    case 5:
        want = fn_802CF1A4((void*)0x770E693A);
        break;
    case 6:
        want = fn_802CF1A4((void*)0x59B0D0EC);
        break;
    case 12:
        want = fn_802CF1A4((void*)0x12974903);
        break;
    case 7:
        want = fn_802CF1A4((void*)0x18F0984B);
        break;
    case 8:
        want = fn_802CF1A4((void*)0xC2AA8C);
        break;
    case 9:
        want = fn_802CF1A4((void*)0x19ED3C7E);
        break;
    case 10:
        want = fn_802CF1A4((void*)0x0B02FCB3);
        break;
    case 11:
        want = fn_802CF1A4((void*)0x0BFFA0E6);
        break;
    case 13:
        want = fn_802CF1A4((void*)0x129749C9);
        break;
    case 1: {
        Unk802D4BD0_Obj* t = fn_803272D0((char*)ow + 0x50, 9);
        int flag = 0;
        int a = 0x3C;
        if (t != 0) {
            if (t->s5(1) != 0)
                flag = 1;
            a = t->m390;
        }
        fn_802D6008(o, o->m60->m6F8->m10->m124, a, o->m154);
        void* n = (char*)o + 0xE8;
        if (flag != 0)
            n = (char*)o + 0xC8;
        want = (int)fn_802CF168(n);
        break;
    }
    }
    if ((*(Unk802D505C_Cam**)((char*)o + 0x6C))->mA0 != want) {
        fn_802CBDBC(*(Unk802CBD04**)((char*)o + 0x6C), want, 1, 0);
        changed = 1;
    }
    return changed;
}

void fn_802D5618(Unk802D5618* o)
{
    Unk802D5618_Blob tmp = *(Unk802D5618_Blob*)(o->m64->m40 + 0x3D48);
    *(Unk802D5618_Blob*)(o->m70 + 0x184) = tmp;
}

/* near-miss (68 vs 70 insns): the float constants are passed to a variadic printf-style call; as literals they are promoted to doubles (lfd), retail loads
   them as floats (lfs) from separate 0x805E4250.. objects; extern const floats are CSE'd into f30/f31, plain extern floats too. */
void fn_802D56CC(Unk802D56CC* o)
{
    if (o->mC != 0) {
        fn_802CC53C(o->m74);
        if (lbl_8061EDC8 != 0) {
            fn_80303BC4(lbl_805E4210, 0.1f, 0.2f, fn_802CBD90(o->m74));
            fn_80303BC4(lbl_805E421C, 0.1f, 0.23f, o->m74->m60.x, o->m74->m60.y, o->m74->m60.z);
            fn_80303BC4(lbl_805E4230, 0.1f, 0.26f, o->m74->m70.x * 57.295776f, o->m74->m70.y * 57.295776f, o->m74->m70.z * 57.295776f);
        }
    }
    if (o->mA0 != 0) {
        fn_80303BC4(lbl_805E4244, 0.1f, 0.1f, o->mA4);
    }
}

void fn_802D57E4(Unk802D58E8* o, int flag, int a, int b, int c)
{
    if (flag != 0) {
        Unk802D5B64_View* t = fn_801A04A8(o->m60, 5);
        fn_8031E1A0(t, b);
        t->m4 = 1;
        Unk802D5618_Blob blob = lbl_8068B828;
        fn_8016BA48(t->m40, c, 0, 0, &blob, 0);
        fn_8031E1A0(o->m64, a);
    } else {
        Unk802D5B64_View* t = fn_801A04A8(o->m60, 1);
        fn_8031E1D4(t, lbl_80620150);
        fn_8016C4A0(fn_801A04A8(o->m60, 0)->m40);
    }
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

void fn_802D5F74(Unk802D5F74* o)
{
    o->m164 = (Unk802D5F74_Rec*)fn_802CF168(lbl_805E4284);
    Unk802D5F74_Rec* b = (Unk802D5F74_Rec*)fn_802CF168(lbl_805E4298);
    CopyF(&o->m164->m70, b->m70);
    CopyF(&o->m164->m74, b->m74);
    CopyF(&o->m164->m5C, b->m5C);
    fn_802CBDBC(o->m6C, (int)o->m164, 1, 0);
}

class Unk802D6008_Virt : public Unk802D4BD0_Base {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4();
};
extern const char lbl_805E42A8[];
extern const char lbl_805E42BC[];
extern const char lbl_805E42D4[];
extern const char lbl_805E42E8[];
extern const char lbl_805E42FC[];
char* fn_8040B448(char* d, const char* s);
char* fn_8040B61C(char* d, const char* s);

void fn_802D6008(Unk802D58E8* o, int k, int a, int b)
{
    int sp8 = k;
    fn_802D5D24(o, &sp8);
    char c = ((char*)&sp8)[3] + 0x31;
    if (!((float)a >= 78.0f)) {
        const char* s1 = lbl_805E42A8;
        const char* s2 = lbl_805E42BC;
        fn_8040B61C((char*)o + 0xC8, s1);
        fn_8040B61C((char*)o + 0xE8, s2);
    } else {
        const char* s1 = lbl_805E42D4;
        const char* s2 = lbl_805E42E8;
        fn_8040B61C((char*)o + 0xC8, s1);
        fn_8040B61C((char*)o + 0xE8, s2);
    }
    *((char*)o + 0xD3) = c;
    *((char*)o + 0xF3) = c;
    if (sp8 == 0 && o->m60->m6F4 != 8) {
        Unk802D6008_Virt* p = (Unk802D6008_Virt*)fn_801A4B34(o->m60);
        int f1 = 0;
        int f2 = 0;
        Unk802D6008_Virt* q = *(Unk802D6008_Virt**)((char*)o->m60 + 0x65C);
        if (p != 0)
            f1 = p->s4();
        if (q != 0)
            f2 = q->s4();
        if (f1 != 0) {
            if (f2 != 0)
                goto cat;
        } else if (f2 == 0) {
        cat:
            fn_8040B448((char*)o + 0xC8, lbl_805E42FC);
            fn_8040B448((char*)o + 0xE8, lbl_805E42FC);
        }
    }
    o->m154 = b;
    if (b != 0)
        o->m158 = sp8;
    else
        o->m158 = b;
}

void fn_802D61AC(Unk802D58E8* o, int k, int a)
{
    fn_802D6008(o, k, fn_801A4B34(o->m60)->m390, a);
}

void fn_802D62A8(Unk802D62A8* p, int c)
{
    p->m8 = lbl_806643D0;
    fn_802D3B40(p, c);
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

void fn_802D729C(Unk802D729C* p, int c)
{
    p->vptr = lbl_80664528;
    fn_8033CD28(p->m2C, 2);
    p->vptr = lbl_806646F0;
    fn_8037B424(p, c);
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
