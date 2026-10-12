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

extern "C" {
void* fn_8030C654(void* p);
float fn_80323AC0(void* a, int k);
void fn_8030E504();
void fn_8030B358(void* p, int k);
void fn_80328374(void* p, int c);
void fn_8030EB38(void* p);
void fn_803DBD84(void* p, int k);
void fn_803E6708(void* p, int k);
void fn_8030BFF8(int p);
void fn_8030C11C(void* p);
void fn_8030CE58(void* p);
void fn_8030CECC(void* p, int k);
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

int fn_8030CE18(int p)
{
    return fn_8037C7FC()->fn_8037CE98(0x77F3B9AB, p, 0);
}

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

void fn_8030D28C(Unk8030C5D8_P6C* p, int i)
{
    Unk8030C5D8_Obj4* q = p->m6C[i];
    if (q && q->m4 == 0) {
        fn_8030CE58(q);
        fn_8030CECC(q, 0);
    }
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

void fn_8030E504()
{
    for (int i = 0; i < 0x11; i++) {
        int o = fn_8030CE18(fn_80378568(lbl_8061FBF4[i], 0));
        if (o)
            fn_8030C7E4((Unk8030C5D8_List*)o);
    }
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
