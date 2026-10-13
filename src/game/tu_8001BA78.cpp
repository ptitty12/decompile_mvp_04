/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001BA78-0x8001CACC only: every data object is extern by its lbl_ name.
 *
 * The one-line trace wrappers here share the shape described in
 * include/game/tu_800101C0.h (fn_80056C9C(id); then a variadic call through
 * lbl_80624408 with the fn_80391C04(0, 0, line) tag and the argument count).
 */
#include "game/tu_800101C0.h"
#include "game/tu_8001B190.h"
#include "game/tu_8001BA78.h"

void* fn_803ED8EC(int);
int fn_803ED9D4();
void fn_803ED720(int h, const char* name, void* buf, int a, int b, int c, int d, int e, int f, int g);
int fn_80020BCC(int);
extern const char lbl_805A50B8[];
extern Unk8001BA78* lbl_806164E8;
extern Unk8001BC8C* lbl_806164F0;
extern Unk8001C314* lbl_806164F4;
struct Unk80686D90 {
    int m0;
};
extern const Unk80686D90 lbl_80686D90;

Unk8001BA78::Unk8001BA78()
{
    m8 = new (0) char[0x6400];
    m4 = fn_803ED9D4();
    fn_803ED720(m4, lbl_805A50B8, m8, 0x6400, 4, 4, 0, 0, 0, 1);
}

Unk8001BA78::~Unk8001BA78()
{
    fn_803ED8EC(m4);
    if (m8) {
        delete[] m8;
    }
    lbl_806164E8 = 0;
}

Unk8001BA78* fn_8001BB7C()
{
    if (lbl_806164E8 == 0) {
        lbl_806164E8 = new (0) Unk8001BA78;
    }
    return lbl_806164E8;
}

void fn_8001BBC8()
{
    if (lbl_806164E8) {
        delete lbl_806164E8;
    }
}

void fn_8001BC10()
{
    lbl_806164F0 = new (0) Unk8001BC8C;
}

Unk8001BC8C* fn_8001BC4C()
{
    return lbl_806164F0;
}

void fn_8001BC58()
{
    if (lbl_806164F0) {
        delete lbl_806164F0;
    }
}

Unk8001BC8C::Unk8001BC8C() : m4(0), m8(0), mC(-1), m10(0)
{
    lbl_806164F0 = this;
    m0 = fn_80020BCC(lbl_80686D90.m0);
    m4 = 0;
    m8 = 0;
}

void fn_8001BCF0()
{
    fn_8001C394()->fn_8001C620(0);
}

void fn_8001BD18()
{
    fn_8001C394()->fn_8001C89C(0);
}

void Unk8001BC8C::fn_8001BD40()
{
    if (mC >= 0) {
        mC = mC - 1;
    }
}

Unk8001BC8C::~Unk8001BC8C()
{
    lbl_806164F0 = 0;
    fn_8001C394()->fn_8001C89C(0);
}

void fn_8005AF00(Unk8005ACE4* o, int a);
void fn_8005B58C(Unk8005ACE4* o, int a);
void fn_8001AE3C();

static inline int Cond(Unk800475EC* o)
{
    int r = 0;
    if (o->mF4 == 1) {
        r = o->mC00 >= 0;
    }
    return r;
}

void Unk8001BC8C::fn_8001BDAC(int cmd)
{
    if (cmd >= 0x99 && cmd <= 0xb4) {
        switch (cmd) {
        case 0xb1:
            if (m4 == 0) {
                fn_8005AF00(fn_8005ACE4(), 0);
            }
            break;
        case 0xb2:
            if (m4 == 0) {
                fn_8005B58C(fn_8005ACE4(), 0);
            }
            break;
        case 0xa4:
            fn_800412AC(fn_8004072C(), 0x40, 2, 1, 10, 0);
            break;
        case 0xa5:
            fn_800412AC(fn_8004072C(), 0x40, 2, 1, 12, 0);
            break;
        case 0xa6:
            fn_800412AC(fn_8004072C(), 0x40, 2, 1, 12, 0);
            break;
        case 0xa7:
            fn_800412AC(fn_8004072C(), 0x40, 2, 1, 11, 0);
            break;
        case 0xa8:
            fn_800412AC(fn_8004072C(), 0x40, 2, 1, 4, 0);
            break;
        case 0xa9:
            if (Cond(fn_800475EC())) {
                Unk800475EC* o = fn_800475EC();
                int b = 0;
                if (Cond(o)) {
                    if (o->m74) {
                        b = 1;
                    }
                }
                if (b) {
                    fn_8001AE3C();
                }
            }
            break;
        case 0xaa:
            if (Cond(fn_800475EC())) {
                Unk800475EC* o = fn_800475EC();
                int b = 0;
                if (Cond(o)) {
                    if (o->m74) {
                        b = 1;
                    }
                }
                if (b) {
                    fn_8001AE3C();
                }
            }
            break;
        case 0xab:
            fn_800412AC(fn_8004072C(), 3, 2, 1, 0x46, 0);
            break;
        case 0xac:
            fn_800412AC(fn_8004072C(), 0, 2, 1, 0x46, 0);
            break;
        case 0xad:
            fn_800412AC(fn_8004072C(), 0, 2, 1, 0x5a, 0);
            break;
        case 0xae:
            fn_800412AC(fn_8004072C(), 0, 2, 1, 0x8c, 0);
            break;
        case 0xaf:
            fn_800412AC(fn_8004072C(), 7, 2, 1, 0x5a, 0);
            break;
        case 0xb0:
            fn_800412AC(fn_8004072C(), 0x33, 0x64, 1, 0, 0);
            break;
        case 0xb3:
        case 0xb4:
            break;
        default:
            if (m8 == 0) {
                fn_800412AC(fn_8004072C(), cmd, 0, 0, 0, 0);
            }
            break;
        }
    }
}

extern const float lbl_80616508[];
void fn_800210E4(int h, int idx, float v);
struct Unk8061A32C {
    Unk8061A32C();
    char pad0[0xB8];
    int mB8;
    char padBC[0xD8 - 0xBC];
};
struct Unk6F8 {
    char pad0[0x10];
    int m10;
};
struct Unk8011AA24 {
    char pad0[0x6F8];
    Unk6F8* m6F8;
};
Unk8011AA24* fn_8011AA24(int a);
int fn_8007FE04(int a);
void fn_80086D44(int h, int idx, float v);
extern Unk8061A32C* lbl_8061A32C;
extern int lbl_8061930C;

float Unk8001BC8C::fn_8001C048(int idx)
{
    return lbl_80616508[idx];
}

void Unk8001BC8C::fn_8001C05C(int idx, float value, int flag)
{
    if (fn_8001C048(idx) != value) {
        fn_800210E4(lbl_806164F0->m0, idx, value);
        if (flag) {
            if (lbl_8061A32C == 0) {
                lbl_8061A32C = new (0) Unk8061A32C;
            }
            if (lbl_8061A32C->mB8) {
                fn_80086D44(fn_8011AA24(0)->m6F8->m10, idx, value);
            } else {
                fn_80086D44(fn_8007FE04(lbl_8061930C), idx, value);
            }
        }
    }
}

extern int lbl_80616F10;
void fn_800395B0(Unk80038EB4* o, int a);
void fn_800396D0(Unk80038EB4* o, int a);
void fn_80039854(Unk80038EB4* o, int a, float v);
void fn_8005B87C(Unk8005ACE4* o, int i, int on);

void fn_8001C128(float v)
{
    fn_80038EB4();
    if (lbl_80616F10) {
        fn_800395B0(fn_80038EB4(), 0);
    }
}

void fn_8001C168()
{
    fn_800396D0(fn_80038EB4(), 1);
}

extern const int lbl_805B19C0[];

void Unk8001BC8C::fn_8001C190(int idx, int val, int flag)
{
    if (mC < 0 || flag == 1 || lbl_805B19C0[idx] != m10) {
        mC = 0x5a;
        m10 = lbl_805B19C0[idx];
        switch (idx) {
        case 0:
            fn_800412AC(fn_8004072C(), 0x35, val, 0, 0, 0);
            break;
        case 1:
            fn_800412AC(fn_8004072C(), 0x36, val, 0, 0, 0);
            break;
        case 2:
            fn_800412AC(fn_8004072C(), 0x39, val, 0, 0, 0);
            break;
        case 3:
            fn_800412AC(fn_8004072C(), 0x38, val, 0, 0, 0);
            break;
        }
    }
}

void Unk8001BC8C::fn_8001C28C(int bits)
{
    for (int i = 0; i <= 8; i++) {
        Unk8005ACE4* o = fn_8005ACE4();
        int on = 0;
        if ((bits >> i) & 1) {
            on = 1;
        }
        fn_8005B87C(o, i, on);
    }
}

void fn_8001C2E4(float v)
{
    fn_80039854(fn_80038EB4(), 1, v);
}

Unk8001C314::Unk8001C314() : Unk80328234(0x12, 0)
{
    m68 = 0;
    m6C = 0;
    m64 = 0;
    for (int i = 0; i < 8; i++) {
        m24[i].m0 = -1;
        m24[i].m4 = 0;
    }
}

Unk8001C314* fn_8001C394()
{
    if (lbl_806164F4 == 0) {
        lbl_806164F4 = new (0) Unk8001C314;
    }
    return lbl_806164F4;
}

Unk8001C314::~Unk8001C314()
{
}

void fn_80030948(Unk80030938* o);
void fn_8005AD34(Unk8005ACE4* o);
void fn_80047898(Unk800475EC* o);
void fn_8003922C(Unk80038EB4* o);
void fn_8005BDA8(Unk8005BA9C* o);
void fn_800408A0(Unk8004072C* o);
struct Unk803AC134;
Unk803AC134* fn_803AC134();
void fn_803B9DC8(Unk803AC134* o);
void fn_8005BE30(Unk8005BA9C* o);

void Unk8001C314::fn_8001C410()
{
    if (m68 == 1) {
        for (int i = 0; i <= 7; i++) {
            if (m24[i].m4 != 0) {
                m24[i].m4 = 1;
                fn_8001C89C(i);
            }
        }
        fn_80030948(fn_80030938());
        fn_8005AD34(fn_8005ACE4());
        fn_80047898(fn_800475EC());
        fn_8003922C(fn_80038EB4());
        fn_8005BDA8(fn_8005BA9C());
        fn_800408A0(fn_8004072C());
        fn_803B9DC8(fn_803AC134());
        fn_8005BE30(fn_8005BA9C());
        if (m64) {
            delete[] m64;
            m64 = 0;
        }
        fn_8001BB7C();
        fn_8001BBC8();
    }
    if (lbl_806164F4) {
        delete lbl_806164F4;
    }
}

void Unk8001C314::fn_8001C50C()
{
    m68 = 1;
    fn_8004072C()->m5C4 = 1;
    fn_8005BA9C()->m0 = 1;
    fn_80038EB4()->m5288 = 1;
    fn_800475EC()->mF4 = 1;
    fn_8005ACE4()->m7C = 1;
    fn_80030938()->m34 = 1;
}

void fn_8005BB10(Unk8005BA9C* o);
int fn_8005BEE4(Unk8005BA9C* o, int idx);

void fn_800407EC(Unk8004072C* o);
void fn_80038F28(Unk80038EB4* o);
void fn_80316614(int h, int a, float v);
void fn_800477D4(Unk800475EC* o);
void fn_8005AD30(Unk8005ACE4* o);
void fn_80030944(Unk80030938* o);
extern int lbl_8061FEDC;
extern const float lbl_805A5114;
extern const float lbl_805A5118;

void Unk8001C314::fn_8001C568()
{
    if (m68 == 1) {
        if (m6C == 0) {
            fn_8001CACC();
        }
        if (m6C == 1) {
            fn_8005BB10(fn_8005BA9C());
            fn_8005BEE4(fn_8005BA9C(), 0);
            fn_800407EC(fn_8004072C());
            fn_80038F28(fn_80038EB4());
            fn_80316614(lbl_8061FEDC, 2, lbl_805A5114);
            fn_800477D4(fn_800475EC());
            fn_8005AD30(fn_8005ACE4());
            fn_80030944(fn_80030938());
            fn_80316614(lbl_8061FEDC, 2, lbl_805A5118);
        }
    }
}

extern const Unk805B10B4 lbl_805B10B4[];
extern int lbl_80616500;
extern int lbl_80616504;
extern int lbl_80618FBC;
void fn_803EE7BC();
void fn_800644D4(int h);
void fn_80064F78(int h);
int fn_80040958(Unk8004072C* o, int idx);
int fn_800392A8(Unk80038EB4* o, int idx);
int fn_80047958(Unk800475EC* o, int idx);
int fn_8005ADD0(Unk8005ACE4* o, int idx);
void fn_80020C5C(int h);

int Unk8001C314::fn_8001C620(int idx)
{
    int result;
    fn_803EE7BC();
    result = -1;
    if (m68 == 0) {
        result = -3;
    } else if (m6C == 0) {
        result = -2;
    }
    if (result != -3 && result != -2) {
        if (idx == 3 || idx == 6) {
            fn_800644D4(lbl_80618FBC);
        }
        if (m24[idx].m4 != 0) {
            m24[idx].m4 = m24[idx].m4 + 1;
            switch (m24[idx].m0) {
            case -3:
                result = m24[idx].m0;
                break;
            case -2:
                result = m24[idx].m0;
                break;
            case -1:
                result = m24[idx].m0;
                break;
            case 0:
                result = m24[idx].m0;
                break;
            case 1:
                result = m24[idx].m0;
                break;
            default:
                result = -2;
                break;
            }
        } else {
            lbl_80616500 = idx;
            if (lbl_805B10B4[idx].m20) {
                fn_8001CC04(&result, fn_80040958(fn_8004072C(), idx));
            }
            if (lbl_805B10B4[idx].m28) {
                fn_8001CC04(&result, fn_8005BEE4(fn_8005BA9C(), idx));
            }
            if (lbl_805B10B4[idx].m34) {
                fn_8001CC04(&result, fn_800392A8(fn_80038EB4(), idx));
            }
            if (lbl_805B10B4[idx].m24) {
                fn_8001CC04(&result, fn_80047958(fn_800475EC(), idx));
            }
            if (lbl_805B10B4[idx].m30) {
                fn_8001CC04(&result, fn_8005ADD0(fn_8005ACE4(), idx));
            }
        }
    }
    int slot;
    switch (result) {
    case -3:
        slot = -3;
        break;
    case 0:
        slot = 0;
        break;
    case 1:
        slot = 1;
        break;
    case -1:
        slot = -1;
        break;
    case -2:
        slot = -2;
        break;
    default:
        slot = -2;
        break;
    }
    m24[idx].m0 = slot;
    if (result >= 0) {
        int h = lbl_80686D90.m0;
        m24[idx].m4 = 1;
        fn_80020C5C(fn_80020BCC(h));
    }
    fn_803EE7BC();
    return result;
}

void fn_80047D40(Unk800475EC* o, int idx);
void fn_8005AEB0(Unk8005ACE4* o, int idx);
void fn_800393B0(Unk80038EB4* o, int idx);
void fn_800410D8(Unk8004072C* o, int idx);
void fn_8005C0C8(Unk8005BA9C* o, int idx);

void Unk8001C314::fn_8001C89C(int idx)
{
    fn_803EE7BC();
    if (m24[idx].m4 != 0) {
        if (idx == 3 || idx == 6) {
            fn_80064F78(lbl_80618FBC);
        }
        m24[idx].m4 = m24[idx].m4 - 1;
        if (m24[idx].m4 == 0) {
            m24[idx].m0 = -1;
            if (lbl_805B10B4[idx].m24) {
                fn_80047D40(fn_800475EC(), idx);
            }
            if (lbl_805B10B4[idx].m30) {
                fn_8005AEB0(fn_8005ACE4(), idx);
            }
            if (lbl_805B10B4[idx].m34) {
                fn_800393B0(fn_80038EB4(), idx);
            }
            if (lbl_805B10B4[idx].m20) {
                fn_800410D8(fn_8004072C(), idx);
            }
            if (lbl_805B10B4[idx].m28) {
                fn_8005C0C8(fn_8005BA9C(), idx);
            }
        }
    }
    fn_803EE7BC();
}

void fn_8004801C(Unk800475EC* o, int idx);
void fn_8005B414(Unk8005ACE4* o);
void fn_8005C868(Unk8005BA9C* o);
void fn_80039434(Unk80038EB4* o);
void fn_80031000(Unk80030938* o);

void Unk8001C314::fn_vslot5()
{
    if (lbl_80616504 > 0) {
        lbl_80616504 = lbl_80616504 - 1;
    } else if (m68 == 1) {
        for (int i = 0; i <= 7; i++) {
            if (fn_8001CC40(i) == 1 && lbl_805B10B4[i].m24 == 1) {
                fn_8004801C(fn_800475EC(), i);
            }
        }
        fn_8005B414(fn_8005ACE4());
        fn_8005C868(fn_8005BA9C());
        fn_80039434(fn_80038EB4());
        fn_80031000(fn_80030938());
    }
}

extern int lbl_806164F8;
extern const char lbl_805A511C[];
extern const float lbl_805A5130;
extern const float lbl_805A5134;
int fn_80400DA4();
void fn_80303BC4(const char* fmt, int a, ...);

/* near-miss: retail loads the three lis (floats, then the string) before the lfs pair and does `mr r4,r3` first (7 slots) */
void fn_8001CA78()
{
    if (lbl_806164F8 == 1) {
        fn_80303BC4(lbl_805A511C, fn_80400DA4(), lbl_805A5130, lbl_805A5134);
    }
}
