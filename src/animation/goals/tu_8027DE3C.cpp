/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic between cShortestPathChooser and catchgoal.cpp.
 * Original file name unknown; placeholder. 25 functions.
 *
 * .text 0x8027DE3C-0x8027FD64, .rodata 0x805DD134-0x805DD24C, .data 0x8061E6C8-0x8061E6D0.
 */
#include "game/chooser.h"
#include "game/goals/tu_8027DE3C.h"

/* By-value parameter gives retail's temp-to-member copy after a call that returns a Vec3. */
inline void SetVec(Unk80273498_Vec3& dst, Unk80273498_Vec3 v)
{
    dst = v;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DE3C(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b)
{
    mB0 = *a;
    mBC = *b;
    mE8 |= 0x100000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DE88(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b)
{
    mB0 = *a;
    mBC = *b;
    mE8 |= 0x80000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DED4()
{
    fn_8027DDE8(8);
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DF08()
{
    mE8 |= 0x40000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DF1C(int a)
{
    if (a == 1) {
        fn_8027DDE8(0x1B);
        mE8 |= 0x1000;
    } else {
        fn_8027DDE8(0x1A);
    }
    m7C = 2;
    return this;
}

void Unk8027DE3C::fn_8027DF7C()
{
    m7C = 2;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DF88(int a)
{
    mA0 = a;
    m9C = -1;
    mE8 |= 0x4000;
    return this;
}

Unk8027DE3C* Unk8027DE3C::fn_8027DFA8(int a)
{
    mA0 = a;
    m9C = 0;
    return this;
}

void Unk8027DE3C::fn_8027DFBC(int a, const Unk80273498_Vec3* v)
{
    mA4 = *v;
    mE8 |= 0x80000000;
    fn_8027DFA8(a);
}

Unk8027DE3C* Unk8027DE3C::fn_8027E008(int a)
{
    mA0 = a;
    m9C = 1;
    return this;
}

void Unk8027DE3C::fn_8027E01C(int a, const Unk80273498_Vec3* v)
{
    mA4 = *v;
    mE8 |= 0x80000000;
    fn_8027E008(a);
}

void Unk8027DE3C::fn_8027E068(int a)
{
    mA0 = a;
}

Unk8027DE3C* Unk8027DE3C::fn_8027E070(int a)
{
    mE8bits.f8 = a;
    return this;
}

int Unk8027DE3C::fn_8027EA14(Unk80270BA0_X* x)
{
    if ((mE8 & 0x400) && m4->m28 == 0) {
        return 0;
    }
    Unk8027DE3C_Owner* o = m4;
    if (o->m28 != 0) {
        int st = m78;
        int h = x->m618->m838;
        if ((unsigned)(st - 2) > 3 && st != 7 && st != 6 && st != 8 && st != 12 && st != 13
            && st != 26 && st != 27
            && (st != 1
                || (h != 0xA84A0C58 && h != (int)0xFA52B1B5 && h != 0x7942CA79 && h != (int)0xF90D27A1
                    && h != (int)0xCA50EF74 && h != (int)0x9FE2E6D1))
            && fn_80290D1C(o, x) == 1) {
            return 0;
        }
    }
    return 1;
}

void Unk8027DE3C::fn_8027EB34(int st, Unk80270BA0_X* x)
{
    switch (st) {
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
        x->m948.y = x->m93C.y = -1000.0f;
        break;
    case 1:
        SetVec(x->m93C, fn_802850EC());
        SetVec(x->m948, fn_802850EC());
        break;
    default:
        x->m948.y = -1000.0f;
        if (m28 != 0) {
            if (fn_802853E4() == 0) {
                SetVec(x->m93C, fn_80286E70());
            } else {
                x->m93C.y = -1000.0f;
            }
        } else {
            x->m93C.y = -1000.0f;
        }
        break;
    }
}

/* near-miss (about 98%): identical but for two instructions of the idx==1 store
 * (retail: "li r9,288; stwx rZ,rP,r9" with the zero hoisted to r11 and the index
 * reloaded) and r9/r11 for the index. Tried: shared zero local, [-1] indexing,
 * q[-1], cast pointer arithmetic, q = &p->m120[idx] reuse. */
void Unk8027DE3C::fn_8027EC58(Unk80270BA0_X* x, int h)
{
    Unk802726BC_Angles* p = &x->m734;
    Unk80271DBC_Link* link = x->m618;
    int r = 0;
    int* q = &p->m120[p->m190];
    int old = *q;
    int v;
    switch (m78) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        v = 0x63A1DF0F;
        break;
    case 8:
        v = (int)0xEA68D008;
        break;
    case 12:
    case 13:
        v = (int)0xEFF17291;
        break;
    case 1:
        if (h == 0x7942CA79 || h == (int)0xFA52B1B5 || h == (int)0xA84A0C58 || h == (int)0xF90D27A1) {
            v = 0x7942CA79;
        } else {
            v = (int)0xFA52B1B5;
        }
        break;
    default:
        if (p->m190 == 1) {
            p->m120[0] = 0;
        }
        v = (int)0xA32A6AB4;
        q = &p->m120[p->m190];
        *q = 0;
        if (mE8 & 0x400000) {
            float t = (float)x->m44C->m4C * 0.016666668f;
            if (!(m98 - t <= 0.5f)) {
                Unk80273498_Vec3 pos = fn_80286E70();
                r = fn_8027B1A0(x, &pos);
                if (p->m190 == 1) {
                    p->m120[0] = r;
                }
                q = &p->m120[p->m190];
                *q = r;
            }
            if (fn_80285498() != 0 || link->m83C == 0x27C57C8B) {
                v = 0x27C57C8B;
            }
        }
        break;
    }
    fn_80381E9C(link, v, 0, 0);
    if (h == v && v == (int)0xA32A6AB4 && r != old) {
        fn_80381B38(x->m618);
    }
}

int Unk8027DE3C::fn_8027EE9C(Unk80270BA0_X* x, int h)
{
    int v = 0;
    if (h == (int)0xA713FF5B || h == (int)0xCA0C5FC1) {
        v = 0x67A49CBA;
    } else if (h == 0x3453C76B || h == 0x44D39191) {
        v = 0x2D9F492A;
    }
    if (v != 0) {
        fn_80381E9C(x->m618, v, 0, 0);
        if (h != v) {
            return 1;
        }
    }
    return 0;
}

float Unk8027DE3C::fn_8027EF48(float a)
{
    float r = 100.0f;
    float t = fn_80286F9C() - a;
    if (!(t <= 0.0f)) {
        r = mC8 / t;
    }
    return r;
}

inline int IsStateGroup(int st)
{
    switch (st) {
    case 9:
    case 10:
    case 11:
    case 14:
        return 1;
    }
    return 0;
}

float Unk8027DE3C::fn_8027F28C(Unk80270BA0_X* x, float a)
{
    unsigned changed = 0;
    if (mC <= 2) {
        if (IsStateGroup(m78)) {
            Unk80273498_Pos* ball = fn_8027B304(x);
            int hit = 0;
            if (mE8 & 0x1000) {
                if (a == 100.0f || ball->m60.y > 216.0f) {
                    hit = 1;
                } else {
                    int id = x->m44C->m700->m3B8;
                    float t = fn_801DC5C4(id);
                    if (!(t <= 0.0f)) {
                        if (!(t >= fn_80286F9C() - 0.15f)) {
                            Unk8027DE3C_Holder* h = fn_801DC570(id);
                            if (h->fn_8026D940(0) != 0) {
                                Unk8027DE3C_Slot* s = h->m934;
                                Unk8027DE3C* sub = 0;
                                if (s->m10 == 6) {
                                    sub = &s->m18;
                                }
                                if (sub != 0 && !(sub->mE8 & 0x100)) {
                                    hit = 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((m7C == 2 || m7C == 4) && a == 100.0f && m28 != 0) {
                    Unk80273498_Vec3 v1 = fn_8018959C(ball, 0.3f);
                    Unk80273498_Vec3 v2 = fn_80286E70();
                    if (!((v1.x - v2.x) * (v1.x - v2.x) + (v1.z - v2.z) * (v1.z - v2.z) <= 1296.0f)) {
                        hit = 1;
                    }
                }
            }
            if (hit) {
                if (m7C == 2 || m7C == 4) {
                    m78 = 0x19;
                } else {
                    m78 = 0x18;
                }
                changed = 1;
            }
        }
    }
    if (m78 == 0x1A && mC <= 3 && !(a <= 1.5f)) {
        m78 = 0x1B;
        changed = 1;
        mE8 |= 0x1000;
    }
    return (float)changed;
}

inline void SetAngle2(Unk802726BC_Angles* p, float t)
{
    if (p->m190 == 1) {
        p->m48[0] = t;
    }
    float* q = &p->m48[p->m190];
    *q = t;
}

inline void SetAngle(Unk802726BC_Angles* p, float v)
{
    SetAngle2(p, v);
}

inline void SetFloat(float& dst, float v)
{
    dst = v;
}

inline float LenSq(Unk80273498_Vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

/* The clamps use g++'s >? (maximum) operator for the lower bound; see PATTERNS,
 * "In-place float clamp". */
float Unk8027DE3C::fn_8027EFB8(Unk80270BA0_X* x, float a)
{
    float hi = 1.3f;
    float lim = 0.5f;
    if (!(mE8 & 0x2000000)) {
        switch (m7C) {
        case 2:
        case 3:
        case 4:
            hi = 5.0f;
            if (fn_8026DAA4(x, 0) != 0) {
                hi = 1.3f;
            }
            break;
        case 1: {
            hi = 1.3f;
            float t = fn_80286F9C() - (float)x->m44C->m4C * 0.016666668f;
            Unk80273498_Pos* ball = fn_8027B304(x);
            float lenSq = LenSq(fn_80189618(ball, t));
            float r = 20.0f;
            if (!(lenSq >= r * (r * 309.76f))) {
                float c = 1.7f;
                hi = c;
            }
            break;
        }
        }
    }
    if (mE8 & 0x20000) {
        lim = 0.05f;
        hi = 5.0f;
    }
    if (mE8 & 0x1000000) {
        if (m7C == 1) {
            lim = !(lim > 1.2f) ? (lim >? 0.8f) : 1.2f;
            hi = !(hi <= 1.2f) ? 1.2f : (hi >? 0.8f);
        } else {
            lim = !(lim > 1.6f) ? (lim >? 0.8f) : 1.6f;
            hi = !(hi > 1.6f) ? (hi >? 0.8f) : 1.6f;
        }
    }
    if ((unsigned)(m78 - 0x1A) <= 1) {
        lim = 0.6f;
        hi = 1.5f;
    }
    if (mC <= 3) {
        lim = lim >? 0.75f;
    }
    float result = !(a > hi) ? (a >? lim) : hi;
    return result;
}

/* near-miss: 175 of 181 instructions. The clamp (>? operator) and the frame (SetAngle
 * as two nested inlines, each with its own 8-byte-aligned inline frame: 0x30, 0x38)
 * match. Left: the 0 / 5 constants for m95C / m958 get r11 / r0 (retail r0 / r11;
 * local-alloc priority from the sched1 order), and "addi r3,r30,0x734" is scheduled
 * one slot before "lfs f0,0x10(r1)". Tried: the four store orders, a SetAngle(x, v)
 * wrapper, a pointer local in the wrapper, reference and pointer inner forms. */
void Unk8027DE3C::fn_8027F504(Unk80270BA0_X* x, int h, float f)
{
    int a = 0;
    int b = 1;
    switch (h) {
    case (int)0x9FE2E6D1:
    case (int)0xCA50EF74:
        if (mC > 3) {
            break;
        }
    case 0x7942CA79:
        a = 1;
        break;
    case (int)0xF90D27A1:
    case (int)0xFA52B1B5:
        a = 0;
        break;
    default:
        b = 0;
        break;
    }
    if (b != 0) {
        x->m938 = 1;
    }
    if (a != 0) {
        float side = 0.0f;
        if (x->fn_vslot23() != 0) {
            side = -side;
        }
        float ang = fn_80410CE8(m1C, m24) - side;
        float cur = fn_80382BB8(x->m618);
        float diff = AngleDiff(ang, cur);
        x->m95C = 0;
        x->m958 = 5;
        SetFloat(x->m954, diff * 0.2f);
    }
    if (h == (int)0xA84A0C58 || h == (int)0xFA52B1B5 || h == (int)0xF90D27A1) {
        if (!(f <= 0.0f)) {
            float k = fn_80382BD8(x->m618, 0);
            float w = lbl_8061E6CC * (1.0f - k);
            float v = (mC8 + w) / f;
            v = !(v <= 0.0f) ? (!(v > 5.0f) ? (v >? 1.0f) : 5.0f) : 5.0f;
            SetAngle(&x->m734, v);
        }
    }
}

int Unk8027DE3C::fn_8027FC20(int a)
{
    int r = 0;
    switch (a) {
    case 2:
        r = lbl_806242B4;
        break;
    case 4:
        if ((unsigned)(m78 - 0x18) <= 1) {
            r = lbl_806242B4;
        } else {
            r = 0x971949A6;
        }
        break;
    case 5:
        r = 0x8BF0ACA6;
        break;
    }
    return r;
}

/* near-miss: instruction-identical except register numbers (p in r11 vs r10,
 * idx*4 in r9 vs r11) and the scheduling of the 54.0f multiply; 5 variants tried */
int Unk8027DE3C::fn_8027FC80(Unk80270BA0_X* x)
{
    Unk802726BC_Angles* p = &x->m734;
    float* q = &p->m30[p->m190];
    float lo = *q;
    if (!(lo <= x->mAB4 * 54.0f)) {
        float* r = &p->m40[p->m190];
        float hi = *r;
        float d = AngleDiff(hi, 3.1415927f);
        if (__builtin_fabsf(d) < 0.7853982f) {
            return 1;
        }
    }
    return 0;
}
