/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80058060-0x8005ADD0 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

/* near-miss: retail keeps the constant 3 in r4 for both the m18 store and the
 * fn_803A9204 argument (one fewer callee-saved register); this loads it twice. */
Unk8005BA1C_Voice::Unk8005BA1C_Voice(int unused, int vol, int a3, int a4, int a5, int a6, int a7)
    : m4(a7), m8(a5), mC(a4), m10(a3), m18(3), m1C(a6), m24(0), m30(-1)
{
    m0 = -1;
    m14 = -1;
    m20 = 0;
    m28 = -1;
    m2C = -1;
    fn_803A9204(&m50, m18);
    m50 = vol <= 0x7F ? (vol < 0 ? 0 : vol) : 0x7F;
}

int fn_8005A118(Unk8005BA1C_Voice* v, float f)
{
    int r = 0;
    if (v->m1C == 0) {
        r = fn_803AB858(v->m0, (int)(f * (float)v->m8)) >= 0;
    }
    return r;
}

/* near-miss (2 slots): retail loads the return value 1 after the final store. */
int fn_8005A19C(Unk8005BA1C_Voice* v)
{
    if (v->m1C == 0) {
        fn_803AAA3C(v->m0);
        fn_803AA95C(v->m0);
    }
    v->m0 = -1;
    v->m18 = 3;
    return 1;
}

Unk8005BA1C_Voice::~Unk8005BA1C_Voice()
{
    fn_8005A19C(this);
}

int fn_8005A010(Unk8005BA1C_Voice* v, int a, int ch)
{
    int ok = 0;
    if (v->m4 != 0) {
        fn_8005A814(v, 0);
        fn_8005A19C(v);
        if (a == 0) {
            v->m0 = fn_803AA934(&v->m50, v->m10, v->mC, v->m4, v->m8);
        } else {
            int cnt = 0;
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                if (lbl_805AE420[ch].e[i].m24 == 1) {
                    cnt++;
                    sum += lbl_805AE420[ch].e[i].m20;
                }
            }
            if (fn_803A7924(v->m4, sum - (lbl_80620548 << 10), cnt) >= 0) {
                v->m0 = 0;
            }
        }
        if (v->m0 >= 0) {
            ok = 1;
            v->m18 = 0;
        }
    }
    return ok;
}

void fn_8005A240(Unk8005BA1C_Voice* v)
{
    if (v->m1C == 0 && v->m0 > -1) {
        fn_803A975C();
        if (fn_803AB8A4(v->m0, &v->m34) >= 0) {
            fn_803A979C();
            if (v->m34 > 0) {
                fn_803A975C();
                fn_803AB644(v->m38, &v->m40);
                fn_803A979C();
                if (v->m40 == 2 && v->m48 <= 0xC8) {
                    fn_8005AA00(v);
                }
            }
        } else {
            fn_803A979C();
        }
    }
}

void fn_8005A2E4(Unk8005BA1C_Voice* v, int k)
{
    if (v->m1C == 0 && fn_8005A5FC(v, k) != 0 && v->m0 >= 0) {
        fn_803A975C();
        int f = 0;
        if (fn_803AB8A4(v->m0, &v->m34) >= 0) {
            fn_803A979C();
            int t = v->m34;
            if (t == 0) {
                f = 1;
            } else if (t == 1) {
                fn_803A975C();
                fn_803AB644(v->m38, &v->m40);
                fn_803A979C();
                if (v->m40 == 2) {
                    f = v->m48 <= 0xC8;
                }
            }
            if (f == 1) {
                int h = lbl_805B09F4[k].mC4;
                if (fn_803927D0(h) != 0) {
                    fn_80392AA4(h);
                    fn_80392A28(h);
                }
            }
        } else {
            fn_803A979C();
        }
    }
}

/* near-miss (2 slots): the ch * 0x1C product lands in r11 instead of r0. Same in fn_8005A4F8. */
int fn_8005A3E8(Unk8005BA1C_Voice* v, int ch, int x)
{
    int r = -1;
    if (v->m1C == 0) {
        if (v->m0 < 0) {
            return -1;
        }
        r = fn_803AAA18(v->m0, lbl_805B09F4[ch].mC8, (int)lbl_805B09F4[ch].m7E, x);
        v->m18 = 1;
        fn_8005A674(v, fn_800475EC()->e[ch].m0, 0);
        if (r < 0) {
            return r;
        }
        fn_8005AA00(v);
        v->m28 = ch;
        if (ch == 0) {
            v->m2C = fn_800412AC(fn_8004072C(), 0x45, 0, 0, 0, 0);
        } else if (ch == 3) {
            v->m30 = fn_800412AC(fn_8004072C(), 0x46, 0, 0, 0, 0);
        }
        v->m14 = r;
    }
    return r;
}

int fn_8005A4F8(Unk8005BA1C_Voice* v, int ch, int a, int b)
{
    int r = -1;
    if (v->m1C == 0) {
        if (v->m0 < 0) {
            return -1;
        }
        r = fn_803AAA18(v->m0, lbl_805B09F4[ch].mC8, a, b);
        v->m18 = 1;
        fn_8005A674(v, fn_800475EC()->e[ch].m0, 0);
        if (r < 0) {
            return r;
        }
        fn_8005AA00(v);
        v->m28 = ch;
        if (ch == 0) {
            v->m2C = fn_800412AC(fn_8004072C(), 0x45, 0, 0, 0, 0);
        } else if (ch == 3) {
            v->m30 = fn_800412AC(fn_8004072C(), 0x46, 0, 0, 0, 0);
        }
        v->m14 = r;
    }
    return r;
}

int fn_8005A5FC(Unk8005BA1C_Voice* v, int k)
{
    if (v->m1C == 0) {
        int r = 0;
        if (v->m0 > -1 && lbl_805B09F4[k].mC4 > -1 && fn_803927D0(lbl_805B09F4[k].mC4) != 0) {
            r = 1;
        }
        return r;
    }
    return 0;
}

int fn_8005A674(Unk8005BA1C_Voice* v, int a, int b)
{
    int r = -1;
    if (v->m1C == 0) {
        v->m24 = b;
        if (v->m18 != 2) {
            a = ((a << 7) - a) / 100;
            if (a < 0) {
                a = 0;
            }
            if (a > 0x7F) {
                a = 0x7F;
            }
            v->m20 = a;
            fn_803A975C();
            if (b <= 0) {
                float f = (float)a * lbl_805ADC60;
                r = fn_803AB9F0(v->m0, -1, f);
            } else {
                r = fn_803AAFB8(v->m0, b, a);
            }
            fn_803A979C();
        }
    }
    if (r >= 0) {
        v->m50 = a;
        return 1;
    }
    return 0;
}

int fn_8005A780(Unk8005BA1C_Voice* v, int a)
{
    int r = -1;
    int z = v->m1C;
    if (z == 0 && v->m0 >= 0 && v->m18 != 3) {
        r = fn_803AAA18(v->m0, 0x64, (int)lbl_805B0780[a], 0);
        if (r < 0) {
            v->m18 = z;
        } else {
            v->m14 = r;
            v->m18 = 1;
            v->m28 = -1;
        }
    }
    return r;
}

void fn_8005A814(Unk8005BA1C_Voice* v, int a)
{
    if (v->m1C == 0) {
        if (v->m18 != 3) {
            fn_8005A674(v, 0, a);
            if (v->m18 == 1) {
                v->m18 = 2;
            }
            if (a == 0 && fn_8005AAA8(v) == 1) {
                fn_8005A9A8(v);
            } else {
                fn_8005AA00(v);
            }
        }
    } else {
        fn_800396D0(fn_80038EB4(), 1);
    }
}

int fn_8005A8B4(Unk8005BA1C_Voice* v)
{
    if (v->m18 != 3) {
        int r = fn_8005AAA8(v);
        if (r == 0) {
            v->m18 = r;
        } else if (v->m18 != 2) {
            v->m18 = 1;
        } else if (v->m1C == 0) {
            fn_803A975C();
            if (fn_803AB278(v->m0) <= 0) {
                fn_803A979C();
                fn_8005A9A8(v);
            } else {
                fn_803A979C();
            }
        }
    }
    return v->m18;
}

int fn_8005A94C(Unk8005BA1C_Voice* v)
{
    int r = -1;
    if (v->m1C == 0) {
        fn_803A975C();
        if (fn_803AB8A4(v->m0, &v->m34) >= 0) {
            r = v->m34;
        }
        fn_803A979C();
    }
    return r;
}

void fn_8005A9A8(Unk8005BA1C_Voice* v)
{
    int z = v->m1C;
    if (z == 0) {
        fn_803AAA3C(v->m0);
        v->m18 = z;
        fn_8005A674(v, v->m20, v->m24);
        fn_8005AA00(v);
    }
}

void fn_8005AA00(Unk8005BA1C_Voice* v)
{
    if (v->m28 == 0) {
        if (v->m2C > -1) {
            fn_8004181C(fn_8004072C(), 0x45, v->m2C, 0, 0, 0, 0);
            v->m2C = -1;
        }
    } else if (v->m28 == 3) {
        if (v->m30 > -1) {
            fn_8004181C(fn_8004072C(), 0x46, v->m30, 0, 0, 0, 0);
            v->m30 = -1;
        }
    }
}

int fn_8005AAA8(Unk8005BA1C_Voice* v)
{
    int r = 0;
    if (v->m1C == 0) {
        fn_803A975C();
        if (fn_803AB8A4(v->m0, &v->m34) >= 0) {
            if (fn_803AB644(v->m38, &v->m40) >= 0) {
                fn_803A979C();
                int t = v->m40;
                if (t == 0 || t == 2 || t == 1) {
                    r = 1;
                }
            } else {
                fn_803A979C();
            }
        } else {
            fn_803A979C();
        }
    }
    return r;
}

int fn_8005AB44(Unk8005BA1C_Voice* v)
{
    int r = 0;
    if (v->m1C == 0 && v->m0 >= 0) {
        fn_803A975C();
        r = fn_803AB278(v->m0);
        fn_803A979C();
    }
    return r;
}

Unk8005ADD0_Obj::Unk8005ADD0_Obj()
    : m78(0x7F), m7C(0), mA4(0)
{
    m10C = 0;
    m108 = -1;
    for (int i = 0; i < 8; i++) {
        mE8[i] = -1;
    }
    for (int j = 0; j < 9; j++) {
        m80[j] = j;
        mC[j].mState = 0;
        mC[j].mHandle = -1;
        mC[j].mMode = -1;
    }
    fn_8005B658(this);
    mA8 = m80[mA4];
}

/* near-miss (3 slots): retail also stores the base class vtable (lbl_80649DB8) into
 * the vptr before calling the base destructor fn_80378620; this build omits that store. */
Unk8005ADD0_Obj::~Unk8005ADD0_Obj()
{
}

Unk8005ADD0_Obj* fn_8005ACE4(void)
{
    if (lbl_80618F88 == 0) {
        lbl_80618F88 = new (0) Unk8005ADD0_Obj;
    }
    return lbl_80618F88;
}

void fn_8005AD30(void)
{
}

void fn_8005AD34(Unk8005ADD0_Obj* o)
{
    int ok = 0;
    if (o->m7C == 1) {
        ok = o->m108 >= 0;
    }
    if (ok == 1) {
        for (int i = 0; i < 8; i++) {
            fn_8005AEB0(o, i);
        }
    }
    if (lbl_80618F88 != 0) {
        delete lbl_80618F88;
        lbl_80618F88 = 0;
    }
}
