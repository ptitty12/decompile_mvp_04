#line 1 "C:/mvp2004/source/common/animation/choosers/randomchooser.cpp"
/*
 * C:/mvp2004/source/common/animation/choosers/randomchooser.cpp
 * (path string at 0x805DC4AC, used by fn_8027011C's assert and the RNG call
 * in fn_802704E8). Part of the choosers/goals unity TU (docs/DECISIONS.md).
 *
 * .text 0x8026FEB8-0x80270730, .rodata 0x805DC4A4-0x805DC568,
 * .data 0x8061E644-0x8061E648.
 *
 * cRandom: vtable 0x80662538 slot 3 (0x802AC860) returns the pointer at
 * 0x8061E644 -> "cRandom". Its weights-list helper (vtable 0x806625D0: parse
 * 0x8027021C, dtor 0x8026FF08; ctor 0x8026FEB8) is also used by
 * randomloadedchooser.cpp. An assert names one of its members:
 * "value >= 0.0 && value <= mAssetWeights[top]...". "a" and "weights"
 * (0x805DC538, 0x805DC53C) are global arrays: other units pass them too.
 */
#include "game/chooser_base.h"

/* Class name; read by cRandom's vtable slot 3 (0x802AC860). Defined first so
 * that "cRandom" is the first string in .rodata, as in retail. */
const char* lbl_8061E644 = "cRandom";

/* The assertion handler called by fn_8027011C (file, line, expression). */
void fn_80409CC0(const char* file, int line, const char* expr);

/* Resolved asset behind a weights-list entry (class unknown). Only the two
 * virtual calls fn_8026FF6C makes are known: slot 18 (vtable +0x90/+0x94) of
 * the entry's object returns an object whose slot 23 (+0xB8/+0xBC) returns
 * the value the callers pass on. The other slots are placeholders. */
class Unk8026FF6C_Target {
public:
    virtual void fn_vslot1();  virtual void fn_vslot2();  virtual void fn_vslot3();
    virtual void fn_vslot4();  virtual void fn_vslot5();  virtual void fn_vslot6();
    virtual void fn_vslot7();  virtual void fn_vslot8();  virtual void fn_vslot9();
    virtual void fn_vslot10(); virtual void fn_vslot11(); virtual void fn_vslot12();
    virtual void fn_vslot13(); virtual void fn_vslot14(); virtual void fn_vslot15();
    virtual void fn_vslot16(); virtual void fn_vslot17(); virtual void fn_vslot18();
    virtual void fn_vslot19(); virtual void fn_vslot20(); virtual void fn_vslot21();
    virtual void fn_vslot22(); virtual void* fn_vslot23();
};

struct Unk8026FF6C_Obj {
    virtual void fn_vslot1();  virtual void fn_vslot2();  virtual void fn_vslot3();
    virtual void fn_vslot4();  virtual void fn_vslot5();  virtual void fn_vslot6();
    virtual void fn_vslot7();  virtual void fn_vslot8();  virtual void fn_vslot9();
    virtual void fn_vslot10(); virtual void fn_vslot11(); virtual void fn_vslot12();
    virtual void fn_vslot13(); virtual void fn_vslot14(); virtual void fn_vslot15();
    virtual void fn_vslot16(); virtual void fn_vslot17();
    virtual Unk8026FF6C_Target* fn_vslot18();
};

/* ---- Unk8026FEB8 ---- */

Unk8026FEB8::Unk8026FEB8()
{
    m10 = 0;
    m4 = 0;
    mC = 0;
    mAssetWeights = 0;
}

Unk8026FEB8::~Unk8026FEB8()
{
    if (m4) {
        delete[] mAssetWeights;
    }
}

void* Unk8026FEB8::fn_8026FF6C(int index)
{
    fn_8026FFF8();
    if (index >= 0 && index < m4) {
        return mAssetWeights[index].m4->fn_vslot18()->fn_vslot23();
    }
    return 0;
}

void Unk8026FEB8::fn_8026FFF8()
{
    if (!m10) {
        for (int i = 0; i < m4; i++) {
            mAssetWeights[i].m4 = (Unk8026FF6C_Obj*)fn_80383334(mAssetWeights[i].m0);
        }
        m10 = 1;
    }
}

int Unk8026FEB8::fn_80270074(Unk80270BA0_X* x, int index, int* outId, float* outWeight)
{
    fn_8026FFF8();
    if (x->m71C & 0x800) {
        int top = m4 - 1;
        int pick = mC > top ? top : mC;
        index = pick;
    }
    if (index >= 0 && index < m4) {
        *outId = (int)mAssetWeights[index].m4;
        *outWeight = mAssetWeights[index].m8;
        return 1;
    }
    return 0;
}

/* Picks the entry whose cumulative weight first exceeds `value` (binary search
 * on mSumWeight) and returns fn_80270074 for it. `value`, `top` and the
 * assert text come from the string at 0x805DC4EC. The assert is written as
 * `value < 0.0 || !(value <= ...)`: the plain `!(a >= 0.0 && b)` form gives
 * different float branches. The line number 127 is the original's __LINE__. */
int Unk8026FEB8::fn_8027011C(Unk80270BA0_X* x, int* outId, float* outWeight, float value)
{
    int top = m4 - 1;
    int lo = 0;

    if (x->m71C & 0x800) {
        return fn_80270074(x, mC, outId, outWeight);
    }
    if (value < 0.0 || !(value <= mAssetWeights[top].mSumWeight)) {
        fn_80409CC0(__FILE__, 127, "value >= 0.0 && value <= mAssetWeights[top].mSumWeight");
    }
    while (top != lo) {
        int mid = (top + lo) >> 1;
        if (!(value >= mAssetWeights[mid].mSumWeight)) {
            top = mid;
        } else {
            lo = mid + 1;
        }
    }
    return fn_80270074(x, top, outId, outWeight);
}

void Unk8026FEB8::fn_vslot1(char* buf, int len)
{
    m10 = 0;
    if (len) {
        for (int pass = 0; pass <= 1; pass++) {
            float sum = 0.0f;
            char* cursor;
            int remaining;
            char* list;
            int listLen;
            char* token;
            int tokenLen;
            char* token2;
            int token2Len;
            int count;
            int done;

            remaining = len;
            listLen = len;
            cursor = buf;
            list = buf;
            count = 0;
            fn_80378E48(&cursor, &remaining, '#', &list, &listLen);
            fn_80378E48(&cursor, &remaining, '#', &token2, &token2Len);
            mC = token2Len ? fn_80409DAC(token2) : 0;
            done = 0;
            while (!done) {
                fn_80378E48(&list, &listLen, ',', &token, &tokenLen);
                fn_80378E48(&list, &listLen, ',', &token2, &token2Len);
                if (tokenLen && token2Len) {
                    if (pass == 1) {
                        mAssetWeights[count].m0 = fn_80378568(token, tokenLen);
                        mAssetWeights[count].m8 = fn_80409D88(token2);
                        sum += mAssetWeights[count].m8;
                        mAssetWeights[count].mSumWeight = sum;
                    }
                    count++;
                } else {
                    done = 1;
                }
            }
            if (pass == 0) {
                if (mAssetWeights) {
                    delete[] mAssetWeights;
                }
                mAssetWeights = new (lbl_806EF9B4) Unk8026FEB8_Entry[count];
                m4 = count;
            }
        }
    }
}

class cRandom : public Unk80362C2C {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cRandom();
    virtual ~cRandom();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);

    float m4;                  /* total weight; 0 = not computed yet, -1 = all weights equal */
    Unk8026FEB8 m8;            /* "a"/"weights" */
};

cRandom::cRandom() : Unk80362C2C(0x8EE57249), m4(0.0f)
{
}

/* Defined here, after the constructor: other units (cRandomLoaded) pass them
 * to fn_8037B728 too, and retail places them between the constructor's float
 * constant and slot 17's. */
const char lbl_805DC538[] = "a";
const char lbl_805DC53C[] = "weights";

void cRandom::fn_vslot2()
{
    fn_8037B728(lbl_805DC538, lbl_805DC53C, &m8, 0);
}

cRandom::~cRandom()
{
}

Unk8037B3E8* cRandom::fn_vslot5()
{
    return new (lbl_806EF9B4) cRandom;
}

/* m4 is computed on first use: the sum of all weights, or -1 when every
 * weight is equal (then an entry is picked uniformly). */
int cRandom::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    Unk8026FEB8* countList = &m8;
    int n = countList->m4;
    int id;
    float weight;

    out->type = 1;
    if (m4 == 0.0) {
        float first = 0.0f;
        int allSame = 1;
        int i;

        weight = 0.0f;
        for (i = 0; i < n; i++) {
            /* Declared per iteration: with one pointer for the whole function
             * the later calls would reuse it instead of recomputing this+8
             * (same as randomloadedchooser.cpp). */
            Unk8026FEB8* list = &m8;

            list->fn_80270074(x, i, &id, &weight);
            m4 += weight;
            if (i != 0) {
                if (first != weight) {
                    allSame = 0;
                }
            } else {
                first = weight;
            }
        }
        if (allSame) {
            m4 = -1.0f;
        }
    }
    if (n != 0) {
        if (n == 1) {
            m8.fn_80270074(x, 0, &id, &weight);
        } else if (!(m4 >= 0.0f)) {
            int pick = x->m44C->m554->fn_8014D8AC(n, __FILE__, 283);
            m8.fn_80270074(x, pick, &id, &weight);
        } else {
            float r = (float)(unsigned int)x->m44C->m554->fn_8014D8AC(10000, __FILE__, 288) * m4 * 0.0001f;
            m8.fn_8027011C(x, &id, &weight, r);
        }
    } else {
        id = 0;
        out->type = 0;
        weight = 0.0f;
    }
    out->id = id;
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}
