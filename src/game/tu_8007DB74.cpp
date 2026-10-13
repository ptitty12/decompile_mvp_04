/*
 * Game code, .text 0x8007DB74-0x8007F198 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007DB74.h"
#include "game/db_8053967C.h"

typedef Unk8007DB74_A A;
typedef Unk8007DB74_Rec Rec;
typedef Unk8007DB74_Tbl Tbl;
typedef Unk8007DB74_Vec Vec;

struct A1A0;
struct Db805A0000_Holder;
struct Db805A19C8_Obj;
struct Db805A1958_Tab;
struct T28; struct G2C; struct T3C; struct G40;
struct T50; struct G54; struct T64; struct G68;

extern "C" char* fn_8059FFF8(A1A0* p);
extern "C" int fn_805A00BC(Db805A0000_Holder* p, char* b, int c);
extern "C" int fn_805A19C8(Db805A19C8_Obj* t, int id);
extern "C" void fn_805A1958(Db805A1958_Tab* r, int a, int b, int c);
extern "C" int fn_8053CAE0(Db8053967C_Idx* r);
extern "C" void fn_8053CB1C(Db8053967C_Idx* r, int a);
extern "C" void fn_8053CB94(Db8053967C_Idx* r, int a, unsigned b);
extern "C" void fn_8053CBF8(Db8053967C_Idx* r);
extern "C" void fn_8053ACB8(Db8053967C_Idx* r, int a);
extern "C" int fn_8053CC28(Db8053967C_Idx* r, int a);
extern "C" int fn_8053AD1C(Db8053967C_Idx* r, int a);
extern "C" void fn_8053CC1C(Db8053967C_Idx* r);
extern "C" int fn_805A18D8(T28* r, int i);
extern "C" int fn_805A18F0(G2C* r);
extern "C" int fn_805A18F8(T3C* r, int i);
extern "C" int fn_805A1910(G40* r);
extern "C" int fn_805A1918(T50* r, int i);
extern "C" int fn_805A1930(G54* r);
extern "C" int fn_805A1938(T64* r, int i);
extern "C" int fn_805A1950(G68* r);

int fn_8007DDC8(A* self, int a, int group, int idx);
int fn_8007DEAC(A* self, int a, int group);
int fn_8007DF5C(A* self, int a, int group, int idx);
int fn_8007E0E4(A* self, int a, int group);

static inline Db8053967C_Idx* Cur(Tbl* t, int id)
{
    return (Db8053967C_Idx*)&t->m10[fn_805A19C8((Db805A19C8_Obj*)t, id)];
}

void fn_8007DB74(A* self, int v)
{
    self->m8->m1BC8 = v;
}

int fn_8007DB80(A* self)
{
    return self->m8->m1BC8;
}

int fn_8007DB8C(A* self, char* b, int c)
{
    return fn_805A00BC((Db805A0000_Holder*)self->m8, b, c);
}

int fn_8007DBB0(A* self)
{
    return self->m8->m0;
}

char* fn_8007DBBC(A* self, int idx)
{
    Unk8007DB74_Arr* a = self->m8;
    if (idx >= 0 && idx < a->m0)
        return fn_8059FFF8((A1A0*)&a->m18[idx]);
    return 0;
}

int fn_8007DC08(A* self, int a, int target, int c, int* out)
{
    Unk8007DB74_Iter<9> it;
    while (it.i < fn_8007DEAC(self, a, c)) {
        if (fn_8007DDC8(self, a, c, it.i) == target) {
            *out = it.i;
            return 1;
        }
        it.Next();
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
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    if (d)
        fn_805A1958((Db805A1958_Tab*)r, b, c, (unsigned char)fn_8053B6CC((Db8053967C_Rost*)r, d));
    else
        fn_805A1958((Db805A1958_Tab*)r, b, c, 0xFF);
}

int fn_8007DDC8(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int rb = i * 0x1E0 + (int)t->m10;
    if (idx == 0)
        return fn_8053CAE0((Db8053967C_Idx*)rb);
    int ba = rb + 0xF0;
    int bo = idx + group * 0x30;
    unsigned char v = *(unsigned char*)(ba + bo);
    if (v == 0xFF)
        return 0;
    int vo = v * 4;
    return *(int*)((char*)((Rec*)rb)->m0 + vo);
}

unsigned char fn_8007DE50(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    return t->m10[i].mF0[group].b[idx];
}

int fn_8007DEAC(A* self, int a, int group)
{
    Cur(self->m58, a);
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
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    t->m10[i].mF0[group].w[idx] = v;
}

int fn_8007DF5C(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int rb = i * 0x1E0 + (int)t->m10;
    int go = group * 0x30;
    int io = idx * 4;
    int wa = rb + 0xFC;
    int wo = io + go;
    int w = *(int*)(wa + wo);
    if (w == 0)
        return fn_8053CAE0((Db8053967C_Idx*)rb);
    int ba = rb + 0xF0;
    int bo = w + go;
    unsigned char v = *(unsigned char*)(ba + bo);
    if (v == 0xFF)
        return 0;
    int vo = v * 4;
    return *(int*)((char*)((Rec*)rb)->m0 + vo);
}

unsigned char fn_8007DFF4(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int rb = i * 0x1E0 + (int)t->m10;
    int go = group * 0x30;
    int io = idx * 4;
    int wa = rb + 0xFC;
    int wo = io + go;
    int w = *(int*)(wa + wo);
    int ba = rb + 0xF0;
    int bo = w + go;
    return *(unsigned char*)(ba + bo);
}

int fn_8007E060(A* self, int a, int group, int idx)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    return t->m10[i].mF0[group].w[idx];
}

int fn_8007E0C0(A* self, int a, int target, int c)
{
    int tmp;
    return fn_8007DCA8(self, a, target, c, &tmp);
}

int fn_8007E0E4(A* self, int a, int group)
{
    Cur(self->m58, a);
    return 9;
}

int fn_8007E10C(A* self, int id)
{
    return fn_8053CA58(Cur(self->m58, id));
}

int fn_8007E154(A* self, int a, int x)
{
    return fn_8053CA8C(Cur(self->m58, a), x);
}

unsigned char fn_8007E1A4(A* self, int a, int x)
{
    int promoted = (signed char)fn_8053CAD4(Cur(self->m58, a), x);
    return (unsigned char)promoted;
}

int fn_8007E1F8(A* self, int id)
{
    return fn_8053CAE0(Cur(self->m58, id));
}

unsigned char fn_8007E240(A* self, int id)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, id);
    return t->m10[i].m14[t->m10[i].m20];
}

int fn_8007E290(A* self, int id)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, id);
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

void fn_8007E34C(A* self, int a, int x)
{
    fn_8053CB1C(Cur(self->m58, a), x);
}

void fn_8007E39C(A* self, int a, int x, int y)
{
    fn_8053CB94(Cur(self->m58, a), x, y);
}

void fn_8007E3F4(A* self, int id)
{
    fn_8053CBF8(Cur(self->m58, id));
}

void fn_8007E43C(A* self, int a, int x)
{
    fn_8053ACB8(Cur(self->m58, a), x);
}

int fn_8007E48C(A* self, int a, int x)
{
    return fn_8053CC28(Cur(self->m58, a), x) != -1;
}

void fn_8007E4EC(A* self, int a, int x)
{
    fn_8053AD1C(Cur(self->m58, a), x);
}

void fn_8007E53C(A* self)
{
    Tbl* t = self->m58;
    for (unsigned i = 0; i < t->mC; i++)
        fn_8053CC1C((Db8053967C_Idx*)&t->m10[i]);
}
int fn_8007E814(A* self, int a, int val, int* out);
int fn_8007EB14(A* self, int a, int val, int* out);
int fn_8007EE14(A* self, int a, int val, int* out);
int fn_8007F114(A* self, int a, int val, int* out);

void fn_8007E598(A* self, int a, int x)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, x);
    Vec* v = &r->m28[0];
    if (v->m4 < v->m8) {
        r->m28[0].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007E618(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A18F0((G2C*)r); i++) {
        if (fn_805A18D8((T28*)r, (unsigned char)i) == val) {
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
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, val);
    Vec* v = &r->m28[0];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[0].m0[n] = b;
}

int fn_8007E74C(A* self, int a, int idx)
{
    Tbl* t = self->m58;
    unsigned char n = idx;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int* p = t->m10[i].m0 + t->m10[i].m28[0].m0[n];
    return *p;
}

unsigned fn_8007E7A8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
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
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, x);
    Vec* v = &r->m28[1];
    if (v->m4 < v->m8) {
        r->m28[1].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007E918(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, val);
    Vec* v = &r->m28[1];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[1].m0[n] = b;
}

void fn_8007E994(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A1910((G40*)r); i++) {
        if (fn_805A18F8((T3C*)r, (unsigned char)i) == val) {
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
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int* p = t->m10[i].m0 + t->m10[i].m28[1].m0[n];
    return *p;
}

unsigned fn_8007EAA8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
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
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, x);
    Vec* v = &r->m28[2];
    if (v->m4 < v->m8) {
        r->m28[2].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007EC18(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, val);
    Vec* v = &r->m28[2];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[2].m0[n] = b;
}

void fn_8007EC94(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A1930((G54*)r); i++) {
        if (fn_805A1918((T50*)r, (unsigned char)i) == val) {
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
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int* p = t->m10[i].m0 + t->m10[i].m28[2].m0[n];
    return *p;
}

unsigned fn_8007EDA8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
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
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, x);
    Vec* v = &r->m28[3];
    if (v->m4 < v->m8) {
        r->m28[3].m0[v->m4] = b;
        v->m4++;
    }
}

void fn_8007EF18(A* self, int a, int idx, int val)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(i * 0x1E0 + (int)t->m10);
    unsigned char n = idx;
    unsigned char b = fn_8053B6CC((Db8053967C_Rost*)r, val);
    Vec* v = &r->m28[3];
    if (n >= v->m4)
        v->m4 = n + 1;
    r->m28[3].m0[n] = b;
}

void fn_8007EF94(A* self, int a, int val)
{
    Tbl* t = self->m58;
    int idx = fn_805A19C8((Db805A19C8_Obj*)t, a);
    Rec* r = (Rec*)(idx * 0x1E0 + (int)t->m10);
    for (int i = 0; i < fn_805A1950((G68*)r); i++) {
        if (fn_805A1938((T64*)r, (unsigned char)i) == val) {
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
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
    int* p = t->m10[i].m0 + t->m10[i].m28[3].m0[n];
    return *p;
}

unsigned fn_8007F0A8(A* self, int a)
{
    Tbl* t = self->m58;
    int i = fn_805A19C8((Db805A19C8_Obj*)t, a);
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
