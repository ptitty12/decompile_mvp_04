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

extern "C" float fn_801C17EC(Unk802F4F40_P* p);
inline Unk802F44D0_V3 ScaledV(Unk802F4F40_P* p)
{
    Unk802F44D0_V3 v = p->m420;
    v.y = v.y * fn_801C17EC(p);
    return v;
}

/* near-miss: 84 of 86 instructions identical; retail stores mBC, mB4, mB8 and ours mBC, mB8, mB4 (all 720 orders of the six
   leading stores, chained assignments and separate statements tried) */
void Unk802F42A4::fn_802F44D0()
{
    mA8 = 0;
    mBC = mB4 = mB8 = 0.0f;
    m70 = 0;
    m6C = 0;
    Unk802F4F40_P* p = m64->m6CC;
    m30 = ScaledV(p);
    m3C = p->m438;
    m40 = p->m43C * fn_801C17EC(p);
    m44 = p->m440;
    m48 = p->m444 * fn_801C17EC(p);
    Unk802F44D0_Lim* l = m64->m700->m3BC;
    m4C = l->m28 * m40;
    m50 = l->m2C * m40;
    m54 = l->m30 * m3C;
    m90 = 0;
    m58 = l->m34 * m3C;
    if (mC0 == 0)
        fn_802F4628();
    mC4 = 0;
    m28 = 1;
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

struct Unk802F7E24_V2 {
    float x;
    float y;
};
inline Unk802F7E24_V2 V2Add(const Unk802F7E24_V2& a, const Unk802F7E24_V2& b)
{
    Unk802F7E24_V2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}
inline Unk802F7E24_V2 V2Scl(const Unk802F7E24_V2& a, float s)
{
    Unk802F7E24_V2 r;
    r.x = a.x * s;
    r.y = a.y * s;
    return r;
}

Unk802F7E24_V2 fn_802F7E24(Unk802F7EE8_S* s, Unk802F7E24_V2* a, Unk802F7E24_V2* b)
{
    Unk802F7E24_V2 sum = V2Add(*a, *b);
    Unk802F7E24_V2 h = V2Scl(sum, 0.5f);
    h.x *= s->m3C;
    h.y *= s->m40;
    return h;
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
