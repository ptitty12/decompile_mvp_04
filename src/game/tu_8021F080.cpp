/*
 * Game code, .text 0x8021F080-0x8022309C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

struct Unk8019F8C0_Owner;
int fn_801A2034(Unk8019F8C0_Owner* o, int k); /* C++ linkage: mangled by the owner type */

extern "C" {
int fn_802055F4(TaskInner* in);
int fn_80205664(TaskInner* in);
int fn_80226BC0(Task* t);
void fn_8014E09C(IterObj* it, CtxOwner* c, int x);
void fn_8014E108(IterObj* it);
int fn_8026D940(void* o, int x);
void fn_801EDE78(Task* t, int x);
void fn_801F0174(Task* t, int a, int b);
void fn_802044A4(Task* t, int a, void* p, float f);
void fn_801F0EA8(Task* t, int a);
}

extern char lbl_80660C48[];

class Unk802A9B9C : public EvBase {
public:
    int m8;
    int mC;
    Unk802A9B9C(int id) : EvBase(id)
    {
        m4 = lbl_80660C48;
        mC = 0;
        m8 = 0;
    }
    ~Unk802A9B9C() { m4 = lbl_80649DA0; }
    void fn_802A9B9C(int a);
    void fn_802A9BA4(int a);
};

extern const float lbl_805D6320;
extern const float lbl_805D6330;
extern const float lbl_805D6334;

extern "C" {

float fn_802478A0(void* o, void* p, int a, int b);
float fn_8018D2EC(Obj4_36C* o, int a);

float fn_80259A74(void* list, int a, int b);
int fn_80210FC4(Sub* t, int kind, int x, Player** out);

extern Vec3f lbl_805D6244;

int fn_8021F490(Task* t)
{
    TaskInner* in = t->m9C;
    Obj4_36C* o = in->m4;
    if (in->m2CC == 1 || in->mC0.m[3] != o->m374->m460) {
        return 0;
    }
    Player* out = 0;
    if (fn_80210FC4((Sub*)&t->m9C, 2, 3, &out) == 0) {
        return 1;
    }
    float a = fn_80259A74(t->m9C->m0->m700->m3B4, out->m458, 3);
    float b = o->m37C - o->m3F4;
    float c = 0.0f;
    if (t->m9C->m98 == 3) {
        c = 0.2f;
    } else {
        c = 0.0f;
    }
    return b >= a + c;
}

void fn_8021FFD4(Task* t, int, RecQueue* q)
{
    Rec* e = &q->e[0];
    TaskInner* in = t->m9C;
    Obj4_36C* o4 = in->m4;
    if (e->mA4 == 1) {
        e->mA4 = 0;
    }
    if (e->m28 == 0) {
        return;
    }
    if (o4->m36C == 0) {
        return;
    }
    if ((void*)o4->m36C == (void*)e->m28) {
        return;
    }
    e->mA4 = 1;
    e->m80 = lbl_805D6244.x;
    e->m9C = 0;
    e->mAC = 0;
}

struct Unk80220808_In {
    char pad0[0x1A0];
    int m1A0;
};
struct Unk80220808_O {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x36C - 0x6C];
    Obj36C* m36C;
};
struct Unk80220330_In { char pad0[0x9C]; int m9C; };
extern int lbl_8061B9C8;
void fn_802099F8(void* p, int a); /* retail: Unk801EE438_Scr* */
void fn_80205784(void* p, int a, int b);
int fn_801F0004(Task* t, int* out);
void fn_801EDE78(Task* t, int a);
void fn_80220330(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    int lim = 0xF0 / lbl_8061B9C8;
    if (e->mA4 == 1) {
        e->mA4 = 0;
        e->m90 = 0.0f;
    }
    e->m90 = e->m90 + 1.0f;
    if ((int)e->m90 % 3 == 0) {
        void* sub = (char*)t + 0xA8;
        fn_802099F8(sub, 0);
        fn_80205784(sub, 0, 0);
        int z = 0;
        if (fn_801F0004(t, &z) == 0 || !(e->m90 < (float)lim)) {
            ((Unk80220330_In*)t->m9C)->m9C = 1;
            fn_801EDE78(t, 1);
            fn_801F0174(t, a, 1);
        }
    }
}

void fn_80220808(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    TaskInner* in = t->m9C;
    Unk80220808_O* o = (Unk80220808_O*)in->m4;
    Obj36C* x = (Obj36C*)ObjAt(in->m8, a);
    if (e->mA4 == 1) {
        e->mA4 = 0;
    }
    if (o->m36C == x) {
        e->m90 = e->m90 - 0.016666668f;
        if (e->m90 <= 0.0f || ((Unk80220808_In*)t->m9C)->m1A0 == 0) {
            fn_801F0174(t, a, 0);
        }
    } else {
        e->m94 = 1;
        e->m50 = o->m60 - x->m60;
        e->m50.y = 0.0f;
    }
}

struct Unk8026C414_O;
struct Unk8026C414_X;
struct Unk8024EF40_A;
struct Unk8024EF40_P;
extern "C++" {
int fn_8026D914(Unk8026C414_O* o, Unk8026C414_X* x);
int fn_80254A90(Unk8024EF40_A* a);
void fn_80251E80(Unk8024EF40_P* p);
}
extern "C++" { int fn_8026DD60(Unk8026C414_O* o, Unk8026C414_X* x); }
int fn_802110F8(Sub* t, int kind, void* o, int k);
void fn_801EC5F8(Task* t, int a);
void fn_80205450(TaskInner* g, int i);
void fn_802123D4(Task* t, int a, int b);
void fn_8021D4A4(Task* t);
void fn_801F0EA8(Task* t, int a);
void fn_801F0174(Task* t, int a, int b);
void fn_802252F4(Task* t, int a, RecQueue* q);
float fn_804028E4(float x);
extern const float lbl_805D6294;
extern const float lbl_805D6298;
extern const float lbl_805D629C;
extern const float lbl_805D62A8;
extern int lbl_8061B9C8;

/* near-miss 98.4%: same instruction stream; differs in slwi r0 vs r11 (index temp) and the order of the lfs f1 / lfs f31
   pair before fn_804028E4. The dead 'float k' local reproduces the stfs f31,8(r1) spill. Tried hoisting k, an int index copy. */
void fn_80220BFC(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    Player* pl = e->m28;
    Player* p = (Player*)t->m9C->m8[a];
    int ok = 0;
    if (fn_8026D914((Unk8026C414_O*)p, 0) == 1)
        goto set;
    if (e->m90 > lbl_805D6294)
        goto big;
    if (fn_80254A90((Unk8024EF40_A*)&pl->m58C) != 0)
        goto after;
set:
    ok = 1;
    goto after;
big:
    if (*(unsigned*)((char*)pl + 0x590) & 0x20000000)
        goto set;
    e->m90 = e->m90 - lbl_805D6298;
after:
    if (ok == 1) {
        if (e->m1C == 3 && fn_8026D914((Unk8026C414_O*)p, 0) == 1) {
            if (p->m44C->m6CC->m36C == 0) {
                fn_80251E80((Unk8024EF40_P*)p);
                fn_80205450(t->m9C, a);
                fn_802123D4(t, 0, 1);
                fn_8021D4A4(t);
                if (fn_80210C98((Sub*)&t->m9C, 0) == 1) {
                    fn_801EC5F8(t, a);
                    return;
                }
                goto generic;
            }
            return;
        }
    generic:
        fn_801F0EA8(t, a);
        if (p->m450 != 0) {
            fn_80251E80((Unk8024EF40_P*)p);
            fn_801F0174(t, a, 0);
        } else {
            fn_80205450(t->m9C, a);
            fn_802123D4(t, 0, 1);
            fn_8021D4A4(t);
            if (fn_80210C98((Sub*)&t->m9C, 0) == 1)
                fn_801EC5F8(t, a);
        }
    } else {
        float k = lbl_805D629C;
        float v = fn_804028E4(*(float*)((char*)pl + 0x8E8)) / ((float)lbl_8061B9C8 * lbl_805D62A8);
        if (fn_8026DD60((Unk8026C414_O*)pl, 0) == 0) {
            if (fn_802110F8((Sub*)&t->m9C, 2, pl, e->m1C) == 0 || !(v >= lbl_805D629C)) {
                fn_801F0174(t, a, 0);
                return;
            }
        }
        fn_802252F4(t, a, (RecQueue*)e);
    }
}

void fn_80220E48(Task* t, int a, Player* p)
{
    TaskInner* in = t->m9C;
    int z = in->m74;
    if (z == 0 && in->m70 == 1) {
        int f = p->m58C.m4b;
        if (f == 1) {
            Unk802A9B9C e(0x6E);
            e.fn_802A9B9C((int)p);
            e.fn_802A9BA4(a);
            fn_8037893C(t->m9C->m0->m704, e.m0, &e, 0, 0);
            t->m9C->m74 = f;
        }
    }
}

void fn_802217E0(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    void* x = ObjAt(t->m9C->m8, a);
    if (e->mA4 == 1) {
        if (!(e->m80 >= lbl_805D6320)) {
            e->m80 = (float)t->m9C->m0->m4C * lbl_805D6330 + fn_802478A0(x, (char*)q + 0x3C, e->mC, e->m10) + lbl_805D6334;
        }
        e->mA4 = 0;
    }
}

extern Vec3f lbl_805D6338;
void fn_802218A4(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    Obj4_36C* o = t->m9C->m4;
    if (e->mA4 == 1) {
        fn_802044A4(t, a, (char*)q + 0x48, e->m84);
        e->mA4 = 0;
    }
    Obj36C* x = o->m36C;
    if (x != 0) {
        if ((void*)x == ObjAt(t->m9C->m8, a)) {
            t->m9C->mA4 = -1;
            t->m9C->m30 = 4;
            fn_801F0EA8(t, a);
            fn_801F0174(t, a, 0);
            return;
        }
        e->mA4 = 1;
        e->m80 = lbl_805D6338.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

int fn_80221974(Task* t)
{
    if (fn_802055F4(t->m9C) == 1 && fn_80205664(t->m9C) == 0) {
        Obj3A64* o = t->m9C->m3A64;
        if (o->m798 != 0 || o->m794 != 0) {
            return fn_80226BC0(t);
        }
    }
    return 1;
}

int fn_802219EC(Task* t)
{
    IterObj it;
    fn_8014E09C(&it, t->m9C->m0, 1);
    IterObj* p = &it;
    while (p->m8 != 10) {
        int i = p->m8;
        if (fn_8026D940(ObjAt(t->m9C->m8, i), 0) != 0) {
            return 1;
        }
        fn_8014E108(p);
    }
    return 0;
}

/* near-miss: loop pointer lives in r31 here; retail passes it in r3 and keeps a copy in r31 (3 slots) */
unsigned fn_801BBF24(int x);
int fn_80204F8C(Rec* r);
int fn_80204F30(Rec* r);
struct Unk80221A70_Ow {
    char pad0[0x3BC];
    int m3BC;
};
struct Unk80221A70_Ctx {
    char pad0[0x6CC];
    Obj4_36C* m6CC;
    char pad6D0[0x700 - 0x6D0];
    Unk80221A70_Ow* m700;
};
struct Unk80221A70_It {
    char pad0[8];
    int m8;
    char padC[0x18 - 0xC];
    int Cur() { return m8; }
};
int fn_80221A70(Task* t)
{
    if (fn_801A2034((Unk8019F8C0_Owner*)t->m9C->m0, 4) != -1)
        return 1;
    Unk80221A70_Ctx* c = (Unk80221A70_Ctx*)t->m9C->m0;
    if (c->m6CC->m36C != 0)
        return 1;
    if (fn_801BBF24(c->m700->m3BC) <= 2)
        return 1;
    Unk80221A70_It it;
    fn_8014E09C((IterObj*)&it, t->m9C->m0, 1);
    while (it.Cur() != 10) {
        RecQueue* base = t->m9C->mCA8;
        RecQueue* q = &base[it.Cur()];
        int i = 0;
        Rec* r = &q->e[0];
        while (i < q->count) {
            if (fn_80204F8C(r) != 1)
                break;
            r++;
            i++;
        }
        if (i < q->count) {
            if (fn_80204F30(r) != 0 || r->m0 == 0x1B)
                return 1;
        }
        fn_8014E108((IterObj*)&it);
    }
    return 0;
}

extern const char lbl_80660A90[];
struct Unk80221B8C_El {
    int m0;
    float m4;
    float m8;
};
struct Unk80221B8C_Obj {
    int m0;
    int m4;
    const void* m8;
    Unk80221B8C_El mC[9];
    ~Unk80221B8C_Obj() { m8 = lbl_80660A90; }
};
struct Unk80221B8C_It {
    char pad0[8];
    int m8;
    char padC[0x18 - 0xC];
    int Cur() { return m8; }
};
struct Unk80221B8C_Pl {
    char pad0[0x71C];
    unsigned m71C;
};
int fn_8020CD10(void* unused, int k);
Unk80221B8C_Obj* fn_802116B4(Unk80221B8C_Obj* o, TaskInner* g);
void fn_80211778(Unk80221B8C_Obj* o, int a);
void fn_80205450(TaskInner* g, int i);
void fn_802123D4(Task* t, int a, int b);
void fn_80214B10(Task* t, int a, int b);

/* near-miss (10 slots, registers only in the inner scan loop) */
void fn_80221B8C(Task* t)
{
    int n = 0;
    int lim = 2;
    if (fn_8020CD10((char*)t->m9C + 0x2C, t->m9C->mA4) == 0 || fn_801A2034((Unk8019F8C0_Owner*)t->m9C->m0, 4) == -1)
        lim = 1;
    Unk80221B8C_It it;
    fn_8014E09C((IterObj*)&it, t->m9C->m0, 7);
    while (it.Cur() != 10) {
        TaskInner* in = t->m9C;
        int i = it.Cur();
        RecQueue* base = in->mCA8;
        RecQueue* q = &base[i];
        if (!(((Unk80221B8C_Pl*)ObjAt(in->m8, i))->m71C & 0x1000) && q->count != 0 && q->e[0].m0 == 0x1D) {
            n++;
            if (n > lim) {
                Unk80221B8C_Obj o;
                fn_802116B4(&o, t->m9C);
                fn_80211778(&o, 1);
                int j = 8;
                do {
                    RecQueue* rb = t->m9C->mCA8;
                    RecQueue* r = &rb[o.mC[j].m0];
                    if (r->count > 0 && r->e[0].m0 == 0x1D) {
                        fn_80205450(t->m9C, o.mC[j].m0);
                        n--;
                        fn_802123D4(t, 1, 1);
                        fn_80214B10(t, 2, 2);
                        break;
                    }
                } while (--j >= 0);
            }
        }
        fn_8014E108((IterObj*)&it);
    }
}

int fn_80221D0C(Task* t, int k)
{
    int r = 0;
    if (k <= 8) {
        TaskInner* in = t->m9C;
        if ((!(in->m6D0[k].m0 < 0.0f) && in->m6D0[k].m4 >= 0) || in->m6D0[k].m34 != 0) {
            r = 1;
        }
    }
    const float c = 0.25f;
    float d = t->m9C->m6D0[k].m0 - (float)t->m9C->m0->m4C * 0.016666668f;
    Obj4_36C* o = t->m9C->m0->m6CC;
    float e = fn_8018D2EC(o, 0) - o->m3F4;
    if (!(d - c <= e)) {
        r = 0;
    }
    return r;
}

void fn_80222AE0(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    if (e->mA4 == 1) {
        e->mA4 = 0;
    }
    if (fn_80210C98((Sub*)&t->m9C, 3) == 1) {
        fn_801EDE78(t, 1);
        fn_801F0174(t, a, 0);
    }
}

}

extern "C" {
float fn_8018A214(Obj4_36C* o);
void fn_801E8A3C(Obj3A64* p, int a, int b);
void fn_801EC5F8(Task* t, int a);
void fn_8021CE28(Task* t, float f);
int fn_801EE6F4(Task* t, int a);
void fn_80205450(TaskInner* g, int i);
void fn_802123D4(Task* t, int a, int b);
int fn_80205664(TaskInner* in);

inline void SetM4(void* s, float x)
{
    ((float*)s)[1] = x;
}
struct Unk80222B54_S {
    TaskInner* m0;
    float m4;
};

/* near-miss (7 slots): the constant-zero register and store order in the early-return block (retail stores mA4, mAC, m80, m9C with one li r0,0) */
void fn_80222B54(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    Obj4_36C* o = t->m9C->m4;
    if (e->mA4 == 1) {
        fn_802044A4(t, a, (char*)q + 0x48, e->m84);
        e->mA4 = 0;
    }
    if (fn_80205664(t->m9C) == 1)
        fn_801E8A3C(t->m9C->m3A64, a, -1);
    Unk80222B54_S* sub = (Unk80222B54_S*)((char*)t + 0xA0);
    if (!(e->m84 < sub->m4)) {
        float v = (float)t->m9C->m0->m4C * 0.016666668f + fn_8018A214(o);
        if (!(v < e->m84)) {
            SetM4(sub, v);
            fn_80205450(t->m9C, a);
            fn_802123D4(t, 1, 1);
            fn_801EC5F8(t, a);
        }
    }
    if (o->m36C != 0) {
        t->m9C->mA4 = -1;
        t->m9C->m30 = 4;
        if (o->m36C->m460 != a) {
            e->mA4 = 1;
            e->mAC = 0;
            e->m80 = 0.0f;
            e->m9C = 0;
            return;
        }
        if (t->m9C->m6A8 == 1 && fn_80210C98((Sub*)&t->m9C, 3) == 0) {
            int r = fn_802055F4(t->m9C);
            if (r == 0) {
                fn_801EE6F4(t, a);
                fn_801F0EA8(t, a);
                fn_80205450(t->m9C, a);
                fn_802123D4(t, 1, 1);
                fn_8021CE28(t, 0.8333334f);
                t->m9C->m6A8 = r;
                return;
            }
        }
        fn_801EE6F4(t, a);
        fn_801F0EA8(t, a);
        fn_801F0174(t, a, 0);
    }
}
}
