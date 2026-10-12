/*
 * Game code, .text 0x80304858-0x80308874 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

extern char lbl_80665C78[];
extern char lbl_80665C38[];
extern char lbl_80665BF8[];
extern char lbl_80665BB8[];
extern char lbl_80665B18[];
extern int lbl_8061F96C;
extern int lbl_8061F970;
extern int lbl_8061F974;

struct Unk80304858_V3 {
    float x;
    float y;
    float z;
};
struct Unk80304858_At24 {
    char pad0[0x24];
    int m24;
};
struct Unk80304858_At8 {
    char pad0[8];
    const void* m8;
};
struct Unk80304858_P198 {
    char pad0[8];
    const void* m8;
    char pad0C[0x198 - 0xC];
    void* m198;
};
struct Unk80304858_P0 {
    int m0;
    char pad4[4];
};
struct Unk80304858_Slot {
    int m0;
    int m4;
    float m8;
};
struct Unk80304858_Slots {
    char pad0[0x288];
    Unk80304858_Slot s[1];
    Unk80304858_Slot m294;
};
struct Unk80304858_Elem3C {
    char pad0[0x2C];
    int m2C;
    char pad30[0xC];
};
struct Unk80304858_E8 {
    char pad0[0x28];
    Unk80304858_Elem3C e[8];
};

extern "C" {
void fn_80304098(void* p, int a, int b, int c, int d, int e);
void fn_80304388(void* p, int c);
void fn_80377488(void* p);
void fn_80377408(void* p);
void fn_8030ACCC(void* p);
void fn_8030AD10(void* p, int a, int b, int c, int d);
void fn_803DD73C(int h, int k);
void fn_803EDA0C(int h);
void fn_803063E8();
void fn_803063C4();
int fn_80306438();
void fn_80306788(void* p);
}

int fn_80304BDC(Unk80304858_At24* p)
{
    return p->m24;
}

void* fn_80305B88(Unk80304858_P198* p, int a, int b, int c, int d)
{
    fn_80304098(p, a, b, c, 0, d);
    p->m198 = 0;
    p->m8 = lbl_80665C78;
    return p;
}

void fn_80305BD4(Unk80304858_P198* p, int c)
{
    p->m8 = lbl_80665C78;
    if (p->m198) {
        fn_80377488(p->m198);
        p->m198 = 0;
    }
    fn_80304388(p, c);
}

void fn_80305C30(Unk80304858_P0* p, int a, int b, int c)
{
    fn_8030ACCC((char*)p + 4);
    fn_8030AD10((char*)p + 4, p->m0, a, b, c);
}

void* fn_80305E94(Unk80304858_At8* p, int a, int b, int c)
{
    fn_80304098(p, a, b, c, 0, 0);
    p->m8 = lbl_80665C38;
    return p;
}

void fn_80305ED8(Unk80304858_At8* p, int c)
{
    p->m8 = lbl_80665C38;
    fn_80304388(p, c);
}

void* fn_80305F08(Unk80304858_At8* p, int a, int b, int c)
{
    fn_80304098(p, a, b, c, 0, 0);
    p->m8 = lbl_80665BF8;
    return p;
}

void fn_80305F4C(Unk80304858_At8* p, int c)
{
    p->m8 = lbl_80665BF8;
    fn_80304388(p, c);
}

void* fn_80306350(Unk80304858_At8* p, int a, int b, int c)
{
    fn_80304098(p, a, b, c, 0, 0);
    p->m8 = lbl_80665BB8;
    return p;
}

void fn_80306394(Unk80304858_At8* p, int c)
{
    p->m8 = lbl_80665BB8;
    fn_80304388(p, c);
}

/* near-miss: retail keeps the loaded zero in r0 and stores it before li r0,1; ours loads into r11 (4 spellings tried) */
void fn_803063C4()
{
    if (lbl_8061F96C == 0) {
        lbl_8061F974 = 0;
        lbl_8061F96C = 1;
    }
}

extern "C" void fn_803063E8()
{
    lbl_8061F96C = 0;
}


int fn_803063F8()
{
    if (lbl_8061F970 != 0) {
        fn_80306438();
        fn_803063C4();
    }
    return lbl_8061F970;
}

int fn_80306438()
{
    if (lbl_8061F970 != 0) {
        fn_803DD73C(lbl_8061F970, 3);
        lbl_8061F970 = 0;
        fn_803EDA0C(lbl_8061F974);
        lbl_8061F974 = 0;
        fn_803063E8();
    }
    return 1;
}

void fn_80306734(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

void fn_8030675C(Unk80304858_At8* p, int a)
{
    *(int*)((char*)p + 0x208) = a;
    fn_80306788(p);
}

int fn_80306A88(Unk80304858_E8* p)
{
    for (int i = 0; i < 8; i++) {
        if (p->e[i].m2C != 0)
            return i;
    }
    return 4;
}

void fn_80307F20(Unk80304858_Slots* p, int i, int a, int b, float f)
{
    Unk80304858_Slot* s = &p->s[i];
    s->m0 = a;
    s->m4 = b;
    s->m8 = f;
}

void fn_80307F4C(Unk80304858_Slots* p, int i)
{
    int off = i * 0xC + 0x288;
    *(Unk80304858_Slot*)((char*)p + off) = p->m294;
}

int fn_80308618(void* a, const Unk80304858_V3* v)
{
    int r = 0;
    if (!(v->x < 0.0f))
        r = v->z >= 0.0f;
    return r;
}

int fn_80308648(void* a, const Unk80304858_V3* v)
{
    int r = 0;
    if (!(v->x > 0.0f))
        r = v->z <= 0.0f;
    return r;
}
