/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic after userpickupballgoal (33 functions). Original file boundary unknown; placeholder.
 *
 * .text 0x8029EE50-0x802A3704 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 */
#include "game/goals/tu_8029EE50.h"

void fn_8029EE50(Unk8029B70C_Goal* g)
{
    g->m88 = g->m88 - (float)lbl_8061B9C8 * 0.016666668f;
    if (!(g->m88 <= 0.0f)) {
        g->mD0.f8 = 0;
    }
    if (g->mD0.f9) {
        g->m74 = g->m74 - (float)lbl_8061B9C8 * 0.016666668f;
    } else if (g->mD0.f8) {
        g->m74 = -0.016666668f;
        g->mD0.f9 = 1;
        g->m88 = 0.33333334f;
    }
}

void fn_8029EF28(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80271DBC_Link* link)
{
    if (!lbl_8061F8FC) {
        fn_802771A0(1);
        if (lbl_806EF9D4) {
            lbl_8061F8FC = 2;
            fn_802D7B88(fn_801A2034(((Unk8027A84C*)g)->fn_8027A918(), 4), 1, 1.0f, 8);
        }
        fn_802771A0(0);
    }
}

int fn_802A15BC(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    int r = fn_802A1790(g, x, fn_804028E4(x->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f));
    if (r == 0x11) {
        r = g->m48;
        if ((unsigned int)(r - 14) <= 1) {
            if (!fn_80380964(x->m618)) {
                switch (g->m48) {
                case 14:
                    return 3;
                case 15:
                    return 4;
                }
            }
            r = g->m48;
        }
    }
    return r;
}

int fn_802A168C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, unsigned int hash, float f)
{
    if (fn_8026DC18(x, 0) || fn_8026D628(x, 0) || fn_8026D988(x, 0)) {
        float now = (float)x->m44C->m4C * 0.016666668f;
        if (!(g->m78 - now >= 0.8f)) {
            Unk80271DBC_Link* link = x->m618;
            if (link->m838 != hash) {
                fn_803814A4(link, hash, 0, 3.0f);
            }
            fn_80244858(x, f);
            return 1;
        }
        return 0;
    }
    return 0;
}

int fn_802A253C(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    if (g->m60) {
        Unk80273498_Vec3 pos = FlatPos(x->m60);
        int idx;
        float d;
        if (fn_8026CF70(x, g->m60, &g->mC4, &idx, &d)) {
            if (!(d >= 14400.0f)) {
                if (!fn_8026CFF8(g->mC4, &pos, idx, &g->mB8)) {
                    return 2;
                }
            }
        }
    }
    return -1;
}

int fn_802A2604(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f, int a)
{
    int r = 1;
    float a1 = ((Unk802A2604_Player*)x)->m720;
    float a2 = ((Unk802A2604_Player*)x)->m72C;
    if (!(f <= a1)) {
        if ((unsigned int)g->mCC <= 1) {
            if (g->mD0.f15 && ((unsigned int)(a - 5) <= 1 || a == 3)) {
                g->mD0.f15 = 1;
            } else if ((unsigned int)(a - 1) <= 1) {
                g->mD0.f15 = 1;
            } else {
                g->mD0.f15 = 0;
            }
        } else {
            g->mD0.f15 = 0;
        }
        switch (g->mCC) {
        case 0:
            r = 5;
            if (!((Unk802A2604_Ctx*)((Unk8027A84C*)g)->fn_8027A918())->m6F8->m10->m188) {
                if (g->mD0.f15) {
                    if (!(f <= lbl_8061E868 * a2)) {
                        r = 3;
                    }
                } else if (a == 3) {
                    if (!(f <= lbl_8061E864 * a2)) {
                        r = 3;
                    }
                }
            }
            break;
        case 1:
            r = 6;
            if (g->mD0.f15) {
                if (!(f <= lbl_8061E868 * a2)) {
                    r = 3;
                }
            } else if (a == 3) {
                if (!(f <= lbl_8061E864 * a2)) {
                    r = 3;
                }
            }
            break;
        case 2:
            r = 7;
            break;
        case 3:
            switch (a) {
            case 1:
            case 2:
            case 9:
                r = 9;
                break;
            case 3:
            default:
                r = a;
                break;
            }
            break;
        case 4:
            switch (a) {
            case 1:
            case 2:
            case 4:
            case 9:
                r = 4;
                break;
            case 3:
            default:
                r = a;
                break;
            }
            break;
        default:
            r = 3;
            break;
        }
        g->m90 = -1;
    } else {
        switch (a) {
        case 3:
        case 4: {
            int m = g->m90;
            if (m == -1) {
                r = a;
                g->m90 = lbl_8061E7DC;
            } else if (m != 0) {
                r = a;
                g->m90 = m - 1;
            }
            break;
        }
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        default:
            r = a;
            break;
        }
        if (r == 1 && g->mCC == 2) {
            r = 8;
        }
    }
    if (lbl_8061E7A4 && r == 4) {
        r = 3;
    }
    if (lbl_80691DE0 && r == 3) {
        r = 4;
    }
    return r;
}

float fn_802A28A4(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    float r = 0.0f;
    if (g->mD0.f0) {
        r = fn_80249188(x, g->m68);
    }
    return r;
}

void fn_802A28EC(Unk8029B70C_Goal* g, Unk80270BA0_X* a, Unk80273498_Pos* b)
{
    if (a && b) {
        Unk80273498_Vec3 va = FlatPos(a->m60);
        Unk80273498_Vec3 vb = b->m60;
        float lenSq = LenSq3(va - vb);
        if (!(lenSq <= 3600.0f || lenSq >= 921600.0f)) {
            fn_80249DF8(a, 1);
            fn_80249B08(a, 1, 0.2f);
        } else if (a->mB3C & 0x10000000) {
            fn_80249B40(a, 0, 0, 0, 0.2f);
            fn_80249DF8(a, 0);
        }
    }
}

void fn_802A2A64(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80273498_Pos* p)
{
    if (x && p) {
        Unk80273498_Vec3 d = x->m60 - p->m60;
        if (!(LenSq3(d) <= 3600.0f)) {
            fn_80249DF8(x, 1);
            fn_80249B40(x, p, 0, 0, 0.2f);
        } else if (x->mB3C & 0x10000000) {
            fn_80249B40(x, 0, 0, 0, 0.2f);
            fn_80249DF8(x, 0);
        }
    }
}

void fn_802A2B7C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* out, int a, Unk80273498_Vec3* b, int c, int d, float f)
{
    ((Unk8027A84C*)g)->fn_8027AC90((Unk8037B128_Mtx*)out, d, c, b);
    out->mD8 = 0;
}

int fn_802A2BC0(Unk8029B70C_Goal* a, Unk8029B70C_Goal* b)
{
    if (b) {
        a->m6C = b->m6C;
        a->m60 = b->m60;
        a->mD0.f1 = b->mD0.f1;
        a->m68 = b->mD0.f0 ? b->m68 : -1.0f;
        a->mD0.f0 = b->mD0.f0;
        a->mD0.f8 = b->mD0.f8;
        return 1;
    }
    return 0;
}

float fn_802A2C40(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    float a = 1.5f;
    float b = 0.8f;
    if (x->m71C & 0x2000) {
        return b;
    }
    return a;
}

int fn_802A2C7C(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    unsigned int hash = 0;
    Unk80271DBC_Link* link = x->m618;
    switch (g->m48) {
    case 0:
    case 15:
    case 18:
        return 0;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
        hash = 0x64FBD939;
        break;
    case 5:
        hash = fn_8026D578(x, 0) ? 0x64E185D4 : 0x64FBD939;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        hash = 0x64E185D4;
        break;
    }
    Unk802726BC_Angles* p = &x->m734;
    Unk8029B70C_Mirror90(p, g->m48);
    fn_80381E9C(link, hash, 0, 0);
    if (link->m838 == hash) {
        g->m48 = 0;
        return 0;
    }
    return 1;
}

void fn_802A2DA4(Unk802A2DA4_Goal* g)
{
    g->m0 = 2;
    g->m4C = -1.0f;
    g->m48 = -1.0f;
}

Unk802A2DA4_Goal* fn_802A2DC0(Unk802A2DA4_Goal* g, float f)
{
    g->m4C = -1.0f;
    g->m48 = f;
    return g;
}

inline void Unk802A2DE8_Max(int& a, int b)
{
    if (b > a) {
        a = b;
    }
}

int fn_802A2DE8(Unk802A2DA4_Goal* g)
{
    Unk8014D8AC_Ctx* ctx = ((Unk8027A84C*)g)->fn_8027A90C()->m44C;
    float now = (float)ctx->m4C * 0.016666668f;
    if (g->mC <= 2) {
        if (!(g->m48 <= 0.0f)) {
            g->m4C = now + g->m48;
        }
    }
    if (!(now <= g->m4C)) {
        return 0;
    }
    Unk802A2DE8_Max(g->mC, 4);
    return 1;
}

/* near-miss: 23 of 23 instructions, 11 differ: retail keeps `out` in r31
 * (stw r31, no stmw) and spills the unused float parameter first. Here the
 * single-block pseudo lands in r30. Tried: local float, += form, member cast,
 * &out->m0, an inline Add(float*, float) and Add(float&, float) (this one). */
inline void Unk802A2EB0_Add(float& dst, float v)
{
    dst = dst + v;
}

void fn_802A2EB0(Unk802A2DA4_Goal* g, Unk80270BA0_X* x, Unk80279BB8* out, int a, Unk80273498_Vec3* b, int c, int d, float f)
{
    Unk802A2EB0_Add(out->mD4, g->m48);
    ((Unk8027A84C*)g)->fn_8027AC90((Unk8037B128_Mtx*)out, d, c, b);
    out->mD8 = 1;
}

int fn_802A2F0C(Unk802A2DA4_Goal* a, Unk802A2DA4_Goal* b)
{
    return b != 0;
}

void fn_802A2F20(Unk802A2F20_Goal* g)
{
    g->m48 = 0;
}

int fn_802A2F2C(Unk802A2F20_Goal* g, Unk80270BA0_X* x)
{
    int kind = g->m48;
    unsigned int hash;
    switch (kind) {
    case 1:
        hash = 0x128EDBC5;
        break;
    case 2:
        hash = 0x85882CD7;
        break;
    case 5:
        hash = 0x1BD7330D;
        break;
    case 6:
        hash = 0x9913AB0D;
        break;
    case 3:
        hash = 0x4FD07A76;
        break;
    case 7:
        hash = 0xFBCD00CC;
        break;
    case 4:
        hash = 0x99F6097B;
        break;
    case 8:
        hash = 0x87D389D9;
        break;
    case 9:
        hash = 0xBFED16BE;
        break;
    default:
        return 0;
    }
    unsigned int cur = x->m618->m838;
    if (cur == hash || (kind == 3 && cur != 0x53CFCF84) || (kind == 7 && cur != 0x18AC23C2)) {
        g->m48 = 0;
        return x->m44C->m6F4 == 3 ? 2 : 0;
    }
    fn_80381E9C(x->m618, hash, 0, 0);
    return 1;
}

int fn_802A3094(Unk802A2F20_Goal* a, Unk802A2F20_Goal* b)
{
    return 0;
}

void fn_802A309C(Unk802A309C_Goal* g)
{
    g->m48 = 0;
    g->m4C = 0;
    g->m50 = 0;
}

void fn_802A36B0(Unk802A309C_Goal* g)
{
    fn_802A309C(g);
    fn_801CE9D8(((Unk8027A84C*)g)->fn_8027A918()->m700->m3A4);
    ((Unk802A36B0_Ctx*)((Unk8027A84C*)g)->fn_8027A918())->m720->mC8 = 1;
}
