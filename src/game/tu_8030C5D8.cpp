/*
 * Game code, .text 0x8030C5D8-0x80310934 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

extern char lbl_80665308[];
extern char lbl_80665278[];
extern Unk802F8324_VT18* lbl_8061FE10;
extern const char* lbl_8061FBF4[];

struct Unk8030C5D8_V2 {
    float x;
    float y;
};
struct Unk8030C5D8_Slot {
    int m0;
    int m4;
    float m8;
};
struct Unk8030C5D8_Slots {
    char pad0[0x24];
    Unk8030C5D8_Slot s[1];
    Unk8030C5D8_Slot m30;
};
struct Unk8030C5D8_At18 {
    char pad0[0x18];
    const void* m18;
};
struct Unk8030C5D8_Ent {
    int m0;
    int m4;
    char pad8[0x58 - 8];
};
struct Unk8030C5D8_List {
    char pad0[0x1C];
    int m1C;
    Unk8030C5D8_Ent e[1];
};
struct Unk8030C5D8_Obj4 {
    int m0;
    int m4;
};
struct Unk8030C5D8_P6C {
    char pad0[0x6C];
    Unk8030C5D8_Obj4* m6C[1];
};

struct V3x {
    float x;
    float y;
    float z;
};
struct Unk8030C5D8_V3 {
    int a;
    int b;
    int c;
};
struct Unk8030C5D8_FxObj {
    char pad0[4];
    float m4;
    char pad8[0x94 - 8];
    float m94;
    Unk8030C5D8_V3 m98;
};
struct Unk8030C5D8_FxEnt {
    Unk8030C5D8_FxObj* m0;
    int m4;
    float m8;
    Unk8030C5D8_V3 mC;
    char pad18[0x58 - 0x18];
};
struct Unk8030C5D8_Fx {
    const void* m0;
    int m4;
    char pad8[4];
    float mC;
    float m10;
    char pad14[8];
    int m1C;
    Unk8030C5D8_FxEnt e[5];
    float m1D8;
};
struct Unk8030C5D8_Md {
    char pad0[0x4C];
    unsigned int m4C;
};
struct Unk8030C5D8_PM {
    char pad0[0x6C];
    Unk8030C5D8_Fx* m6C[17];
};
struct Unk8030C5D8_Cur {
    int* p;
};
extern float lbl_806E10E4[];
extern void (*lbl_8062C66C)(void* p, int n);
struct Unk8030C5D8_Dl {
    char pad0[0xB8];
    void* mB8;
    void* mBC;
};
struct Unk8030C5D8_Em {
    char pad0[0x64];
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
    float m78;
    float m7C;
    char pad80[0xC4 - 0x80];
    float mC4[8];
    float mE4[8];
};
struct Unk8030C5D8_F3 {
    float x;
    float y;
    float z;
};
struct Unk8030C5D8_Em2 {
    char pad0[0x84];
    Unk8030C5D8_F3 m84;
    Unk8030C5D8_F3 m90;
    float m9C;
    char pad_A0[0xA0 - 0xA0];
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    float mB0;
};
struct Unk8030C5D8_Ctl {
    char pad0[0x6F4];
    int m6F4;
};

struct Unk8030C5D8_Pm {
    char pad0[0x14];
    int m14;
    const void* m18;
    char pad1C[0x6C - 0x1C];
    Unk8030C5D8_Fx* m6C[17];
};
struct Unk802FCAC0_Ent {
    char pad0[4];
    int m4;
    char pad8[0xC - 8];
    int mC;
    char pad10[0x24 - 0x10];
    Unk802F8324_V2 m24;
};

struct Unk802FCAC0_Obj {
    char pad0[0x18];
    const void* m18;
    char pad1C[8];
    int m24;
    Unk802FCAC0_Ent* m28[3];
    int m34_unused;
};

extern "C" void fn_8030D090(Unk802FCAC0_Obj* p);

extern "C" {
char* fn_8040B61C(char* d, const char* s);
void fn_80328234(void* p, int a, int b);
void fn_8030B188(void* p, int n);
int fn_8030B45C(void* p, int n);
int rand(void);
int fn_803285A0(int n);
void fn_8030CE58(Unk8030C5D8_Fx* p);
void fn_8030CECC(Unk8030C5D8_Fx* p, int k);
void fn_8030CF7C(Unk8030C5D8_Fx* p, const Unk8030C5D8_V3* a, const Unk8030C5D8_V3* b);
void fn_8030E47C(Unk8030C5D8_PM* p);
void* fn_8030C654(void* p);
void* fn_8030E63C(void* mem, Unk8030C5D8_Ctl* p, int c);
void fn_8030E78C(void* p, int a);
float fn_80323AC0(void* a, int k);
void fn_8030E504();
void fn_8030B358(void* p, int k);
void fn_80328374(void* p, int c);
void fn_8030EB38(void* p);
void fn_803DBD84(void* p, int k);
void fn_803E6708(void* p, int k);
void fn_8030BFF8(int p);
void fn_8030C11C(void* p);
int fn_8030CE18(int h);
int fn_8030C5D8(int h);
}

int fn_8030C5D8(int p)
{
    return fn_8037C7FC()->fn_8037CE98(0xD99143B6, p, 0);
}

float fn_8030C618(void* a, const Unk8030C5D8_V2* v, int k)
{
    return v->y * fn_80323AC0(a, k) + v->x;
}

void fn_8030C774(Unk8030C5D8_List* p)
{
    for (int i = 0; i < p->m1C; i++) {
        p->e[i].m0 = fn_8030C5D8(p->e[i].m4);
        if (p->e[i].m0)
            fn_8030BFF8(p->e[i].m0);
    }
}

void fn_8030C7E4(Unk8030C5D8_List* p)
{
    for (int i = 0; i < p->m1C; i++) {
        int q = fn_8030C5D8(p->e[i].m4);
        if (q)
            fn_8030C11C((void*)q);
    }
}

void* fn_8030CC08()
{
    return fn_8030C654(operator new(0x1DC, lbl_806EF9B4));
}

void fn_8030CC38(Unk802F8324_VT0* a, Unk802F8324_VT0* b)
{
    if (b) {
        if (a->s4() == b->s4()) {
            Unk8030C5D8_Fx* x = (Unk8030C5D8_Fx*)a;
            Unk8030C5D8_Fx* y = (Unk8030C5D8_Fx*)b;
            y->m4 = x->m4;
            y->mC = x->mC;
            y->m10 = x->m10;
            y->m1D8 = x->m1D8;
        }
    }
}

int fn_8030CE18(int p)
{
    return fn_8037C7FC()->fn_8037CE98(0x77F3B9AB, p, 0);
}

extern "C" void fn_8030CE58(Unk8030C5D8_Fx* p)
{
    Unk8030C5D8_Md* m = (Unk8030C5D8_Md*)fn_803285A0(1);
    p->m4 = 1;
    p->mC = (float)m->m4C * 0.016666668f;
    p->m10 = p->mC;
}

extern "C" void fn_8030CECC(Unk8030C5D8_Fx* p, int k)
{
    float t;
    for (int i = 0; i < p->m1C; i++) {
        Unk8030C5D8_FxObj* o = p->e[i].m0;
        if (o) {
            if (k != 0 || !(o->m94 >= 0.0f)) {
                o->m94 = -1.0f;
                p->m10 = -1.0f;
            } else {
                t = p->mC + p->e[i].m8 + o->m94 + o->m4;
                if (!(t <= p->m10))
                    p->m10 = t;
            }
        }
    }
}

extern "C" void fn_8030CF7C(Unk8030C5D8_Fx* p, const Unk8030C5D8_V3* a, const Unk8030C5D8_V3* b)
{
    for (int i = 0; i < p->m1C; i++) {
        if (p->e[i].m0)
            p->e[i].m0->m98 = *b;
        p->e[i].mC = *a;
    }
}

extern "C" void* fn_8030CFF4(Unk8030C5D8_Pm* p, int a)
{
    fn_80328234(p, 6, a);
    p->m18 = lbl_80665308;
    fn_8030B188((char*)p + 0xB0, 0x1B8);
    for (int i = 0; i < 0x11; i++)
        p->m6C[i] = 0;
    fn_8030D090((Unk802FCAC0_Obj*)p);
    fn_8030B45C((char*)p + 0xB0, 0);
    p->m14 = 0;
    fn_8040B61C((char*)p, "ParticleManager");
    return p;
}

extern "C" void fn_8030D090(Unk802FCAC0_Obj* q)
{
    Unk8030C5D8_PM* p = (Unk8030C5D8_PM*)q;
    for (int i = 0; i < 0x400; i++)
        lbl_806E10E4[i] = (float)(rand() % 10000) * 0.0002f - 1.0f;
    for (int i = 0; i < 0x11; i++) {
        Unk8030C5D8_Fx* o = p->m6C[i];
        if (o) {
            o->mC = 0.0f;
            o->m10 = 0.0f;
        }
    }
    fn_8030E47C(p);
}

extern "C" void fn_8030D170(Unk802FCAC0_Obj* p)
{
    fn_8030D090(p);
}

void fn_8030D190(Unk8030C5D8_At18* p, int c)
{
    p->m18 = lbl_80665308;
    fn_8030E504();
    fn_8030B358((char*)p + 0xB0, 2);
    fn_80328374(p, c);
}

extern "C" void fn_8030D1E4(void* pp, int idx, V3x* a, V3x* b, int depth, float f)
{
    Unk8030C5D8_PM* p = (Unk8030C5D8_PM*)pp;
    Unk8030C5D8_Fx* o = p->m6C[idx];
    if (o && o->m4 == 0) {
        fn_8030CE58(o);
        fn_8030CECC(o, 0);
        fn_8030CF7C(o, (const Unk8030C5D8_V3*)a, (const Unk8030C5D8_V3*)b);
        o->m1D8 = f;
    } else if (depth > 0 && idx <= 0x10) {
        fn_8030D1E4(p, idx + 1, a, b, depth - 1, f);
    }
}

void fn_8030D28C(Unk8030C5D8_P6C* p, int i)
{
    Unk8030C5D8_Obj4* q = p->m6C[i];
    if (q && q->m4 == 0) {
        fn_8030CE58((Unk8030C5D8_Fx*)q);
        fn_8030CECC((Unk8030C5D8_Fx*)q, 0);
    }
}

int fn_8030E2F8(Unk8030C5D8_PM* p, int** out)
{
    int* cur = *out;
    int** pc = &cur;
    for (int i = 0; i < 0x11; i++) {
        Unk8030C5D8_Obj4* o = (Unk8030C5D8_Obj4*)p->m6C[i];
        if (o) {
            int* q = *pc;
            *q = o->m4;
            *pc = q + 1;
        }
    }
    *out = cur;
    return 1;
}

void fn_8030E354(Unk8030C5D8_Slots* p, int i)
{
    Unk8030C5D8_Slot* s = &p->s[i];
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = 0.0f;
}

void fn_8030E37C(Unk8030C5D8_Slots* p, int i, int a, int b, float f)
{
    Unk8030C5D8_Slot* s = &p->s[i];
    s->m0 = a;
    s->m4 = b;
    s->m8 = f;
}

void fn_8030E3A8(Unk8030C5D8_Slots* p, int i)
{
    int off = i * 0xC + 0x24;
    *(Unk8030C5D8_Slot*)((char*)p + off) = p->m30;
}

void fn_8030E3D4(Unk8030C5D8_PM* p, int idx)
{
    int off = idx * 0xC + 0x24;
    Unk8030C5D8_Slot* s = (Unk8030C5D8_Slot*)((char*)p + off);
    int* a = (int*)s->m0;
    int* b = (int*)s->m4;
    int* x = a;
    int* y = b;
    for (int i = 0; i < 0x11; i++) {
        Unk8030C5D8_Fx* o = p->m6C[i];
        if (o)
            o->m4 = 0;
    }
    if (a == 0)
        return;
    if (b == 0)
        return;
    for (int i = 0; i < 0x11; i++) {
        Unk8030C5D8_Fx* o = p->m6C[i];
        if (o) {
            int f = 0;
            if (*x != 0 || *y != 0)
                f = 1;
            o->m4 = f;
            x++;
            y++;
        }
    }
}

extern "C" void fn_8030E47C(Unk8030C5D8_PM* p)
{
    Unk8030C5D8_Fx* o;
    for (int i = 0; i < 0x11; i++) {
        o = p->m6C[i] = (Unk8030C5D8_Fx*)fn_8030CE18(fn_80378568(lbl_8061FBF4[i], 0));
        if (o)
            fn_8030C774((Unk8030C5D8_List*)o);
    }
    o = p->m6C[0];
    if (o) {
        fn_8030CE58(o);
        fn_8030CECC(o, 1);
    }
}

void fn_8030E504()
{
    for (int i = 0; i < 0x11; i++) {
        int o = fn_8030CE18(fn_80378568(lbl_8061FBF4[i], 0));
        if (o)
            fn_8030C7E4((Unk8030C5D8_List*)o);
    }
}

void* fn_8030E560(Unk8030C5D8_Ctl* p, int a, int c)
{
    if (p && lbl_8061FE10 == 0 && p->m6F4 != 2 && p->m6F4 != 3) {
        void* t = fn_8030E63C(operator new(0x1BC, 0x400), p, c);
        lbl_8061FE10 = (Unk802F8324_VT18*)t;
        fn_8030E78C(t, a);
    }
    return lbl_8061FE10;
}

void fn_8030E5E4()
{
    if (lbl_8061FE10) {
        delete lbl_8061FE10;
        lbl_8061FE10 = 0;
    }
}

void fn_8030E72C(Unk8030C5D8_At18* p, int c)
{
    p->m18 = lbl_80665278;
    fn_8030EB38(p);
    fn_803DBD84((char*)p + 0x150, 2);
    fn_803E6708((char*)p + 0x114, 2);
    fn_80328374(p, c);
}

extern "C" void fn_8030EB38(void* pp)
{
    Unk8030C5D8_Dl* p = (Unk8030C5D8_Dl*)pp;
    if (p->mB8 != 0) {
        lbl_8062C66C((char*)p->mB8 - 8, ((int*)p->mB8)[-2] * 12 + 8);
        p->mB8 = 0;
    }
    if (p->mBC != 0) {
        lbl_8062C66C((char*)p->mBC - 8, ((int*)p->mBC)[-2] * 4 + 8);
        p->mBC = 0;
    }
}

void fn_8030F9DC(Unk8030C5D8_Em2* p)
{
    float a = 1500.0f;
    float b = -150.0f;
    float c = 500.0f;
    p->m84.x = a;
    p->m84.y = p->mA0 * 0.5f + b;
    p->m84.z = c;
    p->m90 = p->m84;
    p->m90.x = p->m9C * ((p->mA8 + 1.0f) * 0.5f) + p->m90.x;
    p->m90.z = p->mA4 * ((p->mB0 - 1.0f) * 0.25f) + p->m90.z;
}

void fn_8030FA9C(Unk8030C5D8_Em* p)
{
    for (int i = 0; i < 8; i++) {
        float v = p->m78 * ((float)(rand() % 1024) * 0.0009775171f) + p->m64;
        p->mC4[i] = p->m6C * v + p->m68 * (1.0f - v);
    }
}

void fn_8030FB5C(Unk8030C5D8_Em* p)
{
    for (int i = 0; i < 8; i++) {
        float v = p->m7C * ((float)(rand() % 1024) * 0.0009775171f) + p->m64;
        p->mE4[i] = p->m74 * v + p->m70 * (1.0f - v);
    }
}
