/*
 * Game code, .text 0x80216CF4-0x8021ADDC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern const Vec3f lbl_805D6760[];
extern const Vec3f lbl_805D676C;

extern "C" {
float fn_80248450(void* p, const Vec3f* v, int a, int b);
void fn_8021A53C(Task* t, Vec3f* a, Vec3f* b);
}

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

inline int GetB(Ctx6F8Inner* c) { return c->m1CC9; }
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

/* near-miss: 14 stores plus two Vec3 copies; best hill-climb order is 111 slots off */
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
    e->m0 = 8;
    e->m4 = 0x19;
    e->m8 = 2;
    e->mC = 2;
    e->m10 = 0xA;
    e->m14 = 0x1D;
    e->m20 = 4;
    e->m28 = x;
    e->m44 = lbl_806055AC;
    e->m50 = lbl_806055AC;
    e->m80 = -1.0f;
    e->m84 = 0.0f;
    e->m90 = 0.16666667f;
    e->m9C = 1;
}

void fn_8021A4A0(Task* t, int i)
{
    Obj36C* obj = t->m9C->m4->m36C;
    Vec3f a = FlatPos(obj->m60);
    Vec3f b = lbl_805D6760[i];
    fn_8021A53C(t, &a, &b);
}

}
