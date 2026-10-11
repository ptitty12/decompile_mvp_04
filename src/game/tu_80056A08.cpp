/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80056A08-0x80058060 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

Unk80056A08_Ring::~Unk80056A08_Ring()
{
    if (mC != 0) {
        delete[] mC;
        mC = 0;
    }
}

/* near-miss (2 slots): see fn_80056AC0. */
void fn_80056A68(Unk80056970_Obj* r)
{
    r->m0 = 0;
    r->m4 = 0;
    for (unsigned i = 0; i < r->m8; i++) {
        Unk80056970_Entry* e = &r->mC[i];
        e->m0 = lbl_805AB8A4;
        e->m8 = i;
        e->m4 = 0x1D8;
    }
}

static inline void SetVal(Unk80056970_Entry* e, float x)
{
    e->m0 = x;
}

/* near-miss (2 slots): retail forms the element address as add off,base and uses
 * stfsx off,base; this gives add base,off. Same in fn_80056A68. */
void fn_80056AC0(Unk80056970_Obj* r, int id, float v)
{
    Unk80056970_Entry* e = &r->mC[r->m0];
    SetVal(e, v);
    e->m4 = id;
    r->m0 = (r->m0 + 1) % r->m8;
    if (r->m0 == r->m4) {
        r->m4 = (r->m0 + 1) % r->m8;
    }
}

Unk80056970_Entry* fn_80056B30(Unk80056970_Obj* r)
{
    Unk80056970_Entry* res = 0;
    int ne = 1;
    if (r->m0 == r->m4) {
        ne = 0;
    }
    if (ne != 0) {
        unsigned i;
        if (r->m0 != 0) {
            i = r->m0 - 1;
        } else {
            i = r->m8 - 1;
        }
        res = fn_80056BE0(r, i);
    }
    return res;
}

Unk80056970_Entry* fn_80056B94(Unk80056970_Obj* r)
{
    Unk80056970_Entry* res = 0;
    int ne = 1;
    if (r->m0 == r->m4) {
        ne = 0;
    }
    if (ne != 0) {
        res = fn_80056BE0(r, r->m4);
    }
    return res;
}

Unk80056970_Entry* fn_80056BE0(Unk80056970_Obj* r, unsigned idx)
{
    Unk80056970_Entry* res = 0;
    int ok;
    if (r->m0 < r->m4) {
        ok = idx < r->m8;
    } else {
        ok = idx < r->m0 && idx >= r->m4;
    }
    if (ok) {
        res = &r->mC[idx];
    }
    return res;
}

Unk80056970_Entry* fn_80056C3C(Unk80056970_Obj* r, Unk80056970_Entry* e)
{
    Unk80056970_Entry* res = 0;
    if (e != 0 && r->m0 != r->m4) {
        unsigned i = e->m8;
        if (i != 0) {
            i = i - 1;
        } else {
            i = r->m8 - 1;
        }
        res = fn_80056BE0(r, i);
    }
    return res;
}

void fn_80056C9C(int id)
{
    if (lbl_80687604 != 0) {
        fn_80056AC0(lbl_80687604, id, (float)lbl_8061B8C0->m8->m4C * lbl_805AB8B0);
    }
}

int fn_80056D0C(int id)
{
    int r = 0;
    if (fn_80056EE4(lbl_80687600, id, 0) != 0 || fn_80056EE4(lbl_80687604, id, 0) != 0) {
        r = 1;
    }
    return r ^ 1;
}

void fn_80056D78(Unk80056970_Obj* r, Unk80056970_Entry** out, Unk80056970_Entry** last)
{
    int sp8;
    *out = 0;
    *last = fn_80056B30(r);
    if (*last != 0 && (*last)->m4 != 0x1DA) {
        *out = fn_80056EE4(r, 0x1DA, 0);
    } else {
        int i = (*last)->m8;
        if (i != 0) {
            i = i - 1;
        } else {
            i = r->m8 - 1;
        }
        sp8 = i;
        *out = fn_80056EE4(r, 0x1DA, &sp8);
    }
    if (*out == 0) {
        *out = fn_80056EE4(r, 0x1D9, 0);
    }
}

Unk80056970_Entry* fn_80056E34(Unk80056970_Obj* r, int id)
{
    Unk80056970_Entry* sp8;
    Unk80056970_Entry* spC;
    fn_80056D78(r, &sp8, &spC);
    if (spC != 0) {
        if (spC->m4 != id && spC != sp8) {
            do {
                spC = fn_80056C3C(r, spC);
                if (spC == 0) {
                    goto done;
                }
            } while (spC->m4 != id && spC != sp8);
        }
        if (spC != 0 && spC->m4 != id) {
            spC = 0;
        }
    }
done:
    return spC;
}

Unk80056970_Entry* fn_80056EE4(Unk80056970_Obj* r, int id, int* idxp)
{
    Unk80056970_Entry* e = fn_80056B30(r);
    int ne = 1;
    if (r->m0 == r->m4) {
        ne = 0;
    }
    if (ne != 0) {
        if (idxp != 0) {
            e = fn_80056BE0(r, *idxp);
        }
        Unk80056970_Entry* first = fn_80056B94(r);
        while (e != 0) {
            if (e->m4 == id || e == first) {
                break;
            }
            e = fn_80056C3C(r, e);
        }
        if (e != 0 && e->m4 != id) {
            e = 0;
        }
    }
    return e;
}

void* fn_80056FAC(Unk80057204_Mgr* m, int k)
{
    void* r = fn_800578E4(m, k, 0);
    if (r == 0) {
        fn_8033E958(lbl_805ADA74, lbl_80618F6C, lbl_80618CB0[k]);
    }
    return r;
}

void* fn_80057010(Unk80057204_Mgr* m, int k)
{
    void* r = fn_800578E4(m, k, 1);
    if (r == 0) {
        fn_8033E958(lbl_805ADA74, lbl_80618F70, lbl_80618CB0[k]);
    }
    return r;
}

void* fn_80057074(Unk80057204_Mgr* m, int k)
{
    void* r = fn_800578E4(m, k, 2);
    if (r == 0) {
        fn_8033E958(lbl_805ADA74, lbl_80618F74, lbl_80618CB0[k]);
    }
    return r;
}

void* fn_800570D8(Unk80057204_Mgr* m, int k)
{
    void* r = fn_800578E4(m, k, 3);
    if (r == 0) {
        fn_8033E958(lbl_805ADA74, lbl_80618F78, lbl_80618CB0[k]);
    }
    return r;
}

void* fn_8005713C(Unk80057204_Mgr* m, int k)
{
    void* r = fn_800578E4(m, k, 4);
    if (r == 0) {
        fn_8033E958(lbl_805ADA74, lbl_80618F7C, lbl_80618CB0[k]);
    }
    return r;
}

void* fn_800571A0(Unk80057204_Mgr* m, int k)
{
    void* r = fn_800578E4(m, k, 5);
    if (r == 0) {
        fn_8033E958(lbl_805ADA74, lbl_80618F80, lbl_80618CB0[k]);
    }
    return r;
}

void* fn_800578E4(Unk80057204_Mgr* m, int a, int b)
{
    unsigned t = m->mB4[a];
    int lo = t >> 16;
    int hi = (unsigned short)t;
    for (; lo < hi; lo++) {
        if (m->mBC[lo] == b) {
            return m->mF4[lo];
        }
    }
    return 0;
}

int fn_80057938(Unk80057204_Mgr* m)
{
    if (m->mF4 != 0) {
        return 1;
    }
    return 0;
}

void fn_80057AD4(void* self, Unk80052794_Rec* rec, Unk80052794_Obj* obj)
{
    fn_80055204(rec, obj);
    fn_80055F18(rec);
}

void fn_80057B10(void)
{
    if (lbl_80687600 != 0) {
        fn_80056A68(lbl_80687600);
    }
    if (lbl_80687604 != 0) {
        fn_80056A68(lbl_80687604);
    }
}

void fn_80057B54(void* self, int flag)
{
    int id = 0x1D9;
    if (flag == 0) {
        id = 0x1DA;
    }
    if (lbl_80687600 != 0) {
        fn_80056AC0(lbl_80687600, id, (float)lbl_8061B8C0->m8->m4C * lbl_805ADC18);
    }
    if (lbl_80687604 != 0) {
        fn_80056AC0(lbl_80687604, id, (float)lbl_8061B8C0->m8->m4C * lbl_805ADC18);
    }
}
