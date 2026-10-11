/*
 * Game code, .text 0x8007DB74-0x8007F198 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007DB74.h"

typedef Unk8007DB74_A A;
typedef Unk8007DB74_Rec Rec;
typedef Unk8007DB74_Tbl Tbl;
typedef Unk8007DB74_Vec Vec;

int fn_8059FFF8(void* p);
void fn_805A00BC(void* p);
int fn_805A19C8(Tbl* t);
int fn_805A1958(Rec* r, int a, int b, unsigned char c);
int fn_8053B6CC(Rec* r, int a);
int fn_8053CAE0(Rec* r);
int fn_8053CA58(Rec* r);
int fn_8053CA8C(Rec* r, int a);
int fn_8053CAD4(Rec* r, int a);
int fn_8053CB1C(Rec* r, int a);
int fn_8053CB94(Rec* r, int a, int b);
int fn_8053CBF8(Rec* r);
int fn_8053ACB8(Rec* r, int a);
int fn_8053CC28(Rec* r, int a);
int fn_8053AD1C(Rec* r, int a);
void fn_8053CC1C(Rec* r);

int fn_8007DDC8(A* self, int a, int group, int idx);
int fn_8007DDC8(A* self, int a, int group);
int fn_8007DEAC(A* self, int a, int group);
int fn_8007DF5C(A* self, int a, int group, int idx);
int fn_8007E0E4(A* self, int a, int group);

static inline Rec* Cur(Tbl* t)
{
    return &t->m10[fn_805A19C8(t)];
}

void fn_8007DB74(A* self, int v)
{
    self->m8->m1BC8 = v;
}

int fn_8007DB80(A* self)
{
    return self->m8->m1BC8;
}

void fn_8007DB8C(A* self)
{
    fn_805A00BC(self->m8);
}

int fn_8007DBB0(A* self)
{
    return self->m8->m0;
}

int fn_8007DBBC(A* self, int idx)
{
    Unk8007DB74_Arr* a = self->m8;
    if (idx >= 0 && idx < a->m0)
        return fn_8059FFF8(&a->m18[idx]);
    return 0;
}

/* near-miss: retail keeps i in a stack slot (stw/lwz at 8(r1)) with the
 * branchy clamp, calls fn_8007DDC8 with only three arguments (r6 left stale),
 * and no 4th argument is passed here. volatile i, int& helpers and two-field
 * structs were tried; none gives the same frame. */
int fn_8007DC08(A* self, int a, int target, int c, int* out)
{
    int i = 0;
    while (i < fn_8007DEAC(self, a, c)) {
        if (fn_8007DDC8(self, a, c, 0) == target) {
            *out = i;
            return 1;
        }
        i = (i > 9) ? i : i + 1;
    }
    return 0;
}

int fn_8007DCA8(A* self, int a, int target, int c, int* out)
{
    int n = fn_8007E0E4(self, a, c);
    for (*out = 0; *out < n; (*out)++) {
        if (fn_8007DF5C(self, a, c, *out) == target)
            return 1;
    }
    return 0;
}

void fn_8007DD38(A* self, int a, int b, int c, int d)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    if (d)
        fn_805A1958(r, b, c, fn_8053B6CC(r, d));
    else
        fn_805A1958(r, b, c, 0xFF);
}

/* near-miss: only the register choice of the loaded byte and the offset/base
 * temporaries differ. */
int fn_8007DDC8(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    if (idx == 0)
        return fn_8053CAE0(r);
    unsigned char v = r->mF0[group].b[idx];
    if (v != 0xFF)
        return r->m0[v];
    return 0;
}

unsigned char fn_8007DE50(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].mF0[group].b[idx];
}

int fn_8007DEAC(A* self, int a, int group)
{
    Cur(self->m58);
    return 10;
}

int fn_8007DED4(A* self, int a, int target, int c)
{
    int tmp;
    return fn_8007DC08(self, a, target, c, &tmp);
}

void fn_8007DEF8(A* self, int a, int group, int idx, int v)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    t->m10[i].mF0[group].w[idx] = v;
}

int fn_8007DF5C(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    int w = r->mF0[group].w[idx];
    if (w == 0)
        return fn_8053CAE0(r);
    unsigned char v = r->mF0[group].b[w];
    if (v != 0xFF)
        return r->m0[v];
    return 0;
}

unsigned char fn_8007DFF4(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    return r->mF0[group].b[r->mF0[group].w[idx]];
}

int fn_8007E060(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].mF0[group].w[idx];
}

int fn_8007E0C0(A* self, int a, int target, int c)
{
    int tmp;
    return fn_8007DCA8(self, a, target, c, &tmp);
}

int fn_8007E0E4(A* self, int a, int group)
{
    Cur(self->m58);
    return 9;
}

int fn_8007E10C(A* self)
{
    return fn_8053CA58(Cur(self->m58));
}

int fn_8007E154(A* self, int a, int x)
{
    return fn_8053CA8C(Cur(self->m58), x);
}

unsigned char fn_8007E1A4(A* self, int a, int x)
{
    return fn_8053CAD4(Cur(self->m58), x);
}

int fn_8007E1F8(A* self)
{
    return fn_8053CAE0(Cur(self->m58));
}

unsigned char fn_8007E240(A* self)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m14[t->m10[i].m20];
}

int fn_8007E290(A* self)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m20;
}

int fn_8007E2D8(A* self, int a, int target, int* out)
{
    for (*out = 0; *out <= 4; (*out)++) {
        if (fn_8007E154(self, a, *out) == target)
            return 1;
    }
    return 0;
}

int fn_8007E34C(A* self, int a, int x)
{
    return fn_8053CB1C(Cur(self->m58), x);
}

int fn_8007E39C(A* self, int a, int x, int y)
{
    return fn_8053CB94(Cur(self->m58), x, y);
}

int fn_8007E3F4(A* self)
{
    return fn_8053CBF8(Cur(self->m58));
}

int fn_8007E43C(A* self, int a, int x)
{
    return fn_8053ACB8(Cur(self->m58), x);
}

int fn_8007E48C(A* self, int a, int x)
{
    return fn_8053CC28(Cur(self->m58), x) != -1;
}

int fn_8007E4EC(A* self, int a, int x)
{
    return fn_8053AD1C(Cur(self->m58), x);
}

void fn_8007E53C(A* self)
{
    Tbl* t = self->m58;
    for (unsigned i = 0; i < t->mC; i++)
        fn_8053CC1C(&t->m10[i]);
}
int fn_805A18D8(Rec* r, unsigned char i);
int fn_805A18F0(Rec* r);
int fn_805A18F8(Rec* r, unsigned char i);
int fn_805A1910(Rec* r);
int fn_805A1918(Rec* r, unsigned char i);
int fn_805A1930(Rec* r);
int fn_805A1938(Rec* r, unsigned char i);
int fn_805A1950(Rec* r);
int fn_8007E814(A* self, int a, int val, int* out);
int fn_8007EB14(A* self, int a, int val, int* out);
int fn_8007EE14(A* self, int a, int val, int* out);
int fn_8007F114(A* self, int a, int val, int* out);

void fn_8007E598(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC(r, x);
    Vec* v = &r->m28[0];
    if (v->m4 < v->m8) {
        r->m28[0].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007E618(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A18F0(r); i++) {
        if (fn_805A18D8(r, i) == val) {
            Vec* v = &r->m28[0];
            if ((unsigned)i < v->m4) {
                unsigned j = i;
                do {
                    v->m0[j] = v->m0[j + 1];
                    j++;
                } while (j < v->m4);
                v->m4 = v->m4 - 1;
            }
            break;
        }
    }
}

void fn_8007E6D0(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC(r, val);
    Vec* v = &r->m28[0];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[0].m0[n] = b;
}

int fn_8007E74C(A* self, int a, int idx)
{
    Tbl* t = self->m58;
    unsigned char n = idx;
    int i = fn_805A19C8(t);
    int* p = t->m10[i].m0 + t->m10[i].m28[0].m0[n];
    return *p;
}

unsigned fn_8007E7A8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m28[0].m4;
}

int fn_8007E7F0(A* self, int a, int val)
{
    int tmp;
    return fn_8007E814(self, a, val, &tmp);
}

int fn_8007E814(A* self, int a, int val, int* out)
{
    for (*out = 0; *out < (int)fn_8007E7A8(self, a); (*out)++) {
        if (fn_8007E74C(self, a, *out) == val)
            return 1;
    }
    return 0;
}

void fn_8007E898(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC(r, x);
    Vec* v = &r->m28[1];
    if (v->m4 < v->m8) {
        r->m28[1].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007E918(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC(r, val);
    Vec* v = &r->m28[1];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[1].m0[n] = b;
}

void fn_8007E994(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A1910(r); i++) {
        if (fn_805A18F8(r, i) == val) {
            Vec* v = &r->m28[1];
            if ((unsigned)i < v->m4) {
                unsigned j = i;
                do {
                    v->m0[j] = v->m0[j + 1];
                    j++;
                } while (j < v->m4);
                v->m4 = v->m4 - 1;
            }
            break;
        }
    }
}

int fn_8007EA4C(A* self, int a, int idx)
{
    Tbl* t = self->m58;
    unsigned char n = idx;
    int i = fn_805A19C8(t);
    int* p = t->m10[i].m0 + t->m10[i].m28[1].m0[n];
    return *p;
}

unsigned fn_8007EAA8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m28[1].m4;
}

int fn_8007EAF0(A* self, int a, int val)
{
    int tmp;
    return fn_8007EB14(self, a, val, &tmp);
}

int fn_8007EB14(A* self, int a, int val, int* out)
{
    for (*out = 0; *out < (int)fn_8007EAA8(self, a); (*out)++) {
        if (fn_8007EA4C(self, a, *out) == val)
            return 1;
    }
    return 0;
}

void fn_8007EB98(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC(r, x);
    Vec* v = &r->m28[2];
    if (v->m4 < v->m8) {
        r->m28[2].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007EC18(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC(r, val);
    Vec* v = &r->m28[2];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[2].m0[n] = b;
}

void fn_8007EC94(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A1930(r); i++) {
        if (fn_805A1918(r, i) == val) {
            Vec* v = &r->m28[2];
            if ((unsigned)i < v->m4) {
                unsigned j = i;
                do {
                    v->m0[j] = v->m0[j + 1];
                    j++;
                } while (j < v->m4);
                v->m4 = v->m4 - 1;
            }
            break;
        }
    }
}

int fn_8007ED4C(A* self, int a, int idx)
{
    Tbl* t = self->m58;
    unsigned char n = idx;
    int i = fn_805A19C8(t);
    int* p = t->m10[i].m0 + t->m10[i].m28[2].m0[n];
    return *p;
}

unsigned fn_8007EDA8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m28[2].m4;
}

int fn_8007EDF0(A* self, int a, int val)
{
    int tmp;
    return fn_8007EE14(self, a, val, &tmp);
}

int fn_8007EE14(A* self, int a, int val, int* out)
{
    for (*out = 0; *out < (int)fn_8007EDA8(self, a); (*out)++) {
        if (fn_8007ED4C(self, a, *out) == val)
            return 1;
    }
    return 0;
}

void fn_8007EE98(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC(r, x);
    Vec* v = &r->m28[3];
    if (v->m4 < v->m8) {
        r->m28[3].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007EF18(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC(r, val);
    Vec* v = &r->m28[3];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[3].m0[n] = b;
}

void fn_8007EF94(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8(t);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A1950(r); i++) {
        if (fn_805A1938(r, i) == val) {
            Vec* v = &r->m28[3];
            if ((unsigned)i < v->m4) {
                unsigned j = i;
                do {
                    v->m0[j] = v->m0[j + 1];
                    j++;
                } while (j < v->m4);
                v->m4 = v->m4 - 1;
            }
            break;
        }
    }
}

int fn_8007F04C(A* self, int a, int idx)
{
    Tbl* t = self->m58;
    unsigned char n = idx;
    int i = fn_805A19C8(t);
    int* p = t->m10[i].m0 + t->m10[i].m28[3].m0[n];
    return *p;
}

unsigned fn_8007F0A8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8(t);
    return t->m10[i].m28[3].m4;
}

int fn_8007F0F0(A* self, int a, int val)
{
    int tmp;
    return fn_8007F114(self, a, val, &tmp);
}

int fn_8007F114(A* self, int a, int val, int* out)
{
    for (*out = 0; *out < (int)fn_8007F0A8(self, a); (*out)++) {
        if (fn_8007F04C(self, a, *out) == val)
            return 1;
    }
    return 0;
}
