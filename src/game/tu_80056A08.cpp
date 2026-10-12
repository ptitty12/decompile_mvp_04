/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80056A08-0x80058060 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

void fn_80057B10(void);

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

struct Unk803442CC;
struct Unk803416C4;
struct Unk8034468C;
Unk803442CC* fn_80344640(Unk803442CC* self);
void fn_803416C4(Unk803416C4* s);
void fn_803416D0(Unk803416C4* s);
void fn_803416DC(Unk803416C4* s);
void fn_803416E8(Unk803416C4* s);
Unk8034468C* fn_8034468C(Unk8034468C* self);
Unk8034468C* fn_803446C8(Unk8034468C* self);
Unk8034468C* fn_8034470C(Unk8034468C* self);
extern char lbl_80649718[];
extern char lbl_806496E0[];
extern char lbl_806496A8[];
extern char lbl_80649670[];

Unk80058060_Node* fn_80057204(int id)
{
    Unk80058060_Node* r;
    switch (id) {
    case 0: {
        Unk803442CC* p = (Unk803442CC*)operator new(8, 0);
        fn_80344640(p);
        *(const void**)p = lbl_80649718;
        fn_803416C4((Unk803416C4*)p);
        r = (Unk80058060_Node*)p;
        fn_803EE7BC();
        return r;
    }
    case 1: {
        Unk803442CC* p = (Unk803442CC*)operator new(8, 0);
        fn_80344640(p);
        *(const void**)p = lbl_806496E0;
        fn_803416D0((Unk803416C4*)p);
        r = (Unk80058060_Node*)p;
        fn_803EE7BC();
        return r;
    }
    case 2:
        r = (Unk80058060_Node*)fn_8034470C((Unk8034468C*)operator new(0x100, 0));
        fn_803EE7BC();
        return r;
    case 3:
        r = (Unk80058060_Node*)fn_803446C8((Unk8034468C*)operator new(0x9C, 0));
        fn_803EE7BC();
        return r;
    case 4: {
        Unk803442CC* p = (Unk803442CC*)operator new(8, 0);
        fn_80344640(p);
        *(const void**)p = lbl_806496A8;
        fn_803416DC((Unk803416C4*)p);
        r = (Unk80058060_Node*)p;
        fn_803EE7BC();
        return r;
    }
    case 5: {
        Unk803442CC* p = (Unk803442CC*)operator new(8, 0);
        fn_80344640(p);
        *(const void**)p = lbl_80649670;
        fn_803416E8((Unk803416C4*)p);
        r = (Unk80058060_Node*)p;
        fn_803EE7BC();
        return r;
    }
    case 6:
        r = (Unk80058060_Node*)fn_8034468C((Unk8034468C*)operator new(0xC, 0));
        fn_803EE7BC();
        return r;
    default:
        return 0;
    }
}


struct Unk80341FFC;
void fn_80341FFC(Unk80341FFC* p, unsigned short* t);
void fn_802B912C(const char* s);
void fn_802B9180(void);
extern "C" {
void fn_80342148(void* p, const char* name, const void* tbl);
void fn_8034243C(void* p, const char* name, const void* tbl);
void fn_80342730(void* p, const char* name, const void* tbl);
void fn_80342A24(void* p, const char* name, const void* tbl);
void fn_80342D18(void* p, const char* name, const void* tbl);
void fn_80343024(void* p, const char* name);
void fn_803432EC(void* p, const char* name);
void fn_803435B4(void* p, const char* name);
void fn_8034387C(void* p, const char* name);
void fn_80343B44(void* p, const char* name);
void fn_80343DE4(void* p, const char* name);
}
Unk80058060_Node* fn_80057204(int id);
extern unsigned short lbl_806186D0[];
extern const char* lbl_806186CC;
extern const char lbl_805ADAB0[];
extern const char lbl_805ADAC8[];
extern const char lbl_805ADADC[];
extern const char lbl_805ADAFC[];
extern const char lbl_805ADB18[];
extern const char lbl_805ADB2C[];
extern const char lbl_805ADB50[];
extern const char lbl_805ADB6C[];
extern const char lbl_805ADB94[];
extern const char lbl_805ADBC0[];
extern const char lbl_805ADBE4[];
extern char lbl_80618BB0[];
extern char lbl_80618D00[];
extern char lbl_80618A80[];

struct Unk80341F1C;
struct Unk80341E5C;
struct Unk80341D9C;
struct Unk80341CDC;
struct Unk80341C1C;
struct Unk80341B5C;
struct Unk80341AA0;
struct Unk803419E4;
struct Unk80341928;
struct Unk8034186C;
struct Unk803417B0;
struct Unk803416F4;
void fn_80341F90(Unk80341F1C* p, int c);
void fn_80341ED0(Unk80341E5C* p, int c);
void fn_80341E10(Unk80341D9C* p, int c);
void fn_80341D50(Unk80341CDC* p, int c);
void fn_80341C90(Unk80341C1C* p, int c);
void fn_80341BD0(Unk80341B5C* p, int c);
void fn_80341B10(Unk80341AA0* p, int c);
void fn_80341A54(Unk803419E4* p, int c);
void fn_80341998(Unk80341928* p, int c);
void fn_803418DC(Unk8034186C* p, int c);
void fn_80341820(Unk803417B0* p, int c);
void fn_80341764(Unk803416F4* p, int c);
void fn_80377408(void* p);
struct Unk800575E4_E1 {
    char pad0[0xC];
    virtual ~Unk800575E4_E1();
};
struct Unk800575E4_E2 {
    char pad0[0x10];
    virtual ~Unk800575E4_E2();
};
struct Unk800575E4_M {
    char pad0[0xF8];
    Unk800575E4_E1* mF8;
    Unk800575E4_E2* mFC;
};

void fn_800575E4(Unk800575E4_M* m, int c)
{
    if (m->mF8 != 0) {
        delete m->mF8;
        m->mF8 = 0;
    }
    if (m->mFC != 0) {
        delete m->mFC;
        m->mFC = 0;
    }
    if (lbl_80687600 != 0) {
        delete (Unk80056A08_Ring*)lbl_80687600;
        lbl_80687600 = 0;
    }
    if (lbl_80687604 != 0) {
        delete (Unk80056A08_Ring*)lbl_80687604;
        lbl_80687604 = 0;
    }
    char* b = (char*)m;
    fn_80341F90((Unk80341F1C*)(b + 0xDC), 2);
    fn_80341ED0((Unk80341E5C*)(b + 0xC4), 2);
    fn_80341E10((Unk80341D9C*)(b + 0xAC), 2);
    fn_80341D50((Unk80341CDC*)(b + 0x94), 2);
    fn_80341C90((Unk80341C1C*)(b + 0x7C), 2);
    fn_80341BD0((Unk80341B5C*)(b + 0x64), 2);
    fn_80341B10((Unk80341AA0*)(b + 0x54), 2);
    fn_80341A54((Unk803419E4*)(b + 0x44), 2);
    fn_80341998((Unk80341928*)(b + 0x34), 2);
    fn_803418DC((Unk8034186C*)(b + 0x24), 2);
    fn_80341820((Unk803417B0*)(b + 0x14), 2);
    fn_80341764((Unk803416F4*)(b + 0x4), 2);
    if (c & 1) {
        fn_80377408(m);
    }
}

void fn_80057778(void* p)
{
    Unk80057204_Mgr* m = (Unk80057204_Mgr*)p;
    char* b = (char*)m;
    fn_80341FFC((Unk80341FFC*)(b + 0x54), lbl_806186D0);
    unsigned i = 0;
    fn_802B912C(lbl_806186CC);
    fn_80342148(b + 0x4, lbl_805ADAB0, lbl_80618BB0);
    fn_8034243C(b + 0x14, lbl_805ADAC8, lbl_80618CB0);
    fn_80342730(b + 0x24, lbl_805ADADC, lbl_80618D00);
    fn_80342A24(b + 0x34, lbl_805ADAFC, &lbl_80618F6C);
    fn_80342D18(b + 0x44, lbl_805ADB18, lbl_80618A80);
    fn_80343024(b + 0x64, lbl_805ADB2C);
    fn_803432EC(b + 0x7C, lbl_805ADB50);
    fn_803435B4(b + 0x94, lbl_805ADB6C);
    fn_8034387C(b + 0xAC, lbl_805ADB94);
    fn_80343B44(b + 0xC4, lbl_805ADBC0);
    fn_80343DE4(b + 0xDC, lbl_805ADBE4);
    fn_802B9180();
    unsigned n = m->mC0;
    m->mF4 = new (0) Unk80058060_Node*[n];
    fn_803EE7BC();
    for (; i < n; i++) {
        m->mF4[i] = fn_80057204(m->mBC[i]);
    }
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

struct Unk80057950_E {
    virtual ~Unk80057950_E();
};
struct Unk803416F4;
struct Unk803417B0;
struct Unk8034186C;
struct Unk80341928;
struct Unk803419E4;
struct Unk80341AA0;
struct Unk80341B5C;
struct Unk80341C1C;
struct Unk80341CDC;
struct Unk80341D9C;
struct Unk80341E5C;
struct Unk80341F1C;
void fn_8034170C(Unk803416F4* p);
void fn_803417C8(Unk803417B0* p);
void fn_80341884(Unk8034186C* p);
void fn_80341940(Unk80341928* p);
void fn_803419FC(Unk803419E4* p);
void fn_80341AB8(Unk80341AA0* p);
void fn_80341B78(Unk80341B5C* p);
void fn_80341C38(Unk80341C1C* p);
void fn_80341CF8(Unk80341CDC* p);
void fn_80341DB8(Unk80341D9C* p);
void fn_80341E78(Unk80341E5C* p);
void fn_80341F38(Unk80341F1C* p);

void fn_80057950(Unk80057204_Mgr* m)
{
    unsigned i = 0;
    unsigned n = m->mC0;
    for (; i < n; i++) {
        Unk80057950_E* e = (Unk80057950_E*)m->mF4[i];
        if (e != 0) {
            delete e;
            m->mF4[i] = 0;
        }
    }
    if (m->mF4 != 0) {
        delete[] m->mF4;
        m->mF4 = 0;
    }
    char* b = (char*)m;
    fn_8034170C((Unk803416F4*)(b + 0x4));
    fn_803417C8((Unk803417B0*)(b + 0x14));
    fn_80341884((Unk8034186C*)(b + 0x24));
    fn_80341940((Unk80341928*)(b + 0x34));
    fn_803419FC((Unk803419E4*)(b + 0x44));
    fn_80341AB8((Unk80341AA0*)(b + 0x54));
    fn_80341B78((Unk80341B5C*)(b + 0x64));
    fn_80341C38((Unk80341C1C*)(b + 0x7C));
    fn_80341CF8((Unk80341CDC*)(b + 0x94));
    fn_80341DB8((Unk80341D9C*)(b + 0xAC));
    fn_80341E78((Unk80341E5C*)(b + 0xC4));
    fn_80341F38((Unk80341F1C*)(b + 0xDC));
}

void fn_80057A4C(Unk80057204_Mgr* m)
{
    if (fn_80057938(m)) {
        unsigned n = m->mC0;
        for (unsigned i = 0; i < n; i++) {
            m->mF4[i]->v2();
        }
        m->m100 = 0;
        ((void (*)(Unk80057204_Mgr*))fn_80057B10)(m);
    }
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
