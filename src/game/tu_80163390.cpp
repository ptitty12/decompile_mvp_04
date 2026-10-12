/*
 * Game code, .text 0x80163390-0x80167DCC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80163390.h"




extern const char lbl_805C8C20[];


extern float lbl_805EBA00;
extern int lbl_8062087C;
extern int lbl_8061C3A4;
extern int lbl_8061C3A8;
extern int lbl_8062151C;
int fn_801DC10C(void* p);
int fn_80259330(void* p);
void fn_8016C4A0(void* p);
void fn_80327214(Unk801527C8_Sub* s);
void fn_80327274(Unk801527C8_Sub* s);
Unk801527C8_Actor* fn_801A04A8(Unk801527C8_Actor* a, int i);
Unk801527C8_Actor* fn_801A49F0(Unk801527C8_Actor* a, int k, int v);
Unk801527C8_Actor* fn_801A4910(Unk801527C8_Actor* a, int k, int v);
int fn_8014E310(int id);
void fn_8022EA60(Unk80273498_Vec3* out, void* a, ...);
void fn_8018CA5C(Unk80189300* o, float* a, float* b, float* c);

void Unk80159F28::fn_80163A98() /* 80163A98 */
{
    Unk801527C8_Actor* a = mC;
    m32C = 0;
    Unk801527C8_Sub* s = &a->m50;
    Unk801527C8_Actor* o = fn_801A04A8(a, 0);
    if (o != 0) {
        fn_8016C4A0(o->m40);
    }
    fn_80327214(s);
}

void Unk80159F28::fn_80163AF0() /* 80163AF0 */
{
}

void Unk80159F28::fn_80163AF4(int id) /* 80163AF4 */
{
    Unk801527C8_Actor* a = mC;
    Unk801527C8_Sub* s = &a->m50;
    float t = (float)*(unsigned int*)&a->m4C * 0.016666668f;
    switch (id) {
    case 0x10:
    case 0x3D:
    case 0x44:
    case 0x56:
        s->fn_80326EF4(t, 0.0f, id, -1, -1, 0);
        break;
    case 0x5A:
        fn_80163A98();
        s->fn_80326EF4(t, 0.0f, 0x5A, -1, -1, 0);
        break;
    case 0x32:
        fn_80327274(s);
        break;
    case 0x5B:
        m10 = 1;
        fn_80161A74();
        break;
    case 0x42: {
        float u = a->m700->m3A4->m180 - 0.016666668f;
        s->fn_80326EF4(u, 0.0f, 0x42, -1, -1, 0);
        break;
    }
    }
}

/* near-miss: retail tests v > 7 first and handles 0/<0/>=2 with a compare chain; the switch below compiles to a different tree */
void Unk80159F28::fn_80163C50() /* 80163C50 */
{
    switch (mC->m6F4) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
    case 10:
    case 11:
        fn_80163AF0();
        break;
    case 6:
    case 7:
        fn_80163AF4();
        break;
    default:
        fn_80163CC4();
        break;
    }
}

struct Unk80163CC4_Evt {
    int m0;
};

struct Unk80163CC4_Obj {
    char pad0[0x708];
    int m708;
    char pad70C[0xB74 - 0x70C];
    int mB74;
};

struct Unk80163CC4_Evt97 {
    char pad0[0xC];
    Unk80163CC4_Obj* mC;
};

struct Unk80163CC4_Evt98 {
    char pad0[8];
    int m8;
    int mC;
};

struct Unk80163CC4_Evt99 {
    char pad0[8];
    int m8;
    Unk80326F44_Out mC;
    int m24;
};

struct Unk8019F8C0_Owner;
struct Unk802B0ACC_T;
int fn_801A7130(Unk8019F8C0_Owner* o, int i);
void fn_802B2ED0(Unk802B0ACC_T* t, int i);
extern char* lbl_8061E978;

struct Unk80163CC4_Time {
    char pad0[0x4C];
    unsigned int m4C;
};

inline Unk80326F44_Out Unk80163CC4_OutOf(const Unk80163CC4_Evt99* c)
{
    return c->mC;
}

struct Unk80165978_Obj {
    char pad0[0x458];
    int m458;
};

struct Unk80165978_Evt {          /* fn_80165978 */
    int m0;
    char pad4[4];
    int m8;
    Unk80165978_Obj* mC;
    char pad10[0xC];
    float m1C;
    int m20;
    int m24;
    int m28;
    char pad2C[0x3C - 0x2C];
    int m3C;
    char pad40[4];
    int m44;
};

struct Unk801655F0_Obj {
    char pad0[0x458];
    int m458;
    char pad45C[0x4C4 - 0x45C];
    unsigned int m4C4;
};

struct Unk801655F0_Evt {          /* fn_801655F0 */
    int m0;
    char pad4[0xC];
    Unk801655F0_Obj* m10;
    int m14;
};

struct Unk80164624_Evt {          /* fn_80164624 */
    int m0;
    char pad4[4];
    int m8;
    char padC[4];
    int m10;
};

#define EVK(T, k) ((T*)(e ? ((k) == e->m0 ? e : 0) : 0))


void Unk80159F28::fn_80163CC4(int id, Unk80163CC4_Evt* e) /* 80163CC4 */
{
    Unk801527C8_Actor* a = mC;
    Unk801527C8_Sub* s = &a->m50;
    float t = (float)((Unk80163CC4_Time*)a)->m4C * 0.016666668f;
    switch (id) {
    case 3:
    case 4:
    case 0x10:
    case 0x29:
    case 0x3C:
    case 0x40:
    case 0x44:
    case 0x45:
    case 0x4B:
    case 0x4C:
    case 0x4E:
    case 0x4F:
    case 0x52:
    case 0x56:
    case 0x61:
    case 0x69:
    case 0x84:
    case 0x87:
    case 0x8C:
        s->fn_80326EF4(t, 0.0f, id, -1, -1, 0);
        break;
    case 0x41:
    case 0x48:
        fn_801653B0(id, t);
        break;
    case 0x8D:
        fn_80165790(EVK(Unk80165790_Evt, id), t);
        break;
    case 0x64:
        fn_80165738(EVK(Unk801654F0_Evt, id), t);
        break;
    case 0x88:
        s->fn_80326EF4(t, 0.0f, id, EVK(Unk80165790_Evt, id)->m8->m458, -1, 0);
        break;
    case 0x46:
        m334 = (float)((Unk80163CC4_Time*)a)->m4C * 0.016666668f + 2.0f;
        break;
    case 0x59: {
        Unk801527C8_Actor* o = fn_801A04A8(a, 0);
        if (o != 0) {
            fn_8016C4A0(o->m40);
        }
        break;
    }
    case 0x7B:
        s->fn_80326EF4(t, 0.0f, 0x7B, -1, -1, 0);
        fn_80169674();
        break;
    case 0x7E:
        fn_801654F0(EVK(Unk801654F0_Evt, id), t);
        break;
    case 0xA4:
        fn_80164624(EVK(Unk80164624_Evt, id));
        break;
    case 0x30:
        fn_80163A98();
        break;
    case 0x5A:
        fn_80163A98();
        s->fn_80326EF4(t, 0.0f, 0x5A, -1, -1, 0);
        break;
    case 0x3D:
        fn_80165328(EVK(Unk80165328_Evt, id), t);
        break;
    case 0x79:
        fn_80165578(EVK(Unk80165578_Evt, id), t);
        break;
    case 0x6A:
        fn_80163A98();
        s->fn_80326EF4(t, 0.0f, 0x6A, -1, -1, 0);
        break;
    case 0x3A:
        s->fn_80326EF4(t, 0.0f, 0x3A, -1, -1, 0);
        fn_80164F48(EVK(Unk801654F0_Evt, id), t);
        break;
    case 0x68:
        fn_801657EC(EVK(Unk801657EC_Evt, id), t);
        break;
    case 0x5F:
        fn_80165884(EVK(Unk80165884_Evt, id), t);
        break;
    case 0x49: {
        s->fn_80326EF4(t, 0.0f, 0x49, -1, -1, 0);
        Unk801654F0_Evt* c = EVK(Unk801654F0_Evt, id);
        if (c->m8 == 1) {
            s->fn_80326EF4(t, 0.0f, 0xB1, -1, -1, 0);
            fn_802B2ED0((Unk802B0ACC_T*)(lbl_8061E978 + 0xAF4), 0);
            m338 = (float)((Unk80163CC4_Time*)a)->m4C * 0.016666668f + 2.0f;
        }
        break;
    }
    case 0x7F:
        fn_80165834(EVK(Unk80165834_Evt, id), t);
        break;
    case 0x32:
        fn_80327274(s);
        break;
    case 0x39:
        fn_80165BE0(EVK(Unk80165BE0_Evt, id), t);
        break;
    case 0x5B:
        m10 = 1;
        fn_80161A74();
        break;
    case 0x93:
        fn_801655F0(EVK(Unk801655F0_Evt, id));
        break;
    case 0x42: {
        float u = a->m700->m3A4->m180 - 0.016666668f;
        s->fn_80326EF4(u, 0.0f, 0x42, -1, -1, 0);
        break;
    }
    case 0x58:
        fn_80165978(EVK(Unk80165978_Evt, id), t);
        break;
    case 0x73:
        fn_80165AF4(EVK(Unk80165AF4_Evt, id), t);
        break;
    case 0x57:
        fn_80165B68(EVK(Unk80165B68_Evt, id), t);
        break;
    case 0x62:
        fn_80165908(EVK(Unk80165834_Evt, id), t);
        break;
    case 0x97: {
        Unk80163CC4_Evt97* c = EVK(Unk80163CC4_Evt97, id);
        Unk80163CC4_Obj* o = c->mC;
        if (o != 0) {
            int k = o->m708;
            if (fn_801A7130((Unk8019F8C0_Owner*)mC, k) != 0) {
                if (o->mB74 == 0) {
                    o->mB74 = 1;
                    if (k == 0) {
                        m28 = 1;
                    } else {
                        m2C = 1;
                    }
                }
            }
        }
        break;
    }
    case 0x98: {
        Unk80163CC4_Evt98* c = EVK(Unk80163CC4_Evt98, 0x98);
        m30 = 1;
        m38 = c->mC;
        m34 = c->m8;
        break;
    }
    case 0x99: {
        Unk80163CC4_Evt99* c = EVK(Unk80163CC4_Evt99, id);
        m3C = 1;
        m40 = c->m8;
        Unk80326F44_Out o = Unk80163CC4_OutOf(c);
        m44 = o.mC;
        if (c->m24 != 0) {
            fn_80163748();
        }
        break;
    }
    }
}

#undef EVK

struct Unk8017A930_T;
struct Unk80178BBC_T;
void fn_8017CF00(Unk8017A930_T* t);
void fn_80179114(Unk80178BBC_T* t, int a);
extern "C" int fn_80097190(Unk801527C8_Team* t, int a);
extern "C" int fn_80097300(Unk801527C8_Team* t, int a);
extern "C" int fn_800968C0(Unk801527C8_Team* t, int a, int b);

struct Unk80164624_Slots {
    char pad0[0x3AC];
    Unk80178BBC_T* m3AC;
};

void Unk80159F28::fn_80164624(Unk80164624_Evt* e) /* 80164624 */
{
    if (e != 0) {
        int sel = -1;
        switch (e->m8) {
        case 0x26:
            m1C = 0;
            break;
        case 0x27:
            m20 = 0;
            break;
        case 0x28:
            m24 = 0;
            break;
        case 1:
            m10 = 0;
            break;
        case 0xD:
            sel = 0;
            break;
        case 0xE:
            sel = 1;
            break;
        case 0xF:
            sel = 2;
            break;
        case 0x10:
            sel = 3;
            break;
        case 0x11:
            sel = 4;
            break;
        case 0x12:
            sel = 5;
            break;
        case 0x13:
            sel = 6;
            break;
        case 0x29:
            m14 = 0;
            m18 = 0;
            break;
        case 0x1C:
        case 0x1D:
        case 0x1E:
            m30 = 0;
            m38 = 0;
            break;
        case 0x1F:
            fn_8017CF00((Unk8017A930_T*)mC->m700);
            m3C = 0;
            break;
        case 0x23:
        case 0x24:
        case 0x25:
            fn_80179114(((Unk80164624_Slots*)mC->m700)->m3AC, e->m10);
            break;
        }
        if (sel != -1) {
            int t = 0;
            if (mC->m6F8->m14->m1CD0 != 0) {
                t = 1;
            }
            Unk801527C8_Team* team = &mC->m6F8->m14->m0[t];
            int* slot = fn_80161A5C(sel, fn_800968C0(team, fn_80097300(team, fn_80097190(team, 1)), 1));
            *slot = 1;
            m30C[sel] = 1;
            m4C = -1;
            m328 = m328 + 1;
        }
    }
}

void Unk80159F28::fn_8016482C() /* 8016482C */
{
    Unk80359ACC* p = &m5F4;
    p->m0 = 0;
    p->m4 = lbl_8062087C;
    p->m8 = 0;
    p->mC = 0;
    p->m10 = 0;
    p->m14 = 0;
    p->m18 = 0;
    lbl_8062151C = 0;
    lbl_8061C3A4 = -1;
    lbl_8061C3A8 = 0;
}

void Unk80159F28::fn_80164878() /* 80164878 */
{
}

extern int lbl_8061BE34[];
extern int lbl_805C9758[];
extern int lbl_8061C0EC[];

void Unk80159F28::fn_80164CEC() /* 80164CEC */
{
    int c = m5F4.m10 + 1;
    m5F4.m10 = c;
    int k = m5F4.m4;
    if (c >= lbl_8061BE34[k]) {
        m5F4.m10 = 0;
        int d = m5F4.m8 + 1;
        m5F4.m8 = d;
        if (!(d < lbl_805C9758[k])) {
            m5F4.m8 = 0;
            int flag = 0;
            if (lbl_8061C0EC[k] != 0 && m5F4.mC == 0) {
                m5F4.mC = 1;
            } else {
                flag = 1;
            }
            if (flag != 0) {
                m5F4.mC = 0;
                int i = m5F4.m4 + 1;
                if (i <= 0xAE) {
                    m5F4.m4 = i;
                    if (!(lbl_8061BE34[i] > 0)) {
                        do {
                            i++;
                            if (i > 0xAE) {
                                break;
                            }
                            m5F4.m4 = i;
                        } while (lbl_8061BE34[i] <= 0);
                    }
                }
            }
        }
    }
}

extern "C" void fn_8016487C(Unk80159F28* self);
extern "C" void fn_80162264(Unk80159F28* self);
extern "C" void fn_801597F0(Unk80159F28* self);
extern "C" void fn_8016645C(Unk80159F28* self, int a);
inline float Secs(unsigned int n) { return (float)n * 0.016666668f; }

void Unk80159F28::fn_80164DDC() /* 80164DDC */
{
    fn_8016487C(this);
    if (!(m330 <= 0.0f)) {
        if (!(Secs(*(unsigned int*)&mC->m4C) <= m330)) {
            fn_80162264(this);
        }
    }
    if (!(m334 <= 0.0f)) {
        if (!(Secs(*(unsigned int*)&mC->m4C) <= m334)) {
            fn_801597F0(this);
        }
    }
    if (!(m338 <= 0.0f)) {
        if (!(Secs(*(unsigned int*)&mC->m4C) <= m338)) {
            int r = 0;
            if (mC->m6F8->m14->m1CD0 != 0) {
                r = 1;
            }
            fn_8016645C(this, r ^ 1);
        }
    }
}

void Unk80159F28::fn_80164F48(Unk801654F0_Evt* e, float t) /* 80164F48 */
{
    if (*(int*)((char*)e + 0x14) != 0) {
        fn_80165010(e);
    } else {
        int k = fn_801DC10C(mC->m700->m3B8);
        int is = 0;
        if (k == 0xB || k == 0xD) {
            is = 1;
        }
        if (is != 0) {
            if (fn_80259330(mC->m700->m3B4) == 0) {
                m330 = (float)*(unsigned int*)&mC->m4C * 0.016666668f + 1.0f;
            }
        }
    }
}

void Unk80159F28::fn_80165328(Unk80165328_Evt* e, float t) /* 80165328 */
{
    Unk801527C8_Sub* s = &mC->m50;
    s->fn_80326EF4(t, 0.0f, 0x3D, -1, -1, 0);
    float u = t + e->m10;
    s->fn_80326EF4(u, 0.0f, 0xAC, -1, -1, 0);
}

/* near-miss: 80/80 insns, instruction stream identical; retail's frame is 40 bytes (the 12-byte vector keeps 4-byte alignment), ours 48 */
void Unk80159F28::fn_801653B0(int id, float t) /* 801653B0 */
{
    float x;
    Unk80273498_Vec3 v;
    Unk80273498_Vec3* pv = &v;
    fn_8022EA60(pv, mC->m700->m3B0);
    if (fn_8015F840() != 0) {
        v.x = -v.x;
    }
    int g = v.x + pv->y > 0.0f;
    x = lbl_805EBA00;
    int flags;
    if (!(v.x - pv->y <= 0.0f)) {
        if (g) {
            flags = 0x8000;
            x = v.x - 1.0f;
        } else {
            flags = 0x2000;
            x = -pv->y - 1.0f;
        }
    } else {
        if (g) {
            flags = 0x1000;
            x = pv->y - 1.0f;
        } else {
            flags = 0x4000;
            x = -v.x - 1.0f;
        }
    }
    if (id == 0x41) {
        x = -x;
    }
    mC->m50.fn_80326EF4(t, x, id, -1, -1, flags);
}

void Unk80159F28::fn_801654F0(Unk801654F0_Evt* e, float t) /* 801654F0 */
{
    if (e->m8 == 2) {
        mC->m50.fn_80326EF4(t, 0.0f, 0xAF, -1, -1, 0);
    } else if (e->m8 == 1) {
        mC->m50.fn_80326EF4(t, 0.0f, 0xB0, -1, -1, 0);
    }
}

void Unk80159F28::fn_80165578(Unk80165578_Evt* e, float t) /* 80165578 */
{
    Unk80165578_Obj* o = (Unk80165578_Obj*)fn_801A49F0(mC, e->mC, e->m8);
    if (o != 0 && o->m458 == 0) {
        mC->m50.fn_80326EF4(t, 0.0f, 0x79, 0, -1, 0);
    }
}

class Unk80069F0C {
public:
    int fn_8006BDCC();
};
struct Unk801655F0_Rec {
    char pad0[0x1CC8];
    unsigned char m1CC8;
    char pad1CC9;
    unsigned char m1CCA;
    unsigned char m1CCB;
};
struct Unk801655F0_Mgr {
    char pad0[0x14];
    Unk801655F0_Rec* m14;
};
struct Unk801655F0_Ent564 {
    char pad0[0x14];
    int m14;
};
struct Unk801655F0_Ent3C8 {
    char pad0[0x5C];
    int m5C;
};
struct Unk801655F0_Slots {
    char pad0[0x3C8];
    Unk801655F0_Ent3C8* m3C8;
};
struct Unk801655F0_Act {
    char pad0[0x564];
    Unk801655F0_Ent564* m564;
    char pad568[0x6F8 - 0x568];
    Unk801655F0_Mgr* m6F8;
    char pad6FC[4];
    Unk801655F0_Slots* m700;
};

void Unk80159F28::fn_801655F0(Unk801655F0_Evt* e) /* 801655F0 */
{
    Unk801655F0_Act* a = (Unk801655F0_Act*)mC;
    int flag = 0;
    int state = a->m564->m14;
    if (state == 9 || ((Unk80069F0C*)a->m6F8)->fn_8006BDCC() != 0) {
        flag = 1;
    }
    if (state == 10 && ((Unk801655F0_Act*)mC)->m6F8->m14->m1CC8 == 0) {
        flag = 1;
    }
    if (flag == 0) {
        int k = e->m10->m458;
        if (k == 0) {
            m14 = 1;
            m18 = 1;
            if (e->m14 != 0) {
                m18 = k;
            }
            if (e->m10->m4C4 & 0x20000000) {
                m18 = k;
            }
            if (state == 10) {
                m18 = k;
            }
            Unk801655F0_Act* b = (Unk801655F0_Act*)mC;
            Unk801655F0_Rec* r = b->m6F8->m14;
            int sum = r->m1CCB + r->m1CCA;
            if (sum == 0 && b->m700->m3C8->m5C <= 1) {
                m18 = sum;
            }
        }
        if (e->m10->m458 == 0xA) {
            m1C = 1;
        }
        if (e->m10->m458 == 0xB) {
            m20 = 1;
        }
        if (e->m10->m458 == 0xC) {
            m24 = 1;
        }
    }
}

void Unk80159F28::fn_80165738(Unk801654F0_Evt* e, float t) /* 80165738 */
{
    mC->m50.fn_80326EF4(t, lbl_805EBA00, 0x64, -1, -1, (e->m8 == 1) << 16);
}

void Unk80159F28::fn_80165790(Unk80165790_Evt* e, float t) /* 80165790 */
{
    Unk801527C8_Sub* s = &mC->m50;
    int fl = 0;
    if (e->mC != 0) {
        fl = 0x20000;
    }
    s->fn_80326EF4(t, lbl_805EBA00, 0x8D, e->m8->m458, -1, fl);
}

void Unk80159F28::fn_801657EC(Unk801657EC_Evt* e, float t) /* 801657EC */
{
    mC->m50.fn_80326EF4(t, 0.0f, 0x68, -1, e->m8, 0);
}

/* near-miss: same code; retail loads the float constant (0.0f) after the two int operands, here it is hoisted above them; 4 variants tried */
void Unk80159F28::fn_80165834(Unk80165834_Evt* e, float t) /* 80165834 */
{
    int id = e->mC->m458;
    int b = e->m8;
    mC->m50.fn_80326EF4(t, 0.0f, 0x7F, id, b, 0);
}

/* near-miss: same code; retail loads e->m8 before the float constant for the last call (2 instructions swapped); 6 variants tried */
void Unk80159F28::fn_80165884(Unk80165884_Evt* e, float t) /* 80165884 */
{
    int m10 = e->m10;
    Unk801527C8_Actor* a = mC;
    Unk801527C8_Sub* s = &a->m50;
    int k = 0;
    if (a->m6F8->m14->m1CD0 != 0) {
        k = 1;
    }
    Unk80165578_Obj* o = (Unk80165578_Obj*)fn_801A4910(a, k, m10);
    if (o != 0) {
        int id = o->m458;
        int b = e->m8;
        s->fn_80326EF4(t, 0.0f, 0x5F, id, b, 0);
    }
}

void Unk80159F28::fn_80165908(Unk80165834_Evt* e, float t) /* 80165908 */
{
    Unk801527C8_Sub* s = &mC->m50;
    float x = lbl_805EBA00;
    if (!(e->m18 < 0.0f)) {
        x = -e->m18;
    }
    s->fn_80326EF4(t, x, 0x62, e->mC->m458, e->m8, 0);
}

void Unk80159F28::fn_80165978(Unk80165978_Evt* e, float t) /* 80165978 */
{
    int flags = 0;
    Unk801527C8_Sub* s = &mC->m50;
    int a = e->mC->m458;
    int b = e->m44;
    float kk = e->m1C;
    int id;
    if ((unsigned int)(a - 0xF) > 1) {
        if (e->m20 != 0) {
            if (e->m28 != 0) {
                flags = 4;
            }
            id = 0xAD;
        } else {
            const float lim = 0.1f;
            Unk80326F44_Out out = s->fn_80326F44(0x42, 1, -1.0f);
            int v = 1;
            if (out.m0 == 0xC7) {
                v = 0;
            }
            if (v != 0 && e->mC->m458 == 1 && (t - out.m4) < lim) {
                return;
            }
            id = 0xAE;
        }
        int m = e->m8;
        if (m == 0xA) {
            flags |= 1;
        }
        if (m == 6 || m == 8) {
            flags |= 0x10;
        }
        if (m == 7) {
            flags |= 0x80;
        }
        if (m == 5) {
            flags |= 0x40;
        }
        if (m == 2 || m == 4) {
            flags |= 0x20;
        }
        if (e->m24 != 0) {
            flags |= 2;
        }
        if (e->m3C != 0) {
            flags |= 0x100;
        }
        s->fn_80326EF4(t, kk, id, a, b, flags);
    }
}

void Unk80159F28::fn_80165AF4(Unk80165AF4_Evt* e, float t) /* 80165AF4 */
{
    Unk801527C8_Sub* s = &mC->m50;
    float x = lbl_805EBA00;
    int id = 0xAD;
    if (e->mC == 0) {
        x = 0.0f;
        id = 0xAE;
    }
    s->fn_80326EF4(t, x, id, e->m8->m458, -1, 0x200);
}

void Unk80159F28::fn_80165B68(Unk80165B68_Evt* e, float t) /* 80165B68 */
{
    int id = e->m8->m458;
    if ((unsigned int)(id - 0xF) > 1) {
        Unk801527C8_Sub* s = &mC->m50;
        int fl = 0;
        if (e->m18 != 0) {
            fl = 0x800;
        }
        if (e->m1C != 0) {
            fl |= 0x400;
        }
        s->fn_80326EF4(t, lbl_805EBA00, 0x57, id, -1, fl);
    }
}

/* near-miss: scheduling of the leading loads (e->m14 before the team pointer) differs; not retried */
void Unk80159F28::fn_80165BE0(Unk80165BE0_Evt* e, float t) /* 80165BE0 */
{
    Unk801527C8_Actor* a = mC;
    Unk801527C8_Sub* s = &a->m50;
    int k = 0;
    if (a->m6F8->m14->m1CD0 != 0) {
        k = 1;
    }
    int id = ((Unk80165578_Obj*)fn_801A4910(a, k, e->m14))->m458;
    int n = e->mC;
    if (e->m8 == 3) {
        if (n > fn_8014E310(id)) {
            s->fn_80326EF4(t, 0.0f, 0x60, id, n, 0);
        }
    }
    float x = lbl_805EBA00;
    if (!(e->m1C < 0.0f)) {
        x = -e->m1C;
    }
    s->fn_80326EF4(t, x, 0x39, id, e->mC, 0);
}

int Unk80159F28::fn_80165CC8() /* 80165CC8 */
{
    Unk801527C8_Actor* a = mC;
    int r = 0;
    Unk801527C8_Mgr* m = a->m6F8;
    Unk801527C8_Teams* t = m->m14;
    int k = 0;
    if (t->m1CD0 != 0) {
        k = 1;
    }
    Unk801527C8_Team* tm = t->m0 + k;
    if (tm->mD70 > 1 && m->mC->m84 == 0) {
        float p = 1.0f;
        const char* file = lbl_805C8C20;
        unsigned int n = a->m554->fn_8014D8AC(1000000, file, 0x1359);
        if (!((float)n * p * 0.000001f < 0.8f)) {
            r = 1;
        }
    }
    return r;
}

void Unk80159F28::fn_80165DA8(int p, Unk8015FB08_Rec rec) /* 80165DA8 */
{
    int c = fn_80165CC8();
    if (fn_8015F840() != 0) {
        if (c != 0) {
            fn_8015FB08(0x77, p, rec);
        } else {
            fn_8015FB08(0xA5, p, rec);
        }
    } else {
        if (c != 0) {
            fn_8015FB08(0x78, p, rec);
        } else {
            fn_8015FB08(0xA6, p, rec);
        }
    }
}

void Unk80159F28::fn_80165F94(int p, Unk8015FB08_Rec rec) /* 80165F94 */
{
    if (fn_8015F840() != 0) {
        fn_8015FB08(0x7D, p, rec);
    } else {
        fn_8015FB08(0x7E, p, rec);
    }
}

void Unk80159F28::fn_801660A4(int p, Unk8015FB08_Rec rec) /* 801660A4 */
{
    float a, b, c;
    fn_8018CA5C(mC->m6CC, &a, &b, &c);
    if (!(a <= 0.78539824f)) {
        fn_8015FB08(0x70, p, rec);
    } else {
        fn_8015FB08(0x71, p, rec);
    }
}

void Unk80159F28::fn_801661D8(int p, Unk8015FB08_Rec rec) /* 801661D8 */
{
    float a, b, c;
    fn_8018CA5C(mC->m6CC, &a, &b, &c);
    if (!(a <= 0.78539824f)) {
        fn_8015FB08(0x72, p, rec);
    } else {
        fn_8015FB08(0x73, p, rec);
    }
}

void Unk80159F28::fn_8016630C(int p, Unk8015FB08_Rec rec) /* 8016630C */
{
    float a, b, c;
    fn_8018CA5C(mC->m6CC, &a, &b, &c);
    if (!(a <= 0.78539824f)) {
        fn_8015FB08(0x74, p, rec);
    } else {
        fn_8015FB08(0x75, p, rec);
    }
}

int fn_80166440(void* self, int v) /* 80166440 */
{
    switch (v) {
    case 0x31:
    case 0x32:
        return 1;
    }
    return 0;
}

/* Sum of the 128 bytes at Row+0x1B4 (row pointer taken as a parameter: see Unk8001D47C_SumRow). */
struct Unk80166E40_Row {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
};
inline int Unk80166E40_SumRow(Unk80166E40_Row* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->m1B4[(unsigned char)i];
    }
    return s;
}
struct Unk80166E40_G {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk80166E40_T {
    char pad0[0x14];
    Unk80166E40_G* m14;
};
class Unk80166E40_Obj {
public:
    char pad0[0x98];
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
};
struct Unk80166E40_A {
    char pad0[0x6B8];
    void* m6B8;
    char pad6BC[0x6CC - 0x6BC];
    Unk80166E40_Obj* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Unk80166E40_T* m6F8;
    char pad6FC[0x704 - 0x6FC];
    char m704[0x1C];
};
struct Unk80166E40_S {
    char pad0[0xC];
    Unk80166E40_A* mC;
    char pad10[0x48 - 0x10];
    int m48;
};
/* Event posted with fn_8037893C: id at +0, vptr at +4 (base vtable lbl_80649DA0, derived lbl_8065EA28). */
class Unk80166E40_EvBase {
public:
    Unk80166E40_EvBase(int id) { m0 = id; }
    int m0;
    virtual ~Unk80166E40_EvBase() {}
};
class Unk80166E40_Ev : public Unk80166E40_EvBase {
public:
    Unk80166E40_Ev() : Unk80166E40_EvBase(0xA4)
    {
        mC = 0;
        m10 = 2;
        m8 = 4;
    }
    virtual ~Unk80166E40_Ev() {}
    int m8;
    int mC;
    int m10;
};
int fn_80166BD0(void* self);
void fn_80166FEC(void* self, int a, int b, int c, int d);
int fn_8018240C(void* p, int f);
int fn_803EE348(int a);
void fn_80303CA0(const char* s, float a, float b, float c, ...);
extern "C" void fn_8037893C(void* q, int id, void* e, int a, int b);

/* near-miss (99.6%): only the first SumRow loop differs. Retail holds the byte index in r9, the element
 * address in r11 and the counter in r10 (as in the second loop, which matches); here the index shares r0
 * with the loaded byte, the address is r9 and the counter r11. Same open SumRow register-choice family
 * as fn_80361FCC / fn_8001F788; ~25 row-pointer, statement-order and loop-body forms left it unchanged. */
void fn_80166E40(void* self) /* 80166E40 */
{
    Unk80166E40_S* s = (Unk80166E40_S*)self;
    if (fn_803EE348(0) > 0x1B7FF && s->m48 != 1) {
        s->mC->m6CC->fn_vslot8(1);
        int n = fn_80166BD0(self);
        fn_80303CA0("End of game intensity %d", 4.0f, 0.4f, 0.4f, n + 1);
        Unk80166E40_G* g = s->mC->m6F8->m14;
        int x = Unk80166E40_SumRow((Unk80166E40_Row*)g);
        int y = Unk80166E40_SumRow((Unk80166E40_Row*)((char*)g + 0xE64));
        int le = x <= y;
        int c = 0;
        if (le == 0) {
            c = g->m1CD0 == 1;
        }
        fn_80166FEC(self, n, le, c, fn_8018240C(s->mC->m6B8, le));
        Unk80166E40_Ev e;
        fn_8037893C(s->mC->m704, e.m0, &e, 0, 0);
    }
}
