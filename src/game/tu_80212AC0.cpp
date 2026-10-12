/*
 * Game code, .text 0x80212AC0-0x80216CF4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

struct Obj4_390 : Obj4_36C {
    int m390;
};

struct Unk8026C414_O;
struct Unk8026C414_X;
int fn_8026DC5C(Unk8026C414_O* self, Unk8026C414_X* ctx);
int fn_8026DA60(Unk8026C414_O* self, Unk8026C414_X* ctx);
int fn_8026D7E0(Unk8026C414_O* self, Unk8026C414_X* ctx);

struct Unk8021646C_Obj {
    char pad0[0x458];
    int m458;
};
extern "C" void fn_8023CAF0__Fv(Player* p);
extern const float lbl_805D5E04;
extern const float lbl_805D5E08;
extern const float lbl_805D5E0C;
extern const float lbl_805D5E10;
extern float lbl_8061D560;
struct Unk80256C80_M;
Player* fn_80257B40(Unk80256C80_M* list);
extern "C" int fn_802055F4(TaskInner* in);
struct Unk80216590_O838 {
    char pad0[0x838];
    int m838;
};
struct Unk80216590_P : Unk8021646C_Obj {
    char pad45C[0x618 - 0x45C];
    Unk80216590_O838* m618;
};
extern const Vec3f lbl_805D6790;
int fn_8026D9D0(Unk8026C414_O* self, Unk8026C414_X* ctx);
inline float Secs80214F1C(unsigned n)
{
    return (float)n * 0.016666668f;
}
extern "C" {
void fn_80213988(Task* t, int x, int y);
void fn_80213B80(Task* t, int a, int b, int c);
void fn_8021354C(Task* t, int a, int b);
void fn_80214F1C(Task* t, int a, int b, float f);
int fn_801A9D9C(void* p, int x);
int fn_802142C8(Task* t, int a);
int fn_801F0E78(Task* t);
void fn_80219B8C(Task* t, int x);
void fn_80219EB0(Task* t);
void fn_80213DF4(Task* t, int x);
void fn_80213E30(Task* t, int x);
void fn_80213E84(Task* t, int x);
int fn_8026D8BC(void* o, int x);
int fn_8026DB3C(void* o, int x);
int fn_80217C04(Task* t, void* o, Player* p);
}

struct TaskInnerAC {
    char pad0[0xAC];
    Vec3f mAC;
};

extern "C" float fn_804028E4(float x); /* square root */
extern const Vec3f lbl_805D6760[];
extern float lbl_805D5D80;

inline float Len2138AC(Vec3f v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

extern "C" {

void fn_802138AC(Task* t, int a, int b, float f)
{
    TaskInner* in = t->m9C;
    Player* pl = (Player*)in->m8[in->m3A5C];
    float dist = Len2138AC(((PosObj*)pl)->m60 - ((TaskInnerAC*)in)->mAC);
    if (!(dist >= f))
        fn_8021354C(t, a, b);
}

struct TaskInner64 {
    char pad0[0x64];
    int m64;
};

struct TaskInnerD {
    char pad0[0x4];
    Obj4_36C* m4;
};

extern const float lbl_805D5D60;
extern const float lbl_805D5D64;
extern int lbl_8061CB80;
extern "C" int fn_8018B648(Obj4_36C* o);
extern "C" void fn_80204CCC(Rec* r);
extern "C" void fn_80224228(Task* t, int a, Rec* e);
extern const Vec3f lbl_806055DC;

inline void PutI3988(Slots4* s, int i, int v)
{
    int o = i * 4;
    *(int*)((char*)s + o) = v;
}

void fn_80213988(Task* t, int x, int mode)
{
    TaskInner* in = t->m9C;
    Obj4_36C* o4 = in->m4;
    if (((unsigned)(in->m30 - 5) <= 1 || fn_8018B648(o4) != 0) && lbl_8061CB80 == 0 && ((TaskInner64*)t->m9C)->m64 == 1) {
        fn_80214F1C(t, 1, 2, lbl_805D5D60);
        return;
    }
    TaskInner* b = t->m9C;
    int idx = b->m3A5C;
    Rec16* r16 = (Rec16*)((char*)b + (idx * 16 + 0x9F4));
    int k = 0;
    if (mode == 1)
        PutI3988(&b->mC0, x, idx);
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = k; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 0x21;
    e->m0 = 0x10;
    e->m9C = 1;
    e->m38 = lbl_806055DC;
    e->m80 = lbl_805D5D60;
    e->mC = 2;
    e->m1C = x;
    if (k == 1)
        e->m8 = k;
    else
        e->m8 = 3;
    e->m10 = 0xB;
    e->m94 = 1;
    e->m20 = 0;
    e->m24 = 0;
    e->m50 = lbl_806055DC;
    e->m8C = lbl_805D5D64;
    r16->m0 = x;
    r16->mC = 0;
    fn_80224228(t, t->m9C->m3A5C, e);
}

extern const float lbl_805D5D68;
extern "C" int fn_80259330(void* l);
extern "C" int fn_801EF308(Task* t, int a, int b);
extern "C" void fn_801EE6F4(Task* t, int a);
extern "C" void fn_801F0EA8(Task* t, int a);
extern "C" void fn_8021D4A4(Task* t);
extern "C" void fn_80205450(TaskInner* g, int i);
extern "C" void fn_80224630(Task* t, int a, Rec* e);

inline void PutI3B80(Slots4* s, int i, int v)
{
    int o = i * 4;
    *(int*)((char*)s + o) = v;
}

/* near-miss (2 insns over, registers/CSE): the whole record push matches fn_80213988's shape; retail re-forms &in->mD4 for the
   second GetSlot (ours reuses the first address) and keeps `in` in r10 */
void fn_80213B80(Task* t, int a, int b, int c)
{
    TaskInner* in = t->m9C;
    if ((unsigned)(in->m30 - 5) <= 1 && ((TaskInner64*)in)->m64 == 1) {
        fn_80214F1C(t, 1, 2, lbl_805D5D68);
        return;
    }
    if (GetSlot(&in->mD4, a) != -1 && GetSlot(&in->mD4, a) != in->m3A5C) {
        fn_8021D4A4(t);
        return;
    }
    if (a == 1 && fn_80259330(t->m9C->m0->m700->m3B4) == 0) {
        fn_8021D4A4(t);
        return;
    }
    if (fn_801EF308(t, a, t->m9C->m3A5C) == 1) {
        fn_80211BA0(&t->m9C->mC0, a);
        fn_80205450(t->m9C, t->m9C->m3A5C);
        fn_801EE6F4(t, t->m9C->m3A5C);
        fn_801F0EA8(t, t->m9C->m3A5C);
        fn_80213988(t, a, 1);
        return;
    }
    TaskInner* d = t->m9C;
    RecQueue* q = d->m3A60;
    Rec16* r16 = (Rec16*)((char*)d + (d->m3A5C * 16 + 0x9F4));
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
    e->m4 = 0x22;
    e->m0 = 0x11;
    e->mC = c;
    e->m8 = b;
    e->m9C = 1;
    e->m10 = 1;
    e->m1C = a;
    e->m38 = lbl_806055DC;
    e->m50 = lbl_806055DC;
    e->m94 = 1;
    e->m80 = lbl_805D5D68;
    e->m88 = lbl_805D5D68;
    PutI3B80(&t->m9C->mD4, a, t->m9C->m3A5C);
    r16->mC = 0;
    r16->m0 = a;
    fn_80224630(t, t->m9C->m3A5C, e);
}

void fn_80213DF4(Task* t, int x)
{
    t->m9C->m9FC[t->m9C->m3A5C].m0 = 1;
    fn_80213988(t, x, 1);
}

void fn_80213E30(Task* t, int x)
{
    t->m9C->m9FC[t->m9C->m3A5C].m0 = 1;
    t->m9C->mC0.m[x] = t->m9C->m3A5C;
    fn_80213988(t, x, 1);
}

void fn_80213E84(Task* t, int x)
{
    t->m9C->mD4.m[x] = t->m9C->m3A5C;
    if (fn_80210FC4((Sub*)&t->m9C, 5, x, 0) == 1) {
        fn_80213B80(t, x, 2, 3);
    } else {
        fn_80214F1C(t, 1, 2, -1.0f);
    }
}

void fn_80213F10(Task* t, int x)
{
    TaskInner* in = t->m9C;
    int v = GetSlot(&in->mC0, x);
    if (v == -1) {
        v = fn_801A9D9C(in->m0->m700->m3C4, x);
    }
    if (t->m9C->m3A5C == v) {
        fn_80213DF4(t, x);
    } else {
        fn_80213B80(t, x, 2, 3);
    }
}

void fn_80213FAC(Task* t, int x)
{
    TaskInner* in = t->m9C;
    int v = GetSlot(&in->mC0, x);
    if (v == -1) {
        v = fn_801A9D9C(in->m0->m700->m3C4, x);
    }
    if (t->m9C->m3A5C == v) {
        fn_80213E30(t, x);
    } else {
        fn_80213E84(t, x);
    }
}

extern const float lbl_805D5D78;
extern const float lbl_805D5D7C;

/* near-miss: 23 slots (9 out of order): all slots, frame and temps match; retail has no store in the else arm of the l2
   select (both arms leave the value in f0 and share one stfs), ours stores per arm with different registers */
inline float LenXZ42C8(Vec3f v)
{
    return v.x * v.x + v.z * v.z;
}

int fn_802142C8(Task* t, int k)
{
    float hi = lbl_805D5D78;
    float lo = lbl_805D5D7C;
    int m = t->m9C->m3A5C;
    if (m != 0 && m != 2) {
        if (k == 0)
            return 0;
        int c = fn_801F0E78(t) != -1;
        if (c)
            return 1;
        float l = LenXZ42C8(((TaskInnerAC*)t->m9C)->mAC - lbl_805D6760[k]);
        float l2 = k == 3 ? l : LenXZ42C8(((TaskInnerAC*)t->m9C)->mAC - lbl_805D6760[3]);
        if (!(l2 <= lbl_805D5D7C)) {
            if (l > lbl_805D5D78)
                return 1;
        }
    }
    return 0;
}

/* near-miss: logic and Vec3 temps match; retail reloads lbl_805D5D80 with its own lis after the call (the unused
   float local only stores it), ours shares the lis/lfs across the call in callee-saved r30 and the frame differs */
int fn_8021446C(Task* t, int k)
{
    if (t->m9C->m3A5C == 2 && k == 3) {
        float f = lbl_805D5D80;
        if (fn_80210FC4((Sub*)&t->m9C, 3, 2, 0) != 0) {
            TaskInner* in = t->m9C;
            Obj4_36C* g = in->m0->m6CC;
            if (g->m36C == 0 || g->m38C == 1) {
                Vec3f d = ((TaskInnerAC*)in)->mAC - lbl_805D6760[k];
                float d2 = d.x * d.x + d.z * d.z;
                return d2 > lbl_805D5D80;
            }
        }
    }
    return 0;
}

void fn_8021458C(Task* t, int a, int b)
{
    if (fn_802142C8(t, a) == 1 && fn_801F0E78(t) == -1) {
        fn_80219B8C(t, a);
    } else if (b != -1) {
        fn_80213B80(t, b, 2, 3);
    } else {
        fn_80214F1C(t, 1, 2, -1.0f);
    }
}

void fn_80214620(Task* t)
{
    t->m9C->mC0.m[0] = t->m9C->m3A5C;
    fn_80219EB0(t);
}

void fn_80214B10(Task* t, int a, int b)
{
    Vec3f arr[3] = { { 1860.0f, 0.0f, 120.0f }, { 1860.0f, 0.0f, 1860.0f }, { 120.0f, 0.0f, 1860.0f } };
    fn_80212550(t, &arr[t->m9C->m3A5C - 6], -1.0f, -1.0f, a, b);
    fn_80214F1C(t, 1, 2, -1.0f);
}

void fn_80214BE8(Task* t, int a, int b)
{
    Vec3f v = { 2496.0f, 0.0f, 108.0f };
    fn_80212550(t, &v, -1.0f, -1.0f, a, b);
    fn_80214F1C(t, 1, 2, -1.0f);
}

void fn_80214C68(Task* t, int a, int b)
{
    Vec3f v = { 84.0f, 0.0f, 2388.0f };
    fn_80212550(t, &v, -1.0f, -1.0f, a, b);
    fn_80214F1C(t, 1, 2, -1.0f);
}

struct Own4C {
    char pad0[0x4C];
    unsigned int m4C;
};
extern const float lbl_805D5DDC;
extern const float lbl_805D5DE8;

/* near-miss: 26 slots: body, frame and store order match; register numbering is shifted by one (retail keeps the constant 1
   in r4 and the record pointer in r5) and the 2^52 conversion literal is loaded after lbl_805D5DE8 instead of before it */
void fn_80214CE8(Task* t, int sel, Vec3f* pos, int a, int b, float f)
{
    if (!(f <= lbl_805D5DDC)) {
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
        e->m0 = 1;
        e->mC = b;
        e->m8 = a;
        e->m80 = (float)((Own4C*)t->m9C->m0)->m4C * lbl_805D5DE8 + f;
        TaskInner* in = t->m9C;
        PosObj* pl = (PosObj*)in->m8[in->m3A5C];
        if (sel == 1) {
            Vec3f d = ((PosObj*)in->m4)->m60 - pl->m60;
            e->m50 = d;
            e->m50.y = lbl_805D5DDC;
            e->m94 = 1;
        } else if (pos != 0) {
            Vec3f d = *pos - pl->m60;
            e->m50 = d;
            e->m50.y = lbl_805D5DDC;
            e->m94 = 1;
        }
    }
}

extern const float lbl_805D5E00;
extern const Vec3f lbl_8068C7F0;

void fn_80214F1C(Task* t, int a, int b, float f)
{
    TaskInner* in = t->m9C;
    RecQueue* q = in->m3A60;
    Obj4_36C* g = in->m4;
    Player* pl = (Player*)ObjAt(in->m8, in->m3A5C);
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
    e->m0 = 0x17;
    e->m9C = 1;
    if (!(f <= 0.0f))
        e->m80 = Secs80214F1C(t->m9C->m0->m4C) + f;
    else
        e->m80 = -1.0f;
    e->mC = b;
    e->m8 = a;
    e->m94 = 1;
    Obj36C* o = g->m36C;
    if ((Player*)o == pl) {
        e->m50 = lbl_806055AC - lbl_805D6790;
    } else if (o != 0) {
        if (fn_8026D9D0((Unk8026C414_O*)o, 0) == 1) {
            Obj36C* o2 = *(Obj36C**)((char*)o + 0x918);
            if (o2 != 0)
                e->m50 = o2->m60 - ((PosObj*)pl)->m60;
        }
    } else {
        e->m50 = ((PosObj*)g)->m60 - ((PosObj*)pl)->m60;
    }
    e->m50.y = 0.0f;
}

void fn_802151D0(Task* t)
{
    TaskInner* in = t->m9C;
    if ((unsigned)(in->m30 - 5) <= 1 && ((TaskInner64*)in)->m64 == 1) {
        fn_80214F1C(t, 1, 2, lbl_805D5E00);
        return;
    }
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
    e->m4 = 1;
    e->m0 = 0x20;
    e->m80 = lbl_805D5E00;
    e->m9C = 1;
    e->m94 = 1;
    e->m50 = lbl_8068C7F0;
}

extern const float lbl_805D5E28;
extern const float lbl_805D5E2C;

void fn_802152E0(Task* t, int a, int b, int c)
{
    TaskInner* in = t->m9C;
    if ((unsigned)(in->m30 - 5) <= 1 && in->m64 == 1) {
        fn_80214F1C(t, 1, 2, lbl_805D5E04);
        return;
    }
    RecQueue* q = in->m3A60;
    Obj4_36C* g = in->m4;
    Player* pl = (Player*)in->m8[in->m3A5C];
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    const Vec3f& pos = ((PosObj*)pl)->m60;
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m0 = 6;
    e->m80 = lbl_805D5E04;
    e->m4 = 0xB;
    e->mC = b;
    e->m8C = lbl_805D5E08;
    e->m8 = a;
    e->m9C = 1;
    e->m38 = pos;
    e->m44 = pos;
    fn_8023CAF0__Fv(pl);
    e->m20 = c;
    e->m24 = 1;
    e->m44.y = lbl_8061D560 * lbl_805D5E0C;
    e->m94 = 1;
    if (g->m36C != 0) {
        e->m50 = g->m36C->m60 - pos;
    } else {
        e->m50 = *(Vec3f*)((char*)g + 0x60) - pos;
    }
    e->m50.y = lbl_805D5E10;
    e->m84 = lbl_805D5E04;
}

void fn_80215540(Task* t, Vec3f* pos, int a, int b, int c)
{
    TaskInner* in = t->m9C;
    RecQueue* q = in->m3A60;
    PosObj* pl = (PosObj*)in->m8[in->m3A5C];
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
    e->m0 = 0x23;
    e->m80 = lbl_805D5E28;
    e->m4 = 0xC;
    e->mC = c;
    e->m8 = b;
    e->m1C = a;
    e->m9C = 1;
    e->m8C = lbl_805D5E2C;
    e->m24 = 1;
    e->m38 = *pos;
    e->m38.y = lbl_805D5E2C;
    e->m44 = *pos;
    e->m94 = 1;
    Vec3f d = *pos - pl->m60;
    e->m50 = d;
    e->m50.y = lbl_805D5E2C;
    e->m90 = lbl_805D5E2C;
}

extern const float lbl_805D5E30;
extern const float lbl_805D5E34;

void fn_802156DC(Task* t, Vec3f* pos, int a, int b, int c)
{
    TaskInner* in = t->m9C;
    RecQueue* q = in->m3A60;
    PosObj* pl = (PosObj*)in->m8[in->m3A5C];
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
    e->m0 = 0x24;
    e->m80 = lbl_805D5E30;
    e->m4 = 0xD;
    e->mC = c;
    e->m8 = b;
    e->m1C = a;
    e->m9C = 1;
    e->m8C = lbl_805D5E34;
    e->m24 = 1;
    e->m38 = *pos;
    e->m38.y = lbl_805D5E34;
    e->m44 = *pos;
    e->m94 = 1;
    Vec3f d = *pos - pl->m60;
    e->m50 = d;
    e->m50.y = lbl_805D5E34;
    e->m90 = lbl_805D5E34;
}

struct Own6F4 {
    char pad0[0x6F4];
    int m6F4;
};
extern const float lbl_805D5E64;
extern const float lbl_805D5E68;
extern const Vec3f lbl_805D6784;

/* squared distance; the operator- temp slot is reused across calls only when the subtraction lives inside an inline
   body with a local Vec3f (fn_80215D28, fn_80216014) */
inline float DistSq5D28(const Vec3f& a, const Vec3f& b)
{
    Vec3f d = a - b;
    return d.x * d.x + d.y * d.y + d.z * d.z;
}

int fn_80215D28(Task* t, PosObj* p, Vec3f* q)
{
    if (((Own6F4*)t->m9C->m0)->m6F4 != 9) {
        float thr = lbl_805D5E64;
        Vec3f pos = p->m60;
        float l = DistSq5D28(lbl_805D6784, pos);
        if (!(l < lbl_805D5E64)) {
            float l2 = DistSq5D28(*q, pos);
            float thr2 = lbl_805D5E68;
            if (l2 > lbl_805D5E68)
                return 2;
            return 1;
        }
    }
    return 0;
}

int fn_80215E6C(void*, Unk8026C414_O* o)
{
    return fn_8026DC5C(o, 0);
}

/* near-miss: best variant is 22 slots off: retail stores both float constants to locals and selects the third from registers */
extern const float lbl_805D5E6C;
extern const float lbl_805D5E70;

int fn_80215E94(void*, PosObj* a, Vec3f* b, int flag)
{
    Vec3f pa = a->m60;
    Vec3f pb = *b;
    float k1 = lbl_805D5E6C;
    float k2 = lbl_805D5E70;
    float th;
    if (flag == 1) {
        th = lbl_805D5E70;
    } else {
        th = lbl_805D5E6C;
    }
    float d2 = (pb.x - pa.x) * (pb.x - pa.x) + (pb.z - pa.z) * (pb.z - pa.z);
    return d2 < th;
}

/* near-miss: 2 slots: retail emits li r4,0 before mr r3,r30 for the first fn_8026D8BC call */
int fn_80215F40(Task* t, void* obj, int, int, int k, int* out)
{
    *out = 0;
    Player* p = t->m9C->m0->m684;
    if (p == 0 || p->m58C.m8 != 0.0f || (unsigned)(k - 1) > 1) {
        return 0;
    }
    fn_8026D8BC(obj, 0);
    if (fn_8026DB3C(obj, 0) == 1 && fn_80217C04(t, obj, p) == 0x17) {
        *out = 4;
    } else if (k == 1) {
        *out = k;
    } else {
        *out = 2;
    }
    return 1;
}

extern const float lbl_805D5E78;

int fn_80216014(void*, PosObj* o, Vec3f* q, int a, int b, int c, int mode)
{
    if (mode != 1 && a == 0 && (b != 0 || c == 0)) {
        Vec3f pos = o->m60;
        Vec3f qq = *q;
        float thr = lbl_805D5E78;
        if (fn_8026DA60((Unk8026C414_O*)o, 0) != 0)
            return DistSq5D28(qq, pos) <= lbl_805D5E78;
    }
    return 0;
}

struct Unk80270BA0_X;
class Unk80279BB8 {
public:
    Unk80279BB8();
    void fn_80279DD0(Unk80270BA0_X* x);
    char pad0[0xDC];
};
struct Unk80271DBC_Link {
    char pad0[0x838];
    int m838;
};
struct Own6134 {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x458 - 0x6C];
    int m458;
    char pad45C[4];
    int m460;
    char pad464[0x618 - 0x464];
    Unk80271DBC_Link* m618;
};
extern const float lbl_805D5E7C;
extern const float lbl_805D5E80;
extern const float lbl_805D5E84;
extern const float lbl_805D5E88;
extern "C" int fn_80386110(Unk80271DBC_Link* link, Unk80279BB8* q, int a, int b, float* out, int c);

int fn_80216134(Task* t, Own6134* o, Vec3f* q, int a, int, int c)
{
    if (a != 0 || (c != 0 && o->m460 != 0))
        return 0;
    Unk80271DBC_Link* link = o->m618;
    int h = link->m838;
    Vec3f pos = o->m60;
    Vec3f qq = *q;
    if (fn_8026D7E0((Unk8026C414_O*)o, 0) == 0 || ((PosObj*)t->m9C->m0->m6CC)->m60.y > lbl_805D5E7C)
        return 0;
    float l = DistSq5D28(qq, pos);
    float thr = lbl_805D5E80;
    float thr2 = lbl_805D5E84;
    if (l > lbl_805D5E80 || (o->m458 == 0 && !(l <= lbl_805D5E84)))
        return 0;
    float fl = lbl_805D5E88;
    Unk80279BB8 qy;
    qy.fn_80279DD0((Unk80270BA0_X*)o);
    if (!(fn_80386110(link, &qy, h, 0xFF18E0CC, &fl, 0) & 0x10000))
        return 0;
    return 1;
}

/* near-miss: 24 slots: retail lays out the return-0 block right after the flag/kind tests (beq to the body), ours puts it last */
int fn_802162F0(Task* t, Player* pl, int flag)
{
    int k = pl->m460;
    if (flag == 1 || (k != 5 && k != 3))
        return 0;
    if (fn_80211BB0(&t->m9C->mC0, k) != -1)
        return 0;
    Obj4_390* g = (Obj4_390*)pl->m44C->m6CC;
    if ((Player*)g->m36C == pl) {
        if (g->m390 != 3)
            return 0;
    } else {
        if (g->m38C != 3)
            return 0;
        if ((Player*)g->m374 != pl)
            return 0;
    }
    return 1;
}

struct Unk8021638C_Tbl {
    int m[12];
};
extern Unk8021638C_Tbl lbl_805D5E8C;

/* near-miss: 39 slots: table copy loop matches; retail keeps r4 free of temporaries, has an explicit i = 0 in case 2 (not
   folded away) and lays the second compare chain out differently */
int fn_8021638C(void*, void*, int a2, int a3, int a4)
{
    Unk8021638C_Tbl t = lbl_805D5E8C;
    int k = a4 == 1;
    int i = 0;
    int j = 0;
    switch (a3) {
    case 2:
        i = 0;
        break;
    case 1:
        i = 1;
        break;
    case 0:
        i = 2;
        break;
    default:
        i = 0;
        break;
    }
    switch (a2) {
    case 0:
        j = 0;
        break;
    case 1:
        j = 1;
        break;
    default:
        j = 0;
        break;
    }
    return *(int*)((char*)&t + (k * 4 + i * 8 + j * 0x18));
}

struct TaskInner70 {
    char pad0[0x70];
    int m70;
};
extern const float lbl_805D5F04;
extern const float lbl_805D5F08;
struct Unk80270BA0_X;
int fn_8024D434(Unk80270BA0_X* x);
extern "C" int fn_80254EA4(PlayerSub* p, int a);
extern "C" void fn_801F0F30(Task* t);

/* near-miss: 37 slots, 4 insns out of place: everything but the first block matches; retail keeps "li r3,8; b" inside
   the bne-skipped block, ours hoists the li above the branch (tried if/else, goto, result var, ternary, operand swap) */
extern "C" int fn_8021646C(void* self, Unk8021646C_Obj* o, int a, int b, int c)
{
    int t[3][3][2] = {
        { { 5, 3 }, { 4, 2 }, { 8, 6 } },
        { { 5, 3 }, { 4, 2 }, { 9, 7 } },
        { { 5, 5 }, { 4, 4 }, { 9, 9 } },
    };
    int f = c == 1;
    int bi = 0;
    int ai = 0;
    switch (b) {
    case 2:
        bi = 0;
        break;
    case 1:
        bi = 1;
        break;
    case 0:
        bi = 2;
        break;
    }
    switch (a) {
    case 0:
        ai = 0;
        break;
    case 1:
        ai = 1;
        break;
    case 2:
        ai = 2;
        break;
    }
    int r = t[ai][bi][f];
    int k = o->m458;
    if (k == 0 && r == 6)
        r = 7;
    if (k == 1 && r == 8)
        r = 9;
    return r;
}

int fn_80216590(Task* t, Unk80216590_P* pl, Vec3f v, int a, int b, int c)
{
    int sp18 = 0;
    int r = 1;
    if ((unsigned)(c - 10) <= 1) {
        int f = c == 11;
        Player* o = fn_80257B40((Unk80256C80_M*)t->m9C->m0->m700->m3B4);
        if (o == 0 || ((Unk8021646C_Obj*)o)->m458 == 9) {
            r = 9;
        } else if (a == 0) {
            r = 0x11;
            if (f == 1)
                r = 0x14;
        } else if (a == 1) {
            r = 0x13;
            if (f == 1)
                r = 0x16;
        } else {
            r = 0x12;
            if (f == 1)
                r = 0x15;
        }
    } else {
        if (c == 5) {
            r = 9;
            if (pl->m458 == 1 && pl->m618->m838 == -0x3C0481DF)
                r = 0x1B;
        } else if (c == 6) {
            r = 0x1E;
        } else if (c == 3) {
            r = 0x1C;
        } else if (c == 4) {
            r = 0x1D;
        }
    }
    if (r == 1) {
        int e = fn_802055F4(t->m9C) == 1;
        Vec3f w = v;
        int x = fn_80215D28(t, (PosObj*)pl, &w);
        int y = fn_80215E6C(t, (Unk8026C414_O*)pl);
        w = v;
        if (fn_80216014(t, (PosObj*)pl, &w, x, e, b, y) == 1)
            return 0xC;
        w = v;
        if (fn_80215E94(t, (PosObj*)pl, &w, y) == 1) {
            r = 0xA;
            if (y == 1)
                r = 0xB;
            return r;
        }
        if (fn_80215F40(t, pl, e, b, c, &sp18) == 1) {
            if (sp18 == 1)
                return 0x17;
            r = 0x18;
            if (sp18 == 4)
                r = 0x1A;
            return r;
        }
        w = v;
        r = 0xD;
        if (((int (*)(Task*, Own6134*, Vec3f*, int, int, int, int))fn_80216134)(t, (Own6134*)pl, &w, x, e, b, y) == 1)
            return r;
        if (fn_802162F0(t, (Player*)pl, y) == 1) {
            r = 9;
            if (b == 0)
                r = 8;
            return r;
        }
        if (e == 1)
            return fn_8021638C(t, pl, b, x, y);
        return fn_8021646C(t, pl, b, x, y);
    }
    return r;
}

int fn_8021693C(Task* t, Player* o, int x, Player* pl, int mode, float f1, float f2)
{
    if (x == -1) {
        if (fn_801F0E78(t) == o->m460)
            return 8;
        fn_801F0F30(t);
        return 1;
    }
    if (pl != 0) {
        int e = fn_80254EA4(&pl->m58C, 0) == x;
        float lo = lbl_805D5F04;
        float hi = lbl_805D5F08;
        float d = f2 - f1;
        if (!e && (mode == 0x1C || ((TaskInner70*)t->m9C)->m70 == 1)) {
            return fn_8024D434((Unk80270BA0_X*)pl) == 1 ? 4 : 6;
        } else if (!(d >= lbl_805D5F08)) {
            return e == 1 ? 3 : 4;
        } else if (!(d >= lbl_805D5F04)) {
            if (e == 1) {
                return x == 0 ? 2 : 3;
            }
            return 5;
        }
    }
    return 4;
}

void fn_802168B4(Task* t, PosObj* a, Vec3f* pos, int* out)
{
    int k = fn_80215E6C(t, (Unk8026C414_O*)a);
    Vec3f v = *pos;
    if (fn_80215E94(t, a, &v, k) == 1)
        *out = k == 1 ? 0xB : 0xA;
}

}
