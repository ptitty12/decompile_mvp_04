/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic after userpickupballgoal (33 functions). Original file boundary unknown; placeholder.
 *
 * .text 0x8029EE50-0x802A3704 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 *
 * Status: 22/33 match. Near-misses carry a note above them. Not written (the
 * original assembly stays): fn_8029EFAC and fn_8029FB9C (about 760 instructions
 * each, the goal state functions), fn_802A1D7C (496, float compares kept as
 * values) and fn_802A30B0 (214, a dozen by-value Vec3 temporaries).
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

/* near-miss: 395 of 395 instructions, 84%. The prologue and the three
 * fn_8029CFDC argument copies match (FlatPosOf, non-const lbl_805DED34/4C). Retail
 * keeps the results of the two AngleDiff calls in named float slots (+0x48 and
 * +0x4C, one store/reload pair each); naming them here grows the frame to 184.
 * The operator- temporary of `zero - pos` also lands at +0x68 here, +0x58 in
 * retail, and the loads of the global zero vector are scheduled later. */
int fn_802A0754(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    Unk80271DBC_Link* link = x->m618;
    Unk80273498_Vec3 pos = FlatPosOf(x);
    float cur = fn_80382BB8(link);
    int state = fn_802A2604(g, x, f, g->m48);
    int s = fn_802A1790(g, x, f);
    if (s != 0x11) {
        return s;
    }
    if (state == 7 || state == 5 || state == 6 || state == 9) {
        int kind = g->m48;
        unsigned int hash = 0x12A7B064;
        if (kind == 5) {
            hash = 0xEF34393E;
        }
        if (kind == 6) {
            Unk80273498_Vec3 a = pos;
            Unk80273498_Vec3 b = lbl_805DED34;
            fn_8029CFDC(g, &a, &b);
        } else if (kind == 7) {
            if (g->m60) {
                Unk80273498_Vec3 b = pos;
                Unk80273498_Vec3 a = g->m60->m60;
                fn_8029CFDC(g, &b, &a);
            }
        } else {
            Unk80273498_Vec3 b = pos;
            Unk80273498_Vec3 a = lbl_805DED4C;
            fn_8029CFDC(g, &b, &a);
        }
        if (!fn_8029D7C4(g) || !fn_802A168C(g, x, g->m70, hash)) {
            Unk802726BC_Angles* p = &x->m734;
            Unk8029B70C_Mirror98(p, AngleDiff(cur, g->m70));
            Unk8029B70C_Mirror108(p, AngleDiff(g->m70, g->m6C));
            Unk80273498_Vec3 zero = lbl_806055AC;
            float speed = 0.0f;
            ((Unk8027A84C*)g)->fn_8027AAB0(x, hash, lbl_806242B4, &speed, &zero, 0, 0);
            float dist = fn_804028E4(LenSq3(FlatPos(zero - pos)));
            float q = dist / speed;
            dist = !(dist > 120.0f) ? (dist >? 12.0f) : 120.0f;
            Unk8029B70C_Mirror8(p, f);
            Unk8029B70C_Mirror48(p, -1.0f);
            float k = f / ((Unk802A2604_Player*)x)->m72C;
            k = !(k > 1.0f) ? (k >? 0.1f) : 1.0f;
            float v = g->m48 == 5 ? lbl_8061E7D4 : lbl_8061E7D8;
            float w = v / q * k;
            Unk8029B70C_Mirror50(p, w);
            Unk8029B70C_Mirror110(p, g->m6C);
            fn_80381E9C(link, hash, 0, 0);
            if (link->m838 != hash) {
                return state;
            }
            if (!(x->m71C & 0x2000)) {
                g->mD0.f4 = 1;
            }
            fn_80244858(x, g->m70);
        }
        g->mD0.f7 = 1;
    }
    return state;
}

int fn_802A0D80(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    Unk8014D8AC_Ctx* ctx = x->m44C;
    float now = (float)ctx->m4C * 0.016666668f;
    unsigned int flags = *(unsigned int*)&g->mD0;
    Unk80271DBC_Link* link = x->m618;
    if (g->mD0.f6) {
        if (!(now <= g->m5C)) {
            Unk8029B70C_Mirror8(&x->m734, 0.0f);
            g->mD0.f6 = 0;
            return 1;
        }
        if (!(now <= g->m58)) {
            Unk8029B70C_Mirror8(&x->m734, ((Unk802A2604_Player*)x)->m728);
            g->mD0.f6 = 0;
            return 3;
        }
        if (!(now <= g->m54)) {
            Unk80270BA0_X* other = ((Unk8029B70C_Pos*)ctx->m6CC)->m36C;
            if (other && other != x) {
                g->mD0.f6 = 0;
                return 1;
            }
        }
    }
    unsigned int cur = link->m838;
    if (cur != g->m50) {
        return 0xA;
    }
    int hit = flags & 0x02000000;
    if (!hit) {
        float t = 0.0f;
        Unk8029B70C_Query q;
        q.mBC = 0;
        fn_80386110(x->m618, &q, cur, 0x971949A6, &t, 0);
        q.mBC = 0;
        g->m54 = now + t;
        float b = 0.0f;
        if (fn_80386110(x->m618, &q, g->m50, 0xFF0D1452, &b, 0) & 0x10000) {
            g->m5C = now + b;
            g->m58 = now + 9999.0f;
            if (!(g->m5C >= g->m54)) {
                g->m5C = g->m54;
            }
        }
        q.mBC = 0;
        float c = 0.0f;
        if (fn_80386110(x->m618, &q, g->m50, 0x989091AD, &c, 0) & 0x10000) {
            g->m58 = c + now;
            g->m5C = now + 9999.0f;
            if (!(g->m58 >= g->m54)) {
                g->m58 = g->m54;
            }
        }
        g->mD0.f6 = 1;
    }
    g->mD0.f7 = 0;
    return 0xA;
}

int fn_802A1070(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    Unk80271DBC_Link* link = x->m618;
    float now = (float)x->m44C->m4C * 0.016666668f;
    if (g->mD0.f6) {
        if (!(now <= g->m54)) {
            fn_80249B40(x, 0, 0, 0, 0.2f);
            return 1;
        }
    }
    if (fn_8026D8E8(x, 0) || fn_8026D914(x, 0)) {
        return 1;
    }
    if (link->m838 != g->m50) {
        return 0xB;
    }
    if (fn_80380964(link)) {
        return 0xB;
    }
    if (!g->mD0.f6) {
        float t = 0.0f;
        Unk8029B70C_Query q;
        q.mBC = 0;
        fn_80386110(x->m618, &q, g->m50, 0x440397DE, &t, 4);
        g->m54 = now + t;
    }
    g->mD0.f6 = 1;
    g->mD0.f7 = 0;
    return 0xB;
}

/* near-miss: 240 of 240 instructions, 97.2%. Retail's first store of the int slot
 * at +0x158 is `li r9,0x158; stwx r11,r30,r9` (the same idiom as in fn_80280F08,
 * tu_8027FD64.cpp, and fn_802977FC, tu_8028F178.cpp); here it folds into
 * `stw r11,0x158(r30)`, which also lets the next float store move up.
 * Found: the idiom appears when the offset is computed from an index that is a
 * variable at inline time (`int zi = 0; Set158(p, zi, 0);` with
 * `int off = i * 4 + 0x158; *(int*)((char*)a + off) = v;`), but the constant then
 * lands in r0 (retail: r9) and the stfs still moves, so the score does not improve. */
int fn_802A11FC(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    Unk80271DBC_Link* link = x->m618;
    unsigned int cur = link->m838;
    int a = fn_8026DC5C(x, 0);
    int b = fn_8026DB3C(x, 0);
    g->m50 = ((Unk8027A84C*)g)->fn_8027BB88(x, (Unk8027BBA8_Obj*)g->m60, a, b, 1);
    if (g->m50) {
        g->mD0.f6 = 0;
        return 0xB;
    }
    if (!g->m60 || !fn_8027D708(g, (Unk8027C728_Player*)x, (Unk8027C728_Player*)g->m60)) {
        return 3;
    }
    float ang;
    if (g->mD0.f1) {
        ang = g->m6C;
    } else {
        ang = g->m70;
    }
    Unk802726BC_Angles* p = &x->m734;
    Unk8029B70C_Mirror48(p, -1.0f);
    Unk8029B70C_Mirror158(p, 0);
    Unk8029B70C_Mirror10(p, ang);
    Unk8029B70C_Mirror140(p, ang);
    Unk8029B70C_Mirror18(p, 3);
    Unk8029B70C_Mirror8(p, f);
    fn_80381E9C(link, 0x6A939117, 0, 0);
    if (cur == 0x6A939117) {
        if (g->mC <= 3) {
            const float zero = 0.0f;
            float speed = zero;
            Unk80273498_Vec3 vec;
            ((Unk8027A84C*)g)->fn_8027A9AC(x, 0x6A939117, lbl_806242B4, &speed, (int)&vec, 0, 0);
            vec.y = zero;
            g->m98 = fn_804028E4(LenSq3(vec)) / speed;
        }
        float k = f / g->m98;
        Unk8029B70C_Mirror48(p, k);
        float diff = AngleDiff(ang, fn_80382BB8(x->m618));
        if (!(diff >= -2.3561945f)) {
            diff = diff + 6.2831855f;
        }
        ang = diff * 0.1f + fn_80382BB8(x->m618);
        fn_80244858(x, ang);
        g->mD0.f7 = 0;
        if (f < ((Unk802A2604_Player*)x)->m720) {
            return 1;
        }
    }
    return 0xD;
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

int fn_802A168C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f, unsigned int hash)
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

/* near-miss: 379 of 379 instructions, about 80%. The control flow, the register
 * assignment (r22-r31) and the first 44 frame offsets match. Retail's frame is
 * 312 bytes, here 280: retail allocates the by-value Vec3 temporaries of the
 * Scale/Dir inlines at +0x80/+0x90 and the Dir frame at +0xA0 (here they are packed
 * lower), and it keeps h2, eps and len at +0xF8/+0xFC/+0x100 above the operator+
 * result. */
int fn_802A1790(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f)
{
    Unk80273498_Vec3 pos = FlatPosOf(x);
    Unk802A1790_Pos* p = (Unk802A1790_Pos*)x->m44C->m6CC;
    Unk80273498_Vec3 ppos = p->m60;
    if (p->m36C == 0) {
        {
            Unk80273498_Vec3 a = pos;
            Unk80273498_Vec3 b = ppos;
            if (!fn_8029CFDC(g, &a, &b)) {
                if (!(ppos.y <= 120.0f)) {
                    fn_80189618(&a, (Unk8018959C_Obj*)p, 0.0f);
                    float yaw = Unk802A1790_Yaw(-a);
                    g->m70 = yaw;
                    g->mD0.f2 = 1;
                }
            }
        }
        int flagB = 0;
        fn_802A28EC(g, x, (Unk80273498_Pos*)p);
        int flagC = 0;
        int is34 = (unsigned int)(g->m48 - 3) <= 1;
        if (is34) {
            float t = ((Unk802A2604_Player*)x)->m724;
            if (g->m48 == 4) {
                t *= fn_8024D0C4(x, 0x48, 0.0f, 1.0f);
            }
            if (!(f >= t)) {
                flagB = 1;
            }
        } else {
            flagB = 1;
        }
        if (!flagB || (fn_8026D628(x, 0) && !(f <= 0.0f))) {
            if (fn_8024D408(x)) {
                int c = 0;
                if (p->m38C == 1 || p->m390 == 1) {
                    c = 1;
                }
                if (c) {
                    Unk80273498_Vec3 w = x->m60;
                    float h = 0.0f;
                    fn_80191068(p, &w, 0, &h, lbl_8061E858, lbl_8061E85C);
                    if (!(h >= lbl_8061E850)) {
                        if (fn_8026D654(x, 0)) {
                            flagB = 1;
                        } else {
                            float ang = fn_80382BB8(x->m618);
                            Unk80273498_Vec3 off = Unk802A1790_Scale(Unk802A1790_Scale(Unk802A1790_Dir(ang), f), 0.35f);
                            float h2 = 0.0f;
                            Unk802A1790_Probe(p, w + off, &h2);
                            if (!(h2 <= lbl_8061E854)) {
                                float eps = 65.0f;
                                flagB = 1;
                                Unk80273498_Vec3 v;
                                fn_80189618(&v, (Unk8018959C_Obj*)p, 0.3f);
                                float len = LenSq3(v);
                                if (!(len <= eps * (eps * 309.76f))) {
                                    if (!fn_8026DC18(x, 0)) {
                                        flagC = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int r = fn_8029D7D4(g, x, (int)p, is34, flagB, flagC);
        if (r == 1) {
            return 0xA;
        }
        if (r == 2) {
            return 0xC;
        }
        return 0x11;
    }
    g->mD0.f2 = 0;
    if (g->m60) {
        fn_802A2A64(g, x, g->m60);
        int flag = 0;
        g->m70 = fn_80410CE8(g->m60->m60.x - pos.x, g->m60->m60.z - pos.z);
        g->mD0.f2 = 1;
        int a = fn_8026DC5C(x, 0);
        if (!a || fn_8026DB3C(x, 0)) {
            flag = 1;
        }
        g->m50 = ((Unk8027A84C*)g)->fn_8027BB88(x, (Unk8027BBA8_Obj*)g->m60, a, flag, 1);
        if (g->m50) {
            g->mD0.f6 = 0;
            return 0xB;
        }
        if (!(f <= ((Unk802A2604_Player*)x)->m720)) {
            if (fn_8027D708(g, (Unk8027C728_Player*)x, (Unk8027C728_Player*)g->m60) == 1) {
                return 0xD;
            }
        }
    }
    return 0x11;
}

int fn_802A253C(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    if (g->m60) {
        Unk80273498_Vec3 pos = FlatPosOf(x);
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

/* near-miss: 70 of 70 instructions, about 96%. Same instructions as retail; the
 * 3600.0f constant load is scheduled before the loads of the second position
 * here and after them in retail (so the position pointer takes r10, not r9).
 * Retail forms the pointer to the second position first, which the swapped
 * argument order of SubR reproduces. Tried: no named Vec3, a by-value LenSq, a
 * float local, `>` instead of `!(<=)`. */
/* near-miss: 70 of 70 instructions, 95%. Same instructions as retail; the 3600.0f
 * constant load is scheduled before the vector subtraction here and after it in
 * retail, and the two position pointers take their registers in the other order.
 * Tried: no named Vec3, a by-value LenSq, a float local, `>` instead of `!(<=)`. */
inline Unk80273498_Vec3 Unk802A2A64_SubR(const Unk80273498_Vec3& b, const Unk80273498_Vec3& a)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

void fn_802A2A64(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80273498_Pos* p)
{
    if (x && p) {
        Unk80273498_Vec3 d = Unk802A2A64_SubR(p->m60, x->m60);
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

/* near-miss: 90 of 90 instructions, 95%. The code is identical; only the registers
 * differ. Retail keeps the goal in r3 (never copied), the player in r10 and the link
 * in r8; here the link takes r3, the goal r10 and the player r8 (global allocation
 * priority of the link pseudo). 36 spellings (link local at the top, after the kind
 * or absent; `cur` local or inline; three forms of the return value; int or unsigned
 * hash) compile to the same registers. The case order 1,2,5,6,3,7,4,8,9 is
 * retail's block order. */
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

/* near-miss: 170 of 170 instructions, 97.8%. Retail copies the vector `v` into
 * x->m960 with loads straight off the frame (8/12/16(r1)); here the second and
 * third word come through the pointer register that the initial copy of the
 * global created (4/8(r27)). Tried: a by-value or const& SetPos inline and all 24
 * orders of the four head statements. The second ratio test is an if/else chain
 * because `switch (n) { case 2: break; case 1: ... }` drops the empty case. */
inline void Unk802A3408_SetM320(Unk80270BA0_X* x, const Unk80273498_Vec3& v)
{
    ((Unk802A3408_Player*)x)->m320 = v;
}

int fn_802A3408(Unk802A309C_Goal* g, Unk80270BA0_X* x)
{
    int play = 0;
    unsigned int hash;
    Unk80273498_Vec3 v = lbl_806055AC;
    Unk802A3408_SetXY(x, 1.0f, 1.0f);
    x->m960 = v;
    x->m974 = 0;
    x->m978 = 0;
    Unk80271DBC_Link* link = x->m618;
    switch (g->m48) {
    case 2:
        play = 1;
        hash = 0xBF270656;
        break;
    case 1:
        play = 1;
        hash = 0x3C188866;
        break;
    case 3:
        hash = 0x62F631D0;
        break;
    default:
        hash = 0;
        break;
    }
    if (play) {
        if (g->m4C == 0) {
            if (link->m838 == 0x94C34DBD) {
                fn_80381E9C(link, hash, 0, 0);
                g->m50 = 1;
            } else {
                fn_80381E9C(link, 0x94C34DBD, 0, 0);
            }
            if (g->m50 && link->m838 == hash && !fn_80380964(link)) {
                int n = fn_801CEADC(x->m44C->m700->m3A4);
                int k = 1;
                if (g->m48 == 1) {
                    switch (n) {
                    case 0:
                        break;
                    case 1:
                        k = 2;
                        break;
                    }
                } else if (g->m48 == 2) {
                    if (n == 2) {
                    } else if (n == 1) {
                        k = 0;
                    }
                }
                fn_801CEA44(&v, x->m44C->m700->m3A4, k);
                Unk80273498_Vec3 t = v;
                Unk802A3408_SetM320(x, t);
                fn_80381E9C(link, 0x94C34DBD, 0, 0);
                g->m4C = 1;
            }
            return 1;
        }
        if (link->m838 != hash) {
            fn_802A36B0(g);
            return 0;
        }
        if (fn_802A30B0(g, x)) {
            fn_802A36B0(g);
            return 0;
        }
        return 1;
    }
    if (link->m838 == hash) {
        g->m48 = 0;
        return 0;
    }
    fn_80381E9C(link, hash, 0, 0);
    return 1;
}

void fn_802A36B0(Unk802A309C_Goal* g)
{
    fn_802A309C(g);
    fn_801CE9D8(((Unk8027A84C*)g)->fn_8027A918()->m700->m3A4);
    ((Unk802A36B0_Ctx*)((Unk8027A84C*)g)->fn_8027A918())->m720->mC8 = 1;
}
