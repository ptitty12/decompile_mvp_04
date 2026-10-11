/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x80279AE4-0x8027A84C, .rodata 0x805DCEE8-0x805DCF60,
 * .data 0x8061E69C-0x8061E6A0. The end is where this group's float
 * constants end (the next group's start at 0x805DCF60).
 *
 * cShortestPathChooser: vtable 0x80661EA0 slot 3 (0x802ACB8C) returns the
 * pointer at 0x8061E69C -> "cShortestPathChooser".
 */
#include "game/chooser.h"

/* Class name; read by cShortestPathChooser's vtable slot 3 (0x802ACB8C). */
const char* lbl_8061E69C = "cShortestPathChooser";
extern unsigned int lbl_806EF9D8;     /* hash of the class name, read by slot 4 (0x802ACB98) */

class cShortestPathChooser : public Unk8037B3E8 {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cShortestPathChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
};

cShortestPathChooser::cShortestPathChooser() : Unk8037B3E8(lbl_8061E69C)
{
    lbl_806EF9D8 = fn_80378568(lbl_8061E69C, 0);
}

void cShortestPathChooser::fn_vslot2()
{
}

Unk8037B3E8* cShortestPathChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cShortestPathChooser;
}

int cShortestPathChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    out->type = 0;
    out->id = 0;
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, obj, c, d, e, f);
}

/* ---- path query helpers (functions 0x80279BB8..0x8027A4A4) ----
 *
 * Not part of cShortestPathChooser (its slot 17 does not touch them): they are
 * helper classes of this region, defined after the chooser. Names are
 * placeholders. Evidence for the layouts is given above each class.
 *
 * Unk8035EB7C: 0xC0-byte query record. fn_8035EB7C (0x8035EB7C) and
 * fn_8035EC3C (0x8035EC3C) are its methods (called with this in r3 by the
 * constructors below; fn_80279DD0 contains fn_8035EB7C's body inline).
 * Unk80279BB8: adds +0xCC..+0xD8 (copy ctor body 0x80279F40 copies D0, CC, D4
 * after a 0xC0-byte block copy). Unk8027A05C: 3-entry cache of query results
 * (entries at +0x20, stride 0x28, key = ints at +4/+8/+0xC/+0x10 and the 12
 * bytes at +0x14 compared with fn_8040B100).
 */

extern const Unk80270BA0_Mtx lbl_8060E938;     /* identity matrix */
extern const Unk80273498_Vec3 lbl_806055AC;    /* zero vector */
extern int lbl_8061B9C8;
extern int lbl_806242B4;
extern char lbl_8061EC9C;

float fn_804028E4(float x);               /* square root */
float fn_80382BB8(Unk80271DBC_Link* p);
void fn_8037D768(Unk80270BA0_X* x);
void* fn_8040B320(void* dst, int c, unsigned int n);     /* memset */
int fn_8040B100(const void* a, const void* b, unsigned int n);   /* memcmp */

struct Unk8035EB7C_Vec3i {
    int a;
    int b;
    int c;
    void Clear()
    {
        a = 0;
        b = 0;
        c = 0;
    }
};

/* Query record handed to fn_80386110/fn_80386188 (size 0xC0). Offsets seen in
 * the constructors at 0x80279BB8..0x80279F40 and the local in 0x8027A4A4. */
class Unk8035EB7C {
public:
    Unk80270BA0_Mtx m0;
    float m40;
    unsigned int m44 : 4;
    unsigned int m44r : 28;
    char pad48[0x68 - 0x48];
    Unk8035EB7C_Vec3i m68;
    char pad74[0xA0 - 0x74];
    int mA0;
    Unk80273498_Vec3 mA4;
    char padB0[0xBC - 0xB0];
    unsigned int mBC;

    void fn_8035EB7C(Unk80270BA0_X* x);
    void fn_8035EC3C(float yaw);
    void Init()
    {
        m44 = 0;
        m68.Clear();
        mA0 = 0;
        mBC = 0;
        m0 = lbl_8060E938;
    }
};

void fn_80386110(Unk80271DBC_Link* link, Unk8035EB7C* q, int a, int b, float* out, int c);
void fn_80386188(Unk80271DBC_Link* link, Unk8035EB7C* q, int a, int b, float* f1, int c, int* d,
                 Unk80273498_Vec3* e, Unk80273498_Vec3* g, int h, int i);

inline Unk80273498_Vec3 GetPos(Unk80270BA0_X* x)
{
    return x->m93C;
}

class Unk80279BB8 : public Unk8035EB7C {
public:
    Unk80279BB8(Unk80270BA0_X* x);
    Unk80279BB8();
    void fn_80279DD0(Unk80270BA0_X* x);
    void fn_80279F40(const Unk80279BB8& o);

    char padC0[0xCC - 0xC0];
    int mCC;
    float mD0;
    float mD4;
    int mD8;
};

Unk80279BB8::Unk80279BB8(Unk80270BA0_X* x)
{
    m44 = 0;
    m68.Clear();
    mA0 = 0;
    mBC = 0;
    mD0 = fn_804028E4(x->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f);
    mCC = x->m618->m830;
    mD4 = 0.0f;
    mBC = 0;
    mA4 = GetPos(x);
    fn_8035EB7C(x);
    fn_8035EC3C(fn_80382BB8(x->m618));
    mD8 = 0;
}

Unk80279BB8::Unk80279BB8()
{
    m44 = 0;
    m68.Clear();
    mA0 = 0;
    mBC = 0;
    mCC = 3;
    mD0 = 0.0f;
    mD4 = 0.0f;
    m0 = lbl_8060E938;
    m40 = 0.0f;
    mBC = 3;
    mA4 = lbl_806055AC;
    mA4.y = -1000.0f;
    mD8 = 0;
}

void Unk80279BB8::fn_80279DD0(Unk80270BA0_X* x)
{
    mBC = 0;
    mA4 = GetPos(x);
    mD0 = fn_804028E4(x->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f);
    mCC = x->m618->m830;
    mD4 = 0.0f;
    if (!x->m0) {
        fn_8037D768(x);
    }
    x->m0 = 1;
    m0 = x->m20;
    mBC |= 1;
    fn_8035EC3C(fn_80382BB8(x->m618));
}

void Unk80279BB8::fn_80279F40(const Unk80279BB8& o)
{
    *(Unk8035EB7C*)this = o;
    mD0 = o.mD0;
    mCC = o.mCC;
    mD4 = o.mD4;
    m0 = o.m0;
    mBC |= 1;
    float yaw = ((Unk80279BB8&)o).m0.fn_8037B1F0();
    fn_8035EC3C(yaw);
}

struct Unk8027A05C_Bytes {
    unsigned char b[12];
};

struct Unk8027A05C_Entry {
    int m0;
    int m4;
    int m8;
    int mC;
    Unk8027A05C_Bytes m10;
    unsigned short m1C;
    short m1E;
    short m20;
    short m22;
    unsigned int m24;
};

/* Matching note: reading the flags word through this helper gives retail's
 * "add rX,this,idx*40; lwz 0x44(rX)"; m20[idx].m24 directly gives an indexed
 * "addi rX,this,0x44; lwzx" instead. */
inline Unk8027A05C_Entry* Unk8027A05C_At(Unk8027A05C_Entry* arr, int i)
{
    return &arr[i];
}

/* Cache of up to three path query results for one player (size 0xA8). */
class Unk8027A05C {
public:
    void fn_8027A05C(Unk80270BA0_X* x);
    void fn_8027A078();
    void fn_8027A0B8(float a, float b, float c);
    void fn_8027A148(unsigned char b);
    void fn_8027A17C(int a, int b, int c, int d);
    int fn_8027A198(int* changed);
    float fn_8027A280(int a);
    Unk80273498_Vec3 fn_8027A358(int a);
    void fn_8027A4A4(int* idx, int flag, int unused);

    Unk80270BA0_X* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Unk8027A05C_Bytes m14;
    Unk8027A05C_Entry m20[3];
    int m98;
    int m9C;
    int mA0;
    int mA4;
};

void Unk8027A05C::fn_8027A05C(Unk80270BA0_X* x)
{
    m0 = x;
    m98 = 0;
    m9C = 0;
    mA4 = -1;
}

void Unk8027A05C::fn_8027A078()
{
    fn_8040B320(&m14, 0, 12);
    mA0 = 0;
}

/* One-float wrapper: -ffloat-store keeps plain float variables in memory but lets
 * a struct holding one float live in a register, which is what retail's clamp
 * (an "fmr" select with no store) needs. */
struct Unk8027A0B8_Float {
    float f;
};

void Unk8027A05C::fn_8027A0B8(float a, float b, float c)
{
    float t = (a - c) / (b - c) * 255.0f;
    unsigned char r;
    if (!(t > 255.0f)) {
        Unk8027A0B8_Float u;
        u.f = t;
        if (!(u.f >= 0.0f)) {
            u.f = 0.0f;
        }
        r = (int)u.f;
    } else {
        r = 255;
    }
    fn_8027A148(r);
}

void Unk8027A05C::fn_8027A148(unsigned char b)
{
    mA0 = mA0 + 1;
    if (mA0 > 12) {
        mA0 = 12;
    }
    m14.b[mA0 - 1] = b;
    mA4 = -1;
}

void Unk8027A05C::fn_8027A17C(int a, int b, int c, int d)
{
    m4 = a;
    mC = b;
    m10 = c;
    m8 = d;
    mA4 = -1;
}

int Unk8027A05C::fn_8027A198(int* changed)
{
    *changed = 0;
    if (mA4 < 0) {
        for (int i = 0; i < m98; i++) {
            if (m20[i].m8 == mC && m20[i].m0 == m4 && m20[i].mC == m10 && m20[i].m4 == m8) {
                if (fn_8040B100(&m20[i].m10, &m14, 12)) {
                    *changed = 1;
                }
                mA4 = i;
                return i;
            }
        }
        return -1;
    }
    return mA4;
}

float Unk8027A05C::fn_8027A280(int a)
{
    if (a) {
        m10 = a;
        mA4 = -1;
    }
    int changed = 0;
    int idx = fn_8027A198(&changed);
    if (idx == -1 || changed || (int)Unk8027A05C_At(m20, idx)->m24 >= 0) {
        fn_8027A4A4(&idx, 0, 0);
    }
    float r = (float)m20[idx].m1C * 0.000076293945f;
    return r;
}

Unk80273498_Vec3 Unk8027A05C::fn_8027A358(int a)
{
    if (a) {
        m10 = a;
        mA4 = -1;
    }
    int changed = 0;
    int idx = fn_8027A198(&changed);
    if (idx == -1 || changed || !(Unk8027A05C_At(m20, idx)->m24 & 0x40000000)) {
        fn_8027A4A4(&idx, 1, 0);
    }
    Unk80273498_Vec3 v;
    v.x = (float)m20[idx].m1E * 0.010986328f;
    v.y = (float)m20[idx].m20 * 0.010986328f;
    v.z = (float)m20[idx].m22 * 0.010986328f;
    return v;
}

/* near-miss: 232 of 234 instructions, ~58 positional-aligned register-normalized
 * differences left. What retail does that this does not:
 *  1. "cmpwi cr4,r21,0" (flag != 0) is emitted early, before the entry stores,
 *     and the final "beq cr4" reuses it; the prologue/epilogue save CR
 *     ("mfcr r12 / mtcrf 8,r12"), frame 0x148 instead of 0x150. This code tests
 *     flag at the end (cr0). Tried: copying flag into a local, "flag != 0" into
 *     an int, swapping the branches, dead early "if (flag)" statements.
 *  2. The three RMW updates of the flags word compile to "add rX,this,idx*40;
 *     lwz 0x44(rX)" in retail; here "lwz 0x24(rX)" off an entry pointer (the
 *     helper) or an indexed lwzx (plain m20[*idx].m24). Tried: |= vs x = x | c,
 *     helper vs direct vs this-based helper for each of the 3 sites (27 combos).
 *  3. Loads of m8/mC/m10 are scheduled just before their stores in retail.
 * Locals a/b/c/d (copies of m4/m8/mC/m10) are right: they are reused as call
 * arguments. q.Init() reproduces the pointer-based zeroing of q.m68/mA0/mBC. */
void Unk8027A05C::fn_8027A4A4(int* idx, int flag, int unused)
{
    if (*idx == -1) {
        if (m98 <= 2) {
            m98 = m98 + 1;
        } else {
            m9C = 0;
        }
        *idx = m9C;
        m9C = m9C + 1;
    }
    int a = m4;
    int c = mC;
    int d = m10;
    int b = m8;
    m20[*idx].m0 = a;
    m20[*idx].m8 = c;
    m20[*idx].mC = d;
    m20[*idx].m4 = b;
    m20[*idx].m10 = m14;
    float f18 = 0.0f;
    Unk80273498_Vec3 v20 = lbl_806055AC;
    Unk80273498_Vec3 v30 = lbl_806055AC;
    Unk8035EB7C q;
    q.Init();
    if (a == 0) {
        q.mBC = 1;
    } else {
        q.mBC = 0xB;
        q.mA0 = a;
        q.m40 = 0.0f;
    }
    float f100 = 0.0f;
    if (b) {
        fn_80386110(m0->m618, &q, b, lbl_806242B4, &f100, 2);
    }
    int sc = lbl_8061EC9C;
    fn_80386188(m0->m618, &q, c, d, &f18, 1, &sc, &v30, &v20, 0, 0);
    m20[*idx].m1C = (short)((f100 + f18) * 13107.2f);
    Unk8027A05C_At(m20, *idx)->m24 |= 0x80000000u;
    if (flag) {
        m20[*idx].m1E = (short)(v30.x * 91.022224f);
        m20[*idx].m20 = (short)(v30.y * 91.022224f);
        m20[*idx].m22 = (short)(v30.z * 91.022224f);
        Unk8027A05C_At(m20, *idx)->m24 |= 0x40000000u;
    } else {
        m20[*idx].m1E = 0;
        m20[*idx].m20 = 0;
        m20[*idx].m22 = 0;
        Unk8027A05C_At(m20, *idx)->m24 &= ~0x40000000u;
    }
}
