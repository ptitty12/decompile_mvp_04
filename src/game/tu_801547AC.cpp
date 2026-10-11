/*
 * Game code, .text 0x801547AC-0x80156714 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801527C8.h"

extern float lbl_805C8418;
extern float lbl_805C84F4;
extern float lbl_805C8580;
extern float lbl_805C8978;

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

void fn_801A4F40(Unk801527C8_Actor* a);
Unk801527C8_Actor* fn_801A04A8(Unk801527C8_Actor* a, int i);
int fn_80097190(Unk801527C8_Team* t, int a);
int fn_80097300(Unk801527C8_Team* t, int a);
int fn_801A49F0(Unk801527C8_Actor* a, int k, int v);
void fn_80178F64(void* p, int v);
void fn_80327274(Unk801527C8_Sub* s);
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_80326E64(Unk801527C8_Sub* s, int a);
void fn_8016D3DC(Unk801527C8_Ctx* ctx, int a);
void fn_8016C660(Unk801527C8_Ctx* ctx, int a);
void fn_801515AC(int* a, int* b, int* c);
int fn_803270C4(Unk801527C8_Sub* s, int id, int n, float t);
void fn_802B2518(void* o, int a, float t);

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
