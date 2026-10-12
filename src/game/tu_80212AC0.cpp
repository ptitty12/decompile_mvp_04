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
void fn_8026D8BC(void* o, int x);
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

/* near-miss: 5 slots: a/b swap r29/r30 (retail keeps a in r30, b in r29) */
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

void fn_802168B4(Task* t, PosObj* a, Vec3f* pos, int* out)
{
    int k = fn_80215E6C(t, (Unk8026C414_O*)a);
    Vec3f v = *pos;
    if (fn_80215E94(t, a, &v, k) == 1)
        *out = k == 1 ? 0xB : 0xA;
}

}
