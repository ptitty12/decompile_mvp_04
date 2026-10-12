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

struct Unk8030665C_E {
    char m0[0x16];
    char pad16[2];
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    float m38;
    Unk8030665C_E();
    Unk8030665C_E(const char* a, const char* b, int c18, int c1C, int c20, int c24, int c28, int c2C, int c30, int c34, float f38);
};
struct Unk80306780_P {
    char pad0[0x20C];
    int m20C;
};
struct Unk80306AC0_P {
    char pad0[0x210];
    int m210;
    int m214;
    int m218;
};
struct Unk803065EC_P {
    char pad0[0x18];
    const void* m18;
    char pad1C[0xC];
    Unk8030665C_E e[8];
};
extern float lbl_805E8728;
extern char lbl_805E7988;
extern "C" void* fn_8040B830(void* dst, const void* src, int n);
extern "C" void fn_80328374(void* p, int c);
void fn_80306734(void* p, int c);

/* 0x34-byte state record at +0x220 (copied to +0x254 by fn_80307E20, streamed out by fn_80307E9C). */
struct Unk80307E20_S {
    int w[13];
};
struct Unk80307E20_P {
    char pad0[0x220];
    Unk80307E20_S st[2];
};

inline void Unk80307E9C_Put(Unk80307E20_S** pp, const Unk80307E20_S* v)
{
    *(*pp)++ = *v;
}

extern const float lbl_805E8800;

struct Unk80305C88_Item {
    short v;
    short pad;
};
struct Unk80305C88_E {
    char pad0[8];
    int m8;
    Unk80305C88_Item* mC;
};
struct Unk80305C88_P {
    char pad0[0x15C];
    Unk80305C88_E* m15C;
    Unk80305C88_E* m160;
};
extern "C" int fn_803D77EC(void* p);

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

/* near-miss: retail's inner store loop is a compare/branch loop with a separate byte-offset register (sthx), ours becomes mtctr/bdnz (10 spellings tried: function-scope counter, explicit offset, inline setter) */
void fn_80305C88(Unk80305C88_P* p, short v)
{
    Unk80305C88_E* e = p->m15C;
    if (e != p->m160) {
        do {
            int n = 0;
            Unk80305C88_Item* arr;
            int ok;
            if (fn_803D77EC(e) != 0) {
                arr = e->mC;
                ok = 1;
                n = e->m8;
            } else {
                arr = 0;
                ok = 0;
            }
            if (ok != 0) {
                for (int i = 0; i < n; i++)
                    arr[i].v = v;
            }
            e++;
        } while (e != p->m160);
    }
}

void fn_80305D2C()
{
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

void fn_80306168()
{
}

void fn_80306258()
{
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

void fn_803065EC(Unk803065EC_P* p, int c)
{
    p->m18 = lbl_80665B18;
    Unk8030665C_E* b = &p->e[0];
    if (b != 0) {
        Unk8030665C_E* e = b + 8;
        if (b != e) {
            do {
                e--;
                fn_80306734(e, 0);
            } while (b != e);
        }
    }
    fn_80328374(p, c);
}

Unk8030665C_E::Unk8030665C_E()
{
    m38 = lbl_805E8728;
    m18 = 0;
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m0[0] = lbl_805E7988;
    m0[5] = lbl_805E7988;
}

Unk8030665C_E::Unk8030665C_E(const char* a, const char* b, int c18, int c1C, int c20, int c24, int c28, int c2C, int c30, int c34, float f38)
{
    m18 = c18;
    m1C = c1C;
    m20 = c20;
    m24 = c24;
    m28 = c28;
    m2C = c2C;
    m30 = c30;
    m34 = c34;
    m38 = f38;
    fn_8040B830(m0, a, 5);
    m0[5] = 0;
    fn_8040B830(&m0[5], b, 16);
    m0[0x15] = 0;
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

void fn_80306780(Unk80306780_P* p, int a)
{
    p->m20C = a;
}

int fn_80306A88(Unk80304858_E8* p)
{
    for (int i = 0; i < 8; i++) {
        if (p->e[i].m2C != 0)
            return i;
    }
    return 4;
}

void fn_80306AC0(int obj, int mode)
{
    Unk80306AC0_P* p = (Unk80306AC0_P*)obj;
    int a = 1;
    int b = 2;
    switch (mode) {
    case 0:
        p->m210 = 0;
        break;
    case 1:
        a = 4;
        p->m210 = 0;
        b = 3;
        break;
    case 2:
        a = 5;
        p->m210 = 1;
        b = 4;
        break;
    case 3:
        a = 5;
        p->m210 = 1;
        b = 6;
        break;
    }
    if (p->m214 != a)
        p->m214 = a;
    if (p->m218 != b)
        p->m218 = b;
}

void fn_80307E20(Unk80304858_Slots* p, int i)
{
    Unk80304858_Slot* sl = &p->s[i];
    sl->m0 = 0;
    sl->m4 = 0;
    sl->m8 = lbl_805E8800;
    ((Unk80307E20_P*)p)->st[1] = ((Unk80307E20_P*)p)->st[0];
}

int fn_80307E9C(Unk80307E20_P* p, Unk80307E20_S** out)
{
    Unk80307E20_S* cur = *out;
    Unk80307E9C_Put(&cur, &p->st[0]);
    *out = cur;
    return 1;
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
