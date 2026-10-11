/*
 * Game code, .text 0x8020EE9C-0x80212AC0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
Player* fn_80257B40(void* list);
Player* fn_80257BD0(void* list, Player* cur, int x);
int fn_80254984(PlayerSub* p);
int fn_80254A34(PlayerSub* p);
int fn_80254B60(PlayerSub* p);
int fn_80254BEC(PlayerSub* p);
int fn_80255028(PlayerSub* p);
int fn_80210DA8(Sub* t, int kind, Player* p);
int fn_802110F8(Sub* t, int kind, Player* p, int x);
void fn_80204CCC(Rec* r);
int fn_8026DAE8(void* obj, int x);
void fn_80214CE8(Task* t, float f, int a, int b, int c, int d);
void fn_80211C04(Ent38* e);
void fn_80211CAC(EntList* l);
float fabsf(float x);
}

extern "C" {

int fn_80210C98(Sub* t, int kind)
{
    void* list = t->m0->m0->m700->m3B4;
    int r = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80210DA8(t, kind, p) == 1) {
            r = 1;
            break;
        }
    }
    return r;
}

int fn_80210D20(Sub* t, int kind)
{
    void* list = t->m0->m0->m700->m3B4;
    int n = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80210DA8(t, kind, p) == 1) {
            n++;
        }
    }
    return n;
}

int fn_80210DA8(Sub* t, int kind, Player* p)
{
    switch (kind) {
    case 0:
        return fn_80254984(&p->m58C);
    case 1: {
        int r = 0;
        if (fn_80254984(&p->m58C) == 1 && p->m458 != 9) {
            r = 1;
        }
        return r;
    }
    case 2:
        return fn_80254A34(&p->m58C);
    case 3:
        return fn_80254B60(&p->m58C);
    case 4:
        return fn_80254BEC(&p->m58C);
    default:
        return 0;
    }
}

int fn_80210FC4(Sub* t, int kind, int x, Player** out)
{
    void* list = t->m0->m0->m700->m3B4;
    int r = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_802110F8(t, kind, p, x) == 1) {
            r = 1;
            if (out) {
                *out = p;
            }
            break;
        }
    }
    return r;
}

int fn_80211064(Sub* t, int kind, Player* p, int* out)
{
    int r = 0;
    volatile int e = 0;
    int c;
    while ((c = e) <= 3) {
        if (fn_802110F8(t, kind, p, c) == 1) {
            r = 1;
            if (out) {
                *out = e;
            }
            break;
        }
        int d = e;
        int n;
        if (d > 3) {
            n = d;
        } else {
            n = d + 1;
        }
        e = n;
    }
    return r;
}

/* near-miss: retail lays out li -1; b end between ble and addi r3,r3,1; ours speculates the addi above the ble */
int fn_802112B4(Sub* t, Player** out)
{
    void* list = t->m0->m0->m700->m3B4;
    Player* found = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80254A34(&p->m58C) == 1) {
            found = p;
            break;
        }
    }
    if (found) {
        *out = found;
        PlayerSub* s = &found->m58C;
        if (fn_80254B60(s) == 1) {
            return fn_80255028(s);
        }
        int v = s->m38;
        if (v <= 2) {
            return v + 1;
        }
    }
    return -1;
}

Player* fn_80211370(Sub* t)
{
    void* list = t->m0->m0->m700->m3B4;
    Player* found = 0;
    for (Player* p = fn_80257B40(list); p; p = fn_80257BD0(list, p, 0)) {
        if (fn_80254B60(&p->m58C) == 1) {
            found = p;
            break;
        }
    }
    return found;
}

int fn_8021157C(CmpPos* a, CmpPos* b)
{
    float d = a->m4 - b->m4;
    if (d < 0.0f) {
        return -1;
    }
    return d > 0.0f;
}

int fn_802115B8(CmpPos* a, CmpPos* b)
{
    float d = a->m4 - b->m4;
    if (d < 0.0f) {
        return -1;
    }
    if (!(d <= 0.0f)) {
        return 1;
    }
    float e = a->m8 - b->m8;
    if (e < 0.0f) {
        return -1;
    }
    return e > 0.0f;
}

int fn_80211624(CmpPos* a, CmpPos* b)
{
    return -fn_802115B8(a, b);
}

int fn_80211648(CmpPos* a, CmpPos* b)
{
    float d = a->m4 - b->m4;
    if (d < 0.0f) {
        return -1;
    }
    if (!(d <= 0.0f)) {
        return 1;
    }
    float e = a->m8 - b->m8;
    if (e < 0.0f) {
        return -1;
    }
    return e > 0.0f;
}

void fn_80211B58(Slots4* s)
{
    volatile int sp8 = 0;
    int e = 0;
    do {
        s->m[e] = -1;
        int c = sp8;
        int t;
        if (c > 3) {
            t = c;
        } else {
            t = c + 1;
        }
        sp8 = t;
        e = t;
    } while (e <= 3);
}

void fn_80211BA0(Slots4* s, int i)
{
    s->m[i] = -1;
}

int fn_80211BB0(Slots4* s, int v)
{
    int found = -1;
    volatile int sp8 = 0;
    int e = 0;
    do {
        if (s->m[e] == v) {
            found = e;
        }
        int t;
        if (e > 3) {
            t = e;
        } else {
            t = e + 1;
        }
        sp8 = t;
        e = t;
    } while (e <= 3);
    return found;
}

void fn_80211C04(Ent38* e)
{
    e->m0 = -1;
    e->m4 = 0;
    e->m8 = 99.0f;
    e->mC = 0;
    e->m10 = 0;
    e->m14 = 0;
    e->m18 = 0;
    e->m1C = 0;
    e->m24 = 0;
    e->m28 = -1;
    e->m2C = lbl_806055DC;
}

inline void SetM0(EntList* l, float v)
{
    l->m0 = v;
}

void fn_80211C64(EntList* l)
{
    fn_80211CAC(l);
    l->mC0 = 0;
    SetM0(l, -99.0f);
}

void fn_80211CAC(EntList* l)
{
    l->m4 = 0;
    l->m8 = 0;
    for (int i = 0; i < 3; i++) {
        fn_80211C04(&l->mC[i]);
    }
    l->mB4 = 0;
    l->mB8 = 0;
    l->mBC = 0;
    fn_8035B940(&l->mC4, -1);
}

void fn_80211D14(EntList* l)
{
    Ent38* p = l->mC;
    for (int i = 0; i < 3; i++) {
        p->m20 = 0;
        p++;
    }
}

int fn_80211D34(EntList* l)
{
    return l->mC[l->m8].m24;
}

Vec3f fn_80211D48(EntList* l)
{
    return l->mC[l->m8].m2C;
}

int fn_80211D78(EntList* l)
{
    return l->mC[l->m8].m0;
}

int fn_80211D8C(EntList* l)
{
    int i = l->m8 + 1;
    if (i < l->m4) {
        return l->mC[i].m0;
    }
    return -1;
}

int fn_80211DB8(EntList* l)
{
    return l->mC[l->m8].m4;
}

int fn_80211DCC(EntList* l)
{
    return l->mC[l->m8].m10;
}

float fn_80211DE0(EntList* l)
{
    return l->mC[l->m8].m8;
}

int fn_80211DF4(EntList* l)
{
    return l->mC[l->m8].m18;
}

int fn_80211E08(EntList* l)
{
    return l->mC[l->m8].m1C;
}

int fn_80211E1C(EntList* l)
{
    return l->mC[l->m8].m20;
}

/* near-miss: block layout: retail duplicates the m10 compare in both type arms and shares the -1/1 tails */
int fn_80211E30(CmpKey* a, CmpKey* b)
{
    if (a->m4 == 7) {
        return -1;
    }
    if (b->m4 == 7) {
        return 1;
    }
    float d = a->mC - b->mC;
    int close = fabsf(d) < 0.01f;
    if (a->m4 == 1) {
        if (b->m4 != 1) {
            return -1;
        }
    } else {
        if (b->m4 == 1) {
            return 1;
        }
    }
    if (!close) {
        if (a->mC > b->mC) {
            return 1;
        }
        return -1;
    }
    if (a->m10 > b->m10) {
        return 1;
    }
    if (a->m10 < b->m10) {
        return -1;
    }
    return 0;
}

void fn_80211EF8(Rec2C* r)
{
    r->m0 = -1;
    r->m4 = -1;
    r->m8 = -1;
    r->mC = -1;
    r->m10 = 0;
    r->m14 = 0;
    r->m18 = 99.0f;
    r->m1C = 99.0f;
    r->m20 = -1.0f;
    r->m24 = 0;
}

void fn_80211F3C(Rec34* r)
{
    r->m0 = 0;
    r->m4 = 0;
    r->m8 = 0;
    r->mC = -99.0f;
    r->m14 = -99.0f;
    r->m10 = -99.0f;
    r->m18 = -99.0f;
    r->m1C = -99.0f;
    r->m20 = -99.0f;
    r->m24 = -99.0f;
    r->m28 = -99.0f;
    r->m2C = -99.0f;
}

void fn_80211F7C(Rec1C* r)
{
    r->m0 = -99.0f;
    r->m4 = -99.0f;
    r->m8 = lbl_806055DC;
    r->m14 = -1.0f;
}

void fn_80211FC0(Rec14* r)
{
    r->m0 = -99.0f;
    r->m4 = -1;
    r->m8 = 0;
    r->mC = 0;
}

void fn_80211FE4(Rec40* r)
{
    r->m0 = -1;
    r->m4 = 0;
    r->mC = 0;
    r->m28 = -99.0f;
    r->m8 = 100000000.0f;
    r->m10 = 0;
    r->m14 = 0;
    r->m18 = 0;
    r->m1C = 0;
    r->m20 = 0;
    r->m2C = -99.0f;
    r->m24 = 0;
    r->m30 = lbl_806055DC;
}

void fn_80212170(Pair2* p, int i, int v)
{
    p->m4[i] = v;
}

void fn_80212180(Pair2* p)
{
    for (int i = 0; i < 2; i++) {
        fn_80212170(p, i, -1);
    }
    p->m0 = 0;
}

void fn_8021239C(Obj74* o, int a, float f, Vec3f* v)
{
    o->m74 = a;
    o->m78 = f;
    o->m7C = *v;
}

void fn_802123D4(Task* t, int kind, int)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    for (int i = 0; i < n; i++) {
    }
    q->count = 0;
    if (kind == 1) {
        int id = t->m9C->m3A5C;
        int idx = fn_80211BB0(&t->m9C->mC0, id);
        if (idx != -1) {
            fn_80211BA0(&t->m9C->mC0, idx);
        }
        idx = fn_80211BB0(&t->m9C->mD4, id);
        if (idx != -1) {
            fn_80211BA0(&t->m9C->mD4, idx);
        }
    }
}

extern Vec3f lbl_805D5C98;
/* The zero comes from a global struct (lbl_805D5C98): a load from an aggregate stays below the
   record stores, as in retail (a scalar or literal float is hoisted above them). */
extern Vec3f lbl_805D5C98;
void fn_8021247C(Task* t)
{
    RecQueue* q = t->m9C->m3A60;
    if (q->count <= 0) return;
    Rec* e = &q->e[0];
    e->mA4 = 1;
    e->m80 = lbl_805D5C98.x;
    e->m9C = 0;
    e->mAC = 0;
}

void fn_802124B8(Task* t)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 1;
    e->m0 = 1;
}

void fn_80212550(Task* t, Vec3f* pos, float a, float b, int c, int d)
{
    TaskInner* in = t->m9C;
    PosObj* obj = (PosObj*)in->m8[in->m3A5C];
    RecQueue* q = in->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 5;
    e->m0 = 0x1B;
    e->mC = d;
    e->m8 = c;
    e->m9C = 1;
    e->m38 = *pos;
    e->m88 = a;
    e->m80 = b;
    e->m94 = 1;
    e->m50 = *pos - obj->m60;
}

void fn_80212A28(Task* t, float f, int a, int b, int c, int d)
{
    TaskInner* in = t->m9C;
    if (in->m30 == 1 && in->m3A60->count <= 0) {
        if (fn_8026DAE8(in->m8[in->m3A5C], 0)) {
            fn_80214CE8(t, f, a, b, c, d);
        }
    }
}

}
