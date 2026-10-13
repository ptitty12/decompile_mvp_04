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

struct Unk80304858_M44 {
    float m[16];
};
struct Unk80304858_Cam {
    char pad0[0x6B8];
    char* m6B8;
};
extern void* lbl_8061FEDC;
void fn_80312DA0();
void fn_80312DA4();
struct Unk80304858_VT98D {
    char pad0[0x98];
};
class Unk80304858_VT98V : public Unk80304858_VT98D {
public:
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5(int a);
    virtual void* s6();
};
struct Unk80305D30_C {
    char pad0[0xB3C];
    unsigned mB3C;
};
struct Unk80304858_VT98 : public Unk80304858_VT98V {
    char pad9C[0x36C - 0x9C];
    Unk80305D30_C* m36C;
    int m370;
};
struct Unk80304858_Rec {
    int m0;
};
struct Unk80304858_Sx {
    char pad0[0x1C];
    int m1C;
    char pad20[4];
    int m24;
    char pad28[0x18C - 0x28];
    Unk80304858_VT98* m18C;
    char pad190[4];
    int m194;
};
extern int lbl_8061F94C;
extern int lbl_80620378;
extern int lbl_8061F960;
extern int lbl_8061F964;
struct Unk8030741C_E {
    char pad0[4];
    float m4;
};
struct Unk8030741C_L {
    char pad0[4];
    Unk8030741C_E* e[15];
};
struct Unk8030741C_T {
    int n;
    char pad4[0x3C - 4];
};
struct Unk8030741C_O2 {
    char pad0[0x54];
    int m54;
};
struct Unk8030741C_O1 {
    char pad0[0x54C];
    Unk8030741C_O2* m54C;
};
struct Unk8030741C_P {
    char pad0[0x1C];
    Unk8030741C_O1* m1C;
    char pad20[4];
    int m24;
    char pad28[0x40 - 0x28];
    Unk8030741C_T t[5];
    char pad16C[0x208 - 0x16C];
    Unk8030741C_L* m208;
    char pad20C[0x254 - 0x20C];
    float m254;
    unsigned m258;
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
void fn_80305AAC(Unk80304858_V3* v, Unk80304858_M44* o, float f);
void fn_803DFE28(Unk80304858_M44* dst, Unk80304858_M44* other);
void fn_803D68AC(int h, void* mtx);
void fn_8037D768(void* p);
void fn_803DFEE0(Unk80304858_M44* dst, float x, float y, float z, float w);
void fn_80328234(void* p, int a, int b);
void fn_80305D30(Unk80304858_Sx* p);
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

void fn_80304A8C(Unk80304858_Sx* p)
{
    if (p->m194 != 0) {
        Unk80304858_Rec* r = (Unk80304858_Rec*)p->m18C->s6();
        if (r->m0 == 0)
            fn_8037D768(r);
        r->m0 = 1;
        Unk80304858_M44 work = *(Unk80304858_M44*)((char*)r + 0x20);
        if (p->m1C != 0) {
            if (p->m18C->s5(1) != 0 && lbl_8061F94C == 0)
                fn_803DFEE0(&work, -1.0f, 1.0f, 1.0f, 1.0f);
        }
        if (p->m24 != 0)
            fn_803D68AC(p->m24, &work);
    }
}

int fn_80304BDC(Unk80304858_At24* p)
{
    return p->m24;
}

void fn_80304BE4(Unk80304858_Sx* p, Unk80304858_M44* src)
{
    if (p->m194 != 0) {
        Unk80304858_M44 work = *src;
        if (p->m1C != 0) {
            if (p->m18C->s5(1) != 0 && lbl_8061F94C == 0)
                fn_803DFEE0(&work, -1.0f, 1.0f, 1.0f, 1.0f);
        }
        if (p->m24 != 0)
            fn_803D68AC(p->m24, &work);
    }
}

void fn_80304CF8(Unk80304858_Sx* p)
{
    if (p->m194 != 0) {
        Unk80304858_Rec* r = (Unk80304858_Rec*)p->m18C->s6();
        if (r->m0 == 0)
            fn_8037D768(r);
        r->m0 = 1;
        Unk80304858_M44 work = *(Unk80304858_M44*)((char*)r + 0x20);
        lbl_8061F960 = lbl_8061F960 + 1;
        if (lbl_8061F960 == 0xB) {
            lbl_8061F960 = 0;
            lbl_8061F964 = lbl_8061F964 + 1;
        }
        if (lbl_8061F964 > 0x59)
            lbl_8061F964 = 0;
        if (p->m1C != 0) {
            if (p->m18C->s5(1) != 0 && lbl_8061F94C == 0)
                fn_803DFEE0(&work, -1.0f, 1.0f, 1.0f, 1.0f);
        }
        if (p->m24 != 0)
            fn_803D68AC(p->m24, &work);
    }
}

extern "C" void fn_80305AAC(Unk80304858_V3* v, Unk80304858_M44* o, float f)
{
    float a = v->y;
    float b = -f;
    float d = 1.0f / (a + b);
    o->m[1] = 0.0f;
    o->m[2] = 0.0f;
    o->m[3] = 0.0f;
    o->m[0] = (a + b) * d;
    o->m[4] = v->x * -d;
    o->m[5] = ((a + b) - v->y) * d;
    o->m[6] = v->z * -d;
    o->m[7] = -d;
    o->m[10] = 1.0f;
    o->m[8] = 0.0f;
    o->m[9] = 0.0f;
    o->m[11] = 0.0f;
    o->m[12] = v->x * -b * d;
    o->m[13] = v->y * -b * d;
    o->m[14] = v->z * -b * d;
    o->m[15] = a * d;
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

void fn_80305D30(Unk80304858_Sx* p)
{
    Unk80304858_VT98* c = p->m18C;
    Unk80305D30_C* d = c->m36C;
    if (d != 0) {
        Unk80304858_M44 work = *(Unk80304858_M44*)((char*)c + 0x3A0);
        unsigned f = d->mB3C;
        if (f & 0x01000000) {
            fn_803DFEE0(&work, 1.0f, 2.0f, 2.0f, 1.0f);
        } else {
            int t = (f >> 27) & 1;
            if (lbl_80620378 != 0)
                t = 1;
            if (t != 0)
                fn_803DFEE0(&work, 1.0f, 0.5f, 0.5f, 1.0f);
        }
        fn_803D68AC(p->m24, &work);
        return;
    }
    Unk80304858_Rec* r = (Unk80304858_Rec*)c->s6();
    if (r->m0 == 0)
        fn_8037D768(r);
    r->m0 = 1;
    fn_803D68AC(p->m24, (char*)r + 0x20);
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

void fn_8030616C(void* u0, int h, Unk80304858_M44* src, void* u3, Unk80304858_Cam* cam)
{
    if (h != 0) {
        void* o = lbl_8061FEDC;
        ((void (*)(void*))fn_80312DA0)(o);
        char* b = cam->m6B8;
        Unk80304858_M44 out;
        Unk80304858_M44 work = *src;
        Unk80304858_M44* pw = &work;
        fn_80305AAC((Unk80304858_V3*)(b + 0x364), &out, 0.5f);
        fn_803DFE28(pw, &out);
        fn_803D68AC(h, pw);
        ((void (*)(void*))fn_80312DA4)(o);
    }
}

void fn_80306258()
{
}

void fn_8030625C(Unk80304858_Sx* p)
{
    Unk80304858_VT98* c = p->m18C;
    if (c->m370 != 0) {
        Unk80304858_M44 work = *(Unk80304858_M44*)((char*)c + 0x460);
        fn_803D68AC(p->m24, &work);
        return;
    }
    Unk80304858_Rec* r = (Unk80304858_Rec*)c->s6();
    if (r->m0 == 0)
        fn_8037D768(r);
    r->m0 = 1;
    fn_803D68AC(p->m24, (char*)r + 0x20);
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
    if (lbl_8061F970 != 0)
        fn_80306438();
    fn_803063C4();
    return lbl_8061F970;
}

int fn_80306438()
{
    if (lbl_8061F970 != 0) {
        fn_803DD73C(lbl_8061F970, 3);
        lbl_8061F970 = 0;
        fn_803EDA0C(lbl_8061F974);
        lbl_8061F974 = 0;
    }
    fn_803063E8();
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

void fn_8030741C(Unk8030741C_P* p)
{
    if (p->m24 != 0 && p->m1C->m54C->m54 == 3) {
        unsigned idx = p->m258;
        if (idx <= 4) {
            int n = p->t[idx].n;
            float sp8 = (float)n;
            float spC = 1.0f / sp8;
            int k = (int)(p->m254 * (float)(n - 1) + (!(p->m254 * (float)(n - 1) < 0.0f) ? 0.5f : -0.5f));
            for (int i = 0; i < 15; i++) {
                Unk8030741C_E* e = p->m208->e[i];
                if (e != 0)
                    e->m4 = ((sp8 - 1.0f) - (float)k) * -spC;
            }
        }
    }
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
