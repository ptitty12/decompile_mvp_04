/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic between cShortestPathChooser and catchgoal.cpp.
 * Original file name unknown; placeholder. 25 functions.
 *
 * .text 0x8027A84C-0x8027C728, .rodata 0x805DCF60-0x805DD040, .data 0x8061E6A0-0x8061E6C8.
 *
 * .data 0x8061E6A0-0x8061E6C8 is assigned here so the split has no gap;
 * 0x8061E6B8..0x8061E6C4 are used by fn_80285238/fn_802852F0 (a later part
 * of the unity TU), whose units extern them.
 *
 * Status: 15/25 match. Near-misses are noted above their functions (fn_8027A84C,
 * A9AC, AAB0, AD3C, B1A0, B924, BA64). Not attempted: fn_8027B55C (242 insns),
 * fn_8027BBA8 (458) and fn_8027C2D0 (225); fn_8027BB88 only wraps fn_8027BBA8.
 */
#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

Unk80273498_Vec3 fn_8014E388(unsigned int idx);
float fn_804028E4(float x);
float fn_80382BB8(Unk80271DBC_Link* p);
float fn_8041171C(float x);
double fn_80410634(double x);
extern float lbl_8061E6A0;
extern float lbl_8061E6A4;
extern float lbl_8061E6A8;
float fn_80411554(float x);
float fn_80410CE8(float y, float x);

inline Unk80273498_Vec3 GetPos(const Unk8037B128_Mtx* m)
{
    Unk80273498_Vec3 v = fn_8037B128(m);
    return v;
}

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Unk80273498_Vec3 operator+(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Unk80273498_Vec3 operator*(Unk80273498_Vec3 v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline Unk80273498_Vec3 Direction(float angle)
{
    Unk80273498_Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
    return r;
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

/* near-miss (stores scheduled in a different order; same instructions): 12 stores, source order is the
 * retail order but sched1 permutes them. 200 random permutations tried, none match. */
void Unk8027A84C::fn_8027A84C(Unk8027A84C_Owner* owner)
{
    m3C = -1;
    m38 = 2;
    m40 = 5;
    mC = 0;
    m44 = owner;
    m34 = 2;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m4 = (Unk8027A84C*)((char*)owner + 0x104);
    m4->m48 = this;
    m8 = (char*)owner + 0x294;
}

void Unk8027A84C::fn_8027A898(const Unk80273498_Vec3* v)
{
    m1C = *v;
    m2C = v->x != 0.0f || v->z != 0.0f || v->y != 0.0f;
}

Unk8027A84C_Owner* Unk8027A84C::fn_8027A8F0()
{
    if (m44) {
        return m44->m0;
    }
    return 0;
}

Unk80270BA0_X* Unk8027A84C::fn_8027A90C()
{
    return m44->mC;
}

Unk8014D8AC_Ctx* Unk8027A84C::fn_8027A918()
{
    return m44->mC->m44C;
}

float Unk8027A84C::fn_8027A928()
{
    float r = 0.0f;
    switch (m38) {
    case 0:
        r = 0.0f;
        break;
    case 1:
        r = 0.25f;
        break;
    case 2:
        r = 0.5f;
        break;
    case 3:
        r = 0.75f;
        break;
    case 4:
        r = 1.0f;
        break;
    }
    return r;
}

/* near-miss: only the first 15 instructions differ (order of the inlined request constructor's
 * stores: retail loads the bitfield word first and stores m68.m8/m4 after it, through the
 * pointer register). 5 variants of the constructor tried (member ctors, flat body, pointer
 * locals, 720 permutations of the six stores). */
int Unk8027A84C::fn_8027A9AC(Unk80270BA0_X* x, int a, int b, float* c, int d, int e, int f)
{
    Unk8027A9AC_Req req;
    req.mtx = lbl_8060E938;
    req.m40 = 0.0f;
    req.mBC = 0xB;
    req.mA0 = a;
    int fl = 0;
    if (f) {
        fl = 4;
    }
    return fn_8038614C(x->m618, &req, a, b, c, d, e, 0, fl | 1);
}

/* near-miss: same constructor-prefix difference as fn_8027A9AC; the rest matches. */
int Unk8027A84C::fn_8027AAB0(Unk80270BA0_X* x, int a, int b, float* c, Unk80273498_Vec3* d, float* e, int f)
{
    Unk8027A9AC_Req req;
    float angle = fn_80382BB8(x->m618);
    float s = fn_8041171C(angle);
    float cs = fn_80411554(angle);
    int r;

    if (x->m0 == 0) {
        fn_8037D768(x);
    }
    x->m0 = 1;
    req.mtx = x->m20;
    req.mtx.r[0][0] = cs;
    req.mtx.r[0][1] = 0.0f;
    req.mtx.r[0][2] = -s;
    req.mtx.r[1][0] = 0.0f;
    req.mtx.r[1][1] = 1.0f;
    req.mtx.r[1][2] = 0.0f;
    req.mtx.r[2][0] = s;
    req.mtx.r[2][1] = 0.0f;
    req.mtx.r[2][2] = cs;
    req.m40 = 0.0f;
    req.mBC = 0xB;
    req.mA0 = a;
    int fl = 0;
    if (f) {
        fl = 4;
    }
    r = fn_80386110(x->m618, &req, a, b, c, fl | 2);
    if (d) {
        Unk80273498_Vec3 v = fn_8037B128(&req.mtx);
        *d = v;
    }
    if (e) {
        *e = fn_8037B1F0(&req.mtx);
    }
    return r;
}

void Unk8027A84C::fn_8027AC90(Unk8037B128_Mtx* m, int n, int unused, Unk80273498_Vec3* out)
{
    if (out) {
        Unk80273498_Vec3 pos = GetPos(m);
        out[0] = pos;
        out[0].y = 36.0f;
        for (int i = 1; i < n; i++) {
            out[i].x = out[0].x;
            out[i].y = 0.0f;
            out[i].z = out[0].z;
        }
    }
}

/* near-miss: heading temp slot and the else-branch position copy (retail copies m60 through a
 * 0x28 temp into a slot at sp+8; mine adds one more copy). 24 variants tried. */
void Unk8027A84C::fn_8027AD3C(Unk80270BA0_X* x, Unk8027AD3C_Obj* o, Unk80273498_Vec3* outPos, float* outHeading,
                              float* outSpeed, int* outA, int* outB, int* outC)
{
    if (o) {
        if (outPos) {
            Unk80273498_Vec3 pos = GetPos(&o->mtx);
            pos.y = 0.0f;
            *outPos = pos;
        }
        if (outHeading) {
            float h = fn_8037B1F0(&o->mtx);
            *outHeading = h;
        }
        if (outSpeed) {
            *outSpeed = o->mD0;
        }
        if (outA) {
            *outA = o->mCC;
        }
    } else {
        if (outPos) {
            Unk80273498_Vec3 t = x->m60;
            t.y = 0.0f;
            Unk80273498_Vec3 pos = t;
            *outPos = pos;
        }
        if (outHeading) {
            *outHeading = fn_80382BB8(x->m618);
        }
        if (outSpeed) {
            *outSpeed = fn_804028E4(x->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f);
        }
        if (outA) {
            *outA = x->m618->m830;
        }
    }
    if (outB || outC) {
        if (o && (o->mBC & 8)) {
            if (outB) {
                *outB = o->mA0;
            }
            if (outC) {
                *outC = 0;
            }
        } else {
            Unk80271DBC_Link* link = x->m618;
            if (outB) {
                *outB = link->m838;
            }
            if (outC) {
                *outC = fn_80380964(link);
            }
        }
    }
}

Unk80273498_Vec3 Unk8027A84C::fn_8027AF54(unsigned int idx)
{
    Unk80273498_Vec3 v = fn_8014E388(idx);
    return v;
}

void Unk8027A84C::fn_8027AFA8(Unk8014D8AC_Ctx* ctx, Unk80270BA0_X* x, int a)
{
    if (ctx->m6F4 != 1 && fn_8024D4C0(x) == 0) {
        int p0 = fn_801BBC30(ctx->m700->m3BC);
        int p1 = fn_8018AD2C(ctx->m6CC);
        int p2 = fn_801BBEFC(ctx->m700->m3BC);
        int kind = x->m458;

        if (p0 != 0 || p1 == 0) {
            if (x->mB3C & 0x10000000) {
                fn_80249B40(x, 0.2f, 0, 0, 0);
                fn_80249DF8(x, 0);
            }
        } else if (x->m450 == 0) {
            fn_80249DF8(x, 1);
            Unk80273498_Pos* t = ctx->m6CC;
            if (t->m38C == 3 && t->m374 != x) {
                Unk80273498_Vec3 v = t->m3D0;
                fn_80249958(x, &v, 0, 0.2f);
                return;
            }
            if (p2 == 0 && kind != 1 && kind != 0xE) {
                Unk80273498_Vec3 w = lbl_806055AC;
                w.y = 36.0f;
                Unk80273498_Vec3 w2 = w;
                fn_80249958(x, &w2, 0, 0.2f);
                return;
            }
            float f = 0.2f;
            if (t->m38C == 1 && kind != 1 && kind != 0xE) {
                f = 0.001f;
            }
            fn_80249B08(x, a, f);
        }
    }
}

/* near-miss: loop body identical; retail keeps the result in a callee-saved register
 * (mr r3,r29) while mine threads the constant (li r3,1). */
int Unk8027A84C::fn_8027B1A0(Unk80270BA0_X* x, const Unk80273498_Vec3* pos)
{
    Unk8014D8AC_Ctx* ctx = fn_8027A918();
    int hit = 0;

    if (ctx->m6F4 == 9) {
        return 0;
    }
    int cur = x->m458;
    Unk8014D8AC_Ctx* list = x->m44C;
    for (int i = 2; i < 9; i++) {
        if (i != cur) {
            Unk80273498_Pos* o = (unsigned int)i <= 12 ? list->m65C[i] : 0;
            Unk80273498_Vec3 p = o->m60;
            float limit = 25.0f;
            Unk80273498_Vec3 d = p - *pos;
            if (d.x * d.x + d.z * d.z < 90000.0f) {
                hit = 1;
                break;
            }
        }
    }
    return hit;
}

int Unk8027A84C::fn_8027B2CC(Unk80270BA0_X* p)
{
    return fn_8027B2F0(p->m458);
}

int Unk8027A84C::fn_8027B2F0(int x)
{
    return x >= 9 && x <= 12;
}

Unk80273498_Pos* Unk8027A84C::fn_8027B304(Unk80270BA0_X* p)
{
    if (p->m908) {
        return p->m908;
    }
    return p->m44C->m6CC;
}


void Unk8027A84C::fn_8027B31C(int state, const Unk80273498_Vec3* pos, float angle, const Unk80273498_Vec3* target,
                              int flag, float* out1, float* out2, Unk80273498_Vec3* outPos)
{
    if (out1 || out2 || outPos) {
        float dist = flag ? 36.0f : 60.0f;
        if (fn_8027B2F0(state)) {
            dist = flag ? 60.0f : 96.0f;
        }
        Unk80273498_Vec3 p = *pos + Direction(angle) * dist;
        if (outPos) {
            *outPos = p;
        }
        if (out2 || out1) {
            float a = fn_80410CE8(target->x - p.x, target->z - p.z);
            if (out1) {
                *out1 = a;
            }
            if (out2) {
                *out2 = AngleDiff(a, angle);
            }
        }
    }
}

/* near-miss: same instructions; stack slots differ (retail: Vec3 at sp+0x10, thresholds at
 * sp+0x20, d2 at sp+0x2c). 36 declaration-placement variants tried. */
int Unk8027A84C::fn_8027B924(Unk80270BA0_X* x, Unk8018959C_Obj* o, float f)
{
    if (o->m36C == 0) {
        float vy = fn_8018959C(f, o).y;
        if (!(vy >= 12.0f)) {
            float th[3];
            th[0] = lbl_8061E6A0 * (lbl_8061E6A0 * 309.76f);
            th[1] = lbl_8061E6A4 * (lbl_8061E6A4 * 309.76f);
            th[2] = lbl_8061E6A8 * (lbl_8061E6A8 * 309.76f);
            Unk80273498_Vec3 v = fn_80189618(f, o);
            float d2 = v.x * v.x + v.y * v.y + v.z * v.z;
            if (!(d2 >= th[0])) {
                return 1;
            }
            if (d2 < th[1]) {
                return 2;
            }
            if (fn_8024D41C(x)) {
                return 0;
            }
            if (d2 < th[1]) {
                return 0;
            }
            if (d2 < th[2]) {
                return 3;
            }
        }
    }
    return 0;
}

/* near-miss: same instructions; stack slots differ (retail's inlined AngleDiff slots are not
 * shared between the two uses, frame 96 vs 72). */
int Unk8027A84C::fn_8027BA64(float a, float b, float c)
{
    float da = AngleDiff(b, a);
    if (__builtin_fabs(da) > 0.7853982f) {
        float db = AngleDiff(c, a);
        if (__builtin_fabs(db) < 0.3926991f) {
            return 1;
        }
    }
    return 0;
}

/* fn_8027BBA8 (458 instructions) is not attempted yet. */
int Unk8027A84C::fn_8027BB88(Unk80270BA0_X* x, Unk8027BBA8_Obj* o, int a, int b, int c)
{
    return fn_8027BBA8(x, o, a, b, c);
}

Unk8027C654::Unk8027C654()
{
    m0 = 0;
    m4 = 0;
    mC = 0;
    m14 = 0;
}

Unk8027A84C* Unk8027A84C_Owner::fn_8027C67C()
{
    switch (m10) {
    case 0:
        return (Unk8027A84C*)m18;
    case 1:
        return (Unk8027A84C*)m18;
    case 2:
        return (Unk8027A84C*)m18;
    case 3:
        return (Unk8027A84C*)m18;
    case 4:
        return (Unk8027A84C*)m18;
    case 5:
        return (Unk8027A84C*)m18;
    case 6:
        return (Unk8027A84C*)m18;
    case 7:
        return (Unk8027A84C*)m18;
    case 8:
        return (Unk8027A84C*)m18;
    case 9:
        return (Unk8027A84C*)m18;
    case 10:
        return (Unk8027A84C*)m18;
    case 11:
        return (Unk8027A84C*)m18;
    case 12:
        return (Unk8027A84C*)m18;
    case 13:
        return (Unk8027A84C*)m18;
    case 14:
        return (Unk8027A84C*)m18;
    case 15:
        return (Unk8027A84C*)m18;
    case 16:
        return (Unk8027A84C*)m18;
    case 17:
        return (Unk8027A84C*)m18;
    default:
        return (Unk8027A84C*)m18;
    }
}
