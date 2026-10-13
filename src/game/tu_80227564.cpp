/*
 * Game code, .text 0x80227564-0x8022BB90 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
int fn_802055F4(TaskInner* in);
void fn_80205450(TaskInner* in, int x);
void fn_802123D4(Task* t, int kind, int x);
void fn_801E81C8(Obj3A64* p);
void fn_801E8068(Obj3A64* p);
void fn_801E80F0(Obj3A64* p, int id);
int fn_801E8C1C(Obj3A64* p, int a, int* b, int* c);
int fn_801E8EF4(Obj3A64* p, int a, int* c);
void fn_8022A438(Task* t, int a, int b);
void fn_8022A580(Task* t, int a);
void fn_80229948(Task* t, int a);
void fn_8022AB14(Task* t, int a, RecQueue* q);
float fn_80218DCC(Task* t, void* x, void* y, int d);
int fn_802280E0(Task* t, int a);
void* fn_802CB924(void* mem, CtxOwner* a);
char* fn_801A4CE8(CtxOwner* o, int k);
void fn_802CBD04(void* o, int x);
void fn_8022870C(Task* t, void* arr, int* n, void* obj);
int fn_802281D0(Task* t, int a, int b, int c);
int fn_801E816C(Obj3A64* p, int a);
int fn_801E82CC(Obj3A64* p, int a);
int fn_802283E0(Task* t, int a);
int fn_80205664(TaskInner* in);
int fn_801E8B80(Obj3A64* p);
int fn_80205644(TaskInner* in);
int fn_80227564(Task* t, int id, int flag);
int fn_80225970(Task* t, int* out);
int fn_801EE6F4(Task* t, int a);
void fn_801F0EA8(Task* t, int a);
void fn_8021354C(Task* t, int a, int b);
void fn_8021D4A4(Task* t);
void fn_801EDE78(Task* t, int x);
void fn_801EFC48(Task* t, int a);
void fn_801E8250(Obj3A64* p, int a);
void fn_80201864(Task* t);
int fn_8020CCFC(void* p, int a);
void fn_802296D0(Task* t, int a);
void fn_801EE6F4_(Task* t, int a);
int fn_8024D41C(void* x);
}

struct U;
struct Unk802CBD04;
void* fn_802CF168(void* o);
void fn_802CBDBC(Unk802CBD04* o, int a, int b, int kind);
void fn_8035EFD4(U* self, int chrg);

/* Entry table filled by fn_8022870C: 8-byte pairs, the pointer at +4 (an object whose id sits at +0x460). */
struct Unk802280E0_Ent {
    char pad0[0x460];
    int m460;
};
struct Unk802280E0_Pair {
    int a;
    Unk802280E0_Ent* p;
};

inline void SetE8(Task* t, float v)
{
    t->mE8 = v;
}

extern "C" {

extern int lbl_8061F8F8;
extern int lbl_8061B9C8;

/* near-miss: 131/131 insns, only the callee-saved pair swapped (retail: t in r30, sel in r31; ours t in r31, sel in r30).
   Tried a copy of sel and without the TaskInner local. */
int fn_80227564(Task* t, int sel, int flag)
{
    t->m9C->m6C = 1;
    if (fn_802055F4(t->m9C) == 0) {
        return 0;
    }
    TaskInner* in = t->m9C;
    if (in->m48 == 1) {
        if (in->mA8 == -1.0f) {
            return 0;
        }
    }
    if (in->m4->m36C != 0) {
        return 1;
    }
    if (sel == -1) {
        int tmp;
        sel = fn_80225970(t, &tmp);
        if (sel == -1) {
            sel = t->m9C->mA4;
            if (sel == -1) {
                sel = t->m9C->m3C;
                if (sel == -1) {
                    sel = 3;
                }
            }
        }
    }
    int old = t->m9C->mA4;
    fn_801E81C8(t->m9C->m3A64);
    fn_801E8068(t->m9C->m3A64);
    t->m9C->mA4 = sel;
    fn_801EFC48(t, sel);
    if (flag == 0) {
        fn_801E80F0(t->m9C->m3A64, sel);
        fn_80205450(t->m9C, sel);
        fn_802123D4(t, 0, 0);
        fn_802296D0(t, 0);
    } else {
        fn_801E8250(t->m9C->m3A64, sel);
        fn_80205450(t->m9C, sel);
        fn_802123D4(t, 0, 0);
        fn_80201864(t);
    }
    if (old != -1 && old != t->m9C->mA4) {
        fn_80205450(t->m9C, old);
        if (fn_8020CCFC((char*)t->m9C + 0x2C, old) == 1) {
            fn_801EE6F4(t, old);
            fn_801F0EA8(t, old);
            fn_802123D4(t, 1, 1);
            fn_8021354C(t, 3, 4);
        } else {
            fn_802123D4(t, 0, 0);
            fn_8021D4A4(t);
        }
    }
    fn_801EDE78(t, 0);
    return 1;
}

/* near-miss: 96/97 insns, one missing: retail presets li r3,0 before the m100 compare (the outer exit returns that r3) and
   has a second li r3,0 for the inner exits; ours folds them. Same preset-r3 family as fn_8006FB10 / fn_80236F34. */
int fn_80227770(Task* t)
{
    int id = -1;
    Obj3A64* o = t->m9C->m3A64;
    if (o->m798 > 0) {
        id = fn_801E816C(o, 0);
    } else if (o->m794 > 0) {
        id = fn_801E82CC(o, 0);
    }
    lbl_8061F8F8 = fn_802283E0(t, 0);
    t->m100 = t->m100 - (float)lbl_8061B9C8 * 0.016666668f;
    if (!(t->m100 > 0.0f)) {
        if (fn_802055F4(t->m9C) == 1) {
            int z = fn_80205664(t->m9C);
            if (z == 0) {
                if (fn_801E8B80(t->m9C->m3A64) != 0) {
                    t->m118 = z;
                    if (id != -1) {
                        id = lbl_8061F8F8;
                        if (id != -1) {
                            float k = 0.1f;
                            t->m104 = 2.0f;
                            t->m100 = 0.5f;
                            t->mE8 = k;
                            fn_80227564(t, id, (fn_80205644(t->m9C->m3A64->m9C) ^ 1) == 0);
                            t->m118 = z;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int fn_802278F4(Task* t)
{
    if (fn_802055F4(t->m9C) == 0) {
        return 0;
    }
    SetE8(t, -1.0f);
    t->m9C->m80 = 0;
    t->m9C->m40 = 0;
    int id = t->m9C->m4->m36C->m460;
    fn_801E81C8(t->m9C->m3A64);
    fn_801E8068(t->m9C->m3A64);
    fn_801E80F0(t->m9C->m3A64, id);
    return 1;
}

int fn_80227994(Task* t, int a)
{
    if (fn_802055F4(t->m9C) == 0) {
        return 0;
    }
    int id = t->m9C->m4->m36C->m460;
    fn_801E81C8(t->m9C->m3A64);
    fn_801E8068(t->m9C->m3A64);
    fn_801E80F0(t->m9C->m3A64, id);
    fn_80205450(t->m9C, id);
    fn_802123D4(t, 1, 1);
    fn_80229948(t, a);
    return 1;
}

int fn_80227A38(Task* t, int a)
{
    int s8 = -1;
    int r = 0;
    int sC = 0;
    if (fn_801E8C1C(t->m9C->m3A64, a, &s8, &sC) == 1) {
        r = 1;
        fn_80205450(t->m9C, a);
        fn_802123D4(t, 0, 0);
        fn_8022A438(t, s8, sC);
    } else if (fn_801E8EF4(t->m9C->m3A64, a, &sC) == 1) {
        r = 1;
        fn_80205450(t->m9C, a);
        fn_802123D4(t, 0, 0);
        fn_8022A580(t, sC);
    }
    return r;
}

int fn_802280E0(Task* t, int a)
{
    char obj[0x1E0];
    Unk802280E0_Pair arr[25];
    int n;
    fn_802CB924(obj, t->m9C->m0);
    char* c = fn_801A4CE8(t->m9C->m0, 1) + 0x128;
    if (c != 0) {
        fn_802CBDBC((Unk802CBD04*)obj, (int)fn_802CF168(c), 1, 0);
    }
    fn_802CBD04(obj, 1);
    n = 0;
    fn_8022870C(t, arr, &n, obj);
    for (int i = 0; i < n; i++) {
        if (arr[i].p->m460 == a) {
            fn_8035EFD4((U*)obj, 2);
            return 1;
        }
    }
    fn_8035EFD4((U*)obj, 2);
    return 0;
}

extern const float lbl_805D6558;
extern "C++" { void fn_8035B7B0(U* p); }
int fn_8021157C(CmpPos* a, CmpPos* b);
Vec3f fn_8018959C(Obj4_36C* o, float t);
int fn_801DC658(void* o, Vec3f* v, int k);
int fn_8024D408(void* p);
void qsort(void* a, unsigned n, unsigned es, int (*cmp)());

struct Ent802281D0 {
    int idx;
    float d;
    int pad8;
    Ent802281D0() { fn_8035B7B0((U*)this); }
};

inline float Id802281D0(float v)
{
    return v;
}

int fn_802281D0(Task* t, int a, int b, int c)
{
    Ent802281D0 arr[9];
    int n = 0;
    Vec3f ref = lbl_806055AC;
    int rr = fn_801DC658(*(void**)((char*)t->m9C->m0->m700 + 0x3B8), &ref, 0);
    Obj4_36C* o4 = t->m9C->m0->m6CC;
    if (rr == 0) {
        float f = lbl_805D6558; ref = fn_8018959C(o4, lbl_805D6558);
    }
    for (int k = 0; k <= 8; k++) {
        if (k == a)
            continue;
        TaskInner* in = t->m9C;
        int sel = in->m8C;
        void* o = in->m8[k];
        if (sel != 0 && in->m94 == 1 && sel == (int)o)
            continue;
        if (fn_8024D408(o) != 0 && b == 0)
            continue;
        if (c != 0 && fn_802280E0(t, k) == 0)
            continue;
        arr[n].idx = k;
        Vec3f p = ((PosObj*)o)->m60;
        Vec3f d = p - ref;
        arr[n].d = d.x * d.x + d.z * d.z;
        n++;
    }
    qsort(arr, n, 0xC, (int (*)())fn_8021157C);
    return arr[0].idx;
}

int fn_8022921C(Task* t, int a)
{
    int r = -1;
    if (t->mF8 == 0.0f) {
        if (fn_802280E0(t, a) == 0) {
            TaskInner* in = t->m9C;
            int v = in->m1D8;
            if (v > 1) {
                r = in->m1F4;
                if (v > 2 && a == 0 && r == 1 && in->m20C == 2) {
                    r = 2;
                }
            } else {
                r = fn_802281D0(t, a, 1, 1);
            }
        } else if (a == 0) {
            TaskInner* in = t->m9C;
            if (in->mCA8 != 0) {
                Rec* e = in->mCA8->e;
                if (e != 0 && e->mBC != 0 && in->m1D8 > 1) {
                    r = in->m1F4;
                }
            }
        }
    }
    return r;
}

int fn_80229304(Task* t)
{
    return t->mF8 >= 2.0f;
}

float fn_80229324(Task* t)
{
    return t->mF8;
}

void fn_80229948(Task* t, int a)
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
    e->m4 = 3;
    e->m0 = 0x2b;
    e->m9C = 1;
    e->mA8 = 1;
    e->m80 = -1.0f;
    if (a == 1) {
        fn_8022AB14(t, t->m9C->m3A5C, t->m9C->m3A60);
    }
}

struct Unk80229CB4_S {
    int m0;
    int m4;
    float m8;
    int mC;
    float m10;
    float m14;
    int m18;
    int m1C;
    int m20;
};
inline void Unk80229CB4_SetM8(Unk80229CB4_S* s, float v)
{
    s->m8 = v;
}
inline void Unk80229CB4_SetM10(Unk80229CB4_S* s, float v)
{
    s->m10 = v;
}
inline void Unk80229CB4_SetM14(Unk80229CB4_S* s, float v)
{
    s->m14 = v;
}
float fn_8020EE9C(Task* t, int a, Vec3f v, int b);
int fn_801F5DD8(Task* t, int b);
float fn_8020E074(Task* t, int a1, int a2, const Vec3f& v, int b, int c, int d);
float fn_802F9DD0(int p);
int* fn_8023CB08__Fv(int a);
void fn_8035D1D8__FP1Uf(Unk80229CB4_S* s, int a, float f);
extern float lbl_8061D600;
extern float lbl_8061D604;
void fn_80229CB4(Task* t, int a, int b, Vec3f* v)
{
    Unk80229CB4_S* s = (Unk80229CB4_S*)((char*)t + 0xC4);
    float ratio = fn_8020EE9C(t, a, *v, b);
    float val = 0.0f;
    int r = fn_801F5DD8(t, b);
    if (r == 1) {
        s->m20 = a;
        s->m4 = r;
        Unk80229CB4_SetM8(s, 0.0f);
        fn_8035D1D8__FP1Uf(s, a, 0.0f);
        val = 1.0f - fn_802F9DD0(*(int*)((char*)t->m9C->m0 + 0x720));
    } else {
        s->m20 = a;
        s->m4 = 1;
        Unk80229CB4_SetM8(s, 0.0f);
        fn_8035D1D8__FP1Uf(s, a, 0.0f);
        Unk80229CB4_SetM8(s, 0.01f);
        fn_8023CB08__Fv(a);
        float lo = lbl_8061D600;
        fn_8023CB08__Fv(a);
        float hi = lbl_8061D604;
        val = (hi - lo) * ratio + lo;
    }
    Unk80229CB4_SetM10(s, val);
    float d = fn_8020E074(t, (int)t->m9C->m0->m6CC, a, *v, b, 0, 0);
    Unk80229CB4_SetM14(s, d);
}

int fn_80229E50(Task* t, int a, int b, int c, int d)
{
    void* x = ObjAt(t->m9C->m8, a);
    void* y = ObjAt(t->m9C->m8, c);
    float f = fn_80218DCC(t, x, y, d);
    float k1 = 0.4f;
    float k2 = 0.85f;
    if (!(f >= 0.4f)) {
        if (fn_8024D41C(x) == 1) {
            return 2;
        }
    }
    return f <= 0.85f;
}

inline void SetSlot(Slots4* s, int x, int v)
{
    s->m[x] = v;
}
extern "C" Vec3f fn_801E73B8(Obj3A64* self, int k);
void fn_8022A438(Task* t, int a, int b)
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
    e->m4 = 0x2C;
    e->m0 = 0x2E;
    e->m9C = 1;
    e->m38 = fn_801E73B8(t->m9C->m3A64, a);
    e->m10 = 6;
    e->m28 = (Player*)b;
    e->m80 = -1.0f;
    e->mC = 4;
    e->m8 = 3;
    e->m1C = a;
    TaskInner* in = t->m9C;
    if (GetSlot(&in->mC0, a) == -1)
        SetSlot(&t->m9C->mC0, a, t->m9C->m3A5C);
}

void fn_801E8428(Obj3A64* p, int k, Vec3f* pos, float* ang);
struct Unk8022A580_Obj {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x928 - 0x6C];
    Player* m928;
};
void fn_8022A580(Task* t, int ai)
{
    Unk8022A580_Obj* a = (Unk8022A580_Obj*)ai;
    RecQueue* q = t->m9C->m3A60;
    Unk8022A580_Obj* cur = (Unk8022A580_Obj*)t->m9C->m8[t->m9C->m3A5C];
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
    cur->m928 = (Player*)a;
    Vec3f pos;
    float ang;
    fn_801E8428(t->m9C->m3A64, t->m9C->m3A5C, &pos, &ang);
    e->m4 = 0x2D;
    e->m0 = 0x2F;
    e->mC = 4;
    e->m8 = 3;
    e->m80 = -1.0f;
    e->m9C = 1;
    e->m28 = (Player*)a;
    e->m38 = pos;
    e->m8C = ang;
    const Vec3f* pa = &a->m60;
    const Vec3f* pc = &cur->m60;
    Vec3f d = *pa - *pc;
    e->m50 = d;
    e->m94 = 1;
    t->m9C->m60 = 0;
}

void fn_801E8250(Obj3A64* p, int a);
inline float Unk8022A934_Secs(unsigned n)
{
    return (float)n * 0.016666668f;
}
struct Unk8022A934_Obj {
    char pad0[0x60];
    Vec3f m60;
};
void fn_8022A934(Task* t, Vec3f* v, int a, int b)
{
    RecQueue* q = t->m9C->m3A60;
    Unk8022A934_Obj* cur = (Unk8022A934_Obj*)t->m9C->m8[t->m9C->m3A5C];
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
    *(int*)((char*)t->m9C + 0xA0) = 1;
    v->y = 0.0f;
    e->m4 = 0x2A;
    e->m0 = 0x31;
    e->mC = b;
    e->m8 = a;
    e->m9C = 1;
    const Vec3f* pc = &cur->m60;
    e->m38 = *v;
    e->m8C = 1.0f;
    e->m88 = -1.0f;
    e->m80 = -1.0f;
    e->m84 = Unk8022A934_Secs(t->m9C->m0->m4C);
    e->m94 = 1;
    Vec3f d = *v - *pc;
    e->m50 = d;
    fn_801E8250(t->m9C->m3A64, t->m9C->m3A5C);
}

void fn_8022AB04(Task* t)
{
    t->m9C->m30 = 6;
}

}
