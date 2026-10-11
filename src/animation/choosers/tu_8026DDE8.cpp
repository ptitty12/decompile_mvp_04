/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x8026DDE8-0x8026FEB8, .rodata 0x805DC360-0x805DC4A4,
 * .data 0x8061E640-0x8061E644.
 *
 * cMatrixChooser: vtable 0x806625F0 slot 3 (0x802AC838) returns the pointer at
 * 0x8061E640 -> "cMatrixChooser". Its helper class (vtable 0x80662688,
 * ctor 0x8026DDE8, dtor 0x8026DE5C, parse 0x8026DFE4) comes first. "type"
 * (0x805DC394), which other choosers' slot 2 also passes, is defined here
 * as a global array.
 */
#include "game/chooser.h"

extern const char lbl_805DBC10[];   /* 0x148-byte tables in another unit's .rodata */
extern const char lbl_805DBD58[];

/* Placeholder object classes. Only the virtual slots called in this unit are
 * typed; the others are padding that keeps the slot numbers right.
 *
 * Unk8026DEF4_Obj is what fn_80383334 (hash lookup) returns (slot 12 called by
 * 0x8026DEF4); Unk8026FB80_A is what slot 12 returns (slots 18 and 22 called by
 * 0x8026F590 and 0x8026FB80); Unk8026FB80_B is what those return (slots 24 and
 * 25, and the non-virtual 0x80384070). */
struct Unk8026FB80_D {
    float m0;
    float m4;
};

class Unk8026FB80_B {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual Unk8026FB80_D* fn_vslot24();
    virtual int fn_vslot25();
    void fn_80384070(float f, Unk80270BA0_Obj* obj, int a, int* b, float* out, int c, int d);
};

class Unk8026FB80_A {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual Unk8026FB80_B* fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual Unk8026FB80_B* fn_vslot22();
};

class Unk8026DEF4_Obj {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual Unk8026FB80_A* fn_vslot12();
};

/* One parsed entry (0x18 bytes). Evidence: stride 0x18 in the parse function
 * (0x8026DFE4), the id resolve (0x8026E2E8) and the accessors 0x8026DEF4,
 * 0x8026DF9C and 0x8026DFC0. */
struct Unk8026DDE8_Entry {
    unsigned int hash;
    int id;                    /* resolved from hash by fn_8026E2E8 */
    float m8;
    float mC;
    float m10;
    float m14;
};

/* Position table for cMatrixChooser (vtable 0x80662688 with the parse function
 * in slot 1 and the dtor in slot 2; base ctor 0x80356798; size 0x48, embedded in
 * the chooser at +0xC).
 *
 * Parse format (slot 1): "count#" then per entry "hash,m8#...", then "m3C,",
 * "m40#" and "count2#" followed by count2 byte triples "a,b,c#". */
class Unk8026DDE8 : public Unk80356798 {
public:
    Unk8026DDE8();
    virtual void fn_vslot1(char* buf, int len);
    virtual ~Unk8026DDE8();
    int fn_8026DEF4(int idx, Unk8026FB80_A** id, float* a, float* b);
    void fn_8026DF9C(int idx, float v);
    void fn_8026DFC0(int idx, float v);
    void fn_8026E2E8();
    int fn_8026E364(Unk80270BA0_X* x, float a, float b, Unk80270BA0_Result* out, int fx, int fy);

    int m4;                    /* entry count */
    Unk8026DDE8_Entry* m8;
    int mC;                    /* triple count */
    unsigned char* m10;        /* triples of entry indices */
    float m14;                 /* last input (99999 = none) */
    float m18;
    int m1C;                   /* last result */
    int m20;
    int m24;
    float m28;
    float m2C;
    float m30;
    int m34;                   /* last result type */
    int m38;                   /* set by the owner */
    float m3C;                 /* default input */
    float m40;
    int m44;                   /* ids resolved */
};

Unk8026DDE8::Unk8026DDE8()
{
    m4 = 0;
    mC = 0;
    m44 = 0;
    m8 = 0;
    m10 = 0;
    m3C = m40 = 0.0f;
    m18 = m14 = 99999.0f;
}

Unk8026DDE8::~Unk8026DDE8()
{
    if (m4) {
        m4 = 0;
        if (m8) {
            delete[] m8;
        }
        m8 = 0;
    }
    if (mC) {
        mC = 0;
        if (m10) {
            delete[] m10;
        }
        m10 = 0;
    }
}

int Unk8026DDE8::fn_8026DEF4(int idx, Unk8026FB80_A** id, float* a, float* b)
{
    fn_8026E2E8();
    if (idx >= 0 && idx < m4) {
        *id = ((Unk8026DEF4_Obj*)m8[idx].id)->fn_vslot12();
        *a = m8[idx].m8;
        *b = m8[idx].mC;
        return 1;
    }
    return 0;
}

void Unk8026DDE8::fn_8026DF9C(int idx, float v)
{
    m8[idx].m8 = v;
}

void Unk8026DDE8::fn_8026DFC0(int idx, float v)
{
    m8[idx].mC = v;
}

void Unk8026DDE8::fn_vslot1(char* buf, int len)
{
    m44 = 0;
    if (len) {
        char* cursor;
        int remaining;
        char* token;
        int tokenLen;
        char* token1;
        int token1Len;
        char* token2;
        int token2Len;
        char* token3;
        int token3Len;
        int i;
        int err;

        remaining = len;
        cursor = buf;
        err = 0;
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        m4 = fn_80409DAC(token);
        if (m8) {
            delete[] m8;
        }
        m8 = new (lbl_806EF9B4 | 0x100) Unk8026DDE8_Entry[m4];
        for (i = 0; i < m4 && !err; i++) {
            fn_80378E48(&cursor, &remaining, ',', &token1, &token1Len);
            fn_80378E48(&cursor, &remaining, ',', &token2, &token2Len);
            fn_80378E48(&cursor, &remaining, '#', &token3, &token3Len);
            if (token1Len && token2Len && token3Len) {
                m8[i].hash = fn_80378568(token1, token1Len);
                m8[i].m8 = m8[i].m10 = (float)fn_80409D88(token2);
                m8[i].mC = m8[i].m14 = (float)fn_80409D88(token3);
            } else {
                err = 1;
            }
        }
        fn_80378E48(&cursor, &remaining, ',', &token, &tokenLen);
        m3C = (float)fn_80409D88(token);
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        m40 = (float)fn_80409D88(token);
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        mC = fn_80409DAC(token);
        if (m10) {
            delete[] m10;
            m10 = 0;
        }
        if (mC) {
            unsigned char* p;
            char* tokenA;
            int tokenALen;

            p = m10 = new (lbl_806EF9B4 | 0x100) unsigned char[mC * 3];
            for (i = 0; i < mC && !err; i++) {
                fn_80378E48(&cursor, &remaining, ',', &tokenA, &tokenALen);
                *p++ = fn_80409DAC(tokenA);
                fn_80378E48(&cursor, &remaining, ',', &tokenA, &tokenALen);
                *p++ = fn_80409DAC(tokenA);
                fn_80378E48(&cursor, &remaining, '#', &tokenA, &tokenALen);
                *p++ = fn_80409DAC(tokenA);
            }
        }
    }
}

void Unk8026DDE8::fn_8026E2E8()
{
    if (!m44) {
        for (int i = 0; i < m4; i++) {
            m8[i].id = fn_80383334(m8[i].hash);
        }
        m44 = 1;
    }
}

/* "type" (also passed by other choosers' slot 2); right after the class name. */
const char lbl_805DC394[] = "type";

/* Class name; read by cMatrixChooser's vtable slot 3 (0x802AC838). */
const char* lbl_8061E640 = "cMatrixChooser";

/* Return value of fn_801A4C20 (only these fields are read). */
struct Unk801A4C20_Ret {
    char pad0[0xB40];
    float mB40;
    float mB44;
    int mB48;
};
Unk801A4C20_Ret* fn_801A4C20();
void fn_801C3D44(Unk8027107C_Inner* p, float* a, float* b);
float fn_8024BFEC(Unk80270BA0_X* x, float v);
float fn_8026FDB0(Unk80270BA0_Obj* obj);

class cMatrixChooser : public Unk8037B3E8 {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cMatrixChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
    void fn_8026F530(Unk80270BA0_Obj* obj);
    int fn_8026F590(Unk80270BA0_Obj* obj, unsigned char* buf);
    int fn_8026FB80(Unk80270BA0_Obj* obj, float* out);

    int m4;                    /* state: -1, 0, 1 or 2 */
    int m8;                    /* "type" enum */
    Unk8026DDE8 mC;            /* "matrix2d"/"positions" */
    int m54;                   /* "RepositionCatches_X" */
    int m58;                   /* "RepositionCatches_Y" */
    int m5C;
};

cMatrixChooser::cMatrixChooser() : Unk8037B3E8(lbl_8061E640)
{
    m8 = 3;
    m4 = 0;
    m54 = 0;
    m58 = 0;
    m5C = 0;
}

void cMatrixChooser::fn_vslot2()
{
    fn_8037B6B0(lbl_805DC394, &m8, "-,-,-,Swing,DirectionalCatch,Run,PopFlyCatch,Catch,BackCatch");
    fn_8037B728("matrix2d", "positions", &mC, 0);
    fn_8037B458("RepositionCatches_X", &m54, lbl_805DBC10, lbl_805DBD58);
    fn_8037B458("RepositionCatches_Y", &m58, lbl_805DBC10, lbl_805DBD58);
}

int cMatrixChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return m4 ? 0 : fn_vslot17(out, obj, 3, 0, 0, 0);
}

int cMatrixChooser::fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    if (m4 == 2) {
        return fn_vslot17(out, obj, 1, 0, 0, 0);
    }
    if (m4 == 0) {
        return fn_vslot17(out, obj, 3, 0, 0, 0);
    }
    return 0;
}

Unk8037B3E8* cMatrixChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cMatrixChooser;
}

/* near-miss, well under 95%: 431 of 433 instructions, per-case structure,
 * constants and the nine clamps (">?" form, see fn_8026FDB0) match. Open:
 * (1) the incoming arguments c,d,e,f land in different callee-saved registers,
 * (2) the switch dispatch tree differs a little (cases 0-2 share the default
 * body here), (3) the m170/m178/m38 array reads index from x+0x734 in retail
 * (addi r8; slwi; addi 368; lfsx) where ours folds the offsets into the base.
 * Attempts so far: 6. */
int cMatrixChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    m4 = -1;
    float a = 0.0f;
    float b = 0.0f;
    int fx = 0;
    int fy = 0;
    int mode;
    Unk80270BA0_X* x = obj->fn_vslot1();

    fn_8026F530(x);
    switch (m8) {
    case 3: {
        Unk8014D8AC_Ctx* ctx = x->m44C;
        int k = ctx->m6F4;
        if (k == 1) {
            Unk801A4C20_Ret* r = fn_801A4C20();
            a = r->mB40;
            b = r->mB44;
            if (r->mB48) {
                m4 = 0;
            } else {
                m4 = 1;
            }
        } else {
            m4 = 0;
            fn_801C3D44(ctx->m700->m3A4, &a, &b);
        }
        a = (a - 0.5f) / x->mAB4 + 0.5f;
        mode = 0;
        break;
    }
    case 5: {
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m0[p->m190];
        float t = fn_8024BFEC(x, *q);
        a = t + 0.5f;
        b = fn_8026FDB0(x);
        mode = 0;
        m4 = 0;
        break;
    }
    case 7: {
        Unk802726BC_Angles* p = &x->m734;
        float t1 = p->m170[p->m190];
        float t2 = p->m178[p->m190];
        if (t1 != -1000.0f) {
            a = t1;
            fx = 1;
        } else {
            float t3 = p->m38[p->m190];
            a = t3 * 0.5f / (x->mAB4 * 120.0f) + 0.5f;
            a = !(a > 1.0f) ? (a >? 0.0f) : 1.0f;
        }
        if (t2 != -1000.0f) {
            b = t2;
            fy = 1;
        } else {
            float t4 = p->m30[p->m190];
            b = t4 / (x->mAB4 * 120.0f);
            b = !(b > 1.0f) ? (b >? 0.0f) : 1.0f;
        }
        m4 = 2;
        mode = 1;
        break;
    }
    case 4: {
        Unk802726BC_Angles* p = &x->m734;
        float t1 = p->m170[p->m190];
        float t2 = p->m178[p->m190];
        if (!(t1 < 0.0f)) {
            a = t1;
            fx = 1;
        } else {
            float t3 = p->m40[p->m190];
            t3 = !(t3 > 3.1415927f) ? (t3 >? -3.1415927f) : 3.1415927f;
            a = t3 * 0.15915494f + 0.5f;
            a = !(a > 1.0f) ? (a >? 0.0f) : 1.0f;
        }
        if (!(t2 < 0.0f)) {
            b = t2;
            fy = 1;
        } else {
            float t4 = p->m30[p->m190];
            b = t4 / (x->mAB4 * 120.0f);
            b = !(b > 1.0f) ? (b >? 0.0f) : 1.0f;
        }
        m4 = 1;
        mode = 1;
        break;
    }
    case 8: {
        Unk802726BC_Angles* p = &x->m734;
        float t1 = p->m38[p->m190];
        float t2 = p->m30[p->m190];
        a = t1 * 0.5f / (x->mAB4 * 120.0f) + 0.5f;
        a = !(a > 1.0f) ? (a >? 0.0f) : 1.0f;
        b = t2 / (x->mAB4 * 120.0f);
        b = !(b > 1.0f) ? (b >? 0.0f) : 1.0f;
        m4 = 1;
        mode = 0;
        break;
    }
    case 6: {
        Unk802726BC_Angles* p = &x->m734;
        float t1 = p->m38[p->m190];
        float t2 = p->m130[p->m190];
        a = t1 * 0.5f / (x->mAB4 * 120.0f) + 0.5f;
        a = !(a > 1.0f) ? (a >? 0.0f) : 1.0f;
        b = t2 * 0.5f / (x->mAB4 * 120.0f) + 0.5f;
        b = !(b > 1.0f) ? (b >? 0.0f) : 1.0f;
        m4 = 1;
        mode = 1;
        break;
    }
    case 0:
    case 1:
    case 2:
    default:
        a = 0.5f;
        b = 0.5f;
        m4 = 1;
        mode = 1;
        break;
    }
    if (x->fn_vslot4()) {
        a = 1.0f - a;
    }
    Unk8026DDE8* h = &mC;
    h->m38 = mode;
    h->fn_8026E364(x, a, b, out, fx, fy);
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}

void cMatrixChooser::fn_8026F530(Unk80270BA0_Obj* obj)
{
    if (!m5C) {
        if (m54 || m58) {
            fn_8026F590(obj, 0);
        }
        m5C = 1;
    }
}

int fn_8026FB60(const float* a, const float* b)
{
    if (*a < *b) {
        return -1;
    }
    return *a > *b;
}

float fn_804028E4(float x);               /* square root */
void fn_8040A208(void* base, int count, int size, int (*cmp)(const float*, const float*));
extern char lbl_806EF9C7;

struct Unk8026FB80_Item {
    float key;
    Unk8026FB80_B* obj;
    int idx;
};

/* near-miss: 139 of 140 instructions; the stack frame, the call sequence and
 * all float code match. Remaining: callee-saved register numbers differ (this
 * r27 vs r25, loop index r26 vs r29, ...), the loop bottom reads the entry
 * count as 16(this) instead of 4(&mC), and the final copy loop is a bdnz loop
 * where retail has "mr rN,count; addic. rN,rN,-1; bne".
 * Needed to get the frame right: v, dist, r, a, b, n, q, list declared in this
 * order at function scope; an unused float between maxDist and ent (it only
 * occupies a slot); &v held in a pointer before the call. */
int cMatrixChooser::fn_8026FB80(Unk80270BA0_Obj* obj, float* out)
{
    Unk80273498_Vec3 v;
    float dist;
    float r;
    float a;
    float b;
    float n;
    float q;
    Unk8026FB80_Item list[6];
    int count = 0;
    int i;

    for (i = 0; i < mC.m4; i++) {
        float maxDist;
        float unusedF;
        Unk8026FB80_A* ent;
        int flag;
        mC.fn_8026DEF4(i, &ent, &a, &b);
        {
            Unk8026FB80_B* pl = ent->fn_vslot18();
            Unk80273498_Vec3* p = &v;
            maxDist = 9999.0f;
            flag = lbl_806EF9C7;
            pl->fn_80384070(maxDist, obj, 1, &flag, &p->x, 0, 1);
            dist = fn_804028E4(p->x * p->x + p->z * p->z);
            n = (float)pl->fn_vslot25();
            q = (n - 1.0f) / pl->fn_vslot24()->m4;
            r = dist / q;
            b = r * 0.0025399998f;
            mC.fn_8026DFC0(i, b);
            if (!(a <= 0.48) && !(a >= 0.52)) {
                list[count].key = r;
                list[count].obj = pl;
                list[count].idx = i;
                count++;
            }
        }
    }
    fn_8040A208(list, count, 12, fn_8026FB60);
    for (int k = 0; k < count; k++) {
        out[k] = list[k].key;
    }
    return count;
}

float fn_8028F220(Unk80270BA0_X* x, int a, int b);
float fn_80249070(Unk80270BA0_X* x);
float fn_8024BF20(Unk80270BA0_X* x, float v);

/* The clamp is g++'s minimum/maximum operator inside a ternary (see PATTERNS,
 * "In-place float clamp"): MAX_EXPR compares its own result register, so the
 * jump pass cannot hoist a copy of t above the 0.0 test. */
float fn_8026FDB0(Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    float scale = fn_8028F220(x, 4, 0);
    float len = fn_80249070(x);
    if (!(len >= 39.370083f)) {
        len = 393.7008f;
    }
    Unk802726BC_Angles* p = &x->m734;
    float* q = &p->m8[p->m190];
    float v = fn_8024BF20(x, *q);
    float t = v / len;
    t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
    t = t * 0.0025399998f * scale;
    return t;
}
