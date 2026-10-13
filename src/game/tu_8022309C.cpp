/*
 * Game code, .text 0x8022309C-0x80227564 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
int fn_8026D988(void* o, int x);
int fn_8026DB3C(void* o, int x);
int fn_8026DAE8(void* o, int x);
void fn_80205450(TaskInner* in, int x);
void fn_802123D4(Task* t, int kind, int x);
void fn_80213B80(Task* t, int a, int b, int c);
void fn_801EDE78(Task* t, int x);
void fn_801F0174(Task* t, int a, int b);
int fn_801E817C(Obj3A64* p, int x);
void fn_802278F4(Task* t);
void fn_801F0EA8(Task* t, int a);
int fn_801EE6F4(Task* t, int a);
void fn_80213988(Task* t, int a, int b);
void fn_8021D4A4(Task* t);
int fn_801F0F30(Task* t);
void fn_8022A71C(Task* t, int a, int b);
int fn_802055F4(TaskInner* in);
void fn_802044A4(Task* t, int a, void* p, float f);
int fn_80205664(TaskInner* in);
void fn_801E8A3C(Obj3A64* p, int a, int b);
void fn_8021CE28(Task* t, float f);
int fn_80210C98(Sub* t, int kind);
void fn_8021354C(Task* t, int a, int b);
void fn_8021B6EC(Task* t, int a, int b);
void fn_80214F1C(Task* t, float f, int a, int b);
}

extern "C" {

extern Vec3f lbl_805D63F4;
extern float lbl_805D63EC[1];

void fn_8022309C(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    Obj4_36C* o = t->m9C->m4;
    if (e->mA4 == 1) {
        fn_802044A4(t, a, (char*)q + 0x48, e->m84);
        e->mA4 = 0;
    }
    if (fn_80205664(t->m9C) == 1) {
        fn_801E8A3C(t->m9C->m3A64, a, -1);
    }
    if (o->m36C != 0) {
        t->m9C->mA4 = -1;
        t->m9C->m30 = 4;
        if (o->m36C->m460 != a) {
            e->mA4 = 1;
            e->m80 = lbl_805D63EC[0];
            e->m9C = 0;
            e->mAC = 0;
        } else {
            int r;
            if (t->m9C->m6A8 == 1 && fn_80210C98((Sub*)&t->m9C, 3) == 0 && (r = fn_802055F4(t->m9C)) == 0) {
                fn_80205450(t->m9C, a);
                fn_801EE6F4(t, a);
                fn_801F0EA8(t, a);
                fn_802123D4(t, 1, 1);
                fn_8021CE28(t, 0.8333334f);
                t->m9C->m6A8 = r;
            } else {
                fn_801EE6F4(t, a);
                fn_801F0EA8(t, a);
                fn_801F0174(t, a, 0);
            }
        }
    }
}

void fn_8022321C(Task* t, int idx, RecQueue* q)
{
    Rec* e = &q->e[0];
    void* o = ObjAt(t->m9C->m8, idx);
    if (fn_8026D988(o, 0) == 1 || fn_8026DB3C(o, 0) == 1) {
        e->mA4 = 1;
        e->m80 = lbl_805D63F4.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

void fn_8022359C(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    e->m90 = e->m90 + 0.016666668f;
    t->m9C->m30 = 7;
    if (fn_80210C98((Sub*)&t->m9C, 3) == 1) {
        t->m9C->m19C = 0;
        fn_801EDE78(t, 1);
        fn_801F0174(t, a, 0);
    }
}

/* TaskInner::m8[] lookup through an inline: keeps the byte offset out of r0 as retail does. */
inline Obj36C* ObjAt80(TaskInner* in, int i)
{
    return (Obj36C*)in->m8[i];
}
inline Vec3f Unk80223628_Flat(Obj36C* o)
{
    Vec3f v = o->m60;
    v.y = 0.0f;
    return v;
}
inline float Unk80223628_Len2(Vec3f v)
{
    return v.x * v.x + v.z * v.z;
}
void fn_801A656C(CtxOwner* c, Obj36C* o, int k);
int fn_801F18A0(Task* t);
void fn_8021BA44(Task* t);
void fn_80223628(Task* t, int idx, RecQueue* q)
{
    Rec* e = &q->e[0];
    Obj36C* o = ObjAt80(t->m9C, idx);
    const float lim = 5184.0f;
    float d2 = Unk80223628_Len2(Unk80223628_Flat(o) - e->m38);
    if (!(d2 >= lim)) {
        e->mA4 = 1;
        e->m80 = 0.0f;
        e->m9C = 0;
        e->mAC = 0;
        fn_801A656C(t->m9C->m0, o, 0xD);
        int r = fn_801F18A0(t);
        if (r == 1) {
            e->mA4 = r;
            e->m80 = 0.0f;
            e->m9C = 0;
            e->mAC = 0;
            fn_80205450(t->m9C, idx);
            fn_8021BA44(t);
        }
    }
}

inline RecQueue* RqAt(RecQueue* b, int k)
{
    return b + k;
}

void fn_80223780(Task* t, int a)
{
    fn_80205450(t->m9C, a);
    int k = fn_80211BB0(&t->m9C->mC0, a);
    if (k != -1) {
        fn_80211BA0(&t->m9C->mC0, k);
        fn_802123D4(t, 0, 0);
        fn_80213988(t, k, 1);
    } else {
        k = fn_80211BB0(&t->m9C->mD4, a);
        if (k != -1) {
            fn_80211BA0(&t->m9C->mD4, k);
            fn_802123D4(t, 0, 0);
            fn_80213B80(t, k, 2, 3);
        } else {
            TaskInner* in = t->m9C;
            int f = 0;
            if ((unsigned)(in->m30 - 1) <= 1 && in->mA4 != -1 && in->m0->m6CC->m36C == 0) {
                f = in->m6D0[a].m30 <= 1;
            }
            if (f == 1) {
                fn_802123D4(t, 1, 1);
                fn_8021354C(t, 3, 4);
            } else {
                fn_802123D4(t, 1, 1);
                fn_8021B6EC(t, 1, 1);
                fn_80214F1C(t, -1.0f, 1, 2);
            }
        }
    }
}

void fn_80223910(Task* t, int a)
{
    TaskInner* in = t->m9C;
    int v = in->mC0.m[3];
    if (v == a || v == -1) {
        fn_80205450(in, a);
        fn_801F0EA8(t, a);
        fn_801EE6F4(t, a);
        fn_802123D4(t, 1, 1);
        fn_80213988(t, 3, 1);
    } else {
        Slots4* s = &in->mD4;
        int k = s->m[3];
        if (k != -1) {
            RecQueue* rq = RqAt(in->mCA8, k);
            if (rq && rq->count != 0) {
                if ((unsigned)(rq->e[0].m0 - 0xC) <= 1) {
                    fn_80211BA0(s, 3);
                }
            } else {
                fn_80205450(in, k);
                fn_801EE6F4(t, k);
                fn_802123D4(t, 1, 0);
                fn_8021D4A4(t);
            }
        }
        fn_80205450(t->m9C, a);
        fn_801F0EA8(t, a);
        fn_801EE6F4(t, a);
        fn_802123D4(t, 1, 1);
        fn_80213B80(t, 3, 2, 3);
    }
}

inline void SetSlot80(Slots4* s, int x, int v)
{
    s->m[x] = v;
}
inline Vec3f Unk802252F4_Flat(Obj36C* o)
{
    Vec3f v = o->m60;
    v.y = 0.0f;
    return v;
}
void fn_8014E388(Vec3f* p, unsigned i);
int fn_801EEFA8(Task* t, int a);
void fn_8021AA44(Task* t, int a, int b);
void fn_802252F4(Task* t, int a, RecQueue* q)
{
    int k = q->e[0].m18;
    if (GetSlot(&t->m9C->mC0, k) != a) {
        if (GetSlot(&t->m9C->mC0, k) == -1) {
            SetSlot80(&t->m9C->mC0, k, a);
            return;
        }
        float d2;
        Obj36C* o = ObjAt80(t->m9C, a);
        Vec3f flat = Unk802252F4_Flat(o);
        Vec3f p;
        fn_8014E388(&p, k);
        d2 = (flat.x - p.x) * (flat.x - p.x) + (flat.z - p.z) * (flat.z - p.z);
        if (!(d2 > 17424.0f)) {
            int prev = GetSlot(&t->m9C->mC0, k);
            fn_80205450(t->m9C, a);
            fn_801EE6F4(t, prev);
            fn_801EEFA8(t, a);
            fn_80213988(t, k, 1);
            fn_80205450(t->m9C, prev);
            fn_802123D4(t, 1, 1);
            fn_8021AA44(t, k, a);
        }
    }
}

/* Object in TaskInner::m8[] whose position (a Vec3f) sits at +0x60 (fn_80225488). */
struct Unk80225488_Obj {
    char pad0[0x60];
    Vec3f m60;
};
Vec3f fn_801F492C(Task* s, Vec3f* pos, int c, float f);
int fn_8020CDA0(void* p, Vec3f* v);
inline Vec3f Unk80225488_Flat(Unk80225488_Obj* o)
{
    Vec3f v = o->m60;
    v.y = 0.0f;
    return v;
}
inline float Unk80225488_Len2(const Vec3f& a, const Vec3f& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.z - b.z) * (a.z - b.z);
}
int fn_80225488(Task* t, int idx, Vec3f* out)
{
    Unk80225488_Obj* o = (Unk80225488_Obj*)t->m9C->m8[idx];
    Vec3f b = Unk80225488_Flat(o);
    *out = b;
    if (fn_8020CDA0((char*)t->m9C + 0x2C, out) == 0) {
        *out = fn_801F492C(t, out, (int)out, 168.0f);
    }
    const float lim = 576.0f;
    return Unk80225488_Len2(b, *out) > lim;
}

int fn_8022559C(Task* t)
{
    if (fn_8026DAE8(t->m9C->m8[0], 0) != 0) {
        fn_80205450(t->m9C, 0);
        fn_802123D4(t, 0, 0);
        fn_80213B80(t, 3, 2, 3);
        return 1;
    }
    return 0;
}

int fn_80225614(Task* t, int a)
{
    TaskInner* in = t->m9C;
    Obj4_36C* c = in->m0->m6CC;
    Obj36C* o = c->m374;
    if (c->m36C == 0 && o != 0) {
        int v = fn_80211BB0(&in->mC0, o->m460);
        fn_80205450(t->m9C, a);
        if (fn_802055F4(t->m9C) == 1 && (v != 3 || fn_801F0F30(t) == -1)) {
            fn_802123D4(t, 0, 0);
            fn_8022A71C(t, v, c->m378);
            fn_8021D4A4(t);
            return 1;
        }
    }
    return 0;
}

void fn_802258FC(Task* t)
{
    TaskInner* in = t->m9C;
    Obj3A64* o = in->m3A64;
    Obj4_36C* c = in->m0->m6CC;
    int ok = 0;
    if (c->m36C != 0) {
        t->mB8 = 0;
        ok = fn_801E817C(o, c->m36C->m460) == 0;
    }
    if (ok) {
        fn_802278F4(t);
    }
}

}

struct U;
extern "C++" { void fn_8035B7B0(U* p); }

struct Ent80226BC0 {
    int idx;
    float d;
    int pad8;
    Ent80226BC0() { fn_8035B7B0((U*)this); }
};

extern "C" {

int fn_801E816C(Obj3A64* p, int a);
int fn_801E82CC(Obj3A64* p, int a);
int fn_80226E28(Task* t, Ent80226BC0* arr, int n, int one, float f);
extern const float lbl_805D64E8;

/* near-miss 98.1%: same instructions; only the scratch registers of the id*4 / id*0x5C temporaries differ
   (retail slwi r11 / mulli r10, ours slwi r0 / mulli r11). Tried q-before-p, idx store first, typed obj, offset locals. */
int fn_80226BC0(Task* t)
{
    Ent80226BC0 arr[9];
    int n = 0;
    int i = 0;
    Obj3A64* o = t->m9C->m3A64;
    int n1 = o->m794;
    if (i < n1) {
        do {
            int id = fn_801E82CC(o, i);
            i++;
            TaskInner* in = t->m9C;
            PosObj* obj = (PosObj*)in->m8[id];
            arr[n].idx = id;
            Vec3f p = obj->m60;
            Vec3f q = *(Vec3f*)((char*)&in->m6D0[id] + 0x20);
            Vec3f d = p - q;
            arr[n].d = d.x * d.x + d.z * d.z;
            n++;
        } while (i < n1);
    }
    int n2 = o->m798;
    i = 0;
    if (i < n2) {
        do {
            int id = fn_801E816C(o, i);
            i++;
            TaskInner* in = t->m9C;
            PosObj* obj = (PosObj*)in->m8[id];
            arr[n].idx = id;
            Vec3f p = obj->m60;
            Vec3f q = *(Vec3f*)((char*)&in->m6D0[id] + 0x20);
            Vec3f d = p - q;
            arr[n].d = d.x * d.x + d.z * d.z;
            n++;
        } while (i < n2);
    }
    return fn_80226E28(t, arr, n, 1, lbl_805D64E8) == -1 ? 0 : 1;
}

}
