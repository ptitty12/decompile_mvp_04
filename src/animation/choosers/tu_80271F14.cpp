/*
 * Translation unit at 0x80271F14 (original file name unknown; placeholder).
 * Same directory evidence as animation/choosers/tu_80271748.cpp.
 *
 * .text 0x80271F14-0x80272B20, .rodata 0x805DC70C-0x805DC7E4, .data 0x8061E66C-0x8061E670.
 *
 * cCircleChooser: vtable 0x80662140 slot 3 (0x802ACA7C) returns the pointer at
 * 0x8061E66C -> "cCircleChooser". The helper class it embeds at +0xC (vtable
 * 0x806621D8, ctor 0x80271F14) is defined first in the file: the helper's
 * float constants come before the class-name string in .rodata.
 */
#include "game/chooser.h"

/* One parsed (hash, id, value) triple. */
struct Unk80271F14_Entry {
    unsigned int hash;
    int id;
    float value;
};

/* Table of (hash, value) pairs parsed from "n#hash,value#hash,value#...#default#".
 * Maps an input value onto one or two entries and weights. Size 0x30. */
class Unk80271F14 : public Unk80356798 {
public:
    Unk80271F14();
    virtual ~Unk80271F14();
    void fn_80271FE8(char* buf, int len);
    void fn_80272164();
    int fn_802721E0(Unk80270BA0_X* x, float value, Unk80270BA0_Result* out);

    int m4;                    /* entry count */
    Unk80271F14_Entry* m8;
    float mC;                  /* last input (99999 = none) */
    int m10;                   /* last result ids and weights */
    int m14;
    float m18;
    float m1C;
    int m20;                   /* last result type */
    float m24;                 /* default value */
    int m28;                   /* set by the owner */
    int m2C;                   /* ids resolved */
};

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

Unk80271F14::Unk80271F14()
{
    m4 = 0;
    m2C = 0;
    m8 = 0;
    m24 = 0.0f;
    mC = 99999.0f;
}

Unk80271F14::~Unk80271F14()
{
    if (m4) {
        m4 = 0;
        if (m8) {
            delete[] m8;
        }
        m8 = 0;
    }
}

void Unk80271F14::fn_80271FE8(char* buf, int len)
{
    m2C = 0;
    if (len) {
        char* cursor;
        int remaining;
        char* token;
        int tokenLen;
        char* token1;
        int token1Len;
        char* token2;
        int token2Len;
        int i;
        int err;

        cursor = buf;
        remaining = len;
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        m4 = fn_80409DAC(token);
        if (m8) {
            delete[] m8;
            m8 = 0;
        }
        err = 0;
        m8 = new (lbl_806EF9B4 | 0x100) Unk80271F14_Entry[m4];
        for (i = 0; i < m4 && !err; i++) {
            fn_80378E48(&cursor, &remaining, ',', &token1, &token1Len);
            fn_80378E48(&cursor, &remaining, '#', &token2, &token2Len);
            if (token1Len && token2Len) {
                m8[i].hash = fn_80378568(token1, token1Len);
                m8[i].value = (float)fn_80409D88(token2);
            } else {
                err = 1;
            }
        }
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        m24 = (float)fn_80409D88(token);
    }
}

void Unk80271F14::fn_80272164()
{
    if (!m2C) {
        for (int i = 0; i < m4; i++) {
            m8[i].id = fn_80383334(m8[i].hash);
        }
        m2C = 1;
    }
}

int Unk80271F14::fn_802721E0(Unk80270BA0_X* x, float value, Unk80270BA0_Result* out)
{
    int nearest = 0;
    int idx = 0;
    int ret = 0;

    fn_80272164();
    if (x->m71C & 0x800) {
        value = m24;
    }
    if (mC == value) {
        out->type = m20;
        out->id = m10;
        out->m8 = m14;
        out->m14 = m18;
        out->m18 = m1C;
        return 1;
    }
    mC = value;
    for (int i = 0; i < m4; i++) {
        if (!(m8[i].value <= value)) {
            idx = i;
            break;
        }
    }
    value *= 6.2831855f;
    if (m4 > 1) {
        float dHi = 0.0f;
        float dLo = 0.0f;
        float lov;
        float hi;
        int lo;
        if (idx == 0) {
            lo = m4 - 1;
        } else {
            lo = idx - 1;
        }
        hi = m8[idx].value * 6.2831855f;
        lov = m8[lo].value * 6.2831855f;
        nearest = idx;
        dHi = AngleDiff(hi, value);
        dLo = AngleDiff(value, lov);
        if (!(dHi <= dLo)) {
            nearest = lo;
        }
        if (!m28 && !(dHi <= 0.000001f) && !(dLo <= 0.000001f)) {
            float range = hi - lov;
            out->type = 2;
            m20 = 2;
            float t = dLo / range;
            out->m14 = m18 = 1.0f - t;
            out->m18 = m1C = t;
            out->id = m10 = m8[lo].id;
            out->m8 = m14 = m8[idx].id;
            return 1;
        }
    } else {
        ret = 1;
    }
    m20 = 1;
    out->type = 1;
    out->id = m10 = m8[nearest].id;
    out->m14 = m18 = 1.0f;
    return ret;
}

const char* lbl_8061E66C = "cCircleChooser";

class cCircleChooser : public Unk8037B3E8 {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cCircleChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);

    int m4;                    /* state: -1, 0 or 2 */
    int m8;                    /* "type" enum */
    Unk80271F14 mC;            /* "matrix2pi"/"angles" */
};

cCircleChooser::cCircleChooser() : Unk8037B3E8(lbl_8061E66C)
{
    m4 = 0;
}

void cCircleChooser::fn_vslot2()
{
    fn_8037B6B0(lbl_805DC394, &m8, "SmallStepDirection,SmallStepRotation,MedDistLocDirection,CatchDirection,RecoverAfterDiving,StrafingDirection");
    fn_8037B728("matrix2pi", "angles", &mC, 0);
}

int cCircleChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return m4 ? 0 : fn_vslot17(out, obj, 3, 0, 0, 0);
}

int cCircleChooser::fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    if (m4 == 2) {
        return fn_vslot17(out, obj, 1, 0, 0, 0);
    }
    return m4 ? 0 : fn_vslot17(out, obj, 3, 0, 0, 0);
}

Unk8037B3E8* cCircleChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cCircleChooser;
}

/* near-miss: 275 of 281 instructions match. Only case 1 differs, and only in
 * registers: retail puts the dead copy "mr r8,r11" (a leftover of the
 * (float)(int) conversion) in r8 and the high half of the pi/4 constant in r10,
 * and reloads the local c2 through f13; this version has r10, r8 and f0.
 * Tried: every statement order and declaration order of diff/n/s/t/c2/r, n as a
 * variable or an inline cast, swapped operand orders, a nested inline helper,
 * and reordering unrelated statements in the function.
 * Element reads go through a float* (`q = &p->m[idx]; *q`): that is what gives
 * retail's "addi rX,rX,off; lfsx" shape and keeps &x->m734 in its own register. */
int cCircleChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    m4 = -1;
    float angle = 0.0f;
    int snap = -1;
    Unk80270BA0_X* x = obj->fn_vslot1();

    switch (m8) {
    case 0: {
        m4 = 2;
        snap = 1;
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->mE0[p->m190];
        float a = *q;
        float b = fn_8026D504(x, e);
        float r = AngleDiff(b, a);
        angle = r * 0.15915494f;
        if (!(angle >= 0.0f)) {
            angle += 1.0f;
        }
        break;
    }
    case 1: {
        m4 = 2;
        snap = 1;
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->mE0[p->m190];
        float a = *q;
        float b = fn_8026D504(x, e);
        float diff = a - b;
        int n = (int)(diff * 1.2732395f + 0.5f);
        float s, t, c2;
        q = &p->mE8[p->m190];
        c2 = *q;
        s = (float)n * 0.7853982f;
        t = s + b;
        float r = AngleDiff(t, c2);
        angle = r * 0.15915494f;
        if (!(angle >= 0.0f)) {
            angle += 1.0f;
        }
        break;
    }
    case 2: {
        m4 = 2;
        snap = 1;
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m100[p->m190];
        float v = *q;
        angle = v * 0.15915494f;
        if (!(angle >= 0.0f)) {
            angle += 1.0f;
        }
        break;
    }
    case 5: {
        m4 = 0;
        snap = 1;
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m108[p->m190];
        float v = *q;
        angle = v * 0.15915494f;
        if (!(angle >= 0.0f)) {
            angle += 1.0f;
        }
        break;
    }
    case 3: {
        m4 = 2;
        snap = 1;
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m40[p->m190];
        float v = *q;
        angle = v * 0.15915494f;
        if (!(angle >= 0.0f)) {
            angle += 1.0f;
        }
        break;
    }
    case 4: {
        m4 = 2;
        snap = 1;
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m140[p->m190];
        float a = *q;
        float b = fn_8026D504(x, e);
        float r = AngleDiff(b, a);
        angle = r * 0.15915494f;
        if (!(angle >= 0.0f)) {
            angle += 1.0f;
        }
        break;
    }
    }
    if (x->fn_vslot4()) {
        angle = 1.0f - angle;
    }
    Unk80271F14* h = &mC;
    h->m28 = (snap == 1);
    h->fn_802721E0(x, angle, out);
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}
