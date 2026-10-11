/*
 * Game code, .text 0x80163390-0x80167DCC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80163390.h"

extern float lbl_805C9204;
extern float lbl_805C9208;

extern float lbl_805C9248;
extern float lbl_805C924C;
extern float lbl_805C9250;

extern const char lbl_805C8C20[];
extern float lbl_805C91D8;
extern float lbl_805C91DC;
extern float lbl_805C9234;
extern float lbl_805C9240;
extern float lbl_805C9244;

extern float lbl_805C9200;
extern float lbl_805C920C;
extern float lbl_805C9210;
extern float lbl_805C9214;
extern float lbl_805C9218;
extern float lbl_805C921C;
extern float lbl_805C9220;
extern float lbl_805C922C;
extern float lbl_805C9230;

extern float lbl_805EBA00;
extern int lbl_8062087C;
extern int lbl_8061C3A4;
extern int lbl_8061C3A8;
extern int lbl_8062151C;
int fn_801DC10C(void* p);
int fn_80259330(void* p);
void fn_8016C4A0(void* p);
void fn_80327214(Unk801527C8_Sub* s);
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
                m330 = (float)*(unsigned int*)&mC->m4C * lbl_805C91D8 + lbl_805C91DC;
            }
        }
    }
}

void Unk80159F28::fn_80165328(Unk80165328_Evt* e, float t) /* 80165328 */
{
    Unk801527C8_Sub* s = &mC->m50;
    s->fn_80326EF4(t, lbl_805C9200, 0x3D, -1, -1, 0);
    float u = t + e->m10;
    s->fn_80326EF4(u, lbl_805C9200, 0xAC, -1, -1, 0);
}

/* near-miss: structure differs (retail computes the (x+y > c) flag once into an int before the branches); 3 forms tried */
void Unk80159F28::fn_801653B0(int id, float t) /* 801653B0 */
{
    Unk80273498_Vec3 v;
    fn_8022EA60(&v, mC->m700->m3B0);
    if (fn_8015F840() != 0) {
        v.x = -v.x;
    }
    int g = v.x + v.y > lbl_805C9204;
    float x = lbl_805EBA00;
    int flags;
    if (!(v.x - v.y <= lbl_805C9204)) {
        if (g) {
            flags = 0x8000;
            x = v.x - lbl_805C9208;
        } else {
            flags = 0x2000;
            x = -v.y - lbl_805C9208;
        }
    } else {
        if (g) {
            flags = 0x1000;
            x = v.y - lbl_805C9208;
        } else {
            flags = 0x4000;
            x = -v.x - lbl_805C9208;
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
        mC->m50.fn_80326EF4(t, lbl_805C920C, 0xAF, -1, -1, 0);
    } else if (e->m8 == 1) {
        mC->m50.fn_80326EF4(t, lbl_805C920C, 0xB0, -1, -1, 0);
    }
}

void Unk80159F28::fn_80165578(Unk80165578_Evt* e, float t) /* 80165578 */
{
    Unk80165578_Obj* o = (Unk80165578_Obj*)fn_801A49F0(mC, e->mC, e->m8);
    if (o != 0 && o->m458 == 0) {
        mC->m50.fn_80326EF4(t, lbl_805C9210, 0x79, 0, -1, 0);
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
    mC->m50.fn_80326EF4(t, lbl_805C9214, 0x68, -1, e->m8, 0);
}

/* near-miss: same code; retail loads the float constant (lbl_805C9218) after the two int operands, here it is hoisted above them; 4 variants tried */
void Unk80159F28::fn_80165834(Unk80165834_Evt* e, float t) /* 80165834 */
{
    int id = e->mC->m458;
    int b = e->m8;
    mC->m50.fn_80326EF4(t, lbl_805C9218, 0x7F, id, b, 0);
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
        s->fn_80326EF4(t, lbl_805C921C, 0x5F, id, b, 0);
    }
}

/* near-miss: same code; scheduling of the lis/lwz pair for mC and the constants differs (6 diff lines); 4 variants tried */
void Unk80159F28::fn_80165908(Unk80165834_Evt* e, float t) /* 80165908 */
{
    Unk801527C8_Sub* s = &mC->m50;
    float x = lbl_805EBA00;
    if (!(e->m18 < lbl_805C9220)) {
        x = -e->m18;
    }
    s->fn_80326EF4(t, x, 0x62, e->mC->m458, e->m8, 0);
}

void Unk80159F28::fn_80165AF4(Unk80165AF4_Evt* e, float t) /* 80165AF4 */
{
    Unk801527C8_Sub* s = &mC->m50;
    float x = lbl_805EBA00;
    int id = 0xAD;
    if (e->mC == 0) {
        x = lbl_805C922C;
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
            s->fn_80326EF4(t, lbl_805C9230, 0x60, id, n, 0);
        }
    }
    float x = lbl_805EBA00;
    if (!(e->m1C < lbl_805C9230)) {
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
        float p = lbl_805C9234;
        const char* file = lbl_805C8C20;
        unsigned int n = a->m554->fn_8014D8AC(1000000, file, 0x1359);
        if (!((float)n * p * lbl_805C9240 < lbl_805C9244)) {
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
    if (!(a <= lbl_805C9248)) {
        fn_8015FB08(0x70, p, rec);
    } else {
        fn_8015FB08(0x71, p, rec);
    }
}

void Unk80159F28::fn_801661D8(int p, Unk8015FB08_Rec rec) /* 801661D8 */
{
    float a, b, c;
    fn_8018CA5C(mC->m6CC, &a, &b, &c);
    if (!(a <= lbl_805C924C)) {
        fn_8015FB08(0x72, p, rec);
    } else {
        fn_8015FB08(0x73, p, rec);
    }
}

void Unk80159F28::fn_8016630C(int p, Unk8015FB08_Rec rec) /* 8016630C */
{
    float a, b, c;
    fn_8018CA5C(mC->m6CC, &a, &b, &c);
    if (!(a <= lbl_805C9250)) {
        fn_8015FB08(0x74, p, rec);
    } else {
        fn_8015FB08(0x75, p, rec);
    }
}

inline int InRange(int v, int lo, int hi)
{
    if (v > hi) {
        return 0;
    }
    return v >= lo;
}

int fn_80166440(void* self, int v) /* 80166440 */
{
    return InRange(v, 0x31, 0x32);
}
