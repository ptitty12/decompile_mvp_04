/*
 * Game code, .text 0x80212AC0-0x80216CF4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
void fn_80213988(Task* t, int x, int y);
void fn_80213B80(Task* t, int a, int b, int c);
void fn_80214F1C(Task* t, int a, int b, float f);
int fn_801A9D9C(void* p, int x);
int fn_802142C8(Task* t);
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

extern "C" {

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

/* near-miss: 5 slots: a/b swap r29/r30 (retail keeps a in r30, b in r29) */
void fn_8021458C(Task* t, int a, int b)
{
    if (fn_802142C8(t) == 1 && fn_801F0E78(t) == -1) {
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

/* near-miss: best variant is 22 slots off: retail stores both float constants to locals and selects the third from registers */
int fn_80215E94(void*, PosObj* a, Vec3f* b, int flag)
{
    Vec3f pa = a->m60;
    Vec3f pb = *b;
    float k1 = 90000.0f;
    float k2 = 129600.0f;
    float th;
    if (flag == 1) {
        th = k2;
    } else {
        th = k1;
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

}
