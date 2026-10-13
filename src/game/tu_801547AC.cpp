/*
 * Game code, .text 0x801547AC-0x80156714 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801527C8.h"
#include "game/goals/tu_8028C6B8.h"
#include "game/goals/tu_8027A84C.h"

extern float lbl_805C88D4;

extern const char lbl_805C85FC[];
extern float lbl_805C8630;
extern float lbl_805C8640;

extern float lbl_805C8514;
extern float lbl_805C8518;
extern float lbl_805C851C;

extern float lbl_805C8418;
extern float lbl_805C84F4;
extern float lbl_805C8580;
extern float lbl_805C8978;

struct Unk80178BBC_T;
Unk8016C788_Obj* fn_80178E6C(Unk80178BBC_T* sl, unsigned a, unsigned b);
struct Unk8016C1C4_List {
    int fn_8016C798(int idx);
    Unk8016C788_Obj* fn_8016C788(int idx);
};
class Vt80155A0 {
public:
    char pad0[0x18];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
};
struct Obj708 {
    char pad0[0x708];
    int m708;
};

struct Unk802A2DA4_Goal;
void fn_802A2DC0(Unk802A2DA4_Goal* g, float t);

struct Unk8014E388 {
    char pad0[0x10];
};
extern Unk80619D10* lbl_80619D10;
void fn_8016B8CC(void* o, int v);
void fn_8014E388(Unk8014E388* b, int v);
Unk8027C728_Goal* fn_801B9438(Unk8016C788_Obj* o, int v, Unk8014E388* b);
void fn_802D5618(void* o);
void fn_802D59C0(void* o, int a, int b);
void* fn_801A4CE8(Unk801527C8_Actor* a, int i);
void fn_802D57E4(void* o, int a, int b, int c, int d);
void fn_8031E1A0(Unk801527C8_Actor* a, int v);
void* fn_801A6D84(Unk801527C8_Actor* a, int i);
int fn_8031C6A8();
void fn_8031C6C0(int a, int b, int c, int d);

extern const char lbl_805C5FD4[];
extern const char lbl_805C7518[];
extern const char lbl_805C7530[];
extern const char lbl_805C7540[];
extern const char lbl_805C7544[];
extern const char lbl_805C7548[];
extern const char lbl_805C755C[];
extern const char lbl_805C7564[];
extern const char lbl_805C7574[];
extern const char lbl_805C7580[];
extern const char lbl_805C758C[];
extern const char lbl_805C75A0[];
extern const char lbl_805C7A38[];
extern const char lbl_805C7AA8[];
extern const char lbl_805C7B78[];
extern float lbl_805C8334;
extern const char lbl_805C8338[];
extern const char lbl_805C8344[];
extern const char lbl_805C834C[];
extern const char lbl_805C8354[];
extern const char lbl_805C835C[];
extern const char lbl_805C8374[];
extern const char lbl_805C837C[];
extern const char lbl_805C8388[];
extern const char lbl_805C8394[];
extern const char lbl_805C83AC[];
extern const char lbl_805C83BC[];
extern const char lbl_805C83D4[];
extern const char lbl_805C83E8[];
extern const char lbl_805C83F8[];
extern float lbl_805C8434;
extern const char lbl_805C8438[];
extern const char lbl_805C8444[];
extern const char lbl_805C844C[];
extern const char lbl_805C845C[];
extern const char lbl_805C8468[];
extern const char lbl_805C8470[];
extern const char lbl_805C847C[];
extern const char lbl_805C8488[];
extern const char lbl_805C8498[];
extern const char lbl_805C84A4[];
extern const char lbl_805C84B0[];
extern const char lbl_805C84C0[];
extern const char lbl_805C84CC[];
extern const char lbl_805C84E0[];
extern float lbl_805C8530;
extern const char lbl_805C8534[];
extern const char lbl_805C8544[];
extern const char lbl_805C8554[];
extern const char lbl_805C8560[];
extern const char lbl_805C856C[];
extern const char lbl_805C8578[];
extern const char lbl_805C85A8[];
extern float lbl_805C85C8;
extern const char lbl_805C85CC[];
extern const char lbl_805C85D8[];
extern const char lbl_805C85E4[];
extern const char lbl_805C8650[];
extern const char lbl_805C8658[];
extern const char lbl_805C869C[];
extern const char lbl_805C86A4[];
extern const char lbl_805C86B0[];
extern const char lbl_805C86C0[];
extern const char lbl_805C86CC[];
extern const char lbl_805C86D8[];
extern const char lbl_805C86F8[];
extern const char lbl_805C8868[];
extern const char lbl_805C8880[];
extern const char lbl_805C8890[];
extern const char lbl_805C8898[];
extern const char lbl_805C88A4[];
extern const char lbl_805C88B8[];
extern const char lbl_805C8954[];
extern const char lbl_805C8964[];
extern const char lbl_805C8974[];
extern float lbl_805C8984;
extern const char* lbl_8061BD84;
extern const char* lbl_8061BE0C;
extern const char* lbl_8061BE24;
extern const char* lbl_8061BE28;
extern const char* lbl_8061BE2C;
extern unsigned int lbl_8068B7D8;

extern const char lbl_805C626C[];

extern const char lbl_805C7F90[];
extern const char lbl_805C805C[];
extern const char lbl_805C824C[];

extern const char lbl_805C7994[];

extern const char lbl_805C60F8[];
extern const char lbl_805C6240[];
extern const char lbl_805C7988[];

Unk801527C8_Actor* fn_801A04A8(Unk801527C8_Actor* a, int i);

inline void SetM4C(Unk8061FEDC_Obj* o, float v)
{
    o->m40.mC = v;
}

int cScriptIdleGoal::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 801547AC */
{
    Unk8016C788_Obj* o = fn_8016C788(ctx, a);
    if (o != 0) {
        Unk8027C728_Goal* g = fn_802448F4(o, 1);
        g->m10 = 2;
        fn_8027C728(g);
        char* b = g->m18;
        *(int*)(b + 0x34) = m4;
        *(int*)(b + 0x38) = m8;
        *(int*)(b + 0x40) = mC;
        ((Unk80287D70*)b)->fn_80287DB8(m10);
        fn_8015152C(o, g);
    }
}

Unk8037B3E8* cScriptIdleGoal::fn_vslot5() /* 80154844 */
{
    return new (lbl_806EF9B4) cScriptIdleGoal;
}

cScriptReachGoal::cScriptReachGoal() : Unk80359B48(0x88EC4E63u) /* 80154874 */
{
    m10 = lbl_805C8334;
    m14 = 0;
    m18 = 0;
    m1C = 0;
    m20 = 0;
    m24 = lbl_805C8334;
}

void cScriptReachGoal::fn_vslot2() /* 801548DC */
{
    fn_8037B7E8(lbl_805C8338);
    fn_8037B50C(lbl_805C8344, &m4, lbl_805C7530, 0);
    fn_8037B50C(lbl_805C834C, &m8, lbl_805C7530, 0);
    fn_8037B50C(lbl_805C8354, &mC, lbl_805C7530, 0);
    fn_8037B548(lbl_805C7548, lbl_805C835C);
    fn_8037B548(lbl_805C7564, lbl_805C835C);
    fn_8037B7E8(lbl_805C8374);
    fn_8037B458(lbl_805C837C, &m18, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C8388, &m1C, lbl_805C8394);
    fn_8037B830(lbl_805C8374);
    fn_8037B830(lbl_805C8338);
    fn_8037B7E8(lbl_805C83AC);
    fn_8037B458(lbl_805C83BC, &m20, lbl_805C60F8, lbl_805C6240);
    fn_8037B50C(lbl_805C83D4, &m24, lbl_805C7988, lbl_805C6240);
    fn_8037B830(lbl_805C83AC);
    fn_8037B7E8(lbl_805C83E8);
    fn_8037B50C(lbl_805C7574, &m10, lbl_805C7580, 0);
    fn_8037B548(lbl_805C758C, lbl_805C7574);
    fn_8037B548(lbl_805C75A0, lbl_805C7574);
    fn_8037B830(lbl_805C83E8);
    fn_8037B674(lbl_805C824C, &m14, lbl_8061BE24, 0);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C83F8);
}

int cScriptReachGoal::fn_cslot8() /* 80154AF8 */
{
    int n = m1C - 1;
    m8 = lbl_805C8418;
    m1C = n;
    if (n < 0) {
        m1C = 3;
    }
}

/* Goal object at Unk8027C728_Goal::m18 (full layout in goals/tu_8028B194.h, which clashes with tu_8028C6B8.h): m38 and the setters used by cScriptReachGoal::fn_cslot11. */
class Unk8028B194 {
public:
    char pad0[0x38];
    int m38;
    Unk8028B194* fn_8028B194(Unk80273498_Vec3 v);
    Unk8028B194* fn_8028B1F0(int a);
    void fn_8028B31C(int id);
    Unk8028B194* fn_8028B51C(float a);
};
extern float lbl_805C841C;
extern float lbl_805C8420;
extern "C" float fn_8041171C(float x);
extern "C" float fn_80411554(float x);
inline void SetDir(Unk8027A84C* o, Unk80273498_Vec3 v)
{
    o->fn_8027A898(&v);
}
inline Unk80273498_Vec3 Direction(float angle)
{
    Unk80273498_Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = lbl_805C8420;
    r.z = fn_80411554(angle);
    return r;
}

int cScriptReachGoal::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80154B24 */
{
    Unk8016C788_Obj* o = fn_8016C788(ctx, a);
    if (o != 0) {
        Unk8027C728_Goal* g = fn_802448F4(o, 1);
        g->m10 = 10;
        fn_8027C728(g);
        Unk8028B194* b = (Unk8028B194*)g->m18;
        if (m18 != 0) {
            b->fn_8028B1F0(m1C);
        } else {
            b->fn_8028B194(*(Unk80273498_Vec3*)&m4);
        }
        Unk80273498_Vec3 v = Direction(m10 * lbl_805C841C);
        SetDir((Unk8027A84C*)b, v);
        if (m14 == 0x1A) {
            b->fn_8028B31C(0);
        } else {
            b->fn_8028B31C(m14);
        }
        if (m20 != 0) {
            b->fn_8028B51C(m24);
        }
        b->m38 = 3;
        fn_8015152C(o, g);
    }
}

Unk8037B3E8* cScriptReachGoal::fn_vslot5() /* 80154C9C */
{
    return new (lbl_806EF9B4) cScriptReachGoal;
}

cScriptReplay::cScriptReplay() : Unk80359B48(0x2916F5EAu) /* 80154CCC */
{
    m4 = 0;
    m10 = lbl_805C8434;
    m18 = 0;
    m8 = 0;
    mC = 0;
}

void cScriptReplay::fn_vslot2() /* 80154D38 */
{
    fn_8037B7E8(lbl_805C8438);
    fn_8037B458(lbl_805C8444, &m4, lbl_805C60F8, lbl_805C7A38);
    fn_8037B7E8(lbl_805C844C);
    fn_8037B458(lbl_805C845C, &m8, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C8468, &mC, lbl_8061BE0C);
    fn_8037B830(lbl_805C844C);
    fn_8037B50C(lbl_805C8470, &m10, lbl_805C847C, lbl_805C6240);
    fn_8037B830(lbl_805C8438);
    fn_8037B50C(lbl_805C8488, &m14, lbl_805C8498, lbl_805C7A38);
    fn_8037B7E8(lbl_805C84A4);
    fn_8037B458(lbl_805C84B0, &m18, lbl_805C60F8, lbl_805C6240);
    fn_8037B728(lbl_805C7B78, lbl_805C84C0, &m1C, lbl_805C84CC);
    fn_8037B830(lbl_805C84A4);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C84E0);
}

int cScriptReplay::fn_cslot8() /* 80154EB0 */
{
    m14 = m14 * lbl_805C84F4;
    if (m18 == 0) {
        m1C.fn_8033CD74();
    }
}

inline void SetF(float* p, float v)
{
    *p = v;
}

int cScriptReplay::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155288 */
{
    Unk801527C8_Actor* act = ctx->mA54;
    float u = m14;
    if (m18 != 0) {
        float t = (f3 - f1) / f2;
        t = !(t > lbl_805C8514) ? (t >? lbl_805C8518) : lbl_805C8514;
        u = m1C.fn_8033CDC4(t) * lbl_805C851C;
    }
    SetF((float*)((char*)act + 0x50), u);
    return 1;
}

Unk8037B3E8* cScriptReplay::fn_vslot5() /* 80155348 */
{
    return new (lbl_806EF9B4) cScriptReplay;
}

cScriptRunGoal::cScriptRunGoal() : Unk80359B48(0x710FFB15u) /* 80155378 */
{
    m4 = 0;
    m14 = 0;
    m1C = lbl_805C8530;
    m18 = 0;
}

void cScriptRunGoal::fn_vslot2() /* 801553D8 */
{
    fn_8037B7E8(lbl_805C83AC);
    fn_8037B50C(lbl_805C8534, &m1C, lbl_805C8544, lbl_805C7A38);
    fn_8037B830(lbl_805C83AC);
    fn_8037B7E8(lbl_805C8554);
    fn_8037B458(lbl_805C8560, &m4, lbl_805C60F8, lbl_805C6240);
    fn_8037B830(lbl_805C8554);
    fn_8037B7E8(lbl_805C856C);
    fn_8037B50C(lbl_805C5FD4, &m8, lbl_805C7530, 0);
    fn_8037B50C(lbl_805C7540, &mC, lbl_805C7530, 0);
    fn_8037B50C(lbl_805C7544, &m10, lbl_805C7530, 0);
    fn_8037B548(lbl_805C7548, lbl_805C755C);
    fn_8037B548(lbl_805C7564, lbl_805C755C);
    fn_8037B830(lbl_805C856C);
    fn_8037B7E8(lbl_805C837C);
    fn_8037B458(lbl_805C8374, &m14, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C8388, &m18, lbl_805C8394);
    fn_8037B830(lbl_805C837C);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C8578);
}

int cScriptRunGoal::fn_cslot8() /* 80155590 */
{
    int n = m18 - 1;
    mC = lbl_805C8580;
    m18 = n;
    if (n < 0) {
        m18 = 3;
    }
}

int cScriptRunGoal::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 801555BC */
{
    int v = ((Unk8016C1C4_List*)ctx)->fn_8016C798(a);
    if (v == 0x39) {
        Unk80178BBC_T* l = (Unk80178BBC_T*)ctx->mA4C->m700->m3AC;
        for (int i = 0; i <= 7; ) {
            fn_801556A4(fn_80178E6C(l, 0, i++));
        }
    } else if (v == 0x3A) {
        Unk80178BBC_T* l = (Unk80178BBC_T*)ctx->mA4C->m700->m3AC;
        for (int i = 0; i <= 7; ) {
            fn_801556A4(fn_80178E6C(l, 1, i++));
        }
    } else {
        fn_801556A4(((Unk8016C1C4_List*)ctx)->fn_8016C788(a));
    }
}

void cScriptRunGoal::fn_801556A4(Unk8016C788_Obj* o) /* 801556A4 */
{
    if (o != 0) {
        Unk8027C728_Goal* g = fn_802448F4(o, 1);
        g->m10 = 4;
        fn_8027C728(g);
        Unk8028C6B8_Goal* gg = (Unk8028C6B8_Goal*)((char*)g + 0x18);
        gg->fn_8028F01C(m1C);
        gg->m34 = 1;
        if (m4 != 0) {
            gg->fn_8028EE4C(((Obj708*)o)->m708, 0);
            gg->fn_8028EEF4();
        } else if (m14 != 0) {
            gg->fn_8028EDD0(m18);
        } else {
            gg->fn_8028ED30(*(Unk80273498_Vec3*)&m8);
        }
        fn_8015152C(o, g);
        ((Vt80155A0*)((char*)o + 0xA0))->s13();
    }
}

Unk8037B3E8* cScriptRunGoal::fn_vslot5() /* 801557A0 */
{
    return new (lbl_806EF9B4) cScriptRunGoal;
}

cSpawnProcess::cSpawnProcess() : Unk80359B48(lbl_8068B7D8) /* 801557D0 */
{
    m4 = 0;
}

void cSpawnProcess::fn_vslot2() /* 8015581C */
{
    fn_8037B5C0(lbl_805C7F90, &m4, lbl_805C626C);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7F90);
}

int cSpawnProcess::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155878 */
{
    fn_8016B8CC(ctx->mA50, m4);
}

Unk8037B3E8* cSpawnProcess::fn_vslot5() /* 801558B0 */
{
    return new (lbl_806EF9B4) cSpawnProcess;
}

cScriptUmpireSignal::cScriptUmpireSignal() : Unk80359B48(0xD0D5A56Du) /* 801558E0 */
{
    m4 = 0;
}

void cScriptUmpireSignal::fn_vslot2() /* 8015592C */
{
    fn_8037B6B0(lbl_805C85A8, &m4, lbl_8061BD84);
}

int cScriptUmpireSignal::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155960 */
{
    if (m4 != 0) {
        Unk8016C788_Obj* o = fn_8016C788(ctx, a);
        if (o != 0) {
            Unk8014E388 buf;
            fn_8014E388(&buf, 3);
            fn_8015152C(o, fn_801B9438(o, m4, &buf));
        }
    }
}

Unk8037B3E8* cScriptUmpireSignal::fn_vslot5() /* 801559E0 */
{
    return new (lbl_806EF9B4) cScriptUmpireSignal;
}

cScriptWaitGoal::cScriptWaitGoal() : Unk80359B48(0x243A95F5u) /* 80155A10 */
{
    m4 = lbl_805C85C8;
    m8 = lbl_805C85C8;
    mC = lbl_805C85C8;
}

void cScriptWaitGoal::fn_vslot2() /* 80155A68 */
{
    fn_8037B50C(lbl_805C805C, &m4, lbl_805C85CC, 0);
    fn_8037B50C(lbl_805C85D8, &m8, lbl_805C85CC, 0);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C85E4);
}

int cScriptWaitGoal::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155AE8 */
{
    float d = (m8 - m4) >? lbl_805C8630;
    float k = d;
    const char* file = lbl_805C85FC;
    unsigned int n = ctx->mA4C->m554->fn_8014D8AC(1000000, file, 0x33);
    mC = (float)n * k * lbl_805C8640 + m4;
    Unk8016C788_Obj* o = fn_8016C788(ctx, a);
    if (o != 0) {
        Unk8027C728_Goal* g = fn_802448F4(o, 1);
        g->m10 = 9;
        fn_8027C728(g);
        fn_802A2DC0((Unk802A2DA4_Goal*)g->m18, mC);
        fn_8015152C(o, g);
    }
}

Unk8037B3E8* cScriptWaitGoal::fn_vslot5() /* 80155BF8 */
{
    return new (lbl_806EF9B4) cScriptWaitGoal;
}

cSetCamera::cSetCamera() : Unk80359B48(0x44DB939Du) /* 80155C28 */
{
    m4 = 0;
}

void cSetCamera::fn_vslot2() /* 80155C74 */
{
    fn_8037B5C0(lbl_805C8650, &m4, lbl_805C8658);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C8650);
}

int cSetCamera::fn_cslot8() /* 80155CD0 */
{
}

int cSetCamera::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155CD4 */
{
    void* o = ctx->mA54->m3C;
    fn_802D5618(o);
    fn_802D59C0(o, 1, m4);
}

Unk8037B3E8* cSetCamera::fn_vslot5() /* 80155D28 */
{
    return new (lbl_806EF9B4) cSetCamera;
}

cScriptPIP::cScriptPIP() : Unk80359B48(0x2C1A5FC6u) /* 80155D58 */
{
    m4 = 0;
    m8 = 0;
    m10 = 0;
    mC = 0;
}

void cScriptPIP::fn_vslot2() /* 80155DB0 */
{
    fn_8037B458(lbl_805C869C, &m4, 0, 0);
    fn_8037B7E8(lbl_805C86A4);
    fn_8037B5C0(lbl_805C86B0, &m8, lbl_805C86C0);
    fn_8037B5C0(lbl_805C86CC, &mC, lbl_805C86C0);
    fn_8037B830(lbl_805C86A4);
    fn_8037B7E8(lbl_805C7F90);
    fn_8037B5C0(lbl_805C86D8, &m10, lbl_805C626C);
    fn_8037B830(lbl_805C7F90);
}

int cScriptPIP::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155E78 */
{
    fn_802D57E4(fn_801A4CE8(ctx->mA4C, 1), m4, m8, mC, m10);
}

int cScriptPIP::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155ECC */
{
    return f3 >= f1 + f2;
}

Unk8037B3E8* cScriptPIP::fn_vslot5() /* 80155F04 */
{
    return new (lbl_806EF9B4) cScriptPIP;
}

cScriptViewport::cScriptViewport() : Unk80359B48(0x96C2CBDDu) /* 80155F34 */
{
    m4 = 0;
    m8 = 0;
}

void cScriptViewport::fn_vslot2() /* 80155F84 */
{
    fn_8037B458(lbl_805C869C, &m4, 0, 0);
    fn_8037B5C0(lbl_805C86F8, &m8, lbl_805C86C0);
}

int cScriptViewport::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80155FE0 */
{
    int v = m4;
    Unk801527C8_Actor* actor = ctx->mA4C;
    if (v != 0) {
        fn_801A04A8(actor, 1)->m4 = 1;
        fn_8031E1A0(fn_801A04A8(actor, 1), m8);
    } else {
        fn_801A04A8(actor, 1)->m4 = v;
    }
}

int cScriptViewport::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156060 */
{
    return 1;
}

Unk8037B3E8* cScriptViewport::fn_vslot5() /* 8015607C */
{
    return new (lbl_806EF9B4) cScriptViewport;
}

cSetOverlay::cSetOverlay() : Unk80359B48(0xAC7B7956u) /* 801560AC */
{
    m4 = 0;
}

void cSetOverlay::fn_vslot2() /* 801560F8 */
{
    fn_8037B674(lbl_805C8868, &m4, lbl_8061BE28, 0);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C8868);
}

int cSetOverlay::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156158 */
{
    void* p = ctx->mA50;
    if (p != fn_801A6D84(ctx->mA4C, 0)) {
        lbl_80619D10->fn_v23(m4);
    }
}

Unk8037B3E8* cSetOverlay::fn_vslot5() /* 801561CC */
{
    return new (lbl_806EF9B4) cSetOverlay;
}

cTeleportActor::cTeleportActor() : Unk80359B48(0xEE89A570u) /* 801561FC */
{
    m14 = 0;
    mC = 0;
    m24 = lbl_806055AC;
    m10 = 0;
}

void cTeleportActor::fn_vslot2() /* 80156274 */
{
    fn_8037B7E8(lbl_805C8880);
    fn_8037B5C0(lbl_805C8890, &m14, lbl_805C7518);
    fn_8037B458(lbl_805C8898, &mC, 0, 0);
    fn_8037B830(lbl_805C8880);
    fn_8037B50C(lbl_805C5FD4, &m18, lbl_805C7530, 0);
    fn_8037B50C(lbl_805C7540, &m1C, lbl_805C7530, 0);
    fn_8037B50C(lbl_805C7544, &m20, lbl_805C7530, 0);
    fn_8037B548(lbl_805C7548, lbl_805C755C);
    fn_8037B548(lbl_805C7564, lbl_805C755C);
    fn_8037B50C(lbl_805C7574, &m24.y, lbl_805C7580, 0);
    fn_8037B548(lbl_805C758C, lbl_805C7574);
    fn_8037B548(lbl_805C75A0, lbl_805C7574);
    fn_8037B458(lbl_805C88A4, &m10, lbl_805C60F8, lbl_805C6240);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C88B8);
}

int cTeleportActor::fn_cslot8() /* 801563FC */
{
}

struct Unk80150FC0_Marker {
    char pad0[4];
    Unk80273498_Vec3 m4;
    float m10;
};
Unk80150FC0_Marker* fn_80150FC0(int id);
void fn_80244A64(Unk8016C788_Obj* o, int a, int b);
void fn_80299B98(Unk80270BA0_X* x, const Unk80273498_Vec3& pos, float* ang);

/* near-miss: the Vec3 sum is formed with all loads hoisted here; retail adds each component in place right after the copy (27 diff lines); 6 variants tried */
int cTeleportActor::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156400 */
{
    Unk8016C788_Obj* o = fn_8016C788(ctx, a);
    if (o != 0) {
        if (m10 != 0) {
            fn_80244A64(o, 0, 0);
        }
        if (mC != 0) {
            Unk80150FC0_Marker* mk = fn_80150FC0(m14);
            if (mk == 0) {
                fn_80299B98((Unk80270BA0_X*)o, lbl_806055AC, 0);
            } else {
                float* d = &m18;
                Unk80273498_Vec3 v = mk->m4;
                v.x = v.x + d[0];
                v.y = v.y + d[1];
                v.z = v.z + d[2];
                float f = mk->m10 * lbl_805C88D4;
                fn_80299B98((Unk80270BA0_X*)o, v, &f);
            }
        } else {
            float f = m24.y * lbl_805C88D4;
            fn_80299B98((Unk80270BA0_X*)o, *(Unk80273498_Vec3*)&m18, &f);
        }
    }
}

Unk8037B3E8* cTeleportActor::fn_vslot5() /* 80156534 */
{
    return new (lbl_806EF9B4) cTeleportActor;
}

cTransitionWipe::cTransitionWipe() : Unk80359B48(fn_80378568(lbl_805C8954, 0)) /* 80156564 */
{
    m4 = 0;
}

void cTransitionWipe::fn_vslot2() /* 801565C0 */
{
    fn_8037B674(lbl_805C8964, &m4, lbl_8061BE2C, 0);
    fn_8037B50C(lbl_805C7AA8, &m8, 0, lbl_805C8974);
}

int cTransitionWipe::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156624 */
{
    fn_8031C6C0(fn_8031C6A8(), m4 + 1, (int)(m8 * lbl_805C8978), 0);
}

Unk8037B3E8* cTransitionWipe::fn_vslot5() /* 80156688 */
{
    return new (lbl_806EF9B4) cTransitionWipe;
}

cWait::cWait() : Unk80359B48(0x0F2FD99Du) /* 801566B8 */
{
    m4 = 0;
    m8 = lbl_805C8984;
    mC = 0;
}
