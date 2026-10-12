/*
 * Game code, .text 0x80216CF4-0x8021ADDC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern const char lbl_80660C90[];
extern const char lbl_80660CA8[];
extern const char lbl_80660CC0[];
extern const float lbl_805D5FF4;
extern const float lbl_805D5FF8;
extern const float lbl_805D5FFC;
extern const float lbl_805D6000;
extern const Vec3f lbl_805D6760[];
extern const Vec3f lbl_805D676C;

extern "C" {
float fn_80248450(void* p, const Vec3f* v, int a, int b);
void fn_8021A53C(Task* t, Vec3f* a, Vec3f* b);
int fn_801A9D9C(void* o, int i);
void fn_80205450(TaskInner* in, int x);
int fn_80204F8C(Rec* r);
int fn_80204F30(Rec* r);
void fn_802123D4(Task* t, int kind, int x);
void fn_80218294(Task* t, int a, int b, int c, int d);
void fn_8021D4A4(Task* t);
int fn_802055F4(TaskInner* in);
int fn_80227994(Task* t, int a);
void fn_8021CE28(Task* t, float f);
}

inline int GetB(Ctx6F8Inner* c) { return c->m1CC9; }

struct Unk8017A930_T;
void fn_8017B4A0(Unk8017A930_T* p, int a);

inline Vec3f FlatPos(const Vec3f& p)
{
    Vec3f r = p;
    r.y = 0.0f;
    return r;
}

extern "C" {

struct Sub65C {
    char pad0[0x24];
    int m24;
    Player* m28;
};


int fn_80217B80(Task* t, Player* p, int kind)
{
    TaskInner* in = t->m9C;
    Sub65C* s = (Sub65C*)((char*)p->m44C + 0x65C);
    int b = GetB(in->m0->m6F8->m14);
    int cur = in->mC0.m[1];
    int v24 = s->m24;
    Player* pl = s->m28;
    if (kind == 7 && b <= 1 && v24 != 0 && pl != 0) {
        PlayerSub* ps = &pl->m58C;
        if (ps->m8 == 0.0f && ps->m30 == 1 && p->m460 == cur) {
            return 1;
        }
    }
    return 0;
}

int fn_80217C04(Task* t, Obj36C* obj, void* other)
{
    float a = fn_80248450(other, &lbl_805D676C, 3, 6);
    float b = 0.0f;
    if (!((obj->m60.x - lbl_805D676C.x) * (obj->m60.x - lbl_805D676C.x)
              + (obj->m60.z - lbl_805D676C.z) * (obj->m60.z - lbl_805D676C.z)
          <= 1296.0f)) {
        b = fn_80248450(obj, &lbl_805D676C, 3, 6);
    }
    float diff = a - b;
    const float k = 0.8f;
    if (diff > k) {
        return 0x17;
    }
    return 0x16;
}

void fn_80218A30(Task* t, int, int b, int idx)
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
    e->m4 = 0;
    e->m0 = 3;
    e->m28 = (Player*)t->m9C->m8[idx];
    e->m1C = b;
    e->m9C = 1;
}

struct Obj71C {
    char pad0[0x71C];
    unsigned m71C;
};

inline RecQueue* RqAt(RecQueue* b, int k)
{
    return b + k;
}

class Ev72 : public EvBase {
public:
    Ev72() : EvBase(0x72) { m4 = lbl_80660C90; }
    ~Ev72() { m4 = lbl_80649DA0; }
};

void fn_80218CD4(Task* t, int a)
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
    e->m4 = 0x1C;
    e->m0 = 5;
    e->m14 = a;
    e->m9C = 1;
    Ev72 ev;
    fn_8037893C(t->m9C->m0->m704, ev.m0, &ev, 0, 0);
}

inline void SetAt(int* a, int i, int v)
{
    int o = i * 4;
    *(int*)((char*)a + o) = v;
}

class Unk802A9B68 : public EvBase {
public:
    int m8;
    Unk802A9B68() : EvBase(0x68) { m4 = lbl_80660CC0; }
    ~Unk802A9B68() { m4 = lbl_80649DA0; }
    void fn_802A9B68(int a);
};

void fn_802195D4(Task* t, int a)
{
    if (fn_802055F4(t->m9C) == 1) {
        fn_80227994(t, 0);
        Unk802A9B68 ev;
        ev.fn_802A9B68(a);
        fn_8037893C(t->m9C->m0->m704, ev.m0, &ev, 0, 0);
    } else {
        if (fn_80210FC4((Sub*)&t->m9C, 2, a, 0) == 0 || GetB(t->m9C->m0->m6F8->m14) > 2) {
            fn_8021CE28(t, lbl_805D5FF4);
        } else {
            int k = 5;
            int r = fn_801A9D9C(t->m9C->m0->m700->m3C4, a);
            if (t->m9C->m0->m700->m41C == 0x11) {
                k = 6;
            }
            t->m9C->m60 = 0;
            t->m9C->m0->m700->m41C = 10;
            fn_80205450(t->m9C, t->m9C->m3A5C);
            fn_802123D4(t, 0, 1);
            fn_80218294(t, r, a, 1, k);
            fn_8021D4A4(t);
            Unk802A9B68 ev;
            ev.fn_802A9B68(a);
            fn_8037893C(t->m9C->m0->m704, ev.m0, &ev, 0, 0);
        }
    }
}

class Unk802A9B70 : public EvBase {
public:
    int m8;
    Unk802A9B70() : EvBase(0x6A) { m4 = lbl_80660CA8; }
    ~Unk802A9B70() { m4 = lbl_80649DA0; }
    void fn_802A9B70(int a);
};

void fn_802197A0(Task* t, int a)
{
    int r = fn_801A9D9C(t->m9C->m0->m700->m3C4, a);
    SetAt(t->m9C->mC0.m, a, r);
    Unk802A9B70 ev;
    ev.fn_802A9B70(a);
    fn_8017B4A0((Unk8017A930_T*)t->m9C->m0->m700, (int)&ev);
    fn_8037893C(t->m9C->m0->m704, ev.m0, &ev, 0, 0);
    fn_80205450(t->m9C, t->m9C->m3A5C);
    fn_802123D4(t, 0, 1);
    int k = 10;
    if (t->m9C->mC90 != 0) {
        k = 11;
    }
    fn_80218294(t, r, a, 1, k);
    fn_8021D4A4(t);
}

/* near-miss: 77/77 insns, 2 slots (the m8 and m28 stores are swapped). Statement order = retail's store order; the three
   floats are read through extern lbl_ globals (literals would be hoisted into callee-saved registers). */
void fn_802198AC(Task* t, Player* x)
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
    e->m4 = 0x19;
    e->m0 = 8;
    e->m9C = 1;
    e->m10 = 0xA;
    e->m28 = x;
    e->m14 = 0x1D;
    e->mC = 2;
    e->m84 = lbl_805D5FF8;
    e->m80 = lbl_805D5FFC;
    e->m8 = 2;
    e->m44 = lbl_806055AC;
    e->m50 = lbl_806055AC;
    e->m20 = 4;
    e->m90 = lbl_805D6000;
}

/* near-miss: 61/61 insns, 4 slots: retail keeps the running element pointer in r3 (recomputed as cur + 1 after the call)
   and copies it into the callee-saved cur each iteration; ours increments the saved register in place. Tried NextRec(),
   for/while forms. The two flag tests are separate nested ifs (a combined mask is merged into 0x6000). */
int fn_8021A194(Task* t, int a)
{
    TaskInner* in = t->m9C;
    Obj71C* obj = (Obj71C*)ObjAt(in->m8, a);
    RecQueue* q = RqAt(in->mCA8, a);
    if (obj == 0 || q == 0) {
        return 0;
    }
    int s = fn_80211BB0(&in->mC0, a);
    int r = 0;
    Rec* e = q->e;
    Rec* cur = e;
    int i = 0;
    while (i < q->count) {
        cur = e;
        if (fn_80204F8C(cur) != 1) {
            break;
        }
        e = cur + 1;
        i++;
    }
    if (i < q->count) {
        if (fn_80204F30(cur) == 0 && t->m9C->mA4 != a) {
            unsigned f = obj->m71C;
            if ((f & 0x4000) == 0) {
                if ((f & 0x2000) == 0) {
                    if (s == -1) {
                        r = 1;
                    }
                }
            }
        }
    } else {
        r = 1;
    }
    return r;
}

void fn_8021A4A0(Task* t, int i)
{
    Obj36C* obj = t->m9C->m4->m36C;
    Vec3f a = FlatPos(obj->m60);
    Vec3f b = lbl_805D6760[i];
    fn_8021A53C(t, &a, &b);
}

}
