/*
 * Game code, .text 0x801527C8-0x801547AC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801527C8.h"

extern const char lbl_805C7F58[];

extern const char lbl_805C7F30[];
extern const char lbl_805C7F3C[];
extern const char lbl_805C7F48[];

extern const char lbl_805C626C[];
extern const char lbl_805C62EC[];
extern float lbl_805C808C;
extern float lbl_805C8090;

extern const char lbl_805C7F90[];
extern const char lbl_805C7F98[];
extern const char lbl_805C8050[];
extern const char lbl_805C805C[];
extern const char lbl_805C8068[];
extern const char lbl_805C8074[];
extern const char lbl_805C80A8[];
extern const char lbl_805C80CC[];
extern const char lbl_805C80D4[];
extern const char lbl_805C80E0[];
extern const char lbl_805C80EC[];
extern const char lbl_805C811C[];
extern const char lbl_805C812C[];
extern const char lbl_805C8134[];
extern const char lbl_805C8144[];
extern const char lbl_805C8158[];
extern const char lbl_805C8164[];
extern const char lbl_805C8170[];
extern const char lbl_805C8180[];
extern const char lbl_805C818C[];
extern const char lbl_805C81D8[];
extern const char lbl_805C81EC[];
extern const char lbl_805C824C[];

extern const char lbl_805C7994[];

extern const char lbl_805C7D70[];
extern const char lbl_805C7974[];
extern const char lbl_805C60F8[];
extern const char lbl_805C6240[];
extern const char lbl_805C797C[];
extern const char lbl_805C7988[];
extern const char lbl_805C7D78[];
extern const char lbl_805C7D84[];
extern const char lbl_805C7D94[];
extern const char lbl_805C7D9C[];
extern const char lbl_805C7DA8[];
extern const char lbl_805C7DB4[];
extern const char lbl_805C7DC0[];
extern const char lbl_805C7DC8[];
extern const char lbl_805C7DD4[];
extern const char lbl_805C7DE0[];
extern const char lbl_805C7DE4[];
extern const char lbl_805C7DF4[];
extern const char lbl_805C7E00[];
extern const char lbl_805C7E10[];
extern const char lbl_805C7E18[];
extern const char lbl_805C7E28[];
extern const char lbl_805C7E34[];
extern const char lbl_805C7E44[];
extern const char lbl_805C7E50[];
extern const char lbl_805C7E58[];
extern const char lbl_805C7E64[];
extern const char lbl_805C7E74[];
extern const char lbl_805C7E80[];
extern const char lbl_805C7E98[];
extern const char lbl_805C770C[];
extern const char lbl_805C771C[];
extern const char lbl_805C7728[];
extern const char lbl_805C7EA0[];
extern const char* lbl_8061BD80;
extern const char* lbl_8061BE1C;
extern float lbl_805C7CD8;
extern float lbl_805C8094;
extern float lbl_805C7CDC;
extern const float lbl_805C7D34;
extern float lbl_805C7D38;
extern float lbl_805C7D6C;
extern float lbl_805C804C;
extern unsigned int lbl_8068B7D0;
extern int lbl_80621528;
extern int lbl_8062152C;
extern int lbl_8068B870;
extern int lbl_8068B874;
extern int lbl_8068B878;
extern unsigned int lbl_8068B7D4;

extern void* lbl_8061EA74;

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

int cBlendDepthOfField::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 801527C8 */
{
    float t = (f3 - f1) / f2;
    t = !(t > lbl_805C7CD8) ? (t >? lbl_805C7CDC) : lbl_805C7CD8;
    float u;
    if (mC != 0) {
        u = m10.fn_8033CDC4(t);
        u = !(u > lbl_805C7CD8) ? (u >? lbl_805C7CDC) : lbl_805C7CD8;
    } else {
        u = t;
    }
    SetM4C(lbl_8061FEDC, u);
    int r = f3 >= f1 + f2;
    return r;
}

Unk8037B3E8* cBlendDepthOfField::fn_vslot5() /* 801528C4 */
{
    return new (lbl_806EF9B4) cBlendDepthOfField;
}

cSimToEndOfPlay::cSimToEndOfPlay() : Unk80359B48(lbl_8068B7D0) /* 801528F4 */
{
}

int cSimToEndOfPlay::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80152938 */
{
    fn_801A4F40(ctx->mA4C);
}

int cSimToEndOfPlay::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80152968 */
{
    return ctx->mA4C->m6FC == 0;
}

Unk8037B3E8* cSimToEndOfPlay::fn_vslot5() /* 80152990 */
{
    return new (lbl_806EF9B4) cSimToEndOfPlay;
}

cAssignOnDeckBatter::cAssignOnDeckBatter() : Unk80359B48(0x0554CC43u) /* 801529C0 */
{
}

int cAssignOnDeckBatter::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80152A04 */
{
    Unk801527C8_Actor* actor = ctx->mA4C;
    Unk801527C8_Teams* teams = actor->m6F8->m14;
    int k = 0;
    if (teams->m1CD0 != 0) {
        k = 1;
    }
    Unk801527C8_Team* t = &teams->m0[k];
    int r = fn_801A49F0(actor, k, fn_80097300(t, fn_80097190(t, 1)));
    fn_80178F64(ctx->mA4C->m700->m3AC, r);
}

Unk8037B3E8* cAssignOnDeckBatter::fn_vslot5() /* 80152A9C */
{
    return new (lbl_806EF9B4) cAssignOnDeckBatter;
}

cScriptStopSavingReplay::cScriptStopSavingReplay() : Unk80359B48(0xF5F663D8u) /* 80152ACC */
{
}

int cScriptStopSavingReplay::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80152B10 */
{
    fn_80327274(&ctx->mA4C->m50);
}

Unk8037B3E8* cScriptStopSavingReplay::fn_vslot5() /* 80152B44 */
{
    return new (lbl_806EF9B4) cScriptStopSavingReplay;
}

cScriptCrowdCameraFlash::cScriptCrowdCameraFlash() : Unk80359B48(0x55486B13u) /* 80152B74 */
{
}

inline int HasAnim(Unk801527C8_Sub* s, int id, int n, float t)
{
    return fn_803270C4(s, id, n, t) != 0;
}

int cScriptCrowdCameraFlash::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80152BB8 */
{
    Unk801527C8_Actor* cur = ctx->mA54;
    if (cur == fn_801A04A8(ctx->mA4C, 1)) {
        Unk801527C8_Sub* s = &ctx->mA4C->m50;
        if (HasAnim(s, 0xB1, 1, lbl_805C7D34) || HasAnim(s, 0x40, 1, lbl_805C7D34)) {
            fn_802B2518(lbl_8061EA74, 2, lbl_805C7D38);
        }
    }
}

Unk8037B3E8* cScriptCrowdCameraFlash::fn_vslot5() /* 80152C8C */
{
    return new (lbl_806EF9B4) cScriptCrowdCameraFlash;
}

cGeneralScriptConditional::cGeneralScriptConditional() : Unk80359B48(0x377EB5AFu) /* 80152CBC */
{
    m4 = 0;
    m8 = lbl_805C7D6C;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1C = 0;
    m24 = 0;
    m20 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3C = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4C = 0;
}

void cGeneralScriptConditional::fn_vslot2() /* 80152D60 */
{
    fn_8037B7E8(lbl_805C7D70);
    fn_8037B458(lbl_805C7974, &m4, lbl_805C60F8, lbl_805C6240);
    fn_8037B50C(lbl_805C797C, &m8, lbl_805C7988, 0);
    fn_8037B830(lbl_805C7D70);
    fn_8037B7E8(lbl_805C7D78);
    fn_8037B458(lbl_805C7D84, &mC, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C7D94, &m10, lbl_805C7D9C);
    fn_8037B6B0(lbl_805C7DA8, &m14, lbl_8061BD80);
    fn_8037B830(lbl_805C7D78);
    fn_8037B7E8(lbl_805C7DB4);
    fn_8037B458(lbl_805C7DC0, &m18, lbl_805C60F8, lbl_805C6240);
    fn_8037B458(lbl_805C7DC8, &m1C, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C7DD4, &m20, lbl_8061BD80);
    fn_8037B674(lbl_805C7DE0, &m24, lbl_8061BE1C, 0);
    fn_8037B830(lbl_805C7DB4);
    fn_8037B7E8(lbl_805C7DE4);
    fn_8037B458(lbl_805C7DF4, &m28, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C7E00, &m2C, lbl_8061BD80);
    fn_8037B458(lbl_805C7E10, &m30, 0, 0);
    fn_8037B830(lbl_805C7DE4);
    fn_8037B7E8(lbl_805C7E18);
    fn_8037B458(lbl_805C7E28, &m34, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C7E34, &m38, lbl_8061BD80);
    fn_8037B458(lbl_805C7E44, &m3C, 0, 0);
    fn_8037B830(lbl_805C7E18);
    fn_8037B7E8(lbl_805C7E50);
    fn_8037B458(lbl_805C7E58, &m40, lbl_805C60F8, lbl_805C6240);
    fn_8037B458(lbl_805C7E64, &m44, 0, 0);
    fn_8037B830(lbl_805C7E50);
    fn_8037B7E8(lbl_805C7E74);
    fn_8037B458(lbl_805C7E80, &m48, lbl_805C60F8, lbl_805C6240);
    fn_8037B458(lbl_805C7E98, &m4C, 0, 0);
    fn_8037B830(lbl_805C7E74);
    fn_8037B728(lbl_805C770C, lbl_805C771C, &m50, lbl_805C7728);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7EA0);
}

Unk8037B3E8* cGeneralScriptConditional::fn_vslot5() /* 801533D8 */
{
    return new (lbl_806EF9B4) cGeneralScriptConditional;
}

cGosubRandom::cGosubRandom() : Unk80359B48(lbl_8068B7D4) /* 80153408 */
{
    Entry* e = m4;
    for (int i = 0; i < 8; i++) {
        e->mUse = 0;
        e->mName = 0;
        e++;
    }
}

void cGosubRandom::fn_vslot2() /* 8015346C */
{
    char buf[64];
    for (int i = 0; i < 8; i++) {
        int n = i + 1;
        fn_804089B4(buf, lbl_805C7F30, n);
        fn_8037B7E8(buf);
        fn_804089B4(buf, lbl_805C7F3C, n);
        Entry* e = &m4[i];
        fn_8037B458(buf, &e->mUse, 0, lbl_805C6240);
        fn_804089B4(buf, lbl_805C7F48, n);
        fn_8037B5C0(buf, &e->mName, lbl_805C626C);
        fn_804089B4(buf, lbl_805C7F30, n);
        fn_8037B830(buf);
    }
}

/* near-miss: clamp of the random index compiles with different registers (one extra copy); 3 variants tried */
int cGosubRandom::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 8015355C */
{
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (m4[i].mUse != 0) {
            cnt++;
        }
    }
    if (cnt > 0) {
        int r = ctx->mA4C->m554->fn_8014D8AC(cnt, lbl_805C7F58, 0x5C);
        if (lbl_80621528 != 0) {
            int x = cnt - 1;
            int lim = lbl_8062152C - 1;
            if (lim <= x) {
                x = lim;
                if (x < 0) {
                    x = 0;
                }
            }
            r = x;
        }
        int c = 0;
        for (int j = 0; j < 8; j++) {
            if (m4[j].mUse != 0) {
                if (c == r) {
                    ctx->mA18 = m4[j].mName;
                    break;
                }
                c++;
            }
        }
    }
}

int cGosubRandom::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 8015367C */
{
    fn_8016D3DC(ctx, a);
    return 0;
}

Unk8037B3E8* cGosubRandom::fn_vslot5() /* 801536B4 */
{
    return new (lbl_806EF9B4) cGosubRandom;
}

cGosub::cGosub() : Unk80359B48(0xF4115D88u) /* 801536E4 */
{
    m4 = 0;
}

void cGosub::fn_vslot2() /* 80153730 */
{
    fn_8037B5C0(lbl_805C7F90, &m4, lbl_805C626C);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7F90);
}

int cGosub::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 8015378C */
{
    ctx->mA18 = m4;
}

int cGosub::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 801537AC */
{
    fn_8016D3DC(ctx, a);
    return 0;
}

Unk8037B3E8* cGosub::fn_vslot5() /* 801537E4 */
{
    return new (lbl_806EF9B4) cGosub;
}

extern int lbl_8061BE20;

cPlayManagerArgumentScript::cPlayManagerArgumentScript() : Unk80359B48(lbl_805C7F98) /* 80153814 */
{
    if (lbl_8061BE20 == 0) {
        lbl_8061BE20 = fn_80378568(lbl_805C7F98, 0);
    }
}

int cPlayManagerArgumentScript::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80153E40 */
{
    return 1;
}

Unk8037B3E8* cPlayManagerArgumentScript::fn_vslot5() /* 80153E5C */
{
    return new (lbl_806EF9B4) cPlayManagerArgumentScript;
}

cGoto::cGoto() : Unk80359B48(0x0F275081u) /* 80153E8C */
{
    m4 = 0;
}

void cGoto::fn_vslot2() /* 80153ED8 */
{
    fn_8037B5C0(lbl_805C7F90, &m4, lbl_805C626C);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7F90);
}

int cGoto::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80153F34 */
{
    ctx->mA14 = m4;
}

int cGoto::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80153F54 */
{
    return 0;
}

Unk8037B3E8* cGoto::fn_vslot5() /* 80153F70 */
{
    return new (lbl_806EF9B4) cGoto;
}

cLoop::cLoop() : Unk80359B48(0x0F2A0DC2u) /* 80153FA0 */
{
}

void cLoop::fn_vslot2() /* 80153FE4 */
{
}

int cLoop::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80153FE8 */
{
    fn_8016C660(ctx, a);
}

Unk8037B3E8* cLoop::fn_vslot5() /* 8015401C */
{
    return new (lbl_806EF9B4) cLoop;
}

cPause::cPause() : Unk80359B48(0xF4AC9506u) /* 8015404C */
{
    m4 = lbl_805C804C;
    m8 = 0;
}

void cPause::fn_vslot2() /* 801540A4 */
{
    fn_8037B458(lbl_805C8050, &m8, lbl_805C60F8, lbl_805C6240);
    fn_8037B50C(lbl_805C805C, &m4, lbl_805C8068, 0);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C8074);
}

int cPause::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 8015412C */
{
}

float cPause::fn_cslot13(float f1) /* 80154144 */
{
    if (m8 != 0) {
        return lbl_805C808C;
    }
    float t = m4 - f1;
    if (!(t >= lbl_805C8090)) {
        t = lbl_805C8090;
    }
    return t;
}

int cPause::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 8015419C */
{
    if (m8 != 0) {
        return f1 != f3;
    }
    Unk801527C8_Actor* p = ctx->mA54;
    if (p->m44 != 0) {
        float cur = p->m4C;
        int n = fn_80326E64(&ctx->mA4C->m50, 0);
        if (p != fn_801A04A8(ctx->mA4C, 5)) {
            n -= 30;
        }
        if ((int)(cur * lbl_805C8094) > n) {
            return 1;
        }
    }
    return f1 + m4 < f3;
}

Unk8037B3E8* cPause::fn_vslot5() /* 80154288 */
{
    return new (lbl_806EF9B4) cPause;
}

cPlayAnimation::cPlayAnimation() : Unk80359B48(0x8B9DFA5Eu) /* 801542B8 */
{
    m4 = 0;
}

void cPlayAnimation::fn_vslot2() /* 80154304 */
{
    fn_8037B5C0(lbl_805C80A8, &m4, lbl_805C62EC);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C80A8);
}

int cPlayAnimation::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80154360 */
{
    if (m4 != 0) {
        Unk8016C788_Obj* o = fn_8016C788(ctx, a);
        if (o != 0) {
            Unk8027C728_Goal* g = fn_802448F4(o, 1);
            int v = m4;
            g->m10 = 0xB;
            fn_8027C728(g);
            ((Unk80287D70*)g->m18)->fn_80287D50(v);
            fn_8015152C(o, g);
        }
    }
}

Unk8037B3E8* cPlayAnimation::fn_vslot5() /* 801543EC */
{
    return new (lbl_806EF9B4) cPlayAnimation;
}

cPlayerAttributes::cPlayerAttributes() : Unk80359B48(0xBF3C8C5Cu) /* 8015441C */
{
    m4 = 0;
    m8 = 0;
    mC = 0;
}

void cPlayerAttributes::fn_vslot2() /* 80154470 */
{
    fn_8037B458(lbl_805C80CC, &m4, lbl_805C60F8, lbl_805C6240);
    fn_8037B458(lbl_805C80D4, &m8, lbl_805C60F8, lbl_805C6240);
    fn_8037B458(lbl_805C80E0, &mC, lbl_805C60F8, lbl_805C6240);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C80EC);
}

int cPlayerAttributes::fn_cslot8() /* 80154510 */
{
}

/* near-miss: the 11 zeroing stores are scheduled in a different order than retail (0x60 first, 0x5C last); ascending source order tried */
int cPlayerAttributes::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80154514 */
{
    Unk8016C788_Obj* o = fn_8016C788(ctx, a);
    if (m4 != 0) {
        Unk8016C788_Sub* s = &o->m360;
        s->m40 = 0;
        s->m44 = 0;
        s->m48 = 0;
        s->m4C = 0;
        s->m50 = 0;
        s->m54 = 0;
        s->m58 = 0;
        s->m5C = 0;
        s->m60 = 0;
        s->m64 = 0;
        s->m68 = 0;
    }
    if (m8 != 0) {
        Unk80189300* p = ctx->mA4C->m6CC;
        fn_80189300(p, o);
        p->fn_v8(0);
    }
    if (mC != 0) {
        fn_80189300(ctx->mA4C->m6CC, 0);
    }
}

Unk8037B3E8* cPlayerAttributes::fn_vslot5() /* 801545F0 */
{
    return new (lbl_806EF9B4) cPlayerAttributes;
}

cScriptIdleGoal::cScriptIdleGoal() : Unk80359B48(0x257FB23Eu) /* 80154620 */
{
}

void cScriptIdleGoal::fn_vslot2() /* 80154664 */
{
    fn_8037B7E8(lbl_805C811C);
    fn_8037B6B0(lbl_805C812C, &lbl_8068B870, lbl_805C8134);
    fn_8037B830(lbl_805C811C);
    fn_8037B7E8(lbl_805C8144);
    fn_8037B6B0(lbl_805C8158, &lbl_8068B874, lbl_805C8164);
    fn_8037B830(lbl_805C8144);
    fn_8037B7E8(lbl_805C8170);
    fn_8037B6B0(lbl_805C8180, &lbl_8068B878, lbl_805C818C);
    fn_8037B830(lbl_805C8170);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C81D8);
    const char* v = lbl_805C81EC;
    fn_8037B674(lbl_805C824C, &m10, v, 0);
}

int cScriptIdleGoal::fn_cslot8() /* 8015477C */
{
    fn_801515AC(&m4, &m8, &mC);
}
