/*
 * Game code, .text 0x802F42A4-0x802F8324 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F42A4.h"

Unk802F42A4::Unk802F42A4(Unk802F4F40_Q* a)
{
    m64 = a;
    fn_802F4368();
}

Unk802F42A4::~Unk802F42A4()
{
}

void fn_802F4348(Unk802F42A4* o)
{
    o->fn_802F4368();
}

void Unk802F42A4::fn_802F4368()
{
    Unk802F4F40_Q* q = m64;
    fn_802FD0F8(&mCC);
    m24 = 0;
    mC8 = 0;
    m2C = 0;
    m6C = 0;
    m60 = 0.0f;
    m5C = 0.0f;
    m68 = 1;
    mA0 = 0;
    mA4 = 0;
    m3C = 0.0f;
    m40 = 0.0f;
    m44 = 0.0f;
    m48 = 0.0f;
    mB0 = 0;
    mA8 = 0;
    mAC = 0.0f;
    m70 = 0;
    m28 = 0;
    m80 = 1;
    m74 = 100000.0f;
    m7C = 100000.0f;
    m78 = 0;
    m90 = 0;
    mC0 = 0;
    mC4 = 0;
    mB4 = 0.0f;
    mB8 = 0.0f;
    mBC = 0.0f;
    m84 = lbl_806055AC;
    m94 = lbl_806055AC;
    int n = fn_80328648(q) - 1;
    if (n == 0) {
        mDC = 1;
        mD8 = n;
        mE0 = 2;
        mE4 = 3;
    } else {
        mD8 = 5;
        mDC = 6;
        mE0 = 7;
        mE4 = 8;
    }
    mF0 = 0;
    mE8 = -1.0f;
    mEC = -1.0f;
}

void Unk802F42A4::fn_802F4628()
{
    int a = lbl_8061E978;
    for (int k = 0; k < 10; k++) {
        lbl_806E0DD8[k] = fn_802B0850(a, lbl_8061F804[k], 0);
        lbl_806E0E00[k] = fn_802B0ACC(a, lbl_8061F804[k]);
    }
    float t = lbl_806E0E00[0].mC;
    t = t * 0.1f;
    lbl_806E0E00[0].mC = lbl_806E0E00[0].mC - 2.0f * t;
    lbl_806E0E00[0].m4 = lbl_806E0E00[0].m4 + t;
    mC0 = 1;
}

void Unk802F42A4::fn_802F4F40()
{
    Unk802F4F40_P* p = m64->m6CC;
    if (p && p->m38C == 2) {
        m94 = p->m3C0;
        /* near-miss: retail loads m3F4 into f31 before the call with no stack store; a const float
           local stores/reloads it (same length), the inline compare evaluates the call first */
        const float f = p->m3F4;
        if (!(f < fn_80190F0C(p))) {
            m90 = 1;
        }
    }
}

float fn_802F7ED0()
{
    return lbl_8061CBC4 + 0.04f;
}

float fn_802F7EE8(Unk802F7EE8_S* o)
{
    return o->m3C * 0.33333334f - lbl_8061F6EC;
}

float fn_802F7F04(Unk802F7EE8_S* o)
{
    return o->m40 * 0.33333334f - lbl_8061F6EC;
}
